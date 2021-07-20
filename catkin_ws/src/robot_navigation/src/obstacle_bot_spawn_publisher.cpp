#include "ros/ros.h"
#include <string>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Int32.h>


class obstacle_bot_spawn {
private:
    ros::NodeHandle node_handle;
    ros::Publisher obstacle_bot_spawn_publisher;
    /* ros::Subscriber obstacle_bot_subscriber; */

    geometry_msgs::Twist twist_val;
    geometry_msgs::PoseWithCovarianceStamped spawn;
    tf2::Quaternion quaternion;
    /* sensor_msgs::LaserScan laser_scan_val; */

    float obstacle_bot_x_position = 0.0;
    float obstacle_bot_y_position = 0.0;
    float obstacle_bot_z_rotation = 0.0;

public:
  obstacle_bot_spawn() {
    ROS_INFO("SPAWN_PUB | Point: (%.2f,%.2f)\tRotation: %.2f",obstacle_bot_x_position,obstacle_bot_y_position,obstacle_bot_z_rotation);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_x_position", obstacle_bot_x_position);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_y_position", obstacle_bot_y_position);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_z_position", obstacle_bot_z_rotation);
    obstacle_bot_spawn_publisher = node_handle.advertise<geometry_msgs::PoseWithCovarianceStamped>("spawn", 1, true);
  }


  void spawnning_obstacle_bot() {
    //Construct Spawn message for the obstacle_bot 
    spawn.header.frame_id = "map";
    spawn.pose.pose.position.x = obstacle_bot_x_position;
    spawn.pose.pose.position.y = obstacle_bot_y_position;
    spawn.pose.pose.position.z = 0;
    quaternion.setRPY( 0, 0, obstacle_bot_z_rotation);
    spawn.pose.pose.orientation.z = quaternion[2];
    spawn.pose.pose.orientation.w = quaternion[3];

    // Goal message published for the obstacle_bot
    spawn.header.stamp = ros::Time::now();
    obstacle_bot_spawn_publisher.publish(spawn);
    }
};


int main(int argc, char **argv) {

    ros::init(argc, argv, "obstacle_bot_spawn_publisher");
    obstacle_bot_spawn obstacle_bot_spawn_obj;

    obstacle_bot_spawn_obj.spawnning_obstacle_bot();
    ros::spin();


  return 0;
}
