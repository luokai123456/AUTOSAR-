/*
 * File: intrp2d_fu32fla_pw.c
 *
 * Code generated for Simulink model 'swc_BatCoreFct'.
 *
 * Model version                  : 1.318
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 16:29:54 2023
 */

#include "intrp2d_fu32fla_pw.h"
#include "rtwtypes.h"
#define swc_BatCoreFct_START_SEC_CODE
#include "swc_BatCoreFct_MemMap.h"

float32 intrp2d_fu32fla_pw(const uint32 bpIndex[], const float32 frac[],
  const float32 table[], const uint32 stride, const uint32 maxIndex[])
{
  float32 y;
  float32 yL_0d0;
  uint32 offset_1d;

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  offset_1d = bpIndex[1U] * stride + bpIndex[0U];
  if (bpIndex[0U] == maxIndex[0U]) {
    y = table[offset_1d];
  } else {
    yL_0d0 = table[offset_1d];
    y = (table[offset_1d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
  }

  if (bpIndex[1U] == maxIndex[1U]) {
  } else {
    offset_1d += stride;
    if (bpIndex[0U] == maxIndex[0U]) {
      yL_0d0 = table[offset_1d];
    } else {
      yL_0d0 = table[offset_1d];
      yL_0d0 += (table[offset_1d + 1U] - yL_0d0) * frac[0U];
    }

    y += (yL_0d0 - y) * frac[1U];
  }

  return y;
}

#define swc_BatCoreFct_STOP_SEC_CODE
#include "swc_BatCoreFct_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
