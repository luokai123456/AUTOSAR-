/*
 * File: intrp3d_fu32fl_pw.c
 *
 * Code generated for Simulink model 'swc_BatCoreFct'.
 *
 * Model version                  : 1.318
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 16:29:54 2023
 */

#include "intrp3d_fu32fl_pw.h"
#include "rtwtypes.h"
#define swc_BatCoreFct_START_SEC_CODE
#include "swc_BatCoreFct_MemMap.h"

float32 intrp3d_fu32fl_pw(const uint32 bpIndex[], const float32 frac[],
  const float32 table[], const uint32 stride[])
{
  float32 yL_0d0;
  float32 yL_1d;
  float32 yL_2d;
  uint32 offset_0d;
  uint32 offset_2d;

  /* Column-major Interpolation 3-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  offset_2d = (bpIndex[2U] * stride[2U] + bpIndex[1U] * stride[1U]) + bpIndex[0U];
  yL_0d0 = table[offset_2d];
  yL_1d = (table[offset_2d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
  offset_0d = offset_2d + stride[1U];
  yL_0d0 = table[offset_0d];
  yL_2d = (((table[offset_0d + 1U] - yL_0d0) * frac[0U] + yL_0d0) - yL_1d) *
    frac[1U] + yL_1d;
  offset_2d += stride[2U];
  yL_0d0 = table[offset_2d];
  yL_1d = (table[offset_2d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
  offset_0d = offset_2d + stride[1U];
  yL_0d0 = table[offset_0d];
  return (((((table[offset_0d + 1U] - yL_0d0) * frac[0U] + yL_0d0) - yL_1d) *
           frac[1U] + yL_1d) - yL_2d) * frac[2U] + yL_2d;
}

#define swc_BatCoreFct_STOP_SEC_CODE
#include "swc_BatCoreFct_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
