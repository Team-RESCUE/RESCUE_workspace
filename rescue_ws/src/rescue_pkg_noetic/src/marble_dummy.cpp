#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

#include <sstream>
#include <iostream>
#include <string>
#include <typeinfo>

// status message callback function
void statusCallback(const std_msgs::String::ConstPtr& status_msg) {
	ROS_INFO("STATUS RECEIVED: [%s]", status_msg->data.c_str());
	// interpret status message / act accordingly
}

// co2 flag callback function
void co2Callback(const std_msgs::Bool::ConstPtr& co2_flag_msg) {
	std::string co2_str = std::to_string(co2_flag_msg->data);
	ROS_INFO("CO2 FLAG RECEIVED:");
	const char* datatype = typeid(co2_flag_msg->data).name();
	std::cout << co2_flag_msg->data << std::endl;
	// interpret co2 flag / act accordingly
}


int main(int argc, char **argv) {

	ros::init(argc, argv, "marble_dummy");

	ros::NodeHandle n;

	// subscribe to status message topic
	ros::Subscriber status_sub = n.subscribe("status_ping_rescue", 1000, statusCallback);

	// subscribe to co2 flag topic
	ros::Subscriber co2_sub = n.subscribe("co2_flag", 1000, co2Callback);

	ros::Publisher msg_pub = n.advertise<std_msgs::String>("location_command",1000);

	ros::Rate loop_rate(10);

	while (ros::ok()) {
		// =================== Param message ===================

		// std::string param_msg;
		std_msgs::String msg;

		// if (n.getParam("param", param_msg)) {
		// 	ROS_INFO("Parameter received: %s",param_msg.c_str());
		// 	msg.data = msg_param.c_str()
		// }


		std::stringstream ss_test;
		ss_test << "test message" << std::endl;
		msg.data = ss_test.str();

		ROS_INFO("Message out: %s",msg.data.c_str());

		// msg_pub.publish(msg);



		// =====================================================
		ros::spinOnce();
		loop_rate.sleep();
	}
	// ros::spin();

}