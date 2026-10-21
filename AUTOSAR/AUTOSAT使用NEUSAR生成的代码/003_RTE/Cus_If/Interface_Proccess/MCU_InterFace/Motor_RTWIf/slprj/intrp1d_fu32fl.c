/*
 * File: intrp1d_fu32fl.c
 *
 * Code generated for Simulink model 'SigResolverAngleDecoder'.
 *
 * Model version                  : 1.101
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jun 12 17:46:21 2026
 */

#include "intrp1d_fu32fl.h"
#include "rtwtypes.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

real32_T intrp1d_fu32fl(uint32_T bpIndex, real32_T frac, real32_T table[])
{
  real32_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
