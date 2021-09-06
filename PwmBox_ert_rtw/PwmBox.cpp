//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: PwmBox.cpp
//
// Code generated for Simulink model 'PwmBox'.
//
// Model version                  : 4.49
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon May 10 16:59:57 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "PwmBox.h"
#include "PwmBox_private.h"

// Block states (default storage)
DW_PwmBox_T PwmBox_DW;

// Previous zero-crossings (trigger) states
PrevZCX_PwmBox_T PwmBox_PrevZCX;

// External inputs (root inport signals with default storage)
ExtU_PwmBox_T PwmBox_U;

// External outputs (root outports fed by signals with default storage)
ExtY_PwmBox_T PwmBox_Y;

// Real-time model
RT_MODEL_PwmBox_T PwmBox_M_ = RT_MODEL_PwmBox_T();
RT_MODEL_PwmBox_T *const PwmBox_M = &PwmBox_M_;

// Forward declaration for local functions
static void PwmBox_SystemCore_setup(px4_internal_block_PWM_PwmBox_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void PwmBox_SystemCore_setup(px4_internal_block_PWM_PwmBox_T *obj,
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
void PwmBox_step(void)
{
  real_T rtb_u00Hz;
  int32_T i;
  real32_T rtb_siB_cmd[4];
  real32_T u0;
  uint16_T pwmValue[8];
  uint16_T status;
  ZCEventType zcEvent;

  // DiscretePulseGenerator: '<S1>/100 Hz'
  rtb_u00Hz = (PwmBox_DW.clockTickCounter < PwmBox_P.u00Hz_Duty) &&
    (PwmBox_DW.clockTickCounter >= 0) ? PwmBox_P.u00Hz_Amp : 0.0;
  if (PwmBox_DW.clockTickCounter >= PwmBox_P.u00Hz_Period - 1.0) {
    PwmBox_DW.clockTickCounter = 0;
  } else {
    PwmBox_DW.clockTickCounter++;
  }

  // End of DiscretePulseGenerator: '<S1>/100 Hz'

  // Outputs for Triggered SubSystem: '<S1>/Emulated Pixhawk' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &PwmBox_PrevZCX.EmulatedPixhawk_Trig_ZCE,
                     (rtb_u00Hz));
  if (zcEvent != NO_ZCEVENT) {
    // Product: '<S5>/Product' incorporates:
    //   Constant: '<S3>/Constant'
    //   Constant: '<S3>/Constant1'
    //   Constant: '<S5>/Constant7'
    //   DataTypeConversion: '<S5>/Cast To Single1'
    //   Inport: '<Root>/Serial In'

    for (i = 0; i < 4; i++) {
      rtb_siB_cmd[i] = PwmBox_P.Constant7_Value[i + 8] * static_cast<real32_T>
        (PwmBox_P.Constant1_Value) + (PwmBox_P.Constant7_Value[i + 4] *
        static_cast<real32_T>(PwmBox_P.Constant_Value) +
        PwmBox_P.Constant7_Value[i] * static_cast<real32_T>(PwmBox_U.SerialIn));
    }

    // End of Product: '<S5>/Product'

    // Gain: '<S6>/Gain'
    u0 = PwmBox_P.Gain_Gain * rtb_siB_cmd[0];

    // Saturate: '<S4>/Saturation'
    if (u0 > PwmBox_P.Saturation_UpperSat) {
      u0 = PwmBox_P.Saturation_UpperSat;
    } else if (u0 < PwmBox_P.Saturation_LowerSat) {
      u0 = PwmBox_P.Saturation_LowerSat;
    }

    // End of Saturate: '<S4>/Saturation'

    // DataTypeConversion: '<S4>/Cast To Double' incorporates:
    //   Constant: '<S4>/One'
    //   Gain: '<S4>/Gain'
    //   Sum: '<S4>/Add'

    u0 = static_cast<real32_T>(floor(static_cast<real_T>(PwmBox_P.Gain_Gain_g *
      u0 + PwmBox_P.One_Value)));
    if (rtIsNaNF(u0) || rtIsInfF(u0)) {
      u0 = 0.0F;
    } else {
      u0 = static_cast<real32_T>(fmod(static_cast<real_T>(u0), 65536.0));
    }

    // Outport: '<Root>/signal1' incorporates:
    //   DataTypeConversion: '<S4>/Cast To Double'

    PwmBox_Y.signal1 = static_cast<uint16_T>(u0 < 0.0F ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-u0)))) :
      static_cast<int32_T>(static_cast<uint16_T>(u0)));

    // Gain: '<S7>/Gain'
    u0 = PwmBox_P.Gain_Gain_i * rtb_siB_cmd[1];

    // Saturate: '<S4>/Saturation1'
    if (u0 > PwmBox_P.Saturation1_UpperSat) {
      u0 = PwmBox_P.Saturation1_UpperSat;
    } else if (u0 < PwmBox_P.Saturation1_LowerSat) {
      u0 = PwmBox_P.Saturation1_LowerSat;
    }

    // End of Saturate: '<S4>/Saturation1'

    // DataTypeConversion: '<S4>/Cast To Double1' incorporates:
    //   Constant: '<S4>/One1'
    //   Gain: '<S4>/Gain1'
    //   Sum: '<S4>/Add1'

    u0 = static_cast<real32_T>(floor(static_cast<real_T>(PwmBox_P.Gain1_Gain *
      u0 + PwmBox_P.One1_Value)));
    if (rtIsNaNF(u0) || rtIsInfF(u0)) {
      u0 = 0.0F;
    } else {
      u0 = static_cast<real32_T>(fmod(static_cast<real_T>(u0), 65536.0));
    }

    // Outport: '<Root>/signal2' incorporates:
    //   DataTypeConversion: '<S4>/Cast To Double1'

    PwmBox_Y.signal2 = static_cast<uint16_T>(u0 < 0.0F ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-u0)))) :
      static_cast<int32_T>(static_cast<uint16_T>(u0)));

    // Gain: '<S8>/Gain'
    u0 = PwmBox_P.Gain_Gain_j * rtb_siB_cmd[2];

    // Saturate: '<S4>/Saturation2'
    if (u0 > PwmBox_P.Saturation2_UpperSat) {
      u0 = PwmBox_P.Saturation2_UpperSat;
    } else if (u0 < PwmBox_P.Saturation2_LowerSat) {
      u0 = PwmBox_P.Saturation2_LowerSat;
    }

    // End of Saturate: '<S4>/Saturation2'

    // DataTypeConversion: '<S4>/Cast To Double2' incorporates:
    //   Constant: '<S4>/One2'
    //   Gain: '<S4>/Gain2'
    //   Sum: '<S4>/Add2'

    u0 = static_cast<real32_T>(floor(static_cast<real_T>(PwmBox_P.Gain2_Gain *
      u0 + PwmBox_P.One2_Value)));
    if (rtIsNaNF(u0) || rtIsInfF(u0)) {
      u0 = 0.0F;
    } else {
      u0 = static_cast<real32_T>(fmod(static_cast<real_T>(u0), 65536.0));
    }

    // Outport: '<Root>/signal3' incorporates:
    //   DataTypeConversion: '<S4>/Cast To Double2'

    PwmBox_Y.signal3 = static_cast<uint16_T>(u0 < 0.0F ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-u0)))) :
      static_cast<int32_T>(static_cast<uint16_T>(u0)));

    // Gain: '<S9>/Gain'
    u0 = PwmBox_P.Gain_Gain_o * rtb_siB_cmd[3];

    // Saturate: '<S4>/Saturation3'
    if (u0 > PwmBox_P.Saturation3_UpperSat) {
      u0 = PwmBox_P.Saturation3_UpperSat;
    } else if (u0 < PwmBox_P.Saturation3_LowerSat) {
      u0 = PwmBox_P.Saturation3_LowerSat;
    }

    // End of Saturate: '<S4>/Saturation3'

    // DataTypeConversion: '<S4>/Cast To Double3' incorporates:
    //   Constant: '<S4>/One3'
    //   Gain: '<S4>/Gain3'
    //   Sum: '<S4>/Add3'

    u0 = static_cast<real32_T>(floor(static_cast<real_T>(PwmBox_P.Gain3_Gain *
      u0 + PwmBox_P.One3_Value)));
    if (rtIsNaNF(u0) || rtIsInfF(u0)) {
      u0 = 0.0F;
    } else {
      u0 = static_cast<real32_T>(fmod(static_cast<real_T>(u0), 65536.0));
    }

    // Outport: '<Root>/signal4' incorporates:
    //   DataTypeConversion: '<S4>/Cast To Double3'

    PwmBox_Y.signal4 = static_cast<uint16_T>(u0 < 0.0F ? static_cast<int32_T>(
      static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>(-u0)))) :
      static_cast<int32_T>(static_cast<uint16_T>(u0)));

    // MATLABSystem: '<S4>/PX4 PWM Output1' incorporates:
    //   Constant: '<S4>/One4'
    //   Constant: '<S4>/One7'
    //   Outport: '<Root>/signal1'
    //   Outport: '<Root>/signal2'
    //   Outport: '<Root>/signal3'
    //   Outport: '<Root>/signal4'

    for (i = 0; i < 8; i++) {
      pwmValue[i] = 0U;
    }

    pwmValue[0] = PwmBox_Y.signal1;
    pwmValue[1] = PwmBox_Y.signal2;
    pwmValue[2] = PwmBox_Y.signal3;
    pwmValue[3] = PwmBox_Y.signal4;
    if (PwmBox_P.One7_Value) {
      if (!PwmBox_DW.obj.isArmed) {
        PwmBox_DW.obj.isArmed = true;
        status = pwm_arm(&PwmBox_DW.obj.pwmDevHandler,
                         &PwmBox_DW.obj.armAdvertiseObj);
        PwmBox_DW.obj.errorStatus = static_cast<uint16_T>
          (PwmBox_DW.obj.errorStatus | status);
      }

      status = pwm_setServo(&PwmBox_DW.obj.pwmDevHandler,
                            PwmBox_DW.obj.servoCount, PwmBox_DW.obj.channelMask,
                            &pwmValue[0], PwmBox_DW.obj.isMain,
                            &PwmBox_DW.obj.actuatorAdvertiseObj);
      PwmBox_DW.obj.errorStatus = static_cast<uint16_T>
        (PwmBox_DW.obj.errorStatus | status);
    } else {
      status = pwm_disarm(&PwmBox_DW.obj.pwmDevHandler,
                          &PwmBox_DW.obj.armAdvertiseObj);
      PwmBox_DW.obj.errorStatus = static_cast<uint16_T>
        (PwmBox_DW.obj.errorStatus | status);
      PwmBox_DW.obj.isArmed = false;
      status = pwm_resetServo(&PwmBox_DW.obj.pwmDevHandler,
        PwmBox_DW.obj.servoCount, PwmBox_DW.obj.channelMask,
        PwmBox_DW.obj.isMain, &PwmBox_DW.obj.actuatorAdvertiseObj);
      PwmBox_DW.obj.errorStatus = static_cast<uint16_T>
        (PwmBox_DW.obj.errorStatus | status);
    }

    if (PwmBox_DW.obj.isMain) {
      status = pwm_forceFailsafe(&PwmBox_DW.obj.pwmDevHandler,
        static_cast<int32_T>(PwmBox_P.One4_Value));
      PwmBox_DW.obj.errorStatus = static_cast<uint16_T>
        (PwmBox_DW.obj.errorStatus | status);
    }

    // End of MATLABSystem: '<S4>/PX4 PWM Output1'
  }

  // End of Outputs for SubSystem: '<S1>/Emulated Pixhawk'
}

