/*
 * Mainframe_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Mainframe".
 *
 * Model version              : 1.275
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Feb 18 00:43:29 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Mainframe_private_h_
#define RTW_HEADER_Mainframe_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "Mainframe.h"

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(const real_T u0[9], const real_T
  u1[3], real_T y[3]);
extern real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void Mainframe_EnabledSubsystem1_Init(B_EnabledSubsystem1_Mainframe_T
  *localB, P_EnabledSubsystem1_Mainframe_T *localP);
extern void Mainframe_EnabledSubsystem1(RT_MODEL_Mainframe_T * const Mainframe_M,
  boolean_T rtu_Trigger, B_EnabledSubsystem1_Mainframe_T *localB,
  DW_EnabledSubsystem1_Mainframe_T *localDW, ZCE_EnabledSubsystem1_Mainframe_T
  *localZCE);
extern void Mainframe_Limiting_Acceleration(real_T rtu_siB, real_T rtu_d_siB,
  real_T rtu_dd_siB, B_Limiting_Acceleration_Mainframe_T *localB, real_T
  rtp_d_siB_max, real_T rtp_d_siB_min, real_T rtp_dd_siB_max, real_T
  rtp_dd_siB_min, real_T rtp_siB_max, real_T rtp_siB_min);
extern void Mainframe_Limiting_Rate(real_T rtu_siB, real_T rtu_d_siB,
  B_Limiting_Rate_Mainframe_T *localB, real_T rtp_d_siB_max, real_T
  rtp_d_siB_min, real_T rtp_siB_max, real_T rtp_siB_min);

/* private model entry point functions */
extern void Mainframe_derivatives(void);

#endif                                 /* RTW_HEADER_Mainframe_private_h_ */
