//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PixBlock3.h
//
// Code generated for Simulink model 'PixBlock3'.
//
// Model version                  : 4.25
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 26 14:55:21 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_PixBlock3_h_
#define RTW_HEADER_PixBlock3_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PX4_PWM.h"
#include "PixBlock3_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_PixBlock3_T {
  uint16_T pwmValue[8];
  real32_T siB_cmd[4];                 // '<S14>/Product'
  real_T u00Hz;                        // '<S1>/100 Hz'
};

// Block states (default storage) for system '<Root>'
struct DW_PixBlock3_T {
  px4_internal_block_PWM_PixBlock3_T obj;// '<S13>/PX4 PWM Output1'
  real_T DiscreteTimeIntegrator_PREV_U;// '<S12>/Discrete-Time Integrator'
  real32_T DiscreteTransferFcn1_states;// '<S3>/Discrete Transfer Fcn1'
  real32_T Delay_DSTATE;               // '<S21>/Delay'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S12>/Discrete-Time Integrator'
  real32_T Delay_DSTATE_l;             // '<S16>/Delay'
  int32_T clockTickCounter;            // '<S1>/100 Hz'
  uint32_T EmulatedPixhawk_PREV_T;     // '<S1>/Emulated Pixhawk'
  int8_T DiscreteTimeIntegrator_PrevResetState;// '<S12>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE;// '<S12>/Discrete-Time Integrator' 
  boolean_T EmulatedPixhawk_RESET_ELAPS_T;// '<S1>/Emulated Pixhawk'
};

// Zero-crossing (trigger) state
struct PrevZCX_PixBlock3_T {
  ZCSigState EmulatedPixhawk_Trig_ZCE; // '<S1>/Emulated Pixhawk'
};

// External inputs (root inport signals with default storage)
struct ExtU_PixBlock3_T {
  real32_T SerialIn[23];               // '<Root>/Serial In'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_PixBlock3_T {
  real32_T SerialOut[18];              // '<Root>/Serial Out'
};

// Parameters (default storage)
struct P_PixBlock3_T_ {
  real_T Constant_Value;               // Expression: 0
                                          //  Referenced by: '<S10>/Constant'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S12>/Discrete-Time Integrator'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S12>/Zero'

  real_T u00Hz_Amp;                    // Expression: 1
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Period;                 // Computed Parameter: u00Hz_Period
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Duty;                   // Computed Parameter: u00Hz_Duty
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_PhaseDelay;             // Expression: 0
                                          //  Referenced by: '<S1>/100 Hz'

  real32_T One9_Value;                 // Computed Parameter: One9_Value
                                          //  Referenced by: '<S22>/One9'

  real32_T One_Value;                  // Computed Parameter: One_Value
                                          //  Referenced by: '<S22>/One'

  real32_T One1_Value;                 // Computed Parameter: One1_Value
                                          //  Referenced by: '<S22>/One1'

  real32_T One2_Value;                 // Computed Parameter: One2_Value
                                          //  Referenced by: '<S22>/One2'

  real32_T One3_Value;                 // Computed Parameter: One3_Value
                                          //  Referenced by: '<S22>/One3'

  real32_T One4_Value;                 // Computed Parameter: One4_Value
                                          //  Referenced by: '<S22>/One4'

  real32_T One5_Value;                 // Computed Parameter: One5_Value
                                          //  Referenced by: '<S22>/One5'

  real32_T One6_Value;                 // Computed Parameter: One6_Value
                                          //  Referenced by: '<S22>/One6'

  real32_T One7_Value;                 // Computed Parameter: One7_Value
                                          //  Referenced by: '<S22>/One7'

  real32_T One8_Value;                 // Computed Parameter: One8_Value
                                          //  Referenced by: '<S22>/One8'

  real32_T SerialOut_Y0;               // Computed Parameter: SerialOut_Y0
                                          //  Referenced by: '<S2>/Serial Out'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S14>/Constant7'

