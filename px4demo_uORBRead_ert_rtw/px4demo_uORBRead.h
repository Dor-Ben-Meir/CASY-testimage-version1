//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_uORBRead.h
//
// Code generated for Simulink model 'px4demo_uORBRead'.
//
// Model version                  : 4.32
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May 23 15:24:02 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_px4demo_uORBRead_h_
#define RTW_HEADER_px4demo_uORBRead_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <drivers/drv_hrt.h>
#include <stdio.h>
#include <time.h>
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "MW_uORB_Read.h"
#include "MW_uORB_Write.h"
#include "MW_PX4_PWM.h"
#include "MW_Parameter.h"
#include "MW_ParameterRead.h"
#include "px4demo_uORBRead_types.h"
#include "rt_zcfcn.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

// Block signals (default storage)
struct B_px4demo_uORBRead_T {
  real_T TmpSignalConversionAtSFunct[40];// '<S68>/SDCard_logger'
  px4_Bus_vehicle_odometry In1;        // '<S73>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_vehicle_local_position In1_p;// '<S18>/In1'
  px4_Bus_vehicle_local_position b_varargout_2_m;
  px4_Bus_vehicle_gps_position In1_m;  // '<S17>/In1'
  px4_Bus_vehicle_gps_position b_varargout_2_c;
  real_T csumrev[9];
  px4_Bus_mavlink_log BusAssignment;   // '<S11>/Bus Assignment'
  px4_Bus_mavlink_log BusAssignment_k; // '<S11>/Bus Assignment'
  px4_Bus_sensor_accel b_varargout_2_cx;
  px4_Bus_sensor_gyro In1_h;           // '<S16>/In1'
  px4_Bus_sensor_accel In1_k;          // '<S14>/In1'
  real_T CastToDouble3[10];            // '<S19>/Cast To Double3'
  px4_Bus_sensor_gyro b_varargout_2_b;
  char_T b[56];
  char_T cv[50];
  px4_Bus_debug_vect BusAssignment1;   // '<Root>/Bus Assignment1'
  px4_Bus_debug_vect BusAssignment1_p; // '<Root>/Bus Assignment1'
  real_T siB_cmd[4];                   // '<S27>/Product'
  char_T e[28];
  char_T c[24];
  char_T ParameterNameStr[17];
  uint16_T pwmValue[8];
  real_T scale;
  real_T absxk;
  real_T t;
  real_T cumRevIndex;
  real_T csum;
  real_T z;
  real_T y;                            // '<Root>/MATLAB Function'
  real_T u00Hz;                        // '<S8>/100 Hz'
  real_T CastToDouble18;               // '<Root>/Cast To Double18'
  real_T fcn3;                         // '<S9>/fcn3'
  real_T CastToDouble8;                // '<Root>/Cast To Double8'
  real_T CastToDouble6;                // '<Root>/Cast To Double6'
  real_T rtb_VectorConcatenate_idx_2;
  real_T rtb_Switch_l_idx_0;
  real_T rtb_Switch_l_idx_1;
  real_T rtb_Switch_l_idx_2;
  real_T rtb_Switch_l_idx_3;
  real_T rtb_fin_cmd_idx_0;
  real_T numAccum;
  real_T rtb_VectorConcatenate_idx_2_tmp;
  real32_T RateTransition;             // '<Root>/Rate Transition'
  int32_T RateTransition1;             // '<Root>/Rate Transition1'
};

