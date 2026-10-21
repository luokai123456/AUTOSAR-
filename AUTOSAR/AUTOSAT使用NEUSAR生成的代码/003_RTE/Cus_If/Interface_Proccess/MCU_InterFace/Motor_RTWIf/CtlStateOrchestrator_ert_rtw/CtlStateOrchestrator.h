/*
 * File: CtlStateOrchestrator.h
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

#ifndef RTW_HEADER_CtlStateOrchestrator_h_
#define RTW_HEADER_CtlStateOrchestrator_h_
#ifndef CtlStateOrchestrator_COMMON_INCLUDES_
#define CtlStateOrchestrator_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                               /* CtlStateOrchestrator_COMMON_INCLUDES_ */

#include "CtlStateOrchestrator_types.h"
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

/* Block signals (default storage) */
typedef struct {
  EnumCtlPwmState CTSO_StPwm;          /* '<S1>/Chart' */
} B_CtlStateOrchestrator_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S20>/Delay' */
  real32_T UnitDelay_DSTATE;           /* '<S17>/Unit Delay' */
  real32_T TiInin;                     /* '<S2>/CtlModeChart' */
  uint8_T Delay_DSTATE_f;              /* '<S14>/Delay' */
  boolean_T UnitDelay_DSTATE_c;        /* '<S4>/Unit Delay' */
  uint8_T is_c3_CtlStateOrchestrator;  /* '<S2>/CtlModeChart' */
  uint8_T is_MainControl;              /* '<S2>/CtlModeChart' */
  uint8_T CTSO_StInin;                 /* '<S2>/CtlModeChart' */
  uint8_T is_c1_CtlStateOrchestrator;  /* '<S1>/Chart' */
  uint8_T is_active_c1_CtlStateOrchestrator;/* '<S1>/Chart' */
} DW_CtlStateOrchestrator_T;

/* Real-time Model Data Structure */
struct tag_RTM_CtlStateOrchestrator_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_CtlStateOrchestrator_T CtlStateOrchestrator_B;

/* Block states (default storage) */
extern DW_CtlStateOrchestrator_T CtlStateOrchestrator_DW;

