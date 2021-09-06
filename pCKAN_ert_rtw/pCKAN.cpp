//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pCKAN.cpp
//
// Code generated for Simulink model 'pCKAN'.
//
// Model version                  : 4.46
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed May  5 00:00:29 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pCKAN.h"
#include "pCKAN_private.h"

// Block signals (default storage)
B_pCKAN_T pCKAN_B;

// Block states (default storage)
DW_pCKAN_T pCKAN_DW;

// Previous zero-crossings (trigger) states
PrevZCX_pCKAN_T pCKAN_PrevZCX;

// External inputs (root inport signals with default storage)
ExtU_pCKAN_T pCKAN_U;

// External outputs (root outports fed by signals with default storage)
ExtY_pCKAN_T pCKAN_Y;

// Real-time model
RT_MODEL_pCKAN_T pCKAN_M_ = RT_MODEL_pCKAN_T();
RT_MODEL_pCKAN_T *const pCKAN_M = &pCKAN_M_;

// Forward declaration for local functions
static void pCKAN_SystemCore_setup(px4_internal_block_PWM_pCKAN_T *obj,
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

static void pCKAN_SystemCore_setup(px4_internal_block_PWM_pCKAN_T *obj,
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
void pCKAN_step(void)
{
  c_dsp_private_SlidingWindowAverageCG_pCKAN_T *obj;
  int32_T i;
  real32_T DiscreteTransferFcn3_tmp;
  real32_T rtb_Gain1;
  real32_T rtb_Ki_phi;
  real32_T rtb_Sum3;
  real32_T rtb_fin_cmd_idx_0;
  real32_T rtb_p;
  real32_T rtb_v;
  real32_T rtb_w;
  real32_T rtb_z;
  uint32_T EmulatedPixhawk_ELAPS_T;
  uint16_T status;
  boolean_T rtb_GreaterThan;
  boolean_T rtb_MECO_log;
  boolean_T rtb_Memory;
  boolean_T rtb_NOT;
  boolean_T rtb_NOT_d;
  boolean_T rtb_NOT_e;
  boolean_T rtb_recovery_log;

  // DiscretePulseGenerator: '<S1>/100 Hz'
  pCKAN_B.u00Hz = (pCKAN_DW.clockTickCounter < pCKAN_P.u00Hz_Duty) &&
    (pCKAN_DW.clockTickCounter >= 0) ? pCKAN_P.u00Hz_Amp : 0.0;
  if (pCKAN_DW.clockTickCounter >= pCKAN_P.u00Hz_Period - 1.0) {
    pCKAN_DW.clockTickCounter = 0;
  } else {
    pCKAN_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S1>/100 Hz'

  // Outputs for Triggered SubSystem: '<S1>/Emulated Pixhawk' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  pCKAN_B.zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
    &pCKAN_PrevZCX.EmulatedPixhawk_Trig_ZCE,
    (pCKAN_B.u00Hz));
  if (pCKAN_B.zcEvent != NO_ZCEVENT) {
    if (pCKAN_DW.EmulatedPixhawk_RESET_ELAPS_T) {
      EmulatedPixhawk_ELAPS_T = 0U;
    } else {
      EmulatedPixhawk_ELAPS_T = pCKAN_M->Timing.clockTick0 -
        pCKAN_DW.EmulatedPixhawk_PREV_T;
    }

    pCKAN_DW.EmulatedPixhawk_PREV_T = pCKAN_M->Timing.clockTick0;
    pCKAN_DW.EmulatedPixhawk_RESET_ELAPS_T = false;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[0] = pCKAN_U.SerialIn[1];

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One'
    //   Inport: '<Root>/Serial In'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_1_Threshold) {
      pCKAN_B.u = pCKAN_P.One_Value;
    } else {
      pCKAN_B.u = pCKAN_U.SerialIn[4];
    }

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One1'
    //   Inport: '<Root>/Serial In'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_2_Threshold) {
      rtb_v = pCKAN_P.One1_Value;
    } else {
      rtb_v = pCKAN_U.SerialIn[5];
    }

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One2'
    //   Inport: '<Root>/Serial In'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_3_Threshold) {
      rtb_w = pCKAN_P.One2_Value;
    } else {
      rtb_w = pCKAN_U.SerialIn[6];
    }

    // Sqrt: '<S9>/Square Root' incorporates:
    //   Math: '<S9>/Square'
    //   Math: '<S9>/Square1'
    //   Math: '<S9>/Square2'
    //   Sum: '<S9>/Add'

    rtb_Ki_phi = static_cast<real32_T>(sqrt(static_cast<real_T>((pCKAN_B.u *
      pCKAN_B.u + rtb_v * rtb_v) + rtb_w * rtb_w)));

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One5'
    //   Inport: '<Root>/Serial In'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_6_Threshold) {
      rtb_z = pCKAN_P.One5_Value_o;
    } else {
      rtb_z = pCKAN_U.SerialIn[9];
    }

    // Gain: '<S3>/Gain1'
    rtb_Gain1 = pCKAN_P.Gain1_Gain * rtb_z;

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One9'
    //   Inport: '<Root>/Serial In'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_10_Threshold) {
      rtb_p = pCKAN_P.One9_Value;
    } else {
      rtb_p = pCKAN_U.SerialIn[19];
    }

    // Sum: '<S14>/Sum3' incorporates:
    //   Inport: '<Root>/Serial In'

    rtb_Sum3 = pCKAN_U.SerialIn[22] - rtb_p;

    // RelationalOperator: '<S47>/GreaterThan' incorporates:
    //   Delay: '<S47>/Delay'
    //   Inport: '<Root>/Serial In'

    rtb_GreaterThan = (pCKAN_U.SerialIn[1] < pCKAN_DW.Delay_DSTATE);

    // DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S14>/Constant'

    if (pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE == 0) {
      if (rtb_GreaterThan || (pCKAN_DW.DiscreteTimeIntegrator_PrevResetState !=
                              0)) {
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE_n = pCKAN_P.Constant_Value_o;
      } else {
        // DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE_n +=
          pCKAN_P.DiscreteTimeIntegrator_gainval_m * static_cast<real32_T>
          (EmulatedPixhawk_ELAPS_T) * pCKAN_DW.DiscreteTimeIntegrator_PREV_U_jd;
      }
    }

    // End of DiscreteIntegrator: '<S14>/Discrete-Time Integrator'

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One6'
    //   Inport: '<Root>/Serial In'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_7_Threshold) {
      rtb_p = pCKAN_P.One6_Value_c;
    } else {
      rtb_p = pCKAN_U.SerialIn[10];
    }

    // DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn3'
    DiscreteTransferFcn3_tmp = (rtb_p - pCKAN_P.DiscreteTransferFcn3_DenCoef[1] *
      pCKAN_DW.DiscreteTransferFcn3_states) /
      pCKAN_P.DiscreteTransferFcn3_DenCoef[0];

    // Product: '<S14>/Product1' incorporates:
    //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn3'
    //   Gain: '<S3>/Gain1'
    //   Lookup_n-D: '<S41>/1-D Lookup Table3'
    //   Lookup_n-D: '<S41>/1-D Lookup Table4'
    //   Lookup_n-D: '<S41>/1-D Lookup Table5'
    //   Product: '<S14>/Product2'
    //   Sum: '<S14>/Sum4'
    //   Sum: '<S14>/Sum5'

    rtb_fin_cmd_idx_0 = ((look2_iflf_binlcapw(rtb_Gain1, rtb_Ki_phi,
      pCKAN_P.uDLookupTable5_bp01Data, pCKAN_P.uDLookupTable5_bp02Data,
      pCKAN_P.uDLookupTable5_tableData, pCKAN_P.uDLookupTable5_maxIndex, 3U) *
                          rtb_Sum3 + pCKAN_DW.DiscreteTimeIntegrator_DSTATE_n) -
                         (pCKAN_P.DiscreteTransferFcn3_NumCoef[0] *
                          DiscreteTransferFcn3_tmp +
                          pCKAN_P.DiscreteTransferFcn3_NumCoef[1] *
                          pCKAN_DW.DiscreteTransferFcn3_states)) *
      look2_iflf_binlcapw(rtb_Gain1, rtb_Ki_phi, pCKAN_P.uDLookupTable3_bp01Data,
                          pCKAN_P.uDLookupTable3_bp02Data,
                          pCKAN_P.uDLookupTable3_tableData,
                          pCKAN_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S16>/Product' incorporates:
    //   Constant: '<S14>/Zero'
    //   Constant: '<S16>/Constant7'

    for (i = 0; i < 4; i++) {
      pCKAN_B.siB_cmd[i] = pCKAN_P.Constant7_Value[i + 8] * pCKAN_P.Zero_Value +
        (pCKAN_P.Constant7_Value[i + 4] * pCKAN_P.Zero_Value +
         pCKAN_P.Constant7_Value[i] * rtb_fin_cmd_idx_0);
    }

    // End of Product: '<S16>/Product'

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[1] = pCKAN_B.siB_cmd[0];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[2] = pCKAN_B.siB_cmd[1];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[3] = pCKAN_B.siB_cmd[2];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[4] = pCKAN_B.siB_cmd[3];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[5] = pCKAN_U.SerialIn[16];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[6] = pCKAN_U.SerialIn[17];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[7] = pCKAN_U.SerialIn[18];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[8] = pCKAN_B.u;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[9] = rtb_v;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[10] = rtb_w;

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One3'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_4_Threshold) {
      pCKAN_Y.SerialOut[11] = pCKAN_P.One3_Value;
    } else {
      pCKAN_Y.SerialOut[11] = pCKAN_U.SerialIn[7];
    }

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One4'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_5_Threshold) {
      pCKAN_Y.SerialOut[12] = pCKAN_P.One4_Value;
    } else {
      pCKAN_Y.SerialOut[12] = pCKAN_U.SerialIn[8];
    }

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[13] = rtb_z;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[14] = rtb_p;

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One7'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_8_Threshold) {
      pCKAN_Y.SerialOut[15] = pCKAN_P.One7_Value;
    } else {
      pCKAN_Y.SerialOut[15] = pCKAN_U.SerialIn[11];
    }

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S48>/One8'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (pCKAN_U.SerialIn[2] > pCKAN_P.Switch_9_Threshold) {
      pCKAN_Y.SerialOut[16] = pCKAN_P.One8_Value;
    } else {
      pCKAN_Y.SerialOut[16] = pCKAN_U.SerialIn[12];
    }

    // Constant: '<S2>/Zero' incorporates:
    //   Outport: '<Root>/Serial Out'

    pCKAN_Y.SerialOut[17] = pCKAN_P.Zero_Value_a;

    // Gain: '<S46>/Gain'
    rtb_z = pCKAN_P.Gain_Gain_l * pCKAN_B.siB_cmd[3];

    // Saturate: '<S15>/Saturation3'
    if (rtb_z > pCKAN_P.Saturation3_UpperSat) {
      rtb_z = pCKAN_P.Saturation3_UpperSat;
    } else if (rtb_z < pCKAN_P.Saturation3_LowerSat) {
      rtb_z = pCKAN_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S15>/Saturation3'

    // DataTypeConversion: '<S15>/Cast To Double3' incorporates:
    //   Constant: '<S15>/One3'
    //   Gain: '<S15>/Gain3'
    //   Sum: '<S15>/Add3'

    rtb_p = static_cast<real32_T>(floor(static_cast<real_T>(pCKAN_P.Gain3_Gain *
      rtb_z + pCKAN_P.One3_Value_b)));
    if (rtIsNaNF(rtb_p) || rtIsInfF(rtb_p)) {
      rtb_p = 0.0F;
    } else {
      rtb_p = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_p), 65536.0));
    }

    // DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' incorporates:
    //   Inport: '<Root>/Serial In'

    pCKAN_B.u = (pCKAN_U.SerialIn[13] - pCKAN_P.DiscreteTransferFcn_DenCoef[1] *
                 pCKAN_DW.DiscreteTransferFcn_states) /
      pCKAN_P.DiscreteTransferFcn_DenCoef[0];
    rtb_v = pCKAN_P.DiscreteTransferFcn_NumCoef[0] * pCKAN_B.u +
      pCKAN_P.DiscreteTransferFcn_NumCoef[1] *
      pCKAN_DW.DiscreteTransferFcn_states;

    // RelationalOperator: '<S28>/Compare' incorporates:
    //   Constant: '<S28>/Constant'
    //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'

    rtb_Memory = (rtb_v >= pCKAN_P.CompareToConstant_const);

    // Logic: '<S30>/NOT' incorporates:
    //   Logic: '<S30>/AND'
    //   Memory: '<S19>/Memory'

    rtb_NOT = ((!rtb_Memory) && (!pCKAN_DW.Memory_PreviousInput));

    // DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S30>/Constant1'

    if (pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e == 0) {
      if (rtb_NOT || (pCKAN_DW.DiscreteTimeIntegrator_PrevResetState_i != 0)) {
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE = pCKAN_P.Constant1_Value_m;
      } else {
        // DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE +=
          pCKAN_P.DiscreteTimeIntegrator_gainval * static_cast<real_T>
          (EmulatedPixhawk_ELAPS_T) * pCKAN_DW.DiscreteTimeIntegrator_PREV_U;
      }
    }

    // End of DiscreteIntegrator: '<S30>/Discrete-Time Integrator'

    // Switch: '<S31>/Switch1' incorporates:
    //   Constant: '<S29>/Constant'
    //   Logic: '<S19>/AND'
    //   Memory: '<S31>/Memory'
    //   RelationalOperator: '<S29>/Compare'

    pCKAN_DW.Memory_PreviousInput = ((rtb_Memory &&
      (pCKAN_DW.DiscreteTimeIntegrator_DSTATE >=
       pCKAN_P.Flight_Logic.Ax_launch_timer_threshold_sec)) ||
      pCKAN_DW.Memory_PreviousInput_f);

    // Logic: '<S35>/NOT' incorporates:
    //   Constant: '<S33>/Constant'
    //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
    //   Logic: '<S20>/AND'
    //   RelationalOperator: '<S33>/Compare'

    rtb_Memory = ((!pCKAN_DW.Memory_PreviousInput) || (!(rtb_v <=
      pCKAN_P.CompareToConstant2_const)));

    // DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant1'

    if (pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d == 0) {
      if (rtb_Memory || (pCKAN_DW.DiscreteTimeIntegrator_PrevResetState_iw != 0))
      {
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE_p = pCKAN_P.Constant1_Value_f;
      } else {
        // DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE_p +=
          pCKAN_P.DiscreteTimeIntegrator_gainval_k * static_cast<real_T>
          (EmulatedPixhawk_ELAPS_T) * pCKAN_DW.DiscreteTimeIntegrator_PREV_U_a;
      }
    }

    // End of DiscreteIntegrator: '<S35>/Discrete-Time Integrator'

    // Switch: '<S36>/Switch1' incorporates:
    //   Constant: '<S32>/Constant'
    //   Memory: '<S36>/Memory'
    //   RelationalOperator: '<S32>/Compare'

    pCKAN_DW.Memory_PreviousInput_l = ((pCKAN_DW.DiscreteTimeIntegrator_DSTATE_p
      >= pCKAN_P.Flight_Logic.Ax_MECO_timer_threshold_sec) ||
      pCKAN_DW.Memory_PreviousInput_l);

    // Switch: '<S19>/Switch' incorporates:
    //   Constant: '<S19>/Constant'

    if (pCKAN_DW.Memory_PreviousInput) {
      pCKAN_B.u00Hz = pCKAN_DW.DiscreteTimeIntegrator_DSTATE;
    } else {
      pCKAN_B.u00Hz = pCKAN_P.Constant_Value_l;
    }

    // End of Switch: '<S19>/Switch'

    // Logic: '<S20>/AND1' incorporates:
    //   Constant: '<S34>/Constant'
    //   RelationalOperator: '<S34>/Compare'

    rtb_MECO_log = (pCKAN_DW.Memory_PreviousInput_l || (pCKAN_B.u00Hz >=
      pCKAN_P.Flight_Logic.MECO_timeout_TOF_sec));

    // MATLABSystem: '<S17>/Moving Average1'
    if (pCKAN_DW.obj.TunablePropsChanged) {
      pCKAN_DW.obj.TunablePropsChanged = false;
    }

    obj = pCKAN_DW.obj.pStatistic;
    if (obj->isInitialized != 1) {
      obj->isSetupComplete = false;
      obj->isInitialized = 1;
      obj->pCumSum = 0.0F;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0F;
      }

      obj->pCumRevIndex = 1.0F;
      obj->isSetupComplete = true;
      obj->pCumSum = 0.0F;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0F;
      }

      obj->pCumRevIndex = 1.0F;
    }

    rtb_v = obj->pCumRevIndex;
    rtb_z = obj->pCumSum;
    for (i = 0; i < 9; i++) {
      pCKAN_B.csumrev[i] = obj->pCumSumRev[i];
    }

    rtb_z += rtb_Gain1;
    rtb_fin_cmd_idx_0 = pCKAN_B.csumrev[static_cast<int32_T>(rtb_v) - 1] + rtb_z;
    pCKAN_B.csumrev[static_cast<int32_T>(rtb_v) - 1] = rtb_Gain1;
    if (rtb_v != 9.0F) {
      rtb_v++;
    } else {
      rtb_v = 1.0F;
      rtb_z = 0.0F;
      for (i = 7; i >= 0; i--) {
        pCKAN_B.csumrev[i] += pCKAN_B.csumrev[i + 1];
      }
    }

    obj->pCumSum = rtb_z;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = pCKAN_B.csumrev[i];
    }

    obj->pCumRevIndex = rtb_v;
    rtb_v = rtb_fin_cmd_idx_0 / 10.0F;

    // End of MATLABSystem: '<S17>/Moving Average1'

    // Logic: '<S26>/NOT' incorporates:
    //   RelationalOperator: '<S25>/FixPt Relational Operator'
    //   UnitDelay: '<S25>/Delay Input1'
    //
    //  Block description for '<S25>/Delay Input1':
    //
    //   Store in Global RAM

    rtb_NOT_e = !(rtb_v < pCKAN_DW.DelayInput1_DSTATE);

    // DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S26>/Constant1'

    if (pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h == 0) {
      if (rtb_NOT_e || (pCKAN_DW.DiscreteTimeIntegrator_PrevResetState_j != 0))
      {
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE_c = pCKAN_P.Constant1_Value_g;
      } else {
        // DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE_c +=
          pCKAN_P.DiscreteTimeIntegrator_gainval_b * static_cast<real_T>
          (EmulatedPixhawk_ELAPS_T) * pCKAN_DW.DiscreteTimeIntegrator_PREV_U_j;
      }
    }

    // End of DiscreteIntegrator: '<S26>/Discrete-Time Integrator'

    // Switch: '<S27>/Switch1' incorporates:
    //   Constant: '<S22>/Constant'
    //   Constant: '<S23>/Constant'
    //   Logic: '<S17>/AND'
    //   Memory: '<S27>/Memory'
    //   RelationalOperator: '<S22>/Compare'
    //   RelationalOperator: '<S23>/Compare'

    pCKAN_DW.Memory_PreviousInput_e = ((rtb_MECO_log &&
      (pCKAN_DW.DiscreteTimeIntegrator_DSTATE_c >=
       pCKAN_P.Flight_Logic.h_apogee_timer_threshold_sec) && (rtb_w >
      pCKAN_P.CompareToConstant_const_g)) || pCKAN_DW.Memory_PreviousInput_e);

    // Logic: '<S39>/NOT' incorporates:
    //   Constant: '<S24>/Constant'
    //   Logic: '<S17>/AND1'
    //   RelationalOperator: '<S24>/Compare'

    rtb_NOT_d = ((!pCKAN_DW.Memory_PreviousInput_e) && (!(pCKAN_B.u00Hz >=
      pCKAN_P.Flight_Logic.apogee_timeout_TOF_sec)));

    // DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant1'

    if (pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec == 0) {
      if (rtb_NOT_d || (pCKAN_DW.DiscreteTimeIntegrator_PrevResetState_ii != 0))
      {
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE_o = pCKAN_P.Constant1_Value_e;
      } else {
        // DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
        pCKAN_DW.DiscreteTimeIntegrator_DSTATE_o +=
          pCKAN_P.DiscreteTimeIntegrator_gainval_o * static_cast<real_T>
          (EmulatedPixhawk_ELAPS_T) * pCKAN_DW.DiscreteTimeIntegrator_PREV_U_m;
      }
    }

    // End of DiscreteIntegrator: '<S39>/Discrete-Time Integrator'

    // Switch: '<S40>/Switch1' incorporates:
    //   Constant: '<S37>/Constant'
    //   Memory: '<S40>/Memory'
    //   RelationalOperator: '<S37>/Compare'

    pCKAN_DW.Memory_PreviousInput_p = ((pCKAN_DW.DiscreteTimeIntegrator_DSTATE_o
      >= pCKAN_P.Flight_Logic.apogee_recovery_timer_threshold_sec) ||
      pCKAN_DW.Memory_PreviousInput_p);

    // Logic: '<S21>/AND2' incorporates:
    //   Constant: '<S21>/Constant'
    //   Constant: '<S38>/Constant'
    //   Logic: '<S21>/AND1'
    //   Logic: '<S21>/NOT'
    //   RelationalOperator: '<S38>/Compare'

    rtb_recovery_log = ((pCKAN_DW.Memory_PreviousInput_p || (pCKAN_B.u00Hz >=
      pCKAN_P.Flight_Logic.recovery_timeout_TOF_sec)) &&
                        (!(pCKAN_P.Flight_Logic.disable_recovery_manual != 0.0)));

    // MATLABSystem: '<S15>/PX4 PWM Output1'
    for (i = 0; i < 8; i++) {
      pCKAN_B.pwmValue[i] = 0U;
    }

    // Gain: '<S43>/Gain'
    rtb_z = pCKAN_P.Gain_Gain * pCKAN_B.siB_cmd[0];

    // Saturate: '<S15>/Saturation'
    if (rtb_z > pCKAN_P.Saturation_UpperSat) {
      rtb_z = pCKAN_P.Saturation_UpperSat;
    } else if (rtb_z < pCKAN_P.Saturation_LowerSat) {
      rtb_z = pCKAN_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S15>/Saturation'

    // DataTypeConversion: '<S15>/Cast To Double' incorporates:
    //   Constant: '<S15>/One'
    //   Gain: '<S15>/Gain'
    //   Sum: '<S15>/Add'

    rtb_w = static_cast<real32_T>(floor(static_cast<real_T>(pCKAN_P.Gain_Gain_m *
      rtb_z + pCKAN_P.One_Value_f)));
    if (rtIsNaNF(rtb_w) || rtIsInfF(rtb_w)) {
      rtb_w = 0.0F;
    } else {
      rtb_w = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_w), 65536.0));
    }

    // MATLABSystem: '<S15>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S15>/Cast To Double'

    pCKAN_B.pwmValue[0] = static_cast<uint16_T>(rtb_w < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_w)))) : static_cast<int32_T>
      (static_cast<uint16_T>(rtb_w)));

    // Gain: '<S44>/Gain'
    rtb_z = pCKAN_P.Gain_Gain_g * pCKAN_B.siB_cmd[1];

    // Saturate: '<S15>/Saturation1'
    if (rtb_z > pCKAN_P.Saturation1_UpperSat) {
      rtb_z = pCKAN_P.Saturation1_UpperSat;
    } else if (rtb_z < pCKAN_P.Saturation1_LowerSat) {
      rtb_z = pCKAN_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S15>/Saturation1'

    // DataTypeConversion: '<S15>/Cast To Double1' incorporates:
    //   Constant: '<S15>/One1'
    //   Gain: '<S15>/Gain1'
    //   Sum: '<S15>/Add1'

    rtb_w = static_cast<real32_T>(floor(static_cast<real_T>(pCKAN_P.Gain1_Gain_j
      * rtb_z + pCKAN_P.One1_Value_d)));
    if (rtIsNaNF(rtb_w) || rtIsInfF(rtb_w)) {
      rtb_w = 0.0F;
    } else {
      rtb_w = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_w), 65536.0));
    }

    // MATLABSystem: '<S15>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S15>/Cast To Double1'

    pCKAN_B.pwmValue[1] = static_cast<uint16_T>(rtb_w < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_w)))) : static_cast<int32_T>
      (static_cast<uint16_T>(rtb_w)));

    // Gain: '<S45>/Gain'
    rtb_z = pCKAN_P.Gain_Gain_c * pCKAN_B.siB_cmd[2];

    // Saturate: '<S15>/Saturation2'
    if (rtb_z > pCKAN_P.Saturation2_UpperSat) {
      rtb_z = pCKAN_P.Saturation2_UpperSat;
    } else if (rtb_z < pCKAN_P.Saturation2_LowerSat) {
      rtb_z = pCKAN_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S15>/Saturation2'

    // DataTypeConversion: '<S15>/Cast To Double2' incorporates:
    //   Constant: '<S15>/One2'
    //   Gain: '<S15>/Gain2'
    //   Sum: '<S15>/Add2'

    rtb_w = static_cast<real32_T>(floor(static_cast<real_T>(pCKAN_P.Gain2_Gain *
      rtb_z + pCKAN_P.One2_Value_d)));
    if (rtIsNaNF(rtb_w) || rtIsInfF(rtb_w)) {
      rtb_w = 0.0F;
    } else {
      rtb_w = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_w), 65536.0));
    }

    // MATLABSystem: '<S15>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S15>/Cast To Double2'
    //   DataTypeConversion: '<S15>/Cast To Double3'

    pCKAN_B.pwmValue[2] = static_cast<uint16_T>(rtb_w < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_w)))) : static_cast<int32_T>
      (static_cast<uint16_T>(rtb_w)));
    pCKAN_B.pwmValue[3] = static_cast<uint16_T>(rtb_p < 0.0F ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-rtb_p)))) : static_cast<int32_T>
      (static_cast<uint16_T>(rtb_p)));

    // Switch: '<S15>/Switch'
    if (rtb_recovery_log) {
      // DataTypeConversion: '<S15>/Cast To Double4' incorporates:
      //   Constant: '<S15>/One5'

      pCKAN_B.u00Hz = floor(pCKAN_P.One5_Value);
      if (rtIsNaN(pCKAN_B.u00Hz) || rtIsInf(pCKAN_B.u00Hz)) {
        pCKAN_B.u00Hz = 0.0;
      } else {
        pCKAN_B.u00Hz = fmod(pCKAN_B.u00Hz, 65536.0);
      }

      // MATLABSystem: '<S15>/PX4 PWM Output1' incorporates:
      //   DataTypeConversion: '<S15>/Cast To Double4'

      pCKAN_B.pwmValue[4] = static_cast<uint16_T>(pCKAN_B.u00Hz < 0.0 ?
        static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-pCKAN_B.u00Hz)))) : static_cast<int32_T>(
        static_cast<uint16_T>(pCKAN_B.u00Hz)));
    } else {
      // DataTypeConversion: '<S15>/Cast To Double4' incorporates:
      //   Constant: '<S15>/One6'

      pCKAN_B.u00Hz = floor(pCKAN_P.One6_Value);
      if (rtIsNaN(pCKAN_B.u00Hz) || rtIsInf(pCKAN_B.u00Hz)) {
        pCKAN_B.u00Hz = 0.0;
      } else {
        pCKAN_B.u00Hz = fmod(pCKAN_B.u00Hz, 65536.0);
      }

      // MATLABSystem: '<S15>/PX4 PWM Output1' incorporates:
      //   DataTypeConversion: '<S15>/Cast To Double4'

      pCKAN_B.pwmValue[4] = static_cast<uint16_T>(pCKAN_B.u00Hz < 0.0 ?
        static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
        static_cast<uint16_T>(-pCKAN_B.u00Hz)))) : static_cast<int32_T>(
        static_cast<uint16_T>(pCKAN_B.u00Hz)));
    }

    // End of Switch: '<S15>/Switch'

    // MATLABSystem: '<S15>/PX4 PWM Output1' incorporates:
    //   Constant: '<S15>/One4'
    //   Delay: '<S42>/Delay'
    //   Inport: '<Root>/Serial In'
    //   Logic: '<S15>/AND'
    //   RelationalOperator: '<S42>/GreaterThan'

    if ((pCKAN_U.SerialIn[0] != 0.0F) && (pCKAN_U.SerialIn[1] >
         pCKAN_DW.Delay_DSTATE_l)) {
      if (!pCKAN_DW.obj_j.isArmed) {
        pCKAN_DW.obj_j.isArmed = true;
        status = pwm_arm(&pCKAN_DW.obj_j.pwmDevHandler,
                         &pCKAN_DW.obj_j.armAdvertiseObj);
        pCKAN_DW.obj_j.errorStatus = static_cast<uint16_T>
          (pCKAN_DW.obj_j.errorStatus | status);
      }

      status = pwm_setServo(&pCKAN_DW.obj_j.pwmDevHandler,
                            pCKAN_DW.obj_j.servoCount,
                            pCKAN_DW.obj_j.channelMask, &pCKAN_B.pwmValue[0],
                            pCKAN_DW.obj_j.isMain,
                            &pCKAN_DW.obj_j.actuatorAdvertiseObj);
      pCKAN_DW.obj_j.errorStatus = static_cast<uint16_T>
        (pCKAN_DW.obj_j.errorStatus | status);
    } else {
      status = pwm_disarm(&pCKAN_DW.obj_j.pwmDevHandler,
                          &pCKAN_DW.obj_j.armAdvertiseObj);
      pCKAN_DW.obj_j.errorStatus = static_cast<uint16_T>
        (pCKAN_DW.obj_j.errorStatus | status);
      pCKAN_DW.obj_j.isArmed = false;
      status = pwm_resetServo(&pCKAN_DW.obj_j.pwmDevHandler,
        pCKAN_DW.obj_j.servoCount, pCKAN_DW.obj_j.channelMask,
        pCKAN_DW.obj_j.isMain, &pCKAN_DW.obj_j.actuatorAdvertiseObj);
      pCKAN_DW.obj_j.errorStatus = static_cast<uint16_T>
        (pCKAN_DW.obj_j.errorStatus | status);
    }

    if (pCKAN_DW.obj_j.isMain) {
      status = pwm_forceFailsafe(&pCKAN_DW.obj_j.pwmDevHandler,
        static_cast<int32_T>(pCKAN_P.One4_Value_p));
      pCKAN_DW.obj_j.errorStatus = static_cast<uint16_T>
        (pCKAN_DW.obj_j.errorStatus | status);
    }

    // Switch: '<S18>/Switch3' incorporates:
    //   Constant: '<S12>/Constant5'
    //   Constant: '<S18>/Constant5'
    //   Switch: '<S18>/Switch'
    //   Switch: '<S18>/Switch1'
    //   Switch: '<S18>/Switch2'
    //   Switch: '<S18>/Switch4'

    if (rtb_recovery_log) {
      // Outport: '<Root>/flight_mode_enum' incorporates:
      //   Constant: '<S18>/Constant4'

      pCKAN_Y.flight_mode_enum = pCKAN_P.Constant4_Value;
    } else if (pCKAN_P.Constant5_Value_k != 0.0) {
      // Switch: '<S18>/Switch4' incorporates:
      //   Constant: '<S18>/Constant6'
      //   Outport: '<Root>/flight_mode_enum'

      pCKAN_Y.flight_mode_enum = pCKAN_P.Constant6_Value;
    } else if (rtb_MECO_log) {
      // Switch: '<S18>/Switch2' incorporates:
      //   Constant: '<S18>/Constant3'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S18>/Switch4'

      pCKAN_Y.flight_mode_enum = pCKAN_P.Constant3_Value;
    } else if (pCKAN_DW.Memory_PreviousInput) {
      // Switch: '<S18>/Switch1' incorporates:
      //   Constant: '<S18>/Constant2'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S18>/Switch2'
      //   Switch: '<S18>/Switch4'

      pCKAN_Y.flight_mode_enum = pCKAN_P.Constant2_Value;
    } else if (pCKAN_P.Constant5_Value != 0.0) {
      // Switch: '<S18>/Switch' incorporates:
      //   Constant: '<S18>/Constant1'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S18>/Switch1'
      //   Switch: '<S18>/Switch2'
      //   Switch: '<S18>/Switch4'

      pCKAN_Y.flight_mode_enum = pCKAN_P.Constant1_Value;
    } else {
      // Outport: '<Root>/flight_mode_enum' incorporates:
      //   Constant: '<S18>/Constant'
      //   Switch: '<S18>/Switch1'
      //   Switch: '<S18>/Switch2'
      //   Switch: '<S18>/Switch4'

      pCKAN_Y.flight_mode_enum = pCKAN_P.Constant_Value;
    }

    // End of Switch: '<S18>/Switch3'

    // Update for Delay: '<S47>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    pCKAN_DW.Delay_DSTATE = pCKAN_U.SerialIn[1];

    // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
    //   Gain: '<S3>/Gain1'
    //   Lookup_n-D: '<S41>/1-D Lookup Table4'
    //   Product: '<S14>/Product3'

    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
    pCKAN_DW.DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
      (rtb_GreaterThan);
    pCKAN_DW.DiscreteTimeIntegrator_PREV_U_jd = look2_iflf_binlcapw(rtb_Gain1,
      rtb_Ki_phi, pCKAN_P.uDLookupTable4_bp01Data,
      pCKAN_P.uDLookupTable4_bp02Data, pCKAN_P.uDLookupTable4_tableData,
      pCKAN_P.uDLookupTable4_maxIndex, 3U) * rtb_Sum3;

    // Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn3'
    pCKAN_DW.DiscreteTransferFcn3_states = DiscreteTransferFcn3_tmp;

    // Update for Delay: '<S42>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    pCKAN_DW.Delay_DSTATE_l = pCKAN_U.SerialIn[1];

    // Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
    pCKAN_DW.DiscreteTransferFcn_states = pCKAN_B.u;

    // Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S30>/Constant'

    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e = 0U;
    pCKAN_DW.DiscreteTimeIntegrator_PrevResetState_i = static_cast<int8_T>
      (rtb_NOT);
    pCKAN_DW.DiscreteTimeIntegrator_PREV_U = pCKAN_P.Constant_Value_lo;

    // Update for Memory: '<S31>/Memory'
    pCKAN_DW.Memory_PreviousInput_f = pCKAN_DW.Memory_PreviousInput;

    // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant'

    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d = 0U;
    pCKAN_DW.DiscreteTimeIntegrator_PrevResetState_iw = static_cast<int8_T>
      (rtb_Memory);
    pCKAN_DW.DiscreteTimeIntegrator_PREV_U_a = pCKAN_P.Constant_Value_b;

    // Update for UnitDelay: '<S25>/Delay Input1'
    //
    //  Block description for '<S25>/Delay Input1':
    //
    //   Store in Global RAM

    pCKAN_DW.DelayInput1_DSTATE = rtb_v;

    // Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S26>/Constant'

    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h = 0U;
    pCKAN_DW.DiscreteTimeIntegrator_PrevResetState_j = static_cast<int8_T>
      (rtb_NOT_e);
    pCKAN_DW.DiscreteTimeIntegrator_PREV_U_j = pCKAN_P.Constant_Value_a;

    // Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant'

    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec = 0U;
    pCKAN_DW.DiscreteTimeIntegrator_PrevResetState_ii = static_cast<int8_T>
      (rtb_NOT_d);
    pCKAN_DW.DiscreteTimeIntegrator_PREV_U_m = pCKAN_P.Constant_Value_bq;
  }

  // End of Outputs for SubSystem: '<S1>/Emulated Pixhawk'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.001, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  pCKAN_M->Timing.clockTick0++;
}

