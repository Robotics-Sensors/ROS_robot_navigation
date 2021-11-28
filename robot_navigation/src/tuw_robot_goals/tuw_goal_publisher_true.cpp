#include <ros/ros.h>
#include "tuw_multi_robot_msgs/RobotGoalsArray.h"
#include "ros/ros.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <ros/ros.h>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "tuw_geometry/utils.h"


class robot_goal_publisher{
private:
  std::vector<robot_navigation::Goal> robot_goal_array;
  std::ifstream csvFile;
  ros::Publisher robot_goal_pub;
  int counter;

  float robot_goal_x_position = 0.0;
  float robot_goal_y_position = 0.0;
  float robot_goal_z_rotation = 0.0;

  // Determine if you want to determinde the input or no of goal
  std::string user_choose;

public:
  robot_goal_publisher(ros::NodeHandle node_handle) {
    
    //Get file location
    std::string file_location;
    node_handle.getParam(ros::this_node::getName() + "/file_path", file_location);

    csvFile.open(file_location.c_str());
    if (!csvFile){
      ROS_ERROR("Unable to open goal file");
      throw std::invalid_argument("Invalid file name");
    }

    node_handle.getParam(ros::this_node::getName()+"user_choose", user_choose);
    node_handle.getParam(ros::this_node::getName()+"/robot_goal_x_position", robot_goal_x_position);
    node_handle.getParam(ros::this_node::getName()+"/robot_goal_y_position", robot_goal_y_position);
    node_handle.getParam(ros::this_node::getName()+"/robot_goal_z_rotation", robot_goal_z_rotation);
    
    // Open  file for goal
    std::string csvLine;
    std::getline(csvFile, csvLine);

    while (std::getline(csvFile, csvLine)){
      if (!csvLine.empty()){
        std::vector<std::string> data;
        boost::algorithm::split(data, csvLine, boost::is_any_of(","));

        //parse the seperated strings into the goal msg
        robot_navigation::Goal goal;
        goal.description = data[0];
        
        // Determine if that is the goal position or not 
        if (user_choose == "csvInput"){
          goal.goal.x = std::stod(data[1].c_str());
          goal.goal.y = std::stod(data[2].c_str());
          goal.goal.theta = std::stod(data[3].c_str());
        }
        else if (user_choose == "userInput"){
          goal.goal.x = robot_goal_x_position;
          goal.goal.y = robot_goal_y_position;
          goal.goal.theta = robot_goal_z_rotation;
        }


        ROS_INFO("Goal: %s registered at x:%f, y:%f and yaw:%f", goal.description.c_str(), goal.goal.x, goal.goal.y, goal.goal.theta);
        robot_goal_array.push_back(goal);
      }
    }




