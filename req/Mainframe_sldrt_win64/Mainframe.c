/*
 * Mainframe.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Mainframe".
 *
 * Model version              : 1.275
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Feb 18 00:43:29 2021
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Mainframe.h"
#include "Mainframe_private.h"
#include "Mainframe_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  115200.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/Serial_Port", 10U, 8, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_Mainframe_T Mainframe_B;

/* Continuous states */
X_Mainframe_T Mainframe_X;

/* Block states (default storage) */
DW_Mainframe_T Mainframe_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Mainframe_T Mainframe_PrevZCX;

/* Real-time model */
RT_MODEL_Mainframe_T Mainframe_M_;
RT_MODEL_Mainframe_T *const Mainframe_M = &Mainframe_M_;

/* Forward declaration for local functions */
static void Mainframe_nullAssignment(real_T x_data[], int32_T x_size[2], const
  boolean_T idx_data[], const int32_T idx_size[2]);
static void rate_scheduler(void);
real_T look1_binlcapw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T maxIndex)
{
  real_T y;
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
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
    iLeft = maxIndex;
    frac = 0.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    y = (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
  }

  return y;
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Mainframe_M->Timing.TaskCounters.TID[2])++;
  if ((Mainframe_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.01s, 0.0s] */
    Mainframe_M->Timing.TaskCounters.TID[2] = 0;
  }

  Mainframe_M->Timing.sampleHits[2] = (Mainframe_M->Timing.TaskCounters.TID[2] ==
    0);
  (Mainframe_M->Timing.TaskCounters.TID[3])++;
  if ((Mainframe_M->Timing.TaskCounters.TID[3]) > 99) {/* Sample time: [0.1s, 0.0s] */
    Mainframe_M->Timing.TaskCounters.TID[3] = 0;
  }

  Mainframe_M->Timing.sampleHits[3] = (Mainframe_M->Timing.TaskCounters.TID[3] ==
    0);
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 61;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Mainframe_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Mainframe_output();
  Mainframe_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Mainframe_output();
  Mainframe_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for trigger system:
 *    '<S1>/Enabled Subsystem1'
 *    '<S70>/Enabled Subsystem1'
 */
void Mainframe_EnabledSubsystem1_Init(B_EnabledSubsystem1_Mainframe_T *localB,
  P_EnabledSubsystem1_Mainframe_T *localP)
{
  /* SystemInitialize for Outport: '<S29>/CalibrationTime' */
  localB->DigitalClock = localP->CalibrationTime_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S1>/Enabled Subsystem1'
 *    '<S70>/Enabled Subsystem1'
 */
void Mainframe_EnabledSubsystem1(RT_MODEL_Mainframe_T * const Mainframe_M,
  boolean_T rtu_Trigger, B_EnabledSubsystem1_Mainframe_T *localB,
  DW_EnabledSubsystem1_Mainframe_T *localDW, ZCE_EnabledSubsystem1_Mainframe_T
  *localZCE)
{
  /* Outputs for Triggered SubSystem: '<S1>/Enabled Subsystem1' incorporates:
   *  TriggerPort: '<S29>/Trigger'
   */
  if (rtmIsMajorTimeStep(Mainframe_M)) {
    if (rtu_Trigger && (localZCE->EnabledSubsystem1_Trig_ZCE != POS_ZCSIG)) {
      /* DigitalClock: '<S29>/Digital Clock' */
      localB->DigitalClock = Mainframe_M->Timing.t[1];
      localDW->EnabledSubsystem1_SubsysRanBC = 4;
    }

    localZCE->EnabledSubsystem1_Trig_ZCE = rtu_Trigger;
  }

  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem1' */
}

/*
 * Output and update for atomic system:
 *    '<S151>/Limiting_Acceleration'
 *    '<S152>/Limiting_Acceleration'
 *    '<S153>/Limiting_Acceleration'
 *    '<S154>/Limiting_Acceleration'
 */
void Mainframe_Limiting_Acceleration(real_T rtu_siB, real_T rtu_d_siB, real_T
  rtu_dd_siB, B_Limiting_Acceleration_Mainframe_T *localB, real_T rtp_d_siB_max,
  real_T rtp_d_siB_min, real_T rtp_dd_siB_max, real_T rtp_dd_siB_min, real_T
  rtp_siB_max, real_T rtp_siB_min)
{
  localB->dd_siB_l = rtu_dd_siB;
  if (rtu_dd_siB < rtp_dd_siB_min) {
    localB->dd_siB_l = rtp_dd_siB_min;
  } else {
    if (rtp_dd_siB_max < rtu_dd_siB) {
      localB->dd_siB_l = rtp_dd_siB_max;
    }
  }

  if (((rtu_siB <= rtp_siB_min) && (rtu_d_siB < 0.0)) || ((rtp_siB_max <=
        rtu_siB) && (0.0 < rtu_d_siB))) {
    localB->dd_siB_l = 0.0;
  }

  if (((rtu_d_siB <= rtp_d_siB_min) && (rtu_dd_siB < 0.0)) || ((rtp_d_siB_max <=
        rtu_d_siB) && (0.0 < rtu_dd_siB))) {
    localB->dd_siB_l = 0.0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S151>/Limiting_Rate'
 *    '<S152>/Limiting_Rate'
 *    '<S153>/Limiting_Rate'
 *    '<S154>/Limiting_Rate'
 */
void Mainframe_Limiting_Rate(real_T rtu_siB, real_T rtu_d_siB,
  B_Limiting_Rate_Mainframe_T *localB, real_T rtp_d_siB_max, real_T
  rtp_d_siB_min, real_T rtp_siB_max, real_T rtp_siB_min)
{
  localB->d_siB_l = rtu_d_siB;
  if (rtu_d_siB < rtp_d_siB_min) {
    localB->d_siB_l = rtp_d_siB_min;
  } else {
    if (rtp_d_siB_max < rtu_d_siB) {
      localB->d_siB_l = rtp_d_siB_max;
    }
  }

  if (((rtu_siB <= rtp_siB_min) && (rtu_d_siB < 0.0)) || ((rtp_siB_max <=
        rtu_siB) && (0.0 < rtu_d_siB))) {
    localB->d_siB_l = 0.0;
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T lo;
  uint32_T hi;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T y;
  real_T sr;
  real_T si;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
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

    y = atan2(u0_0, u1_0);
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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

void rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(const real_T u0[9], const real_T u1[3],
  real_T y[3])
{
  real_T A[9];
  int32_T r1;
  int32_T r2;
  int32_T r3;
  real_T maxval;
  real_T a21;
  int32_T rtemp;
  memcpy(&A[0], &u0[0], 9U * sizeof(real_T));
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = fabs(u0[0]);
  a21 = fabs(u0[1]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }

  if (fabs(u0[2]) > maxval) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }

  A[r2] = u0[r2] / u0[r1];
  A[r3] /= A[r1];
  A[r2 + 3] -= A[r1 + 3] * A[r2];
  A[r3 + 3] -= A[r1 + 3] * A[r3];
  A[r2 + 6] -= A[r1 + 6] * A[r2];
  A[r3 + 6] -= A[r1 + 6] * A[r3];
  if (fabs(A[r3 + 3]) > fabs(A[r2 + 3])) {
    rtemp = r2 + 1;
    r2 = r3;
    r3 = rtemp - 1;
  }

  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  y[1] = u1[r2] - u1[r1] * A[r2];
  y[2] = (u1[r3] - u1[r1] * A[r3]) - A[r3 + 3] * y[1];
  y[2] /= A[r3 + 6];
  y[0] = u1[r1] - A[r1 + 6] * y[2];
  y[1] -= A[r2 + 6] * y[2];
  y[1] /= A[r2 + 3];
  y[0] -= A[r1 + 3] * y[1];
  y[0] /= A[r1];
}

/* Function for MATLAB Function: '<S58>/Extract Message' */
static void Mainframe_nullAssignment(real_T x_data[], int32_T x_size[2], const
  boolean_T idx_data[], const int32_T idx_size[2])
{
  int32_T nxout;
  int32_T k0;
  int32_T k;
  nxout = 0;
  for (k0 = 0; k0 < idx_size[1]; k0++) {
    nxout += idx_data[k0];
  }

  nxout = x_size[1] - nxout;
  k0 = -1;
  for (k = 0; k < x_size[1]; k++) {
    if ((k + 1 > idx_size[1]) || (!idx_data[k])) {
      k0++;
      x_data[k0] = x_data[k];
    }
  }

  if (1 > nxout) {
    x_size[1] = 0;
  } else {
    x_size[1] = nxout;
  }
}

/* Model output function */
void Mainframe_output(void)
{
  /* local block i/o variables */
  real_T rtb_siB;
  real_T rtb_siB_a;
  real_T rtb_siB_e;
  real_T rtb_siB_i;
  real_T rtb_d_siB;
  real_T rtb_d_siB_g;
  real_T rtb_d_siB_j;
  real_T rtb_d_siB_b;
  real_T rtb_dd_siB;
  real_T rtb_dd_siB_h;
  real_T rtb_dd_siB_k;
  real_T rtb_dd_siB_c;
  uint8_T packet[75];
  real_T headerPos_data[75];
  uint8_T messageTmp_data[149];
  int32_T d;
  boolean_T x[75];
  int8_T ii_data[75];
  real32_T y_data[18];
  uint8_T b_x_data[72];
  int32_T idx;
  ZCEventType zcEvent;
  real_T *lastU;
  real_T beta;
  real_T w;
  real_T q_0;
  real_T rtb_jxi_f;
  real_T rtb_ixk_k;
  real_T rtb_Switch_j;
  real_T rtb_Sum4[3];
  real_T rtb_VectorConcatenate_hw[4];
  real_T rtb_wEIE[3];
  real_T rtb_myItems[18];
  real_T rtb_Sum1_e[3];
  real_T rtb_IntegratorSecondOrderLimited_o1[3];
  real_T rtb_IntegratorSecondOrderLimited_o2_a[3];
  uint16_T rtb_FixPtSum1;
  real_T rtb_TrigonometricFunction1_j;
  real_T rtb_q_conj[4];
  real_T rtb_afinB[3];
  real_T rtb_d_qEI[4];
  real_T rtb_d_qBI[4];
  real_T rtb_u2[3];
  real_T rtb_VectorConcatenate3[9];
  real_T rtb_T_sim_glbl;
  real_T rtb_uzetawn_p[3];
  real_T rtb_ZeroOrderHold2_c[3];
  real_T rtb_JMMB[9];
  real_T rtb_Sqrt_c;
  real_T rtb_lat;
  real_T rtb_Sqrt_cv;
  real_T rtb_Product2_l;
  real_T rtb_Product9_k;
  real_T rtb_VectorConcatenate_m[3];
  real_T rtb_MathFunction2[9];
  real_T rtb_MultiportSwitch[9];
  real_T rtb_MultiportSwitch1[9];
  real_T rtb_MultiportSwitch2[9];
  real_T rtb_TBI_tmp[9];
  real_T c_x_tmp;
  real_T rtb_gamma_R_tmp;
  int32_T i;
  real_T rtb_VectorConcatenate_fo[3];
  int32_T loop_ub;
  real_T tmp[16];
  real_T rtb_Product2_mq[9];
  boolean_T tmp_0;
  int32_T headerPos_size[2];
  int32_T headerPos_size_0[2];
  int32_T headerPos_size_1[2];
  int32_T tmp_size[2];
  int32_T packet_size[2];
  real_T rtb_VectorConcatenate_de;
  real_T rtb_Product_d;
  real_T rtb_Product4_b_idx_3;
  real_T rtb_Product4_b_idx_1;
  real_T rtb_Product4_b_idx_2;
  real_T rtb_Product_b_idx_0;
  real_T rtb_Product_b_idx_1;
  real_T rtb_Product_b_idx_2;
  real_T q0_tmp;
  real_T rtb_JMMB_tmp;
  real_T rtb_JMMB_tmp_0;
  real_T rtb_JMMB_tmp_1;
  real_T rtb_JMMB_tmp_2;
  real_T rtb_JMMB_tmp_3;
  real_T rtb_JMMB_tmp_4;
  real_T rtb_VectorConcatenate3_tmp;
  real_T rtb_VectorConcatenate3_tmp_0;
  real_T rtb_VectorConcatenate3_tmp_1;
  real_T rtb_Product2_mq_tmp;
  real_T rtb_IntegratorSecondOrderLimited_o2_h_tmp;
  real_T rtb_IntegratorSecondOrderLimited_o2_h_tmp_0;
  real_T w_tmp;
  real_T rtb_JMMB_tmp_5;
  real_T rtb_JMMB_tmp_6;
  int32_T rtb_MultiportSwitch1_tmp;
  uint8_T *rtb_message_0;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(Mainframe_M)) {
    /* set solver stop time */
    if (!(Mainframe_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Mainframe_M->solverInfo,
                            ((Mainframe_M->Timing.clockTickH0 + 1) *
        Mainframe_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Mainframe_M->solverInfo,
                            ((Mainframe_M->Timing.clockTick0 + 1) *
        Mainframe_M->Timing.stepSize0 + Mainframe_M->Timing.clockTickH0 *
        Mainframe_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Mainframe_M)) {
    Mainframe_M->Timing.t[0] = rtsiGetT(&Mainframe_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mainframe_DW.EnabledSubsystem1.EnabledSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mainframe_DW.EnabledSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mainframe_DW.EnabledSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mainframe_DW.q_R0R_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mainframe_DW.q_R1R_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mainframe_DW.q_R2R_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mainframe_DW.q_R3R_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Mainframe_DW.Subsystem_SubsysRanBC);

  /* Gain: '<S287>/Gain' incorporates:
   *  TransferFcn: '<S287>/Transfer Fcn1'
   */
  Mainframe_B.Fin_1 = (Mainframe_P.TransferFcn1_C[0] *
                       Mainframe_X.TransferFcn1_CSTATE[0] +
                       Mainframe_P.TransferFcn1_C[1] *
                       Mainframe_X.TransferFcn1_CSTATE[1]) *
    Mainframe_P.Gain_Gain_c5;

  /* Gain: '<S287>/Gain1' incorporates:
   *  TransferFcn: '<S287>/Transfer Fcn2'
   */
  Mainframe_B.Fin_2 = (Mainframe_P.TransferFcn2_C[0] *
                       Mainframe_X.TransferFcn2_CSTATE[0] +
                       Mainframe_P.TransferFcn2_C[1] *
                       Mainframe_X.TransferFcn2_CSTATE[1]) *
    Mainframe_P.Gain1_Gain_bb;

  /* Gain: '<S287>/Gain2' incorporates:
   *  TransferFcn: '<S287>/Transfer Fcn3'
   */
  Mainframe_B.Fin_3 = (Mainframe_P.TransferFcn3_C[0] *
                       Mainframe_X.TransferFcn3_CSTATE[0] +
                       Mainframe_P.TransferFcn3_C[1] *
                       Mainframe_X.TransferFcn3_CSTATE[1]) *
    Mainframe_P.Gain2_Gain_p;

  /* Gain: '<S287>/Gain3' incorporates:
   *  TransferFcn: '<S287>/Transfer Fcn4'
   */
  Mainframe_B.Fin_4 = (Mainframe_P.TransferFcn4_C[0] *
                       Mainframe_X.TransferFcn4_CSTATE[0] +
                       Mainframe_P.TransferFcn4_C[1] *
                       Mainframe_X.TransferFcn4_CSTATE[1]) *
    Mainframe_P.Gain3_Gain_l0;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S276>/Gain1' incorporates:
     *  Constant: '<S69>/Constant1'
     */
    rtb_wEIE[0] = Mainframe_P.Gain1_Gain_m2 * Mainframe_P.Constant1_Value_l2;

    /* Gain: '<S277>/Gain1' incorporates:
     *  Constant: '<S69>/Constant2'
     */
    rtb_wEIE[1] = Mainframe_P.Gain1_Gain_ove * Mainframe_P.Constant2_Value_e;

    /* Gain: '<S278>/Gain1' incorporates:
     *  Constant: '<S69>/Constant3'
     */
    rtb_wEIE[2] = Mainframe_P.Gain1_Gain_gj * Mainframe_P.Constant3_Value_m;

    /* Product: '<S279>/Product' incorporates:
     *  Constant: '<S279>/Constant7'
     */
    for (i = 0; i < 4; i++) {
      Mainframe_B.siB_cmd[i] = 0.0;
      Mainframe_B.siB_cmd[i] += Mainframe_P.Constant7_Value_ej[i] * rtb_wEIE[0];
      Mainframe_B.siB_cmd[i] += Mainframe_P.Constant7_Value_ej[i + 4] *
        rtb_wEIE[1];
      Mainframe_B.siB_cmd[i] += Mainframe_P.Constant7_Value_ej[i + 8] *
        rtb_wEIE[2];
    }

    /* End of Product: '<S279>/Product' */
  }

  /* Sum: '<S69>/Add' incorporates:
   *  SignalConversion generated from: '<S69>/Vector Concatenate'
   * */
  rtb_VectorConcatenate_hw[0] = Mainframe_B.Fin_1 + Mainframe_B.siB_cmd[0];
  rtb_VectorConcatenate_hw[1] = Mainframe_B.Fin_2 + Mainframe_B.siB_cmd[1];
  rtb_VectorConcatenate_hw[2] = Mainframe_B.Fin_3 + Mainframe_B.siB_cmd[2];
  rtb_VectorConcatenate_de = Mainframe_B.Fin_4 + Mainframe_B.siB_cmd[3];

  /* Outputs for Enabled SubSystem: '<S7>/Subsystem' incorporates:
   *  EnablePort: '<S68>/Enable'
   */
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Triggered SubSystem: '<S70>/Enabled Subsystem1' */
    /* Constant: '<S66>/One' */
    Mainframe_EnabledSubsystem1(Mainframe_M, Mainframe_P.One_Value,
      &Mainframe_B.EnabledSubsystem1_h, &Mainframe_DW.EnabledSubsystem1_h,
      &Mainframe_PrevZCX.EnabledSubsystem1_h);

    /* End of Outputs for SubSystem: '<S70>/Enabled Subsystem1' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      /* Constant: '<S66>/One' */
      if (Mainframe_P.One_Value) {
        Mainframe_DW.Subsystem_MODE = true;
      } else {
        if (Mainframe_DW.Subsystem_MODE) {
          /* Disable for Enabled SubSystem: '<S210>/q_R^0(R)' */
          Mainframe_DW.q_R0R_MODE = false;

          /* End of Disable for SubSystem: '<S210>/q_R^0(R)' */

          /* Disable for Enabled SubSystem: '<S210>/q_R^1(R)' */
          Mainframe_DW.q_R1R_MODE = false;

          /* End of Disable for SubSystem: '<S210>/q_R^1(R)' */

          /* Disable for Enabled SubSystem: '<S210>/q_R^2(R)' */
          Mainframe_DW.q_R2R_MODE = false;

          /* End of Disable for SubSystem: '<S210>/q_R^2(R)' */

          /* Disable for Enabled SubSystem: '<S210>/q_R^3(R)' */
          Mainframe_DW.q_R3R_MODE = false;

          /* End of Disable for SubSystem: '<S210>/q_R^3(R)' */
          Mainframe_DW.Subsystem_MODE = false;
        }
      }
    }
  }

  /* Clock: '<S70>/Clock' incorporates:
   *  Clock: '<S26>/Clock'
   *  Clock: '<S27>/Clock'
   *  Clock: '<S28>/Clock'
   *  Derivative: '<S185>/Derivative'
   *  Derivative: '<S185>/Derivative1'
   */
  rtb_jxi_f = Mainframe_M->Timing.t[0];
  if (Mainframe_DW.Subsystem_MODE) {
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S208>/Constant' */
      memcpy(&Mainframe_B.Constant[0], &Mainframe_P.Constant_Value_cg[0], 13U *
             sizeof(real_T));
    }

    /* Integrator: '<S238>/integration_eom' */
    for (i = 0; i < 13; i++) {
      if (Mainframe_DW.integration_eom_IWORK != 0) {
        Mainframe_X.integration_eom_CSTATE[i] = Mainframe_B.Constant[i];
      }

      Mainframe_B.x_d[i] = Mainframe_X.integration_eom_CSTATE[i];
    }

    /* End of Integrator: '<S238>/integration_eom' */

    /* Sum: '<S241>/Add' incorporates:
     *  Product: '<S241>/Product1'
     *  Product: '<S241>/Product2'
     *  Product: '<S241>/Product3'
     *  Product: '<S241>/Product4'
     */
    rtb_Switch_j = ((Mainframe_B.x_d[6] * Mainframe_B.x_d[6] + Mainframe_B.x_d[7]
                     * Mainframe_B.x_d[7]) + Mainframe_B.x_d[8] *
                    Mainframe_B.x_d[8]) + Mainframe_B.x_d[9] * Mainframe_B.x_d[9];

    /* Math: '<S241>/Math Function'
     *
     * About '<S241>/Math Function':
     *  Operator: sqrt
     */
    if (rtb_Switch_j < 0.0) {
      rtb_Switch_j = -sqrt(fabs(rtb_Switch_j));
    } else {
      rtb_Switch_j = sqrt(rtb_Switch_j);
    }

    /* End of Math: '<S241>/Math Function' */

    /* Product: '<S241>/Product' */
    rtb_Product_d = Mainframe_B.x_d[6] / rtb_Switch_j;

    /* MATLAB Function: '<S72>/MATLAB Function1' */
    rtb_q_conj[0] = -rtb_Product_d;

    /* Product: '<S241>/Product' */
    rtb_Product_b_idx_0 = rtb_Product_d;
    rtb_Product_d = Mainframe_B.x_d[7] / rtb_Switch_j;

    /* MATLAB Function: '<S72>/MATLAB Function1' */
    rtb_q_conj[1] = -rtb_Product_d;

    /* Product: '<S241>/Product' */
    rtb_Product_b_idx_1 = rtb_Product_d;
    rtb_Product_d = Mainframe_B.x_d[8] / rtb_Switch_j;

    /* MATLAB Function: '<S72>/MATLAB Function1' */
    rtb_q_conj[2] = -rtb_Product_d;

    /* Product: '<S241>/Product' */
    rtb_Product_b_idx_2 = rtb_Product_d;
    rtb_Product_d = Mainframe_B.x_d[9] / rtb_Switch_j;

    /* Gain: '<S76>/Gain' incorporates:
     *  Product: '<S76>/Product4'
     *  Product: '<S76>/Product5'
     *  Sum: '<S76>/Add2'
     */
    rtb_Product4_b_idx_2 = (rtb_q_conj[1] * rtb_Product_d - rtb_q_conj[0] *
      rtb_q_conj[2]) * Mainframe_P.Gain_Gain_iz;

    /* Saturate: '<S76>/Saturation' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Saturation_UpperSat_ph) {
      rtb_Product4_b_idx_2 = Mainframe_P.Saturation_UpperSat_ph;
    } else {
      if (rtb_Product4_b_idx_2 < Mainframe_P.Saturation_LowerSat_o) {
        rtb_Product4_b_idx_2 = Mainframe_P.Saturation_LowerSat_o;
      }
    }

    /* End of Saturate: '<S76>/Saturation' */

    /* Product: '<S76>/Product3' incorporates:
     *  Product: '<S76>/Product8'
     */
    rtb_Switch_j = rtb_q_conj[1] * rtb_q_conj[1];

    /* ComplexToRealImag: '<S76>/Complex to Real-Imag' incorporates:
     *  Constant: '<S76>/Constant'
     *  Product: '<S76>/Product'
     *  Product: '<S76>/Product1'
     *  Product: '<S76>/Product2'
     *  Product: '<S76>/Product3'
     *  Sum: '<S76>/Add'
     *  Sum: '<S76>/Add1'
     *  Trigonometry: '<S76>/Trigonometric Function'
     */
    Mainframe_B.ComplextoRealImag[0] = rt_atan2d_snf(rtb_q_conj[0] *
      rtb_Product_d + rtb_q_conj[1] * rtb_q_conj[2],
      (Mainframe_P.Constant_Value_ix - rtb_q_conj[0] * rtb_q_conj[0]) -
      rtb_Switch_j);

    /* Gain: '<S78>/1//2' */
    rtb_Product4_b_idx_3 = Mainframe_P.u2_Gain * Mainframe_B.ComplextoRealImag[0];

    /* Trigonometry: '<S78>/sincos' */
    rtb_Sum1_e[0] = sin(rtb_Product4_b_idx_3);
    rtb_IntegratorSecondOrderLimited_o2_a[0] = cos(rtb_Product4_b_idx_3);

    /* Trigonometry: '<S76>/Trigonometric Function1' */
    if (rtb_Product4_b_idx_2 > 1.0) {
      rtb_Product4_b_idx_2 = 1.0;
    } else {
      if (rtb_Product4_b_idx_2 < -1.0) {
        rtb_Product4_b_idx_2 = -1.0;
      }
    }

    /* ComplexToRealImag: '<S76>/Complex to Real-Imag' incorporates:
     *  Trigonometry: '<S76>/Trigonometric Function1'
     */
    Mainframe_B.ComplextoRealImag[1] = asin(rtb_Product4_b_idx_2);

    /* Gain: '<S78>/1//2' */
    rtb_Product4_b_idx_3 = Mainframe_P.u2_Gain * Mainframe_B.ComplextoRealImag[1];

    /* Trigonometry: '<S78>/sincos' */
    rtb_Sum1_e[1] = sin(rtb_Product4_b_idx_3);
    rtb_IntegratorSecondOrderLimited_o2_a[1] = cos(rtb_Product4_b_idx_3);

    /* ComplexToRealImag: '<S76>/Complex to Real-Imag' incorporates:
     *  Constant: '<S76>/Constant1'
     *  Product: '<S76>/Product6'
     *  Product: '<S76>/Product7'
     *  Product: '<S76>/Product9'
     *  Sum: '<S76>/Add3'
     *  Sum: '<S76>/Add4'
     *  Trigonometry: '<S76>/Trigonometric Function2'
     */
    Mainframe_B.ComplextoRealImag[2] = rt_atan2d_snf(rtb_q_conj[0] * rtb_q_conj
      [1] + rtb_q_conj[2] * rtb_Product_d, (Mainframe_P.Constant1_Value_la -
      rtb_Switch_j) - rtb_q_conj[2] * rtb_q_conj[2]);

    /* Gain: '<S78>/1//2' */
    rtb_Product4_b_idx_3 = Mainframe_P.u2_Gain * Mainframe_B.ComplextoRealImag[2];

    /* Trigonometry: '<S78>/sincos' */
    rtb_Sum1_e[2] = sin(rtb_Product4_b_idx_3);
    rtb_IntegratorSecondOrderLimited_o2_a[2] = cos(rtb_Product4_b_idx_3);

    /* Trigonometry: '<S77>/Cos2' */
    rtb_Switch_j = cos(Mainframe_B.ComplextoRealImag[1]);

    /* Gain: '<S77>/Multiply' incorporates:
     *  Product: '<S77>/Product'
     *  Trigonometry: '<S77>/Cos1'
     */
    rtb_Sum4[1] = sin(Mainframe_B.ComplextoRealImag[0]) * rtb_Switch_j *
      Mainframe_P.Multiply_Gain;

    /* Gain: '<S77>/Multiply1' incorporates:
     *  Product: '<S77>/Product1'
     *  Trigonometry: '<S77>/Cos3'
     */
    rtb_Sum4[2] = rtb_Switch_j * cos(Mainframe_B.ComplextoRealImag[0]) *
      Mainframe_P.Multiply1_Gain;

    /* Gain: '<S77>/Multiply2' incorporates:
     *  Trigonometry: '<S77>/Cos'
     */
    rtb_Sum4[0] = Mainframe_P.Multiply2_Gain * sin
      (Mainframe_B.ComplextoRealImag[1]);

    /* Fcn: '<S78>/q0' incorporates:
     *  Fcn: '<S78>/q1'
     */
    rtb_Switch_j = rtb_IntegratorSecondOrderLimited_o2_a[0] *
      rtb_IntegratorSecondOrderLimited_o2_a[1];
    q0_tmp = rtb_Sum1_e[0] * rtb_Sum1_e[1];
    Mainframe_B.q0 = rtb_Switch_j * rtb_IntegratorSecondOrderLimited_o2_a[2] +
      q0_tmp * rtb_Sum1_e[2];

    /* Fcn: '<S78>/q1' */
    Mainframe_B.q1 = rtb_Switch_j * rtb_Sum1_e[2] - q0_tmp *
      rtb_IntegratorSecondOrderLimited_o2_a[2];

    /* Fcn: '<S78>/q2' incorporates:
     *  Fcn: '<S78>/q3'
     */
    rtb_Switch_j = rtb_Sum1_e[0] * rtb_IntegratorSecondOrderLimited_o2_a[1];
    q0_tmp = rtb_IntegratorSecondOrderLimited_o2_a[0] * rtb_Sum1_e[1];
    Mainframe_B.q2 = q0_tmp * rtb_IntegratorSecondOrderLimited_o2_a[2] +
      rtb_Switch_j * rtb_Sum1_e[2];

    /* Fcn: '<S78>/q3' */
    Mainframe_B.q3 = rtb_Switch_j * rtb_IntegratorSecondOrderLimited_o2_a[2] -
      q0_tmp * rtb_Sum1_e[2];

    /* Math: '<S173>/Math Function1' incorporates:
     *  Math: '<S173>/Math Function5'
     *  Math: '<S173>/Math Function9'
     */
    q0_tmp = rtb_Product_b_idx_1 * rtb_Product_b_idx_1;

    /* Math: '<S173>/Math Function' incorporates:
     *  Math: '<S173>/Math Function4'
     *  Math: '<S173>/Math Function8'
     */
    rtb_Switch_j = rtb_Product_b_idx_0 * rtb_Product_b_idx_0;

    /* Math: '<S173>/Math Function2' incorporates:
     *  Math: '<S173>/Math Function10'
     *  Math: '<S173>/Math Function6'
     */
    rtb_Product4_b_idx_1 = rtb_Product_b_idx_2 * rtb_Product_b_idx_2;

    /* Math: '<S173>/Math Function3' incorporates:
     *  Math: '<S173>/Math Function11'
     *  Math: '<S173>/Math Function7'
     */
    rtb_Product4_b_idx_3 = rtb_Product_d * rtb_Product_d;

    /* Sum: '<S173>/Add' incorporates:
     *  Math: '<S173>/Math Function'
     *  Math: '<S173>/Math Function1'
     *  Math: '<S173>/Math Function2'
     *  Math: '<S173>/Math Function3'
     *  Sum: '<S239>/Add'
     *  Switch: '<S237>/Switch'
     */
    rtb_JMMB_tmp_6 = ((rtb_Switch_j - q0_tmp) - rtb_Product4_b_idx_1) +
      rtb_Product4_b_idx_3;
    rtb_JMMB[0] = rtb_JMMB_tmp_6;

    /* Product: '<S173>/Product' incorporates:
     *  Product: '<S173>/Product6'
     *  Product: '<S239>/Product'
     *  Product: '<S239>/Product6'
     *  Switch: '<S237>/Switch'
     */
    rtb_JMMB_tmp = rtb_Product_b_idx_0 * rtb_Product_b_idx_1;

    /* Product: '<S173>/Product1' incorporates:
     *  Product: '<S173>/Product7'
     *  Product: '<S239>/Product1'
     *  Product: '<S239>/Product7'
     *  Switch: '<S237>/Switch'
     */
    rtb_JMMB_tmp_0 = rtb_Product_b_idx_2 * rtb_Product_d;

    /* Sum: '<S173>/Add1' incorporates:
     *  Gain: '<S173>/Gain1'
     *  Gain: '<S173>/Gain2'
     *  Product: '<S173>/Product'
     *  Product: '<S173>/Product1'
     */
    rtb_JMMB[1] = rtb_JMMB_tmp * Mainframe_P.Gain1_Gain_l - rtb_JMMB_tmp_0 *
      Mainframe_P.Gain2_Gain_o;

    /* Product: '<S173>/Product8' incorporates:
     *  Product: '<S173>/Product4'
     *  Product: '<S239>/Product4'
     *  Product: '<S239>/Product8'
     *  Switch: '<S237>/Switch'
     */
    rtb_JMMB_tmp_1 = rtb_Product_b_idx_0 * rtb_Product_b_idx_2;

    /* Product: '<S173>/Product9' incorporates:
     *  Product: '<S173>/Product5'
     *  Product: '<S239>/Product5'
     *  Product: '<S239>/Product9'
     *  Switch: '<S237>/Switch'
     */
    rtb_JMMB_tmp_2 = rtb_Product_b_idx_1 * rtb_Product_d;

    /* Sum: '<S173>/Add5' incorporates:
     *  Gain: '<S173>/Gain10'
     *  Gain: '<S173>/Gain9'
     *  Product: '<S173>/Product8'
     *  Product: '<S173>/Product9'
     */
    rtb_JMMB[2] = rtb_JMMB_tmp_1 * Mainframe_P.Gain9_Gain_f + rtb_JMMB_tmp_2 *
      Mainframe_P.Gain10_Gain_o;

    /* Sum: '<S173>/Add4' incorporates:
     *  Gain: '<S173>/Gain7'
     *  Gain: '<S173>/Gain8'
     */
    rtb_JMMB[3] = rtb_JMMB_tmp * Mainframe_P.Gain7_Gain_h + rtb_JMMB_tmp_0 *
      Mainframe_P.Gain8_Gain_f;

    /* Sum: '<S173>/Add6' incorporates:
     *  Sum: '<S239>/Add6'
     *  Switch: '<S237>/Switch'
     */
    rtb_JMMB_tmp_5 = ((q0_tmp - rtb_Switch_j) - rtb_Product4_b_idx_1) +
      rtb_Product4_b_idx_3;
    rtb_JMMB[4] = rtb_JMMB_tmp_5;

    /* Product: '<S173>/Product2' incorporates:
     *  Product: '<S173>/Product10'
     *  Product: '<S239>/Product10'
     *  Product: '<S239>/Product2'
     *  Switch: '<S237>/Switch'
     */
    rtb_JMMB_tmp_3 = rtb_Product_b_idx_1 * rtb_Product_b_idx_2;

    /* Product: '<S173>/Product3' incorporates:
     *  Product: '<S173>/Product11'
     *  Product: '<S239>/Product11'
     *  Product: '<S239>/Product3'
     *  Switch: '<S237>/Switch'
     */
    rtb_JMMB_tmp_4 = rtb_Product_b_idx_0 * rtb_Product_d;

    /* Sum: '<S173>/Add2' incorporates:
     *  Gain: '<S173>/Gain3'
     *  Gain: '<S173>/Gain4'
     *  Product: '<S173>/Product2'
     *  Product: '<S173>/Product3'
     */
    rtb_JMMB[5] = rtb_JMMB_tmp_3 * Mainframe_P.Gain3_Gain_m - rtb_JMMB_tmp_4 *
      Mainframe_P.Gain4_Gain_g;

    /* Sum: '<S173>/Add3' incorporates:
     *  Gain: '<S173>/Gain5'
     *  Gain: '<S173>/Gain6'
     */
    rtb_JMMB[6] = rtb_JMMB_tmp_1 * Mainframe_P.Gain5_Gain_i - rtb_JMMB_tmp_2 *
      Mainframe_P.Gain6_Gain_e;

    /* Sum: '<S173>/Add8' incorporates:
     *  Gain: '<S173>/Gain11'
     *  Gain: '<S173>/Gain12'
     */
    rtb_JMMB[7] = rtb_JMMB_tmp_3 * Mainframe_P.Gain11_Gain_k + rtb_JMMB_tmp_4 *
      Mainframe_P.Gain12_Gain_j;

    /* Sum: '<S173>/Add7' incorporates:
     *  Sum: '<S239>/Add7'
     *  Switch: '<S237>/Switch'
     */
    q0_tmp = ((rtb_Product4_b_idx_1 - rtb_Switch_j) - q0_tmp) +
      rtb_Product4_b_idx_3;
    rtb_JMMB[8] = q0_tmp;
    for (i = 0; i < 3; i++) {
      /* Math: '<S207>/Math Function' incorporates:
       *  Math: '<S247>/Math Function'
       */
      rtb_TBI_tmp[3 * i] = rtb_JMMB[i];
      rtb_TBI_tmp[3 * i + 1] = rtb_JMMB[i + 3];
      rtb_TBI_tmp[3 * i + 2] = rtb_JMMB[i + 6];
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S183>/Constant8' */
      Mainframe_B.Constant8[0] = Mainframe_P.Constant8_Value_mc[0];
      Mainframe_B.Constant8[1] = Mainframe_P.Constant8_Value_mc[1];
      Mainframe_B.Constant8[2] = Mainframe_P.Constant8_Value_mc[2];
      Mainframe_B.Constant8[3] = Mainframe_P.Constant8_Value_mc[3];
    }

    /* Integrator: '<S183>/integration_eom' */
    if (Mainframe_DW.integration_eom_IWORK_p != 0) {
      Mainframe_X.integration_eom_CSTATE_o[0] = Mainframe_B.Constant8[0];
      Mainframe_X.integration_eom_CSTATE_o[1] = Mainframe_B.Constant8[1];
      Mainframe_X.integration_eom_CSTATE_o[2] = Mainframe_B.Constant8[2];
      Mainframe_X.integration_eom_CSTATE_o[3] = Mainframe_B.Constant8[3];
    }

    /* Sum: '<S187>/Add' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Math: '<S187>/Math Function'
     *  Math: '<S187>/Math Function1'
     *  Math: '<S187>/Math Function2'
     *  Math: '<S187>/Math Function3'
     */
    rtb_VectorConcatenate3[0] = ((Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[0] -
      Mainframe_X.integration_eom_CSTATE_o[1] *
      Mainframe_X.integration_eom_CSTATE_o[1]) -
      Mainframe_X.integration_eom_CSTATE_o[2] *
      Mainframe_X.integration_eom_CSTATE_o[2]) +
      Mainframe_X.integration_eom_CSTATE_o[3] *
      Mainframe_X.integration_eom_CSTATE_o[3];

    /* Sum: '<S187>/Add1' incorporates:
     *  Gain: '<S187>/Gain1'
     *  Gain: '<S187>/Gain2'
     *  Integrator: '<S183>/integration_eom'
     *  Product: '<S187>/Product'
     *  Product: '<S187>/Product1'
     */
    rtb_VectorConcatenate3[1] = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[1] * Mainframe_P.Gain1_Gain_mx -
      Mainframe_X.integration_eom_CSTATE_o[2] *
      Mainframe_X.integration_eom_CSTATE_o[3] * Mainframe_P.Gain2_Gain_i;

    /* Product: '<S187>/Product8' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Product: '<S187>/Product4'
     */
    rtb_lat = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[2];

    /* Product: '<S187>/Product9' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Product: '<S187>/Product5'
     */
    rtb_Sqrt_cv = Mainframe_X.integration_eom_CSTATE_o[1] *
      Mainframe_X.integration_eom_CSTATE_o[3];

    /* Sum: '<S187>/Add5' incorporates:
     *  Gain: '<S187>/Gain10'
     *  Gain: '<S187>/Gain9'
     *  Product: '<S187>/Product8'
     *  Product: '<S187>/Product9'
     */
    rtb_VectorConcatenate3[2] = rtb_lat * Mainframe_P.Gain9_Gain_fk +
      rtb_Sqrt_cv * Mainframe_P.Gain10_Gain_f;

    /* Sum: '<S187>/Add4' incorporates:
     *  Gain: '<S187>/Gain7'
     *  Gain: '<S187>/Gain8'
     *  Integrator: '<S183>/integration_eom'
     *  Product: '<S187>/Product6'
     *  Product: '<S187>/Product7'
     */
    rtb_VectorConcatenate3[3] = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[1] * Mainframe_P.Gain7_Gain_k +
      Mainframe_X.integration_eom_CSTATE_o[2] *
      Mainframe_X.integration_eom_CSTATE_o[3] * Mainframe_P.Gain8_Gain_a;

    /* Math: '<S187>/Math Function6' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Math: '<S187>/Math Function10'
     */
    rtb_Product2_l = Mainframe_X.integration_eom_CSTATE_o[2] *
      Mainframe_X.integration_eom_CSTATE_o[2];

    /* Math: '<S187>/Math Function4' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Math: '<S187>/Math Function8'
     */
    rtb_ixk_k = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[0];

    /* Math: '<S187>/Math Function5' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Math: '<S187>/Math Function9'
     */
    rtb_T_sim_glbl = Mainframe_X.integration_eom_CSTATE_o[1] *
      Mainframe_X.integration_eom_CSTATE_o[1];

    /* Math: '<S187>/Math Function7' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Math: '<S187>/Math Function11'
     */
    rtb_VectorConcatenate3_tmp_1 = Mainframe_X.integration_eom_CSTATE_o[3] *
      Mainframe_X.integration_eom_CSTATE_o[3];

    /* Sum: '<S187>/Add6' incorporates:
     *  Math: '<S187>/Math Function4'
     *  Math: '<S187>/Math Function5'
     *  Math: '<S187>/Math Function6'
     *  Math: '<S187>/Math Function7'
     */
    rtb_VectorConcatenate3[4] = ((rtb_T_sim_glbl - rtb_ixk_k) - rtb_Product2_l)
      + rtb_VectorConcatenate3_tmp_1;

    /* Product: '<S187>/Product2' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Product: '<S187>/Product10'
     */
    rtb_VectorConcatenate3_tmp = Mainframe_X.integration_eom_CSTATE_o[1] *
      Mainframe_X.integration_eom_CSTATE_o[2];

    /* Product: '<S187>/Product3' incorporates:
     *  Integrator: '<S183>/integration_eom'
     *  Product: '<S187>/Product11'
     */
    rtb_VectorConcatenate3_tmp_0 = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[3];

    /* Sum: '<S187>/Add2' incorporates:
     *  Gain: '<S187>/Gain3'
     *  Gain: '<S187>/Gain4'
     *  Product: '<S187>/Product2'
     *  Product: '<S187>/Product3'
     */
    rtb_VectorConcatenate3[5] = rtb_VectorConcatenate3_tmp *
      Mainframe_P.Gain3_Gain_n - rtb_VectorConcatenate3_tmp_0 *
      Mainframe_P.Gain4_Gain_k;

    /* Sum: '<S187>/Add3' incorporates:
     *  Gain: '<S187>/Gain5'
     *  Gain: '<S187>/Gain6'
     */
    rtb_VectorConcatenate3[6] = rtb_lat * Mainframe_P.Gain5_Gain_l - rtb_Sqrt_cv
      * Mainframe_P.Gain6_Gain_d;

    /* Sum: '<S187>/Add8' incorporates:
     *  Gain: '<S187>/Gain11'
     *  Gain: '<S187>/Gain12'
     */
    rtb_VectorConcatenate3[7] = rtb_VectorConcatenate3_tmp *
      Mainframe_P.Gain11_Gain_m + rtb_VectorConcatenate3_tmp_0 *
      Mainframe_P.Gain12_Gain_o;

    /* Sum: '<S187>/Add7' */
    rtb_VectorConcatenate3[8] = ((rtb_Product2_l - rtb_ixk_k) - rtb_T_sim_glbl)
      + rtb_VectorConcatenate3_tmp_1;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Switch: '<S182>/Switch' incorporates:
       *  Constant: '<S182>/Constant7'
       *  Constant: '<S182>/Constant9'
       */
      if (Mainframe_P.Constant9_Value > Mainframe_P.Switch_Threshold) {
        Mainframe_B.wIEE[2] = Mainframe_P.Constant7_Value;

        /* SignalConversion generated from: '<S182>/Vector Concatenate' incorporates:
         *  Constant: '<S182>/Constant6'
         *  Constant: '<S182>/Constant7'
         */
        Mainframe_B.wIEE[1] = Mainframe_P.Constant6_Value;

        /* SignalConversion generated from: '<S182>/Vector Concatenate' incorporates:
         *  Constant: '<S182>/Constant6'
         */
        Mainframe_B.wIEE[0] = Mainframe_P.Constant6_Value;
      } else {
        /* SignalConversion generated from: '<S182>/Vector Concatenate1' incorporates:
         *  Constant: '<S182>/Constant8'
         */
        Mainframe_B.wIEE[2] = Mainframe_P.Constant8_Value;

        /* SignalConversion generated from: '<S182>/Vector Concatenate1' incorporates:
         *  Constant: '<S182>/Constant8'
         */
        Mainframe_B.wIEE[1] = Mainframe_P.Constant8_Value;

        /* SignalConversion generated from: '<S182>/Vector Concatenate1' incorporates:
         *  Constant: '<S182>/Constant8'
         */
        Mainframe_B.wIEE[0] = Mainframe_P.Constant8_Value;
      }

      /* End of Switch: '<S182>/Switch' */
    }

    /* Product: '<S249>/Product' */
    for (i = 0; i < 3; i++) {
      rtb_Sum1_e[i] = rtb_VectorConcatenate3[i + 6] * Mainframe_B.wIEE[2] +
        (rtb_VectorConcatenate3[i + 3] * Mainframe_B.wIEE[1] +
         rtb_VectorConcatenate3[i] * Mainframe_B.wIEE[0]);
    }

    /* End of Product: '<S249>/Product' */

    /* Sum: '<S249>/Add' incorporates:
     *  Product: '<S254>/Product2'
     *  Product: '<S254>/Product3'
     *  Product: '<S254>/Product4'
     *  Product: '<S254>/Product5'
     *  Product: '<S254>/Product6'
     *  Product: '<S254>/Product7'
     *  Sum: '<S254>/Sum'
     *  Sum: '<S254>/Sum1'
     *  Sum: '<S254>/Sum2'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[0] = Mainframe_B.x_d[3] - (rtb_Sum1_e
      [1] * Mainframe_B.x_d[2] - rtb_Sum1_e[2] * Mainframe_B.x_d[1]);
    rtb_IntegratorSecondOrderLimited_o2_a[1] = Mainframe_B.x_d[4] - (rtb_Sum1_e
      [2] * Mainframe_B.x_d[0] - rtb_Sum1_e[0] * Mainframe_B.x_d[2]);
    rtb_ixk_k = Mainframe_B.x_d[5] - (rtb_Sum1_e[0] * Mainframe_B.x_d[1] -
      rtb_Sum1_e[1] * Mainframe_B.x_d[0]);

    /* DotProduct: '<S253>/Dot Product1' */
    rtb_Product4_b_idx_3 = 0.0;
    for (i = 0; i < 3; i++) {
      /* Product: '<S247>/Product' */
      rtb_Switch_j = rtb_TBI_tmp[i + 6] * rtb_ixk_k + (rtb_TBI_tmp[i + 3] *
        rtb_IntegratorSecondOrderLimited_o2_a[1] + rtb_TBI_tmp[i] *
        rtb_IntegratorSecondOrderLimited_o2_a[0]);

      /* DotProduct: '<S253>/Dot Product1' */
      rtb_Product4_b_idx_3 += rtb_Switch_j * rtb_Switch_j;

      /* Product: '<S247>/Product' */
      rtb_u2[i] = rtb_Switch_j;
    }

    /* Math: '<S253>/Math Function1' incorporates:
     *  DotProduct: '<S253>/Dot Product1'
     *
     * About '<S253>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product4_b_idx_3 < 0.0) {
      rtb_Switch_j = -sqrt(fabs(rtb_Product4_b_idx_3));
    } else {
      rtb_Switch_j = sqrt(rtb_Product4_b_idx_3);
    }

    /* End of Math: '<S253>/Math Function1' */

    /* Switch: '<S250>/Switch' incorporates:
     *  Constant: '<S250>/Constant'
     */
    if (rtb_Switch_j != 0.0) {
      /* SignalConversion generated from: '<S250>/Vector Concatenate' */
      rtb_Product4_b_idx_3 = rtb_Switch_j;

      /* SignalConversion generated from: '<S250>/Vector Concatenate' */
      rtb_Product4_b_idx_2 = rtb_u2[2];

      /* SignalConversion generated from: '<S250>/Vector Concatenate' */
      rtb_Product4_b_idx_1 = rtb_u2[1];

      /* SignalConversion generated from: '<S250>/Vector Concatenate' */
      rtb_Switch_j = rtb_u2[0];
    } else {
      rtb_Switch_j = Mainframe_P.Constant_Value_fh[0];
      rtb_Product4_b_idx_1 = Mainframe_P.Constant_Value_fh[1];
      rtb_Product4_b_idx_2 = Mainframe_P.Constant_Value_fh[2];
      rtb_Product4_b_idx_3 = Mainframe_P.Constant_Value_fh[3];
    }

    /* End of Switch: '<S250>/Switch' */

    /* Trigonometry: '<S250>/Trigonometric Function' */
    rtb_Switch_j = rt_atan2d_snf(rtb_Product4_b_idx_2, rtb_Switch_j);

    /* Saturate: '<S112>/Saturation2' */
    if (rtb_Switch_j > Mainframe_P.Saturation2_UpperSat) {
      rtb_Switch_j = Mainframe_P.Saturation2_UpperSat;
    } else {
      if (rtb_Switch_j < Mainframe_P.Saturation2_LowerSat) {
        rtb_Switch_j = Mainframe_P.Saturation2_LowerSat;
      }
    }

    /* End of Saturate: '<S112>/Saturation2' */

    /* Product: '<S250>/Divide' */
    rtb_Product4_b_idx_2 = rtb_Product4_b_idx_1 / rtb_Product4_b_idx_3;

    /* Trigonometry: '<S250>/Trigonometric Function1' */
    if (rtb_Product4_b_idx_2 > 1.0) {
      rtb_Product4_b_idx_2 = 1.0;
    } else {
      if (rtb_Product4_b_idx_2 < -1.0) {
        rtb_Product4_b_idx_2 = -1.0;
      }
    }

    rtb_Product4_b_idx_1 = asin(rtb_Product4_b_idx_2);

    /* End of Trigonometry: '<S250>/Trigonometric Function1' */

    /* Saturate: '<S112>/Saturation3' */
    if (rtb_Product4_b_idx_1 > Mainframe_P.Saturation3_UpperSat) {
      rtb_Product4_b_idx_1 = Mainframe_P.Saturation3_UpperSat;
    } else {
      if (rtb_Product4_b_idx_1 < Mainframe_P.Saturation3_LowerSat) {
        rtb_Product4_b_idx_1 = Mainframe_P.Saturation3_LowerSat;
      }
    }

    /* End of Saturate: '<S112>/Saturation3' */

    /* Integrator: '<S151>/Integrator1' */
    /* Limited  Integrator  (w/ Saturation Port) */
    if (Mainframe_X.Integrator1_CSTATE >= Mainframe_P.Rudder_siB_max) {
      Mainframe_X.Integrator1_CSTATE = Mainframe_P.Rudder_siB_max;
      Mainframe_B.sat = 1.0;
    } else if (Mainframe_X.Integrator1_CSTATE <= Mainframe_P.Rudder_siB_min) {
      Mainframe_X.Integrator1_CSTATE = Mainframe_P.Rudder_siB_min;
      Mainframe_B.sat = -1.0;
    } else {
      Mainframe_B.sat = 0.0;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Signum: '<S151>/Sign' incorporates:
       *  Constant: '<S103>/Constant7'
       */
      if (Mainframe_P.Constant7_Value_k < 0.0) {
        rtb_T_sim_glbl = -1.0;
      } else if (Mainframe_P.Constant7_Value_k > 0.0) {
        rtb_T_sim_glbl = 1.0;
      } else if (Mainframe_P.Constant7_Value_k == 0.0) {
        rtb_T_sim_glbl = 0.0;
      } else {
        rtb_T_sim_glbl = (rtNaN);
      }

      /* End of Signum: '<S151>/Sign' */

      /* Gain: '<S151>/Gain3' */
      Mainframe_B.Gain3 = Mainframe_P.Rudder_unc_bl * rtb_T_sim_glbl;
    }

    /* Sum: '<S151>/Add2' incorporates:
     *  Constant: '<S151>/Constant'
     *  Gain: '<S151>/Gain1'
     *  Integrator: '<S151>/Integrator1'
     */
    rtb_Product4_b_idx_2 = (Mainframe_P.Rudder_unc_scale *
      Mainframe_X.Integrator1_CSTATE + Mainframe_P.Rudder_unc_off) +
      Mainframe_B.Gain3;

    /* Saturate: '<S151>/Saturation1' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Rudder_siB_max) {
      rtb_siB = Mainframe_P.Rudder_siB_max;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Rudder_siB_min) {
      rtb_siB = Mainframe_P.Rudder_siB_min;
    } else {
      rtb_siB = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S151>/Saturation1' */

    /* Integrator: '<S152>/Integrator1' */
    /* Limited  Integrator  (w/ Saturation Port) */
    if (Mainframe_X.Integrator1_CSTATE_n >= Mainframe_P.Rudder1_siB_max) {
      Mainframe_X.Integrator1_CSTATE_n = Mainframe_P.Rudder1_siB_max;
      Mainframe_B.sat_d = 1.0;
    } else if (Mainframe_X.Integrator1_CSTATE_n <= Mainframe_P.Rudder1_siB_min)
    {
      Mainframe_X.Integrator1_CSTATE_n = Mainframe_P.Rudder1_siB_min;
      Mainframe_B.sat_d = -1.0;
    } else {
      Mainframe_B.sat_d = 0.0;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Signum: '<S152>/Sign' incorporates:
       *  Constant: '<S103>/Constant7'
       */
      if (Mainframe_P.Constant7_Value_k < 0.0) {
        rtb_T_sim_glbl = -1.0;
      } else if (Mainframe_P.Constant7_Value_k > 0.0) {
        rtb_T_sim_glbl = 1.0;
      } else if (Mainframe_P.Constant7_Value_k == 0.0) {
        rtb_T_sim_glbl = 0.0;
      } else {
        rtb_T_sim_glbl = (rtNaN);
      }

      /* End of Signum: '<S152>/Sign' */

      /* Gain: '<S152>/Gain3' */
      Mainframe_B.Gain3_g = Mainframe_P.Rudder1_unc_bl * rtb_T_sim_glbl;
    }

    /* Sum: '<S152>/Add2' incorporates:
     *  Constant: '<S152>/Constant'
     *  Gain: '<S152>/Gain1'
     *  Integrator: '<S152>/Integrator1'
     */
    rtb_Product4_b_idx_2 = (Mainframe_P.Rudder1_unc_scale *
      Mainframe_X.Integrator1_CSTATE_n + Mainframe_P.Rudder1_unc_off) +
      Mainframe_B.Gain3_g;

    /* Saturate: '<S152>/Saturation1' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Rudder1_siB_max) {
      rtb_siB_a = Mainframe_P.Rudder1_siB_max;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Rudder1_siB_min) {
      rtb_siB_a = Mainframe_P.Rudder1_siB_min;
    } else {
      rtb_siB_a = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S152>/Saturation1' */

    /* Integrator: '<S153>/Integrator1' */
    /* Limited  Integrator  (w/ Saturation Port) */
    if (Mainframe_X.Integrator1_CSTATE_k >= Mainframe_P.Rudder2_siB_max) {
      Mainframe_X.Integrator1_CSTATE_k = Mainframe_P.Rudder2_siB_max;
      Mainframe_B.sat_a = 1.0;
    } else if (Mainframe_X.Integrator1_CSTATE_k <= Mainframe_P.Rudder2_siB_min)
    {
      Mainframe_X.Integrator1_CSTATE_k = Mainframe_P.Rudder2_siB_min;
      Mainframe_B.sat_a = -1.0;
    } else {
      Mainframe_B.sat_a = 0.0;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Signum: '<S153>/Sign' incorporates:
       *  Constant: '<S103>/Constant7'
       */
      if (Mainframe_P.Constant7_Value_k < 0.0) {
        rtb_T_sim_glbl = -1.0;
      } else if (Mainframe_P.Constant7_Value_k > 0.0) {
        rtb_T_sim_glbl = 1.0;
      } else if (Mainframe_P.Constant7_Value_k == 0.0) {
        rtb_T_sim_glbl = 0.0;
      } else {
        rtb_T_sim_glbl = (rtNaN);
      }

      /* End of Signum: '<S153>/Sign' */

      /* Gain: '<S153>/Gain3' */
      Mainframe_B.Gain3_o = Mainframe_P.Rudder2_unc_bl * rtb_T_sim_glbl;
    }

    /* Sum: '<S153>/Add2' incorporates:
     *  Constant: '<S153>/Constant'
     *  Gain: '<S153>/Gain1'
     *  Integrator: '<S153>/Integrator1'
     */
    rtb_Product4_b_idx_2 = (Mainframe_P.Rudder2_unc_scale *
      Mainframe_X.Integrator1_CSTATE_k + Mainframe_P.Rudder2_unc_off) +
      Mainframe_B.Gain3_o;

    /* Saturate: '<S153>/Saturation1' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Rudder2_siB_max) {
      rtb_siB_e = Mainframe_P.Rudder2_siB_max;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Rudder2_siB_min) {
      rtb_siB_e = Mainframe_P.Rudder2_siB_min;
    } else {
      rtb_siB_e = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S153>/Saturation1' */

    /* Integrator: '<S154>/Integrator1' */
    /* Limited  Integrator  (w/ Saturation Port) */
    if (Mainframe_X.Integrator1_CSTATE_f >= Mainframe_P.Rudder3_siB_max) {
      Mainframe_X.Integrator1_CSTATE_f = Mainframe_P.Rudder3_siB_max;
      Mainframe_B.sat_p = 1.0;
    } else if (Mainframe_X.Integrator1_CSTATE_f <= Mainframe_P.Rudder3_siB_min)
    {
      Mainframe_X.Integrator1_CSTATE_f = Mainframe_P.Rudder3_siB_min;
      Mainframe_B.sat_p = -1.0;
    } else {
      Mainframe_B.sat_p = 0.0;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Signum: '<S154>/Sign' incorporates:
       *  Constant: '<S103>/Constant7'
       */
      if (Mainframe_P.Constant7_Value_k < 0.0) {
        rtb_T_sim_glbl = -1.0;
      } else if (Mainframe_P.Constant7_Value_k > 0.0) {
        rtb_T_sim_glbl = 1.0;
      } else if (Mainframe_P.Constant7_Value_k == 0.0) {
        rtb_T_sim_glbl = 0.0;
      } else {
        rtb_T_sim_glbl = (rtNaN);
      }

      /* End of Signum: '<S154>/Sign' */

      /* Gain: '<S154>/Gain3' */
      Mainframe_B.Gain3_i = Mainframe_P.Rudder3_unc_bl * rtb_T_sim_glbl;
    }

    /* Sum: '<S154>/Add2' incorporates:
     *  Constant: '<S154>/Constant'
     *  Gain: '<S154>/Gain1'
     *  Integrator: '<S154>/Integrator1'
     */
    rtb_Product4_b_idx_2 = (Mainframe_P.Rudder3_unc_scale *
      Mainframe_X.Integrator1_CSTATE_f + Mainframe_P.Rudder3_unc_off) +
      Mainframe_B.Gain3_i;

    /* Saturate: '<S154>/Saturation1' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Rudder3_siB_max) {
      rtb_siB_i = Mainframe_P.Rudder3_siB_max;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Rudder3_siB_min) {
      rtb_siB_i = Mainframe_P.Rudder3_siB_min;
    } else {
      rtb_siB_i = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S154>/Saturation1' */

    /* Product: '<S155>/Product' incorporates:
     *  Constant: '<S155>/Constant8'
     *  SignalConversion generated from: '<S103>/Vector Concatenate1'
     * */
    for (i = 0; i < 3; i++) {
      rtb_Product4_b_idx_3 = Mainframe_P.Constant8_Value_d[i + 9] * rtb_siB_i +
        (Mainframe_P.Constant8_Value_d[i + 6] * rtb_siB_e +
         (Mainframe_P.Constant8_Value_d[i + 3] * rtb_siB_a +
          Mainframe_P.Constant8_Value_d[i] * rtb_siB));
      rtb_afinB[i] = rtb_Product4_b_idx_3;
    }

    /* End of Product: '<S155>/Product' */

    /* DotProduct: '<S252>/Dot Product1' */
    rtb_Product4_b_idx_3 = (rtb_u2[0] * rtb_u2[0] + rtb_u2[1] * rtb_u2[1]) +
      rtb_u2[2] * rtb_u2[2];

    /* Math: '<S252>/Math Function1' incorporates:
     *  DotProduct: '<S252>/Dot Product1'
     *
     * About '<S252>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product4_b_idx_3 < 0.0) {
      rtb_Product4_b_idx_3 = -sqrt(fabs(rtb_Product4_b_idx_3));
    } else {
      rtb_Product4_b_idx_3 = sqrt(rtb_Product4_b_idx_3);
    }

    /* End of Math: '<S252>/Math Function1' */
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S148>/Subtract1' incorporates:
       *  Constant: '<S148>/Tmp_norm_msl'
       *  Constant: '<S70>/deviation_Tmp'
       */
      Mainframe_B.Tmp_ref = Mainframe_P.deviation_Tmp_Value +
        Mainframe_P.Tmp_norm_msl_Value;

      /* Constant: '<S209>/Constant' */
      Mainframe_B.VectorConcatenate1[0] = Mainframe_P.Constant_Value_ja;

      /* Constant: '<S209>/Constant2' */
      Mainframe_B.VectorConcatenate1[1] = Mainframe_P.Constant2_Value_px;

      /* Product: '<S215>/Product' incorporates:
       *  Constant: '<S213>/c_flat'
       *  Constant: '<S213>/c_rsma'
       *  Constant: '<S215>/Constant'
       *  Sum: '<S215>/Subtract'
       */
      Mainframe_B.Product_n = (Mainframe_P.Constant_Value_ae -
        Mainframe_P.c_flat_Value_j) * Mainframe_P.c_rsma_Value_n;

      /* Product: '<S215>/Product5' */
      rtb_TrigonometricFunction1_j = Mainframe_B.Product_n *
        Mainframe_B.Product_n;

      /* Product: '<S215>/Divide' incorporates:
       *  Constant: '<S213>/c_rsma'
       *  Product: '<S215>/Product4'
       *  Sum: '<S215>/Subtract2'
       */
      Mainframe_B.Divide = (Mainframe_P.c_rsma_Value_n *
                            Mainframe_P.c_rsma_Value_n -
                            rtb_TrigonometricFunction1_j) /
        rtb_TrigonometricFunction1_j;

      /* Product: '<S215>/Product3' incorporates:
       *  Constant: '<S213>/c_flat'
       *  Product: '<S214>/Product3'
       */
      rtb_Product4_b_idx_2 = Mainframe_P.c_flat_Value_j *
        Mainframe_P.c_flat_Value_j;

      /* Sum: '<S215>/Subtract1' incorporates:
       *  Constant: '<S213>/c_flat'
       *  Gain: '<S215>/Gain'
       *  Product: '<S215>/Product3'
       */
      Mainframe_B.Subtract1 = Mainframe_P.Gain_Gain_he *
        Mainframe_P.c_flat_Value_j - rtb_Product4_b_idx_2;

      /* Sum: '<S214>/Subtract' incorporates:
       *  Constant: '<S213>/c_flat'
       *  Gain: '<S214>/Gain'
       */
      Mainframe_B.Subtract = Mainframe_P.Gain_Gain_pd *
        Mainframe_P.c_flat_Value_j - rtb_Product4_b_idx_2;
    }

    /* Switch: '<S209>/Switch' incorporates:
     *  Constant: '<S209>/Constant1'
     */
    if (Mainframe_P.Constant1_Value_hf > Mainframe_P.Switch_Threshold_f) {
      /* Gain: '<S209>/Gain' */
      Mainframe_B.VectorConcatenate1[2] = Mainframe_P.Gain_Gain_im *
        Mainframe_B.x_d[2];
      Mainframe_B.Switch[0] = Mainframe_B.VectorConcatenate1[0];
      Mainframe_B.Switch[1] = Mainframe_B.VectorConcatenate1[1];
      Mainframe_B.Switch[2] = Mainframe_B.VectorConcatenate1[2];
    } else {
      /* Product: '<S209>/Product' incorporates:
       *  Math: '<S209>/Math Function'
       */
      for (i = 0; i < 3; i++) {
        rtb_IntegratorSecondOrderLimited_o2_a[i] = rtb_VectorConcatenate3[3 * i
          + 2] * Mainframe_B.x_d[2] + (rtb_VectorConcatenate3[3 * i + 1] *
          Mainframe_B.x_d[1] + rtb_VectorConcatenate3[3 * i] * Mainframe_B.x_d[0]);
      }

      /* End of Product: '<S209>/Product' */

      /* Sqrt: '<S215>/Sqrt' incorporates:
       *  Product: '<S215>/Product1'
       *  Product: '<S215>/Product2'
       *  Sqrt: '<S214>/Sqrt'
       *  Sum: '<S215>/Add'
       */
      rtb_Product4_b_idx_2 = sqrt(rtb_IntegratorSecondOrderLimited_o2_a[0] *
        rtb_IntegratorSecondOrderLimited_o2_a[0] +
        rtb_IntegratorSecondOrderLimited_o2_a[1] *
        rtb_IntegratorSecondOrderLimited_o2_a[1]);

      /* Trigonometry: '<S215>/Trigonometric Function' incorporates:
       *  Constant: '<S213>/c_rsma'
       *  Product: '<S215>/Divide1'
       *  Product: '<S215>/Product6'
       *  Product: '<S215>/Product7'
       *  Sqrt: '<S215>/Sqrt'
       */
      rtb_Sqrt_c = atan(rtb_IntegratorSecondOrderLimited_o2_a[2] *
                        Mainframe_P.c_rsma_Value_n / (rtb_Product4_b_idx_2 *
        Mainframe_B.Product_n));

      /* Trigonometry: '<S215>/Trigonometric Function3' */
      rtb_lat = cos(rtb_Sqrt_c);

      /* Trigonometry: '<S215>/Trigonometric Function2' */
      rtb_Sqrt_c = sin(rtb_Sqrt_c);

      /* Trigonometry: '<S215>/Trigonometric Function1' incorporates:
       *  Constant: '<S213>/c_rsma'
       *  Product: '<S215>/Divide2'
       *  Product: '<S215>/Product10'
       *  Product: '<S215>/Product11'
       *  Product: '<S215>/Product8'
       *  Product: '<S215>/Product9'
       *  Sqrt: '<S215>/Sqrt'
       *  Sum: '<S215>/Add1'
       *  Sum: '<S215>/Subtract3'
       */
      rtb_lat = atan((rtb_Sqrt_c * rtb_Sqrt_c * rtb_Sqrt_c * (Mainframe_B.Divide
        * Mainframe_B.Product_n) + rtb_IntegratorSecondOrderLimited_o2_a[2]) /
                     (rtb_Product4_b_idx_2 - rtb_lat * rtb_lat * rtb_lat *
                      (Mainframe_B.Subtract1 * Mainframe_P.c_rsma_Value_n)));

      /* Trigonometry: '<S214>/Trigonometric Function' */
      rtb_Sqrt_c = sin(rtb_lat);

      /* Sqrt: '<S214>/Sqrt1' incorporates:
       *  Constant: '<S214>/Constant'
       *  Product: '<S214>/Product5'
       *  Sum: '<S214>/Subtract1'
       */
      rtb_Sqrt_c = sqrt(Mainframe_P.Constant_Value_cc - rtb_Sqrt_c * rtb_Sqrt_c *
                        Mainframe_B.Subtract);

      /* Sum: '<S214>/Sum' incorporates:
       *  Constant: '<S213>/c_rsma'
       *  Product: '<S214>/Product'
       *  Product: '<S214>/Product4'
       *  Trigonometry: '<S214>/cos(latGD)'
       */
      Mainframe_B.Switch[2] = rtb_Product4_b_idx_2 / cos(rtb_lat) -
        Mainframe_P.c_rsma_Value_n / rtb_Sqrt_c;

      /* SignalConversion generated from: '<S209>/Vector Concatenate' */
      Mainframe_B.Switch[1] = rtb_lat;

      /* Trigonometry: '<S213>/Trigonometric Function1' */
      Mainframe_B.Switch[0] = rt_atan2d_snf
        (rtb_IntegratorSecondOrderLimited_o2_a[1],
         rtb_IntegratorSecondOrderLimited_o2_a[0]);
    }

    /* End of Switch: '<S209>/Switch' */

    /* Product: '<S146>/Divide' incorporates:
     *  Constant: '<S146>/mean_earth_radius'
     *  Sum: '<S146>/Add'
     */
    rtb_ixk_k = Mainframe_B.Switch[2] / (Mainframe_B.Switch[2] +
      Mainframe_P.geopot_height_mean_earth_radius) *
      Mainframe_P.geopot_height_mean_earth_radius;

    /* Saturate: '<S136>/Saturation' */
    if (rtb_ixk_k > Mainframe_P.Saturation_UpperSat_e) {
      rtb_ixk_k = Mainframe_P.Saturation_UpperSat_e;
    } else {
      if (rtb_ixk_k < Mainframe_P.Saturation_LowerSat_oe) {
        rtb_ixk_k = Mainframe_P.Saturation_LowerSat_oe;
      }
    }

    /* End of Saturate: '<S136>/Saturation' */

    /* Sum: '<S149>/Subtract' incorporates:
     *  Constant: '<S148>/geopotential_height_ref'
     *  Sum: '<S150>/Subtract'
     */
    rtb_Product4_b_idx_2 = rtb_ixk_k - Mainframe_P.geopotential_height_ref_Value;

    /* Sum: '<S150>/Add' incorporates:
     *  Constant: '<S150>/Constant1'
     *  Constant: '<S150>/Tmp_gradient_tropo'
     *  Product: '<S150>/Divide'
     */
    rtb_ixk_k = rtb_Product4_b_idx_2 / Mainframe_B.Tmp_ref *
      Mainframe_P.Tmp_gradient_tropo_Value_p + Mainframe_P.Constant1_Value_pz;

    /* Math: '<S150>/Math Function' incorporates:
     *  Constant: '<S150>/pressure_exponent'
     */
    if ((rtb_ixk_k < 0.0) && (Mainframe_P.pressure_exponent_Value > floor
         (Mainframe_P.pressure_exponent_Value))) {
      rtb_ixk_k = -rt_powd_snf(-rtb_ixk_k, Mainframe_P.pressure_exponent_Value);
    } else {
      rtb_ixk_k = rt_powd_snf(rtb_ixk_k, Mainframe_P.pressure_exponent_Value);
    }

    /* End of Math: '<S150>/Math Function' */
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S148>/Subtract2' incorporates:
       *  Constant: '<S148>/pa_norm_msl'
       *  Constant: '<S70>/deviation_pa_QFH'
       */
      Mainframe_B.pa_ref = Mainframe_P.deviation_pa_QFH_Value +
        Mainframe_P.pa_norm_msl_Value;
    }

    /* Product: '<S115>/Product2' incorporates:
     *  Constant: '<S115>/Constant2'
     *  Constant: '<S145>/specific_gas_constant'
     *  Constant: '<S149>/Tmp_gradient_tropo'
     *  Constant: '<S248>/Constant'
     *  Math: '<S248>/Math Function1'
     *  Product: '<S145>/Divide'
     *  Product: '<S149>/Product'
     *  Product: '<S150>/Product'
     *  Product: '<S248>/Product1'
     *  Sum: '<S149>/Add'
     *  Sum: '<S149>/Subtract'
     */
    rtb_Product4_b_idx_2 = 1.0 / (Mainframe_B.Tmp_ref + rtb_Product4_b_idx_2 *
      Mainframe_P.Tmp_gradient_tropo_Value) * (rtb_ixk_k * Mainframe_B.pa_ref) /
      Mainframe_P.specific_gas_constant_Value * (rtb_Product4_b_idx_3 *
      rtb_Product4_b_idx_3 * Mainframe_P.Constant_Value_e) *
      Mainframe_P.Constant2_Value_jd;

    /* Product: '<S115>/Product' incorporates:
     *  Constant: '<S119>/Constant'
     *  Constant: '<S120>/Constant'
     *  Constant: '<S121>/Constant'
     *  Gain: '<S119>/Gain2'
     *  Gain: '<S119>/Gain3'
     *  Gain: '<S119>/Gain4'
     *  Gain: '<S119>/Gain5'
     *  Gain: '<S119>/Gain6'
     *  Gain: '<S119>/Gain7'
     *  Gain: '<S120>/Gain'
     *  Gain: '<S120>/Gain1'
     *  Gain: '<S121>/Gain'
     *  Gain: '<S121>/Gain1'
     *  Product: '<S119>/Product'
     *  Product: '<S119>/Product2'
     *  Product: '<S119>/Product3'
     *  Product: '<S119>/Product4'
     *  Sum: '<S119>/Sum'
     *  Sum: '<S119>/Sum1'
     *  Sum: '<S119>/Sum3'
     *  Sum: '<S120>/Sum'
     *  Sum: '<S121>/Sum'
     */
    rtb_wEIE[0] = (((((rtb_Switch_j * rtb_Switch_j * Mainframe_P.Gain2_Gain_h +
                       Mainframe_P.Gain3_Gain_l * rtb_Switch_j) +
                      Mainframe_P.Constant_Value_od) + (rtb_Product4_b_idx_1 *
      rtb_Product4_b_idx_1 * Mainframe_P.Gain4_Gain_j + Mainframe_P.Gain5_Gain_a
      * rtb_Product4_b_idx_1)) + rtb_afinB[1] * rtb_afinB[1] *
                    Mainframe_P.Gain6_Gain_a) + rtb_afinB[0] * rtb_afinB[0] *
                   Mainframe_P.Gain7_Gain_b) * rtb_Product4_b_idx_2;
    rtb_wEIE[1] = ((Mainframe_P.Gain_Gain_mn * rtb_Product4_b_idx_1 +
                    Mainframe_P.Constant_Value_mq) + Mainframe_P.Gain1_Gain_o *
                   rtb_afinB[2]) * rtb_Product4_b_idx_2;
    rtb_wEIE[2] = ((Mainframe_P.Gain_Gain_px * rtb_Switch_j +
                    Mainframe_P.Constant_Value_kb) + Mainframe_P.Gain1_Gain_ov *
                   rtb_afinB[1]) * rtb_Product4_b_idx_2;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Switch: '<S126>/Switch1' incorporates:
       *  Constant: '<S126>/Constant'
       *  Constant: '<S126>/Constant2'
       *  Constant: '<S127>/c_flat'
       *  Constant: '<S127>/c_rsma'
       *  Constant: '<S128>/Constant'
       *  Gain: '<S126>/Gain'
       *  Gain: '<S128>/Gain'
       *  Product: '<S128>/Product'
       *  Product: '<S128>/Product4'
       *  Product: '<S128>/Product5'
       *  Sqrt: '<S128>/Sqrt1'
       *  Sum: '<S128>/Subtract'
       *  Sum: '<S128>/Subtract1'
       *  Sum: '<S128>/Sum'
       *  Trigonometry: '<S128>/cos(latGD)'
       */
      if (Mainframe_P.Constant2_Value_jj > Mainframe_P.Switch1_Threshold) {
        Mainframe_B.hBE_0 = Mainframe_P.Gain_Gain_a *
          Mainframe_P.Constant_Value_es[2];
      } else {
        /* Sqrt: '<S129>/Sqrt' incorporates:
         *  Constant: '<S126>/Constant'
         *  Product: '<S129>/Product1'
         *  Product: '<S129>/Product2'
         *  Sqrt: '<S128>/Sqrt'
         *  Sum: '<S129>/Add'
         */
        rtb_lat = sqrt(Mainframe_P.Constant_Value_es[0] *
                       Mainframe_P.Constant_Value_es[0] +
                       Mainframe_P.Constant_Value_es[1] *
                       Mainframe_P.Constant_Value_es[1]);

        /* Product: '<S129>/Product' incorporates:
         *  Constant: '<S127>/c_flat'
         *  Constant: '<S127>/c_rsma'
         *  Constant: '<S129>/Constant'
         *  Sum: '<S129>/Subtract'
         */
        rtb_Sqrt_c = (Mainframe_P.Constant_Value - Mainframe_P.c_flat_Value) *
          Mainframe_P.c_rsma_Value;

        /* Trigonometry: '<S129>/Trigonometric Function' incorporates:
         *  Constant: '<S126>/Constant'
         *  Constant: '<S127>/c_rsma'
         *  Product: '<S129>/Divide1'
         *  Product: '<S129>/Product6'
         *  Product: '<S129>/Product7'
         *  Sqrt: '<S129>/Sqrt'
         */
        rtb_Sqrt_cv = atan(Mainframe_P.Constant_Value_es[2] *
                           Mainframe_P.c_rsma_Value / (rtb_lat * rtb_Sqrt_c));

        /* Trigonometry: '<S129>/Trigonometric Function3' */
        rtb_Product2_l = cos(rtb_Sqrt_cv);

        /* Product: '<S129>/Product9' */
        rtb_ixk_k = rtb_Product2_l * rtb_Product2_l * rtb_Product2_l;

        /* Trigonometry: '<S129>/Trigonometric Function2' */
        rtb_Sqrt_cv = sin(rtb_Sqrt_cv);

        /* Product: '<S129>/Product5' */
        rtb_Product2_l = rtb_Sqrt_c * rtb_Sqrt_c;

        /* Product: '<S129>/Product10' incorporates:
         *  Constant: '<S127>/c_rsma'
         *  Product: '<S129>/Divide'
         *  Product: '<S129>/Product4'
         *  Product: '<S129>/Product8'
         *  Sum: '<S129>/Subtract2'
         */
        rtb_Sqrt_c = (Mainframe_P.c_rsma_Value * Mainframe_P.c_rsma_Value -
                      rtb_Product2_l) / rtb_Product2_l * rtb_Sqrt_c *
          (rtb_Sqrt_cv * rtb_Sqrt_cv * rtb_Sqrt_cv);

        /* Sum: '<S129>/Add1' incorporates:
         *  Constant: '<S126>/Constant'
         */
        rtb_Sqrt_c += Mainframe_P.Constant_Value_es[2];

        /* Product: '<S129>/Product3' incorporates:
         *  Constant: '<S127>/c_flat'
         *  Product: '<S128>/Product3'
         */
        rtb_T_sim_glbl = Mainframe_P.c_flat_Value * Mainframe_P.c_flat_Value;

        /* Trigonometry: '<S129>/Trigonometric Function1' incorporates:
         *  Constant: '<S127>/c_flat'
         *  Constant: '<S127>/c_rsma'
         *  Gain: '<S129>/Gain'
         *  Product: '<S129>/Divide2'
         *  Product: '<S129>/Product11'
         *  Product: '<S129>/Product3'
         *  Sqrt: '<S129>/Sqrt'
         *  Sum: '<S129>/Subtract1'
         *  Sum: '<S129>/Subtract3'
         */
        rtb_Product2_l = atan(rtb_Sqrt_c / (rtb_lat - (Mainframe_P.Gain_Gain_b *
          Mainframe_P.c_flat_Value - rtb_T_sim_glbl) * Mainframe_P.c_rsma_Value *
          rtb_ixk_k));

        /* Trigonometry: '<S128>/Trigonometric Function' */
        rtb_Sqrt_cv = sin(rtb_Product2_l);
        Mainframe_B.hBE_0 = rtb_lat / cos(rtb_Product2_l) -
          Mainframe_P.c_rsma_Value / sqrt(Mainframe_P.Constant_Value_l -
          (Mainframe_P.Gain_Gain * Mainframe_P.c_flat_Value - rtb_T_sim_glbl) *
          (rtb_Sqrt_cv * rtb_Sqrt_cv));
      }

      /* End of Switch: '<S126>/Switch1' */

      /* SignalConversion generated from: '<S124>/Vector Concatenate' incorporates:
       *  Constant: '<S124>/Constant3'
       */
      Mainframe_B.VectorConcatenate[0] = Mainframe_P.Constant3_Value;

      /* SignalConversion generated from: '<S124>/Vector Concatenate' incorporates:
       *  Constant: '<S124>/Constant3'
       */
      Mainframe_B.VectorConcatenate[1] = Mainframe_P.Constant3_Value;

      /* SignalConversion generated from: '<S124>/Vector Concatenate' incorporates:
       *  Constant: '<S124>/Constant3'
       */
      Mainframe_B.VectorConcatenate[2] = Mainframe_P.Constant3_Value;

      /* Constant: '<S184>/Constant8' */
      Mainframe_B.Constant8_a[0] = Mainframe_P.Constant8_Value_el[0];
      Mainframe_B.Constant8_a[1] = Mainframe_P.Constant8_Value_el[1];
      Mainframe_B.Constant8_a[2] = Mainframe_P.Constant8_Value_el[2];
      Mainframe_B.Constant8_a[3] = Mainframe_P.Constant8_Value_el[3];
    }

    /* Switch: '<S124>/Switch' incorporates:
     *  Constant: '<S124>/Constant1'
     *  Sum: '<S124>/Subtract'
     */
    if ((Mainframe_B.Switch[2] + Mainframe_P.Constant1_Value_hj) -
        Mainframe_B.hBE_0 > Mainframe_P.Switch_Threshold_a) {
      rtb_Sum1_e[0] = rtb_wEIE[0];
      rtb_Sum1_e[1] = rtb_wEIE[1];
      rtb_Sum1_e[2] = rtb_wEIE[2];
    } else {
      rtb_Sum1_e[0] = Mainframe_B.VectorConcatenate[0];
      rtb_Sum1_e[1] = Mainframe_B.VectorConcatenate[1];
      rtb_Sum1_e[2] = Mainframe_B.VectorConcatenate[2];
    }

    /* End of Switch: '<S124>/Switch' */

    /* Integrator: '<S184>/integration_eom' */
    if (Mainframe_DW.integration_eom_IWORK_g != 0) {
      Mainframe_X.integration_eom_CSTATE_k[0] = Mainframe_B.Constant8_a[0];
      Mainframe_X.integration_eom_CSTATE_k[1] = Mainframe_B.Constant8_a[1];
      Mainframe_X.integration_eom_CSTATE_k[2] = Mainframe_B.Constant8_a[2];
      Mainframe_X.integration_eom_CSTATE_k[3] = Mainframe_B.Constant8_a[3];
    }

    /* Sum: '<S178>/Add' incorporates:
     *  Constant: '<S178>/Q_1'
     *  Constant: '<S178>/Q_2'
     *  Constant: '<S178>/Q_3'
     *  Constant: '<S178>/Q_4'
     *  Integrator: '<S183>/integration_eom'
     *  Product: '<S178>/Product'
     *  Product: '<S178>/Product1'
     *  Product: '<S178>/Product2'
     *  Product: '<S178>/Product3'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_p[i] *
                 Mainframe_X.integration_eom_CSTATE_o[0] +
                 Mainframe_P.Q_2_Value_c[i] *
                 Mainframe_X.integration_eom_CSTATE_o[1]) +
                Mainframe_P.Q_3_Value_h[i] *
                Mainframe_X.integration_eom_CSTATE_o[2]) +
        Mainframe_P.Q_4_Value_g[i] * Mainframe_X.integration_eom_CSTATE_o[3];
    }

    /* End of Sum: '<S178>/Add' */

    /* Product: '<S178>/Product8' incorporates:
     *  Integrator: '<S184>/integration_eom'
     */
    for (i = 0; i < 4; i++) {
      rtb_ixk_k = tmp[i + 12] * Mainframe_X.integration_eom_CSTATE_k[3] + (tmp[i
        + 8] * Mainframe_X.integration_eom_CSTATE_k[2] + (tmp[i + 4] *
        Mainframe_X.integration_eom_CSTATE_k[1] + tmp[i] *
        Mainframe_X.integration_eom_CSTATE_k[0]));
      rtb_q_conj[i] = rtb_ixk_k;
    }

    /* End of Product: '<S178>/Product8' */

    /* Sum: '<S181>/Add' incorporates:
     *  Product: '<S181>/Product1'
     *  Product: '<S181>/Product2'
     *  Product: '<S181>/Product3'
     *  Product: '<S181>/Product4'
     */
    rtb_ixk_k = ((rtb_q_conj[0] * rtb_q_conj[0] + rtb_q_conj[1] * rtb_q_conj[1])
                 + rtb_q_conj[2] * rtb_q_conj[2]) + rtb_q_conj[3] * rtb_q_conj[3];

    /* Math: '<S181>/Math Function'
     *
     * About '<S181>/Math Function':
     *  Operator: sqrt
     */
    if (rtb_ixk_k < 0.0) {
      rtb_ixk_k = -sqrt(fabs(rtb_ixk_k));
    } else {
      rtb_ixk_k = sqrt(rtb_ixk_k);
    }

    /* End of Math: '<S181>/Math Function' */

    /* Product: '<S181>/Product' */
    rtb_q_conj[0] /= rtb_ixk_k;
    rtb_q_conj[1] /= rtb_ixk_k;
    rtb_q_conj[2] /= rtb_ixk_k;
    rtb_ixk_k = rtb_q_conj[3] / rtb_ixk_k;

    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S178>/Constant'
     *  Constant: '<S178>/Constant1'
     */
    if (rtb_ixk_k >= Mainframe_P.Switch_Threshold_i) {
      rtb_Sqrt_cv = Mainframe_P.Constant_Value_p0;
    } else {
      rtb_Sqrt_cv = Mainframe_P.Constant1_Value_jf;
    }

    /* End of Switch: '<S178>/Switch' */

    /* Product: '<S178>/Product4' */
    rtb_q_conj[0] *= rtb_Sqrt_cv;
    rtb_q_conj[1] *= rtb_Sqrt_cv;
    rtb_q_conj[2] *= rtb_Sqrt_cv;
    rtb_ixk_k *= rtb_Sqrt_cv;

    /* Gain: '<S175>/Gain1' */
    rtb_d_qEI[0] = Mainframe_P.Gain1_Gain_n * rtb_q_conj[0];
    rtb_d_qEI[1] = Mainframe_P.Gain1_Gain_n * rtb_q_conj[1];
    rtb_d_qEI[2] = Mainframe_P.Gain1_Gain_n * rtb_q_conj[2];

    /* Sum: '<S176>/Add' incorporates:
     *  Constant: '<S176>/Q_1'
     *  Constant: '<S176>/Q_2'
     *  Constant: '<S176>/Q_3'
     *  Constant: '<S176>/Q_4'
     *  Product: '<S176>/Product'
     *  Product: '<S176>/Product1'
     *  Product: '<S176>/Product2'
     *  Product: '<S176>/Product3'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_g[i] * rtb_d_qEI[0] +
                 Mainframe_P.Q_2_Value_h[i] * rtb_d_qEI[1]) +
                Mainframe_P.Q_3_Value_h3[i] * rtb_d_qEI[2]) +
        Mainframe_P.Q_4_Value_e[i] * rtb_ixk_k;
    }

    /* End of Sum: '<S176>/Add' */

    /* Product: '<S176>/Product8' */
    for (i = 0; i < 4; i++) {
      rtb_Sqrt_c = tmp[i + 12] * rtb_Product_d + (tmp[i + 8] *
        rtb_Product_b_idx_2 + (tmp[i + 4] * rtb_Product_b_idx_1 + tmp[i] *
        rtb_Product_b_idx_0));
      rtb_d_qEI[i] = rtb_Sqrt_c;
    }

    /* End of Product: '<S176>/Product8' */

    /* Sum: '<S179>/Add' incorporates:
     *  Product: '<S179>/Product1'
     *  Product: '<S179>/Product2'
     *  Product: '<S179>/Product3'
     *  Product: '<S179>/Product4'
     */
    rtb_Sqrt_cv = ((rtb_d_qEI[0] * rtb_d_qEI[0] + rtb_d_qEI[1] * rtb_d_qEI[1]) +
                   rtb_d_qEI[2] * rtb_d_qEI[2]) + rtb_d_qEI[3] * rtb_d_qEI[3];

    /* Math: '<S179>/Math Function'
     *
     * About '<S179>/Math Function':
     *  Operator: sqrt
     */
    if (rtb_Sqrt_cv < 0.0) {
      rtb_Sqrt_cv = -sqrt(fabs(rtb_Sqrt_cv));
    } else {
      rtb_Sqrt_cv = sqrt(rtb_Sqrt_cv);
    }

    /* End of Math: '<S179>/Math Function' */

    /* Product: '<S179>/Product' */
    rtb_d_qEI[0] /= rtb_Sqrt_cv;
    rtb_d_qEI[1] /= rtb_Sqrt_cv;
    rtb_d_qEI[2] /= rtb_Sqrt_cv;
    rtb_Sqrt_c = rtb_d_qEI[3] / rtb_Sqrt_cv;

    /* Switch: '<S176>/Switch' incorporates:
     *  Constant: '<S176>/Constant'
     *  Constant: '<S176>/Constant1'
     */
    if (rtb_Sqrt_c >= Mainframe_P.Switch_Threshold_a2) {
      rtb_Sqrt_cv = Mainframe_P.Constant_Value_az;
    } else {
      rtb_Sqrt_cv = Mainframe_P.Constant1_Value_hk;
    }

    /* End of Switch: '<S176>/Switch' */

    /* Product: '<S176>/Product4' */
    rtb_d_qEI[0] *= rtb_Sqrt_cv;
    rtb_d_qEI[1] *= rtb_Sqrt_cv;
    rtb_d_qEI[2] *= rtb_Sqrt_cv;
    rtb_Sqrt_c *= rtb_Sqrt_cv;

    /* Math: '<S174>/Math Function1' incorporates:
     *  Math: '<S174>/Math Function5'
     *  Math: '<S174>/Math Function9'
     */
    rtb_lat = rtb_d_qEI[1] * rtb_d_qEI[1];

    /* Math: '<S174>/Math Function' incorporates:
     *  Math: '<S174>/Math Function4'
     *  Math: '<S174>/Math Function8'
     */
    rtb_Sqrt_cv = rtb_d_qEI[0] * rtb_d_qEI[0];

    /* Math: '<S174>/Math Function2' incorporates:
     *  Math: '<S174>/Math Function10'
     *  Math: '<S174>/Math Function6'
     */
    rtb_Product2_l = rtb_d_qEI[2] * rtb_d_qEI[2];

    /* Math: '<S174>/Math Function3' incorporates:
     *  Math: '<S174>/Math Function11'
     *  Math: '<S174>/Math Function7'
     */
    rtb_ixk_k = rtb_Sqrt_c * rtb_Sqrt_c;

    /* Sum: '<S174>/Add' incorporates:
     *  Math: '<S174>/Math Function'
     *  Math: '<S174>/Math Function1'
     *  Math: '<S174>/Math Function2'
     *  Math: '<S174>/Math Function3'
     */
    rtb_VectorConcatenate3[0] = ((rtb_Sqrt_cv - rtb_lat) - rtb_Product2_l) +
      rtb_ixk_k;

    /* Product: '<S174>/Product' incorporates:
     *  Product: '<S174>/Product6'
     */
    rtb_T_sim_glbl = rtb_d_qEI[0] * rtb_d_qEI[1];

    /* Product: '<S174>/Product1' incorporates:
     *  Product: '<S174>/Product7'
     */
    rtb_VectorConcatenate3_tmp_1 = rtb_d_qEI[2] * rtb_Sqrt_c;

    /* Sum: '<S174>/Add1' incorporates:
     *  Gain: '<S174>/Gain1'
     *  Gain: '<S174>/Gain2'
     *  Product: '<S174>/Product'
     *  Product: '<S174>/Product1'
     */
    rtb_VectorConcatenate3[1] = rtb_T_sim_glbl * Mainframe_P.Gain1_Gain_b3 -
      rtb_VectorConcatenate3_tmp_1 * Mainframe_P.Gain2_Gain_fo;

    /* Product: '<S174>/Product8' incorporates:
     *  Product: '<S174>/Product4'
     */
    rtb_VectorConcatenate3_tmp = rtb_d_qEI[0] * rtb_d_qEI[2];

    /* Product: '<S174>/Product9' incorporates:
     *  Product: '<S174>/Product5'
     */
    rtb_VectorConcatenate3_tmp_0 = rtb_d_qEI[1] * rtb_Sqrt_c;

    /* Sum: '<S174>/Add5' incorporates:
     *  Gain: '<S174>/Gain10'
     *  Gain: '<S174>/Gain9'
     *  Product: '<S174>/Product8'
     *  Product: '<S174>/Product9'
     */
    rtb_VectorConcatenate3[2] = rtb_VectorConcatenate3_tmp *
      Mainframe_P.Gain9_Gain_e + rtb_VectorConcatenate3_tmp_0 *
      Mainframe_P.Gain10_Gain_i;

    /* Sum: '<S174>/Add4' incorporates:
     *  Gain: '<S174>/Gain7'
     *  Gain: '<S174>/Gain8'
     */
    rtb_VectorConcatenate3[3] = rtb_T_sim_glbl * Mainframe_P.Gain7_Gain_n +
      rtb_VectorConcatenate3_tmp_1 * Mainframe_P.Gain8_Gain_o;

    /* Sum: '<S174>/Add6' */
    rtb_VectorConcatenate3[4] = ((rtb_lat - rtb_Sqrt_cv) - rtb_Product2_l) +
      rtb_ixk_k;

    /* Product: '<S174>/Product2' incorporates:
     *  Product: '<S174>/Product10'
     */
    rtb_T_sim_glbl = rtb_d_qEI[1] * rtb_d_qEI[2];

    /* Product: '<S174>/Product3' incorporates:
     *  Product: '<S174>/Product11'
     */
    rtb_VectorConcatenate3_tmp_1 = rtb_d_qEI[0] * rtb_Sqrt_c;

    /* Sum: '<S174>/Add2' incorporates:
     *  Gain: '<S174>/Gain3'
     *  Gain: '<S174>/Gain4'
     *  Product: '<S174>/Product2'
     *  Product: '<S174>/Product3'
     */
    rtb_VectorConcatenate3[5] = rtb_T_sim_glbl * Mainframe_P.Gain3_Gain_i -
      rtb_VectorConcatenate3_tmp_1 * Mainframe_P.Gain4_Gain_m;

    /* Sum: '<S174>/Add3' incorporates:
     *  Gain: '<S174>/Gain5'
     *  Gain: '<S174>/Gain6'
     */
    rtb_VectorConcatenate3[6] = rtb_VectorConcatenate3_tmp *
      Mainframe_P.Gain5_Gain_c - rtb_VectorConcatenate3_tmp_0 *
      Mainframe_P.Gain6_Gain_j;

    /* Sum: '<S174>/Add8' incorporates:
     *  Gain: '<S174>/Gain11'
     *  Gain: '<S174>/Gain12'
     */
    rtb_VectorConcatenate3[7] = rtb_T_sim_glbl * Mainframe_P.Gain11_Gain_l +
      rtb_VectorConcatenate3_tmp_1 * Mainframe_P.Gain12_Gain_b;

    /* Sum: '<S174>/Add7' */
    rtb_VectorConcatenate3[8] = ((rtb_Product2_l - rtb_Sqrt_cv) - rtb_lat) +
      rtb_ixk_k;

    /* Saturate: '<S102>/Saturation' */
    if (Mainframe_B.Switch[2] > Mainframe_P.Saturation_UpperSat_l) {
      rtb_Sqrt_cv = Mainframe_P.Saturation_UpperSat_l;
    } else if (Mainframe_B.Switch[2] < Mainframe_P.Saturation_LowerSat_f) {
      rtb_Sqrt_cv = Mainframe_P.Saturation_LowerSat_f;
    } else {
      rtb_Sqrt_cv = Mainframe_B.Switch[2];
    }

    /* End of Saturate: '<S102>/Saturation' */

    /* Trigonometry: '<S143>/Trigonometric Function' incorporates:
     *  Switch: '<S185>/Switch'
     *  Trigonometry: '<S141>/Trigonometric Function2'
     *  Trigonometry: '<S185>/Trigonometric Function'
     */
    rtb_lat = sin(Mainframe_B.Switch[1]);
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Product: '<S144>/Divide' incorporates:
       *  Constant: '<S143>/WGS84 Semi-major Axis, [m]'
       *  Constant: '<S143>/WGS84 Semi-minor Axis, [m]'
       *  Sum: '<S144>/Add'
       */
      rtb_TrigonometricFunction1_j = (Mainframe_P.WGS84SemimajorAxism_Value -
        Mainframe_P.WGS84SemiminorAxism_Value) /
        Mainframe_P.WGS84SemimajorAxism_Value;

      /* Product: '<S144>/Divide1' incorporates:
       *  Constant: '<S144>/a2'
       *  Sum: '<S144>/Add1'
       */
      rtb_TrigonometricFunction1_j *= Mainframe_P.a2_Value -
        rtb_TrigonometricFunction1_j;

      /* Sqrt: '<S144>/Sqrt' */
      rtb_TrigonometricFunction1_j = sqrt(rtb_TrigonometricFunction1_j);

      /* Product: '<S143>/Divide' */
      Mainframe_B.e2 = rtb_TrigonometricFunction1_j *
        rtb_TrigonometricFunction1_j;

      /* Sum: '<S141>/Add1' incorporates:
       *  Constant: '<S141>/Constant'
       *  Product: '<S141>/Divide2'
       */
      Mainframe_B.Add1 = Mainframe_P.Constant_Value_kc -
        rtb_TrigonometricFunction1_j * rtb_TrigonometricFunction1_j;
    }

    /* Product: '<S143>/Divide3' incorporates:
     *  Constant: '<S143>/WGS84 Semi-major Axis, [m]'
     *  Constant: '<S143>/a3'
     *  Product: '<S143>/Divide1'
     *  Product: '<S143>/Divide2'
     *  Sqrt: '<S143>/Sqrt'
     *  Sum: '<S143>/Add2'
     *  Trigonometry: '<S143>/Trigonometric Function'
     */
    rtb_Product2_l = 1.0 / sqrt(Mainframe_P.a3_Value - rtb_lat * rtb_lat *
      Mainframe_B.e2) * Mainframe_P.WGS84SemimajorAxism_Value;

    /* Sum: '<S141>/Add3' */
    rtb_ixk_k = rtb_Sqrt_cv + rtb_Product2_l;

    /* Trigonometry: '<S141>/Trigonometric Function3' incorporates:
     *  Switch: '<S185>/Switch'
     *  Trigonometry: '<S185>/Trigonometric Function1'
     */
    rtb_Sqrt_c = cos(Mainframe_B.Switch[1]);

    /* Trigonometry: '<S141>/Trigonometric Function1' incorporates:
     *  MATLAB Function: '<S135>/WGS84_Gravity_Implementation'
     */
    rtb_IntegratorSecondOrderLimited_o2_h_tmp = cos(Mainframe_B.Switch[0]);

    /* SignalConversion generated from: '<S142>/ SFunction ' incorporates:
     *  MATLAB Function: '<S135>/WGS84_Gravity_Implementation'
     *  Product: '<S141>/Divide'
     *  Trigonometry: '<S141>/Trigonometric Function1'
     *  Trigonometry: '<S141>/Trigonometric Function3'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[0] = rtb_ixk_k *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp * rtb_Sqrt_c;

    /* Trigonometry: '<S141>/Trigonometric Function' incorporates:
     *  MATLAB Function: '<S135>/WGS84_Gravity_Implementation'
     */
    rtb_IntegratorSecondOrderLimited_o2_h_tmp_0 = sin(Mainframe_B.Switch[0]);

    /* SignalConversion generated from: '<S142>/ SFunction ' incorporates:
     *  MATLAB Function: '<S135>/WGS84_Gravity_Implementation'
     *  Product: '<S141>/Divide1'
     *  Product: '<S141>/Divide3'
     *  Product: '<S141>/Divide4'
     *  Sum: '<S141>/Add2'
     *  Trigonometry: '<S141>/Trigonometric Function'
     *  Trigonometry: '<S141>/Trigonometric Function3'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[1] = rtb_ixk_k *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp_0 * rtb_Sqrt_c;
    rtb_IntegratorSecondOrderLimited_o2_a[2] = (rtb_Product2_l *
      Mainframe_B.Add1 + rtb_Sqrt_cv) * rtb_lat;

    /* MATLAB Function: '<S135>/WGS84_Gravity_Implementation' */
    q_0 = Mainframe_P.WGS84_Gravity_Implementation_c_b_WGS *
      Mainframe_P.WGS84_Gravity_Implementation_c_b_WGS;
    rtb_VectorConcatenate3_tmp_1 =
      Mainframe_P.WGS84_Gravity_Implementation_c_rsma *
      Mainframe_P.WGS84_Gravity_Implementation_c_rsma;
    rtb_TrigonometricFunction1_j = sqrt(rtb_VectorConcatenate3_tmp_1 - q_0);
    rtb_T_sim_glbl = rtb_TrigonometricFunction1_j * rtb_TrigonometricFunction1_j;
    rtb_Product2_mq_tmp = rtb_IntegratorSecondOrderLimited_o2_a[2] *
      rtb_IntegratorSecondOrderLimited_o2_a[2];
    rtb_Product9_k = rtb_IntegratorSecondOrderLimited_o2_a[0] *
      rtb_IntegratorSecondOrderLimited_o2_a[0] +
      rtb_IntegratorSecondOrderLimited_o2_a[1] *
      rtb_IntegratorSecondOrderLimited_o2_a[1];
    rtb_Product2_l = (rtb_Product9_k + rtb_Product2_mq_tmp) - rtb_T_sim_glbl;
    rtb_Product2_l = sqrt((sqrt(rtb_T_sim_glbl * 4.0 * rtb_Product2_mq_tmp /
      (rtb_Product2_l * rtb_Product2_l) + 1.0) + 1.0) * (rtb_Product2_l * 0.5));
    rtb_VectorConcatenate3_tmp = rtb_Product2_l * rtb_Product2_l;
    rtb_VectorConcatenate3_tmp_0 = rtb_VectorConcatenate3_tmp + rtb_T_sim_glbl;
    rtb_ixk_k = sqrt(rtb_VectorConcatenate3_tmp_0);
    beta = rt_atan2d_snf(rtb_IntegratorSecondOrderLimited_o2_a[2] * rtb_ixk_k,
                         sqrt(rtb_Product9_k) * rtb_Product2_l);
    rtb_Product9_k = sin(beta);
    w_tmp = rtb_Product9_k * rtb_Product9_k;
    w = sqrt((rtb_T_sim_glbl * w_tmp + rtb_VectorConcatenate3_tmp) /
             rtb_VectorConcatenate3_tmp_0);
    q_0 = ((q_0 * 3.0 / rtb_T_sim_glbl + 1.0) * rt_atan2d_snf
           (rtb_TrigonometricFunction1_j,
            Mainframe_P.WGS84_Gravity_Implementation_c_b_WGS) - 3.0 *
           Mainframe_P.WGS84_Gravity_Implementation_c_b_WGS /
           rtb_TrigonometricFunction1_j) * 0.5;
    c_x_tmp = cos(beta);
    rtb_gamma_R_tmp = rt_atan2d_snf(rtb_TrigonometricFunction1_j, rtb_Product2_l);
    rtb_Product2_mq[0] = rtb_Product2_l / (w * rtb_ixk_k) * c_x_tmp *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp;
    rtb_Product2_mq[3] = -1.0 / w * rtb_Product9_k *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp;
    rtb_Product2_mq[6] = -rtb_IntegratorSecondOrderLimited_o2_h_tmp_0;
    rtb_Product2_mq_tmp = rtb_Product2_l / (sqrt(rtb_Product2_l * rtb_Product2_l
      + rtb_TrigonometricFunction1_j * rtb_TrigonometricFunction1_j) * w) * cos
      (beta);
    rtb_Product2_mq[1] = rtb_Product2_mq_tmp *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp_0;
    rtb_Product2_mq[4] = -1.0 / w * sin(beta) *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp_0;
    rtb_Product2_mq[7] = rtb_IntegratorSecondOrderLimited_o2_h_tmp;
    rtb_Product2_mq[2] = 1.0 / w * rtb_Product9_k;
    rtb_Product2_mq[5] = rtb_Product2_mq_tmp;
    rtb_Product2_mq[8] = 0.0;
    rtb_IntegratorSecondOrderLimited_o2_h_tmp =
      Mainframe_P.WGS84_Gravity_Implementation_c_rot *
      Mainframe_P.WGS84_Gravity_Implementation_c_rot;
    rtb_IntegratorSecondOrderLimited_o2_h_tmp_0 =
      Mainframe_P.WGS84_Gravitation_flg_omega_enabled / w *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp;
    rtb_Product2_mq_tmp = (((rtb_VectorConcatenate3_tmp / rtb_T_sim_glbl + 1.0) *
      3.0 * (1.0 - rtb_Product2_l / rtb_TrigonometricFunction1_j *
             rtb_gamma_R_tmp) - 1.0) *
      (rtb_IntegratorSecondOrderLimited_o2_h_tmp * rtb_VectorConcatenate3_tmp_1 *
       rtb_TrigonometricFunction1_j / rtb_VectorConcatenate3_tmp_0) / q_0 *
      (w_tmp * 0.5 - 0.16666666666666666) +
      Mainframe_P.WGS84_Gravity_Implementation_c_grav /
      rtb_VectorConcatenate3_tmp_0) * (-1.0 / w) +
      rtb_IntegratorSecondOrderLimited_o2_h_tmp_0 * rtb_Product2_l * (c_x_tmp *
      c_x_tmp);
    rtb_TrigonometricFunction1_j = ((rtb_VectorConcatenate3_tmp * 3.0 /
      rtb_T_sim_glbl + 1.0) * rtb_gamma_R_tmp - 3.0 * rtb_Product2_l /
      rtb_TrigonometricFunction1_j) * 0.5 * (1.0 / w *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp * rtb_VectorConcatenate3_tmp_1 /
      rtb_VectorConcatenate3_tmp_0) / q_0 * rtb_Product9_k * c_x_tmp -
      rtb_IntegratorSecondOrderLimited_o2_h_tmp_0 * rtb_ixk_k * rtb_Product9_k *
      c_x_tmp;
    for (i = 0; i < 3; i++) {
      rtb_u2[i] = rtb_Product2_mq[i + 6] * 0.0 + (rtb_Product2_mq[i + 3] *
        rtb_TrigonometricFunction1_j + rtb_Product2_mq[i] * rtb_Product2_mq_tmp);
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Switch: '<S165>/Switch1' incorporates:
       *  Constant: '<S165>/Constant'
       *  Constant: '<S165>/Constant2'
       *  Constant: '<S166>/c_flat'
       *  Constant: '<S166>/c_rsma'
       *  Constant: '<S167>/Constant'
       *  Gain: '<S165>/Gain'
       *  Gain: '<S167>/Gain'
       *  Product: '<S167>/Product'
       *  Product: '<S167>/Product4'
       *  Product: '<S167>/Product5'
       *  Sqrt: '<S167>/Sqrt1'
       *  Sum: '<S167>/Subtract'
       *  Sum: '<S167>/Subtract1'
       *  Sum: '<S167>/Sum'
       *  Trigonometry: '<S167>/cos(latGD)'
       */
      if (Mainframe_P.Constant2_Value_d > Mainframe_P.Switch1_Threshold_g) {
        Mainframe_B.hBE_0_i = Mainframe_P.Gain_Gain_bh *
          Mainframe_P.Constant_Value_bh[2];
      } else {
        /* Sqrt: '<S168>/Sqrt' incorporates:
         *  Constant: '<S165>/Constant'
         *  Product: '<S168>/Product1'
         *  Product: '<S168>/Product2'
         *  Sqrt: '<S167>/Sqrt'
         *  Sum: '<S168>/Add'
         */
        rtb_TrigonometricFunction1_j = sqrt(Mainframe_P.Constant_Value_bh[0] *
          Mainframe_P.Constant_Value_bh[0] + Mainframe_P.Constant_Value_bh[1] *
          Mainframe_P.Constant_Value_bh[1]);

        /* Product: '<S168>/Product' incorporates:
         *  Constant: '<S166>/c_flat'
         *  Constant: '<S166>/c_rsma'
         *  Constant: '<S168>/Constant'
         *  Sum: '<S168>/Subtract'
         */
        rtb_Product2_l = (Mainframe_P.Constant_Value_lt -
                          Mainframe_P.c_flat_Value_h) *
          Mainframe_P.c_rsma_Value_a;

        /* Trigonometry: '<S168>/Trigonometric Function' incorporates:
         *  Constant: '<S165>/Constant'
         *  Constant: '<S166>/c_rsma'
         *  Product: '<S168>/Divide1'
         *  Product: '<S168>/Product6'
         *  Product: '<S168>/Product7'
         *  Sqrt: '<S168>/Sqrt'
         */
        rtb_ixk_k = atan(Mainframe_P.Constant_Value_bh[2] *
                         Mainframe_P.c_rsma_Value_a /
                         (rtb_TrigonometricFunction1_j * rtb_Product2_l));

        /* Trigonometry: '<S168>/Trigonometric Function3' */
        beta = cos(rtb_ixk_k);

        /* Product: '<S168>/Product9' */
        rtb_Product9_k = beta * beta * beta;

        /* Trigonometry: '<S168>/Trigonometric Function2' */
        rtb_ixk_k = sin(rtb_ixk_k);

        /* Product: '<S168>/Product5' */
        beta = rtb_Product2_l * rtb_Product2_l;

        /* Product: '<S168>/Product10' incorporates:
         *  Constant: '<S166>/c_rsma'
         *  Product: '<S168>/Divide'
         *  Product: '<S168>/Product4'
         *  Product: '<S168>/Product8'
         *  Sum: '<S168>/Subtract2'
         */
        rtb_Product2_l = (Mainframe_P.c_rsma_Value_a *
                          Mainframe_P.c_rsma_Value_a - beta) / beta *
          rtb_Product2_l * (rtb_ixk_k * rtb_ixk_k * rtb_ixk_k);

        /* Sum: '<S168>/Add1' incorporates:
         *  Constant: '<S165>/Constant'
         */
        rtb_Product2_l += Mainframe_P.Constant_Value_bh[2];

        /* Product: '<S168>/Product3' incorporates:
         *  Constant: '<S166>/c_flat'
         *  Product: '<S167>/Product3'
         */
        rtb_T_sim_glbl = Mainframe_P.c_flat_Value_h * Mainframe_P.c_flat_Value_h;

        /* Trigonometry: '<S168>/Trigonometric Function1' incorporates:
         *  Constant: '<S166>/c_flat'
         *  Constant: '<S166>/c_rsma'
         *  Gain: '<S168>/Gain'
         *  Product: '<S168>/Divide2'
         *  Product: '<S168>/Product11'
         *  Product: '<S168>/Product3'
         *  Sqrt: '<S168>/Sqrt'
         *  Sum: '<S168>/Subtract1'
         *  Sum: '<S168>/Subtract3'
         */
        beta = atan(rtb_Product2_l / (rtb_TrigonometricFunction1_j -
          (Mainframe_P.Gain_Gain_l * Mainframe_P.c_flat_Value_h - rtb_T_sim_glbl)
          * Mainframe_P.c_rsma_Value_a * rtb_Product9_k));

        /* Trigonometry: '<S167>/Trigonometric Function' */
        rtb_ixk_k = sin(beta);
        Mainframe_B.hBE_0_i = rtb_TrigonometricFunction1_j / cos(beta) -
          Mainframe_P.c_rsma_Value_a / sqrt(Mainframe_P.Constant_Value_b -
          (Mainframe_P.Gain_Gain_ab * Mainframe_P.c_flat_Value_h -
           rtb_T_sim_glbl) * (rtb_ixk_k * rtb_ixk_k));
      }

      /* End of Switch: '<S165>/Switch1' */

      /* SignalConversion generated from: '<S164>/Vector Concatenate' incorporates:
       *  Constant: '<S164>/Constant3'
       */
      Mainframe_B.VectorConcatenate_g[0] = Mainframe_P.Constant3_Value_l;

      /* SignalConversion generated from: '<S164>/Vector Concatenate' incorporates:
       *  Constant: '<S164>/Constant3'
       */
      Mainframe_B.VectorConcatenate_g[1] = Mainframe_P.Constant3_Value_l;

      /* SignalConversion generated from: '<S164>/Vector Concatenate' incorporates:
       *  Constant: '<S164>/Constant3'
       */
      Mainframe_B.VectorConcatenate_g[2] = Mainframe_P.Constant3_Value_l;
    }

    /* Switch: '<S164>/Switch' incorporates:
     *  Constant: '<S164>/Constant1'
     *  Sum: '<S164>/Subtract'
     */
    if ((Mainframe_B.Switch[2] + Mainframe_P.Constant1_Value_o) -
        Mainframe_B.hBE_0_i > Mainframe_P.Switch_Threshold_o) {
      /* Sqrt: '<S137>/Sqrt' incorporates:
       *  DotProduct: '<S137>/Dot Product'
       */
      rtb_IntegratorSecondOrderLimited_o2_a[2] = sqrt((rtb_u2[0] * rtb_u2[0] +
        rtb_u2[1] * rtb_u2[1]) + rtb_u2[2] * rtb_u2[2]);

      /* SignalConversion generated from: '<S137>/Vector Concatenate' incorporates:
       *  Constant: '<S137>/Constant1'
       */
      rtb_IntegratorSecondOrderLimited_o2_a[1] = Mainframe_P.Constant1_Value_b4;

      /* SignalConversion generated from: '<S137>/Vector Concatenate' incorporates:
       *  Constant: '<S137>/Constant1'
       */
      rtb_IntegratorSecondOrderLimited_o2_a[0] = Mainframe_P.Constant1_Value_b4;
    } else {
      rtb_IntegratorSecondOrderLimited_o2_a[0] =
        Mainframe_B.VectorConcatenate_g[0];
      rtb_IntegratorSecondOrderLimited_o2_a[1] =
        Mainframe_B.VectorConcatenate_g[1];
      rtb_IntegratorSecondOrderLimited_o2_a[2] =
        Mainframe_B.VectorConcatenate_g[2];
    }

    /* End of Switch: '<S164>/Switch' */

    /* Sum: '<S111>/Subtract' incorporates:
     *  Clock: '<S70>/Clock'
     *  Constant: '<S70>/Constant6'
     *  Sum: '<S194>/Subtract'
     *  Sum: '<S70>/Add'
     */
    rtb_T_sim_glbl = (rtb_jxi_f - Mainframe_B.EnabledSubsystem1_h.DigitalClock)
      - Mainframe_P.Constant6_Value_c;
    rtb_TrigonometricFunction1_j = rtb_T_sim_glbl;

    /* Switch: '<S256>/Switch' incorporates:
     *  Constant: '<S256>/Constant'
     *  Sum: '<S111>/Subtract'
     */
    if (!(rtb_T_sim_glbl > Mainframe_P.Switch_Threshold_op)) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Constant_Value_n;
    }

    /* End of Switch: '<S256>/Switch' */

    /* Switch: '<S256>/Switch1' incorporates:
     *  Lookup_n-D: '<S256>/1-D Lookup Table'
     */
    if (rtb_TrigonometricFunction1_j > Mainframe_P.Switch1_Threshold_j) {
      /* Saturate: '<S256>/Saturation' */
      if (rtb_TrigonometricFunction1_j > Mainframe_P.Saturation_UpperSat_d) {
        rtb_TrigonometricFunction1_j = Mainframe_P.Saturation_UpperSat_d;
      } else {
        if (rtb_TrigonometricFunction1_j < Mainframe_P.Saturation_LowerSat_ee) {
          rtb_TrigonometricFunction1_j = Mainframe_P.Saturation_LowerSat_ee;
        }
      }

      /* End of Saturate: '<S256>/Saturation' */
      rtb_TrigonometricFunction1_j = look1_binlcapw(rtb_TrigonometricFunction1_j,
        Mainframe_P.uDLookupTable_bp01Data, Mainframe_P.uDLookupTable_tableData,
        332U);
    }

    /* End of Switch: '<S256>/Switch1' */

    /* Sum: '<S257>/Add' incorporates:
     *  Constant: '<S256>/Constant1'
     *  Constant: '<S257>/Constant'
     *  Constant: '<S257>/Constant1'
     *  Product: '<S257>/Product'
     *  Sum: '<S256>/Subtract1'
     */
    rtb_Product2_l = (Mainframe_P.Constant1_Value_m +
                      rtb_TrigonometricFunction1_j) *
      Mainframe_P.Constant1_Value_lf + Mainframe_P.Constant_Value_aw;

    /* Product: '<S105>/Product' */
    rtb_IntegratorSecondOrderLimited_o2_a[0] *= rtb_Product2_l;
    rtb_IntegratorSecondOrderLimited_o2_a[1] *= rtb_Product2_l;
    rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[2] * rtb_Product2_l;

    /* Product: '<S104>/Product' incorporates:
     *  Math: '<S104>/Math Function'
     */
    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate_m[i] = rtb_VectorConcatenate3[3 * i + 2] * rtb_ixk_k
        + (rtb_VectorConcatenate3[3 * i + 1] *
           rtb_IntegratorSecondOrderLimited_o2_a[1] + rtb_VectorConcatenate3[3 *
           i] * rtb_IntegratorSecondOrderLimited_o2_a[0]);
    }

    /* End of Product: '<S104>/Product' */
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* MultiPortSwitch: '<S196>/Multiport Switch2' incorporates:
       *  Constant: '<S196>/Constant2'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_3) {
       case 1:
        /* Trigonometry: '<S204>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/thrust_rot_x'
         *  Trigonometry: '<S204>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_x_Value);

        /* Trigonometry: '<S204>/Trigonometric Function3' incorporates:
         *  Constant: '<S195>/thrust_rot_x'
         *  Trigonometry: '<S204>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.thrust_rot_x_Value);

        /* SignalConversion generated from: '<S204>/Matrix Concatenate' incorporates:
         *  Constant: '<S204>/Constant7'
         *  Trigonometry: '<S204>/Trigonometric Function1'
         *  Trigonometry: '<S204>/Trigonometric Function3'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Constant7_Value_a;
        rtb_MultiportSwitch[7] = rtb_ixk_k;
        rtb_MultiportSwitch[8] = beta;

        /* SignalConversion generated from: '<S204>/Matrix Concatenate' incorporates:
         *  Constant: '<S204>/Constant8'
         *  Gain: '<S204>/Gain'
         */
        rtb_MultiportSwitch[3] = Mainframe_P.Constant8_Value_g;
        rtb_MultiportSwitch[4] = beta;
        rtb_MultiportSwitch[5] = Mainframe_P.Gain_Gain_c * rtb_ixk_k;

        /* SignalConversion generated from: '<S204>/Matrix Concatenate' incorporates:
         *  Constant: '<S204>/Constant'
         *  Constant: '<S204>/Constant1'
         *  Constant: '<S204>/Constant2'
         */
        rtb_MultiportSwitch[0] = Mainframe_P.Constant_Value_o;
        rtb_MultiportSwitch[1] = Mainframe_P.Constant1_Value_j;
        rtb_MultiportSwitch[2] = Mainframe_P.Constant2_Value_i;
        break;

       case 2:
        /* Trigonometry: '<S205>/Trigonometric Function3' incorporates:
         *  Constant: '<S195>/thrust_rot_x'
         *  Trigonometry: '<S205>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.thrust_rot_x_Value);

        /* Trigonometry: '<S205>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/thrust_rot_x'
         *  Trigonometry: '<S205>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.thrust_rot_x_Value);

        /* SignalConversion generated from: '<S205>/Matrix Concatenate' incorporates:
         *  Constant: '<S205>/Constant7'
         *  Gain: '<S205>/Gain1'
         *  Trigonometry: '<S205>/Trigonometric Function1'
         *  Trigonometry: '<S205>/Trigonometric Function3'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Gain1_Gain_f * beta;
        rtb_MultiportSwitch[7] = Mainframe_P.Constant7_Value_d;
        rtb_MultiportSwitch[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S205>/Matrix Concatenate' incorporates:
         *  Constant: '<S205>/Constant'
         *  Constant: '<S205>/Constant1'
         *  Constant: '<S205>/Constant2'
         */
        rtb_MultiportSwitch[3] = Mainframe_P.Constant_Value_c;
        rtb_MultiportSwitch[4] = Mainframe_P.Constant1_Value;
        rtb_MultiportSwitch[5] = Mainframe_P.Constant2_Value;

        /* SignalConversion generated from: '<S205>/Matrix Concatenate' incorporates:
         *  Constant: '<S205>/Constant8'
         */
        rtb_MultiportSwitch[0] = rtb_ixk_k;
        rtb_MultiportSwitch[1] = Mainframe_P.Constant8_Value_k;
        rtb_MultiportSwitch[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S206>/Matrix Concatenate' incorporates:
         *  Constant: '<S206>/Constant10'
         *  Constant: '<S206>/Constant11'
         *  Constant: '<S206>/Constant4'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Constant4_Value;
        rtb_MultiportSwitch[7] = Mainframe_P.Constant10_Value;
        rtb_MultiportSwitch[8] = Mainframe_P.Constant11_Value;

        /* Trigonometry: '<S206>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/thrust_rot_x'
         *  Trigonometry: '<S206>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_x_Value);

        /* Trigonometry: '<S206>/Trigonometric Function' incorporates:
         *  Constant: '<S195>/thrust_rot_x'
         *  Trigonometry: '<S206>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.thrust_rot_x_Value);

        /* SignalConversion generated from: '<S206>/Matrix Concatenate' incorporates:
         *  Constant: '<S206>/Constant7'
         *  Trigonometry: '<S206>/Trigonometric Function'
         *  Trigonometry: '<S206>/Trigonometric Function1'
         */
        rtb_MultiportSwitch[3] = rtb_ixk_k;
        rtb_MultiportSwitch[4] = beta;
        rtb_MultiportSwitch[5] = Mainframe_P.Constant7_Value_f;

        /* SignalConversion generated from: '<S206>/Matrix Concatenate' incorporates:
         *  Constant: '<S206>/Constant8'
         *  Gain: '<S206>/Gain'
         */
        rtb_MultiportSwitch[0] = beta;
        rtb_MultiportSwitch[1] = Mainframe_P.Gain_Gain_k * rtb_ixk_k;
        rtb_MultiportSwitch[2] = Mainframe_P.Constant8_Value_a;
        break;
      }

      /* End of MultiPortSwitch: '<S196>/Multiport Switch2' */

      /* MultiPortSwitch: '<S196>/Multiport Switch1' incorporates:
       *  Constant: '<S196>/Constant1'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_2) {
       case 1:
        /* Trigonometry: '<S201>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/thrust_rot_y'
         *  Trigonometry: '<S201>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_y_Value);

        /* Trigonometry: '<S201>/Trigonometric Function3' incorporates:
         *  Constant: '<S195>/thrust_rot_y'
         *  Trigonometry: '<S201>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.thrust_rot_y_Value);

        /* SignalConversion generated from: '<S201>/Matrix Concatenate' incorporates:
         *  Constant: '<S201>/Constant7'
         *  Trigonometry: '<S201>/Trigonometric Function1'
         *  Trigonometry: '<S201>/Trigonometric Function3'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Constant7_Value_o;
        rtb_MultiportSwitch1[7] = rtb_ixk_k;
        rtb_MultiportSwitch1[8] = beta;

        /* SignalConversion generated from: '<S201>/Matrix Concatenate' incorporates:
         *  Constant: '<S201>/Constant8'
         *  Gain: '<S201>/Gain'
         */
        rtb_MultiportSwitch1[3] = Mainframe_P.Constant8_Value_g5;
        rtb_MultiportSwitch1[4] = beta;
        rtb_MultiportSwitch1[5] = Mainframe_P.Gain_Gain_d * rtb_ixk_k;

        /* SignalConversion generated from: '<S201>/Matrix Concatenate' incorporates:
         *  Constant: '<S201>/Constant'
         *  Constant: '<S201>/Constant1'
         *  Constant: '<S201>/Constant2'
         */
        rtb_MultiportSwitch1[0] = Mainframe_P.Constant_Value_hm;
        rtb_MultiportSwitch1[1] = Mainframe_P.Constant1_Value_d;
        rtb_MultiportSwitch1[2] = Mainframe_P.Constant2_Value_io;
        break;

       case 2:
        /* Trigonometry: '<S202>/Trigonometric Function3' incorporates:
         *  Constant: '<S195>/thrust_rot_y'
         *  Trigonometry: '<S202>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.thrust_rot_y_Value);

        /* Trigonometry: '<S202>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/thrust_rot_y'
         *  Trigonometry: '<S202>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.thrust_rot_y_Value);

        /* SignalConversion generated from: '<S202>/Matrix Concatenate' incorporates:
         *  Constant: '<S202>/Constant7'
         *  Gain: '<S202>/Gain1'
         *  Trigonometry: '<S202>/Trigonometric Function1'
         *  Trigonometry: '<S202>/Trigonometric Function3'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Gain1_Gain_c * beta;
        rtb_MultiportSwitch1[7] = Mainframe_P.Constant7_Value_c;
        rtb_MultiportSwitch1[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S202>/Matrix Concatenate' incorporates:
         *  Constant: '<S202>/Constant'
         *  Constant: '<S202>/Constant1'
         *  Constant: '<S202>/Constant2'
         */
        rtb_MultiportSwitch1[3] = Mainframe_P.Constant_Value_h;
        rtb_MultiportSwitch1[4] = Mainframe_P.Constant1_Value_b;
        rtb_MultiportSwitch1[5] = Mainframe_P.Constant2_Value_p;

        /* SignalConversion generated from: '<S202>/Matrix Concatenate' incorporates:
         *  Constant: '<S202>/Constant8'
         */
        rtb_MultiportSwitch1[0] = rtb_ixk_k;
        rtb_MultiportSwitch1[1] = Mainframe_P.Constant8_Value_j5;
        rtb_MultiportSwitch1[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S203>/Matrix Concatenate' incorporates:
         *  Constant: '<S203>/Constant10'
         *  Constant: '<S203>/Constant11'
         *  Constant: '<S203>/Constant4'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Constant4_Value_a;
        rtb_MultiportSwitch1[7] = Mainframe_P.Constant10_Value_f;
        rtb_MultiportSwitch1[8] = Mainframe_P.Constant11_Value_p;

        /* Trigonometry: '<S203>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/thrust_rot_y'
         *  Trigonometry: '<S203>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_y_Value);

        /* Trigonometry: '<S203>/Trigonometric Function' incorporates:
         *  Constant: '<S195>/thrust_rot_y'
         *  Trigonometry: '<S203>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.thrust_rot_y_Value);

        /* SignalConversion generated from: '<S203>/Matrix Concatenate' incorporates:
         *  Constant: '<S203>/Constant7'
         *  Trigonometry: '<S203>/Trigonometric Function'
         *  Trigonometry: '<S203>/Trigonometric Function1'
         */
        rtb_MultiportSwitch1[3] = rtb_ixk_k;
        rtb_MultiportSwitch1[4] = beta;
        rtb_MultiportSwitch1[5] = Mainframe_P.Constant7_Value_j;

        /* SignalConversion generated from: '<S203>/Matrix Concatenate' incorporates:
         *  Constant: '<S203>/Constant8'
         *  Gain: '<S203>/Gain'
         */
        rtb_MultiportSwitch1[0] = beta;
        rtb_MultiportSwitch1[1] = Mainframe_P.Gain_Gain_ii * rtb_ixk_k;
        rtb_MultiportSwitch1[2] = Mainframe_P.Constant8_Value_j;
        break;
      }

      /* End of MultiPortSwitch: '<S196>/Multiport Switch1' */

      /* MultiPortSwitch: '<S196>/Multiport Switch' incorporates:
       *  Constant: '<S196>/Constant'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_1) {
       case 1:
        /* Trigonometry: '<S198>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/Thrust_rot_z'
         *  Trigonometry: '<S198>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.Thrust_rot_z_Value);

        /* Trigonometry: '<S198>/Trigonometric Function3' incorporates:
         *  Constant: '<S195>/Thrust_rot_z'
         *  Trigonometry: '<S198>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.Thrust_rot_z_Value);

        /* SignalConversion generated from: '<S198>/Matrix Concatenate' incorporates:
         *  Constant: '<S198>/Constant7'
         *  Trigonometry: '<S198>/Trigonometric Function1'
         *  Trigonometry: '<S198>/Trigonometric Function3'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Constant7_Value_ih;
        rtb_MultiportSwitch2[7] = rtb_ixk_k;
        rtb_MultiportSwitch2[8] = beta;

        /* SignalConversion generated from: '<S198>/Matrix Concatenate' incorporates:
         *  Constant: '<S198>/Constant8'
         *  Gain: '<S198>/Gain'
         */
        rtb_MultiportSwitch2[3] = Mainframe_P.Constant8_Value_m;
        rtb_MultiportSwitch2[4] = beta;
        rtb_MultiportSwitch2[5] = Mainframe_P.Gain_Gain_dp * rtb_ixk_k;

        /* SignalConversion generated from: '<S198>/Matrix Concatenate' incorporates:
         *  Constant: '<S198>/Constant'
         *  Constant: '<S198>/Constant1'
         *  Constant: '<S198>/Constant2'
         */
        rtb_MultiportSwitch2[0] = Mainframe_P.Constant_Value_h1;
        rtb_MultiportSwitch2[1] = Mainframe_P.Constant1_Value_l;
        rtb_MultiportSwitch2[2] = Mainframe_P.Constant2_Value_f;
        break;

       case 2:
        /* Trigonometry: '<S199>/Trigonometric Function3' incorporates:
         *  Constant: '<S195>/Thrust_rot_z'
         *  Trigonometry: '<S199>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.Thrust_rot_z_Value);

        /* Trigonometry: '<S199>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/Thrust_rot_z'
         *  Trigonometry: '<S199>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.Thrust_rot_z_Value);

        /* SignalConversion generated from: '<S199>/Matrix Concatenate' incorporates:
         *  Constant: '<S199>/Constant7'
         *  Gain: '<S199>/Gain1'
         *  Trigonometry: '<S199>/Trigonometric Function1'
         *  Trigonometry: '<S199>/Trigonometric Function3'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Gain1_Gain_h * beta;
        rtb_MultiportSwitch2[7] = Mainframe_P.Constant7_Value_i;
        rtb_MultiportSwitch2[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S199>/Matrix Concatenate' incorporates:
         *  Constant: '<S199>/Constant'
         *  Constant: '<S199>/Constant1'
         *  Constant: '<S199>/Constant2'
         */
        rtb_MultiportSwitch2[3] = Mainframe_P.Constant_Value_lv;
        rtb_MultiportSwitch2[4] = Mainframe_P.Constant1_Value_h;
        rtb_MultiportSwitch2[5] = Mainframe_P.Constant2_Value_l;

        /* SignalConversion generated from: '<S199>/Matrix Concatenate' incorporates:
         *  Constant: '<S199>/Constant8'
         */
        rtb_MultiportSwitch2[0] = rtb_ixk_k;
        rtb_MultiportSwitch2[1] = Mainframe_P.Constant8_Value_cm;
        rtb_MultiportSwitch2[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S200>/Matrix Concatenate' incorporates:
         *  Constant: '<S200>/Constant10'
         *  Constant: '<S200>/Constant11'
         *  Constant: '<S200>/Constant4'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Constant4_Value_o;
        rtb_MultiportSwitch2[7] = Mainframe_P.Constant10_Value_g;
        rtb_MultiportSwitch2[8] = Mainframe_P.Constant11_Value_o;

        /* Trigonometry: '<S200>/Trigonometric Function1' incorporates:
         *  Constant: '<S195>/Thrust_rot_z'
         *  Trigonometry: '<S200>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.Thrust_rot_z_Value);

        /* Trigonometry: '<S200>/Trigonometric Function' incorporates:
         *  Constant: '<S195>/Thrust_rot_z'
         *  Trigonometry: '<S200>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.Thrust_rot_z_Value);

        /* SignalConversion generated from: '<S200>/Matrix Concatenate' incorporates:
         *  Constant: '<S200>/Constant7'
         *  Trigonometry: '<S200>/Trigonometric Function'
         *  Trigonometry: '<S200>/Trigonometric Function1'
         */
        rtb_MultiportSwitch2[3] = rtb_ixk_k;
        rtb_MultiportSwitch2[4] = beta;
        rtb_MultiportSwitch2[5] = Mainframe_P.Constant7_Value_ct;

        /* SignalConversion generated from: '<S200>/Matrix Concatenate' incorporates:
         *  Constant: '<S200>/Constant8'
         *  Gain: '<S200>/Gain'
         */
        rtb_MultiportSwitch2[0] = beta;
        rtb_MultiportSwitch2[1] = Mainframe_P.Gain_Gain_pz * rtb_ixk_k;
        rtb_MultiportSwitch2[2] = Mainframe_P.Constant8_Value_c;
        break;
      }

      /* End of MultiPortSwitch: '<S196>/Multiport Switch' */

      /* Product: '<S196>/3. Rotation' */
      for (i = 0; i < 3; i++) {
        for (idx = 0; idx < 3; idx++) {
          rtb_MultiportSwitch1_tmp = idx + 3 * i;
          rtb_Product2_mq[rtb_MultiportSwitch1_tmp] = 0.0;
          rtb_Product2_mq[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 *
            i] * rtb_MultiportSwitch1[idx];
          rtb_Product2_mq[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 *
            i + 1] * rtb_MultiportSwitch1[idx + 3];
          rtb_Product2_mq[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch2[3 *
            i + 2] * rtb_MultiportSwitch1[idx + 6];
        }
      }

      for (i = 0; i < 3; i++) {
        for (idx = 0; idx < 3; idx++) {
          rtb_MultiportSwitch1_tmp = idx + 3 * i;
          Mainframe_B.T12[rtb_MultiportSwitch1_tmp] = 0.0;
          Mainframe_B.T12[rtb_MultiportSwitch1_tmp] += rtb_Product2_mq[3 * i] *
            rtb_MultiportSwitch[idx];
          Mainframe_B.T12[rtb_MultiportSwitch1_tmp] += rtb_Product2_mq[3 * i + 1]
            * rtb_MultiportSwitch[idx + 3];
          Mainframe_B.T12[rtb_MultiportSwitch1_tmp] += rtb_Product2_mq[3 * i + 2]
            * rtb_MultiportSwitch[idx + 6];
        }
      }

      /* End of Product: '<S196>/3. Rotation' */
    }

    /* Switch: '<S194>/Switch' incorporates:
     *  Constant: '<S194>/Constant'
     */
    if (!(rtb_T_sim_glbl > Mainframe_P.Switch_Threshold_o3)) {
      rtb_T_sim_glbl = Mainframe_P.Constant_Value_ny;
    }

    /* End of Switch: '<S194>/Switch' */

    /* Switch: '<S194>/Switch1' incorporates:
     *  Lookup_n-D: '<S194>/thrust_lookup'
     */
    if (rtb_T_sim_glbl > Mainframe_P.Switch1_Threshold_f) {
      /* Saturate: '<S194>/Saturation' */
      if (rtb_T_sim_glbl > Mainframe_P.Saturation_UpperSat) {
        rtb_T_sim_glbl = Mainframe_P.Saturation_UpperSat;
      } else {
        if (rtb_T_sim_glbl < Mainframe_P.Saturation_LowerSat) {
          rtb_T_sim_glbl = Mainframe_P.Saturation_LowerSat;
        }
      }

      /* End of Saturate: '<S194>/Saturation' */
      rtb_IntegratorSecondOrderLimited_o2_a[0] = look1_binlcapw(rtb_T_sim_glbl,
        Mainframe_P.thrust_lookup_bp01Data, Mainframe_P.thrust_lookup_tableData,
        332U);
    } else {
      rtb_IntegratorSecondOrderLimited_o2_a[0] = rtb_T_sim_glbl;
    }

    /* End of Switch: '<S194>/Switch1' */

    /* Product: '<S195>/Product1' incorporates:
     *  Constant: '<S194>/Constant1'
     *  Constant: '<S195>/uncert_thrust'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[0] *= Mainframe_P.uncert_thrust_Value;
    rtb_IntegratorSecondOrderLimited_o2_h_tmp = Mainframe_P.Constant1_Value_k *
      Mainframe_P.uncert_thrust_Value;

    /* Product: '<S195>/Product' incorporates:
     *  Product: '<S195>/Product1'
     */
    for (i = 0; i < 3; i++) {
      rtb_u2[i] = Mainframe_B.T12[i + 6] *
        rtb_IntegratorSecondOrderLimited_o2_h_tmp + (Mainframe_B.T12[i + 3] *
        rtb_IntegratorSecondOrderLimited_o2_h_tmp + Mainframe_B.T12[i] *
        rtb_IntegratorSecondOrderLimited_o2_a[0]);
    }

    /* End of Product: '<S195>/Product' */

    /* Switch: '<S237>/Switch' incorporates:
     *  Constant: '<S237>/Constant'
     *  Product: '<S237>/Product2'
     *  Sum: '<S104>/Add'
     */
    if (Mainframe_P.Rigid_Body_EOM_6_DOF_flag_Kraft >
        Mainframe_P.Switch_Threshold_om) {
      rtb_Sum1_e[0] = (rtb_Sum1_e[0] + rtb_VectorConcatenate_m[0]) + rtb_u2[0];
      rtb_Sum1_e[1] = (rtb_Sum1_e[1] + rtb_VectorConcatenate_m[1]) + rtb_u2[1];
      rtb_Sum1_e[2] = (rtb_Sum1_e[2] + rtb_VectorConcatenate_m[2]) + rtb_u2[2];
    } else {
      /* Sum: '<S239>/Add7' */
      rtb_MathFunction2[8] = q0_tmp;

      /* Sum: '<S239>/Add8' incorporates:
       *  Gain: '<S239>/Gain11'
       *  Gain: '<S239>/Gain12'
       */
      rtb_MathFunction2[7] = rtb_JMMB_tmp_3 * Mainframe_P.Gain11_Gain +
        rtb_JMMB_tmp_4 * Mainframe_P.Gain12_Gain;

      /* Sum: '<S239>/Add3' incorporates:
       *  Gain: '<S239>/Gain5'
       *  Gain: '<S239>/Gain6'
       */
      rtb_MathFunction2[6] = rtb_JMMB_tmp_1 * Mainframe_P.Gain5_Gain -
        rtb_JMMB_tmp_2 * Mainframe_P.Gain6_Gain;

      /* Sum: '<S239>/Add2' incorporates:
       *  Gain: '<S239>/Gain3'
       *  Gain: '<S239>/Gain4'
       */
      rtb_MathFunction2[5] = rtb_JMMB_tmp_3 * Mainframe_P.Gain3_Gain -
        rtb_JMMB_tmp_4 * Mainframe_P.Gain4_Gain;

      /* Sum: '<S239>/Add6' */
      rtb_MathFunction2[4] = rtb_JMMB_tmp_5;

      /* Sum: '<S239>/Add4' incorporates:
       *  Gain: '<S239>/Gain7'
       *  Gain: '<S239>/Gain8'
       */
      rtb_MathFunction2[3] = rtb_JMMB_tmp * Mainframe_P.Gain7_Gain +
        rtb_JMMB_tmp_0 * Mainframe_P.Gain8_Gain;

      /* Sum: '<S239>/Add5' incorporates:
       *  Gain: '<S239>/Gain10'
       *  Gain: '<S239>/Gain9'
       */
      rtb_MathFunction2[2] = rtb_JMMB_tmp_1 * Mainframe_P.Gain9_Gain +
        rtb_JMMB_tmp_2 * Mainframe_P.Gain10_Gain;

      /* Sum: '<S239>/Add1' incorporates:
       *  Gain: '<S239>/Gain1'
       *  Gain: '<S239>/Gain2'
       */
      rtb_MathFunction2[1] = rtb_JMMB_tmp * Mainframe_P.Gain1_Gain_g -
        rtb_JMMB_tmp_0 * Mainframe_P.Gain2_Gain_j;

      /* Sum: '<S239>/Add' */
      rtb_MathFunction2[0] = rtb_JMMB_tmp_6;

      /* Math: '<S237>/Math Function2' */
      for (i = 0; i < 3; i++) {
        rtb_Product2_mq[3 * i] = rtb_MathFunction2[i];
        rtb_Product2_mq[3 * i + 1] = rtb_MathFunction2[i + 3];
        rtb_Product2_mq[3 * i + 2] = rtb_MathFunction2[i + 6];
      }

      memcpy(&rtb_MathFunction2[0], &rtb_Product2_mq[0], 9U * sizeof(real_T));

      /* End of Math: '<S237>/Math Function2' */

      /* Sum: '<S104>/Add' */
      rtb_JMMB_tmp = (rtb_Sum1_e[0] + rtb_VectorConcatenate_m[0]) + rtb_u2[0];
      q0_tmp = (rtb_Sum1_e[1] + rtb_VectorConcatenate_m[1]) + rtb_u2[1];
      rtb_JMMB_tmp_6 = (rtb_Sum1_e[2] + rtb_VectorConcatenate_m[2]) + rtb_u2[2];
      for (i = 0; i < 3; i++) {
        rtb_Sum1_e[i] = rtb_MathFunction2[i + 6] * rtb_JMMB_tmp_6 +
          (rtb_MathFunction2[i + 3] * q0_tmp + rtb_MathFunction2[i] *
           rtb_JMMB_tmp);
      }
    }

    /* Saturate: '<S240>/Saturation' */
    if (rtb_Product2_l > Mainframe_P.Saturation_UpperSat_g) {
      rtb_ixk_k = Mainframe_P.Saturation_UpperSat_g;
    } else if (rtb_Product2_l < Mainframe_P.Saturation_LowerSat_i) {
      rtb_ixk_k = Mainframe_P.Saturation_LowerSat_i;
    } else {
      rtb_ixk_k = rtb_Product2_l;
    }

    /* End of Saturate: '<S240>/Saturation' */

    /* Product: '<S240>/Divide' */
    rtb_Sum1_e[0] /= rtb_ixk_k;
    rtb_Sum1_e[1] /= rtb_ixk_k;

    /* SignalConversion generated from: '<S244>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_c[0] = rtb_Sum1_e[0];

    /* SignalConversion generated from: '<S244>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_c[1] = rtb_Sum1_e[1];

    /* SignalConversion generated from: '<S244>/Vector Concatenate' incorporates:
     *  Product: '<S240>/Divide'
     */
    Mainframe_B.VectorConcatenate_c[2] = rtb_Sum1_e[2] / rtb_ixk_k;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S244>/Constant' */
      Mainframe_B.VectorConcatenate_c[3] = Mainframe_P.Constant_Value_bd;
    }

    /* Sum: '<S244>/Add' incorporates:
     *  Constant: '<S244>/Q_1'
     *  Constant: '<S244>/Q_2'
     *  Constant: '<S244>/Q_3'
     *  Constant: '<S244>/Q_4'
     *  Product: '<S244>/Product'
     *  Product: '<S244>/Product1'
     *  Product: '<S244>/Product2'
     *  Product: '<S244>/Product3'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_d[i] * rtb_Product_b_idx_0 +
                 Mainframe_P.Q_2_Value_f[i] * rtb_Product_b_idx_1) +
                Mainframe_P.Q_3_Value_c[i] * rtb_Product_b_idx_2) +
        Mainframe_P.Q_4_Value_n[i] * rtb_Product_d;
    }

    /* End of Sum: '<S244>/Add' */

    /* Product: '<S244>/Product8' */
    for (i = 0; i < 4; i++) {
      rtb_T_sim_glbl = tmp[i + 12] * Mainframe_B.VectorConcatenate_c[3] + (tmp[i
        + 8] * Mainframe_B.VectorConcatenate_c[2] + (tmp[i + 4] *
        Mainframe_B.VectorConcatenate_c[1] + tmp[i] *
        Mainframe_B.VectorConcatenate_c[0]));
      rtb_d_qEI[i] = rtb_T_sim_glbl;
    }

    /* Sum: '<S244>/Add1' incorporates:
     *  Constant: '<S244>/Q~_1'
     *  Constant: '<S244>/Q~_2'
     *  Constant: '<S244>/Q~_3'
     *  Constant: '<S244>/Q~_4'
     *  Product: '<S244>/Product4'
     *  Product: '<S244>/Product5'
     *  Product: '<S244>/Product6'
     *  Product: '<S244>/Product7'
     */
    for (i = 0; i < 4; i++) {
      idx = i << 2;
      tmp[idx] = ((Mainframe_P.Q_1_Value[i] * rtb_Product_b_idx_0 +
                   Mainframe_P.Q_2_Value[i] * rtb_Product_b_idx_1) +
                  Mainframe_P.Q_3_Value[i] * rtb_Product_b_idx_2) +
        Mainframe_P.Q_4_Value[i] * rtb_Product_d;
      tmp[idx + 1] = ((Mainframe_P.Q_1_Value[i + 4] * rtb_Product_b_idx_0 +
                       Mainframe_P.Q_2_Value[i + 4] * rtb_Product_b_idx_1) +
                      Mainframe_P.Q_3_Value[i + 4] * rtb_Product_b_idx_2) +
        Mainframe_P.Q_4_Value[i + 4] * rtb_Product_d;
      tmp[idx + 2] = ((Mainframe_P.Q_1_Value[i + 8] * rtb_Product_b_idx_0 +
                       Mainframe_P.Q_2_Value[i + 8] * rtb_Product_b_idx_1) +
                      Mainframe_P.Q_3_Value[i + 8] * rtb_Product_b_idx_2) +
        Mainframe_P.Q_4_Value[i + 8] * rtb_Product_d;
      tmp[idx + 3] = ((Mainframe_P.Q_1_Value[i + 12] * rtb_Product_b_idx_0 +
                       Mainframe_P.Q_2_Value[i + 12] * rtb_Product_b_idx_1) +
                      Mainframe_P.Q_3_Value[i + 12] * rtb_Product_b_idx_2) +
        Mainframe_P.Q_4_Value[i + 12] * rtb_Product_d;
    }

    /* End of Sum: '<S244>/Add1' */

    /* Product: '<S244>/Product8' */
    for (i = 0; i < 4; i++) {
      rtb_ixk_k = tmp[i + 12] * rtb_d_qEI[3] + (tmp[i + 8] * rtb_d_qEI[2] +
        (tmp[i + 4] * rtb_d_qEI[1] + tmp[i] * rtb_d_qEI[0]));
      rtb_q_conj[i] = rtb_ixk_k;
    }

    /* SecondOrderIntegrator: '<S88>/Integrator, Second-Order Limited' */
    /* Unit Conversion - from: m/s^2 to: gn
       Expression: output = (0.101972*input) + (0) */
    idx = 3;

    /* Gain: '<S88>/2*zeta * wn' */
    rtb_T_sim_glbl = 2.0 * Mainframe_P.ThreeaxisInertialMeasurementUnit_z_a *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a;
    for (rtb_MultiportSwitch1_tmp = 0; rtb_MultiportSwitch1_tmp < 3;
         rtb_MultiportSwitch1_tmp++) {
      /* Product: '<S207>/Product' incorporates:
       *  Math: '<S207>/Math Function'
       */
      Mainframe_B.aBIB[rtb_MultiportSwitch1_tmp] = 0.0;
      Mainframe_B.aBIB[rtb_MultiportSwitch1_tmp] +=
        rtb_TBI_tmp[rtb_MultiportSwitch1_tmp] * rtb_q_conj[0];
      Mainframe_B.aBIB[rtb_MultiportSwitch1_tmp] +=
        rtb_TBI_tmp[rtb_MultiportSwitch1_tmp + 3] * rtb_q_conj[1];
      Mainframe_B.aBIB[rtb_MultiportSwitch1_tmp] +=
        rtb_TBI_tmp[rtb_MultiportSwitch1_tmp + 6] * rtb_q_conj[2];

      /* SecondOrderIntegrator: '<S88>/Integrator, Second-Order Limited' */
      rtb_IntegratorSecondOrderLimited_o2_a[rtb_MultiportSwitch1_tmp] =
        Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[rtb_MultiportSwitch1_tmp];
      q0_tmp = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[idx];
      idx++;

      /* Gain: '<S88>/2*zeta * wn' */
      rtb_uzetawn_p[rtb_MultiportSwitch1_tmp] = rtb_T_sim_glbl * q0_tmp;

      /* Gain: '<S81>/Zero-Order Hold2' */
      rtb_ZeroOrderHold2_c[rtb_MultiportSwitch1_tmp] =
        Mainframe_P.ZeroOrderHold2_Gain * rtb_Sum4[rtb_MultiportSwitch1_tmp];

      /* Gain: '<S81>/Zero-Order Hold' */
      rtb_Sum4[rtb_MultiportSwitch1_tmp] =
        Mainframe_B.x_d[rtb_MultiportSwitch1_tmp + 10] *
        Mainframe_P.ZeroOrderHold_Gain;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S81>/Gain' incorporates:
       *  Constant: '<S74>/Constant1'
       *  Constant: '<S81>/wl_ins'
       *  Gain: '<S81>/Zero-Order Hold4'
       *  Sum: '<S81>/Sum7'
       */
      Mainframe_B.Gain_ln[0] = (Mainframe_P.ZeroOrderHold4_Gain *
        Mainframe_P.Constant1_Value_c[0] -
        Mainframe_P.ThreeaxisInertialMeasurementUnit_imu[0]) *
        Mainframe_P.Gain_Gain_aj[0];
      Mainframe_B.Gain_ln[1] = (Mainframe_P.ZeroOrderHold4_Gain *
        Mainframe_P.Constant1_Value_c[1] -
        Mainframe_P.ThreeaxisInertialMeasurementUnit_imu[1]) *
        Mainframe_P.Gain_Gain_aj[1];
      Mainframe_B.Gain_ln[2] = (Mainframe_P.ZeroOrderHold4_Gain *
        Mainframe_P.Constant1_Value_c[2] -
        Mainframe_P.ThreeaxisInertialMeasurementUnit_imu[2]) *
        Mainframe_P.Gain_Gain_aj[2];

      /* Product: '<S255>/Product' incorporates:
       *  Constant: '<S255>/Constant'
       *  Constant: '<S255>/Constant6'
       */
      Mainframe_B.Product_a = Mainframe_P.Constant_Value_ds *
        Mainframe_P.Constant6_Value_i;
    }

    /* Sum: '<S90>/Sum' incorporates:
     *  Product: '<S93>/i x j'
     *  Product: '<S93>/j x k'
     *  Product: '<S93>/k x i'
     *  Product: '<S94>/i x k'
     *  Product: '<S94>/j x i'
     *  Product: '<S94>/k x j'
     */
    rtb_VectorConcatenate_m[0] = rtb_Sum4[1] * Mainframe_B.Gain_ln[2] -
      rtb_Sum4[2] * Mainframe_B.Gain_ln[1];
    rtb_VectorConcatenate_m[1] = rtb_Sum4[2] * Mainframe_B.Gain_ln[0] -
      rtb_Sum4[0] * Mainframe_B.Gain_ln[2];
    rtb_VectorConcatenate_m[2] = rtb_Sum4[0] * Mainframe_B.Gain_ln[1] -
      rtb_Sum4[1] * Mainframe_B.Gain_ln[0];

    /* Product: '<S91>/i x j' */
    rtb_T_sim_glbl = rtb_Sum4[0];

    /* Product: '<S92>/i x k' */
    q0_tmp = rtb_Sum4[0];

    /* Product: '<S92>/j x i' */
    rtb_JMMB_tmp_6 = rtb_Sum4[1];

    /* Sum: '<S89>/Sum' incorporates:
     *  Product: '<S91>/i x j'
     *  Product: '<S91>/j x k'
     *  Product: '<S91>/k x i'
     *  Product: '<S92>/i x k'
     *  Product: '<S92>/j x i'
     *  Product: '<S92>/k x j'
     */
    rtb_Sum4[0] = rtb_Sum4[1] * rtb_VectorConcatenate_m[2] - rtb_Sum4[2] *
      rtb_VectorConcatenate_m[1];
    rtb_Sum4[1] = rtb_Sum4[2] * rtb_VectorConcatenate_m[0] - q0_tmp *
      rtb_VectorConcatenate_m[2];
    rtb_Sum4[2] = rtb_T_sim_glbl * rtb_VectorConcatenate_m[1] - rtb_JMMB_tmp_6 *
      rtb_VectorConcatenate_m[0];

    /* Sum: '<S255>/Add4' incorporates:
     *  Constant: '<S255>/Constant3'
     *  Constant: '<S255>/Constant4'
     *  Product: '<S255>/Divide'
     *  Product: '<S255>/Product1'
     *  Sum: '<S255>/Add'
     */
    rtb_Sum1_e[0] = (rtb_TrigonometricFunction1_j *
                     Mainframe_P.Constant4_Value_as + Mainframe_B.Product_a) *
      (1.0 / rtb_Product2_l) + Mainframe_P.Constant3_Value_p;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Product: '<S255>/Product2' incorporates:
       *  Constant: '<S255>/Constant'
       *  Constant: '<S255>/Constant5'
       */
      Mainframe_B.Product2 = Mainframe_P.Constant_Value_ds *
        Mainframe_P.Constant5_Value;

      /* Product: '<S255>/Product4' incorporates:
       *  Constant: '<S255>/Constant'
       *  Constant: '<S255>/Constant8'
       */
      Mainframe_B.Product4 = Mainframe_P.Constant_Value_ds *
        Mainframe_P.Constant8_Value_n;
    }

    /* Sum: '<S255>/Add3' incorporates:
     *  Constant: '<S255>/Constant1'
     *  Constant: '<S255>/Constant7'
     *  Product: '<S255>/Divide1'
     *  Product: '<S255>/Product3'
     *  Sum: '<S255>/Add1'
     */
    rtb_Sum1_e[1] = (rtb_TrigonometricFunction1_j *
                     Mainframe_P.Constant7_Value_ei + Mainframe_B.Product2) *
      (1.0 / rtb_Product2_l) + Mainframe_P.Constant1_Value_mh;

    /* Sum: '<S255>/Add5' incorporates:
     *  Constant: '<S255>/Constant2'
     *  Constant: '<S255>/Constant9'
     *  Product: '<S255>/Divide2'
     *  Product: '<S255>/Product5'
     *  Sum: '<S255>/Add2'
     */
    rtb_Sum1_e[2] = (rtb_TrigonometricFunction1_j *
                     Mainframe_P.Constant9_Value_a + Mainframe_B.Product4) *
      (1.0 / rtb_Product2_l) + Mainframe_P.Constant2_Value_lc;

    /* Sum: '<S262>/Subtract' incorporates:
     *  Constant: '<S262>/Constant17'
     */
    rtb_VectorConcatenate_m[0] = rtb_Sum1_e[0] - Mainframe_P.Constant17_Value[0];
    rtb_VectorConcatenate_m[1] = rtb_Sum1_e[1] - Mainframe_P.Constant17_Value[1];
    rtb_VectorConcatenate_m[2] = rtb_Sum1_e[2] - Mainframe_P.Constant17_Value[2];

    /* Product: '<S274>/Product1' */
    rtb_T_sim_glbl = rtb_VectorConcatenate_m[1] * rtb_VectorConcatenate_m[1];

    /* Product: '<S274>/Product2' */
    rtb_Product2_l = rtb_VectorConcatenate_m[2] * rtb_VectorConcatenate_m[2];

    /* Sum: '<S274>/Add' */
    rtb_JMMB[0] = rtb_T_sim_glbl + rtb_Product2_l;

    /* Gain: '<S274>/Gain' incorporates:
     *  Product: '<S274>/Product3'
     */
    rtb_ixk_k = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[1] *
      Mainframe_P.Gain_Gain_mf;

    /* SignalConversion generated from: '<S274>/Vector Concatenate6' */
    rtb_JMMB[1] = rtb_ixk_k;

    /* Gain: '<S274>/Gain1' incorporates:
     *  Product: '<S274>/Product4'
     */
    beta = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[2] *
      Mainframe_P.Gain1_Gain_o1;

    /* SignalConversion generated from: '<S274>/Vector Concatenate6' */
    rtb_JMMB[2] = beta;

    /* SignalConversion generated from: '<S274>/Vector Concatenate7' */
    rtb_JMMB[3] = rtb_ixk_k;

    /* Product: '<S274>/Product5' */
    rtb_ixk_k = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[0];

    /* Sum: '<S274>/Add5' */
    rtb_JMMB[4] = rtb_T_sim_glbl + rtb_ixk_k;

    /* Gain: '<S274>/Gain3' incorporates:
     *  Product: '<S274>/Product6'
     */
    rtb_T_sim_glbl = rtb_VectorConcatenate_m[1] * rtb_VectorConcatenate_m[2] *
      Mainframe_P.Gain3_Gain_b;

    /* SignalConversion generated from: '<S274>/Vector Concatenate7' */
    rtb_JMMB[5] = rtb_T_sim_glbl;

    /* SignalConversion generated from: '<S274>/Vector Concatenate8' */
    rtb_JMMB[6] = beta;

    /* SignalConversion generated from: '<S274>/Vector Concatenate8' */
    rtb_JMMB[7] = rtb_T_sim_glbl;

    /* Sum: '<S274>/Add4' */
    rtb_JMMB[8] = rtb_Product2_l + rtb_ixk_k;

    /* Sum: '<S258>/Add5' incorporates:
     *  Constant: '<S258>/Constant15'
     *  Constant: '<S262>/Constant'
     *  Product: '<S262>/Product'
     */
    for (i = 0; i < 9; i++) {
      rtb_MathFunction2[i] = Mainframe_P.Constant_Value_mt * rtb_JMMB[i] +
        Mainframe_P.Constant15_Value[i];
    }

    /* End of Sum: '<S258>/Add5' */

    /* Sum: '<S263>/Subtract4' incorporates:
     *  Constant: '<S263>/Constant16'
     */
    rtb_VectorConcatenate_m[0] = rtb_Sum1_e[0] - Mainframe_P.Constant16_Value[0];
    rtb_VectorConcatenate_m[1] = rtb_Sum1_e[1] - Mainframe_P.Constant16_Value[1];
    rtb_VectorConcatenate_m[2] = rtb_Sum1_e[2] - Mainframe_P.Constant16_Value[2];

    /* Product: '<S275>/Product1' */
    rtb_T_sim_glbl = rtb_VectorConcatenate_m[1] * rtb_VectorConcatenate_m[1];

    /* Product: '<S275>/Product2' */
    rtb_Product2_l = rtb_VectorConcatenate_m[2] * rtb_VectorConcatenate_m[2];

    /* Sum: '<S275>/Add' */
    rtb_JMMB[0] = rtb_T_sim_glbl + rtb_Product2_l;

    /* Gain: '<S275>/Gain' incorporates:
     *  Product: '<S275>/Product3'
     */
    rtb_ixk_k = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[1] *
      Mainframe_P.Gain_Gain_mj;

    /* SignalConversion generated from: '<S275>/Vector Concatenate6' */
    rtb_JMMB[1] = rtb_ixk_k;

    /* Gain: '<S275>/Gain1' incorporates:
     *  Product: '<S275>/Product4'
     */
    beta = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[2] *
      Mainframe_P.Gain1_Gain_fv;

    /* SignalConversion generated from: '<S275>/Vector Concatenate6' */
    rtb_JMMB[2] = beta;

    /* SignalConversion generated from: '<S275>/Vector Concatenate7' */
    rtb_JMMB[3] = rtb_ixk_k;

    /* Product: '<S275>/Product5' */
    rtb_ixk_k = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[0];

    /* Sum: '<S275>/Add5' */
    rtb_JMMB[4] = rtb_T_sim_glbl + rtb_ixk_k;

    /* Gain: '<S275>/Gain3' incorporates:
     *  Product: '<S275>/Product6'
     */
    rtb_T_sim_glbl = rtb_VectorConcatenate_m[1] * rtb_VectorConcatenate_m[2] *
      Mainframe_P.Gain3_Gain_bz;

    /* SignalConversion generated from: '<S275>/Vector Concatenate7' */
    rtb_JMMB[5] = rtb_T_sim_glbl;

    /* SignalConversion generated from: '<S275>/Vector Concatenate8' */
    rtb_JMMB[6] = beta;

    /* SignalConversion generated from: '<S275>/Vector Concatenate8' */
    rtb_JMMB[7] = rtb_T_sim_glbl;

    /* Sum: '<S275>/Add4' */
    rtb_JMMB[8] = rtb_Product2_l + rtb_ixk_k;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* MultiPortSwitch: '<S264>/Multiport Switch2' incorporates:
       *  Constant: '<S264>/Constant2'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_3_a) {
       case 1:
        /* Trigonometry: '<S271>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/thrust_rot_x'
         *  Trigonometry: '<S271>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_x_Value_h);

        /* Trigonometry: '<S271>/Trigonometric Function3' incorporates:
         *  Constant: '<S260>/thrust_rot_x'
         *  Trigonometry: '<S271>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.thrust_rot_x_Value_h);

        /* SignalConversion generated from: '<S271>/Matrix Concatenate' incorporates:
         *  Constant: '<S271>/Constant7'
         *  Trigonometry: '<S271>/Trigonometric Function1'
         *  Trigonometry: '<S271>/Trigonometric Function3'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Constant7_Value_g;
        rtb_MultiportSwitch2[7] = rtb_ixk_k;
        rtb_MultiportSwitch2[8] = beta;

        /* SignalConversion generated from: '<S271>/Matrix Concatenate' incorporates:
         *  Constant: '<S271>/Constant8'
         *  Gain: '<S271>/Gain'
         */
        rtb_MultiportSwitch2[3] = Mainframe_P.Constant8_Value_l;
        rtb_MultiportSwitch2[4] = beta;
        rtb_MultiportSwitch2[5] = Mainframe_P.Gain_Gain_gk * rtb_ixk_k;

        /* SignalConversion generated from: '<S271>/Matrix Concatenate' incorporates:
         *  Constant: '<S271>/Constant'
         *  Constant: '<S271>/Constant1'
         *  Constant: '<S271>/Constant2'
         */
        rtb_MultiportSwitch2[0] = Mainframe_P.Constant_Value_pf;
        rtb_MultiportSwitch2[1] = Mainframe_P.Constant1_Value_i;
        rtb_MultiportSwitch2[2] = Mainframe_P.Constant2_Value_m;
        break;

       case 2:
        /* Trigonometry: '<S272>/Trigonometric Function3' incorporates:
         *  Constant: '<S260>/thrust_rot_x'
         *  Trigonometry: '<S272>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.thrust_rot_x_Value_h);

        /* Trigonometry: '<S272>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/thrust_rot_x'
         *  Trigonometry: '<S272>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.thrust_rot_x_Value_h);

        /* SignalConversion generated from: '<S272>/Matrix Concatenate' incorporates:
         *  Constant: '<S272>/Constant7'
         *  Gain: '<S272>/Gain1'
         *  Trigonometry: '<S272>/Trigonometric Function1'
         *  Trigonometry: '<S272>/Trigonometric Function3'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Gain1_Gain_g4 * beta;
        rtb_MultiportSwitch2[7] = Mainframe_P.Constant7_Value_op;
        rtb_MultiportSwitch2[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S272>/Matrix Concatenate' incorporates:
         *  Constant: '<S272>/Constant'
         *  Constant: '<S272>/Constant1'
         *  Constant: '<S272>/Constant2'
         */
        rtb_MultiportSwitch2[3] = Mainframe_P.Constant_Value_f;
        rtb_MultiportSwitch2[4] = Mainframe_P.Constant1_Value_jv;
        rtb_MultiportSwitch2[5] = Mainframe_P.Constant2_Value_j;

        /* SignalConversion generated from: '<S272>/Matrix Concatenate' incorporates:
         *  Constant: '<S272>/Constant8'
         */
        rtb_MultiportSwitch2[0] = rtb_ixk_k;
        rtb_MultiportSwitch2[1] = Mainframe_P.Constant8_Value_gc;
        rtb_MultiportSwitch2[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S273>/Matrix Concatenate' incorporates:
         *  Constant: '<S273>/Constant10'
         *  Constant: '<S273>/Constant11'
         *  Constant: '<S273>/Constant4'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Constant4_Value_i;
        rtb_MultiportSwitch2[7] = Mainframe_P.Constant10_Value_k;
        rtb_MultiportSwitch2[8] = Mainframe_P.Constant11_Value_l;

        /* Trigonometry: '<S273>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/thrust_rot_x'
         *  Trigonometry: '<S273>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_x_Value_h);

        /* Trigonometry: '<S273>/Trigonometric Function' incorporates:
         *  Constant: '<S260>/thrust_rot_x'
         *  Trigonometry: '<S273>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.thrust_rot_x_Value_h);

        /* SignalConversion generated from: '<S273>/Matrix Concatenate' incorporates:
         *  Constant: '<S273>/Constant7'
         *  Trigonometry: '<S273>/Trigonometric Function'
         *  Trigonometry: '<S273>/Trigonometric Function1'
         */
        rtb_MultiportSwitch2[3] = rtb_ixk_k;
        rtb_MultiportSwitch2[4] = beta;
        rtb_MultiportSwitch2[5] = Mainframe_P.Constant7_Value_a5;

        /* SignalConversion generated from: '<S273>/Matrix Concatenate' incorporates:
         *  Constant: '<S273>/Constant8'
         *  Gain: '<S273>/Gain'
         */
        rtb_MultiportSwitch2[0] = beta;
        rtb_MultiportSwitch2[1] = Mainframe_P.Gain_Gain_h * rtb_ixk_k;
        rtb_MultiportSwitch2[2] = Mainframe_P.Constant8_Value_j1;
        break;
      }

      /* End of MultiPortSwitch: '<S264>/Multiport Switch2' */

      /* MultiPortSwitch: '<S264>/Multiport Switch1' incorporates:
       *  Constant: '<S264>/Constant1'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_2_a) {
       case 1:
        /* Trigonometry: '<S268>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/thrust_rot_y'
         *  Trigonometry: '<S268>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_y_Value_j);

        /* Trigonometry: '<S268>/Trigonometric Function3' incorporates:
         *  Constant: '<S260>/thrust_rot_y'
         *  Trigonometry: '<S268>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.thrust_rot_y_Value_j);

        /* SignalConversion generated from: '<S268>/Matrix Concatenate' incorporates:
         *  Constant: '<S268>/Constant7'
         *  Trigonometry: '<S268>/Trigonometric Function1'
         *  Trigonometry: '<S268>/Trigonometric Function3'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Constant7_Value_e;
        rtb_MultiportSwitch1[7] = rtb_ixk_k;
        rtb_MultiportSwitch1[8] = beta;

        /* SignalConversion generated from: '<S268>/Matrix Concatenate' incorporates:
         *  Constant: '<S268>/Constant8'
         *  Gain: '<S268>/Gain'
         */
        rtb_MultiportSwitch1[3] = Mainframe_P.Constant8_Value_e;
        rtb_MultiportSwitch1[4] = beta;
        rtb_MultiportSwitch1[5] = Mainframe_P.Gain_Gain_o * rtb_ixk_k;

        /* SignalConversion generated from: '<S268>/Matrix Concatenate' incorporates:
         *  Constant: '<S268>/Constant'
         *  Constant: '<S268>/Constant1'
         *  Constant: '<S268>/Constant2'
         */
        rtb_MultiportSwitch1[0] = Mainframe_P.Constant_Value_m;
        rtb_MultiportSwitch1[1] = Mainframe_P.Constant1_Value_f;
        rtb_MultiportSwitch1[2] = Mainframe_P.Constant2_Value_i3;
        break;

       case 2:
        /* Trigonometry: '<S269>/Trigonometric Function3' incorporates:
         *  Constant: '<S260>/thrust_rot_y'
         *  Trigonometry: '<S269>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.thrust_rot_y_Value_j);

        /* Trigonometry: '<S269>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/thrust_rot_y'
         *  Trigonometry: '<S269>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.thrust_rot_y_Value_j);

        /* SignalConversion generated from: '<S269>/Matrix Concatenate' incorporates:
         *  Constant: '<S269>/Constant7'
         *  Gain: '<S269>/Gain1'
         *  Trigonometry: '<S269>/Trigonometric Function1'
         *  Trigonometry: '<S269>/Trigonometric Function3'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Gain1_Gain_cw * beta;
        rtb_MultiportSwitch1[7] = Mainframe_P.Constant7_Value_l;
        rtb_MultiportSwitch1[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S269>/Matrix Concatenate' incorporates:
         *  Constant: '<S269>/Constant'
         *  Constant: '<S269>/Constant1'
         *  Constant: '<S269>/Constant2'
         */
        rtb_MultiportSwitch1[3] = Mainframe_P.Constant_Value_b4;
        rtb_MultiportSwitch1[4] = Mainframe_P.Constant1_Value_jy;
        rtb_MultiportSwitch1[5] = Mainframe_P.Constant2_Value_ia;

        /* SignalConversion generated from: '<S269>/Matrix Concatenate' incorporates:
         *  Constant: '<S269>/Constant8'
         */
        rtb_MultiportSwitch1[0] = rtb_ixk_k;
        rtb_MultiportSwitch1[1] = Mainframe_P.Constant8_Value_cx;
        rtb_MultiportSwitch1[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S270>/Matrix Concatenate' incorporates:
         *  Constant: '<S270>/Constant10'
         *  Constant: '<S270>/Constant11'
         *  Constant: '<S270>/Constant4'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Constant4_Value_j;
        rtb_MultiportSwitch1[7] = Mainframe_P.Constant10_Value_i;
        rtb_MultiportSwitch1[8] = Mainframe_P.Constant11_Value_lg;

        /* Trigonometry: '<S270>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/thrust_rot_y'
         *  Trigonometry: '<S270>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_y_Value_j);

        /* Trigonometry: '<S270>/Trigonometric Function' incorporates:
         *  Constant: '<S260>/thrust_rot_y'
         *  Trigonometry: '<S270>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.thrust_rot_y_Value_j);

        /* SignalConversion generated from: '<S270>/Matrix Concatenate' incorporates:
         *  Constant: '<S270>/Constant7'
         *  Trigonometry: '<S270>/Trigonometric Function'
         *  Trigonometry: '<S270>/Trigonometric Function1'
         */
        rtb_MultiportSwitch1[3] = rtb_ixk_k;
        rtb_MultiportSwitch1[4] = beta;
        rtb_MultiportSwitch1[5] = Mainframe_P.Constant7_Value_n;

        /* SignalConversion generated from: '<S270>/Matrix Concatenate' incorporates:
         *  Constant: '<S270>/Constant8'
         *  Gain: '<S270>/Gain'
         */
        rtb_MultiportSwitch1[0] = beta;
        rtb_MultiportSwitch1[1] = Mainframe_P.Gain_Gain_c4 * rtb_ixk_k;
        rtb_MultiportSwitch1[2] = Mainframe_P.Constant8_Value_mn;
        break;
      }

      /* End of MultiPortSwitch: '<S264>/Multiport Switch1' */

      /* MultiPortSwitch: '<S264>/Multiport Switch' incorporates:
       *  Constant: '<S264>/Constant'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_1_e) {
       case 1:
        /* Trigonometry: '<S265>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/Thrust_rot_z'
         *  Trigonometry: '<S265>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.Thrust_rot_z_Value_l);

        /* Trigonometry: '<S265>/Trigonometric Function3' incorporates:
         *  Constant: '<S260>/Thrust_rot_z'
         *  Trigonometry: '<S265>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.Thrust_rot_z_Value_l);

        /* SignalConversion generated from: '<S265>/Matrix Concatenate' incorporates:
         *  Constant: '<S265>/Constant7'
         *  Trigonometry: '<S265>/Trigonometric Function1'
         *  Trigonometry: '<S265>/Trigonometric Function3'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Constant7_Value_b;
        rtb_MultiportSwitch[7] = rtb_ixk_k;
        rtb_MultiportSwitch[8] = beta;

        /* SignalConversion generated from: '<S265>/Matrix Concatenate' incorporates:
         *  Constant: '<S265>/Constant8'
         *  Gain: '<S265>/Gain'
         */
        rtb_MultiportSwitch[3] = Mainframe_P.Constant8_Value_o;
        rtb_MultiportSwitch[4] = beta;
        rtb_MultiportSwitch[5] = Mainframe_P.Gain_Gain_kc * rtb_ixk_k;

        /* SignalConversion generated from: '<S265>/Matrix Concatenate' incorporates:
         *  Constant: '<S265>/Constant'
         *  Constant: '<S265>/Constant1'
         *  Constant: '<S265>/Constant2'
         */
        rtb_MultiportSwitch[0] = Mainframe_P.Constant_Value_dt;
        rtb_MultiportSwitch[1] = Mainframe_P.Constant1_Value_g;
        rtb_MultiportSwitch[2] = Mainframe_P.Constant2_Value_g;
        break;

       case 2:
        /* Trigonometry: '<S266>/Trigonometric Function3' incorporates:
         *  Constant: '<S260>/Thrust_rot_z'
         *  Trigonometry: '<S266>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.Thrust_rot_z_Value_l);

        /* Trigonometry: '<S266>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/Thrust_rot_z'
         *  Trigonometry: '<S266>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.Thrust_rot_z_Value_l);

        /* SignalConversion generated from: '<S266>/Matrix Concatenate' incorporates:
         *  Constant: '<S266>/Constant7'
         *  Gain: '<S266>/Gain1'
         *  Trigonometry: '<S266>/Trigonometric Function1'
         *  Trigonometry: '<S266>/Trigonometric Function3'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Gain1_Gain_b * beta;
        rtb_MultiportSwitch[7] = Mainframe_P.Constant7_Value_ow;
        rtb_MultiportSwitch[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S266>/Matrix Concatenate' incorporates:
         *  Constant: '<S266>/Constant'
         *  Constant: '<S266>/Constant1'
         *  Constant: '<S266>/Constant2'
         */
        rtb_MultiportSwitch[3] = Mainframe_P.Constant_Value_d;
        rtb_MultiportSwitch[4] = Mainframe_P.Constant1_Value_p;
        rtb_MultiportSwitch[5] = Mainframe_P.Constant2_Value_b;

        /* SignalConversion generated from: '<S266>/Matrix Concatenate' incorporates:
         *  Constant: '<S266>/Constant8'
         */
        rtb_MultiportSwitch[0] = rtb_ixk_k;
        rtb_MultiportSwitch[1] = Mainframe_P.Constant8_Value_c0;
        rtb_MultiportSwitch[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S267>/Matrix Concatenate' incorporates:
         *  Constant: '<S267>/Constant10'
         *  Constant: '<S267>/Constant11'
         *  Constant: '<S267>/Constant4'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Constant4_Value_h;
        rtb_MultiportSwitch[7] = Mainframe_P.Constant10_Value_a;
        rtb_MultiportSwitch[8] = Mainframe_P.Constant11_Value_lo;

        /* Trigonometry: '<S267>/Trigonometric Function1' incorporates:
         *  Constant: '<S260>/Thrust_rot_z'
         *  Trigonometry: '<S267>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.Thrust_rot_z_Value_l);

        /* Trigonometry: '<S267>/Trigonometric Function' incorporates:
         *  Constant: '<S260>/Thrust_rot_z'
         *  Trigonometry: '<S267>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.Thrust_rot_z_Value_l);

        /* SignalConversion generated from: '<S267>/Matrix Concatenate' incorporates:
         *  Constant: '<S267>/Constant7'
         *  Trigonometry: '<S267>/Trigonometric Function'
         *  Trigonometry: '<S267>/Trigonometric Function1'
         */
        rtb_MultiportSwitch[3] = rtb_ixk_k;
        rtb_MultiportSwitch[4] = beta;
        rtb_MultiportSwitch[5] = Mainframe_P.Constant7_Value_ah;

        /* SignalConversion generated from: '<S267>/Matrix Concatenate' incorporates:
         *  Constant: '<S267>/Constant8'
         *  Gain: '<S267>/Gain'
         */
        rtb_MultiportSwitch[0] = beta;
        rtb_MultiportSwitch[1] = Mainframe_P.Gain_Gain_ib * rtb_ixk_k;
        rtb_MultiportSwitch[2] = Mainframe_P.Constant8_Value_my;
        break;
      }

      /* End of MultiPortSwitch: '<S264>/Multiport Switch' */

      /* Product: '<S264>/3. Rotation' */
      for (i = 0; i < 3; i++) {
        for (idx = 0; idx < 3; idx++) {
          rtb_MultiportSwitch1_tmp = idx + 3 * i;
          rtb_Product2_mq[rtb_MultiportSwitch1_tmp] = 0.0;
          rtb_Product2_mq[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i]
            * rtb_MultiportSwitch1[idx];
          rtb_Product2_mq[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i
            + 1] * rtb_MultiportSwitch1[idx + 3];
          rtb_Product2_mq[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch[3 * i
            + 2] * rtb_MultiportSwitch1[idx + 6];
        }
      }

      for (i = 0; i < 3; i++) {
        for (idx = 0; idx < 3; idx++) {
          rtb_MultiportSwitch1_tmp = idx + 3 * i;
          Mainframe_B.T12_a[rtb_MultiportSwitch1_tmp] = 0.0;
          Mainframe_B.T12_a[rtb_MultiportSwitch1_tmp] += rtb_Product2_mq[3 * i] *
            rtb_MultiportSwitch2[idx];
          Mainframe_B.T12_a[rtb_MultiportSwitch1_tmp] += rtb_Product2_mq[3 * i +
            1] * rtb_MultiportSwitch2[idx + 3];
          Mainframe_B.T12_a[rtb_MultiportSwitch1_tmp] += rtb_Product2_mq[3 * i +
            2] * rtb_MultiportSwitch2[idx + 6];
        }
      }

      /* End of Product: '<S264>/3. Rotation' */

      /* Sum: '<S259>/Subtract' incorporates:
       *  Constant: '<S259>/Constant16'
       *  Constant: '<S259>/Constant17'
       */
      for (i = 0; i < 9; i++) {
        Mainframe_B.Subtract_k[i] = Mainframe_P.Constant17_Value_c[i] -
          Mainframe_P.Constant16_Value_g[i];
      }

      /* End of Sum: '<S259>/Subtract' */

      /* Sum: '<S259>/Subtract4' incorporates:
       *  Constant: '<S259>/Constant18'
       *  Constant: '<S259>/Constant19'
       */
      Mainframe_B.Subtract4 = Mainframe_P.Constant19_Value -
        Mainframe_P.Constant18_Value;

      /* Math: '<S260>/Math Function' */
      for (i = 0; i < 3; i++) {
        Mainframe_B.MathFunction[3 * i] = Mainframe_B.T12_a[i];
        Mainframe_B.MathFunction[3 * i + 1] = Mainframe_B.T12_a[i + 3];
        Mainframe_B.MathFunction[3 * i + 2] = Mainframe_B.T12_a[i + 6];
      }

      /* End of Math: '<S260>/Math Function' */
    }

    /* Sum: '<S259>/Subtract5' incorporates:
     *  Constant: '<S259>/Constant20'
     */
    rtb_T_sim_glbl = rtb_TrigonometricFunction1_j - Mainframe_P.Constant20_Value;

    /* Sum: '<S259>/Subtract6' incorporates:
     *  Constant: '<S259>/Constant21'
     *  Product: '<S259>/Divide'
     */
    for (i = 0; i < 9; i++) {
      rtb_MultiportSwitch1[i] = rtb_T_sim_glbl * Mainframe_B.Subtract_k[i] /
        Mainframe_B.Subtract4 + Mainframe_P.Constant21_Value[i];
    }

    /* End of Sum: '<S259>/Subtract6' */
    for (i = 0; i < 3; i++) {
      /* Product: '<S260>/Matrix Multiply' */
      for (idx = 0; idx < 3; idx++) {
        rtb_MultiportSwitch1_tmp = i + 3 * idx;
        rtb_MultiportSwitch2[rtb_MultiportSwitch1_tmp] = 0.0;
        rtb_MultiportSwitch2[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch1[3
          * idx] * Mainframe_B.T12_a[i];
        rtb_MultiportSwitch2[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch1[3
          * idx + 1] * Mainframe_B.T12_a[i + 3];
        rtb_MultiportSwitch2[rtb_MultiportSwitch1_tmp] += rtb_MultiportSwitch1[3
          * idx + 2] * Mainframe_B.T12_a[i + 6];
      }

      /* End of Product: '<S260>/Matrix Multiply' */

      /* Sum: '<S261>/Add7' incorporates:
       *  Constant: '<S261>/Constant16'
       *  Product: '<S260>/Matrix Multiply1'
       *  Product: '<S263>/Product'
       *  Sum: '<S258>/Add'
       *  Sum: '<S258>/Add4'
       */
      for (idx = 0; idx < 3; idx++) {
        /* Product: '<S263>/Product' incorporates:
         *  Constant: '<S261>/Constant16'
         *  Product: '<S260>/Matrix Multiply1'
         *  Sum: '<S258>/Add4'
         */
        rtb_MultiportSwitch1_tmp = 3 * idx + i;
        rtb_MultiportSwitch[rtb_MultiportSwitch1_tmp] =
          ((((Mainframe_B.MathFunction[3 * idx + 1] * rtb_MultiportSwitch2[i + 3]
              + Mainframe_B.MathFunction[3 * idx] * rtb_MultiportSwitch2[i]) +
             Mainframe_B.MathFunction[3 * idx + 2] * rtb_MultiportSwitch2[i + 6])
            + rtb_JMMB[rtb_MultiportSwitch1_tmp] * rtb_TrigonometricFunction1_j)
           + rtb_MathFunction2[rtb_MultiportSwitch1_tmp]) +
          Mainframe_P.Constant16_Value_gd[rtb_MultiportSwitch1_tmp];
      }

      /* End of Sum: '<S261>/Add7' */
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S122>/Gain' incorporates:
       *  Constant: '<S122>/Constant'
       */
      Mainframe_B.pAPB[0] = Mainframe_P.Gain_Gain_kk *
        Mainframe_P.Constant_Value_mx;

      /* SignalConversion generated from: '<S122>/Vector Concatenate' incorporates:
       *  Constant: '<S122>/Constant3'
       */
      Mainframe_B.pAPB[1] = Mainframe_P.Constant3_Value_pw;

      /* SignalConversion generated from: '<S122>/Vector Concatenate' incorporates:
       *  Constant: '<S122>/Constant3'
       */
      Mainframe_B.pAPB[2] = Mainframe_P.Constant3_Value_pw;

      /* Switch: '<S130>/Switch1' incorporates:
       *  Constant: '<S130>/Constant'
       *  Constant: '<S130>/Constant2'
       *  Constant: '<S131>/c_flat'
       *  Constant: '<S131>/c_rsma'
       *  Constant: '<S132>/Constant'
       *  Gain: '<S130>/Gain'
       *  Gain: '<S132>/Gain'
       *  Product: '<S132>/Product'
       *  Product: '<S132>/Product4'
       *  Product: '<S132>/Product5'
       *  Sqrt: '<S132>/Sqrt1'
       *  Sum: '<S132>/Subtract'
       *  Sum: '<S132>/Subtract1'
       *  Sum: '<S132>/Sum'
       *  Trigonometry: '<S132>/cos(latGD)'
       */
      if (Mainframe_P.Constant2_Value_je > Mainframe_P.Switch1_Threshold_m) {
        Mainframe_B.hBE_0_c = Mainframe_P.Gain_Gain_bf *
          Mainframe_P.Constant_Value_ixx[2];
      } else {
        /* Sqrt: '<S133>/Sqrt' incorporates:
         *  Constant: '<S130>/Constant'
         *  Product: '<S133>/Product1'
         *  Product: '<S133>/Product2'
         *  Sqrt: '<S132>/Sqrt'
         *  Sum: '<S133>/Add'
         */
        rtb_T_sim_glbl = sqrt(Mainframe_P.Constant_Value_ixx[0] *
                              Mainframe_P.Constant_Value_ixx[0] +
                              Mainframe_P.Constant_Value_ixx[1] *
                              Mainframe_P.Constant_Value_ixx[1]);

        /* Product: '<S133>/Product' incorporates:
         *  Constant: '<S131>/c_flat'
         *  Constant: '<S131>/c_rsma'
         *  Constant: '<S133>/Constant'
         *  Sum: '<S133>/Subtract'
         */
        rtb_TrigonometricFunction1_j = (Mainframe_P.Constant_Value_k -
          Mainframe_P.c_flat_Value_k) * Mainframe_P.c_rsma_Value_j;

        /* Trigonometry: '<S133>/Trigonometric Function' incorporates:
         *  Constant: '<S130>/Constant'
         *  Constant: '<S131>/c_rsma'
         *  Product: '<S133>/Divide1'
         *  Product: '<S133>/Product6'
         *  Product: '<S133>/Product7'
         *  Sqrt: '<S133>/Sqrt'
         */
        rtb_Product2_l = atan(Mainframe_P.Constant_Value_ixx[2] *
                              Mainframe_P.c_rsma_Value_j / (rtb_T_sim_glbl *
          rtb_TrigonometricFunction1_j));

        /* Trigonometry: '<S133>/Trigonometric Function3' */
        rtb_ixk_k = cos(rtb_Product2_l);

        /* Product: '<S133>/Product9' */
        beta = rtb_ixk_k * rtb_ixk_k * rtb_ixk_k;

        /* Trigonometry: '<S133>/Trigonometric Function2' */
        rtb_Product2_l = sin(rtb_Product2_l);

        /* Product: '<S133>/Product5' */
        rtb_ixk_k = rtb_TrigonometricFunction1_j * rtb_TrigonometricFunction1_j;

        /* Product: '<S133>/Product10' incorporates:
         *  Constant: '<S131>/c_rsma'
         *  Product: '<S133>/Divide'
         *  Product: '<S133>/Product4'
         *  Product: '<S133>/Product8'
         *  Sum: '<S133>/Subtract2'
         */
        rtb_TrigonometricFunction1_j = (Mainframe_P.c_rsma_Value_j *
          Mainframe_P.c_rsma_Value_j - rtb_ixk_k) / rtb_ixk_k *
          rtb_TrigonometricFunction1_j * (rtb_Product2_l * rtb_Product2_l *
          rtb_Product2_l);

        /* Sum: '<S133>/Add1' incorporates:
         *  Constant: '<S130>/Constant'
         */
        rtb_TrigonometricFunction1_j += Mainframe_P.Constant_Value_ixx[2];

        /* Product: '<S133>/Product3' incorporates:
         *  Constant: '<S131>/c_flat'
         *  Product: '<S132>/Product3'
         */
        rtb_VectorConcatenate3_tmp = Mainframe_P.c_flat_Value_k *
          Mainframe_P.c_flat_Value_k;

        /* Trigonometry: '<S133>/Trigonometric Function1' incorporates:
         *  Constant: '<S131>/c_flat'
         *  Constant: '<S131>/c_rsma'
         *  Gain: '<S133>/Gain'
         *  Product: '<S133>/Divide2'
         *  Product: '<S133>/Product11'
         *  Product: '<S133>/Product3'
         *  Sqrt: '<S133>/Sqrt'
         *  Sum: '<S133>/Subtract1'
         *  Sum: '<S133>/Subtract3'
         */
        rtb_ixk_k = atan(rtb_TrigonometricFunction1_j / (rtb_T_sim_glbl -
          (Mainframe_P.Gain_Gain_ig * Mainframe_P.c_flat_Value_k -
           rtb_VectorConcatenate3_tmp) * Mainframe_P.c_rsma_Value_j * beta));

        /* Trigonometry: '<S132>/Trigonometric Function' */
        rtb_Product2_l = sin(rtb_ixk_k);
        Mainframe_B.hBE_0_c = rtb_T_sim_glbl / cos(rtb_ixk_k) -
          Mainframe_P.c_rsma_Value_j / sqrt(Mainframe_P.Constant_Value_lg -
          (Mainframe_P.Gain_Gain_nm * Mainframe_P.c_flat_Value_k -
           rtb_VectorConcatenate3_tmp) * (rtb_Product2_l * rtb_Product2_l));
      }

      /* End of Switch: '<S130>/Switch1' */

      /* SignalConversion generated from: '<S125>/Vector Concatenate' incorporates:
       *  Constant: '<S125>/Constant3'
       */
      Mainframe_B.VectorConcatenate_h[0] = Mainframe_P.Constant3_Value_b;

      /* SignalConversion generated from: '<S125>/Vector Concatenate' incorporates:
       *  Constant: '<S125>/Constant3'
       */
      Mainframe_B.VectorConcatenate_h[1] = Mainframe_P.Constant3_Value_b;

      /* SignalConversion generated from: '<S125>/Vector Concatenate' incorporates:
       *  Constant: '<S125>/Constant3'
       */
      Mainframe_B.VectorConcatenate_h[2] = Mainframe_P.Constant3_Value_b;
    }

    /* Switch: '<S125>/Switch' incorporates:
     *  Constant: '<S125>/Constant1'
     *  Sum: '<S115>/Add'
     *  Sum: '<S115>/Subtract'
     *  Sum: '<S125>/Subtract'
     */
    if ((Mainframe_B.Switch[2] + Mainframe_P.Constant1_Value_k5) -
        Mainframe_B.hBE_0_c > Mainframe_P.Switch_Threshold_j) {
      /* Saturate: '<S251>/Saturation1' */
      if (rtb_Product4_b_idx_3 > Mainframe_P.Saturation1_UpperSat) {
        rtb_Product4_b_idx_3 = Mainframe_P.Saturation1_UpperSat;
      } else {
        if (rtb_Product4_b_idx_3 < Mainframe_P.Saturation1_LowerSat) {
          rtb_Product4_b_idx_3 = Mainframe_P.Saturation1_LowerSat;
        }
      }

      /* End of Saturate: '<S251>/Saturation1' */

      /* Product: '<S251>/Divide1' incorporates:
       *  Constant: '<S251>/Constant1'
       *  Gain: '<S251>/Gain'
       */
      rtb_Product4_b_idx_3 = 1.0 / (Mainframe_P.Gain_Gain_n *
        rtb_Product4_b_idx_3) * Mainframe_P.Constant1_Value_cs;

      /* Product: '<S115>/Product1' incorporates:
       *  Constant: '<S115>/Constant1'
       *  Constant: '<S116>/Constant'
       *  Gain: '<S116>/Gain'
       *  Gain: '<S116>/Gain2'
       *  Product: '<S251>/Product2'
       *  Sum: '<S116>/Sum'
       */
      rtb_afinB[0] = ((Mainframe_P.Gain_Gain_g * rtb_afinB[0] +
                       Mainframe_P.Constant_Value_bp) + rtb_Product4_b_idx_3 *
                      Mainframe_B.x_d[10] * Mainframe_P.Gain2_Gain_e) *
        rtb_Product4_b_idx_2 * Mainframe_P.Constant1_Value_a;
      rtb_TrigonometricFunction1_j = Mainframe_B.pAPB[0] - rtb_Sum1_e[0];

      /* Product: '<S115>/Product1' incorporates:
       *  Constant: '<S115>/Constant1'
       *  Constant: '<S117>/Constant'
       *  Gain: '<S117>/Gain'
       *  Gain: '<S117>/Gain1'
       *  Gain: '<S117>/Gain2'
       *  Product: '<S251>/Product3'
       *  Sum: '<S115>/Subtract'
       *  Sum: '<S117>/Sum'
       */
      rtb_afinB[1] = (((Mainframe_P.Gain1_Gain_k * rtb_Switch_j +
                        Mainframe_P.Constant_Value_ce) + Mainframe_P.Gain_Gain_i
                       * rtb_afinB[1]) + rtb_Product4_b_idx_3 * Mainframe_B.x_d
                      [11] * Mainframe_P.Gain2_Gain_c) * rtb_Product4_b_idx_2 *
        Mainframe_P.Constant1_Value_a;
      rtb_Switch_j = Mainframe_B.pAPB[1] - rtb_Sum1_e[1];

      /* Product: '<S115>/Product1' incorporates:
       *  Constant: '<S115>/Constant1'
       *  Constant: '<S118>/Constant'
       *  Gain: '<S118>/Gain'
       *  Gain: '<S118>/Gain1'
       *  Gain: '<S118>/Gain2'
       *  Product: '<S251>/Product4'
       *  Sum: '<S115>/Subtract'
       *  Sum: '<S118>/Sum'
       */
      rtb_afinB[2] = (((Mainframe_P.Gain1_Gain * rtb_Product4_b_idx_1 +
                        Mainframe_P.Constant_Value_f1) + Mainframe_P.Gain_Gain_p
                       * rtb_afinB[2]) + rtb_Product4_b_idx_3 * Mainframe_B.x_d
                      [12] * Mainframe_P.Gain2_Gain) * rtb_Product4_b_idx_2 *
        Mainframe_P.Constant1_Value_a;

      /* Sum: '<S115>/Subtract' */
      q0_tmp = Mainframe_B.pAPB[2] - rtb_Sum1_e[2];

      /* Sum: '<S123>/Sum2' incorporates:
       *  Product: '<S123>/Product6'
       *  Product: '<S123>/Product7'
       */
      rtb_VectorConcatenate_m[2] = rtb_TrigonometricFunction1_j * rtb_wEIE[1] -
        rtb_Switch_j * rtb_wEIE[0];

      /* Sum: '<S123>/Sum1' incorporates:
       *  Product: '<S123>/Product4'
       *  Product: '<S123>/Product5'
       */
      rtb_VectorConcatenate_m[1] = q0_tmp * rtb_wEIE[0] -
        rtb_TrigonometricFunction1_j * rtb_wEIE[2];

      /* Sum: '<S123>/Sum' incorporates:
       *  Product: '<S123>/Product2'
       *  Product: '<S123>/Product3'
       */
      rtb_VectorConcatenate_m[0] = rtb_Switch_j * rtb_wEIE[2] - q0_tmp *
        rtb_wEIE[1];
      rtb_VectorConcatenate_m[0] += rtb_afinB[0];
      rtb_VectorConcatenate_m[1] += rtb_afinB[1];
      rtb_VectorConcatenate_m[2] += rtb_afinB[2];
    } else {
      rtb_VectorConcatenate_m[0] = Mainframe_B.VectorConcatenate_h[0];
      rtb_VectorConcatenate_m[1] = Mainframe_B.VectorConcatenate_h[1];
      rtb_VectorConcatenate_m[2] = Mainframe_B.VectorConcatenate_h[2];
    }

    /* End of Switch: '<S125>/Switch' */

    /* Sum: '<S195>/Subtract' incorporates:
     *  Constant: '<S195>/pNPB'
     */
    rtb_Sum1_e[0] -= Mainframe_P.pNPB_Value[0];
    rtb_Sum1_e[1] -= Mainframe_P.pNPB_Value[1];
    rtb_TrigonometricFunction1_j = rtb_Sum1_e[2] - Mainframe_P.pNPB_Value[2];

    /* Sum: '<S197>/Sum' incorporates:
     *  Product: '<S197>/Product2'
     *  Product: '<S197>/Product3'
     */
    rtb_afinB[0] = rtb_Sum1_e[1] * rtb_u2[2] - rtb_TrigonometricFunction1_j *
      rtb_u2[1];

    /* Sum: '<S197>/Sum1' incorporates:
     *  Product: '<S197>/Product4'
     *  Product: '<S197>/Product5'
     */
    rtb_afinB[1] = rtb_TrigonometricFunction1_j * rtb_u2[0] - rtb_Sum1_e[0] *
      rtb_u2[2];

    /* Sum: '<S197>/Sum2' incorporates:
     *  Product: '<S197>/Product6'
     *  Product: '<S197>/Product7'
     */
    rtb_afinB[2] = rtb_Sum1_e[0] * rtb_u2[1] - rtb_Sum1_e[1] * rtb_u2[0];

    /* Product: '<S240>/Product1' */
    for (i = 0; i < 3; i++) {
      rtb_u2[i] = rtb_MultiportSwitch[i + 6] * Mainframe_B.x_d[12] +
        (rtb_MultiportSwitch[i + 3] * Mainframe_B.x_d[11] +
         rtb_MultiportSwitch[i] * Mainframe_B.x_d[10]);
    }

    /* End of Product: '<S240>/Product1' */

    /* Sum: '<S243>/Sum' incorporates:
     *  Product: '<S243>/Product2'
     *  Product: '<S243>/Product3'
     */
    rtb_Sum1_e[0] = Mainframe_B.x_d[11] * rtb_u2[2] - Mainframe_B.x_d[12] *
      rtb_u2[1];

    /* Sum: '<S243>/Sum1' incorporates:
     *  Product: '<S243>/Product4'
     *  Product: '<S243>/Product5'
     */
    rtb_Sum1_e[1] = Mainframe_B.x_d[12] * rtb_u2[0] - Mainframe_B.x_d[10] *
      rtb_u2[2];

    /* Sum: '<S243>/Sum2' incorporates:
     *  Product: '<S243>/Product6'
     *  Product: '<S243>/Product7'
     */
    rtb_Sum1_e[2] = Mainframe_B.x_d[10] * rtb_u2[1] - Mainframe_B.x_d[11] *
      rtb_u2[0];

    /* Sum: '<S240>/Subtract' incorporates:
     *  Constant: '<S208>/Constant9'
     *  Product: '<S240>/Product'
     *  Sum: '<S104>/Add1'
     */
    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate_fo[i] = ((rtb_VectorConcatenate_m[i] + rtb_afinB[i])
        - ((Mainframe_P.Constant9_Value_l[i + 3] * Mainframe_B.x_d[11] +
            Mainframe_P.Constant9_Value_l[i] * Mainframe_B.x_d[10]) +
           Mainframe_P.Constant9_Value_l[i + 6] * Mainframe_B.x_d[12])) -
        rtb_Sum1_e[i];
    }

    /* End of Sum: '<S240>/Subtract' */

    /* Product: '<S240>/Divide1' */
    rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(rtb_MultiportSwitch,
      rtb_VectorConcatenate_fo, rtb_u2);

    /* Reshape: '<S238>/Reshape1' */
    Mainframe_B.d_wBIB[0] = rtb_u2[0];

    /* Gain: '<S81>/Zero-Order Hold3' */
    rtb_Sum1_e[0] = Mainframe_P.ZeroOrderHold3_Gain * Mainframe_B.d_wBIB[0];

    /* Reshape: '<S238>/Reshape1' */
    Mainframe_B.d_wBIB[1] = rtb_u2[1];

    /* Gain: '<S81>/Zero-Order Hold3' */
    rtb_Sum1_e[1] = Mainframe_P.ZeroOrderHold3_Gain * Mainframe_B.d_wBIB[1];

    /* Reshape: '<S238>/Reshape1' */
    Mainframe_B.d_wBIB[2] = rtb_u2[2];

    /* Gain: '<S81>/Zero-Order Hold3' */
    rtb_Sum1_e[2] = Mainframe_P.ZeroOrderHold3_Gain * Mainframe_B.d_wBIB[2];

    /* Sum: '<S81>/Sum' incorporates:
     *  Gain: '<S81>/Zero-Order Hold1'
     *  Product: '<S95>/i x j'
     *  Product: '<S95>/j x k'
     *  Product: '<S95>/k x i'
     *  Product: '<S96>/i x k'
     *  Product: '<S96>/j x i'
     *  Product: '<S96>/k x j'
     *  Sum: '<S86>/Sum'
     */
    rtb_Sum4[0] = ((Mainframe_P.ZeroOrderHold1_Gain * Mainframe_B.aBIB[0] -
                    rtb_ZeroOrderHold2_c[0]) + rtb_Sum4[0]) + (rtb_Sum1_e[1] *
      Mainframe_B.Gain_ln[2] - rtb_Sum1_e[2] * Mainframe_B.Gain_ln[1]);
    rtb_Sum4[1] = ((Mainframe_P.ZeroOrderHold1_Gain * Mainframe_B.aBIB[1] -
                    rtb_ZeroOrderHold2_c[1]) + rtb_Sum4[1]) + (rtb_Sum1_e[2] *
      Mainframe_B.Gain_ln[0] - rtb_Sum1_e[0] * Mainframe_B.Gain_ln[2]);
    rtb_Switch_j = ((Mainframe_P.ZeroOrderHold1_Gain * Mainframe_B.aBIB[2] -
                     rtb_ZeroOrderHold2_c[2]) + rtb_Sum4[2]) + (rtb_Sum1_e[0] *
      Mainframe_B.Gain_ln[1] - rtb_Sum1_e[1] * Mainframe_B.Gain_ln[0]);

    /* Gain: '<S88>/wn^2' */
    rtb_T_sim_glbl = Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a;

    /* Switch: '<S83>/Switch' incorporates:
     *  Constant: '<S83>/Constant'
     */
    tmp_0 = (Mainframe_P.Constant_Value_fd >= Mainframe_P.Switch_Threshold_p);
    for (i = 0; i < 3; i++) {
      /* Sum: '<S88>/Sum3' */
      rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[i];

      /* Sum: '<S81>/Sum4' incorporates:
       *  Constant: '<S81>/Measurement bias'
       *  Constant: '<S81>/Scale factors & Cross-coupling  errors'
       *  Product: '<S81>/Product'
       */
      rtb_TrigonometricFunction1_j =
        ((Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i + 3] *
          rtb_Sum4[1] + Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i] *
          rtb_Sum4[0]) + Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i
         + 6] * rtb_Switch_j) +
        Mainframe_P.ThreeaxisInertialMeasurementUnit_a_bias[i];

      /* Sum: '<S88>/Sum2' incorporates:
       *  Gain: '<S88>/wn^2'
       *  Sum: '<S88>/Sum3'
       */
      Mainframe_B.Sum2_b[i] = (rtb_TrigonometricFunction1_j -
        rtb_IntegratorSecondOrderLimited_o2_a[i]) * rtb_T_sim_glbl -
        rtb_uzetawn_p[i];

      /* Switch: '<S83>/Switch' */
      if (!tmp_0) {
        rtb_ixk_k = rtb_TrigonometricFunction1_j;
      }

      rtb_IntegratorSecondOrderLimited_o2_a[i] = rtb_ixk_k;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
      /* Sqrt: '<S84>/Sqrt1' incorporates:
       *  Constant: '<S84>/Constant1'
       */
      rtb_Switch_j = sqrt(Mainframe_P.Randombias_Ts);

      /* Product: '<S84>/Product' incorporates:
       *  Constant: '<S84>/Constant'
       *  Product: '<S84>/Divide'
       *  RandomNumber: '<S84>/White Noise'
       *  Sqrt: '<S84>/Sqrt'
       */
      Mainframe_B.Product_k[0] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow[0])
        / rtb_Switch_j * Mainframe_DW.NextOutput_mb[0];
      Mainframe_B.Product_k[1] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow[1])
        / rtb_Switch_j * Mainframe_DW.NextOutput_mb[1];
      Mainframe_B.Product_k[2] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow[2])
        / rtb_Switch_j * Mainframe_DW.NextOutput_mb[2];
    }

    /* Gain: '<S100>/2*zeta * wn' */
    rtb_T_sim_glbl = 2.0 * Mainframe_P.ThreeaxisInertialMeasurementUnit_z_g *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g;

    /* Sum: '<S81>/Sum1' */
    rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[0] +
      Mainframe_B.Product_k[0];

    /* Saturate: '<S81>/Saturation' */
    if (rtb_ixk_k > Mainframe_P.Saturation_UpperSat_j[0]) {
      Mainframe_B.Saturation_j[0] = Mainframe_P.Saturation_UpperSat_j[0];
    } else if (rtb_ixk_k < Mainframe_P.Saturation_LowerSat_p[0]) {
      Mainframe_B.Saturation_j[0] = Mainframe_P.Saturation_LowerSat_p[0];
    } else {
      Mainframe_B.Saturation_j[0] = rtb_ixk_k;
    }

    /* SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    rtb_Sum4[0] = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[0];

    /* Gain: '<S100>/2*zeta * wn' incorporates:
     *  SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited'
     */
    rtb_wEIE[0] = rtb_T_sim_glbl *
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[3];

    /* Sum: '<S81>/Sum1' incorporates:
     *  Gain: '<S82>/Zero-Order Hold'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[0] = Mainframe_P.ZeroOrderHold_Gain_k *
      Mainframe_B.x_d[10];
    rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[1] +
      Mainframe_B.Product_k[1];

    /* Saturate: '<S81>/Saturation' */
    if (rtb_ixk_k > Mainframe_P.Saturation_UpperSat_j[1]) {
      Mainframe_B.Saturation_j[1] = Mainframe_P.Saturation_UpperSat_j[1];
    } else if (rtb_ixk_k < Mainframe_P.Saturation_LowerSat_p[1]) {
      Mainframe_B.Saturation_j[1] = Mainframe_P.Saturation_LowerSat_p[1];
    } else {
      Mainframe_B.Saturation_j[1] = rtb_ixk_k;
    }

    /* SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    rtb_Sum4[1] = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[1];

    /* Gain: '<S100>/2*zeta * wn' incorporates:
     *  SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited'
     */
    rtb_wEIE[1] = rtb_T_sim_glbl *
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[4];

    /* Sum: '<S81>/Sum1' incorporates:
     *  Gain: '<S82>/Zero-Order Hold'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[1] = Mainframe_P.ZeroOrderHold_Gain_k *
      Mainframe_B.x_d[11];
    rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[2] +
      Mainframe_B.Product_k[2];

    /* Saturate: '<S81>/Saturation' */
    if (rtb_ixk_k > Mainframe_P.Saturation_UpperSat_j[2]) {
      Mainframe_B.Saturation_j[2] = Mainframe_P.Saturation_UpperSat_j[2];
    } else if (rtb_ixk_k < Mainframe_P.Saturation_LowerSat_p[2]) {
      Mainframe_B.Saturation_j[2] = Mainframe_P.Saturation_LowerSat_p[2];
    } else {
      Mainframe_B.Saturation_j[2] = rtb_ixk_k;
    }

    /* SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    rtb_Sum4[2] = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[2];

    /* Gain: '<S100>/2*zeta * wn' incorporates:
     *  SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited'
     */
    rtb_wEIE[2] = rtb_T_sim_glbl *
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[5];

    /* Gain: '<S82>/Zero-Order Hold' */
    rtb_ixk_k = Mainframe_P.ZeroOrderHold_Gain_k * Mainframe_B.x_d[12];

    /* Gain: '<S100>/wn^2' */
    rtb_T_sim_glbl = Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g;

    /* Switch: '<S97>/Switch' incorporates:
     *  Constant: '<S97>/Constant'
     */
    tmp_0 = (Mainframe_P.Constant_Value_p3 >= Mainframe_P.Switch_Threshold_i0);
    for (i = 0; i < 3; i++) {
      /* Sum: '<S100>/Sum3' */
      rtb_Switch_j = rtb_Sum4[i];

      /* Sum: '<S82>/Sum4' incorporates:
       *  Constant: '<S82>/Measurement bias'
       *  Constant: '<S82>/Scale factors & Cross-coupling  errors '
       *  Constant: '<S82>/g-sensitive bias'
       *  Gain: '<S82>/Zero-Order Hold1'
       *  Product: '<S82>/Product'
       *  Product: '<S82>/Product1'
       *  UnitConversion: '<S80>/Unit Conversion'
       */
      rtb_TrigonometricFunction1_j =
        (((Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sf_cc[i + 3] *
           rtb_IntegratorSecondOrderLimited_o2_a[1] +
           Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sf_cc[i] *
           rtb_IntegratorSecondOrderLimited_o2_a[0]) +
          Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sf_cc[i + 6] *
          rtb_ixk_k) + Mainframe_P.ThreeaxisInertialMeasurementUnit_g_bias[i]) +
        0.10197162129779282 * Mainframe_B.aBIB[i] *
        Mainframe_P.ZeroOrderHold1_Gain_k *
        Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sens[i];

      /* Sum: '<S100>/Sum2' incorporates:
       *  Gain: '<S100>/wn^2'
       *  Sum: '<S100>/Sum3'
       */
      Mainframe_B.Sum2_h[i] = (rtb_TrigonometricFunction1_j - rtb_Sum4[i]) *
        rtb_T_sim_glbl - rtb_wEIE[i];

      /* Switch: '<S97>/Switch' */
      if (!tmp_0) {
        rtb_Switch_j = rtb_TrigonometricFunction1_j;
      }

      rtb_Sum4[i] = rtb_Switch_j;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
      /* Sqrt: '<S98>/Sqrt1' incorporates:
       *  Constant: '<S98>/Constant1'
       */
      rtb_Switch_j = sqrt(Mainframe_P.Randombias_Ts_n);

      /* Product: '<S98>/Product' incorporates:
       *  Constant: '<S98>/Constant'
       *  Product: '<S98>/Divide'
       *  RandomNumber: '<S98>/White Noise'
       *  Sqrt: '<S98>/Sqrt'
       */
      Mainframe_B.Product_g[0] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow[0]) /
        rtb_Switch_j * Mainframe_DW.NextOutput_i[0];
      Mainframe_B.Product_g[1] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow[1]) /
        rtb_Switch_j * Mainframe_DW.NextOutput_i[1];
      Mainframe_B.Product_g[2] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow[2]) /
        rtb_Switch_j * Mainframe_DW.NextOutput_i[2];
    }

    /* Sum: '<S82>/Sum1' */
    rtb_Switch_j = rtb_Sum4[0] + Mainframe_B.Product_g[0];

    /* Saturate: '<S82>/Saturation' */
    if (rtb_Switch_j > Mainframe_P.Saturation_UpperSat_pp[0]) {
      Mainframe_B.Saturation_je[0] = Mainframe_P.Saturation_UpperSat_pp[0];
    } else if (rtb_Switch_j < Mainframe_P.Saturation_LowerSat_ga[0]) {
      Mainframe_B.Saturation_je[0] = Mainframe_P.Saturation_LowerSat_ga[0];
    } else {
      Mainframe_B.Saturation_je[0] = rtb_Switch_j;
    }

    /* Sum: '<S82>/Sum1' */
    rtb_Switch_j = rtb_Sum4[1] + Mainframe_B.Product_g[1];

    /* Saturate: '<S82>/Saturation' */
    if (rtb_Switch_j > Mainframe_P.Saturation_UpperSat_pp[1]) {
      Mainframe_B.Saturation_je[1] = Mainframe_P.Saturation_UpperSat_pp[1];
    } else if (rtb_Switch_j < Mainframe_P.Saturation_LowerSat_ga[1]) {
      Mainframe_B.Saturation_je[1] = Mainframe_P.Saturation_LowerSat_ga[1];
    } else {
      Mainframe_B.Saturation_je[1] = rtb_Switch_j;
    }

    /* Sum: '<S82>/Sum1' */
    rtb_Switch_j = rtb_Sum4[2] + Mainframe_B.Product_g[2];

    /* Saturate: '<S82>/Saturation' */
    if (rtb_Switch_j > Mainframe_P.Saturation_UpperSat_pp[2]) {
      Mainframe_B.Saturation_je[2] = Mainframe_P.Saturation_UpperSat_pp[2];
    } else if (rtb_Switch_j < Mainframe_P.Saturation_LowerSat_ga[2]) {
      Mainframe_B.Saturation_je[2] = Mainframe_P.Saturation_LowerSat_ga[2];
    } else {
      Mainframe_B.Saturation_je[2] = rtb_Switch_j;
    }

    /* RelationalOperator: '<S138>/Compare' incorporates:
     *  Constant: '<S138>/Constant'
     */
    Mainframe_B.Compare = (rtb_Sqrt_cv >= Mainframe_P.CompareToConstant_const);
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Assertion: '<S135>/Assertion' */
      utAssert(Mainframe_B.Compare);
    }

    /* Logic: '<S139>/AND' incorporates:
     *  Constant: '<S139>/Lower Limit'
     *  Constant: '<S139>/Upper Limit'
     *  RelationalOperator: '<S139>/Lower Test'
     *  RelationalOperator: '<S139>/Upper Test'
     */
    Mainframe_B.AND_c = ((Mainframe_P.IntervalTest_lowlimit <=
                          Mainframe_B.Switch[0]) && (Mainframe_B.Switch[0] <=
      Mainframe_P.IntervalTest_uplimit));
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Assertion: '<S135>/Assertion1' */
      utAssert(Mainframe_B.AND_c);
    }

    /* Logic: '<S140>/AND' incorporates:
     *  Constant: '<S140>/Lower Limit'
     *  Constant: '<S140>/Upper Limit'
     *  RelationalOperator: '<S140>/Lower Test'
     *  RelationalOperator: '<S140>/Upper Test'
     */
    Mainframe_B.AND_cl = ((Mainframe_P.IntervalTest1_lowlimit <=
      Mainframe_B.Switch[1]) && (Mainframe_B.Switch[1] <=
      Mainframe_P.IntervalTest1_uplimit));
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Assertion: '<S135>/Assertion2' */
      utAssert(Mainframe_B.AND_cl);
    }

    /* Integrator: '<S151>/Integrator' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &Mainframe_PrevZCX.Integrator_Reset_ZCE,
                         (Mainframe_B.sat));

      /* evaluate zero-crossings */
      if (zcEvent != NO_ZCEVENT) {
        Mainframe_X.Integrator_CSTATE = Mainframe_P.Rudder_d_siB_0;
      }
    }

    rtb_d_siB = Mainframe_X.Integrator_CSTATE;

    /* End of Integrator: '<S151>/Integrator' */

    /* MATLAB Function: '<S151>/Limiting_Rate' */
    Mainframe_Limiting_Rate(rtb_siB, rtb_d_siB, &Mainframe_B.sf_Limiting_Rate,
      Mainframe_P.Rudder_d_siB_max, Mainframe_P.Rudder_d_siB_min,
      Mainframe_P.Rudder_siB_max, Mainframe_P.Rudder_siB_min);

    /* Integrator: '<S152>/Integrator' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &Mainframe_PrevZCX.Integrator_Reset_ZCE_e,
                         (Mainframe_B.sat_d));

      /* evaluate zero-crossings */
      if (zcEvent != NO_ZCEVENT) {
        Mainframe_X.Integrator_CSTATE_g = Mainframe_P.Rudder1_d_siB_0;
      }
    }

    rtb_d_siB_g = Mainframe_X.Integrator_CSTATE_g;

    /* End of Integrator: '<S152>/Integrator' */

    /* MATLAB Function: '<S152>/Limiting_Rate' */
    Mainframe_Limiting_Rate(rtb_siB_a, rtb_d_siB_g,
      &Mainframe_B.sf_Limiting_Rate_g, Mainframe_P.Rudder1_d_siB_max,
      Mainframe_P.Rudder1_d_siB_min, Mainframe_P.Rudder1_siB_max,
      Mainframe_P.Rudder1_siB_min);

    /* Integrator: '<S153>/Integrator' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &Mainframe_PrevZCX.Integrator_Reset_ZCE_o,
                         (Mainframe_B.sat_a));

      /* evaluate zero-crossings */
      if (zcEvent != NO_ZCEVENT) {
        Mainframe_X.Integrator_CSTATE_f = Mainframe_P.Rudder2_d_siB_0;
      }
    }

    rtb_d_siB_j = Mainframe_X.Integrator_CSTATE_f;

    /* End of Integrator: '<S153>/Integrator' */

    /* MATLAB Function: '<S153>/Limiting_Rate' */
    Mainframe_Limiting_Rate(rtb_siB_e, rtb_d_siB_j,
      &Mainframe_B.sf_Limiting_Rate_a, Mainframe_P.Rudder2_d_siB_max,
      Mainframe_P.Rudder2_d_siB_min, Mainframe_P.Rudder2_siB_max,
      Mainframe_P.Rudder2_siB_min);

    /* Integrator: '<S154>/Integrator' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &Mainframe_PrevZCX.Integrator_Reset_ZCE_p,
                         (Mainframe_B.sat_p));

      /* evaluate zero-crossings */
      if (zcEvent != NO_ZCEVENT) {
        Mainframe_X.Integrator_CSTATE_o = Mainframe_P.Rudder3_d_siB_0;
      }
    }

    rtb_d_siB_b = Mainframe_X.Integrator_CSTATE_o;

    /* End of Integrator: '<S154>/Integrator' */

    /* MATLAB Function: '<S154>/Limiting_Rate' */
    Mainframe_Limiting_Rate(rtb_siB_i, rtb_d_siB_b,
      &Mainframe_B.sf_Limiting_Rate_o, Mainframe_P.Rudder3_d_siB_max,
      Mainframe_P.Rudder3_d_siB_min, Mainframe_P.Rudder3_siB_max,
      Mainframe_P.Rudder3_siB_min);

    /* Saturate: '<S151>/Saturation' */
    if (rtb_VectorConcatenate_hw[0] > Mainframe_P.Rudder_siB_max) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder_siB_max;
    } else if (rtb_VectorConcatenate_hw[0] < Mainframe_P.Rudder_siB_min) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder_siB_min;
    } else {
      rtb_TrigonometricFunction1_j = rtb_VectorConcatenate_hw[0];
    }

    /* End of Saturate: '<S151>/Saturation' */

    /* Sum: '<S151>/Add1' incorporates:
     *  Gain: '<S151>/Gain'
     *  Gain: '<S151>/Gain2'
     *  Integrator: '<S151>/Integrator1'
     *  Sum: '<S151>/Add'
     */
    rtb_dd_siB = (rtb_TrigonometricFunction1_j - Mainframe_X.Integrator1_CSTATE)
      * Mainframe_P.Gain_Gain_cv - 2.0 * Mainframe_P.Rudder_dmp *
      Mainframe_P.Rudder_omega * rtb_d_siB;

    /* MATLAB Function: '<S151>/Limiting_Acceleration' */
    Mainframe_Limiting_Acceleration(rtb_siB,
      Mainframe_B.sf_Limiting_Rate.d_siB_l, rtb_dd_siB,
      &Mainframe_B.sf_Limiting_Acceleration, Mainframe_P.Rudder_d_siB_max,
      Mainframe_P.Rudder_d_siB_min, Mainframe_P.Rudder_dd_siB_max,
      Mainframe_P.Rudder_dd_siB_min, Mainframe_P.Rudder_siB_max,
      Mainframe_P.Rudder_siB_min);

    /* Saturate: '<S152>/Saturation' */
    if (rtb_VectorConcatenate_hw[1] > Mainframe_P.Rudder1_siB_max) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder1_siB_max;
    } else if (rtb_VectorConcatenate_hw[1] < Mainframe_P.Rudder1_siB_min) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder1_siB_min;
    } else {
      rtb_TrigonometricFunction1_j = rtb_VectorConcatenate_hw[1];
    }

    /* End of Saturate: '<S152>/Saturation' */

    /* Sum: '<S152>/Add1' incorporates:
     *  Gain: '<S152>/Gain'
     *  Gain: '<S152>/Gain2'
     *  Integrator: '<S152>/Integrator1'
     *  Sum: '<S152>/Add'
     */
    rtb_dd_siB_h = (rtb_TrigonometricFunction1_j -
                    Mainframe_X.Integrator1_CSTATE_n) * Mainframe_P.Gain_Gain_e
      - 2.0 * Mainframe_P.Rudder1_dmp * Mainframe_P.Rudder1_omega * rtb_d_siB_g;

    /* MATLAB Function: '<S152>/Limiting_Acceleration' */
    Mainframe_Limiting_Acceleration(rtb_siB_a,
      Mainframe_B.sf_Limiting_Rate_g.d_siB_l, rtb_dd_siB_h,
      &Mainframe_B.sf_Limiting_Acceleration_p, Mainframe_P.Rudder1_d_siB_max,
      Mainframe_P.Rudder1_d_siB_min, Mainframe_P.Rudder1_dd_siB_max,
      Mainframe_P.Rudder1_dd_siB_min, Mainframe_P.Rudder1_siB_max,
      Mainframe_P.Rudder1_siB_min);

    /* Saturate: '<S153>/Saturation' */
    if (rtb_VectorConcatenate_hw[2] > Mainframe_P.Rudder2_siB_max) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder2_siB_max;
    } else if (rtb_VectorConcatenate_hw[2] < Mainframe_P.Rudder2_siB_min) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder2_siB_min;
    } else {
      rtb_TrigonometricFunction1_j = rtb_VectorConcatenate_hw[2];
    }

    /* End of Saturate: '<S153>/Saturation' */

    /* Sum: '<S153>/Add1' incorporates:
     *  Gain: '<S153>/Gain'
     *  Gain: '<S153>/Gain2'
     *  Integrator: '<S153>/Integrator1'
     *  Sum: '<S153>/Add'
     */
    rtb_dd_siB_k = (rtb_TrigonometricFunction1_j -
                    Mainframe_X.Integrator1_CSTATE_k) * Mainframe_P.Gain_Gain_ga
      - 2.0 * Mainframe_P.Rudder2_dmp * Mainframe_P.Rudder2_omega * rtb_d_siB_j;

    /* MATLAB Function: '<S153>/Limiting_Acceleration' */
    Mainframe_Limiting_Acceleration(rtb_siB_e,
      Mainframe_B.sf_Limiting_Rate_a.d_siB_l, rtb_dd_siB_k,
      &Mainframe_B.sf_Limiting_Acceleration_l, Mainframe_P.Rudder2_d_siB_max,
      Mainframe_P.Rudder2_d_siB_min, Mainframe_P.Rudder2_dd_siB_max,
      Mainframe_P.Rudder2_dd_siB_min, Mainframe_P.Rudder2_siB_max,
      Mainframe_P.Rudder2_siB_min);

    /* Saturate: '<S154>/Saturation' */
    if (rtb_VectorConcatenate_de > Mainframe_P.Rudder3_siB_max) {
      rtb_VectorConcatenate_de = Mainframe_P.Rudder3_siB_max;
    } else {
      if (rtb_VectorConcatenate_de < Mainframe_P.Rudder3_siB_min) {
        rtb_VectorConcatenate_de = Mainframe_P.Rudder3_siB_min;
      }
    }

    /* End of Saturate: '<S154>/Saturation' */

    /* Sum: '<S154>/Add1' incorporates:
     *  Gain: '<S154>/Gain'
     *  Gain: '<S154>/Gain2'
     *  Integrator: '<S154>/Integrator1'
     *  Sum: '<S154>/Add'
     */
    rtb_dd_siB_c = (rtb_VectorConcatenate_de - Mainframe_X.Integrator1_CSTATE_f)
      * Mainframe_P.Gain_Gain_gh - 2.0 * Mainframe_P.Rudder3_dmp *
      Mainframe_P.Rudder3_omega * rtb_d_siB_b;

    /* MATLAB Function: '<S154>/Limiting_Acceleration' */
    Mainframe_Limiting_Acceleration(rtb_siB_i,
      Mainframe_B.sf_Limiting_Rate_o.d_siB_l, rtb_dd_siB_c,
      &Mainframe_B.sf_Limiting_Acceleration_j, Mainframe_P.Rudder3_d_siB_max,
      Mainframe_P.Rudder3_d_siB_min, Mainframe_P.Rudder3_dd_siB_max,
      Mainframe_P.Rudder3_dd_siB_min, Mainframe_P.Rudder3_siB_max,
      Mainframe_P.Rudder3_siB_min);
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S171>/Gain' */
      rtb_wEIE[0] = Mainframe_P.Gain_Gain_ce * Mainframe_B.wIEE[0];
      rtb_wEIE[1] = Mainframe_P.Gain_Gain_ce * Mainframe_B.wIEE[1];
      rtb_wEIE[2] = Mainframe_P.Gain_Gain_ce * Mainframe_B.wIEE[2];

      /* Sum: '<S186>/Add' incorporates:
       *  Constant: '<S186>/Constant8'
       *  Constant: '<S186>/Q_1'
       *  Constant: '<S186>/Q_2'
       *  Constant: '<S186>/Q_3'
       *  Constant: '<S186>/Q_4'
       *  Product: '<S186>/Product1'
       *  Product: '<S186>/Product2'
       *  Product: '<S186>/Product3'
       *  Product: '<S186>/Product4'
       *  SignalConversion generated from: '<S186>/Vector Concatenate'
       * */
      for (i = 0; i < 16; i++) {
        Mainframe_B.Add[i] = ((Mainframe_P.Q_1_Value_a[i] * rtb_wEIE[0] +
          Mainframe_P.Q_2_Value_p[i] * rtb_wEIE[1]) + Mainframe_P.Q_3_Value_f[i]
                              * rtb_wEIE[2]) + Mainframe_P.Q_4_Value_p[i] *
          Mainframe_P.Constant8_Value_km;
      }

      /* End of Sum: '<S186>/Add' */
    }

    /* Gain: '<S188>/Gain1' incorporates:
     *  Integrator: '<S183>/integration_eom'
     */
    rtb_VectorConcatenate_hw[0] = Mainframe_P.Gain1_Gain_k1 *
      Mainframe_X.integration_eom_CSTATE_o[0];
    rtb_VectorConcatenate_hw[1] = Mainframe_P.Gain1_Gain_k1 *
      Mainframe_X.integration_eom_CSTATE_o[1];
    rtb_VectorConcatenate_hw[2] = Mainframe_P.Gain1_Gain_k1 *
      Mainframe_X.integration_eom_CSTATE_o[2];
    for (i = 0; i < 4; i++) {
      /* Product: '<S186>/Product5' incorporates:
       *  Integrator: '<S183>/integration_eom'
       */
      rtb_T_sim_glbl = Mainframe_B.Add[i + 12] *
        Mainframe_X.integration_eom_CSTATE_o[3] + (Mainframe_B.Add[i + 8] *
        rtb_VectorConcatenate_hw[2] + (Mainframe_B.Add[i + 4] *
        rtb_VectorConcatenate_hw[1] + Mainframe_B.Add[i] *
        rtb_VectorConcatenate_hw[0]));

      /* Gain: '<S186>/Gain' */
      rtb_d_qEI[i] = Mainframe_P.Gain_Gain_f * rtb_T_sim_glbl;
    }

    /* SignalConversion generated from: '<S189>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_m[3] = rtb_d_qEI[3];

    /* Gain: '<S189>/Gain1' */
    Mainframe_B.VectorConcatenate_m[0] = Mainframe_P.Gain1_Gain_nr * rtb_d_qEI[0];
    Mainframe_B.VectorConcatenate_m[1] = Mainframe_P.Gain1_Gain_nr * rtb_d_qEI[1];
    Mainframe_B.VectorConcatenate_m[2] = Mainframe_P.Gain1_Gain_nr * rtb_d_qEI[2];
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S185>/Vector Concatenate1' incorporates:
       *  Constant: '<S185>/Constant8'
       */
      Mainframe_B.wEGG[0] = Mainframe_P.Constant8_Value_k2;

      /* SignalConversion generated from: '<S185>/Vector Concatenate1' incorporates:
       *  Constant: '<S185>/Constant8'
       */
      Mainframe_B.wEGG[1] = Mainframe_P.Constant8_Value_k2;

      /* SignalConversion generated from: '<S185>/Vector Concatenate1' incorporates:
       *  Constant: '<S185>/Constant8'
       */
      Mainframe_B.wEGG[2] = Mainframe_P.Constant8_Value_k2;
    }

    /* Derivative: '<S185>/Derivative1' */
    if ((Mainframe_DW.TimeStampA >= rtb_jxi_f) && (Mainframe_DW.TimeStampB >=
         rtb_jxi_f)) {
      rtb_Switch_j = 0.0;
    } else {
      rtb_Product4_b_idx_1 = Mainframe_DW.TimeStampA;
      lastU = &Mainframe_DW.LastUAtTimeA;
      if (Mainframe_DW.TimeStampA < Mainframe_DW.TimeStampB) {
        if (Mainframe_DW.TimeStampB < rtb_jxi_f) {
          rtb_Product4_b_idx_1 = Mainframe_DW.TimeStampB;
          lastU = &Mainframe_DW.LastUAtTimeB;
        }
      } else {
        if (Mainframe_DW.TimeStampA >= rtb_jxi_f) {
          rtb_Product4_b_idx_1 = Mainframe_DW.TimeStampB;
          lastU = &Mainframe_DW.LastUAtTimeB;
        }
      }

      rtb_Switch_j = (Mainframe_B.Switch[0] - *lastU) / (rtb_jxi_f -
        rtb_Product4_b_idx_1);
    }

    /* Derivative: '<S185>/Derivative' */
    if ((Mainframe_DW.TimeStampA_i >= rtb_jxi_f) && (Mainframe_DW.TimeStampB_c >=
         rtb_jxi_f)) {
      rtb_Product4_b_idx_1 = 0.0;
    } else {
      rtb_Product4_b_idx_1 = Mainframe_DW.TimeStampA_i;
      lastU = &Mainframe_DW.LastUAtTimeA_d;
      if (Mainframe_DW.TimeStampA_i < Mainframe_DW.TimeStampB_c) {
        if (Mainframe_DW.TimeStampB_c < rtb_jxi_f) {
          rtb_Product4_b_idx_1 = Mainframe_DW.TimeStampB_c;
          lastU = &Mainframe_DW.LastUAtTimeB_g;
        }
      } else {
        if (Mainframe_DW.TimeStampA_i >= rtb_jxi_f) {
          rtb_Product4_b_idx_1 = Mainframe_DW.TimeStampB_c;
          lastU = &Mainframe_DW.LastUAtTimeB_g;
        }
      }

      rtb_Product4_b_idx_1 = (Mainframe_B.Switch[1] - *lastU) / (rtb_jxi_f -
        rtb_Product4_b_idx_1);
    }

    /* Switch: '<S185>/Switch' incorporates:
     *  Constant: '<S185>/Constant9'
     */
    if (Mainframe_P.Constant9_Value_m > Mainframe_P.Switch_Threshold_m) {
      rtb_Sum4[0] = Mainframe_B.wEGG[0];
      rtb_Sum4[1] = Mainframe_B.wEGG[1];
      rtb_Sum4[2] = Mainframe_B.wEGG[2];
    } else {
      /* Gain: '<S185>/Gain2' incorporates:
       *  Product: '<S185>/Product'
       */
      rtb_Sum4[2] = rtb_lat * rtb_Switch_j * Mainframe_P.Gain2_Gain_f;

      /* Gain: '<S185>/Gain1' */
      rtb_Sum4[1] = Mainframe_P.Gain1_Gain_m * rtb_Product4_b_idx_1;

      /* Product: '<S185>/Product1' */
      rtb_Sum4[0] = rtb_Switch_j * rtb_Sqrt_c;
    }

    /* Gain: '<S171>/Gain1' */
    rtb_Sum4[0] *= Mainframe_P.Gain1_Gain_ge;
    rtb_Sum4[1] *= Mainframe_P.Gain1_Gain_ge;

    /* SignalConversion generated from: '<S190>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_d[0] = rtb_Sum4[0];

    /* SignalConversion generated from: '<S190>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_d[1] = rtb_Sum4[1];

    /* SignalConversion generated from: '<S190>/Vector Concatenate' incorporates:
     *  Gain: '<S171>/Gain1'
     */
    Mainframe_B.VectorConcatenate_d[2] = Mainframe_P.Gain1_Gain_ge * rtb_Sum4[2];
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S190>/Constant8' */
      Mainframe_B.VectorConcatenate_d[3] = Mainframe_P.Constant8_Value_kt;
    }

    /* Gain: '<S192>/Gain1' incorporates:
     *  Integrator: '<S184>/integration_eom'
     */
    rtb_d_qBI[0] = Mainframe_P.Gain1_Gain_p *
      Mainframe_X.integration_eom_CSTATE_k[0];
    rtb_d_qBI[1] = Mainframe_P.Gain1_Gain_p *
      Mainframe_X.integration_eom_CSTATE_k[1];
    rtb_d_qBI[2] = Mainframe_P.Gain1_Gain_p *
      Mainframe_X.integration_eom_CSTATE_k[2];

    /* Sum: '<S190>/Add' incorporates:
     *  Constant: '<S190>/Q_1'
     *  Constant: '<S190>/Q_2'
     *  Constant: '<S190>/Q_3'
     *  Constant: '<S190>/Q_4'
     *  Product: '<S190>/Product1'
     *  Product: '<S190>/Product2'
     *  Product: '<S190>/Product3'
     *  Product: '<S190>/Product4'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_o[i] * Mainframe_B.VectorConcatenate_d[0]
                 + Mainframe_P.Q_2_Value_ca[i] *
                 Mainframe_B.VectorConcatenate_d[1]) + Mainframe_P.Q_3_Value_g[i]
                * Mainframe_B.VectorConcatenate_d[2]) +
        Mainframe_P.Q_4_Value_po[i] * Mainframe_B.VectorConcatenate_d[3];
    }

    /* End of Sum: '<S190>/Add' */
    for (i = 0; i < 4; i++) {
      /* Product: '<S190>/Product5' incorporates:
       *  Integrator: '<S184>/integration_eom'
       */
      rtb_T_sim_glbl = tmp[i + 12] * Mainframe_X.integration_eom_CSTATE_k[3] +
        (tmp[i + 8] * rtb_d_qBI[2] + (tmp[i + 4] * rtb_d_qBI[1] + tmp[i] *
          rtb_d_qBI[0]));

      /* Gain: '<S190>/Gain' */
      rtb_VectorConcatenate_hw[i] = Mainframe_P.Gain_Gain_j * rtb_T_sim_glbl;
    }

    /* SignalConversion generated from: '<S193>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_e[3] = rtb_VectorConcatenate_hw[3];
    for (i = 0; i < 3; i++) {
      /* Gain: '<S193>/Gain1' */
      Mainframe_B.VectorConcatenate_e[i] = Mainframe_P.Gain1_Gain_e *
        rtb_VectorConcatenate_hw[i];

      /* Product: '<S207>/Product1' incorporates:
       *  Math: '<S207>/Math Function'
       */
      Mainframe_B.vBIB[i] = 0.0;
      Mainframe_B.vBIB[i] += rtb_TBI_tmp[i] * Mainframe_B.x_d[3];
      Mainframe_B.vBIB[i] += rtb_TBI_tmp[i + 3] * Mainframe_B.x_d[4];
      Mainframe_B.vBIB[i] += rtb_TBI_tmp[i + 6] * Mainframe_B.x_d[5];
    }

    /* Sum: '<S216>/Add2' incorporates:
     *  Selector: '<S210>/dcm22'
     *  Selector: '<S210>/dcm33'
     *  Sum: '<S217>/Add2'
     */
    rtb_JMMB_tmp_6 = rtb_VectorConcatenate3[4] + rtb_VectorConcatenate3[8];

    /* Sum: '<S216>/Add1' incorporates:
     *  Selector: '<S210>/dcm11'
     *  Selector: '<S210>/dcm33'
     *  Sum: '<S218>/Add1'
     */
    rtb_VectorConcatenate_de = rtb_VectorConcatenate3[0] +
      rtb_VectorConcatenate3[8];

    /* Sum: '<S216>/Add' incorporates:
     *  Selector: '<S210>/dcm11'
     *  Selector: '<S210>/dcm22'
     *  Sum: '<S219>/Add'
     */
    rtb_TrigonometricFunction1_j = rtb_VectorConcatenate3[0] +
      rtb_VectorConcatenate3[4];

    /* Logic: '<S216>/Logical Operator' incorporates:
     *  Constant: '<S225>/Constant'
     *  Constant: '<S226>/Constant'
     *  Constant: '<S227>/Constant'
     *  RelationalOperator: '<S225>/Compare'
     *  RelationalOperator: '<S226>/Compare'
     *  RelationalOperator: '<S227>/Compare'
     *  Sum: '<S216>/Add'
     *  Sum: '<S216>/Add1'
     *  Sum: '<S216>/Add2'
     */
    Mainframe_B.q_R0R = ((rtb_TrigonometricFunction1_j >=
                          Mainframe_P.Constant_Value_g) &&
                         (rtb_VectorConcatenate_de >=
                          Mainframe_P.Constant_Value_ck) && (rtb_JMMB_tmp_6 >=
      Mainframe_P.Constant_Value_o0));

    /* Sum: '<S217>/Add' incorporates:
     *  Selector: '<S210>/dcm11'
     *  Selector: '<S210>/dcm22'
     *  Sum: '<S218>/Add'
     */
    rtb_Switch_j = rtb_VectorConcatenate3[0] - rtb_VectorConcatenate3[4];

    /* Sum: '<S217>/Add1' incorporates:
     *  Selector: '<S210>/dcm11'
     *  Selector: '<S210>/dcm33'
     *  Sum: '<S219>/Add1'
     */
    q0_tmp = rtb_VectorConcatenate3[0] - rtb_VectorConcatenate3[8];

    /* Logic: '<S217>/Logical Operator' incorporates:
     *  Constant: '<S228>/Constant'
     *  Constant: '<S229>/Constant'
     *  Constant: '<S230>/Constant'
     *  RelationalOperator: '<S228>/Compare'
     *  RelationalOperator: '<S229>/Compare'
     *  RelationalOperator: '<S230>/Compare'
     *  Sum: '<S217>/Add'
     *  Sum: '<S217>/Add1'
     */
    Mainframe_B.q_R1R = ((rtb_Switch_j >= Mainframe_P.Constant_Value_pq) &&
                         (q0_tmp >= Mainframe_P.Constant_Value_a) &&
                         (rtb_JMMB_tmp_6 < Mainframe_P.Constant_Value_kz));

    /* Sum: '<S218>/Add2' incorporates:
     *  Selector: '<S210>/dcm22'
     *  Selector: '<S210>/dcm33'
     *  Sum: '<S219>/Add2'
     */
    rtb_JMMB_tmp_6 = rtb_VectorConcatenate3[4] - rtb_VectorConcatenate3[8];

    /* Logic: '<S218>/Logical Operator' incorporates:
     *  Constant: '<S231>/Constant'
     *  Constant: '<S232>/Constant'
     *  Constant: '<S233>/Constant'
     *  RelationalOperator: '<S231>/Compare'
     *  RelationalOperator: '<S232>/Compare'
     *  RelationalOperator: '<S233>/Compare'
     *  Sum: '<S218>/Add2'
     */
    Mainframe_B.q_R2R = ((rtb_Switch_j < Mainframe_P.Constant_Value_do) &&
                         (rtb_VectorConcatenate_de <
                          Mainframe_P.Constant_Value_g4) && (rtb_JMMB_tmp_6 >=
      Mainframe_P.Constant_Value_g1));

    /* Logic: '<S219>/Logical Operator' incorporates:
     *  Constant: '<S234>/Constant'
     *  Constant: '<S235>/Constant'
     *  Constant: '<S236>/Constant'
     *  RelationalOperator: '<S234>/Compare'
     *  RelationalOperator: '<S235>/Compare'
     *  RelationalOperator: '<S236>/Compare'
     */
    Mainframe_B.q_R3R = ((rtb_TrigonometricFunction1_j <
                          Mainframe_P.Constant_Value_gb) && (q0_tmp <
      Mainframe_P.Constant_Value_gf) && (rtb_JMMB_tmp_6 <
      Mainframe_P.Constant_Value_ok));
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S221>/q_R^0(R) = TRUE' */
      Mainframe_B.HiddenBuf_InsertedFor_q_R0R_at_inport_1 = Mainframe_B.q_R0R;

      /* SignalConversion generated from: '<S222>/q_R^1(R) = TRUE' */
      Mainframe_B.HiddenBuf_InsertedFor_q_R1R_at_inport_1 = Mainframe_B.q_R1R;

      /* SignalConversion generated from: '<S223>/q_R^2(R) = TRUE' */
      Mainframe_B.HiddenBuf_InsertedFor_q_R2R_at_inport_1 = Mainframe_B.q_R2R;

      /* SignalConversion generated from: '<S224>/q_R^3(R) = TRUE' */
      Mainframe_B.HiddenBuf_InsertedFor_q_R3R_at_inport_1 = Mainframe_B.q_R3R;

      /* Outputs for Enabled SubSystem: '<S210>/q_R^0(R)' incorporates:
       *  EnablePort: '<S221>/q_R^0(R) = TRUE'
       */
      if (rtmIsMajorTimeStep(Mainframe_M)) {
        Mainframe_DW.q_R0R_MODE =
          Mainframe_B.HiddenBuf_InsertedFor_q_R0R_at_inport_1;
      }

      /* End of Outputs for SubSystem: '<S210>/q_R^0(R)' */
    }

    /* Outputs for Enabled SubSystem: '<S210>/q_R^0(R)' incorporates:
     *  EnablePort: '<S221>/q_R^0(R) = TRUE'
     */
    if (Mainframe_DW.q_R0R_MODE && rtmIsMajorTimeStep(Mainframe_M)) {
      srUpdateBC(Mainframe_DW.q_R0R_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S210>/q_R^0(R)' */

    /* Outputs for Enabled SubSystem: '<S210>/q_R^1(R)' incorporates:
     *  EnablePort: '<S222>/q_R^1(R) = TRUE'
     */
    if ((rtmIsMajorTimeStep(Mainframe_M) &&
         Mainframe_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
        (Mainframe_M)) {
      Mainframe_DW.q_R1R_MODE =
        Mainframe_B.HiddenBuf_InsertedFor_q_R1R_at_inport_1;
    }

    if (Mainframe_DW.q_R1R_MODE && rtmIsMajorTimeStep(Mainframe_M)) {
      srUpdateBC(Mainframe_DW.q_R1R_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S210>/q_R^1(R)' */

    /* Outputs for Enabled SubSystem: '<S210>/q_R^2(R)' incorporates:
     *  EnablePort: '<S223>/q_R^2(R) = TRUE'
     */
    if ((rtmIsMajorTimeStep(Mainframe_M) &&
         Mainframe_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
        (Mainframe_M)) {
      Mainframe_DW.q_R2R_MODE =
        Mainframe_B.HiddenBuf_InsertedFor_q_R2R_at_inport_1;
    }

    if (Mainframe_DW.q_R2R_MODE && rtmIsMajorTimeStep(Mainframe_M)) {
      srUpdateBC(Mainframe_DW.q_R2R_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S210>/q_R^2(R)' */

    /* Outputs for Enabled SubSystem: '<S210>/q_R^3(R)' incorporates:
     *  EnablePort: '<S224>/q_R^3(R) = TRUE'
     */
    if ((rtmIsMajorTimeStep(Mainframe_M) &&
         Mainframe_M->Timing.TaskCounters.TID[1] == 0) && rtmIsMajorTimeStep
        (Mainframe_M)) {
      Mainframe_DW.q_R3R_MODE =
        Mainframe_B.HiddenBuf_InsertedFor_q_R3R_at_inport_1;
    }

    if (Mainframe_DW.q_R3R_MODE && rtmIsMajorTimeStep(Mainframe_M)) {
      srUpdateBC(Mainframe_DW.q_R3R_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S210>/q_R^3(R)' */

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[0] = Mainframe_B.x_d[3];

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[3] = rtb_q_conj[0];

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[10] = rtb_u2[0];

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[1] = Mainframe_B.x_d[4];

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[4] = rtb_q_conj[1];

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[11] = rtb_u2[1];

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[2] = Mainframe_B.x_d[5];

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[5] = rtb_q_conj[2];

    /* SignalConversion generated from: '<S238>/Vector Concatenate' */
    Mainframe_B.d_x[12] = rtb_u2[2];

    /* SignalConversion generated from: '<S242>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_f[0] = Mainframe_B.x_d[10];

    /* SignalConversion generated from: '<S242>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_f[1] = Mainframe_B.x_d[11];

    /* SignalConversion generated from: '<S242>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_f[2] = Mainframe_B.x_d[12];
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S242>/Constant' */
      Mainframe_B.VectorConcatenate_f[3] = Mainframe_P.Constant_Value_cu;
    }

    /* Gain: '<S245>/Gain1' */
    rtb_d_qEI[0] = Mainframe_P.Gain1_Gain_gee * rtb_Product_b_idx_0;
    rtb_d_qEI[1] = Mainframe_P.Gain1_Gain_gee * rtb_Product_b_idx_1;
    rtb_d_qEI[2] = Mainframe_P.Gain1_Gain_gee * rtb_Product_b_idx_2;

    /* Sum: '<S242>/Add' incorporates:
     *  Constant: '<S242>/Q_1'
     *  Constant: '<S242>/Q_2'
     *  Constant: '<S242>/Q_3'
     *  Constant: '<S242>/Q_4'
     *  Product: '<S242>/Product2'
     *  Product: '<S242>/Product3'
     *  Product: '<S242>/Product4'
     *  Product: '<S242>/Product5'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_ab[i] * Mainframe_B.VectorConcatenate_f[0]
                 + Mainframe_P.Q_2_Value_m[i] * Mainframe_B.VectorConcatenate_f
                 [1]) + Mainframe_P.Q_3_Value_c1[i] *
                Mainframe_B.VectorConcatenate_f[2]) + Mainframe_P.Q_4_Value_gi[i]
        * Mainframe_B.VectorConcatenate_f[3];
    }

    /* End of Sum: '<S242>/Add' */
    for (i = 0; i < 4; i++) {
      /* Product: '<S242>/Product6' */
      rtb_T_sim_glbl = tmp[i + 12] * rtb_Product_d + (tmp[i + 8] * rtb_d_qEI[2]
        + (tmp[i + 4] * rtb_d_qEI[1] + tmp[i] * rtb_d_qEI[0]));

      /* Gain: '<S242>/Gain' */
      rtb_d_qBI[i] = Mainframe_P.Gain_Gain_bs * rtb_T_sim_glbl;
    }

    /* Gain: '<S246>/Gain1' */
    Mainframe_B.d_x[6] = Mainframe_P.Gain1_Gain_nw * rtb_d_qBI[0];
    Mainframe_B.d_x[7] = Mainframe_P.Gain1_Gain_nw * rtb_d_qBI[1];
    Mainframe_B.d_x[8] = Mainframe_P.Gain1_Gain_nw * rtb_d_qBI[2];

    /* SignalConversion generated from: '<S246>/Vector Concatenate' */
    Mainframe_B.d_x[9] = rtb_d_qBI[3];
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    }

    if (rtmIsMajorTimeStep(Mainframe_M)) {
      srUpdateBC(Mainframe_DW.Subsystem_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S7>/Subsystem' */

  /* Gain: '<S9>/Gain' */
  Mainframe_B.Gain = Mainframe_P.Gain_Gain_nd * Mainframe_B.ComplextoRealImag[0];

  /* Gain: '<S20>/Gain' */
  Mainframe_B.Gain_f = Mainframe_P.Gain_Gain_bk * Mainframe_B.ComplextoRealImag
    [1];

  /* Gain: '<S21>/Gain' */
  Mainframe_B.Gain_n = Mainframe_P.Gain_Gain_ju * Mainframe_B.ComplextoRealImag
    [2];
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S12>/Gain' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
     */
    Mainframe_B.Gain_p = Mainframe_P.Gain_Gain_gj *
      Mainframe_DW.DiscreteTimeIntegrator1_DSTATE;

    /* Gain: '<S11>/Gain' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
     */
    Mainframe_B.Gain_b = Mainframe_P.Gain_Gain_of *
      Mainframe_DW.DiscreteTimeIntegrator_DSTATE;

    /* Gain: '<S10>/Gain' incorporates:
     *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
     */
    Mainframe_B.Gain_i = Mainframe_P.Gain_Gain_e2 *
      Mainframe_DW.DiscreteTimeIntegrator2_DSTATE;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Constant: '<S66>/Zero1' */
    Mainframe_B.gimbalPhi = Mainframe_P.Zero1_Value;

    /* Gain: '<S8>/Gain' */
    Mainframe_B.Gain_br = Mainframe_P.Gain_Gain_dy * Mainframe_B.gimbalPhi;

    /* Constant: '<S66>/Zero' */
    Mainframe_B.gimbalTheta = Mainframe_P.Zero_Value;

    /* Gain: '<S13>/Gain' */
    Mainframe_B.Gain_e = Mainframe_P.Gain_Gain_ag * Mainframe_B.gimbalTheta;

    /* Constant: '<S66>/Zero2' */
    Mainframe_B.gimbalPsi = Mainframe_P.Zero2_Value;

    /* Gain: '<S14>/Gain' */
    Mainframe_B.Gain_o = Mainframe_P.Gain_Gain_b4 * Mainframe_B.gimbalPsi;

    /* S-Function (sldrtpi): '<S58>/Packet Input' */
    /* S-Function Block: <S58>/Packet Input */
    {
      uint8_T indata[75U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 75U,
        &Mainframe_P.PacketInput_PacketID, (double*) indata, NULL);
      Mainframe_B.PacketInput_o2 = status & 0x1;/* Data Ready port */
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;

        {
          int_T i1;
          uint8_T *y0 = &Mainframe_B.PacketInput_o1[0];
          for (i1=0; i1 < 75; i1++) {
            y0[i1] = *indp.p_uint8_T++;
          }
        }
      }
    }

    /* Outputs for Triggered SubSystem: '<S58>/Enabled Subsystem' incorporates:
     *  TriggerPort: '<S59>/Trigger'
     */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      if (Mainframe_B.PacketInput_o2 &&
          (Mainframe_PrevZCX.EnabledSubsystem_Trig_ZCE != POS_ZCSIG)) {
        /* Inport: '<S59>/In1' */
        memcpy(&Mainframe_B.In1[0], &Mainframe_B.PacketInput_o1[0], 75U * sizeof
               (uint8_T));
        Mainframe_DW.EnabledSubsystem_SubsysRanBC = 4;
      }

      Mainframe_PrevZCX.EnabledSubsystem_Trig_ZCE = Mainframe_B.PacketInput_o2;
    }

    /* End of Outputs for SubSystem: '<S58>/Enabled Subsystem' */

    /* MATLAB Function: '<S58>/Extract Message' */
    memcpy(&packet[0], &Mainframe_B.In1[0], 75U * sizeof(uint8_T));
    memset(&rtb_myItems[0], 0, 18U * sizeof(real_T));
    for (i = 0; i < 75; i++) {
      x[i] = (Mainframe_B.In1[i] == 5);
    }

    idx = 0;
    rtb_MultiportSwitch1_tmp = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_MultiportSwitch1_tmp < 75)) {
      if (x[rtb_MultiportSwitch1_tmp]) {
        idx++;
        ii_data[idx - 1] = (int8_T)(rtb_MultiportSwitch1_tmp + 1);
        if (idx >= 75) {
          exitg1 = true;
        } else {
          rtb_MultiportSwitch1_tmp++;
        }
      } else {
        rtb_MultiportSwitch1_tmp++;
      }
    }

    if (1 > idx) {
      idx = 0;
    }

    headerPos_size[0] = 1;
    headerPos_size[1] = idx;
    loop_ub = idx - 1;
    for (i = 0; i <= loop_ub; i++) {
      headerPos_data[i] = ii_data[i];
    }

    headerPos_size_1[0] = 1;
    headerPos_size_1[1] = idx;
    for (i = 0; i < idx; i++) {
      x[i] = (headerPos_data[i] > 73.0);
    }

    Mainframe_nullAssignment(headerPos_data, headerPos_size, x, headerPos_size_1);
    tmp_size[0] = 1;
    tmp_size[1] = headerPos_size[1];
    loop_ub = headerPos_size[0] * headerPos_size[1];
    for (i = 0; i < loop_ub; i++) {
      x[i] = (Mainframe_B.In1[(int32_T)((headerPos_data[i] + 2.0) - 1.0) - 1] !=
              5);
    }

    Mainframe_nullAssignment(headerPos_data, headerPos_size, x, tmp_size);
    tmp_size[0] = 1;
    tmp_size[1] = headerPos_size[1];
    loop_ub = headerPos_size[0] * headerPos_size[1];
    for (i = 0; i < loop_ub; i++) {
      x[i] = (Mainframe_B.In1[(int32_T)((headerPos_data[i] + 3.0) - 1.0) - 1] !=
              5);
    }

    Mainframe_nullAssignment(headerPos_data, headerPos_size, x, tmp_size);
    if (headerPos_size[1] == 0) {
      memcpy(&packet[0], &Mainframe_B.In1[3], 72U * sizeof(uint8_T));
      packet[72] = Mainframe_B.In1[0];
      packet[73] = Mainframe_B.In1[1];
      packet[74] = Mainframe_B.In1[2];
      for (i = 0; i < 75; i++) {
        x[i] = (packet[i] == 5);
      }

      idx = 0;
      rtb_MultiportSwitch1_tmp = 0;
      exitg1 = false;
      while ((!exitg1) && (rtb_MultiportSwitch1_tmp < 75)) {
        if (x[rtb_MultiportSwitch1_tmp]) {
          idx++;
          ii_data[idx - 1] = (int8_T)(rtb_MultiportSwitch1_tmp + 1);
          if (idx >= 75) {
            exitg1 = true;
          } else {
            rtb_MultiportSwitch1_tmp++;
          }
        } else {
          rtb_MultiportSwitch1_tmp++;
        }
      }

      if (1 > idx) {
        idx = 0;
      }

      headerPos_size[0] = 1;
      headerPos_size[1] = idx;
      loop_ub = idx - 1;
      for (i = 0; i <= loop_ub; i++) {
        headerPos_data[i] = ii_data[i];
      }

      headerPos_size_0[0] = 1;
      headerPos_size_0[1] = idx;
      for (i = 0; i < idx; i++) {
        x[i] = (headerPos_data[i] > 73.0);
      }

      Mainframe_nullAssignment(headerPos_data, headerPos_size, x,
        headerPos_size_0);
      packet_size[0] = 1;
      packet_size[1] = headerPos_size[1];
      loop_ub = headerPos_size[0] * headerPos_size[1];
      for (i = 0; i < loop_ub; i++) {
        x[i] = (packet[(int32_T)((headerPos_data[i] + 2.0) - 1.0) - 1] != 5);
      }

      Mainframe_nullAssignment(headerPos_data, headerPos_size, x, packet_size);
      packet_size[0] = 1;
      packet_size[1] = headerPos_size[1];
      loop_ub = headerPos_size[0] * headerPos_size[1];
      for (i = 0; i < loop_ub; i++) {
        x[i] = (packet[(int32_T)((headerPos_data[i] + 3.0) - 1.0) - 1] != 5);
      }

      Mainframe_nullAssignment(headerPos_data, headerPos_size, x, packet_size);
    }

    if (headerPos_size[1] != 0) {
      if (headerPos_data[0] + 3.0 > 75.0) {
        idx = 0;
        rtb_MultiportSwitch1_tmp = 0;
      } else {
        idx = (int32_T)(headerPos_data[0] + 3.0) - 1;
        rtb_MultiportSwitch1_tmp = 75;
      }

      if (1.0 > headerPos_data[0] - 1.0) {
        d = 0;
      } else {
        d = (int32_T)(headerPos_data[0] - 1.0);
      }

      loop_ub = rtb_MultiportSwitch1_tmp - idx;
      for (i = 0; i < loop_ub; i++) {
        messageTmp_data[i] = packet[idx + i];
      }

      for (i = 0; i < d; i++) {
        messageTmp_data[(i + rtb_MultiportSwitch1_tmp) - idx] = packet[i];
      }

      rtb_message_0 = &messageTmp_data[0];
      for (idx = 0; idx < 18; idx++) {
        rtb_MultiportSwitch1_tmp = idx << 2;
        d = (idx + 1) << 2;
        if (rtb_MultiportSwitch1_tmp + 1 > d) {
          rtb_MultiportSwitch1_tmp = -1;
          d = -1;
        } else {
          rtb_MultiportSwitch1_tmp--;
          d--;
        }

        loop_ub = d - rtb_MultiportSwitch1_tmp;
        for (i = 0; i < loop_ub; i++) {
          b_x_data[i] = rtb_message_0[(rtb_MultiportSwitch1_tmp + i) + 1];
        }

        if (loop_ub == 0) {
          d = 0;
        } else {
          d = loop_ub >> 2;
        }

        memcpy((void *)&y_data[0], (void *)&b_x_data[0], (uint32_T)((size_t)d *
                sizeof(real32_T)));
        rtb_myItems[idx] = y_data[0];
      }
    }

    /* End of MATLAB Function: '<S58>/Extract Message' */

    /* DataTypeConversion: '<S56>/Cast To Double1' */
    Mainframe_B.Fin_1_Cmd_rad = rtb_myItems[1];

    /* Gain: '<S17>/Gain' */
    Mainframe_B.Gain_h = Mainframe_P.Gain_Gain_abz * Mainframe_B.Fin_1_Cmd_rad;

    /* DataTypeConversion: '<S56>/Cast To Double2' */
    Mainframe_B.Fin_2_Cmd_rad = rtb_myItems[2];

    /* Gain: '<S15>/Gain' */
    Mainframe_B.Gain_a = Mainframe_P.Gain_Gain_j1 * Mainframe_B.Fin_2_Cmd_rad;

    /* DataTypeConversion: '<S56>/Cast To Double3' */
    Mainframe_B.Fin_3_Cmd_rad = rtb_myItems[3];

    /* Gain: '<S18>/Gain' */
    Mainframe_B.Gain_k = Mainframe_P.Gain_Gain_ho * Mainframe_B.Fin_3_Cmd_rad;

    /* DataTypeConversion: '<S56>/Cast To Double4' */
    Mainframe_B.Fin_4_Cmd_rad = rtb_myItems[4];

    /* Gain: '<S16>/Gain' */
    Mainframe_B.Gain_d = Mainframe_P.Gain_Gain_pm * Mainframe_B.Fin_4_Cmd_rad;
  }

  /* Gain: '<S19>/Gain' */
  Mainframe_B.Gain_j = Mainframe_P.Gain_Gain_fd * Mainframe_B.Fin_1;

  /* Gain: '<S23>/Gain' */
  Mainframe_B.Gain_kd = Mainframe_P.Gain_Gain_me * Mainframe_B.Fin_2;

  /* Gain: '<S22>/Gain' */
  Mainframe_B.Gain_oi = Mainframe_P.Gain_Gain_iq * Mainframe_B.Fin_3;

  /* Gain: '<S24>/Gain' */
  Mainframe_B.Gain_is = Mainframe_P.Gain_Gain_pzg * Mainframe_B.Fin_4;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Triggered SubSystem: '<Root>/Enabled Subsystem1' incorporates:
     *  TriggerPort: '<S3>/Trigger'
     */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      /* Constant: '<S66>/One' */
      if (Mainframe_P.One_Value &&
          (Mainframe_PrevZCX.EnabledSubsystem1_Trig_ZCE_b != POS_ZCSIG)) {
        /* DigitalClock: '<S3>/Digital Clock' */
        Mainframe_B.DigitalClock = Mainframe_M->Timing.t[1];
        Mainframe_DW.EnabledSubsystem1_SubsysRanBC = 4;
      }

      Mainframe_PrevZCX.EnabledSubsystem1_Trig_ZCE_b = Mainframe_P.One_Value;
    }

    /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem1' */

    /* Constant: '<S2>/Zero1' */
    Mainframe_B.p = Mainframe_P.Zero1_Value_d;

    /* Constant: '<S2>/Zero2' */
    Mainframe_B.q = Mainframe_P.Zero2_Value_k;

    /* Constant: '<S2>/Zero6' */
    Mainframe_B.r = Mainframe_P.Zero6_Value;

    /* Constant: '<S2>/Zero5' */
    Mainframe_B.phi = Mainframe_P.Zero5_Value;

    /* Constant: '<S2>/Zero4' */
    Mainframe_B.theta = Mainframe_P.Zero4_Value;

    /* Constant: '<S2>/Zero3' */
    Mainframe_B.psi = Mainframe_P.Zero3_Value;

    /* Gain: '<S34>/Gain' incorporates:
     *  Constant: '<S30>/Constant1'
     *  Constant: '<S34>/wl_ins'
     *  Gain: '<S34>/Zero-Order Hold4'
     *  Sum: '<S34>/Sum7'
     */
    Mainframe_B.Gain_l[0] = (Mainframe_P.ZeroOrderHold4_Gain_o *
      Mainframe_P.Constant1_Value_plv[0] -
      Mainframe_P.ThreeaxisInertialMeasurementUnit_imu_p[0]) *
      Mainframe_P.Gain_Gain_en[0];
    Mainframe_B.Gain_l[1] = (Mainframe_P.ZeroOrderHold4_Gain_o *
      Mainframe_P.Constant1_Value_plv[1] -
      Mainframe_P.ThreeaxisInertialMeasurementUnit_imu_p[1]) *
      Mainframe_P.Gain_Gain_en[1];
    Mainframe_B.Gain_l[2] = (Mainframe_P.ZeroOrderHold4_Gain_o *
      Mainframe_P.Constant1_Value_plv[2] -
      Mainframe_P.ThreeaxisInertialMeasurementUnit_imu_p[2]) *
      Mainframe_P.Gain_Gain_en[2];
  }

  /* SignalConversion generated from: '<S30>/Vector Concatenate' */
  rtb_uzetawn_p[0] = Mainframe_B.aBIB[0];

  /* SignalConversion generated from: '<S30>/Vector Concatenate' */
  rtb_uzetawn_p[1] = Mainframe_B.aBIB[1];

  /* SignalConversion generated from: '<S30>/Vector Concatenate' */
  rtb_uzetawn_p[2] = Mainframe_B.aBIB[2];

  /* Trigonometry: '<S31>/Cos2' */
  rtb_ixk_k = cos(Mainframe_B.ComplextoRealImag[1]);

  /* SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited' */
  rtb_IntegratorSecondOrderLimited_o1[0] =
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[0];

  /* Gain: '<S34>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S30>/Vector Concatenate3'
   */
  rtb_Sum1_e[0] = Mainframe_P.ZeroOrderHold_Gain_a * Mainframe_B.x_d[10];

  /* SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited' */
  rtb_IntegratorSecondOrderLimited_o1[1] =
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[1];

  /* Gain: '<S34>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S30>/Vector Concatenate3'
   */
  rtb_Sum1_e[1] = Mainframe_P.ZeroOrderHold_Gain_a * Mainframe_B.x_d[11];

  /* SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited' */
  rtb_IntegratorSecondOrderLimited_o1[2] =
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[2];

  /* Gain: '<S34>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S30>/Vector Concatenate3'
   */
  rtb_Product_d = Mainframe_P.ZeroOrderHold_Gain_a * Mainframe_B.x_d[12];

  /* Sum: '<S43>/Sum' incorporates:
   *  Gain: '<S34>/Zero-Order Hold'
   *  Product: '<S46>/i x j'
   *  Product: '<S46>/j x k'
   *  Product: '<S46>/k x i'
   *  Product: '<S47>/i x k'
   *  Product: '<S47>/j x i'
   *  Product: '<S47>/k x j'
   */
  rtb_u2[0] = rtb_Sum1_e[1] * Mainframe_B.Gain_l[2] - rtb_Product_d *
    Mainframe_B.Gain_l[1];
  rtb_u2[1] = rtb_Product_d * Mainframe_B.Gain_l[0] - rtb_Sum1_e[0] *
    Mainframe_B.Gain_l[2];
  rtb_u2[2] = rtb_Sum1_e[0] * Mainframe_B.Gain_l[1] - rtb_Sum1_e[1] *
    Mainframe_B.Gain_l[0];

  /* Product: '<S44>/k x i' */
  rtb_T_sim_glbl = rtb_u2[0];

  /* Sum: '<S42>/Sum' incorporates:
   *  Product: '<S44>/i x j'
   *  Product: '<S44>/j x k'
   *  Product: '<S45>/i x k'
   *  Product: '<S45>/j x i'
   *  Product: '<S45>/k x j'
   */
  rtb_JMMB_tmp_6 = rtb_Sum1_e[0] * rtb_u2[1];
  q0_tmp = rtb_Sum1_e[0] * rtb_u2[2];
  rtb_Product_b_idx_0 = rtb_Sum1_e[1] * rtb_u2[0];
  rtb_u2[0] = rtb_Sum1_e[1] * rtb_u2[2] - rtb_Product_d * rtb_u2[1];

  /* Gain: '<S34>/Zero-Order Hold3' incorporates:
   *  SignalConversion generated from: '<S30>/Vector Concatenate2'
   * */
  rtb_Sum1_e[0] = Mainframe_P.ZeroOrderHold3_Gain_d * Mainframe_B.d_wBIB[0];
  rtb_Sum1_e[1] = Mainframe_P.ZeroOrderHold3_Gain_d * Mainframe_B.d_wBIB[1];
  rtb_Sum1_e[2] = Mainframe_P.ZeroOrderHold3_Gain_d * Mainframe_B.d_wBIB[2];

  /* Sum: '<S34>/Sum' incorporates:
   *  Gain: '<S31>/Multiply'
   *  Gain: '<S31>/Multiply1'
   *  Gain: '<S31>/Multiply2'
   *  Gain: '<S34>/Zero-Order Hold1'
   *  Gain: '<S34>/Zero-Order Hold2'
   *  Product: '<S31>/Product'
   *  Product: '<S31>/Product1'
   *  Product: '<S44>/k x i'
   *  Product: '<S48>/i x j'
   *  Product: '<S48>/j x k'
   *  Product: '<S48>/k x i'
   *  Product: '<S49>/i x k'
   *  Product: '<S49>/j x i'
   *  Product: '<S49>/k x j'
   *  SignalConversion generated from: '<S30>/Vector Concatenate'
   *  Sum: '<S39>/Sum'
   *  Sum: '<S42>/Sum'
   *  Trigonometry: '<S31>/Cos'
   *  Trigonometry: '<S31>/Cos1'
   *  Trigonometry: '<S31>/Cos3'
   * */
  rtb_u2[0] = ((Mainframe_P.ZeroOrderHold1_Gain_b * Mainframe_B.aBIB[0] -
                Mainframe_P.ZeroOrderHold2_Gain_l *
                (Mainframe_P.Multiply2_Gain_g * sin
                 (Mainframe_B.ComplextoRealImag[1]))) + rtb_u2[0]) +
    (rtb_Sum1_e[1] * Mainframe_B.Gain_l[2] - rtb_Sum1_e[2] * Mainframe_B.Gain_l
     [1]);
  rtb_u2[1] = ((Mainframe_P.ZeroOrderHold1_Gain_b * Mainframe_B.aBIB[1] -
                Mainframe_P.ZeroOrderHold2_Gain_l * (sin
    (Mainframe_B.ComplextoRealImag[0]) * rtb_ixk_k * Mainframe_P.Multiply_Gain_d))
               + (rtb_Product_d * rtb_T_sim_glbl - q0_tmp)) + (rtb_Sum1_e[2] *
    Mainframe_B.Gain_l[0] - rtb_Sum1_e[0] * Mainframe_B.Gain_l[2]);
  rtb_Product4_b_idx_3 = ((Mainframe_P.ZeroOrderHold1_Gain_b * Mainframe_B.aBIB
    [2] - Mainframe_P.ZeroOrderHold2_Gain_l * (rtb_ixk_k * cos
    (Mainframe_B.ComplextoRealImag[0]) * Mainframe_P.Multiply1_Gain_n)) +
    (rtb_JMMB_tmp_6 - rtb_Product_b_idx_0)) + (rtb_Sum1_e[0] *
    Mainframe_B.Gain_l[1] - rtb_Sum1_e[1] * Mainframe_B.Gain_l[0]);

  /* Sum: '<S34>/Sum4' incorporates:
   *  Constant: '<S34>/Measurement bias'
   *  Constant: '<S34>/Scale factors & Cross-coupling  errors'
   *  Product: '<S34>/Product'
   */
  for (i = 0; i < 3; i++) {
    rtb_Sum1_e[i] = ((Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc_i[i +
                      3] * rtb_u2[1] +
                      Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc_i[i] *
                      rtb_u2[0]) +
                     Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc_i[i +
                     6] * rtb_Product4_b_idx_3) +
      Mainframe_P.ThreeaxisInertialMeasurementUnit_a_bias_h[i];
  }

  /* End of Sum: '<S34>/Sum4' */
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
    /* Sqrt: '<S37>/Sqrt1' incorporates:
     *  Constant: '<S37>/Constant1'
     */
    rtb_Switch_j = sqrt(Mainframe_P.Randombias_Ts_i);

    /* Product: '<S37>/Product' incorporates:
     *  Constant: '<S37>/Constant'
     *  Product: '<S37>/Divide'
     *  RandomNumber: '<S37>/White Noise'
     *  Sqrt: '<S37>/Sqrt'
     */
    Mainframe_B.Product[0] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow_e[0])
      / rtb_Switch_j * Mainframe_DW.NextOutput[0];
    Mainframe_B.Product[1] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow_e[1])
      / rtb_Switch_j * Mainframe_DW.NextOutput[1];
    Mainframe_B.Product[2] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow_e[2])
      / rtb_Switch_j * Mainframe_DW.NextOutput[2];
  }

  /* SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
  idx = 3;

  /* Unit Conversion - from: m/s^2 to: gn
     Expression: output = (0.101972*input) + (0) */
  for (i = 0; i < 3; i++) {
    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S36>/Constant'
     */
    if (Mainframe_P.Constant_Value_p3p >= Mainframe_P.Switch_Threshold_k) {
      rtb_T_sim_glbl = rtb_IntegratorSecondOrderLimited_o1[i];
    } else {
      rtb_T_sim_glbl = rtb_Sum1_e[i];
    }

    /* End of Switch: '<S36>/Switch' */

    /* Sum: '<S34>/Sum1' */
    rtb_Product4_b_idx_3 = rtb_T_sim_glbl + Mainframe_B.Product[i];

    /* Saturate: '<S34>/Saturation' */
    if (rtb_Product4_b_idx_3 > Mainframe_P.Saturation_UpperSat_m[i]) {
      Mainframe_B.Saturation[i] = Mainframe_P.Saturation_UpperSat_m[i];
    } else if (rtb_Product4_b_idx_3 < Mainframe_P.Saturation_LowerSat_e1[i]) {
      Mainframe_B.Saturation[i] = Mainframe_P.Saturation_LowerSat_e1[i];
    } else {
      Mainframe_B.Saturation[i] = rtb_Product4_b_idx_3;
    }

    /* End of Saturate: '<S34>/Saturation' */

    /* SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
    rtb_IntegratorSecondOrderLimited_o2_a[i] =
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[idx];
    idx++;

    /* Sum: '<S35>/Sum4' incorporates:
     *  Constant: '<S35>/Measurement bias'
     *  Constant: '<S35>/Scale factors & Cross-coupling  errors '
     *  Constant: '<S35>/g-sensitive bias'
     *  Gain: '<S35>/Zero-Order Hold'
     *  Gain: '<S35>/Zero-Order Hold1'
     *  Product: '<S35>/Product'
     *  Product: '<S35>/Product1'
     *  SignalConversion generated from: '<S30>/Vector Concatenate3'
     *  UnitConversion: '<S33>/Unit Conversion'
     * */
    rtb_Sum4[i] = (((Mainframe_P.ZeroOrderHold_Gain_i * Mainframe_B.x_d[10] *
                     Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sf_cc_e[i] +
                     Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sf_cc_e[i +
                     3] * (Mainframe_P.ZeroOrderHold_Gain_i * Mainframe_B.x_d[11]))
                    + Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sf_cc_e[i +
                    6] * (Mainframe_P.ZeroOrderHold_Gain_i * Mainframe_B.x_d[12]))
                   + Mainframe_P.ThreeaxisInertialMeasurementUnit_g_bias_o[i]) +
      0.10197162129779282 * rtb_uzetawn_p[i] *
      Mainframe_P.ZeroOrderHold1_Gain_be *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_g_sens_m[i];

    /* Sum: '<S34>/Sum1' incorporates:
     *  SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited'
     */
    rtb_u2[i] = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[i];
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
    /* Sqrt: '<S51>/Sqrt1' incorporates:
     *  Constant: '<S51>/Constant1'
     */
    rtb_Switch_j = sqrt(Mainframe_P.Randombias_Ts_h);

    /* Product: '<S51>/Product' incorporates:
     *  Constant: '<S51>/Constant'
     *  Product: '<S51>/Divide'
     *  RandomNumber: '<S51>/White Noise'
     *  Sqrt: '<S51>/Sqrt'
     */
    Mainframe_B.Product_i[0] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow_h[0]) /
      rtb_Switch_j * Mainframe_DW.NextOutput_m[0];
    Mainframe_B.Product_i[1] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow_h[1]) /
      rtb_Switch_j * Mainframe_DW.NextOutput_m[1];
    Mainframe_B.Product_i[2] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow_h[2]) /
      rtb_Switch_j * Mainframe_DW.NextOutput_m[2];
  }

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant'
   */
  if (Mainframe_P.Constant_Value_jy >= Mainframe_P.Switch_Threshold_c) {
    rtb_T_sim_glbl = rtb_u2[0];
  } else {
    rtb_T_sim_glbl = rtb_Sum4[0];
  }

  /* Sum: '<S35>/Sum1' */
  rtb_Product4_b_idx_2 = rtb_T_sim_glbl + Mainframe_B.Product_i[0];

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Product4_b_idx_2 > Mainframe_P.Saturation_UpperSat_jb[0]) {
    Mainframe_B.Saturation_g[0] = Mainframe_P.Saturation_UpperSat_jb[0];
  } else if (rtb_Product4_b_idx_2 < Mainframe_P.Saturation_LowerSat_h[0]) {
    Mainframe_B.Saturation_g[0] = Mainframe_P.Saturation_LowerSat_h[0];
  } else {
    Mainframe_B.Saturation_g[0] = rtb_Product4_b_idx_2;
  }

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant'
   */
  if (Mainframe_P.Constant_Value_jy >= Mainframe_P.Switch_Threshold_c) {
    rtb_T_sim_glbl = rtb_u2[1];
  } else {
    rtb_T_sim_glbl = rtb_Sum4[1];
  }

  /* Sum: '<S35>/Sum1' */
  rtb_Product4_b_idx_2 = rtb_T_sim_glbl + Mainframe_B.Product_i[1];

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Product4_b_idx_2 > Mainframe_P.Saturation_UpperSat_jb[1]) {
    Mainframe_B.Saturation_g[1] = Mainframe_P.Saturation_UpperSat_jb[1];
  } else if (rtb_Product4_b_idx_2 < Mainframe_P.Saturation_LowerSat_h[1]) {
    Mainframe_B.Saturation_g[1] = Mainframe_P.Saturation_LowerSat_h[1];
  } else {
    Mainframe_B.Saturation_g[1] = rtb_Product4_b_idx_2;
  }

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S50>/Constant'
   */
  if (Mainframe_P.Constant_Value_jy >= Mainframe_P.Switch_Threshold_c) {
    rtb_T_sim_glbl = rtb_u2[2];
  } else {
    rtb_T_sim_glbl = rtb_Sum4[2];
  }

  /* Sum: '<S35>/Sum1' */
  rtb_Product4_b_idx_2 = rtb_T_sim_glbl + Mainframe_B.Product_i[2];

  /* Saturate: '<S35>/Saturation' */
  if (rtb_Product4_b_idx_2 > Mainframe_P.Saturation_UpperSat_jb[2]) {
    Mainframe_B.Saturation_g[2] = Mainframe_P.Saturation_UpperSat_jb[2];
  } else if (rtb_Product4_b_idx_2 < Mainframe_P.Saturation_LowerSat_h[2]) {
    Mainframe_B.Saturation_g[2] = Mainframe_P.Saturation_LowerSat_h[2];
  } else {
    Mainframe_B.Saturation_g[2] = rtb_Product4_b_idx_2;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* ToAsyncQueueBlock generated from: '<Root>/Emulate Estimator' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.p;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1110197359U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4156403547U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.r;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1606765488U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.phi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2305462947U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.theta;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(893051655U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.psi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(831987235U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1158053104U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1997342388U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3218268302U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_g[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1817488696U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_g[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1780639081U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_g[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2935969427U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Enabled Subsystem1' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.DigitalClock;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3309731223U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/From5' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3304343069U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(853267115U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_3;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2590797546U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_4;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3441512437U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/From6' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.vBIB[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1856964718U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.vBIB[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2660894958U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.vBIB[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(102008659U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[10];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(867745408U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[11];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4278791749U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[12];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1806566792U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.aBIB[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1585476352U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.aBIB[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2660817397U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.aBIB[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3957705118U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.d_wBIB[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(277397359U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.d_wBIB[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2078467285U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.d_wBIB[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1715215123U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.ComplextoRealImag[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3659361763U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.ComplextoRealImag[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2915724623U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.ComplextoRealImag[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2434242509U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q0;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1193717670U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(725076203U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4101768425U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q3;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4010102393U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1544459028U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1066855102U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1517789491U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_j[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2774521372U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_j[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1205183121U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_j[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(479375500U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_je[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1446509722U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_je[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1348995696U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_je[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(23372329U, time, pData, size);
      }
    }

    /* DataTypeConversion: '<S56>/Cast To Double5' */
    Mainframe_B.gyroX = rtb_myItems[5];

    /* DataTypeConversion: '<S56>/Cast To Double6' */
    Mainframe_B.gyroY = rtb_myItems[6];

    /* DataTypeConversion: '<S56>/Cast To Double7' */
    Mainframe_B.gyroZ = rtb_myItems[7];

    /* DataTypeConversion: '<S56>/Cast To Double8' */
    Mainframe_B.u = rtb_myItems[8];

    /* DataTypeConversion: '<S56>/Cast To Double9' */
    Mainframe_B.v = rtb_myItems[9];

    /* DataTypeConversion: '<S56>/Cast To Double10' */
    Mainframe_B.w = rtb_myItems[10];

    /* DataTypeConversion: '<S56>/Cast To Double12' */
    Mainframe_B.x = rtb_myItems[11];

    /* DataTypeConversion: '<S56>/Cast To Double13' */
    Mainframe_B.y = rtb_myItems[12];

    /* DataTypeConversion: '<S56>/Cast To Double14' */
    Mainframe_B.z = rtb_myItems[13];

    /* DataTypeConversion: '<S56>/Cast To Double15' */
    Mainframe_B.p_a = rtb_myItems[14];

    /* DataTypeConversion: '<S56>/Cast To Double16' */
    Mainframe_B.q_l = rtb_myItems[15];

    /* DataTypeConversion: '<S56>/Cast To Double11' */
    Mainframe_B.r_h = rtb_myItems[16];

    /* ToAsyncQueueBlock generated from: '<Root>/From7' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_1_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3925016344U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_2_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3427867939U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_3_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1011547104U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_4_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1923142615U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gyroX;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(156066950U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gyroY;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2857319297U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gyroZ;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4163597182U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.u;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(328523713U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.v;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1482536487U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.w;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(33329569U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(334319060U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.y;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1104957129U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.z;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2586663111U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.p_a;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1518896715U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q_l;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3508803028U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.r_h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3493397462U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/From8' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gimbalPhi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(266997907U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gimbalTheta;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(87553503U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gimbalPsi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(964975019U, time, pData, size);
      }
    }
  }

  /* Sqrt: '<Root>/Square Root1' incorporates:
   *  Math: '<Root>/Square3'
   *  Math: '<Root>/Square4'
   *  Math: '<Root>/Square5'
   *  Sum: '<Root>/Add1'
   */
  Mainframe_B.SquareRoot1 = sqrt((Mainframe_B.vBIB[0] * Mainframe_B.vBIB[0] +
    Mainframe_B.vBIB[1] * Mainframe_B.vBIB[1]) + Mainframe_B.vBIB[2] *
    Mainframe_B.vBIB[2]);
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Triggered SubSystem: '<S1>/Enabled Subsystem1' */
    /* Constant: '<S66>/One' */
    Mainframe_EnabledSubsystem1(Mainframe_M, Mainframe_P.One_Value,
      &Mainframe_B.EnabledSubsystem1, &Mainframe_DW.EnabledSubsystem1,
      &Mainframe_PrevZCX.EnabledSubsystem1);

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem1' */

    /* Sum: '<S27>/Sum' incorporates:
     *  Constant: '<S27>/Constant2'
     */
    Mainframe_B.Sum = Mainframe_B.EnabledSubsystem1.DigitalClock +
      Mainframe_P.DelayedStep1_stepTime;

    /* Sum: '<S28>/Sum' incorporates:
     *  Constant: '<S28>/Constant2'
     */
    Mainframe_B.Sum_g = Mainframe_B.EnabledSubsystem1.DigitalClock +
      Mainframe_P.DelayedStep2_stepTime;
  }

  /* RelationalOperator: '<S27>/GreaterThan' */
  Mainframe_B.GreaterThan = (rtb_jxi_f >= Mainframe_B.Sum);

  /* RelationalOperator: '<S28>/GreaterThan' */
  Mainframe_B.GreaterThan_e = (rtb_jxi_f >= Mainframe_B.Sum_g);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S27>/Constant1'
   *  Constant: '<S27>/Constant3'
   */
  if (Mainframe_B.GreaterThan) {
    rtb_T_sim_glbl = Mainframe_P.DelayedStep1_u1;
  } else {
    rtb_T_sim_glbl = Mainframe_P.DelayedStep1_u0;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S28>/Constant3'
   */
  if (Mainframe_B.GreaterThan_e) {
    q0_tmp = Mainframe_P.DelayedStep2_u1;
  } else {
    q0_tmp = Mainframe_P.DelayedStep2_u0;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Sum: '<S1>/Sum' */
  Mainframe_B.phicmdrad = rtb_T_sim_glbl + q0_tmp;

  /* RelationalOperator: '<S26>/GreaterThan' */
  Mainframe_B.GreaterThan_c = (rtb_jxi_f >=
    Mainframe_B.EnabledSubsystem1.DigitalClock);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S26>/Zero'
   *  Sin: '<S26>/Sine Wave'
   *  Sum: '<S26>/Subtract'
   */
  if (Mainframe_B.GreaterThan_c) {
    rtb_T_sim_glbl = sin((rtb_jxi_f - Mainframe_B.EnabledSubsystem1.DigitalClock)
                         * Mainframe_P.DelayedSine_freq +
                         Mainframe_P.DelayedSine_phase) *
      Mainframe_P.DelayedSine_amp + Mainframe_P.DelayedSine_bias;
  } else {
    rtb_T_sim_glbl = Mainframe_P.Zero_Value_d;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Product: '<S1>/Product' */
  Mainframe_B.phicmdrad_m = Mainframe_B.phicmdrad * rtb_T_sim_glbl;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S41>/2*zeta * wn' */
  rtb_T_sim_glbl = 2.0 * Mainframe_P.ThreeaxisInertialMeasurementUnit_z_a_m *
    Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a_m;

  /* Gain: '<S41>/wn^2' */
  rtb_jxi_f = Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a_m *
    Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a_m;

  /* Sum: '<S41>/Sum2' incorporates:
   *  Gain: '<S41>/2*zeta * wn'
   *  Gain: '<S41>/wn^2'
   *  SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited'
   *  Sum: '<S41>/Sum3'
   */
  Mainframe_B.Sum2[0] = (rtb_Sum1_e[0] -
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[0]) * rtb_jxi_f -
    rtb_T_sim_glbl * Mainframe_X.IntegratorSecondOrderLimited_CSTATE[3];
  Mainframe_B.Sum2[1] = (rtb_Sum1_e[1] -
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[1]) * rtb_jxi_f -
    rtb_T_sim_glbl * Mainframe_X.IntegratorSecondOrderLimited_CSTATE[4];
  Mainframe_B.Sum2[2] = (rtb_Sum1_e[2] -
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[2]) * rtb_jxi_f -
    rtb_T_sim_glbl * Mainframe_X.IntegratorSecondOrderLimited_CSTATE[5];

  /* Gain: '<S53>/2*zeta * wn' */
  rtb_T_sim_glbl = 2.0 * Mainframe_P.ThreeaxisInertialMeasurementUnit_z_g_h *
    Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g_n;

  /* Gain: '<S53>/wn^2' */
  rtb_jxi_f = Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g_n *
    Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g_n;

  /* Sum: '<S53>/Sum2' incorporates:
   *  Gain: '<S53>/2*zeta * wn'
   *  Gain: '<S53>/wn^2'
   *  Sum: '<S53>/Sum3'
   */
  Mainframe_B.Sum2_k[0] = (rtb_Sum4[0] - rtb_u2[0]) * rtb_jxi_f - rtb_T_sim_glbl
    * rtb_IntegratorSecondOrderLimited_o2_a[0];
  Mainframe_B.Sum2_k[1] = (rtb_Sum4[1] - rtb_u2[1]) * rtb_jxi_f - rtb_T_sim_glbl
    * rtb_IntegratorSecondOrderLimited_o2_a[1];
  Mainframe_B.Sum2_k[2] = (rtb_Sum4[2] - rtb_u2[2]) * rtb_jxi_f - rtb_T_sim_glbl
    * rtb_IntegratorSecondOrderLimited_o2_a[2];
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S56>/Cast To Double17' */
    Mainframe_B.debug = rtb_myItems[17];

    /* UnitDelay: '<S62>/Output' */
    rtb_FixPtSum1 = Mainframe_DW.Output_DSTATE;

    /* DataTypeConversion: '<S57>/Cast To Single18' incorporates:
     *  Constant: '<S61>/Zero'
     *  DataTypeConversion: '<S61>/Cast To Double14'
     *  Sum: '<S61>/Subtract'
     *  UnitDelay: '<S62>/Output'
     */
    Mainframe_B.CastToSingle18 = (real32_T)Mainframe_DW.Output_DSTATE -
      Mainframe_P.Zero_Value_i;

    /* RateTransition: '<S55>/Rate Transition' */
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      Mainframe_B.RateTransition = Mainframe_B.CastToSingle18;
    }

    /* End of RateTransition: '<S55>/Rate Transition' */

    /* DataTypeConversion: '<S55>/Cast To Single' */
    Mainframe_B.CastToSingle = (real32_T)rtb_myItems[0];
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (sldrtpo): '<S58>/Packet Output' */
    /* S-Function Block: <S58>/Packet Output */

    /* no code required */
  }

  /* DataTypeConversion: '<S57>/Cast To Single15' */
  Mainframe_B.CastToSingle15 = (real32_T)Mainframe_B.vBIB[0];

  /* DataTypeConversion: '<S57>/Cast To Single14' */
  Mainframe_B.CastToSingle14 = (real32_T)Mainframe_B.vBIB[1];

  /* DataTypeConversion: '<S57>/Cast To Single13' */
  Mainframe_B.CastToSingle13 = (real32_T)Mainframe_B.vBIB[2];

  /* DataTypeConversion: '<S57>/Cast To Single12' */
  Mainframe_B.CastToSingle12 = (real32_T)Mainframe_B.x_d[0];

  /* DataTypeConversion: '<S57>/Cast To Single11' */
  Mainframe_B.CastToSingle11 = (real32_T)Mainframe_B.x_d[1];

  /* DataTypeConversion: '<S57>/Cast To Single10' */
  Mainframe_B.CastToSingle10 = (real32_T)Mainframe_B.x_d[2];

  /* DataTypeConversion: '<S57>/Cast To Single9' */
  Mainframe_B.CastToSingle9 = (real32_T)Mainframe_B.x_d[10];

  /* DataTypeConversion: '<S57>/Cast To Single8' */
  Mainframe_B.CastToSingle8 = (real32_T)Mainframe_B.x_d[11];

  /* DataTypeConversion: '<S57>/Cast To Single7' */
  Mainframe_B.CastToSingle7 = (real32_T)Mainframe_B.x_d[12];

  /* DataTypeConversion: '<S57>/Cast To Single6' */
  Mainframe_B.CastToSingle6 = (real32_T)Mainframe_B.Saturation_j[0];

  /* DataTypeConversion: '<S57>/Cast To Single5' */
  Mainframe_B.CastToSingle5 = (real32_T)Mainframe_B.Saturation_j[1];

  /* DataTypeConversion: '<S57>/Cast To Single4' */
  Mainframe_B.CastToSingle4 = (real32_T)Mainframe_B.Saturation_j[2];

  /* DataTypeConversion: '<S57>/Cast To Single3' */
  Mainframe_B.CastToSingle3 = (real32_T)Mainframe_B.Saturation_je[0];

  /* DataTypeConversion: '<S57>/Cast To Single2' */
  Mainframe_B.CastToSingle2 = (real32_T)Mainframe_B.Saturation_je[1];

  /* DataTypeConversion: '<S57>/Cast To Single1' */
  Mainframe_B.CastToSingle1 = (real32_T)Mainframe_B.Saturation_je[2];

  /* DataTypeConversion: '<S57>/Cast To Single20' */
  Mainframe_B.CastToSingle20 = (real32_T)Mainframe_B.phicmdrad_m;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S57>/Cast To Single19' incorporates:
     *  Constant: '<S66>/One'
     */
    Mainframe_B.CastToSingle19 = Mainframe_P.One_Value;

    /* DataTypeConversion: '<S57>/Cast To Single17' incorporates:
     *  Constant: '<S4>/Constant4'
     */
    Mainframe_B.CastToSingle17 = Mainframe_P.INS_Passthrough;

    /* DataTypeConversion: '<S57>/Cast To Single16' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    Mainframe_B.CastToSingle16 = Mainframe_P.Real_Gyros;

    /* Sum: '<S63>/FixPt Sum1' incorporates:
     *  Constant: '<S63>/FixPt Constant'
     */
    rtb_FixPtSum1 = (uint16_T)((uint32_T)rtb_FixPtSum1 +
      Mainframe_P.FixPtConstant_Value);

    /* Switch: '<S64>/FixPt Switch' incorporates:
     *  Constant: '<S64>/Constant'
     */
    if (rtb_FixPtSum1 > Mainframe_P.WrapToZero_Threshold) {
      Mainframe_B.FixPtSwitch = Mainframe_P.Constant_Value_hg;
    } else {
      Mainframe_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S64>/FixPt Switch' */
  }

  /* Logic: '<S67>/AND' incorporates:
   *  Constant: '<S66>/One'
   *  Constant: '<S71>/Constant'
   *  RelationalOperator: '<S71>/Compare'
   */
  Mainframe_B.AND = (Mainframe_P.One_Value && (Mainframe_B.x_d[2] >=
    Mainframe_P.CompareToConstant_const_n));
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Stop: '<S67>/Stop Simulation' */
    if (Mainframe_B.AND) {
      rtmSetStopRequested(Mainframe_M, 1);
    }

    /* End of Stop: '<S67>/Stop Simulation' */
  }
}

/* Model update function */
void Mainframe_update(void)
{
  real_T *lastU;

  /* Update for Enabled SubSystem: '<S7>/Subsystem' incorporates:
   *  EnablePort: '<S68>/Enable'
   */
  if (Mainframe_DW.Subsystem_MODE) {
    /* Update for Integrator: '<S238>/integration_eom' */
    Mainframe_DW.integration_eom_IWORK = 0;

    /* Update for Integrator: '<S183>/integration_eom' */
    Mainframe_DW.integration_eom_IWORK_p = 0;

    /* Update for Integrator: '<S184>/integration_eom' */
    Mainframe_DW.integration_eom_IWORK_g = 0;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
      /* Update for RandomNumber: '<S84>/White Noise' */
      Mainframe_DW.NextOutput_mb[0] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_gr[0]) * Mainframe_P.WhiteNoise_StdDev +
        Mainframe_P.WhiteNoise_Mean;

      /* Update for RandomNumber: '<S98>/White Noise' */
      Mainframe_DW.NextOutput_i[0] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_i[0]) * Mainframe_P.WhiteNoise_StdDev_f +
        Mainframe_P.WhiteNoise_Mean_i;

      /* Update for RandomNumber: '<S84>/White Noise' */
      Mainframe_DW.NextOutput_mb[1] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_gr[1]) * Mainframe_P.WhiteNoise_StdDev +
        Mainframe_P.WhiteNoise_Mean;

      /* Update for RandomNumber: '<S98>/White Noise' */
      Mainframe_DW.NextOutput_i[1] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_i[1]) * Mainframe_P.WhiteNoise_StdDev_f +
        Mainframe_P.WhiteNoise_Mean_i;

      /* Update for RandomNumber: '<S84>/White Noise' */
      Mainframe_DW.NextOutput_mb[2] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_gr[2]) * Mainframe_P.WhiteNoise_StdDev +
        Mainframe_P.WhiteNoise_Mean;

      /* Update for RandomNumber: '<S98>/White Noise' */
      Mainframe_DW.NextOutput_i[2] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_i[2]) * Mainframe_P.WhiteNoise_StdDev_f +
        Mainframe_P.WhiteNoise_Mean_i;
    }

    /* Update for Derivative: '<S185>/Derivative1' */
    if (Mainframe_DW.TimeStampA == (rtInf)) {
      Mainframe_DW.TimeStampA = Mainframe_M->Timing.t[0];
      lastU = &Mainframe_DW.LastUAtTimeA;
    } else if (Mainframe_DW.TimeStampB == (rtInf)) {
      Mainframe_DW.TimeStampB = Mainframe_M->Timing.t[0];
      lastU = &Mainframe_DW.LastUAtTimeB;
    } else if (Mainframe_DW.TimeStampA < Mainframe_DW.TimeStampB) {
      Mainframe_DW.TimeStampA = Mainframe_M->Timing.t[0];
      lastU = &Mainframe_DW.LastUAtTimeA;
    } else {
      Mainframe_DW.TimeStampB = Mainframe_M->Timing.t[0];
      lastU = &Mainframe_DW.LastUAtTimeB;
    }

    *lastU = Mainframe_B.Switch[0];

    /* End of Update for Derivative: '<S185>/Derivative1' */

    /* Update for Derivative: '<S185>/Derivative' */
    if (Mainframe_DW.TimeStampA_i == (rtInf)) {
      Mainframe_DW.TimeStampA_i = Mainframe_M->Timing.t[0];
      lastU = &Mainframe_DW.LastUAtTimeA_d;
    } else if (Mainframe_DW.TimeStampB_c == (rtInf)) {
      Mainframe_DW.TimeStampB_c = Mainframe_M->Timing.t[0];
      lastU = &Mainframe_DW.LastUAtTimeB_g;
    } else if (Mainframe_DW.TimeStampA_i < Mainframe_DW.TimeStampB_c) {
      Mainframe_DW.TimeStampA_i = Mainframe_M->Timing.t[0];
      lastU = &Mainframe_DW.LastUAtTimeA_d;
    } else {
      Mainframe_DW.TimeStampB_c = Mainframe_M->Timing.t[0];
      lastU = &Mainframe_DW.LastUAtTimeB_g;
    }

    *lastU = Mainframe_B.Switch[1];

    /* End of Update for Derivative: '<S185>/Derivative' */
  }

  /* End of Update for SubSystem: '<S7>/Subsystem' */
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Mainframe_DW.DiscreteTimeIntegrator1_DSTATE +=
      Mainframe_P.DiscreteTimeIntegrator1_gainval * Mainframe_B.gyroX;

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    Mainframe_DW.DiscreteTimeIntegrator_DSTATE +=
      Mainframe_P.DiscreteTimeIntegrator_gainval * Mainframe_B.gyroY;

    /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
    Mainframe_DW.DiscreteTimeIntegrator2_DSTATE +=
      Mainframe_P.DiscreteTimeIntegrator2_gainval * Mainframe_B.gyroZ;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update for RandomNumber: '<S37>/White Noise' */
    Mainframe_DW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[0]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* Update for RandomNumber: '<S51>/White Noise' */
    Mainframe_DW.NextOutput_m[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[0]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;

    /* Update for RandomNumber: '<S37>/White Noise' */
    Mainframe_DW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[1]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* Update for RandomNumber: '<S51>/White Noise' */
    Mainframe_DW.NextOutput_m[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[1]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;

    /* Update for RandomNumber: '<S37>/White Noise' */
    Mainframe_DW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[2]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* Update for RandomNumber: '<S51>/White Noise' */
    Mainframe_DW.NextOutput_m[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[2]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S62>/Output' */
    Mainframe_DW.Output_DSTATE = Mainframe_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for S-Function (sldrtpo): '<S58>/Packet Output' */

    /* S-Function Block: <S58>/Packet Output */
    {
      uint8_T outdata[80U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        real32_T pktout = Mainframe_B.CastToSingle19;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle18;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle17;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle16;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle15;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle14;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle13;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle12;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle11;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle10;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle9;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle8;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle7;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle6;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle5;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle4;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle3;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle2;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle1;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle20;
        *outdp.p_real32_T++ = pktout;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 80U,
                     &Mainframe_P.PacketOutput_PacketID, (double*) outdata, NULL);
    }
  }

  if (rtmIsMajorTimeStep(Mainframe_M)) {
    rt_ertODEUpdateContinuousStates(&Mainframe_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Mainframe_M->Timing.clockTick0)) {
    ++Mainframe_M->Timing.clockTickH0;
  }

  Mainframe_M->Timing.t[0] = rtsiGetSolverStopTime(&Mainframe_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Mainframe_M->Timing.clockTick1)) {
      ++Mainframe_M->Timing.clockTickH1;
    }

    Mainframe_M->Timing.t[1] = Mainframe_M->Timing.clockTick1 *
      Mainframe_M->Timing.stepSize1 + Mainframe_M->Timing.clockTickH1 *
      Mainframe_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Mainframe_M->Timing.clockTick2)) {
      ++Mainframe_M->Timing.clockTickH2;
    }

    Mainframe_M->Timing.t[2] = Mainframe_M->Timing.clockTick2 *
      Mainframe_M->Timing.stepSize2 + Mainframe_M->Timing.clockTickH2 *
      Mainframe_M->Timing.stepSize2 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Mainframe_M->Timing.clockTick3)) {
      ++Mainframe_M->Timing.clockTickH3;
    }

    Mainframe_M->Timing.t[3] = Mainframe_M->Timing.clockTick3 *
      Mainframe_M->Timing.stepSize3 + Mainframe_M->Timing.clockTickH3 *
      Mainframe_M->Timing.stepSize3 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void Mainframe_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  XDot_Mainframe_T *_rtXdot;
  _rtXdot = ((XDot_Mainframe_T *) Mainframe_M->derivs);

  /* Derivatives for TransferFcn: '<S287>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += Mainframe_P.TransferFcn1_A[0] *
    Mainframe_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += Mainframe_P.TransferFcn1_A[1] *
    Mainframe_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += Mainframe_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += Mainframe_B.Fin_1_Cmd_rad;

  /* Derivatives for TransferFcn: '<S287>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += Mainframe_P.TransferFcn2_A[0] *
    Mainframe_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += Mainframe_P.TransferFcn2_A[1] *
    Mainframe_X.TransferFcn2_CSTATE[1];
  _rtXdot->TransferFcn2_CSTATE[1] += Mainframe_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[0] += Mainframe_B.Fin_2_Cmd_rad;

  /* Derivatives for TransferFcn: '<S287>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += Mainframe_P.TransferFcn3_A[0] *
    Mainframe_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += Mainframe_P.TransferFcn3_A[1] *
    Mainframe_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] += Mainframe_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[0] += Mainframe_B.Fin_3_Cmd_rad;

  /* Derivatives for TransferFcn: '<S287>/Transfer Fcn4' */
  _rtXdot->TransferFcn4_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn4_CSTATE[0] += Mainframe_P.TransferFcn4_A[0] *
    Mainframe_X.TransferFcn4_CSTATE[0];
  _rtXdot->TransferFcn4_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn4_CSTATE[0] += Mainframe_P.TransferFcn4_A[1] *
    Mainframe_X.TransferFcn4_CSTATE[1];
  _rtXdot->TransferFcn4_CSTATE[1] += Mainframe_X.TransferFcn4_CSTATE[0];
  _rtXdot->TransferFcn4_CSTATE[0] += Mainframe_B.Fin_4_Cmd_rad;

  /* Derivatives for Enabled SubSystem: '<S7>/Subsystem' */
  if (Mainframe_DW.Subsystem_MODE) {
    /* Derivatives for Integrator: '<S238>/integration_eom' */
    memcpy(&_rtXdot->integration_eom_CSTATE[0], &Mainframe_B.d_x[0], 13U *
           sizeof(real_T));

    /* Derivatives for Integrator: '<S183>/integration_eom' */
    _rtXdot->integration_eom_CSTATE_o[0] = Mainframe_B.VectorConcatenate_m[0];
    _rtXdot->integration_eom_CSTATE_o[1] = Mainframe_B.VectorConcatenate_m[1];
    _rtXdot->integration_eom_CSTATE_o[2] = Mainframe_B.VectorConcatenate_m[2];
    _rtXdot->integration_eom_CSTATE_o[3] = Mainframe_B.VectorConcatenate_m[3];

    /* Derivatives for Integrator: '<S151>/Integrator1' */
    lsat = (Mainframe_X.Integrator1_CSTATE <= Mainframe_P.Rudder_siB_min);
    usat = (Mainframe_X.Integrator1_CSTATE >= Mainframe_P.Rudder_siB_max);
    if (((!lsat) && (!usat)) || (lsat && (Mainframe_B.sf_Limiting_Rate.d_siB_l >
          0.0)) || (usat && (Mainframe_B.sf_Limiting_Rate.d_siB_l < 0.0))) {
      _rtXdot->Integrator1_CSTATE = Mainframe_B.sf_Limiting_Rate.d_siB_l;
    } else {
      /* in saturation */
      _rtXdot->Integrator1_CSTATE = 0.0;
    }

    /* End of Derivatives for Integrator: '<S151>/Integrator1' */

    /* Derivatives for Integrator: '<S152>/Integrator1' */
    lsat = (Mainframe_X.Integrator1_CSTATE_n <= Mainframe_P.Rudder1_siB_min);
    usat = (Mainframe_X.Integrator1_CSTATE_n >= Mainframe_P.Rudder1_siB_max);
    if (((!lsat) && (!usat)) || (lsat && (Mainframe_B.sf_Limiting_Rate_g.d_siB_l
          > 0.0)) || (usat && (Mainframe_B.sf_Limiting_Rate_g.d_siB_l < 0.0))) {
      _rtXdot->Integrator1_CSTATE_n = Mainframe_B.sf_Limiting_Rate_g.d_siB_l;
    } else {
      /* in saturation */
      _rtXdot->Integrator1_CSTATE_n = 0.0;
    }

    /* End of Derivatives for Integrator: '<S152>/Integrator1' */

    /* Derivatives for Integrator: '<S153>/Integrator1' */
    lsat = (Mainframe_X.Integrator1_CSTATE_k <= Mainframe_P.Rudder2_siB_min);
    usat = (Mainframe_X.Integrator1_CSTATE_k >= Mainframe_P.Rudder2_siB_max);
    if (((!lsat) && (!usat)) || (lsat && (Mainframe_B.sf_Limiting_Rate_a.d_siB_l
          > 0.0)) || (usat && (Mainframe_B.sf_Limiting_Rate_a.d_siB_l < 0.0))) {
      _rtXdot->Integrator1_CSTATE_k = Mainframe_B.sf_Limiting_Rate_a.d_siB_l;
    } else {
      /* in saturation */
      _rtXdot->Integrator1_CSTATE_k = 0.0;
    }

    /* End of Derivatives for Integrator: '<S153>/Integrator1' */

    /* Derivatives for Integrator: '<S154>/Integrator1' */
    lsat = (Mainframe_X.Integrator1_CSTATE_f <= Mainframe_P.Rudder3_siB_min);
    usat = (Mainframe_X.Integrator1_CSTATE_f >= Mainframe_P.Rudder3_siB_max);
    if (((!lsat) && (!usat)) || (lsat && (Mainframe_B.sf_Limiting_Rate_o.d_siB_l
          > 0.0)) || (usat && (Mainframe_B.sf_Limiting_Rate_o.d_siB_l < 0.0))) {
      _rtXdot->Integrator1_CSTATE_f = Mainframe_B.sf_Limiting_Rate_o.d_siB_l;
    } else {
      /* in saturation */
      _rtXdot->Integrator1_CSTATE_f = 0.0;
    }

    /* End of Derivatives for Integrator: '<S154>/Integrator1' */

    /* Derivatives for Integrator: '<S184>/integration_eom' */
    _rtXdot->integration_eom_CSTATE_k[0] = Mainframe_B.VectorConcatenate_e[0];
    _rtXdot->integration_eom_CSTATE_k[1] = Mainframe_B.VectorConcatenate_e[1];
    _rtXdot->integration_eom_CSTATE_k[2] = Mainframe_B.VectorConcatenate_e[2];
    _rtXdot->integration_eom_CSTATE_k[3] = Mainframe_B.VectorConcatenate_e[3];

    /* Derivatives for SecondOrderIntegrator: '<S88>/Integrator, Second-Order Limited' */
    if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[0] == 0) {
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_g[0] =
        Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[3];
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_g[3] = Mainframe_B.Sum2_b[0];
    }

    if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[1] == 0) {
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_g[1] =
        Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[4];
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_g[4] = Mainframe_B.Sum2_b[1];
    }

    if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[2] == 0) {
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_g[2] =
        Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[5];
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_g[5] = Mainframe_B.Sum2_b[2];
    }

    /* End of Derivatives for SecondOrderIntegrator: '<S88>/Integrator, Second-Order Limited' */

    /* Derivatives for SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[0] == 0) {
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_e[0] =
        Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[3];
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_e[3] = Mainframe_B.Sum2_h[0];
    }

    if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[1] == 0) {
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_e[1] =
        Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[4];
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_e[4] = Mainframe_B.Sum2_h[1];
    }

    if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[2] == 0) {
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_e[2] =
        Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[5];
      _rtXdot->IntegratorSecondOrderLimited_CSTATE_e[5] = Mainframe_B.Sum2_h[2];
    }

    /* End of Derivatives for SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */

    /* Derivatives for Integrator: '<S151>/Integrator' */
    _rtXdot->Integrator_CSTATE = Mainframe_B.sf_Limiting_Acceleration.dd_siB_l;

    /* Derivatives for Integrator: '<S152>/Integrator' */
    _rtXdot->Integrator_CSTATE_g =
      Mainframe_B.sf_Limiting_Acceleration_p.dd_siB_l;

    /* Derivatives for Integrator: '<S153>/Integrator' */
    _rtXdot->Integrator_CSTATE_f =
      Mainframe_B.sf_Limiting_Acceleration_l.dd_siB_l;

    /* Derivatives for Integrator: '<S154>/Integrator' */
    _rtXdot->Integrator_CSTATE_o =
      Mainframe_B.sf_Limiting_Acceleration_j.dd_siB_l;
  } else {
    {
      real_T *dx;
      int_T i;
      dx = &(((XDot_Mainframe_T *) Mainframe_M->derivs)->integration_eom_CSTATE
             [0]);
      for (i=0; i < 41; i++) {
        dx[i] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<S7>/Subsystem' */

  /* Derivatives for SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited' */
  if (Mainframe_DW.IntegratorSecondOrderLimited_MODE[0] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[0] =
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE[3];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[3] = Mainframe_B.Sum2[0];
  }

  if (Mainframe_DW.IntegratorSecondOrderLimited_MODE[1] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[1] =
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE[4];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[4] = Mainframe_B.Sum2[1];
  }

  if (Mainframe_DW.IntegratorSecondOrderLimited_MODE[2] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[2] =
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE[5];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE[5] = Mainframe_B.Sum2[2];
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited' */

  /* Derivatives for SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
  if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[0] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_c[0] =
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[3];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_c[3] = Mainframe_B.Sum2_k[0];
  }

  if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[1] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_c[1] =
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[4];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_c[4] = Mainframe_B.Sum2_k[1];
  }

  if (Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[2] == 0) {
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_c[2] =
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[5];
    _rtXdot->IntegratorSecondOrderLimited_CSTATE_c[5] = Mainframe_B.Sum2_k[2];
  }

  /* End of Derivatives for SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
}

/* Model initialize function */
void Mainframe_initialize(void)
{
  /* Start for Enabled SubSystem: '<S7>/Subsystem' */
  Mainframe_DW.Subsystem_MODE = false;

  /* Start for Constant: '<S208>/Constant' */
  memcpy(&Mainframe_B.Constant[0], &Mainframe_P.Constant_Value_cg[0], 13U *
         sizeof(real_T));

  /* Start for Constant: '<S183>/Constant8' */
  Mainframe_B.Constant8[0] = Mainframe_P.Constant8_Value_mc[0];

  /* Start for Constant: '<S184>/Constant8' */
  Mainframe_B.Constant8_a[0] = Mainframe_P.Constant8_Value_el[0];

  /* Start for Constant: '<S183>/Constant8' */
  Mainframe_B.Constant8[1] = Mainframe_P.Constant8_Value_mc[1];

  /* Start for Constant: '<S184>/Constant8' */
  Mainframe_B.Constant8_a[1] = Mainframe_P.Constant8_Value_el[1];

  /* Start for Constant: '<S183>/Constant8' */
  Mainframe_B.Constant8[2] = Mainframe_P.Constant8_Value_mc[2];

  /* Start for Constant: '<S184>/Constant8' */
  Mainframe_B.Constant8_a[2] = Mainframe_P.Constant8_Value_el[2];

  /* Start for Constant: '<S183>/Constant8' */
  Mainframe_B.Constant8[3] = Mainframe_P.Constant8_Value_mc[3];

  /* Start for Constant: '<S184>/Constant8' */
  Mainframe_B.Constant8_a[3] = Mainframe_P.Constant8_Value_el[3];

  /* Start for Enabled SubSystem: '<S210>/q_R^0(R)' */
  Mainframe_DW.q_R0R_MODE = false;

  /* End of Start for SubSystem: '<S210>/q_R^0(R)' */

  /* Start for Enabled SubSystem: '<S210>/q_R^1(R)' */
  Mainframe_DW.q_R1R_MODE = false;

  /* End of Start for SubSystem: '<S210>/q_R^1(R)' */

  /* Start for Enabled SubSystem: '<S210>/q_R^2(R)' */
  Mainframe_DW.q_R2R_MODE = false;

  /* End of Start for SubSystem: '<S210>/q_R^2(R)' */

  /* Start for Enabled SubSystem: '<S210>/q_R^3(R)' */
  Mainframe_DW.q_R3R_MODE = false;

  /* End of Start for SubSystem: '<S210>/q_R^3(R)' */
  /* End of Start for SubSystem: '<S7>/Subsystem' */
  /* Start for S-Function (sldrtpo): '<S58>/Packet Output' */

  /* S-Function Block: <S58>/Packet Output */
  /* no initial value should be set */
  Mainframe_PrevZCX.EnabledSubsystem1_Trig_ZCE_b = POS_ZCSIG;
  Mainframe_PrevZCX.EnabledSubsystem_Trig_ZCE = POS_ZCSIG;
  Mainframe_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Mainframe_PrevZCX.Integrator_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  Mainframe_PrevZCX.Integrator_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
  Mainframe_PrevZCX.Integrator_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  Mainframe_PrevZCX.EnabledSubsystem1_h.EnabledSubsystem1_Trig_ZCE = POS_ZCSIG;
  Mainframe_PrevZCX.EnabledSubsystem1.EnabledSubsystem1_Trig_ZCE = POS_ZCSIG;

  {
    uint32_T tseed;
    int32_T t;
    int32_T i;
    real_T tmp;

    /* InitializeConditions for TransferFcn: '<S287>/Transfer Fcn1' */
    Mainframe_X.TransferFcn1_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S287>/Transfer Fcn2' */
    Mainframe_X.TransferFcn2_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S287>/Transfer Fcn3' */
    Mainframe_X.TransferFcn3_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S287>/Transfer Fcn4' */
    Mainframe_X.TransferFcn4_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S287>/Transfer Fcn1' */
    Mainframe_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S287>/Transfer Fcn2' */
    Mainframe_X.TransferFcn2_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S287>/Transfer Fcn3' */
    Mainframe_X.TransferFcn3_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S287>/Transfer Fcn4' */
    Mainframe_X.TransferFcn4_CSTATE[1] = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
    Mainframe_DW.DiscreteTimeIntegrator1_DSTATE =
      Mainframe_P.DiscreteTimeIntegrator1_IC;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
    Mainframe_DW.DiscreteTimeIntegrator_DSTATE =
      Mainframe_P.DiscreteTimeIntegrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
    Mainframe_DW.DiscreteTimeIntegrator2_DSTATE =
      Mainframe_P.DiscreteTimeIntegrator2_IC;

    /* InitializeConditions for SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[0] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_l;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[1] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_l;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[2] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_l;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[3] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_b;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE[0] = 0;

    /* InitializeConditions for RandomNumber: '<S37>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisAccelerometer_a_seeds_a[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed[0] = tseed;
    Mainframe_DW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[0]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* InitializeConditions for SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[0] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_h;

    /* InitializeConditions for SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[4] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_b;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE[1] = 0;

    /* InitializeConditions for RandomNumber: '<S37>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisAccelerometer_a_seeds_a[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed[1] = tseed;
    Mainframe_DW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[1]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* InitializeConditions for SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[1] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_h;

    /* InitializeConditions for SecondOrderIntegrator: '<S41>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[5] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_b;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE[2] = 0;

    /* InitializeConditions for RandomNumber: '<S37>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisAccelerometer_a_seeds_a[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed[2] = tseed;
    Mainframe_DW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[2]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* InitializeConditions for SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[2] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_h;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[3] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_d;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[0] = 0;

    /* InitializeConditions for RandomNumber: '<S51>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisGyroscope_g_seeds_o[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_g[0] = tseed;
    Mainframe_DW.NextOutput_m[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[0]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;

    /* InitializeConditions for SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[4] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_d;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[1] = 0;

    /* InitializeConditions for RandomNumber: '<S51>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisGyroscope_g_seeds_o[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_g[1] = tseed;
    Mainframe_DW.NextOutput_m[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[1]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;

    /* InitializeConditions for SecondOrderIntegrator: '<S53>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[5] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_d;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[2] = 0;

    /* InitializeConditions for RandomNumber: '<S51>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisGyroscope_g_seeds_o[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_g[2] = tseed;
    Mainframe_DW.NextOutput_m[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[2]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;

    /* InitializeConditions for UnitDelay: '<S62>/Output' */
    Mainframe_DW.Output_DSTATE = Mainframe_P.Output_InitialCondition;

    /* SystemInitialize for Triggered SubSystem: '<S70>/Enabled Subsystem1' */
    Mainframe_EnabledSubsystem1_Init(&Mainframe_B.EnabledSubsystem1_h,
      &Mainframe_P.EnabledSubsystem1_h);

    /* End of SystemInitialize for SubSystem: '<S70>/Enabled Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S7>/Subsystem' */
    /* InitializeConditions for Integrator: '<S238>/integration_eom' incorporates:
     *  Integrator: '<S183>/integration_eom'
     */
    if (rtmIsFirstInitCond(Mainframe_M)) {
      Mainframe_X.integration_eom_CSTATE[0] = 0.0;
      Mainframe_X.integration_eom_CSTATE[1] = 0.0;
      Mainframe_X.integration_eom_CSTATE[2] = -15.0;
      Mainframe_X.integration_eom_CSTATE[3] = 0.0;
      Mainframe_X.integration_eom_CSTATE[4] = 0.0;
      Mainframe_X.integration_eom_CSTATE[5] = 0.0;
      Mainframe_X.integration_eom_CSTATE[6] = 0.0;
      Mainframe_X.integration_eom_CSTATE[7] = -0.64278760968653936;
      Mainframe_X.integration_eom_CSTATE[8] = 0.0;
      Mainframe_X.integration_eom_CSTATE[9] = 0.76604444311897812;
      Mainframe_X.integration_eom_CSTATE[10] = 0.0;
      Mainframe_X.integration_eom_CSTATE[11] = 0.0;
      Mainframe_X.integration_eom_CSTATE[12] = 0.0;
      Mainframe_X.integration_eom_CSTATE_o[0] = 0.0;
      Mainframe_X.integration_eom_CSTATE_o[1] = 0.0;
      Mainframe_X.integration_eom_CSTATE_o[2] = 0.0;
      Mainframe_X.integration_eom_CSTATE_o[3] = 1.0;
    }

    Mainframe_DW.integration_eom_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S238>/integration_eom' */

    /* InitializeConditions for Integrator: '<S183>/integration_eom' */
    Mainframe_DW.integration_eom_IWORK_p = 1;

    /* InitializeConditions for Integrator: '<S151>/Integrator1' */
    Mainframe_X.Integrator1_CSTATE = Mainframe_P.Rudder_siB_0;

    /* InitializeConditions for Integrator: '<S152>/Integrator1' */
    Mainframe_X.Integrator1_CSTATE_n = Mainframe_P.Rudder1_siB_0;

    /* InitializeConditions for Integrator: '<S153>/Integrator1' */
    Mainframe_X.Integrator1_CSTATE_k = Mainframe_P.Rudder2_siB_0;

    /* InitializeConditions for Integrator: '<S154>/Integrator1' */
    Mainframe_X.Integrator1_CSTATE_f = Mainframe_P.Rudder3_siB_0;

    /* InitializeConditions for Integrator: '<S184>/integration_eom' */
    if (rtmIsFirstInitCond(Mainframe_M)) {
      Mainframe_X.integration_eom_CSTATE_k[0] = 0.0;
      Mainframe_X.integration_eom_CSTATE_k[1] = 0.0;
      Mainframe_X.integration_eom_CSTATE_k[2] = 0.0;
      Mainframe_X.integration_eom_CSTATE_k[3] = 1.0;
    }

    Mainframe_DW.integration_eom_IWORK_g = 1;

    /* End of InitializeConditions for Integrator: '<S184>/integration_eom' */

    /* InitializeConditions for SecondOrderIntegrator: '<S88>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[0] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[1] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[2] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[3] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[0] = 0;

    /* InitializeConditions for RandomNumber: '<S84>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisAccelerometer_a_seeds[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_gr[0] = tseed;
    Mainframe_DW.NextOutput_mb[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_gr[0]) * Mainframe_P.WhiteNoise_StdDev +
      Mainframe_P.WhiteNoise_Mean;

    /* InitializeConditions for SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[0] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_a;

    /* InitializeConditions for SecondOrderIntegrator: '<S88>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[4] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[1] = 0;

    /* InitializeConditions for RandomNumber: '<S84>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisAccelerometer_a_seeds[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_gr[1] = tseed;
    Mainframe_DW.NextOutput_mb[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_gr[1]) * Mainframe_P.WhiteNoise_StdDev +
      Mainframe_P.WhiteNoise_Mean;

    /* InitializeConditions for SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[1] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_a;

    /* InitializeConditions for SecondOrderIntegrator: '<S88>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[5] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[2] = 0;

    /* InitializeConditions for RandomNumber: '<S84>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisAccelerometer_a_seeds[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_gr[2] = tseed;
    Mainframe_DW.NextOutput_mb[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_gr[2]) * Mainframe_P.WhiteNoise_StdDev +
      Mainframe_P.WhiteNoise_Mean;

    /* InitializeConditions for SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[2] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_a;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[3] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_n;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[0] = 0;

    /* InitializeConditions for RandomNumber: '<S98>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisGyroscope_g_seeds[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_i[0] = tseed;
    Mainframe_DW.NextOutput_i[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_i[0]) * Mainframe_P.WhiteNoise_StdDev_f +
      Mainframe_P.WhiteNoise_Mean_i;

    /* InitializeConditions for SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[4] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_n;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[1] = 0;

    /* InitializeConditions for RandomNumber: '<S98>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisGyroscope_g_seeds[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_i[1] = tseed;
    Mainframe_DW.NextOutput_i[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_i[1]) * Mainframe_P.WhiteNoise_StdDev_f +
      Mainframe_P.WhiteNoise_Mean_i;

    /* InitializeConditions for SecondOrderIntegrator: '<S100>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[5] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_n;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[2] = 0;

    /* InitializeConditions for RandomNumber: '<S98>/White Noise' */
    tmp = floor(Mainframe_P.ThreeaxisGyroscope_g_seeds[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + t) << 16U) + t) + i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else {
      if (tseed > 2147483646U) {
        tseed = 2147483646U;
      }
    }

    Mainframe_DW.RandSeed_i[2] = tseed;
    Mainframe_DW.NextOutput_i[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_i[2]) * Mainframe_P.WhiteNoise_StdDev_f +
      Mainframe_P.WhiteNoise_Mean_i;

    /* InitializeConditions for Integrator: '<S151>/Integrator' */
    Mainframe_X.Integrator_CSTATE = Mainframe_P.Rudder_d_siB_0;

    /* InitializeConditions for Integrator: '<S152>/Integrator' */
    Mainframe_X.Integrator_CSTATE_g = Mainframe_P.Rudder1_d_siB_0;

    /* InitializeConditions for Integrator: '<S153>/Integrator' */
    Mainframe_X.Integrator_CSTATE_f = Mainframe_P.Rudder2_d_siB_0;

    /* InitializeConditions for Integrator: '<S154>/Integrator' */
    Mainframe_X.Integrator_CSTATE_o = Mainframe_P.Rudder3_d_siB_0;

    /* InitializeConditions for Derivative: '<S185>/Derivative1' */
    Mainframe_DW.TimeStampA = (rtInf);
    Mainframe_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<S185>/Derivative' */
    Mainframe_DW.TimeStampA_i = (rtInf);
    Mainframe_DW.TimeStampB_c = (rtInf);

    /* SystemInitialize for Outport: '<S68>/States' */
    Mainframe_B.vBIB[0] = Mainframe_P.States_Y0.Translation_States.u_mDs;
    Mainframe_B.vBIB[1] = Mainframe_P.States_Y0.Translation_States.v_mDs;
    Mainframe_B.vBIB[2] = Mainframe_P.States_Y0.Translation_States.w_mDs;
    Mainframe_B.x_d[10] = Mainframe_P.States_Y0.Rotation_States.p_radDs;
    Mainframe_B.x_d[11] = Mainframe_P.States_Y0.Rotation_States.q_radDs;
    Mainframe_B.x_d[12] = Mainframe_P.States_Y0.Rotation_States.r_radDs;
    Mainframe_B.aBIB[0] =
      Mainframe_P.States_Y0.Translation_States_Dot.u_dot_mDs2;
    Mainframe_B.aBIB[1] =
      Mainframe_P.States_Y0.Translation_States_Dot.v_dot_mDs2;
    Mainframe_B.aBIB[2] =
      Mainframe_P.States_Y0.Translation_States_Dot.w_dot_mDs2;
    Mainframe_B.d_wBIB[0] =
      Mainframe_P.States_Y0.Rotation_States_Dot.p_dot_radDs2;
    Mainframe_B.d_wBIB[1] =
      Mainframe_P.States_Y0.Rotation_States_Dot.q_dot_radDs2;
    Mainframe_B.d_wBIB[2] =
      Mainframe_P.States_Y0.Rotation_States_Dot.r_dot_radDs2;
    Mainframe_B.ComplextoRealImag[0] =
      Mainframe_P.States_Y0.Attitude_States.ATT_Euler.Phi_rad;
    Mainframe_B.ComplextoRealImag[1] =
      Mainframe_P.States_Y0.Attitude_States.ATT_Euler.Theta_rad;
    Mainframe_B.ComplextoRealImag[2] =
      Mainframe_P.States_Y0.Attitude_States.ATT_Euler.Psi_rad;
    Mainframe_B.q0 =
      Mainframe_P.States_Y0.Attitude_States.ATT_Quaternions.quat_0;
    Mainframe_B.q1 =
      Mainframe_P.States_Y0.Attitude_States.ATT_Quaternions.quat_1;
    Mainframe_B.q2 =
      Mainframe_P.States_Y0.Attitude_States.ATT_Quaternions.quat_2;
    Mainframe_B.q3 =
      Mainframe_P.States_Y0.Attitude_States.ATT_Quaternions.quat_3;
    Mainframe_B.x_d[0] = Mainframe_P.States_Y0.POS_NED.POS_x_NED_m;
    Mainframe_B.x_d[1] = Mainframe_P.States_Y0.POS_NED.POS_y_NED_m;
    Mainframe_B.x_d[2] = Mainframe_P.States_Y0.POS_NED.POS_z_NED_m;
    Mainframe_B.Saturation_j[0] = Mainframe_P.States_Y0.IMU.accelerometer.accX;
    Mainframe_B.Saturation_j[1] = Mainframe_P.States_Y0.IMU.accelerometer.accY;
    Mainframe_B.Saturation_j[2] = Mainframe_P.States_Y0.IMU.accelerometer.accZ;
    Mainframe_B.Saturation_je[0] = Mainframe_P.States_Y0.IMU.gyro.gyroX;
    Mainframe_B.Saturation_je[1] = Mainframe_P.States_Y0.IMU.gyro.gyroY;
    Mainframe_B.Saturation_je[2] = Mainframe_P.States_Y0.IMU.gyro.gyroZ;

    /* End of SystemInitialize for SubSystem: '<S7>/Subsystem' */

    /* SystemInitialize for Triggered SubSystem: '<S58>/Enabled Subsystem' */
    /* SystemInitialize for Outport: '<S59>/Out1' */
    for (i = 0; i < 75; i++) {
      Mainframe_B.In1[i] = Mainframe_P.Out1_Y0;
    }

    /* End of SystemInitialize for Outport: '<S59>/Out1' */
    /* End of SystemInitialize for SubSystem: '<S58>/Enabled Subsystem' */

    /* SystemInitialize for Triggered SubSystem: '<Root>/Enabled Subsystem1' */
    /* SystemInitialize for Outport: '<S3>/CalibrationTime' */
    Mainframe_B.DigitalClock = Mainframe_P.CalibrationTime_Y0;

    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem1' */

    /* SystemInitialize for Triggered SubSystem: '<S1>/Enabled Subsystem1' */
    Mainframe_EnabledSubsystem1_Init(&Mainframe_B.EnabledSubsystem1,
      &Mainframe_P.EnabledSubsystem1);

    /* End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem1' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(Mainframe_M)) {
      rtmSetFirstInitCond(Mainframe_M, 0);
    }
  }
}

/* Model terminate function */
void Mainframe_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<S58>/Packet Output' */

  /* S-Function Block: <S58>/Packet Output */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Mainframe_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Mainframe_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Mainframe_initialize();
}

void MdlTerminate(void)
{
  Mainframe_terminate();
}

/* Registration function */
RT_MODEL_Mainframe_T *Mainframe(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Mainframe_P.Rudder_dd_siB_max = rtInf;
  Mainframe_P.Rudder1_dd_siB_max = rtInf;
  Mainframe_P.Rudder2_dd_siB_max = rtInf;
  Mainframe_P.Rudder3_dd_siB_max = rtInf;
  Mainframe_P.Rudder_dd_siB_min = rtMinusInf;
  Mainframe_P.Rudder1_dd_siB_min = rtMinusInf;
  Mainframe_P.Rudder2_dd_siB_min = rtMinusInf;
  Mainframe_P.Rudder3_dd_siB_min = rtMinusInf;
  Mainframe_P.Saturation1_UpperSat = rtInf;
  Mainframe_P.Saturation_UpperSat_p = rtInf;
  Mainframe_P.Saturation_UpperSat_h = rtInf;
  Mainframe_P.Saturation_UpperSat_pr = rtInf;
  Mainframe_P.Saturation_UpperSat_k = rtInf;
  Mainframe_P.Saturation_UpperSat_l = rtInf;
  Mainframe_P.Saturation_UpperSat_g = rtInf;
  Mainframe_P.Saturation_UpperSat_j[0] = rtInf;
  Mainframe_P.Saturation_UpperSat_j[1] = rtInf;
  Mainframe_P.Saturation_UpperSat_j[2] = rtInf;
  Mainframe_P.Saturation_LowerSat_p[0] = rtMinusInf;
  Mainframe_P.Saturation_LowerSat_p[1] = rtMinusInf;
  Mainframe_P.Saturation_LowerSat_p[2] = rtMinusInf;
  Mainframe_P.Saturation_UpperSat_pp[0] = rtInf;
  Mainframe_P.Saturation_UpperSat_pp[1] = rtInf;
  Mainframe_P.Saturation_UpperSat_pp[2] = rtInf;
  Mainframe_P.Saturation_LowerSat_ga[0] = rtMinusInf;
  Mainframe_P.Saturation_LowerSat_ga[1] = rtMinusInf;
  Mainframe_P.Saturation_LowerSat_ga[2] = rtMinusInf;
  Mainframe_P.Saturation_UpperSat_m[0] = rtInf;
  Mainframe_P.Saturation_UpperSat_m[1] = rtInf;
  Mainframe_P.Saturation_UpperSat_m[2] = rtInf;
  Mainframe_P.Saturation_LowerSat_e1[0] = rtMinusInf;
  Mainframe_P.Saturation_LowerSat_e1[1] = rtMinusInf;
  Mainframe_P.Saturation_LowerSat_e1[2] = rtMinusInf;
  Mainframe_P.Saturation_UpperSat_jb[0] = rtInf;
  Mainframe_P.Saturation_UpperSat_jb[1] = rtInf;
  Mainframe_P.Saturation_UpperSat_jb[2] = rtInf;
  Mainframe_P.Saturation_LowerSat_h[0] = rtMinusInf;
  Mainframe_P.Saturation_LowerSat_h[1] = rtMinusInf;
  Mainframe_P.Saturation_LowerSat_h[2] = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)Mainframe_M, 0,
                sizeof(RT_MODEL_Mainframe_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Mainframe_M->solverInfo,
                          &Mainframe_M->Timing.simTimeStep);
    rtsiSetTPtr(&Mainframe_M->solverInfo, &rtmGetTPtr(Mainframe_M));
    rtsiSetStepSizePtr(&Mainframe_M->solverInfo, &Mainframe_M->Timing.stepSize0);
    rtsiSetdXPtr(&Mainframe_M->solverInfo, &Mainframe_M->derivs);
    rtsiSetContStatesPtr(&Mainframe_M->solverInfo, (real_T **)
                         &Mainframe_M->contStates);
    rtsiSetNumContStatesPtr(&Mainframe_M->solverInfo,
      &Mainframe_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Mainframe_M->solverInfo,
      &Mainframe_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Mainframe_M->solverInfo,
      &Mainframe_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Mainframe_M->solverInfo,
      &Mainframe_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Mainframe_M->solverInfo, (&rtmGetErrorStatus
      (Mainframe_M)));
    rtsiSetRTModelPtr(&Mainframe_M->solverInfo, Mainframe_M);
  }

  rtsiSetSimTimeStep(&Mainframe_M->solverInfo, MAJOR_TIME_STEP);
  Mainframe_M->intgData.y = Mainframe_M->odeY;
  Mainframe_M->intgData.f[0] = Mainframe_M->odeF[0];
  Mainframe_M->intgData.f[1] = Mainframe_M->odeF[1];
  Mainframe_M->intgData.f[2] = Mainframe_M->odeF[2];
  Mainframe_M->contStates = ((real_T *) &Mainframe_X);
  rtsiSetSolverData(&Mainframe_M->solverInfo, (void *)&Mainframe_M->intgData);
  rtsiSetSolverName(&Mainframe_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Mainframe_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    Mainframe_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Mainframe_M->Timing.sampleTimes = (&Mainframe_M->Timing.sampleTimesArray[0]);
    Mainframe_M->Timing.offsetTimes = (&Mainframe_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Mainframe_M->Timing.sampleTimes[0] = (0.0);
    Mainframe_M->Timing.sampleTimes[1] = (0.001);
    Mainframe_M->Timing.sampleTimes[2] = (0.01);
    Mainframe_M->Timing.sampleTimes[3] = (0.1);

    /* task offsets */
    Mainframe_M->Timing.offsetTimes[0] = (0.0);
    Mainframe_M->Timing.offsetTimes[1] = (0.0);
    Mainframe_M->Timing.offsetTimes[2] = (0.0);
    Mainframe_M->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(Mainframe_M, &Mainframe_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Mainframe_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    mdlSampleHits[3] = 1;
    Mainframe_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Mainframe_M, 50.0);
  Mainframe_M->Timing.stepSize0 = 0.001;
  Mainframe_M->Timing.stepSize1 = 0.001;
  Mainframe_M->Timing.stepSize2 = 0.01;
  Mainframe_M->Timing.stepSize3 = 0.1;
  rtmSetFirstInitCond(Mainframe_M, 1);

  /* External mode info */
  Mainframe_M->Sizes.checksums[0] = (1338055871U);
  Mainframe_M->Sizes.checksums[1] = (713334091U);
  Mainframe_M->Sizes.checksums[2] = (3727939429U);
  Mainframe_M->Sizes.checksums[3] = (1253909183U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[59];
    Mainframe_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &Mainframe_DW.EnabledSubsystem1.EnabledSubsystem1_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&Mainframe_DW.EnabledSubsystem1_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&Mainframe_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[24] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[25] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[28] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[30] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[31] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[32] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[33] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[34] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[36] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[39] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[40] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[41] = (sysRanDType *)&Mainframe_DW.q_R0R_SubsysRanBC;
    systemRan[42] = (sysRanDType *)&Mainframe_DW.q_R1R_SubsysRanBC;
    systemRan[43] = (sysRanDType *)&Mainframe_DW.q_R2R_SubsysRanBC;
    systemRan[44] = (sysRanDType *)&Mainframe_DW.q_R3R_SubsysRanBC;
    systemRan[45] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[46] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[47] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[48] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[49] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[50] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[51] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[52] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[53] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[54] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[55] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[56] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[57] = (sysRanDType *)&Mainframe_DW.Subsystem_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &Mainframe_DW.EnabledSubsystem1_h.EnabledSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Mainframe_M->extModeInfo,
      &Mainframe_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Mainframe_M->extModeInfo, Mainframe_M->Sizes.checksums);
    rteiSetTPtr(Mainframe_M->extModeInfo, rtmGetTPtr(Mainframe_M));
  }

  Mainframe_M->solverInfoPtr = (&Mainframe_M->solverInfo);
  Mainframe_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Mainframe_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Mainframe_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Mainframe_M->blockIO = ((void *) &Mainframe_B);
  (void) memset(((void *) &Mainframe_B), 0,
                sizeof(B_Mainframe_T));

  /* parameters */
  Mainframe_M->defaultParam = ((real_T *)&Mainframe_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Mainframe_X;
    Mainframe_M->contStates = (x);
    (void) memset((void *)&Mainframe_X, 0,
                  sizeof(X_Mainframe_T));
  }

  /* states (dwork) */
  Mainframe_M->dwork = ((void *) &Mainframe_DW);
  (void) memset((void *)&Mainframe_DW, 0,
                sizeof(DW_Mainframe_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Mainframe_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 29;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Mainframe_M->Sizes.numContStates = (61);/* Number of continuous states */
  Mainframe_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Mainframe_M->Sizes.numY = (0);       /* Number of model outputs */
  Mainframe_M->Sizes.numU = (0);       /* Number of model inputs */
  Mainframe_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Mainframe_M->Sizes.numSampTimes = (4);/* Number of sample times */
  Mainframe_M->Sizes.numBlocks = (2109);/* Number of blocks */
  Mainframe_M->Sizes.numBlockIO = (175);/* Number of block outputs */
  Mainframe_M->Sizes.numBlockPrms = (2742);/* Sum of parameter "widths" */
  return Mainframe_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
