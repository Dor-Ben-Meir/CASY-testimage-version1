//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Corneto_flight_program_control.cpp
//
// Code generated for Simulink model 'Corneto_flight_program_control'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue Jun 29 11:53:12 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Corneto_flight_program_control.h"
#include "Corneto_flight_program_control_private.h"

// Block signals (default storage)
B_Corneto_flight_program_cont_T Corneto_flight_program_contro_B;

// Block states (default storage)
DW_Corneto_flight_program_con_T Corneto_flight_program_contr_DW;

// Previous zero-crossings (trigger) states
PrevZCX_Corneto_flight_progra_T Corneto_flight_program__PrevZCX;

// Real-time model
RT_MODEL_Corneto_flight_progr_T Corneto_flight_program_contr_M_ =
  RT_MODEL_Corneto_flight_progr_T();
RT_MODEL_Corneto_flight_progr_T *const Corneto_flight_program_contr_M =
  &Corneto_flight_program_contr_M_;

// Forward declaration for local functions
static void Corneto_flight_SystemCore_setup(px4_internal_block_PWM_Cornet_T *obj,
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

  (Corneto_flight_program_contr_M->Timing.TaskCounters.TID[1])++;
  if ((Corneto_flight_program_contr_M->Timing.TaskCounters.TID[1]) > 199) {// Sample time: [1.0s, 0.0s] 
    Corneto_flight_program_contr_M->Timing.TaskCounters.TID[1] = 0;
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

static void Corneto_flight_SystemCore_setup(px4_internal_block_PWM_Cornet_T *obj,
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

// Model step function
void Corneto_flight_program_control_step(void)
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
  boolean_T rtb_recovery_log;
  ZCEventType zcEvent;
  static const char_T g[24] = "/fs/microsd/log/pwm.bin";
  static const char_T f[28] = "CLOSING file. count = %d %c";
  static const char_T i_0[56] =
    "OPENING file %s vect_size %d elem_size %d numRecs %d %c";

  // StringToASCII: '<S11>/String to ASCII' incorporates:
  //   StringConstant: '<S11>/String Constant'

  strncpy(&Corneto_flight_program_contro_B.cv[0],
          &Corneto_flight_program_contro_P.StringConstant_String[0], 50U);

  // BusAssignment: '<S11>/Bus Assignment' incorporates:
  //   Constant: '<S11>/Constant'
  //   Constant: '<S70>/Constant'
  //   StringToASCII: '<S11>/String to ASCII'

  Corneto_flight_program_contro_B.BusAssignment =
    Corneto_flight_program_contro_P.Constant_Value_c;
  Corneto_flight_program_contro_B.BusAssignment.severity =
    Corneto_flight_program_contro_P.Constant_Value_kb;
  for (i = 0; i < 50; i++) {
    Corneto_flight_program_contro_B.BusAssignment.text[i] = static_cast<uint8_T>
      (Corneto_flight_program_contro_B.cv[i]);
  }

  // End of BusAssignment: '<S11>/Bus Assignment'

  // MATLABSystem: '<S71>/SinkBlock' incorporates:
  //   BusAssignment: '<S11>/Bus Assignment'

  uORB_write_step(Corneto_flight_program_contr_DW.obj_lw.orbMetadataObj,
                  &Corneto_flight_program_contr_DW.obj_lw.orbAdvertiseObj,
                  &Corneto_flight_program_contro_B.BusAssignment);

  // MATLABSystem: '<S5>/SourceBlock' incorporates:
  //   Inport: '<S17>/In1'

  rtb_NOT = uORB_read_step(Corneto_flight_program_contr_DW.obj_k.orbMetadataObj,
    &Corneto_flight_program_contr_DW.obj_k.eventStructObj,
    &Corneto_flight_program_contro_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S17>/Enable'

  if (rtb_NOT) {
    Corneto_flight_program_contro_B.In1_a =
      Corneto_flight_program_contro_B.b_varargout_2_c;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // MATLABSystem: '<S72>/SourceBlock' incorporates:
  //   Inport: '<S73>/In1'

  rtb_NOT = uORB_read_step(Corneto_flight_program_contr_DW.obj_n.orbMetadataObj,
    &Corneto_flight_program_contr_DW.obj_n.eventStructObj,
    &Corneto_flight_program_contro_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S72>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S73>/Enable'

  if (rtb_NOT) {
    Corneto_flight_program_contro_B.In1 =
      Corneto_flight_program_contro_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S72>/SourceBlock'
  // End of Outputs for SubSystem: '<S72>/Enabled Subsystem'

  // MATLABSystem: '<S13>/SourceBlock' incorporates:
  //   Inport: '<S14>/In1'

  rtb_NOT = uORB_read_step(Corneto_flight_program_contr_DW.obj_j.orbMetadataObj,
    &Corneto_flight_program_contr_DW.obj_j.eventStructObj,
    &Corneto_flight_program_contro_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S13>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  if (rtb_NOT) {
    Corneto_flight_program_contro_B.In1_i =
      Corneto_flight_program_contro_B.b_varargout_2_cx;
  }

  // End of MATLABSystem: '<S13>/SourceBlock'
  // End of Outputs for SubSystem: '<S13>/Enabled Subsystem'

  // MATLABSystem: '<S15>/SourceBlock' incorporates:
  //   Inport: '<S16>/In1'

  rtb_NOT = uORB_read_step(Corneto_flight_program_contr_DW.obj_nc.orbMetadataObj,
    &Corneto_flight_program_contr_DW.obj_nc.eventStructObj,
    &Corneto_flight_program_contro_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S16>/Enable'

  if (rtb_NOT) {
    Corneto_flight_program_contro_B.In1_eg =
      Corneto_flight_program_contro_B.b_varargout_2_b;
  }

  // End of MATLABSystem: '<S15>/SourceBlock'
  // End of Outputs for SubSystem: '<S15>/Enabled Subsystem'

  // MATLABSystem: '<S6>/SourceBlock' incorporates:
  //   Inport: '<S18>/In1'

  rtb_NOT = uORB_read_step(Corneto_flight_program_contr_DW.obj_f.orbMetadataObj,
    &Corneto_flight_program_contr_DW.obj_f.eventStructObj,
    &Corneto_flight_program_contro_B.b_varargout_2_m, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S18>/Enable'

  if (rtb_NOT) {
    Corneto_flight_program_contro_B.In1_e =
      Corneto_flight_program_contro_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // Sqrt: '<S66>/sqrt' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'
  //   Product: '<S67>/Product'
  //   Product: '<S67>/Product1'
  //   Product: '<S67>/Product2'
  //   Product: '<S67>/Product3'
  //   Sum: '<S67>/Sum'

  Corneto_flight_program_contro_B.Product3_n = sqrt(((static_cast<real_T>
    (Corneto_flight_program_contro_B.In1.q[0]) *
    Corneto_flight_program_contro_B.In1.q[0] + static_cast<real_T>
    (Corneto_flight_program_contro_B.In1.q[1]) *
    Corneto_flight_program_contro_B.In1.q[1]) + static_cast<real_T>
    (Corneto_flight_program_contro_B.In1.q[2]) *
    Corneto_flight_program_contro_B.In1.q[2]) + static_cast<real_T>
    (Corneto_flight_program_contro_B.In1.q[3]) *
    Corneto_flight_program_contro_B.In1.q[3]);

  // Product: '<S61>/Product' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  Corneto_flight_program_contro_B.Kp_phi =
    Corneto_flight_program_contro_B.In1.q[0] /
    Corneto_flight_program_contro_B.Product3_n;

  // Product: '<S61>/Product1' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  Corneto_flight_program_contro_B.Sum3 = Corneto_flight_program_contro_B.In1.q[1]
    / Corneto_flight_program_contro_B.Product3_n;

  // Product: '<S61>/Product2' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  Corneto_flight_program_contro_B.Product2_f =
    Corneto_flight_program_contro_B.In1.q[2] /
    Corneto_flight_program_contro_B.Product3_n;

  // Product: '<S61>/Product3' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double2'

  Corneto_flight_program_contro_B.Product3_n =
    Corneto_flight_program_contro_B.In1.q[3] /
    Corneto_flight_program_contro_B.Product3_n;

  // Fcn: '<S9>/fcn2' incorporates:
  //   Fcn: '<S9>/fcn5'

  Corneto_flight_program_contro_B.t = Corneto_flight_program_contro_B.Kp_phi *
    Corneto_flight_program_contro_B.Kp_phi;
  rtb_TmpSignalConversionAtSFun_0 = Corneto_flight_program_contro_B.Sum3 *
    Corneto_flight_program_contro_B.Sum3;
  Corneto_flight_program_contro_B.rtb_Switch_j_idx_1 =
    Corneto_flight_program_contro_B.Product2_f *
    Corneto_flight_program_contro_B.Product2_f;
  Corneto_flight_program_contro_B.rtb_Switch_j_idx_2 =
    Corneto_flight_program_contro_B.Product3_n *
    Corneto_flight_program_contro_B.Product3_n;

  // SignalConversion generated from: '<S69>/ SFunction ' incorporates:
  //   Fcn: '<S9>/fcn1'
  //   Fcn: '<S9>/fcn2'
  //   MATLAB Function: '<S68>/SDCard_logger'
  //   Trigonometry: '<S60>/Trigonometric Function1'

  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[12] =
    rt_atan2d_snf((Corneto_flight_program_contro_B.Sum3 *
                   Corneto_flight_program_contro_B.Product2_f +
                   Corneto_flight_program_contro_B.Kp_phi *
                   Corneto_flight_program_contro_B.Product3_n) * 2.0,
                  ((Corneto_flight_program_contro_B.t +
                    rtb_TmpSignalConversionAtSFun_0) -
                   Corneto_flight_program_contro_B.rtb_Switch_j_idx_1) -
                  Corneto_flight_program_contro_B.rtb_Switch_j_idx_2);

  // Fcn: '<S9>/fcn3'
  Corneto_flight_program_contro_B.fcn3 = (Corneto_flight_program_contro_B.Sum3 *
    Corneto_flight_program_contro_B.Product3_n -
    Corneto_flight_program_contro_B.Kp_phi *
    Corneto_flight_program_contro_B.Product2_f) * -2.0;

  // If: '<S62>/If' incorporates:
  //   Constant: '<S63>/Constant'
  //   Constant: '<S64>/Constant'

  if (Corneto_flight_program_contro_B.fcn3 > 1.0) {
    Corneto_flight_program_contro_B.fcn3 =
      Corneto_flight_program_contro_P.Constant_Value_ki;
  } else if (Corneto_flight_program_contro_B.fcn3 < -1.0) {
    Corneto_flight_program_contro_B.fcn3 =
      Corneto_flight_program_contro_P.Constant_Value_g0;
  }

  // End of If: '<S62>/If'

  // Trigonometry: '<S60>/Trigonometric Function3' incorporates:
  //   Fcn: '<S9>/fcn4'
  //   Fcn: '<S9>/fcn5'

  Corneto_flight_program_contro_B.Product3_n = rt_atan2d_snf
    ((Corneto_flight_program_contro_B.Product2_f *
      Corneto_flight_program_contro_B.Product3_n +
      Corneto_flight_program_contro_B.Kp_phi *
      Corneto_flight_program_contro_B.Sum3) * 2.0,
     ((Corneto_flight_program_contro_B.t - rtb_TmpSignalConversionAtSFun_0) -
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_1) +
     Corneto_flight_program_contro_B.rtb_Switch_j_idx_2);

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<Root>/Cast To Double29'
  //   DataTypeConversion: '<Root>/Cast To Double30'
  //   DataTypeConversion: '<Root>/Cast To Double31'

  Corneto_flight_program_contro_B.Sum3 = 3.3121686421112381E-170;
  Corneto_flight_program_contro_B.Product2_f = fabs(static_cast<real_T>
    (Corneto_flight_program_contro_B.In1_e.vx));
  if (Corneto_flight_program_contro_B.Product2_f > 3.3121686421112381E-170) {
    Corneto_flight_program_contro_B.Kp_phi = 1.0;
    Corneto_flight_program_contro_B.Sum3 =
      Corneto_flight_program_contro_B.Product2_f;
  } else {
    Corneto_flight_program_contro_B.t =
      Corneto_flight_program_contro_B.Product2_f / 3.3121686421112381E-170;
    Corneto_flight_program_contro_B.Kp_phi = Corneto_flight_program_contro_B.t *
      Corneto_flight_program_contro_B.t;
  }

  Corneto_flight_program_contro_B.Product2_f = fabs(static_cast<real_T>
    (Corneto_flight_program_contro_B.In1_e.vy));
  if (Corneto_flight_program_contro_B.Product2_f >
      Corneto_flight_program_contro_B.Sum3) {
    Corneto_flight_program_contro_B.t = Corneto_flight_program_contro_B.Sum3 /
      Corneto_flight_program_contro_B.Product2_f;
    Corneto_flight_program_contro_B.Kp_phi =
      Corneto_flight_program_contro_B.Kp_phi * Corneto_flight_program_contro_B.t
      * Corneto_flight_program_contro_B.t + 1.0;
    Corneto_flight_program_contro_B.Sum3 =
      Corneto_flight_program_contro_B.Product2_f;
  } else {
    Corneto_flight_program_contro_B.t =
      Corneto_flight_program_contro_B.Product2_f /
      Corneto_flight_program_contro_B.Sum3;
    Corneto_flight_program_contro_B.Kp_phi += Corneto_flight_program_contro_B.t *
      Corneto_flight_program_contro_B.t;
  }

  Corneto_flight_program_contro_B.Product2_f = fabs(static_cast<real_T>
    (Corneto_flight_program_contro_B.In1_e.vz));
  if (Corneto_flight_program_contro_B.Product2_f >
      Corneto_flight_program_contro_B.Sum3) {
    Corneto_flight_program_contro_B.t = Corneto_flight_program_contro_B.Sum3 /
      Corneto_flight_program_contro_B.Product2_f;
    Corneto_flight_program_contro_B.Kp_phi =
      Corneto_flight_program_contro_B.Kp_phi * Corneto_flight_program_contro_B.t
      * Corneto_flight_program_contro_B.t + 1.0;
    Corneto_flight_program_contro_B.Sum3 =
      Corneto_flight_program_contro_B.Product2_f;
  } else {
    Corneto_flight_program_contro_B.t =
      Corneto_flight_program_contro_B.Product2_f /
      Corneto_flight_program_contro_B.Sum3;
    Corneto_flight_program_contro_B.Kp_phi += Corneto_flight_program_contro_B.t *
      Corneto_flight_program_contro_B.t;
  }

  Corneto_flight_program_contro_B.Kp_phi = Corneto_flight_program_contro_B.Sum3 *
    sqrt(Corneto_flight_program_contro_B.Kp_phi);

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // RateTransition: '<Root>/Rate Transition' incorporates:
  //   RateTransition: '<Root>/Rate Transition1'

  if (Corneto_flight_program_contr_M->Timing.TaskCounters.TID[1] == 0) {
    // RateTransition: '<Root>/Rate Transition'
    Corneto_flight_program_contro_B.RateTransition =
      Corneto_flight_program_contr_DW.RateTransition_Buffer0;

    // RateTransition: '<Root>/Rate Transition1'
    Corneto_flight_program_contro_B.RateTransition1 =
      Corneto_flight_program_contr_DW.RateTransition1_Buffer0;
  }

  // End of RateTransition: '<Root>/Rate Transition'

  // DiscretePulseGenerator: '<S8>/100 Hz'
  Corneto_flight_program_contro_B.Sum3 =
    (Corneto_flight_program_contr_DW.clockTickCounter <
     Corneto_flight_program_contro_P.u00Hz_Duty) &&
    (Corneto_flight_program_contr_DW.clockTickCounter >= 0) ?
    Corneto_flight_program_contro_P.u00Hz_Amp : 0.0;
  if (Corneto_flight_program_contr_DW.clockTickCounter >=
      Corneto_flight_program_contro_P.u00Hz_Period - 1.0) {
    Corneto_flight_program_contr_DW.clockTickCounter = 0;
  } else {
    Corneto_flight_program_contr_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S8>/100 Hz'

  // Outputs for Triggered SubSystem: '<S8>/Emulated Pixhawk' incorporates:
  //   TriggerPort: '<S19>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Corneto_flight_program__PrevZCX.EmulatedPixhawk_Trig_ZCE,
                     (Corneto_flight_program_contro_B.Sum3));
  if (zcEvent != NO_ZCEVENT) {
    if (Corneto_flight_program_contr_DW.EmulatedPixhawk_RESET_ELAPS_T) {
      EmulatedPixhawk_ELAPS_T = 0U;
    } else {
      EmulatedPixhawk_ELAPS_T =
        Corneto_flight_program_contr_M->Timing.clockTick0 -
        Corneto_flight_program_contr_DW.EmulatedPixhawk_PREV_T;
    }

    Corneto_flight_program_contr_DW.EmulatedPixhawk_PREV_T =
      Corneto_flight_program_contr_M->Timing.clockTick0;
    Corneto_flight_program_contr_DW.EmulatedPixhawk_RESET_ELAPS_T = false;

    // DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double16'

    Corneto_flight_program_contro_B.Product2_f =
      (Corneto_flight_program_contro_B.In1.rollspeed -
       Corneto_flight_program_contro_P.DiscreteTransferFcn_DenCoef[1] *
       Corneto_flight_program_contr_DW.DiscreteTransferFcn_states) /
      Corneto_flight_program_contro_P.DiscreteTransferFcn_DenCoef[0];
    rtb_TmpSignalConversionAtSFun_0 =
      Corneto_flight_program_contro_P.DiscreteTransferFcn_NumCoef[0] *
      Corneto_flight_program_contro_B.Product2_f +
      Corneto_flight_program_contro_P.DiscreteTransferFcn_NumCoef[1] *
      Corneto_flight_program_contr_DW.DiscreteTransferFcn_states;

    // DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S25>/Constant'
    //   DataTypeConversion: '<S19>/Cast To Double36'

    if (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
      // Switch: '<S19>/Switch1' incorporates:
      //   Constant: '<S19>/One1'
      //   Constant: '<S19>/One2'
      //   DataTypeConversion: '<Root>/Cast To Boolean3'

      if (Corneto_flight_program_contro_B.RateTransition1 != 0) {
        Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 =
          Corneto_flight_program_contro_P.One1_Value;
      } else {
        Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 =
          Corneto_flight_program_contro_P.One2_Value;
      }

      if ((Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 != 0.0) ||
          (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRese != 0))
      {
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTAT_b5 =
          Corneto_flight_program_contro_P.Constant_Value_m;
      } else {
        // DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTAT_b5 +=
          static_cast<real32_T>
          (Corneto_flight_program_contro_P.DiscreteTimeIntegrator_gainval *
           static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
           * Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U);
      }
    }

    // End of DiscreteIntegrator: '<S25>/Discrete-Time Integrator'

    // Sum: '<S25>/Sum3' incorporates:
    //   Constant: '<Root>/Constant2'

    Corneto_flight_program_contro_B.Sum3 =
      Corneto_flight_program_contro_P.Constant2_Value_m -
      Corneto_flight_program_contro_B.Product3_n;

    // Product: '<S25>/Product1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'
    //   DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn'
    //   Lookup_n-D: '<S26>/1-D Lookup Table3'
    //   Lookup_n-D: '<S26>/1-D Lookup Table5'
    //   Product: '<S25>/Product2'
    //   Sum: '<S25>/Sum4'
    //   Sum: '<S25>/Sum5'

    Corneto_flight_program_contro_B.t = ((look2_binlcapw(static_cast<real_T>
      (Corneto_flight_program_contro_B.In1_a.alt),
      Corneto_flight_program_contro_B.Kp_phi,
      Corneto_flight_program_contro_P.Autopilot.Phi.h_bkpts_m,
      Corneto_flight_program_contro_P.Autopilot.Phi.V_bkpts_mps,
      Corneto_flight_program_contro_P.Autopilot.Phi.Kp_phi_vec,
      Corneto_flight_program_contro_P.uDLookupTable5_maxIndex, 3U) *
      Corneto_flight_program_contro_B.Sum3 +
      Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTAT_b5) -
      rtb_TmpSignalConversionAtSFun_0) * look2_binlcapw(static_cast<real_T>
      (Corneto_flight_program_contro_B.In1_a.alt),
      Corneto_flight_program_contro_B.Kp_phi,
      Corneto_flight_program_contro_P.Autopilot.Phi.h_bkpts_m,
      Corneto_flight_program_contro_P.Autopilot.Phi.V_bkpts_mps,
      Corneto_flight_program_contro_P.Autopilot.Phi.Kp_p_vec,
      Corneto_flight_program_contro_P.uDLookupTable3_maxIndex, 3U);

    // Product: '<S27>/Product' incorporates:
    //   Constant: '<S20>/Zero'
    //   Constant: '<S27>/Constant7'

    for (i = 0; i < 4; i++) {
      Corneto_flight_program_contro_B.siB_cmd[i] =
        Corneto_flight_program_contro_P.Constant7_Value[i + 8] *
        Corneto_flight_program_contro_P.Zero_Value +
        (Corneto_flight_program_contro_P.Constant7_Value[i + 4] *
         Corneto_flight_program_contro_P.Zero_Value +
         Corneto_flight_program_contro_P.Constant7_Value[i] *
         Corneto_flight_program_contro_B.t);
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

    if (Corneto_flight_program_contro_B.RateTransition != 0.0F) {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 =
        Corneto_flight_program_contro_B.siB_cmd[0];
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_1 =
        Corneto_flight_program_contro_B.siB_cmd[1];
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_2 =
        Corneto_flight_program_contro_B.siB_cmd[2];
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_3 =
        Corneto_flight_program_contro_B.siB_cmd[3];
    } else {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 =
        Corneto_flight_program_contro_P.Gain1_Gain *
        Corneto_flight_program_contro_P.One5_Value_c;
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_1 =
        Corneto_flight_program_contro_P.Gain1_Gain_k *
        Corneto_flight_program_contro_P.One6_Value_m;
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_2 =
        Corneto_flight_program_contro_P.Gain1_Gain_m *
        Corneto_flight_program_contro_P.One7_Value;
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_3 =
        Corneto_flight_program_contro_P.Gain1_Gain_d *
        Corneto_flight_program_contro_P.One8_Value;
    }

    // End of Switch: '<S19>/Switch'

    // DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double13'

    Corneto_flight_program_contro_B.t = (Corneto_flight_program_contro_B.In1_i.x
      - Corneto_flight_program_contro_P.DiscreteTransferFcn_DenCoef_a[1] *
      Corneto_flight_program_contr_DW.DiscreteTransferFcn_states_b) /
      Corneto_flight_program_contro_P.DiscreteTransferFcn_DenCoef_a[0];
    Corneto_flight_program_contro_B.cumRevIndex =
      Corneto_flight_program_contro_P.DiscreteTransferFcn_NumCoef_b[0] *
      Corneto_flight_program_contro_B.t +
      Corneto_flight_program_contro_P.DiscreteTransferFcn_NumCoef_b[1] *
      Corneto_flight_program_contr_DW.DiscreteTransferFcn_states_b;

    // RelationalOperator: '<S39>/Compare' incorporates:
    //   Constant: '<S39>/Constant'
    //   DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'

    rtb_CastToBoolean2 = (Corneto_flight_program_contro_B.cumRevIndex >=
                          Corneto_flight_program_contro_P.Flight_Logic.Ax_launch_accel_threshold_mps2);

    // Logic: '<S41>/NOT' incorporates:
    //   Logic: '<S41>/AND'
    //   Memory: '<S30>/Memory'

    rtb_NOT = ((!rtb_CastToBoolean2) &&
               (!Corneto_flight_program_contr_DW.Memory_PreviousInput));

    // DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S41>/Constant1'

    if (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_d == 0) {
      if (rtb_NOT ||
          (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRe_h != 0))
      {
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE =
          Corneto_flight_program_contro_P.Constant1_Value_d;
      } else {
        // DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE +=
          Corneto_flight_program_contro_P.DiscreteTimeIntegrator_gainva_c *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U_e;
      }
    }

    // End of DiscreteIntegrator: '<S41>/Discrete-Time Integrator'

    // Switch: '<S42>/Switch1' incorporates:
    //   Constant: '<S40>/Constant'
    //   Logic: '<S30>/AND'
    //   Memory: '<S42>/Memory'
    //   RelationalOperator: '<S40>/Compare'

    Corneto_flight_program_contr_DW.Memory_PreviousInput = ((rtb_CastToBoolean2 &&
      (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE >=
       Corneto_flight_program_contro_P.Flight_Logic.Ax_launch_timer_threshold_sec))
      || Corneto_flight_program_contr_DW.Memory_PreviousInput_g);

    // Logic: '<S46>/NOT' incorporates:
    //   Constant: '<S44>/Constant'
    //   DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'
    //   Logic: '<S31>/AND'
    //   RelationalOperator: '<S44>/Compare'

    rtb_CastToBoolean2 = ((!Corneto_flight_program_contr_DW.Memory_PreviousInput)
                          || (!(Corneto_flight_program_contro_B.cumRevIndex <=
      Corneto_flight_program_contro_P.CompareToConstant2_const)));

    // DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S46>/Constant1'

    if (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_e == 0) {
      if (rtb_CastToBoolean2 ||
          (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRe_a != 0))
      {
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_f =
          Corneto_flight_program_contro_P.Constant1_Value_k;
      } else {
        // DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_f +=
          Corneto_flight_program_contro_P.DiscreteTimeIntegrator_gainva_h *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U_k;
      }
    }

    // End of DiscreteIntegrator: '<S46>/Discrete-Time Integrator'

    // Switch: '<S47>/Switch1' incorporates:
    //   Constant: '<S43>/Constant'
    //   Memory: '<S47>/Memory'
    //   RelationalOperator: '<S43>/Compare'

    Corneto_flight_program_contr_DW.Memory_PreviousInput_o =
      ((Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_f >=
        Corneto_flight_program_contro_P.Flight_Logic.Ax_MECO_timer_threshold_sec)
       || Corneto_flight_program_contr_DW.Memory_PreviousInput_o);

    // Switch: '<S30>/Switch' incorporates:
    //   Constant: '<S30>/Constant'

    if (Corneto_flight_program_contr_DW.Memory_PreviousInput) {
      Corneto_flight_program_contro_B.flight_mode_enum =
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE;
    } else {
      Corneto_flight_program_contro_B.flight_mode_enum =
        Corneto_flight_program_contro_P.Constant_Value_j;
    }

    // End of Switch: '<S30>/Switch'

    // Logic: '<S31>/AND1' incorporates:
    //   Constant: '<S45>/Constant'
    //   RelationalOperator: '<S45>/Compare'

    rtb_MECO_log = (Corneto_flight_program_contr_DW.Memory_PreviousInput_o ||
                    (Corneto_flight_program_contro_B.flight_mode_enum >=
                     Corneto_flight_program_contro_P.Flight_Logic.MECO_timeout_TOF_sec));

    // MATLABSystem: '<S28>/Moving Average1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'

    if (Corneto_flight_program_contr_DW.obj.TunablePropsChanged) {
      Corneto_flight_program_contr_DW.obj.TunablePropsChanged = false;
    }

    obj = Corneto_flight_program_contr_DW.obj.pStatistic;
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

    Corneto_flight_program_contro_B.cumRevIndex = obj->pCumRevIndex;
    Corneto_flight_program_contro_B.csum = obj->pCumSum;
    for (i = 0; i < 9; i++) {
      Corneto_flight_program_contro_B.csumrev[i] = obj->pCumSumRev[i];
    }

    Corneto_flight_program_contro_B.csum += static_cast<real_T>
      (Corneto_flight_program_contro_B.In1_a.alt);
    Corneto_flight_program_contro_B.z = Corneto_flight_program_contro_B.csumrev[
      static_cast<int32_T>(Corneto_flight_program_contro_B.cumRevIndex) - 1] +
      Corneto_flight_program_contro_B.csum;
    Corneto_flight_program_contro_B.csumrev[static_cast<int32_T>
      (Corneto_flight_program_contro_B.cumRevIndex) - 1] =
      Corneto_flight_program_contro_B.In1_a.alt;
    if (Corneto_flight_program_contro_B.cumRevIndex != 9.0) {
      Corneto_flight_program_contro_B.cumRevIndex++;
    } else {
      Corneto_flight_program_contro_B.cumRevIndex = 1.0;
      Corneto_flight_program_contro_B.csum = 0.0;
      for (i = 7; i >= 0; i--) {
        Corneto_flight_program_contro_B.csumrev[i] +=
          Corneto_flight_program_contro_B.csumrev[i + 1];
      }
    }

    obj->pCumSum = Corneto_flight_program_contro_B.csum;
    for (i = 0; i < 9; i++) {
      obj->pCumSumRev[i] = Corneto_flight_program_contro_B.csumrev[i];
    }

    obj->pCumRevIndex = Corneto_flight_program_contro_B.cumRevIndex;
    Corneto_flight_program_contro_B.cumRevIndex =
      Corneto_flight_program_contro_B.z / 10.0;

    // End of MATLABSystem: '<S28>/Moving Average1'

    // Logic: '<S37>/NOT' incorporates:
    //   RelationalOperator: '<S36>/FixPt Relational Operator'
    //   UnitDelay: '<S36>/Delay Input1'
    //
    //  Block description for '<S36>/Delay Input1':
    //
    //   Store in Global RAM

    rtb_NOT_c = !(Corneto_flight_program_contro_B.cumRevIndex <
                  Corneto_flight_program_contr_DW.DelayInput1_DSTATE);

    // DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S37>/Constant1'

    if (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_k == 0) {
      if (rtb_NOT_c ||
          (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRe_k != 0))
      {
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_b =
          Corneto_flight_program_contro_P.Constant1_Value_n;
      } else {
        // DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_b +=
          Corneto_flight_program_contro_P.DiscreteTimeIntegrator_gainv_hy *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U_h;
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

    Corneto_flight_program_contr_DW.Memory_PreviousInput_j = ((rtb_MECO_log &&
      (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_b >=
       Corneto_flight_program_contro_P.Flight_Logic.h_apogee_timer_threshold_sec)
      && (Corneto_flight_program_contro_B.In1_e.vz >
          Corneto_flight_program_contro_P.CompareToConstant_const)) ||
      Corneto_flight_program_contr_DW.Memory_PreviousInput_j);

    // Logic: '<S50>/NOT' incorporates:
    //   Constant: '<S35>/Constant'
    //   Logic: '<S28>/AND1'
    //   RelationalOperator: '<S35>/Compare'

    rtb_NOT_f = ((!Corneto_flight_program_contr_DW.Memory_PreviousInput_j) &&
                 (!(Corneto_flight_program_contro_B.flight_mode_enum >=
                    Corneto_flight_program_contro_P.Flight_Logic.apogee_timeout_TOF_sec)));

    // DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S50>/Constant1'

    if (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTE_es == 0) {
      if (rtb_NOT_f ||
          (Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRe_f != 0))
      {
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_d =
          Corneto_flight_program_contro_P.Constant1_Value_i;
      } else {
        // DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
        Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_d +=
          Corneto_flight_program_contro_P.DiscreteTimeIntegrator_gainv_c4 *
          static_cast<real_T>(EmulatedPixhawk_ELAPS_T)
          * Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U_c;
      }
    }

    // End of DiscreteIntegrator: '<S50>/Discrete-Time Integrator'

    // Switch: '<S51>/Switch1' incorporates:
    //   Constant: '<S48>/Constant'
    //   Memory: '<S51>/Memory'
    //   RelationalOperator: '<S48>/Compare'

    Corneto_flight_program_contr_DW.Memory_PreviousInput_ge =
      ((Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_d >=
        Corneto_flight_program_contro_P.Flight_Logic.apogee_recovery_timer_threshold_sec)
       || Corneto_flight_program_contr_DW.Memory_PreviousInput_ge);

    // Logic: '<S32>/AND2' incorporates:
    //   Constant: '<S32>/Constant'
    //   Constant: '<S49>/Constant'
    //   Logic: '<S32>/AND1'
    //   Logic: '<S32>/NOT'
    //   RelationalOperator: '<S49>/Compare'

    rtb_recovery_log = ((Corneto_flight_program_contr_DW.Memory_PreviousInput_ge
                         || (Corneto_flight_program_contro_B.flight_mode_enum >=
      Corneto_flight_program_contro_P.Flight_Logic.recovery_timeout_TOF_sec)) &&
                        (!(Corneto_flight_program_contro_P.Flight_Logic.disable_recovery_manual
      != 0.0)));

    // DataTypeConversion: '<S19>/Cast To Double3' incorporates:
    //   DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn'

    Corneto_flight_program_contro_B.CastToDouble3[4] =
      rtb_TmpSignalConversionAtSFun_0;

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

      Corneto_flight_program_contro_B.CastToDouble3[5] =
        Corneto_flight_program_contro_P.Constant4_Value;
    } else if (Corneto_flight_program_contro_P.Constant5_Value_p != 0.0) {
      // Switch: '<S29>/Switch4' incorporates:
      //   Constant: '<S29>/Constant6'
      //   DataTypeConversion: '<S19>/Cast To Double3'

      Corneto_flight_program_contro_B.CastToDouble3[5] =
        Corneto_flight_program_contro_P.Constant6_Value;
    } else if (rtb_MECO_log) {
      // Switch: '<S29>/Switch2' incorporates:
      //   Constant: '<S29>/Constant3'
      //   DataTypeConversion: '<S19>/Cast To Double3'
      //   Switch: '<S29>/Switch4'

      Corneto_flight_program_contro_B.CastToDouble3[5] =
        Corneto_flight_program_contro_P.Constant3_Value;
    } else if (Corneto_flight_program_contr_DW.Memory_PreviousInput) {
      // Switch: '<S29>/Switch1' incorporates:
      //   Constant: '<S29>/Constant2'
      //   DataTypeConversion: '<S19>/Cast To Double3'
      //   Switch: '<S29>/Switch2'
      //   Switch: '<S29>/Switch4'

      Corneto_flight_program_contro_B.CastToDouble3[5] =
        Corneto_flight_program_contro_P.Constant2_Value;
    } else if (Corneto_flight_program_contro_P.Constant5_Value != 0.0) {
      // Switch: '<S29>/Switch' incorporates:
      //   Constant: '<S29>/Constant1'
      //   DataTypeConversion: '<S19>/Cast To Double3'
      //   Switch: '<S29>/Switch1'
      //   Switch: '<S29>/Switch2'
      //   Switch: '<S29>/Switch4'

      Corneto_flight_program_contro_B.CastToDouble3[5] =
        Corneto_flight_program_contro_P.Constant1_Value;
    } else {
      // DataTypeConversion: '<S19>/Cast To Double3' incorporates:
      //   Constant: '<S29>/Constant'

      Corneto_flight_program_contro_B.CastToDouble3[5] =
        Corneto_flight_program_contro_P.Constant_Value_lj;
    }

    // End of Switch: '<S29>/Switch3'

    // DataTypeConversion: '<S19>/Cast To Double3'
    Corneto_flight_program_contro_B.CastToDouble3[0] =
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0;
    Corneto_flight_program_contro_B.CastToDouble3[6] =
      Corneto_flight_program_contro_B.siB_cmd[0];
    Corneto_flight_program_contro_B.CastToDouble3[1] =
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_1;
    Corneto_flight_program_contro_B.CastToDouble3[7] =
      Corneto_flight_program_contro_B.siB_cmd[1];
    Corneto_flight_program_contro_B.CastToDouble3[2] =
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_2;
    Corneto_flight_program_contro_B.CastToDouble3[8] =
      Corneto_flight_program_contro_B.siB_cmd[2];
    Corneto_flight_program_contro_B.CastToDouble3[3] =
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_3;
    Corneto_flight_program_contro_B.CastToDouble3[9] =
      Corneto_flight_program_contro_B.siB_cmd[3];

    // MATLABSystem: '<S23>/PX4 PWM Output1'
    for (i = 0; i < 8; i++) {
      Corneto_flight_program_contro_B.pwmValue[i] = 0U;
    }

    // Gain: '<S52>/Gain'
    rtb_TmpSignalConversionAtSFun_0 = Corneto_flight_program_contro_P.Gain_Gain *
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0;

    // Saturate: '<S23>/Saturation'
    if (rtb_TmpSignalConversionAtSFun_0 >
        Corneto_flight_program_contro_P.Saturation_UpperSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Corneto_flight_program_contro_P.Saturation_UpperSat;
    } else if (rtb_TmpSignalConversionAtSFun_0 <
               Corneto_flight_program_contro_P.Saturation_LowerSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Corneto_flight_program_contro_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation'

    // DataTypeConversion: '<S23>/Cast To Double' incorporates:
    //   Constant: '<S23>/One'
    //   Gain: '<S23>/Gain'
    //   Sum: '<S23>/Add'

    Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = floor
      (Corneto_flight_program_contro_P.Gain_Gain_b *
       rtb_TmpSignalConversionAtSFun_0 +
       Corneto_flight_program_contro_P.One_Value);
    if (rtIsNaN(Corneto_flight_program_contro_B.rtb_Switch_j_idx_0) || rtIsInf
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)) {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = 0.0;
    } else {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = fmod
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double'

    Corneto_flight_program_contro_B.pwmValue[0] = static_cast<uint16_T>
      (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)));

    // Gain: '<S53>/Gain'
    rtb_TmpSignalConversionAtSFun_0 =
      Corneto_flight_program_contro_P.Gain_Gain_o *
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_1;

    // Saturate: '<S23>/Saturation1'
    if (rtb_TmpSignalConversionAtSFun_0 >
        Corneto_flight_program_contro_P.Saturation1_UpperSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Corneto_flight_program_contro_P.Saturation1_UpperSat;
    } else if (rtb_TmpSignalConversionAtSFun_0 <
               Corneto_flight_program_contro_P.Saturation1_LowerSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Corneto_flight_program_contro_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation1'

    // DataTypeConversion: '<S23>/Cast To Double1' incorporates:
    //   Constant: '<S23>/One1'
    //   Gain: '<S23>/Gain1'
    //   Sum: '<S23>/Add1'

    Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = floor
      (Corneto_flight_program_contro_P.Gain1_Gain_l *
       rtb_TmpSignalConversionAtSFun_0 +
       Corneto_flight_program_contro_P.One1_Value_b);
    if (rtIsNaN(Corneto_flight_program_contro_B.rtb_Switch_j_idx_0) || rtIsInf
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)) {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = 0.0;
    } else {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = fmod
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double1'

    Corneto_flight_program_contro_B.pwmValue[1] = static_cast<uint16_T>
      (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)));

    // Gain: '<S54>/Gain'
    rtb_TmpSignalConversionAtSFun_0 =
      Corneto_flight_program_contro_P.Gain_Gain_g *
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_2;

    // Saturate: '<S23>/Saturation2'
    if (rtb_TmpSignalConversionAtSFun_0 >
        Corneto_flight_program_contro_P.Saturation2_UpperSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Corneto_flight_program_contro_P.Saturation2_UpperSat;
    } else if (rtb_TmpSignalConversionAtSFun_0 <
               Corneto_flight_program_contro_P.Saturation2_LowerSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Corneto_flight_program_contro_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation2'

    // DataTypeConversion: '<S23>/Cast To Double2' incorporates:
    //   Constant: '<S23>/One2'
    //   Gain: '<S23>/Gain2'
    //   Sum: '<S23>/Add2'

    Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = floor
      (Corneto_flight_program_contro_P.Gain2_Gain *
       rtb_TmpSignalConversionAtSFun_0 +
       Corneto_flight_program_contro_P.One2_Value_d);
    if (rtIsNaN(Corneto_flight_program_contro_B.rtb_Switch_j_idx_0) || rtIsInf
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)) {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = 0.0;
    } else {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = fmod
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double2'

    Corneto_flight_program_contro_B.pwmValue[2] = static_cast<uint16_T>
      (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)));

    // Gain: '<S55>/Gain'
    rtb_TmpSignalConversionAtSFun_0 =
      Corneto_flight_program_contro_P.Gain_Gain_l *
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_3;

    // Saturate: '<S23>/Saturation3'
    if (rtb_TmpSignalConversionAtSFun_0 >
        Corneto_flight_program_contro_P.Saturation3_UpperSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Corneto_flight_program_contro_P.Saturation3_UpperSat;
    } else if (rtb_TmpSignalConversionAtSFun_0 <
               Corneto_flight_program_contro_P.Saturation3_LowerSat) {
      rtb_TmpSignalConversionAtSFun_0 =
        Corneto_flight_program_contro_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S23>/Saturation3'

    // DataTypeConversion: '<S23>/Cast To Double3' incorporates:
    //   Constant: '<S23>/One3'
    //   Gain: '<S23>/Gain3'
    //   Sum: '<S23>/Add3'

    Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = floor
      (Corneto_flight_program_contro_P.Gain3_Gain *
       rtb_TmpSignalConversionAtSFun_0 +
       Corneto_flight_program_contro_P.One3_Value);
    if (rtIsNaN(Corneto_flight_program_contro_B.rtb_Switch_j_idx_0) || rtIsInf
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)) {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = 0.0;
    } else {
      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = fmod
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0, 65536.0);
    }

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   DataTypeConversion: '<S23>/Cast To Double3'

    Corneto_flight_program_contro_B.pwmValue[3] = static_cast<uint16_T>
      (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 < 0.0 ?
       static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>
          (-Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)))) :
       static_cast<int32_T>(static_cast<uint16_T>
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)));

    // Switch: '<S23>/Switch'
    if (rtb_recovery_log) {
      // DataTypeConversion: '<S23>/Cast To Double4' incorporates:
      //   Constant: '<S23>/One5'

      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = floor
        (Corneto_flight_program_contro_P.One5_Value);
      if (rtIsNaN(Corneto_flight_program_contro_B.rtb_Switch_j_idx_0) || rtIsInf
          (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)) {
        Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = 0.0;
      } else {
        Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = fmod
          (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0, 65536.0);
      }

      // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
      //   DataTypeConversion: '<S23>/Cast To Double4'

      Corneto_flight_program_contro_B.pwmValue[4] = static_cast<uint16_T>
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 < 0.0 ? static_cast<
         int32_T>(static_cast<uint16_T>(-static_cast<int16_T>
           (static_cast<uint16_T>
            (-Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)))) :
         static_cast<int32_T>(static_cast<uint16_T>
          (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)));
    } else {
      // DataTypeConversion: '<S23>/Cast To Double4' incorporates:
      //   Constant: '<S23>/One6'

      Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = floor
        (Corneto_flight_program_contro_P.One6_Value);
      if (rtIsNaN(Corneto_flight_program_contro_B.rtb_Switch_j_idx_0) || rtIsInf
          (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)) {
        Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = 0.0;
      } else {
        Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 = fmod
          (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0, 65536.0);
      }

      // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
      //   DataTypeConversion: '<S23>/Cast To Double4'

      Corneto_flight_program_contro_B.pwmValue[4] = static_cast<uint16_T>
        (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0 < 0.0 ? static_cast<
         int32_T>(static_cast<uint16_T>(-static_cast<int16_T>
           (static_cast<uint16_T>
            (-Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)))) :
         static_cast<int32_T>(static_cast<uint16_T>
          (Corneto_flight_program_contro_B.rtb_Switch_j_idx_0)));
    }

    // End of Switch: '<S23>/Switch'

    // MATLABSystem: '<S23>/PX4 PWM Output1' incorporates:
    //   Constant: '<S23>/One4'
    //   Constant: '<S23>/One7'

    if (Corneto_flight_program_contro_P.One7_Value_g) {
      if (!Corneto_flight_program_contr_DW.obj_mo.isArmed) {
        Corneto_flight_program_contr_DW.obj_mo.isArmed = true;
        status = pwm_arm(&Corneto_flight_program_contr_DW.obj_mo.pwmDevHandler,
                         &Corneto_flight_program_contr_DW.obj_mo.armAdvertiseObj);
        Corneto_flight_program_contr_DW.obj_mo.errorStatus =
          static_cast<uint16_T>
          (Corneto_flight_program_contr_DW.obj_mo.errorStatus | status);
      }

      status = pwm_setServo
        (&Corneto_flight_program_contr_DW.obj_mo.pwmDevHandler,
         Corneto_flight_program_contr_DW.obj_mo.servoCount,
         Corneto_flight_program_contr_DW.obj_mo.channelMask,
         &Corneto_flight_program_contro_B.pwmValue[0],
         Corneto_flight_program_contr_DW.obj_mo.isMain,
         &Corneto_flight_program_contr_DW.obj_mo.actuatorAdvertiseObj);
      Corneto_flight_program_contr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Corneto_flight_program_contr_DW.obj_mo.errorStatus | status);
    } else {
      status = pwm_disarm(&Corneto_flight_program_contr_DW.obj_mo.pwmDevHandler,
                          &Corneto_flight_program_contr_DW.obj_mo.armAdvertiseObj);
      Corneto_flight_program_contr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Corneto_flight_program_contr_DW.obj_mo.errorStatus | status);
      Corneto_flight_program_contr_DW.obj_mo.isArmed = false;
      status = pwm_resetServo
        (&Corneto_flight_program_contr_DW.obj_mo.pwmDevHandler,
         Corneto_flight_program_contr_DW.obj_mo.servoCount,
         Corneto_flight_program_contr_DW.obj_mo.channelMask,
         Corneto_flight_program_contr_DW.obj_mo.isMain,
         &Corneto_flight_program_contr_DW.obj_mo.actuatorAdvertiseObj);
      Corneto_flight_program_contr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Corneto_flight_program_contr_DW.obj_mo.errorStatus | status);
    }

    if (Corneto_flight_program_contr_DW.obj_mo.isMain) {
      status = pwm_forceFailsafe
        (&Corneto_flight_program_contr_DW.obj_mo.pwmDevHandler,
         static_cast<int32_T>(Corneto_flight_program_contro_P.One4_Value));
      Corneto_flight_program_contr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Corneto_flight_program_contr_DW.obj_mo.errorStatus | status);
    }

    // Update for DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn'
    Corneto_flight_program_contr_DW.DiscreteTransferFcn_states =
      Corneto_flight_program_contro_B.Product2_f;

    // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;

    // Switch: '<S19>/Switch1' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Boolean3'

    if (Corneto_flight_program_contro_B.RateTransition1 != 0) {
      // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
      //   Constant: '<S19>/One1'
      //   DataTypeConversion: '<S19>/Cast To Double36'

      Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRese =
        static_cast<int8_T>(Corneto_flight_program_contro_P.One1_Value != 0.0);
    } else {
      // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
      //   Constant: '<S19>/One2'
      //   DataTypeConversion: '<S19>/Cast To Double36'

      Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRese =
        static_cast<int8_T>(Corneto_flight_program_contro_P.One2_Value != 0.0);
    }

    // Update for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Double4'
    //   Lookup_n-D: '<S26>/1-D Lookup Table4'
    //   Product: '<S25>/Product3'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U =
      look2_binlcapw(static_cast<real_T>
                     (Corneto_flight_program_contro_B.In1_a.alt),
                     Corneto_flight_program_contro_B.Kp_phi,
                     Corneto_flight_program_contro_P.Autopilot.Phi.h_bkpts_m,
                     Corneto_flight_program_contro_P.Autopilot.Phi.V_bkpts_mps,
                     Corneto_flight_program_contro_P.Autopilot.Phi.Ki_phi_vec,
                     Corneto_flight_program_contro_P.uDLookupTable4_maxIndex, 3U)
      * Corneto_flight_program_contro_B.Sum3;

    // Update for DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn'
    Corneto_flight_program_contr_DW.DiscreteTransferFcn_states_b =
      Corneto_flight_program_contro_B.t;

    // Update for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S41>/Constant'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_d = 0U;
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRe_h =
      static_cast<int8_T>(rtb_NOT);
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U_e =
      Corneto_flight_program_contro_P.Constant_Value_k;

    // Update for Memory: '<S42>/Memory'
    Corneto_flight_program_contr_DW.Memory_PreviousInput_g =
      Corneto_flight_program_contr_DW.Memory_PreviousInput;

    // Update for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S46>/Constant'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_e = 0U;
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRe_a =
      static_cast<int8_T>(rtb_CastToBoolean2);
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U_k =
      Corneto_flight_program_contro_P.Constant_Value_e;

    // Update for UnitDelay: '<S36>/Delay Input1'
    //
    //  Block description for '<S36>/Delay Input1':
    //
    //   Store in Global RAM

    Corneto_flight_program_contr_DW.DelayInput1_DSTATE =
      Corneto_flight_program_contro_B.cumRevIndex;

    // Update for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S37>/Constant'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_k = 0U;
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRe_k =
      static_cast<int8_T>(rtb_NOT_c);
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U_h =
      Corneto_flight_program_contro_P.Constant_Value_a;

    // Update for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S50>/Constant'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTE_es = 0U;
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PrevRe_f =
      static_cast<int8_T>(rtb_NOT_f);
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_PREV_U_c =
      Corneto_flight_program_contro_P.Constant_Value_b;
  }

  // End of Outputs for SubSystem: '<S8>/Emulated Pixhawk'

  // RateTransition: '<Root>/Rate Transition3' incorporates:
  //   RateTransition: '<Root>/Rate Transition4'

  if (Corneto_flight_program_contr_M->Timing.TaskCounters.TID[1] == 0) {
    // RateTransition: '<Root>/Rate Transition4' incorporates:
    //   DataTypeConversion: '<Root>/Cast To Boolean2'

    Corneto_flight_program_contro_B.RateTransition4 =
      (Corneto_flight_program_contr_DW.RateTransition3_Buffer0 != 0.0F);
  }

  // End of RateTransition: '<Root>/Rate Transition3'

  // SignalConversion generated from: '<S69>/ SFunction ' incorporates:
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
  //   MATLAB Function: '<S68>/SDCard_logger'

  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[0] =
    Corneto_flight_program_contro_B.In1_a.lat;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[1] =
    Corneto_flight_program_contro_B.In1_a.lon;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[2] =
    Corneto_flight_program_contro_B.In1_a.alt;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[3] =
    Corneto_flight_program_contro_B.In1_a.fix_type;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[4] =
    Corneto_flight_program_contro_B.In1_a.satellites_used;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[5] =
    Corneto_flight_program_contro_B.In1_a.vel_m_s;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[6] =
    Corneto_flight_program_contro_B.In1_a.vel_n_m_s;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[7] =
    Corneto_flight_program_contro_B.In1_a.vel_e_m_s;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[8] =
    Corneto_flight_program_contro_B.In1_a.vel_d_m_s;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[9] =
    Corneto_flight_program_contro_B.In1.rollspeed;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[10] =
    Corneto_flight_program_contro_B.In1.pitchspeed;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[11] =
    Corneto_flight_program_contro_B.In1.yawspeed;

  // Trigonometry: '<S60>/trigFcn'
  if (Corneto_flight_program_contro_B.fcn3 > 1.0) {
    Corneto_flight_program_contro_B.fcn3 = 1.0;
  } else if (Corneto_flight_program_contro_B.fcn3 < -1.0) {
    Corneto_flight_program_contro_B.fcn3 = -1.0;
  }

  // SignalConversion generated from: '<S69>/ SFunction ' incorporates:
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
  //   MATLAB Function: '<S68>/SDCard_logger'
  //   Trigonometry: '<S60>/trigFcn'

  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[13] = asin
    (Corneto_flight_program_contro_B.fcn3);
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[14] =
    Corneto_flight_program_contro_B.Product3_n;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[15] =
    Corneto_flight_program_contro_B.In1_i.x;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[16] =
    Corneto_flight_program_contro_B.In1_i.y;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[17] =
    Corneto_flight_program_contro_B.In1_i.z;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[18] =
    Corneto_flight_program_contro_B.In1_eg.x;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[19] =
    Corneto_flight_program_contro_B.In1_eg.y;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[20] =
    Corneto_flight_program_contro_B.In1_eg.z;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[21] =
    Corneto_flight_program_contro_B.In1_e.ax;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[22] =
    Corneto_flight_program_contro_B.In1_e.ay;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[23] =
    Corneto_flight_program_contro_B.In1_e.az;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[24] =
    Corneto_flight_program_contro_B.In1_e.z;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[25] =
    Corneto_flight_program_contro_B.In1_e.x;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[26] =
    Corneto_flight_program_contro_B.In1_e.y;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[27] =
    Corneto_flight_program_contro_B.In1_e.vx;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[28] =
    Corneto_flight_program_contro_B.In1_e.vy;
  Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[29] =
    Corneto_flight_program_contro_B.In1_e.vz;
  memcpy(&Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[30],
         &Corneto_flight_program_contro_B.CastToDouble3[0], 10U * sizeof(real_T));

  // MATLAB Function: '<S68>/SDCard_logger'
  Corneto_flight_program_contro_B.timestamp = hrt_absolute_time();
  if (!Corneto_flight_program_contr_DW.count_not_empty) {
    Corneto_flight_program_contr_DW.count_not_empty = true;
    elem_type = 1U;
    Corneto_flight_program_contr_DW.vect_size = 40U;
    for (i = 0; i < 56; i++) {
      Corneto_flight_program_contro_B.b[i] = i_0[i];
    }

    for (i = 0; i < 24; i++) {
      Corneto_flight_program_contro_B.c[i] = g[i];
    }

    printf(&Corneto_flight_program_contro_B.b[0],
           &Corneto_flight_program_contro_B.c[0], static_cast<uint32_T>
           (Corneto_flight_program_contr_DW.vect_size), static_cast<uint32_T>
           (Corneto_flight_program_contr_DW.elem_size), 276447232U, 10);
    for (i = 0; i < 24; i++) {
      Corneto_flight_program_contro_B.c[i] = g[i];
    }

    d[0] = 'w';
    d[1] = 'b';
    d[2] = '\x00';
    Corneto_flight_program_contr_DW.fp = fopen
      (&Corneto_flight_program_contro_B.c[0], &d[0]);
    fwrite(&mlStrVer[0], 1U, 5.0, Corneto_flight_program_contr_DW.fp);
    tm = time(&EmulatedPixhawk_ELAPS_T);
    fwrite(&tm, 4U, 1U, Corneto_flight_program_contr_DW.fp);
    fwrite(&Corneto_flight_program_contr_DW.vect_size, 1U, 1U,
           Corneto_flight_program_contr_DW.fp);
    fwrite(&elem_type, 1U, 1U, Corneto_flight_program_contr_DW.fp);
    EmulatedPixhawk_ELAPS_T = static_cast<uint32_T>
      (Corneto_flight_program_contr_DW.elem_size) *
      Corneto_flight_program_contr_DW.vect_size;
    if (EmulatedPixhawk_ELAPS_T > 65535U) {
      EmulatedPixhawk_ELAPS_T = 65535U;
    }

    status = static_cast<uint16_T>(EmulatedPixhawk_ELAPS_T);
    fwrite(&status, 2U, 1U, Corneto_flight_program_contr_DW.fp);
  }

  if (Corneto_flight_program_contro_B.RateTransition4 &&
      (Corneto_flight_program_contr_DW.count < 276447232U)) {
    if (!Corneto_flight_program_contr_DW.isopen) {
      for (i = 0; i < 24; i++) {
        Corneto_flight_program_contro_B.c[i] = g[i];
      }

      d[0] = 'a';
      d[1] = 'b';
      d[2] = '\x00';
      Corneto_flight_program_contr_DW.fp = fopen
        (&Corneto_flight_program_contro_B.c[0], &d[0]);
      Corneto_flight_program_contr_DW.isflushed = false;
      Corneto_flight_program_contr_DW.isopen = true;
    }

    fwrite(&Corneto_flight_program_contro_B.TmpSignalConversionAtSFunct[0],
           Corneto_flight_program_contr_DW.elem_size,
           Corneto_flight_program_contr_DW.vect_size,
           Corneto_flight_program_contr_DW.fp);
    fwrite(&Corneto_flight_program_contro_B.timestamp, 8U, 1U,
           Corneto_flight_program_contr_DW.fp);
    EmulatedPixhawk_ELAPS_T = Corneto_flight_program_contr_DW.count +
      /*MW:OvSatOk*/ 1U;
    if (Corneto_flight_program_contr_DW.count + 1U <
        Corneto_flight_program_contr_DW.count) {
      EmulatedPixhawk_ELAPS_T = MAX_uint32_T;
    }

    Corneto_flight_program_contr_DW.count = EmulatedPixhawk_ELAPS_T;
  } else {
    if (Corneto_flight_program_contr_DW.isopen) {
      if (!Corneto_flight_program_contr_DW.isflushed) {
        for (i = 0; i < 28; i++) {
          Corneto_flight_program_contro_B.e[i] = f[i];
        }

        printf(&Corneto_flight_program_contro_B.e[0],
               Corneto_flight_program_contr_DW.count, 10);
        fflush(Corneto_flight_program_contr_DW.fp);
        Corneto_flight_program_contr_DW.isflushed = true;
      }

      fclose(Corneto_flight_program_contr_DW.fp);
    }

    Corneto_flight_program_contr_DW.isopen = false;
  }

  if (Corneto_flight_program_contr_M->Timing.TaskCounters.TID[1] == 0) {
    // MATLABSystem: '<Root>/Read Parameter'
    if (Corneto_flight_program_contr_DW.obj_b.SampleTime !=
        Corneto_flight_program_contro_P.ReadParameter_SampleTime) {
      Corneto_flight_program_contr_DW.obj_b.SampleTime =
        Corneto_flight_program_contro_P.ReadParameter_SampleTime;
    }

    Corneto_flight_program_contro_B.ParamDataType = MW_INT32;
    rtb_NOT = MW_Param_Step(Corneto_flight_program_contr_DW.obj_b.MW_PARAMHANDLE,
      Corneto_flight_program_contro_B.ParamDataType, &i);
    if (rtb_NOT) {
      i = 0;
    }

    // DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
    //   MATLABSystem: '<Root>/Read Parameter'

    rtb_DataTypeConversion3 = static_cast<real32_T>(i);

    // MATLABSystem: '<Root>/Read Parameter1'
    if (Corneto_flight_program_contr_DW.obj_l.SampleTime !=
        Corneto_flight_program_contro_P.ReadParameter1_SampleTime) {
      Corneto_flight_program_contr_DW.obj_l.SampleTime =
        Corneto_flight_program_contro_P.ReadParameter1_SampleTime;
    }

    Corneto_flight_program_contro_B.ParamDataType = MW_INT32;
    rtb_NOT = MW_Param_Step(Corneto_flight_program_contr_DW.obj_l.MW_PARAMHANDLE,
      Corneto_flight_program_contro_B.ParamDataType, &i);
    if (rtb_NOT) {
      i = 0;
    }

    // DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
    //   MATLABSystem: '<Root>/Read Parameter1'

    rtb_DataTypeConversion2 = static_cast<real32_T>(i);

    // MATLABSystem: '<Root>/Read Parameter2'
    if (Corneto_flight_program_contr_DW.obj_m.SampleTime !=
        Corneto_flight_program_contro_P.ReadParameter2_SampleTime) {
      Corneto_flight_program_contr_DW.obj_m.SampleTime =
        Corneto_flight_program_contro_P.ReadParameter2_SampleTime;
    }

    Corneto_flight_program_contro_B.ParamDataType = MW_INT32;
    rtb_NOT = MW_Param_Step(Corneto_flight_program_contr_DW.obj_m.MW_PARAMHANDLE,
      Corneto_flight_program_contro_B.ParamDataType, &rtb_ReadParameter2_o1);
    if (rtb_NOT) {
      rtb_ReadParameter2_o1 = 0;
    }

    // End of MATLABSystem: '<Root>/Read Parameter2'

    // BusAssignment: '<Root>/Bus Assignment1' incorporates:
    //   Constant: '<S4>/Constant'
    //   DataTypeConversion: '<Root>/Data Type Conversion4'

    Corneto_flight_program_contro_B.BusAssignment1 =
      Corneto_flight_program_contro_P.Constant_Value_h;
    Corneto_flight_program_contro_B.BusAssignment1.x = rtb_DataTypeConversion3;
    Corneto_flight_program_contro_B.BusAssignment1.y = rtb_DataTypeConversion2;
    Corneto_flight_program_contro_B.BusAssignment1.z = static_cast<real32_T>
      (rtb_ReadParameter2_o1);

    // MATLABSystem: '<S7>/SinkBlock' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment1'

    uORB_write_step(Corneto_flight_program_contr_DW.obj_o.orbMetadataObj,
                    &Corneto_flight_program_contr_DW.obj_o.orbAdvertiseObj,
                    &Corneto_flight_program_contro_B.BusAssignment1);

    // Update for RateTransition: '<Root>/Rate Transition'
    Corneto_flight_program_contr_DW.RateTransition_Buffer0 =
      rtb_DataTypeConversion2;

    // Update for RateTransition: '<Root>/Rate Transition1'
    Corneto_flight_program_contr_DW.RateTransition1_Buffer0 =
      rtb_ReadParameter2_o1;

    // Update for RateTransition: '<Root>/Rate Transition3'
    Corneto_flight_program_contr_DW.RateTransition3_Buffer0 =
      rtb_DataTypeConversion3;
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.005, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  Corneto_flight_program_contr_M->Timing.clockTick0++;
  rate_scheduler();
}

