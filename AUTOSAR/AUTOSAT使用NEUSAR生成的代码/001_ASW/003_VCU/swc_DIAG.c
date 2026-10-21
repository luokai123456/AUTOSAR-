/*
 * File: swc_DIAG.c
 *
 * Code generated for Simulink model 'swc_DIAG'.
 *
 * Model version                  : 6.377
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 21 15:45:21 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "swc_DIAG.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include "const_ImportedDefine.h"
#include "zero_crossing_types.h"

/*
 * Check that imported macros with storage class "ImportedDefine" are defined
 */
#ifndef ACP_TASK_INTERVAL_S
#error The value of parameter "ACP_TASK_INTERVAL_S" is not defined
#endif

#ifndef BRP_TASK_INTERVAL_S
#error The value of parameter "BRP_TASK_INTERVAL_S" is not defined
#endif

#ifndef CES_TASK_INTERVAL_S
#error The value of parameter "CES_TASK_INTERVAL_S" is not defined
#endif

#ifndef HVB_TASK_INTERVAL_S
#error The value of parameter "HVB_TASK_INTERVAL_S" is not defined
#endif

#ifndef MAC_TASK_INTERVAL_S
#error The value of parameter "MAC_TASK_INTERVAL_S" is not defined
#endif

/* Named constants for Chart: '<S165>/timed_debounce' */
#define swc_DIAG_IN_OFF                ((uint8)1U)
#define swc_DIAG_IN_OFF_WAIT           ((uint8)2U)
#define swc_DIAG_IN_ON                 ((uint8)3U)
#define swc_DIAG_IN_ON_WAIT            ((uint8)4U)

/* Named constants for Chart: '<S161>/timed_delay' */
#define swc_DIAG_IN_OFF_WAIT_b         ((uint8)2U)
#define swc_DIAG_IN_OFF_n              ((uint8)1U)
#define swc_DIAG_IN_ON_a               ((uint8)3U)

/* Named constants for Chart: '<S224>/timed_delay' */
#define swc_DIAG_IN_OFF_h              ((uint8)1U)
#define swc_DIAG_IN_ON_WAIT_j          ((uint8)3U)
#define swc_DIAG_IN_ON_k               ((uint8)2U)

/* Named constants for Chart: '<S48>/timed_debounce' */
#define swc_DIAG_IN_NO_ACTIVE_CHILD    ((uint8)0U)
#define swc_DIAG_IN_OFF_WAIT_o         ((uint8)2U)
#define swc_DIAG_IN_OFF_no             ((uint8)1U)
#define swc_DIAG_IN_ON_WAIT_l          ((uint8)4U)
#define swc_DIAG_IN_ON_j               ((uint8)3U)

/* Named constants for Chart: '<S125>/timed_debounce' */
#define swc_DIAG_IN_NO_ACTIVE_CHILD_f  ((uint8)0U)
#define swc_DIAG_IN_OFF_WAIT_d         ((uint8)2U)
#define swc_DIAG_IN_OFF_j              ((uint8)1U)
#define swc_DIAG_IN_ON_WAIT_m          ((uint8)4U)
#define swc_DIAG_IN_ON_ju              ((uint8)3U)

/* Named constants for Chart: '<S117>/Chart1' */
#define swc_DIAG_IN_CLEAR1             ((uint8)1U)
#define swc_DIAG_IN_CLEAR2             ((uint8)2U)
#define swc_DIAG_IN_ERRCN1             ((uint8)3U)
#define swc_DIAG_IN_INIT               ((uint8)4U)
#define swc_DIAG_IN_STATE1             ((uint8)5U)
#define swc_DIAG_IN_STATE2             ((uint8)6U)

/* Named constants for Chart: '<S175>/timed_debounce' */
#define swc_DIAG_IN_NO_ACTIVE_CHILD_p  ((uint8)0U)
#define swc_DIAG_IN_OFF_WAIT_l         ((uint8)2U)
#define swc_DIAG_IN_OFF_nb             ((uint8)1U)
#define swc_DIAG_IN_ON_WAIT_mt         ((uint8)4U)
#define swc_DIAG_IN_ON_av              ((uint8)3U)

/* Named constants for Chart: '<S189>/timed_debounce' */
#define swc_DIAG_IN_NO_ACTIVE_CHILD_k  ((uint8)0U)
#define swc_DIAG_IN_OFF_WAIT_ow        ((uint8)2U)
#define swc_DIAG_IN_OFF_m              ((uint8)1U)
#define swc_DIAG_IN_ON_WAIT_h          ((uint8)4U)
#define swc_DIAG_IN_ON_h               ((uint8)3U)

/* Named constants for Chart: '<S218>/timed_debounce' */
#define swc_DIAG_IN_NO_ACTIVE_CHILD_b  ((uint8)0U)
#define swc_DIAG_IN_OFF_WAIT_p         ((uint8)2U)
#define swc_DIAG_IN_OFF_o              ((uint8)1U)
#define swc_DIAG_IN_ON_WAIT_lh         ((uint8)4U)
#define swc_DIAG_IN_ON_b               ((uint8)3U)

/* Named constants for Chart: '<S295>/timed_debounce' */
#define swc_DIAG_IN_NO_ACTIVE_CHILD_b0 ((uint8)0U)
#define swc_DIAG_IN_OFF_WAIT_i         ((uint8)2U)
#define swc_DIAG_IN_OFF_e              ((uint8)1U)
#define swc_DIAG_IN_ON_WAIT_g          ((uint8)4U)
#define swc_DIAG_IN_ON_kn              ((uint8)3U)

/* Named constants for Chart: '<S401>/timed_debounce' */
#define swc_DIAG_IN_NO_ACTIVE_CHILD_d  ((uint8)0U)
#define swc_DIAG_IN_OFF_WAIT_ik        ((uint8)2U)
#define swc_DIAG_IN_OFF_k              ((uint8)1U)
#define swc_DIAG_IN_ON_WAIT_f          ((uint8)4U)
#define swc_DIAG_IN_ON_e               ((uint8)3U)

/* Exported data definition */
#define swc_DIAG_START_SEC_CONST_VOLATILE
#include "swc_DIAG_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_CAL */
const volatile boolean acpc_b_acp1RngHiEnb_ovrdflg = false;
                        /* Referenced by: '<S21>/acpc_b_acp1RngHiEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal1ORHigh */
const volatile boolean acpc_b_acp1RngHiEnb_ovrdval = false;
                        /* Referenced by: '<S21>/acpc_b_acp1RngHiEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal1ORHigh */
const volatile float32 acpc_b_acp1RngHiFail_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_fail3' */

/* DFC_HYB_ACCPedal1ORHigh fault set threshold */
const volatile float32 acpc_b_acp1RngHiHeal_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_heal3' */

/* DFC_HYB_ACCPedal1ORHigh fault clear threshold */
const volatile boolean acpc_b_acp1RngHiSet_ovrdflg = false;
                        /* Referenced by: '<S22>/acpc_b_acp1RngHiSet_ovrdflg' */

/* Override flag for signal acpd_b_acp1RngHiSet */
const volatile boolean acpc_b_acp1RngHiSet_ovrdval = false;
                        /* Referenced by: '<S22>/acpc_b_acp1RngHiSet_ovrdval' */

/* Override value for signal acpd_b_acp1RngHiSet */
const volatile boolean acpc_b_acp1RngLowEnb_ovrdflg = false;
                       /* Referenced by: '<S23>/acpc_b_acp1RngLowEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal1ORLow */
const volatile boolean acpc_b_acp1RngLowEnb_ovrdval = false;
                       /* Referenced by: '<S23>/acpc_b_acp1RngLowEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal1ORLow */
const volatile float32 acpc_b_acp1RngLowFail_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_fail2' */

/* DFC_HYB_ACCPedal1ORLow fault set threshold */
const volatile float32 acpc_b_acp1RngLowHeal_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_heal2' */

/* DFC_HYB_ACCPedal1ORLow fault clear threshold */
const volatile boolean acpc_b_acp1RngLowSet_ovrdflg = false;
                       /* Referenced by: '<S24>/acpc_b_acp1RngLowSet_ovrdflg' */

/* Override flag for signal acpd_b_acp1RngLowSet */
const volatile boolean acpc_b_acp1RngLowSet_ovrdval = false;
                       /* Referenced by: '<S24>/acpc_b_acp1RngLowSet_ovrdval' */

/* Override value for signal acpd_b_acp1RngLowSet */
const volatile boolean acpc_b_acp1Sho2BatEnb_ovrdflg = false;
                      /* Referenced by: '<S25>/acpc_b_acp1Sho2BatEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal1SCB */
const volatile boolean acpc_b_acp1Sho2BatEnb_ovrdval = false;
                      /* Referenced by: '<S25>/acpc_b_acp1Sho2BatEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal1SCB */
const volatile float32 acpc_b_acp1Sho2BatFail_s = 1.5F;
                                      /* Referenced by: '<S11>/t_delay_fail1' */

/* DFC_HYB_ACCPedal1SCB fault set threshold */
const volatile float32 acpc_b_acp1Sho2BatHeal_s = 1.5F;
                                      /* Referenced by: '<S11>/t_delay_heal1' */

/* DFC_HYB_ACCPedal1SCB fault clear threshold */
const volatile boolean acpc_b_acp1Sho2BatSet_ovrdflg = false;
                      /* Referenced by: '<S26>/acpc_b_acp1Sho2BatSet_ovrdflg' */

/* Override flag for signal acpd_b_acp1Sho2BatSet */
const volatile boolean acpc_b_acp1Sho2BatSet_ovrdval = false;
                      /* Referenced by: '<S26>/acpc_b_acp1Sho2BatSet_ovrdval' */

/* Override value for signal acpd_b_acp1Sho2BatSet */
const volatile boolean acpc_b_acp1Sho2GndEnb_ovrdflg = false;
                      /* Referenced by: '<S27>/acpc_b_acp1Sho2GndEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal1SCG */
const volatile boolean acpc_b_acp1Sho2GndEnb_ovrdval = false;
                      /* Referenced by: '<S27>/acpc_b_acp1Sho2GndEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal1SCG */
const volatile float32 acpc_b_acp1Sho2GndFail_s = 1.5F;/* Referenced by: '<S11>/t_delay_fail' */

/* DFC_HYB_ACCPedal1SCG fault set threshold */
const volatile float32 acpc_b_acp1Sho2GndHeal_s = 1.5F;/* Referenced by: '<S11>/t_delay_heal' */

/* DFC_HYB_ACCPedal1SCG fault clear threshold */
const volatile boolean acpc_b_acp1Sho2GndSet_ovrdflg = false;
                      /* Referenced by: '<S28>/acpc_b_acp1Sho2GndSet_ovrdflg' */

/* Override flag for signal acpd_b_acp1Sho2GndSet */
const volatile boolean acpc_b_acp1Sho2GndSet_ovrdval = false;
                      /* Referenced by: '<S28>/acpc_b_acp1Sho2GndSet_ovrdval' */

/* Override value for signal acpd_b_acp1Sho2GndSet */
const volatile boolean acpc_b_acp2RngHiEnb_ovrdflg = false;
                        /* Referenced by: '<S29>/acpc_b_acp2RngHiEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal2ORHigh */
const volatile boolean acpc_b_acp2RngHiEnb_ovrdval = false;
                        /* Referenced by: '<S29>/acpc_b_acp2RngHiEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal2ORHigh */
const volatile float32 acpc_b_acp2RngHiFail_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_fail7' */

/* DFC_HYB_ACCPedal2ORHigh fault set threshold */
const volatile float32 acpc_b_acp2RngHiHeal_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_heal7' */

/* DFC_HYB_ACCPedal2ORHigh fault clear threshold */
const volatile boolean acpc_b_acp2RngHiSet_ovrdflg = false;
                        /* Referenced by: '<S30>/acpc_b_acp2RngHiSet_ovrdflg' */

/* Override flag for signal acpd_b_acp2RngHiSet */
const volatile boolean acpc_b_acp2RngHiSet_ovrdval = false;
                        /* Referenced by: '<S30>/acpc_b_acp2RngHiSet_ovrdval' */

/* Override value for signal acpd_b_acp2RngHiSet */
const volatile boolean acpc_b_acp2RngLowEnb_ovrdflg = false;
                       /* Referenced by: '<S31>/acpc_b_acp2RngLowEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal2ORLow */
const volatile boolean acpc_b_acp2RngLowEnb_ovrdval = false;
                       /* Referenced by: '<S31>/acpc_b_acp2RngLowEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal2ORLow */
const volatile float32 acpc_b_acp2RngLowFail_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_fail6' */

/* DFC_HYB_ACCPedal2ORLow fault set threshold */
const volatile float32 acpc_b_acp2RngLowHeal_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_heal6' */

/* DFC_HYB_ACCPedal2ORLow fault clear threshold */
const volatile boolean acpc_b_acp2RngLowSet_ovrdflg = false;
                       /* Referenced by: '<S32>/acpc_b_acp2RngLowSet_ovrdflg' */

/* Override flag for signal acpd_b_acp2RngLowSet */
const volatile boolean acpc_b_acp2RngLowSet_ovrdval = false;
                       /* Referenced by: '<S32>/acpc_b_acp2RngLowSet_ovrdval' */

/* Override value for signal acpd_b_acp2RngLowSet */
const volatile boolean acpc_b_acp2Sho2BatEnb_ovrdflg = false;
                      /* Referenced by: '<S33>/acpc_b_acp2Sho2BatEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal2SCB */
const volatile boolean acpc_b_acp2Sho2BatEnb_ovrdval = false;
                      /* Referenced by: '<S33>/acpc_b_acp2Sho2BatEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal2SCB */
const volatile float32 acpc_b_acp2Sho2BatFail_s = 1.5F;
                                      /* Referenced by: '<S11>/t_delay_fail5' */

/* DFC_HYB_ACCPedal2SCB fault set threshold */
const volatile float32 acpc_b_acp2Sho2BatHeal_s = 1.5F;
                                      /* Referenced by: '<S11>/t_delay_heal5' */

/* DFC_HYB_ACCPedal2SCB fault clear threshold */
const volatile boolean acpc_b_acp2Sho2BatSet_ovrdflg = false;
                      /* Referenced by: '<S34>/acpc_b_acp2Sho2BatSet_ovrdflg' */

/* Override flag for signal acpd_b_acp2Sho2BatSet */
const volatile boolean acpc_b_acp2Sho2BatSet_ovrdval = false;
                      /* Referenced by: '<S34>/acpc_b_acp2Sho2BatSet_ovrdval' */

/* Override value for signal acpd_b_acp2Sho2BatSet */
const volatile boolean acpc_b_acp2Sho2GndEnb_ovrdflg = false;
                      /* Referenced by: '<S35>/acpc_b_acp2Sho2GndEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal2SCG */
const volatile boolean acpc_b_acp2Sho2GndEnb_ovrdval = false;
                      /* Referenced by: '<S35>/acpc_b_acp2Sho2GndEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal2SCG */
const volatile float32 acpc_b_acp2Sho2GndFail_s = 1.5F;
                                      /* Referenced by: '<S11>/t_delay_fail4' */

/* DFC_HYB_ACCPedal2SCG fault set threshold */
const volatile float32 acpc_b_acp2Sho2GndHeal_s = 1.5F;
                                      /* Referenced by: '<S11>/t_delay_heal4' */

/* DFC_HYB_ACCPedal2SCG fault clear threshold */
const volatile boolean acpc_b_acp2Sho2GndSet_ovrdflg = false;
                      /* Referenced by: '<S36>/acpc_b_acp2Sho2GndSet_ovrdflg' */

/* Override flag for signal acpd_b_acp2Sho2GndSet */
const volatile boolean acpc_b_acp2Sho2GndSet_ovrdval = false;
                      /* Referenced by: '<S36>/acpc_b_acp2Sho2GndSet_ovrdval' */

/* Override value for signal acpd_b_acp2Sho2GndSet */
const volatile boolean acpc_b_acpCrsFltEnb_ovrdflg = false;
                        /* Referenced by: '<S37>/acpc_b_acpCrsFltEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedalCrossNP */
const volatile boolean acpc_b_acpCrsFltEnb_ovrdval = false;
                        /* Referenced by: '<S37>/acpc_b_acpCrsFltEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedalCrossNP */
const volatile boolean acpc_b_acpCrsFltSet_ovrdflg = false;
                        /* Referenced by: '<S38>/acpc_b_acpCrsFltSet_ovrdflg' */

/* Override flag for signal acpd_b_acpCrsFltSet */
const volatile boolean acpc_b_acpCrsFltSet_ovrdval = false;
                        /* Referenced by: '<S38>/acpc_b_acpCrsFltSet_ovrdval' */

/* Override value for signal acpd_b_acpCrsFltSet */
const volatile boolean brpc_b_VacPumpEnOvrTmHiPreFltSet_ovrdflg = false;
                /* Referenced by: '<S111>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
const volatile boolean brpc_b_VacPumpEnOvrTmHiPreFltSet_ovrdval = false;
                /* Referenced by: '<S111>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
const volatile boolean brpc_b_VacPumpEnOvrTmLoPreFltSet_ovrdflg = false;
                /* Referenced by: '<S112>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
const volatile boolean brpc_b_VacPumpEnOvrTmLoPreFltSet_ovrdval = false;
                /* Referenced by: '<S112>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
const volatile boolean brpc_b_VacPumpLoPreFltSet_ovrdflg = false;
                /* Referenced by: '<S113>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
const volatile boolean brpc_b_VacPumpLoPreFltSet_ovrdval = false;
                /* Referenced by: '<S113>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
const volatile boolean brpc_b_VacPumpRlyFltSet_ovrdflg = false;
                /* Referenced by: '<S114>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
const volatile boolean brpc_b_VacPumpRlyFltSet_ovrdval = false;
                /* Referenced by: '<S114>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
const volatile boolean brpc_b_VacPumpSnrFltSet_ovrdflg = false;
                /* Referenced by: '<S115>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
const volatile boolean brpc_b_VacPumpSnrFltSet_ovrdval = false;
                /* Referenced by: '<S115>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
const volatile boolean brpc_b_VacPumpSysFailFltSet_ovrdflg = false;
                /* Referenced by: '<S116>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
const volatile boolean brpc_b_VacPumpSysFailFltSet_ovrdval = false;
                /* Referenced by: '<S116>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
const volatile boolean brpc_b_brkSwtMismatchEnb_ovrdflg = false;
                  /* Referenced by: '<S109>/brpc_b_brkSwtMismatchEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_BrkSthNP */
const volatile boolean brpc_b_brkSwtMismatchEnb_ovrdval = false;
                  /* Referenced by: '<S109>/brpc_b_brkSwtMismatchEnb_ovrdval' */

/* Override value to enable DFC_HYB_BrkSthNP */
const volatile float32 brpc_b_brkSwtMismatchHeal_s = 1.0F;
                                     /* Referenced by: '<S159>/t_delay_heal3' */

/* DFC_HYB_BrkSthNP fault clear threshold */
const volatile boolean brpc_b_brkSwtMismatchSet_ovrdflg = false;
                  /* Referenced by: '<S110>/brpc_b_brkSwtMismatchSet_ovrdflg' */

/* Override flag for signal brpd_b_brkSwtMismatchSet */
const volatile boolean brpc_b_brkSwtMismatchSet_ovrdval = false;
                  /* Referenced by: '<S110>/brpc_b_brkSwtMismatchSet_ovrdval' */

/* Override value for signal brpd_b_brkSwtMismatchSet */
const volatile boolean cesc_b_crashEventEnb_ovrdflg = false;
                      /* Referenced by: '<S171>/cesc_b_crashEventEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_CrashEvent */
const volatile boolean cesc_b_crashEventEnb_ovrdval = false;
                      /* Referenced by: '<S171>/cesc_b_crashEventEnb_ovrdval' */

/* Override value to enable DFC_HYB_CrashEvent */
const volatile boolean cesc_b_crashEventSet_ovrdflg = false;
                      /* Referenced by: '<S172>/cesc_b_crashEventSet_ovrdflg' */

/* Override flag for signal cesd_b_crashEventSet */
const volatile boolean cesc_b_crashEventSet_ovrdval = false;
                      /* Referenced by: '<S172>/cesc_b_crashEventSet_ovrdval' */

/* Override value for signal cesd_b_crashEventSet */
const volatile boolean ddic_b_forceDisDTCFcnCall = false;
                                     /* Referenced by: '<S206>/t_delay_heal2' */
const volatile float32 digc_ABSMsgErr2fail_s = 0.25F;/* Referenced by: '<S8>/Constant156' */

/* macc_ABSMsgErr2fail_s fault set threshold */
const volatile float32 digc_ABSMsgErr2heal_s = 0.25F;/* Referenced by: '<S8>/Constant157' */

/* macc_ABSMsgErr2heal_s fault clear threshold */
const volatile float32 digc_ABSSpdMsgErr2fail_s = 0.25F;/* Referenced by: '<S8>/Constant223' */

/* macc_ABSSpdMsgErr2fail_s fault set threshold */
const volatile float32 digc_ABSSpdMsgErr2heal_s = 0.25F;/* Referenced by: '<S8>/Constant224' */

/* macc_ABSSpdMsgErr2heal_s fault clear threshold */
const volatile float32 digc_ACUMsgErrfail_s = 0.25F;/* Referenced by: '<S8>/Constant15' */
const volatile float32 digc_ACUMsgErrheal_s = 0.25F;/* Referenced by: '<S8>/Constant16' */
const volatile float32 digc_BMSHealthMonErrfail_s = 0.25F;/* Referenced by: '<S8>/Constant18' */
const volatile float32 digc_BMSHealthMonErrheal_s = 0.25F;/* Referenced by: '<S8>/Constant19' */
const volatile float32 digc_CSMMsgErrfail_s = 0.5F;/* Referenced by: '<S8>/Constant24' */
const volatile float32 digc_CSMMsgErrheal_s = 0.5F;/* Referenced by: '<S8>/Constant25' */
const volatile float32 digc_DCDCMsgErr2fail_s = 0.5F;/* Referenced by: '<S8>/Constant175' */

/* macc_DCDCMsgErr2fail_s fault set threshold */
const volatile float32 digc_DCDCMsgErr2heal_s = 0.5F;/* Referenced by: '<S8>/Constant176' */

/* macc_DCDCMsgErr2heal_s fault clear threshold */
const volatile float32 digc_EGSMMsgErr2fail_s = 0.25F;/* Referenced by: '<S8>/Constant189' */

/* macc_EGSMMsgErr2fail_s fault set threshold */
const volatile float32 digc_EGSMMsgErr2heal_s = 0.25F;/* Referenced by: '<S8>/Constant192' */

/* macc_EGSMMsgErr2heal_s fault clear threshold */
const volatile float32 digc_MCUHealthMonErrfail_s = 0.25F;/* Referenced by: '<S8>/Constant21' */
const volatile float32 digc_MCUHealthMonErrheal_s = 0.25F;/* Referenced by: '<S8>/Constant22' */
const volatile float32 digc_PEPSMsgErr2fail_s = 0.25F;/* Referenced by: '<S8>/Constant2' */

/* macc_PEPSMsgErr2fail_s fault set threshold */
const volatile float32 digc_PEPSMsgErr2heal_s = 0.25F;/* Referenced by: '<S8>/Constant3' */

/* macc_PEPSMsgErr2heal_s fault clear threshold */
const volatile float32 digc_b_acpCrsFltFail_s = 3.0F;
                                      /* Referenced by: '<S11>/t_delay_fail8' */
const volatile float32 digc_b_acpCrsFltHeal_s = 2.0F;
                                      /* Referenced by: '<S11>/t_delay_heal8' */
const volatile float32 digc_b_batIntSmplHiFail_s = 6.0F;/* Referenced by: '<S8>/t_delay_fail1' */
const volatile float32 digc_b_batIntSmplLoFail_s = 6.0F;/* Referenced by: '<S8>/t_delay_fail' */
const volatile float32 digc_b_brkSwtMismatchFail_s = 120.0F;/* Referenced by:
                                                             * '<S117>/t_delay_fail1'
                                                             * '<S159>/t_delay_fail3'
                                                             */
const volatile float32 digc_b_crashEventFail_s = 0.25F;/* Referenced by: '<S4>/t_delay_fail' */
const volatile float32 digc_b_crashEventHeal_s = 0.25F;/* Referenced by: '<S4>/t_delay_heal' */
const volatile boolean digc_b_edcpBlock_ovrdflg = false;
                  /* Referenced by: '<S395>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_edcpBlock_ovrdval = false;
                  /* Referenced by: '<S395>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_edcpIdly_ovrdflg = false;
                  /* Referenced by: '<S392>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_edcpIdly_ovrdval = false;
                  /* Referenced by: '<S392>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_edcpOvrCurr_ovrdflg = false;
                  /* Referenced by: '<S396>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_edcpOvrCurr_ovrdval = false;
                  /* Referenced by: '<S396>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_edcpOvrTmp_ovrdflg = false;
                  /* Referenced by: '<S388>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_edcpOvrTmp_ovrdval = false;
                  /* Referenced by: '<S388>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_edcpOvrVolt_ovrdflg = false;
                  /* Referenced by: '<S394>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_edcpOvrVolt_ovrdval = false;
                  /* Referenced by: '<S394>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_edcpUdVolt_ovrdflg = false;
                  /* Referenced by: '<S393>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_edcpUdVolt_ovrdval = false;
                  /* Referenced by: '<S393>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_evtFaildBMSFaultLevel4A_ovrdflg = false;/* Referenced by: '<S7>/DFC_ovrdflg' */
const volatile boolean digc_b_evtFaildBMSFaultLevel4A_ovrdval = false;/* Referenced by: '<S7>/DFC_ovrdval' */
const volatile boolean digc_b_evtFaildCrashEvent_ovrdflg = false;/* Referenced by: '<S4>/DFC_ovrdflg' */
const volatile boolean digc_b_evtFaildCrashEvent_ovrdval = false;/* Referenced by: '<S4>/DFC_ovrdval' */
const volatile boolean digc_b_hbcpBlock_ovrdflg = false;
                  /* Referenced by: '<S390>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_hbcpBlock_ovrdval = false;
                  /* Referenced by: '<S390>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_hbcpIdly_ovrdflg = false;
                  /* Referenced by: '<S398>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_hbcpIdly_ovrdval = false;
                  /* Referenced by: '<S398>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_hbcpOvrCurr_ovrdflg = false;
                  /* Referenced by: '<S391>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_hbcpOvrCurr_ovrdval = false;
                  /* Referenced by: '<S391>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_hbcpOvrTmp_ovrdflg = false;
                  /* Referenced by: '<S397>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_hbcpOvrTmp_ovrdval = false;
                  /* Referenced by: '<S397>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_hbcpOvrVolt_ovrdflg = false;
                  /* Referenced by: '<S389>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_hbcpOvrVolt_ovrdval = false;
                  /* Referenced by: '<S389>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile boolean digc_b_hbcpUdVolt_ovrdflg = false;
                  /* Referenced by: '<S399>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
const volatile boolean digc_b_hbcpUdVolt_ovrdval = false;
                  /* Referenced by: '<S399>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
const volatile float32 digc_cCanBusOfffail_s = 1.0F;/* Referenced by: '<S8>/Constant170' */
const volatile float32 digc_cCanBusOffheal_s = 0.0F;/* Referenced by: '<S8>/Constant174' */
const volatile float32 digc_evCanBusOfffail_s = 1.0F;/* Referenced by:
                                                      * '<S8>/Constant1'
                                                      * '<S8>/Constant243'
                                                      */
const volatile float32 digc_evCanBusOffheal_s = 0.0F;/* Referenced by:
                                                      * '<S8>/Constant244'
                                                      * '<S8>/Constant5'
                                                      */
const volatile float32 digc_ptCanBusOfffail_s = 1.0F;/* Referenced by: '<S8>/Constant188' */
const volatile float32 digc_ptCanBusOffheal_s = 0.0F;/* Referenced by: '<S8>/Constant194' */
const volatile float32 digc_tm_brkStsOffDly_s = 1.0F;
                                     /* Referenced by: '<S117>/t_delay_heal3' */
const volatile float32 digc_tm_brkStsOpenDly_s = 1.0F;
                                     /* Referenced by: '<S117>/t_delay_heal2' */
const volatile float32 digc_u_acp1RngHiSet_V = 4.5F;/* Referenced by: '<S11>/Constant12' */

/* Accel pedal 1 range high fault set threshold */
const volatile float32 digc_u_acp1RngLowSet_V = 0.5F;/* Referenced by: '<S11>/Constant28' */

/* Accel pedal 1 range low fault set threshold */
const volatile float32 digc_u_acp1Sho2BatSet_V = 4.9F;/* Referenced by: '<S11>/Constant8' */

/* Accel pedal 1 short to 12V battery fault set */
const volatile float32 digc_u_acp1Sho2GndSet_V = 0.1F;/* Referenced by: '<S11>/Constant' */

/* Accel pedal 1 short to ground fault set */
const volatile float32 digc_u_acp2RngHiSet_V = 2.25F;/* Referenced by: '<S11>/Constant19' */

/* Accel pedal 2 range high fault set threshold */
const volatile float32 digc_u_acp2RngLowSet_V = 0.25F;/* Referenced by: '<S11>/Constant32' */

/* Accel pedal 2 range low fault set threshold */
const volatile float32 digc_u_acp2Sho2BatSet_V = 4.9F;/* Referenced by: '<S11>/Constant26' */

/* Accel pedal 2 short to 12V battery fault set threshold */
const volatile float32 digc_u_acp2Sho2GndSet_V = 0.1F;/* Referenced by: '<S11>/Constant16' */

/* Accel pedal 2 short to ground fault set threshold */
const volatile float32 digc_u_acpCrsFltSet_V = 0.35F;/* Referenced by: '<S11>/Constant36' */

/* Accel pedal cross fault set threshold */
const volatile boolean digd_b_VehLvl1Flt_ovrdflg = false;/* Referenced by: '<S197>/Constant5' */

/* Override flag for digd_b_VehLvl1Flt */
const volatile boolean digd_b_VehLvl1Flt_ovrdval = false;/* Referenced by: '<S197>/Constant6' */

/* Override value for digd_b_VehLvl1Flt */
const volatile boolean digd_b_VehLvl21Flt_ovrdflg = false;/* Referenced by: '<S198>/Constant2' */

/* Override flag for digd_b_VehLvl21Flt */
const volatile boolean digd_b_VehLvl21Flt_ovrdval = false;/* Referenced by: '<S198>/Constant3' */

/* Override value for digd_b_VehLvl21Flt */
const volatile boolean digd_b_VehLvl22Flt_ovrdflg = false;/* Referenced by: '<S199>/Constant16' */

/* Override flag for digd_b_VehLvl21Flt */
const volatile boolean digd_b_VehLvl22Flt_ovrdval = false;/* Referenced by: '<S199>/Constant17' */

/* Override value for digd_b_VehLvl21Flt */
const volatile boolean digd_b_VehLvl23Flt_ovrdflg = false;/* Referenced by: '<S200>/Constant18' */

/* Override flag for digd_b_VehLvl21Flt */
const volatile boolean digd_b_VehLvl23Flt_ovrdval = false;/* Referenced by: '<S200>/Constant19' */

/* Override value for digd_b_VehLvl21Flt */
const volatile boolean digd_b_VehLvl31Flt_ovrdflg = false;/* Referenced by: '<S201>/Constant7' */

/* Override flag for digd_b_VehLvl31Flt */
const volatile boolean digd_b_VehLvl31Flt_ovrdval = false;/* Referenced by: '<S201>/Constant8' */

/* Override value for digd_b_VehLvl31Flt */
const volatile boolean digd_b_VehLvl32Flt_ovrdflg = false;/* Referenced by: '<S202>/Constant9' */

/* Override flag for digd_b_VehLvl32Flt */
const volatile boolean digd_b_VehLvl32Flt_ovrdval = false;/* Referenced by: '<S202>/Constant10' */

/* Override value for digd_b_VehLvl32Flt */
const volatile boolean digd_b_VehLvl33Flt_ovrdflg = false;/* Referenced by: '<S203>/Constant2' */

/* Override flag for digd_b_VehLvl33Flt */
const volatile boolean digd_b_VehLvl33Flt_ovrdval = false;/* Referenced by: '<S203>/Constant12' */

/* Override value for digd_b_VehLvl33Flt */
const volatile boolean hvbc_b_BMSFaultLevel2ASet_ovrdflg = false;
                      /* Referenced by: '<S210>/hvbc_b_vehHvilFltSet_ovrdflg' */
const volatile boolean hvbc_b_BMSFaultLevel2ASet_ovrdval = false;
                      /* Referenced by: '<S210>/hvbc_b_vehHvilFltSet_ovrdval' */
const volatile boolean hvbc_b_BMSFaultLevel3ASet_ovrdflg = false;
                      /* Referenced by: '<S211>/hvbc_b_vehHvilFltSet_ovrdflg' */
const volatile boolean hvbc_b_BMSFaultLevel3ASet_ovrdval = false;
                      /* Referenced by: '<S211>/hvbc_b_vehHvilFltSet_ovrdval' */
const volatile boolean hvbc_b_BMSFaultLevel4ASet_ovrdflg = false;
                      /* Referenced by: '<S212>/hvbc_b_vehHvilFltSet_ovrdflg' */
const volatile boolean hvbc_b_BMSFaultLevel4ASet_ovrdval = false;
                      /* Referenced by: '<S212>/hvbc_b_vehHvilFltSet_ovrdval' */
const volatile boolean hvbc_b_MCUFaultLevel2ASet_ovrdflg = false;
                      /* Referenced by: '<S184>/hvbc_b_vehHvilFltSet_ovrdflg' */
const volatile boolean hvbc_b_MCUFaultLevel2ASet_ovrdval = false;
                      /* Referenced by: '<S184>/hvbc_b_vehHvilFltSet_ovrdval' */
const volatile boolean hvbc_b_MCUFaultLevel3ASet_ovrdflg = false;
                      /* Referenced by: '<S185>/hvbc_b_vehHvilFltSet_ovrdflg' */
const volatile boolean hvbc_b_MCUFaultLevel3ASet_ovrdval = false;
                      /* Referenced by: '<S185>/hvbc_b_vehHvilFltSet_ovrdval' */
const volatile float32 hvbc_b_vehHvilFltFail_s = 0.01F;/* Referenced by: '<S7>/t_delay_fail7' */

/* DFC_HYB_VehicleHVILFlt fault set threshold */
const volatile float32 hvbc_b_vehHvilFltHeal_s = 0.01F;/* Referenced by: '<S7>/t_delay_heal7' */

/* DFC_HYB_VehicleHVILFlt fault clear threshold */
const volatile boolean hvbc_b_vehHvilFltSet_ovrdflg = false;
                      /* Referenced by: '<S209>/hvbc_b_vehHvilFltSet_ovrdflg' */

/* Override flag for signal hvbd_b_vehHvilFltSet */
const volatile boolean hvbc_b_vehHvilFltSet_ovrdval = false;
                      /* Referenced by: '<S209>/hvbc_b_vehHvilFltSet_ovrdval' */

/* Override value for signal hvbd_b_vehHvilFltSet */
const volatile boolean macc_b_5VT1IntSmplFltEnb_ovrdflg = false;
                  /* Referenced by: '<S259>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_T5V1Mon */
const volatile boolean macc_b_5VT1IntSmplFltEnb_ovrdval = false;
                  /* Referenced by: '<S259>/macc_b_5VT1IntSmplFltEnb_ovrdval' */

/* Override value to enable DFC_HYB_T5V1Mon */
const volatile float32 macc_b_5VT1IntSmplFltFail_s = 0.5F;/* Referenced by: '<S8>/t_delay_fail2' */

/* DFC_HYB_T5V1Mon fault set threshold */
const volatile float32 macc_b_5VT1IntSmplFltHeal_s = 0.5F;/* Referenced by: '<S8>/t_delay_heal2' */

/* DFC_HYB_T5V1Mon fault clear threshold */
const volatile boolean macc_b_5VT1IntSmplFltSet_ovrdflg = false;
                  /* Referenced by: '<S260>/macc_b_5VT1IntSmplFltSet_ovrdflg' */

/* Override flag for signal macd_b_5VT1IntSmplFltSet */
const volatile boolean macc_b_5VT1IntSmplFltSet_ovrdval = false;
                  /* Referenced by: '<S260>/macc_b_5VT1IntSmplFltSet_ovrdval' */

/* Override value for signal macd_b_5VT1IntSmplFltSet */
const volatile boolean macc_b_5VT2IntSmplFltEnb_ovrdflg = false;
                  /* Referenced by: '<S261>/macc_b_5VT2IntSmplFltEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_T5V2Mon */
const volatile boolean macc_b_5VT2IntSmplFltEnb_ovrdval = false;
                  /* Referenced by: '<S261>/macc_b_5VT2IntSmplFltEnb_ovrdval' */

/* Override value to enable DFC_HYB_T5V2Mon */
const volatile float32 macc_b_5VT2IntSmplFltFail_s = 0.5F;/* Referenced by: '<S8>/t_delay_fail3' */

/* DFC_HYB_T5V2Mon fault set threshold */
const volatile float32 macc_b_5VT2IntSmplFltHeal_s = 0.5F;/* Referenced by: '<S8>/t_delay_heal3' */

/* DFC_HYB_T5V2Mon fault clear threshold */
const volatile boolean macc_b_5VT2IntSmplFltSet_ovrdflg = false;
                  /* Referenced by: '<S262>/macc_b_5VT2IntSmplFltSet_ovrdflg' */

/* Override flag for signal macd_b_5VT2IntSmplFltSet */
const volatile boolean macc_b_5VT2IntSmplFltSet_ovrdval = false;
                  /* Referenced by: '<S262>/macc_b_5VT2IntSmplFltSet_ovrdval' */

/* Override value for signal macd_b_5VT2IntSmplFltSet */
const volatile boolean macc_b_ABSMsgErrSet_ovrdflg = false;
                    /* Referenced by: '<S273>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_ABSMsgErrSet_ovrdval = false;
                    /* Referenced by: '<S273>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_ABSSpdMsgErrSet_ovrdflg = false;
                    /* Referenced by: '<S264>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_ABSSpdMsgErrSet_ovrdval = false;
                    /* Referenced by: '<S264>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_ACUMsgErrSet_ovrdflg = false;
                    /* Referenced by: '<S266>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_ACUMsgErrSet_ovrdval = false;
                    /* Referenced by: '<S266>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_BMSHealthMonErrSet_ovrdflg = false;
                    /* Referenced by: '<S267>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_BMSHealthMonErrSet_ovrdval = false;
                    /* Referenced by: '<S267>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_CSMMsgErrSet_ovrdflg = false;
                    /* Referenced by: '<S269>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_CSMMsgErrSet_ovrdval = false;
                    /* Referenced by: '<S269>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_DCDCMsgErrSet_ovrdflg = false;
                    /* Referenced by: '<S274>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_DCDCMsgErrSet_ovrdval = false;
                    /* Referenced by: '<S274>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_EGSMMsgErrSet_ovrdflg = false;
                    /* Referenced by: '<S275>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_EGSMMsgErrSet_ovrdval = false;
                    /* Referenced by: '<S275>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_MCUHealthMonErrSet_ovrdflg = false;
                    /* Referenced by: '<S268>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_MCUHealthMonErrSet_ovrdval = false;
                    /* Referenced by: '<S268>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_PEPSMsgErrSet_ovrdflg = false;
                    /* Referenced by: '<S265>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_PEPSMsgErrSet_ovrdval = false;
                    /* Referenced by: '<S265>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_batIntSmplHiEnb_ovrdflg = false;
                    /* Referenced by: '<S255>/macc_b_batIntSmplHiEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_PwrSuplyORHigh */
const volatile boolean macc_b_batIntSmplHiEnb_ovrdval = false;
                    /* Referenced by: '<S255>/macc_b_batIntSmplHiEnb_ovrdval' */

/* Override value to enable DFC_HYB_PwrSuplyORHigh */
const volatile float32 macc_b_batIntSmplHiHeal_s = 0.5F;/* Referenced by: '<S8>/t_delay_heal1' */

/* DFC_HYB_PwrSuplyORHigh fault clear threshold */
const volatile boolean macc_b_batIntSmplHiSet_ovrdflg = false;
                    /* Referenced by: '<S256>/macc_b_batIntSmplHiSet_ovrdflg' */

/* Override flag for signal macd_b_batIntSmplHiSet */
const volatile boolean macc_b_batIntSmplHiSet_ovrdval = false;
                    /* Referenced by: '<S256>/macc_b_batIntSmplHiSet_ovrdval' */

/* Override value for signal macd_b_batIntSmplHiSet */
const volatile boolean macc_b_batIntSmplLoEnb_ovrdflg = false;
                    /* Referenced by: '<S257>/macc_b_batIntSmplLoEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_PwrSuplyORLow */
const volatile boolean macc_b_batIntSmplLoEnb_ovrdval = false;
                    /* Referenced by: '<S257>/macc_b_batIntSmplLoEnb_ovrdval' */

/* Override value to enable DFC_HYB_PwrSuplyORLow */
const volatile float32 macc_b_batIntSmplLoHeal_s = 0.5F;/* Referenced by: '<S8>/t_delay_heal' */

/* DFC_HYB_PwrSuplyORLow fault clear threshold */
const volatile boolean macc_b_batIntSmplLoSet_ovrdflg = false;
                    /* Referenced by: '<S258>/macc_b_batIntSmplLoSet_ovrdflg' */

/* Override flag for signal macd_b_batIntSmplLoSet */
const volatile boolean macc_b_batIntSmplLoSet_ovrdval = false;
                    /* Referenced by: '<S258>/macc_b_batIntSmplLoSet_ovrdval' */

/* Override value for signal macd_b_batIntSmplLoSet */
const volatile boolean macc_b_cCanBusOffSet_ovrdflg = false;
                    /* Referenced by: '<S272>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_cCanBusOffSet_ovrdval = false;
                    /* Referenced by: '<S272>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile boolean macc_b_evCANBusoffSet_ovrdflg = false;/* Referenced by:
                                                              * '<S270>/macc_b_batIntSmplHiSet_ovrdflg'
                                                              * '<S271>/macc_b_batIntSmplHiSet_ovrdflg'
                                                              */
const volatile boolean macc_b_evCANBusoffSet_ovrdval = false;/* Referenced by:
                                                              * '<S270>/macc_b_batIntSmplHiSet_ovrdval'
                                                              * '<S271>/macc_b_batIntSmplHiSet_ovrdval'
                                                              */
const volatile boolean macc_b_ptCanBusOffSet_ovrdflg = false;
                    /* Referenced by: '<S263>/macc_b_batIntSmplHiSet_ovrdflg' */
const volatile boolean macc_b_ptCanBusOffSet_ovrdval = false;
                    /* Referenced by: '<S263>/macc_b_batIntSmplHiSet_ovrdval' */
const volatile float32 macc_tm_ignOnDeb_s = 4.0F;/* Referenced by:
                                                  * '<S364>/Constant198'
                                                  * '<S365>/Constant198'
                                                  * '<S366>/Constant198'
                                                  * '<S367>/Constant198'
                                                  */
const volatile float32 macc_u_5VT1IntSmplFltSetHi_V = 5.2F;/* Referenced by: '<S8>/Constant303' */

/* 5VT1 voltage open circuit set higher threshold */
const volatile float32 macc_u_5VT1IntSmplFltSetLo_V = 4.7F;/* Referenced by: '<S8>/Constant292' */

/* 5VT1 voltage open circuit set lower threshold */
const volatile float32 macc_u_5VT2IntSmplFltSetHi_V = 5.2F;/* Referenced by: '<S8>/Constant325' */

/* 5VT2 voltage open circuit set higher threshold */
const volatile float32 macc_u_5VT2IntSmplFltSetLo_V = 4.7F;/* Referenced by: '<S8>/Constant314' */

/* 5VT2 voltage open circuit set lower threshold */
const volatile float32 macc_u_batIntSmplHiSet_V = 16.0F;/* Referenced by: '<S8>/Constant281' */

/* Low voltage battery voltage high set threshold */
const volatile float32 macc_u_batIntSmplLoSet_V = 9.0F;/* Referenced by: '<S8>/Constant230' */

/* Low voltage battery voltage low set threshold */
const volatile boolean sysc_b_delayEnaDTCFcnCall = true;
                                     /* Referenced by: '<S206>/t_delay_heal1' */

/* Calibration to delay enabling the DTC function call by the fault set debounce time */
const volatile boolean sysc_b_forceEnaDTCFcnCall = false;
                                    /* Referenced by: '<S206>/t_delay_heal15' */

/* Calibration to always enable the DTC function call regardless of the enabling conditions */
#define swc_DIAG_STOP_SEC_CONST_VOLATILE
#include "swc_DIAG_MemMap.h"
#define swc_DIAG_START_SEC_VAR
#include "swc_DIAG_MemMap.h"

/* Definition for custom storage class: AUTOSAR4_SIG */
boolean acpd_b_accPed1Vld;             /* '<S11>/Logical Operator8' */

/* Accelerator Pedal 1 valid */
boolean acpd_b_accPed2Vld;             /* '<S11>/Logical Operator9' */

/* Accelerator Pedal 2 valid */
boolean acpd_b_acp1RngHiDebd;          /* '<S49>/timed_debounce' */

/* acp1RngHi fault debounced */
boolean acpd_b_acp1RngHiEnb;           /* '<S82>/Switch2' */

/* DFC_HYB_ACCPedal1ORHigh enabled */
boolean acpd_b_acp1RngHiRaw;           /* '<S48>/timed_debounce' */

/* acp1RngHi fault raw */
boolean acpd_b_acp1RngHiSet;           /* '<S83>/Switch2' */

/* Accel pedal 1 range high fault set */
boolean acpd_b_acp1RngLowDebd;         /* '<S53>/timed_debounce' */

/* acp1RngLow fault debounced */
boolean acpd_b_acp1RngLowEnb;          /* '<S84>/Switch2' */

/* DFC_HYB_ACCPedal1ORLow enabled */
boolean acpd_b_acp1RngLowRaw;          /* '<S52>/timed_debounce' */

/* acp1RngLow fault raw */
boolean acpd_b_acp1RngLowSet;          /* '<S85>/Switch2' */

/* Accel pedal 1 range low fault set */
boolean acpd_b_acp1Sho2BatDebd;        /* '<S57>/timed_debounce' */

/* acp1Sho2Bat fault debounced */
boolean acpd_b_acp1Sho2BatEnb;         /* '<S86>/Switch2' */

/* DFC_HYB_ACCPedal1SCB enabled */
boolean acpd_b_acp1Sho2BatRaw;         /* '<S56>/timed_debounce' */

/* acp1Sho2Bat fault raw */
boolean acpd_b_acp1Sho2BatSet;         /* '<S87>/Switch2' */

/* Accel pedal 1 short to 12V battery fault set */
boolean acpd_b_acp1Sho2GndDebd;        /* '<S61>/timed_debounce' */

/* acp1Sho2Gnd fault debounced */
boolean acpd_b_acp1Sho2GndEnb;         /* '<S88>/Switch2' */

/* DFC_HYB_ACCPedal1SCG enabled */
boolean acpd_b_acp1Sho2GndRaw;         /* '<S60>/timed_debounce' */

/* acp1Sho2Gnd fault raw */
boolean acpd_b_acp1Sho2GndSet;         /* '<S89>/Switch2' */

/* Accel pedal 1 short to ground fault set */
boolean acpd_b_acp2RngHiDebd;          /* '<S65>/timed_debounce' */

/* acp2RngHi fault debounced */
boolean acpd_b_acp2RngHiEnb;           /* '<S90>/Switch2' */

/* DFC_HYB_ACCPedal2ORHigh enabled */
boolean acpd_b_acp2RngHiRaw;           /* '<S64>/timed_debounce' */

/* acp2RngHi fault raw */
boolean acpd_b_acp2RngHiSet;           /* '<S91>/Switch2' */

/* Accel pedal 2 range high fault set */
boolean acpd_b_acp2RngLowDebd;         /* '<S69>/timed_debounce' */

/* acp2RngLow fault debounced */
boolean acpd_b_acp2RngLowEnb;          /* '<S92>/Switch2' */

/* DFC_HYB_ACCPedal2ORLow enabled */
boolean acpd_b_acp2RngLowRaw;          /* '<S68>/timed_debounce' */

/* acp2RngLow fault raw */
boolean acpd_b_acp2RngLowSet;          /* '<S93>/Switch2' */

/* Accel pedal 2 range low fault set */
boolean acpd_b_acp2Sho2BatDebd;        /* '<S73>/timed_debounce' */

/* acp2Sho2Bat fault debounced */
boolean acpd_b_acp2Sho2BatEnb;         /* '<S94>/Switch2' */

/* DFC_HYB_ACCPedal2SCB enabled */
boolean acpd_b_acp2Sho2BatRaw;         /* '<S72>/timed_debounce' */

/* acp2Sho2Bat fault raw */
boolean acpd_b_acp2Sho2BatSet;         /* '<S95>/Switch2' */

/* Accel pedal 2 short to 12V battery fault set */
boolean acpd_b_acp2Sho2GndDebd;        /* '<S77>/timed_debounce' */

/* acp2Sho2Gnd fault debounced */
boolean acpd_b_acp2Sho2GndEnb;         /* '<S96>/Switch2' */

/* DFC_HYB_ACCPedal2SCG enabled */
boolean acpd_b_acp2Sho2GndRaw;         /* '<S76>/timed_debounce' */

/* acp2Sho2Gnd fault raw */
boolean acpd_b_acp2Sho2GndSet;         /* '<S97>/Switch2' */

/* Accel pedal 2 short to ground fault set */
boolean acpd_b_acpCrsFltDebd;          /* '<S80>/timed_debounce' */

/* acpCrsFlt fault debounced */
boolean acpd_b_acpCrsFltEnb;           /* '<S98>/Switch2' */

/* DFC_HYB_ACCPedalCrossNP enabled */
boolean acpd_b_acpCrsFltSet;           /* '<S99>/Switch2' */

/* Accel pedal cross fault set */
boolean brpd_b_BrkSigUnreasnFlt_Flg;   /* '<S154>/Compare' */
boolean brpd_b_VacPumpLoPreDebd;       /* '<S127>/timed_debounce' */
boolean brpd_b_VacPumpLoPreSet;        /* '<S143>/Switch2' */
boolean brpd_b_VacPumpRlyFltDebd;      /* '<S129>/timed_debounce' */
boolean brpd_b_VacPumpRlyFltSet;       /* '<S144>/Switch2' */
boolean brpd_b_VacPumpSnrFltDebd;      /* '<S131>/timed_debounce' */
boolean brpd_b_VacPumpSnrFltSet;       /* '<S145>/Switch2' */
boolean brpd_b_VacPumpSysFailDebd;     /* '<S133>/timed_debounce' */
boolean brpd_b_VacPumpSysFailSet;      /* '<S146>/Switch2' */
boolean brpd_b_VpEnOvTmHiPreDebd;      /* '<S135>/timed_debounce' */
boolean brpd_b_VpEnOvTmHiPreSet;       /* '<S141>/Switch2' */
boolean brpd_b_VpEnOvrTmLoPreDebd;     /* '<S137>/timed_debounce' */
boolean brpd_b_VpEnOvrTmLoPreSet;      /* '<S142>/Switch2' */
boolean brpd_b_brakeMutExcErr_flg;     /* '<S117>/Logical Operator10' */
boolean brpd_b_brakeStateOff_flg;      /* '<S117>/Logical Operator2' */
boolean brpd_b_brakeStateOpen_flg;     /* '<S117>/Logical Operator1' */
boolean brpd_b_brakeUnreasn_flg;       /* '<S157>/FixPt Relational Operator' */
boolean brpd_b_breakFailOver_flg;      /* '<S117>/Logical Operator11' */
boolean brpd_b_brkSwtMismatch;         /* '<S101>/Signal Conversion' */

/* Brake pedal switch mismatch error flag */
boolean brpd_b_brkSwtMismatchEnb;      /* '<S139>/Switch2' */

/* DFC_HYB_BrkSthNP enabled */
boolean brpd_b_brkSwtMismatchSet;      /* '<S140>/Switch2' */

/* brkSwtMismatch fault set */
uint8 brpd_d_BrkSigErrCn;              /* '<S117>/Subtract' */
uint8 brpd_d_BrkSigStoreCn;            /* '<S117>/C Caller' */
boolean cesd_b_crashEventDebd;         /* '<S175>/timed_debounce' */

/* crashEvent fault debounced */
boolean cesd_b_crashEventEnb;          /* '<S177>/Switch2' */

/* DFC_HYB_CrashEvent enabled */
boolean cesd_b_crashEventSet;          /* '<S178>/Switch2' */

/* crashEvent fault set */
boolean digd_b_ACUMsgErrDebd;          /* '<S297>/timed_debounce' */
boolean digd_b_VehLvl1Flt_flg;         /* '<S197>/Switch' */
boolean digd_b_VehLvl1Flt_flgRaw;      /* '<S197>/Logical Operator1' */
boolean digd_b_VehLvl21Flt_flg;        /* '<S198>/Switch1' */
boolean digd_b_VehLvl21Flt_flgRaw;     /* '<S198>/Logical Operator' */
boolean digd_b_VehLvl22Flt_flg;        /* '<S199>/Switch5' */
boolean digd_b_VehLvl23Flt_flg;        /* '<S200>/Switch6' */
boolean digd_b_VehLvl31Flt_flg;        /* '<S201>/Switch2' */
boolean digd_b_VehLvl32Flt_flg;        /* '<S202>/Switch3' */
boolean digd_b_VehLvl33Flt_flg;        /* '<S203>/Switch4' */
boolean digd_b_edcpBlockDebd;          /* '<S419>/timed_debounce' */
boolean digd_b_edcpBlockSet;           /* '<S443>/Switch2' */
boolean digd_b_edcpIdlyDebd;           /* '<S404>/timed_debounce' */
boolean digd_b_edcpIdlySet;            /* '<S440>/Switch2' */
boolean digd_b_edcpOvrCurrDebd;        /* '<S422>/timed_debounce' */
boolean digd_b_edcpOvrCurrSet;         /* '<S444>/Switch2' */
boolean digd_b_edcpOvrTmpDebd;         /* '<S401>/timed_debounce' */
boolean digd_b_edcpOvrTmpSet;          /* '<S436>/Switch2' */
boolean digd_b_edcpOvrVoltDebd;        /* '<S416>/timed_debounce' */
boolean digd_b_edcpOvrVoltSet;         /* '<S442>/Switch2' */
boolean digd_b_edcpUdVoltDebd;         /* '<S413>/timed_debounce' */
boolean digd_b_edcpUdVoltSet;          /* '<S441>/Switch2' */
boolean digd_b_hbcpBlockDebd;          /* '<S407>/timed_debounce' */
boolean digd_b_hbcpBlockSet;           /* '<S438>/Switch2' */
boolean digd_b_hbcpIdlyDebd;           /* '<S428>/timed_debounce' */
boolean digd_b_hbcpIdlySet;            /* '<S446>/Switch2' */
boolean digd_b_hbcpOvrCurrDebd;        /* '<S410>/timed_debounce' */
boolean digd_b_hbcpOvrCurrSet;         /* '<S439>/Switch2' */
boolean digd_b_hbcpOvrTmpDebd;         /* '<S425>/timed_debounce' */
boolean digd_b_hbcpOvrTmpSet;          /* '<S445>/Switch2' */
boolean digd_b_hbcpOvrVoltDebd;        /* '<S434>/timed_debounce' */
boolean digd_b_hbcpOvrVoltSet;         /* '<S437>/Switch2' */
boolean digd_b_hbcpUdVoltDebd;         /* '<S431>/timed_debounce' */
boolean digd_b_hbcpUdVoltSet;          /* '<S447>/Switch2' */
boolean digd_b_vcuLvl1Flt_MAC;         /* '<S8>/Logical Operator264' */
boolean digd_b_vcuLvl1Flt_THM;         /* '<S10>/Logical Operator' */
boolean digd_b_vcuLvl21Flt_MAC;        /* '<S309>/timed_debounce' */
boolean digd_b_vcuLvl23Flt_MAC;        /* '<S8>/Logical Operator265' */
boolean digd_b_vcuLvl31Flt_MAC;        /* '<S8>/Logical Operator271' */
boolean digd_b_vcuVehLvl1Flt_flg_ACP;  /* '<S11>/Logical Operator20' */
boolean digd_b_vcuVehLvl1Flt_flg_HVB;  /* '<S7>/Signal Conversion' */
boolean digd_b_vcuVehLvl21Flt_flg_EAD; /* '<S189>/timed_debounce' */
boolean digd_b_vcuVehLvl21Flt_flg_HVB; /* '<S218>/timed_debounce' */
boolean digd_b_vcuVehLvl22Flt_flg_BRP; /* '<S101>/Logical Operator36' */
boolean digd_b_vcuVehLvl23Flt_flg_ACP; /* '<S11>/Signal Conversion' */
boolean digd_b_vcuVehLvl31Flt_flg_EAD; /* '<S186>/Logical Operator3' */
boolean digd_b_vcuVehLvl32Flt_flg_HVB; /* '<S213>/Logical Operator3' */
boolean digd_b_vcuVehLvl33Flt_flg_CES; /* '<S4>/Signal Conversion' */
boolean digd_b_vcuVehLvl33Flt_flg_HVB; /* '<S7>/Signal Conversion3' */
uint8 digd_st_edcpFlt;                 /* '<S10>/Switch' */
uint8 digd_st_hbcpFlt;                 /* '<S10>/Switch6' */
uint8 digd_st_vehSysErrLevel;          /* '<S6>/Switch' */
boolean hvbd_b_BMSFaultLevel2ASet;     /* '<S230>/Switch2' */
boolean hvbd_b_BMSFaultLevel3ASet;     /* '<S231>/Switch2' */
boolean hvbd_b_BMSFaultLevel4ASet;     /* '<S232>/Switch2' */
boolean hvbd_b_MCUFaultLevel2ASet;     /* '<S195>/Switch2' */
boolean hvbd_b_MCUFaultLevel3ASet;     /* '<S196>/Switch2' */
boolean hvbd_b_vehHvilFltSet;          /* '<S229>/Switch2' */

/* vehHvilFlt fault set */
boolean macb_b_P2AD4;                  /* '<S8>/Signal Conversion2' */

/* Power supply out of range low - 4.5T BEV and 8T REV */
boolean macb_b_P2AD5;                  /* '<S8>/Signal Conversion3' */

/* Power supply out of range high - 4.5T BEV and 8T REV */
boolean macd_b_5VT1IntSmplFltEnb;      /* '<S346>/Switch2' */

/* DFC_HYB_T5V1Mon enabled */
boolean macd_b_5VT1IntSmplFltSet;      /* '<S347>/Switch2' */

/* 5VT1 voltage open circuit set */
boolean macd_b_5VT2IntSmplFltEnb;      /* '<S348>/Switch2' */

/* DFC_HYB_T5V2Mon enabled */
boolean macd_b_5VT2IntSmplFltSet;      /* '<S349>/Switch2' */

/* 5VT2 voltage open circuit set */
boolean macd_b_ABSMsgErrDebd;          /* '<S295>/timed_debounce' */

/* ABSMsgErrDebd fault debounced */
boolean macd_b_ABSMsgErrSet;           /* '<S360>/Switch2' */
boolean macd_b_ABSSpdMsgErrDebd;       /* '<S321>/timed_debounce' */

/* macd_b_ABSSpdMsgErrDebd fault debounced */
boolean macd_b_ABSSpdMsgErrSet;        /* '<S351>/Switch2' */
boolean macd_b_ACUMsgErrSet;           /* '<S353>/Switch2' */
boolean macd_b_BMSHealthMonErrDebd;    /* '<S299>/timed_debounce' */
boolean macd_b_BMSHealthMonErrSet;     /* '<S354>/Switch2' */
boolean macd_b_CSMMsgErrDebd;          /* '<S303>/timed_debounce' */
boolean macd_b_CSMMsgErrSet;           /* '<S356>/Switch2' */
boolean macd_b_DCDCMsgErrDebd;         /* '<S305>/timed_debounce' */

/* macd_b_DCDCMsgErrDebd fault debounced */
boolean macd_b_DCDCMsgErrSet;          /* '<S361>/Switch2' */
boolean macd_b_EGSMMsgErrDebd;         /* '<S307>/timed_debounce' */

/* macd_b_EGSMMsgErrDebd fault debounced */
boolean macd_b_EGSMMsgErrSet;          /* '<S362>/Switch2' */
boolean macd_b_MCUHealthMonErrDebd;    /* '<S313>/timed_debounce' */
boolean macd_b_MCUHealthMonErrSet;     /* '<S355>/Switch2' */
boolean macd_b_PEPSMsgErrDebd;         /* '<S315>/timed_debounce' */

/* macd_b_PEPSMsgErrDebd fault debounced */
boolean macd_b_PEPSMsgErrSet;          /* '<S352>/Switch2' */
boolean macd_b_batIntSmplHiEnb;        /* '<S342>/Switch2' */

/* DFC_HYB_PwrSuplyORHigh enabled */
boolean macd_b_batIntSmplHiSet;        /* '<S343>/Switch2' */

/* Low voltage battery voltage high set */
boolean macd_b_batIntSmplLoDebd;       /* '<S8>/SR_latch3' */

/* batIntSmplLo fault debounced */
boolean macd_b_batIntSmplLoEnb;        /* '<S344>/Switch2' */

/* DFC_HYB_PwrSuplyORLow enabled */
boolean macd_b_batIntSmplLoSet;        /* '<S345>/Switch2' */

/* Low voltage battery voltage low set */
boolean macd_b_cCanBusOffDebd;         /* '<S327>/timed_debounce' */
boolean macd_b_cCanBusOffSet;          /* '<S359>/Switch2' */
boolean macd_b_evCANBusoffDebd;        /* '<S311>/timed_debounce' */
boolean macd_b_evCANBusoffSet;         /* '<S357>/Switch2' */
boolean macd_b_ptCanBusOffDebd;        /* '<S301>/timed_debounce' */
boolean macd_b_ptCanBusOffSet;         /* '<S350>/Switch2' */

#define swc_DIAG_STOP_SEC_VAR
#include "swc_DIAG_MemMap.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_swc_DIAG_T swc_DIAG_ARID_DEF;
static void swc_DIAG_timed_debounce_Init(boolean *rty_flg_out);
static void swc_DIAG_timed_debounce(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_delay_off, float32 rtu_t_step, boolean *rty_flg_out,
  ARID_DEF_timed_debounce_swc_D_T *swc_DIAG__ARID_DEF_arg);
static void swc_DIAG_turnOFF_delay_Init(boolean *rty_flg_out);
static void swc_DIAG_turnOFF_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay_swc_DI_T
  *swc_DIAG__ARID_DEF_arg);
static void swc_DIAG_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch1_swc_DIAG_T *swc_DIAG__ARID_DEF_arg);
static void swc_DIAG_turnON_delay_Init(boolean *rty_flg_out);
static void swc_DIAG_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_DIA_T
  *swc_DIAG__ARID_DEF_arg);
static void swc_DIAG_SR_latch1_m(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch1_swc_DIAG_m_T *swc_DIAG__ARID_DEF_arg);
static void swc_DIAG_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch2_swc_DIAG_T *swc_DIAG__ARID_DEF_arg);
static void swc_DIAG_SR_latch3(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch3_swc_DIAG_T *swc_DIAG__ARID_DEF_arg);
static void swc_DIAG_SR_latch4(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch4_swc_DIAG_T *swc_DIAG__ARID_DEF_arg);
static void swc_DIAG_ACP_Diag_Init(void);
static void swc_DIAG_ACP_Diag(void);
static void swc_DIAG_BRP_Diag_Init(void);
static void swc_DIAG_BRP_Diag(void);
static void swc_DIAG_CES_Diag(void);
static void swc_DIAG_EAD_DiagMot2(void);
static void swc_DIAG_HVB_Diag_Init(void);
static void swc_DIAG_HVB_Diag(void);
static void swc_DIAG_MAC_Diag_Init(void);
static void swc_DIAG_MAC_Diag(void);
static void swc_DIAG_Fault_Management(void);

/* System initialize for function-call system: '<S1>/ACP_Diag' */
static void swc_DIAG_ACP_Diag_Init(void)
{
  /* SystemInitialize for SignalConversion: '<S11>/Signal Conversion' */
  digd_b_vcuVehLvl23Flt_flg_ACP = acpd_b_acpCrsFltDebd;
}

/* Output and update for function-call system: '<S1>/ACP_Diag' */
static void swc_DIAG_ACP_Diag(void)
{
  float32 rtb_Gain1;
  float32 rtb_t_delay_off_kj;
  float32 rtb_t_delay_off_n;
  float32 rtb_t_delay_on_aw;
  boolean rtb_AND;
  boolean rtb_AND1;
  boolean rtb_LogicalOperator21_tmp_tmp;
  boolean rtb_LogicalOperator22_tmp_tmp;
  boolean rtb_LogicalOperator24_tmp_tmp;
  boolean rtb_LogicalOperator25_tmp_tmp;

  /* Gain: '<S11>/Gain1' */
  rtb_Gain1 = 0.001F * swc_DIAG_ARID_DEF.DataTypeConversion252;

  /* Switch: '<S89>/Switch2' incorporates:
   *  Constant: '<S28>/acpc_b_acp1Sho2GndSet_ovrdflg'
   */
  if (acpc_b_acp1Sho2GndSet_ovrdflg) {
    /* Switch: '<S89>/Switch2' incorporates:
     *  Constant: '<S28>/acpc_b_acp1Sho2GndSet_ovrdval'
     */
    acpd_b_acp1Sho2GndSet = acpc_b_acp1Sho2GndSet_ovrdval;
  } else {
    /* Switch: '<S89>/Switch2' incorporates:
     *  Constant: '<S11>/Constant'
     *  RelationalOperator: '<S11>/Relational Operator'
     */
    acpd_b_acp1Sho2GndSet = (rtb_Gain1 <= digc_u_acp1Sho2GndSet_V);
  }

  /* End of Switch: '<S89>/Switch2' */

  /* Logic: '<S11>/AND' incorporates:
   *  Logic: '<S11>/Logical Operator2'
   */
  rtb_AND = (swc_DIAG_ARID_DEF.DataTypeConversion254 &&
             (!macd_b_5VT1IntSmplFltSet));

  /* Switch: '<S88>/Switch2' incorporates:
   *  Constant: '<S27>/acpc_b_acp1Sho2GndEnb_ovrdflg'
   */
  if (acpc_b_acp1Sho2GndEnb_ovrdflg) {
    /* Switch: '<S88>/Switch2' incorporates:
     *  Constant: '<S27>/acpc_b_acp1Sho2GndEnb_ovrdval'
     */
    acpd_b_acp1Sho2GndEnb = acpc_b_acp1Sho2GndEnb_ovrdval;
  } else {
    /* Switch: '<S88>/Switch2' */
    acpd_b_acp1Sho2GndEnb = rtb_AND;
  }

  /* End of Switch: '<S88>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S15>/debounce2' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  if (acpd_b_acp1Sho2GndEnb) {
    if (!swc_DIAG_ARID_DEF.debounce2_MODE_b) {
      /* SystemReset for Chart: '<S61>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c7_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_g0 = 0.0F;
      swc_DIAG_ARID_DEF.debounce2_MODE_b = true;
    }

    /* Saturate: '<S61>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail'
     */
    if (acpc_b_acp1Sho2GndFail_s > 1.6777216E+7F) {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else if (acpc_b_acp1Sho2GndFail_s < 0.0F) {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on_aw = 0.0F;
    } else {
      /* Saturate: '<S61>/Saturation' */
      rtb_t_delay_on_aw = acpc_b_acp1Sho2GndFail_s;
    }

    /* End of Saturate: '<S61>/Saturation' */

    /* Saturate: '<S61>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal'
     */
    if (acpc_b_acp1Sho2GndHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S61>/Saturation1' */
      rtb_t_delay_off_kj = 1.6777216E+7F;
    } else if (acpc_b_acp1Sho2GndHeal_s < 0.0F) {
      /* Saturate: '<S61>/Saturation1' */
      rtb_t_delay_off_kj = 0.0F;
    } else {
      /* Saturate: '<S61>/Saturation1' */
      rtb_t_delay_off_kj = acpc_b_acp1Sho2GndHeal_s;
    }

    /* End of Saturate: '<S61>/Saturation1' */

    /* Chart: '<S61>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step'
     *  DataTypeConversion: '<S61>/Data Type Conversion'
     *  UnitDelay: '<S15>/Unit Delay2'
     */
    if (swc_DIAG_ARID_DEF.is_active_c7_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c7_swc_DIAG = 1U;
      if ((!acpd_b_acp1Sho2GndSet) && (rtb_t_delay_off_kj == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S61>/flg_out' */
        acpd_b_acp1Sho2GndDebd = false;
      } else if (acpd_b_acp1Sho2GndSet && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S61>/flg_out' */
        acpd_b_acp1Sho2GndDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay2_DSTATE) {
        swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_g0 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_g0 += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S61>/flg_out' incorporates:
         *  Constant: '<S11>/t_step'
         */
        acpd_b_acp1Sho2GndDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_g0 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_g0 += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S61>/flg_out' incorporates:
         *  Constant: '<S11>/t_step'
         */
        acpd_b_acp1Sho2GndDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c7_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp1Sho2GndSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S61>/flg_out' */
            acpd_b_acp1Sho2GndDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_g0 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_g0 += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S61>/flg_out' incorporates:
             *  Constant: '<S11>/t_step'
             */
            acpd_b_acp1Sho2GndDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S61>/flg_out' */
          acpd_b_acp1Sho2GndDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp1Sho2GndSet) {
          swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S61>/flg_out' */
          acpd_b_acp1Sho2GndDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_g0 > rtb_t_delay_off_kj - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S61>/flg_out' */
          acpd_b_acp1Sho2GndDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_g0 += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S61>/flg_out' incorporates:
           *  Constant: '<S11>/t_step'
           */
          acpd_b_acp1Sho2GndDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp1Sho2GndSet) {
          if (rtb_t_delay_off_kj == 0.0F) {
            swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S61>/flg_out' */
            acpd_b_acp1Sho2GndDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_g0 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_g0 += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S61>/flg_out' incorporates:
             *  Constant: '<S11>/t_step'
             */
            acpd_b_acp1Sho2GndDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S61>/flg_out' */
          acpd_b_acp1Sho2GndDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp1Sho2GndSet) {
          swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S61>/flg_out' */
          acpd_b_acp1Sho2GndDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_g0 > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c7_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S61>/flg_out' */
          acpd_b_acp1Sho2GndDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_g0 += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S61>/flg_out' incorporates:
           *  Constant: '<S11>/t_step'
           */
          acpd_b_acp1Sho2GndDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S61>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce2_MODE_b) {
    /* Disable for SignalConversion generated from: '<S61>/flg_out' incorporates:
     *  Outport: '<S61>/flg_out'
     */
    acpd_b_acp1Sho2GndDebd = false;
    swc_DIAG_ARID_DEF.debounce2_MODE_b = false;
  }

  /* End of Outputs for SubSystem: '<S15>/debounce2' */

  /* CCaller: '<S39>/C Caller' incorporates:
   *  Constant: '<S11>/event_id'
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32880U), acpd_b_acp1Sho2GndDebd);

  /* Switch: '<S87>/Switch2' incorporates:
   *  Constant: '<S26>/acpc_b_acp1Sho2BatSet_ovrdflg'
   */
  if (acpc_b_acp1Sho2BatSet_ovrdflg) {
    /* Switch: '<S87>/Switch2' incorporates:
     *  Constant: '<S26>/acpc_b_acp1Sho2BatSet_ovrdval'
     */
    acpd_b_acp1Sho2BatSet = acpc_b_acp1Sho2BatSet_ovrdval;
  } else {
    /* Switch: '<S87>/Switch2' incorporates:
     *  Constant: '<S11>/Constant8'
     *  RelationalOperator: '<S11>/Relational Operator6'
     */
    acpd_b_acp1Sho2BatSet = (rtb_Gain1 >= digc_u_acp1Sho2BatSet_V);
  }

  /* End of Switch: '<S87>/Switch2' */

  /* Switch: '<S86>/Switch2' incorporates:
   *  Constant: '<S25>/acpc_b_acp1Sho2BatEnb_ovrdflg'
   */
  if (acpc_b_acp1Sho2BatEnb_ovrdflg) {
    /* Switch: '<S86>/Switch2' incorporates:
     *  Constant: '<S25>/acpc_b_acp1Sho2BatEnb_ovrdval'
     */
    acpd_b_acp1Sho2BatEnb = acpc_b_acp1Sho2BatEnb_ovrdval;
  } else {
    /* Switch: '<S86>/Switch2' */
    acpd_b_acp1Sho2BatEnb = rtb_AND;
  }

  /* End of Switch: '<S86>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S14>/debounce2' incorporates:
   *  EnablePort: '<S57>/Enable'
   */
  if (acpd_b_acp1Sho2BatEnb) {
    if (!swc_DIAG_ARID_DEF.debounce2_MODE_c) {
      /* SystemReset for Chart: '<S57>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c8_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_hq = 0.0F;
      swc_DIAG_ARID_DEF.debounce2_MODE_c = true;
    }

    /* Saturate: '<S57>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail1'
     */
    if (acpc_b_acp1Sho2BatFail_s > 1.6777216E+7F) {
      /* Saturate: '<S57>/Saturation' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else if (acpc_b_acp1Sho2BatFail_s < 0.0F) {
      /* Saturate: '<S57>/Saturation' */
      rtb_t_delay_on_aw = 0.0F;
    } else {
      /* Saturate: '<S57>/Saturation' */
      rtb_t_delay_on_aw = acpc_b_acp1Sho2BatFail_s;
    }

    /* End of Saturate: '<S57>/Saturation' */

    /* Saturate: '<S57>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal1'
     */
    if (acpc_b_acp1Sho2BatHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S57>/Saturation1' */
      rtb_t_delay_off_kj = 1.6777216E+7F;
    } else if (acpc_b_acp1Sho2BatHeal_s < 0.0F) {
      /* Saturate: '<S57>/Saturation1' */
      rtb_t_delay_off_kj = 0.0F;
    } else {
      /* Saturate: '<S57>/Saturation1' */
      rtb_t_delay_off_kj = acpc_b_acp1Sho2BatHeal_s;
    }

    /* End of Saturate: '<S57>/Saturation1' */

    /* Chart: '<S57>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step1'
     *  DataTypeConversion: '<S57>/Data Type Conversion'
     *  UnitDelay: '<S14>/Unit Delay2'
     */
    if (swc_DIAG_ARID_DEF.is_active_c8_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c8_swc_DIAG = 1U;
      if ((!acpd_b_acp1Sho2BatSet) && (rtb_t_delay_off_kj == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S57>/flg_out' */
        acpd_b_acp1Sho2BatDebd = false;
      } else if (acpd_b_acp1Sho2BatSet && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S57>/flg_out' */
        acpd_b_acp1Sho2BatDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_k) {
        swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_hq = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_hq += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S57>/flg_out' incorporates:
         *  Constant: '<S11>/t_step1'
         */
        acpd_b_acp1Sho2BatDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_hq = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_hq += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S57>/flg_out' incorporates:
         *  Constant: '<S11>/t_step1'
         */
        acpd_b_acp1Sho2BatDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c8_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp1Sho2BatSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S57>/flg_out' */
            acpd_b_acp1Sho2BatDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_hq = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_hq += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S57>/flg_out' incorporates:
             *  Constant: '<S11>/t_step1'
             */
            acpd_b_acp1Sho2BatDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S57>/flg_out' */
          acpd_b_acp1Sho2BatDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp1Sho2BatSet) {
          swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S57>/flg_out' */
          acpd_b_acp1Sho2BatDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_hq > rtb_t_delay_off_kj - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S57>/flg_out' */
          acpd_b_acp1Sho2BatDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_hq += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S57>/flg_out' incorporates:
           *  Constant: '<S11>/t_step1'
           */
          acpd_b_acp1Sho2BatDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp1Sho2BatSet) {
          if (rtb_t_delay_off_kj == 0.0F) {
            swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S57>/flg_out' */
            acpd_b_acp1Sho2BatDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_hq = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_hq += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S57>/flg_out' incorporates:
             *  Constant: '<S11>/t_step1'
             */
            acpd_b_acp1Sho2BatDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S57>/flg_out' */
          acpd_b_acp1Sho2BatDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp1Sho2BatSet) {
          swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S57>/flg_out' */
          acpd_b_acp1Sho2BatDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_hq > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c8_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S57>/flg_out' */
          acpd_b_acp1Sho2BatDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_hq += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S57>/flg_out' incorporates:
           *  Constant: '<S11>/t_step1'
           */
          acpd_b_acp1Sho2BatDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S57>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce2_MODE_c) {
    /* Disable for SignalConversion generated from: '<S57>/flg_out' incorporates:
     *  Outport: '<S57>/flg_out'
     */
    acpd_b_acp1Sho2BatDebd = false;
    swc_DIAG_ARID_DEF.debounce2_MODE_c = false;
  }

  /* End of Outputs for SubSystem: '<S14>/debounce2' */

  /* CCaller: '<S40>/C Caller' incorporates:
   *  Constant: '<S11>/event_id1'
   *  DataTypeConversion: '<S11>/Data Type Conversion1'
   */
  Dem_SetEventStatus(((uint16)32881U), acpd_b_acp1Sho2BatDebd);

  /* Switch: '<S85>/Switch2' incorporates:
   *  Constant: '<S24>/acpc_b_acp1RngLowSet_ovrdflg'
   */
  if (acpc_b_acp1RngLowSet_ovrdflg) {
    /* Switch: '<S85>/Switch2' incorporates:
     *  Constant: '<S24>/acpc_b_acp1RngLowSet_ovrdval'
     */
    acpd_b_acp1RngLowSet = acpc_b_acp1RngLowSet_ovrdval;
  } else {
    /* Switch: '<S85>/Switch2' incorporates:
     *  Constant: '<S11>/Constant28'
     *  RelationalOperator: '<S11>/Relational Operator17'
     */
    acpd_b_acp1RngLowSet = (rtb_Gain1 < digc_u_acp1RngLowSet_V);
  }

  /* End of Switch: '<S85>/Switch2' */

  /* Logic: '<S11>/Logical Operator21' */
  rtb_LogicalOperator21_tmp_tmp = !acpd_b_acp1Sho2GndSet;

  /* Switch: '<S84>/Switch2' incorporates:
   *  Constant: '<S23>/acpc_b_acp1RngLowEnb_ovrdflg'
   */
  if (acpc_b_acp1RngLowEnb_ovrdflg) {
    /* Switch: '<S84>/Switch2' incorporates:
     *  Constant: '<S23>/acpc_b_acp1RngLowEnb_ovrdval'
     */
    acpd_b_acp1RngLowEnb = acpc_b_acp1RngLowEnb_ovrdval;
  } else {
    /* Switch: '<S84>/Switch2' incorporates:
     *  Logic: '<S11>/Logical Operator15'
     *  Logic: '<S11>/Logical Operator21'
     */
    acpd_b_acp1RngLowEnb = (rtb_AND && rtb_LogicalOperator21_tmp_tmp);
  }

  /* End of Switch: '<S84>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S13>/debounce2' incorporates:
   *  EnablePort: '<S53>/Enable'
   */
  if (acpd_b_acp1RngLowEnb) {
    if (!swc_DIAG_ARID_DEF.debounce2_MODE_gv) {
      /* SystemReset for Chart: '<S53>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c14_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_ez = 0.0F;
      swc_DIAG_ARID_DEF.debounce2_MODE_gv = true;
    }

    /* Saturate: '<S53>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail2'
     */
    if (acpc_b_acp1RngLowFail_s > 1.6777216E+7F) {
      /* Saturate: '<S53>/Saturation' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else if (acpc_b_acp1RngLowFail_s < 0.0F) {
      /* Saturate: '<S53>/Saturation' */
      rtb_t_delay_on_aw = 0.0F;
    } else {
      /* Saturate: '<S53>/Saturation' */
      rtb_t_delay_on_aw = acpc_b_acp1RngLowFail_s;
    }

    /* End of Saturate: '<S53>/Saturation' */

    /* Saturate: '<S53>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal2'
     */
    if (acpc_b_acp1RngLowHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S53>/Saturation1' */
      rtb_t_delay_off_kj = 1.6777216E+7F;
    } else if (acpc_b_acp1RngLowHeal_s < 0.0F) {
      /* Saturate: '<S53>/Saturation1' */
      rtb_t_delay_off_kj = 0.0F;
    } else {
      /* Saturate: '<S53>/Saturation1' */
      rtb_t_delay_off_kj = acpc_b_acp1RngLowHeal_s;
    }

    /* End of Saturate: '<S53>/Saturation1' */

    /* Chart: '<S53>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step2'
     *  DataTypeConversion: '<S53>/Data Type Conversion'
     *  UnitDelay: '<S13>/Unit Delay2'
     */
    if (swc_DIAG_ARID_DEF.is_active_c14_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c14_swc_DIAG = 1U;
      if ((!acpd_b_acp1RngLowSet) && (rtb_t_delay_off_kj == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S53>/flg_out' */
        acpd_b_acp1RngLowDebd = false;
      } else if (acpd_b_acp1RngLowSet && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S53>/flg_out' */
        acpd_b_acp1RngLowDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_c) {
        swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_ez = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ez += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S53>/flg_out' incorporates:
         *  Constant: '<S11>/t_step2'
         */
        acpd_b_acp1RngLowDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_ez = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ez += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S53>/flg_out' incorporates:
         *  Constant: '<S11>/t_step2'
         */
        acpd_b_acp1RngLowDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c14_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp1RngLowSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S53>/flg_out' */
            acpd_b_acp1RngLowDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_ez = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ez += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S53>/flg_out' incorporates:
             *  Constant: '<S11>/t_step2'
             */
            acpd_b_acp1RngLowDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S53>/flg_out' */
          acpd_b_acp1RngLowDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp1RngLowSet) {
          swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S53>/flg_out' */
          acpd_b_acp1RngLowDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_ez > rtb_t_delay_off_kj - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S53>/flg_out' */
          acpd_b_acp1RngLowDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ez += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S53>/flg_out' incorporates:
           *  Constant: '<S11>/t_step2'
           */
          acpd_b_acp1RngLowDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp1RngLowSet) {
          if (rtb_t_delay_off_kj == 0.0F) {
            swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S53>/flg_out' */
            acpd_b_acp1RngLowDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_ez = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ez += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S53>/flg_out' incorporates:
             *  Constant: '<S11>/t_step2'
             */
            acpd_b_acp1RngLowDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S53>/flg_out' */
          acpd_b_acp1RngLowDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp1RngLowSet) {
          swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S53>/flg_out' */
          acpd_b_acp1RngLowDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_ez > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c14_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S53>/flg_out' */
          acpd_b_acp1RngLowDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ez += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S53>/flg_out' incorporates:
           *  Constant: '<S11>/t_step2'
           */
          acpd_b_acp1RngLowDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S53>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce2_MODE_gv) {
    /* Disable for SignalConversion generated from: '<S53>/flg_out' incorporates:
     *  Outport: '<S53>/flg_out'
     */
    acpd_b_acp1RngLowDebd = false;
    swc_DIAG_ARID_DEF.debounce2_MODE_gv = false;
  }

  /* End of Outputs for SubSystem: '<S13>/debounce2' */

  /* CCaller: '<S41>/C Caller' incorporates:
   *  Constant: '<S11>/event_id2'
   *  DataTypeConversion: '<S11>/Data Type Conversion2'
   */
  Dem_SetEventStatus(((uint16)32882U), acpd_b_acp1RngLowDebd);

  /* Switch: '<S83>/Switch2' incorporates:
   *  Constant: '<S22>/acpc_b_acp1RngHiSet_ovrdflg'
   */
  if (acpc_b_acp1RngHiSet_ovrdflg) {
    /* Switch: '<S83>/Switch2' incorporates:
     *  Constant: '<S22>/acpc_b_acp1RngHiSet_ovrdval'
     */
    acpd_b_acp1RngHiSet = acpc_b_acp1RngHiSet_ovrdval;
  } else {
    /* Switch: '<S83>/Switch2' incorporates:
     *  Constant: '<S11>/Constant12'
     *  RelationalOperator: '<S11>/Relational Operator8'
     */
    acpd_b_acp1RngHiSet = (rtb_Gain1 > digc_u_acp1RngHiSet_V);
  }

  /* End of Switch: '<S83>/Switch2' */

  /* Logic: '<S11>/Logical Operator22' */
  rtb_LogicalOperator22_tmp_tmp = !acpd_b_acp1Sho2BatSet;

  /* Switch: '<S82>/Switch2' incorporates:
   *  Constant: '<S21>/acpc_b_acp1RngHiEnb_ovrdflg'
   */
  if (acpc_b_acp1RngHiEnb_ovrdflg) {
    /* Switch: '<S82>/Switch2' incorporates:
     *  Constant: '<S21>/acpc_b_acp1RngHiEnb_ovrdval'
     */
    acpd_b_acp1RngHiEnb = acpc_b_acp1RngHiEnb_ovrdval;
  } else {
    /* Switch: '<S82>/Switch2' incorporates:
     *  Logic: '<S11>/Logical Operator'
     *  Logic: '<S11>/Logical Operator22'
     */
    acpd_b_acp1RngHiEnb = (rtb_AND && rtb_LogicalOperator22_tmp_tmp);
  }

  /* End of Switch: '<S82>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S12>/debounce2' incorporates:
   *  EnablePort: '<S49>/Enable'
   */
  if (acpd_b_acp1RngHiEnb) {
    if (!swc_DIAG_ARID_DEF.debounce2_MODE_p) {
      /* SystemReset for Chart: '<S49>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c56_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_j4 = 0.0F;
      swc_DIAG_ARID_DEF.debounce2_MODE_p = true;
    }

    /* Saturate: '<S49>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail3'
     */
    if (acpc_b_acp1RngHiFail_s > 1.6777216E+7F) {
      /* Saturate: '<S49>/Saturation' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else if (acpc_b_acp1RngHiFail_s < 0.0F) {
      /* Saturate: '<S49>/Saturation' */
      rtb_t_delay_on_aw = 0.0F;
    } else {
      /* Saturate: '<S49>/Saturation' */
      rtb_t_delay_on_aw = acpc_b_acp1RngHiFail_s;
    }

    /* End of Saturate: '<S49>/Saturation' */

    /* Saturate: '<S49>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal3'
     */
    if (acpc_b_acp1RngHiHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S49>/Saturation1' */
      rtb_t_delay_off_kj = 1.6777216E+7F;
    } else if (acpc_b_acp1RngHiHeal_s < 0.0F) {
      /* Saturate: '<S49>/Saturation1' */
      rtb_t_delay_off_kj = 0.0F;
    } else {
      /* Saturate: '<S49>/Saturation1' */
      rtb_t_delay_off_kj = acpc_b_acp1RngHiHeal_s;
    }

    /* End of Saturate: '<S49>/Saturation1' */

    /* Chart: '<S49>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step3'
     *  DataTypeConversion: '<S49>/Data Type Conversion'
     *  UnitDelay: '<S12>/Unit Delay2'
     */
    if (swc_DIAG_ARID_DEF.is_active_c56_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c56_swc_DIAG = 1U;
      if ((!acpd_b_acp1RngHiSet) && (rtb_t_delay_off_kj == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S49>/flg_out' */
        acpd_b_acp1RngHiDebd = false;
      } else if (acpd_b_acp1RngHiSet && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S49>/flg_out' */
        acpd_b_acp1RngHiDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_a) {
        swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_j4 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_j4 += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S49>/flg_out' incorporates:
         *  Constant: '<S11>/t_step3'
         */
        acpd_b_acp1RngHiDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_j4 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_j4 += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S49>/flg_out' incorporates:
         *  Constant: '<S11>/t_step3'
         */
        acpd_b_acp1RngHiDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c56_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp1RngHiSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S49>/flg_out' */
            acpd_b_acp1RngHiDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_j4 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_j4 += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S49>/flg_out' incorporates:
             *  Constant: '<S11>/t_step3'
             */
            acpd_b_acp1RngHiDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S49>/flg_out' */
          acpd_b_acp1RngHiDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp1RngHiSet) {
          swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S49>/flg_out' */
          acpd_b_acp1RngHiDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_j4 > rtb_t_delay_off_kj - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S49>/flg_out' */
          acpd_b_acp1RngHiDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_j4 += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S49>/flg_out' incorporates:
           *  Constant: '<S11>/t_step3'
           */
          acpd_b_acp1RngHiDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp1RngHiSet) {
          if (rtb_t_delay_off_kj == 0.0F) {
            swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S49>/flg_out' */
            acpd_b_acp1RngHiDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_j4 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_j4 += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S49>/flg_out' incorporates:
             *  Constant: '<S11>/t_step3'
             */
            acpd_b_acp1RngHiDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S49>/flg_out' */
          acpd_b_acp1RngHiDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp1RngHiSet) {
          swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S49>/flg_out' */
          acpd_b_acp1RngHiDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_j4 > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c56_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S49>/flg_out' */
          acpd_b_acp1RngHiDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_j4 += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S49>/flg_out' incorporates:
           *  Constant: '<S11>/t_step3'
           */
          acpd_b_acp1RngHiDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S49>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce2_MODE_p) {
    /* Disable for SignalConversion generated from: '<S49>/flg_out' incorporates:
     *  Outport: '<S49>/flg_out'
     */
    acpd_b_acp1RngHiDebd = false;
    swc_DIAG_ARID_DEF.debounce2_MODE_p = false;
  }

  /* End of Outputs for SubSystem: '<S12>/debounce2' */

  /* CCaller: '<S42>/C Caller' incorporates:
   *  Constant: '<S11>/event_id3'
   *  DataTypeConversion: '<S11>/Data Type Conversion3'
   */
  Dem_SetEventStatus(((uint16)32883U), acpd_b_acp1RngHiDebd);

  /* Gain: '<S11>/Gain2' */
  rtb_t_delay_on_aw = 0.001F * swc_DIAG_ARID_DEF.DataTypeConversion253;

  /* Switch: '<S97>/Switch2' incorporates:
   *  Constant: '<S36>/acpc_b_acp2Sho2GndSet_ovrdflg'
   */
  if (acpc_b_acp2Sho2GndSet_ovrdflg) {
    /* Switch: '<S97>/Switch2' incorporates:
     *  Constant: '<S36>/acpc_b_acp2Sho2GndSet_ovrdval'
     */
    acpd_b_acp2Sho2GndSet = acpc_b_acp2Sho2GndSet_ovrdval;
  } else {
    /* Switch: '<S97>/Switch2' incorporates:
     *  Constant: '<S11>/Constant16'
     *  RelationalOperator: '<S11>/Relational Operator11'
     */
    acpd_b_acp2Sho2GndSet = (rtb_t_delay_on_aw <= digc_u_acp2Sho2GndSet_V);
  }

  /* End of Switch: '<S97>/Switch2' */

  /* Logic: '<S11>/AND1' incorporates:
   *  Logic: '<S11>/Logical Operator12'
   */
  rtb_AND1 = (swc_DIAG_ARID_DEF.DataTypeConversion254 &&
              (!macd_b_5VT2IntSmplFltSet));

  /* Switch: '<S96>/Switch2' incorporates:
   *  Constant: '<S35>/acpc_b_acp2Sho2GndEnb_ovrdflg'
   */
  if (acpc_b_acp2Sho2GndEnb_ovrdflg) {
    /* Switch: '<S96>/Switch2' incorporates:
     *  Constant: '<S35>/acpc_b_acp2Sho2GndEnb_ovrdval'
     */
    acpd_b_acp2Sho2GndEnb = acpc_b_acp2Sho2GndEnb_ovrdval;
  } else {
    /* Switch: '<S96>/Switch2' */
    acpd_b_acp2Sho2GndEnb = rtb_AND1;
  }

  /* End of Switch: '<S96>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S19>/debounce2' incorporates:
   *  EnablePort: '<S77>/Enable'
   */
  if (acpd_b_acp2Sho2GndEnb) {
    if (!swc_DIAG_ARID_DEF.debounce2_MODE) {
      /* SystemReset for Chart: '<S77>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c57_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_pu = 0.0F;
      swc_DIAG_ARID_DEF.debounce2_MODE = true;
    }

    /* Saturate: '<S77>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail4'
     */
    if (acpc_b_acp2Sho2GndFail_s > 1.6777216E+7F) {
      /* Saturate: '<S77>/Saturation' */
      rtb_t_delay_off_kj = 1.6777216E+7F;
    } else if (acpc_b_acp2Sho2GndFail_s < 0.0F) {
      /* Saturate: '<S77>/Saturation' */
      rtb_t_delay_off_kj = 0.0F;
    } else {
      /* Saturate: '<S77>/Saturation' */
      rtb_t_delay_off_kj = acpc_b_acp2Sho2GndFail_s;
    }

    /* End of Saturate: '<S77>/Saturation' */

    /* Saturate: '<S77>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal4'
     */
    if (acpc_b_acp2Sho2GndHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S77>/Saturation1' */
      rtb_t_delay_off_n = 1.6777216E+7F;
    } else if (acpc_b_acp2Sho2GndHeal_s < 0.0F) {
      /* Saturate: '<S77>/Saturation1' */
      rtb_t_delay_off_n = 0.0F;
    } else {
      /* Saturate: '<S77>/Saturation1' */
      rtb_t_delay_off_n = acpc_b_acp2Sho2GndHeal_s;
    }

    /* End of Saturate: '<S77>/Saturation1' */

    /* Chart: '<S77>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step4'
     *  DataTypeConversion: '<S77>/Data Type Conversion'
     *  UnitDelay: '<S19>/Unit Delay2'
     */
    if (swc_DIAG_ARID_DEF.is_active_c57_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c57_swc_DIAG = 1U;
      if ((!acpd_b_acp2Sho2GndSet) && (rtb_t_delay_off_n == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S77>/flg_out' */
        acpd_b_acp2Sho2GndDebd = false;
      } else if (acpd_b_acp2Sho2GndSet && (rtb_t_delay_off_kj == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S77>/flg_out' */
        acpd_b_acp2Sho2GndDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_p) {
        swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_pu = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_pu += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S77>/flg_out' incorporates:
         *  Constant: '<S11>/t_step4'
         */
        acpd_b_acp2Sho2GndDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_pu = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_pu += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S77>/flg_out' incorporates:
         *  Constant: '<S11>/t_step4'
         */
        acpd_b_acp2Sho2GndDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c57_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp2Sho2GndSet) {
          if (rtb_t_delay_off_kj == 0.0F) {
            swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S77>/flg_out' */
            acpd_b_acp2Sho2GndDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_pu = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_pu += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S77>/flg_out' incorporates:
             *  Constant: '<S11>/t_step4'
             */
            acpd_b_acp2Sho2GndDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S77>/flg_out' */
          acpd_b_acp2Sho2GndDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp2Sho2GndSet) {
          swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S77>/flg_out' */
          acpd_b_acp2Sho2GndDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_pu > rtb_t_delay_off_n - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S77>/flg_out' */
          acpd_b_acp2Sho2GndDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_pu += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S77>/flg_out' incorporates:
           *  Constant: '<S11>/t_step4'
           */
          acpd_b_acp2Sho2GndDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp2Sho2GndSet) {
          if (rtb_t_delay_off_n == 0.0F) {
            swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S77>/flg_out' */
            acpd_b_acp2Sho2GndDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_pu = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_pu += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S77>/flg_out' incorporates:
             *  Constant: '<S11>/t_step4'
             */
            acpd_b_acp2Sho2GndDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S77>/flg_out' */
          acpd_b_acp2Sho2GndDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp2Sho2GndSet) {
          swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S77>/flg_out' */
          acpd_b_acp2Sho2GndDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_pu > rtb_t_delay_off_kj - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c57_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S77>/flg_out' */
          acpd_b_acp2Sho2GndDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_pu += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S77>/flg_out' incorporates:
           *  Constant: '<S11>/t_step4'
           */
          acpd_b_acp2Sho2GndDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S77>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce2_MODE) {
    /* Disable for SignalConversion generated from: '<S77>/flg_out' incorporates:
     *  Outport: '<S77>/flg_out'
     */
    acpd_b_acp2Sho2GndDebd = false;
    swc_DIAG_ARID_DEF.debounce2_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S19>/debounce2' */

  /* CCaller: '<S43>/C Caller' incorporates:
   *  Constant: '<S11>/event_id4'
   *  DataTypeConversion: '<S11>/Data Type Conversion4'
   */
  Dem_SetEventStatus(((uint16)32884U), acpd_b_acp2Sho2GndDebd);

  /* Switch: '<S95>/Switch2' incorporates:
   *  Constant: '<S34>/acpc_b_acp2Sho2BatSet_ovrdflg'
   */
  if (acpc_b_acp2Sho2BatSet_ovrdflg) {
    /* Switch: '<S95>/Switch2' incorporates:
     *  Constant: '<S34>/acpc_b_acp2Sho2BatSet_ovrdval'
     */
    acpd_b_acp2Sho2BatSet = acpc_b_acp2Sho2BatSet_ovrdval;
  } else {
    /* Switch: '<S95>/Switch2' incorporates:
     *  Constant: '<S11>/Constant26'
     *  RelationalOperator: '<S11>/Relational Operator13'
     */
    acpd_b_acp2Sho2BatSet = (rtb_t_delay_on_aw >= digc_u_acp2Sho2BatSet_V);
  }

  /* End of Switch: '<S95>/Switch2' */

  /* Switch: '<S94>/Switch2' incorporates:
   *  Constant: '<S33>/acpc_b_acp2Sho2BatEnb_ovrdflg'
   */
  if (acpc_b_acp2Sho2BatEnb_ovrdflg) {
    /* Switch: '<S94>/Switch2' incorporates:
     *  Constant: '<S33>/acpc_b_acp2Sho2BatEnb_ovrdval'
     */
    acpd_b_acp2Sho2BatEnb = acpc_b_acp2Sho2BatEnb_ovrdval;
  } else {
    /* Switch: '<S94>/Switch2' */
    acpd_b_acp2Sho2BatEnb = rtb_AND1;
  }

  /* End of Switch: '<S94>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S18>/debounce2' incorporates:
   *  EnablePort: '<S73>/Enable'
   */
  if (acpd_b_acp2Sho2BatEnb) {
    if (!swc_DIAG_ARID_DEF.debounce2_MODE_o) {
      /* SystemReset for Chart: '<S73>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c58_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_bj = 0.0F;
      swc_DIAG_ARID_DEF.debounce2_MODE_o = true;
    }

    /* Saturate: '<S73>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail5'
     */
    if (acpc_b_acp2Sho2BatFail_s > 1.6777216E+7F) {
      /* Saturate: '<S73>/Saturation' */
      rtb_t_delay_off_kj = 1.6777216E+7F;
    } else if (acpc_b_acp2Sho2BatFail_s < 0.0F) {
      /* Saturate: '<S73>/Saturation' */
      rtb_t_delay_off_kj = 0.0F;
    } else {
      /* Saturate: '<S73>/Saturation' */
      rtb_t_delay_off_kj = acpc_b_acp2Sho2BatFail_s;
    }

    /* End of Saturate: '<S73>/Saturation' */

    /* Saturate: '<S73>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal5'
     */
    if (acpc_b_acp2Sho2BatHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S73>/Saturation1' */
      rtb_t_delay_off_n = 1.6777216E+7F;
    } else if (acpc_b_acp2Sho2BatHeal_s < 0.0F) {
      /* Saturate: '<S73>/Saturation1' */
      rtb_t_delay_off_n = 0.0F;
    } else {
      /* Saturate: '<S73>/Saturation1' */
      rtb_t_delay_off_n = acpc_b_acp2Sho2BatHeal_s;
    }

    /* End of Saturate: '<S73>/Saturation1' */

    /* Chart: '<S73>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step5'
     *  DataTypeConversion: '<S73>/Data Type Conversion'
     *  UnitDelay: '<S18>/Unit Delay2'
     */
    if (swc_DIAG_ARID_DEF.is_active_c58_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c58_swc_DIAG = 1U;
      if ((!acpd_b_acp2Sho2BatSet) && (rtb_t_delay_off_n == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S73>/flg_out' */
        acpd_b_acp2Sho2BatDebd = false;
      } else if (acpd_b_acp2Sho2BatSet && (rtb_t_delay_off_kj == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S73>/flg_out' */
        acpd_b_acp2Sho2BatDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_j) {
        swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_bj = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_bj += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S73>/flg_out' incorporates:
         *  Constant: '<S11>/t_step5'
         */
        acpd_b_acp2Sho2BatDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_bj = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_bj += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S73>/flg_out' incorporates:
         *  Constant: '<S11>/t_step5'
         */
        acpd_b_acp2Sho2BatDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c58_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp2Sho2BatSet) {
          if (rtb_t_delay_off_kj == 0.0F) {
            swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S73>/flg_out' */
            acpd_b_acp2Sho2BatDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_bj = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_bj += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S73>/flg_out' incorporates:
             *  Constant: '<S11>/t_step5'
             */
            acpd_b_acp2Sho2BatDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S73>/flg_out' */
          acpd_b_acp2Sho2BatDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp2Sho2BatSet) {
          swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S73>/flg_out' */
          acpd_b_acp2Sho2BatDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_bj > rtb_t_delay_off_n - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S73>/flg_out' */
          acpd_b_acp2Sho2BatDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_bj += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S73>/flg_out' incorporates:
           *  Constant: '<S11>/t_step5'
           */
          acpd_b_acp2Sho2BatDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp2Sho2BatSet) {
          if (rtb_t_delay_off_n == 0.0F) {
            swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S73>/flg_out' */
            acpd_b_acp2Sho2BatDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_bj = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_bj += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S73>/flg_out' incorporates:
             *  Constant: '<S11>/t_step5'
             */
            acpd_b_acp2Sho2BatDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S73>/flg_out' */
          acpd_b_acp2Sho2BatDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp2Sho2BatSet) {
          swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S73>/flg_out' */
          acpd_b_acp2Sho2BatDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_bj > rtb_t_delay_off_kj - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c58_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S73>/flg_out' */
          acpd_b_acp2Sho2BatDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_bj += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S73>/flg_out' incorporates:
           *  Constant: '<S11>/t_step5'
           */
          acpd_b_acp2Sho2BatDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S73>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce2_MODE_o) {
    /* Disable for SignalConversion generated from: '<S73>/flg_out' incorporates:
     *  Outport: '<S73>/flg_out'
     */
    acpd_b_acp2Sho2BatDebd = false;
    swc_DIAG_ARID_DEF.debounce2_MODE_o = false;
  }

  /* End of Outputs for SubSystem: '<S18>/debounce2' */

  /* CCaller: '<S44>/C Caller' incorporates:
   *  Constant: '<S11>/event_id5'
   *  DataTypeConversion: '<S11>/Data Type Conversion5'
   */
  Dem_SetEventStatus(((uint16)32885U), acpd_b_acp2Sho2BatDebd);

  /* Switch: '<S93>/Switch2' incorporates:
   *  Constant: '<S32>/acpc_b_acp2RngLowSet_ovrdflg'
   */
  if (acpc_b_acp2RngLowSet_ovrdflg) {
    /* Switch: '<S93>/Switch2' incorporates:
     *  Constant: '<S32>/acpc_b_acp2RngLowSet_ovrdval'
     */
    acpd_b_acp2RngLowSet = acpc_b_acp2RngLowSet_ovrdval;
  } else {
    /* Switch: '<S93>/Switch2' incorporates:
     *  Constant: '<S11>/Constant32'
     *  RelationalOperator: '<S11>/Relational Operator15'
     */
    acpd_b_acp2RngLowSet = (rtb_t_delay_on_aw < digc_u_acp2RngLowSet_V);
  }

  /* End of Switch: '<S93>/Switch2' */

  /* Logic: '<S11>/Logical Operator24' */
  rtb_LogicalOperator24_tmp_tmp = !acpd_b_acp2Sho2GndSet;

  /* Switch: '<S92>/Switch2' incorporates:
   *  Constant: '<S31>/acpc_b_acp2RngLowEnb_ovrdflg'
   */
  if (acpc_b_acp2RngLowEnb_ovrdflg) {
    /* Switch: '<S92>/Switch2' incorporates:
     *  Constant: '<S31>/acpc_b_acp2RngLowEnb_ovrdval'
     */
    acpd_b_acp2RngLowEnb = acpc_b_acp2RngLowEnb_ovrdval;
  } else {
    /* Switch: '<S92>/Switch2' incorporates:
     *  Logic: '<S11>/Logical Operator11'
     *  Logic: '<S11>/Logical Operator24'
     */
    acpd_b_acp2RngLowEnb = (rtb_AND1 && rtb_LogicalOperator24_tmp_tmp);
  }

  /* End of Switch: '<S92>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S17>/debounce2' incorporates:
   *  EnablePort: '<S69>/Enable'
   */
  if (acpd_b_acp2RngLowEnb) {
    if (!swc_DIAG_ARID_DEF.debounce2_MODE_g) {
      /* SystemReset for Chart: '<S69>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c59_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_do = 0.0F;
      swc_DIAG_ARID_DEF.debounce2_MODE_g = true;
    }

    /* Saturate: '<S69>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail6'
     */
    if (acpc_b_acp2RngLowFail_s > 1.6777216E+7F) {
      /* Saturate: '<S69>/Saturation' */
      rtb_t_delay_off_kj = 1.6777216E+7F;
    } else if (acpc_b_acp2RngLowFail_s < 0.0F) {
      /* Saturate: '<S69>/Saturation' */
      rtb_t_delay_off_kj = 0.0F;
    } else {
      /* Saturate: '<S69>/Saturation' */
      rtb_t_delay_off_kj = acpc_b_acp2RngLowFail_s;
    }

    /* End of Saturate: '<S69>/Saturation' */

    /* Saturate: '<S69>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal6'
     */
    if (acpc_b_acp2RngLowHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S69>/Saturation1' */
      rtb_t_delay_off_n = 1.6777216E+7F;
    } else if (acpc_b_acp2RngLowHeal_s < 0.0F) {
      /* Saturate: '<S69>/Saturation1' */
      rtb_t_delay_off_n = 0.0F;
    } else {
      /* Saturate: '<S69>/Saturation1' */
      rtb_t_delay_off_n = acpc_b_acp2RngLowHeal_s;
    }

    /* End of Saturate: '<S69>/Saturation1' */

    /* Chart: '<S69>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step6'
     *  DataTypeConversion: '<S69>/Data Type Conversion'
     *  UnitDelay: '<S17>/Unit Delay2'
     */
    if (swc_DIAG_ARID_DEF.is_active_c59_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c59_swc_DIAG = 1U;
      if ((!acpd_b_acp2RngLowSet) && (rtb_t_delay_off_n == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S69>/flg_out' */
        acpd_b_acp2RngLowDebd = false;
      } else if (acpd_b_acp2RngLowSet && (rtb_t_delay_off_kj == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S69>/flg_out' */
        acpd_b_acp2RngLowDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_n) {
        swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_do = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_do += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S69>/flg_out' incorporates:
         *  Constant: '<S11>/t_step6'
         */
        acpd_b_acp2RngLowDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_do = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_do += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S69>/flg_out' incorporates:
         *  Constant: '<S11>/t_step6'
         */
        acpd_b_acp2RngLowDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c59_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp2RngLowSet) {
          if (rtb_t_delay_off_kj == 0.0F) {
            swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S69>/flg_out' */
            acpd_b_acp2RngLowDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_do = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_do += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S69>/flg_out' incorporates:
             *  Constant: '<S11>/t_step6'
             */
            acpd_b_acp2RngLowDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S69>/flg_out' */
          acpd_b_acp2RngLowDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp2RngLowSet) {
          swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S69>/flg_out' */
          acpd_b_acp2RngLowDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_do > rtb_t_delay_off_n - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S69>/flg_out' */
          acpd_b_acp2RngLowDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_do += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S69>/flg_out' incorporates:
           *  Constant: '<S11>/t_step6'
           */
          acpd_b_acp2RngLowDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp2RngLowSet) {
          if (rtb_t_delay_off_n == 0.0F) {
            swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S69>/flg_out' */
            acpd_b_acp2RngLowDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_do = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_do += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S69>/flg_out' incorporates:
             *  Constant: '<S11>/t_step6'
             */
            acpd_b_acp2RngLowDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S69>/flg_out' */
          acpd_b_acp2RngLowDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp2RngLowSet) {
          swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S69>/flg_out' */
          acpd_b_acp2RngLowDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_do > rtb_t_delay_off_kj - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c59_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S69>/flg_out' */
          acpd_b_acp2RngLowDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_do += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S69>/flg_out' incorporates:
           *  Constant: '<S11>/t_step6'
           */
          acpd_b_acp2RngLowDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S69>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce2_MODE_g) {
    /* Disable for SignalConversion generated from: '<S69>/flg_out' incorporates:
     *  Outport: '<S69>/flg_out'
     */
    acpd_b_acp2RngLowDebd = false;
    swc_DIAG_ARID_DEF.debounce2_MODE_g = false;
  }

  /* End of Outputs for SubSystem: '<S17>/debounce2' */

  /* CCaller: '<S45>/C Caller' incorporates:
   *  Constant: '<S11>/event_id6'
   *  DataTypeConversion: '<S11>/Data Type Conversion6'
   */
  Dem_SetEventStatus(((uint16)32886U), acpd_b_acp2RngLowDebd);

  /* Switch: '<S91>/Switch2' incorporates:
   *  Constant: '<S30>/acpc_b_acp2RngHiSet_ovrdflg'
   */
  if (acpc_b_acp2RngHiSet_ovrdflg) {
    /* Switch: '<S91>/Switch2' incorporates:
     *  Constant: '<S30>/acpc_b_acp2RngHiSet_ovrdval'
     */
    acpd_b_acp2RngHiSet = acpc_b_acp2RngHiSet_ovrdval;
  } else {
    /* Switch: '<S91>/Switch2' incorporates:
     *  Constant: '<S11>/Constant19'
     *  RelationalOperator: '<S11>/Relational Operator19'
     */
    acpd_b_acp2RngHiSet = (rtb_t_delay_on_aw > digc_u_acp2RngHiSet_V);
  }

  /* End of Switch: '<S91>/Switch2' */

  /* Logic: '<S11>/Logical Operator25' */
  rtb_LogicalOperator25_tmp_tmp = !acpd_b_acp2Sho2BatSet;

  /* Switch: '<S90>/Switch2' incorporates:
   *  Constant: '<S29>/acpc_b_acp2RngHiEnb_ovrdflg'
   */
  if (acpc_b_acp2RngHiEnb_ovrdflg) {
    /* Switch: '<S90>/Switch2' incorporates:
     *  Constant: '<S29>/acpc_b_acp2RngHiEnb_ovrdval'
     */
    acpd_b_acp2RngHiEnb = acpc_b_acp2RngHiEnb_ovrdval;
  } else {
    /* Switch: '<S90>/Switch2' incorporates:
     *  Logic: '<S11>/Logical Operator10'
     *  Logic: '<S11>/Logical Operator25'
     */
    acpd_b_acp2RngHiEnb = (rtb_AND1 && rtb_LogicalOperator25_tmp_tmp);
  }

  /* End of Switch: '<S90>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S16>/debounce2' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  if (acpd_b_acp2RngHiEnb) {
    if (!swc_DIAG_ARID_DEF.debounce2_MODE_e) {
      /* SystemReset for Chart: '<S65>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c60_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_j0 = 0.0F;
      swc_DIAG_ARID_DEF.debounce2_MODE_e = true;
    }

    /* Saturate: '<S65>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail7'
     */
    if (acpc_b_acp2RngHiFail_s > 1.6777216E+7F) {
      /* Saturate: '<S65>/Saturation' */
      rtb_t_delay_off_kj = 1.6777216E+7F;
    } else if (acpc_b_acp2RngHiFail_s < 0.0F) {
      /* Saturate: '<S65>/Saturation' */
      rtb_t_delay_off_kj = 0.0F;
    } else {
      /* Saturate: '<S65>/Saturation' */
      rtb_t_delay_off_kj = acpc_b_acp2RngHiFail_s;
    }

    /* End of Saturate: '<S65>/Saturation' */

    /* Saturate: '<S65>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal7'
     */
    if (acpc_b_acp2RngHiHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S65>/Saturation1' */
      rtb_t_delay_off_n = 1.6777216E+7F;
    } else if (acpc_b_acp2RngHiHeal_s < 0.0F) {
      /* Saturate: '<S65>/Saturation1' */
      rtb_t_delay_off_n = 0.0F;
    } else {
      /* Saturate: '<S65>/Saturation1' */
      rtb_t_delay_off_n = acpc_b_acp2RngHiHeal_s;
    }

    /* End of Saturate: '<S65>/Saturation1' */

    /* Chart: '<S65>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step7'
     *  DataTypeConversion: '<S65>/Data Type Conversion'
     *  UnitDelay: '<S16>/Unit Delay2'
     */
    if (swc_DIAG_ARID_DEF.is_active_c60_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c60_swc_DIAG = 1U;
      if ((!acpd_b_acp2RngHiSet) && (rtb_t_delay_off_n == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S65>/flg_out' */
        acpd_b_acp2RngHiDebd = false;
      } else if (acpd_b_acp2RngHiSet && (rtb_t_delay_off_kj == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S65>/flg_out' */
        acpd_b_acp2RngHiDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_cs) {
        swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_j0 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_j0 += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S65>/flg_out' incorporates:
         *  Constant: '<S11>/t_step7'
         */
        acpd_b_acp2RngHiDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_j0 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_j0 += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S65>/flg_out' incorporates:
         *  Constant: '<S11>/t_step7'
         */
        acpd_b_acp2RngHiDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c60_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp2RngHiSet) {
          if (rtb_t_delay_off_kj == 0.0F) {
            swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S65>/flg_out' */
            acpd_b_acp2RngHiDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_j0 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_j0 += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S65>/flg_out' incorporates:
             *  Constant: '<S11>/t_step7'
             */
            acpd_b_acp2RngHiDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S65>/flg_out' */
          acpd_b_acp2RngHiDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp2RngHiSet) {
          swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S65>/flg_out' */
          acpd_b_acp2RngHiDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_j0 > rtb_t_delay_off_n - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S65>/flg_out' */
          acpd_b_acp2RngHiDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_j0 += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S65>/flg_out' incorporates:
           *  Constant: '<S11>/t_step7'
           */
          acpd_b_acp2RngHiDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp2RngHiSet) {
          if (rtb_t_delay_off_n == 0.0F) {
            swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S65>/flg_out' */
            acpd_b_acp2RngHiDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_j0 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_j0 += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S65>/flg_out' incorporates:
             *  Constant: '<S11>/t_step7'
             */
            acpd_b_acp2RngHiDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S65>/flg_out' */
          acpd_b_acp2RngHiDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp2RngHiSet) {
          swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S65>/flg_out' */
          acpd_b_acp2RngHiDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_j0 > rtb_t_delay_off_kj - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c60_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S65>/flg_out' */
          acpd_b_acp2RngHiDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_j0 += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S65>/flg_out' incorporates:
           *  Constant: '<S11>/t_step7'
           */
          acpd_b_acp2RngHiDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S65>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce2_MODE_e) {
    /* Disable for SignalConversion generated from: '<S65>/flg_out' incorporates:
     *  Outport: '<S65>/flg_out'
     */
    acpd_b_acp2RngHiDebd = false;
    swc_DIAG_ARID_DEF.debounce2_MODE_e = false;
  }

  /* End of Outputs for SubSystem: '<S16>/debounce2' */

  /* CCaller: '<S46>/C Caller' incorporates:
   *  Constant: '<S11>/event_id7'
   *  DataTypeConversion: '<S11>/Data Type Conversion7'
   */
  Dem_SetEventStatus(((uint16)32887U), acpd_b_acp2RngHiDebd);

  /* Switch: '<S99>/Switch2' incorporates:
   *  Constant: '<S38>/acpc_b_acpCrsFltSet_ovrdflg'
   */
  if (acpc_b_acpCrsFltSet_ovrdflg) {
    /* Switch: '<S99>/Switch2' incorporates:
     *  Constant: '<S38>/acpc_b_acpCrsFltSet_ovrdval'
     */
    acpd_b_acpCrsFltSet = acpc_b_acpCrsFltSet_ovrdval;
  } else {
    /* Switch: '<S99>/Switch2' incorporates:
     *  Abs: '<S11>/Abs'
     *  Constant: '<S11>/Constant36'
     *  Gain: '<S11>/Gain'
     *  RelationalOperator: '<S11>/Relational Operator21'
     *  Sum: '<S11>/Sum'
     */
    acpd_b_acpCrsFltSet = (fabsf(rtb_Gain1 - 2.0F * rtb_t_delay_on_aw) >
      digc_u_acpCrsFltSet_V);
  }

  /* End of Switch: '<S99>/Switch2' */

  /* Switch: '<S98>/Switch2' incorporates:
   *  Constant: '<S37>/acpc_b_acpCrsFltEnb_ovrdflg'
   */
  if (acpc_b_acpCrsFltEnb_ovrdflg) {
    /* Switch: '<S98>/Switch2' incorporates:
     *  Constant: '<S37>/acpc_b_acpCrsFltEnb_ovrdval'
     */
    acpd_b_acpCrsFltEnb = acpc_b_acpCrsFltEnb_ovrdval;
  } else {
    /* Switch: '<S98>/Switch2' incorporates:
     *  Logic: '<S11>/Logical Operator13'
     *  Logic: '<S11>/Logical Operator14'
     *  Logic: '<S11>/Logical Operator16'
     *  Logic: '<S11>/Logical Operator17'
     *  Logic: '<S11>/Logical Operator19'
     *  Logic: '<S11>/Logical Operator21'
     *  Logic: '<S11>/Logical Operator22'
     *  Logic: '<S11>/Logical Operator24'
     *  Logic: '<S11>/Logical Operator25'
     */
    acpd_b_acpCrsFltEnb = (rtb_AND && rtb_AND1 && rtb_LogicalOperator21_tmp_tmp &&
      rtb_LogicalOperator22_tmp_tmp && (!acpd_b_acp1RngLowSet) &&
      (!acpd_b_acp1RngHiSet) && rtb_LogicalOperator24_tmp_tmp &&
      rtb_LogicalOperator25_tmp_tmp && (!acpd_b_acp2RngLowSet) &&
      (!acpd_b_acp2RngHiSet));
  }

  /* End of Switch: '<S98>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S20>/debounce' incorporates:
   *  EnablePort: '<S80>/Enable'
   */
  if (acpd_b_acpCrsFltEnb) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_id) {
      /* SystemReset for Chart: '<S80>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c26_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_fu = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_id = true;
    }

    /* Saturate: '<S80>/Saturation' incorporates:
     *  Constant: '<S11>/t_delay_fail8'
     */
    if (digc_b_acpCrsFltFail_s > 1.6777216E+7F) {
      /* Saturate: '<S80>/Saturation' */
      rtb_Gain1 = 1.6777216E+7F;
    } else if (digc_b_acpCrsFltFail_s < 0.0F) {
      /* Saturate: '<S80>/Saturation' */
      rtb_Gain1 = 0.0F;
    } else {
      /* Saturate: '<S80>/Saturation' */
      rtb_Gain1 = digc_b_acpCrsFltFail_s;
    }

    /* End of Saturate: '<S80>/Saturation' */

    /* Saturate: '<S80>/Saturation1' incorporates:
     *  Constant: '<S11>/t_delay_heal8'
     */
    if (digc_b_acpCrsFltHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S80>/Saturation1' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else if (digc_b_acpCrsFltHeal_s < 0.0F) {
      /* Saturate: '<S80>/Saturation1' */
      rtb_t_delay_on_aw = 0.0F;
    } else {
      /* Saturate: '<S80>/Saturation1' */
      rtb_t_delay_on_aw = digc_b_acpCrsFltHeal_s;
    }

    /* End of Saturate: '<S80>/Saturation1' */

    /* Chart: '<S80>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step8'
     *  DataTypeConversion: '<S80>/Data Type Conversion'
     *  UnitDelay: '<S20>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c26_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c26_swc_DIAG = 1U;
      if ((!acpd_b_acpCrsFltSet) && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S80>/flg_out' */
        acpd_b_acpCrsFltDebd = false;
      } else if (acpd_b_acpCrsFltSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S80>/flg_out' */
        acpd_b_acpCrsFltDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_lab) {
        swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_fu = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_fu += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S80>/flg_out' incorporates:
         *  Constant: '<S11>/t_step8'
         */
        acpd_b_acpCrsFltDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_fu = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_fu += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S80>/flg_out' incorporates:
         *  Constant: '<S11>/t_step8'
         */
        acpd_b_acpCrsFltDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c26_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acpCrsFltSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S80>/flg_out' */
            acpd_b_acpCrsFltDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_fu = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_fu += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S80>/flg_out' incorporates:
             *  Constant: '<S11>/t_step8'
             */
            acpd_b_acpCrsFltDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S80>/flg_out' */
          acpd_b_acpCrsFltDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acpCrsFltSet) {
          swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S80>/flg_out' */
          acpd_b_acpCrsFltDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_fu > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S80>/flg_out' */
          acpd_b_acpCrsFltDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_fu += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S80>/flg_out' incorporates:
           *  Constant: '<S11>/t_step8'
           */
          acpd_b_acpCrsFltDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acpCrsFltSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S80>/flg_out' */
            acpd_b_acpCrsFltDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_fu = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_fu += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S80>/flg_out' incorporates:
             *  Constant: '<S11>/t_step8'
             */
            acpd_b_acpCrsFltDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S80>/flg_out' */
          acpd_b_acpCrsFltDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acpCrsFltSet) {
          swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S80>/flg_out' */
          acpd_b_acpCrsFltDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_fu > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c26_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S80>/flg_out' */
          acpd_b_acpCrsFltDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_fu += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S80>/flg_out' incorporates:
           *  Constant: '<S11>/t_step8'
           */
          acpd_b_acpCrsFltDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S80>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_id) {
    /* Disable for SignalConversion generated from: '<S80>/flg_out' incorporates:
     *  Outport: '<S80>/flg_out'
     */
    acpd_b_acpCrsFltDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_id = false;
  }

  /* End of Outputs for SubSystem: '<S20>/debounce' */

  /* CCaller: '<S47>/C Caller' incorporates:
   *  Constant: '<S11>/event_id8'
   *  DataTypeConversion: '<S11>/Data Type Conversion8'
   */
  Dem_SetEventStatus(((uint16)32888U), acpd_b_acpCrsFltDebd);

  /* Outputs for Enabled SubSystem: '<S12>/debounce1' incorporates:
   *  EnablePort: '<S48>/Enable'
   */
  if (acpd_b_acp1RngHiEnb) {
    if (!swc_DIAG_ARID_DEF.debounce1_MODE_ps) {
      /* SystemReset for Chart: '<S48>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c16_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_jr = 0.0F;
      swc_DIAG_ARID_DEF.debounce1_MODE_ps = true;
    }

    /* Saturate: '<S48>/Saturation' incorporates:
     *  Constant: '<S12>/t_delay_fail1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S48>/Saturation1' */
      rtb_Gain1 = 1.6777216E+7F;
    } else {
      /* Saturate: '<S48>/Saturation1' */
      rtb_Gain1 = 0.0F;
    }

    /* Chart: '<S48>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step3'
     *  DataTypeConversion: '<S48>/Data Type Conversion'
     *  Saturate: '<S48>/Saturation'
     *  UnitDelay: '<S12>/Unit Delay1'
     */
    if (swc_DIAG_ARID_DEF.is_active_c16_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c16_swc_DIAG = 1U;
      if ((!acpd_b_acp1RngHiSet) && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S48>/flg_out' */
        acpd_b_acp1RngHiRaw = false;
      } else if (acpd_b_acp1RngHiSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S48>/flg_out' */
        acpd_b_acp1RngHiRaw = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay1_DSTATE) {
        swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_jr = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_jr += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S48>/flg_out' incorporates:
         *  Constant: '<S11>/t_step3'
         */
        acpd_b_acp1RngHiRaw = true;
      } else {
        swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_jr = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_jr += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S48>/flg_out' incorporates:
         *  Constant: '<S11>/t_step3'
         */
        acpd_b_acp1RngHiRaw = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c16_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp1RngHiSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S48>/flg_out' */
            acpd_b_acp1RngHiRaw = true;
          } else {
            swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_jr = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_jr += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S48>/flg_out' incorporates:
             *  Constant: '<S11>/t_step3'
             */
            acpd_b_acp1RngHiRaw = false;
          }
        } else {
          /* SignalConversion generated from: '<S48>/flg_out' */
          acpd_b_acp1RngHiRaw = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp1RngHiSet) {
          swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S48>/flg_out' */
          acpd_b_acp1RngHiRaw = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_jr > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S48>/flg_out' */
          acpd_b_acp1RngHiRaw = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_jr += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S48>/flg_out' incorporates:
           *  Constant: '<S11>/t_step3'
           */
          acpd_b_acp1RngHiRaw = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp1RngHiSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S48>/flg_out' */
            acpd_b_acp1RngHiRaw = false;
          } else {
            swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_jr = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_jr += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S48>/flg_out' incorporates:
             *  Constant: '<S11>/t_step3'
             */
            acpd_b_acp1RngHiRaw = true;
          }
        } else {
          /* SignalConversion generated from: '<S48>/flg_out' */
          acpd_b_acp1RngHiRaw = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp1RngHiSet) {
          swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S48>/flg_out' */
          acpd_b_acp1RngHiRaw = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_jr > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c16_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S48>/flg_out' */
          acpd_b_acp1RngHiRaw = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_jr += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S48>/flg_out' incorporates:
           *  Constant: '<S11>/t_step3'
           */
          acpd_b_acp1RngHiRaw = false;
        }
        break;
      }
    }

    /* End of Chart: '<S48>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce1_MODE_ps) {
    /* Disable for SignalConversion generated from: '<S48>/flg_out' incorporates:
     *  Outport: '<S48>/flg_out'
     */
    acpd_b_acp1RngHiRaw = false;
    swc_DIAG_ARID_DEF.debounce1_MODE_ps = false;
  }

  /* End of Outputs for SubSystem: '<S12>/debounce1' */

  /* Outputs for Enabled SubSystem: '<S13>/debounce1' incorporates:
   *  EnablePort: '<S52>/Enable'
   */
  if (acpd_b_acp1RngLowEnb) {
    if (!swc_DIAG_ARID_DEF.debounce1_MODE_c) {
      /* SystemReset for Chart: '<S52>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c18_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_nj = 0.0F;
      swc_DIAG_ARID_DEF.debounce1_MODE_c = true;
    }

    /* Saturate: '<S52>/Saturation' incorporates:
     *  Constant: '<S13>/t_delay_fail1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S52>/Saturation1' */
      rtb_Gain1 = 1.6777216E+7F;
    } else {
      /* Saturate: '<S52>/Saturation1' */
      rtb_Gain1 = 0.0F;
    }

    /* Chart: '<S52>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step2'
     *  DataTypeConversion: '<S52>/Data Type Conversion'
     *  Saturate: '<S52>/Saturation'
     *  UnitDelay: '<S13>/Unit Delay1'
     */
    if (swc_DIAG_ARID_DEF.is_active_c18_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c18_swc_DIAG = 1U;
      if ((!acpd_b_acp1RngLowSet) && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S52>/flg_out' */
        acpd_b_acp1RngLowRaw = false;
      } else if (acpd_b_acp1RngLowSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S52>/flg_out' */
        acpd_b_acp1RngLowRaw = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_f) {
        swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_nj = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_nj += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S52>/flg_out' incorporates:
         *  Constant: '<S11>/t_step2'
         */
        acpd_b_acp1RngLowRaw = true;
      } else {
        swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_nj = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_nj += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S52>/flg_out' incorporates:
         *  Constant: '<S11>/t_step2'
         */
        acpd_b_acp1RngLowRaw = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c18_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp1RngLowSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S52>/flg_out' */
            acpd_b_acp1RngLowRaw = true;
          } else {
            swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_nj = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_nj += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S52>/flg_out' incorporates:
             *  Constant: '<S11>/t_step2'
             */
            acpd_b_acp1RngLowRaw = false;
          }
        } else {
          /* SignalConversion generated from: '<S52>/flg_out' */
          acpd_b_acp1RngLowRaw = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp1RngLowSet) {
          swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S52>/flg_out' */
          acpd_b_acp1RngLowRaw = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_nj > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S52>/flg_out' */
          acpd_b_acp1RngLowRaw = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_nj += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S52>/flg_out' incorporates:
           *  Constant: '<S11>/t_step2'
           */
          acpd_b_acp1RngLowRaw = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp1RngLowSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S52>/flg_out' */
            acpd_b_acp1RngLowRaw = false;
          } else {
            swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_nj = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_nj += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S52>/flg_out' incorporates:
             *  Constant: '<S11>/t_step2'
             */
            acpd_b_acp1RngLowRaw = true;
          }
        } else {
          /* SignalConversion generated from: '<S52>/flg_out' */
          acpd_b_acp1RngLowRaw = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp1RngLowSet) {
          swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S52>/flg_out' */
          acpd_b_acp1RngLowRaw = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_nj > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c18_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S52>/flg_out' */
          acpd_b_acp1RngLowRaw = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_nj += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S52>/flg_out' incorporates:
           *  Constant: '<S11>/t_step2'
           */
          acpd_b_acp1RngLowRaw = false;
        }
        break;
      }
    }

    /* End of Chart: '<S52>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce1_MODE_c) {
    /* Disable for SignalConversion generated from: '<S52>/flg_out' incorporates:
     *  Outport: '<S52>/flg_out'
     */
    acpd_b_acp1RngLowRaw = false;
    swc_DIAG_ARID_DEF.debounce1_MODE_c = false;
  }

  /* End of Outputs for SubSystem: '<S13>/debounce1' */

  /* Outputs for Enabled SubSystem: '<S14>/debounce1' incorporates:
   *  EnablePort: '<S56>/Enable'
   */
  if (acpd_b_acp1Sho2BatEnb) {
    if (!swc_DIAG_ARID_DEF.debounce1_MODE_p) {
      /* SystemReset for Chart: '<S56>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c19_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_ng = 0.0F;
      swc_DIAG_ARID_DEF.debounce1_MODE_p = true;
    }

    /* Saturate: '<S56>/Saturation' incorporates:
     *  Constant: '<S14>/t_delay_fail1'
     *  Saturate: '<S56>/Saturation1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S56>/Saturation' */
      rtb_Gain1 = 1.6777216E+7F;

      /* Saturate: '<S56>/Saturation1' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else {
      /* Saturate: '<S56>/Saturation' */
      rtb_Gain1 = 0.0F;

      /* Saturate: '<S56>/Saturation1' incorporates:
       *  Constant: '<S14>/t_delay_fail2'
       */
      rtb_t_delay_on_aw = 0.0F;
    }

    /* End of Saturate: '<S56>/Saturation' */

    /* Chart: '<S56>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step1'
     *  DataTypeConversion: '<S56>/Data Type Conversion'
     *  UnitDelay: '<S14>/Unit Delay1'
     */
    if (swc_DIAG_ARID_DEF.is_active_c19_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c19_swc_DIAG = 1U;
      if ((!acpd_b_acp1Sho2BatSet) && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S56>/flg_out' */
        acpd_b_acp1Sho2BatRaw = false;
      } else if (acpd_b_acp1Sho2BatSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S56>/flg_out' */
        acpd_b_acp1Sho2BatRaw = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_p) {
        swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_ng = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ng += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S56>/flg_out' incorporates:
         *  Constant: '<S11>/t_step1'
         */
        acpd_b_acp1Sho2BatRaw = true;
      } else {
        swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_ng = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ng += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S56>/flg_out' incorporates:
         *  Constant: '<S11>/t_step1'
         */
        acpd_b_acp1Sho2BatRaw = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c19_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp1Sho2BatSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S56>/flg_out' */
            acpd_b_acp1Sho2BatRaw = true;
          } else {
            swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_ng = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ng += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S56>/flg_out' incorporates:
             *  Constant: '<S11>/t_step1'
             */
            acpd_b_acp1Sho2BatRaw = false;
          }
        } else {
          /* SignalConversion generated from: '<S56>/flg_out' */
          acpd_b_acp1Sho2BatRaw = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp1Sho2BatSet) {
          swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S56>/flg_out' */
          acpd_b_acp1Sho2BatRaw = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_ng > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S56>/flg_out' */
          acpd_b_acp1Sho2BatRaw = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ng += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S56>/flg_out' incorporates:
           *  Constant: '<S11>/t_step1'
           */
          acpd_b_acp1Sho2BatRaw = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp1Sho2BatSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S56>/flg_out' */
            acpd_b_acp1Sho2BatRaw = false;
          } else {
            swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_ng = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ng += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S56>/flg_out' incorporates:
             *  Constant: '<S11>/t_step1'
             */
            acpd_b_acp1Sho2BatRaw = true;
          }
        } else {
          /* SignalConversion generated from: '<S56>/flg_out' */
          acpd_b_acp1Sho2BatRaw = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp1Sho2BatSet) {
          swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S56>/flg_out' */
          acpd_b_acp1Sho2BatRaw = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_ng > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c19_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S56>/flg_out' */
          acpd_b_acp1Sho2BatRaw = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ng += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S56>/flg_out' incorporates:
           *  Constant: '<S11>/t_step1'
           */
          acpd_b_acp1Sho2BatRaw = false;
        }
        break;
      }
    }

    /* End of Chart: '<S56>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce1_MODE_p) {
    /* Disable for SignalConversion generated from: '<S56>/flg_out' incorporates:
     *  Outport: '<S56>/flg_out'
     */
    acpd_b_acp1Sho2BatRaw = false;
    swc_DIAG_ARID_DEF.debounce1_MODE_p = false;
  }

  /* End of Outputs for SubSystem: '<S14>/debounce1' */

  /* Outputs for Enabled SubSystem: '<S15>/debounce1' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (acpd_b_acp1Sho2GndEnb) {
    if (!swc_DIAG_ARID_DEF.debounce1_MODE_o) {
      /* SystemReset for Chart: '<S60>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c15_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_cv = 0.0F;
      swc_DIAG_ARID_DEF.debounce1_MODE_o = true;
    }

    /* Saturate: '<S60>/Saturation' incorporates:
     *  Constant: '<S15>/t_delay_fail1'
     *  Saturate: '<S60>/Saturation1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S60>/Saturation' */
      rtb_Gain1 = 1.6777216E+7F;

      /* Saturate: '<S60>/Saturation1' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else {
      /* Saturate: '<S60>/Saturation' */
      rtb_Gain1 = 0.0F;

      /* Saturate: '<S60>/Saturation1' incorporates:
       *  Constant: '<S15>/t_delay_fail2'
       */
      rtb_t_delay_on_aw = 0.0F;
    }

    /* End of Saturate: '<S60>/Saturation' */

    /* Chart: '<S60>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step'
     *  DataTypeConversion: '<S60>/Data Type Conversion'
     *  UnitDelay: '<S15>/Unit Delay1'
     */
    if (swc_DIAG_ARID_DEF.is_active_c15_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c15_swc_DIAG = 1U;
      if ((!acpd_b_acp1Sho2GndSet) && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S60>/flg_out' */
        acpd_b_acp1Sho2GndRaw = false;
      } else if (acpd_b_acp1Sho2GndSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S60>/flg_out' */
        acpd_b_acp1Sho2GndRaw = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_n) {
        swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_cv = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_cv += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S60>/flg_out' incorporates:
         *  Constant: '<S11>/t_step'
         */
        acpd_b_acp1Sho2GndRaw = true;
      } else {
        swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_cv = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_cv += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S60>/flg_out' incorporates:
         *  Constant: '<S11>/t_step'
         */
        acpd_b_acp1Sho2GndRaw = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c15_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp1Sho2GndSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S60>/flg_out' */
            acpd_b_acp1Sho2GndRaw = true;
          } else {
            swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_cv = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_cv += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S60>/flg_out' incorporates:
             *  Constant: '<S11>/t_step'
             */
            acpd_b_acp1Sho2GndRaw = false;
          }
        } else {
          /* SignalConversion generated from: '<S60>/flg_out' */
          acpd_b_acp1Sho2GndRaw = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp1Sho2GndSet) {
          swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S60>/flg_out' */
          acpd_b_acp1Sho2GndRaw = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_cv > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S60>/flg_out' */
          acpd_b_acp1Sho2GndRaw = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_cv += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S60>/flg_out' incorporates:
           *  Constant: '<S11>/t_step'
           */
          acpd_b_acp1Sho2GndRaw = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp1Sho2GndSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S60>/flg_out' */
            acpd_b_acp1Sho2GndRaw = false;
          } else {
            swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_cv = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_cv += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S60>/flg_out' incorporates:
             *  Constant: '<S11>/t_step'
             */
            acpd_b_acp1Sho2GndRaw = true;
          }
        } else {
          /* SignalConversion generated from: '<S60>/flg_out' */
          acpd_b_acp1Sho2GndRaw = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp1Sho2GndSet) {
          swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S60>/flg_out' */
          acpd_b_acp1Sho2GndRaw = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_cv > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c15_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S60>/flg_out' */
          acpd_b_acp1Sho2GndRaw = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_cv += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S60>/flg_out' incorporates:
           *  Constant: '<S11>/t_step'
           */
          acpd_b_acp1Sho2GndRaw = false;
        }
        break;
      }
    }

    /* End of Chart: '<S60>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce1_MODE_o) {
    /* Disable for SignalConversion generated from: '<S60>/flg_out' incorporates:
     *  Outport: '<S60>/flg_out'
     */
    acpd_b_acp1Sho2GndRaw = false;
    swc_DIAG_ARID_DEF.debounce1_MODE_o = false;
  }

  /* End of Outputs for SubSystem: '<S15>/debounce1' */

  /* Outputs for Enabled SubSystem: '<S16>/debounce1' incorporates:
   *  EnablePort: '<S64>/Enable'
   */
  if (acpd_b_acp2RngHiEnb) {
    if (!swc_DIAG_ARID_DEF.debounce1_MODE_f) {
      /* SystemReset for Chart: '<S64>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c20_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_aq = 0.0F;
      swc_DIAG_ARID_DEF.debounce1_MODE_f = true;
    }

    /* Saturate: '<S64>/Saturation' incorporates:
     *  Constant: '<S16>/t_delay_fail1'
     *  Saturate: '<S64>/Saturation1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S64>/Saturation' */
      rtb_Gain1 = 1.6777216E+7F;

      /* Saturate: '<S64>/Saturation1' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else {
      /* Saturate: '<S64>/Saturation' */
      rtb_Gain1 = 0.0F;

      /* Saturate: '<S64>/Saturation1' incorporates:
       *  Constant: '<S16>/t_delay_fail2'
       */
      rtb_t_delay_on_aw = 0.0F;
    }

    /* End of Saturate: '<S64>/Saturation' */

    /* Chart: '<S64>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step7'
     *  DataTypeConversion: '<S64>/Data Type Conversion'
     *  UnitDelay: '<S16>/Unit Delay1'
     */
    if (swc_DIAG_ARID_DEF.is_active_c20_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c20_swc_DIAG = 1U;
      if ((!acpd_b_acp2RngHiSet) && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S64>/flg_out' */
        acpd_b_acp2RngHiRaw = false;
      } else if (acpd_b_acp2RngHiSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S64>/flg_out' */
        acpd_b_acp2RngHiRaw = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_o) {
        swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_aq = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_aq += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S64>/flg_out' incorporates:
         *  Constant: '<S11>/t_step7'
         */
        acpd_b_acp2RngHiRaw = true;
      } else {
        swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_aq = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_aq += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S64>/flg_out' incorporates:
         *  Constant: '<S11>/t_step7'
         */
        acpd_b_acp2RngHiRaw = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c20_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp2RngHiSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S64>/flg_out' */
            acpd_b_acp2RngHiRaw = true;
          } else {
            swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_aq = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_aq += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S64>/flg_out' incorporates:
             *  Constant: '<S11>/t_step7'
             */
            acpd_b_acp2RngHiRaw = false;
          }
        } else {
          /* SignalConversion generated from: '<S64>/flg_out' */
          acpd_b_acp2RngHiRaw = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp2RngHiSet) {
          swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S64>/flg_out' */
          acpd_b_acp2RngHiRaw = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_aq > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S64>/flg_out' */
          acpd_b_acp2RngHiRaw = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_aq += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S64>/flg_out' incorporates:
           *  Constant: '<S11>/t_step7'
           */
          acpd_b_acp2RngHiRaw = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp2RngHiSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S64>/flg_out' */
            acpd_b_acp2RngHiRaw = false;
          } else {
            swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_aq = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_aq += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S64>/flg_out' incorporates:
             *  Constant: '<S11>/t_step7'
             */
            acpd_b_acp2RngHiRaw = true;
          }
        } else {
          /* SignalConversion generated from: '<S64>/flg_out' */
          acpd_b_acp2RngHiRaw = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp2RngHiSet) {
          swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S64>/flg_out' */
          acpd_b_acp2RngHiRaw = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_aq > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c20_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S64>/flg_out' */
          acpd_b_acp2RngHiRaw = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_aq += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S64>/flg_out' incorporates:
           *  Constant: '<S11>/t_step7'
           */
          acpd_b_acp2RngHiRaw = false;
        }
        break;
      }
    }

    /* End of Chart: '<S64>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce1_MODE_f) {
    /* Disable for SignalConversion generated from: '<S64>/flg_out' incorporates:
     *  Outport: '<S64>/flg_out'
     */
    acpd_b_acp2RngHiRaw = false;
    swc_DIAG_ARID_DEF.debounce1_MODE_f = false;
  }

  /* End of Outputs for SubSystem: '<S16>/debounce1' */

  /* Outputs for Enabled SubSystem: '<S17>/debounce1' incorporates:
   *  EnablePort: '<S68>/Enable'
   */
  if (acpd_b_acp2RngLowEnb) {
    if (!swc_DIAG_ARID_DEF.debounce1_MODE_h) {
      /* SystemReset for Chart: '<S68>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c21_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_a3 = 0.0F;
      swc_DIAG_ARID_DEF.debounce1_MODE_h = true;
    }

    /* Saturate: '<S68>/Saturation' incorporates:
     *  Constant: '<S17>/t_delay_fail1'
     *  Saturate: '<S68>/Saturation1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S68>/Saturation' */
      rtb_Gain1 = 1.6777216E+7F;

      /* Saturate: '<S68>/Saturation1' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else {
      /* Saturate: '<S68>/Saturation' */
      rtb_Gain1 = 0.0F;

      /* Saturate: '<S68>/Saturation1' incorporates:
       *  Constant: '<S17>/t_delay_fail2'
       */
      rtb_t_delay_on_aw = 0.0F;
    }

    /* End of Saturate: '<S68>/Saturation' */

    /* Chart: '<S68>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step6'
     *  DataTypeConversion: '<S68>/Data Type Conversion'
     *  UnitDelay: '<S17>/Unit Delay1'
     */
    if (swc_DIAG_ARID_DEF.is_active_c21_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c21_swc_DIAG = 1U;
      if ((!acpd_b_acp2RngLowSet) && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S68>/flg_out' */
        acpd_b_acp2RngLowRaw = false;
      } else if (acpd_b_acp2RngLowSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S68>/flg_out' */
        acpd_b_acp2RngLowRaw = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_j) {
        swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_a3 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_a3 += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S68>/flg_out' incorporates:
         *  Constant: '<S11>/t_step6'
         */
        acpd_b_acp2RngLowRaw = true;
      } else {
        swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_a3 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_a3 += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S68>/flg_out' incorporates:
         *  Constant: '<S11>/t_step6'
         */
        acpd_b_acp2RngLowRaw = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c21_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp2RngLowSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S68>/flg_out' */
            acpd_b_acp2RngLowRaw = true;
          } else {
            swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_a3 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_a3 += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S68>/flg_out' incorporates:
             *  Constant: '<S11>/t_step6'
             */
            acpd_b_acp2RngLowRaw = false;
          }
        } else {
          /* SignalConversion generated from: '<S68>/flg_out' */
          acpd_b_acp2RngLowRaw = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp2RngLowSet) {
          swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S68>/flg_out' */
          acpd_b_acp2RngLowRaw = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_a3 > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S68>/flg_out' */
          acpd_b_acp2RngLowRaw = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_a3 += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S68>/flg_out' incorporates:
           *  Constant: '<S11>/t_step6'
           */
          acpd_b_acp2RngLowRaw = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp2RngLowSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S68>/flg_out' */
            acpd_b_acp2RngLowRaw = false;
          } else {
            swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_a3 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_a3 += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S68>/flg_out' incorporates:
             *  Constant: '<S11>/t_step6'
             */
            acpd_b_acp2RngLowRaw = true;
          }
        } else {
          /* SignalConversion generated from: '<S68>/flg_out' */
          acpd_b_acp2RngLowRaw = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp2RngLowSet) {
          swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S68>/flg_out' */
          acpd_b_acp2RngLowRaw = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_a3 > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c21_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S68>/flg_out' */
          acpd_b_acp2RngLowRaw = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_a3 += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S68>/flg_out' incorporates:
           *  Constant: '<S11>/t_step6'
           */
          acpd_b_acp2RngLowRaw = false;
        }
        break;
      }
    }

    /* End of Chart: '<S68>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce1_MODE_h) {
    /* Disable for SignalConversion generated from: '<S68>/flg_out' incorporates:
     *  Outport: '<S68>/flg_out'
     */
    acpd_b_acp2RngLowRaw = false;
    swc_DIAG_ARID_DEF.debounce1_MODE_h = false;
  }

  /* End of Outputs for SubSystem: '<S17>/debounce1' */

  /* Outputs for Enabled SubSystem: '<S18>/debounce1' incorporates:
   *  EnablePort: '<S72>/Enable'
   */
  if (acpd_b_acp2Sho2BatEnb) {
    if (!swc_DIAG_ARID_DEF.debounce1_MODE_b) {
      /* SystemReset for Chart: '<S72>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c23_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_n = 0.0F;
      swc_DIAG_ARID_DEF.debounce1_MODE_b = true;
    }

    /* Saturate: '<S72>/Saturation' incorporates:
     *  Constant: '<S18>/t_delay_fail1'
     *  Saturate: '<S72>/Saturation1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S72>/Saturation' */
      rtb_Gain1 = 1.6777216E+7F;

      /* Saturate: '<S72>/Saturation1' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else {
      /* Saturate: '<S72>/Saturation' */
      rtb_Gain1 = 0.0F;

      /* Saturate: '<S72>/Saturation1' incorporates:
       *  Constant: '<S18>/t_delay_fail2'
       */
      rtb_t_delay_on_aw = 0.0F;
    }

    /* End of Saturate: '<S72>/Saturation' */

    /* Chart: '<S72>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step5'
     *  DataTypeConversion: '<S72>/Data Type Conversion'
     *  UnitDelay: '<S18>/Unit Delay1'
     */
    if (swc_DIAG_ARID_DEF.is_active_c23_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c23_swc_DIAG = 1U;
      if ((!acpd_b_acp2Sho2BatSet) && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S72>/flg_out' */
        acpd_b_acp2Sho2BatRaw = false;
      } else if (acpd_b_acp2Sho2BatSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S72>/flg_out' */
        acpd_b_acp2Sho2BatRaw = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_i) {
        swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_n = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_n += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S72>/flg_out' incorporates:
         *  Constant: '<S11>/t_step5'
         */
        acpd_b_acp2Sho2BatRaw = true;
      } else {
        swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_n = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_n += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S72>/flg_out' incorporates:
         *  Constant: '<S11>/t_step5'
         */
        acpd_b_acp2Sho2BatRaw = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c23_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp2Sho2BatSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S72>/flg_out' */
            acpd_b_acp2Sho2BatRaw = true;
          } else {
            swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_n = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_n += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S72>/flg_out' incorporates:
             *  Constant: '<S11>/t_step5'
             */
            acpd_b_acp2Sho2BatRaw = false;
          }
        } else {
          /* SignalConversion generated from: '<S72>/flg_out' */
          acpd_b_acp2Sho2BatRaw = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp2Sho2BatSet) {
          swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S72>/flg_out' */
          acpd_b_acp2Sho2BatRaw = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_n > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S72>/flg_out' */
          acpd_b_acp2Sho2BatRaw = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_n += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S72>/flg_out' incorporates:
           *  Constant: '<S11>/t_step5'
           */
          acpd_b_acp2Sho2BatRaw = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp2Sho2BatSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S72>/flg_out' */
            acpd_b_acp2Sho2BatRaw = false;
          } else {
            swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_n = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_n += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S72>/flg_out' incorporates:
             *  Constant: '<S11>/t_step5'
             */
            acpd_b_acp2Sho2BatRaw = true;
          }
        } else {
          /* SignalConversion generated from: '<S72>/flg_out' */
          acpd_b_acp2Sho2BatRaw = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp2Sho2BatSet) {
          swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S72>/flg_out' */
          acpd_b_acp2Sho2BatRaw = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_n > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c23_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S72>/flg_out' */
          acpd_b_acp2Sho2BatRaw = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_n += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S72>/flg_out' incorporates:
           *  Constant: '<S11>/t_step5'
           */
          acpd_b_acp2Sho2BatRaw = false;
        }
        break;
      }
    }

    /* End of Chart: '<S72>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce1_MODE_b) {
    /* Disable for SignalConversion generated from: '<S72>/flg_out' incorporates:
     *  Outport: '<S72>/flg_out'
     */
    acpd_b_acp2Sho2BatRaw = false;
    swc_DIAG_ARID_DEF.debounce1_MODE_b = false;
  }

  /* End of Outputs for SubSystem: '<S18>/debounce1' */

  /* Outputs for Enabled SubSystem: '<S19>/debounce1' incorporates:
   *  EnablePort: '<S76>/Enable'
   */
  if (acpd_b_acp2Sho2GndEnb) {
    if (!swc_DIAG_ARID_DEF.debounce1_MODE) {
      /* SystemReset for Chart: '<S76>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c25_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD;
      swc_DIAG_ARID_DEF.t_wait_ij = 0.0F;
      swc_DIAG_ARID_DEF.debounce1_MODE = true;
    }

    /* Saturate: '<S76>/Saturation' incorporates:
     *  Constant: '<S19>/t_delay_fail1'
     *  Saturate: '<S76>/Saturation1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S76>/Saturation' */
      rtb_Gain1 = 1.6777216E+7F;

      /* Saturate: '<S76>/Saturation1' */
      rtb_t_delay_on_aw = 1.6777216E+7F;
    } else {
      /* Saturate: '<S76>/Saturation' */
      rtb_Gain1 = 0.0F;

      /* Saturate: '<S76>/Saturation1' incorporates:
       *  Constant: '<S19>/t_delay_fail2'
       */
      rtb_t_delay_on_aw = 0.0F;
    }

    /* End of Saturate: '<S76>/Saturation' */

    /* Chart: '<S76>/timed_debounce' incorporates:
     *  Constant: '<S11>/t_step4'
     *  DataTypeConversion: '<S76>/Data Type Conversion'
     *  UnitDelay: '<S19>/Unit Delay1'
     */
    if (swc_DIAG_ARID_DEF.is_active_c25_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c25_swc_DIAG = 1U;
      if ((!acpd_b_acp2Sho2GndSet) && (rtb_t_delay_on_aw == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_OFF_no;

        /* SignalConversion generated from: '<S76>/flg_out' */
        acpd_b_acp2Sho2GndRaw = false;
      } else if (acpd_b_acp2Sho2GndSet && (rtb_Gain1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_ON_j;

        /* SignalConversion generated from: '<S76>/flg_out' */
        acpd_b_acp2Sho2GndRaw = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_l) {
        swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
        swc_DIAG_ARID_DEF.t_wait_ij = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ij += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S76>/flg_out' incorporates:
         *  Constant: '<S11>/t_step4'
         */
        acpd_b_acp2Sho2GndRaw = true;
      } else {
        swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_ij = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ij += ((float32)ACP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S76>/flg_out' incorporates:
         *  Constant: '<S11>/t_step4'
         */
        acpd_b_acp2Sho2GndRaw = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c25_swc_DIAG) {
       case swc_DIAG_IN_OFF_no:
        if (acpd_b_acp2Sho2GndSet) {
          if (rtb_Gain1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_ON_j;

            /* SignalConversion generated from: '<S76>/flg_out' */
            acpd_b_acp2Sho2GndRaw = true;
          } else {
            swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_ON_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_ij = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ij += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S76>/flg_out' incorporates:
             *  Constant: '<S11>/t_step4'
             */
            acpd_b_acp2Sho2GndRaw = false;
          }
        } else {
          /* SignalConversion generated from: '<S76>/flg_out' */
          acpd_b_acp2Sho2GndRaw = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_o:
        if (acpd_b_acp2Sho2GndSet) {
          swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S76>/flg_out' */
          acpd_b_acp2Sho2GndRaw = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_ij > rtb_t_delay_on_aw - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S76>/flg_out' */
          acpd_b_acp2Sho2GndRaw = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ij += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S76>/flg_out' incorporates:
           *  Constant: '<S11>/t_step4'
           */
          acpd_b_acp2Sho2GndRaw = true;
        }
        break;

       case swc_DIAG_IN_ON_j:
        if (!acpd_b_acp2Sho2GndSet) {
          if (rtb_t_delay_on_aw == 0.0F) {
            swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_OFF_no;

            /* SignalConversion generated from: '<S76>/flg_out' */
            acpd_b_acp2Sho2GndRaw = false;
          } else {
            swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_OFF_WAIT_o;
            swc_DIAG_ARID_DEF.t_wait_ij = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ij += ((float32)ACP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S76>/flg_out' incorporates:
             *  Constant: '<S11>/t_step4'
             */
            acpd_b_acp2Sho2GndRaw = true;
          }
        } else {
          /* SignalConversion generated from: '<S76>/flg_out' */
          acpd_b_acp2Sho2GndRaw = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!acpd_b_acp2Sho2GndSet) {
          swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_OFF_no;

          /* SignalConversion generated from: '<S76>/flg_out' */
          acpd_b_acp2Sho2GndRaw = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_ij > rtb_Gain1 - ((float32)
                    ACP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c25_swc_DIAG = swc_DIAG_IN_ON_j;

          /* SignalConversion generated from: '<S76>/flg_out' */
          acpd_b_acp2Sho2GndRaw = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ij += ((float32)ACP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S76>/flg_out' incorporates:
           *  Constant: '<S11>/t_step4'
           */
          acpd_b_acp2Sho2GndRaw = false;
        }
        break;
      }
    }

    /* End of Chart: '<S76>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce1_MODE) {
    /* Disable for SignalConversion generated from: '<S76>/flg_out' incorporates:
     *  Outport: '<S76>/flg_out'
     */
    acpd_b_acp2Sho2GndRaw = false;
    swc_DIAG_ARID_DEF.debounce1_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S19>/debounce1' */

  /* Logic: '<S11>/Logical Operator20' */
  digd_b_vcuVehLvl1Flt_flg_ACP = (acpd_b_acp1Sho2GndDebd ||
    acpd_b_acp1Sho2BatDebd || acpd_b_acp1RngLowDebd || acpd_b_acp1RngHiDebd ||
    acpd_b_acp2Sho2GndDebd || acpd_b_acp2Sho2BatDebd || acpd_b_acp2RngLowDebd ||
    acpd_b_acp2RngHiDebd);

  /* Logic: '<S11>/Logical Operator8' incorporates:
   *  Logic: '<S11>/Logical Operator9'
   */
  rtb_AND = !swc_DIAG_ARID_DEF.OutportBufferForflg_out;
  rtb_LogicalOperator21_tmp_tmp = !swc_DIAG_ARID_DEF.OutportBufferForflg_out_h;

  /* Logic: '<S11>/Logical Operator8' */
  acpd_b_accPed1Vld = ((!acpd_b_acp1Sho2GndRaw) && (!acpd_b_acp1Sho2BatRaw) && (
    !acpd_b_acp1RngLowRaw) && (!acpd_b_acp1RngHiRaw) &&
                       rtb_LogicalOperator21_tmp_tmp && rtb_AND);

  /* Logic: '<S11>/Logical Operator9' */
  acpd_b_accPed2Vld = (rtb_AND && rtb_LogicalOperator21_tmp_tmp &&
                       (!acpd_b_acp2Sho2GndRaw) && (!acpd_b_acp2Sho2BatRaw) && (
    !acpd_b_acp2RngLowRaw) && (!acpd_b_acp2RngHiRaw));

  /* SignalConversion: '<S11>/Signal Conversion' */
  digd_b_vcuVehLvl23Flt_flg_ACP = acpd_b_acpCrsFltDebd;

  /* Update for UnitDelay: '<S15>/Unit Delay2' */
  swc_DIAG_ARID_DEF.UnitDelay2_DSTATE = acpd_b_acp1Sho2GndDebd;

  /* Update for UnitDelay: '<S14>/Unit Delay2' */
  swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_k = acpd_b_acp1Sho2BatDebd;

  /* Update for UnitDelay: '<S13>/Unit Delay2' */
  swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_c = acpd_b_acp1RngLowDebd;

  /* Update for UnitDelay: '<S12>/Unit Delay2' */
  swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_a = acpd_b_acp1RngHiDebd;

  /* Update for UnitDelay: '<S19>/Unit Delay2' */
  swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_p = acpd_b_acp2Sho2GndDebd;

  /* Update for UnitDelay: '<S18>/Unit Delay2' */
  swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_j = acpd_b_acp2Sho2BatDebd;

  /* Update for UnitDelay: '<S17>/Unit Delay2' */
  swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_n = acpd_b_acp2RngLowDebd;

  /* Update for UnitDelay: '<S16>/Unit Delay2' */
  swc_DIAG_ARID_DEF.UnitDelay2_DSTATE_cs = acpd_b_acp2RngHiDebd;

  /* Update for UnitDelay: '<S20>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_lab = acpd_b_acpCrsFltDebd;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  swc_DIAG_ARID_DEF.UnitDelay1_DSTATE = acpd_b_acp1RngHiRaw;

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_f = acpd_b_acp1RngLowRaw;

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_p = acpd_b_acp1Sho2BatRaw;

  /* Update for UnitDelay: '<S15>/Unit Delay1' */
  swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_n = acpd_b_acp1Sho2GndRaw;

  /* Update for UnitDelay: '<S16>/Unit Delay1' */
  swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_o = acpd_b_acp2RngHiRaw;

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_j = acpd_b_acp2RngLowRaw;

  /* Update for UnitDelay: '<S18>/Unit Delay1' */
  swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_i = acpd_b_acp2Sho2BatRaw;

  /* Update for UnitDelay: '<S19>/Unit Delay1' */
  swc_DIAG_ARID_DEF.UnitDelay1_DSTATE_l = acpd_b_acp2Sho2GndRaw;
}

/*
 * System initialize for atomic system:
 *    '<S165>/timed_debounce'
 *    '<S160>/timed_debounce'
 */
static void swc_DIAG_timed_debounce_Init(boolean *rty_flg_out)
{
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S165>/timed_debounce'
 *    '<S160>/timed_debounce'
 */
static void swc_DIAG_timed_debounce(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_delay_off, float32 rtu_t_step, boolean *rty_flg_out,
  ARID_DEF_timed_debounce_swc_D_T *swc_DIAG__ARID_DEF_arg)
{
  /* Chart: '<S165>/timed_debounce' */
  if (swc_DIAG__ARID_DEF_arg->is_active_c65_swc_DIAG == 0U) {
    swc_DIAG__ARID_DEF_arg->is_active_c65_swc_DIAG = 1U;
    if (rtu_flg_in) {
      swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_ON;
      *rty_flg_out = true;
    } else {
      swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_OFF;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG) {
     case swc_DIAG_IN_OFF:
      if (rtu_flg_in) {
        if (rtu_t_delay_on == 0.0F) {
          swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_ON;
          *rty_flg_out = true;
        } else {
          swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_ON_WAIT;
          swc_DIAG__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_DIAG_IN_OFF_WAIT:
      if (rtu_flg_in) {
        swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_ON;
        *rty_flg_out = true;
      } else if (swc_DIAG__ARID_DEF_arg->t_wait > rtu_t_delay_off - rtu_t_step)
      {
        swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_OFF;
        *rty_flg_out = false;
      } else {
        swc_DIAG__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     case swc_DIAG_IN_ON:
      if (!rtu_flg_in) {
        if (rtu_t_delay_off == 0.0F) {
          swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_OFF;
          *rty_flg_out = false;
        } else {
          swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_OFF_WAIT;
          swc_DIAG__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_OFF;
        *rty_flg_out = false;
      } else if (swc_DIAG__ARID_DEF_arg->t_wait > rtu_t_delay_on - rtu_t_step) {
        swc_DIAG__ARID_DEF_arg->is_c65_swc_DIAG = swc_DIAG_IN_ON;
        *rty_flg_out = true;
      } else {
        swc_DIAG__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S165>/timed_debounce' */
}

/*
 * System initialize for atomic system:
 *    '<S117>/turnOFF_delay'
 *    '<S117>/turnOFF_delay1'
 */
static void swc_DIAG_turnOFF_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S161>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S117>/turnOFF_delay'
 *    '<S117>/turnOFF_delay1'
 */
static void swc_DIAG_turnOFF_delay(boolean rtu_flg_in, float32 rtu_t_delay_off,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnOFF_delay_swc_DI_T
  *swc_DIAG__ARID_DEF_arg)
{
  float32 rtb_t_delay_off_p4;

  /* Saturate: '<S161>/Saturation1' */
  if (rtu_t_delay_off > 1.6777216E+7F) {
    /* Saturate: '<S161>/Saturation1' */
    rtb_t_delay_off_p4 = 1.6777216E+7F;
  } else if (rtu_t_delay_off < 0.0F) {
    /* Saturate: '<S161>/Saturation1' */
    rtb_t_delay_off_p4 = 0.0F;
  } else {
    /* Saturate: '<S161>/Saturation1' */
    rtb_t_delay_off_p4 = rtu_t_delay_off;
  }

  /* End of Saturate: '<S161>/Saturation1' */

  /* Chart: '<S161>/timed_delay' incorporates:
   *  DataTypeConversion: '<S161>/Data Type Conversion'
   */
  if (swc_DIAG__ARID_DEF_arg->is_active_c62_swc_DIAG == 0U) {
    swc_DIAG__ARID_DEF_arg->is_active_c62_swc_DIAG = 1U;
    if (rtu_flg_in) {
      swc_DIAG__ARID_DEF_arg->is_c62_swc_DIAG = swc_DIAG_IN_ON_a;
      *rty_flg_out = true;
    } else {
      swc_DIAG__ARID_DEF_arg->is_c62_swc_DIAG = swc_DIAG_IN_OFF_n;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_DIAG__ARID_DEF_arg->is_c62_swc_DIAG) {
     case swc_DIAG_IN_OFF_n:
      if (rtu_flg_in) {
        swc_DIAG__ARID_DEF_arg->is_c62_swc_DIAG = swc_DIAG_IN_ON_a;
        *rty_flg_out = true;
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_DIAG_IN_OFF_WAIT_b:
      if (rtu_flg_in) {
        swc_DIAG__ARID_DEF_arg->is_c62_swc_DIAG = swc_DIAG_IN_ON_a;
        *rty_flg_out = true;
      } else if (swc_DIAG__ARID_DEF_arg->t_wait > rtb_t_delay_off_p4 -
                 rtu_t_step) {
        swc_DIAG__ARID_DEF_arg->is_c62_swc_DIAG = swc_DIAG_IN_OFF_n;
        *rty_flg_out = false;
      } else {
        swc_DIAG__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON: */
      if (!rtu_flg_in) {
        if (rtb_t_delay_off_p4 == 0.0F) {
          swc_DIAG__ARID_DEF_arg->is_c62_swc_DIAG = swc_DIAG_IN_OFF_n;
          *rty_flg_out = false;
        } else {
          swc_DIAG__ARID_DEF_arg->is_c62_swc_DIAG = swc_DIAG_IN_OFF_WAIT_b;
          swc_DIAG__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = true;
        }
      } else {
        *rty_flg_out = true;
      }
      break;
    }
  }

  /* End of Chart: '<S161>/timed_delay' */
}

/* System initialize for function-call system: '<S1>/BRP_Diag' */
static void swc_DIAG_BRP_Diag_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out_e;
  boolean rtb_flg_out_gc;
  boolean rtb_flg_out_m4;

  /* InitializeConditions for Delay: '<S117>/Delay1' */
  swc_DIAG_ARID_DEF.Delay1_DSTATE = ((uint8)1U);

  /* InitializeConditions for Delay: '<S117>/Delay' */
  swc_DIAG_ARID_DEF.Delay_DSTATE = ((uint8)0U);

  /* SystemInitialize for Atomic SubSystem: '<S117>/debounce1' */
  /* SystemInitialize for Chart: '<S160>/timed_debounce' */
  swc_DIAG_timed_debounce_Init(&rtb_flg_out_m4);

  /* End of SystemInitialize for SubSystem: '<S117>/debounce1' */

  /* SystemInitialize for Atomic SubSystem: '<S117>/turnOFF_delay' */
  swc_DIAG_turnOFF_delay_Init(&rtb_flg_out_gc);

  /* End of SystemInitialize for SubSystem: '<S117>/turnOFF_delay' */

  /* SystemInitialize for Atomic SubSystem: '<S117>/turnOFF_delay1' */
  swc_DIAG_turnOFF_delay_Init(&rtb_flg_out_e);

  /* End of SystemInitialize for SubSystem: '<S117>/turnOFF_delay1' */

  /* SystemInitialize for Enabled SubSystem: '<S117>/Enabled Subsystem' */
  /* SystemInitialize for Atomic SubSystem: '<S159>/debounce3' */
  /* SystemInitialize for Chart: '<S165>/timed_debounce' */
  swc_DIAG_timed_debounce_Init(&swc_DIAG_ARID_DEF.flg_out_p);

  /* End of SystemInitialize for SubSystem: '<S159>/debounce3' */
  /* End of SystemInitialize for SubSystem: '<S117>/Enabled Subsystem' */

  /* SystemInitialize for SignalConversion: '<S101>/Signal Conversion' */
  brpd_b_brkSwtMismatch = swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq;
}

/* Output and update for function-call system: '<S1>/BRP_Diag' */
static void swc_DIAG_BRP_Diag(void)
{
  /* local block i/o variables */
  float32 rtb_t_delay_on_p2;
  float32 rtb_t_delay_off_kk;
  float32 rtb_Saturation;
  float32 rtb_Saturation1;
  uint8 rtb_BreakSts;
  boolean rtb_FixPtRelationalOperator_o;
  boolean rtb_FixPtRelationalOperator_e;
  boolean rtb_flg_out_e;
  boolean rtb_flg_out_gc;
  boolean rtb_DataTypeConversion_h;
  boolean rtb_flg_out_m4;
  boolean rtb_DataTypeConversion_cq;
  float32 rtb_t_delay_off_dr;
  float32 rtb_t_delay_on_ii;
  uint8 rtb_FltCounter;
  uint8 tmp;
  boolean rtb_LogicalOperator106;
  boolean rtb_LogicalOperator9;
  boolean rtb_SignalConversion1;

  /* CCaller: '<S117>/C Caller' */
  brpd_d_BrkSigStoreCn = mBSW_NvmRead_BrkSwtFltCnt();

  /* Outputs for Atomic SubSystem: '<S117>/debounce1' */
  /* DataTypeConversion: '<S160>/Data Type Conversion' incorporates:
   *  Constant: '<S150>/Constant'
   *  Constant: '<S151>/Constant'
   *  Logic: '<S117>/Logical Operator6'
   *  RelationalOperator: '<S150>/Compare'
   *  RelationalOperator: '<S151>/Compare'
   */
  rtb_DataTypeConversion_h = ((swc_DIAG_ARID_DEF.DataTypeConversion3 == 1.0) &&
    (swc_DIAG_ARID_DEF.DataTypeConversion2 == 1.0) &&
    swc_DIAG_ARID_DEF.DataTypeConversion254);

  /* Saturate: '<S160>/Saturation' incorporates:
   *  Constant: '<S117>/t_delay_fail1'
   */
  if (digc_b_brkSwtMismatchFail_s > 1.6777216E+7F) {
    /* Saturate: '<S160>/Saturation' */
    rtb_t_delay_on_p2 = 1.6777216E+7F;
  } else if (digc_b_brkSwtMismatchFail_s < 0.0F) {
    /* Saturate: '<S160>/Saturation' */
    rtb_t_delay_on_p2 = 0.0F;
  } else {
    /* Saturate: '<S160>/Saturation' */
    rtb_t_delay_on_p2 = digc_b_brkSwtMismatchFail_s;
  }

  /* End of Saturate: '<S160>/Saturation' */

  /* Saturate: '<S160>/Saturation1' incorporates:
   *  Constant: '<S117>/t_delay_heal1'
   */
  if (0.0F > 1.6777216E+7F) {
    /* Saturate: '<S160>/Saturation1' */
    rtb_t_delay_off_kk = 1.6777216E+7F;
  } else {
    /* Saturate: '<S160>/Saturation1' */
    rtb_t_delay_off_kk = 0.0F;
  }

  /* End of Saturate: '<S160>/Saturation1' */

  /* Chart: '<S160>/timed_debounce' incorporates:
   *  Constant: '<S117>/Constant9'
   */
  swc_DIAG_timed_debounce(rtb_DataTypeConversion_h, rtb_t_delay_on_p2,
    rtb_t_delay_off_kk, ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_m4,
    &swc_DIAG_ARID_DEF.ARID_DEF_timed_debounce);

  /* End of Outputs for SubSystem: '<S117>/debounce1' */

  /* RelationalOperator: '<S157>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  brpd_b_brakeUnreasn_flg = ((sint32)rtb_flg_out_m4 > (sint32)
    swc_DIAG_ARID_DEF.DelayInput1_DSTATE_p);

  /* Logic: '<S117>/Logical Operator1' incorporates:
   *  Constant: '<S148>/Constant'
   *  Constant: '<S149>/Constant'
   *  RelationalOperator: '<S148>/Compare'
   *  RelationalOperator: '<S149>/Compare'
   */
  brpd_b_brakeStateOpen_flg = ((swc_DIAG_ARID_DEF.DataTypeConversion3 == 1.0) &&
    (swc_DIAG_ARID_DEF.DataTypeConversion2 == 0.0) &&
    swc_DIAG_ARID_DEF.DataTypeConversion254);

  /* Logic: '<S117>/Logical Operator2' incorporates:
   *  Constant: '<S152>/Constant'
   *  Constant: '<S153>/Constant'
   *  RelationalOperator: '<S152>/Compare'
   *  RelationalOperator: '<S153>/Compare'
   */
  brpd_b_brakeStateOff_flg = ((swc_DIAG_ARID_DEF.DataTypeConversion3 == 0.0) &&
    (swc_DIAG_ARID_DEF.DataTypeConversion2 == 1.0) &&
    swc_DIAG_ARID_DEF.DataTypeConversion254);

  /* Chart: '<S117>/Chart1' */
  if (swc_DIAG_ARID_DEF.is_active_c24_swc_DIAG == 0U) {
    swc_DIAG_ARID_DEF.is_active_c24_swc_DIAG = 1U;
    swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_INIT;
    rtb_FltCounter = 0U;
    swc_DIAG_ARID_DEF.ClearEn = false;
    rtb_BreakSts = 0U;
  } else {
    switch (swc_DIAG_ARID_DEF.is_c24_swc_DIAG) {
     case swc_DIAG_IN_CLEAR1:
      rtb_FltCounter = 0U;
      rtb_BreakSts = 4U;
      if (brpd_b_brakeUnreasn_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_ERRCN1;
        rtb_FltCounter = 1U;
        swc_DIAG_ARID_DEF.ClearEn = false;
        rtb_BreakSts = 1U;
      }
      break;

     case swc_DIAG_IN_CLEAR2:
      rtb_FltCounter = 0U;
      rtb_BreakSts = 6U;
      if (brpd_b_brakeUnreasn_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_ERRCN1;
        rtb_FltCounter = 1U;
        swc_DIAG_ARID_DEF.ClearEn = false;
        rtb_BreakSts = 1U;
      }
      break;

     case swc_DIAG_IN_ERRCN1:
      rtb_FltCounter = 1U;
      rtb_BreakSts = 1U;
      if (brpd_b_brakeStateOff_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_STATE1;
        rtb_FltCounter = 0U;
        swc_DIAG_ARID_DEF.ClearEn = false;
        rtb_BreakSts = 2U;
      } else if (brpd_b_brakeStateOpen_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_STATE2;
        rtb_FltCounter = 0U;
        swc_DIAG_ARID_DEF.ClearEn = false;
        rtb_BreakSts = 3U;
      }
      break;

     case swc_DIAG_IN_INIT:
      rtb_FltCounter = 0U;
      rtb_BreakSts = 0U;
      if (brpd_b_brakeUnreasn_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_ERRCN1;
        rtb_FltCounter = 1U;
        swc_DIAG_ARID_DEF.ClearEn = false;
        rtb_BreakSts = 1U;
      }
      break;

     case swc_DIAG_IN_STATE1:
      rtb_FltCounter = 0U;
      rtb_BreakSts = 2U;
      if (brpd_b_brakeStateOpen_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_CLEAR1;
        swc_DIAG_ARID_DEF.ClearEn = true;
        rtb_BreakSts = 4U;
      } else if (brpd_b_brakeUnreasn_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_ERRCN1;
        rtb_FltCounter = 1U;
        swc_DIAG_ARID_DEF.ClearEn = false;
        rtb_BreakSts = 1U;
      }
      break;

     default:
      /* case IN_STATE2: */
      rtb_FltCounter = 0U;
      rtb_BreakSts = 3U;
      if (brpd_b_brakeStateOff_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_CLEAR2;
        swc_DIAG_ARID_DEF.ClearEn = true;
        rtb_BreakSts = 6U;
      } else if (brpd_b_brakeUnreasn_flg) {
        swc_DIAG_ARID_DEF.is_c24_swc_DIAG = swc_DIAG_IN_ERRCN1;
        rtb_FltCounter = 1U;
        swc_DIAG_ARID_DEF.ClearEn = false;
        rtb_BreakSts = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S117>/Chart1' */

  /* RelationalOperator: '<S155>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S155>/Delay Input1'
   *
   * Block description for '<S155>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_o = ((sint32)brpd_b_brakeStateOpen_flg < (sint32)
    swc_DIAG_ARID_DEF.DelayInput1_DSTATE_a);

  /* Outputs for Atomic SubSystem: '<S117>/turnOFF_delay' */
  /* Constant: '<S117>/t_delay_heal2' incorporates:
   *  Constant: '<S117>/Constant2'
   */
  swc_DIAG_turnOFF_delay(rtb_FixPtRelationalOperator_o, digc_tm_brkStsOpenDly_s,
    ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_gc,
    &swc_DIAG_ARID_DEF.ARID_DEF_turnOFF_delay);

  /* End of Outputs for SubSystem: '<S117>/turnOFF_delay' */

  /* RelationalOperator: '<S156>/FixPt Relational Operator' incorporates:
   *  UnitDelay: '<S156>/Delay Input1'
   *
   * Block description for '<S156>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_FixPtRelationalOperator_e = ((sint32)brpd_b_brakeStateOff_flg < (sint32)
    swc_DIAG_ARID_DEF.DelayInput1_DSTATE_c);

  /* Outputs for Atomic SubSystem: '<S117>/turnOFF_delay1' */
  /* Constant: '<S117>/t_delay_heal3' incorporates:
   *  Constant: '<S117>/Constant3'
   */
  swc_DIAG_turnOFF_delay(rtb_FixPtRelationalOperator_e, digc_tm_brkStsOffDly_s,
    ((float32)BRP_TASK_INTERVAL_S), &rtb_flg_out_e,
    &swc_DIAG_ARID_DEF.ARID_DEF_turnOFF_delay1);

  /* End of Outputs for SubSystem: '<S117>/turnOFF_delay1' */

  /* Logic: '<S117>/Logical Operator11' incorporates:
   *  Logic: '<S117>/Logical Operator12'
   *  Logic: '<S117>/Logical Operator13'
   */
  brpd_b_breakFailOver_flg = ((rtb_flg_out_gc && brpd_b_brakeStateOff_flg) ||
    (rtb_flg_out_e && brpd_b_brakeStateOpen_flg));

  /* Logic: '<S117>/Logical Operator9' */
  rtb_LogicalOperator9 = (swc_DIAG_ARID_DEF.ClearEn || brpd_b_breakFailOver_flg);

  /* Delay: '<S117>/Delay' */
  if (((swc_DIAG_ARID_DEF.Delay_Reset_ZCE == POS_ZCSIG) != (sint32)
       rtb_LogicalOperator9) && (swc_DIAG_ARID_DEF.Delay_Reset_ZCE !=
       UNINITIALIZED_ZCSIG)) {
    swc_DIAG_ARID_DEF.Delay_DSTATE = ((uint8)0U);
  }

  swc_DIAG_ARID_DEF.Delay_Reset_ZCE = rtb_LogicalOperator9;

  /* Switch: '<S117>/Switch' incorporates:
   *  Constant: '<S117>/Constant'
   *  Delay: '<S117>/Delay1'
   */
  if (swc_DIAG_ARID_DEF.Delay1_DSTATE > ((uint8)0U)) {
    tmp = brpd_d_BrkSigStoreCn;
  } else {
    tmp = ((uint8)0U);
  }

  /* Sum: '<S117>/Subtract' incorporates:
   *  Delay: '<S117>/Delay'
   *  RelationalOperator: '<S158>/FixPt Relational Operator'
   *  Switch: '<S117>/Switch'
   *  UnitDelay: '<S158>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  brpd_d_BrkSigErrCn = (uint8)((uint32)(uint8)((uint32)(rtb_FltCounter >
    swc_DIAG_ARID_DEF.DelayInput1_DSTATE) + tmp) +
    swc_DIAG_ARID_DEF.Delay_DSTATE);

  /* RelationalOperator: '<S154>/Compare' incorporates:
   *  Constant: '<S154>/Constant'
   */
  brpd_b_BrkSigUnreasnFlt_Flg = (brpd_d_BrkSigErrCn >= ((uint8)3U));

  /* Outputs for Enabled SubSystem: '<S117>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S159>/Enable'
   */
  if (swc_DIAG_ARID_DEF.DataTypeConversion254) {
    /* Outputs for Atomic SubSystem: '<S159>/debounce3' */
    /* DataTypeConversion: '<S165>/Data Type Conversion' incorporates:
     *  Constant: '<S163>/Constant'
     *  Constant: '<S164>/Constant'
     *  Logic: '<S159>/Logical Operator3'
     *  RelationalOperator: '<S163>/Compare'
     *  RelationalOperator: '<S164>/Compare'
     */
    rtb_DataTypeConversion_cq = ((swc_DIAG_ARID_DEF.DataTypeConversion3 == 0.0) &&
      (swc_DIAG_ARID_DEF.DataTypeConversion2 == 0.0));

    /* Saturate: '<S165>/Saturation' incorporates:
     *  Constant: '<S159>/t_delay_fail3'
     */
    if (digc_b_brkSwtMismatchFail_s > 1.6777216E+7F) {
      /* Saturate: '<S165>/Saturation' */
      rtb_Saturation = 1.6777216E+7F;
    } else if (digc_b_brkSwtMismatchFail_s < 0.0F) {
      /* Saturate: '<S165>/Saturation' */
      rtb_Saturation = 0.0F;
    } else {
      /* Saturate: '<S165>/Saturation' */
      rtb_Saturation = digc_b_brkSwtMismatchFail_s;
    }

    /* End of Saturate: '<S165>/Saturation' */

    /* Saturate: '<S165>/Saturation1' incorporates:
     *  Constant: '<S159>/t_delay_heal3'
     */
    if (brpc_b_brkSwtMismatchHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S165>/Saturation1' */
      rtb_Saturation1 = 1.6777216E+7F;
    } else if (brpc_b_brkSwtMismatchHeal_s < 0.0F) {
      /* Saturate: '<S165>/Saturation1' */
      rtb_Saturation1 = 0.0F;
    } else {
      /* Saturate: '<S165>/Saturation1' */
      rtb_Saturation1 = brpc_b_brkSwtMismatchHeal_s;
    }

    /* End of Saturate: '<S165>/Saturation1' */

    /* Chart: '<S165>/timed_debounce' incorporates:
     *  Constant: '<S159>/Constant2'
     */
    swc_DIAG_timed_debounce(rtb_DataTypeConversion_cq, rtb_Saturation,
      rtb_Saturation1, ((float32)BRP_TASK_INTERVAL_S),
      &swc_DIAG_ARID_DEF.flg_out_p, &swc_DIAG_ARID_DEF.ARID_DEF_timed_debounce_b);

    /* End of Outputs for SubSystem: '<S159>/debounce3' */
  }

  /* End of Outputs for SubSystem: '<S117>/Enabled Subsystem' */

  /* Logic: '<S117>/Logical Operator10' incorporates:
   *  Logic: '<S117>/Logical Operator4'
   */
  brpd_b_brakeMutExcErr_flg = ((brpd_b_BrkSigUnreasnFlt_Flg ||
    swc_DIAG_ARID_DEF.flg_out_p) && swc_DIAG_ARID_DEF.DataTypeConversion254);

  /* Switch: '<S140>/Switch2' incorporates:
   *  Constant: '<S110>/brpc_b_brkSwtMismatchSet_ovrdflg'
   */
  if (brpc_b_brkSwtMismatchSet_ovrdflg) {
    /* Switch: '<S140>/Switch2' incorporates:
     *  Constant: '<S110>/brpc_b_brkSwtMismatchSet_ovrdval'
     */
    brpd_b_brkSwtMismatchSet = brpc_b_brkSwtMismatchSet_ovrdval;
  } else {
    /* Switch: '<S140>/Switch2' */
    brpd_b_brkSwtMismatchSet = brpd_b_brakeMutExcErr_flg;
  }

  /* End of Switch: '<S140>/Switch2' */

  /* Logic: '<S100>/Logical Operator63' */
  rtb_LogicalOperator9 = !macb_b_P2AD4;

  /* Logic: '<S100>/Logical Operator106' */
  rtb_LogicalOperator106 = !macb_b_P2AD5;

  /* Switch: '<S139>/Switch2' incorporates:
   *  Constant: '<S109>/brpc_b_brkSwtMismatchEnb_ovrdflg'
   */
  if (brpc_b_brkSwtMismatchEnb_ovrdflg) {
    /* Switch: '<S139>/Switch2' incorporates:
     *  Constant: '<S109>/brpc_b_brkSwtMismatchEnb_ovrdval'
     */
    brpd_b_brkSwtMismatchEnb = brpc_b_brkSwtMismatchEnb_ovrdval;
  } else {
    /* Switch: '<S139>/Switch2' incorporates:
     *  Logic: '<S101>/OR'
     */
    brpd_b_brkSwtMismatchEnb = (rtb_LogicalOperator9 && rtb_LogicalOperator106 &&
      swc_DIAG_ARID_DEF.DataTypeConversion254);
  }

  /* End of Switch: '<S139>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S102>/debounce' incorporates:
   *  EnablePort: '<S125>/Enable'
   */
  if (brpd_b_brkSwtMismatchEnb) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_kx) {
      /* SystemReset for Chart: '<S125>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c12_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_f;
      swc_DIAG_ARID_DEF.t_wait_eg = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_kx = true;
    }

    /* Saturate: '<S125>/Saturation' incorporates:
     *  Constant: '<S101>/t_delay_fail'
     *  Saturate: '<S125>/Saturation1'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S125>/Saturation' */
      rtb_t_delay_on_ii = 1.6777216E+7F;

      /* Saturate: '<S125>/Saturation1' */
      rtb_t_delay_off_dr = 1.6777216E+7F;
    } else {
      /* Saturate: '<S125>/Saturation' */
      rtb_t_delay_on_ii = 0.0F;

      /* Saturate: '<S125>/Saturation1' incorporates:
       *  Constant: '<S101>/t_delay_heal'
       */
      rtb_t_delay_off_dr = 0.0F;
    }

    /* End of Saturate: '<S125>/Saturation' */

    /* Chart: '<S125>/timed_debounce' incorporates:
     *  Constant: '<S101>/t_step'
     *  DataTypeConversion: '<S125>/Data Type Conversion'
     *  UnitDelay: '<S102>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c12_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c12_swc_DIAG = 1U;
      if ((!brpd_b_brkSwtMismatchSet) && (rtb_t_delay_off_dr == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_OFF_j;

        /* SignalConversion generated from: '<S125>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
      } else if (brpd_b_brkSwtMismatchSet && (rtb_t_delay_on_ii == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_ON_ju;

        /* SignalConversion generated from: '<S125>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_pd) {
        swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
        swc_DIAG_ARID_DEF.t_wait_eg = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_eg += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S125>/flg_out' incorporates:
         *  Constant: '<S101>/t_step'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = true;
      } else {
        swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
        swc_DIAG_ARID_DEF.t_wait_eg = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_eg += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S125>/flg_out' incorporates:
         *  Constant: '<S101>/t_step'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c12_swc_DIAG) {
       case swc_DIAG_IN_OFF_j:
        if (brpd_b_brkSwtMismatchSet) {
          if (rtb_t_delay_on_ii == 0.0F) {
            swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_ON_ju;

            /* SignalConversion generated from: '<S125>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = true;
          } else {
            swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
            swc_DIAG_ARID_DEF.t_wait_eg = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_eg += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S125>/flg_out' incorporates:
             *  Constant: '<S101>/t_step'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
          }
        } else {
          /* SignalConversion generated from: '<S125>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_d:
        if (brpd_b_brkSwtMismatchSet) {
          swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S125>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_eg > rtb_t_delay_off_dr - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S125>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_eg += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S125>/flg_out' incorporates:
           *  Constant: '<S101>/t_step'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = true;
        }
        break;

       case swc_DIAG_IN_ON_ju:
        if (!brpd_b_brkSwtMismatchSet) {
          if (rtb_t_delay_off_dr == 0.0F) {
            swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_OFF_j;

            /* SignalConversion generated from: '<S125>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
          } else {
            swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
            swc_DIAG_ARID_DEF.t_wait_eg = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_eg += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S125>/flg_out' incorporates:
             *  Constant: '<S101>/t_step'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = true;
          }
        } else {
          /* SignalConversion generated from: '<S125>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!brpd_b_brkSwtMismatchSet) {
          swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S125>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_eg > rtb_t_delay_on_ii - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c12_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S125>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_eg += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S125>/flg_out' incorporates:
           *  Constant: '<S101>/t_step'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
        }
        break;
      }
    }

    /* End of Chart: '<S125>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_kx) {
    /* Disable for SignalConversion generated from: '<S125>/flg_out' incorporates:
     *  Outport: '<S125>/flg_out'
     */
    swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq = false;
    swc_DIAG_ARID_DEF.debounce_MODE_kx = false;
  }

  /* End of Outputs for SubSystem: '<S102>/debounce' */

  /* SignalConversion: '<S101>/Signal Conversion1' */
  rtb_SignalConversion1 = swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq;

  /* CCaller: '<S118>/C Caller' incorporates:
   *  Constant: '<S101>/event_id'
   *  DataTypeConversion: '<S101>/Data Type Conversion'
   *  SignalConversion: '<S101>/Signal Conversion1'
   */
  Dem_SetEventStatus(((uint16)32935U),
                     swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq);

  /* Switch: '<S144>/Switch2' incorporates:
   *  Constant: '<S114>/brpc_b_BdcacOpTmLongFltSet_ovrdflg'
   */
  if (brpc_b_VacPumpRlyFltSet_ovrdflg) {
    /* Switch: '<S144>/Switch2' incorporates:
     *  Constant: '<S114>/brpc_b_BdcacOpTmLongFltSet_ovrdval'
     */
    brpd_b_VacPumpRlyFltSet = brpc_b_VacPumpRlyFltSet_ovrdval;
  } else {
    /* Switch: '<S144>/Switch2' */
    brpd_b_VacPumpRlyFltSet = swc_DIAG_ARID_DEF.DataTypeConversion31;
  }

  /* End of Switch: '<S144>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S104>/debounce' incorporates:
   *  EnablePort: '<S129>/Enable'
   */
  /* Logic: '<S101>/Logical Operator44' */
  if (rtb_LogicalOperator9 && rtb_LogicalOperator106 &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_o5) {
      /* SystemReset for Chart: '<S129>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c1_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_f;
      swc_DIAG_ARID_DEF.t_wait_jv = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_o5 = true;
    }

    /* Saturate: '<S129>/Saturation' incorporates:
     *  Constant: '<S101>/t_delay_fail17'
     */
    if (2.0F > 1.6777216E+7F) {
      /* Saturate: '<S129>/Saturation1' */
      rtb_t_delay_on_ii = 1.6777216E+7F;
    } else if (2.0F < 0.0F) {
      /* Saturate: '<S129>/Saturation1' */
      rtb_t_delay_on_ii = 0.0F;
    } else {
      /* Saturate: '<S129>/Saturation1' */
      rtb_t_delay_on_ii = 2.0F;
    }

    /* Chart: '<S129>/timed_debounce' incorporates:
     *  Constant: '<S101>/t_step18'
     *  DataTypeConversion: '<S129>/Data Type Conversion'
     *  Saturate: '<S129>/Saturation'
     *  UnitDelay: '<S104>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c1_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c1_swc_DIAG = 1U;
      if ((!brpd_b_VacPumpRlyFltSet) && (rtb_t_delay_on_ii == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_OFF_j;

        /* SignalConversion generated from: '<S129>/flg_out' */
        brpd_b_VacPumpRlyFltDebd = false;
      } else if (brpd_b_VacPumpRlyFltSet && (rtb_t_delay_on_ii == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_ON_ju;

        /* SignalConversion generated from: '<S129>/flg_out' */
        brpd_b_VacPumpRlyFltDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_h1) {
        swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
        swc_DIAG_ARID_DEF.t_wait_jv = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_jv += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S129>/flg_out' incorporates:
         *  Constant: '<S101>/t_step18'
         */
        brpd_b_VacPumpRlyFltDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
        swc_DIAG_ARID_DEF.t_wait_jv = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_jv += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S129>/flg_out' incorporates:
         *  Constant: '<S101>/t_step18'
         */
        brpd_b_VacPumpRlyFltDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c1_swc_DIAG) {
       case swc_DIAG_IN_OFF_j:
        if (brpd_b_VacPumpRlyFltSet) {
          if (rtb_t_delay_on_ii == 0.0F) {
            swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_ON_ju;

            /* SignalConversion generated from: '<S129>/flg_out' */
            brpd_b_VacPumpRlyFltDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
            swc_DIAG_ARID_DEF.t_wait_jv = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_jv += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S129>/flg_out' incorporates:
             *  Constant: '<S101>/t_step18'
             */
            brpd_b_VacPumpRlyFltDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S129>/flg_out' */
          brpd_b_VacPumpRlyFltDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_d:
        if (brpd_b_VacPumpRlyFltSet) {
          swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S129>/flg_out' */
          brpd_b_VacPumpRlyFltDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_jv > rtb_t_delay_on_ii - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S129>/flg_out' */
          brpd_b_VacPumpRlyFltDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_jv += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S129>/flg_out' incorporates:
           *  Constant: '<S101>/t_step18'
           */
          brpd_b_VacPumpRlyFltDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_ju:
        if (!brpd_b_VacPumpRlyFltSet) {
          if (rtb_t_delay_on_ii == 0.0F) {
            swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_OFF_j;

            /* SignalConversion generated from: '<S129>/flg_out' */
            brpd_b_VacPumpRlyFltDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
            swc_DIAG_ARID_DEF.t_wait_jv = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_jv += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S129>/flg_out' incorporates:
             *  Constant: '<S101>/t_step18'
             */
            brpd_b_VacPumpRlyFltDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S129>/flg_out' */
          brpd_b_VacPumpRlyFltDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!brpd_b_VacPumpRlyFltSet) {
          swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S129>/flg_out' */
          brpd_b_VacPumpRlyFltDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_jv > rtb_t_delay_on_ii - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c1_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S129>/flg_out' */
          brpd_b_VacPumpRlyFltDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_jv += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S129>/flg_out' incorporates:
           *  Constant: '<S101>/t_step18'
           */
          brpd_b_VacPumpRlyFltDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S129>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_o5) {
    /* Disable for SignalConversion generated from: '<S129>/flg_out' incorporates:
     *  Outport: '<S129>/flg_out'
     */
    brpd_b_VacPumpRlyFltDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_o5 = false;
  }

  /* End of Logic: '<S101>/Logical Operator44' */
  /* End of Outputs for SubSystem: '<S104>/debounce' */

  /* CCaller: '<S119>/C Caller' incorporates:
   *  Constant: '<S101>/event_id16'
   *  DataTypeConversion: '<S101>/Data Type Conversion1'
   */
  Dem_SetEventStatus(((uint16)32982U), brpd_b_VacPumpRlyFltDebd);

  /* Switch: '<S143>/Switch2' incorporates:
   *  Constant: '<S113>/brpc_b_BdcacOpTmLongFltSet_ovrdflg'
   */
  if (brpc_b_VacPumpLoPreFltSet_ovrdflg) {
    /* Switch: '<S143>/Switch2' incorporates:
     *  Constant: '<S113>/brpc_b_BdcacOpTmLongFltSet_ovrdval'
     */
    brpd_b_VacPumpLoPreSet = brpc_b_VacPumpLoPreFltSet_ovrdval;
  } else {
    /* Switch: '<S143>/Switch2' */
    brpd_b_VacPumpLoPreSet = swc_DIAG_ARID_DEF.DataTypeConversion16;
  }

  /* End of Switch: '<S143>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S103>/debounce' incorporates:
   *  EnablePort: '<S127>/Enable'
   */
  /* Logic: '<S101>/Logical Operator1' */
  if (rtb_LogicalOperator9 && rtb_LogicalOperator106 &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_c0) {
      /* SystemReset for Chart: '<S127>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c2_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_f;
      swc_DIAG_ARID_DEF.t_wait_df = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_c0 = true;
    }

    /* Saturate: '<S127>/Saturation' incorporates:
     *  Constant: '<S101>/t_delay_fail13'
     */
    if (5.0F > 1.6777216E+7F) {
      /* Saturate: '<S127>/Saturation' */
      rtb_t_delay_on_ii = 1.6777216E+7F;
    } else if (5.0F < 0.0F) {
      /* Saturate: '<S127>/Saturation' */
      rtb_t_delay_on_ii = 0.0F;
    } else {
      /* Saturate: '<S127>/Saturation' */
      rtb_t_delay_on_ii = 5.0F;
    }

    /* End of Saturate: '<S127>/Saturation' */

    /* Saturate: '<S127>/Saturation1' incorporates:
     *  Constant: '<S101>/t_delay_heal12'
     */
    if (2.0F > 1.6777216E+7F) {
      /* Saturate: '<S127>/Saturation1' */
      rtb_t_delay_off_dr = 1.6777216E+7F;
    } else if (2.0F < 0.0F) {
      /* Saturate: '<S127>/Saturation1' */
      rtb_t_delay_off_dr = 0.0F;
    } else {
      /* Saturate: '<S127>/Saturation1' */
      rtb_t_delay_off_dr = 2.0F;
    }

    /* End of Saturate: '<S127>/Saturation1' */

    /* Chart: '<S127>/timed_debounce' incorporates:
     *  Constant: '<S101>/t_step14'
     *  DataTypeConversion: '<S127>/Data Type Conversion'
     *  UnitDelay: '<S103>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c2_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c2_swc_DIAG = 1U;
      if ((!brpd_b_VacPumpLoPreSet) && (rtb_t_delay_off_dr == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_OFF_j;

        /* SignalConversion generated from: '<S127>/flg_out' */
        brpd_b_VacPumpLoPreDebd = false;
      } else if (brpd_b_VacPumpLoPreSet && (rtb_t_delay_on_ii == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_ON_ju;

        /* SignalConversion generated from: '<S127>/flg_out' */
        brpd_b_VacPumpLoPreDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_lc) {
        swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
        swc_DIAG_ARID_DEF.t_wait_df = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_df += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S127>/flg_out' incorporates:
         *  Constant: '<S101>/t_step14'
         */
        brpd_b_VacPumpLoPreDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
        swc_DIAG_ARID_DEF.t_wait_df = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_df += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S127>/flg_out' incorporates:
         *  Constant: '<S101>/t_step14'
         */
        brpd_b_VacPumpLoPreDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c2_swc_DIAG) {
       case swc_DIAG_IN_OFF_j:
        if (brpd_b_VacPumpLoPreSet) {
          if (rtb_t_delay_on_ii == 0.0F) {
            swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_ON_ju;

            /* SignalConversion generated from: '<S127>/flg_out' */
            brpd_b_VacPumpLoPreDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
            swc_DIAG_ARID_DEF.t_wait_df = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_df += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S127>/flg_out' incorporates:
             *  Constant: '<S101>/t_step14'
             */
            brpd_b_VacPumpLoPreDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S127>/flg_out' */
          brpd_b_VacPumpLoPreDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_d:
        if (brpd_b_VacPumpLoPreSet) {
          swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S127>/flg_out' */
          brpd_b_VacPumpLoPreDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_df > rtb_t_delay_off_dr - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S127>/flg_out' */
          brpd_b_VacPumpLoPreDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_df += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S127>/flg_out' incorporates:
           *  Constant: '<S101>/t_step14'
           */
          brpd_b_VacPumpLoPreDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_ju:
        if (!brpd_b_VacPumpLoPreSet) {
          if (rtb_t_delay_off_dr == 0.0F) {
            swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_OFF_j;

            /* SignalConversion generated from: '<S127>/flg_out' */
            brpd_b_VacPumpLoPreDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
            swc_DIAG_ARID_DEF.t_wait_df = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_df += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S127>/flg_out' incorporates:
             *  Constant: '<S101>/t_step14'
             */
            brpd_b_VacPumpLoPreDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S127>/flg_out' */
          brpd_b_VacPumpLoPreDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!brpd_b_VacPumpLoPreSet) {
          swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S127>/flg_out' */
          brpd_b_VacPumpLoPreDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_df > rtb_t_delay_on_ii - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c2_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S127>/flg_out' */
          brpd_b_VacPumpLoPreDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_df += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S127>/flg_out' incorporates:
           *  Constant: '<S101>/t_step14'
           */
          brpd_b_VacPumpLoPreDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S127>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_c0) {
    /* Disable for SignalConversion generated from: '<S127>/flg_out' incorporates:
     *  Outport: '<S127>/flg_out'
     */
    brpd_b_VacPumpLoPreDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_c0 = false;
  }

  /* End of Logic: '<S101>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S103>/debounce' */

  /* CCaller: '<S120>/C Caller' incorporates:
   *  Constant: '<S101>/event_id12'
   *  DataTypeConversion: '<S101>/Data Type Conversion2'
   */
  Dem_SetEventStatus(((uint16)32915U), brpd_b_VacPumpLoPreDebd);

  /* Switch: '<S141>/Switch2' incorporates:
   *  Constant: '<S111>/brpc_b_BdcacOpTmLongFltSet_ovrdflg'
   */
  if (brpc_b_VacPumpEnOvrTmHiPreFltSet_ovrdflg) {
    /* Switch: '<S141>/Switch2' incorporates:
     *  Constant: '<S111>/brpc_b_BdcacOpTmLongFltSet_ovrdval'
     */
    brpd_b_VpEnOvTmHiPreSet = brpc_b_VacPumpEnOvrTmHiPreFltSet_ovrdval;
  } else {
    /* Switch: '<S141>/Switch2' */
    brpd_b_VpEnOvTmHiPreSet = swc_DIAG_ARID_DEF.DataTypeConversion27;
  }

  /* End of Switch: '<S141>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S107>/debounce' incorporates:
   *  EnablePort: '<S135>/Enable'
   */
  /* Logic: '<S101>/Logical Operator2' */
  if (rtb_LogicalOperator9 && rtb_LogicalOperator106 &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_mr) {
      /* SystemReset for Chart: '<S135>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c3_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_f;
      swc_DIAG_ARID_DEF.t_wait_fp = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_mr = true;
    }

    /* Saturate: '<S135>/Saturation' incorporates:
     *  Constant: '<S101>/t_delay_fail14'
     */
    if (45.0F > 1.6777216E+7F) {
      /* Saturate: '<S135>/Saturation' */
      rtb_t_delay_on_ii = 1.6777216E+7F;
    } else if (45.0F < 0.0F) {
      /* Saturate: '<S135>/Saturation' */
      rtb_t_delay_on_ii = 0.0F;
    } else {
      /* Saturate: '<S135>/Saturation' */
      rtb_t_delay_on_ii = 45.0F;
    }

    /* End of Saturate: '<S135>/Saturation' */

    /* Saturate: '<S135>/Saturation1' incorporates:
     *  Constant: '<S101>/t_delay_heal13'
     */
    if (2.0F > 1.6777216E+7F) {
      /* Saturate: '<S135>/Saturation1' */
      rtb_t_delay_off_dr = 1.6777216E+7F;
    } else if (2.0F < 0.0F) {
      /* Saturate: '<S135>/Saturation1' */
      rtb_t_delay_off_dr = 0.0F;
    } else {
      /* Saturate: '<S135>/Saturation1' */
      rtb_t_delay_off_dr = 2.0F;
    }

    /* End of Saturate: '<S135>/Saturation1' */

    /* Chart: '<S135>/timed_debounce' incorporates:
     *  Constant: '<S101>/t_step1'
     *  DataTypeConversion: '<S135>/Data Type Conversion'
     *  UnitDelay: '<S107>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c3_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c3_swc_DIAG = 1U;
      if ((!brpd_b_VpEnOvTmHiPreSet) && (rtb_t_delay_off_dr == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_OFF_j;

        /* SignalConversion generated from: '<S135>/flg_out' */
        brpd_b_VpEnOvTmHiPreDebd = false;
      } else if (brpd_b_VpEnOvTmHiPreSet && (rtb_t_delay_on_ii == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_ON_ju;

        /* SignalConversion generated from: '<S135>/flg_out' */
        brpd_b_VpEnOvTmHiPreDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_dh) {
        swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
        swc_DIAG_ARID_DEF.t_wait_fp = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_fp += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S135>/flg_out' incorporates:
         *  Constant: '<S101>/t_step1'
         */
        brpd_b_VpEnOvTmHiPreDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
        swc_DIAG_ARID_DEF.t_wait_fp = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_fp += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S135>/flg_out' incorporates:
         *  Constant: '<S101>/t_step1'
         */
        brpd_b_VpEnOvTmHiPreDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c3_swc_DIAG) {
       case swc_DIAG_IN_OFF_j:
        if (brpd_b_VpEnOvTmHiPreSet) {
          if (rtb_t_delay_on_ii == 0.0F) {
            swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_ON_ju;

            /* SignalConversion generated from: '<S135>/flg_out' */
            brpd_b_VpEnOvTmHiPreDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
            swc_DIAG_ARID_DEF.t_wait_fp = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_fp += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S135>/flg_out' incorporates:
             *  Constant: '<S101>/t_step1'
             */
            brpd_b_VpEnOvTmHiPreDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S135>/flg_out' */
          brpd_b_VpEnOvTmHiPreDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_d:
        if (brpd_b_VpEnOvTmHiPreSet) {
          swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S135>/flg_out' */
          brpd_b_VpEnOvTmHiPreDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_fp > rtb_t_delay_off_dr - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S135>/flg_out' */
          brpd_b_VpEnOvTmHiPreDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_fp += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S135>/flg_out' incorporates:
           *  Constant: '<S101>/t_step1'
           */
          brpd_b_VpEnOvTmHiPreDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_ju:
        if (!brpd_b_VpEnOvTmHiPreSet) {
          if (rtb_t_delay_off_dr == 0.0F) {
            swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_OFF_j;

            /* SignalConversion generated from: '<S135>/flg_out' */
            brpd_b_VpEnOvTmHiPreDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
            swc_DIAG_ARID_DEF.t_wait_fp = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_fp += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S135>/flg_out' incorporates:
             *  Constant: '<S101>/t_step1'
             */
            brpd_b_VpEnOvTmHiPreDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S135>/flg_out' */
          brpd_b_VpEnOvTmHiPreDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!brpd_b_VpEnOvTmHiPreSet) {
          swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S135>/flg_out' */
          brpd_b_VpEnOvTmHiPreDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_fp > rtb_t_delay_on_ii - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c3_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S135>/flg_out' */
          brpd_b_VpEnOvTmHiPreDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_fp += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S135>/flg_out' incorporates:
           *  Constant: '<S101>/t_step1'
           */
          brpd_b_VpEnOvTmHiPreDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S135>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_mr) {
    /* Disable for SignalConversion generated from: '<S135>/flg_out' incorporates:
     *  Outport: '<S135>/flg_out'
     */
    brpd_b_VpEnOvTmHiPreDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_mr = false;
  }

  /* End of Logic: '<S101>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S107>/debounce' */

  /* CCaller: '<S121>/C Caller' incorporates:
   *  Constant: '<S101>/event_id13'
   *  DataTypeConversion: '<S101>/Data Type Conversion3'
   */
  Dem_SetEventStatus(((uint16)32916U), brpd_b_VpEnOvTmHiPreDebd);

  /* Switch: '<S142>/Switch2' incorporates:
   *  Constant: '<S112>/brpc_b_BdcacOpTmLongFltSet_ovrdflg'
   */
  if (brpc_b_VacPumpEnOvrTmLoPreFltSet_ovrdflg) {
    /* Switch: '<S142>/Switch2' incorporates:
     *  Constant: '<S112>/brpc_b_BdcacOpTmLongFltSet_ovrdval'
     */
    brpd_b_VpEnOvrTmLoPreSet = brpc_b_VacPumpEnOvrTmLoPreFltSet_ovrdval;
  } else {
    /* Switch: '<S142>/Switch2' */
    brpd_b_VpEnOvrTmLoPreSet = swc_DIAG_ARID_DEF.DataTypeConversion28;
  }

  /* End of Switch: '<S142>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S108>/debounce' incorporates:
   *  EnablePort: '<S137>/Enable'
   */
  /* Logic: '<S101>/Logical Operator3' */
  if (rtb_LogicalOperator9 && rtb_LogicalOperator106 &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_av) {
      /* SystemReset for Chart: '<S137>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c4_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_f;
      swc_DIAG_ARID_DEF.t_wait_lj = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_av = true;
    }

    /* Saturate: '<S137>/Saturation' incorporates:
     *  Constant: '<S101>/t_delay_fail15'
     */
    if (45.0F > 1.6777216E+7F) {
      /* Saturate: '<S137>/Saturation' */
      rtb_t_delay_on_ii = 1.6777216E+7F;
    } else if (45.0F < 0.0F) {
      /* Saturate: '<S137>/Saturation' */
      rtb_t_delay_on_ii = 0.0F;
    } else {
      /* Saturate: '<S137>/Saturation' */
      rtb_t_delay_on_ii = 45.0F;
    }

    /* End of Saturate: '<S137>/Saturation' */

    /* Saturate: '<S137>/Saturation1' incorporates:
     *  Constant: '<S101>/t_delay_heal14'
     */
    if (2.0F > 1.6777216E+7F) {
      /* Saturate: '<S137>/Saturation1' */
      rtb_t_delay_off_dr = 1.6777216E+7F;
    } else if (2.0F < 0.0F) {
      /* Saturate: '<S137>/Saturation1' */
      rtb_t_delay_off_dr = 0.0F;
    } else {
      /* Saturate: '<S137>/Saturation1' */
      rtb_t_delay_off_dr = 2.0F;
    }

    /* End of Saturate: '<S137>/Saturation1' */

    /* Chart: '<S137>/timed_debounce' incorporates:
     *  Constant: '<S101>/t_step16'
     *  DataTypeConversion: '<S137>/Data Type Conversion'
     *  UnitDelay: '<S108>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c4_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c4_swc_DIAG = 1U;
      if ((!brpd_b_VpEnOvrTmLoPreSet) && (rtb_t_delay_off_dr == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_OFF_j;

        /* SignalConversion generated from: '<S137>/flg_out' */
        brpd_b_VpEnOvrTmLoPreDebd = false;
      } else if (brpd_b_VpEnOvrTmLoPreSet && (rtb_t_delay_on_ii == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_ON_ju;

        /* SignalConversion generated from: '<S137>/flg_out' */
        brpd_b_VpEnOvrTmLoPreDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_i0) {
        swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
        swc_DIAG_ARID_DEF.t_wait_lj = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_lj += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S137>/flg_out' incorporates:
         *  Constant: '<S101>/t_step16'
         */
        brpd_b_VpEnOvrTmLoPreDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
        swc_DIAG_ARID_DEF.t_wait_lj = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_lj += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S137>/flg_out' incorporates:
         *  Constant: '<S101>/t_step16'
         */
        brpd_b_VpEnOvrTmLoPreDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c4_swc_DIAG) {
       case swc_DIAG_IN_OFF_j:
        if (brpd_b_VpEnOvrTmLoPreSet) {
          if (rtb_t_delay_on_ii == 0.0F) {
            swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_ON_ju;

            /* SignalConversion generated from: '<S137>/flg_out' */
            brpd_b_VpEnOvrTmLoPreDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
            swc_DIAG_ARID_DEF.t_wait_lj = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_lj += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S137>/flg_out' incorporates:
             *  Constant: '<S101>/t_step16'
             */
            brpd_b_VpEnOvrTmLoPreDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S137>/flg_out' */
          brpd_b_VpEnOvrTmLoPreDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_d:
        if (brpd_b_VpEnOvrTmLoPreSet) {
          swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S137>/flg_out' */
          brpd_b_VpEnOvrTmLoPreDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_lj > rtb_t_delay_off_dr - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S137>/flg_out' */
          brpd_b_VpEnOvrTmLoPreDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_lj += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S137>/flg_out' incorporates:
           *  Constant: '<S101>/t_step16'
           */
          brpd_b_VpEnOvrTmLoPreDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_ju:
        if (!brpd_b_VpEnOvrTmLoPreSet) {
          if (rtb_t_delay_off_dr == 0.0F) {
            swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_OFF_j;

            /* SignalConversion generated from: '<S137>/flg_out' */
            brpd_b_VpEnOvrTmLoPreDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
            swc_DIAG_ARID_DEF.t_wait_lj = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_lj += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S137>/flg_out' incorporates:
             *  Constant: '<S101>/t_step16'
             */
            brpd_b_VpEnOvrTmLoPreDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S137>/flg_out' */
          brpd_b_VpEnOvrTmLoPreDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!brpd_b_VpEnOvrTmLoPreSet) {
          swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S137>/flg_out' */
          brpd_b_VpEnOvrTmLoPreDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_lj > rtb_t_delay_on_ii - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c4_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S137>/flg_out' */
          brpd_b_VpEnOvrTmLoPreDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_lj += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S137>/flg_out' incorporates:
           *  Constant: '<S101>/t_step16'
           */
          brpd_b_VpEnOvrTmLoPreDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S137>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_av) {
    /* Disable for SignalConversion generated from: '<S137>/flg_out' incorporates:
     *  Outport: '<S137>/flg_out'
     */
    brpd_b_VpEnOvrTmLoPreDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_av = false;
  }

  /* End of Logic: '<S101>/Logical Operator3' */
  /* End of Outputs for SubSystem: '<S108>/debounce' */

  /* CCaller: '<S122>/C Caller' incorporates:
   *  Constant: '<S101>/event_id14'
   *  DataTypeConversion: '<S101>/Data Type Conversion4'
   */
  Dem_SetEventStatus(((uint16)32917U), brpd_b_VpEnOvrTmLoPreDebd);

  /* Switch: '<S145>/Switch2' incorporates:
   *  Constant: '<S115>/brpc_b_BdcacOpTmLongFltSet_ovrdflg'
   */
  if (brpc_b_VacPumpSnrFltSet_ovrdflg) {
    /* Switch: '<S145>/Switch2' incorporates:
     *  Constant: '<S115>/brpc_b_BdcacOpTmLongFltSet_ovrdval'
     */
    brpd_b_VacPumpSnrFltSet = brpc_b_VacPumpSnrFltSet_ovrdval;
  } else {
    /* Switch: '<S145>/Switch2' */
    brpd_b_VacPumpSnrFltSet = swc_DIAG_ARID_DEF.DataTypeConversion25;
  }

  /* End of Switch: '<S145>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S105>/debounce' incorporates:
   *  EnablePort: '<S131>/Enable'
   */
  /* Logic: '<S101>/Logical Operator4' */
  if (rtb_LogicalOperator9 && rtb_LogicalOperator106 &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_gv) {
      /* SystemReset for Chart: '<S131>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c5_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_f;
      swc_DIAG_ARID_DEF.t_wait_aj = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_gv = true;
    }

    /* Saturate: '<S131>/Saturation' incorporates:
     *  Constant: '<S101>/t_delay_fail12'
     */
    if (0.5F > 1.6777216E+7F) {
      /* Saturate: '<S131>/Saturation' */
      rtb_t_delay_on_ii = 1.6777216E+7F;
    } else if (0.5F < 0.0F) {
      /* Saturate: '<S131>/Saturation' */
      rtb_t_delay_on_ii = 0.0F;
    } else {
      /* Saturate: '<S131>/Saturation' */
      rtb_t_delay_on_ii = 0.5F;
    }

    /* End of Saturate: '<S131>/Saturation' */

    /* Saturate: '<S131>/Saturation1' incorporates:
     *  Constant: '<S101>/t_delay_heal11'
     */
    if (0.0F > 1.6777216E+7F) {
      /* Saturate: '<S131>/Saturation1' */
      rtb_t_delay_off_dr = 1.6777216E+7F;
    } else {
      /* Saturate: '<S131>/Saturation1' */
      rtb_t_delay_off_dr = 0.0F;
    }

    /* End of Saturate: '<S131>/Saturation1' */

    /* Chart: '<S131>/timed_debounce' incorporates:
     *  Constant: '<S101>/t_step13'
     *  DataTypeConversion: '<S131>/Data Type Conversion'
     *  UnitDelay: '<S105>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c5_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c5_swc_DIAG = 1U;
      if ((!brpd_b_VacPumpSnrFltSet) && (rtb_t_delay_off_dr == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_OFF_j;

        /* SignalConversion generated from: '<S131>/flg_out' */
        brpd_b_VacPumpSnrFltDebd = false;
      } else if (brpd_b_VacPumpSnrFltSet && (rtb_t_delay_on_ii == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_ON_ju;

        /* SignalConversion generated from: '<S131>/flg_out' */
        brpd_b_VacPumpSnrFltDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_fr) {
        swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
        swc_DIAG_ARID_DEF.t_wait_aj = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_aj += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S131>/flg_out' incorporates:
         *  Constant: '<S101>/t_step13'
         */
        brpd_b_VacPumpSnrFltDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
        swc_DIAG_ARID_DEF.t_wait_aj = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_aj += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S131>/flg_out' incorporates:
         *  Constant: '<S101>/t_step13'
         */
        brpd_b_VacPumpSnrFltDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c5_swc_DIAG) {
       case swc_DIAG_IN_OFF_j:
        if (brpd_b_VacPumpSnrFltSet) {
          if (rtb_t_delay_on_ii == 0.0F) {
            swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_ON_ju;

            /* SignalConversion generated from: '<S131>/flg_out' */
            brpd_b_VacPumpSnrFltDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
            swc_DIAG_ARID_DEF.t_wait_aj = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_aj += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S131>/flg_out' incorporates:
             *  Constant: '<S101>/t_step13'
             */
            brpd_b_VacPumpSnrFltDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S131>/flg_out' */
          brpd_b_VacPumpSnrFltDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_d:
        if (brpd_b_VacPumpSnrFltSet) {
          swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S131>/flg_out' */
          brpd_b_VacPumpSnrFltDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_aj > rtb_t_delay_off_dr - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S131>/flg_out' */
          brpd_b_VacPumpSnrFltDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_aj += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S131>/flg_out' incorporates:
           *  Constant: '<S101>/t_step13'
           */
          brpd_b_VacPumpSnrFltDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_ju:
        if (!brpd_b_VacPumpSnrFltSet) {
          if (rtb_t_delay_off_dr == 0.0F) {
            swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_OFF_j;

            /* SignalConversion generated from: '<S131>/flg_out' */
            brpd_b_VacPumpSnrFltDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
            swc_DIAG_ARID_DEF.t_wait_aj = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_aj += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S131>/flg_out' incorporates:
             *  Constant: '<S101>/t_step13'
             */
            brpd_b_VacPumpSnrFltDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S131>/flg_out' */
          brpd_b_VacPumpSnrFltDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!brpd_b_VacPumpSnrFltSet) {
          swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S131>/flg_out' */
          brpd_b_VacPumpSnrFltDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_aj > rtb_t_delay_on_ii - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c5_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S131>/flg_out' */
          brpd_b_VacPumpSnrFltDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_aj += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S131>/flg_out' incorporates:
           *  Constant: '<S101>/t_step13'
           */
          brpd_b_VacPumpSnrFltDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S131>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_gv) {
    /* Disable for SignalConversion generated from: '<S131>/flg_out' incorporates:
     *  Outport: '<S131>/flg_out'
     */
    brpd_b_VacPumpSnrFltDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_gv = false;
  }

  /* End of Logic: '<S101>/Logical Operator4' */
  /* End of Outputs for SubSystem: '<S105>/debounce' */

  /* CCaller: '<S123>/C Caller' incorporates:
   *  Constant: '<S101>/event_id11'
   *  DataTypeConversion: '<S101>/Data Type Conversion5'
   */
  Dem_SetEventStatus(((uint16)32918U), brpd_b_VacPumpSnrFltDebd);

  /* Switch: '<S146>/Switch2' incorporates:
   *  Constant: '<S116>/brpc_b_BdcacOpTmLongFltSet_ovrdflg'
   */
  if (brpc_b_VacPumpSysFailFltSet_ovrdflg) {
    /* Switch: '<S146>/Switch2' incorporates:
     *  Constant: '<S116>/brpc_b_BdcacOpTmLongFltSet_ovrdval'
     */
    brpd_b_VacPumpSysFailSet = brpc_b_VacPumpSysFailFltSet_ovrdval;
  } else {
    /* Switch: '<S146>/Switch2' */
    brpd_b_VacPumpSysFailSet = swc_DIAG_ARID_DEF.DataTypeConversion30;
  }

  /* End of Switch: '<S146>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S106>/debounce' incorporates:
   *  EnablePort: '<S133>/Enable'
   */
  /* Logic: '<S101>/Logical Operator5' */
  if (rtb_LogicalOperator9 && rtb_LogicalOperator106 &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_pt) {
      /* SystemReset for Chart: '<S133>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c6_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_f;
      swc_DIAG_ARID_DEF.t_wait_iq = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_pt = true;
    }

    /* Saturate: '<S133>/Saturation' incorporates:
     *  Constant: '<S101>/t_delay_fail16'
     */
    if (5.0F > 1.6777216E+7F) {
      /* Saturate: '<S133>/Saturation' */
      rtb_t_delay_on_ii = 1.6777216E+7F;
    } else if (5.0F < 0.0F) {
      /* Saturate: '<S133>/Saturation' */
      rtb_t_delay_on_ii = 0.0F;
    } else {
      /* Saturate: '<S133>/Saturation' */
      rtb_t_delay_on_ii = 5.0F;
    }

    /* End of Saturate: '<S133>/Saturation' */

    /* Saturate: '<S133>/Saturation1' incorporates:
     *  Constant: '<S101>/t_delay_heal15'
     */
    if (2.0F > 1.6777216E+7F) {
      /* Saturate: '<S133>/Saturation1' */
      rtb_t_delay_off_dr = 1.6777216E+7F;
    } else if (2.0F < 0.0F) {
      /* Saturate: '<S133>/Saturation1' */
      rtb_t_delay_off_dr = 0.0F;
    } else {
      /* Saturate: '<S133>/Saturation1' */
      rtb_t_delay_off_dr = 2.0F;
    }

    /* End of Saturate: '<S133>/Saturation1' */

    /* Chart: '<S133>/timed_debounce' incorporates:
     *  Constant: '<S101>/t_step17'
     *  DataTypeConversion: '<S133>/Data Type Conversion'
     *  UnitDelay: '<S106>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c6_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c6_swc_DIAG = 1U;
      if ((!brpd_b_VacPumpSysFailSet) && (rtb_t_delay_off_dr == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_OFF_j;

        /* SignalConversion generated from: '<S133>/flg_out' */
        brpd_b_VacPumpSysFailDebd = false;
      } else if (brpd_b_VacPumpSysFailSet && (rtb_t_delay_on_ii == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_ON_ju;

        /* SignalConversion generated from: '<S133>/flg_out' */
        brpd_b_VacPumpSysFailDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_eo) {
        swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
        swc_DIAG_ARID_DEF.t_wait_iq = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_iq += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S133>/flg_out' incorporates:
         *  Constant: '<S101>/t_step17'
         */
        brpd_b_VacPumpSysFailDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
        swc_DIAG_ARID_DEF.t_wait_iq = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_iq += ((float32)BRP_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S133>/flg_out' incorporates:
         *  Constant: '<S101>/t_step17'
         */
        brpd_b_VacPumpSysFailDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c6_swc_DIAG) {
       case swc_DIAG_IN_OFF_j:
        if (brpd_b_VacPumpSysFailSet) {
          if (rtb_t_delay_on_ii == 0.0F) {
            swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_ON_ju;

            /* SignalConversion generated from: '<S133>/flg_out' */
            brpd_b_VacPumpSysFailDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_ON_WAIT_m;
            swc_DIAG_ARID_DEF.t_wait_iq = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_iq += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S133>/flg_out' incorporates:
             *  Constant: '<S101>/t_step17'
             */
            brpd_b_VacPumpSysFailDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S133>/flg_out' */
          brpd_b_VacPumpSysFailDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_d:
        if (brpd_b_VacPumpSysFailSet) {
          swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S133>/flg_out' */
          brpd_b_VacPumpSysFailDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_iq > rtb_t_delay_off_dr - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S133>/flg_out' */
          brpd_b_VacPumpSysFailDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_iq += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S133>/flg_out' incorporates:
           *  Constant: '<S101>/t_step17'
           */
          brpd_b_VacPumpSysFailDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_ju:
        if (!brpd_b_VacPumpSysFailSet) {
          if (rtb_t_delay_off_dr == 0.0F) {
            swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_OFF_j;

            /* SignalConversion generated from: '<S133>/flg_out' */
            brpd_b_VacPumpSysFailDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_OFF_WAIT_d;
            swc_DIAG_ARID_DEF.t_wait_iq = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_iq += ((float32)BRP_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S133>/flg_out' incorporates:
             *  Constant: '<S101>/t_step17'
             */
            brpd_b_VacPumpSysFailDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S133>/flg_out' */
          brpd_b_VacPumpSysFailDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!brpd_b_VacPumpSysFailSet) {
          swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_OFF_j;

          /* SignalConversion generated from: '<S133>/flg_out' */
          brpd_b_VacPumpSysFailDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_iq > rtb_t_delay_on_ii - ((float32)
                    BRP_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c6_swc_DIAG = swc_DIAG_IN_ON_ju;

          /* SignalConversion generated from: '<S133>/flg_out' */
          brpd_b_VacPumpSysFailDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_iq += ((float32)BRP_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S133>/flg_out' incorporates:
           *  Constant: '<S101>/t_step17'
           */
          brpd_b_VacPumpSysFailDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S133>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_pt) {
    /* Disable for SignalConversion generated from: '<S133>/flg_out' incorporates:
     *  Outport: '<S133>/flg_out'
     */
    brpd_b_VacPumpSysFailDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_pt = false;
  }

  /* End of Logic: '<S101>/Logical Operator5' */
  /* End of Outputs for SubSystem: '<S106>/debounce' */

  /* CCaller: '<S124>/C Caller' incorporates:
   *  Constant: '<S101>/event_id2'
   *  DataTypeConversion: '<S101>/Data Type Conversion6'
   */
  Dem_SetEventStatus(((uint16)32983U), brpd_b_VacPumpSysFailDebd);

  /* Logic: '<S101>/Logical Operator36' */
  digd_b_vcuVehLvl22Flt_flg_BRP = (rtb_SignalConversion1 ||
    brpd_b_VacPumpRlyFltDebd || brpd_b_VacPumpLoPreDebd ||
    brpd_b_VpEnOvrTmLoPreDebd || brpd_b_VacPumpSnrFltDebd ||
    brpd_b_VacPumpSysFailDebd);

  /* SignalConversion: '<S101>/Signal Conversion' */
  brpd_b_brkSwtMismatch = swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq;

  /* CCaller: '<S117>/C Caller1' */
  mBSW_NvmWrite_BrkSwtFltCnt(brpd_d_BrkSigErrCn);

  /* Update for Delay: '<S117>/Delay1' incorporates:
   *  Constant: '<S117>/Constant1'
   */
  swc_DIAG_ARID_DEF.Delay1_DSTATE = ((uint8)0U);

  /* Update for UnitDelay: '<S157>/Delay Input1'
   *
   * Block description for '<S157>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_DIAG_ARID_DEF.DelayInput1_DSTATE_p = rtb_flg_out_m4;

  /* Update for UnitDelay: '<S158>/Delay Input1'
   *
   * Block description for '<S158>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_DIAG_ARID_DEF.DelayInput1_DSTATE = rtb_FltCounter;

  /* Update for UnitDelay: '<S155>/Delay Input1'
   *
   * Block description for '<S155>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_DIAG_ARID_DEF.DelayInput1_DSTATE_a = brpd_b_brakeStateOpen_flg;

  /* Update for UnitDelay: '<S156>/Delay Input1'
   *
   * Block description for '<S156>/Delay Input1':
   *
   *  Store in Global RAM
   */
  swc_DIAG_ARID_DEF.DelayInput1_DSTATE_c = brpd_b_brakeStateOff_flg;

  /* Update for Delay: '<S117>/Delay' */
  swc_DIAG_ARID_DEF.Delay_DSTATE = brpd_d_BrkSigErrCn;

  /* Update for UnitDelay: '<S102>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_pd =
    swc_DIAG_ARID_DEF.OutportBufferForflg_ou_hsohtgiq;

  /* Update for UnitDelay: '<S104>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_h1 = brpd_b_VacPumpRlyFltDebd;

  /* Update for UnitDelay: '<S103>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_lc = brpd_b_VacPumpLoPreDebd;

  /* Update for UnitDelay: '<S107>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_dh = brpd_b_VpEnOvTmHiPreDebd;

  /* Update for UnitDelay: '<S108>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_i0 = brpd_b_VpEnOvrTmLoPreDebd;

  /* Update for UnitDelay: '<S105>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_fr = brpd_b_VacPumpSnrFltDebd;

  /* Update for UnitDelay: '<S106>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_eo = brpd_b_VacPumpSysFailDebd;
}

/* Output and update for function-call system: '<S1>/CES_Diag' */
static void swc_DIAG_CES_Diag(void)
{
  uint8 rtb_CCaller4;

  /* CCaller: '<S4>/C Caller4' */
  rtb_CCaller4 = 0U;

  /* CCaller: '<S4>/C Caller4' incorporates:
   *  Constant: '<S4>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32914U), &rtb_CCaller4);

  /* Switch: '<S173>/Switch2' incorporates:
   *  Constant: '<S4>/DFC_ovrdflg'
   */
  if (digc_b_evtFaildCrashEvent_ovrdflg) {
    /* SignalConversion: '<S4>/Signal Conversion' incorporates:
     *  Constant: '<S4>/DFC_ovrdval'
     *  Switch: '<S173>/Switch2'
     */
    digd_b_vcuVehLvl33Flt_flg_CES = digc_b_evtFaildCrashEvent_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S4>/Bitwise And1' */
    rtb_CCaller4 &= ((uint8)8U);

    /* SignalConversion: '<S4>/Signal Conversion' incorporates:
     *  DataTypeConversion: '<S4>/con_3'
     *  Switch: '<S173>/Switch2'
     */
    digd_b_vcuVehLvl33Flt_flg_CES = (rtb_CCaller4 != 0);
  }

  /* End of Switch: '<S173>/Switch2' */

  /* Switch: '<S178>/Switch2' incorporates:
   *  Constant: '<S172>/cesc_b_crashEventSet_ovrdflg'
   */
  if (cesc_b_crashEventSet_ovrdflg) {
    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S172>/cesc_b_crashEventSet_ovrdval'
     */
    cesd_b_crashEventSet = cesc_b_crashEventSet_ovrdval;
  } else {
    /* Switch: '<S178>/Switch2' */
    cesd_b_crashEventSet = swc_DIAG_ARID_DEF.DataTypeConversion22;
  }

  /* End of Switch: '<S178>/Switch2' */

  /* Switch: '<S177>/Switch2' incorporates:
   *  Constant: '<S171>/cesc_b_crashEventEnb_ovrdflg'
   */
  if (cesc_b_crashEventEnb_ovrdflg) {
    /* Switch: '<S177>/Switch2' incorporates:
     *  Constant: '<S171>/cesc_b_crashEventEnb_ovrdval'
     */
    cesd_b_crashEventEnb = cesc_b_crashEventEnb_ovrdval;
  } else {
    /* Switch: '<S177>/Switch2' incorporates:
     *  Logic: '<S4>/Logical Operator'
     */
    cesd_b_crashEventEnb = (swc_DIAG_ARID_DEF.DataTypeConversion254 ||
      swc_DIAG_ARID_DEF.DataTypeConversion123);
  }

  /* End of Switch: '<S177>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S170>/debounce' incorporates:
   *  EnablePort: '<S175>/Enable'
   */
  if (cesd_b_crashEventEnb) {
    float32 rtb_t_delay_off_am;
    float32 rtb_t_delay_on_d;
    if (!swc_DIAG_ARID_DEF.debounce_MODE_ih) {
      /* SystemReset for Chart: '<S175>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c22_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_p;
      swc_DIAG_ARID_DEF.t_wait_ml = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_ih = true;
    }

    /* Saturate: '<S175>/Saturation' incorporates:
     *  Constant: '<S4>/t_delay_fail'
     */
    if (digc_b_crashEventFail_s > 1.6777216E+7F) {
      /* Saturate: '<S175>/Saturation' */
      rtb_t_delay_on_d = 1.6777216E+7F;
    } else if (digc_b_crashEventFail_s < 0.0F) {
      /* Saturate: '<S175>/Saturation' */
      rtb_t_delay_on_d = 0.0F;
    } else {
      /* Saturate: '<S175>/Saturation' */
      rtb_t_delay_on_d = digc_b_crashEventFail_s;
    }

    /* End of Saturate: '<S175>/Saturation' */

    /* Saturate: '<S175>/Saturation1' incorporates:
     *  Constant: '<S4>/t_delay_heal'
     */
    if (digc_b_crashEventHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S175>/Saturation1' */
      rtb_t_delay_off_am = 1.6777216E+7F;
    } else if (digc_b_crashEventHeal_s < 0.0F) {
      /* Saturate: '<S175>/Saturation1' */
      rtb_t_delay_off_am = 0.0F;
    } else {
      /* Saturate: '<S175>/Saturation1' */
      rtb_t_delay_off_am = digc_b_crashEventHeal_s;
    }

    /* End of Saturate: '<S175>/Saturation1' */

    /* Chart: '<S175>/timed_debounce' incorporates:
     *  Constant: '<S4>/t_step'
     *  DataTypeConversion: '<S175>/Data Type Conversion'
     *  UnitDelay: '<S170>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c22_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c22_swc_DIAG = 1U;
      if ((!cesd_b_crashEventSet) && (rtb_t_delay_off_am == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_OFF_nb;

        /* SignalConversion generated from: '<S175>/flg_out' */
        cesd_b_crashEventDebd = false;
      } else if (cesd_b_crashEventSet && (rtb_t_delay_on_d == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_ON_av;

        /* SignalConversion generated from: '<S175>/flg_out' */
        cesd_b_crashEventDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_o5) {
        swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_OFF_WAIT_l;
        swc_DIAG_ARID_DEF.t_wait_ml = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ml += ((float32)CES_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S175>/flg_out' incorporates:
         *  Constant: '<S4>/t_step'
         */
        cesd_b_crashEventDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_ON_WAIT_mt;
        swc_DIAG_ARID_DEF.t_wait_ml = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ml += ((float32)CES_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S175>/flg_out' incorporates:
         *  Constant: '<S4>/t_step'
         */
        cesd_b_crashEventDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c22_swc_DIAG) {
       case swc_DIAG_IN_OFF_nb:
        if (cesd_b_crashEventSet) {
          if (rtb_t_delay_on_d == 0.0F) {
            swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_ON_av;

            /* SignalConversion generated from: '<S175>/flg_out' */
            cesd_b_crashEventDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_ON_WAIT_mt;
            swc_DIAG_ARID_DEF.t_wait_ml = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ml += ((float32)CES_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S175>/flg_out' incorporates:
             *  Constant: '<S4>/t_step'
             */
            cesd_b_crashEventDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S175>/flg_out' */
          cesd_b_crashEventDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_l:
        if (cesd_b_crashEventSet) {
          swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_ON_av;

          /* SignalConversion generated from: '<S175>/flg_out' */
          cesd_b_crashEventDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_ml > rtb_t_delay_off_am - ((float32)
                    CES_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_OFF_nb;

          /* SignalConversion generated from: '<S175>/flg_out' */
          cesd_b_crashEventDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ml += ((float32)CES_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S175>/flg_out' incorporates:
           *  Constant: '<S4>/t_step'
           */
          cesd_b_crashEventDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_av:
        if (!cesd_b_crashEventSet) {
          if (rtb_t_delay_off_am == 0.0F) {
            swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_OFF_nb;

            /* SignalConversion generated from: '<S175>/flg_out' */
            cesd_b_crashEventDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_OFF_WAIT_l;
            swc_DIAG_ARID_DEF.t_wait_ml = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ml += ((float32)CES_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S175>/flg_out' incorporates:
             *  Constant: '<S4>/t_step'
             */
            cesd_b_crashEventDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S175>/flg_out' */
          cesd_b_crashEventDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!cesd_b_crashEventSet) {
          swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_OFF_nb;

          /* SignalConversion generated from: '<S175>/flg_out' */
          cesd_b_crashEventDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_ml > rtb_t_delay_on_d - ((float32)
                    CES_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c22_swc_DIAG = swc_DIAG_IN_ON_av;

          /* SignalConversion generated from: '<S175>/flg_out' */
          cesd_b_crashEventDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ml += ((float32)CES_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S175>/flg_out' incorporates:
           *  Constant: '<S4>/t_step'
           */
          cesd_b_crashEventDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S175>/timed_debounce' */
  } else {
    swc_DIAG_ARID_DEF.debounce_MODE_ih = false;
  }

  /* End of Outputs for SubSystem: '<S170>/debounce' */

  /* Outputs for Triggered SubSystem: '<S170>/Subsystem' incorporates:
   *  TriggerPort: '<S174>/Trigger'
   */
  if (cesd_b_crashEventDebd && (swc_DIAG_ARID_DEF.Subsystem_Trig_ZCE !=
       POS_ZCSIG)) {
    /* CCaller: '<S174>/C Caller' incorporates:
     *  Constant: '<S4>/event_id'
     *  DataTypeConversion: '<S170>/Data Type Conversion'
     */
    Dem_SetEventStatus(((uint16)32914U), cesd_b_crashEventDebd);
  }

  swc_DIAG_ARID_DEF.Subsystem_Trig_ZCE = cesd_b_crashEventDebd;

  /* End of Outputs for SubSystem: '<S170>/Subsystem' */

  /* Update for UnitDelay: '<S170>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_o5 = cesd_b_crashEventDebd;
}

/* Output and update for atomic system: '<S5>/SR_latch1' */
static void swc_DIAG_SR_latch1(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch1_swc_DIAG_T *swc_DIAG__ARID_DEF_arg)
{
  /* Logic: '<S186>/Logical Operator3' incorporates:
   *  Logic: '<S186>/Logical Operator'
   *  Logic: '<S186>/Logical Operator1'
   *  UnitDelay: '<S186>/Unit Delay'
   */
  digd_b_vcuVehLvl31Flt_flg_EAD = ((swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S186>/Unit Delay' */
  swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE = digd_b_vcuVehLvl31Flt_flg_EAD;
}

/* Output and update for function-call system: '<S1>/EAD_DiagMot2' */
static void swc_DIAG_EAD_DiagMot2(void)
{
  /* local block i/o variables */
  boolean rtb_OR1;
  float32 rtb_t_delay_off_cc;
  float32 rtb_t_delay_on_o1;
  boolean rtb_LogicalOperator13_k;
  boolean rtb_LogicalOperator14_l;

  /* Switch: '<S196>/Switch2' incorporates:
   *  Constant: '<S185>/hvbc_b_vehHvilFltSet_ovrdflg'
   */
  if (hvbc_b_MCUFaultLevel3ASet_ovrdflg) {
    /* Switch: '<S196>/Switch2' incorporates:
     *  Constant: '<S185>/hvbc_b_vehHvilFltSet_ovrdval'
     */
    hvbd_b_MCUFaultLevel3ASet = hvbc_b_MCUFaultLevel3ASet_ovrdval;
  } else {
    /* Switch: '<S196>/Switch2' incorporates:
     *  Constant: '<S182>/Constant'
     *  DataTypeConversion: '<Root>/Data Type Conversion183'
     *  RelationalOperator: '<S5>/Relational Operator2'
     */
    hvbd_b_MCUFaultLevel3ASet = (swc_DIAG_ARID_DEF.DataTypeConversion183 ==
      FaultStatus_LEVEL_3);
  }

  /* End of Switch: '<S196>/Switch2' */

  /* Logic: '<S5>/Logical Operator13' */
  rtb_LogicalOperator13_k = !macb_b_P2AD4;

  /* Logic: '<S5>/Logical Operator14' */
  rtb_LogicalOperator14_l = !macb_b_P2AD5;

  /* Outputs for Enabled SubSystem: '<S180>/debounce' incorporates:
   *  EnablePort: '<S191>/Enable'
   */
  /* Logic: '<S5>/Logical Operator3' */
  if (rtb_LogicalOperator13_k && rtb_LogicalOperator14_l &&
      swc_DIAG_ARID_DEF.LogicalOperator &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_b0) {
      /* SystemReset for Chart: '<S191>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c28_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_k;
      swc_DIAG_ARID_DEF.t_wait_il = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_b0 = true;
    }

    /* Saturate: '<S191>/Saturation' incorporates:
     *  Constant: '<S5>/t_delay_fail3'
     */
    if (0.5F > 1.6777216E+7F) {
      /* Saturate: '<S191>/Saturation' */
      rtb_t_delay_on_o1 = 1.6777216E+7F;
    } else if (0.5F < 0.0F) {
      /* Saturate: '<S191>/Saturation' */
      rtb_t_delay_on_o1 = 0.0F;
    } else {
      /* Saturate: '<S191>/Saturation' */
      rtb_t_delay_on_o1 = 0.5F;
    }

    /* End of Saturate: '<S191>/Saturation' */

    /* Saturate: '<S191>/Saturation1' incorporates:
     *  Constant: '<S5>/t_delay_fail4'
     */
    if (0.25F > 1.6777216E+7F) {
      /* Saturate: '<S191>/Saturation1' */
      rtb_t_delay_off_cc = 1.6777216E+7F;
    } else if (0.25F < 0.0F) {
      /* Saturate: '<S191>/Saturation1' */
      rtb_t_delay_off_cc = 0.0F;
    } else {
      /* Saturate: '<S191>/Saturation1' */
      rtb_t_delay_off_cc = 0.25F;
    }

    /* End of Saturate: '<S191>/Saturation1' */

    /* Chart: '<S191>/timed_debounce' incorporates:
     *  Constant: '<S5>/t_step2'
     *  DataTypeConversion: '<S191>/Data Type Conversion'
     *  UnitDelay: '<S180>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c28_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c28_swc_DIAG = 1U;
      if ((!hvbd_b_MCUFaultLevel3ASet) && (rtb_t_delay_off_cc == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_OFF_m;

        /* SignalConversion generated from: '<S191>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
      } else if (hvbd_b_MCUFaultLevel3ASet && (rtb_t_delay_on_o1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_ON_h;

        /* SignalConversion generated from: '<S191>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_j) {
        swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ow;
        swc_DIAG_ARID_DEF.t_wait_il = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_il += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S191>/flg_out' incorporates:
         *  Constant: '<S5>/t_step2'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = true;
      } else {
        swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_ON_WAIT_h;
        swc_DIAG_ARID_DEF.t_wait_il = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_il += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S191>/flg_out' incorporates:
         *  Constant: '<S5>/t_step2'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c28_swc_DIAG) {
       case swc_DIAG_IN_OFF_m:
        if (hvbd_b_MCUFaultLevel3ASet) {
          if (rtb_t_delay_on_o1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_ON_h;

            /* SignalConversion generated from: '<S191>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = true;
          } else {
            swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_ON_WAIT_h;
            swc_DIAG_ARID_DEF.t_wait_il = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_il += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S191>/flg_out' incorporates:
             *  Constant: '<S5>/t_step2'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
          }
        } else {
          /* SignalConversion generated from: '<S191>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ow:
        if (hvbd_b_MCUFaultLevel3ASet) {
          swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_ON_h;

          /* SignalConversion generated from: '<S191>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_il > rtb_t_delay_off_cc - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_OFF_m;

          /* SignalConversion generated from: '<S191>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_il += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S191>/flg_out' incorporates:
           *  Constant: '<S5>/t_step2'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = true;
        }
        break;

       case swc_DIAG_IN_ON_h:
        if (!hvbd_b_MCUFaultLevel3ASet) {
          if (rtb_t_delay_off_cc == 0.0F) {
            swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_OFF_m;

            /* SignalConversion generated from: '<S191>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
          } else {
            swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ow;
            swc_DIAG_ARID_DEF.t_wait_il = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_il += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S191>/flg_out' incorporates:
             *  Constant: '<S5>/t_step2'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = true;
          }
        } else {
          /* SignalConversion generated from: '<S191>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!hvbd_b_MCUFaultLevel3ASet) {
          swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_OFF_m;

          /* SignalConversion generated from: '<S191>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_il > rtb_t_delay_on_o1 - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c28_swc_DIAG = swc_DIAG_IN_ON_h;

          /* SignalConversion generated from: '<S191>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_il += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S191>/flg_out' incorporates:
           *  Constant: '<S5>/t_step2'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
        }
        break;
      }
    }

    /* End of Chart: '<S191>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_b0) {
    /* Disable for SignalConversion generated from: '<S191>/flg_out' incorporates:
     *  Outport: '<S191>/flg_out'
     */
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi = false;
    swc_DIAG_ARID_DEF.debounce_MODE_b0 = false;
  }

  /* End of Logic: '<S5>/Logical Operator3' */
  /* End of Outputs for SubSystem: '<S180>/debounce' */

  /* Logic: '<S183>/OR1' incorporates:
   *  Constant: '<S193>/Constant'
   *  Constant: '<S194>/Constant'
   *  Inport generated from: '<Root>/vild_b_flgClearDTC'
   *  RelationalOperator: '<S193>/Compare'
   *  RelationalOperator: '<S194>/Compare'
   */
  rtb_OR1 = ((swc_DIAG_ARID_DEF.DataTypeConversion254 == false) ||
             (Rte_IRead_swc_DIAG_Step_vild_b_flgClearDTC_vild_b_flgClearDTC() ==
              true));

  /* Outputs for Atomic SubSystem: '<S5>/SR_latch1' */
  swc_DIAG_SR_latch1(swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi, rtb_OR1,
                     &swc_DIAG_ARID_DEF.ARID_DEF_SR_latch1_c);

  /* End of Outputs for SubSystem: '<S5>/SR_latch1' */

  /* CCaller: '<S187>/C Caller' incorporates:
   *  Constant: '<S5>/event_id2'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32956U), digd_b_vcuVehLvl31Flt_flg_EAD);

  /* Switch: '<S195>/Switch2' incorporates:
   *  Constant: '<S184>/hvbc_b_vehHvilFltSet_ovrdflg'
   */
  if (hvbc_b_MCUFaultLevel2ASet_ovrdflg) {
    /* Switch: '<S195>/Switch2' incorporates:
     *  Constant: '<S184>/hvbc_b_vehHvilFltSet_ovrdval'
     */
    hvbd_b_MCUFaultLevel2ASet = hvbc_b_MCUFaultLevel2ASet_ovrdval;
  } else {
    /* Switch: '<S195>/Switch2' incorporates:
     *  Constant: '<S181>/Constant'
     *  DataTypeConversion: '<Root>/Data Type Conversion183'
     *  RelationalOperator: '<S5>/Relational Operator1'
     */
    hvbd_b_MCUFaultLevel2ASet = (swc_DIAG_ARID_DEF.DataTypeConversion183 ==
      FaultStatus_LEVEL_2);
  }

  /* End of Switch: '<S195>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S179>/debounce' incorporates:
   *  EnablePort: '<S189>/Enable'
   */
  /* Logic: '<S5>/Logical Operator10' */
  if (rtb_LogicalOperator13_k && rtb_LogicalOperator14_l &&
      swc_DIAG_ARID_DEF.LogicalOperator &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_b5) {
      /* SystemReset for Chart: '<S189>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c27_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_k;
      swc_DIAG_ARID_DEF.t_wait_iu = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_b5 = true;
    }

    /* Saturate: '<S189>/Saturation' incorporates:
     *  Constant: '<S5>/t_delay_fail1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S189>/Saturation' */
      rtb_t_delay_on_o1 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S189>/Saturation' */
      rtb_t_delay_on_o1 = 0.0F;
    } else {
      /* Saturate: '<S189>/Saturation' */
      rtb_t_delay_on_o1 = 1.0F;
    }

    /* End of Saturate: '<S189>/Saturation' */

    /* Saturate: '<S189>/Saturation1' incorporates:
     *  Constant: '<S5>/t_delay_fail2'
     */
    if (0.25F > 1.6777216E+7F) {
      /* Saturate: '<S189>/Saturation1' */
      rtb_t_delay_off_cc = 1.6777216E+7F;
    } else if (0.25F < 0.0F) {
      /* Saturate: '<S189>/Saturation1' */
      rtb_t_delay_off_cc = 0.0F;
    } else {
      /* Saturate: '<S189>/Saturation1' */
      rtb_t_delay_off_cc = 0.25F;
    }

    /* End of Saturate: '<S189>/Saturation1' */

    /* Chart: '<S189>/timed_debounce' incorporates:
     *  Constant: '<S5>/t_step1'
     *  DataTypeConversion: '<S189>/Data Type Conversion'
     *  UnitDelay: '<S179>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c27_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c27_swc_DIAG = 1U;
      if ((!hvbd_b_MCUFaultLevel2ASet) && (rtb_t_delay_off_cc == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_OFF_m;

        /* SignalConversion generated from: '<S189>/flg_out' */
        digd_b_vcuVehLvl21Flt_flg_EAD = false;
      } else if (hvbd_b_MCUFaultLevel2ASet && (rtb_t_delay_on_o1 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_ON_h;

        /* SignalConversion generated from: '<S189>/flg_out' */
        digd_b_vcuVehLvl21Flt_flg_EAD = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_ms) {
        swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ow;
        swc_DIAG_ARID_DEF.t_wait_iu = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_iu += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S189>/flg_out' incorporates:
         *  Constant: '<S5>/t_step1'
         */
        digd_b_vcuVehLvl21Flt_flg_EAD = true;
      } else {
        swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_ON_WAIT_h;
        swc_DIAG_ARID_DEF.t_wait_iu = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_iu += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S189>/flg_out' incorporates:
         *  Constant: '<S5>/t_step1'
         */
        digd_b_vcuVehLvl21Flt_flg_EAD = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c27_swc_DIAG) {
       case swc_DIAG_IN_OFF_m:
        if (hvbd_b_MCUFaultLevel2ASet) {
          if (rtb_t_delay_on_o1 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_ON_h;

            /* SignalConversion generated from: '<S189>/flg_out' */
            digd_b_vcuVehLvl21Flt_flg_EAD = true;
          } else {
            swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_ON_WAIT_h;
            swc_DIAG_ARID_DEF.t_wait_iu = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_iu += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S189>/flg_out' incorporates:
             *  Constant: '<S5>/t_step1'
             */
            digd_b_vcuVehLvl21Flt_flg_EAD = false;
          }
        } else {
          /* SignalConversion generated from: '<S189>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_EAD = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ow:
        if (hvbd_b_MCUFaultLevel2ASet) {
          swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_ON_h;

          /* SignalConversion generated from: '<S189>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_EAD = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_iu > rtb_t_delay_off_cc - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_OFF_m;

          /* SignalConversion generated from: '<S189>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_EAD = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_iu += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S189>/flg_out' incorporates:
           *  Constant: '<S5>/t_step1'
           */
          digd_b_vcuVehLvl21Flt_flg_EAD = true;
        }
        break;

       case swc_DIAG_IN_ON_h:
        if (!hvbd_b_MCUFaultLevel2ASet) {
          if (rtb_t_delay_off_cc == 0.0F) {
            swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_OFF_m;

            /* SignalConversion generated from: '<S189>/flg_out' */
            digd_b_vcuVehLvl21Flt_flg_EAD = false;
          } else {
            swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ow;
            swc_DIAG_ARID_DEF.t_wait_iu = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_iu += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S189>/flg_out' incorporates:
             *  Constant: '<S5>/t_step1'
             */
            digd_b_vcuVehLvl21Flt_flg_EAD = true;
          }
        } else {
          /* SignalConversion generated from: '<S189>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_EAD = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!hvbd_b_MCUFaultLevel2ASet) {
          swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_OFF_m;

          /* SignalConversion generated from: '<S189>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_EAD = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_iu > rtb_t_delay_on_o1 - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c27_swc_DIAG = swc_DIAG_IN_ON_h;

          /* SignalConversion generated from: '<S189>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_EAD = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_iu += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S189>/flg_out' incorporates:
           *  Constant: '<S5>/t_step1'
           */
          digd_b_vcuVehLvl21Flt_flg_EAD = false;
        }
        break;
      }
    }

    /* End of Chart: '<S189>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_b5) {
    /* Disable for SignalConversion generated from: '<S189>/flg_out' incorporates:
     *  Outport: '<S189>/flg_out'
     */
    digd_b_vcuVehLvl21Flt_flg_EAD = false;
    swc_DIAG_ARID_DEF.debounce_MODE_b5 = false;
  }

  /* End of Logic: '<S5>/Logical Operator10' */
  /* End of Outputs for SubSystem: '<S179>/debounce' */

  /* CCaller: '<S188>/C Caller' incorporates:
   *  Constant: '<S5>/event_id1'
   *  DataTypeConversion: '<S5>/Data Type Conversion1'
   */
  Dem_SetEventStatus(((uint16)32955U), digd_b_vcuVehLvl21Flt_flg_EAD);

  /* Update for UnitDelay: '<S180>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_j =
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtgi;

  /* Update for UnitDelay: '<S179>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_ms = digd_b_vcuVehLvl21Flt_flg_EAD;
}

/*
 * System initialize for atomic system:
 *    '<S206>/turnON_delay'
 *    '<S364>/turnON_delay5'
 *    '<S365>/turnON_delay5'
 *    '<S366>/turnON_delay5'
 *    '<S367>/turnON_delay5'
 */
static void swc_DIAG_turnON_delay_Init(boolean *rty_flg_out)
{
  /* SystemInitialize for Chart: '<S224>/timed_delay' */
  *rty_flg_out = false;
}

/*
 * Output and update for atomic system:
 *    '<S206>/turnON_delay'
 *    '<S364>/turnON_delay5'
 *    '<S365>/turnON_delay5'
 *    '<S366>/turnON_delay5'
 *    '<S367>/turnON_delay5'
 */
static void swc_DIAG_turnON_delay(boolean rtu_flg_in, float32 rtu_t_delay_on,
  float32 rtu_t_step, boolean *rty_flg_out, ARID_DEF_turnON_delay_swc_DIA_T
  *swc_DIAG__ARID_DEF_arg)
{
  float32 rtb_t_delay_on_fq;

  /* Saturate: '<S224>/Saturation' */
  if (rtu_t_delay_on > 1.6777216E+7F) {
    /* Saturate: '<S224>/Saturation' */
    rtb_t_delay_on_fq = 1.6777216E+7F;
  } else if (rtu_t_delay_on < 0.0F) {
    /* Saturate: '<S224>/Saturation' */
    rtb_t_delay_on_fq = 0.0F;
  } else {
    /* Saturate: '<S224>/Saturation' */
    rtb_t_delay_on_fq = rtu_t_delay_on;
  }

  /* End of Saturate: '<S224>/Saturation' */

  /* Chart: '<S224>/timed_delay' incorporates:
   *  DataTypeConversion: '<S224>/Data Type Conversion'
   */
  if (swc_DIAG__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li == 0U) {
    swc_DIAG__ARID_DEF_arg->is_active_c14_Ricardo_SW_dev_li = 1U;
    if (rtu_flg_in) {
      swc_DIAG__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_DIAG_IN_ON_k;
      *rty_flg_out = true;
    } else {
      swc_DIAG__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_DIAG_IN_OFF_h;
      *rty_flg_out = false;
    }
  } else {
    switch (swc_DIAG__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib) {
     case swc_DIAG_IN_OFF_h:
      if (rtu_flg_in) {
        if (rtb_t_delay_on_fq == 0.0F) {
          swc_DIAG__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_DIAG_IN_ON_k;
          *rty_flg_out = true;
        } else {
          swc_DIAG__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib =
            swc_DIAG_IN_ON_WAIT_j;
          swc_DIAG__ARID_DEF_arg->t_wait = rtu_t_step;
          *rty_flg_out = false;
        }
      } else {
        *rty_flg_out = false;
      }
      break;

     case swc_DIAG_IN_ON_k:
      if (!rtu_flg_in) {
        swc_DIAG__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_DIAG_IN_OFF_h;
        *rty_flg_out = false;
      } else {
        *rty_flg_out = true;
      }
      break;

     default:
      /* case IN_ON_WAIT: */
      if (!rtu_flg_in) {
        swc_DIAG__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_DIAG_IN_OFF_h;
        *rty_flg_out = false;
      } else if (swc_DIAG__ARID_DEF_arg->t_wait > rtb_t_delay_on_fq - rtu_t_step)
      {
        swc_DIAG__ARID_DEF_arg->is_c14_Ricardo_SW_dev_lib = swc_DIAG_IN_ON_k;
        *rty_flg_out = true;
      } else {
        swc_DIAG__ARID_DEF_arg->t_wait += rtu_t_step;
        *rty_flg_out = false;
      }
      break;
    }
  }

  /* End of Chart: '<S224>/timed_delay' */
}

/* Output and update for atomic system: '<S7>/SR_latch1' */
static void swc_DIAG_SR_latch1_m(boolean rtu_flg_set, boolean rtu_flg_reset,
  ARID_DEF_SR_latch1_swc_DIAG_m_T *swc_DIAG__ARID_DEF_arg)
{
  /* Logic: '<S213>/Logical Operator3' incorporates:
   *  Logic: '<S213>/Logical Operator'
   *  Logic: '<S213>/Logical Operator1'
   *  UnitDelay: '<S213>/Unit Delay'
   */
  digd_b_vcuVehLvl32Flt_flg_HVB = ((swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE ||
    rtu_flg_set) && (!rtu_flg_reset));

  /* Update for UnitDelay: '<S213>/Unit Delay' */
  swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE = digd_b_vcuVehLvl32Flt_flg_HVB;
}

/* System initialize for function-call system: '<S1>/HVB_Diag' */
static void swc_DIAG_HVB_Diag_Init(void)
{
  /* local block i/o variables */
  boolean rtb_flg_out_eo;

  /* SystemInitialize for SignalConversion: '<S7>/Signal Conversion' */
  digd_b_vcuVehLvl1Flt_flg_HVB = swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh;

  /* SystemInitialize for Atomic SubSystem: '<S206>/turnON_delay' */
  swc_DIAG_turnON_delay_Init(&rtb_flg_out_eo);

  /* End of SystemInitialize for SubSystem: '<S206>/turnON_delay' */
}

/* Output and update for function-call system: '<S1>/HVB_Diag' */
static void swc_DIAG_HVB_Diag(void)
{
  /* local block i/o variables */
  boolean rtb_OR1_k;
  boolean rtb_LogicalOperator12_a;
  boolean rtb_flg_out_eo;
  float32 rtb_t_delay_off_ks;
  float32 rtb_t_delay_on_d;
  uint8 rtb_CCaller4;
  boolean rtb_LogicalOperator13_m;
  boolean rtb_signal_e;

  /* Switch: '<S229>/Switch2' incorporates:
   *  Constant: '<S209>/hvbc_b_vehHvilFltSet_ovrdflg'
   */
  if (hvbc_b_vehHvilFltSet_ovrdflg) {
    /* Switch: '<S229>/Switch2' incorporates:
     *  Constant: '<S209>/hvbc_b_vehHvilFltSet_ovrdval'
     */
    hvbd_b_vehHvilFltSet = hvbc_b_vehHvilFltSet_ovrdval;
  } else {
    /* Switch: '<S229>/Switch2' */
    hvbd_b_vehHvilFltSet = swc_DIAG_ARID_DEF.DataTypeConversion93;
  }

  /* End of Switch: '<S229>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S207>/debounce' incorporates:
   *  EnablePort: '<S227>/Enable'
   */
  if (swc_DIAG_ARID_DEF.OR1) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_gu) {
      /* SystemReset for Chart: '<S227>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c32_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b;
      swc_DIAG_ARID_DEF.t_wait_e = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_gu = true;
    }

    /* Saturate: '<S227>/Saturation' incorporates:
     *  Constant: '<S7>/t_delay_fail7'
     */
    if (hvbc_b_vehHvilFltFail_s > 1.6777216E+7F) {
      /* Saturate: '<S227>/Saturation' */
      rtb_t_delay_on_d = 1.6777216E+7F;
    } else if (hvbc_b_vehHvilFltFail_s < 0.0F) {
      /* Saturate: '<S227>/Saturation' */
      rtb_t_delay_on_d = 0.0F;
    } else {
      /* Saturate: '<S227>/Saturation' */
      rtb_t_delay_on_d = hvbc_b_vehHvilFltFail_s;
    }

    /* End of Saturate: '<S227>/Saturation' */

    /* Saturate: '<S227>/Saturation1' incorporates:
     *  Constant: '<S7>/t_delay_heal7'
     */
    if (hvbc_b_vehHvilFltHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S227>/Saturation1' */
      rtb_t_delay_off_ks = 1.6777216E+7F;
    } else if (hvbc_b_vehHvilFltHeal_s < 0.0F) {
      /* Saturate: '<S227>/Saturation1' */
      rtb_t_delay_off_ks = 0.0F;
    } else {
      /* Saturate: '<S227>/Saturation1' */
      rtb_t_delay_off_ks = hvbc_b_vehHvilFltHeal_s;
    }

    /* End of Saturate: '<S227>/Saturation1' */

    /* Chart: '<S227>/timed_debounce' incorporates:
     *  Constant: '<S7>/t_step7'
     *  DataTypeConversion: '<S227>/Data Type Conversion'
     *  UnitDelay: '<S207>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c32_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c32_swc_DIAG = 1U;
      if ((!hvbd_b_vehHvilFltSet) && (rtb_t_delay_off_ks == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_OFF_o;

        /* SignalConversion generated from: '<S227>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
      } else if (hvbd_b_vehHvilFltSet && (rtb_t_delay_on_d == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_ON_b;

        /* SignalConversion generated from: '<S227>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_m1) {
        swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_OFF_WAIT_p;
        swc_DIAG_ARID_DEF.t_wait_e = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_e += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S227>/flg_out' incorporates:
         *  Constant: '<S7>/t_step7'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = true;
      } else {
        swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_ON_WAIT_lh;
        swc_DIAG_ARID_DEF.t_wait_e = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_e += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S227>/flg_out' incorporates:
         *  Constant: '<S7>/t_step7'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c32_swc_DIAG) {
       case swc_DIAG_IN_OFF_o:
        if (hvbd_b_vehHvilFltSet) {
          if (rtb_t_delay_on_d == 0.0F) {
            swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_ON_b;

            /* SignalConversion generated from: '<S227>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = true;
          } else {
            swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_ON_WAIT_lh;
            swc_DIAG_ARID_DEF.t_wait_e = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_e += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S227>/flg_out' incorporates:
             *  Constant: '<S7>/t_step7'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
          }
        } else {
          /* SignalConversion generated from: '<S227>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_p:
        if (hvbd_b_vehHvilFltSet) {
          swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_ON_b;

          /* SignalConversion generated from: '<S227>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_e > rtb_t_delay_off_ks - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_OFF_o;

          /* SignalConversion generated from: '<S227>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_e += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S227>/flg_out' incorporates:
           *  Constant: '<S7>/t_step7'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = true;
        }
        break;

       case swc_DIAG_IN_ON_b:
        if (!hvbd_b_vehHvilFltSet) {
          if (rtb_t_delay_off_ks == 0.0F) {
            swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_OFF_o;

            /* SignalConversion generated from: '<S227>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
          } else {
            swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_OFF_WAIT_p;
            swc_DIAG_ARID_DEF.t_wait_e = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_e += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S227>/flg_out' incorporates:
             *  Constant: '<S7>/t_step7'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = true;
          }
        } else {
          /* SignalConversion generated from: '<S227>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!hvbd_b_vehHvilFltSet) {
          swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_OFF_o;

          /* SignalConversion generated from: '<S227>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_e > rtb_t_delay_on_d - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c32_swc_DIAG = swc_DIAG_IN_ON_b;

          /* SignalConversion generated from: '<S227>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_e += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S227>/flg_out' incorporates:
           *  Constant: '<S7>/t_step7'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
        }
        break;
      }
    }

    /* End of Chart: '<S227>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_gu) {
    /* Disable for SignalConversion generated from: '<S227>/flg_out' incorporates:
     *  Outport: '<S227>/flg_out'
     */
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh = false;
    swc_DIAG_ARID_DEF.debounce_MODE_gu = false;
  }

  /* End of Outputs for SubSystem: '<S207>/debounce' */

  /* SignalConversion: '<S7>/Signal Conversion' */
  digd_b_vcuVehLvl1Flt_flg_HVB = swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh;

  /* CCaller: '<S216>/C Caller' incorporates:
   *  Constant: '<S7>/event_id7'
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   */
  Dem_SetEventStatus(((uint16)32913U), digd_b_vcuVehLvl1Flt_flg_HVB);

  /* Switch: '<S231>/Switch2' incorporates:
   *  Constant: '<S211>/hvbc_b_vehHvilFltSet_ovrdflg'
   */
  if (hvbc_b_BMSFaultLevel3ASet_ovrdflg) {
    /* Switch: '<S231>/Switch2' incorporates:
     *  Constant: '<S211>/hvbc_b_vehHvilFltSet_ovrdval'
     */
    hvbd_b_BMSFaultLevel3ASet = hvbc_b_BMSFaultLevel3ASet_ovrdval;
  } else {
    /* Switch: '<S231>/Switch2' incorporates:
     *  Constant: '<S7>/Constant1'
     *  Constant: '<S7>/Constant3'
     *  Logic: '<S7>/OR'
     *  RelationalOperator: '<S7>/Relational Operator2'
     *  RelationalOperator: '<S7>/Relational Operator4'
     */
    hvbd_b_BMSFaultLevel3ASet = ((swc_DIAG_ARID_DEF.DataTypeConversion24 ==
      ((uint8)11U)) || (swc_DIAG_ARID_DEF.DataTypeConversion182 == ((uint8)3U)));
  }

  /* End of Switch: '<S231>/Switch2' */

  /* Logic: '<S7>/Logical Operator13' */
  rtb_LogicalOperator13_m = !macb_b_P2AD4;

  /* Switch: '<S217>/Switch2' incorporates:
   *  Logic: '<S7>/Logical Operator14'
   */
  rtb_signal_e = !macb_b_P2AD5;

  /* Outputs for Enabled SubSystem: '<S205>/debounce' incorporates:
   *  EnablePort: '<S220>/Enable'
   */
  /* Logic: '<S7>/Logical Operator2' */
  if (rtb_LogicalOperator13_m && rtb_signal_e &&
      swc_DIAG_ARID_DEF.LogicalOperator &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_e) {
      /* SystemReset for Chart: '<S220>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c30_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b;
      swc_DIAG_ARID_DEF.t_wait_bd = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_e = true;
    }

    /* Saturate: '<S220>/Saturation' incorporates:
     *  Constant: '<S7>/t_delay_fail3'
     */
    if (0.5F > 1.6777216E+7F) {
      /* Saturate: '<S220>/Saturation' */
      rtb_t_delay_on_d = 1.6777216E+7F;
    } else if (0.5F < 0.0F) {
      /* Saturate: '<S220>/Saturation' */
      rtb_t_delay_on_d = 0.0F;
    } else {
      /* Saturate: '<S220>/Saturation' */
      rtb_t_delay_on_d = 0.5F;
    }

    /* End of Saturate: '<S220>/Saturation' */

    /* Saturate: '<S220>/Saturation1' incorporates:
     *  Constant: '<S7>/t_delay_fail4'
     */
    if (0.25F > 1.6777216E+7F) {
      /* Saturate: '<S220>/Saturation1' */
      rtb_t_delay_off_ks = 1.6777216E+7F;
    } else if (0.25F < 0.0F) {
      /* Saturate: '<S220>/Saturation1' */
      rtb_t_delay_off_ks = 0.0F;
    } else {
      /* Saturate: '<S220>/Saturation1' */
      rtb_t_delay_off_ks = 0.25F;
    }

    /* End of Saturate: '<S220>/Saturation1' */

    /* Chart: '<S220>/timed_debounce' incorporates:
     *  Constant: '<S7>/t_step2'
     *  DataTypeConversion: '<S220>/Data Type Conversion'
     *  UnitDelay: '<S205>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c30_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c30_swc_DIAG = 1U;
      if ((!hvbd_b_BMSFaultLevel3ASet) && (rtb_t_delay_off_ks == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_OFF_o;

        /* SignalConversion generated from: '<S220>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
      } else if (hvbd_b_BMSFaultLevel3ASet && (rtb_t_delay_on_d == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_ON_b;

        /* SignalConversion generated from: '<S220>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_mc) {
        swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_OFF_WAIT_p;
        swc_DIAG_ARID_DEF.t_wait_bd = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_bd += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S220>/flg_out' incorporates:
         *  Constant: '<S7>/t_step2'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = true;
      } else {
        swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_ON_WAIT_lh;
        swc_DIAG_ARID_DEF.t_wait_bd = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_bd += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S220>/flg_out' incorporates:
         *  Constant: '<S7>/t_step2'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c30_swc_DIAG) {
       case swc_DIAG_IN_OFF_o:
        if (hvbd_b_BMSFaultLevel3ASet) {
          if (rtb_t_delay_on_d == 0.0F) {
            swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_ON_b;

            /* SignalConversion generated from: '<S220>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = true;
          } else {
            swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_ON_WAIT_lh;
            swc_DIAG_ARID_DEF.t_wait_bd = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_bd += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S220>/flg_out' incorporates:
             *  Constant: '<S7>/t_step2'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
          }
        } else {
          /* SignalConversion generated from: '<S220>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_p:
        if (hvbd_b_BMSFaultLevel3ASet) {
          swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_ON_b;

          /* SignalConversion generated from: '<S220>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_bd > rtb_t_delay_off_ks - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_OFF_o;

          /* SignalConversion generated from: '<S220>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_bd += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S220>/flg_out' incorporates:
           *  Constant: '<S7>/t_step2'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = true;
        }
        break;

       case swc_DIAG_IN_ON_b:
        if (!hvbd_b_BMSFaultLevel3ASet) {
          if (rtb_t_delay_off_ks == 0.0F) {
            swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_OFF_o;

            /* SignalConversion generated from: '<S220>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
          } else {
            swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_OFF_WAIT_p;
            swc_DIAG_ARID_DEF.t_wait_bd = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_bd += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S220>/flg_out' incorporates:
             *  Constant: '<S7>/t_step2'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = true;
          }
        } else {
          /* SignalConversion generated from: '<S220>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!hvbd_b_BMSFaultLevel3ASet) {
          swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_OFF_o;

          /* SignalConversion generated from: '<S220>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_bd > rtb_t_delay_on_d - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c30_swc_DIAG = swc_DIAG_IN_ON_b;

          /* SignalConversion generated from: '<S220>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_bd += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S220>/flg_out' incorporates:
           *  Constant: '<S7>/t_step2'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
        }
        break;
      }
    }

    /* End of Chart: '<S220>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_e) {
    /* Disable for SignalConversion generated from: '<S220>/flg_out' incorporates:
     *  Outport: '<S220>/flg_out'
     */
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg = false;
    swc_DIAG_ARID_DEF.debounce_MODE_e = false;
  }

  /* End of Logic: '<S7>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S205>/debounce' */

  /* Logic: '<S208>/OR1' incorporates:
   *  Inport generated from: '<Root>/vild_b_flgClearDTC'
   *  Logic: '<S208>/NOT'
   */
  rtb_OR1_k = ((!swc_DIAG_ARID_DEF.DataTypeConversion254) ||
               Rte_IRead_swc_DIAG_Step_vild_b_flgClearDTC_vild_b_flgClearDTC() ||
               swc_DIAG_ARID_DEF.DataTypeConversion123);

  /* Outputs for Atomic SubSystem: '<S7>/SR_latch1' */
  swc_DIAG_SR_latch1_m(swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg,
                       rtb_OR1_k, &swc_DIAG_ARID_DEF.ARID_DEF_SR_latch1);

  /* End of Outputs for SubSystem: '<S7>/SR_latch1' */

  /* CCaller: '<S214>/C Caller' incorporates:
   *  Constant: '<S7>/event_id2'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32958U), digd_b_vcuVehLvl32Flt_flg_HVB);

  /* Switch: '<S230>/Switch2' incorporates:
   *  Constant: '<S210>/hvbc_b_vehHvilFltSet_ovrdflg'
   */
  if (hvbc_b_BMSFaultLevel2ASet_ovrdflg) {
    /* Switch: '<S230>/Switch2' incorporates:
     *  Constant: '<S210>/hvbc_b_vehHvilFltSet_ovrdval'
     */
    hvbd_b_BMSFaultLevel2ASet = hvbc_b_BMSFaultLevel2ASet_ovrdval;
  } else {
    /* Switch: '<S230>/Switch2' incorporates:
     *  Constant: '<S7>/Constant2'
     *  RelationalOperator: '<S7>/Relational Operator1'
     */
    hvbd_b_BMSFaultLevel2ASet = (swc_DIAG_ARID_DEF.DataTypeConversion182 ==
      ((uint8)2U));
  }

  /* End of Switch: '<S230>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S204>/debounce' incorporates:
   *  EnablePort: '<S218>/Enable'
   */
  /* Logic: '<S7>/Logical Operator10' */
  if (rtb_LogicalOperator13_m && rtb_signal_e &&
      swc_DIAG_ARID_DEF.LogicalOperator &&
      swc_DIAG_ARID_DEF.DataTypeConversion254) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_jy) {
      /* SystemReset for Chart: '<S218>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c29_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b;
      swc_DIAG_ARID_DEF.t_wait_g = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_jy = true;
    }

    /* Saturate: '<S218>/Saturation' incorporates:
     *  Constant: '<S7>/t_delay_fail1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S218>/Saturation' */
      rtb_t_delay_on_d = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S218>/Saturation' */
      rtb_t_delay_on_d = 0.0F;
    } else {
      /* Saturate: '<S218>/Saturation' */
      rtb_t_delay_on_d = 1.0F;
    }

    /* End of Saturate: '<S218>/Saturation' */

    /* Saturate: '<S218>/Saturation1' incorporates:
     *  Constant: '<S7>/t_delay_fail2'
     */
    if (0.25F > 1.6777216E+7F) {
      /* Saturate: '<S218>/Saturation1' */
      rtb_t_delay_off_ks = 1.6777216E+7F;
    } else if (0.25F < 0.0F) {
      /* Saturate: '<S218>/Saturation1' */
      rtb_t_delay_off_ks = 0.0F;
    } else {
      /* Saturate: '<S218>/Saturation1' */
      rtb_t_delay_off_ks = 0.25F;
    }

    /* End of Saturate: '<S218>/Saturation1' */

    /* Chart: '<S218>/timed_debounce' incorporates:
     *  Constant: '<S7>/t_step1'
     *  DataTypeConversion: '<S218>/Data Type Conversion'
     *  UnitDelay: '<S204>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c29_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c29_swc_DIAG = 1U;
      if ((!hvbd_b_BMSFaultLevel2ASet) && (rtb_t_delay_off_ks == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_OFF_o;

        /* SignalConversion generated from: '<S218>/flg_out' */
        digd_b_vcuVehLvl21Flt_flg_HVB = false;
      } else if (hvbd_b_BMSFaultLevel2ASet && (rtb_t_delay_on_d == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_ON_b;

        /* SignalConversion generated from: '<S218>/flg_out' */
        digd_b_vcuVehLvl21Flt_flg_HVB = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_nr) {
        swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_OFF_WAIT_p;
        swc_DIAG_ARID_DEF.t_wait_g = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_g += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S218>/flg_out' incorporates:
         *  Constant: '<S7>/t_step1'
         */
        digd_b_vcuVehLvl21Flt_flg_HVB = true;
      } else {
        swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_ON_WAIT_lh;
        swc_DIAG_ARID_DEF.t_wait_g = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_g += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S218>/flg_out' incorporates:
         *  Constant: '<S7>/t_step1'
         */
        digd_b_vcuVehLvl21Flt_flg_HVB = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c29_swc_DIAG) {
       case swc_DIAG_IN_OFF_o:
        if (hvbd_b_BMSFaultLevel2ASet) {
          if (rtb_t_delay_on_d == 0.0F) {
            swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_ON_b;

            /* SignalConversion generated from: '<S218>/flg_out' */
            digd_b_vcuVehLvl21Flt_flg_HVB = true;
          } else {
            swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_ON_WAIT_lh;
            swc_DIAG_ARID_DEF.t_wait_g = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_g += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S218>/flg_out' incorporates:
             *  Constant: '<S7>/t_step1'
             */
            digd_b_vcuVehLvl21Flt_flg_HVB = false;
          }
        } else {
          /* SignalConversion generated from: '<S218>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_HVB = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_p:
        if (hvbd_b_BMSFaultLevel2ASet) {
          swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_ON_b;

          /* SignalConversion generated from: '<S218>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_HVB = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_g > rtb_t_delay_off_ks - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_OFF_o;

          /* SignalConversion generated from: '<S218>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_HVB = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_g += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S218>/flg_out' incorporates:
           *  Constant: '<S7>/t_step1'
           */
          digd_b_vcuVehLvl21Flt_flg_HVB = true;
        }
        break;

       case swc_DIAG_IN_ON_b:
        if (!hvbd_b_BMSFaultLevel2ASet) {
          if (rtb_t_delay_off_ks == 0.0F) {
            swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_OFF_o;

            /* SignalConversion generated from: '<S218>/flg_out' */
            digd_b_vcuVehLvl21Flt_flg_HVB = false;
          } else {
            swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_OFF_WAIT_p;
            swc_DIAG_ARID_DEF.t_wait_g = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_g += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S218>/flg_out' incorporates:
             *  Constant: '<S7>/t_step1'
             */
            digd_b_vcuVehLvl21Flt_flg_HVB = true;
          }
        } else {
          /* SignalConversion generated from: '<S218>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_HVB = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!hvbd_b_BMSFaultLevel2ASet) {
          swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_OFF_o;

          /* SignalConversion generated from: '<S218>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_HVB = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_g > rtb_t_delay_on_d - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c29_swc_DIAG = swc_DIAG_IN_ON_b;

          /* SignalConversion generated from: '<S218>/flg_out' */
          digd_b_vcuVehLvl21Flt_flg_HVB = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_g += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S218>/flg_out' incorporates:
           *  Constant: '<S7>/t_step1'
           */
          digd_b_vcuVehLvl21Flt_flg_HVB = false;
        }
        break;
      }
    }

    /* End of Chart: '<S218>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_jy) {
    /* Disable for SignalConversion generated from: '<S218>/flg_out' incorporates:
     *  Outport: '<S218>/flg_out'
     */
    digd_b_vcuVehLvl21Flt_flg_HVB = false;
    swc_DIAG_ARID_DEF.debounce_MODE_jy = false;
  }

  /* End of Logic: '<S7>/Logical Operator10' */
  /* End of Outputs for SubSystem: '<S204>/debounce' */

  /* CCaller: '<S215>/C Caller' incorporates:
   *  Constant: '<S7>/event_id1'
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   */
  Dem_SetEventStatus(((uint16)32957U), digd_b_vcuVehLvl21Flt_flg_HVB);

  /* Switch: '<S232>/Switch2' incorporates:
   *  Constant: '<S212>/hvbc_b_vehHvilFltSet_ovrdflg'
   */
  if (hvbc_b_BMSFaultLevel4ASet_ovrdflg) {
    /* Switch: '<S232>/Switch2' incorporates:
     *  Constant: '<S212>/hvbc_b_vehHvilFltSet_ovrdval'
     */
    hvbd_b_BMSFaultLevel4ASet = hvbc_b_BMSFaultLevel4ASet_ovrdval;
  } else {
    /* Switch: '<S232>/Switch2' incorporates:
     *  Constant: '<S7>/Constant4'
     *  Constant: '<S7>/Constant6'
     *  Logic: '<S7>/OR1'
     *  RelationalOperator: '<S7>/Relational Operator3'
     *  RelationalOperator: '<S7>/Relational Operator6'
     */
    hvbd_b_BMSFaultLevel4ASet = ((swc_DIAG_ARID_DEF.DataTypeConversion24 ==
      ((uint8)13U)) || (swc_DIAG_ARID_DEF.DataTypeConversion182 == ((uint8)4U)));
  }

  /* End of Switch: '<S232>/Switch2' */

  /* Logic: '<S7>/Logical Operator12' incorporates:
   *  Logic: '<S7>/Logical Operator3'
   */
  rtb_LogicalOperator12_a = (rtb_LogicalOperator13_m && rtb_signal_e &&
    swc_DIAG_ARID_DEF.LogicalOperator &&
    (swc_DIAG_ARID_DEF.DataTypeConversion254 ||
     swc_DIAG_ARID_DEF.DataTypeConversion123));

  /* Outputs for Enabled SubSystem: '<S206>/debounce' incorporates:
   *  EnablePort: '<S223>/Enable'
   */
  if (rtb_LogicalOperator12_a) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_ka) {
      /* SystemReset for Chart: '<S223>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c31_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b;
      swc_DIAG_ARID_DEF.t_wait_k3 = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_ka = true;
    }

    /* Saturate: '<S223>/Saturation' incorporates:
     *  Constant: '<S7>/t_delay_fail5'
     */
    if (0.01F > 1.6777216E+7F) {
      /* Saturate: '<S223>/Saturation1' */
      rtb_t_delay_on_d = 1.6777216E+7F;
    } else if (0.01F < 0.0F) {
      /* Saturate: '<S223>/Saturation1' */
      rtb_t_delay_on_d = 0.0F;
    } else {
      /* Saturate: '<S223>/Saturation1' */
      rtb_t_delay_on_d = 0.01F;
    }

    /* Chart: '<S223>/timed_debounce' incorporates:
     *  Constant: '<S7>/t_step3'
     *  DataTypeConversion: '<S223>/Data Type Conversion'
     *  Saturate: '<S223>/Saturation'
     *  UnitDelay: '<S206>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c31_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c31_swc_DIAG = 1U;
      if ((!hvbd_b_BMSFaultLevel4ASet) && (rtb_t_delay_on_d == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_OFF_o;

        /* SignalConversion generated from: '<S223>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = false;
      } else if (hvbd_b_BMSFaultLevel4ASet && (rtb_t_delay_on_d == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_ON_b;

        /* SignalConversion generated from: '<S223>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_ix) {
        swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_OFF_WAIT_p;
        swc_DIAG_ARID_DEF.t_wait_k3 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_k3 += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S223>/flg_out' incorporates:
         *  Constant: '<S7>/t_step3'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = true;
      } else {
        swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_ON_WAIT_lh;
        swc_DIAG_ARID_DEF.t_wait_k3 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_k3 += ((float32)HVB_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S223>/flg_out' incorporates:
         *  Constant: '<S7>/t_step3'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c31_swc_DIAG) {
       case swc_DIAG_IN_OFF_o:
        if (hvbd_b_BMSFaultLevel4ASet) {
          if (rtb_t_delay_on_d == 0.0F) {
            swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_ON_b;

            /* SignalConversion generated from: '<S223>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = true;
          } else {
            swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_ON_WAIT_lh;
            swc_DIAG_ARID_DEF.t_wait_k3 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_k3 += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S223>/flg_out' incorporates:
             *  Constant: '<S7>/t_step3'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = false;
          }
        } else {
          /* SignalConversion generated from: '<S223>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_p:
        if (hvbd_b_BMSFaultLevel4ASet) {
          swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_ON_b;

          /* SignalConversion generated from: '<S223>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_k3 > rtb_t_delay_on_d - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_OFF_o;

          /* SignalConversion generated from: '<S223>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_k3 += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S223>/flg_out' incorporates:
           *  Constant: '<S7>/t_step3'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = true;
        }
        break;

       case swc_DIAG_IN_ON_b:
        if (!hvbd_b_BMSFaultLevel4ASet) {
          if (rtb_t_delay_on_d == 0.0F) {
            swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_OFF_o;

            /* SignalConversion generated from: '<S223>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = false;
          } else {
            swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_OFF_WAIT_p;
            swc_DIAG_ARID_DEF.t_wait_k3 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_k3 += ((float32)HVB_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S223>/flg_out' incorporates:
             *  Constant: '<S7>/t_step3'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = true;
          }
        } else {
          /* SignalConversion generated from: '<S223>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!hvbd_b_BMSFaultLevel4ASet) {
          swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_OFF_o;

          /* SignalConversion generated from: '<S223>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_k3 > rtb_t_delay_on_d - ((float32)
                    HVB_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c31_swc_DIAG = swc_DIAG_IN_ON_b;

          /* SignalConversion generated from: '<S223>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_k3 += ((float32)HVB_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S223>/flg_out' incorporates:
           *  Constant: '<S7>/t_step3'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht = false;
        }
        break;
      }
    }

    /* End of Chart: '<S223>/timed_debounce' */
  } else {
    swc_DIAG_ARID_DEF.debounce_MODE_ka = false;
  }

  /* End of Outputs for SubSystem: '<S206>/debounce' */

  /* Outputs for Atomic SubSystem: '<S206>/turnON_delay' */
  /* Constant: '<S7>/t_delay_fail5' incorporates:
   *  Constant: '<S7>/t_step3'
   */
  swc_DIAG_turnON_delay(rtb_LogicalOperator12_a, 0.01F, ((float32)
    HVB_TASK_INTERVAL_S), &rtb_flg_out_eo,
                        &swc_DIAG_ARID_DEF.ARID_DEF_turnON_delay);

  /* End of Outputs for SubSystem: '<S206>/turnON_delay' */

  /* Switch: '<S206>/Switch2' incorporates:
   *  Constant: '<S206>/t_delay_heal1'
   *  Logic: '<S206>/Logical Operator1'
   */
  if (!sysc_b_delayEnaDTCFcnCall) {
    rtb_LogicalOperator13_m = rtb_LogicalOperator12_a;
  } else {
    rtb_LogicalOperator13_m = rtb_flg_out_eo;
  }

  /* Outputs for Enabled SubSystem: '<S206>/Subsystem' incorporates:
   *  EnablePort: '<S222>/Enable'
   */
  /* Logic: '<S206>/Logical Operator2' incorporates:
   *  Constant: '<S206>/t_delay_heal15'
   *  Constant: '<S206>/t_delay_heal2'
   *  Logic: '<S206>/Logical Operator'
   *  Logic: '<S206>/Logical Operator3'
   *  Switch: '<S206>/Switch2'
   */
  if ((rtb_LogicalOperator13_m || sysc_b_forceEnaDTCFcnCall) &&
      (!ddic_b_forceDisDTCFcnCall)) {
    /* CCaller: '<S222>/C Caller' incorporates:
     *  Constant: '<S7>/event_id3'
     *  DataTypeConversion: '<S206>/Data Type Conversion'
     */
    Dem_SetEventStatus(((uint16)32959U),
                       swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht);
  }

  /* End of Logic: '<S206>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S206>/Subsystem' */

  /* CCaller: '<S7>/C Caller4' */
  rtb_CCaller4 = 0U;

  /* CCaller: '<S7>/C Caller4' incorporates:
   *  Constant: '<S7>/DFC_Constant26'
   */
  Dem_GetEventStatus(((uint16)32959U), &rtb_CCaller4);

  /* Switch: '<S217>/Switch2' incorporates:
   *  Constant: '<S7>/DFC_ovrdflg'
   */
  if (digc_b_evtFaildBMSFaultLevel4A_ovrdflg) {
    /* SignalConversion: '<S7>/Signal Conversion3' incorporates:
     *  Constant: '<S7>/DFC_ovrdval'
     *  Switch: '<S217>/Switch2'
     */
    digd_b_vcuVehLvl33Flt_flg_HVB = digc_b_evtFaildBMSFaultLevel4A_ovrdval;
  } else {
    /* S-Function (sfix_bitop): '<S7>/Bitwise And1' */
    rtb_CCaller4 &= ((uint8)8U);

    /* SignalConversion: '<S7>/Signal Conversion3' incorporates:
     *  DataTypeConversion: '<S7>/con_3'
     *  Switch: '<S217>/Switch2'
     */
    digd_b_vcuVehLvl33Flt_flg_HVB = (rtb_CCaller4 != 0);
  }

  /* End of Switch: '<S217>/Switch2' */

  /* Update for UnitDelay: '<S207>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_m1 =
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoh;

  /* Update for UnitDelay: '<S205>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_mc =
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsohtg;

  /* Update for UnitDelay: '<S204>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_nr = digd_b_vcuVehLvl21Flt_flg_HVB;

  /* Update for UnitDelay: '<S206>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_ix =
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hsoht;
}

/* Output and update for atomic system: '<S8>/SR_latch2' */
static void swc_DIAG_SR_latch2(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch2_swc_DIAG_T *swc_DIAG__ARID_DEF_arg)
{
  /* Logic: '<S276>/Logical Operator3' incorporates:
   *  Logic: '<S276>/Logical Operator'
   *  Logic: '<S276>/Logical Operator1'
   *  UnitDelay: '<S276>/Unit Delay'
   */
  *rty_flg_out = ((swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S276>/Unit Delay' */
  swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/* Output and update for atomic system: '<S8>/SR_latch3' */
static void swc_DIAG_SR_latch3(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch3_swc_DIAG_T *swc_DIAG__ARID_DEF_arg)
{
  /* Logic: '<S277>/Logical Operator3' incorporates:
   *  Logic: '<S277>/Logical Operator'
   *  Logic: '<S277>/Logical Operator1'
   *  UnitDelay: '<S277>/Unit Delay'
   */
  *rty_flg_out = ((swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S277>/Unit Delay' */
  swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/* Output and update for atomic system: '<S8>/SR_latch4' */
static void swc_DIAG_SR_latch4(boolean rtu_flg_set, boolean rtu_flg_reset,
  boolean *rty_flg_out, ARID_DEF_SR_latch4_swc_DIAG_T *swc_DIAG__ARID_DEF_arg)
{
  /* Logic: '<S278>/Logical Operator3' incorporates:
   *  Logic: '<S278>/Logical Operator'
   *  Logic: '<S278>/Logical Operator1'
   *  UnitDelay: '<S278>/Unit Delay'
   */
  *rty_flg_out = ((swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE || rtu_flg_set) && (
    !rtu_flg_reset));

  /* Update for UnitDelay: '<S278>/Unit Delay' */
  swc_DIAG__ARID_DEF_arg->UnitDelay_DSTATE = *rty_flg_out;
}

/* System initialize for function-call system: '<S1>/MAC_Diag' */
static void swc_DIAG_MAC_Diag_Init(void)
{
  /* SystemInitialize for SignalConversion: '<S8>/Signal Conversion5' */
  swc_DIAG_ARID_DEF.SignalConversion5 = macd_b_EGSMMsgErrDebd;
}

/* Output and update for function-call system: '<S1>/MAC_Diag' */
static void swc_DIAG_MAC_Diag(void)
{
  /* local block i/o variables */
  boolean rtb_OR1_j;
  boolean rtb_OR1_h;
  boolean rtb_OR1_o;
  boolean rtb_LogicalOperator3_aq;
  boolean rtb_LogicalOperator3_n;
  float32 rtb_t_delay_off_l;
  float32 rtb_t_delay_on_ne;
  boolean rtb_LogicalOperator4_c_tmp_tmp;
  boolean rtb_LogicalOperator5_p_tmp_tmp;
  boolean rtb_LogicalOperator63_m;
  boolean rtb_LogicalOperator64;
  boolean rtb_OR1_j_tmp;
  boolean rtb_Switch2;
  boolean tmp;

  /* Switch: '<S345>/Switch2' incorporates:
   *  Constant: '<S258>/macc_b_batIntSmplLoSet_ovrdflg'
   */
  if (macc_b_batIntSmplLoSet_ovrdflg) {
    /* Switch: '<S345>/Switch2' incorporates:
     *  Constant: '<S258>/macc_b_batIntSmplLoSet_ovrdval'
     */
    macd_b_batIntSmplLoSet = macc_b_batIntSmplLoSet_ovrdval;
  } else {
    /* Switch: '<S345>/Switch2' incorporates:
     *  Constant: '<S8>/Constant230'
     *  RelationalOperator: '<S8>/Relational Operator50'
     */
    macd_b_batIntSmplLoSet = (swc_DIAG_ARID_DEF.DataTypeConversion51 <
      macc_u_batIntSmplLoSet_V);
  }

  /* End of Switch: '<S345>/Switch2' */

  /* Switch: '<S344>/Switch2' incorporates:
   *  Constant: '<S257>/macc_b_batIntSmplLoEnb_ovrdflg'
   */
  if (macc_b_batIntSmplLoEnb_ovrdflg) {
    /* Switch: '<S344>/Switch2' incorporates:
     *  Constant: '<S257>/macc_b_batIntSmplLoEnb_ovrdval'
     */
    macd_b_batIntSmplLoEnb = macc_b_batIntSmplLoEnb_ovrdval;
  } else {
    /* Switch: '<S344>/Switch2' */
    macd_b_batIntSmplLoEnb = swc_DIAG_ARID_DEF.OR1;
  }

  /* End of Switch: '<S344>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S247>/debounce' incorporates:
   *  EnablePort: '<S319>/Enable'
   */
  if (macd_b_batIntSmplLoEnb) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_n4) {
      /* SystemReset for Chart: '<S319>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c17_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_f = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_n4 = true;
    }

    /* Saturate: '<S319>/Saturation' incorporates:
     *  Constant: '<S8>/t_delay_fail'
     */
    if (digc_b_batIntSmplLoFail_s > 1.6777216E+7F) {
      /* Saturate: '<S319>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_b_batIntSmplLoFail_s < 0.0F) {
      /* Saturate: '<S319>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S319>/Saturation' */
      rtb_t_delay_on_ne = digc_b_batIntSmplLoFail_s;
    }

    /* End of Saturate: '<S319>/Saturation' */

    /* Saturate: '<S319>/Saturation1' incorporates:
     *  Constant: '<S8>/t_delay_heal'
     */
    if (macc_b_batIntSmplLoHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S319>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (macc_b_batIntSmplLoHeal_s < 0.0F) {
      /* Saturate: '<S319>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S319>/Saturation1' */
      rtb_t_delay_off_l = macc_b_batIntSmplLoHeal_s;
    }

    /* End of Saturate: '<S319>/Saturation1' */

    /* Chart: '<S319>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step'
     *  DataTypeConversion: '<S319>/Data Type Conversion'
     *  UnitDelay: '<S247>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c17_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c17_swc_DIAG = 1U;
      if ((!macd_b_batIntSmplLoSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S319>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
      } else if (macd_b_batIntSmplLoSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S319>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_d4) {
        swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_f = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_f += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S319>/flg_out' incorporates:
         *  Constant: '<S8>/t_step'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = true;
      } else {
        swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_f = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_f += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S319>/flg_out' incorporates:
         *  Constant: '<S8>/t_step'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c17_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_batIntSmplLoSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S319>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = true;
          } else {
            swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_f = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_f += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S319>/flg_out' incorporates:
             *  Constant: '<S8>/t_step'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
          }
        } else {
          /* SignalConversion generated from: '<S319>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_batIntSmplLoSet) {
          swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S319>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_f > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S319>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_f += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S319>/flg_out' incorporates:
           *  Constant: '<S8>/t_step'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_batIntSmplLoSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S319>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
          } else {
            swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_f = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_f += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S319>/flg_out' incorporates:
             *  Constant: '<S8>/t_step'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = true;
          }
        } else {
          /* SignalConversion generated from: '<S319>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_batIntSmplLoSet) {
          swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S319>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_f > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c17_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S319>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_f += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S319>/flg_out' incorporates:
           *  Constant: '<S8>/t_step'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
        }
        break;
      }
    }

    /* End of Chart: '<S319>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_n4) {
    /* Disable for SignalConversion generated from: '<S319>/flg_out' incorporates:
     *  Outport: '<S319>/flg_out'
     */
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs = false;
    swc_DIAG_ARID_DEF.debounce_MODE_n4 = false;
  }

  /* End of Outputs for SubSystem: '<S247>/debounce' */

  /* RelationalOperator: '<S336>/Compare' incorporates:
   *  Inport generated from: '<Root>/vild_b_flgClearDTC'
   *  RelationalOperator: '<S332>/Compare'
   *  RelationalOperator: '<S340>/Compare'
   */
  rtb_OR1_j_tmp = Rte_IRead_swc_DIAG_Step_vild_b_flgClearDTC_vild_b_flgClearDTC();

  /* Logic: '<S253>/OR1' incorporates:
   *  Constant: '<S333>/Constant'
   *  Constant: '<S334>/Constant'
   *  Constant: '<S335>/Constant'
   *  Constant: '<S336>/Constant'
   *  Inport generated from: '<Root>/vild_b_flgClearDTC'
   *  Logic: '<S253>/AND2'
   *  RelationalOperator: '<S333>/Compare'
   *  RelationalOperator: '<S334>/Compare'
   *  RelationalOperator: '<S335>/Compare'
   *  RelationalOperator: '<S336>/Compare'
   */
  rtb_OR1_j = (((swc_DIAG_ARID_DEF.DataTypeConversion254 == false) &&
                (swc_DIAG_ARID_DEF.DataTypeConversion82 == false) &&
                (swc_DIAG_ARID_DEF.DataTypeConversion123 == false)) ||
               (rtb_OR1_j_tmp == true));

  /* Outputs for Atomic SubSystem: '<S8>/SR_latch3' */
  swc_DIAG_SR_latch3(swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs, rtb_OR1_j,
                     &rtb_LogicalOperator3_n,
                     &swc_DIAG_ARID_DEF.ARID_DEF_SR_latch3);

  /* End of Outputs for SubSystem: '<S8>/SR_latch3' */

  /* SignalConversion generated from: '<S8>/SR_latch3' */
  macd_b_batIntSmplLoDebd = rtb_LogicalOperator3_n;

  /* CCaller: '<S279>/C Caller' incorporates:
   *  Constant: '<S8>/event_id'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32876U), macd_b_batIntSmplLoDebd);

  /* Switch: '<S343>/Switch2' incorporates:
   *  Constant: '<S256>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_batIntSmplHiSet_ovrdflg) {
    /* Switch: '<S343>/Switch2' incorporates:
     *  Constant: '<S256>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_batIntSmplHiSet = macc_b_batIntSmplHiSet_ovrdval;
  } else {
    /* Switch: '<S343>/Switch2' incorporates:
     *  Constant: '<S8>/Constant281'
     *  RelationalOperator: '<S8>/Relational Operator62'
     */
    macd_b_batIntSmplHiSet = (swc_DIAG_ARID_DEF.DataTypeConversion51 >
      macc_u_batIntSmplHiSet_V);
  }

  /* End of Switch: '<S343>/Switch2' */

  /* Switch: '<S342>/Switch2' incorporates:
   *  Constant: '<S255>/macc_b_batIntSmplHiEnb_ovrdflg'
   */
  if (macc_b_batIntSmplHiEnb_ovrdflg) {
    /* Switch: '<S342>/Switch2' incorporates:
     *  Constant: '<S255>/macc_b_batIntSmplHiEnb_ovrdval'
     */
    macd_b_batIntSmplHiEnb = macc_b_batIntSmplHiEnb_ovrdval;
  } else {
    /* Switch: '<S342>/Switch2' */
    macd_b_batIntSmplHiEnb = swc_DIAG_ARID_DEF.OR1;
  }

  /* End of Switch: '<S342>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S246>/debounce' incorporates:
   *  EnablePort: '<S317>/Enable'
   */
  if (macd_b_batIntSmplHiEnb) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_gg) {
      /* SystemReset for Chart: '<S317>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c11_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_cc = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_gg = true;
    }

    /* Saturate: '<S317>/Saturation' incorporates:
     *  Constant: '<S8>/t_delay_fail1'
     */
    if (digc_b_batIntSmplHiFail_s > 1.6777216E+7F) {
      /* Saturate: '<S317>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_b_batIntSmplHiFail_s < 0.0F) {
      /* Saturate: '<S317>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S317>/Saturation' */
      rtb_t_delay_on_ne = digc_b_batIntSmplHiFail_s;
    }

    /* End of Saturate: '<S317>/Saturation' */

    /* Saturate: '<S317>/Saturation1' incorporates:
     *  Constant: '<S8>/t_delay_heal1'
     */
    if (macc_b_batIntSmplHiHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S317>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (macc_b_batIntSmplHiHeal_s < 0.0F) {
      /* Saturate: '<S317>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S317>/Saturation1' */
      rtb_t_delay_off_l = macc_b_batIntSmplHiHeal_s;
    }

    /* End of Saturate: '<S317>/Saturation1' */

    /* Chart: '<S317>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step1'
     *  DataTypeConversion: '<S317>/Data Type Conversion'
     *  UnitDelay: '<S246>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c11_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c11_swc_DIAG = 1U;
      if ((!macd_b_batIntSmplHiSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S317>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
      } else if (macd_b_batIntSmplHiSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S317>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_iw) {
        swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_cc = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_cc += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S317>/flg_out' incorporates:
         *  Constant: '<S8>/t_step1'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = true;
      } else {
        swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_cc = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_cc += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S317>/flg_out' incorporates:
         *  Constant: '<S8>/t_step1'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c11_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_batIntSmplHiSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S317>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = true;
          } else {
            swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_cc = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_cc += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S317>/flg_out' incorporates:
             *  Constant: '<S8>/t_step1'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
          }
        } else {
          /* SignalConversion generated from: '<S317>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_batIntSmplHiSet) {
          swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S317>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_cc > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S317>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_cc += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S317>/flg_out' incorporates:
           *  Constant: '<S8>/t_step1'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_batIntSmplHiSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S317>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
          } else {
            swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_cc = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_cc += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S317>/flg_out' incorporates:
             *  Constant: '<S8>/t_step1'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = true;
          }
        } else {
          /* SignalConversion generated from: '<S317>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_batIntSmplHiSet) {
          swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S317>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_cc > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c11_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S317>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_cc += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S317>/flg_out' incorporates:
           *  Constant: '<S8>/t_step1'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
        }
        break;
      }
    }

    /* End of Chart: '<S317>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_gg) {
    /* Disable for SignalConversion generated from: '<S317>/flg_out' incorporates:
     *  Outport: '<S317>/flg_out'
     */
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso = false;
    swc_DIAG_ARID_DEF.debounce_MODE_gg = false;
  }

  /* End of Outputs for SubSystem: '<S246>/debounce' */

  /* Logic: '<S252>/OR1' incorporates:
   *  Constant: '<S329>/Constant'
   *  Constant: '<S330>/Constant'
   *  Constant: '<S331>/Constant'
   *  Constant: '<S332>/Constant'
   *  Logic: '<S252>/AND2'
   *  RelationalOperator: '<S329>/Compare'
   *  RelationalOperator: '<S330>/Compare'
   *  RelationalOperator: '<S331>/Compare'
   *  RelationalOperator: '<S332>/Compare'
   */
  rtb_OR1_h = (((swc_DIAG_ARID_DEF.DataTypeConversion254 == false) &&
                (swc_DIAG_ARID_DEF.DataTypeConversion82 == false) &&
                (swc_DIAG_ARID_DEF.DataTypeConversion123 == false)) ||
               (rtb_OR1_j_tmp == true));

  /* Outputs for Atomic SubSystem: '<S8>/SR_latch4' */
  swc_DIAG_SR_latch4(swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso, rtb_OR1_h,
                     &rtb_LogicalOperator3_aq,
                     &swc_DIAG_ARID_DEF.ARID_DEF_SR_latch4);

  /* End of Outputs for SubSystem: '<S8>/SR_latch4' */

  /* CCaller: '<S280>/C Caller' incorporates:
   *  Constant: '<S8>/event_id1'
   *  DataTypeConversion: '<S8>/Data Type Conversion1'
   */
  Dem_SetEventStatus(((uint16)32877U), rtb_LogicalOperator3_aq);

  /* Switch: '<S362>/Switch2' incorporates:
   *  Constant: '<S275>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_EGSMMsgErrSet_ovrdflg) {
    /* Switch: '<S362>/Switch2' incorporates:
     *  Constant: '<S275>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_EGSMMsgErrSet = macc_b_EGSMMsgErrSet_ovrdval;
  } else {
    /* Switch: '<S362>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vild_b_flgEGSMAlvCtrErr'
     *  Inport generated from: '<Root>/vild_b_flgEGSMCsmErr'
     *  Logic: '<S8>/OR'
     */
    macd_b_EGSMMsgErrSet = (swc_DIAG_ARID_DEF.DataTypeConversion12 ||
      Rte_IRead_swc_DIAG_Step_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr() ||
      Rte_IRead_swc_DIAG_Step_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr());
  }

  /* End of Switch: '<S362>/Switch2' */

  /* Logic: '<S8>/Logical Operator64' */
  rtb_LogicalOperator64 = !macd_b_batIntSmplLoSet;

  /* Logic: '<S8>/Logical Operator63' */
  rtb_LogicalOperator63_m = !macd_b_batIntSmplHiSet;

  /* Switch: '<S350>/Switch2' incorporates:
   *  Constant: '<S263>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_ptCanBusOffSet_ovrdflg) {
    /* Switch: '<S350>/Switch2' incorporates:
     *  Constant: '<S263>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_ptCanBusOffSet = macc_b_ptCanBusOffSet_ovrdval;
  } else {
    /* Switch: '<S350>/Switch2' */
    macd_b_ptCanBusOffSet = swc_DIAG_ARID_DEF.DataTypeConversion84;
  }

  /* End of Switch: '<S350>/Switch2' */

  /* Logic: '<S8>/Logical Operator4' */
  rtb_LogicalOperator4_c_tmp_tmp = !macd_b_ptCanBusOffSet;

  /* Switch: '<S359>/Switch2' incorporates:
   *  Constant: '<S272>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_cCanBusOffSet_ovrdflg) {
    /* Switch: '<S359>/Switch2' incorporates:
     *  Constant: '<S272>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_cCanBusOffSet = macc_b_cCanBusOffSet_ovrdval;
  } else {
    /* Switch: '<S359>/Switch2' */
    macd_b_cCanBusOffSet = swc_DIAG_ARID_DEF.DataTypeConversion14;
  }

  /* End of Switch: '<S359>/Switch2' */

  /* Logic: '<S8>/Logical Operator5' */
  rtb_LogicalOperator5_p_tmp_tmp = !macd_b_cCanBusOffSet;

  /* Logic: '<S8>/Logical Operator' */
  swc_DIAG_ARID_DEF.LogicalOperator = !swc_DIAG_ARID_DEF.DataTypeConversion13;

  /* Outputs for Enabled SubSystem: '<S241>/debounce' incorporates:
   *  EnablePort: '<S307>/Enable'
   */
  /* Logic: '<S8>/Logical Operator13' incorporates:
   *  Logic: '<S8>/Logical Operator4'
   *  Logic: '<S8>/Logical Operator5'
   */
  if (swc_DIAG_ARID_DEF.flg_out_h && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m && rtb_LogicalOperator4_c_tmp_tmp &&
      rtb_LogicalOperator5_p_tmp_tmp && swc_DIAG_ARID_DEF.LogicalOperator) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_b) {
      /* SystemReset for Chart: '<S307>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c38_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_ho = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_b = true;
    }

    /* Saturate: '<S307>/Saturation' incorporates:
     *  Constant: '<S8>/Constant189'
     */
    if (digc_EGSMMsgErr2fail_s > 1.6777216E+7F) {
      /* Saturate: '<S307>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_EGSMMsgErr2fail_s < 0.0F) {
      /* Saturate: '<S307>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S307>/Saturation' */
      rtb_t_delay_on_ne = digc_EGSMMsgErr2fail_s;
    }

    /* End of Saturate: '<S307>/Saturation' */

    /* Saturate: '<S307>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant192'
     */
    if (digc_EGSMMsgErr2heal_s > 1.6777216E+7F) {
      /* Saturate: '<S307>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_EGSMMsgErr2heal_s < 0.0F) {
      /* Saturate: '<S307>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S307>/Saturation1' */
      rtb_t_delay_off_l = digc_EGSMMsgErr2heal_s;
    }

    /* End of Saturate: '<S307>/Saturation1' */

    /* Chart: '<S307>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step164'
     *  DataTypeConversion: '<S307>/Data Type Conversion'
     *  UnitDelay: '<S241>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c38_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c38_swc_DIAG = 1U;
      if ((!macd_b_EGSMMsgErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S307>/flg_out' */
        macd_b_EGSMMsgErrDebd = false;
      } else if (macd_b_EGSMMsgErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S307>/flg_out' */
        macd_b_EGSMMsgErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_da) {
        swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_ho = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ho += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S307>/flg_out' incorporates:
         *  Constant: '<S8>/t_step164'
         */
        macd_b_EGSMMsgErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_ho = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ho += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S307>/flg_out' incorporates:
         *  Constant: '<S8>/t_step164'
         */
        macd_b_EGSMMsgErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c38_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_EGSMMsgErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S307>/flg_out' */
            macd_b_EGSMMsgErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_ho = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ho += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S307>/flg_out' incorporates:
             *  Constant: '<S8>/t_step164'
             */
            macd_b_EGSMMsgErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S307>/flg_out' */
          macd_b_EGSMMsgErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_EGSMMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S307>/flg_out' */
          macd_b_EGSMMsgErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_ho > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S307>/flg_out' */
          macd_b_EGSMMsgErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ho += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S307>/flg_out' incorporates:
           *  Constant: '<S8>/t_step164'
           */
          macd_b_EGSMMsgErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_EGSMMsgErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S307>/flg_out' */
            macd_b_EGSMMsgErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_ho = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ho += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S307>/flg_out' incorporates:
             *  Constant: '<S8>/t_step164'
             */
            macd_b_EGSMMsgErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S307>/flg_out' */
          macd_b_EGSMMsgErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_EGSMMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S307>/flg_out' */
          macd_b_EGSMMsgErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_ho > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c38_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S307>/flg_out' */
          macd_b_EGSMMsgErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ho += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S307>/flg_out' incorporates:
           *  Constant: '<S8>/t_step164'
           */
          macd_b_EGSMMsgErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S307>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_b) {
    /* Disable for SignalConversion generated from: '<S307>/flg_out' incorporates:
     *  Outport: '<S307>/flg_out'
     */
    macd_b_EGSMMsgErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_b = false;
  }

  /* End of Logic: '<S8>/Logical Operator13' */
  /* End of Outputs for SubSystem: '<S241>/debounce' */

  /* CCaller: '<S281>/C Caller' incorporates:
   *  Constant: '<S8>/Constant193'
   *  DataTypeConversion: '<S8>/Data Type Conversion10'
   */
  Dem_SetEventStatus(((uint16)32900U), macd_b_EGSMMsgErrDebd);

  /* Switch: '<S354>/Switch2' incorporates:
   *  Constant: '<S267>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_BMSHealthMonErrSet_ovrdflg) {
    /* Switch: '<S354>/Switch2' incorporates:
     *  Constant: '<S267>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_BMSHealthMonErrSet = macc_b_BMSHealthMonErrSet_ovrdval;
  } else {
    /* Switch: '<S354>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vild_b_flgBMSAlvCtrErr'
     *  Inport generated from: '<Root>/vild_b_flgBMSCsmErr'
     *  Logic: '<S8>/OR4'
     */
    macd_b_BMSHealthMonErrSet =
      (Rte_IRead_swc_DIAG_Step_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr() ||
       Rte_IRead_swc_DIAG_Step_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr());
  }

  /* End of Switch: '<S354>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S237>/debounce' incorporates:
   *  EnablePort: '<S299>/Enable'
   */
  /* Logic: '<S8>/Logical Operator35' incorporates:
   *  Logic: '<S8>/Logical Operator4'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m && rtb_LogicalOperator4_c_tmp_tmp &&
      swc_DIAG_ARID_DEF.LogicalOperator) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_iq) {
      /* SystemReset for Chart: '<S299>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c35_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_ap = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_iq = true;
    }

    /* Saturate: '<S299>/Saturation' incorporates:
     *  Constant: '<S8>/Constant18'
     */
    if (digc_BMSHealthMonErrfail_s > 1.6777216E+7F) {
      /* Saturate: '<S299>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_BMSHealthMonErrfail_s < 0.0F) {
      /* Saturate: '<S299>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S299>/Saturation' */
      rtb_t_delay_on_ne = digc_BMSHealthMonErrfail_s;
    }

    /* End of Saturate: '<S299>/Saturation' */

    /* Saturate: '<S299>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant19'
     */
    if (digc_BMSHealthMonErrheal_s > 1.6777216E+7F) {
      /* Saturate: '<S299>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_BMSHealthMonErrheal_s < 0.0F) {
      /* Saturate: '<S299>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S299>/Saturation1' */
      rtb_t_delay_off_l = digc_BMSHealthMonErrheal_s;
    }

    /* End of Saturate: '<S299>/Saturation1' */

    /* Chart: '<S299>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step6'
     *  DataTypeConversion: '<S299>/Data Type Conversion'
     *  UnitDelay: '<S237>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c35_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c35_swc_DIAG = 1U;
      if ((!macd_b_BMSHealthMonErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S299>/flg_out' */
        macd_b_BMSHealthMonErrDebd = false;
      } else if (macd_b_BMSHealthMonErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S299>/flg_out' */
        macd_b_BMSHealthMonErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_nj) {
        swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_ap = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ap += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S299>/flg_out' incorporates:
         *  Constant: '<S8>/t_step6'
         */
        macd_b_BMSHealthMonErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_ap = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ap += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S299>/flg_out' incorporates:
         *  Constant: '<S8>/t_step6'
         */
        macd_b_BMSHealthMonErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c35_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_BMSHealthMonErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S299>/flg_out' */
            macd_b_BMSHealthMonErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_ap = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ap += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S299>/flg_out' incorporates:
             *  Constant: '<S8>/t_step6'
             */
            macd_b_BMSHealthMonErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S299>/flg_out' */
          macd_b_BMSHealthMonErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_BMSHealthMonErrSet) {
          swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S299>/flg_out' */
          macd_b_BMSHealthMonErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_ap > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S299>/flg_out' */
          macd_b_BMSHealthMonErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ap += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S299>/flg_out' incorporates:
           *  Constant: '<S8>/t_step6'
           */
          macd_b_BMSHealthMonErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_BMSHealthMonErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S299>/flg_out' */
            macd_b_BMSHealthMonErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_ap = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ap += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S299>/flg_out' incorporates:
             *  Constant: '<S8>/t_step6'
             */
            macd_b_BMSHealthMonErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S299>/flg_out' */
          macd_b_BMSHealthMonErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_BMSHealthMonErrSet) {
          swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S299>/flg_out' */
          macd_b_BMSHealthMonErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_ap > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c35_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S299>/flg_out' */
          macd_b_BMSHealthMonErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ap += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S299>/flg_out' incorporates:
           *  Constant: '<S8>/t_step6'
           */
          macd_b_BMSHealthMonErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S299>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_iq) {
    /* Disable for SignalConversion generated from: '<S299>/flg_out' incorporates:
     *  Outport: '<S299>/flg_out'
     */
    macd_b_BMSHealthMonErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_iq = false;
  }

  /* End of Logic: '<S8>/Logical Operator35' */
  /* End of Outputs for SubSystem: '<S237>/debounce' */

  /* CCaller: '<S282>/C Caller' incorporates:
   *  Constant: '<S8>/Constant7'
   *  DataTypeConversion: '<S8>/Data Type Conversion11'
   */
  Dem_SetEventStatus(((uint16)32973U), macd_b_BMSHealthMonErrDebd);

  /* Switch: '<S351>/Switch2' incorporates:
   *  Constant: '<S264>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_ABSSpdMsgErrSet_ovrdflg) {
    /* Switch: '<S351>/Switch2' incorporates:
     *  Constant: '<S264>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_ABSSpdMsgErrSet = macc_b_ABSSpdMsgErrSet_ovrdval;
  } else {
    /* Switch: '<S351>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vild_b_flgEHBAlvCtrErr'
     *  Inport generated from: '<Root>/vild_b_flgEHBCsmErr'
     *  Logic: '<S8>/OR1'
     */
    macd_b_ABSSpdMsgErrSet = (swc_DIAG_ARID_DEF.SignalConversion ||
      Rte_IRead_swc_DIAG_Step_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr() ||
      Rte_IRead_swc_DIAG_Step_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr());
  }

  /* End of Switch: '<S351>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S248>/debounce' incorporates:
   *  EnablePort: '<S321>/Enable'
   */
  /* Logic: '<S8>/Logical Operator15' incorporates:
   *  Logic: '<S8>/Logical Operator5'
   */
  if (swc_DIAG_ARID_DEF.flg_out_h && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m && rtb_LogicalOperator5_p_tmp_tmp &&
      swc_DIAG_ARID_DEF.LogicalOperator) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_l) {
      /* SystemReset for Chart: '<S321>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c41_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_j = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_l = true;
    }

    /* Saturate: '<S321>/Saturation' incorporates:
     *  Constant: '<S8>/Constant223'
     */
    if (digc_ABSSpdMsgErr2fail_s > 1.6777216E+7F) {
      /* Saturate: '<S321>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_ABSSpdMsgErr2fail_s < 0.0F) {
      /* Saturate: '<S321>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S321>/Saturation' */
      rtb_t_delay_on_ne = digc_ABSSpdMsgErr2fail_s;
    }

    /* End of Saturate: '<S321>/Saturation' */

    /* Saturate: '<S321>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant224'
     */
    if (digc_ABSSpdMsgErr2heal_s > 1.6777216E+7F) {
      /* Saturate: '<S321>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_ABSSpdMsgErr2heal_s < 0.0F) {
      /* Saturate: '<S321>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S321>/Saturation1' */
      rtb_t_delay_off_l = digc_ABSSpdMsgErr2heal_s;
    }

    /* End of Saturate: '<S321>/Saturation1' */

    /* Chart: '<S321>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step170'
     *  DataTypeConversion: '<S321>/Data Type Conversion'
     *  UnitDelay: '<S248>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c41_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c41_swc_DIAG = 1U;
      if ((!macd_b_ABSSpdMsgErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S321>/flg_out' */
        macd_b_ABSSpdMsgErrDebd = false;
      } else if (macd_b_ABSSpdMsgErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S321>/flg_out' */
        macd_b_ABSSpdMsgErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_m) {
        swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_j = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_j += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S321>/flg_out' incorporates:
         *  Constant: '<S8>/t_step170'
         */
        macd_b_ABSSpdMsgErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_j = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_j += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S321>/flg_out' incorporates:
         *  Constant: '<S8>/t_step170'
         */
        macd_b_ABSSpdMsgErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c41_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_ABSSpdMsgErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S321>/flg_out' */
            macd_b_ABSSpdMsgErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_j = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_j += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S321>/flg_out' incorporates:
             *  Constant: '<S8>/t_step170'
             */
            macd_b_ABSSpdMsgErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S321>/flg_out' */
          macd_b_ABSSpdMsgErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_ABSSpdMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S321>/flg_out' */
          macd_b_ABSSpdMsgErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_j > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S321>/flg_out' */
          macd_b_ABSSpdMsgErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_j += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S321>/flg_out' incorporates:
           *  Constant: '<S8>/t_step170'
           */
          macd_b_ABSSpdMsgErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_ABSSpdMsgErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S321>/flg_out' */
            macd_b_ABSSpdMsgErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_j = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_j += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S321>/flg_out' incorporates:
             *  Constant: '<S8>/t_step170'
             */
            macd_b_ABSSpdMsgErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S321>/flg_out' */
          macd_b_ABSSpdMsgErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_ABSSpdMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S321>/flg_out' */
          macd_b_ABSSpdMsgErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_j > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c41_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S321>/flg_out' */
          macd_b_ABSSpdMsgErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_j += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S321>/flg_out' incorporates:
           *  Constant: '<S8>/t_step170'
           */
          macd_b_ABSSpdMsgErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S321>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_l) {
    /* Disable for SignalConversion generated from: '<S321>/flg_out' incorporates:
     *  Outport: '<S321>/flg_out'
     */
    macd_b_ABSSpdMsgErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_l = false;
  }

  /* End of Logic: '<S8>/Logical Operator15' */
  /* End of Outputs for SubSystem: '<S248>/debounce' */

  /* CCaller: '<S283>/C Caller' incorporates:
   *  Constant: '<S8>/Constant229'
   *  DataTypeConversion: '<S8>/Data Type Conversion12'
   */
  Dem_SetEventStatus(((uint16)32902U), macd_b_ABSSpdMsgErrDebd);

  /* Switch: '<S353>/Switch2' incorporates:
   *  Constant: '<S266>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_ACUMsgErrSet_ovrdflg) {
    /* Switch: '<S353>/Switch2' incorporates:
     *  Constant: '<S266>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_ACUMsgErrSet = macc_b_ACUMsgErrSet_ovrdval;
  } else {
    /* Switch: '<S353>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vild_b_flgACUAlvCtrErr'
     *  Inport generated from: '<Root>/vild_b_flgACUCsmErr'
     *  Inport generated from: '<Root>/vild_b_flgACUMsgErr'
     *  Logic: '<S8>/AND'
     *  Logic: '<S8>/OR3'
     */
    macd_b_ACUMsgErrSet = (swc_DIAG_ARID_DEF.DataTypeConversion23 &&
      (Rte_IRead_swc_DIAG_Step_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr() ||
       Rte_IRead_swc_DIAG_Step_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr() ||
       Rte_IRead_swc_DIAG_Step_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr()));
  }

  /* End of Switch: '<S353>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S236>/debounce' incorporates:
   *  EnablePort: '<S297>/Enable'
   */
  /* Logic: '<S8>/Logical Operator34' incorporates:
   *  Logic: '<S8>/Logical Operator5'
   */
  if (swc_DIAG_ARID_DEF.flg_out_h && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m && rtb_LogicalOperator5_p_tmp_tmp) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_hl) {
      /* SystemReset for Chart: '<S297>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c34_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_i1 = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_hl = true;
    }

    /* Saturate: '<S297>/Saturation' incorporates:
     *  Constant: '<S8>/Constant15'
     */
    if (digc_ACUMsgErrfail_s > 1.6777216E+7F) {
      /* Saturate: '<S297>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_ACUMsgErrfail_s < 0.0F) {
      /* Saturate: '<S297>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S297>/Saturation' */
      rtb_t_delay_on_ne = digc_ACUMsgErrfail_s;
    }

    /* End of Saturate: '<S297>/Saturation' */

    /* Saturate: '<S297>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant16'
     */
    if (digc_ACUMsgErrheal_s > 1.6777216E+7F) {
      /* Saturate: '<S297>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_ACUMsgErrheal_s < 0.0F) {
      /* Saturate: '<S297>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S297>/Saturation1' */
      rtb_t_delay_off_l = digc_ACUMsgErrheal_s;
    }

    /* End of Saturate: '<S297>/Saturation1' */

    /* Chart: '<S297>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step5'
     *  DataTypeConversion: '<S297>/Data Type Conversion'
     *  UnitDelay: '<S236>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c34_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c34_swc_DIAG = 1U;
      if ((!macd_b_ACUMsgErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S297>/flg_out' */
        digd_b_ACUMsgErrDebd = false;
      } else if (macd_b_ACUMsgErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S297>/flg_out' */
        digd_b_ACUMsgErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_cp) {
        swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_i1 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_i1 += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S297>/flg_out' incorporates:
         *  Constant: '<S8>/t_step5'
         */
        digd_b_ACUMsgErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_i1 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_i1 += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S297>/flg_out' incorporates:
         *  Constant: '<S8>/t_step5'
         */
        digd_b_ACUMsgErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c34_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_ACUMsgErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S297>/flg_out' */
            digd_b_ACUMsgErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_i1 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_i1 += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S297>/flg_out' incorporates:
             *  Constant: '<S8>/t_step5'
             */
            digd_b_ACUMsgErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S297>/flg_out' */
          digd_b_ACUMsgErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_ACUMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S297>/flg_out' */
          digd_b_ACUMsgErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_i1 > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S297>/flg_out' */
          digd_b_ACUMsgErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_i1 += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S297>/flg_out' incorporates:
           *  Constant: '<S8>/t_step5'
           */
          digd_b_ACUMsgErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_ACUMsgErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S297>/flg_out' */
            digd_b_ACUMsgErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_i1 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_i1 += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S297>/flg_out' incorporates:
             *  Constant: '<S8>/t_step5'
             */
            digd_b_ACUMsgErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S297>/flg_out' */
          digd_b_ACUMsgErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_ACUMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S297>/flg_out' */
          digd_b_ACUMsgErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_i1 > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c34_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S297>/flg_out' */
          digd_b_ACUMsgErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_i1 += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S297>/flg_out' incorporates:
           *  Constant: '<S8>/t_step5'
           */
          digd_b_ACUMsgErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S297>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_hl) {
    /* Disable for SignalConversion generated from: '<S297>/flg_out' incorporates:
     *  Outport: '<S297>/flg_out'
     */
    digd_b_ACUMsgErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_hl = false;
  }

  /* End of Logic: '<S8>/Logical Operator34' */
  /* End of Outputs for SubSystem: '<S236>/debounce' */

  /* CCaller: '<S284>/C Caller' incorporates:
   *  Constant: '<S8>/Constant6'
   *  DataTypeConversion: '<S8>/Data Type Conversion13'
   */
  Dem_SetEventStatus(((uint16)32972U), digd_b_ACUMsgErrDebd);

  /* Switch: '<S356>/Switch2' incorporates:
   *  Constant: '<S269>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_CSMMsgErrSet_ovrdflg) {
    /* Switch: '<S356>/Switch2' incorporates:
     *  Constant: '<S269>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_CSMMsgErrSet = macc_b_CSMMsgErrSet_ovrdval;
  } else {
    /* Switch: '<S356>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vild_b_flgCSMAlvCtrErr'
     *  Inport generated from: '<Root>/vild_b_flgCSMCsmErr'
     *  Inport generated from: '<Root>/vild_b_flgCSMMsgErr'
     *  Logic: '<S8>/OR6'
     */
    macd_b_CSMMsgErrSet =
      (Rte_IRead_swc_DIAG_Step_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr() ||
       Rte_IRead_swc_DIAG_Step_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr() ||
       Rte_IRead_swc_DIAG_Step_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr());
  }

  /* End of Switch: '<S356>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S239>/debounce' incorporates:
   *  EnablePort: '<S303>/Enable'
   */
  /* Logic: '<S8>/Logical Operator37' incorporates:
   *  Logic: '<S8>/Logical Operator4'
   */
  if (swc_DIAG_ARID_DEF.flg_out_h && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m && rtb_LogicalOperator4_c_tmp_tmp) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_o1) {
      /* SystemReset for Chart: '<S303>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c36_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_jt = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_o1 = true;
    }

    /* Saturate: '<S303>/Saturation' incorporates:
     *  Constant: '<S8>/Constant24'
     */
    if (digc_CSMMsgErrfail_s > 1.6777216E+7F) {
      /* Saturate: '<S303>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_CSMMsgErrfail_s < 0.0F) {
      /* Saturate: '<S303>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S303>/Saturation' */
      rtb_t_delay_on_ne = digc_CSMMsgErrfail_s;
    }

    /* End of Saturate: '<S303>/Saturation' */

    /* Saturate: '<S303>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant25'
     */
    if (digc_CSMMsgErrheal_s > 1.6777216E+7F) {
      /* Saturate: '<S303>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_CSMMsgErrheal_s < 0.0F) {
      /* Saturate: '<S303>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S303>/Saturation1' */
      rtb_t_delay_off_l = digc_CSMMsgErrheal_s;
    }

    /* End of Saturate: '<S303>/Saturation1' */

    /* Chart: '<S303>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step8'
     *  DataTypeConversion: '<S303>/Data Type Conversion'
     *  UnitDelay: '<S239>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c36_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c36_swc_DIAG = 1U;
      if ((!macd_b_CSMMsgErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S303>/flg_out' */
        macd_b_CSMMsgErrDebd = false;
      } else if (macd_b_CSMMsgErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S303>/flg_out' */
        macd_b_CSMMsgErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_h) {
        swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_jt = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_jt += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S303>/flg_out' incorporates:
         *  Constant: '<S8>/t_step8'
         */
        macd_b_CSMMsgErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_jt = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_jt += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S303>/flg_out' incorporates:
         *  Constant: '<S8>/t_step8'
         */
        macd_b_CSMMsgErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c36_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_CSMMsgErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S303>/flg_out' */
            macd_b_CSMMsgErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_jt = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_jt += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S303>/flg_out' incorporates:
             *  Constant: '<S8>/t_step8'
             */
            macd_b_CSMMsgErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S303>/flg_out' */
          macd_b_CSMMsgErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_CSMMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S303>/flg_out' */
          macd_b_CSMMsgErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_jt > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S303>/flg_out' */
          macd_b_CSMMsgErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_jt += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S303>/flg_out' incorporates:
           *  Constant: '<S8>/t_step8'
           */
          macd_b_CSMMsgErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_CSMMsgErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S303>/flg_out' */
            macd_b_CSMMsgErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_jt = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_jt += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S303>/flg_out' incorporates:
             *  Constant: '<S8>/t_step8'
             */
            macd_b_CSMMsgErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S303>/flg_out' */
          macd_b_CSMMsgErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_CSMMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S303>/flg_out' */
          macd_b_CSMMsgErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_jt > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c36_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S303>/flg_out' */
          macd_b_CSMMsgErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_jt += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S303>/flg_out' incorporates:
           *  Constant: '<S8>/t_step8'
           */
          macd_b_CSMMsgErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S303>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_o1) {
    /* Disable for SignalConversion generated from: '<S303>/flg_out' incorporates:
     *  Outport: '<S303>/flg_out'
     */
    macd_b_CSMMsgErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_o1 = false;
  }

  /* End of Logic: '<S8>/Logical Operator37' */
  /* End of Outputs for SubSystem: '<S239>/debounce' */

  /* CCaller: '<S285>/C Caller' incorporates:
   *  Constant: '<S8>/Constant9'
   *  DataTypeConversion: '<S8>/Data Type Conversion14'
   */
  Dem_SetEventStatus(((uint16)32975U), macd_b_CSMMsgErrDebd);

  /* Switch: '<S355>/Switch2' incorporates:
   *  Constant: '<S268>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_MCUHealthMonErrSet_ovrdflg) {
    /* Switch: '<S355>/Switch2' incorporates:
     *  Constant: '<S268>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_MCUHealthMonErrSet = macc_b_MCUHealthMonErrSet_ovrdval;
  } else {
    /* Switch: '<S355>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vild_b_flgIPUAlvCtrErr'
     *  Inport generated from: '<Root>/vild_b_flgIPUCsmErr'
     *  Logic: '<S8>/OR5'
     */
    macd_b_MCUHealthMonErrSet =
      (Rte_IRead_swc_DIAG_Step_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr() ||
       Rte_IRead_swc_DIAG_Step_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr());
  }

  /* End of Switch: '<S355>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S244>/debounce' incorporates:
   *  EnablePort: '<S313>/Enable'
   */
  /* Logic: '<S8>/Logical Operator36' incorporates:
   *  Logic: '<S8>/Logical Operator5'
   */
  if (swc_DIAG_ARID_DEF.flg_out_h && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m && rtb_LogicalOperator5_p_tmp_tmp &&
      swc_DIAG_ARID_DEF.LogicalOperator) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_cj) {
      /* SystemReset for Chart: '<S313>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c39_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_pp = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_cj = true;
    }

    /* Saturate: '<S313>/Saturation' incorporates:
     *  Constant: '<S8>/Constant21'
     */
    if (digc_MCUHealthMonErrfail_s > 1.6777216E+7F) {
      /* Saturate: '<S313>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_MCUHealthMonErrfail_s < 0.0F) {
      /* Saturate: '<S313>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S313>/Saturation' */
      rtb_t_delay_on_ne = digc_MCUHealthMonErrfail_s;
    }

    /* End of Saturate: '<S313>/Saturation' */

    /* Saturate: '<S313>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant22'
     */
    if (digc_MCUHealthMonErrheal_s > 1.6777216E+7F) {
      /* Saturate: '<S313>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_MCUHealthMonErrheal_s < 0.0F) {
      /* Saturate: '<S313>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S313>/Saturation1' */
      rtb_t_delay_off_l = digc_MCUHealthMonErrheal_s;
    }

    /* End of Saturate: '<S313>/Saturation1' */

    /* Chart: '<S313>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step7'
     *  DataTypeConversion: '<S313>/Data Type Conversion'
     *  UnitDelay: '<S244>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c39_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c39_swc_DIAG = 1U;
      if ((!macd_b_MCUHealthMonErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S313>/flg_out' */
        macd_b_MCUHealthMonErrDebd = false;
      } else if (macd_b_MCUHealthMonErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S313>/flg_out' */
        macd_b_MCUHealthMonErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_ov) {
        swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_pp = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_pp += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S313>/flg_out' incorporates:
         *  Constant: '<S8>/t_step7'
         */
        macd_b_MCUHealthMonErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_pp = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_pp += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S313>/flg_out' incorporates:
         *  Constant: '<S8>/t_step7'
         */
        macd_b_MCUHealthMonErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c39_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_MCUHealthMonErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S313>/flg_out' */
            macd_b_MCUHealthMonErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_pp = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_pp += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S313>/flg_out' incorporates:
             *  Constant: '<S8>/t_step7'
             */
            macd_b_MCUHealthMonErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S313>/flg_out' */
          macd_b_MCUHealthMonErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_MCUHealthMonErrSet) {
          swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S313>/flg_out' */
          macd_b_MCUHealthMonErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_pp > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S313>/flg_out' */
          macd_b_MCUHealthMonErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_pp += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S313>/flg_out' incorporates:
           *  Constant: '<S8>/t_step7'
           */
          macd_b_MCUHealthMonErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_MCUHealthMonErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S313>/flg_out' */
            macd_b_MCUHealthMonErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_pp = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_pp += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S313>/flg_out' incorporates:
             *  Constant: '<S8>/t_step7'
             */
            macd_b_MCUHealthMonErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S313>/flg_out' */
          macd_b_MCUHealthMonErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_MCUHealthMonErrSet) {
          swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S313>/flg_out' */
          macd_b_MCUHealthMonErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_pp > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c39_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S313>/flg_out' */
          macd_b_MCUHealthMonErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_pp += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S313>/flg_out' incorporates:
           *  Constant: '<S8>/t_step7'
           */
          macd_b_MCUHealthMonErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S313>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_cj) {
    /* Disable for SignalConversion generated from: '<S313>/flg_out' incorporates:
     *  Outport: '<S313>/flg_out'
     */
    macd_b_MCUHealthMonErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_cj = false;
  }

  /* End of Logic: '<S8>/Logical Operator36' */
  /* End of Outputs for SubSystem: '<S244>/debounce' */

  /* CCaller: '<S286>/C Caller' incorporates:
   *  Constant: '<S8>/Constant8'
   *  DataTypeConversion: '<S8>/Data Type Conversion15'
   */
  Dem_SetEventStatus(((uint16)32974U), macd_b_MCUHealthMonErrDebd);

  /* Switch: '<S347>/Switch2' incorporates:
   *  Constant: '<S260>/macc_b_5VT1IntSmplFltSet_ovrdflg'
   *  Constant: '<S260>/macc_b_5VT1IntSmplFltSet_ovrdval'
   *  Constant: '<S8>/Constant292'
   *  Constant: '<S8>/Constant303'
   *  Logic: '<S8>/Logical Operator232'
   *  RelationalOperator: '<S8>/Relational Operator84'
   *  RelationalOperator: '<S8>/Relational Operator95'
   */
  if (macc_b_5VT1IntSmplFltSet_ovrdflg) {
    macd_b_5VT1IntSmplFltSet = macc_b_5VT1IntSmplFltSet_ovrdval;
  } else {
    macd_b_5VT1IntSmplFltSet = ((swc_DIAG_ARID_DEF.DataTypeConversion52 >
      macc_u_5VT1IntSmplFltSetHi_V) || (swc_DIAG_ARID_DEF.DataTypeConversion52 <
      macc_u_5VT1IntSmplFltSetLo_V));
  }

  /* End of Switch: '<S347>/Switch2' */

  /* Switch: '<S346>/Switch2' incorporates:
   *  Constant: '<S259>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (macc_b_5VT1IntSmplFltEnb_ovrdflg) {
    /* Switch: '<S346>/Switch2' incorporates:
     *  Constant: '<S259>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    macd_b_5VT1IntSmplFltEnb = macc_b_5VT1IntSmplFltEnb_ovrdval;
  } else {
    /* Switch: '<S346>/Switch2' incorporates:
     *  Logic: '<S8>/Logical Operator234'
     */
    macd_b_5VT1IntSmplFltEnb = (rtb_LogicalOperator64 && rtb_LogicalOperator63_m
      && swc_DIAG_ARID_DEF.DataTypeConversion254);
  }

  /* End of Switch: '<S346>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S249>/debounce' incorporates:
   *  EnablePort: '<S323>/Enable'
   */
  if (macd_b_5VT1IntSmplFltEnb) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_h) {
      /* SystemReset for Chart: '<S323>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c42_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_cb = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_h = true;
    }

    /* Saturate: '<S323>/Saturation' incorporates:
     *  Constant: '<S8>/t_delay_fail2'
     */
    if (macc_b_5VT1IntSmplFltFail_s > 1.6777216E+7F) {
      /* Saturate: '<S323>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (macc_b_5VT1IntSmplFltFail_s < 0.0F) {
      /* Saturate: '<S323>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S323>/Saturation' */
      rtb_t_delay_on_ne = macc_b_5VT1IntSmplFltFail_s;
    }

    /* End of Saturate: '<S323>/Saturation' */

    /* Saturate: '<S323>/Saturation1' incorporates:
     *  Constant: '<S8>/t_delay_heal2'
     */
    if (macc_b_5VT1IntSmplFltHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S323>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (macc_b_5VT1IntSmplFltHeal_s < 0.0F) {
      /* Saturate: '<S323>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S323>/Saturation1' */
      rtb_t_delay_off_l = macc_b_5VT1IntSmplFltHeal_s;
    }

    /* End of Saturate: '<S323>/Saturation1' */

    /* Chart: '<S323>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step2'
     *  DataTypeConversion: '<S323>/Data Type Conversion'
     *  UnitDelay: '<S249>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c42_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c42_swc_DIAG = 1U;
      if ((!macd_b_5VT1IntSmplFltSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S323>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
      } else if (macd_b_5VT1IntSmplFltSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S323>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_d2) {
        swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_cb = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_cb += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S323>/flg_out' incorporates:
         *  Constant: '<S8>/t_step2'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = true;
      } else {
        swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_cb = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_cb += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S323>/flg_out' incorporates:
         *  Constant: '<S8>/t_step2'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c42_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_5VT1IntSmplFltSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S323>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = true;
          } else {
            swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_cb = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_cb += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S323>/flg_out' incorporates:
             *  Constant: '<S8>/t_step2'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
          }
        } else {
          /* SignalConversion generated from: '<S323>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_5VT1IntSmplFltSet) {
          swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S323>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_cb > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S323>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_cb += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S323>/flg_out' incorporates:
           *  Constant: '<S8>/t_step2'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_5VT1IntSmplFltSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S323>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
          } else {
            swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_cb = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_cb += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S323>/flg_out' incorporates:
             *  Constant: '<S8>/t_step2'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = true;
          }
        } else {
          /* SignalConversion generated from: '<S323>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_5VT1IntSmplFltSet) {
          swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S323>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_cb > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c42_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S323>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_cb += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S323>/flg_out' incorporates:
           *  Constant: '<S8>/t_step2'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
        }
        break;
      }
    }

    /* End of Chart: '<S323>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_h) {
    /* Disable for Outport: '<S323>/flg_out' incorporates:
     *  SignalConversion generated from: '<S323>/flg_out'
     */
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_h = false;
    swc_DIAG_ARID_DEF.debounce_MODE_h = false;
  }

  /* End of Outputs for SubSystem: '<S249>/debounce' */

  /* CCaller: '<S287>/C Caller' incorporates:
   *  Constant: '<S8>/event_id2'
   *  DataTypeConversion: '<S8>/Data Type Conversion2'
   */
  Dem_SetEventStatus(((uint16)32878U),
                     swc_DIAG_ARID_DEF.OutportBufferForflg_out_h);

  /* Switch: '<S349>/Switch2' incorporates:
   *  Constant: '<S262>/macc_b_5VT2IntSmplFltSet_ovrdflg'
   *  Constant: '<S262>/macc_b_5VT2IntSmplFltSet_ovrdval'
   *  Constant: '<S8>/Constant314'
   *  Constant: '<S8>/Constant325'
   *  Logic: '<S8>/Logical Operator240'
   *  RelationalOperator: '<S8>/Relational Operator205'
   *  RelationalOperator: '<S8>/Relational Operator206'
   */
  if (macc_b_5VT2IntSmplFltSet_ovrdflg) {
    macd_b_5VT2IntSmplFltSet = macc_b_5VT2IntSmplFltSet_ovrdval;
  } else {
    macd_b_5VT2IntSmplFltSet = ((swc_DIAG_ARID_DEF.DataTypeConversion53 >
      macc_u_5VT2IntSmplFltSetHi_V) || (swc_DIAG_ARID_DEF.DataTypeConversion53 <
      macc_u_5VT2IntSmplFltSetLo_V));
  }

  /* End of Switch: '<S349>/Switch2' */

  /* Switch: '<S348>/Switch2' incorporates:
   *  Constant: '<S261>/macc_b_5VT2IntSmplFltEnb_ovrdflg'
   */
  if (macc_b_5VT2IntSmplFltEnb_ovrdflg) {
    /* Switch: '<S348>/Switch2' incorporates:
     *  Constant: '<S261>/macc_b_5VT2IntSmplFltEnb_ovrdval'
     */
    macd_b_5VT2IntSmplFltEnb = macc_b_5VT2IntSmplFltEnb_ovrdval;
  } else {
    /* Switch: '<S348>/Switch2' incorporates:
     *  Logic: '<S8>/Logical Operator237'
     */
    macd_b_5VT2IntSmplFltEnb = (rtb_LogicalOperator64 && rtb_LogicalOperator63_m
      && swc_DIAG_ARID_DEF.DataTypeConversion254);
  }

  /* End of Switch: '<S348>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S250>/debounce' incorporates:
   *  EnablePort: '<S325>/Enable'
   */
  if (macd_b_5VT2IntSmplFltEnb) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_c) {
      /* SystemReset for Chart: '<S325>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c43_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_mg = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_c = true;
    }

    /* Saturate: '<S325>/Saturation' incorporates:
     *  Constant: '<S8>/t_delay_fail3'
     */
    if (macc_b_5VT2IntSmplFltFail_s > 1.6777216E+7F) {
      /* Saturate: '<S325>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (macc_b_5VT2IntSmplFltFail_s < 0.0F) {
      /* Saturate: '<S325>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S325>/Saturation' */
      rtb_t_delay_on_ne = macc_b_5VT2IntSmplFltFail_s;
    }

    /* End of Saturate: '<S325>/Saturation' */

    /* Saturate: '<S325>/Saturation1' incorporates:
     *  Constant: '<S8>/t_delay_heal3'
     */
    if (macc_b_5VT2IntSmplFltHeal_s > 1.6777216E+7F) {
      /* Saturate: '<S325>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (macc_b_5VT2IntSmplFltHeal_s < 0.0F) {
      /* Saturate: '<S325>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S325>/Saturation1' */
      rtb_t_delay_off_l = macc_b_5VT2IntSmplFltHeal_s;
    }

    /* End of Saturate: '<S325>/Saturation1' */

    /* Chart: '<S325>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step3'
     *  DataTypeConversion: '<S325>/Data Type Conversion'
     *  UnitDelay: '<S250>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c43_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c43_swc_DIAG = 1U;
      if ((!macd_b_5VT2IntSmplFltSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S325>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
      } else if (macd_b_5VT2IntSmplFltSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S325>/flg_out' */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_kq) {
        swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_mg = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_mg += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S325>/flg_out' incorporates:
         *  Constant: '<S8>/t_step3'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out = true;
      } else {
        swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_mg = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_mg += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S325>/flg_out' incorporates:
         *  Constant: '<S8>/t_step3'
         */
        swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c43_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_5VT2IntSmplFltSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S325>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out = true;
          } else {
            swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_mg = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_mg += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S325>/flg_out' incorporates:
             *  Constant: '<S8>/t_step3'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
          }
        } else {
          /* SignalConversion generated from: '<S325>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_5VT2IntSmplFltSet) {
          swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S325>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_mg > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S325>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_mg += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S325>/flg_out' incorporates:
           *  Constant: '<S8>/t_step3'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_5VT2IntSmplFltSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S325>/flg_out' */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
          } else {
            swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_mg = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_mg += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S325>/flg_out' incorporates:
             *  Constant: '<S8>/t_step3'
             */
            swc_DIAG_ARID_DEF.OutportBufferForflg_out = true;
          }
        } else {
          /* SignalConversion generated from: '<S325>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_5VT2IntSmplFltSet) {
          swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S325>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_mg > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c43_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S325>/flg_out' */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_mg += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S325>/flg_out' incorporates:
           *  Constant: '<S8>/t_step3'
           */
          swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
        }
        break;
      }
    }

    /* End of Chart: '<S325>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_c) {
    /* Disable for Outport: '<S325>/flg_out' incorporates:
     *  SignalConversion generated from: '<S325>/flg_out'
     */
    swc_DIAG_ARID_DEF.OutportBufferForflg_out = false;
    swc_DIAG_ARID_DEF.debounce_MODE_c = false;
  }

  /* End of Outputs for SubSystem: '<S250>/debounce' */

  /* CCaller: '<S288>/C Caller' incorporates:
   *  Constant: '<S8>/event_id3'
   *  DataTypeConversion: '<S8>/Data Type Conversion3'
   */
  Dem_SetEventStatus(((uint16)32879U), swc_DIAG_ARID_DEF.OutportBufferForflg_out);

  /* Switch: '<S352>/Switch2' incorporates:
   *  Constant: '<S265>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_PEPSMsgErrSet_ovrdflg) {
    /* Switch: '<S352>/Switch2' incorporates:
     *  Constant: '<S265>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_PEPSMsgErrSet = macc_b_PEPSMsgErrSet_ovrdval;
  } else {
    /* Switch: '<S352>/Switch2' incorporates:
     *  Inport generated from: '<Root>/vild_b_flgPEPSAlvErr'
     *  Inport generated from: '<Root>/vild_b_flgPEPSCsmErr'
     *  Inport generated from: '<Root>/vild_b_flgPEPSMsgErr'
     *  Logic: '<S8>/OR2'
     */
    macd_b_PEPSMsgErrSet =
      (Rte_IRead_swc_DIAG_Step_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr() ||
       Rte_IRead_swc_DIAG_Step_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr() ||
       Rte_IRead_swc_DIAG_Step_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr());
  }

  /* End of Switch: '<S352>/Switch2' */

  /* Logic: '<S8>/Logical Operator18' incorporates:
   *  Logic: '<S8>/Logical Operator1'
   *  Logic: '<S8>/Logical Operator3'
   *  Logic: '<S8>/Logical Operator4'
   */
  tmp = (rtb_LogicalOperator64 && rtb_LogicalOperator63_m);

  /* Outputs for Enabled SubSystem: '<S245>/debounce' incorporates:
   *  EnablePort: '<S315>/Enable'
   */
  if (tmp && rtb_LogicalOperator4_c_tmp_tmp && swc_DIAG_ARID_DEF.LogicalOperator
      && swc_DIAG_ARID_DEF.flg_out_h) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_pa) {
      /* SystemReset for Chart: '<S315>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c40_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_mt = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_pa = true;
    }

    /* Saturate: '<S315>/Saturation' incorporates:
     *  Constant: '<S8>/Constant2'
     */
    if (digc_PEPSMsgErr2fail_s > 1.6777216E+7F) {
      /* Saturate: '<S315>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_PEPSMsgErr2fail_s < 0.0F) {
      /* Saturate: '<S315>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S315>/Saturation' */
      rtb_t_delay_on_ne = digc_PEPSMsgErr2fail_s;
    }

    /* End of Saturate: '<S315>/Saturation' */

    /* Saturate: '<S315>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant3'
     */
    if (digc_PEPSMsgErr2heal_s > 1.6777216E+7F) {
      /* Saturate: '<S315>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_PEPSMsgErr2heal_s < 0.0F) {
      /* Saturate: '<S315>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S315>/Saturation1' */
      rtb_t_delay_off_l = digc_PEPSMsgErr2heal_s;
    }

    /* End of Saturate: '<S315>/Saturation1' */

    /* Chart: '<S315>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step4'
     *  DataTypeConversion: '<S315>/Data Type Conversion'
     *  UnitDelay: '<S245>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c40_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c40_swc_DIAG = 1U;
      if ((!macd_b_PEPSMsgErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S315>/flg_out' */
        macd_b_PEPSMsgErrDebd = false;
      } else if (macd_b_PEPSMsgErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S315>/flg_out' */
        macd_b_PEPSMsgErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_f) {
        swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_mt = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_mt += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S315>/flg_out' incorporates:
         *  Constant: '<S8>/t_step4'
         */
        macd_b_PEPSMsgErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_mt = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_mt += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S315>/flg_out' incorporates:
         *  Constant: '<S8>/t_step4'
         */
        macd_b_PEPSMsgErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c40_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_PEPSMsgErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S315>/flg_out' */
            macd_b_PEPSMsgErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_mt = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_mt += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S315>/flg_out' incorporates:
             *  Constant: '<S8>/t_step4'
             */
            macd_b_PEPSMsgErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S315>/flg_out' */
          macd_b_PEPSMsgErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_PEPSMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S315>/flg_out' */
          macd_b_PEPSMsgErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_mt > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S315>/flg_out' */
          macd_b_PEPSMsgErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_mt += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S315>/flg_out' incorporates:
           *  Constant: '<S8>/t_step4'
           */
          macd_b_PEPSMsgErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_PEPSMsgErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S315>/flg_out' */
            macd_b_PEPSMsgErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_mt = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_mt += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S315>/flg_out' incorporates:
             *  Constant: '<S8>/t_step4'
             */
            macd_b_PEPSMsgErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S315>/flg_out' */
          macd_b_PEPSMsgErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_PEPSMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S315>/flg_out' */
          macd_b_PEPSMsgErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_mt > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c40_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S315>/flg_out' */
          macd_b_PEPSMsgErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_mt += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S315>/flg_out' incorporates:
           *  Constant: '<S8>/t_step4'
           */
          macd_b_PEPSMsgErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S315>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_pa) {
    /* Disable for SignalConversion generated from: '<S315>/flg_out' incorporates:
     *  Outport: '<S315>/flg_out'
     */
    macd_b_PEPSMsgErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_pa = false;
  }

  /* End of Logic: '<S8>/Logical Operator18' */
  /* End of Outputs for SubSystem: '<S245>/debounce' */

  /* CCaller: '<S289>/C Caller' incorporates:
   *  Constant: '<S8>/Constant4'
   *  DataTypeConversion: '<S8>/Data Type Conversion4'
   */
  Dem_SetEventStatus(((uint16)32945U), macd_b_PEPSMsgErrDebd);

  /* Switch: '<S358>/Switch2' incorporates:
   *  Constant: '<S271>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_evCANBusoffSet_ovrdflg) {
    /* Switch: '<S358>/Switch2' incorporates:
     *  Constant: '<S271>/macc_b_batIntSmplHiSet_ovrdval'
     */
    rtb_Switch2 = macc_b_evCANBusoffSet_ovrdval;
  } else {
    /* Switch: '<S358>/Switch2' incorporates:
     *  Constant: '<S233>/Constant'
     *  Logic: '<S8>/AND1'
     *  RelationalOperator: '<S233>/Compare'
     */
    rtb_Switch2 = (swc_DIAG_ARID_DEF.DataTypeConversion13 &&
                   (swc_DIAG_ARID_DEF.DataTypeConversion20 > 3.0));
  }

  /* End of Switch: '<S358>/Switch2' */

  /* Switch: '<S357>/Switch2' incorporates:
   *  Constant: '<S270>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_evCANBusoffSet_ovrdflg) {
    /* Switch: '<S357>/Switch2' incorporates:
     *  Constant: '<S270>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_evCANBusoffSet = macc_b_evCANBusoffSet_ovrdval;
  } else {
    /* Switch: '<S357>/Switch2' incorporates:
     *  Constant: '<S234>/Constant'
     *  Logic: '<S8>/AND2'
     *  RelationalOperator: '<S234>/Compare'
     */
    macd_b_evCANBusoffSet = ((swc_DIAG_ARID_DEF.DataTypeConversion20 <= 3.0) &&
      swc_DIAG_ARID_DEF.DataTypeConversion13);
  }

  /* End of Switch: '<S357>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S243>/debounce' incorporates:
   *  EnablePort: '<S311>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S242>/debounce' incorporates:
   *  EnablePort: '<S309>/Enable'
   */
  /* Logic: '<S8>/Logical Operator2' */
  if (swc_DIAG_ARID_DEF.flg_out && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_j3) {
      /* SystemReset for Chart: '<S309>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c9_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_d = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_j3 = true;
    }

    /* Saturate: '<S309>/Saturation' incorporates:
     *  Constant: '<S8>/Constant243'
     */
    if (digc_evCanBusOfffail_s > 1.6777216E+7F) {
      /* Saturate: '<S309>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_evCanBusOfffail_s < 0.0F) {
      /* Saturate: '<S309>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S309>/Saturation' */
      rtb_t_delay_on_ne = digc_evCanBusOfffail_s;
    }

    /* End of Saturate: '<S309>/Saturation' */

    /* Saturate: '<S309>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant244'
     */
    if (digc_evCanBusOffheal_s > 1.6777216E+7F) {
      /* Saturate: '<S309>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_evCanBusOffheal_s < 0.0F) {
      /* Saturate: '<S309>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S309>/Saturation1' */
      rtb_t_delay_off_l = digc_evCanBusOffheal_s;
    }

    /* End of Saturate: '<S309>/Saturation1' */

    /* Chart: '<S309>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step173'
     *  DataTypeConversion: '<S309>/Data Type Conversion'
     *  UnitDelay: '<S242>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c9_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c9_swc_DIAG = 1U;
      if ((!rtb_Switch2) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S309>/flg_out' */
        digd_b_vcuLvl21Flt_MAC = false;
      } else if (rtb_Switch2 && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S309>/flg_out' */
        digd_b_vcuLvl21Flt_MAC = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_mn) {
        swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_d = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_d += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S309>/flg_out' incorporates:
         *  Constant: '<S8>/t_step173'
         */
        digd_b_vcuLvl21Flt_MAC = true;
      } else {
        swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_d = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_d += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S309>/flg_out' incorporates:
         *  Constant: '<S8>/t_step173'
         */
        digd_b_vcuLvl21Flt_MAC = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c9_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (rtb_Switch2) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S309>/flg_out' */
            digd_b_vcuLvl21Flt_MAC = true;
          } else {
            swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_d = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_d += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S309>/flg_out' incorporates:
             *  Constant: '<S8>/t_step173'
             */
            digd_b_vcuLvl21Flt_MAC = false;
          }
        } else {
          /* SignalConversion generated from: '<S309>/flg_out' */
          digd_b_vcuLvl21Flt_MAC = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (rtb_Switch2) {
          swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S309>/flg_out' */
          digd_b_vcuLvl21Flt_MAC = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_d > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S309>/flg_out' */
          digd_b_vcuLvl21Flt_MAC = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_d += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S309>/flg_out' incorporates:
           *  Constant: '<S8>/t_step173'
           */
          digd_b_vcuLvl21Flt_MAC = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!rtb_Switch2) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S309>/flg_out' */
            digd_b_vcuLvl21Flt_MAC = false;
          } else {
            swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_d = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_d += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S309>/flg_out' incorporates:
             *  Constant: '<S8>/t_step173'
             */
            digd_b_vcuLvl21Flt_MAC = true;
          }
        } else {
          /* SignalConversion generated from: '<S309>/flg_out' */
          digd_b_vcuLvl21Flt_MAC = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!rtb_Switch2) {
          swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S309>/flg_out' */
          digd_b_vcuLvl21Flt_MAC = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_d > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c9_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S309>/flg_out' */
          digd_b_vcuLvl21Flt_MAC = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_d += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S309>/flg_out' incorporates:
           *  Constant: '<S8>/t_step173'
           */
          digd_b_vcuLvl21Flt_MAC = false;
        }
        break;
      }
    }

    /* End of Chart: '<S309>/timed_debounce' */
    if (!swc_DIAG_ARID_DEF.debounce_MODE_k) {
      /* SystemReset for Chart: '<S311>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c61_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_ph = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_k = true;
    }

    /* Saturate: '<S311>/Saturation' incorporates:
     *  Constant: '<S8>/Constant1'
     */
    if (digc_evCanBusOfffail_s > 1.6777216E+7F) {
      /* Saturate: '<S311>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_evCanBusOfffail_s < 0.0F) {
      /* Saturate: '<S311>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S311>/Saturation' */
      rtb_t_delay_on_ne = digc_evCanBusOfffail_s;
    }

    /* End of Saturate: '<S311>/Saturation' */

    /* Saturate: '<S311>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant5'
     */
    if (digc_evCanBusOffheal_s > 1.6777216E+7F) {
      /* Saturate: '<S311>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_evCanBusOffheal_s < 0.0F) {
      /* Saturate: '<S311>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S311>/Saturation1' */
      rtb_t_delay_off_l = digc_evCanBusOffheal_s;
    }

    /* End of Saturate: '<S311>/Saturation1' */

    /* Chart: '<S311>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step9'
     *  DataTypeConversion: '<S311>/Data Type Conversion'
     *  UnitDelay: '<S243>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c61_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c61_swc_DIAG = 1U;
      if ((!macd_b_evCANBusoffSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S311>/flg_out' */
        macd_b_evCANBusoffDebd = false;
      } else if (macd_b_evCANBusoffSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S311>/flg_out' */
        macd_b_evCANBusoffDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_l) {
        swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_ph = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ph += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S311>/flg_out' incorporates:
         *  Constant: '<S8>/t_step9'
         */
        macd_b_evCANBusoffDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_ph = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ph += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S311>/flg_out' incorporates:
         *  Constant: '<S8>/t_step9'
         */
        macd_b_evCANBusoffDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c61_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_evCANBusoffSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S311>/flg_out' */
            macd_b_evCANBusoffDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_ph = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ph += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S311>/flg_out' incorporates:
             *  Constant: '<S8>/t_step9'
             */
            macd_b_evCANBusoffDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S311>/flg_out' */
          macd_b_evCANBusoffDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_evCANBusoffSet) {
          swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S311>/flg_out' */
          macd_b_evCANBusoffDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_ph > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S311>/flg_out' */
          macd_b_evCANBusoffDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ph += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S311>/flg_out' incorporates:
           *  Constant: '<S8>/t_step9'
           */
          macd_b_evCANBusoffDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_evCANBusoffSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S311>/flg_out' */
            macd_b_evCANBusoffDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_ph = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ph += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S311>/flg_out' incorporates:
             *  Constant: '<S8>/t_step9'
             */
            macd_b_evCANBusoffDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S311>/flg_out' */
          macd_b_evCANBusoffDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_evCANBusoffSet) {
          swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S311>/flg_out' */
          macd_b_evCANBusoffDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_ph > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c61_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S311>/flg_out' */
          macd_b_evCANBusoffDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ph += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S311>/flg_out' incorporates:
           *  Constant: '<S8>/t_step9'
           */
          macd_b_evCANBusoffDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S311>/timed_debounce' */
  } else {
    if (swc_DIAG_ARID_DEF.debounce_MODE_j3) {
      /* Disable for SignalConversion generated from: '<S309>/flg_out' incorporates:
       *  Outport: '<S309>/flg_out'
       */
      digd_b_vcuLvl21Flt_MAC = false;
      swc_DIAG_ARID_DEF.debounce_MODE_j3 = false;
    }

    if (swc_DIAG_ARID_DEF.debounce_MODE_k) {
      /* Disable for SignalConversion generated from: '<S311>/flg_out' incorporates:
       *  Outport: '<S311>/flg_out'
       */
      macd_b_evCANBusoffDebd = false;
      swc_DIAG_ARID_DEF.debounce_MODE_k = false;
    }
  }

  /* End of Logic: '<S8>/Logical Operator2' */
  /* End of Outputs for SubSystem: '<S242>/debounce' */
  /* End of Outputs for SubSystem: '<S243>/debounce' */

  /* Logic: '<S254>/OR1' incorporates:
   *  Constant: '<S337>/Constant'
   *  Constant: '<S338>/Constant'
   *  Constant: '<S339>/Constant'
   *  Constant: '<S340>/Constant'
   *  Constant: '<S341>/Constant'
   *  Logic: '<S254>/AND2'
   *  RelationalOperator: '<S337>/Compare'
   *  RelationalOperator: '<S338>/Compare'
   *  RelationalOperator: '<S339>/Compare'
   *  RelationalOperator: '<S340>/Compare'
   *  RelationalOperator: '<S341>/Compare'
   */
  rtb_OR1_o = (((swc_DIAG_ARID_DEF.DataTypeConversion254 == false) &&
                (swc_DIAG_ARID_DEF.DataTypeConversion82 == false) &&
                (swc_DIAG_ARID_DEF.DataTypeConversion123 == false) &&
                (swc_DIAG_ARID_DEF.DataTypeConversion33 != 1.0)) ||
               (rtb_OR1_j_tmp == true));

  /* Outputs for Atomic SubSystem: '<S8>/SR_latch2' */
  swc_DIAG_SR_latch2(macd_b_evCANBusoffDebd, rtb_OR1_o,
                     &swc_DIAG_ARID_DEF.LogicalOperator3,
                     &swc_DIAG_ARID_DEF.ARID_DEF_SR_latch2);

  /* End of Outputs for SubSystem: '<S8>/SR_latch2' */

  /* CCaller: '<S290>/C Caller' incorporates:
   *  Constant: '<S8>/event_id6'
   *  DataTypeConversion: '<S8>/Data Type Conversion5'
   *  Logic: '<S8>/OR7'
   */
  Dem_SetEventStatus(((uint16)32892U), (uint8)(digd_b_vcuLvl21Flt_MAC ||
    swc_DIAG_ARID_DEF.LogicalOperator3));

  /* Outputs for Enabled SubSystem: '<S238>/debounce' incorporates:
   *  EnablePort: '<S301>/Enable'
   */
  /* Logic: '<S8>/Logical Operator1' */
  if (tmp && swc_DIAG_ARID_DEF.flg_out) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_o3) {
      /* SystemReset for Chart: '<S301>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c10_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_fi = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_o3 = true;
    }

    /* Saturate: '<S301>/Saturation' incorporates:
     *  Constant: '<S8>/Constant188'
     */
    if (digc_ptCanBusOfffail_s > 1.6777216E+7F) {
      /* Saturate: '<S301>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_ptCanBusOfffail_s < 0.0F) {
      /* Saturate: '<S301>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S301>/Saturation' */
      rtb_t_delay_on_ne = digc_ptCanBusOfffail_s;
    }

    /* End of Saturate: '<S301>/Saturation' */

    /* Saturate: '<S301>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant194'
     */
    if (digc_ptCanBusOffheal_s > 1.6777216E+7F) {
      /* Saturate: '<S301>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_ptCanBusOffheal_s < 0.0F) {
      /* Saturate: '<S301>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S301>/Saturation1' */
      rtb_t_delay_off_l = digc_ptCanBusOffheal_s;
    }

    /* End of Saturate: '<S301>/Saturation1' */

    /* Chart: '<S301>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step172'
     *  DataTypeConversion: '<S301>/Data Type Conversion'
     *  UnitDelay: '<S238>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c10_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c10_swc_DIAG = 1U;
      if ((!macd_b_ptCanBusOffSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S301>/flg_out' */
        macd_b_ptCanBusOffDebd = false;
      } else if (macd_b_ptCanBusOffSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S301>/flg_out' */
        macd_b_ptCanBusOffDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_la) {
        swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_fi = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_fi += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S301>/flg_out' incorporates:
         *  Constant: '<S8>/t_step172'
         */
        macd_b_ptCanBusOffDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_fi = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_fi += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S301>/flg_out' incorporates:
         *  Constant: '<S8>/t_step172'
         */
        macd_b_ptCanBusOffDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c10_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_ptCanBusOffSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S301>/flg_out' */
            macd_b_ptCanBusOffDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_fi = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_fi += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S301>/flg_out' incorporates:
             *  Constant: '<S8>/t_step172'
             */
            macd_b_ptCanBusOffDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S301>/flg_out' */
          macd_b_ptCanBusOffDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_ptCanBusOffSet) {
          swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S301>/flg_out' */
          macd_b_ptCanBusOffDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_fi > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S301>/flg_out' */
          macd_b_ptCanBusOffDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_fi += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S301>/flg_out' incorporates:
           *  Constant: '<S8>/t_step172'
           */
          macd_b_ptCanBusOffDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_ptCanBusOffSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S301>/flg_out' */
            macd_b_ptCanBusOffDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_fi = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_fi += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S301>/flg_out' incorporates:
             *  Constant: '<S8>/t_step172'
             */
            macd_b_ptCanBusOffDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S301>/flg_out' */
          macd_b_ptCanBusOffDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_ptCanBusOffSet) {
          swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S301>/flg_out' */
          macd_b_ptCanBusOffDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_fi > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c10_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S301>/flg_out' */
          macd_b_ptCanBusOffDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_fi += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S301>/flg_out' incorporates:
           *  Constant: '<S8>/t_step172'
           */
          macd_b_ptCanBusOffDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S301>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_o3) {
    /* Disable for SignalConversion generated from: '<S301>/flg_out' incorporates:
     *  Outport: '<S301>/flg_out'
     */
    macd_b_ptCanBusOffDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_o3 = false;
  }

  /* End of Outputs for SubSystem: '<S238>/debounce' */

  /* CCaller: '<S291>/C Caller' incorporates:
   *  Constant: '<S8>/event_id4'
   *  DataTypeConversion: '<S8>/Data Type Conversion6'
   */
  Dem_SetEventStatus(((uint16)32891U), macd_b_ptCanBusOffDebd);

  /* Outputs for Enabled SubSystem: '<S251>/debounce' incorporates:
   *  EnablePort: '<S327>/Enable'
   */
  /* Logic: '<S8>/Logical Operator3' */
  if (tmp && swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_aj) {
      /* SystemReset for Chart: '<S327>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c13_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_be = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_aj = true;
    }

    /* Saturate: '<S327>/Saturation' incorporates:
     *  Constant: '<S8>/Constant170'
     */
    if (digc_cCanBusOfffail_s > 1.6777216E+7F) {
      /* Saturate: '<S327>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_cCanBusOfffail_s < 0.0F) {
      /* Saturate: '<S327>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S327>/Saturation' */
      rtb_t_delay_on_ne = digc_cCanBusOfffail_s;
    }

    /* End of Saturate: '<S327>/Saturation' */

    /* Saturate: '<S327>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant174'
     */
    if (digc_cCanBusOffheal_s > 1.6777216E+7F) {
      /* Saturate: '<S327>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_cCanBusOffheal_s < 0.0F) {
      /* Saturate: '<S327>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S327>/Saturation1' */
      rtb_t_delay_off_l = digc_cCanBusOffheal_s;
    }

    /* End of Saturate: '<S327>/Saturation1' */

    /* Chart: '<S327>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step171'
     *  DataTypeConversion: '<S327>/Data Type Conversion'
     *  UnitDelay: '<S251>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c13_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c13_swc_DIAG = 1U;
      if ((!macd_b_cCanBusOffSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S327>/flg_out' */
        macd_b_cCanBusOffDebd = false;
      } else if (macd_b_cCanBusOffSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S327>/flg_out' */
        macd_b_cCanBusOffDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_ia) {
        swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_be = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_be += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S327>/flg_out' incorporates:
         *  Constant: '<S8>/t_step171'
         */
        macd_b_cCanBusOffDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_be = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_be += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S327>/flg_out' incorporates:
         *  Constant: '<S8>/t_step171'
         */
        macd_b_cCanBusOffDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c13_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_cCanBusOffSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S327>/flg_out' */
            macd_b_cCanBusOffDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_be = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_be += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S327>/flg_out' incorporates:
             *  Constant: '<S8>/t_step171'
             */
            macd_b_cCanBusOffDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S327>/flg_out' */
          macd_b_cCanBusOffDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_cCanBusOffSet) {
          swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S327>/flg_out' */
          macd_b_cCanBusOffDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_be > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S327>/flg_out' */
          macd_b_cCanBusOffDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_be += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S327>/flg_out' incorporates:
           *  Constant: '<S8>/t_step171'
           */
          macd_b_cCanBusOffDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_cCanBusOffSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S327>/flg_out' */
            macd_b_cCanBusOffDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_be = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_be += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S327>/flg_out' incorporates:
             *  Constant: '<S8>/t_step171'
             */
            macd_b_cCanBusOffDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S327>/flg_out' */
          macd_b_cCanBusOffDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_cCanBusOffSet) {
          swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S327>/flg_out' */
          macd_b_cCanBusOffDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_be > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c13_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S327>/flg_out' */
          macd_b_cCanBusOffDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_be += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S327>/flg_out' incorporates:
           *  Constant: '<S8>/t_step171'
           */
          macd_b_cCanBusOffDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S327>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_aj) {
    /* Disable for SignalConversion generated from: '<S327>/flg_out' incorporates:
     *  Outport: '<S327>/flg_out'
     */
    macd_b_cCanBusOffDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_aj = false;
  }

  /* End of Outputs for SubSystem: '<S251>/debounce' */

  /* CCaller: '<S292>/C Caller' incorporates:
   *  Constant: '<S8>/event_id5'
   *  DataTypeConversion: '<S8>/Data Type Conversion7'
   */
  Dem_SetEventStatus(((uint16)32936U), macd_b_cCanBusOffDebd);

  /* Switch: '<S360>/Switch2' incorporates:
   *  Constant: '<S273>/macc_b_batIntSmplHiSet_ovrdflg'
   *  Switch: '<S8>/Switch12'
   */
  if (macc_b_ABSMsgErrSet_ovrdflg) {
    /* Switch: '<S360>/Switch2' incorporates:
     *  Constant: '<S273>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_ABSMsgErrSet = macc_b_ABSMsgErrSet_ovrdval;
  } else if (swc_DIAG_ARID_DEF.DataTypeConversion117 > 0.0) {
    /* Switch: '<S8>/Switch12' incorporates:
     *  Switch: '<S360>/Switch2'
     */
    macd_b_ABSMsgErrSet = swc_DIAG_ARID_DEF.SignalConversion;
  } else {
    /* Switch: '<S360>/Switch2' incorporates:
     *  Switch: '<S8>/Switch12'
     */
    macd_b_ABSMsgErrSet = swc_DIAG_ARID_DEF.DataTypeConversion4;
  }

  /* End of Switch: '<S360>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S235>/debounce' incorporates:
   *  EnablePort: '<S295>/Enable'
   */
  /* Logic: '<S8>/Logical Operator6' incorporates:
   *  Logic: '<S8>/Logical Operator5'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m && rtb_LogicalOperator5_p_tmp_tmp &&
      swc_DIAG_ARID_DEF.LogicalOperator) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_jr) {
      /* SystemReset for Chart: '<S295>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c33_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_d1 = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_jr = true;
    }

    /* Saturate: '<S295>/Saturation' incorporates:
     *  Constant: '<S8>/Constant156'
     */
    if (digc_ABSMsgErr2fail_s > 1.6777216E+7F) {
      /* Saturate: '<S295>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_ABSMsgErr2fail_s < 0.0F) {
      /* Saturate: '<S295>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S295>/Saturation' */
      rtb_t_delay_on_ne = digc_ABSMsgErr2fail_s;
    }

    /* End of Saturate: '<S295>/Saturation' */

    /* Saturate: '<S295>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant157'
     */
    if (digc_ABSMsgErr2heal_s > 1.6777216E+7F) {
      /* Saturate: '<S295>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_ABSMsgErr2heal_s < 0.0F) {
      /* Saturate: '<S295>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S295>/Saturation1' */
      rtb_t_delay_off_l = digc_ABSMsgErr2heal_s;
    }

    /* End of Saturate: '<S295>/Saturation1' */

    /* Chart: '<S295>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step149'
     *  DataTypeConversion: '<S295>/Data Type Conversion'
     *  UnitDelay: '<S235>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c33_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c33_swc_DIAG = 1U;
      if ((!macd_b_ABSMsgErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S295>/flg_out' */
        macd_b_ABSMsgErrDebd = false;
      } else if (macd_b_ABSMsgErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S295>/flg_out' */
        macd_b_ABSMsgErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_dc) {
        swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_d1 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_d1 += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S295>/flg_out' incorporates:
         *  Constant: '<S8>/t_step149'
         */
        macd_b_ABSMsgErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_d1 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_d1 += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S295>/flg_out' incorporates:
         *  Constant: '<S8>/t_step149'
         */
        macd_b_ABSMsgErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c33_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_ABSMsgErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S295>/flg_out' */
            macd_b_ABSMsgErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_d1 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_d1 += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S295>/flg_out' incorporates:
             *  Constant: '<S8>/t_step149'
             */
            macd_b_ABSMsgErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S295>/flg_out' */
          macd_b_ABSMsgErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_ABSMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S295>/flg_out' */
          macd_b_ABSMsgErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_d1 > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S295>/flg_out' */
          macd_b_ABSMsgErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_d1 += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S295>/flg_out' incorporates:
           *  Constant: '<S8>/t_step149'
           */
          macd_b_ABSMsgErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_ABSMsgErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S295>/flg_out' */
            macd_b_ABSMsgErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_d1 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_d1 += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S295>/flg_out' incorporates:
             *  Constant: '<S8>/t_step149'
             */
            macd_b_ABSMsgErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S295>/flg_out' */
          macd_b_ABSMsgErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_ABSMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S295>/flg_out' */
          macd_b_ABSMsgErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_d1 > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c33_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S295>/flg_out' */
          macd_b_ABSMsgErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_d1 += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S295>/flg_out' incorporates:
           *  Constant: '<S8>/t_step149'
           */
          macd_b_ABSMsgErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S295>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_jr) {
    /* Disable for SignalConversion generated from: '<S295>/flg_out' incorporates:
     *  Outport: '<S295>/flg_out'
     */
    macd_b_ABSMsgErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_jr = false;
  }

  /* End of Logic: '<S8>/Logical Operator6' */
  /* End of Outputs for SubSystem: '<S235>/debounce' */

  /* CCaller: '<S293>/C Caller' incorporates:
   *  Constant: '<S8>/Constant158'
   *  DataTypeConversion: '<S8>/Data Type Conversion8'
   */
  Dem_SetEventStatus(((uint16)32894U), macd_b_ABSMsgErrDebd);

  /* Switch: '<S361>/Switch2' incorporates:
   *  Constant: '<S274>/macc_b_batIntSmplHiSet_ovrdflg'
   */
  if (macc_b_DCDCMsgErrSet_ovrdflg) {
    /* Switch: '<S361>/Switch2' incorporates:
     *  Constant: '<S274>/macc_b_batIntSmplHiSet_ovrdval'
     */
    macd_b_DCDCMsgErrSet = macc_b_DCDCMsgErrSet_ovrdval;
  } else {
    /* Switch: '<S361>/Switch2' */
    macd_b_DCDCMsgErrSet = swc_DIAG_ARID_DEF.DataTypeConversion10;
  }

  /* End of Switch: '<S361>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S240>/debounce' incorporates:
   *  EnablePort: '<S305>/Enable'
   */
  /* Logic: '<S8>/Logical Operator9' incorporates:
   *  Logic: '<S8>/Logical Operator4'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c && rtb_LogicalOperator64 &&
      rtb_LogicalOperator63_m && rtb_LogicalOperator4_c_tmp_tmp &&
      swc_DIAG_ARID_DEF.LogicalOperator) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_bk) {
      /* SystemReset for Chart: '<S305>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c37_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_b0;
      swc_DIAG_ARID_DEF.t_wait_i = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_bk = true;
    }

    /* Saturate: '<S305>/Saturation' incorporates:
     *  Constant: '<S8>/Constant175'
     */
    if (digc_DCDCMsgErr2fail_s > 1.6777216E+7F) {
      /* Saturate: '<S305>/Saturation' */
      rtb_t_delay_on_ne = 1.6777216E+7F;
    } else if (digc_DCDCMsgErr2fail_s < 0.0F) {
      /* Saturate: '<S305>/Saturation' */
      rtb_t_delay_on_ne = 0.0F;
    } else {
      /* Saturate: '<S305>/Saturation' */
      rtb_t_delay_on_ne = digc_DCDCMsgErr2fail_s;
    }

    /* End of Saturate: '<S305>/Saturation' */

    /* Saturate: '<S305>/Saturation1' incorporates:
     *  Constant: '<S8>/Constant176'
     */
    if (digc_DCDCMsgErr2heal_s > 1.6777216E+7F) {
      /* Saturate: '<S305>/Saturation1' */
      rtb_t_delay_off_l = 1.6777216E+7F;
    } else if (digc_DCDCMsgErr2heal_s < 0.0F) {
      /* Saturate: '<S305>/Saturation1' */
      rtb_t_delay_off_l = 0.0F;
    } else {
      /* Saturate: '<S305>/Saturation1' */
      rtb_t_delay_off_l = digc_DCDCMsgErr2heal_s;
    }

    /* End of Saturate: '<S305>/Saturation1' */

    /* Chart: '<S305>/timed_debounce' incorporates:
     *  Constant: '<S8>/t_step161'
     *  DataTypeConversion: '<S305>/Data Type Conversion'
     *  UnitDelay: '<S240>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c37_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c37_swc_DIAG = 1U;
      if ((!macd_b_DCDCMsgErrSet) && (rtb_t_delay_off_l == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_OFF_e;

        /* SignalConversion generated from: '<S305>/flg_out' */
        macd_b_DCDCMsgErrDebd = false;
      } else if (macd_b_DCDCMsgErrSet && (rtb_t_delay_on_ne == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_ON_kn;

        /* SignalConversion generated from: '<S305>/flg_out' */
        macd_b_DCDCMsgErrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_cl) {
        swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
        swc_DIAG_ARID_DEF.t_wait_i = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_i += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S305>/flg_out' incorporates:
         *  Constant: '<S8>/t_step161'
         */
        macd_b_DCDCMsgErrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
        swc_DIAG_ARID_DEF.t_wait_i = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_i += ((float32)MAC_TASK_INTERVAL_S);

        /* SignalConversion generated from: '<S305>/flg_out' incorporates:
         *  Constant: '<S8>/t_step161'
         */
        macd_b_DCDCMsgErrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c37_swc_DIAG) {
       case swc_DIAG_IN_OFF_e:
        if (macd_b_DCDCMsgErrSet) {
          if (rtb_t_delay_on_ne == 0.0F) {
            swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_ON_kn;

            /* SignalConversion generated from: '<S305>/flg_out' */
            macd_b_DCDCMsgErrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_ON_WAIT_g;
            swc_DIAG_ARID_DEF.t_wait_i = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_i += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S305>/flg_out' incorporates:
             *  Constant: '<S8>/t_step161'
             */
            macd_b_DCDCMsgErrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S305>/flg_out' */
          macd_b_DCDCMsgErrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_i:
        if (macd_b_DCDCMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S305>/flg_out' */
          macd_b_DCDCMsgErrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_i > rtb_t_delay_off_l - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S305>/flg_out' */
          macd_b_DCDCMsgErrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_i += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S305>/flg_out' incorporates:
           *  Constant: '<S8>/t_step161'
           */
          macd_b_DCDCMsgErrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_kn:
        if (!macd_b_DCDCMsgErrSet) {
          if (rtb_t_delay_off_l == 0.0F) {
            swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_OFF_e;

            /* SignalConversion generated from: '<S305>/flg_out' */
            macd_b_DCDCMsgErrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_OFF_WAIT_i;
            swc_DIAG_ARID_DEF.t_wait_i = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_i += ((float32)MAC_TASK_INTERVAL_S);

            /* SignalConversion generated from: '<S305>/flg_out' incorporates:
             *  Constant: '<S8>/t_step161'
             */
            macd_b_DCDCMsgErrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S305>/flg_out' */
          macd_b_DCDCMsgErrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!macd_b_DCDCMsgErrSet) {
          swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_OFF_e;

          /* SignalConversion generated from: '<S305>/flg_out' */
          macd_b_DCDCMsgErrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_i > rtb_t_delay_on_ne - ((float32)
                    MAC_TASK_INTERVAL_S)) {
          swc_DIAG_ARID_DEF.is_c37_swc_DIAG = swc_DIAG_IN_ON_kn;

          /* SignalConversion generated from: '<S305>/flg_out' */
          macd_b_DCDCMsgErrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_i += ((float32)MAC_TASK_INTERVAL_S);

          /* SignalConversion generated from: '<S305>/flg_out' incorporates:
           *  Constant: '<S8>/t_step161'
           */
          macd_b_DCDCMsgErrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S305>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_bk) {
    /* Disable for SignalConversion generated from: '<S305>/flg_out' incorporates:
     *  Outport: '<S305>/flg_out'
     */
    macd_b_DCDCMsgErrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_bk = false;
  }

  /* End of Logic: '<S8>/Logical Operator9' */
  /* End of Outputs for SubSystem: '<S240>/debounce' */

  /* CCaller: '<S294>/C Caller' incorporates:
   *  Constant: '<S8>/Constant177'
   *  DataTypeConversion: '<S8>/Data Type Conversion9'
   */
  Dem_SetEventStatus(((uint16)32896U), macd_b_DCDCMsgErrDebd);

  /* Logic: '<S8>/Logical Operator264' */
  digd_b_vcuLvl1Flt_MAC = (swc_DIAG_ARID_DEF.OutportBufferForflg_out_h ||
    swc_DIAG_ARID_DEF.OutportBufferForflg_out || macd_b_ABSMsgErrDebd ||
    macd_b_DCDCMsgErrDebd || macd_b_EGSMMsgErrDebd || macd_b_ABSSpdMsgErrDebd ||
    macd_b_ptCanBusOffDebd || macd_b_cCanBusOffDebd || macd_b_PEPSMsgErrDebd);

  /* Logic: '<S8>/Logical Operator271' */
  digd_b_vcuLvl31Flt_MAC = (macd_b_batIntSmplLoDebd || rtb_LogicalOperator3_aq ||
    swc_DIAG_ARID_DEF.LogicalOperator3);

  /* SignalConversion: '<S8>/Signal Conversion2' */
  macb_b_P2AD4 = macd_b_batIntSmplLoSet;

  /* SignalConversion: '<S8>/Signal Conversion3' */
  macb_b_P2AD5 = macd_b_batIntSmplHiSet;

  /* SignalConversion: '<S8>/Signal Conversion5' */
  swc_DIAG_ARID_DEF.SignalConversion5 = macd_b_EGSMMsgErrDebd;

  /* Logic: '<S8>/Logical Operator265' */
  digd_b_vcuLvl23Flt_MAC = false;

  /* Update for UnitDelay: '<S247>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_d4 =
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hs;

  /* Update for UnitDelay: '<S246>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_iw =
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_hso;

  /* Update for UnitDelay: '<S241>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_da = macd_b_EGSMMsgErrDebd;

  /* Update for UnitDelay: '<S237>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_nj = macd_b_BMSHealthMonErrDebd;

  /* Update for UnitDelay: '<S248>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_m = macd_b_ABSSpdMsgErrDebd;

  /* Update for UnitDelay: '<S236>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_cp = digd_b_ACUMsgErrDebd;

  /* Update for UnitDelay: '<S239>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_h = macd_b_CSMMsgErrDebd;

  /* Update for UnitDelay: '<S244>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_ov = macd_b_MCUHealthMonErrDebd;

  /* Update for UnitDelay: '<S249>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_d2 =
    swc_DIAG_ARID_DEF.OutportBufferForflg_out_h;

  /* Update for UnitDelay: '<S250>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_kq =
    swc_DIAG_ARID_DEF.OutportBufferForflg_out;

  /* Update for UnitDelay: '<S245>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_f = macd_b_PEPSMsgErrDebd;

  /* Update for UnitDelay: '<S242>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_mn = digd_b_vcuLvl21Flt_MAC;

  /* Update for UnitDelay: '<S243>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_l = macd_b_evCANBusoffDebd;

  /* Update for UnitDelay: '<S238>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_la = macd_b_ptCanBusOffDebd;

  /* Update for UnitDelay: '<S251>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_ia = macd_b_cCanBusOffDebd;

  /* Update for UnitDelay: '<S235>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_dc = macd_b_ABSMsgErrDebd;

  /* Update for UnitDelay: '<S240>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_cl = macd_b_DCDCMsgErrDebd;
}

/* Output and update for function-call system: '<S1>/Fault_Management' */
static void swc_DIAG_Fault_Management(void)
{
  /* Logic: '<S198>/Logical Operator' */
  digd_b_VehLvl21Flt_flgRaw = (digd_b_vcuLvl21Flt_MAC ||
    digd_b_vcuVehLvl21Flt_flg_HVB || digd_b_vcuVehLvl21Flt_flg_EAD);

  /* Switch: '<S198>/Switch1' incorporates:
   *  Constant: '<S198>/Constant2'
   */
  if (digd_b_VehLvl21Flt_ovrdflg) {
    /* Switch: '<S198>/Switch1' incorporates:
     *  Constant: '<S198>/Constant3'
     */
    digd_b_VehLvl21Flt_flg = digd_b_VehLvl21Flt_ovrdval;
  } else {
    /* Switch: '<S198>/Switch1' */
    digd_b_VehLvl21Flt_flg = digd_b_VehLvl21Flt_flgRaw;
  }

  /* End of Switch: '<S198>/Switch1' */

  /* Switch: '<S199>/Switch5' incorporates:
   *  Constant: '<S199>/Constant16'
   */
  if (digd_b_VehLvl22Flt_ovrdflg) {
    /* Switch: '<S199>/Switch5' incorporates:
     *  Constant: '<S199>/Constant17'
     */
    digd_b_VehLvl22Flt_flg = digd_b_VehLvl22Flt_ovrdval;
  } else {
    /* Switch: '<S199>/Switch5' */
    digd_b_VehLvl22Flt_flg = digd_b_vcuVehLvl22Flt_flg_BRP;
  }

  /* End of Switch: '<S199>/Switch5' */

  /* Switch: '<S200>/Switch6' incorporates:
   *  Constant: '<S200>/Constant18'
   */
  if (digd_b_VehLvl23Flt_ovrdflg) {
    /* Switch: '<S200>/Switch6' incorporates:
     *  Constant: '<S200>/Constant19'
     */
    digd_b_VehLvl23Flt_flg = digd_b_VehLvl23Flt_ovrdval;
  } else {
    /* Switch: '<S200>/Switch6' incorporates:
     *  Logic: '<S200>/Logical Operator'
     */
    digd_b_VehLvl23Flt_flg = (digd_b_vcuVehLvl23Flt_flg_ACP ||
      digd_b_vcuLvl23Flt_MAC);
  }

  /* End of Switch: '<S200>/Switch6' */

  /* Switch: '<S201>/Switch2' incorporates:
   *  Constant: '<S201>/Constant7'
   */
  if (digd_b_VehLvl31Flt_ovrdflg) {
    /* Switch: '<S201>/Switch2' incorporates:
     *  Constant: '<S201>/Constant8'
     */
    digd_b_VehLvl31Flt_flg = digd_b_VehLvl31Flt_ovrdval;
  } else {
    /* Switch: '<S201>/Switch2' incorporates:
     *  Logic: '<S201>/Logical Operator'
     */
    digd_b_VehLvl31Flt_flg = (digd_b_vcuLvl31Flt_MAC ||
      digd_b_vcuVehLvl31Flt_flg_EAD);
  }

  /* End of Switch: '<S201>/Switch2' */

  /* Switch: '<S202>/Switch3' incorporates:
   *  Constant: '<S202>/Constant9'
   */
  if (digd_b_VehLvl32Flt_ovrdflg) {
    /* Switch: '<S202>/Switch3' incorporates:
     *  Constant: '<S202>/Constant10'
     */
    digd_b_VehLvl32Flt_flg = digd_b_VehLvl32Flt_ovrdval;
  } else {
    /* Switch: '<S202>/Switch3' */
    digd_b_VehLvl32Flt_flg = digd_b_vcuVehLvl32Flt_flg_HVB;
  }

  /* End of Switch: '<S202>/Switch3' */

  /* Switch: '<S203>/Switch4' incorporates:
   *  Constant: '<S203>/Constant2'
   */
  if (digd_b_VehLvl33Flt_ovrdflg) {
    /* Switch: '<S203>/Switch4' incorporates:
     *  Constant: '<S203>/Constant12'
     */
    digd_b_VehLvl33Flt_flg = digd_b_VehLvl33Flt_ovrdval;
  } else {
    /* Switch: '<S203>/Switch4' incorporates:
     *  Logic: '<S203>/Logical Operator1'
     */
    digd_b_VehLvl33Flt_flg = (digd_b_vcuVehLvl33Flt_flg_CES ||
      digd_b_vcuVehLvl33Flt_flg_HVB);
  }

  /* End of Switch: '<S203>/Switch4' */

  /* Logic: '<S197>/Logical Operator1' */
  digd_b_VehLvl1Flt_flgRaw = (digd_b_vcuVehLvl1Flt_flg_ACP ||
    digd_b_vcuVehLvl1Flt_flg_HVB || digd_b_vcuLvl1Flt_MAC ||
    digd_b_vcuLvl1Flt_THM || brpd_b_VpEnOvTmHiPreDebd);

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S197>/Constant5'
   */
  if (digd_b_VehLvl1Flt_ovrdflg) {
    /* Switch: '<S197>/Switch' incorporates:
     *  Constant: '<S197>/Constant6'
     */
    digd_b_VehLvl1Flt_flg = digd_b_VehLvl1Flt_ovrdval;
  } else {
    /* Switch: '<S197>/Switch' */
    digd_b_VehLvl1Flt_flg = digd_b_VehLvl1Flt_flgRaw;
  }

  /* End of Switch: '<S197>/Switch' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Logic: '<S6>/Logical Operator4'
   *  Logic: '<S6>/OR'
   *  Switch: '<S6>/Switch1'
   *  Switch: '<S6>/Switch2'
   *  Switch: '<S6>/Switch3'
   */
  if (digd_b_VehLvl33Flt_flg) {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant'
     */
    digd_st_vehSysErrLevel = ((uint8)4U);
  } else if (digd_b_VehLvl31Flt_flg || digd_b_VehLvl32Flt_flg) {
    /* Switch: '<S6>/Switch1' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Switch: '<S6>/Switch'
     */
    digd_st_vehSysErrLevel = ((uint8)3U);
  } else if (digd_b_VehLvl21Flt_flg || digd_b_VehLvl22Flt_flg ||
             digd_b_VehLvl23Flt_flg) {
    /* Switch: '<S6>/Switch2' incorporates:
     *  Constant: '<S6>/Constant4'
     *  Switch: '<S6>/Switch'
     *  Switch: '<S6>/Switch1'
     */
    digd_st_vehSysErrLevel = ((uint8)2U);
  } else if (digd_b_VehLvl1Flt_flg) {
    /* Switch: '<S6>/Switch3' incorporates:
     *  Constant: '<S6>/Constant5'
     *  Switch: '<S6>/Switch'
     *  Switch: '<S6>/Switch1'
     *  Switch: '<S6>/Switch2'
     */
    digd_st_vehSysErrLevel = ((uint8)1U);
  } else {
    /* Switch: '<S6>/Switch' incorporates:
     *  Constant: '<S6>/Constant8'
     *  Switch: '<S6>/Switch1'
     *  Switch: '<S6>/Switch2'
     *  Switch: '<S6>/Switch3'
     */
    digd_st_vehSysErrLevel = ((uint8)0U);
  }

  /* End of Switch: '<S6>/Switch' */
}

/* Model step function */
void swc_DIAG_Step(void)
{
  /* local block i/o variables */
  boolean rtb_OR_gp;
  boolean rtb_OR2_i;
  boolean rtb_OR3_m;
  boolean rtb_flg_out_nk;
  PmmStatus rtb_DataTypeConversion29;
  float32 rtb_DataTypeConversion1_j;
  float32 rtb_DataTypeConversion71;
  float32 rtb_t_delay_off_bv3;
  float32 rtb_t_delay_on_cn;
  boolean rtb_OR_gp_tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in1'
   */
  rtb_DataTypeConversion1_j =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_pct_WatPmpEP1FbPWM();

  /* DataTypeConversion: '<Root>/Data Type Conversion71' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in8'
   */
  rtb_DataTypeConversion71 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_pct_WatPmpEP2FbPWM();

  /* DataTypeConversion: '<Root>/Data Type Conversion254' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in192'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion254 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_pmmd_b_ignOn();

  /* DataTypeConversion: '<Root>/Data Type Conversion123' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in41'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion123 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_obcd_b_obcWakeUp();

  /* Logic: '<S9>/OR' incorporates:
   *  Logic: '<S9>/OR1'
   */
  rtb_OR_gp_tmp = (swc_DIAG_ARID_DEF.DataTypeConversion254 ||
                   swc_DIAG_ARID_DEF.DataTypeConversion123);

  /* Logic: '<S9>/OR' */
  rtb_OR_gp = rtb_OR_gp_tmp;

  /* Outputs for Atomic SubSystem: '<S365>/turnON_delay5' */
  /* Constant: '<S365>/Constant198' incorporates:
   *  Constant: '<S365>/t_step175'
   */
  swc_DIAG_turnON_delay(rtb_OR_gp, macc_tm_ignOnDeb_s, ((float32)
    MAC_TASK_INTERVAL_S), &swc_DIAG_ARID_DEF.flg_out_c,
                        &swc_DIAG_ARID_DEF.ARID_DEF_turnON_delay5_c);

  /* End of Outputs for SubSystem: '<S365>/turnON_delay5' */

  /* DataTypeConversion: '<Root>/Data Type Conversion51' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in42'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion51 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_macd_u_batIntSmpl_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion52' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in43'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion52 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_u_5VT1IntSmpl_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion53' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in44'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion53 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_u_5VT2IntSmpl_V();

  /* DataTypeConversion: '<Root>/Data Type Conversion14' incorporates:
   *  Inport generated from: '<Root>/vild_b_adcCanBusOff'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion14 =
    Rte_IRead_swc_DIAG_Step_vild_b_adcCanBusOff_vild_b_adcCanBusOff();

  /* DataTypeConversion: '<Root>/Data Type Conversion84' incorporates:
   *  Inport generated from: '<Root>/vild_b_pmsCanBusOff'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion84 =
    Rte_IRead_swc_DIAG_Step_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff();

  /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
   *  Inport generated from: '<Root>/vild_b_flgABSMsgErr'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion4 =
    Rte_IRead_swc_DIAG_Step_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr();

  /* DataTypeConversion: '<Root>/Data Type Conversion10' incorporates:
   *  Inport generated from: '<Root>/vild_b_flgDCDCMsgErr'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion10 =
    Rte_IRead_swc_DIAG_Step_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr();

  /* DataTypeConversion: '<Root>/Data Type Conversion12' incorporates:
   *  Inport generated from: '<Root>/vild_b_flgEGSMMsgErr'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion12 =
    Rte_IRead_swc_DIAG_Step_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr();

  /* SignalConversion: '<S1>/Signal Conversion' incorporates:
   *  Inport generated from: '<Root>/vild_b_flgABSSpdMsgErr'
   */
  swc_DIAG_ARID_DEF.SignalConversion =
    Rte_IRead_swc_DIAG_Step_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr();

  /* DataTypeConversion: '<Root>/Data Type Conversion13' incorporates:
   *  Inport generated from: '<Root>/vild_b_evCanBusOff'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion13 =
    Rte_IRead_swc_DIAG_Step_vild_b_evCanBusOff_vild_b_evCanBusOff();

  /* DataTypeConversion: '<Root>/Data Type Conversion117' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in16'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion117 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_b_flgNetConfgABS();

  /* DataTypeConversion: '<Root>/Data Type Conversion82' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in69'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion82 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw();

  /* DataTypeConversion: '<Root>/Data Type Conversion20' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in4'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion20 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vscd_v_vehSpd_kph();

  /* DataTypeConversion: '<Root>/Data Type Conversion23' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in5'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion23 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_b_flgFctCfgACU();

  /* Outputs for Atomic SubSystem: '<S364>/turnON_delay5' */
  /* Constant: '<S364>/Constant198' incorporates:
   *  Constant: '<S364>/t_step175'
   */
  swc_DIAG_turnON_delay(swc_DIAG_ARID_DEF.DataTypeConversion254,
                        macc_tm_ignOnDeb_s, ((float32)MAC_TASK_INTERVAL_S),
                        &swc_DIAG_ARID_DEF.flg_out_h,
                        &swc_DIAG_ARID_DEF.ARID_DEF_turnON_delay5_k);

  /* End of Outputs for SubSystem: '<S364>/turnON_delay5' */

  /* Logic: '<S9>/OR1' incorporates:
   *  Logic: '<S9>/OR2'
   */
  rtb_OR_gp_tmp = (rtb_OR_gp_tmp || swc_DIAG_ARID_DEF.DataTypeConversion82);
  swc_DIAG_ARID_DEF.OR1 = rtb_OR_gp_tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion33' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in7'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion33 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_st_bmsDlyDataUpldEnb();

  /* Logic: '<S9>/OR2' incorporates:
   *  Constant: '<S363>/Constant'
   *  RelationalOperator: '<S363>/Compare'
   */
  rtb_OR2_i = (rtb_OR_gp_tmp || (swc_DIAG_ARID_DEF.DataTypeConversion33 == 1.0));

  /* Outputs for Atomic SubSystem: '<S367>/turnON_delay5' */
  /* Constant: '<S367>/Constant198' incorporates:
   *  Constant: '<S367>/t_step175'
   */
  swc_DIAG_turnON_delay(rtb_OR2_i, macc_tm_ignOnDeb_s, ((float32)
    MAC_TASK_INTERVAL_S), &swc_DIAG_ARID_DEF.flg_out,
                        &swc_DIAG_ARID_DEF.ARID_DEF_turnON_delay5);

  /* End of Outputs for SubSystem: '<S367>/turnON_delay5' */

  /* DataTypeConversion: '<Root>/Data Type Conversion93' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in76'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion93 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_hvbd_b_hvilOpen();

  /* DataTypeConversion: '<Root>/Data Type Conversion182' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in166'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion182 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_st_hvbStsDischgFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion24' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in6'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion24 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_st_hvbDischgFltReq();

  /* DataTypeConversion: '<Root>/Data Type Conversion183' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in77'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion183 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_eadd_e_inv2FltSts();

  /* DataTypeConversion: '<Root>/Data Type Conversion22' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in18'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion22 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_cesd_b_crash();

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in2'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion2 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_b_brkSwt1Actv();

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in3'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion3 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_b_brkSwt2Actv();

  /* DataTypeConversion: '<Root>/Data Type Conversion16' incorporates:
   *  Inport generated from: '<Root>/In Bus Element101'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion16 =
    Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpLoPreFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion25' incorporates:
   *  Inport generated from: '<Root>/In Bus Element3'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion25 =
    Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpSnrFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion27' incorporates:
   *  Inport generated from: '<Root>/In Bus Element1'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion27 =
    Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion28' incorporates:
   *  Inport generated from: '<Root>/In Bus Element2'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion28 =
    Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion30' incorporates:
   *  Inport generated from: '<Root>/In Bus Element4'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion30 =
    Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpSysFailFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion31' incorporates:
   *  Inport generated from: '<Root>/In Bus Element5'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion31 =
    Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpRlyFlt();

  /* DataTypeConversion: '<Root>/Data Type Conversion252' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in190'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion252 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_u_Acc1Raw_mV();

  /* DataTypeConversion: '<Root>/Data Type Conversion253' incorporates:
   *  Inport generated from: '<Root>/vcib_VCIP_in191'
   */
  swc_DIAG_ARID_DEF.DataTypeConversion253 =
    Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_u_Acc2Raw_mV();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/ACP_Diag'
   */
  swc_DIAG_ACP_Diag();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/BRP_Diag'
   */
  swc_DIAG_BRP_Diag();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/CES_Diag'
   */
  swc_DIAG_CES_Diag();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/EAD_DiagMot2'
   */
  swc_DIAG_EAD_DiagMot2();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/HVB_Diag'
   */
  swc_DIAG_HVB_Diag();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/MAC_Diag'
   */
  swc_DIAG_MAC_Diag();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/Fault_Management'
   */
  swc_DIAG_Fault_Management();

  /* S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
   *  SubSystem: '<S1>/THM_Diag'
   */
  /* Switch: '<S436>/Switch2' incorporates:
   *  Constant: '<S388>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_edcpOvrTmp_ovrdflg) {
    /* Switch: '<S436>/Switch2' incorporates:
     *  Constant: '<S388>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_edcpOvrTmpSet = digc_b_edcpOvrTmp_ovrdval;
  } else {
    /* Switch: '<S436>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail6'
     *  Constant: '<S10>/t_delay_fail7'
     *  Logic: '<S10>/Logical Operator232'
     *  RelationalOperator: '<S10>/Relational Operator84'
     *  RelationalOperator: '<S10>/Relational Operator95'
     */
    digd_b_edcpOvrTmpSet = ((rtb_DataTypeConversion1_j >= 26.0F) &&
      (rtb_DataTypeConversion1_j <= 34.0F));
  }

  /* End of Switch: '<S436>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S376>/debounce' incorporates:
   *  EnablePort: '<S401>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_j) {
      /* SystemReset for Chart: '<S401>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c44_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_h0 = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_j = true;
    }

    /* Saturate: '<S401>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail2'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S401>/Saturation1' */
      rtb_t_delay_on_cn = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S401>/Saturation1' */
      rtb_t_delay_on_cn = 0.0F;
    } else {
      /* Saturate: '<S401>/Saturation1' */
      rtb_t_delay_on_cn = 1.0F;
    }

    /* Chart: '<S401>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail4'
     *  DataTypeConversion: '<S401>/Data Type Conversion'
     *  Saturate: '<S401>/Saturation'
     *  UnitDelay: '<S376>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c44_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c44_swc_DIAG = 1U;
      if ((!digd_b_edcpOvrTmpSet) && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S401>/flg_out' */
        digd_b_edcpOvrTmpDebd = false;
      } else if (digd_b_edcpOvrTmpSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S401>/flg_out' */
        digd_b_edcpOvrTmpDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE) {
        swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_h0 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_h0 += 0.01F;

        /* SignalConversion generated from: '<S401>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail4'
         */
        digd_b_edcpOvrTmpDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_h0 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_h0 += 0.01F;

        /* SignalConversion generated from: '<S401>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail4'
         */
        digd_b_edcpOvrTmpDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c44_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_edcpOvrTmpSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S401>/flg_out' */
            digd_b_edcpOvrTmpDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_h0 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_h0 += 0.01F;

            /* SignalConversion generated from: '<S401>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail4'
             */
            digd_b_edcpOvrTmpDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S401>/flg_out' */
          digd_b_edcpOvrTmpDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_edcpOvrTmpSet) {
          swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S401>/flg_out' */
          digd_b_edcpOvrTmpDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_h0 > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S401>/flg_out' */
          digd_b_edcpOvrTmpDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_h0 += 0.01F;

          /* SignalConversion generated from: '<S401>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail4'
           */
          digd_b_edcpOvrTmpDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_edcpOvrTmpSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S401>/flg_out' */
            digd_b_edcpOvrTmpDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_h0 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_h0 += 0.01F;

            /* SignalConversion generated from: '<S401>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail4'
             */
            digd_b_edcpOvrTmpDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S401>/flg_out' */
          digd_b_edcpOvrTmpDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_edcpOvrTmpSet) {
          swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S401>/flg_out' */
          digd_b_edcpOvrTmpDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_h0 > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c44_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S401>/flg_out' */
          digd_b_edcpOvrTmpDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_h0 += 0.01F;

          /* SignalConversion generated from: '<S401>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail4'
           */
          digd_b_edcpOvrTmpDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S401>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_j) {
    /* Disable for SignalConversion generated from: '<S401>/flg_out' incorporates:
     *  Outport: '<S401>/flg_out'
     */
    digd_b_edcpOvrTmpDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_j = false;
  }

  /* End of Outputs for SubSystem: '<S376>/debounce' */

  /* CCaller: '<S400>/C Caller' incorporates:
   *  Constant: '<S10>/event_id2'
   *  DataTypeConversion: '<S376>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32920U), digd_b_edcpOvrTmpDebd);

  /* Switch: '<S440>/Switch2' incorporates:
   *  Constant: '<S392>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_edcpIdly_ovrdflg) {
    /* Switch: '<S440>/Switch2' incorporates:
     *  Constant: '<S392>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_edcpIdlySet = digc_b_edcpIdly_ovrdval;
  } else {
    /* Switch: '<S440>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail11'
     *  Constant: '<S10>/t_delay_fail12'
     *  Logic: '<S10>/Logical Operator2'
     *  RelationalOperator: '<S10>/Relational Operator1'
     *  RelationalOperator: '<S10>/Relational Operator2'
     */
    digd_b_edcpIdlySet = ((rtb_DataTypeConversion1_j >= 36.0F) &&
                          (rtb_DataTypeConversion1_j <= 44.0F));
  }

  /* End of Switch: '<S440>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S377>/debounce' incorporates:
   *  EnablePort: '<S404>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_po) {
      /* SystemReset for Chart: '<S404>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c45_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_b = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_po = true;
    }

    /* Saturate: '<S404>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail8'
     *  Saturate: '<S404>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S404>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S404>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S404>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S404>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S404>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S404>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail10'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S404>/Saturation' */

    /* Chart: '<S404>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail9'
     *  DataTypeConversion: '<S404>/Data Type Conversion'
     *  UnitDelay: '<S377>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c45_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c45_swc_DIAG = 1U;
      if ((!digd_b_edcpIdlySet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S404>/flg_out' */
        digd_b_edcpIdlyDebd = false;
      } else if (digd_b_edcpIdlySet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S404>/flg_out' */
        digd_b_edcpIdlyDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_g) {
        swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_b = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_b += 0.01F;

        /* SignalConversion generated from: '<S404>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail9'
         */
        digd_b_edcpIdlyDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_b = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_b += 0.01F;

        /* SignalConversion generated from: '<S404>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail9'
         */
        digd_b_edcpIdlyDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c45_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_edcpIdlySet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S404>/flg_out' */
            digd_b_edcpIdlyDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_b = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_b += 0.01F;

            /* SignalConversion generated from: '<S404>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail9'
             */
            digd_b_edcpIdlyDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S404>/flg_out' */
          digd_b_edcpIdlyDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_edcpIdlySet) {
          swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S404>/flg_out' */
          digd_b_edcpIdlyDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_b > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S404>/flg_out' */
          digd_b_edcpIdlyDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_b += 0.01F;

          /* SignalConversion generated from: '<S404>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail9'
           */
          digd_b_edcpIdlyDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_edcpIdlySet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S404>/flg_out' */
            digd_b_edcpIdlyDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_b = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_b += 0.01F;

            /* SignalConversion generated from: '<S404>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail9'
             */
            digd_b_edcpIdlyDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S404>/flg_out' */
          digd_b_edcpIdlyDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_edcpIdlySet) {
          swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S404>/flg_out' */
          digd_b_edcpIdlyDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_b > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c45_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S404>/flg_out' */
          digd_b_edcpIdlyDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_b += 0.01F;

          /* SignalConversion generated from: '<S404>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail9'
           */
          digd_b_edcpIdlyDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S404>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_po) {
    /* Disable for SignalConversion generated from: '<S404>/flg_out' incorporates:
     *  Outport: '<S404>/flg_out'
     */
    digd_b_edcpIdlyDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_po = false;
  }

  /* End of Outputs for SubSystem: '<S377>/debounce' */

  /* CCaller: '<S403>/C Caller' incorporates:
   *  Constant: '<S10>/event_id1'
   *  DataTypeConversion: '<S377>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32921U), digd_b_edcpIdlyDebd);

  /* Switch: '<S438>/Switch2' incorporates:
   *  Constant: '<S390>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_hbcpBlock_ovrdflg) {
    /* Switch: '<S438>/Switch2' incorporates:
     *  Constant: '<S390>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_hbcpBlockSet = digc_b_hbcpBlock_ovrdval;
  } else {
    /* Switch: '<S438>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail50'
     *  Constant: '<S10>/t_delay_fail51'
     *  Logic: '<S10>/Logical Operator12'
     *  RelationalOperator: '<S10>/Relational Operator22'
     *  RelationalOperator: '<S10>/Relational Operator23'
     */
    digd_b_hbcpBlockSet = ((rtb_DataTypeConversion71 >= 66.0F) &&
      (rtb_DataTypeConversion71 <= 74.0F));
  }

  /* End of Switch: '<S438>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S378>/debounce' incorporates:
   *  EnablePort: '<S407>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_p) {
      /* SystemReset for Chart: '<S407>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c46_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_ky = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_p = true;
    }

    /* Saturate: '<S407>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail52'
     *  Saturate: '<S407>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S407>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S407>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S407>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S407>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S407>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S407>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail49'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S407>/Saturation' */

    /* Chart: '<S407>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail53'
     *  DataTypeConversion: '<S407>/Data Type Conversion'
     *  UnitDelay: '<S378>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c46_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c46_swc_DIAG = 1U;
      if ((!digd_b_hbcpBlockSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S407>/flg_out' */
        digd_b_hbcpBlockDebd = false;
      } else if (digd_b_hbcpBlockSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S407>/flg_out' */
        digd_b_hbcpBlockDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_c) {
        swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_ky = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ky += 0.01F;

        /* SignalConversion generated from: '<S407>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail53'
         */
        digd_b_hbcpBlockDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_ky = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_ky += 0.01F;

        /* SignalConversion generated from: '<S407>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail53'
         */
        digd_b_hbcpBlockDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c46_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_hbcpBlockSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S407>/flg_out' */
            digd_b_hbcpBlockDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_ky = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ky += 0.01F;

            /* SignalConversion generated from: '<S407>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail53'
             */
            digd_b_hbcpBlockDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S407>/flg_out' */
          digd_b_hbcpBlockDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_hbcpBlockSet) {
          swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S407>/flg_out' */
          digd_b_hbcpBlockDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_ky > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S407>/flg_out' */
          digd_b_hbcpBlockDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ky += 0.01F;

          /* SignalConversion generated from: '<S407>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail53'
           */
          digd_b_hbcpBlockDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_hbcpBlockSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S407>/flg_out' */
            digd_b_hbcpBlockDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_ky = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_ky += 0.01F;

            /* SignalConversion generated from: '<S407>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail53'
             */
            digd_b_hbcpBlockDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S407>/flg_out' */
          digd_b_hbcpBlockDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_hbcpBlockSet) {
          swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S407>/flg_out' */
          digd_b_hbcpBlockDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_ky > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c46_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S407>/flg_out' */
          digd_b_hbcpBlockDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_ky += 0.01F;

          /* SignalConversion generated from: '<S407>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail53'
           */
          digd_b_hbcpBlockDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S407>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_p) {
    /* Disable for SignalConversion generated from: '<S407>/flg_out' incorporates:
     *  Outport: '<S407>/flg_out'
     */
    digd_b_hbcpBlockDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_p = false;
  }

  /* End of Outputs for SubSystem: '<S378>/debounce' */

  /* CCaller: '<S406>/C Caller' incorporates:
   *  Constant: '<S10>/event_id10'
   *  DataTypeConversion: '<S378>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32951U), digd_b_hbcpBlockDebd);

  /* Switch: '<S439>/Switch2' incorporates:
   *  Constant: '<S391>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_hbcpOvrCurr_ovrdflg) {
    /* Switch: '<S439>/Switch2' incorporates:
     *  Constant: '<S391>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_hbcpOvrCurrSet = digc_b_hbcpOvrCurr_ovrdval;
  } else {
    /* Switch: '<S439>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail55'
     *  Constant: '<S10>/t_delay_fail56'
     *  Logic: '<S10>/Logical Operator13'
     *  RelationalOperator: '<S10>/Relational Operator14'
     *  RelationalOperator: '<S10>/Relational Operator25'
     */
    digd_b_hbcpOvrCurrSet = ((rtb_DataTypeConversion71 >= 76.0F) &&
      (rtb_DataTypeConversion71 <= 84.0F));
  }

  /* End of Switch: '<S439>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S379>/debounce' incorporates:
   *  EnablePort: '<S410>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_ns) {
      /* SystemReset for Chart: '<S410>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c47_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_l1 = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_ns = true;
    }

    /* Saturate: '<S410>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail57'
     *  Saturate: '<S410>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S410>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S410>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S410>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S410>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S410>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S410>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail54'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S410>/Saturation' */

    /* Chart: '<S410>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail58'
     *  DataTypeConversion: '<S410>/Data Type Conversion'
     *  UnitDelay: '<S379>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c47_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c47_swc_DIAG = 1U;
      if ((!digd_b_hbcpOvrCurrSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S410>/flg_out' */
        digd_b_hbcpOvrCurrDebd = false;
      } else if (digd_b_hbcpOvrCurrSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S410>/flg_out' */
        digd_b_hbcpOvrCurrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_a) {
        swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_l1 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_l1 += 0.01F;

        /* SignalConversion generated from: '<S410>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail58'
         */
        digd_b_hbcpOvrCurrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_l1 = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_l1 += 0.01F;

        /* SignalConversion generated from: '<S410>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail58'
         */
        digd_b_hbcpOvrCurrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c47_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_hbcpOvrCurrSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S410>/flg_out' */
            digd_b_hbcpOvrCurrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_l1 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_l1 += 0.01F;

            /* SignalConversion generated from: '<S410>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail58'
             */
            digd_b_hbcpOvrCurrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S410>/flg_out' */
          digd_b_hbcpOvrCurrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_hbcpOvrCurrSet) {
          swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S410>/flg_out' */
          digd_b_hbcpOvrCurrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_l1 > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S410>/flg_out' */
          digd_b_hbcpOvrCurrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_l1 += 0.01F;

          /* SignalConversion generated from: '<S410>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail58'
           */
          digd_b_hbcpOvrCurrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_hbcpOvrCurrSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S410>/flg_out' */
            digd_b_hbcpOvrCurrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_l1 = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_l1 += 0.01F;

            /* SignalConversion generated from: '<S410>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail58'
             */
            digd_b_hbcpOvrCurrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S410>/flg_out' */
          digd_b_hbcpOvrCurrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_hbcpOvrCurrSet) {
          swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S410>/flg_out' */
          digd_b_hbcpOvrCurrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_l1 > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c47_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S410>/flg_out' */
          digd_b_hbcpOvrCurrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_l1 += 0.01F;

          /* SignalConversion generated from: '<S410>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail58'
           */
          digd_b_hbcpOvrCurrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S410>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_ns) {
    /* Disable for SignalConversion generated from: '<S410>/flg_out' incorporates:
     *  Outport: '<S410>/flg_out'
     */
    digd_b_hbcpOvrCurrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_ns = false;
  }

  /* End of Outputs for SubSystem: '<S379>/debounce' */

  /* CCaller: '<S409>/C Caller' incorporates:
   *  Constant: '<S10>/event_id14'
   *  DataTypeConversion: '<S379>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32952U), digd_b_hbcpOvrCurrDebd);

  /* Switch: '<S441>/Switch2' incorporates:
   *  Constant: '<S393>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_edcpUdVolt_ovrdflg) {
    /* Switch: '<S441>/Switch2' incorporates:
     *  Constant: '<S393>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_edcpUdVoltSet = digc_b_edcpUdVolt_ovrdval;
  } else {
    /* Switch: '<S441>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail14'
     *  Constant: '<S10>/t_delay_fail15'
     *  Logic: '<S10>/Logical Operator3'
     *  RelationalOperator: '<S10>/Relational Operator3'
     *  RelationalOperator: '<S10>/Relational Operator4'
     */
    digd_b_edcpUdVoltSet = ((rtb_DataTypeConversion1_j >= 46.0F) &&
      (rtb_DataTypeConversion1_j <= 54.0F));
  }

  /* End of Switch: '<S441>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S380>/debounce' incorporates:
   *  EnablePort: '<S413>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_n) {
      /* SystemReset for Chart: '<S413>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c48_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_h = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_n = true;
    }

    /* Saturate: '<S413>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail16'
     *  Saturate: '<S413>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S413>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S413>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S413>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S413>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S413>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S413>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail13'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S413>/Saturation' */

    /* Chart: '<S413>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail17'
     *  DataTypeConversion: '<S413>/Data Type Conversion'
     *  UnitDelay: '<S380>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c48_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c48_swc_DIAG = 1U;
      if ((!digd_b_edcpUdVoltSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S413>/flg_out' */
        digd_b_edcpUdVoltDebd = false;
      } else if (digd_b_edcpUdVoltSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S413>/flg_out' */
        digd_b_edcpUdVoltDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_i) {
        swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_h = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_h += 0.01F;

        /* SignalConversion generated from: '<S413>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail17'
         */
        digd_b_edcpUdVoltDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_h = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_h += 0.01F;

        /* SignalConversion generated from: '<S413>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail17'
         */
        digd_b_edcpUdVoltDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c48_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_edcpUdVoltSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S413>/flg_out' */
            digd_b_edcpUdVoltDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_h = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_h += 0.01F;

            /* SignalConversion generated from: '<S413>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail17'
             */
            digd_b_edcpUdVoltDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S413>/flg_out' */
          digd_b_edcpUdVoltDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_edcpUdVoltSet) {
          swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S413>/flg_out' */
          digd_b_edcpUdVoltDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_h > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S413>/flg_out' */
          digd_b_edcpUdVoltDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_h += 0.01F;

          /* SignalConversion generated from: '<S413>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail17'
           */
          digd_b_edcpUdVoltDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_edcpUdVoltSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S413>/flg_out' */
            digd_b_edcpUdVoltDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_h = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_h += 0.01F;

            /* SignalConversion generated from: '<S413>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail17'
             */
            digd_b_edcpUdVoltDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S413>/flg_out' */
          digd_b_edcpUdVoltDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_edcpUdVoltSet) {
          swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S413>/flg_out' */
          digd_b_edcpUdVoltDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_h > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c48_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S413>/flg_out' */
          digd_b_edcpUdVoltDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_h += 0.01F;

          /* SignalConversion generated from: '<S413>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail17'
           */
          digd_b_edcpUdVoltDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S413>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_n) {
    /* Disable for SignalConversion generated from: '<S413>/flg_out' incorporates:
     *  Outport: '<S413>/flg_out'
     */
    digd_b_edcpUdVoltDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_n = false;
  }

  /* End of Outputs for SubSystem: '<S380>/debounce' */

  /* CCaller: '<S412>/C Caller' incorporates:
   *  Constant: '<S10>/event_id3'
   *  DataTypeConversion: '<S380>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32922U), digd_b_edcpUdVoltDebd);

  /* Switch: '<S442>/Switch2' incorporates:
   *  Constant: '<S394>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_edcpOvrVolt_ovrdflg) {
    /* Switch: '<S442>/Switch2' incorporates:
     *  Constant: '<S394>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_edcpOvrVoltSet = digc_b_edcpOvrVolt_ovrdval;
  } else {
    /* Switch: '<S442>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail19'
     *  Constant: '<S10>/t_delay_fail20'
     *  Logic: '<S10>/Logical Operator4'
     *  RelationalOperator: '<S10>/Relational Operator5'
     *  RelationalOperator: '<S10>/Relational Operator6'
     */
    digd_b_edcpOvrVoltSet = ((rtb_DataTypeConversion1_j >= 56.0F) &&
      (rtb_DataTypeConversion1_j <= 64.0F));
  }

  /* End of Switch: '<S442>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S381>/debounce' incorporates:
   *  EnablePort: '<S416>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_g) {
      /* SystemReset for Chart: '<S416>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c49_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_a = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_g = true;
    }

    /* Saturate: '<S416>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail21'
     *  Saturate: '<S416>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S416>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S416>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S416>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S416>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S416>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S416>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail18'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S416>/Saturation' */

    /* Chart: '<S416>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail22'
     *  DataTypeConversion: '<S416>/Data Type Conversion'
     *  UnitDelay: '<S381>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c49_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c49_swc_DIAG = 1U;
      if ((!digd_b_edcpOvrVoltSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S416>/flg_out' */
        digd_b_edcpOvrVoltDebd = false;
      } else if (digd_b_edcpOvrVoltSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S416>/flg_out' */
        digd_b_edcpOvrVoltDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_p) {
        swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_a = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_a += 0.01F;

        /* SignalConversion generated from: '<S416>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail22'
         */
        digd_b_edcpOvrVoltDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_a = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_a += 0.01F;

        /* SignalConversion generated from: '<S416>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail22'
         */
        digd_b_edcpOvrVoltDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c49_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_edcpOvrVoltSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S416>/flg_out' */
            digd_b_edcpOvrVoltDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_a = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_a += 0.01F;

            /* SignalConversion generated from: '<S416>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail22'
             */
            digd_b_edcpOvrVoltDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S416>/flg_out' */
          digd_b_edcpOvrVoltDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_edcpOvrVoltSet) {
          swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S416>/flg_out' */
          digd_b_edcpOvrVoltDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_a > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S416>/flg_out' */
          digd_b_edcpOvrVoltDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_a += 0.01F;

          /* SignalConversion generated from: '<S416>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail22'
           */
          digd_b_edcpOvrVoltDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_edcpOvrVoltSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S416>/flg_out' */
            digd_b_edcpOvrVoltDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_a = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_a += 0.01F;

            /* SignalConversion generated from: '<S416>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail22'
             */
            digd_b_edcpOvrVoltDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S416>/flg_out' */
          digd_b_edcpOvrVoltDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_edcpOvrVoltSet) {
          swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S416>/flg_out' */
          digd_b_edcpOvrVoltDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_a > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c49_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S416>/flg_out' */
          digd_b_edcpOvrVoltDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_a += 0.01F;

          /* SignalConversion generated from: '<S416>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail22'
           */
          digd_b_edcpOvrVoltDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S416>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_g) {
    /* Disable for SignalConversion generated from: '<S416>/flg_out' incorporates:
     *  Outport: '<S416>/flg_out'
     */
    digd_b_edcpOvrVoltDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_g = false;
  }

  /* End of Outputs for SubSystem: '<S381>/debounce' */

  /* CCaller: '<S415>/C Caller' incorporates:
   *  Constant: '<S10>/event_id4'
   *  DataTypeConversion: '<S381>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32923U), digd_b_edcpOvrVoltDebd);

  /* Switch: '<S443>/Switch2' incorporates:
   *  Constant: '<S395>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_edcpBlock_ovrdflg) {
    /* Switch: '<S443>/Switch2' incorporates:
     *  Constant: '<S395>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_edcpBlockSet = digc_b_edcpBlock_ovrdval;
  } else {
    /* Switch: '<S443>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail24'
     *  Constant: '<S10>/t_delay_fail25'
     *  Logic: '<S10>/Logical Operator5'
     *  RelationalOperator: '<S10>/Relational Operator7'
     *  RelationalOperator: '<S10>/Relational Operator8'
     */
    digd_b_edcpBlockSet = ((rtb_DataTypeConversion1_j >= 66.0F) &&
      (rtb_DataTypeConversion1_j <= 74.0F));
  }

  /* End of Switch: '<S443>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S382>/debounce' incorporates:
   *  EnablePort: '<S419>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_ig) {
      /* SystemReset for Chart: '<S419>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c50_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_c = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_ig = true;
    }

    /* Saturate: '<S419>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail26'
     *  Saturate: '<S419>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S419>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S419>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S419>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S419>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S419>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S419>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail23'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S419>/Saturation' */

    /* Chart: '<S419>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail27'
     *  DataTypeConversion: '<S419>/Data Type Conversion'
     *  UnitDelay: '<S382>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c50_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c50_swc_DIAG = 1U;
      if ((!digd_b_edcpBlockSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S419>/flg_out' */
        digd_b_edcpBlockDebd = false;
      } else if (digd_b_edcpBlockSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S419>/flg_out' */
        digd_b_edcpBlockDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_a3) {
        swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_c = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_c += 0.01F;

        /* SignalConversion generated from: '<S419>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail27'
         */
        digd_b_edcpBlockDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_c = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_c += 0.01F;

        /* SignalConversion generated from: '<S419>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail27'
         */
        digd_b_edcpBlockDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c50_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_edcpBlockSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S419>/flg_out' */
            digd_b_edcpBlockDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_c = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_c += 0.01F;

            /* SignalConversion generated from: '<S419>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail27'
             */
            digd_b_edcpBlockDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S419>/flg_out' */
          digd_b_edcpBlockDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_edcpBlockSet) {
          swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S419>/flg_out' */
          digd_b_edcpBlockDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_c > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S419>/flg_out' */
          digd_b_edcpBlockDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_c += 0.01F;

          /* SignalConversion generated from: '<S419>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail27'
           */
          digd_b_edcpBlockDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_edcpBlockSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S419>/flg_out' */
            digd_b_edcpBlockDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_c = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_c += 0.01F;

            /* SignalConversion generated from: '<S419>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail27'
             */
            digd_b_edcpBlockDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S419>/flg_out' */
          digd_b_edcpBlockDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_edcpBlockSet) {
          swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S419>/flg_out' */
          digd_b_edcpBlockDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_c > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c50_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S419>/flg_out' */
          digd_b_edcpBlockDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_c += 0.01F;

          /* SignalConversion generated from: '<S419>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail27'
           */
          digd_b_edcpBlockDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S419>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_ig) {
    /* Disable for SignalConversion generated from: '<S419>/flg_out' incorporates:
     *  Outport: '<S419>/flg_out'
     */
    digd_b_edcpBlockDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_ig = false;
  }

  /* End of Outputs for SubSystem: '<S382>/debounce' */

  /* CCaller: '<S418>/C Caller' incorporates:
   *  Constant: '<S10>/event_id5'
   *  DataTypeConversion: '<S382>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32924U), digd_b_edcpBlockDebd);

  /* Switch: '<S444>/Switch2' incorporates:
   *  Constant: '<S396>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_edcpOvrCurr_ovrdflg) {
    /* Switch: '<S444>/Switch2' incorporates:
     *  Constant: '<S396>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_edcpOvrCurrSet = digc_b_edcpOvrCurr_ovrdval;
  } else {
    /* Switch: '<S444>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail29'
     *  Constant: '<S10>/t_delay_fail30'
     *  Logic: '<S10>/Logical Operator6'
     *  RelationalOperator: '<S10>/Relational Operator10'
     *  RelationalOperator: '<S10>/Relational Operator9'
     */
    digd_b_edcpOvrCurrSet = ((rtb_DataTypeConversion1_j >= 76.0F) &&
      (rtb_DataTypeConversion1_j <= 84.0F));
  }

  /* End of Switch: '<S444>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S383>/debounce' incorporates:
   *  EnablePort: '<S422>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_o) {
      /* SystemReset for Chart: '<S422>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c51_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_m = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_o = true;
    }

    /* Saturate: '<S422>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail31'
     *  Saturate: '<S422>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S422>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S422>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S422>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S422>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S422>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S422>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail28'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S422>/Saturation' */

    /* Chart: '<S422>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail32'
     *  DataTypeConversion: '<S422>/Data Type Conversion'
     *  UnitDelay: '<S383>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c51_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c51_swc_DIAG = 1U;
      if ((!digd_b_edcpOvrCurrSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S422>/flg_out' */
        digd_b_edcpOvrCurrDebd = false;
      } else if (digd_b_edcpOvrCurrSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S422>/flg_out' */
        digd_b_edcpOvrCurrDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_k) {
        swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_m = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_m += 0.01F;

        /* SignalConversion generated from: '<S422>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail32'
         */
        digd_b_edcpOvrCurrDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_m = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_m += 0.01F;

        /* SignalConversion generated from: '<S422>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail32'
         */
        digd_b_edcpOvrCurrDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c51_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_edcpOvrCurrSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S422>/flg_out' */
            digd_b_edcpOvrCurrDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_m = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_m += 0.01F;

            /* SignalConversion generated from: '<S422>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail32'
             */
            digd_b_edcpOvrCurrDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S422>/flg_out' */
          digd_b_edcpOvrCurrDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_edcpOvrCurrSet) {
          swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S422>/flg_out' */
          digd_b_edcpOvrCurrDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_m > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S422>/flg_out' */
          digd_b_edcpOvrCurrDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_m += 0.01F;

          /* SignalConversion generated from: '<S422>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail32'
           */
          digd_b_edcpOvrCurrDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_edcpOvrCurrSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S422>/flg_out' */
            digd_b_edcpOvrCurrDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_m = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_m += 0.01F;

            /* SignalConversion generated from: '<S422>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail32'
             */
            digd_b_edcpOvrCurrDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S422>/flg_out' */
          digd_b_edcpOvrCurrDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_edcpOvrCurrSet) {
          swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S422>/flg_out' */
          digd_b_edcpOvrCurrDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_m > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c51_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S422>/flg_out' */
          digd_b_edcpOvrCurrDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_m += 0.01F;

          /* SignalConversion generated from: '<S422>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail32'
           */
          digd_b_edcpOvrCurrDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S422>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_o) {
    /* Disable for SignalConversion generated from: '<S422>/flg_out' incorporates:
     *  Outport: '<S422>/flg_out'
     */
    digd_b_edcpOvrCurrDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_o = false;
  }

  /* End of Outputs for SubSystem: '<S383>/debounce' */

  /* CCaller: '<S421>/C Caller' incorporates:
   *  Constant: '<S10>/event_id6'
   *  DataTypeConversion: '<S383>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32925U), digd_b_edcpOvrCurrDebd);

  /* Switch: '<S445>/Switch2' incorporates:
   *  Constant: '<S397>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_hbcpOvrTmp_ovrdflg) {
    /* Switch: '<S445>/Switch2' incorporates:
     *  Constant: '<S397>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_hbcpOvrTmpSet = digc_b_hbcpOvrTmp_ovrdval;
  } else {
    /* Switch: '<S445>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail63'
     *  Constant: '<S10>/t_delay_fail64'
     *  Logic: '<S10>/Logical Operator9'
     *  RelationalOperator: '<S10>/Relational Operator24'
     *  RelationalOperator: '<S10>/Relational Operator26'
     */
    digd_b_hbcpOvrTmpSet = ((rtb_DataTypeConversion71 >= 26.0F) &&
      (rtb_DataTypeConversion71 <= 34.0F));
  }

  /* End of Switch: '<S445>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S384>/debounce' incorporates:
   *  EnablePort: '<S425>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_m) {
      /* SystemReset for Chart: '<S425>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c52_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_k = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_m = true;
    }

    /* Saturate: '<S425>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail45'
     *  Saturate: '<S425>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S425>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S425>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S425>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S425>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S425>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S425>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail62'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S425>/Saturation' */

    /* Chart: '<S425>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail61'
     *  DataTypeConversion: '<S425>/Data Type Conversion'
     *  UnitDelay: '<S384>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c52_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c52_swc_DIAG = 1U;
      if ((!digd_b_hbcpOvrTmpSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S425>/flg_out' */
        digd_b_hbcpOvrTmpDebd = false;
      } else if (digd_b_hbcpOvrTmpSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S425>/flg_out' */
        digd_b_hbcpOvrTmpDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_n) {
        swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_k = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_k += 0.01F;

        /* SignalConversion generated from: '<S425>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail61'
         */
        digd_b_hbcpOvrTmpDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_k = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_k += 0.01F;

        /* SignalConversion generated from: '<S425>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail61'
         */
        digd_b_hbcpOvrTmpDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c52_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_hbcpOvrTmpSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S425>/flg_out' */
            digd_b_hbcpOvrTmpDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_k = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_k += 0.01F;

            /* SignalConversion generated from: '<S425>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail61'
             */
            digd_b_hbcpOvrTmpDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S425>/flg_out' */
          digd_b_hbcpOvrTmpDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_hbcpOvrTmpSet) {
          swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S425>/flg_out' */
          digd_b_hbcpOvrTmpDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_k > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S425>/flg_out' */
          digd_b_hbcpOvrTmpDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_k += 0.01F;

          /* SignalConversion generated from: '<S425>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail61'
           */
          digd_b_hbcpOvrTmpDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_hbcpOvrTmpSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S425>/flg_out' */
            digd_b_hbcpOvrTmpDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_k = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_k += 0.01F;

            /* SignalConversion generated from: '<S425>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail61'
             */
            digd_b_hbcpOvrTmpDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S425>/flg_out' */
          digd_b_hbcpOvrTmpDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_hbcpOvrTmpSet) {
          swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S425>/flg_out' */
          digd_b_hbcpOvrTmpDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_k > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c52_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S425>/flg_out' */
          digd_b_hbcpOvrTmpDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_k += 0.01F;

          /* SignalConversion generated from: '<S425>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail61'
           */
          digd_b_hbcpOvrTmpDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S425>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_m) {
    /* Disable for SignalConversion generated from: '<S425>/flg_out' incorporates:
     *  Outport: '<S425>/flg_out'
     */
    digd_b_hbcpOvrTmpDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_m = false;
  }

  /* End of Outputs for SubSystem: '<S384>/debounce' */

  /* CCaller: '<S424>/C Caller' incorporates:
   *  Constant: '<S10>/event_id13'
   *  DataTypeConversion: '<S384>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32947U), digd_b_hbcpOvrTmpDebd);

  /* Switch: '<S446>/Switch2' incorporates:
   *  Constant: '<S398>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_hbcpIdly_ovrdflg) {
    /* Switch: '<S446>/Switch2' incorporates:
     *  Constant: '<S398>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_hbcpIdlySet = digc_b_hbcpIdly_ovrdval;
  } else {
    /* Switch: '<S446>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail36'
     *  Constant: '<S10>/t_delay_fail37'
     *  Logic: '<S10>/Logical Operator8'
     *  RelationalOperator: '<S10>/Relational Operator13'
     *  RelationalOperator: '<S10>/Relational Operator17'
     */
    digd_b_hbcpIdlySet = ((rtb_DataTypeConversion71 >= 36.0F) &&
                          (rtb_DataTypeConversion71 <= 44.0F));
  }

  /* End of Switch: '<S446>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S385>/debounce' incorporates:
   *  EnablePort: '<S428>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_a) {
      /* SystemReset for Chart: '<S428>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c53_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_l = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_a = true;
    }

    /* Saturate: '<S428>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail65'
     *  Saturate: '<S428>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S428>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S428>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S428>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S428>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S428>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S428>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail35'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S428>/Saturation' */

    /* Chart: '<S428>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail66'
     *  DataTypeConversion: '<S428>/Data Type Conversion'
     *  UnitDelay: '<S385>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c53_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c53_swc_DIAG = 1U;
      if ((!digd_b_hbcpIdlySet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S428>/flg_out' */
        digd_b_hbcpIdlyDebd = false;
      } else if (digd_b_hbcpIdlySet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S428>/flg_out' */
        digd_b_hbcpIdlyDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_e) {
        swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_l = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_l += 0.01F;

        /* SignalConversion generated from: '<S428>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail66'
         */
        digd_b_hbcpIdlyDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_l = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_l += 0.01F;

        /* SignalConversion generated from: '<S428>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail66'
         */
        digd_b_hbcpIdlyDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c53_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_hbcpIdlySet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S428>/flg_out' */
            digd_b_hbcpIdlyDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_l = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_l += 0.01F;

            /* SignalConversion generated from: '<S428>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail66'
             */
            digd_b_hbcpIdlyDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S428>/flg_out' */
          digd_b_hbcpIdlyDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_hbcpIdlySet) {
          swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S428>/flg_out' */
          digd_b_hbcpIdlyDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_l > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S428>/flg_out' */
          digd_b_hbcpIdlyDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_l += 0.01F;

          /* SignalConversion generated from: '<S428>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail66'
           */
          digd_b_hbcpIdlyDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_hbcpIdlySet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S428>/flg_out' */
            digd_b_hbcpIdlyDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_l = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_l += 0.01F;

            /* SignalConversion generated from: '<S428>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail66'
             */
            digd_b_hbcpIdlyDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S428>/flg_out' */
          digd_b_hbcpIdlyDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_hbcpIdlySet) {
          swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S428>/flg_out' */
          digd_b_hbcpIdlyDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_l > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c53_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S428>/flg_out' */
          digd_b_hbcpIdlyDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_l += 0.01F;

          /* SignalConversion generated from: '<S428>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail66'
           */
          digd_b_hbcpIdlyDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S428>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_a) {
    /* Disable for SignalConversion generated from: '<S428>/flg_out' incorporates:
     *  Outport: '<S428>/flg_out'
     */
    digd_b_hbcpIdlyDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_a = false;
  }

  /* End of Outputs for SubSystem: '<S385>/debounce' */

  /* CCaller: '<S427>/C Caller' incorporates:
   *  Constant: '<S10>/event_id7'
   *  DataTypeConversion: '<S385>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32948U), digd_b_hbcpIdlyDebd);

  /* Switch: '<S447>/Switch2' incorporates:
   *  Constant: '<S399>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_hbcpUdVolt_ovrdflg) {
    /* Switch: '<S447>/Switch2' incorporates:
     *  Constant: '<S399>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_hbcpUdVoltSet = digc_b_hbcpUdVolt_ovrdval;
  } else {
    /* Switch: '<S447>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail39'
     *  Constant: '<S10>/t_delay_fail40'
     *  Logic: '<S10>/Logical Operator10'
     *  RelationalOperator: '<S10>/Relational Operator18'
     *  RelationalOperator: '<S10>/Relational Operator19'
     */
    digd_b_hbcpUdVoltSet = ((rtb_DataTypeConversion71 >= 46.0F) &&
      (rtb_DataTypeConversion71 <= 54.0F));
  }

  /* End of Switch: '<S447>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S386>/debounce' incorporates:
   *  EnablePort: '<S431>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE_i) {
      /* SystemReset for Chart: '<S431>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c54_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait_p = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE_i = true;
    }

    /* Saturate: '<S431>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail41'
     *  Saturate: '<S431>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S431>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S431>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S431>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S431>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S431>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S431>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail38'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S431>/Saturation' */

    /* Chart: '<S431>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail42'
     *  DataTypeConversion: '<S431>/Data Type Conversion'
     *  UnitDelay: '<S386>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c54_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c54_swc_DIAG = 1U;
      if ((!digd_b_hbcpUdVoltSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S431>/flg_out' */
        digd_b_hbcpUdVoltDebd = false;
      } else if (digd_b_hbcpUdVoltSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S431>/flg_out' */
        digd_b_hbcpUdVoltDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_d) {
        swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait_p = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_p += 0.01F;

        /* SignalConversion generated from: '<S431>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail42'
         */
        digd_b_hbcpUdVoltDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait_p = 0.0F;
        swc_DIAG_ARID_DEF.t_wait_p += 0.01F;

        /* SignalConversion generated from: '<S431>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail42'
         */
        digd_b_hbcpUdVoltDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c54_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_hbcpUdVoltSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S431>/flg_out' */
            digd_b_hbcpUdVoltDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait_p = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_p += 0.01F;

            /* SignalConversion generated from: '<S431>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail42'
             */
            digd_b_hbcpUdVoltDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S431>/flg_out' */
          digd_b_hbcpUdVoltDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_hbcpUdVoltSet) {
          swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S431>/flg_out' */
          digd_b_hbcpUdVoltDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait_p > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S431>/flg_out' */
          digd_b_hbcpUdVoltDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait_p += 0.01F;

          /* SignalConversion generated from: '<S431>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail42'
           */
          digd_b_hbcpUdVoltDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_hbcpUdVoltSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S431>/flg_out' */
            digd_b_hbcpUdVoltDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait_p = 0.0F;
            swc_DIAG_ARID_DEF.t_wait_p += 0.01F;

            /* SignalConversion generated from: '<S431>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail42'
             */
            digd_b_hbcpUdVoltDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S431>/flg_out' */
          digd_b_hbcpUdVoltDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_hbcpUdVoltSet) {
          swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S431>/flg_out' */
          digd_b_hbcpUdVoltDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait_p > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c54_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S431>/flg_out' */
          digd_b_hbcpUdVoltDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait_p += 0.01F;

          /* SignalConversion generated from: '<S431>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail42'
           */
          digd_b_hbcpUdVoltDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S431>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE_i) {
    /* Disable for SignalConversion generated from: '<S431>/flg_out' incorporates:
     *  Outport: '<S431>/flg_out'
     */
    digd_b_hbcpUdVoltDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE_i = false;
  }

  /* End of Outputs for SubSystem: '<S386>/debounce' */

  /* CCaller: '<S430>/C Caller' incorporates:
   *  Constant: '<S10>/event_id8'
   *  DataTypeConversion: '<S386>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32949U), digd_b_hbcpUdVoltDebd);

  /* Switch: '<S437>/Switch2' incorporates:
   *  Constant: '<S389>/macc_b_5VT1IntSmplFltEnb_ovrdflg'
   */
  if (digc_b_hbcpOvrVolt_ovrdflg) {
    /* Switch: '<S437>/Switch2' incorporates:
     *  Constant: '<S389>/macc_b_5VT1IntSmplFltEnb_ovrdval'
     */
    digd_b_hbcpOvrVoltSet = digc_b_hbcpOvrVolt_ovrdval;
  } else {
    /* Switch: '<S437>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail44'
     *  Constant: '<S10>/t_delay_fail46'
     *  Logic: '<S10>/Logical Operator11'
     *  RelationalOperator: '<S10>/Relational Operator20'
     *  RelationalOperator: '<S10>/Relational Operator21'
     */
    digd_b_hbcpOvrVoltSet = ((rtb_DataTypeConversion71 >= 56.0F) &&
      (rtb_DataTypeConversion71 <= 64.0F));
  }

  /* End of Switch: '<S437>/Switch2' */

  /* Outputs for Enabled SubSystem: '<S387>/debounce' incorporates:
   *  EnablePort: '<S434>/Enable'
   */
  if (swc_DIAG_ARID_DEF.flg_out_c) {
    if (!swc_DIAG_ARID_DEF.debounce_MODE) {
      /* SystemReset for Chart: '<S434>/timed_debounce' */
      swc_DIAG_ARID_DEF.is_active_c55_swc_DIAG = 0U;
      swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_NO_ACTIVE_CHILD_d;
      swc_DIAG_ARID_DEF.t_wait = 0.0F;
      swc_DIAG_ARID_DEF.debounce_MODE = true;
    }

    /* Saturate: '<S434>/Saturation' incorporates:
     *  Constant: '<S10>/t_delay_fail47'
     *  Saturate: '<S434>/Saturation1'
     */
    if (1.0F > 1.6777216E+7F) {
      /* Saturate: '<S434>/Saturation' */
      rtb_t_delay_on_cn = 1.6777216E+7F;

      /* Saturate: '<S434>/Saturation1' */
      rtb_t_delay_off_bv3 = 1.6777216E+7F;
    } else if (1.0F < 0.0F) {
      /* Saturate: '<S434>/Saturation' */
      rtb_t_delay_on_cn = 0.0F;

      /* Saturate: '<S434>/Saturation1' */
      rtb_t_delay_off_bv3 = 0.0F;
    } else {
      /* Saturate: '<S434>/Saturation' */
      rtb_t_delay_on_cn = 1.0F;

      /* Saturate: '<S434>/Saturation1' incorporates:
       *  Constant: '<S10>/t_delay_fail43'
       */
      rtb_t_delay_off_bv3 = 1.0F;
    }

    /* End of Saturate: '<S434>/Saturation' */

    /* Chart: '<S434>/timed_debounce' incorporates:
     *  Constant: '<S10>/t_delay_fail48'
     *  DataTypeConversion: '<S434>/Data Type Conversion'
     *  UnitDelay: '<S387>/Unit Delay'
     */
    if (swc_DIAG_ARID_DEF.is_active_c55_swc_DIAG == 0U) {
      swc_DIAG_ARID_DEF.is_active_c55_swc_DIAG = 1U;
      if ((!digd_b_hbcpOvrVoltSet) && (rtb_t_delay_off_bv3 == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_OFF_k;

        /* SignalConversion generated from: '<S434>/flg_out' */
        digd_b_hbcpOvrVoltDebd = false;
      } else if (digd_b_hbcpOvrVoltSet && (rtb_t_delay_on_cn == 0.0F)) {
        swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_ON_e;

        /* SignalConversion generated from: '<S434>/flg_out' */
        digd_b_hbcpOvrVoltDebd = true;
      } else if (swc_DIAG_ARID_DEF.UnitDelay_DSTATE_o) {
        swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
        swc_DIAG_ARID_DEF.t_wait = 0.0F;
        swc_DIAG_ARID_DEF.t_wait += 0.01F;

        /* SignalConversion generated from: '<S434>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail48'
         */
        digd_b_hbcpOvrVoltDebd = true;
      } else {
        swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
        swc_DIAG_ARID_DEF.t_wait = 0.0F;
        swc_DIAG_ARID_DEF.t_wait += 0.01F;

        /* SignalConversion generated from: '<S434>/flg_out' incorporates:
         *  Constant: '<S10>/t_delay_fail48'
         */
        digd_b_hbcpOvrVoltDebd = false;
      }
    } else {
      switch (swc_DIAG_ARID_DEF.is_c55_swc_DIAG) {
       case swc_DIAG_IN_OFF_k:
        if (digd_b_hbcpOvrVoltSet) {
          if (rtb_t_delay_on_cn == 0.0F) {
            swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_ON_e;

            /* SignalConversion generated from: '<S434>/flg_out' */
            digd_b_hbcpOvrVoltDebd = true;
          } else {
            swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_ON_WAIT_f;
            swc_DIAG_ARID_DEF.t_wait = 0.0F;
            swc_DIAG_ARID_DEF.t_wait += 0.01F;

            /* SignalConversion generated from: '<S434>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail48'
             */
            digd_b_hbcpOvrVoltDebd = false;
          }
        } else {
          /* SignalConversion generated from: '<S434>/flg_out' */
          digd_b_hbcpOvrVoltDebd = false;
        }
        break;

       case swc_DIAG_IN_OFF_WAIT_ik:
        if (digd_b_hbcpOvrVoltSet) {
          swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S434>/flg_out' */
          digd_b_hbcpOvrVoltDebd = true;
        } else if (swc_DIAG_ARID_DEF.t_wait > rtb_t_delay_off_bv3 - 0.01F) {
          swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S434>/flg_out' */
          digd_b_hbcpOvrVoltDebd = false;
        } else {
          swc_DIAG_ARID_DEF.t_wait += 0.01F;

          /* SignalConversion generated from: '<S434>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail48'
           */
          digd_b_hbcpOvrVoltDebd = true;
        }
        break;

       case swc_DIAG_IN_ON_e:
        if (!digd_b_hbcpOvrVoltSet) {
          if (rtb_t_delay_off_bv3 == 0.0F) {
            swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_OFF_k;

            /* SignalConversion generated from: '<S434>/flg_out' */
            digd_b_hbcpOvrVoltDebd = false;
          } else {
            swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_OFF_WAIT_ik;
            swc_DIAG_ARID_DEF.t_wait = 0.0F;
            swc_DIAG_ARID_DEF.t_wait += 0.01F;

            /* SignalConversion generated from: '<S434>/flg_out' incorporates:
             *  Constant: '<S10>/t_delay_fail48'
             */
            digd_b_hbcpOvrVoltDebd = true;
          }
        } else {
          /* SignalConversion generated from: '<S434>/flg_out' */
          digd_b_hbcpOvrVoltDebd = true;
        }
        break;

       default:
        /* case IN_ON_WAIT: */
        if (!digd_b_hbcpOvrVoltSet) {
          swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_OFF_k;

          /* SignalConversion generated from: '<S434>/flg_out' */
          digd_b_hbcpOvrVoltDebd = false;
        } else if (swc_DIAG_ARID_DEF.t_wait > rtb_t_delay_on_cn - 0.01F) {
          swc_DIAG_ARID_DEF.is_c55_swc_DIAG = swc_DIAG_IN_ON_e;

          /* SignalConversion generated from: '<S434>/flg_out' */
          digd_b_hbcpOvrVoltDebd = true;
        } else {
          swc_DIAG_ARID_DEF.t_wait += 0.01F;

          /* SignalConversion generated from: '<S434>/flg_out' incorporates:
           *  Constant: '<S10>/t_delay_fail48'
           */
          digd_b_hbcpOvrVoltDebd = false;
        }
        break;
      }
    }

    /* End of Chart: '<S434>/timed_debounce' */
  } else if (swc_DIAG_ARID_DEF.debounce_MODE) {
    /* Disable for SignalConversion generated from: '<S434>/flg_out' incorporates:
     *  Outport: '<S434>/flg_out'
     */
    digd_b_hbcpOvrVoltDebd = false;
    swc_DIAG_ARID_DEF.debounce_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S387>/debounce' */

  /* CCaller: '<S433>/C Caller' incorporates:
   *  Constant: '<S10>/event_id9'
   *  DataTypeConversion: '<S387>/Data Type Conversion'
   */
  Dem_SetEventStatus(((uint16)32950U), digd_b_hbcpOvrVoltDebd);

  /* Logic: '<S10>/Logical Operator' */
  digd_b_vcuLvl1Flt_THM = (digd_b_edcpOvrCurrDebd || digd_b_edcpIdlyDebd ||
    digd_b_edcpOvrVoltDebd || digd_b_edcpOvrTmpDebd || digd_b_edcpBlockDebd ||
    digd_b_edcpUdVoltDebd || digd_b_hbcpOvrCurrDebd || digd_b_hbcpIdlyDebd ||
    digd_b_hbcpOvrVoltDebd || digd_b_hbcpOvrTmpDebd || digd_b_hbcpBlockDebd ||
    digd_b_hbcpUdVoltDebd);

  /* Switch: '<S10>/Switch' incorporates:
   *  Constant: '<S10>/t_delay_fail33'
   *  Constant: '<S10>/t_delay_fail34'
   *  Logic: '<S10>/Logical Operator7'
   *  RelationalOperator: '<S10>/Relational Operator11'
   *  RelationalOperator: '<S10>/Relational Operator12'
   *  Switch: '<S10>/Switch1'
   *  Switch: '<S10>/Switch12'
   *  Switch: '<S10>/Switch2'
   *  Switch: '<S10>/Switch3'
   *  Switch: '<S10>/Switch4'
   *  Switch: '<S10>/Switch5'
   */
  if (digd_b_edcpOvrCurrDebd) {
    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/t_delay_fail67'
     */
    digd_st_edcpFlt = ((uint8)2U);
  } else if (digd_b_edcpIdlyDebd) {
    /* Switch: '<S10>/Switch1' incorporates:
     *  Constant: '<S10>/t_delay_fail68'
     *  Switch: '<S10>/Switch'
     */
    digd_st_edcpFlt = ((uint8)3U);
  } else if (digd_b_edcpOvrVoltDebd) {
    /* Switch: '<S10>/Switch2' incorporates:
     *  Constant: '<S10>/t_delay_fail69'
     *  Switch: '<S10>/Switch'
     *  Switch: '<S10>/Switch1'
     */
    digd_st_edcpFlt = ((uint8)4U);
  } else if (digd_b_edcpOvrTmpDebd) {
    /* Switch: '<S10>/Switch3' incorporates:
     *  Constant: '<S10>/t_delay_fail70'
     *  Switch: '<S10>/Switch'
     *  Switch: '<S10>/Switch1'
     *  Switch: '<S10>/Switch2'
     */
    digd_st_edcpFlt = ((uint8)5U);
  } else if (digd_b_edcpBlockDebd) {
    /* Switch: '<S10>/Switch4' incorporates:
     *  Constant: '<S10>/t_delay_fail71'
     *  Switch: '<S10>/Switch'
     *  Switch: '<S10>/Switch1'
     *  Switch: '<S10>/Switch2'
     *  Switch: '<S10>/Switch3'
     */
    digd_st_edcpFlt = ((uint8)6U);
  } else if (digd_b_edcpUdVoltDebd) {
    /* Switch: '<S10>/Switch5' incorporates:
     *  Constant: '<S10>/t_delay_fail72'
     *  Switch: '<S10>/Switch'
     *  Switch: '<S10>/Switch1'
     *  Switch: '<S10>/Switch2'
     *  Switch: '<S10>/Switch3'
     *  Switch: '<S10>/Switch4'
     */
    digd_st_edcpFlt = ((uint8)7U);
  } else if ((rtb_DataTypeConversion1_j >= 6.0F) && (rtb_DataTypeConversion1_j <=
              14.0F)) {
    /* Switch: '<S10>/Switch12' incorporates:
     *  Constant: '<S10>/t_delay_fail73'
     *  Switch: '<S10>/Switch'
     *  Switch: '<S10>/Switch1'
     *  Switch: '<S10>/Switch2'
     *  Switch: '<S10>/Switch3'
     *  Switch: '<S10>/Switch4'
     *  Switch: '<S10>/Switch5'
     */
    digd_st_edcpFlt = ((uint8)0U);
  } else {
    /* Switch: '<S10>/Switch' incorporates:
     *  Constant: '<S10>/t_delay_fail1'
     *  Switch: '<S10>/Switch1'
     *  Switch: '<S10>/Switch12'
     *  Switch: '<S10>/Switch2'
     *  Switch: '<S10>/Switch3'
     *  Switch: '<S10>/Switch4'
     *  Switch: '<S10>/Switch5'
     */
    digd_st_edcpFlt = ((uint8)15U);
  }

  /* End of Switch: '<S10>/Switch' */

  /* Switch: '<S10>/Switch6' incorporates:
   *  Constant: '<S10>/t_delay_fail59'
   *  Constant: '<S10>/t_delay_fail60'
   *  Logic: '<S10>/Logical Operator14'
   *  RelationalOperator: '<S10>/Relational Operator15'
   *  RelationalOperator: '<S10>/Relational Operator16'
   *  Switch: '<S10>/Switch10'
   *  Switch: '<S10>/Switch11'
   *  Switch: '<S10>/Switch13'
   *  Switch: '<S10>/Switch7'
   *  Switch: '<S10>/Switch8'
   *  Switch: '<S10>/Switch9'
   */
  if (digd_b_hbcpOvrCurrDebd) {
    /* Switch: '<S10>/Switch6' incorporates:
     *  Constant: '<S10>/t_delay_fail74'
     */
    digd_st_hbcpFlt = ((uint8)2U);
  } else if (digd_b_hbcpIdlyDebd) {
    /* Switch: '<S10>/Switch7' incorporates:
     *  Constant: '<S10>/t_delay_fail75'
     *  Switch: '<S10>/Switch6'
     */
    digd_st_hbcpFlt = ((uint8)3U);
  } else if (digd_b_hbcpOvrVoltDebd) {
    /* Switch: '<S10>/Switch8' incorporates:
     *  Constant: '<S10>/t_delay_fail76'
     *  Switch: '<S10>/Switch6'
     *  Switch: '<S10>/Switch7'
     */
    digd_st_hbcpFlt = ((uint8)4U);
  } else if (digd_b_hbcpOvrTmpDebd) {
    /* Switch: '<S10>/Switch9' incorporates:
     *  Constant: '<S10>/t_delay_fail77'
     *  Switch: '<S10>/Switch6'
     *  Switch: '<S10>/Switch7'
     *  Switch: '<S10>/Switch8'
     */
    digd_st_hbcpFlt = ((uint8)5U);
  } else if (digd_b_hbcpBlockDebd) {
    /* Switch: '<S10>/Switch10' incorporates:
     *  Constant: '<S10>/t_delay_fail78'
     *  Switch: '<S10>/Switch6'
     *  Switch: '<S10>/Switch7'
     *  Switch: '<S10>/Switch8'
     *  Switch: '<S10>/Switch9'
     */
    digd_st_hbcpFlt = ((uint8)6U);
  } else if (digd_b_hbcpUdVoltDebd) {
    /* Switch: '<S10>/Switch11' incorporates:
     *  Constant: '<S10>/t_delay_fail79'
     *  Switch: '<S10>/Switch10'
     *  Switch: '<S10>/Switch6'
     *  Switch: '<S10>/Switch7'
     *  Switch: '<S10>/Switch8'
     *  Switch: '<S10>/Switch9'
     */
    digd_st_hbcpFlt = ((uint8)7U);
  } else if ((rtb_DataTypeConversion71 >= 6.0F) && (rtb_DataTypeConversion71 <=
              14.0F)) {
    /* Switch: '<S10>/Switch13' incorporates:
     *  Constant: '<S10>/t_delay_fail80'
     *  Switch: '<S10>/Switch10'
     *  Switch: '<S10>/Switch11'
     *  Switch: '<S10>/Switch6'
     *  Switch: '<S10>/Switch7'
     *  Switch: '<S10>/Switch8'
     *  Switch: '<S10>/Switch9'
     */
    digd_st_hbcpFlt = ((uint8)0U);
  } else {
    /* Switch: '<S10>/Switch6' incorporates:
     *  Constant: '<S10>/t_delay_fail3'
     *  Switch: '<S10>/Switch10'
     *  Switch: '<S10>/Switch11'
     *  Switch: '<S10>/Switch13'
     *  Switch: '<S10>/Switch7'
     *  Switch: '<S10>/Switch8'
     *  Switch: '<S10>/Switch9'
     */
    digd_st_hbcpFlt = ((uint8)15U);
  }

  /* End of Switch: '<S10>/Switch6' */

  /* Update for UnitDelay: '<S376>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE = digd_b_edcpOvrTmpDebd;

  /* Update for UnitDelay: '<S377>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_g = digd_b_edcpIdlyDebd;

  /* Update for UnitDelay: '<S378>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_c = digd_b_hbcpBlockDebd;

  /* Update for UnitDelay: '<S379>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_a = digd_b_hbcpOvrCurrDebd;

  /* Update for UnitDelay: '<S380>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_i = digd_b_edcpUdVoltDebd;

  /* Update for UnitDelay: '<S381>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_p = digd_b_edcpOvrVoltDebd;

  /* Update for UnitDelay: '<S382>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_a3 = digd_b_edcpBlockDebd;

  /* Update for UnitDelay: '<S383>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_k = digd_b_edcpOvrCurrDebd;

  /* Update for UnitDelay: '<S384>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_n = digd_b_hbcpOvrTmpDebd;

  /* Update for UnitDelay: '<S385>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_e = digd_b_hbcpIdlyDebd;

  /* Update for UnitDelay: '<S386>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_d = digd_b_hbcpUdVoltDebd;

  /* Update for UnitDelay: '<S387>/Unit Delay' */
  swc_DIAG_ARID_DEF.UnitDelay_DSTATE_o = digd_b_hbcpOvrVoltDebd;

  /* End of Outputs for S-Function (fcgen): '<S1>/Function-Call Generator' */

  /* Logic: '<S9>/OR3' */
  rtb_OR3_m = (swc_DIAG_ARID_DEF.DataTypeConversion254 ||
               swc_DIAG_ARID_DEF.DataTypeConversion123 ||
               swc_DIAG_ARID_DEF.DataTypeConversion82);

  /* Outputs for Atomic SubSystem: '<S366>/turnON_delay5' */
  /* Constant: '<S366>/Constant198' incorporates:
   *  Constant: '<S366>/t_step175'
   */
  swc_DIAG_turnON_delay(rtb_OR3_m, macc_tm_ignOnDeb_s, ((float32)
    MAC_TASK_INTERVAL_S), &rtb_flg_out_nk,
                        &swc_DIAG_ARID_DEF.ARID_DEF_turnON_delay5_m);

  /* End of Outputs for SubSystem: '<S366>/turnON_delay5' */

  /* DataTypeConversion: '<Root>/Data Type Conversion29' incorporates:
   *  Inport generated from: '<Root>/vcsb_HVSM_in12'
   */
  rtb_DataTypeConversion29 = Rte_IRead_swc_DIAG_Step_vcsb_HVSM_hvbd_e_PmmStatus();

  /* Outport generated from: '<Root>/Out Bus Element3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion7'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_st_edcpFlt(digd_st_edcpFlt);

  /* Outport generated from: '<Root>/Out Bus Element4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion6'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_st_hbcpFlt(digd_st_hbcpFlt);

  /* Outport generated from: '<Root>/Out Bus Element11' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion5'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_st_vehSysErrLevel
    (digd_st_vehSysErrLevel);

  /* Outport generated from: '<Root>/Out Bus Element1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion248'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_acpd_b_accPed1Vld(acpd_b_accPed1Vld);

  /* Outport generated from: '<Root>/Out Bus Element2' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion247'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_acpd_b_accPed2Vld(acpd_b_accPed2Vld);

  /* Outport generated from: '<Root>/Out Bus Element17' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion244'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_brpd_b_brkSwtMismatch(brpd_b_brkSwtMismatch);

  /* Outport generated from: '<Root>/Out Bus Element18' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion243'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP
    (digd_b_vcuVehLvl22Flt_flg_BRP);

  /* Outport generated from: '<Root>/Out Bus Element42' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion104'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_macd_b_EVCANBusoffDebd
    (digd_b_vcuLvl21Flt_MAC);

  /* Outport generated from: '<Root>/Out Bus Element39' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion36'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl1Flt_flg(digd_b_VehLvl1Flt_flg);

  /* Outport generated from: '<Root>/Out Bus Element45' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion113'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl21Flt_flg
    (digd_b_VehLvl21Flt_flg);

  /* Outport generated from: '<Root>/Out Bus Element46' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion112'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg
    (digd_b_VehLvl31Flt_flg);

  /* Outport generated from: '<Root>/Out Bus Element47' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion111'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg
    (digd_b_VehLvl32Flt_flg);

  /* Outport generated from: '<Root>/Out Bus Element48' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion110'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg
    (digd_b_VehLvl33Flt_flg);

  /* Outport generated from: '<Root>/Out Bus Element49' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion109'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl22Flt_flg
    (digd_b_VehLvl22Flt_flg);

  /* Outport generated from: '<Root>/Out Bus Element50' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion108'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl23Flt_flg
    (digd_b_VehLvl23Flt_flg);

  /* Outport generated from: '<Root>/Out Bus Element5' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion9'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_ddid_b_egsmMsgErr
    (swc_DIAG_ARID_DEF.SignalConversion5);

  /* Outport generated from: '<Root>/Out Bus Element6' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion8'
   *  Inport generated from: '<Root>/vild_b_flgBMSMsgErr'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_ddid_b_bmsMsgErr
    (Rte_IRead_swc_DIAG_Step_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr());

  /* Outport generated from: '<Root>/Out Bus Element7' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion15'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_bmsFltLv4A
    (digd_b_vcuVehLvl33Flt_flg_HVB);

  /* Outport generated from: '<Root>/Out Bus Element8' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion17'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuFltLv2A
    (digd_b_vcuVehLvl21Flt_flg_EAD);

  /* Outport generated from: '<Root>/Out Bus Element9' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion18'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuFltLv3A
    (digd_b_vcuVehLvl31Flt_flg_EAD);

  /* Outport generated from: '<Root>/Out Bus Element10' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion11'
   *  Inport generated from: '<Root>/vild_b_flgMCUMsgErr'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuMsgErr
    (Rte_IRead_swc_DIAG_Step_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr());

  /* Outport generated from: '<Root>/Out Bus Element12' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion21'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_macd_b_EVCANBusoff31Err
    (swc_DIAG_ARID_DEF.LogicalOperator3);

  /* Outport generated from: '<Root>/Out Bus Element13' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion32'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP
    (brpd_b_VpEnOvTmHiPreDebd);

  /* Outport generated from: '<Root>/Out Bus Element14' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion34'
   */
  Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_vehCrashFltLvl33
    (digd_b_vcuVehLvl33Flt_flg_CES);
}

/* Model initialize function */
void swc_DIAG_Init(void)
{
  {
    /* local block i/o variables */
    boolean rtb_flg_out_nk;
    swc_DIAG_ARID_DEF.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    swc_DIAG_ARID_DEF.Subsystem_Trig_ZCE = POS_ZCSIG;

    /* SystemInitialize for Atomic SubSystem: '<S365>/turnON_delay5' */
    swc_DIAG_turnON_delay_Init(&swc_DIAG_ARID_DEF.flg_out_c);

    /* End of SystemInitialize for SubSystem: '<S365>/turnON_delay5' */

    /* SystemInitialize for Atomic SubSystem: '<S364>/turnON_delay5' */
    swc_DIAG_turnON_delay_Init(&swc_DIAG_ARID_DEF.flg_out_h);

    /* End of SystemInitialize for SubSystem: '<S364>/turnON_delay5' */

    /* SystemInitialize for Atomic SubSystem: '<S367>/turnON_delay5' */
    swc_DIAG_turnON_delay_Init(&swc_DIAG_ARID_DEF.flg_out);

    /* End of SystemInitialize for SubSystem: '<S367>/turnON_delay5' */

    /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/ACP_Diag'
     */
    swc_DIAG_ACP_Diag_Init();

    /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/BRP_Diag'
     */
    swc_DIAG_BRP_Diag_Init();

    /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/HVB_Diag'
     */
    swc_DIAG_HVB_Diag_Init();

    /* SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' incorporates:
     *  SubSystem: '<S1>/MAC_Diag'
     */
    swc_DIAG_MAC_Diag_Init();

    /* End of SystemInitialize for S-Function (fcgen): '<S1>/Function-Call Generator' */

    /* SystemInitialize for Atomic SubSystem: '<S366>/turnON_delay5' */
    swc_DIAG_turnON_delay_Init(&rtb_flg_out_nk);

    /* End of SystemInitialize for SubSystem: '<S366>/turnON_delay5' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
