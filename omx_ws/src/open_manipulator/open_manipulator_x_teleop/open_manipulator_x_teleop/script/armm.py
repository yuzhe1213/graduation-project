#!/usr/bin/env python3

from concurrent.futures import ThreadPoolExecutor
from math import exp
import os
import select
import sys
import rclpy

from open_manipulator_msgs.msg import KinematicsPose, OpenManipulatorState
from open_manipulator_msgs.srv import SetJointPosition, SetKinematicsPose
from rclpy.callback_groups import ReentrantCallbackGroup
from sensor_msgs.msg import JointState
# from rclpy.executors import Executor, SingleThreadedExecutor
from rclpy.node import Node
from rclpy.qos import QoSProfile
from threading import Timer

if os.name == 'nt':
    import msvcrt
else:
    import termios
    import tty

present_joint_angle = [0.0, 0.0, 0.0, 0.0]
goal_joint_angle = [0.0, 0.0, 0.0, 0.0]
prev_goal_joint_angle = [0.0, 0.0, 0.0, 0.0]
present_kinematics_pose = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
goal_kinematics_pose = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]
goal_tool_angle = [0.0]
prev_goal_kinematics_pose = [0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0]

debug = True
task_position_delta = 0.01  # meter
joint_angle_delta = 0.05  # radian
path_time = 0.5  # second

usage = """
Control Your OpenManipulator!
---------------------------
Task Space Control:
         (Forward, X+)
              W                   Q (Upward, Z+)
(Left, Y+) A     D (Right, Y-)    Z (Downward, Z-)
              X 
        (Backward, X-)

Joint Space Control:
- Joint1 : Increase (Y), Decrease (H)
- Joint2 : Increase (U), Decrease (J)
- Joint3 : Increase (I), Decrease (K)
- Joint4 : Increase (O), Decrease (L)
- Gripper: Open     (G),    Close (F)

INIT : (1)
HOME : (2)

CTRL-C to quit
"""

e = """
Communications Failed
"""
from vosk import Model, KaldiRecognizer
import sounddevice as sd
import json
import threading

# 加入vosk套件
vosk_model_path = "/home/yuzhe/vosk_models/model-cn" #注意vosk檔案位置
model = Model(vosk_model_path)
recognizer = KaldiRecognizer(model, 16000)
recognizer.SetWords(False)


def start_voice_thread(teleop_keyboard_node):
    def callback(indata, frames, time, status):
        if recognizer.AcceptWaveform(indata):
            result = json.loads(recognizer.Result())
            text = result.get("text", "")
            if "家" in text: #輸入想要的文字
                print(" 偵測到：夾取！執行 key = 'n'")
                do_grasp_action(teleop_keyboard_node)

    stream = sd.InputStream(samplerate=16000, channels=1, dtype='int16', callback=callback)
    stream.start()
def callback(indata, frames, time, status):
    if recognizer.AcceptWaveform(indata):
        result = json.loads(recognizer.Result())
        print("語音辨識結果：", result)


