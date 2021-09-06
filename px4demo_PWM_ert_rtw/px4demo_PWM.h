//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_PWM.h
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
#ifndef RTW_HEADER_px4demo_PWM_h_
#define RTW_HEADER_px4demo_PWM_h_
#include <string.h>
#include <stddef.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "px4demo_PWM_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_px4demo_PWM_T {
  px4_Bus_actuator_outputs b_varargout_2;
};

// Block states (default storage) for system '<Root>'
struct DW_px4demo_PWM_T {
  px4_internal_block_PWM_px4dem_T obj; // '<Root>/PX4 PWM Output1'
  px4_internal_block_PWM_px4dem_T obj_i;// '<Root>/PX4 PWM Output'
  px4_internal_block_Subscriber_T obj_l;// '<S1>/SourceBlock'
};

// Parameters (default storage)
struct P_px4demo_PWM_T_ {
  px4_Bus_actuator_outputs Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S2>/Out1'

  px4_Bus_actuator_outputs Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S1>/Constant'

  uint16_T MAINPWMCh12value_Value; // Computed Parameter: MAINPWMCh12value_Value
                                      //  Referenced by: '<Root>/MAIN PWM Ch 1,2 value'

  uint16_T AUXPWMCh1234value_Value;
                                  // Computed Parameter: AUXPWMCh1234value_Value
                                     //  Referenced by: '<Root>/AUX PWM Ch 1,2,3,4 value'

  boolean_T ARMPWM_Value;              // Computed Parameter: ARMPWM_Value
                                          //  Referenced by: '<Root>/ARM PWM'

  boolean_T failsafe_Value;            // Computed Parameter: failsafe_Value
                                          //  Referenced by: '<Root>/failsafe'

  boolean_T failsafe1_Value;           // Computed Parameter: failsafe1_Value
                                          //  Referenced by: '<Root>/failsafe1'

};

// Real-time Model Data Structure
struct tag_RTM_px4demo_PWM_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_px4demo_PWM_T px4demo_PWM_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_px4demo_PWM_T px4demo_PWM_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_px4demo_PWM_T px4demo_PWM_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void px4demo_PWM_initialize(void);
  extern void px4demo_PWM_step(void);
  extern void px4demo_PWM_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_px4demo_PWM_T *const px4demo_PWM_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display' : Unused code path elimination
//  Block '<S1>/NOT' : Unused code path elimination
//  Block '<Root>/Signal Conversion' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'px4demo_PWM'
//  '<S1>'   : 'px4demo_PWM/PX4 uORB Read'
//  '<S2>'   : 'px4demo_PWM/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_px4demo_PWM_h_

//
// File trailer for generated code.
//
// [EOF]
//
