#include "ros/ros.h"
#include <string>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Int32.h>


class robot_spawn {
private:
    ros::NodeHandle node_handle;
    ros::Publisher robot_spawn_publisher;
    /* ros::Subscriber robot_subscriber; */

    geometry_msgs::Twist twist_val;
    geometry_msgs::PoseWithCovarianceStamped spawn;
    tf2::Quaternion quaternion;
    /* sensor_msgs::LaserScan laser_scan_val; */

    float robot_x_position = 0.0;
    float robot_y_position = 0.0;
    float robot_z_rotation = 0.0;

public:
  robot_spawn() {
    ROS_INFO("SPAWN_PUB | Point: (%.2f,%.2f)\tRotation: %.2f",robot_x_position,robot_y_position,robot_z_rotation);
    node_handle.getParam(ros::this_node::getName()+"/robot_x_position", robot_x_position);
    node_handle.getParam(ros::this_node::getName()+"/robot_y_position", robot_y_position);
    node_handle.getParam(ros::this_node::getName()+"/robot_z_position", robot_z_rotation);
    robot_spawn_publisher = node_handle.advertise<geometry_msgs::PoseWithCovarianceStamped>("spawn", 1, true);
  }

  /* void move_robot_callback(const sensor_msgs::LaserScan::ConstPtr &message) { */
  /* } */


  void spawnning_robot() {
    //Construct Spawn message for the robot 
    spawn.header.frame_id = "map";
    spawn.pose.pose.position.x = robot_x_position;
    spawn.pose.pose.position.y = robot_y_position;
    spawn.pose.pose.position.z = 0;
    quaternion.setRPY( 0, 0, robot_z_rotation );
    spawn.pose.pose.orientation.z = quaternion[2];
    spawn.pose.pose.orientation.w = quaternion[3];

    // Goal message published for the robot
    spawn.header.stamp = ros::Time::now();
    robot_spawn_publisher.publish(spawn);
    }
};


int main(int argc, char **argv) {

    ros::init(argc, argv, "robot_spawn_publisher");
    robot_spawn robot_spawn_obj;

    robot_spawn_obj.spawnning_robot();
    ros::spin();


  return 0;
}
