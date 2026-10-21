/*
 * File: rt_modf.c
 *
 * Code generated for Simulink model 'swc_BatChCtl'.
 *
 * Model version                  : 1.435
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Jul 15 09:39:00 2023
 */

#include "rtwtypes.h"
#include "rt_modf.h"
#include <math.h>
#include <float.h>
#define swc_BatChCtl_START_SEC_CODE
#include "swc_BatChCtl_MemMap.h"

float32 rt_modf(float32 u0, float32 u1)
{
  float32 q;
  float32 y;
  boolean yEq;
  y = u0;
  if (u1 == 0.0F) {
    if (u0 == 0.0F) {
      y = u1;
    }
  } else if (u0 == 0.0F) {
    y = 0.0F / u1;
  } else {
    y = (float32)fmod(u0, u1);
    yEq = (y == 0.0F);
    if ((!yEq) && (u1 > (float32)floor(u1))) {
      q = (float32)fabs(u0 / u1);
      yEq = ((float32)fabs(q - (float32)floor(q + 0.5F)) <= FLT_EPSILON * q);
    }

    if (yEq) {
      y = 0.0F;
    } else if ((u0 < 0.0F) != (u1 < 0.0F)) {
      y += u1;
    }
  }

  return y;
}

#define swc_BatChCtl_STOP_SEC_CODE
#include "swc_BatChCtl_MemMap.h"

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
