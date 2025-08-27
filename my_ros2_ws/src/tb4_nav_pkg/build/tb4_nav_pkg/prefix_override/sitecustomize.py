import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/yuzhe/my_ros2_ws/src/tb4_nav_pkg/install/tb4_nav_pkg'
