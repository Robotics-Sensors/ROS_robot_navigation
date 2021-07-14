# Install script for directory: /home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install" TYPE PROGRAM FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install" TYPE PROGRAM FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/setup.bash;/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install" TYPE FILE FILES
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/setup.bash"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/setup.sh;/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install" TYPE FILE FILES
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/setup.sh"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/setup.zsh;/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install" TYPE FILE FILES
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/setup.zsh"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install" TYPE FILE FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tuw_multi_robot_msgs/msg" TYPE FILE FILES
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/RobotGoals.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/RobotGoalsArray.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/RoutePrecondition.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/RouteSegment.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/Route.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/RouterStatus.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/Vertex.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/Graph.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/RobotInfo.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/Order.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/OrderArray.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/Pickup.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/OrderPosition.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/Station.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/StationArray.msg"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/msg/RouteProgress.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tuw_multi_robot_msgs/srv" TYPE FILE FILES
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/srv/StationManagerControlProtocol.srv"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/srv/StationManagerStationProtocol.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tuw_multi_robot_msgs/cmake" TYPE FILE FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/tuw_multi_robot_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/devel/.private/tuw_multi_robot_msgs/include/tuw_multi_robot_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/devel/.private/tuw_multi_robot_msgs/share/roseus/ros/tuw_multi_robot_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/devel/.private/tuw_multi_robot_msgs/share/common-lisp/ros/tuw_multi_robot_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/devel/.private/tuw_multi_robot_msgs/share/gennodejs/ros/tuw_multi_robot_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/devel/.private/tuw_multi_robot_msgs/lib/python2.7/dist-packages/tuw_multi_robot_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/devel/.private/tuw_multi_robot_msgs/lib/python2.7/dist-packages/tuw_multi_robot_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/tuw_multi_robot_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tuw_multi_robot_msgs/cmake" TYPE FILE FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/tuw_multi_robot_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tuw_multi_robot_msgs/cmake" TYPE FILE FILES
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/tuw_multi_robot_msgsConfig.cmake"
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/catkin_generated/installspace/tuw_multi_robot_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tuw_multi_robot_msgs" TYPE FILE FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/tuw_multi_robot_msgs" TYPE DIRECTORY FILES "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_msgs/tuw_multi_robot_msgs/include/tuw_multi_robot_msgs/" FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "/\\.svn$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_multi_robot_msgs/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
