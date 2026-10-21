/*
 * File: CtlTorqueLoopController_private.h
 *
 * Code generated for Simulink model 'CtlTorqueLoopController'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:39:37 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CtlTorqueLoopController_private_h_
#define RTW_HEADER_CtlTorqueLoopController_private_h_
#include "rtwtypes.h"
#include "CtlTorqueLoopController_types.h"

extern const uint32_T rtCP_pooled_qeoiEt90FOdv[3];
extern const uint32_T rtCP_pooled_h2JSIQERFvV7[3];

#define rtCP_InterpolationUsingPrelookup_dimSize rtCP_pooled_qeoiEt90FOdv/* Computed Parameter: rtCP_InterpolationUsingPrelookup_dimSize
                                                                      * Referenced by: '<S19>/Interpolation Using Prelookup'
                                                                      */
#define rtCP_InterpolationUsingPrelookup_maxIndex rtCP_pooled_h2JSIQERFvV7/* Computed Parameter: rtCP_InterpolationUsingPrelookup_maxIndex
                                                                      * Referenced by: '<S19>/Interpolation Using Prelookup'
                                                                      */
#define rtCP_InterpolationUsingPrelookup1_dimSize rtCP_pooled_qeoiEt90FOdv/* Computed Parameter: rtCP_InterpolationUsingPrelookup1_dimSize
                                                                      * Referenced by: '<S19>/Interpolation Using Prelookup1'
                                                                      */
#define rtCP_InterpolationUsingPrelookup1_maxIndex rtCP_pooled_h2JSIQERFvV7/* Computed Parameter: rtCP_InterpolationUsingPrelookup1_maxIndex
                                                                      * Referenced by: '<S19>/Interpolation Using Prelookup1'
                                                                      */

/* Exported data declaration */

/* Data with Imported storage */
extern real32_T CTCR_VoltVectorMagFiltered;/* '<Root>/CTCR_VoltVectorMagFiltered' */
extern real32_T CTDM_TorqueLimitNeg;   /* '<Root>/CTDM_TorqueLimitNeg' */
extern real32_T CTDM_TorqueLimitPos;   /* '<Root>/CTDM_TorqueLimitPos' */
extern real32_T CTDM_TorqueSpLimited;  /* '<Root>/CTDM_TorqueSpLimited' */
extern EnumCtlMode CTSO_OperationMode; /* '<Root>/CTSO_OperationMode' */
extern boolean_T CTSO_SpeedIntegralDisable;/* '<Root>/CTSO_SpeedIntegralDisable' */
extern real32_T CTSO_SpeedIntegralReset;/* '<Root>/CTSO_SpeedIntegralReset' */
extern real32_T SGPP_DcLinkVoltMeas;   /* '<Root>/SGPP_DcLinkVoltMeas' */
extern real32_T SGPP_MechSpeed;        /* '<Root>/SGPP_MechSpeed' */
extern real32_T SGPP_SampleTime2;      /* '<Root>/SGPP_SampleTime2' */
extern real32_T SGPP_SpeedSp;          /* '<Root>/SGPP_SpeedSp' */

#endif                       /* RTW_HEADER_CtlTorqueLoopController_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
