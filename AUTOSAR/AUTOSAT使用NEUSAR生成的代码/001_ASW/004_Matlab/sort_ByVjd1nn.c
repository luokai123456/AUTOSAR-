/*
 * File: sort_ByVjd1nn.c
 *
 * Code generated for Simulink model 'Diag'.
 *
 * Model version                  : 4.150
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Apr 29 21:44:37 2025
 */

#include "rtwtypes.h"
#include "sort_ByVjd1nn.h"
#include <string.h>
#include "merge_xRqbf8II.h"

/* Function for MATLAB Function: '<S50>/MATLAB Function1' */
void sort_ByVjd1nn(uint8 x[47], sint32 idx[47])
{
  sint32 iwork[47];
  sint32 i;
  sint32 i1;
  sint32 i2;
  sint32 nPairs;
  sint8 idx4[4];
  sint8 perm_idx_0;
  sint8 perm_idx_1;
  sint8 perm_idx_2;
  uint8 xwork[47];
  uint8 x4[4];
  memset(&idx[0], 0, 47U * sizeof(sint32));
  x4[3] = 0U;
  idx4[3] = 0;
  for (nPairs = 0; nPairs < 11; nPairs++) {
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

  idx4[0] = 45;
  x4[0] = x[44];
  idx4[1] = 46;
  x4[1] = x[45];
  idx4[2] = 47;
  x4[2] = x[46];
  if (x[44] >= x[45]) {
    if (x[45] >= x[46]) {
      perm_idx_0 = 1;
      perm_idx_1 = 2;
      perm_idx_2 = 3;
    } else if (x[44] >= x[46]) {
      perm_idx_0 = 1;
      perm_idx_1 = 3;
      perm_idx_2 = 2;
    } else {
      perm_idx_0 = 3;
      perm_idx_1 = 1;
      perm_idx_2 = 2;
    }
  } else if (x[44] >= x[46]) {
    perm_idx_0 = 2;
    perm_idx_1 = 1;
    perm_idx_2 = 3;
  } else if (x[45] >= x[46]) {
    perm_idx_0 = 2;
    perm_idx_1 = 3;
    perm_idx_2 = 1;
  } else {
    perm_idx_0 = 3;
    perm_idx_1 = 2;
    perm_idx_2 = 1;
  }

  idx[44] = idx4[perm_idx_0 - 1];
  x[44] = x4[perm_idx_0 - 1];
  idx[45] = idx4[perm_idx_1 - 1];
  x[45] = x4[perm_idx_1 - 1];
  idx[46] = idx4[perm_idx_2 - 1];
  x[46] = x4[perm_idx_2 - 1];
  memset(&iwork[0], 0, 47U * sizeof(sint32));
  for (i = 0; i < 47; i++) {
    xwork[i] = 0U;
  }

  nPairs = 11;
  i = 4;
  while (nPairs > 1) {
    if (((uint32)nPairs & 1U) != 0U) {
      nPairs--;
      i1 = i * nPairs;
      if (47 - i1 > i) {
        merge_xRqbf8II(idx, x, i1, i, 47 - (i1 + i), iwork, xwork);
      }
    }

    i2 = i << 1;
    nPairs >>= 1;
    for (i1 = 0; i1 < nPairs; i1++) {
      merge_xRqbf8II(idx, x, i1 * i2, i, i, iwork, xwork);
    }

    i = i2;
  }

  if (i < 47) {
    merge_xRqbf8II(idx, x, 0, i, 47 - i, iwork, xwork);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