// Block states (default storage) for system '<Root>'
struct DW_px4demo_uORBRead_T {
  dsp_simulink_MovingAverage_px_T obj; // '<S28>/Moving Average1'
  px4_internal_block_ParameterU_T obj_h;// '<Root>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_i;// '<Root>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_p;// '<Root>/Read Parameter'
  px4_internal_block_Subscriber_T obj_ph;// '<S72>/SourceBlock'
  px4_internal_block_Subscriber_T obj_hy;// '<S6>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S5>/SourceBlock'
  px4_internal_block_Subscriber_T obj_g;// '<S15>/SourceBlock'
  px4_internal_block_Subscriber_T obj_n;// '<S13>/SourceBlock'
  px4_internal_block_PWM_px4dem_T obj_hi;// '<S23>/PX4 PWM Output1'
  px4_internal_block_Publisher__T obj_o;// '<S71>/SinkBlock'
  px4_internal_block_Publisher__T obj_e;// '<S7>/SinkBlock'
  real_T DiscreteTransferFcn_states;   // '<S20>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn_states_i; // '<S19>/Discrete Transfer Fcn'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S41>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_c;// '<S46>/Discrete-Time Integrator'
  real_T DelayInput1_DSTATE;           // '<S36>/Delay Input1'
  real_T DiscreteTimeIntegrator_DSTATE_b;// '<S37>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_k;// '<S50>/Discrete-Time Integrator'
  real_T RateTransition2_4_Buffer[10]; // '<Root>/Rate Transition2'
  real_T RateTransition2_2_Buffer[12]; // '<Root>/Rate Transition2'
  real_T RateTransition2_3_Buffer[9];  // '<Root>/Rate Transition2'
  real_T RateTransition2_1_Buffer[9];  // '<Root>/Rate Transition2'
  real_T DiscreteTimeIntegrator_PREV_U;// '<S25>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_e;// '<S41>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_o;// '<S46>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_d;// '<S37>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_h;// '<S50>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_kw;// '<S25>/Discrete-Time Integrator'
  real32_T RateTransition_Buffer0;     // '<Root>/Rate Transition'
  real32_T RateTransition3_Buffer0;    // '<Root>/Rate Transition3'
  int32_T RateTransition1_Buffer0;     // '<Root>/Rate Transition1'
  int32_T clockTickCounter;            // '<S8>/100 Hz'
  uint32_T count;                      // '<S68>/SDCard_logger'
  uint32_T EmulatedPixhawk_PREV_T;     // '<S8>/Emulated Pixhawk'
  uint16_T elem_size;                  // '<S68>/SDCard_logger'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S25>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_f;// '<S41>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_i;// '<S46>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_ia;// '<S37>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevR_iv;// '<S50>/Discrete-Time Integrator'
  uint8_T vect_size;                   // '<S68>/SDCard_logger'
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;// '<S25>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_m;// '<S41>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_j;// '<S46>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTE_jm;// '<S37>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_o;// '<S50>/Discrete-Time Integrator'
  boolean_T RateTransition4_Buffer;    // '<Root>/Rate Transition4'
  boolean_T isflushed;                 // '<S68>/SDCard_logger'
  boolean_T isopen;                    // '<S68>/SDCard_logger'
  boolean_T count_not_empty;           // '<S68>/SDCard_logger'
  boolean_T EmulatedPixhawk_RESET_ELAPS_T;// '<S8>/Emulated Pixhawk'
  boolean_T Memory_PreviousInput;      // '<S30>/Memory'
  boolean_T Memory_PreviousInput_a;    // '<S42>/Memory'
  boolean_T Memory_PreviousInput_o;    // '<S47>/Memory'
  boolean_T Memory_PreviousInput_d;    // '<S38>/Memory'
  boolean_T Memory_PreviousInput_b;    // '<S51>/Memory'
  FILE* fp;                            // '<S68>/SDCard_logger'
};

// Zero-crossing (trigger) state
struct PrevZCX_px4demo_uORBRead_T {
  ZCSigState EmulatedPixhawk_Trig_ZCE; // '<S8>/Emulated Pixhawk'
};

// Parameters (default storage)
struct P_px4demo_uORBRead_T_ {
  struct_FuH2ngUSrLPtrZS1Hkt11F Autopilot;// Variable: Autopilot
                                             //  Referenced by:
                                             //    '<S26>/1-D Lookup Table3'
                                             //    '<S26>/1-D Lookup Table4'
                                             //    '<S26>/1-D Lookup Table5'

