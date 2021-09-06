//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PixBlock2.h
//
// Code generated for Simulink model 'PixBlock2'.
//
// Model version                  : 4.22
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Apr 13 10:08:45 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_PixBlock2_h_
#define RTW_HEADER_PixBlock2_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "PixBlock2_types.h"
#include "rt_zcfcn.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_PixBlock2_T {
  real32_T siB_cmd[4];                 // '<S14>/Product'
};

// Block states (default storage) for system '<Root>'
struct DW_PixBlock2_T {
  real32_T DiscreteTransferFcn_states; // '<S3>/Discrete Transfer Fcn'
  real32_T Delay_DSTATE;               // '<S13>/Delay'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S11>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_PREV_U;// '<S11>/Discrete-Time Integrator'
  int32_T clockTickCounter;            // '<S1>/100 Hz'
  uint32_T EmulatedPixhawk_PREV_T;     // '<S1>/Emulated Pixhawk'
  int8_T DiscreteTimeIntegrator_PrevResetState;// '<S11>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE;// '<S11>/Discrete-Time Integrator' 
  boolean_T EmulatedPixhawk_RESET_ELAPS_T;// '<S1>/Emulated Pixhawk'
};

// Zero-crossing (trigger) state
struct PrevZCX_PixBlock2_T {
  ZCSigState EmulatedPixhawk_Trig_ZCE; // '<S1>/Emulated Pixhawk'
};

// External inputs (root inport signals with default storage)
struct ExtU_PixBlock2_T {
  real32_T send[23];                   // '<Root>/Serial In'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_PixBlock2_T {
  real32_T SerialOut[18];              // '<Root>/Serial Out'
};

// Parameters (default storage)
struct P_PixBlock2_T_ {
  real_T u00Hz_Amp;                    // Expression: 1
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Period;                 // Computed Parameter: u00Hz_Period
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Duty;                   // Computed Parameter: u00Hz_Duty
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_PhaseDelay;             // Expression: 0
                                          //  Referenced by: '<S1>/100 Hz'

  real32_T One9_Value;                 // Computed Parameter: One9_Value
                                          //  Referenced by: '<S15>/One9'

  real32_T One_Value;                  // Computed Parameter: One_Value
                                          //  Referenced by: '<S15>/One'

  real32_T One1_Value;                 // Computed Parameter: One1_Value
                                          //  Referenced by: '<S15>/One1'

  real32_T One2_Value;                 // Computed Parameter: One2_Value
                                          //  Referenced by: '<S15>/One2'

  real32_T One3_Value;                 // Computed Parameter: One3_Value
                                          //  Referenced by: '<S15>/One3'

  real32_T One4_Value;                 // Computed Parameter: One4_Value
                                          //  Referenced by: '<S15>/One4'

  real32_T One5_Value;                 // Computed Parameter: One5_Value
                                          //  Referenced by: '<S15>/One5'

  real32_T One6_Value;                 // Computed Parameter: One6_Value
                                          //  Referenced by: '<S15>/One6'

  real32_T One7_Value;                 // Computed Parameter: One7_Value
                                          //  Referenced by: '<S15>/One7'

  real32_T One8_Value;                 // Computed Parameter: One8_Value
                                          //  Referenced by: '<S15>/One8'

  real32_T SerialOut_Y0;               // Computed Parameter: SerialOut_Y0
                                          //  Referenced by: '<S2>/Serial Out'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S14>/Constant7'

  real32_T Switch_1_Threshold;         // Computed Parameter: Switch_1_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Switch_2_Threshold;         // Computed Parameter: Switch_2_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Switch_3_Threshold;         // Computed Parameter: Switch_3_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Switch_6_Threshold;         // Computed Parameter: Switch_6_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S3>/Gain'

  real32_T uDLookupTable3_tableData[30];
                                 // Computed Parameter: uDLookupTable3_tableData
                                    //  Referenced by: '<S12>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp01Data[3];
                                  // Computed Parameter: uDLookupTable3_bp01Data
                                     //  Referenced by: '<S12>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp02Data[10];
                                  // Computed Parameter: uDLookupTable3_bp02Data
                                     //  Referenced by: '<S12>/1-D Lookup Table3'

  real32_T DiscreteTransferFcn_NumCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_NumCoef
                                 //  Referenced by: '<S3>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_DenCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_DenCoef
                                 //  Referenced by: '<S3>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_InitialStates;
                        // Computed Parameter: DiscreteTransferFcn_InitialStates
                           //  Referenced by: '<S3>/Discrete Transfer Fcn'

