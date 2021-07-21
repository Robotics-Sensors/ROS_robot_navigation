/*  
    The obstacle_bot goal publisher node publishes the current navigation goal to the goal topic for the robot.  In a navigation test, a set of navigation goals are specified in a csv file and the
    obstacle_bot travels between the specified goals for a specifed number of iterations. It also keeps track which goal is the current goal and the next goal is recieved
    if the obstacle_bot_goal_publisher service is called.  This node also handles parsing the goal csv file goals within the launch file.
*/

#include <ros/ros.h>
#include <string>
#include <sstream>
#include <std_srvs/Empty.h>
#include <geometry_msgs/Pose2D.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <robot_navigation/Goal.h>
#include <boost/algorithm/string.hpp>
#include <stdexcept>

class obstacle_bot_goal_publisher{
private:
  std::vector<obstacle_bot_navigation::Goal> robot_goal_array;
  std::ifstream csvFile;

  ros::Publisher obstacle_bot_goal_publisher;
  int counter;

  float obstacle_bot_goal_x_position = 0.0;
  float obstacle_bot_goal_y_position = 0.0;
  float obstacle_bot_goal_z_rotation = 0.0;

public:
  ros::NodeHandle node_handle;
  obstacle_bot_goal_publisher() {

    /* if (obstacle_bot_goal_x_position == 0.0 && robot_goal_y_position == 0.0 && robot_goal_z_rotation){ */
    //Get file location
    std::string file_location;
    node_handle.getParam(ros::this_node::getName() + "/file_path", file_location);

    csvFile.open(file_location.c_str());
    if (!csvFile){
      ROS_ERROR("Unable to open goal file");
      throw std::invalid_argument("Invalid file name");
    }
    
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_goal_x_position", robot_goal_x_position);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_goal_y_position", robot_goal_y_position);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_goal_z_rotation", robot_goal_z_rotation);
    
    // Open  file for goal
    std::string csvLine;
    std::getline(csvFile, csvLine);

    while (std::getline(csvFile, csvLine)){
      if (!csvLine.empty()){
        std::vector<std::string> data;
        boost::algorithm::split(data, csvLine, boost::is_any_of(","));

        //parse the seperated strings into the goal msg
        obstacle_bot_navigation::Goal goal;
        goal.description = data[0];

        if (obstacle_bot_goal_x_position == 0.0 && robot_goal_y_position == 0.0 && robot_goal_z_rotation == 0.0){
          goal.goal.x = std::stod(data[1].c_str());
          goal.goal.y = std::stod(data[2].c_str());
          goal.goal.theta = std::stod(data[3].c_str());
        }
        else{
          goal.goal.x = obstacle_bot_goal_x_position;
          goal.goal.y = obstacle_bot_goal_y_position;
          goal.goal.theta = obstacle_bot_goal_z_rotation;
        }


        ROS_INFO("Goal: %s registered at x:%f, y:%f and yaw:%f", goal.description.c_str(), goal.goal.x, goal.goal.y, goal.goal.theta);
        obstacle_bot_goal_array.push_back(goal);
      }
    }

    //After parsing all of the goals, set the total number of goals inside all of the goal msgs
    for(int i = 0; i < obstacle_bot_goal_array.size(); i++){
      obstacle_bot_goal_array[i].total_goals = goalArray.size();
    }

    obstacle_bot_goal_publisher = node_handle.advertise<robot_navigation::Goal>("goal", 1, true);
    counter = 1;
  }

  //Publishes the next goal in the goal array. The goals wrap around to the beginning of the array after the last goal is published
  void publishNextGoal(){
    int currentGoalIndex = counter % obstacle_bot_goal_array.size();
    obstacle_bot_goal_publisher.publish(robot_goal_array[currentGoalIndex]);
    ROS_INFO("Published goal: %s", obstacle_bot_goal_array[currentGoalIndex].description.c_str());
    counter++;
  }

  //Publishes the first goal in the goal array
  void publishInitialGoal(){
    obstacle_bot_goal_publisher.publish(robot_goal_array[0]);
    ROS_INFO("Published initial goal: %s", obstacle_bot_goal_array[0].description.c_str());
  }

  //Resets the counter back to 1
  void resetGoals(){
    counter = 1;
    ROS_INFO("Goal publisher order reset to beginning");
  }
};


//Service Callbacks
bool newGoalCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res, goal_handler_obj){
  goal_handler_obj.publishNextGoal();
  return true;
}

bool initialGoalCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res){
  goal_handler_obj.publishInitialGoal();
  return true;
}

bool resetGoalsCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res){
  goal_handler_obj.resetGoals();
  return true;
}


int main(int argc, char **argv){

  //Create ros node
  ros::init(argc, argv, "obstacle_bot_goal_publisher");
  obstacle_bot_goal_publisher goal_handler_obj;

  //Create the service callbacks
  ros::ServiceServer obstacle_bot_goal_server = goal_handler_obj.node_handle.advertiseService("get_robot_new_goal", newGoalCallback(goal_manager_obj));
  ros::ServiceServer initial_obstacle_bot_goal_server = goal_handler_obj.node_handle.advertiseService("get_robot_initial_goal", initialGoalCallback(goal_manager_obj));
  ros::ServiceServer reset_obstacle_bot_goal_server = goal_handler_obj.node_handle.advertiseService("reset_robot_goals", resetGoalsCallback(goal_manager_obj));
  ros::spin();

  return 0;
}
