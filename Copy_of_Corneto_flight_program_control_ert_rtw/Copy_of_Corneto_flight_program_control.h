//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Copy_of_Corneto_flight_program_control.h
//
// Code generated for Simulink model 'Copy_of_Corneto_flight_program_control'.
//
// Model version                  : 1.8
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Jun 30 14:22:49 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Copy_of_Corneto_flight_program_control_h_
#define RTW_HEADER_Copy_of_Corneto_flight_program_control_h_
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
#include "Copy_of_Corneto_flight_program_control_types.h"
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

#define Copy_of_Corneto_flight_program_control_M (Copy_of_Corneto_flight_progr_M)

// Block signals (default storage)
struct B_Copy_of_Corneto_flight_prog_T {
  real_T TmpSignalConversionAtSFunct[40];// '<S62>/SDCard_logger'
  px4_Bus_vehicle_odometry In1;        // '<S65>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_vehicle_local_position In1_e;// '<S17>/In1'
  px4_Bus_vehicle_local_position b_varargout_2_m;
  px4_Bus_vehicle_gps_position In1_a;  // '<S16>/In1'
  px4_Bus_vehicle_gps_position b_varargout_2_c;
  real_T csumrev[9];
  px4_Bus_sensor_accel In1_i;          // '<S13>/In1'
  real_T CastToDouble3[10];            // '<S18>/Cast To Double3'
  px4_Bus_sensor_accel b_varargout_2_k;
  px4_Bus_sensor_gyro In1_eg;          // '<S15>/In1'
  px4_Bus_sensor_gyro b_varargout_2_cx;
  char_T b[56];
  px4_Bus_debug_vect BusAssignment1;   // '<Root>/Bus Assignment1'
  px4_Bus_debug_vect BusAssignment1_b; // '<Root>/Bus Assignment1'
  real_T CastToDouble2[4];             // '<Root>/Cast To Double2'
  char_T e[28];
  char_T c[24];
  char_T ParameterNameStr[17];
  uint16_T pwmValue[8];
  uint64_t timestamp;
  MW_PARAM_DATA_TYPE ParamDataType;
  real_T t;
  real_T cumRevIndex;
  real_T csum;
  real_T z;
  real_T Product3_n;                   // '<S55>/Product3'
  real_T Product2_f;                   // '<S55>/Product2'
  real_T Sum3;                         // '<S23>/Sum3'
  real_T Kp_phi;                       // '<S24>/1-D Lookup Table5'
  real_T flight_mode_enum;             // '<S27>/Switch3'
  real_T fcn3;                         // '<S9>/fcn3'
  real32_T RateTransition;             // '<Root>/Rate Transition'
  int32_T RateTransition1;             // '<Root>/Rate Transition1'
  boolean_T RateTransition4;           // '<Root>/Rate Transition4'
};

