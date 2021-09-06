//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PwmBox_types.h
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
#ifndef RTW_HEADER_PwmBox_types_h_
#define RTW_HEADER_PwmBox_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_struct_utAnIhe7m7cRGcmWlKaoJH_
#define DEFINED_TYPEDEF_FOR_struct_utAnIhe7m7cRGcmWlKaoJH_

struct struct_utAnIhe7m7cRGcmWlKaoJH
{
  real_T euler[3];
  real_T Tr4r3[12];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_20D8cUUeS0Xpo6TMettltD_
#define DEFINED_TYPEDEF_FOR_struct_20D8cUUeS0Xpo6TMettltD_

struct struct_20D8cUUeS0Xpo6TMettltD
{
  real_T FCC;
  real_T Gimbal;
  real_T FlightGear;
  real_T MeasureServos;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_wt9OAyFSpMZjzxD2JWHKO_
#define DEFINED_TYPEDEF_FOR_struct_wt9OAyFSpMZjzxD2JWHKO_

struct struct_wt9OAyFSpMZjzxD2JWHKO
{
  struct_utAnIhe7m7cRGcmWlKaoJH FDM;
  struct_20D8cUUeS0Xpo6TMettltD VSS;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_a1AjtOphUHLNf8OXJ9zaQB_
#define DEFINED_TYPEDEF_FOR_struct_a1AjtOphUHLNf8OXJ9zaQB_

struct struct_a1AjtOphUHLNf8OXJ9zaQB
{
  uint16_T signal1;
  uint16_T signal2;
  uint16_T signal3;
  uint16_T signal4;
};

#endif

#ifndef struct_px4_internal_block_PWM_PwmBox_T
#define struct_px4_internal_block_PWM_PwmBox_T

struct px4_internal_block_PWM_PwmBox_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  int pwmDevHandler;
  const char * pwmDevObj;
  unsigned int servoCount;
  int channelMask;
  boolean_T isMain;
  uint16_T errorStatus;
  orb_advert_t armAdvertiseObj;
  orb_advert_t actuatorAdvertiseObj;
  boolean_T isArmed;
};

#endif                                // struct_px4_internal_block_PWM_PwmBox_T

// Parameters (default storage)
typedef struct P_PwmBox_T_ P_PwmBox_T;

// Forward declaration for rtModel
typedef struct tag_RTM_PwmBox_T RT_MODEL_PwmBox_T;

#endif                                 // RTW_HEADER_PwmBox_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