// Model initialize function
void Corneto_flight_program_control_initialize(void)
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
    Corneto_flight_program_contro_B.RateTransition =
      Corneto_flight_program_contro_P.RateTransition_InitialCondition;

    // Start for RateTransition: '<Root>/Rate Transition1'
    Corneto_flight_program_contro_B.RateTransition1 =
      Corneto_flight_program_contro_P.RateTransition1_InitialConditio;
    Corneto_flight_program__PrevZCX.EmulatedPixhawk_Trig_ZCE =
      UNINITIALIZED_ZCSIG;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition'
    Corneto_flight_program_contr_DW.RateTransition_Buffer0 =
      Corneto_flight_program_contro_P.RateTransition_InitialCondition;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition1'
    Corneto_flight_program_contr_DW.RateTransition1_Buffer0 =
      Corneto_flight_program_contro_P.RateTransition1_InitialConditio;

    // InitializeConditions for RateTransition: '<Root>/Rate Transition3'
    Corneto_flight_program_contr_DW.RateTransition3_Buffer0 =
      Corneto_flight_program_contro_P.RateTransition3_InitialConditio;

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S17>/Out1' incorporates:
    //   Inport: '<S17>/In1'

    Corneto_flight_program_contro_B.In1_a =
      Corneto_flight_program_contro_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S72>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S73>/Out1' incorporates:
    //   Inport: '<S73>/In1'

    Corneto_flight_program_contro_B.In1 =
      Corneto_flight_program_contro_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S72>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S13>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S14>/Out1' incorporates:
    //   Inport: '<S14>/In1'

    Corneto_flight_program_contro_B.In1_i =
      Corneto_flight_program_contro_P.Out1_Y0_iw;

    // End of SystemInitialize for SubSystem: '<S13>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S16>/Out1' incorporates:
    //   Inport: '<S16>/In1'

    Corneto_flight_program_contro_B.In1_eg =
      Corneto_flight_program_contro_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S18>/Out1' incorporates:
    //   Inport: '<S18>/In1'

    Corneto_flight_program_contro_B.In1_e =
      Corneto_flight_program_contro_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Triggered SubSystem: '<S8>/Emulated Pixhawk'
    // InitializeConditions for DiscreteTransferFcn: '<S20>/Discrete Transfer Fcn' 
    Corneto_flight_program_contr_DW.DiscreteTransferFcn_states =
      Corneto_flight_program_contro_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteIntegrator: '<S25>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S25>/Constant'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTAT_b5 =
      Corneto_flight_program_contro_P.Constant_Value_m;

    // InitializeConditions for DiscreteTransferFcn: '<S19>/Discrete Transfer Fcn' 
    Corneto_flight_program_contr_DW.DiscreteTransferFcn_states_b =
      Corneto_flight_program_contro_P.DiscreteTransferFcn_InitialSt_g;

    // InitializeConditions for Switch: '<S42>/Switch1' incorporates:
    //   Memory: '<S30>/Memory'

    Corneto_flight_program_contr_DW.Memory_PreviousInput =
      Corneto_flight_program_contro_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S41>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S41>/Constant1'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE =
      Corneto_flight_program_contro_P.Constant1_Value_d;

    // InitializeConditions for Memory: '<S42>/Memory'
    Corneto_flight_program_contr_DW.Memory_PreviousInput_g =
      Corneto_flight_program_contro_P.Memory_InitialCondition_n;

    // InitializeConditions for DiscreteIntegrator: '<S46>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S46>/Constant1'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_f =
      Corneto_flight_program_contro_P.Constant1_Value_k;

    // InitializeConditions for Switch: '<S47>/Switch1' incorporates:
    //   Memory: '<S47>/Memory'

    Corneto_flight_program_contr_DW.Memory_PreviousInput_o =
      Corneto_flight_program_contro_P.Memory_InitialCondition_l;

    // InitializeConditions for UnitDelay: '<S36>/Delay Input1'
    //
    //  Block description for '<S36>/Delay Input1':
    //
    //   Store in Global RAM

    Corneto_flight_program_contr_DW.DelayInput1_DSTATE =
      Corneto_flight_program_contro_P.DetectDecrease_vinit;

    // InitializeConditions for DiscreteIntegrator: '<S37>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S37>/Constant1'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_b =
      Corneto_flight_program_contro_P.Constant1_Value_n;

    // InitializeConditions for Switch: '<S38>/Switch1' incorporates:
    //   Memory: '<S38>/Memory'

    Corneto_flight_program_contr_DW.Memory_PreviousInput_j =
      Corneto_flight_program_contro_P.Memory_InitialCondition_b;

    // InitializeConditions for DiscreteIntegrator: '<S50>/Discrete-Time Integrator' incorporates:
    //   Constant: '<S50>/Constant1'

    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_DSTATE_d =
      Corneto_flight_program_contro_P.Constant1_Value_i;

    // InitializeConditions for Switch: '<S51>/Switch1' incorporates:
    //   Memory: '<S51>/Memory'

    Corneto_flight_program_contr_DW.Memory_PreviousInput_ge =
      Corneto_flight_program_contro_P.Memory_InitialCondition_m;

    // Start for MATLABSystem: '<S28>/Moving Average1'
    Corneto_flight_program_contr_DW.obj.matlabCodegenIsDeleted = true;
    Corneto_flight_program_contr_DW.obj.isInitialized = 0;
    Corneto_flight_program_contr_DW.obj.NumChannels = -1;
    Corneto_flight_program_contr_DW.obj.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj.isInitialized = 1;
    Corneto_flight_program_contr_DW.obj.NumChannels = 1;
    Corneto_flight_program_contr_DW.obj._pobj0.isInitialized = 0;
    Corneto_flight_program_contr_DW.obj.pStatistic =
      &Corneto_flight_program_contr_DW.obj._pobj0;
    Corneto_flight_program_contr_DW.obj.isSetupComplete = true;
    Corneto_flight_program_contr_DW.obj.TunablePropsChanged = false;

    // InitializeConditions for MATLABSystem: '<S28>/Moving Average1'
    obj_0 = Corneto_flight_program_contr_DW.obj.pStatistic;
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

    Corneto_flight_program_contr_DW.obj_mo.errorStatus = 0U;
    Corneto_flight_program_contr_DW.obj_mo.isInitialized = 0;
    Corneto_flight_program_contr_DW.obj_mo.matlabCodegenIsDeleted = false;
    Corneto_flight_SystemCore_setup(&Corneto_flight_program_contr_DW.obj_mo,
      Corneto_flight_program_contro_P.One7_Value_g,
      Corneto_flight_program_contro_P.One4_Value);
    for (i = 0; i < 10; i++) {
      // SystemInitialize for DataTypeConversion: '<S19>/Cast To Double3' incorporates:
      //   Outport: '<S19>/Pix_Out'

      Corneto_flight_program_contro_B.CastToDouble3[i] =
        Corneto_flight_program_contro_P.Pix_Out_Y0;
    }

    // End of SystemInitialize for SubSystem: '<S8>/Emulated Pixhawk'

    // SystemInitialize for MATLAB Function: '<S68>/SDCard_logger'
    Corneto_flight_program_contr_DW.elem_size = 8U;
    Corneto_flight_program_contr_DW.isopen = true;

    // Start for MATLABSystem: '<S71>/SinkBlock' incorporates:
    //   BusAssignment: '<S11>/Bus Assignment'

    Corneto_flight_program_contr_DW.obj_lw.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_lw.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_lw.isInitialized = 1;
    Corneto_flight_program_contr_DW.obj_lw.orbMetadataObj = ORB_ID(mavlink_log);
    uORB_write_initialize(Corneto_flight_program_contr_DW.obj_lw.orbMetadataObj,
                          &Corneto_flight_program_contr_DW.obj_lw.orbAdvertiseObj,
                          &Corneto_flight_program_contro_B.BusAssignment_k, 1);
    Corneto_flight_program_contr_DW.obj_lw.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/SourceBlock'
    Corneto_flight_program_contr_DW.obj_k.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_k.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_k.isInitialized = 1;
    Corneto_flight_program_contr_DW.obj_k.orbMetadataObj = ORB_ID
      (vehicle_gps_position);
    uORB_read_initialize(Corneto_flight_program_contr_DW.obj_k.orbMetadataObj,
                         &Corneto_flight_program_contr_DW.obj_k.eventStructObj);
    Corneto_flight_program_contr_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S72>/SourceBlock'
    Corneto_flight_program_contr_DW.obj_n.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_n.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_n.isInitialized = 1;
    Corneto_flight_program_contr_DW.obj_n.orbMetadataObj = ORB_ID
      (vehicle_odometry);
    uORB_read_initialize(Corneto_flight_program_contr_DW.obj_n.orbMetadataObj,
                         &Corneto_flight_program_contr_DW.obj_n.eventStructObj);
    Corneto_flight_program_contr_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S13>/SourceBlock'
    Corneto_flight_program_contr_DW.obj_j.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_j.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_j.isInitialized = 1;
    Corneto_flight_program_contr_DW.obj_j.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(Corneto_flight_program_contr_DW.obj_j.orbMetadataObj,
                         &Corneto_flight_program_contr_DW.obj_j.eventStructObj);
    Corneto_flight_program_contr_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S15>/SourceBlock'
    Corneto_flight_program_contr_DW.obj_nc.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_nc.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_nc.isInitialized = 1;
    Corneto_flight_program_contr_DW.obj_nc.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(Corneto_flight_program_contr_DW.obj_nc.orbMetadataObj,
                         &Corneto_flight_program_contr_DW.obj_nc.eventStructObj);
    Corneto_flight_program_contr_DW.obj_nc.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/SourceBlock'
    Corneto_flight_program_contr_DW.obj_f.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_f.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_f.isInitialized = 1;
    Corneto_flight_program_contr_DW.obj_f.orbMetadataObj = ORB_ID
      (vehicle_local_position);
    uORB_read_initialize(Corneto_flight_program_contr_DW.obj_f.orbMetadataObj,
                         &Corneto_flight_program_contr_DW.obj_f.eventStructObj);
    Corneto_flight_program_contr_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Read Parameter'
    Corneto_flight_program_contr_DW.obj_b.matlabCodegenIsDeleted = true;
    Corneto_flight_program_contr_DW.obj_b.isInitialized = 0;
    Corneto_flight_program_contr_DW.obj_b.SampleTime = -1.0;
    Corneto_flight_program_contr_DW.obj_b.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_b.SampleTime =
      Corneto_flight_program_contro_P.ReadParameter_SampleTime;
    obj = &Corneto_flight_program_contr_DW.obj_b;
    Corneto_flight_program_contr_DW.obj_b.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      ParameterNameStr[i] = tmp[i];
    }

    ParameterNameStr[12] = '\x00';
    if (Corneto_flight_program_contr_DW.obj_b.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = Corneto_flight_program_contr_DW.obj_b.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr[0], true, sts * 1000.0);
    Corneto_flight_program_contr_DW.obj_b.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter'

    // Start for MATLABSystem: '<Root>/Read Parameter1'
    Corneto_flight_program_contr_DW.obj_l.matlabCodegenIsDeleted = true;
    Corneto_flight_program_contr_DW.obj_l.isInitialized = 0;
    Corneto_flight_program_contr_DW.obj_l.SampleTime = -1.0;
    Corneto_flight_program_contr_DW.obj_l.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_l.SampleTime =
      Corneto_flight_program_contro_P.ReadParameter1_SampleTime;
    obj = &Corneto_flight_program_contr_DW.obj_l;
    Corneto_flight_program_contr_DW.obj_l.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_l.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      ParameterNameStr_0[i] = tmp_0[i];
    }

    ParameterNameStr_0[14] = '\x00';
    if (Corneto_flight_program_contr_DW.obj_l.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = Corneto_flight_program_contr_DW.obj_l.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param(&ParameterNameStr_0[0], true, sts *
      1000.0);
    Corneto_flight_program_contr_DW.obj_l.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter1'

    // Start for MATLABSystem: '<Root>/Read Parameter2'
    Corneto_flight_program_contr_DW.obj_m.matlabCodegenIsDeleted = true;
    Corneto_flight_program_contr_DW.obj_m.isInitialized = 0;
    Corneto_flight_program_contr_DW.obj_m.SampleTime = -1.0;
    Corneto_flight_program_contr_DW.obj_m.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_m.SampleTime =
      Corneto_flight_program_contro_P.ReadParameter2_SampleTime;
    obj = &Corneto_flight_program_contr_DW.obj_m;
    Corneto_flight_program_contr_DW.obj_m.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      Corneto_flight_program_contro_B.ParameterNameStr[i] = tmp_1[i];
    }

    Corneto_flight_program_contro_B.ParameterNameStr[16] = '\x00';
    if (Corneto_flight_program_contr_DW.obj_m.SampleTime == -1.0) {
      sts = 0.2;
    } else {
      sts = Corneto_flight_program_contr_DW.obj_m.SampleTime;
    }

    obj->MW_PARAMHANDLE = MW_Init_Param
      (&Corneto_flight_program_contro_B.ParameterNameStr[0], true, sts * 1000.0);
    Corneto_flight_program_contr_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Read Parameter2'

    // Start for MATLABSystem: '<S7>/SinkBlock' incorporates:
    //   BusAssignment: '<Root>/Bus Assignment1'

    Corneto_flight_program_contr_DW.obj_o.matlabCodegenIsDeleted = false;
    Corneto_flight_program_contr_DW.obj_o.isSetupComplete = false;
    Corneto_flight_program_contr_DW.obj_o.isInitialized = 1;
    Corneto_flight_program_contr_DW.obj_o.orbMetadataObj = ORB_ID(debug_vect);
    uORB_write_initialize(Corneto_flight_program_contr_DW.obj_o.orbMetadataObj,
                          &Corneto_flight_program_contr_DW.obj_o.orbAdvertiseObj,
                          &Corneto_flight_program_contro_B.BusAssignment1_p, 1);
    Corneto_flight_program_contr_DW.obj_o.isSetupComplete = true;

    // Enable for Triggered SubSystem: '<S8>/Emulated Pixhawk'
    Corneto_flight_program_contr_DW.EmulatedPixhawk_RESET_ELAPS_T = true;

    // Enable for DiscreteIntegrator: '<S25>/Discrete-Time Integrator'
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

    // Enable for DiscreteIntegrator: '<S41>/Discrete-Time Integrator'
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_d = 1U;

    // Enable for DiscreteIntegrator: '<S46>/Discrete-Time Integrator'
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_e = 1U;

    // Enable for DiscreteIntegrator: '<S37>/Discrete-Time Integrator'
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTEM_k = 1U;

    // Enable for DiscreteIntegrator: '<S50>/Discrete-Time Integrator'
    Corneto_flight_program_contr_DW.DiscreteTimeIntegrator_SYSTE_es = 1U;

    // End of Enable for SubSystem: '<S8>/Emulated Pixhawk'
  }
}

