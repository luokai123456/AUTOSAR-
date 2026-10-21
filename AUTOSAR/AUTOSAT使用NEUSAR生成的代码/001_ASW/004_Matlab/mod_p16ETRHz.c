/*
 * File: mod_p16ETRHz.c
 *
 * Code generated for Simulink model 'vcu_arch'.
 *
 * Model version                  : 1.3184
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Sep 15 09:47:24 2025
 */

#include "rtwtypes.h"
#include <math.h>
#include "mod_p16ETRHz.h"

/* Function for MATLAB Function: '<S1754>/MATLAB Function' */
real_T mod_p16ETRHz(real_T x)
{
  real_T r;
  if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 7.0);
    if (r == 0.0) {
      r = 0.0;
    } else {
      if (x < 0.0) {
        r += 7.0;
      }
    }
  }

  return r;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
