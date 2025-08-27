#!/usr/bin/env python3
import os
import sys
import time
import json
import select
import threading
import rclpy
import sounddevice as sd
from vosk import Model, KaldiRecognizer

from sensor_msgs.msg import JointState
from open_manipulator_msgs.msg import KinematicsPose, OpenManipulatorState
from open_manipulator_msgs.srv import SetJointPosition, SetKinematicsPose
from rclpy.node import Node
from rclpy.qos import QoSProfile

if os.name == 'nt':
    import msvcrt
else:
    import termios
    import tty

# === Global Variables ===
present_joint_angle = [0.0] * 4
goal_joint_angle = [0.0] * 4
prev_goal_joint_angle = [0.0] * 4
present_kinematics_pose = [0.0] * 7
goal_kinematics_pose = [0.0] * 7
prev_goal_kinematics_pose = [0.0] * 7
goal_tool_angle = [0.0]

task_position_delta = 0.01  # m
joint_angle_delta = 0.05    # rad
path_time = 0.5             # sec

# 語音辨識
def start_voice_thread(teleop_keyboard_node):
    model_path = os.path.expanduser("~/vosk_models/model-cn")
    model = Model(model_path)
    recognizer = KaldiRecognizer(model, 16000)
    recognizer.SetWords(False)

    def callback(indata, frames, time, status):
        if recognizer.AcceptWaveform(indata.tobytes()):
            result = json.loads(recognizer.Result())
            text = result.get("text", "")
            print("🎤 語音辨識結果：", text)
            if "家" in text or "夾取" in text:
                print("🟢 偵測到關鍵詞，執行夾取")
                do_grasp_action(teleop_keyboard_node)

    def run_stream():
        with sd.InputStream(samplerate=16000, channels=1, dtype='int16', callback=callback):
            print("🎤 語音辨識中（請說『家』或『夾取』）...")
            while True:
                time.sleep(0.1)

    threading.Thread(target=run_stream, daemon=True).start()

#執行夾取
def do_grasp_action(teleop_keyboard):
    target_joint = [-0.230097, 0.817612, -0.503146, 1.256330]
    print("💡 目標角度：", target_joint)
    step = 0.04
    delay = 0.05

    for i in reversed(range(4)):
        while abs(goal_joint_angle[i] - target_joint[i]) > step:
            if goal_joint_angle[i] < target_joint[i]:
                goal_joint_angle[i] = min(goal_joint_angle[i] + step, target_joint[i])
            else:
                goal_joint_angle[i] = max(goal_joint_angle[i] - step, target_joint[i])

            teleop_keyboard.send_goal_joint_space()
            rclpy.spin_once(teleop_keyboard, timeout_sec=0.05)
            time.sleep(delay)

    goal_tool_angle[0] = -0.01
    teleop_keyboard.send_goal_tool_space()
    print("✅ 語音夾取完成")