  struct_KbuHZdFirwgp0Ajtitq2dC Flight_Logic;// Variable: Flight_Logic
                                                //  Referenced by:
                                                //    '<S32>/Constant'
                                                //    '<S34>/Constant'
                                                //    '<S35>/Constant'
                                                //    '<S39>/Constant'
                                                //    '<S40>/Constant'
                                                //    '<S43>/Constant'
                                                //    '<S45>/Constant'
                                                //    '<S48>/Constant'
                                                //    '<S49>/Constant'

  real_T CompareToConstant2_const;   // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S44>/Constant'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S33>/Constant'

  real_T DetectDecrease_vinit;         // Mask Parameter: DetectDecrease_vinit
                                          //  Referenced by: '<S36>/Delay Input1'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S73>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S72>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                              //  Referenced by: '<S18>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                     //  Referenced by: '<S6>/Constant'

  px4_Bus_vehicle_gps_position Out1_Y0_hz;// Computed Parameter: Out1_Y0_hz
                                             //  Referenced by: '<S17>/Out1'

  px4_Bus_vehicle_gps_position Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                   //  Referenced by: '<S5>/Constant'

  px4_Bus_mavlink_log Constant_Value_n;// Computed Parameter: Constant_Value_n
                                          //  Referenced by: '<S70>/Constant'

  px4_Bus_sensor_accel Out1_Y0_hh;     // Computed Parameter: Out1_Y0_hh
                                          //  Referenced by: '<S14>/Out1'

  px4_Bus_sensor_accel Constant_Value_h;// Computed Parameter: Constant_Value_h
                                           //  Referenced by: '<S13>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_c;       // Computed Parameter: Out1_Y0_c
                                          //  Referenced by: '<S16>/Out1'

  px4_Bus_sensor_gyro Constant_Value_o;// Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S15>/Constant'

  px4_Bus_debug_vect Constant_Value_k; // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S4>/Constant'

  real_T Constant4_Value;              // Expression: 600
                                          //  Referenced by: '<S29>/Constant4'

  real_T Constant6_Value;              // Expression: 500
                                          //  Referenced by: '<S29>/Constant6'

  real_T Constant3_Value;              // Expression: 400
                                          //  Referenced by: '<S29>/Constant3'

  real_T Constant2_Value;              // Expression: 300
                                          //  Referenced by: '<S29>/Constant2'

  real_T Constant1_Value;              // Expression: 200
                                          //  Referenced by: '<S29>/Constant1'

  real_T Constant_Value_k0;            // Expression: 1
                                          //  Referenced by: '<S29>/Constant'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S22>/Constant5'

  real_T Constant5_Value_n;            // Expression: 0
                                          //  Referenced by: '<S29>/Constant5'

  real_T Constant_Value_hl;            // Expression: 0
                                          //  Referenced by: '<S30>/Constant'

  real_T One5_Value;                   // Expression: 2000
                                          //  Referenced by: '<S23>/One5'

  real_T One6_Value;                   // Expression: 1000
                                          //  Referenced by: '<S23>/One6'

  real_T One1_Value;                   // Expression: 1
                                          //  Referenced by: '<S19>/One1'

  real_T One2_Value;                   // Expression: 0
                                          //  Referenced by: '<S19>/One2'

  real_T One5_Value_e;                 // Expression: 5
                                          //  Referenced by: '<S24>/One5'

  real_T Gain1_Gain;                   // Expression: pi/180
                                          //  Referenced by: '<S56>/Gain1'

  real_T One6_Value_p;                 // Expression: 5
                                          //  Referenced by: '<S24>/One6'

  real_T Gain1_Gain_m;                 // Expression: pi/180
                                          //  Referenced by: '<S57>/Gain1'

  real_T One7_Value;                   // Expression: 5
                                          //  Referenced by: '<S24>/One7'

