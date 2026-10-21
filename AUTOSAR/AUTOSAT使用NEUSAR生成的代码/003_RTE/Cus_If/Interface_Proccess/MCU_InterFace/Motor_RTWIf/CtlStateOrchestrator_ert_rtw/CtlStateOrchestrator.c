/*
 * File: CtlStateOrchestrator.c
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

#include "CtlStateOrchestrator.h"
#include "rtwtypes.h"
#include "CtlStateOrchestrator_types.h"
#include "rt_nonfinite.h"
#include "CtlStateOrchestrator_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define CtlStateOrchestrator_IN_Fault_AscHigh ((uint8_T)1U)
#define CtlStateOrchestrator_IN_Fault_AscLow ((uint8_T)2U)
#define CtlStateOrchestrator_IN_Fault_Off ((uint8_T)3U)
#define CtlStateOrchestrator_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define CtlStateOrchestrator_IN_WorkMode ((uint8_T)4U)

/* Named constants for Chart: '<S2>/CtlModeChart' */
#define CtlStateOrchestrator_IN_CurrCtrl ((uint8_T)1U)
#define CtlStateOrchestrator_IN_Discharge ((uint8_T)1U)
#define CtlStateOrchestrator_IN_Fault  ((uint8_T)2U)
#define CtlStateOrchestrator_IN_HighVoltReady ((uint8_T)2U)
#define CtlStateOrchestrator_IN_Init   ((uint8_T)3U)
#define CtlStateOrchestrator_IN_LowVoltReady ((uint8_T)4U)
#define CtlStateOrchestrator_IN_MainControl ((uint8_T)5U)
#define CtlStateOrchestrator_IN_OpenLoopCtrl ((uint8_T)3U)
#define CtlStateOrchestrator_IN_PowerDown ((uint8_T)6U)
#define CtlStateOrchestrator_IN_SpeedCtrl ((uint8_T)4U)
#define CtlStateOrchestrator_IN_TorqueCtrl ((uint8_T)5U)
#define CtlStateOrchestrator_IN_VoltDirectCtrl ((uint8_T)6U)
#define CtlStateOrchestrator_IN_ZeroPointCal ((uint8_T)7U)

/* Exported data definition */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Par */
volatile uint8_T CTSO_DischargeFaultReset_C = 0U;/* Referenced by: '<S19>/Constant' */

/* Reset flag for discharge fault condition */
volatile uint8_T CTSO_FaultRecoveryEnable_C = 1U;/* Referenced by: '<S2>/CtlModeChart' */

/* Enable falut mode recovery */
volatile real32_T CTSO_IGBTOffVoltThreshold_C = 50.0F;/* Referenced by:
                                                       * '<S6>/Constant'
                                                       * '<S7>/Constant'
                                                       */

/* The threshold below the dc-link voltage up to which the error reaction IgbtsOff is admissible */
volatile real32_T CTSO_InitWaitTime_C = 0.1F;/* Referenced by: '<S2>/CtlModeChart' */

/* time of waiting gate driver initialization */
volatile uint8_T CTSO_LowVoltStandbyEnable_C = 0U;/* Referenced by: '<S24>/Constant' */

/* Enable transition to standby mode on low DC voltage */
volatile real32_T CTSO_MinVoltControl_C = 200.0F;/* Referenced by: '<S2>/CtlModeChart' */

/* Minimum DC link voltage for motor control enable */
volatile uint8_T CTSO_OpModeCondition_C = 0U;/* Referenced by: '<S22>/Constant' */

/* Input condition for suitable operating state 0 - as given by customer, 1 - to include additional states not  required by customer */
volatile uint8_T CTSO_OpModeSelection_C = 0U;/* Referenced by: '<S23>/Constant' */

/* Operating mode selection parameter */
volatile real32_T CTSO_PowerdownVoltLimit_C = 60.0F;/* Referenced by:
                                                     * '<S2>/CtlModeChart'
                                                     * '<S25>/Constant'
                                                     */

/* Voltage threshold for system power-down sequence */
volatile uint8_T CTSO_ServiceModeEnable_C = 1U;/* Referenced by: '<S2>/CtlModeChart' */

/* Enable Service controlmodes, openloopvoltage etc. */
volatile real32_T CTSO_SpeedLimit_C = 500.0F;/* Referenced by: '<S2>/CtlModeChart' */

/* Speed limit */
volatile real32_T CTSO_VoltASCThreshold_C = 380.0F;/* Referenced by: '<S9>/Constant' */

/* DC voltage threshold for active short circuit mode selection */
volatile real32_T CTSO_VoltDischargeHighThr_C = 60.0F;/* Referenced by: '<S16>/Constant' */

/* Upper voltage threshold for discharge activation trigger */
volatile real32_T CTSO_VoltDischargeLowThr_C = 55.0F;/* Referenced by:
                                                      * '<S2>/CtlModeChart'
                                                      * '<S15>/Constant'
                                                      */

/* Lower voltage threshold for discharge completion detection */
volatile real32_T CTSO_VoltPerSpeedRatio_C = 0.06F;/* Referenced by: '<S8>/Constant' */