// Model initialize function
void pCKAN_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    c_dsp_private_SlidingWindowAverageCG_pCKAN_T *obj;
    int32_T i;
    boolean_T rtb_AND;
    pCKAN_PrevZCX.EmulatedPixhawk_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // SystemInitialize for Triggered SubSystem: '<S1>/Emulated Pixhawk'
    // InitializeConditions for Delay: '<S47>/Delay'
    pCKAN_DW.Delay_DSTATE = pCKAN_P.Delay_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S14>/Constant'

    pCKAN_DW.DiscreteTimeIntegrator_DSTATE_n = pCKAN_P.Constant_Value_o;

    // InitializeConditions for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn3' 
    pCKAN_DW.DiscreteTransferFcn3_states =
      pCKAN_P.DiscreteTransferFcn3_InitialStates;

    // InitializeConditions for Delay: '<S42>/Delay'
    pCKAN_DW.Delay_DSTATE_l = pCKAN_P.Delay_InitialCondition_f;

    // InitializeConditions for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' 
    pCKAN_DW.DiscreteTransferFcn_states =
      pCKAN_P.DiscreteTransferFcn_InitialStates;

    // InitializeConditions for Switch: '<S31>/Switch1' incorporates:
    //   Memory: '<S19>/Memory'

    pCKAN_DW.Memory_PreviousInput = pCKAN_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S30>/Constant1'

    pCKAN_DW.DiscreteTimeIntegrator_DSTATE = pCKAN_P.Constant1_Value_m;

    // InitializeConditions for Memory: '<S31>/Memory'
    pCKAN_DW.Memory_PreviousInput_f = pCKAN_P.Memory_InitialCondition_f;

    // InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant1'

    pCKAN_DW.DiscreteTimeIntegrator_DSTATE_p = pCKAN_P.Constant1_Value_f;

    // InitializeConditions for Switch: '<S36>/Switch1' incorporates:
    //   Memory: '<S36>/Memory'

    pCKAN_DW.Memory_PreviousInput_l = pCKAN_P.Memory_InitialCondition_p;

    // InitializeConditions for UnitDelay: '<S25>/Delay Input1'
    //
    //  Block description for '<S25>/Delay Input1':
    //
    //   Store in Global RAM

    pCKAN_DW.DelayInput1_DSTATE = pCKAN_P.DetectDecrease_vinit;

    // InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S26>/Constant1'

    pCKAN_DW.DiscreteTimeIntegrator_DSTATE_c = pCKAN_P.Constant1_Value_g;

    // InitializeConditions for Switch: '<S27>/Switch1' incorporates:
    //   Memory: '<S27>/Memory'

    pCKAN_DW.Memory_PreviousInput_e = pCKAN_P.Memory_InitialCondition_n;

    // InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant1'

    pCKAN_DW.DiscreteTimeIntegrator_DSTATE_o = pCKAN_P.Constant1_Value_e;

    // InitializeConditions for Switch: '<S40>/Switch1' incorporates:
    //   Memory: '<S40>/Memory'

    pCKAN_DW.Memory_PreviousInput_p = pCKAN_P.Memory_InitialCondition_m;

    // Start for MATLABSystem: '<S17>/Moving Average1'
    pCKAN_DW.obj.matlabCodegenIsDeleted = true;
    pCKAN_DW.obj.isInitialized = 0;
    pCKAN_DW.obj.NumChannels = -1;
    pCKAN_DW.obj.matlabCodegenIsDeleted = false;
    pCKAN_DW.obj.isSetupComplete = false;
    pCKAN_DW.obj.isInitialized = 1;
    pCKAN_DW.obj.NumChannels = 1;
    pCKAN_DW.obj._pobj0.isInitialized = 0;
    pCKAN_DW.obj.pStatistic = &pCKAN_DW.obj._pobj0;
    pCKAN_DW.obj.isSetupComplete = true;
    pCKAN_DW.obj.TunablePropsChanged = false;

    // InitializeConditions for MATLABSystem: '<S17>/Moving Average1'
    obj = pCKAN_DW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0F;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0F;
      }

      obj->pCumRevIndex = 1.0F;
    }

    // End of InitializeConditions for MATLABSystem: '<S17>/Moving Average1'

    // Start for MATLABSystem: '<S15>/PX4 PWM Output1' incorporates:
    //   Constant: '<S15>/One4'

    pCKAN_DW.obj_j.errorStatus = 0U;
    pCKAN_DW.obj_j.isInitialized = 0;
    pCKAN_DW.obj_j.matlabCodegenIsDeleted = false;
    pCKAN_SystemCore_setup(&pCKAN_DW.obj_j, rtb_AND, pCKAN_P.One4_Value_p);
    for (i = 0; i < 18; i++) {
      // SystemInitialize for Outport: '<Root>/Serial Out' incorporates:
      //   Outport: '<S2>/Serial Out'

      pCKAN_Y.SerialOut[i] = pCKAN_P.SerialOut_Y0;
    }

    // SystemInitialize for Outport: '<Root>/flight_mode_enum' incorporates:
    //   Outport: '<S2>/flight_mode_enum'

    pCKAN_Y.flight_mode_enum = pCKAN_P.flight_mode_enum_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Emulated Pixhawk'

    // Enable for Triggered SubSystem: '<S1>/Emulated Pixhawk'
    pCKAN_DW.EmulatedPixhawk_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;

    // Enable for DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e = 1U;

    // Enable for DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d = 1U;

    // Enable for DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h = 1U;

    // Enable for DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
    pCKAN_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec = 1U;

    // End of Enable for SubSystem: '<S1>/Emulated Pixhawk'
  }
}

