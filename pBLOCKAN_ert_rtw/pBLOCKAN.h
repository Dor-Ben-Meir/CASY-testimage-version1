//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pBLOCKAN.h
//
// Code generated for Simulink model 'pBLOCKAN'.
//
// Model version                  : 4.44
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sat May  1 20:14:09 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_pBLOCKAN_h_
#define RTW_HEADER_pBLOCKAN_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PX4_PWM.h"
#include "pBLOCKAN_types.h"
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
struct B_pBLOCKAN_T {
  real32_T csumrev[9];
  uint16_T pwmValue[8];
  real32_T siB_cmd[4];                 // '<S16>/Product'
  real_T u00Hz;                        // '<S1>/100 Hz'
  real32_T u;                          // '<S7>/Switch'
  ZCEventType zcEvent;
};

// Block states (default storage) for system '<Root>'
struct DW_pBLOCKAN_T {
  dsp_simulink_MovingAverage_pBLOCKAN_T obj;// '<S17>/Moving Average1'
  px4_internal_block_PWM_pBLOCKAN_T obj_j;// '<S15>/PX4 PWM Output1'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S30>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_p;// '<S35>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_c;// '<S26>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_o;// '<S39>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U;// '<S30>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_a;// '<S35>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_j;// '<S26>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_m;// '<S39>/Discrete-Time Integrator'
  real32_T Delay_DSTATE;               // '<S47>/Delay'
  real32_T DiscreteTimeIntegrator_DSTATE_n;// '<S14>/Discrete-Time Integrator'
  real32_T DiscreteTransferFcn3_states;// '<S13>/Discrete Transfer Fcn3'
  real32_T Delay_DSTATE_l;             // '<S42>/Delay'
  real32_T DiscreteTransferFcn_states; // '<S13>/Discrete Transfer Fcn'
  real32_T DelayInput1_DSTATE;         // '<S25>/Delay Input1'
  real32_T DiscreteTimeIntegrator_PREV_U_jd;// '<S14>/Discrete-Time Integrator'
  int32_T clockTickCounter;            // '<S1>/100 Hz'
  uint32_T EmulatedPixhawk_PREV_T;     // '<S1>/Emulated Pixhawk'
  int8_T DiscreteTimeIntegrator_PrevResetState;// '<S14>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_i;// '<S30>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_iw;// '<S35>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_j;// '<S26>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_ii;// '<S39>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE;// '<S14>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE_e;// '<S30>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE_d;// '<S35>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE_h;// '<S26>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE_ec;// '<S39>/Discrete-Time Integrator' 
  boolean_T EmulatedPixhawk_RESET_ELAPS_T;// '<S1>/Emulated Pixhawk'
  boolean_T Memory_PreviousInput;      // '<S19>/Memory'
  boolean_T Memory_PreviousInput_f;    // '<S31>/Memory'
  boolean_T Memory_PreviousInput_l;    // '<S36>/Memory'
  boolean_T Memory_PreviousInput_e;    // '<S27>/Memory'
  boolean_T Memory_PreviousInput_p;    // '<S40>/Memory'
};

// Zero-crossing (trigger) state
struct PrevZCX_pBLOCKAN_T {
  ZCSigState EmulatedPixhawk_Trig_ZCE; // '<S1>/Emulated Pixhawk'
};

// External inputs (root inport signals with default storage)
struct ExtU_pBLOCKAN_T {
  real32_T SerialIn[23];               // '<Root>/Serial In'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_pBLOCKAN_T {
  real32_T SerialOut[18];              // '<Root>/Serial Out'
  real_T flight_mode_enum;             // '<Root>/flight_mode_enum'
};

// Parameters (default storage)
struct P_pBLOCKAN_T_ {
  struct_KbuHZdFirwgp0Ajtitq2dC Flight_Logic;// Variable: Flight_Logic
                                                //  Referenced by:
                                                //    '<S21>/Constant'
                                                //    '<S23>/Constant'
                                                //    '<S24>/Constant'
                                                //    '<S29>/Constant'
                                                //    '<S32>/Constant'
                                                //    '<S34>/Constant'
                                                //    '<S37>/Constant'
                                                //    '<S38>/Constant'

  real32_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S28>/Constant'

  real32_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S33>/Constant'

  real32_T CompareToConstant_const_g;
                                    // Mask Parameter: CompareToConstant_const_g
                                       //  Referenced by: '<S22>/Constant'

  real32_T DetectDecrease_vinit;       // Mask Parameter: DetectDecrease_vinit
                                          //  Referenced by: '<S25>/Delay Input1'

  real_T Constant4_Value;              // Expression: 600
                                          //  Referenced by: '<S18>/Constant4'

