/*
 * File: swc_HMIF.c
 *
 * Code generated for Simulink model 'swc_HMIF'.
 *
 * Model version                  : 6.412
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Sep  9 19:15:42 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_HMIF.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include "const_ImportedDefine.h"
#include "const_ImportFromFile.h"
#include "zero_crossing_types.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef DSP_TASK_INTERVAL_S
#error The value of parameter "DSP_TASK_INTERVAL_S" is not defined
#endif

#ifndef NmRPM_2_KW
#error The value of parameter "NmRPM_2_KW" is not defined
#endif

#ifndef PWR_ZERO
#error The value of parameter "PWR_ZERO" is not defined
#endif

#ifndef VEH_SWT_INF
#error The value of parameter "VEH_SWT_INF" is not defined
#endif

/* Named constants for Chart: '<S197>/timed_delay' */
#define swc_HMIF_IN_OFF                ((uint8)1U)
#define swc_HMIF_IN_ON                 ((uint8)2U)
#define swc_HMIF_IN_ON_WAIT            ((uint8)3U)

/* Named constants for Chart: '<S39>/timed_delay' */
#define swc_HMIF_IN_OFF_WAIT           ((uint8)2U)
#define swc_HMIF_IN_OFF_f              ((uint8)1U)
#define swc_HMIF_IN_ON_p               ((uint8)3U)

/* Named constants for Chart: '<S7>/odometerbackup' */
#define swc_HMIF_IN_backup_off         ((uint8)1U)
#define swc_HMIF_IN_backup_unable      ((uint8)2U)
#define swc_HMIF_IN_enable             ((uint8)3U)
#define swc_HMIF_IN_init               ((uint8)4U)

/* Named constants for Chart: '<S8>/OdometerAdd' */
#define swc_HMIF_IN_Add                ((uint8)1U)
#define swc_HMIF_IN_CntAdd             ((uint8)1U)
#define swc_HMIF_IN_Delay              ((uint8)2U)
#define swc_HMIF_IN_Keep               ((uint8)3U)
#define swc_HMIF_IN_Stop               ((uint8)4U)
#define swc_HMIF_IN_clear              ((uint8)2U)
#define swc_HMIF_IN_init_k             ((uint8)5U)

/* Named constants for Chart: '<S8>/OdometerBackup1' */
#define swc_HMIF_IN_BackupChange       ((uint8)1U)
#define swc_HMIF_IN_BackupHold         ((uint8)2U)
#define swc_HMIF_IN_Delay_g            ((uint8)3U)
#define swc_HMIF_IN_Init               ((uint8)4U)
#define swc_HMIF_IN_ReadNvm            ((uint8)5U)
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Exported data definition */
#define swc_HMIF_START_SEC_CONST_VOLATILE
#include "swc_HMIF_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean ddic_b_BMSHealthMonErr_ovrdflg = false;/* Referenced by: '<S130>/DFC_ovrdflg' */
const volatile boolean ddic_b_BMSHealthMonErr_ovrdval = false;/* Referenced by: '<S130>/DFC_ovrdval' */
const volatile boolean ddic_b_MCUHealthMonErr_ovrdflg = false;/* Referenced by: '<S90>/DFC_ovrdflg' */
const volatile boolean ddic_b_MCUHealthMonErr_ovrdval = false;/* Referenced by: '<S90>/DFC_ovrdval' */
const volatile boolean ddic_b_VacPumpRlyErr_ovrdflg = false;/* Referenced by: '<S127>/DFC_ovrdflg' */
const volatile boolean ddic_b_VacPumpRlyErr_ovrdval = false;/* Referenced by: '<S127>/DFC_ovrdval' */
const volatile boolean ddic_b_evtFaildVacPumpLoPre_ovrdflg = false;/* Referenced by: '<S123>/DFC_ovrdflg' */
const volatile boolean ddic_b_evtFaildVacPumpLoPre_ovrdval = false;/* Referenced by: '<S123>/DFC_ovrdval' */
const volatile boolean ddic_b_evtFaildVacPumpSnr_ovrdflg = false;/* Referenced by: '<S122>/DFC_ovrdflg' */
const volatile boolean ddic_b_evtFaildVacPumpSnr_ovrdval = false;/* Referenced by: '<S122>/DFC_ovrdval' */
const volatile boolean ddic_b_evtFaildVpEnOvTmHiPre_ovrdflg = false;/* Referenced by: '<S124>/DFC_ovrdflg' */
const volatile boolean ddic_b_evtFaildVpEnOvTmHiPre_ovrdval = false;/* Referenced by: '<S124>/DFC_ovrdval' */
const volatile boolean ddic_b_evtFaildVpEnOvTmLoPre_ovrdflg = false;/* Referenced by: '<S125>/DFC_ovrdflg' */
const volatile boolean ddic_b_evtFaildVpEnOvTmLoPre_ovrdval = false;/* Referenced by: '<S125>/DFC_ovrdval' */
const volatile boolean ddic_b_evtFaildVpSysFail_ovrdflg = false;/* Referenced by: '<S126>/DFC_ovrdflg' */
const volatile boolean ddic_b_evtFaildVpSysFail_ovrdval = false;/* Referenced by: '<S126>/DFC_ovrdval' */
const volatile float32 dspc_FCHiHEVRange_mlps = 10.0F;/* Referenced by: '<S6>/Relay2' */

/* fuel consumption high for HEV range calculation */
const volatile float32 dspc_FCLoHEVRange_mlps = 6.0F;/* Referenced by: '<S6>/Relay2' */

/* fuel consumption low for HEV range calculation */
const volatile float32 dspc_X_rngAct[12] = { 9.0F, 10.0F, 11.0F, 12.0F, 13.0F,
  14.0F, 15.0F, 16.0F, 17.0F, 18.0F, 19.0F, 20.0F } ;/* Referenced by:
                                                      * '<S68>/1-D Lookup Table1'
                                                      * '<S51>/1-D Lookup Table1'
                                                      */

const volatile float32 dspc_Y_rngVarFactor[12] = { 0.0F, 0.0F, 0.1F, 0.2F, 0.3F,
  0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F } ;/* Referenced by:
                                               * '<S68>/1-D Lookup Table1'
                                               * '<S51>/1-D Lookup Table1'
                                               */

const volatile boolean dspc_b_ACUMsgErr_ovrdflg = false;/* Referenced by: '<S91>/DFC_ovrdflg' */
const volatile boolean dspc_b_ACUMsgErr_ovrdval = false;/* Referenced by: '<S91>/DFC_ovrdval' */
const volatile boolean dspc_b_CSMMsgErr_ovrdflg = false;/* Referenced by: '<S110>/DFC_ovrdflg' */
const volatile boolean dspc_b_CSMMsgErr_ovrdval = false;/* Referenced by: '<S110>/DFC_ovrdval' */
const volatile boolean dspc_b_EDCPBlockingSet_ovrdflg = false;/* Referenced by: '<S102>/DFC_ovrdflg' */
const volatile boolean dspc_b_EDCPBlockingSet_ovrdval = false;/* Referenced by: '<S102>/DFC_ovrdval' */
const volatile boolean dspc_b_EDCPIdlySet_ovrdflg = false;/* Referenced by: '<S99>/DFC_ovrdflg' */
const volatile boolean dspc_b_EDCPIdlySet_ovrdval = false;/* Referenced by: '<S99>/DFC_ovrdval' */
const volatile boolean dspc_b_EDCPOverCurrSet_ovrdflg = false;/* Referenced by: '<S98>/DFC_ovrdflg' */
const volatile boolean dspc_b_EDCPOverCurrSet_ovrdval = false;/* Referenced by: '<S98>/DFC_ovrdval' */
const volatile boolean dspc_b_EDCPOverTempSet_ovrdflg = false;/* Referenced by: '<S97>/DFC_ovrdflg' */
const volatile boolean dspc_b_EDCPOverTempSet_ovrdval = false;/* Referenced by: '<S97>/DFC_ovrdval' */
const volatile boolean dspc_b_EDCPOverVoltSet_ovrdflg = false;/* Referenced by: '<S100>/DFC_ovrdflg' */
const volatile boolean dspc_b_EDCPOverVoltSet_ovrdval = false;/* Referenced by: '<S100>/DFC_ovrdval' */
const volatile boolean dspc_b_EDCPUnderVoltSet_ovrdflg = false;/* Referenced by: '<S101>/DFC_ovrdflg' */
const volatile boolean dspc_b_EDCPUnderVoltSet_ovrdval = false;/* Referenced by: '<S101>/DFC_ovrdval' */
const volatile boolean dspc_b_FCAllAlowed = false;/* Referenced by:
                                                   * '<S6>/Constant3'
                                                   * '<S6>/Constant6'
                                                   */

/* allow to calculate HEV range according to FC level */
const volatile boolean dspc_b_PEPSMsgInvDataErr_ovrdflg = false;/* Referenced by: '<S109>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_PEPSMsgCntErr */
const volatile boolean dspc_b_PEPSMsgInvDataErr_ovrdval = false;/* Referenced by: '<S109>/DFC_ovrdval' */

/* Override value for DFC_HYB_PEPSMsgCntErr */
const volatile boolean dspc_b_enaDisplayEVinGear = true;/* Referenced by: '<S247>/Constant1' */

/* Display EV mode when Gear Lever Position is R/D/S */
const volatile boolean dspc_b_evtFaildABSMsgErr_ovrdflg = false;/* Referenced by: '<S135>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ABSMsgErr */
const volatile boolean dspc_b_evtFaildABSSpdMsgErr_ovrdflg = false;/* Referenced by: '<S92>/DFC_ovrdflg' */

/* Override value for DFC_HYB_ABSSpdMsgErr */
const volatile boolean dspc_b_evtFaildABSSpdMsgErr_ovrdval = false;/* Referenced by: '<S92>/DFC_ovrdval' */

/* Override flag for DFC_HYB_ABSSpdMsgErr */
const volatile boolean dspc_b_evtFaildACCPedal1ORHigh_ovrdflg = false;/* Referenced by: '<S134>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal1ORHigh */
const volatile boolean dspc_b_evtFaildACCPedal1ORHigh_ovrdval = false;/* Referenced by: '<S134>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal1ORHigh */
const volatile boolean dspc_b_evtFaildACCPedal1ORLow_ovrdflg = false;/* Referenced by: '<S133>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal1ORLow */
const volatile boolean dspc_b_evtFaildACCPedal1ORLow_ovrdval = false;/* Referenced by: '<S133>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal1ORLow */
const volatile boolean dspc_b_evtFaildACCPedal1SCB_ovrdflg = false;/* Referenced by: '<S132>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal1SCB */
const volatile boolean dspc_b_evtFaildACCPedal1SCB_ovrdval = false;/* Referenced by: '<S132>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal1SCB */
const volatile boolean dspc_b_evtFaildACCPedal1SCG_ovrdflg = false;/* Referenced by: '<S131>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal1SCG */
const volatile boolean dspc_b_evtFaildACCPedal1SCG_ovrdval = false;/* Referenced by: '<S131>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal1SCG */
const volatile boolean dspc_b_evtFaildACCPedal2ORHigh_ovrdflg = false;/* Referenced by: '<S139>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal2ORHigh */
const volatile boolean dspc_b_evtFaildACCPedal2ORHigh_ovrdval = false;/* Referenced by: '<S139>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal2ORHigh */
const volatile boolean dspc_b_evtFaildACCPedal2ORLow_ovrdflg = false;/* Referenced by: '<S138>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal2ORLow */
const volatile boolean dspc_b_evtFaildACCPedal2ORLow_ovrdval = false;/* Referenced by: '<S138>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal2ORLow */
const volatile boolean dspc_b_evtFaildACCPedal2SCB_ovrdflg = false;/* Referenced by: '<S137>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal2SCB */
const volatile boolean dspc_b_evtFaildACCPedal2SCB_ovrdval = false;/* Referenced by: '<S137>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal2SCB */
const volatile boolean dspc_b_evtFaildACCPedal2SCG_ovrdflg = false;/* Referenced by: '<S136>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal2SCG */
const volatile boolean dspc_b_evtFaildACCPedal2SCG_ovrdval = false;/* Referenced by: '<S136>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal2SCG */
const volatile boolean dspc_b_evtFaildACCPedalCrossNP_ovrdflg = false;/* Referenced by: '<S111>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedalCrossNP */
const volatile boolean dspc_b_evtFaildACCPedalCrossNP_ovrdval = false;/* Referenced by: '<S111>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedalCrossNP */
const volatile boolean dspc_b_evtFaildBMSFaultLevel2A_ovrdflg = false;/* Referenced by: '<S119>/DFC_ovrdflg' */
const volatile boolean dspc_b_evtFaildBMSFaultLevel2A_ovrdval = false;/* Referenced by: '<S119>/DFC_ovrdval' */
const volatile boolean dspc_b_evtFaildBMSFaultLevel3A_ovrdflg = false;/* Referenced by: '<S112>/DFC_ovrdflg' */
const volatile boolean dspc_b_evtFaildBMSFaultLevel3A_ovrdval = false;/* Referenced by: '<S112>/DFC_ovrdval' */
const volatile boolean dspc_b_evtFaildBMSFaultLevel4A_ovrdflg = false;/* Referenced by: '<S128>/DFC_ovrdflg' */
const volatile boolean dspc_b_evtFaildBMSFaultLevel4A_ovrdval = false;/* Referenced by: '<S128>/DFC_ovrdval' */
const volatile boolean dspc_b_evtFaildBrkSthNP_ovrdflg = false;/* Referenced by: '<S114>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_BrkSthNP */
const volatile boolean dspc_b_evtFaildBrkSthNP_ovrdval = false;/* Referenced by: '<S114>/DFC_ovrdval' */

/* Override value for DFC_HYB_BrkSthNP */
const volatile boolean dspc_b_evtFaildCrashEvent_ovrdflg = false;/* Referenced by: '<S117>/DFC_ovrdflg' */

/* Override value for DFC_HYB_CrashEvent */
const volatile boolean dspc_b_evtFaildCrashEvent_ovrdval = false;/* Referenced by: '<S117>/DFC_ovrdval' */

/* Override flag for DFC_HYB_CrashEvent */
const volatile boolean dspc_b_evtFaildEGSMMsgErr_ovrdflg = false;/* Referenced by: '<S140>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_EGSMMsgErr */
const volatile boolean dspc_b_evtFaildEGSMMsgErr_ovrdval = false;/* Referenced by: '<S140>/DFC_ovrdval' */

/* Override value for DFC_HYB_EGSMMsgErr */
const volatile boolean dspc_b_evtFaildEPCANBusoff_ovrdflg = false;/* Referenced by: '<S94>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_EPCANBusoff */
const volatile boolean dspc_b_evtFaildEPCANBusoff_ovrdval = false;/* Referenced by: '<S94>/DFC_ovrdval' */

/* Override value for DFC_HYB_EPCANBusoff */
const volatile boolean dspc_b_evtFaildEVCANBusoff_ovrdflg = false;/* Referenced by: '<S121>/DFC_ovrdflg' */
const volatile boolean dspc_b_evtFaildEVCANBusoff_ovrdval = false;/* Referenced by: '<S121>/DFC_ovrdval' */
const volatile boolean dspc_b_evtFaildMCUFaultLevel2A_ovrdflg = false;/* Referenced by: '<S113>/DFC_ovrdflg' */
const volatile boolean dspc_b_evtFaildMCUFaultLevel2A_ovrdval = false;/* Referenced by: '<S113>/DFC_ovrdval' */
const volatile boolean dspc_b_evtFaildMCUFaultLevel3A_ovrdflg = false;/* Referenced by: '<S120>/DFC_ovrdflg' */
const volatile boolean dspc_b_evtFaildMCUFaultLevel3A_ovrdval = false;/* Referenced by: '<S120>/DFC_ovrdval' */
const volatile boolean dspc_b_evtFaildPwrSuplyORHigh_ovrdflg = false;/* Referenced by: '<S118>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_PwrSuplyORHigh */
const volatile boolean dspc_b_evtFaildPwrSuplyORHigh_ovrdval = false;/* Referenced by: '<S118>/DFC_ovrdval' */

/* Override value for DFC_HYB_PwrSuplyORHigh */
const volatile boolean dspc_b_evtFaildPwrSuplyORLow_ovrdflg = false;/* Referenced by: '<S116>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_PwrSuplyORLow */
const volatile boolean dspc_b_evtFaildPwrSuplyORLow_ovrdval = false;/* Referenced by: '<S116>/DFC_ovrdval' */

/* Override value for DFC_HYB_PwrSuplyORLow */
const volatile boolean dspc_b_evtFaildT5V1Mon_ovrdflg = false;/* Referenced by: '<S93>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_T5V1Mon */
const volatile boolean dspc_b_evtFaildT5V1Mon_ovrdval = false;/* Referenced by: '<S93>/DFC_ovrdval' */

/* Override value for DFC_HYB_T5V1Mon */
const volatile boolean dspc_b_evtFaildT5V2Mon_ovrdflg = false;/* Referenced by: '<S96>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_T5V2Mon */
const volatile boolean dspc_b_evtFaildT5V2Mon_ovrdval = false;/* Referenced by: '<S96>/DFC_ovrdval' */

/* Override value for DFC_HYB_T5V2Mon */
const volatile boolean dspc_b_evtFaildTPCANBusoff_ovrdflg = false;/* Referenced by: '<S95>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_TPCANBusoff */
const volatile boolean dspc_b_evtFaildTPCANBusoff_ovrdval = false;/* Referenced by: '<S95>/DFC_ovrdval' */

/* Override value for DFC_HYB_TPCANBusoff */
const volatile boolean dspc_b_evtFaildVehicleHVILFlt_ovrdflg = false;/* Referenced by: '<S115>/DFC_ovrdflg' */

/* Override value for DFC_HYB_VehicleHVILFlt */
const volatile boolean dspc_b_evtFaildVehicleHVILFlt_ovrdval = false;/* Referenced by: '<S115>/DFC_ovrdval' */

/* Override flag for DFC_HYB_VehicleHVILFlt */
const volatile boolean dspc_b_hbcpBlock_ovrdflg = false;/* Referenced by: '<S107>/DFC_ovrdflg' */
const volatile boolean dspc_b_hbcpBlock_ovrdval = false;/* Referenced by: '<S107>/DFC_ovrdval' */
const volatile boolean dspc_b_hbcpIdly_ovrdflg = false;/* Referenced by: '<S104>/DFC_ovrdflg' */
const volatile boolean dspc_b_hbcpIdly_ovrdval = false;/* Referenced by: '<S104>/DFC_ovrdval' */
const volatile boolean dspc_b_hbcpOvrCurr_ovrdflg = false;/* Referenced by: '<S108>/DFC_ovrdflg' */
const volatile boolean dspc_b_hbcpOvrCurr_ovrdval = false;/* Referenced by: '<S108>/DFC_ovrdval' */
const volatile boolean dspc_b_hbcpOvrTmp_ovrdflg = false;/* Referenced by: '<S105>/DFC_ovrdflg' */
const volatile boolean dspc_b_hbcpOvrTmp_ovrdval = false;/* Referenced by: '<S105>/DFC_ovrdval' */
const volatile boolean dspc_b_hbcpOvrVolt_ovrdflg = false;/* Referenced by: '<S106>/DFC_ovrdflg' */
const volatile boolean dspc_b_hbcpOvrVolt_ovrdval = false;/* Referenced by: '<S106>/DFC_ovrdval' */
const volatile boolean dspc_b_hbcpUdVolt_ovrdflg = false;/* Referenced by: '<S103>/DFC_ovrdflg' */
const volatile boolean dspc_b_hbcpUdVolt_ovrdval = false;/* Referenced by: '<S103>/DFC_ovrdval' */
const volatile boolean dspc_b_nvmDataWriteAec_ovrdflg = false;
                     /* Referenced by: '<S41>/dspc_b_nvmDataWriteAec_ovrdflg' */
const volatile boolean dspc_b_odoClearCntOvrdFlg = false;/* Referenced by: '<S8>/Constant17' */
const volatile boolean dspc_b_phevOvrEvBtn = true;/* Referenced by: '<S13>/Constant3' */

/* PHEV hybrid powertrain mode overrides the EV button press for the purposes of determining the Drive Mode */
const volatile boolean dspc_b_sportModDspEnb = true;/* Referenced by: '<S13>/Constant7' */
const volatile boolean dspc_b_useFuelRateForFC = true;/* Referenced by: '<S218>/Constant1' */

/* Use Fuel Rate for FC calculation */
const volatile float32 dspc_d_aecCellMileage_km = 1.0F;/* Referenced by: '<S27>/Constant16' */
const volatile float32 dspc_d_odoBckpDiff_km = 300.0F;/* Referenced by:
                                                       * '<S8>/Constant15'
                                                       * '<S8>/Constant16'
                                                       */
const volatile float32 dspc_d_odoWriteSet_km = 20.0F;/* Referenced by: '<S206>/Constant17' */
const volatile float32 dspc_d_storedDynRange = 20.0F;/* Referenced by: '<S68>/Constant' */
const volatile float32 dspc_d_vehDrvRngInvalid_km = 1023.0F;
                                 /* Referenced by: '<S65>/InvalidValue_0X3FF' */
const volatile float32 dspc_d_vehDrvRngStdInvalid = 4095.0F;
                                 /* Referenced by: '<S38>/InvalidValue_0XFFF' */
const volatile float32 dspc_dn_RngDecGradH = -50000.0F;/* Referenced by:
                                                        * '<S65>/Constant24'
                                                        * '<S38>/Constant24'
                                                        */
const volatile float32 dspc_dn_RngDecGradL = -0.067F;/* Referenced by: '<S65>/Constant27' */
const volatile float32 dspc_dn_RngIncGradH = 50000.0F;/* Referenced by:
                                                       * '<S65>/Constant13'
                                                       * '<S38>/Constant13'
                                                       */
const volatile float32 dspc_dn_RngIncGradL = 0.067F;/* Referenced by: '<S65>/Constant26' */
const volatile float32 dspc_dn_StdRngDecGradL = -0.1F;/* Referenced by: '<S38>/Constant27' */
const volatile float32 dspc_dn_StdRngIncGradL = 0.1F;/* Referenced by: '<S38>/Constant26' */
const volatile float32 dspc_dn_aecDecGrad_kWhp100km = -20000.0F;/* Referenced by: '<S27>/Constant14' */

/* AEC decrease gradient */
const volatile float32 dspc_dn_aecIncGrad_kWhp100km = 20000.0F;/* Referenced by: '<S27>/Constant13' */

/* AEC increase gradient */
const volatile DisplayLampMode dspc_e_lampMode = DisplayLampMode_DriverMode;/* Referenced by: '<S220>/Constant' */

/* Lamp lighting strategy choice */
const volatile float32 dspc_num_AecMin_kWhp100km = 1.0F;/* Referenced by:
                                                         * '<S27>/Constant1'
                                                         * '<S27>/Unit Delay3'
                                                         */

/* AEC Cell Minimum Value */
const volatile float32 dspc_num_nvmDataWriteAec_ovrdval = 0.0F;
                   /* Referenced by: '<S41>/dspc_num_nvmDataWriteAec_ovrdval' */
const volatile float32 dspc_pwr_AECHiLimit = 35.0F;/* Referenced by:
                                                    * '<S36>/Constant1'
                                                    * '<S44>/Constant'
                                                    */
const volatile float32 dspc_pwr_AECLowLimit = 10.0F;/* Referenced by:
                                                     * '<S36>/Constant'
                                                     * '<S43>/Constant'
                                                     */
const volatile float32 dspc_pwr_eadActiveThold_kW = 0.05F;/* Referenced by: '<S14>/Constant2' */

/* Threshold for ICU to consider the EAD active */
const volatile float32 dspc_q_socLowAcDnThd = 10.0F;/* Referenced by: '<S3>/Relay' */
const volatile float32 dspc_q_socLowAcUpThd = 15.0F;/* Referenced by: '<S3>/Relay' */
const volatile boolean dspc_st_odoClearCntOvrdVal = false;/* Referenced by: '<S8>/Constant' */
const volatile float32 dspc_t_ipkOdoBckUp_s = 5.0F;/* Referenced by: '<S7>/Constant19' */
const volatile float32 dspc_tm_DisplayTime_s = 2.0F;/* Referenced by: '<S5>/Constant_disp' */

/* Display time threshold */
const volatile float32 dspc_tm_FCFilter_s = 0.2F;/* Referenced by: '<S218>/Constant7' */

/* Fuel Consumption Time constant filter */
const volatile float32 dspc_tm_HEVRangeFilter_s = 0.2F;/* Referenced by: '<S6>/Constant1' */

/* HEV range Time constant filter */
const volatile float32 dspc_tm_bcmOdoDebd_s = 0.5F;/* Referenced by: '<S8>/Constant11' */
const volatile float32 dspc_tm_drRngDelay = 400.0F;/* Referenced by:
                                                    * '<S40>/Constant1'
                                                    * '<S69>/Constant1'
                                                    * '<S52>/Constant1'
                                                    * '<S53>/Constant1'
                                                    */
const volatile float32 dspc_tm_hvPwrCsmptFilter_s = 0.2F;/* Referenced by: '<S23>/Constant15' */

/* HV power consumption constant filter */
const volatile float32 dspc_tm_ipkOdoDebd_s = 1.0F;/* Referenced by: '<S8>/Constant10' */
const volatile float32 dspc_tm_nvmReadHold_s = 0.0F;/* Referenced by: '<S27>/Constant8' */
const volatile float32 dspc_tm_rangeCrtnwkUpDly = 450.0F;/* Referenced by:
                                                          * '<S76>/Constant1'
                                                          * '<S61>/Constant1'
                                                          */
const volatile float32 dspc_tq_motorActiveThold = 1.0F;/* Referenced by: '<S14>/Constant1' */

/* Threshold for ICU to consider the EAD active */
const volatile float32 dspc_v_defaultVehSpdforFC_kph = 18.35F;/* Referenced by: '<S9>/Constant4' */

/* default vehicle speed for average fuel consumption calculation */
const volatile float32 dspc_v_dfltVehSpdHEVRange_kph = 18.35F;/* Referenced by: '<S6>/Constant5' */

/* default vehicle speed for HEV range */
const volatile float32 dspc_v_vehSpdHiFC_kph = 10.0F;/* Referenced by: '<S9>/Relay1' */

/* vehicle speed high for average fuel consumption calculation */
const volatile float32 dspc_v_vehSpdHiHEVRange_kph = 10.0F;/* Referenced by: '<S6>/Relay3' */

/* vehicle speed high for HEV range calculation */
const volatile float32 dspc_v_vehSpdLoFC_kph = 6.0F;/* Referenced by: '<S9>/Relay1' */

/* vehicle speed low for average fuel consumption calculation */
const volatile float32 dspc_v_vehSpdLoHEVRange_kph = 6.0F;/* Referenced by: '<S6>/Relay3' */

/* vehicle speed low for HEV range calculation */
const volatile float32 dspc_v_vehStopSpd_kph = 3.0F;/* Referenced by: '<S27>/Constant25' */
const volatile boolean dspd_b_odoTotal2NVM_ovrdflg = false;/* Referenced by: '<S8>/Constant23' */
const volatile float32 dspd_b_odoTotal2NVM_ovrdval = 20.0F;/* Referenced by: '<S8>/Constant22' */
const volatile float32 dspd_d_distRange = 500.0F;/* Referenced by: '<S8>/Constant30' */
const volatile float32 dspd_num_AecLowLim = 10.0F;/* Referenced by: '<S32>/Constant1' */
const volatile float32 dspd_num_AecUpLim = 30.0F;/* Referenced by: '<S32>/Constant9' */
const volatile float32 dspv_SOCDisplayMap_X_SOC_pct[8] = { 0.0F, 20.0F, 34.0F,
  48.0F, 62.0F, 76.0F, 90.0F, 100.0F } ;
                                   /* Referenced by: '<S10>/1-D Lookup Table' */

/* SOC Display Map - Battery SOC Axis */
const volatile float32 dspv_SOCDisplayMap_Y_pct[8] = { 0.0F, 20.0F, 34.0F, 48.0F,
  62.0F, 76.0F, 90.0F, 100.0F } ;  /* Referenced by: '<S10>/1-D Lookup Table' */

/* SOC Display Map - Displayed SOC */
const volatile boolean swchmif_ddic_b_evtFaildABSMsgErr_ovrdval = false;/* Referenced by: '<S135>/DFC_ovrdval' */

/* Override value for DFC_HYB_ABSMsgErr */
const volatile boolean swchmif_ddic_b_evtFaildDCDCMsgErr_ovrdflg = false;/* Referenced by: '<S129>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_DCDCMsgErr */
const volatile boolean swchmif_ddic_b_evtFaildDCDCMsgErr_ovrdval = false;/* Referenced by: '<S129>/DFC_ovrdval' */

/* Override value for DFC_HYB_DCDCMsgErr */
#define swc_HMIF_STOP_SEC_CONST_VOLATILE
#include "swc_HMIF_MemMap.h"
#define swc_HMIF_START_SEC_VAR
#include "swc_HMIF_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
float32 Aec1;                          /* '<S27>/RollingAverage' */

/* AEC1 */
float32 Aec10;                         /* '<S27>/RollingAverage' */

/* AEC10 */
float32 Aec2;                          /* '<S27>/RollingAverage' */

/* AEC2 */
float32 Aec3;                          /* '<S27>/RollingAverage' */

/* AEC3 */
float32 Aec4;                          /* '<S27>/RollingAverage' */

/* AEC4 */
float32 Aec5;                          /* '<S27>/RollingAverage' */

/* AEC5 */
float32 Aec6;                          /* '<S27>/RollingAverage' */

/* AEC6 */
float32 Aec7;                          /* '<S27>/RollingAverage' */

/* AEC7 */
float32 Aec8;                          /* '<S27>/RollingAverage' */

/* AEC8 */
float32 Aec9;                          /* '<S27>/RollingAverage' */

/* AEC9 */
uint8 Cntr;                            /* '<S27>/RollingAverage' */

/* AEC Rolling Average Counter */
uint8 dspd_ST;                         /* '<S8>/OdometerAdd' */
float32 dspd_V_engFuelConsAvg_lp100km; /* '<S9>/Divide' */

/* average fuel consumption in L/100km  */
boolean dspd_b_ABSMsgErr;              /* '<S186>/Switch2' */

/* Lost Communication with ABS */
boolean dspd_b_ABSSpdMsgErr;           /* '<S143>/Switch2' */

/* DFC_HYB_ABSSpdMsgErr Fault */
boolean dspd_b_ACCPedal1ORHigh;        /* '<S185>/Switch2' */

/* Throttle Position Sensor/Switch "G" Circuit Range/Performance */
boolean dspd_b_ACCPedal1ORLow;         /* '<S184>/Switch2' */

/* Throttle Position Sensor/Switch "G" Circuit Range/Performance */
boolean dspd_b_ACCPedal1SCB;           /* '<S183>/Switch2' */

/* DFC_HYB_ACCPedal1SCB Fault */
boolean dspd_b_ACCPedal1SCG;           /* '<S182>/Switch2' */

/* DFC_HYB_ACCPedal1SCG Fault */
boolean dspd_b_ACCPedal2ORHigh;        /* '<S190>/Switch2' */

/* Throttle/Pedal Position Sensor/Switch "F" Circuit Range/Performance */
boolean dspd_b_ACCPedal2ORLow;         /* '<S189>/Switch2' */

/* Throttle/Pedal Position Sensor/Switch "F" Circuit Range/Performance */
boolean dspd_b_ACCPedal2SCB;           /* '<S188>/Switch2' */

/* DFC_HYB_ACCPedal2SCB Fault */
boolean dspd_b_ACCPedal2SCG;           /* '<S187>/Switch2' */

/* DFC_HYB_ACCPedal2SCG Fault */
boolean dspd_b_ACCPedalCrossNP;        /* '<S162>/Switch2' */

/* Throttle/Pedal Position Sensor/Switch "F"/"G" Voltage Correlation */
boolean dspd_b_ACUMsgErr;              /* '<S142>/Switch2' */
boolean dspd_b_BMSFaultLevel2;         /* '<S170>/Switch2' */
boolean dspd_b_BMSHealthMonErr;        /* '<S181>/Switch2' */
boolean dspd_b_BrkSthNP;               /* '<S165>/Switch2' */

/* Brake Switch "A"/"B" Correlation */
boolean dspd_b_CSMMsgErr;              /* '<S161>/Switch2' */
boolean dspd_b_CrashEvent;             /* '<S168>/Switch2' */
boolean dspd_b_DCDCMsgErr;             /* '<S180>/Switch2' */

/* Lost Communication with DCDC */
boolean dspd_b_EDCPBlocking;           /* '<S153>/Switch2' */

/* DFC_HYB_EDCP Blocking protection */
boolean dspd_b_EDCPIdly;               /* '<S150>/Switch2' */

/* DFC_HYB_EDCP Idly protection */
boolean dspd_b_EDCPOverCurr;           /* '<S149>/Switch2' */

/* DFC_HYB_EDCP Overcurrent protection */
boolean dspd_b_EDCPOverTemp;           /* '<S148>/Switch2' */

/* DFC_HYB_EDCP Over temp protection */
boolean dspd_b_EDCPOverVolt;           /* '<S151>/Switch2' */

