//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4log_types.h
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
#ifndef RTW_HEADER_px4log_types_h_
#define RTW_HEADER_px4log_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/vehicle_local_position.h>
#include <uORB/topics/vehicle_gps_position.h>
#include <uORB/topics/vehicle_odometry.h>

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

#ifndef DEFINED_TYPEDEF_FOR_struct_VVhaihDhHy5oT5WqtkJGhD_
#define DEFINED_TYPEDEF_FOR_struct_VVhaihDhHy5oT5WqtkJGhD_

struct struct_VVhaihDhHy5oT5WqtkJGhD
{
  real_T Fin_1_Cmd_rad;
  real_T Fin_2_Cmd_rad;
  real_T Fin_3_Cmd_rad;
  real_T Fin_4_Cmd_rad;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_phqKDUCYMf8zD1VgkGPMAE_
#define DEFINED_TYPEDEF_FOR_struct_phqKDUCYMf8zD1VgkGPMAE_

struct struct_phqKDUCYMf8zD1VgkGPMAE
{
  real_T signal1;
  real_T signal2;
  real_T signal3;
  real_T signal4;
  real_T signal5;
  real_T signal6;
  real_T signal7;
  real_T signal8;
  real_T signal9;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_GPGM62P5su4CoPIE5BQ8nE_
#define DEFINED_TYPEDEF_FOR_struct_GPGM62P5su4CoPIE5BQ8nE_

struct struct_GPGM62P5su4CoPIE5BQ8nE
{
  real_T signal1;
  real_T signal2;
  real_T signal3;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_P6rP1Gtrz2yB2zz1IAKQCE_
#define DEFINED_TYPEDEF_FOR_struct_P6rP1Gtrz2yB2zz1IAKQCE_

struct struct_P6rP1Gtrz2yB2zz1IAKQCE
{
  real_T signal1;
  real_T signal2;
  real_T signal3;
  real_T psi;
  real_T theta;
  real_T phi;
  struct_GPGM62P5su4CoPIE5BQ8nE accelerometer;
  struct_GPGM62P5su4CoPIE5BQ8nE gyro;
};

#endif

#ifndef struct_e_px4_internal_block_SampleTi_T
#define struct_e_px4_internal_block_SampleTi_T

struct e_px4_internal_block_SampleTi_T
{
  int32_T __dummy;
};

#endif                                // struct_e_px4_internal_block_SampleTi_T

#ifndef struct_px4_internal_block_Subscriber_T
#define struct_px4_internal_block_Subscriber_T

struct px4_internal_block_Subscriber_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  e_px4_internal_block_SampleTi_T SampleTimeHandler;
  pollfd_t eventStructObj;
  orb_metadata_t * orbMetadataObj;
};

#endif                                // struct_px4_internal_block_Subscriber_T

#ifndef struct_px4_internal_block_PWM_px4log_T
#define struct_px4_internal_block_PWM_px4log_T

struct px4_internal_block_PWM_px4log_T
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

#endif                                // struct_px4_internal_block_PWM_px4log_T

#ifndef SS_INT64
#define SS_INT64                       34
#endif

#ifndef SS_UINT64
#define SS_UINT64                      35
#endif

// Parameters (default storage)
typedef struct P_px4log_T_ P_px4log_T;

// Forward declaration for rtModel
typedef struct tag_RTM_px4log_T RT_MODEL_px4log_T;

#endif                                 // RTW_HEADER_px4log_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
