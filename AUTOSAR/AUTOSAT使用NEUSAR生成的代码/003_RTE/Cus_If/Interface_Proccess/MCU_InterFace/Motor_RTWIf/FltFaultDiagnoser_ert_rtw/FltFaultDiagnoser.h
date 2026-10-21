/*
 * File: FltFaultDiagnoser.h
 *
 * Code generated for Simulink model 'FltFaultDiagnoser'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu May 28 16:38:06 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FltFaultDiagnoser_h_
#define RTW_HEADER_FltFaultDiagnoser_h_
#ifndef FltFaultDiagnoser_COMMON_INCLUDES_
#define FltFaultDiagnoser_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FltFaultDiagnoser_COMMON_INCLUDES_ */

#include "FltFaultDiagnoser_types.h"
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
  uint16_T BareUnitDelay_DSTATE;       /* '<S113>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_k;      /* '<S124>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_e[3];   /* '<S77>/Bare Unit Delay' */
  uint8_T UnitDelay_DSTATE;            /* '<S33>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_o;          /* '<S34>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_a;          /* '<S35>/Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_d;      /* '<S64>/Bare Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_o;      /* '<S67>/Bare Unit Delay' */
  uint8_T UnitDelay_DSTATE_k;          /* '<S24>/Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_e2;     /* '<S101>/Bare Unit Delay' */
  uint8_T UnitDelay_DSTATE_i;          /* '<S23>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_h;          /* '<S103>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_kt;         /* '<S32>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_ax;         /* '<S78>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_f;          /* '<S79>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_l;          /* '<S80>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_m;          /* '<S81>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_d;          /* '<S25>/Unit Delay' */
  uint8_T BareUnitDelay_DSTATE_p[3];   /* '<S14>/Bare Unit Delay' */
  boolean_T Delay_DSTATE;              /* '<S46>/Delay' */
  boolean_T Delay_DSTATE_b;            /* '<S47>/Delay' */
  boolean_T Delay_DSTATE_i;            /* '<S91>/Delay' */
  boolean_T Memory_PreviousInput;      /* '<S123>/Memory' */
  boolean_T Memory_PreviousInput_i[3]; /* '<S76>/Memory' */
  boolean_T Memory_PreviousInput_n;    /* '<S63>/Memory' */
  boolean_T Memory_PreviousInput_k;    /* '<S66>/Memory' */
  boolean_T Memory_PreviousInput_l;    /* '<S100>/Memory' */
  boolean_T Memory_PreviousInput_m;    /* '<S112>/Memory' */
  boolean_T Memory_PreviousInput_nc[3];/* '<S13>/Memory' */
} DW_FltFaultDiagnoser_T;

/* Real-time Model Data Structure */
struct tag_RTM_FltFaultDiagnoser_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_FltFaultDiagnoser_T FltFaultDiagnoser_DW;

