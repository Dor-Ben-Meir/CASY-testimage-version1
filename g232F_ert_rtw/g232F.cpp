//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: g232F.cpp
//
// Code generated for Simulink model 'g232F'.
//
// Model version                  : 1.140
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Thu Apr 15 15:32:05 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "g232F.h"
#include "g232F_private.h"

// Block signals (default storage)
B_g232F_T g232F_B;

// Block states (default storage)
DW_g232F_T g232F_DW;

// Real-time model
RT_MODEL_g232F_T g232F_M_ = RT_MODEL_g232F_T();
RT_MODEL_g232F_T *const g232F_M = &g232F_M_;

// Model step function
void g232F_step(void)
{
  px4_Bus_sensor_gyro b_varargout_2;

  // MATLABSystem: '<S17>/SourceBlock'
  uORB_read_step(g232F_DW.obj.orbMetadataObj, &g232F_DW.obj.eventStructObj,
                 &g232F_B.b_varargout_2, false, 1.0);

  // MATLABSystem: '<S5>/SourceBlock'
  uORB_read_step(g232F_DW.obj_o.orbMetadataObj, &g232F_DW.obj_o.eventStructObj,
                 &g232F_B.b_varargout_2_m, false, 1.0);

  // MATLABSystem: '<S7>/SourceBlock'
  uORB_read_step(g232F_DW.obj_b.orbMetadataObj, &g232F_DW.obj_b.eventStructObj,
                 &b_varargout_2, false, 1.0);
}

// Model initialize function
void g232F_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Start for MATLABSystem: '<S17>/SourceBlock'
  g232F_DW.obj.matlabCodegenIsDeleted = false;
  g232F_DW.obj.isSetupComplete = false;
  g232F_DW.obj.isInitialized = 1;
  g232F_DW.obj.orbMetadataObj = ORB_ID(vehicle_odometry);
  uORB_read_initialize(g232F_DW.obj.orbMetadataObj, &g232F_DW.obj.eventStructObj);
  g232F_DW.obj.isSetupComplete = true;

  // Start for MATLABSystem: '<S5>/SourceBlock'
  g232F_DW.obj_o.matlabCodegenIsDeleted = false;
  g232F_DW.obj_o.isSetupComplete = false;
  g232F_DW.obj_o.isInitialized = 1;
  g232F_DW.obj_o.orbMetadataObj = ORB_ID(sensor_accel);
  uORB_read_initialize(g232F_DW.obj_o.orbMetadataObj,
                       &g232F_DW.obj_o.eventStructObj);
  g232F_DW.obj_o.isSetupComplete = true;

  // Start for MATLABSystem: '<S7>/SourceBlock'
  g232F_DW.obj_b.matlabCodegenIsDeleted = false;
  g232F_DW.obj_b.isSetupComplete = false;
  g232F_DW.obj_b.isInitialized = 1;
  g232F_DW.obj_b.orbMetadataObj = ORB_ID(sensor_gyro);
  uORB_read_initialize(g232F_DW.obj_b.orbMetadataObj,
                       &g232F_DW.obj_b.eventStructObj);
  g232F_DW.obj_b.isSetupComplete = true;
}

// Model terminate function
void g232F_terminate(void)
{
  // Terminate for MATLABSystem: '<S17>/SourceBlock'
  if (!g232F_DW.obj.matlabCodegenIsDeleted) {
    g232F_DW.obj.matlabCodegenIsDeleted = true;
    if ((g232F_DW.obj.isInitialized == 1) && g232F_DW.obj.isSetupComplete) {
      uORB_read_terminate(&g232F_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S17>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!g232F_DW.obj_o.matlabCodegenIsDeleted) {
    g232F_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((g232F_DW.obj_o.isInitialized == 1) && g232F_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&g232F_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!g232F_DW.obj_b.matlabCodegenIsDeleted) {
    g232F_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((g232F_DW.obj_b.isInitialized == 1) && g232F_DW.obj_b.isSetupComplete) {
      uORB_read_terminate(&g232F_DW.obj_b.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
