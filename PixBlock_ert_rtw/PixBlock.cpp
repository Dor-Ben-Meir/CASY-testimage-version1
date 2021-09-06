//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PixBlock.cpp
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
#include "PixBlock.h"
#include "PixBlock_private.h"

// Block signals (default storage)
B_PixBlock_T PixBlock_B;

// Block states (default storage)
DW_PixBlock_T PixBlock_DW;

// Previous zero-crossings (trigger) states
PrevZCX_PixBlock_T PixBlock_PrevZCX;

// External inputs (root inport signals with default storage)
ExtU_PixBlock_T PixBlock_U;

// External outputs (root outports fed by signals with default storage)
ExtY_PixBlock_T PixBlock_Y;

// Real-time model
RT_MODEL_PixBlock_T PixBlock_M_ = RT_MODEL_PixBlock_T();
RT_MODEL_PixBlock_T *const PixBlock_M = &PixBlock_M_;

// Forward declaration for local functions
static void PixBlock_SystemCore_setup(px4_internal_block_PWM_PixBlock_T *obj,
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

static void PixBlock_SystemCore_setup(px4_internal_block_PWM_PixBlock_T *obj,
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
void PixBlock_step(void)
{
  real_T rtb_u00Hz1;
  int32_T i;
  real32_T DiscreteTransferFcn_tmp;
  real32_T rtb_Add3;
  real32_T rtb_Ki_phi;
  real32_T rtb_SquareRoot;
  real32_T rtb_Sum3;
  real32_T rtb_fin_cmd_idx_0;
  real32_T rtb_u;
  real32_T rtb_v;
  real32_T rtb_w;
  real32_T rtb_z;
  uint32_T EmulatedPixhawk1_ELAPS_T;
  uint16_T status;
  boolean_T rtb_GreaterThan;
  ZCEventType zcEvent;

  // DiscretePulseGenerator: '<S1>/100 Hz1'
  rtb_u00Hz1 = (PixBlock_DW.clockTickCounter < PixBlock_P.u00Hz1_Duty) &&
    (PixBlock_DW.clockTickCounter >= 0) ? PixBlock_P.u00Hz1_Amp : 0.0;
  if (PixBlock_DW.clockTickCounter >= PixBlock_P.u00Hz1_Period - 1.0) {
    PixBlock_DW.clockTickCounter = 0;
  } else {
    PixBlock_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S1>/100 Hz1'

  // Outputs for Triggered SubSystem: '<S1>/Emulated Pixhawk1' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &PixBlock_PrevZCX.EmulatedPixhawk1_Trig_ZCE,
                     (rtb_u00Hz1));
  if (zcEvent != NO_ZCEVENT) {
    if (PixBlock_DW.EmulatedPixhawk1_RESET_ELAPS_T) {
      EmulatedPixhawk1_ELAPS_T = 0U;
    } else {
      EmulatedPixhawk1_ELAPS_T = PixBlock_M->Timing.clockTick0 -
        PixBlock_DW.EmulatedPixhawk1_PREV_T;
    }

    PixBlock_DW.EmulatedPixhawk1_PREV_T = PixBlock_M->Timing.clockTick0;
    PixBlock_DW.EmulatedPixhawk1_RESET_ELAPS_T = false;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[0] = PixBlock_U.send[1];

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One5'
    //   Inport: '<Root>/Serial In'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_6_Threshold) {
      rtb_z = PixBlock_P.One5_Value;
    } else {
      rtb_z = PixBlock_U.send[9];
    }

    // Gain: '<S3>/Gain'
    rtb_Ki_phi = PixBlock_P.Gain_Gain * rtb_z;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One'
    //   Inport: '<Root>/Serial In'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_1_Threshold) {
      rtb_u = PixBlock_P.One_Value;
    } else {
      rtb_u = PixBlock_U.send[4];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One1'
    //   Inport: '<Root>/Serial In'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_2_Threshold) {
      rtb_v = PixBlock_P.One1_Value;
    } else {
      rtb_v = PixBlock_U.send[5];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One2'
    //   Inport: '<Root>/Serial In'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_3_Threshold) {
      rtb_w = PixBlock_P.One2_Value;
    } else {
      rtb_w = PixBlock_U.send[6];
    }

    // Sqrt: '<S11>/Square Root' incorporates:
    //   Math: '<S11>/Square'
    //   Math: '<S11>/Square1'
    //   Math: '<S11>/Square2'
    //   Sum: '<S11>/Add'

    rtb_SquareRoot = static_cast<real32_T>(sqrt(static_cast<real_T>((rtb_u *
      rtb_u + rtb_v * rtb_v) + rtb_w * rtb_w)));

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One9'
    //   Inport: '<Root>/Serial In'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_10_Threshold) {
      rtb_fin_cmd_idx_0 = PixBlock_P.One9_Value;
    } else {
      rtb_fin_cmd_idx_0 = PixBlock_U.send[19];
    }

    // Sum: '<S12>/Sum3' incorporates:
    //   Inport: '<Root>/Serial In'

    rtb_Sum3 = PixBlock_U.send[22] - rtb_fin_cmd_idx_0;

    // RelationalOperator: '<S14>/GreaterThan' incorporates:
    //   Delay: '<S14>/Delay'
    //   Inport: '<Root>/Serial In'

    rtb_GreaterThan = (PixBlock_U.send[1] < PixBlock_DW.Delay_DSTATE);

    // DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S12>/Constant'

    if (PixBlock_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE == 0) {
      if (rtb_GreaterThan || (PixBlock_DW.DiscreteTimeIntegrator_PrevResetState
                              != 0)) {
        PixBlock_DW.DiscreteTimeIntegrator_DSTATE = PixBlock_P.Constant_Value;
      } else {
        // DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
        PixBlock_DW.DiscreteTimeIntegrator_DSTATE +=
          PixBlock_P.DiscreteTimeIntegrator_gainval * static_cast<real32_T>
          (EmulatedPixhawk1_ELAPS_T) * PixBlock_DW.DiscreteTimeIntegrator_PREV_U;
      }
    }

    // End of DiscreteIntegrator: '<S12>/Discrete-Time Integrator'

    // DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' incorporates:
    //   Inport: '<Root>/Serial In'

    DiscreteTransferFcn_tmp = (PixBlock_U.send[16] -
      PixBlock_P.DiscreteTransferFcn_DenCoef[1] *
      PixBlock_DW.DiscreteTransferFcn_states) /
      PixBlock_P.DiscreteTransferFcn_DenCoef[0];

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One6'
    //   Inport: '<Root>/Serial In'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_7_Threshold) {
      rtb_Add3 = PixBlock_P.One6_Value;
    } else {
      rtb_Add3 = PixBlock_U.send[10];
    }

    // ManualSwitch: '<S3>/Manual Switch' incorporates:
    //   DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'

    if (PixBlock_P.ManualSwitch_CurrentSetting == 1) {
      rtb_fin_cmd_idx_0 = PixBlock_P.DiscreteTransferFcn_NumCoef[0] *
        DiscreteTransferFcn_tmp + PixBlock_P.DiscreteTransferFcn_NumCoef[1] *
        PixBlock_DW.DiscreteTransferFcn_states;
    } else {
      rtb_fin_cmd_idx_0 = rtb_Add3;
    }

    // End of ManualSwitch: '<S3>/Manual Switch'

    // Product: '<S12>/Product1' incorporates:
    //   Lookup_n-D: '<S13>/1-D Lookup Table3'
    //   Lookup_n-D: '<S13>/1-D Lookup Table4'
    //   Lookup_n-D: '<S13>/1-D Lookup Table5'
    //   Product: '<S12>/Product2'
    //   Sqrt: '<S11>/Square Root'
    //   Sum: '<S12>/Sum4'
    //   Sum: '<S12>/Sum5'

    rtb_fin_cmd_idx_0 = ((look2_iflf_binlcapw(rtb_Ki_phi, rtb_SquareRoot,
      PixBlock_P.uDLookupTable5_bp01Data, PixBlock_P.uDLookupTable5_bp02Data,
      PixBlock_P.uDLookupTable5_tableData, PixBlock_P.uDLookupTable5_maxIndex,
      3U) * rtb_Sum3 + PixBlock_DW.DiscreteTimeIntegrator_DSTATE) -
                         rtb_fin_cmd_idx_0) * look2_iflf_binlcapw(rtb_Ki_phi,
      rtb_SquareRoot, PixBlock_P.uDLookupTable3_bp01Data,
      PixBlock_P.uDLookupTable3_bp02Data, PixBlock_P.uDLookupTable3_tableData,
      PixBlock_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S15>/Product' incorporates:
    //   Constant: '<S15>/Constant7'
    //   Constant: '<S3>/Zero'

    for (i = 0; i < 4; i++) {
      PixBlock_B.siB_cmd[i] = PixBlock_P.Constant7_Value[i + 8] *
        PixBlock_P.Zero_Value + (PixBlock_P.Constant7_Value[i + 4] *
        PixBlock_P.Zero_Value + PixBlock_P.Constant7_Value[i] *
        rtb_fin_cmd_idx_0);
    }

    // End of Product: '<S15>/Product'

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[1] = PixBlock_B.siB_cmd[0];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[2] = PixBlock_B.siB_cmd[1];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[3] = PixBlock_B.siB_cmd[2];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[4] = PixBlock_B.siB_cmd[3];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[5] = PixBlock_U.send[16];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[6] = PixBlock_U.send[17];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[7] = PixBlock_U.send[18];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[8] = rtb_u;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[9] = rtb_v;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[10] = rtb_w;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One3'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_4_Threshold) {
      PixBlock_Y.SerialOut[11] = PixBlock_P.One3_Value;
    } else {
      PixBlock_Y.SerialOut[11] = PixBlock_U.send[7];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One4'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_5_Threshold) {
      PixBlock_Y.SerialOut[12] = PixBlock_P.One4_Value;
    } else {
      PixBlock_Y.SerialOut[12] = PixBlock_U.send[8];
    }

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[13] = rtb_z;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[14] = rtb_Add3;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One7'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_8_Threshold) {
      PixBlock_Y.SerialOut[15] = PixBlock_P.One7_Value;
    } else {
      PixBlock_Y.SerialOut[15] = PixBlock_U.send[11];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One8'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock_U.send[2] > PixBlock_P.Switch_9_Threshold) {
      PixBlock_Y.SerialOut[16] = PixBlock_P.One8_Value;
    } else {
      PixBlock_Y.SerialOut[16] = PixBlock_U.send[12];
    }

    // Constant: '<S2>/Zero' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock_Y.SerialOut[17] = PixBlock_P.Zero_Value_f;

    // MATLABSystem: '<S10>/PX4 PWM Output1'
    for (i = 0; i < 8; i++) {
      PixBlock_B.pwmValue[i] = 0U;
    }

    // Gain: '<S18>/Gain'
    rtb_z = PixBlock_P.Gain_Gain_j * PixBlock_B.siB_cmd[0];

    // Saturate: '<S10>/Saturation'
    if (rtb_z > PixBlock_P.Saturation_UpperSat) {
      rtb_z = PixBlock_P.Saturation_UpperSat;
    } else if (rtb_z < PixBlock_P.Saturation_LowerSat) {
      rtb_z = PixBlock_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S10>/Saturation'

    // DataTypeConversion: '<S10>/Cast To Double' incorporates:
    //   Constant: '<S10>/One'
    //   Gain: '<S10>/Gain'
    //   Sum: '<S10>/Add'

    rtb_fin_cmd_idx_0 = static_cast<real32_T>(floor(static_cast<real_T>
      (PixBlock_P.Gain_Gain_o * rtb_z + PixBlock_P.One_Value_a)));
    if (rtIsNaNF(rtb_fin_cmd_idx_0) || rtIsInfF(rtb_fin_cmd_idx_0)) {
      rtb_fin_cmd_idx_0 = 0.0F;
    } else {
      rtb_fin_cmd_idx_0 = static_cast<real32_T>(fmod(static_cast<real_T>
        (rtb_fin_cmd_idx_0), 65536.0));
    }

    // MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double'

    PixBlock_B.pwmValue[0] = static_cast<uint16_T>(rtb_fin_cmd_idx_0 < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_fin_cmd_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_fin_cmd_idx_0)));

    // Gain: '<S19>/Gain'
    rtb_z = PixBlock_P.Gain_Gain_os * PixBlock_B.siB_cmd[1];

    // Saturate: '<S10>/Saturation1'
    if (rtb_z > PixBlock_P.Saturation1_UpperSat) {
      rtb_z = PixBlock_P.Saturation1_UpperSat;
    } else if (rtb_z < PixBlock_P.Saturation1_LowerSat) {
      rtb_z = PixBlock_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S10>/Saturation1'

    // DataTypeConversion: '<S10>/Cast To Double1' incorporates:
    //   Constant: '<S10>/One1'
    //   Gain: '<S10>/Gain1'
    //   Sum: '<S10>/Add1'

    rtb_fin_cmd_idx_0 = static_cast<real32_T>(floor(static_cast<real_T>
      (PixBlock_P.Gain1_Gain * rtb_z + PixBlock_P.One1_Value_a)));
    if (rtIsNaNF(rtb_fin_cmd_idx_0) || rtIsInfF(rtb_fin_cmd_idx_0)) {
      rtb_fin_cmd_idx_0 = 0.0F;
    } else {
      rtb_fin_cmd_idx_0 = static_cast<real32_T>(fmod(static_cast<real_T>
        (rtb_fin_cmd_idx_0), 65536.0));
    }

    // MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double1'

    PixBlock_B.pwmValue[1] = static_cast<uint16_T>(rtb_fin_cmd_idx_0 < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_fin_cmd_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_fin_cmd_idx_0)));

    // Gain: '<S20>/Gain'
    rtb_z = PixBlock_P.Gain_Gain_p * PixBlock_B.siB_cmd[2];

    // Saturate: '<S10>/Saturation2'
    if (rtb_z > PixBlock_P.Saturation2_UpperSat) {
      rtb_z = PixBlock_P.Saturation2_UpperSat;
    } else if (rtb_z < PixBlock_P.Saturation2_LowerSat) {
      rtb_z = PixBlock_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S10>/Saturation2'

    // DataTypeConversion: '<S10>/Cast To Double2' incorporates:
    //   Constant: '<S10>/One2'
    //   Gain: '<S10>/Gain2'
    //   Sum: '<S10>/Add2'

    rtb_fin_cmd_idx_0 = static_cast<real32_T>(floor(static_cast<real_T>
      (PixBlock_P.Gain2_Gain * rtb_z + PixBlock_P.One2_Value_k)));
    if (rtIsNaNF(rtb_fin_cmd_idx_0) || rtIsInfF(rtb_fin_cmd_idx_0)) {
      rtb_fin_cmd_idx_0 = 0.0F;
    } else {
      rtb_fin_cmd_idx_0 = static_cast<real32_T>(fmod(static_cast<real_T>
        (rtb_fin_cmd_idx_0), 65536.0));
    }

    // MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double2'

    PixBlock_B.pwmValue[2] = static_cast<uint16_T>(rtb_fin_cmd_idx_0 < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_fin_cmd_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_fin_cmd_idx_0)));

    // Gain: '<S21>/Gain'
    rtb_z = PixBlock_P.Gain_Gain_g * PixBlock_B.siB_cmd[3];

    // Saturate: '<S10>/Saturation3'
    if (rtb_z > PixBlock_P.Saturation3_UpperSat) {
      rtb_z = PixBlock_P.Saturation3_UpperSat;
    } else if (rtb_z < PixBlock_P.Saturation3_LowerSat) {
      rtb_z = PixBlock_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S10>/Saturation3'

    // DataTypeConversion: '<S10>/Cast To Double3' incorporates:
    //   Constant: '<S10>/One3'
    //   Gain: '<S10>/Gain3'
    //   Sum: '<S10>/Add3'

    rtb_fin_cmd_idx_0 = static_cast<real32_T>(floor(static_cast<real_T>
      (PixBlock_P.Gain3_Gain * rtb_z + PixBlock_P.One3_Value_o)));
    if (rtIsNaNF(rtb_fin_cmd_idx_0) || rtIsInfF(rtb_fin_cmd_idx_0)) {
      rtb_fin_cmd_idx_0 = 0.0F;
    } else {
      rtb_fin_cmd_idx_0 = static_cast<real32_T>(fmod(static_cast<real_T>
        (rtb_fin_cmd_idx_0), 65536.0));
    }

    // MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   Constant: '<S10>/One4'
    //   DataTypeConversion: '<S10>/Cast To Double3'
    //   Delay: '<S17>/Delay'
    //   Inport: '<Root>/Serial In'
    //   Logic: '<S10>/AND'
    //   RelationalOperator: '<S17>/GreaterThan'

    PixBlock_B.pwmValue[3] = static_cast<uint16_T>(rtb_fin_cmd_idx_0 < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_fin_cmd_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_fin_cmd_idx_0)));
    if ((PixBlock_U.send[0] != 0.0F) && (PixBlock_U.send[1] >
         PixBlock_DW.Delay_DSTATE_l)) {
      if (!PixBlock_DW.obj.isArmed) {
        PixBlock_DW.obj.isArmed = true;
        status = pwm_arm(&PixBlock_DW.obj.pwmDevHandler,
                         &PixBlock_DW.obj.armAdvertiseObj);
        PixBlock_DW.obj.errorStatus = static_cast<uint16_T>
          (PixBlock_DW.obj.errorStatus | status);
      }

      status = pwm_setServo(&PixBlock_DW.obj.pwmDevHandler,
                            PixBlock_DW.obj.servoCount,
                            PixBlock_DW.obj.channelMask, &PixBlock_B.pwmValue[0],
                            PixBlock_DW.obj.isMain,
                            &PixBlock_DW.obj.actuatorAdvertiseObj);
      PixBlock_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock_DW.obj.errorStatus | status);
    } else {
      status = pwm_disarm(&PixBlock_DW.obj.pwmDevHandler,
                          &PixBlock_DW.obj.armAdvertiseObj);
      PixBlock_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock_DW.obj.errorStatus | status);
      PixBlock_DW.obj.isArmed = false;
      status = pwm_resetServo(&PixBlock_DW.obj.pwmDevHandler,
        PixBlock_DW.obj.servoCount, PixBlock_DW.obj.channelMask,
        PixBlock_DW.obj.isMain, &PixBlock_DW.obj.actuatorAdvertiseObj);
      PixBlock_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock_DW.obj.errorStatus | status);
    }

    if (PixBlock_DW.obj.isMain) {
      status = pwm_forceFailsafe(&PixBlock_DW.obj.pwmDevHandler,
        static_cast<int32_T>(PixBlock_P.One4_Value_p));
      PixBlock_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock_DW.obj.errorStatus | status);
    }

    // Update for Delay: '<S14>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    PixBlock_DW.Delay_DSTATE = PixBlock_U.send[1];

    // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Lookup_n-D: '<S13>/1-D Lookup Table4'
    //   Product: '<S12>/Product3'
    //   Sqrt: '<S11>/Square Root'

    PixBlock_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
    PixBlock_DW.DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
      (rtb_GreaterThan);
    PixBlock_DW.DiscreteTimeIntegrator_PREV_U = look2_iflf_binlcapw(rtb_Ki_phi,
      rtb_SquareRoot, PixBlock_P.uDLookupTable4_bp01Data,
      PixBlock_P.uDLookupTable4_bp02Data, PixBlock_P.uDLookupTable4_tableData,
      PixBlock_P.uDLookupTable4_maxIndex, 3U) * rtb_Sum3;

    // Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
    PixBlock_DW.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

    // Update for Delay: '<S17>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    PixBlock_DW.Delay_DSTATE_l = PixBlock_U.send[1];
  }

  // End of Outputs for SubSystem: '<S1>/Emulated Pixhawk1'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.001, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  PixBlock_M->Timing.clockTick0++;
}