  real_T Constant6_Value;              // Expression: 500
                                          //  Referenced by: '<S18>/Constant6'

  real_T Constant3_Value;              // Expression: 400
                                          //  Referenced by: '<S18>/Constant3'

  real_T Constant2_Value;              // Expression: 300
                                          //  Referenced by: '<S18>/Constant2'

  real_T Constant1_Value;              // Expression: 200
                                          //  Referenced by: '<S18>/Constant1'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S18>/Constant'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S12>/Constant5'

  real_T Constant5_Value_k;            // Expression: 0
                                          //  Referenced by: '<S18>/Constant5'

  real_T Constant_Value_l;             // Expression: 0
                                          //  Referenced by: '<S19>/Constant'

  real_T One5_Value;                   // Expression: 2000
                                          //  Referenced by: '<S15>/One5'

  real_T One6_Value;                   // Expression: 1000
                                          //  Referenced by: '<S15>/One6'

  real_T flight_mode_enum_Y0;         // Computed Parameter: flight_mode_enum_Y0
                                         //  Referenced by: '<S2>/flight_mode_enum'

  real_T Constant1_Value_m;            // Expression: 0
                                          //  Referenced by: '<S30>/Constant1'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S30>/Discrete-Time Integrator'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S35>/Constant1'

  real_T DiscreteTimeIntegrator_gainval_k;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_k
                            //  Referenced by: '<S35>/Discrete-Time Integrator'

  real_T Constant1_Value_g;            // Expression: 0
                                          //  Referenced by: '<S26>/Constant1'

  real_T DiscreteTimeIntegrator_gainval_b;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_b
                            //  Referenced by: '<S26>/Discrete-Time Integrator'

  real_T Constant1_Value_e;            // Expression: 0
                                          //  Referenced by: '<S39>/Constant1'

  real_T DiscreteTimeIntegrator_gainval_o;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_o
                            //  Referenced by: '<S39>/Discrete-Time Integrator'

  real_T Constant_Value_a;             // Expression: 1
                                          //  Referenced by: '<S26>/Constant'

  real_T Constant_Value_lo;            // Expression: 1
                                          //  Referenced by: '<S30>/Constant'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<S35>/Constant'

  real_T Constant_Value_bq;            // Expression: 1
                                          //  Referenced by: '<S39>/Constant'

  real_T u00Hz_Amp;                    // Expression: 1
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Period;                 // Computed Parameter: u00Hz_Period
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Duty;                   // Computed Parameter: u00Hz_Duty
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_PhaseDelay;             // Expression: 0
                                          //  Referenced by: '<S1>/100 Hz'

  real32_T One9_Value;                 // Computed Parameter: One9_Value
                                          //  Referenced by: '<S48>/One9'

  real32_T One_Value;                  // Computed Parameter: One_Value
                                          //  Referenced by: '<S48>/One'

  real32_T One1_Value;                 // Computed Parameter: One1_Value
                                          //  Referenced by: '<S48>/One1'

  real32_T One2_Value;                 // Computed Parameter: One2_Value
                                          //  Referenced by: '<S48>/One2'

  real32_T One3_Value;                 // Computed Parameter: One3_Value
                                          //  Referenced by: '<S48>/One3'

  real32_T One4_Value;                 // Computed Parameter: One4_Value
                                          //  Referenced by: '<S48>/One4'

  real32_T One5_Value_o;               // Computed Parameter: One5_Value_o
                                          //  Referenced by: '<S48>/One5'

  real32_T One6_Value_c;               // Computed Parameter: One6_Value_c
                                          //  Referenced by: '<S48>/One6'

  real32_T One7_Value;                 // Computed Parameter: One7_Value
                                          //  Referenced by: '<S48>/One7'

  real32_T One8_Value;                 // Computed Parameter: One8_Value
                                          //  Referenced by: '<S48>/One8'

  real32_T SerialOut_Y0;               // Computed Parameter: SerialOut_Y0
                                          //  Referenced by: '<S2>/Serial Out'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S16>/Constant7'

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
                                    //  Referenced by: '<S41>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp01Data[3];
                                  // Computed Parameter: uDLookupTable3_bp01Data
                                     //  Referenced by: '<S41>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp02Data[10];
                                  // Computed Parameter: uDLookupTable3_bp02Data
                                     //  Referenced by: '<S41>/1-D Lookup Table3'

  real32_T uDLookupTable5_tableData[30];
                                 // Computed Parameter: uDLookupTable5_tableData
                                    //  Referenced by: '<S41>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp01Data[3];
                                  // Computed Parameter: uDLookupTable5_bp01Data
                                     //  Referenced by: '<S41>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp02Data[10];
                                  // Computed Parameter: uDLookupTable5_bp02Data
                                     //  Referenced by: '<S41>/1-D Lookup Table5'

