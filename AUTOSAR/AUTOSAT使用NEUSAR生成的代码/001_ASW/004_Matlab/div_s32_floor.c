/*
 * File: div_s32_floor.c
 *
 * Code generated for Simulink model 'swc_DiagcEveHndlg'.
 *
 * Model version                  : 9.175
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct 30 12:05:45 2024
 */

#include "div_s32_floor.h"
#include "rtwtypes.h"

sint32 div_s32_floor(sint32 numerator, sint32 denominator)
{
  sint32 quotient;
  uint32 absDenominator;
  uint32 absNumerator;
  uint32 tempAbsQuotient;
  boolean quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32)numerator + 1U : (uint32)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32)denominator + 1U : (uint32)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(sint32)tempAbsQuotient : (sint32)
      tempAbsQuotient;
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
