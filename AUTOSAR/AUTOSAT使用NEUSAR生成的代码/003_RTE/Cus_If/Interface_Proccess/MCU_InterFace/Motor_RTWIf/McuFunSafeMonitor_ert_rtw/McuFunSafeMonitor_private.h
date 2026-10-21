/*
 * File: McuFunSafeMonitor_private.h
 *
 * Code generated for Simulink model 'McuFunSafeMonitor'.
 *
 * Model version                  : 1.993
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Sep  5 08:33:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_McuFunSafeMonitor_private_h_
#define RTW_HEADER_McuFunSafeMonitor_private_h_
#include "rtwtypes.h"
#include "McuFunSafeMonitor_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Exported data declaration */

/* Data with Imported storage */
extern uint16_T IPU_IsgTqActIsgTqAct;  /* '<Root>/IPU_IsgTqActIsgTqAct' */
extern real32_T SGPP_BSW_f32_iSmpPhaU_A;/* '<Root>/SGPP_BSW_f32_iSmpPhaU_A' */
extern real32_T SGPP_BSW_f32_iSmpPhaW_A;/* '<Root>/SGPP_BSW_f32_iSmpPhaW_A' */
extern real32_T SGPP_BSW_f32_nRotateSpd_rpm;
                                      /* '<Root>/SGPP_BSW_f32_nRotateSpd_rpm' */
extern real32_T SGPP_BSW_f32_uDcHV_V;  /* '<Root>/SGPP_BSW_f32_uDcHV_V' */
extern real32_T SGPP_FOC_f32_Uduty_Null;/* '<Root>/SGPP_FOC_f32_Uduty_Null' */
extern real32_T SGPP_FOC_f32_Vduty_Null;/* '<Root>/SGPP_FOC_f32_Vduty_Null' */
extern real32_T SGPP_FOC_f32_Wduty_Null;/* '<Root>/SGPP_FOC_f32_Wduty_Null' */
extern real32_T SGPP_PhaseADuty;       /* '<Root>/SGPP_PhaseADuty' */
extern real32_T SGPP_PhaseBDuty;       /* '<Root>/SGPP_PhaseBDuty' */
extern real32_T SGPP_PhaseCDuty;       /* '<Root>/SGPP_PhaseCDuty' */
extern real32_T SGRD_CosEnvelope;      /* '<Root>/SGRD_CosEnvelope' */
extern real32_T SGRD_SinEnvelope;      /* '<Root>/SGRD_SinEnvelope' */
extern real32_T SGSA_DcLinkVoltMeasAD; /* '<Root>/SGSA_DcLinkVoltMeasAD' */
extern real32_T SGSA_MotorTemp1AD;     /* '<Root>/SGSA_MotorTemp1AD' */
extern real32_T SGSA_PhaseACurrentAD;  /* '<Root>/SGSA_PhaseACurrentAD' */
extern real32_T SGSA_PhaseCCurrentAD;  /* '<Root>/SGSA_PhaseCCurrentAD' */
extern real32_T SGSA_PwrChipVolt;      /* '<Root>/SGSA_PwrChipVolt' */

#endif                             /* RTW_HEADER_McuFunSafeMonitor_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
