/*  
    The mover node manages the navigation status of a robot2.  First, if the robot2 needs to navigate towards a goal, the mover node
    gets the current navigation goal from goal_pub and commands the move_base to move toward that goal.  Once the robot2 reaches a goal,
    the mover node will call the goal_pub service to get a new goal if another iteration is desired.  Next, the mover node keeps track
    of the the number of iterations the robot2 has completed and limits the robot2 to a specified number of iterations.  Finally, if desired,
    the costmaps on the robot2 are cleared in between each iteration.
*/

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_srvs/Empty.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <robot_navigation/Goal.h>
#include <tf2/LinearMath/Quaternion.h>

/* typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient; */

class robot2_mover {
private:

    typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
    ros::NodeHandle node_handle;
    ros::Subscriber robot2_subscriber;

    MoveBaseClient *ac;
    ros::ServiceClient costmap_service;
    ros::ServiceClient goal_service;
    ros::ServiceClient initial_goal_service;
    ros::ServiceClient reset_goals_service;
    ros::Publisher testStatusPub;

    int goals_reached = 0;
    int iterations = 0;
    bool clear_costmaps = false;
    bool initial_setup = false;
    std_msgs::Bool boolean;


  public:
  robot2_mover() {
    robot2_subscriber = node_handle.subscribe("goal",1, &robot2_mover::move_robot2_callback, this);
    // Publisher to show test being preformed or not
    testStatusPub = node_handle.advertise<std_msgs::Bool>("/test_status", 1000, true);

    //Set up move base client and services
    ac = new MoveBaseClient("move_base", true);
    costmap_service = node_handle.serviceClient<std_srvs::Empty>("move_base/clear_costmaps");
    goal_service = node_handle.serviceClient<std_srvs::Empty>("get_new_goal");
    initial_goal_service = node_handle.serviceClient<std_srvs::Empty>("get_initial_goal");
    reset_goals_service = node_handle.serviceClient<std_srvs::Empty>("reset_goals");

    node_handle.getParam(ros::this_node::getName() + "/iterations", iterations);
    node_handle.getParam(ros::this_node::getName() + "/clear_costmaps", clear_costmaps);

    boolean.data = false;
    testStatusPub.publish(boolean);

    //wait for the action server to come up
    while (!ac->waitForServer(ros::Duration(10.0)))
    {
        ROS_INFO("Waiting for the robot2 move_base action server to come up");
    }

    //wait for services
    costmap_service.waitForExistence();
    goal_service.waitForExistence();
    initial_goal_service.waitForExistence();
    reset_goals_service.waitForExistence();

    std_srvs::Empty service_msg;

    //clear the initial costmaps
    if (!costmap_service.call(service_msg))
    {
        ROS_WARN("Failed to clear costmaps");
    }

    //Call the reset goal service to ensure that the first test goal is the correct goal
    if (!reset_goals_service.call(service_msg))
    {
        ROS_ERROR("Failed to reset goals");
    }

    //Call the initial goal service to move the robot2s to their initial positions
    ROS_INFO("Navigating to initial test position");
    if (!initial_goal_service.call(service_msg))
    {
        ROS_ERROR("Failed to request initial goal");
    }

}

  void move_robot2_callback(robot_navigation::Goal goal_msg) {
    move_base_msgs::MoveBaseGoal goal;
    //save # of total goals for checking if all the goals have been navigated to in a given iteration
    unsigned int total_goals_in_iteration = goal_msg.total_goals;

    //translate Goal Message to a MoveBaseGoal
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose.position.x = goal_msg.goal.x;
    goal.target_pose.pose.position.y = goal_msg.goal.y;
    tf2::Quaternion angle;
    angle.setRPY(0, 0, goal_msg.goal.theta);
    goal.target_pose.pose.orientation.z = angle.getZ();
    goal.target_pose.pose.orientation.w = angle.getW();

    //Send the goal to the navigation action client
    ac->sendGoal(goal);
    ROS_INFO("Starting navigation toward goal: %s", goal_msg.description.c_str());

    //Wait 1 second before checking nav status so for cases that instantly finish navigating, the code still holds for at least 1 sec
    ros::Duration(1).sleep();

    //Wait for the robot2 to finish moving
    ac->waitForResult();

    //Wait a little bit before requesting the next goal
    ros::Duration(2).sleep();

    std_srvs::Empty service_msg;

    if(initial_setup)
    {
        //robot2 is performing the navigation test

        //Clear costmaps every iteration if clear_costmaps is true
        if(clear_costmaps)
        {
            if (!costmap_service.call(service_msg))
            {
                ROS_WARN("Failed to clear costmaps");
            }
        }

        //Increase goals_reached counter
        goals_reached++;

        //Requests another goal if the number of trips has not been met, otherwise shut down the node
        if (goals_reached / total_goals_in_iteration < iterations)
        {
            //Get the next goal
            if (!goal_service.call(service_msg))
            {
                ROS_ERROR("Failed to request for a goal");
            }
        }
        else
        {
            //All iterations finished, publish false to test_status
            std_msgs::Bool boolean;
            boolean.data = false;
            testStatusPub.publish(boolean);

            //Node no longer needed
            ros::shutdown();
            return;
        }
    }
    else
    {
        //The robot2 has finished navigating to its initial position.  Either the robot2 sucessfully made it to its
        //initial position and the test will start or it failed and the robot2 will attempt to get to its initial
        //position again

        //First reset the costmap before the test starts
        if (!costmap_service.call(service_msg))
        {
            ROS_WARN("Failed to clear costmaps");
        }

        //Determine if the robot2 made it to its initial position
        if(ac->getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        {
            //Succeded at getting to its initial position, set initial_setup to true and get first test goal

            ROS_INFO("robot2 sucessfully reached its initial position, now starting test");
            initial_setup = true;

            //Publish true to test_status
            std_msgs::Bool boolean;
            boolean.data = true;
            testStatusPub.publish(boolean);

            //Get first goal
            if (!goal_service.call(service_msg))
            {
                ROS_ERROR("Failed to request for a goal");
            }
        }
        else
        {
            //Failed at getting to its initial position, request the initial goal again

            ROS_INFO("robot2 failed to reach its initial position, attempting again");

            //Get initial goal
            if (!initial_goal_service.call(service_msg))
            {
                ROS_ERROR("Failed to request for initial goal");
            }
        }
    }

  }

};


int main(int argc, char **argv) {

  ros::init(argc, argv, "robot2_mover_publisher");
  robot2_mover robot_mover_obj;

  ros::spin();
  ros::shutdown();


  return 0;
}
