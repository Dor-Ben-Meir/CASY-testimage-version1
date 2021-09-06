//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flash_FCC.h
//
// Code generated for Simulink model 'Flash_FCC'.
//
// Model version                  : 1.408
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Feb 18 00:57:35 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Flash_FCC_h_
#define RTW_HEADER_Flash_FCC_h_
#include <string.h>
#include <math.h>
#include <stddef.h>
#ifndef Flash_FCC_COMMON_INCLUDES_
# define Flash_FCC_COMMON_INCLUDES_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_uORB_Read.h"
#include "MW_SCI.h"
#include "MW_PX4_PWM.h"
#include "MW_PX4_SCI.h"
#endif                                 // Flash_FCC_COMMON_INCLUDES_

#include "Flash_FCC_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  uint8_T RxDataLocChar[80];
  real32_T In1_c[20];                  // '<S31>/In1'
  real32_T RxData[20];
  uint8_T TxDataLocChar[75];
  px4_Bus_sensor_gyro In1;             // '<S23>/In1'
  px4_Bus_sensor_gyro b_varargout_2;
  real32_T VectorConcatenate[18];      // '<S8>/Vector Concatenate'
  uint8_T VectorConcatenate1[75];      // '<S9>/Vector Concatenate1'
  uint16_T pwmValue[8];
} B_Flash_FCC_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  px4_internal_block_PX4SCIRead_T obj; // '<S2>/Serial Receive'
  px4_internal_block_Subscriber_T obj_o;// '<S22>/SourceBlock'
  px4_internal_block_PX4SCIWrit_T obj_k;// '<S9>/Serial Transmit'
  px4_internal_block_PWM_Flash__T obj_a;// '<S10>/PX4 PWM Output1'
  real32_T Delay_DSTATE;               // '<S3>/Delay'
  real32_T DiscreteTimeIntegrator_DSTATE;// '<S14>/Discrete-Time Integrator'
  real32_T DiscreteTransferFcn_states; // '<S14>/Discrete Transfer Fcn'
  real32_T DiscreteTimeIntegrator_DSTATE_m;// '<S1>/Discrete-Time Integrator'
  real32_T Delay_DSTATE_n;             // '<S25>/Delay'
  real32_T DiscreteTimeIntegrator_PREV_U;// '<S14>/Discrete-Time Integrator'
  real32_T DiscreteTimeIntegrator_PREV_U_e;// '<S1>/Discrete-Time Integrator'
  int32_T clockTickCounter;            // '<Root>/Pulse Generator1'
  uint32_T PixhawkSoftware100Hz_PREV_T;// '<Root>/Pixhawk Software - 100 Hz'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S14>/Discrete-Time Integrator'
  int8_T DiscreteTimeIntegrator_PrevRe_d;// '<S1>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;// '<S14>/Discrete-Time Integrator'
  uint8_T DiscreteTimeIntegrator_SYSTEM_l;// '<S1>/Discrete-Time Integrator'
  boolean_T PixhawkSoftware100Hz_RESET_ELAP;// '<Root>/Pixhawk Software - 100 Hz' 
} DW_Flash_FCC_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;// '<S2>/Triggered Subsystem'
  ZCSigState PixhawkSoftware100Hz_Trig_ZCE;// '<Root>/Pixhawk Software - 100 Hz' 
  ZCSigState DiscreteTransferFcn_Reset_ZCE;// '<S14>/Discrete Transfer Fcn'
} PrevZCX_Flash_FCC_T;

// Parameters for system: '<S14>/If Action Subsystem'
struct P_IfActionSubsystem_Flash_FCC_T_ {
  real32_T One_Value;                  // Computed Parameter: One_Value
                                          //  Referenced by: '<S15>/One'

};

// Parameters (default storage)
struct P_Flash_FCC_T_ {
  px4_Bus_sensor_gyro Out1_Y0;         // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S23>/Out1'

  px4_Bus_sensor_gyro Constant_Value;  // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S22>/Constant'

  real_T SerialReceive_SampleTime;     // Expression: 0.001
                                          //  Referenced by: '<S2>/Serial Receive'

