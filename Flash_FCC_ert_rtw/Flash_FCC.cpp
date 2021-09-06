//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: Flash_FCC.cpp
//
// Code generated for Simulink model 'Flash_FCC'.
//
// Model version                  : 1.411
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Feb 18 16:35:37 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "Flash_FCC.h"
#include "Flash_FCC_private.h"

// Block signals (default storage)
B_Flash_FCC_T Flash_FCC_B;

// Block states (default storage)
DW_Flash_FCC_T Flash_FCC_DW;

// Previous zero-crossings (trigger) states
PrevZCX_Flash_FCC_T Flash_FCC_PrevZCX;

// Real-time model
RT_MODEL_Flash_FCC_T Flash_FCC_M_ = RT_MODEL_Flash_FCC_T();
RT_MODEL_Flash_FCC_T *const Flash_FCC_M = &Flash_FCC_M_;

// Forward declaration for local functions
static void Flash_FC_SystemCore_release_fhm(const
  px4_internal_block_PX4SCIRead_T *obj);
static void Flash_FCC_SystemCore_delete_fhm(const
  px4_internal_block_PX4SCIRead_T *obj);
static void matlabCodegenHandle_matlabC_fhm(px4_internal_block_PX4SCIRead_T *obj);
static void Flash_FCC_SystemCore_release_f(const px4_internal_block_Subscriber_T
  *obj);
static void Flash_FCC_SystemCore_delete_f(const px4_internal_block_Subscriber_T *
  obj);
static void matlabCodegenHandle_matlabCod_f(px4_internal_block_Subscriber_T *obj);
static void Flash_FCC_SystemCore_release_fh(px4_internal_block_PWM_Flash__T *obj);
static void Flash_FCC_SystemCore_delete_fh(px4_internal_block_PWM_Flash__T *obj);
static void matlabCodegenHandle_matlabCo_fh(px4_internal_block_PWM_Flash__T *obj);
static void Flash_FCC_SystemCore_release(const px4_internal_block_PX4SCIWrit_T
  *obj);
static void Flash_FCC_SystemCore_delete(const px4_internal_block_PX4SCIWrit_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIWrit_T *obj);
static void Flash_FCC_SystemCore_setup_fh(px4_internal_block_PX4SCIRead_T *obj);
static void Flash_FCC_SystemCore_setup_f(px4_internal_block_PWM_Flash__T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
static void Flash_FCC_SystemCore_setup(px4_internal_block_PX4SCIWrit_T *obj);
static void rate_scheduler(void);

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

  (Flash_FCC_M->Timing.TaskCounters.TID[1])++;
  if ((Flash_FCC_M->Timing.TaskCounters.TID[1]) > 4) {// Sample time: [0.005s, 0.0s] 
    Flash_FCC_M->Timing.TaskCounters.TID[1] = 0;
  }
}

//
// Output and update for action system:
//    '<S14>/If Action Subsystem'
//    '<S14>/If Action Subsystem1'
//
void Flash_FCC_IfActionSubsystem(real32_T *rty_Out1,
  P_IfActionSubsystem_Flash_FCC_T *localP)
{
  // SignalConversion generated from: '<S15>/Out1' incorporates:
  //   Constant: '<S15>/One'

  *rty_Out1 = localP->One_Value;
}

static void Flash_FC_SystemCore_release_fhm(const
  px4_internal_block_PX4SCIRead_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Flash_FCC_SystemCore_delete_fhm(const
  px4_internal_block_PX4SCIRead_T *obj)
{
  Flash_FC_SystemCore_release_fhm(obj);
}

static void matlabCodegenHandle_matlabC_fhm(px4_internal_block_PX4SCIRead_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Flash_FCC_SystemCore_delete_fhm(obj);
  }
}

static void Flash_FCC_SystemCore_release_f(const px4_internal_block_Subscriber_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    uORB_read_terminate(&obj->eventStructObj);
  }
}

static void Flash_FCC_SystemCore_delete_f(const px4_internal_block_Subscriber_T *
  obj)
{
  Flash_FCC_SystemCore_release_f(obj);
}

static void matlabCodegenHandle_matlabCod_f(px4_internal_block_Subscriber_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Flash_FCC_SystemCore_delete_f(obj);
  }
}

static void Flash_FCC_SystemCore_release_fh(px4_internal_block_PWM_Flash__T *obj)
{
  uint16_T status;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    status = pwm_disarm(&obj->pwmDevHandler);
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
    status = pwm_resetServo(&obj->pwmDevHandler, obj->servoCount,
      obj->channelMask, obj->isMain);
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
    status = pwm_close(&obj->pwmDevHandler);
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  }
}

static void Flash_FCC_SystemCore_delete_fh(px4_internal_block_PWM_Flash__T *obj)
{
  Flash_FCC_SystemCore_release_fh(obj);
}

static void matlabCodegenHandle_matlabCo_fh(px4_internal_block_PWM_Flash__T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Flash_FCC_SystemCore_delete_fh(obj);
  }
}

static void Flash_FCC_SystemCore_release(const px4_internal_block_PX4SCIWrit_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_SCI_Close(obj->MW_SCIHANDLE);
  }
}

static void Flash_FCC_SystemCore_delete(const px4_internal_block_PX4SCIWrit_T
  *obj)
{
  Flash_FCC_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(px4_internal_block_PX4SCIWrit_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Flash_FCC_SystemCore_delete(obj);
  }
}

