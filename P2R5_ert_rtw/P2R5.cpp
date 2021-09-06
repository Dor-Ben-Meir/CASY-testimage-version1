//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: P2R5.cpp
//
// Code generated for Simulink model 'P2R5'.
//
// Model version                  : 4.48
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon May 10 17:59:57 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "P2R5.h"
#include "P2R5_private.h"

// Block signals (default storage)
B_P2R5_T P2R5_B;

// Block states (default storage)
DW_P2R5_T P2R5_DW;

// Previous zero-crossings (trigger) states
PrevZCX_P2R5_T P2R5_PrevZCX;

// External inputs (root inport signals with default storage)
ExtU_P2R5_T P2R5_U;

// External outputs (root outports fed by signals with default storage)
ExtY_P2R5_T P2R5_Y;

// Real-time model
RT_MODEL_P2R5_T P2R5_M_ = RT_MODEL_P2R5_T();
RT_MODEL_P2R5_T *const P2R5_M = &P2R5_M_;

// Forward declaration for local functions
static void P2R5_SystemCore_setup(px4_internal_block_PWM_P2R5_T *obj, boolean_T
  varargin_1, boolean_T varargin_2);
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

static void P2R5_SystemCore_setup(px4_internal_block_PWM_P2R5_T *obj, boolean_T
  varargin_1, boolean_T varargin_2)
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

