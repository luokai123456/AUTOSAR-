/*
 * File: sMultiWordShrNear.c
 *
 * Code generated for Simulink model 'swc_SetInputInterface'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 24 15:30:30 2026
 */

#include "rtwtypes.h"
#include "sMultiWordShr.h"
#include "sMultiWordShrNear.h"

void sMultiWordShrNear(const unsigned int u1[], int n1, unsigned int n2, unsigned int y[],
  int n)
{
  int nb;
  unsigned char doNearest;
  nb = (int)((n2 - 1U) >> 5);
  if (nb < n1) {
    doNearest = ((1U << ((n2 - (nb << 5)) - 1U) & u1[nb]) != 0U);
  } else {
    doNearest = (((u1[n1 - 1] & 2147483648U) != 0U ? ((uint32_T)(0xFFFFFFFFU)) : 0U) != 0U);
  }

  sMultiWordShr(u1, n1, n2, y, n);
  nb = 0;
  while (doNearest && (nb < n)) {
    y[nb]++;
    if (y[nb] != 0U) {
      doNearest = false;
    }

    nb++;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