  real_T Gain1_Gain_l;                 // Expression: pi/180
                                          //  Referenced by: '<S58>/Gain1'

  real_T One8_Value;                   // Expression: 5
                                          //  Referenced by: '<S24>/One8'

  real_T Gain1_Gain_k;                 // Expression: pi/180
                                          //  Referenced by: '<S59>/Gain1'

  real_T Pix_Out_Y0;                   // Computed Parameter: Pix_Out_Y0
                                          //  Referenced by: '<S19>/Pix_Out'

  real_T DiscreteTransferFcn_NumCoef[2];// Expression: [num_lpf_d]
                                           //  Referenced by: '<S20>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [den_lpf_d]
                                           //  Referenced by: '<S20>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S20>/Discrete Transfer Fcn'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S25>/Discrete-Time Integrator'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S20>/Zero'

  real_T DiscreteTransferFcn_NumCoef_b[2];// Expression: [num_lpf_d]
                                             //  Referenced by: '<S19>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_l[2];// Expression: [den_lpf_d]
                                             //  Referenced by: '<S19>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_g;// Expression: 0
                                            //  Referenced by: '<S19>/Discrete Transfer Fcn'

  real_T Constant1_Value_p;            // Expression: 0
                                          //  Referenced by: '<S41>/Constant1'

  real_T DiscreteTimeIntegrator_gainva_p;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_p
                             //  Referenced by: '<S41>/Discrete-Time Integrator'

  real_T Constant1_Value_m;            // Expression: 0
                                          //  Referenced by: '<S46>/Constant1'

  real_T DiscreteTimeIntegrator_gainva_h;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_h
                             //  Referenced by: '<S46>/Discrete-Time Integrator'

  real_T Constant1_Value_i;            // Expression: 0
                                          //  Referenced by: '<S37>/Constant1'

  real_T DiscreteTimeIntegrator_gainva_n;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_n
                             //  Referenced by: '<S37>/Discrete-Time Integrator'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S50>/Constant1'

  real_T DiscreteTimeIntegrator_gainva_b;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_b
                             //  Referenced by: '<S50>/Discrete-Time Integrator'

  real_T Gain_Gain;                    // Expression: 180/pi
                                          //  Referenced by: '<S52>/Gain'

  real_T Saturation_UpperSat;          // Expression: 20
                                          //  Referenced by: '<S23>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -20
                                          //  Referenced by: '<S23>/Saturation'

  real_T Gain_Gain_n;                  // Expression: 1000/91
                                          //  Referenced by: '<S23>/Gain'

  real_T One_Value;                    // Expression: 900
                                          //  Referenced by: '<S23>/One'

  real_T Gain_Gain_d;                  // Expression: 180/pi
                                          //  Referenced by: '<S53>/Gain'

  real_T Saturation1_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S23>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S23>/Saturation1'

  real_T Gain1_Gain_f;                 // Expression: 1000/91
                                          //  Referenced by: '<S23>/Gain1'

  real_T One1_Value_f;                 // Expression: 900
                                          //  Referenced by: '<S23>/One1'

  real_T Gain_Gain_c;                  // Expression: 180/pi
                                          //  Referenced by: '<S54>/Gain'

  real_T Saturation2_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S23>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S23>/Saturation2'

  real_T Gain2_Gain;                   // Expression: 1000/91
                                          //  Referenced by: '<S23>/Gain2'

  real_T One2_Value_j;                 // Expression: 900
                                          //  Referenced by: '<S23>/One2'

  real_T Gain_Gain_f;                  // Expression: 180/pi
                                          //  Referenced by: '<S55>/Gain'

  real_T Saturation3_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S23>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S23>/Saturation3'

  real_T Gain3_Gain;                   // Expression: 1000/91
                                          //  Referenced by: '<S23>/Gain3'

  real_T One3_Value;                   // Expression: 900
                                          //  Referenced by: '<S23>/One3'

  real_T Constant_Value_c;             // Expression: 1
                                          //  Referenced by: '<S37>/Constant'

