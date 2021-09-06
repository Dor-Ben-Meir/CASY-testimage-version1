/*
 * Mainframe.h
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

#ifndef RTW_HEADER_Mainframe_h_
#define RTW_HEADER_Mainframe_h_
#include <math.h>
#include <string.h>
#ifndef Mainframe_COMMON_INCLUDES_
# define Mainframe_COMMON_INCLUDES_
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* Mainframe_COMMON_INCLUDES_ */

#include "Mainframe_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_zcfcn.h"
#include "rt_assert.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define Mainframe_rtModel              RT_MODEL_Mainframe_T

/* Block signals for system '<S1>/Enabled Subsystem1' */
typedef struct {
  real_T DigitalClock;                 /* '<S31>/Digital Clock' */
} B_EnabledSubsystem1_Mainframe_T;

/* Block states (default storage) for system '<S1>/Enabled Subsystem1' */
typedef struct {
  int8_T EnabledSubsystem1_SubsysRanBC;/* '<S1>/Enabled Subsystem1' */
} DW_EnabledSubsystem1_Mainframe_T;

/* Zero-crossing (trigger) state for system '<S1>/Enabled Subsystem1' */
typedef struct {
  ZCSigState EnabledSubsystem1_Trig_ZCE;/* '<S1>/Enabled Subsystem1' */
} ZCE_EnabledSubsystem1_Mainframe_T;

/* Block signals for system '<S153>/Limiting_Acceleration' */
typedef struct {
  real_T dd_siB_l;                     /* '<S153>/Limiting_Acceleration' */
} B_Limiting_Acceleration_Mainframe_T;

/* Block signals for system '<S153>/Limiting_Rate' */
typedef struct {
  real_T d_siB_l;                      /* '<S153>/Limiting_Rate' */
} B_Limiting_Rate_Mainframe_T;

/* Block signals (default storage) */
typedef struct {
  real_T Fin_1;                        /* '<S289>/Gain' */
  real_T Fin_2;                        /* '<S289>/Gain1' */
  real_T Fin_3;                        /* '<S289>/Gain2' */
  real_T Fin_4;                        /* '<S289>/Gain3' */
  real_T siB_cmd[4];                   /* '<S281>/Product' */
  real_T Gain;                         /* '<S9>/Gain' */
  real_T Gain_f;                       /* '<S22>/Gain' */
  real_T Gain_n;                       /* '<S23>/Gain' */
  real_T Gain_p;                       /* '<S12>/Gain' */
  real_T Gain_b;                       /* '<S11>/Gain' */
  real_T Gain_i;                       /* '<S10>/Gain' */
  real_T gimbalPhi;                    /* '<S68>/Zero1' */
  real_T Gain_br;                      /* '<S8>/Gain' */
  real_T gimbalTheta;                  /* '<S68>/Zero' */
  real_T Gain_e;                       /* '<S13>/Gain' */
  real_T gimbalPsi;                    /* '<S68>/Zero2' */
  real_T Gain_o;                       /* '<S14>/Gain' */
  real_T Fin_1_Cmd_rad;                /* '<S58>/Cast To Double1' */
  real_T Gain_h;                       /* '<S19>/Gain' */
  real_T Fin_2_Cmd_rad;                /* '<S58>/Cast To Double2' */
  real_T Gain_a;                       /* '<S15>/Gain' */
  real_T Fin_3_Cmd_rad;                /* '<S58>/Cast To Double3' */
  real_T Gain_k;                       /* '<S20>/Gain' */
  real_T Fin_4_Cmd_rad;                /* '<S58>/Cast To Double4' */
  real_T Gain_d;                       /* '<S16>/Gain' */
  real_T Gain_j;                       /* '<S21>/Gain' */
  real_T Gain_kd;                      /* '<S25>/Gain' */
  real_T Gain_oi;                      /* '<S24>/Gain' */
  real_T Gain_is;                      /* '<S26>/Gain' */
  real_T Gain_m;                       /* '<S17>/Gain' */
  real_T Integrator;                   /* '<Root>/Integrator' */
  real_T p;                            /* '<S2>/Zero1' */
  real_T q;                            /* '<S2>/Zero2' */
  real_T r;                            /* '<S2>/Zero6' */
  real_T phi;                          /* '<S2>/Zero5' */
  real_T theta;                        /* '<S2>/Zero4' */
  real_T psi;                          /* '<S2>/Zero3' */
  real_T Gain_l[3];                    /* '<S36>/Gain' */
  real_T Product[3];                   /* '<S39>/Product' */
  real_T Saturation[3];                /* '<S36>/Saturation' */
  real_T Product_i[3];                 /* '<S53>/Product' */
  real_T Saturation_g[3];              /* '<S37>/Saturation' */
  real_T gyroX;                        /* '<S58>/Cast To Double5' */
  real_T gyroY;                        /* '<S58>/Cast To Double6' */
  real_T gyroZ;                        /* '<S58>/Cast To Double7' */
  real_T u;                            /* '<S58>/Cast To Double8' */
  real_T v;                            /* '<S58>/Cast To Double9' */
  real_T w;                            /* '<S58>/Cast To Double10' */
  real_T x;                            /* '<S58>/Cast To Double12' */
  real_T y;                            /* '<S58>/Cast To Double13' */
  real_T z;                            /* '<S58>/Cast To Double14' */
  real_T p_a;                          /* '<S58>/Cast To Double15' */
  real_T q_l;                          /* '<S58>/Cast To Double16' */
  real_T r_h;                          /* '<S58>/Cast To Double11' */
  real_T SquareRoot1;                  /* '<Root>/Square Root1' */
  real_T Sum;                          /* '<S29>/Sum' */
  real_T Sum_g;                        /* '<S30>/Sum' */
  real_T phicmdrad;                    /* '<S1>/Sum' */
  real_T phicmdrad_m;                  /* '<S1>/Product' */
  real_T Sum2[3];                      /* '<S43>/Sum2' */
  real_T Sum2_k[3];                    /* '<S55>/Sum2' */
  real_T debug;                        /* '<S58>/Cast To Double17' */
  real_T FccDelay;                     /* '<S57>/Saturation' */
  real_T Gain_fp;                      /* '<S18>/Gain' */
  real_T Constant[13];                 /* '<S210>/Constant' */
  real_T x_d[13];                      /* '<S240>/integration_eom' */
  real_T ComplextoRealImag[3];         /* '<S78>/Complex to Real-Imag' */
  real_T q0;                           /* '<S80>/q0' */
  real_T q1;                           /* '<S80>/q1' */
  real_T q2;                           /* '<S80>/q2' */
  real_T q3;                           /* '<S80>/q3' */
  real_T Constant8[4];                 /* '<S185>/Constant8' */
  real_T wIEE[3];                      /* '<S184>/Switch' */
  real_T sat;                          /* '<S153>/Integrator1' */
  real_T Gain3;                        /* '<S153>/Gain3' */
  real_T sat_d;                        /* '<S154>/Integrator1' */
  real_T Gain3_g;                      /* '<S154>/Gain3' */
  real_T sat_a;                        /* '<S155>/Integrator1' */
  real_T Gain3_o;                      /* '<S155>/Gain3' */
  real_T sat_p;                        /* '<S156>/Integrator1' */
  real_T Gain3_i;                      /* '<S156>/Gain3' */
  real_T Tmp_ref;                      /* '<S150>/Subtract1' */
  real_T Product_n;                    /* '<S217>/Product' */
  real_T Divide;                       /* '<S217>/Divide' */
  real_T Subtract1;                    /* '<S217>/Subtract1' */
  real_T Subtract;                     /* '<S216>/Subtract' */
  real_T Switch[3];                    /* '<S211>/Switch' */
  real_T pa_ref;                       /* '<S150>/Subtract2' */
  real_T hBE_0;                        /* '<S128>/Switch1' */
  real_T VectorConcatenate[3];         /* '<S126>/Vector Concatenate' */
  real_T Constant8_a[4];               /* '<S186>/Constant8' */
  real_T e2;                           /* '<S145>/Divide' */
  real_T Add1;                         /* '<S143>/Add1' */
  real_T hBE_0_i;                      /* '<S167>/Switch1' */
  real_T VectorConcatenate_g[3];       /* '<S166>/Vector Concatenate' */
  real_T T12[9];                       /* '<S198>/3. Rotation' */
  real_T VectorConcatenate_c[4];       /* '<S246>/Vector Concatenate' */
  real_T aBIB[3];                      /* '<S209>/Product' */
  real_T Gain_ln[3];                   /* '<S83>/Gain' */
  real_T Product_a;                    /* '<S257>/Product' */
  real_T Product2;                     /* '<S257>/Product2' */
  real_T Product4;                     /* '<S257>/Product4' */
  real_T T12_a[9];                     /* '<S266>/3. Rotation' */
  real_T Subtract_k[9];                /* '<S261>/Subtract' */
  real_T Subtract4;                    /* '<S261>/Subtract4' */
  real_T MathFunction[9];              /* '<S262>/Math Function' */
  real_T pAPB[3];                      /* '<S124>/Vector Concatenate' */
  real_T hBE_0_c;                      /* '<S132>/Switch1' */
  real_T VectorConcatenate_h[3];       /* '<S127>/Vector Concatenate' */
  real_T d_wBIB[3];                    /* '<S240>/Reshape1' */
  real_T Sum2_b[3];                    /* '<S90>/Sum2' */
  real_T Product_k[3];                 /* '<S86>/Product' */
  real_T Saturation_j[3];              /* '<S83>/Saturation' */
  real_T Sum2_h[3];                    /* '<S102>/Sum2' */
  real_T Product_g[3];                 /* '<S100>/Product' */
  real_T Saturation_je[3];             /* '<S84>/Saturation' */
  real_T Add[16];                      /* '<S188>/Add' */
  real_T VectorConcatenate_m[4];       /* '<S191>/Vector Concatenate' */
  real_T wEGG[3];                      /* '<S187>/Vector Concatenate1' */
  real_T VectorConcatenate_d[4];       /* '<S192>/Vector Concatenate' */
  real_T VectorConcatenate_e[4];       /* '<S195>/Vector Concatenate' */
  real_T vBIB[3];                      /* '<S209>/Product1' */
  real_T VectorConcatenate_f[4];       /* '<S244>/Vector Concatenate' */
  real_T d_x[13];                      /* '<S240>/Vector Concatenate' */
  real_T VectorConcatenate1[3];        /* '<S211>/Vector Concatenate1' */
  real_T DigitalClock;                 /* '<S3>/Digital Clock' */
  real32_T CastToSingle18;             /* '<S59>/Cast To Single18' */
  real32_T RateTransition;             /* '<S57>/Rate Transition' */
  real32_T CastToSingle;               /* '<S57>/Cast To Single' */
  real32_T CastToSingle19;             /* '<S59>/Cast To Single19' */
  real32_T CastToSingle17;             /* '<S59>/Cast To Single17' */
  real32_T CastToSingle16;             /* '<S59>/Cast To Single16' */
  real32_T CastToSingle15;             /* '<S59>/Cast To Single15' */
  real32_T CastToSingle14;             /* '<S59>/Cast To Single14' */
  real32_T CastToSingle13;             /* '<S59>/Cast To Single13' */
  real32_T CastToSingle12;             /* '<S59>/Cast To Single12' */
  real32_T CastToSingle11;             /* '<S59>/Cast To Single11' */
  real32_T CastToSingle10;             /* '<S59>/Cast To Single10' */
  real32_T CastToSingle9;              /* '<S59>/Cast To Single9' */
  real32_T CastToSingle8;              /* '<S59>/Cast To Single8' */
  real32_T CastToSingle7;              /* '<S59>/Cast To Single7' */
  real32_T CastToSingle6;              /* '<S59>/Cast To Single6' */
  real32_T CastToSingle5;              /* '<S59>/Cast To Single5' */
  real32_T CastToSingle4;              /* '<S59>/Cast To Single4' */
  real32_T CastToSingle3;              /* '<S59>/Cast To Single3' */
  real32_T CastToSingle2;              /* '<S59>/Cast To Single2' */
  real32_T CastToSingle1;              /* '<S59>/Cast To Single1' */
  real32_T CastToSingle21;             /* '<S59>/Cast To Single21' */
  real32_T CastToSingle22;             /* '<S59>/Cast To Single22' */
  real32_T CastToSingle23;             /* '<S59>/Cast To Single23' */
  real32_T CastToSingle20;             /* '<S59>/Cast To Single20' */
  uint16_T FixPtSwitch;                /* '<S66>/FixPt Switch' */
  uint8_T PacketInput_o1[75];          /* '<S60>/Packet Input' */
  uint8_T In1[75];                     /* '<S61>/In1' */
  boolean_T PacketInput_o2;            /* '<S60>/Packet Input' */
  boolean_T GreaterThan;               /* '<S29>/GreaterThan' */
  boolean_T GreaterThan_e;             /* '<S30>/GreaterThan' */
  boolean_T GreaterThan_c;             /* '<S28>/GreaterThan' */
  boolean_T AND;                       /* '<S69>/AND' */
  boolean_T Compare;                   /* '<S140>/Compare' */
  boolean_T AND_c;                     /* '<S141>/AND' */
  boolean_T AND_cl;                    /* '<S142>/AND' */
  boolean_T q_R0R;                     /* '<S218>/Logical Operator' */
  boolean_T q_R1R;                     /* '<S219>/Logical Operator' */
  boolean_T q_R2R;                     /* '<S220>/Logical Operator' */
  boolean_T q_R3R;                     /* '<S221>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_q_R0R_at_inport_1;/* '<S212>/Case 0' */
  boolean_T HiddenBuf_InsertedFor_q_R1R_at_inport_1;/* '<S212>/Case 1' */
  boolean_T HiddenBuf_InsertedFor_q_R2R_at_inport_1;/* '<S212>/Case 2' */
  boolean_T HiddenBuf_InsertedFor_q_R3R_at_inport_1;/* '<S212>/Case 3' */
  B_EnabledSubsystem1_Mainframe_T EnabledSubsystem1_h;/* '<S72>/Enabled Subsystem1' */
  B_Limiting_Rate_Mainframe_T sf_Limiting_Rate_o;/* '<S156>/Limiting_Rate' */
  B_Limiting_Acceleration_Mainframe_T sf_Limiting_Acceleration_j;/* '<S156>/Limiting_Acceleration' */
  B_Limiting_Rate_Mainframe_T sf_Limiting_Rate_a;/* '<S155>/Limiting_Rate' */
  B_Limiting_Acceleration_Mainframe_T sf_Limiting_Acceleration_l;/* '<S155>/Limiting_Acceleration' */
  B_Limiting_Rate_Mainframe_T sf_Limiting_Rate_g;/* '<S154>/Limiting_Rate' */
  B_Limiting_Acceleration_Mainframe_T sf_Limiting_Acceleration_p;/* '<S154>/Limiting_Acceleration' */
  B_Limiting_Rate_Mainframe_T sf_Limiting_Rate;/* '<S153>/Limiting_Rate' */
  B_Limiting_Acceleration_Mainframe_T sf_Limiting_Acceleration;/* '<S153>/Limiting_Acceleration' */
  B_EnabledSubsystem1_Mainframe_T EnabledSubsystem1;/* '<S1>/Enabled Subsystem1' */
} B_Mainframe_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<Root>/Discrete-Time Integrator2' */
  real_T NextOutput[3];                /* '<S39>/White Noise' */
  real_T NextOutput_m[3];              /* '<S53>/White Noise' */
  real_T NextOutput_mb[3];             /* '<S86>/White Noise' */
  real_T NextOutput_i[3];              /* '<S100>/White Noise' */
  real_T TimeStampA;                   /* '<S187>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<S187>/Derivative1' */
  real_T TimeStampB;                   /* '<S187>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<S187>/Derivative1' */
  real_T TimeStampA_i;                 /* '<S187>/Derivative' */
  real_T LastUAtTimeA_d;               /* '<S187>/Derivative' */
  real_T TimeStampB_c;                 /* '<S187>/Derivative' */
  real_T LastUAtTimeB_g;               /* '<S187>/Derivative' */
  struct {
    void *LoggedData[9];
  } Attitude_PWORK;                    /* '<Root>/Attitude' */

  void *PacketInput_PWORK;             /* '<S60>/Packet Input' */
  struct {
    void *LoggedData[8];
  } FinDeflections_PWORK;              /* '<Root>/Fin Deflections' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *AQHandles[12];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_EmulateEstimator_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_EnabledSubsystem1_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *AQHandles[4];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_From5_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *AQHandles[28];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_From6_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *AQHandles[16];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_From7_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *AQHandles[3];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_From8_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *LoggedData;
  } U1_PWORK;                          /* '<Root>/U1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_n;                     /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     /* '<S28>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_g;                     /* '<S29>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_gw;                    /* '<S30>/Scope' */

  struct {
    void *LoggedData;
  } Debug_PWORK;                       /* '<S4>/Debug' */

  struct {
    void *LoggedData;
  } FCCSync_PWORK;                     /* '<S4>/FCC Sync' */

  struct {
    void *LoggedData;
  } Scope_PWORK_a;                     /* '<S60>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_p;                    /* '<S60>/Scope1' */

  void *PacketOutput_PWORK[2];         /* '<S60>/Packet Output' */
  struct {
    void *LoggedData;
  } FccDelay_PWORK;                    /* '<S57>/FccDelay' */

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     /* '<S59>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_oh;                    /* '<S289>/Scope' */

  void* Assertion_slioAccessor;        /* '<S137>/Assertion' */
  void* Assertion1_slioAccessor;       /* '<S137>/Assertion1' */
  void* Assertion2_slioAccessor;       /* '<S137>/Assertion2' */
  struct {
    void *LoggedData;
  } Scope_PWORK_n4;                    /* '<S251>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;                    /* '<S251>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S251>/Scope2' */

  uint32_T RandSeed[3];                /* '<S39>/White Noise' */
  uint32_T RandSeed_g[3];              /* '<S53>/White Noise' */
  uint32_T RandSeed_gr[3];             /* '<S86>/White Noise' */
  uint32_T RandSeed_i[3];              /* '<S100>/White Noise' */
  int_T integration_eom_IWORK;         /* '<S240>/integration_eom' */
  int_T integration_eom_IWORK_p;       /* '<S185>/integration_eom' */
  int_T integration_eom_IWORK_g;       /* '<S186>/integration_eom' */
  int_T IntegratorSecondOrderLimited_MODE[3];
                                  /* '<S43>/Integrator, Second-Order Limited' */
  int_T IntegratorSecondOrderLimited_MODE_e[3];
                                  /* '<S55>/Integrator, Second-Order Limited' */
  int_T IntegratorSecondOrderLimited_MODE_h[3];
                                  /* '<S90>/Integrator, Second-Order Limited' */
  int_T IntegratorSecondOrderLimited_MODE_a[3];
                                 /* '<S102>/Integrator, Second-Order Limited' */
  uint16_T Output_DSTATE;              /* '<S64>/Output' */
  int8_T Subsystem_SubsysRanBC;        /* '<S7>/Subsystem' */
  int8_T q_R3R_SubsysRanBC;            /* '<S212>/q_R^3(R)' */
  int8_T q_R2R_SubsysRanBC;            /* '<S212>/q_R^2(R)' */
  int8_T q_R1R_SubsysRanBC;            /* '<S212>/q_R^1(R)' */
  int8_T q_R0R_SubsysRanBC;            /* '<S212>/q_R^0(R)' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S60>/Enabled Subsystem' */
  int8_T EnabledSubsystem1_SubsysRanBC;/* '<Root>/Enabled Subsystem1' */
  boolean_T IntegratorSecondOrderLimited_DWORK1;
                                  /* '<S43>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited_DWORK1_c;
                                  /* '<S55>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited_DWORK1_a;
                                  /* '<S90>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited_DWORK1_i;
                                 /* '<S102>/Integrator, Second-Order Limited' */
  boolean_T Subsystem_MODE;            /* '<S7>/Subsystem' */
  boolean_T q_R3R_MODE;                /* '<S212>/q_R^3(R)' */
  boolean_T q_R2R_MODE;                /* '<S212>/q_R^2(R)' */
  boolean_T q_R1R_MODE;                /* '<S212>/q_R^1(R)' */
  boolean_T q_R0R_MODE;                /* '<S212>/q_R^0(R)' */
  DW_EnabledSubsystem1_Mainframe_T EnabledSubsystem1_h;/* '<S72>/Enabled Subsystem1' */
  DW_EnabledSubsystem1_Mainframe_T EnabledSubsystem1;/* '<S1>/Enabled Subsystem1' */
} DW_Mainframe_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE[2];       /* '<S289>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S289>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S289>/Transfer Fcn3' */
  real_T TransferFcn4_CSTATE[2];       /* '<S289>/Transfer Fcn4' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T IntegratorSecondOrderLimited_CSTATE[6];
                                  /* '<S43>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited_CSTATE_c[6];
                                  /* '<S55>/Integrator, Second-Order Limited' */
  real_T integration_eom_CSTATE[13];   /* '<S240>/integration_eom' */
  real_T integration_eom_CSTATE_o[4];  /* '<S185>/integration_eom' */
  real_T Integrator1_CSTATE;           /* '<S153>/Integrator1' */
  real_T Integrator1_CSTATE_n;         /* '<S154>/Integrator1' */
  real_T Integrator1_CSTATE_k;         /* '<S155>/Integrator1' */
  real_T Integrator1_CSTATE_f;         /* '<S156>/Integrator1' */
  real_T integration_eom_CSTATE_k[4];  /* '<S186>/integration_eom' */
  real_T IntegratorSecondOrderLimited_CSTATE_g[6];
                                  /* '<S90>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited_CSTATE_e[6];
                                 /* '<S102>/Integrator, Second-Order Limited' */
  real_T Integrator_CSTATE_j;          /* '<S153>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S154>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S155>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S156>/Integrator' */
} X_Mainframe_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE[2];       /* '<S289>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S289>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S289>/Transfer Fcn3' */
  real_T TransferFcn4_CSTATE[2];       /* '<S289>/Transfer Fcn4' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T IntegratorSecondOrderLimited_CSTATE[6];
                                  /* '<S43>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited_CSTATE_c[6];
                                  /* '<S55>/Integrator, Second-Order Limited' */
  real_T integration_eom_CSTATE[13];   /* '<S240>/integration_eom' */
  real_T integration_eom_CSTATE_o[4];  /* '<S185>/integration_eom' */
  real_T Integrator1_CSTATE;           /* '<S153>/Integrator1' */
  real_T Integrator1_CSTATE_n;         /* '<S154>/Integrator1' */
  real_T Integrator1_CSTATE_k;         /* '<S155>/Integrator1' */
  real_T Integrator1_CSTATE_f;         /* '<S156>/Integrator1' */
  real_T integration_eom_CSTATE_k[4];  /* '<S186>/integration_eom' */
  real_T IntegratorSecondOrderLimited_CSTATE_g[6];
                                  /* '<S90>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited_CSTATE_e[6];
                                 /* '<S102>/Integrator, Second-Order Limited' */
  real_T Integrator_CSTATE_j;          /* '<S153>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S154>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S155>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S156>/Integrator' */
} XDot_Mainframe_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE[2];    /* '<S289>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE[2];    /* '<S289>/Transfer Fcn2' */
  boolean_T TransferFcn3_CSTATE[2];    /* '<S289>/Transfer Fcn3' */
  boolean_T TransferFcn4_CSTATE[2];    /* '<S289>/Transfer Fcn4' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T IntegratorSecondOrderLimited_CSTATE[6];
                                  /* '<S43>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited_CSTATE_c[6];
                                  /* '<S55>/Integrator, Second-Order Limited' */
  boolean_T integration_eom_CSTATE[13];/* '<S240>/integration_eom' */
  boolean_T integration_eom_CSTATE_o[4];/* '<S185>/integration_eom' */
  boolean_T Integrator1_CSTATE;        /* '<S153>/Integrator1' */
  boolean_T Integrator1_CSTATE_n;      /* '<S154>/Integrator1' */
  boolean_T Integrator1_CSTATE_k;      /* '<S155>/Integrator1' */
  boolean_T Integrator1_CSTATE_f;      /* '<S156>/Integrator1' */
  boolean_T integration_eom_CSTATE_k[4];/* '<S186>/integration_eom' */
  boolean_T IntegratorSecondOrderLimited_CSTATE_g[6];
                                  /* '<S90>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited_CSTATE_e[6];
                                 /* '<S102>/Integrator, Second-Order Limited' */
  boolean_T Integrator_CSTATE_j;       /* '<S153>/Integrator' */
  boolean_T Integrator_CSTATE_g;       /* '<S154>/Integrator' */
  boolean_T Integrator_CSTATE_f;       /* '<S155>/Integrator' */
  boolean_T Integrator_CSTATE_o;       /* '<S156>/Integrator' */
} XDis_Mainframe_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCE_EnabledSubsystem1_Mainframe_T EnabledSubsystem1_h;/* '<S72>/Enabled Subsystem1' */
  ZCSigState Integrator_Reset_ZCE;     /* '<S153>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_e;   /* '<S154>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_o;   /* '<S155>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_p;   /* '<S156>/Integrator' */
  ZCSigState EnabledSubsystem_Trig_ZCE;/* '<S60>/Enabled Subsystem' */
  ZCSigState EnabledSubsystem1_Trig_ZCE_b;/* '<Root>/Enabled Subsystem1' */
  ZCE_EnabledSubsystem1_Mainframe_T EnabledSubsystem1;/* '<S1>/Enabled Subsystem1' */
} PrevZCX_Mainframe_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            Mainframe_B
#define BlockIO                        B_Mainframe_T
#define rtX                            Mainframe_X
#define ContinuousStates               X_Mainframe_T
#define rtXdot                         Mainframe_XDot
#define StateDerivatives               XDot_Mainframe_T
#define tXdis                          Mainframe_XDis
#define StateDisabled                  XDis_Mainframe_T
#define rtP                            Mainframe_P
#define Parameters                     P_Mainframe_T
#define rtDWork                        Mainframe_DW
#define D_Work                         DW_Mainframe_T
#define rtPrevZCSigState               Mainframe_PrevZCX
#define PrevZCSigStates                PrevZCX_Mainframe_T