  real32_T Switch_10_Threshold;       // Computed Parameter: Switch_10_Threshold
                                         //  Referenced by: '<S7>/Switch'

  real32_T Delay_InitialCondition; // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S47>/Delay'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S14>/Constant'

  real32_T DiscreteTimeIntegrator_gainval_m;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_m
                            //  Referenced by: '<S14>/Discrete-Time Integrator'

  real32_T Switch_7_Threshold;         // Computed Parameter: Switch_7_Threshold
                                          //  Referenced by: '<S7>/Switch'

  real32_T DiscreteTransferFcn3_NumCoef[2];
                             // Computed Parameter: DiscreteTransferFcn3_NumCoef
                                //  Referenced by: '<S13>/Discrete Transfer Fcn3'

  real32_T DiscreteTransferFcn3_DenCoef[2];
                             // Computed Parameter: DiscreteTransferFcn3_DenCoef
                                //  Referenced by: '<S13>/Discrete Transfer Fcn3'

  real32_T DiscreteTransferFcn3_InitialStates;
                       // Computed Parameter: DiscreteTransferFcn3_InitialStates
                          //  Referenced by: '<S13>/Discrete Transfer Fcn3'

  real32_T Zero_Value;                 // Computed Parameter: Zero_Value
                                          //  Referenced by: '<S14>/Zero'

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
                                          //  Referenced by: '<S43>/Gain'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S15>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S15>/Saturation'

  real32_T Gain_Gain_m;                // Computed Parameter: Gain_Gain_m
                                          //  Referenced by: '<S15>/Gain'

  real32_T One_Value_f;                // Computed Parameter: One_Value_f
                                          //  Referenced by: '<S15>/One'

  real32_T Delay_InitialCondition_f;
                                 // Computed Parameter: Delay_InitialCondition_f
                                    //  Referenced by: '<S42>/Delay'

  real32_T Gain_Gain_g;                // Computed Parameter: Gain_Gain_g
                                          //  Referenced by: '<S44>/Gain'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S15>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S15>/Saturation1'

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: '<S15>/Gain1'

  real32_T One1_Value_d;               // Computed Parameter: One1_Value_d
                                          //  Referenced by: '<S15>/One1'

  real32_T Gain_Gain_c;                // Computed Parameter: Gain_Gain_c
                                          //  Referenced by: '<S45>/Gain'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S15>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S15>/Saturation2'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S15>/Gain2'

  real32_T One2_Value_d;               // Computed Parameter: One2_Value_d
                                          //  Referenced by: '<S15>/One2'

  real32_T Gain_Gain_l;                // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S46>/Gain'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S15>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S15>/Saturation3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S15>/Gain3'

  real32_T One3_Value_b;               // Computed Parameter: One3_Value_b
                                          //  Referenced by: '<S15>/One3'

  real32_T DiscreteTransferFcn_NumCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_NumCoef
                                 //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_DenCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_DenCoef
                                 //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_InitialStates;
                        // Computed Parameter: DiscreteTransferFcn_InitialStates
                           //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real32_T uDLookupTable4_tableData[30];
                                 // Computed Parameter: uDLookupTable4_tableData
                                    //  Referenced by: '<S41>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp01Data[3];
                                  // Computed Parameter: uDLookupTable4_bp01Data
                                     //  Referenced by: '<S41>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp02Data[10];
                                  // Computed Parameter: uDLookupTable4_bp02Data
                                     //  Referenced by: '<S41>/1-D Lookup Table4'

  uint32_T uDLookupTable3_maxIndex[2];
                                  // Computed Parameter: uDLookupTable3_maxIndex
                                     //  Referenced by: '<S41>/1-D Lookup Table3'

  uint32_T uDLookupTable5_maxIndex[2];
                                  // Computed Parameter: uDLookupTable5_maxIndex
                                     //  Referenced by: '<S41>/1-D Lookup Table5'

  uint32_T uDLookupTable4_maxIndex[2];
                                  // Computed Parameter: uDLookupTable4_maxIndex
                                     //  Referenced by: '<S41>/1-D Lookup Table4'

  boolean_T One4_Value_p;              // Computed Parameter: One4_Value_p
                                          //  Referenced by: '<S15>/One4'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S19>/Memory'

  boolean_T Memory_InitialCondition_f;
                                // Computed Parameter: Memory_InitialCondition_f
                                   //  Referenced by: '<S31>/Memory'

