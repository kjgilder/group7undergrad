#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "dm_ros_controller2_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block dm_ros_controller2/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_dm_ros_controller2_std_msgs_Float64> Sub_dm_ros_controller2_71;

// For Block dm_ros_controller2/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_dm_ros_controller2_std_msgs_Float64> Sub_dm_ros_controller2_92;

// For Block dm_ros_controller2/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_dm_ros_controller2_std_msgs_Float64> Sub_dm_ros_controller2_72;

// For Block dm_ros_controller2/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_dm_ros_controller2_std_msgs_Float64> Pub_dm_ros_controller2_70;

void slros_node_init(int argc, char** argv);

#endif
