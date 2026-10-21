/*
 * File: merge_xRqbf8II.c
 *
 * Code generated for Simulink model 'Diag'.
 *
 * Model version                  : 4.150
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Apr 29 21:44:37 2025
 */

#include "rtwtypes.h"
#include "merge_xRqbf8II.h"

/* Function for MATLAB Function: '<S50>/MATLAB Function1' */
void merge_xRqbf8II(sint32 idx[47], uint8 x[47], sint32 offset, sint32 np,
                    sint32 nq, sint32 iwork[47], uint8 xwork[47])
{
  sint32 q;
  if ((np != 0) && (nq != 0)) {
    sint32 iout;
    sint32 offset1;
    sint32 p;
    offset1 = np + nq;
    for (q = 0; q < offset1; q++) {
      iout = offset + q;
      iwork[q] = idx[iout];
      xwork[q] = x[iout];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    sint32 exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          for (q = p + 1; q <= np; q++) {
            iout = offset1 + q;
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
