/*
 * File: sMultiWord2sLongSat.c
 *
 * Code generated for Simulink model 'swc_SetInputInterface'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 24 15:30:30 2026
 */

#include "rtwtypes.h"
#include "sMultiWord2sMultiWordSat.h"
#include "sMultiWord2sLongSat.h"

int sMultiWord2sLongSat(const unsigned int u1[], int n1)
{
  unsigned int y;
  sMultiWord2sMultiWordSat(u1, n1, &y, 1);
  return (int)y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
