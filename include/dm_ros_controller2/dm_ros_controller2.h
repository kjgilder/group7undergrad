/*
 * dm_ros_controller2.h
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

#ifndef dm_ros_controller2_h_
#define dm_ros_controller2_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "dm_ros_controller2_types.h"
#include <string.h>
#include <stddef.h>
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals for system '<S4>/Enabled Subsystem' */
struct B_EnabledSubsystem_dm_ros_con_T {
  SL_Bus_dm_ros_controller2_std_msgs_Float64 In1;/* '<S8>/In1' */
};

/* Block signals (default storage) */
struct B_dm_ros_controller2_T {
  real_T Clock3;                       /* '<Root>/Clock3' */
  real_T Sum;                          /* '<S7>/Sum' */
  real_T vel_ego;
  boolean_T RelationalOperator1;       /* '<Root>/Relational Operator1' */
  B_EnabledSubsystem_dm_ros_con_T EnabledSubsystem_b;/* '<S6>/Enabled Subsystem' */
  B_EnabledSubsystem_dm_ros_con_T EnabledSubsystem_n;/* '<S5>/Enabled Subsystem' */
  B_EnabledSubsystem_dm_ros_con_T EnabledSubsystem;/* '<S4>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_dm_ros_controller2_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S3>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_l;/* '<S6>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_e;/* '<S5>/SourceBlock' */
  ros_slroscpp_internal_block_S_T obj_m;/* '<S4>/SourceBlock' */
  real_T Memory_PreviousInput;         /* '<S7>/Memory' */
  boolean_T objisempty;                /* '<S6>/SourceBlock' */
  boolean_T objisempty_f;              /* '<S5>/SourceBlock' */
  boolean_T objisempty_o;              /* '<S4>/SourceBlock' */
  boolean_T objisempty_h;              /* '<S3>/SinkBlock' */
};

/* Continuous states (default storage) */
struct X_dm_ros_controller2_T {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
};

/* State derivatives (default storage) */
struct XDot_dm_ros_controller2_T {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
};

/* State disabled  */
struct XDis_dm_ros_controller2_T {
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
};

/* Zero-crossing (trigger) state */
struct PrevZCX_dm_ros_controller2_T {
  ZCSigState TriggeredSubsystem1_Trig_ZCE;/* '<Root>/Triggered Subsystem1' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters for system: '<S4>/Enabled Subsystem' */
struct P_EnabledSubsystem_dm_ros_con_T_ {
  SL_Bus_dm_ros_controller2_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                                      * Referenced by: '<S8>/Out1'
                                                      */
};

/* Parameters (default storage) */
struct P_dm_ros_controller2_T_ {
  SL_Bus_dm_ros_controller2_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                             * Referenced by: '<S1>/Constant'
                                                             */
  SL_Bus_dm_ros_controller2_std_msgs_Float64 Constant_Value_o;/* Computed Parameter: Constant_Value_o
                                                               * Referenced by: '<S4>/Constant'
                                                               */
  SL_Bus_dm_ros_controller2_std_msgs_Float64 Constant_Value_p;/* Computed Parameter: Constant_Value_p
                                                               * Referenced by: '<S5>/Constant'
                                                               */
  SL_Bus_dm_ros_controller2_std_msgs_Float64 Constant_Value_g;/* Computed Parameter: Constant_Value_g
                                                               * Referenced by: '<S6>/Constant'
                                                               */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S7>/Out1'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T initial_space_to_int1_Value;  /* Expression: 500
                                        * Referenced by: '<Root>/initial_space_to_int1'
                                        */
  real_T threshold_distance1_Value;    /* Expression: 100
                                        * Referenced by: '<Root>/threshold_distance1'
                                        */
  real_T initial_time_to_green_Value;  /* Expression: 12
                                        * Referenced by: '<Root>/initial_time_to_green'
                                        */
  P_EnabledSubsystem_dm_ros_con_T EnabledSubsystem_b;/* '<S6>/Enabled Subsystem' */
  P_EnabledSubsystem_dm_ros_con_T EnabledSubsystem_n;/* '<S5>/Enabled Subsystem' */
  P_EnabledSubsystem_dm_ros_con_T EnabledSubsystem;/* '<S4>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_dm_ros_controller2_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_dm_ros_controller2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_dm_ros_controller2_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_dm_ros_controller2_T dm_ros_controller2_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_dm_ros_controller2_T dm_ros_controller2_B;

#ifdef __cplusplus

}

#endif

/* Continuous states (default storage) */
extern X_dm_ros_controller2_T dm_ros_controller2_X;

/* Disabled states (default storage) */
extern XDis_dm_ros_controller2_T dm_ros_controller2_XDis;

/* Block states (default storage) */
extern struct DW_dm_ros_controller2_T dm_ros_controller2_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_dm_ros_controller2_T dm_ros_controller2_PrevZCX;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void dm_ros_controller2_initialize(void);
  extern void dm_ros_controller2_step(void);
  extern void dm_ros_controller2_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_dm_ros_controller2_T *const dm_ros_controller2_M;

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
 * '<Root>' : 'dm_ros_controller2'
 * '<S1>'   : 'dm_ros_controller2/Blank Message'
 * '<S2>'   : 'dm_ros_controller2/MATLAB Function1'
 * '<S3>'   : 'dm_ros_controller2/Publish'
 * '<S4>'   : 'dm_ros_controller2/Subscribe'
 * '<S5>'   : 'dm_ros_controller2/Subscribe1'
 * '<S6>'   : 'dm_ros_controller2/Subscribe2'
 * '<S7>'   : 'dm_ros_controller2/Triggered Subsystem1'
 * '<S8>'   : 'dm_ros_controller2/Subscribe/Enabled Subsystem'
 * '<S9>'   : 'dm_ros_controller2/Subscribe1/Enabled Subsystem'
 * '<S10>'  : 'dm_ros_controller2/Subscribe2/Enabled Subsystem'
 */
#endif                                 /* dm_ros_controller2_h_ */
