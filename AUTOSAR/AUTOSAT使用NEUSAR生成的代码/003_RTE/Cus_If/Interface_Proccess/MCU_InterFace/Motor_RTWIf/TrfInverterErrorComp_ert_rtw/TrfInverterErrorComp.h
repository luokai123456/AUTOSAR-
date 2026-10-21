/*
 * File: TrfInverterErrorComp.h
 *
 * Code generated for Simulink model 'TrfInverterErrorComp'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:29:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TrfInverterErrorComp_h_
#define RTW_HEADER_TrfInverterErrorComp_h_
#ifndef TrfInverterErrorComp_COMMON_INCLUDES_
#define TrfInverterErrorComp_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* TrfInverterErrorComp_COMMON_INCLUDES_ */

#include "TrfInverterErrorComp_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T Delay_DSTATE;                /* '<S27>/Delay' */
  boolean_T Delay_DSTATE_k;            /* '<S24>/Delay' */
} DW_TrfInverterErrorComp_T;

/* Real-time Model Data Structure */
struct tag_RTM_TrfInverterErrorComp_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_TrfInverterErrorComp_T TrfInverterErrorComp_DW;

/* Model entry point functions */
extern void TrfInverterErrorComp_initialize(void);
extern void TrfInverterErrorComp_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void TFEC_CompInverterError_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile real32_T TFEC_AngleFactor_C;/* Referenced by: '<S49>/Constant' */

/* Correction factor for electrical angle compensation */
extern volatile uint8_T TFEC_CompMasterEna_C;/* Referenced by: '<S22>/Constant' */

/* Master enable for compensation independent of conditions */
extern volatile real32_T TFEC_CurrentRampStart_C;/* Referenced by: '<S35>/Constant' */

/* Current threshold for sign function ramp initiation */
extern volatile uint8_T TFEC_CurrentReadMode_C;/* Referenced by: '<S41>/Constant' */

/* Current source selection: 0=measured dq, 1=dq setpoints */
extern volatile real32_T TFEC_CurrentSignMax_C;/* Referenced by: '<S33>/Constant' */

/* Current threshold for full sign saturation */
extern volatile real32_T TFEC_CurrentThrActivate_C;/* Referenced by: '<S26>/Constant' */

/* Current threshold to activate compensation */
extern volatile real32_T TFEC_CurrentThrDeactivate_C;/* Referenced by: '<S25>/Constant' */

/* Current threshold to deactivate compensation */
extern volatile uint8_T TFEC_DeadTimeCompEna_C;/* Referenced by: '<S16>/Constant' */

/* Enable flag for dead-time compensation */
extern volatile real32_T TFEC_DeadTimeDuration_C;/* Referenced by: '<S15>/Constant' */

/* Dead-time duration for inverter switching */
extern volatile real32_T TFEC_DeviceVoltDrop_C;/* Referenced by: '<S17>/Constant' */

/* Voltage drop per semiconductor device */
extern volatile real32_T TFEC_RampSlopeFactor_C;/* Referenced by: '<S34>/Constant' */

/* Slope factor for current sign ramp function */
extern volatile real32_T TFEC_SpeedThrActivate_C;/* Referenced by: '<S29>/Constant' */

/* Speed threshold to activate compensation */
extern volatile real32_T TFEC_SpeedThrDeactivate_C;/* Referenced by: '<S28>/Constant' */

/* Speed threshold to deactivate compensation */
extern volatile uint8_T TFEC_VoltDropCompEna_C;/* Referenced by: '<S18>/Constant' */

/* Enable flag for voltage drop compensation */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern uint8_T TFEC_CompConditionEna;

/* Conditional enable flag based on operating conditions */
extern real32_T TFEC_CurrentMagCalc;

/* Calculated current magnitude for compensation */
extern real32_T TFEC_IdRead;

/* D-axis current value for compensation calculation */
extern real32_T TFEC_IqRead;

/* Q-axis current value for compensation calculation */
extern real32_T TFEC_PhaseACompVolt;   /* '<S3>/Switch' */

/* Phase A total compensation voltage */
extern real32_T TFEC_PhaseACurrentCalc;

/* Calculated phase A current for compensation */
extern real32_T TFEC_PhaseACurrentSign;

/* Phase A current direction indicator */
extern real32_T TFEC_PhaseADeadTimeComp;

