//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PwmBox.h
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
#ifndef RTW_HEADER_PwmBox_h_
#define RTW_HEADER_PwmBox_h_
#include <math.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PX4_PWM.h"
#include "PwmBox_types.h"
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

// Block states (default storage) for system '<Root>'
struct DW_PwmBox_T {
  px4_internal_block_PWM_PwmBox_T obj; // '<S4>/PX4 PWM Output1'
  int32_T clockTickCounter;            // '<S1>/100 Hz'
};

// Zero-crossing (trigger) state
struct PrevZCX_PwmBox_T {
  ZCSigState EmulatedPixhawk_Trig_ZCE; // '<S1>/Emulated Pixhawk'
};

// External inputs (root inport signals with default storage)
struct ExtU_PwmBox_T {
  real_T SerialIn;                     // '<Root>/Serial In'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_PwmBox_T {
  uint16_T signal1;                    // '<Root>/signal1'
  uint16_T signal2;                    // '<Root>/signal2'
  uint16_T signal3;                    // '<Root>/signal3'
  uint16_T signal4;                    // '<Root>/signal4'
};

// Parameters (default storage)
struct P_PwmBox_T_ {
  real_T Constant_Value;               // Expression: 0
                                          //  Referenced by: '<S3>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S3>/Constant1'

  real_T u00Hz_Amp;                    // Expression: 1
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Period;                 // Computed Parameter: u00Hz_Period
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_Duty;                   // Computed Parameter: u00Hz_Duty
                                          //  Referenced by: '<S1>/100 Hz'

  real_T u00Hz_PhaseDelay;             // Expression: 0
                                          //  Referenced by: '<S1>/100 Hz'

  struct_a1AjtOphUHLNf8OXJ9zaQB PWM_Y0;// Computed Parameter: PWM_Y0
                                          //  Referenced by: '<S2>/PWM'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S5>/Constant7'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S6>/Gain'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S4>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S4>/Saturation'

  real32_T Gain_Gain_g;                // Computed Parameter: Gain_Gain_g
                                          //  Referenced by: '<S4>/Gain'

  real32_T One_Value;                  // Computed Parameter: One_Value
                                          //  Referenced by: '<S4>/One'

  real32_T Gain_Gain_i;                // Computed Parameter: Gain_Gain_i
                                          //  Referenced by: '<S7>/Gain'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S4>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S4>/Saturation1'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S4>/Gain1'

  real32_T One1_Value;                 // Computed Parameter: One1_Value
                                          //  Referenced by: '<S4>/One1'

  real32_T Gain_Gain_j;                // Computed Parameter: Gain_Gain_j
                                          //  Referenced by: '<S8>/Gain'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S4>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S4>/Saturation2'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S4>/Gain2'

  real32_T One2_Value;                 // Computed Parameter: One2_Value
                                          //  Referenced by: '<S4>/One2'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S9>/Gain'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S4>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S4>/Saturation3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S4>/Gain3'

  real32_T One3_Value;                 // Computed Parameter: One3_Value
                                          //  Referenced by: '<S4>/One3'

  boolean_T One7_Value;                // Computed Parameter: One7_Value
                                          //  Referenced by: '<S4>/One7'

  boolean_T One4_Value;                // Computed Parameter: One4_Value
                                          //  Referenced by: '<S4>/One4'

};

// Real-time Model Data Structure
struct tag_RTM_PwmBox_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_PwmBox_T PwmBox_P;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_PwmBox_T PwmBox_DW;

// Zero-crossing (trigger) state
extern PrevZCX_PwmBox_T PwmBox_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // External inputs (root inport signals with default storage)
  extern struct ExtU_PwmBox_T PwmBox_U;

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_PwmBox_T PwmBox_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void PwmBox_initialize(void);
  extern void PwmBox_step(void);
  extern void PwmBox_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_PwmBox_T *const PwmBox_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S5>/Cast To Single9' : Eliminate redundant data type conversion


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
//  hilite_system('PILAN2021a/PwmBox')    - opens subsystem PILAN2021a/PwmBox
//  hilite_system('PILAN2021a/PwmBox/Kp') - opens and selects block Kp
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'PILAN2021a'
//  '<S1>'   : 'PILAN2021a/PwmBox'
//  '<S2>'   : 'PILAN2021a/PwmBox/Emulated Pixhawk'
//  '<S3>'   : 'PILAN2021a/PwmBox/Emulated Pixhawk/Fin Allocation'
//  '<S4>'   : 'PILAN2021a/PwmBox/Emulated Pixhawk/Servo Commands'
//  '<S5>'   : 'PILAN2021a/PwmBox/Emulated Pixhawk/Fin Allocation/control_allocation'
//  '<S6>'   : 'PILAN2021a/PwmBox/Emulated Pixhawk/Servo Commands/Radians to Degrees'
//  '<S7>'   : 'PILAN2021a/PwmBox/Emulated Pixhawk/Servo Commands/Radians to Degrees1'
//  '<S8>'   : 'PILAN2021a/PwmBox/Emulated Pixhawk/Servo Commands/Radians to Degrees2'
//  '<S9>'   : 'PILAN2021a/PwmBox/Emulated Pixhawk/Servo Commands/Radians to Degrees3'

#endif                                 // RTW_HEADER_PwmBox_h_

//
// File trailer for generated code.
//
// [EOF]
//
