/*
 * File: LookUp_real32_T_real32_T_ZERO.c
 *
 * Code generated for Simulink model 'vcu_arch'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Apr 25 22:11:57 2021
 */

#include "rtwtypes.h"
#include "BINARYSEARCH_real32_T.h"
#include "LookUp_real32_T_real32_T_ZERO.h"

/* Lookup Utility LookUp_real32_T_real32_T_ZERO */
void LookUp_real32_T_real32_T_ZERO(real32_T *pY, const real32_T *pYData,
  real32_T u, const real32_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real32_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real32_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real32_T num;
      real32_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0F;
    }

    {
      real32_T yLeftCast;
      real32_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
