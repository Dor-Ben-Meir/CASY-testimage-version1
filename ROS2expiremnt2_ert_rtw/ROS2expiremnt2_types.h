//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS2expiremnt2_types.h
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
#ifndef RTW_HEADER_ROS2expiremnt2_types_h_
#define RTW_HEADER_ROS2expiremnt2_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_px4_msgs_OffboardControlMode_
#define DEFINED_TYPEDEF_FOR_SL_Bus_px4_msgs_OffboardControlMode_

// MsgType=px4_msgs/OffboardControlMode
struct SL_Bus_px4_msgs_OffboardControlMode
{
  // Int64Type=uint64
  real_T timestamp;
  boolean_T position;
  boolean_T velocity;
  boolean_T acceleration;
  boolean_T attitude;
  boolean_T body_rate;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_px4_msgs_SensorCombined_
#define DEFINED_TYPEDEF_FOR_SL_Bus_px4_msgs_SensorCombined_

// MsgType=px4_msgs/SensorCombined
struct SL_Bus_px4_msgs_SensorCombined
{
  // Int64Type=uint64
  real_T timestamp;
  real32_T gyro_rad[3];
  uint32_T gyro_integral_dt;
  int32_T accelerometer_timestamp_relative;
  real32_T accelerometer_m_s2[3];
  uint32_T accelerometer_integral_dt;
  uint8_T accelerometer_clipping;
};

#endif

// Custom Type definition for MATLABSystem: '<S4>/SourceBlock'
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include "rmw/types.h"
#include "rmw/types.h"
#ifndef struct_ros_slros2_internal_block_Pub_T
#define struct_ros_slros2_internal_block_Pub_T

struct ros_slros2_internal_block_Pub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros2_internal_block_Pub_T

#ifndef struct_ros_slros2_internal_block_Sub_T
#define struct_ros_slros2_internal_block_Sub_T

struct ros_slros2_internal_block_Sub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros2_internal_block_Sub_T

// Parameters (default storage)
typedef struct P_ROS2expiremnt2_T_ P_ROS2expiremnt2_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ROS2expiremnt2_T RT_MODEL_ROS2expiremnt2_T;

#endif                                 // RTW_HEADER_ROS2expiremnt2_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
