/*
 * File: SrvOpenLoopService_private.h
 *
 * Code generated for Simulink model 'SrvOpenLoopService'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:31:51 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SrvOpenLoopService_private_h_
#define RTW_HEADER_SrvOpenLoopService_private_h_
#include "rtwtypes.h"
#include "SrvOpenLoopService_types.h"
#include "SrvOpenLoopService.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern int32_T mul_s32_sat(int32_T a, int32_T b);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */

/* Data with Imported storage */
extern EnumCtlMode CTSO_OperationMode; /* '<Root>/CTSO_OperationMode' */
extern real32_T SGPP_ElecAngle;        /* '<Root>/SGPP_ElecAngle' */
extern uint8_T SGPP_PolePairs;         /* '<Root>/SGPP_PolePairs' */
extern real32_T SGPP_SampleTime1;      /* '<Root>/SGPP_SampleTime1' */
extern real32_T SGPP_SpeedSp;          /* '<Root>/SGPP_SpeedSp' */

#endif                            /* RTW_HEADER_SrvOpenLoopService_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