/* Model entry point functions */
extern void FltFaultDiagnoser_initialize(void);
extern void FltFaultDiagnoser_terminate(void);

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void FLDG_DiagCurrentFast_100us(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void FLDG_DiagFaultResponse_1ms(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported entry point function */
#define MTRCTRL_START_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

extern void FLDG_DiagTempSlow_10ms(void);

#define MTRCTRL_STOP_SEC_CODE_DEFAULT
#include "MtrCtrl_MemMap.h"

/* Exported data declaration */
#define MTRCTRL_START_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Par */
extern volatile uint16_T FLDG_DebounceDecrDcVoltHi_C;/* Referenced by: '<S109>/Constant' */

/* Debounce decrement value for diagnostic of DC overvoltage */
extern volatile uint8_T FLDG_DebounceDecrInvTMonitor_C;/* Referenced by: '<S74>/Constant' */

/* Debounce decrement value for diagnostic of IGBT overtemperature */
extern volatile uint8_T FLDG_DebounceDecrPhaCur_C;/* Referenced by: '<S11>/Constant' */

/* Debounce decrement value for diagnostic of phase overcurrent */
extern volatile uint8_T FLDG_DebounceDecrResolverSpdMonitor_C;/* Referenced by:
                                                               * '<S51>/Constant'
                                                               * '<S58>/Constant'
                                                               * '<S97>/Constant'
                                                               */

/* Debounce decrement value for diagnostic of overspeed from position sensor */
extern volatile uint8_T FLDG_DebounceDecrWindingTMonitor_C;/* Referenced by: '<S121>/Constant' */

/* Debounce decrement value for winding temperatue monitoring */
extern volatile uint16_T FLDG_DebounceIncrDcVoltHi_C;/* Referenced by: '<S108>/Constant' */

/* Debounce increment value for diagnostic of DC overvoltage */
extern volatile uint8_T FLDG_DebounceIncrInvTMonitor_C;/* Referenced by: '<S73>/Constant' */

/* Debounce increment value for diagnostic of IGBT overtemperature */
extern volatile uint8_T FLDG_DebounceIncrPhaCur_C;/* Referenced by: '<S10>/Constant' */

/* Debounce increment value for diagnostic of phase overcurrent */
extern volatile uint8_T FLDG_DebounceIncrResolverSpdMonitor_C;/* Referenced by:
                                                               * '<S50>/Constant'
                                                               * '<S57>/Constant'
                                                               * '<S96>/Constant'
                                                               */

/* Debounce increment value for diagnostic of overspeed from position sensor */
extern volatile uint8_T FLDG_DebounceIncrWindingTMonitor_C;/* Referenced by: '<S120>/Constant' */

/* Debounce increment value for winding temperature monitoring */
extern volatile uint16_T FLDG_DebounceMaxDcVoltHi_C;/* Referenced by: '<S106>/Constant' */

/* Debounce maximum value for diagnostic of DC overvoltage */
extern volatile uint8_T FLDG_DebounceMaxInvTMonitor_C;/* Referenced by: '<S71>/Constant' */

/* Debounce maximum value for diagnostic of IGBT overtemperature */
extern volatile uint8_T FLDG_DebounceMaxPhaCur_C;/* Referenced by: '<S8>/Constant' */

/* Debounce maximum value for diagnostic of phase overcurrent */
extern volatile uint8_T FLDG_DebounceMaxResolverSpdMonitor_C;/* Referenced by:
                                                              * '<S55>/Constant'
                                                              * '<S61>/Constant'
                                                              * '<S94>/Constant'
                                                              */

/* Debounce maximum value for diagnostic of overspeed from position sensor */
extern volatile uint8_T FLDG_DebounceMaxWindingTMonitor_C;/* Referenced by: '<S118>/Constant' */

/* Debounce maximum value for winding temperature monitoring */
extern volatile uint16_T FLDG_DebounceMinDcVoltHi_C;/* Referenced by: '<S107>/Constant' */

/* Debounce minimum value for diagnostic of DC overvoltage */
extern volatile uint8_T FLDG_DebounceMinInvTMonitor_C;/* Referenced by: '<S72>/Constant' */

/* Debounce minimum value for diagnostic of IGBT overtemperature */
extern volatile uint8_T FLDG_DebounceMinPhaCur_C;/* Referenced by: '<S9>/Constant' */

/* Debounce minimum value for diagnostic of phase overcurrent */
extern volatile uint8_T FLDG_DebounceMinResolverSpdMonitor_C;/* Referenced by:
                                                              * '<S49>/Constant'
                                                              * '<S56>/Constant'
                                                              * '<S95>/Constant'
                                                              */

/* Debounce minimum value for diagnostic of overspeed from position sensor */
extern volatile uint8_T FLDG_DebounceMinWindingTMonitor_C;/* Referenced by: '<S119>/Constant' */

/* Debounce minimum value for winding temperature monitoring */
extern volatile uint8_T FLDG_EnableDiagHwDcLinkVoltDiag_C;/* Referenced by: '<S36>/Constant' */

/* Enable flag for hardware monitor DC link voltage diagnostic */
extern volatile uint8_T FLDG_EnableDiagHwErrPhaCurDiag_C;/* Referenced by: '<S38>/Constant' */

/* Enable flag for hardware monitor phase current diagnostic */
extern volatile uint8_T FLDG_EnableDiagHwFltHiSideB_C;/* Referenced by: '<S40>/Constant' */

/* Enable flag for hardware monitor DC fault B HS diagnostic */
extern volatile uint8_T FLDG_EnableDiagHwFltLoSideB_C;/* Referenced by: '<S42>/Constant' */

/* Enable flag for hardware monitor DC fault B LS diagnostic */
extern volatile uint8_T FLDG_EnableDiagResolverCosLosDiag_C;/* Referenced by: '<S86>/Constant' */

/* Enable flag for Resolver diagnostic of tracking */
extern volatile uint8_T FLDG_EnableDiagResolverDiagDos_C;/* Referenced by: '<S82>/Constant' */

/* Enable flag for Resolver diagnostic of phase lock range error */
extern volatile uint8_T FLDG_EnableDiagResolverDiagSigLot_C;/* Referenced by: '<S88>/Constant' */

/* Enable flag for Resolver diagnostic of LOS (loss of signal)  threshold */
extern volatile uint8_T FLDG_EnableDiagResolverSineLosDiag_C;/* Referenced by: '<S84>/Constant' */

/* Enable flag for Resolver diagnostic of velocity tracking rate */
extern volatile uint8_T FLDG_EnableShutdownReq_C;/* Referenced by:
                                                  * '<S26>/Constant'
                                                  * '<S28>/Constant'
                                                  * '<S30>/Constant'
                                                  */

/* Enable flag for shutdown request function */
extern volatile real32_T FLDG_IHiThr_C;/* Referenced by: '<S6>/Constant' */

/* Max permissible current */
extern volatile uint8_T FLDG_ResetDcDiagUHi_C;/* Referenced by: '<S105>/Constant' */

/* Reset for diagnostic of DC Link overvoltage */
extern volatile uint8_T FLDG_ResetDiagPhaCur_C;/* Referenced by: '<S7>/Constant' */

/* Reset for diagnostic of phase current */
extern volatile uint8_T FLDG_ResetInvTMonitor_C;/* Referenced by: '<S70>/Constant' */

/* Rst for Temperature monitoring of Inverter */
extern volatile uint8_T FLDG_ResetLatchDcVoltHi_C;/* Referenced by: '<S110>/Constant' */

/* Fault detection flag */
extern volatile uint8_T FLDG_ResetLatchHwDcLinkVolt_C;/* Referenced by: '<S37>/Constant' */

/* clear to enable latching. */
extern volatile uint8_T FLDG_ResetLatchHwFltLoSideB_C;/* Referenced by:
                                                       * '<S41>/Constant'
                                                       * '<S43>/Constant'
                                                       */

/* clear to enable latching. */
extern volatile uint8_T FLDG_ResetLatchHwPhaCur_C;/* Referenced by: '<S39>/Constant' */

/* clear to enable latching. */
extern volatile uint8_T FLDG_ResetLatchResolverCosLos_C;/* Referenced by: '<S87>/Constant' */

/* clear to enable latching. */
extern volatile uint8_T FLDG_ResetLatchResolverDos_C;/* Referenced by: '<S83>/Constant' */

/* clear to enable latching. */
extern volatile uint8_T FLDG_ResetLatchResolverSigLot_C;/* Referenced by: '<S89>/Constant' */

/* clear to enable latching. */
extern volatile uint8_T FLDG_ResetLatchResolverSineLos_C;/* Referenced by: '<S85>/Constant' */

/* clear to enable latching. */
extern volatile uint8_T FLDG_ResetLatchShutdownReq_C;/* Referenced by:
                                                      * '<S27>/Constant'
                                                      * '<S29>/Constant'
                                                      * '<S31>/Constant'
                                                      */

/* Reset control for shutdown request latched error functionality */
extern volatile uint8_T FLDG_ResetResolverNMonitor_C;/* Referenced by:
                                                      * '<S54>/Constant'
                                                      * '<S59>/Constant'
                                                      * '<S93>/Constant'
                                                      */

/* Reset for speed monitoring from position sensor */
extern volatile uint8_T FLDG_ResetWindingTMonitor_C;/* Referenced by: '<S117>/Constant' */

/* Reset for Temperature monitoring of Winding */
extern volatile real32_T FLDG_SpdResolverThrFaiRcvrr_C;/* Referenced by: '<S98>/Constant' */

/* over speed recovery Threshold */
extern volatile real32_T FLDG_SpdResolverThrFai_C;/* Referenced by: '<S92>/Constant' */

/* Threshold speed from position sensor above which the machine should be shut down */
extern volatile real32_T FLDG_TIgbtPha1Thr_C;/* Referenced by: '<S69>/Constant' */

/* Threshold value for power switch temperature at phase A */
extern volatile real32_T FLDG_TWindingThr_C;/* Referenced by: '<S116>/Constant' */

/* Winding temp above which error is set to 1 */
extern volatile real32_T FLDG_UBattVoltThrHiRcvrr_C;/* Referenced by: '<S53>/Constant' */

/* OVER voltage RECOVERY threshold of battery voltage */
extern volatile real32_T FLDG_UBattVoltThrHi_C;/* Referenced by: '<S52>/Constant' */

/* OVER voltage threshold of battery voltage */
extern volatile real32_T FLDG_UBattVoltThrLoRcvrr_C;/* Referenced by: '<S48>/Constant' */

/* UNDER voltage recovery threshold of battery voltage */
extern volatile real32_T FLDG_UBattVoltThrLo_C;/* Referenced by: '<S60>/Constant' */

/* Voltage at battery voltage below which a DEM error entry is set */
extern volatile real32_T FLDG_UDcThrHi_C;/* Referenced by: '<S104>/Constant' */

/* DC voltage above which error is set to 1 */
#define MTRCTRL_STOP_SEC_CALIB_UNSPECIFIED
#include "MtrCtrl_MemMap.h"
#define MTRCTRL_START_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Declaration for custom storage class: MtrCtrl_Sig */
extern uint8_T FLDG_ActiveShortHsReq;  /* '<S25>/Switch XOR' */

/* Active short circuit request for high-side switches */
extern uint8_T FLDG_BattVoltHiErr;     /* '<S66>/Data Type Conversion EveSt2' */

/* Fault detection active when the voltage at battery voltage is above a threshold value */
extern uint8_T FLDG_BattVoltLoErr;     /* '<S63>/Data Type Conversion EveSt2' */

/* Fault detection active when the voltage at battery voltage is below a threshold value */
extern uint8_T FLDG_DcVoltHiWarn;      /* '<S103>/Switch XOR' */

/* Warning flag is set when DC bus voltage is above the critical value */
extern uint8_T FLDG_DischargeErr;      /* '<S2>/CTSO_DischargeFaultFlag' */

/* Discharge Error */
extern uint8_T FLDG_HwDcLinkVoltErr;   /* '<S32>/Switch XOR' */

/* Scanned errors of hardware monitor Bit 9: DC link overvoltage */
extern uint8_T FLDG_HwHsShortErr;      /* '<S34>/Switch XOR' */

/* Scanned errors of hardware monitor Bit 11: Fault B HS */
extern uint8_T FLDG_HwLsShortErr;      /* '<S35>/Switch XOR' */

/* Scanned errors of hardware monitor Bit 14: Fault B LS */
extern uint8_T FLDG_HwPhaCurErr;       /* '<S33>/Switch XOR' */

/* hardware monitor Phase Current Error */
extern uint8_T FLDG_IgbtTemp1Err;      /* '<S18>/Signal Conversion' */

/* Fault detection active when power switch at phase A temperature above threshold value */
extern uint8_T FLDG_IgbtTemp2Err;      /* '<S18>/Signal Conversion1' */

/* Fault detection active when power switch at phase B temperature above threshold value */
extern uint8_T FLDG_IgbtTemp3Err;      /* '<S18>/Signal Conversion2' */

/* Fault detection active when power switch at phase C temperature above threshold value */
extern uint8_T FLDG_PhaCur1Err;        /* '<S4>/Signal Conversion' */

/* Fault indicator active when maximum allowable current at phase A is  exceeds limit */
extern uint8_T FLDG_PhaCur1Err_IRV;    /* '<S1>/OverCurrentDiag' */

/* Fault indicator active when maximum allowable current at phase A is  exceeds limit */
extern uint8_T FLDG_PhaCur2Err;        /* '<S4>/Signal Conversion1' */

/* Fault indicator active when maximum allowable current exceeds limit at phase B */
extern uint8_T FLDG_PhaCur2Err_IRV;    /* '<S1>/OverCurrentDiag' */

/* Fault indicator active when maximum allowable current exceeds limit at phase B */
extern uint8_T FLDG_PhaCur3Err;        /* '<S4>/Signal Conversion2' */

/* Fault indicator active when maximum allowable current exceeds limit at phase C */
extern uint8_T FLDG_PhaCur3Err_IRV;    /* '<S1>/OverCurrentDiag' */

/* Fault indicator active when maximum allowable current exceeds limit at phase C */
extern uint8_T FLDG_PowerSwitchOffReq; /* '<S24>/Switch XOR' */

/* Error reaction request for power switches off (freewheeling mode) */
extern uint8_T FLDG_ResolverCosLosErr; /* '<S80>/Switch XOR' */

/* Scanned errors of Resolver Bit 3: tracking error exceeds LOT (Loss of tracking) threshold */
extern uint8_T FLDG_ResolverDosErr;    /* '<S78>/Switch XOR' */

/* Scanned errors of Resolver Bit 1: phase error exceeds phase lock range */
extern uint8_T FLDG_ResolverError;     /* '<S19>/Data Type Conversion4' */

/* Resolver Error */
extern uint8_T FLDG_ResolverSigLotErr; /* '<S81>/Switch XOR' */

/* Scanned errors of Resolver Bit 6: sin/cos below LOS (loss of signa)l threshold */
extern uint8_T FLDG_ResolverSineLosErr;/* '<S79>/Switch XOR' */

/* Scanned errors of Resolver Bit 2: velocity exceeds maximum tracking rate */
extern uint8_T FLDG_ResolverSpdErr;   /* '<S100>/Data Type Conversion EveSt2' */

/* When the absolut value of measured rotor speed exceeds the maximum threshold value, this flag is set to one */
extern uint8_T FLDG_ShutdownReq;       /* '<S23>/Switch XOR' */

/* System shutdown request flag indicator */
extern uint8_T FLDG_WindingTempErr;   /* '<S123>/Data Type Conversion EveSt2' */

/* Fault detection active when motor winding temperature above threshold value */
extern uint8_T FLDG_WindingTempErr_IRV;/* '<S3>/MotorTemperatureDiag' */

/* Fault detection active when motor winding temperature above threshold value */
#define MTRCTRL_STOP_SEC_VAR_CLEAR_UNSPECIFIED
#include "MtrCtrl_MemMap.h"

/* Real-time Model object */
extern RT_MODEL_FltFaultDiagnoser_T *const FltFaultDiagnoser_M;

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
 * '<Root>' : 'FltFaultDiagnoser'
 * '<S1>'   : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys'
 * '<S2>'   : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys'
 * '<S3>'   : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys'
 * '<S4>'   : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag'
 * '<S5>'   : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/FaultDebounce'
 * '<S6>'   : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/Parameter1'
 * '<S7>'   : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/Parameter2'
 * '<S8>'   : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/Parameter3'
 * '<S9>'   : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/Parameter4'
 * '<S10>'  : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/Parameter5'
 * '<S11>'  : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/Parameter6'
 * '<S12>'  : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/FaultDebounce/Saturation Dynamic'
 * '<S13>'  : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/FaultDebounce/Subsystem'
 * '<S14>'  : 'FltFaultDiagnoser/FLDG_DiagCurrentFast_100us_sys/OverCurrentDiag/FaultDebounce/UnitDelay'
 * '<S15>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction'
 * '<S16>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch'
 * '<S17>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag'
 * '<S18>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag'
 * '<S19>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode'
 * '<S20>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag'
 * '<S21>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/Subsystem'
 * '<S22>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag'
 * '<S23>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/HoldLatch'
 * '<S24>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/HoldLatch1'
 * '<S25>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/HoldLatch2'
 * '<S26>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/Parameter1'
 * '<S27>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/Parameter2'
 * '<S28>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/Parameter3'
 * '<S29>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/Parameter4'
 * '<S30>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/Parameter5'
 * '<S31>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ErrorReaction/Parameter6'
 * '<S32>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/HoldLatch'
 * '<S33>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/HoldLatch1'
 * '<S34>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/HoldLatch2'
 * '<S35>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/HoldLatch3'
 * '<S36>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/Parameter1'
 * '<S37>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/Parameter2'
 * '<S38>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/Parameter3'
 * '<S39>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/Parameter4'
 * '<S40>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/Parameter5'
 * '<S41>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/Parameter6'
 * '<S42>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/Parameter7'
 * '<S43>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/HwFaultLatch/Parameter8'
 * '<S44>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/FaultDebounce'
 * '<S45>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/FaultDebounce1'
 * '<S46>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/HysteresisCtrl'
 * '<S47>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/HysteresisCtrl1'
 * '<S48>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter1'
 * '<S49>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter10'
 * '<S50>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter11'
 * '<S51>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter12'
 * '<S52>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter13'
 * '<S53>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter14'
 * '<S54>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter2'
 * '<S55>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter3'
 * '<S56>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter4'
 * '<S57>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter5'
 * '<S58>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter6'
 * '<S59>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter7'
 * '<S60>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter8'
 * '<S61>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/Parameter9'
 * '<S62>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/FaultDebounce/Saturation Dynamic'
 * '<S63>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/FaultDebounce/Subsystem'
 * '<S64>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/FaultDebounce/UnitDelay'
 * '<S65>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/FaultDebounce1/Saturation Dynamic'
 * '<S66>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/FaultDebounce1/Subsystem'
 * '<S67>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/KL30VoltageDiag/FaultDebounce1/UnitDelay'
 * '<S68>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/FaultDebounce'
 * '<S69>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/Parameter1'
 * '<S70>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/Parameter2'
 * '<S71>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/Parameter3'
 * '<S72>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/Parameter4'
 * '<S73>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/Parameter5'
 * '<S74>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/Parameter6'
 * '<S75>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/FaultDebounce/Saturation Dynamic'
 * '<S76>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/FaultDebounce/Subsystem'
 * '<S77>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/PowerModuleTemperatureDiag/FaultDebounce/UnitDelay'
 * '<S78>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/HoldLatch'
 * '<S79>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/HoldLatch1'
 * '<S80>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/HoldLatch2'
 * '<S81>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/HoldLatch3'
 * '<S82>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/Parameter1'
 * '<S83>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/Parameter2'
 * '<S84>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/Parameter3'
 * '<S85>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/Parameter4'
 * '<S86>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/Parameter5'
 * '<S87>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/Parameter6'
 * '<S88>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/Parameter7'
 * '<S89>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/ResolverFaultDecode/Parameter8'
 * '<S90>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/FaultDebounce'
 * '<S91>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/HysteresisCtrl'
 * '<S92>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/Parameter1'
 * '<S93>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/Parameter2'
 * '<S94>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/Parameter3'
 * '<S95>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/Parameter4'
 * '<S96>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/Parameter5'
 * '<S97>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/Parameter6'
 * '<S98>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/Parameter8'
 * '<S99>'  : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/FaultDebounce/Saturation Dynamic'
 * '<S100>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/FaultDebounce/Subsystem'
 * '<S101>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/SpeedDiag/FaultDebounce/UnitDelay'
 * '<S102>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/FaultDebounce'
 * '<S103>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/HoldLatch'
 * '<S104>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/Parameter1'
 * '<S105>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/Parameter2'
 * '<S106>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/Parameter3'
 * '<S107>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/Parameter4'
 * '<S108>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/Parameter5'
 * '<S109>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/Parameter6'
 * '<S110>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/Parameter7'
 * '<S111>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/FaultDebounce/Saturation Dynamic'
 * '<S112>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/FaultDebounce/Subsystem'
 * '<S113>' : 'FltFaultDiagnoser/FLDG_DiagFaultResponse_1ms_sys/UdcVoltageDiag/FaultDebounce/UnitDelay'
 * '<S114>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag'
 * '<S115>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/FaultDebounce'
 * '<S116>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/Parameter1'
 * '<S117>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/Parameter2'
 * '<S118>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/Parameter3'
 * '<S119>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/Parameter4'
 * '<S120>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/Parameter5'
 * '<S121>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/Parameter6'
 * '<S122>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/FaultDebounce/Saturation Dynamic'
 * '<S123>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/FaultDebounce/Subsystem'
 * '<S124>' : 'FltFaultDiagnoser/FLDG_DiagTempSlow_10ms_sys/MotorTemperatureDiag/FaultDebounce/UnitDelay'
 */
#endif                                 /* RTW_HEADER_FltFaultDiagnoser_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