  real32_T Switch_7_Threshold;         // Computed Parameter: Switch_7_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Constant_Value;             // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S11>/Constant'

  real32_T Delay_InitialCondition; // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S13>/Delay'

  real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S11>/Discrete-Time Integrator'

  real32_T uDLookupTable5_tableData[30];
                                 // Computed Parameter: uDLookupTable5_tableData
                                    //  Referenced by: '<S12>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp01Data[3];
                                  // Computed Parameter: uDLookupTable5_bp01Data
                                     //  Referenced by: '<S12>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp02Data[10];
                                  // Computed Parameter: uDLookupTable5_bp02Data
                                     //  Referenced by: '<S12>/1-D Lookup Table5'

  real32_T Switch_10_Threshold;       // Computed Parameter: Switch_10_Threshold
                                         //  Referenced by: '<S8>/Switch'

  real32_T Zero_Value;                 // Computed Parameter: Zero_Value
                                          //  Referenced by: '<S3>/Zero'

  real32_T Switch_4_Threshold;         // Computed Parameter: Switch_4_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Switch_5_Threshold;         // Computed Parameter: Switch_5_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Switch_8_Threshold;         // Computed Parameter: Switch_8_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Switch_9_Threshold;         // Computed Parameter: Switch_9_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Zero_Value_e;               // Computed Parameter: Zero_Value_e
                                          //  Referenced by: '<S2>/Zero'

  real32_T uDLookupTable4_tableData[30];
                                 // Computed Parameter: uDLookupTable4_tableData
                                    //  Referenced by: '<S12>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp01Data[3];
                                  // Computed Parameter: uDLookupTable4_bp01Data
                                     //  Referenced by: '<S12>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp02Data[10];
                                  // Computed Parameter: uDLookupTable4_bp02Data
                                     //  Referenced by: '<S12>/1-D Lookup Table4'

  uint32_T uDLookupTable3_maxIndex[2];
                                  // Computed Parameter: uDLookupTable3_maxIndex
                                     //  Referenced by: '<S12>/1-D Lookup Table3'

  uint32_T uDLookupTable5_maxIndex[2];
                                  // Computed Parameter: uDLookupTable5_maxIndex
                                     //  Referenced by: '<S12>/1-D Lookup Table5'

  uint32_T uDLookupTable4_maxIndex[2];
                                  // Computed Parameter: uDLookupTable4_maxIndex
                                     //  Referenced by: '<S12>/1-D Lookup Table4'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<S3>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_PixBlock2_T {
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

  extern P_PixBlock2_T PixBlock2_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_PixBlock2_T PixBlock2_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_PixBlock2_T PixBlock2_DW;

// Zero-crossing (trigger) state
extern PrevZCX_PixBlock2_T PixBlock2_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_PixBlock2_T PixBlock2_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_PixBlock2_T PixBlock2_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void PixBlock2_initialize(void);
  extern void PixBlock2_step(void);
  extern void PixBlock2_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_PixBlock2_T *const PixBlock2_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S12>/1-D Lookup Table1' : Unused code path elimination
//  Block '<S12>/1-D Lookup Table2' : Unused code path elimination
//  Block '<S12>/1-D Lookup Table6' : Unused code path elimination
//  Block '<S15>/One10' : Unused code path elimination
//  Block '<S15>/One11' : Unused code path elimination


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
//  hilite_system('PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2')    - opens subsystem PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2
//  hilite_system('PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC'
//  '<S1>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2'
//  '<S2>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk'
//  '<S3>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Autopilot'
//  '<S4>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Convert to Bus'
//  '<S5>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Convert to Vector'
//  '<S6>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Fin Allocation'
//  '<S7>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/IMU - Merge'
//  '<S8>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Inertial Navigation System'
//  '<S9>'   : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Real Gyro'
//  '<S10>'  : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Autopilot/Calculate U'
//  '<S11>'  : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Autopilot/Phi_Control'
//  '<S12>'  : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Autopilot/Phi_Control/Gain_Lookup'
//  '<S13>'  : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Convert to Bus/100Hz Reset'
//  '<S14>'  : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Fin Allocation/control_allocation'
//  '<S15>'  : 'PILnewH/Flight Control Computer/FCC - Real or Emulated/Real FCC/PixBlock2/Emulated Pixhawk/Inertial Navigation System/INS (INCOMPLETE)'

#endif                                 // RTW_HEADER_PixBlock2_h_

//
// File trailer for generated code.
//
// [EOF]
//
