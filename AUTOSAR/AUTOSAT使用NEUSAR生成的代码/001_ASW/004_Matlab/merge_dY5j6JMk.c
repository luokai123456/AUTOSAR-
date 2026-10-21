/*
 * File: merge_dY5j6JMk.c
 *
 * Code generated for Simulink model 'vcu_arch'.
 *
 * Model version                  : 11.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr 27 15:26:59 2026
 */

#include "rtwtypes.h"
#include "merge_dY5j6JMk.h"

/* Function for MATLAB Function: '<S3731>/MATLAB Function1' */
void merge_dY5j6JMk(sint32 idx[5], float32 x[5], sint32 offset, sint32 np,
                    sint32 nq, sint32 iwork[5], float32 xwork[5])
{
  sint32 q;
  if ((np != 0) && (nq != 0)) {
    sint32 iout;
    sint32 n;
    sint32 qend;
    qend = np + nq;
    for (q = 0; q < qend; q++) {
      iwork[q] = idx[offset + q];
      xwork[q] = x[offset + q];
    }

    n = 0;
    q = np;
    iout = offset - 1;
    sint32 exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[n] <= xwork[q]) {
        idx[iout] = iwork[n];
        x[iout] = xwork[n];
        if (n + 1 < np) {
          n++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < qend) {
          q++;
        } else {
          qend = iout - n;
          for (q = n + 1; q <= np; q++) {
            iout = qend + q;
            idx[iout] = iwork[q - 1];
            x[iout] = xwork[q - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
