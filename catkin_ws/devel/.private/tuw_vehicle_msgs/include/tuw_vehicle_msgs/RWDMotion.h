// Generated by gencpp from file tuw_vehicle_msgs/RWDMotion.msg
// DO NOT EDIT!


#ifndef TUW_VEHICLE_MSGS_MESSAGE_RWDMOTION_H
#define TUW_VEHICLE_MSGS_MESSAGE_RWDMOTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace tuw_vehicle_msgs
{
template <class ContainerAllocator>
struct RWDMotion_
{
  typedef RWDMotion_<ContainerAllocator> Type;

  RWDMotion_()
    : header()
    , x_vel(0.0)
    , y_vel(0.0)
    , yaw_rate(0.0)
    , roll_rate(0.0)  {
    }
  RWDMotion_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , x_vel(0.0)
    , y_vel(0.0)
    , yaw_rate(0.0)
    , roll_rate(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _x_vel_type;
  _x_vel_type x_vel;

   typedef double _y_vel_type;
  _y_vel_type y_vel;

   typedef double _yaw_rate_type;
  _yaw_rate_type yaw_rate;

   typedef double _roll_rate_type;
  _roll_rate_type roll_rate;





  typedef boost::shared_ptr< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> const> ConstPtr;

}; // struct RWDMotion_

typedef ::tuw_vehicle_msgs::RWDMotion_<std::allocator<void> > RWDMotion;

typedef boost::shared_ptr< ::tuw_vehicle_msgs::RWDMotion > RWDMotionPtr;
typedef boost::shared_ptr< ::tuw_vehicle_msgs::RWDMotion const> RWDMotionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator1> & lhs, const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.x_vel == rhs.x_vel &&
    lhs.y_vel == rhs.y_vel &&
    lhs.yaw_rate == rhs.yaw_rate &&
    lhs.roll_rate == rhs.roll_rate;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator1> & lhs, const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace tuw_vehicle_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8c19313c75b199649c626db68589a3e7";
  }

  static const char* value(const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8c19313c75b19964ULL;
  static const uint64_t static_value2 = 0x9c626db68589a3e7ULL;
};

template<class ContainerAllocator>
struct DataType< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "tuw_vehicle_msgs/RWDMotion";
  }

  static const char* value(const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"# velocity in x-direction in m/s\n"
"float64 x_vel\n"
"# velocity in y-direction in m/s\n"
"float64 y_vel\n"
"# yaw rate in deg/s\n"
"float64 yaw_rate\n"
"# roll rate in deg/s\n"
"float64 roll_rate\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.x_vel);
      stream.next(m.y_vel);
      stream.next(m.yaw_rate);
      stream.next(m.roll_rate);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RWDMotion_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::tuw_vehicle_msgs::RWDMotion_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "x_vel: ";
    Printer<double>::stream(s, indent + "  ", v.x_vel);
    s << indent << "y_vel: ";
    Printer<double>::stream(s, indent + "  ", v.y_vel);
    s << indent << "yaw_rate: ";
    Printer<double>::stream(s, indent + "  ", v.yaw_rate);
    s << indent << "roll_rate: ";
    Printer<double>::stream(s, indent + "  ", v.roll_rate);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TUW_VEHICLE_MSGS_MESSAGE_RWDMOTION_H
