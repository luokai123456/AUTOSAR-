/*
 * File: LookUp_real32_T_real32_T.c
 *
 * Code generated for Simulink model 'swc_BatCoreFct'.
 *
 * Model version                  : 9.80
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 18 10:01:33 2024
 */

#include "LookUp_real32_T_real32_T.h"
#include "BINARYSEARCH_real32_T.h"
#include "rtwtypes.h"

/* Lookup Utility LookUp_real32_T_real32_T */
void LookUp_real32_T_real32_T(float32 *pY, const float32 *pYData, float32 u,
  const float32 *pUData, uint32 iHi)
{
  uint32 iLeft;
  uint32 iRght;
  BINARYSEARCH_real32_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    float32 lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      float32 num;
      float32 den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0F;
    }

    {
      float32 yLeftCast;
      float32 yRghtCast;
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
