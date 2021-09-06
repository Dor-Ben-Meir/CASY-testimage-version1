//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Emulated.h
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
#ifndef RTW_HEADER_Emulated_h_
#define RTW_HEADER_Emulated_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PX4_PWM.h"
#include "Emulated_types.h"
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
struct B_Emulated_T {
  real32_T csumrev[9];
  uint16_T pwmValue[8];
  real32_T siB_cmd[4];                 // '<S15>/Product'
  real_T u00Hz;                        // '<S1>/100 Hz'
  real32_T Fin_1_Cmd_rad;
  real32_T Fin_2_Cmd_rad;
  real32_T Fin_3_Cmd_rad;
  real32_T Fin_4_Cmd_rad;
  real32_T u;                          // '<S6>/Switch'
  boolean_T recovery_log;              // '<S20>/AND2'
};

// Block states (default storage) for system '<Root>'
struct DW_Emulated_T {
  dsp_simulink_MovingAverage_Emulated_T obj;// '<S16>/Moving Average1'
  px4_internal_block_PWM_Emulated_T obj_m;// '<S8>/PX4 PWM Output1'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S25>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_n;// '<S29>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_p;// '<S34>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_o;// '<S38>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U;// '<S25>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_m;// '<S29>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_a;// '<S34>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_mh;// '<S38>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTATE_no;// '<S14>/Discrete-Time Integrator'
  real32_T DiscreteTransferFcn3_states;// '<S13>/Discrete Transfer Fcn3'
  real32_T DelayInput1_DSTATE;         // '<S24>/Delay Input1'
  real32_T DiscreteTransferFcn_states; // '<S13>/Discrete Transfer Fcn'
  real32_T DiscreteTimeIntegrator_PREV_U_j;// '<S14>/Discrete-Time Integrator'
  int32_T clockTickCounter;            // '<S1>/100 Hz'
  uint32_T Autopilot_PREV_T;           // '<S1>/Autopilot'
  int8_T DiscreteTimeIntegrator_PrevResetState;// '<S14>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_j;// '<S25>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_i;// '<S29>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_iw;// '<S34>/Discrete-Time Integrator' 
  int8_T DiscreteTimeIntegrator_PrevResetState_ii;// '<S38>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE;// '<S14>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE_h;// '<S25>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE_e;// '<S29>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE_d;// '<S34>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE_ec;// '<S38>/Discrete-Time Integrator' 
  boolean_T Autopilot_RESET_ELAPS_T;   // '<S1>/Autopilot'
  boolean_T Memory_PreviousInput;      // '<S18>/Memory'
  boolean_T Memory_PreviousInput_f;    // '<S30>/Memory'
  boolean_T Memory_PreviousInput_l;    // '<S35>/Memory'
  boolean_T Memory_PreviousInput_e;    // '<S26>/Memory'
  boolean_T Memory_PreviousInput_p;    // '<S39>/Memory'
};

// Zero-crossing (trigger) state
struct PrevZCX_Emulated_T {
  ZCSigState Autopilot_Trig_ZCE;       // '<S1>/Autopilot'
};

// External inputs (root inport signals with default storage)
struct ExtU_Emulated_T {
  real32_T SerialIn[23];               // '<Root>/Serial In'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_Emulated_T {
  real32_T SerialOut[18];              // '<Root>/Serial Out'
  real_T flight_mode_enum;             // '<Root>/flight_mode_enum'
};

// Parameters (default storage)
struct P_Emulated_T_ {
  struct_KbuHZdFirwgp0Ajtitq2dC Flight_Logic;// Variable: Flight_Logic
                                                //  Referenced by:
                                                //    '<S20>/Constant'
                                                //    '<S22>/Constant'
                                                //    '<S23>/Constant'
                                                //    '<S28>/Constant'
                                                //    '<S31>/Constant'
                                                //    '<S33>/Constant'
                                                //    '<S36>/Constant'
                                                //    '<S37>/Constant'

  real32_T CompareToConstant_const;   // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S27>/Constant'

