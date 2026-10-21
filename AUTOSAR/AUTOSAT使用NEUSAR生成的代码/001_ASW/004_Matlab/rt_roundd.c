/*
 * File: rt_roundd.c
 *
 * Code generated for Simulink model 'swc_BatThermHndlgMngt'.
 *
 * Model version                  : 9.3
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec 12 11:20:50 2023
 */

#include "rtwtypes.h"
#include "rt_roundd.h"
#include <math.h>

float64 rt_roundd(float64 u)
{
  float64 y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = 0.0;
    } else {
      y = ceil(u - 0.5);
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
