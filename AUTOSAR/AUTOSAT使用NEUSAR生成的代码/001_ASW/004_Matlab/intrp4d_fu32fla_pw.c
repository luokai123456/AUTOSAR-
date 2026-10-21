/*
 * File: intrp4d_fu32fla_pw.c
 *
 * Code generated for Simulink model 'swc_BatChCtl'.
 *
 * Model version                  : 1.435
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 16:37:23 2023
 */

#include "intrp4d_fu32fla_pw.h"
#include "rtwtypes.h"
#define swc_BatChCtl_START_SEC_CODE
#include "swc_BatChCtl_MemMap.h"

float32 intrp4d_fu32fla_pw(const uint32 bpIndex[], const float32 frac[],
  const float32 table[], const uint32 stride[], const uint32 maxIndex[])
{
  float32 y;
  float32 yL_0d0;
  float32 yL_1d;
  float32 yL_1d_0;
  uint32 offset_0d;
  uint32 offset_1d;
  uint32 offset_3d;

  /* Column-major Interpolation 4-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  offset_3d = ((bpIndex[3U] * stride[3U] + bpIndex[2U] * stride[2U]) + bpIndex
               [1U] * stride[1U]) + bpIndex[0U];
  if (bpIndex[0U] == maxIndex[0U]) {
    y = table[offset_3d];
  } else {
    yL_0d0 = table[offset_3d];
    y = (table[offset_3d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
  }

  if (bpIndex[1U] == maxIndex[1U]) {
  } else {
    offset_0d = offset_3d + stride[1U];
    if (bpIndex[0U] == maxIndex[0U]) {
      yL_0d0 = table[offset_0d];
    } else {
      yL_0d0 = table[offset_0d];
      yL_0d0 += (table[offset_0d + 1U] - yL_0d0) * frac[0U];
    }

    y += (yL_0d0 - y) * frac[1U];
  }

  if (bpIndex[2U] == maxIndex[2U]) {
  } else {
    offset_1d = offset_3d + stride[2U];
    if (bpIndex[0U] == maxIndex[0U]) {
      yL_1d = table[offset_1d];
    } else {
      yL_0d0 = table[offset_1d];
      yL_1d = (table[offset_1d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
    }

    if (bpIndex[1U] == maxIndex[1U]) {
    } else {
      offset_0d = offset_1d + stride[1U];
      if (bpIndex[0U] == maxIndex[0U]) {
        yL_0d0 = table[offset_0d];
      } else {
        yL_0d0 = table[offset_0d];
        yL_0d0 += (table[offset_0d + 1U] - yL_0d0) * frac[0U];
      }

      yL_1d += (yL_0d0 - yL_1d) * frac[1U];
    }

    y += (yL_1d - y) * frac[2U];
  }

  if (bpIndex[3U] == maxIndex[3U]) {
  } else {
    offset_1d = offset_3d + stride[3U];
    if (bpIndex[0U] == maxIndex[0U]) {
      yL_1d = table[offset_1d];
    } else {
      yL_0d0 = table[offset_1d];
      yL_1d = (table[offset_1d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
    }

    if (bpIndex[1U] == maxIndex[1U]) {
    } else {
      offset_0d = offset_1d + stride[1U];
      if (bpIndex[0U] == maxIndex[0U]) {
        yL_0d0 = table[offset_0d];
      } else {
        yL_0d0 = table[offset_0d];
        yL_0d0 += (table[offset_0d + 1U] - yL_0d0) * frac[0U];
      }

      yL_1d += (yL_0d0 - yL_1d) * frac[1U];
    }

    if (bpIndex[2U] == maxIndex[2U]) {
    } else {
      offset_1d += stride[2U];
      if (bpIndex[0U] == maxIndex[0U]) {
        yL_1d_0 = table[offset_1d];
      } else {
        yL_0d0 = table[offset_1d];
        yL_1d_0 = (table[offset_1d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
      }

      if (bpIndex[1U] == maxIndex[1U]) {
      } else {
        offset_0d = offset_1d + stride[1U];
        if (bpIndex[0U] == maxIndex[0U]) {
          yL_0d0 = table[offset_0d];
        } else {
          yL_0d0 = table[offset_0d];
          yL_0d0 += (table[offset_0d + 1U] - yL_0d0) * frac[0U];
        }

        yL_1d_0 += (yL_0d0 - yL_1d_0) * frac[1U];
      }

      yL_1d += (yL_1d_0 - yL_1d) * frac[2U];
    }

    y += (yL_1d - y) * frac[3U];
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
