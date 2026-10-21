/*
 * File: sMultiWordShr.c
 *
 * Code generated for Simulink model 'swc_SetInputInterface'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 24 15:30:30 2026
 */

#include "rtwtypes.h"
#include "sMultiWordShr.h"

void sMultiWordShr(const unsigned int u1[], int n1, unsigned int n2, unsigned int y[],
                   int n)
{
  int i;
  int i1;
  int nb;
  unsigned int ys;
  nb = (int)(n2 >> 5);
  i = 0;
  ys = (u1[n1 - 1] & 2147483648U) != 0U ? ((unsigned int)(0xFFFFFFFFU)) : 0U;
  if (nb < n1) {
    int nc;
    unsigned int nr;
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((unsigned int)nb << 5);
    if (nr > 0U) {
      unsigned int u1i;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        unsigned int yi;
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << (32U - nr) | yi;
        i++;
      }

      y[i] = (nc < n1 ? u1[nc] : ys) << (32U - nr) | u1i >> nr;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
