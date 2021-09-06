/*
 * Mainframe_types.h
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

#ifndef RTW_HEADER_Mainframe_types_h_
#define RTW_HEADER_Mainframe_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_jbxYdWwrCciuYkBuQMgmLB_
#define DEFINED_TYPEDEF_FOR_struct_jbxYdWwrCciuYkBuQMgmLB_

typedef struct {
  real_T u_mDs;
  real_T v_mDs;
  real_T w_mDs;
} struct_jbxYdWwrCciuYkBuQMgmLB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tv90JB0iQLW6AIr5s7BfDC_
#define DEFINED_TYPEDEF_FOR_struct_tv90JB0iQLW6AIr5s7BfDC_

typedef struct {
  real_T p_radDs;
  real_T q_radDs;
  real_T r_radDs;
} struct_tv90JB0iQLW6AIr5s7BfDC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_qAeYjvUSNpG7NMI2ogqXLH_
#define DEFINED_TYPEDEF_FOR_struct_qAeYjvUSNpG7NMI2ogqXLH_

typedef struct {
  real_T u_dot_mDs2;
  real_T v_dot_mDs2;
  real_T w_dot_mDs2;
} struct_qAeYjvUSNpG7NMI2ogqXLH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_amXqGZUCV7xS8GBArfT5hB_
#define DEFINED_TYPEDEF_FOR_struct_amXqGZUCV7xS8GBArfT5hB_

typedef struct {
  real_T p_dot_radDs2;
  real_T q_dot_radDs2;
  real_T r_dot_radDs2;
} struct_amXqGZUCV7xS8GBArfT5hB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_UjIRKSZtxYpJmyaul7bZkB_
#define DEFINED_TYPEDEF_FOR_struct_UjIRKSZtxYpJmyaul7bZkB_

typedef struct {
  real_T Phi_rad;
  real_T Theta_rad;
  real_T Psi_rad;
} struct_UjIRKSZtxYpJmyaul7bZkB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_7zmzx7fKYRI5okiTdV8gfC_
#define DEFINED_TYPEDEF_FOR_struct_7zmzx7fKYRI5okiTdV8gfC_

typedef struct {
  real_T quat_0;
  real_T quat_1;
  real_T quat_2;
  real_T quat_3;
} struct_7zmzx7fKYRI5okiTdV8gfC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_bRuDvduKLtVUFiM55ecZoH_
#define DEFINED_TYPEDEF_FOR_struct_bRuDvduKLtVUFiM55ecZoH_

typedef struct {
  struct_UjIRKSZtxYpJmyaul7bZkB ATT_Euler;
  struct_7zmzx7fKYRI5okiTdV8gfC ATT_Quaternions;
} struct_bRuDvduKLtVUFiM55ecZoH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Tvr8NhakFinFbdhQqtcySF_
#define DEFINED_TYPEDEF_FOR_struct_Tvr8NhakFinFbdhQqtcySF_

typedef struct {
  real_T POS_x_NED_m;
  real_T POS_y_NED_m;
  real_T POS_z_NED_m;
} struct_Tvr8NhakFinFbdhQqtcySF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BGXGGRv8susPyI4gnuC71F_
#define DEFINED_TYPEDEF_FOR_struct_BGXGGRv8susPyI4gnuC71F_

typedef struct {
  real_T accX;
  real_T accY;
  real_T accZ;
} struct_BGXGGRv8susPyI4gnuC71F;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_E4zyrlOqU7yN0r42gdoW3E_
#define DEFINED_TYPEDEF_FOR_struct_E4zyrlOqU7yN0r42gdoW3E_

typedef struct {
  real_T gyroX;
  real_T gyroY;
  real_T gyroZ;
} struct_E4zyrlOqU7yN0r42gdoW3E;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Ww70OUmJnjMrjHguTkjSfE_
#define DEFINED_TYPEDEF_FOR_struct_Ww70OUmJnjMrjHguTkjSfE_

typedef struct {
  struct_BGXGGRv8susPyI4gnuC71F accelerometer;
  struct_E4zyrlOqU7yN0r42gdoW3E gyro;
} struct_Ww70OUmJnjMrjHguTkjSfE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lXmhUO4fjcHlZG2drh1EOG_
#define DEFINED_TYPEDEF_FOR_struct_lXmhUO4fjcHlZG2drh1EOG_

typedef struct {
  struct_jbxYdWwrCciuYkBuQMgmLB Translation_States;
  struct_tv90JB0iQLW6AIr5s7BfDC Rotation_States;
  struct_qAeYjvUSNpG7NMI2ogqXLH Translation_States_Dot;
  struct_amXqGZUCV7xS8GBArfT5hB Rotation_States_Dot;
  struct_bRuDvduKLtVUFiM55ecZoH Attitude_States;
  struct_Tvr8NhakFinFbdhQqtcySF POS_NED;
  struct_Ww70OUmJnjMrjHguTkjSfE IMU;
} struct_lXmhUO4fjcHlZG2drh1EOG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_QfWAjvnYOEAzkihVXImMy_
#define DEFINED_TYPEDEF_FOR_struct_QfWAjvnYOEAzkihVXImMy_

typedef struct {
  real_T euler[3];
} struct_QfWAjvnYOEAzkihVXImMy;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_20D8cUUeS0Xpo6TMettltD_
#define DEFINED_TYPEDEF_FOR_struct_20D8cUUeS0Xpo6TMettltD_

typedef struct {
  real_T FCC;
  real_T Gimbal;
  real_T FlightGear;
  real_T MeasureServos;
} struct_20D8cUUeS0Xpo6TMettltD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_zEKLU1UYGrI2UXuQVw6e3G_
#define DEFINED_TYPEDEF_FOR_struct_zEKLU1UYGrI2UXuQVw6e3G_

typedef struct {
  struct_QfWAjvnYOEAzkihVXImMy FDM;
  struct_20D8cUUeS0Xpo6TMettltD VSS;
} struct_zEKLU1UYGrI2UXuQVw6e3G;

#endif

/* Parameters for system: '<S1>/Enabled Subsystem1' */
typedef struct P_EnabledSubsystem1_Mainframe_T_ P_EnabledSubsystem1_Mainframe_T;

/* Parameters (default storage) */
typedef struct P_Mainframe_T_ P_Mainframe_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Mainframe_T RT_MODEL_Mainframe_T;

#endif                                 /* RTW_HEADER_Mainframe_types_h_ */
