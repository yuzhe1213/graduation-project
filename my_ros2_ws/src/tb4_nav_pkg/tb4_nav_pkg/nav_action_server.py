#!/usr/bin/env python3
#本程式有使用AI撰寫
#此段為測試cmd_vel前進的程式碼
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from std_msgs.msg import Bool
from nav2_msgs.action import NavigateToPose
from geometry_msgs.msg import PoseStamped, Quaternion, Twist
import math
from enum import IntEnum
import time
from tf2_ros import Buffer, TransformListener

class TurtleBot4Directions(IntEnum):
    NORTH = 0
    NORTH_WEST = 45
    WEST = 90
    SOUTH_WEST = 135
    SOUTH = 180
    SOUTH_EAST = 225
    EAST = 270
    NORTH_EAST = 315

    @staticmethod
    def opposite(direction):
        return TurtleBot4Directions((direction + 180) % 360)

class NavActionNode(Node):
    def __init__(self):
        super().__init__('nav_action_node')

        self.trigger_sub = self.create_subscription(Bool, '/nav_trigger', self.trigger_callback, 10)
        self.done_pub = self.create_publisher(Bool, '/nav_done', 10)
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)
        self.nav_client = ActionClient(self, NavigateToPose, '/navigate_to_pose')

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

    def trigger_callback(self, msg):
        if msg.data:
            self.get_logger().info('收到導航觸發，開始導航')
            self.navigate()

    def navigate(self):
        pose = PoseStamped()
        pose.header.frame_id = "map"
        pose.header.stamp = self.get_clock().now().to_msg()
        pose.pose.position.x = -1.906828761100769
        pose.pose.position.y = 0.5624497532844543

        try:
            now = rclpy.time.Time()
            trans = self.tf_buffer.lookup_transform('map', 'base_link', now, timeout=rclpy.duration.Duration(seconds=1.0))
            q = trans.transform.rotation
            siny_cosp = 2 * (q.w * q.z + q.x * q.y)
            cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
            yaw = math.atan2(siny_cosp, cosy_cosp)

            yaw += math.pi  # 轉 180 度
            q_rot = Quaternion()
            q_rot.x = 0.0
            q_rot.y = 0.0
            q_rot.z = math.sin(yaw / 2)
            q_rot.w = math.cos(yaw / 2)
            pose.pose.orientation = q_rot
        except Exception as e:
            self.get_logger().warn(f'TF 查詢失敗，使用預設 180 度方向: {e}')
            pose.pose.orientation = Quaternion(x=0.0, y=0.0, z=1.0, w=0.0)

        goal = NavigateToPose.Goal()
        goal.pose = pose

        self.nav_client.wait_for_server()
        send_goal_future = self.nav_client.send_goal_async(goal)
        send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().warn('導航被拒絕')
            return

        self.get_logger().info('導航中')
        goal_handle.get_result_async().add_done_callback(self.forward_and_notify)

    def forward_and_notify(self, future):
        self.get_logger().info('到達導航目標，開始前進 0.5 公尺')

        twist = Twist()
        twist.linear.x = 0.1
        duration = 4.0
        start_time = self.get_clock().now().seconds_nanoseconds()[0]

        def forward_callback():
            now = self.get_clock().now().seconds_nanoseconds()[0]
            if now - start_time < duration:
                self.cmd_vel_pub.publish(twist)
            else:
                self.cmd_vel_pub.publish(Twist())
                self.get_logger().info('前進完成，通知手臂執行夾取')
                self.done_pub.publish(Bool(data=True))
                self.timer.cancel()

        self.timer = self.create_timer(0.1, forward_callback)

def main():
    rclpy.init()
    node = NavActionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
