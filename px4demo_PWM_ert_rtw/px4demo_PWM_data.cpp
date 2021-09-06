//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_PWM_data.cpp
//
// Code generated for Simulink model 'px4demo_PWM'.
//
// Model version                  : 4.1
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  9 19:41:22 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4demo_PWM.h"
#include "px4demo_PWM_private.h"

// Block parameters (default storage)
P_px4demo_PWM_T px4demo_PWM_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S2>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // noutputs

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // output

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // noutputs

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // output

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: MAINPWMCh12value_Value
  //  Referenced by: '<Root>/MAIN PWM Ch 1,2 value'

  1200U,

  // Computed Parameter: AUXPWMCh1234value_Value
  //  Referenced by: '<Root>/AUX PWM Ch 1,2,3,4 value'

  1200U,

  // Computed Parameter: ARMPWM_Value
  //  Referenced by: '<Root>/ARM PWM'

  1,

  // Computed Parameter: failsafe_Value
  //  Referenced by: '<Root>/failsafe'

  0,

  // Computed Parameter: failsafe1_Value
  //  Referenced by: '<Root>/failsafe1'

  0
};

//
// File trailer for generated code.
//
// [EOF]
//
