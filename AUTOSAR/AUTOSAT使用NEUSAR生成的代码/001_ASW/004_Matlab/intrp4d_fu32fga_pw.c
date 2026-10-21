/*
 * File: intrp4d_fu32fga_pw.c
 *
 * Code generated for Simulink model 'swc_BatChCtl'.
 *
 * Model version                  : 9.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Sep 11 10:07:18 2023
 */

#include "intrp4d_fu32fga_pw.h"
#include "rtwtypes.h"

float32 intrp4d_fu32fga_pw(const uint32 bpIndex[], const float32 frac[],
  const float32 table[], const uint32 stride[], const uint32 maxIndex[])
{
  float32 y;
  float32 yL_1d;
  float32 yL_1d_0;
  float32 yR_1d;
  uint32 offset_0d;
  uint32 offset_1d;
  uint32 offset_3d;

  /* Column-major Interpolation 4-D
     Interpolation method: 'Linear Lagrange'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  offset_3d = ((bpIndex[3U] * stride[3U] + bpIndex[2U] * stride[2U]) + bpIndex
               [1U] * stride[1U]) + bpIndex[0U];
  if (bpIndex[0U] == maxIndex[0U]) {
    y = table[offset_3d];
  } else {
    y = (1.0F - frac[0U]) * table[offset_3d] + table[offset_3d + 1U] * frac[0U];
  }

  if (bpIndex[1U] == maxIndex[1U]) {
  } else {
    offset_0d = offset_3d + stride[1U];
    if (bpIndex[0U] == maxIndex[0U]) {
      yR_1d = table[offset_0d];
    } else {
      yR_1d = (1.0F - frac[0U]) * table[offset_0d] + table[offset_0d + 1U] *
        frac[0U];
    }

    y = (1.0F - frac[1U]) * y + frac[1U] * yR_1d;
  }

  if (bpIndex[2U] == maxIndex[2U]) {
  } else {
    offset_1d = offset_3d + stride[2U];
    if (bpIndex[0U] == maxIndex[0U]) {
      yL_1d = table[offset_1d];
    } else {
      yL_1d = (1.0F - frac[0U]) * table[offset_1d] + table[offset_1d + 1U] *
        frac[0U];
    }

    if (bpIndex[1U] == maxIndex[1U]) {
    } else {
      offset_0d = offset_1d + stride[1U];
      if (bpIndex[0U] == maxIndex[0U]) {
        yR_1d = table[offset_0d];
      } else {
        yR_1d = (1.0F - frac[0U]) * table[offset_0d] + table[offset_0d + 1U] *
          frac[0U];
      }

      yL_1d = (1.0F - frac[1U]) * yL_1d + frac[1U] * yR_1d;
    }

    y = (1.0F - frac[2U]) * y + frac[2U] * yL_1d;
  }

  if (bpIndex[3U] == maxIndex[3U]) {
  } else {
    offset_1d = offset_3d + stride[3U];
    if (bpIndex[0U] == maxIndex[0U]) {
      yL_1d = table[offset_1d];
    } else {
      yL_1d = (1.0F - frac[0U]) * table[offset_1d] + table[offset_1d + 1U] *
        frac[0U];
    }

    if (bpIndex[1U] == maxIndex[1U]) {
    } else {
      offset_0d = offset_1d + stride[1U];
      if (bpIndex[0U] == maxIndex[0U]) {
        yR_1d = table[offset_0d];
      } else {
        yR_1d = (1.0F - frac[0U]) * table[offset_0d] + table[offset_0d + 1U] *
          frac[0U];
      }

      yL_1d = (1.0F - frac[1U]) * yL_1d + frac[1U] * yR_1d;
    }

    if (bpIndex[2U] == maxIndex[2U]) {
    } else {
      offset_1d += stride[2U];
      if (bpIndex[0U] == maxIndex[0U]) {
        yL_1d_0 = table[offset_1d];
      } else {
        yL_1d_0 = (1.0F - frac[0U]) * table[offset_1d] + table[offset_1d + 1U] *
          frac[0U];
      }

      if (bpIndex[1U] == maxIndex[1U]) {
      } else {
        offset_0d = offset_1d + stride[1U];
        if (bpIndex[0U] == maxIndex[0U]) {
          yR_1d = table[offset_0d];
        } else {
          yR_1d = (1.0F - frac[0U]) * table[offset_0d] + table[offset_0d + 1U] *
            frac[0U];
        }

        yL_1d_0 = (1.0F - frac[1U]) * yL_1d_0 + frac[1U] * yR_1d;
      }

      yL_1d = (1.0F - frac[2U]) * yL_1d + frac[2U] * yL_1d_0;
    }

    y = (1.0F - frac[3U]) * y + frac[3U] * yL_1d;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
