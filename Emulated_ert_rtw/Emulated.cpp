//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Emulated.cpp
//
// Code generated for Simulink model 'Emulated'.
//
// Model version                  : 4.48
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon May 10 17:26:16 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Emulated.h"
#include "Emulated_private.h"

// Block signals (default storage)
B_Emulated_T Emulated_B;

// Block states (default storage)
DW_Emulated_T Emulated_DW;

// Previous zero-crossings (trigger) states
PrevZCX_Emulated_T Emulated_PrevZCX;

// External inputs (root inport signals with default storage)
ExtU_Emulated_T Emulated_U;

// External outputs (root outports fed by signals with default storage)
ExtY_Emulated_T Emulated_Y;

// Real-time model
RT_MODEL_Emulated_T Emulated_M_ = RT_MODEL_Emulated_T();
RT_MODEL_Emulated_T *const Emulated_M = &Emulated_M_;

// Forward declaration for local functions
static void Emulated_SystemCore_setup(px4_internal_block_PWM_Emulated_T *obj,
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

static void Emulated_SystemCore_setup(px4_internal_block_PWM_Emulated_T *obj,
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
void Emulated_step(void)
{
  c_dsp_private_SlidingWindowAverageCG_Emulated_T *obj;
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

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Constant: '<S42>/One'
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_1_Threshold) {
    Emulated_B.u = Emulated_P.One_Value;
  } else {
    Emulated_B.u = Emulated_U.SerialIn[4];
  }

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Constant: '<S42>/One1'
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_2_Threshold) {
    rtb_v = Emulated_P.One1_Value;
  } else {
    rtb_v = Emulated_U.SerialIn[5];
  }

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Constant: '<S42>/One2'
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_3_Threshold) {
    rtb_w = Emulated_P.One2_Value;
  } else {
    rtb_w = Emulated_U.SerialIn[6];
  }

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Constant: '<S42>/One5'
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_6_Threshold) {
    rtb_z = Emulated_P.One5_Value_o;
  } else {
    rtb_z = Emulated_U.SerialIn[9];
  }

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Constant: '<S42>/One6'
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_7_Threshold) {
    rtb_p = Emulated_P.One6_Value_c;
  } else {
    rtb_p = Emulated_U.SerialIn[10];
  }

  // DiscretePulseGenerator: '<S1>/100 Hz'
  Emulated_B.u00Hz = (Emulated_DW.clockTickCounter < Emulated_P.u00Hz_Duty) &&
    (Emulated_DW.clockTickCounter >= 0) ? Emulated_P.u00Hz_Amp : 0.0;
  if (Emulated_DW.clockTickCounter >= Emulated_P.u00Hz_Period - 1.0) {
    Emulated_DW.clockTickCounter = 0;
  } else {
    Emulated_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S1>/100 Hz'

  // Outputs for Triggered SubSystem: '<S1>/Autopilot' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,&Emulated_PrevZCX.Autopilot_Trig_ZCE,
                     (Emulated_B.u00Hz));
  if (zcEvent != NO_ZCEVENT) {
    if (Emulated_DW.Autopilot_RESET_ELAPS_T) {
      Autopilot_ELAPS_T = 0U;
    } else {
      Autopilot_ELAPS_T = Emulated_M->Timing.clockTick0 -
        Emulated_DW.Autopilot_PREV_T;
    }

    Emulated_DW.Autopilot_PREV_T = Emulated_M->Timing.clockTick0;
    Emulated_DW.Autopilot_RESET_ELAPS_T = false;

    // Gain: '<S2>/Gain1'
    rtb_Gain1_o = Emulated_P.Gain1_Gain * rtb_z;

    // Sqrt: '<S9>/Square Root' incorporates:
    //   Math: '<S9>/Square'
    //   Math: '<S9>/Square1'
    //   Math: '<S9>/Square2'
    //   Sum: '<S9>/Add'

    rtb_Add3 = static_cast<real32_T>(sqrt(static_cast<real_T>((Emulated_B.u *
      Emulated_B.u + rtb_v * rtb_v) + rtb_w * rtb_w)));

    // Switch generated from: '<S6>/Switch' incorporates:
    //   Constant: '<S42>/One9'
    //   Inport: '<Root>/Serial In'

    if (Emulated_U.SerialIn[2] > Emulated_P.Switch_10_Threshold) {
      DiscreteTransferFcn3_tmp = Emulated_P.One9_Value;
    } else {
      DiscreteTransferFcn3_tmp = Emulated_U.SerialIn[19];
    }

    // Sum: '<S14>/Sum3' incorporates:
    //   Inport: '<Root>/Serial In'

    rtb_DiscreteTransferFcn = Emulated_U.SerialIn[22] - DiscreteTransferFcn3_tmp;

    // DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S10>/Constant'
    //   Constant: '<S14>/Constant'

    if (Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE == 0) {
      if (Emulated_P.Constant_Value_c ||
          (Emulated_DW.DiscreteTimeIntegrator_PrevResetState != 0)) {
        Emulated_DW.DiscreteTimeIntegrator_DSTATE_no =
          Emulated_P.Constant_Value_o;
      } else {
        // DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
        Emulated_DW.DiscreteTimeIntegrator_DSTATE_no +=
          Emulated_P.DiscreteTimeIntegrator_gainval_m * static_cast<real32_T>
          (Autopilot_ELAPS_T) * Emulated_DW.DiscreteTimeIntegrator_PREV_U_j;
      }
    }

    // End of DiscreteIntegrator: '<S14>/Discrete-Time Integrator'

    // DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn3'
    DiscreteTransferFcn3_tmp = (rtb_p - Emulated_P.DiscreteTransferFcn3_DenCoef
      [1] * Emulated_DW.DiscreteTransferFcn3_states) /
      Emulated_P.DiscreteTransferFcn3_DenCoef[0];

    // Product: '<S14>/Product1' incorporates:
    //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn3'
    //   Gain: '<S2>/Gain1'
    //   Lookup_n-D: '<S40>/1-D Lookup Table3'
    //   Lookup_n-D: '<S40>/1-D Lookup Table5'
    //   Product: '<S14>/Product2'
    //   Sum: '<S14>/Sum4'
    //   Sum: '<S14>/Sum5'
    //   Sum: '<S8>/Add3'

    rtb_fin_cmd_idx_0 = ((look2_iflf_binlcapw(rtb_Gain1_o, rtb_Add3,
      Emulated_P.uDLookupTable5_bp01Data, Emulated_P.uDLookupTable5_bp02Data,
      Emulated_P.uDLookupTable5_tableData, Emulated_P.uDLookupTable5_maxIndex,
      3U) * rtb_DiscreteTransferFcn +
                          Emulated_DW.DiscreteTimeIntegrator_DSTATE_no) -
                         (Emulated_P.DiscreteTransferFcn3_NumCoef[0] *
                          DiscreteTransferFcn3_tmp +
                          Emulated_P.DiscreteTransferFcn3_NumCoef[1] *
                          Emulated_DW.DiscreteTransferFcn3_states)) *
      look2_iflf_binlcapw(rtb_Gain1_o, rtb_Add3,
                          Emulated_P.uDLookupTable3_bp01Data,
                          Emulated_P.uDLookupTable3_bp02Data,
                          Emulated_P.uDLookupTable3_tableData,
                          Emulated_P.uDLookupTable3_maxIndex, 3U);
    for (i = 0; i < 4; i++) {
      // Product: '<S15>/Product' incorporates:
      //   Constant: '<S14>/Zero'
      //   Constant: '<S15>/Constant7'

      Emulated_B.siB_cmd[i] = 0.0F;
      Emulated_B.siB_cmd[i] += Emulated_P.Constant7_Value[i] * rtb_fin_cmd_idx_0;
      Emulated_B.siB_cmd[i] += Emulated_P.Constant7_Value[i + 4] *
        Emulated_P.Zero_Value;
      Emulated_B.siB_cmd[i] += Emulated_P.Constant7_Value[i + 8] *
        Emulated_P.Zero_Value;
    }

    // SignalConversion generated from: '<S2>/Fin Cmd'
    Emulated_B.Fin_1_Cmd_rad = Emulated_B.siB_cmd[0];

    // SignalConversion generated from: '<S2>/Fin Cmd'
    Emulated_B.Fin_2_Cmd_rad = Emulated_B.siB_cmd[1];

    // SignalConversion generated from: '<S2>/Fin Cmd'
    Emulated_B.Fin_3_Cmd_rad = Emulated_B.siB_cmd[2];

    // SignalConversion generated from: '<S2>/Fin Cmd'
    Emulated_B.Fin_4_Cmd_rad = Emulated_B.siB_cmd[3];

    // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
    //   Gain: '<S2>/Gain1'
    //   Lookup_n-D: '<S40>/1-D Lookup Table4'
    //   Product: '<S14>/Product3'
    //   Sum: '<S8>/Add3'

    Emulated_DW.DiscreteTimeIntegrator_PREV_U_j = look2_iflf_binlcapw
      (rtb_Gain1_o, rtb_Add3, Emulated_P.uDLookupTable4_bp01Data,
       Emulated_P.uDLookupTable4_bp02Data, Emulated_P.uDLookupTable4_tableData,
       Emulated_P.uDLookupTable4_maxIndex, 3U) * rtb_DiscreteTransferFcn;

    // MATLABSystem: '<S16>/Moving Average1'
    if (Emulated_DW.obj.TunablePropsChanged) {
      Emulated_DW.obj.TunablePropsChanged = false;
    }

    obj = Emulated_DW.obj.pStatistic;
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
      Emulated_B.csumrev[i] = obj->pCumSumRev[i];
    }

    rtb_DiscreteTransferFcn += rtb_Gain1_o;
    rtb_fin_cmd_idx_0 = Emulated_B.csumrev[static_cast<int32_T>(rtb_Add3) - 1] +
      rtb_DiscreteTransferFcn;
    Emulated_B.csumrev[static_cast<int32_T>(rtb_Add3) - 1] = rtb_Gain1_o;
    if (rtb_Add3 != 9.0F) {
      rtb_Add3++;
    } else {
      rtb_Add3 = 1.0F;
      rtb_DiscreteTransferFcn = 0.0F;
      for (i = 7; i >= 0; i--) {
        Emulated_B.csumrev[i] += Emulated_B.csumrev[i + 1];
      }
    }

    obj->pCumSum = rtb_DiscreteTransferFcn;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = Emulated_B.csumrev[i];
    }

    obj->pCumRevIndex = rtb_Add3;
    rtb_Gain1_o = rtb_fin_cmd_idx_0 / 10.0F;

    // End of MATLABSystem: '<S16>/Moving Average1'

    // Logic: '<S25>/NOT' incorporates:
    //   RelationalOperator: '<S24>/FixPt Relational Operator'
    //   UnitDelay: '<S24>/Delay Input1'
    //
    //  Block description for '<S24>/Delay Input1':
    //
    //   Store in Global RAM

    rtb_NOT = !(rtb_Gain1_o < Emulated_DW.DelayInput1_DSTATE);

    // DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S25>/Constant1'

    if (Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h == 0) {
      if (rtb_NOT || (Emulated_DW.DiscreteTimeIntegrator_PrevResetState_j != 0))
      {
        Emulated_DW.DiscreteTimeIntegrator_DSTATE = Emulated_P.Constant1_Value_g;
      } else {
        // DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
        Emulated_DW.DiscreteTimeIntegrator_DSTATE +=
          Emulated_P.DiscreteTimeIntegrator_gainval * static_cast<real_T>
          (Autopilot_ELAPS_T) * Emulated_DW.DiscreteTimeIntegrator_PREV_U;
      }
    }

    // End of DiscreteIntegrator: '<S25>/Discrete-Time Integrator'

    // DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' incorporates:
    //   Inport: '<Root>/Serial In'

    rtb_Add3 = (Emulated_U.SerialIn[13] -
                Emulated_P.DiscreteTransferFcn_DenCoef[1] *
                Emulated_DW.DiscreteTransferFcn_states) /
      Emulated_P.DiscreteTransferFcn_DenCoef[0];
    rtb_DiscreteTransferFcn = Emulated_P.DiscreteTransferFcn_NumCoef[0] *
      rtb_Add3 + Emulated_P.DiscreteTransferFcn_NumCoef[1] *
      Emulated_DW.DiscreteTransferFcn_states;

    // RelationalOperator: '<S27>/Compare' incorporates:
    //   Constant: '<S27>/Constant'
    //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'

    rtb_Memory = (rtb_DiscreteTransferFcn >= Emulated_P.CompareToConstant_const);

    // Logic: '<S29>/NOT' incorporates:
    //   Logic: '<S29>/AND'
    //   Memory: '<S18>/Memory'

    rtb_NOT_h = ((!rtb_Memory) && (!Emulated_DW.Memory_PreviousInput));

    // DiscreteIntegrator: '<S29>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S29>/Constant1'

    if (Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e == 0) {
      if (rtb_NOT_h || (Emulated_DW.DiscreteTimeIntegrator_PrevResetState_i != 0))
      {
        Emulated_DW.DiscreteTimeIntegrator_DSTATE_n =
          Emulated_P.Constant1_Value_m;
      } else {
        // DiscreteIntegrator: '<S29>/Discrete-Time Integrator'
        Emulated_DW.DiscreteTimeIntegrator_DSTATE_n +=
          Emulated_P.DiscreteTimeIntegrator_gainval_l * static_cast<real_T>
          (Autopilot_ELAPS_T) * Emulated_DW.DiscreteTimeIntegrator_PREV_U_m;
      }
    }

    // End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator'

    // Switch: '<S30>/Switch1' incorporates:
    //   Constant: '<S28>/Constant'
    //   Logic: '<S18>/AND'
    //   Memory: '<S30>/Memory'
    //   RelationalOperator: '<S28>/Compare'

    Emulated_DW.Memory_PreviousInput = ((rtb_Memory &&
      (Emulated_DW.DiscreteTimeIntegrator_DSTATE_n >=
       Emulated_P.Flight_Logic.Ax_launch_timer_threshold_sec)) ||
      Emulated_DW.Memory_PreviousInput_f);

    // Logic: '<S34>/NOT' incorporates:
    //   Constant: '<S32>/Constant'
    //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
    //   Logic: '<S19>/AND'
    //   RelationalOperator: '<S32>/Compare'

    rtb_Memory = ((!Emulated_DW.Memory_PreviousInput) ||
                  (!(rtb_DiscreteTransferFcn <=
                     Emulated_P.CompareToConstant2_const)));

    // DiscreteIntegrator: '<S34>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S34>/Constant1'

    if (Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d == 0) {
      if (rtb_Memory || (Emulated_DW.DiscreteTimeIntegrator_PrevResetState_iw !=
                         0)) {
        Emulated_DW.DiscreteTimeIntegrator_DSTATE_p =
          Emulated_P.Constant1_Value_f;
      } else {
        // DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
        Emulated_DW.DiscreteTimeIntegrator_DSTATE_p +=
          Emulated_P.DiscreteTimeIntegrator_gainval_k * static_cast<real_T>
          (Autopilot_ELAPS_T) * Emulated_DW.DiscreteTimeIntegrator_PREV_U_a;
      }
    }

    // End of DiscreteIntegrator: '<S34>/Discrete-Time Integrator'

    // Switch: '<S35>/Switch1' incorporates:
    //   Constant: '<S31>/Constant'
    //   Memory: '<S35>/Memory'
    //   RelationalOperator: '<S31>/Compare'

    Emulated_DW.Memory_PreviousInput_l =
      ((Emulated_DW.DiscreteTimeIntegrator_DSTATE_p >=
        Emulated_P.Flight_Logic.Ax_MECO_timer_threshold_sec) ||
       Emulated_DW.Memory_PreviousInput_l);

    // Switch: '<S18>/Switch' incorporates:
    //   Constant: '<S18>/Constant'

    if (Emulated_DW.Memory_PreviousInput) {
      Emulated_B.u00Hz = Emulated_DW.DiscreteTimeIntegrator_DSTATE_n;
    } else {
      Emulated_B.u00Hz = Emulated_P.Constant_Value_l;
    }

    // End of Switch: '<S18>/Switch'

    // Logic: '<S19>/AND1' incorporates:
    //   Constant: '<S33>/Constant'
    //   RelationalOperator: '<S33>/Compare'

    rtb_MECO_log = (Emulated_DW.Memory_PreviousInput_l || (Emulated_B.u00Hz >=
      Emulated_P.Flight_Logic.MECO_timeout_TOF_sec));

    // Switch: '<S26>/Switch1' incorporates:
    //   Constant: '<S21>/Constant'
    //   Constant: '<S22>/Constant'
    //   Logic: '<S16>/AND'
    //   Memory: '<S26>/Memory'
    //   RelationalOperator: '<S21>/Compare'
    //   RelationalOperator: '<S22>/Compare'

    Emulated_DW.Memory_PreviousInput_e = ((rtb_MECO_log &&
      (Emulated_DW.DiscreteTimeIntegrator_DSTATE >=
       Emulated_P.Flight_Logic.h_apogee_timer_threshold_sec) && (rtb_w >
      Emulated_P.CompareToConstant_const_g)) ||
      Emulated_DW.Memory_PreviousInput_e);

    // Logic: '<S38>/NOT' incorporates:
    //   Constant: '<S23>/Constant'
    //   Logic: '<S16>/AND1'
    //   RelationalOperator: '<S23>/Compare'

    rtb_NOT_d = ((!Emulated_DW.Memory_PreviousInput_e) && (!(Emulated_B.u00Hz >=
      Emulated_P.Flight_Logic.apogee_timeout_TOF_sec)));

    // DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S38>/Constant1'

    if (Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec == 0) {
      if (rtb_NOT_d || (Emulated_DW.DiscreteTimeIntegrator_PrevResetState_ii !=
                        0)) {
        Emulated_DW.DiscreteTimeIntegrator_DSTATE_o =
          Emulated_P.Constant1_Value_e;
      } else {
        // DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
        Emulated_DW.DiscreteTimeIntegrator_DSTATE_o +=
          Emulated_P.DiscreteTimeIntegrator_gainval_o * static_cast<real_T>
          (Autopilot_ELAPS_T) * Emulated_DW.DiscreteTimeIntegrator_PREV_U_mh;
      }
    }

    // End of DiscreteIntegrator: '<S38>/Discrete-Time Integrator'

    // Switch: '<S39>/Switch1' incorporates:
    //   Constant: '<S36>/Constant'
    //   Memory: '<S39>/Memory'
    //   RelationalOperator: '<S36>/Compare'

    Emulated_DW.Memory_PreviousInput_p =
      ((Emulated_DW.DiscreteTimeIntegrator_DSTATE_o >=
        Emulated_P.Flight_Logic.apogee_recovery_timer_threshold_sec) ||
       Emulated_DW.Memory_PreviousInput_p);

    // Logic: '<S20>/AND2' incorporates:
    //   Constant: '<S20>/Constant'
    //   Constant: '<S37>/Constant'
    //   Logic: '<S20>/AND1'
    //   Logic: '<S20>/NOT'
    //   RelationalOperator: '<S37>/Compare'

    Emulated_B.recovery_log = ((Emulated_DW.Memory_PreviousInput_p ||
      (Emulated_B.u00Hz >= Emulated_P.Flight_Logic.recovery_timeout_TOF_sec)) &&
      (!(Emulated_P.Flight_Logic.disable_recovery_manual != 0.0)));

    // Switch: '<S17>/Switch3' incorporates:
    //   Constant: '<S12>/Constant5'
    //   Constant: '<S17>/Constant5'
    //   Switch: '<S17>/Switch'
    //   Switch: '<S17>/Switch1'
    //   Switch: '<S17>/Switch2'
    //   Switch: '<S17>/Switch4'

    if (Emulated_B.recovery_log) {
      // Outport: '<Root>/flight_mode_enum' incorporates:
      //   Constant: '<S17>/Constant4'

      Emulated_Y.flight_mode_enum = Emulated_P.Constant4_Value;
    } else if (Emulated_P.Constant5_Value_k != 0.0) {
      // Switch: '<S17>/Switch4' incorporates:
      //   Constant: '<S17>/Constant6'
      //   Outport: '<Root>/flight_mode_enum'

      Emulated_Y.flight_mode_enum = Emulated_P.Constant6_Value;
    } else if (rtb_MECO_log) {
      // Switch: '<S17>/Switch2' incorporates:
      //   Constant: '<S17>/Constant3'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S17>/Switch4'

      Emulated_Y.flight_mode_enum = Emulated_P.Constant3_Value;
    } else if (Emulated_DW.Memory_PreviousInput) {
      // Switch: '<S17>/Switch1' incorporates:
      //   Constant: '<S17>/Constant2'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S17>/Switch2'
      //   Switch: '<S17>/Switch4'

      Emulated_Y.flight_mode_enum = Emulated_P.Constant2_Value;
    } else if (Emulated_P.Constant5_Value != 0.0) {
      // Switch: '<S17>/Switch' incorporates:
      //   Constant: '<S17>/Constant1'
      //   Outport: '<Root>/flight_mode_enum'
      //   Switch: '<S17>/Switch1'
      //   Switch: '<S17>/Switch2'
      //   Switch: '<S17>/Switch4'

      Emulated_Y.flight_mode_enum = Emulated_P.Constant1_Value;
    } else {
      // Outport: '<Root>/flight_mode_enum' incorporates:
      //   Constant: '<S17>/Constant'
      //   Switch: '<S17>/Switch1'
      //   Switch: '<S17>/Switch2'
      //   Switch: '<S17>/Switch4'

      Emulated_Y.flight_mode_enum = Emulated_P.Constant_Value;
    }

    // End of Switch: '<S17>/Switch3'

    // Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S10>/Constant'

    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
    Emulated_DW.DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
      (Emulated_P.Constant_Value_c);

    // Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn3'
    Emulated_DW.DiscreteTransferFcn3_states = DiscreteTransferFcn3_tmp;

    // Update for UnitDelay: '<S24>/Delay Input1'
    //
    //  Block description for '<S24>/Delay Input1':
    //
    //   Store in Global RAM

    Emulated_DW.DelayInput1_DSTATE = rtb_Gain1_o;

    // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S25>/Constant'

    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h = 0U;
    Emulated_DW.DiscreteTimeIntegrator_PrevResetState_j = static_cast<int8_T>
      (rtb_NOT);
    Emulated_DW.DiscreteTimeIntegrator_PREV_U = Emulated_P.Constant_Value_a;

    // Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
    Emulated_DW.DiscreteTransferFcn_states = rtb_Add3;

    // Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S29>/Constant'

    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e = 0U;
    Emulated_DW.DiscreteTimeIntegrator_PrevResetState_i = static_cast<int8_T>
      (rtb_NOT_h);
    Emulated_DW.DiscreteTimeIntegrator_PREV_U_m = Emulated_P.Constant_Value_lo;

    // Update for Memory: '<S30>/Memory'
    Emulated_DW.Memory_PreviousInput_f = Emulated_DW.Memory_PreviousInput;

    // Update for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S34>/Constant'

    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d = 0U;
    Emulated_DW.DiscreteTimeIntegrator_PrevResetState_iw = static_cast<int8_T>
      (rtb_Memory);
    Emulated_DW.DiscreteTimeIntegrator_PREV_U_a = Emulated_P.Constant_Value_b;

    // Update for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S38>/Constant'

    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec = 0U;
    Emulated_DW.DiscreteTimeIntegrator_PrevResetState_ii = static_cast<int8_T>
      (rtb_NOT_d);
    Emulated_DW.DiscreteTimeIntegrator_PREV_U_mh = Emulated_P.Constant_Value_bq;
  }

  // End of Outputs for SubSystem: '<S1>/Autopilot'

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[1] = Emulated_B.siB_cmd[0];

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[2] = Emulated_B.siB_cmd[1];

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[3] = Emulated_B.siB_cmd[2];

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[4] = Emulated_B.siB_cmd[3];

  // MATLABSystem: '<S8>/PX4 PWM Output1'
  for (i = 0; i < 8; i++) {
    Emulated_B.pwmValue[i] = 0U;
  }

  // Gain: '<S44>/Gain'
  DiscreteTransferFcn3_tmp = Emulated_P.Gain_Gain * Emulated_B.Fin_1_Cmd_rad;

  // Saturate: '<S8>/Saturation'
  if (DiscreteTransferFcn3_tmp > Emulated_P.Saturation_UpperSat) {
    DiscreteTransferFcn3_tmp = Emulated_P.Saturation_UpperSat;
  } else if (DiscreteTransferFcn3_tmp < Emulated_P.Saturation_LowerSat) {
    DiscreteTransferFcn3_tmp = Emulated_P.Saturation_LowerSat;
  }

  // End of Saturate: '<S8>/Saturation'

  // DataTypeConversion: '<S8>/Cast To Double' incorporates:
  //   Constant: '<S8>/One'
  //   Gain: '<S8>/Gain'
  //   Sum: '<S8>/Add'

  DiscreteTransferFcn3_tmp = static_cast<real32_T>(floor(static_cast<real_T>
    (Emulated_P.Gain_Gain_h * DiscreteTransferFcn3_tmp + Emulated_P.One_Value_a)));
  if (rtIsNaNF(DiscreteTransferFcn3_tmp) || rtIsInfF(DiscreteTransferFcn3_tmp))
  {
    DiscreteTransferFcn3_tmp = 0.0F;
  } else {
    DiscreteTransferFcn3_tmp = static_cast<real32_T>(fmod(static_cast<real_T>
      (DiscreteTransferFcn3_tmp), 65536.0));
  }

  // MATLABSystem: '<S8>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S8>/Cast To Double'

  Emulated_B.pwmValue[0] = static_cast<uint16_T>(DiscreteTransferFcn3_tmp < 0.0F
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-DiscreteTransferFcn3_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(DiscreteTransferFcn3_tmp)));

  // Gain: '<S45>/Gain'
  DiscreteTransferFcn3_tmp = Emulated_P.Gain_Gain_m * Emulated_B.Fin_2_Cmd_rad;

  // Saturate: '<S8>/Saturation1'
  if (DiscreteTransferFcn3_tmp > Emulated_P.Saturation1_UpperSat) {
    DiscreteTransferFcn3_tmp = Emulated_P.Saturation1_UpperSat;
  } else if (DiscreteTransferFcn3_tmp < Emulated_P.Saturation1_LowerSat) {
    DiscreteTransferFcn3_tmp = Emulated_P.Saturation1_LowerSat;
  }

  // End of Saturate: '<S8>/Saturation1'

  // DataTypeConversion: '<S8>/Cast To Double1' incorporates:
  //   Constant: '<S8>/One1'
  //   Gain: '<S8>/Gain1'
  //   Sum: '<S8>/Add1'

  DiscreteTransferFcn3_tmp = static_cast<real32_T>(floor(static_cast<real_T>
    (Emulated_P.Gain1_Gain_l * DiscreteTransferFcn3_tmp +
     Emulated_P.One1_Value_b)));
  if (rtIsNaNF(DiscreteTransferFcn3_tmp) || rtIsInfF(DiscreteTransferFcn3_tmp))
  {
    DiscreteTransferFcn3_tmp = 0.0F;
  } else {
    DiscreteTransferFcn3_tmp = static_cast<real32_T>(fmod(static_cast<real_T>
      (DiscreteTransferFcn3_tmp), 65536.0));
  }

  // MATLABSystem: '<S8>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S8>/Cast To Double1'

  Emulated_B.pwmValue[1] = static_cast<uint16_T>(DiscreteTransferFcn3_tmp < 0.0F
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-DiscreteTransferFcn3_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(DiscreteTransferFcn3_tmp)));

  // Gain: '<S46>/Gain'
  DiscreteTransferFcn3_tmp = Emulated_P.Gain_Gain_l * Emulated_B.Fin_3_Cmd_rad;

  // Saturate: '<S8>/Saturation2'
  if (DiscreteTransferFcn3_tmp > Emulated_P.Saturation2_UpperSat) {
    DiscreteTransferFcn3_tmp = Emulated_P.Saturation2_UpperSat;
  } else if (DiscreteTransferFcn3_tmp < Emulated_P.Saturation2_LowerSat) {
    DiscreteTransferFcn3_tmp = Emulated_P.Saturation2_LowerSat;
  }

  // End of Saturate: '<S8>/Saturation2'

  // DataTypeConversion: '<S8>/Cast To Double2' incorporates:
  //   Constant: '<S8>/One2'
  //   Gain: '<S8>/Gain2'
  //   Sum: '<S8>/Add2'

  DiscreteTransferFcn3_tmp = static_cast<real32_T>(floor(static_cast<real_T>
    (Emulated_P.Gain2_Gain * DiscreteTransferFcn3_tmp + Emulated_P.One2_Value_o)));
  if (rtIsNaNF(DiscreteTransferFcn3_tmp) || rtIsInfF(DiscreteTransferFcn3_tmp))
  {
    DiscreteTransferFcn3_tmp = 0.0F;
  } else {
    DiscreteTransferFcn3_tmp = static_cast<real32_T>(fmod(static_cast<real_T>
      (DiscreteTransferFcn3_tmp), 65536.0));
  }

  // MATLABSystem: '<S8>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S8>/Cast To Double2'

  Emulated_B.pwmValue[2] = static_cast<uint16_T>(DiscreteTransferFcn3_tmp < 0.0F
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-DiscreteTransferFcn3_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(DiscreteTransferFcn3_tmp)));

  // Gain: '<S47>/Gain'
  DiscreteTransferFcn3_tmp = Emulated_P.Gain_Gain_p * Emulated_B.Fin_4_Cmd_rad;

  // Saturate: '<S8>/Saturation3'
  if (DiscreteTransferFcn3_tmp > Emulated_P.Saturation3_UpperSat) {
    DiscreteTransferFcn3_tmp = Emulated_P.Saturation3_UpperSat;
  } else if (DiscreteTransferFcn3_tmp < Emulated_P.Saturation3_LowerSat) {
    DiscreteTransferFcn3_tmp = Emulated_P.Saturation3_LowerSat;
  }

  // End of Saturate: '<S8>/Saturation3'

  // DataTypeConversion: '<S8>/Cast To Double3' incorporates:
  //   Constant: '<S8>/One3'
  //   Gain: '<S8>/Gain3'
  //   Sum: '<S8>/Add3'

  DiscreteTransferFcn3_tmp = static_cast<real32_T>(floor(static_cast<real_T>
    (Emulated_P.Gain3_Gain * DiscreteTransferFcn3_tmp + Emulated_P.One3_Value_p)));
  if (rtIsNaNF(DiscreteTransferFcn3_tmp) || rtIsInfF(DiscreteTransferFcn3_tmp))
  {
    DiscreteTransferFcn3_tmp = 0.0F;
  } else {
    DiscreteTransferFcn3_tmp = static_cast<real32_T>(fmod(static_cast<real_T>
      (DiscreteTransferFcn3_tmp), 65536.0));
  }

  // MATLABSystem: '<S8>/PX4 PWM Output1' incorporates:
  //   DataTypeConversion: '<S8>/Cast To Double3'

  Emulated_B.pwmValue[3] = static_cast<uint16_T>(DiscreteTransferFcn3_tmp < 0.0F
    ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-DiscreteTransferFcn3_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(DiscreteTransferFcn3_tmp)));

  // Switch: '<S8>/Switch'
  if (Emulated_B.recovery_log) {
    // DataTypeConversion: '<S8>/Cast To Double4' incorporates:
    //   Constant: '<S8>/One5'

    Emulated_B.u00Hz = floor(Emulated_P.One5_Value);
    if (rtIsNaN(Emulated_B.u00Hz) || rtIsInf(Emulated_B.u00Hz)) {
      Emulated_B.u00Hz = 0.0;
    } else {
      Emulated_B.u00Hz = fmod(Emulated_B.u00Hz, 65536.0);
    }

    // MATLABSystem: '<S8>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S8>/Cast To Double4'

    Emulated_B.pwmValue[4] = static_cast<uint16_T>(Emulated_B.u00Hz < 0.0 ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-Emulated_B.u00Hz)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Emulated_B.u00Hz)));
  } else {
    // DataTypeConversion: '<S8>/Cast To Double4' incorporates:
    //   Constant: '<S8>/One6'

    Emulated_B.u00Hz = floor(Emulated_P.One6_Value);
    if (rtIsNaN(Emulated_B.u00Hz) || rtIsInf(Emulated_B.u00Hz)) {
      Emulated_B.u00Hz = 0.0;
    } else {
      Emulated_B.u00Hz = fmod(Emulated_B.u00Hz, 65536.0);
    }

    // MATLABSystem: '<S8>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S8>/Cast To Double4'

    Emulated_B.pwmValue[4] = static_cast<uint16_T>(Emulated_B.u00Hz < 0.0 ?
      static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
      static_cast<uint16_T>(-Emulated_B.u00Hz)))) : static_cast<int32_T>(
      static_cast<uint16_T>(Emulated_B.u00Hz)));
  }

  // End of Switch: '<S8>/Switch'

  // MATLABSystem: '<S8>/PX4 PWM Output1' incorporates:
  //   Constant: '<S8>/One4'
  //   Constant: '<S8>/One7'

  if (Emulated_P.One7_Value_m) {
    if (!Emulated_DW.obj_m.isArmed) {
      Emulated_DW.obj_m.isArmed = true;
      status = pwm_arm(&Emulated_DW.obj_m.pwmDevHandler,
                       &Emulated_DW.obj_m.armAdvertiseObj);
      Emulated_DW.obj_m.errorStatus = static_cast<uint16_T>
        (Emulated_DW.obj_m.errorStatus | status);
    }

    status = pwm_setServo(&Emulated_DW.obj_m.pwmDevHandler,
                          Emulated_DW.obj_m.servoCount,
                          Emulated_DW.obj_m.channelMask, &Emulated_B.pwmValue[0],
                          Emulated_DW.obj_m.isMain,
                          &Emulated_DW.obj_m.actuatorAdvertiseObj);
    Emulated_DW.obj_m.errorStatus = static_cast<uint16_T>
      (Emulated_DW.obj_m.errorStatus | status);
  } else {
    status = pwm_disarm(&Emulated_DW.obj_m.pwmDevHandler,
                        &Emulated_DW.obj_m.armAdvertiseObj);
    Emulated_DW.obj_m.errorStatus = static_cast<uint16_T>
      (Emulated_DW.obj_m.errorStatus | status);
    Emulated_DW.obj_m.isArmed = false;
    status = pwm_resetServo(&Emulated_DW.obj_m.pwmDevHandler,
      Emulated_DW.obj_m.servoCount, Emulated_DW.obj_m.channelMask,
      Emulated_DW.obj_m.isMain, &Emulated_DW.obj_m.actuatorAdvertiseObj);
    Emulated_DW.obj_m.errorStatus = static_cast<uint16_T>
      (Emulated_DW.obj_m.errorStatus | status);
  }

  if (Emulated_DW.obj_m.isMain) {
    status = pwm_forceFailsafe(&Emulated_DW.obj_m.pwmDevHandler,
      static_cast<int32_T>(Emulated_P.One4_Value_n));
    Emulated_DW.obj_m.errorStatus = static_cast<uint16_T>
      (Emulated_DW.obj_m.errorStatus | status);
  }

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_9_Threshold) {
    // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
    //   Constant: '<S42>/One8'
    //   Outport: '<Root>/Serial Out'

    Emulated_Y.SerialOut[16] = Emulated_P.One8_Value;
  } else {
    // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Emulated_Y.SerialOut[16] = Emulated_U.SerialIn[12];
  }

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_8_Threshold) {
    // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
    //   Constant: '<S42>/One7'
    //   Outport: '<Root>/Serial Out'

    Emulated_Y.SerialOut[15] = Emulated_P.One7_Value;
  } else {
    // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Emulated_Y.SerialOut[15] = Emulated_U.SerialIn[11];
  }

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[14] = rtb_p;

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[13] = rtb_z;

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_5_Threshold) {
    // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
    //   Constant: '<S42>/One4'
    //   Outport: '<Root>/Serial Out'

    Emulated_Y.SerialOut[12] = Emulated_P.One4_Value;
  } else {
    // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Emulated_Y.SerialOut[12] = Emulated_U.SerialIn[8];
  }

  // Switch generated from: '<S6>/Switch' incorporates:
  //   Inport: '<Root>/Serial In'

  if (Emulated_U.SerialIn[2] > Emulated_P.Switch_4_Threshold) {
    // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
    //   Constant: '<S42>/One3'
    //   Outport: '<Root>/Serial Out'

    Emulated_Y.SerialOut[11] = Emulated_P.One3_Value;
  } else {
    // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    Emulated_Y.SerialOut[11] = Emulated_U.SerialIn[7];
  }

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[10] = rtb_w;

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[9] = rtb_v;

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[8] = Emulated_B.u;

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/Serial In'
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[0] = Emulated_U.SerialIn[1];

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/Serial In'
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[5] = Emulated_U.SerialIn[16];

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/Serial In'
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[6] = Emulated_U.SerialIn[17];

  // SignalConversion generated from: '<S4>/Vector Concatenate' incorporates:
  //   Inport: '<Root>/Serial In'
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[7] = Emulated_U.SerialIn[18];

  // Constant: '<S1>/Zero' incorporates:
  //   Outport: '<Root>/Serial Out'

  Emulated_Y.SerialOut[17] = Emulated_P.Zero_Value_a;

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.001, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  Emulated_M->Timing.clockTick0++;
}