// Model initialize function
void PixBlock_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    boolean_T rtb_AND;
    PixBlock_PrevZCX.EmulatedPixhawk1_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // SystemInitialize for Triggered SubSystem: '<S1>/Emulated Pixhawk1'
    // InitializeConditions for Delay: '<S14>/Delay'
    PixBlock_DW.Delay_DSTATE = PixBlock_P.Delay_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S12>/Constant'

    PixBlock_DW.DiscreteTimeIntegrator_DSTATE = PixBlock_P.Constant_Value;

    // InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' 
    PixBlock_DW.DiscreteTransferFcn_states =
      PixBlock_P.DiscreteTransferFcn_InitialStates;

    // InitializeConditions for Delay: '<S17>/Delay'
    PixBlock_DW.Delay_DSTATE_l = PixBlock_P.Delay_InitialCondition_g;

    // Start for MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   Constant: '<S10>/One4'

    PixBlock_DW.obj.errorStatus = 0U;
    PixBlock_DW.obj.isInitialized = 0;
    PixBlock_DW.obj.matlabCodegenIsDeleted = false;
    PixBlock_SystemCore_setup(&PixBlock_DW.obj, rtb_AND, PixBlock_P.One4_Value_p);
    for (i = 0; i < 18; i++) {
      // SystemInitialize for Outport: '<Root>/Serial Out' incorporates:
      //   Outport: '<S2>/Serial Out'

      PixBlock_Y.SerialOut[i] = PixBlock_P.SerialOut_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S1>/Emulated Pixhawk1'

    // Enable for Triggered SubSystem: '<S1>/Emulated Pixhawk1'
    PixBlock_DW.EmulatedPixhawk1_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
    PixBlock_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;

    // End of Enable for SubSystem: '<S1>/Emulated Pixhawk1'
  }
}

