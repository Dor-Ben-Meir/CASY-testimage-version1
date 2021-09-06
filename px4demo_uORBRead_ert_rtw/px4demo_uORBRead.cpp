//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_uORBRead.cpp
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

// Block signals (default storage)
B_px4demo_uORBRead_T px4demo_uORBRead_B;

// Block states (default storage)
DW_px4demo_uORBRead_T px4demo_uORBRead_DW;

// Previous zero-crossings (trigger) states
PrevZCX_px4demo_uORBRead_T px4demo_uORBRead_PrevZCX;

// Real-time model
RT_MODEL_px4demo_uORBRead_T px4demo_uORBRead_M_ = RT_MODEL_px4demo_uORBRead_T();
RT_MODEL_px4demo_uORBRead_T *const px4demo_uORBRead_M = &px4demo_uORBRead_M_;

// Forward declaration for local functions
static void px4demo_uORBRe_SystemCore_setup(px4_internal_block_PWM_px4dem_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void rate_monotonic_scheduler(void);
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
// Set which subrates need to run this base step (base rate always runs).
// This function must be called prior to calling the model step function
// in order to "remember" which rates need to run this base step.  The
// buffering of events allows for overlapping preemption.
//
void px4demo_uORBRead_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  // Task runs when its counter is zero, computed via rtmStepTask macro
  eventFlags[1] = ((boolean_T)rtmStepTask(px4demo_uORBRead_M, 1));
}

