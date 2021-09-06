//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PixBlock2.cpp
//
// Code generated for Simulink model 'PixBlock2'.
//
// Model version                  : 4.22
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Apr 13 10:08:45 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PixBlock2.h"
#include "PixBlock2_private.h"

// Block signals (default storage)
B_PixBlock2_T PixBlock2_B;

// Block states (default storage)
DW_PixBlock2_T PixBlock2_DW;

// Previous zero-crossings (trigger) states
PrevZCX_PixBlock2_T PixBlock2_PrevZCX;

// External inputs (root inport signals with default storage)
ExtU_PixBlock2_T PixBlock2_U;

// External outputs (root outports fed by signals with default storage)
ExtY_PixBlock2_T PixBlock2_Y;

// Real-time model
RT_MODEL_PixBlock2_T PixBlock2_M_ = RT_MODEL_PixBlock2_T();
RT_MODEL_PixBlock2_T *const PixBlock2_M = &PixBlock2_M_;
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

// Model step function
void PixBlock2_step(void)
{
  real_T rtb_u00Hz;
  int32_T i;
  real32_T DiscreteTransferFcn_tmp;
  real32_T rtb_Ki_phi;
  real32_T rtb_ManualSwitch;
  real32_T rtb_SquareRoot;
  real32_T rtb_Sum3;
  real32_T rtb_p;
  real32_T rtb_u;
  real32_T rtb_v;
  real32_T rtb_w;
  real32_T rtb_z;
  uint32_T EmulatedPixhawk_ELAPS_T;
  boolean_T rtb_GreaterThan;
  ZCEventType zcEvent;

  // DiscretePulseGenerator: '<S1>/100 Hz'
  rtb_u00Hz = (PixBlock2_DW.clockTickCounter < PixBlock2_P.u00Hz_Duty) &&
    (PixBlock2_DW.clockTickCounter >= 0) ? PixBlock2_P.u00Hz_Amp : 0.0;
  if (PixBlock2_DW.clockTickCounter >= PixBlock2_P.u00Hz_Period - 1.0) {
    PixBlock2_DW.clockTickCounter = 0;
  } else {
    PixBlock2_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S1>/100 Hz'

  // Outputs for Triggered SubSystem: '<S1>/Emulated Pixhawk' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &PixBlock2_PrevZCX.EmulatedPixhawk_Trig_ZCE,
                     (rtb_u00Hz));
  if (zcEvent != NO_ZCEVENT) {
    if (PixBlock2_DW.EmulatedPixhawk_RESET_ELAPS_T) {
      EmulatedPixhawk_ELAPS_T = 0U;
    } else {
      EmulatedPixhawk_ELAPS_T = PixBlock2_M->Timing.clockTick0 -
        PixBlock2_DW.EmulatedPixhawk_PREV_T;
    }

    PixBlock2_DW.EmulatedPixhawk_PREV_T = PixBlock2_M->Timing.clockTick0;
    PixBlock2_DW.EmulatedPixhawk_RESET_ELAPS_T = false;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[0] = PixBlock2_U.send[1];

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One'
    //   Inport: '<Root>/Serial In'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_1_Threshold) {
      rtb_u = PixBlock2_P.One_Value;
    } else {
      rtb_u = PixBlock2_U.send[4];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One1'
    //   Inport: '<Root>/Serial In'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_2_Threshold) {
      rtb_v = PixBlock2_P.One1_Value;
    } else {
      rtb_v = PixBlock2_U.send[5];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One2'
    //   Inport: '<Root>/Serial In'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_3_Threshold) {
      rtb_w = PixBlock2_P.One2_Value;
    } else {
      rtb_w = PixBlock2_U.send[6];
    }

    // Sqrt: '<S10>/Square Root' incorporates:
    //   Math: '<S10>/Square'
    //   Math: '<S10>/Square1'
    //   Math: '<S10>/Square2'
    //   Sum: '<S10>/Add'

    rtb_SquareRoot = static_cast<real32_T>(sqrt(static_cast<real_T>((rtb_u *
      rtb_u + rtb_v * rtb_v) + rtb_w * rtb_w)));

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One5'
    //   Inport: '<Root>/Serial In'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_6_Threshold) {
      rtb_z = PixBlock2_P.One5_Value;
    } else {
      rtb_z = PixBlock2_U.send[9];
    }

    // Gain: '<S3>/Gain'
    rtb_Ki_phi = PixBlock2_P.Gain_Gain * rtb_z;

    // DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' incorporates:
    //   Inport: '<Root>/Serial In'

    DiscreteTransferFcn_tmp = (PixBlock2_U.send[16] -
      PixBlock2_P.DiscreteTransferFcn_DenCoef[1] *
      PixBlock2_DW.DiscreteTransferFcn_states) /
      PixBlock2_P.DiscreteTransferFcn_DenCoef[0];
    rtb_ManualSwitch = PixBlock2_P.DiscreteTransferFcn_NumCoef[0] *
      DiscreteTransferFcn_tmp + PixBlock2_P.DiscreteTransferFcn_NumCoef[1] *
      PixBlock2_DW.DiscreteTransferFcn_states;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One6'
    //   Inport: '<Root>/Serial In'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_7_Threshold) {
      rtb_p = PixBlock2_P.One6_Value;
    } else {
      rtb_p = PixBlock2_U.send[10];
    }

    // ManualSwitch: '<S3>/Manual Switch'
    if (PixBlock2_P.ManualSwitch_CurrentSetting != 1) {
      rtb_ManualSwitch = rtb_p;
    }

    // End of ManualSwitch: '<S3>/Manual Switch'

    // RelationalOperator: '<S13>/GreaterThan' incorporates:
    //   Delay: '<S13>/Delay'
    //   Inport: '<Root>/Serial In'

    rtb_GreaterThan = (PixBlock2_U.send[1] < PixBlock2_DW.Delay_DSTATE);

    // DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S11>/Constant'

    if (PixBlock2_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE == 0) {
      if (rtb_GreaterThan || (PixBlock2_DW.DiscreteTimeIntegrator_PrevResetState
           != 0)) {
        PixBlock2_DW.DiscreteTimeIntegrator_DSTATE = PixBlock2_P.Constant_Value;
      } else {
        // DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
        PixBlock2_DW.DiscreteTimeIntegrator_DSTATE +=
          PixBlock2_P.DiscreteTimeIntegrator_gainval * static_cast<real32_T>
          (EmulatedPixhawk_ELAPS_T) * PixBlock2_DW.DiscreteTimeIntegrator_PREV_U;
      }
    }

    // End of DiscreteIntegrator: '<S11>/Discrete-Time Integrator'

    // Lookup_n-D: '<S12>/1-D Lookup Table5' incorporates:
    //   Delay: '<S13>/Delay'
    //   Lookup_n-D: '<S12>/1-D Lookup Table4'
    //   Sqrt: '<S10>/Square Root'

    PixBlock2_DW.Delay_DSTATE = look2_iflf_binlcapw(rtb_Ki_phi, rtb_SquareRoot,
      PixBlock2_P.uDLookupTable5_bp01Data, PixBlock2_P.uDLookupTable5_bp02Data,
      PixBlock2_P.uDLookupTable5_tableData, PixBlock2_P.uDLookupTable5_maxIndex,
      3U);

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One9'
    //   Inport: '<Root>/Serial In'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_10_Threshold) {
      rtb_Sum3 = PixBlock2_P.One9_Value;
    } else {
      rtb_Sum3 = PixBlock2_U.send[19];
    }

    // Sum: '<S11>/Sum3' incorporates:
    //   Inport: '<Root>/Serial In'

    rtb_Sum3 = PixBlock2_U.send[22] - rtb_Sum3;

    // Product: '<S11>/Product1' incorporates:
    //   Delay: '<S13>/Delay'
    //   Lookup_n-D: '<S12>/1-D Lookup Table3'
    //   Lookup_n-D: '<S12>/1-D Lookup Table4'
    //   Product: '<S11>/Product2'
    //   Sqrt: '<S10>/Square Root'
    //   Sum: '<S11>/Sum4'
    //   Sum: '<S11>/Sum5'

    rtb_ManualSwitch = ((PixBlock2_DW.Delay_DSTATE * rtb_Sum3 +
                         PixBlock2_DW.DiscreteTimeIntegrator_DSTATE) -
                        rtb_ManualSwitch) * look2_iflf_binlcapw(rtb_Ki_phi,
      rtb_SquareRoot, PixBlock2_P.uDLookupTable3_bp01Data,
      PixBlock2_P.uDLookupTable3_bp02Data, PixBlock2_P.uDLookupTable3_tableData,
      PixBlock2_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S14>/Product' incorporates:
    //   Constant: '<S14>/Constant7'
    //   Constant: '<S3>/Zero'

    for (i = 0; i < 4; i++) {
      PixBlock2_B.siB_cmd[i] = PixBlock2_P.Constant7_Value[i + 8] *
        PixBlock2_P.Zero_Value + (PixBlock2_P.Constant7_Value[i + 4] *
        PixBlock2_P.Zero_Value + PixBlock2_P.Constant7_Value[i] *
        rtb_ManualSwitch);
    }

    // End of Product: '<S14>/Product'

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[1] = PixBlock2_B.siB_cmd[0];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[2] = PixBlock2_B.siB_cmd[1];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[3] = PixBlock2_B.siB_cmd[2];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[4] = PixBlock2_B.siB_cmd[3];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[5] = PixBlock2_U.send[16];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[6] = PixBlock2_U.send[17];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[7] = PixBlock2_U.send[18];

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[8] = rtb_u;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[9] = rtb_v;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[10] = rtb_w;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One3'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_4_Threshold) {
      PixBlock2_Y.SerialOut[11] = PixBlock2_P.One3_Value;
    } else {
      PixBlock2_Y.SerialOut[11] = PixBlock2_U.send[7];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One4'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_5_Threshold) {
      PixBlock2_Y.SerialOut[12] = PixBlock2_P.One4_Value;
    } else {
      PixBlock2_Y.SerialOut[12] = PixBlock2_U.send[8];
    }

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[13] = rtb_z;

    // SignalConversion generated from: '<S5>/Vector Concatenate' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[14] = rtb_p;

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One7'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_8_Threshold) {
      PixBlock2_Y.SerialOut[15] = PixBlock2_P.One7_Value;
    } else {
      PixBlock2_Y.SerialOut[15] = PixBlock2_U.send[11];
    }

    // Switch generated from: '<S8>/Switch' incorporates:
    //   Constant: '<S15>/One8'
    //   Inport: '<Root>/Serial In'
    //   Outport: '<Root>/Serial Out'

    if (PixBlock2_U.send[2] > PixBlock2_P.Switch_9_Threshold) {
      PixBlock2_Y.SerialOut[16] = PixBlock2_P.One8_Value;
    } else {
      PixBlock2_Y.SerialOut[16] = PixBlock2_U.send[12];
    }

    // Constant: '<S2>/Zero' incorporates:
    //   Outport: '<Root>/Serial Out'

    PixBlock2_Y.SerialOut[17] = PixBlock2_P.Zero_Value_e;

    // Update for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn'
    PixBlock2_DW.DiscreteTransferFcn_states = DiscreteTransferFcn_tmp;

    // Update for Delay: '<S13>/Delay' incorporates:
    //   Inport: '<Root>/Serial In'

    PixBlock2_DW.Delay_DSTATE = PixBlock2_U.send[1];

    // Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
    //   Lookup_n-D: '<S12>/1-D Lookup Table4'
    //   Product: '<S11>/Product3'
    //   Sqrt: '<S10>/Square Root'

    PixBlock2_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 0U;
    PixBlock2_DW.DiscreteTimeIntegrator_PrevResetState = static_cast<int8_T>
      (rtb_GreaterThan);
    PixBlock2_DW.DiscreteTimeIntegrator_PREV_U = look2_iflf_binlcapw(rtb_Ki_phi,
      rtb_SquareRoot, PixBlock2_P.uDLookupTable4_bp01Data,
      PixBlock2_P.uDLookupTable4_bp02Data, PixBlock2_P.uDLookupTable4_tableData,
      PixBlock2_P.uDLookupTable4_maxIndex, 3U) * rtb_Sum3;
  }

  // End of Outputs for SubSystem: '<S1>/Emulated Pixhawk'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.001, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  PixBlock2_M->Timing.clockTick0++;
}