// Model initialize function
void PwmBox_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  PwmBox_PrevZCX.EmulatedPixhawk_Trig_ZCE = UNINITIALIZED_ZCSIG;

  // SystemInitialize for Triggered SubSystem: '<S1>/Emulated Pixhawk'
  // Start for MATLABSystem: '<S4>/PX4 PWM Output1' incorporates:
  //   Constant: '<S4>/One4'
  //   Constant: '<S4>/One7'

  PwmBox_DW.obj.errorStatus = 0U;
  PwmBox_DW.obj.isInitialized = 0;
  PwmBox_DW.obj.matlabCodegenIsDeleted = false;
  PwmBox_SystemCore_setup(&PwmBox_DW.obj, PwmBox_P.One7_Value,
    PwmBox_P.One4_Value);

  // SystemInitialize for Outport: '<Root>/signal1' incorporates:
  //   Outport: '<S2>/PWM'

  PwmBox_Y.signal1 = PwmBox_P.PWM_Y0.signal1;

  // SystemInitialize for Outport: '<Root>/signal2' incorporates:
  //   Outport: '<S2>/PWM'

  PwmBox_Y.signal2 = PwmBox_P.PWM_Y0.signal2;

  // SystemInitialize for Outport: '<Root>/signal3' incorporates:
  //   Outport: '<S2>/PWM'

  PwmBox_Y.signal3 = PwmBox_P.PWM_Y0.signal3;

  // SystemInitialize for Outport: '<Root>/signal4' incorporates:
  //   Outport: '<S2>/PWM'

  PwmBox_Y.signal4 = PwmBox_P.PWM_Y0.signal4;

  // End of SystemInitialize for SubSystem: '<S1>/Emulated Pixhawk'
}

