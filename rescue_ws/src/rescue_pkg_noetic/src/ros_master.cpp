#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

#include <sstream>

int main (int argc, char **argv)
{
	// initialize ROS and specify node name
	ros::init(argc, argv, "ros_master");

	ros::NodeHandle n;

	int status_count = 0; // # of status messages sent

	// system status (ping to MARBLE)
	ros::Publisher status_pub = n.advertise<std_msgs::String>("status_ping_rescue",1000);

	// CO2 flag (ping to MARBLE)
	ros::Publisher co2_pub = n.advertise<std_msgs::Bool>("co2_flag",1000);

	// pan/tilt commands to end effector
	ros::Publisher pan_tilt_pub = n.advertise<std_msgs::String>("pan_tilt_command",1000);

	ros::Rate loop_rate(10);

	while (ros::ok()) {

		std::stringstream ss;

		// ================== System Status ===================
		std_msgs::String status_msg;

		ss << "Test status " << status_count << ": yes" << std::endl;
		status_msg.data = ss.str();


		// print & broadcast status
		ROS_INFO("%s", status_msg.data.c_str());
		status_pub.publish(status_msg);
		// ====================================================


		// ===================== CO2 Flag =====================
		std_msgs::Bool co2_flag_msg;

		// temporarily set to "false"
		// TODO: figure out why "true" gives seg fault
		// 		 also, why doesn't this topic show on rqt_graph
		co2_flag_msg.data = false;

		ROS_INFO("CO2 flag: %s", co2_flag_msg.data);
		co2_pub.publish(co2_flag_msg);
		// ====================================================


		// ================= Pan/Tilt Commands ================
		std_msgs::String pan_tilt_msg;

		ss << "Pan/tilt command " << status_count << ": TILT IT" << std::endl;
		pan_tilt_msg.data = ss.str();

		ROS_INFO("%s", pan_tilt_msg.data.c_str());
		pan_tilt_pub.publish(pan_tilt_msg);

		// ====================================================


		// this will be useful once ros_master is subscribed to topics from various other nodes
		ros::spinOnce();

		// sleep accordingly to meet loop_rate
		loop_rate.sleep();

		++status_count;

	}
}