/* Model entry point functions */
extern void CtlStateOrchestrator_initialize(void);
extern void CtlStateOrchestrator_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void CTSO_ControlPwmState_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void CTSO_ManageStateMode_1ms(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile uint8_T CTSO_DischargeFaultReset_C;/* Referenced by: '<S19>/Constant' */

/* Reset flag for discharge fault condition */
extern volatile uint8_T CTSO_FaultRecoveryEnable_C;/* Referenced by: '<S2>/CtlModeChart' */

/* Enable falut mode recovery */
extern volatile real32_T CTSO_IGBTOffVoltThreshold_C;/* Referenced by:
                                                      * '<S6>/Constant'
                                                      * '<S7>/Constant'
                                                      */

/* The threshold below the dc-link voltage up to which the error reaction IgbtsOff is admissible */
extern volatile real32_T CTSO_InitWaitTime_C;/* Referenced by: '<S2>/CtlModeChart' */

/* time of waiting gate driver initialization */
extern volatile uint8_T CTSO_LowVoltStandbyEnable_C;/* Referenced by: '<S24>/Constant' */

/* Enable transition to standby mode on low DC voltage */
extern volatile real32_T CTSO_MinVoltControl_C;/* Referenced by: '<S2>/CtlModeChart' */

/* Minimum DC link voltage for motor control enable */
extern volatile uint8_T CTSO_OpModeCondition_C;/* Referenced by: '<S22>/Constant' */

/* Input condition for suitable operating state 0 - as given by customer, 1 - to include additional states not  required by customer */
extern volatile uint8_T CTSO_OpModeSelection_C;/* Referenced by: '<S23>/Constant' */

/* Operating mode selection parameter */
extern volatile real32_T CTSO_PowerdownVoltLimit_C;/* Referenced by:
                                                    * '<S2>/CtlModeChart'
                                                    * '<S25>/Constant'
                                                    */

/* Voltage threshold for system power-down sequence */
extern volatile uint8_T CTSO_ServiceModeEnable_C;/* Referenced by: '<S2>/CtlModeChart' */

/* Enable Service controlmodes, openloopvoltage etc. */
extern volatile real32_T CTSO_SpeedLimit_C;/* Referenced by: '<S2>/CtlModeChart' */

/* Speed limit */
extern volatile real32_T CTSO_VoltASCThreshold_C;/* Referenced by: '<S9>/Constant' */

/* DC voltage threshold for active short circuit mode selection */
extern volatile real32_T CTSO_VoltDischargeHighThr_C;/* Referenced by: '<S16>/Constant' */

/* Upper voltage threshold for discharge activation trigger */
extern volatile real32_T CTSO_VoltDischargeLowThr_C;/* Referenced by:
                                                     * '<S2>/CtlModeChart'
                                                     * '<S15>/Constant'
                                                     */

/* Lower voltage threshold for discharge completion detection */
extern volatile real32_T CTSO_VoltPerSpeedRatio_C;/* Referenced by: '<S8>/Constant' */

/* DC link voltage per motor speed constant ratio */
extern volatile real32_T CTSO_WindingDischargeMaxTime_C;/* Referenced by: '<S18>/Constant' */

/* Maximum time for motor winding discharge */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern uint8_T CTSO_CurrentIntegralDisable;/* '<S2>/CtlModeChart' */

/* Disable flag for current controller integral term */
extern uint8_T CTSO_CurrentIntegralReset;/* '<S2>/CtlModeChart' */

/* Reset flag for current controller integral term */
extern uint8_T CTSO_DischargeFaultFlag;/* '<S11>/Data Type Conversion2' */

/* Active discharge fault status flag */
extern uint8_T CTSO_FaultModeRequest_IRV;/* '<S1>/Chart' */

/* Fault mode operation request signal */
extern uint8_T CTSO_IGBTOffAllowed;

/* IGBT off operation permission flag */
extern uint8_T CTSO_ModeSetpoint;

/* Target operating mode setpoint selection */
extern uint8_T CTSO_OperationMode;     /* '<S2>/Data Type Conversion' */

/* System operation mode state */
extern uint8_T CTSO_PWMControlState;   /* '<S1>/Data Type Conversion' */

/* PWM unit control state */
extern uint8_T CTSO_PWMRequest_IRV;    /* '<S2>/CtlModeChart' */

/* PWM control state request signal */
extern uint8_T CTSO_SpeedCalcReset;    /* '<S2>/CtlModeChart' */

/* Reset signal for speed calculation low-pass filter */
extern uint8_T CTSO_SpeedIntegralDisable;/* '<S2>/CtlModeChart' */

/* signal for disabling of integrlpart of speed control */
extern uint8_T CTSO_SpeedIntegralReset;/* '<S2>/CtlModeChart' */

/* Reset flag for speed controller integral term */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_CtlStateOrchestrator_T *const CtlStateOrchestrator_M;

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
 * '<Root>' : 'CtlStateOrchestrator'
 * '<S1>'   : 'CtlStateOrchestrator/CTSO_ControlPwmState_100us_sys'
 * '<S2>'   : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys'
 * '<S3>'   : 'CtlStateOrchestrator/CTSO_ControlPwmState_100us_sys/Chart'
 * '<S4>'   : 'CtlStateOrchestrator/CTSO_ControlPwmState_100us_sys/SwitchOffCondition'
 * '<S5>'   : 'CtlStateOrchestrator/CTSO_ControlPwmState_100us_sys/SwitchOffCondition/Local Variable Storage1'
 * '<S6>'   : 'CtlStateOrchestrator/CTSO_ControlPwmState_100us_sys/SwitchOffCondition/Parameter1'
 * '<S7>'   : 'CtlStateOrchestrator/CTSO_ControlPwmState_100us_sys/SwitchOffCondition/Parameter2'
 * '<S8>'   : 'CtlStateOrchestrator/CTSO_ControlPwmState_100us_sys/SwitchOffCondition/Parameter3'
 * '<S9>'   : 'CtlStateOrchestrator/CTSO_ControlPwmState_100us_sys/SwitchOffCondition/Parameter4'
 * '<S10>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/CtlModeChart'
 * '<S11>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/DischargeTransitionLogic'
 * '<S12>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/ModeCmdPreprocess'
 * '<S13>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/StandbyTransitionLogic'
 * '<S14>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/DischargeTransitionLogic/AcvDchaDiag'
 * '<S15>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/DischargeTransitionLogic/Parameter1'
 * '<S16>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/DischargeTransitionLogic/Parameter4'
 * '<S17>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/DischargeTransitionLogic/AcvDchaDiag/HoldLatch'
 * '<S18>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/DischargeTransitionLogic/AcvDchaDiag/Parameter2'
 * '<S19>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/DischargeTransitionLogic/AcvDchaDiag/Parameter3'
 * '<S20>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/DischargeTransitionLogic/AcvDchaDiag/TimeMeter'
 * '<S21>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/ModeCmdPreprocess/Local Variable Storage1'
 * '<S22>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/ModeCmdPreprocess/Parameter1'
 * '<S23>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/ModeCmdPreprocess/Parameter4'
 * '<S24>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/StandbyTransitionLogic/Parameter1'
 * '<S25>'  : 'CtlStateOrchestrator/CTSO_ManageStateMode_1ms_sys/StandbyTransitionLogic/Parameter4'
 */
#endif                                 /* RTW_HEADER_CtlStateOrchestrator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