  real32_T Switch_1_Threshold;         // Computed Parameter: Switch_1_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T Switch_2_Threshold;         // Computed Parameter: Switch_2_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T Switch_3_Threshold;         // Computed Parameter: Switch_3_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T Switch_6_Threshold;         // Computed Parameter: Switch_6_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S3>/Gain1'

  real32_T uDLookupTable3_tableData[30];
                                 // Computed Parameter: uDLookupTable3_tableData
                                    //  Referenced by: '<S15>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp01Data[3];
                                  // Computed Parameter: uDLookupTable3_bp01Data
                                     //  Referenced by: '<S15>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp02Data[10];
                                  // Computed Parameter: uDLookupTable3_bp02Data
                                     //  Referenced by: '<S15>/1-D Lookup Table3'

  real32_T Switch_7_Threshold;         // Computed Parameter: Switch_7_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T DiscreteTransferFcn1_NumCoef[2];
                             // Computed Parameter: DiscreteTransferFcn1_NumCoef
                                //  Referenced by: '<S3>/Discrete Transfer Fcn1'

  real32_T DiscreteTransferFcn1_DenCoef[2];
                             // Computed Parameter: DiscreteTransferFcn1_DenCoef
                                //  Referenced by: '<S3>/Discrete Transfer Fcn1'

  real32_T DiscreteTransferFcn1_InitialStates;
                       // Computed Parameter: DiscreteTransferFcn1_InitialStates
                          //  Referenced by: '<S3>/Discrete Transfer Fcn1'

  real32_T uDLookupTable5_tableData[30];
                                 // Computed Parameter: uDLookupTable5_tableData
                                    //  Referenced by: '<S15>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp01Data[3];
                                  // Computed Parameter: uDLookupTable5_bp01Data
                                     //  Referenced by: '<S15>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp02Data[10];
                                  // Computed Parameter: uDLookupTable5_bp02Data
                                     //  Referenced by: '<S15>/1-D Lookup Table5'

  real32_T Switch_10_Threshold;       // Computed Parameter: Switch_10_Threshold
                                         //  Referenced by: '<S7>/Switch'

  real32_T Delay_InitialCondition; // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S21>/Delay'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S12>/Constant'

  real32_T Switch_4_Threshold;         // Computed Parameter: Switch_4_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T Switch_5_Threshold;         // Computed Parameter: Switch_5_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T Switch_8_Threshold;         // Computed Parameter: Switch_8_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T Switch_9_Threshold;         // Computed Parameter: Switch_9_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T Zero_Value_a;               // Computed Parameter: Zero_Value_a
                                          //  Referenced by: '<S2>/Zero'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S17>/Gain'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S13>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S13>/Saturation'

  real32_T Gain_Gain_m;                // Computed Parameter: Gain_Gain_m
                                          //  Referenced by: '<S13>/Gain'

  real32_T One_Value_f;                // Computed Parameter: One_Value_f
                                          //  Referenced by: '<S13>/One'

  real32_T Delay_InitialCondition_f;
                                 // Computed Parameter: Delay_InitialCondition_f
                                    //  Referenced by: '<S16>/Delay'

  real32_T Gain_Gain_g;                // Computed Parameter: Gain_Gain_g
                                          //  Referenced by: '<S18>/Gain'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S13>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S13>/Saturation1'

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: '<S13>/Gain1'

  real32_T One1_Value_d;               // Computed Parameter: One1_Value_d
                                          //  Referenced by: '<S13>/One1'

  real32_T Gain_Gain_c;                // Computed Parameter: Gain_Gain_c
                                          //  Referenced by: '<S19>/Gain'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S13>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S13>/Saturation2'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S13>/Gain2'

  real32_T One2_Value_d;               // Computed Parameter: One2_Value_d
                                          //  Referenced by: '<S13>/One2'

  real32_T Gain_Gain_l;                // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S20>/Gain'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S13>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S13>/Saturation3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S13>/Gain3'

  real32_T One3_Value_b;               // Computed Parameter: One3_Value_b
                                          //  Referenced by: '<S13>/One3'

