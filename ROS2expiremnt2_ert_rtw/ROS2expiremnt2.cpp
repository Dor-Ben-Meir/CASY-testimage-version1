//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS2expiremnt2.cpp
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
#include "ROS2expiremnt2.h"
#include "ROS2expiremnt2_private.h"

// Block signals (default storage)
B_ROS2expiremnt2_T ROS2expiremnt2_B;

// Block states (default storage)
DW_ROS2expiremnt2_T ROS2expiremnt2_DW;

// Real-time model
RT_MODEL_ROS2expiremnt2_T ROS2expiremnt2_M_ = RT_MODEL_ROS2expiremnt2_T();
RT_MODEL_ROS2expiremnt2_T *const ROS2expiremnt2_M = &ROS2expiremnt2_M_;

// Forward declaration for local functions
static void ROS2expiremnt2_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj);
static void ROS2expiremn_SystemCore_setup_h(ros_slros2_internal_block_Sub_T *obj);
static void ROS2expiremnt2_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  int32_T i;
  static const char_T tmp[31] = { 'O', 'f', 'f', 'b', 'o', 'a', 'r', 'd', 'C',
    'o', 'n', 't', 'r', 'o', 'l', 'M', 'o', 'd', 'e', '_', 'P', 'u', 'b', 'S',
    'u', 'b', 'T', 'o', 'p', 'i', 'c' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (i = 0; i < 31; i++) {
    ROS2expiremnt2_B.b_zeroDelimTopic[i] = tmp[i];
  }

  ROS2expiremnt2_B.b_zeroDelimTopic[31] = '\x00';
  ros2::matlab::create_Pub_ROS2expiremnt2_14(&ROS2expiremnt2_B.b_zeroDelimTopic
    [0], qos_profile);
  obj->isSetupComplete = true;
}

static void ROS2expiremn_SystemCore_setup_h(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  int32_T i;
  char_T b_zeroDelimTopic[28];
  static const char_T tmp[27] = { '/', 'S', 'e', 'n', 's', 'o', 'r', 'C', 'o',
    'm', 'b', 'i', 'n', 'e', 'd', '_', 'P', 'u', 'b', 'S', 'u', 'b', 'T', 'o',
    'p', 'i', 'c' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (i = 0; i < 27; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[27] = '\x00';
  ros2::matlab::create_Sub_ROS2expiremnt2_1(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void ROS2expiremnt2_step(void)
{
  SL_Bus_px4_msgs_OffboardControlMode rtb_BusAssignment;
  SL_Bus_px4_msgs_SensorCombined b_varargout_2;

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<S1>/Constant'

  rtb_BusAssignment = ROS2expiremnt2_P.Constant_Value_o;
  rtb_BusAssignment.attitude = ROS2expiremnt2_P.Constant_Value_a;

  // MATLABSystem: '<S3>/SinkBlock'
  ros2::matlab::publish_Pub_ROS2expiremnt2_14(&rtb_BusAssignment);

  // MATLABSystem: '<S4>/SourceBlock'
  ros2::matlab::getLatestMessage_Sub_ROS2expiremnt2_1(&b_varargout_2);
}

// Model initialize function
void ROS2expiremnt2_initialize(void)
{
  // Start for MATLABSystem: '<S3>/SinkBlock'
  ROS2expiremnt2_DW.obj.isInitialized = 0;
  ROS2expiremnt2_DW.obj.matlabCodegenIsDeleted = false;
  ROS2expiremnt2_SystemCore_setup(&ROS2expiremnt2_DW.obj);

  // Start for MATLABSystem: '<S4>/SourceBlock'
  ROS2expiremnt2_DW.obj_n.isInitialized = 0;
  ROS2expiremnt2_DW.obj_n.matlabCodegenIsDeleted = false;
  ROS2expiremn_SystemCore_setup_h(&ROS2expiremnt2_DW.obj_n);
}

// Model terminate function
void ROS2expiremnt2_terminate(void)
{
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!ROS2expiremnt2_DW.obj.matlabCodegenIsDeleted) {
    ROS2expiremnt2_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'

  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!ROS2expiremnt2_DW.obj_n.matlabCodegenIsDeleted) {
    ROS2expiremnt2_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
