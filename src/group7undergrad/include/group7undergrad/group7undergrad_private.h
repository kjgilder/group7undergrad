/*
 * group7undergrad_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "group7undergrad".
 *
 * Model version              : 1.49
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Mon Nov 18 12:50:26 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef group7undergrad_private_h_
#define group7undergrad_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "group7undergrad.h"
#include "group7undergrad_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

extern void group7und_EnabledSubsystem_Init(B_EnabledSubsystem_group7unde_T
  *localB, P_EnabledSubsystem_group7unde_T *localP);
extern void group7undergra_EnabledSubsystem(boolean_T rtu_Enable, const
  SL_Bus_group7undergrad_std_msgs_Float64 *rtu_In1,
  B_EnabledSubsystem_group7unde_T *localB);

#endif                                 /* group7undergrad_private_h_ */
