/*
 * File: CtlStateOrchestrator_types.h
 *
 * Code generated for Simulink model 'CtlStateOrchestrator'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:42:19 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_CtlStateOrchestrator_types_h_
#define RTW_HEADER_CtlStateOrchestrator_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_EnumCtlPwmState_
#define DEFINED_TYPEDEF_FOR_EnumCtlPwmState_

/* PWM state enumeration for CtlStateOrchestrator */
typedef uint8_T EnumCtlPwmState;

/* enum EnumCtlPwmState */
#define Unused                         ((EnumCtlPwmState)0U)     /* Default value */
#define Run                            ((EnumCtlPwmState)1U)
#define AscLow                         ((EnumCtlPwmState)2U)
#define Off                            ((EnumCtlPwmState)3U)
#define AscHigh                        ((EnumCtlPwmState)4U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumCtlMode_
#define DEFINED_TYPEDEF_FOR_EnumCtlMode_

/* Control mode enumeration for CtlStateOrchestrator */
typedef uint8_T EnumCtlMode;

/* enum EnumCtlMode */
#define Init                           ((EnumCtlMode)0U)         /* Default value */
#define LowVoltReady                   ((EnumCtlMode)1U)
#define HighVoltStandby                ((EnumCtlMode)2U)
#define Ready                          ((EnumCtlMode)3U)
#define HighVoltDischarge              ((EnumCtlMode)4U)
#define LowVoltDischarge               ((EnumCtlMode)5U)
#define Discharge                      ((EnumCtlMode)6U)
#define PowerDown                      ((EnumCtlMode)7U)
#define Fault                          ((EnumCtlMode)8U)
#define OpenLoopCtrl                   ((EnumCtlMode)9U)
#define VoltDirectCtrl                 ((EnumCtlMode)10U)
#define CurrCtrl                       ((EnumCtlMode)11U)
#define TorqueCtrl                     ((EnumCtlMode)12U)
#define SpeedCtrl                      ((EnumCtlMode)13U)
#define ZeroPointCal                   ((EnumCtlMode)14U)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_CtlStateOrchestrator_T RT_MODEL_CtlStateOrchestrator_T;

#endif                            /* RTW_HEADER_CtlStateOrchestrator_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