/* DC link voltage per motor speed constant ratio */
volatile real32_T CTSO_WindingDischargeMaxTime_C = 1.0F;/* Referenced by: '<S18>/Constant' */

/* Maximum time for motor winding discharge */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Definition for custom storage class: MtrCtrl_Sig */
uint8_T CTSO_CurrentIntegralDisable;   /* '<S2>/CtlModeChart' */

/* Disable flag for current controller integral term */
uint8_T CTSO_CurrentIntegralReset;     /* '<S2>/CtlModeChart' */

/* Reset flag for current controller integral term */
uint8_T CTSO_DischargeFaultFlag;       /* '<S11>/Data Type Conversion2' */

/* Active discharge fault status flag */
uint8_T CTSO_FaultModeRequest_IRV;     /* '<S1>/Chart' */

/* Fault mode operation request signal */
uint8_T CTSO_IGBTOffAllowed;           /* IGBT off operation permission flag */
uint8_T CTSO_ModeSetpoint;        /* Target operating mode setpoint selection */
uint8_T CTSO_OperationMode;            /* '<S2>/Data Type Conversion' */

/* System operation mode state */
uint8_T CTSO_PWMControlState;          /* '<S1>/Data Type Conversion' */

/* PWM unit control state */
uint8_T CTSO_PWMRequest_IRV;           /* '<S2>/CtlModeChart' */

/* PWM control state request signal */
uint8_T CTSO_SpeedCalcReset;           /* '<S2>/CtlModeChart' */

/* Reset signal for speed calculation low-pass filter */
uint8_T CTSO_SpeedIntegralDisable;     /* '<S2>/CtlModeChart' */

/* signal for disabling of integrlpart of speed control */
uint8_T CTSO_SpeedIntegralReset;       /* '<S2>/CtlModeChart' */

/* Reset flag for speed controller integral term */


/* Block signals (default storage) */
B_CtlStateOrchestrator_T CtlStateOrchestrator_B;

/* Block states (default storage) */
DW_CtlStateOrchestrator_T CtlStateOrchestrator_DW;

/* Real-time model */
static RT_MODEL_CtlStateOrchestrator_T CtlStateOrchestrator_M_;
RT_MODEL_CtlStateOrchestrator_T *const CtlStateOrchestrator_M =
  &CtlStateOrchestrator_M_;
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
/* Forward declaration for local functions */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

static uint8_T CtlStateOrchestrato_safe_cast_to_EnumCtlPwmState(uint8_T input);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

static void CtlStateOrchestrator_MainControl(const uint8_T *DataTypeConversion,
  const uint8_T *DataTypeConversion_g, const EnumCtlMode *DataTypeConversion_p,
  EnumCtlMode *CTSO_StOperMode);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

