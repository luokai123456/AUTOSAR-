 
/*
************************************************************************************************************************
*
* File name: Rte_swc_SCOO.h
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
#ifndef RTE_SWC_SCOO_H_
#define RTE_SWC_SCOO_H_

#include "Rte_swc_SCOO_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_intAccTgt_mps2;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_b_accCtrlActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd;
extern VAR(CrsBtnErrSts, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnErrSts;
extern VAR(CrsBtnSts, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsBtnSts;
extern VAR(CrModeMngr_e, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSpdMode;
extern VAR(CruiseSts_e, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_e_crsCtrlSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_tq_whlDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_b_eCreepReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_ctdd_tq_whlDem_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_b_vslTqIntvReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxSpd_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_x_brkPedlPos_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_ccdd_u_cruiseADvoltage_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_a_yrsLongitAcce_mps2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_vscEHBAVHSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ESPActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_ehbTrqDecReqActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSlipWarn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbEPBDynAppSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_st_ehbHHCActive;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_brpd_b_brkSwtMismatch;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl22Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl23Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl31Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehFailLvl;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_OGVL_vcsb_OGVL_dtld_v_dstSpdLim_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_RMLK_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_tqld_tq_whlMax_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_apdd_tq_whlDem_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_dtdd_tq_whlDragDem_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_tqdd_b_ehbDisEnbCreep;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
extern VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxSpd_kph(Float data);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
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
#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_acpd_x_accPedlPos_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_brpd_e_brkPedalStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_brpd_x_brkPedlPos_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_brpd_x_brkPedlPos_pct.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_ccdd_u_cruiseADvoltage_V() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_ccdd_u_cruiseADvoltage_V.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_epbd_e_parkingSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_a_yrsLongitAcce_mps2() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_a_yrsLongitAcce_mps2.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_bcmFrntLftDrAjSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_bcmFrntRDrAjSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_b_flgFctCfgDrvSeat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgECOMaxSpd.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgNormalMaxSpd.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgPowerMaxSpd.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vild_st_vscEHBAVHSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vild_st_vscEHBAVHSts.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_b_ESPActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_b_ESPActv.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_b_ehbTrqDecReqActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_b_ehbTrqDecReqActv.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_b_vehSlipWarn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_b_vehSlipWarn.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_b_vehSpdVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_st_ehbEPBDynAppSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_st_ehbEPBDynAppSts.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_st_ehbHHCActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_st_ehbHHCActive.value)

#define Rte_IRead_swc_SCOO_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_DIAG_brpd_b_brkSwtMismatch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_brpd_b_brkSwtMismatch.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl22Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl23Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_HMIF_dspd_st_vehFailLvl() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_HMIF_dspd_st_vehFailLvl.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_OGVL_dtld_v_dstSpdLim_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_OGVL_dtld_v_dstSpdLim_kph.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_RMLK_rlcd_v_rmtCtrlFctSpdLim_kph.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_SCAP_tqld_tq_whlMax_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCAP_tqld_tq_whlMax_Nm.value)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_acc_intAccTgt_mps2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_acc_intAccTgt_mps2.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_acc_intAccTgt_mps2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_acc_intAccTgt_mps2.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_acc_vehAccTgt_mps2.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_b_accCtrlActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_b_accCtrlActv.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_b_accCtrlActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_b_accCtrlActv.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_b_crsCtrlAccPedlOvrd.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsBtnErrSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnErrSts.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsBtnErrSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnErrSts.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsBtnSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnSts.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsBtnSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsBtnSts.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsCtrlSpdMode(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSpdMode.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsCtrlSpdMode() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSpdMode.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsCtrlSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSts.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_e_crsCtrlSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_e_crsCtrlSts.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_tq_whlDemRawAdv_Nm.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_tq_whlDem_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_tq_whlDem_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_tq_whlDem_Nm.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_v_crsCtrlTgtSpd_kph.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_v_crsTgtSpdQuit_kph.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ccdd_x_accPedlPosVirt_pct.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_a_yrsLongAccAvgVld_mps2.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_b_crpSlopeTrqOffsetEnHld.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_b_eCreepReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_b_eCreepReq.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ctdd_b_eCreepReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_b_eCreepReq.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_n_vehTgtCrpSpdFwd_kph.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_ctdd_tq_whlDem_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_tq_whlDem_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_ctdd_tq_whlDem_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_ctdd_tq_whlDem_Nm.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_vsld_b_vslTqIntvReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_b_vslTqIntvReq.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_vsld_b_vslTqIntvReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_b_vslTqIntvReq.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimFast_Nm.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_tq_whlMaxTqLimSlow_Nm.value \
)

#define Rte_IWrite_swc_SCOO_Step_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph.value = (data) \
)

#define Rte_IWriteRef_swc_SCOO_Step_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_SCOO_vsld_v_vehMaxCfgSpd_kph.value \
)

#define Rte_IRead_swc_SCOO_Step_vcsb_TCOO_apdd_tq_whlDem_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_TCOO_apdd_tq_whlDem_Nm.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlCstDrgDemNoEhb_Nm.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_TCOO_dtdd_tq_whlDragDem_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_TCOO_dtdd_tq_whlDragDem_Nm.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_TCOO_tqdd_b_ehbDisEnbCreep() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_TCOO_tqdd_b_ehbDisEnbCreep.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_VOMM_drid_b_vehEcoModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_VOMM_drid_b_vehSportModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_VOMM_drid_e_driveDirSel() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value)

#define Rte_IRead_swc_SCOO_Step_vcsb_VOMM_vsmd_b_VehRun() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_SCOO_swc_SCOO_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value)

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
#define Rte_Write_vcsb_SCOO_vsld_v_vehMaxSpd_kph Rte_Write_swc_SCOO_vcsb_SCOO_vsld_v_vehMaxSpd_kph
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
FUNC(void, swc_SCOO_CODE) swc_SCOO_Step(void);
FUNC(void, swc_SCOO_CODE) swc_SCOO_Init(void);
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
#endif /* RTE_SWC_SCOO_H_ */
 
 
 
