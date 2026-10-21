 
/*
************************************************************************************************************************
*
* File name: Rte_swc_SCAP.h
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
#ifndef RTE_SWC_SCAP_H_
#define RTE_SWC_SCAP_H_

#include "Rte_swc_SCAP_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_b_mot2TqOff;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MinTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMin_Nm;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(ElMac, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2ModeAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_fact_mot2GearRat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakDischMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatChMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatDischMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearshiftActv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat;
extern VAR(SInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_i_hvbCurr_A;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbVolt_V;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActvRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_accd_pwr_hvAttpwr_kW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_mcuEnbFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Enad;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_st_pwrOffCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_b_rmtCtrlTqOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
extern VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
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
#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_brpd_e_brkPedalStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_e_inv2ModeAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_e_inv2ModeAct.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_fact_mot2GearRat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_fact_mot2GearRat.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBrk_Nm.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailLTBst_Nm.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBrk_Nm.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_eadd_tq_mot2MaxAvailSTBst_Nm.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_pwr_PeakChMax_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_pwr_PeakDischMax_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_pwr_PeakDischMax_kW.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_pwr_StatChMax_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_pwr_StatDischMax_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_pwr_StatDischMax_kW.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_hvbd_q_hvbSOC_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_trad_b_trsm2GearshiftActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_trad_b_trsm2GearshiftActv.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_trad_fact_trsm2GearRat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_trad_st_trsm2GearAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_vild_i_hvbCurr_A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vild_i_hvbCurr_A.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_vild_st_flgFctCfgMotTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_vild_u_hvbVolt_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vild_u_hvbVolt_V.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_vscd_b_ESPActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_vscd_b_ESPActvRaw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vscd_b_ESPActvRaw.value)

#define Rte_IRead_swc_SCAP_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_EGYM_accd_pwr_hvAttpwr_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_EGYM_accd_pwr_hvAttpwr_kW.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_EGYM_egmd_b_mcuEnbFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_EGYM_egmd_b_mcuEnbFlg.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_HVSM_eadd_b_ead2Enad() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_HVSM_eadd_b_ead2Enad.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_OGVL_dtld_st_pwrOffCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_OGVL_dtld_st_pwrOffCmd.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_RMLK_rlcd_b_rmtCtrlTqOff() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_RMLK_rlcd_b_rmtCtrlTqOff.value)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_b_mot2TqOff(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_b_mot2TqOff.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_eadd_b_mot2TqOff() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_b_mot2TqOff.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MaxLTTq_Nm.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MinLTTq_Nm.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_tqld_tq_axle2MinTq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_axle2MinTq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_tqld_tq_axle2MinTq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_axle2MinTq_Nm.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_tqld_tq_whlMax_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_tqld_tq_whlMax_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value \
)

#define Rte_IWrite_swc_SCAP_Step_vcsb_SCAP_tqld_tq_whlMin_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_whlMin_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCAP_Step_vcsb_SCAP_tqld_tq_whlMin_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_SCAP_tqld_tq_whlMin_Nm.value \
)

#define Rte_IRead_swc_SCAP_Step_vcsb_VOMM_drid_b_veh4WDModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_VOMM_drid_b_vehSportModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_VOMM_drid_e_driveDirSel() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_VOMM_hmmd_b_EVModeActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value)

#define Rte_IRead_swc_SCAP_Step_vcsb_VOMM_vsmd_b_VehRun() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCAP_swc_SCAP_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value)

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
FUNC(void, swc_SCAP_CODE) swc_SCAP_Step(void);
FUNC(void, swc_SCAP_CODE) swc_SCAP_Init(void);
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
#endif /* RTE_SWC_SCAP_H_ */
 
 
 
