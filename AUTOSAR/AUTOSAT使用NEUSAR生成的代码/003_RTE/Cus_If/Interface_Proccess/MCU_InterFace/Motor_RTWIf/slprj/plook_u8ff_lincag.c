/*
 * File: plook_u8ff_lincag.c
 *
 * Code generated for Simulink model 'CtlTorqueLoopController'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:39:37 2026
 */

#include "plook_u8ff_lincag.h"
#include "rtwtypes.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

uint8_T plook_u8ff_lincag(real32_T u, const real32_T bp[], uint32_T maxIndex,
  real32_T *fraction)
{
  uint32_T bpIdx;
  uint8_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
   */
  /* Linear Search */
  bpIdx = maxIndex >> 1U;
  while ((u < bp[bpIdx]) && (bpIdx > 0U)) {
    bpIdx--;
  }

  while ((bpIdx < maxIndex) && (u >= bp[bpIdx + 1U])) {
    bpIdx++;
  }

  bpIndex = (uint8_T)bpIdx;
  *fraction = (u - bp[(uint32_T)(uint8_T)bpIdx]) / (bp[(uint8_T)bpIdx + 1U] -
    bp[(uint32_T)(uint8_T)bpIdx]);
  return bpIndex;
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
