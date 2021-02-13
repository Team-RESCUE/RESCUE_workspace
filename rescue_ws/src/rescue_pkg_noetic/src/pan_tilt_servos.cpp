#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

#include <sstream>

// pan/tilt command callback function
void panTiltCallback(const std_msgs::String::ConstPtr& pan_tilt_msg){
	ROS_INFO("PAN/TILT COMMAND RECEIVED : [%s]", pan_tilt_msg->data.c_str());
	// Interpret command and act accordingly
	// note: command is in string format as a placeholder for prelim testing
}

int main (int argc, char **argv)
{
	// initialize ROS
	ros::init(argc, argv, "pan_tilt_servos");
	ros::NodeHandle n;

	// subscribe to pan/tilt command topic
	ros::Subscriber pan_tilt_sub = n.subscribe("pan_tilt_command", 1000, panTiltCallback);

	ros::spin();	
}