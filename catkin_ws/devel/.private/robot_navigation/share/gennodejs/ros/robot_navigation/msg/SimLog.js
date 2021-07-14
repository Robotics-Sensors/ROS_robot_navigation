// Auto-generated. Do not edit!

// (in-package robot_navigation.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class SimLog {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.robot_pos = null;
      this.goal = null;
      this.dist_from_goal = null;
      this.collision = null;
      this.iteration = null;
      this.event = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('robot_pos')) {
        this.robot_pos = initObj.robot_pos
      }
      else {
        this.robot_pos = new geometry_msgs.msg.Pose2D();
      }
      if (initObj.hasOwnProperty('goal')) {
        this.goal = initObj.goal
      }
      else {
        this.goal = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('dist_from_goal')) {
        this.dist_from_goal = initObj.dist_from_goal
      }
      else {
        this.dist_from_goal = 0.0;
      }
      if (initObj.hasOwnProperty('collision')) {
        this.collision = initObj.collision
      }
      else {
        this.collision = new geometry_msgs.msg.Point();
      }
      if (initObj.hasOwnProperty('iteration')) {
        this.iteration = initObj.iteration
      }
      else {
        this.iteration = 0;
      }
      if (initObj.hasOwnProperty('event')) {
        this.event = initObj.event
      }
      else {
        this.event = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SimLog
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [robot_pos]
    bufferOffset = geometry_msgs.msg.Pose2D.serialize(obj.robot_pos, buffer, bufferOffset);
    // Serialize message field [goal]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.goal, buffer, bufferOffset);
    // Serialize message field [dist_from_goal]
    bufferOffset = _serializer.float64(obj.dist_from_goal, buffer, bufferOffset);
    // Serialize message field [collision]
    bufferOffset = geometry_msgs.msg.Point.serialize(obj.collision, buffer, bufferOffset);
    // Serialize message field [iteration]
    bufferOffset = _serializer.uint8(obj.iteration, buffer, bufferOffset);
    // Serialize message field [event]
    bufferOffset = _serializer.string(obj.event, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SimLog
    let len;
    let data = new SimLog(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [robot_pos]
    data.robot_pos = geometry_msgs.msg.Pose2D.deserialize(buffer, bufferOffset);
    // Deserialize message field [goal]
    data.goal = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [dist_from_goal]
    data.dist_from_goal = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [collision]
    data.collision = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset);
    // Deserialize message field [iteration]
    data.iteration = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [event]
    data.event = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += object.event.length;
    return length + 85;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robot_navigation/SimLog';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cc387dc22a2d950d15b2be5ad31d16db';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    geometry_msgs/Pose2D robot_pos
    geometry_msgs/Point goal
    float64 dist_from_goal
    geometry_msgs/Point collision
    uint8 iteration
    string event
    
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Pose2D
    # Deprecated
    # Please use the full 3D pose.
    
    # In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.
    
    # If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.
    
    
    # This expresses a position and orientation on a 2D manifold.
    
    float64 x
    float64 y
    float64 theta
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SimLog(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.robot_pos !== undefined) {
      resolved.robot_pos = geometry_msgs.msg.Pose2D.Resolve(msg.robot_pos)
    }
    else {
      resolved.robot_pos = new geometry_msgs.msg.Pose2D()
    }

    if (msg.goal !== undefined) {
      resolved.goal = geometry_msgs.msg.Point.Resolve(msg.goal)
    }
    else {
      resolved.goal = new geometry_msgs.msg.Point()
    }

    if (msg.dist_from_goal !== undefined) {
      resolved.dist_from_goal = msg.dist_from_goal;
    }
    else {
      resolved.dist_from_goal = 0.0
    }

    if (msg.collision !== undefined) {
      resolved.collision = geometry_msgs.msg.Point.Resolve(msg.collision)
    }
    else {
      resolved.collision = new geometry_msgs.msg.Point()
    }

    if (msg.iteration !== undefined) {
      resolved.iteration = msg.iteration;
    }
    else {
      resolved.iteration = 0
    }

    if (msg.event !== undefined) {
      resolved.event = msg.event;
    }
    else {
      resolved.event = ''
    }

    return resolved;
    }
};

module.exports = SimLog;
