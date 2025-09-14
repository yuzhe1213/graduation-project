# 語音搬運助理 (ROS 2 Humble, TurtleBot4 Lite)

# 專題介紹

本專題以 **TurtleBot4 Lite 行動平台** 為核心，結合 **OpenMANIPULATOR-X 機械手臂**，建置一套基於 **ROS 2 Humble** 的智慧型服務機器人系統。研究目標在於讓機器人能在室內環境中透過語音辨識完成自主導航、抓取與搬運等任務，進一步驗證服務型機器人在實際應用上的可行性。

---

## 專案架構

本專案包含多個 ROS 2 工作區（workspace）：

- **`omx_ws`**  
  整合機械手臂相關套件，如 `open_manipulator`、`open_manipulator_msgs`、`robotis_manipulator`，用於控制手臂運動與夾爪操作。

- **`my_ros2_ws`**  
  自建的 ROS 2 工作區，包含語音控制、導航整合、影像處理等模組，用於拓展機器人的智慧化功能。

- **`turtlebot4_navigation`**  
  針對 TurtleBot4 進行導航與路徑規劃參數調整，實現地圖建構、路徑規劃與避障功能。

- **`ros`**  
  提供額外 ROS 2 相依套件與測試環境，確保專案能完整建置與運行。

---

## 系統功能

1. **自主導航**  
   使用 Nav2 套件搭配 SLAM 技術，機器人可在未知或已知地圖中進行自主移動，並能在動態環境下避開障礙物。

2. **語音控制**  
   整合 Vosk 中文語音辨識模組，支援語音指令（如「餅乾」、「飲料」、「麵包」），提升人機互動的自然性。

3. **機械手臂操作**  
   機械手臂能在導航抵達指定地點後，自動進行物品夾取與放置，完成「從起點搬運到目標區域」的完整任務。

---

## 專題目標

- 建立一個可同時進行 **自主導航** 與 **操作手臂** 的 ROS 2 系統。  
- 整合語音與運動控制，實現簡單的智慧型服務應用（如物品搬運）。  
- 探討 ROS 2 多工作區整合與實驗參數調整，累積開發與實作經驗。

---
# 以下為一些基本的安裝流程

## Ubuntu 22.04安裝教學：
進入這個網站下載映像檔 - > https://releases.ubuntu.com/jammy/

載完之後進入BIOS進行安裝動作，磁碟分割請依照自行所需來進行分割

進入ubuntu以後再來安裝ROS 2 Humble

## ROS 2 Humble 安裝教學：
```text
$ locale  # check for UTF-8

$ sudo apt update && sudo apt install locales
$ sudo locale-gen en_US en_US.UTF-8
$ sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
$ export LANG=en_US.UTF-8

$ locale  # verify settings

$ sudo apt install software-properties-common
$ sudo add-apt-repository universe
$ sudo apt update && sudo apt install curl -y
$ export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F\" '{print $4}')
$ curl -L -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo $VERSION_CODENAME)_all.deb" # If using Ubuntu derivates use $UBUNTU_CODENAME
$ sudo dpkg -i /tmp/ros2-apt-source.deb
$ sudo apt update
$ sudo apt upgrade
$ sudo apt install ros-humble-desktop
$ sudo apt install ros-humble-ros-base
$ sudo apt install ros-dev-tools
```
PC都設置好接著就是turtlebot4的部分

樹梅派的映象檔可以從這個網站進行安裝自行所需的版本 -> http://download.ros.org/downloads/turtlebot4/ (需與電腦ubuntu的版本一致)

接者再從這邊進行基本設置 -> https://turtlebot.github.io/turtlebot4-user-manual/setup/basic.html

## Open Manipulator X 手臂安裝教學：
安裝套件 ( 需要 PC & TurtleBot4 皆安裝 )
```text
$ sudo apt install ros-humble-joint-state-publisher ros-humble-ament-cmake ros-humble-dynamixel-sdk ros-humble-dynamixel-workbench
```
到這邊以後就可以將github上的 omx_ws/ & my_ros2_ws/ 裝上去
如果想自行動手嘗試做也可以繼續裝下去
```text
$ mkdir -p omx_ws/src
$ cd omx_ws/src
$ git clone -b ros2 https://github.com/ROBOTIS-GIT/open_manipulator_msgs.git
$ git clone -b ros2 https://github.com/ROBOTIS-GIT/robotis_manipulator.git
$ git clone -b humble-devel https://github.com/ROBOTIS-GIT/open_manipulator.git
```
開啟 robotis_manipulator/CMakeLists.txt 文件並刪除 20、37、77 行使用 cmake_modules 套件語法，改完之後重新編譯。
```text
$ cd ~/omx_ws && colcon build --symlink-install
$ echo "source ~/omx_ws/install/setup.bash" >> ~/.bashrc
```
TurtleBot4 端執行腳本修改 U2D2 權限及 lantency_timer。
```text
$ ros2 run open_manipulator_x_controller create_udev_rules
```
執行 ( 限於 TurtleBot4 端操作 )
```text
$ ros2 launch open_manipulator_x_controller open_manipulator_x_controller.launch.py
```
遙控 ( 兩端皆可操作 )
```text
$ ros2 run open_manipulator_x_teleop teleop_keyboard
```
## 建置
每個檔案編輯過記得都要重新建置
colcon build --symlink-install
# 繪製地圖
```text
$ ros2 launch turtlebot4_navigation slam.launch.py
打開rivz2來看地圖繪製的狀況
$ ros2 launch turtlebot4_viz view_robot.launch.py
跑完之後就可以儲存地圖了
$ ros2 service call /slam_toolbox/save_map slam_toolbox/srv/SaveMap "name:
  data: 'map_name'"
```
都弄完之後接下來就可以執行檔案了

本次專題一共用到六個終端機
# 指令介紹
1. 啟動地圖
```text
$ ros2 launch turtlebot4_navigation localization.launch.py map:=map.yaml
```
2. 啟動 Navigation
```text
$ ros2 launch turtlebot4_navigation nav2.launch.py
```
3. 開啟Rviz視窗以此監控整個實驗過程
```text
$ ros2 launch turtlebot4_viz view_robot.launch.py
```
4. 在執行手臂的節點之前必須啟動手臂的控制器套件，該指令必須在 Raspberry Pi 端執行
```text
$ ros2 launch open_manipulator_x_controller open_manipulator_x_controller.launch.py
```
5. 執行語音辨識以及手臂的節點
```text
$ ros2 run tb4_nav_pkg vosk_arm
```
6. 執行 tb4_nav 節點，當vosk_arm 發布「餅乾、飲料、電池」等目標名稱時，tb4_nav 會根據目標名稱切換對應的座標，並在夾取完成後回到放置點
```text
$ ros2 run tb4_nav_pkg tb4_nav
```