  boolean_T Memory_InitialCondition_p;
                                // Computed Parameter: Memory_InitialCondition_p
                                   //  Referenced by: '<S36>/Memory'

  boolean_T Memory_InitialCondition_n;
                                // Computed Parameter: Memory_InitialCondition_n
                                   //  Referenced by: '<S27>/Memory'

  boolean_T Memory_InitialCondition_m;
                                // Computed Parameter: Memory_InitialCondition_m
                                   //  Referenced by: '<S40>/Memory'

};

// Real-time Model Data Structure
struct tag_RTM_pBLOCKAN_T {
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

  extern P_pBLOCKAN_T pBLOCKAN_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_pBLOCKAN_T pBLOCKAN_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_pBLOCKAN_T pBLOCKAN_DW;

// Zero-crossing (trigger) state
extern PrevZCX_pBLOCKAN_T pBLOCKAN_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_pBLOCKAN_T pBLOCKAN_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_pBLOCKAN_T pBLOCKAN_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void pBLOCKAN_initialize(void);
  extern void pBLOCKAN_step(void);
  extern void pBLOCKAN_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_pBLOCKAN_T *const pBLOCKAN_M;

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
//  Block '<S13>/Discrete Transfer Fcn1' : Unused code path elimination
//  Block '<S13>/Discrete Transfer Fcn2' : Unused code path elimination
//  Block '<S13>/Discrete Transfer Fcn4' : Unused code path elimination
//  Block '<S13>/Discrete Transfer Fcn5' : Unused code path elimination
//  Block '<S41>/1-D Lookup Table1' : Unused code path elimination
//  Block '<S41>/1-D Lookup Table2' : Unused code path elimination
//  Block '<S41>/1-D Lookup Table6' : Unused code path elimination
//  Block '<S48>/One10' : Unused code path elimination
//  Block '<S48>/One11' : Unused code path elimination
//  Block '<S16>/Cast To Single1' : Eliminate redundant data type conversion
//  Block '<S16>/Cast To Single9' : Eliminate redundant data type conversion
//  Block '<S15>/Cast To Boolean' : Eliminate redundant data type conversion


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
//  hilite_system('PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN')    - opens subsystem PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN
//  hilite_system('PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC'
//  '<S1>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN'
//  '<S2>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk'
//  '<S3>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot'
//  '<S4>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Convert to Bus'
//  '<S5>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Convert to Vector'
//  '<S6>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/IMU - Merge'
//  '<S7>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Inertial Navigation System'
//  '<S8>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Real Gyro'
//  '<S9>'   : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Calculate U1'
//  '<S10>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software'
//  '<S11>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Fin Allocation'
//  '<S12>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic'
//  '<S13>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/IMU_Filter'
//  '<S14>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Phi_Control'
//  '<S15>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands'
//  '<S16>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Fin Allocation/control_allocation'
//  '<S17>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic'
//  '<S18>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Enumeration'
//  '<S19>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic'
//  '<S20>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic'
//  '<S21>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic'
//  '<S22>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Compare To Constant'
//  '<S23>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Compare To Constant1'
//  '<S24>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Compare To Constant3'
//  '<S25>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Detect Decrease'
//  '<S26>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Enable_Timer_Logic'
//  '<S27>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Latch_Signal'
//  '<S28>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic/Compare To Constant'
//  '<S29>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic/Compare To Constant1'
//  '<S30>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic/Enable_Timer_Logic'
//  '<S31>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic/Latch_Signal'
//  '<S32>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Compare To Constant1'
//  '<S33>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Compare To Constant2'
//  '<S34>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Compare To Constant3'
//  '<S35>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Enable_Timer_Logic'
//  '<S36>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Latch_Signal'
//  '<S37>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic/Compare To Constant1'
//  '<S38>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic/Compare To Constant3'
//  '<S39>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic/Enable_Timer_Logic'
//  '<S40>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic/Latch_Signal'
//  '<S41>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Phi_Control/Gain_Lookup'
//  '<S42>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/100Hz Progress'
//  '<S43>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/Radians to Degrees'
//  '<S44>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/Radians to Degrees1'
//  '<S45>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/Radians to Degrees2'
//  '<S46>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Autopilot/Flight_Software/Servo Commands/Radians to Degrees3'
//  '<S47>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Convert to Bus/100Hz Reset'
//  '<S48>'  : 'PILAN2021a/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/pBLOCKAN/Emulated Pixhawk/Inertial Navigation System/INS (INCOMPLETE)'

#endif                                 // RTW_HEADER_pBLOCKAN_h_

//
// File trailer for generated code.
//
// [EOF]
//
