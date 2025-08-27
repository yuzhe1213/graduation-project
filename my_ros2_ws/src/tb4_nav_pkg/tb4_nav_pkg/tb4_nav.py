#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from std_msgs.msg import String, Bool
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped, Quaternion, Twist
from tf2_ros import Buffer, TransformListener
import math
import time

class NavActionNode(Node):
    def __init__(self):
        super().__init__('nav_action_node')

        self.trigger_sub = self.create_subscription(String, '/nav_trigger', self.trigger_callback, 10)
        self.done_pub = self.create_publisher(Bool, '/nav_done', 10)
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.nav_client = ActionClient(self, NavigateToPose, '/navigate_to_pose')

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.nav_stage = 1
        self.target_item = None

    def trigger_callback(self, msg):
        self.target_item = msg.data.strip()

        if self.target_item != "放置點" and self.nav_stage != 1:
            self.get_logger().info('正在導航中')
            return

        if self.target_item not in ["面包", "饮料", "饼干", "放置點"]:
            self.get_logger().warn(f"不支援的物品名稱：{self.target_item}")
            return

        if self.target_item == "放置點":
            self.navigate_to_drop_zone()
        else:
            self.get_logger().info(f'收到導航觸發：{self.target_item}')
            self.navigate_to_target()

    def navigate_to_target(self):
        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.header.stamp = self.get_clock().now().to_msg()
        rotate_180 = self.target_item in ["饮料", "饼干", "面包", ]

        if self.target_item == "面包":
            pose.pose.position.x = -2.19427752494812
            pose.pose.position.y = 1.1741442680358887
        elif self.target_item == "饮料":
            pose.pose.position.x = -2.15773606300354
            pose.pose.position.y = 0.09259955585002899
        elif self.target_item == "饼干":
            pose.pose.position.x = -2.203303575515747
            pose.pose.position.y = 0.5524160861968994
        else:
            self.get_logger().warn("無法辨識")
            return


        now = rclpy.time.Time()
        trans = self.tf_buffer.lookup_transform('map', 'base_link', now, timeout=rclpy.duration.Duration(seconds=1.0))
        q = trans.transform.rotation
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        yaw = math.atan2(siny_cosp, cosy_cosp)

        if rotate_180:
            yaw += math.pi

        q_rot = Quaternion()
        q_rot.x = 0.0
        q_rot.y = 0.0
        q_rot.z = math.sin(yaw / 2)
        q_rot.w = math.cos(yaw / 2)
        pose.pose.orientation = q_rot

 

        goal = NavigateToPose.Goal()
        goal.pose = pose

        self.get_logger().info(f"正在導航到：{self.target_item}")
        self.nav_client.wait_for_server()
        self.nav_client.send_goal_async(goal).add_done_callback(self.goal_response_callback)

    def navigate_to_drop_zone(self):
        time.sleep(5)
        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = -0.036616262048482895
        pose.pose.position.y = 0.9508790373802185
        pose.pose.orientation = Quaternion(x=0.0, y=0.0, z=0.0, w=1.0)

        goal = NavigateToPose.Goal()
        goal.pose = pose

        self.get_logger().info("正在導航到放置點")
        self.nav_client.wait_for_server()
        self.nav_client.send_goal_async(goal).add_done_callback(self.drop_zone_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn("導航被拒絕")
            return
        goal_handle.get_result_async().add_done_callback(self.notify_arm)

    def drop_zone_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn("放置點導航被拒絕")
            return
        goal_handle.get_result_async().add_done_callback(self.finish_sequence)

    def notify_arm(self, future):
        self.get_logger().info("已抵達目的地並通知手臂")

        # if self.target_item in ["果冻", "饼干", "面包"]:
        #     self.rotate_in_place(math.pi)

        time.sleep(1.0)

        self.done_pub.publish(Bool(data=True))
        self.nav_stage = 2
        self.navigate_to_drop_zone()

    # def rotate_in_place(self, angle_rad):
    #     twist = Twist()
    #     twist.angular.z = 0.5 if angle_rad > 0 else -0.5

    #     duration = abs(angle_rad / twist.angular.z)
    #     start = self.get_clock().now().nanoseconds / 1e9

    #     while (self.get_clock().now().nanoseconds / 1e9) - start < duration:
    #         self.cmd_vel_pub.publish(twist)
    #         rclpy.spin_once(self, timeout_sec=0.1)

    #     self.cmd_vel_pub.publish(Twist())

    def finish_sequence(self, future):
        self.get_logger().info("前往放置點")
        time.sleep(8)
        self.done_pub.publish(Bool(data=True))
        self.get_logger().info("鬆爪已完成")
        self.nav_stage = 1
        self.target_item = None

def main():
    rclpy.init()
    node = NavActionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
