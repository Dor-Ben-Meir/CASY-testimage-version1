//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4log.h
//
// Code generated for Simulink model 'px4log'.
//
// Model version                  : 1.155
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sat May  8 14:47:16 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_px4log_h_
#define RTW_HEADER_px4log_h_
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_PWM.h"
#include "px4log_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
struct B_px4log_T {
  px4_Bus_vehicle_odometry In1;        // '<S41>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_vehicle_local_position In1_p;// '<S18>/In1'
  px4_Bus_vehicle_local_position b_varargout_2_m;
  px4_Bus_vehicle_gps_position In1_c;  // '<S19>/In1'
  px4_Bus_vehicle_gps_position b_varargout_2_c;
  px4_Bus_sensor_accel b_varargout_2_k;
  px4_Bus_sensor_gyro b_varargout_2_cx;
  real_T CastToDouble2[4];             // '<S1>/Cast To Double2'
  uint16_T pwmValue[8];
  real_T scale;
  real_T absxk;
};

// Block states (default storage) for system '<Root>'
struct DW_px4log_T {
  px4_internal_block_Subscriber_T obj; // '<S40>/SourceBlock'
  px4_internal_block_Subscriber_T obj_g;// '<S7>/SourceBlock'
  px4_internal_block_Subscriber_T obj_f;// '<S6>/SourceBlock'
  px4_internal_block_Subscriber_T obj_n;// '<S13>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S11>/SourceBlock'
  px4_internal_block_PWM_px4log_T obj_p;// '<S23>/PX4 PWM Output1'
  real_T DiscreteTransferFcn_states;   // '<S21>/Discrete Transfer Fcn'
  real_T DiscreteTimeIntegrator_PREV_U;// '<S25>/Discrete-Time Integrator'
  real32_T Delay_DSTATE;               // '<S24>/Delay'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S25>/Discrete-Time Integrator'
  int32_T clockTickCounter;            // '<Root>/100 Hz'
  uint32_T Subsystem_PREV_T;           // '<Root>/Subsystem'
  uint16_T Output_DSTATE;              // '<S15>/Output'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S25>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;// '<S25>/Discrete-Time Integrator'
  boolean_T Subsystem_RESET_ELAPS_T;   // '<Root>/Subsystem'
};

// Zero-crossing (trigger) state
struct PrevZCX_px4log_T {
  ZCSigState Subsystem_Trig_ZCE;       // '<Root>/Subsystem'
};

// Parameters (default storage)
struct P_px4log_T_ {
  struct_FuH2ngUSrLPtrZS1Hkt11F Autopilot;// Variable: Autopilot
                                             //  Referenced by:
                                             //    '<S26>/1-D Lookup Table3'
                                             //    '<S26>/1-D Lookup Table4'
                                             //    '<S26>/1-D Lookup Table5'

  uint16_T WrapToZero_Threshold;       // Mask Parameter: WrapToZero_Threshold
                                          //  Referenced by: '<S17>/FixPt Switch'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S41>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S40>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                              //  Referenced by: '<S18>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                     //  Referenced by: '<S6>/Constant'

  px4_Bus_vehicle_gps_position Out1_Y0_b;// Computed Parameter: Out1_Y0_b
                                            //  Referenced by: '<S19>/Out1'

  px4_Bus_vehicle_gps_position Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                   //  Referenced by: '<S7>/Constant'

  struct_P6rP1Gtrz2yB2zz1IAKQCE Imu_Sensors_Y0;// Computed Parameter: Imu_Sensors_Y0
                                                  //  Referenced by: '<S1>/Imu_Sensors'

  struct_phqKDUCYMf8zD1VgkGPMAE Local_Position_Y0;// Computed Parameter: Local_Position_Y0
                                                     //  Referenced by: '<S1>/Local_Position'

  struct_phqKDUCYMf8zD1VgkGPMAE GPS_Data_Y0;// Computed Parameter: GPS_Data_Y0
                                               //  Referenced by: '<S1>/GPS_Data'

