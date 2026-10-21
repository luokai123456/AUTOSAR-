/*
 * File: plook_u32dff_binca.c
 *
 * Code generated for Simulink model 'swc_BatCoreFct'.
 *
 * Model version                  : 9.80
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 18 10:01:33 2024
 */

#include "plook_u32dff_binca.h"
#include "binsearch_u32df.h"
#include "rtwtypes.h"

uint32 plook_u32dff_binca(float64 u, const float32 bp[], uint32 maxIndex,
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
    bpIndex = binsearch_u32df(u, bp, maxIndex >> 1U, maxIndex);
    *fraction = (float32)((u - bp[bpIndex]) / ((float64)bp[bpIndex + 1U] -
      bp[bpIndex]));
  } else {
    bpIndex = maxIndex;
    *fraction = 0.0F;
  }

  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
