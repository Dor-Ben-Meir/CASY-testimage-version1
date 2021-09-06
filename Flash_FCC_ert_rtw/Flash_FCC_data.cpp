//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flash_FCC_data.cpp
//
// Code generated for Simulink model 'Flash_FCC'.
//
// Model version                  : 1.411
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Feb 18 16:35:37 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Flash_FCC.h"
#include "Flash_FCC_private.h"

// Block parameters (default storage)
P_Flash_FCC_T Flash_FCC_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S23>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // integral_dt
    (0ULL),                            // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // range_rad_s
    0.0F,                              // scaling
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    0                                  // temperature_raw
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S22>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // integral_dt
    (0ULL),                            // error_count
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // range_rad_s
    0.0F,                              // scaling
    0U,                                // device_id
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw
    0                                  // temperature_raw
  },

  // Expression: 0.001
  //  Referenced by: '<S2>/Serial Receive'

  0.001,

  // Expression: 1
  //  Referenced by: '<Root>/Pulse Generator1'

  1.0,

  // Computed Parameter: PulseGenerator1_Period
  //  Referenced by: '<Root>/Pulse Generator1'

  2.0,

  // Computed Parameter: PulseGenerator1_Duty
  //  Referenced by: '<Root>/Pulse Generator1'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Pulse Generator1'

  0.0,

  // Computed Parameter: One8_Value
  //  Referenced by: '<S24>/One8'

  -1.0F,

  // Computed Parameter: One7_Value
  //  Referenced by: '<S24>/One7'

  -1.0F,

  // Computed Parameter: One6_Value
  //  Referenced by: '<S24>/One6'

  -1.0F,

  // Computed Parameter: One5_Value
  //  Referenced by: '<S24>/One5'

  -1.0F,

  // Computed Parameter: One4_Value
  //  Referenced by: '<S24>/One4'

  -1.0F,

  // Computed Parameter: One3_Value
  //  Referenced by: '<S24>/One3'

  -1.0F,

  // Computed Parameter: One2_Value
  //  Referenced by: '<S24>/One2'

  -1.0F,

  // Computed Parameter: One1_Value
  //  Referenced by: '<S24>/One1'

  -1.0F,

  // Computed Parameter: One9_Value
  //  Referenced by: '<S24>/One9'

  -1.0F,

  // Computed Parameter: One_Value
  //  Referenced by: '<S24>/One'

  -1.0F,

  // Computed Parameter: Switch_1_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Switch_2_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Switch_3_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Switch_10_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Delay_InitialCondition
  //  Referenced by: '<S3>/Delay'

  0.0F,

  // Computed Parameter: DiscreteTransferFcn_NumCoef
  //  Referenced by: '<S14>/Discrete Transfer Fcn'

  { 20.3646F, -20.335F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef
  //  Referenced by: '<S14>/Discrete Transfer Fcn'

  { 1.0F, -1.0F },

  // Computed Parameter: DiscreteTransferFcn_InitialStat
  //  Referenced by: '<S14>/Discrete Transfer Fcn'

  0.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S14>/Gain2'

  0.6F,

  // Computed Parameter: Switch_4_Threshold
  //  Referenced by: '<S12>/Switch'

  0.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S14>/Gain'

  0.01F,

  // Computed Parameter: Limit2maxDeflection_UpperSat
  //  Referenced by: '<S6>/Limit2maxDeflection'

  0.34906584F,

  // Computed Parameter: Limit2maxDeflection_LowerSat
  //  Referenced by: '<S6>/Limit2maxDeflection'

  -0.34906584F,

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S6>/Constant'

  -1.57079637F,

  // Computed Parameter: Zero_Value
  //  Referenced by: '<S4>/Zero'

  0.0F,

  // Computed Parameter: Constant1_Value
  //  Referenced by: '<S6>/Constant1'

  1.57079637F,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<S6>/Constant2'

  4.71238899F,

  // Computed Parameter: Constant3_Value
  //  Referenced by: '<S6>/Constant3'

  -4.71238899F,

  // Computed Parameter: Constant4_Value
  //  Referenced by: '<S6>/Constant4'

  0.34906584F,

  // Computed Parameter: Gain_Gain_c
  //  Referenced by: '<S27>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S11>/Saturation'

  20.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S11>/Saturation'

  -20.0F,

  // Computed Parameter: Gain_Gain_g
  //  Referenced by: '<S11>/Gain'

  10.9890108F,

  // Computed Parameter: One_Value_m
  //  Referenced by: '<S11>/One'

  1500.0F,

  // Computed Parameter: Delay_InitialCondition_h
  //  Referenced by: '<S26>/Delay'

  0.0F,

  // Computed Parameter: Gain_Gain_d
  //  Referenced by: '<S28>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S11>/Saturation1'

  20.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S11>/Saturation1'

  -20.0F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S11>/Gain1'

  10.9890108F,

  // Computed Parameter: One1_Value_e
  //  Referenced by: '<S11>/One1'

  1500.0F,

  // Computed Parameter: Gain_Gain_f
  //  Referenced by: '<S29>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S11>/Saturation2'

  20.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S11>/Saturation2'

  -20.0F,

  // Computed Parameter: Gain2_Gain_h
  //  Referenced by: '<S11>/Gain2'

  10.9890108F,

  // Computed Parameter: One2_Value_f
  //  Referenced by: '<S11>/One2'

  1500.0F,

  // Computed Parameter: Gain_Gain_o
  //  Referenced by: '<S30>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S11>/Saturation3'

  20.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S11>/Saturation3'

  -20.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S11>/Gain3'

  10.9890108F,

  // Computed Parameter: One3_Value_o
  //  Referenced by: '<S11>/One3'

  1500.0F,

  // Computed Parameter: Switch_4_Threshold_k
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Switch_5_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Switch_6_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Switch_7_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Switch_8_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Switch_9_Threshold
  //  Referenced by: '<S8>/Switch'

  0.0F,

  // Computed Parameter: Zero_Value_g
  //  Referenced by: '<S1>/Zero'

  0.0F,

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S31>/Out1'

  0.0F,

  // Computed Parameter: One4_Value_h
  //  Referenced by: '<S11>/One4'

  0,

  // Computed Parameter: Zero_Value_b
  //  Referenced by: '<S25>/Zero'

  { 5U, 5U, 5U },

  // Start of '<S14>/If Action Subsystem1'
  {
    // Computed Parameter: One_Value
    //  Referenced by: '<S16>/One'

    0.5F
  }
  ,

  // End of '<S14>/If Action Subsystem1'

  // Start of '<S14>/If Action Subsystem'
  {
    // Computed Parameter: One_Value
    //  Referenced by: '<S15>/One'

    1.0F
  }
  // End of '<S14>/If Action Subsystem'
};

//
// File trailer for generated code.
//
// [EOF]
//
