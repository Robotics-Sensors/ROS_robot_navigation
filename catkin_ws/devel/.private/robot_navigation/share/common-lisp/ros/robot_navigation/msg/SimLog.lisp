; Auto-generated. Do not edit!


(cl:in-package robot_navigation-msg)


;//! \htmlinclude SimLog.msg.html

(cl:defclass <SimLog> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (robot_pos
    :reader robot_pos
    :initarg :robot_pos
    :type geometry_msgs-msg:Pose2D
    :initform (cl:make-instance 'geometry_msgs-msg:Pose2D))
   (goal
    :reader goal
    :initarg :goal
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (dist_from_goal
    :reader dist_from_goal
    :initarg :dist_from_goal
    :type cl:float
    :initform 0.0)
   (collision
    :reader collision
    :initarg :collision
    :type geometry_msgs-msg:Point
    :initform (cl:make-instance 'geometry_msgs-msg:Point))
   (iteration
    :reader iteration
    :initarg :iteration
    :type cl:fixnum
    :initform 0)
   (event
    :reader event
    :initarg :event
    :type cl:string
    :initform ""))
)

(cl:defclass SimLog (<SimLog>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SimLog>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SimLog)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_navigation-msg:<SimLog> is deprecated: use robot_navigation-msg:SimLog instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SimLog>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:header-val is deprecated.  Use robot_navigation-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'robot_pos-val :lambda-list '(m))
(cl:defmethod robot_pos-val ((m <SimLog>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:robot_pos-val is deprecated.  Use robot_navigation-msg:robot_pos instead.")
  (robot_pos m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <SimLog>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:goal-val is deprecated.  Use robot_navigation-msg:goal instead.")
  (goal m))

(cl:ensure-generic-function 'dist_from_goal-val :lambda-list '(m))
(cl:defmethod dist_from_goal-val ((m <SimLog>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:dist_from_goal-val is deprecated.  Use robot_navigation-msg:dist_from_goal instead.")
  (dist_from_goal m))

(cl:ensure-generic-function 'collision-val :lambda-list '(m))
(cl:defmethod collision-val ((m <SimLog>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:collision-val is deprecated.  Use robot_navigation-msg:collision instead.")
  (collision m))

(cl:ensure-generic-function 'iteration-val :lambda-list '(m))
(cl:defmethod iteration-val ((m <SimLog>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:iteration-val is deprecated.  Use robot_navigation-msg:iteration instead.")
  (iteration m))

(cl:ensure-generic-function 'event-val :lambda-list '(m))
(cl:defmethod event-val ((m <SimLog>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:event-val is deprecated.  Use robot_navigation-msg:event instead.")
  (event m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SimLog>) ostream)
  "Serializes a message object of type '<SimLog>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'robot_pos) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'dist_from_goal))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'collision) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'iteration)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'event))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'event))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SimLog>) istream)
  "Deserializes a message object of type '<SimLog>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'robot_pos) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'dist_from_goal) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'collision) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'iteration)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'event) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'event) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SimLog>)))
  "Returns string type for a message object of type '<SimLog>"
  "robot_navigation/SimLog")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SimLog)))
  "Returns string type for a message object of type 'SimLog"
  "robot_navigation/SimLog")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SimLog>)))
  "Returns md5sum for a message object of type '<SimLog>"
  "cc387dc22a2d950d15b2be5ad31d16db")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SimLog)))
  "Returns md5sum for a message object of type 'SimLog"
  "cc387dc22a2d950d15b2be5ad31d16db")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SimLog>)))
  "Returns full string definition for message of type '<SimLog>"
  (cl:format cl:nil "Header header~%geometry_msgs/Pose2D robot_pos~%geometry_msgs/Point goal~%float64 dist_from_goal~%geometry_msgs/Point collision~%uint8 iteration~%string event~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SimLog)))
  "Returns full string definition for message of type 'SimLog"
  (cl:format cl:nil "Header header~%geometry_msgs/Pose2D robot_pos~%geometry_msgs/Point goal~%float64 dist_from_goal~%geometry_msgs/Point collision~%uint8 iteration~%string event~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SimLog>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'robot_pos))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'collision))
     1
     4 (cl:length (cl:slot-value msg 'event))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SimLog>))
  "Converts a ROS message object to a list"
  (cl:list 'SimLog
    (cl:cons ':header (header msg))
    (cl:cons ':robot_pos (robot_pos msg))
    (cl:cons ':goal (goal msg))
    (cl:cons ':dist_from_goal (dist_from_goal msg))
    (cl:cons ':collision (collision msg))
    (cl:cons ':iteration (iteration msg))
    (cl:cons ':event (event msg))
))