  px4_Bus_sensor_accel Out1_Y0_kq;     // Computed Parameter: Out1_Y0_kq
                                          //  Referenced by: '<S12>/Out1'

  px4_Bus_sensor_accel Constant_Value_c;// Computed Parameter: Constant_Value_c
                                           //  Referenced by: '<S11>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_f;       // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S14>/Out1'

  px4_Bus_sensor_gyro Constant_Value_b;// Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S13>/Constant'

  struct_VVhaihDhHy5oT5WqtkJGhD Phi_com_Y0;// Computed Parameter: Phi_com_Y0
                                              //  Referenced by: '<S1>/Phi_com'

  real_T Constant_Value_l;             // Expression: 1
                                          //  Referenced by: '<S35>/Constant'

  real_T Constant_Value_j;             // Expression: 1
                                          //  Referenced by: '<S36>/Constant'

  real_T P_filter_Y0;                  // Computed Parameter: P_filter_Y0
                                          //  Referenced by: '<S1>/P_filter'

  real_T P_Y0;                         // Computed Parameter: P_Y0
                                          //  Referenced by: '<S1>/P'

  real_T Phi_Y0;                       // Computed Parameter: Phi_Y0
                                          //  Referenced by: '<S1>/Phi'

  real_T Velocity_Y0;                  // Computed Parameter: Velocity_Y0
                                          //  Referenced by: '<S1>/Velocity'

  real_T Alt_Y0;                       // Computed Parameter: Alt_Y0
                                          //  Referenced by: '<S1>/Alt'

  real_T A_Y0;                         // Computed Parameter: A_Y0
                                          //  Referenced by: '<S1>/A'

  real_T DiscreteTransferFcn_NumCoef[2];// Expression: [num_lpf_d]
                                           //  Referenced by: '<S21>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [den_lpf_d]
                                           //  Referenced by: '<S21>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S21>/Discrete Transfer Fcn'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S25>/Discrete-Time Integrator'

  real_T Constant2_Value;              // Expression: 0
                                          //  Referenced by: '<S1>/Constant2'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S21>/Zero'

  real_T Gain_Gain;                    // Expression: 180/pi
                                          //  Referenced by: '<S28>/Gain'

  real_T Saturation_UpperSat;          // Expression: 20
                                          //  Referenced by: '<S23>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -20
                                          //  Referenced by: '<S23>/Saturation'

  real_T Gain_Gain_c;                  // Expression: 1000/91
                                          //  Referenced by: '<S23>/Gain'

  real_T One_Value;                    // Expression: 1500
                                          //  Referenced by: '<S23>/One'

  real_T Gain_Gain_l;                  // Expression: 180/pi
                                          //  Referenced by: '<S29>/Gain'

  real_T Saturation1_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S23>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S23>/Saturation1'

  real_T Gain1_Gain;                   // Expression: 1000/91
                                          //  Referenced by: '<S23>/Gain1'

  real_T One1_Value;                   // Expression: 1500
                                          //  Referenced by: '<S23>/One1'

  real_T Gain_Gain_m;                  // Expression: 180/pi
                                          //  Referenced by: '<S30>/Gain'

  real_T Saturation2_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S23>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S23>/Saturation2'

  real_T Gain2_Gain;                   // Expression: 1000/91
                                          //  Referenced by: '<S23>/Gain2'

  real_T One2_Value;                   // Expression: 1500
                                          //  Referenced by: '<S23>/One2'

  real_T Gain_Gain_mt;                 // Expression: 180/pi
                                          //  Referenced by: '<S31>/Gain'

  real_T Saturation3_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S23>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S23>/Saturation3'

  real_T Gain3_Gain;                   // Expression: 1000/91
                                          //  Referenced by: '<S23>/Gain3'

  real_T One3_Value;                   // Expression: 1500
                                          //  Referenced by: '<S23>/One3'

  real_T u00Hz_Amp;                    // Expression: 1
                                          //  Referenced by: '<Root>/100 Hz'

  real_T u00Hz_Period;                 // Computed Parameter: u00Hz_Period
                                          //  Referenced by: '<Root>/100 Hz'

