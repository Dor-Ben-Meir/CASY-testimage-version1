//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PixBlock3.cpp
//
// Code generated for Simulink model 'PixBlock3'.
//
// Model version                  : 4.25
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Apr 26 14:55:21 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PixBlock3.h"
#include "PixBlock3_private.h"

// Block signals (default storage)
B_PixBlock3_T PixBlock3_B;

// Block states (default storage)
DW_PixBlock3_T PixBlock3_DW;

// Previous zero-crossings (trigger) states
PrevZCX_PixBlock3_T PixBlock3_PrevZCX;

// External inputs (root inport signals with default storage)
ExtU_PixBlock3_T PixBlock3_U;

// External outputs (root outports fed by signals with default storage)
ExtY_PixBlock3_T PixBlock3_Y;

// Real-time model
RT_MODEL_PixBlock3_T PixBlock3_M_ = RT_MODEL_PixBlock3_T();
RT_MODEL_PixBlock3_T *const PixBlock3_M = &PixBlock3_M_;

// Forward declaration for local functions
static void PixBlock3_SystemCore_setup(px4_internal_block_PWM_PixBlock3_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
real32_T look2_iflf_binlcapw(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real32_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  real32_T fractions[2];
  real32_T frac;
  real32_T y;
  real32_T yL_0d0;
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
    frac = 0.0F;
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
    frac = 0.0F;
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
    frac = 0.0F;
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
    frac = 0.0F;
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

static void PixBlock3_SystemCore_setup(px4_internal_block_PWM_PixBlock3_T *obj,
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
void PixBlock3_step(void)
{
  real_T rtb_fin_cmd_idx_0;
  int32_T i;
  real32_T DiscreteTransferFcn1_tmp;
  real32_T rtb_Ki_phi;
  real32_T rtb_SquareRoot;
  real32_T rtb_p;
  real32_T rtb_u;
  real32_T rtb_v;
  real32_T rtb_w;
  real32_T rtb_z;
  real32_T tmp;
  uint32_T EmulatedPixhawk_ELAPS_T;
  uint16_T status;
  boolean_T rtb_GreaterThan;
  ZCEventType zcEvent;

  // DiscretePulseGenerator: '<S1>/100 Hz'
  PixBlock3_B.u00Hz = (PixBlock3_DW.clockTickCounter < PixBlock3_P.u00Hz_Duty) &&
    (PixBlock3_DW.clockTickCounter >= 0) ? PixBlock3_P.u00Hz_Amp : 0.0;
  if (PixBlock3_DW.clockTickCounter >= PixBlock3_P.u00Hz_Period - 1.0) {
    PixBlock3_DW.clockTickCounter = 0;
  } else {
    PixBlock3_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S1>/100 Hz'

  // Outputs for Triggered SubSystem: '<S1>/Emulated Pixhawk' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &PixBlock3_PrevZCX.EmulatedPixhawk_Trig_ZCE,
                     (PixBlock3_B.u00Hz));
  if (zcEvent != NO_ZCEVENT) {
    if (PixBlock3_DW.EmulatedPixhawk_RESET_ELAPS_T) {
      EmulatedPixhawk_ELAPS_T = 0U;
    } else {
      EmulatedPixhawk_ELAPS_T = PixBlock3_M->Timing.clockTick0 -
        PixBlock3_DW.EmulatedPixhawk_PREV_T;
    }

    PixBlock3_DW.EmulatedPixhawk_PREV_T = PixBlock3_M->Timing.clockTick0;
    PixBlock3_DW.EmulatedPixhawk_RESET_ELAPS_T = false;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[0] = PixBlock3_U.SerialIn[1];

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One'
    //   Inport: '<Root>/Serial In'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_1_Threshold) {
      rtb_u = PixBlock3_P.One_Value;
    } else {
      rtb_u = PixBlock3_U.SerialIn[4];
    }

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One1'
    //   Inport: '<Root>/Serial In'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_2_Threshold) {
      rtb_v = PixBlock3_P.One1_Value;
    } else {
      rtb_v = PixBlock3_U.SerialIn[5];
    }

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One2'
    //   Inport: '<Root>/Serial In'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_3_Threshold) {
      rtb_w = PixBlock3_P.One2_Value;
    } else {
      rtb_w = PixBlock3_U.SerialIn[6];
    }

    // Sqrt: '<S9>/Square Root' incorporates:
    //   Math: '<S9>/Square'
    //   Math: '<S9>/Square1'
    //   Math: '<S9>/Square2'
    //   Sum: '<S9>/Add'

    rtb_SquareRoot = static_cast<real32_T>(sqrt(static_cast<real_T>((rtb_u *
      rtb_u + rtb_v * rtb_v) + rtb_w * rtb_w)));

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One5'
    //   Inport: '<Root>/Serial In'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_6_Threshold) {
      rtb_z = PixBlock3_P.One5_Value;
    } else {
      rtb_z = PixBlock3_U.SerialIn[9];
    }

    // Gain: '<S3>/Gain1'
    rtb_Ki_phi = PixBlock3_P.Gain1_Gain * rtb_z;

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One6'
    //   Inport: '<Root>/Serial In'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_7_Threshold) {
      rtb_p = PixBlock3_P.One6_Value;
    } else {
      rtb_p = PixBlock3_U.SerialIn[10];
    }

    // DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1'
    DiscreteTransferFcn1_tmp = (rtb_p -
      PixBlock3_P.DiscreteTransferFcn1_DenCoef[1] *
      PixBlock3_DW.DiscreteTransferFcn1_states) /
      PixBlock3_P.DiscreteTransferFcn1_DenCoef[0];

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One9'
    //   Inport: '<Root>/Serial In'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_10_Threshold) {
      tmp = PixBlock3_P.One9_Value;
    } else {
      tmp = PixBlock3_U.SerialIn[19];
    }

    // Sum: '<S12>/Sum3' incorporates:
    //   Constant: '<S10>/Constant'

    PixBlock3_B.u00Hz = PixBlock3_P.Constant_Value - tmp;

    // RelationalOperator: '<S21>/GreaterThan' incorporates:
    //   Delay: '<S21>/Delay'
    //   Inport: '<Root>/Serial In'

    rtb_GreaterThan = (PixBlock3_U.SerialIn[1] < PixBlock3_DW.Delay_DSTATE);

    // DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S12>/Constant'

    if (PixBlock3_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE == 0) {
      if (rtb_GreaterThan || (PixBlock3_DW.DiscreteTimeIntegrator_PrevResetState
           != 0)) {
        PixBlock3_DW.DiscreteTimeIntegrator_DSTATE =
          PixBlock3_P.Constant_Value_o;
      } else {
        // DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
        PixBlock3_DW.DiscreteTimeIntegrator_DSTATE += static_cast<real32_T>
          (PixBlock3_P.DiscreteTimeIntegrator_gainval * static_cast<real_T>
           (EmulatedPixhawk_ELAPS_T)
           * PixBlock3_DW.DiscreteTimeIntegrator_PREV_U);
      }
    }

    // End of DiscreteIntegrator: '<S12>/Discrete-Time Integrator'

    // Product: '<S12>/Product1' incorporates:
    //   DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1'
    //   Lookup_n-D: '<S15>/1-D Lookup Table3'
    //   Lookup_n-D: '<S15>/1-D Lookup Table4'
    //   Lookup_n-D: '<S15>/1-D Lookup Table5'
    //   Product: '<S12>/Product2'
    //   Sqrt: '<S9>/Square Root'
    //   Sum: '<S12>/Sum4'
    //   Sum: '<S12>/Sum5'

    rtb_fin_cmd_idx_0 = ((look2_iflf_binlcapw(rtb_Ki_phi, rtb_SquareRoot,
      PixBlock3_P.uDLookupTable5_bp01Data, PixBlock3_P.uDLookupTable5_bp02Data,
      PixBlock3_P.uDLookupTable5_tableData, PixBlock3_P.uDLookupTable5_maxIndex,
      3U) * PixBlock3_B.u00Hz + PixBlock3_DW.DiscreteTimeIntegrator_DSTATE) -
                         (PixBlock3_P.DiscreteTransferFcn1_NumCoef[0] *
                          DiscreteTransferFcn1_tmp +
                          PixBlock3_P.DiscreteTransferFcn1_NumCoef[1] *
                          PixBlock3_DW.DiscreteTransferFcn1_states)) *
      look2_iflf_binlcapw(rtb_Ki_phi, rtb_SquareRoot,
                          PixBlock3_P.uDLookupTable3_bp01Data,
                          PixBlock3_P.uDLookupTable3_bp02Data,
                          PixBlock3_P.uDLookupTable3_tableData,
                          PixBlock3_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S14>/Product' incorporates:
    //   Constant: '<S12>/Zero'
    //   Constant: '<S14>/Constant7'
    //   DataTypeConversion: '<S14>/Cast To Single1'

    for (i = 0; i < 4; i++) {
      PixBlock3_B.siB_cmd[i] = PixBlock3_P.Constant7_Value[i + 8] *
        static_cast<real32_T>(PixBlock3_P.Zero_Value) +
        (PixBlock3_P.Constant7_Value[i + 4] * static_cast<real32_T>
         (PixBlock3_P.Zero_Value) + PixBlock3_P.Constant7_Value[i] *
         static_cast<real32_T>(rtb_fin_cmd_idx_0));
    }

    // End of Product: '<S14>/Product'

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[1] = PixBlock3_B.siB_cmd[0];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[2] = PixBlock3_B.siB_cmd[1];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[3] = PixBlock3_B.siB_cmd[2];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[4] = PixBlock3_B.siB_cmd[3];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[5] = PixBlock3_U.SerialIn[16];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[6] = PixBlock3_U.SerialIn[17];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[7] = PixBlock3_U.SerialIn[18];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[8] = rtb_u;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[9] = rtb_v;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[10] = rtb_w;

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One3'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_4_Threshold) {
      PixBlock3_Y.SerialOut[11] = PixBlock3_P.One3_Value;
    } else {
      PixBlock3_Y.SerialOut[11] = PixBlock3_U.SerialIn[7];
    }

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One4'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_5_Threshold) {
      PixBlock3_Y.SerialOut[12] = PixBlock3_P.One4_Value;
    } else {
      PixBlock3_Y.SerialOut[12] = PixBlock3_U.SerialIn[8];
    }

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[13] = rtb_z;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[14] = rtb_p;

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One7'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_8_Threshold) {
      PixBlock3_Y.SerialOut[15] = PixBlock3_P.One7_Value;
    } else {
      PixBlock3_Y.SerialOut[15] = PixBlock3_U.SerialIn[11];
    }

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S22>/One8'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock3_U.SerialIn[2] > PixBlock3_P.Switch_9_Threshold) {
      PixBlock3_Y.SerialOut[16] = PixBlock3_P.One8_Value;
    } else {
      PixBlock3_Y.SerialOut[16] = PixBlock3_U.SerialIn[12];
    }

    // Constant: '<S2>/Zero' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock3_Y.SerialOut[17] = PixBlock3_P.Zero_Value_a;

    // MATLABSystem: '<S13>/PX4 PWM Output1'
    for (i = 0; i < 8; i++) {
      PixBlock3_B.pwmValue[i] = 0U;
    }

    // Gain: '<S17>/Gain'
    rtb_u = PixBlock3_P.Gain_Gain * PixBlock3_B.siB_cmd[0];

    // Saturate: '<S13>/Saturation'
    if (rtb_u > PixBlock3_P.Saturation_UpperSat) {
      rtb_u = PixBlock3_P.Saturation_UpperSat;
    } else if (rtb_u < PixBlock3_P.Saturation_LowerSat) {
      rtb_u = PixBlock3_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S13>/Saturation'

    // DataTypeConversion: '<S13>/Cast To Double' incorporates:
    //   Constant: '<S13>/One'
    //   Gain: '<S13>/Gain'
    //   Sum: '<S13>/Add'

    tmp = static_cast<real32_T>(floor(static_cast<real_T>
      (PixBlock3_P.Gain_Gain_m * rtb_u + PixBlock3_P.One_Value_f)));
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = static_cast<real32_T>(fmod(static_cast<real_T>(tmp), 65536.0));
    }

    // MATLABSystem: '<S13>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S13>/Cast To Double'

    PixBlock3_B.pwmValue[0] = static_cast<uint16_T>(tmp < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
      (tmp)));

    // Gain: '<S18>/Gain'
    rtb_u = PixBlock3_P.Gain_Gain_g * PixBlock3_B.siB_cmd[1];

    // Saturate: '<S13>/Saturation1'
    if (rtb_u > PixBlock3_P.Saturation1_UpperSat) {
      rtb_u = PixBlock3_P.Saturation1_UpperSat;
    } else if (rtb_u < PixBlock3_P.Saturation1_LowerSat) {
      rtb_u = PixBlock3_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S13>/Saturation1'

    // DataTypeConversion: '<S13>/Cast To Double1' incorporates:
    //   Constant: '<S13>/One1'
    //   Gain: '<S13>/Gain1'
    //   Sum: '<S13>/Add1'

    tmp = static_cast<real32_T>(floor(static_cast<real_T>
      (PixBlock3_P.Gain1_Gain_j * rtb_u + PixBlock3_P.One1_Value_d)));
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = static_cast<real32_T>(fmod(static_cast<real_T>(tmp), 65536.0));
    }

    // MATLABSystem: '<S13>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S13>/Cast To Double1'

    PixBlock3_B.pwmValue[1] = static_cast<uint16_T>(tmp < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
      (tmp)));

    // Gain: '<S19>/Gain'
    rtb_u = PixBlock3_P.Gain_Gain_c * PixBlock3_B.siB_cmd[2];

    // Saturate: '<S13>/Saturation2'
    if (rtb_u > PixBlock3_P.Saturation2_UpperSat) {
      rtb_u = PixBlock3_P.Saturation2_UpperSat;
    } else if (rtb_u < PixBlock3_P.Saturation2_LowerSat) {
      rtb_u = PixBlock3_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S13>/Saturation2'

    // DataTypeConversion: '<S13>/Cast To Double2' incorporates:
    //   Constant: '<S13>/One2'
    //   Gain: '<S13>/Gain2'
    //   Sum: '<S13>/Add2'

    tmp = static_cast<real32_T>(floor(static_cast<real_T>(PixBlock3_P.Gain2_Gain
      * rtb_u + PixBlock3_P.One2_Value_d)));
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = static_cast<real32_T>(fmod(static_cast<real_T>(tmp), 65536.0));
    }

    // MATLABSystem: '<S13>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S13>/Cast To Double2'

    PixBlock3_B.pwmValue[2] = static_cast<uint16_T>(tmp < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
      (tmp)));

    // Gain: '<S20>/Gain'
    rtb_u = PixBlock3_P.Gain_Gain_l * PixBlock3_B.siB_cmd[3];

    // Saturate: '<S13>/Saturation3'
    if (rtb_u > PixBlock3_P.Saturation3_UpperSat) {
      rtb_u = PixBlock3_P.Saturation3_UpperSat;
    } else if (rtb_u < PixBlock3_P.Saturation3_LowerSat) {
      rtb_u = PixBlock3_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S13>/Saturation3'

    // DataTypeConversion: '<S13>/Cast To Double3' incorporates:
    //   Constant: '<S13>/One3'
    //   Gain: '<S13>/Gain3'
    //   Sum: '<S13>/Add3'

    tmp = static_cast<real32_T>(floor(static_cast<real_T>(PixBlock3_P.Gain3_Gain
      * rtb_u + PixBlock3_P.One3_Value_b)));
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = static_cast<real32_T>(fmod(static_cast<real_T>(tmp), 65536.0));
    }

    // MATLABSystem: '<S13>/PX4 PWM Output1' incorporates:
    //   Constant: '<S13>/One4'
    //   DataTypeConversion: '<S13>/Cast To Double3'
    //   Delay: '<S16>/Delay'
    //   Inport: '<Root>/Serial In'
    //   Logic: '<S13>/AND'
    //   RelationalOperator: '<S16>/GreaterThan'

    PixBlock3_B.pwmValue[3] = static_cast<uint16_T>(tmp < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
      (tmp)));
    if ((PixBlock3_U.SerialIn[0] != 0.0F) && (PixBlock3_U.SerialIn[1] >
         PixBlock3_DW.Delay_DSTATE_l)) {
      if (!PixBlock3_DW.obj.isArmed) {
        PixBlock3_DW.obj.isArmed = true;
        status = pwm_arm(&PixBlock3_DW.obj.pwmDevHandler,
                         &PixBlock3_DW.obj.armAdvertiseObj);
        PixBlock3_DW.obj.errorStatus = static_cast<uint16_T>
          (PixBlock3_DW.obj.errorStatus | status);
      }

      status = pwm_setServo(&PixBlock3_DW.obj.pwmDevHandler,
                            PixBlock3_DW.obj.servoCount,
                            PixBlock3_DW.obj.channelMask, &PixBlock3_B.pwmValue
                            [0], PixBlock3_DW.obj.isMain,
                            &PixBlock3_DW.obj.actuatorAdvertiseObj);
      PixBlock3_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock3_DW.obj.errorStatus | status);
    } else {
      status = pwm_disarm(&PixBlock3_DW.obj.pwmDevHandler,
                          &PixBlock3_DW.obj.armAdvertiseObj);
      PixBlock3_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock3_DW.obj.errorStatus | status);
      PixBlock3_DW.obj.isArmed = false;
      status = pwm_resetServo(&PixBlock3_DW.obj.pwmDevHandler,
        PixBlock3_DW.obj.servoCount, PixBlock3_DW.obj.channelMask,
        PixBlock3_DW.obj.isMain, &PixBlock3_DW.obj.actuatorAdvertiseObj);
      PixBlock3_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock3_DW.obj.errorStatus | status);
    }

    if (PixBlock3_DW.obj.isMain) {
      status = pwm_forceFailsafe(&PixBlock3_DW.obj.pwmDevHandler,
        static_cast<int32_T>(PixBlock3_P.One4_Value_p));
      PixBlock3_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock3_DW.obj.errorStatus | status);
    }

    // Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1'
    PixBlock3_DW.DiscreteTransferFcn1_states = DiscreteTransferFcn1_tmp;

    // Update for Delay: '<S21>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    PixBlock3_DW.Delay_DSTATE = PixBlock3_U.SerialIn[1];

    // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Lookup_n-D: '<S15>/1-D Lookup Table4'
    //   Product: '<S12>/Product3'
    //   Sqrt: '<S9>/Square Root'

    PixBlock3_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
    PixBlock3_DW.DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
      (rtb_GreaterThan);
    PixBlock3_DW.DiscreteTimeIntegrator_PREV_U = look2_iflf_binlcapw(rtb_Ki_phi,
      rtb_SquareRoot, PixBlock3_P.uDLookupTable4_bp01Data,
      PixBlock3_P.uDLookupTable4_bp02Data, PixBlock3_P.uDLookupTable4_tableData,
      PixBlock3_P.uDLookupTable4_maxIndex, 3U) * PixBlock3_B.u00Hz;

    // Update for Delay: '<S16>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    PixBlock3_DW.Delay_DSTATE_l = PixBlock3_U.SerialIn[1];
  }

  // End of Outputs for SubSystem: '<S1>/Emulated Pixhawk'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.001, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  PixBlock3_M->Timing.clockTick0++;
}

