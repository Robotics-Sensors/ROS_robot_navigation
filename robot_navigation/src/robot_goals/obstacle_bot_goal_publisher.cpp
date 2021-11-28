/*  
    The obstacle_bot goal publisher node publishes the current navigation goal to the goal topic for the obstacle_bot.  In a navigation test, a set of navigation goals are specified in a csv file and the
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
  std::vector<robot_navigation::Goal> obstacle_bot_goal_array;
  std::ifstream csvFile;
  ros::Publisher obstacle_bot_goal_pub;
  int counter;
  std::string file_location;
  std::string csvLine;

  float obstacle_bot_goal_x_position = 0.0;
  float obstacle_bot_goal_y_position = 0.0;
  float obstacle_bot_goal_z_rotation = 0.0;
  
  //Determine if you want to determinde the input or no of goal
  std::string user_choose;

public:
  obstacle_bot_goal_publisher(ros::NodeHandle node_handle) {

    //Get file location
    node_handle.getParam(ros::this_node::getName() + "/file_path", file_location);

    // Open the csv file 
    csvFile.open(file_location.c_str());
    if (!csvFile){
      ROS_ERROR("Unable to open goal file for obstacle bot");
      throw std::invalid_argument("Invalid file name");
    }
    
    node_handle.getParam(ros::this_node::getName()+"/user_choose", user_choose);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_goal_x_position", obstacle_bot_goal_x_position);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_goal_y_position", obstacle_bot_goal_y_position);
    node_handle.getParam(ros::this_node::getName()+"/obstacle_bot_goal_z_rotation", obstacle_bot_goal_z_rotation);
    
    // Open  file for goal
    std::getline(csvFile, csvLine);

    // While loop for getting the goal position from the 
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
      obstacle_bot_goal_array[i].total_goals = obstacle_bot_goal_array.size();
    }

    obstacle_bot_goal_pub = node_handle.advertise<robot_navigation::Goal>("goal", 1, true);
    counter = 1;
  }
  
  friend bool newGoalCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res);
  friend bool initialGoalCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res);
  friend bool resetGoalsCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res);

  //Publishes the next goal in the goal array. The goals wrap around to the beginning of the array after the last goal is published
  void publishNextGoal(){
    int currentGoalIndex = counter % obstacle_bot_goal_array.size();
    obstacle_bot_goal_pub.publish(obstacle_bot_goal_array[currentGoalIndex]);
    ROS_INFO("Published goal: %s", obstacle_bot_goal_array[currentGoalIndex].description.c_str());
    counter++;
  }

  //Publishes the first goal in the goal array
  void publishInitialGoal(){
    obstacle_bot_goal_pub.publish(obstacle_bot_goal_array[0]);
    ROS_INFO("Published initial goal: %s", obstacle_bot_goal_array[0].description.c_str());
  }

  //Resets the counter back to 1
  void resetGoals(){
    counter = 1;
    ROS_INFO("Goal publisher order reset to beginning");
  }

};


//Service Callbacks
bool newGoalCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res){
  obstacle_bot_goal_publisher *object;
  object->publishNextGoal();
  return true;
}

bool initialGoalCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res){
  obstacle_bot_goal_publisher *object;
  object->publishInitialGoal();
  return true;
}

bool resetGoalsCallback(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res){
  obstacle_bot_goal_publisher *object;
  object->resetGoals();
  return true;
}


int main(int argc, char **argv){

  //Create ros node
  ros::init(argc, argv, "obstacle_bot_goal_publisher");
  ros::NodeHandle node_handle;

  obstacle_bot_goal_publisher goal_handler_obj(node_handle);

  //Create the service callbacks
  ros::ServiceServer obstacle_bot_goal_server = node_handle.advertiseService("get_obstacle_bot_new_goal", newGoalCallback);
  ros::ServiceServer initial_obstacle_bot_goal_server = node_handle.advertiseService("get_obstacle_bot_initial_goal", initialGoalCallback);
  ros::ServiceServer reset_obstacle_bot_goal_server = node_handle.advertiseService("reset_obstacle_bot_goals", resetGoalsCallback);
  ros::spin();

  return 0;
}
