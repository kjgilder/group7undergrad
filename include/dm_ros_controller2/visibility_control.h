#ifndef DM_ROS_CONTROLLER2__VISIBILITY_CONTROL_H_
#define DM_ROS_CONTROLLER2__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define DM_ROS_CONTROLLER2_EXPORT __attribute__ ((dllexport))
    #define DM_ROS_CONTROLLER2_IMPORT __attribute__ ((dllimport))
  #else
    #define DM_ROS_CONTROLLER2_EXPORT __declspec(dllexport)
    #define DM_ROS_CONTROLLER2_IMPORT __declspec(dllimport)
  #endif
  #ifdef DM_ROS_CONTROLLER2_BUILDING_LIBRARY
    #define DM_ROS_CONTROLLER2_PUBLIC DM_ROS_CONTROLLER2_EXPORT
  #else
    #define DM_ROS_CONTROLLER2_PUBLIC DM_ROS_CONTROLLER2_IMPORT
  #endif
  #define DM_ROS_CONTROLLER2_PUBLIC_TYPE DM_ROS_CONTROLLER2_PUBLIC
  #define DM_ROS_CONTROLLER2_LOCAL
#else
  #define DM_ROS_CONTROLLER2_EXPORT __attribute__ ((visibility("default")))
  #define DM_ROS_CONTROLLER2_IMPORT
  #if __GNUC__ >= 4
    #define DM_ROS_CONTROLLER2_PUBLIC __attribute__ ((visibility("default")))
    #define DM_ROS_CONTROLLER2_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define DM_ROS_CONTROLLER2_PUBLIC
    #define DM_ROS_CONTROLLER2_LOCAL
  #endif
  #define DM_ROS_CONTROLLER2_PUBLIC_TYPE
#endif
#endif  // DM_ROS_CONTROLLER2__VISIBILITY_CONTROL_H_
// Generated 15-Nov-2024 19:46:36
// Copyright 2019-2020 The MathWorks, Inc.
