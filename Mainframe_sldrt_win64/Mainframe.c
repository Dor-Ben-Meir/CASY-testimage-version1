/*
 * Mainframe.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Mainframe".
 *
 * Model version              : 1.280
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Feb 18 16:40:21 2021
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
  256000.0,
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
  int_T nXc = 62;
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
 *    '<S72>/Enabled Subsystem1'
 */
void Mainframe_EnabledSubsystem1_Init(B_EnabledSubsystem1_Mainframe_T *localB,
  P_EnabledSubsystem1_Mainframe_T *localP)
{
  /* SystemInitialize for Outport: '<S31>/CalibrationTime' */
  localB->DigitalClock = localP->CalibrationTime_Y0;
}

/*
 * Output and update for trigger system:
 *    '<S1>/Enabled Subsystem1'
 *    '<S72>/Enabled Subsystem1'
 */
void Mainframe_EnabledSubsystem1(RT_MODEL_Mainframe_T * const Mainframe_M,
  boolean_T rtu_Trigger, B_EnabledSubsystem1_Mainframe_T *localB,
  DW_EnabledSubsystem1_Mainframe_T *localDW, ZCE_EnabledSubsystem1_Mainframe_T
  *localZCE)
{
  /* Outputs for Triggered SubSystem: '<S1>/Enabled Subsystem1' incorporates:
   *  TriggerPort: '<S31>/Trigger'
   */
  if (rtmIsMajorTimeStep(Mainframe_M)) {
    if (rtu_Trigger && (localZCE->EnabledSubsystem1_Trig_ZCE != POS_ZCSIG)) {
      /* DigitalClock: '<S31>/Digital Clock' */
      localB->DigitalClock = Mainframe_M->Timing.t[1];
      localDW->EnabledSubsystem1_SubsysRanBC = 4;
    }

    localZCE->EnabledSubsystem1_Trig_ZCE = rtu_Trigger;
  }

  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem1' */
}

