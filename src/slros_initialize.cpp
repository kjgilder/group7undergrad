#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "dm_ros_controller2";

// For Block dm_ros_controller2/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_dm_ros_controller2_std_msgs_Float64> Sub_dm_ros_controller2_71;

// For Block dm_ros_controller2/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_dm_ros_controller2_std_msgs_Float64> Sub_dm_ros_controller2_92;

// For Block dm_ros_controller2/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_dm_ros_controller2_std_msgs_Float64> Sub_dm_ros_controller2_72;

// For Block dm_ros_controller2/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_dm_ros_controller2_std_msgs_Float64> Pub_dm_ros_controller2_70;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

