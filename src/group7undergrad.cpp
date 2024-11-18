/*
 * group7undergrad.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "group7undergrad".
 *
 * Model version              : 1.60
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov 18 13:45:27 2024
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
#include <string.h>

/* Block signals (default storage) */
B_group7undergrad_T group7undergrad_B;

/* Block states (default storage) */
DW_group7undergrad_T group7undergrad_DW;

/* Real-time model */
RT_MODEL_group7undergrad_T group7undergrad_M_ = RT_MODEL_group7undergrad_T();
RT_MODEL_group7undergrad_T *const group7undergrad_M = &group7undergrad_M_;

/* Model step function */
void group7undergrad_step(void)
{
  SL_Bus_group7undergrad_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_group7undergrad_std_msgs_Float64 rtb_SourceBlock_o2_0;
  boolean_T b_varargout_1;

  /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
  /* MATLABSystem: '<S4>/SourceBlock' */
  b_varargout_1 = Sub_group7undergrad_67.getLatestMessage(&rtb_SourceBlock_o2_0);

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* Start for MATLABSystem: '<S4>/SourceBlock' */
  if (b_varargout_1) {
    /* SignalConversion generated from: '<S5>/In1' */
    group7undergrad_B.In1 = rtb_SourceBlock_o2_0;
  }

  /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of Outputs for SubSystem: '<Root>/Subscribe' */

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   *  DataStoreRead: '<Root>/Data Store Read2'
   */
  group7undergrad_DW.stop_light_distance -= group7undergrad_B.In1.Data * 0.01;
  if ((group7undergrad_DW.stop_light_distance <= 100.0) && (40.0 -
       group7undergrad_DW.sim_time > 0.0)) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = (group7undergrad_DW.stop_light_distance / (40.0 -
      group7undergrad_DW.sim_time) - group7undergrad_B.In1.Data) * 0.25;
  } else {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = (15.0 - group7undergrad_B.In1.Data) * 0.25;
  }

  if (group7undergrad_DW.stop_light_distance < 0.0) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = (15.0 - group7undergrad_B.In1.Data) * 0.25;
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
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[11];
    static const char_T b_zeroDelimTopic_1[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_2[11] = "/cmd_accel";

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    group7undergrad_DW.obj_p.matlabCodegenIsDeleted = false;
    group7undergrad_DW.objisempty = true;
    group7undergrad_DW.obj_p.isInitialized = 1;
    for (int32_T i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_group7undergrad_67.createSubscriber(&b_zeroDelimTopic[0], 1);
    group7undergrad_DW.obj_p.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S3>/SinkBlock' */
    group7undergrad_DW.obj.matlabCodegenIsDeleted = false;
    group7undergrad_DW.objisempty_i = true;
    group7undergrad_DW.obj.isInitialized = 1;
    for (int32_T i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Pub_group7undergrad_20.createPublisher(&b_zeroDelimTopic_0[0], 1);
    group7undergrad_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S3>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    group7undergrad_DW.sim_time = group7undergrad_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    group7undergrad_DW.stop_light_distance =
      group7undergrad_P.DataStoreMemory2_InitialValue;
  }

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S5>/In1' incorporates:
   *  Outport: '<S5>/Out1'
   */
  group7undergrad_B.In1 = group7undergrad_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */
}

/* Model terminate function */
void group7undergrad_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!group7undergrad_DW.obj_p.matlabCodegenIsDeleted) {
    group7undergrad_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */

  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S3>/SinkBlock' */
  if (!group7undergrad_DW.obj.matlabCodegenIsDeleted) {
    group7undergrad_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S3>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */
}
