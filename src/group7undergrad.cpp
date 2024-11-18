/*
 * group7undergrad.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "group7undergrad".
 *
 * Model version              : 1.46
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov 18 11:46:12 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "group7undergrad.h"
#include "rtwtypes.h"
#include "group7undergrad_types.h"
#include "group7undergrad_private.h"
#include <string.h>

/* Block signals (default storage) */
B_group7undergrad_T group7undergrad_B;

/* Block states (default storage) */
DW_group7undergrad_T group7undergrad_DW;

/* Real-time model */
RT_MODEL_group7undergrad_T group7undergrad_M_ = RT_MODEL_group7undergrad_T();
RT_MODEL_group7undergrad_T *const group7undergrad_M = &group7undergrad_M_;

/*
 * System initialize for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 *    '<S6>/Enabled Subsystem'
 */
void group7und_EnabledSubsystem_Init(B_EnabledSubsystem_group7unde_T *localB,
  P_EnabledSubsystem_group7unde_T *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
   *  Outport: '<S7>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S4>/Enabled Subsystem'
 *    '<S5>/Enabled Subsystem'
 *    '<S6>/Enabled Subsystem'
 */
void group7undergra_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_group7undergrad_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_group7unde_T *localB)
{
  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S7>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
}

/* Model step function */
void group7undergrad_step(void)
{
  SL_Bus_group7undergrad_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_group7undergrad_std_msgs_Float64 tmp;
  real_T rtb_Switch;
  boolean_T b_varargout_1;

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe_dist' */
  /* MATLABSystem: '<S4>/SourceBlock' */
  b_varargout_1 = Sub_group7undergrad_16.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S4>/SourceBlock' */
  group7undergra_EnabledSubsystem(b_varargout_1, &tmp,
    &group7undergrad_B.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe_dist' */

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe_vel_x' */
  /* MATLABSystem: '<S6>/SourceBlock' */
  b_varargout_1 = Sub_group7undergrad_13.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S6>/SourceBlock' */
  group7undergra_EnabledSubsystem(b_varargout_1, &tmp,
    &group7undergrad_B.EnabledSubsystem_a);

  /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe_vel_x' */

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (group7undergrad_B.EnabledSubsystem_a.In1.Data >
      group7undergrad_P.Switch_Threshold) {
    rtb_Switch = group7undergrad_B.EnabledSubsystem.In1.Data;
  } else {
    rtb_Switch = group7undergrad_P.Constant_Value_b;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe_rel_vel' */
  /* MATLABSystem: '<S5>/SourceBlock' */
  b_varargout_1 = Sub_group7undergrad_14.getLatestMessage(&tmp);

  /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S5>/SourceBlock' */
  group7undergra_EnabledSubsystem(b_varargout_1, &tmp,
    &group7undergrad_B.EnabledSubsystem_d);

  /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe_rel_vel' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   *  DataStoreRead: '<Root>/Data Store Read2'
   */
  group7undergrad_DW.stop_light_distance -= rtb_Switch * 0.01;
  if ((group7undergrad_DW.stop_light_distance <= 100.0) && (25.0 -
       group7undergrad_DW.sim_time > 0.0)) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = (group7undergrad_DW.stop_light_distance / (25.0 -
      group7undergrad_DW.sim_time) - rtb_Switch) * 0.25;
  } else {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = (group7undergrad_B.EnabledSubsystem.In1.Data /
      rtb_Switch - 2.0) * 0.25 + group7undergrad_B.EnabledSubsystem_d.In1.Data;
  }

  if (group7undergrad_DW.stop_light_distance < 0.0) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = 0.0;
  }

  if (group7undergrad_B.EnabledSubsystem.In1.Data < 0.0) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = 0.0;
  }

  /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   */
  group7undergrad_DW.sim_time += 0.01;

  /* Outputs for Atomic SubSystem: '<Root>/Publish' */
  /* MATLABSystem: '<S3>/SinkBlock' */
  Pub_group7undergrad_20.publish(&rtb_BusAssignment);

  /* End of Outputs for SubSystem: '<Root>/Publish' */
}

/* Model initialize function */
void group7undergrad_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset((static_cast<void *>(&group7undergrad_B)), 0,
                sizeof(B_group7undergrad_T));

  /* states (dwork) */
  (void) memset(static_cast<void *>(&group7undergrad_DW), 0,
                sizeof(DW_group7undergrad_T));

  {
    char_T b_zeroDelimTopic_0[17];
    char_T b_zeroDelimTopic[11];
    char_T b_zeroDelimTopic_1[9];
    static const char_T b_zeroDelimTopic_2[11] = "/lead_dist";
    static const char_T b_zeroDelimTopic_3[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_4[9] = "/rel_vel";
    static const char_T b_zeroDelimTopic_5[11] = "/cmd_accel";

    /* Start for Atomic SubSystem: '<Root>/Subscribe_dist' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    group7undergrad_DW.obj_pp.matlabCodegenIsDeleted = false;
    group7undergrad_DW.objisempty_o = true;
    group7undergrad_DW.obj_pp.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_group7undergrad_16.createSubscriber(&b_zeroDelimTopic[0], 1);
    group7undergrad_DW.obj_pp.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe_dist' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe_vel_x' */
    /* Start for MATLABSystem: '<S6>/SourceBlock' */
    group7undergrad_DW.obj_l.matlabCodegenIsDeleted = false;
    group7undergrad_DW.objisempty = true;
    group7undergrad_DW.obj_l.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_group7undergrad_13.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    group7undergrad_DW.obj_l.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S6>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe_vel_x' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe_rel_vel' */
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    group7undergrad_DW.obj_p.matlabCodegenIsDeleted = false;
    group7undergrad_DW.objisempty_d = true;
    group7undergrad_DW.obj_p.isInitialized = 1;
    for (int32_T i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Sub_group7undergrad_14.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    group7undergrad_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe_rel_vel' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    group7undergrad_DW.obj.matlabCodegenIsDeleted = false;
    group7undergrad_DW.objisempty_i = true;
    group7undergrad_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_5[i];
    }

    Pub_group7undergrad_20.createPublisher(&b_zeroDelimTopic[0], 1);
    group7undergrad_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    group7undergrad_DW.sim_time = group7undergrad_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    group7undergrad_DW.stop_light_distance =
      group7undergrad_P.DataStoreMemory2_InitialValue;
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe_dist' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  group7und_EnabledSubsystem_Init(&group7undergrad_B.EnabledSubsystem,
    &group7undergrad_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe_dist' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe_vel_x' */
  /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  group7und_EnabledSubsystem_Init(&group7undergrad_B.EnabledSubsystem_a,
    &group7undergrad_P.EnabledSubsystem_a);

  /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe_vel_x' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe_rel_vel' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  group7und_EnabledSubsystem_Init(&group7undergrad_B.EnabledSubsystem_d,
    &group7undergrad_P.EnabledSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe_rel_vel' */
}

/* Model terminate function */
void group7undergrad_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe_dist' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!group7undergrad_DW.obj_pp.matlabCodegenIsDeleted) {
    group7undergrad_DW.obj_pp.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe_dist' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe_vel_x' */
  /* Terminate for MATLABSystem: '<S6>/SourceBlock' */
  if (!group7undergrad_DW.obj_l.matlabCodegenIsDeleted) {
    group7undergrad_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S6>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe_vel_x' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe_rel_vel' */
  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  if (!group7undergrad_DW.obj_p.matlabCodegenIsDeleted) {
    group7undergrad_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe_rel_vel' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!group7undergrad_DW.obj.matlabCodegenIsDeleted) {
    group7undergrad_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