// Model step function
void P2R5_step(void)
{
  c_dsp_private_SlidingWindowAverageCG_P2R5_T *obj;
  int32_T i;
  real32_T DiscreteTransferFcn3_tmp;
  real32_T rtb_Add3;
  real32_T rtb_DiscreteTransferFcn;
  real32_T rtb_Gain1_o;
  real32_T rtb_fin_cmd_idx_0;
  real32_T rtb_p;
  real32_T rtb_v;
  real32_T rtb_w;
  real32_T rtb_z;
  uint32_T Autopilot_ELAPS_T;
  uint16_T status;
  boolean_T rtb_MECO_log;
  boolean_T rtb_Memory;
  boolean_T rtb_NOT;
  boolean_T rtb_NOT_d;
  boolean_T rtb_NOT_h;
  ZCEventType zcEvent;

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Constant: '<S43>/One'
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_1_Threshold) {
    P2R5_B.u = P2R5_P.One_Value;
  } else {
    P2R5_B.u = P2R5_U.SerialIn[4];
  }

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Constant: '<S43>/One1'
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_2_Threshold) {
    rtb_v = P2R5_P.One1_Value;
  } else {
    rtb_v = P2R5_U.SerialIn[5];
  }

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Constant: '<S43>/One2'
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_3_Threshold) {
    rtb_w = P2R5_P.One2_Value;
  } else {
    rtb_w = P2R5_U.SerialIn[6];
  }

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Constant: '<S43>/One5'
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_6_Threshold) {
    rtb_z = P2R5_P.One5_Value_o;
  } else {
    rtb_z = P2R5_U.SerialIn[9];
  }

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Constant: '<S43>/One6'
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_7_Threshold) {
    rtb_p = P2R5_P.One6_Value_c;
  } else {
    rtb_p = P2R5_U.SerialIn[10];
  }

  // DiscretePulseGenerator: '<S2>/100 Hz'
  P2R5_B.u00Hz = (P2R5_DW.clockTickCounter < P2R5_P.u00Hz_Duty) &&
    (P2R5_DW.clockTickCounter >= 0) ? P2R5_P.u00Hz_Amp : 0.0;
  if (P2R5_DW.clockTickCounter >= P2R5_P.u00Hz_Period - 1.0) {
    P2R5_DW.clockTickCounter = 0;
  } else {
    P2R5_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S2>/100 Hz'

  // Outputs for Triggered SubSystem: '<S2>/Autopilot' incorporates:
  //   TriggerPort: '<S3>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&P2R5_PrevZCX.Autopilot_Trig_ZCE,
                     (P2R5_B.u00Hz));
  if (zcEvent != NO_ZCEVENT) {
    if (P2R5_DW.Autopilot_RESET_ELAPS_T) {
      Autopilot_ELAPS_T = 0U;
    } else {
      Autopilot_ELAPS_T = P2R5_M->Timing.clockTick0 - P2R5_DW.Autopilot_PREV_T;
    }

    P2R5_DW.Autopilot_PREV_T = P2R5_M->Timing.clockTick0;
    P2R5_DW.Autopilot_RESET_ELAPS_T = false;

    // Gain: '<S3>/Gain1'
    rtb_Gain1_o = P2R5_P.Gain1_Gain * rtb_z;

    // Sqrt: '<S10>/Square Root' incorporates:
    //   Math: '<S10>/Square'
    //   Math: '<S10>/Square1'
    //   Math: '<S10>/Square2'
    //   Sum: '<S10>/Add'

    rtb_Add3 = static_cast<real32_T>(sqrt(static_cast<real_T>((P2R5_B.u *
      P2R5_B.u + rtb_v * rtb_v) + rtb_w * rtb_w)));

    // Switch generated from: '<S7>/Switch' incorporates:
    //   Constant: '<S43>/One9'
    //   Inport: '<Root>/Serial In'

    if (P2R5_U.SerialIn[2] > P2R5_P.Switch_10_Threshold) {
      DiscreteTransferFcn3_tmp = P2R5_P.One9_Value;
    } else {
      DiscreteTransferFcn3_tmp = P2R5_U.SerialIn[19];
    }

    // Sum: '<S15>/Sum3' incorporates:
    //   Inport: '<Root>/Serial In'

    rtb_DiscreteTransferFcn = P2R5_U.SerialIn[22] - DiscreteTransferFcn3_tmp;

    // DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S11>/Constant'
    //   Constant: '<S15>/Constant'

    if (P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE == 0) {
      if (P2R5_P.Constant_Value_c ||
          (P2R5_DW.DiscreteTimeIntegrator_PrevResetState != 0)) {
        P2R5_DW.DiscreteTimeIntegrator_DSTATE_no = P2R5_P.Constant_Value_o;
      } else {
        // DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
        P2R5_DW.DiscreteTimeIntegrator_DSTATE_no +=
          P2R5_P.DiscreteTimeIntegrator_gainval_m * static_cast<real32_T>
          (Autopilot_ELAPS_T) * P2R5_DW.DiscreteTimeIntegrator_PREV_U_j;
      }
    }

    // End of DiscreteIntegrator: '<S15>/Discrete-Time Integrator'

    // DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn3'
    DiscreteTransferFcn3_tmp = (rtb_p - P2R5_P.DiscreteTransferFcn3_DenCoef[1] *
      P2R5_DW.DiscreteTransferFcn3_states) /
      P2R5_P.DiscreteTransferFcn3_DenCoef[0];

    // Product: '<S15>/Product1' incorporates:
    //   DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn3'
    //   Gain: '<S3>/Gain1'
    //   Lookup_n-D: '<S41>/1-D Lookup Table3'
    //   Lookup_n-D: '<S41>/1-D Lookup Table5'
    //   Product: '<S15>/Product2'
    //   Sum: '<S15>/Sum4'
    //   Sum: '<S15>/Sum5'
    //   Sum: '<S9>/Add3'

    rtb_fin_cmd_idx_0 = ((look2_iflf_binlcapw(rtb_Gain1_o, rtb_Add3,
      P2R5_P.uDLookupTable5_bp01Data, P2R5_P.uDLookupTable5_bp02Data,
      P2R5_P.uDLookupTable5_tableData, P2R5_P.uDLookupTable5_maxIndex, 3U) *
                          rtb_DiscreteTransferFcn +
                          P2R5_DW.DiscreteTimeIntegrator_DSTATE_no) -
                         (P2R5_P.DiscreteTransferFcn3_NumCoef[0] *
                          DiscreteTransferFcn3_tmp +
                          P2R5_P.DiscreteTransferFcn3_NumCoef[1] *
                          P2R5_DW.DiscreteTransferFcn3_states)) *
      look2_iflf_binlcapw(rtb_Gain1_o, rtb_Add3, P2R5_P.uDLookupTable3_bp01Data,
                          P2R5_P.uDLookupTable3_bp02Data,
                          P2R5_P.uDLookupTable3_tableData,
                          P2R5_P.uDLookupTable3_maxIndex, 3U);
    for (i = 0; i < 4; i++) {
      // Product: '<S16>/Product' incorporates:
      //   Constant: '<S15>/Zero'
      //   Constant: '<S16>/Constant7'

      P2R5_B.siB_cmd[i] = 0.0F;
      P2R5_B.siB_cmd[i] += P2R5_P.Constant7_Value[i] * rtb_fin_cmd_idx_0;
      P2R5_B.siB_cmd[i] += P2R5_P.Constant7_Value[i + 4] * P2R5_P.Zero_Value;
      P2R5_B.siB_cmd[i] += P2R5_P.Constant7_Value[i + 8] * P2R5_P.Zero_Value;
    }

    // SignalConversion generated from: '<S3>/Fin Cmd'
    P2R5_B.Fin_1_Cmd_rad = P2R5_B.siB_cmd[0];

    // SignalConversion generated from: '<S3>/Fin Cmd'
    P2R5_B.Fin_2_Cmd_rad = P2R5_B.siB_cmd[1];

    // SignalConversion generated from: '<S3>/Fin Cmd'
    P2R5_B.Fin_3_Cmd_rad = P2R5_B.siB_cmd[2];

    // SignalConversion generated from: '<S3>/Fin Cmd'
    P2R5_B.Fin_4_Cmd_rad = P2R5_B.siB_cmd[3];

    // Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
    //   Gain: '<S3>/Gain1'
    //   Lookup_n-D: '<S41>/1-D Lookup Table4'
    //   Product: '<S15>/Product3'
    //   Sum: '<S9>/Add3'

    P2R5_DW.DiscreteTimeIntegrator_PREV_U_j = look2_iflf_binlcapw(rtb_Gain1_o,
      rtb_Add3, P2R5_P.uDLookupTable4_bp01Data, P2R5_P.uDLookupTable4_bp02Data,
      P2R5_P.uDLookupTable4_tableData, P2R5_P.uDLookupTable4_maxIndex, 3U) *
      rtb_DiscreteTransferFcn;

    // MATLABSystem: '<S17>/Moving Average1'
    if (P2R5_DW.obj.TunablePropsChanged) {
      P2R5_DW.obj.TunablePropsChanged = false;
    }

    obj = P2R5_DW.obj.pStatistic;
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

    rtb_Add3 = obj->pCumRevIndex;
    rtb_DiscreteTransferFcn = obj->pCumSum;
    for (i = 0; i < 9; i++) {
      P2R5_B.csumrev[i] = obj->pCumSumRev[i];
    }

    rtb_DiscreteTransferFcn += rtb_Gain1_o;
    rtb_fin_cmd_idx_0 = P2R5_B.csumrev[static_cast<int32_T>(rtb_Add3) - 1] +
      rtb_DiscreteTransferFcn;
    P2R5_B.csumrev[static_cast<int32_T>(rtb_Add3) - 1] = rtb_Gain1_o;
    if (rtb_Add3 != 9.0F) {
      rtb_Add3++;
    } else {
      rtb_Add3 = 1.0F;
      rtb_DiscreteTransferFcn = 0.0F;
      for (i = 7; i >= 0; i--) {
        P2R5_B.csumrev[i] += P2R5_B.csumrev[i + 1];
      }
    }

    obj->pCumSum = rtb_DiscreteTransferFcn;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = P2R5_B.csumrev[i];
    }

    obj->pCumRevIndex = rtb_Add3;
    rtb_Gain1_o = rtb_fin_cmd_idx_0 / 10.0F;

    // End of MATLABSystem: '<S17>/Moving Average1'

    // Logic: '<S26>/NOT' incorporates:
    //   RelationalOperator: '<S25>/FixPt Relational Operator'
    //   UnitDelay: '<S25>/Delay Input1'
    //
    //  Block description for '<S25>/Delay Input1':
    //
    //   Store in Global RAM

    rtb_NOT = !(rtb_Gain1_o < P2R5_DW.DelayInput1_DSTATE);

    // DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S26>/Constant1'

    if (P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h == 0) {
      if (rtb_NOT || (P2R5_DW.DiscreteTimeIntegrator_PrevResetState_j != 0)) {
        P2R5_DW.DiscreteTimeIntegrator_DSTATE = P2R5_P.Constant1_Value_g;
      } else {
        // DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
        P2R5_DW.DiscreteTimeIntegrator_DSTATE +=
          P2R5_P.DiscreteTimeIntegrator_gainval * static_cast<real_T>
          (Autopilot_ELAPS_T) * P2R5_DW.DiscreteTimeIntegrator_PREV_U;
      }
    }

    // End of DiscreteIntegrator: '<S26>/Discrete-Time Integrator'

    // DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' incorporates:
    //   Inport: '<Root>/Serial In'

    rtb_Add3 = (P2R5_U.SerialIn[13] - P2R5_P.DiscreteTransferFcn_DenCoef[1] *
                P2R5_DW.DiscreteTransferFcn_states) /
      P2R5_P.DiscreteTransferFcn_DenCoef[0];
    rtb_DiscreteTransferFcn = P2R5_P.DiscreteTransferFcn_NumCoef[0] * rtb_Add3 +
      P2R5_P.DiscreteTransferFcn_NumCoef[1] * P2R5_DW.DiscreteTransferFcn_states;

    // RelationalOperator: '<S28>/Compare' incorporates:
    //   Constant: '<S28>/Constant'
    //   DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn'

    rtb_Memory = (rtb_DiscreteTransferFcn >= P2R5_P.CompareToConstant_const);

    // Logic: '<S30>/NOT' incorporates:
    //   Logic: '<S30>/AND'
    //   Memory: '<S19>/Memory'

    rtb_NOT_h = ((!rtb_Memory) && (!P2R5_DW.Memory_PreviousInput));

    // DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S30>/Constant1'

    if (P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e == 0) {
      if (rtb_NOT_h || (P2R5_DW.DiscreteTimeIntegrator_PrevResetState_i != 0)) {
        P2R5_DW.DiscreteTimeIntegrator_DSTATE_n = P2R5_P.Constant1_Value_m;
      } else {
        // DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
        P2R5_DW.DiscreteTimeIntegrator_DSTATE_n +=
          P2R5_P.DiscreteTimeIntegrator_gainval_l * static_cast<real_T>
          (Autopilot_ELAPS_T) * P2R5_DW.DiscreteTimeIntegrator_PREV_U_m;
      }
    }

    // End of DiscreteIntegrator: '<S30>/Discrete-Time Integrator'

    // Switch: '<S31>/Switch1' incorporates:
    //   Constant: '<S29>/Constant'
    //   Logic: '<S19>/AND'
    //   Memory: '<S31>/Memory'
    //   RelationalOperator: '<S29>/Compare'

    P2R5_DW.Memory_PreviousInput = ((rtb_Memory &&
      (P2R5_DW.DiscreteTimeIntegrator_DSTATE_n >=
       P2R5_P.Flight_Logic.Ax_launch_timer_threshold_sec)) ||
      P2R5_DW.Memory_PreviousInput_f);

    // Logic: '<S35>/NOT' incorporates:
    //   Constant: '<S33>/Constant'
    //   DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn'
    //   Logic: '<S20>/AND'
    //   RelationalOperator: '<S33>/Compare'

    rtb_Memory = ((!P2R5_DW.Memory_PreviousInput) || (!(rtb_DiscreteTransferFcn <=
      P2R5_P.CompareToConstant2_const)));

    // DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant1'

    if (P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d == 0) {
      if (rtb_Memory || (P2R5_DW.DiscreteTimeIntegrator_PrevResetState_iw != 0))
      {
        P2R5_DW.DiscreteTimeIntegrator_DSTATE_p = P2R5_P.Constant1_Value_f;
      } else {
        // DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
        P2R5_DW.DiscreteTimeIntegrator_DSTATE_p +=
          P2R5_P.DiscreteTimeIntegrator_gainval_k * static_cast<real_T>
          (Autopilot_ELAPS_T) * P2R5_DW.DiscreteTimeIntegrator_PREV_U_a;
      }
    }

    // End of DiscreteIntegrator: '<S35>/Discrete-Time Integrator'

    // Switch: '<S36>/Switch1' incorporates:
    //   Constant: '<S32>/Constant'
    //   Memory: '<S36>/Memory'
    //   RelationalOperator: '<S32>/Compare'

    P2R5_DW.Memory_PreviousInput_l = ((P2R5_DW.DiscreteTimeIntegrator_DSTATE_p >=
      P2R5_P.Flight_Logic.Ax_MECO_timer_threshold_sec) ||
      P2R5_DW.Memory_PreviousInput_l);

    // Switch: '<S19>/Switch' incorporates:
    //   Constant: '<S19>/Constant'

    if (P2R5_DW.Memory_PreviousInput) {
      P2R5_B.u00Hz = P2R5_DW.DiscreteTimeIntegrator_DSTATE_n;
    } else {
      P2R5_B.u00Hz = P2R5_P.Constant_Value_l;
    }

    // End of Switch: '<S19>/Switch'

    // Logic: '<S20>/AND1' incorporates:
    //   Constant: '<S34>/Constant'
    //   RelationalOperator: '<S34>/Compare'

    rtb_MECO_log = (P2R5_DW.Memory_PreviousInput_l || (P2R5_B.u00Hz >=
      P2R5_P.Flight_Logic.MECO_timeout_TOF_sec));

    // Switch: '<S27>/Switch1' incorporates:
    //   Constant: '<S22>/Constant'
    //   Constant: '<S23>/Constant'
    //   Logic: '<S17>/AND'
    //   Memory: '<S27>/Memory'
    //   RelationalOperator: '<S22>/Compare'
    //   RelationalOperator: '<S23>/Compare'

    P2R5_DW.Memory_PreviousInput_e = ((rtb_MECO_log &&
      (P2R5_DW.DiscreteTimeIntegrator_DSTATE >=
       P2R5_P.Flight_Logic.h_apogee_timer_threshold_sec) && (rtb_w >
      P2R5_P.CompareToConstant_const_g)) || P2R5_DW.Memory_PreviousInput_e);

    // Logic: '<S39>/NOT' incorporates:
    //   Constant: '<S24>/Constant'
    //   Logic: '<S17>/AND1'
    //   RelationalOperator: '<S24>/Compare'

    rtb_NOT_d = ((!P2R5_DW.Memory_PreviousInput_e) && (!(P2R5_B.u00Hz >=
      P2R5_P.Flight_Logic.apogee_timeout_TOF_sec)));

    // DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant1'

    if (P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec == 0) {
      if (rtb_NOT_d || (P2R5_DW.DiscreteTimeIntegrator_PrevResetState_ii != 0))
      {
        P2R5_DW.DiscreteTimeIntegrator_DSTATE_o = P2R5_P.Constant1_Value_e;
      } else {
        // DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
        P2R5_DW.DiscreteTimeIntegrator_DSTATE_o +=
          P2R5_P.DiscreteTimeIntegrator_gainval_o * static_cast<real_T>
          (Autopilot_ELAPS_T) * P2R5_DW.DiscreteTimeIntegrator_PREV_U_mh;
      }
    }

    // End of DiscreteIntegrator: '<S39>/Discrete-Time Integrator'

    // Switch: '<S40>/Switch1' incorporates:
    //   Constant: '<S37>/Constant'
    //   Memory: '<S40>/Memory'
    //   RelationalOperator: '<S37>/Compare'

    P2R5_DW.Memory_PreviousInput_p = ((P2R5_DW.DiscreteTimeIntegrator_DSTATE_o >=
      P2R5_P.Flight_Logic.apogee_recovery_timer_threshold_sec) ||
      P2R5_DW.Memory_PreviousInput_p);

    // Logic: '<S21>/AND2' incorporates:
    //   Constant: '<S21>/Constant'
    //   Constant: '<S38>/Constant'
    //   Logic: '<S21>/AND1'
    //   Logic: '<S21>/NOT'
    //   RelationalOperator: '<S38>/Compare'

    P2R5_B.recovery_log = ((P2R5_DW.Memory_PreviousInput_p || (P2R5_B.u00Hz >=
      P2R5_P.Flight_Logic.recovery_timeout_TOF_sec)) &&
      (!(P2R5_P.Flight_Logic.disable_recovery_manual != 0.0)));

    // Switch: '<S18>/Switch3' incorporates:
    //   Constant: '<S13>/Constant5'
    //   Constant: '<S18>/Constant5'
    //   Switch: '<S18>/Switch'
    //   Switch: '<S18>/Switch1'
    //   Switch: '<S18>/Switch2'
    //   Switch: '<S18>/Switch4'

    if (P2R5_B.recovery_log) {
      // Outport: '<Root>/flight_mode_enum' incorporates:
      //   Constant: '<S18>/Constant4'

      P2R5_Y.flight_mode_enum = P2R5_P.Constant4_Value;
    } else if (P2R5_P.Constant5_Value_k != 0.0) {
      // Switch: '<S18>/Switch4' incorporates:
      //   Constant: '<S18>/Constant6'
      //   Outport: '<Root>/flight_mode_enum'

      P2R5_Y.flight_mode_enum = P2R5_P.Constant6_Value;
    } else if (rtb_MECO_log) {
      // Switch: '<S18>/Switch2' incorporates:
      //   Constant: '<S18>/Constant3'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S18>/Switch4'

      P2R5_Y.flight_mode_enum = P2R5_P.Constant3_Value;
    } else if (P2R5_DW.Memory_PreviousInput) {
      // Switch: '<S18>/Switch1' incorporates:
      //   Constant: '<S18>/Constant2'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S18>/Switch2'
      //   Switch: '<S18>/Switch4'

      P2R5_Y.flight_mode_enum = P2R5_P.Constant2_Value;
    } else if (P2R5_P.Constant5_Value != 0.0) {
      // Switch: '<S18>/Switch' incorporates:
      //   Constant: '<S18>/Constant1'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S18>/Switch1'
      //   Switch: '<S18>/Switch2'
      //   Switch: '<S18>/Switch4'

      P2R5_Y.flight_mode_enum = P2R5_P.Constant1_Value;
    } else {
      // Outport: '<Root>/flight_mode_enum' incorporates:
      //   Constant: '<S18>/Constant'
      //   Switch: '<S18>/Switch1'
      //   Switch: '<S18>/Switch2'
      //   Switch: '<S18>/Switch4'

      P2R5_Y.flight_mode_enum = P2R5_P.Constant_Value;
    }

    // End of Switch: '<S18>/Switch3'

    // Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S11>/Constant'

    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
    P2R5_DW.DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
      (P2R5_P.Constant_Value_c);

    // Update for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn3'
    P2R5_DW.DiscreteTransferFcn3_states = DiscreteTransferFcn3_tmp;

    // Update for UnitDelay: '<S25>/Delay Input1'
    //
    //  Block description for '<S25>/Delay Input1':
    //
    //   Store in Global RAM

    P2R5_DW.DelayInput1_DSTATE = rtb_Gain1_o;

    // Update for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S26>/Constant'

    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h = 0U;
    P2R5_DW.DiscreteTimeIntegrator_PrevResetState_j = static_cast<int8_T>
      (rtb_NOT);
    P2R5_DW.DiscreteTimeIntegrator_PREV_U = P2R5_P.Constant_Value_a;

    // Update for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn'
    P2R5_DW.DiscreteTransferFcn_states = rtb_Add3;

    // Update for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S30>/Constant'

    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e = 0U;
    P2R5_DW.DiscreteTimeIntegrator_PrevResetState_i = static_cast<int8_T>
      (rtb_NOT_h);
    P2R5_DW.DiscreteTimeIntegrator_PREV_U_m = P2R5_P.Constant_Value_lo;

    // Update for Memory: '<S31>/Memory'
    P2R5_DW.Memory_PreviousInput_f = P2R5_DW.Memory_PreviousInput;

    // Update for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant'

    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d = 0U;
    P2R5_DW.DiscreteTimeIntegrator_PrevResetState_iw = static_cast<int8_T>
      (rtb_Memory);
    P2R5_DW.DiscreteTimeIntegrator_PREV_U_a = P2R5_P.Constant_Value_b;

    // Update for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant'

    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec = 0U;
    P2R5_DW.DiscreteTimeIntegrator_PrevResetState_ii = static_cast<int8_T>
      (rtb_NOT_d);
    P2R5_DW.DiscreteTimeIntegrator_PREV_U_mh = P2R5_P.Constant_Value_bq;
  }

  // End of Outputs for SubSystem: '<S2>/Autopilot'

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[1] = P2R5_B.siB_cmd[0];

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[2] = P2R5_B.siB_cmd[1];

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[3] = P2R5_B.siB_cmd[2];

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[4] = P2R5_B.siB_cmd[3];

  // MATLABSystem: '<S9>/PX4 PWM Output1'
  for (i = 0; i < 8; i++) {
    P2R5_B.pwmValue[i] = 0U;
  }

  // Gain: '<S45>/Gain'
  DiscreteTransferFcn3_tmp = P2R5_P.Gain_Gain * P2R5_B.Fin_1_Cmd_rad;

  // Saturate: '<S9>/Saturation'
  if (DiscreteTransferFcn3_tmp > P2R5_P.Saturation_UpperSat) {
    DiscreteTransferFcn3_tmp = P2R5_P.Saturation_UpperSat;
  } else if (DiscreteTransferFcn3_tmp < P2R5_P.Saturation_LowerSat) {
    DiscreteTransferFcn3_tmp = P2R5_P.Saturation_LowerSat;
  }

  // End of Saturate: '<S9>/Saturation'

  // DataTypeConversion: '<S9>/Cast To Double' incorporates:
  //   Constant: '<S9>/One'
  //   Gain: '<S9>/Gain'
  //   Sum: '<S9>/Add'

  DiscreteTransferFcn3_tmp = static_cast<real32_T>(floor(static_cast<real_T>
    (P2R5_P.Gain_Gain_h * DiscreteTransferFcn3_tmp + P2R5_P.One_Value_a)));
  if (rtIsNaNF(DiscreteTransferFcn3_tmp) || rtIsInfF(DiscreteTransferFcn3_tmp))
  {
    DiscreteTransferFcn3_tmp = 0.0F;
  } else {
    DiscreteTransferFcn3_tmp = static_cast<real32_T>(fmod(static_cast<real_T>
      (DiscreteTransferFcn3_tmp), 65536.0));
  }

  // MATLABSystem: '<S9>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S9>/Cast To Double'

  P2R5_B.pwmValue[0] = static_cast<uint16_T>(DiscreteTransferFcn3_tmp < 0.0F ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-DiscreteTransferFcn3_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(DiscreteTransferFcn3_tmp)));

  // Gain: '<S46>/Gain'
  DiscreteTransferFcn3_tmp = P2R5_P.Gain_Gain_m * P2R5_B.Fin_2_Cmd_rad;

  // Saturate: '<S9>/Saturation1'
  if (DiscreteTransferFcn3_tmp > P2R5_P.Saturation1_UpperSat) {
    DiscreteTransferFcn3_tmp = P2R5_P.Saturation1_UpperSat;
  } else if (DiscreteTransferFcn3_tmp < P2R5_P.Saturation1_LowerSat) {
    DiscreteTransferFcn3_tmp = P2R5_P.Saturation1_LowerSat;
  }

  // End of Saturate: '<S9>/Saturation1'

  // DataTypeConversion: '<S9>/Cast To Double1' incorporates:
  //   Constant: '<S9>/One1'
  //   Gain: '<S9>/Gain1'
  //   Sum: '<S9>/Add1'

  DiscreteTransferFcn3_tmp = static_cast<real32_T>(floor(static_cast<real_T>
    (P2R5_P.Gain1_Gain_l * DiscreteTransferFcn3_tmp + P2R5_P.One1_Value_b)));
  if (rtIsNaNF(DiscreteTransferFcn3_tmp) || rtIsInfF(DiscreteTransferFcn3_tmp))
  {
    DiscreteTransferFcn3_tmp = 0.0F;
  } else {
    DiscreteTransferFcn3_tmp = static_cast<real32_T>(fmod(static_cast<real_T>
      (DiscreteTransferFcn3_tmp), 65536.0));
  }

  // MATLABSystem: '<S9>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S9>/Cast To Double1'

  P2R5_B.pwmValue[1] = static_cast<uint16_T>(DiscreteTransferFcn3_tmp < 0.0F ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-DiscreteTransferFcn3_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(DiscreteTransferFcn3_tmp)));

  // Gain: '<S47>/Gain'
  DiscreteTransferFcn3_tmp = P2R5_P.Gain_Gain_l * P2R5_B.Fin_3_Cmd_rad;

  // Saturate: '<S9>/Saturation2'
  if (DiscreteTransferFcn3_tmp > P2R5_P.Saturation2_UpperSat) {
    DiscreteTransferFcn3_tmp = P2R5_P.Saturation2_UpperSat;
  } else if (DiscreteTransferFcn3_tmp < P2R5_P.Saturation2_LowerSat) {
    DiscreteTransferFcn3_tmp = P2R5_P.Saturation2_LowerSat;
  }

  // End of Saturate: '<S9>/Saturation2'

  // DataTypeConversion: '<S9>/Cast To Double2' incorporates:
  //   Constant: '<S9>/One2'
  //   Gain: '<S9>/Gain2'
  //   Sum: '<S9>/Add2'

  DiscreteTransferFcn3_tmp = static_cast<real32_T>(floor(static_cast<real_T>
    (P2R5_P.Gain2_Gain * DiscreteTransferFcn3_tmp + P2R5_P.One2_Value_o)));
  if (rtIsNaNF(DiscreteTransferFcn3_tmp) || rtIsInfF(DiscreteTransferFcn3_tmp))
  {
    DiscreteTransferFcn3_tmp = 0.0F;
  } else {
    DiscreteTransferFcn3_tmp = static_cast<real32_T>(fmod(static_cast<real_T>
      (DiscreteTransferFcn3_tmp), 65536.0));
  }

  // MATLABSystem: '<S9>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S9>/Cast To Double2'

  P2R5_B.pwmValue[2] = static_cast<uint16_T>(DiscreteTransferFcn3_tmp < 0.0F ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-DiscreteTransferFcn3_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(DiscreteTransferFcn3_tmp)));

  // Gain: '<S48>/Gain'
  DiscreteTransferFcn3_tmp = P2R5_P.Gain_Gain_p * P2R5_B.Fin_4_Cmd_rad;

  // Saturate: '<S9>/Saturation3'
  if (DiscreteTransferFcn3_tmp > P2R5_P.Saturation3_UpperSat) {
    DiscreteTransferFcn3_tmp = P2R5_P.Saturation3_UpperSat;
  } else if (DiscreteTransferFcn3_tmp < P2R5_P.Saturation3_LowerSat) {
    DiscreteTransferFcn3_tmp = P2R5_P.Saturation3_LowerSat;
  }

  // End of Saturate: '<S9>/Saturation3'

  // DataTypeConversion: '<S9>/Cast To Double3' incorporates:
  //   Constant: '<S9>/One3'
  //   Gain: '<S9>/Gain3'
  //   Sum: '<S9>/Add3'

  DiscreteTransferFcn3_tmp = static_cast<real32_T>(floor(static_cast<real_T>
    (P2R5_P.Gain3_Gain * DiscreteTransferFcn3_tmp + P2R5_P.One3_Value_p)));
  if (rtIsNaNF(DiscreteTransferFcn3_tmp) || rtIsInfF(DiscreteTransferFcn3_tmp))
  {
    DiscreteTransferFcn3_tmp = 0.0F;
  } else {
    DiscreteTransferFcn3_tmp = static_cast<real32_T>(fmod(static_cast<real_T>
      (DiscreteTransferFcn3_tmp), 65536.0));
  }

  // MATLABSystem: '<S9>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S9>/Cast To Double3'

  P2R5_B.pwmValue[3] = static_cast<uint16_T>(DiscreteTransferFcn3_tmp < 0.0F ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-DiscreteTransferFcn3_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(DiscreteTransferFcn3_tmp)));

  // Switch: '<S9>/Switch'
  if (P2R5_B.recovery_log) {
    // DataTypeConversion: '<S9>/Cast To Double4' incorporates:
    //   Constant: '<S9>/One5'

    P2R5_B.u00Hz = floor(P2R5_P.One5_Value);
    if (rtIsNaN(P2R5_B.u00Hz) || rtIsInf(P2R5_B.u00Hz)) {
      P2R5_B.u00Hz = 0.0;
    } else {
      P2R5_B.u00Hz = fmod(P2R5_B.u00Hz, 65536.0);
    }

    // MATLABSystem: '<S9>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S9>/Cast To Double4'

    P2R5_B.pwmValue[4] = static_cast<uint16_T>(P2R5_B.u00Hz < 0.0 ? static_cast<
      int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
      (-P2R5_B.u00Hz)))) : static_cast<int32_T>(static_cast<uint16_T>
      (P2R5_B.u00Hz)));
  } else {
    // DataTypeConversion: '<S9>/Cast To Double4' incorporates:
    //   Constant: '<S9>/One6'

    P2R5_B.u00Hz = floor(P2R5_P.One6_Value);
    if (rtIsNaN(P2R5_B.u00Hz) || rtIsInf(P2R5_B.u00Hz)) {
      P2R5_B.u00Hz = 0.0;
    } else {
      P2R5_B.u00Hz = fmod(P2R5_B.u00Hz, 65536.0);
    }

    // MATLABSystem: '<S9>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S9>/Cast To Double4'

    P2R5_B.pwmValue[4] = static_cast<uint16_T>(P2R5_B.u00Hz < 0.0 ? static_cast<
      int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
      (-P2R5_B.u00Hz)))) : static_cast<int32_T>(static_cast<uint16_T>
      (P2R5_B.u00Hz)));
  }

  // End of Switch: '<S9>/Switch'

  // MATLABSystem: '<S9>/PX4 PWM Output1' incorporates:
  //   Constant: '<S9>/One4'
  //   Constant: '<S9>/One7'

  if (P2R5_P.One7_Value_m) {
    if (!P2R5_DW.obj_m.isArmed) {
      P2R5_DW.obj_m.isArmed = true;
      status = pwm_arm(&P2R5_DW.obj_m.pwmDevHandler,
                       &P2R5_DW.obj_m.armAdvertiseObj);
      P2R5_DW.obj_m.errorStatus = static_cast<uint16_T>
        (P2R5_DW.obj_m.errorStatus | status);
    }

    status = pwm_setServo(&P2R5_DW.obj_m.pwmDevHandler, P2R5_DW.obj_m.servoCount,
                          P2R5_DW.obj_m.channelMask, &P2R5_B.pwmValue[0],
                          P2R5_DW.obj_m.isMain,
                          &P2R5_DW.obj_m.actuatorAdvertiseObj);
    P2R5_DW.obj_m.errorStatus = static_cast<uint16_T>(P2R5_DW.obj_m.errorStatus |
      status);
  } else {
    status = pwm_disarm(&P2R5_DW.obj_m.pwmDevHandler,
                        &P2R5_DW.obj_m.armAdvertiseObj);
    P2R5_DW.obj_m.errorStatus = static_cast<uint16_T>(P2R5_DW.obj_m.errorStatus |
      status);
    P2R5_DW.obj_m.isArmed = false;
    status = pwm_resetServo(&P2R5_DW.obj_m.pwmDevHandler,
      P2R5_DW.obj_m.servoCount, P2R5_DW.obj_m.channelMask, P2R5_DW.obj_m.isMain,
      &P2R5_DW.obj_m.actuatorAdvertiseObj);
    P2R5_DW.obj_m.errorStatus = static_cast<uint16_T>(P2R5_DW.obj_m.errorStatus |
      status);
  }

  if (P2R5_DW.obj_m.isMain) {
    status = pwm_forceFailsafe(&P2R5_DW.obj_m.pwmDevHandler, static_cast<int32_T>
      (P2R5_P.One4_Value_n));
    P2R5_DW.obj_m.errorStatus = static_cast<uint16_T>(P2R5_DW.obj_m.errorStatus |
      status);
  }

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_9_Threshold) {
    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Constant: '<S43>/One8'
    //   Outport: '<Root>/Serial Out'

    P2R5_Y.SerialOut[16] = P2R5_P.One8_Value;
  } else {
    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    P2R5_Y.SerialOut[16] = P2R5_U.SerialIn[12];
  }

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_8_Threshold) {
    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Constant: '<S43>/One7'
    //   Outport: '<Root>/Serial Out'

    P2R5_Y.SerialOut[15] = P2R5_P.One7_Value;
  } else {
    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    P2R5_Y.SerialOut[15] = P2R5_U.SerialIn[11];
  }

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[14] = rtb_p;

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[13] = rtb_z;

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_5_Threshold) {
    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Constant: '<S43>/One4'
    //   Outport: '<Root>/Serial Out'

    P2R5_Y.SerialOut[12] = P2R5_P.One4_Value;
  } else {
    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    P2R5_Y.SerialOut[12] = P2R5_U.SerialIn[8];
  }

  // Switch generated from: '<S7>/Switch' incorporates:
  //   Inport: '<Root>/Serial In'

  if (P2R5_U.SerialIn[2] > P2R5_P.Switch_4_Threshold) {
    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Constant: '<S43>/One3'
    //   Outport: '<Root>/Serial Out'

    P2R5_Y.SerialOut[11] = P2R5_P.One3_Value;
  } else {
    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    P2R5_Y.SerialOut[11] = P2R5_U.SerialIn[7];
  }

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[10] = rtb_w;

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[9] = rtb_v;

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[8] = P2R5_B.u;

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/Serial In'
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[0] = P2R5_U.SerialIn[1];

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/Serial In'
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[5] = P2R5_U.SerialIn[16];

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/Serial In'
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[6] = P2R5_U.SerialIn[17];

  // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/Serial In'
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[7] = P2R5_U.SerialIn[18];

  // Constant: '<S2>/Zero' incorporates:
  //   Outport: '<Root>/Serial Out'

  P2R5_Y.SerialOut[17] = P2R5_P.Zero_Value_a;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.001, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  P2R5_M->Timing.clockTick0++;
}

