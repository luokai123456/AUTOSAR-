/*
 * File: TrfPWMModulator.h
 *
 * Code generated for Simulink model 'TrfPWMModulator'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:26:20 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TrfPWMModulator_h_
#define RTW_HEADER_TrfPWMModulator_h_
#ifndef TrfPWMModulator_COMMON_INCLUDES_
#define TrfPWMModulator_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TrfPWMModulator_COMMON_INCLUDES_ */

#include "TrfPWMModulator_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_TrfPWMModulator_T {
  const char_T * volatile errorStatus;
};

/* Model entry point functions */
extern void TrfPWMModulator_initialize(void);
extern void TrfPWMModulator_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void TFPM_ModulatePwm_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T TFPM_DutyLowerLimit_C;/* Referenced by: '<S25>/Constant' */

/* Lower limit for duty cycle saturation */
extern volatile real32_T TFPM_DutyUpperLimit_C;/* Referenced by: '<S24>/Constant' */

/* Upper limit for duty cycle saturation */
extern volatile uint8_T TFPM_HighSideSwitchSel_C;/* Referenced by: '<S23>/Constant' */

/* Switch side selection: 1=high-side, 0=low-side */
extern volatile real32_T TFPM_MinSwitchTime_C;/* Referenced by: '<S28>/Constant' */

/* Minimum switching time constraint */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern real32_T TFPM_AlphaVoltNorm;

/* Normalized alpha-axis voltage relative to DC-link */
extern real32_T TFPM_AlphaVoltSp;

/* Alpha-axis voltage setpoint */
extern real32_T TFPM_BetaVoltNorm;

/* Normalized beta-axis voltage relative to DC-link */
extern real32_T TFPM_BetaVoltSp;

/* Beta-axis voltage setpoint */
extern real32_T TFPM_MinSwitchTimeRel;

/* Relative minimum switching time value */
extern real32_T TFPM_PhaseACompDutyLim;

/* Phase A compensated duty cycle with limiting */
extern real32_T TFPM_PhaseADuty;       /* '<S3>/Signal Conversion' */

/* Phase A PWM duty cycle output */
extern real32_T TFPM_PhaseADutyRel;

/* Phase A relative duty cycle value */
extern real32_T TFPM_PhaseASvmDuty;

/* Phase A space vector modulation duty cycle */
extern real32_T TFPM_PhaseAVoltNorm;

/* Phase A normalized voltage after modulation */
extern real32_T TFPM_PhaseBCompDutyLim;

/* Phase B compensated duty cycle with limiting */
extern real32_T TFPM_PhaseBDuty;       /* '<S3>/Signal Conversion1' */

/* Phase B PWM duty cycle output */
extern real32_T TFPM_PhaseBDutyRel;

/* Phase B relative duty cycle value */
extern real32_T TFPM_PhaseBSvmDuty;

/* Phase B space vector modulation duty cycle */
extern real32_T TFPM_PhaseBVoltNorm;

/* Phase B normalized voltage after modulation */
extern real32_T TFPM_PhaseCCompDutyLim;

/* Phase C compensated duty cycle with limiting */
extern real32_T TFPM_PhaseCDuty;       /* '<S3>/Signal Conversion2' */

/* Phase C PWM duty cycle output */
extern real32_T TFPM_PhaseCDutyRel;

/* Phase C relative duty cycle value */
extern real32_T TFPM_PhaseCLvmDuty;

/* Phase C space vector modulation duty cycle */
extern real32_T TFPM_PhaseCVoltNorm;

/* Phase C normalized voltage after modulation */
extern real32_T TFPM_ThreePhaseVoltMid;

/* Mid-point normalized voltage among three phases */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_TrfPWMModulator_T *const TrfPWMModulator_M;

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
 * '<Root>' : 'TrfPWMModulator'
 * '<S1>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys'
 * '<S2>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize'
 * '<S3>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis'
 * '<S4>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaModeSelect'
 * '<S5>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaToPhaseRef'
 * '<S6>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/Normalize'
 * '<S7>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaModeSelect/ClosedLoop'
 * '<S8>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaModeSelect/Local Variable Storage'
 * '<S9>'   : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaModeSelect/Local Variable Storage1'
 * '<S10>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaModeSelect/OpenLoop'
 * '<S11>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaToPhaseRef/Local Variable Storage'
 * '<S12>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaToPhaseRef/Local Variable Storage1'
 * '<S13>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/AlphaBetaToPhaseRef/Local Variable Storage2'
 * '<S14>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/Normalize/Local Variable Storage'
 * '<S15>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/Normalize/Local Variable Storage1'
 * '<S16>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/Normalize/Local Variable Storage2'
 * '<S17>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/Normalize/Local Variable Storage3'
 * '<S18>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/AlphaBetaToPhaseRefAndNormalize/Normalize/Local Variable Storage4'
 * '<S19>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/DutyLimiter'
 * '<S20>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/MinPulseCalc'
 * '<S21>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/NarrowPulseSuppress'
 * '<S22>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/ZeroSeqInjection'
 * '<S23>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/DutyLimiter/Parameter'
 * '<S24>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/DutyLimiter/Parameter1'
 * '<S25>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/DutyLimiter/Parameter2'
 * '<S26>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/DutyLimiter/Saturation Dynamic'
 * '<S27>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/MinPulseCalc/Local Variable Storage'
 * '<S28>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/MinPulseCalc/Parameter'
 * '<S29>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/NarrowPulseSuppress/Local Variable Storage'
 * '<S30>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/NarrowPulseSuppress/Local Variable Storage1'
 * '<S31>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/NarrowPulseSuppress/Local Variable Storage2'
 * '<S32>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/ZeroSeqInjection/Local Variable Storage1'
 * '<S33>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/ZeroSeqInjection/Local Variable Storage2'
 * '<S34>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/ZeroSeqInjection/Local Variable Storage3'
 * '<S35>'  : 'TrfPWMModulator/TFPM_ModulatePwm_100us_sys/DutySynthesis/ZeroSeqInjection/Local Variable Storage4'
 */
#endif                                 /* RTW_HEADER_TrfPWMModulator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
