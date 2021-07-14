;; Auto-generated. Do not edit!


(when (boundp 'robot_navigation::Goal)
  (if (not (find-package "ROBOT_NAVIGATION"))
    (make-package "ROBOT_NAVIGATION"))
  (shadow 'Goal (find-package "ROBOT_NAVIGATION")))
(unless (find-package "ROBOT_NAVIGATION::GOAL")
  (make-package "ROBOT_NAVIGATION::GOAL"))

(in-package "ROS")
;;//! \htmlinclude Goal.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass robot_navigation::Goal
  :super ros::object
  :slots (_goal _description _total_goals ))

(defmethod robot_navigation::Goal
  (:init
   (&key
    ((:goal __goal) (instance geometry_msgs::Pose2D :init))
    ((:description __description) "")
    ((:total_goals __total_goals) 0)
    )
   (send-super :init)
   (setq _goal __goal)
   (setq _description (string __description))
   (setq _total_goals (round __total_goals))
   self)
  (:goal
   (&rest __goal)
   (if (keywordp (car __goal))
       (send* _goal __goal)
     (progn
       (if __goal (setq _goal (car __goal)))
       _goal)))
  (:description
   (&optional __description)
   (if __description (setq _description __description)) _description)
  (:total_goals
   (&optional __total_goals)
   (if __total_goals (setq _total_goals __total_goals)) _total_goals)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Pose2D _goal
    (send _goal :serialization-length)
    ;; string _description
    4 (length _description)
    ;; uint16 _total_goals
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Pose2D _goal
       (send _goal :serialize s)
     ;; string _description
       (write-long (length _description) s) (princ _description s)
     ;; uint16 _total_goals
       (write-word _total_goals s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Pose2D _goal
     (send _goal :deserialize buf ptr-) (incf ptr- (send _goal :serialization-length))
   ;; string _description
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _description (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint16 _total_goals
     (setq _total_goals (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get robot_navigation::Goal :md5sum-) "c07a3dfa52044e15fc6e0a0dae2b5434")
(setf (get robot_navigation::Goal :datatype-) "robot_navigation/Goal")
(setf (get robot_navigation::Goal :definition-)
      "geometry_msgs/Pose2D goal
string description
uint16 total_goals
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

")



(provide :robot_navigation/Goal "c07a3dfa52044e15fc6e0a0dae2b5434")