// Model initialize function
void P2R5_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    c_dsp_private_SlidingWindowAverageCG_P2R5_T *obj;
    int32_T i;
    P2R5_PrevZCX.Autopilot_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // SystemInitialize for Triggered SubSystem: '<S2>/Autopilot'
    // InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S15>/Constant'

    P2R5_DW.DiscreteTimeIntegrator_DSTATE_no = P2R5_P.Constant_Value_o;

    // InitializeConditions for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn3' 
    P2R5_DW.DiscreteTransferFcn3_states =
      P2R5_P.DiscreteTransferFcn3_InitialStates;

    // InitializeConditions for UnitDelay: '<S25>/Delay Input1'
    //
    //  Block description for '<S25>/Delay Input1':
    //
    //   Store in Global RAM

    P2R5_DW.DelayInput1_DSTATE = P2R5_P.DetectDecrease_vinit;

    // InitializeConditions for DiscreteIntegrator: '<S26>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S26>/Constant1'

    P2R5_DW.DiscreteTimeIntegrator_DSTATE = P2R5_P.Constant1_Value_g;

    // InitializeConditions for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' 
    P2R5_DW.DiscreteTransferFcn_states =
      P2R5_P.DiscreteTransferFcn_InitialStates;

    // InitializeConditions for Switch: '<S31>/Switch1' incorporates:
    //   Memory: '<S19>/Memory'

    P2R5_DW.Memory_PreviousInput = P2R5_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S30>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S30>/Constant1'

    P2R5_DW.DiscreteTimeIntegrator_DSTATE_n = P2R5_P.Constant1_Value_m;

    // InitializeConditions for Memory: '<S31>/Memory'
    P2R5_DW.Memory_PreviousInput_f = P2R5_P.Memory_InitialCondition_f;

    // InitializeConditions for DiscreteIntegrator: '<S35>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S35>/Constant1'

    P2R5_DW.DiscreteTimeIntegrator_DSTATE_p = P2R5_P.Constant1_Value_f;

    // InitializeConditions for Switch: '<S36>/Switch1' incorporates:
    //   Memory: '<S36>/Memory'

    P2R5_DW.Memory_PreviousInput_l = P2R5_P.Memory_InitialCondition_p;

    // InitializeConditions for Switch: '<S27>/Switch1' incorporates:
    //   Memory: '<S27>/Memory'

    P2R5_DW.Memory_PreviousInput_e = P2R5_P.Memory_InitialCondition_n;

    // InitializeConditions for DiscreteIntegrator: '<S39>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S39>/Constant1'

    P2R5_DW.DiscreteTimeIntegrator_DSTATE_o = P2R5_P.Constant1_Value_e;

    // InitializeConditions for Switch: '<S40>/Switch1' incorporates:
    //   Memory: '<S40>/Memory'

    P2R5_DW.Memory_PreviousInput_p = P2R5_P.Memory_InitialCondition_m;

    // Start for MATLABSystem: '<S17>/Moving Average1'
    P2R5_DW.obj.matlabCodegenIsDeleted = true;
    P2R5_DW.obj.isInitialized = 0;
    P2R5_DW.obj.NumChannels = -1;
    P2R5_DW.obj.matlabCodegenIsDeleted = false;
    P2R5_DW.obj.isSetupComplete = false;
    P2R5_DW.obj.isInitialized = 1;
    P2R5_DW.obj.NumChannels = 1;
    P2R5_DW.obj._pobj0.isInitialized = 0;
    P2R5_DW.obj.pStatistic = &P2R5_DW.obj._pobj0;
    P2R5_DW.obj.isSetupComplete = true;
    P2R5_DW.obj.TunablePropsChanged = false;

    // InitializeConditions for MATLABSystem: '<S17>/Moving Average1'
    obj = P2R5_DW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0F;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0F;
      }

      obj->pCumRevIndex = 1.0F;
    }

    // End of InitializeConditions for MATLABSystem: '<S17>/Moving Average1'

    // SystemInitialize for Outport: '<S3>/Fin Deflections'
    P2R5_B.siB_cmd[0] = P2R5_P.FinDeflections_Y0.Fin_1_Cmd_rad;
    P2R5_B.siB_cmd[1] = P2R5_P.FinDeflections_Y0.Fin_2_Cmd_rad;
    P2R5_B.siB_cmd[2] = P2R5_P.FinDeflections_Y0.Fin_3_Cmd_rad;
    P2R5_B.siB_cmd[3] = P2R5_P.FinDeflections_Y0.Fin_4_Cmd_rad;

    // SystemInitialize for Outport: '<Root>/flight_mode_enum' incorporates:
    //   Outport: '<S3>/flight_mode_enum'

    P2R5_Y.flight_mode_enum = P2R5_P.flight_mode_enum_Y0;

    // SystemInitialize for SignalConversion generated from: '<S3>/Fin Cmd' incorporates:
    //   Outport: '<S3>/Fin Cmd'

    P2R5_B.Fin_1_Cmd_rad = P2R5_P.FinCmd_Y0.Fin_1_Cmd_rad;

    // SystemInitialize for SignalConversion generated from: '<S3>/Fin Cmd' incorporates:
    //   Outport: '<S3>/Fin Cmd'

    P2R5_B.Fin_2_Cmd_rad = P2R5_P.FinCmd_Y0.Fin_2_Cmd_rad;

    // SystemInitialize for SignalConversion generated from: '<S3>/Fin Cmd' incorporates:
    //   Outport: '<S3>/Fin Cmd'

    P2R5_B.Fin_3_Cmd_rad = P2R5_P.FinCmd_Y0.Fin_3_Cmd_rad;

    // SystemInitialize for SignalConversion generated from: '<S3>/Fin Cmd' incorporates:
    //   Outport: '<S3>/Fin Cmd'

    P2R5_B.Fin_4_Cmd_rad = P2R5_P.FinCmd_Y0.Fin_4_Cmd_rad;

    // SystemInitialize for Logic: '<S21>/AND2' incorporates:
    //   Outport: '<S3>/Recovery'

    P2R5_B.recovery_log = P2R5_P.Recovery_Y0;

    // End of SystemInitialize for SubSystem: '<S2>/Autopilot'

    // Start for MATLABSystem: '<S9>/PX4 PWM Output1' incorporates:
    //   Constant: '<S9>/One4'
    //   Constant: '<S9>/One7'

    P2R5_DW.obj_m.errorStatus = 0U;
    P2R5_DW.obj_m.isInitialized = 0;
    P2R5_DW.obj_m.matlabCodegenIsDeleted = false;
    P2R5_SystemCore_setup(&P2R5_DW.obj_m, P2R5_P.One7_Value_m,
                          P2R5_P.One4_Value_n);

    // Enable for Triggered SubSystem: '<S2>/Autopilot'
    P2R5_DW.Autopilot_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;

    // Enable for DiscreteIntegrator: '<S26>/Discrete-Time Integrator'
    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h = 1U;

    // Enable for DiscreteIntegrator: '<S30>/Discrete-Time Integrator'
    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e = 1U;

    // Enable for DiscreteIntegrator: '<S35>/Discrete-Time Integrator'
    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d = 1U;

    // Enable for DiscreteIntegrator: '<S39>/Discrete-Time Integrator'
    P2R5_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec = 1U;

    // End of Enable for SubSystem: '<S2>/Autopilot'
  }
}

