; Auto-generated. Do not edit!


(cl:in-package robot_navigation-msg)


;//! \htmlinclude Goal.msg.html

(cl:defclass <Goal> (roslisp-msg-protocol:ros-message)
  ((goal
    :reader goal
    :initarg :goal
    :type geometry_msgs-msg:Pose2D
    :initform (cl:make-instance 'geometry_msgs-msg:Pose2D))
   (description
    :reader description
    :initarg :description
    :type cl:string
    :initform "")
   (total_goals
    :reader total_goals
    :initarg :total_goals
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Goal (<Goal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Goal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Goal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_navigation-msg:<Goal> is deprecated: use robot_navigation-msg:Goal instead.")))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:goal-val is deprecated.  Use robot_navigation-msg:goal instead.")
  (goal m))

(cl:ensure-generic-function 'description-val :lambda-list '(m))
(cl:defmethod description-val ((m <Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:description-val is deprecated.  Use robot_navigation-msg:description instead.")
  (description m))

(cl:ensure-generic-function 'total_goals-val :lambda-list '(m))
(cl:defmethod total_goals-val ((m <Goal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_navigation-msg:total_goals-val is deprecated.  Use robot_navigation-msg:total_goals instead.")
  (total_goals m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Goal>) ostream)
  "Serializes a message object of type '<Goal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'description))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'description))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'total_goals)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'total_goals)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Goal>) istream)
  "Deserializes a message object of type '<Goal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'description) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'description) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'total_goals)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'total_goals)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Goal>)))
  "Returns string type for a message object of type '<Goal>"
  "robot_navigation/Goal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Goal)))
  "Returns string type for a message object of type 'Goal"
  "robot_navigation/Goal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Goal>)))
  "Returns md5sum for a message object of type '<Goal>"
  "c07a3dfa52044e15fc6e0a0dae2b5434")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Goal)))
  "Returns md5sum for a message object of type 'Goal"
  "c07a3dfa52044e15fc6e0a0dae2b5434")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Goal>)))
  "Returns full string definition for message of type '<Goal>"
  (cl:format cl:nil "geometry_msgs/Pose2D goal~%string description~%uint16 total_goals~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Goal)))
  "Returns full string definition for message of type 'Goal"
  (cl:format cl:nil "geometry_msgs/Pose2D goal~%string description~%uint16 total_goals~%================================================================================~%MSG: geometry_msgs/Pose2D~%# Deprecated~%# Please use the full 3D pose.~%~%# In general our recommendation is to use a full 3D representation of everything and for 2D specific applications make the appropriate projections into the plane for their calculations but optimally will preserve the 3D information during processing.~%~%# If we have parallel copies of 2D datatypes every UI and other pipeline will end up needing to have dual interfaces to plot everything. And you will end up with not being able to use 3D tools for 2D use cases even if they're completely valid, as you'd have to reimplement it with different inputs and outputs. It's not particularly hard to plot the 2D pose or compute the yaw error for the Pose message and there are already tools and libraries that can do this for you.~%~%~%# This expresses a position and orientation on a 2D manifold.~%~%float64 x~%float64 y~%float64 theta~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Goal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
     4 (cl:length (cl:slot-value msg 'description))
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Goal>))
  "Converts a ROS message object to a list"
  (cl:list 'Goal
    (cl:cons ':goal (goal msg))
    (cl:cons ':description (description msg))
    (cl:cons ':total_goals (total_goals msg))
))
