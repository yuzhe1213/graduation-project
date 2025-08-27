#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from open_manipulator_msgs.srv import SetJointPosition
import sys
import termios
import tty

class GripperTeleop(Node):
    def __init__(self):
        super().__init__('gripper_teleop')
        self.cli = self.create_client(SetJointPosition, 'goal_tool_control')
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('等待 goal_tool_control 服務中...')

        self.req = SetJointPosition.Request()
        self.current_position = 0.0  # 從張開開始（負方向控制）

    def set_gripper(self, delta: float = None, override: float = None):
        if override is not None:
            self.current_position = override
        elif delta is not None:
            self.current_position += delta
            self.current_position = max(-0.01, min(0.0, self.current_position))  # 限制在 -0.01 ~ 0.0

        self.req.joint_position.joint_name = ['gripper']
        self.req.joint_position.position = [self.current_position]
        self.req.path_time = 1.0

        future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is not None:
            self.get_logger().info(f'Gripper 位置：{self.current_position:.4f}')
        else:
            self.get_logger().error('呼叫服務失敗')

def get_key(settings):
    tty.setraw(sys.stdin.fileno())
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

def main():
    settings = termios.tcgetattr(sys.stdin)
    rclpy.init()
    node = GripperTeleop()

    print("\n[Gripper Teleop 控制器]\n"
          "g: 收緊 (-0.001)\n"
          "f: 放開 (+0.001)\n"
          "z: 直接跳到最夾緊（-0.010）\n"
          "q: 離開\n")

    try:
        while True:
            key = get_key(settings)
            if key == 'g':
                node.set_gripper(-0.001)  # 收緊（往 -0.01 靠近）
            elif key == 'f':
                node.set_gripper(0.001)   # 放開（往 0.0 靠近）
            elif key == 'z':
                node.set_gripper(override=-0.01)  # 直接跳到最夾緊
            elif key == 'q':
                break
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