// Block states (default storage) for system '<Root>'
struct DW_Copy_of_Corneto_flight_pro_T {
  dsp_simulink_MovingAverage_Co_T obj; // '<S26>/Moving Average1'
  px4_internal_block_ParameterU_T obj_m;// '<Root>/Read Parameter2'
  px4_internal_block_ParameterU_T obj_l;// '<Root>/Read Parameter1'
  px4_internal_block_ParameterU_T obj_b;// '<Root>/Read Parameter'
  px4_internal_block_Subscriber_T obj_n;// '<S64>/SourceBlock'
  px4_internal_block_Subscriber_T obj_f;// '<S6>/SourceBlock'
  px4_internal_block_Subscriber_T obj_k;// '<S5>/SourceBlock'
  px4_internal_block_Subscriber_T obj_nc;// '<S14>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S12>/SourceBlock'
  px4_internal_block_PWM_Copy_o_T obj_mo;// '<S22>/PX4 PWM Output1'
  px4_internal_block_Publisher__T obj_o;// '<S7>/SinkBlock'
  real_T DiscreteTransferFcn_states;   // '<S19>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn_states_b; // '<S18>/Discrete Transfer Fcn'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S39>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_f;// '<S44>/Discrete-Time Integrator'
  real_T DelayInput1_DSTATE;           // '<S34>/Delay Input1'
  real_T DiscreteTimeIntegrator_DSTATE_b;// '<S35>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_DSTATE_d;// '<S48>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U;// '<S23>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_e;// '<S39>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_k;// '<S44>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_h;// '<S35>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U_c;// '<S48>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_DSTAT_b5;// '<S23>/Discrete-Time Integrator'
  real32_T RateTransition_Buffer0;     // '<Root>/Rate Transition'
  real32_T RateTransition3_Buffer0;    // '<Root>/Rate Transition3'
  int32_T RateTransition1_Buffer0;     // '<Root>/Rate Transition1'
  int32_T clockTickCounter;            // '<S8>/100 Hz'
  uint32_T count;                      // '<S62>/SDCard_logger'
  uint32_T EmulatedPixhawk_PREV_T;     // '<S8>/Emulated Pixhawk'
  uint16_T elem_size;                  // '<S62>/SDCard_logger'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S23>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_h;// '<S39>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_a;// '<S44>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_k;// '<S35>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_f;// '<S48>/Discrete-Time Integrator'
  uint8_T vect_size;                   // '<S62>/SDCard_logger'
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;// '<S23>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_d;// '<S39>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_e;// '<S44>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_k;// '<S35>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTE_es;// '<S48>/Discrete-Time Integrator'
  boolean_T isflushed;                 // '<S62>/SDCard_logger'
  boolean_T isopen;                    // '<S62>/SDCard_logger'
  boolean_T count_not_empty;           // '<S62>/SDCard_logger'
  boolean_T EmulatedPixhawk_RESET_ELAPS_T;// '<S8>/Emulated Pixhawk'
  boolean_T Memory_PreviousInput;      // '<S28>/Memory'
  boolean_T Memory_PreviousInput_g;    // '<S40>/Memory'
  boolean_T Memory_PreviousInput_o;    // '<S45>/Memory'
  boolean_T Memory_PreviousInput_j;    // '<S36>/Memory'
  boolean_T Memory_PreviousInput_ge;   // '<S49>/Memory'
  FILE* fp;                            // '<S62>/SDCard_logger'
};

// Zero-crossing (trigger) state
struct PrevZCX_Copy_of_Corneto_fligh_T {
  ZCSigState EmulatedPixhawk_Trig_ZCE; // '<S8>/Emulated Pixhawk'
};

// Parameters (default storage)
struct P_Copy_of_Corneto_flight_prog_T_ {
  struct_FuH2ngUSrLPtrZS1Hkt11F Autopilot;// Variable: Autopilot
                                             //  Referenced by:
                                             //    '<S24>/1-D Lookup Table3'
                                             //    '<S24>/1-D Lookup Table4'
                                             //    '<S24>/1-D Lookup Table5'

  struct_KbuHZdFirwgp0Ajtitq2dC Flight_Logic;// Variable: Flight_Logic
                                                //  Referenced by:
                                                //    '<S30>/Constant'
                                                //    '<S32>/Constant'
                                                //    '<S33>/Constant'
                                                //    '<S37>/Constant'
                                                //    '<S38>/Constant'
                                                //    '<S41>/Constant'
                                                //    '<S43>/Constant'
                                                //    '<S46>/Constant'
                                                //    '<S47>/Constant'

  real_T CompareToConstant2_const;   // Mask Parameter: CompareToConstant2_const
                                        //  Referenced by: '<S42>/Constant'

  real_T CompareToConstant_const;     // Mask Parameter: CompareToConstant_const
                                         //  Referenced by: '<S31>/Constant'

  real_T DetectDecrease_vinit;         // Mask Parameter: DetectDecrease_vinit
                                          //  Referenced by: '<S34>/Delay Input1'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S65>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S64>/Constant'

  px4_Bus_vehicle_local_position Out1_Y0_k;// Computed Parameter: Out1_Y0_k
                                              //  Referenced by: '<S17>/Out1'

  px4_Bus_vehicle_local_position Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                     //  Referenced by: '<S6>/Constant'

  px4_Bus_vehicle_gps_position Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                            //  Referenced by: '<S16>/Out1'

  px4_Bus_vehicle_gps_position Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                   //  Referenced by: '<S5>/Constant'

