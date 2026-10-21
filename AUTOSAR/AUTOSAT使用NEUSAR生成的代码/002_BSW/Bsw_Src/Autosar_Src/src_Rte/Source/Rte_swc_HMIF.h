 
/*
************************************************************************************************************************
*
* File name: Rte_swc_HMIF.h
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
#ifndef RTE_SWC_HMIF_H_
#define RTE_SWC_HMIF_H_

#include "Rte_swc_HMIF_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_CruisingDstSwtFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_HazardReqLmpOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_brkSysFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_ePTFault;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_evLampOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_hevLampOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_odoBckpEn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_turtleLmpOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_b_vehOvrLoadEnbl;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_odoTotal_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehCrsDst_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_d_vehDrvRngStandard_km;
extern VAR(PowerFlowMode, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_e_vehPwrFlow;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_m_vehWeight_kg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_num_AecEV_kWhp100km;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_num_errorCode;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_q_hvbSOC_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvModInd;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvPfmncRedn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_drvrOptRmdr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehCalNum;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehDrvMode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehFailLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehOverLoadSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HMIF_vcsb_HMIF_dspd_st_vehSubFailLvl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_AcWrk;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_e_gearLvrPosRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_pwr_mot2ActPwr_kW;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMainRlySts;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_pwr_hvbActRaw_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_V_tankFuelLvl_l;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_ipkOdoBckUpEn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_bcmOdometerbackup;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_ipkOdometerbackup;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_d_odometer_km;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgDspRemainRng;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_ddid_b_bmsMsgErr;
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoff31Err;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_macd_b_EVCANBusoffDebd;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_TCOO_vcsb_TCOO_msgd_tq_targetTqReq_Nm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
extern VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
extern VAR(HEVModeReq, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_drvrHEVModReq;
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
#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_accd_st_AcWrk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_accd_st_AcWrk.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_brpd_e_brkPedalStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_drid_e_gearLvrPosRaw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_drid_e_gearLvrPosRaw.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_eadd_pwr_mot2ActPwr_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_eadd_pwr_mot2ActPwr_kW.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_engd_V_engFuelConsInst_ml() \
  (0.0F)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_engd_dV_engFuelCns_lph() \
  (0.0F)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_engd_st_apuActWrkSt() \
  (0U)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_epbd_e_parkingSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_b_hvbChPwrLimdByTemp.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_b_hvbDischPwrLimdByTemp.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_b_hvilOpen() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_e_hvbMainRlySts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_e_hvbMainRlySts.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_pwr_hvbActRaw_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_pwr_hvbActRaw_kW.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_hvbd_q_hvbSOC_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_macd_V_tankFuelLvl_l() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_macd_V_tankFuelLvl_l.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_obcd_b_obcChrgCablePlugged() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_obcd_b_obcWakeUp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_pmmd_b_driverStartReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_trad_st_trsm1GearAct() \
  (0)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_E_hvbPackRemnEgy_kWh.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_b_ipkOdoBckUpEn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_b_ipkOdoBckUpEn.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_d_bcmOdometerbackup() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_d_bcmOdometerbackup.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_d_ipkOdometerbackup() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_d_ipkOdometerbackup.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_d_odometer_km() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_d_odometer_km.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_st_bmsDlyDataUpldEnb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vild_st_flgFctCfgDspRemainRng() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vild_st_flgFctCfgDspRemainRng.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vscd_b_vehSpdVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value)

#define Rte_IRead_swc_HMIF_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_ddid_b_bmsMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_ddid_b_bmsMsgErr.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl1Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl1Flt_flg.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl21Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl21Flt_flg.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl22Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl22Flt_flg.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl23Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl23Flt_flg.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl31Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl31Flt_flg.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_bmsFltLv4A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_bmsFltLv4A.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_mcuFltLv2A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv2A.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_mcuFltLv3A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_mcuFltLv3A.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_mcuMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_mcuMsgErr.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl1Flt_flg_BRP.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_digd_b_vcuVehLvl22Flt_flg_BRP.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_macd_b_EVCANBusoff31Err() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoff31Err.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_DIAG_macd_b_EVCANBusoffDebd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_DIAG_macd_b_EVCANBusoffDebd.value)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_V_engFuelConsAvg_lp100km.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_CruisingDstSwtFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_CruisingDstSwtFb.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_CruisingDstSwtFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_CruisingDstSwtFb.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_HazardReqLmpOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_HazardReqLmpOn.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_HazardReqLmpOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_HazardReqLmpOn.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_brkSysFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_brkSysFlt.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_brkSysFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_brkSysFlt.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_ePTFault(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_ePTFault.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_ePTFault() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_ePTFault.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_evLampOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_evLampOn.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_evLampOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_evLampOn.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_hevLampOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_hevLampOn.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_hevLampOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_hevLampOn.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_odoBckpEn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_odoBckpEn.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_odoBckpEn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_odoBckpEn.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_turtleLmpOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_turtleLmpOn.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_turtleLmpOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_turtleLmpOn.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_b_vehOvrLoadEnbl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_vehOvrLoadEnbl.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_b_vehOvrLoadEnbl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_b_vehOvrLoadEnbl.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_odoTotal_km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_odoTotal_km.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_d_odoTotal_km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_odoTotal_km.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_pmsOdoBckUpMilg_km.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehCrsDst_km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehCrsDst_km.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehCrsDst_km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehCrsDst_km.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngEVMod_km.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngHEVMod_km.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngStandard_km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngStandard_km.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_d_vehDrvRngStandard_km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_d_vehDrvRngStandard_km.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_e_vehPwrFlow(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_e_vehPwrFlow.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_e_vehPwrFlow() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_e_vehPwrFlow.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_m_vehWeight_kg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_m_vehWeight_kg.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_m_vehWeight_kg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_m_vehWeight_kg.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_num_AecEV_kWhp100km(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_num_AecEV_kWhp100km.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_num_AecEV_kWhp100km() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_num_AecEV_kWhp100km.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_num_errorCode(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_num_errorCode.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_num_errorCode() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_num_errorCode.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_pwr_hvPwrCsmpt_kW.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_pwr_hvPwrRemain_kW.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_q_hvbSOC_pct(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_q_hvbSOC_pct.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_q_hvbSOC_pct() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_q_hvbSOC_pct.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvModInd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvModInd.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvModInd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvModInd.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvPfmncRedn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvPfmncRedn.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvPfmncRedn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvPfmncRedn.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvrOptRmdr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvrOptRmdr.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_st_drvrOptRmdr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_drvrOptRmdr.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehCalNum(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehCalNum.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehCalNum() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehCalNum.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehDrvMode(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehDrvMode.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehDrvMode() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehDrvMode.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehFailLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehFailLvl.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehFailLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehFailLvl.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehOverLoadSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehOverLoadSts.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehOverLoadSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehOverLoadSts.value \
)

#define Rte_IWrite_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehSubFailLvl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehSubFailLvl.value = (data) \
)

#define Rte_IWriteRef_swc_HMIF_Step_vcsb_HMIF_dspd_st_vehSubFailLvl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HMIF_dspd_st_vehSubFailLvl.value \
)

#define Rte_IRead_swc_HMIF_Step_vcsb_HVSM_apud_b_tmpFrcSttApu1() \
  (FALSE)

#define Rte_IRead_swc_HMIF_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_HVSM_hvbd_st_ptRdyInd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_SCAP_ptld_pwr_hvbDischAvail_kW.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_TCOO_eadd_tq_mot2TgtTqReq_Nm.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_TCOO_msgd_tq_targetTqReq_Nm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_TCOO_msgd_tq_targetTqReq_Nm.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_b_veh4WDModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_b_vehEcoModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_b_vehSportModActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_e_driveDirSel() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_drid_e_drvrHEVModReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_drid_e_drvrHEVModReq.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_hmmd_b_EVModeActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_hmmd_b_PHEVModeActive() \
  (FALSE)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_hmmd_b_SHEVModeActive() \
  (FALSE)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_hmmd_e_hmmState() \
  (0U)

#define Rte_IRead_swc_HMIF_Step_vcsb_VOMM_vsmd_b_VehRun() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HMIF_swc_HMIF_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value)

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
FUNC(void, swc_HMIF_CODE) swc_HMIF_Step(void);
FUNC(void, swc_HMIF_CODE) swc_HMIF_Init(void);
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
#endif /* RTE_SWC_HMIF_H_ */
 
 
 
