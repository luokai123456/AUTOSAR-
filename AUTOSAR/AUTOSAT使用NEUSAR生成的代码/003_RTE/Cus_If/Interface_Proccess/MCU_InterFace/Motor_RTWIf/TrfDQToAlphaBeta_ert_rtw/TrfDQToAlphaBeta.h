/*
 * File: TrfDQToAlphaBeta.h
 *
 * Code generated for Simulink model 'TrfDQToAlphaBeta'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Jun 18 15:41:08 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TrfDQToAlphaBeta_h_
#define RTW_HEADER_TrfDQToAlphaBeta_h_
#ifndef TrfDQToAlphaBeta_COMMON_INCLUDES_
#define TrfDQToAlphaBeta_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TrfDQToAlphaBeta_COMMON_INCLUDES_ */

#include "TrfDQToAlphaBeta_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_TrfDQToAlphaBeta_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void TrfDQToAlphaBeta_initialize(void);
extern void TrfDQToAlphaBeta_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void TFDA_InvParkTransform_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T TFDA_AngleFactor_C;/* Referenced by: '<S5>/Constant' */

/* Angle correction factor for inverse Park transformation */
extern volatile real32_T TFDA_Open_Loop_SwitchC;/* Referenced by: '<S1>/Constant1' */

/* Angle correction factor for inverse Park transformation */
extern volatile real32_T TFDA_Open_Loop_Ud_C;/* Referenced by: '<S1>/Constant3' */

/* Angle correction factor for inverse Park transformation */
extern volatile real32_T TFDA_Open_Loop_Uq_C;/* Referenced by: '<S1>/Constant2' */

/* Angle correction factor for inverse Park transformation */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern real32_T TFDA_AlphaVoltSp;      /* '<S3>/Add' */

/* Alpha-axis voltage setpoint in stationary frame */
extern real32_T TFDA_BetaVoltSp;       /* '<S3>/Add1' */

/* Beta-axis voltage setpoint in stationary frame */
extern real32_T TFDA_ElecAngleCorrPreNorm;

/* Speed-corrected electrical angle before normalization */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_TrfDQToAlphaBeta_T *const TrfDQToAlphaBeta_M;

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
 * '<Root>' : 'TrfDQToAlphaBeta'
 * '<S1>'   : 'TrfDQToAlphaBeta/TFDA_InvParkTransform_100us_sys'
 * '<S2>'   : 'TrfDQToAlphaBeta/TFDA_InvParkTransform_100us_sys/AngleCompensate'
 * '<S3>'   : 'TrfDQToAlphaBeta/TFDA_InvParkTransform_100us_sys/VoltageParkInvTransform'
 * '<S4>'   : 'TrfDQToAlphaBeta/TFDA_InvParkTransform_100us_sys/AngleCompensate/Local Variable Storage'
 * '<S5>'   : 'TrfDQToAlphaBeta/TFDA_InvParkTransform_100us_sys/AngleCompensate/Parameter'
 */
#endif                                 /* RTW_HEADER_TrfDQToAlphaBeta_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
