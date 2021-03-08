#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/PointStamped.h"


// target location callback function
// void targetCallback(const std_msgs::String::ConstPtr& target_location_msg) {
void targetCallback(const geometry_msgs::PointStamped::ConstPtr& target_point) {
	std::stringstream coords_string;

	// coords_string << "\n x = " << target_point.point.x <<
	// "\n y = " << target_point.point.y <<
	// "\n z = " << target_point.point.z;
	// ROS_INFO("TARGET LOCATION RECEIVED : [%s]", coords_string);//target_location_msg->data.c_str());
	ROS_INFO("TARGET LOCATION RECEIVED");
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