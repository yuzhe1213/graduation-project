from vosk import Model, KaldiRecognizer
import sounddevice as sd
import json
import rclpy
from rclpy.node import Node
from open_manipulator_msgs.srv import SetJointPosition
from sensor_msgs.msg import JointState

# --- 初始化參數 ---
goal_joint_angle = [0.0, 0.0, 0.0, 0.0]
goal_tool_angle = [0.0]

# --- 語音辨識模型 ---
model = Model("/home/yuzhe/vosk_models/model-cn")
recognizer = KaldiRecognizer(model, 16000)
recognizer.SetWords(False)

# --- ROS2 節點 ---
class VoiceArmControl(Node):
    def __init__(self):
        super().__init__('voice_arm_control')
        self.tool_client = self.create_client(SetJointPosition, 'goal_tool_control')
        self.joint_client = self.create_client(SetJointPosition, 'goal_joint_space_path')
        self.joint_sub = self.create_subscription(JointState, 'joint_states', self.joint_callback, 10)

    def joint_callback(self, msg):
        for i in range(4):
            goal_joint_angle[i] = msg.position[i]

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

def listen_and_control(node):
    def callback(indata, frames, time, status):
        if recognizer.AcceptWaveform(bytes(indata)):
            result = json.loads(recognizer.Result())
            text = result.get("text", "")
            print(f"🎤 辨識：{text}")

            if "家" in text:
                print("→ 語音：家 → 執行夾取")
                node.send_joint([-0.230097, 0.817612, -0.503146, 1.256330])
                node.send_gripper(-0.01)
            elif "收" in text:
                print("→ 語音：收 → 執行收回")
                node.send_joint([-0.081301, -1.038505, 0.684155, 1.402058])
            elif "放" in text:
                print("→ 語音：放 → 放開")
                node.send_gripper(0.0)
            elif "初始化" in text or "歸位" in text:
                print("→ 語音：初始化")
                node.send_joint([-0.230097, 0.817612, -0.503146, 1.256330])
    
    stream = sd.InputStream(samplerate=16000, blocksize=8000, dtype='int16', channels=1, callback=callback)
    with stream:
        print("🟢 語音控制啟動中：請說『家』、『收』、『放』、『初始化』")
        while True:
            pass

def main():
    rclpy.init()
    node = VoiceArmControl()
    listen_and_control(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
