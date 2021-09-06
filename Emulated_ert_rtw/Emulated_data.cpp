//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Emulated_data.cpp
//
// Code generated for Simulink model 'Emulated'.
//
// Model version                  : 4.48
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon May 10 17:26:16 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Emulated.h"
#include "Emulated_private.h"

// Block parameters (default storage)
P_Emulated_T Emulated_P = {
  // Variable: Flight_Logic
  //  Referenced by:
  //    '<S20>/Constant'
  //    '<S22>/Constant'
  //    '<S23>/Constant'
  //    '<S28>/Constant'
  //    '<S31>/Constant'
  //    '<S33>/Constant'
  //    '<S36>/Constant'
  //    '<S37>/Constant'

  {
    40.0,
    0.3,
    0.3,
    0.5,
    0.5,
    999.0,
    999.0,
    999.0,
    0.0
  },

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S27>/Constant'

  40.0F,

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S32>/Constant'

  0.0F,

  // Mask Parameter: CompareToConstant_const_g
  //  Referenced by: '<S21>/Constant'

  0.0F,

  // Mask Parameter: DetectDecrease_vinit
  //  Referenced by: '<S24>/Delay Input1'

  0.0F,

  // Computed Parameter: FinDeflections_Y0
  //  Referenced by: '<S2>/Fin Deflections'

  {
    0.0F,                              // Fin_1_Cmd_rad
    0.0F,                              // Fin_2_Cmd_rad
    0.0F,                              // Fin_3_Cmd_rad
    0.0F                               // Fin_4_Cmd_rad
  },

  // Computed Parameter: FinCmd_Y0
  //  Referenced by: '<S2>/Fin Cmd'

  {
    0.0F,                              // Fin_1_Cmd_rad
    0.0F,                              // Fin_2_Cmd_rad
    0.0F,                              // Fin_3_Cmd_rad
    0.0F                               // Fin_4_Cmd_rad
  },

  // Expression: 600
  //  Referenced by: '<S17>/Constant4'

  600.0,

  // Expression: 500
  //  Referenced by: '<S17>/Constant6'

  500.0,

  // Expression: 400
  //  Referenced by: '<S17>/Constant3'

  400.0,

  // Expression: 300
  //  Referenced by: '<S17>/Constant2'

  300.0,

  // Expression: 200
  //  Referenced by: '<S17>/Constant1'

  200.0,

  // Expression: 1
  //  Referenced by: '<S17>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S12>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S17>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S18>/Constant'

  0.0,

  // Computed Parameter: flight_mode_enum_Y0
  //  Referenced by: '<S2>/flight_mode_enum'

  0.0,

  // Expression: 0
  //  Referenced by: '<S25>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S25>/Discrete-Time Integrator'

  0.001,

  // Expression: 0
  //  Referenced by: '<S29>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval_l
  //  Referenced by: '<S29>/Discrete-Time Integrator'

  0.001,

  // Expression: 0
  //  Referenced by: '<S34>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval_k
  //  Referenced by: '<S34>/Discrete-Time Integrator'

  0.001,

  // Expression: 0
  //  Referenced by: '<S38>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval_o
  //  Referenced by: '<S38>/Discrete-Time Integrator'

  0.001,

  // Expression: 1
  //  Referenced by: '<S25>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S29>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S34>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S38>/Constant'

  1.0,

  // Expression: 2000
  //  Referenced by: '<S8>/One5'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S8>/One6'

  1000.0,

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

  // Expression: HIL_Data.FDM.Tr4r3
  //  Referenced by: '<S15>/Constant7'

  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F },

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S2>/Gain1'

  -1.0F,

  // Computed Parameter: uDLookupTable3_tableData
  //  Referenced by: '<S40>/1-D Lookup Table3'

  { 0.30841F, 0.24701F, 0.22655F, 0.067F, 0.072F, 0.075925F, 0.028F, 0.02989F,
    0.03232F, 0.0165F, 0.0174F, 0.01828F, 0.0113F, 0.0118F, 0.01216F, 0.0085F,
    0.008722F, 0.009118F, 0.0068F, 0.007003F, 0.00721F, 0.00568F, 0.005806F,
    0.005986F, 0.00486F, 0.004951F, 0.005104F, 0.00422F, 0.004303F, 0.004456F },

  // Computed Parameter: uDLookupTable3_bp01Data
  //  Referenced by: '<S40>/1-D Lookup Table3'

  { 10.0F, 1000.0F, 2000.0F },

  // Computed Parameter: uDLookupTable3_bp02Data
  //  Referenced by: '<S40>/1-D Lookup Table3'

  { 20.0F, 50.0F, 80.0F, 110.0F, 140.0F, 170.0F, 200.0F, 230.0F, 260.0F, 290.0F
  },

  // Computed Parameter: uDLookupTable5_tableData
  //  Referenced by: '<S40>/1-D Lookup Table5'

  { 3.358F, 2.989F, 3.079F, 3.817F, 3.691F, 3.574F, 4.456F, 4.4F, 4.096F, 4.609F,
    4.609F, 4.609F, 5.14F, 4.951F, 5.014F, 5.32F, 5.32F, 5.284F, 5.626F, 5.437F,
    5.374F, 5.716F, 5.68F, 5.437F, 5.869F, 5.833F, 5.527F, 6.14F, 6.022F, 5.473F
  },

  // Computed Parameter: uDLookupTable5_bp01Data
  //  Referenced by: '<S40>/1-D Lookup Table5'

  { 10.0F, 1000.0F, 2000.0F },

  // Computed Parameter: uDLookupTable5_bp02Data
  //  Referenced by: '<S40>/1-D Lookup Table5'

  { 20.0F, 50.0F, 80.0F, 110.0F, 140.0F, 170.0F, 200.0F, 230.0F, 260.0F, 290.0F
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S14>/Constant'

  0.0F,

  // Computed Parameter: DiscreteTimeIntegrator_gainval_m
  //  Referenced by: '<S14>/Discrete-Time Integrator'

  0.001F,

  // Computed Parameter: DiscreteTransferFcn3_NumCoef
  //  Referenced by: '<S13>/Discrete Transfer Fcn3'

  { 0.385869533F, 0.385869533F },

  // Computed Parameter: DiscreteTransferFcn3_DenCoef
  //  Referenced by: '<S13>/Discrete Transfer Fcn3'

  { 1.0F, -0.228260905F },

  // Computed Parameter: DiscreteTransferFcn3_InitialStates
  //  Referenced by: '<S13>/Discrete Transfer Fcn3'

  0.0F,

  // Computed Parameter: Zero_Value
  //  Referenced by: '<S14>/Zero'

  0.0F,

  // Computed Parameter: uDLookupTable4_tableData
  //  Referenced by: '<S40>/1-D Lookup Table4'

  { 0.7945F, 1.279F, 1.126F, 1.369F, 1.432F, 1.432F, 1.549F, 1.792F, 1.675F,
    2.1493F, 1.981F, 1.765F, 2.1493F, 2.071F, 1.855F, 2.251F, 2.134F, 2.0F,
    2.314F, 2.224F, 2.224F, 2.35F, 2.287F, 2.458F, 2.35F, 2.3F, 2.62F, 2.35F,
    2.404F, 2.836F },

  // Computed Parameter: uDLookupTable4_bp01Data
  //  Referenced by: '<S40>/1-D Lookup Table4'

  { 10.0F, 1000.0F, 2000.0F },

  // Computed Parameter: uDLookupTable4_bp02Data
  //  Referenced by: '<S40>/1-D Lookup Table4'

  { 20.0F, 50.0F, 80.0F, 110.0F, 140.0F, 170.0F, 200.0F, 230.0F, 260.0F, 290.0F
  },

  // Computed Parameter: DiscreteTransferFcn_NumCoef
  //  Referenced by: '<S13>/Discrete Transfer Fcn'

  { 0.385869533F, 0.385869533F },

  // Computed Parameter: DiscreteTransferFcn_DenCoef
  //  Referenced by: '<S13>/Discrete Transfer Fcn'

  { 1.0F, -0.228260905F },

  // Computed Parameter: DiscreteTransferFcn_InitialStates
  //  Referenced by: '<S13>/Discrete Transfer Fcn'

  0.0F,

  // Computed Parameter: One9_Value
  //  Referenced by: '<S42>/One9'

  -1.0F,

  // Computed Parameter: One_Value
  //  Referenced by: '<S42>/One'

  -1.0F,

  // Computed Parameter: One1_Value
  //  Referenced by: '<S42>/One1'

  -1.0F,

  // Computed Parameter: One2_Value
  //  Referenced by: '<S42>/One2'

  -1.0F,

  // Computed Parameter: One3_Value
  //  Referenced by: '<S42>/One3'

  -1.0F,

  // Computed Parameter: One4_Value
  //  Referenced by: '<S42>/One4'

  -1.0F,

  // Computed Parameter: One5_Value_o
  //  Referenced by: '<S42>/One5'

  -1.0F,

  // Computed Parameter: One6_Value_c
  //  Referenced by: '<S42>/One6'

  -1.0F,

  // Computed Parameter: One7_Value
  //  Referenced by: '<S42>/One7'

  -1.0F,

  // Computed Parameter: One8_Value
  //  Referenced by: '<S42>/One8'

  -1.0F,

  // Computed Parameter: Switch_1_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_2_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_3_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_4_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_5_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_6_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_7_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_8_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_9_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Switch_10_Threshold
  //  Referenced by: '<S6>/Switch'

  0.0F,

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S44>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation_UpperSat
  //  Referenced by: '<S8>/Saturation'

  20.0F,

  // Computed Parameter: Saturation_LowerSat
  //  Referenced by: '<S8>/Saturation'

  -20.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S8>/Gain'

  10.9890108F,

  // Computed Parameter: One_Value_a
  //  Referenced by: '<S8>/One'

  900.0F,

  // Computed Parameter: Gain_Gain_m
  //  Referenced by: '<S45>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation1_UpperSat
  //  Referenced by: '<S8>/Saturation1'

  20.0F,

  // Computed Parameter: Saturation1_LowerSat
  //  Referenced by: '<S8>/Saturation1'

  -20.0F,

  // Computed Parameter: Gain1_Gain_l
  //  Referenced by: '<S8>/Gain1'

  10.9890108F,

  // Computed Parameter: One1_Value_b
  //  Referenced by: '<S8>/One1'

  900.0F,

  // Computed Parameter: Gain_Gain_l
  //  Referenced by: '<S46>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation2_UpperSat
  //  Referenced by: '<S8>/Saturation2'

  20.0F,

  // Computed Parameter: Saturation2_LowerSat
  //  Referenced by: '<S8>/Saturation2'

  -20.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S8>/Gain2'

  10.9890108F,

  // Computed Parameter: One2_Value_o
  //  Referenced by: '<S8>/One2'

  900.0F,

  // Computed Parameter: Gain_Gain_p
  //  Referenced by: '<S47>/Gain'

  57.2957802F,

  // Computed Parameter: Saturation3_UpperSat
  //  Referenced by: '<S8>/Saturation3'

  20.0F,

  // Computed Parameter: Saturation3_LowerSat
  //  Referenced by: '<S8>/Saturation3'

  -20.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S8>/Gain3'

  10.9890108F,

  // Computed Parameter: One3_Value_p
  //  Referenced by: '<S8>/One3'

  900.0F,

  // Computed Parameter: Zero_Value_a
  //  Referenced by: '<S1>/Zero'

  0.0F,

  // Computed Parameter: uDLookupTable3_maxIndex
  //  Referenced by: '<S40>/1-D Lookup Table3'

  { 2U, 9U },

  // Computed Parameter: uDLookupTable5_maxIndex
  //  Referenced by: '<S40>/1-D Lookup Table5'

  { 2U, 9U },

  // Computed Parameter: uDLookupTable4_maxIndex
  //  Referenced by: '<S40>/1-D Lookup Table4'

  { 2U, 9U },

  // Computed Parameter: Recovery_Y0
  //  Referenced by: '<S2>/Recovery'

  0,

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S10>/Constant'

  1,

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S18>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_f
  //  Referenced by: '<S30>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_p
  //  Referenced by: '<S35>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_n
  //  Referenced by: '<S26>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_m
  //  Referenced by: '<S39>/Memory'

  0,

  // Computed Parameter: One7_Value_m
  //  Referenced by: '<S8>/One7'

  1,

  // Computed Parameter: One4_Value_n
  //  Referenced by: '<S8>/One4'

  0
};

//
// File trailer for generated code.
//
// [EOF]
//
