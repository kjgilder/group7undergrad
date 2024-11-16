/*
 * dm_ros_controller2_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "dm_ros_controller2".
 *
 * Model version              : 1.5
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Fri Nov 15 19:46:32 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef dm_ros_controller2_types_h_
#define dm_ros_controller2_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_dm_ros_controller2_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_dm_ros_controller2_std_msgs_Float64_

struct SL_Bus_dm_ros_controller2_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                              /* struct_ros_slroscpp_internal_block_P_T */

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                              /* struct_ros_slroscpp_internal_block_S_T */

/* Parameters for system: '<S4>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_dm_ros_con_T_ P_EnabledSubsystem_dm_ros_con_T;

/* Parameters (default storage) */
typedef struct P_dm_ros_controller2_T_ P_dm_ros_controller2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_dm_ros_controller2_T RT_MODEL_dm_ros_controller2_T;

#endif                                 /* dm_ros_controller2_types_h_ */
