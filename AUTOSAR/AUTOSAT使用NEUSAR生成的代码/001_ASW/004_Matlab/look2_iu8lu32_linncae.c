/*
 * File: look2_iu8lu32_linncae.c
 *
 * Code generated for Simulink model 'vcu_arch'.
 *
 * Model version                  : 11.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr 27 15:26:59 2026
 */

#include "look2_iu8lu32_linncae.h"
#include "rtwtypes.h"

uint8 look2_iu8lu32_linncae(uint8 u0, uint8 u1, const uint8 bp0[], const
  uint8 bp1[], const uint8 table[], const uint32 maxIndex[], uint32
  stride)
{
  uint32 bpIndices[2];
  uint32 bpIdx;

  /* Column-major Lookup 2-D
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Nearest'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index only
     Index Search method: 'linear'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[0U] >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    if ((bpIdx < maxIndex[0U]) && ((uint8)((uint32)bp0[bpIdx + 1U] - u0) <=
         (uint8)((uint32)u0 - bp0[bpIdx]))) {
      bpIdx++;
    }
  } else {
    bpIdx = maxIndex[0U];
  }

  bpIndices[0U] = bpIdx;

  /* Prelookup - Index only
     Index Search method: 'linear'
     Interpolation method: 'Use nearest'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    bpIdx = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[1U] >> 1U; u1 < bp1[bpIdx]; bpIdx--) {
    }

    while (u1 >= bp1[bpIdx + 1U]) {
      bpIdx++;
    }

    if ((bpIdx < maxIndex[1U]) && ((uint8)((uint32)bp1[bpIdx + 1U] - u1) <=
         (uint8)((uint32)u1 - bp1[bpIdx]))) {
      bpIdx++;
    }
  } else {
    bpIdx = maxIndex[1U];
  }

  return table[bpIdx * stride + bpIndices[0]];
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
