//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Pixhawk.cpp
//
// Code generated for Simulink model 'Pixhawk'.
//
// Model version                  : 4.14
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Apr  9 18:43:59 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Pixhawk.h"
#include "Pixhawk_private.h"

// Block signals (default storage)
B_Pixhawk_T Pixhawk_B;

// Block states (default storage)
DW_Pixhawk_T Pixhawk_DW;

// Previous zero-crossings (trigger) states
PrevZCX_Pixhawk_T Pixhawk_PrevZCX;

// External inputs (root inport signals with default storage)
ExtU_Pixhawk_T Pixhawk_U;

// External outputs (root outports fed by signals with default storage)
ExtY_Pixhawk_T Pixhawk_Y;

// Real-time model
RT_MODEL_Pixhawk_T Pixhawk_M_ = RT_MODEL_Pixhawk_T();
RT_MODEL_Pixhawk_T *const Pixhawk_M = &Pixhawk_M_;

// Forward declaration for local functions
static void Pixhawk_SystemCore_setup(px4_internal_block_PWM_Pixhawk_T *obj,
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

static void Pixhawk_SystemCore_setup(px4_internal_block_PWM_Pixhawk_T *obj,
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
void Pixhawk_step(void)
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
  rtb_u00Hz1 = (Pixhawk_DW.clockTickCounter < Pixhawk_P.u00Hz1_Duty) &&
    (Pixhawk_DW.clockTickCounter >= 0) ? Pixhawk_P.u00Hz1_Amp : 0.0;
  if (Pixhawk_DW.clockTickCounter >= Pixhawk_P.u00Hz1_Period - 1.0) {
    Pixhawk_DW.clockTickCounter = 0;
  } else {
    Pixhawk_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S1>/100 Hz1'

  // Outputs for Triggered SubSystem: '<S1>/Emulated Pixhawk1' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Pixhawk_PrevZCX.EmulatedPixhawk1_Trig_ZCE,
                     (rtb_u00Hz1));
  if (zcEvent != NO_ZCEVENT) {
    if (Pixhawk_DW.EmulatedPixhawk1_RESET_ELAPS_T) {
      EmulatedPixhawk1_ELAPS_T = 0U;
    } else {
      EmulatedPixhawk1_ELAPS_T = Pixhawk_M->Timing.clockTick0 -
        Pixhawk_DW.EmulatedPixhawk1_PREV_T;
    }

    Pixhawk_DW.EmulatedPixhawk1_PREV_T = Pixhawk_M->Timing.clockTick0;
    Pixhawk_DW.EmulatedPixhawk1_RESET_ELAPS_T = false;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[0] = Pixhawk_U.send[1];

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One5'
    //   Inport: '<Root>/Serial In'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_6_Threshold) {
      rtb_z = Pixhawk_P.One5_Value;
    } else {
      rtb_z = Pixhawk_U.send[9];
    }

    // Gain: '<S3>/Gain'
    rtb_Ki_phi = Pixhawk_P.Gain_Gain * rtb_z;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One'
    //   Inport: '<Root>/Serial In'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_1_Threshold) {
      rtb_u = Pixhawk_P.One_Value;
    } else {
      rtb_u = Pixhawk_U.send[4];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One1'
    //   Inport: '<Root>/Serial In'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_2_Threshold) {
      rtb_v = Pixhawk_P.One1_Value;
    } else {
      rtb_v = Pixhawk_U.send[5];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One2'
    //   Inport: '<Root>/Serial In'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_3_Threshold) {
      rtb_w = Pixhawk_P.One2_Value;
    } else {
      rtb_w = Pixhawk_U.send[6];
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

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_10_Threshold) {
      rtb_fin_cmd_idx_0 = Pixhawk_P.One9_Value;
    } else {
      rtb_fin_cmd_idx_0 = Pixhawk_U.send[19];
    }

    // Sum: '<S12>/Sum3' incorporates:
    //   Inport: '<Root>/Serial In'

    rtb_Sum3 = Pixhawk_U.send[22] - rtb_fin_cmd_idx_0;

    // RelationalOperator: '<S14>/GreaterThan' incorporates:
    //   Delay: '<S14>/Delay'
    //   Inport: '<Root>/Serial In'

    rtb_GreaterThan = (Pixhawk_U.send[1] < Pixhawk_DW.Delay_DSTATE);

    // DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S12>/Constant'

    if (Pixhawk_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE == 0) {
      if (rtb_GreaterThan || (Pixhawk_DW.DiscreteTimeIntegrator_PrevResetState
                              != 0)) {
        Pixhawk_DW.DiscreteTimeIntegrator_DSTATE = Pixhawk_P.Constant_Value;
      } else {
        // DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
        Pixhawk_DW.DiscreteTimeIntegrator_DSTATE +=
          Pixhawk_P.DiscreteTimeIntegrator_gainval * static_cast<real32_T>
          (EmulatedPixhawk1_ELAPS_T) * Pixhawk_DW.DiscreteTimeIntegrator_PREV_U;
      }
    }

    // End of DiscreteIntegrator: '<S12>/Discrete-Time Integrator'

    // DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' incorporates:
    //   Inport: '<Root>/Serial In'

    DiscreteTransferFcn_tmp = (Pixhawk_U.send[16] -
      Pixhawk_P.DiscreteTransferFcn_DenCoef[1] *
      Pixhawk_DW.DiscreteTransferFcn_states) /
      Pixhawk_P.DiscreteTransferFcn_DenCoef[0];

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One6'
    //   Inport: '<Root>/Serial In'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_7_Threshold) {
      rtb_Add3 = Pixhawk_P.One6_Value;
    } else {
      rtb_Add3 = Pixhawk_U.send[10];
    }

    // ManualSwitch: '<S3>/Manual Switch' incorporates:
    //   DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'

    if (Pixhawk_P.ManualSwitch_CurrentSetting == 1) {
      rtb_fin_cmd_idx_0 = Pixhawk_P.DiscreteTransferFcn_NumCoef[0] *
        DiscreteTransferFcn_tmp + Pixhawk_P.DiscreteTransferFcn_NumCoef[1] *
        Pixhawk_DW.DiscreteTransferFcn_states;
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
      Pixhawk_P.uDLookupTable5_bp01Data, Pixhawk_P.uDLookupTable5_bp02Data,
      Pixhawk_P.uDLookupTable5_tableData, Pixhawk_P.uDLookupTable5_maxIndex, 3U)
                          * rtb_Sum3 + Pixhawk_DW.DiscreteTimeIntegrator_DSTATE)
                         - rtb_fin_cmd_idx_0) * look2_iflf_binlcapw(rtb_Ki_phi,
      rtb_SquareRoot, Pixhawk_P.uDLookupTable3_bp01Data,
      Pixhawk_P.uDLookupTable3_bp02Data, Pixhawk_P.uDLookupTable3_tableData,
      Pixhawk_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S15>/Product' incorporates:
    //   Constant: '<S15>/Constant7'
    //   Constant: '<S3>/Zero'

    for (i = 0; i < 4; i++) {
      Pixhawk_B.siB_cmd[i] = Pixhawk_P.Constant7_Value[i + 8] *
        Pixhawk_P.Zero_Value + (Pixhawk_P.Constant7_Value[i + 4] *
        Pixhawk_P.Zero_Value + Pixhawk_P.Constant7_Value[i] * rtb_fin_cmd_idx_0);
    }

    // End of Product: '<S15>/Product'

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[1] = Pixhawk_B.siB_cmd[0];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[2] = Pixhawk_B.siB_cmd[1];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[3] = Pixhawk_B.siB_cmd[2];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[4] = Pixhawk_B.siB_cmd[3];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[5] = Pixhawk_U.send[16];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[6] = Pixhawk_U.send[17];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[7] = Pixhawk_U.send[18];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[8] = rtb_u;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[9] = rtb_v;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[10] = rtb_w;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One3'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_4_Threshold) {
      Pixhawk_Y.SerialOut[11] = Pixhawk_P.One3_Value;
    } else {
      Pixhawk_Y.SerialOut[11] = Pixhawk_U.send[7];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One4'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_5_Threshold) {
      Pixhawk_Y.SerialOut[12] = Pixhawk_P.One4_Value;
    } else {
      Pixhawk_Y.SerialOut[12] = Pixhawk_U.send[8];
    }

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[13] = rtb_z;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[14] = rtb_Add3;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One7'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_8_Threshold) {
      Pixhawk_Y.SerialOut[15] = Pixhawk_P.One7_Value;
    } else {
      Pixhawk_Y.SerialOut[15] = Pixhawk_U.send[11];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S16>/One8'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (Pixhawk_U.send[2] > Pixhawk_P.Switch_9_Threshold) {
      Pixhawk_Y.SerialOut[16] = Pixhawk_P.One8_Value;
    } else {
      Pixhawk_Y.SerialOut[16] = Pixhawk_U.send[12];
    }

    // Constant: '<S2>/Zero' incorporates:
    //   Outport: '<Root>/Serial Out'

    Pixhawk_Y.SerialOut[17] = Pixhawk_P.Zero_Value_f;

    // MATLABSystem: '<S10>/PX4 PWM Output1'
    for (i = 0; i < 8; i++) {
      Pixhawk_B.pwmValue[i] = 0U;
    }

    // Gain: '<S18>/Gain'
    rtb_z = Pixhawk_P.Gain_Gain_j * Pixhawk_B.siB_cmd[0];

    // Saturate: '<S10>/Saturation'
    if (rtb_z > Pixhawk_P.Saturation_UpperSat) {
      rtb_z = Pixhawk_P.Saturation_UpperSat;
    } else if (rtb_z < Pixhawk_P.Saturation_LowerSat) {
      rtb_z = Pixhawk_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S10>/Saturation'

    // DataTypeConversion: '<S10>/Cast To Double' incorporates:
    //   Constant: '<S10>/One'
    //   Gain: '<S10>/Gain'
    //   Sum: '<S10>/Add'

    rtb_fin_cmd_idx_0 = static_cast<real32_T>(floor(static_cast<real_T>
      (Pixhawk_P.Gain_Gain_o * rtb_z + Pixhawk_P.One_Value_a)));
    if (rtIsNaNF(rtb_fin_cmd_idx_0) || rtIsInfF(rtb_fin_cmd_idx_0)) {
      rtb_fin_cmd_idx_0 = 0.0F;
    } else {
      rtb_fin_cmd_idx_0 = static_cast<real32_T>(fmod(static_cast<real_T>
        (rtb_fin_cmd_idx_0), 65536.0));
    }

    // MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double'

    Pixhawk_B.pwmValue[0] = static_cast<uint16_T>(rtb_fin_cmd_idx_0 < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_fin_cmd_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_fin_cmd_idx_0)));

    // Gain: '<S19>/Gain'
    rtb_z = Pixhawk_P.Gain_Gain_os * Pixhawk_B.siB_cmd[1];

    // Saturate: '<S10>/Saturation1'
    if (rtb_z > Pixhawk_P.Saturation1_UpperSat) {
      rtb_z = Pixhawk_P.Saturation1_UpperSat;
    } else if (rtb_z < Pixhawk_P.Saturation1_LowerSat) {
      rtb_z = Pixhawk_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S10>/Saturation1'

    // DataTypeConversion: '<S10>/Cast To Double1' incorporates:
    //   Constant: '<S10>/One1'
    //   Gain: '<S10>/Gain1'
    //   Sum: '<S10>/Add1'

    rtb_fin_cmd_idx_0 = static_cast<real32_T>(floor(static_cast<real_T>
      (Pixhawk_P.Gain1_Gain * rtb_z + Pixhawk_P.One1_Value_a)));
    if (rtIsNaNF(rtb_fin_cmd_idx_0) || rtIsInfF(rtb_fin_cmd_idx_0)) {
      rtb_fin_cmd_idx_0 = 0.0F;
    } else {
      rtb_fin_cmd_idx_0 = static_cast<real32_T>(fmod(static_cast<real_T>
        (rtb_fin_cmd_idx_0), 65536.0));
    }

    // MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double1'

    Pixhawk_B.pwmValue[1] = static_cast<uint16_T>(rtb_fin_cmd_idx_0 < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_fin_cmd_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_fin_cmd_idx_0)));

    // Gain: '<S20>/Gain'
    rtb_z = Pixhawk_P.Gain_Gain_p * Pixhawk_B.siB_cmd[2];

    // Saturate: '<S10>/Saturation2'
    if (rtb_z > Pixhawk_P.Saturation2_UpperSat) {
      rtb_z = Pixhawk_P.Saturation2_UpperSat;
    } else if (rtb_z < Pixhawk_P.Saturation2_LowerSat) {
      rtb_z = Pixhawk_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S10>/Saturation2'

    // DataTypeConversion: '<S10>/Cast To Double2' incorporates:
    //   Constant: '<S10>/One2'
    //   Gain: '<S10>/Gain2'
    //   Sum: '<S10>/Add2'

    rtb_fin_cmd_idx_0 = static_cast<real32_T>(floor(static_cast<real_T>
      (Pixhawk_P.Gain2_Gain * rtb_z + Pixhawk_P.One2_Value_k)));
    if (rtIsNaNF(rtb_fin_cmd_idx_0) || rtIsInfF(rtb_fin_cmd_idx_0)) {
      rtb_fin_cmd_idx_0 = 0.0F;
    } else {
      rtb_fin_cmd_idx_0 = static_cast<real32_T>(fmod(static_cast<real_T>
        (rtb_fin_cmd_idx_0), 65536.0));
    }

    // MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S10>/Cast To Double2'

    Pixhawk_B.pwmValue[2] = static_cast<uint16_T>(rtb_fin_cmd_idx_0 < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_fin_cmd_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_fin_cmd_idx_0)));

    // Gain: '<S21>/Gain'
    rtb_z = Pixhawk_P.Gain_Gain_g * Pixhawk_B.siB_cmd[3];

    // Saturate: '<S10>/Saturation3'
    if (rtb_z > Pixhawk_P.Saturation3_UpperSat) {
      rtb_z = Pixhawk_P.Saturation3_UpperSat;
    } else if (rtb_z < Pixhawk_P.Saturation3_LowerSat) {
      rtb_z = Pixhawk_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S10>/Saturation3'

    // DataTypeConversion: '<S10>/Cast To Double3' incorporates:
    //   Constant: '<S10>/One3'
    //   Gain: '<S10>/Gain3'
    //   Sum: '<S10>/Add3'

    rtb_fin_cmd_idx_0 = static_cast<real32_T>(floor(static_cast<real_T>
      (Pixhawk_P.Gain3_Gain * rtb_z + Pixhawk_P.One3_Value_o)));
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

    Pixhawk_B.pwmValue[3] = static_cast<uint16_T>(rtb_fin_cmd_idx_0 < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_fin_cmd_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(rtb_fin_cmd_idx_0)));
    if ((Pixhawk_U.send[0] != 0.0F) && (Pixhawk_U.send[1] >
         Pixhawk_DW.Delay_DSTATE_l)) {
      if (!Pixhawk_DW.obj.isArmed) {
        Pixhawk_DW.obj.isArmed = true;
        status = pwm_arm(&Pixhawk_DW.obj.pwmDevHandler,
                         &Pixhawk_DW.obj.armAdvertiseObj);
        Pixhawk_DW.obj.errorStatus = static_cast<uint16_T>
          (Pixhawk_DW.obj.errorStatus | status);
      }

      status = pwm_setServo(&Pixhawk_DW.obj.pwmDevHandler,
                            Pixhawk_DW.obj.servoCount,
                            Pixhawk_DW.obj.channelMask, &Pixhawk_B.pwmValue[0],
                            Pixhawk_DW.obj.isMain,
                            &Pixhawk_DW.obj.actuatorAdvertiseObj);
      Pixhawk_DW.obj.errorStatus = static_cast<uint16_T>
        (Pixhawk_DW.obj.errorStatus | status);
    } else {
      status = pwm_disarm(&Pixhawk_DW.obj.pwmDevHandler,
                          &Pixhawk_DW.obj.armAdvertiseObj);
      Pixhawk_DW.obj.errorStatus = static_cast<uint16_T>
        (Pixhawk_DW.obj.errorStatus | status);
      Pixhawk_DW.obj.isArmed = false;
      status = pwm_resetServo(&Pixhawk_DW.obj.pwmDevHandler,
        Pixhawk_DW.obj.servoCount, Pixhawk_DW.obj.channelMask,
        Pixhawk_DW.obj.isMain, &Pixhawk_DW.obj.actuatorAdvertiseObj);
      Pixhawk_DW.obj.errorStatus = static_cast<uint16_T>
        (Pixhawk_DW.obj.errorStatus | status);
    }

    if (Pixhawk_DW.obj.isMain) {
      status = pwm_forceFailsafe(&Pixhawk_DW.obj.pwmDevHandler,
        static_cast<int32_T>(Pixhawk_P.One4_Value_p));
      Pixhawk_DW.obj.errorStatus = static_cast<uint16_T>
        (Pixhawk_DW.obj.errorStatus | status);
    }

    // Update for Delay: '<S14>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    Pixhawk_DW.Delay_DSTATE = Pixhawk_U.send[1];

    // Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Lookup_n-D: '<S13>/1-D Lookup Table4'
    //   Product: '<S12>/Product3'
    //   Sqrt: '<S11>/Square Root'

    Pixhawk_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
    Pixhawk_DW.DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
      (rtb_GreaterThan);
    Pixhawk_DW.DiscreteTimeIntegrator_PREV_U = look2_iflf_binlcapw(rtb_Ki_phi,
      rtb_SquareRoot, Pixhawk_P.uDLookupTable4_bp01Data,
      Pixhawk_P.uDLookupTable4_bp02Data, Pixhawk_P.uDLookupTable4_tableData,
      Pixhawk_P.uDLookupTable4_maxIndex, 3U) * rtb_Sum3;

    // Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
    Pixhawk_DW.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

    // Update for Delay: '<S17>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    Pixhawk_DW.Delay_DSTATE_l = Pixhawk_U.send[1];
  }

  // End of Outputs for SubSystem: '<S1>/Emulated Pixhawk1'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.001, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  Pixhawk_M->Timing.clockTick0++;
}

