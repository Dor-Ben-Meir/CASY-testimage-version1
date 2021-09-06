//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PwmBox_data.cpp
//
// Code generated for Simulink model 'PwmBox'.
//
// Model version                  : 4.49
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon May 10 16:59:57 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PwmBox.h"
#include "PwmBox_private.h"

// Block parameters (default storage)
P_PwmBox_T PwmBox_P = {
  // Expression: 0
  //  Referenced by: '<S3>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Constant1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S1>/100 Hz'

  1.0,

  // Computed Parameter: u00Hz_Period
  //  Referenced by: '<S1>/100 Hz'

  10.0,

  // Computed Parameter: u00Hz_Duty
  //  Referenced by: '<S1>/100 Hz'

  5.0,

  // Expression: 0
  //  Referenced by: '<S1>/100 Hz'

  0.0,

  // Computed Parameter: PWM_Y0
  //  Referenced by: '<S2>/PWM'

  {
    0U,                                // signal1
    0U,                                // signal2
    0U,                                // signal3
    0U                                 // signal4
  },

  // Expression: HIL_Data.FDM.Tr4r3
  //  Referenced by: '<S5>/Constant7'

  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F },

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S6>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S4>/Saturation'

  20.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S4>/Saturation'

  -20.0F,

  // Computed Parameter: Gain_Gain_g
  //  Referenced by: '<S4>/Gain'

  10.9890108F,

  // Computed Parameter: One_Value
  //  Referenced by: '<S4>/One'

  900.0F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S7>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S4>/Saturation1'

  20.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S4>/Saturation1'

  -20.0F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S4>/Gain1'

  10.9890108F,

  // Computed Parameter: One1_Value
  //  Referenced by: '<S4>/One1'

  900.0F,

  // Computed Parameter: Gain_Gain_j
  //  Referenced by: '<S8>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S4>/Saturation2'

  20.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S4>/Saturation2'

  -20.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S4>/Gain2'

  10.9890108F,

  // Computed Parameter: One2_Value
  //  Referenced by: '<S4>/One2'

  900.0F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: '<S9>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S4>/Saturation3'

  20.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S4>/Saturation3'

  -20.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S4>/Gain3'

  10.9890108F,

  // Computed Parameter: One3_Value
  //  Referenced by: '<S4>/One3'

  900.0F,

  // Computed Parameter: One7_Value
  //  Referenced by: '<S4>/One7'

  1,

  // Computed Parameter: One4_Value
  //  Referenced by: '<S4>/One4'

  0
};

//
// File trailer for generated code.
//
// [EOF]
//
