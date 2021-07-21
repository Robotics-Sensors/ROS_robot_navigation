// Generated by gencpp from file robot_navigation/Goal.msg
// DO NOT EDIT!


#ifndef ROBOT_NAVIGATION_MESSAGE_GOAL_H
#define ROBOT_NAVIGATION_MESSAGE_GOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Pose2D.h>

namespace robot_navigation
{
template <class ContainerAllocator>
struct Goal_
{
  typedef Goal_<ContainerAllocator> Type;

  Goal_()
    : goal()
    , description()
    , total_goals(0)  {
    }
  Goal_(const ContainerAllocator& _alloc)
    : goal(_alloc)
    , description(_alloc)
    , total_goals(0)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Pose2D_<ContainerAllocator>  _goal_type;
  _goal_type goal;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _description_type;
  _description_type description;

   typedef uint16_t _total_goals_type;
  _total_goals_type total_goals;





  typedef boost::shared_ptr< ::robot_navigation::Goal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_navigation::Goal_<ContainerAllocator> const> ConstPtr;

}; // struct Goal_

typedef ::robot_navigation::Goal_<std::allocator<void> > Goal;

typedef boost::shared_ptr< ::robot_navigation::Goal > GoalPtr;
typedef boost::shared_ptr< ::robot_navigation::Goal const> GoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_navigation::Goal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_navigation::Goal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::robot_navigation::Goal_<ContainerAllocator1> & lhs, const ::robot_navigation::Goal_<ContainerAllocator2> & rhs)
{
  return lhs.goal == rhs.goal &&
    lhs.description == rhs.description &&
    lhs.total_goals == rhs.total_goals;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::robot_navigation::Goal_<ContainerAllocator1> & lhs, const ::robot_navigation::Goal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace robot_navigation

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::robot_navigation::Goal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_navigation::Goal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_navigation::Goal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_navigation::Goal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_navigation::Goal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_navigation::Goal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_navigation::Goal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c07a3dfa52044e15fc6e0a0dae2b5434";
  }

  static const char* value(const ::robot_navigation::Goal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc07a3dfa52044e15ULL;
  static const uint64_t static_value2 = 0xfc6e0a0dae2b5434ULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_navigation::Goal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_navigation/Goal";
  }

  static const char* value(const ::robot_navigation::Goal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_navigation::Goal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Pose2D goal\n"
"string description\n"
"uint16 total_goals\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose2D\n"
"# Deprecated\n"
"# Please use the full 3D pose.\n"
"\n"
"# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.\n"
"\n"
"# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.\n"
"\n"
"\n"
"# This expresses a position and orientation on a 2D manifold.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 theta\n"
;
  }

  static const char* value(const ::robot_navigation::Goal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_navigation::Goal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.goal);
      stream.next(m.description);
      stream.next(m.total_goals);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Goal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_navigation::Goal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_navigation::Goal_<ContainerAllocator>& v)
  {
    s << indent << "goal: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose2D_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
    s << indent << "description: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.description);
    s << indent << "total_goals: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.total_goals);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_NAVIGATION_MESSAGE_GOAL_H