static void Flash_FCC_SystemCore_setup_fh(px4_internal_block_PX4SCIRead_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  char_T SCIModuleLoc[13];
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_HardwareFlowControl_Type HardwareFlowControlValue;
  int32_T i;
  static const char_T tmp[12] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A',
    'C', 'M', '0' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  TxPinLoc = MW_UNDEFINED_VALUE;
  for (i = 0; i < 12; i++) {
    SCIModuleLoc[i] = tmp[i];
  }

  SCIModuleLoc[12] = '\x00';
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleLoc, true, RxPinLoc, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 9600U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  RxPinLoc = MW_UNDEFINED_VALUE;
  TxPinLoc = MW_UNDEFINED_VALUE;
  HardwareFlowControlValue = MW_SCI_FLOWCONTROL_RTS_CTS;
  MW_SCI_ConfigureHardwareFlowControl(obj->MW_SCIHANDLE,
    HardwareFlowControlValue, RxPinLoc, TxPinLoc);
  obj->isSetupComplete = true;
}

static void Flash_FCC_SystemCore_setup_f(px4_internal_block_PWM_Flash__T *obj,
  boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  uint16_T varargin_1_0;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->isMain = false;
  obj->pwmDevObj = MW_PWM_OUTPUT_AUX_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler);
    obj->isArmed = true;
  } else {
    status = pwm_disarm(&obj->pwmDevHandler);
    obj->isArmed = false;
  }

  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
  obj->channelMask = 15;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  varargin_1_0 = obj->errorStatus;
  obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, varargin_2);
    varargin_1_0 = obj->errorStatus;
    obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, false);
    varargin_1_0 = obj->errorStatus;
    obj->errorStatus = static_cast<uint16_T>(varargin_1_0 | status);
  }

  obj->isSetupComplete = true;
}