/*
 * Output and update for atomic system:
 *    '<S153>/Limiting_Acceleration'
 *    '<S154>/Limiting_Acceleration'
 *    '<S155>/Limiting_Acceleration'
 *    '<S156>/Limiting_Acceleration'
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
 *    '<S153>/Limiting_Rate'
 *    '<S154>/Limiting_Rate'
 *    '<S155>/Limiting_Rate'
 *    '<S156>/Limiting_Rate'
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

/* Function for MATLAB Function: '<S60>/Extract Message' */
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

  /* Gain: '<S289>/Gain' incorporates:
   *  TransferFcn: '<S289>/Transfer Fcn1'
   */
  Mainframe_B.Fin_1 = (Mainframe_P.TransferFcn1_C[0] *
                       Mainframe_X.TransferFcn1_CSTATE[0] +
                       Mainframe_P.TransferFcn1_C[1] *
                       Mainframe_X.TransferFcn1_CSTATE[1]) *
    Mainframe_P.Gain_Gain_c5;

  /* Gain: '<S289>/Gain1' incorporates:
   *  TransferFcn: '<S289>/Transfer Fcn2'
   */
  Mainframe_B.Fin_2 = (Mainframe_P.TransferFcn2_C[0] *
                       Mainframe_X.TransferFcn2_CSTATE[0] +
                       Mainframe_P.TransferFcn2_C[1] *
                       Mainframe_X.TransferFcn2_CSTATE[1]) *
    Mainframe_P.Gain1_Gain_bb;

  /* Gain: '<S289>/Gain2' incorporates:
   *  TransferFcn: '<S289>/Transfer Fcn3'
   */
  Mainframe_B.Fin_3 = (Mainframe_P.TransferFcn3_C[0] *
                       Mainframe_X.TransferFcn3_CSTATE[0] +
                       Mainframe_P.TransferFcn3_C[1] *
                       Mainframe_X.TransferFcn3_CSTATE[1]) *
    Mainframe_P.Gain2_Gain_p;

  /* Gain: '<S289>/Gain3' incorporates:
   *  TransferFcn: '<S289>/Transfer Fcn4'
   */
  Mainframe_B.Fin_4 = (Mainframe_P.TransferFcn4_C[0] *
                       Mainframe_X.TransferFcn4_CSTATE[0] +
                       Mainframe_P.TransferFcn4_C[1] *
                       Mainframe_X.TransferFcn4_CSTATE[1]) *
    Mainframe_P.Gain3_Gain_l0;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S278>/Gain1' incorporates:
     *  Constant: '<S71>/Constant1'
     */
    rtb_wEIE[0] = Mainframe_P.Gain1_Gain_m2 * Mainframe_P.Constant1_Value_l2;

    /* Gain: '<S279>/Gain1' incorporates:
     *  Constant: '<S71>/Constant2'
     */
    rtb_wEIE[1] = Mainframe_P.Gain1_Gain_ove * Mainframe_P.Constant2_Value_e;

    /* Gain: '<S280>/Gain1' incorporates:
     *  Constant: '<S71>/Constant3'
     */
    rtb_wEIE[2] = Mainframe_P.Gain1_Gain_gj * Mainframe_P.Constant3_Value_m;

    /* Product: '<S281>/Product' incorporates:
     *  Constant: '<S281>/Constant7'
     */
    for (i = 0; i < 4; i++) {
      Mainframe_B.siB_cmd[i] = 0.0;
      Mainframe_B.siB_cmd[i] += Mainframe_P.Constant7_Value_ej[i] * rtb_wEIE[0];
      Mainframe_B.siB_cmd[i] += Mainframe_P.Constant7_Value_ej[i + 4] *
        rtb_wEIE[1];
      Mainframe_B.siB_cmd[i] += Mainframe_P.Constant7_Value_ej[i + 8] *
        rtb_wEIE[2];
    }

    /* End of Product: '<S281>/Product' */
  }

  /* Sum: '<S71>/Add' incorporates:
   *  SignalConversion generated from: '<S71>/Vector Concatenate'
   * */
  rtb_VectorConcatenate_hw[0] = Mainframe_B.Fin_1 + Mainframe_B.siB_cmd[0];
  rtb_VectorConcatenate_hw[1] = Mainframe_B.Fin_2 + Mainframe_B.siB_cmd[1];
  rtb_VectorConcatenate_hw[2] = Mainframe_B.Fin_3 + Mainframe_B.siB_cmd[2];
  rtb_VectorConcatenate_de = Mainframe_B.Fin_4 + Mainframe_B.siB_cmd[3];

  /* Outputs for Enabled SubSystem: '<S7>/Subsystem' incorporates:
   *  EnablePort: '<S70>/Enable'
   */
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Triggered SubSystem: '<S72>/Enabled Subsystem1' */
    /* Constant: '<S68>/One' */
    Mainframe_EnabledSubsystem1(Mainframe_M, Mainframe_P.One_Value_j,
      &Mainframe_B.EnabledSubsystem1_h, &Mainframe_DW.EnabledSubsystem1_h,
      &Mainframe_PrevZCX.EnabledSubsystem1_h);

    /* End of Outputs for SubSystem: '<S72>/Enabled Subsystem1' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      /* Constant: '<S68>/One' */
      if (Mainframe_P.One_Value_j) {
        Mainframe_DW.Subsystem_MODE = true;
      } else {
        if (Mainframe_DW.Subsystem_MODE) {
          /* Disable for Enabled SubSystem: '<S212>/q_R^0(R)' */
          Mainframe_DW.q_R0R_MODE = false;

          /* End of Disable for SubSystem: '<S212>/q_R^0(R)' */

          /* Disable for Enabled SubSystem: '<S212>/q_R^1(R)' */
          Mainframe_DW.q_R1R_MODE = false;

          /* End of Disable for SubSystem: '<S212>/q_R^1(R)' */

          /* Disable for Enabled SubSystem: '<S212>/q_R^2(R)' */
          Mainframe_DW.q_R2R_MODE = false;

          /* End of Disable for SubSystem: '<S212>/q_R^2(R)' */

          /* Disable for Enabled SubSystem: '<S212>/q_R^3(R)' */
          Mainframe_DW.q_R3R_MODE = false;

          /* End of Disable for SubSystem: '<S212>/q_R^3(R)' */
          Mainframe_DW.Subsystem_MODE = false;
        }
      }
    }
  }

  /* Clock: '<S72>/Clock' incorporates:
   *  Clock: '<S28>/Clock'
   *  Clock: '<S29>/Clock'
   *  Clock: '<S30>/Clock'
   *  Derivative: '<S187>/Derivative'
   *  Derivative: '<S187>/Derivative1'
   */
  rtb_jxi_f = Mainframe_M->Timing.t[0];
  if (Mainframe_DW.Subsystem_MODE) {
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S210>/Constant' */
      memcpy(&Mainframe_B.Constant[0], &Mainframe_P.Constant_Value_cg[0], 13U *
             sizeof(real_T));
    }

    /* Integrator: '<S240>/integration_eom' */
    for (i = 0; i < 13; i++) {
      if (Mainframe_DW.integration_eom_IWORK != 0) {
        Mainframe_X.integration_eom_CSTATE[i] = Mainframe_B.Constant[i];
      }

      Mainframe_B.x_d[i] = Mainframe_X.integration_eom_CSTATE[i];
    }

    /* End of Integrator: '<S240>/integration_eom' */

    /* Sum: '<S243>/Add' incorporates:
     *  Product: '<S243>/Product1'
     *  Product: '<S243>/Product2'
     *  Product: '<S243>/Product3'
     *  Product: '<S243>/Product4'
     */
    rtb_Switch_j = ((Mainframe_B.x_d[6] * Mainframe_B.x_d[6] + Mainframe_B.x_d[7]
                     * Mainframe_B.x_d[7]) + Mainframe_B.x_d[8] *
                    Mainframe_B.x_d[8]) + Mainframe_B.x_d[9] * Mainframe_B.x_d[9];

    /* Math: '<S243>/Math Function'
     *
     * About '<S243>/Math Function':
     *  Operator: sqrt
     */
    if (rtb_Switch_j < 0.0) {
      rtb_Switch_j = -sqrt(fabs(rtb_Switch_j));
    } else {
      rtb_Switch_j = sqrt(rtb_Switch_j);
    }

    /* End of Math: '<S243>/Math Function' */

    /* Product: '<S243>/Product' */
    rtb_Product_d = Mainframe_B.x_d[6] / rtb_Switch_j;

    /* MATLAB Function: '<S74>/MATLAB Function1' */
    rtb_q_conj[0] = -rtb_Product_d;

    /* Product: '<S243>/Product' */
    rtb_Product_b_idx_0 = rtb_Product_d;
    rtb_Product_d = Mainframe_B.x_d[7] / rtb_Switch_j;

    /* MATLAB Function: '<S74>/MATLAB Function1' */
    rtb_q_conj[1] = -rtb_Product_d;

    /* Product: '<S243>/Product' */
    rtb_Product_b_idx_1 = rtb_Product_d;
    rtb_Product_d = Mainframe_B.x_d[8] / rtb_Switch_j;

    /* MATLAB Function: '<S74>/MATLAB Function1' */
    rtb_q_conj[2] = -rtb_Product_d;

    /* Product: '<S243>/Product' */
    rtb_Product_b_idx_2 = rtb_Product_d;
    rtb_Product_d = Mainframe_B.x_d[9] / rtb_Switch_j;

    /* Gain: '<S78>/Gain' incorporates:
     *  Product: '<S78>/Product4'
     *  Product: '<S78>/Product5'
     *  Sum: '<S78>/Add2'
     */
    rtb_Product4_b_idx_2 = (rtb_q_conj[1] * rtb_Product_d - rtb_q_conj[0] *
      rtb_q_conj[2]) * Mainframe_P.Gain_Gain_iz;

    /* Saturate: '<S78>/Saturation' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Saturation_UpperSat_ph) {
      rtb_Product4_b_idx_2 = Mainframe_P.Saturation_UpperSat_ph;
    } else {
      if (rtb_Product4_b_idx_2 < Mainframe_P.Saturation_LowerSat_o) {
        rtb_Product4_b_idx_2 = Mainframe_P.Saturation_LowerSat_o;
      }
    }

    /* End of Saturate: '<S78>/Saturation' */

    /* Product: '<S78>/Product3' incorporates:
     *  Product: '<S78>/Product8'
     */
    rtb_Switch_j = rtb_q_conj[1] * rtb_q_conj[1];

    /* ComplexToRealImag: '<S78>/Complex to Real-Imag' incorporates:
     *  Constant: '<S78>/Constant'
     *  Product: '<S78>/Product'
     *  Product: '<S78>/Product1'
     *  Product: '<S78>/Product2'
     *  Product: '<S78>/Product3'
     *  Sum: '<S78>/Add'
     *  Sum: '<S78>/Add1'
     *  Trigonometry: '<S78>/Trigonometric Function'
     */
    Mainframe_B.ComplextoRealImag[0] = rt_atan2d_snf(rtb_q_conj[0] *
      rtb_Product_d + rtb_q_conj[1] * rtb_q_conj[2],
      (Mainframe_P.Constant_Value_ix - rtb_q_conj[0] * rtb_q_conj[0]) -
      rtb_Switch_j);

    /* Gain: '<S80>/1//2' */
    rtb_Product4_b_idx_3 = Mainframe_P.u2_Gain * Mainframe_B.ComplextoRealImag[0];

    /* Trigonometry: '<S80>/sincos' */
    rtb_Sum1_e[0] = sin(rtb_Product4_b_idx_3);
    rtb_IntegratorSecondOrderLimited_o2_a[0] = cos(rtb_Product4_b_idx_3);

    /* Trigonometry: '<S78>/Trigonometric Function1' */
    if (rtb_Product4_b_idx_2 > 1.0) {
      rtb_Product4_b_idx_2 = 1.0;
    } else {
      if (rtb_Product4_b_idx_2 < -1.0) {
        rtb_Product4_b_idx_2 = -1.0;
      }
    }

    /* ComplexToRealImag: '<S78>/Complex to Real-Imag' incorporates:
     *  Trigonometry: '<S78>/Trigonometric Function1'
     */
    Mainframe_B.ComplextoRealImag[1] = asin(rtb_Product4_b_idx_2);

    /* Gain: '<S80>/1//2' */
    rtb_Product4_b_idx_3 = Mainframe_P.u2_Gain * Mainframe_B.ComplextoRealImag[1];

    /* Trigonometry: '<S80>/sincos' */
    rtb_Sum1_e[1] = sin(rtb_Product4_b_idx_3);
    rtb_IntegratorSecondOrderLimited_o2_a[1] = cos(rtb_Product4_b_idx_3);

    /* ComplexToRealImag: '<S78>/Complex to Real-Imag' incorporates:
     *  Constant: '<S78>/Constant1'
     *  Product: '<S78>/Product6'
     *  Product: '<S78>/Product7'
     *  Product: '<S78>/Product9'
     *  Sum: '<S78>/Add3'
     *  Sum: '<S78>/Add4'
     *  Trigonometry: '<S78>/Trigonometric Function2'
     */
    Mainframe_B.ComplextoRealImag[2] = rt_atan2d_snf(rtb_q_conj[0] * rtb_q_conj
      [1] + rtb_q_conj[2] * rtb_Product_d, (Mainframe_P.Constant1_Value_la -
      rtb_Switch_j) - rtb_q_conj[2] * rtb_q_conj[2]);

    /* Gain: '<S80>/1//2' */
    rtb_Product4_b_idx_3 = Mainframe_P.u2_Gain * Mainframe_B.ComplextoRealImag[2];

    /* Trigonometry: '<S80>/sincos' */
    rtb_Sum1_e[2] = sin(rtb_Product4_b_idx_3);
    rtb_IntegratorSecondOrderLimited_o2_a[2] = cos(rtb_Product4_b_idx_3);

    /* Trigonometry: '<S79>/Cos2' */
    rtb_Switch_j = cos(Mainframe_B.ComplextoRealImag[1]);

    /* Gain: '<S79>/Multiply' incorporates:
     *  Product: '<S79>/Product'
     *  Trigonometry: '<S79>/Cos1'
     */
    rtb_Sum4[1] = sin(Mainframe_B.ComplextoRealImag[0]) * rtb_Switch_j *
      Mainframe_P.Multiply_Gain;

    /* Gain: '<S79>/Multiply1' incorporates:
     *  Product: '<S79>/Product1'
     *  Trigonometry: '<S79>/Cos3'
     */
    rtb_Sum4[2] = rtb_Switch_j * cos(Mainframe_B.ComplextoRealImag[0]) *
      Mainframe_P.Multiply1_Gain;

    /* Gain: '<S79>/Multiply2' incorporates:
     *  Trigonometry: '<S79>/Cos'
     */
    rtb_Sum4[0] = Mainframe_P.Multiply2_Gain * sin
      (Mainframe_B.ComplextoRealImag[1]);

    /* Fcn: '<S80>/q0' incorporates:
     *  Fcn: '<S80>/q1'
     */
    rtb_Switch_j = rtb_IntegratorSecondOrderLimited_o2_a[0] *
      rtb_IntegratorSecondOrderLimited_o2_a[1];
    q0_tmp = rtb_Sum1_e[0] * rtb_Sum1_e[1];
    Mainframe_B.q0 = rtb_Switch_j * rtb_IntegratorSecondOrderLimited_o2_a[2] +
      q0_tmp * rtb_Sum1_e[2];

    /* Fcn: '<S80>/q1' */
    Mainframe_B.q1 = rtb_Switch_j * rtb_Sum1_e[2] - q0_tmp *
      rtb_IntegratorSecondOrderLimited_o2_a[2];

    /* Fcn: '<S80>/q2' incorporates:
     *  Fcn: '<S80>/q3'
     */
    rtb_Switch_j = rtb_Sum1_e[0] * rtb_IntegratorSecondOrderLimited_o2_a[1];
    q0_tmp = rtb_IntegratorSecondOrderLimited_o2_a[0] * rtb_Sum1_e[1];
    Mainframe_B.q2 = q0_tmp * rtb_IntegratorSecondOrderLimited_o2_a[2] +
      rtb_Switch_j * rtb_Sum1_e[2];

    /* Fcn: '<S80>/q3' */
    Mainframe_B.q3 = rtb_Switch_j * rtb_IntegratorSecondOrderLimited_o2_a[2] -
      q0_tmp * rtb_Sum1_e[2];

    /* Math: '<S175>/Math Function1' incorporates:
     *  Math: '<S175>/Math Function5'
     *  Math: '<S175>/Math Function9'
     */
    q0_tmp = rtb_Product_b_idx_1 * rtb_Product_b_idx_1;

    /* Math: '<S175>/Math Function' incorporates:
     *  Math: '<S175>/Math Function4'
     *  Math: '<S175>/Math Function8'
     */
    rtb_Switch_j = rtb_Product_b_idx_0 * rtb_Product_b_idx_0;

    /* Math: '<S175>/Math Function2' incorporates:
     *  Math: '<S175>/Math Function10'
     *  Math: '<S175>/Math Function6'
     */
    rtb_Product4_b_idx_1 = rtb_Product_b_idx_2 * rtb_Product_b_idx_2;

    /* Math: '<S175>/Math Function3' incorporates:
     *  Math: '<S175>/Math Function11'
     *  Math: '<S175>/Math Function7'
     */
    rtb_Product4_b_idx_3 = rtb_Product_d * rtb_Product_d;

    /* Sum: '<S175>/Add' incorporates:
     *  Math: '<S175>/Math Function'
     *  Math: '<S175>/Math Function1'
     *  Math: '<S175>/Math Function2'
     *  Math: '<S175>/Math Function3'
     *  Sum: '<S241>/Add'
     *  Switch: '<S239>/Switch'
     */
    rtb_JMMB_tmp_6 = ((rtb_Switch_j - q0_tmp) - rtb_Product4_b_idx_1) +
      rtb_Product4_b_idx_3;
    rtb_JMMB[0] = rtb_JMMB_tmp_6;

    /* Product: '<S175>/Product' incorporates:
     *  Product: '<S175>/Product6'
     *  Product: '<S241>/Product'
     *  Product: '<S241>/Product6'
     *  Switch: '<S239>/Switch'
     */
    rtb_JMMB_tmp = rtb_Product_b_idx_0 * rtb_Product_b_idx_1;

    /* Product: '<S175>/Product1' incorporates:
     *  Product: '<S175>/Product7'
     *  Product: '<S241>/Product1'
     *  Product: '<S241>/Product7'
     *  Switch: '<S239>/Switch'
     */
    rtb_JMMB_tmp_0 = rtb_Product_b_idx_2 * rtb_Product_d;

    /* Sum: '<S175>/Add1' incorporates:
     *  Gain: '<S175>/Gain1'
     *  Gain: '<S175>/Gain2'
     *  Product: '<S175>/Product'
     *  Product: '<S175>/Product1'
     */
    rtb_JMMB[1] = rtb_JMMB_tmp * Mainframe_P.Gain1_Gain_l - rtb_JMMB_tmp_0 *
      Mainframe_P.Gain2_Gain_o;

    /* Product: '<S175>/Product8' incorporates:
     *  Product: '<S175>/Product4'
     *  Product: '<S241>/Product4'
     *  Product: '<S241>/Product8'
     *  Switch: '<S239>/Switch'
     */
    rtb_JMMB_tmp_1 = rtb_Product_b_idx_0 * rtb_Product_b_idx_2;

    /* Product: '<S175>/Product9' incorporates:
     *  Product: '<S175>/Product5'
     *  Product: '<S241>/Product5'
     *  Product: '<S241>/Product9'
     *  Switch: '<S239>/Switch'
     */
    rtb_JMMB_tmp_2 = rtb_Product_b_idx_1 * rtb_Product_d;

    /* Sum: '<S175>/Add5' incorporates:
     *  Gain: '<S175>/Gain10'
     *  Gain: '<S175>/Gain9'
     *  Product: '<S175>/Product8'
     *  Product: '<S175>/Product9'
     */
    rtb_JMMB[2] = rtb_JMMB_tmp_1 * Mainframe_P.Gain9_Gain_f + rtb_JMMB_tmp_2 *
      Mainframe_P.Gain10_Gain_o;

    /* Sum: '<S175>/Add4' incorporates:
     *  Gain: '<S175>/Gain7'
     *  Gain: '<S175>/Gain8'
     */
    rtb_JMMB[3] = rtb_JMMB_tmp * Mainframe_P.Gain7_Gain_h + rtb_JMMB_tmp_0 *
      Mainframe_P.Gain8_Gain_f;

    /* Sum: '<S175>/Add6' incorporates:
     *  Sum: '<S241>/Add6'
     *  Switch: '<S239>/Switch'
     */
    rtb_JMMB_tmp_5 = ((q0_tmp - rtb_Switch_j) - rtb_Product4_b_idx_1) +
      rtb_Product4_b_idx_3;
    rtb_JMMB[4] = rtb_JMMB_tmp_5;

    /* Product: '<S175>/Product2' incorporates:
     *  Product: '<S175>/Product10'
     *  Product: '<S241>/Product10'
     *  Product: '<S241>/Product2'
     *  Switch: '<S239>/Switch'
     */
    rtb_JMMB_tmp_3 = rtb_Product_b_idx_1 * rtb_Product_b_idx_2;

    /* Product: '<S175>/Product3' incorporates:
     *  Product: '<S175>/Product11'
     *  Product: '<S241>/Product11'
     *  Product: '<S241>/Product3'
     *  Switch: '<S239>/Switch'
     */
    rtb_JMMB_tmp_4 = rtb_Product_b_idx_0 * rtb_Product_d;

    /* Sum: '<S175>/Add2' incorporates:
     *  Gain: '<S175>/Gain3'
     *  Gain: '<S175>/Gain4'
     *  Product: '<S175>/Product2'
     *  Product: '<S175>/Product3'
     */
    rtb_JMMB[5] = rtb_JMMB_tmp_3 * Mainframe_P.Gain3_Gain_m - rtb_JMMB_tmp_4 *
      Mainframe_P.Gain4_Gain_g;

    /* Sum: '<S175>/Add3' incorporates:
     *  Gain: '<S175>/Gain5'
     *  Gain: '<S175>/Gain6'
     */
    rtb_JMMB[6] = rtb_JMMB_tmp_1 * Mainframe_P.Gain5_Gain_i - rtb_JMMB_tmp_2 *
      Mainframe_P.Gain6_Gain_e;

    /* Sum: '<S175>/Add8' incorporates:
     *  Gain: '<S175>/Gain11'
     *  Gain: '<S175>/Gain12'
     */
    rtb_JMMB[7] = rtb_JMMB_tmp_3 * Mainframe_P.Gain11_Gain_k + rtb_JMMB_tmp_4 *
      Mainframe_P.Gain12_Gain_j;

    /* Sum: '<S175>/Add7' incorporates:
     *  Sum: '<S241>/Add7'
     *  Switch: '<S239>/Switch'
     */
    q0_tmp = ((rtb_Product4_b_idx_1 - rtb_Switch_j) - q0_tmp) +
      rtb_Product4_b_idx_3;
    rtb_JMMB[8] = q0_tmp;
    for (i = 0; i < 3; i++) {
      /* Math: '<S209>/Math Function' incorporates:
       *  Math: '<S249>/Math Function'
       */
      rtb_TBI_tmp[3 * i] = rtb_JMMB[i];
      rtb_TBI_tmp[3 * i + 1] = rtb_JMMB[i + 3];
      rtb_TBI_tmp[3 * i + 2] = rtb_JMMB[i + 6];
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S185>/Constant8' */
      Mainframe_B.Constant8[0] = Mainframe_P.Constant8_Value_mc[0];
      Mainframe_B.Constant8[1] = Mainframe_P.Constant8_Value_mc[1];
      Mainframe_B.Constant8[2] = Mainframe_P.Constant8_Value_mc[2];
      Mainframe_B.Constant8[3] = Mainframe_P.Constant8_Value_mc[3];
    }

    /* Integrator: '<S185>/integration_eom' */
    if (Mainframe_DW.integration_eom_IWORK_p != 0) {
      Mainframe_X.integration_eom_CSTATE_o[0] = Mainframe_B.Constant8[0];
      Mainframe_X.integration_eom_CSTATE_o[1] = Mainframe_B.Constant8[1];
      Mainframe_X.integration_eom_CSTATE_o[2] = Mainframe_B.Constant8[2];
      Mainframe_X.integration_eom_CSTATE_o[3] = Mainframe_B.Constant8[3];
    }

    /* Sum: '<S189>/Add' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Math: '<S189>/Math Function'
     *  Math: '<S189>/Math Function1'
     *  Math: '<S189>/Math Function2'
     *  Math: '<S189>/Math Function3'
     */
    rtb_VectorConcatenate3[0] = ((Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[0] -
      Mainframe_X.integration_eom_CSTATE_o[1] *
      Mainframe_X.integration_eom_CSTATE_o[1]) -
      Mainframe_X.integration_eom_CSTATE_o[2] *
      Mainframe_X.integration_eom_CSTATE_o[2]) +
      Mainframe_X.integration_eom_CSTATE_o[3] *
      Mainframe_X.integration_eom_CSTATE_o[3];

    /* Sum: '<S189>/Add1' incorporates:
     *  Gain: '<S189>/Gain1'
     *  Gain: '<S189>/Gain2'
     *  Integrator: '<S185>/integration_eom'
     *  Product: '<S189>/Product'
     *  Product: '<S189>/Product1'
     */
    rtb_VectorConcatenate3[1] = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[1] * Mainframe_P.Gain1_Gain_mx -
      Mainframe_X.integration_eom_CSTATE_o[2] *
      Mainframe_X.integration_eom_CSTATE_o[3] * Mainframe_P.Gain2_Gain_i;

    /* Product: '<S189>/Product8' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Product: '<S189>/Product4'
     */
    rtb_lat = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[2];

    /* Product: '<S189>/Product9' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Product: '<S189>/Product5'
     */
    rtb_Sqrt_cv = Mainframe_X.integration_eom_CSTATE_o[1] *
      Mainframe_X.integration_eom_CSTATE_o[3];

    /* Sum: '<S189>/Add5' incorporates:
     *  Gain: '<S189>/Gain10'
     *  Gain: '<S189>/Gain9'
     *  Product: '<S189>/Product8'
     *  Product: '<S189>/Product9'
     */
    rtb_VectorConcatenate3[2] = rtb_lat * Mainframe_P.Gain9_Gain_fk +
      rtb_Sqrt_cv * Mainframe_P.Gain10_Gain_f;

    /* Sum: '<S189>/Add4' incorporates:
     *  Gain: '<S189>/Gain7'
     *  Gain: '<S189>/Gain8'
     *  Integrator: '<S185>/integration_eom'
     *  Product: '<S189>/Product6'
     *  Product: '<S189>/Product7'
     */
    rtb_VectorConcatenate3[3] = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[1] * Mainframe_P.Gain7_Gain_k +
      Mainframe_X.integration_eom_CSTATE_o[2] *
      Mainframe_X.integration_eom_CSTATE_o[3] * Mainframe_P.Gain8_Gain_a;

    /* Math: '<S189>/Math Function6' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Math: '<S189>/Math Function10'
     */
    rtb_Product2_l = Mainframe_X.integration_eom_CSTATE_o[2] *
      Mainframe_X.integration_eom_CSTATE_o[2];

    /* Math: '<S189>/Math Function4' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Math: '<S189>/Math Function8'
     */
    rtb_ixk_k = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[0];

    /* Math: '<S189>/Math Function5' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Math: '<S189>/Math Function9'
     */
    rtb_T_sim_glbl = Mainframe_X.integration_eom_CSTATE_o[1] *
      Mainframe_X.integration_eom_CSTATE_o[1];

    /* Math: '<S189>/Math Function7' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Math: '<S189>/Math Function11'
     */
    rtb_VectorConcatenate3_tmp_1 = Mainframe_X.integration_eom_CSTATE_o[3] *
      Mainframe_X.integration_eom_CSTATE_o[3];

    /* Sum: '<S189>/Add6' incorporates:
     *  Math: '<S189>/Math Function4'
     *  Math: '<S189>/Math Function5'
     *  Math: '<S189>/Math Function6'
     *  Math: '<S189>/Math Function7'
     */
    rtb_VectorConcatenate3[4] = ((rtb_T_sim_glbl - rtb_ixk_k) - rtb_Product2_l)
      + rtb_VectorConcatenate3_tmp_1;

    /* Product: '<S189>/Product2' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Product: '<S189>/Product10'
     */
    rtb_VectorConcatenate3_tmp = Mainframe_X.integration_eom_CSTATE_o[1] *
      Mainframe_X.integration_eom_CSTATE_o[2];

    /* Product: '<S189>/Product3' incorporates:
     *  Integrator: '<S185>/integration_eom'
     *  Product: '<S189>/Product11'
     */
    rtb_VectorConcatenate3_tmp_0 = Mainframe_X.integration_eom_CSTATE_o[0] *
      Mainframe_X.integration_eom_CSTATE_o[3];

    /* Sum: '<S189>/Add2' incorporates:
     *  Gain: '<S189>/Gain3'
     *  Gain: '<S189>/Gain4'
     *  Product: '<S189>/Product2'
     *  Product: '<S189>/Product3'
     */
    rtb_VectorConcatenate3[5] = rtb_VectorConcatenate3_tmp *
      Mainframe_P.Gain3_Gain_n - rtb_VectorConcatenate3_tmp_0 *
      Mainframe_P.Gain4_Gain_k;

    /* Sum: '<S189>/Add3' incorporates:
     *  Gain: '<S189>/Gain5'
     *  Gain: '<S189>/Gain6'
     */
    rtb_VectorConcatenate3[6] = rtb_lat * Mainframe_P.Gain5_Gain_l - rtb_Sqrt_cv
      * Mainframe_P.Gain6_Gain_d;

    /* Sum: '<S189>/Add8' incorporates:
     *  Gain: '<S189>/Gain11'
     *  Gain: '<S189>/Gain12'
     */
    rtb_VectorConcatenate3[7] = rtb_VectorConcatenate3_tmp *
      Mainframe_P.Gain11_Gain_m + rtb_VectorConcatenate3_tmp_0 *
      Mainframe_P.Gain12_Gain_o;

    /* Sum: '<S189>/Add7' */
    rtb_VectorConcatenate3[8] = ((rtb_Product2_l - rtb_ixk_k) - rtb_T_sim_glbl)
      + rtb_VectorConcatenate3_tmp_1;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Switch: '<S184>/Switch' incorporates:
       *  Constant: '<S184>/Constant7'
       *  Constant: '<S184>/Constant9'
       */
      if (Mainframe_P.Constant9_Value > Mainframe_P.Switch_Threshold) {
        Mainframe_B.wIEE[2] = Mainframe_P.Constant7_Value;

        /* SignalConversion generated from: '<S184>/Vector Concatenate' incorporates:
         *  Constant: '<S184>/Constant6'
         *  Constant: '<S184>/Constant7'
         */
        Mainframe_B.wIEE[1] = Mainframe_P.Constant6_Value;

        /* SignalConversion generated from: '<S184>/Vector Concatenate' incorporates:
         *  Constant: '<S184>/Constant6'
         */
        Mainframe_B.wIEE[0] = Mainframe_P.Constant6_Value;
      } else {
        /* SignalConversion generated from: '<S184>/Vector Concatenate1' incorporates:
         *  Constant: '<S184>/Constant8'
         */
        Mainframe_B.wIEE[2] = Mainframe_P.Constant8_Value;

        /* SignalConversion generated from: '<S184>/Vector Concatenate1' incorporates:
         *  Constant: '<S184>/Constant8'
         */
        Mainframe_B.wIEE[1] = Mainframe_P.Constant8_Value;

        /* SignalConversion generated from: '<S184>/Vector Concatenate1' incorporates:
         *  Constant: '<S184>/Constant8'
         */
        Mainframe_B.wIEE[0] = Mainframe_P.Constant8_Value;
      }

      /* End of Switch: '<S184>/Switch' */
    }

    /* Product: '<S251>/Product' */
    for (i = 0; i < 3; i++) {
      rtb_Sum1_e[i] = rtb_VectorConcatenate3[i + 6] * Mainframe_B.wIEE[2] +
        (rtb_VectorConcatenate3[i + 3] * Mainframe_B.wIEE[1] +
         rtb_VectorConcatenate3[i] * Mainframe_B.wIEE[0]);
    }

    /* End of Product: '<S251>/Product' */

    /* Sum: '<S251>/Add' incorporates:
     *  Product: '<S256>/Product2'
     *  Product: '<S256>/Product3'
     *  Product: '<S256>/Product4'
     *  Product: '<S256>/Product5'
     *  Product: '<S256>/Product6'
     *  Product: '<S256>/Product7'
     *  Sum: '<S256>/Sum'
     *  Sum: '<S256>/Sum1'
     *  Sum: '<S256>/Sum2'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[0] = Mainframe_B.x_d[3] - (rtb_Sum1_e
      [1] * Mainframe_B.x_d[2] - rtb_Sum1_e[2] * Mainframe_B.x_d[1]);
    rtb_IntegratorSecondOrderLimited_o2_a[1] = Mainframe_B.x_d[4] - (rtb_Sum1_e
      [2] * Mainframe_B.x_d[0] - rtb_Sum1_e[0] * Mainframe_B.x_d[2]);
    rtb_ixk_k = Mainframe_B.x_d[5] - (rtb_Sum1_e[0] * Mainframe_B.x_d[1] -
      rtb_Sum1_e[1] * Mainframe_B.x_d[0]);

    /* DotProduct: '<S255>/Dot Product1' */
    rtb_Product4_b_idx_3 = 0.0;
    for (i = 0; i < 3; i++) {
      /* Product: '<S249>/Product' */
      rtb_Switch_j = rtb_TBI_tmp[i + 6] * rtb_ixk_k + (rtb_TBI_tmp[i + 3] *
        rtb_IntegratorSecondOrderLimited_o2_a[1] + rtb_TBI_tmp[i] *
        rtb_IntegratorSecondOrderLimited_o2_a[0]);

      /* DotProduct: '<S255>/Dot Product1' */
      rtb_Product4_b_idx_3 += rtb_Switch_j * rtb_Switch_j;

      /* Product: '<S249>/Product' */
      rtb_u2[i] = rtb_Switch_j;
    }

    /* Math: '<S255>/Math Function1' incorporates:
     *  DotProduct: '<S255>/Dot Product1'
     *
     * About '<S255>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product4_b_idx_3 < 0.0) {
      rtb_Switch_j = -sqrt(fabs(rtb_Product4_b_idx_3));
    } else {
      rtb_Switch_j = sqrt(rtb_Product4_b_idx_3);
    }

    /* End of Math: '<S255>/Math Function1' */

    /* Switch: '<S252>/Switch' incorporates:
     *  Constant: '<S252>/Constant'
     */
    if (rtb_Switch_j != 0.0) {
      /* SignalConversion generated from: '<S252>/Vector Concatenate' */
      rtb_Product4_b_idx_3 = rtb_Switch_j;

      /* SignalConversion generated from: '<S252>/Vector Concatenate' */
      rtb_Product4_b_idx_2 = rtb_u2[2];

      /* SignalConversion generated from: '<S252>/Vector Concatenate' */
      rtb_Product4_b_idx_1 = rtb_u2[1];

      /* SignalConversion generated from: '<S252>/Vector Concatenate' */
      rtb_Switch_j = rtb_u2[0];
    } else {
      rtb_Switch_j = Mainframe_P.Constant_Value_fh[0];
      rtb_Product4_b_idx_1 = Mainframe_P.Constant_Value_fh[1];
      rtb_Product4_b_idx_2 = Mainframe_P.Constant_Value_fh[2];
      rtb_Product4_b_idx_3 = Mainframe_P.Constant_Value_fh[3];
    }

    /* End of Switch: '<S252>/Switch' */

    /* Trigonometry: '<S252>/Trigonometric Function' */
    rtb_Switch_j = rt_atan2d_snf(rtb_Product4_b_idx_2, rtb_Switch_j);

    /* Saturate: '<S114>/Saturation2' */
    if (rtb_Switch_j > Mainframe_P.Saturation2_UpperSat) {
      rtb_Switch_j = Mainframe_P.Saturation2_UpperSat;
    } else {
      if (rtb_Switch_j < Mainframe_P.Saturation2_LowerSat) {
        rtb_Switch_j = Mainframe_P.Saturation2_LowerSat;
      }
    }

    /* End of Saturate: '<S114>/Saturation2' */

    /* Product: '<S252>/Divide' */
    rtb_Product4_b_idx_2 = rtb_Product4_b_idx_1 / rtb_Product4_b_idx_3;

    /* Trigonometry: '<S252>/Trigonometric Function1' */
    if (rtb_Product4_b_idx_2 > 1.0) {
      rtb_Product4_b_idx_2 = 1.0;
    } else {
      if (rtb_Product4_b_idx_2 < -1.0) {
        rtb_Product4_b_idx_2 = -1.0;
      }
    }

    rtb_Product4_b_idx_1 = asin(rtb_Product4_b_idx_2);

    /* End of Trigonometry: '<S252>/Trigonometric Function1' */

    /* Saturate: '<S114>/Saturation3' */
    if (rtb_Product4_b_idx_1 > Mainframe_P.Saturation3_UpperSat) {
      rtb_Product4_b_idx_1 = Mainframe_P.Saturation3_UpperSat;
    } else {
      if (rtb_Product4_b_idx_1 < Mainframe_P.Saturation3_LowerSat) {
        rtb_Product4_b_idx_1 = Mainframe_P.Saturation3_LowerSat;
      }
    }

    /* End of Saturate: '<S114>/Saturation3' */

    /* Integrator: '<S153>/Integrator1' */
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
      /* Signum: '<S153>/Sign' incorporates:
       *  Constant: '<S105>/Constant7'
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
      Mainframe_B.Gain3 = Mainframe_P.Rudder_unc_bl * rtb_T_sim_glbl;
    }

    /* Sum: '<S153>/Add2' incorporates:
     *  Constant: '<S153>/Constant'
     *  Gain: '<S153>/Gain1'
     *  Integrator: '<S153>/Integrator1'
     */
    rtb_Product4_b_idx_2 = (Mainframe_P.Rudder_unc_scale *
      Mainframe_X.Integrator1_CSTATE + Mainframe_P.Rudder_unc_off) +
      Mainframe_B.Gain3;

    /* Saturate: '<S153>/Saturation1' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Rudder_siB_max) {
      rtb_siB = Mainframe_P.Rudder_siB_max;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Rudder_siB_min) {
      rtb_siB = Mainframe_P.Rudder_siB_min;
    } else {
      rtb_siB = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S153>/Saturation1' */

    /* Integrator: '<S154>/Integrator1' */
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
      /* Signum: '<S154>/Sign' incorporates:
       *  Constant: '<S105>/Constant7'
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
      Mainframe_B.Gain3_g = Mainframe_P.Rudder1_unc_bl * rtb_T_sim_glbl;
    }

    /* Sum: '<S154>/Add2' incorporates:
     *  Constant: '<S154>/Constant'
     *  Gain: '<S154>/Gain1'
     *  Integrator: '<S154>/Integrator1'
     */
    rtb_Product4_b_idx_2 = (Mainframe_P.Rudder1_unc_scale *
      Mainframe_X.Integrator1_CSTATE_n + Mainframe_P.Rudder1_unc_off) +
      Mainframe_B.Gain3_g;

    /* Saturate: '<S154>/Saturation1' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Rudder1_siB_max) {
      rtb_siB_a = Mainframe_P.Rudder1_siB_max;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Rudder1_siB_min) {
      rtb_siB_a = Mainframe_P.Rudder1_siB_min;
    } else {
      rtb_siB_a = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S154>/Saturation1' */

    /* Integrator: '<S155>/Integrator1' */
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
      /* Signum: '<S155>/Sign' incorporates:
       *  Constant: '<S105>/Constant7'
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

      /* End of Signum: '<S155>/Sign' */

      /* Gain: '<S155>/Gain3' */
      Mainframe_B.Gain3_o = Mainframe_P.Rudder2_unc_bl * rtb_T_sim_glbl;
    }

    /* Sum: '<S155>/Add2' incorporates:
     *  Constant: '<S155>/Constant'
     *  Gain: '<S155>/Gain1'
     *  Integrator: '<S155>/Integrator1'
     */
    rtb_Product4_b_idx_2 = (Mainframe_P.Rudder2_unc_scale *
      Mainframe_X.Integrator1_CSTATE_k + Mainframe_P.Rudder2_unc_off) +
      Mainframe_B.Gain3_o;

    /* Saturate: '<S155>/Saturation1' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Rudder2_siB_max) {
      rtb_siB_e = Mainframe_P.Rudder2_siB_max;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Rudder2_siB_min) {
      rtb_siB_e = Mainframe_P.Rudder2_siB_min;
    } else {
      rtb_siB_e = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S155>/Saturation1' */

    /* Integrator: '<S156>/Integrator1' */
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
      /* Signum: '<S156>/Sign' incorporates:
       *  Constant: '<S105>/Constant7'
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

      /* End of Signum: '<S156>/Sign' */

      /* Gain: '<S156>/Gain3' */
      Mainframe_B.Gain3_i = Mainframe_P.Rudder3_unc_bl * rtb_T_sim_glbl;
    }

    /* Sum: '<S156>/Add2' incorporates:
     *  Constant: '<S156>/Constant'
     *  Gain: '<S156>/Gain1'
     *  Integrator: '<S156>/Integrator1'
     */
    rtb_Product4_b_idx_2 = (Mainframe_P.Rudder3_unc_scale *
      Mainframe_X.Integrator1_CSTATE_f + Mainframe_P.Rudder3_unc_off) +
      Mainframe_B.Gain3_i;

    /* Saturate: '<S156>/Saturation1' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Rudder3_siB_max) {
      rtb_siB_i = Mainframe_P.Rudder3_siB_max;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Rudder3_siB_min) {
      rtb_siB_i = Mainframe_P.Rudder3_siB_min;
    } else {
      rtb_siB_i = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S156>/Saturation1' */

    /* Product: '<S157>/Product' incorporates:
     *  Constant: '<S157>/Constant8'
     *  SignalConversion generated from: '<S105>/Vector Concatenate1'
     * */
    for (i = 0; i < 3; i++) {
      rtb_Product4_b_idx_3 = Mainframe_P.Constant8_Value_d[i + 9] * rtb_siB_i +
        (Mainframe_P.Constant8_Value_d[i + 6] * rtb_siB_e +
         (Mainframe_P.Constant8_Value_d[i + 3] * rtb_siB_a +
          Mainframe_P.Constant8_Value_d[i] * rtb_siB));
      rtb_afinB[i] = rtb_Product4_b_idx_3;
    }

    /* End of Product: '<S157>/Product' */

    /* DotProduct: '<S254>/Dot Product1' */
    rtb_Product4_b_idx_3 = (rtb_u2[0] * rtb_u2[0] + rtb_u2[1] * rtb_u2[1]) +
      rtb_u2[2] * rtb_u2[2];

    /* Math: '<S254>/Math Function1' incorporates:
     *  DotProduct: '<S254>/Dot Product1'
     *
     * About '<S254>/Math Function1':
     *  Operator: sqrt
     */
    if (rtb_Product4_b_idx_3 < 0.0) {
      rtb_Product4_b_idx_3 = -sqrt(fabs(rtb_Product4_b_idx_3));
    } else {
      rtb_Product4_b_idx_3 = sqrt(rtb_Product4_b_idx_3);
    }

    /* End of Math: '<S254>/Math Function1' */
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S150>/Subtract1' incorporates:
       *  Constant: '<S150>/Tmp_norm_msl'
       *  Constant: '<S72>/deviation_Tmp'
       */
      Mainframe_B.Tmp_ref = Mainframe_P.deviation_Tmp_Value +
        Mainframe_P.Tmp_norm_msl_Value;

      /* Constant: '<S211>/Constant' */
      Mainframe_B.VectorConcatenate1[0] = Mainframe_P.Constant_Value_ja;

      /* Constant: '<S211>/Constant2' */
      Mainframe_B.VectorConcatenate1[1] = Mainframe_P.Constant2_Value_px;

      /* Product: '<S217>/Product' incorporates:
       *  Constant: '<S215>/c_flat'
       *  Constant: '<S215>/c_rsma'
       *  Constant: '<S217>/Constant'
       *  Sum: '<S217>/Subtract'
       */
      Mainframe_B.Product_n = (Mainframe_P.Constant_Value_ae -
        Mainframe_P.c_flat_Value_j) * Mainframe_P.c_rsma_Value_n;

      /* Product: '<S217>/Product5' */
      rtb_TrigonometricFunction1_j = Mainframe_B.Product_n *
        Mainframe_B.Product_n;

      /* Product: '<S217>/Divide' incorporates:
       *  Constant: '<S215>/c_rsma'
       *  Product: '<S217>/Product4'
       *  Sum: '<S217>/Subtract2'
       */
      Mainframe_B.Divide = (Mainframe_P.c_rsma_Value_n *
                            Mainframe_P.c_rsma_Value_n -
                            rtb_TrigonometricFunction1_j) /
        rtb_TrigonometricFunction1_j;

      /* Product: '<S217>/Product3' incorporates:
       *  Constant: '<S215>/c_flat'
       *  Product: '<S216>/Product3'
       */
      rtb_Product4_b_idx_2 = Mainframe_P.c_flat_Value_j *
        Mainframe_P.c_flat_Value_j;

      /* Sum: '<S217>/Subtract1' incorporates:
       *  Constant: '<S215>/c_flat'
       *  Gain: '<S217>/Gain'
       *  Product: '<S217>/Product3'
       */
      Mainframe_B.Subtract1 = Mainframe_P.Gain_Gain_he *
        Mainframe_P.c_flat_Value_j - rtb_Product4_b_idx_2;

      /* Sum: '<S216>/Subtract' incorporates:
       *  Constant: '<S215>/c_flat'
       *  Gain: '<S216>/Gain'
       */
      Mainframe_B.Subtract = Mainframe_P.Gain_Gain_pd *
        Mainframe_P.c_flat_Value_j - rtb_Product4_b_idx_2;
    }

    /* Switch: '<S211>/Switch' incorporates:
     *  Constant: '<S211>/Constant1'
     */
    if (Mainframe_P.Constant1_Value_hf > Mainframe_P.Switch_Threshold_f) {
      /* Gain: '<S211>/Gain' */
      Mainframe_B.VectorConcatenate1[2] = Mainframe_P.Gain_Gain_im *
        Mainframe_B.x_d[2];
      Mainframe_B.Switch[0] = Mainframe_B.VectorConcatenate1[0];
      Mainframe_B.Switch[1] = Mainframe_B.VectorConcatenate1[1];
      Mainframe_B.Switch[2] = Mainframe_B.VectorConcatenate1[2];
    } else {
      /* Product: '<S211>/Product' incorporates:
       *  Math: '<S211>/Math Function'
       */
      for (i = 0; i < 3; i++) {
        rtb_IntegratorSecondOrderLimited_o2_a[i] = rtb_VectorConcatenate3[3 * i
          + 2] * Mainframe_B.x_d[2] + (rtb_VectorConcatenate3[3 * i + 1] *
          Mainframe_B.x_d[1] + rtb_VectorConcatenate3[3 * i] * Mainframe_B.x_d[0]);
      }

      /* End of Product: '<S211>/Product' */

      /* Sqrt: '<S217>/Sqrt' incorporates:
       *  Product: '<S217>/Product1'
       *  Product: '<S217>/Product2'
       *  Sqrt: '<S216>/Sqrt'
       *  Sum: '<S217>/Add'
       */
      rtb_Product4_b_idx_2 = sqrt(rtb_IntegratorSecondOrderLimited_o2_a[0] *
        rtb_IntegratorSecondOrderLimited_o2_a[0] +
        rtb_IntegratorSecondOrderLimited_o2_a[1] *
        rtb_IntegratorSecondOrderLimited_o2_a[1]);

      /* Trigonometry: '<S217>/Trigonometric Function' incorporates:
       *  Constant: '<S215>/c_rsma'
       *  Product: '<S217>/Divide1'
       *  Product: '<S217>/Product6'
       *  Product: '<S217>/Product7'
       *  Sqrt: '<S217>/Sqrt'
       */
      rtb_Sqrt_c = atan(rtb_IntegratorSecondOrderLimited_o2_a[2] *
                        Mainframe_P.c_rsma_Value_n / (rtb_Product4_b_idx_2 *
        Mainframe_B.Product_n));

      /* Trigonometry: '<S217>/Trigonometric Function3' */
      rtb_lat = cos(rtb_Sqrt_c);

      /* Trigonometry: '<S217>/Trigonometric Function2' */
      rtb_Sqrt_c = sin(rtb_Sqrt_c);

      /* Trigonometry: '<S217>/Trigonometric Function1' incorporates:
       *  Constant: '<S215>/c_rsma'
       *  Product: '<S217>/Divide2'
       *  Product: '<S217>/Product10'
       *  Product: '<S217>/Product11'
       *  Product: '<S217>/Product8'
       *  Product: '<S217>/Product9'
       *  Sqrt: '<S217>/Sqrt'
       *  Sum: '<S217>/Add1'
       *  Sum: '<S217>/Subtract3'
       */
      rtb_lat = atan((rtb_Sqrt_c * rtb_Sqrt_c * rtb_Sqrt_c * (Mainframe_B.Divide
        * Mainframe_B.Product_n) + rtb_IntegratorSecondOrderLimited_o2_a[2]) /
                     (rtb_Product4_b_idx_2 - rtb_lat * rtb_lat * rtb_lat *
                      (Mainframe_B.Subtract1 * Mainframe_P.c_rsma_Value_n)));

      /* Trigonometry: '<S216>/Trigonometric Function' */
      rtb_Sqrt_c = sin(rtb_lat);

      /* Sqrt: '<S216>/Sqrt1' incorporates:
       *  Constant: '<S216>/Constant'
       *  Product: '<S216>/Product5'
       *  Sum: '<S216>/Subtract1'
       */
      rtb_Sqrt_c = sqrt(Mainframe_P.Constant_Value_cc - rtb_Sqrt_c * rtb_Sqrt_c *
                        Mainframe_B.Subtract);

      /* Sum: '<S216>/Sum' incorporates:
       *  Constant: '<S215>/c_rsma'
       *  Product: '<S216>/Product'
       *  Product: '<S216>/Product4'
       *  Trigonometry: '<S216>/cos(latGD)'
       */
      Mainframe_B.Switch[2] = rtb_Product4_b_idx_2 / cos(rtb_lat) -
        Mainframe_P.c_rsma_Value_n / rtb_Sqrt_c;

      /* SignalConversion generated from: '<S211>/Vector Concatenate' */
      Mainframe_B.Switch[1] = rtb_lat;

      /* Trigonometry: '<S215>/Trigonometric Function1' */
      Mainframe_B.Switch[0] = rt_atan2d_snf
        (rtb_IntegratorSecondOrderLimited_o2_a[1],
         rtb_IntegratorSecondOrderLimited_o2_a[0]);
    }

    /* End of Switch: '<S211>/Switch' */

    /* Product: '<S148>/Divide' incorporates:
     *  Constant: '<S148>/mean_earth_radius'
     *  Sum: '<S148>/Add'
     */
    rtb_ixk_k = Mainframe_B.Switch[2] / (Mainframe_B.Switch[2] +
      Mainframe_P.geopot_height_mean_earth_radius) *
      Mainframe_P.geopot_height_mean_earth_radius;

    /* Saturate: '<S138>/Saturation' */
    if (rtb_ixk_k > Mainframe_P.Saturation_UpperSat_e) {
      rtb_ixk_k = Mainframe_P.Saturation_UpperSat_e;
    } else {
      if (rtb_ixk_k < Mainframe_P.Saturation_LowerSat_oe) {
        rtb_ixk_k = Mainframe_P.Saturation_LowerSat_oe;
      }
    }

    /* End of Saturate: '<S138>/Saturation' */

    /* Sum: '<S151>/Subtract' incorporates:
     *  Constant: '<S150>/geopotential_height_ref'
     *  Sum: '<S152>/Subtract'
     */
    rtb_Product4_b_idx_2 = rtb_ixk_k - Mainframe_P.geopotential_height_ref_Value;

    /* Sum: '<S152>/Add' incorporates:
     *  Constant: '<S152>/Constant1'
     *  Constant: '<S152>/Tmp_gradient_tropo'
     *  Product: '<S152>/Divide'
     */
    rtb_ixk_k = rtb_Product4_b_idx_2 / Mainframe_B.Tmp_ref *
      Mainframe_P.Tmp_gradient_tropo_Value_p + Mainframe_P.Constant1_Value_pz;

    /* Math: '<S152>/Math Function' incorporates:
     *  Constant: '<S152>/pressure_exponent'
     */
    if ((rtb_ixk_k < 0.0) && (Mainframe_P.pressure_exponent_Value > floor
         (Mainframe_P.pressure_exponent_Value))) {
      rtb_ixk_k = -rt_powd_snf(-rtb_ixk_k, Mainframe_P.pressure_exponent_Value);
    } else {
      rtb_ixk_k = rt_powd_snf(rtb_ixk_k, Mainframe_P.pressure_exponent_Value);
    }

    /* End of Math: '<S152>/Math Function' */
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Sum: '<S150>/Subtract2' incorporates:
       *  Constant: '<S150>/pa_norm_msl'
       *  Constant: '<S72>/deviation_pa_QFH'
       */
      Mainframe_B.pa_ref = Mainframe_P.deviation_pa_QFH_Value +
        Mainframe_P.pa_norm_msl_Value;
    }

    /* Product: '<S117>/Product2' incorporates:
     *  Constant: '<S117>/Constant2'
     *  Constant: '<S147>/specific_gas_constant'
     *  Constant: '<S151>/Tmp_gradient_tropo'
     *  Constant: '<S250>/Constant'
     *  Math: '<S250>/Math Function1'
     *  Product: '<S147>/Divide'
     *  Product: '<S151>/Product'
     *  Product: '<S152>/Product'
     *  Product: '<S250>/Product1'
     *  Sum: '<S151>/Add'
     *  Sum: '<S151>/Subtract'
     */
    rtb_Product4_b_idx_2 = 1.0 / (Mainframe_B.Tmp_ref + rtb_Product4_b_idx_2 *
      Mainframe_P.Tmp_gradient_tropo_Value) * (rtb_ixk_k * Mainframe_B.pa_ref) /
      Mainframe_P.specific_gas_constant_Value * (rtb_Product4_b_idx_3 *
      rtb_Product4_b_idx_3 * Mainframe_P.Constant_Value_e) *
      Mainframe_P.Constant2_Value_jd;

    /* Product: '<S117>/Product' incorporates:
     *  Constant: '<S121>/Constant'
     *  Constant: '<S122>/Constant'
     *  Constant: '<S123>/Constant'
     *  Gain: '<S121>/Gain2'
     *  Gain: '<S121>/Gain3'
     *  Gain: '<S121>/Gain4'
     *  Gain: '<S121>/Gain5'
     *  Gain: '<S121>/Gain6'
     *  Gain: '<S121>/Gain7'
     *  Gain: '<S122>/Gain'
     *  Gain: '<S122>/Gain1'
     *  Gain: '<S123>/Gain'
     *  Gain: '<S123>/Gain1'
     *  Product: '<S121>/Product'
     *  Product: '<S121>/Product2'
     *  Product: '<S121>/Product3'
     *  Product: '<S121>/Product4'
     *  Sum: '<S121>/Sum'
     *  Sum: '<S121>/Sum1'
     *  Sum: '<S121>/Sum3'
     *  Sum: '<S122>/Sum'
     *  Sum: '<S123>/Sum'
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
      /* Switch: '<S128>/Switch1' incorporates:
       *  Constant: '<S128>/Constant'
       *  Constant: '<S128>/Constant2'
       *  Constant: '<S129>/c_flat'
       *  Constant: '<S129>/c_rsma'
       *  Constant: '<S130>/Constant'
       *  Gain: '<S128>/Gain'
       *  Gain: '<S130>/Gain'
       *  Product: '<S130>/Product'
       *  Product: '<S130>/Product4'
       *  Product: '<S130>/Product5'
       *  Sqrt: '<S130>/Sqrt1'
       *  Sum: '<S130>/Subtract'
       *  Sum: '<S130>/Subtract1'
       *  Sum: '<S130>/Sum'
       *  Trigonometry: '<S130>/cos(latGD)'
       */
      if (Mainframe_P.Constant2_Value_jj > Mainframe_P.Switch1_Threshold) {
        Mainframe_B.hBE_0 = Mainframe_P.Gain_Gain_a *
          Mainframe_P.Constant_Value_es[2];
      } else {
        /* Sqrt: '<S131>/Sqrt' incorporates:
         *  Constant: '<S128>/Constant'
         *  Product: '<S131>/Product1'
         *  Product: '<S131>/Product2'
         *  Sqrt: '<S130>/Sqrt'
         *  Sum: '<S131>/Add'
         */
        rtb_lat = sqrt(Mainframe_P.Constant_Value_es[0] *
                       Mainframe_P.Constant_Value_es[0] +
                       Mainframe_P.Constant_Value_es[1] *
                       Mainframe_P.Constant_Value_es[1]);

        /* Product: '<S131>/Product' incorporates:
         *  Constant: '<S129>/c_flat'
         *  Constant: '<S129>/c_rsma'
         *  Constant: '<S131>/Constant'
         *  Sum: '<S131>/Subtract'
         */
        rtb_Sqrt_c = (Mainframe_P.Constant_Value - Mainframe_P.c_flat_Value) *
          Mainframe_P.c_rsma_Value;

        /* Trigonometry: '<S131>/Trigonometric Function' incorporates:
         *  Constant: '<S128>/Constant'
         *  Constant: '<S129>/c_rsma'
         *  Product: '<S131>/Divide1'
         *  Product: '<S131>/Product6'
         *  Product: '<S131>/Product7'
         *  Sqrt: '<S131>/Sqrt'
         */
        rtb_Sqrt_cv = atan(Mainframe_P.Constant_Value_es[2] *
                           Mainframe_P.c_rsma_Value / (rtb_lat * rtb_Sqrt_c));

        /* Trigonometry: '<S131>/Trigonometric Function3' */
        rtb_Product2_l = cos(rtb_Sqrt_cv);

        /* Product: '<S131>/Product9' */
        rtb_ixk_k = rtb_Product2_l * rtb_Product2_l * rtb_Product2_l;

        /* Trigonometry: '<S131>/Trigonometric Function2' */
        rtb_Sqrt_cv = sin(rtb_Sqrt_cv);

        /* Product: '<S131>/Product5' */
        rtb_Product2_l = rtb_Sqrt_c * rtb_Sqrt_c;

        /* Product: '<S131>/Product10' incorporates:
         *  Constant: '<S129>/c_rsma'
         *  Product: '<S131>/Divide'
         *  Product: '<S131>/Product4'
         *  Product: '<S131>/Product8'
         *  Sum: '<S131>/Subtract2'
         */
        rtb_Sqrt_c = (Mainframe_P.c_rsma_Value * Mainframe_P.c_rsma_Value -
                      rtb_Product2_l) / rtb_Product2_l * rtb_Sqrt_c *
          (rtb_Sqrt_cv * rtb_Sqrt_cv * rtb_Sqrt_cv);

        /* Sum: '<S131>/Add1' incorporates:
         *  Constant: '<S128>/Constant'
         */
        rtb_Sqrt_c += Mainframe_P.Constant_Value_es[2];

        /* Product: '<S131>/Product3' incorporates:
         *  Constant: '<S129>/c_flat'
         *  Product: '<S130>/Product3'
         */
        rtb_T_sim_glbl = Mainframe_P.c_flat_Value * Mainframe_P.c_flat_Value;

        /* Trigonometry: '<S131>/Trigonometric Function1' incorporates:
         *  Constant: '<S129>/c_flat'
         *  Constant: '<S129>/c_rsma'
         *  Gain: '<S131>/Gain'
         *  Product: '<S131>/Divide2'
         *  Product: '<S131>/Product11'
         *  Product: '<S131>/Product3'
         *  Sqrt: '<S131>/Sqrt'
         *  Sum: '<S131>/Subtract1'
         *  Sum: '<S131>/Subtract3'
         */
        rtb_Product2_l = atan(rtb_Sqrt_c / (rtb_lat - (Mainframe_P.Gain_Gain_b *
          Mainframe_P.c_flat_Value - rtb_T_sim_glbl) * Mainframe_P.c_rsma_Value *
          rtb_ixk_k));

        /* Trigonometry: '<S130>/Trigonometric Function' */
        rtb_Sqrt_cv = sin(rtb_Product2_l);
        Mainframe_B.hBE_0 = rtb_lat / cos(rtb_Product2_l) -
          Mainframe_P.c_rsma_Value / sqrt(Mainframe_P.Constant_Value_l -
          (Mainframe_P.Gain_Gain * Mainframe_P.c_flat_Value - rtb_T_sim_glbl) *
          (rtb_Sqrt_cv * rtb_Sqrt_cv));
      }

      /* End of Switch: '<S128>/Switch1' */

      /* SignalConversion generated from: '<S126>/Vector Concatenate' incorporates:
       *  Constant: '<S126>/Constant3'
       */
      Mainframe_B.VectorConcatenate[0] = Mainframe_P.Constant3_Value;

      /* SignalConversion generated from: '<S126>/Vector Concatenate' incorporates:
       *  Constant: '<S126>/Constant3'
       */
      Mainframe_B.VectorConcatenate[1] = Mainframe_P.Constant3_Value;

      /* SignalConversion generated from: '<S126>/Vector Concatenate' incorporates:
       *  Constant: '<S126>/Constant3'
       */
      Mainframe_B.VectorConcatenate[2] = Mainframe_P.Constant3_Value;

      /* Constant: '<S186>/Constant8' */
      Mainframe_B.Constant8_a[0] = Mainframe_P.Constant8_Value_el[0];
      Mainframe_B.Constant8_a[1] = Mainframe_P.Constant8_Value_el[1];
      Mainframe_B.Constant8_a[2] = Mainframe_P.Constant8_Value_el[2];
      Mainframe_B.Constant8_a[3] = Mainframe_P.Constant8_Value_el[3];
    }

    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S126>/Constant1'
     *  Sum: '<S126>/Subtract'
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

    /* End of Switch: '<S126>/Switch' */

    /* Integrator: '<S186>/integration_eom' */
    if (Mainframe_DW.integration_eom_IWORK_g != 0) {
      Mainframe_X.integration_eom_CSTATE_k[0] = Mainframe_B.Constant8_a[0];
      Mainframe_X.integration_eom_CSTATE_k[1] = Mainframe_B.Constant8_a[1];
      Mainframe_X.integration_eom_CSTATE_k[2] = Mainframe_B.Constant8_a[2];
      Mainframe_X.integration_eom_CSTATE_k[3] = Mainframe_B.Constant8_a[3];
    }

    /* Sum: '<S180>/Add' incorporates:
     *  Constant: '<S180>/Q_1'
     *  Constant: '<S180>/Q_2'
     *  Constant: '<S180>/Q_3'
     *  Constant: '<S180>/Q_4'
     *  Integrator: '<S185>/integration_eom'
     *  Product: '<S180>/Product'
     *  Product: '<S180>/Product1'
     *  Product: '<S180>/Product2'
     *  Product: '<S180>/Product3'
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

    /* End of Sum: '<S180>/Add' */

    /* Product: '<S180>/Product8' incorporates:
     *  Integrator: '<S186>/integration_eom'
     */
    for (i = 0; i < 4; i++) {
      rtb_ixk_k = tmp[i + 12] * Mainframe_X.integration_eom_CSTATE_k[3] + (tmp[i
        + 8] * Mainframe_X.integration_eom_CSTATE_k[2] + (tmp[i + 4] *
        Mainframe_X.integration_eom_CSTATE_k[1] + tmp[i] *
        Mainframe_X.integration_eom_CSTATE_k[0]));
      rtb_q_conj[i] = rtb_ixk_k;
    }

    /* End of Product: '<S180>/Product8' */

    /* Sum: '<S183>/Add' incorporates:
     *  Product: '<S183>/Product1'
     *  Product: '<S183>/Product2'
     *  Product: '<S183>/Product3'
     *  Product: '<S183>/Product4'
     */
    rtb_ixk_k = ((rtb_q_conj[0] * rtb_q_conj[0] + rtb_q_conj[1] * rtb_q_conj[1])
                 + rtb_q_conj[2] * rtb_q_conj[2]) + rtb_q_conj[3] * rtb_q_conj[3];

    /* Math: '<S183>/Math Function'
     *
     * About '<S183>/Math Function':
     *  Operator: sqrt
     */
    if (rtb_ixk_k < 0.0) {
      rtb_ixk_k = -sqrt(fabs(rtb_ixk_k));
    } else {
      rtb_ixk_k = sqrt(rtb_ixk_k);
    }

    /* End of Math: '<S183>/Math Function' */

    /* Product: '<S183>/Product' */
    rtb_q_conj[0] /= rtb_ixk_k;
    rtb_q_conj[1] /= rtb_ixk_k;
    rtb_q_conj[2] /= rtb_ixk_k;
    rtb_ixk_k = rtb_q_conj[3] / rtb_ixk_k;

    /* Switch: '<S180>/Switch' incorporates:
     *  Constant: '<S180>/Constant'
     *  Constant: '<S180>/Constant1'
     */
    if (rtb_ixk_k >= Mainframe_P.Switch_Threshold_i) {
      rtb_Sqrt_cv = Mainframe_P.Constant_Value_p0;
    } else {
      rtb_Sqrt_cv = Mainframe_P.Constant1_Value_jf;
    }

    /* End of Switch: '<S180>/Switch' */

    /* Product: '<S180>/Product4' */
    rtb_q_conj[0] *= rtb_Sqrt_cv;
    rtb_q_conj[1] *= rtb_Sqrt_cv;
    rtb_q_conj[2] *= rtb_Sqrt_cv;
    rtb_ixk_k *= rtb_Sqrt_cv;

    /* Gain: '<S177>/Gain1' */
    rtb_d_qEI[0] = Mainframe_P.Gain1_Gain_n * rtb_q_conj[0];
    rtb_d_qEI[1] = Mainframe_P.Gain1_Gain_n * rtb_q_conj[1];
    rtb_d_qEI[2] = Mainframe_P.Gain1_Gain_n * rtb_q_conj[2];

    /* Sum: '<S178>/Add' incorporates:
     *  Constant: '<S178>/Q_1'
     *  Constant: '<S178>/Q_2'
     *  Constant: '<S178>/Q_3'
     *  Constant: '<S178>/Q_4'
     *  Product: '<S178>/Product'
     *  Product: '<S178>/Product1'
     *  Product: '<S178>/Product2'
     *  Product: '<S178>/Product3'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_g[i] * rtb_d_qEI[0] +
                 Mainframe_P.Q_2_Value_h[i] * rtb_d_qEI[1]) +
                Mainframe_P.Q_3_Value_h3[i] * rtb_d_qEI[2]) +
        Mainframe_P.Q_4_Value_e[i] * rtb_ixk_k;
    }

    /* End of Sum: '<S178>/Add' */

    /* Product: '<S178>/Product8' */
    for (i = 0; i < 4; i++) {
      rtb_Sqrt_c = tmp[i + 12] * rtb_Product_d + (tmp[i + 8] *
        rtb_Product_b_idx_2 + (tmp[i + 4] * rtb_Product_b_idx_1 + tmp[i] *
        rtb_Product_b_idx_0));
      rtb_d_qEI[i] = rtb_Sqrt_c;
    }

    /* End of Product: '<S178>/Product8' */

    /* Sum: '<S181>/Add' incorporates:
     *  Product: '<S181>/Product1'
     *  Product: '<S181>/Product2'
     *  Product: '<S181>/Product3'
     *  Product: '<S181>/Product4'
     */
    rtb_Sqrt_cv = ((rtb_d_qEI[0] * rtb_d_qEI[0] + rtb_d_qEI[1] * rtb_d_qEI[1]) +
                   rtb_d_qEI[2] * rtb_d_qEI[2]) + rtb_d_qEI[3] * rtb_d_qEI[3];

    /* Math: '<S181>/Math Function'
     *
     * About '<S181>/Math Function':
     *  Operator: sqrt
     */
    if (rtb_Sqrt_cv < 0.0) {
      rtb_Sqrt_cv = -sqrt(fabs(rtb_Sqrt_cv));
    } else {
      rtb_Sqrt_cv = sqrt(rtb_Sqrt_cv);
    }

    /* End of Math: '<S181>/Math Function' */

    /* Product: '<S181>/Product' */
    rtb_d_qEI[0] /= rtb_Sqrt_cv;
    rtb_d_qEI[1] /= rtb_Sqrt_cv;
    rtb_d_qEI[2] /= rtb_Sqrt_cv;
    rtb_Sqrt_c = rtb_d_qEI[3] / rtb_Sqrt_cv;

    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S178>/Constant'
     *  Constant: '<S178>/Constant1'
     */
    if (rtb_Sqrt_c >= Mainframe_P.Switch_Threshold_a2) {
      rtb_Sqrt_cv = Mainframe_P.Constant_Value_az;
    } else {
      rtb_Sqrt_cv = Mainframe_P.Constant1_Value_hk;
    }

    /* End of Switch: '<S178>/Switch' */

    /* Product: '<S178>/Product4' */
    rtb_d_qEI[0] *= rtb_Sqrt_cv;
    rtb_d_qEI[1] *= rtb_Sqrt_cv;
    rtb_d_qEI[2] *= rtb_Sqrt_cv;
    rtb_Sqrt_c *= rtb_Sqrt_cv;

    /* Math: '<S176>/Math Function1' incorporates:
     *  Math: '<S176>/Math Function5'
     *  Math: '<S176>/Math Function9'
     */
    rtb_lat = rtb_d_qEI[1] * rtb_d_qEI[1];

    /* Math: '<S176>/Math Function' incorporates:
     *  Math: '<S176>/Math Function4'
     *  Math: '<S176>/Math Function8'
     */
    rtb_Sqrt_cv = rtb_d_qEI[0] * rtb_d_qEI[0];

    /* Math: '<S176>/Math Function2' incorporates:
     *  Math: '<S176>/Math Function10'
     *  Math: '<S176>/Math Function6'
     */
    rtb_Product2_l = rtb_d_qEI[2] * rtb_d_qEI[2];

    /* Math: '<S176>/Math Function3' incorporates:
     *  Math: '<S176>/Math Function11'
     *  Math: '<S176>/Math Function7'
     */
    rtb_ixk_k = rtb_Sqrt_c * rtb_Sqrt_c;

    /* Sum: '<S176>/Add' incorporates:
     *  Math: '<S176>/Math Function'
     *  Math: '<S176>/Math Function1'
     *  Math: '<S176>/Math Function2'
     *  Math: '<S176>/Math Function3'
     */
    rtb_VectorConcatenate3[0] = ((rtb_Sqrt_cv - rtb_lat) - rtb_Product2_l) +
      rtb_ixk_k;

    /* Product: '<S176>/Product' incorporates:
     *  Product: '<S176>/Product6'
     */
    rtb_T_sim_glbl = rtb_d_qEI[0] * rtb_d_qEI[1];

    /* Product: '<S176>/Product1' incorporates:
     *  Product: '<S176>/Product7'
     */
    rtb_VectorConcatenate3_tmp_1 = rtb_d_qEI[2] * rtb_Sqrt_c;

    /* Sum: '<S176>/Add1' incorporates:
     *  Gain: '<S176>/Gain1'
     *  Gain: '<S176>/Gain2'
     *  Product: '<S176>/Product'
     *  Product: '<S176>/Product1'
     */
    rtb_VectorConcatenate3[1] = rtb_T_sim_glbl * Mainframe_P.Gain1_Gain_b3 -
      rtb_VectorConcatenate3_tmp_1 * Mainframe_P.Gain2_Gain_fo;

    /* Product: '<S176>/Product8' incorporates:
     *  Product: '<S176>/Product4'
     */
    rtb_VectorConcatenate3_tmp = rtb_d_qEI[0] * rtb_d_qEI[2];

    /* Product: '<S176>/Product9' incorporates:
     *  Product: '<S176>/Product5'
     */
    rtb_VectorConcatenate3_tmp_0 = rtb_d_qEI[1] * rtb_Sqrt_c;

    /* Sum: '<S176>/Add5' incorporates:
     *  Gain: '<S176>/Gain10'
     *  Gain: '<S176>/Gain9'
     *  Product: '<S176>/Product8'
     *  Product: '<S176>/Product9'
     */
    rtb_VectorConcatenate3[2] = rtb_VectorConcatenate3_tmp *
      Mainframe_P.Gain9_Gain_e + rtb_VectorConcatenate3_tmp_0 *
      Mainframe_P.Gain10_Gain_i;

    /* Sum: '<S176>/Add4' incorporates:
     *  Gain: '<S176>/Gain7'
     *  Gain: '<S176>/Gain8'
     */
    rtb_VectorConcatenate3[3] = rtb_T_sim_glbl * Mainframe_P.Gain7_Gain_n +
      rtb_VectorConcatenate3_tmp_1 * Mainframe_P.Gain8_Gain_o;

    /* Sum: '<S176>/Add6' */
    rtb_VectorConcatenate3[4] = ((rtb_lat - rtb_Sqrt_cv) - rtb_Product2_l) +
      rtb_ixk_k;

    /* Product: '<S176>/Product2' incorporates:
     *  Product: '<S176>/Product10'
     */
    rtb_T_sim_glbl = rtb_d_qEI[1] * rtb_d_qEI[2];

    /* Product: '<S176>/Product3' incorporates:
     *  Product: '<S176>/Product11'
     */
    rtb_VectorConcatenate3_tmp_1 = rtb_d_qEI[0] * rtb_Sqrt_c;

    /* Sum: '<S176>/Add2' incorporates:
     *  Gain: '<S176>/Gain3'
     *  Gain: '<S176>/Gain4'
     *  Product: '<S176>/Product2'
     *  Product: '<S176>/Product3'
     */
    rtb_VectorConcatenate3[5] = rtb_T_sim_glbl * Mainframe_P.Gain3_Gain_i -
      rtb_VectorConcatenate3_tmp_1 * Mainframe_P.Gain4_Gain_m;

    /* Sum: '<S176>/Add3' incorporates:
     *  Gain: '<S176>/Gain5'
     *  Gain: '<S176>/Gain6'
     */
    rtb_VectorConcatenate3[6] = rtb_VectorConcatenate3_tmp *
      Mainframe_P.Gain5_Gain_c - rtb_VectorConcatenate3_tmp_0 *
      Mainframe_P.Gain6_Gain_j;

    /* Sum: '<S176>/Add8' incorporates:
     *  Gain: '<S176>/Gain11'
     *  Gain: '<S176>/Gain12'
     */
    rtb_VectorConcatenate3[7] = rtb_T_sim_glbl * Mainframe_P.Gain11_Gain_l +
      rtb_VectorConcatenate3_tmp_1 * Mainframe_P.Gain12_Gain_b;

    /* Sum: '<S176>/Add7' */
    rtb_VectorConcatenate3[8] = ((rtb_Product2_l - rtb_Sqrt_cv) - rtb_lat) +
      rtb_ixk_k;

    /* Saturate: '<S104>/Saturation' */
    if (Mainframe_B.Switch[2] > Mainframe_P.Saturation_UpperSat_l) {
      rtb_Sqrt_cv = Mainframe_P.Saturation_UpperSat_l;
    } else if (Mainframe_B.Switch[2] < Mainframe_P.Saturation_LowerSat_f) {
      rtb_Sqrt_cv = Mainframe_P.Saturation_LowerSat_f;
    } else {
      rtb_Sqrt_cv = Mainframe_B.Switch[2];
    }

    /* End of Saturate: '<S104>/Saturation' */

    /* Trigonometry: '<S145>/Trigonometric Function' incorporates:
     *  Switch: '<S187>/Switch'
     *  Trigonometry: '<S143>/Trigonometric Function2'
     *  Trigonometry: '<S187>/Trigonometric Function'
     */
    rtb_lat = sin(Mainframe_B.Switch[1]);
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Product: '<S146>/Divide' incorporates:
       *  Constant: '<S145>/WGS84 Semi-major Axis, [m]'
       *  Constant: '<S145>/WGS84 Semi-minor Axis, [m]'
       *  Sum: '<S146>/Add'
       */
      rtb_TrigonometricFunction1_j = (Mainframe_P.WGS84SemimajorAxism_Value -
        Mainframe_P.WGS84SemiminorAxism_Value) /
        Mainframe_P.WGS84SemimajorAxism_Value;

      /* Product: '<S146>/Divide1' incorporates:
       *  Constant: '<S146>/a2'
       *  Sum: '<S146>/Add1'
       */
      rtb_TrigonometricFunction1_j *= Mainframe_P.a2_Value -
        rtb_TrigonometricFunction1_j;

      /* Sqrt: '<S146>/Sqrt' */
      rtb_TrigonometricFunction1_j = sqrt(rtb_TrigonometricFunction1_j);

      /* Product: '<S145>/Divide' */
      Mainframe_B.e2 = rtb_TrigonometricFunction1_j *
        rtb_TrigonometricFunction1_j;

      /* Sum: '<S143>/Add1' incorporates:
       *  Constant: '<S143>/Constant'
       *  Product: '<S143>/Divide2'
       */
      Mainframe_B.Add1 = Mainframe_P.Constant_Value_kc -
        rtb_TrigonometricFunction1_j * rtb_TrigonometricFunction1_j;
    }

    /* Product: '<S145>/Divide3' incorporates:
     *  Constant: '<S145>/WGS84 Semi-major Axis, [m]'
     *  Constant: '<S145>/a3'
     *  Product: '<S145>/Divide1'
     *  Product: '<S145>/Divide2'
     *  Sqrt: '<S145>/Sqrt'
     *  Sum: '<S145>/Add2'
     *  Trigonometry: '<S145>/Trigonometric Function'
     */
    rtb_Product2_l = 1.0 / sqrt(Mainframe_P.a3_Value - rtb_lat * rtb_lat *
      Mainframe_B.e2) * Mainframe_P.WGS84SemimajorAxism_Value;

    /* Sum: '<S143>/Add3' */
    rtb_ixk_k = rtb_Sqrt_cv + rtb_Product2_l;

    /* Trigonometry: '<S143>/Trigonometric Function3' incorporates:
     *  Switch: '<S187>/Switch'
     *  Trigonometry: '<S187>/Trigonometric Function1'
     */
    rtb_Sqrt_c = cos(Mainframe_B.Switch[1]);

    /* Trigonometry: '<S143>/Trigonometric Function1' incorporates:
     *  MATLAB Function: '<S137>/WGS84_Gravity_Implementation'
     */
    rtb_IntegratorSecondOrderLimited_o2_h_tmp = cos(Mainframe_B.Switch[0]);

    /* SignalConversion generated from: '<S144>/ SFunction ' incorporates:
     *  MATLAB Function: '<S137>/WGS84_Gravity_Implementation'
     *  Product: '<S143>/Divide'
     *  Trigonometry: '<S143>/Trigonometric Function1'
     *  Trigonometry: '<S143>/Trigonometric Function3'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[0] = rtb_ixk_k *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp * rtb_Sqrt_c;

    /* Trigonometry: '<S143>/Trigonometric Function' incorporates:
     *  MATLAB Function: '<S137>/WGS84_Gravity_Implementation'
     */
    rtb_IntegratorSecondOrderLimited_o2_h_tmp_0 = sin(Mainframe_B.Switch[0]);

    /* SignalConversion generated from: '<S144>/ SFunction ' incorporates:
     *  MATLAB Function: '<S137>/WGS84_Gravity_Implementation'
     *  Product: '<S143>/Divide1'
     *  Product: '<S143>/Divide3'
     *  Product: '<S143>/Divide4'
     *  Sum: '<S143>/Add2'
     *  Trigonometry: '<S143>/Trigonometric Function'
     *  Trigonometry: '<S143>/Trigonometric Function3'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[1] = rtb_ixk_k *
      rtb_IntegratorSecondOrderLimited_o2_h_tmp_0 * rtb_Sqrt_c;
    rtb_IntegratorSecondOrderLimited_o2_a[2] = (rtb_Product2_l *
      Mainframe_B.Add1 + rtb_Sqrt_cv) * rtb_lat;

    /* MATLAB Function: '<S137>/WGS84_Gravity_Implementation' */
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
      /* Switch: '<S167>/Switch1' incorporates:
       *  Constant: '<S167>/Constant'
       *  Constant: '<S167>/Constant2'
       *  Constant: '<S168>/c_flat'
       *  Constant: '<S168>/c_rsma'
       *  Constant: '<S169>/Constant'
       *  Gain: '<S167>/Gain'
       *  Gain: '<S169>/Gain'
       *  Product: '<S169>/Product'
       *  Product: '<S169>/Product4'
       *  Product: '<S169>/Product5'
       *  Sqrt: '<S169>/Sqrt1'
       *  Sum: '<S169>/Subtract'
       *  Sum: '<S169>/Subtract1'
       *  Sum: '<S169>/Sum'
       *  Trigonometry: '<S169>/cos(latGD)'
       */
      if (Mainframe_P.Constant2_Value_d > Mainframe_P.Switch1_Threshold_g) {
        Mainframe_B.hBE_0_i = Mainframe_P.Gain_Gain_bh *
          Mainframe_P.Constant_Value_bh[2];
      } else {
        /* Sqrt: '<S170>/Sqrt' incorporates:
         *  Constant: '<S167>/Constant'
         *  Product: '<S170>/Product1'
         *  Product: '<S170>/Product2'
         *  Sqrt: '<S169>/Sqrt'
         *  Sum: '<S170>/Add'
         */
        rtb_TrigonometricFunction1_j = sqrt(Mainframe_P.Constant_Value_bh[0] *
          Mainframe_P.Constant_Value_bh[0] + Mainframe_P.Constant_Value_bh[1] *
          Mainframe_P.Constant_Value_bh[1]);

        /* Product: '<S170>/Product' incorporates:
         *  Constant: '<S168>/c_flat'
         *  Constant: '<S168>/c_rsma'
         *  Constant: '<S170>/Constant'
         *  Sum: '<S170>/Subtract'
         */
        rtb_Product2_l = (Mainframe_P.Constant_Value_lt -
                          Mainframe_P.c_flat_Value_h) *
          Mainframe_P.c_rsma_Value_a;

        /* Trigonometry: '<S170>/Trigonometric Function' incorporates:
         *  Constant: '<S167>/Constant'
         *  Constant: '<S168>/c_rsma'
         *  Product: '<S170>/Divide1'
         *  Product: '<S170>/Product6'
         *  Product: '<S170>/Product7'
         *  Sqrt: '<S170>/Sqrt'
         */
        rtb_ixk_k = atan(Mainframe_P.Constant_Value_bh[2] *
                         Mainframe_P.c_rsma_Value_a /
                         (rtb_TrigonometricFunction1_j * rtb_Product2_l));

        /* Trigonometry: '<S170>/Trigonometric Function3' */
        beta = cos(rtb_ixk_k);

        /* Product: '<S170>/Product9' */
        rtb_Product9_k = beta * beta * beta;

        /* Trigonometry: '<S170>/Trigonometric Function2' */
        rtb_ixk_k = sin(rtb_ixk_k);

        /* Product: '<S170>/Product5' */
        beta = rtb_Product2_l * rtb_Product2_l;

        /* Product: '<S170>/Product10' incorporates:
         *  Constant: '<S168>/c_rsma'
         *  Product: '<S170>/Divide'
         *  Product: '<S170>/Product4'
         *  Product: '<S170>/Product8'
         *  Sum: '<S170>/Subtract2'
         */
        rtb_Product2_l = (Mainframe_P.c_rsma_Value_a *
                          Mainframe_P.c_rsma_Value_a - beta) / beta *
          rtb_Product2_l * (rtb_ixk_k * rtb_ixk_k * rtb_ixk_k);

        /* Sum: '<S170>/Add1' incorporates:
         *  Constant: '<S167>/Constant'
         */
        rtb_Product2_l += Mainframe_P.Constant_Value_bh[2];

        /* Product: '<S170>/Product3' incorporates:
         *  Constant: '<S168>/c_flat'
         *  Product: '<S169>/Product3'
         */
        rtb_T_sim_glbl = Mainframe_P.c_flat_Value_h * Mainframe_P.c_flat_Value_h;

        /* Trigonometry: '<S170>/Trigonometric Function1' incorporates:
         *  Constant: '<S168>/c_flat'
         *  Constant: '<S168>/c_rsma'
         *  Gain: '<S170>/Gain'
         *  Product: '<S170>/Divide2'
         *  Product: '<S170>/Product11'
         *  Product: '<S170>/Product3'
         *  Sqrt: '<S170>/Sqrt'
         *  Sum: '<S170>/Subtract1'
         *  Sum: '<S170>/Subtract3'
         */
        beta = atan(rtb_Product2_l / (rtb_TrigonometricFunction1_j -
          (Mainframe_P.Gain_Gain_l * Mainframe_P.c_flat_Value_h - rtb_T_sim_glbl)
          * Mainframe_P.c_rsma_Value_a * rtb_Product9_k));

        /* Trigonometry: '<S169>/Trigonometric Function' */
        rtb_ixk_k = sin(beta);
        Mainframe_B.hBE_0_i = rtb_TrigonometricFunction1_j / cos(beta) -
          Mainframe_P.c_rsma_Value_a / sqrt(Mainframe_P.Constant_Value_b -
          (Mainframe_P.Gain_Gain_ab * Mainframe_P.c_flat_Value_h -
           rtb_T_sim_glbl) * (rtb_ixk_k * rtb_ixk_k));
      }

      /* End of Switch: '<S167>/Switch1' */

      /* SignalConversion generated from: '<S166>/Vector Concatenate' incorporates:
       *  Constant: '<S166>/Constant3'
       */
      Mainframe_B.VectorConcatenate_g[0] = Mainframe_P.Constant3_Value_l;

      /* SignalConversion generated from: '<S166>/Vector Concatenate' incorporates:
       *  Constant: '<S166>/Constant3'
       */
      Mainframe_B.VectorConcatenate_g[1] = Mainframe_P.Constant3_Value_l;

      /* SignalConversion generated from: '<S166>/Vector Concatenate' incorporates:
       *  Constant: '<S166>/Constant3'
       */
      Mainframe_B.VectorConcatenate_g[2] = Mainframe_P.Constant3_Value_l;
    }

    /* Switch: '<S166>/Switch' incorporates:
     *  Constant: '<S166>/Constant1'
     *  Sum: '<S166>/Subtract'
     */
    if ((Mainframe_B.Switch[2] + Mainframe_P.Constant1_Value_o) -
        Mainframe_B.hBE_0_i > Mainframe_P.Switch_Threshold_o) {
      /* Sqrt: '<S139>/Sqrt' incorporates:
       *  DotProduct: '<S139>/Dot Product'
       */
      rtb_IntegratorSecondOrderLimited_o2_a[2] = sqrt((rtb_u2[0] * rtb_u2[0] +
        rtb_u2[1] * rtb_u2[1]) + rtb_u2[2] * rtb_u2[2]);

      /* SignalConversion generated from: '<S139>/Vector Concatenate' incorporates:
       *  Constant: '<S139>/Constant1'
       */
      rtb_IntegratorSecondOrderLimited_o2_a[1] = Mainframe_P.Constant1_Value_b4;

      /* SignalConversion generated from: '<S139>/Vector Concatenate' incorporates:
       *  Constant: '<S139>/Constant1'
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

    /* End of Switch: '<S166>/Switch' */

    /* Sum: '<S113>/Subtract' incorporates:
     *  Clock: '<S72>/Clock'
     *  Constant: '<S72>/Constant6'
     *  Sum: '<S196>/Subtract'
     *  Sum: '<S72>/Add'
     */
    rtb_T_sim_glbl = (rtb_jxi_f - Mainframe_B.EnabledSubsystem1_h.DigitalClock)
      - Mainframe_P.Constant6_Value_c;
    rtb_TrigonometricFunction1_j = rtb_T_sim_glbl;

    /* Switch: '<S258>/Switch' incorporates:
     *  Constant: '<S258>/Constant'
     *  Sum: '<S113>/Subtract'
     */
    if (!(rtb_T_sim_glbl > Mainframe_P.Switch_Threshold_op)) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Constant_Value_n;
    }

    /* End of Switch: '<S258>/Switch' */

    /* Switch: '<S258>/Switch1' incorporates:
     *  Lookup_n-D: '<S258>/1-D Lookup Table'
     */
    if (rtb_TrigonometricFunction1_j > Mainframe_P.Switch1_Threshold_j) {
      /* Saturate: '<S258>/Saturation' */
      if (rtb_TrigonometricFunction1_j > Mainframe_P.Saturation_UpperSat_d) {
        rtb_TrigonometricFunction1_j = Mainframe_P.Saturation_UpperSat_d;
      } else {
        if (rtb_TrigonometricFunction1_j < Mainframe_P.Saturation_LowerSat_ee) {
          rtb_TrigonometricFunction1_j = Mainframe_P.Saturation_LowerSat_ee;
        }
      }

      /* End of Saturate: '<S258>/Saturation' */
      rtb_TrigonometricFunction1_j = look1_binlcapw(rtb_TrigonometricFunction1_j,
        Mainframe_P.uDLookupTable_bp01Data, Mainframe_P.uDLookupTable_tableData,
        332U);
    }

    /* End of Switch: '<S258>/Switch1' */

    /* Sum: '<S259>/Add' incorporates:
     *  Constant: '<S258>/Constant1'
     *  Constant: '<S259>/Constant'
     *  Constant: '<S259>/Constant1'
     *  Product: '<S259>/Product'
     *  Sum: '<S258>/Subtract1'
     */
    rtb_Product2_l = (Mainframe_P.Constant1_Value_m +
                      rtb_TrigonometricFunction1_j) *
      Mainframe_P.Constant1_Value_lf + Mainframe_P.Constant_Value_aw;

    /* Product: '<S107>/Product' */
    rtb_IntegratorSecondOrderLimited_o2_a[0] *= rtb_Product2_l;
    rtb_IntegratorSecondOrderLimited_o2_a[1] *= rtb_Product2_l;
    rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[2] * rtb_Product2_l;

    /* Product: '<S106>/Product' incorporates:
     *  Math: '<S106>/Math Function'
     */
    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate_m[i] = rtb_VectorConcatenate3[3 * i + 2] * rtb_ixk_k
        + (rtb_VectorConcatenate3[3 * i + 1] *
           rtb_IntegratorSecondOrderLimited_o2_a[1] + rtb_VectorConcatenate3[3 *
           i] * rtb_IntegratorSecondOrderLimited_o2_a[0]);
    }

    /* End of Product: '<S106>/Product' */
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* MultiPortSwitch: '<S198>/Multiport Switch2' incorporates:
       *  Constant: '<S198>/Constant2'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_3) {
       case 1:
        /* Trigonometry: '<S206>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/thrust_rot_x'
         *  Trigonometry: '<S206>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_x_Value);

        /* Trigonometry: '<S206>/Trigonometric Function3' incorporates:
         *  Constant: '<S197>/thrust_rot_x'
         *  Trigonometry: '<S206>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.thrust_rot_x_Value);

        /* SignalConversion generated from: '<S206>/Matrix Concatenate' incorporates:
         *  Constant: '<S206>/Constant7'
         *  Trigonometry: '<S206>/Trigonometric Function1'
         *  Trigonometry: '<S206>/Trigonometric Function3'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Constant7_Value_a;
        rtb_MultiportSwitch[7] = rtb_ixk_k;
        rtb_MultiportSwitch[8] = beta;

        /* SignalConversion generated from: '<S206>/Matrix Concatenate' incorporates:
         *  Constant: '<S206>/Constant8'
         *  Gain: '<S206>/Gain'
         */
        rtb_MultiportSwitch[3] = Mainframe_P.Constant8_Value_g;
        rtb_MultiportSwitch[4] = beta;
        rtb_MultiportSwitch[5] = Mainframe_P.Gain_Gain_c * rtb_ixk_k;

        /* SignalConversion generated from: '<S206>/Matrix Concatenate' incorporates:
         *  Constant: '<S206>/Constant'
         *  Constant: '<S206>/Constant1'
         *  Constant: '<S206>/Constant2'
         */
        rtb_MultiportSwitch[0] = Mainframe_P.Constant_Value_o;
        rtb_MultiportSwitch[1] = Mainframe_P.Constant1_Value_j;
        rtb_MultiportSwitch[2] = Mainframe_P.Constant2_Value_i;
        break;

       case 2:
        /* Trigonometry: '<S207>/Trigonometric Function3' incorporates:
         *  Constant: '<S197>/thrust_rot_x'
         *  Trigonometry: '<S207>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.thrust_rot_x_Value);

        /* Trigonometry: '<S207>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/thrust_rot_x'
         *  Trigonometry: '<S207>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.thrust_rot_x_Value);

        /* SignalConversion generated from: '<S207>/Matrix Concatenate' incorporates:
         *  Constant: '<S207>/Constant7'
         *  Gain: '<S207>/Gain1'
         *  Trigonometry: '<S207>/Trigonometric Function1'
         *  Trigonometry: '<S207>/Trigonometric Function3'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Gain1_Gain_f * beta;
        rtb_MultiportSwitch[7] = Mainframe_P.Constant7_Value_d;
        rtb_MultiportSwitch[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S207>/Matrix Concatenate' incorporates:
         *  Constant: '<S207>/Constant'
         *  Constant: '<S207>/Constant1'
         *  Constant: '<S207>/Constant2'
         */
        rtb_MultiportSwitch[3] = Mainframe_P.Constant_Value_c;
        rtb_MultiportSwitch[4] = Mainframe_P.Constant1_Value;
        rtb_MultiportSwitch[5] = Mainframe_P.Constant2_Value;

        /* SignalConversion generated from: '<S207>/Matrix Concatenate' incorporates:
         *  Constant: '<S207>/Constant8'
         */
        rtb_MultiportSwitch[0] = rtb_ixk_k;
        rtb_MultiportSwitch[1] = Mainframe_P.Constant8_Value_k;
        rtb_MultiportSwitch[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S208>/Matrix Concatenate' incorporates:
         *  Constant: '<S208>/Constant10'
         *  Constant: '<S208>/Constant11'
         *  Constant: '<S208>/Constant4'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Constant4_Value;
        rtb_MultiportSwitch[7] = Mainframe_P.Constant10_Value;
        rtb_MultiportSwitch[8] = Mainframe_P.Constant11_Value;

        /* Trigonometry: '<S208>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/thrust_rot_x'
         *  Trigonometry: '<S208>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_x_Value);

        /* Trigonometry: '<S208>/Trigonometric Function' incorporates:
         *  Constant: '<S197>/thrust_rot_x'
         *  Trigonometry: '<S208>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.thrust_rot_x_Value);

        /* SignalConversion generated from: '<S208>/Matrix Concatenate' incorporates:
         *  Constant: '<S208>/Constant7'
         *  Trigonometry: '<S208>/Trigonometric Function'
         *  Trigonometry: '<S208>/Trigonometric Function1'
         */
        rtb_MultiportSwitch[3] = rtb_ixk_k;
        rtb_MultiportSwitch[4] = beta;
        rtb_MultiportSwitch[5] = Mainframe_P.Constant7_Value_f;

        /* SignalConversion generated from: '<S208>/Matrix Concatenate' incorporates:
         *  Constant: '<S208>/Constant8'
         *  Gain: '<S208>/Gain'
         */
        rtb_MultiportSwitch[0] = beta;
        rtb_MultiportSwitch[1] = Mainframe_P.Gain_Gain_k * rtb_ixk_k;
        rtb_MultiportSwitch[2] = Mainframe_P.Constant8_Value_a;
        break;
      }

      /* End of MultiPortSwitch: '<S198>/Multiport Switch2' */

      /* MultiPortSwitch: '<S198>/Multiport Switch1' incorporates:
       *  Constant: '<S198>/Constant1'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_2) {
       case 1:
        /* Trigonometry: '<S203>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/thrust_rot_y'
         *  Trigonometry: '<S203>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_y_Value);

        /* Trigonometry: '<S203>/Trigonometric Function3' incorporates:
         *  Constant: '<S197>/thrust_rot_y'
         *  Trigonometry: '<S203>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.thrust_rot_y_Value);

        /* SignalConversion generated from: '<S203>/Matrix Concatenate' incorporates:
         *  Constant: '<S203>/Constant7'
         *  Trigonometry: '<S203>/Trigonometric Function1'
         *  Trigonometry: '<S203>/Trigonometric Function3'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Constant7_Value_o;
        rtb_MultiportSwitch1[7] = rtb_ixk_k;
        rtb_MultiportSwitch1[8] = beta;

        /* SignalConversion generated from: '<S203>/Matrix Concatenate' incorporates:
         *  Constant: '<S203>/Constant8'
         *  Gain: '<S203>/Gain'
         */
        rtb_MultiportSwitch1[3] = Mainframe_P.Constant8_Value_g5;
        rtb_MultiportSwitch1[4] = beta;
        rtb_MultiportSwitch1[5] = Mainframe_P.Gain_Gain_d * rtb_ixk_k;

        /* SignalConversion generated from: '<S203>/Matrix Concatenate' incorporates:
         *  Constant: '<S203>/Constant'
         *  Constant: '<S203>/Constant1'
         *  Constant: '<S203>/Constant2'
         */
        rtb_MultiportSwitch1[0] = Mainframe_P.Constant_Value_hm;
        rtb_MultiportSwitch1[1] = Mainframe_P.Constant1_Value_d;
        rtb_MultiportSwitch1[2] = Mainframe_P.Constant2_Value_io;
        break;

       case 2:
        /* Trigonometry: '<S204>/Trigonometric Function3' incorporates:
         *  Constant: '<S197>/thrust_rot_y'
         *  Trigonometry: '<S204>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.thrust_rot_y_Value);

        /* Trigonometry: '<S204>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/thrust_rot_y'
         *  Trigonometry: '<S204>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.thrust_rot_y_Value);

        /* SignalConversion generated from: '<S204>/Matrix Concatenate' incorporates:
         *  Constant: '<S204>/Constant7'
         *  Gain: '<S204>/Gain1'
         *  Trigonometry: '<S204>/Trigonometric Function1'
         *  Trigonometry: '<S204>/Trigonometric Function3'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Gain1_Gain_c * beta;
        rtb_MultiportSwitch1[7] = Mainframe_P.Constant7_Value_c;
        rtb_MultiportSwitch1[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S204>/Matrix Concatenate' incorporates:
         *  Constant: '<S204>/Constant'
         *  Constant: '<S204>/Constant1'
         *  Constant: '<S204>/Constant2'
         */
        rtb_MultiportSwitch1[3] = Mainframe_P.Constant_Value_h;
        rtb_MultiportSwitch1[4] = Mainframe_P.Constant1_Value_b;
        rtb_MultiportSwitch1[5] = Mainframe_P.Constant2_Value_p;

        /* SignalConversion generated from: '<S204>/Matrix Concatenate' incorporates:
         *  Constant: '<S204>/Constant8'
         */
        rtb_MultiportSwitch1[0] = rtb_ixk_k;
        rtb_MultiportSwitch1[1] = Mainframe_P.Constant8_Value_j5;
        rtb_MultiportSwitch1[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S205>/Matrix Concatenate' incorporates:
         *  Constant: '<S205>/Constant10'
         *  Constant: '<S205>/Constant11'
         *  Constant: '<S205>/Constant4'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Constant4_Value_a;
        rtb_MultiportSwitch1[7] = Mainframe_P.Constant10_Value_f;
        rtb_MultiportSwitch1[8] = Mainframe_P.Constant11_Value_p;

        /* Trigonometry: '<S205>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/thrust_rot_y'
         *  Trigonometry: '<S205>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_y_Value);

        /* Trigonometry: '<S205>/Trigonometric Function' incorporates:
         *  Constant: '<S197>/thrust_rot_y'
         *  Trigonometry: '<S205>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.thrust_rot_y_Value);

        /* SignalConversion generated from: '<S205>/Matrix Concatenate' incorporates:
         *  Constant: '<S205>/Constant7'
         *  Trigonometry: '<S205>/Trigonometric Function'
         *  Trigonometry: '<S205>/Trigonometric Function1'
         */
        rtb_MultiportSwitch1[3] = rtb_ixk_k;
        rtb_MultiportSwitch1[4] = beta;
        rtb_MultiportSwitch1[5] = Mainframe_P.Constant7_Value_j;

        /* SignalConversion generated from: '<S205>/Matrix Concatenate' incorporates:
         *  Constant: '<S205>/Constant8'
         *  Gain: '<S205>/Gain'
         */
        rtb_MultiportSwitch1[0] = beta;
        rtb_MultiportSwitch1[1] = Mainframe_P.Gain_Gain_ii * rtb_ixk_k;
        rtb_MultiportSwitch1[2] = Mainframe_P.Constant8_Value_j;
        break;
      }

      /* End of MultiPortSwitch: '<S198>/Multiport Switch1' */

      /* MultiPortSwitch: '<S198>/Multiport Switch' incorporates:
       *  Constant: '<S198>/Constant'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_1) {
       case 1:
        /* Trigonometry: '<S200>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/Thrust_rot_z'
         *  Trigonometry: '<S200>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.Thrust_rot_z_Value);

        /* Trigonometry: '<S200>/Trigonometric Function3' incorporates:
         *  Constant: '<S197>/Thrust_rot_z'
         *  Trigonometry: '<S200>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.Thrust_rot_z_Value);

        /* SignalConversion generated from: '<S200>/Matrix Concatenate' incorporates:
         *  Constant: '<S200>/Constant7'
         *  Trigonometry: '<S200>/Trigonometric Function1'
         *  Trigonometry: '<S200>/Trigonometric Function3'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Constant7_Value_ih;
        rtb_MultiportSwitch2[7] = rtb_ixk_k;
        rtb_MultiportSwitch2[8] = beta;

        /* SignalConversion generated from: '<S200>/Matrix Concatenate' incorporates:
         *  Constant: '<S200>/Constant8'
         *  Gain: '<S200>/Gain'
         */
        rtb_MultiportSwitch2[3] = Mainframe_P.Constant8_Value_m;
        rtb_MultiportSwitch2[4] = beta;
        rtb_MultiportSwitch2[5] = Mainframe_P.Gain_Gain_dp * rtb_ixk_k;

        /* SignalConversion generated from: '<S200>/Matrix Concatenate' incorporates:
         *  Constant: '<S200>/Constant'
         *  Constant: '<S200>/Constant1'
         *  Constant: '<S200>/Constant2'
         */
        rtb_MultiportSwitch2[0] = Mainframe_P.Constant_Value_h1;
        rtb_MultiportSwitch2[1] = Mainframe_P.Constant1_Value_l;
        rtb_MultiportSwitch2[2] = Mainframe_P.Constant2_Value_f;
        break;

       case 2:
        /* Trigonometry: '<S201>/Trigonometric Function3' incorporates:
         *  Constant: '<S197>/Thrust_rot_z'
         *  Trigonometry: '<S201>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.Thrust_rot_z_Value);

        /* Trigonometry: '<S201>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/Thrust_rot_z'
         *  Trigonometry: '<S201>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.Thrust_rot_z_Value);

        /* SignalConversion generated from: '<S201>/Matrix Concatenate' incorporates:
         *  Constant: '<S201>/Constant7'
         *  Gain: '<S201>/Gain1'
         *  Trigonometry: '<S201>/Trigonometric Function1'
         *  Trigonometry: '<S201>/Trigonometric Function3'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Gain1_Gain_h * beta;
        rtb_MultiportSwitch2[7] = Mainframe_P.Constant7_Value_i;
        rtb_MultiportSwitch2[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S201>/Matrix Concatenate' incorporates:
         *  Constant: '<S201>/Constant'
         *  Constant: '<S201>/Constant1'
         *  Constant: '<S201>/Constant2'
         */
        rtb_MultiportSwitch2[3] = Mainframe_P.Constant_Value_lv;
        rtb_MultiportSwitch2[4] = Mainframe_P.Constant1_Value_h;
        rtb_MultiportSwitch2[5] = Mainframe_P.Constant2_Value_l;

        /* SignalConversion generated from: '<S201>/Matrix Concatenate' incorporates:
         *  Constant: '<S201>/Constant8'
         */
        rtb_MultiportSwitch2[0] = rtb_ixk_k;
        rtb_MultiportSwitch2[1] = Mainframe_P.Constant8_Value_cm;
        rtb_MultiportSwitch2[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S202>/Matrix Concatenate' incorporates:
         *  Constant: '<S202>/Constant10'
         *  Constant: '<S202>/Constant11'
         *  Constant: '<S202>/Constant4'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Constant4_Value_o;
        rtb_MultiportSwitch2[7] = Mainframe_P.Constant10_Value_g;
        rtb_MultiportSwitch2[8] = Mainframe_P.Constant11_Value_o;

        /* Trigonometry: '<S202>/Trigonometric Function1' incorporates:
         *  Constant: '<S197>/Thrust_rot_z'
         *  Trigonometry: '<S202>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.Thrust_rot_z_Value);

        /* Trigonometry: '<S202>/Trigonometric Function' incorporates:
         *  Constant: '<S197>/Thrust_rot_z'
         *  Trigonometry: '<S202>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.Thrust_rot_z_Value);

        /* SignalConversion generated from: '<S202>/Matrix Concatenate' incorporates:
         *  Constant: '<S202>/Constant7'
         *  Trigonometry: '<S202>/Trigonometric Function'
         *  Trigonometry: '<S202>/Trigonometric Function1'
         */
        rtb_MultiportSwitch2[3] = rtb_ixk_k;
        rtb_MultiportSwitch2[4] = beta;
        rtb_MultiportSwitch2[5] = Mainframe_P.Constant7_Value_ct;

        /* SignalConversion generated from: '<S202>/Matrix Concatenate' incorporates:
         *  Constant: '<S202>/Constant8'
         *  Gain: '<S202>/Gain'
         */
        rtb_MultiportSwitch2[0] = beta;
        rtb_MultiportSwitch2[1] = Mainframe_P.Gain_Gain_pz * rtb_ixk_k;
        rtb_MultiportSwitch2[2] = Mainframe_P.Constant8_Value_c;
        break;
      }

      /* End of MultiPortSwitch: '<S198>/Multiport Switch' */

      /* Product: '<S198>/3. Rotation' */
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

      /* End of Product: '<S198>/3. Rotation' */
    }

    /* Switch: '<S196>/Switch' incorporates:
     *  Constant: '<S196>/Constant'
     */
    if (!(rtb_T_sim_glbl > Mainframe_P.Switch_Threshold_o3)) {
      rtb_T_sim_glbl = Mainframe_P.Constant_Value_ny;
    }

    /* End of Switch: '<S196>/Switch' */

    /* Switch: '<S196>/Switch1' incorporates:
     *  Lookup_n-D: '<S196>/thrust_lookup'
     */
    if (rtb_T_sim_glbl > Mainframe_P.Switch1_Threshold_f) {
      /* Saturate: '<S196>/Saturation' */
      if (rtb_T_sim_glbl > Mainframe_P.Saturation_UpperSat) {
        rtb_T_sim_glbl = Mainframe_P.Saturation_UpperSat;
      } else {
        if (rtb_T_sim_glbl < Mainframe_P.Saturation_LowerSat) {
          rtb_T_sim_glbl = Mainframe_P.Saturation_LowerSat;
        }
      }

      /* End of Saturate: '<S196>/Saturation' */
      rtb_IntegratorSecondOrderLimited_o2_a[0] = look1_binlcapw(rtb_T_sim_glbl,
        Mainframe_P.thrust_lookup_bp01Data, Mainframe_P.thrust_lookup_tableData,
        332U);
    } else {
      rtb_IntegratorSecondOrderLimited_o2_a[0] = rtb_T_sim_glbl;
    }

    /* End of Switch: '<S196>/Switch1' */

    /* Product: '<S197>/Product1' incorporates:
     *  Constant: '<S196>/Constant1'
     *  Constant: '<S197>/uncert_thrust'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[0] *= Mainframe_P.uncert_thrust_Value;
    rtb_IntegratorSecondOrderLimited_o2_h_tmp = Mainframe_P.Constant1_Value_k *
      Mainframe_P.uncert_thrust_Value;

    /* Product: '<S197>/Product' incorporates:
     *  Product: '<S197>/Product1'
     */
    for (i = 0; i < 3; i++) {
      rtb_u2[i] = Mainframe_B.T12[i + 6] *
        rtb_IntegratorSecondOrderLimited_o2_h_tmp + (Mainframe_B.T12[i + 3] *
        rtb_IntegratorSecondOrderLimited_o2_h_tmp + Mainframe_B.T12[i] *
        rtb_IntegratorSecondOrderLimited_o2_a[0]);
    }

    /* End of Product: '<S197>/Product' */

    /* Switch: '<S239>/Switch' incorporates:
     *  Constant: '<S239>/Constant'
     *  Product: '<S239>/Product2'
     *  Sum: '<S106>/Add'
     */
    if (Mainframe_P.Rigid_Body_EOM_6_DOF_flag_Kraft >
        Mainframe_P.Switch_Threshold_om) {
      rtb_Sum1_e[0] = (rtb_Sum1_e[0] + rtb_VectorConcatenate_m[0]) + rtb_u2[0];
      rtb_Sum1_e[1] = (rtb_Sum1_e[1] + rtb_VectorConcatenate_m[1]) + rtb_u2[1];
      rtb_Sum1_e[2] = (rtb_Sum1_e[2] + rtb_VectorConcatenate_m[2]) + rtb_u2[2];
    } else {
      /* Sum: '<S241>/Add7' */
      rtb_MathFunction2[8] = q0_tmp;

      /* Sum: '<S241>/Add8' incorporates:
       *  Gain: '<S241>/Gain11'
       *  Gain: '<S241>/Gain12'
       */
      rtb_MathFunction2[7] = rtb_JMMB_tmp_3 * Mainframe_P.Gain11_Gain +
        rtb_JMMB_tmp_4 * Mainframe_P.Gain12_Gain;

      /* Sum: '<S241>/Add3' incorporates:
       *  Gain: '<S241>/Gain5'
       *  Gain: '<S241>/Gain6'
       */
      rtb_MathFunction2[6] = rtb_JMMB_tmp_1 * Mainframe_P.Gain5_Gain -
        rtb_JMMB_tmp_2 * Mainframe_P.Gain6_Gain;

      /* Sum: '<S241>/Add2' incorporates:
       *  Gain: '<S241>/Gain3'
       *  Gain: '<S241>/Gain4'
       */
      rtb_MathFunction2[5] = rtb_JMMB_tmp_3 * Mainframe_P.Gain3_Gain -
        rtb_JMMB_tmp_4 * Mainframe_P.Gain4_Gain;

      /* Sum: '<S241>/Add6' */
      rtb_MathFunction2[4] = rtb_JMMB_tmp_5;

      /* Sum: '<S241>/Add4' incorporates:
       *  Gain: '<S241>/Gain7'
       *  Gain: '<S241>/Gain8'
       */
      rtb_MathFunction2[3] = rtb_JMMB_tmp * Mainframe_P.Gain7_Gain +
        rtb_JMMB_tmp_0 * Mainframe_P.Gain8_Gain;

      /* Sum: '<S241>/Add5' incorporates:
       *  Gain: '<S241>/Gain10'
       *  Gain: '<S241>/Gain9'
       */
      rtb_MathFunction2[2] = rtb_JMMB_tmp_1 * Mainframe_P.Gain9_Gain +
        rtb_JMMB_tmp_2 * Mainframe_P.Gain10_Gain;

      /* Sum: '<S241>/Add1' incorporates:
       *  Gain: '<S241>/Gain1'
       *  Gain: '<S241>/Gain2'
       */
      rtb_MathFunction2[1] = rtb_JMMB_tmp * Mainframe_P.Gain1_Gain_g -
        rtb_JMMB_tmp_0 * Mainframe_P.Gain2_Gain_j;

      /* Sum: '<S241>/Add' */
      rtb_MathFunction2[0] = rtb_JMMB_tmp_6;

      /* Math: '<S239>/Math Function2' */
      for (i = 0; i < 3; i++) {
        rtb_Product2_mq[3 * i] = rtb_MathFunction2[i];
        rtb_Product2_mq[3 * i + 1] = rtb_MathFunction2[i + 3];
        rtb_Product2_mq[3 * i + 2] = rtb_MathFunction2[i + 6];
      }

      memcpy(&rtb_MathFunction2[0], &rtb_Product2_mq[0], 9U * sizeof(real_T));

      /* End of Math: '<S239>/Math Function2' */

      /* Sum: '<S106>/Add' */
      rtb_JMMB_tmp = (rtb_Sum1_e[0] + rtb_VectorConcatenate_m[0]) + rtb_u2[0];
      q0_tmp = (rtb_Sum1_e[1] + rtb_VectorConcatenate_m[1]) + rtb_u2[1];
      rtb_JMMB_tmp_6 = (rtb_Sum1_e[2] + rtb_VectorConcatenate_m[2]) + rtb_u2[2];
      for (i = 0; i < 3; i++) {
        rtb_Sum1_e[i] = rtb_MathFunction2[i + 6] * rtb_JMMB_tmp_6 +
          (rtb_MathFunction2[i + 3] * q0_tmp + rtb_MathFunction2[i] *
           rtb_JMMB_tmp);
      }
    }

    /* Saturate: '<S242>/Saturation' */
    if (rtb_Product2_l > Mainframe_P.Saturation_UpperSat_g) {
      rtb_ixk_k = Mainframe_P.Saturation_UpperSat_g;
    } else if (rtb_Product2_l < Mainframe_P.Saturation_LowerSat_i) {
      rtb_ixk_k = Mainframe_P.Saturation_LowerSat_i;
    } else {
      rtb_ixk_k = rtb_Product2_l;
    }

    /* End of Saturate: '<S242>/Saturation' */

    /* Product: '<S242>/Divide' */
    rtb_Sum1_e[0] /= rtb_ixk_k;
    rtb_Sum1_e[1] /= rtb_ixk_k;

    /* SignalConversion generated from: '<S246>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_c[0] = rtb_Sum1_e[0];

    /* SignalConversion generated from: '<S246>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_c[1] = rtb_Sum1_e[1];

    /* SignalConversion generated from: '<S246>/Vector Concatenate' incorporates:
     *  Product: '<S242>/Divide'
     */
    Mainframe_B.VectorConcatenate_c[2] = rtb_Sum1_e[2] / rtb_ixk_k;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S246>/Constant' */
      Mainframe_B.VectorConcatenate_c[3] = Mainframe_P.Constant_Value_bd;
    }

    /* Sum: '<S246>/Add' incorporates:
     *  Constant: '<S246>/Q_1'
     *  Constant: '<S246>/Q_2'
     *  Constant: '<S246>/Q_3'
     *  Constant: '<S246>/Q_4'
     *  Product: '<S246>/Product'
     *  Product: '<S246>/Product1'
     *  Product: '<S246>/Product2'
     *  Product: '<S246>/Product3'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_d[i] * rtb_Product_b_idx_0 +
                 Mainframe_P.Q_2_Value_f[i] * rtb_Product_b_idx_1) +
                Mainframe_P.Q_3_Value_c[i] * rtb_Product_b_idx_2) +
        Mainframe_P.Q_4_Value_n[i] * rtb_Product_d;
    }

    /* End of Sum: '<S246>/Add' */

    /* Product: '<S246>/Product8' */
    for (i = 0; i < 4; i++) {
      rtb_T_sim_glbl = tmp[i + 12] * Mainframe_B.VectorConcatenate_c[3] + (tmp[i
        + 8] * Mainframe_B.VectorConcatenate_c[2] + (tmp[i + 4] *
        Mainframe_B.VectorConcatenate_c[1] + tmp[i] *
        Mainframe_B.VectorConcatenate_c[0]));
      rtb_d_qEI[i] = rtb_T_sim_glbl;
    }

    /* Sum: '<S246>/Add1' incorporates:
     *  Constant: '<S246>/Q~_1'
     *  Constant: '<S246>/Q~_2'
     *  Constant: '<S246>/Q~_3'
     *  Constant: '<S246>/Q~_4'
     *  Product: '<S246>/Product4'
     *  Product: '<S246>/Product5'
     *  Product: '<S246>/Product6'
     *  Product: '<S246>/Product7'
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

    /* End of Sum: '<S246>/Add1' */

    /* Product: '<S246>/Product8' */
    for (i = 0; i < 4; i++) {
      rtb_ixk_k = tmp[i + 12] * rtb_d_qEI[3] + (tmp[i + 8] * rtb_d_qEI[2] +
        (tmp[i + 4] * rtb_d_qEI[1] + tmp[i] * rtb_d_qEI[0]));
      rtb_q_conj[i] = rtb_ixk_k;
    }

    /* SecondOrderIntegrator: '<S90>/Integrator, Second-Order Limited' */
    /* Unit Conversion - from: m/s^2 to: gn
       Expression: output = (0.101972*input) + (0) */
    idx = 3;

    /* Gain: '<S90>/2*zeta * wn' */
    rtb_T_sim_glbl = 2.0 * Mainframe_P.ThreeaxisInertialMeasurementUnit_z_a *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a;
    for (rtb_MultiportSwitch1_tmp = 0; rtb_MultiportSwitch1_tmp < 3;
         rtb_MultiportSwitch1_tmp++) {
      /* Product: '<S209>/Product' incorporates:
       *  Math: '<S209>/Math Function'
       */
      Mainframe_B.aBIB[rtb_MultiportSwitch1_tmp] = 0.0;
      Mainframe_B.aBIB[rtb_MultiportSwitch1_tmp] +=
        rtb_TBI_tmp[rtb_MultiportSwitch1_tmp] * rtb_q_conj[0];
      Mainframe_B.aBIB[rtb_MultiportSwitch1_tmp] +=
        rtb_TBI_tmp[rtb_MultiportSwitch1_tmp + 3] * rtb_q_conj[1];
      Mainframe_B.aBIB[rtb_MultiportSwitch1_tmp] +=
        rtb_TBI_tmp[rtb_MultiportSwitch1_tmp + 6] * rtb_q_conj[2];

      /* SecondOrderIntegrator: '<S90>/Integrator, Second-Order Limited' */
      rtb_IntegratorSecondOrderLimited_o2_a[rtb_MultiportSwitch1_tmp] =
        Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[rtb_MultiportSwitch1_tmp];
      q0_tmp = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[idx];
      idx++;

      /* Gain: '<S90>/2*zeta * wn' */
      rtb_uzetawn_p[rtb_MultiportSwitch1_tmp] = rtb_T_sim_glbl * q0_tmp;

      /* Gain: '<S83>/Zero-Order Hold2' */
      rtb_ZeroOrderHold2_c[rtb_MultiportSwitch1_tmp] =
        Mainframe_P.ZeroOrderHold2_Gain * rtb_Sum4[rtb_MultiportSwitch1_tmp];

      /* Gain: '<S83>/Zero-Order Hold' */
      rtb_Sum4[rtb_MultiportSwitch1_tmp] =
        Mainframe_B.x_d[rtb_MultiportSwitch1_tmp + 10] *
        Mainframe_P.ZeroOrderHold_Gain;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S83>/Gain' incorporates:
       *  Constant: '<S76>/Constant1'
       *  Constant: '<S83>/wl_ins'
       *  Gain: '<S83>/Zero-Order Hold4'
       *  Sum: '<S83>/Sum7'
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

      /* Product: '<S257>/Product' incorporates:
       *  Constant: '<S257>/Constant'
       *  Constant: '<S257>/Constant6'
       */
      Mainframe_B.Product_a = Mainframe_P.Constant_Value_ds *
        Mainframe_P.Constant6_Value_i;
    }

    /* Sum: '<S92>/Sum' incorporates:
     *  Product: '<S95>/i x j'
     *  Product: '<S95>/j x k'
     *  Product: '<S95>/k x i'
     *  Product: '<S96>/i x k'
     *  Product: '<S96>/j x i'
     *  Product: '<S96>/k x j'
     */
    rtb_VectorConcatenate_m[0] = rtb_Sum4[1] * Mainframe_B.Gain_ln[2] -
      rtb_Sum4[2] * Mainframe_B.Gain_ln[1];
    rtb_VectorConcatenate_m[1] = rtb_Sum4[2] * Mainframe_B.Gain_ln[0] -
      rtb_Sum4[0] * Mainframe_B.Gain_ln[2];
    rtb_VectorConcatenate_m[2] = rtb_Sum4[0] * Mainframe_B.Gain_ln[1] -
      rtb_Sum4[1] * Mainframe_B.Gain_ln[0];

    /* Product: '<S93>/i x j' */
    rtb_T_sim_glbl = rtb_Sum4[0];

    /* Product: '<S94>/i x k' */
    q0_tmp = rtb_Sum4[0];

    /* Product: '<S94>/j x i' */
    rtb_JMMB_tmp_6 = rtb_Sum4[1];

    /* Sum: '<S91>/Sum' incorporates:
     *  Product: '<S93>/i x j'
     *  Product: '<S93>/j x k'
     *  Product: '<S93>/k x i'
     *  Product: '<S94>/i x k'
     *  Product: '<S94>/j x i'
     *  Product: '<S94>/k x j'
     */
    rtb_Sum4[0] = rtb_Sum4[1] * rtb_VectorConcatenate_m[2] - rtb_Sum4[2] *
      rtb_VectorConcatenate_m[1];
    rtb_Sum4[1] = rtb_Sum4[2] * rtb_VectorConcatenate_m[0] - q0_tmp *
      rtb_VectorConcatenate_m[2];
    rtb_Sum4[2] = rtb_T_sim_glbl * rtb_VectorConcatenate_m[1] - rtb_JMMB_tmp_6 *
      rtb_VectorConcatenate_m[0];

    /* Sum: '<S257>/Add4' incorporates:
     *  Constant: '<S257>/Constant3'
     *  Constant: '<S257>/Constant4'
     *  Product: '<S257>/Divide'
     *  Product: '<S257>/Product1'
     *  Sum: '<S257>/Add'
     */
    rtb_Sum1_e[0] = (rtb_TrigonometricFunction1_j *
                     Mainframe_P.Constant4_Value_as + Mainframe_B.Product_a) *
      (1.0 / rtb_Product2_l) + Mainframe_P.Constant3_Value_p;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Product: '<S257>/Product2' incorporates:
       *  Constant: '<S257>/Constant'
       *  Constant: '<S257>/Constant5'
       */
      Mainframe_B.Product2 = Mainframe_P.Constant_Value_ds *
        Mainframe_P.Constant5_Value;

      /* Product: '<S257>/Product4' incorporates:
       *  Constant: '<S257>/Constant'
       *  Constant: '<S257>/Constant8'
       */
      Mainframe_B.Product4 = Mainframe_P.Constant_Value_ds *
        Mainframe_P.Constant8_Value_n;
    }

    /* Sum: '<S257>/Add3' incorporates:
     *  Constant: '<S257>/Constant1'
     *  Constant: '<S257>/Constant7'
     *  Product: '<S257>/Divide1'
     *  Product: '<S257>/Product3'
     *  Sum: '<S257>/Add1'
     */
    rtb_Sum1_e[1] = (rtb_TrigonometricFunction1_j *
                     Mainframe_P.Constant7_Value_ei + Mainframe_B.Product2) *
      (1.0 / rtb_Product2_l) + Mainframe_P.Constant1_Value_mh;

    /* Sum: '<S257>/Add5' incorporates:
     *  Constant: '<S257>/Constant2'
     *  Constant: '<S257>/Constant9'
     *  Product: '<S257>/Divide2'
     *  Product: '<S257>/Product5'
     *  Sum: '<S257>/Add2'
     */
    rtb_Sum1_e[2] = (rtb_TrigonometricFunction1_j *
                     Mainframe_P.Constant9_Value_a + Mainframe_B.Product4) *
      (1.0 / rtb_Product2_l) + Mainframe_P.Constant2_Value_lc;

    /* Sum: '<S264>/Subtract' incorporates:
     *  Constant: '<S264>/Constant17'
     */
    rtb_VectorConcatenate_m[0] = rtb_Sum1_e[0] - Mainframe_P.Constant17_Value[0];
    rtb_VectorConcatenate_m[1] = rtb_Sum1_e[1] - Mainframe_P.Constant17_Value[1];
    rtb_VectorConcatenate_m[2] = rtb_Sum1_e[2] - Mainframe_P.Constant17_Value[2];

    /* Product: '<S276>/Product1' */
    rtb_T_sim_glbl = rtb_VectorConcatenate_m[1] * rtb_VectorConcatenate_m[1];

    /* Product: '<S276>/Product2' */
    rtb_Product2_l = rtb_VectorConcatenate_m[2] * rtb_VectorConcatenate_m[2];

    /* Sum: '<S276>/Add' */
    rtb_JMMB[0] = rtb_T_sim_glbl + rtb_Product2_l;

    /* Gain: '<S276>/Gain' incorporates:
     *  Product: '<S276>/Product3'
     */
    rtb_ixk_k = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[1] *
      Mainframe_P.Gain_Gain_mf;

    /* SignalConversion generated from: '<S276>/Vector Concatenate6' */
    rtb_JMMB[1] = rtb_ixk_k;

    /* Gain: '<S276>/Gain1' incorporates:
     *  Product: '<S276>/Product4'
     */
    beta = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[2] *
      Mainframe_P.Gain1_Gain_o1;

    /* SignalConversion generated from: '<S276>/Vector Concatenate6' */
    rtb_JMMB[2] = beta;

    /* SignalConversion generated from: '<S276>/Vector Concatenate7' */
    rtb_JMMB[3] = rtb_ixk_k;

    /* Product: '<S276>/Product5' */
    rtb_ixk_k = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[0];

    /* Sum: '<S276>/Add5' */
    rtb_JMMB[4] = rtb_T_sim_glbl + rtb_ixk_k;

    /* Gain: '<S276>/Gain3' incorporates:
     *  Product: '<S276>/Product6'
     */
    rtb_T_sim_glbl = rtb_VectorConcatenate_m[1] * rtb_VectorConcatenate_m[2] *
      Mainframe_P.Gain3_Gain_b;

    /* SignalConversion generated from: '<S276>/Vector Concatenate7' */
    rtb_JMMB[5] = rtb_T_sim_glbl;

    /* SignalConversion generated from: '<S276>/Vector Concatenate8' */
    rtb_JMMB[6] = beta;

    /* SignalConversion generated from: '<S276>/Vector Concatenate8' */
    rtb_JMMB[7] = rtb_T_sim_glbl;

    /* Sum: '<S276>/Add4' */
    rtb_JMMB[8] = rtb_Product2_l + rtb_ixk_k;

    /* Sum: '<S260>/Add5' incorporates:
     *  Constant: '<S260>/Constant15'
     *  Constant: '<S264>/Constant'
     *  Product: '<S264>/Product'
     */
    for (i = 0; i < 9; i++) {
      rtb_MathFunction2[i] = Mainframe_P.Constant_Value_mt * rtb_JMMB[i] +
        Mainframe_P.Constant15_Value[i];
    }

    /* End of Sum: '<S260>/Add5' */

    /* Sum: '<S265>/Subtract4' incorporates:
     *  Constant: '<S265>/Constant16'
     */
    rtb_VectorConcatenate_m[0] = rtb_Sum1_e[0] - Mainframe_P.Constant16_Value[0];
    rtb_VectorConcatenate_m[1] = rtb_Sum1_e[1] - Mainframe_P.Constant16_Value[1];
    rtb_VectorConcatenate_m[2] = rtb_Sum1_e[2] - Mainframe_P.Constant16_Value[2];

    /* Product: '<S277>/Product1' */
    rtb_T_sim_glbl = rtb_VectorConcatenate_m[1] * rtb_VectorConcatenate_m[1];

    /* Product: '<S277>/Product2' */
    rtb_Product2_l = rtb_VectorConcatenate_m[2] * rtb_VectorConcatenate_m[2];

    /* Sum: '<S277>/Add' */
    rtb_JMMB[0] = rtb_T_sim_glbl + rtb_Product2_l;

    /* Gain: '<S277>/Gain' incorporates:
     *  Product: '<S277>/Product3'
     */
    rtb_ixk_k = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[1] *
      Mainframe_P.Gain_Gain_mj;

    /* SignalConversion generated from: '<S277>/Vector Concatenate6' */
    rtb_JMMB[1] = rtb_ixk_k;

    /* Gain: '<S277>/Gain1' incorporates:
     *  Product: '<S277>/Product4'
     */
    beta = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[2] *
      Mainframe_P.Gain1_Gain_fv;

    /* SignalConversion generated from: '<S277>/Vector Concatenate6' */
    rtb_JMMB[2] = beta;

    /* SignalConversion generated from: '<S277>/Vector Concatenate7' */
    rtb_JMMB[3] = rtb_ixk_k;

    /* Product: '<S277>/Product5' */
    rtb_ixk_k = rtb_VectorConcatenate_m[0] * rtb_VectorConcatenate_m[0];

    /* Sum: '<S277>/Add5' */
    rtb_JMMB[4] = rtb_T_sim_glbl + rtb_ixk_k;

    /* Gain: '<S277>/Gain3' incorporates:
     *  Product: '<S277>/Product6'
     */
    rtb_T_sim_glbl = rtb_VectorConcatenate_m[1] * rtb_VectorConcatenate_m[2] *
      Mainframe_P.Gain3_Gain_bz;

    /* SignalConversion generated from: '<S277>/Vector Concatenate7' */
    rtb_JMMB[5] = rtb_T_sim_glbl;

    /* SignalConversion generated from: '<S277>/Vector Concatenate8' */
    rtb_JMMB[6] = beta;

    /* SignalConversion generated from: '<S277>/Vector Concatenate8' */
    rtb_JMMB[7] = rtb_T_sim_glbl;

    /* Sum: '<S277>/Add4' */
    rtb_JMMB[8] = rtb_Product2_l + rtb_ixk_k;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* MultiPortSwitch: '<S266>/Multiport Switch2' incorporates:
       *  Constant: '<S266>/Constant2'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_3_a) {
       case 1:
        /* Trigonometry: '<S273>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/thrust_rot_x'
         *  Trigonometry: '<S273>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_x_Value_h);

        /* Trigonometry: '<S273>/Trigonometric Function3' incorporates:
         *  Constant: '<S262>/thrust_rot_x'
         *  Trigonometry: '<S273>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.thrust_rot_x_Value_h);

        /* SignalConversion generated from: '<S273>/Matrix Concatenate' incorporates:
         *  Constant: '<S273>/Constant7'
         *  Trigonometry: '<S273>/Trigonometric Function1'
         *  Trigonometry: '<S273>/Trigonometric Function3'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Constant7_Value_g;
        rtb_MultiportSwitch2[7] = rtb_ixk_k;
        rtb_MultiportSwitch2[8] = beta;

        /* SignalConversion generated from: '<S273>/Matrix Concatenate' incorporates:
         *  Constant: '<S273>/Constant8'
         *  Gain: '<S273>/Gain'
         */
        rtb_MultiportSwitch2[3] = Mainframe_P.Constant8_Value_l;
        rtb_MultiportSwitch2[4] = beta;
        rtb_MultiportSwitch2[5] = Mainframe_P.Gain_Gain_gk * rtb_ixk_k;

        /* SignalConversion generated from: '<S273>/Matrix Concatenate' incorporates:
         *  Constant: '<S273>/Constant'
         *  Constant: '<S273>/Constant1'
         *  Constant: '<S273>/Constant2'
         */
        rtb_MultiportSwitch2[0] = Mainframe_P.Constant_Value_pf;
        rtb_MultiportSwitch2[1] = Mainframe_P.Constant1_Value_i;
        rtb_MultiportSwitch2[2] = Mainframe_P.Constant2_Value_m;
        break;

       case 2:
        /* Trigonometry: '<S274>/Trigonometric Function3' incorporates:
         *  Constant: '<S262>/thrust_rot_x'
         *  Trigonometry: '<S274>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.thrust_rot_x_Value_h);

        /* Trigonometry: '<S274>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/thrust_rot_x'
         *  Trigonometry: '<S274>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.thrust_rot_x_Value_h);

        /* SignalConversion generated from: '<S274>/Matrix Concatenate' incorporates:
         *  Constant: '<S274>/Constant7'
         *  Gain: '<S274>/Gain1'
         *  Trigonometry: '<S274>/Trigonometric Function1'
         *  Trigonometry: '<S274>/Trigonometric Function3'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Gain1_Gain_g4 * beta;
        rtb_MultiportSwitch2[7] = Mainframe_P.Constant7_Value_op;
        rtb_MultiportSwitch2[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S274>/Matrix Concatenate' incorporates:
         *  Constant: '<S274>/Constant'
         *  Constant: '<S274>/Constant1'
         *  Constant: '<S274>/Constant2'
         */
        rtb_MultiportSwitch2[3] = Mainframe_P.Constant_Value_f;
        rtb_MultiportSwitch2[4] = Mainframe_P.Constant1_Value_jv;
        rtb_MultiportSwitch2[5] = Mainframe_P.Constant2_Value_j;

        /* SignalConversion generated from: '<S274>/Matrix Concatenate' incorporates:
         *  Constant: '<S274>/Constant8'
         */
        rtb_MultiportSwitch2[0] = rtb_ixk_k;
        rtb_MultiportSwitch2[1] = Mainframe_P.Constant8_Value_gc;
        rtb_MultiportSwitch2[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S275>/Matrix Concatenate' incorporates:
         *  Constant: '<S275>/Constant10'
         *  Constant: '<S275>/Constant11'
         *  Constant: '<S275>/Constant4'
         */
        rtb_MultiportSwitch2[6] = Mainframe_P.Constant4_Value_i;
        rtb_MultiportSwitch2[7] = Mainframe_P.Constant10_Value_k;
        rtb_MultiportSwitch2[8] = Mainframe_P.Constant11_Value_l;

        /* Trigonometry: '<S275>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/thrust_rot_x'
         *  Trigonometry: '<S275>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_x_Value_h);

        /* Trigonometry: '<S275>/Trigonometric Function' incorporates:
         *  Constant: '<S262>/thrust_rot_x'
         *  Trigonometry: '<S275>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.thrust_rot_x_Value_h);

        /* SignalConversion generated from: '<S275>/Matrix Concatenate' incorporates:
         *  Constant: '<S275>/Constant7'
         *  Trigonometry: '<S275>/Trigonometric Function'
         *  Trigonometry: '<S275>/Trigonometric Function1'
         */
        rtb_MultiportSwitch2[3] = rtb_ixk_k;
        rtb_MultiportSwitch2[4] = beta;
        rtb_MultiportSwitch2[5] = Mainframe_P.Constant7_Value_a5;

        /* SignalConversion generated from: '<S275>/Matrix Concatenate' incorporates:
         *  Constant: '<S275>/Constant8'
         *  Gain: '<S275>/Gain'
         */
        rtb_MultiportSwitch2[0] = beta;
        rtb_MultiportSwitch2[1] = Mainframe_P.Gain_Gain_h * rtb_ixk_k;
        rtb_MultiportSwitch2[2] = Mainframe_P.Constant8_Value_j1;
        break;
      }

      /* End of MultiPortSwitch: '<S266>/Multiport Switch2' */

      /* MultiPortSwitch: '<S266>/Multiport Switch1' incorporates:
       *  Constant: '<S266>/Constant1'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_2_a) {
       case 1:
        /* Trigonometry: '<S270>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/thrust_rot_y'
         *  Trigonometry: '<S270>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_y_Value_j);

        /* Trigonometry: '<S270>/Trigonometric Function3' incorporates:
         *  Constant: '<S262>/thrust_rot_y'
         *  Trigonometry: '<S270>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.thrust_rot_y_Value_j);

        /* SignalConversion generated from: '<S270>/Matrix Concatenate' incorporates:
         *  Constant: '<S270>/Constant7'
         *  Trigonometry: '<S270>/Trigonometric Function1'
         *  Trigonometry: '<S270>/Trigonometric Function3'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Constant7_Value_e;
        rtb_MultiportSwitch1[7] = rtb_ixk_k;
        rtb_MultiportSwitch1[8] = beta;

        /* SignalConversion generated from: '<S270>/Matrix Concatenate' incorporates:
         *  Constant: '<S270>/Constant8'
         *  Gain: '<S270>/Gain'
         */
        rtb_MultiportSwitch1[3] = Mainframe_P.Constant8_Value_e;
        rtb_MultiportSwitch1[4] = beta;
        rtb_MultiportSwitch1[5] = Mainframe_P.Gain_Gain_o * rtb_ixk_k;

        /* SignalConversion generated from: '<S270>/Matrix Concatenate' incorporates:
         *  Constant: '<S270>/Constant'
         *  Constant: '<S270>/Constant1'
         *  Constant: '<S270>/Constant2'
         */
        rtb_MultiportSwitch1[0] = Mainframe_P.Constant_Value_m;
        rtb_MultiportSwitch1[1] = Mainframe_P.Constant1_Value_f;
        rtb_MultiportSwitch1[2] = Mainframe_P.Constant2_Value_i3;
        break;

       case 2:
        /* Trigonometry: '<S271>/Trigonometric Function3' incorporates:
         *  Constant: '<S262>/thrust_rot_y'
         *  Trigonometry: '<S271>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.thrust_rot_y_Value_j);

        /* Trigonometry: '<S271>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/thrust_rot_y'
         *  Trigonometry: '<S271>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.thrust_rot_y_Value_j);

        /* SignalConversion generated from: '<S271>/Matrix Concatenate' incorporates:
         *  Constant: '<S271>/Constant7'
         *  Gain: '<S271>/Gain1'
         *  Trigonometry: '<S271>/Trigonometric Function1'
         *  Trigonometry: '<S271>/Trigonometric Function3'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Gain1_Gain_cw * beta;
        rtb_MultiportSwitch1[7] = Mainframe_P.Constant7_Value_l;
        rtb_MultiportSwitch1[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S271>/Matrix Concatenate' incorporates:
         *  Constant: '<S271>/Constant'
         *  Constant: '<S271>/Constant1'
         *  Constant: '<S271>/Constant2'
         */
        rtb_MultiportSwitch1[3] = Mainframe_P.Constant_Value_b4;
        rtb_MultiportSwitch1[4] = Mainframe_P.Constant1_Value_jy;
        rtb_MultiportSwitch1[5] = Mainframe_P.Constant2_Value_ia;

        /* SignalConversion generated from: '<S271>/Matrix Concatenate' incorporates:
         *  Constant: '<S271>/Constant8'
         */
        rtb_MultiportSwitch1[0] = rtb_ixk_k;
        rtb_MultiportSwitch1[1] = Mainframe_P.Constant8_Value_cx;
        rtb_MultiportSwitch1[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S272>/Matrix Concatenate' incorporates:
         *  Constant: '<S272>/Constant10'
         *  Constant: '<S272>/Constant11'
         *  Constant: '<S272>/Constant4'
         */
        rtb_MultiportSwitch1[6] = Mainframe_P.Constant4_Value_j;
        rtb_MultiportSwitch1[7] = Mainframe_P.Constant10_Value_i;
        rtb_MultiportSwitch1[8] = Mainframe_P.Constant11_Value_lg;

        /* Trigonometry: '<S272>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/thrust_rot_y'
         *  Trigonometry: '<S272>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.thrust_rot_y_Value_j);

        /* Trigonometry: '<S272>/Trigonometric Function' incorporates:
         *  Constant: '<S262>/thrust_rot_y'
         *  Trigonometry: '<S272>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.thrust_rot_y_Value_j);

        /* SignalConversion generated from: '<S272>/Matrix Concatenate' incorporates:
         *  Constant: '<S272>/Constant7'
         *  Trigonometry: '<S272>/Trigonometric Function'
         *  Trigonometry: '<S272>/Trigonometric Function1'
         */
        rtb_MultiportSwitch1[3] = rtb_ixk_k;
        rtb_MultiportSwitch1[4] = beta;
        rtb_MultiportSwitch1[5] = Mainframe_P.Constant7_Value_n;

        /* SignalConversion generated from: '<S272>/Matrix Concatenate' incorporates:
         *  Constant: '<S272>/Constant8'
         *  Gain: '<S272>/Gain'
         */
        rtb_MultiportSwitch1[0] = beta;
        rtb_MultiportSwitch1[1] = Mainframe_P.Gain_Gain_c4 * rtb_ixk_k;
        rtb_MultiportSwitch1[2] = Mainframe_P.Constant8_Value_mn;
        break;
      }

      /* End of MultiPortSwitch: '<S266>/Multiport Switch1' */

      /* MultiPortSwitch: '<S266>/Multiport Switch' incorporates:
       *  Constant: '<S266>/Constant'
       */
      switch ((int32_T)Mainframe_P.u_rot_mat_rot_1_e) {
       case 1:
        /* Trigonometry: '<S267>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/Thrust_rot_z'
         *  Trigonometry: '<S267>/Trigonometric Function2'
         */
        rtb_ixk_k = sin(Mainframe_P.Thrust_rot_z_Value_l);

        /* Trigonometry: '<S267>/Trigonometric Function3' incorporates:
         *  Constant: '<S262>/Thrust_rot_z'
         *  Trigonometry: '<S267>/Trigonometric Function'
         */
        beta = cos(Mainframe_P.Thrust_rot_z_Value_l);

        /* SignalConversion generated from: '<S267>/Matrix Concatenate' incorporates:
         *  Constant: '<S267>/Constant7'
         *  Trigonometry: '<S267>/Trigonometric Function1'
         *  Trigonometry: '<S267>/Trigonometric Function3'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Constant7_Value_b;
        rtb_MultiportSwitch[7] = rtb_ixk_k;
        rtb_MultiportSwitch[8] = beta;

        /* SignalConversion generated from: '<S267>/Matrix Concatenate' incorporates:
         *  Constant: '<S267>/Constant8'
         *  Gain: '<S267>/Gain'
         */
        rtb_MultiportSwitch[3] = Mainframe_P.Constant8_Value_o;
        rtb_MultiportSwitch[4] = beta;
        rtb_MultiportSwitch[5] = Mainframe_P.Gain_Gain_kc * rtb_ixk_k;

        /* SignalConversion generated from: '<S267>/Matrix Concatenate' incorporates:
         *  Constant: '<S267>/Constant'
         *  Constant: '<S267>/Constant1'
         *  Constant: '<S267>/Constant2'
         */
        rtb_MultiportSwitch[0] = Mainframe_P.Constant_Value_dt;
        rtb_MultiportSwitch[1] = Mainframe_P.Constant1_Value_g;
        rtb_MultiportSwitch[2] = Mainframe_P.Constant2_Value_g;
        break;

       case 2:
        /* Trigonometry: '<S268>/Trigonometric Function3' incorporates:
         *  Constant: '<S262>/Thrust_rot_z'
         *  Trigonometry: '<S268>/Trigonometric Function'
         */
        rtb_ixk_k = cos(Mainframe_P.Thrust_rot_z_Value_l);

        /* Trigonometry: '<S268>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/Thrust_rot_z'
         *  Trigonometry: '<S268>/Trigonometric Function2'
         */
        beta = sin(Mainframe_P.Thrust_rot_z_Value_l);

        /* SignalConversion generated from: '<S268>/Matrix Concatenate' incorporates:
         *  Constant: '<S268>/Constant7'
         *  Gain: '<S268>/Gain1'
         *  Trigonometry: '<S268>/Trigonometric Function1'
         *  Trigonometry: '<S268>/Trigonometric Function3'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Gain1_Gain_b * beta;
        rtb_MultiportSwitch[7] = Mainframe_P.Constant7_Value_ow;
        rtb_MultiportSwitch[8] = rtb_ixk_k;

        /* SignalConversion generated from: '<S268>/Matrix Concatenate' incorporates:
         *  Constant: '<S268>/Constant'
         *  Constant: '<S268>/Constant1'
         *  Constant: '<S268>/Constant2'
         */
        rtb_MultiportSwitch[3] = Mainframe_P.Constant_Value_d;
        rtb_MultiportSwitch[4] = Mainframe_P.Constant1_Value_p;
        rtb_MultiportSwitch[5] = Mainframe_P.Constant2_Value_b;

        /* SignalConversion generated from: '<S268>/Matrix Concatenate' incorporates:
         *  Constant: '<S268>/Constant8'
         */
        rtb_MultiportSwitch[0] = rtb_ixk_k;
        rtb_MultiportSwitch[1] = Mainframe_P.Constant8_Value_c0;
        rtb_MultiportSwitch[2] = beta;
        break;

       default:
        /* SignalConversion generated from: '<S269>/Matrix Concatenate' incorporates:
         *  Constant: '<S269>/Constant10'
         *  Constant: '<S269>/Constant11'
         *  Constant: '<S269>/Constant4'
         */
        rtb_MultiportSwitch[6] = Mainframe_P.Constant4_Value_h;
        rtb_MultiportSwitch[7] = Mainframe_P.Constant10_Value_a;
        rtb_MultiportSwitch[8] = Mainframe_P.Constant11_Value_lo;

        /* Trigonometry: '<S269>/Trigonometric Function1' incorporates:
         *  Constant: '<S262>/Thrust_rot_z'
         *  Trigonometry: '<S269>/Trigonometric Function4'
         */
        rtb_ixk_k = sin(Mainframe_P.Thrust_rot_z_Value_l);

        /* Trigonometry: '<S269>/Trigonometric Function' incorporates:
         *  Constant: '<S262>/Thrust_rot_z'
         *  Trigonometry: '<S269>/Trigonometric Function3'
         */
        beta = cos(Mainframe_P.Thrust_rot_z_Value_l);

        /* SignalConversion generated from: '<S269>/Matrix Concatenate' incorporates:
         *  Constant: '<S269>/Constant7'
         *  Trigonometry: '<S269>/Trigonometric Function'
         *  Trigonometry: '<S269>/Trigonometric Function1'
         */
        rtb_MultiportSwitch[3] = rtb_ixk_k;
        rtb_MultiportSwitch[4] = beta;
        rtb_MultiportSwitch[5] = Mainframe_P.Constant7_Value_ah;

        /* SignalConversion generated from: '<S269>/Matrix Concatenate' incorporates:
         *  Constant: '<S269>/Constant8'
         *  Gain: '<S269>/Gain'
         */
        rtb_MultiportSwitch[0] = beta;
        rtb_MultiportSwitch[1] = Mainframe_P.Gain_Gain_ib * rtb_ixk_k;
        rtb_MultiportSwitch[2] = Mainframe_P.Constant8_Value_my;
        break;
      }

      /* End of MultiPortSwitch: '<S266>/Multiport Switch' */

      /* Product: '<S266>/3. Rotation' */
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

      /* End of Product: '<S266>/3. Rotation' */

      /* Sum: '<S261>/Subtract' incorporates:
       *  Constant: '<S261>/Constant16'
       *  Constant: '<S261>/Constant17'
       */
      for (i = 0; i < 9; i++) {
        Mainframe_B.Subtract_k[i] = Mainframe_P.Constant17_Value_c[i] -
          Mainframe_P.Constant16_Value_g[i];
      }

      /* End of Sum: '<S261>/Subtract' */

      /* Sum: '<S261>/Subtract4' incorporates:
       *  Constant: '<S261>/Constant18'
       *  Constant: '<S261>/Constant19'
       */
      Mainframe_B.Subtract4 = Mainframe_P.Constant19_Value -
        Mainframe_P.Constant18_Value;

      /* Math: '<S262>/Math Function' */
      for (i = 0; i < 3; i++) {
        Mainframe_B.MathFunction[3 * i] = Mainframe_B.T12_a[i];
        Mainframe_B.MathFunction[3 * i + 1] = Mainframe_B.T12_a[i + 3];
        Mainframe_B.MathFunction[3 * i + 2] = Mainframe_B.T12_a[i + 6];
      }

      /* End of Math: '<S262>/Math Function' */
    }

    /* Sum: '<S261>/Subtract5' incorporates:
     *  Constant: '<S261>/Constant20'
     */
    rtb_T_sim_glbl = rtb_TrigonometricFunction1_j - Mainframe_P.Constant20_Value;

    /* Sum: '<S261>/Subtract6' incorporates:
     *  Constant: '<S261>/Constant21'
     *  Product: '<S261>/Divide'
     */
    for (i = 0; i < 9; i++) {
      rtb_MultiportSwitch1[i] = rtb_T_sim_glbl * Mainframe_B.Subtract_k[i] /
        Mainframe_B.Subtract4 + Mainframe_P.Constant21_Value[i];
    }

    /* End of Sum: '<S261>/Subtract6' */
    for (i = 0; i < 3; i++) {
      /* Product: '<S262>/Matrix Multiply' */
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

      /* End of Product: '<S262>/Matrix Multiply' */

      /* Sum: '<S263>/Add7' incorporates:
       *  Constant: '<S263>/Constant16'
       *  Product: '<S262>/Matrix Multiply1'
       *  Product: '<S265>/Product'
       *  Sum: '<S260>/Add'
       *  Sum: '<S260>/Add4'
       */
      for (idx = 0; idx < 3; idx++) {
        /* Product: '<S265>/Product' incorporates:
         *  Constant: '<S263>/Constant16'
         *  Product: '<S262>/Matrix Multiply1'
         *  Sum: '<S260>/Add4'
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

      /* End of Sum: '<S263>/Add7' */
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S124>/Gain' incorporates:
       *  Constant: '<S124>/Constant'
       */
      Mainframe_B.pAPB[0] = Mainframe_P.Gain_Gain_kk *
        Mainframe_P.Constant_Value_mx;

      /* SignalConversion generated from: '<S124>/Vector Concatenate' incorporates:
       *  Constant: '<S124>/Constant3'
       */
      Mainframe_B.pAPB[1] = Mainframe_P.Constant3_Value_pw;

      /* SignalConversion generated from: '<S124>/Vector Concatenate' incorporates:
       *  Constant: '<S124>/Constant3'
       */
      Mainframe_B.pAPB[2] = Mainframe_P.Constant3_Value_pw;

      /* Switch: '<S132>/Switch1' incorporates:
       *  Constant: '<S132>/Constant'
       *  Constant: '<S132>/Constant2'
       *  Constant: '<S133>/c_flat'
       *  Constant: '<S133>/c_rsma'
       *  Constant: '<S134>/Constant'
       *  Gain: '<S132>/Gain'
       *  Gain: '<S134>/Gain'
       *  Product: '<S134>/Product'
       *  Product: '<S134>/Product4'
       *  Product: '<S134>/Product5'
       *  Sqrt: '<S134>/Sqrt1'
       *  Sum: '<S134>/Subtract'
       *  Sum: '<S134>/Subtract1'
       *  Sum: '<S134>/Sum'
       *  Trigonometry: '<S134>/cos(latGD)'
       */
      if (Mainframe_P.Constant2_Value_je > Mainframe_P.Switch1_Threshold_m) {
        Mainframe_B.hBE_0_c = Mainframe_P.Gain_Gain_bf *
          Mainframe_P.Constant_Value_ixx[2];
      } else {
        /* Sqrt: '<S135>/Sqrt' incorporates:
         *  Constant: '<S132>/Constant'
         *  Product: '<S135>/Product1'
         *  Product: '<S135>/Product2'
         *  Sqrt: '<S134>/Sqrt'
         *  Sum: '<S135>/Add'
         */
        rtb_T_sim_glbl = sqrt(Mainframe_P.Constant_Value_ixx[0] *
                              Mainframe_P.Constant_Value_ixx[0] +
                              Mainframe_P.Constant_Value_ixx[1] *
                              Mainframe_P.Constant_Value_ixx[1]);

        /* Product: '<S135>/Product' incorporates:
         *  Constant: '<S133>/c_flat'
         *  Constant: '<S133>/c_rsma'
         *  Constant: '<S135>/Constant'
         *  Sum: '<S135>/Subtract'
         */
        rtb_TrigonometricFunction1_j = (Mainframe_P.Constant_Value_k -
          Mainframe_P.c_flat_Value_k) * Mainframe_P.c_rsma_Value_j;

        /* Trigonometry: '<S135>/Trigonometric Function' incorporates:
         *  Constant: '<S132>/Constant'
         *  Constant: '<S133>/c_rsma'
         *  Product: '<S135>/Divide1'
         *  Product: '<S135>/Product6'
         *  Product: '<S135>/Product7'
         *  Sqrt: '<S135>/Sqrt'
         */
        rtb_Product2_l = atan(Mainframe_P.Constant_Value_ixx[2] *
                              Mainframe_P.c_rsma_Value_j / (rtb_T_sim_glbl *
          rtb_TrigonometricFunction1_j));

        /* Trigonometry: '<S135>/Trigonometric Function3' */
        rtb_ixk_k = cos(rtb_Product2_l);

        /* Product: '<S135>/Product9' */
        beta = rtb_ixk_k * rtb_ixk_k * rtb_ixk_k;

        /* Trigonometry: '<S135>/Trigonometric Function2' */
        rtb_Product2_l = sin(rtb_Product2_l);

        /* Product: '<S135>/Product5' */
        rtb_ixk_k = rtb_TrigonometricFunction1_j * rtb_TrigonometricFunction1_j;

        /* Product: '<S135>/Product10' incorporates:
         *  Constant: '<S133>/c_rsma'
         *  Product: '<S135>/Divide'
         *  Product: '<S135>/Product4'
         *  Product: '<S135>/Product8'
         *  Sum: '<S135>/Subtract2'
         */
        rtb_TrigonometricFunction1_j = (Mainframe_P.c_rsma_Value_j *
          Mainframe_P.c_rsma_Value_j - rtb_ixk_k) / rtb_ixk_k *
          rtb_TrigonometricFunction1_j * (rtb_Product2_l * rtb_Product2_l *
          rtb_Product2_l);

        /* Sum: '<S135>/Add1' incorporates:
         *  Constant: '<S132>/Constant'
         */
        rtb_TrigonometricFunction1_j += Mainframe_P.Constant_Value_ixx[2];

        /* Product: '<S135>/Product3' incorporates:
         *  Constant: '<S133>/c_flat'
         *  Product: '<S134>/Product3'
         */
        rtb_VectorConcatenate3_tmp = Mainframe_P.c_flat_Value_k *
          Mainframe_P.c_flat_Value_k;

        /* Trigonometry: '<S135>/Trigonometric Function1' incorporates:
         *  Constant: '<S133>/c_flat'
         *  Constant: '<S133>/c_rsma'
         *  Gain: '<S135>/Gain'
         *  Product: '<S135>/Divide2'
         *  Product: '<S135>/Product11'
         *  Product: '<S135>/Product3'
         *  Sqrt: '<S135>/Sqrt'
         *  Sum: '<S135>/Subtract1'
         *  Sum: '<S135>/Subtract3'
         */
        rtb_ixk_k = atan(rtb_TrigonometricFunction1_j / (rtb_T_sim_glbl -
          (Mainframe_P.Gain_Gain_ig * Mainframe_P.c_flat_Value_k -
           rtb_VectorConcatenate3_tmp) * Mainframe_P.c_rsma_Value_j * beta));

        /* Trigonometry: '<S134>/Trigonometric Function' */
        rtb_Product2_l = sin(rtb_ixk_k);
        Mainframe_B.hBE_0_c = rtb_T_sim_glbl / cos(rtb_ixk_k) -
          Mainframe_P.c_rsma_Value_j / sqrt(Mainframe_P.Constant_Value_lg -
          (Mainframe_P.Gain_Gain_nm * Mainframe_P.c_flat_Value_k -
           rtb_VectorConcatenate3_tmp) * (rtb_Product2_l * rtb_Product2_l));
      }

      /* End of Switch: '<S132>/Switch1' */

      /* SignalConversion generated from: '<S127>/Vector Concatenate' incorporates:
       *  Constant: '<S127>/Constant3'
       */
      Mainframe_B.VectorConcatenate_h[0] = Mainframe_P.Constant3_Value_b;

      /* SignalConversion generated from: '<S127>/Vector Concatenate' incorporates:
       *  Constant: '<S127>/Constant3'
       */
      Mainframe_B.VectorConcatenate_h[1] = Mainframe_P.Constant3_Value_b;

      /* SignalConversion generated from: '<S127>/Vector Concatenate' incorporates:
       *  Constant: '<S127>/Constant3'
       */
      Mainframe_B.VectorConcatenate_h[2] = Mainframe_P.Constant3_Value_b;
    }

    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     *  Sum: '<S117>/Add'
     *  Sum: '<S117>/Subtract'
     *  Sum: '<S127>/Subtract'
     */
    if ((Mainframe_B.Switch[2] + Mainframe_P.Constant1_Value_k5) -
        Mainframe_B.hBE_0_c > Mainframe_P.Switch_Threshold_j) {
      /* Saturate: '<S253>/Saturation1' */
      if (rtb_Product4_b_idx_3 > Mainframe_P.Saturation1_UpperSat) {
        rtb_Product4_b_idx_3 = Mainframe_P.Saturation1_UpperSat;
      } else {
        if (rtb_Product4_b_idx_3 < Mainframe_P.Saturation1_LowerSat) {
          rtb_Product4_b_idx_3 = Mainframe_P.Saturation1_LowerSat;
        }
      }

      /* End of Saturate: '<S253>/Saturation1' */

      /* Product: '<S253>/Divide1' incorporates:
       *  Constant: '<S253>/Constant1'
       *  Gain: '<S253>/Gain'
       */
      rtb_Product4_b_idx_3 = 1.0 / (Mainframe_P.Gain_Gain_n *
        rtb_Product4_b_idx_3) * Mainframe_P.Constant1_Value_cs;

      /* Product: '<S117>/Product1' incorporates:
       *  Constant: '<S117>/Constant1'
       *  Constant: '<S118>/Constant'
       *  Gain: '<S118>/Gain'
       *  Gain: '<S118>/Gain2'
       *  Product: '<S253>/Product2'
       *  Sum: '<S118>/Sum'
       */
      rtb_afinB[0] = ((Mainframe_P.Gain_Gain_g * rtb_afinB[0] +
                       Mainframe_P.Constant_Value_bp) + rtb_Product4_b_idx_3 *
                      Mainframe_B.x_d[10] * Mainframe_P.Gain2_Gain_e) *
        rtb_Product4_b_idx_2 * Mainframe_P.Constant1_Value_a;
      rtb_TrigonometricFunction1_j = Mainframe_B.pAPB[0] - rtb_Sum1_e[0];

      /* Product: '<S117>/Product1' incorporates:
       *  Constant: '<S117>/Constant1'
       *  Constant: '<S119>/Constant'
       *  Gain: '<S119>/Gain'
       *  Gain: '<S119>/Gain1'
       *  Gain: '<S119>/Gain2'
       *  Product: '<S253>/Product3'
       *  Sum: '<S117>/Subtract'
       *  Sum: '<S119>/Sum'
       */
      rtb_afinB[1] = (((Mainframe_P.Gain1_Gain_k * rtb_Switch_j +
                        Mainframe_P.Constant_Value_ce) + Mainframe_P.Gain_Gain_i
                       * rtb_afinB[1]) + rtb_Product4_b_idx_3 * Mainframe_B.x_d
                      [11] * Mainframe_P.Gain2_Gain_c) * rtb_Product4_b_idx_2 *
        Mainframe_P.Constant1_Value_a;
      rtb_Switch_j = Mainframe_B.pAPB[1] - rtb_Sum1_e[1];

      /* Product: '<S117>/Product1' incorporates:
       *  Constant: '<S117>/Constant1'
       *  Constant: '<S120>/Constant'
       *  Gain: '<S120>/Gain'
       *  Gain: '<S120>/Gain1'
       *  Gain: '<S120>/Gain2'
       *  Product: '<S253>/Product4'
       *  Sum: '<S117>/Subtract'
       *  Sum: '<S120>/Sum'
       */
      rtb_afinB[2] = (((Mainframe_P.Gain1_Gain * rtb_Product4_b_idx_1 +
                        Mainframe_P.Constant_Value_f1) + Mainframe_P.Gain_Gain_p
                       * rtb_afinB[2]) + rtb_Product4_b_idx_3 * Mainframe_B.x_d
                      [12] * Mainframe_P.Gain2_Gain) * rtb_Product4_b_idx_2 *
        Mainframe_P.Constant1_Value_a;

      /* Sum: '<S117>/Subtract' */
      q0_tmp = Mainframe_B.pAPB[2] - rtb_Sum1_e[2];

      /* Sum: '<S125>/Sum2' incorporates:
       *  Product: '<S125>/Product6'
       *  Product: '<S125>/Product7'
       */
      rtb_VectorConcatenate_m[2] = rtb_TrigonometricFunction1_j * rtb_wEIE[1] -
        rtb_Switch_j * rtb_wEIE[0];

      /* Sum: '<S125>/Sum1' incorporates:
       *  Product: '<S125>/Product4'
       *  Product: '<S125>/Product5'
       */
      rtb_VectorConcatenate_m[1] = q0_tmp * rtb_wEIE[0] -
        rtb_TrigonometricFunction1_j * rtb_wEIE[2];

      /* Sum: '<S125>/Sum' incorporates:
       *  Product: '<S125>/Product2'
       *  Product: '<S125>/Product3'
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

    /* End of Switch: '<S127>/Switch' */

    /* Sum: '<S197>/Subtract' incorporates:
     *  Constant: '<S197>/pNPB'
     */
    rtb_Sum1_e[0] -= Mainframe_P.pNPB_Value[0];
    rtb_Sum1_e[1] -= Mainframe_P.pNPB_Value[1];
    rtb_TrigonometricFunction1_j = rtb_Sum1_e[2] - Mainframe_P.pNPB_Value[2];

    /* Sum: '<S199>/Sum' incorporates:
     *  Product: '<S199>/Product2'
     *  Product: '<S199>/Product3'
     */
    rtb_afinB[0] = rtb_Sum1_e[1] * rtb_u2[2] - rtb_TrigonometricFunction1_j *
      rtb_u2[1];

    /* Sum: '<S199>/Sum1' incorporates:
     *  Product: '<S199>/Product4'
     *  Product: '<S199>/Product5'
     */
    rtb_afinB[1] = rtb_TrigonometricFunction1_j * rtb_u2[0] - rtb_Sum1_e[0] *
      rtb_u2[2];

    /* Sum: '<S199>/Sum2' incorporates:
     *  Product: '<S199>/Product6'
     *  Product: '<S199>/Product7'
     */
    rtb_afinB[2] = rtb_Sum1_e[0] * rtb_u2[1] - rtb_Sum1_e[1] * rtb_u2[0];

    /* Product: '<S242>/Product1' */
    for (i = 0; i < 3; i++) {
      rtb_u2[i] = rtb_MultiportSwitch[i + 6] * Mainframe_B.x_d[12] +
        (rtb_MultiportSwitch[i + 3] * Mainframe_B.x_d[11] +
         rtb_MultiportSwitch[i] * Mainframe_B.x_d[10]);
    }

    /* End of Product: '<S242>/Product1' */

    /* Sum: '<S245>/Sum' incorporates:
     *  Product: '<S245>/Product2'
     *  Product: '<S245>/Product3'
     */
    rtb_Sum1_e[0] = Mainframe_B.x_d[11] * rtb_u2[2] - Mainframe_B.x_d[12] *
      rtb_u2[1];

    /* Sum: '<S245>/Sum1' incorporates:
     *  Product: '<S245>/Product4'
     *  Product: '<S245>/Product5'
     */
    rtb_Sum1_e[1] = Mainframe_B.x_d[12] * rtb_u2[0] - Mainframe_B.x_d[10] *
      rtb_u2[2];

    /* Sum: '<S245>/Sum2' incorporates:
     *  Product: '<S245>/Product6'
     *  Product: '<S245>/Product7'
     */
    rtb_Sum1_e[2] = Mainframe_B.x_d[10] * rtb_u2[1] - Mainframe_B.x_d[11] *
      rtb_u2[0];

    /* Sum: '<S242>/Subtract' incorporates:
     *  Constant: '<S210>/Constant9'
     *  Product: '<S242>/Product'
     *  Sum: '<S106>/Add1'
     */
    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate_fo[i] = ((rtb_VectorConcatenate_m[i] + rtb_afinB[i])
        - ((Mainframe_P.Constant9_Value_l[i + 3] * Mainframe_B.x_d[11] +
            Mainframe_P.Constant9_Value_l[i] * Mainframe_B.x_d[10]) +
           Mainframe_P.Constant9_Value_l[i + 6] * Mainframe_B.x_d[12])) -
        rtb_Sum1_e[i];
    }

    /* End of Sum: '<S242>/Subtract' */

    /* Product: '<S242>/Divide1' */
    rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf(rtb_MultiportSwitch,
      rtb_VectorConcatenate_fo, rtb_u2);

    /* Reshape: '<S240>/Reshape1' */
    Mainframe_B.d_wBIB[0] = rtb_u2[0];

    /* Gain: '<S83>/Zero-Order Hold3' */
    rtb_Sum1_e[0] = Mainframe_P.ZeroOrderHold3_Gain * Mainframe_B.d_wBIB[0];

    /* Reshape: '<S240>/Reshape1' */
    Mainframe_B.d_wBIB[1] = rtb_u2[1];

    /* Gain: '<S83>/Zero-Order Hold3' */
    rtb_Sum1_e[1] = Mainframe_P.ZeroOrderHold3_Gain * Mainframe_B.d_wBIB[1];

    /* Reshape: '<S240>/Reshape1' */
    Mainframe_B.d_wBIB[2] = rtb_u2[2];

    /* Gain: '<S83>/Zero-Order Hold3' */
    rtb_Sum1_e[2] = Mainframe_P.ZeroOrderHold3_Gain * Mainframe_B.d_wBIB[2];

    /* Sum: '<S83>/Sum' incorporates:
     *  Gain: '<S83>/Zero-Order Hold1'
     *  Product: '<S97>/i x j'
     *  Product: '<S97>/j x k'
     *  Product: '<S97>/k x i'
     *  Product: '<S98>/i x k'
     *  Product: '<S98>/j x i'
     *  Product: '<S98>/k x j'
     *  Sum: '<S88>/Sum'
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

    /* Gain: '<S90>/wn^2' */
    rtb_T_sim_glbl = Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a;

    /* Switch: '<S85>/Switch' incorporates:
     *  Constant: '<S85>/Constant'
     */
    tmp_0 = (Mainframe_P.Constant_Value_fd >= Mainframe_P.Switch_Threshold_p);
    for (i = 0; i < 3; i++) {
      /* Sum: '<S90>/Sum3' */
      rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[i];

      /* Sum: '<S83>/Sum4' incorporates:
       *  Constant: '<S83>/Measurement bias'
       *  Constant: '<S83>/Scale factors & Cross-coupling  errors'
       *  Product: '<S83>/Product'
       */
      rtb_TrigonometricFunction1_j =
        ((Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i + 3] *
          rtb_Sum4[1] + Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i] *
          rtb_Sum4[0]) + Mainframe_P.ThreeaxisInertialMeasurementUnit_a_sf_cc[i
         + 6] * rtb_Switch_j) +
        Mainframe_P.ThreeaxisInertialMeasurementUnit_a_bias[i];

      /* Sum: '<S90>/Sum2' incorporates:
       *  Gain: '<S90>/wn^2'
       *  Sum: '<S90>/Sum3'
       */
      Mainframe_B.Sum2_b[i] = (rtb_TrigonometricFunction1_j -
        rtb_IntegratorSecondOrderLimited_o2_a[i]) * rtb_T_sim_glbl -
        rtb_uzetawn_p[i];

      /* Switch: '<S85>/Switch' */
      if (!tmp_0) {
        rtb_ixk_k = rtb_TrigonometricFunction1_j;
      }

      rtb_IntegratorSecondOrderLimited_o2_a[i] = rtb_ixk_k;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
      /* Sqrt: '<S86>/Sqrt1' incorporates:
       *  Constant: '<S86>/Constant1'
       */
      rtb_Switch_j = sqrt(Mainframe_P.Randombias_Ts);

      /* Product: '<S86>/Product' incorporates:
       *  Constant: '<S86>/Constant'
       *  Product: '<S86>/Divide'
       *  RandomNumber: '<S86>/White Noise'
       *  Sqrt: '<S86>/Sqrt'
       */
      Mainframe_B.Product_k[0] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow[0])
        / rtb_Switch_j * Mainframe_DW.NextOutput_mb[0];
      Mainframe_B.Product_k[1] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow[1])
        / rtb_Switch_j * Mainframe_DW.NextOutput_mb[1];
      Mainframe_B.Product_k[2] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow[2])
        / rtb_Switch_j * Mainframe_DW.NextOutput_mb[2];
    }

    /* Gain: '<S102>/2*zeta * wn' */
    rtb_T_sim_glbl = 2.0 * Mainframe_P.ThreeaxisInertialMeasurementUnit_z_g *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g;

    /* Sum: '<S83>/Sum1' */
    rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[0] +
      Mainframe_B.Product_k[0];

    /* Saturate: '<S83>/Saturation' */
    if (rtb_ixk_k > Mainframe_P.Saturation_UpperSat_j[0]) {
      Mainframe_B.Saturation_j[0] = Mainframe_P.Saturation_UpperSat_j[0];
    } else if (rtb_ixk_k < Mainframe_P.Saturation_LowerSat_p[0]) {
      Mainframe_B.Saturation_j[0] = Mainframe_P.Saturation_LowerSat_p[0];
    } else {
      Mainframe_B.Saturation_j[0] = rtb_ixk_k;
    }

    /* SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
    rtb_Sum4[0] = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[0];

    /* Gain: '<S102>/2*zeta * wn' incorporates:
     *  SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited'
     */
    rtb_wEIE[0] = rtb_T_sim_glbl *
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[3];

    /* Sum: '<S83>/Sum1' incorporates:
     *  Gain: '<S84>/Zero-Order Hold'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[0] = Mainframe_P.ZeroOrderHold_Gain_k *
      Mainframe_B.x_d[10];
    rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[1] +
      Mainframe_B.Product_k[1];

    /* Saturate: '<S83>/Saturation' */
    if (rtb_ixk_k > Mainframe_P.Saturation_UpperSat_j[1]) {
      Mainframe_B.Saturation_j[1] = Mainframe_P.Saturation_UpperSat_j[1];
    } else if (rtb_ixk_k < Mainframe_P.Saturation_LowerSat_p[1]) {
      Mainframe_B.Saturation_j[1] = Mainframe_P.Saturation_LowerSat_p[1];
    } else {
      Mainframe_B.Saturation_j[1] = rtb_ixk_k;
    }

    /* SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
    rtb_Sum4[1] = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[1];

    /* Gain: '<S102>/2*zeta * wn' incorporates:
     *  SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited'
     */
    rtb_wEIE[1] = rtb_T_sim_glbl *
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[4];

    /* Sum: '<S83>/Sum1' incorporates:
     *  Gain: '<S84>/Zero-Order Hold'
     */
    rtb_IntegratorSecondOrderLimited_o2_a[1] = Mainframe_P.ZeroOrderHold_Gain_k *
      Mainframe_B.x_d[11];
    rtb_ixk_k = rtb_IntegratorSecondOrderLimited_o2_a[2] +
      Mainframe_B.Product_k[2];

    /* Saturate: '<S83>/Saturation' */
    if (rtb_ixk_k > Mainframe_P.Saturation_UpperSat_j[2]) {
      Mainframe_B.Saturation_j[2] = Mainframe_P.Saturation_UpperSat_j[2];
    } else if (rtb_ixk_k < Mainframe_P.Saturation_LowerSat_p[2]) {
      Mainframe_B.Saturation_j[2] = Mainframe_P.Saturation_LowerSat_p[2];
    } else {
      Mainframe_B.Saturation_j[2] = rtb_ixk_k;
    }

    /* SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
    rtb_Sum4[2] = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[2];

    /* Gain: '<S102>/2*zeta * wn' incorporates:
     *  SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited'
     */
    rtb_wEIE[2] = rtb_T_sim_glbl *
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[5];

    /* Gain: '<S84>/Zero-Order Hold' */
    rtb_ixk_k = Mainframe_P.ZeroOrderHold_Gain_k * Mainframe_B.x_d[12];

    /* Gain: '<S102>/wn^2' */
    rtb_T_sim_glbl = Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g *
      Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g;

    /* Switch: '<S99>/Switch' incorporates:
     *  Constant: '<S99>/Constant'
     */
    tmp_0 = (Mainframe_P.Constant_Value_p3 >= Mainframe_P.Switch_Threshold_i0);
    for (i = 0; i < 3; i++) {
      /* Sum: '<S102>/Sum3' */
      rtb_Switch_j = rtb_Sum4[i];

      /* Sum: '<S84>/Sum4' incorporates:
       *  Constant: '<S84>/Measurement bias'
       *  Constant: '<S84>/Scale factors & Cross-coupling  errors '
       *  Constant: '<S84>/g-sensitive bias'
       *  Gain: '<S84>/Zero-Order Hold1'
       *  Product: '<S84>/Product'
       *  Product: '<S84>/Product1'
       *  UnitConversion: '<S82>/Unit Conversion'
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

      /* Sum: '<S102>/Sum2' incorporates:
       *  Gain: '<S102>/wn^2'
       *  Sum: '<S102>/Sum3'
       */
      Mainframe_B.Sum2_h[i] = (rtb_TrigonometricFunction1_j - rtb_Sum4[i]) *
        rtb_T_sim_glbl - rtb_wEIE[i];

      /* Switch: '<S99>/Switch' */
      if (!tmp_0) {
        rtb_Switch_j = rtb_TrigonometricFunction1_j;
      }

      rtb_Sum4[i] = rtb_Switch_j;
    }

    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
      /* Sqrt: '<S100>/Sqrt1' incorporates:
       *  Constant: '<S100>/Constant1'
       */
      rtb_Switch_j = sqrt(Mainframe_P.Randombias_Ts_n);

      /* Product: '<S100>/Product' incorporates:
       *  Constant: '<S100>/Constant'
       *  Product: '<S100>/Divide'
       *  RandomNumber: '<S100>/White Noise'
       *  Sqrt: '<S100>/Sqrt'
       */
      Mainframe_B.Product_g[0] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow[0]) /
        rtb_Switch_j * Mainframe_DW.NextOutput_i[0];
      Mainframe_B.Product_g[1] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow[1]) /
        rtb_Switch_j * Mainframe_DW.NextOutput_i[1];
      Mainframe_B.Product_g[2] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow[2]) /
        rtb_Switch_j * Mainframe_DW.NextOutput_i[2];
    }

    /* Sum: '<S84>/Sum1' */
    rtb_Switch_j = rtb_Sum4[0] + Mainframe_B.Product_g[0];

    /* Saturate: '<S84>/Saturation' */
    if (rtb_Switch_j > Mainframe_P.Saturation_UpperSat_pp[0]) {
      Mainframe_B.Saturation_je[0] = Mainframe_P.Saturation_UpperSat_pp[0];
    } else if (rtb_Switch_j < Mainframe_P.Saturation_LowerSat_ga[0]) {
      Mainframe_B.Saturation_je[0] = Mainframe_P.Saturation_LowerSat_ga[0];
    } else {
      Mainframe_B.Saturation_je[0] = rtb_Switch_j;
    }

    /* Sum: '<S84>/Sum1' */
    rtb_Switch_j = rtb_Sum4[1] + Mainframe_B.Product_g[1];

    /* Saturate: '<S84>/Saturation' */
    if (rtb_Switch_j > Mainframe_P.Saturation_UpperSat_pp[1]) {
      Mainframe_B.Saturation_je[1] = Mainframe_P.Saturation_UpperSat_pp[1];
    } else if (rtb_Switch_j < Mainframe_P.Saturation_LowerSat_ga[1]) {
      Mainframe_B.Saturation_je[1] = Mainframe_P.Saturation_LowerSat_ga[1];
    } else {
      Mainframe_B.Saturation_je[1] = rtb_Switch_j;
    }

    /* Sum: '<S84>/Sum1' */
    rtb_Switch_j = rtb_Sum4[2] + Mainframe_B.Product_g[2];

    /* Saturate: '<S84>/Saturation' */
    if (rtb_Switch_j > Mainframe_P.Saturation_UpperSat_pp[2]) {
      Mainframe_B.Saturation_je[2] = Mainframe_P.Saturation_UpperSat_pp[2];
    } else if (rtb_Switch_j < Mainframe_P.Saturation_LowerSat_ga[2]) {
      Mainframe_B.Saturation_je[2] = Mainframe_P.Saturation_LowerSat_ga[2];
    } else {
      Mainframe_B.Saturation_je[2] = rtb_Switch_j;
    }

    /* RelationalOperator: '<S140>/Compare' incorporates:
     *  Constant: '<S140>/Constant'
     */
    Mainframe_B.Compare = (rtb_Sqrt_cv >= Mainframe_P.CompareToConstant_const);
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Assertion: '<S137>/Assertion' */
      utAssert(Mainframe_B.Compare);
    }

    /* Logic: '<S141>/AND' incorporates:
     *  Constant: '<S141>/Lower Limit'
     *  Constant: '<S141>/Upper Limit'
     *  RelationalOperator: '<S141>/Lower Test'
     *  RelationalOperator: '<S141>/Upper Test'
     */
    Mainframe_B.AND_c = ((Mainframe_P.IntervalTest_lowlimit <=
                          Mainframe_B.Switch[0]) && (Mainframe_B.Switch[0] <=
      Mainframe_P.IntervalTest_uplimit));
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Assertion: '<S137>/Assertion1' */
      utAssert(Mainframe_B.AND_c);
    }

    /* Logic: '<S142>/AND' incorporates:
     *  Constant: '<S142>/Lower Limit'
     *  Constant: '<S142>/Upper Limit'
     *  RelationalOperator: '<S142>/Lower Test'
     *  RelationalOperator: '<S142>/Upper Test'
     */
    Mainframe_B.AND_cl = ((Mainframe_P.IntervalTest1_lowlimit <=
      Mainframe_B.Switch[1]) && (Mainframe_B.Switch[1] <=
      Mainframe_P.IntervalTest1_uplimit));
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Assertion: '<S137>/Assertion2' */
      utAssert(Mainframe_B.AND_cl);
    }

    /* Integrator: '<S153>/Integrator' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                         &Mainframe_PrevZCX.Integrator_Reset_ZCE,
                         (Mainframe_B.sat));

      /* evaluate zero-crossings */
      if (zcEvent != NO_ZCEVENT) {
        Mainframe_X.Integrator_CSTATE_j = Mainframe_P.Rudder_d_siB_0;
      }
    }

    rtb_d_siB = Mainframe_X.Integrator_CSTATE_j;

    /* End of Integrator: '<S153>/Integrator' */

    /* MATLAB Function: '<S153>/Limiting_Rate' */
    Mainframe_Limiting_Rate(rtb_siB, rtb_d_siB, &Mainframe_B.sf_Limiting_Rate,
      Mainframe_P.Rudder_d_siB_max, Mainframe_P.Rudder_d_siB_min,
      Mainframe_P.Rudder_siB_max, Mainframe_P.Rudder_siB_min);

    /* Integrator: '<S154>/Integrator' */
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

    /* End of Integrator: '<S154>/Integrator' */

    /* MATLAB Function: '<S154>/Limiting_Rate' */
    Mainframe_Limiting_Rate(rtb_siB_a, rtb_d_siB_g,
      &Mainframe_B.sf_Limiting_Rate_g, Mainframe_P.Rudder1_d_siB_max,
      Mainframe_P.Rudder1_d_siB_min, Mainframe_P.Rudder1_siB_max,
      Mainframe_P.Rudder1_siB_min);

    /* Integrator: '<S155>/Integrator' */
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

    /* End of Integrator: '<S155>/Integrator' */

    /* MATLAB Function: '<S155>/Limiting_Rate' */
    Mainframe_Limiting_Rate(rtb_siB_e, rtb_d_siB_j,
      &Mainframe_B.sf_Limiting_Rate_a, Mainframe_P.Rudder2_d_siB_max,
      Mainframe_P.Rudder2_d_siB_min, Mainframe_P.Rudder2_siB_max,
      Mainframe_P.Rudder2_siB_min);

    /* Integrator: '<S156>/Integrator' */
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

    /* End of Integrator: '<S156>/Integrator' */

    /* MATLAB Function: '<S156>/Limiting_Rate' */
    Mainframe_Limiting_Rate(rtb_siB_i, rtb_d_siB_b,
      &Mainframe_B.sf_Limiting_Rate_o, Mainframe_P.Rudder3_d_siB_max,
      Mainframe_P.Rudder3_d_siB_min, Mainframe_P.Rudder3_siB_max,
      Mainframe_P.Rudder3_siB_min);

    /* Saturate: '<S153>/Saturation' */
    if (rtb_VectorConcatenate_hw[0] > Mainframe_P.Rudder_siB_max) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder_siB_max;
    } else if (rtb_VectorConcatenate_hw[0] < Mainframe_P.Rudder_siB_min) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder_siB_min;
    } else {
      rtb_TrigonometricFunction1_j = rtb_VectorConcatenate_hw[0];
    }

    /* End of Saturate: '<S153>/Saturation' */

    /* Sum: '<S153>/Add1' incorporates:
     *  Gain: '<S153>/Gain'
     *  Gain: '<S153>/Gain2'
     *  Integrator: '<S153>/Integrator1'
     *  Sum: '<S153>/Add'
     */
    rtb_dd_siB = (rtb_TrigonometricFunction1_j - Mainframe_X.Integrator1_CSTATE)
      * Mainframe_P.Gain_Gain_cv - 2.0 * Mainframe_P.Rudder_dmp *
      Mainframe_P.Rudder_omega * rtb_d_siB;

    /* MATLAB Function: '<S153>/Limiting_Acceleration' */
    Mainframe_Limiting_Acceleration(rtb_siB,
      Mainframe_B.sf_Limiting_Rate.d_siB_l, rtb_dd_siB,
      &Mainframe_B.sf_Limiting_Acceleration, Mainframe_P.Rudder_d_siB_max,
      Mainframe_P.Rudder_d_siB_min, Mainframe_P.Rudder_dd_siB_max,
      Mainframe_P.Rudder_dd_siB_min, Mainframe_P.Rudder_siB_max,
      Mainframe_P.Rudder_siB_min);

    /* Saturate: '<S154>/Saturation' */
    if (rtb_VectorConcatenate_hw[1] > Mainframe_P.Rudder1_siB_max) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder1_siB_max;
    } else if (rtb_VectorConcatenate_hw[1] < Mainframe_P.Rudder1_siB_min) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder1_siB_min;
    } else {
      rtb_TrigonometricFunction1_j = rtb_VectorConcatenate_hw[1];
    }

    /* End of Saturate: '<S154>/Saturation' */

    /* Sum: '<S154>/Add1' incorporates:
     *  Gain: '<S154>/Gain'
     *  Gain: '<S154>/Gain2'
     *  Integrator: '<S154>/Integrator1'
     *  Sum: '<S154>/Add'
     */
    rtb_dd_siB_h = (rtb_TrigonometricFunction1_j -
                    Mainframe_X.Integrator1_CSTATE_n) * Mainframe_P.Gain_Gain_e
      - 2.0 * Mainframe_P.Rudder1_dmp * Mainframe_P.Rudder1_omega * rtb_d_siB_g;

    /* MATLAB Function: '<S154>/Limiting_Acceleration' */
    Mainframe_Limiting_Acceleration(rtb_siB_a,
      Mainframe_B.sf_Limiting_Rate_g.d_siB_l, rtb_dd_siB_h,
      &Mainframe_B.sf_Limiting_Acceleration_p, Mainframe_P.Rudder1_d_siB_max,
      Mainframe_P.Rudder1_d_siB_min, Mainframe_P.Rudder1_dd_siB_max,
      Mainframe_P.Rudder1_dd_siB_min, Mainframe_P.Rudder1_siB_max,
      Mainframe_P.Rudder1_siB_min);

    /* Saturate: '<S155>/Saturation' */
    if (rtb_VectorConcatenate_hw[2] > Mainframe_P.Rudder2_siB_max) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder2_siB_max;
    } else if (rtb_VectorConcatenate_hw[2] < Mainframe_P.Rudder2_siB_min) {
      rtb_TrigonometricFunction1_j = Mainframe_P.Rudder2_siB_min;
    } else {
      rtb_TrigonometricFunction1_j = rtb_VectorConcatenate_hw[2];
    }

    /* End of Saturate: '<S155>/Saturation' */

    /* Sum: '<S155>/Add1' incorporates:
     *  Gain: '<S155>/Gain'
     *  Gain: '<S155>/Gain2'
     *  Integrator: '<S155>/Integrator1'
     *  Sum: '<S155>/Add'
     */
    rtb_dd_siB_k = (rtb_TrigonometricFunction1_j -
                    Mainframe_X.Integrator1_CSTATE_k) * Mainframe_P.Gain_Gain_ga
      - 2.0 * Mainframe_P.Rudder2_dmp * Mainframe_P.Rudder2_omega * rtb_d_siB_j;

    /* MATLAB Function: '<S155>/Limiting_Acceleration' */
    Mainframe_Limiting_Acceleration(rtb_siB_e,
      Mainframe_B.sf_Limiting_Rate_a.d_siB_l, rtb_dd_siB_k,
      &Mainframe_B.sf_Limiting_Acceleration_l, Mainframe_P.Rudder2_d_siB_max,
      Mainframe_P.Rudder2_d_siB_min, Mainframe_P.Rudder2_dd_siB_max,
      Mainframe_P.Rudder2_dd_siB_min, Mainframe_P.Rudder2_siB_max,
      Mainframe_P.Rudder2_siB_min);

    /* Saturate: '<S156>/Saturation' */
    if (rtb_VectorConcatenate_de > Mainframe_P.Rudder3_siB_max) {
      rtb_VectorConcatenate_de = Mainframe_P.Rudder3_siB_max;
    } else {
      if (rtb_VectorConcatenate_de < Mainframe_P.Rudder3_siB_min) {
        rtb_VectorConcatenate_de = Mainframe_P.Rudder3_siB_min;
      }
    }

    /* End of Saturate: '<S156>/Saturation' */

    /* Sum: '<S156>/Add1' incorporates:
     *  Gain: '<S156>/Gain'
     *  Gain: '<S156>/Gain2'
     *  Integrator: '<S156>/Integrator1'
     *  Sum: '<S156>/Add'
     */
    rtb_dd_siB_c = (rtb_VectorConcatenate_de - Mainframe_X.Integrator1_CSTATE_f)
      * Mainframe_P.Gain_Gain_gh - 2.0 * Mainframe_P.Rudder3_dmp *
      Mainframe_P.Rudder3_omega * rtb_d_siB_b;

    /* MATLAB Function: '<S156>/Limiting_Acceleration' */
    Mainframe_Limiting_Acceleration(rtb_siB_i,
      Mainframe_B.sf_Limiting_Rate_o.d_siB_l, rtb_dd_siB_c,
      &Mainframe_B.sf_Limiting_Acceleration_j, Mainframe_P.Rudder3_d_siB_max,
      Mainframe_P.Rudder3_d_siB_min, Mainframe_P.Rudder3_dd_siB_max,
      Mainframe_P.Rudder3_dd_siB_min, Mainframe_P.Rudder3_siB_max,
      Mainframe_P.Rudder3_siB_min);
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Gain: '<S173>/Gain' */
      rtb_wEIE[0] = Mainframe_P.Gain_Gain_ce * Mainframe_B.wIEE[0];
      rtb_wEIE[1] = Mainframe_P.Gain_Gain_ce * Mainframe_B.wIEE[1];
      rtb_wEIE[2] = Mainframe_P.Gain_Gain_ce * Mainframe_B.wIEE[2];

      /* Sum: '<S188>/Add' incorporates:
       *  Constant: '<S188>/Constant8'
       *  Constant: '<S188>/Q_1'
       *  Constant: '<S188>/Q_2'
       *  Constant: '<S188>/Q_3'
       *  Constant: '<S188>/Q_4'
       *  Product: '<S188>/Product1'
       *  Product: '<S188>/Product2'
       *  Product: '<S188>/Product3'
       *  Product: '<S188>/Product4'
       *  SignalConversion generated from: '<S188>/Vector Concatenate'
       * */
      for (i = 0; i < 16; i++) {
        Mainframe_B.Add[i] = ((Mainframe_P.Q_1_Value_a[i] * rtb_wEIE[0] +
          Mainframe_P.Q_2_Value_p[i] * rtb_wEIE[1]) + Mainframe_P.Q_3_Value_f[i]
                              * rtb_wEIE[2]) + Mainframe_P.Q_4_Value_p[i] *
          Mainframe_P.Constant8_Value_km;
      }

      /* End of Sum: '<S188>/Add' */
    }

    /* Gain: '<S190>/Gain1' incorporates:
     *  Integrator: '<S185>/integration_eom'
     */
    rtb_VectorConcatenate_hw[0] = Mainframe_P.Gain1_Gain_k1 *
      Mainframe_X.integration_eom_CSTATE_o[0];
    rtb_VectorConcatenate_hw[1] = Mainframe_P.Gain1_Gain_k1 *
      Mainframe_X.integration_eom_CSTATE_o[1];
    rtb_VectorConcatenate_hw[2] = Mainframe_P.Gain1_Gain_k1 *
      Mainframe_X.integration_eom_CSTATE_o[2];
    for (i = 0; i < 4; i++) {
      /* Product: '<S188>/Product5' incorporates:
       *  Integrator: '<S185>/integration_eom'
       */
      rtb_T_sim_glbl = Mainframe_B.Add[i + 12] *
        Mainframe_X.integration_eom_CSTATE_o[3] + (Mainframe_B.Add[i + 8] *
        rtb_VectorConcatenate_hw[2] + (Mainframe_B.Add[i + 4] *
        rtb_VectorConcatenate_hw[1] + Mainframe_B.Add[i] *
        rtb_VectorConcatenate_hw[0]));

      /* Gain: '<S188>/Gain' */
      rtb_d_qEI[i] = Mainframe_P.Gain_Gain_f * rtb_T_sim_glbl;
    }

    /* SignalConversion generated from: '<S191>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_m[3] = rtb_d_qEI[3];

    /* Gain: '<S191>/Gain1' */
    Mainframe_B.VectorConcatenate_m[0] = Mainframe_P.Gain1_Gain_nr * rtb_d_qEI[0];
    Mainframe_B.VectorConcatenate_m[1] = Mainframe_P.Gain1_Gain_nr * rtb_d_qEI[1];
    Mainframe_B.VectorConcatenate_m[2] = Mainframe_P.Gain1_Gain_nr * rtb_d_qEI[2];
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S187>/Vector Concatenate1' incorporates:
       *  Constant: '<S187>/Constant8'
       */
      Mainframe_B.wEGG[0] = Mainframe_P.Constant8_Value_k2;

      /* SignalConversion generated from: '<S187>/Vector Concatenate1' incorporates:
       *  Constant: '<S187>/Constant8'
       */
      Mainframe_B.wEGG[1] = Mainframe_P.Constant8_Value_k2;

      /* SignalConversion generated from: '<S187>/Vector Concatenate1' incorporates:
       *  Constant: '<S187>/Constant8'
       */
      Mainframe_B.wEGG[2] = Mainframe_P.Constant8_Value_k2;
    }

    /* Derivative: '<S187>/Derivative1' */
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

    /* Derivative: '<S187>/Derivative' */
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

    /* Switch: '<S187>/Switch' incorporates:
     *  Constant: '<S187>/Constant9'
     */
    if (Mainframe_P.Constant9_Value_m > Mainframe_P.Switch_Threshold_m) {
      rtb_Sum4[0] = Mainframe_B.wEGG[0];
      rtb_Sum4[1] = Mainframe_B.wEGG[1];
      rtb_Sum4[2] = Mainframe_B.wEGG[2];
    } else {
      /* Gain: '<S187>/Gain2' incorporates:
       *  Product: '<S187>/Product'
       */
      rtb_Sum4[2] = rtb_lat * rtb_Switch_j * Mainframe_P.Gain2_Gain_f;

      /* Gain: '<S187>/Gain1' */
      rtb_Sum4[1] = Mainframe_P.Gain1_Gain_m * rtb_Product4_b_idx_1;

      /* Product: '<S187>/Product1' */
      rtb_Sum4[0] = rtb_Switch_j * rtb_Sqrt_c;
    }

    /* Gain: '<S173>/Gain1' */
    rtb_Sum4[0] *= Mainframe_P.Gain1_Gain_ge;
    rtb_Sum4[1] *= Mainframe_P.Gain1_Gain_ge;

    /* SignalConversion generated from: '<S192>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_d[0] = rtb_Sum4[0];

    /* SignalConversion generated from: '<S192>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_d[1] = rtb_Sum4[1];

    /* SignalConversion generated from: '<S192>/Vector Concatenate' incorporates:
     *  Gain: '<S173>/Gain1'
     */
    Mainframe_B.VectorConcatenate_d[2] = Mainframe_P.Gain1_Gain_ge * rtb_Sum4[2];
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S192>/Constant8' */
      Mainframe_B.VectorConcatenate_d[3] = Mainframe_P.Constant8_Value_kt;
    }

    /* Gain: '<S194>/Gain1' incorporates:
     *  Integrator: '<S186>/integration_eom'
     */
    rtb_d_qBI[0] = Mainframe_P.Gain1_Gain_p *
      Mainframe_X.integration_eom_CSTATE_k[0];
    rtb_d_qBI[1] = Mainframe_P.Gain1_Gain_p *
      Mainframe_X.integration_eom_CSTATE_k[1];
    rtb_d_qBI[2] = Mainframe_P.Gain1_Gain_p *
      Mainframe_X.integration_eom_CSTATE_k[2];

    /* Sum: '<S192>/Add' incorporates:
     *  Constant: '<S192>/Q_1'
     *  Constant: '<S192>/Q_2'
     *  Constant: '<S192>/Q_3'
     *  Constant: '<S192>/Q_4'
     *  Product: '<S192>/Product1'
     *  Product: '<S192>/Product2'
     *  Product: '<S192>/Product3'
     *  Product: '<S192>/Product4'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_o[i] * Mainframe_B.VectorConcatenate_d[0]
                 + Mainframe_P.Q_2_Value_ca[i] *
                 Mainframe_B.VectorConcatenate_d[1]) + Mainframe_P.Q_3_Value_g[i]
                * Mainframe_B.VectorConcatenate_d[2]) +
        Mainframe_P.Q_4_Value_po[i] * Mainframe_B.VectorConcatenate_d[3];
    }

    /* End of Sum: '<S192>/Add' */
    for (i = 0; i < 4; i++) {
      /* Product: '<S192>/Product5' incorporates:
       *  Integrator: '<S186>/integration_eom'
       */
      rtb_T_sim_glbl = tmp[i + 12] * Mainframe_X.integration_eom_CSTATE_k[3] +
        (tmp[i + 8] * rtb_d_qBI[2] + (tmp[i + 4] * rtb_d_qBI[1] + tmp[i] *
          rtb_d_qBI[0]));

      /* Gain: '<S192>/Gain' */
      rtb_VectorConcatenate_hw[i] = Mainframe_P.Gain_Gain_j * rtb_T_sim_glbl;
    }

    /* SignalConversion generated from: '<S195>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_e[3] = rtb_VectorConcatenate_hw[3];
    for (i = 0; i < 3; i++) {
      /* Gain: '<S195>/Gain1' */
      Mainframe_B.VectorConcatenate_e[i] = Mainframe_P.Gain1_Gain_e *
        rtb_VectorConcatenate_hw[i];

      /* Product: '<S209>/Product1' incorporates:
       *  Math: '<S209>/Math Function'
       */
      Mainframe_B.vBIB[i] = 0.0;
      Mainframe_B.vBIB[i] += rtb_TBI_tmp[i] * Mainframe_B.x_d[3];
      Mainframe_B.vBIB[i] += rtb_TBI_tmp[i + 3] * Mainframe_B.x_d[4];
      Mainframe_B.vBIB[i] += rtb_TBI_tmp[i + 6] * Mainframe_B.x_d[5];
    }

    /* Sum: '<S218>/Add2' incorporates:
     *  Selector: '<S212>/dcm22'
     *  Selector: '<S212>/dcm33'
     *  Sum: '<S219>/Add2'
     */
    rtb_JMMB_tmp_6 = rtb_VectorConcatenate3[4] + rtb_VectorConcatenate3[8];

    /* Sum: '<S218>/Add1' incorporates:
     *  Selector: '<S212>/dcm11'
     *  Selector: '<S212>/dcm33'
     *  Sum: '<S220>/Add1'
     */
    rtb_VectorConcatenate_de = rtb_VectorConcatenate3[0] +
      rtb_VectorConcatenate3[8];

    /* Sum: '<S218>/Add' incorporates:
     *  Selector: '<S212>/dcm11'
     *  Selector: '<S212>/dcm22'
     *  Sum: '<S221>/Add'
     */
    rtb_TrigonometricFunction1_j = rtb_VectorConcatenate3[0] +
      rtb_VectorConcatenate3[4];

    /* Logic: '<S218>/Logical Operator' incorporates:
     *  Constant: '<S227>/Constant'
     *  Constant: '<S228>/Constant'
     *  Constant: '<S229>/Constant'
     *  RelationalOperator: '<S227>/Compare'
     *  RelationalOperator: '<S228>/Compare'
     *  RelationalOperator: '<S229>/Compare'
     *  Sum: '<S218>/Add'
     *  Sum: '<S218>/Add1'
     *  Sum: '<S218>/Add2'
     */
    Mainframe_B.q_R0R = ((rtb_TrigonometricFunction1_j >=
                          Mainframe_P.Constant_Value_g) &&
                         (rtb_VectorConcatenate_de >=
                          Mainframe_P.Constant_Value_ck) && (rtb_JMMB_tmp_6 >=
      Mainframe_P.Constant_Value_o0));

    /* Sum: '<S219>/Add' incorporates:
     *  Selector: '<S212>/dcm11'
     *  Selector: '<S212>/dcm22'
     *  Sum: '<S220>/Add'
     */
    rtb_Switch_j = rtb_VectorConcatenate3[0] - rtb_VectorConcatenate3[4];

    /* Sum: '<S219>/Add1' incorporates:
     *  Selector: '<S212>/dcm11'
     *  Selector: '<S212>/dcm33'
     *  Sum: '<S221>/Add1'
     */
    q0_tmp = rtb_VectorConcatenate3[0] - rtb_VectorConcatenate3[8];

    /* Logic: '<S219>/Logical Operator' incorporates:
     *  Constant: '<S230>/Constant'
     *  Constant: '<S231>/Constant'
     *  Constant: '<S232>/Constant'
     *  RelationalOperator: '<S230>/Compare'
     *  RelationalOperator: '<S231>/Compare'
     *  RelationalOperator: '<S232>/Compare'
     *  Sum: '<S219>/Add'
     *  Sum: '<S219>/Add1'
     */
    Mainframe_B.q_R1R = ((rtb_Switch_j >= Mainframe_P.Constant_Value_pq) &&
                         (q0_tmp >= Mainframe_P.Constant_Value_a) &&
                         (rtb_JMMB_tmp_6 < Mainframe_P.Constant_Value_kz));

    /* Sum: '<S220>/Add2' incorporates:
     *  Selector: '<S212>/dcm22'
     *  Selector: '<S212>/dcm33'
     *  Sum: '<S221>/Add2'
     */
    rtb_JMMB_tmp_6 = rtb_VectorConcatenate3[4] - rtb_VectorConcatenate3[8];

    /* Logic: '<S220>/Logical Operator' incorporates:
     *  Constant: '<S233>/Constant'
     *  Constant: '<S234>/Constant'
     *  Constant: '<S235>/Constant'
     *  RelationalOperator: '<S233>/Compare'
     *  RelationalOperator: '<S234>/Compare'
     *  RelationalOperator: '<S235>/Compare'
     *  Sum: '<S220>/Add2'
     */
    Mainframe_B.q_R2R = ((rtb_Switch_j < Mainframe_P.Constant_Value_do) &&
                         (rtb_VectorConcatenate_de <
                          Mainframe_P.Constant_Value_g4) && (rtb_JMMB_tmp_6 >=
      Mainframe_P.Constant_Value_g1));

    /* Logic: '<S221>/Logical Operator' incorporates:
     *  Constant: '<S236>/Constant'
     *  Constant: '<S237>/Constant'
     *  Constant: '<S238>/Constant'
     *  RelationalOperator: '<S236>/Compare'
     *  RelationalOperator: '<S237>/Compare'
     *  RelationalOperator: '<S238>/Compare'
     */
    Mainframe_B.q_R3R = ((rtb_TrigonometricFunction1_j <
                          Mainframe_P.Constant_Value_gb) && (q0_tmp <
      Mainframe_P.Constant_Value_gf) && (rtb_JMMB_tmp_6 <
      Mainframe_P.Constant_Value_ok));
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* SignalConversion generated from: '<S223>/q_R^0(R) = TRUE' */
      Mainframe_B.HiddenBuf_InsertedFor_q_R0R_at_inport_1 = Mainframe_B.q_R0R;

      /* SignalConversion generated from: '<S224>/q_R^1(R) = TRUE' */
      Mainframe_B.HiddenBuf_InsertedFor_q_R1R_at_inport_1 = Mainframe_B.q_R1R;

      /* SignalConversion generated from: '<S225>/q_R^2(R) = TRUE' */
      Mainframe_B.HiddenBuf_InsertedFor_q_R2R_at_inport_1 = Mainframe_B.q_R2R;

      /* SignalConversion generated from: '<S226>/q_R^3(R) = TRUE' */
      Mainframe_B.HiddenBuf_InsertedFor_q_R3R_at_inport_1 = Mainframe_B.q_R3R;

      /* Outputs for Enabled SubSystem: '<S212>/q_R^0(R)' incorporates:
       *  EnablePort: '<S223>/q_R^0(R) = TRUE'
       */
      if (rtmIsMajorTimeStep(Mainframe_M)) {
        Mainframe_DW.q_R0R_MODE =
          Mainframe_B.HiddenBuf_InsertedFor_q_R0R_at_inport_1;
      }

      /* End of Outputs for SubSystem: '<S212>/q_R^0(R)' */
    }

    /* Outputs for Enabled SubSystem: '<S212>/q_R^0(R)' incorporates:
     *  EnablePort: '<S223>/q_R^0(R) = TRUE'
     */
    if (Mainframe_DW.q_R0R_MODE && rtmIsMajorTimeStep(Mainframe_M)) {
      srUpdateBC(Mainframe_DW.q_R0R_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S212>/q_R^0(R)' */

    /* Outputs for Enabled SubSystem: '<S212>/q_R^1(R)' incorporates:
     *  EnablePort: '<S224>/q_R^1(R) = TRUE'
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

    /* End of Outputs for SubSystem: '<S212>/q_R^1(R)' */

    /* Outputs for Enabled SubSystem: '<S212>/q_R^2(R)' incorporates:
     *  EnablePort: '<S225>/q_R^2(R) = TRUE'
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

    /* End of Outputs for SubSystem: '<S212>/q_R^2(R)' */

    /* Outputs for Enabled SubSystem: '<S212>/q_R^3(R)' incorporates:
     *  EnablePort: '<S226>/q_R^3(R) = TRUE'
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

    /* End of Outputs for SubSystem: '<S212>/q_R^3(R)' */

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[0] = Mainframe_B.x_d[3];

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[3] = rtb_q_conj[0];

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[10] = rtb_u2[0];

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[1] = Mainframe_B.x_d[4];

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[4] = rtb_q_conj[1];

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[11] = rtb_u2[1];

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[2] = Mainframe_B.x_d[5];

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[5] = rtb_q_conj[2];

    /* SignalConversion generated from: '<S240>/Vector Concatenate' */
    Mainframe_B.d_x[12] = rtb_u2[2];

    /* SignalConversion generated from: '<S244>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_f[0] = Mainframe_B.x_d[10];

    /* SignalConversion generated from: '<S244>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_f[1] = Mainframe_B.x_d[11];

    /* SignalConversion generated from: '<S244>/Vector Concatenate' */
    Mainframe_B.VectorConcatenate_f[2] = Mainframe_B.x_d[12];
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      /* Constant: '<S244>/Constant' */
      Mainframe_B.VectorConcatenate_f[3] = Mainframe_P.Constant_Value_cu;
    }

    /* Gain: '<S247>/Gain1' */
    rtb_d_qEI[0] = Mainframe_P.Gain1_Gain_gee * rtb_Product_b_idx_0;
    rtb_d_qEI[1] = Mainframe_P.Gain1_Gain_gee * rtb_Product_b_idx_1;
    rtb_d_qEI[2] = Mainframe_P.Gain1_Gain_gee * rtb_Product_b_idx_2;

    /* Sum: '<S244>/Add' incorporates:
     *  Constant: '<S244>/Q_1'
     *  Constant: '<S244>/Q_2'
     *  Constant: '<S244>/Q_3'
     *  Constant: '<S244>/Q_4'
     *  Product: '<S244>/Product2'
     *  Product: '<S244>/Product3'
     *  Product: '<S244>/Product4'
     *  Product: '<S244>/Product5'
     */
    for (i = 0; i < 16; i++) {
      tmp[i] = ((Mainframe_P.Q_1_Value_ab[i] * Mainframe_B.VectorConcatenate_f[0]
                 + Mainframe_P.Q_2_Value_m[i] * Mainframe_B.VectorConcatenate_f
                 [1]) + Mainframe_P.Q_3_Value_c1[i] *
                Mainframe_B.VectorConcatenate_f[2]) + Mainframe_P.Q_4_Value_gi[i]
        * Mainframe_B.VectorConcatenate_f[3];
    }

    /* End of Sum: '<S244>/Add' */
    for (i = 0; i < 4; i++) {
      /* Product: '<S244>/Product6' */
      rtb_T_sim_glbl = tmp[i + 12] * rtb_Product_d + (tmp[i + 8] * rtb_d_qEI[2]
        + (tmp[i + 4] * rtb_d_qEI[1] + tmp[i] * rtb_d_qEI[0]));

      /* Gain: '<S244>/Gain' */
      rtb_d_qBI[i] = Mainframe_P.Gain_Gain_bs * rtb_T_sim_glbl;
    }

    /* Gain: '<S248>/Gain1' */
    Mainframe_B.d_x[6] = Mainframe_P.Gain1_Gain_nw * rtb_d_qBI[0];
    Mainframe_B.d_x[7] = Mainframe_P.Gain1_Gain_nw * rtb_d_qBI[1];
    Mainframe_B.d_x[8] = Mainframe_P.Gain1_Gain_nw * rtb_d_qBI[2];

    /* SignalConversion generated from: '<S248>/Vector Concatenate' */
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

  /* Gain: '<S22>/Gain' */
  Mainframe_B.Gain_f = Mainframe_P.Gain_Gain_bk * Mainframe_B.ComplextoRealImag
    [1];

  /* Gain: '<S23>/Gain' */
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
    /* Constant: '<S68>/Zero1' */
    Mainframe_B.gimbalPhi = Mainframe_P.Zero1_Value;

    /* Gain: '<S8>/Gain' */
    Mainframe_B.Gain_br = Mainframe_P.Gain_Gain_dy * Mainframe_B.gimbalPhi;

    /* Constant: '<S68>/Zero' */
    Mainframe_B.gimbalTheta = Mainframe_P.Zero_Value;

    /* Gain: '<S13>/Gain' */
    Mainframe_B.Gain_e = Mainframe_P.Gain_Gain_ag * Mainframe_B.gimbalTheta;

    /* Constant: '<S68>/Zero2' */
    Mainframe_B.gimbalPsi = Mainframe_P.Zero2_Value;

    /* Gain: '<S14>/Gain' */
    Mainframe_B.Gain_o = Mainframe_P.Gain_Gain_b4 * Mainframe_B.gimbalPsi;

    /* S-Function (sldrtpi): '<S60>/Packet Input' */
    /* S-Function Block: <S60>/Packet Input */
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

    /* Outputs for Triggered SubSystem: '<S60>/Enabled Subsystem' incorporates:
     *  TriggerPort: '<S61>/Trigger'
     */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      if (Mainframe_B.PacketInput_o2 &&
          (Mainframe_PrevZCX.EnabledSubsystem_Trig_ZCE != POS_ZCSIG)) {
        /* Inport: '<S61>/In1' */
        memcpy(&Mainframe_B.In1[0], &Mainframe_B.PacketInput_o1[0], 75U * sizeof
               (uint8_T));
        Mainframe_DW.EnabledSubsystem_SubsysRanBC = 4;
      }

      Mainframe_PrevZCX.EnabledSubsystem_Trig_ZCE = Mainframe_B.PacketInput_o2;
    }

    /* End of Outputs for SubSystem: '<S60>/Enabled Subsystem' */

    /* MATLAB Function: '<S60>/Extract Message' */
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

    /* End of MATLAB Function: '<S60>/Extract Message' */

    /* DataTypeConversion: '<S58>/Cast To Double1' */
    Mainframe_B.Fin_1_Cmd_rad = rtb_myItems[1];

    /* Gain: '<S19>/Gain' */
    Mainframe_B.Gain_h = Mainframe_P.Gain_Gain_abz * Mainframe_B.Fin_1_Cmd_rad;

    /* DataTypeConversion: '<S58>/Cast To Double2' */
    Mainframe_B.Fin_2_Cmd_rad = rtb_myItems[2];

    /* Gain: '<S15>/Gain' */
    Mainframe_B.Gain_a = Mainframe_P.Gain_Gain_j1 * Mainframe_B.Fin_2_Cmd_rad;

    /* DataTypeConversion: '<S58>/Cast To Double3' */
    Mainframe_B.Fin_3_Cmd_rad = rtb_myItems[3];

    /* Gain: '<S20>/Gain' */
    Mainframe_B.Gain_k = Mainframe_P.Gain_Gain_ho * Mainframe_B.Fin_3_Cmd_rad;

    /* DataTypeConversion: '<S58>/Cast To Double4' */
    Mainframe_B.Fin_4_Cmd_rad = rtb_myItems[4];

    /* Gain: '<S16>/Gain' */
    Mainframe_B.Gain_d = Mainframe_P.Gain_Gain_pm * Mainframe_B.Fin_4_Cmd_rad;
  }

  /* Gain: '<S21>/Gain' */
  Mainframe_B.Gain_j = Mainframe_P.Gain_Gain_fd * Mainframe_B.Fin_1;

  /* Gain: '<S25>/Gain' */
  Mainframe_B.Gain_kd = Mainframe_P.Gain_Gain_me * Mainframe_B.Fin_2;

  /* Gain: '<S24>/Gain' */
  Mainframe_B.Gain_oi = Mainframe_P.Gain_Gain_iq * Mainframe_B.Fin_3;

  /* Gain: '<S26>/Gain' */
  Mainframe_B.Gain_is = Mainframe_P.Gain_Gain_pzg * Mainframe_B.Fin_4;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Triggered SubSystem: '<Root>/Enabled Subsystem1' incorporates:
     *  TriggerPort: '<S3>/Trigger'
     */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      /* Constant: '<S68>/One' */
      if (Mainframe_P.One_Value_j &&
          (Mainframe_PrevZCX.EnabledSubsystem1_Trig_ZCE_b != POS_ZCSIG)) {
        /* DigitalClock: '<S3>/Digital Clock' */
        Mainframe_B.DigitalClock = Mainframe_M->Timing.t[1];
        Mainframe_DW.EnabledSubsystem1_SubsysRanBC = 4;
      }

      Mainframe_PrevZCX.EnabledSubsystem1_Trig_ZCE_b = Mainframe_P.One_Value_j;
    }

    /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem1' */
  }

  /* Gain: '<S17>/Gain' */
  Mainframe_B.Gain_m = Mainframe_P.Gain_Gain_n4 * Mainframe_B.ComplextoRealImag
    [0];

  /* Integrator: '<Root>/Integrator' */
  Mainframe_B.Integrator = Mainframe_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
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

    /* Gain: '<S36>/Gain' incorporates:
     *  Constant: '<S32>/Constant1'
     *  Constant: '<S36>/wl_ins'
     *  Gain: '<S36>/Zero-Order Hold4'
     *  Sum: '<S36>/Sum7'
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

  /* SignalConversion generated from: '<S32>/Vector Concatenate' */
  rtb_uzetawn_p[0] = Mainframe_B.aBIB[0];

  /* SignalConversion generated from: '<S32>/Vector Concatenate' */
  rtb_uzetawn_p[1] = Mainframe_B.aBIB[1];

  /* SignalConversion generated from: '<S32>/Vector Concatenate' */
  rtb_uzetawn_p[2] = Mainframe_B.aBIB[2];

  /* Trigonometry: '<S33>/Cos2' */
  rtb_ixk_k = cos(Mainframe_B.ComplextoRealImag[1]);

  /* SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited' */
  rtb_IntegratorSecondOrderLimited_o1[0] =
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[0];

  /* Gain: '<S36>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S32>/Vector Concatenate3'
   */
  rtb_Sum1_e[0] = Mainframe_P.ZeroOrderHold_Gain_a * Mainframe_B.x_d[10];

  /* SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited' */
  rtb_IntegratorSecondOrderLimited_o1[1] =
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[1];

  /* Gain: '<S36>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S32>/Vector Concatenate3'
   */
  rtb_Sum1_e[1] = Mainframe_P.ZeroOrderHold_Gain_a * Mainframe_B.x_d[11];

  /* SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited' */
  rtb_IntegratorSecondOrderLimited_o1[2] =
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[2];

  /* Gain: '<S36>/Zero-Order Hold' incorporates:
   *  SignalConversion generated from: '<S32>/Vector Concatenate3'
   */
  rtb_Product_d = Mainframe_P.ZeroOrderHold_Gain_a * Mainframe_B.x_d[12];

  /* Sum: '<S45>/Sum' incorporates:
   *  Gain: '<S36>/Zero-Order Hold'
   *  Product: '<S48>/i x j'
   *  Product: '<S48>/j x k'
   *  Product: '<S48>/k x i'
   *  Product: '<S49>/i x k'
   *  Product: '<S49>/j x i'
   *  Product: '<S49>/k x j'
   */
  rtb_u2[0] = rtb_Sum1_e[1] * Mainframe_B.Gain_l[2] - rtb_Product_d *
    Mainframe_B.Gain_l[1];
  rtb_u2[1] = rtb_Product_d * Mainframe_B.Gain_l[0] - rtb_Sum1_e[0] *
    Mainframe_B.Gain_l[2];
  rtb_u2[2] = rtb_Sum1_e[0] * Mainframe_B.Gain_l[1] - rtb_Sum1_e[1] *
    Mainframe_B.Gain_l[0];

  /* Product: '<S46>/k x i' */
  rtb_T_sim_glbl = rtb_u2[0];

  /* Sum: '<S44>/Sum' incorporates:
   *  Product: '<S46>/i x j'
   *  Product: '<S46>/j x k'
   *  Product: '<S47>/i x k'
   *  Product: '<S47>/j x i'
   *  Product: '<S47>/k x j'
   */
  rtb_JMMB_tmp_6 = rtb_Sum1_e[0] * rtb_u2[1];
  q0_tmp = rtb_Sum1_e[0] * rtb_u2[2];
  rtb_Product_b_idx_0 = rtb_Sum1_e[1] * rtb_u2[0];
  rtb_u2[0] = rtb_Sum1_e[1] * rtb_u2[2] - rtb_Product_d * rtb_u2[1];

  /* Gain: '<S36>/Zero-Order Hold3' incorporates:
   *  SignalConversion generated from: '<S32>/Vector Concatenate2'
   * */
  rtb_Sum1_e[0] = Mainframe_P.ZeroOrderHold3_Gain_d * Mainframe_B.d_wBIB[0];
  rtb_Sum1_e[1] = Mainframe_P.ZeroOrderHold3_Gain_d * Mainframe_B.d_wBIB[1];
  rtb_Sum1_e[2] = Mainframe_P.ZeroOrderHold3_Gain_d * Mainframe_B.d_wBIB[2];

  /* Sum: '<S36>/Sum' incorporates:
   *  Gain: '<S33>/Multiply'
   *  Gain: '<S33>/Multiply1'
   *  Gain: '<S33>/Multiply2'
   *  Gain: '<S36>/Zero-Order Hold1'
   *  Gain: '<S36>/Zero-Order Hold2'
   *  Product: '<S33>/Product'
   *  Product: '<S33>/Product1'
   *  Product: '<S46>/k x i'
   *  Product: '<S50>/i x j'
   *  Product: '<S50>/j x k'
   *  Product: '<S50>/k x i'
   *  Product: '<S51>/i x k'
   *  Product: '<S51>/j x i'
   *  Product: '<S51>/k x j'
   *  SignalConversion generated from: '<S32>/Vector Concatenate'
   *  Sum: '<S41>/Sum'
   *  Sum: '<S44>/Sum'
   *  Trigonometry: '<S33>/Cos'
   *  Trigonometry: '<S33>/Cos1'
   *  Trigonometry: '<S33>/Cos3'
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

  /* Sum: '<S36>/Sum4' incorporates:
   *  Constant: '<S36>/Measurement bias'
   *  Constant: '<S36>/Scale factors & Cross-coupling  errors'
   *  Product: '<S36>/Product'
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

  /* End of Sum: '<S36>/Sum4' */
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
    /* Sqrt: '<S39>/Sqrt1' incorporates:
     *  Constant: '<S39>/Constant1'
     */
    rtb_Switch_j = sqrt(Mainframe_P.Randombias_Ts_i);

    /* Product: '<S39>/Product' incorporates:
     *  Constant: '<S39>/Constant'
     *  Product: '<S39>/Divide'
     *  RandomNumber: '<S39>/White Noise'
     *  Sqrt: '<S39>/Sqrt'
     */
    Mainframe_B.Product[0] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow_e[0])
      / rtb_Switch_j * Mainframe_DW.NextOutput[0];
    Mainframe_B.Product[1] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow_e[1])
      / rtb_Switch_j * Mainframe_DW.NextOutput[1];
    Mainframe_B.Product[2] = sqrt(Mainframe_P.ThreeaxisAccelerometer_a_pow_e[2])
      / rtb_Switch_j * Mainframe_DW.NextOutput[2];
  }

  /* SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
  idx = 3;

  /* Unit Conversion - from: m/s^2 to: gn
     Expression: output = (0.101972*input) + (0) */
  for (i = 0; i < 3; i++) {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/Constant'
     */
    if (Mainframe_P.Constant_Value_p3p >= Mainframe_P.Switch_Threshold_k) {
      rtb_T_sim_glbl = rtb_IntegratorSecondOrderLimited_o1[i];
    } else {
      rtb_T_sim_glbl = rtb_Sum1_e[i];
    }

    /* End of Switch: '<S38>/Switch' */

    /* Sum: '<S36>/Sum1' */
    rtb_Product4_b_idx_3 = rtb_T_sim_glbl + Mainframe_B.Product[i];

    /* Saturate: '<S36>/Saturation' */
    if (rtb_Product4_b_idx_3 > Mainframe_P.Saturation_UpperSat_m[i]) {
      Mainframe_B.Saturation[i] = Mainframe_P.Saturation_UpperSat_m[i];
    } else if (rtb_Product4_b_idx_3 < Mainframe_P.Saturation_LowerSat_e1[i]) {
      Mainframe_B.Saturation[i] = Mainframe_P.Saturation_LowerSat_e1[i];
    } else {
      Mainframe_B.Saturation[i] = rtb_Product4_b_idx_3;
    }

    /* End of Saturate: '<S36>/Saturation' */

    /* SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
    rtb_IntegratorSecondOrderLimited_o2_a[i] =
      Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[idx];
    idx++;

    /* Sum: '<S37>/Sum4' incorporates:
     *  Constant: '<S37>/Measurement bias'
     *  Constant: '<S37>/Scale factors & Cross-coupling  errors '
     *  Constant: '<S37>/g-sensitive bias'
     *  Gain: '<S37>/Zero-Order Hold'
     *  Gain: '<S37>/Zero-Order Hold1'
     *  Product: '<S37>/Product'
     *  Product: '<S37>/Product1'
     *  SignalConversion generated from: '<S32>/Vector Concatenate3'
     *  UnitConversion: '<S35>/Unit Conversion'
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

    /* Sum: '<S36>/Sum1' incorporates:
     *  SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited'
     */
    rtb_u2[i] = Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[i];
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
    /* Sqrt: '<S53>/Sqrt1' incorporates:
     *  Constant: '<S53>/Constant1'
     */
    rtb_Switch_j = sqrt(Mainframe_P.Randombias_Ts_h);

    /* Product: '<S53>/Product' incorporates:
     *  Constant: '<S53>/Constant'
     *  Product: '<S53>/Divide'
     *  RandomNumber: '<S53>/White Noise'
     *  Sqrt: '<S53>/Sqrt'
     */
    Mainframe_B.Product_i[0] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow_h[0]) /
      rtb_Switch_j * Mainframe_DW.NextOutput_m[0];
    Mainframe_B.Product_i[1] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow_h[1]) /
      rtb_Switch_j * Mainframe_DW.NextOutput_m[1];
    Mainframe_B.Product_i[2] = sqrt(Mainframe_P.ThreeaxisGyroscope_g_pow_h[2]) /
      rtb_Switch_j * Mainframe_DW.NextOutput_m[2];
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant'
   */
  if (Mainframe_P.Constant_Value_jy >= Mainframe_P.Switch_Threshold_c) {
    rtb_T_sim_glbl = rtb_u2[0];
  } else {
    rtb_T_sim_glbl = rtb_Sum4[0];
  }

  /* Sum: '<S37>/Sum1' */
  rtb_Product4_b_idx_2 = rtb_T_sim_glbl + Mainframe_B.Product_i[0];

  /* Saturate: '<S37>/Saturation' */
  if (rtb_Product4_b_idx_2 > Mainframe_P.Saturation_UpperSat_jb[0]) {
    Mainframe_B.Saturation_g[0] = Mainframe_P.Saturation_UpperSat_jb[0];
  } else if (rtb_Product4_b_idx_2 < Mainframe_P.Saturation_LowerSat_h[0]) {
    Mainframe_B.Saturation_g[0] = Mainframe_P.Saturation_LowerSat_h[0];
  } else {
    Mainframe_B.Saturation_g[0] = rtb_Product4_b_idx_2;
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant'
   */
  if (Mainframe_P.Constant_Value_jy >= Mainframe_P.Switch_Threshold_c) {
    rtb_T_sim_glbl = rtb_u2[1];
  } else {
    rtb_T_sim_glbl = rtb_Sum4[1];
  }

  /* Sum: '<S37>/Sum1' */
  rtb_Product4_b_idx_2 = rtb_T_sim_glbl + Mainframe_B.Product_i[1];

  /* Saturate: '<S37>/Saturation' */
  if (rtb_Product4_b_idx_2 > Mainframe_P.Saturation_UpperSat_jb[1]) {
    Mainframe_B.Saturation_g[1] = Mainframe_P.Saturation_UpperSat_jb[1];
  } else if (rtb_Product4_b_idx_2 < Mainframe_P.Saturation_LowerSat_h[1]) {
    Mainframe_B.Saturation_g[1] = Mainframe_P.Saturation_LowerSat_h[1];
  } else {
    Mainframe_B.Saturation_g[1] = rtb_Product4_b_idx_2;
  }

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Constant'
   */
  if (Mainframe_P.Constant_Value_jy >= Mainframe_P.Switch_Threshold_c) {
    rtb_T_sim_glbl = rtb_u2[2];
  } else {
    rtb_T_sim_glbl = rtb_Sum4[2];
  }

  /* Sum: '<S37>/Sum1' */
  rtb_Product4_b_idx_2 = rtb_T_sim_glbl + Mainframe_B.Product_i[2];

  /* Saturate: '<S37>/Saturation' */
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
        sendToAsyncQueueTgtAppSvc(2269690172U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1606805854U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.r;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3763816101U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.phi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3303651631U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.theta;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(92154799U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.psi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1595147942U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(813209322U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2700484925U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1205187603U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_g[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3762251263U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_g[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3083298425U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_g[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4210188035U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/Enabled Subsystem1' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.DigitalClock;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3056351304U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/From5' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(435796010U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3364343542U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_3;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1672862759U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_4;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1434835339U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/From6' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.vBIB[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1852947442U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.vBIB[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3017199542U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.vBIB[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2282307050U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[10];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1448809621U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[11];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(321538169U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[12];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1365060542U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.aBIB[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3311604001U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.aBIB[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(786594726U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.aBIB[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2673793388U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.d_wBIB[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2473751612U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.d_wBIB[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3273065333U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.d_wBIB[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(521545225U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.ComplextoRealImag[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3608458456U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.ComplextoRealImag[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1113727168U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.ComplextoRealImag[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3320086328U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q0;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3107806290U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q1;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2790621323U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q2;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3140362247U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q3;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2008297410U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1064471481U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(301461779U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x_d[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1992001880U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_j[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3626977606U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_j[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4092016770U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_j[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2069810939U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_je[0];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(431800080U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_je[1];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4031269822U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Saturation_je[2];
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3764123890U, time, pData, size);
      }
    }

    /* DataTypeConversion: '<S58>/Cast To Double5' */
    Mainframe_B.gyroX = rtb_myItems[5];

    /* DataTypeConversion: '<S58>/Cast To Double6' */
    Mainframe_B.gyroY = rtb_myItems[6];

    /* DataTypeConversion: '<S58>/Cast To Double7' */
    Mainframe_B.gyroZ = rtb_myItems[7];

    /* DataTypeConversion: '<S58>/Cast To Double8' */
    Mainframe_B.u = rtb_myItems[8];

    /* DataTypeConversion: '<S58>/Cast To Double9' */
    Mainframe_B.v = rtb_myItems[9];

    /* DataTypeConversion: '<S58>/Cast To Double10' */
    Mainframe_B.w = rtb_myItems[10];

    /* DataTypeConversion: '<S58>/Cast To Double12' */
    Mainframe_B.x = rtb_myItems[11];

    /* DataTypeConversion: '<S58>/Cast To Double13' */
    Mainframe_B.y = rtb_myItems[12];

    /* DataTypeConversion: '<S58>/Cast To Double14' */
    Mainframe_B.z = rtb_myItems[13];

    /* DataTypeConversion: '<S58>/Cast To Double15' */
    Mainframe_B.p_a = rtb_myItems[14];

    /* DataTypeConversion: '<S58>/Cast To Double16' */
    Mainframe_B.q_l = rtb_myItems[15];

    /* DataTypeConversion: '<S58>/Cast To Double11' */
    Mainframe_B.r_h = rtb_myItems[16];

    /* ToAsyncQueueBlock generated from: '<Root>/From7' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_1_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3915057717U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_2_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3081390809U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_3_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1840066803U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.Fin_4_Cmd_rad;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1451556150U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gyroX;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3471399375U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gyroY;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3628924710U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gyroZ;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2371966979U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.u;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(4148917395U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.v;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1724657657U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.w;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3729253410U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.x;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1408367298U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.y;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(1144390565U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.z;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2780645998U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.p_a;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2495466069U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.q_l;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(2335712673U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.r_h;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3335374413U, time, pData, size);
      }
    }

    /* ToAsyncQueueBlock generated from: '<Root>/From8' */
    if (rtmIsMajorTimeStep(Mainframe_M)) {
      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gimbalPhi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(160906649U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gimbalTheta;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(3733192466U, time, pData, size);
      }

      {
        double time = Mainframe_M->Timing.t[1];
        void *pData = (void *)&Mainframe_B.gimbalPsi;
        int32_T size = 1*sizeof(real_T);
        sendToAsyncQueueTgtAppSvc(769532429U, time, pData, size);
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
    /* Constant: '<S68>/One' */
    Mainframe_EnabledSubsystem1(Mainframe_M, Mainframe_P.One_Value_j,
      &Mainframe_B.EnabledSubsystem1, &Mainframe_DW.EnabledSubsystem1,
      &Mainframe_PrevZCX.EnabledSubsystem1);

    /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem1' */

    /* Sum: '<S29>/Sum' incorporates:
     *  Constant: '<S29>/Constant2'
     */
    Mainframe_B.Sum = Mainframe_B.EnabledSubsystem1.DigitalClock +
      Mainframe_P.DelayedStep1_stepTime;

    /* Sum: '<S30>/Sum' incorporates:
     *  Constant: '<S30>/Constant2'
     */
    Mainframe_B.Sum_g = Mainframe_B.EnabledSubsystem1.DigitalClock +
      Mainframe_P.DelayedStep2_stepTime;
  }

  /* RelationalOperator: '<S29>/GreaterThan' */
  Mainframe_B.GreaterThan = (rtb_jxi_f >= Mainframe_B.Sum);

  /* RelationalOperator: '<S30>/GreaterThan' */
  Mainframe_B.GreaterThan_e = (rtb_jxi_f >= Mainframe_B.Sum_g);

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Constant1'
   *  Constant: '<S29>/Constant3'
   */
  if (Mainframe_B.GreaterThan) {
    rtb_T_sim_glbl = Mainframe_P.DelayedStep1_u1;
  } else {
    rtb_T_sim_glbl = Mainframe_P.DelayedStep1_u0;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant1'
   *  Constant: '<S30>/Constant3'
   */
  if (Mainframe_B.GreaterThan_e) {
    q0_tmp = Mainframe_P.DelayedStep2_u1;
  } else {
    q0_tmp = Mainframe_P.DelayedStep2_u0;
  }

  /* End of Switch: '<S30>/Switch' */

  /* Sum: '<S1>/Sum' */
  Mainframe_B.phicmdrad = rtb_T_sim_glbl + q0_tmp;

  /* RelationalOperator: '<S28>/GreaterThan' */
  Mainframe_B.GreaterThan_c = (rtb_jxi_f >=
    Mainframe_B.EnabledSubsystem1.DigitalClock);

  /* Switch: '<S28>/Switch' incorporates:
   *  Constant: '<S28>/Zero'
   *  Sin: '<S28>/Sine Wave'
   *  Sum: '<S28>/Subtract'
   */
  if (Mainframe_B.GreaterThan_c) {
    rtb_T_sim_glbl = sin((rtb_jxi_f - Mainframe_B.EnabledSubsystem1.DigitalClock)
                         * Mainframe_P.DelayedSine_freq +
                         Mainframe_P.DelayedSine_phase) *
      Mainframe_P.DelayedSine_amp + Mainframe_P.DelayedSine_bias;
  } else {
    rtb_T_sim_glbl = Mainframe_P.Zero_Value_d;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Product: '<S1>/Product' */
  Mainframe_B.phicmdrad_m = Mainframe_B.phicmdrad * rtb_T_sim_glbl;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Gain: '<S43>/2*zeta * wn' */
  rtb_T_sim_glbl = 2.0 * Mainframe_P.ThreeaxisInertialMeasurementUnit_z_a_m *
    Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a_m;

  /* Gain: '<S43>/wn^2' */
  rtb_jxi_f = Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a_m *
    Mainframe_P.ThreeaxisInertialMeasurementUnit_w_a_m;

  /* Sum: '<S43>/Sum2' incorporates:
   *  Gain: '<S43>/2*zeta * wn'
   *  Gain: '<S43>/wn^2'
   *  SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited'
   *  Sum: '<S43>/Sum3'
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

  /* Gain: '<S55>/2*zeta * wn' */
  rtb_T_sim_glbl = 2.0 * Mainframe_P.ThreeaxisInertialMeasurementUnit_z_g_h *
    Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g_n;

  /* Gain: '<S55>/wn^2' */
  rtb_jxi_f = Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g_n *
    Mainframe_P.ThreeaxisInertialMeasurementUnit_w_g_n;

  /* Sum: '<S55>/Sum2' incorporates:
   *  Gain: '<S55>/2*zeta * wn'
   *  Gain: '<S55>/wn^2'
   *  Sum: '<S55>/Sum3'
   */
  Mainframe_B.Sum2_k[0] = (rtb_Sum4[0] - rtb_u2[0]) * rtb_jxi_f - rtb_T_sim_glbl
    * rtb_IntegratorSecondOrderLimited_o2_a[0];
  Mainframe_B.Sum2_k[1] = (rtb_Sum4[1] - rtb_u2[1]) * rtb_jxi_f - rtb_T_sim_glbl
    * rtb_IntegratorSecondOrderLimited_o2_a[1];
  Mainframe_B.Sum2_k[2] = (rtb_Sum4[2] - rtb_u2[2]) * rtb_jxi_f - rtb_T_sim_glbl
    * rtb_IntegratorSecondOrderLimited_o2_a[2];
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* DataTypeConversion: '<S58>/Cast To Double17' */
    Mainframe_B.debug = rtb_myItems[17];

    /* UnitDelay: '<S64>/Output' */
    rtb_FixPtSum1 = Mainframe_DW.Output_DSTATE;

    /* DataTypeConversion: '<S59>/Cast To Single18' incorporates:
     *  Constant: '<S63>/Zero'
     *  DataTypeConversion: '<S63>/Cast To Double14'
     *  Sum: '<S63>/Subtract'
     *  UnitDelay: '<S64>/Output'
     */
    Mainframe_B.CastToSingle18 = (real32_T)Mainframe_DW.Output_DSTATE -
      Mainframe_P.Zero_Value_i;

    /* RateTransition: '<S57>/Rate Transition' */
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
      Mainframe_B.RateTransition = Mainframe_B.CastToSingle18;
    }

    /* End of RateTransition: '<S57>/Rate Transition' */

    /* DataTypeConversion: '<S57>/Cast To Single' */
    Mainframe_B.CastToSingle = (real32_T)rtb_myItems[0];
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (sldrtpo): '<S60>/Packet Output' */
    /* S-Function Block: <S60>/Packet Output */

    /* no code required */
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S57>/Subtract' incorporates:
     *  Constant: '<S57>/One'
     */
    rtb_Product4_b_idx_2 = (Mainframe_B.RateTransition - rtb_myItems[0]) -
      Mainframe_P.One_Value;

    /* Saturate: '<S57>/Saturation' */
    if (rtb_Product4_b_idx_2 > Mainframe_P.Saturation_UpperSat_a) {
      Mainframe_B.FccDelay = Mainframe_P.Saturation_UpperSat_a;
    } else if (rtb_Product4_b_idx_2 < Mainframe_P.Saturation_LowerSat_gt) {
      Mainframe_B.FccDelay = Mainframe_P.Saturation_LowerSat_gt;
    } else {
      Mainframe_B.FccDelay = rtb_Product4_b_idx_2;
    }

    /* End of Saturate: '<S57>/Saturation' */
    /* DataTypeConversion: '<S59>/Cast To Single19' incorporates:
     *  Constant: '<S68>/One'
     */
    Mainframe_B.CastToSingle19 = Mainframe_P.One_Value_j;

    /* DataTypeConversion: '<S59>/Cast To Single17' incorporates:
     *  Constant: '<S4>/Constant4'
     */
    Mainframe_B.CastToSingle17 = Mainframe_P.INS_Passthrough;

    /* DataTypeConversion: '<S59>/Cast To Single16' incorporates:
     *  Constant: '<S4>/Constant1'
     */
    Mainframe_B.CastToSingle16 = Mainframe_P.Real_Gyros;
  }

  /* DataTypeConversion: '<S59>/Cast To Single15' */
  Mainframe_B.CastToSingle15 = (real32_T)Mainframe_B.vBIB[0];

  /* DataTypeConversion: '<S59>/Cast To Single14' */
  Mainframe_B.CastToSingle14 = (real32_T)Mainframe_B.vBIB[1];

  /* DataTypeConversion: '<S59>/Cast To Single13' */
  Mainframe_B.CastToSingle13 = (real32_T)Mainframe_B.vBIB[2];

  /* DataTypeConversion: '<S59>/Cast To Single12' */
  Mainframe_B.CastToSingle12 = (real32_T)Mainframe_B.x_d[0];

  /* DataTypeConversion: '<S59>/Cast To Single11' */
  Mainframe_B.CastToSingle11 = (real32_T)Mainframe_B.x_d[1];

  /* DataTypeConversion: '<S59>/Cast To Single10' */
  Mainframe_B.CastToSingle10 = (real32_T)Mainframe_B.x_d[2];

  /* DataTypeConversion: '<S59>/Cast To Single9' */
  Mainframe_B.CastToSingle9 = (real32_T)Mainframe_B.x_d[10];

  /* DataTypeConversion: '<S59>/Cast To Single8' */
  Mainframe_B.CastToSingle8 = (real32_T)Mainframe_B.x_d[11];

  /* DataTypeConversion: '<S59>/Cast To Single7' */
  Mainframe_B.CastToSingle7 = (real32_T)Mainframe_B.x_d[12];

  /* DataTypeConversion: '<S59>/Cast To Single6' */
  Mainframe_B.CastToSingle6 = (real32_T)Mainframe_B.Saturation_j[0];

  /* DataTypeConversion: '<S59>/Cast To Single5' */
  Mainframe_B.CastToSingle5 = (real32_T)Mainframe_B.Saturation_j[1];

  /* DataTypeConversion: '<S59>/Cast To Single4' */
  Mainframe_B.CastToSingle4 = (real32_T)Mainframe_B.Saturation_j[2];

  /* DataTypeConversion: '<S59>/Cast To Single3' */
  Mainframe_B.CastToSingle3 = (real32_T)Mainframe_B.Saturation_je[0];

  /* DataTypeConversion: '<S59>/Cast To Single2' */
  Mainframe_B.CastToSingle2 = (real32_T)Mainframe_B.Saturation_je[1];

  /* DataTypeConversion: '<S59>/Cast To Single1' */
  Mainframe_B.CastToSingle1 = (real32_T)Mainframe_B.Saturation_je[2];

  /* DataTypeConversion: '<S59>/Cast To Single21' */
  Mainframe_B.CastToSingle21 = (real32_T)Mainframe_B.ComplextoRealImag[0];

  /* DataTypeConversion: '<S59>/Cast To Single22' */
  Mainframe_B.CastToSingle22 = (real32_T)Mainframe_B.ComplextoRealImag[1];

  /* DataTypeConversion: '<S59>/Cast To Single23' */
  Mainframe_B.CastToSingle23 = (real32_T)Mainframe_B.ComplextoRealImag[2];

  /* DataTypeConversion: '<S59>/Cast To Single20' */
  Mainframe_B.CastToSingle20 = (real32_T)Mainframe_B.phicmdrad_m;
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Sum: '<S65>/FixPt Sum1' incorporates:
     *  Constant: '<S65>/FixPt Constant'
     */
    rtb_FixPtSum1 = (uint16_T)((uint32_T)rtb_FixPtSum1 +
      Mainframe_P.FixPtConstant_Value);

    /* Switch: '<S66>/FixPt Switch' incorporates:
     *  Constant: '<S66>/Constant'
     */
    if (rtb_FixPtSum1 > Mainframe_P.WrapToZero_Threshold) {
      Mainframe_B.FixPtSwitch = Mainframe_P.Constant_Value_hg;
    } else {
      Mainframe_B.FixPtSwitch = rtb_FixPtSum1;
    }

    /* End of Switch: '<S66>/FixPt Switch' */
  }

  /* Logic: '<S69>/AND' incorporates:
   *  Constant: '<S68>/One'
   *  Constant: '<S73>/Constant'
   *  RelationalOperator: '<S73>/Compare'
   */
  Mainframe_B.AND = (Mainframe_P.One_Value_j && (Mainframe_B.x_d[2] >=
    Mainframe_P.CompareToConstant_const_n));

  /* Stop: '<S69>/Stop Simulation' */
  if ((rtmIsMajorTimeStep(Mainframe_M) &&
       Mainframe_M->Timing.TaskCounters.TID[1] == 0) && Mainframe_B.AND) {
    rtmSetStopRequested(Mainframe_M, 1);
  }

  /* End of Stop: '<S69>/Stop Simulation' */

  /* Gain: '<S18>/Gain' */
  Mainframe_B.Gain_fp = Mainframe_P.Gain_Gain_nf * Mainframe_B.Saturation_je[0];
  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
  }
}

/* Model update function */
void Mainframe_update(void)
{
  real_T *lastU;

  /* Update for Enabled SubSystem: '<S7>/Subsystem' incorporates:
   *  EnablePort: '<S70>/Enable'
   */
  if (Mainframe_DW.Subsystem_MODE) {
    /* Update for Integrator: '<S240>/integration_eom' */
    Mainframe_DW.integration_eom_IWORK = 0;

    /* Update for Integrator: '<S185>/integration_eom' */
    Mainframe_DW.integration_eom_IWORK_p = 0;

    /* Update for Integrator: '<S186>/integration_eom' */
    Mainframe_DW.integration_eom_IWORK_g = 0;
    if (rtmIsMajorTimeStep(Mainframe_M) &&
        Mainframe_M->Timing.TaskCounters.TID[3] == 0) {
      /* Update for RandomNumber: '<S86>/White Noise' */
      Mainframe_DW.NextOutput_mb[0] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_gr[0]) * Mainframe_P.WhiteNoise_StdDev +
        Mainframe_P.WhiteNoise_Mean;

      /* Update for RandomNumber: '<S100>/White Noise' */
      Mainframe_DW.NextOutput_i[0] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_i[0]) * Mainframe_P.WhiteNoise_StdDev_f +
        Mainframe_P.WhiteNoise_Mean_i;

      /* Update for RandomNumber: '<S86>/White Noise' */
      Mainframe_DW.NextOutput_mb[1] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_gr[1]) * Mainframe_P.WhiteNoise_StdDev +
        Mainframe_P.WhiteNoise_Mean;

      /* Update for RandomNumber: '<S100>/White Noise' */
      Mainframe_DW.NextOutput_i[1] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_i[1]) * Mainframe_P.WhiteNoise_StdDev_f +
        Mainframe_P.WhiteNoise_Mean_i;

      /* Update for RandomNumber: '<S86>/White Noise' */
      Mainframe_DW.NextOutput_mb[2] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_gr[2]) * Mainframe_P.WhiteNoise_StdDev +
        Mainframe_P.WhiteNoise_Mean;

      /* Update for RandomNumber: '<S100>/White Noise' */
      Mainframe_DW.NextOutput_i[2] = rt_nrand_Upu32_Yd_f_pw_snf
        (&Mainframe_DW.RandSeed_i[2]) * Mainframe_P.WhiteNoise_StdDev_f +
        Mainframe_P.WhiteNoise_Mean_i;
    }

    /* Update for Derivative: '<S187>/Derivative1' */
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

    /* End of Update for Derivative: '<S187>/Derivative1' */

    /* Update for Derivative: '<S187>/Derivative' */
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

    /* End of Update for Derivative: '<S187>/Derivative' */
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
    /* Update for RandomNumber: '<S39>/White Noise' */
    Mainframe_DW.NextOutput[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[0]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* Update for RandomNumber: '<S53>/White Noise' */
    Mainframe_DW.NextOutput_m[0] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[0]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;

    /* Update for RandomNumber: '<S39>/White Noise' */
    Mainframe_DW.NextOutput[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[1]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* Update for RandomNumber: '<S53>/White Noise' */
    Mainframe_DW.NextOutput_m[1] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[1]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;

    /* Update for RandomNumber: '<S39>/White Noise' */
    Mainframe_DW.NextOutput[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed[2]) * Mainframe_P.WhiteNoise_StdDev_l +
      Mainframe_P.WhiteNoise_Mean_o;

    /* Update for RandomNumber: '<S53>/White Noise' */
    Mainframe_DW.NextOutput_m[2] = rt_nrand_Upu32_Yd_f_pw_snf
      (&Mainframe_DW.RandSeed_g[2]) * Mainframe_P.WhiteNoise_StdDev_fq +
      Mainframe_P.WhiteNoise_Mean_k;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for UnitDelay: '<S64>/Output' */
    Mainframe_DW.Output_DSTATE = Mainframe_B.FixPtSwitch;
  }

  if (rtmIsMajorTimeStep(Mainframe_M) &&
      Mainframe_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for S-Function (sldrtpo): '<S60>/Packet Output' */

    /* S-Function Block: <S60>/Packet Output */
    {
      uint8_T outdata[92U];
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
        real32_T pktout = Mainframe_B.CastToSingle21;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle22;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle23;
        *outdp.p_real32_T++ = pktout;
      }

      {
        real32_T pktout = Mainframe_B.CastToSingle20;
        *outdp.p_real32_T++ = pktout;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 92U,
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

  /* Derivatives for TransferFcn: '<S289>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += Mainframe_P.TransferFcn1_A[0] *
    Mainframe_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn1_CSTATE[0] += Mainframe_P.TransferFcn1_A[1] *
    Mainframe_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] += Mainframe_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += Mainframe_B.Fin_1_Cmd_rad;

  /* Derivatives for TransferFcn: '<S289>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += Mainframe_P.TransferFcn2_A[0] *
    Mainframe_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn2_CSTATE[0] += Mainframe_P.TransferFcn2_A[1] *
    Mainframe_X.TransferFcn2_CSTATE[1];
  _rtXdot->TransferFcn2_CSTATE[1] += Mainframe_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[0] += Mainframe_B.Fin_2_Cmd_rad;

  /* Derivatives for TransferFcn: '<S289>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += Mainframe_P.TransferFcn3_A[0] *
    Mainframe_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  _rtXdot->TransferFcn3_CSTATE[0] += Mainframe_P.TransferFcn3_A[1] *
    Mainframe_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] += Mainframe_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[0] += Mainframe_B.Fin_3_Cmd_rad;

  /* Derivatives for TransferFcn: '<S289>/Transfer Fcn4' */
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
    /* Derivatives for Integrator: '<S240>/integration_eom' */
    memcpy(&_rtXdot->integration_eom_CSTATE[0], &Mainframe_B.d_x[0], 13U *
           sizeof(real_T));

    /* Derivatives for Integrator: '<S185>/integration_eom' */
    _rtXdot->integration_eom_CSTATE_o[0] = Mainframe_B.VectorConcatenate_m[0];
    _rtXdot->integration_eom_CSTATE_o[1] = Mainframe_B.VectorConcatenate_m[1];
    _rtXdot->integration_eom_CSTATE_o[2] = Mainframe_B.VectorConcatenate_m[2];
    _rtXdot->integration_eom_CSTATE_o[3] = Mainframe_B.VectorConcatenate_m[3];

    /* Derivatives for Integrator: '<S153>/Integrator1' */
    lsat = (Mainframe_X.Integrator1_CSTATE <= Mainframe_P.Rudder_siB_min);
    usat = (Mainframe_X.Integrator1_CSTATE >= Mainframe_P.Rudder_siB_max);
    if (((!lsat) && (!usat)) || (lsat && (Mainframe_B.sf_Limiting_Rate.d_siB_l >
          0.0)) || (usat && (Mainframe_B.sf_Limiting_Rate.d_siB_l < 0.0))) {
      _rtXdot->Integrator1_CSTATE = Mainframe_B.sf_Limiting_Rate.d_siB_l;
    } else {
      /* in saturation */
      _rtXdot->Integrator1_CSTATE = 0.0;
    }

    /* End of Derivatives for Integrator: '<S153>/Integrator1' */

    /* Derivatives for Integrator: '<S154>/Integrator1' */
    lsat = (Mainframe_X.Integrator1_CSTATE_n <= Mainframe_P.Rudder1_siB_min);
    usat = (Mainframe_X.Integrator1_CSTATE_n >= Mainframe_P.Rudder1_siB_max);
    if (((!lsat) && (!usat)) || (lsat && (Mainframe_B.sf_Limiting_Rate_g.d_siB_l
          > 0.0)) || (usat && (Mainframe_B.sf_Limiting_Rate_g.d_siB_l < 0.0))) {
      _rtXdot->Integrator1_CSTATE_n = Mainframe_B.sf_Limiting_Rate_g.d_siB_l;
    } else {
      /* in saturation */
      _rtXdot->Integrator1_CSTATE_n = 0.0;
    }

    /* End of Derivatives for Integrator: '<S154>/Integrator1' */

    /* Derivatives for Integrator: '<S155>/Integrator1' */
    lsat = (Mainframe_X.Integrator1_CSTATE_k <= Mainframe_P.Rudder2_siB_min);
    usat = (Mainframe_X.Integrator1_CSTATE_k >= Mainframe_P.Rudder2_siB_max);
    if (((!lsat) && (!usat)) || (lsat && (Mainframe_B.sf_Limiting_Rate_a.d_siB_l
          > 0.0)) || (usat && (Mainframe_B.sf_Limiting_Rate_a.d_siB_l < 0.0))) {
      _rtXdot->Integrator1_CSTATE_k = Mainframe_B.sf_Limiting_Rate_a.d_siB_l;
    } else {
      /* in saturation */
      _rtXdot->Integrator1_CSTATE_k = 0.0;
    }

    /* End of Derivatives for Integrator: '<S155>/Integrator1' */

    /* Derivatives for Integrator: '<S156>/Integrator1' */
    lsat = (Mainframe_X.Integrator1_CSTATE_f <= Mainframe_P.Rudder3_siB_min);
    usat = (Mainframe_X.Integrator1_CSTATE_f >= Mainframe_P.Rudder3_siB_max);
    if (((!lsat) && (!usat)) || (lsat && (Mainframe_B.sf_Limiting_Rate_o.d_siB_l
          > 0.0)) || (usat && (Mainframe_B.sf_Limiting_Rate_o.d_siB_l < 0.0))) {
      _rtXdot->Integrator1_CSTATE_f = Mainframe_B.sf_Limiting_Rate_o.d_siB_l;
    } else {
      /* in saturation */
      _rtXdot->Integrator1_CSTATE_f = 0.0;
    }

    /* End of Derivatives for Integrator: '<S156>/Integrator1' */

    /* Derivatives for Integrator: '<S186>/integration_eom' */
    _rtXdot->integration_eom_CSTATE_k[0] = Mainframe_B.VectorConcatenate_e[0];
    _rtXdot->integration_eom_CSTATE_k[1] = Mainframe_B.VectorConcatenate_e[1];
    _rtXdot->integration_eom_CSTATE_k[2] = Mainframe_B.VectorConcatenate_e[2];
    _rtXdot->integration_eom_CSTATE_k[3] = Mainframe_B.VectorConcatenate_e[3];

    /* Derivatives for SecondOrderIntegrator: '<S90>/Integrator, Second-Order Limited' */
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

    /* End of Derivatives for SecondOrderIntegrator: '<S90>/Integrator, Second-Order Limited' */

    /* Derivatives for SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
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

    /* End of Derivatives for SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */

    /* Derivatives for Integrator: '<S153>/Integrator' */
    _rtXdot->Integrator_CSTATE_j = Mainframe_B.sf_Limiting_Acceleration.dd_siB_l;

    /* Derivatives for Integrator: '<S154>/Integrator' */
    _rtXdot->Integrator_CSTATE_g =
      Mainframe_B.sf_Limiting_Acceleration_p.dd_siB_l;

    /* Derivatives for Integrator: '<S155>/Integrator' */
    _rtXdot->Integrator_CSTATE_f =
      Mainframe_B.sf_Limiting_Acceleration_l.dd_siB_l;

    /* Derivatives for Integrator: '<S156>/Integrator' */
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

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = Mainframe_B.Gain_fp;

  /* Derivatives for SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited' */
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

  /* End of Derivatives for SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited' */

  /* Derivatives for SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
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

  /* End of Derivatives for SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
}

/* Model initialize function */
void Mainframe_initialize(void)
{
  /* Start for Enabled SubSystem: '<S7>/Subsystem' */
  Mainframe_DW.Subsystem_MODE = false;

  /* Start for Constant: '<S210>/Constant' */
  memcpy(&Mainframe_B.Constant[0], &Mainframe_P.Constant_Value_cg[0], 13U *
         sizeof(real_T));

  /* Start for Constant: '<S185>/Constant8' */
  Mainframe_B.Constant8[0] = Mainframe_P.Constant8_Value_mc[0];

  /* Start for Constant: '<S186>/Constant8' */
  Mainframe_B.Constant8_a[0] = Mainframe_P.Constant8_Value_el[0];

  /* Start for Constant: '<S185>/Constant8' */
  Mainframe_B.Constant8[1] = Mainframe_P.Constant8_Value_mc[1];

  /* Start for Constant: '<S186>/Constant8' */
  Mainframe_B.Constant8_a[1] = Mainframe_P.Constant8_Value_el[1];

  /* Start for Constant: '<S185>/Constant8' */
  Mainframe_B.Constant8[2] = Mainframe_P.Constant8_Value_mc[2];

  /* Start for Constant: '<S186>/Constant8' */
  Mainframe_B.Constant8_a[2] = Mainframe_P.Constant8_Value_el[2];

  /* Start for Constant: '<S185>/Constant8' */
  Mainframe_B.Constant8[3] = Mainframe_P.Constant8_Value_mc[3];

  /* Start for Constant: '<S186>/Constant8' */
  Mainframe_B.Constant8_a[3] = Mainframe_P.Constant8_Value_el[3];

  /* Start for Enabled SubSystem: '<S212>/q_R^0(R)' */
  Mainframe_DW.q_R0R_MODE = false;

  /* End of Start for SubSystem: '<S212>/q_R^0(R)' */

  /* Start for Enabled SubSystem: '<S212>/q_R^1(R)' */
  Mainframe_DW.q_R1R_MODE = false;

  /* End of Start for SubSystem: '<S212>/q_R^1(R)' */

  /* Start for Enabled SubSystem: '<S212>/q_R^2(R)' */
  Mainframe_DW.q_R2R_MODE = false;

  /* End of Start for SubSystem: '<S212>/q_R^2(R)' */

  /* Start for Enabled SubSystem: '<S212>/q_R^3(R)' */
  Mainframe_DW.q_R3R_MODE = false;

  /* End of Start for SubSystem: '<S212>/q_R^3(R)' */
  /* End of Start for SubSystem: '<S7>/Subsystem' */
  /* Start for S-Function (sldrtpo): '<S60>/Packet Output' */

  /* S-Function Block: <S60>/Packet Output */
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

    /* InitializeConditions for TransferFcn: '<S289>/Transfer Fcn1' */
    Mainframe_X.TransferFcn1_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S289>/Transfer Fcn2' */
    Mainframe_X.TransferFcn2_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S289>/Transfer Fcn3' */
    Mainframe_X.TransferFcn3_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S289>/Transfer Fcn4' */
    Mainframe_X.TransferFcn4_CSTATE[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S289>/Transfer Fcn1' */
    Mainframe_X.TransferFcn1_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S289>/Transfer Fcn2' */
    Mainframe_X.TransferFcn2_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S289>/Transfer Fcn3' */
    Mainframe_X.TransferFcn3_CSTATE[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S289>/Transfer Fcn4' */
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

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    Mainframe_X.Integrator_CSTATE = Mainframe_P.Integrator_IC;

    /* InitializeConditions for SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[0] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_l;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[1] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_l;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[2] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_l;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[3] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_b;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE[0] = 0;

    /* InitializeConditions for RandomNumber: '<S39>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[0] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_h;

    /* InitializeConditions for SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[4] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_b;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE[1] = 0;

    /* InitializeConditions for RandomNumber: '<S39>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[1] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_h;

    /* InitializeConditions for SecondOrderIntegrator: '<S43>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE[5] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_b;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE[2] = 0;

    /* InitializeConditions for RandomNumber: '<S39>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[2] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_h;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[3] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_d;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[0] = 0;

    /* InitializeConditions for RandomNumber: '<S53>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[4] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_d;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[1] = 0;

    /* InitializeConditions for RandomNumber: '<S53>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S55>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_c[5] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_d;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_e[2] = 0;

    /* InitializeConditions for RandomNumber: '<S53>/White Noise' */
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

    /* InitializeConditions for UnitDelay: '<S64>/Output' */
    Mainframe_DW.Output_DSTATE = Mainframe_P.Output_InitialCondition;

    /* SystemInitialize for Triggered SubSystem: '<S72>/Enabled Subsystem1' */
    Mainframe_EnabledSubsystem1_Init(&Mainframe_B.EnabledSubsystem1_h,
      &Mainframe_P.EnabledSubsystem1_h);

    /* End of SystemInitialize for SubSystem: '<S72>/Enabled Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S7>/Subsystem' */
    /* InitializeConditions for Integrator: '<S240>/integration_eom' incorporates:
     *  Integrator: '<S185>/integration_eom'
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

    /* End of InitializeConditions for Integrator: '<S240>/integration_eom' */

    /* InitializeConditions for Integrator: '<S185>/integration_eom' */
    Mainframe_DW.integration_eom_IWORK_p = 1;

    /* InitializeConditions for Integrator: '<S153>/Integrator1' */
    Mainframe_X.Integrator1_CSTATE = Mainframe_P.Rudder_siB_0;

    /* InitializeConditions for Integrator: '<S154>/Integrator1' */
    Mainframe_X.Integrator1_CSTATE_n = Mainframe_P.Rudder1_siB_0;

    /* InitializeConditions for Integrator: '<S155>/Integrator1' */
    Mainframe_X.Integrator1_CSTATE_k = Mainframe_P.Rudder2_siB_0;

    /* InitializeConditions for Integrator: '<S156>/Integrator1' */
    Mainframe_X.Integrator1_CSTATE_f = Mainframe_P.Rudder3_siB_0;

    /* InitializeConditions for Integrator: '<S186>/integration_eom' */
    if (rtmIsFirstInitCond(Mainframe_M)) {
      Mainframe_X.integration_eom_CSTATE_k[0] = 0.0;
      Mainframe_X.integration_eom_CSTATE_k[1] = 0.0;
      Mainframe_X.integration_eom_CSTATE_k[2] = 0.0;
      Mainframe_X.integration_eom_CSTATE_k[3] = 1.0;
    }

    Mainframe_DW.integration_eom_IWORK_g = 1;

    /* End of InitializeConditions for Integrator: '<S186>/integration_eom' */

    /* InitializeConditions for SecondOrderIntegrator: '<S90>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[0] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[1] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[2] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[3] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[0] = 0;

    /* InitializeConditions for RandomNumber: '<S86>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[0] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_a;

    /* InitializeConditions for SecondOrderIntegrator: '<S90>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[4] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[1] = 0;

    /* InitializeConditions for RandomNumber: '<S86>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[1] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_a;

    /* InitializeConditions for SecondOrderIntegrator: '<S90>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_g[5] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_h[2] = 0;

    /* InitializeConditions for RandomNumber: '<S86>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[2] =
      Mainframe_P.IntegratorSecondOrderLimited_ICX_a;
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[3] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_n;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[0] = 0;

    /* InitializeConditions for RandomNumber: '<S100>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[4] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_n;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[1] = 0;

    /* InitializeConditions for RandomNumber: '<S100>/White Noise' */
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

    /* InitializeConditions for SecondOrderIntegrator: '<S102>/Integrator, Second-Order Limited' */
    Mainframe_X.IntegratorSecondOrderLimited_CSTATE_e[5] =
      Mainframe_P.IntegratorSecondOrderLimited_ICDXDT_n;
    Mainframe_DW.IntegratorSecondOrderLimited_MODE_a[2] = 0;

    /* InitializeConditions for RandomNumber: '<S100>/White Noise' */
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

    /* InitializeConditions for Integrator: '<S153>/Integrator' */
    Mainframe_X.Integrator_CSTATE_j = Mainframe_P.Rudder_d_siB_0;

    /* InitializeConditions for Integrator: '<S154>/Integrator' */
    Mainframe_X.Integrator_CSTATE_g = Mainframe_P.Rudder1_d_siB_0;

    /* InitializeConditions for Integrator: '<S155>/Integrator' */
    Mainframe_X.Integrator_CSTATE_f = Mainframe_P.Rudder2_d_siB_0;

    /* InitializeConditions for Integrator: '<S156>/Integrator' */
    Mainframe_X.Integrator_CSTATE_o = Mainframe_P.Rudder3_d_siB_0;

    /* InitializeConditions for Derivative: '<S187>/Derivative1' */
    Mainframe_DW.TimeStampA = (rtInf);
    Mainframe_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<S187>/Derivative' */
    Mainframe_DW.TimeStampA_i = (rtInf);
    Mainframe_DW.TimeStampB_c = (rtInf);

    /* SystemInitialize for Outport: '<S70>/States' */
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
    Mainframe_B.Saturation_j[0] = 0.0;
    Mainframe_B.Saturation_j[1] = 0.0;
    Mainframe_B.Saturation_j[2] = 0.0;
    Mainframe_B.Saturation_je[0] = 0.0;
    Mainframe_B.Saturation_je[1] = 0.0;
    Mainframe_B.Saturation_je[2] = 0.0;

    /* End of SystemInitialize for SubSystem: '<S7>/Subsystem' */

    /* SystemInitialize for Triggered SubSystem: '<S60>/Enabled Subsystem' */
    /* SystemInitialize for Outport: '<S61>/Out1' */
    for (i = 0; i < 75; i++) {
      Mainframe_B.In1[i] = Mainframe_P.Out1_Y0;
    }

    /* End of SystemInitialize for Outport: '<S61>/Out1' */
    /* End of SystemInitialize for SubSystem: '<S60>/Enabled Subsystem' */

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
  /* Terminate for S-Function (sldrtpo): '<S60>/Packet Output' */

  /* S-Function Block: <S60>/Packet Output */
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
  Mainframe_P.Saturation_UpperSat_a = rtInf;

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

  rtmSetTFinal(Mainframe_M, 40.0);
  Mainframe_M->Timing.stepSize0 = 0.001;
  Mainframe_M->Timing.stepSize1 = 0.001;
  Mainframe_M->Timing.stepSize2 = 0.01;
  Mainframe_M->Timing.stepSize3 = 0.1;
  rtmSetFirstInitCond(Mainframe_M, 1);

  /* External mode info */
  Mainframe_M->Sizes.checksums[0] = (3958589060U);
  Mainframe_M->Sizes.checksums[1] = (2956927614U);
  Mainframe_M->Sizes.checksums[2] = (2779292625U);
  Mainframe_M->Sizes.checksums[3] = (1316587036U);

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
  Mainframe_M->Sizes.numContStates = (62);/* Number of continuous states */
  Mainframe_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  Mainframe_M->Sizes.numY = (0);       /* Number of model outputs */
  Mainframe_M->Sizes.numU = (0);       /* Number of model inputs */
  Mainframe_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Mainframe_M->Sizes.numSampTimes = (4);/* Number of sample times */
  Mainframe_M->Sizes.numBlocks = (2120);/* Number of blocks */
  Mainframe_M->Sizes.numBlockIO = (182);/* Number of block outputs */
  Mainframe_M->Sizes.numBlockPrms = (2748);/* Sum of parameter "widths" */
  return Mainframe_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