  real32_T CompareToConstant2_const; // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S32>/Constant'

  real32_T CompareToConstant_const_g;
                                    // Mask Parameter: CompareToConstant_const_g
                                       //  Referenced by: '<S21>/Constant'

  real32_T DetectDecrease_vinit;       // Mask Parameter: DetectDecrease_vinit
                                          //  Referenced by: '<S24>/Delay Input1'

  struct_9UxdYJe4udzuwrp3psUiN FinDeflections_Y0;// Computed Parameter: FinDeflections_Y0
                                                    //  Referenced by: '<S2>/Fin Deflections'

  struct_9UxdYJe4udzuwrp3psUiN FinCmd_Y0;// Computed Parameter: FinCmd_Y0
                                            //  Referenced by: '<S2>/Fin Cmd'

  real_T Constant4_Value;              // Expression: 600
                                          //  Referenced by: '<S17>/Constant4'

  real_T Constant6_Value;              // Expression: 500
                                          //  Referenced by: '<S17>/Constant6'

  real_T Constant3_Value;              // Expression: 400
                                          //  Referenced by: '<S17>/Constant3'

  real_T Constant2_Value;              // Expression: 300
                                          //  Referenced by: '<S17>/Constant2'

  real_T Constant1_Value;              // Expression: 200
                                          //  Referenced by: '<S17>/Constant1'

  real_T Constant_Value;               // Expression: 1
                                          //  Referenced by: '<S17>/Constant'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S12>/Constant5'

  real_T Constant5_Value_k;            // Expression: 0
                                          //  Referenced by: '<S17>/Constant5'

  real_T Constant_Value_l;             // Expression: 0
                                          //  Referenced by: '<S18>/Constant'

  real_T flight_mode_enum_Y0;         // Computed Parameter: flight_mode_enum_Y0
                                         //  Referenced by: '<S2>/flight_mode_enum'

  real_T Constant1_Value_g;            // Expression: 0
                                          //  Referenced by: '<S25>/Constant1'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S25>/Discrete-Time Integrator'

  real_T Constant1_Value_m;            // Expression: 0
                                          //  Referenced by: '<S29>/Constant1'

  real_T DiscreteTimeIntegrator_gainval_l;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_l
                            //  Referenced by: '<S29>/Discrete-Time Integrator'

  real_T Constant1_Value_f;            // Expression: 0
                                          //  Referenced by: '<S34>/Constant1'

  real_T DiscreteTimeIntegrator_gainval_k;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_k
                            //  Referenced by: '<S34>/Discrete-Time Integrator'

  real_T Constant1_Value_e;            // Expression: 0
                                          //  Referenced by: '<S38>/Constant1'

  real_T DiscreteTimeIntegrator_gainval_o;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_o
                            //  Referenced by: '<S38>/Discrete-Time Integrator'

  real_T Constant_Value_a;             // Expression: 1
                                          //  Referenced by: '<S25>/Constant'

  real_T Constant_Value_lo;            // Expression: 1
                                          //  Referenced by: '<S29>/Constant'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<S34>/Constant'

  real_T Constant_Value_bq;            // Expression: 1
                                          //  Referenced by: '<S38>/Constant'

  real_T One5_Value;                   // Expression: 2000
                                          //  Referenced by: '<S8>/One5'

  real_T One6_Value;                   // Expression: 1000
                                          //  Referenced by: '<S8>/One6'

  real_T u00Hz_Amp;                    // Expression: 1
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Period;                 // Computed Parameter: u00Hz_Period
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Duty;                   // Computed Parameter: u00Hz_Duty
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_PhaseDelay;             // Expression: 0
                                          //  Referenced by: '<S1>/100 Hz'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S15>/Constant7'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S2>/Gain1'

  real32_T uDLookupTable3_tableData[30];
                                 // Computed Parameter: uDLookupTable3_tableData
                                    //  Referenced by: '<S40>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp01Data[3];
                                  // Computed Parameter: uDLookupTable3_bp01Data
                                     //  Referenced by: '<S40>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp02Data[10];
                                  // Computed Parameter: uDLookupTable3_bp02Data
                                     //  Referenced by: '<S40>/1-D Lookup Table3'