static void Flash_FCC_SystemCore_setup(px4_internal_block_PX4SCIWrit_T *obj)
{
  uint32_T RxPinLoc;
  uint32_T TxPinLoc;
  char_T SCIModuleLoc[13];
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  int32_T i;
  static const char_T tmp[12] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A',
    'C', 'M', '0' };

  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  TxPinLoc = MW_UNDEFINED_VALUE;
  for (i = 0; i < 12; i++) {
    SCIModuleLoc[i] = tmp[i];
  }

  SCIModuleLoc[12] = '\x00';
  obj->MW_SCIHANDLE = MW_SCI_Open(SCIModuleLoc, true, RxPinLoc, TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 9600U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

// Model step function
void Flash_FCC_step(void)
{
  uint8_T sizeptr;
  uint16_T status;
  real32_T rtb_Fin_4_Cmd_rad;
  real32_T rtb_Add3_a;
  real32_T rtb_Fin_3_Cmd_rad;
  real32_T rtb_Add16;
  real32_T rtb_Add3;
  real32_T rtb_Add2;
  real32_T rtb_Add1;
  real32_T rtb_u;
  ZCEventType zcEvent;
  real_T rtb_PulseGenerator1;
  boolean_T rtb_NOT;
  int32_T i;

  // MATLABSystem: '<S2>/Serial Receive'
  if (Flash_FCC_DW.obj.SampleTime != Flash_FCC_P.SerialReceive_SampleTime) {
    Flash_FCC_DW.obj.SampleTime = Flash_FCC_P.SerialReceive_SampleTime;
  }

  MW_SCI_GetDataBytesAvailable(Flash_FCC_DW.obj.MW_SCIHANDLE, false, &sizeptr, 5);
  if (sizeptr >= 92U) {
    MW_SCI_Receive(Flash_FCC_DW.obj.MW_SCIHANDLE, Flash_FCC_B.RxDataLocChar, 92U);
    memcpy((void *)&Flash_FCC_B.RxData[0], (void *)&Flash_FCC_B.RxDataLocChar[0],
           (uint32_T)((size_t)23 * sizeof(real32_T)));
    sizeptr = 0U;
  } else {
    memset(&Flash_FCC_B.RxData[0], 0, 23U * sizeof(real32_T));
    sizeptr = 1U;
  }

  // Logic: '<S2>/NOT' incorporates:
  //   MATLABSystem: '<S2>/Serial Receive'

  rtb_NOT = (sizeptr == 0);

  // Outputs for Triggered SubSystem: '<S2>/Triggered Subsystem' incorporates:
  //   TriggerPort: '<S31>/Trigger'

  if (rtb_NOT && (Flash_FCC_PrevZCX.TriggeredSubsystem_Trig_ZCE != POS_ZCSIG)) {
    // Inport: '<S31>/In1' incorporates:
    //   MATLABSystem: '<S2>/Serial Receive'

    memcpy(&Flash_FCC_B.In1_c[0], &Flash_FCC_B.RxData[0], 23U * sizeof(real32_T));
  }

  Flash_FCC_PrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_NOT;

  // End of Outputs for SubSystem: '<S2>/Triggered Subsystem'
  if (Flash_FCC_M->Timing.TaskCounters.TID[1] == 0) {
    // DiscretePulseGenerator: '<Root>/Pulse Generator1'
    rtb_PulseGenerator1 = (Flash_FCC_DW.clockTickCounter <
      Flash_FCC_P.PulseGenerator1_Duty) && (Flash_FCC_DW.clockTickCounter >= 0) ?
      Flash_FCC_P.PulseGenerator1_Amp : 0.0;
    if (Flash_FCC_DW.clockTickCounter >= Flash_FCC_P.PulseGenerator1_Period -
        1.0) {
      Flash_FCC_DW.clockTickCounter = 0;
    } else {
      Flash_FCC_DW.clockTickCounter++;
    }

    // End of DiscretePulseGenerator: '<Root>/Pulse Generator1'

    // Outputs for Triggered SubSystem: '<Root>/Pixhawk Software - 100 Hz' incorporates:
    //   TriggerPort: '<S1>/Trigger'

    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Flash_FCC_PrevZCX.PixhawkSoftware100Hz_Trig_ZCE,
                       (rtb_PulseGenerator1));
    if (zcEvent != NO_ZCEVENT) {
      // S-Function (any2byte): '<S25>/Byte Pack1' incorporates:
      //   Constant: '<S25>/Zero'


      // Pack: <S25>/Byte Pack1
      (void) memcpy(&Flash_FCC_B.VectorConcatenate1[0],
                    &Flash_FCC_P.Zero_Value_b[0],
                    3);

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_1_Threshold) {
        rtb_u = Flash_FCC_B.In1_c[4];
      } else {
        rtb_u = Flash_FCC_P.One_Value;
      }

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One1'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_2_Threshold) {
        rtb_Add3_a = Flash_FCC_B.In1_c[5];
      } else {
        rtb_Add3_a = Flash_FCC_P.One1_Value;
      }

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One2'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_3_Threshold) {
        rtb_Fin_3_Cmd_rad = Flash_FCC_B.In1_c[6];
      } else {
        rtb_Fin_3_Cmd_rad = Flash_FCC_P.One2_Value;
      }

      // If: '<S14>/If' incorporates:
      //   Math: '<S13>/Square'
      //   Math: '<S13>/Square1'
      //   Math: '<S13>/Square2'
      //   Sqrt: '<S13>/Square Root'
      //   Sum: '<S13>/Add'

      if (static_cast<real32_T>(sqrt(static_cast<real_T>((rtb_u * rtb_u +
              rtb_Add3_a * rtb_Add3_a) + rtb_Fin_3_Cmd_rad * rtb_Fin_3_Cmd_rad)))
          < 150.0F) {
        // Outputs for IfAction SubSystem: '<S14>/If Action Subsystem' incorporates:
        //   ActionPort: '<S15>/Action Port'

        Flash_FCC_IfActionSubsystem(&rtb_Fin_4_Cmd_rad,
          &Flash_FCC_P.IfActionSubsystem);

        // End of Outputs for SubSystem: '<S14>/If Action Subsystem'
      } else {
        // Outputs for IfAction SubSystem: '<S14>/If Action Subsystem1' incorporates:
        //   ActionPort: '<S16>/Action Port'

        Flash_FCC_IfActionSubsystem(&rtb_Fin_4_Cmd_rad,
          &Flash_FCC_P.IfActionSubsystem1);

        // End of Outputs for SubSystem: '<S14>/If Action Subsystem1'
      }

      // End of If: '<S14>/If'

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[10] = rtb_Fin_3_Cmd_rad;

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[9] = rtb_Add3_a;

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[8] = rtb_u;

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One9'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_10_Threshold) {
        rtb_Add3_a = Flash_FCC_B.In1_c[19];
      } else {
        rtb_Add3_a = Flash_FCC_P.One9_Value;
      }

      // RelationalOperator: '<S3>/GreaterThan' incorporates:
      //   Delay: '<S3>/Delay'

      rtb_NOT = (Flash_FCC_B.In1_c[1] < Flash_FCC_DW.Delay_DSTATE);

      // DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' incorporates:
      //   Sum: '<S14>/Sum'

      if (rtb_NOT && (Flash_FCC_PrevZCX.DiscreteTransferFcn_Reset_ZCE !=
                      POS_ZCSIG)) {
        Flash_FCC_DW.DiscreteTransferFcn_states =
          Flash_FCC_P.DiscreteTransferFcn_InitialStat;
      }

      Flash_FCC_PrevZCX.DiscreteTransferFcn_Reset_ZCE = rtb_NOT;
      rtb_u = ((Flash_FCC_B.In1_c[22] - rtb_Add3_a) -
               Flash_FCC_P.DiscreteTransferFcn_DenCoef[1] *
               Flash_FCC_DW.DiscreteTransferFcn_states) /
        Flash_FCC_P.DiscreteTransferFcn_DenCoef[0];

      // MATLABSystem: '<S22>/SourceBlock' incorporates:
      //   Inport: '<S23>/In1'

      rtb_NOT = uORB_read_step(Flash_FCC_DW.obj_o.orbMetadataObj,
        &Flash_FCC_DW.obj_o.eventStructObj, &Flash_FCC_B.b_varargout_2, false,
        1.0);

      // Outputs for Enabled SubSystem: '<S22>/Enabled Subsystem' incorporates:
      //   EnablePort: '<S23>/Enable'

      if (rtb_NOT) {
        Flash_FCC_B.In1 = Flash_FCC_B.b_varargout_2;
      }

      // End of MATLABSystem: '<S22>/SourceBlock'
      // End of Outputs for SubSystem: '<S22>/Enabled Subsystem'

      // Switch generated from: '<S12>/Switch'
      if (Flash_FCC_B.In1_c[3] > Flash_FCC_P.Switch_4_Threshold) {
        rtb_Add1 = Flash_FCC_B.In1.x;
      } else {
        rtb_Add1 = Flash_FCC_B.In1_c[16];
      }

      // End of Switch generated from: '<S12>/Switch'

      // Gain: '<S14>/Gain' incorporates:
      //   DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn'
      //   Gain: '<S14>/Gain2'
      //   Product: '<S14>/Product'
      //   Sum: '<S14>/Sum7'

      rtb_Fin_4_Cmd_rad = ((Flash_FCC_P.DiscreteTransferFcn_NumCoef[0] * rtb_u +
                            Flash_FCC_P.DiscreteTransferFcn_NumCoef[1] *
                            Flash_FCC_DW.DiscreteTransferFcn_states) *
                           Flash_FCC_P.Gain2_Gain * rtb_Fin_4_Cmd_rad - rtb_Add1)
        * Flash_FCC_P.Gain_Gain;

      // Saturate: '<S6>/Limit2maxDeflection'
      if (rtb_Fin_4_Cmd_rad > Flash_FCC_P.Limit2maxDeflection_UpperSat) {
        rtb_Fin_4_Cmd_rad = Flash_FCC_P.Limit2maxDeflection_UpperSat;
      } else {
        if (rtb_Fin_4_Cmd_rad < Flash_FCC_P.Limit2maxDeflection_LowerSat) {
          rtb_Fin_4_Cmd_rad = Flash_FCC_P.Limit2maxDeflection_LowerSat;
        }
      }

      // End of Saturate: '<S6>/Limit2maxDeflection'

      // Sum: '<S6>/Add4' incorporates:
      //   Constant: '<S6>/Constant'
      //   Sum: '<S6>/Add5'

      rtb_Fin_3_Cmd_rad = Flash_FCC_P.Constant_Value_m + rtb_Add3_a;

      // Sum: '<S6>/Add' incorporates:
      //   Constant: '<S4>/Zero'
      //   Fcn: '<S6>/Fcn'
      //   Fcn: '<S6>/Fcn1'
      //   Product: '<S6>/Multiply'
      //   Product: '<S6>/Multiply1'
      //   Sum: '<S6>/Add4'

      rtb_Fin_3_Cmd_rad = -static_cast<real32_T>(cos(static_cast<real_T>
        (rtb_Fin_3_Cmd_rad))) * Flash_FCC_P.Zero_Value + static_cast<real32_T>
        (sin(static_cast<real_T>(rtb_Fin_3_Cmd_rad))) * Flash_FCC_P.Zero_Value;

      // Sum: '<S6>/Add6' incorporates:
      //   Constant: '<S6>/Constant1'
      //   Sum: '<S6>/Add7'

      rtb_Add1 = Flash_FCC_P.Constant1_Value + rtb_Add3_a;

      // Sum: '<S6>/Add1' incorporates:
      //   Constant: '<S4>/Zero'
      //   Fcn: '<S6>/Fcn2'
      //   Fcn: '<S6>/Fcn3'
      //   Product: '<S6>/Multiply2'
      //   Product: '<S6>/Multiply3'
      //   Sum: '<S6>/Add6'

      rtb_Add1 = -static_cast<real32_T>(cos(static_cast<real_T>(rtb_Add1))) *
        Flash_FCC_P.Zero_Value + static_cast<real32_T>(sin(static_cast<real_T>
        (rtb_Add1))) * Flash_FCC_P.Zero_Value;

      // Sum: '<S6>/Add8' incorporates:
      //   Constant: '<S6>/Constant2'
      //   Sum: '<S6>/Add9'

      rtb_Add2 = Flash_FCC_P.Constant2_Value + rtb_Add3_a;

      // Sum: '<S6>/Add2' incorporates:
      //   Constant: '<S4>/Zero'
      //   Fcn: '<S6>/Fcn4'
      //   Fcn: '<S6>/Fcn5'
      //   Product: '<S6>/Multiply4'
      //   Product: '<S6>/Multiply5'
      //   Sum: '<S6>/Add8'

      rtb_Add2 = -static_cast<real32_T>(cos(static_cast<real_T>(rtb_Add2))) *
        Flash_FCC_P.Zero_Value + static_cast<real32_T>(sin(static_cast<real_T>
        (rtb_Add2))) * Flash_FCC_P.Zero_Value;

      // Sum: '<S6>/Add10' incorporates:
      //   Constant: '<S6>/Constant3'
      //   Sum: '<S6>/Add11'

      rtb_Add3_a += Flash_FCC_P.Constant3_Value;

      // Sum: '<S6>/Add3' incorporates:
      //   Constant: '<S4>/Zero'
      //   Fcn: '<S6>/Fcn6'
      //   Fcn: '<S6>/Fcn7'
      //   Product: '<S6>/Multiply6'
      //   Product: '<S6>/Multiply7'
      //   Sum: '<S6>/Add10'

      rtb_Add3 = -static_cast<real32_T>(cos(static_cast<real_T>(rtb_Add3_a))) *
        Flash_FCC_P.Zero_Value + static_cast<real32_T>(sin(static_cast<real_T>
        (rtb_Add3_a))) * Flash_FCC_P.Zero_Value;

      // Sum: '<S6>/Add16' incorporates:
      //   Abs: '<S6>/Abs'
      //   Constant: '<S6>/Constant4'

      rtb_Add16 = Flash_FCC_P.Constant4_Value - static_cast<real32_T>(fabs(
        static_cast<real_T>(rtb_Fin_4_Cmd_rad)));

      // Outputs for Enabled SubSystem: '<S17>/Pass' incorporates:
      //   EnablePort: '<S19>/Enable'

      // Outputs for Enabled SubSystem: '<S17>/Saturate' incorporates:
      //   EnablePort: '<S20>/Enable'

      // Logic: '<S17>/Logical Operator' incorporates:
      //   Abs: '<S18>/Abs'
      //   Abs: '<S18>/Abs1'
      //   Abs: '<S18>/Abs2'
      //   Abs: '<S18>/Abs3'
      //   Logic: '<S18>/OR'
      //   RelationalOperator: '<S18>/Relational Operator'
      //   RelationalOperator: '<S18>/Relational Operator1'
      //   RelationalOperator: '<S18>/Relational Operator2'
      //   RelationalOperator: '<S18>/Relational Operator3'

      if ((static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Fin_3_Cmd_rad))) >
           rtb_Add16) || (static_cast<real32_T>(fabs(static_cast<real_T>
             (rtb_Add1))) > rtb_Add16) || (static_cast<real32_T>(fabs(
             static_cast<real_T>(rtb_Add2))) > rtb_Add16) ||
          (static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Add3))) >
           rtb_Add16)) {
        // MinMax: '<S20>/Max'
        if ((rtb_Fin_3_Cmd_rad > rtb_Add1) || rtIsNaNF(rtb_Add1)) {
          rtb_Add3_a = rtb_Fin_3_Cmd_rad;
        } else {
          rtb_Add3_a = rtb_Add1;
        }

        if ((!(rtb_Add3_a > rtb_Add2)) && (!rtIsNaNF(rtb_Add2))) {
          rtb_Add3_a = rtb_Add2;
        }

        if ((!(rtb_Add3_a > rtb_Add3)) && (!rtIsNaNF(rtb_Add3))) {
          rtb_Add3_a = rtb_Add3;
        }

        // End of MinMax: '<S20>/Max'

        // Abs: '<S20>/Abs1'
        rtb_Add3_a = static_cast<real32_T>(fabs(static_cast<real_T>(rtb_Add3_a)));

        // Product: '<S20>/Multiply' incorporates:
        //   Product: '<S20>/Divide'

        rtb_Fin_3_Cmd_rad = rtb_Fin_3_Cmd_rad / rtb_Add3_a * rtb_Add16;

        // Product: '<S20>/Multiply1' incorporates:
        //   Product: '<S20>/Divide1'

        rtb_Add1 = rtb_Add1 / rtb_Add3_a * rtb_Add16;

        // Product: '<S20>/Multiply3' incorporates:
        //   Product: '<S20>/Divide2'

        rtb_Add3 = rtb_Add3 / rtb_Add3_a * rtb_Add16;

        // Product: '<S20>/Multiply2' incorporates:
        //   Product: '<S20>/Divide4'

        rtb_Add2 = rtb_Add2 / rtb_Add3_a * rtb_Add16;
      }

      // End of Logic: '<S17>/Logical Operator'
      // End of Outputs for SubSystem: '<S17>/Saturate'
      // End of Outputs for SubSystem: '<S17>/Pass'

      // Sum: '<S6>/Add15'
      rtb_Add3_a = rtb_Fin_4_Cmd_rad + rtb_Fin_3_Cmd_rad;

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[1] = rtb_Add3_a;

      // Gain: '<S27>/Gain'
      rtb_Add3_a *= Flash_FCC_P.Gain_Gain_c;

      // Saturate: '<S11>/Saturation'
      if (rtb_Add3_a > Flash_FCC_P.Saturation_UpperSat) {
        rtb_Add3_a = Flash_FCC_P.Saturation_UpperSat;
      } else {
        if (rtb_Add3_a < Flash_FCC_P.Saturation_LowerSat) {
          rtb_Add3_a = Flash_FCC_P.Saturation_LowerSat;
        }
      }

      // End of Saturate: '<S11>/Saturation'

      // Gain: '<S11>/Gain'
      rtb_Add16 = Flash_FCC_P.Gain_Gain_g * rtb_Add3_a;

      // Sum: '<S6>/Add12'
      rtb_Add3_a = rtb_Fin_4_Cmd_rad + rtb_Add1;

      // Sum: '<S6>/Add13'
      rtb_Fin_3_Cmd_rad = rtb_Fin_4_Cmd_rad + rtb_Add2;

      // Sum: '<S6>/Add14'
      rtb_Fin_4_Cmd_rad += rtb_Add3;

      // MATLABSystem: '<S11>/PX4 PWM Output1' incorporates:
      //   Constant: '<S11>/One4'
      //   DataTypeConversion: '<S11>/Cast To Double'
      //   DataTypeConversion: '<S11>/Cast To Double1'
      //   DataTypeConversion: '<S11>/Cast To Double2'
      //   DataTypeConversion: '<S11>/Cast To Double3'
      //   Delay: '<S26>/Delay'
      //   Logic: '<S11>/AND'
      //   RelationalOperator: '<S26>/GreaterThan'

      if ((Flash_FCC_B.In1_c[0] != 0.0F) && (Flash_FCC_B.In1_c[1] >
           Flash_FCC_DW.Delay_DSTATE_n)) {
        if (!Flash_FCC_DW.obj_a.isArmed) {
          Flash_FCC_DW.obj_a.isArmed = true;
          status = pwm_arm(&Flash_FCC_DW.obj_a.pwmDevHandler);
          Flash_FCC_DW.obj_a.errorStatus = static_cast<uint16_T>
            (Flash_FCC_DW.obj_a.errorStatus | status);
        }

        for (i = 0; i < 8; i++) {
          Flash_FCC_B.pwmValue[i] = 0U;
        }

        // DataTypeConversion: '<S11>/Cast To Double' incorporates:
        //   Constant: '<S11>/One'
        //   Sum: '<S11>/Add'

        rtb_Add1 = static_cast<real32_T>(floor(static_cast<real_T>(rtb_Add16 +
          Flash_FCC_P.One_Value_m)));
        if (rtIsNaNF(rtb_Add1) || rtIsInfF(rtb_Add1)) {
          rtb_Add1 = 0.0F;
        } else {
          rtb_Add1 = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Add1),
            65536.0));
        }

        Flash_FCC_B.pwmValue[0] = static_cast<uint16_T>(rtb_Add1 < 0.0F ?
          static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>(-rtb_Add1)))) : static_cast<int32_T>(
          static_cast<uint16_T>(rtb_Add1)));

        // Gain: '<S28>/Gain' incorporates:
        //   DataTypeConversion: '<S11>/Cast To Double'

        rtb_Add1 = Flash_FCC_P.Gain_Gain_d * rtb_Add3_a;

        // Saturate: '<S11>/Saturation1'
        if (rtb_Add1 > Flash_FCC_P.Saturation1_UpperSat) {
          rtb_Add1 = Flash_FCC_P.Saturation1_UpperSat;
        } else {
          if (rtb_Add1 < Flash_FCC_P.Saturation1_LowerSat) {
            rtb_Add1 = Flash_FCC_P.Saturation1_LowerSat;
          }
        }

        // End of Saturate: '<S11>/Saturation1'

        // DataTypeConversion: '<S11>/Cast To Double1' incorporates:
        //   Constant: '<S11>/One1'
        //   Gain: '<S11>/Gain1'
        //   Sum: '<S11>/Add1'

        rtb_Add1 = static_cast<real32_T>(floor(static_cast<real_T>
          (Flash_FCC_P.Gain1_Gain * rtb_Add1 + Flash_FCC_P.One1_Value_e)));
        if (rtIsNaNF(rtb_Add1) || rtIsInfF(rtb_Add1)) {
          rtb_Add1 = 0.0F;
        } else {
          rtb_Add1 = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Add1),
            65536.0));
        }

        Flash_FCC_B.pwmValue[1] = static_cast<uint16_T>(rtb_Add1 < 0.0F ?
          static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>(-rtb_Add1)))) : static_cast<int32_T>(
          static_cast<uint16_T>(rtb_Add1)));

        // Gain: '<S29>/Gain' incorporates:
        //   DataTypeConversion: '<S11>/Cast To Double1'

        rtb_Add1 = Flash_FCC_P.Gain_Gain_f * rtb_Fin_3_Cmd_rad;

        // Saturate: '<S11>/Saturation2'
        if (rtb_Add1 > Flash_FCC_P.Saturation2_UpperSat) {
          rtb_Add1 = Flash_FCC_P.Saturation2_UpperSat;
        } else {
          if (rtb_Add1 < Flash_FCC_P.Saturation2_LowerSat) {
            rtb_Add1 = Flash_FCC_P.Saturation2_LowerSat;
          }
        }

        // End of Saturate: '<S11>/Saturation2'

        // DataTypeConversion: '<S11>/Cast To Double2' incorporates:
        //   Constant: '<S11>/One2'
        //   Gain: '<S11>/Gain2'
        //   Sum: '<S11>/Add2'

        rtb_Add1 = static_cast<real32_T>(floor(static_cast<real_T>
          (Flash_FCC_P.Gain2_Gain_h * rtb_Add1 + Flash_FCC_P.One2_Value_f)));
        if (rtIsNaNF(rtb_Add1) || rtIsInfF(rtb_Add1)) {
          rtb_Add1 = 0.0F;
        } else {
          rtb_Add1 = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Add1),
            65536.0));
        }

        Flash_FCC_B.pwmValue[2] = static_cast<uint16_T>(rtb_Add1 < 0.0F ?
          static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>(-rtb_Add1)))) : static_cast<int32_T>(
          static_cast<uint16_T>(rtb_Add1)));

        // Gain: '<S30>/Gain' incorporates:
        //   DataTypeConversion: '<S11>/Cast To Double2'

        rtb_Add1 = Flash_FCC_P.Gain_Gain_o * rtb_Fin_4_Cmd_rad;

        // Saturate: '<S11>/Saturation3'
        if (rtb_Add1 > Flash_FCC_P.Saturation3_UpperSat) {
          rtb_Add1 = Flash_FCC_P.Saturation3_UpperSat;
        } else {
          if (rtb_Add1 < Flash_FCC_P.Saturation3_LowerSat) {
            rtb_Add1 = Flash_FCC_P.Saturation3_LowerSat;
          }
        }

        // End of Saturate: '<S11>/Saturation3'

        // DataTypeConversion: '<S11>/Cast To Double3' incorporates:
        //   Constant: '<S11>/One3'
        //   Gain: '<S11>/Gain3'
        //   Sum: '<S11>/Add3'

        rtb_Add1 = static_cast<real32_T>(floor(static_cast<real_T>
          (Flash_FCC_P.Gain3_Gain * rtb_Add1 + Flash_FCC_P.One3_Value_o)));
        if (rtIsNaNF(rtb_Add1) || rtIsInfF(rtb_Add1)) {
          rtb_Add1 = 0.0F;
        } else {
          rtb_Add1 = static_cast<real32_T>(fmod(static_cast<real_T>(rtb_Add1),
            65536.0));
        }

        Flash_FCC_B.pwmValue[3] = static_cast<uint16_T>(rtb_Add1 < 0.0F ?
          static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
          static_cast<uint16_T>(-rtb_Add1)))) : static_cast<int32_T>(
          static_cast<uint16_T>(rtb_Add1)));
        status = pwm_setServo(&Flash_FCC_DW.obj_a.pwmDevHandler,
                              Flash_FCC_DW.obj_a.servoCount,
                              Flash_FCC_DW.obj_a.channelMask,
                              Flash_FCC_B.pwmValue);
        Flash_FCC_DW.obj_a.errorStatus = static_cast<uint16_T>
          (Flash_FCC_DW.obj_a.errorStatus | status);
      } else {
        status = pwm_disarm(&Flash_FCC_DW.obj_a.pwmDevHandler);
        Flash_FCC_DW.obj_a.errorStatus = static_cast<uint16_T>
          (Flash_FCC_DW.obj_a.errorStatus | status);
        Flash_FCC_DW.obj_a.isArmed = false;
        status = pwm_resetServo(&Flash_FCC_DW.obj_a.pwmDevHandler,
          Flash_FCC_DW.obj_a.servoCount, Flash_FCC_DW.obj_a.channelMask,
          Flash_FCC_DW.obj_a.isMain);
        Flash_FCC_DW.obj_a.errorStatus = static_cast<uint16_T>
          (Flash_FCC_DW.obj_a.errorStatus | status);
      }

      if (Flash_FCC_DW.obj_a.isMain) {
        status = pwm_forceFailsafe(&Flash_FCC_DW.obj_a.pwmDevHandler,
          Flash_FCC_P.One4_Value_h);
        Flash_FCC_DW.obj_a.errorStatus = static_cast<uint16_T>
          (Flash_FCC_DW.obj_a.errorStatus | status);
      }

      // End of MATLABSystem: '<S11>/PX4 PWM Output1'

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[4] = rtb_Fin_4_Cmd_rad;

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[3] = rtb_Fin_3_Cmd_rad;

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[2] = rtb_Add3_a;

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[5] = Flash_FCC_B.In1.x;

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[6] = Flash_FCC_B.In1.y;

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[7] = Flash_FCC_B.In1.z;

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One3'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_4_Threshold_k) {
        Flash_FCC_B.VectorConcatenate[11] = Flash_FCC_B.In1_c[7];
      } else {
        Flash_FCC_B.VectorConcatenate[11] = Flash_FCC_P.One3_Value;
      }

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One4'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_5_Threshold) {
        Flash_FCC_B.VectorConcatenate[12] = Flash_FCC_B.In1_c[8];
      } else {
        Flash_FCC_B.VectorConcatenate[12] = Flash_FCC_P.One4_Value;
      }

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One5'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_6_Threshold) {
        Flash_FCC_B.VectorConcatenate[13] = Flash_FCC_B.In1_c[9];
      } else {
        Flash_FCC_B.VectorConcatenate[13] = Flash_FCC_P.One5_Value;
      }

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One6'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_7_Threshold) {
        Flash_FCC_B.VectorConcatenate[14] = Flash_FCC_B.In1_c[10];
      } else {
        Flash_FCC_B.VectorConcatenate[14] = Flash_FCC_P.One6_Value;
      }

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One7'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_8_Threshold) {
        Flash_FCC_B.VectorConcatenate[15] = Flash_FCC_B.In1_c[11];
      } else {
        Flash_FCC_B.VectorConcatenate[15] = Flash_FCC_P.One7_Value;
      }

      // Switch generated from: '<S8>/Switch' incorporates:
      //   Constant: '<S24>/One8'

      if (Flash_FCC_B.In1_c[2] > Flash_FCC_P.Switch_9_Threshold) {
        Flash_FCC_B.VectorConcatenate[16] = Flash_FCC_B.In1_c[12];
      } else {
        Flash_FCC_B.VectorConcatenate[16] = Flash_FCC_P.One8_Value;
      }

      // SignalConversion generated from: '<S9>/Vector Concatenate'
      Flash_FCC_B.VectorConcatenate[0] = Flash_FCC_B.In1_c[1];

      // Constant: '<S1>/Zero'
      Flash_FCC_B.VectorConcatenate[17] = Flash_FCC_P.Zero_Value_g;

      // S-Function (any2byte): '<S10>/Byte Pack'

      // Pack: <S10>/Byte Pack
      (void) memcpy(&Flash_FCC_B.VectorConcatenate1[3],
                    &Flash_FCC_B.VectorConcatenate[0],
                    72);

      // MATLABSystem: '<S1>/Serial Transmit'
      memcpy((void *)&Flash_FCC_B.TxDataLocChar[0], (void *)
             &Flash_FCC_B.VectorConcatenate1[0], (uint32_T)((size_t)75 * sizeof
              (uint8_T)));
      MW_SCI_Transmit(Flash_FCC_DW.obj_k.MW_SCIHANDLE, Flash_FCC_B.TxDataLocChar,
                      75U);

      // Update for Delay: '<S3>/Delay'
      Flash_FCC_DW.Delay_DSTATE = Flash_FCC_B.In1_c[1];

      // Update for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn'
      Flash_FCC_DW.DiscreteTransferFcn_states = rtb_u;

      // Update for Delay: '<S26>/Delay'
      Flash_FCC_DW.Delay_DSTATE_n = Flash_FCC_B.In1_c[1];
    }

    // End of Outputs for SubSystem: '<Root>/Pixhawk Software - 100 Hz'
  }

  rate_scheduler();
}

