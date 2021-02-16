#include "ros/ros.h"
#include "std_msgs/String.h"


// callback function, called when a new message arrives on the "chatter" topic
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv) {

	// initialize ROS before using any part of the ROS system
	ros::init(argc, argv, "listener");

	// initialize same node handle as in test_talker
	ros::NodeHandle n;

	// subscribe to the chatter topic and call chatterCallback() whenever a message is received
	// with a max. queue size of 1000
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	// enter a loop, calling message callbacks as fast as possible
	// exits once ros::ok() returns false
	ros::spin();
}