/* Parameters for system: '<S1>/Enabled Subsystem1' */
struct P_EnabledSubsystem1_Mainframe_T_ {
  real_T CalibrationTime_Y0;           /* Expression: 0
                                        * Referenced by: '<S31>/CalibrationTime'
                                        */
};

/* Parameters (default storage) */
struct P_Mainframe_T_ {
  real32_T INS_Passthrough;            /* Variable: INS_Passthrough
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real32_T Real_Gyros;                 /* Variable: Real_Gyros
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T PacketInput_MaxMissedTicks;
                                   /* Mask Parameter: PacketInput_MaxMissedTicks
                                    * Referenced by: '<S60>/Packet Input'
                                    */
  real_T PacketOutput_MaxMissedTicks;
                                  /* Mask Parameter: PacketOutput_MaxMissedTicks
                                   * Referenced by: '<S60>/Packet Output'
                                   */
  real_T Randombias_Ts;                /* Mask Parameter: Randombias_Ts
                                        * Referenced by: '<S86>/Constant1'
                                        */
  real_T Randombias_Ts_n;              /* Mask Parameter: Randombias_Ts_n
                                        * Referenced by: '<S100>/Constant1'
                                        */
  real_T Randombias_Ts_i;              /* Mask Parameter: Randombias_Ts_i
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real_T Randombias_Ts_h;              /* Mask Parameter: Randombias_Ts_h
                                        * Referenced by: '<S53>/Constant1'
                                        */
  real_T PacketInput_YieldWhenWaiting;
                                 /* Mask Parameter: PacketInput_YieldWhenWaiting
                                  * Referenced by: '<S60>/Packet Input'
                                  */
  real_T PacketOutput_YieldWhenWaiting;
                                /* Mask Parameter: PacketOutput_YieldWhenWaiting
                                 * Referenced by: '<S60>/Packet Output'
                                 */
  real_T ThreeaxisInertialMeasurementUnit_a_bias[3];
                      /* Mask Parameter: ThreeaxisInertialMeasurementUnit_a_bias
                       * Referenced by: '<S83>/Measurement bias'
                       */
  real_T ThreeaxisInertialMeasurementUnit_a_bias_h[3];
                    /* Mask Parameter: ThreeaxisInertialMeasurementUnit_a_bias_h
                     * Referenced by: '<S36>/Measurement bias'
                     */
  real_T ThreeaxisAccelerometer_a_pow[3];
                                 /* Mask Parameter: ThreeaxisAccelerometer_a_pow
                                  * Referenced by: '<S86>/Constant'
                                  */
  real_T ThreeaxisAccelerometer_a_pow_e[3];
                               /* Mask Parameter: ThreeaxisAccelerometer_a_pow_e
                                * Referenced by: '<S39>/Constant'
                                */
  real_T ThreeaxisAccelerometer_a_seeds[3];
                               /* Mask Parameter: ThreeaxisAccelerometer_a_seeds
                                * Referenced by: '<S86>/White Noise'
                                */
  real_T ThreeaxisAccelerometer_a_seeds_a[3];
                             /* Mask Parameter: ThreeaxisAccelerometer_a_seeds_a
                              * Referenced by: '<S39>/White Noise'
                              */
  real_T ThreeaxisInertialMeasurementUnit_a_sf_cc[9];
                     /* Mask Parameter: ThreeaxisInertialMeasurementUnit_a_sf_cc
                      * Referenced by: '<S83>/Scale factors & Cross-coupling  errors'
                      */
  real_T ThreeaxisInertialMeasurementUnit_a_sf_cc_i[9];
                   /* Mask Parameter: ThreeaxisInertialMeasurementUnit_a_sf_cc_i
                    * Referenced by: '<S36>/Scale factors & Cross-coupling  errors'
                    */
  real_T DelayedSine_amp;              /* Mask Parameter: DelayedSine_amp
                                        * Referenced by: '<S28>/Sine Wave'
                                        */
  real_T DelayedSine_bias;             /* Mask Parameter: DelayedSine_bias
                                        * Referenced by: '<S28>/Sine Wave'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S140>/Constant'
                                       */
  real_T CompareToConstant_const_n; /* Mask Parameter: CompareToConstant_const_n
                                     * Referenced by: '<S73>/Constant'
                                     */
  real_T Rudder_d_siB_0;               /* Mask Parameter: Rudder_d_siB_0
                                        * Referenced by: '<S153>/Integrator'
                                        */
  real_T Rudder1_d_siB_0;              /* Mask Parameter: Rudder1_d_siB_0
                                        * Referenced by: '<S154>/Integrator'
                                        */
  real_T Rudder2_d_siB_0;              /* Mask Parameter: Rudder2_d_siB_0
                                        * Referenced by: '<S155>/Integrator'
                                        */
  real_T Rudder3_d_siB_0;              /* Mask Parameter: Rudder3_d_siB_0
                                        * Referenced by: '<S156>/Integrator'
                                        */
  real_T Rudder_d_siB_max;             /* Mask Parameter: Rudder_d_siB_max
                                        * Referenced by:
                                        *   '<S153>/Limiting_Acceleration'
                                        *   '<S153>/Limiting_Rate'
                                        */
  real_T Rudder1_d_siB_max;            /* Mask Parameter: Rudder1_d_siB_max
                                        * Referenced by:
                                        *   '<S154>/Limiting_Acceleration'
                                        *   '<S154>/Limiting_Rate'
                                        */
  real_T Rudder2_d_siB_max;            /* Mask Parameter: Rudder2_d_siB_max
                                        * Referenced by:
                                        *   '<S155>/Limiting_Acceleration'
                                        *   '<S155>/Limiting_Rate'
                                        */
  real_T Rudder3_d_siB_max;            /* Mask Parameter: Rudder3_d_siB_max
                                        * Referenced by:
                                        *   '<S156>/Limiting_Acceleration'
                                        *   '<S156>/Limiting_Rate'
                                        */
  real_T Rudder_d_siB_min;             /* Mask Parameter: Rudder_d_siB_min
                                        * Referenced by:
                                        *   '<S153>/Limiting_Acceleration'
                                        *   '<S153>/Limiting_Rate'
                                        */
  real_T Rudder1_d_siB_min;            /* Mask Parameter: Rudder1_d_siB_min
                                        * Referenced by:
                                        *   '<S154>/Limiting_Acceleration'
                                        *   '<S154>/Limiting_Rate'
                                        */
  real_T Rudder2_d_siB_min;            /* Mask Parameter: Rudder2_d_siB_min
                                        * Referenced by:
                                        *   '<S155>/Limiting_Acceleration'
                                        *   '<S155>/Limiting_Rate'
                                        */
  real_T Rudder3_d_siB_min;            /* Mask Parameter: Rudder3_d_siB_min
                                        * Referenced by:
                                        *   '<S156>/Limiting_Acceleration'
                                        *   '<S156>/Limiting_Rate'
                                        */
  real_T Rudder_dd_siB_max;            /* Mask Parameter: Rudder_dd_siB_max
                                        * Referenced by: '<S153>/Limiting_Acceleration'
                                        */
  real_T Rudder1_dd_siB_max;           /* Mask Parameter: Rudder1_dd_siB_max
                                        * Referenced by: '<S154>/Limiting_Acceleration'
                                        */
  real_T Rudder2_dd_siB_max;           /* Mask Parameter: Rudder2_dd_siB_max
                                        * Referenced by: '<S155>/Limiting_Acceleration'
                                        */
  real_T Rudder3_dd_siB_max;           /* Mask Parameter: Rudder3_dd_siB_max
                                        * Referenced by: '<S156>/Limiting_Acceleration'
                                        */
  real_T Rudder_dd_siB_min;            /* Mask Parameter: Rudder_dd_siB_min
                                        * Referenced by: '<S153>/Limiting_Acceleration'
                                        */
  real_T Rudder1_dd_siB_min;           /* Mask Parameter: Rudder1_dd_siB_min
                                        * Referenced by: '<S154>/Limiting_Acceleration'
                                        */
  real_T Rudder2_dd_siB_min;           /* Mask Parameter: Rudder2_dd_siB_min
                                        * Referenced by: '<S155>/Limiting_Acceleration'
                                        */
  real_T Rudder3_dd_siB_min;           /* Mask Parameter: Rudder3_dd_siB_min
                                        * Referenced by: '<S156>/Limiting_Acceleration'
                                        */
  real_T Rudder_dmp;                   /* Mask Parameter: Rudder_dmp
                                        * Referenced by: '<S153>/Gain2'
                                        */
  real_T Rudder1_dmp;                  /* Mask Parameter: Rudder1_dmp
                                        * Referenced by: '<S154>/Gain2'
                                        */
  real_T Rudder2_dmp;                  /* Mask Parameter: Rudder2_dmp
                                        * Referenced by: '<S155>/Gain2'
                                        */
  real_T Rudder3_dmp;                  /* Mask Parameter: Rudder3_dmp
                                        * Referenced by: '<S156>/Gain2'
                                        */
  real_T Rigid_Body_EOM_6_DOF_flag_Kraft;
                              /* Mask Parameter: Rigid_Body_EOM_6_DOF_flag_Kraft
                               * Referenced by: '<S239>/Constant'
                               */
  real_T WGS84_Gravitation_flg_omega_enabled;
                          /* Mask Parameter: WGS84_Gravitation_flg_omega_enabled
                           * Referenced by: '<S137>/WGS84_Gravity_Implementation'
                           */
  real_T DelayedSine_freq;             /* Mask Parameter: DelayedSine_freq
                                        * Referenced by: '<S28>/Sine Wave'
                                        */
  real_T ThreeaxisInertialMeasurementUnit_g_bias[3];
                      /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_bias
                       * Referenced by: '<S84>/Measurement bias'
                       */
  real_T ThreeaxisInertialMeasurementUnit_g_bias_o[3];
                    /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_bias_o
                     * Referenced by: '<S37>/Measurement bias'
                     */
  real_T ThreeaxisGyroscope_g_pow[3];/* Mask Parameter: ThreeaxisGyroscope_g_pow
                                      * Referenced by: '<S100>/Constant'
                                      */
  real_T ThreeaxisGyroscope_g_pow_h[3];
                                   /* Mask Parameter: ThreeaxisGyroscope_g_pow_h
                                    * Referenced by: '<S53>/Constant'
                                    */
  real_T ThreeaxisGyroscope_g_seeds[3];
                                   /* Mask Parameter: ThreeaxisGyroscope_g_seeds
                                    * Referenced by: '<S100>/White Noise'
                                    */
  real_T ThreeaxisGyroscope_g_seeds_o[3];
                                 /* Mask Parameter: ThreeaxisGyroscope_g_seeds_o
                                  * Referenced by: '<S53>/White Noise'
                                  */
  real_T ThreeaxisInertialMeasurementUnit_g_sens[3];
                      /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_sens
                       * Referenced by: '<S84>/g-sensitive bias'
                       */
  real_T ThreeaxisInertialMeasurementUnit_g_sens_m[3];
                    /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_sens_m
                     * Referenced by: '<S37>/g-sensitive bias'
                     */
  real_T ThreeaxisInertialMeasurementUnit_g_sf_cc[9];
                     /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_sf_cc
                      * Referenced by: '<S84>/Scale factors & Cross-coupling  errors '
                      */
  real_T ThreeaxisInertialMeasurementUnit_g_sf_cc_e[9];
                   /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_sf_cc_e
                    * Referenced by: '<S37>/Scale factors & Cross-coupling  errors '
                    */
  real_T ThreeaxisInertialMeasurementUnit_imu[3];
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_imu
                          * Referenced by: '<S83>/wl_ins'
                          */
  real_T ThreeaxisInertialMeasurementUnit_imu_p[3];
                       /* Mask Parameter: ThreeaxisInertialMeasurementUnit_imu_p
                        * Referenced by: '<S36>/wl_ins'
                        */
  real_T IntervalTest_lowlimit;        /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S141>/Lower Limit'
                                        */
  real_T IntervalTest1_lowlimit;       /* Mask Parameter: IntervalTest1_lowlimit
                                        * Referenced by: '<S142>/Lower Limit'
                                        */
  real_T geopot_height_mean_earth_radius;
                              /* Mask Parameter: geopot_height_mean_earth_radius
                               * Referenced by: '<S148>/mean_earth_radius'
                               */
  real_T Rudder_omega;                 /* Mask Parameter: Rudder_omega
                                        * Referenced by: '<S153>/Gain2'
                                        */
  real_T Rudder1_omega;                /* Mask Parameter: Rudder1_omega
                                        * Referenced by: '<S154>/Gain2'
                                        */
  real_T Rudder2_omega;                /* Mask Parameter: Rudder2_omega
                                        * Referenced by: '<S155>/Gain2'
                                        */
  real_T Rudder3_omega;                /* Mask Parameter: Rudder3_omega
                                        * Referenced by: '<S156>/Gain2'
                                        */
  real_T DelayedSine_phase;            /* Mask Parameter: DelayedSine_phase
                                        * Referenced by: '<S28>/Sine Wave'
                                        */
  real_T u_rot_mat_rot_1;              /* Mask Parameter: u_rot_mat_rot_1
                                        * Referenced by: '<S198>/Constant'
                                        */
  real_T u_rot_mat_rot_1_e;            /* Mask Parameter: u_rot_mat_rot_1_e
                                        * Referenced by: '<S266>/Constant'
                                        */
  real_T u_rot_mat_rot_2;              /* Mask Parameter: u_rot_mat_rot_2
                                        * Referenced by: '<S198>/Constant1'
                                        */
  real_T u_rot_mat_rot_2_a;            /* Mask Parameter: u_rot_mat_rot_2_a
                                        * Referenced by: '<S266>/Constant1'
                                        */
  real_T u_rot_mat_rot_3;              /* Mask Parameter: u_rot_mat_rot_3
                                        * Referenced by: '<S198>/Constant2'
                                        */
  real_T u_rot_mat_rot_3_a;            /* Mask Parameter: u_rot_mat_rot_3_a
                                        * Referenced by: '<S266>/Constant2'
                                        */
  real_T Rudder_siB_0;                 /* Mask Parameter: Rudder_siB_0
                                        * Referenced by: '<S153>/Integrator1'
                                        */
  real_T Rudder1_siB_0;                /* Mask Parameter: Rudder1_siB_0
                                        * Referenced by: '<S154>/Integrator1'
                                        */
  real_T Rudder2_siB_0;                /* Mask Parameter: Rudder2_siB_0
                                        * Referenced by: '<S155>/Integrator1'
                                        */
  real_T Rudder3_siB_0;                /* Mask Parameter: Rudder3_siB_0
                                        * Referenced by: '<S156>/Integrator1'
                                        */
  real_T Rudder_siB_max;               /* Mask Parameter: Rudder_siB_max
                                        * Referenced by:
                                        *   '<S153>/Limiting_Acceleration'
                                        *   '<S153>/Limiting_Rate'
                                        *   '<S153>/Integrator1'
                                        *   '<S153>/Saturation'
                                        *   '<S153>/Saturation1'
                                        */
  real_T Rudder1_siB_max;              /* Mask Parameter: Rudder1_siB_max
                                        * Referenced by:
                                        *   '<S154>/Limiting_Acceleration'
                                        *   '<S154>/Limiting_Rate'
                                        *   '<S154>/Integrator1'
                                        *   '<S154>/Saturation'
                                        *   '<S154>/Saturation1'
                                        */
  real_T Rudder2_siB_max;              /* Mask Parameter: Rudder2_siB_max
                                        * Referenced by:
                                        *   '<S155>/Limiting_Acceleration'
                                        *   '<S155>/Limiting_Rate'
                                        *   '<S155>/Integrator1'
                                        *   '<S155>/Saturation'
                                        *   '<S155>/Saturation1'
                                        */
  real_T Rudder3_siB_max;              /* Mask Parameter: Rudder3_siB_max
                                        * Referenced by:
                                        *   '<S156>/Limiting_Acceleration'
                                        *   '<S156>/Limiting_Rate'
                                        *   '<S156>/Integrator1'
                                        *   '<S156>/Saturation'
                                        *   '<S156>/Saturation1'
                                        */
  real_T Rudder_siB_min;               /* Mask Parameter: Rudder_siB_min
                                        * Referenced by:
                                        *   '<S153>/Limiting_Acceleration'
                                        *   '<S153>/Limiting_Rate'
                                        *   '<S153>/Integrator1'
                                        *   '<S153>/Saturation'
                                        *   '<S153>/Saturation1'
                                        */
  real_T Rudder1_siB_min;              /* Mask Parameter: Rudder1_siB_min
                                        * Referenced by:
                                        *   '<S154>/Limiting_Acceleration'
                                        *   '<S154>/Limiting_Rate'
                                        *   '<S154>/Integrator1'
                                        *   '<S154>/Saturation'
                                        *   '<S154>/Saturation1'
                                        */
  real_T Rudder2_siB_min;              /* Mask Parameter: Rudder2_siB_min
                                        * Referenced by:
                                        *   '<S155>/Limiting_Acceleration'
                                        *   '<S155>/Limiting_Rate'
                                        *   '<S155>/Integrator1'
                                        *   '<S155>/Saturation'
                                        *   '<S155>/Saturation1'
                                        */
  real_T Rudder3_siB_min;              /* Mask Parameter: Rudder3_siB_min
                                        * Referenced by:
                                        *   '<S156>/Limiting_Acceleration'
                                        *   '<S156>/Limiting_Rate'
                                        *   '<S156>/Integrator1'
                                        *   '<S156>/Saturation'
                                        *   '<S156>/Saturation1'
                                        */
  real_T DelayedStep1_stepTime;        /* Mask Parameter: DelayedStep1_stepTime
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T DelayedStep2_stepTime;        /* Mask Parameter: DelayedStep2_stepTime
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T DelayedStep1_u0;              /* Mask Parameter: DelayedStep1_u0
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T DelayedStep2_u0;              /* Mask Parameter: DelayedStep2_u0
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T DelayedStep1_u1;              /* Mask Parameter: DelayedStep1_u1
                                        * Referenced by: '<S29>/Constant3'
                                        */
  real_T DelayedStep2_u1;              /* Mask Parameter: DelayedStep2_u1
                                        * Referenced by: '<S30>/Constant3'
                                        */
  real_T Rudder_unc_bl;                /* Mask Parameter: Rudder_unc_bl
                                        * Referenced by: '<S153>/Gain3'
                                        */
  real_T Rudder1_unc_bl;               /* Mask Parameter: Rudder1_unc_bl
                                        * Referenced by: '<S154>/Gain3'
                                        */
  real_T Rudder2_unc_bl;               /* Mask Parameter: Rudder2_unc_bl
                                        * Referenced by: '<S155>/Gain3'
                                        */
  real_T Rudder3_unc_bl;               /* Mask Parameter: Rudder3_unc_bl
                                        * Referenced by: '<S156>/Gain3'
                                        */
  real_T Rudder_unc_off;               /* Mask Parameter: Rudder_unc_off
                                        * Referenced by: '<S153>/Constant'
                                        */
  real_T Rudder1_unc_off;              /* Mask Parameter: Rudder1_unc_off
                                        * Referenced by: '<S154>/Constant'
                                        */
  real_T Rudder2_unc_off;              /* Mask Parameter: Rudder2_unc_off
                                        * Referenced by: '<S155>/Constant'
                                        */
  real_T Rudder3_unc_off;              /* Mask Parameter: Rudder3_unc_off
                                        * Referenced by: '<S156>/Constant'
                                        */
  real_T Rudder_unc_scale;             /* Mask Parameter: Rudder_unc_scale
                                        * Referenced by: '<S153>/Gain1'
                                        */
  real_T Rudder1_unc_scale;            /* Mask Parameter: Rudder1_unc_scale
                                        * Referenced by: '<S154>/Gain1'
                                        */
  real_T Rudder2_unc_scale;            /* Mask Parameter: Rudder2_unc_scale
                                        * Referenced by: '<S155>/Gain1'
                                        */
  real_T Rudder3_unc_scale;            /* Mask Parameter: Rudder3_unc_scale
                                        * Referenced by: '<S156>/Gain1'
                                        */
  real_T IntervalTest_uplimit;         /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S141>/Upper Limit'
                                        */
  real_T IntervalTest1_uplimit;        /* Mask Parameter: IntervalTest1_uplimit
                                        * Referenced by: '<S142>/Upper Limit'
                                        */
  real_T ThreeaxisInertialMeasurementUnit_w_a;
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_w_a
                          * Referenced by:
                          *   '<S90>/2*zeta * wn'
                          *   '<S90>/wn^2'
                          */
  real_T ThreeaxisInertialMeasurementUnit_w_a_m;
                       /* Mask Parameter: ThreeaxisInertialMeasurementUnit_w_a_m
                        * Referenced by:
                        *   '<S43>/2*zeta * wn'
                        *   '<S43>/wn^2'
                        */
  real_T ThreeaxisInertialMeasurementUnit_w_g;
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_w_g
                          * Referenced by:
                          *   '<S102>/2*zeta * wn'
                          *   '<S102>/wn^2'
                          */
  real_T ThreeaxisInertialMeasurementUnit_w_g_n;
                       /* Mask Parameter: ThreeaxisInertialMeasurementUnit_w_g_n
                        * Referenced by:
                        *   '<S55>/2*zeta * wn'
                        *   '<S55>/wn^2'
                        */
  real_T ThreeaxisInertialMeasurementUnit_z_a;
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_z_a
                          * Referenced by: '<S90>/2*zeta * wn'
                          */
  real_T ThreeaxisInertialMeasurementUnit_z_a_m;
                       /* Mask Parameter: ThreeaxisInertialMeasurementUnit_z_a_m
                        * Referenced by: '<S43>/2*zeta * wn'
                        */
  real_T ThreeaxisInertialMeasurementUnit_z_g;
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_z_g
                          * Referenced by: '<S102>/2*zeta * wn'
                          */
  real_T ThreeaxisInertialMeasurementUnit_z_g_h;
                       /* Mask Parameter: ThreeaxisInertialMeasurementUnit_z_g_h
                        * Referenced by: '<S55>/2*zeta * wn'
                        */
  int32_T PacketInput_PacketID;        /* Mask Parameter: PacketInput_PacketID
                                        * Referenced by: '<S60>/Packet Input'
                                        */
  int32_T PacketOutput_PacketID;       /* Mask Parameter: PacketOutput_PacketID
                                        * Referenced by: '<S60>/Packet Output'
                                        */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S66>/FixPt Switch'
                                        */
  struct_iLoOqqsxNZRVPJUkO5oSDB States_Y0;/* Computed Parameter: States_Y0
                                           * Referenced by: '<S70>/States'
                                           */
  real_T CalibrationTime_Y0;           /* Expression: 0
                                        * Referenced by: '<S3>/CalibrationTime'
                                        */
  real_T c_flat_Value;                 /* Expression: c_flat
                                        * Referenced by: '<S129>/c_flat'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S130>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S131>/Constant'
                                        */
  real_T c_rsma_Value;                 /* Expression: c_rsma
                                        * Referenced by: '<S129>/c_rsma'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 2
                                        * Referenced by: '<S131>/Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S130>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S128>/Gain'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S253>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 100*eps
                                        * Referenced by: '<S253>/Saturation1'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 2
                                        * Referenced by: '<S253>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: Aerodynamics.CLN_r
                                        * Referenced by: '<S120>/Gain2'
                                        */
  real_T Gain_Gain_p;                  /* Expression: Aerodynamics.CLN_delr
                                        * Referenced by: '<S120>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: Aerodynamics.CLN_beta
                                        * Referenced by: '<S120>/Gain1'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: Aerodynamics.CLM_q
                                        * Referenced by: '<S119>/Gain2'
                                        */
  real_T Gain_Gain_i;                  /* Expression: Aerodynamics.CLM_dele
                                        * Referenced by: '<S119>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: Aerodynamics.CLM_alpha
                                        * Referenced by: '<S119>/Gain1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: Aerodynamics.CLL_p
                                        * Referenced by: '<S118>/Gain2'
                                        */
  real_T Gain_Gain_g;                  /* Expression: Aerodynamics.CLL_dela
                                        * Referenced by: '<S118>/Gain'
                                        */
  real_T c_flat_Value_k;               /* Expression: c_flat
                                        * Referenced by: '<S133>/c_flat'
                                        */
  real_T Gain_Gain_nm;                 /* Expression: 2
                                        * Referenced by: '<S134>/Gain'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S135>/Constant'
                                        */
  real_T c_rsma_Value_j;               /* Expression: c_rsma
                                        * Referenced by: '<S133>/c_rsma'
                                        */
  real_T Gain_Gain_ig;                 /* Expression: 2
                                        * Referenced by: '<S135>/Gain'
                                        */
  real_T Constant_Value_lg;            /* Expression: 1
                                        * Referenced by: '<S134>/Constant'
                                        */
  real_T Gain_Gain_bf;                 /* Expression: -1
                                        * Referenced by: '<S132>/Gain'
                                        */
  real_T WGS84_Gravity_Implementation_c_b_WGS;/* Expression: c_b_WGS
                                               * Referenced by: '<S137>/WGS84_Gravity_Implementation'
                                               */
  real_T WGS84_Gravity_Implementation_c_grav;/* Expression: c_grav
                                              * Referenced by: '<S137>/WGS84_Gravity_Implementation'
                                              */
  real_T WGS84_Gravity_Implementation_c_rot;/* Expression: c_rot
                                             * Referenced by: '<S137>/WGS84_Gravity_Implementation'
                                             */
  real_T WGS84_Gravity_Implementation_c_rsma;/* Expression: c_rsma
                                              * Referenced by: '<S137>/WGS84_Gravity_Implementation'
                                              */
  real_T c_flat_Value_h;               /* Expression: c_flat
                                        * Referenced by: '<S168>/c_flat'
                                        */
  real_T Gain_Gain_ab;                 /* Expression: 2
                                        * Referenced by: '<S169>/Gain'
                                        */
  real_T Constant_Value_lt;            /* Expression: 1
                                        * Referenced by: '<S170>/Constant'
                                        */
  real_T c_rsma_Value_a;               /* Expression: c_rsma
                                        * Referenced by: '<S168>/c_rsma'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 2
                                        * Referenced by: '<S170>/Gain'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S169>/Constant'
                                        */
  real_T Gain_Gain_bh;                 /* Expression: -1
                                        * Referenced by: '<S167>/Gain'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S184>/Constant8'
                                        */
  real_T Constant7_Value;              /* Expression: c_rot
                                        * Referenced by: '<S184>/Constant7'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S184>/Constant6'
                                        */
  real_T Gain2_Gain_f;                 /* Expression: -1
                                        * Referenced by: '<S187>/Gain2'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: -1
                                        * Referenced by: '<S187>/Gain1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: prp_T(end)
                                        * Referenced by: '<S196>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S196>/Saturation'
                                        */
  real_T thrust_lookup_tableData[333]; /* Expression: prp_FBPB
                                        * Referenced by: '<S196>/thrust_lookup'
                                        */
  real_T thrust_lookup_bp01Data[333];  /* Expression: prp_T
                                        * Referenced by: '<S196>/thrust_lookup'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<S208>/Constant11'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S208>/Constant10'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S208>/Constant4'
                                        */
  real_T Constant7_Value_f;            /* Expression: 0
                                        * Referenced by: '<S208>/Constant7'
                                        */
  real_T Constant8_Value_a;            /* Expression: 0
                                        * Referenced by: '<S208>/Constant8'
                                        */
  real_T Gain_Gain_k;                  /* Expression: -1
                                        * Referenced by: '<S208>/Gain'
                                        */
  real_T Constant7_Value_d;            /* Expression: 0
                                        * Referenced by: '<S207>/Constant7'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: -1
                                        * Referenced by: '<S207>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S207>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S207>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S207>/Constant'
                                        */
  real_T Constant8_Value_k;            /* Expression: 0
                                        * Referenced by: '<S207>/Constant8'
                                        */
  real_T Constant7_Value_a;            /* Expression: 0
                                        * Referenced by: '<S206>/Constant7'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S206>/Gain'
                                        */
  real_T Constant8_Value_g;            /* Expression: 0
                                        * Referenced by: '<S206>/Constant8'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S206>/Constant2'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S206>/Constant1'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S206>/Constant'
                                        */
  real_T Constant11_Value_p;           /* Expression: 1
                                        * Referenced by: '<S205>/Constant11'
                                        */
  real_T Constant10_Value_f;           /* Expression: 0
                                        * Referenced by: '<S205>/Constant10'
                                        */
  real_T Constant4_Value_a;            /* Expression: 0
                                        * Referenced by: '<S205>/Constant4'
                                        */
  real_T Constant7_Value_j;            /* Expression: 0
                                        * Referenced by: '<S205>/Constant7'
                                        */
  real_T Constant8_Value_j;            /* Expression: 0
                                        * Referenced by: '<S205>/Constant8'
                                        */
  real_T Gain_Gain_ii;                 /* Expression: -1
                                        * Referenced by: '<S205>/Gain'
                                        */
  real_T Constant7_Value_c;            /* Expression: 0
                                        * Referenced by: '<S204>/Constant7'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1
                                        * Referenced by: '<S204>/Gain1'
                                        */
  real_T Constant2_Value_p;            /* Expression: 0
                                        * Referenced by: '<S204>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: 1
                                        * Referenced by: '<S204>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S204>/Constant'
                                        */
  real_T Constant8_Value_j5;           /* Expression: 0
                                        * Referenced by: '<S204>/Constant8'
                                        */
  real_T Constant7_Value_o;            /* Expression: 0
                                        * Referenced by: '<S203>/Constant7'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S203>/Gain'
                                        */
  real_T Constant8_Value_g5;           /* Expression: 0
                                        * Referenced by: '<S203>/Constant8'
                                        */
  real_T Constant2_Value_io;           /* Expression: 0
                                        * Referenced by: '<S203>/Constant2'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S203>/Constant1'
                                        */
  real_T Constant_Value_hm;            /* Expression: 1
                                        * Referenced by: '<S203>/Constant'
                                        */
  real_T Constant11_Value_o;           /* Expression: 1
                                        * Referenced by: '<S202>/Constant11'
                                        */
  real_T Constant10_Value_g;           /* Expression: 0
                                        * Referenced by: '<S202>/Constant10'
                                        */
  real_T Constant4_Value_o;            /* Expression: 0
                                        * Referenced by: '<S202>/Constant4'
                                        */
  real_T Constant7_Value_ct;           /* Expression: 0
                                        * Referenced by: '<S202>/Constant7'
                                        */
  real_T Constant8_Value_c;            /* Expression: 0
                                        * Referenced by: '<S202>/Constant8'
                                        */
  real_T Gain_Gain_pz;                 /* Expression: -1
                                        * Referenced by: '<S202>/Gain'
                                        */
  real_T Constant7_Value_i;            /* Expression: 0
                                        * Referenced by: '<S201>/Constant7'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: -1
                                        * Referenced by: '<S201>/Gain1'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S201>/Constant2'
                                        */
  real_T Constant1_Value_h;            /* Expression: 1
                                        * Referenced by: '<S201>/Constant1'
                                        */
  real_T Constant_Value_lv;            /* Expression: 0
                                        * Referenced by: '<S201>/Constant'
                                        */
  real_T Constant8_Value_cm;           /* Expression: 0
                                        * Referenced by: '<S201>/Constant8'
                                        */
  real_T Constant7_Value_ih;           /* Expression: 0
                                        * Referenced by: '<S200>/Constant7'
                                        */
  real_T Gain_Gain_dp;                 /* Expression: -1
                                        * Referenced by: '<S200>/Gain'
                                        */
  real_T Constant8_Value_m;            /* Expression: 0
                                        * Referenced by: '<S200>/Constant8'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S200>/Constant2'
                                        */
  real_T Constant1_Value_l;            /* Expression: 0
                                        * Referenced by: '<S200>/Constant1'
                                        */
  real_T Constant_Value_h1;            /* Expression: 1
                                        * Referenced by: '<S200>/Constant'
                                        */
  real_T Gain_Gain_im;                 /* Expression: -1
                                        * Referenced by: '<S211>/Gain'
                                        */
  real_T Constant_Value_c5;            /* Expression: 1
                                        * Referenced by: '<S223>/Constant'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: inf
                                        * Referenced by: '<S223>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: eps
                                        * Referenced by: '<S223>/Saturation'
                                        */
  real_T Gain_Gain_kz;                 /* Expression: 0.5
                                        * Referenced by: '<S223>/Gain'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S224>/Constant'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: inf
                                        * Referenced by: '<S224>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: eps
                                        * Referenced by: '<S224>/Saturation'
                                        */
  real_T Gain_Gain_lq;                 /* Expression: 0.5
                                        * Referenced by: '<S224>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S225>/Constant'
                                        */
  real_T Saturation_UpperSat_pr;       /* Expression: inf
                                        * Referenced by: '<S225>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: eps
                                        * Referenced by: '<S225>/Saturation'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 0.5
                                        * Referenced by: '<S225>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S226>/Constant'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: inf
                                        * Referenced by: '<S226>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: eps
                                        * Referenced by: '<S226>/Saturation'
                                        */
  real_T Gain_Gain_ih;                 /* Expression: 0.5
                                        * Referenced by: '<S226>/Gain'
                                        */
  real_T Gain12_Gain;                  /* Expression: 2
                                        * Referenced by: '<S241>/Gain12'
                                        */
  real_T Gain11_Gain;                  /* Expression: 2
                                        * Referenced by: '<S241>/Gain11'
                                        */
  real_T Gain6_Gain;                   /* Expression: 2
                                        * Referenced by: '<S241>/Gain6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2
                                        * Referenced by: '<S241>/Gain5'
                                        */
  real_T Gain4_Gain;                   /* Expression: 2
                                        * Referenced by: '<S241>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2
                                        * Referenced by: '<S241>/Gain3'
                                        */
  real_T Gain8_Gain;                   /* Expression: 2
                                        * Referenced by: '<S241>/Gain8'
                                        */
  real_T Gain7_Gain;                   /* Expression: 2
                                        * Referenced by: '<S241>/Gain7'
                                        */
  real_T Gain10_Gain;                  /* Expression: 2
                                        * Referenced by: '<S241>/Gain10'
                                        */
  real_T Gain9_Gain;                   /* Expression: 2
                                        * Referenced by: '<S241>/Gain9'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S241>/Gain2'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S241>/Gain1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: prp_T(end)
                                        * Referenced by: '<S258>/Saturation'
                                        */
  real_T Saturation_LowerSat_ee;       /* Expression: 0
                                        * Referenced by: '<S258>/Saturation'
                                        */
  real_T uDLookupTable_tableData[333]; /* Expression: prp_m
                                        * Referenced by: '<S258>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[333];  /* Expression: prp_T
                                        * Referenced by: '<S258>/1-D Lookup Table'
                                        */
  real_T Constant11_Value_l;           /* Expression: 1
                                        * Referenced by: '<S275>/Constant11'
                                        */
  real_T Constant10_Value_k;           /* Expression: 0
                                        * Referenced by: '<S275>/Constant10'
                                        */
  real_T Constant4_Value_i;            /* Expression: 0
                                        * Referenced by: '<S275>/Constant4'
                                        */
  real_T Constant7_Value_a5;           /* Expression: 0
                                        * Referenced by: '<S275>/Constant7'
                                        */
  real_T Constant8_Value_j1;           /* Expression: 0
                                        * Referenced by: '<S275>/Constant8'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S275>/Gain'
                                        */
  real_T Constant7_Value_op;           /* Expression: 0
                                        * Referenced by: '<S274>/Constant7'
                                        */
  real_T Gain1_Gain_g4;                /* Expression: -1
                                        * Referenced by: '<S274>/Gain1'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S274>/Constant2'
                                        */
  real_T Constant1_Value_jv;           /* Expression: 1
                                        * Referenced by: '<S274>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S274>/Constant'
                                        */
  real_T Constant8_Value_gc;           /* Expression: 0
                                        * Referenced by: '<S274>/Constant8'
                                        */
  real_T Constant7_Value_g;            /* Expression: 0
                                        * Referenced by: '<S273>/Constant7'
                                        */
  real_T Gain_Gain_gk;                 /* Expression: -1
                                        * Referenced by: '<S273>/Gain'
                                        */
  real_T Constant8_Value_l;            /* Expression: 0
                                        * Referenced by: '<S273>/Constant8'
                                        */
  real_T Constant2_Value_m;            /* Expression: 0
                                        * Referenced by: '<S273>/Constant2'
                                        */
  real_T Constant1_Value_i;            /* Expression: 0
                                        * Referenced by: '<S273>/Constant1'
                                        */
  real_T Constant_Value_pf;            /* Expression: 1
                                        * Referenced by: '<S273>/Constant'
                                        */
  real_T Constant11_Value_lg;          /* Expression: 1
                                        * Referenced by: '<S272>/Constant11'
                                        */
  real_T Constant10_Value_i;           /* Expression: 0
                                        * Referenced by: '<S272>/Constant10'
                                        */
  real_T Constant4_Value_j;            /* Expression: 0
                                        * Referenced by: '<S272>/Constant4'
                                        */
  real_T Constant7_Value_n;            /* Expression: 0
                                        * Referenced by: '<S272>/Constant7'
                                        */
  real_T Constant8_Value_mn;           /* Expression: 0
                                        * Referenced by: '<S272>/Constant8'
                                        */
  real_T Gain_Gain_c4;                 /* Expression: -1
                                        * Referenced by: '<S272>/Gain'
                                        */
  real_T Constant7_Value_l;            /* Expression: 0
                                        * Referenced by: '<S271>/Constant7'
                                        */
  real_T Gain1_Gain_cw;                /* Expression: -1
                                        * Referenced by: '<S271>/Gain1'
                                        */
  real_T Constant2_Value_ia;           /* Expression: 0
                                        * Referenced by: '<S271>/Constant2'
                                        */
  real_T Constant1_Value_jy;           /* Expression: 1
                                        * Referenced by: '<S271>/Constant1'
                                        */
  real_T Constant_Value_b4;            /* Expression: 0
                                        * Referenced by: '<S271>/Constant'
                                        */
  real_T Constant8_Value_cx;           /* Expression: 0
                                        * Referenced by: '<S271>/Constant8'
                                        */
  real_T Constant7_Value_e;            /* Expression: 0
                                        * Referenced by: '<S270>/Constant7'
                                        */
  real_T Gain_Gain_o;                  /* Expression: -1
                                        * Referenced by: '<S270>/Gain'
                                        */
  real_T Constant8_Value_e;            /* Expression: 0
                                        * Referenced by: '<S270>/Constant8'
                                        */
  real_T Constant2_Value_i3;           /* Expression: 0
                                        * Referenced by: '<S270>/Constant2'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S270>/Constant1'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S270>/Constant'
                                        */
  real_T Constant11_Value_lo;          /* Expression: 1
                                        * Referenced by: '<S269>/Constant11'
                                        */
  real_T Constant10_Value_a;           /* Expression: 0
                                        * Referenced by: '<S269>/Constant10'
                                        */
  real_T Constant4_Value_h;            /* Expression: 0
                                        * Referenced by: '<S269>/Constant4'
                                        */
  real_T Constant7_Value_ah;           /* Expression: 0
                                        * Referenced by: '<S269>/Constant7'
                                        */
  real_T Constant8_Value_my;           /* Expression: 0
                                        * Referenced by: '<S269>/Constant8'
                                        */
  real_T Gain_Gain_ib;                 /* Expression: -1
                                        * Referenced by: '<S269>/Gain'
                                        */
  real_T Constant7_Value_ow;           /* Expression: 0
                                        * Referenced by: '<S268>/Constant7'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: -1
                                        * Referenced by: '<S268>/Gain1'
                                        */
  real_T Constant2_Value_b;            /* Expression: 0
                                        * Referenced by: '<S268>/Constant2'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S268>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S268>/Constant'
                                        */
  real_T Constant8_Value_c0;           /* Expression: 0
                                        * Referenced by: '<S268>/Constant8'
                                        */
  real_T Constant7_Value_b;            /* Expression: 0
                                        * Referenced by: '<S267>/Constant7'
                                        */
  real_T Gain_Gain_kc;                 /* Expression: -1
                                        * Referenced by: '<S267>/Gain'
                                        */
  real_T Constant8_Value_o;            /* Expression: 0
                                        * Referenced by: '<S267>/Constant8'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S267>/Constant2'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S267>/Constant1'
                                        */
  real_T Constant_Value_dt;            /* Expression: 1
                                        * Referenced by: '<S267>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S227>/Constant'
                                        */
  real_T Constant_Value_ck;            /* Expression: 0
                                        * Referenced by: '<S228>/Constant'
                                        */
  real_T Constant_Value_o0;            /* Expression: 0
                                        * Referenced by: '<S229>/Constant'
                                        */
  real_T Constant_Value_pq;            /* Expression: 0
                                        * Referenced by: '<S230>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S231>/Constant'
                                        */
  real_T Constant_Value_kz;            /* Expression: 0
                                        * Referenced by: '<S232>/Constant'
                                        */
  real_T Constant_Value_g4;            /* Expression: 0
                                        * Referenced by: '<S233>/Constant'
                                        */
  real_T Constant_Value_do;            /* Expression: 0
                                        * Referenced by: '<S234>/Constant'
                                        */
  real_T Constant_Value_g1;            /* Expression: 0
                                        * Referenced by: '<S235>/Constant'
                                        */
  real_T Constant_Value_gb;            /* Expression: 0
                                        * Referenced by: '<S236>/Constant'
                                        */
  real_T Constant_Value_gf;            /* Expression: 0
                                        * Referenced by: '<S237>/Constant'
                                        */
  real_T Constant_Value_ok;            /* Expression: 0
                                        * Referenced by: '<S238>/Constant'
                                        */
  real_T Constant1_Value_c[3];         /* Expression: [0,0,0]
                                        * Referenced by: '<S76>/Constant1'
                                        */
  real_T Constant_Value_cg[13];   /* Expression: [pBII_0; vBII_0; qIB_0; wBIB_0]
                                   * Referenced by: '<S210>/Constant'
                                   */
  real_T Constant_Value_ix;            /* Expression: 0.5
                                        * Referenced by: '<S78>/Constant'
                                        */
  real_T Gain_Gain_iz;                 /* Expression: 2
                                        * Referenced by: '<S78>/Gain'
                                        */
  real_T Saturation_UpperSat_ph;       /* Expression: 1
                                        * Referenced by: '<S78>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -1
                                        * Referenced by: '<S78>/Saturation'
                                        */
  real_T Constant1_Value_la;           /* Expression: 0.5
                                        * Referenced by: '<S78>/Constant1'
                                        */
  real_T Multiply_Gain;                /* Expression: 9.81
                                        * Referenced by: '<S79>/Multiply'
                                        */
  real_T Multiply1_Gain;               /* Expression: 9.81
                                        * Referenced by: '<S79>/Multiply1'
                                        */
  real_T Multiply2_Gain;               /* Expression: -9.81
                                        * Referenced by: '<S79>/Multiply2'
                                        */
  real_T u2_Gain;                      /* Expression: 0.5
                                        * Referenced by: '<S80>/1//2'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain1'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain2'
                                        */
  real_T Gain9_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain9'
                                        */
  real_T Gain10_Gain_o;                /* Expression: 2
                                        * Referenced by: '<S175>/Gain10'
                                        */
  real_T Gain7_Gain_h;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain7'
                                        */
  real_T Gain8_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain8'
                                        */
  real_T Gain3_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain3'
                                        */
  real_T Gain4_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain4'
                                        */
  real_T Gain5_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain5'
                                        */
  real_T Gain6_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S175>/Gain6'
                                        */
  real_T Gain11_Gain_k;                /* Expression: 2
                                        * Referenced by: '<S175>/Gain11'
                                        */
  real_T Gain12_Gain_j;                /* Expression: 2
                                        * Referenced by: '<S175>/Gain12'
                                        */
  real_T Q_1_Value[16];    /* Expression: [0 0 0 1; 0 0 -1 0; 0 1 0 0; -1 0 0 0]
                            * Referenced by: '<S246>/Q~_1'
                            */
  real_T Q_2_Value[16];    /* Expression: [0 0 1 0; 0 0 0 1; -1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S246>/Q~_2'
                            */
  real_T Q_3_Value[16];    /* Expression: [0 -1 0 0; 1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S246>/Q~_3'
                            */
  real_T Q_4_Value[16];      /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S246>/Q~_4'
                              */
  real_T Q_1_Value_d[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S246>/Q_1'
                            */
  real_T Q_2_Value_f[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S246>/Q_2'
                            */
  real_T Q_3_Value_c[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S246>/Q_3'
                            */
  real_T Q_4_Value_n[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S246>/Q_4'
                              */
  real_T Constant_Value_od;            /* Expression: Aerodynamics.CX0
                                        * Referenced by: '<S121>/Constant'
                                        */
  real_T Constant8_Value_mc[4];        /* Expression: qIE_0
                                        * Referenced by: '<S185>/Constant8'
                                        */
  real_T Gain1_Gain_mx;                /* Expression: 2
                                        * Referenced by: '<S189>/Gain1'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S189>/Gain2'
                                        */
  real_T Gain9_Gain_fk;                /* Expression: 2
                                        * Referenced by: '<S189>/Gain9'
                                        */
  real_T Gain10_Gain_f;                /* Expression: 2
                                        * Referenced by: '<S189>/Gain10'
                                        */
  real_T Gain7_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S189>/Gain7'
                                        */
  real_T Gain8_Gain_a;                 /* Expression: 2
                                        * Referenced by: '<S189>/Gain8'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: 2
                                        * Referenced by: '<S189>/Gain3'
                                        */
  real_T Gain4_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S189>/Gain4'
                                        */
  real_T Gain5_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S189>/Gain5'
                                        */
  real_T Gain6_Gain_d;                 /* Expression: 2
                                        * Referenced by: '<S189>/Gain6'
                                        */
  real_T Gain11_Gain_m;                /* Expression: 2
                                        * Referenced by: '<S189>/Gain11'
                                        */
  real_T Gain12_Gain_o;                /* Expression: 2
                                        * Referenced by: '<S189>/Gain12'
                                        */
  real_T Constant9_Value;              /* Expression: flag_I_rot
                                        * Referenced by: '<S184>/Constant9'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S184>/Switch'
                                        */
  real_T Constant_Value_fh[4];         /* Expression: [1; 0; 0; 1]
                                        * Referenced by: '<S252>/Constant'
                                        */
  real_T Saturation2_UpperSat;        /* Expression: Aerodynamics.ulim_alpha_rad
                                       * Referenced by: '<S114>/Saturation2'
                                       */
  real_T Saturation2_LowerSat;        /* Expression: Aerodynamics.llim_alpha_rad
                                       * Referenced by: '<S114>/Saturation2'
                                       */
  real_T Gain2_Gain_h;                 /* Expression: Aerodynamics.CX_alpha2
                                        * Referenced by: '<S121>/Gain2'
                                        */
  real_T Gain3_Gain_l;                 /* Expression: Aerodynamics.CX_alpha
                                        * Referenced by: '<S121>/Gain3'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: Aerodynamics.ulim_beta_rad
                                        * Referenced by: '<S114>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: Aerodynamics.llim_beta_rad
                                        * Referenced by: '<S114>/Saturation3'
                                        */
  real_T Gain4_Gain_j;                 /* Expression: Aerodynamics.CX_beta2
                                        * Referenced by: '<S121>/Gain4'
                                        */
  real_T Gain5_Gain_a;                 /* Expression: Aerodynamics.CX_beta
                                        * Referenced by: '<S121>/Gain5'
                                        */
  real_T Constant8_Value_d[12];        /* Expression: Tr3r4
                                        * Referenced by: '<S157>/Constant8'
                                        */
  real_T Constant7_Value_k;            /* Expression: tRRR
                                        * Referenced by: '<S105>/Constant7'
                                        */
  real_T Gain6_Gain_a;                 /* Expression: Aerodynamics.CX_dele2
                                        * Referenced by: '<S121>/Gain6'
                                        */
  real_T Gain7_Gain_b;                 /* Expression: Aerodynamics.CX_dela2
                                        * Referenced by: '<S121>/Gain7'
                                        */
  real_T Constant_Value_mq;            /* Expression: Aerodynamics.CY0
                                        * Referenced by: '<S122>/Constant'
                                        */
  real_T Gain_Gain_mn;                 /* Expression: Aerodynamics.CY_beta
                                        * Referenced by: '<S122>/Gain'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: Aerodynamics.CY_delr
                                        * Referenced by: '<S122>/Gain1'
                                        */
  real_T Constant_Value_kb;            /* Expression: Aerodynamics.CZ0
                                        * Referenced by: '<S123>/Constant'
                                        */
  real_T Gain_Gain_px;                 /* Expression: Aerodynamics.CZ_alpha
                                        * Referenced by: '<S123>/Gain'
                                        */
  real_T Gain1_Gain_ov;                /* Expression: Aerodynamics.CZ_dele
                                        * Referenced by: '<S123>/Gain1'
                                        */
  real_T Constant2_Value_jd;           /* Expression: aero.sref
                                        * Referenced by: '<S117>/Constant2'
                                        */
  real_T Constant_Value_e;             /* Expression: 0.5
                                        * Referenced by: '<S250>/Constant'
                                        */
  real_T Tmp_norm_msl_Value;           /* Expression: c_Tmp0
                                        * Referenced by: '<S150>/Tmp_norm_msl'
                                        */
  real_T Tmp_gradient_tropo_Value;     /* Expression: c_be
                                        * Referenced by: '<S151>/Tmp_gradient_tropo'
                                        */
  real_T Constant_Value_ja;            /* Expression: lon_0
                                        * Referenced by: '<S211>/Constant'
                                        */
  real_T Constant2_Value_px;           /* Expression: lat_0
                                        * Referenced by: '<S211>/Constant2'
                                        */
  real_T Constant1_Value_hf;           /* Expression: flag_I_flat
                                        * Referenced by: '<S211>/Constant1'
                                        */
  real_T c_rsma_Value_n;               /* Expression: c_rsma
                                        * Referenced by: '<S215>/c_rsma'
                                        */
  real_T Constant_Value_ae;            /* Expression: 1
                                        * Referenced by: '<S217>/Constant'
                                        */
  real_T c_flat_Value_j;               /* Expression: c_flat
                                        * Referenced by: '<S215>/c_flat'
                                        */
  real_T Gain_Gain_he;                 /* Expression: 2
                                        * Referenced by: '<S217>/Gain'
                                        */
  real_T Constant_Value_cc;            /* Expression: 1
                                        * Referenced by: '<S216>/Constant'
                                        */
  real_T Gain_Gain_pd;                 /* Expression: 2
                                        * Referenced by: '<S216>/Gain'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S211>/Switch'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: c_h_geope
                                        * Referenced by: '<S138>/Saturation'
                                        */
  real_T Saturation_LowerSat_oe;       /* Expression: c_h_geop0
                                        * Referenced by: '<S138>/Saturation'
                                        */
  real_T geopotential_height_ref_Value;/* Expression: c_h_geop0
                                        * Referenced by: '<S150>/geopotential_height_ref'
                                        */
  real_T Constant1_Value_pz;           /* Expression: 1
                                        * Referenced by: '<S152>/Constant1'
                                        */
  real_T Tmp_gradient_tropo_Value_p;   /* Expression: c_be
                                        * Referenced by: '<S152>/Tmp_gradient_tropo'
                                        */
  real_T pressure_exponent_Value;      /* Expression: c_pe
                                        * Referenced by: '<S152>/pressure_exponent'
                                        */
  real_T pa_norm_msl_Value;            /* Expression: c_pa0
                                        * Referenced by: '<S150>/pa_norm_msl'
                                        */
  real_T specific_gas_constant_Value;  /* Expression: sgc
                                        * Referenced by: '<S147>/specific_gas_constant'
                                        */
  real_T Constant1_Value_hj;           /* Expression: flag_I_aero_switch
                                        * Referenced by: '<S126>/Constant1'
                                        */
  real_T Constant_Value_es[3];         /* Expression: pBII_0
                                        * Referenced by: '<S128>/Constant'
                                        */
  real_T Constant2_Value_jj;           /* Expression: flag_I_flat
                                        * Referenced by: '<S128>/Constant2'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S128>/Switch1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S126>/Constant3'
                                        */
  real_T Switch_Threshold_a;           /* Expression: 0.05
                                        * Referenced by: '<S126>/Switch'
                                        */
  real_T Q_1_Value_g[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S178>/Q_1'
                            */
  real_T Q_1_Value_p[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S180>/Q_1'
                            */
  real_T Q_2_Value_c[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S180>/Q_2'
                            */
  real_T Q_3_Value_h[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S180>/Q_3'
                            */
  real_T Q_4_Value_g[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S180>/Q_4'
                              */
  real_T Constant8_Value_el[4];        /* Expression: qEG_0
                                        * Referenced by: '<S186>/Constant8'
                                        */
  real_T Constant_Value_p0;            /* Expression: 1
                                        * Referenced by: '<S180>/Constant'
                                        */
  real_T Constant1_Value_jf;           /* Expression: -1
                                        * Referenced by: '<S180>/Constant1'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0
                                        * Referenced by: '<S180>/Switch'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: -1
                                        * Referenced by: '<S177>/Gain1'
                                        */
  real_T Q_2_Value_h[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S178>/Q_2'
                            */
  real_T Q_3_Value_h3[16]; /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S178>/Q_3'
                            */
  real_T Q_4_Value_e[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S178>/Q_4'
                              */
  real_T Constant_Value_az;            /* Expression: 1
                                        * Referenced by: '<S178>/Constant'
                                        */
  real_T Constant1_Value_hk;           /* Expression: -1
                                        * Referenced by: '<S178>/Constant1'
                                        */
  real_T Switch_Threshold_a2;          /* Expression: 0
                                        * Referenced by: '<S178>/Switch'
                                        */
  real_T Gain1_Gain_b3;                /* Expression: 2
                                        * Referenced by: '<S176>/Gain1'
                                        */
  real_T Gain2_Gain_fo;                /* Expression: 2
                                        * Referenced by: '<S176>/Gain2'
                                        */
  real_T Gain9_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S176>/Gain9'
                                        */
  real_T Gain10_Gain_i;                /* Expression: 2
                                        * Referenced by: '<S176>/Gain10'
                                        */
  real_T Gain7_Gain_n;                 /* Expression: 2
                                        * Referenced by: '<S176>/Gain7'
                                        */
  real_T Gain8_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S176>/Gain8'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S176>/Gain3'
                                        */
  real_T Gain4_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S176>/Gain4'
                                        */
  real_T Gain5_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S176>/Gain5'
                                        */
  real_T Gain6_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S176>/Gain6'
                                        */
  real_T Gain11_Gain_l;                /* Expression: 2
                                        * Referenced by: '<S176>/Gain11'
                                        */
  real_T Gain12_Gain_b;                /* Expression: 2
                                        * Referenced by: '<S176>/Gain12'
                                        */
  real_T Constant1_Value_b4;           /* Expression: 0
                                        * Referenced by: '<S139>/Constant1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: inf
                                        * Referenced by: '<S104>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: eps
                                        * Referenced by: '<S104>/Saturation'
                                        */
  real_T a3_Value;                     /* Expression: 1
                                        * Referenced by: '<S145>/a3'
                                        */
  real_T a2_Value;                     /* Expression: 2
                                        * Referenced by: '<S146>/a2'
                                        */
  real_T WGS84SemiminorAxism_Value;    /* Expression: c_b_WGS
                                        * Referenced by: '<S145>/WGS84 Semi-minor Axis, [m]'
                                        */
  real_T WGS84SemimajorAxism_Value;    /* Expression: c_rsma
                                        * Referenced by: '<S145>/WGS84 Semi-major Axis, [m]'
                                        */
  real_T Constant_Value_kc;            /* Expression: 1
                                        * Referenced by: '<S143>/Constant'
                                        */
  real_T Constant1_Value_o;            /* Expression: flag_I_gravity_switch
                                        * Referenced by: '<S166>/Constant1'
                                        */
  real_T Constant_Value_bh[3];         /* Expression: pBII_0
                                        * Referenced by: '<S167>/Constant'
                                        */
  real_T Constant2_Value_d;            /* Expression: flag_I_flat
                                        * Referenced by: '<S167>/Constant2'
                                        */
  real_T Switch1_Threshold_g;          /* Expression: 0
                                        * Referenced by: '<S167>/Switch1'
                                        */
  real_T Constant3_Value_l;            /* Expression: 0
                                        * Referenced by: '<S166>/Constant3'
                                        */
  real_T Switch_Threshold_o;           /* Expression: 0.05
                                        * Referenced by: '<S166>/Switch'
                                        */
  real_T Constant_Value_aw;            /* Expression: unc_mB_bl
                                        * Referenced by: '<S259>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: mB_0
                                        * Referenced by: '<S258>/Constant1'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S258>/Constant'
                                        */
  real_T Switch_Threshold_op;          /* Expression: 0
                                        * Referenced by: '<S258>/Switch'
                                        */
  real_T Switch1_Threshold_j;          /* Expression: 0
                                        * Referenced by: '<S258>/Switch1'
                                        */
  real_T Constant1_Value_lf;           /* Expression: unc_mB_scale
                                        * Referenced by: '<S259>/Constant1'
                                        */
  real_T thrust_rot_x_Value;           /* Expression: unc_prp_x
                                        * Referenced by: '<S197>/thrust_rot_x'
                                        */
  real_T thrust_rot_y_Value;           /* Expression: unc_prp_y
                                        * Referenced by: '<S197>/thrust_rot_y'
                                        */
  real_T Thrust_rot_z_Value;           /* Expression: unc_prp_z
                                        * Referenced by: '<S197>/Thrust_rot_z'
                                        */
  real_T Constant_Value_ny;            /* Expression: 0
                                        * Referenced by: '<S196>/Constant'
                                        */
  real_T Switch_Threshold_o3;          /* Expression: 0
                                        * Referenced by: '<S196>/Switch'
                                        */
  real_T Switch1_Threshold_f;          /* Expression: 0
                                        * Referenced by: '<S196>/Switch1'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S196>/Constant1'
                                        */
  real_T uncert_thrust_Value;          /* Expression: unc_prp_scale
                                        * Referenced by: '<S197>/uncert_thrust'
                                        */
  real_T Switch_Threshold_om;          /* Expression: 1
                                        * Referenced by: '<S239>/Switch'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: Inf
                                        * Referenced by: '<S242>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: 1e-6
                                        * Referenced by: '<S242>/Saturation'
                                        */
  real_T Constant_Value_bd;            /* Expression: 0
                                        * Referenced by: '<S246>/Constant'
                                        */
  real_T Constant_Value_fd;            /* Expression: dtype_a
                                        * Referenced by: '<S85>/Constant'
                                        */
  real_T IntegratorSecondOrderLimited_ICX;/* Expression: 0
                                           * Referenced by: '<S90>/Integrator, Second-Order Limited'
                                           */
  real_T IntegratorSecondOrderLimited_ICDXDT;/* Expression: 0
                                              * Referenced by: '<S90>/Integrator, Second-Order Limited'
                                              */
  real_T ZeroOrderHold1_Gain;          /* Expression: 1
                                        * Referenced by: '<S83>/Zero-Order Hold1'
                                        */
  real_T ZeroOrderHold2_Gain;          /* Expression: 1
                                        * Referenced by: '<S83>/Zero-Order Hold2'
                                        */
  real_T ZeroOrderHold_Gain;           /* Expression: 1
                                        * Referenced by: '<S83>/Zero-Order Hold'
                                        */
  real_T ZeroOrderHold4_Gain;          /* Expression: 1
                                        * Referenced by: '<S83>/Zero-Order Hold4'
                                        */
  real_T Gain_Gain_aj[3];              /* Expression: [1 -1 1]
                                        * Referenced by: '<S83>/Gain'
                                        */
  real_T Constant15_Value[9];          /* Expression: JSPB_e
                                        * Referenced by: '<S260>/Constant15'
                                        */
  real_T Constant_Value_mt;            /* Expression: mB_0
                                        * Referenced by: '<S264>/Constant'
                                        */
  real_T Constant4_Value_as;           /* Expression: pMPB_x
                                        * Referenced by: '<S257>/Constant4'
                                        */
  real_T Constant_Value_ds;            /* Expression: m0
                                        * Referenced by: '<S257>/Constant'
                                        */
  real_T Constant6_Value_i;            /* Expression: pSPB_x
                                        * Referenced by: '<S257>/Constant6'
                                        */
  real_T Constant3_Value_p;            /* Expression: unc_cg_x
                                        * Referenced by: '<S257>/Constant3'
                                        */
  real_T Constant7_Value_ei;           /* Expression: pMPB_y
                                        * Referenced by: '<S257>/Constant7'
                                        */
  real_T Constant5_Value;              /* Expression: pSPB_y
                                        * Referenced by: '<S257>/Constant5'
                                        */
  real_T Constant1_Value_mh;           /* Expression: unc_cg_y
                                        * Referenced by: '<S257>/Constant1'
                                        */
  real_T Constant9_Value_a;            /* Expression: pMPB_z
                                        * Referenced by: '<S257>/Constant9'
                                        */
  real_T Constant8_Value_n;            /* Expression: pSPB_z
                                        * Referenced by: '<S257>/Constant8'
                                        */
  real_T Constant2_Value_lc;           /* Expression: unc_cg_z
                                        * Referenced by: '<S257>/Constant2'
                                        */
  real_T Constant17_Value[3];          /* Expression: pSPB
                                        * Referenced by: '<S264>/Constant17'
                                        */
  real_T Gain_Gain_mf;                 /* Expression: -1
                                        * Referenced by: '<S276>/Gain'
                                        */
  real_T Gain1_Gain_o1;                /* Expression: -1
                                        * Referenced by: '<S276>/Gain1'
                                        */
  real_T Gain3_Gain_b;                 /* Expression: -1
                                        * Referenced by: '<S276>/Gain3'
                                        */
  real_T Constant16_Value[3];          /* Expression: pMPB
                                        * Referenced by: '<S265>/Constant16'
                                        */
  real_T Gain_Gain_mj;                 /* Expression: -1
                                        * Referenced by: '<S277>/Gain'
                                        */
  real_T Gain1_Gain_fv;                /* Expression: -1
                                        * Referenced by: '<S277>/Gain1'
                                        */
  real_T Gain3_Gain_bz;                /* Expression: -1
                                        * Referenced by: '<S277>/Gain3'
                                        */
  real_T thrust_rot_x_Value_h;         /* Expression: unc_prp_x
                                        * Referenced by: '<S262>/thrust_rot_x'
                                        */
  real_T thrust_rot_y_Value_j;         /* Expression: unc_prp_y
                                        * Referenced by: '<S262>/thrust_rot_y'
                                        */
  real_T Thrust_rot_z_Value_l;         /* Expression: unc_prp_z
                                        * Referenced by: '<S262>/Thrust_rot_z'
                                        */
  real_T Constant21_Value[9];          /* Expression: JMMM_0
                                        * Referenced by: '<S261>/Constant21'
                                        */
  real_T Constant20_Value;             /* Expression: mM_0
                                        * Referenced by: '<S261>/Constant20'
                                        */
  real_T Constant17_Value_c[9];        /* Expression: JMMM_e
                                        * Referenced by: '<S261>/Constant17'
                                        */
  real_T Constant16_Value_g[9];        /* Expression: JMMM_0
                                        * Referenced by: '<S261>/Constant16'
                                        */
  real_T Constant19_Value;             /* Expression: mM_e
                                        * Referenced by: '<S261>/Constant19'
                                        */
  real_T Constant18_Value;             /* Expression: mM_0
                                        * Referenced by: '<S261>/Constant18'
                                        */
  real_T Constant16_Value_gd[9];
                /* Expression: [unc_moi_Jxx,0,0;0,unc_moi_Jyy,0;0,0,unc_moi_Jzz]
                 * Referenced by: '<S263>/Constant16'
                 */
  real_T Constant_Value_mx;            /* Expression: aero.xcg
                                        * Referenced by: '<S124>/Constant'
                                        */
  real_T Gain_Gain_kk;                 /* Expression: -1
                                        * Referenced by: '<S124>/Gain'
                                        */
  real_T Constant3_Value_pw;           /* Expression: 0
                                        * Referenced by: '<S124>/Constant3'
                                        */
  real_T Constant_Value_bp;            /* Expression: Aerodynamics.CLL0
                                        * Referenced by: '<S118>/Constant'
                                        */
  real_T Constant1_Value_cs;           /* Expression: aero.lref
                                        * Referenced by: '<S253>/Constant1'
                                        */
  real_T Constant_Value_ce;            /* Expression: Aerodynamics.CLM0
                                        * Referenced by: '<S119>/Constant'
                                        */
  real_T Constant_Value_f1;            /* Expression: Aerodynamics.CLN0
                                        * Referenced by: '<S120>/Constant'
                                        */
  real_T Constant1_Value_a;            /* Expression: aero.lref
                                        * Referenced by: '<S117>/Constant1'
                                        */
  real_T Constant1_Value_k5;           /* Expression: flag_I_aero_switch
                                        * Referenced by: '<S127>/Constant1'
                                        */
  real_T Constant_Value_ixx[3];        /* Expression: pBII_0
                                        * Referenced by: '<S132>/Constant'
                                        */
  real_T Constant2_Value_je;           /* Expression: flag_I_flat
                                        * Referenced by: '<S132>/Constant2'
                                        */
  real_T Switch1_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S132>/Switch1'
                                        */
  real_T Constant3_Value_b;            /* Expression: 0
                                        * Referenced by: '<S127>/Constant3'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0.05
                                        * Referenced by: '<S127>/Switch'
                                        */
  real_T pNPB_Value[3];                /* Expression: pNPB
                                        * Referenced by: '<S197>/pNPB'
                                        */
  real_T Constant9_Value_l[9];         /* Expression: [0 0 0; 0 0 0; 0 0 0]
                                        * Referenced by: '<S210>/Constant9'
                                        */
  real_T ZeroOrderHold3_Gain;          /* Expression: 1
                                        * Referenced by: '<S83>/Zero-Order Hold3'
                                        */
  real_T Switch_Threshold_p;           /* Expression: 0.5
                                        * Referenced by: '<S85>/Switch'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S86>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S86>/White Noise'
                                        */
  real_T Saturation_UpperSat_j[3];     /* Expression: a_sath
                                        * Referenced by: '<S83>/Saturation'
                                        */
  real_T Saturation_LowerSat_p[3];     /* Expression: a_satl
                                        * Referenced by: '<S83>/Saturation'
                                        */
  real_T Constant_Value_p3;            /* Expression: dtype_g
                                        * Referenced by: '<S99>/Constant'
                                        */
  real_T IntegratorSecondOrderLimited_ICX_a;/* Expression: 0
                                             * Referenced by: '<S102>/Integrator, Second-Order Limited'
                                             */
  real_T IntegratorSecondOrderLimited_ICDXDT_n;/* Expression: 0
                                                * Referenced by: '<S102>/Integrator, Second-Order Limited'
                                                */
  real_T ZeroOrderHold_Gain_k;         /* Expression: 1
                                        * Referenced by: '<S84>/Zero-Order Hold'
                                        */
  real_T ZeroOrderHold1_Gain_k;        /* Expression: 1
                                        * Referenced by: '<S84>/Zero-Order Hold1'
                                        */
  real_T Switch_Threshold_i0;          /* Expression: 0.5
                                        * Referenced by: '<S99>/Switch'
                                        */
  real_T WhiteNoise_Mean_i;            /* Expression: 0
                                        * Referenced by: '<S100>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_f;         /* Computed Parameter: WhiteNoise_StdDev_f
                                       * Referenced by: '<S100>/White Noise'
                                       */
  real_T Saturation_UpperSat_pp[3];    /* Expression: g_sath
                                        * Referenced by: '<S84>/Saturation'
                                        */
  real_T Saturation_LowerSat_ga[3];    /* Expression: g_satl
                                        * Referenced by: '<S84>/Saturation'
                                        */
  real_T Constant_Value_id;            /* Expression: prp_T(end)
                                        * Referenced by: '<S115>/Constant'
                                        */
  real_T Gain_Gain_cv;                 /* Expression: omega^2
                                        * Referenced by: '<S153>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: omega^2
                                        * Referenced by: '<S154>/Gain'
                                        */
  real_T Gain_Gain_ga;                 /* Expression: omega^2
                                        * Referenced by: '<S155>/Gain'
                                        */
  real_T Gain_Gain_gh;                 /* Expression: omega^2
                                        * Referenced by: '<S156>/Gain'
                                        */
  real_T Q_1_Value_k[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S179>/Q_1'
                            */
  real_T Q_2_Value_a[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S179>/Q_2'
                            */
  real_T Q_3_Value_d[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S179>/Q_3'
                            */
  real_T Q_4_Value_l[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S179>/Q_4'
                              */
  real_T Constant_Value_h4;            /* Expression: 1
                                        * Referenced by: '<S179>/Constant'
                                        */
  real_T Constant1_Value_ac;           /* Expression: -1
                                        * Referenced by: '<S179>/Constant1'
                                        */
  real_T Switch_Threshold_pk;          /* Expression: 0
                                        * Referenced by: '<S179>/Switch'
                                        */
  real_T Gain1_Gain_be;                /* Expression: 2
                                        * Referenced by: '<S174>/Gain1'
                                        */
  real_T Gain2_Gain_hx;                /* Expression: 2
                                        * Referenced by: '<S174>/Gain2'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S174>/Gain3'
                                        */
  real_T Gain4_Gain_kv;                /* Expression: 2
                                        * Referenced by: '<S174>/Gain4'
                                        */
  real_T Gain5_Gain_ak;                /* Expression: 2
                                        * Referenced by: '<S174>/Gain5'
                                        */
  real_T Gain6_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S174>/Gain6'
                                        */
  real_T Gain7_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S174>/Gain7'
                                        */
  real_T Gain8_Gain_o2;                /* Expression: 2
                                        * Referenced by: '<S174>/Gain8'
                                        */
  real_T Gain9_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S174>/Gain9'
                                        */
  real_T Gain10_Gain_m;                /* Expression: 2
                                        * Referenced by: '<S174>/Gain10'
                                        */
  real_T Gain11_Gain_b;                /* Expression: 2
                                        * Referenced by: '<S174>/Gain11'
                                        */
  real_T Gain12_Gain_f;                /* Expression: 2
                                        * Referenced by: '<S174>/Gain12'
                                        */
  real_T Gain_Gain_ce;                 /* Expression: 1
                                        * Referenced by: '<S173>/Gain'
                                        */
  real_T Q_1_Value_a[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S188>/Q_1'
                            */
  real_T Constant8_Value_km;           /* Expression: 0
                                        * Referenced by: '<S188>/Constant8'
                                        */
  real_T Q_2_Value_p[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S188>/Q_2'
                            */
  real_T Q_3_Value_f[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S188>/Q_3'
                            */
  real_T Q_4_Value_p[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S188>/Q_4'
                              */
  real_T Gain1_Gain_k1;                /* Expression: -1
                                        * Referenced by: '<S190>/Gain1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.5
                                        * Referenced by: '<S188>/Gain'
                                        */
  real_T Gain1_Gain_nr;                /* Expression: -1
                                        * Referenced by: '<S191>/Gain1'
                                        */
  real_T Constant8_Value_k2;           /* Expression: 0
                                        * Referenced by: '<S187>/Constant8'
                                        */
  real_T Constant9_Value_m;            /* Expression: flag_I_flat
                                        * Referenced by: '<S187>/Constant9'
                                        */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S187>/Switch'
                                        */
  real_T Gain1_Gain_ge;                /* Expression: 1
                                        * Referenced by: '<S173>/Gain1'
                                        */
  real_T Q_1_Value_o[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S192>/Q_1'
                            */
  real_T Constant8_Value_kt;           /* Expression: 0
                                        * Referenced by: '<S192>/Constant8'
                                        */
  real_T Q_2_Value_ca[16]; /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S192>/Q_2'
                            */
  real_T Q_3_Value_g[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S192>/Q_3'
                            */
  real_T Q_4_Value_po[16];   /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S192>/Q_4'
                              */
  real_T Gain1_Gain_p;                 /* Expression: -1
                                        * Referenced by: '<S194>/Gain1'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 0.5
                                        * Referenced by: '<S192>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: -1
                                        * Referenced by: '<S195>/Gain1'
                                        */
  real_T Gain1_Gain_cc;                /* Expression: 2
                                        * Referenced by: '<S193>/Gain1'
                                        */
  real_T Gain2_Gain_ev;                /* Expression: 2
                                        * Referenced by: '<S193>/Gain2'
                                        */
  real_T Gain3_Gain_h;                 /* Expression: 2
                                        * Referenced by: '<S193>/Gain3'
                                        */
  real_T Gain4_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S193>/Gain4'
                                        */
  real_T Gain5_Gain_a1;                /* Expression: 2
                                        * Referenced by: '<S193>/Gain5'
                                        */
  real_T Gain6_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S193>/Gain6'
                                        */
  real_T Gain7_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S193>/Gain7'
                                        */
  real_T Gain8_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S193>/Gain8'
                                        */
  real_T Gain9_Gain_fx;                /* Expression: 2
                                        * Referenced by: '<S193>/Gain9'
                                        */
  real_T Gain10_Gain_l;                /* Expression: 2
                                        * Referenced by: '<S193>/Gain10'
                                        */
  real_T Gain11_Gain_ky;               /* Expression: 2
                                        * Referenced by: '<S193>/Gain11'
                                        */
  real_T Gain12_Gain_bf;               /* Expression: 2
                                        * Referenced by: '<S193>/Gain12'
                                        */
  real_T Constant_Value_dg;            /* Expression: 1
                                        * Referenced by: '<S212>/Constant'
                                        */
  real_T Constant1_Value_gx;           /* Expression: -1
                                        * Referenced by: '<S212>/Constant1'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S212>/Merge'
                                       */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S212>/Switch'
                                        */
  real_T Constant_Value_fq;            /* Expression: 0.5
                                        * Referenced by: '<S213>/Constant'
                                        */
  real_T Constant1_Value_pl;           /* Expression: 0.5
                                        * Referenced by: '<S213>/Constant1'
                                        */
  real_T Gain_Gain_p0;                 /* Expression: 2
                                        * Referenced by: '<S213>/Gain'
                                        */
  real_T Saturation_UpperSat_gn;       /* Expression: 1
                                        * Referenced by: '<S213>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: -1
                                        * Referenced by: '<S213>/Saturation'
                                        */
  real_T Constant_Value_ly;            /* Expression: 0.5
                                        * Referenced by: '<S214>/Constant'
                                        */
  real_T Constant1_Value_py;           /* Expression: 0.5
                                        * Referenced by: '<S214>/Constant1'
                                        */
  real_T Gain_Gain_jr;                 /* Expression: 2
                                        * Referenced by: '<S214>/Gain'
                                        */
  real_T Saturation_UpperSat_db;       /* Expression: 1
                                        * Referenced by: '<S214>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -1
                                        * Referenced by: '<S214>/Saturation'
                                        */
  real_T Q_1_Value_ab[16]; /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S244>/Q_1'
                            */
  real_T Constant_Value_cu;            /* Expression: 0
                                        * Referenced by: '<S244>/Constant'
                                        */
  real_T Q_2_Value_m[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S244>/Q_2'
                            */
  real_T Q_3_Value_c1[16]; /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S244>/Q_3'
                            */
  real_T Q_4_Value_gi[16];   /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S244>/Q_4'
                              */
  real_T Gain1_Gain_gee;               /* Expression: -1
                                        * Referenced by: '<S247>/Gain1'
                                        */
  real_T Gain_Gain_bs;                 /* Expression: 0.5
                                        * Referenced by: '<S244>/Gain'
                                        */
  real_T Gain1_Gain_nw;                /* Expression: -1
                                        * Referenced by: '<S248>/Gain1'
                                        */
  real_T TransferFcn1_A[2];            /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S289>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C[2];            /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S289>/Transfer Fcn1'
                                        */
  real_T Gain_Gain_c5;                 /* Expression: 1
                                        * Referenced by: '<S289>/Gain'
                                        */
  real_T TransferFcn2_A[2];            /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S289>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C[2];            /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S289>/Transfer Fcn2'
                                        */
  real_T Gain1_Gain_bb;                /* Expression: 1
                                        * Referenced by: '<S289>/Gain1'
                                        */
  real_T TransferFcn3_A[2];            /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<S289>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C[2];            /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<S289>/Transfer Fcn3'
                                        */
  real_T Gain2_Gain_p;                 /* Expression: 1
                                        * Referenced by: '<S289>/Gain2'
                                        */
  real_T TransferFcn4_A[2];            /* Computed Parameter: TransferFcn4_A
                                        * Referenced by: '<S289>/Transfer Fcn4'
                                        */
  real_T TransferFcn4_C[2];            /* Computed Parameter: TransferFcn4_C
                                        * Referenced by: '<S289>/Transfer Fcn4'
                                        */
  real_T Gain3_Gain_l0;                /* Expression: 1
                                        * Referenced by: '<S289>/Gain3'
                                        */
  real_T Constant7_Value_ej[12];       /* Expression: Tr4r3
                                        * Referenced by: '<S281>/Constant7'
                                        */
  real_T Constant1_Value_l2;           /* Expression: unc_fin_def_roll
                                        * Referenced by: '<S71>/Constant1'
                                        */
  real_T Gain1_Gain_m2;                /* Expression: pi/180
                                        * Referenced by: '<S278>/Gain1'
                                        */
  real_T Constant2_Value_e;            /* Expression: unc_fin_def_pitch
                                        * Referenced by: '<S71>/Constant2'
                                        */
  real_T Gain1_Gain_ove;               /* Expression: pi/180
                                        * Referenced by: '<S279>/Gain1'
                                        */
  real_T Constant3_Value_m;            /* Expression: unc_fin_def_yaw
                                        * Referenced by: '<S71>/Constant3'
                                        */
  real_T Gain1_Gain_gj;                /* Expression: pi/180
                                        * Referenced by: '<S280>/Gain1'
                                        */
  real_T Constant6_Value_c;            /* Expression: T_sim_lnch
                                        * Referenced by: '<S72>/Constant6'
                                        */
  real_T deviation_Tmp_Value;          /* Expression: e_Tmp
                                        * Referenced by: '<S72>/deviation_Tmp'
                                        */
  real_T deviation_pa_QFH_Value;       /* Expression: e_pa
                                        * Referenced by: '<S72>/deviation_pa_QFH'
                                        */
  real_T Gain_Gain_nd;                 /* Expression: 180/pi
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Gain_Gain_bk;                 /* Expression: 180/pi
                                        * Referenced by: '<S22>/Gain'
                                        */
  real_T Gain_Gain_ju;                 /* Expression: 180/pi
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  real_T Gain_Gain_gj;                 /* Expression: 180/pi
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain_of;                 /* Expression: 180/pi
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator2'
                           */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator2'
                                        */
  real_T Gain_Gain_e2;                 /* Expression: 180/pi
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Zero1_Value;                  /* Expression: 0
                                        * Referenced by: '<S68>/Zero1'
                                        */
  real_T Gain_Gain_dy;                 /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S68>/Zero'
                                        */
  real_T Gain_Gain_ag;                 /* Expression: 180/pi
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Zero2_Value;                  /* Expression: 0
                                        * Referenced by: '<S68>/Zero2'
                                        */
  real_T Gain_Gain_b4;                 /* Expression: 180/pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Gain_Gain_abz;                /* Expression: 180/pi
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Gain_Gain_j1;                 /* Expression: 180/pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T Gain_Gain_ho;                 /* Expression: 180/pi
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T Gain_Gain_pm;                 /* Expression: 180/pi
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T Gain_Gain_fd;                 /* Expression: 180/pi
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Gain_Gain_me;                 /* Expression: 180/pi
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Gain_Gain_iq;                 /* Expression: 180/pi
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Gain_Gain_pzg;                /* Expression: 180/pi
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Gain_Gain_n4;                 /* Expression: 180/pi
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Zero1_Value_d;                /* Expression: -1
                                        * Referenced by: '<S2>/Zero1'
                                        */
  real_T Zero2_Value_k;                /* Expression: -1
                                        * Referenced by: '<S2>/Zero2'
                                        */
  real_T Zero6_Value;                  /* Expression: -1
                                        * Referenced by: '<S2>/Zero6'
                                        */
  real_T Zero5_Value;                  /* Expression: -1
                                        * Referenced by: '<S2>/Zero5'
                                        */
  real_T Zero4_Value;                  /* Expression: -1
                                        * Referenced by: '<S2>/Zero4'
                                        */
  real_T Zero3_Value;                  /* Expression: -1
                                        * Referenced by: '<S2>/Zero3'
                                        */
  real_T IntegratorSecondOrderLimited_ICX_l;/* Expression: 0
                                             * Referenced by: '<S43>/Integrator, Second-Order Limited'
                                             */
  real_T IntegratorSecondOrderLimited_ICDXDT_b;/* Expression: 0
                                                * Referenced by: '<S43>/Integrator, Second-Order Limited'
                                                */
  real_T Constant_Value_p3p;           /* Expression: dtype_a
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T ZeroOrderHold1_Gain_b;        /* Expression: 1
                                        * Referenced by: '<S36>/Zero-Order Hold1'
                                        */
  real_T Multiply2_Gain_g;             /* Expression: -9.81
                                        * Referenced by: '<S33>/Multiply2'
                                        */
  real_T Multiply_Gain_d;              /* Expression: 9.81
                                        * Referenced by: '<S33>/Multiply'
                                        */
  real_T Multiply1_Gain_n;             /* Expression: 9.81
                                        * Referenced by: '<S33>/Multiply1'
                                        */
  real_T ZeroOrderHold2_Gain_l;        /* Expression: 1
                                        * Referenced by: '<S36>/Zero-Order Hold2'
                                        */
  real_T ZeroOrderHold_Gain_a;         /* Expression: 1
                                        * Referenced by: '<S36>/Zero-Order Hold'
                                        */
  real_T Constant1_Value_plv[3];       /* Expression: [0,0,0]
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T ZeroOrderHold4_Gain_o;        /* Expression: 1
                                        * Referenced by: '<S36>/Zero-Order Hold4'
                                        */
  real_T Gain_Gain_en[3];              /* Expression: [1 -1 1]
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T ZeroOrderHold3_Gain_d;        /* Expression: 1
                                        * Referenced by: '<S36>/Zero-Order Hold3'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0.5
                                        * Referenced by: '<S38>/Switch'
                                        */
  real_T WhiteNoise_Mean_o;            /* Expression: 0
                                        * Referenced by: '<S39>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_l;         /* Computed Parameter: WhiteNoise_StdDev_l
                                       * Referenced by: '<S39>/White Noise'
                                       */
  real_T Saturation_UpperSat_m[3];     /* Expression: a_sath
                                        * Referenced by: '<S36>/Saturation'
                                        */
  real_T Saturation_LowerSat_e1[3];    /* Expression: a_satl
                                        * Referenced by: '<S36>/Saturation'
                                        */
  real_T IntegratorSecondOrderLimited_ICX_h;/* Expression: 0
                                             * Referenced by: '<S55>/Integrator, Second-Order Limited'
                                             */
  real_T IntegratorSecondOrderLimited_ICDXDT_d;/* Expression: 0
                                                * Referenced by: '<S55>/Integrator, Second-Order Limited'
                                                */
  real_T Constant_Value_jy;            /* Expression: dtype_g
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T ZeroOrderHold_Gain_i;         /* Expression: 1
                                        * Referenced by: '<S37>/Zero-Order Hold'
                                        */
  real_T ZeroOrderHold1_Gain_be;       /* Expression: 1
                                        * Referenced by: '<S37>/Zero-Order Hold1'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0.5
                                        * Referenced by: '<S52>/Switch'
                                        */
  real_T WhiteNoise_Mean_k;            /* Expression: 0
                                        * Referenced by: '<S53>/White Noise'
                                        */
  real_T WhiteNoise_StdDev_fq;       /* Computed Parameter: WhiteNoise_StdDev_fq
                                      * Referenced by: '<S53>/White Noise'
                                      */
  real_T Saturation_UpperSat_jb[3];    /* Expression: g_sath
                                        * Referenced by: '<S37>/Saturation'
                                        */
  real_T Saturation_LowerSat_h[3];     /* Expression: g_satl
                                        * Referenced by: '<S37>/Saturation'
                                        */
  real_T Zero_Value_d;                 /* Expression: 0
                                        * Referenced by: '<S28>/Zero'
                                        */
  real_T One_Value;                    /* Expression: 9
                                        * Referenced by: '<S57>/One'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: inf
                                        * Referenced by: '<S57>/Saturation'
                                        */
  real_T Saturation_LowerSat_gt;       /* Expression: 0
                                        * Referenced by: '<S57>/Saturation'
                                        */
  real_T course_angle_wind_Value;      /* Expression: 0
                                        * Referenced by: '<S283>/course_angle_wind'
                                        */
  real_T course_angle_uncertainty_Value;/* Expression: 0
                                         * Referenced by: '<S283>/course_angle_uncertainty'
                                         */
  real_T vWW_uncertainty_Value;        /* Expression: 0
                                        * Referenced by: '<S283>/vWW_uncertainty'
                                        */
  real_T vWW_Value;                    /* Expression: 0
                                        * Referenced by: '<S283>/vWW'
                                        */
  real_T Constant1_Value_m5;           /* Expression: 0
                                        * Referenced by: '<S283>/Constant1'
                                        */
  real_T Constant_Value_gk;            /* Expression: 1
                                        * Referenced by: '<S286>/Constant'
                                        */
  real_T Constant1_Value_co;           /* Expression: 0
                                        * Referenced by: '<S286>/Constant1'
                                        */
  real_T Constant2_Value_eo;           /* Expression: 0
                                        * Referenced by: '<S286>/Constant2'
                                        */
  real_T Constant8_Value_c2;           /* Expression: 0
                                        * Referenced by: '<S286>/Constant8'
                                        */
  real_T Gain_Gain_go;                 /* Expression: -1
                                        * Referenced by: '<S286>/Gain'
                                        */
  real_T Constant7_Value_gp;           /* Expression: 0
                                        * Referenced by: '<S286>/Constant7'
                                        */
  real_T Constant8_Value_j0;           /* Expression: 0
                                        * Referenced by: '<S287>/Constant8'
                                        */
  real_T Constant_Value_gx;            /* Expression: 0
                                        * Referenced by: '<S287>/Constant'
                                        */
  real_T Constant1_Value_hw;           /* Expression: 1
                                        * Referenced by: '<S287>/Constant1'
                                        */
  real_T Constant2_Value_lq;           /* Expression: 0
                                        * Referenced by: '<S287>/Constant2'
                                        */
  real_T Gain1_Gain_bg;                /* Expression: -1
                                        * Referenced by: '<S287>/Gain1'
                                        */
  real_T Constant7_Value_bf;           /* Expression: 0
                                        * Referenced by: '<S287>/Constant7'
                                        */
  real_T Gain_Gain_j0;                 /* Expression: -1
                                        * Referenced by: '<S288>/Gain'
                                        */
  real_T Constant8_Value_lk;           /* Expression: 0
                                        * Referenced by: '<S288>/Constant8'
                                        */
  real_T Constant7_Value_p;            /* Expression: 0
                                        * Referenced by: '<S288>/Constant7'
                                        */
  real_T Constant4_Value_e;            /* Expression: 0
                                        * Referenced by: '<S288>/Constant4'
                                        */
  real_T Constant10_Value_b;           /* Expression: 0
                                        * Referenced by: '<S288>/Constant10'
                                        */
  real_T Constant11_Value_ll;          /* Expression: 1
                                        * Referenced by: '<S288>/Constant11'
                                        */
  real_T Gain_Gain_nf;                 /* Expression: 180/pi
                                        * Referenced by: '<S18>/Gain'
                                        */
  real32_T Zero_Value_i;               /* Computed Parameter: Zero_Value_i
                                        * Referenced by: '<S63>/Zero'
                                        */
  uint16_T Constant_Value_hg;          /* Computed Parameter: Constant_Value_hg
                                        * Referenced by: '<S66>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S64>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S65>/FixPt Constant'
                                       */
  boolean_T One_Value_j;               /* Computed Parameter: One_Value_j
                                        * Referenced by: '<S68>/One'
                                        */
  uint8_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S61>/Out1'
                                        */
  P_EnabledSubsystem1_Mainframe_T EnabledSubsystem1_h;/* '<S72>/Enabled Subsystem1' */
  P_EnabledSubsystem1_Mainframe_T EnabledSubsystem1;/* '<S1>/Enabled Subsystem1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Mainframe_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[62];
  real_T odeF[3][62];
  ODE3_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    uint32_T clockTick3;
    uint32_T clockTickH3;
    time_T stepSize3;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[4];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[4];
    time_T offsetTimesArray[4];
    int_T sampleTimeTaskIDArray[4];
    int_T sampleHitArray[4];
    int_T perTaskSampleHitsArray[16];
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Mainframe_T Mainframe_P;

/* Block signals (default storage) */
extern B_Mainframe_T Mainframe_B;

/* Continuous states (default storage) */
extern X_Mainframe_T Mainframe_X;

/* Block states (default storage) */
extern DW_Mainframe_T Mainframe_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Mainframe_T Mainframe_PrevZCX;

/* Model entry point functions */
extern void Mainframe_initialize(void);
extern void Mainframe_output(void);
extern void Mainframe_update(void);
extern void Mainframe_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Mainframe_rtModel *Mainframe(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Mainframe_T *const Mainframe_M;

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
 * '<Root>' : 'Mainframe'
 * '<S1>'   : 'Mainframe/Attitude Commands'
 * '<S2>'   : 'Mainframe/Emulate Estimator'
 * '<S3>'   : 'Mainframe/Enabled Subsystem1'
 * '<S4>'   : 'Mainframe/Flight Control Computer'
 * '<S5>'   : 'Mainframe/Flight Gear Simulator'
 * '<S6>'   : 'Mainframe/Flight Table'
 * '<S7>'   : 'Mainframe/Non-linear Flight Dynamic Model'
 * '<S8>'   : 'Mainframe/Radians to Degrees1'
 * '<S9>'   : 'Mainframe/Radians to Degrees10'
 * '<S10>'  : 'Mainframe/Radians to Degrees11'
 * '<S11>'  : 'Mainframe/Radians to Degrees12'
 * '<S12>'  : 'Mainframe/Radians to Degrees13'
 * '<S13>'  : 'Mainframe/Radians to Degrees14'
 * '<S14>'  : 'Mainframe/Radians to Degrees15'
 * '<S15>'  : 'Mainframe/Radians to Degrees16'
 * '<S16>'  : 'Mainframe/Radians to Degrees17'
 * '<S17>'  : 'Mainframe/Radians to Degrees18'
 * '<S18>'  : 'Mainframe/Radians to Degrees19'
 * '<S19>'  : 'Mainframe/Radians to Degrees2'
 * '<S20>'  : 'Mainframe/Radians to Degrees3'
 * '<S21>'  : 'Mainframe/Radians to Degrees4'
 * '<S22>'  : 'Mainframe/Radians to Degrees5'
 * '<S23>'  : 'Mainframe/Radians to Degrees6'
 * '<S24>'  : 'Mainframe/Radians to Degrees7'
 * '<S25>'  : 'Mainframe/Radians to Degrees8'
 * '<S26>'  : 'Mainframe/Radians to Degrees9'
 * '<S27>'  : 'Mainframe/Servos'
 * '<S28>'  : 'Mainframe/Attitude Commands/Delayed Sine'
 * '<S29>'  : 'Mainframe/Attitude Commands/Delayed Step1'
 * '<S30>'  : 'Mainframe/Attitude Commands/Delayed Step2'
 * '<S31>'  : 'Mainframe/Attitude Commands/Enabled Subsystem1'
 * '<S32>'  : 'Mainframe/Emulate Estimator/EMULATED IMU'
 * '<S33>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Gravity Vector'
 * '<S34>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit'
 * '<S35>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Acceleration Conversion'
 * '<S36>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer'
 * '<S37>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Gyroscope'
 * '<S38>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics'
 * '<S39>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Random bias'
 * '<S40>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)'
 * '<S41>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d'
 * '<S42>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics/No Dynamics'
 * '<S43>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics/Second-order Dynamics'
 * '<S44>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)'
 * '<S45>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d'
 * '<S46>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem'
 * '<S47>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem1'
 * '<S48>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem'
 * '<S49>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem1'
 * '<S50>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d/Subsystem'
 * '<S51>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d/Subsystem1'
 * '<S52>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics'
 * '<S53>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Random bias'
 * '<S54>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics/No Dynamics'
 * '<S55>'  : 'Mainframe/Emulate Estimator/EMULATED IMU/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics/Second-order Dynamics'
 * '<S56>'  : 'Mainframe/Flight Control Computer/FCC'
 * '<S57>'  : 'Mainframe/Flight Control Computer/In Sync'
 * '<S58>'  : 'Mainframe/Flight Control Computer/Recieve from Pixhawk'
 * '<S59>'  : 'Mainframe/Flight Control Computer/Send to Pixhawk'
 * '<S60>'  : 'Mainframe/Flight Control Computer/FCC/Real FCC'
 * '<S61>'  : 'Mainframe/Flight Control Computer/FCC/Real FCC/Enabled Subsystem'
 * '<S62>'  : 'Mainframe/Flight Control Computer/FCC/Real FCC/Extract Message'
 * '<S63>'  : 'Mainframe/Flight Control Computer/Send to Pixhawk/Heartbeat'
 * '<S64>'  : 'Mainframe/Flight Control Computer/Send to Pixhawk/Heartbeat/Heartbeat'
 * '<S65>'  : 'Mainframe/Flight Control Computer/Send to Pixhawk/Heartbeat/Heartbeat/Increment Real World'
 * '<S66>'  : 'Mainframe/Flight Control Computer/Send to Pixhawk/Heartbeat/Heartbeat/Wrap To Zero'
 * '<S67>'  : 'Mainframe/Flight Gear Simulator/Flight Simulator Off'
 * '<S68>'  : 'Mainframe/Flight Table/Flight Table Off'
 * '<S69>'  : 'Mainframe/Non-linear Flight Dynamic Model/Simulation Stop-Condition'
 * '<S70>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem'
 * '<S71>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem1'
 * '<S72>'  : 'Mainframe/Non-linear Flight Dynamic Model/environment_global'
 * '<S73>'  : 'Mainframe/Non-linear Flight Dynamic Model/Simulation Stop-Condition/Compare To Constant'
 * '<S74>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States'
 * '<S75>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe'
 * '<S76>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1'
 * '<S77>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/MATLAB Function1'
 * '<S78>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/quaternion_to_euler_angles1'
 * '<S79>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Gravity Vector'
 * '<S80>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Rotation Angles to Quaternions'
 * '<S81>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit'
 * '<S82>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Acceleration Conversion'
 * '<S83>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer'
 * '<S84>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Gyroscope'
 * '<S85>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics'
 * '<S86>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Random bias'
 * '<S87>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)'
 * '<S88>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d'
 * '<S89>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics/No Dynamics'
 * '<S90>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics/Second-order Dynamics'
 * '<S91>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)'
 * '<S92>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d'
 * '<S93>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem'
 * '<S94>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem1'
 * '<S95>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem'
 * '<S96>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem1'
 * '<S97>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d/Subsystem'
 * '<S98>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d/Subsystem1'
 * '<S99>'  : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics'
 * '<S100>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Random bias'
 * '<S101>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics/No Dynamics'
 * '<S102>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/Extract Relevant States/Assemble_States_Bus1/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics/Second-order Dynamics'
 * '<S103>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics'
 * '<S104>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment'
 * '<S105>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators'
 * '<S106>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/forces_moments'
 * '<S107>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/gravity'
 * '<S108>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/input'
 * '<S109>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics'
 * '<S110>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion'
 * '<S111>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom'
 * '<S112>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow'
 * '<S113>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance'
 * '<S114>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup'
 * '<S115>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/logic_base_drag'
 * '<S116>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients'
 * '<S117>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom'
 * '<S118>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients/CLL_TLU'
 * '<S119>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients/CLM_TLU'
 * '<S120>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients/CLN_TLU'
 * '<S121>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients/CX_TLU'
 * '<S122>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients/CY_TLU'
 * '<S123>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients/CZ_TLU'
 * '<S124>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/create_pAPB'
 * '<S125>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/cross_product'
 * '<S126>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail'
 * '<S127>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1'
 * '<S128>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude'
 * '<S129>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic'
 * '<S130>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S131>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S132>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude'
 * '<S133>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic'
 * '<S134>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S135>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S136>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/aerodynamics/logic_base_drag/MATLAB Function'
 * '<S137>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/WGS84_Gravitation'
 * '<S138>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/atmosphere_static_ISO_2533'
 * '<S139>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/convert_to_local_frame'
 * '<S140>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/WGS84_Gravitation/Compare To Constant'
 * '<S141>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/WGS84_Gravitation/Interval Test'
 * '<S142>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/WGS84_Gravitation/Interval Test1'
 * '<S143>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/WGS84_Gravitation/WGS84_2_ECEF'
 * '<S144>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/WGS84_Gravitation/WGS84_Gravity_Implementation'
 * '<S145>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/WGS84_Gravitation/WGS84_2_ECEF/WGS84 Transformation Parameter '
 * '<S146>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/WGS84_Gravitation/WGS84_2_ECEF/WGS84 Transformation Parameter /Subsystem'
 * '<S147>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/atmosphere_static_ISO_2533/density'
 * '<S148>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/atmosphere_static_ISO_2533/geopot_height'
 * '<S149>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/atmosphere_static_ISO_2533/speed_of_sound'
 * '<S150>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533'
 * '<S151>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533/static_Temperature'
 * '<S152>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533/static_pressure'
 * '<S153>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder'
 * '<S154>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder1'
 * '<S155>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder2'
 * '<S156>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder3'
 * '<S157>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/control_allocation'
 * '<S158>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder/Limiting_Acceleration'
 * '<S159>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder/Limiting_Rate'
 * '<S160>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder1/Limiting_Acceleration'
 * '<S161>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder1/Limiting_Rate'
 * '<S162>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder2/Limiting_Acceleration'
 * '<S163>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder2/Limiting_Rate'
 * '<S164>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder3/Limiting_Acceleration'
 * '<S165>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/fin_actuators/Rudder3/Limiting_Rate'
 * '<S166>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/gravity/launch_rail'
 * '<S167>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/gravity/launch_rail/initial_altitude'
 * '<S168>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic'
 * '<S169>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S170>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S171>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics'
 * '<S172>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix'
 * '<S173>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation'
 * '<S174>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q1'
 * '<S175>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q12'
 * '<S176>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q2'
 * '<S177>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/conjugate_quaternion'
 * '<S178>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q1'
 * '<S179>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q2'
 * '<S180>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q21'
 * '<S181>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q1/normalize_quaternion'
 * '<S182>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q2/normalize_quaternion'
 * '<S183>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q21/normalize_quaternion'
 * '<S184>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/earth_rotation_rate'
 * '<S185>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration'
 * '<S186>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1'
 * '<S187>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/transport_rate'
 * '<S188>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1'
 * '<S189>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/T12_from_q12'
 * '<S190>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1/conjugate_quaternion1'
 * '<S191>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1/conjugate_quaternion2'
 * '<S192>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1'
 * '<S193>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/T12_from_q12'
 * '<S194>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1/conjugate_quaternion1'
 * '<S195>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1/conjugate_quaternion2'
 * '<S196>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_look_up'
 * '<S197>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty'
 * '<S198>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat'
 * '<S199>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/cross_product'
 * '<S200>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/1. Rotation x-Achse'
 * '<S201>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/1. Rotation y-Achse'
 * '<S202>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/1. Rotation z-Achse'
 * '<S203>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/2. Rotation x-Achse'
 * '<S204>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/2. Rotation y-Achse'
 * '<S205>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/2. Rotation z-Achse'
 * '<S206>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/3. Rotation x-Achse'
 * '<S207>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/3. Rotation y-Achse'
 * '<S208>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/propulsion/prp_uncertainty/3_rot_mat/3. Rotation z-Achse'
 * '<S209>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries'
 * '<S210>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof'
 * '<S211>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2'
 * '<S212>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12'
 * '<S213>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/quaternion_to_euler_angles'
 * '<S214>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/quaternion_to_euler_angles1'
 * '<S215>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic'
 * '<S216>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S217>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S218>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 0'
 * '<S219>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 1'
 * '<S220>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 2'
 * '<S221>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 3'
 * '<S222>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/normalize_quaternion'
 * '<S223>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/q_R^0(R)'
 * '<S224>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/q_R^1(R)'
 * '<S225>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/q_R^2(R)'
 * '<S226>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/q_R^3(R)'
 * '<S227>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 0/dcm11 >= -dcm22'
 * '<S228>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 0/dcm11 >= -dcm33'
 * '<S229>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 0/dcm22 >= -dcm33'
 * '<S230>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 1/dcm11 >= dcm22'
 * '<S231>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 1/dcm11 >= dcm33'
 * '<S232>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 1/dcm22 < -dcm33'
 * '<S233>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 2/dcm11 < -dcm33'
 * '<S234>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 2/dcm11 < dcm22'
 * '<S235>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 2/dcm22 >= dcm33'
 * '<S236>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 3/dcm11 < -dcm22'
 * '<S237>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 3/dcm11 < dcm33'
 * '<S238>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/calc_bus_flight_dyn_bus_entries/q12_from_T12/Case 3/dcm22 < dcm33'
 * '<S239>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF'
 * '<S240>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/Integration'
 * '<S241>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/T12_from_q12'
 * '<S242>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof'
 * '<S243>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/Integration/normalize_quaternion'
 * '<S244>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB'
 * '<S245>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/cross_product'
 * '<S246>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/r2_from_r1_trans_q21'
 * '<S247>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB/conjugate_quaternion'
 * '<S248>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB/conjugate_quaternion1'
 * '<S249>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow/calc_stream_flow'
 * '<S250>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow/calc_stream_flow/Subsystem1'
 * '<S251>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow/calc_stream_flow/velocity_vector_transformation'
 * '<S252>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow/calc_stream_flow/Subsystem1/AoA_Sideslip_Alphatot_Phi'
 * '<S253>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow/calc_stream_flow/Subsystem1/calc_nondimensional_rates'
 * '<S254>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow/calc_stream_flow/Subsystem1/norm_of_vector'
 * '<S255>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow/calc_stream_flow/Subsystem1/AoA_Sideslip_Alphatot_Phi/norm_of_vector'
 * '<S256>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/stream_flow/calc_stream_flow/velocity_vector_transformation/cross_product'
 * '<S257>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/center_of_gravity'
 * '<S258>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/mass'
 * '<S259>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/mass_uncertainty'
 * '<S260>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi'
 * '<S261>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/JMMM_linear_interpolation'
 * '<S262>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation'
 * '<S263>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_uncertainty'
 * '<S264>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/steiners_theorem_missile'
 * '<S265>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/steiners_theorem_motor'
 * '<S266>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat'
 * '<S267>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation x-Achse'
 * '<S268>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation y-Achse'
 * '<S269>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation z-Achse'
 * '<S270>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation x-Achse'
 * '<S271>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation y-Achse'
 * '<S272>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation z-Achse'
 * '<S273>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation x-Achse'
 * '<S274>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation y-Achse'
 * '<S275>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation z-Achse'
 * '<S276>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/steiners_theorem_missile/create_deviation_matrix'
 * '<S277>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem/GRM_Airframe/weight_and_balance/moi/steiners_theorem_motor/create_deviation_matrix1'
 * '<S278>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem1/Degrees to Radians'
 * '<S279>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem1/Degrees to Radians1'
 * '<S280>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem1/Degrees to Radians2'
 * '<S281>' : 'Mainframe/Non-linear Flight Dynamic Model/Subsystem1/control_allocation'
 * '<S282>' : 'Mainframe/Non-linear Flight Dynamic Model/environment_global/Enabled Subsystem1'
 * '<S283>' : 'Mainframe/Non-linear Flight Dynamic Model/environment_global/atm_dynamic'
 * '<S284>' : 'Mainframe/Non-linear Flight Dynamic Model/environment_global/atm_dynamic/trafo_around_z_axis'
 * '<S285>' : 'Mainframe/Non-linear Flight Dynamic Model/environment_global/atm_dynamic/trafo_around_z_axis/1_rot_mat'
 * '<S286>' : 'Mainframe/Non-linear Flight Dynamic Model/environment_global/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation x-Achse'
 * '<S287>' : 'Mainframe/Non-linear Flight Dynamic Model/environment_global/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation y-Achse'
 * '<S288>' : 'Mainframe/Non-linear Flight Dynamic Model/environment_global/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation z-Achse'
 * '<S289>' : 'Mainframe/Servos/Emulated Servos'
 */
#endif                                 /* RTW_HEADER_Mainframe_h_ */