/* DFC_HYB_EDCP Overpressure protection */
boolean dspd_b_EDCPUnderVolt;          /* '<S152>/Switch2' */

/* DFC_HYB_EDCP Undervoltage protection */
boolean dspd_b_EGSMMsgErr;             /* '<S191>/Switch2' */

/* Lost Communication with EGSM */
boolean dspd_b_EPCANBusoff;            /* '<S145>/Switch2' */

/* DFC_HYB_EPCANBusoff Fault */
boolean dspd_b_EVCANBusoff;            /* '<S172>/Switch2' */
boolean dspd_b_HBCPBlock;              /* '<S158>/Switch2' */

/* DFC_HYB_HBCP Blocking protection */
boolean dspd_b_HBCPOvrCurr;            /* '<S159>/Switch2' */

/* DFC_HYB_HBCP Overcurrent protection */
boolean dspd_b_HBCPOvrTmp;             /* '<S156>/Switch2' */

/* DFC_HYB_HBCP Overpressure protection */
boolean dspd_b_HBCPOvrVolt;            /* '<S157>/Switch2' */

/* DFC_HYB_HBCP Overpressure protection */
boolean dspd_b_HBCPUdVolt;             /* '<S154>/Switch2' */

/* DFC_HYB_HBCP Overpressure protection */
boolean dspd_b_HazardReqLmpOn;         /* '<S192>/Logical Operator3' */
boolean dspd_b_HbcpIdly;               /* '<S155>/Switch2' */

/* DFC_HYB_HBCP Idly protection */
boolean dspd_b_MCUFaultLevel2;         /* '<S164>/Switch2' */
boolean dspd_b_MCUHealthMonErr;        /* '<S141>/Switch2' */
boolean dspd_b_OdoAddEn;               /* '<S8>/Logical Operator' */
boolean dspd_b_PEPSMsgInvDataErr;      /* '<S160>/Switch2' */

/* PEPS_PMSTrqCtrl Counter Error */
boolean dspd_b_PwrSuplyORHigh;         /* '<S169>/Switch2' */

/* System Voltage High */
boolean dspd_b_PwrSuplyORLow;          /* '<S167>/Switch2' */

/* System Voltage Low */
uint8 dspd_b_RoutineResultSet;         /* '<S8>/Switch7' */
boolean dspd_b_T5V1Mon;                /* '<S144>/Switch2' */

/* Sensor Reference Voltage "1" Circuit/Open */
boolean dspd_b_T5V2Mon;                /* '<S147>/Switch2' */

/* Sensor Reference Voltage "2" Circuit/Open */
boolean dspd_b_TPCANBusoff;            /* '<S146>/Switch2' */

/* DFC_HYB_TPCANBusoff Fault */
boolean dspd_b_VacPumpEnOvrTmHiPreFlt; /* '<S175>/Switch2' */
boolean dspd_b_VacPumpEnOvrTmLoPreFlt; /* '<S176>/Switch2' */
boolean dspd_b_VacPumpLoPreFlt;        /* '<S174>/Switch2' */
boolean dspd_b_VacPumpRlyErr;          /* '<S178>/Switch2' */
boolean dspd_b_VacPumpSnrFlt;          /* '<S173>/Switch2' */
boolean dspd_b_VacPumpSysFailFlt;      /* '<S177>/Switch2' */
boolean dspd_b_VehicleHVILFlt;         /* '<S166>/Switch2' */
boolean dspd_b_bcmOdoValid;            /* '<S8>/Logical Operator2' */
boolean dspd_b_bmsFltLvl3;             /* '<S163>/Switch2' */

/* BMS Fault Level 3 */
boolean dspd_b_bmsFltLvl4;             /* '<S179>/Switch2' */
boolean dspd_b_brkSysFlt;              /* '<S81>/Logical Operator8' */

/* Brake System Fault */
boolean dspd_b_ePTFault;               /* '<S82>/Logical Operator8' */
boolean dspd_b_evLampOn;               /* '<S11>/Logical Operator2' */
boolean dspd_b_hevLampOn;              /* '<S11>/Logical Operator1' */
boolean dspd_b_ignOFFodoWriteEn;       /* '<S204>/FixPt Relational Operator' */
boolean dspd_b_ipkOdoValid;            /* '<S8>/Logical Operator1' */
boolean dspd_b_mcuFltLvl3;             /* '<S171>/Switch2' */

/* Motor Fault Level 3 */
boolean dspd_b_odoBckpChgValid;        /* '<S8>/Logical Operator3' */
boolean dspd_b_odoBckpEn;              /* '<S8>/OdometerBackup1' */
boolean dspd_b_odoClearActv;           /* '<S8>/C Caller' */
boolean dspd_b_odoWriteEn;             /* '<S8>/OR' */
boolean dspd_b_rtStorageEn;            /* '<S206>/Relational Operator11' */
boolean dspd_b_turtleLmpOn;            /* '<S83>/Logical Operator7' */
float32 dspd_dV_engFuelConsInst_mlps;  /* '<S219>/Data Type Conversion3' */

/* instantaneous fuel consumption in ml/s  */
float64 dspd_d_MileageInit;            /* '<S8>/Switch10' */
float32 dspd_d_dynRngMapVal;           /* '<S68>/Product' */
float32 dspd_d_dynamicRange;           /* '<S64>/Switch1' */
float64 dspd_d_odoBckp_km;             /* '<S8>/OdometerBackup1' */
float32 dspd_d_odoRead_float;          /* '<S8>/Switch' */
float32 dspd_d_odoRead_km;             /* '<S8>/Max' */
float32 dspd_d_odoRead_u32;            /* '<S8>/Switch5' */
float32 dspd_d_odoTotal_km;            /* '<S8>/Switch1' */
float32 dspd_d_odoWrite_km;            /* '<S8>/Switch3' */
float32 dspd_d_pmsOdoBckUpMilg_km;     /* '<S7>/Data Type Conversion1' */

/* pms Odo BackUp Mileage */
float32 dspd_d_standardRange;          /* '<S37>/Switch9' */
float32 dspd_d_stdRng2NVM;             /* '<S47>/Switch1' */
float32 dspd_d_stdRngDecRate;          /* '<S47>/Switch4' */
float32 dspd_d_stdRngLatVal;           /* '<S47>/Switch' */
float32 dspd_d_stdRngMapVal;           /* '<S51>/Product' */
float32 dspd_d_vehDrvRngDynamic_km;    /* '<S24>/Divide5' */
float32 dspd_d_vehDrvRngEVMod_km;      /* '<S65>/Switch4' */

/* Drive Range in EV Mode */
float32 dspd_d_vehDrvRngHEVModUnfilt_km;/* '<S6>/Switch1' */

/* Unfiltered Drive Range in HEV Mode */
float32 dspd_d_vehDrvRngHEVMod_km;     /* '<S193>/Data Type Conversion3' */

/* Drive Range in HEV Mode */
float32 dspd_d_vehDrvRngStandardRaw_km;/* '<S27>/Product1' */
float32 dspd_d_vehDrvRngStandard_km;   /* '<S38>/Switch10' */
PowerFlowMode dspd_e_vehPwrFlow;       /* '<S14>/Switch' */
float32 dspd_num_AecCell_kWhp100km;    /* '<S36>/Switch1' */

/* AEC Cell in EV Mode */
float32 dspd_num_AecEV_kWhp100km;      /* '<S27>/Switch1' */

/* AEC in EV Mode */
float32 dspd_num_AecInit_kWhp100km;    /* '<S37>/Constant10' */
float32 dspd_num_AecRaw_kWhp100km;     /* '<S27>/RollingAverage' */

/* AEC Raw in EV Mode */
float32 dspd_num_errorCode;            /* '<S5>/Data Type Conversion' */

/* Error code */
float32 dspd_num_nvmDataReadAec;       /* '<S27>/C Caller25' */
float32 dspd_num_nvmDataWriteAec;      /* '<S42>/Switch2' */
float32 dspd_pwr_hvPwrCsmpt_kW;        /* '<S26>/Data Type Conversion3' */

/* HV power consumption */
float32 dspd_pwr_hvPwrRemain_kW;       /* '<S25>/MinMax2' */

/* HV power remain */
uint8 dspd_st_drvModInd;               /* '<S13>/Switch7' */
uint16 dspd_st_drvPfmncRedn;           /* '<S77>/Switch4' */
uint8 dspd_st_drvrOptRmdr;             /* '<S3>/Multiport Switch' */
uint8 dspd_st_nvmMileageClrCnt;        /* '<S8>/C Caller3' */
uint8 dspd_st_odoClrCntRead;           /* '<S8>/Switch4' */
uint8 dspd_st_odoClrCntWrite;          /* '<S8>/Switch2' */
uint8 dspd_st_vehDrvMode;              /* '<S13>/Switch9' */
uint8 dspd_st_vehFailLvl;              /* '<S12>/maxerrlevel1' */
uint8 dspd_st_vehSubFailLvl;           /* '<S12>/maxerrlevel2' */
float64 dspd_v_vehSpd;                 /* '<S8>/Data Type Conversion2' */

