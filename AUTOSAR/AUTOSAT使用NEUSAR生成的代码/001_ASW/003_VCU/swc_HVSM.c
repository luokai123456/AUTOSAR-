/*
 * File: swc_HVSM.c
 *
 * Code generated for Simulink model 'swc_HVSM'.
 *
 * Model version                  : 6.239
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Sep 18 14:26:04 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_HVSM.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include <math.h>
#include "const_ImportedDefine.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef DCC_TASK_INTERVAL_S
#error The value of parameter "DCC_TASK_INTERVAL_S" is not defined
#endif

#ifndef EAD_TASK_INTERVAL_S
#error The value of parameter "EAD_TASK_INTERVAL_S" is not defined
#endif

#ifndef HVB_TASK_INTERVAL_S
#error The value of parameter "HVB_TASK_INTERVAL_S" is not defined
#endif

#ifndef OBC_TASK_INTERVAL_S
#error The value of parameter "OBC_TASK_INTERVAL_S" is not defined
#endif

#ifndef OFF
#error The value of parameter "OFF" is not defined
#endif

#ifndef ON
#error The value of parameter "ON" is not defined
#endif

#ifndef VEH_SWT_INF
#error The value of parameter "VEH_SWT_INF" is not defined
#endif

/* Named constants for Chart: '<S11>/timed_delay' */
#define swc_HVSM_IN_OFF                ((uint8)1U)
#define swc_HVSM_IN_OFF_WAIT           ((uint8)2U)
#define swc_HVSM_IN_ON                 ((uint8)3U)

/* Named constants for Chart: '<S311>/timed_delay' */
#define swc_HVSM_IN_OFF_i              ((uint8)1U)
#define swc_HVSM_IN_ON_WAIT            ((uint8)3U)
#define swc_HVSM_IN_ON_m               ((uint8)2U)

/* Named constants for Chart: '<S135>/timed_delay' */
#define swc_HVSM_IN_OFF_WAIT_h         ((uint8)2U)
#define swc_HVSM_IN_OFF_m              ((uint8)1U)
#define swc_HVSM_IN_ON_j               ((uint8)3U)

/* Named constants for Chart: '<S180>/timed_delay' */
#define swc_HVSM_IN_OFF_n              ((uint8)1U)
#define swc_HVSM_IN_ON_WAIT_o          ((uint8)3U)
#define swc_HVSM_IN_ON_o               ((uint8)2U)

/* Named constants for Chart: '<S6>/ChargerStatus' */
#define swc_HVSM_IN_CONFIRMED_PLUGGED  ((uint8)1U)
#define swc_HVSM_IN_CONFIRMED_UNPLUGGED ((uint8)2U)
#define swc_HVSM_IN_SUSPECT_PLUGGED    ((uint8)3U)
#define swc_HVSM_IN_SUSPECT_UNPLUGGED  ((uint8)4U)
#define swc_HVSM_IN_UNKNOWN            ((uint8)5U)

/* Named constants for Chart: '<S89>/LdtNewPlatform' */
#define swc_HVSM_IN_AFTER_RUN          ((uint8)1U)
#define swc_HVSM_IN_BDCAC_ACT          ((uint8)2U)
#define swc_HVSM_IN_BMS_RELAY_CLOSE    ((uint8)3U)
#define swc_HVSM_IN_BMS_RELAY_OPEN     ((uint8)4U)
#define swc_HVSM_IN_BMS_RELAY_OPEN_EMGY ((uint8)5U)
#define swc_HVSM_IN_BmsDelayOff        ((uint8)1U)
#define swc_HVSM_IN_BmsDelayOn         ((uint8)2U)
#define swc_HVSM_IN_CHARGEND           ((uint8)1U)
#define swc_HVSM_IN_CHARGE_WAIT        ((uint8)6U)
#define swc_HVSM_IN_CHARGING           ((uint8)2U)
#define swc_HVSM_IN_CHG_BMS_RELAY_CLOSE ((uint8)1U)
#define swc_HVSM_IN_CHG_WAIT           ((uint8)1U)
#define swc_HVSM_IN_DCDC_ACT           ((uint8)7U)
#define swc_HVSM_IN_DCDC_ACT_CHG       ((uint8)1U)
#define swc_HVSM_IN_DCDC_ACT_DRV       ((uint8)2U)
#define swc_HVSM_IN_DRIVE              ((uint8)8U)
#define swc_HVSM_IN_DRV_BMS_RELAY_CLOSE ((uint8)2U)
#define swc_HVSM_IN_HCM_WAKEUP         ((uint8)2U)
#define swc_HVSM_IN_HV_DEVICE_DEACT    ((uint8)9U)
#define swc_HVSM_IN_HV_SHUT_DN_EMGY    ((uint8)11U)
#define swc_HVSM_IN_IMMO_CHECK         ((uint8)12U)
#define swc_HVSM_IN_INIT               ((uint8)13U)
#define swc_HVSM_IN_INTELLIGENT_CHARGE ((uint8)3U)
#define swc_HVSM_IN_LOW_TEMP_PROTN_OFF ((uint8)14U)
#define swc_HVSM_IN_LOW_TEMP_PROTN_ON  ((uint8)15U)
#define swc_HVSM_IN_LV_SYS_CUT_OFF_WAIT ((uint8)17U)
#define swc_HVSM_IN_MCU_ACT            ((uint8)18U)
#define swc_HVSM_IN_MCU_DEACT          ((uint8)19U)
#define swc_HVSM_IN_MCU_DISCHARGE      ((uint8)20U)
#define swc_HVSM_IN_MCU_WAKEUP         ((uint8)3U)
#define swc_HVSM_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_HVSM_IN_OFF_d              ((uint8)21U)
#define swc_HVSM_IN_POWER_ON           ((uint8)22U)
#define swc_HVSM_IN_PowerON_WAIT       ((uint8)23U)
#define swc_HVSM_IN_SDCAC_ACT          ((uint8)24U)
#define swc_HVSM_IN_SHUT_DOWN_WAIT     ((uint8)25U)
#define swc_HVSM_IN_SHUT_UP_WAIT_EMGY  ((uint8)26U)
#define swc_HVSM_IN_SLEEP_WAIT         ((uint8)27U)
#define swc_HVSM_IN_STANDBY_DRV        ((uint8)4U)
#define swc_HVSM_IN_TIMEOUT            ((uint8)28U)
#define swc_HVSM_IN_VEHICLE_START      ((uint8)29U)
#define swc_HVSM_IN_WAKEUP             ((uint8)30U)
#define swc_HVS_IN_HV_DEVICE_DEACT_EMGY ((uint8)10U)
#define swc_H_IN_LV_SYS_CUT_OFF_REQUEST ((uint8)16U)

/* Named constants for Chart: '<S281>/timed_delay' */
#define swc_HVSM_IN_OFF_mh             ((uint8)1U)
#define swc_HVSM_IN_ON_WAIT_f          ((uint8)3U)
#define swc_HVSM_IN_ON_n               ((uint8)2U)

/* Named constants for Chart: '<S4>/TractionMotor' */
#define swc_HVSM_IN_CONTROL_ACTIVE1    ((uint8)1U)
#define swc_HVSM_IN_HV_CONTROL         ((uint8)2U)
#define swc_HVSM_IN_NO_ACTIVE_CHILD_i  ((uint8)0U)
#define swc_HVSM_IN_SPEED_CONTROL      ((uint8)1U)
#define swc_HVSM_IN_TORQUE_CONTROL     ((uint8)2U)
#define swc_HVSM_IN_VOLTAGE_CONTROL    ((uint8)3U)

/* Named constants for Chart: '<S3>/DCDC_Converter' */
#define swc_HVSM_IN_ACTIVE             ((uint8)1U)
#define swc_HVSM_IN_ACTIVE_DISCHARGE   ((uint8)1U)
#define swc_HVSM_IN_CONTROL_OFF        ((uint8)2U)
#define swc_HVSM_IN_FAILURE            ((uint8)1U)
#define swc_HVSM_IN_HV_DISCHARGE       ((uint8)3U)
#define swc_HVSM_IN_HV_OFF             ((uint8)4U)
#define swc_HVSM_IN_NO_ACTIVE_CHILD_f  ((uint8)0U)
#define swc_HVSM_IN_PASSIVE_DISCHARGE  ((uint8)2U)
#define swc_HVSM_IN_SHUTDOWN           ((uint8)5U)
#define swc_HVSM_IN_STANDBY            ((uint8)2U)

/* Named constants for Chart: '<S2>/Chart' */
#define swc_HVSM_IN_AccyConnClsFail    ((uint8)1U)
#define swc_HVSM_IN_AccyPreChg         ((uint8)1U)
#define swc_HVSM_IN_AccyRlyChk         ((uint8)2U)
#define swc_HVSM_IN_AccyRlyFlt         ((uint8)3U)
#define swc_HVSM_IN_DisEnable          ((uint8)2U)
#define swc_HVSM_IN_Enable             ((uint8)3U)
#define swc_HVSM_IN_NO_ACTIVE_CHILD_j  ((uint8)0U)
#define swc_HVSM_IN_Off                ((uint8)4U)
#define swc_HVSM_IN_PowerOff           ((uint8)5U)
#define swc_HVSM_IN_PowerOn            ((uint8)6U)
#define swc_HVSM_IN_PowerOneHvOn       ((uint8)7U)
#define swc_HVSM_IN_PreChgFail         ((uint8)1U)
#define swc_HVSM_IN_PreChgOvrTm        ((uint8)4U)
#define swc_HVSM_IN_PreRlyCtrl         ((uint8)2U)

/* Exported data definition */
#define swc_HVSM_START_SEC_CONST_VOLATILE
#include "swc_HVSM_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean dccc_b_ActiveDischgAlwaysEna = false;/* Referenced by: '<S3>/Constant10' */

/* Always enable DCDC Active Discharge */
const volatile boolean dccc_b_enaAbortDischarge = true;/* Referenced by: '<S3>/Constant2' */

/* Enable DCDC Active Discharge Abort */
const volatile boolean dccc_b_enaDCDCFail = true;/* Referenced by: '<S3>/Constant1' */

/* Enable DCDC Fail judgment by DCDC Mode Act */
const volatile boolean dccc_b_enableDCDC = true;/* Referenced by: '<S25>/Constant10' */

/* Enable DCDC */
const volatile boolean dccc_b_enableDCDCWithOBCPlug = false;/* Referenced by: '<S25>/Constant5' */

/* Enable DCDC when OBC plugged */
const volatile float32 dccc_tm_dischargeTimeout_s = 600.0F;/* Referenced by: '<S3>/Constant11' */

/* DCDC discharge timeout */
const volatile float32 dccc_tm_shutdownTimeout_s = 10.0F;/* Referenced by: '<S3>/Constant7' */

/* DCDC shut-down timeout */
const volatile boolean eadc_b_disMot2InGear0 = true;/* Referenced by: '<S43>/Constant4' */

/* Disable Secondary EAD when RAT actual gear is 0 */
const volatile boolean eadc_b_disMot2InGearPN = false;/* Referenced by: '<S43>/Constant3' */

/* Disable Secondary EAD when gear lever is in position P/N */
const volatile boolean eadc_b_enaInv2AbortDisch = true;/* Referenced by: '<S41>/Constant1' */

/* Enable Secondary EAD Active Discharge Abort */
const volatile boolean eadc_b_enaMot2 = true;/* Referenced by: '<S41>/Constant10' */

/* Enable Secondary EAD */
const volatile boolean eadc_b_enaMot2AfterVehRun = false;/* Referenced by: '<S43>/Constant9' */

/* Secondary EAD enabled after Vehicle is Run */
const volatile boolean eadc_b_forceInv2ActvDisch = true;/* Referenced by: '<S4>/Constant10' */

/* Always enable Secondary EAD Active Discharge */
const volatile float32 eadc_tm_disMot2InGearPN_s = 3.0F;/* Referenced by: '<S43>/Constant10' */

/* Delay for disable Secondary EAD when gear lever is in position P/N */
const volatile float32 eadc_tm_inv2ActvDischTout_s = 600.0F;/* Referenced by: '<S4>/Constant11' */

/* ESecondary AD discharge timeout */
const volatile float32 eadc_tm_inv2ShtdwnTout_s = 3.0F;/* Referenced by: '<S4>/Constant2' */

/* Secondary EAD shut-down timeout */
const volatile boolean hvbc_b_FidVehFltLvl32_ovrdflg = false;/* Referenced by: '<S100>/Constant3' */

/* Override flag for FID_HYB_VEHFLTLVL3_3 */
const volatile boolean hvbc_b_FidVehFltLvl3_ovrdflg = false;/* Referenced by: '<S100>/Constant1' */

/* Override flag for FID_HYB_VEHFLTLVL3_3 */
const volatile boolean hvbc_b_FidVehFltLvl3_ovrdval = false;/* Referenced by: '<S100>/Constant4' */

/* Override value for FID_HYB_VEHFLTLVL3_3 */
const volatile boolean hvbc_b_HvONFailResult_ovrdflg = false;/* Referenced by: '<S131>/FID_ovrdflg' */
const volatile boolean hvbc_b_WriteBookChrgnTarVal_ovrdflg = false;/* Referenced by: '<S95>/Constant42' */
const volatile float32 hvbc_b_WriteBookChrgnTarVal_ovrdval = 100.0F;/* Referenced by: '<S95>/Constant43' */
const volatile boolean hvbc_b_accyCtrlHw_ovrdflg = false;/* Referenced by: '<S2>/Constant8' */
const volatile boolean hvbc_b_accyCtrlHw_ovrdval = true;/* Referenced by: '<S2>/Constant5' */
const volatile boolean hvbc_b_accyRlyUseDcc = false;/* Referenced by: '<S2>/Constant6' */
const volatile boolean hvbc_b_dchaOn_ovrdflg = false;/* Referenced by: '<S83>/Constant12' */
const volatile boolean hvbc_b_dchaOn_ovrdval = false;/* Referenced by: '<S83>/Constant11' */
const volatile boolean hvbc_b_fltShutDn_ovrdflg = false;/* Referenced by: '<S88>/Constant8' */

/* Override flag for fltShutDn */
const volatile boolean hvbc_b_fltShutDn_ovrdval = false;/* Referenced by: '<S88>/Constant6' */

/* Override value for fltShutDn */
const volatile boolean hvbc_b_hvOnReq_ovrdflg = false;/* Referenced by: '<S129>/FID_ovrdflg' */
const volatile boolean hvbc_b_hvOnReq_ovrdval = false;/* Referenced by: '<S129>/FID_ovrdval' */
const volatile boolean hvbc_b_hvOnResult_ovrdflg = false;/* Referenced by: '<S132>/FID_ovrdflg' */
const volatile boolean hvbc_b_hvShutDnFailResult_ovrdflg = false;/* Referenced by: '<S133>/FID_ovrdflg' */
const volatile boolean hvbc_b_hvShutDnReq_ovrdflg = false;/* Referenced by: '<S130>/FID_ovrdflg' */
const volatile boolean hvbc_b_hvShutDnReq_ovrdval = false;/* Referenced by: '<S130>/FID_ovrdval' */
const volatile boolean hvbc_b_hvShutDnResult_ovrdflg = false;/* Referenced by: '<S134>/FID_ovrdflg' */
const volatile boolean hvbc_b_otaHvOn_ovrdflg = false;/* Referenced by: '<S61>/Constant7' */
const volatile boolean hvbc_b_otaHvOn_ovrdval = false;/* Referenced by: '<S61>/Constant8' */
const volatile boolean hvbc_b_otaShutDn_ovrdflg = false;/* Referenced by: '<S61>/Constant5' */
const volatile boolean hvbc_b_otaShutDn_ovrdval = false;/* Referenced by: '<S61>/Constant6' */
const volatile boolean hvbc_b_prepCmpl_ovrdval = true;/* Referenced by: '<S62>/Constant6' */
const volatile boolean hvbc_b_rsrNotAlwChg_ovrdflg = false;/* Referenced by: '<S95>/Constant11' */
const volatile boolean hvbc_b_rsrNotAlwChg_ovrdval = false;/* Referenced by: '<S95>/Constant10' */
const volatile boolean hvbc_b_udsGetActiveSession_ovrdflg = false;/* Referenced by: '<S61>/Constant34' */
const volatile boolean hvbc_b_useAccyCanEnb = true;/* Referenced by: '<S9>/Constant4' */
const volatile boolean hvbc_b_vcuWkUpOvrd = false;/* Referenced by: '<S5>/Constant4' */

/* vcuWkUp signal overide flg */
const volatile boolean hvbc_b_vcuWkUpOvrdVal = false;/* Referenced by: '<S5>/Constant3' */

/* vcuWkUp signal overide value */
const volatile boolean hvbc_cesc_b_evtFaildCrashEvent_ovrdflg = false;/* Referenced by: '<S79>/DFC_ovrdflg' */
const volatile boolean hvbc_cesc_b_evtFaildCrashEvent_ovrdval = false;/* Referenced by: '<S79>/DFC_ovrdval' */
const volatile boolean hvbc_cesc_b_evtFaildV2XDchaSwt_ovrdflg = false;/* Referenced by: '<S190>/DFC_ovrdflg' */
const volatile boolean hvbc_cesc_b_evtFaildV2XDchaSwt_ovrdval = false;/* Referenced by: '<S190>/DFC_ovrdval' */
const volatile float32 hvbc_i_bmsCurrent_A = 10.0F;/* Referenced by:
                                                    * '<S62>/Constant'
                                                    * '<S90>/Constant1'
                                                    */

/* HVB Shutdown Condition */
const volatile float32 hvbc_q_220ACQuitSoc_pct = 20.0F;/* Referenced by: '<S83>/Constant7' */
const volatile float32 hvbc_q_CampModeSoc_pct = 20.0F;/* Referenced by: '<S63>/Constant4' */
const volatile float32 hvbc_q_dchaAlwSoc_pct = 20.0F;/* Referenced by: '<S83>/Constant4' */
const volatile float32 hvbc_s_FidVehFltLvl3BTmOut_s = 20.0F;/* Referenced by: '<S100>/Constant10' */

/* HV off max time for the FID_HYB_VEHFLTLVL3_2 */
const volatile uint8 hvbc_st_HvONFailResult_ovrdval = 0U;/* Referenced by: '<S131>/FID_ovrdval' */
const volatile uint8 hvbc_st_hvOnResult_ovrdval = 0U;/* Referenced by: '<S132>/FID_ovrdval' */
const volatile uint8 hvbc_st_hvShutDnFailResult_ovrdval = 0U;/* Referenced by: '<S133>/FID_ovrdval' */
const volatile uint8 hvbc_st_hvShutDnResult_ovrdval = 0U;/* Referenced by: '<S134>/FID_ovrdval' */
const volatile uint8 hvbc_st_udsGetActiveSession_ovrdval = 0U;/* Referenced by: '<S61>/Constant33' */
const volatile float32 hvbc_t_accyDisEnOvrTm_s = 5.0F;/* Referenced by: '<S2>/Constant3' */
const volatile float32 hvbc_t_accyPreChgOvrTm_s = 5.0F;/* Referenced by: '<S2>/Constant13' */
const volatile float32 hvbc_t_accyRePreChgTm_s = 5.0F;/* Referenced by: '<S2>/Constant24' */
const volatile float32 hvbc_t_accyRlyClsOvrTmDrvone_s = 1.5F;/* Referenced by: '<S2>/Constant15' */
const volatile float32 hvbc_t_accyRlyClsOvrTm_s = 2.0F;/* Referenced by: '<S2>/Constant14' */
const volatile float32 hvbc_t_ignOnHold_s = 2.0F;/* Referenced by: '<S2>/Constant1' */
const volatile float32 hvbc_tm_AftRun_s = 5.0F;/* Referenced by: '<S99>/Constant4' */
const volatile float32 hvbc_tm_BmsNegClsDrv_s = 30.0F;/* Referenced by: '<S99>/Constant3' */
const volatile float32 hvbc_tm_BmsNegOpenEmgy_s = 1.5F;/* Referenced by: '<S99>/Constant26' */
const volatile float32 hvbc_tm_BmsNegOpen_s = 3.0F;/* Referenced by: '<S99>/Constant24' */
const volatile float32 hvbc_tm_BmsRlyOpnDly_s = 0.2F;/* Referenced by: '<S5>/Constant15' */
const volatile float32 hvbc_tm_BrkTankRdy_s = 3600.0F;/* Referenced by: '<S99>/Constant11' */
const volatile float32 hvbc_tm_CampFailrReason_s = 1.5F;/* Referenced by: '<S63>/Constant10' */
const volatile float32 hvbc_tm_DcdcAct_s = 10.0F;/* Referenced by: '<S99>/Constant8' */
const volatile float32 hvbc_tm_Default_s = 3600.0F;/* Referenced by: '<S99>/Constant5' */
const volatile float32 hvbc_tm_HcmAssisCls_s = 1.5F;/* Referenced by: '<S99>/Constant7' */
const volatile float32 hvbc_tm_HcmAssisOpenEmgy_s = 0.5F;/* Referenced by: '<S99>/Constant22' */
const volatile float32 hvbc_tm_HcmAssisOpen_s = 0.5F;/* Referenced by: '<S99>/Constant19' */
const volatile float32 hvbc_tm_HcmNegCls_s = 0.5F;/* Referenced by: '<S99>/Constant6' */
const volatile float32 hvbc_tm_HcmNegOpenEmgy_s = 0.5F;/* Referenced by: '<S99>/Constant21' */
const volatile float32 hvbc_tm_HcmNegOpen_s = 0.5F;/* Referenced by: '<S99>/Constant20' */
const volatile float32 hvbc_tm_HcmPosCls_s = 1.5F;/* Referenced by: '<S99>/Constant10' */
const volatile float32 hvbc_tm_HcmPosOpenEmgy_s = 0.5F;/* Referenced by: '<S99>/Constant18' */
const volatile float32 hvbc_tm_HcmPosOpen_s = 0.5F;/* Referenced by: '<S99>/Constant16' */
const volatile float32 hvbc_tm_HcmWkUp_s = 10.0F;/* Referenced by: '<S99>/Constant1' */
const volatile float32 hvbc_tm_HvDvcDeActEmgy_s = 30.0F;/* Referenced by: '<S99>/Constant17' */
const volatile float32 hvbc_tm_HvDvcDeAct_s = 1.5F;/* Referenced by: '<S99>/Constant14' */
const volatile float32 hvbc_tm_LvSysCutOffReq_s = 10.0F;/* Referenced by: '<S99>/Constant25' */
const volatile float32 hvbc_tm_McuAct_s = 0.5F;/* Referenced by: '<S99>/Constant12' */
const volatile float32 hvbc_tm_McuDeAct_s = 10.0F;/* Referenced by: '<S99>/Constant15' */
const volatile float32 hvbc_tm_McuDisChgDly_s = 2.0F;/* Referenced by: '<S5>/Constant16' */
const volatile float32 hvbc_tm_McuDsChg_s = 3.0F;/* Referenced by: '<S99>/Constant23' */
const volatile float32 hvbc_tm_McuWkUp_s = 0.2F;/* Referenced by: '<S99>/Constant2' */
const volatile float32 hvbc_tm_SdcacAct_s = 0.5F;/* Referenced by: '<S99>/Constant9' */
const volatile float32 hvbc_tm_ShutDnWait_s = 360.0F;/* Referenced by: '<S99>/Constant13' */
const volatile float32 hvbc_tm_WakeUpOffDly_s = 2.5F;/* Referenced by:
                                                      * '<S231>/Constant6'
                                                      * '<S232>/Constant6'
                                                      * '<S233>/Constant6'
                                                      * '<S234>/Constant6'
                                                      */

/* Wake Up Off Delay for Relay Timeout Detection */
const volatile float32 hvbc_tm_bmsIntelChgCmplt_s = 7200.0F;/* Referenced by: '<S99>/Constant28' */

/* HVB Intelligent Charge Timeout Detection */
const volatile float32 hvbc_tm_canNmWaitSlpThd_s = 10.0F;/* Referenced by: '<S5>/Constant8' */
const volatile float32 hvbc_tm_chrgRlyTimeOut_s = 150.0F;/* Referenced by:
                                                          * '<S231>/Constant5'
                                                          * '<S232>/Constant5'
                                                          * '<S233>/Constant5'
                                                          * '<S234>/Constant5'
                                                          */
const volatile float32 hvbc_tm_dcdcEnFailChg_s = 180.0F;/* Referenced by: '<S5>/Constant12' */
const volatile float32 hvbc_tm_disChgDccUnWrk_s = 2.0F;/* Referenced by: '<S196>/Constant7' */
const volatile float32 hvbc_tm_disChgSocLow_s = 2.0F;/* Referenced by: '<S197>/Constant7' */
const volatile float32 hvbc_tm_dischRlyTimeOut_s = 100.0F;/* Referenced by:
                                                           * '<S231>/Constant2'
                                                           * '<S232>/Constant2'
                                                           * '<S233>/Constant2'
                                                           * '<S234>/Constant2'
                                                           */
const volatile float32 hvbc_tm_hvbCampModeExit_s = 2.0F;/* Referenced by:
                                                         * '<S63>/t_step1'
                                                         * '<S63>/t_step3'
                                                         */
const volatile float32 hvbc_tm_hvbChEpbgCfmTm_s = 2.0F;/* Referenced by:
                                                        * '<S64>/Constant11'
                                                        * '<S64>/Constant12'
                                                        * '<S64>/Constant13'
                                                        * '<S64>/Constant8'
                                                        */
const volatile float32 hvbc_u_accyPreFinVolt_V = 20.0F;/* Referenced by: '<S2>/Constant11' */
const volatile float32 hvbc_u_accyRlyClsVolt_V = 3.0F;/* Referenced by: '<S2>/Constant' */
const volatile float32 hvbc_u_accyRlyFltVolt_V = 25.0F;/* Referenced by: '<S2>/Constant10' */
const volatile float32 hvbc_v_otaCutOffHvSpd_kph = 5.0F;/* Referenced by: '<S61>/Constant13' */
const volatile boolean hvbd_b_RmtCtrlSw = true;/* Referenced by: '<S63>/Constant12' */
const volatile float32 hvbd_tm_BookChrgnTarTm_s = 0.5F;/* Referenced by: '<S95>/Constant28' */
const volatile float32 obcc_tm_obcNoWakeUpAtIgnOn_s = 1.0F;/* Referenced by: '<S310>/Constant2' */

/* OBC no Wake-Up time after Ignition ON */
const volatile float32 obcc_v_ChargerPlugThr_kph = 3.0F;/* Referenced by:
                                                         * '<S5>/Constant5'
                                                         * '<S6>/Constant5'
                                                         * '<S64>/Constant5'
                                                         */

/* Vehicle speed threshold for charger plug detection */
const volatile float32 obcc_v_VehLvl32FltThr_kph = 5.0F;/* Referenced by: '<S100>/Constant5' */

/* Vehicle speed threshold for VehLvl32Flt */
const volatile boolean swchvsm_hvbc_b_notUseHvBusSts = true;/* Referenced by: '<S90>/Constant' */
const volatile boolean swchvsm_hvbc_flg_PowerONEB_Cfg = false;/* Referenced by: '<S5>/Constant11' */
const volatile float32 swchvsm_hvbc_tm_BmsNegClsChg_s = 60.0F;/* Referenced by: '<S99>/Constant31' */
const volatile float32 swchvsm_hvbc_tm_hvShutDnEmgy_s = 10.0F;/* Referenced by: '<S99>/Constant30' */
const volatile float32 swchvsm_hvbc_tm_hvbChgCfmTm_s = 0.1F;/* Referenced by: '<S64>/Constant3' */
const volatile float32 swchvsm_hvbc_tm_hvbChgFltCfm_s = 600.0F;/* Referenced by: '<S91>/Constant4' */
const volatile float32 swchvsm_hvbc_tm_hvbChgFltTm_s = 600.05F;/* Referenced by: '<S91>/Constant1' */
const volatile float32 swchvsm_hvbc_tm_shtDnWaitEmgy_s = 30.0F;/* Referenced by: '<S99>/Constant29' */
const volatile boolean swchvsm_vsmc_b_enaPTReadyVehRun = false;/* Referenced by: '<S5>/Constant7' */

/* Enable PT Ready determination of Vehicle Run */
#define swc_HVSM_STOP_SEC_CONST_VOLATILE
#include "swc_HVSM_MemMap.h"
#define swc_HVSM_START_SEC_VAR
#include "swc_HVSM_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
uint8 bmsd_e_modeTgt;                  /* '<S5>/Signal Conversion3' */
boolean dccd_b_DCDCEnabled;            /* '<S25>/Logical Operator1' */

/* DCDC Enabled */
DCDCMode dccd_e_modeTgt;               /* '<S3>/DCDC_Converter' */

/* DCDC Target Mode */
boolean eadd_b_ead2Avail;              /* '<S41>/Logical Operator7' */

/* Secondary EAD Available */
boolean eadd_b_ead2Enad;               /* '<S41>/Relational Operator6' */

/* Secondary EAD Enabled */
ElMac eadd_e_inv2ModeTgt;              /* '<S4>/TractionMotor' */

/* Secondary EAD Target Mode */
boolean hvbd_b_CampModeFb;             /* '<S164>/Logical Operator3' */
boolean hvbd_b_ChgLEDCtlFlg;           /* '<S281>/timed_delay' */
boolean hvbd_b_FidVehFltLvl3HvOff;     /* '<S100>/Switch' */

/* FID Vehicle fault level HV off */
boolean hvbd_b_LvSysCutOffAlw;         /* '<S92>/Logical Operator3' */

/* LV System Cut Off Allow */
boolean hvbd_b_LvSysSlfChkOk;          /* '<S93>/Logical Operator2' */

/* LV System Self-check OK */
boolean hvbd_b_ResChgRouterReset;      /* '<S95>/Logical Operator4' */
boolean hvbd_b_ResChgRouterSwt;        /* '<S95>/SR_latch1' */
boolean hvbd_b_StsModeReqFlg;          /* '<S272>/FixPt Relational Operator' */
boolean hvbd_b_TakeEleSwtIndReq;       /* '<S9>/Switch4' */
boolean hvbd_b_acPtcEnb;               /* '<S288>/Logical Operator3' */
boolean hvbd_b_accyCtrlHw;             /* '<S2>/Switch' */
boolean hvbd_b_accyDisEnOvrTm;         /* '<S2>/Data Type Conversion4' */
boolean hvbd_b_accyEnReq;              /* '<S9>/Logical Operator3' */
uint8 hvbd_b_accyHvOnCmd;              /* '<S2>/Data Type Conversion3' */
boolean hvbd_b_accyLvPwrOnCmd;         /* '<S10>/SR_latch' */
boolean hvbd_b_accyPreRlyCmd;          /* '<S2>/Data Type Conversion6' */
boolean hvbd_b_accyWrkEnCmd;           /* '<S2>/Data Type Conversion' */
boolean hvbd_b_allowChg;               /* '<S89>/LdtNewPlatform' */

/* Charge Allow */
boolean hvbd_b_assistPosRlyTmOut;      /* '<S231>/SR_latch' */

/* Assist Positive Relay Time Out Flag */
boolean hvbd_b_bmsNegRlyTmOut;         /* '<S232>/SR_latch' */

/* BMS Negative Relay Time Out Flag */
boolean hvbd_b_brpEpsSlfChkOk;         /* '<S93>/Logical Operator1' */

/* Brake Pump and EPS Self-check OK */
boolean hvbd_b_chargeReq;              /* '<S64>/Logical Operator1' */

/* Charge Request */
boolean hvbd_b_chgCablePlugged;        /* '<S5>/Switch4' */
boolean hvbd_b_crashShutDn;            /* '<Root>/Data Type Conversion80' */
boolean hvbd_b_dchaOn;                 /* '<S83>/Switch4' */
boolean hvbd_b_dchaReq;                /* '<S83>/Data Type Conversion' */
boolean hvbd_b_emgyShutDn;             /* '<S5>/Logical Operator5' */
boolean hvbd_b_fltPwrShutDn;           /* '<S5>/Unit Delay8' */
boolean hvbd_b_fltShutDn;              /* '<S88>/Switch1' */

/* Fault Shut Down */
boolean hvbd_b_hcmNegRlyTmOut;         /* '<S233>/SR_latch' */

/* HCM Negative Relay Time Out Flag */
boolean hvbd_b_hvBusShutDwnCmpl;       /* '<S62>/Logical Operator4' */

/* HV Bus shutdown complete */
boolean hvbd_b_hvDvcShutDnCmplt;       /* '<S90>/Logical Operator4' */

/* High Voltage Device Shut Down Complete */
boolean hvbd_b_hvShutDnCmplt;          /* '<S90>/Logical Operator1' */

/* High Voltage Shut Down Complete */
boolean hvbd_b_hvbHvOnReq;             /* '<S139>/Switch2' */
boolean hvbd_b_hvbIntelChgExitReq;     /* '<S5>/Signal Conversion1' */

/* HVB Intelligent Charge Exit Flag */
boolean hvbd_b_hvbShutDnReq;           /* '<S140>/Switch2' */
boolean hvbd_b_hvilOpenCfm;            /* '<S5>/SR_latch1' */
boolean hvbd_b_lvCutOffReq;            /* '<S89>/LdtNewPlatform' */

/* LV Cut Off Request */
boolean hvbd_b_mainPosRlyTmOut;        /* '<S234>/SR_latch' */

/* Main Positive Relay Time Out Flag */
boolean hvbd_b_otaHvOn;                /* '<S61>/Switch7' */
boolean hvbd_b_otaShutDn;              /* '<S61>/Switch1' */
boolean hvbd_b_parkingSts;             /* '<S64>/Relational Operator2' */
boolean hvbd_b_rlyTmOut;               /* '<S94>/Logical Operator' */

/* Relay Time Out Flag */
boolean hvbd_b_rsrNotAlwChg;           /* '<S95>/Logical Operator6' */
boolean hvbd_b_startReq;               /* '<S98>/SR_latch' */

/* Start Request */
boolean hvbd_b_tboxPrtFullSwStUB;      /* '<Root>/Data Type Conversion214' */
boolean hvbd_b_tmOutFlg;               /* '<S99>/Relational Operator' */

/* PMM Time Out Flg */
boolean hvbd_b_tmOutFlgCfm;            /* '<S301>/Logical Operator3' */

/* PMM Time Out Flg Latched */
boolean hvbd_b_vcuRdyToSlp;            /* '<S5>/Logical Operator4' */

/* VCU Ready To Sleep */
boolean hvbd_b_vcuWkUpCmd;             /* '<S5>/Switch' */

/* VCU Wake Up Command */
boolean hvbd_b_vcuWkUpCmdRaw;          /* '<S89>/LdtNewPlatform' */

/* VCU Wake Up Command Raw */
boolean hvbd_cesd_b_CrashEvent;        /* '<S187>/Switch2' */

/* Crash Signal */
boolean hvbd_cesd_b_V2XDchaSwt;        /* '<S198>/Switch2' */
PmmStatus hvbd_e_PmmStatus;            /* '<S89>/LdtNewPlatform' */

/* PMM Status */
HVBattStatus hvbd_e_modeTgt;           /* '<S89>/LdtNewPlatform' */

/* HVB Target Mode */
PmmStatus hvbd_e_tmOutSource;          /* '<S99>/Switch' */

/* PMM Status */
uint16 hvbd_pct_BookChrgnTarValFb;     /* '<S95>/Switch' */
uint16 hvbd_pct_LocBkChgTarVal_Read;   /* '<S95>/C Caller2' */
uint8 hvbd_st_CampModeFbFailrReason;   /* '<S63>/Switch6' */
uint8 hvbd_st_RmChgCmdFailPmt;         /* '<S95>/Switch5' */
uint8 hvbd_st_accyPreRlyFlt;           /* '<S2>/Data Type Conversion9' */
uint8 hvbd_st_accyPreRlySts;           /* '<S2>/Data Type Conversion7' */
uint8 hvbd_st_accyRlyFlt;              /* '<S2>/Data Type Conversion8' */
uint8 hvbd_st_accyRlyVoltSamSw;        /* '<S2>/Data Type Conversion5' */
uint8 hvbd_st_accyTakeSts;             /* '<S2>/Data Type Conversion2' */
uint8 hvbd_st_bbmWrkEnCmd;             /* '<S2>/Data Type Conversion1' */
uint8 hvbd_st_hcmMaiRlyNegClsReq;      /* '<S89>/LdtNewPlatform' */

/* HCM Main Negative Relay Close Command */
uint8 hvbd_st_hvbAssiRlyPosClsReq;     /* '<S89>/LdtNewPlatform' */

/* HVB Assist Positive Relay Close Command */
uint8 hvbd_st_hvbHvOnFailResult;       /* '<S128>/Signal Conversion' */
uint8 hvbd_st_hvbHvOnFlg;              /* '<S126>/Signal Conversion' */
uint8 hvbd_st_hvbMaiRlyNegClsReq;      /* '<S89>/LdtNewPlatform' */

/* HVB Main Negative Relay Close Command */
uint8 hvbd_st_hvbMaiRlyPosClsReq;      /* '<S89>/LdtNewPlatform' */

/* HVB Main Positive Relay Close Command */
uint8 hvbd_st_hvbShutDnFailResult;     /* '<S127>/Signal Conversion' */
uint8 hvbd_st_hvbShutDnFlg;            /* '<S125>/Signal Conversion' */
uint8 hvbd_st_ptRdyInd;                /* '<S89>/LdtNewPlatform' */

/* Power Train Ready Indication */
uint8 hvbd_st_tboxChgSftSwCtlStEV;     /* '<S95>/Switch2' */
uint8 hvbd_st_tboxPrtFullSwSt;         /* '<Root>/Data Type Conversion215' */
uint8 hvbd_st_udsGetActiveSession;     /* '<S61>/Switch25' */
boolean hvsm_hvbd_b_nmRdySlp;          /* '<S5>/Logical Operator3' */
boolean hvsm_hvbd_b_nmWkUp;            /* '<S5>/C Caller' */
uint8 hvsm_pmmd_num_keyOnCnt;          /* '<S95>/C Caller1' */
boolean obcd_b_chargerPlugged;         /* '<S6>/Relational Operator1' */

/* Charger Plugged */
ChargerStatus obcd_e_chargerSts;       /* '<S6>/ChargerStatus' */

/* Validated external charger status */
uint8 swchvsm_dccd_pct_DCDCPwrLmt;     /* '<S25>/Switch' */

/* DCDC Enabled Power Limit */
boolean swchvsm_hvbd_b_hvbChgEnd;      /* '<S91>/Relational Operator2' */
boolean swchvsm_hvbd_b_hvbChging;      /* '<S91>/Logical Operator11' */
boolean swchvsm_hvbd_b_hvbNoChgFlg;    /* '<S91>/Logical Operator2' */
boolean swchvsm_hvbd_st_hvbRlyClsd;    /* '<S91>/Logical Operator7' */

#define swc_HVSM_STOP_SEC_VAR
#include "swc_HVSM_MemMap.h"

/* Invariant block signals (default storage) */
const ConstB_swc_HVSM_T swc_HVSM_ConstB = {
  0,                                   /* '<S30>/Logical Operator6' */
  1,                                   /* '<S5>/Constant6' */
  1,                                   /* '<S90>/Logical Operator5' */
  1,                                   /* '<S90>/Logical Operator6' */
  0,                                   /* '<S289>/Compare' */
  0,                                   /* '<S290>/Compare' */
  0,                                   /* '<S98>/Logical Operator1' */
  1                                    /* '<S100>/Logical Operator1' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_HVSM_T swc_HVSM_ARID_DEF;

/* externs placed here */
static boolean swc_HVSM_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HVSM_T *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_turnOFF_delay_Init(boolean *rty_flg_out);
static boolean swc_HVSM_turnOFF_delay(boolean rtu_flg_in, float32
  rtu_t_delay_off, float32 rtu_t_step, ARID_DEF_turnOFF_delay_swc_HV_T
  *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_turnON_delay_Init(boolean *rty_flg_out);
static void swc_HVSM_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_HVS_T
  *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_turnOFF_delay1_Init(boolean *rty_flg_out);
static void swc_HVSM_turnOFF_delay1(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay1_swc_H_T
  *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_pos(float32 rtu_in_val, float32 *rty_same_val);
static void swc_HVSM_neg(float32 rtu_in_val, float32 *rty_neg_val);
static void swc_HVSM_SR_latch_n(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HVSM_f_T *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch1_swc_HVSM_T *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_turnON_delay1_Init(boolean *rty_flg_out);
static void swc_HVSM_turnON_delay1(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay1_swc_HV_T
  *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_SR_latch1_f(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HVSM_a_T *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_SR_latch_i(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HVSM_ad_T *swc_HVSM__ARID_DEF_arg);
static void swc_HVSM_OBC_ChargerStatus_Init(void);
static void swc_HVSM_OBC_ChargerStatus(void);
static void swc_HVSM_LdtNewPlatform(void);
static void swc_HVSM_TimeOutManagement(void);
static void swc_HVSM_HVB_ModeManager_Init(void);
static void swc_HVSM_HVB_ModeManager(void);
static void swc_HVSM_Get_FID_Enable(void);
static void swc_HV_EAD_ModeManagerMot2_Init(void);
static void swc_HVSM_EAD_ModeManagerMot2(void);
static void swc_HVSM_Get_FID_Enable_b(void);
static void swc_HVSM_DCC_ModeManager(void);

/* Forward declaration for local functions */
static void swc_HVS_enter_internal_POWER_ON(void);
static void swc_HVSM_WAKEUP(void);
static void swc_HVSM_enter_atomic_OFF(void);
static void swc_HVSM_AFTER_RUN(void);
static void swc_HVSM_BMS_RELAY_CLOSE(void);
static void swc_HVSM_BMS_RELAY_OPEN(void);
static void swc_HVSM_BMS_RELAY_OPEN_EMGY(void);
static void swc_HVSM_CHARGE_WAIT(void);
static void swc_HVSM_DCDC_ACT(void);
static void swc_HVSM_IMMO_CHECK(void);
static void swc_HVSM_enter_atomic_INIT(void);
static void swc_HVSM_INIT(void);
static void swc_HVSM_LV_SYS_CUT_OFF_REQUEST(void);
static void swc_HVSM_LV_SYS_CUT_OFF_WAIT(void);
static void swc_HVSM_MCU_ACT(void);
static void swc_HVSM_MCU_DEACT(void);
static void swc_HVSM_OFF(void);
static void swc_HVSM_POWER_ON(void);
static void swc_HVSM_PowerON_WAIT(void);
static void swc_HVSM_SDCAC_ACT(void);
static void swc_HVSM_SHUT_DOWN_WAIT(void);
static void swc_HVSM_TIMEOUT(void);

/* Forward declaration for local functions */
static void swc_HVSM_PowerOneHvOn(const boolean *RelationalOperator2, const
  boolean *RelationalOperator1);

/*
 * Output and update for atomic system:
 *    '<S10>/SR_latch'
 *    '<S61>/SR_latch1'
 *    '<S61>/SR_latch2'
 *    '<S83>/SR_latch'
 *    '<S92>/SR_latch'
 *    '<S92>/SR_latch1'
 *    '<S92>/SR_latch3'
 *    '<S92>/SR_latch4'
 *    '<S231>/SR_latch'
 *    '<S232>/SR_latch'
 *    ...
 */
static boolean swc_HVSM_SR_latch(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HVSM_T *swc_HVSM__ARID_DEF_arg)
{
  boolean rty_flg_out_0;

  /* Logic: '<S23>/Logical Operator3' incorporates:
   *  Logic: '<S23>/Logical Operator'
   *  Logic: '<S23>/Logical Operator1'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  rty_flg_out_0 = ((swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                   (!rtu_flg_reset));

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE = rty_flg_out_0;
  return rty_flg_out_0;
}

/*
 * System initialize for atomic system:
 *    '<S2>/turnOFF_delay'
 *    '<S63>/turnOFF_delay2'
 *    '<S231>/turnOFF_delay'
 *    '<S232>/turnOFF_delay'
 *    '<S233>/turnOFF_delay'
 *    '<S234>/turnOFF_delay'
 *    '<S100>/turnOFF_delay'
 *    '<S43>/turnOFF_delay'
 */
static void swc_HVSM_turnOFF_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S11>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S2>/turnOFF_delay'
 *    '<S63>/turnOFF_delay2'
 *    '<S231>/turnOFF_delay'
 *    '<S232>/turnOFF_delay'
 *    '<S233>/turnOFF_delay'
 *    '<S234>/turnOFF_delay'
 *    '<S100>/turnOFF_delay'
 *    '<S43>/turnOFF_delay'
 */
static boolean swc_HVSM_turnOFF_delay(boolean rtu_flg_in, float32
  rtu_t_delay_off, float32 rtu_t_step, ARID_DEF_turnOFF_delay_swc_HV_T
  *swc_HVSM__ARID_DEF_arg)
{
  boolean rty_flg_out_0;
  float32 rtb_t_delay_off;

  /* Saturate: '<S11>/Saturation1' */
  if (rtu_t_delay_off > 1.6777216E+7F) {
    /* Saturate: '<S11>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (rtu_t_delay_off < 0.0F) {
    /* Saturate: '<S11>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S11>/Saturation1' */
    rtb_t_delay_off = rtu_t_delay_off;
  }

  /* End of Saturate: '<S11>/Saturation1' */

  /* Chart: '<S11>/timed_delay' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   */
  if (swc_HVSM__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li == 0U) {
    swc_HVSM__ARID_DEF_arg->is_active_c12_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_HVSM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_HVSM_IN_ON;
      rty_flg_out_0 = true;
    } else {
      swc_HVSM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF;
      rty_flg_out_0 = false;
    }
  } else {
    switch (swc_HVSM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib) {
     case swc_HVSM_IN_OFF:
      if (rtu_flg_in) {
        swc_HVSM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_HVSM_IN_ON;
        rty_flg_out_0 = true;
      } else {
        rty_flg_out_0 = false;
      }
      break;

     case swc_HVSM_IN_OFF_WAIT:
      if (rtu_flg_in) {
        swc_HVSM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_HVSM_IN_ON;
        rty_flg_out_0 = true;
      } else if (swc_HVSM__ARID_DEF_arg->t_wait > rtb_t_delay_off - rtu_t_step)
      {
        swc_HVSM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF;
        rty_flg_out_0 = false;
      } else {
        swc_HVSM__ARID_DEF_arg->t_wait += rtu_t_step;
        rty_flg_out_0 = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtu_flg_in) {
        if (rtb_t_delay_off == 0.0F) {
          swc_HVSM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF;
          rty_flg_out_0 = false;
        } else {
          swc_HVSM__ARID_DEF_arg->is_c12_Ricardo_SW_dev_lib =
            swc_HVSM_IN_OFF_WAIT;
          swc_HVSM__ARID_DEF_arg->t_wait = rtu_t_step;
          rty_flg_out_0 = true;
        }
      } else {
        rty_flg_out_0 = true;
      }
      break;
    }
  }

  /* End of Chart: '<S11>/timed_delay' */
  return rty_flg_out_0;
}

/*
 * System initialize for atomic system:
 *    '<S310>/turnON_delay'
 *    '<S137>/turnON_delay1'
 *    '<S138>/turnON_delay1'
 *    '<S63>/turnON_delay'
 *    '<S63>/turnON_delay1'
 *    '<S196>/turnON_delay1'
 *    '<S197>/turnON_delay1'
 *    '<S91>/turnON_delay'
 *    '<S91>/turnON_delay1'
 *    '<S231>/turnON_delay'
 *    ...
 */
static void swc_HVSM_turnON_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S311>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S310>/turnON_delay'
 *    '<S137>/turnON_delay1'
 *    '<S138>/turnON_delay1'
 *    '<S63>/turnON_delay'
 *    '<S63>/turnON_delay1'
 *    '<S196>/turnON_delay1'
 *    '<S197>/turnON_delay1'
 *    '<S91>/turnON_delay'
 *    '<S91>/turnON_delay1'
 *    '<S231>/turnON_delay'
 *    ...
 */
static void swc_HVSM_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_HVS_T
  *swc_HVSM__ARID_DEF_arg)
{
  float32 rtb_t_delay_on_i;

  /* Saturate: '<S311>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S311>/Saturation' */
    rtb_t_delay_on_i = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S311>/Saturation' */
    rtb_t_delay_on_i = 0.0F;
  } else {
    /* Saturate: '<S311>/Saturation' */
    rtb_t_delay_on_i = rtu_t_delay_on;
  }

  /* End of Saturate: '<S311>/Saturation' */

  /* Chart: '<S311>/timed_delay' incorporates:
   *  DataTypeConversion: '<S311>/Data Type Conversion'
   */
  if (swc_HVSM__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_HVSM__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_HVSM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_ON_m;
      *rty_flg_out = true;
    } else {
      swc_HVSM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF_i;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_HVSM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib) {
     case swc_HVSM_IN_OFF_i:
      if (rtu_flg_in) {
        if (rtb_t_delay_on_i == 0.0F) {
          swc_HVSM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_ON_m;
          *rty_flg_out = true;
        } else {
          swc_HVSM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
            swc_HVSM_IN_ON_WAIT;
          swc_HVSM__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_HVSM_IN_ON_m:
      if (!rtu_flg_in) {
        swc_HVSM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF_i;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_HVSM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF_i;
        *rty_flg_out = false;
      } else if (swc_HVSM__ARID_DEF_arg->t_wait > rtb_t_delay_on_i - rtu_t_step)
      {
        swc_HVSM__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_ON_m;
        *rty_flg_out = true;
      } else {
        swc_HVSM__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S311>/timed_delay' */
}

/* System initialize for function-call system: '<S1>/OBC_ChargerStatus' */
static void swc_HVSM_OBC_ChargerStatus_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out;

  /* SystemInitialize for Atomic SubSystem: '<S310>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out);

  /* End of SystemInitialize for SubSystem: '<S310>/turnON_delay' */
}

/* Output and update for function-call system: '<S1>/OBC_ChargerStatus' */
static void swc_HVSM_OBC_ChargerStatus(void)
{
  /* local block i/o variables */
  boolean rtb_LogicalOperator1;
  boolean rtb_flg_out;
  boolean rtb_LogicalOperator3;

  /* Logic: '<S6>/Logical Operator3' incorporates:
   *  Constant: '<S6>/Constant5'
   *  RelationalOperator: '<S6>/Relational Operator3'
   */
  rtb_LogicalOperator3 = (swc_HVSM_ARID_DEF.DataTypeConversion15 &&
    (swc_HVSM_ARID_DEF.DataTypeConversion27 <= obcc_v_ChargerPlugThr_kph) &&
    swc_HVSM_ARID_DEF.DataTypeConversion16);

  /* Logic: '<S310>/Logical Operator1' incorporates:
   *  Logic: '<S310>/Logical Operator7'
   */
  rtb_LogicalOperator1 = ((!swc_HVSM_ARID_DEF.DataTypeConversion16) &&
    swc_HVSM_ARID_DEF.DataTypeConversion24);

  /* Outputs for Atomic SubSystem: '<S310>/turnON_delay' */
  /* Constant: '<S310>/Constant2' incorporates:
   *  Constant: '<S310>/Constant8'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator1, obcc_tm_obcNoWakeUpAtIgnOn_s,
                        ((float32)OBC_TASK_INTERVAL_S), &rtb_flg_out,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay_nv);

  /* End of Outputs for SubSystem: '<S310>/turnON_delay' */

  /* Chart: '<S6>/ChargerStatus' */
  if (swc_HVSM_ARID_DEF.is_active_c1_swc_HVSM == 0U) {
    swc_HVSM_ARID_DEF.is_active_c1_swc_HVSM = 1U;
    swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_UNKNOWN;
    obcd_e_chargerSts = ChargerStatus_UNKNOWN;
  } else {
    switch (swc_HVSM_ARID_DEF.is_c1_swc_HVSM) {
     case swc_HVSM_IN_CONFIRMED_PLUGGED:
      obcd_e_chargerSts = ChargerStatus_CONFIRMED_PLUGGED;
      if (swc_HVSM_ARID_DEF.DataTypeConversion17) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_CONFIRMED_UNPLUGGED;
        obcd_e_chargerSts = ChargerStatus_CONFIRMED_UNPLUGGED;
      } else if (!rtb_LogicalOperator3) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_SUSPECT_PLUGGED;
        obcd_e_chargerSts = ChargerStatus_SUSPECT_PLUGGED;
      }
      break;

     case swc_HVSM_IN_CONFIRMED_UNPLUGGED:
      obcd_e_chargerSts = ChargerStatus_CONFIRMED_UNPLUGGED;
      if (rtb_LogicalOperator3) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_CONFIRMED_PLUGGED;
        obcd_e_chargerSts = ChargerStatus_CONFIRMED_PLUGGED;
      } else if (!swc_HVSM_ARID_DEF.DataTypeConversion17) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_SUSPECT_UNPLUGGED;
        obcd_e_chargerSts = ChargerStatus_SUSPECT_UNPLUGGED;
      }
      break;

     case swc_HVSM_IN_SUSPECT_PLUGGED:
      obcd_e_chargerSts = ChargerStatus_SUSPECT_PLUGGED;
      if (rtb_LogicalOperator3) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_CONFIRMED_PLUGGED;
        obcd_e_chargerSts = ChargerStatus_CONFIRMED_PLUGGED;
      } else if (swc_HVSM_ARID_DEF.DataTypeConversion17) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_CONFIRMED_UNPLUGGED;
        obcd_e_chargerSts = ChargerStatus_CONFIRMED_UNPLUGGED;
      }
      break;

     case swc_HVSM_IN_SUSPECT_UNPLUGGED:
      obcd_e_chargerSts = ChargerStatus_SUSPECT_UNPLUGGED;
      if (rtb_LogicalOperator3) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_CONFIRMED_PLUGGED;
        obcd_e_chargerSts = ChargerStatus_CONFIRMED_PLUGGED;
      } else if (swc_HVSM_ARID_DEF.DataTypeConversion17) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_CONFIRMED_UNPLUGGED;
        obcd_e_chargerSts = ChargerStatus_CONFIRMED_UNPLUGGED;
      }
      break;

     default:
      /* case IN_UNKNOWN: */
      obcd_e_chargerSts = ChargerStatus_UNKNOWN;
      if (rtb_LogicalOperator3) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_CONFIRMED_PLUGGED;
        obcd_e_chargerSts = ChargerStatus_CONFIRMED_PLUGGED;
      } else if (swc_HVSM_ARID_DEF.DataTypeConversion17) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_CONFIRMED_UNPLUGGED;
        obcd_e_chargerSts = ChargerStatus_CONFIRMED_UNPLUGGED;
      } else if (swc_HVSM_ARID_DEF.DataTypeConversion16) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_SUSPECT_PLUGGED;
        obcd_e_chargerSts = ChargerStatus_SUSPECT_PLUGGED;
      } else if (rtb_flg_out) {
        swc_HVSM_ARID_DEF.is_c1_swc_HVSM = swc_HVSM_IN_SUSPECT_UNPLUGGED;
        obcd_e_chargerSts = ChargerStatus_SUSPECT_UNPLUGGED;
      }
      break;
    }
  }

  /* End of Chart: '<S6>/ChargerStatus' */

  /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
   *  Constant: '<S309>/Constant'
   */
  obcd_b_chargerPlugged = (obcd_e_chargerSts == ChargerStatus_CONFIRMED_PLUGGED);
}

/*
 * System initialize for atomic system:
 *    '<S61>/turnOFF_delay1'
 *    '<S61>/turnOFF_delay2'
 *    '<S64>/turnOFF_delay'
 *    '<S64>/turnOFF_delay1'
 *    '<S64>/turnOFF_delay2'
 */
static void swc_HVSM_turnOFF_delay1_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S135>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S61>/turnOFF_delay1'
 *    '<S61>/turnOFF_delay2'
 *    '<S64>/turnOFF_delay'
 *    '<S64>/turnOFF_delay1'
 *    '<S64>/turnOFF_delay2'
 */
static void swc_HVSM_turnOFF_delay1(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay1_swc_H_T
  *swc_HVSM__ARID_DEF_arg)
{
  float32 rtb_t_delay_off;

  /* Saturate: '<S135>/Saturation1' */
  if (rtu_t_delay_off > 1.6777216E+7F) {
    /* Saturate: '<S135>/Saturation1' */
    rtb_t_delay_off = 1.6777216E+7F;
  } else if (rtu_t_delay_off < 0.0F) {
    /* Saturate: '<S135>/Saturation1' */
    rtb_t_delay_off = 0.0F;
  } else {
    /* Saturate: '<S135>/Saturation1' */
    rtb_t_delay_off = rtu_t_delay_off;
  }

  /* End of Saturate: '<S135>/Saturation1' */

  /* Chart: '<S135>/timed_delay' incorporates:
   *  DataTypeConversion: '<S135>/Data Type Conversion'
   */
  if (swc_HVSM__ARID_DEF_arg->is_active_c9_hvb == 0U) {
    swc_HVSM__ARID_DEF_arg->is_active_c9_hvb = 1U;
    swc_HVSM__ARID_DEF_arg->is_c9_hvb = swc_HVSM_IN_OFF_m;
    *rty_flg_out = false;
  } else {
    switch (swc_HVSM__ARID_DEF_arg->is_c9_hvb) {
     case swc_HVSM_IN_OFF_m:
      if (rtu_flg_in) {
        swc_HVSM__ARID_DEF_arg->is_c9_hvb = swc_HVSM_IN_ON_j;
        *rty_flg_out = true;
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_HVSM_IN_OFF_WAIT_h:
      if (rtu_flg_in) {
        swc_HVSM__ARID_DEF_arg->is_c9_hvb = swc_HVSM_IN_ON_j;
        *rty_flg_out = true;
      } else if (swc_HVSM__ARID_DEF_arg->t_wait > rtb_t_delay_off - rtu_t_step)
      {
        swc_HVSM__ARID_DEF_arg->is_c9_hvb = swc_HVSM_IN_OFF_m;
        *rty_flg_out = false;
      } else {
        swc_HVSM__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtu_flg_in) {
        if (rtb_t_delay_off == 0.0F) {
          swc_HVSM__ARID_DEF_arg->is_c9_hvb = swc_HVSM_IN_OFF_m;
          *rty_flg_out = false;
        } else {
          swc_HVSM__ARID_DEF_arg->is_c9_hvb = swc_HVSM_IN_OFF_WAIT_h;
          swc_HVSM__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;
    }
  }

  /* End of Chart: '<S135>/timed_delay' */
}

/*
 * Output and update for action system:
 *    '<S151>/pos'
 *    '<S209>/pos'
 */
static void swc_HVSM_pos(float32 rtu_in_val, float32 *rty_same_val)
{
  /* SignalConversion generated from: '<S153>/in_val' */
  *rty_same_val = rtu_in_val;
}

/*
 * Output and update for action system:
 *    '<S151>/neg'
 *    '<S209>/neg'
 */
static void swc_HVSM_neg(float32 rtu_in_val, float32 *rty_neg_val)
{
  /* UnaryMinus: '<S152>/Unary Minus' */
  *rty_neg_val = -rtu_in_val;
}

/* Output and update for atomic system: '<S63>/SR_latch' */
static void swc_HVSM_SR_latch_n(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HVSM_f_T *swc_HVSM__ARID_DEF_arg)
{
  /* Logic: '<S164>/Logical Operator3' incorporates:
   *  Logic: '<S164>/Logical Operator'
   *  Logic: '<S164>/Logical Operator1'
   *  UnitDelay: '<S164>/Unit Delay'
   */
  hvbd_b_CampModeFb = ((swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set)
                       && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S164>/Unit Delay' */
  swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE = hvbd_b_CampModeFb;
}

/*
 * Output and update for atomic system:
 *    '<S64>/SR_latch1'
 *    '<S95>/SR_latch1'
 *    '<S95>/SR_latch2'
 */
static void swc_HVSM_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch1_swc_HVSM_T *swc_HVSM__ARID_DEF_arg)
{
  /* Logic: '<S176>/Logical Operator3' incorporates:
   *  Logic: '<S176>/Logical Operator'
   *  Logic: '<S176>/Logical Operator1'
   *  UnitDelay: '<S176>/Unit Delay'
   */
  *rty_flg_out = ((swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S176>/Unit Delay' */
  swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/*
 * System initialize for atomic system:
 *    '<S64>/turnON_delay1'
 *    '<S64>/turnON_delay2'
 */
static void swc_HVSM_turnON_delay1_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S180>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S64>/turnON_delay1'
 *    '<S64>/turnON_delay2'
 */
static void swc_HVSM_turnON_delay1(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay1_swc_HV_T
  *swc_HVSM__ARID_DEF_arg)
{
  float32 rtb_t_delay_on_i;

  /* Saturate: '<S180>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S180>/Saturation' */
    rtb_t_delay_on_i = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S180>/Saturation' */
    rtb_t_delay_on_i = 0.0F;
  } else {
    /* Saturate: '<S180>/Saturation' */
    rtb_t_delay_on_i = rtu_t_delay_on;
  }

  /* End of Saturate: '<S180>/Saturation' */

  /* Chart: '<S180>/timed_delay' incorporates:
   *  DataTypeConversion: '<S180>/Data Type Conversion'
   */
  if (swc_HVSM__ARID_DEF_arg->is_active_c5_hvb == 0U) {
    swc_HVSM__ARID_DEF_arg->is_active_c5_hvb = 1U;
    swc_HVSM__ARID_DEF_arg->is_c5_hvb = swc_HVSM_IN_OFF_n;
    *rty_flg_out = false;
  } else {
    switch (swc_HVSM__ARID_DEF_arg->is_c5_hvb) {
     case swc_HVSM_IN_OFF_n:
      if (rtu_flg_in) {
        if (rtb_t_delay_on_i == 0.0F) {
          swc_HVSM__ARID_DEF_arg->is_c5_hvb = swc_HVSM_IN_ON_o;
          *rty_flg_out = true;
        } else {
          swc_HVSM__ARID_DEF_arg->is_c5_hvb = swc_HVSM_IN_ON_WAIT_o;
          swc_HVSM__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_HVSM_IN_ON_o:
      if (!rtu_flg_in) {
        swc_HVSM__ARID_DEF_arg->is_c5_hvb = swc_HVSM_IN_OFF_n;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_HVSM__ARID_DEF_arg->is_c5_hvb = swc_HVSM_IN_OFF_n;
        *rty_flg_out = false;
      } else if (swc_HVSM__ARID_DEF_arg->t_wait > rtb_t_delay_on_i - rtu_t_step)
      {
        swc_HVSM__ARID_DEF_arg->is_c5_hvb = swc_HVSM_IN_ON_o;
        *rty_flg_out = true;
      } else {
        swc_HVSM__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S180>/timed_delay' */
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVS_enter_internal_POWER_ON(void)
{
  boolean tmp;

  /*   */
  tmp = !Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd();
  if (swc_HVSM_ARID_DEF.DataTypeConversion24 &&
      (!swc_HVSM_ARID_DEF.DataTypeConversion16) && tmp) {
    swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_STANDBY_DRV;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_allowChg = ((boolean)OFF);
    swc_HVSM_ARID_DEF.BMSCtrlSts = 4U;
    swc_HVSM_ARID_DEF.IntelChgCmplt = false;

    /* DataTypeConversion: '<Root>/Data Type Conversion47' */
    if (swc_HVSM_ARID_DEF.DataTypeConversion47 != HVBRelayStatus_CLOSED) {
      hvbd_e_PmmStatus = PmmStatus_STANDBYDRVCONV;
    } else {
      hvbd_e_PmmStatus = PmmStatus_STANDBYDRV;
    }

    /* End of DataTypeConversion: '<Root>/Data Type Conversion47' */
  } else if (swc_HVSM_ARID_DEF.DataTypeConversion16 && tmp && hvbd_b_chargeReq)
  {
    swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_CHARGING;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_CHARGE;
    hvbd_e_modeTgt = HVBattStatus_CHARGING;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 10U;
    hvbd_b_allowChg = ((boolean)ON);
    swc_HVSM_ARID_DEF.IntelChgCmplt = false;
  } else {
    swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_INTELLIGENT_CHARGE;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_INTELCHG;
    swc_HVSM_ARID_DEF.IntelChgActive = true;
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_WAKEUP(void)
{
  sint32 tmp;
  boolean tmp_0;
  boolean tmp_1;
  boolean tmp_2;
  tmp = Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_st_hvilOpenSt();
  tmp_0 = !swc_HVSM_ARID_DEF.DataTypeConversion16;
  tmp_1 = !Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd();
  tmp_2 = !swc_HVSM_ARID_DEF.DataTypeConversion24;
  if ((tmp_2 && tmp_0 && tmp_1) || hvbd_b_emgyShutDn || hvbd_b_fltShutDn ||
      hvbd_b_crashShutDn || (tmp == 1)) {
    if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
        (!swc_HVSM_ARID_DEF.DataTypeConversion16)) {
      swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_H_IN_LV_SYS_CUT_OFF_REQUEST;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_LVCUTREQUEST;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      hvbd_b_lvCutOffReq = ((boolean)ON);
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_SHUTDOWN;
    } else {
      swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_LV_SYS_CUT_OFF_WAIT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_LVCUTWAIT;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
    }
  } else {
    boolean guard1 = false;
    guard1 = false;
    switch (swc_HVSM_ARID_DEF.is_WAKEUP) {
     case swc_HVSM_IN_CHG_WAIT:
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      if (hvbd_b_chargeReq && (tmp == 0)) {
        swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_CLOSE;
        swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_CHG_BMS_RELAY_CLOSE;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_CHGBMSNEGCLOSE;
        hvbd_e_modeTgt = HVBattStatus_STANDBY;
        hvbd_st_hvbMaiRlyNegClsReq = 1U;
        hvbd_st_hcmMaiRlyNegClsReq = 1U;
        hvbd_st_hvbAssiRlyPosClsReq = 1U;
        hvbd_st_hvbMaiRlyPosClsReq = 1U;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_PRECHARGE;
        swc_HVSM_ARID_DEF.BMSCtrlSts = 10U;
      } else if (tmp_0 && (swc_HVSM_ARID_DEF.DataTypeConversion24 ||
                           (swc_HVSM_ARID_DEF.DataTypeConversion210 != 0.0))) {
        swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_MCU_WAKEUP;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_MCUWAKEUP;
        hvbd_e_modeTgt = HVBattStatus_STANDBY;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
      } else {
        /* Constant: '<S5>/Constant13' */
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 200ms */
      }
      break;

     case swc_HVSM_IN_HCM_WAKEUP:
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
      if (hvbd_b_LvSysSlfChkOk && (!swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly)) {
        if (swc_HVSM_ARID_DEF.DataTypeConversion16) {
          swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_CHG_WAIT;
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
          hvbd_e_PmmStatus = PmmStatus_CHGWAIT;
          hvbd_e_modeTgt = HVBattStatus_STANDBY;
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
        } else if (swc_HVSM_ARID_DEF.DataTypeConversion24 ||
                   (swc_HVSM_ARID_DEF.DataTypeConversion210 != 0.0)) {
          swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_MCU_WAKEUP;
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
          hvbd_e_PmmStatus = PmmStatus_MCUWAKEUP;
          hvbd_e_modeTgt = HVBattStatus_STANDBY;
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     default:
      /* case IN_MCU_WAKEUP: */
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
      if (swc_HVSM_ARID_DEF.DataTypeConversion43 && (tmp == 0)) {
        if ((swc_HVSM_ARID_DEF.DataTypeConversion210 != 0.0) && tmp_1 && tmp_2)
        {
          swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
          swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_OPEN;
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
          hvbd_e_PmmStatus = PmmStatus_BMSNEGOPEN;
          hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
          hvbd_st_hvbMaiRlyNegClsReq = 2U;
          hvbd_st_hcmMaiRlyNegClsReq = 2U;
          hvbd_st_hvbAssiRlyPosClsReq = 2U;
          hvbd_st_hvbMaiRlyPosClsReq = 2U;
          swc_HVSM_ARID_DEF.BMSCtrlSts = 11U;
        } else {
          swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
          swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_CLOSE;
          swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_DRV_BMS_RELAY_CLOSE;
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
          hvbd_e_PmmStatus = PmmStatus_DRVBMSNEGCLOSE;
          hvbd_e_modeTgt = HVBattStatus_STANDBY;
          hvbd_st_hvbMaiRlyNegClsReq = 1U;
          hvbd_st_hcmMaiRlyNegClsReq = 1U;
          hvbd_st_hvbAssiRlyPosClsReq = 1U;
          hvbd_st_hvbMaiRlyPosClsReq = 1U;
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_PRECHARGE;
          swc_HVSM_ARID_DEF.BMSCtrlSts = 4U;
        }
      } else if ((((uint8)VEH_SWT_INF) == 4) &&
                 swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
        if (((uint8)VEH_SWT_INF) == 4) {
          swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
          swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
          swc_HVS_enter_internal_POWER_ON();
        } else {
          swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
          swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_TIMEOUT;
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
          hvbd_e_PmmStatus = PmmStatus_TIMEOUT;
          swc_HVSM_ARID_DEF.TmOutSts = true;
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
        }
      } else {
        /* Constant: '<S5>/Constant13' */
        /* HW_MCU_PwrRly = ON; */
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 200ms */
      }
      break;
    }

    if (guard1) {
      if ((((uint8)VEH_SWT_INF) == 4) && swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
        if (((uint8)VEH_SWT_INF) == 4) {
          swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
          swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
          swc_HVS_enter_internal_POWER_ON();
        } else {
          swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_NO_ACTIVE_CHILD;
          swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_TIMEOUT;
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
          hvbd_e_PmmStatus = PmmStatus_TIMEOUT;
          swc_HVSM_ARID_DEF.TmOutSts = true;
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
        }
      } else {
        /* Constant: '<S5>/Constant13' */
        /* HW_HCM_PwrRly = ON;
           HW_THM_PwrRly = ON;
           Wake up HCM and THM */
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 2000ms */
      }
    }
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_enter_atomic_OFF(void)
{
  swc_HVSM_ARID_DEF.TimeInState = 0.0F;
  hvbd_e_PmmStatus = PmmStatus_OFF;
  hvbd_e_modeTgt = HVBattStatus_STANDBY;

  /* HW_HCM_PwrRly = OFF;
     HW_MCU_PwrRly = OFF;
     HW_THM_PwrRly = OFF;
     VCU_CutOffLV = OFF;
     VcuSleep = OFF; */
  hvbd_st_ptRdyInd = 0U;
  hvbd_st_hvbMaiRlyNegClsReq = 2U;
  hvbd_st_hcmMaiRlyNegClsReq = 2U;
  hvbd_st_hvbAssiRlyPosClsReq = 2U;
  hvbd_st_hvbMaiRlyPosClsReq = 2U;
  swc_HVSM_ARID_DEF.IntelChgCmplt = false;
  swc_HVSM_ARID_DEF.IntelChgActive = false;

  /* McuDisChgCmd = OFF;
     Everything else OFF */
  swc_HVSM_ARID_DEF.canNmWaitSlpDebTime = 0.0F;
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_AFTER_RUN(void)
{
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
  if (((!swc_HVSM_ARID_DEF.DataTypeConversion71) ||
       swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) &&
      (!swc_HVSM_ARID_DEF.DataTypeConversion16) && (!swc_HVSM_ARID_DEF.Compare_m)
      && (!swc_HVSM_ARID_DEF.DataTypeConversion24)) {
    hvbd_b_vcuWkUpCmdRaw = ((boolean)OFF);
    mBSW_CanSwtOff();
    mBSW_LinSwtOff();
    Sws_EcuCtrl_SetShutDownType(1U);
    swc_HVSM_ARID_DEF.IntelChgExitReq = (swc_HVSM_ARID_DEF.IntelChgActive ||
      swc_HVSM_ARID_DEF.IntelChgExitReq);
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_OFF_d;
    swc_HVSM_enter_atomic_OFF();
    swc_HVSM_ARID_DEF.is_OFF = swc_HVSM_IN_BmsDelayOff;
  } else if ((swc_HVSM_ARID_DEF.DataTypeConversion24 ||
              swc_HVSM_ARID_DEF.DataTypeConversion16) && (!hvbd_b_emgyShutDn) &&
             (!hvbd_b_crashShutDn) &&
             (Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_st_hvilOpenSt() == 0)) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_WAKEUP;
    swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_HCM_WAKEUP;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HCMWAKEUP;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_lvCutOffReq = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
    swc_HVSM_ARID_DEF.TmOutSts = false;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 2U;
  } else {
    /* Constant: '<S5>/Constant13' */
    /* HW_HCM_PwrRly = OFF;
       HW_MCU_PwrRly = OFF; */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 60s */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_BMS_RELAY_CLOSE(void)
{
  if (((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
       (!swc_HVSM_ARID_DEF.DataTypeConversion16) &&
       (!Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd())) ||
      hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_NO_ACTIVE_CHILD;
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_OPEN;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_BMSNEGOPEN;
    hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
    hvbd_st_hvbMaiRlyNegClsReq = 2U;
    hvbd_st_hcmMaiRlyNegClsReq = 2U;
    hvbd_st_hvbAssiRlyPosClsReq = 2U;
    hvbd_st_hvbMaiRlyPosClsReq = 2U;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 11U;
  } else if (swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE ==
             swc_HVSM_IN_CHG_BMS_RELAY_CLOSE) {
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_st_hvbMaiRlyNegClsReq = 1U;
    hvbd_st_hcmMaiRlyNegClsReq = 1U;
    hvbd_st_hvbAssiRlyPosClsReq = 1U;
    hvbd_st_hvbMaiRlyPosClsReq = 1U;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_PRECHARGE;
    if (hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
      swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_CHARGEND;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_CHARGE;
      hvbd_e_modeTgt = HVBattStatus_CHARGING;
      swc_HVSM_ARID_DEF.BMSCtrlSts = 4U;
      hvbd_b_allowChg = ((boolean)OFF);
    } else if (!swc_HVSM_ARID_DEF.DataTypeConversion16) {
      if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
          (!swc_HVSM_ARID_DEF.DataTypeConversion16)) {
        swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_H_IN_LV_SYS_CUT_OFF_REQUEST;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_LVCUTREQUEST;
        hvbd_e_modeTgt = HVBattStatus_STANDBY;
        hvbd_b_lvCutOffReq = ((boolean)ON);
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_SHUTDOWN;
      } else {
        swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_LV_SYS_CUT_OFF_WAIT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_LVCUTWAIT;
        hvbd_e_modeTgt = HVBattStatus_STANDBY;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
      }
    } else if (swchvsm_hvbd_st_hvbRlyClsd) {
      swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_CHARGE_WAIT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    } else {
      /* Constant: '<S5>/Constant13' */
      swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

      /* Wait until BMS close main neg rly */
    }
  } else {
    /* case IN_DRV_BMS_RELAY_CLOSE: */
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_st_hvbMaiRlyNegClsReq = 1U;
    hvbd_st_hcmMaiRlyNegClsReq = 1U;
    hvbd_st_hvbAssiRlyPosClsReq = 1U;
    hvbd_st_hvbMaiRlyPosClsReq = 1U;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_PRECHARGE;

    /* Constant: '<S5>/Constant2' */
    if (false || swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
      swc_HVSM_ARID_DEF.BMSCtrlSts = 2U;
      if (((uint8)VEH_SWT_INF) == 4) {
        swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
        swc_HVS_enter_internal_POWER_ON();
      } else {
        swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_TIMEOUT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_TIMEOUT;
        swc_HVSM_ARID_DEF.TmOutSts = true;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      }
    } else if (swchvsm_hvbd_st_hvbRlyClsd || swc_HVSM_ARID_DEF.Compare) {
      swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_PowerON_WAIT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_DCDCACT;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    } else if (hvbd_b_chargeReq) {
      swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_CHG_BMS_RELAY_CLOSE;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_CHGBMSNEGCLOSE;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      hvbd_st_hvbMaiRlyNegClsReq = 1U;
      hvbd_st_hcmMaiRlyNegClsReq = 1U;
      hvbd_st_hvbAssiRlyPosClsReq = 1U;
      hvbd_st_hvbMaiRlyPosClsReq = 1U;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_PRECHARGE;
      swc_HVSM_ARID_DEF.BMSCtrlSts = 10U;
    } else {
      /* Constant: '<S5>/Constant13' */
      swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

      /* Time-out after 1500ms */
    }

    /* End of Constant: '<S5>/Constant2' */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_BMS_RELAY_OPEN(void)
{
  hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
  hvbd_st_hvbMaiRlyNegClsReq = 2U;
  hvbd_st_hcmMaiRlyNegClsReq = 2U;
  hvbd_st_hvbAssiRlyPosClsReq = 2U;
  hvbd_st_hvbMaiRlyPosClsReq = 2U;
  if (swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
    if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
        (!swc_HVSM_ARID_DEF.DataTypeConversion16)) {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_H_IN_LV_SYS_CUT_OFF_REQUEST;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_LVCUTREQUEST;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      hvbd_b_lvCutOffReq = ((boolean)ON);
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_SHUTDOWN;
    } else {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_LV_SYS_CUT_OFF_WAIT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_LVCUTWAIT;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
    }
  } else if ((swc_HVSM_ARID_DEF.DataTypeConversion47 == HVBRelayStatus_OPEN) &&
             (swc_HVSM_ARID_DEF.DataTypeConversion76 == HVBRelayStatus_OPEN) &&
             (swc_HVSM_ARID_DEF.TimeInState >= hvbc_tm_BmsRlyOpnDly_s)) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_MCU_DISCHARGE;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_MCUDISCHARGE;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_ACTIVE_DISCHARGE;
  } else {
    /* Constant: '<S5>/Constant13' */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 500ms */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_BMS_RELAY_OPEN_EMGY(void)
{
  hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
  hvbd_st_hvbMaiRlyNegClsReq = 3U;
  hvbd_st_hcmMaiRlyNegClsReq = 3U;
  hvbd_st_hvbAssiRlyPosClsReq = 3U;
  hvbd_st_hvbMaiRlyPosClsReq = 3U;
  if (swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
    if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
        (!swc_HVSM_ARID_DEF.DataTypeConversion16)) {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_H_IN_LV_SYS_CUT_OFF_REQUEST;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_LVCUTREQUEST;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      hvbd_b_lvCutOffReq = ((boolean)ON);
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_SHUTDOWN;
    } else {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_LV_SYS_CUT_OFF_WAIT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_LVCUTWAIT;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
    }
  } else if ((swc_HVSM_ARID_DEF.DataTypeConversion47 == HVBRelayStatus_OPEN) &&
             (swc_HVSM_ARID_DEF.DataTypeConversion76 == HVBRelayStatus_OPEN) &&
             (swc_HVSM_ARID_DEF.TimeInState >= hvbc_tm_BmsRlyOpnDly_s)) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_MCU_DISCHARGE;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_MCUDISCHARGE;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_ACTIVE_DISCHARGE;
  } else {
    /* Constant: '<S5>/Constant13' */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 500ms */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_CHARGE_WAIT(void)
{
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  if (swchvsm_hvbd_b_hvbChging) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_DCDC_ACT;
    swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_DCDC_ACT_CHG;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_DCDCACT;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  } else if ((!swc_HVSM_ARID_DEF.DataTypeConversion16) || hvbd_b_emgyShutDn ||
             hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_CHARGEND;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_CHARGE;
    hvbd_e_modeTgt = HVBattStatus_CHARGING;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 4U;
    hvbd_b_allowChg = ((boolean)OFF);
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_DCDC_ACT(void)
{
  if (((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
       (!swc_HVSM_ARID_DEF.DataTypeConversion16) &&
       (!Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd())) ||
      hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_NO_ACTIVE_CHILD;
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_HV_DEVICE_DEACT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HVDEVICEDEACT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_b_allowChg = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  } else if ((swc_HVSM_ARID_DEF.DataTypeConversion54 == McuSts_READY) ||
             ((((uint8)VEH_SWT_INF) == 4) &&
              swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly)) {
    swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_NO_ACTIVE_CHILD;
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    swc_HVS_enter_internal_POWER_ON();
  } else if (swc_HVSM_ARID_DEF.is_DCDC_ACT == swc_HVSM_IN_DCDC_ACT_CHG) {
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    if (swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
      swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_CHARGEND;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_CHARGE;
      hvbd_e_modeTgt = HVBattStatus_CHARGING;
      swc_HVSM_ARID_DEF.BMSCtrlSts = 4U;
      hvbd_b_allowChg = ((boolean)OFF);
    } else if (!swchvsm_hvbd_b_hvbChging) {
      swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_CHARGE_WAIT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    } else {
      /* Constant: '<S5>/Constant13' */
      swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);
    }
  } else {
    /* case IN_DCDC_ACT_DRV: */
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    if (swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
      if (((uint8)VEH_SWT_INF) == 4) {
        swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
        swc_HVS_enter_internal_POWER_ON();
      } else {
        swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_TIMEOUT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_TIMEOUT;
        swc_HVSM_ARID_DEF.TmOutSts = true;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      }
    } else if (hvbd_b_chargeReq) {
      swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_CLOSE;
      swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_CHG_BMS_RELAY_CLOSE;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_CHGBMSNEGCLOSE;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      hvbd_st_hvbMaiRlyNegClsReq = 1U;
      hvbd_st_hcmMaiRlyNegClsReq = 1U;
      hvbd_st_hvbAssiRlyPosClsReq = 1U;
      hvbd_st_hvbMaiRlyPosClsReq = 1U;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_PRECHARGE;
      swc_HVSM_ARID_DEF.BMSCtrlSts = 10U;
    } else {
      /* Constant: '<S5>/Constant13' */
      swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);
    }
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_IMMO_CHECK(void)
{
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_chargeReq ||
      hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_st_ptRdyInd = 0U;
  } else if (true) {
    /* DataTypeConversion: '<Root>/Data Type Conversion47' */
    if ((((uint8)VEH_SWT_INF) == 4) && (swc_HVSM_ARID_DEF.DataTypeConversion47
         != HVBRelayStatus_CLOSED)) {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_VEHICLE_START;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_VEHSTART;
    } else {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SDCAC_ACT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_SDCACACT;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
    }

    /* End of DataTypeConversion: '<Root>/Data Type Conversion47' */
  } else {
    /* Constant: '<S5>/Constant13' */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 500ms */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_enter_atomic_INIT(void)
{
  swc_HVSM_ARID_DEF.TimeInState = 0.0F;
  hvbd_e_PmmStatus = PmmStatus_INIT;
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  hvbd_st_ptRdyInd = 0U;
  hvbd_st_hvbMaiRlyNegClsReq = 2U;
  hvbd_st_hcmMaiRlyNegClsReq = 2U;
  hvbd_st_hvbAssiRlyPosClsReq = 2U;
  hvbd_st_hvbMaiRlyPosClsReq = 2U;
  swc_HVSM_ARID_DEF.IntelChgExitReq = false;
  hvbd_b_lvCutOffReq = ((boolean)OFF);
  swc_HVSM_ARID_DEF.IntelChgCmplt = false;
  swc_HVSM_ARID_DEF.IntelChgActive = false;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;

  /* VCU Initial State */
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_INIT(void)
{
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  hvbd_st_hvbMaiRlyNegClsReq = 2U;
  hvbd_st_hcmMaiRlyNegClsReq = 2U;
  hvbd_st_hvbAssiRlyPosClsReq = 2U;
  hvbd_st_hvbMaiRlyPosClsReq = 2U;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
  if (swc_HVSM_ARID_DEF.DataTypeConversion16 ||
      swc_HVSM_ARID_DEF.DataTypeConversion24 || hvsm_hvbd_b_nmWkUp ||
      (swc_HVSM_ARID_DEF.DataTypeConversion210 != 0.0) ||
      swc_HVSM_ARID_DEF.Compare_m) {
    hvbd_b_vcuWkUpCmdRaw = ((boolean)ON);
    mBSW_CanSwtOn();
    mBSW_LinSwtOn();
    Sws_EcuCtrl_SetShutDownType(0U);
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_OFF_d;
    swc_HVSM_enter_atomic_OFF();
    swc_HVSM_ARID_DEF.is_OFF = swc_HVSM_IN_BmsDelayOff;
  } else {
    Sws_EcuCtrl_SetShutDownType(1U);
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_INIT;
    swc_HVSM_enter_atomic_INIT();
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_LV_SYS_CUT_OFF_REQUEST(void)
{
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_SHUTDOWN;
  if (hvbd_b_LvSysCutOffAlw || swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly || (((uint8)
        VEH_SWT_INF) == 4)) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_AFTER_RUN;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_AFTERRUN;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_lvCutOffReq = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
  } else if ((swc_HVSM_ARID_DEF.DataTypeConversion24 ||
              swc_HVSM_ARID_DEF.DataTypeConversion16) && (!hvbd_b_emgyShutDn) &&
             (!hvbd_b_fltShutDn) && (!hvbd_b_crashShutDn) &&
             (Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_st_hvilOpenSt() == 0)) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_WAKEUP;
    swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_HCM_WAKEUP;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HCMWAKEUP;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_lvCutOffReq = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
    swc_HVSM_ARID_DEF.TmOutSts = false;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 2U;
  } else {
    /* Constant: '<S5>/Constant13' */
    /* VCU_EMWorkMode = Ready_to_cut_off; */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 10s */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_LV_SYS_CUT_OFF_WAIT(void)
{
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
  if ((swc_HVSM_ARID_DEF.DataTypeConversion24 ||
       swc_HVSM_ARID_DEF.DataTypeConversion16) && (!hvbd_b_emgyShutDn) &&
      (!hvbd_b_fltShutDn) && (!hvbd_b_crashShutDn) &&
      (Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_st_hvilOpenSt() == 0)) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_WAKEUP;
    swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_HCM_WAKEUP;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HCMWAKEUP;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_lvCutOffReq = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
    swc_HVSM_ARID_DEF.TmOutSts = false;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 2U;
  } else if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
             (!swc_HVSM_ARID_DEF.DataTypeConversion16)) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_H_IN_LV_SYS_CUT_OFF_REQUEST;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_LVCUTREQUEST;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_lvCutOffReq = ((boolean)ON);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_SHUTDOWN;
  } else {
    /* Wait for Key OFF
       TimeInState = TimeInState + dT;
       Time-out after 200ms */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_MCU_ACT(void)
{
  hvbd_e_modeTgt = HVBattStatus_ACTIVE;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_TORQUE_CTRL;

  /* DataTypeConversion: '<Root>/Data Type Conversion49' incorporates:
   *  Constant: '<S5>/Constant13'
   */
  if ((swc_HVSM_ARID_DEF.DataTypeConversion49 == McuSts_READY) || ((((uint8)
         VEH_SWT_INF) == 4) && swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly)) {
    if (((uint8)VEH_SWT_INF) != 4) {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_DRIVE;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_DRIVE;
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      hvbd_st_ptRdyInd = 1U;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_TORQUE_CTRL;
    } else {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_VEHICLE_START;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_VEHSTART;
    }
  } else if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_chargeReq ||
             hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_st_ptRdyInd = 0U;
  } else if (swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_TIMEOUT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_TIMEOUT;
    swc_HVSM_ARID_DEF.TmOutSts = true;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  } else {
    /* VCU_MCUEnableReq = ON; */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 200ms */
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion49' */
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_MCU_DEACT(void)
{
  hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  if (hvbd_b_emgyShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_HV_SHUT_DN_EMGY;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HVSHUTDNEMGY;
    hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  } else if ((hvbd_b_hvShutDnCmplt && true) ||
             swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
    if ((swc_HVSM_ARID_DEF.DataTypeConversion24 || hvbd_b_chargeReq) &&
        (!hvbd_b_emgyShutDn) && (!hvbd_b_fltShutDn) && (!hvbd_b_crashShutDn) &&
        (!swc_HVSM_ARID_DEF.TmOutSts)) {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_DCDC_ACT;
      swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_DCDC_ACT_DRV;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_DCDCACT;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    } else {
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_OPEN;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_BMSNEGOPEN;
      hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
      hvbd_st_hvbMaiRlyNegClsReq = 2U;
      hvbd_st_hcmMaiRlyNegClsReq = 2U;
      hvbd_st_hvbAssiRlyPosClsReq = 2U;
      hvbd_st_hvbMaiRlyPosClsReq = 2U;
      swc_HVSM_ARID_DEF.BMSCtrlSts = 11U;
    }
  } else {
    /* Constant: '<S5>/Constant13' */
    /* VCU_MCUEnableReq = OFF; */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 1500ms */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_OFF(void)
{
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  hvbd_st_hvbMaiRlyNegClsReq = 2U;
  hvbd_st_hcmMaiRlyNegClsReq = 2U;
  hvbd_st_hvbAssiRlyPosClsReq = 2U;
  hvbd_st_hvbMaiRlyPosClsReq = 2U;

  /* Constant: '<S62>/Constant6' */
  if (swc_HVSM_ARID_DEF.DataTypeConversion86 &&
      (swc_HVSM_ARID_DEF.DataTypeConversion24 ||
       swc_HVSM_ARID_DEF.DataTypeConversion16 ||
       (swc_HVSM_ARID_DEF.DataTypeConversion210 != 0.0)) && (!hvbd_b_emgyShutDn)
      && hvbc_b_prepCmpl_ovrdval) {
    hvbd_b_lvCutOffReq = ((boolean)OFF);
    hvbd_b_vcuWkUpCmdRaw = ((boolean)ON);
    mBSW_CanSwtOn();
    mBSW_LinSwtOn();
    Sws_EcuCtrl_SetShutDownType(0U);
    swc_HVSM_ARID_DEF.is_OFF = swc_HVSM_IN_NO_ACTIVE_CHILD;
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_WAKEUP;
    swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_HCM_WAKEUP;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HCMWAKEUP;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_lvCutOffReq = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
    swc_HVSM_ARID_DEF.TmOutSts = false;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 2U;
  } else {
    boolean guard1 = false;
    boolean tmp;
    boolean tmp_0;
    tmp = ((!swc_HVSM_ARID_DEF.DataTypeConversion16) &&
           (!swc_HVSM_ARID_DEF.DataTypeConversion24));
    tmp_0 = !swc_HVSM_ARID_DEF.Compare_m;

    /* Constant: '<S5>/Constant8' */
    guard1 = false;
    if (tmp && (swc_HVSM_ARID_DEF.DataTypeConversion210 == 0.0) && tmp_0 &&
        (swc_HVSM_ARID_DEF.canNmWaitSlpDebTime >= hvbc_tm_canNmWaitSlpThd_s) &&
        swc_HVSM_ARID_DEF.RelationalOperator4) {
      hvbd_b_vcuWkUpCmdRaw = ((boolean)OFF);
      mBSW_CanSwtOff();
      mBSW_LinSwtOff();
      Sws_EcuCtrl_SetShutDownType(1U);
      guard1 = true;
    } else if (tmp && (swc_HVSM_ARID_DEF.DataTypeConversion210 == 0.0) && tmp_0 &&
               (swc_HVSM_ARID_DEF.canNmWaitSlpDebTime >=
                hvbc_tm_canNmWaitSlpThd_s) &&
               (!swc_HVSM_ARID_DEF.RelationalOperator4)) {
      hvbd_b_vcuWkUpCmdRaw = ((boolean)OFF);
      mBSW_CanSwtOff();
      mBSW_LinSwtOff();
      guard1 = true;
    } else {
      /* Constant: '<S5>/Constant13' */
      swc_HVSM_ARID_DEF.canNmWaitSlpDebTime += ((float32)HVB_TASK_INTERVAL_S);
      if ((swc_HVSM_ARID_DEF.is_OFF == swc_HVSM_IN_BmsDelayOff) &&
          swc_HVSM_ARID_DEF.Compare_m) {
        swc_HVSM_ARID_DEF.is_OFF = swc_HVSM_IN_BmsDelayOn;
        hvbd_b_vcuWkUpCmdRaw = ((boolean)ON);
        mBSW_CanSwtOn();
        mBSW_LinSwtOn();
      } else {
        /* case IN_BmsDelayOn: */
      }
    }

    if (guard1) {
      swc_HVSM_ARID_DEF.is_OFF = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SLEEP_WAIT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;

      /* canNmWaitSlpDebTime=0;
         du:
         canNmWaitSlpDebTime+=dT; */
    }

    /* End of Constant: '<S5>/Constant8' */
  }

  /* End of Constant: '<S62>/Constant6' */
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_POWER_ON(void)
{
  boolean guard1 = false;
  boolean guard2 = false;
  boolean guard3 = false;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  switch (swc_HVSM_ARID_DEF.is_POWER_ON) {
   case swc_HVSM_IN_CHARGEND:
    hvbd_e_modeTgt = HVBattStatus_CHARGING;
    hvbd_b_allowChg = ((boolean)OFF);
    if (((!swc_HVSM_ARID_DEF.DataTypeConversion16) &&
         (!swc_HVSM_ARID_DEF.DataTypeConversion24)) || hvbd_b_emgyShutDn ||
        hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
      swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_HV_DEVICE_DEACT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_HVDEVICEDEACT;
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    } else if ((!swc_HVSM_ARID_DEF.flg_out_e) &&
               swc_HVSM_ARID_DEF.DataTypeConversion24 &&
               (swc_HVSM_ARID_DEF.RelationalOperator1_b ||
                swchvsm_hvbd_b_hvbChging)) {
      if ((swc_HVSM_ARID_DEF.DataTypeConversion24 || hvbd_b_chargeReq) &&
          (!hvbd_b_emgyShutDn) && (!hvbd_b_fltShutDn) && (!hvbd_b_crashShutDn) &&
          (!swc_HVSM_ARID_DEF.TmOutSts)) {
        swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_DCDC_ACT;
        swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_DCDC_ACT_DRV;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_DCDCACT;
        hvbd_e_modeTgt = HVBattStatus_STANDBY;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      } else {
        swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_NO_ACTIVE_CHILD;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_OPEN;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_BMSNEGOPEN;
        hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
        hvbd_st_hvbMaiRlyNegClsReq = 2U;
        hvbd_st_hcmMaiRlyNegClsReq = 2U;
        hvbd_st_hvbAssiRlyPosClsReq = 2U;
        hvbd_st_hvbMaiRlyPosClsReq = 2U;
        swc_HVSM_ARID_DEF.BMSCtrlSts = 11U;
      }
    }
    break;

   case swc_HVSM_IN_CHARGING:
    hvbd_e_modeTgt = HVBattStatus_CHARGING;
    hvbd_b_allowChg = ((boolean)ON);
    if ((!hvbd_b_chargeReq) || swc_HVSM_ARID_DEF.flg_out || hvbd_b_emgyShutDn ||
        (hvbd_b_fltShutDn && (!swc_HVSM_ARID_DEF.LogicalOperator36)) ||
        hvbd_b_crashShutDn) {
      swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_CHARGEND;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_CHARGE;
      hvbd_e_modeTgt = HVBattStatus_CHARGING;
      swc_HVSM_ARID_DEF.BMSCtrlSts = 4U;
      hvbd_b_allowChg = ((boolean)OFF);
    }
    break;

   case swc_HVSM_IN_INTELLIGENT_CHARGE:
    {
      if (swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
        boolean tmp;
        boolean tmp_0;
        boolean tmp_1;
        boolean tmp_2;
        swc_HVSM_ARID_DEF.IntelChgCmplt = true;
        tmp = !hvbd_b_crashShutDn;
        tmp_0 = !Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd();
        tmp_1 = !hvbd_b_emgyShutDn;
        tmp_2 = !hvbd_b_fltShutDn;
        if (tmp_0 && hvbd_b_chargeReq && tmp_1 && tmp_2 && tmp) {
          guard1 = true;
        } else if (tmp_0 && swc_HVSM_ARID_DEF.DataTypeConversion24 && tmp_1 &&
                   tmp_2 && tmp) {
          guard2 = true;
        } else {
          guard3 = true;
        }
      } else {
        boolean tmp;
        boolean tmp_0;
        boolean tmp_1;
        boolean tmp_2;
        tmp = !Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd();
        tmp_0 = !hvbd_b_emgyShutDn;
        tmp_1 = !hvbd_b_fltShutDn;
        tmp_2 = !hvbd_b_crashShutDn;
        if (tmp && swc_HVSM_ARID_DEF.DataTypeConversion24 && tmp_0 && tmp_1 &&
            tmp_2) {
          guard2 = true;
        } else if (tmp && hvbd_b_chargeReq && tmp_0 && tmp_1 && tmp_2) {
          guard1 = true;
        } else if (tmp || hvbd_b_emgyShutDn || hvbd_b_fltShutDn ||
                   hvbd_b_crashShutDn) {
          guard3 = true;
        } else {
          /* Constant: '<S5>/Constant13' */
          swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

          /* Time-out after 2 hours */
        }
      }
    }
    break;

   default:
    /* case IN_STANDBY_DRV: */
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_allowChg = ((boolean)OFF);
    if (hvbd_b_chargeReq) {
      swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_CHARGING;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_CHARGE;
      hvbd_e_modeTgt = HVBattStatus_CHARGING;
      swc_HVSM_ARID_DEF.BMSCtrlSts = 10U;
      hvbd_b_allowChg = ((boolean)ON);
      swc_HVSM_ARID_DEF.IntelChgCmplt = false;
    } else if (hvbd_b_startReq && swc_HVSM_ARID_DEF.RelationalOperator8 &&
               (!hvbd_b_chgCablePlugged)) {
      swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_IMMO_CHECK;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_IMMOCHECK;
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
    } else if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_chargeReq ||
               hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
      swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_NO_ACTIVE_CHILD;
      swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
      hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      hvbd_st_ptRdyInd = 0U;
    }
    break;
  }

  if (guard3) {
    swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_NO_ACTIVE_CHILD;
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_HV_DEVICE_DEACT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HVDEVICEDEACT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_b_allowChg = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  }

  if (guard2) {
    swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_STANDBY_DRV;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_allowChg = ((boolean)OFF);
    swc_HVSM_ARID_DEF.BMSCtrlSts = 4U;
    swc_HVSM_ARID_DEF.IntelChgCmplt = false;

    /* DataTypeConversion: '<Root>/Data Type Conversion47' */
    if (swc_HVSM_ARID_DEF.DataTypeConversion47 != HVBRelayStatus_CLOSED) {
      hvbd_e_PmmStatus = PmmStatus_STANDBYDRVCONV;
    } else {
      hvbd_e_PmmStatus = PmmStatus_STANDBYDRV;
    }

    /* End of DataTypeConversion: '<Root>/Data Type Conversion47' */
  }

  if (guard1) {
    swc_HVSM_ARID_DEF.is_POWER_ON = swc_HVSM_IN_CHARGING;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_CHARGE;
    hvbd_e_modeTgt = HVBattStatus_CHARGING;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 10U;
    hvbd_b_allowChg = ((boolean)ON);
    swc_HVSM_ARID_DEF.IntelChgCmplt = false;
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_PowerON_WAIT(void)
{
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  if (swc_HVSM_ARID_DEF.RelationalOperator1_b) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_DCDC_ACT;
    swc_HVSM_ARID_DEF.is_DCDC_ACT = swc_HVSM_IN_DCDC_ACT_DRV;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_DCDCACT;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  } else if (((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
              (!swc_HVSM_ARID_DEF.DataTypeConversion16) &&
              (!Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd())) ||
             hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_HV_DEVICE_DEACT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HVDEVICEDEACT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_b_allowChg = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  } else if (hvbd_b_chargeReq) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_CLOSE;
    swc_HVSM_ARID_DEF.is_BMS_RELAY_CLOSE = swc_HVSM_IN_CHG_BMS_RELAY_CLOSE;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_CHGBMSNEGCLOSE;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_st_hvbMaiRlyNegClsReq = 1U;
    hvbd_st_hcmMaiRlyNegClsReq = 1U;
    hvbd_st_hvbAssiRlyPosClsReq = 1U;
    hvbd_st_hvbMaiRlyPosClsReq = 1U;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_PRECHARGE;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 10U;
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_SDCAC_ACT(void)
{
  hvbd_e_modeTgt = HVBattStatus_STANDBY;
  if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_chargeReq ||
      hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_st_ptRdyInd = 0U;
  } else if ((swc_HVSM_ARID_DEF.DataTypeConversion50 == McuSts_READY) &&
             (((uint8)VEH_SWT_INF) == 2) &&
             swc_HVSM_ARID_DEF.DataTypeConversion127) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_LOW_TEMP_PROTN_ON;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_LOWTEMPON;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
  } else {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BDCAC_ACT;
    hvbd_e_PmmStatus = PmmStatus_BDCACACT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    if (!swc_HVSM_ARID_DEF.RelationalOperator6_j) {
      /* Constant: '<S5>/Constant13' */
      swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);
    } else {
      swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    }
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_SHUT_DOWN_WAIT(void)
{
  hvbd_e_modeTgt = HVBattStatus_ACTIVE;
  if (hvbd_b_emgyShutDn || hvbd_b_crashShutDn) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_UP_WAIT_EMGY;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAITEMGY;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_st_ptRdyInd = 0U;
  } else if (swc_HVSM_ARID_DEF.DataTypeConversion24 && (!hvbd_b_emgyShutDn) && (
              !hvbd_b_crashShutDn) && (!hvbd_b_fltShutDn) &&
             (!swc_HVSM_ARID_DEF.TmOutSts)) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
    swc_HVS_enter_internal_POWER_ON();
  } else if ((Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_PTDisabled() && (((uint8)
                VEH_SWT_INF) != 4)) || swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_HV_DEVICE_DEACT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HVDEVICEDEACT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_b_allowChg = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  } else {
    /* Constant: '<S5>/Constant13' */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 360s
       Ramp down torque, disable PFCU
       , put Gear lever to N */
  }
}

/* Function for Chart: '<S89>/LdtNewPlatform' */
static void swc_HVSM_TIMEOUT(void)
{
  swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
  if ((swc_HVSM_ARID_DEF.ObcWkUp_prev != swc_HVSM_ARID_DEF.ObcWkUp_start) &&
      swc_HVSM_ARID_DEF.ObcWkUp_start) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_WAKEUP;
    swc_HVSM_ARID_DEF.is_WAKEUP = swc_HVSM_IN_HCM_WAKEUP;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_HCMWAKEUP;
    hvbd_e_modeTgt = HVBattStatus_STANDBY;
    hvbd_b_lvCutOffReq = ((boolean)OFF);
    swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
    swc_HVSM_ARID_DEF.TmOutSts = false;
    swc_HVSM_ARID_DEF.BMSCtrlSts = 2U;
  } else if (((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
              (!swc_HVSM_ARID_DEF.DataTypeConversion16)) || hvbd_b_emgyShutDn ||
             hvbd_b_crashShutDn || hvbd_b_fltShutDn) {
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
    swc_HVSM_ARID_DEF.TimeInState = 0.0F;
    hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
    hvbd_e_modeTgt = HVBattStatus_ACTIVE;
    hvbd_st_ptRdyInd = 0U;
  } else {
    /* Constant: '<S5>/Constant13' */
    swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

    /* Time-out after 500s */
  }
}

/* Output and update for atomic system: '<S89>/LdtNewPlatform' */
static void swc_HVSM_LdtNewPlatform(void)
{
  swc_HVSM_ARID_DEF.ObcWkUp_prev = swc_HVSM_ARID_DEF.ObcWkUp_start;
  swc_HVSM_ARID_DEF.ObcWkUp_start = swc_HVSM_ARID_DEF.DataTypeConversion16;

  /* Chart: '<S89>/LdtNewPlatform' incorporates:
   *  Constant: '<S5>/Constant13'
   *  Constant: '<S5>/Constant16'
   *  DataTypeConversion: '<Root>/Data Type Conversion49'
   *  DataTypeConversion: '<Root>/Data Type Conversion50'
   *  DataTypeConversion: '<Root>/Data Type Conversion54'
   *  Inport generated from: '<Root>/In Bus Element167'
   */
  if (swc_HVSM_ARID_DEF.is_active_c31_hvb == 0U) {
    swc_HVSM_ARID_DEF.ObcWkUp_prev = swc_HVSM_ARID_DEF.DataTypeConversion16;
    swc_HVSM_ARID_DEF.is_active_c31_hvb = 1U;
    swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_INIT;
    swc_HVSM_enter_atomic_INIT();
  } else {
    switch (swc_HVSM_ARID_DEF.is_c31_hvb) {
     case swc_HVSM_IN_AFTER_RUN:
      swc_HVSM_AFTER_RUN();
      break;

     case swc_HVSM_IN_BDCAC_ACT:
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_chargeReq ||
          hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
        hvbd_st_ptRdyInd = 0U;
      } else {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_MCU_ACT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_MCUACT;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_TORQUE_CTRL;
      }
      break;

     case swc_HVSM_IN_BMS_RELAY_CLOSE:
      swc_HVSM_BMS_RELAY_CLOSE();
      break;

     case swc_HVSM_IN_BMS_RELAY_OPEN:
      swc_HVSM_BMS_RELAY_OPEN();
      break;

     case swc_HVSM_IN_BMS_RELAY_OPEN_EMGY:
      swc_HVSM_BMS_RELAY_OPEN_EMGY();
      break;

     case swc_HVSM_IN_CHARGE_WAIT:
      swc_HVSM_CHARGE_WAIT();
      break;

     case swc_HVSM_IN_DCDC_ACT:
      swc_HVSM_DCDC_ACT();
      break;

     case swc_HVSM_IN_DRIVE:
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_TORQUE_CTRL;
      if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_emgyShutDn ||
          hvbd_b_fltShutDn || hvbd_b_crashShutDn ||
          swc_HVSM_ARID_DEF.LogicalOperator36) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
        hvbd_st_ptRdyInd = 0U;
      } else if ((hvbd_b_chgCablePlugged || hvbd_b_CampModeFb) &&
                 swc_HVSM_ARID_DEF.RelationalOperator3_a) {
        hvbd_st_ptRdyInd = 0U;
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_POWER_ON;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
        swc_HVS_enter_internal_POWER_ON();
      }
      break;

     case swc_HVSM_IN_HV_DEVICE_DEACT:
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      hvbd_b_allowChg = ((boolean)OFF);
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      if (hvbd_b_emgyShutDn || hvbd_b_crashShutDn) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVS_IN_HV_DEVICE_DEACT_EMGY;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_HVDEVICEDEACTEMGY;
        hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      } else if (((swc_HVSM_ARID_DEF.DataTypeConversion49 == McuSts_NOTREADY) &&
                  (swc_HVSM_ARID_DEF.DataTypeConversion54 == McuSts_NOTREADY)) ||
                 swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_MCU_DEACT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_MCUDEACT;
        hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      } else {
        /* HW_SDCAC_PwrRly = OFF;
           VCU_SDCACEnableOut = OFF;
           BdcacPwrEnb = OFF;
           HW_DCDC_Enable = OFF;
           VCU_DCDCEnableOut = OFF; */
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 10s */
      }
      break;

     case swc_HVS_IN_HV_DEVICE_DEACT_EMGY:
      hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      if (((swc_HVSM_ARID_DEF.DataTypeConversion49 == McuSts_NOTREADY) &&
           (swc_HVSM_ARID_DEF.DataTypeConversion54 == McuSts_NOTREADY)) ||
          swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly || hvbd_b_crashShutDn) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_HV_SHUT_DN_EMGY;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_HVSHUTDNEMGY;
        hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      } else {
        /* VCU_MCUEnableReq = OFF;
           HW_DCDC_Enable = OFF;
           VCU_DCDCEnableOut = OFF; */
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 30s */
      }
      break;

     case swc_HVSM_IN_HV_SHUT_DN_EMGY:
      hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      if (hvbd_b_hvShutDnCmplt || swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly ||
          hvbd_b_crashShutDn) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BMS_RELAY_OPEN_EMGY;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_BMSNEGOPENEMGY;
        hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
        hvbd_st_hvbMaiRlyNegClsReq = 3U;
        hvbd_st_hcmMaiRlyNegClsReq = 3U;
        hvbd_st_hvbAssiRlyPosClsReq = 3U;
        hvbd_st_hvbMaiRlyPosClsReq = 3U;
        swc_HVSM_ARID_DEF.BMSCtrlSts = 11U;
      } else {
        /* VCU_MCUEnableReq = OFF;
           HW_DCDC_Enable = OFF;
           VCU_DCDCEnableOut = OFF; */
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 30s */
      }
      break;

     case swc_HVSM_IN_IMMO_CHECK:
      swc_HVSM_IMMO_CHECK();
      break;

     case swc_HVSM_IN_INIT:
      swc_HVSM_INIT();
      break;

     case swc_HVSM_IN_LOW_TEMP_PROTN_OFF:
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_chargeReq ||
          hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
        hvbd_st_ptRdyInd = 0U;
      } else if ((swc_HVSM_ARID_DEF.DataTypeConversion50 == McuSts_READY) &&
                 (((uint8)VEH_SWT_INF) == 2) &&
                 swc_HVSM_ARID_DEF.RelationalOperator6_j) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_BDCAC_ACT;
        hvbd_e_PmmStatus = PmmStatus_BDCACACT;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        if (!swc_HVSM_ARID_DEF.RelationalOperator6_j) {
          swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);
        } else {
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        }
      } else {
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 500s */
      }
      break;

     case swc_HVSM_IN_LOW_TEMP_PROTN_ON:
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_chargeReq ||
          hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
        hvbd_st_ptRdyInd = 0U;
      } else if ((swc_HVSM_ARID_DEF.DataTypeConversion50 == McuSts_READY) &&
                 (((uint8)VEH_SWT_INF) == 2) &&
                 (!swc_HVSM_ARID_DEF.DataTypeConversion127)) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_LOW_TEMP_PROTN_OFF;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_LOWTEMPOFF;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      } else {
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 500s */
      }
      break;

     case swc_H_IN_LV_SYS_CUT_OFF_REQUEST:
      swc_HVSM_LV_SYS_CUT_OFF_REQUEST();
      break;

     case swc_HVSM_IN_LV_SYS_CUT_OFF_WAIT:
      swc_HVSM_LV_SYS_CUT_OFF_WAIT();
      break;

     case swc_HVSM_IN_MCU_ACT:
      swc_HVSM_MCU_ACT();
      break;

     case swc_HVSM_IN_MCU_DEACT:
      swc_HVSM_MCU_DEACT();
      break;

     case swc_HVSM_IN_MCU_DISCHARGE:
      hvbd_e_modeTgt = HVBattStatus_STANDBY;
      swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_ACTIVE_DISCHARGE;
      if ((swc_HVSM_ARID_DEF.DataTypeConversion13 &&
           (swc_HVSM_ARID_DEF.TimeInState >= hvbc_tm_McuDisChgDly_s)) ||
          swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly) {
        if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) &&
            (!swc_HVSM_ARID_DEF.DataTypeConversion16)) {
          swc_HVSM_ARID_DEF.is_c31_hvb = swc_H_IN_LV_SYS_CUT_OFF_REQUEST;
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
          hvbd_e_PmmStatus = PmmStatus_LVCUTREQUEST;
          hvbd_e_modeTgt = HVBattStatus_STANDBY;
          hvbd_b_lvCutOffReq = ((boolean)ON);
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_SHUTDOWN;
        } else {
          swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_LV_SYS_CUT_OFF_WAIT;
          swc_HVSM_ARID_DEF.TimeInState = 0.0F;
          hvbd_e_PmmStatus = PmmStatus_LVCUTWAIT;
          hvbd_e_modeTgt = HVBattStatus_STANDBY;
          swc_HVSM_ARID_DEF.ElMacSts = ElMac_HV_OFF;
        }
      } else {
        /* McuDisChgCmd = ON; */
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 3s */
      }
      break;

     case swc_HVSM_IN_OFF_d:
      swc_HVSM_OFF();
      break;

     case swc_HVSM_IN_POWER_ON:
      swc_HVSM_POWER_ON();
      break;

     case swc_HVSM_IN_PowerON_WAIT:
      swc_HVSM_PowerON_WAIT();
      break;

     case swc_HVSM_IN_SDCAC_ACT:
      swc_HVSM_SDCAC_ACT();
      break;

     case swc_HVSM_IN_SHUT_DOWN_WAIT:
      swc_HVSM_SHUT_DOWN_WAIT();
      break;

     case swc_HVSM_IN_SHUT_UP_WAIT_EMGY:
      hvbd_e_modeTgt = HVBattStatus_ACTIVE;
      if ((Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_PTDisabled() && (((uint8)
             VEH_SWT_INF) != 4)) || swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly ||
          hvbd_b_FidVehFltLvl3HvOff || hvbd_b_crashShutDn) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVS_IN_HV_DEVICE_DEACT_EMGY;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_HVDEVICEDEACTEMGY;
        hvbd_e_modeTgt = HVBattStatus_SHUTDOWN;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_STANDBY;
      } else {
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 360s
           Ramp down torque, disable PFCU
           , put Gear lever to N */
      }
      break;

     case swc_HVSM_IN_SLEEP_WAIT:
      if (swc_HVSM_ARID_DEF.DataTypeConversion16 ||
          swc_HVSM_ARID_DEF.DataTypeConversion24 ||
          (swc_HVSM_ARID_DEF.DataTypeConversion210 != 0.0) ||
          swc_HVSM_ARID_DEF.Compare_m) {
        hvbd_b_vcuWkUpCmdRaw = ((boolean)ON);
        mBSW_CanSwtOn();
        mBSW_LinSwtOn();
        Sws_EcuCtrl_SetShutDownType(0U);
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_OFF_d;
        swc_HVSM_enter_atomic_OFF();
        swc_HVSM_ARID_DEF.is_OFF = swc_HVSM_IN_BmsDelayOff;
      } else if (hvsm_hvbd_b_nmRdySlp) {
        Sws_EcuCtrl_SetShutDownType(1U);
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_INIT;
        swc_HVSM_enter_atomic_INIT();
      }
      break;

     case swc_HVSM_IN_TIMEOUT:
      swc_HVSM_TIMEOUT();
      break;

     case swc_HVSM_IN_VEHICLE_START:
      if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || hvbd_b_chargeReq ||
          hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_SHUT_DOWN_WAIT;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_SHUTDOWNWAIT;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
        hvbd_st_ptRdyInd = 0U;
      } else if (swc_HVSM_ARID_DEF.Switch3 != 0.0) {
        swc_HVSM_ARID_DEF.is_c31_hvb = swc_HVSM_IN_DRIVE;
        swc_HVSM_ARID_DEF.TimeInState = 0.0F;
        hvbd_e_PmmStatus = PmmStatus_DRIVE;
        hvbd_e_modeTgt = HVBattStatus_ACTIVE;
        hvbd_st_ptRdyInd = 1U;
        swc_HVSM_ARID_DEF.ElMacSts = ElMac_TORQUE_CTRL;
      } else {
        swc_HVSM_ARID_DEF.TimeInState += ((float32)HVB_TASK_INTERVAL_S);

        /* Time-out after 30s */
      }
      break;

     default:
      /* case IN_WAKEUP: */
      swc_HVSM_WAKEUP();
      break;
    }
  }

  /* End of Chart: '<S89>/LdtNewPlatform' */
}

/* Output and update for atomic system: '<S96>/SR_latch1' */
static void swc_HVSM_SR_latch1_f(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HVSM_a_T *swc_HVSM__ARID_DEF_arg)
{
  /* Logic: '<S288>/Logical Operator3' incorporates:
   *  Logic: '<S288>/Logical Operator'
   *  Logic: '<S288>/Logical Operator1'
   *  UnitDelay: '<S288>/Unit Delay'
   */
  hvbd_b_acPtcEnb = ((swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) &&
                     (!rtu_flg_reset));

  /* Update for UnitDelay: '<S288>/Unit Delay' */
  swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE = hvbd_b_acPtcEnb;
}

/* Output and update for atomic system: '<S99>/SR_latch' */
static void swc_HVSM_SR_latch_i(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch_swc_HVSM_ad_T *swc_HVSM__ARID_DEF_arg)
{
  /* Logic: '<S301>/Logical Operator3' incorporates:
   *  Logic: '<S301>/Logical Operator'
   *  Logic: '<S301>/Logical Operator1'
   *  UnitDelay: '<S301>/Unit Delay'
   */
  hvbd_b_tmOutFlgCfm = ((swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set)
                        && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S301>/Unit Delay' */
  swc_HVSM__ARID_DEF_arg->UnitDelay_DSTATE = hvbd_b_tmOutFlgCfm;
}

/* Output and update for atomic system: '<S5>/TimeOutManagement' */
static void swc_HVSM_TimeOutManagement(void)
{
  /* local block i/o variables */
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator2;
  float32 rtb_MultiportSwitch;

  /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
   *  DataTypeConversion: '<S99>/Data Type Conversion'
   */
  switch (hvbd_e_PmmStatus) {
   case 0:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 1:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant1'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmWkUp_s;
    break;

   case 2:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant2'
     */
    rtb_MultiportSwitch = hvbc_tm_McuWkUp_s;
    break;

   case 3:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant3'
     */
    rtb_MultiportSwitch = hvbc_tm_BmsNegClsDrv_s;
    break;

   case 4:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant31'
     */
    rtb_MultiportSwitch = swchvsm_hvbc_tm_BmsNegClsChg_s;
    break;

   case 5:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant6'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmNegCls_s;
    break;

   case 6:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant7'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmAssisCls_s;
    break;

   case 7:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant8'
     */
    rtb_MultiportSwitch = hvbc_tm_DcdcAct_s;
    break;

   case 8:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 9:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 10:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 11:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant9'
     */
    rtb_MultiportSwitch = hvbc_tm_SdcacAct_s;
    break;

   case 12:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant10'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmPosCls_s;
    break;

   case 13:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant11'
     */
    rtb_MultiportSwitch = hvbc_tm_BrkTankRdy_s;
    break;

   case 14:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant12'
     */
    rtb_MultiportSwitch = hvbc_tm_McuAct_s;
    break;

   case 15:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 16:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant13'
     */
    rtb_MultiportSwitch = hvbc_tm_ShutDnWait_s;
    break;

   case 17:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant14'
     */
    rtb_MultiportSwitch = hvbc_tm_HvDvcDeAct_s;
    break;

   case 18:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant15'
     */
    rtb_MultiportSwitch = hvbc_tm_McuDeAct_s;
    break;

   case 19:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant16'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmPosOpen_s;
    break;

   case 20:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant17'
     */
    rtb_MultiportSwitch = hvbc_tm_HvDvcDeActEmgy_s;
    break;

   case 21:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant18'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmPosOpenEmgy_s;
    break;

   case 22:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant19'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmAssisOpen_s;
    break;

   case 23:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant20'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmNegOpen_s;
    break;

   case 24:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant22'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmAssisOpenEmgy_s;
    break;

   case 25:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant21'
     */
    rtb_MultiportSwitch = hvbc_tm_HcmNegOpenEmgy_s;
    break;

   case 26:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant23'
     */
    rtb_MultiportSwitch = hvbc_tm_McuDsChg_s;
    break;

   case 27:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant24'
     */
    rtb_MultiportSwitch = hvbc_tm_BmsNegOpen_s;
    break;

   case 28:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant25'
     */
    rtb_MultiportSwitch = hvbc_tm_LvSysCutOffReq_s;
    break;

   case 29:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 30:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant4'
     */
    rtb_MultiportSwitch = hvbc_tm_AftRun_s;
    break;

   case 31:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 32:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant26'
     */
    rtb_MultiportSwitch = hvbc_tm_BmsNegOpenEmgy_s;
    break;

   case 33:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 34:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 35:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 36:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 37:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 38:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant28'
     */
    rtb_MultiportSwitch = hvbc_tm_bmsIntelChgCmplt_s;
    break;

   case 39:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   case 40:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant29'
     */
    rtb_MultiportSwitch = swchvsm_hvbc_tm_shtDnWaitEmgy_s;
    break;

   case 41:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant30'
     */
    rtb_MultiportSwitch = swchvsm_hvbc_tm_hvShutDnEmgy_s;
    break;

   case 42:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;

   default:
    /* MultiPortSwitch: '<S99>/Multiport Switch' incorporates:
     *  Constant: '<S99>/Constant5'
     */
    rtb_MultiportSwitch = hvbc_tm_Default_s;
    break;
  }

  /* End of MultiPortSwitch: '<S99>/Multiport Switch' */

  /* RelationalOperator: '<S99>/Relational Operator' */
  hvbd_b_tmOutFlg = (swc_HVSM_ARID_DEF.TimeInState > rtb_MultiportSwitch);

  /* Logic: '<S99>/Logical Operator' */
  rtb_LogicalOperator = !swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Logic: '<S99>/Logical Operator2' incorporates:
   *  Constant: '<S293>/Constant'
   *  Constant: '<S295>/Constant'
   *  Constant: '<S296>/Constant'
   *  Constant: '<S297>/Constant'
   *  Constant: '<S298>/Constant'
   *  Constant: '<S299>/Constant'
   *  Constant: '<S300>/Constant'
   *  Constant: '<S99>/Constant27'
   *  Logic: '<S99>/Logical Operator1'
   *  Logic: '<S99>/Logical Operator5'
   *  RelationalOperator: '<S293>/Compare'
   *  RelationalOperator: '<S99>/Relational Operator1'
   *  RelationalOperator: '<S99>/Relational Operator2'
   *  RelationalOperator: '<S99>/Relational Operator3'
   *  RelationalOperator: '<S99>/Relational Operator4'
   *  RelationalOperator: '<S99>/Relational Operator5'
   *  RelationalOperator: '<S99>/Relational Operator6'
   */
  rtb_LogicalOperator2 = (hvbd_b_tmOutFlg && (((hvbd_e_PmmStatus !=
    PmmStatus_HCMWAKEUP) && (hvbd_e_PmmStatus != PmmStatus_MCUWAKEUP) &&
    (hvbd_e_PmmStatus != PmmStatus_DRVBMSNEGCLOSE) && (hvbd_e_PmmStatus !=
    PmmStatus_DCDCACT) && (hvbd_e_PmmStatus != PmmStatus_SDCACACT) &&
    (hvbd_e_PmmStatus != PmmStatus_MCUACT)) || (((uint8)VEH_SWT_INF) != ((uint8)
    4U))));

  /* Outputs for Atomic SubSystem: '<S99>/SR_latch' */
  swc_HVSM_SR_latch_i(rtb_LogicalOperator2, rtb_LogicalOperator,
                      &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_k);

  /* End of Outputs for SubSystem: '<S99>/SR_latch' */

  /* Switch: '<S99>/Switch' incorporates:
   *  RelationalOperator: '<S294>/FixPt Relational Operator'
   *  UnitDelay: '<S294>/Delay Input1'
   *
   * Block description for '<S294>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((sint32)hvbd_b_tmOutFlg > (sint32)swc_HVSM_ARID_DEF.DelayInput1_DSTATE_gw)
  {
    /* Switch: '<S99>/Switch' incorporates:
     *  RelationalOperator: '<S99>/Relational Operator2'
     */
    hvbd_e_tmOutSource = hvbd_e_PmmStatus;
  } else {
    /* Switch: '<S99>/Switch' incorporates:
     *  UnitDelay: '<S99>/Unit Delay2'
     */
    hvbd_e_tmOutSource = swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_nf;
  }

  /* End of Switch: '<S99>/Switch' */

  /* Update for UnitDelay: '<S294>/Delay Input1'
   *
   * Block description for '<S294>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_gw = hvbd_b_tmOutFlg;

  /* Update for UnitDelay: '<S99>/Unit Delay2' incorporates:
   *  Switch: '<S99>/Switch'
   */
  swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_nf = hvbd_e_tmOutSource;
}

/* System initialize for function-call system: '<S1>/HVB_ModeManager' */
static void swc_HVSM_HVB_ModeManager_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out_o;
  boolean rtb_flg_out_b;
  boolean rtb_flg_out_e;
  boolean rtb_flg_out_j;
  boolean rtb_flg_out_p;
  boolean rtb_flg_out_m;
  boolean rtb_flg_out_k;
  boolean rtb_flg_out_pz;
  boolean rtb_flg_out_g;
  boolean rtb_flg_out_b5;
  boolean rtb_flg_out_n;
  boolean rtb_flg_out_gg;
  boolean rtb_flg_out_oi;
  boolean rtb_flg_out_c;
  boolean rtb_flg_out_gn;
  boolean rtb_flg_out_op;
  boolean rtb_flg_out_mg;
  boolean rtb_flg_out_jt;
  boolean rtb_flg_out_bs;
  boolean rtb_flg_out_d;
  boolean rtb_flg_out_a;
  boolean rtb_flg_out_f;
  boolean rtb_flg_out_m4;
  boolean rtb_flg_out_db;
  boolean rtb_flg_out_oh;
  boolean rtb_flg_out_br;

  /* InitializeConditions for UnitDelay: '<S95>/Unit Delay3' */
  swc_HVSM_ARID_DEF.UnitDelay3_DSTATE = ((uint16)100U);

  /* SystemInitialize for Atomic SubSystem: '<S138>/turnON_delay1' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_m4);

  /* End of SystemInitialize for SubSystem: '<S138>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S137>/turnON_delay1' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_db);

  /* End of SystemInitialize for SubSystem: '<S137>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S64>/turnOFF_delay' */
  swc_HVSM_turnOFF_delay1_Init(&rtb_flg_out_bs);

  /* End of SystemInitialize for SubSystem: '<S64>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S64>/turnON_delay1' */
  swc_HVSM_turnON_delay1_Init(&rtb_flg_out_mg);

  /* End of SystemInitialize for SubSystem: '<S64>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S64>/turnOFF_delay2' */
  swc_HVSM_turnOFF_delay1_Init(&swc_HVSM_ARID_DEF.flg_out_e);

  /* End of SystemInitialize for SubSystem: '<S64>/turnOFF_delay2' */

  /* SystemInitialize for Atomic SubSystem: '<S64>/turnON_delay2' */
  swc_HVSM_turnON_delay1_Init(&rtb_flg_out_op);

  /* End of SystemInitialize for SubSystem: '<S64>/turnON_delay2' */

  /* SystemInitialize for Atomic SubSystem: '<S95>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_e);

  /* End of SystemInitialize for SubSystem: '<S95>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S64>/turnOFF_delay1' */
  swc_HVSM_turnOFF_delay1_Init(&rtb_flg_out_jt);

  /* End of SystemInitialize for SubSystem: '<S64>/turnOFF_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S63>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_a);

  /* End of SystemInitialize for SubSystem: '<S63>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S63>/turnON_delay1' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_d);

  /* End of SystemInitialize for SubSystem: '<S63>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S100>/turnOFF_delay' */
  swc_HVSM_turnOFF_delay_Init(&rtb_flg_out_o);

  /* End of SystemInitialize for SubSystem: '<S100>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S91>/turnON_delay1' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_gg);

  /* End of SystemInitialize for SubSystem: '<S91>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S91>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_oi);

  /* End of SystemInitialize for SubSystem: '<S91>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S197>/turnON_delay1' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_c);

  /* End of SystemInitialize for SubSystem: '<S197>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S196>/turnON_delay1' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_gn);

  /* End of SystemInitialize for SubSystem: '<S196>/turnON_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S5>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&swc_HVSM_ARID_DEF.flg_out);

  /* End of SystemInitialize for SubSystem: '<S5>/turnON_delay' */

  /* SystemInitialize for Enabled SubSystem: '<S61>/Subsystem1' */
  /* SystemInitialize for SignalConversion: '<S126>/Signal Conversion' incorporates:
   *  Outport: '<S126>/mBSW_SetHvShutDnResult'
   */
  hvbd_st_hvbHvOnFlg = ((uint8)2U);

  /* End of SystemInitialize for SubSystem: '<S61>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S61>/Subsystem' */
  /* SystemInitialize for SignalConversion: '<S125>/Signal Conversion' incorporates:
   *  Outport: '<S125>/Out1'
   */
  hvbd_st_hvbShutDnFlg = ((uint8)2U);

  /* End of SystemInitialize for SubSystem: '<S61>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S61>/turnOFF_delay1' */
  swc_HVSM_turnOFF_delay1_Init(&rtb_flg_out_br);

  /* End of SystemInitialize for SubSystem: '<S61>/turnOFF_delay1' */

  /* SystemInitialize for Atomic SubSystem: '<S61>/turnOFF_delay2' */
  swc_HVSM_turnOFF_delay1_Init(&rtb_flg_out_oh);

  /* End of SystemInitialize for SubSystem: '<S61>/turnOFF_delay2' */

  /* SystemInitialize for Atomic SubSystem: '<S63>/turnOFF_delay2' */
  swc_HVSM_turnOFF_delay_Init(&rtb_flg_out_f);

  /* End of SystemInitialize for SubSystem: '<S63>/turnOFF_delay2' */

  /* SystemInitialize for Atomic SubSystem: '<S231>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_b5);

  /* End of SystemInitialize for SubSystem: '<S231>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S231>/turnOFF_delay' */
  swc_HVSM_turnOFF_delay_Init(&rtb_flg_out_n);

  /* End of SystemInitialize for SubSystem: '<S231>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S232>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_pz);

  /* End of SystemInitialize for SubSystem: '<S232>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S232>/turnOFF_delay' */
  swc_HVSM_turnOFF_delay_Init(&rtb_flg_out_g);

  /* End of SystemInitialize for SubSystem: '<S232>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_m);

  /* End of SystemInitialize for SubSystem: '<S233>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/turnOFF_delay' */
  swc_HVSM_turnOFF_delay_Init(&rtb_flg_out_k);

  /* End of SystemInitialize for SubSystem: '<S233>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S234>/turnON_delay' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_j);

  /* End of SystemInitialize for SubSystem: '<S234>/turnON_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S234>/turnOFF_delay' */
  swc_HVSM_turnOFF_delay_Init(&rtb_flg_out_p);

  /* End of SystemInitialize for SubSystem: '<S234>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S276>/turnON_delay1' */
  swc_HVSM_turnON_delay_Init(&rtb_flg_out_b);

  /* End of SystemInitialize for SubSystem: '<S276>/turnON_delay1' */

  /* SystemInitialize for SignalConversion: '<S5>/Signal Conversion' */
  swc_HVSM_ARID_DEF.hvbd_b_hvbIntelChgCmplt = swc_HVSM_ARID_DEF.IntelChgCmplt;

  /* SystemInitialize for SignalConversion: '<S5>/Signal Conversion1' */
  hvbd_b_hvbIntelChgExitReq = swc_HVSM_ARID_DEF.IntelChgExitReq;

  /* SystemInitialize for SignalConversion: '<S5>/Signal Conversion2' */
  swc_HVSM_ARID_DEF.swchvsm_eadd_e_inv2ModeTgtRaw = swc_HVSM_ARID_DEF.ElMacSts;

  /* SystemInitialize for SignalConversion: '<S5>/Signal Conversion3' */
  bmsd_e_modeTgt = swc_HVSM_ARID_DEF.BMSCtrlSts;
}

/* Output and update for function-call system: '<S1>/HVB_ModeManager' */
static void swc_HVSM_HVB_ModeManager(void)
{
  /* local block i/o variables */
  float32 rtb_Switch;
  float32 rtb_Switch_e;
  float32 rtb_Switch_k;
  float32 rtb_Switch_j;
  float32 rtb_Merge;
  uint8 rtb_CCaller;
  uint8 rtb_CCaller_k;
  boolean rtb_LogicalOperator16;
  boolean rtb_LogicalOperator18;
  boolean rtb_LogicalOperator7_b;
  boolean rtb_LogicalOperator5_o;
  boolean rtb_RelationalOperator10_p;
  boolean rtb_LogicalOperator4_p;
  boolean rtb_RelationalOperator14;
  boolean rtb_UnitDelay5_c;
  boolean rtb_LogicalOperator16_b;
  boolean rtb_LogicalOperator5_f;
  boolean rtb_LogicalOperator1_f;
  boolean rtb_LogicalOperator2_g;
  boolean rtb_LogicalOperator6_i;
  boolean rtb_LogicalOperator_j;
  boolean rtb_LogicalOperator9_f;
  boolean rtb_LogicalOperator12_b;
  boolean rtb_LogicalOperator2_h;
  boolean rtb_LogicalOperator_e;
  boolean rtb_RelationalOperator2_j;
  boolean rtb_FixPtRelationalOperator_h;
  boolean rtb_LogicalOperator_l;
  boolean rtb_LogicalOperator9_i;
  boolean rtb_RelationalOperator4_p;
  boolean rtb_LogicalOperator_a;
  boolean rtb_LogicalOperator1_n;
  boolean rtb_RelationalOperator7_g;
  boolean rtb_LogicalOperator11_c;
  boolean rtb_LogicalOperator2_d;
  boolean rtb_LogicalOperator18_i;
  boolean rtb_LogicalOperator9_a;
  boolean rtb_LogicalOperator14_j;
  boolean rtb_RelationalOperator11_f;
  boolean rtb_LogicalOperator3_e;
  boolean rtb_UnitDelay_f;
  boolean rtb_LogicalOperator3_p;
  boolean rtb_UnitDelay_fj;
  boolean rtb_LogicalOperator3_a;
  boolean rtb_UnitDelay_c;
  boolean rtb_UnitDelay_l;
  boolean rtb_LogicalOperator3_hu;
  boolean rtb_LogicalOperator13_k;
  boolean rtb_LogicalOperator7_l;
  boolean rtb_LogicalOperator_b;
  boolean rtb_LogicalOperator1_h;
  boolean rtb_flg_out_o;
  boolean rtb_LogicalOperator3_bd;
  boolean rtb_LogicalOperator3_c;
  boolean rtb_flg_out_b;
  boolean rtb_flg_out_e;
  boolean rtb_LogicalOperator3_i;
  boolean rtb_flg_out_j;
  boolean rtb_flg_out_p;
  boolean rtb_LogicalOperator3_j;
  boolean rtb_flg_out_m;
  boolean rtb_flg_out_k;
  boolean rtb_LogicalOperator3_he;
  boolean rtb_flg_out_pz;
  boolean rtb_flg_out_g;
  boolean rtb_LogicalOperator3_n;
  boolean rtb_flg_out_b5;
  boolean rtb_flg_out_n;
  boolean rtb_LogicalOperator3_kw;
  boolean rtb_flg_out_gg;
  boolean rtb_flg_out_oi;
  boolean rtb_flg_out_c;
  boolean rtb_flg_out_gn;
  boolean rtb_flg_out_op;
  boolean rtb_flg_out_mg;
  boolean rtb_flg_out_jt;
  boolean rtb_flg_out_bs;
  boolean rtb_flg_out_d;
  boolean rtb_flg_out_a;
  boolean rtb_flg_out_f;
  boolean rtb_flg_out_m4;
  boolean rtb_flg_out_db;
  boolean rtb_flg_out_oh;
  boolean rtb_flg_out_br;
  boolean rtb_LogicalOperator3_d;
  boolean rtb_LogicalOperator3_hb;
  boolean rtb_LogicalOperator3_hg;
  boolean rtb_LogicalOperator3_c3;
  boolean rtb_LogicalOperator3_g;
  float32 rtb_t_delay_on;
  uint16 rtb_Switch11;
  GearLeverPos rtb_RelationalOperator25_tmp;
  HVBRelayStatus rtb_LogicalOperator22_tmp;
  HVBattStatus rtb_LogicalOperator22_tmp_tmp;
  PmmStatus rtb_LogicalOperator16_tmp;
  PmmStatus rtb_UnitDelay13;
  uint8 rtb_CCaller2;
  uint8 rtb_Switch1_i;
  uint8 rtb_Switch4;
  uint8 tmp;
  boolean rtb_FixPtRelationalOperator_p3;
  boolean rtb_LogicalOperator10_d;
  boolean rtb_LogicalOperator12;
  boolean rtb_LogicalOperator14_tmp_tmp;
  boolean rtb_LogicalOperator1_l;
  boolean rtb_LogicalOperator21;
  boolean rtb_LogicalOperator22;
  boolean rtb_LogicalOperator2_eb;
  boolean rtb_LogicalOperator3;
  boolean rtb_LogicalOperator3_g_tmp;
  boolean rtb_RelationalOperator13;
  boolean rtb_RelationalOperator25;
  boolean rtb_RelationalOperator2_bz;
  boolean rtb_RelationalOperator8_b;
  boolean rtb_UnitDelay2_f;

  /* Logic: '<S61>/Logical Operator14' */
  rtb_LogicalOperator14_tmp_tmp = !swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* RelationalOperator: '<S61>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  rtb_LogicalOperator22_tmp_tmp = swc_HVSM_ARID_DEF.DataTypeConversion;

  /* Logic: '<S61>/Logical Operator22' incorporates:
   *  Constant: '<S120>/Constant'
   *  Constant: '<S121>/Constant'
   *  Constant: '<S122>/Constant'
   *  RelationalOperator: '<S61>/Relational Operator'
   *  RelationalOperator: '<S61>/Relational Operator15'
   *  RelationalOperator: '<S61>/Relational Operator16'
   */
  rtb_LogicalOperator22 = ((HVBattStatus_SLOW_CHARGE ==
    rtb_LogicalOperator22_tmp_tmp) || (HVBattStatus_FAST_CHARGE ==
    rtb_LogicalOperator22_tmp_tmp) || (HVBattStatus_HEATING ==
    rtb_LogicalOperator22_tmp_tmp));

  /* Logic: '<S61>/Logical Operator21' incorporates:
   *  Constant: '<S61>/Constant13'
   *  Inport generated from: '<Root>/BusElementIn9'
   *  Logic: '<S61>/Logical Operator37'
   *  RelationalOperator: '<S61>/Relational Operator7'
   */
  rtb_LogicalOperator21 = ((swc_HVSM_ARID_DEF.DataTypeConversion27 <=
    hvbc_v_otaCutOffHvSpd_kph) ||
    (!Rte_IRead_swc_HVSM_Step_vcib_VCIP_vscd_b_vehSpdVld()));

  /* Logic: '<S93>/Logical Operator2' incorporates:
   *  Constant: '<S230>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion41'
   *  Logic: '<S93>/Logical Operator3'
   *  Logic: '<S93>/Logical Operator4'
   *  RelationalOperator: '<S93>/Relational Operator1'
   */
  hvbd_b_LvSysSlfChkOk = ((swc_HVSM_ARID_DEF.DataTypeConversion16 ||
    swc_HVSM_ARID_DEF.DataTypeConversion44) &&
    swc_HVSM_ARID_DEF.DataTypeConversion43 &&
    swc_HVSM_ARID_DEF.DataTypeConversion55 &&
    (!swc_HVSM_ARID_DEF.DataTypeConversion83) &&
    (swc_HVSM_ARID_DEF.DataTypeConversion41 == McuSts_READY) &&
    swc_HVSM_ARID_DEF.DataTypeConversion62);

  /* UnitDelay: '<S5>/Unit Delay13' */
  rtb_UnitDelay13 = swc_HVSM_ARID_DEF.UnitDelay13_DSTATE;

  /* RelationalOperator: '<S61>/Relational Operator4' incorporates:
   *  RelationalOperator: '<S61>/Relational Operator10'
   *  RelationalOperator: '<S61>/Relational Operator5'
   *  UnitDelay: '<S5>/Unit Delay13'
   */
  rtb_LogicalOperator16_tmp = swc_HVSM_ARID_DEF.UnitDelay13_DSTATE;

  /* Logic: '<S61>/Logical Operator16' incorporates:
   *  Constant: '<S114>/Constant'
   *  Logic: '<S61>/Logical Operator17'
   *  RelationalOperator: '<S61>/Relational Operator4'
   */
  rtb_LogicalOperator16 = ((!hvbd_b_LvSysSlfChkOk) && (rtb_LogicalOperator16_tmp
    == PmmStatus_HCMWAKEUP));

  /* Outputs for Atomic SubSystem: '<S138>/turnON_delay1' */
  /* Constant: '<S138>/Constant7' incorporates:
   *  Constant: '<S138>/t_step1'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator16, 10.0F, 0.01F, &rtb_flg_out_m4,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay1_j);

  /* End of Outputs for SubSystem: '<S138>/turnON_delay1' */

  /* Logic: '<S61>/Logical Operator18' incorporates:
   *  Constant: '<S115>/Constant'
   *  Constant: '<S118>/Constant'
   *  Inport generated from: '<Root>/In Bus Element63'
   *  Logic: '<S61>/Logical Operator20'
   *  RelationalOperator: '<S61>/Relational Operator10'
   *  RelationalOperator: '<S61>/Relational Operator5'
   */
  rtb_LogicalOperator18 = ((Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_st_hvilOpenSt
    () != 0) && ((rtb_LogicalOperator16_tmp == PmmStatus_MCUWAKEUP) ||
                 (rtb_LogicalOperator16_tmp == PmmStatus_LVCUTWAIT)));

  /* Outputs for Atomic SubSystem: '<S137>/turnON_delay1' */
  /* Constant: '<S137>/Constant7' incorporates:
   *  Constant: '<S137>/t_step1'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator18, 10.0F, 0.01F, &rtb_flg_out_db,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay1_jz);

  /* End of Outputs for SubSystem: '<S137>/turnON_delay1' */

  /* RelationalOperator: '<S64>/Relational Operator2' incorporates:
   *  Constant: '<S173>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion66'
   */
  hvbd_b_parkingSts = (swc_HVSM_ARID_DEF.DataTypeConversion66 ==
                       ParkingStatus_ENGAGED);

  /* Outputs for Atomic SubSystem: '<S64>/turnOFF_delay' */
  /* Constant: '<S64>/Constant8' incorporates:
   *  Constant: '<S64>/t_step2'
   */
  swc_HVSM_turnOFF_delay1(hvbd_b_parkingSts, hvbc_tm_hvbChEpbgCfmTm_s, ((float32)
    HVB_TASK_INTERVAL_S), &rtb_flg_out_bs,
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay_da);

  /* End of Outputs for SubSystem: '<S64>/turnOFF_delay' */

  /* Logic: '<S64>/Logical Operator7' */
  rtb_LogicalOperator7_b = (swc_HVSM_ARID_DEF.DataTypeConversion15 &&
    swc_HVSM_ARID_DEF.DataTypeConversion16);

  /* Outputs for Atomic SubSystem: '<S64>/turnON_delay1' */
  /* Constant: '<S64>/Constant3' incorporates:
   *  Constant: '<S64>/t_step1'
   */
  swc_HVSM_turnON_delay1(rtb_LogicalOperator7_b, swchvsm_hvbc_tm_hvbChgCfmTm_s,
    ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_mg,
    &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay1_bn);

  /* End of Outputs for SubSystem: '<S64>/turnON_delay1' */

  /* Outputs for Atomic SubSystem: '<S64>/turnOFF_delay2' */
  /* Constant: '<S64>/Constant13' incorporates:
   *  Constant: '<S64>/t_step5'
   */
  swc_HVSM_turnOFF_delay1(rtb_flg_out_mg, hvbc_tm_hvbChEpbgCfmTm_s, ((float32)
    HVB_TASK_INTERVAL_S), &swc_HVSM_ARID_DEF.flg_out_e,
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay2);

  /* End of Outputs for SubSystem: '<S64>/turnOFF_delay2' */

  /* Logic: '<S64>/Logical Operator5' incorporates:
   *  Constant: '<S64>/Constant2'
   *  Constant: '<S64>/Constant4'
   *  RelationalOperator: '<S64>/Relational Operator7'
   *  RelationalOperator: '<S64>/Relational Operator9'
   */
  rtb_LogicalOperator5_o = ((swc_HVSM_ARID_DEF.DataTypeConversion99 == ((uint8)
    0U)) || (swc_HVSM_ARID_DEF.DataTypeConversion99 == ((uint8)2U)));

  /* RelationalOperator: '<S64>/Relational Operator10' incorporates:
   *  Constant: '<S64>/Constant6'
   */
  rtb_RelationalOperator10_p = (swc_HVSM_ARID_DEF.DataTypeConversion99 ==
    ((uint8)6U));

  /* Outputs for Atomic SubSystem: '<S64>/turnON_delay2' */
  /* Constant: '<S64>/Constant12' incorporates:
   *  Constant: '<S64>/t_step4'
   */
  swc_HVSM_turnON_delay1(rtb_RelationalOperator10_p, hvbc_tm_hvbChEpbgCfmTm_s,
    ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_op,
    &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay2);

  /* End of Outputs for SubSystem: '<S64>/turnON_delay2' */

  /* UnitDelay: '<S64>/Unit Delay2' */
  rtb_UnitDelay2_f = swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_m;

  /* Logic: '<S64>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S171>/FixPt Relational Operator'
   *  UnitDelay: '<S171>/Delay Input1'
   *  UnitDelay: '<S64>/Unit Delay2'
   *
   * Block description for '<S171>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator4_p = (rtb_flg_out_op || ((sint32)
    swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_m < (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_k));

  /* Outputs for Atomic SubSystem: '<S64>/SR_latch1' */
  swc_HVSM_SR_latch1(rtb_LogicalOperator5_o, rtb_LogicalOperator4_p,
                     &rtb_LogicalOperator3_d,
                     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch1_e);

  /* End of Outputs for SubSystem: '<S64>/SR_latch1' */

  /* RelationalOperator: '<S95>/Relational Operator14' incorporates:
   *  Constant: '<S95>/Constant18'
   *  Inport generated from: '<Root>/In Bus Element64'
   */
  rtb_RelationalOperator14 =
    (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt() == ((uint8)1U));

  /* Logic: '<S95>/Logical Operator12' incorporates:
   *  Constant: '<S95>/Constant12'
   *  Inport generated from: '<Root>/In Bus Element74'
   *  RelationalOperator: '<S95>/Relational Operator10'
   *  UnitDelay: '<S95>/Unit Delay2'
   */
  rtb_LogicalOperator12 = (swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_g &&
    (Rte_IRead_swc_HVSM_Step_vcob_VCOP_BMSH_ChargeLEDCtrl() != ((uint8)1U)));

  /* Outputs for Atomic SubSystem: '<S277>/turnON_delay1' */
  /* Saturate: '<S281>/Saturation' incorporates:
   *  Constant: '<S277>/Constant7'
   */
  if (60.0F > 1.6777216E+7F) {
    /* Saturate: '<S281>/Saturation' */
    rtb_t_delay_on = 1.6777216E+7F;
  } else if (60.0F < 0.0F) {
    /* Saturate: '<S281>/Saturation' */
    rtb_t_delay_on = 0.0F;
  } else {
    /* Saturate: '<S281>/Saturation' */
    rtb_t_delay_on = 60.0F;
  }

  /* End of Saturate: '<S281>/Saturation' */

  /* Chart: '<S281>/timed_delay' incorporates:
   *  Constant: '<S277>/t_step1'
   *  DataTypeConversion: '<S281>/Data Type Conversion'
   */
  if (swc_HVSM_ARID_DEF.is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_HVSM_ARID_DEF.is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtb_LogicalOperator12) {
      swc_HVSM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_ON_n;
      hvbd_b_ChgLEDCtlFlg = true;
    } else {
      swc_HVSM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF_mh;
      hvbd_b_ChgLEDCtlFlg = false;
    }
  } else {
    switch (swc_HVSM_ARID_DEF.is_c14_Ricardo_SW_dev_lib) {
     case swc_HVSM_IN_OFF_mh:
      if (rtb_LogicalOperator12) {
        if (rtb_t_delay_on == 0.0F) {
          swc_HVSM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_ON_n;
          hvbd_b_ChgLEDCtlFlg = true;
        } else {
          swc_HVSM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_ON_WAIT_f;
          swc_HVSM_ARID_DEF.t_wait = 0.0F;
          swc_HVSM_ARID_DEF.t_wait += ((float32)HVB_TASK_INTERVAL_S);
          hvbd_b_ChgLEDCtlFlg = false;
        }
      } else {
        hvbd_b_ChgLEDCtlFlg = false;
      }
      break;

     case swc_HVSM_IN_ON_n:
      if (!rtb_LogicalOperator12) {
        swc_HVSM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF_mh;
        hvbd_b_ChgLEDCtlFlg = false;
      } else {
        hvbd_b_ChgLEDCtlFlg = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtb_LogicalOperator12) {
        swc_HVSM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_OFF_mh;
        hvbd_b_ChgLEDCtlFlg = false;
      } else if (swc_HVSM_ARID_DEF.t_wait > rtb_t_delay_on - ((float32)
                  HVB_TASK_INTERVAL_S)) {
        swc_HVSM_ARID_DEF.is_c14_Ricardo_SW_dev_lib = swc_HVSM_IN_ON_n;
        hvbd_b_ChgLEDCtlFlg = true;
      } else {
        swc_HVSM_ARID_DEF.t_wait += ((float32)HVB_TASK_INTERVAL_S);
        hvbd_b_ChgLEDCtlFlg = false;
      }
      break;
    }
  }

  /* End of Chart: '<S281>/timed_delay' */
  /* End of Outputs for SubSystem: '<S277>/turnON_delay1' */

  /* RelationalOperator: '<S95>/Relational Operator9' incorporates:
   *  Constant: '<S95>/Constant7'
   *  UnitDelay: '<S95>/Unit Delay1'
   */
  rtb_LogicalOperator12 = (swc_HVSM_ARID_DEF.UnitDelay1_DSTATE == ((uint8)10U));

  /* RelationalOperator: '<S272>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S272>/Delay Input1'
   *
   * Block description for '<S272>/Delay Input1':
   *
   *  Store in Global RAM
   */
  hvbd_b_StsModeReqFlg = ((sint32)rtb_LogicalOperator12 < (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_l);

  /* Logic: '<S95>/Logical Operator4' */
  hvbd_b_ResChgRouterReset = (hvbd_b_ChgLEDCtlFlg || hvbd_b_StsModeReqFlg);

  /* Outputs for Atomic SubSystem: '<S95>/SR_latch1' */
  swc_HVSM_SR_latch1(rtb_RelationalOperator14, hvbd_b_ResChgRouterReset,
                     &rtb_LogicalOperator3_i,
                     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch1_f);

  /* End of Outputs for SubSystem: '<S95>/SR_latch1' */

  /* SignalConversion generated from: '<S95>/SR_latch1' */
  hvbd_b_ResChgRouterSwt = rtb_LogicalOperator3_i;

  /* Switch: '<S95>/Switch2' */
  if (hvbd_b_ResChgRouterSwt) {
    /* Switch: '<S95>/Switch3' incorporates:
     *  Constant: '<S95>/Constant13'
     *  Constant: '<S95>/Constant14'
     *  Constant: '<S95>/Constant16'
     *  Logic: '<S95>/Logical Operator5'
     *  RelationalOperator: '<S95>/Relational Operator11'
     *  RelationalOperator: '<S95>/Relational Operator12'
     *  RelationalOperator: '<S95>/Relational Operator13'
     *  Switch: '<S95>/Switch4'
     */
    if ((swc_HVSM_ARID_DEF.DataTypeConversion213 == ((uint8)0U)) ||
        (swc_HVSM_ARID_DEF.DataTypeConversion213 == ((uint8)1U))) {
      /* Switch: '<S95>/Switch2' incorporates:
       *  Constant: '<S95>/Constant15'
       *  Switch: '<S95>/Switch3'
       */
      hvbd_st_tboxChgSftSwCtlStEV = ((uint8)1U);
    } else if (swc_HVSM_ARID_DEF.DataTypeConversion213 == ((uint8)2U)) {
      /* Switch: '<S95>/Switch4' incorporates:
       *  Constant: '<S95>/Constant17'
       *  Switch: '<S95>/Switch2'
       *  Switch: '<S95>/Switch3'
       */
      hvbd_st_tboxChgSftSwCtlStEV = ((uint8)2U);
    } else {
      /* Switch: '<S95>/Switch2' incorporates:
       *  Switch: '<S95>/Switch3'
       *  Switch: '<S95>/Switch4'
       */
      hvbd_st_tboxChgSftSwCtlStEV = swc_HVSM_ARID_DEF.DataTypeConversion213;
    }

    /* End of Switch: '<S95>/Switch3' */
  } else {
    /* Switch: '<S95>/Switch2' */
    hvbd_st_tboxChgSftSwCtlStEV = swc_HVSM_ARID_DEF.DataTypeConversion213;
  }

  /* End of Switch: '<S95>/Switch2' */

  /* RelationalOperator: '<S95>/Relational Operator2' incorporates:
   *  Constant: '<S95>/Constant8'
   */
  rtb_RelationalOperator2_bz = (hvbd_st_tboxChgSftSwCtlStEV == ((uint8)2U));

  /* Switch: '<S95>/Switch8' incorporates:
   *  Constant: '<S95>/Constant36'
   *  Constant: '<S95>/Constant37'
   *  Constant: '<S95>/Constant38'
   *  Constant: '<S95>/Constant39'
   *  Constant: '<S95>/Constant41'
   *  Logic: '<S95>/Logical Operator9'
   *  RelationalOperator: '<S95>/Relational Operator27'
   *  RelationalOperator: '<S95>/Relational Operator28'
   *  RelationalOperator: '<S95>/Relational Operator29'
   *  Switch: '<S95>/Switch9'
   */
  if (swc_HVSM_ARID_DEF.DataTypeConversion209 == ((uint8)3U)) {
    tmp = ((uint8)2U);
  } else if ((swc_HVSM_ARID_DEF.DataTypeConversion209 == ((uint8)1U)) ||
             (swc_HVSM_ARID_DEF.DataTypeConversion209 == ((uint8)2U))) {
    /* Switch: '<S95>/Switch9' incorporates:
     *  Constant: '<S95>/Constant40'
     */
    tmp = ((uint8)1U);
  } else {
    tmp = ((uint8)0U);
  }

  /* Logic: '<S227>/Logical Operator3' incorporates:
   *  Constant: '<S95>/Constant34'
   *  RelationalOperator: '<S95>/Relational Operator24'
   *  Switch: '<S95>/Switch8'
   */
  rtb_LogicalOperator3_hg = (tmp != ((uint8)1U));

  /* Logic: '<S95>/Logical Operator2' incorporates:
   *  Constant: '<S95>/Constant2'
   *  Constant: '<S95>/Constant3'
   *  Constant: '<S95>/Constant4'
   *  Constant: '<S95>/Constant6'
   *  Logic: '<S95>/Logical Operator3'
   *  RelationalOperator: '<S95>/Relational Operator1'
   *  RelationalOperator: '<S95>/Relational Operator4'
   *  RelationalOperator: '<S95>/Relational Operator5'
   *  RelationalOperator: '<S95>/Relational Operator6'
   *  UnitDelay: '<S95>/Unit Delay8'
   */
  rtb_LogicalOperator2_eb = ((hvbd_st_tboxChgSftSwCtlStEV != ((uint8)1U)) &&
    ((swc_HVSM_ARID_DEF.UnitDelay8_DSTATE == ((uint8)3U)) &&
     (swc_HVSM_ARID_DEF.DataTypeConversion216 == ((uint8)1U))) &&
    (hvbd_st_tboxPrtFullSwSt != ((uint8)1U)) && rtb_LogicalOperator3_hg);

  /* Logic: '<S95>/Logical Operator1' incorporates:
   *  Constant: '<S95>/Constant1'
   *  Constant: '<S95>/Constant5'
   *  Constant: '<S95>/Constant9'
   *  RelationalOperator: '<S95>/Relational Operator3'
   *  RelationalOperator: '<S95>/Relational Operator7'
   *  RelationalOperator: '<S95>/Relational Operator8'
   */
  rtb_LogicalOperator1_l = (rtb_LogicalOperator3_hg && (hvbd_st_tboxPrtFullSwSt
    != ((uint8)1U)) && (swc_HVSM_ARID_DEF.DataTypeConversion216 == ((uint8)2U)) &&
    (hvbd_st_tboxChgSftSwCtlStEV != ((uint8)1U)));

  /* RelationalOperator: '<S95>/Relational Operator25' incorporates:
   *  Constant: '<S95>/Constant35'
   */
  rtb_RelationalOperator25 = (swc_HVSM_ARID_DEF.DataTypeConversion216 == ((uint8)
    3U));

  /* UnitDelay: '<S95>/Unit Delay5' */
  rtb_UnitDelay5_c = swc_HVSM_ARID_DEF.UnitDelay5_DSTATE_l;

  /* Outputs for Atomic SubSystem: '<S95>/turnON_delay' */
  /* Constant: '<S95>/Constant28' incorporates:
   *  Constant: '<S95>/Constant29'
   */
  swc_HVSM_turnON_delay(rtb_UnitDelay5_c, hvbd_tm_BookChrgnTarTm_s, 0.01F,
                        &rtb_flg_out_e,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay_c);

  /* End of Outputs for SubSystem: '<S95>/turnON_delay' */

  /* CCaller: '<S95>/C Caller1' */
  hvsm_pmmd_num_keyOnCnt = mBSW_NvmRead_KeyOnCnt();

  /* CCaller: '<S95>/C Caller2' */
  hvbd_pct_LocBkChgTarVal_Read = mBSW_NvmRead_BookChrgnTarVal_eep();

  /* Switch: '<S95>/Switch6' incorporates:
   *  Constant: '<S271>/Constant'
   *  Constant: '<S95>/Constant30'
   *  RelationalOperator: '<S271>/Compare'
   *  RelationalOperator: '<S95>/Relational Operator21'
   *  Switch: '<S95>/Switch10'
   *  Switch: '<S95>/Switch7'
   */
  if (rtb_flg_out_e) {
    /* Merge: '<S151>/Merge' incorporates:
     *  Inport generated from: '<Root>/BusElementIn1'
     */
    rtb_Merge = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_pct_mmiLocBkChgTarVal();
  } else if (hvsm_pmmd_num_keyOnCnt < ((uint8)1U)) {
    /* Switch: '<S95>/Switch7' incorporates:
     *  Constant: '<S95>/Constant31'
     *  Merge: '<S151>/Merge'
     */
    rtb_Merge = 100.0F;
  } else if (hvbd_pct_LocBkChgTarVal_Read == ((uint16)0U)) {
    /* Switch: '<S95>/Switch10' incorporates:
     *  Constant: '<S95>/Constant44'
     *  Merge: '<S151>/Merge'
     *  Switch: '<S95>/Switch7'
     */
    rtb_Merge = 100.0F;
  } else {
    /* Merge: '<S151>/Merge' incorporates:
     *  Switch: '<S95>/Switch10'
     *  Switch: '<S95>/Switch7'
     */
    rtb_Merge = hvbd_pct_LocBkChgTarVal_Read;
  }

  /* End of Switch: '<S95>/Switch6' */

  /* Switch: '<S95>/Switch' incorporates:
   *  Constant: '<S95>/Constant27'
   *  Constant: '<S95>/Constant33'
   *  Logic: '<S95>/Logical Operator14'
   *  RelationalOperator: '<S95>/Relational Operator22'
   *  RelationalOperator: '<S95>/Relational Operator23'
   */
  if ((rtb_Merge <= 100.0F) && (rtb_Merge > 0.0F)) {
    rtb_t_delay_on = fmodf(floorf(rtb_Merge), 65536.0F);

    /* Switch: '<S95>/Switch' */
    hvbd_pct_BookChrgnTarValFb = (uint16)(rtb_t_delay_on < 0.0F ? (sint32)
      (uint16)-(sint16)(uint16)-rtb_t_delay_on : (sint32)(uint16)rtb_t_delay_on);
  } else {
    /* Switch: '<S95>/Switch' incorporates:
     *  UnitDelay: '<S95>/Unit Delay3'
     */
    hvbd_pct_BookChrgnTarValFb = swc_HVSM_ARID_DEF.UnitDelay3_DSTATE;
  }

  /* End of Switch: '<S95>/Switch' */

  /* RelationalOperator: '<S95>/Relational Operator26' incorporates:
   *  Inport generated from: '<Root>/In Bus Element96'
   *  RelationalOperator: '<S63>/Relational Operator4'
   *  RelationalOperator: '<S83>/Relational Operator4'
   *  RelationalOperator: '<S83>/Relational Operator7'
   */
  rtb_t_delay_on = Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_q_hvbSOC_pct();

  /* Logic: '<S228>/Logical Operator3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element96'
   *  RelationalOperator: '<S95>/Relational Operator26'
   */
  rtb_LogicalOperator3_c3 = (rtb_t_delay_on >= hvbd_pct_BookChrgnTarValFb);

  /* Logic: '<S95>/Logical Operator6' incorporates:
   *  Logic: '<S95>/Logical Operator15'
   */
  hvbd_b_rsrNotAlwChg = (rtb_RelationalOperator2_bz || rtb_LogicalOperator2_eb ||
    rtb_LogicalOperator1_l || (rtb_LogicalOperator3_hg &&
    rtb_RelationalOperator25 && rtb_LogicalOperator3_c3));

  /* Switch: '<S95>/Switch1' incorporates:
   *  Constant: '<S95>/Constant11'
   */
  if (hvbc_b_rsrNotAlwChg_ovrdflg) {
    /* Logic: '<S228>/Logical Operator3' incorporates:
     *  Constant: '<S95>/Constant10'
     */
    rtb_LogicalOperator3_c3 = hvbc_b_rsrNotAlwChg_ovrdval;
  } else {
    /* Logic: '<S228>/Logical Operator3' */
    rtb_LogicalOperator3_c3 = hvbd_b_rsrNotAlwChg;
  }

  /* End of Switch: '<S95>/Switch1' */

  /* Logic: '<S64>/Logical Operator3' */
  rtb_RelationalOperator2_bz = !rtb_LogicalOperator3_c3;

  /* Logic: '<S64>/Logical Operator6' incorporates:
   *  Constant: '<S64>/Constant5'
   *  RelationalOperator: '<S64>/Relational Operator6'
   */
  rtb_LogicalOperator2_eb = (swc_HVSM_ARID_DEF.DataTypeConversion27 <=
    obcc_v_ChargerPlugThr_kph);

  /* Logic: '<S64>/Logical Operator16' incorporates:
   *  Constant: '<S172>/Constant'
   *  Constant: '<S174>/Constant'
   *  Constant: '<S175>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Logic: '<S64>/Logical Operator13'
   *  RelationalOperator: '<S64>/Relational Operator1'
   *  RelationalOperator: '<S64>/Relational Operator3'
   *  RelationalOperator: '<S64>/Relational Operator4'
   */
  rtb_LogicalOperator16_b = ((swc_HVSM_ARID_DEF.DataTypeConversion !=
    HVBattStatus_CHARGE_COMPLETE) && (swc_HVSM_ARID_DEF.DataTypeConversion !=
    HVBattStatus_SHUTDOWN) && (swc_HVSM_ARID_DEF.DataTypeConversion !=
    HVBattStatus_INVALID));

  /* Outputs for Atomic SubSystem: '<S64>/turnOFF_delay1' */
  /* Constant: '<S64>/Constant11' incorporates:
   *  Constant: '<S64>/t_step3'
   */
  swc_HVSM_turnOFF_delay1(rtb_LogicalOperator16_b, hvbc_tm_hvbChEpbgCfmTm_s,
    ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_jt,
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay1);

  /* End of Outputs for SubSystem: '<S64>/turnOFF_delay1' */

  /* RelationalOperator: '<S64>/Relational Operator5' incorporates:
   *  Constant: '<S64>/Constant7'
   */
  rtb_LogicalOperator1_l = (swc_HVSM_ARID_DEF.DataTypeConversion213 != ((uint8)
    2U));

  /* RelationalOperator: '<S64>/Relational Operator8' incorporates:
   *  Constant: '<S64>/Constant9'
   *  Inport generated from: '<Root>/In Bus Element31'
   */
  rtb_RelationalOperator8_b =
    (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_pepsRKECom() != ((uint8)14U));

  /* Logic: '<S228>/Logical Operator3' incorporates:
   *  Constant: '<S64>/Constant10'
   *  Inport generated from: '<Root>/In Bus Element37'
   *  RelationalOperator: '<S64>/Relational Operator12'
   */
  rtb_LogicalOperator3_c3 =
    (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_ipkChgSftSwCtlSt() != ((uint8)1U));

  /* Logic: '<S227>/Logical Operator3' incorporates:
   *  CCaller: '<S130>/C Caller1'
   */
  rtb_LogicalOperator3_hg = mBSW_HvShutDnReq();

  /* Switch: '<S140>/Switch2' incorporates:
   *  Constant: '<S130>/FID_ovrdflg'
   */
  if (hvbc_b_hvShutDnReq_ovrdflg) {
    /* Switch: '<S140>/Switch2' incorporates:
     *  Constant: '<S130>/FID_ovrdval'
     */
    hvbd_b_hvbShutDnReq = hvbc_b_hvShutDnReq_ovrdval;
  } else {
    /* Switch: '<S140>/Switch2' */
    hvbd_b_hvbShutDnReq = rtb_LogicalOperator3_hg;
  }

  /* End of Switch: '<S140>/Switch2' */

  /* UnitDelay: '<S61>/Unit Delay' */
  rtb_Switch1_i = swc_HVSM_ARID_DEF.UnitDelay_DSTATE_l;

  /* RelationalOperator: '<S61>/Relational Operator11' incorporates:
   *  Inport generated from: '<Root>/BusElementIn4'
   *  RelationalOperator: '<S61>/Relational Operator12'
   *  RelationalOperator: '<S63>/Relational Operator'
   *  RelationalOperator: '<S63>/Relational Operator1'
   *  RelationalOperator: '<S63>/Relational Operator3'
   *  RelationalOperator: '<S63>/Relational Operator5'
   *  Switch: '<S63>/Switch3'
   *  Switch: '<S63>/Switch6'
   */
  rtb_RelationalOperator25_tmp =
    Rte_IRead_swc_HVSM_Step_vcsb_VOMM_drid_e_gearLvrPos();

  /* Logic: '<S61>/Logical Operator23' incorporates:
   *  Constant: '<S110>/Constant'
   *  Constant: '<S111>/Constant'
   *  RelationalOperator: '<S61>/Relational Operator11'
   *  RelationalOperator: '<S61>/Relational Operator12'
   */
  rtb_RelationalOperator25 = ((rtb_RelationalOperator25_tmp ==
    GearLeverPos_PARKING) || (rtb_RelationalOperator25_tmp ==
    GearLeverPos_NEUTRAL));

  /* RelationalOperator: '<S61>/Relational Operator13' incorporates:
   *  Constant: '<S119>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion66'
   */
  rtb_RelationalOperator13 = (swc_HVSM_ARID_DEF.DataTypeConversion66 ==
    ParkingStatus_ENGAGED);

  /* Logic: '<S227>/Logical Operator3' incorporates:
   *  Logic: '<S61>/Logical Operator24'
   *  Logic: '<S61>/Logical Operator25'
   *  Logic: '<S61>/Logical Operator26'
   *  Logic: '<S61>/Logical Operator7'
   *  Logic: '<S61>/Logical Operator8'
   */
  rtb_LogicalOperator3_hg = ((!rtb_LogicalOperator22) &&
    swc_HVSM_ARID_DEF.DataTypeConversion24 && rtb_LogicalOperator21 &&
    ((rtb_Switch1_i == 0) || ((rtb_Switch1_i != 0) && rtb_RelationalOperator25 &&
    rtb_RelationalOperator13)));

  /* Logic: '<S61>/Logical Operator5' incorporates:
   *  RelationalOperator: '<S107>/FixPt Relational Operator'
   *  UnitDelay: '<S107>/Delay Input1'
   *
   * Block description for '<S107>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator5_f = (((sint32)hvbd_b_hvbShutDnReq > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_i) && rtb_LogicalOperator3_hg);

  /* RelationalOperator: '<S105>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S105>/Delay Input1'
   *
   * Block description for '<S105>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_p3 = (swc_HVSM_ARID_DEF.DataTypeConversion24 !=
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_mi);

  /* Switch: '<S63>/Switch1' incorporates:
   *  CCaller: '<S61>/C Caller'
   */
  rtb_Switch1_i = uds_GetActiveSession();

  /* Switch: '<S61>/Switch25' incorporates:
   *  Constant: '<S61>/Constant34'
   */
  if (hvbc_b_udsGetActiveSession_ovrdflg) {
    /* Switch: '<S61>/Switch25' incorporates:
     *  Constant: '<S61>/Constant33'
     */
    hvbd_st_udsGetActiveSession = hvbc_st_udsGetActiveSession_ovrdval;
  } else {
    /* Switch: '<S61>/Switch25' */
    hvbd_st_udsGetActiveSession = rtb_Switch1_i;
  }

  /* End of Switch: '<S61>/Switch25' */

  /* Logic: '<S304>/Logical Operator3' incorporates:
   *  Constant: '<S102>/Constant'
   *  RelationalOperator: '<S102>/Compare'
   */
  rtb_LogicalOperator3_hb = (hvbd_st_udsGetActiveSession == ((uint8)1U));

  /* Logic: '<S274>/Logical Operator3' incorporates:
   *  CCaller: '<S129>/C Caller1'
   */
  rtb_LogicalOperator3_g = mBSW_RoutineReq_03E1();

  /* Switch: '<S139>/Switch2' incorporates:
   *  Constant: '<S129>/FID_ovrdflg'
   */
  if (hvbc_b_hvOnReq_ovrdflg) {
    /* Switch: '<S139>/Switch2' incorporates:
     *  Constant: '<S129>/FID_ovrdval'
     */
    hvbd_b_hvbHvOnReq = hvbc_b_hvOnReq_ovrdval;
  } else {
    /* Switch: '<S139>/Switch2' */
    hvbd_b_hvbHvOnReq = rtb_LogicalOperator3_g;
  }

  /* End of Switch: '<S139>/Switch2' */

  /* Logic: '<S61>/Logical Operator1' */
  rtb_LogicalOperator1_f = (rtb_FixPtRelationalOperator_p3 ||
    rtb_LogicalOperator3_hb || hvbd_b_hvbHvOnReq);

  /* Outputs for Atomic SubSystem: '<S61>/SR_latch2' */
  rtb_LogicalOperator3_g = swc_HVSM_SR_latch(rtb_LogicalOperator5_f,
    rtb_LogicalOperator1_f, &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch2_i);

  /* End of Outputs for SubSystem: '<S61>/SR_latch2' */

  /* Switch: '<S61>/Switch1' incorporates:
   *  Constant: '<S61>/Constant5'
   */
  if (hvbc_b_otaShutDn_ovrdflg) {
    /* Switch: '<S61>/Switch1' incorporates:
     *  Constant: '<S61>/Constant6'
     */
    hvbd_b_otaShutDn = hvbc_b_otaShutDn_ovrdval;
  } else {
    /* Switch: '<S61>/Switch1' */
    hvbd_b_otaShutDn = rtb_LogicalOperator3_g;
  }

  /* End of Switch: '<S61>/Switch1' */

  /* Logic: '<S61>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S108>/FixPt Relational Operator'
   *  UnitDelay: '<S108>/Delay Input1'
   *
   * Block description for '<S108>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator2_g = (rtb_LogicalOperator3_hg && ((sint32)
    hvbd_b_hvbHvOnReq > (sint32)swc_HVSM_ARID_DEF.DelayInput1_DSTATE_e));

  /* Logic: '<S61>/Logical Operator6' incorporates:
   *  RelationalOperator: '<S106>/FixPt Relational Operator'
   *  UnitDelay: '<S106>/Delay Input1'
   *
   * Block description for '<S106>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator6_i = ((swc_HVSM_ARID_DEF.DataTypeConversion24 !=
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_ea) || rtb_LogicalOperator3_hb ||
    hvbd_b_hvbShutDnReq);

  /* Outputs for Atomic SubSystem: '<S61>/SR_latch1' */
  rtb_LogicalOperator3_g = swc_HVSM_SR_latch(rtb_LogicalOperator2_g,
    rtb_LogicalOperator6_i, &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch1_o);

  /* End of Outputs for SubSystem: '<S61>/SR_latch1' */

  /* Switch: '<S61>/Switch7' incorporates:
   *  Constant: '<S61>/Constant7'
   */
  if (hvbc_b_otaHvOn_ovrdflg) {
    /* Switch: '<S61>/Switch7' incorporates:
     *  Constant: '<S61>/Constant8'
     */
    hvbd_b_otaHvOn = hvbc_b_otaHvOn_ovrdval;
  } else {
    /* Switch: '<S61>/Switch7' */
    hvbd_b_otaHvOn = rtb_LogicalOperator3_g;
  }

  /* End of Switch: '<S61>/Switch7' */

  /* Logic: '<S61>/Logical Operator36' */
  swc_HVSM_ARID_DEF.LogicalOperator36 = (hvbd_b_otaShutDn || hvbd_b_otaHvOn);

  /* Logic: '<S64>/Logical Operator1' incorporates:
   *  Logic: '<S64>/Logical Operator2'
   *  Logic: '<S64>/Logical Operator8'
   *  Logic: '<S64>/Logical Operator9'
   *  UnitDelay: '<S64>/Unit Delay1'
   */
  hvbd_b_chargeReq = (rtb_flg_out_bs && (swc_HVSM_ARID_DEF.flg_out_e &&
    rtb_LogicalOperator3_d && rtb_RelationalOperator2_bz &&
    rtb_LogicalOperator2_eb && rtb_flg_out_jt && rtb_LogicalOperator1_l &&
    rtb_RelationalOperator8_b && rtb_LogicalOperator3_c3 &&
    ((!swc_HVSM_ARID_DEF.LogicalOperator36) ||
     swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_a)));

  /* Switch: '<S5>/Switch4' incorporates:
   *  Constant: '<S5>/Constant11'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S66>/Constant'
   *  Constant: '<S67>/Constant'
   *  Constant: '<S68>/Constant'
   *  Constant: '<S69>/Constant'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S72>/Constant'
   *  Constant: '<S73>/Constant'
   *  Constant: '<S74>/Constant'
   *  Constant: '<S75>/Constant'
   *  Constant: '<S76>/Constant'
   *  Constant: '<S78>/Constant'
   *  Inport generated from: '<Root>/In Bus Element179'
   *  Logic: '<S5>/Logical Operator10'
   *  Logic: '<S5>/Logical Operator12'
   *  Logic: '<S5>/Logical Operator13'
   *  Logic: '<S5>/Logical Operator14'
   *  Logic: '<S5>/Logical Operator15'
   *  Logic: '<S5>/Logical Operator8'
   *  RelationalOperator: '<S65>/Compare'
   *  RelationalOperator: '<S66>/Compare'
   *  RelationalOperator: '<S67>/Compare'
   *  RelationalOperator: '<S68>/Compare'
   *  RelationalOperator: '<S69>/Compare'
   *  RelationalOperator: '<S70>/Compare'
   *  RelationalOperator: '<S72>/Compare'
   *  RelationalOperator: '<S73>/Compare'
   *  RelationalOperator: '<S74>/Compare'
   *  RelationalOperator: '<S75>/Compare'
   *  RelationalOperator: '<S76>/Compare'
   *  RelationalOperator: '<S78>/Compare'
   */
  if (swchvsm_hvbc_flg_PowerONEB_Cfg) {
    /* RelationalOperator: '<S67>/Compare' incorporates:
     *  Inport generated from: '<Root>/In Bus Element179'
     *  RelationalOperator: '<S66>/Compare'
     */
    rtb_Switch1_i = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hvbChgCcsts();
    hvbd_b_chgCablePlugged = ((rtb_Switch1_i == ((uint8)1U)) || (rtb_Switch1_i ==
      ((uint8)2U)) || ((swc_HVSM_ARID_DEF.DataTypeConversion209 == ((uint8)1U)) ||
                       (swc_HVSM_ARID_DEF.DataTypeConversion209 == ((uint8)3U)))
      || (swc_HVSM_ARID_DEF.DataTypeConversion218 != 0.0) ||
      (swc_HVSM_ARID_DEF.DataTypeConversion224 != ((uint8)0U)));
  } else {
    hvbd_b_chgCablePlugged = ((swc_HVSM_ARID_DEF.DataTypeConversion224 !=
      ((uint8)0U)) || ((swc_HVSM_ARID_DEF.DataTypeConversion209 == ((uint8)1U)) ||
                       (swc_HVSM_ARID_DEF.DataTypeConversion209 == ((uint8)3U)))
      || (swc_HVSM_ARID_DEF.DataTypeConversion218 != 0.0) ||
      ((swc_HVSM_ARID_DEF.DataTypeConversion119 == 1.0) ||
       (swc_HVSM_ARID_DEF.DataTypeConversion119 == 2.0)));
  }

  /* End of Switch: '<S5>/Switch4' */

  /* Logic: '<S5>/Logical Operator5' incorporates:
   *  Inport generated from: '<Root>/In Bus Element84'
   */
  hvbd_b_emgyShutDn = (Rte_IRead_swc_HVSM_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg()
                       || swc_HVSM_ARID_DEF.DataTypeConversion19);

  /* Switch: '<S88>/Switch1' incorporates:
   *  Constant: '<S88>/Constant6'
   *  Constant: '<S88>/Constant8'
   *  Inport generated from: '<Root>/In Bus Element80'
   *  Logic: '<S88>/Logical Operator6'
   */
  if (hvbc_b_fltShutDn_ovrdflg) {
    hvbd_b_fltShutDn = hvbc_b_fltShutDn_ovrdval;
  } else {
    hvbd_b_fltShutDn = (hvbd_b_otaShutDn ||
                        Rte_IRead_swc_HVSM_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg
                        ());
  }

  /* End of Switch: '<S88>/Switch1' */

  /* RelationalOperator: '<S158>/FixPt Relational Operator' incorporates:
   *  Inport generated from: '<Root>/BusElementIn2'
   *  UnitDelay: '<S158>/Delay Input1'
   * *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator3_g_tmp =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmCampModeSwt();

  /* Logic: '<S274>/Logical Operator3' incorporates:
   *  Inport generated from: '<Root>/BusElementIn2'
   *  Inport generated from: '<Root>/BusElementIn3'
   *  Logic: '<S63>/Logical Operator16'
   *  Logic: '<S63>/Logical Operator6'
   *  RelationalOperator: '<S158>/FixPt Relational Operator'
   *  UnitDelay: '<S158>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator3_g =
    ((!Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmCampModeSwtInvld()) &&
     ((sint32)rtb_LogicalOperator3_g_tmp > (sint32)
      swc_HVSM_ARID_DEF.DelayInput1_DSTATE_ph));

  /* Switch: '<S63>/Switch1' incorporates:
   *  Constant: '<S63>/Constant19'
   *  Constant: '<S63>/Constant20'
   */
  if (rtb_LogicalOperator3_g) {
    tmp = ((uint8)1U);
  } else {
    tmp = ((uint8)0U);
  }

  /* Switch: '<S144>/Switch2' incorporates:
   *  Sum: '<S63>/Sum'
   *  Switch: '<S63>/Switch1'
   *  UnitDelay: '<S63>/Unit Delay1'
   */
  rtb_Switch1_i = (uint8)((uint32)tmp + swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_l);

  /* Switch: '<S63>/Switch2' incorporates:
   *  Constant: '<S154>/Constant'
   *  Logic: '<S63>/Logical Operator11'
   *  RelationalOperator: '<S154>/Compare'
   *  UnitDelay: '<S63>/Unit Delay2'
   */
  if (swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_h || (rtb_Switch1_i >= ((uint8)2U))) {
    /* Switch: '<S63>/Switch2' incorporates:
     *  Constant: '<S63>/Constant18'
     */
    rtb_RelationalOperator2_bz = (((uint8)0U) != 0);
  } else {
    /* Switch: '<S63>/Switch2' */
    rtb_RelationalOperator2_bz = (rtb_Switch1_i != 0);
  }

  /* End of Switch: '<S63>/Switch2' */

  /* Switch: '<S63>/Switch9' incorporates:
   *  Constant: '<S63>/Constant12'
   */
  if (hvbd_b_RmtCtrlSw) {
    /* Switch: '<S63>/Switch9' incorporates:
     *  Inport generated from: '<Root>/BusElementIn6'
     */
    rtb_Switch1_i = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_pepsRmtCtrlSt();
  } else {
    /* Switch: '<S63>/Switch9' incorporates:
     *  Constant: '<S63>/Constant11'
     */
    rtb_Switch1_i = ((uint8)0U);
  }

  /* End of Switch: '<S63>/Switch9' */

  /* Logic: '<S304>/Logical Operator3' incorporates:
   *  Constant: '<S163>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion66'
   *  RelationalOperator: '<S63>/Relational Operator2'
   */
  rtb_LogicalOperator3_hb = (swc_HVSM_ARID_DEF.DataTypeConversion66 ==
    ParkingStatus_ENGAGED);

  /* Logic: '<S228>/Logical Operator3' incorporates:
   *  Constant: '<S63>/Constant4'
   *  RelationalOperator: '<S63>/Relational Operator4'
   */
  rtb_LogicalOperator3_c3 = (rtb_t_delay_on > hvbc_q_CampModeSoc_pct);

  /* Logic: '<S227>/Logical Operator3' incorporates:
   *  Logic: '<S63>/Logical Operator7'
   */
  rtb_LogicalOperator3_hg = (hvbd_b_fltShutDn || hvbd_b_emgyShutDn ||
    hvbd_b_crashShutDn);

  /* Logic: '<S63>/Logical Operator3' incorporates:
   *  Inport generated from: '<Root>/BusElementIn5'
   *  Logic: '<S63>/Logical Operator13'
   */
  rtb_LogicalOperator2_eb =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_brpd_b_brkPressedFromSwitch();

  /* Logic: '<S63>/Logical Operator' incorporates:
   *  Constant: '<S155>/Constant'
   *  Constant: '<S160>/Constant'
   *  Constant: '<S162>/Constant'
   *  Inport generated from: '<Root>/BusElementIn5'
   *  Logic: '<S63>/Logical Operator1'
   *  Logic: '<S63>/Logical Operator10'
   *  Logic: '<S63>/Logical Operator15'
   *  Logic: '<S63>/Logical Operator3'
   *  RelationalOperator: '<S155>/Compare'
   *  RelationalOperator: '<S63>/Relational Operator'
   *  RelationalOperator: '<S63>/Relational Operator3'
   */
  rtb_LogicalOperator_j = (rtb_RelationalOperator2_bz &&
    (swc_HVSM_ARID_DEF.DataTypeConversion24 && (rtb_Switch1_i != ((uint8)1U))) &&
    ((rtb_RelationalOperator25_tmp == GearLeverPos_NEUTRAL) ||
     (rtb_RelationalOperator25_tmp == GearLeverPos_PARKING)) &&
    rtb_LogicalOperator3_hb && rtb_LogicalOperator3_c3 &&
    (!rtb_LogicalOperator3_hg) && (!rtb_LogicalOperator2_eb));

  /* Logic: '<S63>/Logical Operator9' */
  rtb_LogicalOperator9_f = !rtb_LogicalOperator3_hb;

  /* Outputs for Atomic SubSystem: '<S63>/turnON_delay' */
  /* Constant: '<S63>/t_step1' incorporates:
   *  Constant: '<S63>/t_step2'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator9_f, hvbc_tm_hvbCampModeExit_s,
                        ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_a,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay_jz);

  /* End of Outputs for SubSystem: '<S63>/turnON_delay' */

  /* Logic: '<S63>/Logical Operator12' */
  rtb_LogicalOperator12_b = !rtb_LogicalOperator3_c3;

  /* Outputs for Atomic SubSystem: '<S63>/turnON_delay1' */
  /* Constant: '<S63>/t_step3' incorporates:
   *  Constant: '<S63>/t_step4'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator12_b, hvbc_tm_hvbCampModeExit_s,
                        ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_d,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay1_bj);

  /* End of Outputs for SubSystem: '<S63>/turnON_delay1' */

  /* Switch: '<S63>/Switch6' incorporates:
   *  Constant: '<S156>/Constant'
   *  Constant: '<S159>/Constant'
   *  Constant: '<S161>/Constant'
   *  Logic: '<S63>/Logical Operator18'
   *  Logic: '<S63>/Logical Operator5'
   *  Logic: '<S63>/Logical Operator8'
   *  RelationalOperator: '<S156>/Compare'
   *  RelationalOperator: '<S63>/Relational Operator1'
   *  RelationalOperator: '<S63>/Relational Operator5'
   *  Switch: '<S63>/Switch3'
   *  Switch: '<S63>/Switch4'
   *  Switch: '<S63>/Switch5'
   *  Switch: '<S63>/Switch7'
   */
  if (rtb_LogicalOperator3_hg) {
    /* Switch: '<S63>/Switch6' incorporates:
     *  Constant: '<S63>/Constant5'
     */
    hvbd_st_CampModeFbFailrReason = ((uint8)5U);
  } else if ((!swc_HVSM_ARID_DEF.DataTypeConversion24) || (rtb_Switch1_i ==
              ((uint8)1U))) {
    /* Switch: '<S63>/Switch6' incorporates:
     *  Constant: '<S63>/Constant1'
     *  Switch: '<S63>/Switch3'
     */
    hvbd_st_CampModeFbFailrReason = ((uint8)1U);
  } else if ((rtb_RelationalOperator25_tmp == GearLeverPos_FWD_DRIVE) ||
             (rtb_RelationalOperator25_tmp == GearLeverPos_REV_DRIVE)) {
    /* Switch: '<S63>/Switch4' incorporates:
     *  Constant: '<S63>/Constant2'
     *  Switch: '<S63>/Switch3'
     *  Switch: '<S63>/Switch6'
     */
    hvbd_st_CampModeFbFailrReason = ((uint8)2U);
  } else if (rtb_flg_out_a) {
    /* Switch: '<S63>/Switch5' incorporates:
     *  Constant: '<S63>/Constant3'
     *  Switch: '<S63>/Switch3'
     *  Switch: '<S63>/Switch4'
     *  Switch: '<S63>/Switch6'
     */
    hvbd_st_CampModeFbFailrReason = ((uint8)3U);
  } else if (rtb_flg_out_d) {
    /* Switch: '<S63>/Switch7' incorporates:
     *  Constant: '<S63>/Constant6'
     *  Switch: '<S63>/Switch3'
     *  Switch: '<S63>/Switch4'
     *  Switch: '<S63>/Switch5'
     *  Switch: '<S63>/Switch6'
     */
    hvbd_st_CampModeFbFailrReason = ((uint8)4U);
  } else {
    /* Switch: '<S63>/Switch6' incorporates:
     *  Constant: '<S63>/Constant7'
     *  Switch: '<S63>/Switch3'
     *  Switch: '<S63>/Switch4'
     *  Switch: '<S63>/Switch5'
     *  Switch: '<S63>/Switch7'
     */
    hvbd_st_CampModeFbFailrReason = ((uint8)0U);
  }

  /* Logic: '<S63>/Logical Operator13' */
  rtb_LogicalOperator2_eb = (rtb_LogicalOperator2_eb ||
    (hvbd_st_CampModeFbFailrReason != 0));

  /* Logic: '<S63>/Logical Operator2' incorporates:
   *  Logic: '<S63>/Logical Operator4'
   */
  rtb_LogicalOperator2_h = ((!rtb_RelationalOperator2_bz) ||
    rtb_LogicalOperator2_eb);

  /* Outputs for Atomic SubSystem: '<S63>/SR_latch' */
  swc_HVSM_SR_latch_n(rtb_LogicalOperator_j, rtb_LogicalOperator2_h,
                      &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_a);

  /* End of Outputs for SubSystem: '<S63>/SR_latch' */

  /* Logic: '<S98>/Logical Operator' incorporates:
   *  RelationalOperator: '<S291>/FixPt Relational Operator'
   *  UnitDelay: '<S291>/Delay Input1'
   *
   * Block description for '<S291>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator_e = (((sint32)swc_HVSM_ARID_DEF.DataTypeConversion24 <
    (sint32)swc_HVSM_ARID_DEF.DelayInput1_DSTATE_kb) || hvbd_b_chgCablePlugged ||
    hvbd_b_emgyShutDn || hvbd_b_fltShutDn || hvbd_b_crashShutDn ||
    swc_HVSM_ConstB.LogicalOperator1 || hvbd_b_CampModeFb ||
    swc_HVSM_ARID_DEF.LogicalOperator36);

  /* Outputs for Atomic SubSystem: '<S98>/SR_latch' */
  rtb_LogicalOperator3_bd = swc_HVSM_SR_latch
    (swc_HVSM_ARID_DEF.DataTypeConversion68, rtb_LogicalOperator_e,
     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_c);

  /* End of Outputs for SubSystem: '<S98>/SR_latch' */

  /* SignalConversion generated from: '<S98>/SR_latch' */
  hvbd_b_startReq = rtb_LogicalOperator3_bd;

  /* Logic: '<S90>/Logical Operator4' incorporates:
   *  Constant: '<S204>/Constant'
   *  Constant: '<S208>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion42'
   *  DataTypeConversion: '<Root>/Data Type Conversion50'
   *  DataTypeConversion: '<Root>/Data Type Conversion51'
   *  DataTypeConversion: '<Root>/Data Type Conversion54'
   *  DataTypeConversion: '<Root>/Data Type Conversion56'
   *  Logic: '<S90>/Logical Operator'
   *  Logic: '<S90>/Logical Operator2'
   *  Logic: '<S90>/Logical Operator7'
   *  RelationalOperator: '<S90>/Relational Operator2'
   *  RelationalOperator: '<S90>/Relational Operator3'
   *  RelationalOperator: '<S90>/Relational Operator4'
   *  RelationalOperator: '<S90>/Relational Operator5'
   *  RelationalOperator: '<S90>/Relational Operator6'
   */
  hvbd_b_hvDvcShutDnCmplt = ((swc_HVSM_ConstB.LogicalOperator5 ||
    (swc_HVSM_ARID_DEF.DataTypeConversion50 == McuSts_NOTREADY)) &&
    (swc_HVSM_ConstB.LogicalOperator6_k ||
     (swc_HVSM_ARID_DEF.DataTypeConversion51 == McuSts_NOTREADY)) &&
    (swc_HVSM_ARID_DEF.DataTypeConversion54 == McuSts_NOTREADY) &&
    (swc_HVSM_ARID_DEF.DataTypeConversion56 == McuSts_NOTREADY) &&
    (swc_HVSM_ARID_DEF.DataTypeConversion42 != McuSts_READY) &&
    (!swc_HVSM_ARID_DEF.DataTypeConversion96));

  /* If: '<S209>/If' incorporates:
   *  Constant: '<S209>/Constant'
   */
  if (swc_HVSM_ARID_DEF.DataTypeConversion32 >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S209>/pos' incorporates:
     *  ActionPort: '<S211>/Action Port'
     */
    swc_HVSM_pos(swc_HVSM_ARID_DEF.DataTypeConversion32, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S209>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S209>/neg' incorporates:
     *  ActionPort: '<S210>/Action Port'
     */
    swc_HVSM_neg(swc_HVSM_ARID_DEF.DataTypeConversion32, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S209>/neg' */
  }

  /* End of If: '<S209>/If' */

  /* Logic: '<S90>/Logical Operator1' incorporates:
   *  Constant: '<S90>/Constant'
   *  Constant: '<S90>/Constant1'
   *  Logic: '<S90>/Logical Operator3'
   *  RelationalOperator: '<S90>/Relational Operator19'
   */
  hvbd_b_hvShutDnCmplt = ((swchvsm_hvbc_b_notUseHvBusSts ||
    hvbd_b_hvDvcShutDnCmplt) && (rtb_Merge < hvbc_i_bmsCurrent_A));

  /* Logic: '<S93>/Logical Operator1' */
  hvbd_b_brpEpsSlfChkOk = (swc_HVSM_ARID_DEF.DataTypeConversion58 &&
    swc_HVSM_ARID_DEF.DataTypeConversion61);

  /* RelationalOperator: '<S92>/Relational Operator2' incorporates:
   *  Constant: '<S225>/Constant'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_RelationalOperator2_j = (swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_d !=
    PmmStatus_LVCUTREQUEST);

  /* Outputs for Atomic SubSystem: '<S92>/SR_latch' */
  rtb_LogicalOperator3_d = swc_HVSM_SR_latch
    (swc_HVSM_ARID_DEF.DataTypeConversion34, rtb_RelationalOperator2_j,
     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_o);

  /* End of Outputs for SubSystem: '<S92>/SR_latch' */

  /* Outputs for Atomic SubSystem: '<S92>/SR_latch1' */
  rtb_LogicalOperator3_hg = swc_HVSM_SR_latch
    (swc_HVSM_ARID_DEF.DataTypeConversion37, rtb_RelationalOperator2_j,
     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch1_l);

  /* End of Outputs for SubSystem: '<S92>/SR_latch1' */

  /* Outputs for Atomic SubSystem: '<S92>/SR_latch3' */
  rtb_LogicalOperator3_c3 = swc_HVSM_SR_latch
    (swc_HVSM_ARID_DEF.DataTypeConversion89, rtb_RelationalOperator2_j,
     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch3);

  /* End of Outputs for SubSystem: '<S92>/SR_latch3' */

  /* Outputs for Atomic SubSystem: '<S92>/SR_latch4' */
  rtb_LogicalOperator3_hb = swc_HVSM_SR_latch
    (swc_HVSM_ARID_DEF.DataTypeConversion74, rtb_RelationalOperator2_j,
     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch4);

  /* End of Outputs for SubSystem: '<S92>/SR_latch4' */

  /* Logic: '<S92>/Logical Operator3' */
  hvbd_b_LvSysCutOffAlw = (rtb_LogicalOperator3_d && rtb_LogicalOperator3_hg &&
    rtb_LogicalOperator3_c3 && rtb_LogicalOperator3_hb);

  /* UnitDelay: '<S5>/Unit Delay' */
  swc_HVSM_ARID_DEF.hvbd_b_tmOutFlgDly = swc_HVSM_ARID_DEF.UnitDelay_DSTATE_j;

  /* RelationalOperator: '<S5>/Relational Operator3' incorporates:
   *  Constant: '<S5>/Constant5'
   */
  swc_HVSM_ARID_DEF.RelationalOperator3_a =
    (swc_HVSM_ARID_DEF.DataTypeConversion27 <= obcc_v_ChargerPlugThr_kph);

  /* CCaller: '<S5>/C Caller' */
  hvsm_hvbd_b_nmWkUp = mBSW_NmWkUp();

  /* Logic: '<S5>/Logical Operator3' */
  hvsm_hvbd_b_nmRdySlp = !hvsm_hvbd_b_nmWkUp;

  /* RelationalOperator: '<S5>/Relational Operator6' incorporates:
   *  Constant: '<S85>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion126'
   */
  swc_HVSM_ARID_DEF.RelationalOperator6_j =
    (swc_HVSM_ARID_DEF.DataTypeConversion126 == BrakePedalStatus_PRESSED);

  /* Switch: '<S5>/Switch3' incorporates:
   *  Constant: '<S5>/Constant7'
   *  Inport generated from: '<Root>/In Bus Element172'
   */
  if (swchvsm_vsmc_b_enaPTReadyVehRun) {
    swc_HVSM_ARID_DEF.Switch3 =
      Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_VehRunRaw();
  } else {
    swc_HVSM_ARID_DEF.Switch3 = swc_HVSM_ARID_DEF.DataTypeConversion3;
  }

  /* End of Switch: '<S5>/Switch3' */

  /* RelationalOperator: '<S302>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S302>/Delay Input1'
   *
   * Block description for '<S302>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_h = (swc_HVSM_ARID_DEF.DelayInput1_DSTATE > 0.0);

  /* Outputs for Atomic SubSystem: '<S100>/turnOFF_delay' */
  /* Constant: '<S100>/Constant10' incorporates:
   *  Constant: '<S100>/Constant8'
   */
  rtb_flg_out_o = swc_HVSM_turnOFF_delay(rtb_FixPtRelationalOperator_h,
    hvbc_s_FidVehFltLvl3BTmOut_s, ((float32)HVB_TASK_INTERVAL_S),
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay_c);

  /* End of Outputs for SubSystem: '<S100>/turnOFF_delay' */

  /* Logic: '<S100>/Logical Operator' incorporates:
   *  RelationalOperator: '<S303>/FixPt Relational Operator'
   *  UnitDelay: '<S303>/Delay Input1'
   *
   * Block description for '<S303>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator_l = (swc_HVSM_ConstB.LogicalOperator1_d || ((sint32)
    rtb_flg_out_o < (sint32)swc_HVSM_ARID_DEF.DelayInput1_DSTATE_g));

  /* Outputs for Atomic SubSystem: '<S100>/SR_latch1' */
  /* Constant: '<S100>/Constant9' */
  rtb_LogicalOperator3_hb = swc_HVSM_SR_latch(rtb_LogicalOperator_l, false,
    &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of Outputs for SubSystem: '<S100>/SR_latch1' */

  /* Switch: '<S100>/Switch' incorporates:
   *  Constant: '<S100>/Constant1'
   *  Constant: '<S100>/Constant3'
   *  Switch: '<S100>/Switch1'
   */
  if (hvbc_b_FidVehFltLvl3_ovrdflg) {
    hvbd_b_FidVehFltLvl3HvOff = rtb_LogicalOperator3_hb;
  } else if (hvbc_b_FidVehFltLvl32_ovrdflg) {
    /* Switch: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant4'
     */
    hvbd_b_FidVehFltLvl3HvOff = hvbc_b_FidVehFltLvl3_ovrdval;
  } else {
    /* Switch: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant5'
     *  Inport generated from: '<Root>/In Bus Element80'
     *  Logic: '<S100>/Logical Operator2'
     *  RelationalOperator: '<S100>/Relational Operator3'
     */
    hvbd_b_FidVehFltLvl3HvOff =
      (Rte_IRead_swc_HVSM_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() &&
       (swc_HVSM_ARID_DEF.DataTypeConversion27 <= obcc_v_VehLvl32FltThr_kph));
  }

  /* End of Switch: '<S100>/Switch' */

  /* Logic: '<S5>/Logical Operator9' incorporates:
   *  RelationalOperator: '<S80>/FixPt Relational Operator'
   *  RelationalOperator: '<S81>/FixPt Relational Operator'
   *  RelationalOperator: '<S82>/FixPt Relational Operator'
   *  UnitDelay: '<S80>/Delay Input1'
   *  UnitDelay: '<S81>/Delay Input1'
   *  UnitDelay: '<S82>/Delay Input1'
   *
   * Block description for '<S80>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S81>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S82>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator9_i = (((sint32)swc_HVSM_ARID_DEF.DataTypeConversion24 >
    (sint32)swc_HVSM_ARID_DEF.DelayInput1_DSTATE_ky) || ((sint32)
    swc_HVSM_ARID_DEF.DataTypeConversion16 > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_c) ||
    (swc_HVSM_ARID_DEF.DataTypeConversion210 >
     swc_HVSM_ARID_DEF.DelayInput1_DSTATE_p));

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch1' */
  rtb_LogicalOperator3_c = swc_HVSM_SR_latch
    (swc_HVSM_ARID_DEF.DataTypeConversion70, rtb_LogicalOperator9_i,
     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch1_b);

  /* End of Outputs for SubSystem: '<S5>/SR_latch1' */

  /* SignalConversion generated from: '<S5>/SR_latch1' */
  hvbd_b_hvilOpenCfm = rtb_LogicalOperator3_c;

  /* RelationalOperator: '<S91>/Relational Operator2' incorporates:
   *  Constant: '<S215>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  swchvsm_hvbd_b_hvbChgEnd = (swc_HVSM_ARID_DEF.DataTypeConversion ==
    HVBattStatus_CHARGE_COMPLETE);

  /* Logic: '<S91>/Logical Operator7' incorporates:
   *  Constant: '<S212>/Constant'
   *  Constant: '<S216>/Constant'
   *  Constant: '<S217>/Constant'
   *  Constant: '<S218>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Logic: '<S91>/Logical Operator4'
   *  Logic: '<S91>/Logical Operator6'
   *  Logic: '<S91>/Logical Operator9'
   *  RelationalOperator: '<S91>/Relational Operator1'
   *  RelationalOperator: '<S91>/Relational Operator5'
   *  RelationalOperator: '<S91>/Relational Operator6'
   *  RelationalOperator: '<S91>/Relational Operator7'
   */
  swchvsm_hvbd_st_hvbRlyClsd = ((swc_HVSM_ARID_DEF.DataTypeConversion ==
    HVBattStatus_ACTIVE) || (swc_HVSM_ARID_DEF.DataTypeConversion15 &&
    swc_HVSM_ARID_DEF.DataTypeConversion16 &&
    ((swc_HVSM_ARID_DEF.DataTypeConversion == HVBattStatus_SLOW_CHARGE) ||
     (swc_HVSM_ARID_DEF.DataTypeConversion == HVBattStatus_FAST_CHARGE) ||
     (swc_HVSM_ARID_DEF.DataTypeConversion == HVBattStatus_HEATING))));

  /* Logic: '<S5>/Logical Operator7' incorporates:
   *  Constant: '<S5>/Constant9'
   *  RelationalOperator: '<S5>/Relational Operator2'
   */
  swc_HVSM_ARID_DEF.LogicalOperator7 = (swc_HVSM_ARID_DEF.DataTypeConversion87 &&
    (swc_HVSM_ARID_DEF.DataTypeConversion156 == 0.0F));

  /* RelationalOperator: '<S91>/Relational Operator4' incorporates:
   *  Constant: '<S214>/Constant'
   *  UnitDelay: '<S5>/Unit Delay7'
   */
  rtb_RelationalOperator4_p = (swc_HVSM_ARID_DEF.UnitDelay7_DSTATE ==
    PmmStatus_CHGBMSNEGCLOSE);

  /* Outputs for Atomic SubSystem: '<S91>/turnON_delay1' */
  /* Constant: '<S91>/Constant1' incorporates:
   *  Constant: '<S91>/t_step1'
   */
  swc_HVSM_turnON_delay(rtb_RelationalOperator4_p, swchvsm_hvbc_tm_hvbChgFltTm_s,
                        ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_gg,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay1_b);

  /* End of Outputs for SubSystem: '<S91>/turnON_delay1' */

  /* Logic: '<S91>/Logical Operator' incorporates:
   *  Constant: '<S213>/Constant'
   *  Constant: '<S219>/Constant'
   *  Constant: '<S220>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Logic: '<S91>/Logical Operator1'
   *  Logic: '<S91>/Logical Operator8'
   *  RelationalOperator: '<S91>/Relational Operator3'
   *  RelationalOperator: '<S91>/Relational Operator8'
   *  RelationalOperator: '<S91>/Relational Operator9'
   */
  rtb_LogicalOperator_a = (rtb_RelationalOperator4_p &&
    ((swc_HVSM_ARID_DEF.DataTypeConversion != HVBattStatus_SLOW_CHARGE) &&
     (swc_HVSM_ARID_DEF.DataTypeConversion != HVBattStatus_FAST_CHARGE) &&
     (swc_HVSM_ARID_DEF.DataTypeConversion != HVBattStatus_HEATING)));

  /* Outputs for Atomic SubSystem: '<S91>/turnON_delay' */
  /* Constant: '<S91>/Constant4' incorporates:
   *  Constant: '<S91>/t_step14'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator_a, swchvsm_hvbc_tm_hvbChgFltCfm_s,
                        ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_oi,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay_nu);

  /* End of Outputs for SubSystem: '<S91>/turnON_delay' */

  /* Logic: '<S91>/Logical Operator2' incorporates:
   *  Logic: '<S91>/Logical Operator3'
   */
  swchvsm_hvbd_b_hvbNoChgFlg = ((!rtb_flg_out_gg) && rtb_flg_out_oi);

  /* Logic: '<S91>/Logical Operator11' incorporates:
   *  Constant: '<S91>/Constant'
   */
  swchvsm_hvbd_b_hvbChging = ((((uint8)1U) != 0) &&
    (swc_HVSM_ARID_DEF.DataTypeConversion115 != 0));

  /* UnitDelay: '<S83>/Unit Delay1' */
  rtb_LogicalOperator1_l = swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_f;

  /* Switch: '<S83>/Switch3' incorporates:
   *  Constant: '<S189>/Constant'
   *  Constant: '<S83>/Constant8'
   *  Constant: '<S83>/Constant9'
   *  Logic: '<S83>/Logical Operator4'
   *  RelationalOperator: '<S189>/Compare'
   *  RelationalOperator: '<S192>/FixPt Relational Operator'
   *  UnitDelay: '<S192>/Delay Input1'
   *
   * Block description for '<S192>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((sint32)swc_HVSM_ARID_DEF.DataTypeConversion217 > (sint32)
       swc_HVSM_ARID_DEF.DelayInput1_DSTATE_os) &&
      (swc_HVSM_ARID_DEF.DataTypeConversion221 == 0.0)) {
    tmp = ((uint8)1U);
  } else {
    tmp = ((uint8)0U);
  }

  /* Switch: '<S144>/Switch2' incorporates:
   *  Sum: '<S83>/Sum'
   *  Switch: '<S83>/Switch3'
   *  UnitDelay: '<S83>/Unit Delay'
   */
  rtb_Switch1_i = (uint8)((uint32)tmp + swc_HVSM_ARID_DEF.UnitDelay_DSTATE_g);

  /* Switch: '<S83>/Switch1' incorporates:
   *  Constant: '<S188>/Constant'
   *  Logic: '<S83>/Logical Operator'
   *  RelationalOperator: '<S188>/Compare'
   *  RelationalOperator: '<S191>/FixPt Relational Operator'
   *  UnitDelay: '<S191>/Delay Input1'
   *  UnitDelay: '<S83>/Unit Delay1'
   *
   * Block description for '<S191>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if (((sint32)swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_f > (sint32)
       swc_HVSM_ARID_DEF.DelayInput1_DSTATE_d) || (rtb_Switch1_i >= ((uint8)2U)))
  {
    /* Switch: '<S83>/Switch1' incorporates:
     *  Constant: '<S83>/Constant1'
     */
    rtb_Switch1_i = ((uint8)0U);
  }

  /* End of Switch: '<S83>/Switch1' */

  /* DataTypeConversion: '<S83>/Data Type Conversion' */
  hvbd_b_dchaReq = (rtb_Switch1_i != 0);

  /* Logic: '<S83>/Logical Operator1' incorporates:
   *  Constant: '<S193>/Constant'
   *  Constant: '<S83>/Constant4'
   *  DataTypeConversion: '<Root>/Data Type Conversion54'
   *  RelationalOperator: '<S83>/Relational Operator1'
   *  RelationalOperator: '<S83>/Relational Operator4'
   */
  rtb_LogicalOperator1_n = ((swc_HVSM_ARID_DEF.DataTypeConversion54 ==
    McuSts_READY) && hvbd_b_dchaReq && (rtb_t_delay_on > hvbc_q_dchaAlwSoc_pct));

  /* RelationalOperator: '<S83>/Relational Operator7' incorporates:
   *  Constant: '<S83>/Constant7'
   */
  rtb_RelationalOperator7_g = (rtb_t_delay_on <= hvbc_q_220ACQuitSoc_pct);

  /* Outputs for Atomic SubSystem: '<S197>/turnON_delay1' */
  /* Constant: '<S197>/Constant7' incorporates:
   *  Constant: '<S197>/t_step1'
   */
  swc_HVSM_turnON_delay(rtb_RelationalOperator7_g, hvbc_tm_disChgSocLow_s,
                        ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_c,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay1_bs);

  /* End of Outputs for SubSystem: '<S197>/turnON_delay1' */

  /* Logic: '<S83>/Logical Operator7' */
  rtb_RelationalOperator8_b = (hvbd_b_fltShutDn || hvbd_b_emgyShutDn ||
    hvbd_b_crashShutDn);

  /* Logic: '<S83>/Logical Operator5' */
  rtb_FixPtRelationalOperator_p3 = (swc_HVSM_ARID_DEF.DataTypeConversion16 ||
    swc_HVSM_ARID_DEF.DataTypeConversion24);

  /* Logic: '<S83>/Logical Operator3' */
  rtb_LogicalOperator3 = !hvbd_b_dchaReq;

  /* Logic: '<S83>/Logical Operator11' incorporates:
   *  Constant: '<S194>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion54'
   *  RelationalOperator: '<S83>/Relational Operator2'
   *  UnitDelay: '<S83>/Unit Delay2'
   */
  rtb_LogicalOperator11_c = (swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_n &&
    (swc_HVSM_ARID_DEF.DataTypeConversion54 == McuSts_NOTREADY));

  /* Outputs for Atomic SubSystem: '<S196>/turnON_delay1' */
  /* Constant: '<S196>/Constant7' incorporates:
   *  Constant: '<S196>/t_step1'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator11_c, hvbc_tm_disChgDccUnWrk_s,
                        ((float32)HVB_TASK_INTERVAL_S), &rtb_flg_out_gn,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay1_l);

  /* End of Outputs for SubSystem: '<S196>/turnON_delay1' */

  /* Logic: '<S83>/Logical Operator10' */
  rtb_LogicalOperator10_d = !dccd_b_DCDCEnabled;

  /* CCaller: '<S190>/C Caller2' */
  rtb_CCaller2 = 0U;

  /* CCaller: '<S190>/C Caller2' incorporates:
   *  Constant: '<S190>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32896U), &rtb_CCaller2);

  /* Switch: '<S198>/Switch2' incorporates:
   *  Constant: '<S190>/DFC_ovrdflg'
   */
  if (hvbc_cesc_b_evtFaildV2XDchaSwt_ovrdflg) {
    /* Switch: '<S198>/Switch2' incorporates:
     *  Constant: '<S190>/DFC_ovrdval'
     */
    hvbd_cesd_b_V2XDchaSwt = hvbc_cesc_b_evtFaildV2XDchaSwt_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S190>/Bitwise AND' */
    rtb_CCaller2 &= ((uint8)1U);

    /* Switch: '<S198>/Switch2' incorporates:
     *  DataTypeConversion: '<S190>/Data Type Conversion'
     */
    hvbd_cesd_b_V2XDchaSwt = (rtb_CCaller2 != 0);
  }

  /* End of Switch: '<S198>/Switch2' */

  /* Logic: '<S83>/Logical Operator2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element73'
   *  Logic: '<S83>/Logical Operator6'
   *  Logic: '<S83>/Logical Operator7'
   *  Logic: '<S83>/Logical Operator9'
   */
  rtb_LogicalOperator2_d = (rtb_flg_out_c ||
    (!Rte_IRead_swc_HVSM_Step_vcsb_EGYM_egmd_b_obcEnbAllowFlg()) ||
    rtb_RelationalOperator8_b || (!rtb_FixPtRelationalOperator_p3) ||
    rtb_LogicalOperator3 || rtb_flg_out_gn || rtb_LogicalOperator10_d ||
    hvbd_cesd_b_V2XDchaSwt);

  /* Outputs for Atomic SubSystem: '<S83>/SR_latch' */
  rtb_LogicalOperator3_d = swc_HVSM_SR_latch(rtb_LogicalOperator1_n,
    rtb_LogicalOperator2_d, &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_h);

  /* End of Outputs for SubSystem: '<S83>/SR_latch' */

  /* Switch: '<S83>/Switch4' incorporates:
   *  Constant: '<S83>/Constant12'
   */
  if (hvbc_b_dchaOn_ovrdflg) {
    /* Switch: '<S83>/Switch4' incorporates:
     *  Constant: '<S83>/Constant11'
     */
    hvbd_b_dchaOn = hvbc_b_dchaOn_ovrdval;
  } else {
    /* Switch: '<S83>/Switch4' */
    hvbd_b_dchaOn = rtb_LogicalOperator3_d;
  }

  /* End of Switch: '<S83>/Switch4' */

  /* RelationalOperator: '<S77>/Compare' incorporates:
   *  Constant: '<S77>/Constant'
   */
  swc_HVSM_ARID_DEF.Compare = (swc_HVSM_ARID_DEF.DataTypeConversion225 == 2.0);

  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  Constant: '<S84>/Constant'
   *  UnitDelay: '<S5>/Unit Delay11'
   */
  swc_HVSM_ARID_DEF.RelationalOperator1_b =
    (swc_HVSM_ARID_DEF.UnitDelay11_DSTATE == DCDCMode_ACTIVE);

  /* Logic: '<S5>/Logical Operator18' incorporates:
   *  Constant: '<S84>/Constant'
   *  Constant: '<S87>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion54'
   *  RelationalOperator: '<S5>/Relational Operator1'
   *  RelationalOperator: '<S5>/Relational Operator14'
   *  RelationalOperator: '<S5>/Relational Operator5'
   *  UnitDelay: '<S5>/Unit Delay10'
   */
  rtb_LogicalOperator18_i = ((swc_HVSM_ARID_DEF.UnitDelay10_DSTATE ==
    DCDCMode_ACTIVE) && (swc_HVSM_ARID_DEF.DataTypeConversion54 ==
    McuSts_NOTREADY));

  /* Outputs for Atomic SubSystem: '<S5>/turnON_delay' */
  /* Constant: '<S5>/Constant12' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator18_i, hvbc_tm_dcdcEnFailChg_s,
                        ((float32)HVB_TASK_INTERVAL_S),
                        &swc_HVSM_ARID_DEF.flg_out,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay);

  /* End of Outputs for SubSystem: '<S5>/turnON_delay' */

  /* RelationalOperator: '<S5>/Relational Operator4' incorporates:
   *  Constant: '<S5>/Constant17'
   *  Inport generated from: '<Root>/In Bus Element170'
   */
  swc_HVSM_ARID_DEF.RelationalOperator4 =
    (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp() == ((uint8)1U));

  /* RelationalOperator: '<S5>/Relational Operator8' incorporates:
   *  Constant: '<S5>/Constant18'
   *  Inport generated from: '<Root>/BusElementIn8'
   */
  swc_HVSM_ARID_DEF.RelationalOperator8 =
    (Rte_IRead_swc_HVSM_Step_vcsb_ATAU_pmmd_b_ePTRelease_flg() == ((uint8)1U));

  /* RelationalOperator: '<S71>/Compare' incorporates:
   *  Constant: '<S71>/Constant'
   *  Inport generated from: '<Root>/BusElementIn7'
   */
  swc_HVSM_ARID_DEF.Compare_m =
    (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_bmsDlyDataUpldEnb() == ((uint8)1U));

  /* Chart: '<S89>/LdtNewPlatform' */
  swc_HVSM_LdtNewPlatform();

  /* Outputs for Atomic SubSystem: '<S5>/TimeOutManagement' */
  swc_HVSM_TimeOutManagement();

  /* End of Outputs for SubSystem: '<S5>/TimeOutManagement' */

  /* Switch: '<S61>/Switch12' incorporates:
   *  Constant: '<S116>/Constant'
   *  Constant: '<S117>/Constant'
   *  Constant: '<S61>/Constant27'
   *  Inport generated from: '<Root>/In Bus Element80'
   *  Logic: '<S61>/Logical Operator14'
   *  Logic: '<S61>/Logical Operator15'
   *  Logic: '<S61>/Logical Operator31'
   *  Logic: '<S61>/Logical Operator32'
   *  Logic: '<S61>/Logical Operator33'
   *  Logic: '<S61>/Logical Operator34'
   *  Logic: '<S61>/OR1'
   *  RelationalOperator: '<S61>/Relational Operator14'
   *  RelationalOperator: '<S61>/Relational Operator8'
   *  RelationalOperator: '<S61>/Relational Operator9'
   *  Switch: '<S61>/Switch11'
   *  Switch: '<S61>/Switch13'
   *  Switch: '<S61>/Switch14'
   *  Switch: '<S61>/Switch15'
   *  Switch: '<S61>/Switch16'
   *  Switch: '<S61>/Switch17'
   *  Switch: '<S61>/Switch22'
   *  Switch: '<S61>/Switch23'
   *  Switch: '<S99>/Switch'
   *  UnitDelay: '<S61>/Unit Delay3'
   *  UnitDelay: '<S61>/Unit Delay4'
   */
  if (rtb_LogicalOperator14_tmp_tmp) {
    /* Switch: '<S61>/Switch12' incorporates:
     *  Constant: '<S61>/Constant19'
     */
    rtb_CCaller2 = ((uint8)1U);
  } else if (rtb_LogicalOperator22) {
    /* Switch: '<S61>/Switch12' incorporates:
     *  Constant: '<S61>/Constant16'
     *  Switch: '<S61>/Switch13'
     */
    rtb_CCaller2 = ((uint8)2U);
  } else if (!rtb_LogicalOperator21) {
    /* Switch: '<S61>/Switch12' incorporates:
     *  Constant: '<S61>/Constant17'
     *  Switch: '<S61>/Switch11'
     *  Switch: '<S61>/Switch13'
     */
    rtb_CCaller2 = ((uint8)3U);
  } else if (rtb_flg_out_m4) {
    /* Switch: '<S61>/Switch12' incorporates:
     *  Constant: '<S61>/Constant20'
     *  Switch: '<S61>/Switch11'
     *  Switch: '<S61>/Switch13'
     *  Switch: '<S61>/Switch14'
     */
    rtb_CCaller2 = ((uint8)4U);
  } else if (rtb_flg_out_db) {
    /* Switch: '<S61>/Switch12' incorporates:
     *  Constant: '<S61>/Constant21'
     *  Switch: '<S61>/Switch11'
     *  Switch: '<S61>/Switch13'
     *  Switch: '<S61>/Switch14'
     *  Switch: '<S61>/Switch15'
     */
    rtb_CCaller2 = ((uint8)5U);
  } else if (Rte_IRead_swc_HVSM_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() ||
             (swc_HVSM_ARID_DEF.DataTypeConversion95 == ((uint8)13U)) ||
             (hvbd_e_tmOutSource == PmmStatus_DRVBMSNEGCLOSE)) {
    /* Switch: '<S61>/Switch16' incorporates:
     *  Constant: '<S61>/Constant22'
     *  Switch: '<S61>/Switch11'
     *  Switch: '<S61>/Switch12'
     *  Switch: '<S61>/Switch13'
     *  Switch: '<S61>/Switch14'
     *  Switch: '<S61>/Switch15'
     */
    rtb_CCaller2 = ((uint8)6U);
  } else if (hvbd_e_tmOutSource == PmmStatus_DCDCACT) {
    /* Switch: '<S61>/Switch17' incorporates:
     *  Constant: '<S61>/Constant23'
     *  Switch: '<S61>/Switch11'
     *  Switch: '<S61>/Switch12'
     *  Switch: '<S61>/Switch13'
     *  Switch: '<S61>/Switch14'
     *  Switch: '<S61>/Switch15'
     *  Switch: '<S61>/Switch16'
     */
    rtb_CCaller2 = ((uint8)7U);
  } else if ((swc_HVSM_ARID_DEF.UnitDelay3_DSTATE_h != 0) &&
             (!rtb_RelationalOperator25)) {
    /* Switch: '<S61>/Switch22' incorporates:
     *  Constant: '<S61>/Constant31'
     *  Switch: '<S61>/Switch11'
     *  Switch: '<S61>/Switch12'
     *  Switch: '<S61>/Switch13'
     *  Switch: '<S61>/Switch14'
     *  Switch: '<S61>/Switch15'
     *  Switch: '<S61>/Switch16'
     *  Switch: '<S61>/Switch17'
     */
    rtb_CCaller2 = ((uint8)8U);
  } else if ((swc_HVSM_ARID_DEF.UnitDelay4_DSTATE != 0) &&
             (!rtb_RelationalOperator13)) {
    /* Switch: '<S61>/Switch23' incorporates:
     *  Constant: '<S61>/Constant32'
     *  Switch: '<S61>/Switch11'
     *  Switch: '<S61>/Switch12'
     *  Switch: '<S61>/Switch13'
     *  Switch: '<S61>/Switch14'
     *  Switch: '<S61>/Switch15'
     *  Switch: '<S61>/Switch16'
     *  Switch: '<S61>/Switch17'
     *  Switch: '<S61>/Switch22'
     */
    rtb_CCaller2 = ((uint8)9U);
  } else {
    /* Switch: '<S61>/Switch12' incorporates:
     *  Constant: '<S61>/Constant30'
     *  Switch: '<S61>/Switch11'
     *  Switch: '<S61>/Switch13'
     *  Switch: '<S61>/Switch14'
     *  Switch: '<S61>/Switch15'
     *  Switch: '<S61>/Switch16'
     *  Switch: '<S61>/Switch17'
     *  Switch: '<S61>/Switch22'
     *  Switch: '<S61>/Switch23'
     */
    rtb_CCaller2 = ((uint8)0U);
  }

  /* End of Switch: '<S61>/Switch12' */

  /* Outputs for Enabled SubSystem: '<S61>/Subsystem3' incorporates:
   *  EnablePort: '<S128>/Enable'
   */
  if (hvbd_b_hvbHvOnReq) {
    swc_HVSM_ARID_DEF.Subsystem3_MODE = true;

    /* SignalConversion: '<S128>/Signal Conversion' */
    hvbd_st_hvbHvOnFailResult = rtb_CCaller2;
  } else if (swc_HVSM_ARID_DEF.Subsystem3_MODE) {
    /* Disable for SignalConversion: '<S128>/Signal Conversion' incorporates:
     *  Outport: '<S128>/Out1'
     */
    hvbd_st_hvbHvOnFailResult = ((uint8)0U);
    swc_HVSM_ARID_DEF.Subsystem3_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S61>/Subsystem3' */

  /* Switch: '<S141>/Switch2' incorporates:
   *  Constant: '<S131>/FID_ovrdflg'
   *  Constant: '<S131>/FID_ovrdval'
   */
  if (hvbc_b_HvONFailResult_ovrdflg) {
    tmp = hvbc_st_HvONFailResult_ovrdval;
  } else {
    tmp = hvbd_st_hvbHvOnFailResult;
  }

  /* CCaller: '<S131>/C Caller' incorporates:
   *  Switch: '<S141>/Switch2'
   */
  mBSW_SetHvONFailResult(tmp);

  /* Switch: '<S61>/Switch4' incorporates:
   *  Constant: '<S109>/Constant'
   *  Constant: '<S113>/Constant'
   *  Logic: '<S61>/Logical Operator4'
   *  RelationalOperator: '<S61>/Relational Operator1'
   *  RelationalOperator: '<S61>/Relational Operator2'
   *  Switch: '<S61>/Switch5'
   *  UnitDelay: '<S5>/Unit Delay13'
   */
  if (rtb_CCaller2 != 0) {
    /* Switch: '<S61>/Switch4' incorporates:
     *  Constant: '<S61>/Constant2'
     */
    rtb_Switch4 = ((uint8)3U);
  } else if ((rtb_UnitDelay13 == PmmStatus_STANDBYDRV) || (rtb_UnitDelay13 ==
              PmmStatus_STANDBYDRVCONV)) {
    /* Switch: '<S61>/Switch5' incorporates:
     *  Constant: '<S61>/Constant3'
     *  Switch: '<S61>/Switch4'
     */
    rtb_Switch4 = ((uint8)1U);
  } else {
    /* Switch: '<S61>/Switch4' incorporates:
     *  Constant: '<S61>/Constant1'
     *  Switch: '<S61>/Switch5'
     */
    rtb_Switch4 = ((uint8)2U);
  }

  /* End of Switch: '<S61>/Switch4' */

  /* Outputs for Enabled SubSystem: '<S61>/Subsystem1' incorporates:
   *  EnablePort: '<S126>/Enable'
   */
  if (hvbd_b_hvbHvOnReq) {
    swc_HVSM_ARID_DEF.Subsystem1_MODE = true;

    /* SignalConversion: '<S126>/Signal Conversion' */
    hvbd_st_hvbHvOnFlg = rtb_Switch4;
  } else if (swc_HVSM_ARID_DEF.Subsystem1_MODE) {
    /* Disable for SignalConversion: '<S126>/Signal Conversion' incorporates:
     *  Outport: '<S126>/mBSW_SetHvShutDnResult'
     */
    hvbd_st_hvbHvOnFlg = ((uint8)2U);
    swc_HVSM_ARID_DEF.Subsystem1_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S61>/Subsystem1' */

  /* Switch: '<S142>/Switch2' incorporates:
   *  Constant: '<S132>/FID_ovrdflg'
   */
  if (hvbc_b_hvOnResult_ovrdflg) {
    /* CCaller: '<S132>/C Caller' incorporates:
     *  Constant: '<S132>/FID_ovrdval'
     */
    rtb_CCaller = hvbc_st_hvOnResult_ovrdval;
  } else {
    /* CCaller: '<S132>/C Caller' */
    rtb_CCaller = hvbd_st_hvbHvOnFlg;
  }

  /* End of Switch: '<S142>/Switch2' */

  /* CCaller: '<S132>/C Caller' */
  mBSW_SetRoutineResult_03E1(&rtb_CCaller);

  /* Switch: '<S61>/Switch8' incorporates:
   *  Logic: '<S61>/Logical Operator11'
   *  Logic: '<S61>/Logical Operator13'
   *  Logic: '<S61>/Logical Operator27'
   *  Logic: '<S61>/Logical Operator28'
   *  Logic: '<S61>/Logical Operator29'
   *  Logic: '<S61>/Logical Operator30'
   *  Switch: '<S61>/Switch10'
   *  Switch: '<S61>/Switch18'
   *  Switch: '<S61>/Switch19'
   *  Switch: '<S61>/Switch9'
   *  UnitDelay: '<S61>/Unit Delay1'
   *  UnitDelay: '<S61>/Unit Delay2'
   */
  if (!swc_HVSM_ARID_DEF.DataTypeConversion24) {
    /* Switch: '<S61>/Switch8' incorporates:
     *  Constant: '<S61>/Constant9'
     */
    rtb_Switch4 = ((uint8)1U);
  } else if (rtb_LogicalOperator22) {
    /* Switch: '<S61>/Switch9' incorporates:
     *  Constant: '<S61>/Constant10'
     *  Switch: '<S61>/Switch8'
     */
    rtb_Switch4 = ((uint8)2U);
  } else if (!rtb_LogicalOperator21) {
    /* Switch: '<S61>/Switch10' incorporates:
     *  Constant: '<S61>/Constant14'
     *  Switch: '<S61>/Switch8'
     *  Switch: '<S61>/Switch9'
     */
    rtb_Switch4 = ((uint8)3U);
  } else if ((swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_j != 0) &&
             (!rtb_RelationalOperator25)) {
    /* Switch: '<S61>/Switch18' incorporates:
     *  Constant: '<S61>/Constant24'
     *  Switch: '<S61>/Switch10'
     *  Switch: '<S61>/Switch8'
     *  Switch: '<S61>/Switch9'
     */
    rtb_Switch4 = ((uint8)8U);
  } else if ((swc_HVSM_ARID_DEF.UnitDelay2_DSTATE != 0) &&
             (!rtb_RelationalOperator13)) {
    /* Switch: '<S61>/Switch19' incorporates:
     *  Constant: '<S61>/Constant25'
     *  Switch: '<S61>/Switch10'
     *  Switch: '<S61>/Switch18'
     *  Switch: '<S61>/Switch8'
     *  Switch: '<S61>/Switch9'
     */
    rtb_Switch4 = ((uint8)9U);
  } else {
    /* Switch: '<S61>/Switch8' incorporates:
     *  Constant: '<S61>/Constant15'
     *  Switch: '<S61>/Switch10'
     *  Switch: '<S61>/Switch18'
     *  Switch: '<S61>/Switch19'
     *  Switch: '<S61>/Switch9'
     */
    rtb_Switch4 = ((uint8)0U);
  }

  /* End of Switch: '<S61>/Switch8' */

  /* Outputs for Enabled SubSystem: '<S61>/Subsystem2' incorporates:
   *  EnablePort: '<S127>/Enable'
   */
  if (hvbd_b_hvbShutDnReq) {
    swc_HVSM_ARID_DEF.Subsystem2_MODE = true;

    /* SignalConversion: '<S127>/Signal Conversion' */
    hvbd_st_hvbShutDnFailResult = rtb_Switch4;
  } else if (swc_HVSM_ARID_DEF.Subsystem2_MODE) {
    /* Disable for SignalConversion: '<S127>/Signal Conversion' incorporates:
     *  Outport: '<S127>/Out1'
     */
    hvbd_st_hvbShutDnFailResult = ((uint8)0U);
    swc_HVSM_ARID_DEF.Subsystem2_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S61>/Subsystem2' */

  /* Switch: '<S143>/Switch2' incorporates:
   *  Constant: '<S133>/FID_ovrdflg'
   *  Constant: '<S133>/FID_ovrdval'
   */
  if (hvbc_b_hvShutDnFailResult_ovrdflg) {
    tmp = hvbc_st_hvShutDnFailResult_ovrdval;
  } else {
    tmp = hvbd_st_hvbShutDnFailResult;
  }

  /* CCaller: '<S133>/C Caller' incorporates:
   *  Switch: '<S143>/Switch2'
   */
  mBSW_SetHvShutDnFailResult(tmp);

  /* Switch: '<S61>/Switch2' incorporates:
   *  Constant: '<S112>/Constant'
   *  RelationalOperator: '<S61>/Relational Operator6'
   *  Switch: '<S61>/Switch3'
   *  UnitDelay: '<S5>/Unit Delay13'
   */
  if (rtb_Switch4 != 0) {
    /* Switch: '<S61>/Switch2' incorporates:
     *  Constant: '<S61>/Constant11'
     */
    rtb_Switch4 = ((uint8)3U);
  } else if (rtb_UnitDelay13 == PmmStatus_LVCUTWAIT) {
    /* Switch: '<S61>/Switch3' incorporates:
     *  Constant: '<S61>/Constant12'
     *  Switch: '<S61>/Switch2'
     */
    rtb_Switch4 = ((uint8)1U);
  } else {
    /* Switch: '<S61>/Switch2' incorporates:
     *  Constant: '<S61>/Constant'
     *  Switch: '<S61>/Switch3'
     */
    rtb_Switch4 = ((uint8)2U);
  }

  /* End of Switch: '<S61>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S61>/Subsystem' incorporates:
   *  EnablePort: '<S125>/Enable'
   */
  if (hvbd_b_hvbShutDnReq) {
    swc_HVSM_ARID_DEF.Subsystem_MODE = true;

    /* SignalConversion: '<S125>/Signal Conversion' */
    hvbd_st_hvbShutDnFlg = rtb_Switch4;
  } else if (swc_HVSM_ARID_DEF.Subsystem_MODE) {
    /* Disable for SignalConversion: '<S125>/Signal Conversion' incorporates:
     *  Outport: '<S125>/Out1'
     */
    hvbd_st_hvbShutDnFlg = ((uint8)2U);
    swc_HVSM_ARID_DEF.Subsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S61>/Subsystem' */

  /* Switch: '<S144>/Switch2' incorporates:
   *  Constant: '<S134>/FID_ovrdflg'
   */
  if (hvbc_b_hvShutDnResult_ovrdflg) {
    /* CCaller: '<S134>/C Caller' incorporates:
     *  Constant: '<S134>/FID_ovrdval'
     */
    rtb_CCaller_k = hvbc_st_hvShutDnResult_ovrdval;
  } else {
    /* CCaller: '<S134>/C Caller' */
    rtb_CCaller_k = hvbd_st_hvbShutDnFlg;
  }

  /* End of Switch: '<S144>/Switch2' */

  /* CCaller: '<S134>/C Caller' */
  mBSW_SetHvShutDnResult(&rtb_CCaller_k);

  /* Outputs for Atomic SubSystem: '<S61>/turnOFF_delay1' */
  /* Constant: '<S61>/Constant4' incorporates:
   *  Constant: '<S61>/t_step3'
   */
  swc_HVSM_turnOFF_delay1(hvbd_b_hvbShutDnReq, 0.4F, ((float32)
    HVB_TASK_INTERVAL_S), &rtb_flg_out_br,
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay1_n);

  /* End of Outputs for SubSystem: '<S61>/turnOFF_delay1' */

  /* Outputs for Atomic SubSystem: '<S61>/turnOFF_delay2' */
  /* Constant: '<S61>/Constant35' incorporates:
   *  Constant: '<S61>/t_step1'
   */
  swc_HVSM_turnOFF_delay1(hvbd_b_hvbHvOnReq, 0.4F, ((float32)HVB_TASK_INTERVAL_S),
    &rtb_flg_out_oh, &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay2_o);

  /* End of Outputs for SubSystem: '<S61>/turnOFF_delay2' */

  /* Switch: '<S61>/Switch20' incorporates:
   *  Switch: '<S61>/Switch21'
   */
  if (rtb_flg_out_br) {
    /* Switch: '<S61>/Switch20' incorporates:
     *  Constant: '<S61>/Constant26'
     */
    swc_HVSM_ARID_DEF.Switch20 = ((uint8)1U);
  } else if (rtb_flg_out_oh) {
    /* Switch: '<S61>/Switch21' incorporates:
     *  Constant: '<S61>/Constant28'
     *  Switch: '<S61>/Switch20'
     */
    swc_HVSM_ARID_DEF.Switch20 = ((uint8)2U);
  } else {
    /* Switch: '<S61>/Switch20' incorporates:
     *  Constant: '<S61>/Constant29'
     *  Switch: '<S61>/Switch21'
     */
    swc_HVSM_ARID_DEF.Switch20 = ((uint8)0U);
  }

  /* End of Switch: '<S61>/Switch20' */

  /* Switch: '<S61>/Switch24' incorporates:
   *  Constant: '<S103>/Constant'
   *  Constant: '<S104>/Constant'
   *  Logic: '<S61>/Logical Operator35'
   *  RelationalOperator: '<S103>/Compare'
   *  RelationalOperator: '<S104>/Compare'
   */
  if ((rtb_CCaller2 == ((uint8)8U)) || (rtb_CCaller2 == ((uint8)9U))) {
    /* Switch: '<S61>/Switch24' incorporates:
     *  Constant: '<S61>/Constant18'
     */
    swc_HVSM_ARID_DEF.Switch24 = ((uint8)3U);
  } else {
    /* Switch: '<S61>/Switch24' */
    swc_HVSM_ARID_DEF.Switch24 = rtb_CCaller2;
  }

  /* End of Switch: '<S61>/Switch24' */

  /* Logic: '<S61>/Logical Operator9' */
  rtb_LogicalOperator9_a = !hvbd_b_chgCablePlugged;

  /* If: '<S151>/If' incorporates:
   *  Constant: '<S151>/Constant'
   */
  if (swc_HVSM_ARID_DEF.DataTypeConversion32 >= 0.0F) {
    /* Outputs for IfAction SubSystem: '<S151>/pos' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    swc_HVSM_pos(swc_HVSM_ARID_DEF.DataTypeConversion32, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S151>/pos' */
  } else {
    /* Outputs for IfAction SubSystem: '<S151>/neg' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    swc_HVSM_neg(swc_HVSM_ARID_DEF.DataTypeConversion32, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S151>/neg' */
  }

  /* End of If: '<S151>/If' */

  /* Logic: '<S62>/Logical Operator4' incorporates:
   *  Constant: '<S62>/Constant'
   *  RelationalOperator: '<S62>/Relational Operator19'
   */
  hvbd_b_hvBusShutDwnCmpl = ((rtb_Merge < hvbc_i_bmsCurrent_A) ||
    swc_HVSM_ARID_DEF.DataTypeConversion19 || hvbd_b_crashShutDn);

  /* Logic: '<S63>/Logical Operator14' incorporates:
   *  Logic: '<S63>/Logical Operator17'
   *  RelationalOperator: '<S157>/FixPt Relational Operator'
   *  UnitDelay: '<S157>/Delay Input1'
   *  UnitDelay: '<S63>/Unit Delay3'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator14_j = (((sint32)hvbd_b_CampModeFb < (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_gg) || (rtb_LogicalOperator3_g &&
    swc_HVSM_ARID_DEF.UnitDelay3_DSTATE_p));

  /* Switch: '<S63>/Switch8' */
  if (rtb_LogicalOperator14_j) {
    /* Switch: '<S63>/Switch8' */
    rtb_CCaller2 = hvbd_st_CampModeFbFailrReason;
  } else {
    /* Switch: '<S63>/Switch8' incorporates:
     *  UnitDelay: '<S63>/Unit Delay'
     */
    rtb_CCaller2 = swc_HVSM_ARID_DEF.UnitDelay_DSTATE_c;
  }

  /* End of Switch: '<S63>/Switch8' */

  /* Outputs for Atomic SubSystem: '<S63>/turnOFF_delay2' */
  /* Constant: '<S63>/Constant10' incorporates:
   *  Constant: '<S63>/Constant9'
   */
  rtb_flg_out_f = swc_HVSM_turnOFF_delay(rtb_LogicalOperator14_j,
    hvbc_tm_CampFailrReason_s, 0.01F,
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay2_f);

  /* End of Outputs for SubSystem: '<S63>/turnOFF_delay2' */

  /* Switch: '<S63>/Switch' */
  if (rtb_flg_out_f) {
    /* Switch: '<S63>/Switch' */
    swc_HVSM_ARID_DEF.Switch = rtb_CCaller2;
  } else {
    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/Constant8'
     */
    swc_HVSM_ARID_DEF.Switch = ((uint8)0U);
  }

  /* End of Switch: '<S63>/Switch' */

  /* RelationalOperator: '<S64>/Relational Operator11' incorporates:
   *  Constant: '<S64>/Constant1'
   */
  rtb_RelationalOperator11_f = (swc_HVSM_ARID_DEF.DataTypeConversion99 ==
    ((uint8)3U));

  /* Logic: '<S5>/Logical Operator2' */
  rtb_LogicalOperator14_tmp_tmp = (hvbd_b_fltShutDn || hvbd_b_emgyShutDn ||
    hvbd_b_crashShutDn);

  /* Logic: '<S5>/Logical Operator4' */
  hvbd_b_vcuRdyToSlp = !hvbd_b_vcuWkUpCmdRaw;

  /* UnitDelay: '<S5>/Unit Delay4' */
  rtb_Switch4 = swc_HVSM_ARID_DEF.UnitDelay4_DSTATE_a;

  /* RelationalOperator: '<S231>/Relational Operator2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion64'
   *  RelationalOperator: '<S231>/Relational Operator3'
   */
  rtb_LogicalOperator22_tmp = swc_HVSM_ARID_DEF.DataTypeConversion64;

  /* Logic: '<S231>/Logical Operator1' incorporates:
   *  Constant: '<S231>/Constant'
   *  Constant: '<S238>/Constant'
   *  RelationalOperator: '<S231>/Relational Operator'
   *  RelationalOperator: '<S231>/Relational Operator2'
   */
  rtb_LogicalOperator22 = ((rtb_Switch4 == ((uint8)1U)) &&
    (rtb_LogicalOperator22_tmp != HVBRelayStatus_CLOSED));

  /* Logic: '<S231>/Logical Operator2' incorporates:
   *  Constant: '<S231>/Constant1'
   *  Constant: '<S231>/Constant7'
   *  Constant: '<S237>/Constant'
   *  Logic: '<S231>/Logical Operator4'
   *  RelationalOperator: '<S231>/Relational Operator1'
   *  RelationalOperator: '<S231>/Relational Operator3'
   *  RelationalOperator: '<S231>/Relational Operator4'
   */
  rtb_LogicalOperator21 = (((rtb_Switch4 == ((uint8)2U)) || (rtb_Switch4 ==
    ((uint8)3U))) && (rtb_LogicalOperator22_tmp != HVBRelayStatus_OPEN));

  /* Logic: '<S231>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S235>/FixPt Relational Operator'
   *  RelationalOperator: '<S236>/FixPt Relational Operator'
   *  UnitDelay: '<S235>/Delay Input1'
   *  UnitDelay: '<S236>/Delay Input1'
   *
   * Block description for '<S235>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S236>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator3_e = (((sint32)obcd_b_chargerPlugged > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_a) || ((sint32)
    swc_HVSM_ARID_DEF.DataTypeConversion24 > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_le));

  /* UnitDelay: '<S231>/Unit Delay' */
  rtb_UnitDelay_f = swc_HVSM_ARID_DEF.UnitDelay_DSTATE_p;

  /* Switch: '<S231>/Switch' */
  if (obcd_b_chargerPlugged) {
    /* Switch: '<S231>/Switch' incorporates:
     *  Constant: '<S231>/Constant5'
     */
    rtb_Switch = hvbc_tm_chrgRlyTimeOut_s;
  } else {
    /* Switch: '<S231>/Switch' incorporates:
     *  Constant: '<S231>/Constant2'
     */
    rtb_Switch = hvbc_tm_dischRlyTimeOut_s;
  }

  /* End of Switch: '<S231>/Switch' */

  /* Outputs for Atomic SubSystem: '<S231>/turnON_delay' */
  /* Constant: '<S231>/Constant4' */
  swc_HVSM_turnON_delay(rtb_UnitDelay_f, rtb_Switch, ((float32)
    HVB_TASK_INTERVAL_S), &rtb_flg_out_b5,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay_l);

  /* End of Outputs for SubSystem: '<S231>/turnON_delay' */

  /* Outputs for Atomic SubSystem: '<S231>/turnOFF_delay' */
  /* Constant: '<S231>/Constant6' incorporates:
   *  Constant: '<S231>/Constant3'
   */
  rtb_flg_out_n = swc_HVSM_turnOFF_delay(rtb_LogicalOperator3_e,
    hvbc_tm_WakeUpOffDly_s, ((float32)HVB_TASK_INTERVAL_S),
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay_dh);

  /* End of Outputs for SubSystem: '<S231>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S231>/SR_latch' */
  rtb_LogicalOperator3_kw = swc_HVSM_SR_latch(rtb_flg_out_b5, rtb_flg_out_n,
    &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_d);

  /* End of Outputs for SubSystem: '<S231>/SR_latch' */

  /* SignalConversion generated from: '<S231>/SR_latch' */
  hvbd_b_assistPosRlyTmOut = rtb_LogicalOperator3_kw;

  /* UnitDelay: '<S5>/Unit Delay6' */
  rtb_Switch4 = swc_HVSM_ARID_DEF.UnitDelay6_DSTATE;

  /* RelationalOperator: '<S232>/Relational Operator2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion47'
   *  RelationalOperator: '<S232>/Relational Operator3'
   */
  rtb_LogicalOperator22_tmp = swc_HVSM_ARID_DEF.DataTypeConversion47;

  /* Logic: '<S232>/Logical Operator1' incorporates:
   *  Constant: '<S232>/Constant'
   *  Constant: '<S238>/Constant'
   *  RelationalOperator: '<S231>/Relational Operator2'
   *  RelationalOperator: '<S232>/Relational Operator'
   *  RelationalOperator: '<S232>/Relational Operator2'
   */
  rtb_RelationalOperator25 = ((rtb_Switch4 == ((uint8)1U)) &&
    (rtb_LogicalOperator22_tmp != HVBRelayStatus_CLOSED));

  /* Logic: '<S232>/Logical Operator2' incorporates:
   *  Constant: '<S232>/Constant1'
   *  Constant: '<S232>/Constant7'
   *  Constant: '<S237>/Constant'
   *  Logic: '<S232>/Logical Operator4'
   *  RelationalOperator: '<S231>/Relational Operator3'
   *  RelationalOperator: '<S232>/Relational Operator1'
   *  RelationalOperator: '<S232>/Relational Operator3'
   *  RelationalOperator: '<S232>/Relational Operator4'
   */
  rtb_RelationalOperator13 = (((rtb_Switch4 == ((uint8)2U)) || (rtb_Switch4 ==
    ((uint8)3U))) && (rtb_LogicalOperator22_tmp != HVBRelayStatus_OPEN));

  /* Logic: '<S232>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S244>/FixPt Relational Operator'
   *  RelationalOperator: '<S245>/FixPt Relational Operator'
   *  UnitDelay: '<S244>/Delay Input1'
   *  UnitDelay: '<S245>/Delay Input1'
   *
   * Block description for '<S244>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S245>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator3_p = (((sint32)obcd_b_chargerPlugged > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_ct) || ((sint32)
    swc_HVSM_ARID_DEF.DataTypeConversion24 > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_j));

  /* UnitDelay: '<S232>/Unit Delay' */
  rtb_UnitDelay_fj = swc_HVSM_ARID_DEF.UnitDelay_DSTATE_cp;

  /* Switch: '<S232>/Switch' */
  if (obcd_b_chargerPlugged) {
    /* Switch: '<S232>/Switch' incorporates:
     *  Constant: '<S232>/Constant5'
     */
    rtb_Switch_e = hvbc_tm_chrgRlyTimeOut_s;
  } else {
    /* Switch: '<S232>/Switch' incorporates:
     *  Constant: '<S232>/Constant2'
     */
    rtb_Switch_e = hvbc_tm_dischRlyTimeOut_s;
  }

  /* End of Switch: '<S232>/Switch' */

  /* Outputs for Atomic SubSystem: '<S232>/turnON_delay' */
  /* Constant: '<S232>/Constant4' */
  swc_HVSM_turnON_delay(rtb_UnitDelay_fj, rtb_Switch_e, ((float32)
    HVB_TASK_INTERVAL_S), &rtb_flg_out_pz,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay_j);

  /* End of Outputs for SubSystem: '<S232>/turnON_delay' */

  /* Outputs for Atomic SubSystem: '<S232>/turnOFF_delay' */
  /* Constant: '<S232>/Constant6' incorporates:
   *  Constant: '<S232>/Constant3'
   */
  rtb_flg_out_g = swc_HVSM_turnOFF_delay(rtb_LogicalOperator3_p,
    hvbc_tm_WakeUpOffDly_s, ((float32)HVB_TASK_INTERVAL_S),
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay_d);

  /* End of Outputs for SubSystem: '<S232>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S232>/SR_latch' */
  rtb_LogicalOperator3_n = swc_HVSM_SR_latch(rtb_flg_out_pz, rtb_flg_out_g,
    &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_g);

  /* End of Outputs for SubSystem: '<S232>/SR_latch' */

  /* SignalConversion generated from: '<S232>/SR_latch' */
  hvbd_b_bmsNegRlyTmOut = rtb_LogicalOperator3_n;

  /* UnitDelay: '<S5>/Unit Delay5' */
  rtb_Switch4 = swc_HVSM_ARID_DEF.UnitDelay5_DSTATE;

  /* RelationalOperator: '<S233>/Relational Operator2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion48'
   *  RelationalOperator: '<S233>/Relational Operator3'
   */
  rtb_LogicalOperator22_tmp = swc_HVSM_ARID_DEF.DataTypeConversion48;

  /* Logic: '<S233>/Logical Operator1' incorporates:
   *  Constant: '<S233>/Constant'
   *  Constant: '<S238>/Constant'
   *  RelationalOperator: '<S231>/Relational Operator2'
   *  RelationalOperator: '<S233>/Relational Operator'
   *  RelationalOperator: '<S233>/Relational Operator2'
   */
  rtb_RelationalOperator8_b = ((rtb_Switch4 == ((uint8)1U)) &&
    (rtb_LogicalOperator22_tmp != HVBRelayStatus_CLOSED));

  /* Logic: '<S233>/Logical Operator2' incorporates:
   *  Constant: '<S233>/Constant1'
   *  Constant: '<S233>/Constant7'
   *  Constant: '<S237>/Constant'
   *  Logic: '<S233>/Logical Operator4'
   *  RelationalOperator: '<S231>/Relational Operator3'
   *  RelationalOperator: '<S233>/Relational Operator1'
   *  RelationalOperator: '<S233>/Relational Operator3'
   *  RelationalOperator: '<S233>/Relational Operator4'
   */
  rtb_FixPtRelationalOperator_p3 = (((rtb_Switch4 == ((uint8)2U)) ||
    (rtb_Switch4 == ((uint8)3U))) && (rtb_LogicalOperator22_tmp !=
    HVBRelayStatus_OPEN));

  /* Logic: '<S233>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S253>/FixPt Relational Operator'
   *  RelationalOperator: '<S254>/FixPt Relational Operator'
   *  UnitDelay: '<S253>/Delay Input1'
   *  UnitDelay: '<S254>/Delay Input1'
   *
   * Block description for '<S253>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S254>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator3_a = (((sint32)obcd_b_chargerPlugged > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_gt) || ((sint32)
    swc_HVSM_ARID_DEF.DataTypeConversion24 > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_pz));

  /* UnitDelay: '<S233>/Unit Delay' */
  rtb_UnitDelay_c = swc_HVSM_ARID_DEF.UnitDelay_DSTATE_f;

  /* Switch: '<S233>/Switch' */
  if (obcd_b_chargerPlugged) {
    /* Switch: '<S233>/Switch' incorporates:
     *  Constant: '<S233>/Constant5'
     */
    rtb_Switch_k = hvbc_tm_chrgRlyTimeOut_s;
  } else {
    /* Switch: '<S233>/Switch' incorporates:
     *  Constant: '<S233>/Constant2'
     */
    rtb_Switch_k = hvbc_tm_dischRlyTimeOut_s;
  }

  /* End of Switch: '<S233>/Switch' */

  /* Outputs for Atomic SubSystem: '<S233>/turnON_delay' */
  /* Constant: '<S233>/Constant4' */
  swc_HVSM_turnON_delay(rtb_UnitDelay_c, rtb_Switch_k, ((float32)
    HVB_TASK_INTERVAL_S), &rtb_flg_out_m,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay_n);

  /* End of Outputs for SubSystem: '<S233>/turnON_delay' */

  /* Outputs for Atomic SubSystem: '<S233>/turnOFF_delay' */
  /* Constant: '<S233>/Constant6' incorporates:
   *  Constant: '<S233>/Constant3'
   */
  rtb_flg_out_k = swc_HVSM_turnOFF_delay(rtb_LogicalOperator3_a,
    hvbc_tm_WakeUpOffDly_s, ((float32)HVB_TASK_INTERVAL_S),
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay_p);

  /* End of Outputs for SubSystem: '<S233>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S233>/SR_latch' */
  rtb_LogicalOperator3_he = swc_HVSM_SR_latch(rtb_flg_out_m, rtb_flg_out_k,
    &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_l);

  /* End of Outputs for SubSystem: '<S233>/SR_latch' */

  /* SignalConversion generated from: '<S233>/SR_latch' */
  hvbd_b_hcmNegRlyTmOut = rtb_LogicalOperator3_he;

  /* UnitDelay: '<S234>/Unit Delay' */
  rtb_UnitDelay_l = swc_HVSM_ARID_DEF.UnitDelay_DSTATE_pu;

  /* Switch: '<S234>/Switch' */
  if (obcd_b_chargerPlugged) {
    /* Switch: '<S234>/Switch' incorporates:
     *  Constant: '<S234>/Constant5'
     */
    rtb_Switch_j = hvbc_tm_chrgRlyTimeOut_s;
  } else {
    /* Switch: '<S234>/Switch' incorporates:
     *  Constant: '<S234>/Constant2'
     */
    rtb_Switch_j = hvbc_tm_dischRlyTimeOut_s;
  }

  /* End of Switch: '<S234>/Switch' */

  /* Outputs for Atomic SubSystem: '<S234>/turnON_delay' */
  /* Constant: '<S234>/Constant4' */
  swc_HVSM_turnON_delay(rtb_UnitDelay_l, rtb_Switch_j, ((float32)
    HVB_TASK_INTERVAL_S), &rtb_flg_out_j,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay_g);

  /* End of Outputs for SubSystem: '<S234>/turnON_delay' */

  /* Logic: '<S234>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S262>/FixPt Relational Operator'
   *  RelationalOperator: '<S263>/FixPt Relational Operator'
   *  UnitDelay: '<S262>/Delay Input1'
   *  UnitDelay: '<S263>/Delay Input1'
   *
   * Block description for '<S262>/Delay Input1':
   *
   *  Store in Global RAM
   *
   * Block description for '<S263>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator3_hu = (((sint32)obcd_b_chargerPlugged > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_mz) || ((sint32)
    swc_HVSM_ARID_DEF.DataTypeConversion24 > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_mk));

  /* Outputs for Atomic SubSystem: '<S234>/turnOFF_delay' */
  /* Constant: '<S234>/Constant6' incorporates:
   *  Constant: '<S234>/Constant3'
   */
  rtb_flg_out_p = swc_HVSM_turnOFF_delay(rtb_LogicalOperator3_hu,
    hvbc_tm_WakeUpOffDly_s, ((float32)HVB_TASK_INTERVAL_S),
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay_g);

  /* End of Outputs for SubSystem: '<S234>/turnOFF_delay' */

  /* Outputs for Atomic SubSystem: '<S234>/SR_latch' */
  rtb_LogicalOperator3_j = swc_HVSM_SR_latch(rtb_flg_out_j, rtb_flg_out_p,
    &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_me);

  /* End of Outputs for SubSystem: '<S234>/SR_latch' */

  /* SignalConversion generated from: '<S234>/SR_latch' */
  hvbd_b_mainPosRlyTmOut = rtb_LogicalOperator3_j;

  /* Logic: '<S94>/Logical Operator' */
  hvbd_b_rlyTmOut = (hvbd_b_mainPosRlyTmOut || hvbd_b_assistPosRlyTmOut ||
                     hvbd_b_bmsNegRlyTmOut || hvbd_b_hcmNegRlyTmOut);

  /* UnitDelay: '<S5>/Unit Delay3' */
  rtb_Switch4 = swc_HVSM_ARID_DEF.UnitDelay3_DSTATE_b;

  /* RelationalOperator: '<S234>/Relational Operator2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion76'
   *  RelationalOperator: '<S234>/Relational Operator3'
   */
  rtb_LogicalOperator22_tmp = swc_HVSM_ARID_DEF.DataTypeConversion76;

  /* Logic: '<S234>/Logical Operator1' incorporates:
   *  Constant: '<S234>/Constant8'
   *  Constant: '<S238>/Constant'
   *  RelationalOperator: '<S231>/Relational Operator2'
   *  RelationalOperator: '<S234>/Relational Operator'
   *  RelationalOperator: '<S234>/Relational Operator2'
   */
  rtb_LogicalOperator3 = ((rtb_Switch4 == ((uint8)1U)) &&
    (rtb_LogicalOperator22_tmp != HVBRelayStatus_CLOSED));

  /* Logic: '<S234>/Logical Operator2' incorporates:
   *  Constant: '<S234>/Constant1'
   *  Constant: '<S234>/Constant7'
   *  Constant: '<S237>/Constant'
   *  Logic: '<S234>/Logical Operator4'
   *  RelationalOperator: '<S231>/Relational Operator3'
   *  RelationalOperator: '<S234>/Relational Operator1'
   *  RelationalOperator: '<S234>/Relational Operator3'
   *  RelationalOperator: '<S234>/Relational Operator4'
   */
  rtb_LogicalOperator10_d = (((rtb_Switch4 == ((uint8)2U)) || (rtb_Switch4 ==
    ((uint8)3U))) && (rtb_LogicalOperator22_tmp != HVBRelayStatus_OPEN));

  /* Switch: '<S95>/Switch11' incorporates:
   *  Constant: '<S95>/Constant42'
   *  Constant: '<S95>/Constant43'
   */
  if (hvbc_b_WriteBookChrgnTarVal_ovrdflg) {
    rtb_t_delay_on = fmodf(truncf(hvbc_b_WriteBookChrgnTarVal_ovrdval), 65536.0F);

    /* Switch: '<S95>/Switch11' incorporates:
     *  Constant: '<S95>/Constant43'
     */
    rtb_Switch11 = (uint16)(rtb_t_delay_on < 0.0F ? (sint32)(uint16)-(sint16)
      (uint16)-rtb_t_delay_on : (sint32)(uint16)rtb_t_delay_on);
  } else {
    /* Switch: '<S95>/Switch11' incorporates:
     *  DataTypeConversion: '<S95>/Data Type Conversion'
     */
    rtb_Switch11 = hvbd_pct_BookChrgnTarValFb;
  }

  /* End of Switch: '<S95>/Switch11' */

  /* CCaller: '<S95>/C Caller10' */
  mBSW_NvmWrite_BookChrgnTarVal_eep(rtb_Switch11);

  /* Logic: '<S274>/Logical Operator3' incorporates:
   *  Constant: '<S95>/Constant19'
   *  Constant: '<S95>/Constant20'
   *  Logic: '<S95>/Logical Operator8'
   *  RelationalOperator: '<S95>/Relational Operator15'
   *  RelationalOperator: '<S95>/Relational Operator16'
   */
  rtb_LogicalOperator3_g = ((swc_HVSM_ARID_DEF.DataTypeConversion213 == ((uint8)
    1U)) || (swc_HVSM_ARID_DEF.DataTypeConversion216 == ((uint8)3U)));

  /* Logic: '<S95>/Logical Operator13' incorporates:
   *  Constant: '<S95>/Constant26'
   *  Logic: '<S95>/Logical Operator10'
   *  RelationalOperator: '<S95>/Relational Operator20'
   */
  rtb_LogicalOperator13_k = ((!rtb_LogicalOperator3_g) ||
    (swc_HVSM_ARID_DEF.DataTypeConversion224 == ((uint8)1U)));

  /* Logic: '<S95>/Logical Operator7' incorporates:
   *  Constant: '<S95>/Constant21'
   *  RelationalOperator: '<S95>/Relational Operator17'
   */
  rtb_LogicalOperator7_l = ((swc_HVSM_ARID_DEF.DataTypeConversion224 == ((uint8)
    0U)) && rtb_LogicalOperator3_g);

  /* Outputs for Atomic SubSystem: '<S276>/turnON_delay1' */
  /* Constant: '<S276>/Constant7' incorporates:
   *  Constant: '<S276>/t_step1'
   */
  swc_HVSM_turnON_delay(rtb_LogicalOperator7_l, 10.0F, ((float32)
    HVB_TASK_INTERVAL_S), &rtb_flg_out_b,
                        &swc_HVSM_ARID_DEF.ARID_DEF_turnON_delay1);

  /* End of Outputs for SubSystem: '<S276>/turnON_delay1' */

  /* Outputs for Atomic SubSystem: '<S95>/SR_latch2' */
  swc_HVSM_SR_latch1(rtb_flg_out_b, rtb_LogicalOperator13_k,
                     &rtb_LogicalOperator3_g,
                     &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch2);

  /* End of Outputs for SubSystem: '<S95>/SR_latch2' */

  /* Switch: '<S95>/Switch5' */
  if (rtb_LogicalOperator3_g) {
    /* Switch: '<S95>/Switch5' incorporates:
     *  Constant: '<S95>/Constant22'
     */
    hvbd_st_RmChgCmdFailPmt = ((uint8)2U);
  } else {
    /* Switch: '<S95>/Switch5' incorporates:
     *  Constant: '<S95>/Constant23'
     */
    hvbd_st_RmChgCmdFailPmt = ((uint8)0U);
  }

  /* End of Switch: '<S95>/Switch5' */

  /* RelationalOperator: '<S96>/Relational Operator4' incorporates:
   *  RelationalOperator: '<S96>/Relational Operator1'
   *  RelationalOperator: '<S96>/Relational Operator2'
   *  RelationalOperator: '<S96>/Relational Operator3'
   *  RelationalOperator: '<S96>/Relational Operator5'
   *  UnitDelay: '<S5>/Unit Delay12'
   */
  rtb_LogicalOperator16_tmp = swc_HVSM_ARID_DEF.UnitDelay12_DSTATE;

  /* Logic: '<S96>/Logical Operator' incorporates:
   *  Constant: '<S283>/Constant'
   *  Constant: '<S284>/Constant'
   *  Constant: '<S285>/Constant'
   *  RelationalOperator: '<S96>/Relational Operator1'
   *  RelationalOperator: '<S96>/Relational Operator2'
   *  RelationalOperator: '<S96>/Relational Operator4'
   */
  rtb_LogicalOperator_b = ((rtb_LogicalOperator16_tmp == PmmStatus_STANDBYDRV) ||
    (rtb_LogicalOperator16_tmp == PmmStatus_CHARGE) ||
    (rtb_LogicalOperator16_tmp == PmmStatus_STANDBYDRVCONV));

  /* Logic: '<S96>/Logical Operator1' incorporates:
   *  Constant: '<S286>/Constant'
   *  Constant: '<S287>/Constant'
   *  RelationalOperator: '<S96>/Relational Operator3'
   *  RelationalOperator: '<S96>/Relational Operator5'
   */
  rtb_LogicalOperator1_h = ((rtb_LogicalOperator16_tmp ==
    PmmStatus_HVDEVICEDEACT) || (rtb_LogicalOperator16_tmp ==
    PmmStatus_HVDEVICEDEACTEMGY));

  /* Outputs for Atomic SubSystem: '<S96>/SR_latch1' */
  swc_HVSM_SR_latch1_f(rtb_LogicalOperator_b, rtb_LogicalOperator1_h,
                       &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch1_p);

  /* End of Outputs for SubSystem: '<S96>/SR_latch1' */

  /* SignalConversion: '<S5>/Signal Conversion' */
  swc_HVSM_ARID_DEF.hvbd_b_hvbIntelChgCmplt = swc_HVSM_ARID_DEF.IntelChgCmplt;

  /* SignalConversion: '<S5>/Signal Conversion1' */
  hvbd_b_hvbIntelChgExitReq = swc_HVSM_ARID_DEF.IntelChgExitReq;

  /* SignalConversion: '<S5>/Signal Conversion2' */
  swc_HVSM_ARID_DEF.swchvsm_eadd_e_inv2ModeTgtRaw = swc_HVSM_ARID_DEF.ElMacSts;

  /* SignalConversion: '<S5>/Signal Conversion3' */
  bmsd_e_modeTgt = swc_HVSM_ARID_DEF.BMSCtrlSts;

  /* Switch: '<S5>/Switch' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  if (hvbc_b_vcuWkUpOvrd) {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S5>/Constant3'
     */
    hvbd_b_vcuWkUpCmd = hvbc_b_vcuWkUpOvrdVal;
  } else {
    /* Switch: '<S5>/Switch' incorporates:
     *  Constant: '<S95>/Constant24'
     *  Constant: '<S95>/Constant25'
     *  Logic: '<S5>/Logical Operator1'
     *  Logic: '<S95>/Logical Operator11'
     *  RelationalOperator: '<S95>/Relational Operator18'
     *  RelationalOperator: '<S95>/Relational Operator19'
     */
    hvbd_b_vcuWkUpCmd = (hvbd_b_vcuWkUpCmdRaw ||
                         ((swc_HVSM_ARID_DEF.DataTypeConversion213 == ((uint8)1U))
                          || (swc_HVSM_ARID_DEF.DataTypeConversion216 == ((uint8)
      3U))));
  }

  /* End of Switch: '<S5>/Switch' */

  /* UnitDelay: '<S5>/Unit Delay8' */
  hvbd_b_fltPwrShutDn = swc_HVSM_ARID_DEF.UnitDelay8_DSTATE_g;

  /* CCaller: '<S79>/C Caller2' */
  rtb_Switch4 = 0U;

  /* CCaller: '<S79>/C Caller2' incorporates:
   *  Constant: '<S79>/DFC_Constant1'
   */
  Dem_GetEventStatus(((uint16)32914U), &rtb_Switch4);

  /* Switch: '<S187>/Switch2' incorporates:
   *  Constant: '<S79>/DFC_ovrdflg'
   */
  if (hvbc_cesc_b_evtFaildCrashEvent_ovrdflg) {
    /* Switch: '<S187>/Switch2' incorporates:
     *  Constant: '<S79>/DFC_ovrdval'
     */
    hvbd_cesd_b_CrashEvent = hvbc_cesc_b_evtFaildCrashEvent_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S79>/Bitwise AND' */
    rtb_Switch4 &= ((uint8)32U);

    /* Switch: '<S187>/Switch2' incorporates:
     *  DataTypeConversion: '<S79>/Data Type Conversion'
     */
    hvbd_cesd_b_CrashEvent = (rtb_Switch4 != 0);
  }

  /* End of Switch: '<S187>/Switch2' */

  /* Update for UnitDelay: '<S5>/Unit Delay13' */
  swc_HVSM_ARID_DEF.UnitDelay13_DSTATE = hvbd_e_PmmStatus;

  /* Update for UnitDelay: '<S64>/Unit Delay2' */
  swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_m = hvbd_b_chargeReq;

  /* Update for UnitDelay: '<S171>/Delay Input1'
   *
   * Block description for '<S171>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_k = rtb_UnitDelay2_f;

  /* Update for UnitDelay: '<S95>/Unit Delay2' */
  swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_g = hvbd_b_ResChgRouterSwt;

  /* Update for UnitDelay: '<S95>/Unit Delay1' */
  swc_HVSM_ARID_DEF.UnitDelay1_DSTATE = bmsd_e_modeTgt;

  /* Update for UnitDelay: '<S272>/Delay Input1'
   *
   * Block description for '<S272>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_l = rtb_LogicalOperator12;

  /* Update for UnitDelay: '<S95>/Unit Delay8' */
  swc_HVSM_ARID_DEF.UnitDelay8_DSTATE = swc_HVSM_ARID_DEF.DataTypeConversion216;

  /* Update for UnitDelay: '<S95>/Unit Delay5' incorporates:
   *  Constant: '<S95>/Constant32'
   */
  swc_HVSM_ARID_DEF.UnitDelay5_DSTATE_l = true;

  /* Update for UnitDelay: '<S95>/Unit Delay3' */
  swc_HVSM_ARID_DEF.UnitDelay3_DSTATE = hvbd_pct_BookChrgnTarValFb;

  /* Update for UnitDelay: '<S107>/Delay Input1'
   *
   * Block description for '<S107>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_i = hvbd_b_hvbShutDnReq;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_l = hvbd_st_ptRdyInd;

  /* Update for UnitDelay: '<S105>/Delay Input1'
   *
   * Block description for '<S105>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_mi =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S108>/Delay Input1'
   *
   * Block description for '<S108>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_e = hvbd_b_hvbHvOnReq;

  /* Update for UnitDelay: '<S106>/Delay Input1'
   *
   * Block description for '<S106>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_ea =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S64>/Unit Delay1' */
  swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_a = hvbd_b_chargeReq;

  /* Update for UnitDelay: '<S291>/Delay Input1'
   *
   * Block description for '<S291>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_kb =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S63>/Unit Delay2' */
  swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_h = rtb_LogicalOperator2_eb;

  /* Update for UnitDelay: '<S158>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_ph = rtb_LogicalOperator3_g_tmp;

  /* Update for UnitDelay: '<S63>/Unit Delay1' */
  swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_l = rtb_RelationalOperator2_bz;

  /* Update for UnitDelay: '<S5>/Unit Delay2' */
  swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_d = hvbd_e_PmmStatus;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_j = hvbd_b_tmOutFlg;

  /* Update for UnitDelay: '<S302>/Delay Input1'
   *
   * Block description for '<S302>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE = 0.0;

  /* Update for UnitDelay: '<S303>/Delay Input1'
   *
   * Block description for '<S303>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_g = rtb_flg_out_o;

  /* Update for UnitDelay: '<S80>/Delay Input1'
   *
   * Block description for '<S80>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_ky =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S81>/Delay Input1'
   *
   * Block description for '<S81>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_c =
    swc_HVSM_ARID_DEF.DataTypeConversion16;

  /* Update for UnitDelay: '<S82>/Delay Input1'
   *
   * Block description for '<S82>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_p =
    swc_HVSM_ARID_DEF.DataTypeConversion210;

  /* Update for UnitDelay: '<S5>/Unit Delay7' */
  swc_HVSM_ARID_DEF.UnitDelay7_DSTATE = hvbd_e_PmmStatus;

  /* Update for UnitDelay: '<S83>/Unit Delay1' */
  swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_f = rtb_LogicalOperator2_d;

  /* Update for UnitDelay: '<S191>/Delay Input1'
   *
   * Block description for '<S191>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_d = rtb_LogicalOperator1_l;

  /* Update for UnitDelay: '<S192>/Delay Input1'
   *
   * Block description for '<S192>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_os =
    swc_HVSM_ARID_DEF.DataTypeConversion217;

  /* Update for UnitDelay: '<S83>/Unit Delay' */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_g = rtb_Switch1_i;

  /* Update for UnitDelay: '<S83>/Unit Delay2' */
  swc_HVSM_ARID_DEF.UnitDelay2_DSTATE_n = hvbd_b_dchaOn;

  /* Update for UnitDelay: '<S5>/Unit Delay11' */
  swc_HVSM_ARID_DEF.UnitDelay11_DSTATE = dccd_e_modeTgt;

  /* Update for UnitDelay: '<S5>/Unit Delay10' */
  swc_HVSM_ARID_DEF.UnitDelay10_DSTATE = dccd_e_modeTgt;

  /* Update for UnitDelay: '<S61>/Unit Delay3' */
  swc_HVSM_ARID_DEF.UnitDelay3_DSTATE_h = hvbd_st_ptRdyInd;

  /* Update for UnitDelay: '<S61>/Unit Delay4' */
  swc_HVSM_ARID_DEF.UnitDelay4_DSTATE = hvbd_st_ptRdyInd;

  /* Update for UnitDelay: '<S61>/Unit Delay1' */
  swc_HVSM_ARID_DEF.UnitDelay1_DSTATE_j = hvbd_st_ptRdyInd;

  /* Update for UnitDelay: '<S61>/Unit Delay2' */
  swc_HVSM_ARID_DEF.UnitDelay2_DSTATE = hvbd_st_ptRdyInd;

  /* Update for UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_gg = hvbd_b_CampModeFb;

  /* Update for UnitDelay: '<S63>/Unit Delay3' */
  swc_HVSM_ARID_DEF.UnitDelay3_DSTATE_p = rtb_LogicalOperator2_eb;

  /* Update for UnitDelay: '<S63>/Unit Delay' */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_c = rtb_CCaller2;

  /* Update for UnitDelay: '<S235>/Delay Input1'
   *
   * Block description for '<S235>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_a = obcd_b_chargerPlugged;

  /* Update for UnitDelay: '<S236>/Delay Input1'
   *
   * Block description for '<S236>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_le =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S5>/Unit Delay4' */
  swc_HVSM_ARID_DEF.UnitDelay4_DSTATE_a = hvbd_st_hvbAssiRlyPosClsReq;

  /* Update for UnitDelay: '<S231>/Unit Delay' incorporates:
   *  Logic: '<S231>/Logical Operator'
   */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_p = (rtb_LogicalOperator22 ||
    rtb_LogicalOperator21);

  /* Update for UnitDelay: '<S244>/Delay Input1'
   *
   * Block description for '<S244>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_ct = obcd_b_chargerPlugged;

  /* Update for UnitDelay: '<S245>/Delay Input1'
   *
   * Block description for '<S245>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_j =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S5>/Unit Delay6' */
  swc_HVSM_ARID_DEF.UnitDelay6_DSTATE = hvbd_st_hvbMaiRlyNegClsReq;

  /* Update for UnitDelay: '<S232>/Unit Delay' incorporates:
   *  Logic: '<S232>/Logical Operator'
   */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_cp = (rtb_RelationalOperator25 ||
    rtb_RelationalOperator13);

  /* Update for UnitDelay: '<S253>/Delay Input1'
   *
   * Block description for '<S253>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_gt = obcd_b_chargerPlugged;

  /* Update for UnitDelay: '<S254>/Delay Input1'
   *
   * Block description for '<S254>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_pz =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S5>/Unit Delay5' */
  swc_HVSM_ARID_DEF.UnitDelay5_DSTATE = hvbd_st_hcmMaiRlyNegClsReq;

  /* Update for UnitDelay: '<S233>/Unit Delay' incorporates:
   *  Logic: '<S233>/Logical Operator'
   */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_f = (rtb_RelationalOperator8_b ||
    rtb_FixPtRelationalOperator_p3);

  /* Update for UnitDelay: '<S234>/Unit Delay' incorporates:
   *  Logic: '<S234>/Logical Operator'
   */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_pu = (rtb_LogicalOperator3 ||
    rtb_LogicalOperator10_d);

  /* Update for UnitDelay: '<S262>/Delay Input1'
   *
   * Block description for '<S262>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_mz = obcd_b_chargerPlugged;

  /* Update for UnitDelay: '<S263>/Delay Input1'
   *
   * Block description for '<S263>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_mk =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S5>/Unit Delay3' */
  swc_HVSM_ARID_DEF.UnitDelay3_DSTATE_b = hvbd_st_hvbMaiRlyPosClsReq;

  /* Update for UnitDelay: '<S5>/Unit Delay12' */
  swc_HVSM_ARID_DEF.UnitDelay12_DSTATE = hvbd_e_PmmStatus;

  /* Update for UnitDelay: '<S5>/Unit Delay8' incorporates:
   *  Logic: '<S5>/Logical Operator2'
   */
  swc_HVSM_ARID_DEF.UnitDelay8_DSTATE_g = rtb_LogicalOperator14_tmp_tmp;
}

/* Output and update for atomic system: '<S4>/Get_FID_Enable' */
static void swc_HVSM_Get_FID_Enable(void)
{
  /* S-Function (fm_get_fidperm): '<S42>/S-Function' */
  swc_HVSM_ARID_DEF.GetEnable_g = 1;
}

/* System initialize for function-call system: '<S1>/EAD_ModeManagerMot2' */
static void swc_HV_EAD_ModeManagerMot2_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out_cr;

  /* SystemInitialize for Atomic SubSystem: '<S43>/turnOFF_delay' */
  swc_HVSM_turnOFF_delay_Init(&rtb_flg_out_cr);

  /* End of SystemInitialize for SubSystem: '<S43>/turnOFF_delay' */
}

/* Output and update for function-call system: '<S1>/EAD_ModeManagerMot2' */
static void swc_HVSM_EAD_ModeManagerMot2(void)
{
  /* local block i/o variables */
  boolean rtb_LogicalOperator2_lv;
  boolean rtb_RelationalOperator11_c;
  boolean rtb_LogicalOperator19;
  boolean rtb_flg_out_cr;
  boolean rtb_LogicalOperator3_l;
  boolean rtb_LogicalOperator1_pg;
  boolean rtb_LogicalOperator3;

  /* Logic: '<S41>/Logical Operator7' incorporates:
   *  Constant: '<S41>/Constant10'
   *  Constant: '<S46>/Constant'
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S50>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion25'
   *  DataTypeConversion: '<Root>/Data Type Conversion26'
   *  Logic: '<S41>/Logical Operator10'
   *  Logic: '<S41>/Logical Operator14'
   *  Logic: '<S41>/Logical Operator5'
   *  Logic: '<S41>/Logical Operator6'
   *  RelationalOperator: '<S41>/Relational Operator2'
   *  RelationalOperator: '<S41>/Relational Operator3'
   *  RelationalOperator: '<S41>/Relational Operator4'
   *  RelationalOperator: '<S41>/Relational Operator5'
   *  RelationalOperator: '<S41>/Relational Operator9'
   */
  eadd_b_ead2Avail = ((swc_HVSM_ARID_DEF.DataTypeConversion25 ==
                       HVBRelayStatus_CLOSED) && ((hvbd_e_modeTgt !=
    HVBattStatus_SHUTDOWN) && ((hvbd_e_modeTgt != HVBattStatus_STANDBY) &&
    (hvbd_e_modeTgt != HVBattStatus_CHARGE_OFF))) &&
                      (swc_HVSM_ARID_DEF.DataTypeConversion26 != ElMac_FAILURE) &&
                      eadc_b_enaMot2);

  /* RelationalOperator: '<S41>/Relational Operator6' incorporates:
   *  Constant: '<S41>/Constant'
   */
  eadd_b_ead2Enad = (hvbd_st_ptRdyInd == ((uint8)1U));

  /* Logic: '<S41>/Logical Operator2' incorporates:
   *  Constant: '<S52>/Constant'
   *  Constant: '<S53>/Constant'
   *  Constant: '<S54>/Constant'
   *  Constant: '<S55>/Constant'
   *  Constant: '<S56>/Constant'
   *  RelationalOperator: '<S41>/Relational Operator12'
   *  RelationalOperator: '<S41>/Relational Operator13'
   *  RelationalOperator: '<S41>/Relational Operator14'
   *  RelationalOperator: '<S41>/Relational Operator15'
   *  RelationalOperator: '<S41>/Relational Operator16'
   */
  rtb_LogicalOperator2_lv = ((hvbd_e_PmmStatus == PmmStatus_HVDEVICEDEACT) ||
    (hvbd_e_PmmStatus == PmmStatus_HVDEVICEDEACTEMGY) || (hvbd_e_PmmStatus ==
    PmmStatus_STANDBYDRV) || (hvbd_e_PmmStatus == PmmStatus_CHARGE) ||
    (hvbd_e_PmmStatus == PmmStatus_TIMEOUT));

  /* RelationalOperator: '<S41>/Relational Operator11' incorporates:
   *  Constant: '<S51>/Constant'
   *  RelationalOperator: '<S41>/Relational Operator12'
   */
  rtb_RelationalOperator11_c = (hvbd_e_PmmStatus == PmmStatus_MCUACT);

  /* Outputs for Atomic SubSystem: '<S41>/SR_latch' */
  rtb_LogicalOperator3_l = swc_HVSM_SR_latch(rtb_RelationalOperator11_c,
    rtb_LogicalOperator2_lv, &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_m);

  /* End of Outputs for SubSystem: '<S41>/SR_latch' */

  /* Outputs for Atomic SubSystem: '<S4>/Get_FID_Enable' */
  swc_HVSM_Get_FID_Enable();

  /* End of Outputs for SubSystem: '<S4>/Get_FID_Enable' */

  /* Logic: '<S43>/Logical Operator19' incorporates:
   *  Constant: '<S43>/Constant3'
   *  Constant: '<S58>/Constant'
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   *  Logic: '<S43>/Logical Operator20'
   *  RelationalOperator: '<S43>/Relational Operator'
   */
  rtb_LogicalOperator19 = ((swc_HVSM_ARID_DEF.DataTypeConversion5 !=
    DriveDir_NO_DRIVE) || (!eadc_b_disMot2InGearPN));

  /* Outputs for Atomic SubSystem: '<S43>/turnOFF_delay' */
  /* Constant: '<S43>/Constant10' incorporates:
   *  Constant: '<S43>/Constant1'
   */
  rtb_flg_out_cr = swc_HVSM_turnOFF_delay(rtb_LogicalOperator19,
    eadc_tm_disMot2InGearPN_s, ((float32)EAD_TASK_INTERVAL_S),
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay);

  /* End of Outputs for SubSystem: '<S43>/turnOFF_delay' */

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant9'
   */
  if (eadc_b_enaMot2AfterVehRun) {
    rtb_LogicalOperator3 = (swc_HVSM_ARID_DEF.DataTypeConversion3 != 0.0);
  } else {
    rtb_LogicalOperator3 = swc_HVSM_ARID_DEF.DataTypeConversion2;
  }

  /* Logic: '<S43>/Logical Operator3' incorporates:
   *  Constant: '<S43>/Constant'
   *  Constant: '<S43>/Constant2'
   *  Constant: '<S43>/Constant4'
   *  Inport generated from: '<Root>/In Bus Element67'
   *  Logic: '<S43>/Logical Operator18'
   *  Logic: '<S43>/Logical Operator2'
   *  RelationalOperator: '<S43>/Relational Operator13'
   *  Switch: '<S43>/Switch'
   */
  rtb_LogicalOperator3 = (rtb_LogicalOperator3 && true && rtb_flg_out_cr &&
    ((Rte_IRead_swc_HVSM_Step_vcib_VCIP_trad_st_trsm2GearAct() != ((uint8)0U)) ||
     swc_HVSM_ARID_DEF.DataTypeConversion31 || (!eadc_b_disMot2InGear0)));

  /* Logic: '<S43>/Logical Operator1' incorporates:
   *  Constant: '<S43>/Constant5'
   *  Logic: '<S43>/Logical Operator13'
   */
  rtb_LogicalOperator1_pg = (rtb_LogicalOperator3 && (!false));

  /* Logic: '<S43>/Logical Operator11' incorporates:
   *  Constant: '<S43>/Constant5'
   */
  rtb_LogicalOperator3 = (false && rtb_LogicalOperator3);

  /* Chart: '<S4>/TractionMotor' incorporates:
   *  Constant: '<S43>/Constant7'
   *  SignalConversion: '<S5>/Signal Conversion2'
   */
  if (swc_HVSM_ARID_DEF.is_active_c4_swc_HVSM == 0U) {
    swc_HVSM_ARID_DEF.is_active_c4_swc_HVSM = 1U;
    swc_HVSM_ARID_DEF.is_c4_swc_HVSM = swc_HVSM_IN_HV_CONTROL;
  } else if (swc_HVSM_ARID_DEF.is_c4_swc_HVSM == swc_HVSM_IN_CONTROL_ACTIVE1) {
    if (!rtb_LogicalOperator3_l) {
      swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_NO_ACTIVE_CHILD_i;
      swc_HVSM_ARID_DEF.is_c4_swc_HVSM = swc_HVSM_IN_HV_CONTROL;
    } else {
      switch (swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1) {
       case swc_HVSM_IN_SPEED_CONTROL:
        if (rtb_LogicalOperator1_pg) {
          swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_TORQUE_CONTROL;
          eadd_e_inv2ModeTgt = ElMac_TORQUE_CTRL;
        } else if (false) {
          swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_VOLTAGE_CONTROL;
          eadd_e_inv2ModeTgt = ElMac_VOLTAGE_CTRL;
        }
        break;

       case swc_HVSM_IN_TORQUE_CONTROL:
        if (rtb_LogicalOperator3) {
          swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_SPEED_CONTROL;
          eadd_e_inv2ModeTgt = ElMac_SPEED_CTRL;
        } else if (false) {
          swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_VOLTAGE_CONTROL;
          eadd_e_inv2ModeTgt = ElMac_VOLTAGE_CTRL;
        }
        break;

       default:
        /* case IN_VOLTAGE_CONTROL: */
        if (rtb_LogicalOperator3) {
          swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_SPEED_CONTROL;
          eadd_e_inv2ModeTgt = ElMac_SPEED_CTRL;
        } else if (rtb_LogicalOperator1_pg) {
          swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_TORQUE_CONTROL;
          eadd_e_inv2ModeTgt = ElMac_TORQUE_CTRL;
        }
        break;
      }
    }

    /* case IN_HV_CONTROL: */
  } else if (rtb_LogicalOperator3_l) {
    swc_HVSM_ARID_DEF.is_c4_swc_HVSM = swc_HVSM_IN_CONTROL_ACTIVE1;
    if (rtb_LogicalOperator3) {
      swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_SPEED_CONTROL;
      eadd_e_inv2ModeTgt = ElMac_SPEED_CTRL;
    } else if (false) {
      swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_VOLTAGE_CONTROL;
      eadd_e_inv2ModeTgt = ElMac_VOLTAGE_CTRL;
    } else {
      swc_HVSM_ARID_DEF.is_CONTROL_ACTIVE1 = swc_HVSM_IN_TORQUE_CONTROL;
      eadd_e_inv2ModeTgt = ElMac_TORQUE_CTRL;
    }
  } else {
    eadd_e_inv2ModeTgt = swc_HVSM_ARID_DEF.swchvsm_eadd_e_inv2ModeTgtRaw;
  }

  /* End of Chart: '<S4>/TractionMotor' */
}

/* Output and update for atomic system: '<S3>/Get_FID_Enable' */
static void swc_HVSM_Get_FID_Enable_b(void)
{
  /* S-Function (fm_get_fidperm): '<S29>/S-Function' */
  swc_HVSM_ARID_DEF.GetEnable = 1;
}

/* Output and update for function-call system: '<S1>/DCC_ModeManager' */
static void swc_HVSM_DCC_ModeManager(void)
{
  /* local block i/o variables */
  boolean rtb_LogicalOperator1_o;
  boolean rtb_RelationalOperator1_ev;
  boolean rtb_LogicalOperator3_dk;
  DCDCMode rtb_LogicalOperator7_f_tmp;
  boolean rtb_LogicalOperator1_o0_tmp;
  boolean rtb_LogicalOperator7_o;

  /* Logic: '<S31>/Logical Operator1' incorporates:
   *  Constant: '<S31>/Constant6'
   *  Constant: '<S32>/Constant'
   *  Constant: '<S33>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  Logic: '<S31>/Logical Operator2'
   *  Logic: '<S31>/Logical Operator3'
   *  RelationalOperator: '<S31>/Relational Operator'
   *  RelationalOperator: '<S31>/Relational Operator2'
   *  RelationalOperator: '<S31>/Relational Operator3'
   *  RelationalOperator: '<S32>/Compare'
   */
  rtb_LogicalOperator1_o = ((hvbd_e_PmmStatus == PmmStatus_HVDEVICEDEACT) ||
    (hvbd_e_PmmStatus == PmmStatus_BMSNEGOPENEMGY) || ((hvbd_e_PmmStatus ==
    PmmStatus_HVDEVICEDEACTEMGY) && ((((uint8)VEH_SWT_INF) == ((uint8)0U)) ||
    hvbd_b_crashShutDn)));

  /* RelationalOperator: '<S31>/Relational Operator1' incorporates:
   *  Constant: '<S34>/Constant'
   *  RelationalOperator: '<S31>/Relational Operator'
   */
  rtb_RelationalOperator1_ev = (hvbd_e_PmmStatus == PmmStatus_DCDCACT);

  /* Outputs for Atomic SubSystem: '<S31>/SR_latch' */
  rtb_LogicalOperator3_dk = swc_HVSM_SR_latch(rtb_RelationalOperator1_ev,
    rtb_LogicalOperator1_o, &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch);

  /* End of Outputs for SubSystem: '<S31>/SR_latch' */

  /* Logic: '<S25>/Logical Operator1' incorporates:
   *  Constant: '<S25>/Constant10'
   *  Constant: '<S25>/Constant5'
   *  Logic: '<S25>/Logical Operator2'
   *  Logic: '<S25>/Logical Operator3'
   *  Logic: '<S25>/Logical Operator8'
   */
  dccd_b_DCDCEnabled = (dccc_b_enableDCDC && ((rtb_LogicalOperator3_dk &&
    (swc_HVSM_ARID_DEF.DataTypeConversion115 != 0)) ||
    (dccc_b_enableDCDCWithOBCPlug && obcd_b_chargerPlugged)));

  /* Switch: '<S25>/Switch' */
  if (dccd_b_DCDCEnabled) {
    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/Constant'
     */
    swchvsm_dccd_pct_DCDCPwrLmt = ((uint8)100U);
  } else {
    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S25>/Constant2'
     */
    swchvsm_dccd_pct_DCDCPwrLmt = ((uint8)0U);
  }

  /* End of Switch: '<S25>/Switch' */

  /* Logic: '<S30>/Logical Operator1' incorporates:
   *  Chart: '<S3>/DCDC_Converter'
   */
  rtb_LogicalOperator1_o0_tmp = !dccd_b_DCDCEnabled;

  /* RelationalOperator: '<S3>/Relational Operator2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion21'
   *  RelationalOperator: '<S3>/Relational Operator1'
   */
  rtb_LogicalOperator7_f_tmp = swc_HVSM_ARID_DEF.DataTypeConversion21;

  /* Logic: '<S3>/Logical Operator7' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S3>/Constant1'
   *  RelationalOperator: '<S3>/Relational Operator2'
   */
  rtb_LogicalOperator7_o = (dccc_b_enaDCDCFail && (DCDCMode_FAILURE ==
    rtb_LogicalOperator7_f_tmp));

  /* Outputs for Atomic SubSystem: '<S3>/Get_FID_Enable' */
  swc_HVSM_Get_FID_Enable_b();

  /* End of Outputs for SubSystem: '<S3>/Get_FID_Enable' */

  /* Chart: '<S3>/DCDC_Converter' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S30>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant11'
   *  Constant: '<S3>/Constant13'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant7'
   *  Constant: '<S40>/Constant'
   *  Logic: '<S30>/Logical Operator1'
   *  Logic: '<S30>/Logical Operator4'
   *  Logic: '<S30>/Logical Operator5'
   *  Logic: '<S30>/Logical Operator7'
   *  Logic: '<S3>/Logical Operator3'
   *  Logic: '<S3>/Logical Operator9'
   *  RelationalOperator: '<S30>/Relational Operator4'
   *  RelationalOperator: '<S30>/Relational Operator7'
   *  RelationalOperator: '<S30>/Relational Operator8'
   *  RelationalOperator: '<S3>/Relational Operator1'
   */
  if (swc_HVSM_ARID_DEF.is_active_c2_swc_HVSM == 0U) {
    swc_HVSM_ARID_DEF.is_active_c2_swc_HVSM = 1U;
    swc_HVSM_ARID_DEF.is_c2_swc_HVSM = swc_HVSM_IN_HV_OFF;
    dccd_e_modeTgt = DCDCMode_HV_OFF;
  } else {
    switch (swc_HVSM_ARID_DEF.is_c2_swc_HVSM) {
     case swc_HVSM_IN_ACTIVE:
      dccd_e_modeTgt = DCDCMode_ACTIVE;
      if (rtb_LogicalOperator1_o0_tmp || (!true) || rtb_LogicalOperator7_o) {
        swc_HVSM_ARID_DEF.is_c2_swc_HVSM = swc_HVSM_IN_SHUTDOWN;
        dccd_e_modeTgt = DCDCMode_SHUTDOWN;
        swc_HVSM_ARID_DEF.ShutdownTime = 0.0F;
      }
      break;

     case swc_HVSM_IN_CONTROL_OFF:
      if (((hvbd_e_modeTgt == HVBattStatus_STANDBY) || (hvbd_e_modeTgt ==
            HVBattStatus_CHARGE_OFF)) && swc_HVSM_ConstB.LogicalOperator6) {
        swc_HVSM_ARID_DEF.is_CONTROL_OFF = swc_HVSM_IN_NO_ACTIVE_CHILD_f;
        swc_HVSM_ARID_DEF.is_c2_swc_HVSM = swc_HVSM_IN_HV_DISCHARGE;
        swc_HVSM_ARID_DEF.DischargeTime = 0.0F;
        if (dccc_b_ActiveDischgAlwaysEna || (!swc_HVSM_ARID_DEF.GetEnable)) {
          swc_HVSM_ARID_DEF.is_HV_DISCHARGE = swc_HVSM_IN_ACTIVE_DISCHARGE;
          dccd_e_modeTgt = DCDCMode_HV_ACTIVE_DISCHARGE;
        } else {
          swc_HVSM_ARID_DEF.is_HV_DISCHARGE = swc_HVSM_IN_PASSIVE_DISCHARGE;
          dccd_e_modeTgt = DCDCMode_HV_PASSIVE_DISCHARGE;
        }
      } else if (dccd_b_DCDCEnabled && true && (!rtb_LogicalOperator1_o0_tmp) &&
                 (!rtb_LogicalOperator7_o)) {
        swc_HVSM_ARID_DEF.is_CONTROL_OFF = swc_HVSM_IN_NO_ACTIVE_CHILD_f;
        swc_HVSM_ARID_DEF.is_c2_swc_HVSM = swc_HVSM_IN_ACTIVE;
        dccd_e_modeTgt = DCDCMode_ACTIVE;
      } else if (swc_HVSM_ARID_DEF.is_CONTROL_OFF == swc_HVSM_IN_FAILURE) {
        dccd_e_modeTgt = DCDCMode_FAILURE;
        if (!rtb_LogicalOperator7_o) {
          swc_HVSM_ARID_DEF.is_CONTROL_OFF = swc_HVSM_IN_STANDBY;
          dccd_e_modeTgt = DCDCMode_STANDBY;
        }
      } else {
        /* case IN_STANDBY: */
        dccd_e_modeTgt = DCDCMode_STANDBY;
        if (rtb_LogicalOperator7_o) {
          swc_HVSM_ARID_DEF.is_CONTROL_OFF = swc_HVSM_IN_FAILURE;
          dccd_e_modeTgt = DCDCMode_FAILURE;
        }
      }
      break;

     case swc_HVSM_IN_HV_DISCHARGE:
      if (swc_HVSM_ARID_DEF.DataTypeConversion13 ||
          (swc_HVSM_ARID_DEF.DischargeTime >= dccc_tm_dischargeTimeout_s) ||
          ((true || (hvbd_e_modeTgt == HVBattStatus_PREPARATION)) &&
           dccc_b_enaAbortDischarge)) {
        swc_HVSM_ARID_DEF.is_HV_DISCHARGE = swc_HVSM_IN_NO_ACTIVE_CHILD_f;
        swc_HVSM_ARID_DEF.is_c2_swc_HVSM = swc_HVSM_IN_HV_OFF;
        dccd_e_modeTgt = DCDCMode_HV_OFF;
      } else {
        swc_HVSM_ARID_DEF.DischargeTime += ((float32)DCC_TASK_INTERVAL_S);
        if (swc_HVSM_ARID_DEF.is_HV_DISCHARGE == swc_HVSM_IN_ACTIVE_DISCHARGE) {
          dccd_e_modeTgt = DCDCMode_HV_ACTIVE_DISCHARGE;
        } else {
          /* case IN_PASSIVE_DISCHARGE: */
          dccd_e_modeTgt = DCDCMode_HV_PASSIVE_DISCHARGE;
        }
      }
      break;

     case swc_HVSM_IN_HV_OFF:
      dccd_e_modeTgt = DCDCMode_HV_OFF;
      if (true) {
        swc_HVSM_ARID_DEF.is_c2_swc_HVSM = swc_HVSM_IN_CONTROL_OFF;
        if (rtb_LogicalOperator7_o) {
          swc_HVSM_ARID_DEF.is_CONTROL_OFF = swc_HVSM_IN_FAILURE;
          dccd_e_modeTgt = DCDCMode_FAILURE;
        } else {
          swc_HVSM_ARID_DEF.is_CONTROL_OFF = swc_HVSM_IN_STANDBY;
          dccd_e_modeTgt = DCDCMode_STANDBY;
        }
      }
      break;

     default:
      /* case IN_SHUTDOWN: */
      dccd_e_modeTgt = DCDCMode_SHUTDOWN;
      if (dccd_b_DCDCEnabled && true && (!rtb_LogicalOperator1_o0_tmp) &&
          (!rtb_LogicalOperator7_o)) {
        swc_HVSM_ARID_DEF.is_c2_swc_HVSM = swc_HVSM_IN_ACTIVE;
        dccd_e_modeTgt = DCDCMode_ACTIVE;
      } else if ((rtb_LogicalOperator7_f_tmp != DCDCMode_ACTIVE) ||
                 (swc_HVSM_ARID_DEF.ShutdownTime >= dccc_tm_shutdownTimeout_s))
      {
        swc_HVSM_ARID_DEF.is_c2_swc_HVSM = swc_HVSM_IN_CONTROL_OFF;
        if (rtb_LogicalOperator7_o) {
          swc_HVSM_ARID_DEF.is_CONTROL_OFF = swc_HVSM_IN_FAILURE;
          dccd_e_modeTgt = DCDCMode_FAILURE;
        } else {
          swc_HVSM_ARID_DEF.is_CONTROL_OFF = swc_HVSM_IN_STANDBY;
          dccd_e_modeTgt = DCDCMode_STANDBY;
        }
      } else {
        swc_HVSM_ARID_DEF.ShutdownTime += ((float32)DCC_TASK_INTERVAL_S);
      }
      break;
    }
  }
}

/* Function for Chart: '<S2>/Chart' */
static void swc_HVSM_PowerOneHvOn(const boolean *RelationalOperator2, const
  boolean *RelationalOperator1)
{
  switch (swc_HVSM_ARID_DEF.is_PowerOneHvOn) {
   case swc_HVSM_IN_AccyPreChg:
    if (!hvbd_b_accyEnReq) {
      swc_HVSM_ARID_DEF.is_AccyPreChg = swc_HVSM_IN_NO_ACTIVE_CHILD_j;
      swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_NO_ACTIVE_CHILD_j;
      swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_Off;
      swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
      swc_HVSM_ARID_DEF.flg_accyDisEnOvrTm = 0.0;
      swc_HVSM_ARID_DEF.AccyRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.Counter = 0.0;
    } else if (swc_HVSM_ARID_DEF.Counter >= 3.0) {
      swc_HVSM_ARID_DEF.is_AccyPreChg = swc_HVSM_IN_NO_ACTIVE_CHILD_j;
      swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_PreChgOvrTm;
      swc_HVSM_ARID_DEF.AccyPreRlyFlt = 1.0;
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
      swc_HVSM_ARID_DEF.Counter = 0.0;
    } else if (swc_HVSM_ARID_DEF.is_AccyPreChg == swc_HVSM_IN_PreChgFail) {
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;

      /* Constant: '<S2>/Constant24' */
      if (swc_HVSM_ARID_DEF.t > hvbc_t_accyRePreChgTm_s) {
        swc_HVSM_ARID_DEF.is_AccyPreChg = swc_HVSM_IN_PreRlyCtrl;
        swc_HVSM_ARID_DEF.AccyPreRlyCmd = 1.0;
        swc_HVSM_ARID_DEF.t = 0.0F;
      } else {
        /* Constant: '<S2>/Constant4' */
        swc_HVSM_ARID_DEF.t += ((float32)HVB_TASK_INTERVAL_S);
      }

      /* End of Constant: '<S2>/Constant24' */
    } else {
      /* case IN_PreRlyCtrl: */
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 1.0;
      if (*RelationalOperator2) {
        swc_HVSM_ARID_DEF.is_AccyPreChg = swc_HVSM_IN_NO_ACTIVE_CHILD_j;
        swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_NO_ACTIVE_CHILD_j;
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_PowerOn;
        swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
        swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
        swc_HVSM_ARID_DEF.AccyPreRlySts = 1.0;
        swc_HVSM_ARID_DEF.t = 0.0F;
      } else if (swc_HVSM_ARID_DEF.t > hvbc_t_accyPreChgOvrTm_s) {
        swc_HVSM_ARID_DEF.is_AccyPreChg = swc_HVSM_IN_PreChgFail;
        swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
        swc_HVSM_ARID_DEF.t = 0.0F;
        swc_HVSM_ARID_DEF.Counter++;
      } else {
        /* Constant: '<S2>/Constant4' */
        swc_HVSM_ARID_DEF.t += ((float32)HVB_TASK_INTERVAL_S);
      }
    }
    break;

   case swc_HVSM_IN_AccyRlyChk:
    if (*RelationalOperator1) {
      swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_AccyRlyFlt;
      swc_HVSM_ARID_DEF.AccyRlyFlt = 2.0;
    } else {
      swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_AccyPreChg;
      swc_HVSM_ARID_DEF.is_AccyPreChg = swc_HVSM_IN_PreRlyCtrl;
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 1.0;
      swc_HVSM_ARID_DEF.t = 0.0F;
    }
    break;

   case swc_HVSM_IN_AccyRlyFlt:
    swc_HVSM_ARID_DEF.AccyRlyFlt = 2.0;
    if (!hvbd_b_accyEnReq) {
      swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_NO_ACTIVE_CHILD_j;
      swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_Off;
      swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
      swc_HVSM_ARID_DEF.flg_accyDisEnOvrTm = 0.0;
      swc_HVSM_ARID_DEF.AccyRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.Counter = 0.0;
    }
    break;

   default:
    /* case IN_PreChgOvrTm: */
    swc_HVSM_ARID_DEF.AccyPreRlyFlt = 1.0;
    swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
    if (!hvbd_b_accyEnReq) {
      swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_NO_ACTIVE_CHILD_j;
      swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_Off;
      swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
      swc_HVSM_ARID_DEF.flg_accyDisEnOvrTm = 0.0;
      swc_HVSM_ARID_DEF.AccyRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.Counter = 0.0;
    }
    break;
  }
}

/* Model step function */
void swc_HVSM_Step(void)
{
  /* local block i/o variables */
  boolean rtb_LogicalOperator2_lx;
  boolean rtb_DataTypeConversion120;
  boolean rtb_DataTypeConversion125;
  boolean rtb_FixPtRelationalOperator_d;
  boolean rtb_LogicalOperator_at;
  boolean rtb_LogicalOperator2_c;
  boolean rtb_flg_out_jb;
  boolean rtb_LogicalOperator3_dm;
  NMStatus rtb_DataTypeConversion82;
  HVBRelayStatus rtb_DataTypeConversion94;
  float64 tmp;
  float32 rtb_Abs;
  HVBattStatus rtb_LogicalOperator2_c_tmp;
  McuSts rtb_LogicalOperator2_lx_tmp;
  uint8 rtb_DataTypeConversion10;
  uint8 rtb_Sum;
  uint8 rtb_Switch3_j;
  boolean RelationalOperator3;
  boolean hvbd_b_accyEnReq_tmp;
  boolean rtb_Compare_jd;
  boolean rtb_RelationalOperator11_b;
  boolean rtb_RelationalOperator1_ir;
  boolean rtb_RelationalOperator2_gm;
  boolean rtb_Switch1_k;
  boolean rtb_Switch1_nw;
  boolean tmp_0;
  boolean tmp_1;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Inport generated from: '<Root>/In Bus Element69'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hvbStatus();

  /* RelationalOperator: '<S2>/Relational Operator11' incorporates:
   *  Constant: '<S2>/Constant23'
   *  Inport generated from: '<Root>/In Bus Element60'
   */
  rtb_RelationalOperator11_b =
    (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_flgFctCfgAccy() == ((uint8)1U));

  /* DataTypeConversion: '<Root>/Data Type Conversion54' incorporates:
   *  Inport generated from: '<Root>/In Bus Element27'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion54 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_dccd_e_24vDcdcModAct();

  /* RelationalOperator: '<S10>/Relational Operator' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion54'
   *  RelationalOperator: '<S10>/Relational Operator2'
   */
  rtb_LogicalOperator2_lx_tmp = swc_HVSM_ARID_DEF.DataTypeConversion54;

  /* Logic: '<S10>/Logical Operator2' incorporates:
   *  Constant: '<S22>/Constant'
   *  RelationalOperator: '<S10>/Relational Operator'
   */
  rtb_LogicalOperator2_lx = (rtb_RelationalOperator11_b &&
    (rtb_LogicalOperator2_lx_tmp == McuSts_READY));

  /* RelationalOperator: '<S10>/Relational Operator2' incorporates:
   *  Constant: '<S21>/Constant'
   */
  rtb_RelationalOperator2_gm = (rtb_LogicalOperator2_lx_tmp == McuSts_NOTREADY);

  /* Abs: '<S2>/Abs' incorporates:
   *  Inport generated from: '<Root>/In Bus Element59'
   *  Inport generated from: '<Root>/In Bus Element58'
   *  Sum: '<S2>/Add'
   */
  rtb_Abs = fabsf(Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_u_hcmMainPosBckVolt() -
                  Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_u_hcmAcceRlyVolt());

  /* DataTypeConversion: '<S2>/Data Type Conversion10' incorporates:
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S2>/Relational Operator'
   */
  rtb_DataTypeConversion10 = (uint8)(rtb_Abs <= hvbc_u_accyRlyClsVolt_V);

  /* RelationalOperator: '<S2>/Relational Operator3' incorporates:
   *  Constant: '<S2>/Constant12'
   *  Inport generated from: '<Root>/In Bus Element170'
   */
  RelationalOperator3 =
    (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp() == ((uint8)1U));

  /* Switch: '<S2>/Switch3' incorporates:
   *  Constant: '<S2>/Constant6'
   *  Switch: '<S2>/Switch5'
   */
  if (RelationalOperator3) {
    /* Switch: '<S2>/Switch3' */
    rtb_Switch3_j = rtb_DataTypeConversion10;
  } else if (hvbc_b_accyRlyUseDcc) {
    /* Switch: '<S2>/Switch5' incorporates:
     *  Inport generated from: '<Root>/In Bus Element71'
     *  Switch: '<S2>/Switch3'
     */
    rtb_Switch3_j = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_dccAccyConnStsFb();
  } else {
    /* Switch: '<S2>/Switch3' incorporates:
     *  Inport generated from: '<Root>/In Bus Element53'
     *  Switch: '<S2>/Switch5'
     */
    rtb_Switch3_j = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hcmAccConnStsFb();
  }

  /* End of Switch: '<S2>/Switch3' */

  /* RelationalOperator: '<S10>/Relational Operator1' incorporates:
   *  Constant: '<S10>/Constant5'
   */
  rtb_RelationalOperator1_ir = (rtb_Switch3_j == ((uint8)0U));

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  Inport generated from: '<Root>/BusElementIn'
   */
  rtb_Compare_jd = (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_flgFctCfgAccyButton
                    () == true);

  /* DataTypeConversion: '<Root>/Data Type Conversion15' incorporates:
   *  Inport generated from: '<Root>/In Bus Element'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion15 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_obcd_b_obcChrgCablePlugged();

  /* DataTypeConversion: '<Root>/Data Type Conversion17' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion17 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_obcd_b_obcChrgCableUnplugged();

  /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion16 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_obcd_b_obcWakeUp();

  /* DataTypeConversion: '<Root>/Data Type Conversion24' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion24 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_pmmd_b_ignOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion27' incorporates:
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion27 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion19' incorporates:
   *  Inport generated from: '<Root>/In Bus Element5'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion19 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_cesd_b_EmergencyStop();

  /* DataTypeConversion: '<Root>/Data Type Conversion99' incorporates:
   *  Inport generated from: '<Root>/In Bus Element39'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion99 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hvbChgFltReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion32' incorporates:
   *  Inport generated from: '<Root>/In Bus Element13'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion32 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_i_hvbCurr_A();

  /* DataTypeConversion: '<Root>/Data Type Conversion44' incorporates:
   *  Inport generated from: '<Root>/In Bus Element15'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion44 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_bmsSelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion55' incorporates:
   *  Inport generated from: '<Root>/In Bus Element16'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion55 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hcmSelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion58' incorporates:
   *  Inport generated from: '<Root>/In Bus Element17'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion58 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_macd_b_epsSelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion61' incorporates:
   *  Inport generated from: '<Root>/In Bus Element18'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion61 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_brpd_b_brkPmpSelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion62' incorporates:
   *  Inport generated from: '<Root>/In Bus Element19'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion62 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_dccd_b_dcdcSelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion34' incorporates:
   *  Inport generated from: '<Root>/In Bus Element20'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion34 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb();

  /* DataTypeConversion: '<Root>/Data Type Conversion37' incorporates:
   *  Inport generated from: '<Root>/In Bus Element21'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion37 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hcmCutOffLvFb();

  /* DataTypeConversion: '<Root>/Data Type Conversion41' incorporates:
   *  Inport generated from: '<Root>/In Bus Element23'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion41 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hcmWrkSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion49' incorporates:
   *  Inport generated from: '<Root>/In Bus Element24'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion49 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_eadd_e_eadInv2Sts();

  /* DataTypeConversion: '<Root>/Data Type Conversion50' incorporates:
   *  Inport generated from: '<Root>/In Bus Element25'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion50 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_macd_e_sdcacWrk();

  /* DataTypeConversion: '<Root>/Data Type Conversion51' incorporates:
   *  Inport generated from: '<Root>/In Bus Element26'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion51 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_brpd_e_bdcacWrk();

  /* DataTypeConversion: '<Root>/Data Type Conversion56' incorporates:
   *  Inport generated from: '<Root>/In Bus Element28'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion56 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_accd_e_airCmprSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion42' incorporates:
   *  Inport generated from: '<Root>/In Bus Element29'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion42 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_accd_e_PtcSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion43' incorporates:
   *  Inport generated from: '<Root>/In Bus Element30'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion43 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_eadd_b_eadInv2SelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion47' incorporates:
   *  Inport generated from: '<Root>/In Bus Element32'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion47 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hvbMaiRlyNeg();

  /* DataTypeConversion: '<Root>/Data Type Conversion48' incorporates:
   *  Inport generated from: '<Root>/In Bus Element33'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion48 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hcmMaiRlyNeg();

  /* DataTypeConversion: '<Root>/Data Type Conversion64' incorporates:
   *  Inport generated from: '<Root>/In Bus Element34'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion64 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hvbAssiRly();

  /* DataTypeConversion: '<Root>/Data Type Conversion76' incorporates:
   *  Inport generated from: '<Root>/In Bus Element35'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion76 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hvbMaiRlyPos();

  /* DataTypeConversion: '<Root>/Data Type Conversion120' incorporates:
   *  Inport generated from: '<Root>/In Bus Element163'
   */
  rtb_DataTypeConversion120 = Rte_IRead_swc_HVSM_Step_vcsb_VOMM_pmmd_b_nmWkUp();

  /* DataTypeConversion: '<Root>/Data Type Conversion125' incorporates:
   *  Inport generated from: '<Root>/In Bus Element164'
   */
  rtb_DataTypeConversion125 = Rte_IRead_swc_HVSM_Step_vcsb_VOMM_pmmd_b_nmRdySlp();

  /* DataTypeConversion: '<Root>/Data Type Conversion127' incorporates:
   *  Inport generated from: '<Root>/In Bus Element40'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion127 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_lowTempProtnReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion126' incorporates:
   *  Inport generated from: '<Root>/In Bus Element41'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion126 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_brpd_e_brkPedalStatus();

  /* DataTypeConversion: '<Root>/Data Type Conversion66' incorporates:
   *  Inport generated from: '<Root>/In Bus Element42'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion66 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_epbd_e_parkingSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Inport generated from: '<Root>/In Bus Element176'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion13 =
    Rte_IRead_swc_HVSM_Step_vcsb_VOMM_hmmd_b_HVBusDischrgComplete();

  /* DataTypeConversion: '<Root>/Data Type Conversion68' incorporates:
   *  Inport generated from: '<Root>/In Bus Element166'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion68 =
    Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_StartDemRaw();

  /* DataTypeConversion: '<Root>/Data Type Conversion71' incorporates:
   *  Inport generated from: '<Root>/In Bus Element168'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion71 =
    Rte_IRead_swc_HVSM_Step_vcsb_VOMM_pmmd_b_pwrHoldReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion82' incorporates:
   *  Inport generated from: '<Root>/In Bus Element169'
   */
  rtb_DataTypeConversion82 = Rte_IRead_swc_HVSM_Step_vcsb_VOMM_pmmd_e_CanNMSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion83' incorporates:
   *  Inport generated from: '<Root>/In Bus Element43'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion83 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hcmRlyWldFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion85' incorporates:
   *  Inport generated from: '<Root>/In Bus Element44'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion85 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_obcd_b_obcSelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion86' incorporates:
   *  Inport generated from: '<Root>/In Bus Element45'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion86 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_macd_b_vcuSelfChkOk();

  /* DataTypeConversion: '<Root>/Data Type Conversion89' incorporates:
   *  Inport generated from: '<Root>/In Bus Element46'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion89 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV();

  /* DataTypeConversion: '<Root>/Data Type Conversion74' incorporates:
   *  Inport generated from: '<Root>/In Bus Element47'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion74 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_dccd_b_dcdcCutOffLvFb();

  /* DataTypeConversion: '<Root>/Data Type Conversion80' incorporates:
   *  Inport generated from: '<Root>/In Bus Element50'
   */
  hvbd_b_crashShutDn = Rte_IRead_swc_HVSM_Step_vcib_VCIP_cesd_b_crash();

  /* DataTypeConversion: '<Root>/Data Type Conversion210' incorporates:
   *  Inport generated from: '<Root>/In Bus Element85'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion210 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/In Bus Element174'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion3 =
    Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_VehRun();

  /* DataTypeConversion: '<Root>/Data Type Conversion70' incorporates:
   *  Inport generated from: '<Root>/In Bus Element8'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion70 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hvilOpen();

  /* DataTypeConversion: '<Root>/Data Type Conversion96' incorporates:
   *  Inport generated from: '<Root>/In Bus Element38'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion96 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls();

  /* DataTypeConversion: '<Root>/Data Type Conversion87' incorporates:
   *  Inport generated from: '<Root>/In Bus Element10'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion87 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_pmmd_b_driverStartReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion156' incorporates:
   *  Inport generated from: '<Root>/In Bus Element130'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion156 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_acpd_x_accPedlPos_pct();

  /* DataTypeConversion: '<Root>/Data Type Conversion95' incorporates:
   *  Inport generated from: '<Root>/In Bus Element36'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion95 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hvbDischgFltReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion119' incorporates:
   *  Inport generated from: '<Root>/In Bus Element52'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion119 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_obcChgCCSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion209' incorporates:
   *  Inport generated from: '<Root>/In Bus Element77'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion209 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_dcChgCcSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion115' incorporates:
   *  Inport generated from: '<Root>/In Bus Element14'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion115 =
    Rte_IRead_swc_HVSM_Step_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg();

  /* DataTypeConversion: '<Root>/Data Type Conversion213' incorporates:
   *  Inport generated from: '<Root>/In Bus Element92'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion213 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_tboxChgSftSwCtlSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion214' incorporates:
   *  Inport generated from: '<Root>/In Bus Element93'
   */
  hvbd_b_tboxPrtFullSwStUB =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_tboxPrtFullSwStUB();

  /* DataTypeConversion: '<Root>/Data Type Conversion215' incorporates:
   *  Inport generated from: '<Root>/In Bus Element103'
   */
  hvbd_st_tboxPrtFullSwSt =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_tboxPrtFullSwSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion216' incorporates:
   *  Inport generated from: '<Root>/In Bus Element104'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion216 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_tboxRsrChgSt();

  /* DataTypeConversion: '<Root>/Data Type Conversion217' incorporates:
   *  Inport generated from: '<Root>/In Bus Element105'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion217 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmV2XDchaSw();

  /* DataTypeConversion: '<Root>/Data Type Conversion218' incorporates:
   *  Inport generated from: '<Root>/In Bus Element106'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion218 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_obcOnBdDchaCCline();

  /* DataTypeConversion: '<Root>/Data Type Conversion221' incorporates:
   *  Inport generated from: '<Root>/In Bus Element119'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion221 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmV2XDchaSwInvld();

  /* DataTypeConversion: '<Root>/Data Type Conversion224' incorporates:
   *  Inport generated from: '<Root>/In Bus Element134'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion224 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_obcOnBdCCline();

  /* DataTypeConversion: '<Root>/Data Type Conversion225' incorporates:
   *  Inport generated from: '<Root>/In Bus Element165'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion225 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hvbPreChgSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion5' incorporates:
   *  Inport generated from: '<Root>/In Bus Element175'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion5 =
    Rte_IRead_swc_HVSM_Step_vcsb_VOMM_drid_e_driveDirSel();

  /* DataTypeConversion: '<Root>/Data Type Conversion25' incorporates:
   *  Inport generated from: '<Root>/In Bus Element61'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion25 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_eadInv2MainRlySts();

  /* DataTypeConversion: '<Root>/Data Type Conversion26' incorporates:
   *  Inport generated from: '<Root>/In Bus Element62'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion26 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_eadd_e_inv2ModeAct();

  /* DataTypeConversion: '<Root>/Data Type Conversion31' incorporates:
   *  Inport generated from: '<Root>/In Bus Element65'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion31 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_trad_b_trsm2GearshiftActv();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/In Bus Element173'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_PTEnabled();

  /* DataTypeConversion: '<Root>/Data Type Conversion22' incorporates:
   *  Inport generated from: '<Root>/In Bus Element156'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion22 =
    Rte_IRead_swc_HVSM_Step_vcsb_SCAP_eadd_b_mot2TqOff();

  /* DataTypeConversion: '<Root>/Data Type Conversion21' incorporates:
   *  Inport generated from: '<Root>/In Bus Element6'
   */
  swc_HVSM_ARID_DEF.DataTypeConversion21 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_dccd_e_modeAct();

  /* DataTypeConversion: '<Root>/Data Type Conversion94' incorporates:
   *  Inport generated from: '<Root>/In Bus Element95'
   */
  rtb_DataTypeConversion94 =
    Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_dcdcMainRlySts();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/OBC_ChargerStatus'
   */
  swc_HVSM_OBC_ChargerStatus();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/HVB_ModeManager'
   */
  swc_HVSM_HVB_ModeManager();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/EAD_ModeManagerMot2'
   */
  swc_HVSM_EAD_ModeManagerMot2();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/DCC_ModeManager'
   */
  swc_HVSM_DCC_ModeManager();

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* Logic: '<S9>/Logical Operator10' incorporates:
   *  Inport generated from: '<Root>/In Bus Element22'
   *  Logic: '<S9>/Logical Operator8'
   */
  tmp_0 = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld();

  /* RelationalOperator: '<S14>/FixPt Relational Operator' incorporates:
   *  Inport generated from: '<Root>/In Bus Element9'
   *  UnitDelay: '<S14>/Delay Input1'
   * *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  tmp_1 = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmTakeEleSwt();

  /* Switch: '<S9>/Switch3' incorporates:
   *  Constant: '<S9>/Constant3'
   *  Constant: '<S9>/Constant9'
   *  Inport generated from: '<Root>/In Bus Element9'
   *  Inport generated from: '<Root>/In Bus Element22'
   *  Logic: '<S9>/Logical Operator10'
   *  Logic: '<S9>/Logical Operator9'
   *  RelationalOperator: '<S14>/FixPt Relational Operator'
   *  UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((!tmp_0) && ((sint32)tmp_1 > (sint32)
                   swc_HVSM_ARID_DEF.DelayInput1_DSTATE_o)) {
    rtb_Sum = ((uint8)1U);
  } else {
    rtb_Sum = ((uint8)0U);
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Switch: '<S9>/Switch3'
   *  UnitDelay: '<S9>/Unit Delay'
   */
  rtb_Sum = (uint8)((uint32)rtb_Sum + swc_HVSM_ARID_DEF.UnitDelay_DSTATE);

  /* Switch: '<S9>/Switch2' incorporates:
   *  Constant: '<S12>/Constant'
   *  Constant: '<S16>/Constant'
   *  Constant: '<S17>/Constant'
   *  Logic: '<S9>/Logical Operator11'
   *  Logic: '<S9>/Logical Operator8'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S9>/Relational Operator3'
   *  RelationalOperator: '<S9>/Relational Operator6'
   */
  if ((hvbd_e_PmmStatus == PmmStatus_HVDEVICEDEACT) || (hvbd_e_PmmStatus ==
       PmmStatus_HVDEVICEDEACTEMGY) || tmp_0 || (rtb_Sum >= ((uint8)2U))) {
    /* Switch: '<S9>/Switch2' incorporates:
     *  Constant: '<S9>/Constant1'
     */
    rtb_Sum = ((uint8)0U);
  }

  /* End of Switch: '<S9>/Switch2' */

  /* Switch: '<S9>/Switch4' incorporates:
   *  Constant: '<S9>/Constant4'
   */
  if (hvbc_b_useAccyCanEnb) {
    /* Switch: '<S9>/Switch4' */
    hvbd_b_TakeEleSwtIndReq = (rtb_Sum != 0);
  } else {
    /* Switch: '<S9>/Switch4' incorporates:
     *  Inport generated from: '<Root>/In Bus Element11'
     */
    hvbd_b_TakeEleSwtIndReq = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_AccyEnReq
      ();
  }

  /* End of Switch: '<S9>/Switch4' */

  /* RelationalOperator: '<S8>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S8>/Delay Input1'
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_d = ((sint32)
    swc_HVSM_ARID_DEF.DataTypeConversion24 > (sint32)
    swc_HVSM_ARID_DEF.DelayInput1_DSTATE_m);

  /* Outputs for Atomic SubSystem: '<S2>/turnOFF_delay' */
  /* Constant: '<S2>/Constant1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  rtb_flg_out_jb = swc_HVSM_turnOFF_delay(rtb_FixPtRelationalOperator_d,
    hvbc_t_ignOnHold_s, ((float32)HVB_TASK_INTERVAL_S),
    &swc_HVSM_ARID_DEF.ARID_DEF_turnOFF_delay_m);

  /* End of Outputs for SubSystem: '<S2>/turnOFF_delay' */

  /* Switch: '<S2>/Switch' */
  if (rtb_flg_out_jb) {
    /* Switch: '<S2>/Switch' incorporates:
     *  Inport generated from: '<Root>/In Bus Element72'
     */
    hvbd_b_accyCtrlHw = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_flgBBMMsgErr();
  } else {
    /* Switch: '<S2>/Switch' incorporates:
     *  UnitDelay: '<S2>/Unit Delay'
     */
    hvbd_b_accyCtrlHw = swc_HVSM_ARID_DEF.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S2>/Switch' */

  /* Switch: '<S2>/Switch1' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  if (hvbc_b_accyCtrlHw_ovrdflg) {
    /* Switch: '<S2>/Switch1' incorporates:
     *  Constant: '<S2>/Constant5'
     */
    rtb_Switch1_nw = hvbc_b_accyCtrlHw_ovrdval;
  } else {
    /* Switch: '<S2>/Switch1' */
    rtb_Switch1_nw = hvbd_b_accyCtrlHw;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* Switch: '<S9>/Switch1' */
  if (rtb_Switch1_nw) {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Inport generated from: '<Root>/In Bus Element56'
     */
    rtb_Switch1_k = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_AccyFltSts();
  } else {
    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S9>/Constant8'
     *  Inport generated from: '<Root>/In Bus Element55'
     *  RelationalOperator: '<S9>/Relational Operator8'
     */
    rtb_Switch1_k = (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_bbmFltSts() ==
                     ((uint8)1U));
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Switch: '<S9>/Switch5' incorporates:
   *  Constant: '<S9>/Constant5'
   */
  if (rtb_Compare_jd) {
    tmp_0 = true;
  } else {
    tmp_0 = hvbd_b_TakeEleSwtIndReq;
  }

  /* Logic: '<S9>/Logical Operator7' incorporates:
   *  Chart: '<S2>/Chart'
   */
  hvbd_b_accyEnReq_tmp = !RelationalOperator3;

  /* Logic: '<S9>/Logical Operator3' incorporates:
   *  Constant: '<S9>/Constant2'
   *  Inport generated from: '<Root>/In Bus Element70'
   *  Inport generated from: '<Root>/In Bus Element68'
   *  Inport generated from: '<Root>/In Bus Element54'
   *  Inport generated from: '<Root>/In Bus Element57'
   *  Logic: '<S9>/Logical Operator'
   *  Logic: '<S9>/Logical Operator1'
   *  Logic: '<S9>/Logical Operator4'
   *  Logic: '<S9>/Logical Operator5'
   *  Logic: '<S9>/Logical Operator6'
   *  Logic: '<S9>/Logical Operator7'
   *  RelationalOperator: '<S9>/Relational Operator4'
   *  Switch: '<S9>/Switch5'
   */
  hvbd_b_accyEnReq = (Rte_IRead_swc_HVSM_Step_vcsb_EGYM_egmd_b_accyEnbFlg() &&
                      rtb_RelationalOperator11_b && tmp_0 &&
                      (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hcmHvilSt() ==
                       ((uint8)0U)) && (!rtb_Switch1_k) &&
                      (((!Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts
    ()) && (!Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts())) ||
                       hvbd_b_accyEnReq_tmp));

  /* Switch: '<S2>/Switch2' */
  if (rtb_Switch1_nw) {
    /* Switch: '<S2>/Switch2' incorporates:
     *  Constant: '<S2>/Constant7'
     *  Inport generated from: '<Root>/In Bus Element12'
     *  RelationalOperator: '<S2>/Relational Operator7'
     */
    rtb_RelationalOperator11_b =
      (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_cntnrCtrlEnaFb() == ((uint8)0U));
  } else {
    /* Switch: '<S2>/Switch2' incorporates:
     *  Constant: '<S2>/Constant9'
     *  Inport generated from: '<Root>/In Bus Element7'
     *  RelationalOperator: '<S2>/Relational Operator9'
     */
    rtb_RelationalOperator11_b =
      (Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_bbmWorkSts() == ((uint8)0U));
  }

  /* End of Switch: '<S2>/Switch2' */

  /* RelationalOperator: '<S2>/Relational Operator2' incorporates:
   *  Constant: '<S2>/Constant11'
   */
  rtb_Compare_jd = (rtb_Abs <= hvbc_u_accyPreFinVolt_V);

  /* RelationalOperator: '<S2>/Relational Operator1' incorporates:
   *  Constant: '<S2>/Constant10'
   */
  rtb_Switch1_k = (rtb_Abs <= hvbc_u_accyRlyFltVolt_V);

  /* Chart: '<S2>/Chart' incorporates:
   *  Constant: '<S2>/Constant17'
   *  Constant: '<S2>/Constant4'
   *  RelationalOperator: '<S2>/Relational Operator6'
   *  Switch: '<S2>/Switch4'
   */
  if (swc_HVSM_ARID_DEF.is_active_c68_swc_HVSM == 0U) {
    swc_HVSM_ARID_DEF.is_active_c68_swc_HVSM = 1U;
    swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_Off;
    swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
    swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
    swc_HVSM_ARID_DEF.flg_accyDisEnOvrTm = 0.0;
    swc_HVSM_ARID_DEF.AccyRlyFlt = 0.0;
    swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
    swc_HVSM_ARID_DEF.AccyPreRlyFlt = 0.0;
    swc_HVSM_ARID_DEF.Counter = 0.0;
  } else {
    boolean guard1 = false;
    guard1 = false;
    switch (swc_HVSM_ARID_DEF.is_c68_swc_HVSM) {
     case swc_HVSM_IN_AccyConnClsFail:
      swc_HVSM_ARID_DEF.AccyRlyFlt = 1.0;
      swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
      if (!hvbd_b_accyEnReq) {
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_PowerOff;
        swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
        swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
        swc_HVSM_ARID_DEF.t = 0.0F;
        swc_HVSM_ARID_DEF.AccyPreRlyFlt = 0.0;
        swc_HVSM_ARID_DEF.AccyRlyFlt = 0.0;
      }
      break;

     case swc_HVSM_IN_DisEnable:
      swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
      if (swc_HVSM_ARID_DEF.t > hvbc_t_accyDisEnOvrTm_s) {
        swc_HVSM_ARID_DEF.flg_accyDisEnOvrTm = 1.0;
        guard1 = true;
      } else if (rtb_RelationalOperator11_b) {
        guard1 = true;
      } else {
        swc_HVSM_ARID_DEF.t += ((float32)HVB_TASK_INTERVAL_S);
      }
      break;

     case swc_HVSM_IN_Enable:
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
      swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 1.0;
      if (!hvbd_b_accyEnReq) {
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_DisEnable;
        swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
        swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
        swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
        swc_HVSM_ARID_DEF.t = 0.0F;
      }
      break;

     case swc_HVSM_IN_Off:
      swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
      swc_HVSM_ARID_DEF.AccyRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyFlt = 0.0;
      if (hvbd_b_accyEnReq && hvbd_b_accyEnReq_tmp) {
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_PowerOn;
        swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
        swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
        swc_HVSM_ARID_DEF.AccyPreRlySts = 1.0;
        swc_HVSM_ARID_DEF.t = 0.0F;
      } else if (RelationalOperator3 && hvbd_b_accyEnReq) {
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_PowerOneHvOn;
        swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_AccyRlyChk;
        swc_HVSM_ARID_DEF.Counter = 0.0;
      }
      break;

     case swc_HVSM_IN_PowerOff:
      swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.AccyRlyFlt = 0.0;
      if (hvbd_b_accyEnReq && (swc_HVSM_ARID_DEF.flg_accyDisEnOvrTm == 0.0) &&
          hvbd_b_accyEnReq_tmp) {
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_PowerOn;
        swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
        swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
        swc_HVSM_ARID_DEF.AccyPreRlySts = 1.0;
        swc_HVSM_ARID_DEF.t = 0.0F;
      } else if (hvbd_b_accyEnReq && (swc_HVSM_ARID_DEF.flg_accyDisEnOvrTm ==
                  0.0) && RelationalOperator3) {
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_PowerOneHvOn;
        swc_HVSM_ARID_DEF.is_PowerOneHvOn = swc_HVSM_IN_AccyRlyChk;
        swc_HVSM_ARID_DEF.Counter = 0.0;
      }
      break;

     case swc_HVSM_IN_PowerOn:
      swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
      swc_HVSM_ARID_DEF.AccyPreRlySts = 1.0;
      if (!hvbd_b_accyEnReq) {
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_DisEnable;
        swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
        swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
        swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
        swc_HVSM_ARID_DEF.t = 0.0F;
      } else if (rtb_Switch3_j == ((uint8)1U)) {
        swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_Enable;
        swc_HVSM_ARID_DEF.AccyPreRlyCmd = 0.0;
        swc_HVSM_ARID_DEF.accyHvOnCmd = 1.0;
        swc_HVSM_ARID_DEF.accyWorkEnCmd = 1.0;
      } else {
        if (RelationalOperator3) {
          /* Switch: '<S2>/Switch4' incorporates:
           *  Constant: '<S2>/Constant14'
           */
          rtb_Abs = hvbc_t_accyRlyClsOvrTm_s;
        } else {
          /* Switch: '<S2>/Switch4' incorporates:
           *  Constant: '<S2>/Constant15'
           */
          rtb_Abs = hvbc_t_accyRlyClsOvrTmDrvone_s;
        }

        if (swc_HVSM_ARID_DEF.t > rtb_Abs) {
          swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_AccyConnClsFail;
          swc_HVSM_ARID_DEF.AccyRlyFlt = 1.0;
          swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
        } else {
          swc_HVSM_ARID_DEF.t += ((float32)HVB_TASK_INTERVAL_S);
        }
      }
      break;

     default:
      /* case IN_PowerOneHvOn: */
      swc_HVSM_PowerOneHvOn(&rtb_Compare_jd, &rtb_Switch1_k);
      break;
    }

    if (guard1) {
      swc_HVSM_ARID_DEF.is_c68_swc_HVSM = swc_HVSM_IN_PowerOff;
      swc_HVSM_ARID_DEF.accyHvOnCmd = 0.0;
      swc_HVSM_ARID_DEF.accyWorkEnCmd = 0.0;
      swc_HVSM_ARID_DEF.t = 0.0F;
      swc_HVSM_ARID_DEF.AccyPreRlyFlt = 0.0;
      swc_HVSM_ARID_DEF.AccyRlyFlt = 0.0;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion4' */
  hvbd_b_accyDisEnOvrTm = (swc_HVSM_ARID_DEF.flg_accyDisEnOvrTm != 0.0);

  /* Logic: '<S10>/Logical Operator' incorporates:
   *  Logic: '<S10>/Logical Operator1'
   */
  rtb_LogicalOperator_at = ((rtb_RelationalOperator2_gm &&
    rtb_RelationalOperator1_ir) || hvbd_b_accyDisEnOvrTm);

  /* Outputs for Atomic SubSystem: '<S10>/SR_latch' */
  rtb_LogicalOperator3_dm = swc_HVSM_SR_latch(rtb_LogicalOperator2_lx,
    rtb_LogicalOperator_at, &swc_HVSM_ARID_DEF.ARID_DEF_SR_latch_cz);

  /* End of Outputs for SubSystem: '<S10>/SR_latch' */

  /* SignalConversion generated from: '<S10>/SR_latch' */
  hvbd_b_accyLvPwrOnCmd = rtb_LogicalOperator3_dm;

  /* DataTypeConversion: '<S2>/Data Type Conversion6' */
  hvbd_b_accyPreRlyCmd = (swc_HVSM_ARID_DEF.AccyPreRlyCmd != 0.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion7' */
  tmp = fmod(floor(swc_HVSM_ARID_DEF.AccyPreRlySts), 256.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion7' */
  hvbd_st_accyPreRlySts = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-tmp
    : (sint32)(uint8)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion8' */
  tmp = fmod(floor(swc_HVSM_ARID_DEF.AccyRlyFlt), 256.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion8' */
  hvbd_st_accyRlyFlt = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-tmp :
    (sint32)(uint8)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  tmp = fmod(floor(swc_HVSM_ARID_DEF.AccyPreRlyFlt), 256.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  hvbd_st_accyPreRlyFlt = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-tmp
    : (sint32)(uint8)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  hvbd_b_accyWrkEnCmd = (swc_HVSM_ARID_DEF.accyWorkEnCmd != 0.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  tmp = fmod(floor(swc_HVSM_ARID_DEF.accyHvOnCmd), 256.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  hvbd_b_accyHvOnCmd = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-tmp :
    (sint32)(uint8)tmp);

  /* Switch: '<S2>/Switch7' incorporates:
   *  Constant: '<S2>/Constant27'
   *  RelationalOperator: '<S2>/Relational Operator12'
   *  Switch: '<S2>/Switch8'
   */
  if (swc_HVSM_ARID_DEF.accyWorkEnCmd != 0.0) {
    /* Switch: '<S2>/Switch9' */
    if (rtb_Switch1_nw) {
      /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
       *  DataTypeConversion: '<S2>/Data Type Conversion11'
       *  Inport generated from: '<Root>/In Bus Element12'
       *  Switch: '<S2>/Switch9'
       */
      hvbd_st_accyTakeSts = (uint8)
        Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_cntnrCtrlEnaFb();
    } else {
      /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
       *  Inport generated from: '<Root>/In Bus Element7'
       *  Switch: '<S2>/Switch9'
       */
      hvbd_st_accyTakeSts = Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_bbmWorkSts
        ();
    }

    /* End of Switch: '<S2>/Switch9' */
  } else if (swc_HVSM_ARID_DEF.AccyRlyFlt == ((uint8)1U)) {
    /* Switch: '<S2>/Switch8' incorporates:
     *  Constant: '<S2>/Constant26'
     *  DataTypeConversion: '<S2>/Data Type Conversion2'
     *  Switch: '<S2>/Switch7'
     */
    hvbd_st_accyTakeSts = ((uint8)2U);
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion2' incorporates:
     *  Constant: '<S2>/Constant25'
     *  Switch: '<S2>/Switch7'
     *  Switch: '<S2>/Switch8'
     */
    hvbd_st_accyTakeSts = ((uint8)0U);
  }

  /* End of Switch: '<S2>/Switch7' */

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  tmp = fmod(floor(swc_HVSM_ARID_DEF.accyWorkEnCmd), 256.0);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  hvbd_st_bbmWrkEnCmd = (uint8)(tmp < 0.0 ? (sint32)(uint8)-(sint8)(uint8)-tmp :
    (sint32)(uint8)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion5' */
  hvbd_st_accyRlyVoltSamSw = (uint8)hvbd_b_accyLvPwrOnCmd;

  /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  RelationalOperator: '<S9>/Relational Operator2'
   *  RelationalOperator: '<S9>/Relational Operator5'
   *  RelationalOperator: '<S9>/Relational Operator7'
   */
  rtb_LogicalOperator2_c_tmp = swc_HVSM_ARID_DEF.DataTypeConversion;

  /* Logic: '<S9>/Logical Operator2' incorporates:
   *  Constant: '<S15>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<S9>/Relational Operator1'
   *  RelationalOperator: '<S9>/Relational Operator2'
   *  RelationalOperator: '<S9>/Relational Operator5'
   *  RelationalOperator: '<S9>/Relational Operator7'
   */
  rtb_LogicalOperator2_c = ((rtb_LogicalOperator2_c_tmp == HVBattStatus_ACTIVE) ||
    (rtb_LogicalOperator2_c_tmp == HVBattStatus_SLOW_CHARGE) ||
    (rtb_LogicalOperator2_c_tmp == HVBattStatus_FAST_CHARGE) ||
    (rtb_LogicalOperator2_c_tmp == HVBattStatus_HEATING));

  /* Update for UnitDelay: '<S14>/Delay Input1'
   *
   * Block description for '<S14>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_o = tmp_1;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE = rtb_Sum;

  /* Update for UnitDelay: '<S8>/Delay Input1'
   *
   * Block description for '<S8>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_HVSM_ARID_DEF.DelayInput1_DSTATE_m =
    swc_HVSM_ARID_DEF.DataTypeConversion24;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  swc_HVSM_ARID_DEF.UnitDelay_DSTATE_b = hvbd_b_accyCtrlHw;

  /* Outport generated from: '<Root>/Out Bus Element50' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion18'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_bmsd_e_modeTgt(bmsd_e_modeTgt);

  /* Outport generated from: '<Root>/Out Bus Element' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion200'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_e_modeTgt(hvbd_e_modeTgt);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion198'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl
    (hvbd_b_hvBusShutDwnCmpl);

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion197'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_ptRdyInd(hvbd_st_ptRdyInd);

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion195'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_allowChg(hvbd_b_allowChg);

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion194'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_lvCutOffReq(hvbd_b_lvCutOffReq);

  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion192'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd(hvbd_b_vcuWkUpCmd);

  /* Outport generated from: '<Root>/Out Bus Element8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion190'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq
    (hvbd_st_hvbMaiRlyNegClsReq);

  /* Outport generated from: '<Root>/Out Bus Element9' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion189'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq
    (hvbd_st_hcmMaiRlyNegClsReq);

  /* Outport generated from: '<Root>/Out Bus Element11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion187'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq
    (hvbd_st_hvbAssiRlyPosClsReq);

  /* Outport generated from: '<Root>/Out Bus Element12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion204'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_obcd_e_chargerSts(obcd_e_chargerSts);

  /* Outport generated from: '<Root>/Out Bus Element14' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion203'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_obcd_b_chargerPlugged(obcd_b_chargerPlugged);

  /* Outport generated from: '<Root>/Out Bus Element15' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion185'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq
    (hvbd_st_hvbMaiRlyPosClsReq);

  /* Outport generated from: '<Root>/Out Bus Element16' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion184'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_e_PmmStatus(hvbd_e_PmmStatus);

  /* Outport generated from: '<Root>/Out Bus Element17' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion183'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_tmOutFlg(hvbd_b_tmOutFlg);

  /* Outport generated from: '<Root>/Out Bus Element18' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion202'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_eadd_e_inv2ModeTgt(eadd_e_inv2ModeTgt);

  /* Outport generated from: '<Root>/Out Bus Element19' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion181'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_tmOutFlgCfm(hvbd_b_tmOutFlgCfm);

  /* Outport generated from: '<Root>/Out Bus Element20' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion180'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_rlyTmOut(hvbd_b_rlyTmOut);

  /* Outport generated from: '<Root>/Out Bus Element21' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion201'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_eadd_b_ead2Avail(eadd_b_ead2Avail);

  /* Outport generated from: '<Root>/Out Bus Element22' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion178'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_vcuRdyToSlp(hvbd_b_vcuRdyToSlp);

  /* Outport generated from: '<Root>/Out Bus Element23' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion199'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_eadd_b_ead2Enad(eadd_b_ead2Enad);

  /* Outport generated from: '<Root>/Out Bus Element24' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion177'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt
    (swc_HVSM_ARID_DEF.hvbd_b_hvbIntelChgCmplt);

  /* Outport generated from: '<Root>/Out Bus Element25' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion175'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq
    (hvbd_b_hvbIntelChgExitReq);

  /* Outport generated from: '<Root>/Out Bus Element38' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion170'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_dccd_e_modeTgt(dccd_e_modeTgt);

  /* Outport generated from: '<Root>/Out Bus Element39' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion169'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_dccd_b_DCDCEnabled(dccd_b_DCDCEnabled);

  /* Outport generated from: '<Root>/Out Bus Element51' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion211'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_dccd_pct_DCDCPwrLmt
    (swchvsm_dccd_pct_DCDCPwrLmt);

  /* Outport generated from: '<Root>/Out Bus Element52' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion226'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_dchaOn(hvbd_b_dchaOn);

  /* Outport generated from: '<Root>/Out Bus Element53' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion227'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_fltPwrShutDn(hvbd_b_fltPwrShutDn);

  /* Outport generated from: '<Root>/Out Bus Element64' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion35'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_chgCablePlugged
    (hvbd_b_chgCablePlugged);

  /* Outport generated from: '<Root>/Out Bus Element54' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd(hvbd_b_accyWrkEnCmd);

  /* Outport generated from: '<Root>/Out Bus Element55' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd(hvbd_b_accyLvPwrOnCmd);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyHvOnCmd(hvbd_b_accyHvOnCmd != 0);

  /* Outport generated from: '<Root>/Out Bus Element56' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyTakeSts(hvbd_st_accyTakeSts);

  /* Outport generated from: '<Root>/Out Bus Element57' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_bbmWrkEnCmd(hvbd_st_bbmWrkEnCmd);

  /* Outport generated from: '<Root>/Out Bus Element58' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw
    (hvbd_st_accyRlyVoltSamSw);

  /* Outport generated from: '<Root>/Out Bus Element59' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyPreRlyCmd(hvbd_b_accyPreRlyCmd);

  /* Outport generated from: '<Root>/Out Bus Element60' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion11'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyPreRlySts(hvbd_st_accyPreRlySts);

  /* Outport generated from: '<Root>/Out Bus Element61' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion14'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlyFlt(hvbd_st_accyRlyFlt);

  /* Outport generated from: '<Root>/Out Bus Element62' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion23'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyPreRlyFlt(hvbd_st_accyPreRlyFlt);

  /* Outport generated from: '<Root>/Out Bus Element63' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion33'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlySts(rtb_DataTypeConversion10);

  /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion12'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_acPtcEnb(hvbd_b_acPtcEnb);

  /* Outport generated from: '<Root>/Out Bus Element10' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion20'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt
    (hvbd_st_RmChgCmdFailPmt);

  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion28'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV
    (hvbd_st_tboxChgSftSwCtlStEV);

  /* Outport generated from: '<Root>/Out Bus Element26' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion29'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq
    (hvbd_b_TakeEleSwtIndReq);

  /* Outport generated from: '<Root>/Out Bus Element27' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion30'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb
    (hvbd_pct_BookChrgnTarValFb);

  /* Outport generated from: '<Root>/Out Bus Element28' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion36'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_CampModeFb(hvbd_b_CampModeFb);

  /* Outport generated from: '<Root>/Out Bus Element29' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion38'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_CampModeFbFailrReason
    (swc_HVSM_ARID_DEF.Switch);

  /* Outport generated from: '<Root>/Out Bus Element30' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion39'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts
    (swc_HVSM_ARID_DEF.Switch20);

  /* Outport generated from: '<Root>/Out Bus Element31' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion40'
   */
  Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo
    (swc_HVSM_ARID_DEF.Switch24);
}

/* Model initialize function */
void swc_HVSM_Init(void)
{
  {
    /* local block i/o variables */
    boolean rtb_flg_out_jb;

    /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/OBC_ChargerStatus'
     */
    swc_HVSM_OBC_ChargerStatus_Init();

    /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/HVB_ModeManager'
     */
    swc_HVSM_HVB_ModeManager_Init();

    /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/EAD_ModeManagerMot2'
     */
    swc_HV_EAD_ModeManagerMot2_Init();

    /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */

    /* SystemInitialize for Atomic SubSystem: '<S2>/turnOFF_delay' */
    swc_HVSM_turnOFF_delay_Init(&rtb_flg_out_jb);

    /* End of SystemInitialize for SubSystem: '<S2>/turnOFF_delay' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