//
//   This function updates active task flag for each subrate
// and rate transition flags for tasks that exchange data.
// The function assumes rate-monotonic multitasking scheduler.
// The function must be called at model base rate so that
// the generated code self-manages all its subrates and rate
// transition flags.
//
static void rate_monotonic_scheduler(void)
{
  // To ensure a deterministic data transfer between two rates,
  //  data is transferred at the priority of a fast task and the frequency
  //  of the slow task.  The following flags indicate when the data transfer
  //  happens.  That is, a rate interaction flag is set true when both rates
  //  will run, and false otherwise.


  // tid 0 shares data with slower tid rate: 1
  px4demo_uORBRead_M->Timing.RateInteraction.TID0_1 =
    (px4demo_uORBRead_M->Timing.TaskCounters.TID[1] == 0);

  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (px4demo_uORBRead_M->Timing.TaskCounters.TID[1])++;
  if ((px4demo_uORBRead_M->Timing.TaskCounters.TID[1]) > 199) {// Sample time: [1.0s, 0.0s] 
    px4demo_uORBRead_M->Timing.TaskCounters.TID[1] = 0;
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

static void px4demo_uORBRe_SystemCore_setup(px4_internal_block_PWM_px4dem_T *obj,
  boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->isMain = true;
  obj->pwmDevObj = MW_PWM_OUTPUT_MAIN_DEVICE_PATH;
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

// Model step function for TID0
void px4demo_uORBRead_step0(void)      // Sample time: [0.005s, 0.0s]
{
  g_dsp_private_SlidingWindowAv_T *obj;
  real_T rtb_VectorConcatenate_idx_2_t_0;
  real_T rtb_VectorConcatenate_idx_2_t_1;
  real_T rtb_VectorConcatenate_idx_2_tmp;
  int32_T i;
  uint32_T EmulatedPixhawk_ELAPS_T;
  uint16_T status;
  boolean_T rtb_CastToBoolean2;
  boolean_T rtb_MECO_log;
  boolean_T rtb_NOT;
  boolean_T rtb_NOT_h;
  boolean_T rtb_NOT_j;
  boolean_T rtb_recovery_log;
  ZCEventType zcEvent;

  {                                    // Sample time: [0.005s, 0.0s]
    rate_monotonic_scheduler();
  }

  // StringToASCII: '<S11>/String to ASCII' incorporates:
  //   StringConstant: '<S11>/String Constant'

  strncpy(&px4demo_uORBRead_B.cv[0], &px4demo_uORBRead_P.StringConstant_String[0],
          50U);

  // BusAssignment: '<S11>/Bus Assignment' incorporates:
  //   Constant: '<S11>/Constant'
  //   Constant: '<S70>/Constant'
  //   StringToASCII: '<S11>/String to ASCII'

  px4demo_uORBRead_B.BusAssignment = px4demo_uORBRead_P.Constant_Value_n;
  px4demo_uORBRead_B.BusAssignment.severity =
    px4demo_uORBRead_P.Constant_Value_cd;
  for (i = 0; i < 50; i++) {
    px4demo_uORBRead_B.BusAssignment.text[i] = static_cast<uint8_T>
      (px4demo_uORBRead_B.cv[i]);
  }

  // End of BusAssignment: '<S11>/Bus Assignment'

  // MATLABSystem: '<S71>/SinkBlock' incorporates:
  //   BusAssignment: '<S11>/Bus Assignment'

  uORB_write_step(px4demo_uORBRead_DW.obj_o.orbMetadataObj,
                  &px4demo_uORBRead_DW.obj_o.orbAdvertiseObj,
                  &px4demo_uORBRead_B.BusAssignment);

  // RateTransition: '<Root>/Rate Transition' incorporates:
  //   RateTransition: '<Root>/Rate Transition1'

  if (px4demo_uORBRead_M->Timing.RateInteraction.TID0_1) {
    // RateTransition: '<Root>/Rate Transition'
    px4demo_uORBRead_B.RateTransition =
      px4demo_uORBRead_DW.RateTransition_Buffer0;

    // RateTransition: '<Root>/Rate Transition1'
    px4demo_uORBRead_B.RateTransition1 =
      px4demo_uORBRead_DW.RateTransition1_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition'

  // MATLABSystem: '<S13>/SourceBlock' incorporates:
  //   Inport: '<S14>/In1'

  rtb_NOT = uORB_read_step(px4demo_uORBRead_DW.obj_n.orbMetadataObj,
    &px4demo_uORBRead_DW.obj_n.eventStructObj,
    &px4demo_uORBRead_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S13>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  if (rtb_NOT) {
    px4demo_uORBRead_B.In1_k = px4demo_uORBRead_B.b_varargout_2_cx;
  }

  // End of MATLABSystem: '<S13>/SourceBlock'
  // End of Outputs for SubSystem: '<S13>/Enabled Subsystem'

  // MATLABSystem: '<S72>/SourceBlock' incorporates:
  //   Inport: '<S73>/In1'

  rtb_NOT = uORB_read_step(px4demo_uORBRead_DW.obj_ph.orbMetadataObj,
    &px4demo_uORBRead_DW.obj_ph.eventStructObj,
    &px4demo_uORBRead_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S72>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S73>/Enable'

  if (rtb_NOT) {
    px4demo_uORBRead_B.In1 = px4demo_uORBRead_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S72>/SourceBlock'
  // End of Outputs for SubSystem: '<S72>/Enabled Subsystem'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S18>/In1'

  rtb_NOT = uORB_read_step(px4demo_uORBRead_DW.obj_hy.orbMetadataObj,
    &px4demo_uORBRead_DW.obj_hy.eventStructObj,
    &px4demo_uORBRead_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S18>/Enable'

  if (rtb_NOT) {
    px4demo_uORBRead_B.In1_p = px4demo_uORBRead_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S17>/In1'

  rtb_NOT = uORB_read_step(px4demo_uORBRead_DW.obj_j.orbMetadataObj,
    &px4demo_uORBRead_DW.obj_j.eventStructObj,
    &px4demo_uORBRead_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S17>/Enable'

  if (rtb_NOT) {
    px4demo_uORBRead_B.In1_m = px4demo_uORBRead_B.b_varargout_2_c;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double29'
  //   DataTypeConversion: '<Root>/Cast To Double30'
  //   DataTypeConversion: '<Root>/Cast To Double31'

  px4demo_uORBRead_B.scale = 3.3121686421112381E-170;
  px4demo_uORBRead_B.absxk = fabs(static_cast<real_T>
    (px4demo_uORBRead_B.In1_p.vx));
  if (px4demo_uORBRead_B.absxk > 3.3121686421112381E-170) {
    px4demo_uORBRead_B.y = 1.0;
    px4demo_uORBRead_B.scale = px4demo_uORBRead_B.absxk;
  } else {
    px4demo_uORBRead_B.t = px4demo_uORBRead_B.absxk / 3.3121686421112381E-170;
    px4demo_uORBRead_B.y = px4demo_uORBRead_B.t * px4demo_uORBRead_B.t;
  }

  px4demo_uORBRead_B.absxk = fabs(static_cast<real_T>
    (px4demo_uORBRead_B.In1_p.vy));
  if (px4demo_uORBRead_B.absxk > px4demo_uORBRead_B.scale) {
    px4demo_uORBRead_B.t = px4demo_uORBRead_B.scale / px4demo_uORBRead_B.absxk;
    px4demo_uORBRead_B.y = px4demo_uORBRead_B.y * px4demo_uORBRead_B.t *
      px4demo_uORBRead_B.t + 1.0;
    px4demo_uORBRead_B.scale = px4demo_uORBRead_B.absxk;
  } else {
    px4demo_uORBRead_B.t = px4demo_uORBRead_B.absxk / px4demo_uORBRead_B.scale;
    px4demo_uORBRead_B.y += px4demo_uORBRead_B.t * px4demo_uORBRead_B.t;
  }

  px4demo_uORBRead_B.absxk = fabs(static_cast<real_T>
    (px4demo_uORBRead_B.In1_p.vz));
  if (px4demo_uORBRead_B.absxk > px4demo_uORBRead_B.scale) {
    px4demo_uORBRead_B.t = px4demo_uORBRead_B.scale / px4demo_uORBRead_B.absxk;
    px4demo_uORBRead_B.y = px4demo_uORBRead_B.y * px4demo_uORBRead_B.t *
      px4demo_uORBRead_B.t + 1.0;
    px4demo_uORBRead_B.scale = px4demo_uORBRead_B.absxk;
  } else {
    px4demo_uORBRead_B.t = px4demo_uORBRead_B.absxk / px4demo_uORBRead_B.scale;
    px4demo_uORBRead_B.y += px4demo_uORBRead_B.t * px4demo_uORBRead_B.t;
  }

  px4demo_uORBRead_B.y = px4demo_uORBRead_B.scale * sqrt(px4demo_uORBRead_B.y);

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // DiscretePulseGenerator: '<S8>/100 Hz'
  px4demo_uORBRead_B.u00Hz = (px4demo_uORBRead_DW.clockTickCounter <
    px4demo_uORBRead_P.u00Hz_Duty) && (px4demo_uORBRead_DW.clockTickCounter >= 0)
    ? px4demo_uORBRead_P.u00Hz_Amp : 0.0;
  if (px4demo_uORBRead_DW.clockTickCounter >= px4demo_uORBRead_P.u00Hz_Period -
      1.0) {
    px4demo_uORBRead_DW.clockTickCounter = 0;
  } else {
    px4demo_uORBRead_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S8>/100 Hz'

  // Sqrt: '<S66>/sqrt' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'
  //   Product: '<S67>/Product'
  //   Product: '<S67>/Product1'
  //   Product: '<S67>/Product2'
  //   Product: '<S67>/Product3'
  //   Sum: '<S67>/Sum'

  px4demo_uORBRead_B.scale = sqrt(((static_cast<real_T>
    (px4demo_uORBRead_B.In1.q[0]) * px4demo_uORBRead_B.In1.q[0] +
    static_cast<real_T>(px4demo_uORBRead_B.In1.q[1]) * px4demo_uORBRead_B.In1.q
    [1]) + static_cast<real_T>(px4demo_uORBRead_B.In1.q[2]) *
    px4demo_uORBRead_B.In1.q[2]) + static_cast<real_T>(px4demo_uORBRead_B.In1.q
    [3]) * px4demo_uORBRead_B.In1.q[3]);

  // Product: '<S61>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  px4demo_uORBRead_B.absxk = px4demo_uORBRead_B.In1.q[0] /
    px4demo_uORBRead_B.scale;

  // Product: '<S61>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  px4demo_uORBRead_B.t = px4demo_uORBRead_B.In1.q[1] / px4demo_uORBRead_B.scale;

  // Product: '<S61>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  px4demo_uORBRead_B.CastToDouble18 = px4demo_uORBRead_B.In1.q[2] /
    px4demo_uORBRead_B.scale;

  // Product: '<S61>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  px4demo_uORBRead_B.scale = px4demo_uORBRead_B.In1.q[3] /
    px4demo_uORBRead_B.scale;

  // Fcn: '<S9>/fcn3'
  px4demo_uORBRead_B.fcn3 = (px4demo_uORBRead_B.t * px4demo_uORBRead_B.scale -
    px4demo_uORBRead_B.absxk * px4demo_uORBRead_B.CastToDouble18) * -2.0;

  // If: '<S62>/If' incorporates:
  //   Constant: '<S63>/Constant'
  //   Constant: '<S64>/Constant'

  if (px4demo_uORBRead_B.fcn3 > 1.0) {
    px4demo_uORBRead_B.fcn3 = px4demo_uORBRead_P.Constant_Value_l;
  } else if (px4demo_uORBRead_B.fcn3 < -1.0) {
    px4demo_uORBRead_B.fcn3 = px4demo_uORBRead_P.Constant_Value_d;
  }

  // End of If: '<S62>/If'

  // Fcn: '<S9>/fcn5' incorporates:
  //   Fcn: '<S9>/fcn2'

  px4demo_uORBRead_B.rtb_VectorConcatenate_idx_2_tmp = px4demo_uORBRead_B.absxk *
    px4demo_uORBRead_B.absxk;
  rtb_VectorConcatenate_idx_2_tmp = px4demo_uORBRead_B.t * px4demo_uORBRead_B.t;
  rtb_VectorConcatenate_idx_2_t_0 = px4demo_uORBRead_B.CastToDouble18 *
    px4demo_uORBRead_B.CastToDouble18;
  rtb_VectorConcatenate_idx_2_t_1 = px4demo_uORBRead_B.scale *
    px4demo_uORBRead_B.scale;

  // Trigonometry: '<S60>/Trigonometric Function3' incorporates:
  //   Fcn: '<S9>/fcn4'
  //   Fcn: '<S9>/fcn5'

  px4demo_uORBRead_B.rtb_VectorConcatenate_idx_2 = rt_atan2d_snf
    ((px4demo_uORBRead_B.CastToDouble18 * px4demo_uORBRead_B.scale +
      px4demo_uORBRead_B.absxk * px4demo_uORBRead_B.t) * 2.0,
     ((px4demo_uORBRead_B.rtb_VectorConcatenate_idx_2_tmp -
       rtb_VectorConcatenate_idx_2_tmp) - rtb_VectorConcatenate_idx_2_t_0) +
     rtb_VectorConcatenate_idx_2_t_1);

  // Outputs for Triggered SubSystem: '<S8>/Emulated Pixhawk' incorporates:
  //   TriggerPort: '<S19>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &px4demo_uORBRead_PrevZCX.EmulatedPixhawk_Trig_ZCE,
                     (px4demo_uORBRead_B.u00Hz));
  if (zcEvent != NO_ZCEVENT) {
    if (px4demo_uORBRead_DW.EmulatedPixhawk_RESET_ELAPS_T) {
      EmulatedPixhawk_ELAPS_T = 0U;
    } else {
      EmulatedPixhawk_ELAPS_T = px4demo_uORBRead_M->Timing.clockTick0 -
        px4demo_uORBRead_DW.EmulatedPixhawk_PREV_T;
    }

    px4demo_uORBRead_DW.EmulatedPixhawk_PREV_T =
      px4demo_uORBRead_M->Timing.clockTick0;
    px4demo_uORBRead_DW.EmulatedPixhawk_RESET_ELAPS_T = false;

    // DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double16'

    px4demo_uORBRead_B.u00Hz = (px4demo_uORBRead_B.In1.rollspeed -
      px4demo_uORBRead_P.DiscreteTransferFcn_DenCoef[1] *
      px4demo_uORBRead_DW.DiscreteTransferFcn_states) /
      px4demo_uORBRead_P.DiscreteTransferFcn_DenCoef[0];
    px4demo_uORBRead_B.numAccum =
      px4demo_uORBRead_P.DiscreteTransferFcn_NumCoef[0] *
      px4demo_uORBRead_B.u00Hz + px4demo_uORBRead_P.DiscreteTransferFcn_NumCoef
      [1] * px4demo_uORBRead_DW.DiscreteTransferFcn_states;

    // DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S25>/Constant'
    //   DataTypeConversion: '<S19>/Cast To Double36'

    if (px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
      // Switch: '<S19>/Switch1' incorporates:
      //   Constant: '<S19>/One1'
      //   Constant: '<S19>/One2'
      //   DataTypeConversion: '<Root>/Cast To Boolean3'

      if (px4demo_uORBRead_B.RateTransition1 != 0) {
        px4demo_uORBRead_B.rtb_Switch_l_idx_0 = px4demo_uORBRead_P.One1_Value;
      } else {
        px4demo_uORBRead_B.rtb_Switch_l_idx_0 = px4demo_uORBRead_P.One2_Value;
      }

      if ((px4demo_uORBRead_B.rtb_Switch_l_idx_0 != 0.0) ||
          (px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTAT_kw =
          px4demo_uORBRead_P.Constant_Value_oa;
      } else {
        // DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTAT_kw +=
          static_cast<real32_T>
          (px4demo_uORBRead_P.DiscreteTimeIntegrator_gainval *
           static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
           * px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U);
      }
    }

    // End of DiscreteIntegrator: '<S25>/Discrete-Time Integrator'

    // Sum: '<S25>/Sum3' incorporates:
    //   Constant: '<Root>/Constant2'

    px4demo_uORBRead_B.CastToDouble6 = px4demo_uORBRead_P.Constant2_Value_c -
      px4demo_uORBRead_B.rtb_VectorConcatenate_idx_2;

    // Product: '<S25>/Product1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'
    //   DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn'
    //   Lookup_n-D: '<S26>/1-D Lookup Table3'
    //   Lookup_n-D: '<S26>/1-D Lookup Table5'
    //   Product: '<S25>/Product2'
    //   Sum: '<S25>/Sum4'
    //   Sum: '<S25>/Sum5'

    px4demo_uORBRead_B.rtb_fin_cmd_idx_0 = ((look2_binlcapw(static_cast<real_T>
      (px4demo_uORBRead_B.In1_m.alt), px4demo_uORBRead_B.y,
      px4demo_uORBRead_P.Autopilot.Phi.h_bkpts_m,
      px4demo_uORBRead_P.Autopilot.Phi.V_bkpts_mps,
      px4demo_uORBRead_P.Autopilot.Phi.Kp_phi_vec,
      px4demo_uORBRead_P.uDLookupTable5_maxIndex, 3U) *
      px4demo_uORBRead_B.CastToDouble6 +
      px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTAT_kw) -
      px4demo_uORBRead_B.numAccum) * look2_binlcapw(static_cast<real_T>
      (px4demo_uORBRead_B.In1_m.alt), px4demo_uORBRead_B.y,
      px4demo_uORBRead_P.Autopilot.Phi.h_bkpts_m,
      px4demo_uORBRead_P.Autopilot.Phi.V_bkpts_mps,
      px4demo_uORBRead_P.Autopilot.Phi.Kp_p_vec,
      px4demo_uORBRead_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S27>/Product' incorporates:
    //   Constant: '<S20>/Zero'
    //   Constant: '<S27>/Constant7'

    for (i = 0; i < 4; i++) {
      px4demo_uORBRead_B.siB_cmd[i] = px4demo_uORBRead_P.Constant7_Value[i + 8] *
        px4demo_uORBRead_P.Zero_Value + (px4demo_uORBRead_P.Constant7_Value[i +
        4] * px4demo_uORBRead_P.Zero_Value +
        px4demo_uORBRead_P.Constant7_Value[i] *
        px4demo_uORBRead_B.rtb_fin_cmd_idx_0);
    }

    // End of Product: '<S27>/Product'

    // Switch: '<S19>/Switch' incorporates:
    //   Constant: '<S24>/One5'
    //   Constant: '<S24>/One6'
    //   Constant: '<S24>/One7'
    //   Constant: '<S24>/One8'
    //   DataTypeConversion: '<Root>/Cast To Boolean1'
    //   Gain: '<S56>/Gain1'
    //   Gain: '<S57>/Gain1'
    //   Gain: '<S58>/Gain1'
    //   Gain: '<S59>/Gain1'

    if (px4demo_uORBRead_B.RateTransition != 0.0F) {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = px4demo_uORBRead_B.siB_cmd[0];
      px4demo_uORBRead_B.rtb_Switch_l_idx_1 = px4demo_uORBRead_B.siB_cmd[1];
      px4demo_uORBRead_B.rtb_Switch_l_idx_2 = px4demo_uORBRead_B.siB_cmd[2];
      px4demo_uORBRead_B.rtb_Switch_l_idx_3 = px4demo_uORBRead_B.siB_cmd[3];
    } else {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = px4demo_uORBRead_P.Gain1_Gain *
        px4demo_uORBRead_P.One5_Value_e;
      px4demo_uORBRead_B.rtb_Switch_l_idx_1 = px4demo_uORBRead_P.Gain1_Gain_m *
        px4demo_uORBRead_P.One6_Value_p;
      px4demo_uORBRead_B.rtb_Switch_l_idx_2 = px4demo_uORBRead_P.Gain1_Gain_l *
        px4demo_uORBRead_P.One7_Value;
      px4demo_uORBRead_B.rtb_Switch_l_idx_3 = px4demo_uORBRead_P.Gain1_Gain_k *
        px4demo_uORBRead_P.One8_Value;
    }

    // End of Switch: '<S19>/Switch'

    // DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double13'

    px4demo_uORBRead_B.rtb_fin_cmd_idx_0 = (px4demo_uORBRead_B.In1_k.x -
      px4demo_uORBRead_P.DiscreteTransferFcn_DenCoef_l[1] *
      px4demo_uORBRead_DW.DiscreteTransferFcn_states_i) /
      px4demo_uORBRead_P.DiscreteTransferFcn_DenCoef_l[0];
    px4demo_uORBRead_B.cumRevIndex =
      px4demo_uORBRead_P.DiscreteTransferFcn_NumCoef_b[0] *
      px4demo_uORBRead_B.rtb_fin_cmd_idx_0 +
      px4demo_uORBRead_P.DiscreteTransferFcn_NumCoef_b[1] *
      px4demo_uORBRead_DW.DiscreteTransferFcn_states_i;

    // RelationalOperator: '<S39>/Compare' incorporates:
    //   Constant: '<S39>/Constant'
    //   DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'

    rtb_CastToBoolean2 = (px4demo_uORBRead_B.cumRevIndex >=
                          px4demo_uORBRead_P.Flight_Logic.Ax_launch_accel_threshold_mps2);

    // Logic: '<S41>/NOT' incorporates:
    //   Logic: '<S41>/AND'
    //   Memory: '<S30>/Memory'

    rtb_NOT = ((!rtb_CastToBoolean2) &&
               (!px4demo_uORBRead_DW.Memory_PreviousInput));

    // DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S41>/Constant1'

    if (px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_m == 0) {
      if (rtb_NOT || (px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRe_f != 0))
      {
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE =
          px4demo_uORBRead_P.Constant1_Value_p;
      } else {
        // DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE +=
          px4demo_uORBRead_P.DiscreteTimeIntegrator_gainva_p *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_e;
      }
    }

    // End of DiscreteIntegrator: '<S41>/Discrete-Time Integrator'

    // Switch: '<S42>/Switch1' incorporates:
    //   Constant: '<S40>/Constant'
    //   Logic: '<S30>/AND'
    //   Memory: '<S42>/Memory'
    //   RelationalOperator: '<S40>/Compare'

    px4demo_uORBRead_DW.Memory_PreviousInput = ((rtb_CastToBoolean2 &&
      (px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE >=
       px4demo_uORBRead_P.Flight_Logic.Ax_launch_timer_threshold_sec)) ||
      px4demo_uORBRead_DW.Memory_PreviousInput_a);

    // Logic: '<S46>/NOT' incorporates:
    //   Constant: '<S44>/Constant'
    //   DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'
    //   Logic: '<S31>/AND'
    //   RelationalOperator: '<S44>/Compare'

    rtb_CastToBoolean2 = ((!px4demo_uORBRead_DW.Memory_PreviousInput) ||
                          (!(px4demo_uORBRead_B.cumRevIndex <=
      px4demo_uORBRead_P.CompareToConstant2_const)));

    // DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S46>/Constant1'

    if (px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_j == 0) {
      if (rtb_CastToBoolean2 ||
          (px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRe_i != 0)) {
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_c =
          px4demo_uORBRead_P.Constant1_Value_m;
      } else {
        // DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_c +=
          px4demo_uORBRead_P.DiscreteTimeIntegrator_gainva_h *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_o;
      }
    }

    // End of DiscreteIntegrator: '<S46>/Discrete-Time Integrator'

    // Switch: '<S47>/Switch1' incorporates:
    //   Constant: '<S43>/Constant'
    //   Memory: '<S47>/Memory'
    //   RelationalOperator: '<S43>/Compare'

    px4demo_uORBRead_DW.Memory_PreviousInput_o =
      ((px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_c >=
        px4demo_uORBRead_P.Flight_Logic.Ax_MECO_timer_threshold_sec) ||
       px4demo_uORBRead_DW.Memory_PreviousInput_o);

    // Switch: '<S30>/Switch' incorporates:
    //   Constant: '<S30>/Constant'

    if (px4demo_uORBRead_DW.Memory_PreviousInput) {
      px4demo_uORBRead_B.CastToDouble8 =
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE;
    } else {
      px4demo_uORBRead_B.CastToDouble8 = px4demo_uORBRead_P.Constant_Value_hl;
    }

    // End of Switch: '<S30>/Switch'

    // Logic: '<S31>/AND1' incorporates:
    //   Constant: '<S45>/Constant'
    //   RelationalOperator: '<S45>/Compare'

    rtb_MECO_log = (px4demo_uORBRead_DW.Memory_PreviousInput_o ||
                    (px4demo_uORBRead_B.CastToDouble8 >=
                     px4demo_uORBRead_P.Flight_Logic.MECO_timeout_TOF_sec));

    // MATLABSystem: '<S28>/Moving Average1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'

    if (px4demo_uORBRead_DW.obj.TunablePropsChanged) {
      px4demo_uORBRead_DW.obj.TunablePropsChanged = false;
    }

    obj = px4demo_uORBRead_DW.obj.pStatistic;
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

    px4demo_uORBRead_B.cumRevIndex = obj->pCumRevIndex;
    px4demo_uORBRead_B.csum = obj->pCumSum;
    for (i = 0; i < 9; i++) {
      px4demo_uORBRead_B.csumrev[i] = obj->pCumSumRev[i];
    }

    px4demo_uORBRead_B.csum += static_cast<real_T>(px4demo_uORBRead_B.In1_m.alt);
    px4demo_uORBRead_B.z = px4demo_uORBRead_B.csumrev[static_cast<int32_T>
      (px4demo_uORBRead_B.cumRevIndex) - 1] + px4demo_uORBRead_B.csum;
    px4demo_uORBRead_B.csumrev[static_cast<int32_T>
      (px4demo_uORBRead_B.cumRevIndex) - 1] = px4demo_uORBRead_B.In1_m.alt;
    if (px4demo_uORBRead_B.cumRevIndex != 9.0) {
      px4demo_uORBRead_B.cumRevIndex++;
    } else {
      px4demo_uORBRead_B.cumRevIndex = 1.0;
      px4demo_uORBRead_B.csum = 0.0;
      for (i = 7; i >= 0; i--) {
        px4demo_uORBRead_B.csumrev[i] += px4demo_uORBRead_B.csumrev[i + 1];
      }
    }

    obj->pCumSum = px4demo_uORBRead_B.csum;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = px4demo_uORBRead_B.csumrev[i];
    }

    obj->pCumRevIndex = px4demo_uORBRead_B.cumRevIndex;
    px4demo_uORBRead_B.cumRevIndex = px4demo_uORBRead_B.z / 10.0;

    // End of MATLABSystem: '<S28>/Moving Average1'

    // Logic: '<S37>/NOT' incorporates:
    //   RelationalOperator: '<S36>/FixPt Relational Operator'
    //   UnitDelay: '<S36>/Delay Input1'
    //
    //  Block description for '<S36>/Delay Input1':
    //
    //   Store in Global RAM

    rtb_NOT_h = !(px4demo_uORBRead_B.cumRevIndex <
                  px4demo_uORBRead_DW.DelayInput1_DSTATE);

    // DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S37>/Constant1'

    if (px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTE_jm == 0) {
      if (rtb_NOT_h || (px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevR_ia != 0))
      {
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_b =
          px4demo_uORBRead_P.Constant1_Value_i;
      } else {
        // DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_b +=
          px4demo_uORBRead_P.DiscreteTimeIntegrator_gainva_n *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_d;
      }
    }

    // End of DiscreteIntegrator: '<S37>/Discrete-Time Integrator'

    // Switch: '<S38>/Switch1' incorporates:
    //   Constant: '<S33>/Constant'
    //   Constant: '<S34>/Constant'
    //   DataTypeConversion: '<Root>/Cast To Double31'
    //   Logic: '<S28>/AND'
    //   Memory: '<S38>/Memory'
    //   RelationalOperator: '<S33>/Compare'
    //   RelationalOperator: '<S34>/Compare'

    px4demo_uORBRead_DW.Memory_PreviousInput_d = ((rtb_MECO_log &&
      (px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_b >=
       px4demo_uORBRead_P.Flight_Logic.h_apogee_timer_threshold_sec) &&
      (px4demo_uORBRead_B.In1_p.vz > px4demo_uORBRead_P.CompareToConstant_const))
      || px4demo_uORBRead_DW.Memory_PreviousInput_d);

    // Logic: '<S50>/NOT' incorporates:
    //   Constant: '<S35>/Constant'
    //   Logic: '<S28>/AND1'
    //   RelationalOperator: '<S35>/Compare'

    rtb_NOT_j = ((!px4demo_uORBRead_DW.Memory_PreviousInput_d) &&
                 (!(px4demo_uORBRead_B.CastToDouble8 >=
                    px4demo_uORBRead_P.Flight_Logic.apogee_timeout_TOF_sec)));

    // DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S50>/Constant1'

    if (px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_o == 0) {
      if (rtb_NOT_j || (px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevR_iv != 0))
      {
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_k =
          px4demo_uORBRead_P.Constant1_Value_k;
      } else {
        // DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
        px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_k +=
          px4demo_uORBRead_P.DiscreteTimeIntegrator_gainva_b *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_h;
      }
    }

    // End of DiscreteIntegrator: '<S50>/Discrete-Time Integrator'

    // Switch: '<S51>/Switch1' incorporates:
    //   Constant: '<S48>/Constant'
    //   Memory: '<S51>/Memory'
    //   RelationalOperator: '<S48>/Compare'

    px4demo_uORBRead_DW.Memory_PreviousInput_b =
      ((px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_k >=
        px4demo_uORBRead_P.Flight_Logic.apogee_recovery_timer_threshold_sec) ||
       px4demo_uORBRead_DW.Memory_PreviousInput_b);

    // Logic: '<S32>/AND2' incorporates:
    //   Constant: '<S32>/Constant'
    //   Constant: '<S49>/Constant'
    //   Logic: '<S32>/AND1'
    //   Logic: '<S32>/NOT'
    //   RelationalOperator: '<S49>/Compare'

    rtb_recovery_log = ((px4demo_uORBRead_DW.Memory_PreviousInput_b ||
                         (px4demo_uORBRead_B.CastToDouble8 >=
                          px4demo_uORBRead_P.Flight_Logic.recovery_timeout_TOF_sec))
                        &&
                        (!(px4demo_uORBRead_P.Flight_Logic.disable_recovery_manual
      != 0.0)));

    // DataTypeConversion: '<S19>/Cast To Double3' incorporates:
    //   DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn'

    px4demo_uORBRead_B.CastToDouble3[4] = px4demo_uORBRead_B.numAccum;

    // Switch: '<S29>/Switch3' incorporates:
    //   Constant: '<S22>/Constant5'
    //   Constant: '<S29>/Constant5'
    //   Switch: '<S29>/Switch'
    //   Switch: '<S29>/Switch1'
    //   Switch: '<S29>/Switch2'
    //   Switch: '<S29>/Switch4'

    if (rtb_recovery_log) {
      // DataTypeConversion: '<S19>/Cast To Double3' incorporates:
      //   Constant: '<S29>/Constant4'

      px4demo_uORBRead_B.CastToDouble3[5] = px4demo_uORBRead_P.Constant4_Value;
    } else if (px4demo_uORBRead_P.Constant5_Value_n != 0.0) {
      // Switch: '<S29>/Switch4' incorporates:
      //   Constant: '<S29>/Constant6'
      //   DataTypeConversion: '<S19>/Cast To Double3'

      px4demo_uORBRead_B.CastToDouble3[5] = px4demo_uORBRead_P.Constant6_Value;
    } else if (rtb_MECO_log) {
      // Switch: '<S29>/Switch2' incorporates:
      //   Constant: '<S29>/Constant3'
      //   DataTypeConversion: '<S19>/Cast To Double3'
      //   Switch: '<S29>/Switch4'

      px4demo_uORBRead_B.CastToDouble3[5] = px4demo_uORBRead_P.Constant3_Value;
    } else if (px4demo_uORBRead_DW.Memory_PreviousInput) {
      // Switch: '<S29>/Switch1' incorporates:
      //   Constant: '<S29>/Constant2'
      //   DataTypeConversion: '<S19>/Cast To Double3'
      //   Switch: '<S29>/Switch2'
      //   Switch: '<S29>/Switch4'

      px4demo_uORBRead_B.CastToDouble3[5] = px4demo_uORBRead_P.Constant2_Value;
    } else if (px4demo_uORBRead_P.Constant5_Value != 0.0) {
      // Switch: '<S29>/Switch' incorporates:
      //   Constant: '<S29>/Constant1'
      //   DataTypeConversion: '<S19>/Cast To Double3'
      //   Switch: '<S29>/Switch1'
      //   Switch: '<S29>/Switch2'
      //   Switch: '<S29>/Switch4'

      px4demo_uORBRead_B.CastToDouble3[5] = px4demo_uORBRead_P.Constant1_Value;
    } else {
      // DataTypeConversion: '<S19>/Cast To Double3' incorporates:
      //   Constant: '<S29>/Constant'

      px4demo_uORBRead_B.CastToDouble3[5] = px4demo_uORBRead_P.Constant_Value_k0;
    }

    // End of Switch: '<S29>/Switch3'

    // DataTypeConversion: '<S19>/Cast To Double3'
    px4demo_uORBRead_B.CastToDouble3[0] = px4demo_uORBRead_B.rtb_Switch_l_idx_0;
    px4demo_uORBRead_B.CastToDouble3[6] = px4demo_uORBRead_B.siB_cmd[0];
    px4demo_uORBRead_B.CastToDouble3[1] = px4demo_uORBRead_B.rtb_Switch_l_idx_1;
    px4demo_uORBRead_B.CastToDouble3[7] = px4demo_uORBRead_B.siB_cmd[1];
    px4demo_uORBRead_B.CastToDouble3[2] = px4demo_uORBRead_B.rtb_Switch_l_idx_2;
    px4demo_uORBRead_B.CastToDouble3[8] = px4demo_uORBRead_B.siB_cmd[2];
    px4demo_uORBRead_B.CastToDouble3[3] = px4demo_uORBRead_B.rtb_Switch_l_idx_3;
    px4demo_uORBRead_B.CastToDouble3[9] = px4demo_uORBRead_B.siB_cmd[3];

    // MATLABSystem: '<S23>/PX4 PWM Output1'
    for (i = 0; i < 8; i++) {
      px4demo_uORBRead_B.pwmValue[i] = 0U;
    }

    // Gain: '<S52>/Gain'
    px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Gain_Gain *
      px4demo_uORBRead_B.rtb_Switch_l_idx_0;

    // Saturate: '<S23>/Saturation'
    if (px4demo_uORBRead_B.numAccum > px4demo_uORBRead_P.Saturation_UpperSat) {
      px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Saturation_UpperSat;
    } else if (px4demo_uORBRead_B.numAccum <
               px4demo_uORBRead_P.Saturation_LowerSat) {
      px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation'

    // DataTypeConversion: '<S23>/Cast To Double' incorporates:
    //   Constant: '<S23>/One'
    //   Gain: '<S23>/Gain'
    //   Sum: '<S23>/Add'

    px4demo_uORBRead_B.rtb_Switch_l_idx_0 = floor(px4demo_uORBRead_P.Gain_Gain_n
      * px4demo_uORBRead_B.numAccum + px4demo_uORBRead_P.One_Value);
    if (rtIsNaN(px4demo_uORBRead_B.rtb_Switch_l_idx_0) || rtIsInf
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0)) {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = 0.0;
    } else {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = fmod
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double'

    px4demo_uORBRead_B.pwmValue[0] = static_cast<uint16_T>
      (px4demo_uORBRead_B.rtb_Switch_l_idx_0 < 0.0 ? static_cast<int32_T>(
        static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-px4demo_uORBRead_B.rtb_Switch_l_idx_0)))) : static_cast<int32_T>(
        static_cast<uint16_T>(px4demo_uORBRead_B.rtb_Switch_l_idx_0)));

    // Gain: '<S53>/Gain'
    px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Gain_Gain_d *
      px4demo_uORBRead_B.rtb_Switch_l_idx_1;

    // Saturate: '<S23>/Saturation1'
    if (px4demo_uORBRead_B.numAccum > px4demo_uORBRead_P.Saturation1_UpperSat) {
      px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Saturation1_UpperSat;
    } else if (px4demo_uORBRead_B.numAccum <
               px4demo_uORBRead_P.Saturation1_LowerSat) {
      px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation1'

    // DataTypeConversion: '<S23>/Cast To Double1' incorporates:
    //   Constant: '<S23>/One1'
    //   Gain: '<S23>/Gain1'
    //   Sum: '<S23>/Add1'

    px4demo_uORBRead_B.rtb_Switch_l_idx_0 = floor
      (px4demo_uORBRead_P.Gain1_Gain_f * px4demo_uORBRead_B.numAccum +
       px4demo_uORBRead_P.One1_Value_f);
    if (rtIsNaN(px4demo_uORBRead_B.rtb_Switch_l_idx_0) || rtIsInf
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0)) {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = 0.0;
    } else {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = fmod
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double1'

    px4demo_uORBRead_B.pwmValue[1] = static_cast<uint16_T>
      (px4demo_uORBRead_B.rtb_Switch_l_idx_0 < 0.0 ? static_cast<int32_T>(
        static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-px4demo_uORBRead_B.rtb_Switch_l_idx_0)))) : static_cast<int32_T>(
        static_cast<uint16_T>(px4demo_uORBRead_B.rtb_Switch_l_idx_0)));

    // Gain: '<S54>/Gain'
    px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Gain_Gain_c *
      px4demo_uORBRead_B.rtb_Switch_l_idx_2;

    // Saturate: '<S23>/Saturation2'
    if (px4demo_uORBRead_B.numAccum > px4demo_uORBRead_P.Saturation2_UpperSat) {
      px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Saturation2_UpperSat;
    } else if (px4demo_uORBRead_B.numAccum <
               px4demo_uORBRead_P.Saturation2_LowerSat) {
      px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation2'

    // DataTypeConversion: '<S23>/Cast To Double2' incorporates:
    //   Constant: '<S23>/One2'
    //   Gain: '<S23>/Gain2'
    //   Sum: '<S23>/Add2'

    px4demo_uORBRead_B.rtb_Switch_l_idx_0 = floor(px4demo_uORBRead_P.Gain2_Gain *
      px4demo_uORBRead_B.numAccum + px4demo_uORBRead_P.One2_Value_j);
    if (rtIsNaN(px4demo_uORBRead_B.rtb_Switch_l_idx_0) || rtIsInf
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0)) {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = 0.0;
    } else {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = fmod
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double2'

    px4demo_uORBRead_B.pwmValue[2] = static_cast<uint16_T>
      (px4demo_uORBRead_B.rtb_Switch_l_idx_0 < 0.0 ? static_cast<int32_T>(
        static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-px4demo_uORBRead_B.rtb_Switch_l_idx_0)))) : static_cast<int32_T>(
        static_cast<uint16_T>(px4demo_uORBRead_B.rtb_Switch_l_idx_0)));

    // Gain: '<S55>/Gain'
    px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Gain_Gain_f *
      px4demo_uORBRead_B.rtb_Switch_l_idx_3;

    // Saturate: '<S23>/Saturation3'
    if (px4demo_uORBRead_B.numAccum > px4demo_uORBRead_P.Saturation3_UpperSat) {
      px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Saturation3_UpperSat;
    } else if (px4demo_uORBRead_B.numAccum <
               px4demo_uORBRead_P.Saturation3_LowerSat) {
      px4demo_uORBRead_B.numAccum = px4demo_uORBRead_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation3'

    // DataTypeConversion: '<S23>/Cast To Double3' incorporates:
    //   Constant: '<S23>/One3'
    //   Gain: '<S23>/Gain3'
    //   Sum: '<S23>/Add3'

    px4demo_uORBRead_B.rtb_Switch_l_idx_0 = floor(px4demo_uORBRead_P.Gain3_Gain *
      px4demo_uORBRead_B.numAccum + px4demo_uORBRead_P.One3_Value);
    if (rtIsNaN(px4demo_uORBRead_B.rtb_Switch_l_idx_0) || rtIsInf
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0)) {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = 0.0;
    } else {
      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = fmod
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double3'

    px4demo_uORBRead_B.pwmValue[3] = static_cast<uint16_T>
      (px4demo_uORBRead_B.rtb_Switch_l_idx_0 < 0.0 ? static_cast<int32_T>(
        static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
          (-px4demo_uORBRead_B.rtb_Switch_l_idx_0)))) : static_cast<int32_T>(
        static_cast<uint16_T>(px4demo_uORBRead_B.rtb_Switch_l_idx_0)));

    // Switch: '<S23>/Switch'
    if (rtb_recovery_log) {
      // DataTypeConversion: '<S23>/Cast To Double4' incorporates:
      //   Constant: '<S23>/One5'

      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = floor
        (px4demo_uORBRead_P.One5_Value);
      if (rtIsNaN(px4demo_uORBRead_B.rtb_Switch_l_idx_0) || rtIsInf
          (px4demo_uORBRead_B.rtb_Switch_l_idx_0)) {
        px4demo_uORBRead_B.rtb_Switch_l_idx_0 = 0.0;
      } else {
        px4demo_uORBRead_B.rtb_Switch_l_idx_0 = fmod
          (px4demo_uORBRead_B.rtb_Switch_l_idx_0, 65536.0);
      }

      // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
      //   DataTypeConversion: '<S23>/Cast To Double4'

      px4demo_uORBRead_B.pwmValue[4] = static_cast<uint16_T>
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0 < 0.0 ? static_cast<int32_T>(
          static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
            (-px4demo_uORBRead_B.rtb_Switch_l_idx_0)))) : static_cast<int32_T>(
          static_cast<uint16_T>(px4demo_uORBRead_B.rtb_Switch_l_idx_0)));
    } else {
      // DataTypeConversion: '<S23>/Cast To Double4' incorporates:
      //   Constant: '<S23>/One6'

      px4demo_uORBRead_B.rtb_Switch_l_idx_0 = floor
        (px4demo_uORBRead_P.One6_Value);
      if (rtIsNaN(px4demo_uORBRead_B.rtb_Switch_l_idx_0) || rtIsInf
          (px4demo_uORBRead_B.rtb_Switch_l_idx_0)) {
        px4demo_uORBRead_B.rtb_Switch_l_idx_0 = 0.0;
      } else {
        px4demo_uORBRead_B.rtb_Switch_l_idx_0 = fmod
          (px4demo_uORBRead_B.rtb_Switch_l_idx_0, 65536.0);
      }

      // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
      //   DataTypeConversion: '<S23>/Cast To Double4'

      px4demo_uORBRead_B.pwmValue[4] = static_cast<uint16_T>
        (px4demo_uORBRead_B.rtb_Switch_l_idx_0 < 0.0 ? static_cast<int32_T>(
          static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
            (-px4demo_uORBRead_B.rtb_Switch_l_idx_0)))) : static_cast<int32_T>(
          static_cast<uint16_T>(px4demo_uORBRead_B.rtb_Switch_l_idx_0)));
    }

    // End of Switch: '<S23>/Switch'

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   Constant: '<S23>/One4'
    //   Constant: '<S23>/One7'

    if (px4demo_uORBRead_P.One7_Value_b) {
      if (!px4demo_uORBRead_DW.obj_hi.isArmed) {
        px4demo_uORBRead_DW.obj_hi.isArmed = true;
        status = pwm_arm(&px4demo_uORBRead_DW.obj_hi.pwmDevHandler,
                         &px4demo_uORBRead_DW.obj_hi.armAdvertiseObj);
        px4demo_uORBRead_DW.obj_hi.errorStatus = static_cast<uint16_T>
          (px4demo_uORBRead_DW.obj_hi.errorStatus | status);
      }

      status = pwm_setServo(&px4demo_uORBRead_DW.obj_hi.pwmDevHandler,
                            px4demo_uORBRead_DW.obj_hi.servoCount,
                            px4demo_uORBRead_DW.obj_hi.channelMask,
                            &px4demo_uORBRead_B.pwmValue[0],
                            px4demo_uORBRead_DW.obj_hi.isMain,
                            &px4demo_uORBRead_DW.obj_hi.actuatorAdvertiseObj);
      px4demo_uORBRead_DW.obj_hi.errorStatus = static_cast<uint16_T>
        (px4demo_uORBRead_DW.obj_hi.errorStatus | status);
    } else {
      status = pwm_disarm(&px4demo_uORBRead_DW.obj_hi.pwmDevHandler,
                          &px4demo_uORBRead_DW.obj_hi.armAdvertiseObj);
      px4demo_uORBRead_DW.obj_hi.errorStatus = static_cast<uint16_T>
        (px4demo_uORBRead_DW.obj_hi.errorStatus | status);
      px4demo_uORBRead_DW.obj_hi.isArmed = false;
      status = pwm_resetServo(&px4demo_uORBRead_DW.obj_hi.pwmDevHandler,
        px4demo_uORBRead_DW.obj_hi.servoCount,
        px4demo_uORBRead_DW.obj_hi.channelMask,
        px4demo_uORBRead_DW.obj_hi.isMain,
        &px4demo_uORBRead_DW.obj_hi.actuatorAdvertiseObj);
      px4demo_uORBRead_DW.obj_hi.errorStatus = static_cast<uint16_T>
        (px4demo_uORBRead_DW.obj_hi.errorStatus | status);
    }

    if (px4demo_uORBRead_DW.obj_hi.isMain) {
      status = pwm_forceFailsafe(&px4demo_uORBRead_DW.obj_hi.pwmDevHandler,
        static_cast<int32_T>(px4demo_uORBRead_P.One4_Value));
      px4demo_uORBRead_DW.obj_hi.errorStatus = static_cast<uint16_T>
        (px4demo_uORBRead_DW.obj_hi.errorStatus | status);
    }

    // Update for DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn'
    px4demo_uORBRead_DW.DiscreteTransferFcn_states = px4demo_uORBRead_B.u00Hz;

    // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;

    // Switch: '<S19>/Switch1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Boolean3'

    if (px4demo_uORBRead_B.RateTransition1 != 0) {
      // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
      //   Constant: '<S19>/One1'
      //   DataTypeConversion: '<S19>/Cast To Double36'

      px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
        (px4demo_uORBRead_P.One1_Value != 0.0);
    } else {
      // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
      //   Constant: '<S19>/One2'
      //   DataTypeConversion: '<S19>/Cast To Double36'

      px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
        (px4demo_uORBRead_P.One2_Value != 0.0);
    }

    // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'
    //   Lookup_n-D: '<S26>/1-D Lookup Table4'
    //   Product: '<S25>/Product3'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U = look2_binlcapw(
      static_cast<real_T>(px4demo_uORBRead_B.In1_m.alt), px4demo_uORBRead_B.y,
      px4demo_uORBRead_P.Autopilot.Phi.h_bkpts_m,
      px4demo_uORBRead_P.Autopilot.Phi.V_bkpts_mps,
      px4demo_uORBRead_P.Autopilot.Phi.Ki_phi_vec,
      px4demo_uORBRead_P.uDLookupTable4_maxIndex, 3U) *
      px4demo_uORBRead_B.CastToDouble6;

    // Update for DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'
    px4demo_uORBRead_DW.DiscreteTransferFcn_states_i =
      px4demo_uORBRead_B.rtb_fin_cmd_idx_0;

    // Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S41>/Constant'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_m = 0U;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRe_f = static_cast<int8_T>
      (rtb_NOT);
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_e =
      px4demo_uORBRead_P.Constant_Value_ct;

    // Update for Memory: '<S42>/Memory'
    px4demo_uORBRead_DW.Memory_PreviousInput_a =
      px4demo_uORBRead_DW.Memory_PreviousInput;

    // Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S46>/Constant'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_j = 0U;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRe_i = static_cast<int8_T>
      (rtb_CastToBoolean2);
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_o =
      px4demo_uORBRead_P.Constant_Value_oz;

    // Update for UnitDelay: '<S36>/Delay Input1'
    //
    //  Block description for '<S36>/Delay Input1':
    //
    //   Store in Global RAM

    px4demo_uORBRead_DW.DelayInput1_DSTATE = px4demo_uORBRead_B.cumRevIndex;

    // Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S37>/Constant'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTE_jm = 0U;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevR_ia = static_cast<int8_T>
      (rtb_NOT_h);
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_d =
      px4demo_uORBRead_P.Constant_Value_c;

    // Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S50>/Constant'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_o = 0U;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevR_iv = static_cast<int8_T>
      (rtb_NOT_j);
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_h =
      px4demo_uORBRead_P.Constant_Value_b;
  }

  // End of Outputs for SubSystem: '<S8>/Emulated Pixhawk'

  // RateTransition generated from: '<Root>/Rate Transition2'
  if (px4demo_uORBRead_M->Timing.RateInteraction.TID0_1) {
    memcpy(&px4demo_uORBRead_DW.RateTransition2_4_Buffer[0],
           &px4demo_uORBRead_B.CastToDouble3[0], 10U * sizeof(real_T));
  }

  // MATLABSystem: '<S15>/SourceBlock' incorporates:
  //   Inport: '<S16>/In1'

  rtb_NOT = uORB_read_step(px4demo_uORBRead_DW.obj_g.orbMetadataObj,
    &px4demo_uORBRead_DW.obj_g.eventStructObj,
    &px4demo_uORBRead_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S16>/Enable'

  if (rtb_NOT) {
    px4demo_uORBRead_B.In1_h = px4demo_uORBRead_B.b_varargout_2_b;
  }

  // End of MATLABSystem: '<S15>/SourceBlock'
  // End of Outputs for SubSystem: '<S15>/Enabled Subsystem'

  // RateTransition generated from: '<Root>/Rate Transition2' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Boolean2'
  //   DataTypeConversion: '<Root>/Cast To Double1'
  //   DataTypeConversion: '<Root>/Cast To Double10'
  //   DataTypeConversion: '<Root>/Cast To Double11'
  //   DataTypeConversion: '<Root>/Cast To Double12'
  //   DataTypeConversion: '<Root>/Cast To Double13'
  //   DataTypeConversion: '<Root>/Cast To Double14'
  //   DataTypeConversion: '<Root>/Cast To Double15'
  //   DataTypeConversion: '<Root>/Cast To Double16'
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
  //   DataTypeConversion: '<Root>/Cast To Double3'
  //   DataTypeConversion: '<Root>/Cast To Double30'
  //   DataTypeConversion: '<Root>/Cast To Double31'
  //   DataTypeConversion: '<Root>/Cast To Double4'
  //   DataTypeConversion: '<Root>/Cast To Double5'
  //   DataTypeConversion: '<Root>/Cast To Double6'
  //   DataTypeConversion: '<Root>/Cast To Double7'
  //   DataTypeConversion: '<Root>/Cast To Double8'
  //   DataTypeConversion: '<Root>/Cast To Double9'
  //   Fcn: '<S9>/fcn1'
  //   Fcn: '<S9>/fcn2'
  //   RateTransition: '<Root>/Rate Transition3'
  //   RateTransition: '<Root>/Rate Transition4'
  //   Trigonometry: '<S60>/Trigonometric Function1'
  //   Trigonometry: '<S60>/trigFcn'

  if (px4demo_uORBRead_M->Timing.RateInteraction.TID0_1) {
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[0] =
      px4demo_uORBRead_B.In1.rollspeed;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[1] =
      px4demo_uORBRead_B.In1.pitchspeed;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[2] =
      px4demo_uORBRead_B.In1.yawspeed;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[3] = rt_atan2d_snf
      ((px4demo_uORBRead_B.t * px4demo_uORBRead_B.CastToDouble18 +
        px4demo_uORBRead_B.absxk * px4demo_uORBRead_B.scale) * 2.0,
       ((px4demo_uORBRead_B.rtb_VectorConcatenate_idx_2_tmp +
         rtb_VectorConcatenate_idx_2_tmp) - rtb_VectorConcatenate_idx_2_t_0) -
       rtb_VectorConcatenate_idx_2_t_1);

    // Trigonometry: '<S60>/trigFcn' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double14'
    //   DataTypeConversion: '<Root>/Cast To Double15'
    //   DataTypeConversion: '<Root>/Cast To Double16'
    //   Fcn: '<S9>/fcn1'
    //   Fcn: '<S9>/fcn2'
    //   Trigonometry: '<S60>/Trigonometric Function1'

    if (px4demo_uORBRead_B.fcn3 > 1.0) {
      px4demo_uORBRead_B.fcn3 = 1.0;
    } else if (px4demo_uORBRead_B.fcn3 < -1.0) {
      px4demo_uORBRead_B.fcn3 = -1.0;
    }

    px4demo_uORBRead_DW.RateTransition2_2_Buffer[4] = asin
      (px4demo_uORBRead_B.fcn3);
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[5] =
      px4demo_uORBRead_B.rtb_VectorConcatenate_idx_2;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[6] = px4demo_uORBRead_B.In1_k.x;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[7] = px4demo_uORBRead_B.In1_k.y;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[8] = px4demo_uORBRead_B.In1_k.z;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[9] = px4demo_uORBRead_B.In1_h.x;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[10] =
      px4demo_uORBRead_B.In1_h.y;
    px4demo_uORBRead_DW.RateTransition2_2_Buffer[11] =
      px4demo_uORBRead_B.In1_h.z;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[0] =
      px4demo_uORBRead_B.In1_p.ax;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[1] =
      px4demo_uORBRead_B.In1_p.ay;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[2] =
      px4demo_uORBRead_B.In1_p.az;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[3] = px4demo_uORBRead_B.In1_p.z;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[4] = px4demo_uORBRead_B.In1_p.x;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[5] = px4demo_uORBRead_B.In1_p.y;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[6] =
      px4demo_uORBRead_B.In1_p.vx;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[7] =
      px4demo_uORBRead_B.In1_p.vy;
    px4demo_uORBRead_DW.RateTransition2_3_Buffer[8] =
      px4demo_uORBRead_B.In1_p.vz;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[0] =
      px4demo_uORBRead_B.In1_m.lat;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[1] =
      px4demo_uORBRead_B.In1_m.lon;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[2] =
      px4demo_uORBRead_B.In1_m.alt;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[3] =
      px4demo_uORBRead_B.In1_m.fix_type;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[4] =
      px4demo_uORBRead_B.In1_m.satellites_used;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[5] =
      px4demo_uORBRead_B.In1_m.vel_m_s;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[6] =
      px4demo_uORBRead_B.In1_m.vel_n_m_s;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[7] =
      px4demo_uORBRead_B.In1_m.vel_e_m_s;
    px4demo_uORBRead_DW.RateTransition2_1_Buffer[8] =
      px4demo_uORBRead_B.In1_m.vel_d_m_s;
    px4demo_uORBRead_DW.RateTransition4_Buffer =
      (px4demo_uORBRead_DW.RateTransition3_Buffer0 != 0.0F);
  }

  // Update absolute time
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.005, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  px4demo_uORBRead_M->Timing.clockTick0++;
}

