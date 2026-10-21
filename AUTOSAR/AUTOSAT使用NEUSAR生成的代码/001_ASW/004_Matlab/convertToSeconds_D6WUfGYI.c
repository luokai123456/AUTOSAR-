/*
 * File: convertToSeconds_D6WUfGYI.c
 *
 * Code generated for Simulink model 'swc_BcuStTranCtl'.
 *
 * Model version                  : 9.215
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jul  9 10:50:59 2026
 */

#include "rtwtypes.h"
#include "convertToSeconds_D6WUfGYI.h"
#include <string.h>

/* Function for MATLAB Function: '<S73>/MATLAB Function' */
uint32 convertToSeconds_D6WUfGYI(uint16 year, uint8 month, uint8 day,
  uint8 hour, uint8 minute, uint8 second)
{
  sint32 a;
  sint32 b;
  uint32 qY;
  uint32 totalSeconds;
  uint32 yearSeconds;
  uint16 c;
  uint16 i;
  uint8 daysInMonth[12];
  uint8 x[12];
  static const uint8 d[12] = { 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U,
    31U, 30U, 31U };

  for (b = 0; b < 12; b++) {
    daysInMonth[b] = d[b];
    x[b] = 0U;
  }

  if (((uint16)(year - (uint32)((sint32)((uint32)year >> 2) << 2)) == 0) &&
      (((uint16)(year - (uint32)((sint32)(year / 100U) * 100)) != 0) ||
       ((uint16)(year - (uint32)((sint32)(year / 400U) * 400)) == 0))) {
    daysInMonth[1] = 29U;
  }

  qY = month - 1U;
  if (month - 1U > month) {
    qY = 0U;
  }

  if ((sint32)qY - 1 >= 0) {
    memcpy(&x[0], &daysInMonth[0], qY * sizeof(uint8));
  }

  yearSeconds = 0U;
  qY = year - 1U;
  if (year - 1U > year) {
    qY = 0U;
  }

  c = (uint16)qY;
  for (i = 2000; i <= c; i++) {
    if (((uint16)(i - (uint32)((sint32)((uint32)i >> 2) << 2)) == 0) &&
        (((uint16)(i - (uint32)((sint32)(i / 100U) * 100)) != 0) ||
         ((uint16)(i - (uint32)((sint32)(i / 400U) * 400)) == 0))) {
      qY = yearSeconds + /*MW:OvSatOk*/ 31622400U;
      if (yearSeconds + 31622400U < yearSeconds) {
        qY = MAX_uint32_T;
      }

      yearSeconds = qY;
    } else {
      qY = yearSeconds + /*MW:OvSatOk*/ 31536000U;
      if (yearSeconds + 31536000U < yearSeconds) {
        qY = MAX_uint32_T;
      }

      yearSeconds = qY;
    }
  }

  b = x[0];
  for (a = 0; a < 11; a++) {
    b += x[a + 1];
  }

  qY = (uint32)(b * 24 * 60 * 60) + /*MW:OvSatOk*/ yearSeconds;
  if (qY < yearSeconds) {
    qY = MAX_uint32_T;
  }

  yearSeconds = day - 1U;
  if (day - 1U > day) {
    yearSeconds = 0U;
  }

  yearSeconds = yearSeconds * 24U * 60U * 60U + /*MW:OvSatOk*/ qY;
  if (yearSeconds < qY) {
    yearSeconds = MAX_uint32_T;
  }

  totalSeconds = ((hour * 60U * 60U + yearSeconds) + minute * 60U) + second;
  if (totalSeconds < yearSeconds) {
    totalSeconds = MAX_uint32_T;
  }

  return totalSeconds;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
