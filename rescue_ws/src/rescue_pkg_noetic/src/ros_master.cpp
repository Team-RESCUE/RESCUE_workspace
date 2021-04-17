#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "geometry_msgs/PointStamped.h"

#include <sstream>
#include <iostream>
#include <string>

// for python interfacing
// #include "stdafx.h"
#include <Python.h>

void paramCallback(const std_msgs::String::ConstPtr& param_msg) {
	ROS_INFO("Parameter received: [%s]", param_msg->data.c_str());
}

// void pythonCall(){
// 	printf("Calling Python script:\n");
// 	Py_Initialize();
// 	PyObject *pName, *pModule, *pDict, *pFunc, *pArgs, *pValue;
// 	pName = PyString_FromString("pytest"); //convert filename to string
// 	pModule = PyImport_Import(pName); //import file as Python module
// 	pDict = PyModule_GetDict(pModule); //dictionary for module contents
// 	pFunc = PyDict_GetItemString(pDict,"print"); // get print method from dict
// 	// define input args
// 	pArgs = PyTuple_New(1);
// 	pValue = PyInt_FromLong(5);
// 	PyTuple_SetItem(pArgs,0,pValue);
// 	// call function w/ args
// 	PyObject *pResult = PyObject_CallObject(pFunc,pArgs);

// 	// check if method failed
// 	if (pResult == NULL)
// 		printf("Calling the Python script failed\n");

// 	// handle returned value from Python method
// 	long result = PyInt_AsLong(pResult);
	
// 	Py_Finalize();// destroy Python interpreter
	
// 	// print result
// 	printf("The Python method returned %d.\n",result); std::cin.ignore(); 
// }

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

	// target location
	// ros::Publisher target_location_pub = n.advertise<std_msgs::String>("target_location",1000);
	ros::Publisher target_location_pub = n.advertise<geometry_msgs::PointStamped>("target_location",1000);

	// video data
	ros::Publisher video_data_pub = n.advertise<std_msgs::String>("video_data",1000);

	// parameter message from MARBLE
	ros::Subscriber param_sub = n.subscribe("location_command", 1000, paramCallback);

	ros::Rate loop_rate(10);

	while (ros::ok()) {

		std::stringstream ss_status;

		// ================== System Status ===================
		std_msgs::String status_msg;

		ss_status << "Test status " << status_count << ": yes";
		status_msg.data = ss_status.str();


		// print & broadcast status
		ROS_INFO("%s", status_msg.data.c_str());
		status_pub.publish(status_msg);
		// ====================================================

		// ===================== Video Data =====================
		std_msgs::String video_data_msg;

		std::stringstream ss_vid;
		ss_vid << "Video placeholder";
		video_data_msg.data = ss_vid.str();

		ROS_INFO("%s", video_data_msg.data.c_str());
		video_data_pub.publish(video_data_msg);
		
		// =====================================================

		// ===================== CO2 Flag =====================
		std_msgs::Bool co2_flag_msg;

		// temporarily set to "false"
		// TODO: figure out why "true" gives seg fault
		// 		 also, why doesn't this topic show on rqt_graph
		co2_flag_msg.data = false;
		std::string co2_str = std::to_string(co2_flag_msg.data);

		ROS_INFO("CO2 flag: %c", co2_flag_msg.data);
		co2_pub.publish(co2_flag_msg);
		// ====================================================



		// ================= Pan/Tilt Commands ================
		std::stringstream ss_pt;
		std_msgs::String pan_tilt_msg;

		ss_pt << "Pan/tilt command " << status_count << ": Pan 26 deg, Tilt -30 deg";
		pan_tilt_msg.data = ss_pt.str();


		ROS_INFO("%s", pan_tilt_msg.data.c_str());
		pan_tilt_pub.publish(pan_tilt_msg);

		// ====================================================


		// ================= Input Parameters =================

		// ros::Subscriber param_sub = n.subscribe("param_test", 1000, paramCallback);

		// ====================================================


		// ================= Location Commands ================

		geometry_msgs::PointStamped target_point;

		target_point.header.frame_id = "target_point";
		target_point.header.stamp = ros::Time();

		target_point.point.x = 1.3;
		target_point.point.y = 0.8;
		target_point.point.z = 0.5;



		// placeholder string message
		std::stringstream ss_tl;
		std_msgs::String target_location_msg;

		ss_tl << 
		"Target location: \n x = " << target_point.point.x << 
		"\n y = " << target_point.point.y << 
		"\n z = " << target_point.point.z;
		target_location_msg.data = ss_tl.str();

		// ROS_INFO("%s", target_location_msg.data.c_str());
		// target_location_pub.publish(target_location_msg);

		// actual (stamped point) message
		ROS_INFO("%s", ss_tl.str());
		target_location_pub.publish(target_point);
		
		// ====================================================



		// this will be useful once ros_master is subscribed to topics from other nodes
		ros::spinOnce();

		// sleep accordingly to meet loop_rate
		loop_rate.sleep();

		++status_count;

	}
}
