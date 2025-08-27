#!/usr/bin/env python3

from vosk import Model, KaldiRecognizer
import sounddevice as sd
import json
import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool, String
from open_manipulator_msgs.srv import SetJointPosition
from sensor_msgs.msg import JointState
import time

model = Model("/home/yuzhe/vosk_models/model-cn")
recognizer = KaldiRecognizer(model, 16000)
recognizer.SetWords(False)

goal_joint_angle = [0.0, 0.0, 0.0, 0.0]

class VoskArmNode(Node):
    def __init__(self):
        super().__init__('vosk_arm_node')

        self.nav_pub = self.create_publisher(String, '/nav_trigger', 10)
        self.grasp_done_pub = self.create_publisher(Bool, '/grasp_done', 10)
        self.nav_done_sub = self.create_subscription(Bool, '/nav_done', self.nav_done_callback, 10)
        self.tool_client = self.create_client(SetJointPosition, 'goal_tool_control')
        self.joint_client = self.create_client(SetJointPosition, 'goal_joint_space_path')
        self.joint_sub = self.create_subscription(JointState, 'joint_states', self.joint_callback, 10)

        self._nav_stage = 1
        self._target_item = None

    def joint_callback(self, msg):
        for i in range(4):
            goal_joint_angle[i] = msg.position[i]

    def nav_done_callback(self, msg):
        if msg.data:
            if self._target_item is None:
                self.get_logger().warn('尚未指定目標物品')
                return

            self.get_logger().info(f'導航完成（目標：{self._target_item}）')

            if self._nav_stage == 1:
                self.get_logger().info(f'開始夾取：{self._target_item}')
                self.grasp_and_retract()
                self._target_item = "放置點"
                self.publish_trigger()
                self._nav_stage = 2

            elif self._nav_stage == 2:
                self.get_logger().info('放下物品中')
                self.send_gripper(0.0)
                time.sleep(1)
                self._nav_stage = 1
                self._target_item = None
                self.get_logger().info('任務重置完成')

    def send_joint(self, angles):
        req = SetJointPosition.Request()
        req.joint_position.joint_name = ['joint1', 'joint2', 'joint3', 'joint4']
        req.joint_position.position = angles
        req.path_time = 1.0
        self.joint_client.call_async(req)

    def send_gripper(self, val):
        req = SetJointPosition.Request()
        req.joint_position.joint_name = ['gripper']
        req.joint_position.position = [val]
        req.path_time = 1.0
        self.tool_client.call_async(req)

    def grasp_and_retract(self):
        if self._target_item == "面包":
            self.send_joint([0.001534, 0.018408, 0.018408, 0.004602])
        elif self._target_item == "饮料":
            self.send_joint([0.0, 0.02, 0.015, 0.005])
        elif self._target_item == "饼干":
            self.send_joint([0.015, 0.01, 0.01, 0.0])
        else:
            self.get_logger().warn("查無此項物品")

        time.sleep(2)
        self.send_gripper(-0.01)
        time.sleep(1)
        self.get_logger().info('夾取完成，發送 grasp_done')
        self.grasp_done_pub.publish(Bool(data=True))

    def publish_trigger(self):
        msg = String()
        msg.data = self._target_item
        self.nav_pub.publish(msg)
        self.get_logger().info(f'發送導航觸發（目標：{self._target_item}）')

def listen_and_control(node):
    def callback(indata, frames, time_info, status):
        if recognizer.AcceptWaveform(bytes(indata)):
            result = json.loads(recognizer.Result())
            text = result.get("text", "").strip()
            print(f"語音辨識：'{text}'")

            if text in ["面包", "饮料", "饼干"]:
                print(f"指令觸發：{text} → 導航 + 夾取流程")
                node._target_item = text
                node.publish_trigger()

    stream = sd.InputStream(samplerate=16000, blocksize=8000, dtype='int16', channels=1, callback=callback)
    with stream:
        print("請說：麵包、餅乾、飲料")
        while rclpy.ok():
            rclpy.spin_once(node)

def main():
    rclpy.init()
    node = VoskArmNode()
    listen_and_control(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