  real_T PulseGenerator1_Amp;          // Expression: 1
                                          //  Referenced by: '<Root>/Pulse Generator1'

  real_T PulseGenerator1_Period;   // Computed Parameter: PulseGenerator1_Period
                                      //  Referenced by: '<Root>/Pulse Generator1'

  real_T PulseGenerator1_Duty;       // Computed Parameter: PulseGenerator1_Duty
                                        //  Referenced by: '<Root>/Pulse Generator1'

  real_T PulseGenerator1_PhaseDelay;   // Expression: 0
                                          //  Referenced by: '<Root>/Pulse Generator1'

  real32_T One8_Value;                 // Computed Parameter: One8_Value
                                          //  Referenced by: '<S30>/One8'

  real32_T One7_Value;                 // Computed Parameter: One7_Value
                                          //  Referenced by: '<S30>/One7'

  real32_T One6_Value;                 // Computed Parameter: One6_Value
                                          //  Referenced by: '<S30>/One6'

  real32_T One5_Value;                 // Computed Parameter: One5_Value
                                          //  Referenced by: '<S30>/One5'

  real32_T One4_Value;                 // Computed Parameter: One4_Value
                                          //  Referenced by: '<S30>/One4'

  real32_T One3_Value;                 // Computed Parameter: One3_Value
                                          //  Referenced by: '<S30>/One3'

  real32_T One2_Value;                 // Computed Parameter: One2_Value
                                          //  Referenced by: '<S30>/One2'

  real32_T One1_Value;                 // Computed Parameter: One1_Value
                                          //  Referenced by: '<S30>/One1'

  real32_T One_Value;                  // Computed Parameter: One_Value
                                          //  Referenced by: '<S30>/One'

  real32_T Switch_1_Threshold;         // Computed Parameter: Switch_1_Threshold
                                          //  Referenced by: '<S12>/Switch'

  real32_T Switch_2_Threshold;         // Computed Parameter: Switch_2_Threshold
                                          //  Referenced by: '<S12>/Switch'

  real32_T Switch_3_Threshold;         // Computed Parameter: Switch_3_Threshold
                                          //  Referenced by: '<S12>/Switch'

  real32_T Delay_InitialCondition; // Computed Parameter: Delay_InitialCondition
                                      //  Referenced by: '<S3>/Delay'

  real32_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S14>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_IC;
                                // Computed Parameter: DiscreteTimeIntegrator_IC
                                   //  Referenced by: '<S14>/Discrete-Time Integrator'

  real32_T DiscreteTransferFcn_NumCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_NumCoef
                                 //  Referenced by: '<S14>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_DenCoef[2];
                              // Computed Parameter: DiscreteTransferFcn_DenCoef
                                 //  Referenced by: '<S14>/Discrete Transfer Fcn'

  real32_T DiscreteTransferFcn_InitialStat;
                          // Computed Parameter: DiscreteTransferFcn_InitialStat
                             //  Referenced by: '<S14>/Discrete Transfer Fcn'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S14>/Gain2'

  real32_T Switch_4_Threshold;         // Computed Parameter: Switch_4_Threshold
                                          //  Referenced by: '<S11>/Switch'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S14>/Gain'

  real32_T Limit2maxDeflection_UpperSat;
                             // Computed Parameter: Limit2maxDeflection_UpperSat
                                //  Referenced by: '<S6>/Limit2maxDeflection'

  real32_T Limit2maxDeflection_LowerSat;
                             // Computed Parameter: Limit2maxDeflection_LowerSat
                                //  Referenced by: '<S6>/Limit2maxDeflection'

  real32_T Constant_Value_p;           // Computed Parameter: Constant_Value_p
                                          //  Referenced by: '<S6>/Constant'

  real32_T DiscreteTimeIntegrator_gainva_i;
                          // Computed Parameter: DiscreteTimeIntegrator_gainva_i
                             //  Referenced by: '<S1>/Discrete-Time Integrator'

  real32_T DiscreteTimeIntegrator_IC_d;
                              // Computed Parameter: DiscreteTimeIntegrator_IC_d
                                 //  Referenced by: '<S1>/Discrete-Time Integrator'