  px4_Bus_sensor_accel Out1_Y0_iw;     // Computed Parameter: Out1_Y0_iw
                                          //  Referenced by: '<S13>/Out1'

  px4_Bus_sensor_accel Constant_Value_p;// Computed Parameter: Constant_Value_p
                                           //  Referenced by: '<S12>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_f;       // Computed Parameter: Out1_Y0_f
                                          //  Referenced by: '<S15>/Out1'

  px4_Bus_sensor_gyro Constant_Value_l;// Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S14>/Constant'

  px4_Bus_debug_vect Constant_Value_h; // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S4>/Constant'

  real_T Constant4_Value;              // Expression: 600
                                          //  Referenced by: '<S27>/Constant4'

  real_T Constant6_Value;              // Expression: 500
                                          //  Referenced by: '<S27>/Constant6'

  real_T Constant3_Value;              // Expression: 400
                                          //  Referenced by: '<S27>/Constant3'

  real_T Constant2_Value;              // Expression: 300
                                          //  Referenced by: '<S27>/Constant2'

  real_T Constant1_Value;              // Expression: 200
                                          //  Referenced by: '<S27>/Constant1'

  real_T Constant_Value_lj;            // Expression: 1
                                          //  Referenced by: '<S27>/Constant'

  real_T Constant5_Value;              // Expression: 0
                                          //  Referenced by: '<S21>/Constant5'

  real_T Constant5_Value_p;            // Expression: 0
                                          //  Referenced by: '<S27>/Constant5'

  real_T Constant_Value_j;             // Expression: 0
                                          //  Referenced by: '<S28>/Constant'

  real_T One5_Value;                   // Expression: 2000
                                          //  Referenced by: '<S22>/One5'

  real_T One6_Value;                   // Expression: 1000
                                          //  Referenced by: '<S22>/One6'

  real_T One1_Value;                   // Expression: 1
                                          //  Referenced by: '<S18>/One1'

  real_T One2_Value;                   // Expression: 0
                                          //  Referenced by: '<S18>/One2'

  real_T Pix_Out_Y0;                   // Computed Parameter: Pix_Out_Y0
                                          //  Referenced by: '<S18>/Pix_Out'

  real_T DiscreteTransferFcn_NumCoef[2];// Expression: [num_lpf_d]
                                           //  Referenced by: '<S19>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [den_lpf_d]
                                           //  Referenced by: '<S19>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S19>/Discrete Transfer Fcn'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S23>/Discrete-Time Integrator'

  real_T Zero_Value;                   // Expression: 0
                                          //  Referenced by: '<S19>/Zero'

  real_T DiscreteTransferFcn_NumCoef_b[2];// Expression: [num_lpf_d]
                                             //  Referenced by: '<S18>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_a[2];// Expression: [den_lpf_d]
                                             //  Referenced by: '<S18>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_g;// Expression: 0
                                            //  Referenced by: '<S18>/Discrete Transfer Fcn'

  real_T Constant1_Value_d;            // Expression: 0
                                          //  Referenced by: '<S39>/Constant1'

  real_T DiscreteTimeIntegrator_gainva_c;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_c
                             //  Referenced by: '<S39>/Discrete-Time Integrator'

  real_T Constant1_Value_k;            // Expression: 0
                                          //  Referenced by: '<S44>/Constant1'

  real_T DiscreteTimeIntegrator_gainva_h;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_h
                             //  Referenced by: '<S44>/Discrete-Time Integrator'

  real_T Constant1_Value_n;            // Expression: 0
                                          //  Referenced by: '<S35>/Constant1'

  real_T DiscreteTimeIntegrator_gainv_hy;
                          // Computed Parameter: DiscreteTimeIntegrator_gainv_hy
                             //  Referenced by: '<S35>/Discrete-Time Integrator'

  real_T Constant1_Value_i;            // Expression: 0
                                          //  Referenced by: '<S48>/Constant1'

  real_T DiscreteTimeIntegrator_gainv_c4;
                          // Computed Parameter: DiscreteTimeIntegrator_gainv_c4
                             //  Referenced by: '<S48>/Discrete-Time Integrator'

  real_T Gain_Gain;                    // Expression: 180/pi
                                          //  Referenced by: '<S50>/Gain'