// Model terminate function
void PixBlock_terminate(void)
{
  uint16_T status;

  // Terminate for Triggered SubSystem: '<S1>/Emulated Pixhawk1'
  // Terminate for MATLABSystem: '<S10>/PX4 PWM Output1'
  if (!PixBlock_DW.obj.matlabCodegenIsDeleted) {
    PixBlock_DW.obj.matlabCodegenIsDeleted = true;
    if ((PixBlock_DW.obj.isInitialized == 1) && PixBlock_DW.obj.isSetupComplete)
    {
      status = pwm_disarm(&PixBlock_DW.obj.pwmDevHandler,
                          &PixBlock_DW.obj.armAdvertiseObj);
      PixBlock_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock_DW.obj.errorStatus | status);
      status = pwm_resetServo(&PixBlock_DW.obj.pwmDevHandler,
        PixBlock_DW.obj.servoCount, PixBlock_DW.obj.channelMask,
        PixBlock_DW.obj.isMain, &PixBlock_DW.obj.actuatorAdvertiseObj);
      PixBlock_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock_DW.obj.errorStatus | status);
      status = pwm_close(&PixBlock_DW.obj.pwmDevHandler,
                         &PixBlock_DW.obj.actuatorAdvertiseObj,
                         &PixBlock_DW.obj.armAdvertiseObj);
      PixBlock_DW.obj.errorStatus = static_cast<uint16_T>
        (PixBlock_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S10>/PX4 PWM Output1'
  // End of Terminate for SubSystem: '<S1>/Emulated Pixhawk1'
}

//
// File trailer for generated code.
//
// [EOF]
//
