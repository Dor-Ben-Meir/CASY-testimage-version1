//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: g232F.h
//
// Code generated for Simulink model 'g232F'.
//
// Model version                  : 1.140
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Apr 15 15:32:05 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_g232F_h_
#define RTW_HEADER_g232F_h_
#include <math.h>
#include <stddef.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_uORB_Read.h"
#include "g232F_types.h"
#include "rt_defines.h"
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
struct B_g232F_T {
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_sensor_accel b_varargout_2_m;
};

// Block states (default storage) for system '<Root>'
struct DW_g232F_T {
  px4_internal_block_Subscriber_T obj; // '<S17>/SourceBlock'
  px4_internal_block_Subscriber_T obj_b;// '<S7>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S5>/SourceBlock'
};

// Parameters (default storage)
struct P_g232F_T_ {
  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S18>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S17>/Constant'

  px4_Bus_sensor_accel Out1_Y0_o;      // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S6>/Out1'

  px4_Bus_sensor_accel Constant_Value_h;// Computed Parameter: Constant_Value_h
                                           //  Referenced by: '<S5>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_f;       // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S8>/Out1'

  px4_Bus_sensor_gyro Constant_Value_f;// Computed Parameter: Constant_Value_f
                                          //  Referenced by: '<S7>/Constant'

  real_T Constant_Value_c;             // Expression: 1
                                          //  Referenced by: '<S12>/Constant'

  real_T Constant_Value_n;             // Expression: 1
                                          //  Referenced by: '<S13>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_g232F_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_g232F_T g232F_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_g232F_T g232F_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_g232F_T g232F_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void g232F_initialize(void);
  extern void g232F_step(void);
  extern void g232F_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_g232F_T *const g232F_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S5>/NOT' : Unused code path elimination
//  Block '<Root>/Cast To Double10' : Unused code path elimination
//  Block '<Root>/Cast To Double12' : Unused code path elimination
//  Block '<Root>/Cast To Double13' : Unused code path elimination
//  Block '<Root>/Cast To Double14' : Unused code path elimination
//  Block '<Root>/Cast To Double15' : Unused code path elimination
//  Block '<Root>/Cast To Double16' : Unused code path elimination
//  Block '<Root>/Cast To Double18' : Unused code path elimination
//  Block '<Root>/Cast To Double19' : Unused code path elimination
//  Block '<Root>/Cast To Double20' : Unused code path elimination
//  Block '<Root>/Cast To Double22' : Unused code path elimination
//  Block '<S7>/NOT' : Unused code path elimination
//  Block '<S17>/NOT' : Unused code path elimination


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
//  '<Root>' : 'g232F'
//  '<S1>'   : 'g232F/Accelerometer2'
//  '<S2>'   : 'g232F/Gyroscope2'
//  '<S3>'   : 'g232F/Quaternions to Rotation Angles2'
//  '<S4>'   : 'g232F/Vehicle Attitude2'
//  '<S5>'   : 'g232F/Accelerometer2/PX4 uORB Read'
//  '<S6>'   : 'g232F/Accelerometer2/PX4 uORB Read/Enabled Subsystem'
//  '<S7>'   : 'g232F/Gyroscope2/PX4 uORB Read'
//  '<S8>'   : 'g232F/Gyroscope2/PX4 uORB Read/Enabled Subsystem'
//  '<S9>'   : 'g232F/Quaternions to Rotation Angles2/Angle Calculation'
//  '<S10>'  : 'g232F/Quaternions to Rotation Angles2/Quaternion Normalize'
//  '<S11>'  : 'g232F/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input'
//  '<S12>'  : 'g232F/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S13>'  : 'g232F/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S14>'  : 'g232F/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S15>'  : 'g232F/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus'
//  '<S16>'  : 'g232F/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S17>'  : 'g232F/Vehicle Attitude2/PX4 uORB Read'
//  '<S18>'  : 'g232F/Vehicle Attitude2/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_g232F_h_

//
// File trailer for generated code.
//
// [EOF]
//
