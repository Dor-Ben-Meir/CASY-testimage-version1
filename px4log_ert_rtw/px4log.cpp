//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4log.cpp
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
#include "px4log.h"
#include "px4log_private.h"

// Block signals (default storage)
B_px4log_T px4log_B;

// Block states (default storage)
DW_px4log_T px4log_DW;

// Previous zero-crossings (trigger) states
PrevZCX_px4log_T px4log_PrevZCX;

// Real-time model
RT_MODEL_px4log_T px4log_M_ = RT_MODEL_px4log_T();
RT_MODEL_px4log_T *const px4log_M = &px4log_M_;

// Forward declaration for local functions
static void px4log_SystemCore_setup(px4_internal_block_PWM_px4log_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
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

static void px4log_SystemCore_setup(px4_internal_block_PWM_px4log_T *obj,
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
  obj->channelMask = 15;
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
void px4log_step(void)
{
  real_T rtb_Product1;
  real_T rtb_Product2_o;
  real_T rtb_u00Hz;
  real_T t;
  int32_T i;
  real32_T rtb_Subtract;
  uint32_T Subsystem_ELAPS_T;
  uint16_T status;
  boolean_T rtb_GreaterThan;
  ZCEventType zcEvent;

  // DiscretePulseGenerator: '<Root>/100 Hz'
  rtb_u00Hz = (px4log_DW.clockTickCounter < px4log_P.u00Hz_Duty) &&
    (px4log_DW.clockTickCounter >= 0) ? px4log_P.u00Hz_Amp : 0.0;
  if (px4log_DW.clockTickCounter >= px4log_P.u00Hz_Period - 1.0) {
    px4log_DW.clockTickCounter = 0;
  } else {
    px4log_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<Root>/100 Hz'

  // Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
  //   TriggerPort: '<S1>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&px4log_PrevZCX.Subsystem_Trig_ZCE,
                     (rtb_u00Hz));
  if (zcEvent != NO_ZCEVENT) {
    if (px4log_DW.Subsystem_RESET_ELAPS_T) {
      Subsystem_ELAPS_T = 0U;
    } else {
      Subsystem_ELAPS_T = px4log_M->Timing.clockTick0 -
        px4log_DW.Subsystem_PREV_T;
    }

    px4log_DW.Subsystem_PREV_T = px4log_M->Timing.clockTick0;
    px4log_DW.Subsystem_RESET_ELAPS_T = false;

    // MATLABSystem: '<S6>/SourceBlock' incorporates:
    //   Inport: '<S18>/In1'

    rtb_GreaterThan = uORB_read_step(px4log_DW.obj_f.orbMetadataObj,
      &px4log_DW.obj_f.eventStructObj, &px4log_B.b_varargout_2_m, false, 1.0);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S18>/Enable'

    if (rtb_GreaterThan) {
      px4log_B.In1_p = px4log_B.b_varargout_2_m;
    }

    // End of MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

    // MATLAB Function: '<S1>/MATLAB Function' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double29'
    //   DataTypeConversion: '<S1>/Cast To Double30'
    //   DataTypeConversion: '<S1>/Cast To Double31'

    px4log_B.scale = 3.3121686421112381E-170;
    px4log_B.absxk = fabs(static_cast<real_T>(px4log_B.In1_p.vx));
    if (px4log_B.absxk > 3.3121686421112381E-170) {
      rtb_u00Hz = 1.0;
      px4log_B.scale = px4log_B.absxk;
    } else {
      t = px4log_B.absxk / 3.3121686421112381E-170;
      rtb_u00Hz = t * t;
    }

    px4log_B.absxk = fabs(static_cast<real_T>(px4log_B.In1_p.vy));
    if (px4log_B.absxk > px4log_B.scale) {
      t = px4log_B.scale / px4log_B.absxk;
      rtb_u00Hz = rtb_u00Hz * t * t + 1.0;
      px4log_B.scale = px4log_B.absxk;
    } else {
      t = px4log_B.absxk / px4log_B.scale;
      rtb_u00Hz += t * t;
    }

    px4log_B.absxk = fabs(static_cast<real_T>(px4log_B.In1_p.vz));
    if (px4log_B.absxk > px4log_B.scale) {
      t = px4log_B.scale / px4log_B.absxk;
      rtb_u00Hz = rtb_u00Hz * t * t + 1.0;
      px4log_B.scale = px4log_B.absxk;
    } else {
      t = px4log_B.absxk / px4log_B.scale;
      rtb_u00Hz += t * t;
    }

    rtb_u00Hz = px4log_B.scale * sqrt(rtb_u00Hz);

    // End of MATLAB Function: '<S1>/MATLAB Function'

    // MATLABSystem: '<S7>/SourceBlock' incorporates:
    //   Inport: '<S19>/In1'

    rtb_GreaterThan = uORB_read_step(px4log_DW.obj_g.orbMetadataObj,
      &px4log_DW.obj_g.eventStructObj, &px4log_B.b_varargout_2_c, false, 1.0);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S19>/Enable'

    if (rtb_GreaterThan) {
      px4log_B.In1_c = px4log_B.b_varargout_2_c;
    }

    // End of MATLABSystem: '<S7>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

    // MATLABSystem: '<S40>/SourceBlock' incorporates:
    //   Inport: '<S41>/In1'

    rtb_GreaterThan = uORB_read_step(px4log_DW.obj.orbMetadataObj,
      &px4log_DW.obj.eventStructObj, &px4log_B.b_varargout_2, false, 1.0);

    // Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S41>/Enable'

    if (rtb_GreaterThan) {
      px4log_B.In1 = px4log_B.b_varargout_2;
    }

    // End of MATLABSystem: '<S40>/SourceBlock'
    // End of Outputs for SubSystem: '<S40>/Enabled Subsystem'

    // DiscreteTransferFcn: '<S21>/Discrete Transfer Fcn' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double16'

    px4log_B.scale = (px4log_B.In1.rollspeed -
                      px4log_P.DiscreteTransferFcn_DenCoef[1] *
                      px4log_DW.DiscreteTransferFcn_states) /
      px4log_P.DiscreteTransferFcn_DenCoef[0];

    // Sum: '<S4>/Subtract' incorporates:
    //   Constant: '<S4>/Zero'
    //   DataTypeConversion: '<S4>/Cast To Double14'
    //   UnitDelay: '<S15>/Output'

    rtb_Subtract = static_cast<real32_T>(px4log_DW.Output_DSTATE) -
      px4log_P.Zero_Value_g;

    // RelationalOperator: '<S24>/GreaterThan' incorporates:
    //   Delay: '<S24>/Delay'

    rtb_GreaterThan = (rtb_Subtract < px4log_DW.Delay_DSTATE);

    // DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S25>/Constant'

    if (px4log_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
      if (rtb_GreaterThan || (px4log_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
        px4log_DW.DiscreteTimeIntegrator_DSTATE = px4log_P.Constant_Value_o;
      } else {
        // DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
        px4log_DW.DiscreteTimeIntegrator_DSTATE += static_cast<real32_T>
          (px4log_P.DiscreteTimeIntegrator_gainval * static_cast<real_T>
           (Subsystem_ELAPS_T) * px4log_DW.DiscreteTimeIntegrator_PREV_U);
      }
    }

    // End of DiscreteIntegrator: '<S25>/Discrete-Time Integrator'

    // Sqrt: '<S38>/sqrt' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double2'
    //   Product: '<S39>/Product'
    //   Product: '<S39>/Product1'
    //   Product: '<S39>/Product2'
    //   Product: '<S39>/Product3'
    //   Sum: '<S39>/Sum'

    px4log_B.absxk = sqrt(((static_cast<real_T>(px4log_B.In1.q[0]) *
      px4log_B.In1.q[0] + static_cast<real_T>(px4log_B.In1.q[1]) *
      px4log_B.In1.q[1]) + static_cast<real_T>(px4log_B.In1.q[2]) *
      px4log_B.In1.q[2]) + static_cast<real_T>(px4log_B.In1.q[3]) *
                          px4log_B.In1.q[3]);

    // Product: '<S33>/Product' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double2'

    t = px4log_B.In1.q[0] / px4log_B.absxk;

    // Product: '<S33>/Product1' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double2'

    rtb_Product1 = px4log_B.In1.q[1] / px4log_B.absxk;

    // Product: '<S33>/Product2' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double2'

    rtb_Product2_o = px4log_B.In1.q[2] / px4log_B.absxk;

    // Product: '<S33>/Product3' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double2'

    px4log_B.absxk = px4log_B.In1.q[3] / px4log_B.absxk;

    // Sum: '<S25>/Sum3' incorporates:
    //   Constant: '<S1>/Constant2'
    //   Fcn: '<S9>/fcn4'
    //   Fcn: '<S9>/fcn5'
    //   Trigonometry: '<S32>/Trigonometric Function3'

    px4log_B.absxk = px4log_P.Constant2_Value - rt_atan2d_snf((rtb_Product2_o *
      px4log_B.absxk + t * rtb_Product1) * 2.0, ((t * t - rtb_Product1 *
      rtb_Product1) - rtb_Product2_o * rtb_Product2_o) + px4log_B.absxk *
      px4log_B.absxk);

    // Product: '<S25>/Product1' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double33'
    //   DataTypeConversion: '<S1>/Cast To Double4'
    //   DiscreteTransferFcn: '<S21>/Discrete Transfer Fcn'
    //   Lookup_n-D: '<S26>/1-D Lookup Table3'
    //   Lookup_n-D: '<S26>/1-D Lookup Table5'
    //   Product: '<S25>/Product2'
    //   Sum: '<S25>/Sum4'
    //   Sum: '<S25>/Sum5'

    t = ((look2_binlcapw(static_cast<real_T>(px4log_B.In1_c.alt), rtb_u00Hz,
                         px4log_P.Autopilot.Phi.h_bkpts_m,
                         px4log_P.Autopilot.Phi.V_bkpts_mps,
                         px4log_P.Autopilot.Phi.Kp_phi_vec,
                         px4log_P.uDLookupTable5_maxIndex, 3U) * px4log_B.absxk
          + px4log_DW.DiscreteTimeIntegrator_DSTATE) -
         (px4log_P.DiscreteTransferFcn_NumCoef[0] * px4log_B.scale +
          px4log_P.DiscreteTransferFcn_NumCoef[1] *
          px4log_DW.DiscreteTransferFcn_states)) * look2_binlcapw
      (static_cast<real_T>(px4log_B.In1_c.alt), rtb_u00Hz,
       px4log_P.Autopilot.Phi.h_bkpts_m, px4log_P.Autopilot.Phi.V_bkpts_mps,
       px4log_P.Autopilot.Phi.Kp_p_vec, px4log_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S27>/Product' incorporates:
    //   Constant: '<S21>/Zero'
    //   Constant: '<S27>/Constant7'

    for (i = 0; i < 4; i++) {
      px4log_B.CastToDouble2[i] = px4log_P.Constant7_Value[i + 8] *
        px4log_P.Zero_Value + (px4log_P.Constant7_Value[i + 4] *
        px4log_P.Zero_Value + px4log_P.Constant7_Value[i] * t);
    }

    // End of Product: '<S27>/Product'

    // MATLABSystem: '<S23>/PX4 PWM Output1'
    for (i = 0; i < 8; i++) {
      px4log_B.pwmValue[i] = 0U;
    }

    // Gain: '<S28>/Gain'
    t = px4log_P.Gain_Gain * px4log_B.CastToDouble2[0];

    // Saturate: '<S23>/Saturation'
    if (t > px4log_P.Saturation_UpperSat) {
      t = px4log_P.Saturation_UpperSat;
    } else if (t < px4log_P.Saturation_LowerSat) {
      t = px4log_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation'

    // DataTypeConversion: '<S23>/Cast To Double' incorporates:
    //   Constant: '<S23>/One'
    //   Gain: '<S23>/Gain'
    //   Sum: '<S23>/Add'

    t = floor(px4log_P.Gain_Gain_c * t + px4log_P.One_Value);
    if (rtIsNaN(t) || rtIsInf(t)) {
      t = 0.0;
    } else {
      t = fmod(t, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double'

    px4log_B.pwmValue[0] = static_cast<uint16_T>(t < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-t)))) :
      static_cast<int32_T>(static_cast<uint16_T>(t)));

    // Gain: '<S29>/Gain'
    t = px4log_P.Gain_Gain_l * px4log_B.CastToDouble2[1];

    // Saturate: '<S23>/Saturation1'
    if (t > px4log_P.Saturation1_UpperSat) {
      t = px4log_P.Saturation1_UpperSat;
    } else if (t < px4log_P.Saturation1_LowerSat) {
      t = px4log_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation1'

    // DataTypeConversion: '<S23>/Cast To Double1' incorporates:
    //   Constant: '<S23>/One1'
    //   Gain: '<S23>/Gain1'
    //   Sum: '<S23>/Add1'

    t = floor(px4log_P.Gain1_Gain * t + px4log_P.One1_Value);
    if (rtIsNaN(t) || rtIsInf(t)) {
      t = 0.0;
    } else {
      t = fmod(t, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double1'

    px4log_B.pwmValue[1] = static_cast<uint16_T>(t < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-t)))) :
      static_cast<int32_T>(static_cast<uint16_T>(t)));

    // Gain: '<S30>/Gain'
    t = px4log_P.Gain_Gain_m * px4log_B.CastToDouble2[2];

    // Saturate: '<S23>/Saturation2'
    if (t > px4log_P.Saturation2_UpperSat) {
      t = px4log_P.Saturation2_UpperSat;
    } else if (t < px4log_P.Saturation2_LowerSat) {
      t = px4log_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation2'

    // DataTypeConversion: '<S23>/Cast To Double2' incorporates:
    //   Constant: '<S23>/One2'
    //   Gain: '<S23>/Gain2'
    //   Sum: '<S23>/Add2'

    t = floor(px4log_P.Gain2_Gain * t + px4log_P.One2_Value);
    if (rtIsNaN(t) || rtIsInf(t)) {
      t = 0.0;
    } else {
      t = fmod(t, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double2'

    px4log_B.pwmValue[2] = static_cast<uint16_T>(t < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-t)))) :
      static_cast<int32_T>(static_cast<uint16_T>(t)));

    // Gain: '<S31>/Gain'
    t = px4log_P.Gain_Gain_mt * px4log_B.CastToDouble2[3];

    // Saturate: '<S23>/Saturation3'
    if (t > px4log_P.Saturation3_UpperSat) {
      t = px4log_P.Saturation3_UpperSat;
    } else if (t < px4log_P.Saturation3_LowerSat) {
      t = px4log_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation3'

    // DataTypeConversion: '<S23>/Cast To Double3' incorporates:
    //   Constant: '<S23>/One3'
    //   Gain: '<S23>/Gain3'
    //   Sum: '<S23>/Add3'

    t = floor(px4log_P.Gain3_Gain * t + px4log_P.One3_Value);
    if (rtIsNaN(t) || rtIsInf(t)) {
      t = 0.0;
    } else {
      t = fmod(t, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   Constant: '<S23>/One4'
    //   Constant: '<S23>/One5'
    //   DataTypeConversion: '<S23>/Cast To Double3'

    px4log_B.pwmValue[3] = static_cast<uint16_T>(t < 0.0 ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-t)))) :
      static_cast<int32_T>(static_cast<uint16_T>(t)));
    if (px4log_P.One5_Value) {
      if (!px4log_DW.obj_p.isArmed) {
        px4log_DW.obj_p.isArmed = true;
        status = pwm_arm(&px4log_DW.obj_p.pwmDevHandler,
                         &px4log_DW.obj_p.armAdvertiseObj);
        px4log_DW.obj_p.errorStatus = static_cast<uint16_T>
          (px4log_DW.obj_p.errorStatus | status);
      }

      status = pwm_setServo(&px4log_DW.obj_p.pwmDevHandler,
                            px4log_DW.obj_p.servoCount,
                            px4log_DW.obj_p.channelMask, &px4log_B.pwmValue[0],
                            px4log_DW.obj_p.isMain,
                            &px4log_DW.obj_p.actuatorAdvertiseObj);
      px4log_DW.obj_p.errorStatus = static_cast<uint16_T>
        (px4log_DW.obj_p.errorStatus | status);
    } else {
      status = pwm_disarm(&px4log_DW.obj_p.pwmDevHandler,
                          &px4log_DW.obj_p.armAdvertiseObj);
      px4log_DW.obj_p.errorStatus = static_cast<uint16_T>
        (px4log_DW.obj_p.errorStatus | status);
      px4log_DW.obj_p.isArmed = false;
      status = pwm_resetServo(&px4log_DW.obj_p.pwmDevHandler,
        px4log_DW.obj_p.servoCount, px4log_DW.obj_p.channelMask,
        px4log_DW.obj_p.isMain, &px4log_DW.obj_p.actuatorAdvertiseObj);
      px4log_DW.obj_p.errorStatus = static_cast<uint16_T>
        (px4log_DW.obj_p.errorStatus | status);
    }

    if (px4log_DW.obj_p.isMain) {
      status = pwm_forceFailsafe(&px4log_DW.obj_p.pwmDevHandler,
        static_cast<int32_T>(px4log_P.One4_Value));
      px4log_DW.obj_p.errorStatus = static_cast<uint16_T>
        (px4log_DW.obj_p.errorStatus | status);
    }

    // Sum: '<S16>/FixPt Sum1' incorporates:
    //   Constant: '<S16>/FixPt Constant'
    //   UnitDelay: '<S15>/Output'

    px4log_DW.Output_DSTATE = static_cast<uint16_T>(static_cast<uint32_T>
      (px4log_DW.Output_DSTATE) + px4log_P.FixPtConstant_Value);

    // Switch: '<S17>/FixPt Switch'
    if (px4log_DW.Output_DSTATE > px4log_P.WrapToZero_Threshold) {
      // Sum: '<S16>/FixPt Sum1' incorporates:
      //   Constant: '<S17>/Constant'

      px4log_DW.Output_DSTATE = px4log_P.Constant_Value_ai;
    }

    // End of Switch: '<S17>/FixPt Switch'

    // MATLABSystem: '<S11>/SourceBlock'
    uORB_read_step(px4log_DW.obj_m.orbMetadataObj,
                   &px4log_DW.obj_m.eventStructObj, &px4log_B.b_varargout_2_k,
                   false, 1.0);

    // MATLABSystem: '<S13>/SourceBlock'
    uORB_read_step(px4log_DW.obj_n.orbMetadataObj,
                   &px4log_DW.obj_n.eventStructObj, &px4log_B.b_varargout_2_cx,
                   false, 1.0);

    // Update for DiscreteTransferFcn: '<S21>/Discrete Transfer Fcn'
    px4log_DW.DiscreteTransferFcn_states = px4log_B.scale;

    // Update for Delay: '<S24>/Delay'
    px4log_DW.Delay_DSTATE = rtb_Subtract;

    // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   DataTypeConversion: '<S1>/Cast To Double33'
    //   DataTypeConversion: '<S1>/Cast To Double4'
    //   Lookup_n-D: '<S26>/1-D Lookup Table4'
    //   Product: '<S25>/Product3'

    px4log_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
    px4log_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
      (rtb_GreaterThan);
    px4log_DW.DiscreteTimeIntegrator_PREV_U = look2_binlcapw(static_cast<real_T>
      (px4log_B.In1_c.alt), rtb_u00Hz, px4log_P.Autopilot.Phi.h_bkpts_m,
      px4log_P.Autopilot.Phi.V_bkpts_mps, px4log_P.Autopilot.Phi.Ki_phi_vec,
      px4log_P.uDLookupTable4_maxIndex, 3U) * px4log_B.absxk;
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem'

  // Matfile logging
  rt_UpdateTXYLogVars(px4log_M->rtwLogInfo, (&px4log_M->Timing.taskTime0));

  // signal main to stop simulation
  {                                    // Sample time: [0.005s, 0.0s]
    if ((rtmGetTFinal(px4log_M)!=-1) &&
        !((rtmGetTFinal(px4log_M)-px4log_M->Timing.taskTime0) >
          px4log_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(px4log_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  px4log_M->Timing.taskTime0 =
    ((time_T)(++px4log_M->Timing.clockTick0)) * px4log_M->Timing.stepSize0;
}

// Model initialize function
void px4log_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(px4log_M, -1);
  px4log_M->Timing.stepSize0 = 0.005;

  // Setup for data logging
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    px4log_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  // Setup for data logging
  {
    rtliSetLogXSignalInfo(px4log_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(px4log_M->rtwLogInfo, (NULL));
    rtliSetLogT(px4log_M->rtwLogInfo, "tout");
    rtliSetLogX(px4log_M->rtwLogInfo, "");
    rtliSetLogXFinal(px4log_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(px4log_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(px4log_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(px4log_M->rtwLogInfo, 0);
    rtliSetLogDecimation(px4log_M->rtwLogInfo, 1);
    rtliSetLogY(px4log_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(px4log_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(px4log_M->rtwLogInfo, (NULL));
  }

  // Matfile logging
  rt_StartDataLoggingWithStartTime(px4log_M->rtwLogInfo, 0.0, rtmGetTFinal
    (px4log_M), px4log_M->Timing.stepSize0, (&rtmGetErrorStatus(px4log_M)));
  px4log_PrevZCX.Subsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  // SystemInitialize for Triggered SubSystem: '<Root>/Subsystem'
  // InitializeConditions for DiscreteTransferFcn: '<S21>/Discrete Transfer Fcn' 
  px4log_DW.DiscreteTransferFcn_states =
    px4log_P.DiscreteTransferFcn_InitialStat;

  // InitializeConditions for Sum: '<S16>/FixPt Sum1' incorporates:
  //   UnitDelay: '<S15>/Output'

  px4log_DW.Output_DSTATE = px4log_P.Output_InitialCondition;

  // InitializeConditions for Delay: '<S24>/Delay'
  px4log_DW.Delay_DSTATE = px4log_P.Delay_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
  //   Constant: '<S25>/Constant'

  px4log_DW.DiscreteTimeIntegrator_DSTATE = px4log_P.Constant_Value_o;

  // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S18>/Out1' incorporates:
  //   Inport: '<S18>/In1'

  px4log_B.In1_p = px4log_P.Out1_Y0_k;

  // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S19>/Out1' incorporates:
  //   Inport: '<S19>/In1'

  px4log_B.In1_c = px4log_P.Out1_Y0_b;

  // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S40>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S41>/Out1' incorporates:
  //   Inport: '<S41>/In1'

  px4log_B.In1 = px4log_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S40>/Enabled Subsystem'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  px4log_DW.obj_f.matlabCodegenIsDeleted = false;
  px4log_DW.obj_f.isSetupComplete = false;
  px4log_DW.obj_f.isInitialized = 1;
  px4log_DW.obj_f.orbMetadataObj = ORB_ID(vehicle_local_position);
  uORB_read_initialize(px4log_DW.obj_f.orbMetadataObj,
                       &px4log_DW.obj_f.eventStructObj);
  px4log_DW.obj_f.isSetupComplete = true;

  // Start for MATLABSystem: '<S7>/SourceBlock'
  px4log_DW.obj_g.matlabCodegenIsDeleted = false;
  px4log_DW.obj_g.isSetupComplete = false;
  px4log_DW.obj_g.isInitialized = 1;
  px4log_DW.obj_g.orbMetadataObj = ORB_ID(vehicle_gps_position);
  uORB_read_initialize(px4log_DW.obj_g.orbMetadataObj,
                       &px4log_DW.obj_g.eventStructObj);
  px4log_DW.obj_g.isSetupComplete = true;

  // Start for MATLABSystem: '<S40>/SourceBlock'
  px4log_DW.obj.matlabCodegenIsDeleted = false;
  px4log_DW.obj.isSetupComplete = false;
  px4log_DW.obj.isInitialized = 1;
  px4log_DW.obj.orbMetadataObj = ORB_ID(vehicle_odometry);
  uORB_read_initialize(px4log_DW.obj.orbMetadataObj,
                       &px4log_DW.obj.eventStructObj);
  px4log_DW.obj.isSetupComplete = true;

  // Start for MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
  //   Constant: '<S23>/One4'
  //   Constant: '<S23>/One5'

  px4log_DW.obj_p.errorStatus = 0U;
  px4log_DW.obj_p.isInitialized = 0;
  px4log_DW.obj_p.matlabCodegenIsDeleted = false;
  px4log_SystemCore_setup(&px4log_DW.obj_p, px4log_P.One5_Value,
    px4log_P.One4_Value);

  // Start for MATLABSystem: '<S11>/SourceBlock'
  px4log_DW.obj_m.matlabCodegenIsDeleted = false;
  px4log_DW.obj_m.isSetupComplete = false;
  px4log_DW.obj_m.isInitialized = 1;
  px4log_DW.obj_m.orbMetadataObj = ORB_ID(sensor_accel);
  uORB_read_initialize(px4log_DW.obj_m.orbMetadataObj,
                       &px4log_DW.obj_m.eventStructObj);
  px4log_DW.obj_m.isSetupComplete = true;

  // Start for MATLABSystem: '<S13>/SourceBlock'
  px4log_DW.obj_n.matlabCodegenIsDeleted = false;
  px4log_DW.obj_n.isSetupComplete = false;
  px4log_DW.obj_n.isInitialized = 1;
  px4log_DW.obj_n.orbMetadataObj = ORB_ID(sensor_gyro);
  uORB_read_initialize(px4log_DW.obj_n.orbMetadataObj,
                       &px4log_DW.obj_n.eventStructObj);
  px4log_DW.obj_n.isSetupComplete = true;

  // End of SystemInitialize for SubSystem: '<Root>/Subsystem'

  // Enable for Triggered SubSystem: '<Root>/Subsystem'
  px4log_DW.Subsystem_RESET_ELAPS_T = true;

  // Enable for DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
  px4log_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  // End of Enable for SubSystem: '<Root>/Subsystem'
}

// Model terminate function
void px4log_terminate(void)
{
  uint16_T status;

  // Terminate for Triggered SubSystem: '<Root>/Subsystem'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!px4log_DW.obj_f.matlabCodegenIsDeleted) {
    px4log_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((px4log_DW.obj_f.isInitialized == 1) && px4log_DW.obj_f.isSetupComplete)
    {
      uORB_read_terminate(&px4log_DW.obj_f.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!px4log_DW.obj_g.matlabCodegenIsDeleted) {
    px4log_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((px4log_DW.obj_g.isInitialized == 1) && px4log_DW.obj_g.isSetupComplete)
    {
      uORB_read_terminate(&px4log_DW.obj_g.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'

  // Terminate for MATLABSystem: '<S40>/SourceBlock'
  if (!px4log_DW.obj.matlabCodegenIsDeleted) {
    px4log_DW.obj.matlabCodegenIsDeleted = true;
    if ((px4log_DW.obj.isInitialized == 1) && px4log_DW.obj.isSetupComplete) {
      uORB_read_terminate(&px4log_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S40>/SourceBlock'

  // Terminate for MATLABSystem: '<S23>/PX4 PWM Output1'
  if (!px4log_DW.obj_p.matlabCodegenIsDeleted) {
    px4log_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((px4log_DW.obj_p.isInitialized == 1) && px4log_DW.obj_p.isSetupComplete)
    {
      status = pwm_disarm(&px4log_DW.obj_p.pwmDevHandler,
                          &px4log_DW.obj_p.armAdvertiseObj);
      px4log_DW.obj_p.errorStatus = static_cast<uint16_T>
        (px4log_DW.obj_p.errorStatus | status);
      status = pwm_resetServo(&px4log_DW.obj_p.pwmDevHandler,
        px4log_DW.obj_p.servoCount, px4log_DW.obj_p.channelMask,
        px4log_DW.obj_p.isMain, &px4log_DW.obj_p.actuatorAdvertiseObj);
      px4log_DW.obj_p.errorStatus = static_cast<uint16_T>
        (px4log_DW.obj_p.errorStatus | status);
      status = pwm_close(&px4log_DW.obj_p.pwmDevHandler,
                         &px4log_DW.obj_p.actuatorAdvertiseObj,
                         &px4log_DW.obj_p.armAdvertiseObj);
      px4log_DW.obj_p.errorStatus = static_cast<uint16_T>
        (px4log_DW.obj_p.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S23>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S11>/SourceBlock'
  if (!px4log_DW.obj_m.matlabCodegenIsDeleted) {
    px4log_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((px4log_DW.obj_m.isInitialized == 1) && px4log_DW.obj_m.isSetupComplete)
    {
      uORB_read_terminate(&px4log_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S11>/SourceBlock'

  // Terminate for MATLABSystem: '<S13>/SourceBlock'
  if (!px4log_DW.obj_n.matlabCodegenIsDeleted) {
    px4log_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((px4log_DW.obj_n.isInitialized == 1) && px4log_DW.obj_n.isSetupComplete)
    {
      uORB_read_terminate(&px4log_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S13>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subsystem'
}

//
// File trailer for generated code.
//
// [EOF]
//