  real32_T uDLookupTable5_tableData[30];
                                 // Computed Parameter: uDLookupTable5_tableData
                                    //  Referenced by: '<S40>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp01Data[3];
                                  // Computed Parameter: uDLookupTable5_bp01Data
                                     //  Referenced by: '<S40>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp02Data[10];
                                  // Computed Parameter: uDLookupTable5_bp02Data
                                     //  Referenced by: '<S40>/1-D Lookup Table5'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S14>/Constant'

  real32_T DiscreteTimeIntegrator_gainval_m;
                         // Computed Parameter: DiscreteTimeIntegrator_gainval_m
                            //  Referenced by: '<S14>/Discrete-Time Integrator'

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

  real32_T uDLookupTable4_tableData[30];
                                 // Computed Parameter: uDLookupTable4_tableData
                                    //  Referenced by: '<S40>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp01Data[3];
                                  // Computed Parameter: uDLookupTable4_bp01Data
                                     //  Referenced by: '<S40>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp02Data[10];
                                  // Computed Parameter: uDLookupTable4_bp02Data
                                     //  Referenced by: '<S40>/1-D Lookup Table4'

  real32_T DiscreteTransferFcn_NumCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_NumCoef
                                 //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_DenCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_DenCoef
                                 //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_InitialStates;
                        // Computed Parameter: DiscreteTransferFcn_InitialStates
                           //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real32_T One9_Value;                 // Computed Parameter: One9_Value
                                          //  Referenced by: '<S42>/One9'

  real32_T One_Value;                  // Computed Parameter: One_Value
                                          //  Referenced by: '<S42>/One'

  real32_T One1_Value;                 // Computed Parameter: One1_Value
                                          //  Referenced by: '<S42>/One1'

  real32_T One2_Value;                 // Computed Parameter: One2_Value
                                          //  Referenced by: '<S42>/One2'

  real32_T One3_Value;                 // Computed Parameter: One3_Value
                                          //  Referenced by: '<S42>/One3'

  real32_T One4_Value;                 // Computed Parameter: One4_Value
                                          //  Referenced by: '<S42>/One4'

  real32_T One5_Value_o;               // Computed Parameter: One5_Value_o
                                          //  Referenced by: '<S42>/One5'

  real32_T One6_Value_c;               // Computed Parameter: One6_Value_c
                                          //  Referenced by: '<S42>/One6'

  real32_T One7_Value;                 // Computed Parameter: One7_Value
                                          //  Referenced by: '<S42>/One7'

  real32_T One8_Value;                 // Computed Parameter: One8_Value
                                          //  Referenced by: '<S42>/One8'

  real32_T Switch_1_Threshold;         // Computed Parameter: Switch_1_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_2_Threshold;         // Computed Parameter: Switch_2_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_3_Threshold;         // Computed Parameter: Switch_3_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_4_Threshold;         // Computed Parameter: Switch_4_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_5_Threshold;         // Computed Parameter: Switch_5_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_6_Threshold;         // Computed Parameter: Switch_6_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_7_Threshold;         // Computed Parameter: Switch_7_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_8_Threshold;         // Computed Parameter: Switch_8_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_9_Threshold;         // Computed Parameter: Switch_9_Threshold
                                          //  Referenced by: '<S6>/Switch'

  real32_T Switch_10_Threshold;       // Computed Parameter: Switch_10_Threshold
                                         //  Referenced by: '<S6>/Switch'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S44>/Gain'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S8>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S8>/Saturation'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S8>/Gain'

  real32_T One_Value_a;                // Computed Parameter: One_Value_a
                                          //  Referenced by: '<S8>/One'

  real32_T Gain_Gain_m;                // Computed Parameter: Gain_Gain_m
                                          //  Referenced by: '<S45>/Gain'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S8>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S8>/Saturation1'

