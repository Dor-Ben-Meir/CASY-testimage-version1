//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PixBlock_types.h
//
// Code generated for Simulink model 'PixBlock'.
//
// Model version                  : 4.14
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sat Apr 10 12:35:07 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_PixBlock_types_h_
#define RTW_HEADER_PixBlock_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_struct_C1ErKKHKLGW5ZVBcCVCLBB_
#define DEFINED_TYPEDEF_FOR_struct_C1ErKKHKLGW5ZVBcCVCLBB_

struct struct_C1ErKKHKLGW5ZVBcCVCLBB
{
  real_T Kp_p_vec[30];
  real_T Kp_phi_vec[30];
  real_T Ki_phi_vec[30];
  real_T h_bkpts_m[3];
  real_T V_bkpts_mps[10];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_M8m2YJbQvwnCzbmWZGKwQE_
#define DEFINED_TYPEDEF_FOR_struct_M8m2YJbQvwnCzbmWZGKwQE_

struct struct_M8m2YJbQvwnCzbmWZGKwQE
{
  real_T Kp_r_vec[30];
  real_T Kp_ay_vec[30];
  real_T Ki_ay_vec[30];
  real_T h_bkpts_m[3];
  real_T V_bkpts_mps[10];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_p1tI4g4iafwNR5QbuQnvXC_
#define DEFINED_TYPEDEF_FOR_struct_p1tI4g4iafwNR5QbuQnvXC_

struct struct_p1tI4g4iafwNR5QbuQnvXC
{
  real_T Kp_q_vec[30];
  real_T Kp_az_vec[30];
  real_T Ki_az_vec[30];
  real_T h_bkpts_m[3];
  real_T V_bkpts_mps[10];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_FuH2ngUSrLPtrZS1Hkt11F_
#define DEFINED_TYPEDEF_FOR_struct_FuH2ngUSrLPtrZS1Hkt11F_

struct struct_FuH2ngUSrLPtrZS1Hkt11F
{
  struct_C1ErKKHKLGW5ZVBcCVCLBB Phi;
  struct_M8m2YJbQvwnCzbmWZGKwQE Ay;
  struct_p1tI4g4iafwNR5QbuQnvXC Az;
  real_T fin_def_max_rad;
  real_T fin_def_min_rad;
  real_T dela_cmd_bias_rad;
  real_T dele_cmd_bias_rad;
  real_T delr_cmd_bias_rad;
  real_T fin1_cmd_bias_rad;
  real_T fin2_cmd_bias_rad;
  real_T fin3_cmd_bias_rad;
  real_T fin4_cmd_bias_rad;
};

#endif

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

#ifndef struct_px4_internal_block_PWM_PixBlock_T
#define struct_px4_internal_block_PWM_PixBlock_T

struct px4_internal_block_PWM_PixBlock_T
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

#endif                              // struct_px4_internal_block_PWM_PixBlock_T

// Parameters (default storage)
typedef struct P_PixBlock_T_ P_PixBlock_T;

// Forward declaration for rtModel
typedef struct tag_RTM_PixBlock_T RT_MODEL_PixBlock_T;

#endif                                 // RTW_HEADER_PixBlock_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