// Model terminate function
void PwmBox_terminate(void)
{
  uint16_T status;

  // Terminate for Triggered SubSystem: '<S1>/Emulated Pixhawk'
  // Terminate for MATLABSystem: '<S4>/PX4 PWM Output1'
  if (!PwmBox_DW.obj.matlabCodegenIsDeleted) {
    PwmBox_DW.obj.matlabCodegenIsDeleted = true;
    if ((PwmBox_DW.obj.isInitialized == 1) && PwmBox_DW.obj.isSetupComplete) {
      status = pwm_disarm(&PwmBox_DW.obj.pwmDevHandler,
                          &PwmBox_DW.obj.armAdvertiseObj);
      PwmBox_DW.obj.errorStatus = static_cast<uint16_T>
        (PwmBox_DW.obj.errorStatus | status);
      status = pwm_resetServo(&PwmBox_DW.obj.pwmDevHandler,
        PwmBox_DW.obj.servoCount, PwmBox_DW.obj.channelMask,
        PwmBox_DW.obj.isMain, &PwmBox_DW.obj.actuatorAdvertiseObj);
      PwmBox_DW.obj.errorStatus = static_cast<uint16_T>
        (PwmBox_DW.obj.errorStatus | status);
      status = pwm_close(&PwmBox_DW.obj.pwmDevHandler,
                         &PwmBox_DW.obj.actuatorAdvertiseObj,
                         &PwmBox_DW.obj.armAdvertiseObj);
      PwmBox_DW.obj.errorStatus = static_cast<uint16_T>
        (PwmBox_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/PX4 PWM Output1'
  // End of Terminate for SubSystem: '<S1>/Emulated Pixhawk'
}

//
// File trailer for generated code.
//
// [EOF]
//