#define swc_HMIF_STOP_SEC_VAR
#include "swc_HMIF_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_HMIF_T swc_HMIF_ConstB = {
  0.0,                                 /* '<Root>/Data Type Conversion127' */
  0U,                                  /* '<S7>/Data Type Conversion2' */
  1                                    /* '<S3>/Logical Operator10' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_HMIF_T swc_HMIF_ARID_DEF;
static float32 look1_iflf_binlxpw(float32 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex);
static float32 look1_iflf_binlcapw(float32 u0, const float32 bp0[], const
  float32 table[], uint32 maxIndex);
static void swc_HMIF_CsmptEngyCal(float32 rtu_CsmptEngy_kW, boolean rtu_Pause,
  boolean rtu_Reset, float32 *rty_CsmptEngyTotal_kWh,
  ARID_DEF_CsmptEngyCal_swc_HMI_T *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_MileageCal(float32 rtu_Spd_kph, boolean rtu_Pause, boolean
  rtu_Reset, float32 *rty_Mileage_km, ARID_DEF_MileageCal_swc_HMIF_T
  *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_Subsystem_Init(boolean *rty_Out1,
  ARID_DEF_Subsystem_swc_HMIF_T *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_Subsystem_Reset(ARID_DEF_Subsystem_swc_HMIF_T
  *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_Subsystem_Disable(ARID_DEF_Subsystem_swc_HMIF_T
  *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_Subsystem(boolean rtu_Enable, boolean *rty_Out1,
  ARID_DEF_Subsystem_swc_HMIF_T *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_HMIF_T *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_Subsystem_l_Init(boolean *rty_Out1,
  ARID_DEF_Subsystem_swc_HMIF_h_T *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_Subsystem_g_Reset(ARID_DEF_Subsystem_swc_HMIF_h_T
  *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_Subsystem_m_Disable(ARID_DEF_Subsystem_swc_HMIF_h_T
  *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_Subsystem_d(boolean rtu_Enable, boolean *rty_Out1,
  ARID_DEF_Subsystem_swc_HMIF_h_T *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_SR_latch_k(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HMIF_h_T *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_turnON_delay_Init(boolean *rty_flg_out);
static void swc_HMIF_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_HMI_T
  *swc_HMIF__ARID_DEF_arg);
static void swc_HMIF_DSP_Display_Init(void);
static void swc_HMIF_DSP_Display_Const(void);
static void swc_HMIF_DSP_Display(void);
static float32 look1_iflf_binlxpw(float32 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex)
{
  float32 frac;
  float32 yL_0d0;
  uint32 iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32 bpIdx;
    uint32 iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

static float32 look1_iflf_binlcapw(float32 u0, const float32 bp0[], const
  float32 table[], uint32 maxIndex)
{
  float32 frac;
  float32 y;
  uint32 iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    uint32 bpIdx;
    uint32 iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'portable wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    float32 yL_0d0;
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

/* Output and update for atomic system: '<S27>/CsmptEngyCal' */
static void swc_HMIF_CsmptEngyCal(float32 rtu_CsmptEngy_kW, boolean rtu_Pause,
  boolean rtu_Reset, float32 *rty_CsmptEngyTotal_kWh,
  ARID_DEF_CsmptEngyCal_swc_HMI_T *swc_HMIF__ARID_DEF_arg)
{
  float32 rtb_Switch8_j;

  /* Switch: '<S30>/Switch8' */
  if (rtu_Pause) {
    /* Switch: '<S30>/Switch8' incorporates:
     *  Constant: '<S30>/Constant27'
     */
    rtb_Switch8_j = 0.0F;
  } else {
    /* Switch: '<S30>/Switch8' incorporates:
     *  Constant: '<S30>/Constant20'
     *  Constant: '<S30>/Constant21'
     *  Product: '<S30>/Divide1'
     */
    rtb_Switch8_j = rtu_CsmptEngy_kW * ((float32)DSP_TASK_INTERVAL_S) / 3600.0F;
  }

  /* End of Switch: '<S30>/Switch8' */

  /* Switch: '<S30>/Switch2' incorporates:
   *  Constant: '<S30>/Constant'
   *  UnitDelay: '<S30>/UnitDelay3'
   */
  if (rtu_Reset) {
    *rty_CsmptEngyTotal_kWh = 0.0F;
  } else {
    *rty_CsmptEngyTotal_kWh = swc_HMIF__ARID_DEF_arg->UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* Update for UnitDelay: '<S30>/UnitDelay3' incorporates:
   *  Sum: '<S30>/Sum6'
   */
  swc_HMIF__ARID_DEF_arg->UnitDelay3_DSTATE = rtb_Switch8_j +
    *rty_CsmptEngyTotal_kWh;
}

/* Output and update for atomic system: '<S27>/MileageCal' */
static void swc_HMIF_MileageCal(float32 rtu_Spd_kph, boolean rtu_Pause, boolean
  rtu_Reset, float32 *rty_Mileage_km, ARID_DEF_MileageCal_swc_HMIF_T
  *swc_HMIF__ARID_DEF_arg)
{
  float32 rtb_Switch8_p;

  /* Switch: '<S33>/Switch8' */
  if (rtu_Pause) {
    /* Switch: '<S33>/Switch8' incorporates:
     *  Constant: '<S33>/Constant27'
     */
    rtb_Switch8_p = 0.0F;
  } else {
    /* Switch: '<S33>/Switch8' incorporates:
     *  Constant: '<S33>/Constant20'
     *  Constant: '<S33>/Constant21'
     *  Product: '<S33>/Divide1'
     */
    rtb_Switch8_p = rtu_Spd_kph * ((float32)DSP_TASK_INTERVAL_S) / 3600.0F;
  }

  /* End of Switch: '<S33>/Switch8' */

  /* Switch: '<S33>/Switch2' incorporates:
   *  Constant: '<S33>/Constant'
   *  UnitDelay: '<S33>/UnitDelay3'
   */
  if (rtu_Reset) {
    *rty_Mileage_km = 0.0F;
  } else {
    *rty_Mileage_km = swc_HMIF__ARID_DEF_arg->UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S33>/Switch2' */

  /* Update for UnitDelay: '<S33>/UnitDelay3' incorporates:
   *  Sum: '<S33>/Sum6'
   */
  swc_HMIF__ARID_DEF_arg->UnitDelay3_DSTATE = rtb_Switch8_p + *rty_Mileage_km;
}

/*
 * System initialize for enable system:
 *    '<S46>/Subsystem'
 *    '<S66>/Subsystem'
 */
static void swc_HMIF_Subsystem_Init(boolean *rty_Out1,
  ARID_DEF_Subsystem_swc_HMIF_T *swc_HMIF__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay5' */
  swc_HMIF__ARID_DEF_arg->UnitDelay5_DSTATE = 0.0;

  /* SystemInitialize for Outport: '<S53>/Out1' */
  *rty_Out1 = true;
}

/*
 * System reset for enable system:
 *    '<S46>/Subsystem'
 *    '<S66>/Subsystem'
 */
static void swc_HMIF_Subsystem_Reset(ARID_DEF_Subsystem_swc_HMIF_T
  *swc_HMIF__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay5' */
  swc_HMIF__ARID_DEF_arg->UnitDelay5_DSTATE = 0.0;
}

/*
 * Disable for enable system:
 *    '<S46>/Subsystem'
 *    '<S66>/Subsystem'
 */
static void swc_HMIF_Subsystem_Disable(ARID_DEF_Subsystem_swc_HMIF_T
  *swc_HMIF__ARID_DEF_arg)
{
  swc_HMIF__ARID_DEF_arg->Subsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S46>/Subsystem'
 *    '<S66>/Subsystem'
 */
static void swc_HMIF_Subsystem(boolean rtu_Enable, boolean *rty_Out1,
  ARID_DEF_Subsystem_swc_HMIF_T *swc_HMIF__ARID_DEF_arg)
{
  /* Outputs for Enabled SubSystem: '<S46>/Subsystem' incorporates:
   *  EnablePort: '<S53>/Enable'
   */
  if (rtu_Enable) {
    float64 rtb_Add7_k;
    if (!swc_HMIF__ARID_DEF_arg->Subsystem_MODE) {
      swc_HMIF_Subsystem_Reset(swc_HMIF__ARID_DEF_arg);
      swc_HMIF__ARID_DEF_arg->Subsystem_MODE = true;
    }

    /* Sum: '<S53>/Add7' incorporates:
     *  Constant: '<S53>/Constant'
     *  UnitDelay: '<S53>/Unit Delay5'
     */
    rtb_Add7_k = 1.0 + swc_HMIF__ARID_DEF_arg->UnitDelay5_DSTATE;

    /* RelationalOperator: '<S53>/Relational Operator' incorporates:
     *  Constant: '<S53>/Constant1'
     */
    *rty_Out1 = (dspc_tm_drRngDelay > rtb_Add7_k);

    /* Update for UnitDelay: '<S53>/Unit Delay5' */
    swc_HMIF__ARID_DEF_arg->UnitDelay5_DSTATE = rtb_Add7_k;
  } else if (swc_HMIF__ARID_DEF_arg->Subsystem_MODE) {
    swc_HMIF_Subsystem_Disable(swc_HMIF__ARID_DEF_arg);
  }

  /* End of Outputs for SubSystem: '<S46>/Subsystem' */
}

/*
 * Output and update for atomic system:
 *    '<S47>/SR_latch'
 *    '<S77>/SR_latch1'
 */
static void swc_HMIF_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch_swc_HMIF_T *swc_HMIF__ARID_DEF_arg)
{
  /* Logic: '<S54>/Logical Operator3' incorporates:
   *  Logic: '<S54>/Logical Operator'
   *  Logic: '<S54>/Logical Operator1'
   *  UnitDelay: '<S54>/Unit Delay'
   */
  *rty_flg_out = ((swc_HMIF__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  swc_HMIF__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * System initialize for enable system:
 *    '<S56>/Subsystem'
 *    '<S70>/Subsystem'
 */
static void swc_HMIF_Subsystem_l_Init(boolean *rty_Out1,
  ARID_DEF_Subsystem_swc_HMIF_h_T *swc_HMIF__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay5' */
  swc_HMIF__ARID_DEF_arg->UnitDelay5_DSTATE = 0.0;

  /* SystemInitialize for Outport: '<S61>/Out1' */
  *rty_Out1 = true;
}

/*
 * System reset for enable system:
 *    '<S56>/Subsystem'
 *    '<S70>/Subsystem'
 */
static void swc_HMIF_Subsystem_g_Reset(ARID_DEF_Subsystem_swc_HMIF_h_T
  *swc_HMIF__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S61>/Unit Delay5' */
  swc_HMIF__ARID_DEF_arg->UnitDelay5_DSTATE = 0.0;
}

/*
 * Disable for enable system:
 *    '<S56>/Subsystem'
 *    '<S70>/Subsystem'
 */
static void swc_HMIF_Subsystem_m_Disable(ARID_DEF_Subsystem_swc_HMIF_h_T
  *swc_HMIF__ARID_DEF_arg)
{
  swc_HMIF__ARID_DEF_arg->Subsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S56>/Subsystem'
 *    '<S70>/Subsystem'
 */
static void swc_HMIF_Subsystem_d(boolean rtu_Enable, boolean *rty_Out1,
  ARID_DEF_Subsystem_swc_HMIF_h_T *swc_HMIF__ARID_DEF_arg)
{
  /* Outputs for Enabled SubSystem: '<S56>/Subsystem' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  if (rtu_Enable) {
    float64 rtb_Add7_n;
    if (!swc_HMIF__ARID_DEF_arg->Subsystem_MODE) {
      swc_HMIF_Subsystem_g_Reset(swc_HMIF__ARID_DEF_arg);
      swc_HMIF__ARID_DEF_arg->Subsystem_MODE = true;
    }

    /* Sum: '<S61>/Add7' incorporates:
     *  Constant: '<S61>/Constant'
     *  UnitDelay: '<S61>/Unit Delay5'
     */
    rtb_Add7_n = 1.0 + swc_HMIF__ARID_DEF_arg->UnitDelay5_DSTATE;

    /* RelationalOperator: '<S61>/Relational Operator' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    *rty_Out1 = (dspc_tm_rangeCrtnwkUpDly > rtb_Add7_n);

    /* Update for UnitDelay: '<S61>/Unit Delay5' */
    swc_HMIF__ARID_DEF_arg->UnitDelay5_DSTATE = rtb_Add7_n;
  } else if (swc_HMIF__ARID_DEF_arg->Subsystem_MODE) {
    swc_HMIF_Subsystem_m_Disable(swc_HMIF__ARID_DEF_arg);
  }

  /* End of Outputs for SubSystem: '<S56>/Subsystem' */
}

/* Output and update for atomic system: '<S80>/SR_latch' */
static void swc_HMIF_SR_latch_k(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HMIF_h_T *swc_HMIF__ARID_DEF_arg)
{
  /* Logic: '<S192>/Logical Operator3' incorporates:
   *  Logic: '<S192>/Logical Operator'
   *  Logic: '<S192>/Logical Operator1'
   *  UnitDelay: '<S192>/Unit Delay'
   */
  dspd_b_HazardReqLmpOn = ((swc_HMIF__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S192>/Unit Delay' */
  swc_HMIF__ARID_DEF_arg->UnitDelay_DSTATE = dspd_b_HazardReqLmpOn;
}

/*
 * System initialize for atomic system:
 *    '<S7>/turnON_delay'
 *    '<S8>/turnON_delay1'
 *    '<S8>/turnON_delay2'
 */
static void swc_HMIF_turnON_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S197>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S7>/turnON_delay'
 *    '<S8>/turnON_delay1'
 *    '<S8>/turnON_delay2'
 */
static void swc_HMIF_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_HMI_T
  *swc_HMIF__ARID_DEF_arg)
{
  float32 rtb_t_delay_on;

  /* Saturate: '<S197>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S197>/Saturation' */
    rtb_t_delay_on = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S197>/Saturation' */
    rtb_t_delay_on = 0.0F;
  } else {
    /* Saturate: '<S197>/Saturation' */
    rtb_t_delay_on = rtu_t_delay_on;
  }

  /* End of Saturate: '<S197>/Saturation' */

  /* Chart: '<S197>/timed_delay' incorporates:
   *  DataTypeConversion: '<S197>/Data Type Conversion'
   */
  if (swc_HMIF__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_HMIF__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_HMIF__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HMIF_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_HMIF__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HMIF_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_HMIF__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib) {
     case swc_HMIF_IN_OFF:
      if (rtu_flg_in) {
        if (rtb_t_delay_on == 0.0F) {
          swc_HMIF__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HMIF_IN_ON;
          *rty_flg_out = true;
        } else {
          swc_HMIF__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
            swc_HMIF_IN_ON_WAIT;
          swc_HMIF__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_HMIF_IN_ON:
      if (!rtu_flg_in) {
        swc_HMIF__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HMIF_IN_OFF;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_HMIF__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HMIF_IN_OFF;
        *rty_flg_out = false;
      } else if (swc_HMIF__ARID_DEF_arg->t_wait > rtb_t_delay_on - rtu_t_step) {
        swc_HMIF__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HMIF_IN_ON;
        *rty_flg_out = true;
      } else {
        swc_HMIF__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S197>/timed_delay' */
}

/* System initialize for function-call system: '<S1>/DSP_Display' */
static void swc_HMIF_DSP_Display_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out;
  boolean rtb_flg_out_m;
  boolean rtb_flg_out_e;

  /* InitializeConditions for UnitDelay: '<S26>/init' */
  swc_HMIF_ARID_DEF.init_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_h = true;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay1' */
  swc_HMIF_ARID_DEF.UnitDelay1_DSTATE_m = true;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay6' */
  swc_HMIF_ARID_DEF.UnitDelay6_DSTATE = true;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay3' */
  swc_HMIF_ARID_DEF.UnitDelay3_DSTATE = dspc_num_AecMin_kWhp100km;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay5' */
  swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_j = true;

  /* InitializeConditions for Delay: '<S47>/Delay1' */
  swc_HMIF_ARID_DEF.Delay1_DSTATE_g = true;

  /* InitializeConditions for Delay: '<S47>/Delay3' */
  swc_HMIF_ARID_DEF.Delay3_DSTATE[0] = true;
  swc_HMIF_ARID_DEF.Delay3_DSTATE[1] = true;

  /* InitializeConditions for UnitDelay: '<S58>/init' */
  swc_HMIF_ARID_DEF.init_DSTATE_e = true;

  /* InitializeConditions for UnitDelay: '<S73>/init' */
  swc_HMIF_ARID_DEF.init_DSTATE_a = true;

  /* InitializeConditions for UnitDelay: '<S219>/init' */
  swc_HMIF_ARID_DEF.init_DSTATE_j = true;

  /* InitializeConditions for UnitDelay: '<S193>/init' */
  swc_HMIF_ARID_DEF.init_DSTATE_o = true;

  /* SystemInitialize for Enabled SubSystem: '<S66>/Subsystem' */
  swc_HMIF_Subsystem_Init(&swc_HMIF_ARID_DEF.RelationalOperator_d,
    &swc_HMIF_ARID_DEF.ARID_DEF_Subsystem_m);

  /* End of SystemInitialize for SubSystem: '<S66>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S46>/Subsystem' */
  swc_HMIF_Subsystem_Init(&swc_HMIF_ARID_DEF.RelationalOperator_o,
    &swc_HMIF_ARID_DEF.ARID_DEF_Subsystem_cx);

  /* End of SystemInitialize for SubSystem: '<S46>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S45>/Subsystem' */
  /* InitializeConditions for UnitDelay: '<S52>/Unit Delay5' */
  swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_o = 0.0;

  /* End of SystemInitialize for SubSystem: '<S45>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S56>/Subsystem' */
  swc_HMIF_Subsystem_l_Init(&swc_HMIF_ARID_DEF.RelationalOperator_n,
    &swc_HMIF_ARID_DEF.ARID_DEF_Subsystem_c);

  /* End of SystemInitialize for SubSystem: '<S56>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S70>/Subsystem' */
  swc_HMIF_Subsystem_l_Init(&swc_HMIF_ARID_DEF.RelationalOperator_p,
    &swc_HMIF_ARID_DEF.ARID_DEF_Subsystem);

  /* End of SystemInitialize for SubSystem: '<S70>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S8>/turnON_delay1' */
  swc_HMIF_turnON_delay_Init(&rtb_flg_out_m);

  /* End of SystemInitialize for SubSystem: '<S8>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S8>/turnON_delay2' */
  swc_HMIF_turnON_delay_Init(&rtb_flg_out);

  /* End of SystemInitialize for SubSystem: '<S8>/turnON_delay2' */

  /* SystemInitialize for Enabled SubSystem: '<S88>/Subsystem' */
  /* InitializeConditions for UnitDelay: '<S89>/Unit Delay5' */
  swc_HMIF_ARID_DEF.UnitDelay5_DSTATE = 0.0;

  /* End of SystemInitialize for SubSystem: '<S88>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S7>/turnON_delay' */
  swc_HMIF_turnON_delay_Init(&rtb_flg_out_e);

  /* End of SystemInitialize for SubSystem: '<S7>/turnON_delay' */

  /* SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem' */
  /* InitializeConditions for Delay: '<S206>/Delay' */
  swc_HMIF_ARID_DEF.Delay_DSTATE_d = 0.0;

  /* End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem' */
}

/* Output and update for function-call system: '<S1>/DSP_Display' */
static void swc_HMIF_DSP_Display(void)
{
  /* local block i/o variables */
  float32 rtb_Switch2_p;
  float32 rtb_Switch1;
  boolean rtb_RelationalOperator4;
  boolean rtb_UnitDelay1_p;
  boolean rtb_UnitDelay6;
  boolean rtb_Delay3;
  boolean rtb_OR_h;
  boolean rtb_RelationalOperator3_p;
  boolean rtb_RelationalOperator5;
  boolean rtb_RelationalOperator8;
  boolean rtb_LogicalOperator1;
  boolean rtb_LogicalOperator7;
  boolean rtb_RelationalOperator_j;
  boolean rtb_RelationalOperator1_f;
  boolean rtb_Compare_a;
  boolean rtb_flg_out;
  boolean rtb_flg_out_m;
  boolean rtb_flg_out_e;
  boolean rtb_LogicalOperator3_d;
  float64 rtb_Add7_g;
  sint32 entryg1;
  sint32 i_0;
  float32 rtb_Add_k;
  float32 rtb_CCaller1;
  float32 rtb_DataTypeConversion1;
  float32 rtb_Divide_l;
  float32 rtb_Gain1;
  float32 rtb_Relay;
  float32 rtb_uDLookupTable1;
  uint32 maxV;
  uint32 rtb_CCaller2;
  uint32 rtb_Product;
  uint16 rtb_TmpSignalConversionAtSFunct[51];
  uint16 i;
  uint16 rtb_dspd_num_errorCode;
  HEVModeReq rtb_OR_a_tmp;
  PmmStatus rtb_RelationalOperator_j_tmp;
  ValueTol rtb_tol_type;
  ValueTol rtb_tol_type_k;
  uint8 rtb_DataTypeConversion2_l;
  uint8 rtb_Switch_h;
  boolean tmpForInput_tmp[51];
  boolean rtb_Compare_av;
  boolean rtb_LogicalOperator7_i;
  boolean rtb_OR_f;
  boolean rtb_RelationalOperator1;
  boolean rtb_RelationalOperator3_n;
  boolean rtb_flg_out_b;
  boolean rtb_y_l;
  boolean rtb_y_o;

  /* Relay: '<S3>/Relay' */
  swc_HMIF_ARID_DEF.Relay_Mode = ((swc_HMIF_ARID_DEF.DataTypeConversion10 >=
    dspc_q_socLowAcUpThd) || ((swc_HMIF_ARID_DEF.DataTypeConversion10 >
    dspc_q_socLowAcDnThd) && swc_HMIF_ARID_DEF.Relay_Mode));

  /* Switch: '<S3>/Switch' incorporates:
   *  Logic: '<S3>/Logical Operator'
   */
  if (swc_HMIF_ARID_DEF.DataTypeConversion62 &&
      swc_HMIF_ARID_DEF.DataTypeConversion59) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_Switch_h = ((uint8)4U);
  } else {
    GearLeverPos tmp;

    /* RelationalOperator: '<S3>/Relational Operator1' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion61'
     *  RelationalOperator: '<S3>/Relational Operator2'
     */
    tmp = swc_HMIF_ARID_DEF.DataTypeConversion61;

    /* Switch: '<S3>/Switch1' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S19>/Constant'
     *  Logic: '<S3>/Logical Operator1'
     *  Logic: '<S3>/Logical Operator2'
     *  RelationalOperator: '<S3>/Relational Operator1'
     *  RelationalOperator: '<S3>/Relational Operator2'
     */
    if (swc_HMIF_ARID_DEF.DataTypeConversion59 && ((tmp ==
          GearLeverPos_FWD_DRIVE) || (tmp == GearLeverPos_REV_DRIVE))) {
      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/Constant1'
       *  Switch: '<S3>/Switch1'
       */
      rtb_Switch_h = ((uint8)1U);
    } else {
      /* Logic: '<S3>/Logical Operator7' incorporates:
       *  Constant: '<S20>/Constant'
       *  DataTypeConversion: '<Root>/Data Type Conversion60'
       *  RelationalOperator: '<S3>/Relational Operator6'
       */
      rtb_LogicalOperator7_i = (swc_HMIF_ARID_DEF.DataTypeConversion60 !=
        BrakePedalStatus_PRESSED);

      /* RelationalOperator: '<S3>/Relational Operator' incorporates:
       *  DataTypeConversion: '<Root>/Data Type Conversion56'
       *  RelationalOperator: '<S3>/Relational Operator3'
       *  Switch: '<S3>/Switch2'
       *  Switch: '<S3>/Switch3'
       */
      rtb_RelationalOperator_j_tmp = swc_HMIF_ARID_DEF.DataTypeConversion56;

      /* Switch: '<S3>/Switch2' incorporates:
       *  Constant: '<S17>/Constant'
       *  Logic: '<S3>/Logical Operator3'
       *  Logic: '<S3>/Logical Operator4'
       *  Logic: '<S3>/Logical Operator5'
       *  RelationalOperator: '<S3>/Relational Operator'
       *  Relay: '<S3>/Relay'
       */
      if ((swc_HMIF_ARID_DEF.DataTypeConversion59 && rtb_LogicalOperator7_i) ||
          (rtb_LogicalOperator7_i && (rtb_RelationalOperator_j_tmp ==
            PmmStatus_LOWTEMPOFF))) {
        /* Switch: '<S3>/Switch' incorporates:
         *  Constant: '<S3>/Constant2'
         *  Switch: '<S3>/Switch2'
         */
        rtb_Switch_h = ((uint8)2U);
      } else {
        if (swc_HMIF_ARID_DEF.Relay_Mode) {
          /* Relay: '<S3>/Relay' */
          rtb_Divide_l = 0.0F;
        } else {
          /* Relay: '<S3>/Relay' */
          rtb_Divide_l = 1.0F;
        }

        /* Switch: '<S3>/Switch3' incorporates:
         *  Constant: '<S16>/Constant'
         *  Constant: '<S21>/Constant'
         *  Logic: '<S3>/Logical Operator6'
         *  Logic: '<S3>/Logical Operator8'
         *  RelationalOperator: '<S16>/Compare'
         *  RelationalOperator: '<S3>/Relational Operator3'
         *  Relay: '<S3>/Relay'
         *  Switch: '<S3>/Switch4'
         */
        if ((swc_HMIF_ARID_DEF.DataTypeConversion63 == 1.0) && (rtb_Divide_l !=
             0.0F)) {
          /* Switch: '<S3>/Switch' incorporates:
           *  Constant: '<S3>/Constant3'
           *  Switch: '<S3>/Switch2'
           *  Switch: '<S3>/Switch3'
           */
          rtb_Switch_h = ((uint8)3U);
        } else if (swc_HMIF_ARID_DEF.DataTypeConversion43 ||
                   swc_HMIF_ARID_DEF.DataTypeConversion45 ||
                   swc_HMIF_ARID_DEF.DataTypeConversion71 ||
                   (rtb_RelationalOperator_j_tmp == PmmStatus_LOWTEMPON)) {
          /* Switch: '<S3>/Switch4' incorporates:
           *  Constant: '<S3>/Constant6'
           *  Switch: '<S3>/Switch'
           *  Switch: '<S3>/Switch2'
           *  Switch: '<S3>/Switch3'
           */
          rtb_Switch_h = ((uint8)5U);
        } else {
          /* Switch: '<S3>/Switch' incorporates:
           *  Constant: '<S3>/Constant5'
           *  Switch: '<S3>/Switch2'
           *  Switch: '<S3>/Switch3'
           *  Switch: '<S3>/Switch4'
           */
          rtb_Switch_h = ((uint8)0U);
        }
      }
    }

    /* End of Switch: '<S3>/Switch1' */
  }

  /* End of Switch: '<S3>/Switch' */

  /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
   *  Constant: '<S3>/Constant11'
   */
  switch (((uint8)VEH_SWT_INF)) {
   case 0:
    /* Switch: '<S3>/Switch5' incorporates:
     *  Constant: '<S22>/Constant'
     *  DataTypeConversion: '<Root>/Data Type Conversion77'
     *  Logic: '<S3>/Logical Operator9'
     *  RelationalOperator: '<S3>/Relational Operator4'
     */
    if (swc_HMIF_ConstB.LogicalOperator10 &&
        (swc_HMIF_ARID_DEF.DataTypeConversion77 == ParkingStatus_DISENGAGED) &&
        swc_HMIF_ARID_DEF.DataTypeConversion62) {
      /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
       *  Constant: '<S3>/Constant4'
       */
      dspd_st_drvrOptRmdr = ((uint8)6U);
    } else {
      /* MultiPortSwitch: '<S3>/Multiport Switch' */
      dspd_st_drvrOptRmdr = rtb_Switch_h;
    }

    /* End of Switch: '<S3>/Switch5' */
    break;

   case 1:
    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    dspd_st_drvrOptRmdr = rtb_Switch_h;
    break;

   case 2:
    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    dspd_st_drvrOptRmdr = rtb_Switch_h;
    break;

   case 3:
    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    dspd_st_drvrOptRmdr = rtb_Switch_h;
    break;

   case 4:
    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    dspd_st_drvrOptRmdr = rtb_Switch_h;
    break;

   default:
    /* MultiPortSwitch: '<S3>/Multiport Switch' */
    dspd_st_drvrOptRmdr = rtb_Switch_h;
    break;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

  /* Switch: '<S26>/Switch' incorporates:
   *  UnitDelay: '<S26>/init'
   */
  if (swc_HMIF_ARID_DEF.init_DSTATE) {
    /* DataTypeConversion: '<S26>/Data Type Conversion3' incorporates:
     *  DataTypeConversion: '<S26>/Data Type Conversion'
     *  Switch: '<S51>/Switch'
     */
    dspd_pwr_hvPwrCsmpt_kW = swc_HMIF_ARID_DEF.DataTypeConversion16;
  } else {
    /* Product: '<S26>/Divide' incorporates:
     *  Constant: '<S23>/Constant15'
     *  Constant: '<S23>/Constant16'
     *  DataTypeConversion: '<S26>/Data Type Conversion1'
     *  DataTypeConversion: '<S26>/Data Type Conversion2'
     *  Sum: '<S26>/Add1'
     */
    rtb_Relay = dspc_tm_hvPwrCsmptFilter_s / (dspc_tm_hvPwrCsmptFilter_s +
      ((float32)DSP_TASK_INTERVAL_S));

    /* DataTypeConversion: '<S26>/Data Type Conversion3' incorporates:
     *  Constant: '<S26>/Constant'
     *  DataTypeConversion: '<S26>/Data Type Conversion'
     *  Product: '<S26>/Product'
     *  Product: '<S26>/Product1'
     *  Sum: '<S26>/Add'
     *  Sum: '<S26>/Add2'
     *  Switch: '<S51>/Switch'
     *  UnitDelay: '<S26>/Unit Delay'
     */
    dspd_pwr_hvPwrCsmpt_kW = (1.0F - rtb_Relay) *
      swc_HMIF_ARID_DEF.DataTypeConversion16 + rtb_Relay *
      swc_HMIF_ARID_DEF.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S26>/Switch' */

  /* CCaller: '<S27>/C Caller25' */
  dspd_num_nvmDataReadAec = mBSW_NvmRead_Aec();

  /* UnitDelay: '<S27>/Unit Delay' */
  rtb_LogicalOperator7_i = swc_HMIF_ARID_DEF.UnitDelay_DSTATE_h;

  /* RelationalOperator: '<S27>/Relational Operator4' incorporates:
   *  Constant: '<S27>/Constant25'
   */
  rtb_RelationalOperator4 = (swc_HMIF_ARID_DEF.DataTypeConversion15 <=
    dspc_v_vehStopSpd_kph);

  /* UnitDelay: '<S27>/Unit Delay1' */
  rtb_UnitDelay1_p = swc_HMIF_ARID_DEF.UnitDelay1_DSTATE_m;

  /* Outputs for Atomic SubSystem: '<S27>/MileageCal' */
  swc_HMIF_MileageCal(swc_HMIF_ARID_DEF.DataTypeConversion15,
                      rtb_RelationalOperator4, rtb_UnitDelay1_p, &rtb_Switch2_p,
                      &swc_HMIF_ARID_DEF.ARID_DEF_MileageCal);

  /* End of Outputs for SubSystem: '<S27>/MileageCal' */

  /* RelationalOperator: '<S27>/Relational Operator1' incorporates:
   *  Constant: '<S27>/Constant16'
   */
  rtb_RelationalOperator1 = (rtb_Switch2_p >= dspc_d_aecCellMileage_km);

  /* UnitDelay: '<S27>/Unit Delay6' */
  rtb_UnitDelay6 = swc_HMIF_ARID_DEF.UnitDelay6_DSTATE;

  /* Outputs for Atomic SubSystem: '<S27>/CsmptEngyCal' */
  swc_HMIF_CsmptEngyCal(dspd_pwr_hvPwrCsmpt_kW, rtb_RelationalOperator4,
                        rtb_UnitDelay6, &rtb_Switch1,
                        &swc_HMIF_ARID_DEF.ARID_DEF_CsmptEngyCal);

  /* End of Outputs for SubSystem: '<S27>/CsmptEngyCal' */

  /* Outputs for Enabled SubSystem: '<S27>/Subsystem' incorporates:
   *  EnablePort: '<S36>/Enable'
   */
  if (rtb_RelationalOperator1) {
    /* Product: '<S36>/Divide2' incorporates:
     *  Constant: '<S36>/Constant2'
     *  Constant: '<S36>/Constant4'
     *  MinMax: '<S36>/MinMax1'
     */
    rtb_Relay = rtb_Switch1 * 100.0F / fmaxf(rtb_Switch2_p, 0.1F);

    /* Switch: '<S36>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S44>/Constant'
     *  RelationalOperator: '<S43>/Compare'
     *  RelationalOperator: '<S44>/Compare'
     *  Switch: '<S36>/Switch2'
     */
    if (rtb_Relay <= dspc_pwr_AECLowLimit) {
      /* Switch: '<S36>/Switch1' incorporates:
       *  Constant: '<S36>/Constant'
       */
      dspd_num_AecCell_kWhp100km = dspc_pwr_AECLowLimit;
    } else if (rtb_Relay >= dspc_pwr_AECHiLimit) {
      /* Switch: '<S36>/Switch2' incorporates:
       *  Constant: '<S36>/Constant1'
       *  Switch: '<S36>/Switch1'
       */
      dspd_num_AecCell_kWhp100km = dspc_pwr_AECHiLimit;
    } else {
      /* Switch: '<S36>/Switch1' incorporates:
       *  Switch: '<S36>/Switch2'
       */
      dspd_num_AecCell_kWhp100km = rtb_Relay;
    }

    /* End of Switch: '<S36>/Switch1' */
  }

  /* End of Outputs for SubSystem: '<S27>/Subsystem' */

  /* Outputs for Atomic SubSystem: '<S27>/turnOFF_delay2' */
  /* Saturate: '<S39>/Saturation1' incorporates:
   *  Constant: '<S27>/Constant8'
   */
  if (dspc_tm_nvmReadHold_s > 1.6777216E+7F) {
    /* Saturate: '<S39>/Saturation1' */
    rtb_Relay = 1.6777216E+7F;
  } else if (dspc_tm_nvmReadHold_s < 0.0F) {
    /* Saturate: '<S39>/Saturation1' */
    rtb_Relay = 0.0F;
  } else {
    /* Saturate: '<S39>/Saturation1' */
    rtb_Relay = dspc_tm_nvmReadHold_s;
  }

  /* End of Saturate: '<S39>/Saturation1' */

  /* Chart: '<S39>/timed_delay' incorporates:
   *  Constant: '<S27>/Constant7'
   */
  if (swc_HMIF_ARID_DEF.is_active_c12_Ricardo_SW_dev_li == 0U) {
    swc_HMIF_ARID_DEF.is_active_c12_Ricardo_SW_dev_li = 1U;
    if (swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_j) {
      swc_HMIF_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_HMIF_IN_ON_p;
      rtb_flg_out_b = true;

      /* Chart: '<S27>/RollingAverage' */
      Cntr = 0U;
    } else {
      swc_HMIF_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_HMIF_IN_OFF_f;
      rtb_flg_out_b = false;
    }
  } else {
    switch (swc_HMIF_ARID_DEF.is_c12_Ricardo_SW_dev_lib) {
     case swc_HMIF_IN_OFF_f:
      if (swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_j) {
        swc_HMIF_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_HMIF_IN_ON_p;
        rtb_flg_out_b = true;

        /* Chart: '<S27>/RollingAverage' */
        Cntr = 0U;
      } else {
        rtb_flg_out_b = false;
      }
      break;

     case swc_HMIF_IN_OFF_WAIT:
      if (swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_j) {
        swc_HMIF_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_HMIF_IN_ON_p;
        rtb_flg_out_b = true;

        /* Chart: '<S27>/RollingAverage' */
        Cntr = 0U;
      } else if (swc_HMIF_ARID_DEF.t_wait > rtb_Relay - ((float32)
                  DSP_TASK_INTERVAL_S)) {
        swc_HMIF_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_HMIF_IN_OFF_f;
        rtb_flg_out_b = false;
      } else {
        swc_HMIF_ARID_DEF.t_wait += ((float32)DSP_TASK_INTERVAL_S);
        rtb_flg_out_b = true;

        /* Chart: '<S27>/RollingAverage' */
        Cntr = 0U;
      }
      break;

     default:
      /* case IN_ON: */
      if (!swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_j) {
        if (rtb_Relay == 0.0F) {
          swc_HMIF_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_HMIF_IN_OFF_f;
          rtb_flg_out_b = false;
        } else {
          swc_HMIF_ARID_DEF.is_c12_Ricardo_SW_dev_lib = swc_HMIF_IN_OFF_WAIT;
          swc_HMIF_ARID_DEF.t_wait = 0.0F;
          swc_HMIF_ARID_DEF.t_wait += ((float32)DSP_TASK_INTERVAL_S);
          rtb_flg_out_b = true;

          /* Chart: '<S27>/RollingAverage' */
          Cntr = 0U;
        }
      } else {
        rtb_flg_out_b = true;

        /* Chart: '<S27>/RollingAverage' */
        Cntr = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S39>/timed_delay' */
  /* End of Outputs for SubSystem: '<S27>/turnOFF_delay2' */

  /* Chart: '<S27>/RollingAverage' incorporates:
   *  UnitDelay: '<S27>/Unit Delay3'
   */
  if (Cntr == 0) {
    Aec1 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec2 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec3 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec4 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec5 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec6 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec7 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec8 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec9 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    Aec10 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec11 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec12 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec13 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec14 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec15 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec16 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec17 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec18 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec19 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec20 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec21 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec22 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec23 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec24 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec25 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec26 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec27 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec28 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec29 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec30 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec31 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec32 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec33 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec34 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec35 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec36 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec37 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec38 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec39 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec40 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec41 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec42 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec43 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec44 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec45 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec46 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec47 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec48 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec49 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
    swc_HMIF_ARID_DEF.Aec50 = swc_HMIF_ARID_DEF.UnitDelay3_DSTATE;
  }

  swc_HMIF_ARID_DEF.TmTrig = ((rtb_RelationalOperator1 && (!rtb_flg_out_b)) ||
    swc_HMIF_ARID_DEF.TmTrig);
  if (swc_HMIF_ARID_DEF.TmTrig) {
    Cntr = (uint8)(Cntr + 1);
  }

  if (Cntr >= 51) {
    Cntr = 1U;
  }

  if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 1)) {
    Aec1 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 2)) {
    Aec2 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 3)) {
    Aec3 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 4)) {
    Aec4 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 5)) {
    Aec5 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 6)) {
    Aec6 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 7)) {
    Aec7 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 8)) {
    Aec8 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 9)) {
    Aec9 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 10)) {
    Aec10 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 11)) {
    swc_HMIF_ARID_DEF.Aec11 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 12)) {
    swc_HMIF_ARID_DEF.Aec12 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 13)) {
    swc_HMIF_ARID_DEF.Aec13 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 14)) {
    swc_HMIF_ARID_DEF.Aec14 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 15)) {
    swc_HMIF_ARID_DEF.Aec15 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 16)) {
    swc_HMIF_ARID_DEF.Aec16 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 17)) {
    swc_HMIF_ARID_DEF.Aec17 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 18)) {
    swc_HMIF_ARID_DEF.Aec18 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 19)) {
    swc_HMIF_ARID_DEF.Aec19 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 20)) {
    swc_HMIF_ARID_DEF.Aec20 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 21)) {
    swc_HMIF_ARID_DEF.Aec21 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 22)) {
    swc_HMIF_ARID_DEF.Aec22 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 23)) {
    swc_HMIF_ARID_DEF.Aec23 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 24)) {
    swc_HMIF_ARID_DEF.Aec24 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 25)) {
    swc_HMIF_ARID_DEF.Aec25 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 26)) {
    swc_HMIF_ARID_DEF.Aec26 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 27)) {
    swc_HMIF_ARID_DEF.Aec27 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 28)) {
    swc_HMIF_ARID_DEF.Aec28 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 29)) {
    swc_HMIF_ARID_DEF.Aec29 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 30)) {
    swc_HMIF_ARID_DEF.Aec30 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 31)) {
    swc_HMIF_ARID_DEF.Aec31 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 32)) {
    swc_HMIF_ARID_DEF.Aec32 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 33)) {
    swc_HMIF_ARID_DEF.Aec33 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 34)) {
    swc_HMIF_ARID_DEF.Aec34 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 35)) {
    swc_HMIF_ARID_DEF.Aec35 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 36)) {
    swc_HMIF_ARID_DEF.Aec36 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 37)) {
    swc_HMIF_ARID_DEF.Aec37 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 38)) {
    swc_HMIF_ARID_DEF.Aec38 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 39)) {
    swc_HMIF_ARID_DEF.Aec39 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 40)) {
    swc_HMIF_ARID_DEF.Aec40 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 41)) {
    swc_HMIF_ARID_DEF.Aec41 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 42)) {
    swc_HMIF_ARID_DEF.Aec42 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 43)) {
    swc_HMIF_ARID_DEF.Aec43 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 44)) {
    swc_HMIF_ARID_DEF.Aec44 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 45)) {
    swc_HMIF_ARID_DEF.Aec45 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 46)) {
    swc_HMIF_ARID_DEF.Aec46 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 47)) {
    swc_HMIF_ARID_DEF.Aec47 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 48)) {
    swc_HMIF_ARID_DEF.Aec48 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 49)) {
    swc_HMIF_ARID_DEF.Aec49 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  } else if (swc_HMIF_ARID_DEF.TmTrig && (Cntr == 50)) {
    swc_HMIF_ARID_DEF.Aec50 = dspd_num_AecCell_kWhp100km;
    swc_HMIF_ARID_DEF.TmTrig = false;
  }

  dspd_num_AecRaw_kWhp100km =
    (((((((((((((((((((((((((((((((((((((((((((((((((Aec1 + Aec2) + Aec3) + Aec4)
    + Aec5) + Aec6) + Aec7) + Aec8) + Aec9) + Aec10) + swc_HMIF_ARID_DEF.Aec11)
    + swc_HMIF_ARID_DEF.Aec12) + swc_HMIF_ARID_DEF.Aec13) +
    swc_HMIF_ARID_DEF.Aec14) + swc_HMIF_ARID_DEF.Aec15) +
    swc_HMIF_ARID_DEF.Aec16) + swc_HMIF_ARID_DEF.Aec17) +
    swc_HMIF_ARID_DEF.Aec18) + swc_HMIF_ARID_DEF.Aec19) +
    swc_HMIF_ARID_DEF.Aec20) + swc_HMIF_ARID_DEF.Aec21) +
    swc_HMIF_ARID_DEF.Aec22) + swc_HMIF_ARID_DEF.Aec23) +
    swc_HMIF_ARID_DEF.Aec24) + swc_HMIF_ARID_DEF.Aec25) +
    swc_HMIF_ARID_DEF.Aec26) + swc_HMIF_ARID_DEF.Aec27) +
    swc_HMIF_ARID_DEF.Aec28) + swc_HMIF_ARID_DEF.Aec29) +
    swc_HMIF_ARID_DEF.Aec30) + swc_HMIF_ARID_DEF.Aec31) +
                       swc_HMIF_ARID_DEF.Aec32) + swc_HMIF_ARID_DEF.Aec33) +
                     swc_HMIF_ARID_DEF.Aec34) + swc_HMIF_ARID_DEF.Aec35) +
                   swc_HMIF_ARID_DEF.Aec36) + swc_HMIF_ARID_DEF.Aec37) +
                 swc_HMIF_ARID_DEF.Aec38) + swc_HMIF_ARID_DEF.Aec39) +
               swc_HMIF_ARID_DEF.Aec40) + swc_HMIF_ARID_DEF.Aec41) +
             swc_HMIF_ARID_DEF.Aec42) + swc_HMIF_ARID_DEF.Aec43) +
           swc_HMIF_ARID_DEF.Aec44) + swc_HMIF_ARID_DEF.Aec45) +
         swc_HMIF_ARID_DEF.Aec46) + swc_HMIF_ARID_DEF.Aec47) +
       swc_HMIF_ARID_DEF.Aec48) + swc_HMIF_ARID_DEF.Aec49) +
     swc_HMIF_ARID_DEF.Aec50) / 50.0F;

  /* Lookup_n-D: '<S51>/1-D Lookup Table1' incorporates:
   *  Constant: '<S27>/Constant1'
   *  MinMax: '<S27>/MinMax4'
   */
  rtb_uDLookupTable1 = fmaxf(dspd_num_AecRaw_kWhp100km,
    dspc_num_AecMin_kWhp100km);

  /* Switch: '<S34>/Switch1' incorporates:
   *  Logic: '<S34>/Logical Operator2'
   *  UnitDelay: '<S27>/Unit Delay4'
   */
  if (!swc_HMIF_ARID_DEF.UnitDelay4_DSTATE) {
    /* Lookup_n-D: '<S68>/1-D Lookup Table1' */
    rtb_Relay = rtb_uDLookupTable1;
  } else {
    /* Lookup_n-D: '<S68>/1-D Lookup Table1' incorporates:
     *  UnitDelay: '<S34>/Unit Delay2'
     */
    rtb_Relay = swc_HMIF_ARID_DEF.UnitDelay2_DSTATE;
  }

  /* End of Switch: '<S34>/Switch1' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S27>/Constant11'
   *  Constant: '<S27>/Constant14'
   *  Constant: '<S34>/step_time6'
   *  MinMax: '<S34>/MinMax3'
   *  Product: '<S34>/Product1'
   */
  rtb_Switch1 = ((float32)DSP_TASK_INTERVAL_S) * dspc_dn_aecDecGrad_kWhp100km;
  rtb_Switch1 = fminf(0.0F, rtb_Switch1);

  /* Sum: '<S34>/Sum6' incorporates:
   *  Constant: '<S27>/Constant11'
   *  Constant: '<S27>/Constant13'
   *  Constant: '<S34>/step_time6'
   *  MinMax: '<S34>/MinMax'
   *  MinMax: '<S34>/MinMax1'
   *  MinMax: '<S34>/MinMax2'
   *  Product: '<S34>/Product'
   *  Sum: '<S34>/Sum5'
   */
  rtb_uDLookupTable1 = fminf(fmaxf(dspc_dn_aecIncGrad_kWhp100km * ((float32)
    DSP_TASK_INTERVAL_S), 0.0F), fmaxf(rtb_uDLookupTable1 - rtb_Relay,
    rtb_Switch1)) + rtb_Relay;

  /* Switch: '<S27>/Switch1' incorporates:
   *  UnitDelay: '<S27>/Unit Delay'
   */
  if (swc_HMIF_ARID_DEF.UnitDelay_DSTATE_h) {
    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S27>/Constant2'
     *  RelationalOperator: '<S27>/Relational Operator2'
     */
    if (dspd_num_nvmDataReadAec > 0.0F) {
      /* Switch: '<S27>/Switch1' */
      dspd_num_AecEV_kWhp100km = dspd_num_nvmDataReadAec;
    } else {
      /* Switch: '<S27>/Switch1' */
      dspd_num_AecEV_kWhp100km = dspd_num_AecInit_kWhp100km;
    }

    /* End of Switch: '<S27>/Switch2' */
  } else {
    /* Switch: '<S27>/Switch1' */
    dspd_num_AecEV_kWhp100km = rtb_uDLookupTable1;
  }

  /* End of Switch: '<S27>/Switch1' */

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S32>/Constant9'
   *  Logic: '<S32>/OR'
   *  RelationalOperator: '<S32>/Relational Operator'
   *  RelationalOperator: '<S32>/Relational Operator3'
   */
  if ((dspd_num_AecEV_kWhp100km > dspd_num_AecUpLim) ||
      (dspd_num_AecEV_kWhp100km < dspd_num_AecLowLim)) {
    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/Constant12'
     */
    swc_HMIF_ARID_DEF.Switch = 14.8F;
  } else {
    /* Switch: '<S32>/Switch' */
    swc_HMIF_ARID_DEF.Switch = dspd_num_AecEV_kWhp100km;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Outputs for Enabled SubSystem: '<S27>/AecNvmDataWrite' incorporates:
   *  EnablePort: '<S29>/Enable'
   */
  /* RelationalOperator: '<S31>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S31>/Delay Input1'
   *
   * Block description for '<S31>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((sint32)swc_HMIF_ARID_DEF.DataTypeConversion14 < (sint32)
      swc_HMIF_ARID_DEF.DelayInput1_DSTATE) {
    /* Switch: '<S42>/Switch2' incorporates:
     *  Constant: '<S41>/dspc_b_nvmDataWriteAec_ovrdflg'
     */
    if (dspc_b_nvmDataWriteAec_ovrdflg) {
      /* Switch: '<S42>/Switch2' incorporates:
       *  Constant: '<S41>/dspc_num_nvmDataWriteAec_ovrdval'
       */
      dspd_num_nvmDataWriteAec = dspc_num_nvmDataWriteAec_ovrdval;
    } else {
      /* Switch: '<S42>/Switch2' */
      dspd_num_nvmDataWriteAec = swc_HMIF_ARID_DEF.Switch;
    }

    /* End of Switch: '<S42>/Switch2' */

    /* CCaller: '<S29>/C Caller48' */
    mBSW_NvmWrite_Aec(dspd_num_nvmDataWriteAec);
  }

  /* End of RelationalOperator: '<S31>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<S27>/AecNvmDataWrite' */

  /* Outputs for Enabled SubSystem: '<S28>/Subsystem' incorporates:
   *  EnablePort: '<S40>/Enable'
   */
  /* Constant: '<S27>/Constant3' */
  if (true) {
    /* Sum: '<S40>/Add7' incorporates:
     *  Constant: '<S40>/Constant'
     *  UnitDelay: '<S40>/Unit Delay5'
     */
    rtb_Add7_g = 1.0 + swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_k;

    /* RelationalOperator: '<S40>/Relational Operator' incorporates:
     *  Constant: '<S40>/Constant1'
     */
    swc_HMIF_ARID_DEF.RelationalOperator_g = (dspc_tm_drRngDelay > rtb_Add7_g);

    /* Update for UnitDelay: '<S40>/Unit Delay5' */
    swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_k = rtb_Add7_g;
  }

  /* End of Constant: '<S27>/Constant3' */
  /* End of Outputs for SubSystem: '<S28>/Subsystem' */

  /* Product: '<S27>/Product1' incorporates:
   *  Gain: '<S27>/Gain3'
   */
  dspd_d_vehDrvRngStandardRaw_km = 0.01F *
    swc_HMIF_ARID_DEF.DataTypeConversion10 *
    swc_HMIF_ARID_DEF.DataTypeConversion84;

  /* Switch: '<S9>/Switch1' incorporates:
   *  CCaller: '<S47>/C Caller'
   */
  rtb_Switch1 = mBSW_NvmRead_stdRng();

  /* Switch: '<S47>/Switch1' incorporates:
   *  Delay: '<S47>/Delay1'
   */
  if (swc_HMIF_ARID_DEF.Delay1_DSTATE_g) {
    /* Switch: '<S47>/Switch1' */
    dspd_d_stdRng2NVM = rtb_Switch1;
  } else {
    /* Switch: '<S47>/Switch1' incorporates:
     *  Delay: '<S47>/Delay2'
     */
    dspd_d_stdRng2NVM = swc_HMIF_ARID_DEF.Delay2_DSTATE;
  }

  /* End of Switch: '<S47>/Switch1' */

  /* Delay: '<S47>/Delay3' */
  rtb_Delay3 = swc_HMIF_ARID_DEF.Delay3_DSTATE[0];

  /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
   *  CCaller: '<S4>/C Caller'
   */
  rtb_RelationalOperator3_n = mBSW_NmWkUp();

  /* Logic: '<S4>/OR' */
  rtb_OR_h = (swc_HMIF_ARID_DEF.DataTypeConversion14 ||
              swc_HMIF_ARID_DEF.DataTypeConversion18 ||
              swc_HMIF_ARID_DEF.DataTypeConversion19 ||
              swc_HMIF_ARID_DEF.DataTypeConversion20 ||
              rtb_RelationalOperator3_n);

  /* Outputs for Enabled SubSystem: '<S66>/Subsystem' */
  swc_HMIF_Subsystem(rtb_OR_h, &swc_HMIF_ARID_DEF.RelationalOperator_d,
                     &swc_HMIF_ARID_DEF.ARID_DEF_Subsystem_m);

  /* End of Outputs for SubSystem: '<S66>/Subsystem' */

  /* Product: '<S24>/Divide5' incorporates:
   *  Constant: '<S24>/Constant8'
   */
  dspd_d_vehDrvRngDynamic_km = swc_HMIF_ARID_DEF.DataTypeConversion90 /
    swc_HMIF_ARID_DEF.Switch * 100.0F;

  /* Switch: '<S64>/Switch' */
  if (swc_HMIF_ARID_DEF.RelationalOperator_d) {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    rtb_Switch1 = 0.0F;
  } else {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S64>/Constant20'
     *  Gain: '<S64>/Gain'
     *  MinMax: '<S67>/MinMax10'
     *  MinMax: '<S67>/MinMax5'
     */
    rtb_Switch1 = fmaxf(fminf(dspd_d_vehDrvRngDynamic_km, 1.5F *
      swc_HMIF_ARID_DEF.DataTypeConversion84), 0.0F);
  }

  /* End of Switch: '<S64>/Switch' */

  /* RelationalOperator: '<S47>/Relational Operator3' incorporates:
   *  Constant: '<S47>/Constant5'
   */
  rtb_RelationalOperator3_p = (rtb_Switch1 > 20.0F);

  /* Outputs for Atomic SubSystem: '<S47>/SR_latch' */
  swc_HMIF_SR_latch(rtb_Delay3, rtb_RelationalOperator3_p,
                    &rtb_LogicalOperator3_d,
                    &swc_HMIF_ARID_DEF.ARID_DEF_SR_latch_k);

  /* End of Outputs for SubSystem: '<S47>/SR_latch' */

  /* Outputs for Enabled SubSystem: '<S46>/Subsystem' */
  swc_HMIF_Subsystem(rtb_OR_h, &swc_HMIF_ARID_DEF.RelationalOperator_o,
                     &swc_HMIF_ARID_DEF.ARID_DEF_Subsystem_cx);

  /* End of Outputs for SubSystem: '<S46>/Subsystem' */

  /* Switch: '<S37>/Switch' */
  if (swc_HMIF_ARID_DEF.RelationalOperator_o) {
    /* Lookup_n-D: '<S68>/1-D Lookup Table1' incorporates:
     *  Constant: '<S37>/Constant1'
     */
    rtb_Relay = 0.0F;
  } else {
    /* Lookup_n-D: '<S68>/1-D Lookup Table1' incorporates:
     *  Constant: '<S37>/Constant19'
     *  Gain: '<S37>/Gain1'
     *  MinMax: '<S49>/MinMax10'
     *  MinMax: '<S49>/MinMax5'
     */
    rtb_Relay = fmaxf(fminf(dspd_d_vehDrvRngStandardRaw_km, 1.5F *
      swc_HMIF_ARID_DEF.DataTypeConversion84), 0.0F);
  }

  /* End of Switch: '<S37>/Switch' */

  /* Switch: '<S47>/Switch' incorporates:
   *  Constant: '<S47>/Constant'
   *  RelationalOperator: '<S47>/Relational Operator'
   */
  if (rtb_Switch1 > 20.0F) {
    /* Switch: '<S47>/Switch' */
    dspd_d_stdRngLatVal = rtb_Relay;
  } else {
    /* Switch: '<S47>/Switch' incorporates:
     *  Delay: '<S47>/Delay'
     */
    dspd_d_stdRngLatVal = swc_HMIF_ARID_DEF.Delay_DSTATE_l;
  }

  /* End of Switch: '<S47>/Switch' */

  /* Switch: '<S47>/Switch4' */
  if (rtb_LogicalOperator3_d) {
    /* Switch: '<S47>/Switch4' */
    dspd_d_stdRngDecRate = dspd_d_stdRng2NVM;
  } else {
    /* Switch: '<S47>/Switch4' */
    dspd_d_stdRngDecRate = dspd_d_stdRngLatVal;
  }

  /* End of Switch: '<S47>/Switch4' */

  /* Outputs for Enabled SubSystem: '<S45>/Subsystem' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  if (rtb_OR_h) {
    if (!swc_HMIF_ARID_DEF.Subsystem_MODE_o) {
      /* InitializeConditions for UnitDelay: '<S52>/Unit Delay5' */
      swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_o = 0.0;
      swc_HMIF_ARID_DEF.Subsystem_MODE_o = true;
    }

    /* Sum: '<S52>/Add7' incorporates:
     *  Constant: '<S52>/Constant'
     *  UnitDelay: '<S52>/Unit Delay5'
     */
    rtb_Add7_g = 1.0 + swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_o;

    /* RelationalOperator: '<S52>/Relational Operator' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    swc_HMIF_ARID_DEF.RelationalOperator_e = (dspc_tm_drRngDelay <= rtb_Add7_g);

    /* Update for UnitDelay: '<S52>/Unit Delay5' */
    swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_o = rtb_Add7_g;
  } else {
    swc_HMIF_ARID_DEF.Subsystem_MODE_o = false;
  }

  /* End of Outputs for SubSystem: '<S45>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S37>/Subsystem' incorporates:
   *  EnablePort: '<S50>/Enable'
   */
  /* Logic: '<S37>/AND' incorporates:
   *  RelationalOperator: '<S48>/FixPt Relational Operator'
   *  UnitDelay: '<S48>/Delay Input1'
   *
   * Block description for '<S48>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((sint32)swc_HMIF_ARID_DEF.DataTypeConversion14 < (sint32)
       swc_HMIF_ARID_DEF.DelayInput1_DSTATE_m) &&
      swc_HMIF_ARID_DEF.RelationalOperator_e) {
    /* CCaller: '<S50>/C Caller2' */
    mBSW_NvmWrite_stdRng(dspd_d_stdRngDecRate);
  }

  /* End of Logic: '<S37>/AND' */
  /* End of Outputs for SubSystem: '<S37>/Subsystem' */

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S55>/Lower Limit'
   *  Constant: '<S55>/Upper Limit'
   *  Logic: '<S55>/AND'
   *  RelationalOperator: '<S55>/Lower Test'
   *  RelationalOperator: '<S55>/Upper Test'
   */
  if ((10.0F <= dspd_d_stdRngDecRate) && (dspd_d_stdRngDecRate <= 50.0F)) {
    rtb_Divide_l = dspd_d_stdRngDecRate;
  } else {
    rtb_Divide_l = rtb_Relay;
  }

  /* Product: '<S51>/Product' incorporates:
   *  Lookup_n-D: '<S51>/1-D Lookup Table1'
   *  Switch: '<S51>/Switch'
   *  Switch: '<S9>/Switch1'
   */
  dspd_d_stdRngMapVal = look1_iflf_binlxpw(rtb_Switch1, (const float32 *)
    &dspc_X_rngAct[0], (const float32 *)&dspc_Y_rngVarFactor[0], 11U) *
    rtb_Divide_l;

  /* Switch: '<S37>/Switch9' incorporates:
   *  Constant: '<S37>/Constant21'
   *  RelationalOperator: '<S37>/Relational Operator6'
   */
  if (rtb_Switch1 <= 20.0F) {
    /* Switch: '<S37>/Switch9' */
    dspd_d_standardRange = dspd_d_stdRngMapVal;
  } else {
    /* Switch: '<S37>/Switch9' */
    dspd_d_standardRange = rtb_Relay;
  }

  /* End of Switch: '<S37>/Switch9' */

  /* Outputs for Enabled SubSystem: '<S56>/Subsystem' */
  swc_HMIF_Subsystem_d(rtb_OR_h, &swc_HMIF_ARID_DEF.RelationalOperator_n,
                       &swc_HMIF_ARID_DEF.ARID_DEF_Subsystem_c);

  /* End of Outputs for SubSystem: '<S56>/Subsystem' */

  /* Switch: '<S58>/Switch' incorporates:
   *  Constant: '<S57>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion56'
   *  Logic: '<S38>/OR'
   *  RelationalOperator: '<S38>/Relational Operator'
   *  Switch: '<S38>/Switch3'
   *  Switch: '<S38>/Switch9'
   *  UnitDelay: '<S38>/Unit Delay'
   *  UnitDelay: '<S58>/init'
   */
  if (swc_HMIF_ARID_DEF.init_DSTATE_e) {
    /* Lookup_n-D: '<S68>/1-D Lookup Table1' */
    rtb_Relay = dspd_d_standardRange;
  } else {
    if (swc_HMIF_ARID_DEF.RelationalOperator_n ||
        swc_HMIF_ARID_DEF.UnitDelay_DSTATE_p ||
        (swc_HMIF_ARID_DEF.DataTypeConversion56 == PmmStatus_CHARGE)) {
      /* Switch: '<S38>/Switch3' incorporates:
       *  Constant: '<S38>/Constant13'
       */
      rtb_Divide_l = dspc_dn_RngIncGradH;

      /* Switch: '<S38>/Switch9' incorporates:
       *  Constant: '<S38>/Constant24'
       */
      rtb_CCaller1 = dspc_dn_RngDecGradH;
    } else {
      /* Switch: '<S38>/Switch3' incorporates:
       *  Constant: '<S38>/Constant26'
       */
      rtb_Divide_l = dspc_dn_StdRngIncGradL;

      /* Switch: '<S38>/Switch9' incorporates:
       *  Constant: '<S38>/Constant27'
       */
      rtb_CCaller1 = dspc_dn_StdRngDecGradL;
    }

    /* Lookup_n-D: '<S68>/1-D Lookup Table1' incorporates:
     *  Constant: '<S38>/Constant25'
     *  Constant: '<S58>/step_time6'
     *  MinMax: '<S58>/MinMax'
     *  MinMax: '<S58>/MinMax1'
     *  MinMax: '<S58>/MinMax2'
     *  MinMax: '<S58>/MinMax3'
     *  Product: '<S58>/Product'
     *  Product: '<S58>/Product1'
     *  Sum: '<S58>/Sum5'
     *  Sum: '<S58>/Sum6'
     *  Switch: '<S38>/Switch3'
     *  Switch: '<S38>/Switch9'
     *  UnitDelay: '<S58>/Unit Delay'
     */
    rtb_Relay = fminf(fmaxf(rtb_Divide_l * ((float32)DSP_TASK_INTERVAL_S), 0.0F),
                      fmaxf(dspd_d_standardRange -
      swc_HMIF_ARID_DEF.UnitDelay_DSTATE_c, fminf(0.0F, ((float32)
      DSP_TASK_INTERVAL_S) * rtb_CCaller1))) +
      swc_HMIF_ARID_DEF.UnitDelay_DSTATE_c;
  }

  /* End of Switch: '<S58>/Switch' */

  /* DataTypeConversion: '<S12>/Data Type Conversion2' incorporates:
   *  CCaller: '<S59>/C Caller4'
   */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S59>/C Caller4' incorporates:
   *  Constant: '<S59>/InvalidValue_0XFFF1'
   */
  Dem_GetEventStatus(((uint16)32895U), &rtb_DataTypeConversion2_l);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  S-Function (sfix_bitop): '<S59>/Bitwise And1'
   */
  rtb_Switch_h = (uint8)(rtb_DataTypeConversion2_l & ((uint8)1U));

  /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
   *  DataTypeConversion: '<S59>/con_3'
   */
  rtb_RelationalOperator3_n = (rtb_Switch_h != 0);

  /* Switch: '<S38>/Switch10' */
  if (rtb_RelationalOperator3_n) {
    /* Switch: '<S38>/Switch10' incorporates:
     *  Constant: '<S38>/InvalidValue_0XFFF'
     */
    dspd_d_vehDrvRngStandard_km = dspc_d_vehDrvRngStdInvalid;
  } else {
    /* Switch: '<S38>/Switch10' incorporates:
     *  DataTypeConversion: '<S58>/Data Type Conversion'
     */
    dspd_d_vehDrvRngStandard_km = rtb_Relay;
  }

  /* End of Switch: '<S38>/Switch10' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  CCaller: '<S60>/C Caller4'
   */
  rtb_Switch_h = 0U;

  /* CCaller: '<S60>/C Caller4' incorporates:
   *  Constant: '<S60>/InvalidValue_0XFFF1'
   */
  Dem_GetEventStatus(((uint16)32895U), &rtb_Switch_h);

  /* DataTypeConversion: '<S12>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<S60>/Bitwise And1'
   */
  rtb_DataTypeConversion2_l = (uint8)(rtb_Switch_h & ((uint8)1U));

  /* DataTypeConversion: '<S60>/con_3' */
  rtb_flg_out_b = (rtb_DataTypeConversion2_l != 0);

  /* Product: '<S68>/Product' incorporates:
   *  Constant: '<S68>/Constant'
   *  Lookup_n-D: '<S68>/1-D Lookup Table1'
   *  Switch: '<S9>/Switch1'
   */
  dspd_d_dynRngMapVal = look1_iflf_binlxpw(rtb_Switch1, (const float32 *)
    &dspc_X_rngAct[0], (const float32 *)&dspc_Y_rngVarFactor[0], 11U) *
    dspc_d_storedDynRange;

  /* Switch: '<S64>/Switch1' incorporates:
   *  Constant: '<S64>/Constant3'
   *  RelationalOperator: '<S64>/Relational Operator1'
   */
  if (rtb_Switch1 <= 20.0F) {
    /* Switch: '<S64>/Switch1' */
    dspd_d_dynamicRange = dspd_d_dynRngMapVal;
  } else {
    /* Switch: '<S64>/Switch1' */
    dspd_d_dynamicRange = rtb_Switch1;
  }

  /* End of Switch: '<S64>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S70>/Subsystem' */
  swc_HMIF_Subsystem_d(rtb_OR_h, &swc_HMIF_ARID_DEF.RelationalOperator_p,
                       &swc_HMIF_ARID_DEF.ARID_DEF_Subsystem);

  /* End of Outputs for SubSystem: '<S70>/Subsystem' */

  /* DataTypeConversion: '<S8>/Data Type Conversion6' */
  rtb_Add7_g = swc_HMIF_ARID_DEF.DataTypeConversion5;

  /* CCaller: '<S8>/C Caller1' */
  rtb_CCaller1 = mBSW_NvmRead_Odometer();

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S209>/Lower Limit'
   *  Constant: '<S209>/Upper Limit'
   *  Logic: '<S209>/AND'
   *  RelationalOperator: '<S209>/Lower Test'
   *  RelationalOperator: '<S209>/Upper Test'
   */
  if ((0.0F < rtb_CCaller1) && (rtb_CCaller1 <= 999999.0F)) {
    /* Switch: '<S8>/Switch' */
    dspd_d_odoRead_float = rtb_CCaller1;
  } else {
    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S8>/Constant19'
     */
    dspd_d_odoRead_float = 0.0F;
  }

  /* End of Switch: '<S8>/Switch' */

  /* CCaller: '<S8>/C Caller2' */
  rtb_CCaller2 = mBSW_NvmRead_Odometer_u32();

  /* Switch: '<S8>/Switch5' incorporates:
   *  Constant: '<S210>/Lower Limit'
   *  Constant: '<S210>/Upper Limit'
   *  Logic: '<S210>/AND'
   *  RelationalOperator: '<S210>/Lower Test'
   *  RelationalOperator: '<S210>/Upper Test'
   */
  if ((0U < rtb_CCaller2) && (rtb_CCaller2 <= 999999000U)) {
    /* Switch: '<S8>/Switch5' */
    dspd_d_odoRead_u32 = (float32)rtb_CCaller2;
  } else {
    /* Switch: '<S8>/Switch5' incorporates:
     *  Constant: '<S8>/Constant6'
     */
    dspd_d_odoRead_u32 = 0.0F;
  }

  /* End of Switch: '<S8>/Switch5' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Gain: '<S8>/Gain'
   */
  rtb_Switch1 = 0.001F * dspd_d_odoRead_u32;

  /* MinMax: '<S8>/Max' */
  dspd_d_odoRead_km = fmaxf(dspd_d_odoRead_float, rtb_Switch1);

  /* RelationalOperator: '<S8>/Relational Operator5' incorporates:
   *  UnitDelay: '<S8>/Unit Delay'
   */
  rtb_RelationalOperator5 = (swc_HMIF_ARID_DEF.DataTypeConversion134 ==
    swc_HMIF_ARID_DEF.UnitDelay_DSTATE_l);

  /* Outputs for Atomic SubSystem: '<S8>/turnON_delay1' */
  /* Constant: '<S8>/Constant10' incorporates:
   *  Constant: '<S8>/Constant9'
   */
  swc_HMIF_turnON_delay(rtb_RelationalOperator5, dspc_tm_ipkOdoDebd_s, 0.01F,
                        &rtb_flg_out_m,
                        &swc_HMIF_ARID_DEF.ARID_DEF_turnON_delay1);

  /* End of Outputs for SubSystem: '<S8>/turnON_delay1' */

  /* Logic: '<S8>/Logical Operator1' incorporates:
   *  Constant: '<S8>/Constant7'
   *  Constant: '<S8>/Constant8'
   *  RelationalOperator: '<S8>/Relational Operator3'
   *  RelationalOperator: '<S8>/Relational Operator4'
   */
  dspd_b_ipkOdoValid = ((swc_HMIF_ARID_DEF.DataTypeConversion134 > 0.0F) &&
                        (swc_HMIF_ARID_DEF.DataTypeConversion134 < 1.6383E+6F) &&
                        rtb_flg_out_m);

  /* RelationalOperator: '<S8>/Relational Operator8' incorporates:
   *  UnitDelay: '<S8>/Unit Delay1'
   */
  rtb_RelationalOperator8 = (swc_HMIF_ARID_DEF.DataTypeConversion133 ==
    swc_HMIF_ARID_DEF.UnitDelay1_DSTATE);

  /* Outputs for Atomic SubSystem: '<S8>/turnON_delay2' */
  /* Constant: '<S8>/Constant11' incorporates:
   *  Constant: '<S8>/Constant14'
   */
  swc_HMIF_turnON_delay(rtb_RelationalOperator8, dspc_tm_bcmOdoDebd_s, 0.01F,
                        &rtb_flg_out, &swc_HMIF_ARID_DEF.ARID_DEF_turnON_delay2);

  /* End of Outputs for SubSystem: '<S8>/turnON_delay2' */

  /* Logic: '<S8>/Logical Operator2' incorporates:
   *  Constant: '<S8>/Constant12'
   *  Constant: '<S8>/Constant13'
   *  RelationalOperator: '<S8>/Relational Operator6'
   *  RelationalOperator: '<S8>/Relational Operator7'
   */
  dspd_b_bcmOdoValid = ((swc_HMIF_ARID_DEF.DataTypeConversion133 > 0.0F) &&
                        (swc_HMIF_ARID_DEF.DataTypeConversion133 < 1.6383E+6F) &&
                        rtb_flg_out);

  /* Switch: '<S9>/Switch1' incorporates:
   *  Abs: '<S8>/Abs'
   *  Sum: '<S8>/Add'
   */
  rtb_Switch1 = swc_HMIF_ARID_DEF.DataTypeConversion134 -
    swc_HMIF_ARID_DEF.DataTypeConversion133;
  rtb_Switch1 = fabsf(rtb_Switch1);

  /* Logic: '<S8>/Logical Operator3' incorporates:
   *  Constant: '<S8>/Constant15'
   *  Constant: '<S8>/Constant16'
   *  MinMax: '<S8>/MinMax2'
   *  RelationalOperator: '<S8>/Relational Operator10'
   *  RelationalOperator: '<S8>/Relational Operator9'
   *  Sum: '<S8>/Add1'
   */
  dspd_b_odoBckpChgValid = (dspd_b_ipkOdoValid && dspd_b_bcmOdoValid &&
    (rtb_Switch1 <= dspc_d_odoBckpDiff_km) && (fmaxf
    (swc_HMIF_ARID_DEF.DataTypeConversion134,
     swc_HMIF_ARID_DEF.DataTypeConversion133) - dspd_d_odoRead_km >
    dspc_d_odoBckpDiff_km));

  /* Chart: '<S8>/OdometerBackup1' incorporates:
   *  DataTypeConversion: '<S8>/Data Type Conversion7'
   *  DataTypeConversion: '<S8>/Data Type Conversion8'
   *  DataTypeConversion: '<S8>/Data Type Conversion9'
   */
  if (swc_HMIF_ARID_DEF.is_active_c4_swc_HMIF == 0U) {
    swc_HMIF_ARID_DEF.is_active_c4_swc_HMIF = 1U;
    swc_HMIF_ARID_DEF.is_c4_swc_HMIF = swc_HMIF_IN_Init;
    dspd_b_odoBckpEn = false;
  } else {
    switch (swc_HMIF_ARID_DEF.is_c4_swc_HMIF) {
     case swc_HMIF_IN_BackupChange:
      if (swc_HMIF_ARID_DEF.t > 5.0F) {
        swc_HMIF_ARID_DEF.is_c4_swc_HMIF = swc_HMIF_IN_BackupHold;
        dspd_b_odoBckpEn = true;
      } else {
        swc_HMIF_ARID_DEF.t += 0.01F;
      }
      break;

     case swc_HMIF_IN_BackupHold:
      dspd_b_odoBckpEn = true;
      break;

     case swc_HMIF_IN_Delay_g:
      if (dspd_b_odoBckpChgValid) {
        swc_HMIF_ARID_DEF.is_c4_swc_HMIF = swc_HMIF_IN_BackupChange;
        dspd_d_odoBckp_km = fmax(swc_HMIF_ARID_DEF.DataTypeConversion134,
          swc_HMIF_ARID_DEF.DataTypeConversion133);
        swc_HMIF_ARID_DEF.t = 0.0F;
      } else if (swc_HMIF_ARID_DEF.t > 5.0F) {
        swc_HMIF_ARID_DEF.is_c4_swc_HMIF = swc_HMIF_IN_BackupHold;
        dspd_b_odoBckpEn = true;
      } else {
        swc_HMIF_ARID_DEF.t += 0.01F;
      }
      break;

     case swc_HMIF_IN_Init:
      dspd_b_odoBckpEn = false;
      if (swc_HMIF_ARID_DEF.DataTypeConversion14) {
        swc_HMIF_ARID_DEF.is_c4_swc_HMIF = swc_HMIF_IN_ReadNvm;
        swc_HMIF_ARID_DEF.t = 0.0F;
        dspd_d_odoBckp_km = dspd_d_odoRead_km;
      }
      break;

     default:
      /* case IN_ReadNvm: */
      if (swc_HMIF_ARID_DEF.t > 1.0F) {
        swc_HMIF_ARID_DEF.is_c4_swc_HMIF = swc_HMIF_IN_Delay_g;
        swc_HMIF_ARID_DEF.t = 0.0F;
      } else {
        swc_HMIF_ARID_DEF.t += 0.01F;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/OdometerBackup1' */

  /* Switch: '<S9>/Switch1' incorporates:
   *  Sum: '<S8>/Add2'
   */
  rtb_Switch1 = (float32)(rtb_Add7_g - dspd_d_odoBckp_km);

  /* Switch: '<S8>/Switch9' incorporates:
   *  Constant: '<S8>/Constant27'
   *  Constant: '<S8>/Constant28'
   *  Constant: '<S8>/Constant29'
   *  RelationalOperator: '<S8>/Relational Operator11'
   */
  if (rtb_Add7_g < 1.6777215E+6) {
    rtb_OR_f = true;
  } else {
    rtb_OR_f = false;
  }

  /* Switch: '<S8>/Switch10' incorporates:
   *  Constant: '<S202>/Constant'
   *  Constant: '<S8>/Constant30'
   *  Delay: '<S8>/Delay'
   *  Logic: '<S8>/AND1'
   *  RelationalOperator: '<S202>/Compare'
   *  RelationalOperator: '<S8>/Relational Operator13'
   *  Switch: '<S8>/Switch9'
   */
  if ((rtb_Switch1 >= 0.0F) && (rtb_Switch1 <= dspd_d_distRange) &&
      swc_HMIF_ARID_DEF.Delay_DSTATE_o && rtb_OR_f) {
    /* Switch: '<S8>/Switch10' */
    dspd_d_MileageInit = rtb_Add7_g;
  } else {
    /* Switch: '<S8>/Switch10' */
    dspd_d_MileageInit = dspd_d_odoBckp_km;
  }

  /* End of Switch: '<S8>/Switch10' */

  /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
   *  CCaller: '<S8>/C Caller5'
   */
  rtb_RelationalOperator3_n = mBSW_NvmRead_OdoClrCnt_flg();

  /* RelationalOperator: '<S199>/Compare' incorporates:
   *  Constant: '<S199>/Constant'
   */
  rtb_y_o = (rtb_RelationalOperator3_n == false);

  /* CCaller: '<S8>/C Caller3' */
  dspd_st_nvmMileageClrCnt = mBSW_NvmRead_OdoClrCnt();

  /* Switch: '<S8>/Switch4' */
  if (rtb_y_o) {
    /* Switch: '<S8>/Switch4' incorporates:
     *  Constant: '<S8>/Constant4'
     */
    dspd_st_odoClrCntRead = ((uint8)0U);
  } else {
    /* Switch: '<S8>/Switch4' */
    dspd_st_odoClrCntRead = dspd_st_nvmMileageClrCnt;
  }

  /* End of Switch: '<S8>/Switch4' */

  /* Gain: '<S8>/Gain1' incorporates:
   *  Constant: '<S8>/Constant2'
   *  MinMax: '<S8>/MinMax'
   */
  rtb_Gain1 = 1.03F * fminf(swc_HMIF_ARID_DEF.DataTypeConversion15, 240.0F);

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  dspd_v_vehSpd = rtb_Gain1;

  /* Logic: '<S8>/Logical Operator' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Valid'
   *  RelationalOperator: '<S8>/Relational Operator1'
   *  RelationalOperator: '<S8>/Relational Operator2'
   */
  dspd_b_OdoAddEn = ((swc_HMIF_ARID_DEF.DataTypeConversion15 > 2.0F) &&
                     (swc_HMIF_ARID_DEF.DataTypeConversion135 == true) &&
                     swc_HMIF_ARID_DEF.DataTypeConversion80);

  /* CCaller: '<S8>/C Caller' */
  dspd_b_odoClearActv = mBSW_RoutineReq_03E4();

  /* RelationalOperator: '<S205>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S205>/Delay Input1'
   *
   * Block description for '<S205>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_y_o = ((sint32)dspd_b_odoClearActv > (sint32)
             swc_HMIF_ARID_DEF.DelayInput1_DSTATE_a);

  /* Chart: '<S8>/OdometerAdd' */
  if (swc_HMIF_ARID_DEF.is_active_c1_swc_HMIF == 0U) {
    swc_HMIF_ARID_DEF.is_active_c1_swc_HMIF = 1U;
    swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_init_k;
    swc_HMIF_ARID_DEF.ClearCnt = dspd_st_odoClrCntRead;
    swc_HMIF_ARID_DEF.OdometerAdd = dspd_d_MileageInit;
  } else {
    switch (swc_HMIF_ARID_DEF.is_c1_swc_HMIF) {
     case swc_HMIF_IN_Add:
      if (!dspd_b_OdoAddEn) {
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Stop;
        dspd_ST = 3U;
      } else if ((swc_HMIF_ARID_DEF.OdometerAdd < 500.0) && rtb_y_o) {
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Delay;
        swc_HMIF_ARID_DEF.t_e = 0.0F;
        swc_HMIF_ARID_DEF.is_Delay = swc_HMIF_IN_CntAdd;
        i_0 = (sint32)(swc_HMIF_ARID_DEF.ClearCnt + 1U);
        if (swc_HMIF_ARID_DEF.ClearCnt + 1U > 255U) {
          i_0 = 255;
        }

        swc_HMIF_ARID_DEF.ClearCnt = (uint8)i_0;
        dspd_ST = 6U;
      } else {
        swc_HMIF_ARID_DEF.OdometerAdd += dspd_v_vehSpd * 0.01 / 3600.0;
        dspd_ST = 2U;
      }
      break;

     case swc_HMIF_IN_Delay:
      if (dspd_b_OdoAddEn && (swc_HMIF_ARID_DEF.t_e > 1.0F)) {
        swc_HMIF_ARID_DEF.is_Delay = 0;
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Add;
        swc_HMIF_ARID_DEF.OdometerAdd += dspd_v_vehSpd * 0.01 / 3600.0;
      } else if ((!dspd_b_OdoAddEn) && (swc_HMIF_ARID_DEF.t_e > 1.0F)) {
        swc_HMIF_ARID_DEF.is_Delay = 0;
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Stop;
        dspd_ST = 3U;
      } else {
        swc_HMIF_ARID_DEF.t_e += 0.01F;
        dspd_ST = 5U;
        if ((swc_HMIF_ARID_DEF.is_Delay == swc_HMIF_IN_CntAdd) &&
            (swc_HMIF_ARID_DEF.ClearCnt < 4)) {
          swc_HMIF_ARID_DEF.is_Delay = swc_HMIF_IN_clear;
          swc_HMIF_ARID_DEF.OdometerAdd = 0.0;
          dspd_ST = 7U;
        } else {
          /* case IN_clear: */
        }
      }
      break;

     case swc_HMIF_IN_Keep:
      if ((swc_HMIF_ARID_DEF.OdometerAdd < 500.0) && rtb_y_o) {
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Delay;
        swc_HMIF_ARID_DEF.t_e = 0.0F;
        swc_HMIF_ARID_DEF.is_Delay = swc_HMIF_IN_CntAdd;
        i_0 = (sint32)(swc_HMIF_ARID_DEF.ClearCnt + 1U);
        if (swc_HMIF_ARID_DEF.ClearCnt + 1U > 255U) {
          i_0 = 255;
        }

        swc_HMIF_ARID_DEF.ClearCnt = (uint8)i_0;
        dspd_ST = 6U;
      } else if (dspd_b_OdoAddEn && dspd_b_odoBckpEn) {
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Add;
        swc_HMIF_ARID_DEF.OdometerAdd += dspd_v_vehSpd * 0.01 / 3600.0;
      }
      break;

     case swc_HMIF_IN_Stop:
      if (dspd_b_OdoAddEn) {
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Add;
        swc_HMIF_ARID_DEF.OdometerAdd += dspd_v_vehSpd * 0.01 / 3600.0;
      } else if ((swc_HMIF_ARID_DEF.OdometerAdd < 500.0) && rtb_y_o) {
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Delay;
        swc_HMIF_ARID_DEF.t_e = 0.0F;
        swc_HMIF_ARID_DEF.is_Delay = swc_HMIF_IN_CntAdd;
        i_0 = (sint32)(swc_HMIF_ARID_DEF.ClearCnt + 1U);
        if (swc_HMIF_ARID_DEF.ClearCnt + 1U > 255U) {
          i_0 = 255;
        }

        swc_HMIF_ARID_DEF.ClearCnt = (uint8)i_0;
        dspd_ST = 6U;
      }
      break;

     default:
      /* case IN_init: */
      if (dspd_b_OdoAddEn && dspd_b_odoBckpEn) {
        swc_HMIF_ARID_DEF.OdometerAdd = dspd_d_MileageInit;
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Add;
        swc_HMIF_ARID_DEF.OdometerAdd += dspd_v_vehSpd * 0.01 / 3600.0;
      } else if ((!dspd_b_OdoAddEn) && dspd_b_odoBckpEn) {
        swc_HMIF_ARID_DEF.OdometerAdd = dspd_d_MileageInit;
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Keep;
        dspd_ST = 4U;
      } else if ((swc_HMIF_ARID_DEF.OdometerAdd < 500.0) && rtb_y_o) {
        swc_HMIF_ARID_DEF.OdometerAdd = dspd_d_MileageInit;
        swc_HMIF_ARID_DEF.is_c1_swc_HMIF = swc_HMIF_IN_Delay;
        swc_HMIF_ARID_DEF.t_e = 0.0F;
        swc_HMIF_ARID_DEF.is_Delay = swc_HMIF_IN_CntAdd;
        i_0 = (sint32)(swc_HMIF_ARID_DEF.ClearCnt + 1U);
        if (swc_HMIF_ARID_DEF.ClearCnt + 1U > 255U) {
          i_0 = 255;
        }

        swc_HMIF_ARID_DEF.ClearCnt = (uint8)i_0;
        dspd_ST = 6U;
      } else {
        swc_HMIF_ARID_DEF.OdometerAdd = dspd_d_MileageInit;
        dspd_ST = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S8>/OdometerAdd' */

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  rtb_DataTypeConversion1 = (float32)swc_HMIF_ARID_DEF.OdometerAdd;

  /* Switch: '<S8>/Switch1' */
  if (dspd_b_odoBckpEn) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant3'
     *  DataTypeConversion: '<S8>/Data Type Conversion1'
     *  MinMax: '<S8>/MinMax1'
     */
    dspd_d_odoTotal_km = fminf((float32)swc_HMIF_ARID_DEF.OdometerAdd, 999999.0F);
  } else {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant18'
     */
    dspd_d_odoTotal_km = 2.6843545E+6F;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* RelationalOperator: '<S71>/Compare' incorporates:
   *  Constant: '<S71>/Constant'
   */
  rtb_Compare_av = (dspd_d_odoTotal_km < 60.0F);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  CCaller: '<S74>/C Caller'
   */
  rtb_Switch_h = 0U;

  /* CCaller: '<S74>/C Caller' incorporates:
   *  Constant: '<S74>/InvalidValue_0XFFF'
   */
  Dem_GetEventStatus(((uint16)32895U), &rtb_Switch_h);

  /* DataTypeConversion: '<S12>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<S74>/Bitwise AND'
   */
  rtb_DataTypeConversion2_l = (uint8)(rtb_Switch_h & ((uint8)1U));

  /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
   *  DataTypeConversion: '<S74>/Data Type Conversion'
   */
  rtb_RelationalOperator3_n = (rtb_DataTypeConversion2_l != 0);

  /* Switch: '<S73>/Switch' incorporates:
   *  Constant: '<S72>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion56'
   *  Logic: '<S65>/OR'
   *  RelationalOperator: '<S65>/Relational Operator'
   *  Switch: '<S65>/Switch3'
   *  Switch: '<S65>/Switch9'
   *  UnitDelay: '<S65>/Unit Delay'
   *  UnitDelay: '<S73>/init'
   */
  if (swc_HMIF_ARID_DEF.init_DSTATE_a) {
    /* Switch: '<S9>/Switch1' */
    rtb_Switch1 = dspd_d_dynamicRange;
  } else {
    if (swc_HMIF_ARID_DEF.RelationalOperator_p ||
        swc_HMIF_ARID_DEF.UnitDelay_DSTATE_n ||
        (swc_HMIF_ARID_DEF.DataTypeConversion56 == PmmStatus_CHARGE)) {
      /* Switch: '<S65>/Switch3' incorporates:
       *  Constant: '<S65>/Constant13'
       */
      rtb_Divide_l = dspc_dn_RngIncGradH;

      /* Switch: '<S65>/Switch9' incorporates:
       *  Constant: '<S65>/Constant24'
       */
      rtb_CCaller1 = dspc_dn_RngDecGradH;
    } else {
      /* Switch: '<S65>/Switch3' incorporates:
       *  Constant: '<S65>/Constant26'
       */
      rtb_Divide_l = dspc_dn_RngIncGradL;

      /* Switch: '<S65>/Switch9' incorporates:
       *  Constant: '<S65>/Constant27'
       */
      rtb_CCaller1 = dspc_dn_RngDecGradL;
    }

    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S65>/Constant25'
     *  Constant: '<S73>/step_time6'
     *  MinMax: '<S73>/MinMax'
     *  MinMax: '<S73>/MinMax1'
     *  MinMax: '<S73>/MinMax2'
     *  MinMax: '<S73>/MinMax3'
     *  Product: '<S73>/Product'
     *  Product: '<S73>/Product1'
     *  Sum: '<S73>/Sum5'
     *  Sum: '<S73>/Sum6'
     *  Switch: '<S65>/Switch3'
     *  Switch: '<S65>/Switch9'
     *  UnitDelay: '<S73>/Unit Delay'
     */
    rtb_Switch1 = fminf(fmaxf(rtb_Divide_l * ((float32)DSP_TASK_INTERVAL_S),
      0.0F), fmaxf(dspd_d_dynamicRange - swc_HMIF_ARID_DEF.UnitDelay_DSTATE_a,
                   fminf(0.0F, ((float32)DSP_TASK_INTERVAL_S) * rtb_CCaller1)))
      + swc_HMIF_ARID_DEF.UnitDelay_DSTATE_a;
  }

  /* End of Switch: '<S73>/Switch' */

  /* DataTypeConversion: '<S73>/Data Type Conversion' */
  rtb_CCaller1 = rtb_Switch1;

  /* Switch: '<S65>/Switch4' incorporates:
   *  Logic: '<S65>/Logical Operator2'
   */
  if (rtb_Compare_av || rtb_RelationalOperator3_n) {
    /* Switch: '<S65>/Switch4' incorporates:
     *  Constant: '<S65>/InvalidValue_0X3FF'
     */
    dspd_d_vehDrvRngEVMod_km = dspc_d_vehDrvRngInvalid_km;
  } else {
    /* Switch: '<S65>/Switch4' incorporates:
     *  DataTypeConversion: '<S73>/Data Type Conversion'
     */
    dspd_d_vehDrvRngEVMod_km = rtb_Switch1;
  }

  /* End of Switch: '<S65>/Switch4' */

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  CCaller: '<S75>/C Caller'
   */
  rtb_Switch_h = 0U;

  /* CCaller: '<S75>/C Caller' incorporates:
   *  Constant: '<S75>/InvalidValue_0XFFF'
   */
  Dem_GetEventStatus(((uint16)32895U), &rtb_Switch_h);

  /* DataTypeConversion: '<S12>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<S75>/Bitwise AND'
   */
  rtb_DataTypeConversion2_l = (uint8)(rtb_Switch_h & ((uint8)1U));

  /* DataTypeConversion: '<S75>/Data Type Conversion' */
  rtb_Compare_av = (rtb_DataTypeConversion2_l != 0);

  /* RelationalOperator: '<S63>/Compare' incorporates:
   *  Constant: '<S63>/Constant'
   */
  swc_HMIF_ARID_DEF.Compare = (swc_HMIF_ConstB.DataTypeConversion127 == 2.0);

  /* Switch: '<S9>/Switch1' incorporates:
   *  Sum: '<S25>/Subtract'
   */
  rtb_Switch1 = swc_HMIF_ARID_DEF.DataTypeConversion85 -
    swc_HMIF_ARID_DEF.DataTypeConversion86;

  /* MinMax: '<S25>/MinMax2' incorporates:
   *  Constant: '<S25>/Constant10'
   */
  dspd_pwr_hvPwrRemain_kW = fmaxf(rtb_Switch1, ((float32)PWR_ZERO));

  /* CCaller: '<S112>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S112>/C Caller4' incorporates:
   *  Constant: '<S112>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32958U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S163>/Switch2' incorporates:
   *  Constant: '<S112>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildBMSFaultLevel3A_ovrdflg) {
    /* Switch: '<S163>/Switch2' incorporates:
     *  Constant: '<S112>/DFC_ovrdval'
     */
    dspd_b_bmsFltLvl3 = dspc_b_evtFaildBMSFaultLevel3A_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S112>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S163>/Switch2' incorporates:
     *  DataTypeConversion: '<S112>/con_3'
     */
    dspd_b_bmsFltLvl3 = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S163>/Switch2' */

  /* CCaller: '<S120>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S120>/C Caller4' incorporates:
   *  Constant: '<S120>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32956U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S171>/Switch2' incorporates:
   *  Constant: '<S120>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildMCUFaultLevel3A_ovrdflg) {
    /* Switch: '<S171>/Switch2' incorporates:
     *  Constant: '<S120>/DFC_ovrdval'
     */
    dspd_b_mcuFltLvl3 = dspc_b_evtFaildMCUFaultLevel3A_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S120>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S171>/Switch2' incorporates:
     *  DataTypeConversion: '<S120>/con_3'
     */
    dspd_b_mcuFltLvl3 = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S171>/Switch2' */

  /* CCaller: '<S130>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S130>/C Caller4' incorporates:
   *  Constant: '<S130>/Constant20'
   */
  Dem_GetEventStatus(((uint16)32973U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S181>/Switch2' incorporates:
   *  Constant: '<S130>/DFC_ovrdflg'
   */
  if (ddic_b_BMSHealthMonErr_ovrdflg) {
    /* Switch: '<S181>/Switch2' incorporates:
     *  Constant: '<S130>/DFC_ovrdval'
     */
    dspd_b_BMSHealthMonErr = ddic_b_BMSHealthMonErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S130>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S181>/Switch2' incorporates:
     *  DataTypeConversion: '<S130>/con_3'
     */
    dspd_b_BMSHealthMonErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S181>/Switch2' */

  /* CCaller: '<S90>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S90>/C Caller4' incorporates:
   *  Constant: '<S90>/Constant23'
   */
  Dem_GetEventStatus(((uint16)32974U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S141>/Switch2' incorporates:
   *  Constant: '<S90>/DFC_ovrdflg'
   */
  if (ddic_b_MCUHealthMonErr_ovrdflg) {
    /* Switch: '<S141>/Switch2' incorporates:
     *  Constant: '<S90>/DFC_ovrdval'
     */
    dspd_b_MCUHealthMonErr = ddic_b_MCUHealthMonErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S90>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S141>/Switch2' incorporates:
     *  DataTypeConversion: '<S90>/con_3'
     */
    dspd_b_MCUHealthMonErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S141>/Switch2' */

  /* CCaller: '<S129>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S129>/C Caller4' incorporates:
   *  Constant: '<S129>/DFC_Constant4'
   */
  Dem_GetEventStatus(((uint16)32896U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S180>/Switch2' incorporates:
   *  Constant: '<S129>/DFC_ovrdflg'
   */
  if (swchmif_ddic_b_evtFaildDCDCMsgErr_ovrdflg) {
    /* Switch: '<S180>/Switch2' incorporates:
     *  Constant: '<S129>/DFC_ovrdval'
     */
    dspd_b_DCDCMsgErr = swchmif_ddic_b_evtFaildDCDCMsgErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S129>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S180>/Switch2' incorporates:
     *  DataTypeConversion: '<S129>/con_3'
     */
    dspd_b_DCDCMsgErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S180>/Switch2' */

  /* CCaller: '<S135>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S135>/C Caller4' incorporates:
   *  Constant: '<S135>/DFC_Constant8'
   */
  Dem_GetEventStatus(((uint16)32894U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S186>/Switch2' incorporates:
   *  Constant: '<S135>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildABSMsgErr_ovrdflg) {
    /* Switch: '<S186>/Switch2' incorporates:
     *  Constant: '<S135>/DFC_ovrdval'
     */
    dspd_b_ABSMsgErr = swchmif_ddic_b_evtFaildABSMsgErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S135>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S186>/Switch2' incorporates:
     *  DataTypeConversion: '<S135>/con_3'
     */
    dspd_b_ABSMsgErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S186>/Switch2' */

  /* CCaller: '<S140>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S140>/C Caller4' incorporates:
   *  Constant: '<S140>/DFC_Constant9'
   */
  Dem_GetEventStatus(((uint16)32900U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S191>/Switch2' incorporates:
   *  Constant: '<S140>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildEGSMMsgErr_ovrdflg) {
    /* Switch: '<S191>/Switch2' incorporates:
     *  Constant: '<S140>/DFC_ovrdval'
     */
    dspd_b_EGSMMsgErr = dspc_b_evtFaildEGSMMsgErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S140>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S191>/Switch2' incorporates:
     *  DataTypeConversion: '<S140>/con_3'
     */
    dspd_b_EGSMMsgErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S191>/Switch2' */

  /* CCaller: '<S93>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S93>/C Caller4' incorporates:
   *  Constant: '<S93>/DFC_Constant16'
   */
  Dem_GetEventStatus(((uint16)32878U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S144>/Switch2' incorporates:
   *  Constant: '<S93>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildT5V1Mon_ovrdflg) {
    /* Switch: '<S144>/Switch2' incorporates:
     *  Constant: '<S93>/DFC_ovrdval'
     */
    dspd_b_T5V1Mon = dspc_b_evtFaildT5V1Mon_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S93>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S144>/Switch2' incorporates:
     *  DataTypeConversion: '<S93>/con_3'
     */
    dspd_b_T5V1Mon = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S144>/Switch2' */

  /* CCaller: '<S96>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S96>/C Caller4' incorporates:
   *  Constant: '<S96>/DFC_Constant17'
   */
  Dem_GetEventStatus(((uint16)32879U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S147>/Switch2' incorporates:
   *  Constant: '<S96>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildT5V2Mon_ovrdflg) {
    /* Switch: '<S147>/Switch2' incorporates:
     *  Constant: '<S96>/DFC_ovrdval'
     */
    dspd_b_T5V2Mon = dspc_b_evtFaildT5V2Mon_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S96>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S147>/Switch2' incorporates:
     *  DataTypeConversion: '<S96>/con_3'
     */
    dspd_b_T5V2Mon = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S147>/Switch2' */

  /* CCaller: '<S111>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S111>/C Caller4' incorporates:
   *  Constant: '<S111>/DFC_Constant22'
   */
  Dem_GetEventStatus(((uint16)32888U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S162>/Switch2' incorporates:
   *  Constant: '<S111>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedalCrossNP_ovrdflg) {
    /* Switch: '<S162>/Switch2' incorporates:
     *  Constant: '<S111>/DFC_ovrdval'
     */
    dspd_b_ACCPedalCrossNP = dspc_b_evtFaildACCPedalCrossNP_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S111>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S162>/Switch2' incorporates:
     *  DataTypeConversion: '<S111>/con_3'
     */
    dspd_b_ACCPedalCrossNP = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S162>/Switch2' */

  /* CCaller: '<S114>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S114>/C Caller4' incorporates:
   *  Constant: '<S114>/DFC_Constant23'
   */
  Dem_GetEventStatus(((uint16)32935U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S165>/Switch2' incorporates:
   *  Constant: '<S114>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildBrkSthNP_ovrdflg) {
    /* Switch: '<S165>/Switch2' incorporates:
     *  Constant: '<S114>/DFC_ovrdval'
     */
    dspd_b_BrkSthNP = dspc_b_evtFaildBrkSthNP_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S114>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S165>/Switch2' incorporates:
     *  DataTypeConversion: '<S114>/con_3'
     */
    dspd_b_BrkSthNP = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S165>/Switch2' */

  /* CCaller: '<S116>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S116>/C Caller4' incorporates:
   *  Constant: '<S116>/DFC_Constant27'
   */
  Dem_GetEventStatus(((uint16)32876U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S167>/Switch2' incorporates:
   *  Constant: '<S116>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildPwrSuplyORLow_ovrdflg) {
    /* Switch: '<S167>/Switch2' incorporates:
     *  Constant: '<S116>/DFC_ovrdval'
     */
    dspd_b_PwrSuplyORLow = dspc_b_evtFaildPwrSuplyORLow_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S116>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S167>/Switch2' incorporates:
     *  DataTypeConversion: '<S116>/con_3'
     */
    dspd_b_PwrSuplyORLow = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S167>/Switch2' */

  /* CCaller: '<S118>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S118>/C Caller4' incorporates:
   *  Constant: '<S118>/DFC_Constant28'
   */
  Dem_GetEventStatus(((uint16)32877U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S169>/Switch2' incorporates:
   *  Constant: '<S118>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildPwrSuplyORHigh_ovrdflg) {
    /* Switch: '<S169>/Switch2' incorporates:
     *  Constant: '<S118>/DFC_ovrdval'
     */
    dspd_b_PwrSuplyORHigh = dspc_b_evtFaildPwrSuplyORHigh_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S118>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S169>/Switch2' incorporates:
     *  DataTypeConversion: '<S118>/con_3'
     */
    dspd_b_PwrSuplyORHigh = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S169>/Switch2' */

  /* CCaller: '<S131>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S131>/C Caller4' incorporates:
   *  Constant: '<S131>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32880U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S182>/Switch2' incorporates:
   *  Constant: '<S131>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedal1SCG_ovrdflg) {
    /* Switch: '<S182>/Switch2' incorporates:
     *  Constant: '<S131>/DFC_ovrdval'
     */
    dspd_b_ACCPedal1SCG = dspc_b_evtFaildACCPedal1SCG_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S131>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S182>/Switch2' incorporates:
     *  DataTypeConversion: '<S131>/con_3'
     */
    dspd_b_ACCPedal1SCG = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S182>/Switch2' */

  /* CCaller: '<S132>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S132>/C Caller4' incorporates:
   *  Constant: '<S132>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32881U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S183>/Switch2' incorporates:
   *  Constant: '<S132>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedal1SCB_ovrdflg) {
    /* Switch: '<S183>/Switch2' incorporates:
     *  Constant: '<S132>/DFC_ovrdval'
     */
    dspd_b_ACCPedal1SCB = dspc_b_evtFaildACCPedal1SCB_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S132>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S183>/Switch2' incorporates:
     *  DataTypeConversion: '<S132>/con_3'
     */
    dspd_b_ACCPedal1SCB = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S183>/Switch2' */

  /* CCaller: '<S133>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S133>/C Caller4' incorporates:
   *  Constant: '<S133>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32882U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S184>/Switch2' incorporates:
   *  Constant: '<S133>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedal1ORLow_ovrdflg) {
    /* Switch: '<S184>/Switch2' incorporates:
     *  Constant: '<S133>/DFC_ovrdval'
     */
    dspd_b_ACCPedal1ORLow = dspc_b_evtFaildACCPedal1ORLow_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S133>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S184>/Switch2' incorporates:
     *  DataTypeConversion: '<S133>/con_3'
     */
    dspd_b_ACCPedal1ORLow = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S184>/Switch2' */

  /* CCaller: '<S134>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S134>/C Caller4' incorporates:
   *  Constant: '<S134>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32883U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S185>/Switch2' incorporates:
   *  Constant: '<S134>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedal1ORHigh_ovrdflg) {
    /* Switch: '<S185>/Switch2' incorporates:
     *  Constant: '<S134>/DFC_ovrdval'
     */
    dspd_b_ACCPedal1ORHigh = dspc_b_evtFaildACCPedal1ORHigh_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S134>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S185>/Switch2' incorporates:
     *  DataTypeConversion: '<S134>/con_3'
     */
    dspd_b_ACCPedal1ORHigh = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S185>/Switch2' */

  /* CCaller: '<S136>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S136>/C Caller4' incorporates:
   *  Constant: '<S136>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32884U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S187>/Switch2' incorporates:
   *  Constant: '<S136>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedal2SCG_ovrdflg) {
    /* Switch: '<S187>/Switch2' incorporates:
     *  Constant: '<S136>/DFC_ovrdval'
     */
    dspd_b_ACCPedal2SCG = dspc_b_evtFaildACCPedal2SCG_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S136>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S187>/Switch2' incorporates:
     *  DataTypeConversion: '<S136>/con_3'
     */
    dspd_b_ACCPedal2SCG = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S187>/Switch2' */

  /* CCaller: '<S137>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S137>/C Caller4' incorporates:
   *  Constant: '<S137>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32885U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S188>/Switch2' incorporates:
   *  Constant: '<S137>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedal2SCB_ovrdflg) {
    /* Switch: '<S188>/Switch2' incorporates:
     *  Constant: '<S137>/DFC_ovrdval'
     */
    dspd_b_ACCPedal2SCB = dspc_b_evtFaildACCPedal2SCB_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S137>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S188>/Switch2' incorporates:
     *  DataTypeConversion: '<S137>/con_3'
     */
    dspd_b_ACCPedal2SCB = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S188>/Switch2' */

  /* CCaller: '<S138>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S138>/C Caller4' incorporates:
   *  Constant: '<S138>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32886U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S189>/Switch2' incorporates:
   *  Constant: '<S138>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedal2ORLow_ovrdflg) {
    /* Switch: '<S189>/Switch2' incorporates:
     *  Constant: '<S138>/DFC_ovrdval'
     */
    dspd_b_ACCPedal2ORLow = dspc_b_evtFaildACCPedal2ORLow_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S138>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S189>/Switch2' incorporates:
     *  DataTypeConversion: '<S138>/con_3'
     */
    dspd_b_ACCPedal2ORLow = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S189>/Switch2' */

  /* CCaller: '<S139>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S139>/C Caller4' incorporates:
   *  Constant: '<S139>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32887U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S190>/Switch2' incorporates:
   *  Constant: '<S139>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildACCPedal2ORHigh_ovrdflg) {
    /* Switch: '<S190>/Switch2' incorporates:
     *  Constant: '<S139>/DFC_ovrdval'
     */
    dspd_b_ACCPedal2ORHigh = dspc_b_evtFaildACCPedal2ORHigh_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S139>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S190>/Switch2' incorporates:
     *  DataTypeConversion: '<S139>/con_3'
     */
    dspd_b_ACCPedal2ORHigh = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S190>/Switch2' */

  /* CCaller: '<S94>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S94>/C Caller4' incorporates:
   *  Constant: '<S94>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32891U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S145>/Switch2' incorporates:
   *  Constant: '<S94>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildEPCANBusoff_ovrdflg) {
    /* Switch: '<S145>/Switch2' incorporates:
     *  Constant: '<S94>/DFC_ovrdval'
     */
    dspd_b_EPCANBusoff = dspc_b_evtFaildEPCANBusoff_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S94>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S145>/Switch2' incorporates:
     *  DataTypeConversion: '<S94>/con_3'
     */
    dspd_b_EPCANBusoff = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S145>/Switch2' */

  /* CCaller: '<S95>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S95>/C Caller4' incorporates:
   *  Constant: '<S95>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32936U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S146>/Switch2' incorporates:
   *  Constant: '<S95>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildTPCANBusoff_ovrdflg) {
    /* Switch: '<S146>/Switch2' incorporates:
     *  Constant: '<S95>/DFC_ovrdval'
     */
    dspd_b_TPCANBusoff = dspc_b_evtFaildTPCANBusoff_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S95>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S146>/Switch2' incorporates:
     *  DataTypeConversion: '<S95>/con_3'
     */
    dspd_b_TPCANBusoff = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S146>/Switch2' */

  /* CCaller: '<S91>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S91>/C Caller4' incorporates:
   *  Constant: '<S91>/Constant17'
   */
  Dem_GetEventStatus(((uint16)32972U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S142>/Switch2' incorporates:
   *  Constant: '<S91>/DFC_ovrdflg'
   */
  if (dspc_b_ACUMsgErr_ovrdflg) {
    /* Switch: '<S142>/Switch2' incorporates:
     *  Constant: '<S91>/DFC_ovrdval'
     */
    dspd_b_ACUMsgErr = dspc_b_ACUMsgErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S91>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S142>/Switch2' incorporates:
     *  DataTypeConversion: '<S91>/con_3'
     */
    dspd_b_ACUMsgErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S142>/Switch2' */

  /* CCaller: '<S92>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S92>/C Caller4' incorporates:
   *  Constant: '<S92>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32902U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S143>/Switch2' incorporates:
   *  Constant: '<S92>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildABSSpdMsgErr_ovrdflg) {
    /* Switch: '<S143>/Switch2' incorporates:
     *  Constant: '<S92>/DFC_ovrdval'
     */
    dspd_b_ABSSpdMsgErr = dspc_b_evtFaildABSSpdMsgErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S92>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S143>/Switch2' incorporates:
     *  DataTypeConversion: '<S92>/con_3'
     */
    dspd_b_ABSSpdMsgErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S143>/Switch2' */

  /* CCaller: '<S97>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S97>/C Caller4' incorporates:
   *  Constant: '<S97>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32920U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S148>/Switch2' incorporates:
   *  Constant: '<S97>/DFC_ovrdflg'
   */
  if (dspc_b_EDCPOverTempSet_ovrdflg) {
    /* Switch: '<S148>/Switch2' incorporates:
     *  Constant: '<S97>/DFC_ovrdval'
     */
    dspd_b_EDCPOverTemp = dspc_b_EDCPOverTempSet_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S97>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S148>/Switch2' incorporates:
     *  DataTypeConversion: '<S97>/con_3'
     */
    dspd_b_EDCPOverTemp = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S148>/Switch2' */

  /* CCaller: '<S99>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S99>/C Caller4' incorporates:
   *  Constant: '<S99>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32921U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S150>/Switch2' incorporates:
   *  Constant: '<S99>/DFC_ovrdflg'
   */
  if (dspc_b_EDCPIdlySet_ovrdflg) {
    /* Switch: '<S150>/Switch2' incorporates:
     *  Constant: '<S99>/DFC_ovrdval'
     */
    dspd_b_EDCPIdly = dspc_b_EDCPIdlySet_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S99>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S150>/Switch2' incorporates:
     *  DataTypeConversion: '<S99>/con_3'
     */
    dspd_b_EDCPIdly = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S150>/Switch2' */

  /* CCaller: '<S101>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S101>/C Caller4' incorporates:
   *  Constant: '<S101>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32922U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S152>/Switch2' incorporates:
   *  Constant: '<S101>/DFC_ovrdflg'
   */
  if (dspc_b_EDCPUnderVoltSet_ovrdflg) {
    /* Switch: '<S152>/Switch2' incorporates:
     *  Constant: '<S101>/DFC_ovrdval'
     */
    dspd_b_EDCPUnderVolt = dspc_b_EDCPUnderVoltSet_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S101>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S152>/Switch2' incorporates:
     *  DataTypeConversion: '<S101>/con_3'
     */
    dspd_b_EDCPUnderVolt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S152>/Switch2' */

  /* CCaller: '<S100>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S100>/C Caller4' incorporates:
   *  Constant: '<S100>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32923U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S151>/Switch2' incorporates:
   *  Constant: '<S100>/DFC_ovrdflg'
   */
  if (dspc_b_EDCPOverVoltSet_ovrdflg) {
    /* Switch: '<S151>/Switch2' incorporates:
     *  Constant: '<S100>/DFC_ovrdval'
     */
    dspd_b_EDCPOverVolt = dspc_b_EDCPOverVoltSet_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S100>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S151>/Switch2' incorporates:
     *  DataTypeConversion: '<S100>/con_3'
     */
    dspd_b_EDCPOverVolt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S151>/Switch2' */

  /* CCaller: '<S102>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S102>/C Caller4' incorporates:
   *  Constant: '<S102>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32924U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S153>/Switch2' incorporates:
   *  Constant: '<S102>/DFC_ovrdflg'
   */
  if (dspc_b_EDCPBlockingSet_ovrdflg) {
    /* Switch: '<S153>/Switch2' incorporates:
     *  Constant: '<S102>/DFC_ovrdval'
     */
    dspd_b_EDCPBlocking = dspc_b_EDCPBlockingSet_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S102>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S153>/Switch2' incorporates:
     *  DataTypeConversion: '<S102>/con_3'
     */
    dspd_b_EDCPBlocking = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S153>/Switch2' */

  /* CCaller: '<S98>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S98>/C Caller4' incorporates:
   *  Constant: '<S98>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32925U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S149>/Switch2' incorporates:
   *  Constant: '<S98>/DFC_ovrdflg'
   */
  if (dspc_b_EDCPOverCurrSet_ovrdflg) {
    /* Switch: '<S149>/Switch2' incorporates:
     *  Constant: '<S98>/DFC_ovrdval'
     */
    dspd_b_EDCPOverCurr = dspc_b_EDCPOverCurrSet_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S98>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S149>/Switch2' incorporates:
     *  DataTypeConversion: '<S98>/con_3'
     */
    dspd_b_EDCPOverCurr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S149>/Switch2' */

  /* CCaller: '<S105>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S105>/C Caller4' incorporates:
   *  Constant: '<S105>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32947U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S156>/Switch2' incorporates:
   *  Constant: '<S105>/DFC_ovrdflg'
   */
  if (dspc_b_hbcpOvrTmp_ovrdflg) {
    /* Switch: '<S156>/Switch2' incorporates:
     *  Constant: '<S105>/DFC_ovrdval'
     */
    dspd_b_HBCPOvrTmp = dspc_b_hbcpOvrTmp_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S105>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S156>/Switch2' incorporates:
     *  DataTypeConversion: '<S105>/con_3'
     */
    dspd_b_HBCPOvrTmp = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S156>/Switch2' */

  /* CCaller: '<S104>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S104>/C Caller4' incorporates:
   *  Constant: '<S104>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32948U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S155>/Switch2' incorporates:
   *  Constant: '<S104>/DFC_ovrdflg'
   */
  if (dspc_b_hbcpIdly_ovrdflg) {
    /* Switch: '<S155>/Switch2' incorporates:
     *  Constant: '<S104>/DFC_ovrdval'
     */
    dspd_b_HbcpIdly = dspc_b_hbcpIdly_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S104>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S155>/Switch2' incorporates:
     *  DataTypeConversion: '<S104>/con_3'
     */
    dspd_b_HbcpIdly = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S155>/Switch2' */

  /* CCaller: '<S103>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S103>/C Caller4' incorporates:
   *  Constant: '<S103>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32949U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S154>/Switch2' incorporates:
   *  Constant: '<S103>/DFC_ovrdflg'
   */
  if (dspc_b_hbcpUdVolt_ovrdflg) {
    /* Switch: '<S154>/Switch2' incorporates:
     *  Constant: '<S103>/DFC_ovrdval'
     */
    dspd_b_HBCPUdVolt = dspc_b_hbcpUdVolt_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S103>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S154>/Switch2' incorporates:
     *  DataTypeConversion: '<S103>/con_3'
     */
    dspd_b_HBCPUdVolt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S154>/Switch2' */

  /* CCaller: '<S106>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S106>/C Caller4' incorporates:
   *  Constant: '<S106>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32950U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S157>/Switch2' incorporates:
   *  Constant: '<S106>/DFC_ovrdflg'
   */
  if (dspc_b_hbcpOvrVolt_ovrdflg) {
    /* Switch: '<S157>/Switch2' incorporates:
     *  Constant: '<S106>/DFC_ovrdval'
     */
    dspd_b_HBCPOvrVolt = dspc_b_hbcpOvrVolt_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S106>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S157>/Switch2' incorporates:
     *  DataTypeConversion: '<S106>/con_3'
     */
    dspd_b_HBCPOvrVolt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S157>/Switch2' */

  /* CCaller: '<S107>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S107>/C Caller4' incorporates:
   *  Constant: '<S107>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32951U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S158>/Switch2' incorporates:
   *  Constant: '<S107>/DFC_ovrdflg'
   */
  if (dspc_b_hbcpBlock_ovrdflg) {
    /* Switch: '<S158>/Switch2' incorporates:
     *  Constant: '<S107>/DFC_ovrdval'
     */
    dspd_b_HBCPBlock = dspc_b_hbcpBlock_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S107>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S158>/Switch2' incorporates:
     *  DataTypeConversion: '<S107>/con_3'
     */
    dspd_b_HBCPBlock = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S158>/Switch2' */

  /* CCaller: '<S108>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S108>/C Caller4' incorporates:
   *  Constant: '<S108>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32952U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S159>/Switch2' incorporates:
   *  Constant: '<S108>/DFC_ovrdflg'
   */
  if (dspc_b_hbcpOvrCurr_ovrdflg) {
    /* Switch: '<S159>/Switch2' incorporates:
     *  Constant: '<S108>/DFC_ovrdval'
     */
    dspd_b_HBCPOvrCurr = dspc_b_hbcpOvrCurr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S108>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S159>/Switch2' incorporates:
     *  DataTypeConversion: '<S108>/con_3'
     */
    dspd_b_HBCPOvrCurr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S159>/Switch2' */

  /* CCaller: '<S109>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S109>/C Caller4' incorporates:
   *  Constant: '<S109>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32945U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S160>/Switch2' incorporates:
   *  Constant: '<S109>/DFC_ovrdflg'
   */
  if (dspc_b_PEPSMsgInvDataErr_ovrdflg) {
    /* Switch: '<S160>/Switch2' incorporates:
     *  Constant: '<S109>/DFC_ovrdval'
     */
    dspd_b_PEPSMsgInvDataErr = dspc_b_PEPSMsgInvDataErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S109>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S160>/Switch2' incorporates:
     *  DataTypeConversion: '<S109>/con_3'
     */
    dspd_b_PEPSMsgInvDataErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S160>/Switch2' */

  /* CCaller: '<S119>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S119>/C Caller4' incorporates:
   *  Constant: '<S119>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32957U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S170>/Switch2' incorporates:
   *  Constant: '<S119>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildBMSFaultLevel2A_ovrdflg) {
    /* Switch: '<S170>/Switch2' incorporates:
     *  Constant: '<S119>/DFC_ovrdval'
     */
    dspd_b_BMSFaultLevel2 = dspc_b_evtFaildBMSFaultLevel2A_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S119>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S170>/Switch2' incorporates:
     *  DataTypeConversion: '<S119>/con_3'
     */
    dspd_b_BMSFaultLevel2 = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S170>/Switch2' */

  /* CCaller: '<S113>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S113>/C Caller4' incorporates:
   *  Constant: '<S113>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32955U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S164>/Switch2' incorporates:
   *  Constant: '<S113>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildMCUFaultLevel2A_ovrdflg) {
    /* Switch: '<S164>/Switch2' incorporates:
     *  Constant: '<S113>/DFC_ovrdval'
     */
    dspd_b_MCUFaultLevel2 = dspc_b_evtFaildMCUFaultLevel2A_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S113>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S164>/Switch2' incorporates:
     *  DataTypeConversion: '<S113>/con_3'
     */
    dspd_b_MCUFaultLevel2 = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S164>/Switch2' */

  /* CCaller: '<S115>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S115>/C Caller4' incorporates:
   *  Constant: '<S115>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32913U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S166>/Switch2' incorporates:
   *  Constant: '<S115>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildVehicleHVILFlt_ovrdflg) {
    /* Switch: '<S166>/Switch2' incorporates:
     *  Constant: '<S115>/DFC_ovrdval'
     */
    dspd_b_VehicleHVILFlt = dspc_b_evtFaildVehicleHVILFlt_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S115>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S166>/Switch2' incorporates:
     *  DataTypeConversion: '<S115>/con_3'
     */
    dspd_b_VehicleHVILFlt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S166>/Switch2' */

  /* CCaller: '<S117>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S117>/C Caller4' incorporates:
   *  Constant: '<S117>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32914U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S168>/Switch2' incorporates:
   *  Constant: '<S117>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildCrashEvent_ovrdflg) {
    /* Switch: '<S168>/Switch2' incorporates:
     *  Constant: '<S117>/DFC_ovrdval'
     */
    dspd_b_CrashEvent = dspc_b_evtFaildCrashEvent_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S117>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)8U);

    /* Switch: '<S168>/Switch2' incorporates:
     *  DataTypeConversion: '<S117>/con_3'
     */
    dspd_b_CrashEvent = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S168>/Switch2' */

  /* CCaller: '<S121>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S121>/C Caller4' incorporates:
   *  Constant: '<S121>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32892U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S172>/Switch2' incorporates:
   *  Constant: '<S121>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildEVCANBusoff_ovrdflg) {
    /* Switch: '<S172>/Switch2' incorporates:
     *  Constant: '<S121>/DFC_ovrdval'
     */
    dspd_b_EVCANBusoff = dspc_b_evtFaildEVCANBusoff_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S121>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S172>/Switch2' incorporates:
     *  DataTypeConversion: '<S121>/con_3'
     */
    dspd_b_EVCANBusoff = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S172>/Switch2' */

  /* CCaller: '<S122>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S122>/C Caller4' incorporates:
   *  Constant: '<S122>/event_id11'
   */
  Dem_GetEventStatus(((uint16)32918U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S173>/Switch2' incorporates:
   *  Constant: '<S122>/DFC_ovrdflg'
   */
  if (ddic_b_evtFaildVacPumpSnr_ovrdflg) {
    /* Switch: '<S173>/Switch2' incorporates:
     *  Constant: '<S122>/DFC_ovrdval'
     */
    dspd_b_VacPumpSnrFlt = ddic_b_evtFaildVacPumpSnr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S122>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S173>/Switch2' incorporates:
     *  DataTypeConversion: '<S122>/con_3'
     */
    dspd_b_VacPumpSnrFlt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S173>/Switch2' */

  /* CCaller: '<S123>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S123>/C Caller4' incorporates:
   *  Constant: '<S123>/event_id12'
   */
  Dem_GetEventStatus(((uint16)32915U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S174>/Switch2' incorporates:
   *  Constant: '<S123>/DFC_ovrdflg'
   */
  if (ddic_b_evtFaildVacPumpLoPre_ovrdflg) {
    /* Switch: '<S174>/Switch2' incorporates:
     *  Constant: '<S123>/DFC_ovrdval'
     */
    dspd_b_VacPumpLoPreFlt = ddic_b_evtFaildVacPumpLoPre_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S123>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S174>/Switch2' incorporates:
     *  DataTypeConversion: '<S123>/con_3'
     */
    dspd_b_VacPumpLoPreFlt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S174>/Switch2' */

  /* CCaller: '<S124>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S124>/C Caller4' incorporates:
   *  Constant: '<S124>/event_id13'
   */
  Dem_GetEventStatus(((uint16)32916U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S175>/Switch2' incorporates:
   *  Constant: '<S124>/DFC_ovrdflg'
   */
  if (ddic_b_evtFaildVpEnOvTmHiPre_ovrdflg) {
    /* Switch: '<S175>/Switch2' incorporates:
     *  Constant: '<S124>/DFC_ovrdval'
     */
    dspd_b_VacPumpEnOvrTmHiPreFlt = ddic_b_evtFaildVpEnOvTmHiPre_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S124>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S175>/Switch2' incorporates:
     *  DataTypeConversion: '<S124>/con_3'
     */
    dspd_b_VacPumpEnOvrTmHiPreFlt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S175>/Switch2' */

  /* CCaller: '<S125>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S125>/C Caller4' incorporates:
   *  Constant: '<S125>/event_id14'
   */
  Dem_GetEventStatus(((uint16)32917U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S176>/Switch2' incorporates:
   *  Constant: '<S125>/DFC_ovrdflg'
   */
  if (ddic_b_evtFaildVpEnOvTmLoPre_ovrdflg) {
    /* Switch: '<S176>/Switch2' incorporates:
     *  Constant: '<S125>/DFC_ovrdval'
     */
    dspd_b_VacPumpEnOvrTmLoPreFlt = ddic_b_evtFaildVpEnOvTmLoPre_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S125>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S176>/Switch2' incorporates:
     *  DataTypeConversion: '<S125>/con_3'
     */
    dspd_b_VacPumpEnOvrTmLoPreFlt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S176>/Switch2' */

  /* CCaller: '<S126>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S126>/C Caller4' incorporates:
   *  Constant: '<S126>/event_id2'
   */
  Dem_GetEventStatus(((uint16)32983U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S177>/Switch2' incorporates:
   *  Constant: '<S126>/DFC_ovrdflg'
   */
  if (ddic_b_evtFaildVpSysFail_ovrdflg) {
    /* Switch: '<S177>/Switch2' incorporates:
     *  Constant: '<S126>/DFC_ovrdval'
     */
    dspd_b_VacPumpSysFailFlt = ddic_b_evtFaildVpSysFail_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S126>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S177>/Switch2' incorporates:
     *  DataTypeConversion: '<S126>/con_3'
     */
    dspd_b_VacPumpSysFailFlt = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S177>/Switch2' */

  /* CCaller: '<S127>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S127>/C Caller4' incorporates:
   *  Constant: '<S127>/event_id16'
   */
  Dem_GetEventStatus(((uint16)32982U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S178>/Switch2' incorporates:
   *  Constant: '<S127>/DFC_ovrdflg'
   */
  if (ddic_b_VacPumpRlyErr_ovrdflg) {
    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S127>/DFC_ovrdval'
     */
    dspd_b_VacPumpRlyErr = ddic_b_VacPumpRlyErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S127>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S178>/Switch2' incorporates:
     *  DataTypeConversion: '<S127>/con_3'
     */
    dspd_b_VacPumpRlyErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S178>/Switch2' */

  /* CCaller: '<S128>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S128>/C Caller4' incorporates:
   *  Constant: '<S128>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32959U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S179>/Switch2' incorporates:
   *  Constant: '<S128>/DFC_ovrdflg'
   */
  if (dspc_b_evtFaildBMSFaultLevel4A_ovrdflg) {
    /* Switch: '<S179>/Switch2' incorporates:
     *  Constant: '<S128>/DFC_ovrdval'
     */
    dspd_b_bmsFltLvl4 = dspc_b_evtFaildBMSFaultLevel4A_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S128>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)8U);

    /* Switch: '<S179>/Switch2' incorporates:
     *  DataTypeConversion: '<S128>/con_3'
     */
    dspd_b_bmsFltLvl4 = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S179>/Switch2' */

  /* CCaller: '<S110>/C Caller4' */
  rtb_DataTypeConversion2_l = 0U;

  /* CCaller: '<S110>/C Caller4' incorporates:
   *  Constant: '<S110>/Constant26'
   */
  Dem_GetEventStatus(((uint16)32975U), &rtb_DataTypeConversion2_l);

  /* Switch: '<S161>/Switch2' incorporates:
   *  Constant: '<S110>/DFC_ovrdflg'
   */
  if (dspc_b_CSMMsgErr_ovrdflg) {
    /* Switch: '<S161>/Switch2' incorporates:
     *  Constant: '<S110>/DFC_ovrdval'
     */
    dspd_b_CSMMsgErr = dspc_b_CSMMsgErr_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S110>/Bitwise And1' */
    rtb_DataTypeConversion2_l &= ((uint8)1U);

    /* Switch: '<S161>/Switch2' incorporates:
     *  DataTypeConversion: '<S110>/con_3'
     */
    dspd_b_CSMMsgErr = (rtb_DataTypeConversion2_l != 0);
  }

  /* End of Switch: '<S161>/Switch2' */

  /* Logic: '<S5>/Logical Operator' incorporates:
   *  Chart: '<S5>/ErrorCodeChart'
   *  SignalConversion generated from: '<S78>/ SFunction '
   */
  tmpForInput_tmp[0] = dspd_b_bmsFltLvl3;
  tmpForInput_tmp[1] = dspd_b_mcuFltLvl3;
  tmpForInput_tmp[2] = dspd_b_BMSHealthMonErr;
  tmpForInput_tmp[3] = dspd_b_MCUHealthMonErr;
  tmpForInput_tmp[4] = dspd_b_DCDCMsgErr;
  tmpForInput_tmp[5] = dspd_b_ABSMsgErr;
  tmpForInput_tmp[6] = dspd_b_EGSMMsgErr;
  tmpForInput_tmp[7] = dspd_b_T5V1Mon;
  tmpForInput_tmp[8] = dspd_b_T5V2Mon;
  tmpForInput_tmp[9] = dspd_b_ACCPedalCrossNP;
  tmpForInput_tmp[10] = dspd_b_BrkSthNP;
  tmpForInput_tmp[11] = dspd_b_PwrSuplyORLow;
  tmpForInput_tmp[12] = dspd_b_PwrSuplyORHigh;
  tmpForInput_tmp[13] = dspd_b_ACCPedal1SCG;
  tmpForInput_tmp[14] = dspd_b_ACCPedal1SCB;
  tmpForInput_tmp[15] = dspd_b_ACCPedal1ORLow;
  tmpForInput_tmp[16] = dspd_b_ACCPedal1ORHigh;
  tmpForInput_tmp[17] = dspd_b_ACCPedal2SCG;
  tmpForInput_tmp[18] = dspd_b_ACCPedal2SCB;
  tmpForInput_tmp[19] = dspd_b_ACCPedal2ORLow;
  tmpForInput_tmp[20] = dspd_b_ACCPedal2ORHigh;
  tmpForInput_tmp[21] = dspd_b_EPCANBusoff;
  tmpForInput_tmp[22] = dspd_b_TPCANBusoff;
  tmpForInput_tmp[23] = dspd_b_ACUMsgErr;
  tmpForInput_tmp[24] = dspd_b_ABSSpdMsgErr;
  tmpForInput_tmp[25] = dspd_b_EDCPOverTemp;
  tmpForInput_tmp[26] = dspd_b_EDCPIdly;
  tmpForInput_tmp[27] = dspd_b_EDCPUnderVolt;
  tmpForInput_tmp[28] = dspd_b_EDCPOverVolt;
  tmpForInput_tmp[29] = dspd_b_EDCPBlocking;
  tmpForInput_tmp[30] = dspd_b_EDCPOverCurr;
  tmpForInput_tmp[31] = dspd_b_HBCPOvrTmp;
  tmpForInput_tmp[32] = dspd_b_HbcpIdly;
  tmpForInput_tmp[33] = dspd_b_HBCPUdVolt;
  tmpForInput_tmp[34] = dspd_b_HBCPOvrVolt;
  tmpForInput_tmp[35] = dspd_b_HBCPBlock;
  tmpForInput_tmp[36] = dspd_b_HBCPOvrCurr;
  tmpForInput_tmp[37] = dspd_b_PEPSMsgInvDataErr;
  tmpForInput_tmp[38] = dspd_b_BMSFaultLevel2;
  tmpForInput_tmp[39] = dspd_b_MCUFaultLevel2;
  tmpForInput_tmp[40] = dspd_b_VehicleHVILFlt;
  tmpForInput_tmp[41] = dspd_b_CrashEvent;
  tmpForInput_tmp[42] = dspd_b_EVCANBusoff;
  tmpForInput_tmp[43] = dspd_b_VacPumpSnrFlt;
  tmpForInput_tmp[44] = dspd_b_VacPumpLoPreFlt;
  tmpForInput_tmp[45] = dspd_b_VacPumpEnOvrTmHiPreFlt;
  tmpForInput_tmp[46] = dspd_b_VacPumpEnOvrTmLoPreFlt;
  tmpForInput_tmp[47] = dspd_b_VacPumpSysFailFlt;
  tmpForInput_tmp[48] = dspd_b_VacPumpRlyErr;
  tmpForInput_tmp[49] = dspd_b_bmsFltLvl4;
  tmpForInput_tmp[50] = dspd_b_CSMMsgErr;
  rtb_RelationalOperator3_n = dspd_b_bmsFltLvl3;
  for (i_0 = 0; i_0 < 50; i_0++) {
    rtb_RelationalOperator3_n = (rtb_RelationalOperator3_n ||
      tmpForInput_tmp[i_0 + 1]);
  }

  /* End of Logic: '<S5>/Logical Operator' */

  /* SignalConversion generated from: '<S78>/ SFunction ' incorporates:
   *  Chart: '<S5>/ErrorCodeChart'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant10'
   *  Constant: '<S5>/Constant11'
   *  Constant: '<S5>/Constant12'
   *  Constant: '<S5>/Constant13'
   *  Constant: '<S5>/Constant14'
   *  Constant: '<S5>/Constant15'
   *  Constant: '<S5>/Constant16'
   *  Constant: '<S5>/Constant17'
   *  Constant: '<S5>/Constant18'
   *  Constant: '<S5>/Constant19'
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant20'
   *  Constant: '<S5>/Constant21'
   *  Constant: '<S5>/Constant22'
   *  Constant: '<S5>/Constant23'
   *  Constant: '<S5>/Constant24'
   *  Constant: '<S5>/Constant25'
   *  Constant: '<S5>/Constant26'
   *  Constant: '<S5>/Constant27'
   *  Constant: '<S5>/Constant28'
   *  Constant: '<S5>/Constant29'
   *  Constant: '<S5>/Constant3'
   *  Constant: '<S5>/Constant30'
   *  Constant: '<S5>/Constant31'
   *  Constant: '<S5>/Constant32'
   *  Constant: '<S5>/Constant33'
   *  Constant: '<S5>/Constant34'
   *  Constant: '<S5>/Constant35'
   *  Constant: '<S5>/Constant36'
   *  Constant: '<S5>/Constant37'
   *  Constant: '<S5>/Constant38'
   *  Constant: '<S5>/Constant39'
   *  Constant: '<S5>/Constant4'
   *  Constant: '<S5>/Constant40'
   *  Constant: '<S5>/Constant41'
   *  Constant: '<S5>/Constant42'
   *  Constant: '<S5>/Constant43'
   *  Constant: '<S5>/Constant44'
   *  Constant: '<S5>/Constant45'
   *  Constant: '<S5>/Constant46'
   *  Constant: '<S5>/Constant47'
   *  Constant: '<S5>/Constant48'
   *  Constant: '<S5>/Constant49'
   *  Constant: '<S5>/Constant5'
   *  Constant: '<S5>/Constant53'
   *  Constant: '<S5>/Constant54'
   *  Constant: '<S5>/Constant6'
   *  Constant: '<S5>/Constant7'
   *  Constant: '<S5>/Constant8'
   *  Constant: '<S5>/Constant9'
   */
  rtb_TmpSignalConversionAtSFunct[0] = ((uint16)1003U);
  rtb_TmpSignalConversionAtSFunct[1] = ((uint16)2003U);
  rtb_TmpSignalConversionAtSFunct[2] = ((uint16)3402U);
  rtb_TmpSignalConversionAtSFunct[3] = ((uint16)3403U);
  rtb_TmpSignalConversionAtSFunct[4] = ((uint16)3104U);
  rtb_TmpSignalConversionAtSFunct[5] = ((uint16)3108U);
  rtb_TmpSignalConversionAtSFunct[6] = ((uint16)3111U);
  rtb_TmpSignalConversionAtSFunct[7] = ((uint16)3203U);
  rtb_TmpSignalConversionAtSFunct[8] = ((uint16)3204U);
  rtb_TmpSignalConversionAtSFunct[9] = ((uint16)3207U);
  rtb_TmpSignalConversionAtSFunct[10] = ((uint16)3210U);
  rtb_TmpSignalConversionAtSFunct[11] = ((uint16)3301U);
  rtb_TmpSignalConversionAtSFunct[12] = ((uint16)3303U);
  rtb_TmpSignalConversionAtSFunct[13] = ((uint16)3222U);
  rtb_TmpSignalConversionAtSFunct[14] = ((uint16)3223U);
  rtb_TmpSignalConversionAtSFunct[15] = ((uint16)3224U);
  rtb_TmpSignalConversionAtSFunct[16] = ((uint16)3225U);
  rtb_TmpSignalConversionAtSFunct[17] = ((uint16)3226U);
  rtb_TmpSignalConversionAtSFunct[18] = ((uint16)3227U);
  rtb_TmpSignalConversionAtSFunct[19] = ((uint16)3228U);
  rtb_TmpSignalConversionAtSFunct[20] = ((uint16)3229U);
  rtb_TmpSignalConversionAtSFunct[21] = ((uint16)3140U);
  rtb_TmpSignalConversionAtSFunct[22] = ((uint16)3141U);
  rtb_TmpSignalConversionAtSFunct[23] = ((uint16)3401U);
  rtb_TmpSignalConversionAtSFunct[24] = ((uint16)3137U);
  rtb_TmpSignalConversionAtSFunct[25] = ((uint16)3367U);
  rtb_TmpSignalConversionAtSFunct[26] = ((uint16)3368U);
  rtb_TmpSignalConversionAtSFunct[27] = ((uint16)3369U);
  rtb_TmpSignalConversionAtSFunct[28] = ((uint16)3370U);
  rtb_TmpSignalConversionAtSFunct[29] = ((uint16)3371U);
  rtb_TmpSignalConversionAtSFunct[30] = ((uint16)3372U);
  rtb_TmpSignalConversionAtSFunct[31] = ((uint16)3382U);
  rtb_TmpSignalConversionAtSFunct[32] = ((uint16)3383U);
  rtb_TmpSignalConversionAtSFunct[33] = ((uint16)3384U);
  rtb_TmpSignalConversionAtSFunct[34] = ((uint16)3385U);
  rtb_TmpSignalConversionAtSFunct[35] = ((uint16)3386U);
  rtb_TmpSignalConversionAtSFunct[36] = ((uint16)3387U);
  rtb_TmpSignalConversionAtSFunct[37] = ((uint16)3388U);
  rtb_TmpSignalConversionAtSFunct[38] = ((uint16)1002U);
  rtb_TmpSignalConversionAtSFunct[39] = ((uint16)2002U);
  rtb_TmpSignalConversionAtSFunct[40] = ((uint16)3491U);
  rtb_TmpSignalConversionAtSFunct[41] = ((uint16)3358U);
  rtb_TmpSignalConversionAtSFunct[42] = ((uint16)3150U);
  rtb_TmpSignalConversionAtSFunct[43] = ((uint16)9028U);
  rtb_TmpSignalConversionAtSFunct[44] = ((uint16)9025U);
  rtb_TmpSignalConversionAtSFunct[45] = ((uint16)9026U);
  rtb_TmpSignalConversionAtSFunct[46] = ((uint16)9027U);
  rtb_TmpSignalConversionAtSFunct[47] = ((uint16)9029U);
  rtb_TmpSignalConversionAtSFunct[48] = ((uint16)9024U);
  rtb_TmpSignalConversionAtSFunct[49] = ((uint16)1004U);
  rtb_TmpSignalConversionAtSFunct[50] = ((uint16)3404U);

  /* Chart: '<S5>/ErrorCodeChart' */
  i = 0U;
  rtb_Product = sizeof(boolean);
  if (rtb_Product == 0U) {
    rtb_Product = MAX_uint32_T;

    /* Divide by zero handler */
  } else {
    rtb_Product = sizeof(boolean [51]) / rtb_Product;
  }

  rtb_CCaller2 = sizeof(uint16);
  if (rtb_CCaller2 == 0U) {
    rtb_CCaller2 = MAX_uint32_T;

    /* Divide by zero handler */
  } else {
    rtb_CCaller2 = sizeof(uint16 [51]) / rtb_CCaller2;
  }

  if ((uint16)rtb_CCaller2 != (uint16)rtb_Product) {
    rtb_dspd_num_errorCode = 0U;
  } else {
    do {
      if (swc_HMIF_ARID_DEF.LatchedList[i]) {
        swc_HMIF_ARID_DEF.LatchedList[i] = (tmpForInput_tmp[i] ||
          (swc_HMIF_ARID_DEF.DispTm[i] < dspc_tm_DisplayTime_s));
      } else {
        swc_HMIF_ARID_DEF.LatchedList[i] = tmpForInput_tmp[i];
      }

      i++;
    } while (i < (uint16)rtb_Product);

    i = 0U;
    sint32 exitg3;
    boolean guard11 = false;
    do {
      exitg3 = 0;
      guard11 = false;
      if (swc_HMIF_ARID_DEF.LatchedList[i]) {
        if (swc_HMIF_ARID_DEF.DispTm[i] < dspc_tm_DisplayTime_s) {
          rtb_dspd_num_errorCode = rtb_TmpSignalConversionAtSFunct[i];
          swc_HMIF_ARID_DEF.DispTm[i] += ((float32)DSP_TASK_INTERVAL_S);
          while (i < (uint16)rtb_Product - 1) {
            i++;
            swc_HMIF_ARID_DEF.DispTm[i] = 0.0F;
          }

          exitg3 = 1;
        } else {
          i++;
          entryg1 = 0;
          guard11 = true;
        }
      } else {
        i++;
        entryg1 = 1;
        guard11 = true;
      }

      if (guard11) {
        sint32 exitg2;
        do {
          exitg2 = 0;
          if (entryg1 == 0) {
          } else {
            entryg1 = 0;
          }

          if (i < (uint16)rtb_Product) {
            exitg2 = 2;
          } else if (rtb_RelationalOperator3_n) {
            for (i = 0U; i < (uint16)rtb_Product; i++) {
              swc_HMIF_ARID_DEF.DispTm[i] = 0.0F;
            }

            i = 0U;
          } else {
            rtb_dspd_num_errorCode = 0U;
            exitg2 = 1;
          }
        } while (exitg2 == 0);

        if (exitg2 == 1) {
          exitg3 = 1;
        }
      }
    } while (exitg3 == 0);
  }

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  dspd_num_errorCode = (float32)rtb_dspd_num_errorCode;

  /* Logic: '<S83>/Logical Operator7' */
  dspd_b_turtleLmpOn = (swc_HMIF_ARID_DEF.DataTypeConversion94 ||
                        swc_HMIF_ARID_DEF.DataTypeConversion111 ||
                        swc_HMIF_ARID_DEF.DataTypeConversion115);

  /* Logic: '<S80>/Logical Operator8' */
  rtb_RelationalOperator3_n = (swc_HMIF_ARID_DEF.DataTypeConversion110 ||
    swc_HMIF_ARID_DEF.DataTypeConversion112 ||
    swc_HMIF_ARID_DEF.DataTypeConversion113);

  /* Logic: '<S80>/Logical Operator1' incorporates:
   *  Logic: '<S80>/Logical Operator8'
   */
  rtb_LogicalOperator1 = !rtb_RelationalOperator3_n;

  /* Logic: '<S80>/Logical Operator7' incorporates:
   *  Logic: '<S80>/Logical Operator8'
   */
  rtb_LogicalOperator7 = (rtb_RelationalOperator3_n &&
    swc_HMIF_ARID_DEF.DataTypeConversion14);

  /* Outputs for Atomic SubSystem: '<S80>/SR_latch' */
  swc_HMIF_SR_latch_k(rtb_LogicalOperator7, rtb_LogicalOperator1,
                      &swc_HMIF_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S80>/SR_latch' */

  /* Logic: '<S82>/Logical Operator8' incorporates:
   *  Logic: '<S80>/Logical Operator8'
   */
  dspd_b_ePTFault = rtb_RelationalOperator3_n;

  /* Outputs for Enabled SubSystem: '<S88>/Subsystem' incorporates:
   *  EnablePort: '<S89>/Enable'
   */
  if (swc_HMIF_ARID_DEF.DataTypeConversion137) {
    if (!swc_HMIF_ARID_DEF.Subsystem_MODE) {
      /* InitializeConditions for UnitDelay: '<S89>/Unit Delay5' */
      swc_HMIF_ARID_DEF.UnitDelay5_DSTATE = 0.0;
      swc_HMIF_ARID_DEF.Subsystem_MODE = true;
    }

    /* Sum: '<S89>/Add7' incorporates:
     *  Constant: '<S89>/Constant'
     *  UnitDelay: '<S89>/Unit Delay5'
     */
    rtb_Add7_g = 0.01 + swc_HMIF_ARID_DEF.UnitDelay5_DSTATE;

    /* RelationalOperator: '<S89>/Relational Operator' incorporates:
     *  Constant: '<S89>/Constant1'
     */
    swc_HMIF_ARID_DEF.RelationalOperator = (5.0 <= rtb_Add7_g);

    /* Update for UnitDelay: '<S89>/Unit Delay5' */
    swc_HMIF_ARID_DEF.UnitDelay5_DSTATE = rtb_Add7_g;
  } else if (swc_HMIF_ARID_DEF.Subsystem_MODE) {
    /* Disable for RelationalOperator: '<S89>/Relational Operator' incorporates:
     *  Outport: '<S89>/Out1'
     */
    swc_HMIF_ARID_DEF.RelationalOperator = false;
    swc_HMIF_ARID_DEF.Subsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S88>/Subsystem' */

  /* RelationalOperator: '<S77>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion56'
   *  RelationalOperator: '<S77>/Relational Operator1'
   */
  rtb_RelationalOperator_j_tmp = swc_HMIF_ARID_DEF.DataTypeConversion56;

  /* RelationalOperator: '<S77>/Relational Operator' incorporates:
   *  Constant: '<S85>/Constant'
   */
  rtb_RelationalOperator_j = (rtb_RelationalOperator_j_tmp ==
    PmmStatus_STANDBYDRV);

  /* RelationalOperator: '<S77>/Relational Operator1' incorporates:
   *  Constant: '<S86>/Constant'
   */
  rtb_RelationalOperator1_f = (rtb_RelationalOperator_j_tmp ==
    PmmStatus_BMSNEGOPEN);

  /* Outputs for Atomic SubSystem: '<S77>/SR_latch1' */
  swc_HMIF_SR_latch(rtb_RelationalOperator_j, rtb_RelationalOperator1_f,
                    &rtb_LogicalOperator3_d,
                    &swc_HMIF_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of Outputs for SubSystem: '<S77>/SR_latch1' */

  /* Switch: '<S77>/Switch4' incorporates:
   *  Logic: '<S77>/Logical Operator10'
   *  Logic: '<S77>/Logical Operator13'
   *  Switch: '<S77>/Switch3'
   */
  if (swc_HMIF_ARID_DEF.DataTypeConversion44 &&
      swc_HMIF_ARID_DEF.DataTypeConversion80) {
    /* Switch: '<S77>/Switch4' incorporates:
     *  Constant: '<S77>/Constant5'
     */
    dspd_st_drvPfmncRedn = ((uint16)2U);
  } else if (swc_HMIF_ARID_DEF.DataTypeConversion139 &&
             swc_HMIF_ARID_DEF.DataTypeConversion80) {
    /* Switch: '<S77>/Switch4' incorporates:
     *  Constant: '<S77>/Constant4'
     *  Switch: '<S77>/Switch3'
     */
    dspd_st_drvPfmncRedn = ((uint16)3U);
  } else {
    /* Logic: '<S77>/Logical Operator11' incorporates:
     *  Logic: '<S77>/Logical Operator5'
     *  Switch: '<S77>/Switch1'
     *  Switch: '<S77>/Switch3'
     */
    rtb_OR_f = !swc_HMIF_ARID_DEF.DataTypeConversion62;

    /* Switch: '<S77>/Switch1' incorporates:
     *  Logic: '<S77>/Logical Operator11'
     *  Logic: '<S77>/Logical Operator8'
     *  Logic: '<S77>/Logical Operator9'
     *  Logic: '<S77>/OR'
     *  Switch: '<S77>/Switch3'
     */
    if (swc_HMIF_ARID_DEF.DataTypeConversion139 ||
        (swc_HMIF_ARID_DEF.DataTypeConversion44 &&
         (!swc_HMIF_ARID_DEF.DataTypeConversion80) && rtb_OR_f)) {
      /* Switch: '<S77>/Switch4' incorporates:
       *  Constant: '<S77>/Constant3'
       *  Switch: '<S77>/Switch1'
       */
      dspd_st_drvPfmncRedn = ((uint16)5U);
    } else {
      /* Logic: '<S5>/OR' */
      rtb_RelationalOperator3_n = (swc_HMIF_ARID_DEF.DataTypeConversion141 ||
        swc_HMIF_ARID_DEF.DataTypeConversion116);

      /* Switch: '<S77>/Switch2' incorporates:
       *  Constant: '<S84>/Constant'
       *  Logic: '<S77>/AND'
       *  Logic: '<S77>/Logical Operator18'
       *  Logic: '<S77>/Logical Operator19'
       *  Logic: '<S77>/Logical Operator2'
       *  Logic: '<S77>/Logical Operator4'
       *  Logic: '<S77>/NOT'
       *  Logic: '<S77>/OR1'
       *  Logic: '<S77>/OR2'
       *  RelationalOperator: '<S84>/Compare'
       *  Switch: '<S77>/Switch'
       *  Switch: '<S77>/Switch5'
       *  Switch: '<S77>/Switch7'
       */
      if ((swc_HMIF_ARID_DEF.DataTypeConversion132 ||
           swc_HMIF_ARID_DEF.DataTypeConversion114 || rtb_RelationalOperator3_n ||
           swc_HMIF_ARID_DEF.DataTypeConversion140) && rtb_OR_f) {
        /* Switch: '<S77>/Switch4' incorporates:
         *  Constant: '<S77>/Constant8'
         *  Switch: '<S77>/Switch1'
         *  Switch: '<S77>/Switch2'
         */
        dspd_st_drvPfmncRedn = ((uint16)6U);
      } else if ((swc_HMIF_ARID_DEF.DataTypeConversion114 ||
                  rtb_RelationalOperator3_n) &&
                 swc_HMIF_ARID_DEF.DataTypeConversion62) {
        /* Switch: '<S77>/Switch7' incorporates:
         *  Constant: '<S77>/Constant7'
         *  Switch: '<S77>/Switch4'
         */
        dspd_st_drvPfmncRedn = ((uint16)8U);
      } else if (0.0 < 0.0) {
        /* Switch: '<S77>/Switch5' incorporates:
         *  Constant: '<S77>/Constant6'
         *  Switch: '<S77>/Switch4'
         *  Switch: '<S77>/Switch7'
         */
        dspd_st_drvPfmncRedn = ((uint16)1U);
      } else if ((swc_HMIF_ARID_DEF.RelationalOperator &&
                  (swc_HMIF_ARID_DEF.DataTypeConversion15 <= 3.0F) &&
                  rtb_LogicalOperator3_d) || ((!rtb_LogicalOperator3_d) &&
                  swc_HMIF_ARID_DEF.DataTypeConversion137)) {
        /* Switch: '<S77>/Switch' incorporates:
         *  Constant: '<S77>/Constant'
         *  Switch: '<S77>/Switch4'
         *  Switch: '<S77>/Switch5'
         *  Switch: '<S77>/Switch7'
         */
        dspd_st_drvPfmncRedn = ((uint16)14U);
      } else {
        /* Switch: '<S77>/Switch4' incorporates:
         *  Constant: '<S77>/Constant1'
         *  Switch: '<S77>/Switch'
         *  Switch: '<S77>/Switch5'
         *  Switch: '<S77>/Switch7'
         */
        dspd_st_drvPfmncRedn = ((uint16)0U);
      }

      /* End of Switch: '<S77>/Switch2' */
    }
  }

  /* End of Switch: '<S77>/Switch4' */

  /* Logic: '<S81>/Logical Operator8' */
  dspd_b_brkSysFlt = (swc_HMIF_ARID_DEF.DataTypeConversion11 ||
                      swc_HMIF_ARID_DEF.DataTypeConversion12);

  /* Relay: '<S6>/Relay3' */
  swc_HMIF_ARID_DEF.Relay3_Mode = ((swc_HMIF_ARID_DEF.DataTypeConversion15 >=
    dspc_v_vehSpdHiHEVRange_kph) || ((swc_HMIF_ARID_DEF.DataTypeConversion15 >
    dspc_v_vehSpdLoHEVRange_kph) && swc_HMIF_ARID_DEF.Relay3_Mode));

  /* Switch: '<S218>/Switch1' incorporates:
   *  Constant: '<S218>/Constant1'
   */
  if (dspc_b_useFuelRateForFC) {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Gain: '<S218>/Gain1'
     */
    rtb_Switch1 = 0.277777791F * swc_HMIF_ARID_DEF.DataTypeConversion55;
  } else {
    /* Sum: '<S218>/Add' incorporates:
     *  Delay: '<S218>/Delay'
     */
    rtb_Add_k = (float32)(swc_HMIF_ARID_DEF.DataTypeConversion7 -
                          swc_HMIF_ARID_DEF.Delay_DSTATE);

    /* Switch: '<S218>/Switch2' incorporates:
     *  Constant: '<S218>/Constant5'
     *  RelationalOperator: '<S218>/Relational Operator12'
     */
    if (rtb_Add_k < (-1.0F)) {
      /* Switch: '<S218>/Switch2' incorporates:
       *  Constant: '<S218>/Constant3'
       *  Sum: '<S218>/Add1'
       */
      rtb_Add_k += 20.0F;
    }

    /* End of Switch: '<S218>/Switch2' */

    /* Switch: '<S9>/Switch1' incorporates:
     *  Gain: '<S218>/Gain'
     */
    rtb_Switch1 = 10.0F * rtb_Add_k;
  }

  /* End of Switch: '<S218>/Switch1' */

  /* Saturate: '<S218>/Saturation' */
  if (rtb_Switch1 > 20.0F) {
    /* Switch: '<S9>/Switch1' */
    rtb_Switch1 = 20.0F;
  } else if (rtb_Switch1 < 0.0F) {
    /* Switch: '<S9>/Switch1' */
    rtb_Switch1 = 0.0F;
  }

  /* End of Saturate: '<S218>/Saturation' */

  /* Switch: '<S219>/Switch' incorporates:
   *  UnitDelay: '<S219>/init'
   */
  if (!swc_HMIF_ARID_DEF.init_DSTATE_j) {
    /* Product: '<S219>/Divide' incorporates:
     *  Constant: '<S218>/Constant7'
     *  Constant: '<S218>/Constant8'
     *  DataTypeConversion: '<S219>/Data Type Conversion1'
     *  DataTypeConversion: '<S219>/Data Type Conversion2'
     *  Sum: '<S219>/Add1'
     */
    rtb_Add_k = dspc_tm_FCFilter_s / (dspc_tm_FCFilter_s + ((float32)
      DSP_TASK_INTERVAL_S));

    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S219>/Constant'
     *  DataTypeConversion: '<S219>/Data Type Conversion'
     *  Product: '<S219>/Product'
     *  Product: '<S219>/Product1'
     *  Sum: '<S219>/Add'
     *  Sum: '<S219>/Add2'
     *  UnitDelay: '<S219>/Unit Delay'
     */
    rtb_Switch1 = (1.0F - rtb_Add_k) * rtb_Switch1 + rtb_Add_k *
      swc_HMIF_ARID_DEF.UnitDelay_DSTATE_ci;
  }

  /* End of Switch: '<S219>/Switch' */

  /* DataTypeConversion: '<S219>/Data Type Conversion3' */
  dspd_dV_engFuelConsInst_mlps = rtb_Switch1;

  /* Relay: '<S6>/Relay2' */
  swc_HMIF_ARID_DEF.Relay2_Mode = ((dspd_dV_engFuelConsInst_mlps >=
    dspc_FCHiHEVRange_mlps) || ((dspd_dV_engFuelConsInst_mlps >
    dspc_FCLoHEVRange_mlps) && swc_HMIF_ARID_DEF.Relay2_Mode));
  if (swc_HMIF_ARID_DEF.Relay2_Mode) {
    /* DataTypeConversion: '<S12>/Data Type Conversion1' */
    rtb_Switch_h = ((uint8)1U);
  } else {
    /* DataTypeConversion: '<S12>/Data Type Conversion1' */
    rtb_Switch_h = ((uint8)0U);
  }

  /* End of Relay: '<S6>/Relay2' */

  /* Logic: '<S6>/Logical Operator3' incorporates:
   *  Constant: '<S6>/Constant6'
   *  Logic: '<S6>/Logical Operator1'
   */
  rtb_OR_f = !dspc_b_FCAllAlowed;

  /* Logic: '<S6>/Logical Operator2' incorporates:
   *  Logic: '<S6>/Logical Operator3'
   */
  rtb_RelationalOperator3_n = ((rtb_Switch_h != 0) || rtb_OR_f);

  /* Switch: '<S6>/Switch2' */
  if (rtb_RelationalOperator3_n) {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Gain: '<S6>/Gain'
     */
    rtb_Add_k = 3.6F * dspd_dV_engFuelConsInst_mlps;
  } else {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Delay: '<S6>/Delay1'
     */
    rtb_Add_k = swc_HMIF_ARID_DEF.Delay1_DSTATE;
  }

  /* End of Switch: '<S6>/Switch2' */

  /* Logic: '<S6>/Logical Operator' */
  rtb_RelationalOperator3_n = ((rtb_Switch_h != 0) || rtb_OR_f);

  /* Switch: '<S6>/Switch1' */
  if (rtb_RelationalOperator3_n) {
    /* Relay: '<S6>/Relay3' */
    if (swc_HMIF_ARID_DEF.Relay3_Mode) {
      rtb_Switch_h = ((uint8)1U);
    } else {
      rtb_Switch_h = ((uint8)0U);
    }

    /* Switch: '<S6>/Switch4' incorporates:
     *  Constant: '<S6>/Constant5'
     *  Relay: '<S6>/Relay3'
     */
    if (rtb_Switch_h != 0) {
      rtb_Divide_l = swc_HMIF_ARID_DEF.DataTypeConversion15;
    } else {
      rtb_Divide_l = dspc_v_dfltVehSpdHEVRange_kph;
    }

    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Constant4'
     *  MinMax: '<S6>/MinMax1'
     *  Product: '<S6>/Divide3'
     *  Product: '<S6>/Divide4'
     *  Switch: '<S6>/Switch4'
     */
    dspd_d_vehDrvRngHEVModUnfilt_km = swc_HMIF_ARID_DEF.DataTypeConversion13 *
      rtb_Divide_l / fmaxf(rtb_Add_k, 0.01F);
  } else {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Delay: '<S6>/Delay2'
     */
    dspd_d_vehDrvRngHEVModUnfilt_km = swc_HMIF_ARID_DEF.Delay2_DSTATE_d;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Switch: '<S193>/Switch' incorporates:
   *  UnitDelay: '<S193>/init'
   */
  if (swc_HMIF_ARID_DEF.init_DSTATE_o) {
    /* Switch: '<S9>/Switch1' incorporates:
     *  DataTypeConversion: '<S193>/Data Type Conversion'
     */
    rtb_Switch1 = dspd_d_vehDrvRngHEVModUnfilt_km;
  } else {
    /* Product: '<S193>/Divide' incorporates:
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant2'
     *  DataTypeConversion: '<S193>/Data Type Conversion1'
     *  DataTypeConversion: '<S193>/Data Type Conversion2'
     *  Sum: '<S193>/Add1'
     */
    rtb_Divide_l = dspc_tm_HEVRangeFilter_s / (dspc_tm_HEVRangeFilter_s +
      ((float32)DSP_TASK_INTERVAL_S));

    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S193>/Constant'
     *  DataTypeConversion: '<S193>/Data Type Conversion'
     *  Product: '<S193>/Product'
     *  Product: '<S193>/Product1'
     *  Sum: '<S193>/Add'
     *  Sum: '<S193>/Add2'
     *  UnitDelay: '<S193>/Unit Delay'
     */
    rtb_Switch1 = (1.0F - rtb_Divide_l) * dspd_d_vehDrvRngHEVModUnfilt_km +
      rtb_Divide_l * swc_HMIF_ARID_DEF.UnitDelay_DSTATE_f;
  }

  /* End of Switch: '<S193>/Switch' */

  /* DataTypeConversion: '<S193>/Data Type Conversion3' */
  dspd_d_vehDrvRngHEVMod_km = rtb_Switch1;

  /* DataTypeConversion: '<S7>/Data Type Conversion3' */
  rtb_Divide_l = fmodf(floorf(swc_HMIF_ARID_DEF.DataTypeConversion5),
                       4.2949673E+9F);

  /* DataTypeConversion: '<S7>/Data Type Conversion3' */
  rtb_CCaller2 = rtb_Divide_l < 0.0F ? (uint32)-(sint32)(uint32)-rtb_Divide_l :
    (uint32)rtb_Divide_l;

  /* RelationalOperator: '<S194>/Compare' incorporates:
   *  Constant: '<S194>/Constant'
   *  Delay: '<S7>/Delay'
   *  Sum: '<S7>/Add'
   */
  rtb_Compare_a = (rtb_CCaller2 - swc_HMIF_ARID_DEF.Delay_DSTATE_h <= 100U);

  /* Product: '<S7>/Divide' incorporates:
   *  Constant: '<S7>/Constant3'
   */
  if (100U == 0U) {
    rtb_Product = MAX_uint32_T;

    /* Divide by zero handler */
  } else {
    rtb_Product = rtb_CCaller2 / 100U;
  }

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Product: '<S7>/Divide'
   */
  rtb_Product *= 100U;

  /* Outputs for Atomic SubSystem: '<S7>/turnON_delay' */
  /* Constant: '<S7>/Constant19' incorporates:
   *  Constant: '<S7>/Constant15'
   */
  swc_HMIF_turnON_delay(rtb_Compare_a, dspc_t_ipkOdoBckUp_s, ((float32)
    DSP_TASK_INTERVAL_S), &rtb_flg_out_e,
                        &swc_HMIF_ARID_DEF.ARID_DEF_turnON_delay);

  /* End of Outputs for SubSystem: '<S7>/turnON_delay' */

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  Constant: '<S195>/Constant'
   *  RelationalOperator: '<S195>/Compare'
   *  RelationalOperator: '<S7>/Relational Operator'
   */
  rtb_RelationalOperator3_n = ((rtb_CCaller2 >= 500U) && rtb_flg_out_e &&
    (rtb_CCaller2 > swc_HMIF_ConstB.DataTypeConversion2));

  /* Chart: '<S7>/odometerbackup' */
  if (swc_HMIF_ARID_DEF.is_active_c14_swc_HMIF == 0U) {
    swc_HMIF_ARID_DEF.is_active_c14_swc_HMIF = 1U;
    swc_HMIF_ARID_DEF.is_c14_swc_HMIF = swc_HMIF_IN_init;
    swc_HMIF_ARID_DEF.Odometerbackup_write = swc_HMIF_ConstB.DataTypeConversion2;
    swc_HMIF_ARID_DEF.Count = 0U;
    swc_HMIF_ARID_DEF.count_enable = 0U;
  } else {
    boolean guard1 = false;
    guard1 = false;
    switch (swc_HMIF_ARID_DEF.is_c14_swc_HMIF) {
     case swc_HMIF_IN_backup_off:
      if (swc_HMIF_ARID_DEF.DataTypeConversion92 && rtb_RelationalOperator3_n &&
          swc_HMIF_ARID_DEF.DataTypeConversion14) {
        swc_HMIF_ARID_DEF.is_c14_swc_HMIF = swc_HMIF_IN_enable;
        swc_HMIF_ARID_DEF.Count = 0U;
      } else if ((!swc_HMIF_ARID_DEF.DataTypeConversion92) &&
                 (swc_HMIF_ARID_DEF.count_enable == 1)) {
        swc_HMIF_ARID_DEF.is_c14_swc_HMIF = swc_HMIF_IN_backup_unable;
        swc_HMIF_ARID_DEF.Count = 0U;
      } else {
        i_0 = swc_HMIF_ARID_DEF.Count + 1;
        if (swc_HMIF_ARID_DEF.Count + 1 > 65535) {
          i_0 = 65535;
        }

        swc_HMIF_ARID_DEF.Count = (uint16)i_0;
      }
      break;

     case swc_HMIF_IN_backup_unable:
      if (!swc_HMIF_ARID_DEF.DataTypeConversion14) {
        swc_HMIF_ARID_DEF.count_enable = 0U;
        swc_HMIF_ARID_DEF.is_c14_swc_HMIF = swc_HMIF_IN_backup_off;
        swc_HMIF_ARID_DEF.Count = 0U;
      } else {
        i_0 = swc_HMIF_ARID_DEF.Count + 1;
        if (swc_HMIF_ARID_DEF.Count + 1 > 65535) {
          i_0 = 65535;
        }

        swc_HMIF_ARID_DEF.Count = (uint16)i_0;
      }
      break;

     case swc_HMIF_IN_enable:
      if ((swc_HMIF_ARID_DEF.Odometerbackup_write > rtb_Product) ||
          (!swc_HMIF_ARID_DEF.DataTypeConversion14) ||
          (!rtb_RelationalOperator3_n)) {
        guard1 = true;
      } else if (!swc_HMIF_ARID_DEF.DataTypeConversion92) {
        swc_HMIF_ARID_DEF.count_enable = 1U;
        guard1 = true;
      } else {
        swc_HMIF_ARID_DEF.Odometerbackup_write = rtb_Product;
        i_0 = swc_HMIF_ARID_DEF.Count + 1;
        if (swc_HMIF_ARID_DEF.Count + 1 > 65535) {
          i_0 = 65535;
        }

        swc_HMIF_ARID_DEF.Count = (uint16)i_0;
      }
      break;

     default:
      /* case IN_init: */
      if (swc_HMIF_ARID_DEF.Count > 10) {
        swc_HMIF_ARID_DEF.is_c14_swc_HMIF = swc_HMIF_IN_backup_off;
        swc_HMIF_ARID_DEF.Count = 0U;
      } else {
        i_0 = swc_HMIF_ARID_DEF.Count + 1;
        if (swc_HMIF_ARID_DEF.Count + 1 > 65535) {
          i_0 = 65535;
        }

        swc_HMIF_ARID_DEF.Count = (uint16)i_0;
      }
      break;
    }

    if (guard1) {
      swc_HMIF_ARID_DEF.is_c14_swc_HMIF = swc_HMIF_IN_backup_off;
      swc_HMIF_ARID_DEF.Count = 0U;
    }
  }

  /* End of Chart: '<S7>/odometerbackup' */

  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  dspd_d_pmsOdoBckUpMilg_km = (float32)swc_HMIF_ARID_DEF.Odometerbackup_write;

  /* Switch: '<S8>/Switch3' incorporates:
   *  Constant: '<S8>/Constant23'
   */
  if (dspd_b_odoTotal2NVM_ovrdflg) {
    /* Switch: '<S8>/Switch3' incorporates:
     *  Constant: '<S8>/Constant22'
     */
    dspd_d_odoWrite_km = dspd_b_odoTotal2NVM_ovrdval;
  } else {
    /* Switch: '<S8>/Switch3' */
    dspd_d_odoWrite_km = rtb_DataTypeConversion1;
  }

  /* End of Switch: '<S8>/Switch3' */

  /* RelationalOperator: '<S204>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S204>/Delay Input1'
   *
   * Block description for '<S204>/Delay Input1':
   *
   *  Store in Global RAM
   */
  dspd_b_ignOFFodoWriteEn = ((sint32)swc_HMIF_ARID_DEF.DataTypeConversion14 <
    (sint32)swc_HMIF_ARID_DEF.DelayInput1_DSTATE_j);

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S206>/Enable'
   */
  if (dspd_b_OdoAddEn) {
    swc_HMIF_ARID_DEF.EnabledSubsystem_MODE = true;

    /* Delay: '<S206>/Delay' incorporates:
     *  UnitDelay: '<S206>/Unit Delay'
     */
    if (swc_HMIF_ARID_DEF.UnitDelay_DSTATE_h4 &&
        (swc_HMIF_ARID_DEF.Delay_Reset_ZCE != POS_ZCSIG)) {
      swc_HMIF_ARID_DEF.Delay_DSTATE_d = 0.0;
    }

    swc_HMIF_ARID_DEF.Delay_Reset_ZCE = swc_HMIF_ARID_DEF.UnitDelay_DSTATE_h4;

    /* Sum: '<S206>/Add' incorporates:
     *  Constant: '<S206>/Constant19'
     *  Constant: '<S206>/Constant20'
     *  Delay: '<S206>/Delay'
     *  Product: '<S206>/Divide'
     */
    rtb_Add7_g = rtb_Gain1 * 0.01F / 3600.0F + swc_HMIF_ARID_DEF.Delay_DSTATE_d;

    /* RelationalOperator: '<S206>/Relational Operator11' incorporates:
     *  Constant: '<S206>/Constant17'
     */
    dspd_b_rtStorageEn = (rtb_Add7_g >= dspc_d_odoWriteSet_km);

    /* Update for UnitDelay: '<S206>/Unit Delay' */
    swc_HMIF_ARID_DEF.UnitDelay_DSTATE_h4 = dspd_b_rtStorageEn;

    /* Update for Delay: '<S206>/Delay' */
    swc_HMIF_ARID_DEF.Delay_DSTATE_d = rtb_Add7_g;
  } else if (swc_HMIF_ARID_DEF.EnabledSubsystem_MODE) {
    /* Disable for RelationalOperator: '<S206>/Relational Operator11' incorporates:
     *  Outport: '<S206>/dspd_b_ignONodoWriteEn'
     */
    dspd_b_rtStorageEn = false;
    swc_HMIF_ARID_DEF.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem' */

  /* Logic: '<S8>/OR' incorporates:
   *  UnitDelay: '<S8>/Unit Delay2'
   */
  dspd_b_odoWriteEn = (dspd_b_ignOFFodoWriteEn || dspd_b_rtStorageEn ||
                       swc_HMIF_ARID_DEF.UnitDelay2_DSTATE_h);

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S207>/Enable'
   */
  if (dspd_b_odoWriteEn) {
    /* DataTypeConversion: '<S207>/Data Type Conversion' incorporates:
     *  Gain: '<S207>/Gain'
     */
    rtb_Divide_l = fmodf(floorf(1000.0F * dspd_d_odoWrite_km), 4.2949673E+9F);

    /* CCaller: '<S207>/C Caller4' incorporates:
     *  DataTypeConversion: '<S207>/Data Type Conversion'
     */
    mBSW_NvmWrite_Odometer_u32(rtb_Divide_l < 0.0F ? (uint32)-(sint32)(uint32)-
      rtb_Divide_l : (uint32)rtb_Divide_l);
  }

  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem1' */

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S8>/Constant17'
   */
  if (dspc_b_odoClearCntOvrdFlg) {
    /* Switch: '<S8>/Switch2' incorporates:
     *  Constant: '<S8>/Constant'
     */
    dspd_st_odoClrCntWrite = (uint8)dspc_st_odoClearCntOvrdVal;
  } else {
    /* Switch: '<S8>/Switch2' */
    dspd_st_odoClrCntWrite = swc_HMIF_ARID_DEF.ClearCnt;
  }

  /* End of Switch: '<S8>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem2' incorporates:
   *  EnablePort: '<S208>/Enable'
   */
  /* RelationalOperator: '<S203>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S203>/Delay Input1'
   *
   * Block description for '<S203>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((sint32)swc_HMIF_ARID_DEF.DataTypeConversion14 < (sint32)
      swc_HMIF_ARID_DEF.DelayInput1_DSTATE_i) {
    /* CCaller: '<S208>/C Caller2' */
    mBSW_NvmWrite_OdoClrCnt(dspd_st_odoClrCntWrite);
  }

  /* End of RelationalOperator: '<S203>/FixPt Relational Operator' */
  /* End of Outputs for SubSystem: '<S8>/Enabled Subsystem2' */

  /* Switch: '<S8>/Switch7' incorporates:
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S8>/Constant20'
   *  Logic: '<S8>/Logical Operator4'
   *  RelationalOperator: '<S200>/Compare'
   *  RelationalOperator: '<S201>/Compare'
   *  RelationalOperator: '<S8>/Relational Operator'
   *  Switch: '<S8>/Switch8'
   */
  if ((rtb_DataTypeConversion1 <= 500.0F) && (swc_HMIF_ARID_DEF.ClearCnt <=
       ((uint8)3U))) {
    /* Switch: '<S8>/Switch7' incorporates:
     *  Constant: '<S8>/Constant21'
     */
    dspd_b_RoutineResultSet = ((uint8)0U);
  } else if (swc_HMIF_ARID_DEF.ClearCnt <= ((uint8)3U)) {
    /* Switch: '<S8>/Switch8' incorporates:
     *  Constant: '<S8>/Constant24'
     *  Switch: '<S8>/Switch7'
     */
    dspd_b_RoutineResultSet = ((uint8)1U);
  } else {
    /* Switch: '<S8>/Switch7' incorporates:
     *  Constant: '<S8>/Constant25'
     *  Switch: '<S8>/Switch8'
     */
    dspd_b_RoutineResultSet = ((uint8)2U);
  }

  /* End of Switch: '<S8>/Switch7' */

  /* Outputs for Enabled SubSystem: '<S8>/Subsystem1' incorporates:
   *  EnablePort: '<S213>/Enable'
   */
  if (rtb_y_o) {
    /* CCaller: '<S213>/C Caller7' */
    mBSW_SetRoutineResult_03E4(dspd_b_RoutineResultSet);
  }

  /* End of Outputs for SubSystem: '<S8>/Subsystem1' */

  /* Relay: '<S9>/Relay1' */
  swc_HMIF_ARID_DEF.Relay1_Mode = ((swc_HMIF_ARID_DEF.DataTypeConversion15 >=
    dspc_v_vehSpdHiFC_kph) || ((swc_HMIF_ARID_DEF.DataTypeConversion15 >
    dspc_v_vehSpdLoFC_kph) && swc_HMIF_ARID_DEF.Relay1_Mode));
  if (swc_HMIF_ARID_DEF.Relay1_Mode) {
    /* DataTypeConversion: '<S12>/Data Type Conversion1' */
    rtb_Switch_h = ((uint8)1U);
  } else {
    /* DataTypeConversion: '<S12>/Data Type Conversion1' */
    rtb_Switch_h = ((uint8)0U);
  }

  /* End of Relay: '<S9>/Relay1' */

  /* Switch: '<S9>/Switch1' */
  if (rtb_Switch_h != 0) {
    /* Switch: '<S9>/Switch1' */
    rtb_Switch1 = swc_HMIF_ARID_DEF.DataTypeConversion15;
  } else {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S9>/Constant4'
     */
    rtb_Switch1 = dspc_v_defaultVehSpdforFC_kph;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Product: '<S9>/Divide' incorporates:
   *  Constant: '<S9>/Constant1'
   *  Gain: '<S9>/Gain1'
   *  MinMax: '<S9>/MinMax1'
   */
  dspd_V_engFuelConsAvg_lp100km = 360.0F * dspd_dV_engFuelConsInst_mlps / fmaxf
    (rtb_Switch1, 0.1F);

  /* Lookup_n-D: '<S10>/1-D Lookup Table' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   */
  swc_HMIF_ARID_DEF.dspd_q_hvbSOC_pct = look1_iflf_binlcapw
    (swc_HMIF_ARID_DEF.DataTypeConversion10, (const float32 *)
     &dspv_SOCDisplayMap_X_SOC_pct[0], (const float32 *)
     &dspv_SOCDisplayMap_Y_pct[0], 7U);

  /* Outputs for Atomic SubSystem: '<S11>/icu_driver_req_lamps' */
  /* RelationalOperator: '<S224>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  RelationalOperator: '<S13>/Relational Operator'
   *  Switch: '<S13>/Switch4'
   *  Switch: '<S13>/Switch5'
   *  Switch: '<S13>/Switch9'
   */
  rtb_OR_a_tmp = swc_HMIF_ARID_DEF.DataTypeConversion2;

  /* RelationalOperator: '<S224>/Relational Operator' incorporates:
   *  Constant: '<S226>/Constant'
   */
  rtb_OR_f = (rtb_OR_a_tmp == HEVModeReq_EV);

  /* End of Outputs for SubSystem: '<S11>/icu_driver_req_lamps' */

  /* Switch: '<S13>/Switch9' incorporates:
   *  Constant: '<S13>/Constant17'
   *  Constant: '<S227>/Constant'
   *  RelationalOperator: '<S227>/Compare'
   *  Switch: '<S13>/Switch4'
   */
  if (((uint8)VEH_SWT_INF) == ((uint8)4U)) {
    HybModeMngr tmp_0;

    /* RelationalOperator: '<S229>/Relational Operator15' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion27'
     *  RelationalOperator: '<S229>/Relational Operator12'
     *  RelationalOperator: '<S229>/Relational Operator13'
     *  RelationalOperator: '<S229>/Relational Operator2'
     *  RelationalOperator: '<S229>/Relational Operator4'
     *  RelationalOperator: '<S229>/Relational Operator8'
     *  RelationalOperator: '<S229>/Relational Operator9'
     *  Switch: '<S229>/Switch10'
     *  Switch: '<S229>/Switch11'
     */
    tmp_0 = swc_HMIF_ARID_DEF.DataTypeConversion27;

    /* Switch: '<S229>/Switch10' incorporates:
     *  Constant: '<S231>/Constant'
     *  Constant: '<S232>/Constant'
     *  Constant: '<S233>/Constant'
     *  Constant: '<S234>/Constant'
     *  Constant: '<S235>/Constant'
     *  Constant: '<S236>/Constant'
     *  Constant: '<S237>/Constant'
     *  Logic: '<S229>/Logical Operator1'
     *  Logic: '<S229>/Logical Operator2'
     *  Logic: '<S229>/Logical Operator3'
     *  RelationalOperator: '<S229>/Relational Operator12'
     *  RelationalOperator: '<S229>/Relational Operator13'
     *  RelationalOperator: '<S229>/Relational Operator15'
     *  RelationalOperator: '<S229>/Relational Operator2'
     *  RelationalOperator: '<S229>/Relational Operator4'
     *  RelationalOperator: '<S229>/Relational Operator8'
     *  RelationalOperator: '<S229>/Relational Operator9'
     *  Switch: '<S229>/Switch11'
     *  Switch: '<S229>/Switch12'
     */
    if ((tmp_0 == HybModeMngr_EV_MODE) || (tmp_0 == HybModeMngr_PHEV2EV)) {
      /* Switch: '<S13>/Switch9' incorporates:
       *  Constant: '<S229>/Constant18'
       *  Switch: '<S229>/Switch10'
       */
      dspd_st_vehDrvMode = ((uint8)1U);
    } else if ((tmp_0 == HybModeMngr_PHEV_MODE) || (tmp_0 ==
                HybModeMngr_ICE2PHEV) || (tmp_0 == HybModeMngr_EV2PHEV)) {
      /* Switch: '<S229>/Switch11' incorporates:
       *  Constant: '<S229>/Constant19'
       *  Switch: '<S13>/Switch9'
       */
      dspd_st_vehDrvMode = ((uint8)2U);
    } else if ((tmp_0 == HybModeMngr_ICE_MODE) || (tmp_0 == HybModeMngr_PHEV2ICE))
    {
      /* Switch: '<S229>/Switch12' incorporates:
       *  Constant: '<S229>/Constant20'
       *  Switch: '<S13>/Switch9'
       *  Switch: '<S229>/Switch11'
       */
      dspd_st_vehDrvMode = ((uint8)3U);
    } else {
      /* Switch: '<S13>/Switch9' incorporates:
       *  Constant: '<S229>/Constant22'
       *  Switch: '<S229>/Switch11'
       *  Switch: '<S229>/Switch12'
       */
      dspd_st_vehDrvMode = ((uint8)0U);
    }
  } else if (swc_HMIF_ARID_DEF.DataTypeConversion58 != 0.0) {
    /* Switch: '<S13>/Switch5' incorporates:
     *  Constant: '<S13>/Constant9'
     *  Constant: '<S226>/Constant'
     *  RelationalOperator: '<S13>/Relational Operator'
     *  RelationalOperator: '<S224>/Relational Operator'
     *  Switch: '<S13>/Switch2'
     *  Switch: '<S13>/Switch4'
     */
    if (true) {
      /* Switch: '<S230>/Switch8' incorporates:
       *  Constant: '<S230>/Constant14'
       *  Constant: '<S230>/Constant15'
       *  Constant: '<S230>/Constant21'
       *  Logic: '<S230>/Logical Operator5'
       *  RelationalOperator: '<S230>/Relational Operator1'
       *  RelationalOperator: '<S230>/Relational Operator2'
       *  RelationalOperator: '<S230>/Relational Operator3'
       */
      if ((swc_HMIF_ARID_DEF.DataTypeConversion34 == ((uint8)1U)) ||
          (swc_HMIF_ARID_DEF.DataTypeConversion34 == ((uint8)2U)) ||
          (swc_HMIF_ARID_DEF.DataTypeConversion34 == ((uint8)3U))) {
        /* Switch: '<S13>/Switch9' incorporates:
         *  Constant: '<S230>/Constant16'
         *  Switch: '<S13>/Switch5'
         */
        dspd_st_vehDrvMode = DISPLAY_DRIVEMODE_HEV;
      } else {
        /* Switch: '<S13>/Switch9' incorporates:
         *  Constant: '<S230>/Constant10'
         *  Switch: '<S13>/Switch5'
         */
        dspd_st_vehDrvMode = DISPLAY_DRIVEMODE_EV;
      }

      /* End of Switch: '<S230>/Switch8' */

      /* Outputs for Atomic SubSystem: '<S11>/icu_driver_req_lamps' */
    } else if (rtb_OR_a_tmp == HEVModeReq_EV) {
      /* Switch: '<S13>/Switch3' incorporates:
       *  Constant: '<S13>/Constant3'
       *  Logic: '<S13>/Logical Operator'
       *  Logic: '<S13>/Logical Operator1'
       *  Switch: '<S13>/Switch2'
       */
      if (((swc_HMIF_ARID_DEF.DataTypeConversion25 != 0.0) ||
           (swc_HMIF_ARID_DEF.DataTypeConversion26 != 0.0)) &&
          dspc_b_phevOvrEvBtn) {
        /* Switch: '<S13>/Switch9' incorporates:
         *  Constant: '<S13>/Constant4'
         *  Switch: '<S13>/Switch2'
         *  Switch: '<S13>/Switch5'
         */
        dspd_st_vehDrvMode = DISPLAY_DRIVEMODE_HEV;
      } else {
        /* Switch: '<S13>/Switch9' incorporates:
         *  Constant: '<S13>/Constant5'
         *  Switch: '<S13>/Switch2'
         *  Switch: '<S13>/Switch5'
         */
        dspd_st_vehDrvMode = DISPLAY_DRIVEMODE_EV;
      }

      /* End of Switch: '<S13>/Switch3' */
    } else {
      /* Switch: '<S13>/Switch9' incorporates:
       *  Constant: '<S13>/Constant1'
       *  Switch: '<S13>/Switch2'
       *  Switch: '<S13>/Switch5'
       */
      dspd_st_vehDrvMode = DISPLAY_DRIVEMODE_HEV;

      /* End of Outputs for SubSystem: '<S11>/icu_driver_req_lamps' */
    }
  } else {
    /* Switch: '<S13>/Switch9' incorporates:
     *  Constant: '<S13>/Constant8'
     *  Switch: '<S13>/Switch4'
     */
    dspd_st_vehDrvMode = DISPLAY_DRIVEMODE_OFF;
  }

  /* Outputs for Atomic SubSystem: '<S11>/icu_drive_mode_lamps' */
  /* RelationalOperator: '<S225>/Compare' incorporates:
   *  Constant: '<S223>/Constant'
   *  Constant: '<S225>/Constant'
   *  S-Function (sfix_bitop): '<S223>/Bitwise Operator'
   */
  rtb_y_l = ((dspd_st_vehDrvMode & DISPLAY_DRIVEMODE_HEV) != ((uint8)0U));

  /* End of Outputs for SubSystem: '<S11>/icu_drive_mode_lamps' */

  /* MultiPortSwitch generated from: '<S11>/Multiport Switch' incorporates:
   *  Constant: '<S220>/Constant'
   */
  switch (dspc_e_lampMode) {
   case DisplayLampMode_ButtonState:
    /* Outputs for Atomic SubSystem: '<S11>/icu_button_state_lamps' */
    /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
     *  Constant: '<S1>/Constant1'
     *  SignalConversion: '<S222>/Signal Conversion'
     */
    rtb_RelationalOperator3_n = false;

    /* End of Outputs for SubSystem: '<S11>/icu_button_state_lamps' */
    break;

   case DisplayLampMode_ActiveMode:
    /* Outputs for Atomic SubSystem: '<S11>/icu_active_mode_lamps' */
    /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
     *  Logic: '<S221>/Logical Operator'
     */
    rtb_RelationalOperator3_n = (swc_HMIF_ARID_DEF.DataTypeConversion24 == 0.0);

    /* End of Outputs for SubSystem: '<S11>/icu_active_mode_lamps' */
    break;

   case DisplayLampMode_DriverRequest:
    /* Outputs for Atomic SubSystem: '<S11>/icu_driver_req_lamps' */
    /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
     *  Logic: '<S224>/Logical Operator2'
     */
    rtb_RelationalOperator3_n = !rtb_OR_f;

    /* End of Outputs for SubSystem: '<S11>/icu_driver_req_lamps' */
    break;

   default:
    /* RelationalOperator: '<S247>/Relational Operator3' */
    rtb_RelationalOperator3_n = rtb_y_l;
    break;
  }

  /* Logic: '<S11>/Logical Operator1' */
  dspd_b_hevLampOn = (rtb_RelationalOperator3_n &&
                      swc_HMIF_ARID_DEF.DataTypeConversion14);

  /* MultiPortSwitch generated from: '<S11>/Multiport Switch' incorporates:
   *  Constant: '<S220>/Constant'
   */
  switch (dspc_e_lampMode) {
   case DisplayLampMode_ButtonState:
    /* Outputs for Atomic SubSystem: '<S11>/icu_button_state_lamps' */
    /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
     *  Constant: '<S1>/Constant2'
     *  SignalConversion: '<S222>/Signal Conversion1'
     */
    rtb_RelationalOperator3_n = false;

    /* End of Outputs for SubSystem: '<S11>/icu_button_state_lamps' */
    break;

   case DisplayLampMode_ActiveMode:
    /* Outputs for Atomic SubSystem: '<S11>/icu_active_mode_lamps' */
    /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
     *  Logic: '<S221>/Logical Operator1'
     */
    rtb_RelationalOperator3_n = (swc_HMIF_ARID_DEF.DataTypeConversion24 != 0.0);

    /* End of Outputs for SubSystem: '<S11>/icu_active_mode_lamps' */
    break;

   case DisplayLampMode_DriverRequest:
    /* RelationalOperator: '<S247>/Relational Operator3' */
    rtb_RelationalOperator3_n = rtb_OR_f;
    break;

   default:
    /* Outputs for Atomic SubSystem: '<S11>/icu_drive_mode_lamps' */
    /* RelationalOperator: '<S247>/Relational Operator3' incorporates:
     *  Logic: '<S223>/Logical Operator2'
     */
    rtb_RelationalOperator3_n = !rtb_y_l;

    /* End of Outputs for SubSystem: '<S11>/icu_drive_mode_lamps' */
    break;
  }

  /* Logic: '<S11>/Logical Operator2' */
  dspd_b_evLampOn = (rtb_RelationalOperator3_n &&
                     swc_HMIF_ARID_DEF.DataTypeConversion14);

  /* DataTypeConversion: '<S12>/Data Type Conversion1' incorporates:
   *  Logic: '<S12>/Logical Operator6'
   */
  rtb_Switch_h = (uint8)(swc_HMIF_ARID_DEF.DataTypeConversion110 ||
    swc_HMIF_ARID_DEF.DataTypeConversion112 ||
    swc_HMIF_ARID_DEF.DataTypeConversion113);

  /* DataTypeConversion: '<S12>/Data Type Conversion2' incorporates:
   *  Logic: '<S12>/Logical Operator5'
   */
  rtb_DataTypeConversion2_l = (uint8)(swc_HMIF_ARID_DEF.DataTypeConversion94 ||
    swc_HMIF_ARID_DEF.DataTypeConversion111 ||
    swc_HMIF_ARID_DEF.DataTypeConversion115);

  /* Gain: '<S12>/Gain1' */
  i = (uint16)((uint32)((uint8)128U) * rtb_DataTypeConversion2_l);

  /* Gain: '<S12>/Gain2' */
  rtb_dspd_num_errorCode = (uint16)((uint32)((uint8)192U) * rtb_Switch_h);

  /* MinMax: '<S12>/maxerrlevel1' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion3'
   *  Gain: '<S12>/Gain1'
   *  Gain: '<S12>/Gain2'
   *  Gain: '<S12>/Gain3'
   */
  rtb_Product = (uint32)((uint8)128U) * swc_HMIF_ARID_DEF.DataTypeConversion95;
  maxV = (uint32)i << 1;
  if (rtb_Product >= maxV) {
    maxV = rtb_Product;
  }

  rtb_Product = (uint32)rtb_dspd_num_errorCode << 1;
  if (maxV >= rtb_Product) {
    /* MinMax: '<S12>/maxerrlevel1' */
    dspd_st_vehFailLvl = (uint8)(maxV >> 7);
  } else {
    /* MinMax: '<S12>/maxerrlevel1' */
    dspd_st_vehFailLvl = (uint8)(rtb_Product >> 7);
  }

  /* End of MinMax: '<S12>/maxerrlevel1' */

  /* MinMax: '<S12>/maxerrlevel2' incorporates:
   *  Gain: '<S12>/Gain4'
   *  Gain: '<S12>/Gain5'
   *  Gain: '<S12>/Gain8'
   *  Logic: '<S12>/Logical Operator7'
   *  Logic: '<S12>/Logical Operator8'
   *  Logic: '<S12>/Logical Operator9'
   */
  rtb_Product = (uint32)(swc_HMIF_ARID_DEF.DataTypeConversion94 ||
    swc_HMIF_ARID_DEF.DataTypeConversion110) * ((uint8)128U);
  maxV = ((uint32)(swc_HMIF_ARID_DEF.DataTypeConversion111 ||
                   swc_HMIF_ARID_DEF.DataTypeConversion112) * ((uint8)128U)) <<
    1;
  if (rtb_Product >= maxV) {
    maxV = rtb_Product;
  }

  rtb_Product = ((uint32)(swc_HMIF_ARID_DEF.DataTypeConversion115 ||
    swc_HMIF_ARID_DEF.DataTypeConversion113) * ((uint8)192U)) << 1;
  if (maxV >= rtb_Product) {
    /* MinMax: '<S12>/maxerrlevel2' */
    dspd_st_vehSubFailLvl = (uint8)(maxV >> 7);
  } else {
    /* MinMax: '<S12>/maxerrlevel2' */
    dspd_st_vehSubFailLvl = (uint8)(rtb_Product >> 7);
  }

  /* End of MinMax: '<S12>/maxerrlevel2' */

  /* Switch: '<S13>/Switch7' */
  if (swc_HMIF_ARID_DEF.DataTypeConversion14) {
    /* Switch: '<S13>/Switch1' incorporates:
     *  Constant: '<S13>/Constant7'
     *  Logic: '<S13>/Logical Operator2'
     *  Switch: '<S13>/Switch'
     *  Switch: '<S13>/Switch6'
     */
    if (swc_HMIF_ARID_DEF.DataTypeConversion3 != 0.0) {
      /* Switch: '<S13>/Switch7' incorporates:
       *  Constant: '<S13>/Constant6'
       *  Switch: '<S13>/Switch1'
       */
      dspd_st_drvModInd = DISPLAY_DRIVEMODE_4WD;
    } else if (swc_HMIF_ARID_DEF.DataTypeConversion4 && dspc_b_sportModDspEnb) {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant2'
       *  Switch: '<S13>/Switch7'
       */
      dspd_st_drvModInd = DISPLAY_DRIVEMODE_SPORT;
    } else if (swc_HMIF_ARID_DEF.DataTypeConversion91 != 0.0) {
      /* Switch: '<S13>/Switch6' incorporates:
       *  Constant: '<S13>/Constant11'
       *  Switch: '<S13>/Switch'
       *  Switch: '<S13>/Switch7'
       */
      dspd_st_drvModInd = DISPLAY_DRIVEMODE_ECO;
    } else {
      /* Switch: '<S13>/Switch7' incorporates:
       *  Constant: '<S13>/Constant12'
       *  Switch: '<S13>/Switch'
       *  Switch: '<S13>/Switch6'
       */
      dspd_st_drvModInd = DISPLAY_DRIVEMODE_Normal;
    }

    /* End of Switch: '<S13>/Switch1' */
  } else {
    /* Switch: '<S13>/Switch7' incorporates:
     *  Constant: '<S13>/Constant13'
     */
    dspd_st_drvModInd = DISPLAY_DRIVEMODE_Dft;
  }

  /* End of Switch: '<S13>/Switch7' */

  /* Product: '<S241>/Product1' incorporates:
   *  Constant: '<S241>/Constant'
   *  Product: '<S241>/Product'
   */
  rtb_Gain1 = swc_HMIF_ARID_DEF.DataTypeConversion6 * ((float32)NmRPM_2_KW) *
    swc_HMIF_ARID_DEF.DataTypeConversion28;

  /* Switch: '<S245>/Switch4' incorporates:
   *  Constant: '<S14>/Constant2'
   *  RelationalOperator: '<S245>/Relational Operator4'
   *  RelationalOperator: '<S245>/Relational Operator5'
   *  Switch: '<S245>/Switch5'
   *  UnaryMinus: '<S245>/Unary Minus'
   */
  if (rtb_Gain1 >= dspc_pwr_eadActiveThold_kW) {
    /* Switch: '<S245>/Switch4' incorporates:
     *  Constant: '<S259>/Constant'
     */
    rtb_tol_type = ValueTol_ABOVE_TOL;
  } else if (rtb_Gain1 <= -dspc_pwr_eadActiveThold_kW) {
    /* Switch: '<S245>/Switch5' incorporates:
     *  Constant: '<S260>/Constant'
     *  Switch: '<S245>/Switch4'
     */
    rtb_tol_type = ValueTol_BELOW_TOL;
  } else {
    /* Switch: '<S245>/Switch4' incorporates:
     *  Constant: '<S261>/Constant'
     *  Switch: '<S245>/Switch5'
     */
    rtb_tol_type = ValueTol_WITHIN_TOL;
  }

  /* End of Switch: '<S245>/Switch4' */

  /* Switch: '<S248>/Switch4' incorporates:
   *  Constant: '<S14>/Constant1'
   *  RelationalOperator: '<S248>/Relational Operator4'
   *  RelationalOperator: '<S248>/Relational Operator5'
   *  Switch: '<S248>/Switch5'
   *  UnaryMinus: '<S248>/Unary Minus'
   */
  if (swc_HMIF_ARID_DEF.DataTypeConversion29 >= dspc_tq_motorActiveThold) {
    /* Switch: '<S248>/Switch4' incorporates:
     *  Constant: '<S269>/Constant'
     */
    rtb_tol_type_k = ValueTol_ABOVE_TOL;
  } else if (swc_HMIF_ARID_DEF.DataTypeConversion29 <= -dspc_tq_motorActiveThold)
  {
    /* Switch: '<S248>/Switch5' incorporates:
     *  Constant: '<S270>/Constant'
     *  Switch: '<S248>/Switch4'
     */
    rtb_tol_type_k = ValueTol_BELOW_TOL;
  } else {
    /* Switch: '<S248>/Switch4' incorporates:
     *  Constant: '<S271>/Constant'
     *  Switch: '<S248>/Switch5'
     */
    rtb_tol_type_k = ValueTol_WITHIN_TOL;
  }

  /* End of Switch: '<S248>/Switch4' */

  /* Switch: '<S247>/Switch1' incorporates:
   *  Constant: '<S247>/Constant1'
   *  Constant: '<S264>/Constant'
   *  Constant: '<S267>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Logic: '<S247>/Logical Operator3'
   *  Logic: '<S247>/Logical Operator4'
   *  Logic: '<S247>/Logical Operator7'
   *  RelationalOperator: '<S247>/Relational Operator1'
   *  RelationalOperator: '<S247>/Relational Operator5'
   *  RelationalOperator: '<S247>/Relational Operator6'
   *  Switch: '<S245>/Switch4'
   *  Switch: '<S248>/Switch4'
   */
  if (dspc_b_enaDisplayEVinGear) {
    rtb_OR_f = ((swc_HMIF_ARID_DEF.DataTypeConversion1 == DriveDir_NO_DRIVE) ||
                (swc_HMIF_ARID_DEF.DataTypeConversion24 == 0.0));
  } else {
    rtb_OR_f = ((rtb_tol_type == ValueTol_WITHIN_TOL) && (rtb_tol_type_k ==
      ValueTol_WITHIN_TOL));
  }

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S14>/Constant3'
   *  Constant: '<S263>/Constant'
   *  Constant: '<S265>/Constant'
   *  Constant: '<S266>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   *  Logic: '<S246>/Logical Operator4'
   *  Logic: '<S247>/Logical Operator'
   *  Logic: '<S247>/Logical Operator2'
   *  RelationalOperator: '<S14>/Relational Operator8'
   *  RelationalOperator: '<S246>/Relational Operator13'
   *  RelationalOperator: '<S246>/Relational Operator14'
   *  RelationalOperator: '<S247>/Relational Operator'
   *  RelationalOperator: '<S247>/Relational Operator3'
   *  Switch: '<S14>/Switch1'
   *  Switch: '<S14>/Switch10'
   *  Switch: '<S14>/Switch5'
   *  Switch: '<S14>/Switch9'
   *  Switch: '<S247>/Switch1'
   *  Switch: '<S248>/Switch4'
   */
  if (((EngineState_RUNNING != EngineState_OFF) && rtb_OR_f) ||
      (swc_HMIF_ARID_DEF.DataTypeConversion9 == HVBRelayStatus_OPEN)) {
    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S240>/Constant'
     */
    dspd_e_vehPwrFlow = PowerFlowMode_OFF;
  } else if (swc_HMIF_ARID_DEF.DataTypeConversion26 != 0.0) {
    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S239>/Constant'
     *  Switch: '<S14>/Switch'
     */
    dspd_e_vehPwrFlow = PowerFlowMode_SERIES;
  } else if (swc_HMIF_ARID_DEF.DataTypeConversion24 != 0.0) {
    /* Switch: '<S242>/Switch6' incorporates:
     *  Constant: '<S251>/Constant'
     *  RelationalOperator: '<S242>/Relational Operator7'
     *  Switch: '<S14>/Switch1'
     *  Switch: '<S14>/Switch5'
     *  Switch: '<S245>/Switch4'
     */
    if (rtb_tol_type == ValueTol_BELOW_TOL) {
      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S250>/Constant'
       *  Switch: '<S14>/Switch5'
       */
      dspd_e_vehPwrFlow = PowerFlowMode_REGEN;
    } else {
      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S249>/Constant'
       *  Switch: '<S14>/Switch5'
       */
      dspd_e_vehPwrFlow = PowerFlowMode_EV;
    }

    /* End of Switch: '<S242>/Switch6' */
  } else if (swc_HMIF_ARID_DEF.DataTypeConversion8 == 0) {
    /* Switch: '<S244>/Switch1' incorporates:
     *  Constant: '<S258>/Constant'
     *  Logic: '<S244>/Logical Operator4'
     *  RelationalOperator: '<S244>/Relational Operator11'
     *  RelationalOperator: '<S244>/Relational Operator12'
     *  Switch: '<S14>/Switch1'
     *  Switch: '<S14>/Switch5'
     *  Switch: '<S14>/Switch9'
     *  Switch: '<S248>/Switch4'
     */
    if ((EngineState_RUNNING == EngineState_OFF) && (rtb_tol_type_k ==
         ValueTol_BELOW_TOL)) {
      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S255>/Constant'
       *  Switch: '<S14>/Switch5'
       *  Switch: '<S14>/Switch9'
       */
      dspd_e_vehPwrFlow = PowerFlowMode_PARK_GEN;
    } else {
      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S256>/Constant'
       *  Switch: '<S14>/Switch5'
       *  Switch: '<S14>/Switch9'
       */
      dspd_e_vehPwrFlow = PowerFlowMode_OFF;
    }

    /* End of Switch: '<S244>/Switch1' */
  } else if ((EngineState_RUNNING == EngineState_OFF) && (rtb_tol_type_k ==
              ValueTol_BELOW_TOL)) {
    /* Switch: '<S243>/Switch11' incorporates:
     *  Constant: '<S254>/Constant'
     *  RelationalOperator: '<S243>/Relational Operator12'
     *  Switch: '<S14>/Switch1'
     *  Switch: '<S14>/Switch10'
     *  Switch: '<S14>/Switch5'
     *  Switch: '<S14>/Switch9'
     *  Switch: '<S245>/Switch4'
     */
    if (rtb_tol_type == ValueTol_ABOVE_TOL) {
      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S252>/Constant'
       *  Switch: '<S14>/Switch10'
       */
      dspd_e_vehPwrFlow = PowerFlowMode_DRIVE_GEN;
    } else {
      /* Switch: '<S14>/Switch' incorporates:
       *  Constant: '<S253>/Constant'
       *  Switch: '<S14>/Switch10'
       */
      dspd_e_vehPwrFlow = PowerFlowMode_ICE_MSG;
    }

    /* End of Switch: '<S243>/Switch11' */
  } else {
    /* Switch: '<S14>/Switch' incorporates:
     *  Constant: '<S238>/Constant'
     *  Switch: '<S14>/Switch1'
     *  Switch: '<S14>/Switch10'
     *  Switch: '<S14>/Switch5'
     *  Switch: '<S14>/Switch9'
     */
    dspd_e_vehPwrFlow = PowerFlowMode_PHEV;
  }

  /* End of Switch: '<S14>/Switch' */

  /* SignalConversion generated from: '<S2>/dspd_d_vehCrsDst_km' */
  swc_HMIF_ARID_DEF.OutportBufferFordspd_d_vehCrsDs = 0.0;

  /* SignalConversion generated from: '<S2>/dspd_st_vehOverLoadSts' */
  swc_HMIF_ARID_DEF.OutportBufferFordspd_st_vehOver = 0.0;

  /* SignalConversion generated from: '<S2>/dspd_m_vehWeight_kg' */
  swc_HMIF_ARID_DEF.OutportBufferFordspd_m_vehWeigh = 0.0;

  /* SignalConversion generated from: '<S2>/dspd_st_vehCalNum' */
  swc_HMIF_ARID_DEF.OutportBufferFordspd_st_vehCalN = 0.0;

  /* SignalConversion generated from: '<S2>/dspd_b_vehOvrLoadEnbl' */
  swc_HMIF_ARID_DEF.OutportBufferFordspd_b_vehOvrLo = 0.0;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE = dspd_pwr_hvPwrCsmpt_kW;

  /* Update for UnitDelay: '<S26>/init' incorporates:
   *  Constant: '<S26>/Constant1'
   */
  swc_HMIF_ARID_DEF.init_DSTATE = false;

  /* Update for UnitDelay: '<S27>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_h = swc_HMIF_ARID_DEF.RelationalOperator_g;

  /* Update for UnitDelay: '<S27>/Unit Delay1' */
  swc_HMIF_ARID_DEF.UnitDelay1_DSTATE_m = rtb_RelationalOperator1;

  /* Update for UnitDelay: '<S27>/Unit Delay6' */
  swc_HMIF_ARID_DEF.UnitDelay6_DSTATE = rtb_RelationalOperator1;

  /* Update for UnitDelay: '<S27>/Unit Delay3' */
  swc_HMIF_ARID_DEF.UnitDelay3_DSTATE = swc_HMIF_ARID_DEF.Switch;

  /* Update for UnitDelay: '<S27>/Unit Delay5' incorporates:
   *  Constant: '<S27>/Constant'
   */
  swc_HMIF_ARID_DEF.UnitDelay5_DSTATE_j = false;

  /* Update for UnitDelay: '<S27>/Unit Delay4' incorporates:
   *  Logic: '<S27>/Logical Operator3'
   */
  swc_HMIF_ARID_DEF.UnitDelay4_DSTATE = !rtb_LogicalOperator7_i;

  /* Update for UnitDelay: '<S34>/Unit Delay2' */
  swc_HMIF_ARID_DEF.UnitDelay2_DSTATE = rtb_uDLookupTable1;

  /* Update for UnitDelay: '<S31>/Delay Input1'
   *
   * Block description for '<S31>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HMIF_ARID_DEF.DelayInput1_DSTATE = swc_HMIF_ARID_DEF.DataTypeConversion14;

  /* Update for Delay: '<S47>/Delay1' incorporates:
   *  Constant: '<S47>/Constant1'
   */
  swc_HMIF_ARID_DEF.Delay1_DSTATE_g = false;

  /* Update for Delay: '<S47>/Delay2' */
  swc_HMIF_ARID_DEF.Delay2_DSTATE = dspd_d_stdRng2NVM;

  /* Update for Delay: '<S47>/Delay3' incorporates:
   *  Constant: '<S47>/Constant9'
   */
  swc_HMIF_ARID_DEF.Delay3_DSTATE[0] = swc_HMIF_ARID_DEF.Delay3_DSTATE[1];
  swc_HMIF_ARID_DEF.Delay3_DSTATE[1] = false;

  /* Update for Delay: '<S47>/Delay' */
  swc_HMIF_ARID_DEF.Delay_DSTATE_l = dspd_d_stdRngLatVal;

  /* Update for UnitDelay: '<S48>/Delay Input1'
   *
   * Block description for '<S48>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HMIF_ARID_DEF.DelayInput1_DSTATE_m =
    swc_HMIF_ARID_DEF.DataTypeConversion14;

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_p = rtb_flg_out_b;

  /* Update for UnitDelay: '<S58>/init' incorporates:
   *  Constant: '<S58>/Constant'
   */
  swc_HMIF_ARID_DEF.init_DSTATE_e = false;

  /* Update for UnitDelay: '<S58>/Unit Delay' incorporates:
   *  DataTypeConversion: '<S58>/Data Type Conversion'
   */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_c = rtb_Relay;

  /* Update for UnitDelay: '<S8>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_l = swc_HMIF_ARID_DEF.DataTypeConversion134;

  /* Update for UnitDelay: '<S8>/Unit Delay1' */
  swc_HMIF_ARID_DEF.UnitDelay1_DSTATE = swc_HMIF_ARID_DEF.DataTypeConversion133;

  /* Update for Delay: '<S8>/Delay' incorporates:
   *  Logic: '<S8>/NOT'
   */
  swc_HMIF_ARID_DEF.Delay_DSTATE_o = !dspd_b_odoBckpEn;

  /* Update for UnitDelay: '<S205>/Delay Input1'
   *
   * Block description for '<S205>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HMIF_ARID_DEF.DelayInput1_DSTATE_a = dspd_b_odoClearActv;

  /* Update for UnitDelay: '<S65>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_n = rtb_Compare_av;

  /* Update for UnitDelay: '<S73>/init' incorporates:
   *  Constant: '<S73>/Constant'
   */
  swc_HMIF_ARID_DEF.init_DSTATE_a = false;

  /* Update for UnitDelay: '<S73>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_a = rtb_CCaller1;

  /* Update for Delay: '<S218>/Delay' */
  swc_HMIF_ARID_DEF.Delay_DSTATE = swc_HMIF_ARID_DEF.DataTypeConversion7;

  /* Update for UnitDelay: '<S219>/init' incorporates:
   *  Constant: '<S219>/Constant1'
   */
  swc_HMIF_ARID_DEF.init_DSTATE_j = false;

  /* Update for UnitDelay: '<S219>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_ci = dspd_dV_engFuelConsInst_mlps;

  /* Update for Delay: '<S6>/Delay1' */
  swc_HMIF_ARID_DEF.Delay1_DSTATE = rtb_Add_k;

  /* Update for Delay: '<S6>/Delay2' */
  swc_HMIF_ARID_DEF.Delay2_DSTATE_d = dspd_d_vehDrvRngHEVModUnfilt_km;

  /* Update for UnitDelay: '<S193>/Unit Delay' */
  swc_HMIF_ARID_DEF.UnitDelay_DSTATE_f = dspd_d_vehDrvRngHEVMod_km;

  /* Update for UnitDelay: '<S193>/init' incorporates:
   *  Constant: '<S193>/Constant1'
   */
  swc_HMIF_ARID_DEF.init_DSTATE_o = false;

  /* Update for Delay: '<S7>/Delay' */
  swc_HMIF_ARID_DEF.Delay_DSTATE_h = rtb_CCaller2;

  /* Update for UnitDelay: '<S204>/Delay Input1'
   *
   * Block description for '<S204>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HMIF_ARID_DEF.DelayInput1_DSTATE_j =
    swc_HMIF_ARID_DEF.DataTypeConversion14;

  /* Update for UnitDelay: '<S8>/Unit Delay2' */
  swc_HMIF_ARID_DEF.UnitDelay2_DSTATE_h = rtb_y_o;

  /* Update for UnitDelay: '<S203>/Delay Input1'
   *
   * Block description for '<S203>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HMIF_ARID_DEF.DelayInput1_DSTATE_i =
    swc_HMIF_ARID_DEF.DataTypeConversion14;
}

/* ConstCode for function-call system: '<S1>/DSP_Display' */
static void swc_HMIF_DSP_Display_Const(void)
{
  /* ConstCode for Constant: '<S37>/Constant10' */
  dspd_num_AecInit_kWhp100km = 14.8F;
}

/* Model step function */
void swc_HMIF_Step(void)
{
  float64 tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion1 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_e_driveDirSel();

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Inport generated from: '<Root>/In Bus Element10'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion10 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_q_hvbSOC_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_e_drvrHEVModReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion3 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_b_veh4WDModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion4 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_b_vehSportModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion91' incorporates:
   *  Inport generated from: '<Root>/In Bus Element82'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion91 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_b_vehEcoModActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion6 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm();

  /* DataTypeConversion: '<Root>/Data Type Conversion7' incorporates:
   *  Inport generated from: '<Root>/In Bus Element7'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion7 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_engd_V_engFuelConsInst_ml();

  /* DataTypeConversion: '<Root>/Data Type Conversion8' incorporates:
   *  Inport generated from: '<Root>/In Bus Element8'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion8 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_trad_st_trsm1GearAct();

  /* DataTypeConversion: '<Root>/Data Type Conversion9' incorporates:
   *  Inport generated from: '<Root>/In Bus Element9'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion9 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_e_hvbMainRlySts();

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Inport generated from: '<Root>/In Bus Element13'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion13 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_macd_V_tankFuelLvl_l();

  /* DataTypeConversion: '<Root>/Data Type Conversion14' incorporates:
   *  Inport generated from: '<Root>/In Bus Element14'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion14 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_pmmd_b_ignOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion15' incorporates:
   *  Inport generated from: '<Root>/In Bus Element15'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion15 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
   *  Inport generated from: '<Root>/In Bus Element16'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion16 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_pwr_hvbActRaw_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion24' incorporates:
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion24 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_hmmd_b_EVModeActive();

  /* DataTypeConversion: '<Root>/Data Type Conversion25' incorporates:
   *  Inport generated from: '<Root>/In Bus Element19'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion25 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_hmmd_b_PHEVModeActive();

  /* DataTypeConversion: '<Root>/Data Type Conversion26' incorporates:
   *  Inport generated from: '<Root>/In Bus Element20'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion26 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_hmmd_b_SHEVModeActive();

  /* DataTypeConversion: '<Root>/Data Type Conversion27' incorporates:
   *  Inport generated from: '<Root>/In Bus Element78'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion27 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_hmmd_e_hmmState();

  /* DataTypeConversion: '<Root>/Data Type Conversion28' incorporates:
   *  Inport generated from: '<Root>/In Bus Element22'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion28 =
    Rte_IRead_swc_HMIF_Step_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion29' incorporates:
   *  Inport generated from: '<Root>/In Bus Element23'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion29 =
    Rte_IRead_swc_HMIF_Step_vcsb_TCOO_msgd_tq_targetTqReq_Nm();

  /* DataTypeConversion: '<Root>/Data Type Conversion55' incorporates:
   *  Inport generated from: '<Root>/In Bus Element34'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion55 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_engd_dV_engFuelCns_lph();

  /* DataTypeConversion: '<Root>/Data Type Conversion58' incorporates:
   *  Inport generated from: '<Root>/In Bus Element21'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion58 =
    Rte_IRead_swc_HMIF_Step_vcsb_VOMM_vsmd_b_VehRun();

  /* DataTypeConversion: '<Root>/Data Type Conversion59' incorporates:
   *  Inport generated from: '<Root>/In Bus Element35'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion59 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_pmmd_b_driverStartReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion60' incorporates:
   *  Inport generated from: '<Root>/In Bus Element36'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion60 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_brpd_e_brkPedalStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion61' incorporates:
   *  Inport generated from: '<Root>/In Bus Element37'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion61 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_drid_e_gearLvrPosRaw();

  /* DataTypeConversion: '<Root>/Data Type Conversion62' incorporates:
   *  Inport generated from: '<Root>/In Bus Element38'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion62 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_obcd_b_obcChrgCablePlugged();

  /* DataTypeConversion: '<Root>/Data Type Conversion63' incorporates:
   *  Inport generated from: '<Root>/In Bus Element39'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion63 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_accd_st_AcWrk();

  /* DataTypeConversion: '<Root>/Data Type Conversion34' incorporates:
   *  Inport generated from: '<Root>/In Bus Element40'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion34 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_engd_st_apuActWrkSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion56' incorporates:
   *  Inport generated from: '<Root>/In Bus Element56'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion56 =
    Rte_IRead_swc_HMIF_Step_vcsb_HVSM_hvbd_e_PmmStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion43' incorporates:
   *  Inport generated from: '<Root>/In Bus Element52'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion43 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp();

  /* DataTypeConversion: '<Root>/Data Type Conversion45' incorporates:
   *  Inport generated from: '<Root>/In Bus Element59'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion45 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp();

  /* DataTypeConversion: '<Root>/Data Type Conversion85' incorporates:
   *  Inport generated from: '<Root>/In Bus Element76'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion85 =
    Rte_IRead_swc_HMIF_Step_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion86' incorporates:
   *  Inport generated from: '<Root>/In Bus Element68'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion86 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_eadd_pwr_mot2ActPwr_kW();

  /* DataTypeConversion: '<Root>/Data Type Conversion77' incorporates:
   *  Inport generated from: '<Root>/In Bus Element73'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion77 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_epbd_e_parkingSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion80' incorporates:
   *  Inport generated from: '<Root>/In Bus Element77'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion80 =
    (Rte_IRead_swc_HMIF_Step_vcsb_HVSM_hvbd_st_ptRdyInd() != 0);

  /* DataTypeConversion: '<Root>/Data Type Conversion71' incorporates:
   *  Inport generated from: '<Root>/In Bus Element67'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion71 =
    Rte_IRead_swc_HMIF_Step_vcsb_HVSM_apud_b_tmpFrcSttApu1();

  /* DataTypeConversion: '<Root>/Data Type Conversion90' incorporates:
   *  Inport generated from: '<Root>/In Bus Element80'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion90 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh();

  /* DataTypeConversion: '<Root>/Data Type Conversion94' incorporates:
   *  Inport generated from: '<Root>/In Bus Element84'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion94 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl21Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion95' incorporates:
   *  Inport generated from: '<Root>/In Bus Element85'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion95 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl1Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion110' incorporates:
   *  Inport generated from: '<Root>/In Bus Element86'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion110 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion112' incorporates:
   *  Inport generated from: '<Root>/In Bus Element87'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion112 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion113' incorporates:
   *  Inport generated from: '<Root>/In Bus Element88'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion113 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion111' incorporates:
   *  Inport generated from: '<Root>/In Bus Element89'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion111 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl22Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion115' incorporates:
   *  Inport generated from: '<Root>/In Bus Element90'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion115 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl23Flt_flg();

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Inport generated from: '<Root>/In Bus Element5'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion5 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_d_odometer_km();

  /* DataTypeConversion: '<Root>/Data Type Conversion92' incorporates:
   *  Inport generated from: '<Root>/In Bus Element83'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion92 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_b_ipkOdoBckUpEn();

  /* DataTypeConversion: '<Root>/Data Type Conversion114' incorporates:
   *  Inport generated from: '<Root>/In Bus Element91'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion114 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_ddid_b_bmsMsgErr();

  /* DataTypeConversion: '<Root>/Data Type Conversion116' incorporates:
   *  Inport generated from: '<Root>/In Bus Element92'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion116 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_macd_b_EVCANBusoffDebd();

  /* DataTypeConversion: '<Root>/Data Type Conversion135' incorporates:
   *  Inport generated from: '<Root>/In Bus Element55'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion135 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_vscd_b_vehSpdVld();

  /* DataTypeConversion: '<Root>/Data Type Conversion134' incorporates:
   *  Inport generated from: '<Root>/In Bus Element62'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion134 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_d_ipkOdometerbackup();

  /* DataTypeConversion: '<Root>/Data Type Conversion133' incorporates:
   *  Inport generated from: '<Root>/In Bus Element63'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion133 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_d_bcmOdometerbackup();

  /* DataTypeConversion: '<Root>/Data Type Conversion137' incorporates:
   *  Inport generated from: '<Root>/In Bus Element54'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion137 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_b_hvilOpen();

  /* DataTypeConversion: '<Root>/Data Type Conversion44' incorporates:
   *  Inport generated from: '<Root>/In Bus Element33'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion44 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_bmsFltLv4A();

  /* DataTypeConversion: '<Root>/Data Type Conversion132' incorporates:
   *  Inport generated from: '<Root>/In Bus Element53'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion132 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_mcuFltLv2A();

  /* DataTypeConversion: '<Root>/Data Type Conversion139' incorporates:
   *  Inport generated from: '<Root>/In Bus Element61'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion139 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_mcuFltLv3A();

  /* DataTypeConversion: '<Root>/Data Type Conversion140' incorporates:
   *  Inport generated from: '<Root>/In Bus Element64'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion140 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_mcuMsgErr();

  /* DataTypeConversion: '<Root>/Data Type Conversion141' incorporates:
   *  Inport generated from: '<Root>/In Bus Element65'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion141 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_macd_b_EVCANBusoff31Err();

  /* DataTypeConversion: '<Root>/Data Type Conversion84' incorporates:
   *  Inport generated from: '<Root>/In Bus Element66'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion84 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_st_flgFctCfgDspRemainRng();

  /* DataTypeConversion: '<Root>/Data Type Conversion11' incorporates:
   *  Inport generated from: '<Root>/In Bus Element11'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion11 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/In Bus Element12'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion12 =
    Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP();

  /* DataTypeConversion: '<Root>/Data Type Conversion18' incorporates:
   *  Inport generated from: '<Root>/In Bus Element25'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion18 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_obcd_b_obcWakeUp();

  /* DataTypeConversion: '<Root>/Data Type Conversion19' incorporates:
   *  Inport generated from: '<Root>/In Bus Element24'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion19 =
    Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw();

  /* DataTypeConversion: '<Root>/Data Type Conversion20' incorporates:
   *  Inport generated from: '<Root>/In Bus Element17'
   */
  swc_HMIF_ARID_DEF.DataTypeConversion20 =
    (Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_st_bmsDlyDataUpldEnb() != 0);

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/DSP_Display'
   */
  swc_HMIF_DSP_Display();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* DataTypeConversion: '<Root>/Data Type Conversion67' */
  tmp = fmod(floor(swc_HMIF_ARID_DEF.OutportBufferFordspd_st_vehOver), 256.0);

  /* Outport generated from: '<Root>/Out Bus Element18' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion67'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehOverLoadSts((uint8)(tmp < 0.0 ?
    (sint32)(uint8)-(sint8)(uint8)-tmp : (sint32)(uint8)tmp));

  /* Outport generated from: '<Root>/Out Bus Element17' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion66'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehCrsDst_km((float32)
    swc_HMIF_ARID_DEF.OutportBufferFordspd_d_vehCrsDs);

  /* Outport generated from: '<Root>/Out Bus Element16' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion65'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_HazardReqLmpOn(dspd_b_HazardReqLmpOn);

  /* Outport generated from: '<Root>/Out Bus Element19' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion68'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_m_vehWeight_kg((float32)
    swc_HMIF_ARID_DEF.OutportBufferFordspd_m_vehWeigh);

  /* Outport generated from: '<Root>/Out Bus Element21' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion76'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_vehOvrLoadEnbl
    (swc_HMIF_ARID_DEF.OutportBufferFordspd_b_vehOvrLo != 0.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion69' */
  tmp = fmod(floor(swc_HMIF_ARID_DEF.OutportBufferFordspd_st_vehCalN), 256.0);

  /* Outport generated from: '<Root>/Out Bus Element20' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion69'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehCalNum((uint8)(tmp < 0.0 ?
    (sint32)(uint8)-(sint8)(uint8)-tmp : (sint32)(uint8)tmp));

  /* Outport generated from: '<Root>/Out Bus Element22' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion87'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehSubFailLvl(dspd_st_vehSubFailLvl);

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion109'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehDrvMode(dspd_st_vehDrvMode);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion108'
   *  Switch: '<S14>/Switch'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_e_vehPwrFlow(dspd_e_vehPwrFlow);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion107'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehFailLvl(dspd_st_vehFailLvl);

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion105'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_evLampOn(dspd_b_evLampOn);

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion104'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_hevLampOn(dspd_b_hevLampOn);

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion103'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_q_hvbSOC_pct
    (swc_HMIF_ARID_DEF.dspd_q_hvbSOC_pct);

  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion106'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km
    (dspd_d_vehDrvRngEVMod_km);

  /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion102'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km
    (dspd_V_engFuelConsAvg_lp100km);

  /* Outport generated from: '<Root>/Out Bus Element8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion101'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km
    (dspd_d_vehDrvRngHEVMod_km);

  /* Outport generated from: '<Root>/Out Bus Element9' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion100'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_num_AecEV_kWhp100km
    (swc_HMIF_ARID_DEF.Switch);

  /* Outport generated from: '<Root>/Out Bus Element10' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion99'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_num_errorCode(dspd_num_errorCode);

  /* Outport generated from: '<Root>/Out Bus Element11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion98'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvModInd(dspd_st_drvModInd);

  /* Outport generated from: '<Root>/Out Bus Element12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion97'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvrOptRmdr(dspd_st_drvrOptRmdr);

  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion96'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW
    (dspd_pwr_hvPwrCsmpt_kW);

  /* Outport generated from: '<Root>/Out Bus Element14' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion70'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_turtleLmpOn(dspd_b_turtleLmpOn);

  /* Outport generated from: '<Root>/Out Bus Element15' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion64'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW
    (dspd_pwr_hvPwrRemain_kW);

  /* Outport generated from: '<Root>/Out Bus Element23' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion93'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km
    (dspd_d_pmsOdoBckUpMilg_km);

  /* Outport generated from: '<Root>/Out Bus Element24' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion118'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_ePTFault(dspd_b_ePTFault);

  /* Outport generated from: '<Root>/Out Bus Element25' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion119'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvPfmncRedn(dspd_st_drvPfmncRedn);

  /* Outport generated from: '<Root>/Out Bus Element26' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion124'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_brkSysFlt(dspd_b_brkSysFlt);

  /* Outport generated from: '<Root>/Out Bus Element27' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion128'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_CruisingDstSwtFb
    (swc_HMIF_ARID_DEF.Compare);

  /* Outport generated from: '<Root>/Out Bus Element28' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion130'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngStandard_km
    (dspd_d_vehDrvRngStandard_km);

  /* Outport generated from: '<Root>/Out Bus Element29' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion136'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_odoBckpEn(dspd_b_odoBckpEn);

  /* Outport generated from: '<Root>/Out Bus Element30' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion138'
   */
  Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_odoTotal_km(dspd_d_odoTotal_km);
}

/* Model initialize function */
void swc_HMIF_Init(void)
{
  swc_HMIF_ARID_DEF.Delay_Reset_ZCE = POS_ZCSIG;

  /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/DSP_Display'
   */
  swc_HMIF_DSP_Display_Init();

  /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* ConstCode for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/DSP_Display'
   */
  swc_HMIF_DSP_Display_Const();

  /* End of ConstCode for S-Function (fcgen): '<S1>/Function-Call Generator' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
