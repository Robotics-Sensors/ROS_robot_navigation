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


class GoalHandlerNode  {
public:
    enum Mode {
        READ = 0,
        WRITE = 1
    };
    
    GoalHandlerNode ( ros::NodeHandle & n, Mode mode );
    void callback ( const tuw_multi_robot_msgs::RobotGoalsArray& msg );
    void publish ();
private:
    ros::NodeHandle n_;
    ros::NodeHandle n_param_;
    ros::Subscriber sub_goals_;
    double      loop_rate_;                 
    bool        time_now_;                  
    bool        run_once_;                  
    std::string file_name_;                 
    ros::Publisher pub_goals_;
    tuw_multi_robot_msgs::RobotGoalsArray msg_;
    int counter_;

    void publishGoal ( );

};

GoalHandlerNode::GoalHandlerNode (ros::NodeHandle & n, Mode mode)
    : n_ ( n ),  n_param_ ( "~" ), counter_(0) {
    n_param_.param<std::string> ( "file_path", file_name_);
    
    n_param_.param<bool> ( "run_once", run_once_, "false" );
    if (mode == READ) {
        n_param_.param<double> ( "loop_rate", loop_rate_, 1.0 );
        n_param_.param<bool> ( "time_now", time_now_, "true" );
        pub_goals_ = n.advertise<tuw_multi_robot_msgs::RobotGoalsArray> ( "goal", 1, true);
    }
}


void GoalHandlerNode::callback (const tuw_multi_robot_msgs::RobotGoalsArray& msg) {
    ROS_INFO ( "GoalHandlerNode::callback" );
    msg_ = msg;

    std::string frame_id_;                 // parameter
    std::ofstream file;
    char file_name[0x1FF];
    if(run_once_){
        sprintf(file_name, "%s", file_name_.c_str());
    } else {
        sprintf(file_name, "%s%03i.txt", file_name_.c_str(), counter_);
    }
    file.open ( file_name );
    ROS_INFO ( "Write file %s", file_name );
    for ( size_t i = 0; i < msg_.robots.size(); i++ ) {
        const tuw_multi_robot_msgs::RobotGoals &robot = msg_.robots[i];
        file << robot.robot_name << std::endl;
        for ( size_t j = 0; j < robot.destinations.size(); j++ ) {
            const geometry_msgs::Pose p = robot.destinations[j];
        }
    }
    file.close();
    counter_++;
    if(run_once_) ros::shutdown();
}
void GoalHandlerNode::publish () {
    ros::Rate loop_rate(loop_rate_);
    do {
        publishGoal();
        ros::spinOnce();
        loop_rate.sleep();
    } while ( ros::ok() && (run_once_ == false));
}

void GoalHandlerNode::publishGoal (  ) {
    char file_name[0x1FF];
    if(run_once_){
        sprintf(file_name, "%s", file_name_.c_str());
    } else {
        sprintf(file_name, "%s%03i.txt", file_name_.c_str(), counter_);
    }
    
    std::ifstream file ( file_name );
    if ( !file.good() ) {
        run_once_ = true;
        return;
    }
    if ( !file.is_open() ) {
        return;
    }

    std::vector<std::string> columns;
    std::string line;

    // Goals
    tuw_multi_robot_msgs::RobotGoals::_destinations_type *destinations = NULL;
    msg_.robots.clear();
    while ( getline ( file,line ) ) {
        boost::erase_all ( line, " " );
        boost::split ( columns, line, boost::is_any_of ( "," ) );
        // Robot name
        if ( columns.size() == 1 ) {
            if ( columns[0].size() > 0 ) {
                tuw_multi_robot_msgs::RobotGoals robot;
                robot.robot_name = line;
                msg_.robots.push_back ( robot );
                destinations = &msg_.robots.back().destinations;
            } else {
                ROS_ERROR ( "robot name to short!" );
                return;
            }
        }

        if ( ( columns.size() == 4 ) && ( destinations != NULL ) ) {
            geometry_msgs::Pose p;
            p.position.x = std::stod ( columns[0] );
            p.position.y = std::stod ( columns[1] );
            p.position.z = std::stod ( columns[2] );
            double alpha  = std::stod ( columns[3] );
            tuw::EulerYawToQuaternion ( alpha, p.orientation );
            destinations->push_back ( p );
        }
    }
    if(time_now_){
        msg_.header.stamp = ros::Time::now();
    }
    
    ros::Time timeout = ros::Time::now() + ros::Duration(10);
    int nr_of_subscribers = pub_goals_.getNumSubscribers();
    while (ros::Time::now() < timeout && (nr_of_subscribers <= 0)){
        ROS_INFO ( "NumSubscribers: %i", nr_of_subscribers );
        ros::Duration(0.1).sleep();
        nr_of_subscribers = pub_goals_.getNumSubscribers();
    }
    ROS_INFO ( "NumSubscribers: %i", nr_of_subscribers );
    pub_goals_.publish ( msg_ );
        
    file.close();
    counter_++;
}


int main ( int argc, char **argv ) {
    ros::init ( argc, argv, "GoalServer" );
    ros::NodeHandle n;
    GoalHandlerNode node ( n, GoalHandlerNode::READ);
    node.publish();
    return 0;
}
