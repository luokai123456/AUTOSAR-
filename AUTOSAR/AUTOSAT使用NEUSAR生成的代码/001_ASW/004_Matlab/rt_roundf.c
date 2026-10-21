/*
 * File: rt_roundf.c
 *
 * Code generated for Simulink model 'swc_COL'.
 *
 * Model version                  : 9.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Sep 26 10:11:35 2023
 */

#include "rtwtypes.h"
#include "rt_roundf.h"
#include <math.h>

float32 rt_roundf(float32 u)
{
  float32 y;
  if ((float32)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (float32)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = 0.0F;
    } else {
      y = (float32)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
