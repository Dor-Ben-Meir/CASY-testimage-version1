//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pixhawk.h
//
// Code generated for Simulink model 'Pixhawk'.
//
// Model version                  : 4.14
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Apr  9 18:43:59 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Pixhawk_h_
#define RTW_HEADER_Pixhawk_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PX4_PWM.h"
#include "Pixhawk_types.h"
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
struct B_Pixhawk_T {
  uint16_T pwmValue[8];
  real32_T siB_cmd[4];                 // '<S15>/Product'
};

// Block states (default storage) for system '<Root>'
struct DW_Pixhawk_T {
  px4_internal_block_PWM_Pixhawk_T obj;// '<S10>/PX4 PWM Output1'
  real32_T Delay_DSTATE;               // '<S14>/Delay'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S12>/Discrete-Time Integrator'
  real32_T DiscreteTransferFcn_states; // '<S3>/Discrete Transfer Fcn'
  real32_T Delay_DSTATE_l;             // '<S17>/Delay'
  real32_T DiscreteTimeIntegrator_PREV_U;// '<S12>/Discrete-Time Integrator'
  int32_T clockTickCounter;            // '<S1>/100 Hz1'
  uint32_T EmulatedPixhawk1_PREV_T;    // '<S1>/Emulated Pixhawk1'
  int8_T DiscreteTimeIntegrator_PrevResetState;// '<S12>/Discrete-Time Integrator' 
  uint8_T DiscreteTimeIntegrator_SYSTEM_ENABLE;// '<S12>/Discrete-Time Integrator' 
  boolean_T EmulatedPixhawk1_RESET_ELAPS_T;// '<S1>/Emulated Pixhawk1'
};

// Zero-crossing (trigger) state
struct PrevZCX_Pixhawk_T {
  ZCSigState EmulatedPixhawk1_Trig_ZCE;// '<S1>/Emulated Pixhawk1'
};

// External inputs (root inport signals with default storage)
struct ExtU_Pixhawk_T {
  real32_T send[23];                   // '<Root>/Serial In'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_Pixhawk_T {
  real32_T SerialOut[18];              // '<Root>/Serial Out'
};

// Parameters (default storage)
struct P_Pixhawk_T_ {
  real_T u00Hz1_Amp;                   // Expression: 1
                                          //  Referenced by: '<S1>/100 Hz1'

  real_T u00Hz1_Period;                // Computed Parameter: u00Hz1_Period
                                          //  Referenced by: '<S1>/100 Hz1'

  real_T u00Hz1_Duty;                  // Computed Parameter: u00Hz1_Duty
                                          //  Referenced by: '<S1>/100 Hz1'

  real_T u00Hz1_PhaseDelay;            // Expression: 0
                                          //  Referenced by: '<S1>/100 Hz1'

  real32_T One9_Value;                 // Computed Parameter: One9_Value
                                          //  Referenced by: '<S16>/One9'

  real32_T One_Value;                  // Computed Parameter: One_Value
                                          //  Referenced by: '<S16>/One'

  real32_T One1_Value;                 // Computed Parameter: One1_Value
                                          //  Referenced by: '<S16>/One1'

  real32_T One2_Value;                 // Computed Parameter: One2_Value
                                          //  Referenced by: '<S16>/One2'

  real32_T One3_Value;                 // Computed Parameter: One3_Value
                                          //  Referenced by: '<S16>/One3'

  real32_T One4_Value;                 // Computed Parameter: One4_Value
                                          //  Referenced by: '<S16>/One4'

  real32_T One5_Value;                 // Computed Parameter: One5_Value
                                          //  Referenced by: '<S16>/One5'

  real32_T One6_Value;                 // Computed Parameter: One6_Value
                                          //  Referenced by: '<S16>/One6'

  real32_T One7_Value;                 // Computed Parameter: One7_Value
                                          //  Referenced by: '<S16>/One7'

  real32_T One8_Value;                 // Computed Parameter: One8_Value
                                          //  Referenced by: '<S16>/One8'

  real32_T SerialOut_Y0;               // Computed Parameter: SerialOut_Y0
                                          //  Referenced by: '<S2>/Serial Out'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S15>/Constant7'

  real32_T Switch_6_Threshold;         // Computed Parameter: Switch_6_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S3>/Gain'

  real32_T Switch_1_Threshold;         // Computed Parameter: Switch_1_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Switch_2_Threshold;         // Computed Parameter: Switch_2_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T Switch_3_Threshold;         // Computed Parameter: Switch_3_Threshold
                                          //  Referenced by: '<S8>/Switch'

  real32_T uDLookupTable3_tableData[30];
                                 // Computed Parameter: uDLookupTable3_tableData
                                    //  Referenced by: '<S13>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp01Data[3];
                                  // Computed Parameter: uDLookupTable3_bp01Data
                                     //  Referenced by: '<S13>/1-D Lookup Table3'

  real32_T uDLookupTable3_bp02Data[10];
                                  // Computed Parameter: uDLookupTable3_bp02Data
                                     //  Referenced by: '<S13>/1-D Lookup Table3'

  real32_T uDLookupTable5_tableData[30];
                                 // Computed Parameter: uDLookupTable5_tableData
                                    //  Referenced by: '<S13>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp01Data[3];
                                  // Computed Parameter: uDLookupTable5_bp01Data
                                     //  Referenced by: '<S13>/1-D Lookup Table5'

  real32_T uDLookupTable5_bp02Data[10];
                                  // Computed Parameter: uDLookupTable5_bp02Data
                                     //  Referenced by: '<S13>/1-D Lookup Table5'

