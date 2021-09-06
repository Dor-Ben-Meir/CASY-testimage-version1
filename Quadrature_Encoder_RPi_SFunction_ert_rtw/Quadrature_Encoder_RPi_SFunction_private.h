/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quadrature_Encoder_RPi_SFunction_private.h
 *
 * Code generated for Simulink model 'Quadrature_Encoder_RPi_SFunction'.
 *
 * Model version                  : 1.103
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun May  2 14:34:44 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Quadrature_Encoder_RPi_SFunction_private_h_
#define RTW_HEADER_Quadrature_Encoder_RPi_SFunction_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Quad_Encoder_sfn_Start_wrapper(real_T *xD,
    const uint8_T *enc, const int_T p_width0,
    const uint8_T *pinA, const int_T p_width1,
    const uint8_T *pinB, const int_T p_width2);
  extern void Quad_Encoder_sfn_Outputs_wrapper(int16_T *pos,
    const real_T *xD,
    const uint8_T *enc, const int_T p_width0,
    const uint8_T *pinA, const int_T p_width1,
    const uint8_T *pinB, const int_T p_width2);
  extern void Quad_Encoder_sfn_Update_wrapper(int16_T *pos,
    real_T *xD,
    const uint8_T *enc, const int_T p_width0,
    const uint8_T *pinA, const int_T p_width1,
    const uint8_T *pinB, const int_T p_width2);
  extern void Quad_Encoder_sfn_Terminate_wrapper(real_T *xD,
    const uint8_T *enc, const int_T p_width0,
    const uint8_T *pinA, const int_T p_width1,
    const uint8_T *pinB, const int_T p_width2);

#ifdef __cplusplus

}
#endif
#endif              /* RTW_HEADER_Quadrature_Encoder_RPi_SFunction_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
