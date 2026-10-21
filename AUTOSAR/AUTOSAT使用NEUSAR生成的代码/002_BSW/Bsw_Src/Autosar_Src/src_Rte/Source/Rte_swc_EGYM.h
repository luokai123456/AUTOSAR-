 
/*
************************************************************************************************************************
*
* File name: Rte_swc_EGYM.h
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
#ifndef RTE_SWC_EGYM_H_
#define RTE_SWC_EGYM_H_

#include "Rte_swc_EGYM_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_maxPwrLim_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_minPwrLim_kW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_acEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_accyEnbFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_mcuEnbFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_obcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_zeroPwrFb;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pct_vcuChgDepReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_st_vcuChgLimResp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_airCmprSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_iptWorkSt;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_24vDcdcModAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hcmMaiRlyNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcOutpt_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hvbZeroPwrReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbDCChgCurReq_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxAlwChgCurrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_tboxChgDepth;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_PTCActPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_acwpHeatPower_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_airCmprAct_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_iptActPwr_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pwr_ptcActPwrRear_kW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_actWorkSts1;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmAccConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmPtcDefRlyStFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDCChgProcss;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ptcConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgLmtSw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_bmsd_e_modeTgt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_dchaOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3HW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcConnStsFb;
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
#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_accd_st_airCmprSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_accd_st_airCmprSt.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_accd_st_iptWorkSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_accd_st_iptWorkSt.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_dccd_e_24vDcdcModAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_dccd_e_24vDcdcModAct.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_dccd_pwr_dcdcHVpwr_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_hvbd_e_hvbMaiRlyPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_hvbd_pwr_PeakDischMax_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_hvbd_st_hcmMaiRlyNeg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_hvbd_st_hcmMaiRlyNeg.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_obcd_pwr_obcOutpt_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_obcd_pwr_obcOutpt_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_obcd_pwr_obcRlTmOutpt_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgMaxChgCurr.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_b_hvbZeroPwrReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_b_hvbZeroPwrReq.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_i_hvbDCChgCurReq_A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_i_hvbDCChgCurReq_A.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pct_tboxAlwChgCurrMax() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pct_tboxAlwChgCurrMax.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pct_tboxChgDepth() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pct_tboxChgDepth.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_PTCActPwr_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_PTCActPwr_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_acwpHeatPower_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_acwpHeatPower_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_airCmprAct_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_airCmprAct_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_iptActPwr_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_iptActPwr_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_pwr_ptcActPwrRear_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_pwr_ptcActPwrRear_kW.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_actWorkSts1() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_actWorkSts1.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_hcmAccConnStsFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_hcmAccConnStsFb.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_hcmPtcDefRlyStFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_hcmPtcDefRlyStFb.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_hvbDCChgProcss() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_hvbDCChgProcss.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_obcChgSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_obcChgSts.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_ptcConnStsFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_ptcConnStsFb.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_st_tboxChgLmtSw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_st_tboxChgLmtSw.value)

#define Rte_IRead_swc_EGYM_Step_vcib_VCIP_vild_u_hvbVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_accd_pwr_hvAttpwr_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_accd_pwr_hvAttpwr_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_accd_pwr_maxPwrLim_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_maxPwrLim_kW.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_accd_pwr_maxPwrLim_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_maxPwrLim_kW.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_accd_pwr_minPwrLim_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_minPwrLim_kW.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_accd_pwr_minPwrLim_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_accd_pwr_minPwrLim_kW.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_acEnbAllowFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_acEnbAllowFlg.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_b_acEnbAllowFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_acEnbAllowFlg.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_accyEnbFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_accyEnbFlg.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_b_accyEnbFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_accyEnbFlg.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_mcuEnbFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_mcuEnbFlg.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_b_mcuEnbFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_mcuEnbFlg.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_obcEnbAllowFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_obcEnbAllowFlg.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_b_obcEnbAllowFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_obcEnbAllowFlg.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_ptcEnbAllowFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_ptcEnbAllowFlg.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_b_ptcEnbAllowFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_ptcEnbAllowFlg.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_b_zeroPwrFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_zeroPwrFb.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_b_zeroPwrFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_b_zeroPwrFb.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_i_bmshAlwChgCurrMax.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_pct_vcuChgDepReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pct_vcuChgDepReq.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_pct_vcuChgDepReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pct_vcuChgDepReq.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_accmHvClPwrAllwd_kW.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_acwpHeatPwrCnsAllwd.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_pwr_ptcHvHtPwrAllwd_kW.value \
)

#define Rte_IWrite_swc_EGYM_Step_vcsb_EGYM_egmd_st_vcuChgLimResp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_st_vcuChgLimResp.value = (data) \
)

#define Rte_IWriteRef_swc_EGYM_Step_vcsb_EGYM_egmd_st_vcuChgLimResp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_EGYM_egmd_st_vcuChgLimResp.value \
)

#define Rte_IRead_swc_EGYM_Step_vcsb_HVSM_bmsd_e_modeTgt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_HVSM_bmsd_e_modeTgt.value)

#define Rte_IRead_swc_EGYM_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd.value)

#define Rte_IRead_swc_EGYM_Step_vcsb_HVSM_hvbd_b_dchaOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_HVSM_hvbd_b_dchaOn.value)

#define Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_b_heaterEna() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_b_heaterEna.value)

#define Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_b_heaterEna2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_b_heaterEna2.value)

#define Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_b_heaterEna3HW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_b_heaterEna3HW.value)

#define Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_st_acwpHeat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_st_acwpHeat.value)

#define Rte_IRead_swc_EGYM_Step_vcsb_THSM_thmd_st_ptcConnStsFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_EGYM_swc_EGYM_Step.Rte_vcsb_THSM_thmd_st_ptcConnStsFb.value)

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
FUNC(void, swc_EGYM_CODE) swc_EGYM_Step(void);
FUNC(void, swc_EGYM_CODE) swc_EGYM_Init(void);
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
#endif /* RTE_SWC_EGYM_H_ */
 
 
 