static uint8_T CtlStateOrchestrato_safe_cast_to_EnumCtlPwmState(uint8_T input)
{
  uint8_T output;

  /* Initialize output value to default value for EnumCtlPwmState (Unused) */
  output = 0U;
  if (input <= 4) {
    /* Set output value to input value if it is a member of EnumCtlPwmState */
    output = input;
  }

  return output;
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Function for Chart: '<S2>/CtlModeChart' */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

static void CtlStateOrchestrator_MainControl(const uint8_T *DataTypeConversion,
  const uint8_T *DataTypeConversion_g, const EnumCtlMode *DataTypeConversion_p,
  EnumCtlMode *CTSO_StOperMode)
{
  if (CTSO_FaultModeRequest_IRV == 1) {
    CtlStateOrchestrator_DW.is_MainControl =
      CtlStateOrchestrator_IN_NO_ACTIVE_CHILD;
    CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
      CtlStateOrchestrator_IN_Fault;
    CTSO_PWMRequest_IRV = Off;
    *CTSO_StOperMode = Fault;
    CTSO_CurrentIntegralReset = 1U;
    CTSO_CurrentIntegralDisable = 1U;
    CTSO_SpeedIntegralDisable = 1U;
    CTSO_SpeedIntegralReset = 1U;
    CTSO_SpeedCalcReset = 0U;
  } else {
    switch (CtlStateOrchestrator_DW.is_MainControl) {
     case CtlStateOrchestrator_IN_CurrCtrl:
      CTSO_PWMRequest_IRV = Run;
      *CTSO_StOperMode = CurrCtrl;
      CTSO_CurrentIntegralReset = 0U;
      CTSO_CurrentIntegralDisable = 0U;
      if (*DataTypeConversion != 0) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_HighVoltReady;
        CTSO_PWMRequest_IRV = Off;
        *CTSO_StOperMode = HighVoltStandby;
        CTSO_CurrentIntegralReset = 1U;
        CTSO_CurrentIntegralDisable = 1U;
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CTSO_SpeedCalcReset = 0U;
      }
      break;

     case CtlStateOrchestrator_IN_HighVoltReady:
      CTSO_PWMRequest_IRV = Off;
      *CTSO_StOperMode = HighVoltStandby;
      CTSO_CurrentIntegralReset = 1U;
      CTSO_CurrentIntegralDisable = 1U;

      /* Inport: '<Root>/SGPP_IgnitionStatus' incorporates:
       *  DataTypeConversion: '<S12>/Data Type Conversion'
       *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
       */
      if ((SGPP_IgnitionStatus == 0) || (SGPP_DcLinkVoltMeas <
           CTSO_PowerdownVoltLimit_C)) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_NO_ACTIVE_CHILD;
        CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_LowVoltReady;
        *CTSO_StOperMode = LowVoltReady;
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CTSO_SpeedCalcReset = 0U;
      } else if (*DataTypeConversion_p == TorqueCtrl) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_TorqueCtrl;
        CTSO_PWMRequest_IRV = Run;
        *CTSO_StOperMode = TorqueCtrl;
        CTSO_CurrentIntegralReset = 0U;
        CTSO_CurrentIntegralDisable = 0U;
      } else if (*DataTypeConversion_g == 1) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_NO_ACTIVE_CHILD;
        CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Discharge;
        CTSO_PWMRequest_IRV = Run;
        *CTSO_StOperMode = Discharge;
        CTSO_CurrentIntegralReset = 0U;
        CTSO_CurrentIntegralDisable = 0U;
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CTSO_SpeedCalcReset = 0U;
      } else if (*DataTypeConversion_p == SpeedCtrl) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_SpeedCtrl;
        CTSO_PWMRequest_IRV = Run;
        *CTSO_StOperMode = SpeedCtrl;
        CTSO_SpeedIntegralReset = 0U;
        CTSO_SpeedIntegralDisable = 0U;
        CTSO_CurrentIntegralReset = 0U;
        CTSO_CurrentIntegralDisable = 0U;
      } else if ((*DataTypeConversion_p == OpenLoopCtrl) &&
                 (CTSO_ServiceModeEnable_C == 1)) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_OpenLoopCtrl;
        CTSO_PWMRequest_IRV = Run;
        *CTSO_StOperMode = OpenLoopCtrl;
      } else if ((*DataTypeConversion_p == VoltDirectCtrl) &&
                 (CTSO_ServiceModeEnable_C == 1)) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_VoltDirectCtrl;
        CTSO_PWMRequest_IRV = Run;
        *CTSO_StOperMode = VoltDirectCtrl;
      } else if ((*DataTypeConversion_p == ZeroPointCal) &&
                 (CTSO_ServiceModeEnable_C == 1)) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_ZeroPointCal;
        CTSO_PWMRequest_IRV = Run;
        *CTSO_StOperMode = ZeroPointCal;
      } else if ((*DataTypeConversion_p == CurrCtrl) &&
                 (CTSO_ServiceModeEnable_C == 1)) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_CurrCtrl;
        CTSO_PWMRequest_IRV = Run;
        *CTSO_StOperMode = CurrCtrl;
        CTSO_CurrentIntegralReset = 0U;
        CTSO_CurrentIntegralDisable = 0U;
      }

      /* End of Inport: '<Root>/SGPP_IgnitionStatus' */
      break;

     case CtlStateOrchestrator_IN_OpenLoopCtrl:
      CTSO_PWMRequest_IRV = Run;
      *CTSO_StOperMode = OpenLoopCtrl;
      CTSO_CurrentIntegralReset = 1U;
      CTSO_CurrentIntegralDisable = 1U;
      if (*DataTypeConversion != 0) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_HighVoltReady;
        CTSO_PWMRequest_IRV = Off;
        *CTSO_StOperMode = HighVoltStandby;
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CTSO_SpeedCalcReset = 0U;
      }
      break;

     case CtlStateOrchestrator_IN_SpeedCtrl:
      CTSO_PWMRequest_IRV = Run;
      *CTSO_StOperMode = SpeedCtrl;
      CTSO_CurrentIntegralReset = 0U;
      CTSO_CurrentIntegralDisable = 0U;

      /* DataTypeConversion: '<S12>/Data Type Conversion' */
      if (*DataTypeConversion_p == TorqueCtrl) {
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_TorqueCtrl;
        *CTSO_StOperMode = TorqueCtrl;
      } else if (*DataTypeConversion != 0) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_HighVoltReady;
        CTSO_PWMRequest_IRV = Off;
        *CTSO_StOperMode = HighVoltStandby;
        CTSO_CurrentIntegralReset = 1U;
        CTSO_CurrentIntegralDisable = 1U;
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CTSO_SpeedCalcReset = 0U;
      }
      break;

     case CtlStateOrchestrator_IN_TorqueCtrl:
      CTSO_PWMRequest_IRV = Run;
      *CTSO_StOperMode = TorqueCtrl;
      CTSO_CurrentIntegralReset = 0U;
      CTSO_CurrentIntegralDisable = 0U;

      /* DataTypeConversion: '<S12>/Data Type Conversion' */
      if (*DataTypeConversion_p == SpeedCtrl) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_SpeedCtrl;
        *CTSO_StOperMode = SpeedCtrl;
        CTSO_SpeedIntegralReset = 0U;
        CTSO_SpeedIntegralDisable = 0U;
      } else if (*DataTypeConversion != 0) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_HighVoltReady;
        CTSO_PWMRequest_IRV = Off;
        *CTSO_StOperMode = HighVoltStandby;
        CTSO_CurrentIntegralReset = 1U;
        CTSO_CurrentIntegralDisable = 1U;
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CTSO_SpeedCalcReset = 0U;
      }
      break;

     case CtlStateOrchestrator_IN_VoltDirectCtrl:
      CTSO_PWMRequest_IRV = Run;
      *CTSO_StOperMode = VoltDirectCtrl;
      CTSO_CurrentIntegralReset = 1U;
      CTSO_CurrentIntegralDisable = 1U;
      if (*DataTypeConversion != 0) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_HighVoltReady;
        CTSO_PWMRequest_IRV = Off;
        *CTSO_StOperMode = HighVoltStandby;
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CTSO_SpeedCalcReset = 0U;
      }
      break;

     default:
      /* case IN_ZeroPointCal: */
      CTSO_PWMRequest_IRV = Run;
      *CTSO_StOperMode = ZeroPointCal;
      CTSO_CurrentIntegralReset = 1U;
      CTSO_CurrentIntegralDisable = 1U;
      if (*DataTypeConversion != 0) {
        CtlStateOrchestrator_DW.is_MainControl =
          CtlStateOrchestrator_IN_HighVoltReady;
        CTSO_PWMRequest_IRV = Off;
        *CTSO_StOperMode = HighVoltStandby;
        CTSO_SpeedIntegralReset = 1U;
        CTSO_SpeedIntegralDisable = 1U;
        CTSO_SpeedCalcReset = 0U;
      }
      break;
    }
  }
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function for TID1 */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void CTSO_ControlPwmState_100us(void)
                                 /* Explicit Task: CTSO_ControlPwmState_100us */
{
  real32_T rtb_Switch_b;

  /* RootInportFunctionCallGenerator generated from: '<Root>/CTSO_ControlPwmState_100us' incorporates:
   *  SubSystem: '<Root>/CTSO_ControlPwmState_100us_sys'
   */
  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
   *  MinMax: '<S4>/Max'
   *  Sum: '<S4>/Add'
   *  Sum: '<S4>/Add1'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  if (CtlStateOrchestrator_DW.UnitDelay_DSTATE_c) {
    /* MinMax: '<S4>/Max' incorporates:
     *  Constant: '<S9>/Constant'
     *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
     */
    if ((SGPP_DcLinkVoltMeas >= CTSO_VoltASCThreshold_C) || rtIsNaNF
        (CTSO_VoltASCThreshold_C)) {
      rtb_Switch_b = SGPP_DcLinkVoltMeas;
    } else {
      rtb_Switch_b = CTSO_VoltASCThreshold_C;
    }

    rtb_Switch_b -= CTSO_IGBTOffVoltThreshold_C;
  } else {
    if ((SGPP_DcLinkVoltMeas >= CTSO_VoltASCThreshold_C) || rtIsNaNF
        (CTSO_VoltASCThreshold_C)) {
      /* MinMax: '<S4>/Max' incorporates:
       *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
       */
      rtb_Switch_b = SGPP_DcLinkVoltMeas;
    } else {
      /* MinMax: '<S4>/Max' incorporates:
       *  Constant: '<S9>/Constant'
       */
      rtb_Switch_b = CTSO_VoltASCThreshold_C;
    }

    rtb_Switch_b = (rtb_Switch_b - CTSO_IGBTOffVoltThreshold_C) -
      CTSO_IGBTOffVoltThreshold_C;
  }

  /* End of Switch: '<S4>/Switch' */

  /* RelationalOperator: '<S4>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/SGPP_MechSpeedAbsolute'
   *  Product: '<S4>/Product'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  CtlStateOrchestrator_DW.UnitDelay_DSTATE_c = (rtb_Switch_b >
    SGPP_MechSpeedAbsolute * CTSO_VoltPerSpeedRatio_C);

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S5>/Data Store Write'
   *  Inport: '<Root>/FLDG_ResolverError'
   *  Logic: '<S4>/Logical Operator'
   *  Logic: '<S4>/Logical Operator1'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  CTSO_IGBTOffAllowed = (uint8_T)(CtlStateOrchestrator_DW.UnitDelay_DSTATE_c &&
    (FLDG_ResolverError == 0));

  /* Chart: '<S1>/Chart' incorporates:
   *  DataStoreWrite: '<S5>/Data Store Write'
   *  Inport: '<Root>/FLDG_ActiveShortHsReq'
   *  Inport: '<Root>/FLDG_HwHsShortErr'
   *  Inport: '<Root>/FLDG_HwLsShortErr'
   *  Inport: '<Root>/FLDG_PowerSwitchOffReq'
   *  Inport: '<Root>/FLDG_ShutdownReq'
   */
  if (CtlStateOrchestrator_DW.is_active_c1_CtlStateOrchestrator == 0U) {
    CtlStateOrchestrator_DW.is_active_c1_CtlStateOrchestrator = 1U;
    CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
      CtlStateOrchestrator_IN_WorkMode;
    CtlStateOrchestrator_B.CTSO_StPwm =
      CtlStateOrchestrato_safe_cast_to_EnumCtlPwmState(CTSO_PWMRequest_IRV);
    CTSO_FaultModeRequest_IRV = 0U;
  } else {
    switch (CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator) {
     case CtlStateOrchestrator_IN_Fault_AscHigh:
      CTSO_FaultModeRequest_IRV = 1U;
      if ((FLDG_ShutdownReq == 0) && ((FLDG_PowerSwitchOffReq == 0) &&
           (FLDG_ActiveShortHsReq == 0))) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_WorkMode;
        CtlStateOrchestrator_B.CTSO_StPwm =
          CtlStateOrchestrato_safe_cast_to_EnumCtlPwmState(CTSO_PWMRequest_IRV);
        CTSO_FaultModeRequest_IRV = 0U;
      } else if ((FLDG_HwHsShortErr == 1) && (FLDG_HwLsShortErr == 1)) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_Off;
        CtlStateOrchestrator_B.CTSO_StPwm = Off;
      } else if ((FLDG_HwHsShortErr == 1) && (FLDG_HwLsShortErr == 0)) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_AscLow;
        CtlStateOrchestrator_B.CTSO_StPwm = AscLow;
      }
      break;

     case CtlStateOrchestrator_IN_Fault_AscLow:
      CTSO_FaultModeRequest_IRV = 1U;
      if (FLDG_PowerSwitchOffReq == 1) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_Off;
        CtlStateOrchestrator_B.CTSO_StPwm = Off;
      } else if ((FLDG_ShutdownReq == 0) && ((FLDG_PowerSwitchOffReq == 0) &&
                  (FLDG_ActiveShortHsReq == 0))) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_WorkMode;
        CtlStateOrchestrator_B.CTSO_StPwm =
          CtlStateOrchestrato_safe_cast_to_EnumCtlPwmState(CTSO_PWMRequest_IRV);
        CTSO_FaultModeRequest_IRV = 0U;
      } else if ((FLDG_HwHsShortErr == 0) && (FLDG_HwLsShortErr == 1)) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_AscHigh;
        CtlStateOrchestrator_B.CTSO_StPwm = AscHigh;
      }
      break;

     case CtlStateOrchestrator_IN_Fault_Off:
      CTSO_FaultModeRequest_IRV = 1U;
      if ((FLDG_ShutdownReq == 1) || (CTSO_IGBTOffAllowed != 1)) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_AscLow;
        CtlStateOrchestrator_B.CTSO_StPwm = AscLow;
      } else if (FLDG_ActiveShortHsReq == 1) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_AscHigh;
        CtlStateOrchestrator_B.CTSO_StPwm = AscHigh;
      } else if ((FLDG_ShutdownReq == 0) && ((FLDG_PowerSwitchOffReq == 0) &&
                  (FLDG_ActiveShortHsReq == 0))) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_WorkMode;
        CtlStateOrchestrator_B.CTSO_StPwm =
          CtlStateOrchestrato_safe_cast_to_EnumCtlPwmState(CTSO_PWMRequest_IRV);
        CTSO_FaultModeRequest_IRV = 0U;
      }
      break;

     default:
      /* case IN_WorkMode: */
      CTSO_FaultModeRequest_IRV = 0U;
      if (FLDG_ShutdownReq == 1) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_AscLow;
        CtlStateOrchestrator_B.CTSO_StPwm = AscLow;
        CTSO_FaultModeRequest_IRV = 1U;
      } else if (FLDG_ActiveShortHsReq == 1) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_AscHigh;
        CtlStateOrchestrator_B.CTSO_StPwm = AscHigh;
        CTSO_FaultModeRequest_IRV = 1U;
      } else if (FLDG_PowerSwitchOffReq == 1) {
        CtlStateOrchestrator_DW.is_c1_CtlStateOrchestrator =
          CtlStateOrchestrator_IN_Fault_Off;
        CtlStateOrchestrator_B.CTSO_StPwm = Off;
        CTSO_FaultModeRequest_IRV = 1U;
      } else if ((CTSO_PWMRequest_IRV == Off) && (CTSO_IGBTOffAllowed == 0)) {
        CtlStateOrchestrator_B.CTSO_StPwm = AscLow;
      } else {
        CtlStateOrchestrator_B.CTSO_StPwm =
          CtlStateOrchestrato_safe_cast_to_EnumCtlPwmState(CTSO_PWMRequest_IRV);
      }
      break;
    }
  }

  /* End of Chart: '<S1>/Chart' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  CTSO_PWMControlState = CtlStateOrchestrator_B.CTSO_StPwm;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/CTSO_ControlPwmState_100us' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model step function for TID2 */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

