#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_gazebo/tuw_gazebo_plugins"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/lib/python2.7/dist-packages:/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_gazebo_plugins/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_gazebo_plugins" \
    "/usr/bin/python2" \
    "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/src/tuw_gazebo/tuw_gazebo_plugins/setup.py" \
     \
    build --build-base "/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/build/tuw_gazebo_plugins" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install" --install-scripts="/home/csrobot/Desktop/NERVE_CENTER/ROS_navigation_localization/catkin_ws/install/bin"