  real_T Saturation_UpperSat;          // Expression: 20
                                          //  Referenced by: '<S22>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -20
                                          //  Referenced by: '<S22>/Saturation'

  real_T Gain_Gain_b;                  // Expression: 1000/91
                                          //  Referenced by: '<S22>/Gain'

  real_T One_Value;                    // Expression: 900
                                          //  Referenced by: '<S22>/One'

  real_T Gain_Gain_o;                  // Expression: 180/pi
                                          //  Referenced by: '<S51>/Gain'

  real_T Saturation1_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S22>/Saturation1'

  real_T Saturation1_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S22>/Saturation1'

  real_T Gain1_Gain;                   // Expression: 1000/91
                                          //  Referenced by: '<S22>/Gain1'

  real_T One1_Value_b;                 // Expression: 900
                                          //  Referenced by: '<S22>/One1'

  real_T Gain_Gain_g;                  // Expression: 180/pi
                                          //  Referenced by: '<S52>/Gain'

  real_T Saturation2_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S22>/Saturation2'

  real_T Saturation2_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S22>/Saturation2'

  real_T Gain2_Gain;                   // Expression: 1000/91
                                          //  Referenced by: '<S22>/Gain2'

  real_T One2_Value_d;                 // Expression: 900
                                          //  Referenced by: '<S22>/One2'

  real_T Gain_Gain_l;                  // Expression: 180/pi
                                          //  Referenced by: '<S53>/Gain'

  real_T Saturation3_UpperSat;         // Expression: 20
                                          //  Referenced by: '<S22>/Saturation3'

  real_T Saturation3_LowerSat;         // Expression: -20
                                          //  Referenced by: '<S22>/Saturation3'

  real_T Gain3_Gain;                   // Expression: 1000/91
                                          //  Referenced by: '<S22>/Gain3'

  real_T One3_Value;                   // Expression: 900
                                          //  Referenced by: '<S22>/One3'

  real_T Constant_Value_a;             // Expression: 1
                                          //  Referenced by: '<S35>/Constant'

  real_T Constant_Value_k;             // Expression: 1
                                          //  Referenced by: '<S39>/Constant'

  real_T Constant_Value_e;             // Expression: 1
                                          //  Referenced by: '<S44>/Constant'

  real_T Constant_Value_b;             // Expression: 1
                                          //  Referenced by: '<S48>/Constant'

  real_T Constant_Value_ki;            // Expression: 1
                                          //  Referenced by: '<S57>/Constant'

  real_T Constant_Value_g0;            // Expression: 1
                                          //  Referenced by: '<S58>/Constant'

  real_T ReadParameter_SampleTime;     // Expression: 1
                                          //  Referenced by: '<Root>/Read Parameter'

  real_T ReadParameter1_SampleTime;    // Expression: 1
                                          //  Referenced by: '<Root>/Read Parameter1'

  real_T ReadParameter2_SampleTime;    // Expression: 1
                                          //  Referenced by: '<Root>/Read Parameter2'

  real_T Constant2_Value_m;            // Expression: 0
                                          //  Referenced by: '<Root>/Constant2'

  real_T u00Hz_Amp;                    // Expression: 1
                                          //  Referenced by: '<S8>/100 Hz'

  real_T u00Hz_Period;                 // Computed Parameter: u00Hz_Period
                                          //  Referenced by: '<S8>/100 Hz'

  real_T u00Hz_Duty;                   // Computed Parameter: u00Hz_Duty
                                          //  Referenced by: '<S8>/100 Hz'

  real_T u00Hz_PhaseDelay;             // Expression: 0
                                          //  Referenced by: '<S8>/100 Hz'

  int32_T RateTransition1_InitialConditio;
                          // Computed Parameter: RateTransition1_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition1'

  real32_T Constant7_Value[12];        // Expression: HIL_Data.FDM.Tr4r3
                                          //  Referenced by: '<S25>/Constant7'

  real32_T Constant_Value_m;           // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S23>/Constant'

  real32_T RateTransition_InitialCondition;
                          // Computed Parameter: RateTransition_InitialCondition
                             //  Referenced by: '<Root>/Rate Transition'

