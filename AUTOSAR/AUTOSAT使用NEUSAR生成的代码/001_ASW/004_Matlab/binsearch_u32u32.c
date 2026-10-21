/*
 * File: binsearch_u32u32.c
 *
 * Code generated for Simulink model 'swc_BatCoreFct'.
 *
 * Model version                  : 9.80
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 18 10:01:33 2024
 */

#include "binsearch_u32u32.h"
#include "rtwtypes.h"

uint32 binsearch_u32u32(uint32 u, const uint32 bp[], uint32 startIndex,
  uint32 maxIndex)
{
  uint32 bpIdx;
  uint32 bpIndex;
  uint32 iRght;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