void CTSO_ManageStateMode_1ms(void)
                                   /* Explicit Task: CTSO_ManageStateMode_1ms */
{
  EnumCtlMode CTSO_StOperMode;
  uint8_T DataTypeConversion;
  uint8_T DataTypeConversion_g;
  boolean_T rtb_RelationalOperator2_o;

  /* RootInportFunctionCallGenerator generated from: '<Root>/CTSO_ManageStateMode_1ms' incorporates:
   *  SubSystem: '<Root>/CTSO_ManageStateMode_1ms_sys'
   */
  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   *  DataStoreWrite: '<S21>/Data Store Write'
   *  Inport: '<Root>/SGSA_ModeRequest'
   */
  if (CTSO_OpModeCondition_C != 0) {
    CTSO_ModeSetpoint = CTSO_OpModeSelection_C;
  } else {
    CTSO_ModeSetpoint = SGSA_ModeRequest;
  }

  /* End of Switch: '<S12>/Switch' */

  /* RelationalOperator: '<S13>/Relational Operator4' incorporates:
   *  Constant: '<S11>/Constant3'
   *  Constant: '<S13>/Constant3'
   *  Constant: '<S14>/Constant1'
   *  RelationalOperator: '<S11>/Relational Operator4'
   *  RelationalOperator: '<S14>/Relational Operator3'
   */
  CTSO_StOperMode = Discharge;

  /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   *  Constant: '<S13>/Constant2'
   *  Constant: '<S13>/Constant3'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  DataStoreWrite: '<S21>/Data Store Write'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
   *  Inport: '<Root>/SGPP_IgnitionStatus'
   *  Logic: '<S13>/Logical Operator'
   *  Logic: '<S13>/Logical Operator1'
   *  Logic: '<S13>/Logical Operator2'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  RelationalOperator: '<S13>/Relational Operator1'
   *  RelationalOperator: '<S13>/Relational Operator2'
   *  RelationalOperator: '<S13>/Relational Operator3'
   *  RelationalOperator: '<S13>/Relational Operator4'
   */
  DataTypeConversion = (uint8_T)((CTSO_ModeSetpoint == LowVoltReady) ||
    (CTSO_ModeSetpoint == HighVoltStandby) || (CTSO_ModeSetpoint == Discharge) ||
    (SGPP_IgnitionStatus == ((uint8_T)0U)) || ((SGPP_DcLinkVoltMeas <
    CTSO_PowerdownVoltLimit_C) && (CTSO_LowVoltStandbyEnable_C != 0)));

  /* DataTypeConversion: '<S11>/Data Type Conversion' incorporates:
   *  Constant: '<S13>/Constant3'
   *  Constant: '<S16>/Constant'
   *  DataStoreWrite: '<S21>/Data Store Write'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
   *  Logic: '<S11>/Logical Operator'
   *  RelationalOperator: '<S11>/Relational Operator'
   *  RelationalOperator: '<S11>/Relational Operator4'
   *  RelationalOperator: '<S13>/Relational Operator4'
   */
  DataTypeConversion_g = (uint8_T)((CTSO_ModeSetpoint == Discharge) &&
    (SGPP_DcLinkVoltMeas >= CTSO_VoltDischargeHighThr_C));

  /* Switch: '<S20>/Switch' incorporates:
   *  Constant: '<S13>/Constant3'
   *  Logic: '<S14>/Logical Operator4'
   *  RelationalOperator: '<S13>/Relational Operator4'
   *  RelationalOperator: '<S14>/Relational Operator3'
   *  Switch: '<S20>/Switch1'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  if (CTSO_OperationMode != Discharge) {
    /* Sum: '<S20>/Add' incorporates:
     *  Constant: '<S20>/RstVal'
     *  Delay: '<S20>/Delay'
     */
    CtlStateOrchestrator_DW.Delay_DSTATE = 0.0F;
  } else {
    /* Sum: '<S20>/Add' incorporates:
     *  Delay: '<S20>/Delay'
     *  Inport: '<Root>/SGPP_SampleTime2'
     */
    CtlStateOrchestrator_DW.Delay_DSTATE += SGPP_SampleTime2;

    /* MinMax: '<S20>/Min' incorporates:
     *  Constant: '<S20>/MaxVal'
     */
    if ((65535.0F <= CtlStateOrchestrator_DW.Delay_DSTATE) || rtIsNaNF
        (CtlStateOrchestrator_DW.Delay_DSTATE)) {
      /* Sum: '<S20>/Add' */
      CtlStateOrchestrator_DW.Delay_DSTATE = 65535.0F;
    }

    /* End of MinMax: '<S20>/Min' */
  }

  /* End of Switch: '<S20>/Switch' */

  /* RelationalOperator: '<S14>/Relational Operator2' incorporates:
   *  Constant: '<S18>/Constant'
   *  Delay: '<S20>/Delay'
   */
  rtb_RelationalOperator2_o = (CtlStateOrchestrator_DW.Delay_DSTATE >
    CTSO_WindingDischargeMaxTime_C);

  /* Switch: '<S17>/Switch XOR' incorporates:
   *  Constant: '<S19>/Constant'
   *  DataTypeConversion: '<S17>/Data Type Conversion1'
   *  Delay: '<S14>/Delay'
   *  Inport: '<Root>/SGPP_IgnitionStatus'
   *  Logic: '<S14>/Logical Operator1'
   *  Logic: '<S14>/Logical Operator2'
   *  Logic: '<S14>/Logical Operator3'
   *  Logic: '<S17>/XOR'
   *  Switch: '<S17>/Switch AND'
   *  UnitDelay: '<S17>/Unit Delay'
   */
  if ((boolean_T)(((CTSO_DischargeFaultReset_C != 0) ||
                   ((CtlStateOrchestrator_DW.Delay_DSTATE_f == 0) &&
                    (SGPP_IgnitionStatus != 0))) ^ rtb_RelationalOperator2_o)) {
    CtlStateOrchestrator_DW.UnitDelay_DSTATE = rtb_RelationalOperator2_o;
  } else if (rtb_RelationalOperator2_o) {
    /* Switch: '<S17>/Switch AND' incorporates:
     *  Constant: '<S17>/Constant'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    CtlStateOrchestrator_DW.UnitDelay_DSTATE = 1.0F;
  }

  /* End of Switch: '<S17>/Switch XOR' */

  /* DataTypeConversion: '<S11>/Data Type Conversion2' incorporates:
   *  UnitDelay: '<S17>/Unit Delay'
   */
  CTSO_DischargeFaultFlag = (uint8_T)CtlStateOrchestrator_DW.UnitDelay_DSTATE;

  /* Chart: '<S2>/CtlModeChart' incorporates:
   *  Constant: '<S15>/Constant'
   *  DataStoreWrite: '<S21>/Data Store Write'
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  Inport: '<Root>/SGPP_DcLinkVoltMeas'
   *  Inport: '<Root>/SGPP_IgnitionStatus'
   *  Inport: '<Root>/SGPP_MechSpeedAbsolute'
   *  Inport: '<Root>/SGPP_SampleTime2'
   *  Inport: '<Root>/SGSA_BswInit'
   *  RelationalOperator: '<S11>/Relational Operator1'
   */
  switch (CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator) {
   case CtlStateOrchestrator_IN_Discharge:
    CTSO_PWMRequest_IRV = Run;
    CTSO_StOperMode = Discharge;
    CTSO_CurrentIntegralReset = 0U;
    CTSO_CurrentIntegralDisable = 0U;
    if ((CTSO_DischargeFaultFlag == 1) || (CTSO_FaultModeRequest_IRV == 1)) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_Fault;
      CTSO_PWMRequest_IRV = Off;
      CTSO_StOperMode = Fault;
      CTSO_CurrentIntegralReset = 1U;
      CTSO_CurrentIntegralDisable = 1U;
      CTSO_SpeedIntegralDisable = 1U;
      CTSO_SpeedIntegralReset = 1U;
      CTSO_SpeedCalcReset = 0U;
    } else if ((SGPP_MechSpeedAbsolute <= CTSO_SpeedLimit_C) &&
               (SGPP_IgnitionStatus == 0) && (SGPP_DcLinkVoltMeas <
                CTSO_VoltDischargeLowThr_C)) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_PowerDown;
      CTSO_PWMRequest_IRV = Off;
      CTSO_StOperMode = PowerDown;
    } else if (SGPP_DcLinkVoltMeas < CTSO_VoltDischargeLowThr_C) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_LowVoltReady;
      CTSO_StOperMode = LowVoltReady;
      CTSO_PWMRequest_IRV = Off;
      CTSO_CurrentIntegralReset = 1U;
      CTSO_CurrentIntegralDisable = 1U;
      CTSO_SpeedIntegralReset = 1U;
      CTSO_SpeedIntegralDisable = 1U;
      CTSO_SpeedCalcReset = 0U;
    }
    break;

   case CtlStateOrchestrator_IN_Fault:
    CTSO_PWMRequest_IRV = Off;
    CTSO_StOperMode = Fault;
    CTSO_CurrentIntegralReset = 1U;
    CTSO_CurrentIntegralDisable = 1U;
    if ((CTSO_FaultModeRequest_IRV == 0) && (CTSO_ModeSetpoint ==
         HighVoltStandby) && (SGPP_DcLinkVoltMeas > CTSO_MinVoltControl_C) &&
        (CTSO_DischargeFaultFlag == 0) && (CTSO_FaultRecoveryEnable_C == 1)) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_MainControl;
      CtlStateOrchestrator_DW.is_MainControl =
        CtlStateOrchestrator_IN_HighVoltReady;
      CTSO_StOperMode = HighVoltStandby;
      CTSO_SpeedIntegralReset = 1U;
      CTSO_SpeedIntegralDisable = 1U;
      CTSO_SpeedCalcReset = 0U;
    } else if ((SGPP_MechSpeedAbsolute <= CTSO_SpeedLimit_C) &&
               (SGPP_IgnitionStatus == 0)) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_PowerDown;
      CTSO_StOperMode = PowerDown;
    }
    break;

   case CtlStateOrchestrator_IN_Init:
    CTSO_StOperMode = Init;
    CTSO_PWMRequest_IRV = Off;
    CTSO_CurrentIntegralReset = 1U;
    CTSO_CurrentIntegralDisable = 1U;
    if (CTSO_FaultModeRequest_IRV == 1) {
      CtlStateOrchestrator_DW.TiInin = 0.0F;
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_Fault;
      CTSO_StOperMode = Fault;
      CTSO_SpeedIntegralDisable = 1U;
      CTSO_SpeedIntegralReset = 1U;
      CTSO_SpeedCalcReset = 0U;
    } else if (CtlStateOrchestrator_DW.CTSO_StInin == 1) {
      CtlStateOrchestrator_DW.TiInin = 0.0F;
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_LowVoltReady;
      CTSO_StOperMode = LowVoltReady;
      CTSO_SpeedIntegralReset = 1U;
      CTSO_SpeedIntegralDisable = 1U;
      CTSO_SpeedCalcReset = 0U;
    } else if ((CtlStateOrchestrator_DW.TiInin > CTSO_InitWaitTime_C) &&
               (SGSA_BswInit == 1)) {
      CtlStateOrchestrator_DW.CTSO_StInin = 1U;
    } else {
      CtlStateOrchestrator_DW.TiInin += SGPP_SampleTime2;
    }
    break;

   case CtlStateOrchestrator_IN_LowVoltReady:
    CTSO_StOperMode = LowVoltReady;
    CTSO_PWMRequest_IRV = Off;
    CTSO_CurrentIntegralReset = 1U;
    CTSO_CurrentIntegralDisable = 1U;
    if (CTSO_FaultModeRequest_IRV == 1) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_Fault;
      CTSO_StOperMode = Fault;
      CTSO_SpeedIntegralDisable = 1U;
      CTSO_SpeedIntegralReset = 1U;
      CTSO_SpeedCalcReset = 0U;
    } else if ((SGPP_DcLinkVoltMeas > CTSO_MinVoltControl_C) &&
               (SGPP_IgnitionStatus == 1)) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_MainControl;
      CtlStateOrchestrator_DW.is_MainControl =
        CtlStateOrchestrator_IN_HighVoltReady;
      CTSO_StOperMode = HighVoltStandby;
      CTSO_SpeedIntegralReset = 1U;
      CTSO_SpeedIntegralDisable = 1U;
      CTSO_SpeedCalcReset = 0U;
    } else if ((SGPP_MechSpeedAbsolute <= CTSO_SpeedLimit_C) &&
               (SGPP_IgnitionStatus == 0) && (SGPP_DcLinkVoltMeas <
                CTSO_VoltDischargeLowThr_C)) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_PowerDown;
      CTSO_StOperMode = PowerDown;
    }
    break;

   case CtlStateOrchestrator_IN_MainControl:
    CtlStateOrchestrator_MainControl(&DataTypeConversion, &DataTypeConversion_g,
      &CTSO_ModeSetpoint, &CTSO_StOperMode);
    break;

   default:
    /* case IN_PowerDown: */
    CTSO_PWMRequest_IRV = Off;
    CTSO_StOperMode = PowerDown;
    if (SGPP_IgnitionStatus == 1) {
      CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
        CtlStateOrchestrator_IN_Init;
      CTSO_StOperMode = Init;
      CtlStateOrchestrator_DW.CTSO_StInin = 0U;
      CtlStateOrchestrator_DW.TiInin = 0.0F;
      CTSO_CurrentIntegralReset = 1U;
      CTSO_CurrentIntegralDisable = 1U;
      CTSO_SpeedIntegralReset = 1U;
      CTSO_SpeedIntegralDisable = 1U;
    }
    break;
  }

  /* End of Chart: '<S2>/CtlModeChart' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  CTSO_OperationMode = CTSO_StOperMode;

  /* Update for Delay: '<S14>/Delay' incorporates:
   *  Inport: '<Root>/SGPP_IgnitionStatus'
   */
  CtlStateOrchestrator_DW.Delay_DSTATE_f = SGPP_IgnitionStatus;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/CTSO_ManageStateMode_1ms' */
}

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Model initialize function */
void CtlStateOrchestrator_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */

  /* custom signals */
  CTSO_PWMRequest_IRV = ((uint8_T)3U);

  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/CTSO_ManageStateMode_1ms' incorporates:
   *  SubSystem: '<Root>/CTSO_ManageStateMode_1ms_sys'
   */
  /* Chart: '<S2>/CtlModeChart' */
  CtlStateOrchestrator_DW.is_c3_CtlStateOrchestrator =
    CtlStateOrchestrator_IN_Init;
  CTSO_PWMRequest_IRV = Off;
  CtlStateOrchestrator_DW.TiInin = 0.0F;
  CTSO_CurrentIntegralReset = 1U;
  CTSO_CurrentIntegralDisable = 1U;
  CTSO_SpeedIntegralReset = 1U;
  CTSO_SpeedIntegralDisable = 1U;

  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/CTSO_ManageStateMode_1ms' */
}

/* Model terminate function */
void CtlStateOrchestrator_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
