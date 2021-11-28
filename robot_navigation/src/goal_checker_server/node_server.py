import rospy
import rosnode
from diagnostic_msgs.msg import DiagnosticArray, DiagnosticStatus, KeyValue
from std_msgs.msg import String
from robot_navigation.srv import ListNodesAlive, ListNodesAliveResponse
import fnmatch
from enum import Enum
from rosnode import rosnode_ping_all
import os
import csv


class NodeState(Enum):
    """
    Enum for representing the node state with a descriptive name
    """
    Alive = 0
    Removed = 1
    NotStarted = 2
    Dead = 3



# Write node server in a file
class write_node_server_file(object):
    def __init__(self, node_server):
       
        # Store the node in a file to be read by another function 
        self.node_server = node_server
        print("------------------------- Node Server Length -------------------", len(self.node_server))
        
        # Size of the nodes in one line
        self.size_of_nodes = 1

        # Current path minus the current directory
        self.absolute_path = os.path.abspath(os.getcwd()) + "/src/goal_checker_server/node_check_file/node_check.csv" 

        # call the function to add the node in a csv file to be checked
        self.add_node_name()




    # Add the node to the csv file  
    def add_node_name(self):
    
        # Add the csv file name to be checked in the file for it
        print("================= Adding Node Name to CSV file to be Checked ===============")

        # Save the node files 
        with open(self.absolute_path, "w") as csvfileOutput:
            writer = csv.writer(csvfileOutput, delimiter=",")

            for l_input in range(int(len(self.node_server))):

                # When the input for the user will be saved it so it can be used later
                writer.writerow([self.node_server[l_input]])    




class NodeAliveServer(object):

    # these nodes will end up in the report
    tracked_nodes = []
    
    # all nodes that have been observed
    seen_nodes = []

    # nodes that have been just been pinged and returned
    alive_nodes = []
    
    # nodes that are listed by the ros master (also contains crashed nodes)
    listed_nodes = []

    # fn matches of all nodes that need to be neglected
    neglect_nodes = []

    def __init__(self):
        try:
            self.neglect_nodes = rospy.get_param('node_alive/neglect_nodes')
        except KeyError:
            self.neglect_nodes = []
        self.status_prefix = rospy.get_param('/status_prefix', 'node_alive')
        self.loop_rate_hz = rospy.get_param('/update_rate_hz', 0.1)

        self.pub = rospy.Publisher('diagnostics', DiagnosticArray, queue_size=10)
        self.sub = rospy.Subscriber("check_alive_nodes", String, self.callback)
        self.srv = rospy.Service('get_alive_nodes', ListNodesAlive, self.service_callback)



    def is_neglected_node(self, node_name):
        for neglect_node in self.neglect_nodes:
            if fnmatch.fnmatch(node_name, neglect_node):
                return True
        return False

    

    def callback(self, data):
        if data.data not in self.tracked_nodes and not self.is_neglected_node(data.data):
            rospy.loginfo("Added '%s' to node_alive_server" % data.data)
            self.tracked_nodes.append(data.data)



    def service_callback(self, req):
        rospy.logdebug("get_alive_nodes call")

        return ListNodesAliveResponse(
            tracked_nodes=len(self.tracked_nodes),
            seen_nodes=len(self.seen_nodes),
            alive_nodes=len(self.alive_nodes),
            listed_nodes=len(self.listed_nodes),
        )


    def update_nodes(self):
        # first update the listed nodes by the ros master
        self.listed_nodes = rosnode.get_node_names()
        for listed_node in self.listed_nodes:
            if listed_node not in self.tracked_nodes and not self.is_neglected_node(listed_node):
                rospy.loginfo("Added '%s' to node_alive_server" % listed_node)
                self.tracked_nodes.append(listed_node)
            if listed_node not in self.seen_nodes:
                self.seen_nodes.append(listed_node)

        # then ping all nodes and check if they're online
        self.alive_nodes = []

        (ping_nodes, _) = rosnode_ping_all()

        for alive_node in ping_nodes:
            self.alive_nodes.append(alive_node)



    def generate_diagnostic_array(self):
        diagnostic_array = DiagnosticArray()
        diagnostic_array.header.stamp = rospy.get_rostime()

        for tracked_node in self.tracked_nodes:

            # Create diagnostic message
            status_msg = DiagnosticStatus()
            status_msg.name = self.status_prefix + tracked_node

            # Determine node status
            if tracked_node in self.alive_nodes:
                status_msg.level = DiagnosticStatus.OK  # 1. Node is alive --> Status OK
                status_msg.message = "is alive"
                status_msg.values.append(KeyValue("NodeState", NodeState.Alive.name))
            else:
                if tracked_node not in self.listed_nodes:
                    if tracked_node in self.seen_nodes:
                        self.tracked_nodes.remove(tracked_node)
                        rospy.loginfo("Removed '%s' from node_alive_server" % tracked_node)
                        status_msg.level = DiagnosticStatus.OK  # 2. Node has been cleanly removed
                        status_msg.message = "cleanly removed"
                        status_msg.values.append(KeyValue("NodeState", NodeState.Removed.name))
                    else:
                        status_msg.level = DiagnosticStatus.ERROR  # 3. Node did not start at all --> Status ERROR
                        status_msg.message = "did not start"
                        status_msg.values.append(KeyValue("NodeState", NodeState.NotStarted.name))
                else:
                    status_msg.level = DiagnosticStatus.ERROR  # 4. Node crashed --> Status ERROR
                    status_msg.message = "is dead"
                    status_msg.values.append(KeyValue("NodeState", NodeState.Dead.name))

            diagnostic_array.status.append(status_msg)

        return diagnostic_array




    def loop(self):

        seq = 1
        rate = rospy.Rate(self.loop_rate_hz)
        while not rospy.is_shutdown():

            self.update_nodes()

            # # Get to see what nodes is alive and then change it
            # write_node_obj = write_node_server_file(self.tracked_nodes)

            diagnostic_array = self.generate_diagnostic_array()
            diagnostic_array.header.seq = seq
            seq += 1

            # Get to see what nodes is alive and then change it
            write_node_obj = write_node_server_file(self.tracked_nodes)

            self.pub.publish(diagnostic_array)

            rate.sleep()
