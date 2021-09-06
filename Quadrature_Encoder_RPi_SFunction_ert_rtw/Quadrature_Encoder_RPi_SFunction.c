/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Quadrature_Encoder_RPi_SFunction.c
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

#include "Quadrature_Encoder_RPi_SFunction.h"
#include "Quadrature_Encoder_RPi_SFunction_private.h"

/* Block signals (default storage) */
BlockIO_Quadrature_Encoder_RPi_ Quadrature_Encoder_RPi_SFunct_B;

/* Block states (default storage) */
D_Work_Quadrature_Encoder_RPi_S Quadrature_Encoder_RPi_SF_DWork;

/* Real-time model */
static RT_MODEL_Quadrature_Encoder_RPi Quadrature_Encoder_RPi_SFunc_M_;
RT_MODEL_Quadrature_Encoder_RPi *const Quadrature_Encoder_RPi_SFunc_M =
  &Quadrature_Encoder_RPi_SFunc_M_;

/* Model step function */
void Quadrature_Encoder_RPi_SFunction_step(void)
{
  /* S-Function (Quad_Encoder_sfn): '<Root>/Quad Encoder WiningPi pins 1 and 4 ' */
  Quad_Encoder_sfn_Outputs_wrapper
    (&Quadrature_Encoder_RPi_SFunct_B.QuadEncoderWiningPipins1and4,
     &Quadrature_Encoder_RPi_SF_DWork.QuadEncoderWiningPipins1and4_DS,
     &Quadrature_Encoder_RPi_SFunct_P.QuadEncoderWiningPipins1and4_P1, 1,
     &Quadrature_Encoder_RPi_SFunct_P.QuadEncoderWiningPipins1and4_P2, 1,
     &Quadrature_Encoder_RPi_SFunct_P.QuadEncoderWiningPipins1and4_P3, 1);

  /* Update for S-Function (Quad_Encoder_sfn): '<Root>/Quad Encoder WiningPi pins 1 and 4 ' */

  /* S-Function "Quad_Encoder_sfn_wrapper" Block: <Root>/Quad Encoder WiningPi pins 1 and 4  */
  Quad_Encoder_sfn_Update_wrapper
    (&Quadrature_Encoder_RPi_SFunct_B.QuadEncoderWiningPipins1and4,
     &Quadrature_Encoder_RPi_SF_DWork.QuadEncoderWiningPipins1and4_DS,
     &Quadrature_Encoder_RPi_SFunct_P.QuadEncoderWiningPipins1and4_P1, 1,
     &Quadrature_Encoder_RPi_SFunct_P.QuadEncoderWiningPipins1and4_P2, 1,
     &Quadrature_Encoder_RPi_SFunct_P.QuadEncoderWiningPipins1and4_P3, 1);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)Quadrature_Encoder_RPi_SFunc_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(Quadrature_Encoder_RPi_SFunc_M)!=-1) &&
        !((rtmGetTFinal(Quadrature_Encoder_RPi_SFunc_M)-
           Quadrature_Encoder_RPi_SFunc_M->Timing.taskTime0) >
          Quadrature_Encoder_RPi_SFunc_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Quadrature_Encoder_RPi_SFunc_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Quadrature_Encoder_RPi_SFunc_M)) {
      rtmSetErrorStatus(Quadrature_Encoder_RPi_SFunc_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Quadrature_Encoder_RPi_SFunc_M->Timing.taskTime0 =
    ((time_T)(++Quadrature_Encoder_RPi_SFunc_M->Timing.clockTick0)) *
    Quadrature_Encoder_RPi_SFunc_M->Timing.stepSize0;
}

/* Model initialize function */
void Quadrature_Encoder_RPi_SFunction_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Quadrature_Encoder_RPi_SFunc_M, -1);
  Quadrature_Encoder_RPi_SFunc_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Quadrature_Encoder_RPi_SFunc_M->Sizes.checksums[0] = (3528235584U);
  Quadrature_Encoder_RPi_SFunc_M->Sizes.checksums[1] = (3444351878U);
  Quadrature_Encoder_RPi_SFunc_M->Sizes.checksums[2] = (1024102181U);
  Quadrature_Encoder_RPi_SFunc_M->Sizes.checksums[3] = (536740002U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Quadrature_Encoder_RPi_SFunc_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Quadrature_Encoder_RPi_SFunc_M->extModeInfo,
      &Quadrature_Encoder_RPi_SFunc_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Quadrature_Encoder_RPi_SFunc_M->extModeInfo,
                        Quadrature_Encoder_RPi_SFunc_M->Sizes.checksums);
    rteiSetTPtr(Quadrature_Encoder_RPi_SFunc_M->extModeInfo, rtmGetTPtr
                (Quadrature_Encoder_RPi_SFunc_M));
  }

  /* InitializeConditions for S-Function (Quad_Encoder_sfn): '<Root>/Quad Encoder WiningPi pins 1 and 4 ' */

  /* S-Function Block: <Root>/Quad Encoder WiningPi pins 1 and 4  */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        Quadrature_Encoder_RPi_SF_DWork.QuadEncoderWiningPipins1and4_DS =
          initVector[0];
      }
    }
  }
}

/* Model terminate function */
void Quadrature_Encoder_RPi_SFunction_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