// Model terminate function
void Corneto_flight_program_control_terminate(void)
{
  g_dsp_private_SlidingWindowAv_T *obj;
  uint16_T status;

  // Terminate for MATLABSystem: '<S71>/SinkBlock'
  if (!Corneto_flight_program_contr_DW.obj_lw.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_lw.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj_lw.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj_lw.isSetupComplete) {
      uORB_write_terminate
        (&Corneto_flight_program_contr_DW.obj_lw.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S71>/SinkBlock'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!Corneto_flight_program_contr_DW.obj_k.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj_k.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj_k.isSetupComplete) {
      uORB_read_terminate(&Corneto_flight_program_contr_DW.obj_k.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for MATLABSystem: '<S72>/SourceBlock'
  if (!Corneto_flight_program_contr_DW.obj_n.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj_n.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&Corneto_flight_program_contr_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S72>/SourceBlock'

  // Terminate for MATLABSystem: '<S13>/SourceBlock'
  if (!Corneto_flight_program_contr_DW.obj_j.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj_j.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&Corneto_flight_program_contr_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S13>/SourceBlock'

  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  if (!Corneto_flight_program_contr_DW.obj_nc.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_nc.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj_nc.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj_nc.isSetupComplete) {
      uORB_read_terminate(&Corneto_flight_program_contr_DW.obj_nc.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S15>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!Corneto_flight_program_contr_DW.obj_f.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj_f.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj_f.isSetupComplete) {
      uORB_read_terminate(&Corneto_flight_program_contr_DW.obj_f.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for Triggered SubSystem: '<S8>/Emulated Pixhawk'
  // Terminate for MATLABSystem: '<S28>/Moving Average1'
  if (!Corneto_flight_program_contr_DW.obj.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj.isSetupComplete) {
      obj = Corneto_flight_program_contr_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      Corneto_flight_program_contr_DW.obj.NumChannels = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<S28>/Moving Average1'

  // Terminate for MATLABSystem: '<S23>/PX4 PWM Output1'
  if (!Corneto_flight_program_contr_DW.obj_mo.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_mo.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj_mo.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj_mo.isSetupComplete) {
      status = pwm_disarm(&Corneto_flight_program_contr_DW.obj_mo.pwmDevHandler,
                          &Corneto_flight_program_contr_DW.obj_mo.armAdvertiseObj);
      Corneto_flight_program_contr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Corneto_flight_program_contr_DW.obj_mo.errorStatus | status);
      status = pwm_resetServo
        (&Corneto_flight_program_contr_DW.obj_mo.pwmDevHandler,
         Corneto_flight_program_contr_DW.obj_mo.servoCount,
         Corneto_flight_program_contr_DW.obj_mo.channelMask,
         Corneto_flight_program_contr_DW.obj_mo.isMain,
         &Corneto_flight_program_contr_DW.obj_mo.actuatorAdvertiseObj);
      Corneto_flight_program_contr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Corneto_flight_program_contr_DW.obj_mo.errorStatus | status);
      status = pwm_close(&Corneto_flight_program_contr_DW.obj_mo.pwmDevHandler,
                         &Corneto_flight_program_contr_DW.obj_mo.actuatorAdvertiseObj,
                         &Corneto_flight_program_contr_DW.obj_mo.armAdvertiseObj);
      Corneto_flight_program_contr_DW.obj_mo.errorStatus = static_cast<uint16_T>
        (Corneto_flight_program_contr_DW.obj_mo.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S23>/PX4 PWM Output1'
  // End of Terminate for SubSystem: '<S8>/Emulated Pixhawk'

  // Terminate for MATLABSystem: '<Root>/Read Parameter'
  if (!Corneto_flight_program_contr_DW.obj_b.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter'

  // Terminate for MATLABSystem: '<Root>/Read Parameter1'
  if (!Corneto_flight_program_contr_DW.obj_l.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter1'

  // Terminate for MATLABSystem: '<Root>/Read Parameter2'
  if (!Corneto_flight_program_contr_DW.obj_m.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Read Parameter2'

  // Terminate for MATLABSystem: '<S7>/SinkBlock'
  if (!Corneto_flight_program_contr_DW.obj_o.matlabCodegenIsDeleted) {
    Corneto_flight_program_contr_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Corneto_flight_program_contr_DW.obj_o.isInitialized == 1) &&
        Corneto_flight_program_contr_DW.obj_o.isSetupComplete) {
      uORB_write_terminate
        (&Corneto_flight_program_contr_DW.obj_o.orbAdvertiseObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SinkBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
