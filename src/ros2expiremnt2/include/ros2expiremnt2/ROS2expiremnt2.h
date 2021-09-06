//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS2expiremnt2.h
//
// Code generated for Simulink model 'ROS2expiremnt2'.
//
// Model version                  : 1.1
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue May 18 11:54:54 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ROS2expiremnt2_h_
#define RTW_HEADER_ROS2expiremnt2_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "ROS2expiremnt2_pubsub_common.h"
#include "ROS2expiremnt2_types.h"
#include "MW_target_hardware_resources.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_ROS2expiremnt2_T {
  char_T b_zeroDelimTopic[32];
};

// Block states (default storage) for system '<Root>'
struct DW_ROS2expiremnt2_T {
  ros_slros2_internal_block_Pub_T obj; // '<S3>/SinkBlock'
  ros_slros2_internal_block_Sub_T obj_n;// '<S4>/SourceBlock'
};

// Parameters (default storage)
struct P_ROS2expiremnt2_T_ {
  SL_Bus_px4_msgs_SensorCombined Out1_Y0;// Computed Parameter: Out1_Y0
                                            //  Referenced by: '<S5>/Out1'

  SL_Bus_px4_msgs_SensorCombined Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S4>/Constant'

  SL_Bus_px4_msgs_OffboardControlMode Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                          //  Referenced by: '<S1>/Constant'

  boolean_T Constant_Value_a;          // Computed Parameter: Constant_Value_a
                                          //  Referenced by: '<Root>/Constant'

  uint8_T Out1_Y0_m;                   // Computed Parameter: Out1_Y0_m
                                          //  Referenced by: '<S2>/Out1'

};

// Real-time Model Data Structure
struct tag_RTM_ROS2expiremnt2_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ROS2expiremnt2_T ROS2expiremnt2_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_ROS2expiremnt2_T ROS2expiremnt2_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_ROS2expiremnt2_T ROS2expiremnt2_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ROS2expiremnt2_initialize(void);
  extern void ROS2expiremnt2_step(void);
  extern void ROS2expiremnt2_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ROS2expiremnt2_T *const ROS2expiremnt2_M;

#ifdef __cplusplus

}
#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Display' : Unused code path elimination


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
//  '<Root>' : 'ROS2expiremnt2'
//  '<S1>'   : 'ROS2expiremnt2/Blank Message'
//  '<S2>'   : 'ROS2expiremnt2/Enabled Subsystem'
//  '<S3>'   : 'ROS2expiremnt2/Publish'
//  '<S4>'   : 'ROS2expiremnt2/Subscribe'
//  '<S5>'   : 'ROS2expiremnt2/Subscribe/Enabled Subsystem'

#endif                                 // RTW_HEADER_ROS2expiremnt2_h_

//
// File trailer for generated code.
//
// [EOF]
//
