//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: px4demo_PWM.cpp
//
// Code generated for Simulink model 'px4demo_PWM'.
//
// Model version                  : 4.1
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  9 19:41:22 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "px4demo_PWM.h"
#include "px4demo_PWM_private.h"

// Block signals (default storage)
B_px4demo_PWM_T px4demo_PWM_B;

// Block states (default storage)
DW_px4demo_PWM_T px4demo_PWM_DW;

// Real-time model
RT_MODEL_px4demo_PWM_T px4demo_PWM_M_ = RT_MODEL_px4demo_PWM_T();
RT_MODEL_px4demo_PWM_T *const px4demo_PWM_M = &px4demo_PWM_M_;

// Forward declaration for local functions
static void px4demo_PWM_SystemCore_setup(px4_internal_block_PWM_px4dem_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void px4demo_PWM_SystemCore_setup_m(px4_internal_block_PWM_px4dem_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void px4demo_PWM_SystemCore_setup(px4_internal_block_PWM_px4dem_T *obj,
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
  obj->channelMask = 3;
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

static void px4demo_PWM_SystemCore_setup_m(px4_internal_block_PWM_px4dem_T *obj,
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
void px4demo_PWM_step(void)
{
  int32_T i;
  uint16_T pwmValue[8];
  uint16_T status;

  // MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/MAIN PWM Ch 1,2 value'
  //   Constant: '<Root>/failsafe'

  for (i = 0; i < 8; i++) {
    pwmValue[i] = 0U;
  }

  pwmValue[0] = px4demo_PWM_P.MAINPWMCh12value_Value;
  pwmValue[1] = px4demo_PWM_P.MAINPWMCh12value_Value;
  if (px4demo_PWM_P.ARMPWM_Value) {
    if (!px4demo_PWM_DW.obj_i.isArmed) {
      px4demo_PWM_DW.obj_i.isArmed = true;
      status = pwm_arm(&px4demo_PWM_DW.obj_i.pwmDevHandler,
                       &px4demo_PWM_DW.obj_i.armAdvertiseObj);
      px4demo_PWM_DW.obj_i.errorStatus = static_cast<uint16_T>
        (px4demo_PWM_DW.obj_i.errorStatus | status);
    }

    status = pwm_setServo(&px4demo_PWM_DW.obj_i.pwmDevHandler,
                          px4demo_PWM_DW.obj_i.servoCount,
                          px4demo_PWM_DW.obj_i.channelMask, &pwmValue[0],
                          px4demo_PWM_DW.obj_i.isMain,
                          &px4demo_PWM_DW.obj_i.actuatorAdvertiseObj);
    px4demo_PWM_DW.obj_i.errorStatus = static_cast<uint16_T>
      (px4demo_PWM_DW.obj_i.errorStatus | status);
  } else {
    status = pwm_disarm(&px4demo_PWM_DW.obj_i.pwmDevHandler,
                        &px4demo_PWM_DW.obj_i.armAdvertiseObj);
    px4demo_PWM_DW.obj_i.errorStatus = static_cast<uint16_T>
      (px4demo_PWM_DW.obj_i.errorStatus | status);
    px4demo_PWM_DW.obj_i.isArmed = false;
    status = pwm_resetServo(&px4demo_PWM_DW.obj_i.pwmDevHandler,
      px4demo_PWM_DW.obj_i.servoCount, px4demo_PWM_DW.obj_i.channelMask,
      px4demo_PWM_DW.obj_i.isMain, &px4demo_PWM_DW.obj_i.actuatorAdvertiseObj);
    px4demo_PWM_DW.obj_i.errorStatus = static_cast<uint16_T>
      (px4demo_PWM_DW.obj_i.errorStatus | status);
  }

  if (px4demo_PWM_DW.obj_i.isMain) {
    status = pwm_forceFailsafe(&px4demo_PWM_DW.obj_i.pwmDevHandler, static_cast<
      int32_T>(px4demo_PWM_P.failsafe_Value));
    px4demo_PWM_DW.obj_i.errorStatus = static_cast<uint16_T>
      (px4demo_PWM_DW.obj_i.errorStatus | status);
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output'

  // MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/AUX PWM Ch 1,2,3,4 value'
  //   Constant: '<Root>/failsafe1'

  for (i = 0; i < 8; i++) {
    pwmValue[i] = 0U;
  }

  pwmValue[0] = px4demo_PWM_P.AUXPWMCh1234value_Value;
  pwmValue[1] = px4demo_PWM_P.AUXPWMCh1234value_Value;
  pwmValue[2] = px4demo_PWM_P.AUXPWMCh1234value_Value;
  pwmValue[3] = px4demo_PWM_P.AUXPWMCh1234value_Value;
  if (px4demo_PWM_P.ARMPWM_Value) {
    if (!px4demo_PWM_DW.obj.isArmed) {
      px4demo_PWM_DW.obj.isArmed = true;
      status = pwm_arm(&px4demo_PWM_DW.obj.pwmDevHandler,
                       &px4demo_PWM_DW.obj.armAdvertiseObj);
      px4demo_PWM_DW.obj.errorStatus = static_cast<uint16_T>
        (px4demo_PWM_DW.obj.errorStatus | status);
    }

    status = pwm_setServo(&px4demo_PWM_DW.obj.pwmDevHandler,
                          px4demo_PWM_DW.obj.servoCount,
                          px4demo_PWM_DW.obj.channelMask, &pwmValue[0],
                          px4demo_PWM_DW.obj.isMain,
                          &px4demo_PWM_DW.obj.actuatorAdvertiseObj);
    px4demo_PWM_DW.obj.errorStatus = static_cast<uint16_T>
      (px4demo_PWM_DW.obj.errorStatus | status);
  } else {
    status = pwm_disarm(&px4demo_PWM_DW.obj.pwmDevHandler,
                        &px4demo_PWM_DW.obj.armAdvertiseObj);
    px4demo_PWM_DW.obj.errorStatus = static_cast<uint16_T>
      (px4demo_PWM_DW.obj.errorStatus | status);
    px4demo_PWM_DW.obj.isArmed = false;
    status = pwm_resetServo(&px4demo_PWM_DW.obj.pwmDevHandler,
      px4demo_PWM_DW.obj.servoCount, px4demo_PWM_DW.obj.channelMask,
      px4demo_PWM_DW.obj.isMain, &px4demo_PWM_DW.obj.actuatorAdvertiseObj);
    px4demo_PWM_DW.obj.errorStatus = static_cast<uint16_T>
      (px4demo_PWM_DW.obj.errorStatus | status);
  }

  if (px4demo_PWM_DW.obj.isMain) {
    status = pwm_forceFailsafe(&px4demo_PWM_DW.obj.pwmDevHandler,
      static_cast<int32_T>(px4demo_PWM_P.failsafe1_Value));
    px4demo_PWM_DW.obj.errorStatus = static_cast<uint16_T>
      (px4demo_PWM_DW.obj.errorStatus | status);
  }

  // End of MATLABSystem: '<Root>/PX4 PWM Output1'

  // MATLABSystem: '<S1>/SourceBlock'
  uORB_read_step(px4demo_PWM_DW.obj_l.orbMetadataObj,
                 &px4demo_PWM_DW.obj_l.eventStructObj,
                 &px4demo_PWM_B.b_varargout_2, false, 1.0);
}

// Model initialize function
void px4demo_PWM_initialize(void)
{
  // Registration code

  // states (dwork)
  (void) memset(static_cast<void *>(&px4demo_PWM_DW), 0,
                sizeof(DW_px4demo_PWM_T));

  // Start for MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/failsafe'

  px4demo_PWM_DW.obj_i.errorStatus = 0U;
  px4demo_PWM_DW.obj_i.isInitialized = 0;
  px4demo_PWM_DW.obj_i.matlabCodegenIsDeleted = false;
  px4demo_PWM_SystemCore_setup(&px4demo_PWM_DW.obj_i, px4demo_PWM_P.ARMPWM_Value,
    px4demo_PWM_P.failsafe_Value);

  // Start for MATLABSystem: '<Root>/PX4 PWM Output1' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/failsafe1'

  px4demo_PWM_DW.obj.errorStatus = 0U;
  px4demo_PWM_DW.obj.isInitialized = 0;
  px4demo_PWM_DW.obj.matlabCodegenIsDeleted = false;
  px4demo_PWM_SystemCore_setup_m(&px4demo_PWM_DW.obj, px4demo_PWM_P.ARMPWM_Value,
    px4demo_PWM_P.failsafe1_Value);

  // Start for MATLABSystem: '<S1>/SourceBlock'
  px4demo_PWM_DW.obj_l.matlabCodegenIsDeleted = false;
  px4demo_PWM_DW.obj_l.isSetupComplete = false;
  px4demo_PWM_DW.obj_l.isInitialized = 1;
  px4demo_PWM_DW.obj_l.orbMetadataObj = ORB_ID(actuator_outputs);
  uORB_read_initialize(px4demo_PWM_DW.obj_l.orbMetadataObj,
                       &px4demo_PWM_DW.obj_l.eventStructObj);
  px4demo_PWM_DW.obj_l.isSetupComplete = true;
}

// Model terminate function
void px4demo_PWM_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  if (!px4demo_PWM_DW.obj_i.matlabCodegenIsDeleted) {
    px4demo_PWM_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((px4demo_PWM_DW.obj_i.isInitialized == 1) &&
        px4demo_PWM_DW.obj_i.isSetupComplete) {
      status = pwm_disarm(&px4demo_PWM_DW.obj_i.pwmDevHandler,
                          &px4demo_PWM_DW.obj_i.armAdvertiseObj);
      px4demo_PWM_DW.obj_i.errorStatus = static_cast<uint16_T>
        (px4demo_PWM_DW.obj_i.errorStatus | status);
      status = pwm_resetServo(&px4demo_PWM_DW.obj_i.pwmDevHandler,
        px4demo_PWM_DW.obj_i.servoCount, px4demo_PWM_DW.obj_i.channelMask,
        px4demo_PWM_DW.obj_i.isMain, &px4demo_PWM_DW.obj_i.actuatorAdvertiseObj);
      px4demo_PWM_DW.obj_i.errorStatus = static_cast<uint16_T>
        (px4demo_PWM_DW.obj_i.errorStatus | status);
      status = pwm_close(&px4demo_PWM_DW.obj_i.pwmDevHandler,
                         &px4demo_PWM_DW.obj_i.actuatorAdvertiseObj,
                         &px4demo_PWM_DW.obj_i.armAdvertiseObj);
      px4demo_PWM_DW.obj_i.errorStatus = static_cast<uint16_T>
        (px4demo_PWM_DW.obj_i.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output'

  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'
  if (!px4demo_PWM_DW.obj.matlabCodegenIsDeleted) {
    px4demo_PWM_DW.obj.matlabCodegenIsDeleted = true;
    if ((px4demo_PWM_DW.obj.isInitialized == 1) &&
        px4demo_PWM_DW.obj.isSetupComplete) {
      status = pwm_disarm(&px4demo_PWM_DW.obj.pwmDevHandler,
                          &px4demo_PWM_DW.obj.armAdvertiseObj);
      px4demo_PWM_DW.obj.errorStatus = static_cast<uint16_T>
        (px4demo_PWM_DW.obj.errorStatus | status);
      status = pwm_resetServo(&px4demo_PWM_DW.obj.pwmDevHandler,
        px4demo_PWM_DW.obj.servoCount, px4demo_PWM_DW.obj.channelMask,
        px4demo_PWM_DW.obj.isMain, &px4demo_PWM_DW.obj.actuatorAdvertiseObj);
      px4demo_PWM_DW.obj.errorStatus = static_cast<uint16_T>
        (px4demo_PWM_DW.obj.errorStatus | status);
      status = pwm_close(&px4demo_PWM_DW.obj.pwmDevHandler,
                         &px4demo_PWM_DW.obj.actuatorAdvertiseObj,
                         &px4demo_PWM_DW.obj.armAdvertiseObj);
      px4demo_PWM_DW.obj.errorStatus = static_cast<uint16_T>
        (px4demo_PWM_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output1'

  // Terminate for MATLABSystem: '<S1>/SourceBlock'
  if (!px4demo_PWM_DW.obj_l.matlabCodegenIsDeleted) {
    px4demo_PWM_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((px4demo_PWM_DW.obj_l.isInitialized == 1) &&
        px4demo_PWM_DW.obj_l.isSetupComplete) {
      uORB_read_terminate(&px4demo_PWM_DW.obj_l.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S1>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