// Model step function for TID1
void px4demo_uORBRead_step1(void)      // Sample time: [1.0s, 0.0s]
{
  uint64_t timestamp;
  uint8_T elem_type;
  static const char_T mlStrVer[5] = { 'M', 'W', 'L', 'O', 'G' };

  MW_PARAM_DATA_TYPE ParamDataType;
  int32_T ParamStep;
  int32_T rtb_ReadParameter2_o1;
  real32_T rtb_DataTypeConversion2;
  real32_T rtb_DataTypeConversion3;
  uint32_T tm;
  uint32_T tmptr;
  uint16_T recSize;
  char_T d[3];
  boolean_T b_varargout_2;
  static const char_T g[24] = "/fs/microsd/log/pwm.bin";
  static const char_T f[28] = "CLOSING file. count = %d %c";
  static const char_T i[56] =
    "OPENING file %s vect_size %d elem_size %d numRecs %d %c";

  // MATLABSystem: '<Root>/Read Parameter'
  if (px4demo_uORBRead_DW.obj_p.SampleTime !=
      px4demo_uORBRead_P.ReadParameter_SampleTime) {
    px4demo_uORBRead_DW.obj_p.SampleTime =
      px4demo_uORBRead_P.ReadParameter_SampleTime;
  }

  ParamDataType = MW_INT32;
  b_varargout_2 = MW_Param_Step(px4demo_uORBRead_DW.obj_p.MW_PARAMHANDLE,
    ParamDataType, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0;
  }

  // DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
  //   MATLABSystem: '<Root>/Read Parameter'

  rtb_DataTypeConversion3 = static_cast<real32_T>(ParamStep);

  // MATLABSystem: '<Root>/Read Parameter1'
  if (px4demo_uORBRead_DW.obj_i.SampleTime !=
      px4demo_uORBRead_P.ReadParameter1_SampleTime) {
    px4demo_uORBRead_DW.obj_i.SampleTime =
      px4demo_uORBRead_P.ReadParameter1_SampleTime;
  }

  ParamDataType = MW_INT32;
  b_varargout_2 = MW_Param_Step(px4demo_uORBRead_DW.obj_i.MW_PARAMHANDLE,
    ParamDataType, &ParamStep);
  if (b_varargout_2) {
    ParamStep = 0;
  }

  // DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
  //   MATLABSystem: '<Root>/Read Parameter1'

  rtb_DataTypeConversion2 = static_cast<real32_T>(ParamStep);

  // MATLABSystem: '<Root>/Read Parameter2'
  if (px4demo_uORBRead_DW.obj_h.SampleTime !=
      px4demo_uORBRead_P.ReadParameter2_SampleTime) {
    px4demo_uORBRead_DW.obj_h.SampleTime =
      px4demo_uORBRead_P.ReadParameter2_SampleTime;
  }

  ParamDataType = MW_INT32;
  b_varargout_2 = MW_Param_Step(px4demo_uORBRead_DW.obj_h.MW_PARAMHANDLE,
    ParamDataType, &rtb_ReadParameter2_o1);
  if (b_varargout_2) {
    rtb_ReadParameter2_o1 = 0;
  }

  // End of MATLABSystem: '<Root>/Read Parameter2'

  // BusAssignment: '<Root>/Bus Assignment1' incorporates:
  //   Constant: '<S4>/Constant'
  //   DataTypeConversion: '<Root>/Data Type Conversion4'

  px4demo_uORBRead_B.BusAssignment1 = px4demo_uORBRead_P.Constant_Value_k;
  px4demo_uORBRead_B.BusAssignment1.x = rtb_DataTypeConversion3;
  px4demo_uORBRead_B.BusAssignment1.y = rtb_DataTypeConversion2;
  px4demo_uORBRead_B.BusAssignment1.z = static_cast<real32_T>
    (rtb_ReadParameter2_o1);

  // MATLABSystem: '<S7>/SinkBlock' incorporates:
  //   BusAssignment: '<Root>/Bus Assignment1'

  uORB_write_step(px4demo_uORBRead_DW.obj_e.orbMetadataObj,
                  &px4demo_uORBRead_DW.obj_e.orbAdvertiseObj,
                  &px4demo_uORBRead_B.BusAssignment1);

  // RateTransition: '<Root>/Rate Transition1'
  px4demo_uORBRead_DW.RateTransition1_Buffer0 = rtb_ReadParameter2_o1;

  // RateTransition: '<Root>/Rate Transition'
  px4demo_uORBRead_DW.RateTransition_Buffer0 = rtb_DataTypeConversion2;

  // RateTransition: '<Root>/Rate Transition3'
  px4demo_uORBRead_DW.RateTransition3_Buffer0 = rtb_DataTypeConversion3;

  // SignalConversion generated from: '<S69>/ SFunction ' incorporates:
  //   MATLAB Function: '<S68>/SDCard_logger'
  //   RateTransition generated from: '<Root>/Rate Transition2'

  memcpy(&px4demo_uORBRead_B.TmpSignalConversionAtSFunct[0],
         &px4demo_uORBRead_DW.RateTransition2_1_Buffer[0], 9U * sizeof(real_T));
  memcpy(&px4demo_uORBRead_B.TmpSignalConversionAtSFunct[9],
         &px4demo_uORBRead_DW.RateTransition2_2_Buffer[0], 12U * sizeof(real_T));
  memcpy(&px4demo_uORBRead_B.TmpSignalConversionAtSFunct[21],
         &px4demo_uORBRead_DW.RateTransition2_3_Buffer[0], 9U * sizeof(real_T));
  memcpy(&px4demo_uORBRead_B.TmpSignalConversionAtSFunct[30],
         &px4demo_uORBRead_DW.RateTransition2_4_Buffer[0], 10U * sizeof(real_T));

  // MATLAB Function: '<S68>/SDCard_logger' incorporates:
  //   RateTransition: '<Root>/Rate Transition4'

  timestamp = hrt_absolute_time();
  if (!px4demo_uORBRead_DW.count_not_empty) {
    px4demo_uORBRead_DW.count_not_empty = true;
    elem_type = 1U;
    px4demo_uORBRead_DW.vect_size = 40U;
    for (ParamStep = 0; ParamStep < 56; ParamStep++) {
      px4demo_uORBRead_B.b[ParamStep] = i[ParamStep];
    }

    for (ParamStep = 0; ParamStep < 24; ParamStep++) {
      px4demo_uORBRead_B.c[ParamStep] = g[ParamStep];
    }

    printf(&px4demo_uORBRead_B.b[0], &px4demo_uORBRead_B.c[0],
           static_cast<uint32_T>(px4demo_uORBRead_DW.vect_size),
           static_cast<uint32_T>(px4demo_uORBRead_DW.elem_size), 276447232U, 10);
    for (ParamStep = 0; ParamStep < 24; ParamStep++) {
      px4demo_uORBRead_B.c[ParamStep] = g[ParamStep];
    }

    d[0] = 'w';
    d[1] = 'b';
    d[2] = '\x00';
    px4demo_uORBRead_DW.fp = fopen(&px4demo_uORBRead_B.c[0], &d[0]);
    fwrite(&mlStrVer[0], 1U, 5.0, px4demo_uORBRead_DW.fp);
    tm = time(&tmptr);
    fwrite(&tm, 4U, 1U, px4demo_uORBRead_DW.fp);
    fwrite(&px4demo_uORBRead_DW.vect_size, 1U, 1U, px4demo_uORBRead_DW.fp);
    fwrite(&elem_type, 1U, 1U, px4demo_uORBRead_DW.fp);
    tmptr = static_cast<uint32_T>(px4demo_uORBRead_DW.elem_size) *
      px4demo_uORBRead_DW.vect_size;
    if (tmptr > 65535U) {
      tmptr = 65535U;
    }

    recSize = static_cast<uint16_T>(tmptr);
    fwrite(&recSize, 2U, 1U, px4demo_uORBRead_DW.fp);
  }

  if (px4demo_uORBRead_DW.RateTransition4_Buffer && (px4demo_uORBRead_DW.count <
       276447232U)) {
    if (!px4demo_uORBRead_DW.isopen) {
      for (ParamStep = 0; ParamStep < 24; ParamStep++) {
        px4demo_uORBRead_B.c[ParamStep] = g[ParamStep];
      }

      d[0] = 'a';
      d[1] = 'b';
      d[2] = '\x00';
      px4demo_uORBRead_DW.fp = fopen(&px4demo_uORBRead_B.c[0], &d[0]);
      px4demo_uORBRead_DW.isflushed = false;
      px4demo_uORBRead_DW.isopen = true;
    }

    fwrite(&px4demo_uORBRead_B.TmpSignalConversionAtSFunct[0],
           px4demo_uORBRead_DW.elem_size, px4demo_uORBRead_DW.vect_size,
           px4demo_uORBRead_DW.fp);
    fwrite(&timestamp, 8U, 1U, px4demo_uORBRead_DW.fp);
    tmptr = px4demo_uORBRead_DW.count + /*MW:OvSatOk*/ 1U;
    if (px4demo_uORBRead_DW.count + 1U < px4demo_uORBRead_DW.count) {
      tmptr = MAX_uint32_T;
    }

    px4demo_uORBRead_DW.count = tmptr;
  } else {
    if (px4demo_uORBRead_DW.isopen) {
      if (!px4demo_uORBRead_DW.isflushed) {
        for (ParamStep = 0; ParamStep < 28; ParamStep++) {
          px4demo_uORBRead_B.e[ParamStep] = f[ParamStep];
        }

        printf(&px4demo_uORBRead_B.e[0], px4demo_uORBRead_DW.count, 10);
        fflush(px4demo_uORBRead_DW.fp);
        px4demo_uORBRead_DW.isflushed = true;
      }

      fclose(px4demo_uORBRead_DW.fp);
    }

    px4demo_uORBRead_DW.isopen = false;
  }
}