  real32_T Gain1_Gain_l;               // Computed Parameter: Gain1_Gain_l
                                          //  Referenced by: '<S8>/Gain1'

  real32_T One1_Value_b;               // Computed Parameter: One1_Value_b
                                          //  Referenced by: '<S8>/One1'

  real32_T Gain_Gain_l;                // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S46>/Gain'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S8>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S8>/Saturation2'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S8>/Gain2'

  real32_T One2_Value_o;               // Computed Parameter: One2_Value_o
                                          //  Referenced by: '<S8>/One2'

  real32_T Gain_Gain_p;                // Computed Parameter: Gain_Gain_p
                                          //  Referenced by: '<S47>/Gain'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S8>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S8>/Saturation3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S8>/Gain3'

  real32_T One3_Value_p;               // Computed Parameter: One3_Value_p
                                          //  Referenced by: '<S8>/One3'

  real32_T Zero_Value_a;               // Computed Parameter: Zero_Value_a
                                          //  Referenced by: '<S1>/Zero'

  uint32_T uDLookupTable3_maxIndex[2];
                                  // Computed Parameter: uDLookupTable3_maxIndex
                                     //  Referenced by: '<S40>/1-D Lookup Table3'

  uint32_T uDLookupTable5_maxIndex[2];
                                  // Computed Parameter: uDLookupTable5_maxIndex
                                     //  Referenced by: '<S40>/1-D Lookup Table5'

  uint32_T uDLookupTable4_maxIndex[2];
                                  // Computed Parameter: uDLookupTable4_maxIndex
                                     //  Referenced by: '<S40>/1-D Lookup Table4'

  boolean_T Recovery_Y0;               // Computed Parameter: Recovery_Y0
                                          //  Referenced by: '<S2>/Recovery'

  boolean_T Constant_Value_c;          // Computed Parameter: Constant_Value_c
                                          //  Referenced by: '<S10>/Constant'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S18>/Memory'

  boolean_T Memory_InitialCondition_f;
                                // Computed Parameter: Memory_InitialCondition_f
                                   //  Referenced by: '<S30>/Memory'

  boolean_T Memory_InitialCondition_p;
                                // Computed Parameter: Memory_InitialCondition_p
                                   //  Referenced by: '<S35>/Memory'

  boolean_T Memory_InitialCondition_n;
                                // Computed Parameter: Memory_InitialCondition_n
                                   //  Referenced by: '<S26>/Memory'

  boolean_T Memory_InitialCondition_m;
                                // Computed Parameter: Memory_InitialCondition_m
                                   //  Referenced by: '<S39>/Memory'

  boolean_T One7_Value_m;              // Computed Parameter: One7_Value_m
                                          //  Referenced by: '<S8>/One7'

  boolean_T One4_Value_n;              // Computed Parameter: One4_Value_n
                                          //  Referenced by: '<S8>/One4'

};

// Real-time Model Data Structure
struct tag_RTM_Emulated_T {
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