class TeleopKeyboard(Node):
    qos = QoSProfile(depth=10)
    if os.name != 'nt':
        settings = termios.tcgetattr(sys.stdin)

    def __init__(self):
        super().__init__('teleop_keyboard')
        self.joint_state_subscription = self.create_subscription(
            JointState, 'joint_states', self.joint_state_callback, self.qos)

        self.kinematics_pose_subscription = self.create_subscription(
            KinematicsPose, 'kinematics_pose', self.kinematics_pose_callback, self.qos)

        self.open_manipulator_state_subscription = self.create_subscription(
            OpenManipulatorState, 'states', self.open_manipulator_state_callback, self.qos)

        self.goal_joint_space = self.create_client(SetJointPosition, 'goal_joint_space_path')
        self.goal_task_space = self.create_client(SetKinematicsPose, 'goal_task_space_path')
        self.goal_tool_control = self.create_client(SetJointPosition, 'goal_tool_control')

        self.goal_joint_space_req = SetJointPosition.Request()
        self.goal_task_space_req = SetKinematicsPose.Request()
        self.goal_tool_control_req = SetJointPosition.Request()

    def joint_state_callback(self, msg):
        for i in range(4):
            present_joint_angle[i] = msg.position[i]

    def kinematics_pose_callback(self, msg):
        present_kinematics_pose[0] = msg.pose.position.x
        present_kinematics_pose[1] = msg.pose.position.y
        present_kinematics_pose[2] = msg.pose.position.z
        present_kinematics_pose[3] = msg.pose.orientation.w
        present_kinematics_pose[4] = msg.pose.orientation.x
        present_kinematics_pose[5] = msg.pose.orientation.y
        present_kinematics_pose[6] = msg.pose.orientation.z

    def open_manipulator_state_callback(self, msg):
        if msg.open_manipulator_moving_state == 'STOPPED':
            for i in range(4):
                goal_joint_angle[i] = present_joint_angle[i]
            for i in range(7):
                goal_kinematics_pose[i] = present_kinematics_pose[i]

    def send_goal_joint_space(self):
        self.goal_joint_space_req.joint_position.joint_name = ['joint1', 'joint2', 'joint3', 'joint4']
        self.goal_joint_space_req.joint_position.position = goal_joint_angle.copy()
        self.goal_joint_space_req.path_time = path_time
        self.goal_joint_space.call_async(self.goal_joint_space_req)

    def send_goal_task_space(self):
        self.goal_task_space_req.end_effector_name = 'gripper'
        self.goal_task_space_req.kinematics_pose.pose.position.x = goal_kinematics_pose[0]
        self.goal_task_space_req.kinematics_pose.pose.position.y = goal_kinematics_pose[1]
        self.goal_task_space_req.kinematics_pose.pose.position.z = goal_kinematics_pose[2]
        self.goal_task_space_req.kinematics_pose.pose.orientation.w = goal_kinematics_pose[3]
        self.goal_task_space_req.kinematics_pose.pose.orientation.x = goal_kinematics_pose[4]
        self.goal_task_space_req.kinematics_pose.pose.orientation.y = goal_kinematics_pose[5]
        self.goal_task_space_req.kinematics_pose.pose.orientation.z = goal_kinematics_pose[6]
        self.goal_task_space_req.path_time = path_time
        self.goal_task_space.call_async(self.goal_task_space_req)

    def send_goal_tool_space(self):
        self.goal_tool_control_req.joint_position.joint_name = ['gripper']
        self.goal_tool_control_req.joint_position.position = goal_tool_angle
        self.goal_tool_control_req.path_time = 0.5
        self.goal_tool_control.call_async(self.goal_tool_control_req)

# === 其他功能 ===
def get_key(settings):
    if os.name == 'nt':
        return msvcrt.getch().decode('utf-8')
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    key = sys.stdin.read(1) if rlist else ''
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    # print_present_values()
    return key


def main():
    settings = None
    if os.name != 'nt':
        settings = termios.tcgetattr(sys.stdin)

    rclpy.init()
    teleop_keyboard = TeleopKeyboard()
    start_voice_thread(teleop_keyboard)

    try:
        while rclpy.ok():
            rclpy.spin_once(teleop_keyboard)
            key_value = get_key(settings)

            # 鍵盤控制區
            if key_value == 'g':
                goal_tool_angle[0] = 0.0
                teleop_keyboard.send_goal_tool_space()
            elif key_value == 'f':
                goal_tool_angle[0] = -0.01
                teleop_keyboard.send_goal_tool_space()
            elif key_value == '\x03':
                break
            else:
                for i in range(4):
                    prev_goal_joint_angle[i] = goal_joint_angle[i]
                for i in range(7):
                    prev_goal_kinematics_pose[i] = goal_kinematics_pose[i]

    except Exception as e:
        print(e)
    finally:
        if os.name != 'nt':
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        teleop_keyboard.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
