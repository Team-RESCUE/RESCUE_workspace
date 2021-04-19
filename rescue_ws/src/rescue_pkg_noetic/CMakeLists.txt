cmake_minimum_required(VERSION 3.0.2)
project(rescue_pkg_noetic)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
   roscpp
   rospy
   std_msgs
   message_generation
   geometry_msgs
   ## Python 3.8 COMPONENTS Interpreter Development
   ## PythonInterp 3
   ## PythonLibs 3
)

## Declare ROS messages and services
add_message_files(
   DIRECTORY
   msg
   FILES
   ## Num.msg
)
add_service_files(
   DIRECTORY
   srv
   FILES
   ## AddTwoInts.srv
)

catkin_python_setup()

## Generate added messages and services
generate_messages(
   DEPENDENCIES
   std_msgs
   geometry_msgs
)

## Declare a catkin package
catkin_package(
   CATKIN_DEPENDS message_runtime roscpp
   INCLUDE_DIRS include
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
target_link_libraries(ros_master ${catkin_LIBRARIES} ${PYTHON_LIBRARIES})
add_dependencies(ros_master rescue_pkg_noetic_generate_messages_cpp)

## More fun Python shenanigans
## target_link_libraries(ros_master ${CATKIN_LIBRARIES} ${PYTHON_LIBRARIES})

add_executable(marble_dummy src/marble_dummy.cpp)
target_link_libraries(marble_dummy ${catkin_LIBRARIES})
add_dependencies(marble_dummy rescue_pkg_noetic_generate_messages_cpp)

add_executable(pan_tilt_servos src/pan_tilt_servos.cpp)
target_link_libraries(pan_tilt_servos ${catkin_LIBRARIES})
add_dependencies(pan_tilt_servos rescue_pkg_noetic_generate_messages_cpp)

add_executable(ros_control src/ros_control.cpp)
target_link_libraries(ros_control ${catkin_LIBRARIES})
add_dependencies(ros_control rescue_pkg_noetic_generate_messages_cpp)