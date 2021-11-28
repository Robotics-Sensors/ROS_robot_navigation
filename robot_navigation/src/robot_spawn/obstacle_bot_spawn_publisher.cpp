/*  
    The obstacle_bot spawns publisher node publishes the dedicated starting position to the spawn topic for the obstacle_bot.  In a navigation test, a starting position are specified in a csv file and the
    obstacle_bot spawn between the specified spawn for a specifed number of iterations. This node also handles parsing the starting position in csv file and also within the launch file.
*/

#include "ros/ros.h"
#include <string>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/Twist.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/Int32.h>
#include <boost/algorithm/string.hpp>
#include <stdexcept>


class obstacle_bot_spawn {
private:
    ros::NodeHandle node_handle;
    ros::Publisher obstacle_bot_spawn_publisher;
    std::ifstream csvFile;
    std::string file_location;
    std::string csvLine;

    geometry_msgs::Twist twist_val;
    geometry_msgs::PoseWithCovarianceStamped spawn;
    tf2::Quaternion quaternion;
    
    //Position of the robot
    float obstacle_bot_x_position = 0.0;
    float obstacle_bot_y_position = 0.0;
    float obstacle_bot_z_rotation = 0.0;

    //Determine if you want to determinde the input or no of goal
    std::string user_choose;

public:
  obstacle_bot_spawn() {

    //Get file location
    node_handle.getParam(ros::this_node::getName()+"/file_path", file_location);

    csvFile.open(file_location.c_str());
    /* if (!csvFile){ */
      /* ROS_ERROR("Unable to open spawn file for obstacle bot"); */
      /* throw std::invalid_argument("Invalid file name"); */
    /* } */

    node_handle.getParam(ros::this_node::getName()+"/user_choose", user_choose);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_x_position", obstacle_bot_x_position);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_y_position", obstacle_bot_y_position);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_z_rotation", obstacle_bot_z_rotation);

    // Open  file for starting position
    std::getline(csvFile, csvLine); 
    spawn.header.frame_id = "map";

    // While loop for getting the goal position from the 
    while (std::getline(csvFile, csvLine)){
      if (!csvLine.empty()){
        std::vector<std::string> data;
        boost::algorithm::split(data, csvLine, boost::is_any_of(","));

        //  Determin if you input the starting location or not
        if (user_choose == "csvInput"){
            spawn.pose.pose.position.x = std::stod(data[1].c_str());
            spawn.pose.pose.position.y = std::stod(data[2].c_str());
            spawn.pose.pose.position.z = 0;
            quaternion.setRPY( 0, 0, std::stod(data[3].c_str()));
            spawn.pose.pose.orientation.z = quaternion[2];
            spawn.pose.pose.orientation.w = quaternion[3];

        }
        else if (user_choose == "userInput"){
            spawn.pose.pose.position.x = obstacle_bot_x_position;
            spawn.pose.pose.position.y = obstacle_bot_y_position;
            spawn.pose.pose.position.z = 0;
            quaternion.setRPY( 0, 0, obstacle_bot_z_rotation);
            spawn.pose.pose.orientation.z = quaternion[2];
            spawn.pose.pose.orientation.w = quaternion[3];

        }

    // Goal message published for the obstacle_bot
    spawn.header.stamp = ros::Time::now();
    obstacle_bot_spawn_publisher.publish(spawn);
    ROS_INFO("SPAWN_PUB | Point: (%.2f,%.2f)\tRotation: %.2f", spawn.pose.pose.position.x ,  spawn.pose.pose.position.y , std::stod(data[3].c_str()));
    obstacle_bot_spawn_publisher = node_handle.advertise<geometry_msgs::PoseWithCovarianceStamped>("spawn", 1, true);
    }
  }
  }
};


int main(int argc, char **argv){

  ros::init(argc, argv, "obstacle_bot_spawn_publisher");
  obstacle_bot_spawn obstacle_bot_spawn_obj;

  ros::spin();
  ros::shutdown();

  return 0;
}
