//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Copy_of_Corneto_flight_program_control.cpp
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
#include "Copy_of_Corneto_flight_program_control.h"
#include "Copy_of_Corneto_flight_program_control_private.h"

// Block signals (default storage)
B_Copy_of_Corneto_flight_prog_T Copy_of_Corneto_flight_progra_B;

// Block states (default storage)
DW_Copy_of_Corneto_flight_pro_T Copy_of_Corneto_flight_progr_DW;

// Previous zero-crossings (trigger) states
PrevZCX_Copy_of_Corneto_fligh_T Copy_of_Corneto_flight__PrevZCX;

// Real-time model
RT_MODEL_Copy_of_Corneto_flig_T Copy_of_Corneto_flight_progr_M_ =
  RT_MODEL_Copy_of_Corneto_flig_T();
RT_MODEL_Copy_of_Corneto_flig_T *const Copy_of_Corneto_flight_progr_M =
  &Copy_of_Corneto_flight_progr_M_;

// Forward declaration for local functions
static void Copy_of_Cornet_SystemCore_setup(px4_internal_block_PWM_Copy_o_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_scheduler(void);
real_T look2_binlcapw(real_T u0, real_T u1, const real_T bp0[], const real_T
                      bp1[], const real_T table[], const uint32_T maxIndex[],
                      uint32_T stride)
{
  real_T fractions[2];
  real_T frac;
  real_T y;
  real_T yL_0d0;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  // Column-major Lookup 2-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Clip'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    // Binary Search
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U];
    frac = 0.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Clip'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    // Binary Search
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0;
  }

  // Column-major Interpolation 2-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'on'
  // Overflow mode: 'portable wrapping'

  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1U] - yL_0d0) * fractions[0U] + yL_0d0;
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (Copy_of_Corneto_flight_progr_M->Timing.TaskCounters.TID[1])++;
  if ((Copy_of_Corneto_flight_progr_M->Timing.TaskCounters.TID[1]) > 199) {// Sample time: [1.0s, 0.0s] 
    Copy_of_Corneto_flight_progr_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(static_cast<real_T>(u0_0), static_cast<real_T>(u1_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void Copy_of_Cornet_SystemCore_setup(px4_internal_block_PWM_Copy_o_T *obj,
  boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->isMain = false;
  obj->pwmDevObj = MW_PWM_OUTPUT_AUX_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj,
                    &obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    status = pwm_disarm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->channelMask = 31;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain, &obj->actuatorAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, static_cast<int32_T>
      (varargin_2));
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, 0);
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  }

  obj->isSetupComplete = true;
}

