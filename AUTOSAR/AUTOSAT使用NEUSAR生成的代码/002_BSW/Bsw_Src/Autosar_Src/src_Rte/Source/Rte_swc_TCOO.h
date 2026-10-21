 
/*
************************************************************************************************************************
*
* File name: Rte_swc_TCOO.h
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
#ifndef RTE_SWC_TCOO_H_
#define RTE_SWC_TCOO_H_

#include "Rte_swc_TCOO_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_apdd_tq_whlDem_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_b_drvPfmncDrgDec;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_st_RegenLvlDisp;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlDragDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_msgd_tq_targetTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tdad_tq_whlDem_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_accPedlPosVirtVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_ehbDisEnbCreep;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_gpOvrd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdActv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_ehbOvrdTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_st_whlAcceSupprsn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_b_accPedlPosVld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPosLimd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlTorqEn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_fact_mot2GearRat;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_tq_mot2ActTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_PeakChMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_StatChMax_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_fact_trsm2GearRat;
extern VAR(SInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmEngRecSwtReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ehbVlcCddActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgChgTyp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModConn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgNetConfgABS;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_l_whlRad_m;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_csmRgnLvlSet;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ehbIsaSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAbsOvrdActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbAebActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbDtcActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqIncReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcAvailb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbVlcTrqReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_pdcBrkFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_axle2MinTq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMin_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_b_eCreepReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_tq_whlDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
extern VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive;
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
#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_b_accPedlPosVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_acpd_b_accPedlPosVld.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPosLimd_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_acpd_x_accPedlPosLimd_pct.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_adcd_b_adcCtrlTorqEn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_adcd_b_adcCtrlTorqEn.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_adcd_tq_adcTgtDrvTorq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_brpd_e_brkPedalStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_brpd_x_brkPedlPos_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_eadd_fact_mot2GearRat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_eadd_fact_mot2GearRat.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_eadd_tq_mot2ActTq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_eadd_tq_mot2ActTq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_hvbd_pwr_PeakChMax_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_hvbd_pwr_PeakChMax_kW.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_hvbd_pwr_StatChMax_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_hvbd_pwr_StatChMax_kW.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_hvbd_q_hvbSOC_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_trad_fact_trsm2GearRat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_trad_fact_trsm2GearRat.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_trad_st_trsm2GearAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_a_yrsLongitAcce_mps2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_csmEngRecSwtReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_csmEngRecSwtReq.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_ehbIsaPtTrqDecReqActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_ehbVlcCddActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_ehbVlcCddActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgFctCfgChgTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgFctCfgDrvMod() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgFctCfgDrvModConn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModConn.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgFctCfgDrvModStor() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_b_flgNetConfgABS() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_b_flgNetConfgABS.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_l_whlRad_m() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_l_whlRad_m.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_csmRgnLvlSet() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_csmRgnLvlSet.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_ehbIsaSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_ehbIsaSts.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_flgFctCfgMotTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vild_tq_ehbIsaPtTrqDecReq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ESPActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbAbsOvrdActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbAbsOvrdActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbAebActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbAebActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbDtcActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbDtcActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbTrqDecReqActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbTrqIncReqActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbTrqIncReqActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbVlcActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbVlcActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbVlcAvailb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbVlcAvailb.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_ehbVlcTrqReqActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_ehbVlcTrqReqActv.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_pdcBrkFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_pdcBrkFlg.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_b_vehSpdVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_st_ehbMbRgnTgtWhlSts.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_axle2MaxTqReq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_axle2MinTqReq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_axle2RgnBrkTqReq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_ehbMbRgnTgtWhl_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqDecReq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_ehbTrqIncReq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_tq_ehbVlcTrqReq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_eadd_tq_mot2MaxSTTq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_eadd_tq_mot2MinSTTq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_tqld_tq_axle2MaxTq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCAP_tqld_tq_axle2MinTq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_tqld_tq_axle2MinTq_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCAP_tqld_tq_whlMax_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCAP_tqld_tq_whlMin_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCAP_tqld_tq_whlMin_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ccdd_tq_whlDem_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ctdd_b_eCreepReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ctdd_b_eCreepReq.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCOO_ctdd_tq_whlDem_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_ctdd_tq_whlDem_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph.value)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_apdd_tq_whlDem_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_apdd_tq_whlDem_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_apdd_tq_whlDem_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_apdd_tq_whlDem_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_b_drvPfmncDrgDec(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_b_drvPfmncDrgDec.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_dtdd_b_drvPfmncDrgDec() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_b_drvPfmncDrgDec.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_st_RegenLvlDisp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_st_RegenLvlDisp.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_dtdd_st_RegenLvlDisp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_st_RegenLvlDisp.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlCoastDrgDem_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlDragDem_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlDragDem_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_dtdd_tq_whlDragDem_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlDragDem_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTq_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_msgd_tq_targetTqReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_msgd_tq_targetTqReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_msgd_tq_targetTqReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_msgd_tq_targetTqReq_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDemUnfilt_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDemUnlim_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDem_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDem_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tdad_tq_whlDem_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tdad_tq_whlDem_Nm.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_b_accPedlPosVirtVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_accPedlPosVirtVld.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tqdd_b_accPedlPosVirtVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_accPedlPosVirtVld.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_b_ehbDisEnbCreep(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_ehbDisEnbCreep.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tqdd_b_ehbDisEnbCreep() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_ehbDisEnbCreep.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_b_gpOvrd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_gpOvrd.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tqdd_b_gpOvrd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_b_gpOvrd.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_st_ehbOvrdActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdActv.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tqdd_st_ehbOvrdActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdActv.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_st_ehbOvrdTyp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdTyp.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tqdd_st_ehbOvrdTyp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_ehbOvrdTyp.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_st_whlAcceSupprsn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_whlAcceSupprsn.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tqdd_st_whlAcceSupprsn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_st_whlAcceSupprsn.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tqdd_x_accPedlPosVirt_pct.value \
)

#define Rte_IWrite_swc_TCOO_Step_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_TCOO_Step_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_TCOO_tvrd_tq_mot2TgtTqReq_Nm.value \
)

#define Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_b_veh4WDModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_b_vehEcoModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_b_vehSportModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_e_driveDirSel() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_VOMM_drid_e_gearLvrPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value)

#define Rte_IRead_swc_TCOO_Step_vcsb_VOMM_hmmd_b_EVModeActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_TCOO_swc_TCOO_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value)

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
FUNC(void, swc_TCOO_CODE) swc_TCOO_Step(void);
FUNC(void, swc_TCOO_CODE) swc_TCOO_Init(void);
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
#endif /* RTE_SWC_TCOO_H_ */
 
 
 
