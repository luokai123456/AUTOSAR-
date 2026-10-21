/*
 * File: intrp3d_fu8fla.c
 *
 * Code generated for Simulink model 'CtlTorqueLoopController'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:39:37 2026
 */

#include "intrp3d_fu8fla.h"
#include "rtwtypes.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

real32_T intrp3d_fu8fla(const uint8_T bpIndex[], const real32_T frac[], const
  real32_T table[], const uint32_T stride[], const uint32_T maxIndex[])
{
  real32_T y;
  real32_T yL_0d0;
  real32_T yL_1d;
  uint32_T offset_0d;
  uint32_T offset_2d;

  /* Column-major Interpolation 3-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  offset_2d = (bpIndex[2U] * stride[2U] + bpIndex[1U] * stride[1U]) + bpIndex[0U];
  if (bpIndex[0U] == maxIndex[0U]) {
    y = table[offset_2d];
  } else {
    yL_0d0 = table[offset_2d];
    y = (table[offset_2d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
  }

  if (bpIndex[1U] == maxIndex[1U]) {
  } else {
    offset_0d = offset_2d + stride[1U];
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
    offset_2d += stride[2U];
    if (bpIndex[0U] == maxIndex[0U]) {
      yL_1d = table[offset_2d];
    } else {
      yL_0d0 = table[offset_2d];
      yL_1d = (table[offset_2d + 1U] - yL_0d0) * frac[0U] + yL_0d0;
    }

    if (bpIndex[1U] == maxIndex[1U]) {
    } else {
      offset_0d = offset_2d + stride[1U];
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

  return y;
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
