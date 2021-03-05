#include "ros/ros.h"
#include "std_msgs/String.h"


// target location callback function
void targetCallback(const std_msgs::String::ConstPtr& target_location_msg) {
	ROS_INFO("TARGET LOCATION RECEIVED : [%s]", target_location_msg->data.c_str());
	// Interpret command and act accordingly
	// TO DO: 
	// 		change command to location (and Euler orientation?)
}

int main (int argc, char **argv) {
	// initialize ROS
	ros::init(argc, argv, "target_location");
	ros::NodeHandle n;

	// subscribe to target location topic
	ros::Subscriber target_location_sub = n.subscribe("target_location", 1000, targetCallback);

	ros::spin();
}