// Model step function
void Copy_of_Corneto_flight_program_control_step(void)
{
  uint8_T elem_type;
  static const char_T mlStrVer[5] = { 'M', 'W', 'L', 'O', 'G' };

  g_dsp_private_SlidingWindowAv_T *obj;
  real_T rtb_TmpSignalConversionAtSFun_0;
  int32_T i;
  int32_T rtb_ReadParameter2_o1;
  real32_T rtb_DataTypeConversion2;
  real32_T rtb_DataTypeConversion3;
  uint32_T EmulatedPixhawk_ELAPS_T;
  uint32_T tm;
  uint16_T status;
  char_T d[3];
  boolean_T rtb_CastToBoolean2;
  boolean_T rtb_MECO_log;
  boolean_T rtb_NOT;
  boolean_T rtb_NOT_c;
  boolean_T rtb_NOT_f;
  ZCEventType zcEvent;
  static const char_T g[24] = "/fs/microsd/log/pwm.bin";
  static const char_T f[28] = "CLOSING file. count = %d %c";
  static const char_T i_0[56] =
    "OPENING file %s vect_size %d elem_size %d numRecs %d %c";

  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S16>/In1'

  rtb_NOT = uORB_read_step(Copy_of_Corneto_flight_progr_DW.obj_k.orbMetadataObj,
    &Copy_of_Corneto_flight_progr_DW.obj_k.eventStructObj,
    &Copy_of_Corneto_flight_progra_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S16>/Enable'

  if (rtb_NOT) {
    Copy_of_Corneto_flight_progra_B.In1_a =
      Copy_of_Corneto_flight_progra_B.b_varargout_2_c;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // MATLABSystem: '<S64>/SourceBlock' incorporates:
  //   Inport: '<S65>/In1'

  rtb_NOT = uORB_read_step(Copy_of_Corneto_flight_progr_DW.obj_n.orbMetadataObj,
    &Copy_of_Corneto_flight_progr_DW.obj_n.eventStructObj,
    &Copy_of_Corneto_flight_progra_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S64>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S65>/Enable'

  if (rtb_NOT) {
    Copy_of_Corneto_flight_progra_B.In1 =
      Copy_of_Corneto_flight_progra_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S64>/SourceBlock'
  // End of Outputs for SubSystem: '<S64>/Enabled Subsystem'

  // MATLABSystem: '<S12>/SourceBlock' incorporates:
  //   Inport: '<S13>/In1'

  rtb_NOT = uORB_read_step(Copy_of_Corneto_flight_progr_DW.obj_j.orbMetadataObj,
    &Copy_of_Corneto_flight_progr_DW.obj_j.eventStructObj,
    &Copy_of_Corneto_flight_progra_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (rtb_NOT) {
    Copy_of_Corneto_flight_progra_B.In1_i =
      Copy_of_Corneto_flight_progra_B.b_varargout_2_k;
  }

  // End of MATLABSystem: '<S12>/SourceBlock'
  // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'

  // MATLABSystem: '<S14>/SourceBlock' incorporates:
  //   Inport: '<S15>/In1'

  rtb_NOT = uORB_read_step(Copy_of_Corneto_flight_progr_DW.obj_nc.orbMetadataObj,
    &Copy_of_Corneto_flight_progr_DW.obj_nc.eventStructObj,
    &Copy_of_Corneto_flight_progra_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  if (rtb_NOT) {
    Copy_of_Corneto_flight_progra_B.In1_eg =
      Copy_of_Corneto_flight_progra_B.b_varargout_2_cx;
  }

  // End of MATLABSystem: '<S14>/SourceBlock'
  // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S17>/In1'

  rtb_NOT = uORB_read_step(Copy_of_Corneto_flight_progr_DW.obj_f.orbMetadataObj,
    &Copy_of_Corneto_flight_progr_DW.obj_f.eventStructObj,
    &Copy_of_Corneto_flight_progra_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S17>/Enable'

  if (rtb_NOT) {
    Copy_of_Corneto_flight_progra_B.In1_e =
      Copy_of_Corneto_flight_progra_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // Sqrt: '<S60>/sqrt' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'
  //   Product: '<S61>/Product'
  //   Product: '<S61>/Product1'
  //   Product: '<S61>/Product2'
  //   Product: '<S61>/Product3'
  //   Sum: '<S61>/Sum'

  Copy_of_Corneto_flight_progra_B.Product3_n = sqrt(((static_cast<real_T>
    (Copy_of_Corneto_flight_progra_B.In1.q[0]) *
    Copy_of_Corneto_flight_progra_B.In1.q[0] + static_cast<real_T>
    (Copy_of_Corneto_flight_progra_B.In1.q[1]) *
    Copy_of_Corneto_flight_progra_B.In1.q[1]) + static_cast<real_T>
    (Copy_of_Corneto_flight_progra_B.In1.q[2]) *
    Copy_of_Corneto_flight_progra_B.In1.q[2]) + static_cast<real_T>
    (Copy_of_Corneto_flight_progra_B.In1.q[3]) *
    Copy_of_Corneto_flight_progra_B.In1.q[3]);

  // Product: '<S55>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  Copy_of_Corneto_flight_progra_B.Kp_phi =
    Copy_of_Corneto_flight_progra_B.In1.q[0] /
    Copy_of_Corneto_flight_progra_B.Product3_n;

  // Product: '<S55>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  Copy_of_Corneto_flight_progra_B.Sum3 = Copy_of_Corneto_flight_progra_B.In1.q[1]
    / Copy_of_Corneto_flight_progra_B.Product3_n;

  // Product: '<S55>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  Copy_of_Corneto_flight_progra_B.Product2_f =
    Copy_of_Corneto_flight_progra_B.In1.q[2] /
    Copy_of_Corneto_flight_progra_B.Product3_n;

  // Product: '<S55>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  Copy_of_Corneto_flight_progra_B.Product3_n =
    Copy_of_Corneto_flight_progra_B.In1.q[3] /
    Copy_of_Corneto_flight_progra_B.Product3_n;

  // Fcn: '<S9>/fcn2' incorporates:
  //   Fcn: '<S9>/fcn5'

  Copy_of_Corneto_flight_progra_B.t = Copy_of_Corneto_flight_progra_B.Kp_phi *
    Copy_of_Corneto_flight_progra_B.Kp_phi;
  rtb_TmpSignalConversionAtSFun_0 = Copy_of_Corneto_flight_progra_B.Sum3 *
    Copy_of_Corneto_flight_progra_B.Sum3;
  Copy_of_Corneto_flight_progra_B.cumRevIndex =
    Copy_of_Corneto_flight_progra_B.Product2_f *
    Copy_of_Corneto_flight_progra_B.Product2_f;
  Copy_of_Corneto_flight_progra_B.flight_mode_enum =
    Copy_of_Corneto_flight_progra_B.Product3_n *
    Copy_of_Corneto_flight_progra_B.Product3_n;

  // SignalConversion generated from: '<S63>/ SFunction ' incorporates:
  //   Fcn: '<S9>/fcn1'
  //   Fcn: '<S9>/fcn2'
  //   MATLAB Function: '<S62>/SDCard_logger'
  //   Trigonometry: '<S54>/Trigonometric Function1'

  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[12] =
    rt_atan2d_snf((Copy_of_Corneto_flight_progra_B.Sum3 *
                   Copy_of_Corneto_flight_progra_B.Product2_f +
                   Copy_of_Corneto_flight_progra_B.Kp_phi *
                   Copy_of_Corneto_flight_progra_B.Product3_n) * 2.0,
                  ((Copy_of_Corneto_flight_progra_B.t +
                    rtb_TmpSignalConversionAtSFun_0) -
                   Copy_of_Corneto_flight_progra_B.cumRevIndex) -
                  Copy_of_Corneto_flight_progra_B.flight_mode_enum);

  // Fcn: '<S9>/fcn3'
  Copy_of_Corneto_flight_progra_B.fcn3 = (Copy_of_Corneto_flight_progra_B.Sum3 *
    Copy_of_Corneto_flight_progra_B.Product3_n -
    Copy_of_Corneto_flight_progra_B.Kp_phi *
    Copy_of_Corneto_flight_progra_B.Product2_f) * -2.0;

  // If: '<S56>/If' incorporates:
  //   Constant: '<S57>/Constant'
  //   Constant: '<S58>/Constant'

  if (Copy_of_Corneto_flight_progra_B.fcn3 > 1.0) {
    Copy_of_Corneto_flight_progra_B.fcn3 =
      Copy_of_Corneto_flight_progra_P.Constant_Value_ki;
  } else if (Copy_of_Corneto_flight_progra_B.fcn3 < -1.0) {
    Copy_of_Corneto_flight_progra_B.fcn3 =
      Copy_of_Corneto_flight_progra_P.Constant_Value_g0;
  }

  // End of If: '<S56>/If'

  // Trigonometry: '<S54>/Trigonometric Function3' incorporates:
  //   Fcn: '<S9>/fcn4'
  //   Fcn: '<S9>/fcn5'

  Copy_of_Corneto_flight_progra_B.Product3_n = rt_atan2d_snf
    ((Copy_of_Corneto_flight_progra_B.Product2_f *
      Copy_of_Corneto_flight_progra_B.Product3_n +
      Copy_of_Corneto_flight_progra_B.Kp_phi *
      Copy_of_Corneto_flight_progra_B.Sum3) * 2.0,
     ((Copy_of_Corneto_flight_progra_B.t - rtb_TmpSignalConversionAtSFun_0) -
      Copy_of_Corneto_flight_progra_B.cumRevIndex) +
     Copy_of_Corneto_flight_progra_B.flight_mode_enum);

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double29'
  //   DataTypeConversion: '<Root>/Cast To Double30'
  //   DataTypeConversion: '<Root>/Cast To Double31'

  Copy_of_Corneto_flight_progra_B.Sum3 = 3.3121686421112381E-170;
  Copy_of_Corneto_flight_progra_B.Product2_f = fabs(static_cast<real_T>
    (Copy_of_Corneto_flight_progra_B.In1_e.vx));
  if (Copy_of_Corneto_flight_progra_B.Product2_f > 3.3121686421112381E-170) {
    Copy_of_Corneto_flight_progra_B.Kp_phi = 1.0;
    Copy_of_Corneto_flight_progra_B.Sum3 =
      Copy_of_Corneto_flight_progra_B.Product2_f;
  } else {
    Copy_of_Corneto_flight_progra_B.t =
      Copy_of_Corneto_flight_progra_B.Product2_f / 3.3121686421112381E-170;
    Copy_of_Corneto_flight_progra_B.Kp_phi = Copy_of_Corneto_flight_progra_B.t *
      Copy_of_Corneto_flight_progra_B.t;
  }

  Copy_of_Corneto_flight_progra_B.Product2_f = fabs(static_cast<real_T>
    (Copy_of_Corneto_flight_progra_B.In1_e.vy));
  if (Copy_of_Corneto_flight_progra_B.Product2_f >
      Copy_of_Corneto_flight_progra_B.Sum3) {
    Copy_of_Corneto_flight_progra_B.t = Copy_of_Corneto_flight_progra_B.Sum3 /
      Copy_of_Corneto_flight_progra_B.Product2_f;
    Copy_of_Corneto_flight_progra_B.Kp_phi =
      Copy_of_Corneto_flight_progra_B.Kp_phi * Copy_of_Corneto_flight_progra_B.t
      * Copy_of_Corneto_flight_progra_B.t + 1.0;
    Copy_of_Corneto_flight_progra_B.Sum3 =
      Copy_of_Corneto_flight_progra_B.Product2_f;
  } else {
    Copy_of_Corneto_flight_progra_B.t =
      Copy_of_Corneto_flight_progra_B.Product2_f /
      Copy_of_Corneto_flight_progra_B.Sum3;
    Copy_of_Corneto_flight_progra_B.Kp_phi += Copy_of_Corneto_flight_progra_B.t *
      Copy_of_Corneto_flight_progra_B.t;
  }

  Copy_of_Corneto_flight_progra_B.Product2_f = fabs(static_cast<real_T>
    (Copy_of_Corneto_flight_progra_B.In1_e.vz));
  if (Copy_of_Corneto_flight_progra_B.Product2_f >
      Copy_of_Corneto_flight_progra_B.Sum3) {
    Copy_of_Corneto_flight_progra_B.t = Copy_of_Corneto_flight_progra_B.Sum3 /
      Copy_of_Corneto_flight_progra_B.Product2_f;
    Copy_of_Corneto_flight_progra_B.Kp_phi =
      Copy_of_Corneto_flight_progra_B.Kp_phi * Copy_of_Corneto_flight_progra_B.t
      * Copy_of_Corneto_flight_progra_B.t + 1.0;
    Copy_of_Corneto_flight_progra_B.Sum3 =
      Copy_of_Corneto_flight_progra_B.Product2_f;
  } else {
    Copy_of_Corneto_flight_progra_B.t =
      Copy_of_Corneto_flight_progra_B.Product2_f /
      Copy_of_Corneto_flight_progra_B.Sum3;
    Copy_of_Corneto_flight_progra_B.Kp_phi += Copy_of_Corneto_flight_progra_B.t *
      Copy_of_Corneto_flight_progra_B.t;
  }

  Copy_of_Corneto_flight_progra_B.Kp_phi = Copy_of_Corneto_flight_progra_B.Sum3 *
    sqrt(Copy_of_Corneto_flight_progra_B.Kp_phi);

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // RateTransition: '<Root>/Rate Transition' incorporates:
  //   RateTransition: '<Root>/Rate Transition1'

  if (Copy_of_Corneto_flight_progr_M->Timing.TaskCounters.TID[1] == 0) {
    // RateTransition: '<Root>/Rate Transition'
    Copy_of_Corneto_flight_progra_B.RateTransition =
      Copy_of_Corneto_flight_progr_DW.RateTransition_Buffer0;

    // RateTransition: '<Root>/Rate Transition1'
    Copy_of_Corneto_flight_progra_B.RateTransition1 =
      Copy_of_Corneto_flight_progr_DW.RateTransition1_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition'

  // DiscretePulseGenerator: '<S8>/100 Hz'
  Copy_of_Corneto_flight_progra_B.Sum3 =
    (Copy_of_Corneto_flight_progr_DW.clockTickCounter <
     Copy_of_Corneto_flight_progra_P.u00Hz_Duty) &&
    (Copy_of_Corneto_flight_progr_DW.clockTickCounter >= 0) ?
    Copy_of_Corneto_flight_progra_P.u00Hz_Amp : 0.0;
  if (Copy_of_Corneto_flight_progr_DW.clockTickCounter >=
      Copy_of_Corneto_flight_progra_P.u00Hz_Period - 1.0) {
    Copy_of_Corneto_flight_progr_DW.clockTickCounter = 0;
  } else {
    Copy_of_Corneto_flight_progr_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S8>/100 Hz'

  // Outputs for Triggered SubSystem: '<S8>/Emulated Pixhawk' incorporates:
  //   TriggerPort: '<S18>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Copy_of_Corneto_flight__PrevZCX.EmulatedPixhawk_Trig_ZCE,
                     (Copy_of_Corneto_flight_progra_B.Sum3));
  if (zcEvent != NO_ZCEVENT) {
    if (Copy_of_Corneto_flight_progr_DW.EmulatedPixhawk_RESET_ELAPS_T) {
      EmulatedPixhawk_ELAPS_T = 0U;
    } else {
      EmulatedPixhawk_ELAPS_T =
        Copy_of_Corneto_flight_progr_M->Timing.clockTick0 -
        Copy_of_Corneto_flight_progr_DW.EmulatedPixhawk_PREV_T;
    }

    Copy_of_Corneto_flight_progr_DW.EmulatedPixhawk_PREV_T =
      Copy_of_Corneto_flight_progr_M->Timing.clockTick0;
    Copy_of_Corneto_flight_progr_DW.EmulatedPixhawk_RESET_ELAPS_T = false;

    // DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double16'

    Copy_of_Corneto_flight_progra_B.Product2_f =
      (Copy_of_Corneto_flight_progra_B.In1.rollspeed -
       Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_DenCoef[1] *
       Copy_of_Corneto_flight_progr_DW.DiscreteTransferFcn_states) /
      Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_DenCoef[0];
    rtb_TmpSignalConversionAtSFun_0 =
      Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_NumCoef[0] *
      Copy_of_Corneto_flight_progra_B.Product2_f +
      Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_NumCoef[1] *
      Copy_of_Corneto_flight_progr_DW.DiscreteTransferFcn_states;

    // DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S23>/Constant'
    //   DataTypeConversion: '<S18>/Cast To Double36'

    if (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
      // Switch: '<S18>/Switch1' incorporates:
      //   Constant: '<S18>/One1'
      //   Constant: '<S18>/One2'
      //   DataTypeConversion: '<Root>/Cast To Boolean3'

      if (Copy_of_Corneto_flight_progra_B.RateTransition1 != 0) {
        Copy_of_Corneto_flight_progra_B.flight_mode_enum =
          Copy_of_Corneto_flight_progra_P.One1_Value;
      } else {
        Copy_of_Corneto_flight_progra_B.flight_mode_enum =
          Copy_of_Corneto_flight_progra_P.One2_Value;
      }

      if ((Copy_of_Corneto_flight_progra_B.flight_mode_enum != 0.0) ||
          (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRese != 0))
      {
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTAT_b5 =
          Copy_of_Corneto_flight_progra_P.Constant_Value_m;
      } else {
        // DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTAT_b5 +=
          static_cast<real32_T>
          (Copy_of_Corneto_flight_progra_P.DiscreteTimeIntegrator_gainval *
           static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
           * Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U);
      }
    }

    // End of DiscreteIntegrator: '<S23>/Discrete-Time Integrator'

    // Sum: '<S23>/Sum3' incorporates:
    //   Constant: '<Root>/Constant2'

    Copy_of_Corneto_flight_progra_B.Sum3 =
      Copy_of_Corneto_flight_progra_P.Constant2_Value_m -
      Copy_of_Corneto_flight_progra_B.Product3_n;

    // Product: '<S23>/Product1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'
    //   DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'
    //   Lookup_n-D: '<S24>/1-D Lookup Table3'
    //   Lookup_n-D: '<S24>/1-D Lookup Table5'
    //   Product: '<S23>/Product2'
    //   Sum: '<S23>/Sum4'
    //   Sum: '<S23>/Sum5'

    Copy_of_Corneto_flight_progra_B.t = ((look2_binlcapw(static_cast<real_T>
      (Copy_of_Corneto_flight_progra_B.In1_a.alt),
      Copy_of_Corneto_flight_progra_B.Kp_phi,
      Copy_of_Corneto_flight_progra_P.Autopilot.Phi.h_bkpts_m,
      Copy_of_Corneto_flight_progra_P.Autopilot.Phi.V_bkpts_mps,
      Copy_of_Corneto_flight_progra_P.Autopilot.Phi.Kp_phi_vec,
      Copy_of_Corneto_flight_progra_P.uDLookupTable5_maxIndex, 3U) *
      Copy_of_Corneto_flight_progra_B.Sum3 +
      Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTAT_b5) -
      rtb_TmpSignalConversionAtSFun_0) * look2_binlcapw(static_cast<real_T>
      (Copy_of_Corneto_flight_progra_B.In1_a.alt),
      Copy_of_Corneto_flight_progra_B.Kp_phi,
      Copy_of_Corneto_flight_progra_P.Autopilot.Phi.h_bkpts_m,
      Copy_of_Corneto_flight_progra_P.Autopilot.Phi.V_bkpts_mps,
      Copy_of_Corneto_flight_progra_P.Autopilot.Phi.Kp_p_vec,
      Copy_of_Corneto_flight_progra_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S25>/Product' incorporates:
    //   Constant: '<S19>/Zero'
    //   Constant: '<S25>/Constant7'

    for (i = 0; i < 4; i++) {
      Copy_of_Corneto_flight_progra_B.CastToDouble2[i] =
        Copy_of_Corneto_flight_progra_P.Constant7_Value[i + 8] *
        Copy_of_Corneto_flight_progra_P.Zero_Value +
        (Copy_of_Corneto_flight_progra_P.Constant7_Value[i + 4] *
         Copy_of_Corneto_flight_progra_P.Zero_Value +
         Copy_of_Corneto_flight_progra_P.Constant7_Value[i] *
         Copy_of_Corneto_flight_progra_B.t);
    }

    // End of Product: '<S25>/Product'

    // DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double13'

    Copy_of_Corneto_flight_progra_B.t = (Copy_of_Corneto_flight_progra_B.In1_i.x
      - Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_DenCoef_a[1] *
      Copy_of_Corneto_flight_progr_DW.DiscreteTransferFcn_states_b) /
      Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_DenCoef_a[0];
    Copy_of_Corneto_flight_progra_B.cumRevIndex =
      Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_NumCoef_b[0] *
      Copy_of_Corneto_flight_progra_B.t +
      Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_NumCoef_b[1] *
      Copy_of_Corneto_flight_progr_DW.DiscreteTransferFcn_states_b;

    // RelationalOperator: '<S37>/Compare' incorporates:
    //   Constant: '<S37>/Constant'
    //   DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn'

    rtb_CastToBoolean2 = (Copy_of_Corneto_flight_progra_B.cumRevIndex >=
                          Copy_of_Corneto_flight_progra_P.Flight_Logic.Ax_launch_accel_threshold_mps2);

    // Logic: '<S39>/NOT' incorporates:
    //   Logic: '<S39>/AND'
    //   Memory: '<S28>/Memory'

    rtb_NOT = ((!rtb_CastToBoolean2) &&
               (!Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput));

    // DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant1'

    if (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_d == 0) {
      if (rtb_NOT ||
          (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRe_h != 0))
      {
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE =
          Copy_of_Corneto_flight_progra_P.Constant1_Value_d;
      } else {
        // DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE +=
          Copy_of_Corneto_flight_progra_P.DiscreteTimeIntegrator_gainva_c *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U_e;
      }
    }

    // End of DiscreteIntegrator: '<S39>/Discrete-Time Integrator'

    // Switch: '<S40>/Switch1' incorporates:
    //   Constant: '<S38>/Constant'
    //   Logic: '<S28>/AND'
    //   Memory: '<S40>/Memory'
    //   RelationalOperator: '<S38>/Compare'

    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput = ((rtb_CastToBoolean2 &&
      (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE >=
       Copy_of_Corneto_flight_progra_P.Flight_Logic.Ax_launch_timer_threshold_sec))
      || Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_g);

    // Logic: '<S44>/NOT' incorporates:
    //   Constant: '<S42>/Constant'
    //   DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn'
    //   Logic: '<S29>/AND'
    //   RelationalOperator: '<S42>/Compare'

    rtb_CastToBoolean2 = ((!Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput)
                          || (!(Copy_of_Corneto_flight_progra_B.cumRevIndex <=
      Copy_of_Corneto_flight_progra_P.CompareToConstant2_const)));

    // DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S44>/Constant1'

    if (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_e == 0) {
      if (rtb_CastToBoolean2 ||
          (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRe_a != 0))
      {
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_f =
          Copy_of_Corneto_flight_progra_P.Constant1_Value_k;
      } else {
        // DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_f +=
          Copy_of_Corneto_flight_progra_P.DiscreteTimeIntegrator_gainva_h *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U_k;
      }
    }

    // End of DiscreteIntegrator: '<S44>/Discrete-Time Integrator'

    // Switch: '<S45>/Switch1' incorporates:
    //   Constant: '<S41>/Constant'
    //   Memory: '<S45>/Memory'
    //   RelationalOperator: '<S41>/Compare'

    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_o =
      ((Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_f >=
        Copy_of_Corneto_flight_progra_P.Flight_Logic.Ax_MECO_timer_threshold_sec)
       || Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_o);

    // Switch: '<S28>/Switch' incorporates:
    //   Constant: '<S28>/Constant'

    if (Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput) {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum =
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE;
    } else {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum =
        Copy_of_Corneto_flight_progra_P.Constant_Value_j;
    }

    // End of Switch: '<S28>/Switch'

    // Logic: '<S29>/AND1' incorporates:
    //   Constant: '<S43>/Constant'
    //   RelationalOperator: '<S43>/Compare'

    rtb_MECO_log = (Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_o ||
                    (Copy_of_Corneto_flight_progra_B.flight_mode_enum >=
                     Copy_of_Corneto_flight_progra_P.Flight_Logic.MECO_timeout_TOF_sec));

    // MATLABSystem: '<S26>/Moving Average1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'

    if (Copy_of_Corneto_flight_progr_DW.obj.TunablePropsChanged) {
      Copy_of_Corneto_flight_progr_DW.obj.TunablePropsChanged = false;
    }

    obj = Copy_of_Corneto_flight_progr_DW.obj.pStatistic;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      obj->pCumSum = 0.0;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
      obj->isSetupComplete = true;
      obj->pCumSum = 0.0;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
    }

    Copy_of_Corneto_flight_progra_B.cumRevIndex = obj->pCumRevIndex;
    Copy_of_Corneto_flight_progra_B.csum = obj->pCumSum;
    for (i = 0; i < 9; i++) {
      Copy_of_Corneto_flight_progra_B.csumrev[i] = obj->pCumSumRev[i];
    }

    Copy_of_Corneto_flight_progra_B.csum += static_cast<real_T>
      (Copy_of_Corneto_flight_progra_B.In1_a.alt);
    Copy_of_Corneto_flight_progra_B.z = Copy_of_Corneto_flight_progra_B.csumrev[
      static_cast<int32_T>(Copy_of_Corneto_flight_progra_B.cumRevIndex) - 1] +
      Copy_of_Corneto_flight_progra_B.csum;
    Copy_of_Corneto_flight_progra_B.csumrev[static_cast<int32_T>
      (Copy_of_Corneto_flight_progra_B.cumRevIndex) - 1] =
      Copy_of_Corneto_flight_progra_B.In1_a.alt;
    if (Copy_of_Corneto_flight_progra_B.cumRevIndex != 9.0) {
      Copy_of_Corneto_flight_progra_B.cumRevIndex++;
    } else {
      Copy_of_Corneto_flight_progra_B.cumRevIndex = 1.0;
      Copy_of_Corneto_flight_progra_B.csum = 0.0;
      for (i = 7; i >= 0; i--) {
        Copy_of_Corneto_flight_progra_B.csumrev[i] +=
          Copy_of_Corneto_flight_progra_B.csumrev[i + 1];
      }
    }

    obj->pCumSum = Copy_of_Corneto_flight_progra_B.csum;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = Copy_of_Corneto_flight_progra_B.csumrev[i];
    }

    obj->pCumRevIndex = Copy_of_Corneto_flight_progra_B.cumRevIndex;
    Copy_of_Corneto_flight_progra_B.cumRevIndex =
      Copy_of_Corneto_flight_progra_B.z / 10.0;

    // End of MATLABSystem: '<S26>/Moving Average1'

    // Logic: '<S35>/NOT' incorporates:
    //   RelationalOperator: '<S34>/FixPt Relational Operator'
    //   UnitDelay: '<S34>/Delay Input1'
    //
    //  Block description for '<S34>/Delay Input1':
    //
    //   Store in Global RAM

    rtb_NOT_c = !(Copy_of_Corneto_flight_progra_B.cumRevIndex <
                  Copy_of_Corneto_flight_progr_DW.DelayInput1_DSTATE);

    // DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant1'

    if (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_k == 0) {
      if (rtb_NOT_c ||
          (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRe_k != 0))
      {
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_b =
          Copy_of_Corneto_flight_progra_P.Constant1_Value_n;
      } else {
        // DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_b +=
          Copy_of_Corneto_flight_progra_P.DiscreteTimeIntegrator_gainv_hy *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U_h;
      }
    }

    // End of DiscreteIntegrator: '<S35>/Discrete-Time Integrator'

    // Switch: '<S36>/Switch1' incorporates:
    //   Constant: '<S31>/Constant'
    //   Constant: '<S32>/Constant'
    //   DataTypeConversion: '<Root>/Cast To Double31'
    //   Logic: '<S26>/AND'
    //   Memory: '<S36>/Memory'
    //   RelationalOperator: '<S31>/Compare'
    //   RelationalOperator: '<S32>/Compare'

    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_j = ((rtb_MECO_log &&
      (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_b >=
       Copy_of_Corneto_flight_progra_P.Flight_Logic.h_apogee_timer_threshold_sec)
      && (Copy_of_Corneto_flight_progra_B.In1_e.vz >
          Copy_of_Corneto_flight_progra_P.CompareToConstant_const)) ||
      Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_j);

    // Logic: '<S48>/NOT' incorporates:
    //   Constant: '<S33>/Constant'
    //   Logic: '<S26>/AND1'
    //   RelationalOperator: '<S33>/Compare'

    rtb_NOT_f = ((!Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_j) &&
                 (!(Copy_of_Corneto_flight_progra_B.flight_mode_enum >=
                    Copy_of_Corneto_flight_progra_P.Flight_Logic.apogee_timeout_TOF_sec)));

    // DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S48>/Constant1'

    if (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTE_es == 0) {
      if (rtb_NOT_f ||
          (Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRe_f != 0))
      {
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_d =
          Copy_of_Corneto_flight_progra_P.Constant1_Value_i;
      } else {
        // DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
        Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_d +=
          Copy_of_Corneto_flight_progra_P.DiscreteTimeIntegrator_gainv_c4 *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U_c;
      }
    }

    // End of DiscreteIntegrator: '<S48>/Discrete-Time Integrator'

    // Switch: '<S49>/Switch1' incorporates:
    //   Constant: '<S46>/Constant'
    //   Memory: '<S49>/Memory'
    //   RelationalOperator: '<S46>/Compare'

    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_ge =
      ((Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_d >=
        Copy_of_Corneto_flight_progra_P.Flight_Logic.apogee_recovery_timer_threshold_sec)
       || Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_ge);

    // DataTypeConversion: '<S18>/Cast To Double3' incorporates:
    //   DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'

    Copy_of_Corneto_flight_progra_B.CastToDouble3[4] =
      rtb_TmpSignalConversionAtSFun_0;

    // Switch: '<S27>/Switch3' incorporates:
    //   Constant: '<S21>/Constant5'
    //   Constant: '<S27>/Constant5'
    //   Constant: '<S30>/Constant'
    //   Constant: '<S47>/Constant'
    //   Logic: '<S30>/AND1'
    //   Logic: '<S30>/AND2'
    //   Logic: '<S30>/NOT'
    //   RelationalOperator: '<S47>/Compare'
    //   Switch: '<S27>/Switch'
    //   Switch: '<S27>/Switch1'
    //   Switch: '<S27>/Switch2'
    //   Switch: '<S27>/Switch4'

    if ((Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_ge ||
         (Copy_of_Corneto_flight_progra_B.flight_mode_enum >=
          Copy_of_Corneto_flight_progra_P.Flight_Logic.recovery_timeout_TOF_sec))
        &&
        (!(Copy_of_Corneto_flight_progra_P.Flight_Logic.disable_recovery_manual
           != 0.0))) {
      // DataTypeConversion: '<S18>/Cast To Double3' incorporates:
      //   Constant: '<S27>/Constant4'

      Copy_of_Corneto_flight_progra_B.CastToDouble3[5] =
        Copy_of_Corneto_flight_progra_P.Constant4_Value;
    } else if (Copy_of_Corneto_flight_progra_P.Constant5_Value_p != 0.0) {
      // Switch: '<S27>/Switch4' incorporates:
      //   Constant: '<S27>/Constant6'
      //   DataTypeConversion: '<S18>/Cast To Double3'

      Copy_of_Corneto_flight_progra_B.CastToDouble3[5] =
        Copy_of_Corneto_flight_progra_P.Constant6_Value;
    } else if (rtb_MECO_log) {
      // Switch: '<S27>/Switch2' incorporates:
      //   Constant: '<S27>/Constant3'
      //   DataTypeConversion: '<S18>/Cast To Double3'
      //   Switch: '<S27>/Switch4'

      Copy_of_Corneto_flight_progra_B.CastToDouble3[5] =
        Copy_of_Corneto_flight_progra_P.Constant3_Value;
    } else if (Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput) {
      // Switch: '<S27>/Switch1' incorporates:
      //   Constant: '<S27>/Constant2'
      //   DataTypeConversion: '<S18>/Cast To Double3'
      //   Switch: '<S27>/Switch2'
      //   Switch: '<S27>/Switch4'

      Copy_of_Corneto_flight_progra_B.CastToDouble3[5] =
        Copy_of_Corneto_flight_progra_P.Constant2_Value;
    } else if (Copy_of_Corneto_flight_progra_P.Constant5_Value != 0.0) {
      // Switch: '<S27>/Switch' incorporates:
      //   Constant: '<S27>/Constant1'
      //   DataTypeConversion: '<S18>/Cast To Double3'
      //   Switch: '<S27>/Switch1'
      //   Switch: '<S27>/Switch2'
      //   Switch: '<S27>/Switch4'

      Copy_of_Corneto_flight_progra_B.CastToDouble3[5] =
        Copy_of_Corneto_flight_progra_P.Constant1_Value;
    } else {
      // DataTypeConversion: '<S18>/Cast To Double3' incorporates:
      //   Constant: '<S27>/Constant'

      Copy_of_Corneto_flight_progra_B.CastToDouble3[5] =
        Copy_of_Corneto_flight_progra_P.Constant_Value_lj;
    }

    // End of Switch: '<S27>/Switch3'

    // DataTypeConversion: '<S18>/Cast To Double3'
    Copy_of_Corneto_flight_progra_B.CastToDouble3[0] =
      Copy_of_Corneto_flight_progra_B.CastToDouble2[0];
    Copy_of_Corneto_flight_progra_B.CastToDouble3[6] =
      Copy_of_Corneto_flight_progra_B.CastToDouble2[0];
    Copy_of_Corneto_flight_progra_B.CastToDouble3[1] =
      Copy_of_Corneto_flight_progra_B.CastToDouble2[1];
    Copy_of_Corneto_flight_progra_B.CastToDouble3[7] =
      Copy_of_Corneto_flight_progra_B.CastToDouble2[1];
    Copy_of_Corneto_flight_progra_B.CastToDouble3[2] =
      Copy_of_Corneto_flight_progra_B.CastToDouble2[2];
    Copy_of_Corneto_flight_progra_B.CastToDouble3[8] =
      Copy_of_Corneto_flight_progra_B.CastToDouble2[2];
    Copy_of_Corneto_flight_progra_B.CastToDouble3[3] =
      Copy_of_Corneto_flight_progra_B.CastToDouble2[3];
    Copy_of_Corneto_flight_progra_B.CastToDouble3[9] =
      Copy_of_Corneto_flight_progra_B.CastToDouble2[3];

    // MATLABSystem: '<S22>/PX4 PWM Output1'
    for (i = 0; i < 8; i++) {
      Copy_of_Corneto_flight_progra_B.pwmValue[i] = 0U;
    }

    // Gain: '<S50>/Gain'
    rtb_TmpSignalConversionAtSFun_0 = Copy_of_Corneto_flight_progra_P.Gain_Gain *
      Copy_of_Corneto_flight_progra_B.CastToDouble2[0];

    // Saturate: '<S22>/Saturation'
    if (rtb_TmpSignalConversionAtSFun_0 >
        Copy_of_Corneto_flight_progra_P.Saturation_UpperSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Copy_of_Corneto_flight_progra_P.Saturation_UpperSat;
    } else if (rtb_TmpSignalConversionAtSFun_0 <
               Copy_of_Corneto_flight_progra_P.Saturation_LowerSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Copy_of_Corneto_flight_progra_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S22>/Saturation'

    // DataTypeConversion: '<S22>/Cast To Double' incorporates:
    //   Constant: '<S22>/One'
    //   Gain: '<S22>/Gain'
    //   Sum: '<S22>/Add'

    Copy_of_Corneto_flight_progra_B.flight_mode_enum = floor
      (Copy_of_Corneto_flight_progra_P.Gain_Gain_b *
       rtb_TmpSignalConversionAtSFun_0 +
       Copy_of_Corneto_flight_progra_P.One_Value);
    if (rtIsNaN(Copy_of_Corneto_flight_progra_B.flight_mode_enum) || rtIsInf
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum)) {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum = 0.0;
    } else {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum = fmod
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum, 65536.0);
    }

    // MATLABSystem: '<S22>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S22>/Cast To Double'

    Copy_of_Corneto_flight_progra_B.pwmValue[0] = static_cast<uint16_T>
      (Copy_of_Corneto_flight_progra_B.flight_mode_enum < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Copy_of_Corneto_flight_progra_B.flight_mode_enum)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum)));

    // Gain: '<S51>/Gain'
    rtb_TmpSignalConversionAtSFun_0 =
      Copy_of_Corneto_flight_progra_P.Gain_Gain_o *
      Copy_of_Corneto_flight_progra_B.CastToDouble2[1];

    // Saturate: '<S22>/Saturation1'
    if (rtb_TmpSignalConversionAtSFun_0 >
        Copy_of_Corneto_flight_progra_P.Saturation1_UpperSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Copy_of_Corneto_flight_progra_P.Saturation1_UpperSat;
    } else if (rtb_TmpSignalConversionAtSFun_0 <
               Copy_of_Corneto_flight_progra_P.Saturation1_LowerSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Copy_of_Corneto_flight_progra_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S22>/Saturation1'

    // DataTypeConversion: '<S22>/Cast To Double1' incorporates:
    //   Constant: '<S22>/One1'
    //   Gain: '<S22>/Gain1'
    //   Sum: '<S22>/Add1'

    Copy_of_Corneto_flight_progra_B.flight_mode_enum = floor
      (Copy_of_Corneto_flight_progra_P.Gain1_Gain *
       rtb_TmpSignalConversionAtSFun_0 +
       Copy_of_Corneto_flight_progra_P.One1_Value_b);
    if (rtIsNaN(Copy_of_Corneto_flight_progra_B.flight_mode_enum) || rtIsInf
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum)) {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum = 0.0;
    } else {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum = fmod
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum, 65536.0);
    }

    // MATLABSystem: '<S22>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S22>/Cast To Double1'

    Copy_of_Corneto_flight_progra_B.pwmValue[1] = static_cast<uint16_T>
      (Copy_of_Corneto_flight_progra_B.flight_mode_enum < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Copy_of_Corneto_flight_progra_B.flight_mode_enum)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum)));

    // Gain: '<S52>/Gain'
    rtb_TmpSignalConversionAtSFun_0 =
      Copy_of_Corneto_flight_progra_P.Gain_Gain_g *
      Copy_of_Corneto_flight_progra_B.CastToDouble2[2];

    // Saturate: '<S22>/Saturation2'
    if (rtb_TmpSignalConversionAtSFun_0 >
        Copy_of_Corneto_flight_progra_P.Saturation2_UpperSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Copy_of_Corneto_flight_progra_P.Saturation2_UpperSat;
    } else if (rtb_TmpSignalConversionAtSFun_0 <
               Copy_of_Corneto_flight_progra_P.Saturation2_LowerSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Copy_of_Corneto_flight_progra_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S22>/Saturation2'

    // DataTypeConversion: '<S22>/Cast To Double2' incorporates:
    //   Constant: '<S22>/One2'
    //   Gain: '<S22>/Gain2'
    //   Sum: '<S22>/Add2'

    Copy_of_Corneto_flight_progra_B.flight_mode_enum = floor
      (Copy_of_Corneto_flight_progra_P.Gain2_Gain *
       rtb_TmpSignalConversionAtSFun_0 +
       Copy_of_Corneto_flight_progra_P.One2_Value_d);
    if (rtIsNaN(Copy_of_Corneto_flight_progra_B.flight_mode_enum) || rtIsInf
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum)) {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum = 0.0;
    } else {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum = fmod
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum, 65536.0);
    }

    // MATLABSystem: '<S22>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S22>/Cast To Double2'

    Copy_of_Corneto_flight_progra_B.pwmValue[2] = static_cast<uint16_T>
      (Copy_of_Corneto_flight_progra_B.flight_mode_enum < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Copy_of_Corneto_flight_progra_B.flight_mode_enum)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum)));

    // Gain: '<S53>/Gain'
    rtb_TmpSignalConversionAtSFun_0 =
      Copy_of_Corneto_flight_progra_P.Gain_Gain_l *
      Copy_of_Corneto_flight_progra_B.CastToDouble2[3];

    // Saturate: '<S22>/Saturation3'
    if (rtb_TmpSignalConversionAtSFun_0 >
        Copy_of_Corneto_flight_progra_P.Saturation3_UpperSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Copy_of_Corneto_flight_progra_P.Saturation3_UpperSat;
    } else if (rtb_TmpSignalConversionAtSFun_0 <
               Copy_of_Corneto_flight_progra_P.Saturation3_LowerSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Copy_of_Corneto_flight_progra_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S22>/Saturation3'

    // DataTypeConversion: '<S22>/Cast To Double3' incorporates:
    //   Constant: '<S22>/One3'
    //   Gain: '<S22>/Gain3'
    //   Sum: '<S22>/Add3'

    Copy_of_Corneto_flight_progra_B.flight_mode_enum = floor
      (Copy_of_Corneto_flight_progra_P.Gain3_Gain *
       rtb_TmpSignalConversionAtSFun_0 +
       Copy_of_Corneto_flight_progra_P.One3_Value);
    if (rtIsNaN(Copy_of_Corneto_flight_progra_B.flight_mode_enum) || rtIsInf
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum)) {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum = 0.0;
    } else {
      Copy_of_Corneto_flight_progra_B.flight_mode_enum = fmod
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum, 65536.0);
    }

    // MATLABSystem: '<S22>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S22>/Cast To Double3'

    Copy_of_Corneto_flight_progra_B.pwmValue[3] = static_cast<uint16_T>
      (Copy_of_Corneto_flight_progra_B.flight_mode_enum < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Copy_of_Corneto_flight_progra_B.flight_mode_enum)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum)));

    // Switch: '<S22>/Switch' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Boolean1'

    if (Copy_of_Corneto_flight_progra_B.RateTransition != 0.0F) {
      // DataTypeConversion: '<S22>/Cast To Double4' incorporates:
      //   Constant: '<S22>/One5'

      Copy_of_Corneto_flight_progra_B.flight_mode_enum = floor
        (Copy_of_Corneto_flight_progra_P.One5_Value);
      if (rtIsNaN(Copy_of_Corneto_flight_progra_B.flight_mode_enum) || rtIsInf
          (Copy_of_Corneto_flight_progra_B.flight_mode_enum)) {
        Copy_of_Corneto_flight_progra_B.flight_mode_enum = 0.0;
      } else {
        Copy_of_Corneto_flight_progra_B.flight_mode_enum = fmod
          (Copy_of_Corneto_flight_progra_B.flight_mode_enum, 65536.0);
      }

      // MATLABSystem: '<S22>/PX4 PWM Output1' incorporates:
      //   DataTypeConversion: '<S22>/Cast To Double4'

      Copy_of_Corneto_flight_progra_B.pwmValue[4] = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum < 0.0 ?
         static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
            static_cast<uint16_T>
            (-Copy_of_Corneto_flight_progra_B.flight_mode_enum)))) :
         static_cast<int32_T>(static_cast<uint16_T>
          (Copy_of_Corneto_flight_progra_B.flight_mode_enum)));
    } else {
      // DataTypeConversion: '<S22>/Cast To Double4' incorporates:
      //   Constant: '<S22>/One6'

      Copy_of_Corneto_flight_progra_B.flight_mode_enum = floor
        (Copy_of_Corneto_flight_progra_P.One6_Value);
      if (rtIsNaN(Copy_of_Corneto_flight_progra_B.flight_mode_enum) || rtIsInf
          (Copy_of_Corneto_flight_progra_B.flight_mode_enum)) {
        Copy_of_Corneto_flight_progra_B.flight_mode_enum = 0.0;
      } else {
        Copy_of_Corneto_flight_progra_B.flight_mode_enum = fmod
          (Copy_of_Corneto_flight_progra_B.flight_mode_enum, 65536.0);
      }

      // MATLABSystem: '<S22>/PX4 PWM Output1' incorporates:
      //   DataTypeConversion: '<S22>/Cast To Double4'

      Copy_of_Corneto_flight_progra_B.pwmValue[4] = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progra_B.flight_mode_enum < 0.0 ?
         static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
            static_cast<uint16_T>
            (-Copy_of_Corneto_flight_progra_B.flight_mode_enum)))) :
         static_cast<int32_T>(static_cast<uint16_T>
          (Copy_of_Corneto_flight_progra_B.flight_mode_enum)));
    }

    // End of Switch: '<S22>/Switch'

    // MATLABSystem: '<S22>/PX4 PWM Output1' incorporates:
    //   Constant: '<S22>/One4'
    //   Constant: '<S22>/One7'

    if (Copy_of_Corneto_flight_progra_P.One7_Value) {
      if (!Copy_of_Corneto_flight_progr_DW.obj_mo.isArmed) {
        Copy_of_Corneto_flight_progr_DW.obj_mo.isArmed = true;
        status = pwm_arm(&Copy_of_Corneto_flight_progr_DW.obj_mo.pwmDevHandler,
                         &Copy_of_Corneto_flight_progr_DW.obj_mo.armAdvertiseObj);
        Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus =
          static_cast<uint16_T>
          (Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus | status);
      }

      status = pwm_setServo
        (&Copy_of_Corneto_flight_progr_DW.obj_mo.pwmDevHandler,
         Copy_of_Corneto_flight_progr_DW.obj_mo.servoCount,
         Copy_of_Corneto_flight_progr_DW.obj_mo.channelMask,
         &Copy_of_Corneto_flight_progra_B.pwmValue[0],
         Copy_of_Corneto_flight_progr_DW.obj_mo.isMain,
         &Copy_of_Corneto_flight_progr_DW.obj_mo.actuatorAdvertiseObj);
      Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus | status);
    } else {
      status = pwm_disarm(&Copy_of_Corneto_flight_progr_DW.obj_mo.pwmDevHandler,
                          &Copy_of_Corneto_flight_progr_DW.obj_mo.armAdvertiseObj);
      Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus | status);
      Copy_of_Corneto_flight_progr_DW.obj_mo.isArmed = false;
      status = pwm_resetServo
        (&Copy_of_Corneto_flight_progr_DW.obj_mo.pwmDevHandler,
         Copy_of_Corneto_flight_progr_DW.obj_mo.servoCount,
         Copy_of_Corneto_flight_progr_DW.obj_mo.channelMask,
         Copy_of_Corneto_flight_progr_DW.obj_mo.isMain,
         &Copy_of_Corneto_flight_progr_DW.obj_mo.actuatorAdvertiseObj);
      Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus | status);
    }

    if (Copy_of_Corneto_flight_progr_DW.obj_mo.isMain) {
      status = pwm_forceFailsafe
        (&Copy_of_Corneto_flight_progr_DW.obj_mo.pwmDevHandler,
         static_cast<int32_T>(Copy_of_Corneto_flight_progra_P.One4_Value));
      Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus | status);
    }

    // Update for DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'
    Copy_of_Corneto_flight_progr_DW.DiscreteTransferFcn_states =
      Copy_of_Corneto_flight_progra_B.Product2_f;

    // Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;

    // Switch: '<S18>/Switch1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Boolean3'

    if (Copy_of_Corneto_flight_progra_B.RateTransition1 != 0) {
      // Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
      //   Constant: '<S18>/One1'
      //   DataTypeConversion: '<S18>/Cast To Double36'

      Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRese =
        static_cast<int8_T>(Copy_of_Corneto_flight_progra_P.One1_Value != 0.0);
    } else {
      // Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
      //   Constant: '<S18>/One2'
      //   DataTypeConversion: '<S18>/Cast To Double36'

      Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRese =
        static_cast<int8_T>(Copy_of_Corneto_flight_progra_P.One2_Value != 0.0);
    }

    // Update for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'
    //   Lookup_n-D: '<S24>/1-D Lookup Table4'
    //   Product: '<S23>/Product3'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U =
      look2_binlcapw(static_cast<real_T>
                     (Copy_of_Corneto_flight_progra_B.In1_a.alt),
                     Copy_of_Corneto_flight_progra_B.Kp_phi,
                     Copy_of_Corneto_flight_progra_P.Autopilot.Phi.h_bkpts_m,
                     Copy_of_Corneto_flight_progra_P.Autopilot.Phi.V_bkpts_mps,
                     Copy_of_Corneto_flight_progra_P.Autopilot.Phi.Ki_phi_vec,
                     Copy_of_Corneto_flight_progra_P.uDLookupTable4_maxIndex, 3U)
      * Copy_of_Corneto_flight_progra_B.Sum3;

    // Update for DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn'
    Copy_of_Corneto_flight_progr_DW.DiscreteTransferFcn_states_b =
      Copy_of_Corneto_flight_progra_B.t;

    // Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_d = 0U;
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRe_h =
      static_cast<int8_T>(rtb_NOT);
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U_e =
      Copy_of_Corneto_flight_progra_P.Constant_Value_k;

    // Update for Memory: '<S40>/Memory'
    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_g =
      Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput;

    // Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S44>/Constant'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_e = 0U;
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRe_a =
      static_cast<int8_T>(rtb_CastToBoolean2);
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U_k =
      Copy_of_Corneto_flight_progra_P.Constant_Value_e;

    // Update for UnitDelay: '<S34>/Delay Input1'
    //
    //  Block description for '<S34>/Delay Input1':
    //
    //   Store in Global RAM

    Copy_of_Corneto_flight_progr_DW.DelayInput1_DSTATE =
      Copy_of_Corneto_flight_progra_B.cumRevIndex;

    // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_k = 0U;
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRe_k =
      static_cast<int8_T>(rtb_NOT_c);
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U_h =
      Copy_of_Corneto_flight_progra_P.Constant_Value_a;

    // Update for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S48>/Constant'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTE_es = 0U;
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PrevRe_f =
      static_cast<int8_T>(rtb_NOT_f);
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_PREV_U_c =
      Copy_of_Corneto_flight_progra_P.Constant_Value_b;
  }

  // End of Outputs for SubSystem: '<S8>/Emulated Pixhawk'

  // RateTransition: '<Root>/Rate Transition3' incorporates:
  //   RateTransition: '<Root>/Rate Transition4'

  if (Copy_of_Corneto_flight_progr_M->Timing.TaskCounters.TID[1] == 0) {
    // RateTransition: '<Root>/Rate Transition4' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Boolean2'

    Copy_of_Corneto_flight_progra_B.RateTransition4 =
      (Copy_of_Corneto_flight_progr_DW.RateTransition3_Buffer0 != 0.0F);
  }

  // End of RateTransition: '<Root>/Rate Transition3'

  // SignalConversion generated from: '<S63>/ SFunction ' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double1'
  //   DataTypeConversion: '<Root>/Cast To Double11'
  //   DataTypeConversion: '<Root>/Cast To Double14'
  //   DataTypeConversion: '<Root>/Cast To Double15'
  //   DataTypeConversion: '<Root>/Cast To Double16'
  //   DataTypeConversion: '<Root>/Cast To Double3'
  //   DataTypeConversion: '<Root>/Cast To Double4'
  //   DataTypeConversion: '<Root>/Cast To Double5'
  //   DataTypeConversion: '<Root>/Cast To Double6'
  //   DataTypeConversion: '<Root>/Cast To Double7'
  //   DataTypeConversion: '<Root>/Cast To Double8'
  //   DataTypeConversion: '<Root>/Cast To Double9'
  //   MATLAB Function: '<S62>/SDCard_logger'

  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[0] =
    Copy_of_Corneto_flight_progra_B.In1_a.lat;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[1] =
    Copy_of_Corneto_flight_progra_B.In1_a.lon;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[2] =
    Copy_of_Corneto_flight_progra_B.In1_a.alt;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[3] =
    Copy_of_Corneto_flight_progra_B.In1_a.fix_type;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[4] =
    Copy_of_Corneto_flight_progra_B.In1_a.satellites_used;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[5] =
    Copy_of_Corneto_flight_progra_B.In1_a.vel_m_s;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[6] =
    Copy_of_Corneto_flight_progra_B.In1_a.vel_n_m_s;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[7] =
    Copy_of_Corneto_flight_progra_B.In1_a.vel_e_m_s;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[8] =
    Copy_of_Corneto_flight_progra_B.In1_a.vel_d_m_s;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[9] =
    Copy_of_Corneto_flight_progra_B.In1.rollspeed;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[10] =
    Copy_of_Corneto_flight_progra_B.In1.pitchspeed;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[11] =
    Copy_of_Corneto_flight_progra_B.In1.yawspeed;

  // Trigonometry: '<S54>/trigFcn'
  if (Copy_of_Corneto_flight_progra_B.fcn3 > 1.0) {
    Copy_of_Corneto_flight_progra_B.fcn3 = 1.0;
  } else if (Copy_of_Corneto_flight_progra_B.fcn3 < -1.0) {
    Copy_of_Corneto_flight_progra_B.fcn3 = -1.0;
  }

  // SignalConversion generated from: '<S63>/ SFunction ' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double10'
  //   DataTypeConversion: '<Root>/Cast To Double12'
  //   DataTypeConversion: '<Root>/Cast To Double13'
  //   DataTypeConversion: '<Root>/Cast To Double17'
  //   DataTypeConversion: '<Root>/Cast To Double18'
  //   DataTypeConversion: '<Root>/Cast To Double19'
  //   DataTypeConversion: '<Root>/Cast To Double20'
  //   DataTypeConversion: '<Root>/Cast To Double24'
  //   DataTypeConversion: '<Root>/Cast To Double25'
  //   DataTypeConversion: '<Root>/Cast To Double26'
  //   DataTypeConversion: '<Root>/Cast To Double27'
  //   DataTypeConversion: '<Root>/Cast To Double28'
  //   DataTypeConversion: '<Root>/Cast To Double29'
  //   DataTypeConversion: '<Root>/Cast To Double30'
  //   DataTypeConversion: '<Root>/Cast To Double31'
  //   MATLAB Function: '<S62>/SDCard_logger'
  //   Trigonometry: '<S54>/trigFcn'

  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[13] = asin
    (Copy_of_Corneto_flight_progra_B.fcn3);
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[14] =
    Copy_of_Corneto_flight_progra_B.Product3_n;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[15] =
    Copy_of_Corneto_flight_progra_B.In1_i.x;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[16] =
    Copy_of_Corneto_flight_progra_B.In1_i.y;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[17] =
    Copy_of_Corneto_flight_progra_B.In1_i.z;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[18] =
    Copy_of_Corneto_flight_progra_B.In1_eg.x;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[19] =
    Copy_of_Corneto_flight_progra_B.In1_eg.y;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[20] =
    Copy_of_Corneto_flight_progra_B.In1_eg.z;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[21] =
    Copy_of_Corneto_flight_progra_B.In1_e.ax;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[22] =
    Copy_of_Corneto_flight_progra_B.In1_e.ay;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[23] =
    Copy_of_Corneto_flight_progra_B.In1_e.az;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[24] =
    Copy_of_Corneto_flight_progra_B.In1_e.z;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[25] =
    Copy_of_Corneto_flight_progra_B.In1_e.x;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[26] =
    Copy_of_Corneto_flight_progra_B.In1_e.y;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[27] =
    Copy_of_Corneto_flight_progra_B.In1_e.vx;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[28] =
    Copy_of_Corneto_flight_progra_B.In1_e.vy;
  Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[29] =
    Copy_of_Corneto_flight_progra_B.In1_e.vz;
  memcpy(&Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[30],
         &Copy_of_Corneto_flight_progra_B.CastToDouble3[0], 10U * sizeof(real_T));

  // MATLAB Function: '<S62>/SDCard_logger'
  Copy_of_Corneto_flight_progra_B.timestamp = hrt_absolute_time();
  if (!Copy_of_Corneto_flight_progr_DW.count_not_empty) {
    Copy_of_Corneto_flight_progr_DW.count_not_empty = true;
    elem_type = 1U;
    Copy_of_Corneto_flight_progr_DW.vect_size = 40U;
    for (i = 0; i < 56; i++) {
      Copy_of_Corneto_flight_progra_B.b[i] = i_0[i];
    }

    for (i = 0; i < 24; i++) {
      Copy_of_Corneto_flight_progra_B.c[i] = g[i];
    }

    printf(&Copy_of_Corneto_flight_progra_B.b[0],
           &Copy_of_Corneto_flight_progra_B.c[0], static_cast<uint32_T>
           (Copy_of_Corneto_flight_progr_DW.vect_size), static_cast<uint32_T>
           (Copy_of_Corneto_flight_progr_DW.elem_size), 276447232U, 10);
    for (i = 0; i < 24; i++) {
      Copy_of_Corneto_flight_progra_B.c[i] = g[i];
    }

    d[0] = 'w';
    d[1] = 'b';
    d[2] = '\x00';
    Copy_of_Corneto_flight_progr_DW.fp = fopen
      (&Copy_of_Corneto_flight_progra_B.c[0], &d[0]);
    fwrite(&mlStrVer[0], 1U, 5.0, Copy_of_Corneto_flight_progr_DW.fp);
    tm = time(&EmulatedPixhawk_ELAPS_T);
    fwrite(&tm, 4U, 1U, Copy_of_Corneto_flight_progr_DW.fp);
    fwrite(&Copy_of_Corneto_flight_progr_DW.vect_size, 1U, 1U,
           Copy_of_Corneto_flight_progr_DW.fp);
    fwrite(&elem_type, 1U, 1U, Copy_of_Corneto_flight_progr_DW.fp);
    EmulatedPixhawk_ELAPS_T = static_cast<uint32_T>
      (Copy_of_Corneto_flight_progr_DW.elem_size) *
      Copy_of_Corneto_flight_progr_DW.vect_size;
    if (EmulatedPixhawk_ELAPS_T > 65535U) {
      EmulatedPixhawk_ELAPS_T = 65535U;
    }

    status = static_cast<uint16_T>(EmulatedPixhawk_ELAPS_T);
    fwrite(&status, 2U, 1U, Copy_of_Corneto_flight_progr_DW.fp);
  }

  if (Copy_of_Corneto_flight_progra_B.RateTransition4 &&
      (Copy_of_Corneto_flight_progr_DW.count < 276447232U)) {
    if (!Copy_of_Corneto_flight_progr_DW.isopen) {
      for (i = 0; i < 24; i++) {
        Copy_of_Corneto_flight_progra_B.c[i] = g[i];
      }

      d[0] = 'a';
      d[1] = 'b';
      d[2] = '\x00';
      Copy_of_Corneto_flight_progr_DW.fp = fopen
        (&Copy_of_Corneto_flight_progra_B.c[0], &d[0]);
      Copy_of_Corneto_flight_progr_DW.isflushed = false;
      Copy_of_Corneto_flight_progr_DW.isopen = true;
    }

    fwrite(&Copy_of_Corneto_flight_progra_B.TmpSignalConversionAtSFunct[0],
           Copy_of_Corneto_flight_progr_DW.elem_size,
           Copy_of_Corneto_flight_progr_DW.vect_size,
           Copy_of_Corneto_flight_progr_DW.fp);
    fwrite(&Copy_of_Corneto_flight_progra_B.timestamp, 8U, 1U,
           Copy_of_Corneto_flight_progr_DW.fp);
    EmulatedPixhawk_ELAPS_T = Copy_of_Corneto_flight_progr_DW.count +
      /*MW:OvSatOk*/ 1U;
    if (Copy_of_Corneto_flight_progr_DW.count + 1U <
        Copy_of_Corneto_flight_progr_DW.count) {
      EmulatedPixhawk_ELAPS_T = MAX_uint32_T;
    }

    Copy_of_Corneto_flight_progr_DW.count = EmulatedPixhawk_ELAPS_T;
  } else {
    if (Copy_of_Corneto_flight_progr_DW.isopen) {
      if (!Copy_of_Corneto_flight_progr_DW.isflushed) {
        for (i = 0; i < 28; i++) {
          Copy_of_Corneto_flight_progra_B.e[i] = f[i];
        }

        printf(&Copy_of_Corneto_flight_progra_B.e[0],
               Copy_of_Corneto_flight_progr_DW.count, 10);
        fflush(Copy_of_Corneto_flight_progr_DW.fp);
        Copy_of_Corneto_flight_progr_DW.isflushed = true;
      }

      fclose(Copy_of_Corneto_flight_progr_DW.fp);
    }

    Copy_of_Corneto_flight_progr_DW.isopen = false;
  }

  if (Copy_of_Corneto_flight_progr_M->Timing.TaskCounters.TID[1] == 0) {
    // MATLABSystem: '<Root>/Read Parameter'
    if (Copy_of_Corneto_flight_progr_DW.obj_b.SampleTime !=
        Copy_of_Corneto_flight_progra_P.ReadParameter_SampleTime) {
      Copy_of_Corneto_flight_progr_DW.obj_b.SampleTime =
        Copy_of_Corneto_flight_progra_P.ReadParameter_SampleTime;
    }

    Copy_of_Corneto_flight_progra_B.ParamDataType = MW_INT32;
    rtb_NOT = MW_Param_Step(Copy_of_Corneto_flight_progr_DW.obj_b.MW_PARAMHANDLE,
      Copy_of_Corneto_flight_progra_B.ParamDataType, &i);
    if (rtb_NOT) {
      i = 0;
    }

    // DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
    //   MATLABSystem: '<Root>/Read Parameter'

    rtb_DataTypeConversion3 = static_cast<real32_T>(i);

    // MATLABSystem: '<Root>/Read Parameter1'
    if (Copy_of_Corneto_flight_progr_DW.obj_l.SampleTime !=
        Copy_of_Corneto_flight_progra_P.ReadParameter1_SampleTime) {
      Copy_of_Corneto_flight_progr_DW.obj_l.SampleTime =
        Copy_of_Corneto_flight_progra_P.ReadParameter1_SampleTime;
    }

    Copy_of_Corneto_flight_progra_B.ParamDataType = MW_INT32;
    rtb_NOT = MW_Param_Step(Copy_of_Corneto_flight_progr_DW.obj_l.MW_PARAMHANDLE,
      Copy_of_Corneto_flight_progra_B.ParamDataType, &i);
    if (rtb_NOT) {
      i = 0;
    }

    // DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
    //   MATLABSystem: '<Root>/Read Parameter1'

    rtb_DataTypeConversion2 = static_cast<real32_T>(i);

    // MATLABSystem: '<Root>/Read Parameter2'
    if (Copy_of_Corneto_flight_progr_DW.obj_m.SampleTime !=
        Copy_of_Corneto_flight_progra_P.ReadParameter2_SampleTime) {
      Copy_of_Corneto_flight_progr_DW.obj_m.SampleTime =
        Copy_of_Corneto_flight_progra_P.ReadParameter2_SampleTime;
    }

    Copy_of_Corneto_flight_progra_B.ParamDataType = MW_INT32;
    rtb_NOT = MW_Param_Step(Copy_of_Corneto_flight_progr_DW.obj_m.MW_PARAMHANDLE,
      Copy_of_Corneto_flight_progra_B.ParamDataType, &rtb_ReadParameter2_o1);
    if (rtb_NOT) {
      rtb_ReadParameter2_o1 = 0;
    }

    // End of MATLABSystem: '<Root>/Read Parameter2'

    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   Constant: '<S4>/Constant'
    //   DataTypeConversion: '<Root>/Data Type Conversion4'

    Copy_of_Corneto_flight_progra_B.BusAssignment1 =
      Copy_of_Corneto_flight_progra_P.Constant_Value_h;
    Copy_of_Corneto_flight_progra_B.BusAssignment1.x = rtb_DataTypeConversion3;
    Copy_of_Corneto_flight_progra_B.BusAssignment1.y = rtb_DataTypeConversion2;
    Copy_of_Corneto_flight_progra_B.BusAssignment1.z = static_cast<real32_T>
      (rtb_ReadParameter2_o1);

    // MATLABSystem: '<S7>/SinkBlock' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment1'

    uORB_write_step(Copy_of_Corneto_flight_progr_DW.obj_o.orbMetadataObj,
                    &Copy_of_Corneto_flight_progr_DW.obj_o.orbAdvertiseObj,
                    &Copy_of_Corneto_flight_progra_B.BusAssignment1);

    // Update for RateTransition: '<Root>/Rate Transition'
    Copy_of_Corneto_flight_progr_DW.RateTransition_Buffer0 =
      rtb_DataTypeConversion2;

    // Update for RateTransition: '<Root>/Rate Transition1'
    Copy_of_Corneto_flight_progr_DW.RateTransition1_Buffer0 =
      rtb_ReadParameter2_o1;

    // Update for RateTransition: '<Root>/Rate Transition3'
    Copy_of_Corneto_flight_progr_DW.RateTransition3_Buffer0 =
      rtb_DataTypeConversion3;
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.005, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  Copy_of_Corneto_flight_progr_M->Timing.clockTick0++;
  rate_scheduler();
}