  real32_T Switch_10_Threshold;       // Computed Parameter: Switch_10_Threshold
                                         //  Referenced by: '<S8>/Switch'

  real32_T Delay_InitialCondition; // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S14>/Delay'

  real32_T Constant_Value;             // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S12>/Constant'

  real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S12>/Discrete-Time Integrator'

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

  real32_T Zero_Value_f;               // Computed Parameter: Zero_Value_f
                                          //  Referenced by: '<S2>/Zero'

  real32_T Gain_Gain_j;                // Computed Parameter: Gain_Gain_j
                                          //  Referenced by: '<S18>/Gain'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S10>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S10>/Saturation'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S10>/Gain'

  real32_T One_Value_a;                // Computed Parameter: One_Value_a
                                          //  Referenced by: '<S10>/One'

  real32_T Delay_InitialCondition_g;
                                 // Computed Parameter: Delay_InitialCondition_g
                                    //  Referenced by: '<S17>/Delay'

  real32_T Gain_Gain_os;               // Computed Parameter: Gain_Gain_os
                                          //  Referenced by: '<S19>/Gain'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S10>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S10>/Saturation1'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S10>/Gain1'

  real32_T One1_Value_a;               // Computed Parameter: One1_Value_a
                                          //  Referenced by: '<S10>/One1'

  real32_T Gain_Gain_p;                // Computed Parameter: Gain_Gain_p
                                          //  Referenced by: '<S20>/Gain'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S10>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S10>/Saturation2'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S10>/Gain2'

  real32_T One2_Value_k;               // Computed Parameter: One2_Value_k
                                          //  Referenced by: '<S10>/One2'

  real32_T Gain_Gain_g;                // Computed Parameter: Gain_Gain_g
                                          //  Referenced by: '<S21>/Gain'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S10>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S10>/Saturation3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S10>/Gain3'

  real32_T One3_Value_o;               // Computed Parameter: One3_Value_o
                                          //  Referenced by: '<S10>/One3'

  real32_T uDLookupTable4_tableData[30];
                                 // Computed Parameter: uDLookupTable4_tableData
                                    //  Referenced by: '<S13>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp01Data[3];
                                  // Computed Parameter: uDLookupTable4_bp01Data
                                     //  Referenced by: '<S13>/1-D Lookup Table4'

  real32_T uDLookupTable4_bp02Data[10];
                                  // Computed Parameter: uDLookupTable4_bp02Data
                                     //  Referenced by: '<S13>/1-D Lookup Table4'

  uint32_T uDLookupTable3_maxIndex[2];
                                  // Computed Parameter: uDLookupTable3_maxIndex
                                     //  Referenced by: '<S13>/1-D Lookup Table3'

  uint32_T uDLookupTable5_maxIndex[2];
                                  // Computed Parameter: uDLookupTable5_maxIndex
                                     //  Referenced by: '<S13>/1-D Lookup Table5'

  uint32_T uDLookupTable4_maxIndex[2];
                                  // Computed Parameter: uDLookupTable4_maxIndex
                                     //  Referenced by: '<S13>/1-D Lookup Table4'

  boolean_T One4_Value_p;              // Computed Parameter: One4_Value_p
                                          //  Referenced by: '<S10>/One4'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<S3>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_Pixhawk_T {
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

  extern P_Pixhawk_T Pixhawk_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_Pixhawk_T Pixhawk_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_Pixhawk_T Pixhawk_DW;

// Zero-crossing (trigger) state
extern PrevZCX_Pixhawk_T Pixhawk_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_Pixhawk_T Pixhawk_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_Pixhawk_T Pixhawk_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Pixhawk_initialize(void);
  extern void Pixhawk_step(void);
  extern void Pixhawk_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Pixhawk_T *const Pixhawk_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S13>/1-D Lookup Table1' : Unused code path elimination
//  Block '<S13>/1-D Lookup Table2' : Unused code path elimination
//  Block '<S13>/1-D Lookup Table6' : Unused code path elimination
//  Block '<S16>/One10' : Unused code path elimination
//  Block '<S16>/One11' : Unused code path elimination
//  Block '<S10>/Cast To Boolean' : Eliminate redundant data type conversion


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
//  hilite_system('PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block')    - opens subsystem PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block
//  hilite_system('PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'PIL_NO_RPI_new/Flight Control Computer1'
//  '<S1>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block'
//  '<S2>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1'
//  '<S3>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Autopilot'
//  '<S4>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Convert to Bus'
//  '<S5>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Convert to Vector'
//  '<S6>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Fin Allocation'
//  '<S7>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/IMU - Merge'
//  '<S8>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Inertial Navigation System'
//  '<S9>'   : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Real Gyro'
//  '<S10>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Servo Commands'
//  '<S11>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Autopilot/Calculate U'
//  '<S12>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Autopilot/Phi_Control'
//  '<S13>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Autopilot/Phi_Control/Gain_Lookup'
//  '<S14>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Convert to Bus/100Hz Reset'
//  '<S15>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Fin Allocation/control_allocation'
//  '<S16>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Inertial Navigation System/INS (INCOMPLETE)'
//  '<S17>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Servo Commands/100Hz Progress'
//  '<S18>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Servo Commands/Radians to Degrees'
//  '<S19>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Servo Commands/Radians to Degrees1'
//  '<S20>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Servo Commands/Radians to Degrees2'
//  '<S21>'  : 'PIL_NO_RPI_new/Flight Control Computer1/Pixhawk Block/Emulated Pixhawk1/Servo Commands/Radians to Degrees3'

#endif                                 // RTW_HEADER_Pixhawk_h_

//
// File trailer for generated code.
//
// [EOF]
//
