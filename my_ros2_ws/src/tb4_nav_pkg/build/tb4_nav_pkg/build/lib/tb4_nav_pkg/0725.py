import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient
import math
import subprocess  # 用來關閉避障
import time

class NavigateAndForward(Node):
    def __init__(self):
        super().__init__('navigate_and_forward')

        self.client = ActionClient(self, NavigateToPose, '/navigate_to_pose')
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # 初始目標座標與角度（可自訂）
        self.initial_pose = {
            'x': -2.33,
            'y': 1.03,
            'yaw_deg': 180
        }

        self.forward_speed = 0.2  # m/s
        self.forward_distance = 1.0  # m
        self.forward_duration = self.forward_distance / self.forward_speed  # 時間 = 距離 ÷ 速度

    def send_goal(self, x, y, yaw_deg):
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose.header.frame_id = 'map'
        goal_msg.pose.header.stamp = self.get_clock().now().to_msg()

        # 計算角度 -> 四元數
        yaw_rad = math.radians(yaw_deg)
        qz = math.sin(yaw_rad / 2.0)
        qw = math.cos(yaw_rad / 2.0)
        goal_msg.pose.pose.position.x = x
        goal_msg.pose.pose.position.y = y
        goal_msg.pose.pose.orientation.z = qz
        goal_msg.pose.pose.orientation.w = qw

        self.get_logger().info(f'導航到: x={x:.2f}, y={y:.2f}, yaw={yaw_deg} 度')

        self.client.wait_for_server()
        future = self.client.send_goal_async(goal_msg)
        future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('導航失敗')
            return

        self.get_logger().info('導航已接受')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.result_callback)

    def result_callback(self, future):
        self.get_logger().info('第一個導航完成，準備切換 safety_override 並往前前進')

        # ✅ 關閉安全限制：允許無視避障前進
        try:
            subprocess.run([
                "ros2", "param", "set", "/motion_control", "safety_override", "full"
            ], check=True)
            self.get_logger().info('已設為 safety_override=full（關閉安全限制）')
        except Exception as e:
            self.get_logger().error(f'無法設定 safety_override：{e}')

        # ✅ 發出前進的 Twist 指令
        twist = Twist()
        twist.linear.x = self.forward_speed
        self.cmd_vel_pub.publish(twist)

        # ✅ 啟動 Timer，在 forward_duration 秒後停止
        self.timer = self.create_timer(self.forward_duration, self.stop_robot_once)

    def stop_robot_once(self):
        # 停止移動
        twist = Twist()  # 所有速度設為 0
        self.cmd_vel_pub.publish(twist)
        self.get_logger().info('已完成往前移動 1 公尺')
        self.timer.cancel()

def main(args=None):
    rclpy.init(args=args)
    node = NavigateAndForward()
    node.send_goal(
        node.initial_pose['x'],
        node.initial_pose['y'],
        node.initial_pose['yaw_deg']
    )
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
