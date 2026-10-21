/*
 * File: look2_iflftu8Dfdf_binlcapw.c
 *
 * Code generated for Simulink model 'swc_BatCoreFct'.
 *
 * Model version                  : 9.9
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Oct 16 09:56:45 2023
 */

#include "look2_iflftu8Dfdf_binlcapw.h"
#include <math.h>
#include "rtwtypes.h"

uint8 look2_iflftu8Dfdf_binlcapw(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const uint8 table[], const uint32 maxIndex[],
  uint32 stride)
{
  float32 fractions[2];
  float32 frac;
  float32 u;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 y;
  uint8 yL_0d0;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    u = ((float32)table[bpIdx + 1U] - (float32)yL_0d0) * fractions[0U];
    if (u < 0.0F) {
      u = (float32)ceil(u);
    } else {
      u = (float32)floor(u);
    }

    u = (float32)fmod(u, 256.0);
    y = (uint8)((uint32)(uint8)(u < 0.0F ? (sint32)(uint8)-(sint8)
      (uint8)-u : (sint32)(uint8)u) + yL_0d0);
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      u = ((float32)table[bpIdx + 1U] - (float32)yL_0d0) * fractions[0U];
      if (u < 0.0F) {
        u = (float32)ceil(u);
      } else {
        u = (float32)floor(u);
      }

      u = (float32)fmod(u, 256.0);
      yL_0d0 = (uint8)((uint32)(uint8)(u < 0.0F ? (sint32)(uint8)
        -(sint8)(uint8)-u : (sint32)(uint8)u) + yL_0d0);
    }

    u = ((float32)yL_0d0 - (float32)y) * frac;
    if (u < 0.0F) {
      u = (float32)ceil(u);
    } else {
      u = (float32)floor(u);
    }

    u = (float32)fmod(u, 256.0);
    y = (uint8)((uint32)(uint8)(u < 0.0F ? (sint32)(uint8)-(sint8)
      (uint8)-u : (sint32)(uint8)u) + y);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