  real32_T Zero_Value;                 // Computed Parameter: Zero_Value
                                          //  Referenced by: '<S4>/Zero'

  real32_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<S6>/Constant1'

  real32_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<S6>/Constant2'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                          //  Referenced by: '<S6>/Constant3'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                          //  Referenced by: '<S6>/Constant4'

  real32_T Gain_Gain_c;                // Computed Parameter: Gain_Gain_c
                                          //  Referenced by: '<S26>/Gain'

  real32_T Saturation_UpperSat;       // Computed Parameter: Saturation_UpperSat
                                         //  Referenced by: '<S10>/Saturation'

  real32_T Saturation_LowerSat;       // Computed Parameter: Saturation_LowerSat
                                         //  Referenced by: '<S10>/Saturation'

  real32_T Gain_Gain_g;                // Computed Parameter: Gain_Gain_g
                                          //  Referenced by: '<S10>/Gain'

  real32_T One_Value_m;                // Computed Parameter: One_Value_m
                                          //  Referenced by: '<S10>/One'

  real32_T Delay_InitialCondition_h;
                                 // Computed Parameter: Delay_InitialCondition_h
                                    //  Referenced by: '<S25>/Delay'

  real32_T Gain_Gain_d;                // Computed Parameter: Gain_Gain_d
                                          //  Referenced by: '<S27>/Gain'

  real32_T Saturation1_UpperSat;     // Computed Parameter: Saturation1_UpperSat
                                        //  Referenced by: '<S10>/Saturation1'

  real32_T Saturation1_LowerSat;     // Computed Parameter: Saturation1_LowerSat
                                        //  Referenced by: '<S10>/Saturation1'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S10>/Gain1'

  real32_T One1_Value_e;               // Computed Parameter: One1_Value_e
                                          //  Referenced by: '<S10>/One1'

  real32_T Gain_Gain_f;                // Computed Parameter: Gain_Gain_f
                                          //  Referenced by: '<S28>/Gain'

  real32_T Saturation2_UpperSat;     // Computed Parameter: Saturation2_UpperSat
                                        //  Referenced by: '<S10>/Saturation2'

  real32_T Saturation2_LowerSat;     // Computed Parameter: Saturation2_LowerSat
                                        //  Referenced by: '<S10>/Saturation2'

  real32_T Gain2_Gain_h;               // Computed Parameter: Gain2_Gain_h
                                          //  Referenced by: '<S10>/Gain2'

  real32_T One2_Value_f;               // Computed Parameter: One2_Value_f
                                          //  Referenced by: '<S10>/One2'

  real32_T Gain_Gain_o;                // Computed Parameter: Gain_Gain_o
                                          //  Referenced by: '<S29>/Gain'

  real32_T Saturation3_UpperSat;     // Computed Parameter: Saturation3_UpperSat
                                        //  Referenced by: '<S10>/Saturation3'

  real32_T Saturation3_LowerSat;     // Computed Parameter: Saturation3_LowerSat
                                        //  Referenced by: '<S10>/Saturation3'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S10>/Gain3'

  real32_T One3_Value_o;               // Computed Parameter: One3_Value_o
                                          //  Referenced by: '<S10>/One3'

  real32_T Switch_4_Threshold_n;     // Computed Parameter: Switch_4_Threshold_n
                                        //  Referenced by: '<S12>/Switch'

  real32_T Switch_5_Threshold;         // Computed Parameter: Switch_5_Threshold
                                          //  Referenced by: '<S12>/Switch'

  real32_T Switch_6_Threshold;         // Computed Parameter: Switch_6_Threshold
                                          //  Referenced by: '<S12>/Switch'

  real32_T Switch_7_Threshold;         // Computed Parameter: Switch_7_Threshold
                                          //  Referenced by: '<S12>/Switch'

  real32_T Switch_8_Threshold;         // Computed Parameter: Switch_8_Threshold
                                          //  Referenced by: '<S12>/Switch'

