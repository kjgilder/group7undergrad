/*
 * group7undergrad.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "group7undergrad".
 *
 * Model version              : 1.51
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov 18 12:58:58 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef group7undergrad_h_
#define group7undergrad_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "group7undergrad_types.h"
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S4>/Enabled Subsystem' */
struct B_EnabledSubsystem_group7unde_T {
  SL_Bus_group7undergrad_std_msgs_Float64 In1;/* '<S7>/In1' */
};

/* Block signals (default storage) */
struct B_group7undergrad_T {
  B_EnabledSubsystem_group7unde_T EnabledSubsystem_a;/* '<S6>/Enabled Subsystem' */
  B_EnabledSubsystem_group7unde_T EnabledSubsystem_d;/* '<S5>/Enabled Subsystem' */
  B_EnabledSubsystem_group7unde_T EnabledSubsystem;/* '<S4>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_group7undergrad_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S3>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_l;/* '<S6>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_p;/* '<S5>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_pp;/* '<S4>/SourceBlock' */
  real_T sim_time;                     /* '<Root>/Data Store Memory' */
  real_T stop_light_distance;          /* '<Root>/Data Store Memory2' */
  boolean_T objisempty;                /* '<S6>/SourceBlock' */
  boolean_T objisempty_d;              /* '<S5>/SourceBlock' */
  boolean_T objisempty_o;              /* '<S4>/SourceBlock' */
  boolean_T objisempty_i;              /* '<S3>/SinkBlock' */
};

/* Parameters for system: '<S4>/Enabled Subsystem' */
struct P_EnabledSubsystem_group7unde_T_ {
  SL_Bus_group7undergrad_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                                   * Referenced by: '<S7>/Out1'
                                                   */
};

/* Parameters (default storage) */
struct P_group7undergrad_T_ {
  SL_Bus_group7undergrad_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                          * Referenced by: '<S2>/Constant'
                                                          */
  SL_Bus_group7undergrad_std_msgs_Float64 Constant_Value_h;/* Computed Parameter: Constant_Value_h
                                                            * Referenced by: '<S4>/Constant'
                                                            */
  SL_Bus_group7undergrad_std_msgs_Float64 Constant_Value_n;/* Computed Parameter: Constant_Value_n
                                                            * Referenced by: '<S5>/Constant'
                                                            */
  SL_Bus_group7undergrad_std_msgs_Float64 Constant_Value_e;/* Computed Parameter: Constant_Value_e
                                                            * Referenced by: '<S6>/Constant'
                                                            */
  real_T Constant_Value_b;             /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 100
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T DataStoreMemory2_InitialValue;/* Expression: 500
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  P_EnabledSubsystem_group7unde_T EnabledSubsystem_a;/* '<S6>/Enabled Subsystem' */
  P_EnabledSubsystem_group7unde_T EnabledSubsystem_d;/* '<S5>/Enabled Subsystem' */
  P_EnabledSubsystem_group7unde_T EnabledSubsystem;/* '<S4>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_group7undergrad_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_group7undergrad_T group7undergrad_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_group7undergrad_T group7undergrad_B;

#ifdef __cplusplus

}

#endif

/* Block states (default storage) */
extern struct DW_group7undergrad_T group7undergrad_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void group7undergrad_initialize(void);
  extern void group7undergrad_step(void);
  extern void group7undergrad_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_group7undergrad_T *const group7undergrad_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'group7undergrad'
 * '<S1>'   : 'group7undergrad/MATLAB Function1'
 * '<S2>'   : 'group7undergrad/Message'
 * '<S3>'   : 'group7undergrad/Publish'
 * '<S4>'   : 'group7undergrad/Subscribe_dist'
 * '<S5>'   : 'group7undergrad/Subscribe_rel_vel'
 * '<S6>'   : 'group7undergrad/Subscribe_vel_x'
 * '<S7>'   : 'group7undergrad/Subscribe_dist/Enabled Subsystem'
 * '<S8>'   : 'group7undergrad/Subscribe_rel_vel/Enabled Subsystem'
 * '<S9>'   : 'group7undergrad/Subscribe_vel_x/Enabled Subsystem'
 */
#endif                                 /* group7undergrad_h_ */