// Model initialize function
void Copy_of_Corneto_flight_program_control_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    g_dsp_private_SlidingWindowAv_T *obj_0;
    px4_internal_block_ParameterU_T *obj;
    real_T sts;
    int32_T i;
    char_T ParameterNameStr_0[15];
    char_T ParameterNameStr[13];
    static const char_T tmp[12] = { 'S', 'D', '_', 's', 'a', 'v', 'e', '_', 'f',
      'l', 'a', 'g' };

    static const char_T tmp_0[14] = { 'P', 'r', 'e', 'f', 'l', 'i', 'g', 'h',
      't', '_', 'f', 'l', 'a', 'g' };

    static const char_T tmp_1[16] = { 'I', 'n', 't', 'e', 'g', 'r', 'a', 't',
      'o', 'r', 's', '_', 'f', 'l', 'a', 'g' };

    // Start for RateTransition: '<Root>/Rate Transition'
    Copy_of_Corneto_flight_progra_B.RateTransition =
      Copy_of_Corneto_flight_progra_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<Root>/Rate Transition1'
    Copy_of_Corneto_flight_progra_B.RateTransition1 =
      Copy_of_Corneto_flight_progra_P.RateTransition1_InitialConditio;
    Copy_of_Corneto_flight__PrevZCX.EmulatedPixhawk_Trig_ZCE =
      UNINITIALIZED_ZCSIG;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    Copy_of_Corneto_flight_progr_DW.RateTransition_Buffer0 =
      Copy_of_Corneto_flight_progra_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition1'
    Copy_of_Corneto_flight_progr_DW.RateTransition1_Buffer0 =
      Copy_of_Corneto_flight_progra_P.RateTransition1_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition3'
    Copy_of_Corneto_flight_progr_DW.RateTransition3_Buffer0 =
      Copy_of_Corneto_flight_progra_P.RateTransition3_InitialConditio;

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S16>/Out1' incorporates:
    //   Inport: '<S16>/In1'

    Copy_of_Corneto_flight_progra_B.In1_a =
      Copy_of_Corneto_flight_progra_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S64>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S65>/Out1' incorporates:
    //   Inport: '<S65>/In1'

    Copy_of_Corneto_flight_progra_B.In1 =
      Copy_of_Corneto_flight_progra_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S64>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S13>/Out1' incorporates:
    //   Inport: '<S13>/In1'

    Copy_of_Corneto_flight_progra_B.In1_i =
      Copy_of_Corneto_flight_progra_P.Out1_Y0_iw;

    // End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S15>/Out1' incorporates:
    //   Inport: '<S15>/In1'

    Copy_of_Corneto_flight_progra_B.In1_eg =
      Copy_of_Corneto_flight_progra_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S17>/Out1' incorporates:
    //   Inport: '<S17>/In1'

    Copy_of_Corneto_flight_progra_B.In1_e =
      Copy_of_Corneto_flight_progra_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Triggered SubSystem: '<S8>/Emulated Pixhawk'
    // InitializeConditions for DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' 
    Copy_of_Corneto_flight_progr_DW.DiscreteTransferFcn_states =
      Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteIntegrator: '<S23>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S23>/Constant'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTAT_b5 =
      Copy_of_Corneto_flight_progra_P.Constant_Value_m;

    // InitializeConditions for DiscreteTransferFcn: '<S18>/Discrete Transfer Fcn' 
    Copy_of_Corneto_flight_progr_DW.DiscreteTransferFcn_states_b =
      Copy_of_Corneto_flight_progra_P.DiscreteTransferFcn_InitialSt_g;

    // InitializeConditions for Switch: '<S40>/Switch1' incorporates:
    //   Memory: '<S28>/Memory'

    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput =
      Copy_of_Corneto_flight_progra_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant1'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE =
      Copy_of_Corneto_flight_progra_P.Constant1_Value_d;

    // InitializeConditions for Memory: '<S40>/Memory'
    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_g =
      Copy_of_Corneto_flight_progra_P.Memory_InitialCondition_n;

    // InitializeConditions for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S44>/Constant1'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_f =
      Copy_of_Corneto_flight_progra_P.Constant1_Value_k;

    // InitializeConditions for Switch: '<S45>/Switch1' incorporates:
    //   Memory: '<S45>/Memory'

    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_o =
      Copy_of_Corneto_flight_progra_P.Memory_InitialCondition_l;

    // InitializeConditions for UnitDelay: '<S34>/Delay Input1'
    //
    //  Block description for '<S34>/Delay Input1':
    //
    //   Store in Global RAM

    Copy_of_Corneto_flight_progr_DW.DelayInput1_DSTATE =
      Copy_of_Corneto_flight_progra_P.DetectDecrease_vinit;

    // InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant1'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_b =
      Copy_of_Corneto_flight_progra_P.Constant1_Value_n;

    // InitializeConditions for Switch: '<S36>/Switch1' incorporates:
    //   Memory: '<S36>/Memory'

    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_j =
      Copy_of_Corneto_flight_progra_P.Memory_InitialCondition_b;

    // InitializeConditions for DiscreteIntegrator: '<S48>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S48>/Constant1'

    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_DSTATE_d =
      Copy_of_Corneto_flight_progra_P.Constant1_Value_i;

    // InitializeConditions for Switch: '<S49>/Switch1' incorporates:
    //   Memory: '<S49>/Memory'

    Copy_of_Corneto_flight_progr_DW.Memory_PreviousInput_ge =
      Copy_of_Corneto_flight_progra_P.Memory_InitialCondition_m;

    // Start for MATLABSystem: '<S26>/Moving Average1'
    Copy_of_Corneto_flight_progr_DW.obj.matlabCodegenIsDeleted = true;
    Copy_of_Corneto_flight_progr_DW.obj.isInitialized = 0;
    Copy_of_Corneto_flight_progr_DW.obj.NumChannels = -1;
    Copy_of_Corneto_flight_progr_DW.obj.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj.isInitialized = 1;
    Copy_of_Corneto_flight_progr_DW.obj.NumChannels = 1;
    Copy_of_Corneto_flight_progr_DW.obj._pobj0.isInitialized = 0;
    Copy_of_Corneto_flight_progr_DW.obj.pStatistic =
      &Copy_of_Corneto_flight_progr_DW.obj._pobj0;
    Copy_of_Corneto_flight_progr_DW.obj.isSetupComplete = true;
    Copy_of_Corneto_flight_progr_DW.obj.TunablePropsChanged = false;

    // InitializeConditions for MATLABSystem: '<S26>/Moving Average1'
    obj_0 = Copy_of_Corneto_flight_progr_DW.obj.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 9; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    // End of InitializeConditions for MATLABSystem: '<S26>/Moving Average1'

    // Start for MATLABSystem: '<S22>/PX4 PWM Output1' incorporates:
    //   Constant: '<S22>/One4'
    //   Constant: '<S22>/One7'

    Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus = 0U;
    Copy_of_Corneto_flight_progr_DW.obj_mo.isInitialized = 0;
    Copy_of_Corneto_flight_progr_DW.obj_mo.matlabCodegenIsDeleted = false;
    Copy_of_Cornet_SystemCore_setup(&Copy_of_Corneto_flight_progr_DW.obj_mo,
      Copy_of_Corneto_flight_progra_P.One7_Value,
      Copy_of_Corneto_flight_progra_P.One4_Value);
    for (i = 0; i < 10; i++) {
      // SystemInitialize for DataTypeConversion: '<S18>/Cast To Double3' incorporates:
      //   Outport: '<S18>/Pix_Out'

      Copy_of_Corneto_flight_progra_B.CastToDouble3[i] =
        Copy_of_Corneto_flight_progra_P.Pix_Out_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S8>/Emulated Pixhawk'

    // SystemInitialize for MATLAB Function: '<S62>/SDCard_logger'
    Copy_of_Corneto_flight_progr_DW.elem_size = 8U;
    Copy_of_Corneto_flight_progr_DW.isopen = true;

    // Start for MATLABSystem: '<S5>/SourceBlock'
    Copy_of_Corneto_flight_progr_DW.obj_k.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_k.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_k.isInitialized = 1;
    Copy_of_Corneto_flight_progr_DW.obj_k.orbMetadataObj = ORB_ID
      (vehicle_gps_position);
    uORB_read_initialize(Copy_of_Corneto_flight_progr_DW.obj_k.orbMetadataObj,
                         &Copy_of_Corneto_flight_progr_DW.obj_k.eventStructObj);
    Copy_of_Corneto_flight_progr_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S64>/SourceBlock'
    Copy_of_Corneto_flight_progr_DW.obj_n.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_n.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_n.isInitialized = 1;
    Copy_of_Corneto_flight_progr_DW.obj_n.orbMetadataObj = ORB_ID
      (vehicle_odometry);
    uORB_read_initialize(Copy_of_Corneto_flight_progr_DW.obj_n.orbMetadataObj,
                         &Copy_of_Corneto_flight_progr_DW.obj_n.eventStructObj);
    Copy_of_Corneto_flight_progr_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/SourceBlock'
    Copy_of_Corneto_flight_progr_DW.obj_j.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_j.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_j.isInitialized = 1;
    Copy_of_Corneto_flight_progr_DW.obj_j.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(Copy_of_Corneto_flight_progr_DW.obj_j.orbMetadataObj,
                         &Copy_of_Corneto_flight_progr_DW.obj_j.eventStructObj);
    Copy_of_Corneto_flight_progr_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/SourceBlock'
    Copy_of_Corneto_flight_progr_DW.obj_nc.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_nc.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_nc.isInitialized = 1;
    Copy_of_Corneto_flight_progr_DW.obj_nc.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(Copy_of_Corneto_flight_progr_DW.obj_nc.orbMetadataObj,
                         &Copy_of_Corneto_flight_progr_DW.obj_nc.eventStructObj);
    Copy_of_Corneto_flight_progr_DW.obj_nc.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/SourceBlock'
    Copy_of_Corneto_flight_progr_DW.obj_f.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_f.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_f.isInitialized = 1;
    Copy_of_Corneto_flight_progr_DW.obj_f.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize(Copy_of_Corneto_flight_progr_DW.obj_f.orbMetadataObj,
                         &Copy_of_Corneto_flight_progr_DW.obj_f.eventStructObj);
    Copy_of_Corneto_flight_progr_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Read Parameter'
    Copy_of_Corneto_flight_progr_DW.obj_b.matlabCodegenIsDeleted = true;
    Copy_of_Corneto_flight_progr_DW.obj_b.isInitialized = 0;
    Copy_of_Corneto_flight_progr_DW.obj_b.SampleTime = -1.0;
    Copy_of_Corneto_flight_progr_DW.obj_b.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_b.SampleTime =
      Copy_of_Corneto_flight_progra_P.ReadParameter_SampleTime;
    obj = &Copy_of_Corneto_flight_progr_DW.obj_b;
    Copy_of_Corneto_flight_progr_DW.obj_b.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      ParameterNameStr[i] = tmp[i];
    }

    ParameterNameStr[12] = '\x00';
    if (Copy_of_Corneto_flight_progr_DW.obj_b.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = Copy_of_Corneto_flight_progr_DW.obj_b.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, sts * 1000.0);
    Copy_of_Corneto_flight_progr_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter'

    // Start for MATLABSystem: '<Root>/Read Parameter1'
    Copy_of_Corneto_flight_progr_DW.obj_l.matlabCodegenIsDeleted = true;
    Copy_of_Corneto_flight_progr_DW.obj_l.isInitialized = 0;
    Copy_of_Corneto_flight_progr_DW.obj_l.SampleTime = -1.0;
    Copy_of_Corneto_flight_progr_DW.obj_l.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_l.SampleTime =
      Copy_of_Corneto_flight_progra_P.ReadParameter1_SampleTime;
    obj = &Copy_of_Corneto_flight_progr_DW.obj_l;
    Copy_of_Corneto_flight_progr_DW.obj_l.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      ParameterNameStr_0[i] = tmp_0[i];
    }

    ParameterNameStr_0[14] = '\x00';
    if (Copy_of_Corneto_flight_progr_DW.obj_l.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = Copy_of_Corneto_flight_progr_DW.obj_l.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0], true, sts *
      1000.0);
    Copy_of_Corneto_flight_progr_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter1'

    // Start for MATLABSystem: '<Root>/Read Parameter2'
    Copy_of_Corneto_flight_progr_DW.obj_m.matlabCodegenIsDeleted = true;
    Copy_of_Corneto_flight_progr_DW.obj_m.isInitialized = 0;
    Copy_of_Corneto_flight_progr_DW.obj_m.SampleTime = -1.0;
    Copy_of_Corneto_flight_progr_DW.obj_m.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_m.SampleTime =
      Copy_of_Corneto_flight_progra_P.ReadParameter2_SampleTime;
    obj = &Copy_of_Corneto_flight_progr_DW.obj_m;
    Copy_of_Corneto_flight_progr_DW.obj_m.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      Copy_of_Corneto_flight_progra_B.ParameterNameStr[i] = tmp_1[i];
    }

    Copy_of_Corneto_flight_progra_B.ParameterNameStr[16] = '\x00';
    if (Copy_of_Corneto_flight_progr_DW.obj_m.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = Copy_of_Corneto_flight_progr_DW.obj_m.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param
      (&Copy_of_Corneto_flight_progra_B.ParameterNameStr[0], true, sts * 1000.0);
    Copy_of_Corneto_flight_progr_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter2'

    // Start for MATLABSystem: '<S7>/SinkBlock' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment1'

    Copy_of_Corneto_flight_progr_DW.obj_o.matlabCodegenIsDeleted = false;
    Copy_of_Corneto_flight_progr_DW.obj_o.isSetupComplete = false;
    Copy_of_Corneto_flight_progr_DW.obj_o.isInitialized = 1;
    Copy_of_Corneto_flight_progr_DW.obj_o.orbMetadataObj = ORB_ID(debug_vect);
    uORB_write_initialize(Copy_of_Corneto_flight_progr_DW.obj_o.orbMetadataObj,
                          &Copy_of_Corneto_flight_progr_DW.obj_o.orbAdvertiseObj,
                          &Copy_of_Corneto_flight_progra_B.BusAssignment1_b, 1);
    Copy_of_Corneto_flight_progr_DW.obj_o.isSetupComplete = true;

    // Enable for Triggered SubSystem: '<S8>/Emulated Pixhawk'
    Copy_of_Corneto_flight_progr_DW.EmulatedPixhawk_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S23>/Discrete-Time Integrator'
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

    // Enable for DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_d = 1U;

    // Enable for DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_e = 1U;

    // Enable for DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTEM_k = 1U;

    // Enable for DiscreteIntegrator: '<S48>/Discrete-Time Integrator'
    Copy_of_Corneto_flight_progr_DW.DiscreteTimeIntegrator_SYSTE_es = 1U;

    // End of Enable for SubSystem: '<S8>/Emulated Pixhawk'
  }
}

