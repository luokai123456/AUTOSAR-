 
/*
************************************************************************************************************************
*
* File name: Rte_swc_HVSM.h
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
#ifndef RTE_SWC_HVSM_H_
#define RTE_SWC_HVSM_H_

#include "Rte_swc_HVSM_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_bmsd_e_modeTgt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_b_DCDCEnabled;
extern VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_e_modeTgt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_dccd_pct_DCDCPwrLmt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Avail;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_b_ead2Enad;
extern VAR(ElMac, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_eadd_e_inv2ModeTgt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_CampModeFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_acPtcEnb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyHvOnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyPreRlyCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_accyWrkEnCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_allowChg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_chgCablePlugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_dchaOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_fltPwrShutDn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_lvCutOffReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_rlyTmOut;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_tmOutFlgCfm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuRdyToSlp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_b_vcuWkUpCmd;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(HVBattStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_modeTgt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_CampModeFbFailrReason;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyPreRlySts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlySts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_accyTakeSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_bbmWrkEnCmd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_ptRdyInd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged;
extern VAR(ChargerStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_e_chargerSts;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_PtcSt;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_airCmprSt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_acpd_x_accPedlPos_pct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPmpSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_b_brkPressedFromSwitch;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_bdcacWrk;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_EmergencyStop;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_cesd_b_crash;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_b_dcdcSelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_24vDcdcModAct;
extern VAR(DCDCMode, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_e_modeAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_b_eadInv2SelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_eadInv2Sts;
extern VAR(ElMac, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_e_inv2ModeAct;
extern VAR(ParkingStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_epbd_e_parkingSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_bmsSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmRlyWldFlt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hcmSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvilOpen;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_lowTempProtnReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_dcdcMainRlySts;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_eadInv2MainRlySts;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmMaiRlyNeg;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hcmWrkSt;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbAssiRly;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyNeg;
extern VAR(HVBRelayStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbMaiRlyPos;
extern VAR(HVBattStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_e_hvbStatus;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_i_hvbCurr_A;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_q_hvbSOC_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvilOpenSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_epsSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_b_vcuSelfChkOk;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_e_sdcacWrk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCablePlugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcChrgCableUnplugged;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcSelfChkOk;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_b_obcWakeUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_driverStartReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_b_trsm2GearshiftActv;
extern VAR(SInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_trad_st_trsm2GearAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyEnReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_AccyFltSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_cntnrCtrlEnaFb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmCampModeSwtInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_csmV2XDchaSwInvld;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgBBMMsgErr;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgAccyButton;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_pepsRmtCtrlSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_tboxPrtFullSwStUB;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_pct_mmiLocBkChgTarVal;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bbmFltSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bbmWorkSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_bmsDlyDataUpldEnb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dcChgCcSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_dccAccyConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmAccConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hcmHvilSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgCcsts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbChgFltReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbDischgFltReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_hvbPreChgSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_ipkChgSftSwCtlSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcChgCCSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_obcOnBdDchaCCline;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_pepsRKECom;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxChgSftSwCtlSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxPrtFullSwSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_tboxRsrChgSt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmAcceRlyVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmMainPosBckVolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_b_vehSpdVld;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCOP_vcob_VCOP_BMSH_ChargeLEDCtrl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_ATAU_vcsb_ATAU_pmmd_b_ePTRelease_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl32Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_VehLvl33Flt_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_accyEnbFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_obcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_SCAP_vcsb_SCAP_eadd_b_mot2TqOff;
extern VAR(DriveDir, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_driveDirSel;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_hmmd_b_HVBusDischrgComplete;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmRdySlp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_nmWkUp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq;
extern VAR(NMStatus, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_e_CanNMSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTDisabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_PTEnabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_StartDemRaw;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRun;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_vsmd_b_VehRunRaw;
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
#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_accd_e_PtcSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_accd_e_PtcSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_accd_e_airCmprSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_accd_e_airCmprSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_acpd_x_accPedlPos_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_acpd_x_accPedlPos_pct.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_brpd_b_brkPmpSelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_brpd_b_brkPmpSelfChkOk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_brpd_b_brkPressedFromSwitch() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_brpd_b_brkPressedFromSwitch.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_brpd_e_bdcacWrk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_brpd_e_bdcacWrk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_brpd_e_brkPedalStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_cesd_b_EmergencyStop() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_cesd_b_EmergencyStop.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_cesd_b_crash() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_cesd_b_crash.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_dccd_b_dcdcCutOffLvFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_dccd_b_dcdcCutOffLvFb.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_dccd_b_dcdcSelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_dccd_b_dcdcSelfChkOk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_dccd_e_24vDcdcModAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_dccd_e_24vDcdcModAct.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_dccd_e_modeAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_dccd_e_modeAct.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_eadd_b_eadInv2RdyToCutOffLV.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_eadd_b_eadInv2SelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_eadd_b_eadInv2SelfChkOk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_eadd_e_eadInv2Sts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_eadd_e_eadInv2Sts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_eadd_e_inv2ModeAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_eadd_e_inv2ModeAct.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_epbd_e_parkingSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_epbd_e_parkingSts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_bmsSelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_bmsSelfChkOk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hcmCutOffLvFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hcmCutOffLvFb.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hcmPtcDefRlyCls.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hcmRlyWldFlt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hcmRlyWldFlt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hcmSelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hcmSelfChkOk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hvbPrmtCutOffLvFb.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_hvilOpen() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_hvilOpen.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_lowTempProtnReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_lowTempProtnReq.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmd() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmd.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_dcdcMainRlySts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_dcdcMainRlySts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_eadInv2MainRlySts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_eadInv2MainRlySts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hcmMaiRlyNeg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hcmMaiRlyNeg.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hcmWrkSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hcmWrkSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hvbAssiRly() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hvbAssiRly.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hvbMaiRlyNeg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyNeg.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hvbMaiRlyPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hvbMaiRlyPos.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_e_hvbStatus() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_e_hvbStatus.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_i_hvbCurr_A() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_i_hvbCurr_A.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_q_hvbSOC_pct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_q_hvbSOC_pct.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_hvbd_st_hvilOpenSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_hvbd_st_hvilOpenSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_macd_b_epsSelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_macd_b_epsSelfChkOk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_macd_b_vcuSelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_macd_b_vcuSelfChkOk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_macd_e_sdcacWrk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_macd_e_sdcacWrk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_obcd_b_obcChrgCablePlugged() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_obcd_b_obcChrgCablePlugged.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_obcd_b_obcChrgCableUnplugged() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_obcd_b_obcChrgCableUnplugged.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_obcd_b_obcSelfChkOk() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_obcd_b_obcSelfChkOk.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_obcd_b_obcWakeUp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_obcd_b_obcWakeUp.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_pmmd_b_driverStartReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_pmmd_b_driverStartReq.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_trad_b_trsm2GearshiftActv() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_trad_b_trsm2GearshiftActv.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_trad_st_trsm2GearAct() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_trad_st_trsm2GearAct.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_AccyEnReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_AccyEnReq.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_AccyFltSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_AccyFltSts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_cntnrCtrlEnaFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_cntnrCtrlEnaFb.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmCampModeSwt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmCampModeSwtInvld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmCampModeSwtInvld.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmTakeEleSwt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmTakeEleSwtReqInvld.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmV2XDchaSw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSw.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_csmV2XDchaSwInvld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_csmV2XDchaSwInvld.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_flgBBMMsgErr() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_flgBBMMsgErr.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_flgFctCfgAccyButton() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgAccyButton.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_hcmMainPosBckVoltVldSts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_pepsRmtCtrlSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_pepsRmtCtrlSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_b_tboxPrtFullSwStUB() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_b_tboxPrtFullSwStUB.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_pct_mmiLocBkChgTarVal() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_pct_mmiLocBkChgTarVal.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_bbmFltSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_bbmFltSts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_bbmWorkSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_bbmWorkSts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_bmsDlyDataUpldEnb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_bmsDlyDataUpldEnb.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_dcChgCcSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_dcChgCcSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_dccAccyConnStsFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_dccAccyConnStsFb.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_flgFctCfgAccy() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_flgFctCfgVehTyp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgVehTyp.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hcmAccConnStsFb() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hcmAccConnStsFb.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hcmHvilSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hcmHvilSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hvbChgCcsts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hvbChgCcsts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hvbChgFltReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hvbChgFltReq.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hvbDischgFltReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hvbDischgFltReq.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_hvbPreChgSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_hvbPreChgSts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_ipkAlwChgSftCtlSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_ipkChgSftSwCtlSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_ipkChgSftSwCtlSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_obcChgCCSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_obcChgCCSts.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_obcOnBdCCline() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_obcOnBdCCline.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_obcOnBdDchaCCline() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_obcOnBdDchaCCline.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_pepsRKECom() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_pepsRKECom.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_tboxChgSftSwCtlSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_tboxChgSftSwCtlSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_tboxPrtFullSwSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_tboxPrtFullSwSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_st_tboxRsrChgSt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_st_tboxRsrChgSt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_u_hcmAcceRlyVolt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vild_u_hcmMainPosBckVolt() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vild_u_hcmMainPosBckVolt.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vscd_b_vehSpdVld() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vscd_b_vehSpdVld.value)

#define Rte_IRead_swc_HVSM_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IRead_swc_HVSM_Step_vcob_VCOP_BMSH_ChargeLEDCtrl() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcob_VCOP_BMSH_ChargeLEDCtrl.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_ATAU_pmmd_b_ePTRelease_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_ATAU_pmmd_b_ePTRelease_flg.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_DIAG_digd_b_VehLvl32Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_DIAG_digd_b_VehLvl32Flt_flg.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_DIAG_digd_b_VehLvl33Flt_flg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_DIAG_digd_b_VehLvl33Flt_flg.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_EGYM_egmd_b_accyEnbFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_EGYM_egmd_b_accyEnbFlg.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_EGYM_egmd_b_dcdcEnbAllowFlg.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_EGYM_egmd_b_obcEnbAllowFlg() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_EGYM_egmd_b_obcEnbAllowFlg.value)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_bmsd_e_modeTgt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_bmsd_e_modeTgt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_bmsd_e_modeTgt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_bmsd_e_modeTgt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_dccd_b_DCDCEnabled(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_b_DCDCEnabled.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_dccd_b_DCDCEnabled() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_b_DCDCEnabled.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_dccd_e_modeTgt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_e_modeTgt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_dccd_e_modeTgt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_e_modeTgt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_dccd_pct_DCDCPwrLmt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_pct_DCDCPwrLmt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_dccd_pct_DCDCPwrLmt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_dccd_pct_DCDCPwrLmt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_eadd_b_ead2Avail(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_b_ead2Avail.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_eadd_b_ead2Avail() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_b_ead2Avail.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_eadd_b_ead2Enad(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_b_ead2Enad.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_eadd_b_ead2Enad() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_b_ead2Enad.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_eadd_e_inv2ModeTgt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_e_inv2ModeTgt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_eadd_e_inv2ModeTgt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_eadd_e_inv2ModeTgt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_CampModeFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_CampModeFb.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_CampModeFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_CampModeFb.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_TakeEleSwtIndReq.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_acPtcEnb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_acPtcEnb.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_acPtcEnb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_acPtcEnb.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyHvOnCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyHvOnCmd.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyHvOnCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyHvOnCmd.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyLvPwrOnCmd.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyPreRlyCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyPreRlyCmd.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyPreRlyCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyPreRlyCmd.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_accyWrkEnCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_accyWrkEnCmd.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_allowChg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_allowChg.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_allowChg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_allowChg.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_chgCablePlugged(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_chgCablePlugged.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_chgCablePlugged() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_chgCablePlugged.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_dchaOn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_dchaOn.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_dchaOn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_dchaOn.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_fltPwrShutDn(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_fltPwrShutDn.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_fltPwrShutDn() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_fltPwrShutDn.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvBusShutDwnCmpl.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgCmplt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_hvbIntelChgExitReq.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_lvCutOffReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_lvCutOffReq.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_lvCutOffReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_lvCutOffReq.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_rlyTmOut(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_rlyTmOut.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_rlyTmOut() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_rlyTmOut.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_tmOutFlg(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_tmOutFlg.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_tmOutFlg() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_tmOutFlg.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_tmOutFlgCfm(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_tmOutFlgCfm.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_tmOutFlgCfm() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_tmOutFlgCfm.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_vcuRdyToSlp(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_vcuRdyToSlp.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_vcuRdyToSlp() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_vcuRdyToSlp.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_b_vcuWkUpCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_b_vcuWkUpCmd.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_e_PmmStatus(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_e_modeTgt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_e_modeTgt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_e_modeTgt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_e_modeTgt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_pct_BookChrgnTarValFb.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_CampModeFbFailrReason(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_CampModeFbFailrReason.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_CampModeFbFailrReason() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_CampModeFbFailrReason.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_RmChgCmdFailPmt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyPreRlyFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlyFlt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyPreRlyFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlyFlt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyPreRlySts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlySts.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyPreRlySts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyPreRlySts.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlyFlt(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyFlt.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlyFlt() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyFlt.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlySts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlySts.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlySts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlySts.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyRlyVoltSamSw.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyTakeSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyTakeSts.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_accyTakeSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_accyTakeSts.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_bbmWrkEnCmd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_bbmWrkEnCmd.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_bbmWrkEnCmd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_bbmWrkEnCmd.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hcmMaiRlyNegClsReq.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbAssiRlyPosClsReq.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyNegClsReq.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_hvbMaiRlyPosClsReq.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOFFReqSts.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_otaHvOnOffFailInfo.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_ptRdyInd(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_ptRdyInd() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_ptRdyInd.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_hvbd_st_tboxChgSftSwCtlStEV.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_obcd_b_chargerPlugged(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_obcd_b_chargerPlugged() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value \
)

#define Rte_IWrite_swc_HVSM_Step_vcsb_HVSM_obcd_e_chargerSts(data) \
( \
  Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_obcd_e_chargerSts.value = (data) \
)

#define Rte_IWriteRef_swc_HVSM_Step_vcsb_HVSM_obcd_e_chargerSts() \
( \
  &Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_HVSM_obcd_e_chargerSts.value \
)

#define Rte_IRead_swc_HVSM_Step_vcsb_SCAP_eadd_b_mot2TqOff() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_SCAP_eadd_b_mot2TqOff.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_drid_e_driveDirSel() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_drid_e_driveDirSel.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_drid_e_gearLvrPos() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_hmmd_b_HVBusDischrgComplete() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_hmmd_b_HVBusDischrgComplete.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_pmmd_b_nmRdySlp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_pmmd_b_nmRdySlp.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_pmmd_b_nmWkUp() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_pmmd_b_nmWkUp.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_pmmd_b_pwrHoldReq() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_pmmd_e_CanNMSts() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_pmmd_e_CanNMSts.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_PTDisabled() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_PTDisabled.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_PTEnabled() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_PTEnabled.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_StartDemRaw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_StartDemRaw.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_VehRun() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_VehRun.value)

#define Rte_IRead_swc_HVSM_Step_vcsb_VOMM_vsmd_b_VehRunRaw() \
  (Rte_App1_Task_10ms_Core1_QM.Rte_RB.Rte_swc_HVSM_swc_HVSM_Step.Rte_vcsb_VOMM_vsmd_b_VehRunRaw.value)

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
FUNC(void, swc_HVSM_CODE) swc_HVSM_Step(void);
FUNC(void, swc_HVSM_CODE) swc_HVSM_Init(void);
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
#endif /* RTE_SWC_HVSM_H_ */
 
 
 