  real32_T Switch_9_Threshold;         // Computed Parameter: Switch_9_Threshold
                                          //  Referenced by: '<S12>/Switch'

  real32_T Zero_Value_g;               // Computed Parameter: Zero_Value_g
                                          //  Referenced by: '<S1>/Zero'

  real32_T Out1_Y0_o;                  // Computed Parameter: Out1_Y0_o
                                          //  Referenced by: '<S31>/Out1'

  boolean_T One4_Value_h;              // Computed Parameter: One4_Value_h
                                          //  Referenced by: '<S10>/One4'

  uint8_T Zero_Value_b[3];             // Computed Parameter: Zero_Value_b
                                          //  Referenced by: '<S24>/Zero'

  P_IfActionSubsystem_Flash_FCC_T IfActionSubsystem1;// '<S14>/If Action Subsystem1' 
  P_IfActionSubsystem_Flash_FCC_T IfActionSubsystem;// '<S14>/If Action Subsystem' 
};

// Real-time Model Data Structure
struct tag_RTM_Flash_FCC_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_Flash_FCC_T Flash_FCC_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_Flash_FCC_T Flash_FCC_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_Flash_FCC_T Flash_FCC_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void Flash_FCC_initialize(void);
  extern void Flash_FCC_step(void);
  extern void Flash_FCC_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_Flash_FCC_T *const Flash_FCC_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S14>/Scope' : Unused code path elimination
//  Block '<S22>/NOT' : Unused code path elimination
//  Block '<S8>/Cast To Single' : Eliminate redundant data type conversion
//  Block '<S10>/Cast To Boolean' : Eliminate redundant data type conversion


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
//  '<Root>' : 'Flash_FCC'
//  '<S1>'   : 'Flash_FCC/Pixhawk Software - 100 Hz'
//  '<S2>'   : 'Flash_FCC/Receive from HIL'
//  '<S3>'   : 'Flash_FCC/Pixhawk Software - 100 Hz/100Hz Reset1'
//  '<S4>'   : 'Flash_FCC/Pixhawk Software - 100 Hz/Autopilot'
//  '<S5>'   : 'Flash_FCC/Pixhawk Software - 100 Hz/Convert to Bus'
//  '<S6>'   : 'Flash_FCC/Pixhawk Software - 100 Hz/Fin Allocation'
//  '<S7>'   : 'Flash_FCC/Pixhawk Software - 100 Hz/Gyro'
//  '<S8>'   : 'Flash_FCC/Pixhawk Software - 100 Hz/Send to HIL'
//  '<S9>'   : 'Flash_FCC/Pixhawk Software - 100 Hz/Serial Send'
//  '<S10>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Servos'
//  '<S11>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Subsystem1'
//  '<S12>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Subsystem2'
//  '<S13>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Autopilot/Calculate U'
//  '<S14>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Autopilot/Phi'
//  '<S15>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Autopilot/Phi/If Action Subsystem'
//  '<S16>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Autopilot/Phi/If Action Subsystem1'
//  '<S17>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Fin Allocation/Saturation'
//  '<S18>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Fin Allocation/Saturation/Check_Limit_exceeding'
//  '<S19>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Fin Allocation/Saturation/Pass'
//  '<S20>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Fin Allocation/Saturation/Saturate'
//  '<S21>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Gyro/Gyroscope'
//  '<S22>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Gyro/Gyroscope/PX4 uORB Read'
//  '<S23>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Gyro/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S24>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Serial Send/Header'
//  '<S25>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Servos/100Hz Progress'
//  '<S26>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Servos/Radians to Degrees'
//  '<S27>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Servos/Radians to Degrees1'
//  '<S28>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Servos/Radians to Degrees2'
//  '<S29>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Servos/Radians to Degrees3'
//  '<S30>'  : 'Flash_FCC/Pixhawk Software - 100 Hz/Subsystem2/INS (INCOMPLETE)'
//  '<S31>'  : 'Flash_FCC/Receive from HIL/Triggered Subsystem'

#endif                                 // RTW_HEADER_Flash_FCC_h_

//
// File trailer for generated code.
//
// [EOF]
//
