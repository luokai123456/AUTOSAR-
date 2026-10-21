 
/*
************************************************************************************************************************
*
* File name: Rte_swc_VOMM.h
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
#ifndef RTE_SWC_VOMM_H_
#define RTE_SWC_VOMM_H_

#include "Rte_swc_VOMM_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_epbClsdReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_gearPosVld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_veh4WDModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehEcoModActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_b_vehSportModActv;
extern VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
extern VAR(HEVModeReq, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_drvrHEVModReq;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_st_gearLvrLckInd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStartReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStopReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStrtAbort;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_engStrtComplete;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_motStrtDem;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_motStrtEnad;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_b_strtrRlyDem;
extern VAR(EngStartType, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTyp;
extern VAR(EngStartType, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_essd_e_engStrtTypSeld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_EVModeActive;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_HVBusDischrgComplete;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_emsWake;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_hsdFltClear;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmRdySlp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmWkUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_peuWake;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_startReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuAwb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_vcuRmr;
extern VAR(rt_Array_UInt8_2, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_bm_netModeReq;
extern VAR(NMStatus, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_e_CanNMSts;
extern VAR(PmmMode, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_e_mode;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_num_vcuAddr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_bdCanModeReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_ptCanModeReq;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_stayAwkReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuPwrActvMod;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_st_vcuWkUpReason;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTDisabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTEnabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_StartDemRaw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRunRaw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehStrt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_b_adcCtrlGearEn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_adcTgtGearPostn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_adcd_st_pmsAdcCtrldSts;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_EmergencyStop;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReq4WD;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqECO;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqHEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_drvrModeReqSPORT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_b_parkBtnPressed;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_e_gearLvrPosRaw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_drid_st_gearLvrPosSeql;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_n_mot2ActSpd_rpm;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_pullUpDiagCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcCANMsgValid;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_anyIgnOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ptCanNmStRdy;
extern VAR(KeyAuthStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_e_authenticationStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntLftDrAjSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_bcmFrntRDrAjSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_epbErrSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgChgTyp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvMod;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvModStor;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgDrvSeat;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFnctnConfgEGSM;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_egsmShftLvrFailSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgMotTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehCfg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgCcsts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdDchaCCline;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_AUXC_vcsb_AUXC_brpd_b_airTankPresLowInhDrv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_ddid_b_egsmMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Avail;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_chgCablePlugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_fltPwrShutDn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_rlyTmOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuRdyToSlp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged;
extern VAR(ChargerStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_e_chargerSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_afterRunActive;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_GLOBAL_VAR_INIT
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
#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_acpd_x_accPedlPos_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_adcd_b_adcCtrlGearEn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_adcd_b_adcCtrlGearEn.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_adcd_st_adcTgtGearPostn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_adcd_st_adcTgtGearPostn.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_adcd_st_pmsAdcCtrldSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_adcd_st_pmsAdcCtrldSts.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_brpd_e_brkPedalStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_cesd_b_EmergencyStop() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_cesd_b_EmergencyStop.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReq.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReq4WD() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReq4WD.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReqECO() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReqECO.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReqEV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReqEV.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReqHEV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReqHEV.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_drvrModeReqSPORT() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_drvrModeReqSPORT.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_b_parkBtnPressed() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_b_parkBtnPressed.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_e_gearLvrPosRaw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_e_gearLvrPosRaw.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_drid_st_gearLvrPosSeql() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_drid_st_gearLvrPosSeql.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_eadd_b_eadInv2ActvDischCmplt.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_eadd_n_mot2ActSpd_rpm() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_eadd_n_mot2ActSpd_rpm.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_engd_b_fuTankLock() \
  (FALSE)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_engd_b_fuTankUnlock() \
  (FALSE)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_epbd_e_parkingSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_macd_b_pullUpDiagCmpl() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_macd_b_pullUpDiagCmpl.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcCANMsgValid() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_obcd_b_obcCANMsgValid.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcChrgCablePlugged() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_obcd_b_obcWakeUp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_anyIgnOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_b_anyIgnOn.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_driverStartReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_b_ptCanNmStRdy() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_b_ptCanNmStRdy.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_pmmd_e_authenticationStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_pmmd_e_authenticationStatus.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_tstd_b_engStrtReq() \
  (FALSE)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklInvld.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_acuDrvSeatbltBcklSts.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_bcmFrntLftDrAjSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_bcmFrntLftDrAjSts.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_bcmFrntRDrAjSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_bcmFrntRDrAjSts.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_epbErrSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_epbErrSts.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFctCfgChgTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgChgTyp.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFctCfgDrvMod() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvMod.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFctCfgDrvModStor() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvModStor.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFctCfgDrvSeat() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgDrvSeat.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_b_flgFnctnConfgEGSM() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_b_flgFnctnConfgEGSM.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_dcChgCcSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_egsmShftLvrFailSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_egsmShftLvrFailSt.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_flgFctCfgMotTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgMotTyp.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_flgFctCfgVehCfg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehCfg.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_hvbChgCcsts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_hvbChgCcsts.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_obcChgCCSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_obcChgCCSts.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_obcOnBdCCline() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vild_st_obcOnBdDchaCCline() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vscd_b_vehSpdVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value)

#define Rte_IRead_swc_VOMM_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_AUXC_brpd_b_airTankFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_AUXC_brpd_b_airTankFlt.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_AUXC_brpd_b_airTankPresLowInhDrv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_AUXC_brpd_b_airTankPresLowInhDrv.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_DIAG_ddid_b_egsmMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_DIAG_ddid_b_egsmMsgErr.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_HVSM_eadd_b_ead2Avail() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_eadd_b_ead2Avail.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_b_chgCablePlugged() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_b_chgCablePlugged.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_b_fltPwrShutDn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_b_fltPwrShutDn.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_b_rlyTmOut() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_b_rlyTmOut.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_b_vcuRdyToSlp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_b_vcuRdyToSlp.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_HVSM_hvbd_st_ptRdyInd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_HVSM_obcd_b_chargerPlugged() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_HVSM_obcd_e_chargerSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_HVSM_obcd_e_chargerSts.value)

#define Rte_IRead_swc_VOMM_Step_vcsb_THSM_thmd_b_afterRunActive() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_THSM_thmd_b_afterRunActive.value)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_epbClsdReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_epbClsdReq.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_b_epbClsdReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_epbClsdReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_gearPosVld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_gearPosVld.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_b_gearPosVld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_gearPosVld.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_veh4WDModActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_b_veh4WDModActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_veh4WDModActv.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_vehEcoModActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_b_vehEcoModActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_vehEcoModActv.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_b_vehSportModActv(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_b_vehSportModActv() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_b_vehSportModActv.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_e_driveDirSel(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_e_driveDirSel() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_e_drvrHEVModReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_drvrHEVModReq.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_e_drvrHEVModReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_drvrHEVModReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_e_gearLvrPos(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_e_gearLvrPos() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_drid_st_gearLvrLckInd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_st_gearLvrLckInd.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_drid_st_gearLvrLckInd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_drid_st_gearLvrLckInd.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_engStartReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStartReq.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_b_engStartReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStartReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_engStopReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStopReq.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_b_engStopReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStopReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_engStrtAbort(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStrtAbort.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_b_engStrtAbort() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStrtAbort.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_engStrtComplete(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStrtComplete.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_b_engStrtComplete() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_engStrtComplete.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_motStrtDem(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_motStrtDem.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_b_motStrtDem() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_motStrtDem.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_motStrtEnad(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_motStrtEnad.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_b_motStrtEnad() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_motStrtEnad.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_b_strtrRlyDem(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_strtrRlyDem.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_b_strtrRlyDem() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_b_strtrRlyDem.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_e_engStrtTyp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_e_engStrtTyp.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_e_engStrtTyp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_e_engStrtTyp.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_essd_e_engStrtTypSeld(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_e_engStrtTypSeld.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_essd_e_engStrtTypSeld() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_essd_e_engStrtTypSeld.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_hmmd_b_EVModeActive(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_hmmd_b_EVModeActive() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_hmmd_b_EVModeActive.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_hmmd_b_HVBusDischrgComplete(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_hmmd_b_HVBusDischrgComplete.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_hmmd_b_HVBusDischrgComplete() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_hmmd_b_HVBusDischrgComplete.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_emsWake(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_emsWake.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_emsWake() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_emsWake.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_hsdFltClear(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_hsdFltClear.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_hsdFltClear() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_hsdFltClear.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmRdySlp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmRdySlp.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmRdySlp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmRdySlp.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmSts.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmSts.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmWkUp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmWkUp.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_nmWkUp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_nmWkUp.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_peuWake(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_peuWake.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_peuWake() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_peuWake.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_pwrHoldReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_pwrHoldReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_startReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_startReq.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_startReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_startReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_vcuAwb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_vcuAwb.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_vcuAwb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_vcuAwb.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_b_vcuRmr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_vcuRmr.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_b_vcuRmr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_b_vcuRmr.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_bm_netModeReq(data) \
  RteIWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_bm_netModeReq(data)

#define RteIWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_bm_netModeReq(data) \
( \
  Rte_MemCpy(Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_bm_netModeReq.value, data, sizeof(rt_Array_UInt8_2)) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_bm_netModeReq() \
  (&((*RteIWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_bm_netModeReq())[0]))

#define RteIWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_bm_netModeReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_bm_netModeReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_e_CanNMSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_e_CanNMSts.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_e_CanNMSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_e_CanNMSts.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_e_mode(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_e_mode.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_e_mode() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_e_mode.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_num_vcuAddr(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_num_vcuAddr.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_num_vcuAddr() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_num_vcuAddr.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_bdCanModeReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_bdCanModeReq.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_st_bdCanModeReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_bdCanModeReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_ptCanModeReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_ptCanModeReq.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_st_ptCanModeReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_ptCanModeReq.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_stayAwkReason(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_stayAwkReason.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_st_stayAwkReason() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_stayAwkReason.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_vcuPwrActvMod(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_vcuPwrActvMod.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_st_vcuPwrActvMod() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_vcuPwrActvMod.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_pmmd_st_vcuWkUpReason(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_vcuWkUpReason.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_pmmd_st_vcuWkUpReason() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_pmmd_st_vcuWkUpReason.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_PTDisabled(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_PTDisabled.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_vsmd_b_PTDisabled() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_PTDisabled.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_PTEnabled(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_PTEnabled.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_vsmd_b_PTEnabled() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_PTEnabled.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_StartDemRaw(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_StartDemRaw.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_vsmd_b_StartDemRaw() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_StartDemRaw.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehRun(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehRun() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehRunRaw(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehRunRaw.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehRunRaw() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehRunRaw.value \
)

#define Rte_IWrite_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehStrt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehStrt.value = (data) \
)

#define Rte_IWriteRef_swc_VOMM_Step_vcsb_VOMM_vsmd_b_VehStrt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_VOMM_swc_VOMM_Step.Rte_vcsb_VOMM_vsmd_b_VehStrt.value \
)

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
FUNC(void, swc_VOMM_CODE) swc_VOMM_Step(void);
FUNC(void, swc_VOMM_CODE) swc_VOMM_Init(void);
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
#endif /* RTE_SWC_VOMM_H_ */
 
 
 
