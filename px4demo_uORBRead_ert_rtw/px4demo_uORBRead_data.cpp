//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_uORBRead_data.cpp
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
#include "px4demo_uORBRead.h"
#include "px4demo_uORBRead_private.h"

// Block parameters (default storage)
P_px4demo_uORBRead_T px4demo_uORBRead_P = {
  // Variable: Autopilot
  //  Referenced by:
  //    '<S26>/1-D Lookup Table3'
  //    '<S26>/1-D Lookup Table4'
  //    '<S26>/1-D Lookup Table5'

  {
    {
      { 0.30841, 0.24701, 0.22655, 0.067, 0.072, 0.075925, 0.028, 0.02989,
        0.03232, 0.0165, 0.0174, 0.01828, 0.0113, 0.0118, 0.01216, 0.0085,
        0.008722, 0.009118, 0.0068, 0.007003, 0.00721, 0.00568, 0.005806,
        0.005986, 0.00486, 0.004951, 0.005104, 0.00422, 0.004303, 0.004456 },

      { 3.358, 2.989, 3.079, 3.817, 3.691, 3.574, 4.456, 4.4, 4.096, 4.609,
        4.609, 4.609, 5.14, 4.951, 5.014, 5.32, 5.32, 5.284, 5.626, 5.437, 5.374,
        5.716, 5.68, 5.437, 5.869, 5.833, 5.527, 6.14, 6.022, 5.473 },

      { 0.7945, 1.279, 1.126, 1.369, 1.432, 1.432, 1.549, 1.792, 1.675, 2.1493,
        1.981, 1.765, 2.1493, 2.071, 1.855, 2.251, 2.134, 2.0, 2.314, 2.224,
        2.224, 2.35, 2.287, 2.458, 2.35, 2.3, 2.62, 2.35, 2.404, 2.836 },

      { 10.0, 1000.0, 2000.0 },

      { 20.0, 50.0, 80.0, 110.0, 140.0, 170.0, 200.0, 230.0, 260.0, 290.0 }
    },

    {
      { 0.7606, 0.87113, 0.81019, 0.2599, 0.3844, 0.4294, 0.06035, 0.08029,
        0.1432, 0.02404, 0.04123, 0.06049, 0.01, 0.03052, 0.0379, 0.00703,
        0.01063, 0.0253, 0.005356, 0.007039, 0.01945, 0.004366, 0.00593, 0.0136,
        0.003385, 0.005257, 0.01, 0.002773, 0.004708, 0.008191 },

      { 0.2089, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001,
        0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001,
        0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001, 0.0001,
        0.0001, 0.0001, 0.0001 },

      { 1.75, 0.7669, 0.8686, 0.54163, 0.3754, 0.3691, 0.9874, 0.7489, 0.4861,
        1.2704, 0.8191, 0.6328, 1.9221, 0.7057, 0.6328, 1.9221, 1.3217, 0.6445,
        1.73, 1.5003, 0.6139, 1.73, 1.3141, 0.685, 1.73, 1.2115, 0.712, 1.73,
        1.0443, 0.6877 },

      { 10.0, 1000.0, 2000.0 },

      { 20.0, 50.0, 80.0, 110.0, 140.0, 170.0, 200.0, 230.0, 260.0, 290.0 }
    },

    {
      { 0.7606, 0.87113, 0.81019, 0.2599, 0.3844, 0.4294, 0.06035, 0.08029,
        0.1432, 0.02404, 0.04123, 0.06049, 0.01, 0.03052, 0.0379, 0.00703,
        0.01063, 0.0253, 0.005356, 0.007039, 0.01945, 0.004366, 0.00593, 0.0136,
        0.003385, 0.005257, 0.01, 0.002773, 0.004708, 0.008191 },

      { -0.2089, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001,
        -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001,
        -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001,
        -0.0001, -0.0001, -0.0001, -0.0001, -0.0001, -0.0001 },

      { -1.75, -0.7669, -0.8686, -0.54163, -0.3754, -0.3691, -0.9874, -0.7489,
        -0.4861, -1.2704, -0.8191, -0.6328, -1.9221, -0.7057, -0.6328, -1.9221,
        -1.3217, -0.6445, -1.73, -1.5003, -0.6139, -1.73, -1.3141, -0.685, -1.73,
        -1.2115, -0.712, -1.73, -1.0443, -0.6877 },

      { 10.0, 1000.0, 2000.0 },

      { 20.0, 50.0, 80.0, 110.0, 140.0, 170.0, 200.0, 230.0, 260.0, 290.0 }
    },
    0.3490658503988659,
    -0.3490658503988659,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0
  },

  // Variable: Flight_Logic
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

  {
    40.0,
    0.3,
    0.3,
    0.5,
    0.5,
    999.0,
    999.0,
    999.0,
    0.0
  },

  // Mask Parameter: CompareToConstant2_const
  //  Referenced by: '<S44>/Constant'

  0.0,

  // Mask Parameter: CompareToConstant_const
  //  Referenced by: '<S33>/Constant'

  0.0,

  // Mask Parameter: DetectDecrease_vinit
  //  Referenced by: '<S36>/Delay Input1'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S73>/Out1'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S72>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame

    {
      0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S18>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // yaw
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // dist_bottom_rate
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S6>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // ref_timestamp
    0.0,                               // ref_lat
    0.0,                               // ref_lon
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F }
    ,                                  // delta_xy
    0.0F,                              // delta_z
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // z_deriv

    {
      0.0F, 0.0F }
    ,                                  // delta_vxy
    0.0F,                              // delta_vz
    0.0F,                              // ax
    0.0F,                              // ay
    0.0F,                              // az
    0.0F,                              // yaw
    0.0F,                              // ref_alt
    0.0F,                              // dist_bottom
    0.0F,                              // dist_bottom_rate
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // evh
    0.0F,                              // evv
    0.0F,                              // vxy_max
    0.0F,                              // vz_max
    0.0F,                              // hagl_min
    0.0F,                              // hagl_max
    false,                             // xy_valid
    false,                             // z_valid
    false,                             // v_xy_valid
    false,                             // v_z_valid
    0U,                                // xy_reset_counter
    0U,                                // z_reset_counter
    0U,                                // vxy_reset_counter
    0U,                                // vz_reset_counter
    false,                             // xy_global
    false,                             // z_global
    false,                             // dist_bottom_valid

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_hz
  //  Referenced by: '<S17>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // time_utc_usec
    0,                                 // lat
    0,                                 // lon
    0,                                 // alt
    0,                                 // alt_ellipsoid
    0.0F,                              // s_variance_m_s
    0.0F,                              // c_variance_rad
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // hdop
    0.0F,                              // vdop
    0,                                 // noise_per_ms
    0,                                 // jamming_indicator
    0.0F,                              // vel_m_s
    0.0F,                              // vel_n_m_s
    0.0F,                              // vel_e_m_s
    0.0F,                              // vel_d_m_s
    0.0F,                              // cog_rad
    0,                                 // timestamp_time_relative
    0.0F,                              // heading
    0.0F,                              // heading_offset
    0U,                                // fix_type
    false,                             // vel_ned_valid
    0U,                                // satellites_used

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S5>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // time_utc_usec
    0,                                 // lat
    0,                                 // lon
    0,                                 // alt
    0,                                 // alt_ellipsoid
    0.0F,                              // s_variance_m_s
    0.0F,                              // c_variance_rad
    0.0F,                              // eph
    0.0F,                              // epv
    0.0F,                              // hdop
    0.0F,                              // vdop
    0,                                 // noise_per_ms
    0,                                 // jamming_indicator
    0.0F,                              // vel_m_s
    0.0F,                              // vel_n_m_s
    0.0F,                              // vel_e_m_s
    0.0F,                              // vel_d_m_s
    0.0F,                              // cog_rad
    0,                                 // timestamp_time_relative
    0.0F,                              // heading
    0.0F,                              // heading_offset
    0U,                                // fix_type
    false,                             // vel_ned_valid
    0U,                                // satellites_used

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S70>/Constant'

  {
    (0ULL),                            // timestamp

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // text
    0U,                                // severity

    {
      0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_hh
  //  Referenced by: '<S14>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // error_count
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0U,                                // integral_dt
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // scaling
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S13>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // error_count
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0U,                                // integral_dt
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // scaling
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_c
  //  Referenced by: '<S16>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // error_count
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0U,                                // integral_dt
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // scaling
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S15>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // error_count
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0U,                                // integral_dt
    0.0F,                              // x_integral
    0.0F,                              // y_integral
    0.0F,                              // z_integral
    0.0F,                              // temperature
    0.0F,                              // scaling
    0,                                 // x_raw
    0,                                 // y_raw
    0,                                 // z_raw

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S4>/Constant'

  {
    (0ULL),                            // timestamp
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // name

    {
      0U, 0U }
    // _padding0
  },

  // Expression: 600
  //  Referenced by: '<S29>/Constant4'

  600.0,

  // Expression: 500
  //  Referenced by: '<S29>/Constant6'

  500.0,

  // Expression: 400
  //  Referenced by: '<S29>/Constant3'

  400.0,

  // Expression: 300
  //  Referenced by: '<S29>/Constant2'

  300.0,

  // Expression: 200
  //  Referenced by: '<S29>/Constant1'

  200.0,

  // Expression: 1
  //  Referenced by: '<S29>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<S22>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S29>/Constant5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S30>/Constant'

  0.0,

  // Expression: 2000
  //  Referenced by: '<S23>/One5'

  2000.0,

  // Expression: 1000
  //  Referenced by: '<S23>/One6'

  1000.0,

  // Expression: 1
  //  Referenced by: '<S19>/One1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S19>/One2'

  0.0,

  // Expression: 5
  //  Referenced by: '<S24>/One5'

  5.0,

  // Expression: pi/180
  //  Referenced by: '<S56>/Gain1'

  0.017453292519943295,

  // Expression: 5
  //  Referenced by: '<S24>/One6'

  5.0,

  // Expression: pi/180
  //  Referenced by: '<S57>/Gain1'

  0.017453292519943295,

  // Expression: 5
  //  Referenced by: '<S24>/One7'

  5.0,

  // Expression: pi/180
  //  Referenced by: '<S58>/Gain1'

  0.017453292519943295,

  // Expression: 5
  //  Referenced by: '<S24>/One8'

  5.0,

  // Expression: pi/180
  //  Referenced by: '<S59>/Gain1'

  0.017453292519943295,

  // Computed Parameter: Pix_Out_Y0
  //  Referenced by: '<S19>/Pix_Out'

  0.0,

  // Expression: [num_lpf_d]
  //  Referenced by: '<S20>/Discrete Transfer Fcn'

  { 0.38586954509503751, 0.38586954509503751 },

  // Expression: [den_lpf_d]
  //  Referenced by: '<S20>/Discrete Transfer Fcn'

  { 1.0, -0.22826090980992489 },

  // Expression: 0
  //  Referenced by: '<S20>/Discrete Transfer Fcn'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S25>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S20>/Zero'

  0.0,

  // Expression: [num_lpf_d]
  //  Referenced by: '<S19>/Discrete Transfer Fcn'

  { 0.38586954509503751, 0.38586954509503751 },

  // Expression: [den_lpf_d]
  //  Referenced by: '<S19>/Discrete Transfer Fcn'

  { 1.0, -0.22826090980992489 },

  // Expression: 0
  //  Referenced by: '<S19>/Discrete Transfer Fcn'

  0.0,

  // Expression: 0
  //  Referenced by: '<S41>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_p
  //  Referenced by: '<S41>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S46>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_h
  //  Referenced by: '<S46>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S37>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_n
  //  Referenced by: '<S37>/Discrete-Time Integrator'

  0.005,

  // Expression: 0
  //  Referenced by: '<S50>/Constant1'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_b
  //  Referenced by: '<S50>/Discrete-Time Integrator'

  0.005,

  // Expression: 180/pi
  //  Referenced by: '<S52>/Gain'

  57.295779513082323,

  // Expression: 20
  //  Referenced by: '<S23>/Saturation'

  20.0,

  // Expression: -20
  //  Referenced by: '<S23>/Saturation'

  -20.0,

  // Expression: 1000/91
  //  Referenced by: '<S23>/Gain'

  10.989010989010989,

  // Expression: 900
  //  Referenced by: '<S23>/One'

  900.0,

  // Expression: 180/pi
  //  Referenced by: '<S53>/Gain'

  57.295779513082323,

  // Expression: 20
  //  Referenced by: '<S23>/Saturation1'

  20.0,

  // Expression: -20
  //  Referenced by: '<S23>/Saturation1'

  -20.0,

  // Expression: 1000/91
  //  Referenced by: '<S23>/Gain1'

  10.989010989010989,

  // Expression: 900
  //  Referenced by: '<S23>/One1'

  900.0,

  // Expression: 180/pi
  //  Referenced by: '<S54>/Gain'

  57.295779513082323,

  // Expression: 20
  //  Referenced by: '<S23>/Saturation2'

  20.0,

  // Expression: -20
  //  Referenced by: '<S23>/Saturation2'

  -20.0,

  // Expression: 1000/91
  //  Referenced by: '<S23>/Gain2'

  10.989010989010989,

  // Expression: 900
  //  Referenced by: '<S23>/One2'

  900.0,

  // Expression: 180/pi
  //  Referenced by: '<S55>/Gain'

  57.295779513082323,

  // Expression: 20
  //  Referenced by: '<S23>/Saturation3'

  20.0,

  // Expression: -20
  //  Referenced by: '<S23>/Saturation3'

  -20.0,

  // Expression: 1000/91
  //  Referenced by: '<S23>/Gain3'

  10.989010989010989,

  // Expression: 900
  //  Referenced by: '<S23>/One3'

  900.0,

  // Expression: 1
  //  Referenced by: '<S37>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S41>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S46>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S50>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S63>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S64>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Read Parameter'

  1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Read Parameter1'

  1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Read Parameter2'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant2'

  0.0,

  // Expression: 1
  //  Referenced by: '<S8>/100 Hz'

  1.0,

  // Computed Parameter: u00Hz_Period
  //  Referenced by: '<S8>/100 Hz'

  2.0,

  // Computed Parameter: u00Hz_Duty
  //  Referenced by: '<S8>/100 Hz'

  1.0,

  // Expression: 0
  //  Referenced by: '<S8>/100 Hz'

  0.0,

  // Computed Parameter: StringConstant_String
  //  Referenced by: '<S11>/String Constant'

  "The fucking Missile is READY! (Hope so)",

  // Computed Parameter: RateTransition1_InitialConditio
  //  Referenced by: '<Root>/Rate Transition1'

  1,

  // Expression: HIL_Data.FDM.Tr4r3
  //  Referenced by: '<S27>/Constant7'

  { 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, -1.0F },

  // Computed Parameter: Constant_Value_oa
  //  Referenced by: '<S25>/Constant'

  0.0F,

  // Computed Parameter: RateTransition_InitialCondition
  //  Referenced by: '<Root>/Rate Transition'

  1.0F,

  // Computed Parameter: RateTransition3_InitialConditio
  //  Referenced by: '<Root>/Rate Transition3'

  1.0F,

  // Computed Parameter: uDLookupTable3_maxIndex
  //  Referenced by: '<S26>/1-D Lookup Table3'

  { 2U, 9U },

  // Computed Parameter: uDLookupTable5_maxIndex
  //  Referenced by: '<S26>/1-D Lookup Table5'

  { 2U, 9U },

  // Computed Parameter: uDLookupTable4_maxIndex
  //  Referenced by: '<S26>/1-D Lookup Table4'

  { 2U, 9U },

  // Computed Parameter: Memory_InitialCondition
  //  Referenced by: '<S30>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_d
  //  Referenced by: '<S42>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_b
  //  Referenced by: '<S47>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_o
  //  Referenced by: '<S38>/Memory'

  0,

  // Computed Parameter: Memory_InitialCondition_m
  //  Referenced by: '<S51>/Memory'

  0,

  // Computed Parameter: One7_Value_b
  //  Referenced by: '<S23>/One7'

  1,

  // Computed Parameter: One4_Value
  //  Referenced by: '<S23>/One4'

  0,

  // Computed Parameter: Constant_Value_cd
  //  Referenced by: '<S11>/Constant'

  7U
};

//
// File trailer for generated code.
//
// [EOF]
//