// Model initialize function
void PixBlock3_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    boolean_T rtb_AND;
    PixBlock3_PrevZCX.EmulatedPixhawk_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // SystemInitialize for Triggered SubSystem: '<S1>/Emulated Pixhawk'
    // InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn1' 
    PixBlock3_DW.DiscreteTransferFcn1_states =
      PixBlock3_P.DiscreteTransferFcn1_InitialStates;

    // InitializeConditions for Delay: '<S21>/Delay'
    PixBlock3_DW.Delay_DSTATE = PixBlock3_P.Delay_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S12>/Constant'

    PixBlock3_DW.DiscreteTimeIntegrator_DSTATE = PixBlock3_P.Constant_Value_o;

    // InitializeConditions for Delay: '<S16>/Delay'
    PixBlock3_DW.Delay_DSTATE_l = PixBlock3_P.Delay_InitialCondition_f;

    // Start for MATLABSystem: '<S13>/PX4 PWM Output1' incorporates:
    //   Constant: '<S13>/One4'

    PixBlock3_DW.obj.errorStatus = 0U;
    PixBlock3_DW.obj.isInitialized = 0;
    PixBlock3_DW.obj.matlabCodegenIsDeleted = false;
    PixBlock3_SystemCore_setup(&PixBlock3_DW.obj, rtb_AND,
      PixBlock3_P.One4_Value_p);
    for (i = 0; i < 18; i++) {
      // SystemInitialize for Outport: '<Root>/Serial Out' incorporates:
      //   Outport: '<S2>/Serial Out'

      PixBlock3_Y.SerialOut[i] = PixBlock3_P.SerialOut_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S1>/Emulated Pixhawk'

    // Enable for Triggered SubSystem: '<S1>/Emulated Pixhawk'
    PixBlock3_DW.EmulatedPixhawk_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
    PixBlock3_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;

    // End of Enable for SubSystem: '<S1>/Emulated Pixhawk'
  }
}

