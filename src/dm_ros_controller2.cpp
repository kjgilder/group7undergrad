/*
 * dm_ros_controller2.cpp
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

#include "dm_ros_controller2.h"
#include "rtwtypes.h"
#include "dm_ros_controller2_types.h"
#include "dm_ros_controller2_private.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
B_dm_ros_controller2_T dm_ros_controller2_B;

/* Continuous states */
X_dm_ros_controller2_T dm_ros_controller2_X;

/* Disabled State Vector */
XDis_dm_ros_controller2_T dm_ros_controller2_XDis;

/* Block states (default storage) */
DW_dm_ros_controller2_T dm_ros_controller2_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_dm_ros_controller2_T dm_ros_controller2_PrevZCX;

/* Real-time model */
RT_MODEL_dm_ros_controller2_T dm_ros_controller2_M_ =
  RT_MODEL_dm_ros_controller2_T();
RT_MODEL_dm_ros_controller2_T *const dm_ros_controller2_M =
  &dm_ros_controller2_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  dm_ros_controller2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  dm_ros_controller2_step();
  dm_ros_controller2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  dm_ros_controller2_step();
  dm_ros_controller2_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 *    '<S6>/Enabled Subsystem'
 */
void dm_ros_co_EnabledSubsystem_Init(B_EnabledSubsystem_dm_ros_con_T *localB,
  P_EnabledSubsystem_dm_ros_con_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
   *  Outport: '<S8>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 *    '<S6>/Enabled Subsystem'
 */
void dm_ros_control_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_dm_ros_controller2_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_dm_ros_con_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S8>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
}

