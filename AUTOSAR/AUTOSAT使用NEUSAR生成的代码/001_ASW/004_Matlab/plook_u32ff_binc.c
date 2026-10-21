/*
 * File: plook_u32ff_binc.c
 *
 * Code generated for Simulink model 'swc_BatCoreFct'.
 *
 * Model version                  : 1.318
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 16:29:54 2023
 */

#include "plook_u32ff_binc.h"
#include "binsearch_u32f.h"
#include "rtwtypes.h"
#define swc_BatCoreFct_START_SEC_CODE
#include "swc_BatCoreFct_MemMap.h"

uint32 plook_u32ff_binc(float32 u, const float32 bp[], uint32 maxIndex,
  float32 *fraction)
{
  uint32 bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
    *fraction = 0.0F;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (u - bp[bpIndex]) / (bp[bpIndex + 1U] - bp[bpIndex]);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0F;
  }

  return bpIndex;
}

#define swc_BatCoreFct_STOP_SEC_CODE
#include "swc_BatCoreFct_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
