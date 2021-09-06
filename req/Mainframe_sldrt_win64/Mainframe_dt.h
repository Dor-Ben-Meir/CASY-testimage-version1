/*
 * Mainframe_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(struct_jbxYdWwrCciuYkBuQMgmLB),
  sizeof(struct_tv90JB0iQLW6AIr5s7BfDC),
  sizeof(struct_qAeYjvUSNpG7NMI2ogqXLH),
  sizeof(struct_amXqGZUCV7xS8GBArfT5hB),
  sizeof(struct_UjIRKSZtxYpJmyaul7bZkB),
  sizeof(struct_7zmzx7fKYRI5okiTdV8gfC),
  sizeof(struct_bRuDvduKLtVUFiM55ecZoH),
  sizeof(struct_Tvr8NhakFinFbdhQqtcySF),
  sizeof(struct_BGXGGRv8susPyI4gnuC71F),
  sizeof(struct_E4zyrlOqU7yN0r42gdoW3E),
  sizeof(struct_Ww70OUmJnjMrjHguTkjSfE),
  sizeof(struct_lXmhUO4fjcHlZG2drh1EOG),
  sizeof(struct_QfWAjvnYOEAzkihVXImMy),
  sizeof(struct_20D8cUUeS0Xpo6TMettltD),
  sizeof(struct_zEKLU1UYGrI2UXuQVw6e3G)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "struct_jbxYdWwrCciuYkBuQMgmLB",
  "struct_tv90JB0iQLW6AIr5s7BfDC",
  "struct_qAeYjvUSNpG7NMI2ogqXLH",
  "struct_amXqGZUCV7xS8GBArfT5hB",
  "struct_UjIRKSZtxYpJmyaul7bZkB",
  "struct_7zmzx7fKYRI5okiTdV8gfC",
  "struct_bRuDvduKLtVUFiM55ecZoH",
  "struct_Tvr8NhakFinFbdhQqtcySF",
  "struct_BGXGGRv8susPyI4gnuC71F",
  "struct_E4zyrlOqU7yN0r42gdoW3E",
  "struct_Ww70OUmJnjMrjHguTkjSfE",
  "struct_lXmhUO4fjcHlZG2drh1EOG",
  "struct_QfWAjvnYOEAzkihVXImMy",
  "struct_20D8cUUeS0Xpo6TMettltD",
  "struct_zEKLU1UYGrI2UXuQVw6e3G"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Mainframe_B.Fin_1), 0, 0, 281 },

  { (char_T *)(&Mainframe_B.CastToSingle18), 1, 0, 22 },

  { (char_T *)(&Mainframe_B.FixPtSwitch), 5, 0, 1 },

  { (char_T *)(&Mainframe_B.PacketInput_o1[0]), 3, 0, 150 },

  { (char_T *)(&Mainframe_B.PacketInput_o2), 8, 0, 16 },

  { (char_T *)(&Mainframe_B.EnabledSubsystem1_h.DigitalClock), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.sf_Limiting_Rate_o.d_siB_l), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.sf_Limiting_Acceleration_j.dd_siB_l), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.sf_Limiting_Rate_a.d_siB_l), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.sf_Limiting_Acceleration_l.dd_siB_l), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.sf_Limiting_Rate_g.d_siB_l), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.sf_Limiting_Acceleration_p.dd_siB_l), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.sf_Limiting_Rate.d_siB_l), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.sf_Limiting_Acceleration.dd_siB_l), 0, 0, 1 },

  { (char_T *)(&Mainframe_B.EnabledSubsystem1.DigitalClock), 0, 0, 1 }
  ,

  { (char_T *)(&Mainframe_DW.DiscreteTimeIntegrator1_DSTATE), 0, 0, 23 },

  { (char_T *)(&Mainframe_DW.Attitude_PWORK.LoggedData[0]), 11, 0, 107 },

  { (char_T *)(&Mainframe_DW.RandSeed[0]), 7, 0, 12 },

  { (char_T *)(&Mainframe_DW.integration_eom_IWORK), 10, 0, 15 },

  { (char_T *)(&Mainframe_DW.Output_DSTATE), 5, 0, 1 },

  { (char_T *)(&Mainframe_DW.Subsystem_SubsysRanBC), 2, 0, 7 },

  { (char_T *)(&Mainframe_DW.IntegratorSecondOrderLimited_DWORK1), 8, 0, 9 },

  { (char_T *)(&Mainframe_DW.EnabledSubsystem1_h.EnabledSubsystem1_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Mainframe_DW.EnabledSubsystem1.EnabledSubsystem1_SubsysRanBC), 2,
    0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  24U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Mainframe_P.INS_Passthrough), 1, 0, 2 },

  { (char_T *)(&Mainframe_P.PacketInput_MaxMissedTicks), 0, 0, 177 },

  { (char_T *)(&Mainframe_P.PacketInput_PacketID), 6, 0, 2 },

  { (char_T *)(&Mainframe_P.WrapToZero_Threshold), 5, 0, 1 },

  { (char_T *)(&Mainframe_P.States_Y0), 25, 0, 1 },

  { (char_T *)(&Mainframe_P.CalibrationTime_Y0), 0, 0, 2551 },

  { (char_T *)(&Mainframe_P.Zero_Value_i), 1, 0, 1 },

  { (char_T *)(&Mainframe_P.Constant_Value_hg), 5, 0, 3 },

  { (char_T *)(&Mainframe_P.One_Value), 8, 0, 1 },

  { (char_T *)(&Mainframe_P.Out1_Y0), 3, 0, 1 },

  { (char_T *)(&Mainframe_P.EnabledSubsystem1_h.CalibrationTime_Y0), 0, 0, 1 },

  { (char_T *)(&Mainframe_P.EnabledSubsystem1.CalibrationTime_Y0), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  12U,
  rtPTransitions
};

/* [EOF] Mainframe_dt.h */
