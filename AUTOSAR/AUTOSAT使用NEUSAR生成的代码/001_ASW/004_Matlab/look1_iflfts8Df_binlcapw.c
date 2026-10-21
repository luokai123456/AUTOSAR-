/*
 * File: look1_iflfts8Df_binlcapw.c
 *
 * Code generated for Simulink model 'swc_BatChCtl'.
 *
 * Model version                  : 1.435
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 09:39:00 2023
 */

#include "look1_iflfts8Df_binlcapw.h"
#include <math.h>
#include "rtwtypes.h"
#define swc_BatChCtl_START_SEC_CODE
#include "swc_BatChCtl_MemMap.h"

sint8 look1_iflfts8Df_binlcapw(float32 u0, const float32 bp0[], const sint8
  table[], uint32 maxIndex)
{
  float32 frac;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  sint8 y;
  sint8 yL_0d0;

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

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
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
    yL_0d0 = table[iLeft];
    frac *= (float32)table[iLeft + 1U] - (float32)yL_0d0;
    if (frac < 0.0F) {
      frac = (float32)ceil(frac);
    } else {
      frac = (float32)floor(frac);
    }

    frac = (float32)fmod(frac, 256.0);
    y = (sint8)((sint8)(frac < 0.0F ? (sint32)(sint8)-(sint8)(uint8)-frac
                          : (sint32)(sint8)(uint8)frac) + yL_0d0);
  }

  return y;
}

#define swc_BatChCtl_STOP_SEC_CODE
#include "swc_BatChCtl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
