/*
 * File: sort_3QIh1HvN.c
 *
 * Code generated for Simulink model 'vcu_arch'.
 *
 * Model version                  : 11.1
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Apr 27 15:26:59 2026
 */

#include "rtwtypes.h"
#include "sort_3QIh1HvN.h"
#include "merge_dY5j6JMk.h"

/* Function for MATLAB Function: '<S3731>/MATLAB Function1' */
void sort_3QIh1HvN(float32 x[5])
{
  sint32 idx[5];
  sint32 iwork[5];
  sint32 b_k;
  sint32 i2;
  sint32 ib;
  float32 xwork[5];
  float32 x4[4];
  sint8 idx4[4];
  sint8 perm[4];
  x4[0] = 0.0F;
  idx4[0] = 0;
  x4[1] = 0.0F;
  idx4[1] = 0;
  x4[2] = 0.0F;
  idx4[2] = 0;
  x4[3] = 0.0F;
  idx4[3] = 0;
  ib = -1;
  for (b_k = 0; b_k < 5; b_k++) {
    idx[b_k] = 0;
    ib++;
    idx4[ib] = (sint8)(b_k + 1);
    x4[ib] = x[b_k];
    if (ib + 1 == 4) {
      sint32 i3;
      sint32 i4;
      float32 tmp;
      float32 tmp_0;
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

      tmp = x4[ib - 1];
      tmp_0 = x4[i3 - 1];
      if (tmp <= tmp_0) {
        tmp = x4[i2 - 1];
        if (tmp <= tmp_0) {
          perm[0] = (sint8)ib;
          perm[1] = (sint8)i2;
          perm[2] = (sint8)i3;
          perm[3] = (sint8)i4;
        } else if (tmp <= x4[i4 - 1]) {
          perm[0] = (sint8)ib;
          perm[1] = (sint8)i3;
          perm[2] = (sint8)i2;
          perm[3] = (sint8)i4;
        } else {
          perm[0] = (sint8)ib;
          perm[1] = (sint8)i3;
          perm[2] = (sint8)i4;
          perm[3] = (sint8)i2;
        }
      } else {
        tmp_0 = x4[i4 - 1];
        if (tmp <= tmp_0) {
          if (x4[i2 - 1] <= tmp_0) {
            perm[0] = (sint8)i3;
            perm[1] = (sint8)ib;
            perm[2] = (sint8)i2;
            perm[3] = (sint8)i4;
          } else {
            perm[0] = (sint8)i3;
            perm[1] = (sint8)ib;
            perm[2] = (sint8)i4;
            perm[3] = (sint8)i2;
          }
        } else {
          perm[0] = (sint8)i3;
          perm[1] = (sint8)i4;
          perm[2] = (sint8)ib;
          perm[3] = (sint8)i2;
        }
      }

      idx[b_k - 3] = idx4[perm[0] - 1];
      idx[b_k - 2] = idx4[perm[1] - 1];
      idx[b_k - 1] = idx4[perm[2] - 1];
      idx[b_k] = idx4[perm[3] - 1];
      x[b_k - 3] = x4[perm[0] - 1];
      x[b_k - 2] = x4[perm[1] - 1];
      x[b_k - 1] = x4[perm[2] - 1];
      x[b_k] = x4[perm[3] - 1];
      ib = -1;
    }
  }

  if (ib + 1 > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    switch (ib + 1) {
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

    for (b_k = 0; b_k <= ib; b_k++) {
      sint8 perm_0;
      perm_0 = perm[b_k];
      i2 = (b_k - ib) + 4;
      idx[i2] = idx4[perm_0 - 1];
      x[i2] = x4[perm_0 - 1];
    }
  }

  for (b_k = 0; b_k < 5; b_k++) {
    iwork[b_k] = 0;
    xwork[b_k] = 0.0F;
  }

  merge_dY5j6JMk(idx, x, 0, 4, 1, iwork, xwork);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
