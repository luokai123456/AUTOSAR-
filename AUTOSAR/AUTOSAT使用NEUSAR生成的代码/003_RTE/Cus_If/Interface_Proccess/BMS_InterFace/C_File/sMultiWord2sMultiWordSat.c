/*
 * File: sMultiWord2sMultiWordSat.c
 *
 * Code generated for Simulink model 'swc_SetInputInterface'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 24 15:30:30 2026
 */

#include "rtwtypes.h"
#include "sMultiWord2sMultiWordSat.h"

void sMultiWord2sMultiWordSat(const unsigned int u1[], int n1, unsigned int y[],
  int n)
{
  int i;
  int nm1;
  unsigned int ys;
  unsigned char doSaturation = false;
  nm1 = n - 1;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? ((uint32_T)(0xFFFFFFFFU)) : 0U;
  if (n1 > n) {
    doSaturation = (((u1[n1 - 1] ^ u1[n - 1]) & 2147483648U) != 0U);
    i = n1 - 1;
    while ((!doSaturation) && (i >= n)) {
      doSaturation = (u1[i] != ys);
      i--;
    }
  }

  if (doSaturation) {
    ys = ~ys;
    for (i = 0; i < nm1; i++) {
      y[i] = ys;
    }

    y[i] = ys ^ 2147483648U;
  } else {
    nm1 = n1 < n ? n1 : n;
    for (i = 0; i < nm1; i++) {
      y[i] = u1[i];
    }

    while (i < n) {
      y[i] = ys;
      i++;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
