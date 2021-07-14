execute_process(COMMAND "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_geometry/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_geometry/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
