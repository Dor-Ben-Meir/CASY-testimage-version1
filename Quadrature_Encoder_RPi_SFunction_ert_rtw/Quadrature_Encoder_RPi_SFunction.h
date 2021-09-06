/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quadrature_Encoder_RPi_SFunction.h
 *
 * Code generated for Simulink model 'Quadrature_Encoder_RPi_SFunction'.
 *
 * Model version                  : 1.103
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun May  2 14:34:44 2021
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Quadrature_Encoder_RPi_SFunction_h_
#define RTW_HEADER_Quadrature_Encoder_RPi_SFunction_h_
#include <float.h>
#include <stddef.h>
#ifndef Quadrature_Encoder_RPi_SFunction_COMMON_INCLUDES_
#define Quadrature_Encoder_RPi_SFunction_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "ext_work.h"
#endif                   /* Quadrature_Encoder_RPi_SFunction_COMMON_INCLUDES_ */

#include "Quadrature_Encoder_RPi_SFunction_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#define Quadrature_Encoder_RPi_SFunction_M (Quadrature_Encoder_RPi_SFunc_M)

/* Block signals (default storage) */
typedef struct {
  int16_T QuadEncoderWiningPipins1and4;
                              /* '<Root>/Quad Encoder WiningPi pins 1 and 4 ' */
} BlockIO_Quadrature_Encoder_RPi_;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T QuadEncoderWiningPipins1and4_DS;
                              /* '<Root>/Quad Encoder WiningPi pins 1 and 4 ' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_QuadE;   /* synthesized block */

  struct {
    void *LoggedData;
  } encoder_PWORK;                     /* '<Root>/encoder' */
} D_Work_Quadrature_Encoder_RPi_S;

/* Parameters (default storage) */
struct Parameters_Quadrature_Encoder_R_ {
  uint8_T QuadEncoderWiningPipins1and4_P1;/* Expression: uint8(1024)
                                           * Referenced by: '<Root>/Quad Encoder WiningPi pins 1 and 4 '
                                           */
  uint8_T QuadEncoderWiningPipins1and4_P2;/* Expression: uint8(24)
                                           * Referenced by: '<Root>/Quad Encoder WiningPi pins 1 and 4 '
                                           */
  uint8_T QuadEncoderWiningPipins1and4_P3;/* Expression: uint8(23)
                                           * Referenced by: '<Root>/Quad Encoder WiningPi pins 1 and 4 '
                                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_Quadrature_Encoder_RPi_ {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_Quadrature_Encoder_R Quadrature_Encoder_RPi_SFunct_P;

/* Block signals (default storage) */
extern BlockIO_Quadrature_Encoder_RPi_ Quadrature_Encoder_RPi_SFunct_B;

/* Block states (default storage) */
extern D_Work_Quadrature_Encoder_RPi_S Quadrature_Encoder_RPi_SF_DWork;

/* Model entry point functions */
extern void Quadrature_Encoder_RPi_SFunction_initialize(void);
extern void Quadrature_Encoder_RPi_SFunction_step(void);
extern void Quadrature_Encoder_RPi_SFunction_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Quadrature_Encoder_RPi *const Quadrature_Encoder_RPi_SFunc_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Quadrature_Encoder_RPi_SFunction'
 */
#endif                      /* RTW_HEADER_Quadrature_Encoder_RPi_SFunction_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
