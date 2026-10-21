/*
 * File: plook_u32u32f_binc.c
 *
 * Code generated for Simulink model 'swc_BatCoreFct'.
 *
 * Model version                  : 9.36
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 11 14:56:58 2024
 */

#include "plook_u32u32f_binc.h"
#include "binsearch_u32u32.h"
#include "rtwtypes.h"

uint32 plook_u32u32f_binc(uint32 u, const uint32 bp[], uint32 maxIndex,
  float32 *fraction)
{
  uint32 bpIndex;
  uint32 bpLeftVar;

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
    bpIndex = binsearch_u32u32(u, bp, maxIndex >> 1U, maxIndex);
    bpLeftVar = bp[bpIndex];
    *fraction = (float32)(u - bpLeftVar) / (float32)(bp[bpIndex + 1U] -
      bpLeftVar);
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 1.0F;
  }

  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
