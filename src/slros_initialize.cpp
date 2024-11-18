#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "group7undergrad";

// For Block group7undergrad/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_group7undergrad_std_msgs_Float64> Sub_group7undergrad_67;

// For Block group7undergrad/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_group7undergrad_std_msgs_Float64> Pub_group7undergrad_20;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