class TeleopKeyboard(Node):

    qos = QoSProfile(depth=10)
    settings = None
    if os.name != 'nt':
        settings = termios.tcgetattr(sys.stdin)

    def __init__(self):
        super().__init__('teleop_keyboard')
        key_value = ''


        self.joint_state_subscription = self.create_subscription(
            JointState,
            'joint_states',
            self.joint_state_callback,
            self.qos)
        self.joint_state_subscription


        self.kinematics_pose_subscription = self.create_subscription(
            KinematicsPose,
            'kinematics_pose',
            self.kinematics_pose_callback,
            self.qos)
        self.kinematics_pose_subscription

        self.open_manipulator_state_subscription = self.create_subscription(
            OpenManipulatorState,
            'states',
            self.open_manipulator_state_callback,
            self.qos)
        self.open_manipulator_state_subscription

        # Create Service Clients
        self.goal_joint_space = self.create_client(SetJointPosition, 'goal_joint_space_path')
        self.goal_task_space = self.create_client(SetKinematicsPose, 'goal_task_space_path')
        self.goal_tool_control = self.create_client(SetJointPosition, 'goal_tool_control')
        self.goal_tool_control_req = SetJointPosition.Request()
        self.goal_joint_space_req = SetJointPosition.Request()
        self.goal_task_space_req = SetKinematicsPose.Request()

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

        try:
            send_goal_task = self.goal_task_space.call_async(self.goal_task_space_req)
        except Exception as e:
            self.get_logger().info('Sending Goal Kinematic Pose failed %r' % (e,))

    def send_goal_joint_space(self):
        self.goal_joint_space_req.joint_position.joint_name = ['joint1', 'joint2', 'joint3', 'joint4']
        self.goal_joint_space_req.joint_position.position = [goal_joint_angle[0], goal_joint_angle[1], goal_joint_angle[2], goal_joint_angle[3]]
        self.goal_joint_space_req.path_time = path_time

        try:
            send_goal_joint = self.goal_joint_space.call_async(self.goal_joint_space_req)
        except Exception as e:
            self.get_logger().info('Sending Goal Joint failed %r' % (e,))

    def kinematics_pose_callback(self, msg):
        present_kinematics_pose[0] = msg.pose.position.x
        present_kinematics_pose[1] = msg.pose.position.y
        present_kinematics_pose[2] = msg.pose.position.z
        present_kinematics_pose[3] = msg.pose.orientation.w
        present_kinematics_pose[4] = msg.pose.orientation.x
        present_kinematics_pose[5] = msg.pose.orientation.y
        present_kinematics_pose[6] = msg.pose.orientation.z

    def joint_state_callback(self, msg):
        present_joint_angle[0] = msg.position[0]
        present_joint_angle[1] = msg.position[1]
        present_joint_angle[2] = msg.position[2]
        present_joint_angle[3] = msg.position[3]

    def open_manipulator_state_callback(self, msg):
        if msg.open_manipulator_moving_state == 'STOPPED':
            for index in range(0, 7):
                goal_kinematics_pose[index] = present_kinematics_pose[index]
            for index in range(0, 4):
                goal_joint_angle[index] = present_joint_angle[index]

    def send_goal_tool_space(self):

        self.goal_tool_control_req.joint_position.joint_name = ['gripper']
        self.goal_tool_control_req.joint_position.position = [goal_tool_angle[0]]
        self.goal_tool_control_req.path_time = 0.5

        try:
            send_goal_tool = self.goal_tool_control.call_async(self.goal_tool_control_req)
        except Exception as e:
            self.get_logger().info('Sending Goal Tool failed %r' % (e,))

def get_key(settings):
    if os.name == 'nt':
        return msvcrt.getch().decode('utf-8')
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''

    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    print_present_values()
    return key

def print_present_values():
    print(usage)
    print('Joint Angle(Rad): [{:.6f}, {:.6f}, {:.6f}, {:.6f}]'.format(
        present_joint_angle[0],
        present_joint_angle[1],
        present_joint_angle[2],
        present_joint_angle[3]))
    print('Kinematics Pose(Pose X, Y, Z | Orientation W, X, Y, Z): {:.3f}, {:.3f}, {:.3f} | {:.3f}, {:.3f}, {:.3f}, {:.3f}'.format(
        present_kinematics_pose[0],
        present_kinematics_pose[1],
        present_kinematics_pose[2],
        present_kinematics_pose[3],
        present_kinematics_pose[4],
        present_kinematics_pose[5],
        present_kinematics_pose[6]))
    print('Gripper Angle(Rad): {:.6f}  # !!!'.format(goal_tool_angle[0]))  # 新增印出爪子角度


