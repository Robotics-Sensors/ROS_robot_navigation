;; Auto-generated. Do not edit!


(when (boundp 'robot_navigation::SimLog)
  (if (not (find-package "ROBOT_NAVIGATION"))
    (make-package "ROBOT_NAVIGATION"))
  (shadow 'SimLog (find-package "ROBOT_NAVIGATION")))
(unless (find-package "ROBOT_NAVIGATION::SIMLOG")
  (make-package "ROBOT_NAVIGATION::SIMLOG"))

(in-package "ROS")
;;//! \htmlinclude SimLog.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass robot_navigation::SimLog
  :super ros::object
  :slots (_header _robot_pos _goal _dist_from_goal _collision _iteration _event ))

(defmethod robot_navigation::SimLog
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:robot_pos __robot_pos) (instance geometry_msgs::Pose2D :init))
    ((:goal __goal) (instance geometry_msgs::Point :init))
    ((:dist_from_goal __dist_from_goal) 0.0)
    ((:collision __collision) (instance geometry_msgs::Point :init))
    ((:iteration __iteration) 0)
    ((:event __event) "")
    )
   (send-super :init)
   (setq _header __header)
   (setq _robot_pos __robot_pos)
   (setq _goal __goal)
   (setq _dist_from_goal (float __dist_from_goal))
   (setq _collision __collision)
   (setq _iteration (round __iteration))
   (setq _event (string __event))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:robot_pos
   (&rest __robot_pos)
   (if (keywordp (car __robot_pos))
       (send* _robot_pos __robot_pos)
     (progn
       (if __robot_pos (setq _robot_pos (car __robot_pos)))
       _robot_pos)))
  (:goal
   (&rest __goal)
   (if (keywordp (car __goal))
       (send* _goal __goal)
     (progn
       (if __goal (setq _goal (car __goal)))
       _goal)))
  (:dist_from_goal
   (&optional __dist_from_goal)
   (if __dist_from_goal (setq _dist_from_goal __dist_from_goal)) _dist_from_goal)
  (:collision
   (&rest __collision)
   (if (keywordp (car __collision))
       (send* _collision __collision)
     (progn
       (if __collision (setq _collision (car __collision)))
       _collision)))
  (:iteration
   (&optional __iteration)
   (if __iteration (setq _iteration __iteration)) _iteration)
  (:event
   (&optional __event)
   (if __event (setq _event __event)) _event)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Pose2D _robot_pos
    (send _robot_pos :serialization-length)
    ;; geometry_msgs/Point _goal
    (send _goal :serialization-length)
    ;; float64 _dist_from_goal
    8
    ;; geometry_msgs/Point _collision
    (send _collision :serialization-length)
    ;; uint8 _iteration
    1
    ;; string _event
    4 (length _event)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Pose2D _robot_pos
       (send _robot_pos :serialize s)
     ;; geometry_msgs/Point _goal
       (send _goal :serialize s)
     ;; float64 _dist_from_goal
       (sys::poke _dist_from_goal (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; geometry_msgs/Point _collision
       (send _collision :serialize s)
     ;; uint8 _iteration
       (write-byte _iteration s)
     ;; string _event
       (write-long (length _event) s) (princ _event s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Pose2D _robot_pos
     (send _robot_pos :deserialize buf ptr-) (incf ptr- (send _robot_pos :serialization-length))
   ;; geometry_msgs/Point _goal
     (send _goal :deserialize buf ptr-) (incf ptr- (send _goal :serialization-length))
   ;; float64 _dist_from_goal
     (setq _dist_from_goal (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; geometry_msgs/Point _collision
     (send _collision :deserialize buf ptr-) (incf ptr- (send _collision :serialization-length))
   ;; uint8 _iteration
     (setq _iteration (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _event
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _event (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get robot_navigation::SimLog :md5sum-) "cc387dc22a2d950d15b2be5ad31d16db")
(setf (get robot_navigation::SimLog :datatype-) "robot_navigation/SimLog")
(setf (get robot_navigation::SimLog :definition-)
      "Header header
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

")



(provide :robot_navigation/SimLog "cc387dc22a2d950d15b2be5ad31d16db")


