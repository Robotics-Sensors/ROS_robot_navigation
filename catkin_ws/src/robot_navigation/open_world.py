import roslaunch
import rospy
import time
import sys
import numpy as np


class creating_graph_and_launch(object):
    def __init__(self, input_augument, time_sleep=2):
        self.time_sleep = time_sleep
        self.input_augument = input_augument
        self.ros_file_launch = roslaunch.rlutil.get_or_generate_uuid(None, False)
        roslaunch.configure_logging(self.ros_file_launch)

        # ROS launch the first launch file
        self.robot_and_obstacle_bot_tuw_launch()


    def robot_and_obstacle_bot_tuw_launch(self):
        launch1 = ['robot_navigation', 'robot_and_obstacle_bot_tuw.launch', ('room:='+ self.input_augument[1])]

        roslaunch_file1 = roslaunch.rlutil.resolve_launch_arguments(launch1)
        print(roslaunch_file1)
        print(launch1)
        roslaunch_args1 = launch1[2:]

        launch_files = [(roslaunch_file1, roslaunch_args1)]
        parent = roslaunch.parent.ROSLaunchParent(self.ros_file_launch, roslaunch_file1)

        parent.start()
        time.sleep(2)
        parent.shutdown()

    def robot_and_obstacle_bot_tuw_simulation_launch(self):
        launch2 = ['robot_navigation', 'robot_and_obstacle_bot_simulation_tuw.launch', ('room:='+ self.input_augument[1])]

        roslaunch_file2 = roslaunch.rlutil.resolve_launch_arguments(launch2)
        roslaunch_args2 = launch2[2:]
        launch_files = [roslaunch_file2, roslaunch_args2]
        parent = roslaunch.parent.ROSLaunchParent(self.ros_file_launch, roslaunch_file2)

        parent.start()
        time.sleep(100)

if __name__ == "__main__":
    
    # input_1 = file name(ie: it is by default), input_2 = map to generate(ex: level1)
    augument_list = sys.argv

    util_launch_files = creating_graph_and_launch(input_augument = augument_list)
    util_launch_files.robot_and_obstacle_bot_tuw_simulation_launch()





