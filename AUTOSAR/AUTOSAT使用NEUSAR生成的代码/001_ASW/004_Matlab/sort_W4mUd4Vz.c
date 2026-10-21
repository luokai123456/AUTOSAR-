/*
 * File: sort_W4mUd4Vz.c
 *
 * Code generated for Simulink model 'vcu_arch'.
 *
 * Model version                  : 1.3319
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Fri Nov 21 10:36:00 2025
 */

#include "rtwtypes.h"
#include "merge_9zKjdvfP.h"
#include "sort_W4mUd4Vz.h"

/* Function for MATLAB Function: '<S4612>/MATLAB Function1' */
void sort_W4mUd4Vz(real32_T x[5])
{
  int32_T idx[5];
  int32_T iwork[5];
  real32_T xwork[5];
  real32_T x4[4];
  int8_T idx4[4];
  int32_T ib;
  int8_T perm[4];
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T k;
  x4[0] = 0.0F;
  idx4[0] = 0;
  x4[1] = 0.0F;
  idx4[1] = 0;
  x4[2] = 0.0F;
  idx4[2] = 0;
  x4[3] = 0.0F;
  idx4[3] = 0;
  ib = 0;
  for (k = 0; k < 5; k++) {
    idx[k] = 0;
    ib++;
    idx4[ib - 1] = (int8_T)(k + 1);
    x4[ib - 1] = x[k];
    if (ib == 4) {
      if (x4[0] <= x4[1]) {
        ib = 1;
        i2 = 2;
      } else {
        ib = 2;
        i2 = 1;
      }

      if (x4[2] <= x4[3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      if (x4[ib - 1] <= x4[i3 - 1]) {
        if (x4[i2 - 1] <= x4[i3 - 1]) {
          perm[0] = (int8_T)ib;
          perm[1] = (int8_T)i2;
          perm[2] = (int8_T)i3;
          perm[3] = (int8_T)i4;
        } else if (x4[i2 - 1] <= x4[i4 - 1]) {
          perm[0] = (int8_T)ib;
          perm[1] = (int8_T)i3;
          perm[2] = (int8_T)i2;
          perm[3] = (int8_T)i4;
        } else {
          perm[0] = (int8_T)ib;
          perm[1] = (int8_T)i3;
          perm[2] = (int8_T)i4;
          perm[3] = (int8_T)i2;
        }
      } else if (x4[ib - 1] <= x4[i4 - 1]) {
        if (x4[i2 - 1] <= x4[i4 - 1]) {
          perm[0] = (int8_T)i3;
          perm[1] = (int8_T)ib;
          perm[2] = (int8_T)i2;
          perm[3] = (int8_T)i4;
        } else {
          perm[0] = (int8_T)i3;
          perm[1] = (int8_T)ib;
          perm[2] = (int8_T)i4;
          perm[3] = (int8_T)i2;
        }
      } else {
        perm[0] = (int8_T)i3;
        perm[1] = (int8_T)i4;
        perm[2] = (int8_T)ib;
        perm[3] = (int8_T)i2;
      }

      i2 = perm[0] - 1;
      idx[k - 3] = idx4[i2];
      i3 = perm[1] - 1;
      idx[k - 2] = idx4[i3];
      ib = perm[2] - 1;
      idx[k - 1] = idx4[ib];
      i4 = perm[3] - 1;
      idx[k] = idx4[i4];
      x[k - 3] = x4[i2];
      x[k - 2] = x4[i3];
      x[k - 1] = x4[ib];
      x[k] = x4[i4];
      ib = 0;
    }
  }

  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib) {
     case 1:
      perm[0] = 1;
      break;

     case 2:
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
      break;

     default:
      if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      break;
    }

    for (k = 5; k - 4 <= ib; k++) {
      i2 = perm[k - 5] - 1;
      i3 = k - ib;
      idx[i3] = idx4[i2];
      x[i3] = x4[i2];
    }
  }

  for (k = 0; k < 5; k++) {
    xwork[k] = 0.0F;
    iwork[k] = 0;
  }

  merge_9zKjdvfP(idx, x, 0, 4, 1, iwork, xwork);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
