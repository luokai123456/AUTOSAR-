/*
 * File: plook_u32ff_binca.c
 *
 * Code generated for Simulink model 'swc_BatChCtl'.
 *
 * Model version                  : 1.435
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 09:39:00 2023
 */

#include "plook_u32ff_binca.h"
#include "binsearch_u32f.h"
#include "rtwtypes.h"
#define swc_BatChCtl_START_SEC_CODE
#include "swc_BatChCtl_MemMap.h"

uint32 plook_u32ff_binca(float32 u, const float32 bp[], uint32 maxIndex,
  float32 *fraction)
{
  uint32 bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0F;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex;
    *fraction = 0.0F;
  }

  return bpIndex;
}

#define swc_BatChCtl_STOP_SEC_CODE
#include "swc_BatChCtl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