// Model initialize function
void PixBlock2_initialize(void)
{
  {
    int32_T i;
    PixBlock2_PrevZCX.EmulatedPixhawk_Trig_ZCE = UNINITIALIZED_ZCSIG;

    // SystemInitialize for Triggered SubSystem: '<S1>/Emulated Pixhawk'
    // InitializeConditions for DiscreteTransferFcn: '<S3>/Discrete Transfer Fcn' 
    PixBlock2_DW.DiscreteTransferFcn_states =
      PixBlock2_P.DiscreteTransferFcn_InitialStates;

    // InitializeConditions for Delay: '<S13>/Delay'
    PixBlock2_DW.Delay_DSTATE = PixBlock2_P.Delay_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S11>/Constant'

    PixBlock2_DW.DiscreteTimeIntegrator_DSTATE = PixBlock2_P.Constant_Value;
    for (i = 0; i < 18; i++) {
      // SystemInitialize for Outport: '<Root>/Serial Out' incorporates:
      //   Outport: '<S2>/Serial Out'

      PixBlock2_Y.SerialOut[i] = PixBlock2_P.SerialOut_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S1>/Emulated Pixhawk'

    // Enable for Triggered SubSystem: '<S1>/Emulated Pixhawk'
    PixBlock2_DW.EmulatedPixhawk_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
    PixBlock2_DW.DiscreteTimeIntegrator_SYSTEM_ENABLE = 1U;

    // End of Enable for SubSystem: '<S1>/Emulated Pixhawk'
  }
}

// Model terminate function
void PixBlock2_terminate(void)
{
  // (no terminate code required)
}

//
// File trailer for generated code.
//
// [EOF]
//