/* Phase A dead-time compensation voltage */
extern real32_T TFEC_PhaseAVoltDrop;

/* Phase A voltage drop compensation */
extern real32_T TFEC_PhaseBCompVolt;   /* '<S3>/Switch1' */

/* Phase B total compensation voltage */
extern real32_T TFEC_PhaseBCurrentCalc;

/* Calculated phase B current for compensation */
extern real32_T TFEC_PhaseBCurrentSign;

/* Phase B current direction indicator */
extern real32_T TFEC_PhaseBDeadTimeComp;

/* Phase B dead-time compensation voltage */
extern real32_T TFEC_PhaseBVoltDrop;

/* Phase B voltage drop compensation */
extern real32_T TFEC_PhaseCCompVolt;   /* '<S3>/Switch2' */

/* Phase C total compensation voltage */
extern real32_T TFEC_PhaseCCurrentCalc;

/* Calculated phase C current for compensation */
extern real32_T TFEC_PhaseCCurrentSign;

/* Phase C current direction indicator */
extern real32_T TFEC_PhaseCDeadTimeComp;

/* Phase C dead-time compensation voltage */
extern real32_T TFEC_PhaseCVoltDrop;

/* Phase C voltage drop compensation */
extern real32_T TFEC_StatorCurrentIs;  /* '<S5>/Sqrt' */

/* Stator Current */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_TrfInverterErrorComp_T *const TrfInverterErrorComp_M;

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
 * '<Root>' : 'TrfInverterErrorComp'
 * '<S1>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys'
 * '<S2>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis'
 * '<S3>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic'
 * '<S4>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc'
 * '<S5>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/IdIqSelect'
 * '<S6>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform'
 * '<S7>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/Local Variable Storage1'
 * '<S8>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/Local Variable Storage2'
 * '<S9>'   : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/Local Variable Storage3'
 * '<S10>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/Local Variable Storage4'
 * '<S11>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/Local Variable Storage5'
 * '<S12>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/Local Variable Storage6'
 * '<S13>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/UDdtVal'
 * '<S14>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/UdropVal'
 * '<S15>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/UDdtVal/Parameter3'
 * '<S16>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/UDdtVal/Parameter4'
 * '<S17>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/UdropVal/Parameter1'
 * '<S18>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/CompVoltageSynthesis/UdropVal/Parameter2'
 * '<S19>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/CurrentCondition'
 * '<S20>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/Local Variable Storage3'
 * '<S21>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/ModeCondition'
 * '<S22>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/Parameter4'
 * '<S23>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/SpeedConditon'
 * '<S24>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/CurrentCondition/HysteresisCtrl'
 * '<S25>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/CurrentCondition/Parameter1'
 * '<S26>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/CurrentCondition/Parameter4'
 * '<S27>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/SpeedConditon/HysteresisCtrl'
 * '<S28>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/SpeedConditon/Parameter1'
 * '<S29>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/EnaCompLogic/SpeedConditon/Parameter4'
 * '<S30>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc/Local Variable Storage1'
 * '<S31>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc/Local Variable Storage2'
 * '<S32>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc/Local Variable Storage3'
 * '<S33>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc/Parameter1'
 * '<S34>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc/Parameter2'
 * '<S35>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc/Parameter3'
 * '<S36>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc/Saturation Dynamic'
 * '<S37>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/ISgnCalc/Saturation Dynamic1'
 * '<S38>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/IdIqSelect/Local Variable Storage1'
 * '<S39>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/IdIqSelect/Local Variable Storage2'
 * '<S40>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/IdIqSelect/Local Variable Storage3'
 * '<S41>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/IdIqSelect/Parameter4'
 * '<S42>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform/InvClarkeI'
 * '<S43>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform/InvParkIWithAngleComp'
 * '<S44>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform/InvClarkeI/Local Variable Storage'
 * '<S45>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform/InvClarkeI/Local Variable Storage1'
 * '<S46>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform/InvClarkeI/Local Variable Storage2'
 * '<S47>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform/InvParkIWithAngleComp/AngleCompensate'
 * '<S48>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform/InvParkIWithAngleComp/ParkInvTransform'
 * '<S49>'  : 'TrfInverterErrorComp/TFEC_CompInverterError_100us_sys/InvParkClakeTransform/InvParkIWithAngleComp/AngleCompensate/Parameter'
 */
#endif                                 /* RTW_HEADER_TrfInverterErrorComp_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
