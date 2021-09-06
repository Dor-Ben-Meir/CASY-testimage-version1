//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: GPS32.cpp
//
// Code generated for Simulink model 'GPS32'.
//
// Model version                  : 1.153
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Sun May  9 18:57:43 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "GPS32.h"
#include "GPS32_private.h"

// Block signals (default storage)
B_GPS32_T GPS32_B;

// Block states (default storage)
DW_GPS32_T GPS32_DW;

// External outputs (root outports fed by signals with default storage)
ExtY_GPS32_T GPS32_Y;

// Real-time model
RT_MODEL_GPS32_T GPS32_M_ = RT_MODEL_GPS32_T();
RT_MODEL_GPS32_T *const GPS32_M = &GPS32_M_;

// Model step function
void GPS32_step(void)
{
  // MATLABSystem: '<S2>/SourceBlock'
  uORB_read_step(GPS32_DW.obj_i.orbMetadataObj, &GPS32_DW.obj_i.eventStructObj,
                 &GPS32_B.b_varargout_2, false, 1.0);

  // MATLABSystem: '<S3>/SourceBlock'
  uORB_read_step(GPS32_DW.obj.orbMetadataObj, &GPS32_DW.obj.eventStructObj,
                 &GPS32_B.b_varargout_2_m, false, 1.0);

  // Outport: '<Root>/Out1'
  GPS32_Y.Out1 = 0.0;
}

// Model initialize function
void GPS32_initialize(void)
{
  // Start for MATLABSystem: '<S2>/SourceBlock'
  GPS32_DW.obj_i.matlabCodegenIsDeleted = false;
  GPS32_DW.obj_i.isSetupComplete = false;
  GPS32_DW.obj_i.isInitialized = 1;
  GPS32_DW.obj_i.orbMetadataObj = ORB_ID(vehicle_local_position);
  uORB_read_initialize(GPS32_DW.obj_i.orbMetadataObj,
                       &GPS32_DW.obj_i.eventStructObj);
  GPS32_DW.obj_i.isSetupComplete = true;

  // Start for MATLABSystem: '<S3>/SourceBlock'
  GPS32_DW.obj.matlabCodegenIsDeleted = false;
  GPS32_DW.obj.isSetupComplete = false;
  GPS32_DW.obj.isInitialized = 1;
  GPS32_DW.obj.orbMetadataObj = ORB_ID(vehicle_gps_position);
  uORB_read_initialize(GPS32_DW.obj.orbMetadataObj, &GPS32_DW.obj.eventStructObj);
  GPS32_DW.obj.isSetupComplete = true;
}

// Model terminate function
void GPS32_terminate(void)
{
  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  if (!GPS32_DW.obj_i.matlabCodegenIsDeleted) {
    GPS32_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((GPS32_DW.obj_i.isInitialized == 1) && GPS32_DW.obj_i.isSetupComplete) {
      uORB_read_terminate(&GPS32_DW.obj_i.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S2>/SourceBlock'

  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!GPS32_DW.obj.matlabCodegenIsDeleted) {
    GPS32_DW.obj.matlabCodegenIsDeleted = true;
    if ((GPS32_DW.obj.isInitialized == 1) && GPS32_DW.obj.isSetupComplete) {
      uORB_read_terminate(&GPS32_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
