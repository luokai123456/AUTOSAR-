 
/*
************************************************************************************************************************
*
* File name: Rte_swc_DIAG.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 3.0
* Author/Date: Gaol/2022.6.14
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
*/
#ifndef RTE_SWC_DIAG_H_
#define RTE_SWC_DIAG_H_

#include "Rte_swc_DIAG_Type.h"
#include "Rte_DataHandleType.h"

#ifndef RTE_CORE                                     
#ifdef RTE_APPLICATION_HEADER_FILE                   
# error Multiple application header files included.  
#endif                                               
#define RTE_APPLICATION_HEADER_FILE                  
#ifndef RTE_PTR2ARRAYBASETYPE_PASSING                
#define RTE_PTR2ARRAYBASETYPE_PASSING                
#endif                                               
#endif                                               
                   
#ifdef __cplusplus
extern "C"         
{                  
#endif            

/*
************************************************************************************************************************
*    Buffers for Mode Management
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Mode_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of RTE buffers
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed1Vld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_acpd_b_accPed2Vld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_brpd_b_brkSwtMismatch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_ddid_b_bmsMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_ddid_b_egsmMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl1Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl21Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl22Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl23Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_bmsFltLv4A;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv2A;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuFltLv3A;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_mcuMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vehCrashFltLvl33;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_edcpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_hbcpFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_st_vehSysErrLevel;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoff31Err;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoffDebd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_crash;
extern VAR(FaultStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2FltSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_u_batIntSmpl_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt1Actv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_brkSwt2Actv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgACU;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP1FbPWM;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_WatPmpEP2FbPWM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDischgFltReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbStsDischgFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_5VT1IntSmpl_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_5VT2IntSmpl_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Acc1Raw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_Acc2Raw_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpLoPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSnrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSysFailFlt;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_adcCanBusOff_vild_b_adcCanBusOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_evCanBusOff_vild_b_evCanBusOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgClearDTC_vild_b_flgClearDTC;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_PMS_BswAswRte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_10ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core1_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for inter-runnable variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE Helper-Functions prototypes
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    API prototypes
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Switch_<p>_<m>
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_IRead_<r>_<p>_<d>
*    Rte_IStatus_<r>_<p>_<d>
*    Rte_IWrite_<r>_<p>_<d>
*    Rte_IWriteRef_<r>_<p>_<d>
*    Rte_IInvalidate_<r>_<p>_<d>
************************************************************************************************************************
*/
#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_cesd_b_crash() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_cesd_b_crash.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_eadd_e_inv2FltSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_eadd_e_inv2FltSts.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_hvbd_b_hvilOpen() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_macd_u_batIntSmpl_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_macd_u_batIntSmpl_V.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_obcd_b_obcWakeUp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_b_brkSwt1Actv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_b_brkSwt1Actv.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_b_brkSwt2Actv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_b_brkSwt2Actv.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_b_flgFctCfgACU() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_b_flgFctCfgACU.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_b_flgNetConfgABS() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_pct_WatPmpEP1FbPWM() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP1FbPWM.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_pct_WatPmpEP2FbPWM() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_pct_WatPmpEP2FbPWM.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_st_bmsDlyDataUpldEnb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_st_hvbDischgFltReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_st_hvbDischgFltReq.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_st_hvbStsDischgFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_st_hvbStsDischgFlt.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_u_5VT1IntSmpl_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_u_5VT1IntSmpl_V.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_u_5VT2IntSmpl_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_u_5VT2IntSmpl_V.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_u_Acc1Raw_mV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_u_Acc1Raw_mV.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vild_u_Acc2Raw_mV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vild_u_Acc2Raw_mV.value)

#define Rte_IRead_swc_DIAG_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt.value)

#define Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt.value)

#define Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpLoPreFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpLoPreFlt.value)

#define Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpRlyFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyFlt.value)

#define Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpSnrFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSnrFlt.value)

#define Rte_IRead_swc_DIAG_Step_vcsb_AUXC_brpd_b_VacPumpSysFailFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSysFailFlt.value)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_acpd_b_accPed1Vld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_acpd_b_accPed1Vld.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_acpd_b_accPed1Vld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_acpd_b_accPed1Vld.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_acpd_b_accPed2Vld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_acpd_b_accPed2Vld.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_acpd_b_accPed2Vld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_acpd_b_accPed2Vld.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_brpd_b_brkSwtMismatch(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_brpd_b_brkSwtMismatch.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_brpd_b_brkSwtMismatch() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_brpd_b_brkSwtMismatch.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_ddid_b_bmsMsgErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_ddid_b_bmsMsgErr.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_ddid_b_bmsMsgErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_ddid_b_bmsMsgErr.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_ddid_b_egsmMsgErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_ddid_b_egsmMsgErr.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_ddid_b_egsmMsgErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_ddid_b_egsmMsgErr.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl1Flt_flg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl1Flt_flg.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl1Flt_flg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl1Flt_flg.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl21Flt_flg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl21Flt_flg.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl21Flt_flg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl21Flt_flg.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl22Flt_flg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl22Flt_flg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl23Flt_flg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl23Flt_flg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_bmsFltLv4A(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_bmsFltLv4A.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_bmsFltLv4A() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_bmsFltLv4A.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuFltLv2A(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv2A.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuFltLv2A() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv2A.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuFltLv3A(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv3A.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuFltLv3A() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv3A.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuMsgErr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuMsgErr.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_mcuMsgErr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_mcuMsgErr.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_b_vehCrashFltLvl33(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vehCrashFltLvl33.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_b_vehCrashFltLvl33() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_b_vehCrashFltLvl33.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_st_edcpFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_edcpFlt.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_st_edcpFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_edcpFlt.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_st_hbcpFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_hbcpFlt.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_st_hbcpFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_hbcpFlt.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_digd_st_vehSysErrLevel(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_vehSysErrLevel.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_digd_st_vehSysErrLevel() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_digd_st_vehSysErrLevel.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_macd_b_EVCANBusoff31Err(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoff31Err.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_macd_b_EVCANBusoff31Err() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoff31Err.value \
)

