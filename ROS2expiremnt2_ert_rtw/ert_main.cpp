//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ert_main.cpp
//
// Code generated for Simulink model 'ROS2expiremnt2'.
//
// Model version                  : 1.1
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Tue May 18 11:54:54 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "ROS2expiremnt2.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  // Check for overrun. Protect OverrunFlag against preemption
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  ROS2expiremnt2_step();

  // Get model outputs here
  OverrunFlag--;
}

#define UNUSED(x)                      x = x

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(int argc, char **argv)
{
  float modelBaseRate = 0.01;
  float systemClock = 0;

  // Initialize variables
  stopRequested = false;
  runModel = false;
  UNUSED(modelBaseRate);
  UNUSED(systemClock);
  rtmSetErrorStatus(ROS2expiremnt2_M, 0);
  ROS2expiremnt2_initialize();
  runModel =
    rtmGetErrorStatus(ROS2expiremnt2_M) == (NULL);
  while (runModel) {
    rt_OneStep();
    stopRequested = !(
                      rtmGetErrorStatus(ROS2expiremnt2_M) == (NULL));
    runModel = !(stopRequested);
  }

  // Disable rt_OneStep() here

  // Terminate model
  ROS2expiremnt2_terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
