import roslaunch
import rospy
import time
import sys
import numpy as np


class creating_graph_and_launch(object):

    def __init__(self, input_augument, time_sleep=15):
        self.time_sleep = time_sleep
        self.input_augument = input_augument
        self.ros_file_launch = roslaunch.rlutil.get_or_generate_uuid(None, False)
        roslaunch.configure_logging(self.ros_file_launch)
        self.launch_start_end = roslaunch.scriptapi.ROSLaunch()


    def robot_and_obstacle_bot_tuw_launch(self):
        launch1 = ['robot_navigation', 'robot_and_obstacle_bot_tuw.launch', ('room:='+ str(self.input_augument[1].toString()))]

        roslaunch_file1 = roslaunch.rlutil.resolve_launch_arguments(launch1)
        roslaunch_args1 = launch1[1:]

        launch_files = [(roslaunch_file1, roslaunch_args1)]
        self.launch_start_end.parent = roslaunch.parent.ROSLaunchParent(self.ros_file_launch, launch_files)
        self.launch_start_end.start()

        time.sleep(self.time_sleep)
        self.launch_start_end.shutdown()

        # try:
        #     self.launch_start_end.spin()
        # finally:
        #     self.launch_start_end.shutdown()


    def robot_and_obstacle_bot_tuw_simulation_launch(self):
        launch2 = ['robot_navigation', 'robot_and_obstacle_bot_simulation_tuw.launch', ('room:='+ str(self.input_augument[1].toString()))]

        self.robot_and_obstacle_bot_tuw_launch()

        roslaunch_file2 = roslaunch.rlutil.resolve_launch_arguments(launch2)
        roslaunch_args2 = launch2[1:]

        launch_files = [(roslaunch_file2, roslaunch_args2)]
        parent = roslaunch.parent.ROSLaunchParent(self.ros_file_launch, launch_files)

        parent.start()


if __name__ == "__main__":
    
    # input_1 = file name(ie: it is by default), input_2 = map to generate(ex: level1)
    augument_list = str(sys.argv)
    augument_array = np.array(augument_list)

    util_launch_files = creating_graph_and_launch(input_augument = augument_array)
    util_launch_files.robot_and_obstacle_bot_tuw_simulation_launch()





