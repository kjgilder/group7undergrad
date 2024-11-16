/*
 * dm_ros_controller2_data.cpp
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

/* Block parameters (default storage) */
P_dm_ros_controller2_T dm_ros_controller2_P = {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S4>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S5>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S6>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S7>/Out1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 500
   * Referenced by: '<Root>/initial_space_to_int1'
   */
  500.0,

  /* Expression: 100
   * Referenced by: '<Root>/threshold_distance1'
   */
  100.0,

  /* Expression: 12
   * Referenced by: '<Root>/initial_time_to_green'
   */
  12.0,

  /* Start of '<S6>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S10>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  ,

  /* End of '<S6>/Enabled Subsystem' */

  /* Start of '<S5>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S9>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  ,

  /* End of '<S5>/Enabled Subsystem' */

  /* Start of '<S4>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S8>/Out1'
     */
    {
      0.0                              /* Data */
    }
  }
  /* End of '<S4>/Enabled Subsystem' */
};
