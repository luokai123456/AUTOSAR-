/*
 * File: sort_GvHzBEkR.c
 *
 * Code generated for Simulink model 'Diag'.
 *
 * Model version                  : 4.167
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Aug 11 13:07:45 2025
 */

#include "rtwtypes.h"
#include "sort_GvHzBEkR.h"
#include <string.h>
#include "merge_ai4gPE4J.h"

/* Function for MATLAB Function: '<S56>/MATLAB Function1' */
void sort_GvHzBEkR(uint8 x[31], sint32 idx[31])
{
  sint32 iwork[31];
  sint32 i;
  sint32 i1;
  sint32 i2;
  sint32 nPairs;
  sint8 idx4[4];
  sint8 perm_idx_0;
  sint8 perm_idx_1;
  sint8 perm_idx_2;
  uint8 xwork[31];
  uint8 x4[4];
  memset(&idx[0], 0, 31U * sizeof(sint32));
  x4[3] = 0U;
  idx4[3] = 0;
  for (nPairs = 0; nPairs < 7; nPairs++) {
    sint32 i3;
    sint32 i4;
    sint32 tmp;
    sint32 tmp_0;
    sint8 perm_idx_3;
    uint8 x4_tmp;
    uint8 x4_tmp_0;
    uint8 x4_tmp_1;
    i = nPairs << 2;
    idx4[0] = (sint8)(i + 1);
    idx4[1] = (sint8)(i + 2);
    idx4[2] = (sint8)(i + 3);
    idx4[3] = (sint8)(i + 4);
    x4[0] = x[i];
    x4_tmp = x[i + 1];
    x4[1] = x4_tmp;
    x4_tmp_0 = x[i + 2];
    x4[2] = x4_tmp_0;
    x4_tmp_1 = x[i + 3];
    x4[3] = x4_tmp_1;
    if (x[i] >= x4_tmp) {
      i1 = 1;
      i2 = 2;
    } else {
      i1 = 2;
      i2 = 1;
    }

    if (x4_tmp_0 >= x4_tmp_1) {
      i3 = 3;
      i4 = 4;
    } else {
      i3 = 4;
      i4 = 3;
    }

    tmp = x4[i1 - 1];
    tmp_0 = x4[i3 - 1];
    if (tmp >= tmp_0) {
      tmp = x4[i2 - 1];
      if (tmp >= tmp_0) {
        perm_idx_0 = (sint8)i1;
        perm_idx_1 = (sint8)i2;
        perm_idx_2 = (sint8)i3;
        perm_idx_3 = (sint8)i4;
      } else if (tmp >= x4[i4 - 1]) {
        perm_idx_0 = (sint8)i1;
        perm_idx_1 = (sint8)i3;
        perm_idx_2 = (sint8)i2;
        perm_idx_3 = (sint8)i4;
      } else {
        perm_idx_0 = (sint8)i1;
        perm_idx_1 = (sint8)i3;
        perm_idx_2 = (sint8)i4;
        perm_idx_3 = (sint8)i2;
      }
    } else {
      tmp_0 = x4[i4 - 1];
      if (tmp >= tmp_0) {
        if (x4[i2 - 1] >= tmp_0) {
          perm_idx_0 = (sint8)i3;
          perm_idx_1 = (sint8)i1;
          perm_idx_2 = (sint8)i2;
          perm_idx_3 = (sint8)i4;
        } else {
          perm_idx_0 = (sint8)i3;
          perm_idx_1 = (sint8)i1;
          perm_idx_2 = (sint8)i4;
          perm_idx_3 = (sint8)i2;
        }
      } else {
        perm_idx_0 = (sint8)i3;
        perm_idx_1 = (sint8)i4;
        perm_idx_2 = (sint8)i1;
        perm_idx_3 = (sint8)i2;
      }
    }

    idx[i] = idx4[perm_idx_0 - 1];
    idx[i + 1] = idx4[perm_idx_1 - 1];
    idx[i + 2] = idx4[perm_idx_2 - 1];
    idx[i + 3] = idx4[perm_idx_3 - 1];
    x[i] = x4[perm_idx_0 - 1];
    x[i + 1] = x4[perm_idx_1 - 1];
    x[i + 2] = x4[perm_idx_2 - 1];
    x[i + 3] = x4[perm_idx_3 - 1];
  }

  idx4[0] = 29;
  x4[0] = x[28];
  idx4[1] = 30;
  x4[1] = x[29];
  idx4[2] = 31;
  x4[2] = x[30];
  if (x[28] >= x[29]) {
    if (x[29] >= x[30]) {
      perm_idx_0 = 1;
      perm_idx_1 = 2;
      perm_idx_2 = 3;
    } else if (x[28] >= x[30]) {
      perm_idx_0 = 1;
      perm_idx_1 = 3;
      perm_idx_2 = 2;
    } else {
      perm_idx_0 = 3;
      perm_idx_1 = 1;
      perm_idx_2 = 2;
    }
  } else if (x[28] >= x[30]) {
    perm_idx_0 = 2;
    perm_idx_1 = 1;
    perm_idx_2 = 3;
  } else if (x[29] >= x[30]) {
    perm_idx_0 = 2;
    perm_idx_1 = 3;
    perm_idx_2 = 1;
  } else {
    perm_idx_0 = 3;
    perm_idx_1 = 2;
    perm_idx_2 = 1;
  }

  idx[28] = idx4[perm_idx_0 - 1];
  x[28] = x4[perm_idx_0 - 1];
  idx[29] = idx4[perm_idx_1 - 1];
  x[29] = x4[perm_idx_1 - 1];
  idx[30] = idx4[perm_idx_2 - 1];
  x[30] = x4[perm_idx_2 - 1];
  memset(&iwork[0], 0, 31U * sizeof(sint32));
  for (i = 0; i < 31; i++) {
    xwork[i] = 0U;
  }

  nPairs = 7;
  i = 4;
  while (nPairs > 1) {
    if (((uint32)nPairs & 1U) != 0U) {
      nPairs--;
      i1 = i * nPairs;
      if (31 - i1 > i) {
        merge_ai4gPE4J(idx, x, i1, i, 31 - (i1 + i), iwork, xwork);
      }
    }

    i2 = i << 1;
    nPairs >>= 1;
    for (i1 = 0; i1 < nPairs; i1++) {
      merge_ai4gPE4J(idx, x, i1 * i2, i, i, iwork, xwork);
    }

    i = i2;
  }

  if (i < 31) {
    merge_ai4gPE4J(idx, x, 0, i, 31 - i, iwork, xwork);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
