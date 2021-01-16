#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main (int argc, char **argv)
{

	// initialize ROS and specify node name
	ros::init(argc, argv, "test_talker");

	// create handle to node
	ros::NodeHandle n;

	// specify message type (string) and size of publishing queue (1000 messages)
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

	// set loop rate to 10Hz
	ros::Rate loop_rate(10);

	int count = 0; // # of messages sent

	// handle SIGINT or other terminations
	while (ros::ok()) {

		std_msgs::String msg; // message object

		std::stringstream ss;
		ss << "hello there" << count;
		msg.data = ss.str();

		ROS_INFO("%s", msg.data.c_str()); // acts as printf/cout

		// broadcast message for any subscribed nodes
		chatter_pub.publish(msg);

		// not necessary if not subscribing to another node, added for good measure
		// if subscribed to other node, we would need this to handle callbacks
		ros::spinOnce();

		// sleep for time remaining to meet loop_rate
		loop_rate.sleep();
		++count;
	}

}