  real32_T uDLookupTable4_tableData[30];
                                 // Computed Parameter: uDLookupTable4_tableData
                                    //  Referenced by: '<S15>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp01Data[3];
                                  // Computed Parameter: uDLookupTable4_bp01Data
                                     //  Referenced by: '<S15>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp02Data[10];
                                  // Computed Parameter: uDLookupTable4_bp02Data
                                     //  Referenced by: '<S15>/1-D Lookup Table4'

  uint32_T uDLookupTable3_maxIndex[2];
                                  // Computed Parameter: uDLookupTable3_maxIndex
                                     //  Referenced by: '<S15>/1-D Lookup Table3'

  uint32_T uDLookupTable5_maxIndex[2];
                                  // Computed Parameter: uDLookupTable5_maxIndex
                                     //  Referenced by: '<S15>/1-D Lookup Table5'

  uint32_T uDLookupTable4_maxIndex[2];
                                  // Computed Parameter: uDLookupTable4_maxIndex
                                     //  Referenced by: '<S15>/1-D Lookup Table4'

  boolean_T One4_Value_p;              // Computed Parameter: One4_Value_p
                                          //  Referenced by: '<S13>/One4'

};

// Real-time Model Data Structure
struct tag_RTM_PixBlock3_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_PixBlock3_T PixBlock3_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_PixBlock3_T PixBlock3_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_PixBlock3_T PixBlock3_DW;

// Zero-crossing (trigger) state
extern PrevZCX_PixBlock3_T PixBlock3_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_PixBlock3_T PixBlock3_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_PixBlock3_T PixBlock3_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void PixBlock3_initialize(void);
  extern void PixBlock3_step(void);
  extern void PixBlock3_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_PixBlock3_T *const PixBlock3_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Constant' : Unused code path elimination
//  Block '<S3>/Constant1' : Unused code path elimination
//  Block '<S3>/Constant2' : Unused code path elimination
//  Block '<S3>/Constant3' : Unused code path elimination
//  Block '<S3>/Constant4' : Unused code path elimination
//  Block '<S3>/Constant5' : Unused code path elimination
//  Block '<S3>/Constant6' : Unused code path elimination
//  Block '<S3>/Constant7' : Unused code path elimination
//  Block '<S15>/1-D Lookup Table1' : Unused code path elimination
//  Block '<S15>/1-D Lookup Table2' : Unused code path elimination
//  Block '<S15>/1-D Lookup Table6' : Unused code path elimination
//  Block '<S22>/One10' : Unused code path elimination
//  Block '<S22>/One11' : Unused code path elimination
//  Block '<S14>/Cast To Single9' : Eliminate redundant data type conversion
//  Block '<S13>/Cast To Boolean' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Note that this particular code originates from a subsystem build,
//  and has its own system numbers different from the parent model.
//  Refer to the system hierarchy for this subsystem below, and use the
//  MATLAB hilite_system command to trace the generated code back
//  to the parent model.  For example,
//
//  hilite_system('PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3')    - opens subsystem PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3
//  hilite_system('PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC'
//  '<S1>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3'
//  '<S2>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk'
//  '<S3>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot'
//  '<S4>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Convert to Bus'
//  '<S5>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Convert to Vector'
//  '<S6>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/IMU - Merge'
//  '<S7>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Inertial Navigation System'
//  '<S8>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Real Gyro'
//  '<S9>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Calculate U1'
//  '<S10>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software'
//  '<S11>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Fin Allocation'
//  '<S12>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Phi_Control'
//  '<S13>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands'
//  '<S14>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Fin Allocation/control_allocation'
//  '<S15>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Phi_Control/Gain_Lookup'
//  '<S16>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/100Hz Progress'
//  '<S17>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/Radians to Degrees'
//  '<S18>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/Radians to Degrees1'
//  '<S19>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/Radians to Degrees2'
//  '<S20>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/Radians to Degrees3'
//  '<S21>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Convert to Bus/100Hz Reset'
//  '<S22>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/PixBlock3/Emulated Pixhawk/Inertial Navigation System/INS (INCOMPLETE)'

#endif                                 // RTW_HEADER_PixBlock3_h_

//
// File trailer for generated code.
//
// [EOF]
//