  real_T u00Hz_Duty;                   // Computed Parameter: u00Hz_Duty
                                          //  Referenced by: '<Root>/100 Hz'

  real_T u00Hz_PhaseDelay;             // Expression: 0
                                          //  Referenced by: '<Root>/100 Hz'

  struct_a1AjtOphUHLNf8OXJ9zaQB PWM_Y0;// Computed Parameter: PWM_Y0
                                          //  Referenced by: '<S1>/PWM'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S27>/Constant7'

  real32_T Zero_Value_g;               // Computed Parameter: Zero_Value_g
                                          //  Referenced by: '<S4>/Zero'

  real32_T Delay_InitialCondition; // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S24>/Delay'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S25>/Constant'

  uint32_T uDLookupTable3_maxIndex[2];
                                  // Computed Parameter: uDLookupTable3_maxIndex
                                     //  Referenced by: '<S26>/1-D Lookup Table3'

  uint32_T uDLookupTable5_maxIndex[2];
                                  // Computed Parameter: uDLookupTable5_maxIndex
                                     //  Referenced by: '<S26>/1-D Lookup Table5'

  uint32_T uDLookupTable4_maxIndex[2];
                                  // Computed Parameter: uDLookupTable4_maxIndex
                                     //  Referenced by: '<S26>/1-D Lookup Table4'

  uint16_T Constant_Value_ai;          // Computed Parameter: Constant_Value_ai
                                          //  Referenced by: '<S17>/Constant'

  uint16_T Output_InitialCondition;
                                  // Computed Parameter: Output_InitialCondition
                                     //  Referenced by: '<S15>/Output'

  uint16_T FixPtConstant_Value;       // Computed Parameter: FixPtConstant_Value
                                         //  Referenced by: '<S16>/FixPt Constant'

  boolean_T One5_Value;                // Computed Parameter: One5_Value
                                          //  Referenced by: '<S23>/One5'

  boolean_T One4_Value;                // Computed Parameter: One4_Value
                                          //  Referenced by: '<S23>/One4'

};

// Real-time Model Data Structure
struct tag_RTM_px4log_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_px4log_T px4log_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_px4log_T px4log_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_px4log_T px4log_DW;

// Zero-crossing (trigger) state
extern PrevZCX_px4log_T px4log_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void px4log_initialize(void);
  extern void px4log_step(void);
  extern void px4log_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_px4log_T *const px4log_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S11>/NOT' : Unused code path elimination
