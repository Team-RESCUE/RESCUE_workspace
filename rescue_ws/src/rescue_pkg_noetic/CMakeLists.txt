cmake_minimum_required(VERSION 3.0.2)
project(rescue_pkg_noetic)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
   roscpp
   rospy
   std_msgs
   message_generation
)

## Declare ROS messages and services
add_message_files(
   FILES
   Num.msg
)
add_service_files(
   FILES
   AddTwoInts.srv
)

## Generate added messages and services
generate_messages(
   DEPENDENCIES
   std_msgs
)

## Declare a catkin package
catkin_package(
   CATKIN_DEPENDS message_runtime
)

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(test_talker src/test_talker.cpp)
target_link_libraries(test_talker ${catkin_LIBRARIES})
add_dependencies(test_talker rescue_pkg_noetic_generate_messages_cpp)

add_executable(test_listener src/test_listener.cpp)
target_link_libraries(test_listener ${catkin_LIBRARIES})
add_dependencies(test_listener rescue_pkg_noetic_generate_messages_cpp)

add_executable(ros_master src/ros_master.cpp)
target_link_libraries(ros_master ${catkin_LIBRARIES})
add_dependencies(ros_master rescue_pkg_noetic_generate_messages_cpp)

add_executable(marble_dummy src/marble_dummy.cpp)
target_link_libraries(marble_dummy ${catkin_LIBRARIES})
add_dependencies(marble_dummy rescue_pkg_noetic_generate_messages_cpp)