/*
 * File: merge_9zKjdvfP.c
 *
 * Code generated for Simulink model 'vcu_arch'.
 *
 * Model version                  : 1.3319
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Nov 21 10:36:00 2025
 */

#include "rtwtypes.h"
#include "merge_9zKjdvfP.h"

/* Function for MATLAB Function: '<S4612>/MATLAB Function1' */
void merge_9zKjdvfP(int32_T idx[5], real32_T x[5], int32_T offset, int32_T np,
                    int32_T nq, int32_T iwork[5], real32_T xwork[5])
{
  int32_T n;
  int32_T q;
  int32_T iout;
  int32_T n_tmp;
  int32_T exitg1;
  if (!((np == 0) || (nq == 0))) {
    n_tmp = np + nq;
    for (q = 0; q + 1 <= n_tmp; q++) {
      iout = offset + q;
      iwork[q] = idx[iout];
      xwork[q] = x[iout];
    }

    n = 0;
    q = np;
    iout = offset - 1;
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
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - n;
          while (n + 1 <= np) {
            iout = (q + n) + 1;
            idx[iout] = iwork[n];
            x[iout] = xwork[n];
            n++;
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
