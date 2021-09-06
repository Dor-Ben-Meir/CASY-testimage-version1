//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GPS32.h
//
// Code generated for Simulink model 'GPS32'.
//
// Model version                  : 1.153
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  9 18:57:43 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_GPS32_h_
#define RTW_HEADER_GPS32_h_
#include <stddef.h>
#include <drivers/drv_hrt.h>
#include <stdio.h>
#include <time.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_uORB_Read.h"
#include "GPS32_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_GPS32_T {
  px4_Bus_vehicle_local_position b_varargout_2;
  px4_Bus_vehicle_gps_position b_varargout_2_m;
};

// Block states (default storage) for system '<Root>'
struct DW_GPS32_T {
  px4_internal_block_Subscriber_T obj; // '<S3>/SourceBlock'
  px4_internal_block_Subscriber_T obj_i;// '<S2>/SourceBlock'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_GPS32_T {
  real_T Out1;                         // '<Root>/Out1'
};

// Parameters (default storage)
struct P_GPS32_T_ {
  px4_Bus_vehicle_local_position Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S4>/Out1'

  px4_Bus_vehicle_local_position Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S2>/Constant'

  px4_Bus_vehicle_gps_position Out1_Y0_f;// Computed Parameter: Out1_Y0_f
                                            //  Referenced by: '<S5>/Out1'

  px4_Bus_vehicle_gps_position Constant_Value_b;// Computed Parameter: Constant_Value_b
                                                   //  Referenced by: '<S3>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_GPS32_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_GPS32_T GPS32_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_GPS32_T GPS32_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_GPS32_T GPS32_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // External outputs (root outports fed by signals with default storage)
  extern struct ExtY_GPS32_T GPS32_Y;

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void GPS32_initialize(void);
  extern void GPS32_step(void);
  extern void GPS32_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_GPS32_T *const GPS32_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Cast To Double1' : Unused code path elimination
//  Block '<Root>/Cast To Double11' : Unused code path elimination
//  Block '<Root>/Cast To Double17' : Unused code path elimination
//  Block '<Root>/Cast To Double21' : Unused code path elimination
//  Block '<Root>/Cast To Double24' : Unused code path elimination
//  Block '<Root>/Cast To Double25' : Unused code path elimination
//  Block '<Root>/Cast To Double26' : Unused code path elimination
//  Block '<Root>/Cast To Double27' : Unused code path elimination
//  Block '<Root>/Cast To Double28' : Unused code path elimination
//  Block '<Root>/Cast To Double3' : Unused code path elimination
//  Block '<Root>/Cast To Double33' : Unused code path elimination
//  Block '<Root>/Cast To Double4' : Unused code path elimination
//  Block '<Root>/Cast To Double5' : Unused code path elimination
//  Block '<Root>/Cast To Double6' : Unused code path elimination
//  Block '<Root>/Cast To Double7' : Unused code path elimination
//  Block '<Root>/Cast To Double8' : Unused code path elimination
//  Block '<Root>/Cast To Double9' : Unused code path elimination
//  Block '<S2>/NOT' : Unused code path elimination
//  Block '<S3>/NOT' : Unused code path elimination


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
//  '<Root>' : 'GPS32'
//  '<S1>'   : 'GPS32/MATLAB Function'
//  '<S2>'   : 'GPS32/PX4 uORB Read1'
//  '<S3>'   : 'GPS32/PX4 uORB Read2'
//  '<S4>'   : 'GPS32/PX4 uORB Read1/Enabled Subsystem'
//  '<S5>'   : 'GPS32/PX4 uORB Read2/Enabled Subsystem'

#endif                                 // RTW_HEADER_GPS32_h_

//
// File trailer for generated code.
//
// [EOF]
//
