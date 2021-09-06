//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flash_FCC_types.h
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
#ifndef RTW_HEADER_Flash_FCC_types_h_
#define RTW_HEADER_Flash_FCC_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <uORB/topics/sensor_gyro.h>
#ifndef typedef_d_px4_internal_block_SampleTi_T
#define typedef_d_px4_internal_block_SampleTi_T

typedef struct {
  int32_T __dummy;
} d_px4_internal_block_SampleTi_T;

#endif                                 //typedef_d_px4_internal_block_SampleTi_T

#ifndef typedef_px4_internal_block_Subscriber_T
#define typedef_px4_internal_block_Subscriber_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  d_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
} px4_internal_block_Subscriber_T;

#endif                                 //typedef_px4_internal_block_Subscriber_T

// Custom Type definition for MATLABSystem: '<S2>/Serial Receive'
#include "MW_SVD.h"
#ifndef typedef_px4_internal_block_Hardware_F_T
#define typedef_px4_internal_block_Hardware_F_T

typedef struct {
  int32_T __dummy;
} px4_internal_block_Hardware_F_T;

#endif                                 //typedef_px4_internal_block_Hardware_F_T

#ifndef typedef_px4_internal_block_PX4SCIWrit_T
#define typedef_px4_internal_block_PX4SCIWrit_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  px4_internal_block_Hardware_F_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
} px4_internal_block_PX4SCIWrit_T;

#endif                                 //typedef_px4_internal_block_PX4SCIWrit_T

#ifndef typedef_px4_internal_block_PWM_Flash__T
#define typedef_px4_internal_block_PWM_Flash__T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  int pwmDevHandler;
  const char * pwmDevObj;
  unsigned int servoCount;
  int channelMask;
  boolean_T isMain;
  uint16_T errorStatus;
  boolean_T isArmed;
} px4_internal_block_PWM_Flash__T;

#endif                                 //typedef_px4_internal_block_PWM_Flash__T

#ifndef typedef_px4_internal_block_PX4SCIRead_T
#define typedef_px4_internal_block_PX4SCIRead_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  px4_internal_block_Hardware_F_T Hw;
  MW_Handle_Type MW_SCIHANDLE;
  real_T SampleTime;
} px4_internal_block_PX4SCIRead_T;

#endif                                 //typedef_px4_internal_block_PX4SCIRead_T

#ifndef typedef_struct_T_Flash_FCC_T
#define typedef_struct_T_Flash_FCC_T

typedef struct {
  char_T Value[12];
} struct_T_Flash_FCC_T;

#endif                                 //typedef_struct_T_Flash_FCC_T

// Parameters for system: '<S14>/If Action Subsystem'
typedef struct P_IfActionSubsystem_Flash_FCC_T_ P_IfActionSubsystem_Flash_FCC_T;

// Parameters (default storage)
typedef struct P_Flash_FCC_T_ P_Flash_FCC_T;

// Forward declaration for rtModel
typedef struct tag_RTM_Flash_FCC_T RT_MODEL_Flash_FCC_T;

#endif                                 // RTW_HEADER_Flash_FCC_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