// Model terminate function
void P2R5_terminate(void)
{
  c_dsp_private_SlidingWindowAverageCG_P2R5_T *obj;
  uint16_T status;

  // Terminate for Triggered SubSystem: '<S2>/Autopilot'
  // Terminate for MATLABSystem: '<S17>/Moving Average1'
  if (!P2R5_DW.obj.matlabCodegenIsDeleted) {
    P2R5_DW.obj.matlabCodegenIsDeleted = true;
    if ((P2R5_DW.obj.isInitialized == 1) && P2R5_DW.obj.isSetupComplete) {
      obj = P2R5_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      P2R5_DW.obj.NumChannels = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S17>/Moving Average1'
  // End of Terminate for SubSystem: '<S2>/Autopilot'

  // Terminate for MATLABSystem: '<S9>/PX4 PWM Output1'
  if (!P2R5_DW.obj_m.matlabCodegenIsDeleted) {
    P2R5_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((P2R5_DW.obj_m.isInitialized == 1) && P2R5_DW.obj_m.isSetupComplete) {
      status = pwm_disarm(&P2R5_DW.obj_m.pwmDevHandler,
                          &P2R5_DW.obj_m.armAdvertiseObj);
      P2R5_DW.obj_m.errorStatus = static_cast<uint16_T>
        (P2R5_DW.obj_m.errorStatus | status);
      status = pwm_resetServo(&P2R5_DW.obj_m.pwmDevHandler,
        P2R5_DW.obj_m.servoCount, P2R5_DW.obj_m.channelMask,
        P2R5_DW.obj_m.isMain, &P2R5_DW.obj_m.actuatorAdvertiseObj);
      P2R5_DW.obj_m.errorStatus = static_cast<uint16_T>
        (P2R5_DW.obj_m.errorStatus | status);
      status = pwm_close(&P2R5_DW.obj_m.pwmDevHandler,
                         &P2R5_DW.obj_m.actuatorAdvertiseObj,
                         &P2R5_DW.obj_m.armAdvertiseObj);
      P2R5_DW.obj_m.errorStatus = static_cast<uint16_T>
        (P2R5_DW.obj_m.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S9>/PX4 PWM Output1'
}

//
// File trailer for generated code.
//
// [EOF]
//