  extern P_Emulated_T Emulated_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_Emulated_T Emulated_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_Emulated_T Emulated_DW;

// Zero-crossing (trigger) state
extern PrevZCX_Emulated_T Emulated_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_Emulated_T Emulated_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_Emulated_T Emulated_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Emulated_initialize(void);
  extern void Emulated_step(void);
  extern void Emulated_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Emulated_T *const Emulated_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Constant' : Unused code path elimination
//  Block '<S2>/Constant1' : Unused code path elimination
//  Block '<S2>/Constant2' : Unused code path elimination
//  Block '<S2>/Constant3' : Unused code path elimination
//  Block '<S2>/Constant4' : Unused code path elimination
//  Block '<S2>/Constant5' : Unused code path elimination
//  Block '<S2>/Constant6' : Unused code path elimination
//  Block '<S2>/Constant7' : Unused code path elimination
//  Block '<S2>/Constant8' : Unused code path elimination
//  Block '<S13>/Discrete Transfer Fcn1' : Unused code path elimination
//  Block '<S13>/Discrete Transfer Fcn2' : Unused code path elimination
//  Block '<S13>/Discrete Transfer Fcn4' : Unused code path elimination
//  Block '<S13>/Discrete Transfer Fcn5' : Unused code path elimination
//  Block '<S40>/1-D Lookup Table1' : Unused code path elimination
//  Block '<S40>/1-D Lookup Table2' : Unused code path elimination
//  Block '<S40>/1-D Lookup Table6' : Unused code path elimination
//  Block '<S41>/Delay' : Unused code path elimination
//  Block '<S41>/GreaterThan' : Unused code path elimination
//  Block '<S42>/One10' : Unused code path elimination
//  Block '<S42>/One11' : Unused code path elimination
//  Block '<S43>/Delay' : Unused code path elimination
//  Block '<S43>/GreaterThan' : Unused code path elimination
//  Block '<S8>/AND' : Unused code path elimination
//  Block '<S8>/Cast To Boolean' : Unused code path elimination
//  Block '<S15>/Cast To Single1' : Eliminate redundant data type conversion
//  Block '<S15>/Cast To Single9' : Eliminate redundant data type conversion
//  Block '<S4>/Cast To Single' : Eliminate redundant data type conversion


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
//  hilite_system('PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk')    - opens subsystem PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk
//  hilite_system('PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5'
//  '<S1>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk'
//  '<S2>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot'
//  '<S3>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Convert to Bus'
//  '<S4>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Convert to Vector'
//  '<S5>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/IMU - Merge'
//  '<S6>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Inertial Navigation System'
//  '<S7>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Real Gyro'
//  '<S8>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Servo Commands'
//  '<S9>'   : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Calculate U1'
//  '<S10>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software'
//  '<S11>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Fin Allocation'
//  '<S12>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic'
//  '<S13>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/IMU_Filter'
//  '<S14>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Phi_Control'
//  '<S15>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Fin Allocation/control_allocation'
//  '<S16>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic'
//  '<S17>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Enumeration'
//  '<S18>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic'
//  '<S19>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic'
//  '<S20>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic'
//  '<S21>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Compare To Constant'
//  '<S22>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Compare To Constant1'
//  '<S23>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Compare To Constant3'
//  '<S24>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Detect Decrease'
//  '<S25>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Enable_Timer_Logic'
//  '<S26>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Apogee_Detection_Logic/Latch_Signal'
//  '<S27>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic/Compare To Constant'
//  '<S28>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic/Compare To Constant1'
//  '<S29>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic/Enable_Timer_Logic'
//  '<S30>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Launch_Detection_Logic/Latch_Signal'
//  '<S31>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Compare To Constant1'
//  '<S32>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Compare To Constant2'
//  '<S33>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Compare To Constant3'
//  '<S34>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Enable_Timer_Logic'
//  '<S35>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/MECO_Detection_Logic/Latch_Signal'
//  '<S36>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic/Compare To Constant1'
//  '<S37>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic/Compare To Constant3'
//  '<S38>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic/Enable_Timer_Logic'
//  '<S39>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Flight_Logic/Recovery_Logic/Latch_Signal'
//  '<S40>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Autopilot/Flight_Software/Phi_Control/Gain_Lookup'
//  '<S41>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Convert to Bus/100Hz Reset'
//  '<S42>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Inertial Navigation System/INS (INCOMPLETE)'
//  '<S43>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Servo Commands/100Hz Progress'
//  '<S44>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Servo Commands/Radians to Degrees'
//  '<S45>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Servo Commands/Radians to Degrees1'
//  '<S46>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Servo Commands/Radians to Degrees2'
//  '<S47>'  : 'PILEncoder/Flight Control Computer/FCC - Real or Emulated/Emulated FCC/P2R5/Emulated Pixhawk/Servo Commands/Radians to Degrees3'

#endif                                 // RTW_HEADER_Emulated_h_

//
// File trailer for generated code.
//
// [EOF]
//