  real_T Constant_Value_ct;            // Expression: 1
                                          //  Referenced by: '<S41>/Constant'

  real_T Constant_Value_oz;            // Expression: 1
                                          //  Referenced by: '<S46>/Constant'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<S50>/Constant'

  real_T Constant_Value_l;             // Expression: 1
                                          //  Referenced by: '<S63>/Constant'

  real_T Constant_Value_d;             // Expression: 1
                                          //  Referenced by: '<S64>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: 1
                                          //  Referenced by: '<Root>/Read Parameter'

  real_T ReadParameter1_SampleTime;    // Expression: 1
                                          //  Referenced by: '<Root>/Read Parameter1'

  real_T ReadParameter2_SampleTime;    // Expression: 1
                                          //  Referenced by: '<Root>/Read Parameter2'

  real_T Constant2_Value_c;            // Expression: 0
                                          //  Referenced by: '<Root>/Constant2'

  real_T u00Hz_Amp;                    // Expression: 1
                                          //  Referenced by: '<S8>/100 Hz'

  real_T u00Hz_Period;                 // Computed Parameter: u00Hz_Period
                                          //  Referenced by: '<S8>/100 Hz'

  real_T u00Hz_Duty;                   // Computed Parameter: u00Hz_Duty
                                          //  Referenced by: '<S8>/100 Hz'

  real_T u00Hz_PhaseDelay;             // Expression: 0
                                          //  Referenced by: '<S8>/100 Hz'

  char_T StringConstant_String[256];// Computed Parameter: StringConstant_String
                                       //  Referenced by: '<S11>/String Constant'

  int32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition1'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S27>/Constant7'

  real32_T Constant_Value_oa;          // Computed Parameter: Constant_Value_oa
                                          //  Referenced by: '<S25>/Constant'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<Root>/Rate Transition'

  real32_T RateTransition3_InitialConditio;
                          // Computed Parameter: RateTransition3_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition3'

  uint32_T uDLookupTable3_maxIndex[2];
                                  // Computed Parameter: uDLookupTable3_maxIndex
                                     //  Referenced by: '<S26>/1-D Lookup Table3'

  uint32_T uDLookupTable5_maxIndex[2];
                                  // Computed Parameter: uDLookupTable5_maxIndex
                                     //  Referenced by: '<S26>/1-D Lookup Table5'

  uint32_T uDLookupTable4_maxIndex[2];
                                  // Computed Parameter: uDLookupTable4_maxIndex
                                     //  Referenced by: '<S26>/1-D Lookup Table4'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S30>/Memory'

  boolean_T Memory_InitialCondition_d;
                                // Computed Parameter: Memory_InitialCondition_d
                                   //  Referenced by: '<S42>/Memory'

  boolean_T Memory_InitialCondition_b;
                                // Computed Parameter: Memory_InitialCondition_b
                                   //  Referenced by: '<S47>/Memory'

  boolean_T Memory_InitialCondition_o;
                                // Computed Parameter: Memory_InitialCondition_o
                                   //  Referenced by: '<S38>/Memory'

  boolean_T Memory_InitialCondition_m;
                                // Computed Parameter: Memory_InitialCondition_m
                                   //  Referenced by: '<S51>/Memory'

  boolean_T One7_Value_b;              // Computed Parameter: One7_Value_b
                                          //  Referenced by: '<S23>/One7'

  boolean_T One4_Value;                // Computed Parameter: One4_Value
                                          //  Referenced by: '<S23>/One4'

