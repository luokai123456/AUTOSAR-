/*
 * File: CtlDeratingManager_private.h
 *
 * Code generated for Simulink model 'CtlDeratingManager'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:43:33 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CtlDeratingManager_private_h_
#define RTW_HEADER_CtlDeratingManager_private_h_
#include "rtwtypes.h"
#include "CtlDeratingManager_types.h"

extern const uint32_T rtCP_pooled_FkyIYT0nXjxT[2];

#define rtCP_InterpolationUsingPrelookup_maxIndex_ia rtCP_pooled_FkyIYT0nXjxT/* Computed Parameter: rtCP_InterpolationUsingPrelookup_maxIndex_ia
                                                                      * Referenced by: '<S46>/Interpolation Using Prelookup'
                                                                      */

/* Exported data declaration */

/* Data with Imported storage */
extern real32_T CTLC_IdSpLimited;      /* '<Root>/CTLC_IdSpLimited' */
extern real32_T CTLC_IqSpLimited;      /* '<Root>/CTLC_IqSpLimited' */
extern uint8_T CTSO_OperationMode;     /* '<Root>/CTSO_OperationMode' */
extern real32_T SGPP_DcLinkVoltMeas;   /* '<Root>/SGPP_DcLinkVoltMeas' */
extern real32_T SGPP_MechSpeed;        /* '<Root>/SGPP_MechSpeed' */
extern real32_T SGPP_MechSpeedAbsolute;/* '<Root>/SGPP_MechSpeedAbsolute' */
extern real32_T SGPP_MotorTemp1;       /* '<Root>/SGPP_MotorTemp1' */
extern real32_T SGPP_SampleTime2;      /* '<Root>/SGPP_SampleTime2' */
extern real32_T SGPP_SwitchTempMax;    /* '<Root>/SGPP_SwitchTempMax' */
extern real32_T SGSA_TorqueCommand;    /* '<Root>/SGSA_TorqueCommand' */

#endif                            /* RTW_HEADER_CtlDeratingManager_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