// Model terminate function
void pCKAN_terminate(void)
{
  c_dsp_private_SlidingWindowAverageCG_pCKAN_T *obj;
  uint16_T status;

  // Terminate for Triggered SubSystem: '<S1>/Emulated Pixhawk'
  // Terminate for MATLABSystem: '<S17>/Moving Average1'
  if (!pCKAN_DW.obj.matlabCodegenIsDeleted) {
    pCKAN_DW.obj.matlabCodegenIsDeleted = true;
    if ((pCKAN_DW.obj.isInitialized == 1) && pCKAN_DW.obj.isSetupComplete) {
      obj = pCKAN_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      pCKAN_DW.obj.NumChannels = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S17>/Moving Average1'

  // Terminate for MATLABSystem: '<S15>/PX4 PWM Output1'
  if (!pCKAN_DW.obj_j.matlabCodegenIsDeleted) {
    pCKAN_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((pCKAN_DW.obj_j.isInitialized == 1) && pCKAN_DW.obj_j.isSetupComplete) {
      status = pwm_disarm(&pCKAN_DW.obj_j.pwmDevHandler,
                          &pCKAN_DW.obj_j.armAdvertiseObj);
      pCKAN_DW.obj_j.errorStatus = static_cast<uint16_T>
        (pCKAN_DW.obj_j.errorStatus | status);
      status = pwm_resetServo(&pCKAN_DW.obj_j.pwmDevHandler,
        pCKAN_DW.obj_j.servoCount, pCKAN_DW.obj_j.channelMask,
        pCKAN_DW.obj_j.isMain, &pCKAN_DW.obj_j.actuatorAdvertiseObj);
      pCKAN_DW.obj_j.errorStatus = static_cast<uint16_T>
        (pCKAN_DW.obj_j.errorStatus | status);
      status = pwm_close(&pCKAN_DW.obj_j.pwmDevHandler,
                         &pCKAN_DW.obj_j.actuatorAdvertiseObj,
                         &pCKAN_DW.obj_j.armAdvertiseObj);
      pCKAN_DW.obj_j.errorStatus = static_cast<uint16_T>
        (pCKAN_DW.obj_j.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S15>/PX4 PWM Output1'
  // End of Terminate for SubSystem: '<S1>/Emulated Pixhawk'
}

//
// File trailer for generated code.
//
// [EOF]
//
