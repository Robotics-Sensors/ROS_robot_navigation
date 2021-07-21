
(cl:in-package :asdf)

(defsystem "robot_navigation-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "Goal" :depends-on ("_package_Goal"))
    (:file "_package_Goal" :depends-on ("_package"))
    (:file "SimLog" :depends-on ("_package_SimLog"))
    (:file "_package_SimLog" :depends-on ("_package"))
  ))