// Model terminate function
void PixBlock3_terminate(void)
{
  uint16_T status;

  // Terminate for Triggered SubSystem: '<S1>/Emulated Pixhawk'
  // Terminate for MATLABSystem: '<S13>/PX4 PWM Output1'
  if (!PixBlock3_DW.obj.matlabCodegenIsDeleted) {
    PixBlock3_DW.obj.matlabCodegenIsDeleted = true;
    if ((PixBlock3_DW.obj.isInitialized == 1) &&
        PixBlock3_DW.obj.isSetupComplete) {
      status = pwm_disarm(&PixBlock3_DW.obj.pwmDevHandler,
                          &PixBlock3_DW.obj.armAdvertiseObj);
      PixBlock3_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock3_DW.obj.errorStatus | status);
      status = pwm_resetServo(&PixBlock3_DW.obj.pwmDevHandler,
        PixBlock3_DW.obj.servoCount, PixBlock3_DW.obj.channelMask,
        PixBlock3_DW.obj.isMain, &PixBlock3_DW.obj.actuatorAdvertiseObj);
      PixBlock3_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock3_DW.obj.errorStatus | status);
      status = pwm_close(&PixBlock3_DW.obj.pwmDevHandler,
                         &PixBlock3_DW.obj.actuatorAdvertiseObj,
                         &PixBlock3_DW.obj.armAdvertiseObj);
      PixBlock3_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock3_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S13>/PX4 PWM Output1'
  // End of Terminate for SubSystem: '<S1>/Emulated Pixhawk'
}

//
// File trailer for generated code.
//
// [EOF]
//
