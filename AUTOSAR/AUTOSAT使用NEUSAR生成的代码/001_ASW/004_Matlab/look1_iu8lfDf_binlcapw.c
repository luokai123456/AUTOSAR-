/*
 * File: look1_iu8lfDf_binlcapw.c
 *
 * Code generated for Simulink model 'swc_BatBalnCtl'.
 *
 * Model version                  : 1.234
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 16:57:31 2023
 */

#include "look1_iu8lfDf_binlcapw.h"
#include <math.h>
#include "rtwtypes.h"
#define swc_BatBalnCtl_START_SEC_CODE
#include "swc_BatBalnCtl_MemMap.h"

uint8 look1_iu8lfDf_binlcapw(uint8 u0, const uint8 bp0[], const uint8
  table[], uint32 maxIndex)
{
  float32 frac;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 bpLeftVar;
  uint8 y;

  /* Column-major Lookup 1-D
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
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    bpLeftVar = bp0[iLeft];
    frac = (float32)(uint8)((uint32)u0 - bpLeftVar) / (float32)(uint8)
      ((uint32)bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    bpLeftVar = table[iLeft];
    frac *= (float32)table[iLeft + 1U] - (float32)bpLeftVar;
    if (frac < 0.0F) {
      frac = (float32)ceil(frac);
    } else {
      frac = (float32)floor(frac);
    }

    frac = (float32)fmod(frac, 256.0);
    y = (uint8)((uint32)(uint8)(frac < 0.0F ? (sint32)(uint8)-(sint8)
      (uint8)-frac : (sint32)(uint8)frac) + bpLeftVar);
  }

  return y;
}

#define swc_BatBalnCtl_STOP_SEC_CODE
#include "swc_BatBalnCtl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