  uint8_T Constant_Value_cd;           // Computed Parameter: Constant_Value_cd
                                          //  Referenced by: '<S11>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_px4demo_uORBRead_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    struct {
      uint16_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_px4demo_uORBRead_T px4demo_uORBRead_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_px4demo_uORBRead_T px4demo_uORBRead_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_px4demo_uORBRead_T px4demo_uORBRead_DW;

// Zero-crossing (trigger) state
extern PrevZCX_px4demo_uORBRead_T px4demo_uORBRead_PrevZCX;

// External function called from main
#ifdef __cplusplus

extern "C" {

#endif

  extern void px4demo_uORBRead_SetEventsForThisBaseStep(boolean_T *eventFlags);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void px4demo_uORBRead_SetEventsForThisBaseStep(boolean_T *eventFlags);
  extern void px4demo_uORBRead_initialize(void);
  extern void px4demo_uORBRead_step0(void);
  extern void px4demo_uORBRead_step1(void);
  extern void px4demo_uORBRead_step(int_T tid);
  extern void px4demo_uORBRead_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_px4demo_uORBRead_T *const px4demo_uORBRead_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S13>/NOT' : Unused code path elimination
//  Block '<Root>/Cast To Double36' : Unused code path elimination
//  Block '<S15>/NOT' : Unused code path elimination
//  Block '<S5>/NOT' : Unused code path elimination
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S26>/1-D Lookup Table1' : Unused code path elimination
//  Block '<S26>/1-D Lookup Table2' : Unused code path elimination
//  Block '<S26>/1-D Lookup Table6' : Unused code path elimination
//  Block '<S19>/Cast To Double5' : Unused code path elimination
//  Block '<S19>/One6' : Unused code path elimination
//  Block '<S19>/Switch2' : Unused code path elimination
//  Block '<S72>/NOT' : Unused code path elimination
//  Block '<Root>/Cast To Double21' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double22' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double23' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double32' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double33' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double34' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double35' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double37' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double38' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double39' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double40' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double41' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double42' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double43' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double44' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double45' : Eliminate redundant data type conversion
//  Block '<Root>/Cast To Double46' : Eliminate redundant data type conversion
//  Block '<S19>/Cast To Double1' : Eliminate redundant data type conversion
//  Block '<S19>/Cast To Double2' : Eliminate redundant data type conversion
//  Block '<S19>/Cast To Double4' : Eliminate redundant data type conversion
//  Block '<S19>/Cast To Double40' : Eliminate redundant data type conversion
//  Block '<S19>/Cast To Double6' : Eliminate redundant data type conversion
//  Block '<S24>/Cast To Double1' : Eliminate redundant data type conversion
//  Block '<S24>/Cast To Double2' : Eliminate redundant data type conversion
//  Block '<S24>/Cast To Double3' : Eliminate redundant data type conversion
//  Block '<S24>/Cast To Double6' : Eliminate redundant data type conversion
//  Block '<S10>/Cast To Double23' : Eliminate redundant data type conversion
//  Block '<S10>/Cast To Double32' : Eliminate redundant data type conversion
//  Block '<S10>/Cast To Double35' : Eliminate redundant data type conversion
//  Block '<S10>/Cast To Double39' : Eliminate redundant data type conversion


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
//  '<Root>' : 'px4demo_uORBRead'
//  '<S1>'   : 'px4demo_uORBRead/Accelerometer'
//  '<S2>'   : 'px4demo_uORBRead/Gyroscope'
//  '<S3>'   : 'px4demo_uORBRead/MATLAB Function'
//  '<S4>'   : 'px4demo_uORBRead/PX4 uORB Message'
//  '<S5>'   : 'px4demo_uORBRead/PX4 uORB Read'
//  '<S6>'   : 'px4demo_uORBRead/PX4 uORB Read1'
//  '<S7>'   : 'px4demo_uORBRead/PX4 uORB Write'
//  '<S8>'   : 'px4demo_uORBRead/PixBlock2'
//  '<S9>'   : 'px4demo_uORBRead/Quaternions to Rotation Angles2'
//  '<S10>'  : 'px4demo_uORBRead/Subsystem1'
//  '<S11>'  : 'px4demo_uORBRead/Subsystem2'
//  '<S12>'  : 'px4demo_uORBRead/Vehicle Attitude'
//  '<S13>'  : 'px4demo_uORBRead/Accelerometer/PX4 uORB Read'
//  '<S14>'  : 'px4demo_uORBRead/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S15>'  : 'px4demo_uORBRead/Gyroscope/PX4 uORB Read'
//  '<S16>'  : 'px4demo_uORBRead/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S17>'  : 'px4demo_uORBRead/PX4 uORB Read/Enabled Subsystem'
//  '<S18>'  : 'px4demo_uORBRead/PX4 uORB Read1/Enabled Subsystem'
//  '<S19>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk'
//  '<S20>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Autopilot'
//  '<S21>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Fin Allocation'
//  '<S22>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic'
//  '<S23>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Servo Commands1'
//  '<S24>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Subsystem1'
//  '<S25>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Autopilot/Phi_Control'
//  '<S26>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Autopilot/Phi_Control/Gain_Lookup'
//  '<S27>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Fin Allocation/control_allocation'
//  '<S28>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic'
//  '<S29>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Enumeration'
//  '<S30>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic'
//  '<S31>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic'
//  '<S32>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic'
//  '<S33>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Compare To Constant'
//  '<S34>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Compare To Constant1'
//  '<S35>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Compare To Constant3'
//  '<S36>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Detect Decrease'
//  '<S37>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Enable_Timer_Logic'
//  '<S38>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Latch_Signal'
//  '<S39>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic/Compare To Constant'
//  '<S40>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic/Compare To Constant1'
//  '<S41>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic/Enable_Timer_Logic'
//  '<S42>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic/Latch_Signal'
//  '<S43>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Compare To Constant1'
//  '<S44>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Compare To Constant2'
//  '<S45>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Compare To Constant3'
//  '<S46>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Enable_Timer_Logic'
//  '<S47>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Latch_Signal'
//  '<S48>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic/Compare To Constant1'
//  '<S49>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic/Compare To Constant3'
//  '<S50>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic/Enable_Timer_Logic'
//  '<S51>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic/Latch_Signal'
//  '<S52>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Servo Commands1/Radians to Degrees'
//  '<S53>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Servo Commands1/Radians to Degrees1'
//  '<S54>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Servo Commands1/Radians to Degrees2'
//  '<S55>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Servo Commands1/Radians to Degrees3'
//  '<S56>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Subsystem1/Degrees to Radians'
//  '<S57>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Subsystem1/Degrees to Radians1'
//  '<S58>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Subsystem1/Degrees to Radians2'
//  '<S59>'  : 'px4demo_uORBRead/PixBlock2/Emulated Pixhawk/Subsystem1/Degrees to Radians3'
//  '<S60>'  : 'px4demo_uORBRead/Quaternions to Rotation Angles2/Angle Calculation'
//  '<S61>'  : 'px4demo_uORBRead/Quaternions to Rotation Angles2/Quaternion Normalize'
//  '<S62>'  : 'px4demo_uORBRead/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input'
//  '<S63>'  : 'px4demo_uORBRead/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S64>'  : 'px4demo_uORBRead/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S65>'  : 'px4demo_uORBRead/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S66>'  : 'px4demo_uORBRead/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus'
//  '<S67>'  : 'px4demo_uORBRead/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S68>'  : 'px4demo_uORBRead/Subsystem1/PX4 SD Card Logger3'
//  '<S69>'  : 'px4demo_uORBRead/Subsystem1/PX4 SD Card Logger3/SDCard_logger'
//  '<S70>'  : 'px4demo_uORBRead/Subsystem2/PX4 uORB Message1'
//  '<S71>'  : 'px4demo_uORBRead/Subsystem2/PX4 uORB Write1'
//  '<S72>'  : 'px4demo_uORBRead/Vehicle Attitude/PX4 uORB Read'
//  '<S73>'  : 'px4demo_uORBRead/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_px4demo_uORBRead_h_

//
// File trailer for generated code.
//
// [EOF]
//
