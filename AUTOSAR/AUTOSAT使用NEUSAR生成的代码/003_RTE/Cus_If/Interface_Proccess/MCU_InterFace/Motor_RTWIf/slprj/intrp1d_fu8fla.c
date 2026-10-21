/*
 * File: intrp1d_fu8fla.c
 *
 * Code generated for Simulink model 'CtlDeratingManager'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:43:33 2026
 */

#include "intrp1d_fu8fla.h"
#include "rtwtypes.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

real32_T intrp1d_fu8fla(uint8_T bpIndex, real32_T frac, const real32_T table[],
  uint32_T maxIndex)
{
  real32_T y;
  real32_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  if (bpIndex == maxIndex) {
    y = table[(uint32_T)bpIndex];
  } else {
    yL_0d0 = table[(uint32_T)bpIndex];
    y = (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
