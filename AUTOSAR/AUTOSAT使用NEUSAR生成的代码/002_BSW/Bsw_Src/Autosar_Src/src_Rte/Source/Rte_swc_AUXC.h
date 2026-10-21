 
/*
************************************************************************************************************************
*
* File name: Rte_swc_AUXC.h
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
#ifndef RTE_SWC_AUXC_H_
#define RTE_SWC_AUXC_H_

#include "Rte_swc_AUXC_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpLoPreFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpRlyFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSnrFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacPumpSysFailFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLow;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowEVDis;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowInhDrv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_bdcacEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_bdcacTmOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp1Rly;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_brkPmp2Rly;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_pumpRdy;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_p_VacPumpPressure_kPa;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_u_VacPumpVol_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_lvbd_b_lvbSOCValid;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_lvbd_q_lvbSOC_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_b_epsStopFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_DryAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_ResrAirSwitch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPumpFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_vacTankLowPrs;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_AirPres_kpa;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_p_brkVacuumPres_bar;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_st_bdcacWrk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_crash;
extern VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_modeAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_p_frontAirTankPres_bar;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_p_rearAirTankPres_bar;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_st_epsErrorCode;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkAirPres_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_VacTkEnFb_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_brkVacuumPres_V;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_vacTkPowSup_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
extern VAR(EngStartType, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTyp;
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
#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_b_DryAirSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_b_DryAirSwitch.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_b_ResrAirSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_b_ResrAirSwitch.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_b_brkPumpFault() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_b_brkPumpFault.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_b_vacTankLowPrs() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_b_vacTankLowPrs.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_p_AirPres_kpa() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_p_AirPres_kpa.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_p_brkVacuumPres_bar() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_p_brkVacuumPres_bar.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_brpd_st_bdcacWrk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_brpd_st_bdcacWrk.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_cesd_b_crash() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_cesd_b_crash.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_dccd_e_modeAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_dccd_e_modeAct.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_lvbd_t_lvbEstTemp_C() \
  (0.0F)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_lvbd_u_dcdcLVBusActFilt_V() \
  (0.0F)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_macd_p_frontAirTankPres_bar() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_macd_p_frontAirTankPres_bar.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_macd_p_rearAirTankPres_bar() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_macd_p_rearAirTankPres_bar.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_macd_st_epsErrorCode() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_macd_st_epsErrorCode.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_b_flgNetConfgABS() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_u_VacTkAirPres_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_u_VacTkAirPres_V.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_u_VacTkEnFb_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_u_VacTkEnFb_V.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_u_brkVacuumPres_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_u_brkVacuumPres_V.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_vild_u_vacTkPowSup_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vild_u_vacTkPowSup_V.value)

#define Rte_IRead_swc_AUXC_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmHiPreFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpEnOvrTmLoPreFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpLoPreFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpLoPreFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpLoPreFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpLoPreFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpRlyEn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyEn.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpRlyEn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyEn.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpRlyFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpRlyFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpRlyFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpSnrFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSnrFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpSnrFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSnrFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpSysFailFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSysFailFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacPumpSysFailFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacPumpSysFailFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_VacTkAirPresLowFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLow(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLow.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLow() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLow.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLowEVDis(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLowEVDis.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLowEVDis() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLowEVDis.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLowInhDrv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLowInhDrv.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_airTankPresLowInhDrv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLowInhDrv.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_bdcacEna(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_bdcacEna.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_bdcacEna() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_bdcacEna.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_bdcacTmOut(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_bdcacTmOut.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_bdcacTmOut() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_bdcacTmOut.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_brkPmp1Rly(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_brkPmp1Rly.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_brkPmp1Rly() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_brkPmp1Rly.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_brkPmp2Rly(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_brkPmp2Rly.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_brkPmp2Rly() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_brkPmp2Rly.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_b_pumpRdy(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_pumpRdy.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_b_pumpRdy() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_b_pumpRdy.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_p_VacPumpPressure_kPa(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_p_VacPumpPressure_kPa.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_p_VacPumpPressure_kPa() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_p_VacPumpPressure_kPa.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_brpd_u_VacPumpVol_V(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_u_VacPumpVol_V.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_brpd_u_VacPumpVol_V() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_brpd_u_VacPumpVol_V.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_lvbd_b_lvbSOCValid(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_lvbd_b_lvbSOCValid.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_lvbd_b_lvbSOCValid() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_lvbd_b_lvbSOCValid.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_lvbd_q_lvbSOC_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_lvbd_q_lvbSOC_pct.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_lvbd_q_lvbSOC_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_lvbd_q_lvbSOC_pct.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_pscd_b_epsEna(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_b_epsEna.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_pscd_b_epsEna() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_b_epsEna.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_pscd_b_epsStopFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_b_epsStopFlt.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_pscd_b_epsStopFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_b_epsStopFlt.value \
)

#define Rte_IWrite_swc_AUXC_Step_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz.value = (data) \
)

#define Rte_IWriteRef_swc_AUXC_Step_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_AUXC_pscd_frq_epsFrqTgt_Hz.value \
)

#define Rte_IRead_swc_AUXC_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value)

#define Rte_IRead_swc_AUXC_Step_vcsb_HVSM_hvbd_st_ptRdyInd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value)

#define Rte_IRead_swc_AUXC_Step_vcsb_PTSM_engd_e_engState() \
  (0U)

#define Rte_IRead_swc_AUXC_Step_vcsb_VOMM_essd_e_engStrtTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_AUXC_swc_AUXC_Step.Rte_vcsb_VOMM_essd_e_engStrtTyp.value)

#define Rte_IRead_swc_AUXC_Step_vcsb_VOMM_hmmd_b_EVModeEpsEna() \
  (FALSE)

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
FUNC(void, swc_AUXC_CODE) swc_AUXC_Step(void);
FUNC(void, swc_AUXC_CODE) swc_AUXC_Init(void);
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
#endif /* RTE_SWC_AUXC_H_ */
 
 
 