  real32_T RateTransition3_InitialConditio;
                          // Computed Parameter: RateTransition3_InitialConditio
                             //  Referenced by: '<Root>/Rate Transition3'

  uint32_T uDLookupTable3_maxIndex[2];
                                  // Computed Parameter: uDLookupTable3_maxIndex
                                     //  Referenced by: '<S24>/1-D Lookup Table3'

  uint32_T uDLookupTable5_maxIndex[2];
                                  // Computed Parameter: uDLookupTable5_maxIndex
                                     //  Referenced by: '<S24>/1-D Lookup Table5'

  uint32_T uDLookupTable4_maxIndex[2];
                                  // Computed Parameter: uDLookupTable4_maxIndex
                                     //  Referenced by: '<S24>/1-D Lookup Table4'

  boolean_T Memory_InitialCondition;
                                  // Computed Parameter: Memory_InitialCondition
                                     //  Referenced by: '<S28>/Memory'

  boolean_T Memory_InitialCondition_n;
                                // Computed Parameter: Memory_InitialCondition_n
                                   //  Referenced by: '<S40>/Memory'

  boolean_T Memory_InitialCondition_l;
                                // Computed Parameter: Memory_InitialCondition_l
                                   //  Referenced by: '<S45>/Memory'

  boolean_T Memory_InitialCondition_b;
                                // Computed Parameter: Memory_InitialCondition_b
                                   //  Referenced by: '<S36>/Memory'

  boolean_T Memory_InitialCondition_m;
                                // Computed Parameter: Memory_InitialCondition_m
                                   //  Referenced by: '<S49>/Memory'

  boolean_T One7_Value;                // Computed Parameter: One7_Value
                                          //  Referenced by: '<S22>/One7'

  boolean_T One4_Value;                // Computed Parameter: One4_Value
                                          //  Referenced by: '<S22>/One4'

};