// Model initialize function
void Pixhawk_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    boolean_T rtb_AND;
    Pixhawk_PrevZCX.EmulatedPixhawk1_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // SystemInitialize for Triggered SubSystem: '<S1>/Emulated Pixhawk1'
    // InitializeConditions for Delay: '<S14>/Delay'
    Pixhawk_DW.Delay_DSTATE = Pixhawk_P.Delay_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S12>/Constant'

    Pixhawk_DW.DiscreteTimeIntegrator_DSTATE = Pixhawk_P.Constant_Value;

    // InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' 
    Pixhawk_DW.DiscreteTransferFcn_states =
      Pixhawk_P.DiscreteTransferFcn_InitialStates;

    // InitializeConditions for Delay: '<S17>/Delay'
    Pixhawk_DW.Delay_DSTATE_l = Pixhawk_P.Delay_InitialCondition_g;

    // Start for MATLABSystem: '<S10>/PX4 PWM Output1' incorporates:
    //   Constant: '<S10>/One4'

    Pixhawk_DW.obj.errorStatus = 0U;
    Pixhawk_DW.obj.isInitialized = 0;
    Pixhawk_DW.obj.matlabCodegenIsDeleted = false;
    Pixhawk_SystemCore_setup(&Pixhawk_DW.obj, rtb_AND, Pixhawk_P.One4_Value_p);
    for (i = 0; i < 18; i++) {
      // SystemInitialize for Outport: '<Root>/Serial Out' incorporates:
      //   Outport: '<S2>/Serial Out'

      Pixhawk_Y.SerialOut[i] = Pixhawk_P.SerialOut_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S1>/Emulated Pixhawk1'

    // Enable for Triggered SubSystem: '<S1>/Emulated Pixhawk1'
    Pixhawk_DW.EmulatedPixhawk1_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S12>/Discrete-Time Integrator'
    Pixhawk_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;

    // End of Enable for SubSystem: '<S1>/Emulated Pixhawk1'
  }
}