// Model initialize function
void Flash_FCC_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // block I/O
  (void) memset((static_cast<void *>(&Flash_FCC_B)), 0,
                sizeof(B_Flash_FCC_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&Flash_FCC_DW), 0,
                sizeof(DW_Flash_FCC_T));

  {
    boolean_T rtb_AND;
    int32_T i;

    // Start for MATLABSystem: '<S2>/Serial Receive'
    Flash_FCC_DW.obj.isInitialized = 0;
    Flash_FCC_DW.obj.matlabCodegenIsDeleted = false;
    Flash_FCC_DW.obj.SampleTime = Flash_FCC_P.SerialReceive_SampleTime;
    Flash_FCC_SystemCore_setup_fh(&Flash_FCC_DW.obj);

    // Start for DiscretePulseGenerator: '<Root>/Pulse Generator1'
    Flash_FCC_DW.clockTickCounter = 0;

    // Start for Triggered SubSystem: '<Root>/Pixhawk Software - 100 Hz'
    // Start for MATLABSystem: '<S22>/SourceBlock'
    Flash_FCC_DW.obj_o.matlabCodegenIsDeleted = false;
    Flash_FCC_DW.obj_o.isSetupComplete = false;
    Flash_FCC_DW.obj_o.isInitialized = 1;
    Flash_FCC_DW.obj_o.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(Flash_FCC_DW.obj_o.orbMetadataObj,
                         &Flash_FCC_DW.obj_o.eventStructObj);
    Flash_FCC_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/PX4 PWM Output1' incorporates:
    //   Constant: '<S11>/One4'

    Flash_FCC_DW.obj_a.errorStatus = 0U;
    Flash_FCC_DW.obj_a.isInitialized = 0;
    Flash_FCC_DW.obj_a.matlabCodegenIsDeleted = false;
    Flash_FCC_SystemCore_setup_f(&Flash_FCC_DW.obj_a, rtb_AND,
      Flash_FCC_P.One4_Value_h);

    // Start for MATLABSystem: '<S1>/Serial Transmit'
    Flash_FCC_DW.obj_k.isInitialized = 0;
    Flash_FCC_DW.obj_k.matlabCodegenIsDeleted = false;
    Flash_FCC_SystemCore_setup(&Flash_FCC_DW.obj_k);

    // End of Start for SubSystem: '<Root>/Pixhawk Software - 100 Hz'
    Flash_FCC_PrevZCX.DiscreteTransferFcn_Reset_ZCE = POS_ZCSIG;
    Flash_FCC_PrevZCX.PixhawkSoftware100Hz_Trig_ZCE = UNINITIALIZED_ZCSIG;
    Flash_FCC_PrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

    // SystemInitialize for Triggered SubSystem: '<S2>/Triggered Subsystem'
    // SystemInitialize for Outport: '<S31>/Out1'
    for (i = 0; i < 23; i++) {
      Flash_FCC_B.In1_c[i] = Flash_FCC_P.Out1_Y0_o;
    }

    // End of SystemInitialize for Outport: '<S31>/Out1'
    // End of SystemInitialize for SubSystem: '<S2>/Triggered Subsystem'

    // SystemInitialize for Triggered SubSystem: '<Root>/Pixhawk Software - 100 Hz' 
    // InitializeConditions for Delay: '<S3>/Delay'
    Flash_FCC_DW.Delay_DSTATE = Flash_FCC_P.Delay_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S14>/Discrete Transfer Fcn' 
    Flash_FCC_DW.DiscreteTransferFcn_states =
      Flash_FCC_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for Delay: '<S26>/Delay'
    Flash_FCC_DW.Delay_DSTATE_n = Flash_FCC_P.Delay_InitialCondition_h;

    // SystemInitialize for Enabled SubSystem: '<S22>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S23>/Out1'
    Flash_FCC_B.In1 = Flash_FCC_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S22>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/Pixhawk Software - 100 Hz' 
  }
}

// Model terminate function
void Flash_FCC_terminate(void)
{
  // Terminate for MATLABSystem: '<S2>/Serial Receive'
  matlabCodegenHandle_matlabC_fhm(&Flash_FCC_DW.obj);

  // Terminate for Triggered SubSystem: '<Root>/Pixhawk Software - 100 Hz'
  // Terminate for MATLABSystem: '<S22>/SourceBlock'
  matlabCodegenHandle_matlabCod_f(&Flash_FCC_DW.obj_o);

  // Terminate for MATLABSystem: '<S11>/PX4 PWM Output1'
  matlabCodegenHandle_matlabCo_fh(&Flash_FCC_DW.obj_a);

  // Terminate for MATLABSystem: '<S1>/Serial Transmit'
  matlabCodegenHandle_matlabCodeg(&Flash_FCC_DW.obj_k);

  // End of Terminate for SubSystem: '<Root>/Pixhawk Software - 100 Hz'
}

//
// File trailer for generated code.
//
// [EOF]
//