// Model wrapper function for compatibility with a static main program
void px4demo_uORBRead_step(int_T tid)
{
  switch (tid) {
   case 0 :
    px4demo_uORBRead_step0();
    break;

   case 1 :
    px4demo_uORBRead_step1();
    break;

   default :
    break;
  }
}

// Model initialize function
void px4demo_uORBRead_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // block I/O
  (void) memset((static_cast<void *>(&px4demo_uORBRead_B)), 0,
                sizeof(B_px4demo_uORBRead_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&px4demo_uORBRead_DW), 0,
                sizeof(DW_px4demo_uORBRead_T));

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
    px4demo_uORBRead_B.RateTransition =
      px4demo_uORBRead_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<Root>/Rate Transition1'
    px4demo_uORBRead_B.RateTransition1 =
      px4demo_uORBRead_P.RateTransition1_InitialConditio;

    // Start for DiscretePulseGenerator: '<S8>/100 Hz'
    px4demo_uORBRead_DW.clockTickCounter = 0;
    px4demo_uORBRead_PrevZCX.EmulatedPixhawk_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    px4demo_uORBRead_DW.RateTransition_Buffer0 =
      px4demo_uORBRead_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition1'
    px4demo_uORBRead_DW.RateTransition1_Buffer0 =
      px4demo_uORBRead_P.RateTransition1_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition3'
    px4demo_uORBRead_DW.RateTransition3_Buffer0 =
      px4demo_uORBRead_P.RateTransition3_InitialConditio;

    // SystemInitialize for MATLAB Function: '<S68>/SDCard_logger'
    px4demo_uORBRead_DW.count_not_empty = false;
    px4demo_uORBRead_DW.count = 0U;
    px4demo_uORBRead_DW.isflushed = false;
    px4demo_uORBRead_DW.elem_size = 8U;
    px4demo_uORBRead_DW.isopen = true;

    // SystemInitialize for Enabled SubSystem: '<S13>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S14>/Out1' incorporates:
    //   Inport: '<S14>/In1'

    px4demo_uORBRead_B.In1_k = px4demo_uORBRead_P.Out1_Y0_hh;

    // End of SystemInitialize for SubSystem: '<S13>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S16>/Out1' incorporates:
    //   Inport: '<S16>/In1'

    px4demo_uORBRead_B.In1_h = px4demo_uORBRead_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S17>/Out1' incorporates:
    //   Inport: '<S17>/In1'

    px4demo_uORBRead_B.In1_m = px4demo_uORBRead_P.Out1_Y0_hz;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S18>/Out1' incorporates:
    //   Inport: '<S18>/In1'

    px4demo_uORBRead_B.In1_p = px4demo_uORBRead_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Triggered SubSystem: '<S8>/Emulated Pixhawk'
    // InitializeConditions for DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' 
    px4demo_uORBRead_DW.DiscreteTransferFcn_states =
      px4demo_uORBRead_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S25>/Constant'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTAT_kw =
      px4demo_uORBRead_P.Constant_Value_oa;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRese = 0;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U = 0.0;

    // InitializeConditions for DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' 
    px4demo_uORBRead_DW.DiscreteTransferFcn_states_i =
      px4demo_uORBRead_P.DiscreteTransferFcn_InitialSt_g;

    // InitializeConditions for Switch: '<S42>/Switch1' incorporates:
    //   Memory: '<S30>/Memory'

    px4demo_uORBRead_DW.Memory_PreviousInput =
      px4demo_uORBRead_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S41>/Constant1'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE =
      px4demo_uORBRead_P.Constant1_Value_p;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRe_f = 0;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_e = 0.0;

    // InitializeConditions for Memory: '<S42>/Memory'
    px4demo_uORBRead_DW.Memory_PreviousInput_a =
      px4demo_uORBRead_P.Memory_InitialCondition_d;

    // InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S46>/Constant1'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_c =
      px4demo_uORBRead_P.Constant1_Value_m;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevRe_i = 0;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_o = 0.0;

    // InitializeConditions for Switch: '<S47>/Switch1' incorporates:
    //   Memory: '<S47>/Memory'

    px4demo_uORBRead_DW.Memory_PreviousInput_o =
      px4demo_uORBRead_P.Memory_InitialCondition_b;

    // InitializeConditions for UnitDelay: '<S36>/Delay Input1'
    //
    //  Block description for '<S36>/Delay Input1':
    //
    //   Store in Global RAM

    px4demo_uORBRead_DW.DelayInput1_DSTATE =
      px4demo_uORBRead_P.DetectDecrease_vinit;

    // InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S37>/Constant1'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_b =
      px4demo_uORBRead_P.Constant1_Value_i;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevR_ia = 0;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_d = 0.0;

    // InitializeConditions for Switch: '<S38>/Switch1' incorporates:
    //   Memory: '<S38>/Memory'

    px4demo_uORBRead_DW.Memory_PreviousInput_d =
      px4demo_uORBRead_P.Memory_InitialCondition_o;

    // InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S50>/Constant1'

    px4demo_uORBRead_DW.DiscreteTimeIntegrator_DSTATE_k =
      px4demo_uORBRead_P.Constant1_Value_k;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PrevR_iv = 0;
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_PREV_U_h = 0.0;

    // InitializeConditions for Switch: '<S51>/Switch1' incorporates:
    //   Memory: '<S51>/Memory'

    px4demo_uORBRead_DW.Memory_PreviousInput_b =
      px4demo_uORBRead_P.Memory_InitialCondition_m;

    // Start for MATLABSystem: '<S28>/Moving Average1'
    px4demo_uORBRead_DW.obj.matlabCodegenIsDeleted = true;
    px4demo_uORBRead_DW.obj.isInitialized = 0;
    px4demo_uORBRead_DW.obj.NumChannels = -1;
    px4demo_uORBRead_DW.obj.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj.isSetupComplete = false;
    px4demo_uORBRead_DW.obj.isInitialized = 1;
    px4demo_uORBRead_DW.obj.NumChannels = 1;
    px4demo_uORBRead_DW.obj._pobj0.isInitialized = 0;
    px4demo_uORBRead_DW.obj.pStatistic = &px4demo_uORBRead_DW.obj._pobj0;
    px4demo_uORBRead_DW.obj.isSetupComplete = true;
    px4demo_uORBRead_DW.obj.TunablePropsChanged = false;

    // InitializeConditions for MATLABSystem: '<S28>/Moving Average1'
    obj_0 = px4demo_uORBRead_DW.obj.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (i = 0; i < 9; i++) {
        obj_0->pCumSumRev[i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
    }

    // End of InitializeConditions for MATLABSystem: '<S28>/Moving Average1'

    // Start for MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   Constant: '<S23>/One4'
    //   Constant: '<S23>/One7'

    px4demo_uORBRead_DW.obj_hi.errorStatus = 0U;
    px4demo_uORBRead_DW.obj_hi.isInitialized = 0;
    px4demo_uORBRead_DW.obj_hi.matlabCodegenIsDeleted = false;
    px4demo_uORBRe_SystemCore_setup(&px4demo_uORBRead_DW.obj_hi,
      px4demo_uORBRead_P.One7_Value_b, px4demo_uORBRead_P.One4_Value);
    for (i = 0; i < 10; i++) {
      // SystemInitialize for DataTypeConversion: '<S19>/Cast To Double3' incorporates:
      //   Outport: '<S19>/Pix_Out'

      px4demo_uORBRead_B.CastToDouble3[i] = px4demo_uORBRead_P.Pix_Out_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S8>/Emulated Pixhawk'

    // SystemInitialize for Enabled SubSystem: '<S72>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S73>/Out1' incorporates:
    //   Inport: '<S73>/In1'

    px4demo_uORBRead_B.In1 = px4demo_uORBRead_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S72>/Enabled Subsystem'

    // Start for MATLABSystem: '<S71>/SinkBlock' incorporates:
    //   BusAssignment: '<S11>/Bus Assignment'

    px4demo_uORBRead_DW.obj_o.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_o.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_o.isInitialized = 1;
    px4demo_uORBRead_DW.obj_o.orbMetadataObj = ORB_ID(mavlink_log);
    uORB_write_initialize(px4demo_uORBRead_DW.obj_o.orbMetadataObj,
                          &px4demo_uORBRead_DW.obj_o.orbAdvertiseObj,
                          &px4demo_uORBRead_B.BusAssignment_k, 1);
    px4demo_uORBRead_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S13>/SourceBlock'
    px4demo_uORBRead_DW.obj_n.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_n.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_n.isInitialized = 1;
    px4demo_uORBRead_DW.obj_n.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(px4demo_uORBRead_DW.obj_n.orbMetadataObj,
                         &px4demo_uORBRead_DW.obj_n.eventStructObj);
    px4demo_uORBRead_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S72>/SourceBlock'
    px4demo_uORBRead_DW.obj_ph.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_ph.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_ph.isInitialized = 1;
    px4demo_uORBRead_DW.obj_ph.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(px4demo_uORBRead_DW.obj_ph.orbMetadataObj,
                         &px4demo_uORBRead_DW.obj_ph.eventStructObj);
    px4demo_uORBRead_DW.obj_ph.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/SourceBlock'
    px4demo_uORBRead_DW.obj_hy.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_hy.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_hy.isInitialized = 1;
    px4demo_uORBRead_DW.obj_hy.orbMetadataObj = ORB_ID(vehicle_local_position);
    uORB_read_initialize(px4demo_uORBRead_DW.obj_hy.orbMetadataObj,
                         &px4demo_uORBRead_DW.obj_hy.eventStructObj);
    px4demo_uORBRead_DW.obj_hy.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/SourceBlock'
    px4demo_uORBRead_DW.obj_j.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_j.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_j.isInitialized = 1;
    px4demo_uORBRead_DW.obj_j.orbMetadataObj = ORB_ID(vehicle_gps_position);
    uORB_read_initialize(px4demo_uORBRead_DW.obj_j.orbMetadataObj,
                         &px4demo_uORBRead_DW.obj_j.eventStructObj);
    px4demo_uORBRead_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S15>/SourceBlock'
    px4demo_uORBRead_DW.obj_g.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_g.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_g.isInitialized = 1;
    px4demo_uORBRead_DW.obj_g.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(px4demo_uORBRead_DW.obj_g.orbMetadataObj,
                         &px4demo_uORBRead_DW.obj_g.eventStructObj);
    px4demo_uORBRead_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Read Parameter'
    px4demo_uORBRead_DW.obj_p.matlabCodegenIsDeleted = true;
    px4demo_uORBRead_DW.obj_p.isInitialized = 0;
    px4demo_uORBRead_DW.obj_p.SampleTime = -1.0;
    px4demo_uORBRead_DW.obj_p.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_p.SampleTime =
      px4demo_uORBRead_P.ReadParameter_SampleTime;
    obj = &px4demo_uORBRead_DW.obj_p;
    px4demo_uORBRead_DW.obj_p.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      ParameterNameStr[i] = tmp[i];
    }

    ParameterNameStr[12] = '\x00';
    if (px4demo_uORBRead_DW.obj_p.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = px4demo_uORBRead_DW.obj_p.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, sts * 1000.0);
    px4demo_uORBRead_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter'

    // Start for MATLABSystem: '<Root>/Read Parameter1'
    px4demo_uORBRead_DW.obj_i.matlabCodegenIsDeleted = true;
    px4demo_uORBRead_DW.obj_i.isInitialized = 0;
    px4demo_uORBRead_DW.obj_i.SampleTime = -1.0;
    px4demo_uORBRead_DW.obj_i.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_i.SampleTime =
      px4demo_uORBRead_P.ReadParameter1_SampleTime;
    obj = &px4demo_uORBRead_DW.obj_i;
    px4demo_uORBRead_DW.obj_i.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      ParameterNameStr_0[i] = tmp_0[i];
    }

    ParameterNameStr_0[14] = '\x00';
    if (px4demo_uORBRead_DW.obj_i.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = px4demo_uORBRead_DW.obj_i.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0], true, sts *
      1000.0);
    px4demo_uORBRead_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter1'

    // Start for MATLABSystem: '<Root>/Read Parameter2'
    px4demo_uORBRead_DW.obj_h.matlabCodegenIsDeleted = true;
    px4demo_uORBRead_DW.obj_h.isInitialized = 0;
    px4demo_uORBRead_DW.obj_h.SampleTime = -1.0;
    px4demo_uORBRead_DW.obj_h.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_h.SampleTime =
      px4demo_uORBRead_P.ReadParameter2_SampleTime;
    obj = &px4demo_uORBRead_DW.obj_h;
    px4demo_uORBRead_DW.obj_h.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      px4demo_uORBRead_B.ParameterNameStr[i] = tmp_1[i];
    }

    px4demo_uORBRead_B.ParameterNameStr[16] = '\x00';
    if (px4demo_uORBRead_DW.obj_h.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = px4demo_uORBRead_DW.obj_h.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param(&px4demo_uORBRead_B.ParameterNameStr[0],
      true, sts * 1000.0);
    px4demo_uORBRead_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter2'

    // Start for MATLABSystem: '<S7>/SinkBlock' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment1'

    px4demo_uORBRead_DW.obj_e.matlabCodegenIsDeleted = false;
    px4demo_uORBRead_DW.obj_e.isSetupComplete = false;
    px4demo_uORBRead_DW.obj_e.isInitialized = 1;
    px4demo_uORBRead_DW.obj_e.orbMetadataObj = ORB_ID(debug_vect);
    uORB_write_initialize(px4demo_uORBRead_DW.obj_e.orbMetadataObj,
                          &px4demo_uORBRead_DW.obj_e.orbAdvertiseObj,
                          &px4demo_uORBRead_B.BusAssignment1_p, 1);
    px4demo_uORBRead_DW.obj_e.isSetupComplete = true;

    // Enable for Triggered SubSystem: '<S8>/Emulated Pixhawk'
    px4demo_uORBRead_DW.EmulatedPixhawk_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

    // Enable for DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_m = 1U;

    // Enable for DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_j = 1U;

    // Enable for DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTE_jm = 1U;

    // Enable for DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
    px4demo_uORBRead_DW.DiscreteTimeIntegrator_SYSTEM_o = 1U;

    // End of Enable for SubSystem: '<S8>/Emulated Pixhawk'
  }
}

