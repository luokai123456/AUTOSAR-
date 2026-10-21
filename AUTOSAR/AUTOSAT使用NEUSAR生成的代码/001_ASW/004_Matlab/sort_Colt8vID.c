/*
 * File: sort_Colt8vID.c
 *
 * Code generated for Simulink model 'Diag'.
 *
 * Model version                  : 4.157
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Jul 23 20:36:39 2025
 */

#include "rtwtypes.h"
#include "sort_Colt8vID.h"
#include <string.h>
#include "merge_2pU0puQF.h"

/* Function for MATLAB Function: '<S59>/MATLAB Function1' */
void sort_Colt8vID(uint8 x[48], sint32 idx[48])
{
  sint32 iwork[48];
  sint32 bLen;
  sint32 i;
  sint32 i1;
  sint32 i2;
  sint8 idx4[4];
  uint8 xwork[48];
  uint8 x4[4];
  for (bLen = 0; bLen < 12; bLen++) {
    sint32 i3;
    sint32 i4;
    sint32 tmp;
    sint32 tmp_0;
    sint8 perm_idx_0;
    sint8 perm_idx_1;
    sint8 perm_idx_2;
    sint8 perm_idx_3;
    uint8 x4_tmp;
    uint8 x4_tmp_0;
    uint8 x4_tmp_1;
    i = bLen << 2;
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

  memset(&iwork[0], 0, 48U * sizeof(sint32));
  for (i = 0; i < 48; i++) {
    xwork[i] = 0U;
  }

  i = 12;
  bLen = 4;
  while (i > 1) {
    if (((uint32)i & 1U) != 0U) {
      i--;
      i1 = bLen * i;
      if (48 - i1 > bLen) {
        merge_2pU0puQF(idx, x, i1, bLen, 48 - (i1 + bLen), iwork, xwork);
      }
    }

    i2 = bLen << 1;
    i >>= 1;
    for (i1 = 0; i1 < i; i1++) {
      merge_2pU0puQF(idx, x, i1 * i2, bLen, bLen, iwork, xwork);
    }

    bLen = i2;
  }

  if (bLen < 48) {
    merge_2pU0puQF(idx, x, 0, bLen, 48 - bLen, iwork, xwork);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
