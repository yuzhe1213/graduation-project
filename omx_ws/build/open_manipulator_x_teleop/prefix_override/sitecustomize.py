import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/yuzhe/omx_ws/install/open_manipulator_x_teleop'