def main():
    settings = None
    if os.name != 'nt':
        settings = termios.tcgetattr(sys.stdin)

    try:
        rclpy.init()
    except Exception as e:
        print(e)

    try:
        teleop_keyboard = TeleopKeyboard()
        start_voice_thread(teleop_keyboard)  # 加在 main() 的 try 區塊裡

    except Exception as e:
        print(e)

    try:
        while(rclpy.ok()):
            rclpy.spin_once(teleop_keyboard)
            key_value = get_key(settings)
            if key_value == 'w':
                goal_kinematics_pose[0] = prev_goal_kinematics_pose[0] + task_position_delta
                teleop_keyboard.send_goal_task_space()
            elif key_value == 'x':
                goal_kinematics_pose[0] = prev_goal_kinematics_pose[0] - task_position_delta
                teleop_keyboard.send_goal_task_space()
            elif key_value == 'a':
                goal_kinematics_pose[1] = prev_goal_kinematics_pose[1] + task_position_delta
                teleop_keyboard.send_goal_task_space()
            elif key_value == 'd':
                goal_kinematics_pose[1] = prev_goal_kinematics_pose[1] - task_position_delta
                teleop_keyboard.send_goal_task_space()
            elif key_value == 'q':
                goal_kinematics_pose[2] = prev_goal_kinematics_pose[2] + task_position_delta
                teleop_keyboard.send_goal_task_space()
            elif key_value == 'z':
                goal_kinematics_pose[2] = prev_goal_kinematics_pose[2] - task_position_delta
                teleop_keyboard.send_goal_task_space()
            elif key_value == 'y':
                goal_joint_angle[0] = prev_goal_joint_angle[0] + joint_angle_delta
                teleop_keyboard.send_goal_joint_space()
            elif key_value == 'h':
                goal_joint_angle[0] = prev_goal_joint_angle[0] - joint_angle_delta
                teleop_keyboard.send_goal_joint_space()
            elif key_value == 'u':
                goal_joint_angle[1] = prev_goal_joint_angle[1] + joint_angle_delta
                teleop_keyboard.send_goal_joint_space()
            elif key_value == 'j':
                goal_joint_angle[1] = prev_goal_joint_angle[1] - joint_angle_delta
                teleop_keyboard.send_goal_joint_space()
            elif key_value == 'i':
                goal_joint_angle[2] = prev_goal_joint_angle[2] + joint_angle_delta
                teleop_keyboard.send_goal_joint_space()
            elif key_value == 'k':
                goal_joint_angle[2] = prev_goal_joint_angle[2] - joint_angle_delta
                teleop_keyboard.send_goal_joint_space()
            elif key_value == 'o':
                goal_joint_angle[3] = prev_goal_joint_angle[3] + joint_angle_delta
                teleop_keyboard.send_goal_joint_space()
            elif key_value == 'l':
                goal_joint_angle[3] = prev_goal_joint_angle[3] - joint_angle_delta
                teleop_keyboard.send_goal_joint_space()
            elif key_value == '1':
                goal_joint_angle[0] = 0.0
                goal_joint_angle[1] = 0.0
                goal_joint_angle[2] = 0.0
                goal_joint_angle[3] = 0.0
                teleop_keyboard.send_goal_joint_space()
            elif key_value == '2':
                goal_joint_angle[0] = 0.0
                goal_joint_angle[1] = -1.05
                goal_joint_angle[2] = 0.35
                goal_joint_angle[3] = 0.70
                teleop_keyboard.send_goal_joint_space()
            elif key_value == 'g':
                goal_tool_angle[0] = 0.0
                teleop_keyboard.send_goal_tool_space()
            elif key_value == 'f':
                goal_tool_angle[0] = -0.01
                teleop_keyboard.send_goal_tool_space()
            

            elif key_value == 'n':
                # 按下 n 夾取
                target_joint = [0.001534, 0.018408, 0.018408, 0.004602]  # 設定抓取姿勢
                step = 0.04                              # 每次移動的角度
                delay = 0.05                             # 每步之間的延遲秒數

                for i in reversed(range(4)):
                    while abs(goal_joint_angle[i] - target_joint[i]) > step:
                        if goal_joint_angle[i] < target_joint[i]:
                            goal_joint_angle[i] += step
                            if goal_joint_angle[i] > target_joint[i]:
                                goal_joint_angle[i] = target_joint[i]
                        else:
                            goal_joint_angle[i] -= step
                            if goal_joint_angle[i] < target_joint[i]:
                                goal_joint_angle[i] = target_joint[i]

                        teleop_keyboard.send_goal_joint_space()
                        rclpy.spin_once(teleop_keyboard, timeout_sec=0.05)
                        import time; time.sleep(delay)
                # 移動完成後夾取
                goal_tool_angle[0] = -0.01
                teleop_keyboard.send_goal_tool_space()

            elif key_value == 'm':
                # 按下 m 收回
                target_joint = [-0.081301, -1.038505, 0.684155, 1.402058]  # 設定抓取姿勢角度
                step = 0.04                              # 每次移動的角度
                delay = 0.05                             # 每步之間的延遲秒數

                for i in range(4):
                    while abs(goal_joint_angle[i] - target_joint[i]) > step:
                        if goal_joint_angle[i] < target_joint[i]:
                            goal_joint_angle[i] += step
                            if goal_joint_angle[i] > target_joint[i]:
                                goal_joint_angle[i] = target_joint[i]
                        else:
                            goal_joint_angle[i] -= step
                            if goal_joint_angle[i] < target_joint[i]:
                                goal_joint_angle[i] = target_joint[i]

                        teleop_keyboard.send_goal_joint_space()
                        rclpy.spin_once(teleop_keyboard, timeout_sec=0.05)
                        import time; time.sleep(delay)
                # 移動完成後，立即夾取
                teleop_keyboard.send_goal_tool_space()
                print('已夾取！') 
            elif key_value == 'b':
                #按下 b，手臂慢慢移動到抓取姿勢，然後放下
                target_joint = [-0.230097, 0.817612, -0.503146, 1.256330]  # 設定抓取姿勢角度
                step = 0.04                              # 每次移動的角度
                delay = 0.05                             # 每步之間的延遲秒數

                for i in reversed(range(4)):
                    while abs(goal_joint_angle[i] - target_joint[i]) > step:
                        if goal_joint_angle[i] < target_joint[i]:
                            goal_joint_angle[i] += step
                            if goal_joint_angle[i] > target_joint[i]:
                                goal_joint_angle[i] = target_joint[i]
                        else:
                            goal_joint_angle[i] -= step
                            if goal_joint_angle[i] < target_joint[i]:
                                goal_joint_angle[i] = target_joint[i]

                        teleop_keyboard.send_goal_joint_space()
                        rclpy.spin_once(teleop_keyboard, timeout_sec=0.05)
                        import time; time.sleep(delay)
                # 移動完成後，立即夾取
                goal_tool_angle[0] = 0.0
                teleop_keyboard.send_goal_tool_space()
                print('已夾取！')

            else:
                if key_value == '\x03':
                    break
                else:
                    for index in range(0, 7):
                        prev_goal_kinematics_pose[index] = goal_kinematics_pose[index]
                    for index in range(0, 4):
                        prev_goal_joint_angle[index] = goal_joint_angle[index]
    

    except Exception as e:
        print(e)

    finally:
        if os.name != 'nt':
            termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        teleop_keyboard.destroy_node()
        rclpy.shutdown()
        
    def do_grasp_action(teleop_keyboard):
        target_joint = [-0.230097, 0.817612, -0.503146, 1.256330]
        step = 0.04
        delay = 0.05

        for i in reversed(range(4)):
            while abs(goal_joint_angle[i] - target_joint[i]) > step:
                if goal_joint_angle[i] < target_joint[i]:
                    goal_joint_angle[i] += step
                    if goal_joint_angle[i] > target_joint[i]:
                        goal_joint_angle[i] = target_joint[i]
                else:
                    goal_joint_angle[i] -= step
                    if goal_joint_angle[i] < target_joint[i]:
                        goal_joint_angle[i] = target_joint[i]

                teleop_keyboard.send_goal_joint_space()
                rclpy.spin_once(teleop_keyboard, timeout_sec=0.05)
                import time; time.sleep(delay)

        goal_tool_angle[0] = -0.01
        teleop_keyboard.send_goal_tool_space()
        print('語音夾取完成')


if __name__ == '__main__':
    main()