// Model initialize function
void Emulated_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    c_dsp_private_SlidingWindowAverageCG_Emulated_T *obj;
    int32_T i;
    Emulated_PrevZCX.Autopilot_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // SystemInitialize for Triggered SubSystem: '<S1>/Autopilot'
    // InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S14>/Constant'

    Emulated_DW.DiscreteTimeIntegrator_DSTATE_no = Emulated_P.Constant_Value_o;

    // InitializeConditions for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn3' 
    Emulated_DW.DiscreteTransferFcn3_states =
      Emulated_P.DiscreteTransferFcn3_InitialStates;

    // InitializeConditions for UnitDelay: '<S24>/Delay Input1'
    //
    //  Block description for '<S24>/Delay Input1':
    //
    //   Store in Global RAM

    Emulated_DW.DelayInput1_DSTATE = Emulated_P.DetectDecrease_vinit;

    // InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S25>/Constant1'

    Emulated_DW.DiscreteTimeIntegrator_DSTATE = Emulated_P.Constant1_Value_g;

    // InitializeConditions for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' 
    Emulated_DW.DiscreteTransferFcn_states =
      Emulated_P.DiscreteTransferFcn_InitialStates;

    // InitializeConditions for Switch: '<S30>/Switch1' incorporates:
    //   Memory: '<S18>/Memory'

    Emulated_DW.Memory_PreviousInput = Emulated_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S29>/Constant1'

    Emulated_DW.DiscreteTimeIntegrator_DSTATE_n = Emulated_P.Constant1_Value_m;

    // InitializeConditions for Memory: '<S30>/Memory'
    Emulated_DW.Memory_PreviousInput_f = Emulated_P.Memory_InitialCondition_f;

    // InitializeConditions for DiscreteIntegrator: '<S34>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S34>/Constant1'

    Emulated_DW.DiscreteTimeIntegrator_DSTATE_p = Emulated_P.Constant1_Value_f;

    // InitializeConditions for Switch: '<S35>/Switch1' incorporates:
    //   Memory: '<S35>/Memory'

    Emulated_DW.Memory_PreviousInput_l = Emulated_P.Memory_InitialCondition_p;

    // InitializeConditions for Switch: '<S26>/Switch1' incorporates:
    //   Memory: '<S26>/Memory'

    Emulated_DW.Memory_PreviousInput_e = Emulated_P.Memory_InitialCondition_n;

    // InitializeConditions for DiscreteIntegrator: '<S38>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S38>/Constant1'

    Emulated_DW.DiscreteTimeIntegrator_DSTATE_o = Emulated_P.Constant1_Value_e;

    // InitializeConditions for Switch: '<S39>/Switch1' incorporates:
    //   Memory: '<S39>/Memory'

    Emulated_DW.Memory_PreviousInput_p = Emulated_P.Memory_InitialCondition_m;

    // Start for MATLABSystem: '<S16>/Moving Average1'
    Emulated_DW.obj.matlabCodegenIsDeleted = true;
    Emulated_DW.obj.isInitialized = 0;
    Emulated_DW.obj.NumChannels = -1;
    Emulated_DW.obj.matlabCodegenIsDeleted = false;
    Emulated_DW.obj.isSetupComplete = false;
    Emulated_DW.obj.isInitialized = 1;
    Emulated_DW.obj.NumChannels = 1;
    Emulated_DW.obj._pobj0.isInitialized = 0;
    Emulated_DW.obj.pStatistic = &Emulated_DW.obj._pobj0;
    Emulated_DW.obj.isSetupComplete = true;
    Emulated_DW.obj.TunablePropsChanged = false;

    // InitializeConditions for MATLABSystem: '<S16>/Moving Average1'
    obj = Emulated_DW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0F;
      for (i = 0; i < 9; i++) {
        obj->pCumSumRev[i] = 0.0F;
      }

      obj->pCumRevIndex = 1.0F;
    }

    // End of InitializeConditions for MATLABSystem: '<S16>/Moving Average1'

    // SystemInitialize for Outport: '<S2>/Fin Deflections'
    Emulated_B.siB_cmd[0] = Emulated_P.FinDeflections_Y0.Fin_1_Cmd_rad;
    Emulated_B.siB_cmd[1] = Emulated_P.FinDeflections_Y0.Fin_2_Cmd_rad;
    Emulated_B.siB_cmd[2] = Emulated_P.FinDeflections_Y0.Fin_3_Cmd_rad;
    Emulated_B.siB_cmd[3] = Emulated_P.FinDeflections_Y0.Fin_4_Cmd_rad;

    // SystemInitialize for Outport: '<Root>/flight_mode_enum' incorporates:
    //   Outport: '<S2>/flight_mode_enum'

    Emulated_Y.flight_mode_enum = Emulated_P.flight_mode_enum_Y0;

    // SystemInitialize for SignalConversion generated from: '<S2>/Fin Cmd' incorporates:
    //   Outport: '<S2>/Fin Cmd'

    Emulated_B.Fin_1_Cmd_rad = Emulated_P.FinCmd_Y0.Fin_1_Cmd_rad;

    // SystemInitialize for SignalConversion generated from: '<S2>/Fin Cmd' incorporates:
    //   Outport: '<S2>/Fin Cmd'

    Emulated_B.Fin_2_Cmd_rad = Emulated_P.FinCmd_Y0.Fin_2_Cmd_rad;

    // SystemInitialize for SignalConversion generated from: '<S2>/Fin Cmd' incorporates:
    //   Outport: '<S2>/Fin Cmd'

    Emulated_B.Fin_3_Cmd_rad = Emulated_P.FinCmd_Y0.Fin_3_Cmd_rad;

    // SystemInitialize for SignalConversion generated from: '<S2>/Fin Cmd' incorporates:
    //   Outport: '<S2>/Fin Cmd'

    Emulated_B.Fin_4_Cmd_rad = Emulated_P.FinCmd_Y0.Fin_4_Cmd_rad;

    // SystemInitialize for Logic: '<S20>/AND2' incorporates:
    //   Outport: '<S2>/Recovery'

    Emulated_B.recovery_log = Emulated_P.Recovery_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Autopilot'

    // Start for MATLABSystem: '<S8>/PX4 PWM Output1' incorporates:
    //   Constant: '<S8>/One4'
    //   Constant: '<S8>/One7'

    Emulated_DW.obj_m.errorStatus = 0U;
    Emulated_DW.obj_m.isInitialized = 0;
    Emulated_DW.obj_m.matlabCodegenIsDeleted = false;
    Emulated_SystemCore_setup(&Emulated_DW.obj_m, Emulated_P.One7_Value_m,
      Emulated_P.One4_Value_n);

    // Enable for Triggered SubSystem: '<S1>/Autopilot'
    Emulated_DW.Autopilot_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S14>/Discrete-Time Integrator'
    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;

    // Enable for DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_h = 1U;

    // Enable for DiscreteIntegrator: '<S29>/Discrete-Time Integrator'
    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_e = 1U;

    // Enable for DiscreteIntegrator: '<S34>/Discrete-Time Integrator'
    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_d = 1U;

    // Enable for DiscreteIntegrator: '<S38>/Discrete-Time Integrator'
    Emulated_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE_ec = 1U;

    // End of Enable for SubSystem: '<S1>/Autopilot'
  }
}

