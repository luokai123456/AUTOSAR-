/*
 * File: AswAdapter.h
 *
 * Code generated for Simulink model 'AswAdapter'.
 *
 * Model version                  : 1.328
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jul 10 10:57:43 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AswAdapter_h_
#define RTW_HEADER_AswAdapter_h_
#ifndef AswAdapter_COMMON_INCLUDES_
#define AswAdapter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AswAdapter_COMMON_INCLUDES_ */

#include "AswAdapter_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Constant4;            /* '<S1>/Constant4' */
  const real32_T DataTypeConversion1;  /* '<S4>/Data Type Conversion1' */
  const real32_T DataTypeConversion2;  /* '<S4>/Data Type Conversion2' */
  const uint8_T Constant3;             /* '<S1>/Constant3' */
  const uint8_T DataTypeConversion;    /* '<S4>/Data Type Conversion' */
  const uint8_T Constant;              /* '<S15>/Constant' */
  const boolean_T Constant2;           /* '<S1>/Constant2' */
  const boolean_T Constant1;           /* '<S1>/Constant1' */
} ConstB_AswAdapter_T;

/* Real-time Model Data Structure */
struct tag_RTM_AswAdapter_T {
  const char_T * volatile errorStatus;
};

extern const ConstB_AswAdapter_T AswAdapter_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void AswAdapter_initialize(void);
extern void AswAdapter_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void ASWA_ReadProcess_1ms(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void ASWA_WriteProcess_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile uint8_T SGSA_OperatingModeSource_C;/* Referenced by: '<S10>/Constant' */

/* Operating mode source selection: 0=parameter, 1=CAN */
extern volatile uint8_T SGSA_OperatingModeSp_C;/* Referenced by: '<S9>/Constant' */

/* Operating mode selection parameter */
extern volatile uint8_T SGSA_SpeedSpSource_C;/* Referenced by: '<S13>/Constant' */

/* Speed setpoint source: 0=external, 1=parameter */
extern volatile real32_T SGSA_SpeedSp_C;/* Referenced by: '<S14>/Constant' */

/* Speed setpoint parameter */
extern volatile uint8_T SGSA_TorqueSpSource_C;/* Referenced by: '<S11>/Constant' */

/* Torque setpoint source: 0=external, 1=parameter */
extern volatile real32_T SGSA_TorqueSp_C;/* Referenced by: '<S12>/Constant' */

/* Torque setpoint parameter */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern uint8_T SGPP_BSW_u8_ASC_Enable; /* '<S1>/Chart' */

/* can signal */
extern uint8_T SGPP_BSW_u8_ClearFlt_Roty_En;/* '<S1>/Constant3' */

/* can signal */
extern boolean_T SGPP_BSW_u8_ClearFlt_Volt_Curr_En;/* '<S1>/Constant2' */

/* can signal */
extern boolean_T SGPP_BSW_u8_CutOffDelayEn_flg;/* '<S1>/Constant1' */

/* can signal */
extern uint8_T SGPP_BSW_u8_PWM_Enable; /* '<S1>/Chart' */

/* can signal */
extern real32_T SGPP_ElecSpeedAbsolute;/* '<S7>/Abs' */

/* can signal */
extern real32_T SGPP_FOC_f32_Uduty_Null;/* '<S1>/Chart' */

/* can signal */
extern real32_T SGPP_FOC_f32_Vduty_Null;/* '<S1>/Chart' */

/* can signal */
extern real32_T SGPP_FOC_f32_Wduty_Null;/* '<S1>/Chart' */

/* can signal */
extern real32_T SGPP_MechSpeedAbsolute;/* '<S7>/Abs1' */

/* can signal */
extern real32_T SGPP_kFOC_f32_PWMFreq_Hz;/* '<S1>/Constant4' */

/* can signal */
extern uint8_T SGSA_BswInit;           /* '<S2>/GetBswInit' */

/* can signal */
extern uint8_T SGSA_HwHsIntBSt;      /* '<S2>/SGPP_BSW_f32_DriveHBridg_Error' */

/* can signal */
extern uint8_T SGSA_HwLsIntBSt;      /* '<S2>/SGPP_BSW_f32_DriveLBridg_Error' */

/* can signal */
extern uint8_T SGSA_ModeRequest;       /* '<S4>/Switch' */

/* can signal */
extern real32_T SGSA_SpeedCommand;     /* '<S4>/Switch2' */

/* can signal */
extern real32_T SGSA_TorqueCommand;    /* '<S4>/Switch1' */

/* can signal */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_AswAdapter_T *const AswAdapter_M;

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
 * '<Root>' : 'AswAdapter'
 * '<S1>'   : 'AswAdapter/ASWA_Write_100us_sys'
 * '<S2>'   : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys'
 * '<S3>'   : 'AswAdapter/ASWA_Write_100us_sys/Chart'
 * '<S4>'   : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/CAN Signals'
 * '<S5>'   : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/GetBswInit'
 * '<S6>'   : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/GetHWErrorStatus'
 * '<S7>'   : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/SpeedAbsCalc'
 * '<S8>'   : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/Variant Subsystem1'
 * '<S9>'   : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/CAN Signals/Parameter1'
 * '<S10>'  : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/CAN Signals/Parameter10'
 * '<S11>'  : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/CAN Signals/Parameter2'
 * '<S12>'  : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/CAN Signals/Parameter3'
 * '<S13>'  : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/CAN Signals/Parameter4'
 * '<S14>'  : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/CAN Signals/Parameter5'
 * '<S15>'  : 'AswAdapter/SGPP_ReadTempVolt_1ms_sys/Variant Subsystem1/XCU_Code'
 */
#endif                                 /* RTW_HEADER_AswAdapter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
