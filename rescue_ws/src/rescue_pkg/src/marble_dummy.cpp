#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

// status message callback function
void statusCallback(const std_msgs::String::ConstPtr& status_msg) {
	ROS_INFO("STATUS RECEIVED: [%s]", status_msg->data.c_str());
	// interpret status message / act accordingly
}

// co2 flag callback function
void co2Callback(const std_msgs::Bool::ConstPtr& co2_flag_msg) {
	ROS_INFO("CO2 FLAG RECEIVED: [%s]", co2_flag_msg->data);
	// interpret co2 flag / act accordingly
}


int main(int argc, char **argv) {

	ros::init(argc, argv, "marble_dummy");

	ros::NodeHandle n;

	// subscribe to status message topic
	ros::Subscriber status_sub = n.subscribe("status_ping_rescue", 1000, statusCallback);

	// subscribe to co2 flag topic
	ros::Subscriber co2_sub = n.subscribe("co2_flag", 1000, co2Callback);

	ros::spin();
}