/* Model step function */
void dm_ros_controller2_step(void)
{
  /* local block i/o variables */
  SL_Bus_dm_ros_controller2_std_msgs_Float64 rtb_SourceBlock_o2;
  SL_Bus_dm_ros_controller2_std_msgs_Float64 rtb_SourceBlock_o2_j;
  SL_Bus_dm_ros_controller2_std_msgs_Float64 rtb_SourceBlock_o2_p;
  boolean_T rtb_SourceBlock_o1;
  boolean_T rtb_SourceBlock_o1_e;
  boolean_T rtb_SourceBlock_o1_b;
  SL_Bus_dm_ros_controller2_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Sum1;
  real_T rtb_x_to_int;
  real_T time_gap;
  if (rtmIsMajorTimeStep(dm_ros_controller2_M)) {
    /* set solver stop time */
    if (!(dm_ros_controller2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&dm_ros_controller2_M->solverInfo,
                            ((dm_ros_controller2_M->Timing.clockTickH0 + 1) *
        dm_ros_controller2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&dm_ros_controller2_M->solverInfo,
                            ((dm_ros_controller2_M->Timing.clockTick0 + 1) *
        dm_ros_controller2_M->Timing.stepSize0 +
        dm_ros_controller2_M->Timing.clockTickH0 *
        dm_ros_controller2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(dm_ros_controller2_M)) {
    dm_ros_controller2_M->Timing.t[0] = rtsiGetT
      (&dm_ros_controller2_M->solverInfo);
  }

  /* Sum: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/initial_space_to_int1'
   *  Integrator: '<Root>/Integrator1'
   */
  rtb_x_to_int = dm_ros_controller2_P.initial_space_to_int1_Value -
    dm_ros_controller2_X.Integrator1_CSTATE;

  /* Clock: '<Root>/Clock3' incorporates:
   *  Clock: '<Root>/Clock4'
   */
  dm_ros_controller2_B.Clock3 = dm_ros_controller2_M->Timing.t[0];

  /* RelationalOperator: '<Root>/Relational Operator1' incorporates:
   *  Constant: '<Root>/threshold_distance1'
   */
  dm_ros_controller2_B.RelationalOperator1 = (rtb_x_to_int <=
    dm_ros_controller2_P.threshold_distance1_Value);
  if (rtmIsMajorTimeStep(dm_ros_controller2_M)) {
    /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem1' incorporates:
     *  TriggerPort: '<S7>/Trigger'
     */
    if (rtsiIsModeUpdateTimeStep(&dm_ros_controller2_M->solverInfo)) {
      if (dm_ros_controller2_B.RelationalOperator1 &&
          (dm_ros_controller2_PrevZCX.TriggeredSubsystem1_Trig_ZCE != POS_ZCSIG))
      {
        /* Sum: '<S7>/Sum' */
        dm_ros_controller2_B.Sum = dm_ros_controller2_B.Clock3 -
          dm_ros_controller2_DW.Memory_PreviousInput;

        /* Update for Memory: '<S7>/Memory' */
        dm_ros_controller2_DW.Memory_PreviousInput = dm_ros_controller2_B.Clock3;
      }

      dm_ros_controller2_PrevZCX.TriggeredSubsystem1_Trig_ZCE =
        dm_ros_controller2_B.RelationalOperator1;
    }

    /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem1' */
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/initial_time_to_green'
   *  Sum: '<Root>/Sum3'
   */
  rtb_Sum1 = dm_ros_controller2_P.initial_time_to_green_Value -
    (dm_ros_controller2_B.Clock3 - dm_ros_controller2_B.Sum);
  if (rtmIsMajorTimeStep(dm_ros_controller2_M)) {
    /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
    /* MATLABSystem: '<S4>/SourceBlock' */
    rtb_SourceBlock_o1_b = Sub_dm_ros_controller2_71.getLatestMessage
      (&rtb_SourceBlock_o2_p);

    /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' */
    dm_ros_control_EnabledSubsystem(rtb_SourceBlock_o1_b, &rtb_SourceBlock_o2_p,
      &dm_ros_controller2_B.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe' */

    /* Outputs for Atomic SubSystem: '<Root>/Subscribe2' */
    /* MATLABSystem: '<S6>/SourceBlock' */
    rtb_SourceBlock_o1 = Sub_dm_ros_controller2_72.getLatestMessage
      (&rtb_SourceBlock_o2);

    /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' */
    dm_ros_control_EnabledSubsystem(rtb_SourceBlock_o1, &rtb_SourceBlock_o2,
      &dm_ros_controller2_B.EnabledSubsystem_b);

    /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe2' */

    /* Outputs for Atomic SubSystem: '<Root>/Subscribe1' */
    /* MATLABSystem: '<S5>/SourceBlock' */
    rtb_SourceBlock_o1_e = Sub_dm_ros_controller2_92.getLatestMessage
      (&rtb_SourceBlock_o2_j);

    /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' */
    dm_ros_control_EnabledSubsystem(rtb_SourceBlock_o1_e, &rtb_SourceBlock_o2_j,
      &dm_ros_controller2_B.EnabledSubsystem_n);

    /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Subscribe1' */
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/threshold_distance1'
   */
  dm_ros_controller2_B.vel_ego = dm_ros_controller2_B.EnabledSubsystem.In1.Data;
  if (dm_ros_controller2_B.EnabledSubsystem_b.In1.Data < 0.0) {
    rtb_x_to_int = 0.0;
  } else {
    if ((dm_ros_controller2_B.EnabledSubsystem.In1.Data > -0.01) &&
        (dm_ros_controller2_B.EnabledSubsystem.In1.Data < 0.01)) {
      dm_ros_controller2_B.vel_ego = 0.01;
    }

    time_gap = dm_ros_controller2_B.EnabledSubsystem_b.In1.Data /
      dm_ros_controller2_B.vel_ego;
    if (time_gap < 2.0) {
      rtb_x_to_int = (time_gap - 2.0) * 0.5 +
        dm_ros_controller2_B.EnabledSubsystem_n.In1.Data;
    } else if ((rtb_x_to_int < dm_ros_controller2_P.threshold_distance1_Value) &&
               (rtb_x_to_int > 0.0)) {
      rtb_x_to_int = (rtb_x_to_int - dm_ros_controller2_B.vel_ego * rtb_Sum1) *
        2.0 / (rtb_Sum1 * rtb_Sum1);
    } else {
      rtb_x_to_int = 15.0 - dm_ros_controller2_B.vel_ego;
    }

    if (rtb_x_to_int > 1.5) {
      rtb_x_to_int = 1.5;
    } else if (rtb_x_to_int < -3.0) {
      rtb_x_to_int = -3.0;
    }
  }

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  rtb_BusAssignment.Data = rtb_x_to_int;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_dm_ros_controller2_70.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
  if (rtmIsMajorTimeStep(dm_ros_controller2_M)) {
    rt_ertODEUpdateContinuousStates(&dm_ros_controller2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++dm_ros_controller2_M->Timing.clockTick0)) {
      ++dm_ros_controller2_M->Timing.clockTickH0;
    }

    dm_ros_controller2_M->Timing.t[0] = rtsiGetSolverStopTime
      (&dm_ros_controller2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      dm_ros_controller2_M->Timing.clockTick1++;
      if (!dm_ros_controller2_M->Timing.clockTick1) {
        dm_ros_controller2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void dm_ros_controller2_derivatives(void)
{
  XDot_dm_ros_controller2_T *_rtXdot;
  _rtXdot = ((XDot_dm_ros_controller2_T *) dm_ros_controller2_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = dm_ros_controller2_B.EnabledSubsystem.In1.Data;
}

/* Model initialize function */
void dm_ros_controller2_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&dm_ros_controller2_M->solverInfo,
                          &dm_ros_controller2_M->Timing.simTimeStep);
    rtsiSetTPtr(&dm_ros_controller2_M->solverInfo, &rtmGetTPtr
                (dm_ros_controller2_M));
    rtsiSetStepSizePtr(&dm_ros_controller2_M->solverInfo,
                       &dm_ros_controller2_M->Timing.stepSize0);
    rtsiSetdXPtr(&dm_ros_controller2_M->solverInfo,
                 &dm_ros_controller2_M->derivs);
    rtsiSetContStatesPtr(&dm_ros_controller2_M->solverInfo, (real_T **)
                         &dm_ros_controller2_M->contStates);
    rtsiSetNumContStatesPtr(&dm_ros_controller2_M->solverInfo,
      &dm_ros_controller2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&dm_ros_controller2_M->solverInfo,
      &dm_ros_controller2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&dm_ros_controller2_M->solverInfo,
      &dm_ros_controller2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&dm_ros_controller2_M->solverInfo,
      &dm_ros_controller2_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&dm_ros_controller2_M->solverInfo, (boolean_T**)
      &dm_ros_controller2_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&dm_ros_controller2_M->solverInfo, (&rtmGetErrorStatus
      (dm_ros_controller2_M)));
    rtsiSetRTModelPtr(&dm_ros_controller2_M->solverInfo, dm_ros_controller2_M);
  }

  rtsiSetSimTimeStep(&dm_ros_controller2_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&dm_ros_controller2_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&dm_ros_controller2_M->solverInfo, false);
  dm_ros_controller2_M->intgData.y = dm_ros_controller2_M->odeY;
  dm_ros_controller2_M->intgData.f[0] = dm_ros_controller2_M->odeF[0];
  dm_ros_controller2_M->intgData.f[1] = dm_ros_controller2_M->odeF[1];
  dm_ros_controller2_M->intgData.f[2] = dm_ros_controller2_M->odeF[2];
  dm_ros_controller2_M->contStates = ((X_dm_ros_controller2_T *)
    &dm_ros_controller2_X);
  dm_ros_controller2_M->contStateDisabled = ((XDis_dm_ros_controller2_T *)
    &dm_ros_controller2_XDis);
  dm_ros_controller2_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&dm_ros_controller2_M->solverInfo, static_cast<void *>
                    (&dm_ros_controller2_M->intgData));
  rtsiSetSolverName(&dm_ros_controller2_M->solverInfo,"ode3");
  rtmSetTPtr(dm_ros_controller2_M, &dm_ros_controller2_M->Timing.tArray[0]);
  dm_ros_controller2_M->Timing.stepSize0 = 0.2;

  /* block I/O */
  (void) memset((static_cast<void *>(&dm_ros_controller2_B)), 0,
                sizeof(B_dm_ros_controller2_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&dm_ros_controller2_X), 0,
                  sizeof(X_dm_ros_controller2_T));
  }

  /* disabled states */
  {
    (void) memset(static_cast<void *>(&dm_ros_controller2_XDis), 0,
                  sizeof(XDis_dm_ros_controller2_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&dm_ros_controller2_DW), 0,
                sizeof(DW_dm_ros_controller2_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[11];
    char_T b_zeroDelimTopic_1[9];
    static const char_T b_zeroDelimTopic_2[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_3[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_4[9] = "/rel_vel";
    static const char_T b_zeroDelimTopic_5[11] = "/cmd_accel";

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    dm_ros_controller2_DW.obj_m.matlabCodegenIsDeleted = false;
    dm_ros_controller2_DW.objisempty_o = true;
    dm_ros_controller2_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_dm_ros_controller2_71.createSubscriber(&b_zeroDelimTopic[0], 1);
    dm_ros_controller2_DW.obj_m.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe2' */
    /* Start for MATLABSystem: '<S6>/SourceBlock' */
    dm_ros_controller2_DW.obj_l.matlabCodegenIsDeleted = false;
    dm_ros_controller2_DW.objisempty = true;
    dm_ros_controller2_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_dm_ros_controller2_72.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    dm_ros_controller2_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe2' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe1' */
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    dm_ros_controller2_DW.obj_e.matlabCodegenIsDeleted = false;
    dm_ros_controller2_DW.objisempty_f = true;
    dm_ros_controller2_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Sub_dm_ros_controller2_92.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    dm_ros_controller2_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe1' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    dm_ros_controller2_DW.obj.matlabCodegenIsDeleted = false;
    dm_ros_controller2_DW.objisempty_h = true;
    dm_ros_controller2_DW.obj.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_5[i];
    }

    Pub_dm_ros_controller2_70.createPublisher(&b_zeroDelimTopic_0[0], 1);
    dm_ros_controller2_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */
  }

  dm_ros_controller2_PrevZCX.TriggeredSubsystem1_Trig_ZCE = POS_ZCSIG;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  dm_ros_controller2_X.Integrator1_CSTATE = dm_ros_controller2_P.Integrator1_IC;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Triggered Subsystem1' */
  /* InitializeConditions for Memory: '<S7>/Memory' */
  dm_ros_controller2_DW.Memory_PreviousInput =
    dm_ros_controller2_P.Memory_InitialCondition;

  /* SystemInitialize for Sum: '<S7>/Sum' incorporates:
   *  Outport: '<S7>/Out1'
   */
  dm_ros_controller2_B.Sum = dm_ros_controller2_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Triggered Subsystem1' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  dm_ros_co_EnabledSubsystem_Init(&dm_ros_controller2_B.EnabledSubsystem,
    &dm_ros_controller2_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2' */
  /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  dm_ros_co_EnabledSubsystem_Init(&dm_ros_controller2_B.EnabledSubsystem_b,
    &dm_ros_controller2_P.EnabledSubsystem_b);

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe2' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  dm_ros_co_EnabledSubsystem_Init(&dm_ros_controller2_B.EnabledSubsystem_n,
    &dm_ros_controller2_P.EnabledSubsystem_n);

  /* End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe1' */
}

/* Model terminate function */
void dm_ros_controller2_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!dm_ros_controller2_DW.obj_m.matlabCodegenIsDeleted) {
    dm_ros_controller2_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe2' */
  /* Terminate for MATLABSystem: '<S6>/SourceBlock' */
  if (!dm_ros_controller2_DW.obj_l.matlabCodegenIsDeleted) {
    dm_ros_controller2_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe2' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe1' */
  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  if (!dm_ros_controller2_DW.obj_e.matlabCodegenIsDeleted) {
    dm_ros_controller2_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe1' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!dm_ros_controller2_DW.obj.matlabCodegenIsDeleted) {
    dm_ros_controller2_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
