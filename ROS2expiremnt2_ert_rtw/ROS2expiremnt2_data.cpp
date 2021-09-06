//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ROS2expiremnt2_data.cpp
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

// Block parameters (default storage)
P_ROS2expiremnt2_T ROS2expiremnt2_P = {
  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S5>/Out1'

  {
    0.0,                               // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // gyro_rad
    0U,                                // gyro_integral_dt
    0,                                 // accelerometer_timestamp_relative

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // accelerometer_m_s2
    0U,                                // accelerometer_integral_dt
    0U                                 // accelerometer_clipping
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S4>/Constant'

  {
    0.0,                               // timestamp

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // gyro_rad
    0U,                                // gyro_integral_dt
    0,                                 // accelerometer_timestamp_relative

    {
      0.0F, 0.0F, 0.0F }
    ,                                  // accelerometer_m_s2
    0U,                                // accelerometer_integral_dt
    0U                                 // accelerometer_clipping
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S1>/Constant'

  {
    0.0,                               // timestamp
    false,                             // position
    false,                             // velocity
    false,                             // acceleration
    false,                             // attitude
    false                              // body_rate
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<Root>/Constant'

  1,

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S2>/Out1'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