// Model terminate function
void Emulated_terminate(void)
{
  c_dsp_private_SlidingWindowAverageCG_Emulated_T *obj;
  uint16_T status;

  // Terminate for Triggered SubSystem: '<S1>/Autopilot'
  // Terminate for MATLABSystem: '<S16>/Moving Average1'
  if (!Emulated_DW.obj.matlabCodegenIsDeleted) {
    Emulated_DW.obj.matlabCodegenIsDeleted = true;
    if ((Emulated_DW.obj.isInitialized == 1) && Emulated_DW.obj.isSetupComplete)
    {
      obj = Emulated_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      Emulated_DW.obj.NumChannels = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S16>/Moving Average1'
  // End of Terminate for SubSystem: '<S1>/Autopilot'

  // Terminate for MATLABSystem: '<S8>/PX4 PWM Output1'
  if (!Emulated_DW.obj_m.matlabCodegenIsDeleted) {
    Emulated_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Emulated_DW.obj_m.isInitialized == 1) &&
        Emulated_DW.obj_m.isSetupComplete) {
      status = pwm_disarm(&Emulated_DW.obj_m.pwmDevHandler,
                          &Emulated_DW.obj_m.armAdvertiseObj);
      Emulated_DW.obj_m.errorStatus = static_cast<uint16_T>
        (Emulated_DW.obj_m.errorStatus | status);
      status = pwm_resetServo(&Emulated_DW.obj_m.pwmDevHandler,
        Emulated_DW.obj_m.servoCount, Emulated_DW.obj_m.channelMask,
        Emulated_DW.obj_m.isMain, &Emulated_DW.obj_m.actuatorAdvertiseObj);
      Emulated_DW.obj_m.errorStatus = static_cast<uint16_T>
        (Emulated_DW.obj_m.errorStatus | status);
      status = pwm_close(&Emulated_DW.obj_m.pwmDevHandler,
                         &Emulated_DW.obj_m.actuatorAdvertiseObj,
                         &Emulated_DW.obj_m.armAdvertiseObj);
      Emulated_DW.obj_m.errorStatus = static_cast<uint16_T>
        (Emulated_DW.obj_m.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S8>/PX4 PWM Output1'
}

//
// File trailer for generated code.
//
// [EOF]
//
