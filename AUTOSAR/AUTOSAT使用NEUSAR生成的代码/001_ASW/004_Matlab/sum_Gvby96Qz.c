/*
 * File: sum_Gvby96Qz.c
 *
 * Code generated for Simulink model 'vcu_arch'.
 *
 * Model version                  : 1.3319
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Nov 21 10:36:00 2025
 */

#include "rtwtypes.h"
#include "sum_Gvby96Qz.h"

/* Function for MATLAB Function: '<S4600>/MATLAB Function' */
real32_T sum_Gvby96Qz(const real32_T x[10])
{
  real32_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 9; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