//  Block '<S1>/Cast To Double1' : Unused code path elimination
//  Block '<S1>/Cast To Double10' : Unused code path elimination
//  Block '<S1>/Cast To Double11' : Unused code path elimination
//  Block '<S1>/Cast To Double12' : Unused code path elimination
//  Block '<S1>/Cast To Double13' : Unused code path elimination
//  Block '<S1>/Cast To Double14' : Unused code path elimination
//  Block '<S1>/Cast To Double15' : Unused code path elimination
//  Block '<S1>/Cast To Double17' : Unused code path elimination
//  Block '<S1>/Cast To Double18' : Unused code path elimination
//  Block '<S1>/Cast To Double19' : Unused code path elimination
//  Block '<S1>/Cast To Double20' : Unused code path elimination
//  Block '<S1>/Cast To Double21' : Unused code path elimination
//  Block '<S1>/Cast To Double24' : Unused code path elimination
//  Block '<S1>/Cast To Double25' : Unused code path elimination
//  Block '<S1>/Cast To Double26' : Unused code path elimination
//  Block '<S1>/Cast To Double27' : Unused code path elimination
//  Block '<S1>/Cast To Double28' : Unused code path elimination
//  Block '<S1>/Cast To Double3' : Unused code path elimination
//  Block '<S1>/Cast To Double5' : Unused code path elimination
//  Block '<S1>/Cast To Double6' : Unused code path elimination
//  Block '<S1>/Cast To Double7' : Unused code path elimination
//  Block '<S1>/Cast To Double8' : Unused code path elimination
//  Block '<S1>/Cast To Double9' : Unused code path elimination
//  Block '<S13>/NOT' : Unused code path elimination
//  Block '<S15>/FixPt Data Type Propagation' : Unused code path elimination
//  Block '<S16>/FixPt Data Type Duplicate' : Unused code path elimination
//  Block '<S17>/FixPt Data Type Duplicate1' : Unused code path elimination
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S7>/NOT' : Unused code path elimination
//  Block '<S26>/1-D Lookup Table1' : Unused code path elimination
//  Block '<S26>/1-D Lookup Table2' : Unused code path elimination
//  Block '<S26>/1-D Lookup Table6' : Unused code path elimination
//  Block '<S40>/NOT' : Unused code path elimination
//  Block '<S1>/Cast To Double34' : Eliminate redundant data type conversion


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
//  '<Root>' : 'px4log'
//  '<S1>'   : 'px4log/Subsystem'
//  '<S2>'   : 'px4log/Subsystem/Accelerometer'
//  '<S3>'   : 'px4log/Subsystem/Gyroscope'
//  '<S4>'   : 'px4log/Subsystem/Heartbeat Counter'
//  '<S5>'   : 'px4log/Subsystem/MATLAB Function'
//  '<S6>'   : 'px4log/Subsystem/PX4 uORB Read'
//  '<S7>'   : 'px4log/Subsystem/PX4 uORB Read4'
//  '<S8>'   : 'px4log/Subsystem/PixBlock2'
//  '<S9>'   : 'px4log/Subsystem/Quaternions to Rotation Angles2'
//  '<S10>'  : 'px4log/Subsystem/Vehicle Attitude'
//  '<S11>'  : 'px4log/Subsystem/Accelerometer/PX4 uORB Read'
//  '<S12>'  : 'px4log/Subsystem/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S13>'  : 'px4log/Subsystem/Gyroscope/PX4 uORB Read'
//  '<S14>'  : 'px4log/Subsystem/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S15>'  : 'px4log/Subsystem/Heartbeat Counter/Heartbeat'
//  '<S16>'  : 'px4log/Subsystem/Heartbeat Counter/Heartbeat/Increment Real World'
//  '<S17>'  : 'px4log/Subsystem/Heartbeat Counter/Heartbeat/Wrap To Zero'
//  '<S18>'  : 'px4log/Subsystem/PX4 uORB Read/Enabled Subsystem'
//  '<S19>'  : 'px4log/Subsystem/PX4 uORB Read4/Enabled Subsystem'
//  '<S20>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk'
//  '<S21>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Autopilot'
//  '<S22>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Fin Allocation'
//  '<S23>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Servo Commands'
//  '<S24>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Autopilot/100Hz Reset'
//  '<S25>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Autopilot/Phi_Control'
//  '<S26>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Autopilot/Phi_Control/Gain_Lookup'
//  '<S27>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Fin Allocation/control_allocation'
//  '<S28>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Servo Commands/Radians to Degrees'
//  '<S29>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Servo Commands/Radians to Degrees1'
//  '<S30>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Servo Commands/Radians to Degrees2'
//  '<S31>'  : 'px4log/Subsystem/PixBlock2/Emulated Pixhawk/Servo Commands/Radians to Degrees3'
//  '<S32>'  : 'px4log/Subsystem/Quaternions to Rotation Angles2/Angle Calculation'
//  '<S33>'  : 'px4log/Subsystem/Quaternions to Rotation Angles2/Quaternion Normalize'
//  '<S34>'  : 'px4log/Subsystem/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input'
//  '<S35>'  : 'px4log/Subsystem/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S36>'  : 'px4log/Subsystem/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S37>'  : 'px4log/Subsystem/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S38>'  : 'px4log/Subsystem/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus'
//  '<S39>'  : 'px4log/Subsystem/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S40>'  : 'px4log/Subsystem/Vehicle Attitude/PX4 uORB Read'
//  '<S41>'  : 'px4log/Subsystem/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_px4log_h_

//
// File trailer for generated code.
//
// [EOF]
//