// Model terminate function
void Pixhawk_terminate(void)
{
  uint16_T status;

  // Terminate for Triggered SubSystem: '<S1>/Emulated Pixhawk1'
  // Terminate for MATLABSystem: '<S10>/PX4 PWM Output1'
  if (!Pixhawk_DW.obj.matlabCodegenIsDeleted) {
    Pixhawk_DW.obj.matlabCodegenIsDeleted = true;
    if ((Pixhawk_DW.obj.isInitialized == 1) && Pixhawk_DW.obj.isSetupComplete) {
      status = pwm_disarm(&Pixhawk_DW.obj.pwmDevHandler,
                          &Pixhawk_DW.obj.armAdvertiseObj);
      Pixhawk_DW.obj.errorStatus = static_cast<uint16_T>
        (Pixhawk_DW.obj.errorStatus | status);
      status = pwm_resetServo(&Pixhawk_DW.obj.pwmDevHandler,
        Pixhawk_DW.obj.servoCount, Pixhawk_DW.obj.channelMask,
        Pixhawk_DW.obj.isMain, &Pixhawk_DW.obj.actuatorAdvertiseObj);
      Pixhawk_DW.obj.errorStatus = static_cast<uint16_T>
        (Pixhawk_DW.obj.errorStatus | status);
      status = pwm_close(&Pixhawk_DW.obj.pwmDevHandler,
                         &Pixhawk_DW.obj.actuatorAdvertiseObj,
                         &Pixhawk_DW.obj.armAdvertiseObj);
      Pixhawk_DW.obj.errorStatus = static_cast<uint16_T>
        (Pixhawk_DW.obj.errorStatus | status);
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