#define Rte_IWrite_swc_DIAG_Step_vcsb_DIAG_macd_b_EVCANBusoffDebd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoffDebd.value = (data) \
)

#define Rte_IWriteRef_swc_DIAG_Step_vcsb_DIAG_macd_b_EVCANBusoffDebd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoffDebd.value \
)

#define Rte_IRead_swc_DIAG_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_adcCanBusOff_vild_b_adcCanBusOff() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_adcCanBusOff_vild_b_adcCanBusOff.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_evCanBusOff_vild_b_evCanBusOff() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_evCanBusOff_vild_b_evCanBusOff.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgABSMsgErr_vild_b_flgABSMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgABSSpdMsgErr_vild_b_flgABSSpdMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgACUAlvCtrErr_vild_b_flgACUAlvCtrErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgACUCsmErr_vild_b_flgACUCsmErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgACUMsgErr_vild_b_flgACUMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgBMSAlvCtrErr_vild_b_flgBMSAlvCtrErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgBMSCsmErr_vild_b_flgBMSCsmErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgBMSMsgErr_vild_b_flgBMSMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgCSMAlvCtrErr_vild_b_flgCSMAlvCtrErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgCSMCsmErr_vild_b_flgCSMCsmErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgCSMMsgErr_vild_b_flgCSMMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgClearDTC_vild_b_flgClearDTC() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgClearDTC_vild_b_flgClearDTC.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgDCDCMsgErr_vild_b_flgDCDCMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEGSMAlvCtrErr_vild_b_flgEGSMAlvCtrErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEGSMCsmErr_vild_b_flgEGSMCsmErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEGSMMsgErr_vild_b_flgEGSMMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEHBAlvCtrErr_vild_b_flgEHBAlvCtrErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgEHBCsmErr_vild_b_flgEHBCsmErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgIPUAlvCtrErr_vild_b_flgIPUAlvCtrErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgIPUCsmErr_vild_b_flgIPUCsmErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgMCUMsgErr_vild_b_flgMCUMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgPEPSAlvErr_vild_b_flgPEPSAlvErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgPEPSCsmErr_vild_b_flgPEPSCsmErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_flgPEPSMsgErr_vild_b_flgPEPSMsgErr.value)

#define Rte_IRead_swc_DIAG_Step_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_DIAG_swc_DIAG_Step.Rte_vild_b_pmsCanBusOff_vild_b_pmsCanBusOff.value)

/*
************************************************************************************************************************
*    Rte_Receive_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Send_<p>_<d> (explicit S/R communication with isQueued = true)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Rte_Trigger_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_IsUpdated_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/
#ifndef RTE_CORE
#endif /* !defined(RTE_CORE) */

/*
************************************************************************************************************************
*    Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_IrvRead_<p>_<d> and Rte_IrvWrite_<p>_<d> Inter-runnable variables
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    extern declaration of calibration parameters buffers
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_CData (SW-C local calibration parameters) and Rte_Prm (Calibration component calibration parameters)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    extern declaration of Buffers for Memory Block
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Rte_Pim (Per-Instance Memory)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_DIAG_CODE) swc_DIAG_Step(void);
FUNC(void, swc_DIAG_CODE) swc_DIAG_Init(void);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_SWC_DIAG_H_ */
 
 
 