// Model terminate function
void px4demo_uORBRead_terminate(void)
{
  g_dsp_private_SlidingWindowAv_T *obj;
  uint16_T status;

  // Terminate for MATLABSystem: '<S71>/SinkBlock'
  if (!px4demo_uORBRead_DW.obj_o.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj_o.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj_o.isSetupComplete) {
      uORB_write_terminate(&px4demo_uORBRead_DW.obj_o.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S71>/SinkBlock'

  // Terminate for MATLABSystem: '<S13>/SourceBlock'
  if (!px4demo_uORBRead_DW.obj_n.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj_n.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&px4demo_uORBRead_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S13>/SourceBlock'

  // Terminate for MATLABSystem: '<S72>/SourceBlock'
  if (!px4demo_uORBRead_DW.obj_ph.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_ph.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj_ph.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj_ph.isSetupComplete) {
      uORB_read_terminate(&px4demo_uORBRead_DW.obj_ph.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S72>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!px4demo_uORBRead_DW.obj_hy.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_hy.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj_hy.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj_hy.isSetupComplete) {
      uORB_read_terminate(&px4demo_uORBRead_DW.obj_hy.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!px4demo_uORBRead_DW.obj_j.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj_j.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&px4demo_uORBRead_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for Triggered SubSystem: '<S8>/Emulated Pixhawk'
  // Terminate for MATLABSystem: '<S28>/Moving Average1'
  if (!px4demo_uORBRead_DW.obj.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj.isSetupComplete) {
      obj = px4demo_uORBRead_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      px4demo_uORBRead_DW.obj.NumChannels = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S28>/Moving Average1'

  // Terminate for MATLABSystem: '<S23>/PX4 PWM Output1'
  if (!px4demo_uORBRead_DW.obj_hi.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_hi.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj_hi.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj_hi.isSetupComplete) {
      status = pwm_disarm(&px4demo_uORBRead_DW.obj_hi.pwmDevHandler,
                          &px4demo_uORBRead_DW.obj_hi.armAdvertiseObj);
      px4demo_uORBRead_DW.obj_hi.errorStatus = static_cast<uint16_T>
        (px4demo_uORBRead_DW.obj_hi.errorStatus | status);
      status = pwm_resetServo(&px4demo_uORBRead_DW.obj_hi.pwmDevHandler,
        px4demo_uORBRead_DW.obj_hi.servoCount,
        px4demo_uORBRead_DW.obj_hi.channelMask,
        px4demo_uORBRead_DW.obj_hi.isMain,
        &px4demo_uORBRead_DW.obj_hi.actuatorAdvertiseObj);
      px4demo_uORBRead_DW.obj_hi.errorStatus = static_cast<uint16_T>
        (px4demo_uORBRead_DW.obj_hi.errorStatus | status);
      status = pwm_close(&px4demo_uORBRead_DW.obj_hi.pwmDevHandler,
                         &px4demo_uORBRead_DW.obj_hi.actuatorAdvertiseObj,
                         &px4demo_uORBRead_DW.obj_hi.armAdvertiseObj);
      px4demo_uORBRead_DW.obj_hi.errorStatus = static_cast<uint16_T>
        (px4demo_uORBRead_DW.obj_hi.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S23>/PX4 PWM Output1'
  // End of Terminate for SubSystem: '<S8>/Emulated Pixhawk'

  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  if (!px4demo_uORBRead_DW.obj_g.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj_g.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj_g.isSetupComplete) {
      uORB_read_terminate(&px4demo_uORBRead_DW.obj_g.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S15>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/Read Parameter'
  if (!px4demo_uORBRead_DW.obj_p.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter'

  // Terminate for MATLABSystem: '<Root>/Read Parameter1'
  if (!px4demo_uORBRead_DW.obj_i.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter1'

  // Terminate for MATLABSystem: '<Root>/Read Parameter2'
  if (!px4demo_uORBRead_DW.obj_h.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter2'

  // Terminate for MATLABSystem: '<S7>/SinkBlock'
  if (!px4demo_uORBRead_DW.obj_e.matlabCodegenIsDeleted) {
    px4demo_uORBRead_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((px4demo_uORBRead_DW.obj_e.isInitialized == 1) &&
        px4demo_uORBRead_DW.obj_e.isSetupComplete) {
      uORB_write_terminate(&px4demo_uORBRead_DW.obj_e.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
