# Graduation Project (ROS 2 Humble, TurtleBot4 Lite)

本專案在 **Ubuntu 22.04 + ROS 2 Humble** 環境開發，硬體以 **TurtleBot4 Lite** 為主，並整合 **OpenMANIPULATOR-X**。  
Repository 內含兩個 ROS 2 工作區：

```text
omx_ws/         # 手臂相關套件 (open_manipulator, open_manipulator_msgs, robotis_manipulator)
my_ros2_ws/     # 自建工作區 (自訂套件、turtlebot4_navigation 等)
1. 環境需求
Ubuntu 22.04 (Jammy)
```
ROS 2 Humble

colcon、rosdep、git

TurtleBot4 Lite（機器人端已安裝 ROS 2 Humble 與 TB4 套件）

可選：OpenMANIPULATOR-X + U2D2（如使用機械手臂）

2. 安裝 ROS 2 Humble（Ubuntu 22.04）
bash
複製程式碼
# 更新系統
sudo apt update && sudo apt upgrade -y

# 設定地區與來源（若已設定可略）
sudo apt install -y locales curl gnupg lsb-release
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

# 加入 ROS 2 套件庫
sudo apt install -y software-properties-common
sudo add-apt-repository universe -y
sudo apt update
sudo apt install -y curl
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key \
  | sudo tee /usr/share/keyrings/ros-archive-keyring.gpg > /dev/null
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] \
http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" \
| sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# 安裝 ROS 2 Humble Desktop 與常用工具
sudo apt update
sudo apt install -y ros-humble-desktop python3-colcon-common-extensions python3-rosdep

# 初始化 rosdep
sudo rosdep init 2>/dev/null || true
rosdep update

# 每次開新終端機自動載入環境（可加入 ~/.bashrc）
echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc
source ~/.bashrc
3. 取得與更新本專案
bash
複製程式碼
# 取得專案
cd ~
git clone https://github.com/<你的帳號>/graduation-project.git
cd graduation-project
專案已加入 .gitignore，會忽略各工作區的 build/ install/ log/。

4. 專案結構與建置
4.1 omx_ws（OpenMANIPULATOR-X）
bash
複製程式碼
# 進到工作區根目錄
cd ~/graduation-project/omx_ws

# 解析依賴（第一次與變更後建議執行）
rosdep install --from-paths src -y --ignore-src

# 建置
colcon build --symlink-install

# 載入環境（每開一個新終端機都要）
source install/setup.bash
常見套件（本 repo 已內含）：
open_manipulator, open_manipulator_msgs, robotis_manipulator

4.2 my_ros2_ws（自建工作區）
bash
複製程式碼
cd ~/graduation-project/my_ros2_ws

# 若 src 有新套件，先補齊依賴
rosdep install --from-paths src -y --ignore-src

# 建置
colcon build --symlink-install

# 載入環境
source install/setup.bash
5. TurtleBot4 Lite 基本使用
下列以筆電端操作為例，請先與機器人連到同一網段。
若需遠端連線，請依你的網路設定補上 ROS_DOMAIN_ID 或 Fast DDS discovery 設定。

5.1 安裝 TurtleBot4 相關套件（若尚未安裝）
bash
複製程式碼
sudo apt install -y ros-humble-turtlebot4-* ros-humble-navigation2 ros-humble-nav2-bringup
5.2 機器人最小啟動（Bringup）
在機器人端（或透過 SSH 到機器人）：

bash
複製程式碼
export TURTLEBOT4_MODEL=lite
ros2 launch turtlebot4_bringup minimal.launch.py
5.3 導航（Nav2）
有現成地圖：

bash
複製程式碼
# 筆電端，載入 my_ros2_ws 的環境
source ~/graduation-project/my_ros2_ws/install/setup.bash

# 啟動導航（map:= 你的地圖檔 .yaml）
ros2 launch turtlebot4_navigation nav2.launch.py map:=/path/to/map.yaml use_sim_time:=false
即時建圖（SLAM）可改用對應的 slam/bringup 方案（依你專案提供的 launch 檔為準）。

6. OpenMANIPULATOR-X 基本使用
6.1 U2D2 規則（選用）
若使用 U2D2，建議新增 udev 規則讓裝置名稱固定，例如：

text
複製程式碼
SYMLINK+="U2D2"
完成後重新插拔裝置，並確認連線埠名稱。

6.2 啟動控制與遙控
bash
複製程式碼
# 載入手臂工作區環境
source ~/graduation-project/omx_ws/install/setup.bash

# 控制器
ros2 launch open_manipulator_x_controller open_manipulator_x_controller.launch.py

# 遙控（鍵盤/GUI 等）
ros2 launch open_manipulator_x_teleop open_manipulator_x_teleop.launch.py
若你的專案提供了自訂的節點或服務（例如夾爪服務 goal_tool_control、關節命令 goal_joint_space_path 等），請在此補充對應的啟動與呼叫方式。

7. 常見指令
bash
複製程式碼
# 重新建置單一工作區
cd ~/graduation-project/omx_ws && colcon build --symlink-install
cd ~/graduation-project/my_ros2_ws && colcon build --symlink-install

# 載入環境（不同終端機都要）
source ~/graduation-project/omx_ws/install/setup.bash
source ~/graduation-project/my_ros2_ws/install/setup.bash

# 檢視可用主題/服務/動作
ros2 topic list
ros2 service list
ros2 action list
8. 專案開發與貢獻
bash
複製程式碼
# 拉取最新
git pull origin main --rebase

# 新增或修改檔案
git add .
git commit -m "說明此次修改"
git push
注意：請不要把 build/ install/ log/ 推上 GitHub。
若誤加，請移除追蹤後再提交：

bash
複製程式碼
git rm -r --cached **/build **/install **/log
git commit -m "clean artifacts"
git push
9. 疑難排解
GitHub 無法展開資料夾且檔案型態顯示 160000
→ 表示被當成 git submodule。請移除子資料夾內的 .git，並在專案根目錄執行：

bash
複製程式碼
git rm --cached <path>
git add .
git commit -m "fix submodule issue"
git push
colcon build 依賴缺失
→ 請先執行：

bash
複製程式碼
rosdep install --from-paths src -y --ignore-src
TurtleBot4 無法連線
→ 確認與機器人同網段、時間同步、必要埠未被防火牆阻擋，並檢查
TURTLEBOT4_MODEL 與對應套件是否安裝完整
