// Generated by gencpp from file tuw_airskin_msgs/AirskinColors.msg
// DO NOT EDIT!


#ifndef TUW_AIRSKIN_MSGS_MESSAGE_AIRSKINCOLORS_H
#define TUW_AIRSKIN_MSGS_MESSAGE_AIRSKINCOLORS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/ColorRGBA.h>

namespace tuw_airskin_msgs
{
template <class ContainerAllocator>
struct AirskinColors_
{
  typedef AirskinColors_<ContainerAllocator> Type;

  AirskinColors_()
    : header()
    , idx()
    , colors()  {
    }
  AirskinColors_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , idx(_alloc)
    , colors(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<uint16_t, typename ContainerAllocator::template rebind<uint16_t>::other >  _idx_type;
  _idx_type idx;

   typedef std::vector< ::std_msgs::ColorRGBA_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::std_msgs::ColorRGBA_<ContainerAllocator> >::other >  _colors_type;
  _colors_type colors;





  typedef boost::shared_ptr< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> const> ConstPtr;

}; // struct AirskinColors_

typedef ::tuw_airskin_msgs::AirskinColors_<std::allocator<void> > AirskinColors;

typedef boost::shared_ptr< ::tuw_airskin_msgs::AirskinColors > AirskinColorsPtr;
typedef boost::shared_ptr< ::tuw_airskin_msgs::AirskinColors const> AirskinColorsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator1> & lhs, const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.idx == rhs.idx &&
    lhs.colors == rhs.colors;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator1> & lhs, const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace tuw_airskin_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >
{
  static const char* value()
  {
    return "89c9873192919e34622afd164f6a8ba5";
  }

  static const char* value(const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x89c9873192919e34ULL;
  static const uint64_t static_value2 = 0x622afd164f6a8ba5ULL;
};

template<class ContainerAllocator>
struct DataType< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >
{
  static const char* value()
  {
    return "tuw_airskin_msgs/AirskinColors";
  }

  static const char* value(const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This expresses a set of AirSkin pad colors\n"
"Header header                  # timestamp in the header is the acquisition time and frame\n"
"\n"
"uint16[] idx                   # index of the color in the colors array \n"
"                               # if empty the colors array must match the target system\n"
"std_msgs/ColorRGBA[] colors    # RGBA color values for corresponding AirSkin pads\n"
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
"\n"
"================================================================================\n"
"MSG: std_msgs/ColorRGBA\n"
"float32 r\n"
"float32 g\n"
"float32 b\n"
"float32 a\n"
;
  }

  static const char* value(const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.idx);
      stream.next(m.colors);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AirskinColors_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::tuw_airskin_msgs::AirskinColors_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "idx[]" << std::endl;
    for (size_t i = 0; i < v.idx.size(); ++i)
    {
      s << indent << "  idx[" << i << "]: ";
      Printer<uint16_t>::stream(s, indent + "  ", v.idx[i]);
    }
    s << indent << "colors[]" << std::endl;
    for (size_t i = 0; i < v.colors.size(); ++i)
    {
      s << indent << "  colors[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::std_msgs::ColorRGBA_<ContainerAllocator> >::stream(s, indent + "    ", v.colors[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // TUW_AIRSKIN_MSGS_MESSAGE_AIRSKINCOLORS_H
