# RESCUE_workspace
ROS workspace containing the RESCUE team's custom-built ROS package, `rescue_pkg`

## ROS Nodes & Topics

#### Communication

[`/ros_master`](https://github.com/Team-RESCUE/RESCUE_workspace/blob/main/rescue_ws/src/rescue_pkg_noetic/src/ros_master.cpp) will handle all communications with the MARBLE system, as well as command and data processing. 

`/ros_control`(Not created yet) will convert target locations from `/ros_master` to PID control commands for use in actuation.

#### Actuation

`/hardware_interface`(Not created yet) will handle PID control commands from `/ros_control` to orient the base, extend the arm, and pan/tilt the end effector. 

#### Test Nodes
Two test nodes, `test_talker` and `test_listener`, have been established for basic communication testing. To run them yourself, refer to this [ROS tutorial](https://wiki.ros.org/ROS/Tutorials/ExaminingPublisherSubscriber).


