from setuptools import find_packages, setup

package_name = 'tb4_nav_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yuzhe',
    maintainer_email='yuzhe@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
    'console_scripts': [
        'vosk_arm = tb4_nav_pkg.vosk_arm:main',
        'nav_action_server = tb4_nav_pkg.nav_action_server:main',
        'tb4_nav = tb4_nav_pkg.tb4_nav:main'
    ],
},

)
