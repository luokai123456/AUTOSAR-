/*
 * File: convertToSeconds_WME31nm3.c
 *
 * Code generated for Simulink model 'swc_BcuStTranCtl'.
 *
 * Model version                  : 1.149
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 16:58:41 2023
 */

#include "rtwtypes.h"
#include "convertToSeconds_WME31nm3.h"
#include <string.h>
#define swc_BcuStTranCtl_START_SEC_CODE
#include "swc_BcuStTranCtl_MemMap.h"

/* Function for MATLAB Function: '<S58>/MATLAB Function' */
uint8 convertToSeconds_WME31nm3(uint16 year, uint8 month, uint8 day,
  uint8 hour, uint8 minute, uint8 second)
{
  float64 yearSeconds;
  sint32 a;
  sint32 b;
  uint32 qY;
  uint16 c;
  uint16 i;
  sint8 daysInMonth[12];
  sint8 x[12];
  uint8 tmp;
  static const sint8 d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  for (a = 0; a < 12; a++) {
    daysInMonth[a] = d[a];
    x[a] = 0;
  }

  if (((uint16)(year - (uint32)((sint32)((uint32)year >> 2) << 2)) == 0) &&
      (((uint16)(year - (uint32)((sint32)(year / 100U) * 100)) != 0) ||
       ((uint16)(year - (uint32)((sint32)(year / 400U) * 400)) == 0))) {
    daysInMonth[1] = 29;
  }

  qY = month - 1U;
  if (month - 1U > month) {
    qY = 0U;
  }

  if ((sint32)qY - 1 >= 0) {
    memcpy(&x[0], &daysInMonth[0], qY * sizeof(sint8));
  }

  yearSeconds = 0.0;
  qY = year - 1U;
  if (year - 1U > year) {
    qY = 0U;
  }

  c = (uint16)qY;
  for (i = 2020; i <= c; i++) {
    if (((uint16)(i - (uint32)((sint32)((uint32)i >> 2) << 2)) == 0) &&
        (((uint16)(i - (uint32)((sint32)(i / 100U) * 100)) != 0) ||
         ((uint16)(i - (uint32)((sint32)(i / 400U) * 400)) == 0))) {
      yearSeconds += 3.16224E+7;
    } else {
      yearSeconds += 3.1536E+7;
    }
  }

  b = x[0];
  for (a = 0; a < 11; a++) {
    b += x[a + 1];
  }

  qY = day - 1U;
  if (day - 1U > day) {
    qY = 0U;
  }

  a = (sint32)(qY * 24U);
  if ((uint32)a > 255U) {
    a = 255;
  }

  a = (sint32)((uint32)a * 60U);
  if ((uint32)a > 255U) {
    a = 255;
  }

  a = (sint32)((uint32)a * 60U);
  if ((uint32)a > 255U) {
    a = 255;
  }

  yearSeconds = ((float64)b * 24.0 * 60.0 * 60.0 + yearSeconds) + (float64)a;
  a = (sint32)(hour * 60U);
  if ((uint32)a > 255U) {
    a = 255;
  }

  a = (sint32)((uint32)a * 60U);
  if ((uint32)a > 255U) {
    a = 255;
  }

  b = (sint32)(minute * 60U);
  if ((uint32)b > 255U) {
    b = 255;
  }

  a = (sint32)((uint32)a + (uint32)b);
  if ((uint32)a > 255U) {
    a = 255;
  }

  a = (sint32)((uint32)a + second);
  if ((uint32)a > 255U) {
    a = 255;
  }

  if (yearSeconds < 256.0) {
    tmp = (uint8)yearSeconds;
  } else {
    tmp = MAX_uint8_T;
  }

  a = (sint32)(tmp + (uint32)a);
  if ((uint32)a > 255U) {
    a = 255;
  }

  return (uint8)a;
}

#define swc_BcuStTranCtl_STOP_SEC_CODE
#include "swc_BcuStTranCtl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