// Real-time Model Data Structure
struct tag_RTM_Copy_of_Corneto_fligh_T {
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
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_Copy_of_Corneto_flight_prog_T Copy_of_Corneto_flight_progra_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern struct B_Copy_of_Corneto_flight_prog_T Copy_of_Corneto_flight_progra_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern struct DW_Copy_of_Corneto_flight_pro_T Copy_of_Corneto_flight_progr_DW;

// Zero-crossing (trigger) state
extern PrevZCX_Copy_of_Corneto_fligh_T Copy_of_Corneto_flight__PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Copy_of_Corneto_flight_program_control_initialize(void);
  extern void Copy_of_Corneto_flight_program_control_step(void);
  extern void Copy_of_Corneto_flight_program_control_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Copy_of_Corneto_flig_T *const Copy_of_Corneto_flight_progr_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S12>/NOT' : Unused code path elimination
//  Block '<Root>/Cast To Double36' : Unused code path elimination
//  Block '<S14>/NOT' : Unused code path elimination
//  Block '<S5>/NOT' : Unused code path elimination
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S24>/1-D Lookup Table1' : Unused code path elimination
//  Block '<S24>/1-D Lookup Table2' : Unused code path elimination
//  Block '<S24>/1-D Lookup Table6' : Unused code path elimination
//  Block '<S18>/Cast To Double5' : Unused code path elimination
//  Block '<S18>/One6' : Unused code path elimination
//  Block '<S18>/Switch2' : Unused code path elimination
//  Block '<S64>/NOT' : Unused code path elimination
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
//  Block '<S18>/Cast To Double1' : Eliminate redundant data type conversion
//  Block '<S18>/Cast To Double2' : Eliminate redundant data type conversion
//  Block '<S18>/Cast To Double4' : Eliminate redundant data type conversion
//  Block '<S18>/Cast To Double40' : Eliminate redundant data type conversion
//  Block '<S18>/Cast To Double6' : Eliminate redundant data type conversion
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
//  '<Root>' : 'Copy_of_Corneto_flight_program_control'
//  '<S1>'   : 'Copy_of_Corneto_flight_program_control/Accelerometer'
//  '<S2>'   : 'Copy_of_Corneto_flight_program_control/Gyroscope'
//  '<S3>'   : 'Copy_of_Corneto_flight_program_control/MATLAB Function'
//  '<S4>'   : 'Copy_of_Corneto_flight_program_control/PX4 uORB Message'
//  '<S5>'   : 'Copy_of_Corneto_flight_program_control/PX4 uORB Read'
//  '<S6>'   : 'Copy_of_Corneto_flight_program_control/PX4 uORB Read1'
//  '<S7>'   : 'Copy_of_Corneto_flight_program_control/PX4 uORB Write'
//  '<S8>'   : 'Copy_of_Corneto_flight_program_control/PixBlock2'
//  '<S9>'   : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2'
//  '<S10>'  : 'Copy_of_Corneto_flight_program_control/Subsystem1'
//  '<S11>'  : 'Copy_of_Corneto_flight_program_control/Vehicle Attitude'
//  '<S12>'  : 'Copy_of_Corneto_flight_program_control/Accelerometer/PX4 uORB Read'
//  '<S13>'  : 'Copy_of_Corneto_flight_program_control/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S14>'  : 'Copy_of_Corneto_flight_program_control/Gyroscope/PX4 uORB Read'
//  '<S15>'  : 'Copy_of_Corneto_flight_program_control/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S16>'  : 'Copy_of_Corneto_flight_program_control/PX4 uORB Read/Enabled Subsystem'
//  '<S17>'  : 'Copy_of_Corneto_flight_program_control/PX4 uORB Read1/Enabled Subsystem'
//  '<S18>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk'
//  '<S19>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Autopilot'
//  '<S20>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Fin Allocation'
//  '<S21>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic'
//  '<S22>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Servo Commands1'
//  '<S23>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Autopilot/Phi_Control'
//  '<S24>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Autopilot/Phi_Control/Gain_Lookup'
//  '<S25>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Fin Allocation/control_allocation'
//  '<S26>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic'
//  '<S27>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Enumeration'
//  '<S28>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic'
//  '<S29>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic'
//  '<S30>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic'
//  '<S31>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Compare To Constant'
//  '<S32>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Compare To Constant1'
//  '<S33>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Compare To Constant3'
//  '<S34>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Detect Decrease'
//  '<S35>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Enable_Timer_Logic'
//  '<S36>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Apogee_Detection_Logic/Latch_Signal'
//  '<S37>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic/Compare To Constant'
//  '<S38>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic/Compare To Constant1'
//  '<S39>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic/Enable_Timer_Logic'
//  '<S40>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Launch_Detection_Logic/Latch_Signal'
//  '<S41>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Compare To Constant1'
//  '<S42>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Compare To Constant2'
//  '<S43>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Compare To Constant3'
//  '<S44>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Enable_Timer_Logic'
//  '<S45>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/MECO_Detection_Logic/Latch_Signal'
//  '<S46>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic/Compare To Constant1'
//  '<S47>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic/Compare To Constant3'
//  '<S48>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic/Enable_Timer_Logic'
//  '<S49>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Flight_Logic/Recovery_Logic/Latch_Signal'
//  '<S50>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Servo Commands1/Radians to Degrees'
//  '<S51>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Servo Commands1/Radians to Degrees1'
//  '<S52>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Servo Commands1/Radians to Degrees2'
//  '<S53>'  : 'Copy_of_Corneto_flight_program_control/PixBlock2/Emulated Pixhawk/Servo Commands1/Radians to Degrees3'
//  '<S54>'  : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2/Angle Calculation'
//  '<S55>'  : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2/Quaternion Normalize'
//  '<S56>'  : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input'
//  '<S57>'  : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S58>'  : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S59>'  : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S60>'  : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus'
//  '<S61>'  : 'Copy_of_Corneto_flight_program_control/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S62>'  : 'Copy_of_Corneto_flight_program_control/Subsystem1/PX4 SD Card Logger3'
//  '<S63>'  : 'Copy_of_Corneto_flight_program_control/Subsystem1/PX4 SD Card Logger3/SDCard_logger'
//  '<S64>'  : 'Copy_of_Corneto_flight_program_control/Vehicle Attitude/PX4 uORB Read'
//  '<S65>'  : 'Copy_of_Corneto_flight_program_control/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                  // RTW_HEADER_Copy_of_Corneto_flight_program_control_h_

//
// File trailer for generated code.
//
// [EOF]
//