// Model terminate function
void Copy_of_Corneto_flight_program_control_terminate(void)
{
  g_dsp_private_SlidingWindowAv_T *obj;
  uint16_T status;

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!Copy_of_Corneto_flight_progr_DW.obj_k.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Copy_of_Corneto_flight_progr_DW.obj_k.isInitialized == 1) &&
        Copy_of_Corneto_flight_progr_DW.obj_k.isSetupComplete) {
      uORB_read_terminate(&Copy_of_Corneto_flight_progr_DW.obj_k.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for MATLABSystem: '<S64>/SourceBlock'
  if (!Copy_of_Corneto_flight_progr_DW.obj_n.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Copy_of_Corneto_flight_progr_DW.obj_n.isInitialized == 1) &&
        Copy_of_Corneto_flight_progr_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&Copy_of_Corneto_flight_progr_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S64>/SourceBlock'

  // Terminate for MATLABSystem: '<S12>/SourceBlock'
  if (!Copy_of_Corneto_flight_progr_DW.obj_j.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Copy_of_Corneto_flight_progr_DW.obj_j.isInitialized == 1) &&
        Copy_of_Corneto_flight_progr_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&Copy_of_Corneto_flight_progr_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S12>/SourceBlock'

  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!Copy_of_Corneto_flight_progr_DW.obj_nc.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_nc.matlabCodegenIsDeleted = true;
    if ((Copy_of_Corneto_flight_progr_DW.obj_nc.isInitialized == 1) &&
        Copy_of_Corneto_flight_progr_DW.obj_nc.isSetupComplete) {
      uORB_read_terminate(&Copy_of_Corneto_flight_progr_DW.obj_nc.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!Copy_of_Corneto_flight_progr_DW.obj_f.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Copy_of_Corneto_flight_progr_DW.obj_f.isInitialized == 1) &&
        Copy_of_Corneto_flight_progr_DW.obj_f.isSetupComplete) {
      uORB_read_terminate(&Copy_of_Corneto_flight_progr_DW.obj_f.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for Triggered SubSystem: '<S8>/Emulated Pixhawk'
  // Terminate for MATLABSystem: '<S26>/Moving Average1'
  if (!Copy_of_Corneto_flight_progr_DW.obj.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj.matlabCodegenIsDeleted = true;
    if ((Copy_of_Corneto_flight_progr_DW.obj.isInitialized == 1) &&
        Copy_of_Corneto_flight_progr_DW.obj.isSetupComplete) {
      obj = Copy_of_Corneto_flight_progr_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      Copy_of_Corneto_flight_progr_DW.obj.NumChannels = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S26>/Moving Average1'

  // Terminate for MATLABSystem: '<S22>/PX4 PWM Output1'
  if (!Copy_of_Corneto_flight_progr_DW.obj_mo.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_mo.matlabCodegenIsDeleted = true;
    if ((Copy_of_Corneto_flight_progr_DW.obj_mo.isInitialized == 1) &&
        Copy_of_Corneto_flight_progr_DW.obj_mo.isSetupComplete) {
      status = pwm_disarm(&Copy_of_Corneto_flight_progr_DW.obj_mo.pwmDevHandler,
                          &Copy_of_Corneto_flight_progr_DW.obj_mo.armAdvertiseObj);
      Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus | status);
      status = pwm_resetServo
        (&Copy_of_Corneto_flight_progr_DW.obj_mo.pwmDevHandler,
         Copy_of_Corneto_flight_progr_DW.obj_mo.servoCount,
         Copy_of_Corneto_flight_progr_DW.obj_mo.channelMask,
         Copy_of_Corneto_flight_progr_DW.obj_mo.isMain,
         &Copy_of_Corneto_flight_progr_DW.obj_mo.actuatorAdvertiseObj);
      Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus | status);
      status = pwm_close(&Copy_of_Corneto_flight_progr_DW.obj_mo.pwmDevHandler,
                         &Copy_of_Corneto_flight_progr_DW.obj_mo.actuatorAdvertiseObj,
                         &Copy_of_Corneto_flight_progr_DW.obj_mo.armAdvertiseObj);
      Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Copy_of_Corneto_flight_progr_DW.obj_mo.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S22>/PX4 PWM Output1'
  // End of Terminate for SubSystem: '<S8>/Emulated Pixhawk'

  // Terminate for MATLABSystem: '<Root>/Read Parameter'
  if (!Copy_of_Corneto_flight_progr_DW.obj_b.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter'

  // Terminate for MATLABSystem: '<Root>/Read Parameter1'
  if (!Copy_of_Corneto_flight_progr_DW.obj_l.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter1'

  // Terminate for MATLABSystem: '<Root>/Read Parameter2'
  if (!Copy_of_Corneto_flight_progr_DW.obj_m.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter2'

  // Terminate for MATLABSystem: '<S7>/SinkBlock'
  if (!Copy_of_Corneto_flight_progr_DW.obj_o.matlabCodegenIsDeleted) {
    Copy_of_Corneto_flight_progr_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Copy_of_Corneto_flight_progr_DW.obj_o.isInitialized == 1) &&
        Copy_of_Corneto_flight_progr_DW.obj_o.isSetupComplete) {
      uORB_write_terminate
        (&Copy_of_Corneto_flight_progr_DW.obj_o.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
