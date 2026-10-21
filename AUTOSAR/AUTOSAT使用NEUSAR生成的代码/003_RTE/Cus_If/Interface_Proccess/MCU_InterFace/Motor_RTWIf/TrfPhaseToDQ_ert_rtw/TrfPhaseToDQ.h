/*
 * File: TrfPhaseToDQ.h
 *
 * Code generated for Simulink model 'TrfPhaseToDQ'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:28:04 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TrfPhaseToDQ_h_
#define RTW_HEADER_TrfPhaseToDQ_h_
#ifndef TrfPhaseToDQ_COMMON_INCLUDES_
#define TrfPhaseToDQ_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TrfPhaseToDQ_COMMON_INCLUDES_ */

#include "TrfPhaseToDQ_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_TrfPhaseToDQ_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void TrfPhaseToDQ_initialize(void);
extern void TrfPhaseToDQ_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void TFPD_ClarkeParkTransform_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T TFPD_DAxisFiltFreq_C;/* Referenced by: '<S13>/Constant' */

/* Cutoff frequency for d-axis current filter */
extern volatile real32_T TFPD_QAxisFiltFreq_C;/* Referenced by: '<S14>/Constant' */

/* Cutoff frequency for q-axis current filter */
extern volatile uint8_T TFPD_SensorSelection_C;/* Referenced by: '<S10>/Constant' */

/* Current sensor configuration selection (1-4) */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern real32_T TFPD_AlphaCurrent;

/* Alpha-axis current in stationary reference frame */
extern real32_T TFPD_BetaCurrent;

/* Beta-axis current in stationary reference frame */
extern real32_T TFPD_CurrentMagFilt;   /* '<S3>/Sqrt' */

/* Filtered magnitude of current vector */
extern real32_T TFPD_IdFiltered;       /* '<S11>/Subtract1' */

/* Filtered d-axis current after low-pass filtering */
extern real32_T TFPD_IdMeasured;       /* '<S3>/Add' */

/* Measured d-axis current */
extern real32_T TFPD_IqFiltered;       /* '<S12>/Subtract1' */

/* Filtered q-axis current after low-pass filtering */
extern real32_T TFPD_IqMeasured;       /* '<S3>/Add1' */

/* Measured q-axis current */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_TrfPhaseToDQ_T *const TrfPhaseToDQ_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TrfPhaseToDQ'
 * '<S1>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys'
 * '<S2>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ClarkeTransform'
 * '<S3>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ParkTransform'
 * '<S4>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ClarkeTransform/ClarkAB_AmpInv'
 * '<S5>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ClarkeTransform/ClarkeABC_AmpInv'
 * '<S6>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ClarkeTransform/ClarkeAC_AmpInv'
 * '<S7>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ClarkeTransform/ClarkeBC_AmpInv'
 * '<S8>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ClarkeTransform/Local Variable Storage'
 * '<S9>'   : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ClarkeTransform/Local Variable Storage1'
 * '<S10>'  : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ClarkeTransform/Parameter'
 * '<S11>'  : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ParkTransform/LowPassFilter'
 * '<S12>'  : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ParkTransform/LowPassFilter1'
 * '<S13>'  : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ParkTransform/Parameter'
 * '<S14>'  : 'TrfPhaseToDQ/TFPD_ClarkeParkTransform_100us_sys/ParkTransform/Parameter1'
 */
#endif                                 /* RTW_HEADER_TrfPhaseToDQ_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
