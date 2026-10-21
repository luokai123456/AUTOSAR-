/*
 * File: swc_VCIP.h
 *
 * Code generated for Simulink model 'swc_VCIP'.
 *
 * Model version                  : 6.1062
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Sep 18 13:41:36 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_VCIP_h_
#define RTW_HEADER_swc_VCIP_h_
#ifndef swc_VCIP_COMMON_INCLUDES_
#define swc_VCIP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_VCIP.h"
#endif                                 /* swc_VCIP_COMMON_INCLUDES_ */

#include "Rte_Type.h"
#include "Platform_Types.h"
#include "enum_Type.h"
#include "Rte_swc_rte_dem.h"
#include "Aes_Encypt.h"
#include "AES_Lib.h"

/* Includes for objects with custom storage classes */
#include "const_ImportFromFile.h"
#include "const_ImportedDefine.h"

/* user code (top of header file) */
#include "Platform_Types.h"
#include "enum_Type.h"
#include "Rte_swc_rte_dem.h"
#include "Aes_Encypt.h"
#include "AES_Lib.h"
#ifndef DEFINED_TYPEDEF_FOR_vcsb_VOMM_
#define DEFINED_TYPEDEF_FOR_vcsb_VOMM_

typedef struct {
  uint8 hmmd_e_PHEVClthMode;
  uint8 hmmd_e_PHEVClthModeReq;
  uint8 pmmd_bm_netModeReq[2];
  PmmMode pmmd_e_mode;
  boolean pmmd_b_emsWake;
  boolean pmmd_b_peuWake;
  boolean pmmd_b_pwrHoldReq;
  boolean pmmd_b_startReq;
  boolean pmmd_b_vcuAwb;
  uint32 pmmd_st_stayAwkReason;
  uint8 pmmd_st_vcuWkUpReason;
  boolean pmmd_b_nmSts;
  boolean pmmd_b_vcuRmr;
  uint8 pmmd_num_vcuAddr;
  boolean pmmd_b_nmWkUp;
  boolean pmmd_b_nmRdySlp;
  uint8 pmmd_st_ptCanModeReq;
  uint8 pmmd_st_bdCanModeReq;
  NMStatus pmmd_e_CanNMSts;
  uint8 pmmd_st_vcuPwrActvMod;
  boolean vsmd_b_PTDisabled;
  boolean vsmd_b_PTEnabled;
  boolean vsmd_b_VehRun;
  boolean vsmd_b_VehStrt;
  boolean vsmd_b_StartDemRaw;
  boolean vsmd_b_VehRunRaw;
  boolean drid_b_vehSportModActv;
  boolean drid_b_veh4WDModActv;
  DriveDir drid_e_driveDirSel;
  HEVModeReq drid_e_drvrHEVModReq;
  GearLeverPos drid_e_gearLvrPos;
  HybModeMngr hmmd_e_hmmState;
  boolean hmmd_b_bHVReady;
  boolean hmmd_b_engStartReq;
  boolean hmmd_b_engStopReq;
  boolean hmmd_b_EVModeActive;
  boolean hmmd_b_HVBusDischrgComplete;
  boolean hmmd_b_HVBusDischrgReq;
  boolean hmmd_b_ICEModeReq;
  boolean hmmd_b_PHEVModeActive;
  boolean hmmd_b_SHEVModeActive;
  boolean hmmd_b_motProtActv;
  EngStartType essd_e_engStrtTyp;
  EngStartType essd_e_engStrtTypSeld;
  boolean essd_b_strtrRlyDem;
  boolean essd_b_motStrtDem;
  boolean essd_b_motStrtEnad;
  boolean essd_b_engStartReq;
  boolean essd_b_engStopReq;
  boolean essd_b_engStrtAbort;
  boolean essd_b_engStrtComplete;
  boolean pmmd_b_hsdFltClear;
  boolean hmmd_b_PHEVIdleChrgReq;
  boolean hmmd_b_EVModeEpsEna;
  uint8 drid_st_gearLvrLckInd;
  boolean drid_b_gearPosVld;
  boolean drid_b_epbClsdReq;
  boolean drid_b_vehEcoModActv;
} vcsb_VOMM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_DIAG_
#define DEFINED_TYPEDEF_FOR_vcsb_DIAG_

typedef struct {
  uint8 digd_st_edcpFlt;
  uint8 digd_st_hbcpFlt;
  uint8 digd_st_vehSysErrLevel;
  boolean acpd_b_accPed1Vld;
  boolean acpd_b_accPed2Vld;
  boolean brpd_b_brkSwtMismatch;
  boolean digd_b_vcuVehLvl22Flt_flg_BRP;
  boolean macd_b_EVCANBusoffDebd;
  boolean digd_b_VehLvl1Flt_flg;
  boolean digd_b_VehLvl21Flt_flg;
  boolean digd_b_VehLvl31Flt_flg;
  boolean digd_b_VehLvl32Flt_flg;
  boolean digd_b_VehLvl33Flt_flg;
  boolean digd_b_VehLvl22Flt_flg;
  boolean digd_b_VehLvl23Flt_flg;
  boolean ddid_b_egsmMsgErr;
  boolean ddid_b_bmsMsgErr;
  boolean digd_b_bmsFltLv4A;
  boolean digd_b_mcuFltLv2A;
  boolean digd_b_mcuFltLv3A;
  boolean digd_b_mcuMsgErr;
  boolean macd_b_EVCANBusoff31Err;
  boolean digd_b_vcuVehLvl1Flt_flg_BRP;
  boolean digd_b_vehCrashFltLvl33;
} vcsb_DIAG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_HVSM_
#define DEFINED_TYPEDEF_FOR_vcsb_HVSM_

typedef struct {
  uint8 bmsd_e_modeTgt;
  HVBattStatus hvbd_e_modeTgt;
  boolean hvbd_b_hvBusShutDwnCmpl;
  HVACStatus accd_e_modeTgt;
  uint8 hvbd_st_ptRdyInd;
  boolean hvbd_b_allowChg;
  boolean hvbd_b_lvCutOffReq;
  boolean hvbd_b_vcuWkUpCmd;
  ElMac eadd_e_inv1ModeTgt;
  uint8 hvbd_st_hvbMaiRlyNegClsReq;
  uint8 hvbd_st_hcmMaiRlyNegClsReq;
  boolean eadd_b_ead1Avail;
  uint8 hvbd_st_hvbAssiRlyPosClsReq;
  ChargerStatus obcd_e_chargerSts;
  boolean eadd_b_ead1Enad;
  boolean obcd_b_chargerPlugged;
  uint8 hvbd_st_hvbMaiRlyPosClsReq;
  PmmStatus hvbd_e_PmmStatus;
  boolean hvbd_b_tmOutFlg;
  ElMac eadd_e_inv2ModeTgt;
  boolean hvbd_b_tmOutFlgCfm;
  boolean hvbd_b_rlyTmOut;
  boolean eadd_b_ead2Avail;
  boolean hvbd_b_vcuRdyToSlp;
  boolean eadd_b_ead2Enad;
  boolean hvbd_b_hvbIntelChgCmplt;
  boolean hvbd_b_hvbIntelChgExitReq;
  ElMac msgd_e_invModeTgt;
  boolean msgd_b_msgAvailable;
  boolean msgd_b_msgEnabled;
  float32 msgd_n_motSpdTgt_rpm;
  boolean msgd_b_engStartComplete;
  ElMac tmmd_e_invModeTgt;
  boolean tmmd_b_tmmAvail;
  boolean tmmd_b_tmmEnad;
  float32 tmmd_n_motSpdTgt_rpm;
  boolean tmmd_b_engStartComplete;
  float32 tmmd_n_idleSpdTgt_rpm;
  boolean tmmd_b_tmmSpdCtrlAllow;
  DCDCMode dccd_e_modeTgt;
  boolean dccd_b_DCDCEnabled;
  boolean apud_b_apuStartPrt;
  float32 apud_pwr_apuTgtRevMode_kW;
  float32 apud_n_engSpdTgtRevMode_rpm;
  float32 apud_tq_crsGcuTgtRevMode_Nm;
  boolean apud_b_apuStartFail;
  uint8 apud_st_apuReqFb;
  boolean apud_b_apuFltStop;
  float32 apud_pwr_hvSysPwrAct_kW;
  ApuMode apud_e_apuMode;
  boolean apud_b_tmpFrcSttApu1;
  uint8 dccd_pct_DCDCPwrLmt;
  boolean hvbd_b_dchaOn;
  boolean hvbd_b_fltPwrShutDn;
  boolean hvbd_b_chgCablePlugged;
  boolean hvbd_b_accyWrkEnCmd;
  boolean hvbd_b_accyLvPwrOnCmd;
  boolean hvbd_b_accyHvOnCmd;
  uint8 hvbd_st_accyTakeSts;
  uint8 hvbd_st_bbmWrkEnCmd;
  uint8 hvbd_st_accyRlyVoltSamSw;
  boolean hvbd_b_accyPreRlyCmd;
  uint8 hvbd_st_accyPreRlySts;
  uint8 hvbd_st_accyRlyFlt;
  uint8 hvbd_st_accyPreRlyFlt;
  uint8 hvbd_st_accyRlySts;
  boolean hvbd_b_acPtcEnb;
  uint8 hvbd_st_RmChgCmdFailPmt;
  uint8 hvbd_st_tboxChgSftSwCtlStEV;
  boolean hvbd_b_TakeEleSwtIndReq;
  float32 hvbd_pct_BookChrgnTarValFb;
  boolean hvbd_b_CampModeFb;
  uint8 hvbd_st_CampModeFbFailrReason;
  uint8 hvbd_st_otaHvOnOFFReqSts;
  uint8 hvbd_st_otaHvOnOffFailInfo;
} vcsb_HVSM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcib_VCIP_
#define DEFINED_TYPEDEF_FOR_vcib_VCIP_

typedef struct {
  uint8 vild_st_TBOXLockVehCtrl;
  uint8 vild_st_tboxInventorySpdLmtReq;
  uint8 vild_st_TBOXLockVehType;
  uint8 vild_st_TBOXFunLockVehActive;
  uint8 vild_st_TBOXFunAntiDismantleActive;
  uint8 vild_st_TBOXLockLimSet;
  uint8 vild_st_TBOXLockResultResp;
  uint8 vild_st_tboxLockVehPerFlag;
  uint8 vild_st_tboxVersionConversionFlag;
  uint8 vild_st_tboxSpdLmtLevelReq;
  uint8 vild_st_tboxStartBattChgReq;
  uint8 vild_st_tboxLife;
  uint8 vild_st_FnCfgDstFnclLck;
  float32 brpd_p_AirPres_kpa;
  boolean ccdd_b_extCtrlAvail;
  boolean vild_b_driverEVModeReq;
  float32 hvbd_pwr_accyPwrFilter_kW;
  boolean tmmd_b_testinvModeReq;
  boolean vscd_b_ESPActvRaw;
  FanStatus accd_e_acFanReq;
  FaultStatus accd_e_acFaultStatus;
  boolean accd_b_engStrtReq;
  float32 accd_pwr_hvacPwrAct_kW;
  float32 accd_pwr_hvacPwrDem_kW;
  float32 accd_pwr_hvacPwrDemMin_kW;
  uint8 accd_st_ptcHeatReq;
  float32 accd_t_ambTemp_C;
  float32 accd_p_acPres_kPa;
  uint8 accd_st_frtWdshldDefReq;
  uint8 accd_st_AcWrk;
  uint8 accd_st_cbnThermMngReq;
  uint8 accd_st_hiLoPrsSwtSt;
  uint8 accd_st_acMidPresSwt;
  float32 accd_t_acInTempSet_C;
  McuSts accd_e_airCmprSt;
  McuSts accd_e_PtcSt;
  float32 accd_u_acPresVolt_V;
  boolean accd_b_acHvilOpn;
  float32 accd_t_acEvapTemp_C;
  uint8 accd_num_airCmpFltCode;
  uint8 accd_num_ptcFltCode;
  FaultStatus accd_e_airCmpFltLvl;
  FaultStatus accd_e_ptcFltLvl;
  uint8 accd_st_airCmprSt;
  FaultStatus accd_e_acFltLvl;
  uint8 accd_st_acSubFltSts;
  boolean accd_b_BPTCHvilOpn;
  boolean accd_b_ptcHvLoopFlt;
  boolean accd_b_accmHvLoopFlt;
  boolean acpd_b_accPedlPosVld;
  float32 acpd_x_accPedlPosSens1_pct;
  float32 acpd_x_accPedlPosSens2_pct;
  float32 acpd_x_accPedlPos_pct;
  float32 acpd_x_accPedlPosLimd_pct;
  float32 acpd_u_accPedlPosSens1VoltRaw_V;
  float32 acpd_u_accPedlPosSens2VoltRaw_V;
  float32 acpd_x_accPedlPosCan_pct;
  BrakePedalStatus brpd_e_brkPedalStatus;
  boolean brpd_b_brakeSwitch1Closed;
  boolean brpd_b_brakeSwitch2Closed;
  boolean brpd_b_brkPresValid;
  float32 brpd_p_brkPres_bar;
  float32 brpd_p_brkVacuumPres_bar;
  float32 brpd_x_brkPedlPos_pct;
  boolean brpd_b_brkPedlPosVld;
  boolean brpd_b_brkPedlStsVld;
  uint8 brpd_st_bdcacWrk;
  boolean brpd_b_DryAirSwitch;
  boolean brpd_b_ResrAirSwitch;
  uint8 brpd_st_brkPmpFltLvl;
  boolean brpd_b_brkPumpFault;
  float32 brpd_pwr_brkPumpOpt_kW;
  boolean brpd_b_brkPressedFromSwitch;
  McuSts brpd_e_bdcacWrk;
  boolean brpd_b_brkPmpSelfChkOk;
  boolean brpd_b_brkPmpSelfChkErr;
  boolean brpd_b_vacTankLowPrs;
  boolean ccdd_b_crzCtrlActv;
  float32 ccdd_tq_crzCtrlTqReq_Nm;
  float32 ccdd_v_crzCtrlSpdLim_kph;
  float32 ccdd_u_cruiseADvoltage_V;
  boolean cesd_b_airbagActive;
  uint8 cesd_st_crashSts;
  boolean cesd_b_EmergencyStop;
  boolean cesd_b_crash;
  FaultStatus dccd_e_dcdcFaultStatus;
  DCDCMode dccd_e_modeAct;
  float32 dccd_pwr_ActHV_kW;
  float32 dccd_pwr_ActLV_kW;
  float32 dccd_t_dcdcTemp_C;
  float32 dccd_u_dcdcLVBusAct_V;
  float32 dccd_u_dcdcHVBusAct_V;
  uint8 dccd_st_12vDcdcModAct;
  uint8 dccd_st_24vDcdcModAct;
  uint8 dccd_st_24vDcdcFltSts;
  float32 dccd_pwr_24vDcdcOpt_kW;
  McuSts dccd_e_24vDcdcModAct;
  boolean dccd_b_dcdcSelfChkOk;
  boolean dccd_b_dcdcSelfChkErr;
  boolean dccd_b_dcdcHvilFlt;
  boolean dccd_b_dcdcCutOffLvFb;
  uint8 dccd_st_24vDcdcSubFltSts;
  boolean drid_b_drvrModeReqEV;
  boolean drid_b_drvrModeReqHEV;
  boolean drid_b_drvrModeReqECO;
  boolean drid_b_drvrModeReqSPORT;
  boolean drid_b_drvrModeReq4WD;
  uint8 drid_b_parkBtnPressed;
  GearLeverPos drid_e_gearLvrPosRaw;
  uint8 drid_st_gearLvrPosSeql;
  boolean drid_b_revModeSwitch;
  boolean drid_b_pfcuLowIdle;
  boolean drid_b_pfcuHighIdle;
  boolean drid_b_EVModeButtonPressed;
  boolean drid_b_EVModeButtonCircuitFlt;
  boolean drid_b_SmartModeButtonPressed;
  boolean drid_b_SmartModeButtonCircuitFlt;
  boolean drid_b_SaveModeButtonPressed;
  boolean drid_b_SaveModeButtonCircuitFlt;
  boolean drid_b_RECModeButtonPressed;
  boolean drid_b_RECModeButtonCircuitFlt;
  FaultStatus eadd_e_inv1FltSts;
  ElMac eadd_e_inv1ModeAct;
  boolean eadd_b_inv1Active;
  boolean eadd_b_inv1HVRdy;
  float32 eadd_n_mot1ActSpd_rpm;
  float32 eadd_tq_mot1ActTq_Nm;
  float32 eadd_tq_mot1MaxAvailLTBst_Nm;
  float32 eadd_tq_mot1MaxAvailSTBst_Nm;
  float32 eadd_tq_mot1MaxAvailLTBrk_Nm;
  float32 eadd_tq_mot1MaxAvailSTBrk_Nm;
  float32 eadd_t_inv1Temp_C;
  float32 eadd_t_mot1Temp_C;
  float32 eadd_t_ead1CooltTemp_C;
  float32 eadd_u_busInv1HVAct_V;
  float32 eadd_pwr_mot1ActPwr_kW;
  float32 eadd_fact_mot1GearRat;
  uint8 eadd_st_eadInv1Sts;
  FaultStatus eadd_e_inv2FltSts;
  ElMac eadd_e_inv2ModeAct;
  boolean eadd_b_inv2Active;
  boolean eadd_b_inv2HVRdy;
  float32 eadd_n_mot2ActSpd_rpm;
  float32 eadd_tq_mot2ActTq_Nm;
  float32 eadd_tq_mot2MaxAvailLTBst_Nm;
  float32 eadd_tq_mot2MaxAvailSTBst_Nm;
  float32 eadd_tq_mot2MaxAvailLTBrk_Nm;
  float32 eadd_tq_mot2MaxAvailSTBrk_Nm;
  float32 eadd_t_inv2Temp_C;
  float32 eadd_t_mot2Temp_C;
  float32 eadd_t_ead2CooltTemp_C;
  float32 eadd_u_busInv2HVAct_V;
  float32 eadd_pwr_mot2ActPwr_kW;
  float32 eadd_fact_mot2GearRat;
  boolean eadd_st_eadInv2Sts;
  float32 eadd_pwr_mot21ActPwr_kW;
  float32 eadd_i_eadInv2ActCurrDC_A;
  FaultStatus eadd_e_inv21FltSts;
  float32 eadd_n_mot21ActSpd_rpm;
  float32 eadd_tq_mot21ActTq_Nm;
  uint8 eadd_st_eadInv2WrkMod;
  McuSts eadd_e_eadInv2Sts;
  boolean eadd_b_eadInv2SelfChkOk;
  boolean eadd_b_motPrevnSlipFlg;
  boolean eadd_b_eadMot2SysOvrLd;
  boolean eadd_b_eadInv2SelfChkErr;
  uint8 eadd_st_eadInv2PwrActvMod;
  boolean eadd_b_eadInv2RdyToCutOffLV;
  uint8 eadd_st_inv2SubFltSts;
  uint8 eadd_st_eadMot2ImmoRlsChk;
  boolean eadd_b_eadInv2HVLFlt;
  FanStatus engd_e_engFanReq;
  FaultStatus engd_e_engFltSts;
  float32 engd_fact_engMaxNorm2Tq;
  boolean engd_b_engBattVoltVld;
  boolean engd_b_engCooltTempVld;
  boolean engd_b_engSpdVld;
  boolean engd_b_engStopInhb;
  boolean engd_b_engStrtComplete;
  boolean engd_b_engTqVld;
  float32 engd_n_engSpd_rpm;
  float32 engd_tq_crsEngAvailTq_Nm;
  float32 engd_tq_crsEngLossTq_Nm;
  float32 engd_tq_crsEngMaxTq_Nm;
  float32 engd_tq_crsEngMinTq_Nm;
  float32 engd_tq_crsEngActTq_Nm;
  float32 engd_t_engCooltTemp_C;
  EngineState engd_e_engStFromCan;
  float32 engd_V_engFuelConsInst_ml;
  float32 engd_t_apuEngCooltTemp_C;
  uint8 engd_st_apuFltLvl;
  float32 engd_n_apuEngActSpd_rpm;
  float32 engd_t_apuEngInAirTmp_C;
  float32 engd_pwr_apuMaxPwrPrmt_kW;
  boolean engd_b_apuCutOffLvFb;
  uint8 engd_st_apuActWrkSt;
  float32 engd_dV_engFuelCns_lph;
  boolean engd_b_apuSelfChkOk;
  uint8 engd_st_apuStrtFaild;
  float32 engd_pwr_apuActPwrFb_kW;
  boolean engd_b_apuWrmUpReq;
  uint8 engd_st_apuGPFReq;
  boolean engd_b_apuWrmUpAchvd;
  boolean engd_b_apuRunng;
  boolean engd_b_fuTankUnlock;
  boolean engd_b_parkGPFReq;
  boolean engd_b_apuSttTest;
  boolean engd_b_fuTankLock;
  boolean engd_b_apuSelfChkErr;
  float32 engd_n_engIdleTgtSpd_rpm;
  uint8 engd_st_msgActvDischgFb;
  ParkingStatus epbd_e_parkingSts;
  HVBRelayStatus hvbd_e_hvbChrgRlySts;
  FaultStatus hvbd_e_hvbFaultStatus;
  InsulationStatus hvbd_e_hvbInslStatus;
  HVBRelayStatus hvbd_e_hvbMainRlySts;
  HVBattStatus hvbd_e_hvbStatus;
  boolean hvbd_b_hvbChrgErr;
  boolean hvbd_b_bmsSelfChkOk;
  boolean hvbd_b_hvbRepairIndErr;
  boolean hvbd_b_hvilOpen;
  float32 hvbd_q_hvbSOC_pct;
  float32 hvbd_pwr_PeakChMax_kW;
  float32 hvbd_pwr_PeakDischMax_kW;
  float32 hvbd_pwr_StatChMax_kW;
  float32 hvbd_pwr_StatDischMax_kW;
  float32 hvbd_t_hvbTemp_C;
  float32 hvbd_pwr_hvbAct_kW;
  float32 hvbd_fact_hvbSOH_pct;
  HVBRelayStatus hvbd_e_eadInv1MainRlySts;
  HVBRelayStatus hvbd_e_eadInv2MainRlySts;
  HVBRelayStatus hvbd_e_msgInvMainRlySts;
  HVBRelayStatus hvbd_e_tmmInvMainRlySts;
  HVBRelayStatus hvbd_e_dcdcMainRlySts;
  HVBRelayStatus hvbd_e_hvacMainRlySts;
  boolean hvbd_b_obcChrgReq;
  uint8 hvbd_st_hvbThermMngReq;
  float32 hvbd_t_hvbMin_C;
  uint8 hvbd_st_hcmFltLvl;
  float32 hvbd_i_hvbCurr_A;
  float32 hvbd_t_hvbInCoolTemp_C;
  uint8 hvbd_st_hcmMaiRlyNeg;
  HVBRelayStatus hvbd_e_hcmMaiRlyNeg;
  HVBRelayStatus hvbd_e_hvbMaiRlyNeg;
  HVBRelayStatus hvbd_e_hvbAssiRly;
  HVBRelayStatus hvbd_e_hvbMaiRlyPos;
  McuSts hvbd_e_hcmWrkSt;
  boolean hvbd_b_hcmSelfChkOk;
  boolean hvbd_b_hvbPrmtCutOffLvFb;
  boolean hvbd_b_hcmCutOffLvFb;
  float32 hvbd_t_hvbAvg_C;
  uint8 hvbd_st_hvbPwrActvMod;
  uint8 hvbd_st_hcmPwrActvMod;
  float32 hvbd_pwr_StatChMaxRaw_kW;
  float32 hvbd_pwr_PeakChMaxRaw_kW;
  float32 hvbd_pwr_hvbActRaw_kW;
  boolean hvbd_b_hvbPreChgFin;
  boolean hvbd_b_hvbRlyOpenLdtBev;
  boolean hvbd_b_lowTempProtnReq;
  boolean hvbd_b_dcChgMod;
  boolean hvbd_b_acChgMod;
  boolean hvbd_b_hvbHeatEnad;
  boolean hvbd_b_hvbDischPwrLimdByTemp;
  boolean hvbd_b_bmsSelfChkErr;
  boolean hvbd_b_hcmSelfChkErr;
  boolean hvbd_b_hcmRlyWldFlt;
  boolean hvbd_b_hvbChPwrLimdByTemp;
  boolean hvbd_b_hcmPtcDefRlyCls;
  uint8 hvbd_st_hvbSubFaultSts;
  boolean hvbd_b_tboxIntelChgCmd;
  uint8 hvbd_st_tboxIntelChgQuit;
  boolean hvbd_b_hvbNonPwrFltHVIL;
  float32 lvbd_C_lvbCapacity_Ah;
  boolean lvbd_b_lvbColdTemp;
  float32 lvbd_t_lvbEstTemp_C;
  float32 lvbd_u_dcdcLVBusActFilt_V;
  boolean macd_b_12VStarterRlyFdbk;
  boolean macd_b_TwoWayVlvOn;
  boolean macd_b_ThreeWayVlvOn;
  float32 macd_V_tankFuelLvl_l;
  float32 macd_t_ts5SnsrTemp_C;
  float32 macd_t_ts3SnsrTemp_C;
  float32 macd_t_ts4SnsrTemp_C;
  uint8 macd_st_sdcacWrk;
  uint8 macd_st_epsFltLvl;
  float32 macd_pwr_epsOpt_kW;
  McuSts macd_e_sdcacWrk;
  boolean macd_b_epsSelfChkOk;
  float32 macd_u_batIntSmpl_V;
  float32 macd_u_5VT1IntSmpl_V;
  float32 macd_u_5VT2IntSmpl_V;
  float32 macd_u_5VT3IntSmpl_V;
  float32 macd_u_5VT4IntSmpl_V;
  float32 macd_u_5VT5IntSmpl_V;
  boolean macd_b_pullUpDiagCmpl;
  boolean macd_b_epsSelfChkErr;
  float32 macd_p_frontAirTankPres_bar;
  float32 macd_p_rearAirTankPres_bar;
  boolean macd_b_vcuSelfChkOk;
  float32 macd_ang_strWhlAng_rad;
  uint8 macd_st_epsSubFltLvl;
  uint8 macd_st_epsErrorCode;
  FaultStatus msgd_e_invFaultSts;
  ElMac msgd_e_invModeAct;
  float32 msgd_fact_gearRat;
  boolean msgd_b_invActive;
  boolean msgd_b_invHVReady;
  float32 msgd_n_motAct_rpm;
  float32 msgd_tq_motAct_Nm;
  float32 msgd_tq_motMaxAvlBoost_Nm;
  float32 msgd_tq_motMaxAvlBoostPeak_Nm;
  float32 msgd_tq_motMaxAvlBrake_Nm;
  float32 msgd_tq_motMaxAvlBrakePeak_Nm;
  float32 msgd_t_invTemp_C;
  float32 msgd_t_motTemp_C;
  float32 msgd_u_busHVAct_V;
  float32 msgd_pwr_motAct_kW;
  FaultStatus obcd_e_obcFaultStatus;
  boolean obcd_b_obcCANMsgValid;
  boolean obcd_b_obcChrgCablePlugged;
  boolean obcd_b_obcChrgCableUnplugged;
  boolean obcd_b_obcWakeUp;
  float32 obcd_t_obcTemp_C;
  float32 obcd_pwr_obcStatPwrMax_kW;
  uint8 obcd_st_obcfltLvl;
  boolean obcd_b_obcSelfChkOk;
  boolean obcd_b_obcSelfChkErr;
  KeyAuthStatus pmmd_e_authenticationStatus;
  boolean pmmd_b_anyIgnOn;
  boolean pmmd_b_canIgnOn;
  boolean pmmd_b_driverStartReq;
  boolean pmmd_b_hwIgnOn;
  boolean pmmd_b_ignOn;
  boolean pmmd_b_pepsPduLvlValid;
  boolean pmmd_b_ignStsStrt;
  boolean pmmd_b_ptCanNmStRdy;
  FaultStatus tmmd_e_invFltSts;
  ElMac tmmd_e_invModAct;
  boolean tmmd_b_invActv;
  McuSts tmmd_e_tmmInvSts;
  boolean tmmd_b_invHVRdy;
  float32 tmmd_n_motActSpd_rpm;
  float32 tmmd_tq_motActTq_Nm;
  float32 tmmd_tq_motMaxAvailLTBst_Nm;
  float32 tmmd_tq_motMaxAvailSTBst_Nm;
  float32 tmmd_tq_motMaxAvailLTBrk_Nm;
  float32 tmmd_tq_motMaxAvailSTBrk_Nm;
  float32 tmmd_t_invTemp_C;
  float32 tmmd_t_motTemp_C;
  float32 tmmd_u_busInvHVAct_V;
  float32 tmmd_pwr_motActPwr_kW;
  float32 tmmd_fact_motGearRat;
  boolean tmmd_b_tmmInvSelfChkOk;
  ClutchState trad_e_trsm1ClthSt;
  ClutchState trad_e_engClthSt;
  FaultStatus trad_e_trsm1FltSts;
  FanStatus trad_e_trsm1FanReq;
  ShiftType trad_e_trsm1GearshiftTyp;
  float32 trad_fact_trsm1GearRat;
  boolean trad_b_trsm1CrpActv;
  boolean trad_b_trsm1GearActVld;
  boolean trad_b_trsm1GearTgtVld;
  boolean trad_b_trsm1HVOilPmpRdy;
  boolean trad_b_trsm1MILReq;
  boolean trad_b_trsm1OilTempVld;
  boolean trad_b_trsm1ShiftInProgs;
  boolean trad_b_trsm1EngStopAllwd;
  boolean trad_b_trsm1OutShaftSpdVld;
  float32 trad_n_trsm1EngIdleSpdReq_rpm;
  float32 trad_n_trsm1OutShaftSpd_rpm;
  sint8 trad_st_trsm1GearAct;
  sint8 trad_st_trsm1GearTgt;
  float32 trad_tq_trsm1ClthActTq_Nm;
  float32 trad_tq_engClthTqCap_Nm;
  float32 trad_tq_trsm1ClthMaxLim_Nm;
  float32 trad_tq_trsm1ClthMinLim_Nm;
  float32 trad_t_trsm1OilTemp_C;
  float32 trad_tq_trsm1InpTqMaxSlowReq_Nm;
  float32 trad_tq_trsm1InpTqMaxFastReq_Nm;
  float32 trad_tq_trsm1InpTqMinReq_Nm;
  float32 trad_n_trsm1InpSpdReq_rpm;
  boolean trad_b_trsm1TqIntvReqActv;
  float32 trad_fact_trsm1FinalDrvRat;
  float32 trad_fact_trsm1GbxGearRat;
  boolean trad_b_trsm1GearshiftActv;
  boolean trad_b_trsm1TqRedReqActv;
  boolean trad_b_trsm1TqIncReqActv;
  float32 trad_tq_trsm1InpTqRedReq_Nm;
  float32 trad_tq_trsm1InpTqIncReq_Nm;
  boolean trad_b_trsm1InpSpdCtrlModReq;
  boolean trad_b_trsm1InpTqIntvReq;
  float32 trad_tq_trsm1InpTqReq_Nm;
  ParkingStatus trad_e_trsm1PrkgSts;
  float32 trad_pct_GearPosn;
  float32 trad_tq_engClthMaxLim_Nm;
  float32 trad_tq_engClthMinLim_Nm;
  FaultStatus trad_e_trsm2FltSts;
  ElMac trad_e_trsm2CtrlModReq;
  boolean trad_b_trsm2GearshiftActv;
  boolean trad_b_trsm2InpSpdCtrlModReq;
  boolean trad_b_trsm2InpTqIntvReq;
  float32 trad_n_trsm2InpSpdReq_rpm;
  float32 trad_tq_trsm2InpTqReq_Nm;
  float32 trad_fact_trsm2GearRat;
  boolean trad_b_trsm2GearActVld;
  sint8 trad_st_trsm2GearAct;
  float32 trad_fact_trsm2FinalDrvRat;
  float32 trad_fact_trsm2GbxGearRat;
  GearShiftResp trad_e_trsm2GearShftResp;
  boolean tstd_b_engStrtReq;
  boolean tstd_b_engStarterStrtReq;
  boolean tstd_b_engMotorStrtReq;
  float32 vscd_ang_roadSlope_deg;
  float32 vscd_v_vehSpd_kph;
  float32 vscd_tq_axle1MaxTqFastReq_Nm;
  float32 vscd_tq_axle2MaxTqReq_Nm;
  float32 vscd_tq_axle1MaxTqSlowReq_Nm;
  float32 vscd_tq_axle2MinTqReq_Nm;
  float32 vscd_tq_axle1MinTqReq_Nm;
  boolean vscd_b_vscTqIntvReq;
  boolean vscd_b_ESPActv;
  boolean vscd_b_AVHActv;
  boolean vscd_b_vehSpdVld;
  boolean vscd_b_TCSFltActv;
  boolean vscd_b_VDCFltActv;
  float32 vscd_tq_axle1RgnBrkTqReq_Nm;
  float32 vscd_tq_axle2RgnBrkTqReq_Nm;
  boolean vscd_b_vehSlipWarn;
  boolean vild_b_parkIdleChgSwitch;
  boolean vild_b_hevModeInhSwitch;
  boolean vild_b_engIdleInhSwitch;
  boolean vild_b_engStartSwitch;
  boolean vild_st_trsm1SpdCtrlAllow;
  boolean vild_b_hvbHeatgVlvFlt;
  boolean vild_b_ptCanBusOff;
  float32 vild_u_Acc1Raw_mV;
  float32 vild_u_Acc2Raw_mV;
  float32 vild_u_BrkRaw_mV;
  float32 vild_u_Brk2Raw_mV;
  boolean vild_b_brkSwt1Actv;
  boolean vild_b_brkSwt2Actv;
  uint8 vild_ctr_dcdcStsInfo;
  float32 vild_u_dcdcEnbFb_mV;
  uint8 vild_st_dcdcEnaOutFb;
  uint8 vild_ctr_mcuMotorSts;
  uint8 vild_ctr_mcuMotorTrq;
  uint8 vild_st_eadInv2MilReq;
  uint8 vild_st_12vPwrRlyFlt;
  uint8 vild_ctr_apuWorkInfo;
  float32 vild_u_apuEnbFb_mV;
  uint8 vild_st_apuEngMilReq;
  uint8 vild_st_apuMilReq;
  boolean vild_b_calCanBusOff;
  uint8 vild_st_epbFltLvl;
  uint8 vild_ctr_bmsChgInfo;
  uint8 vild_ctr_bmsBattFaultInfo;
  uint8 vild_ctr_bmsHVIsolationInfo;
  uint8 vild_ctr_hcmWorkInf;
  uint8 vild_st_hvbSocFlt;
  uint8 vild_st_hvbMilReq;
  uint8 vild_st_hcmMilReq;
  float32 vild_u_hvilSrcFb_mV;
  float32 vild_pct_HVILReturnPWM;
  boolean vild_b_hvbHvilFlt;
  boolean vild_b_obcCircFlt;
  boolean vild_b_obcHwFlt;
  boolean vild_b_obcLkLpFlt;
  boolean vild_b_obcTempFlt;
  boolean vild_b_obcOutVoltFlt;
  boolean vild_b_obcOutCurrFlt;
  uint8 vild_st_obcFltInfo;
  boolean vild_b_ignStsStrt;
  float32 vild_u_pepsOn_mV;
  uint8 vild_st_pepsPduLvl;
  float32 vild_pct_GearPosn;
  uint8 vild_st_GearPosn;
  uint8 vild_st_egsmGearReq;
  uint8 vild_ctr_egsmGearInfo;
  uint8 vild_st_vscMilReq;
  float32 vild_u_5VT1IntSmpl_V;
  float32 vild_u_5VT2IntSmpl_V;
  float32 vild_u_5VT3IntSmpl_V;
  float32 vild_u_5VT4IntSmpl_V;
  float32 vild_u_5VT5IntSmpl_V;
  float32 vild_u_TS5sensorFb_mV;
  float32 vild_u_ecoBtnCur_mV;
  float32 vild_u_revBtnCur_mV;
  float32 vild_u_eLpWpCtrlCur_mV;
  float32 vild_u_hvPwrOffCtrl_mV;
  float32 vild_u_5VT6IntSmpl_V;
  boolean vild_b_pullUpDiagCmpl;
  float32 vild_u_edLpWpFb_V;
  float32 vild_u_strPmpEnbFb_mV;
  float32 vild_u_brkPmpEnbFb_mV;
  float32 vild_u_cbnLpPmpCtrlFb_mV;
  float32 vild_u_cbnLpPmpFb_V;
  float32 vild_u_batLpPmpCtrlFb_mV;
  float32 vild_u_batLpPmpFb_V;
  float32 vild_u_fan1CtrlFb_mV;
  float32 vild_u_fan2CtrlFb_mV;
  float32 vild_u_3wayVlvPwrRlyCtrlFb_mV;
  uint8 vild_st_5In1PwrRlyFlt;
  boolean vild_b_heatgLoopVlvFlt;
  uint8 vild_st_vcuSlfChkFlt;
  uint8 vild_st_eepErr;
  uint8 vild_st_waterPmpPwrRlyFlt;
  uint8 vild_st_epsEnaOutFb;
  uint8 vild_st_brkPmpEnaOutFb;
  uint8 vild_pct_fan1DutyRead;
  uint8 vild_pct_fan2DutyRead;
  uint8 vild_st_containerPwrRlyFlt;
  float32 vild_frq_fan1FreqRead_Hz;
  float32 vild_frq_fan2FreqRead_Hz;
  float32 vild_pct_WatPmpEP2FbPWM;
  float32 vild_pct_WatPmpEP3FbPWM;
  float32 vild_pct_fan1Fb;
  float32 vild_pct_fan2Fb;
  float32 vild_u_hvbVolt_V;
  float32 vild_u_hvPwrOnCtrl_mV;
  boolean vild_b_rstAvgPwrConsumption;
  boolean vild_b_hvbCoolgVlvFlt;
  boolean vild_b_ignStsOn;
  boolean vild_b_pepsPduLvlVld;
  float32 vild_t_hvbMax_C;
  float32 vild_t_hvbMin_C;
  float32 vild_i_hvbCurr_A;
  uint8 vild_st_acCoolSts;
  uint8 vild_st_hvbStatus;
  boolean vild_b_cntnrCtrlEnaFb;
  float32 vild_pct_WatPmpEP1FbPWM;
  uint8 vild_st_24vDcdcModAct;
  uint8 vild_st_hvbThermMngReq;
  float32 vild_t_hvbCooltInTemp_C;
  float32 vild_t_hvbCooltOutTemp_C;
  float32 vild_d_odometer_km;
  boolean vild_b_odometerInvalid;
  boolean vild_b_CCSginal;
  boolean vild_b_DryAirSwitch;
  boolean vild_b_ResrAirSwitch;
  float32 vild_t_TS5sensorFb_C;
  boolean vild_b_emgyStopIn;
  float32 vild_u_Brk2_V;
  float32 vild_u_Brk_V;
  uint8 vild_st_TV3FltFbV6;
  uint8 vild_st_TV3FltFbV5;
  uint8 vild_st_TV4FltFbV6;
  uint8 vild_st_TV4FltFbV5;
  uint8 vild_st_TV1FltFbV6;
  uint8 vild_st_TV1FltFbV5;
  boolean vild_b_obcWakeUpActv;
  float32 vild_u_accPdlSens2InpVolt_V;
  float32 vild_u_accPdlSens1InpVolt_V;
  boolean vild_b_driverEcoModeReq;
  uint8 vild_st_engRedStopLamp;
  uint8 vild_st_trsm1RedStopLamp;
  float32 accd_n_acFanReqSpd_pct;
  float32 vild_u_dcdcRelayVolt_V;
  float32 vild_t_hvbOutCoolTemp_C;
  float32 vild_t_hvbSetTgtTemp_C;
  float32 vild_E_hvbPackRemnEgy_kWh;
  float32 vild_i_dcdcInpCurr_A;
  uint8 vild_st_actWorkSts1;
  float32 vild_u_brkVacuumPres_V;
  uint8 vild_st_hvbDischgFltReq;
  uint8 vild_st_hvbChgFltReq;
  boolean vild_b_acuDrvSeatbltBcklSts;
  boolean vild_b_acuDrvSeatbltBcklInvld;
  boolean vild_b_bcmFrntLftDrAjSts;
  uint8 vild_st_egsmShftLvrFailSt;
  boolean vild_b_egsmFnctnConfg;
  uint8 adcd_st_pmsAdcCtrldSts;
  boolean adcd_b_adcCtrlGearEn;
  uint8 adcd_st_adcTgtGearPostn;
  boolean eadd_b_eadInv2ActvDischCmplt;
  boolean vscd_b_ehbAebActv;
  boolean vscd_b_ehbTrqDecReqActv;
  float32 vscd_tq_ehbTrqDecReq_Nm;
  boolean vscd_b_ehbVlcAvailb;
  boolean vscd_b_ehbVlcActv;
  boolean vscd_b_ehbVlcTrqReqActv;
  float32 vscd_tq_ehbVlcTrqReq_Nm;
  boolean vscd_b_ehbDtcActv;
  boolean vscd_b_ehbTrqIncReqActv;
  float32 vscd_tq_ehbTrqIncReq_Nm;
  uint8 vscd_st_ehbMbRgnTgtWhlSts;
  float32 vscd_tq_ehbMbRgnTgtWhl_Nm;
  boolean vild_b_csmRgnLvlSet;
  boolean adcd_b_adc1SwtchCtrlReq;
  boolean adcd_b_adcCtrlTorqEn;
  float32 adcd_tq_adcTgtDrvTorq_Nm;
  boolean adcd_b_adc1CtrlTorqEn;
  float32 adcd_tq_adc1TgtDrvTorq_Nm;
  boolean vild_b_adcComErrFlg;
  boolean vild_b_adc1ComErrFlg;
  boolean vscd_b_ehbAbsOvrdActv;
  uint8 vild_st_rfrSwapprocd;
  boolean vild_b_rfrSwapBatReq;
  uint8 vild_st_rfrConnctSts;
  uint8 vscd_st_vscIsgActvDampModReq;
  float32 dccd_pwr_dcdcHVpwr_kW;
  float32 vild_pwr_PTCActPwr_kW;
  float32 vild_pwr_airCmprAct_kW;
  boolean vild_st_eadMot2TempHiFlt;
  uint8 vild_st_hvbDisChgFaultReq;
  uint8 vild_st_hvbChgFaultReq;
  boolean drid_b_drvrModeReq;
  uint16 vild_num_hvbCellSum;
  uint8 vild_st_BmsTempOutOfCtrlFlt;
  uint8 vild_st_hvbDCChgProcss;
  uint8 vild_st_obcChgSts;
  uint8 vild_st_hvbChgOvrCurr;
  uint8 vild_st_hvbBattIsolationSts;
  uint8 vild_st_hvbDCChgPlgPOvrTmp;
  uint8 vild_st_hvbDCChgPlgNOvrTmp;
  uint16 vild_tm_hvbFnshChgTim_m;
  float32 vild_u_hvbPackVolt_V;
  uint8 vild_st_vscEHBAVHSts;
  uint8 vild_st_dcChgCcSt;
  boolean vild_b_ipkOdoBckUpEn;
  uint8 vild_st_obcChgCCSts;
  float32 obcd_pwr_obcOutpt_kW;
  uint8 vild_st_hvbChgSts;
  float32 vild_i_hvbDCChgCurReq_A;
  float32 vild_n_ead2MotActSpd_rpm;
  float32 vild_v_vscFrontAxleSpd_kph;
  uint8 hvbd_st_hvbEmgyCutOffReq;
  boolean vild_b_flgABSMsgErr;
  boolean vild_b_flgACMsgErr;
  boolean vild_b_flgBCMMsgErr;
  boolean vild_b_flgEPBMsgErr;
  boolean vild_b_flgDCDCMsgErr;
  boolean vild_b_flgSDCACMsgErr;
  boolean vild_b_flgEGSMMsgErr;
  boolean vild_b_flgTBOXMsgErr;
  boolean vild_b_flgICMsgErr;
  boolean vild_b_flgACUMsgErr;
  boolean vild_b_flgPEPSMsgErr;
  boolean vild_b_flgABSSpdMsgErr;
  boolean vild_b_flgFnctnConfgEPB;
  boolean vild_b_flgFnctnConfgACU;
  boolean vild_b_flgFnctnConfgPEPS;
  boolean vild_b_flgBDCACMsgErr;
  boolean vild_b_flgFnctnConfgEGSM;
  boolean vild_b_flgAirEPBMsgErr;
  boolean vild_b_flgFnctnConfgAirEPB;
  boolean hvbd_b_tboxIntelChgCmdRaw;
  boolean vscd_b_ehbMsgErr;
  uint8 vild_st_eadInv2FltSts;
  uint8 vild_st_ipuMotorSubFltLvl;
  float32 vild_u_ipuHVBusVolt_V;
  uint8 vild_st_ptcConnStsFb;
  float32 vild_pwr_accm1ActPwr_kW;
  boolean vild_b_epbErrSts;
  boolean vild_b_flgFnctnConfgEHB;
  float32 vild_v_ehbVehSpd_kph;
  boolean vild_b_mhgvRespErr;
  boolean vild_b_mhgvOvrVoltFlt;
  boolean vild_b_mhgvOvrCurrFlt;
  boolean vild_b_mhgvOvrTempFlt;
  boolean vild_b_mhgvUndVoltFlt;
  boolean vild_b_mhgvInitSts;
  boolean vild_b_mhgvCcwFlg;
  boolean vild_b_mhgvMotSts;
  float32 vild_pct_mhgvCrtPos;
  boolean vild_b_fwfvRespErr;
  boolean vild_b_fwfvOvrVoltFlt;
  boolean vild_b_fwfvOvrCurrFlt;
  boolean vild_b_fwfvOvrTempFlt;
  boolean vild_b_fwfvUndVoltFlt;
  boolean vild_b_fwfvInitSts;
  boolean vild_b_fwfvCcwFlg;
  boolean vild_b_fwfvMotSts;
  float32 vild_pct_fwfvCrtPos;
  uint8 adcd_st_pmsCanBusRecSta;
  uint8 vild_st_tboxChgLmtSw;
  float32 vild_pct_tboxAlwChgCurrMax;
  float32 vild_pct_tboxChgDepth;
  uint8 vild_st_tboxChgSftSwCtlSt;
  uint8 vild_st_tboxRsrChgSt;
  uint8 vild_st_tboxPrtFullSwSt;
  boolean vild_b_tboxPrtFullSwStUB;
  uint8 vild_st_obcOnBdDchaCCline;
  uint8 vild_st_obcElckStMod;
  boolean vild_b_csmV2XDchaSw;
  boolean vild_b_csmV2XDchaSwInvld;
  uint8 vild_num_hvbTempSum;
  float32 vild_R_posInsIRes_Ohm;
  uint8 vild_num_hvbCellMaxID;
  uint8 vild_num_hvbCellMinID;
  float32 vild_u_BmsMaxCellVolt_V;
  float32 vild_u_BmsMinCellVolt_V;
  uint8 vild_num_hvbMaxTempID;
  uint8 vild_num_hvbMinTempID;
  uint8 vild_st_batOvrSoc2;
  uint8 vild_st_hvbSocJumpFlt;
  uint8 vild_st_batLowSoc2;
  uint8 vild_st_hvbCellTempDevFlt;
  uint8 vild_st_cellUdrVolt2;
  uint8 vild_st_cellOverVolt2;
  uint8 vild_st_batUdrVolt2;
  uint8 vild_st_batOvrVolt2;
  uint8 vild_st_hvbTempFlt;
  uint8 vild_st_hvbInslErr;
  uint8 vild_st_hvbCellVoltDevFlt;
  uint8 vild_st_eadInv2TempHiAlrm;
  uint8 vild_st_flgFctCfgVehTyp;
  boolean vild_b_flgFctCfgMaxChgCurr;
  boolean vild_b_flgFctCfgDrvSeat;
  uint8 vild_st_flgFctCfgV2L;
  boolean vild_b_flgFctCfgEpdel;
  boolean vild_b_flgFctCfgMotor;
  uint8 vild_st_flgFctCfgMaxSpd;
  uint8 vild_st_obcOnBdCCline;
  uint8 vild_b_hvbInPositionDetct1;
  uint8 vild_b_hvbInPositionDetct2;
  uint8 vild_st_hvbPreChgSts;
  boolean vild_b_hvbDCChgCurReqRngUp;
  boolean vild_b_hvbDisChgSopRngUp;
  boolean vild_b_flgFctCfgAdc;
  float32 vild_a_yrsLongitAcce_mps2;
  uint8 vild_st_csmRgnLvlSet;
  uint8 accd_st_iptWorkSt;
  float32 vild_pwr_ptcActPwrRear_kW;
  uint8 accd_st_ptcWorkStRear;
  boolean vild_b_hvbZeroPwrReq;
  uint8 vild_st_hcmAccConnStsFb;
  float32 vild_pwr_iptActPwr_kW;
  uint8 vild_st_flgFctCfgFan;
  uint8 vscd_st_ehbAVHSts;
  uint8 vscd_st_ehbHHCActive;
  uint8 vscd_st_ehbEPBDynAppSts;
  float32 obcd_pwr_obcRlTmOutpt_kW;
  uint8 vild_st_flgFctCfgBatTyp;
  boolean vild_b_flgFctCfgTyre;
  uint8 vild_st_flgFctCfgSlowChg;
  uint8 vild_st_flgFctCfgPowerMaxSpd;
  boolean vild_b_flgFctCfgAirBag;
  uint8 vild_st_flgFctCfgMotTyp;
  boolean vild_b_flgFctCfgDrvMod;
  boolean vild_b_flgFctCfgBatCol;
  uint8 vild_st_flgFctCfgAccy;
  uint8 vild_st_flgFctCfgECOMaxSpd;
  uint8 vild_st_flgFctCfgNormalMaxSpd;
  uint8 vild_st_hvbChgCcsts;
  boolean vild_b_bcmFrntRDrAjSts;
  boolean vild_b_flgFctCfgChgTyp;
  float32 vild_u_hvbCooltInSnsr_V;
  float32 vild_u_hvbCooltOutSnsr_V;
  float32 vild_ang_strWhlAng_rad;
  uint8 vild_st_epsEpasFail;
  uint8 vild_st_hvbStsDischgFlt;
  uint8 vild_st_hvbStsChgFlt;
  uint8 vild_st_dccAccyConnStsFb;
  boolean vild_b_dcdcTempAlm;
  boolean vild_b_dcdcStsAlm;
  uint8 vild_st_ipuMotTempHighFlt;
  uint8 vild_st_ipuInvTempHighAlm;
  uint8 vild_st_hvbBatUniformity;
  uint8 vild_st_hvbOvrChgFlt;
  uint8 vild_st_hcmPtcDefRlyStFb;
  float32 vild_u_hcmPtcRlyVolt;
  float32 vild_u_hcmAcceRlyVolt;
  boolean vild_b_hcmPtcRlyVoltVldSts;
  boolean vild_b_hcmAcceRlyVoltVldSts;
  float32 vild_u_hcmMainPosBckVolt;
  boolean vild_b_hcmMainPosBckVoltVldSts;
  boolean vild_b_AccyEnReq;
  boolean vild_b_AccyFltSts;
  uint8 vild_st_bbmFltSts;
  uint8 vild_st_bbmWorkSts;
  uint8 vild_st_hcmHvilSt;
  uint8 vild_st_pepsPduLvlVld;
  uint8 hvbd_st_hvilOpenSt;
  uint8 vild_st_ipkCruisingDstSwt;
  uint8 vild_st_ehbBrkSysErrFlt;
  boolean vild_b_flgFctCfgDrvModStor;
  boolean vild_b_flgFctCfgDrvModConn;
  boolean vild_b_flgBBMMsgErr;
  boolean vild_b_disChgSwtSt;
  uint8 vild_st_flgFctCfgVehCfg;
  uint8 vild_st_flgFctCfgVehUsg;
  float32 vild_tq_ehbIsaPtTrqDecReq_Nm;
  uint8 vild_st_ehbIsaSts;
  boolean vild_b_ehbIsaPtTrqDecReqActv;
  uint8 vild_st_hcmPTC1ConnStsFb;
  boolean vild_b_tboxPowOffCmd;
  boolean vild_b_csmTakeEleSwt;
  boolean vild_b_csmTakeEleSwtReqInvld;
  float32 vild_d_ipkOdometerbackup;
  float32 vild_d_bcmOdometerbackup;
  boolean accd_b_acHvilOpnInvld;
  boolean dccd_b_dcdcHvilFltInvld;
  boolean vild_st_ipkChgSftSwCtlSt;
  uint8 vild_st_pepsRKECom;
  boolean vild_b_pdcBrkFlg;
  boolean vild_st_hvbChgLEDCtl;
  boolean vild_st_ipkAlwChgSftCtlSt;
  boolean cesd_b_acuCrash;
  float32 vild_t_acwpOutptTemp_C;
  float32 vild_pwr_acwpHeatPower_kW;
  uint8 vild_st_flg2FctCfgVehTyp;
  float32 hvbd_pwr_hvbChgPwr_kW;
  boolean vscd_b_pdcBrkFlg;
  float32 vscd_v_vehSpdRaw_kph;
  uint8 vild_st_mmiRestSwitch;
  float32 vild_l_whlRad_m;
  boolean vild_b_flgFctCfgACU;
  uint16 vild_st_flgFctCfgDspRemainRng;
  boolean vild_b_flgFctCfgDualAuthN;
  float32 vild_pct_mmiLocBkChgTarVal;
  boolean vild_b_csmCampModeSwt;
  boolean vild_b_csmCampModeSwtInvld;
  float32 vild_u_VacTkAirPres_V;
  float32 vild_u_VacTkEnFb_V;
  boolean vild_b_flgNetConfgABS;
  uint16 vild_u_vacTkPowSup_V;
  boolean vild_b_ehbVlcCddActv;
  boolean vscd_b_vscBrkLghtActv;
  float32 vscd_a_vscLongitAcce_mps2;
  boolean vild_b_flgFctCfgCoastActivBrkLight;
  boolean vild_b_pepsRmtCtrlSt;
  boolean vild_b_pepsOnSwtSt;
  boolean vild_b_csmEngRecSwtReq;
  uint8 vild_st_csmEngRecReqInvalid;
  uint8 vild_st_bmsTboxFireAlm;
  uint8 vild_st_bmsBattPackMatchFlt;
  uint8 vild_st_ipuMotorOverSpdFlt;
  uint8 vild_st_ipuMotorOverCurrFlt;
  uint8 vild_st_bmsBattSysNum;
  uint8 vild_st_bmsBattPackNum;
  uint8 vild_st_bmsDlyDataUpldEnb;
  boolean vild_b_flgFctCfgAccyButton;
} vcib_VCIP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_TBPfd1tgzD4tMizcVFA0WC_
#define DEFINED_TYPEDEF_FOR_struct_TBPfd1tgzD4tMizcVFA0WC_

typedef struct {
  boolean vild_b_mhgvRespErr;
  boolean vild_b_mhgvOvrVoltFlt;
  boolean vild_b_mhgvOvrCurrFlt;
  boolean vild_b_mhgvOvrTempFlt;
  boolean vild_b_mhgvUndVoltFlt;
  boolean vild_b_mhgvInitSts;
  boolean vild_b_mhgvCcwFlg;
  boolean vild_b_mhgvMotSts;
  float32 vild_pct_mhgvCrtPos;
  boolean vild_b_fwfvRespErr;
  boolean vild_b_fwfvOvrVoltFlt;
  boolean vild_b_fwfvOvrCurrFlt;
  boolean vild_b_fwfvOvrTempFlt;
  boolean vild_b_fwfvUndVoltFlt;
  boolean vild_b_fwfvInitSts;
  boolean vild_b_fwfvCcwFlg;
  boolean vild_b_fwfvMotSts;
  float32 vild_pct_fwfvCrtPos;
} struct_TBPfd1tgzD4tMizcVFA0WC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_vQRcAeqA88H21kX30Q6PRD_
#define DEFINED_TYPEDEF_FOR_struct_vQRcAeqA88H21kX30Q6PRD_

typedef struct {
  uint8 vild_st_bcmATWSSt;
  boolean vild_st_bcmFrntLDoorAjarSt;
  uint8 vild_st_bcmFrntRDoorAjarSt;
  uint8 vild_st_bbmFltSts;
  uint8 vild_st_bbmWorkSts;
  float32 vild_d_bcmOdometerbackup;
} struct_vQRcAeqA88H21kX30Q6PRD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_YwkBReAxMafGFqTULMey1B_
#define DEFINED_TYPEDEF_FOR_struct_YwkBReAxMafGFqTULMey1B_

typedef struct {
  uint8 vild_st_srsCrashSts;
  boolean vild_b_engDoorStatus;
  boolean vild_b_Estop;
  boolean vild_b_airbagActive;
  uint8 vild_st_acuWarnLampSts;
  uint8 vild_st_acuCrashStsInvalid;
  uint8 vild_st_acuCrashOutStsC;
  uint8 vild_st_acuCrashOutStsPT;
  boolean vild_b_acuDrvSeatbltBcklSts;
  boolean vild_b_acuDrvSeatbltBcklInvld;
} struct_YwkBReAxMafGFqTULMey1B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_JB39Xo6qrjHMw3TJPPAFCG_
#define DEFINED_TYPEDEF_FOR_struct_JB39Xo6qrjHMw3TJPPAFCG_

typedef struct {
  boolean vild_b_driverEVModeReq;
  boolean vild_b_driverHEVModeReq;
  boolean vild_b_driverEcoModeReq;
  boolean vild_b_driverSportModeReq;
  boolean vild_b_driver4WDModeReq;
  uint8 vild_st_gearLvrPosSeql;
  uint8 vild_st_parkBtnPressed;
  uint8 vild_st_egsmFltLvl;
  uint8 vild_st_egsmGearReq;
  boolean vild_b_flgFnctnConfgEGSM;
} struct_JB39Xo6qrjHMw3TJPPAFCG;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_r0gZxQnRfEcSOJqujsQhr_
#define DEFINED_TYPEDEF_FOR_struct_r0gZxQnRfEcSOJqujsQhr_

typedef struct {
  float32 vild_t_tboxSec;
  float32 vild_t_tboxMins;
  float32 vild_t_tboxHr;
  float32 vild_t_tboxDay;
  float32 vild_t_tboxMth;
  float32 vild_t_tboxYr;
  boolean vild_b_tboxIntelChgCmd;
  uint8 vild_st_McaOvrLoadInd;
  float32 vild_m_McaVehWeight_kg;
  uint16 vild_st_McaCalNum;
  uint8 vild_st_TBOXLockVehCtrl;
  uint8 vild_st_TBOXFunLockVehActive;
  uint8 vild_st_TBOXFunAntiDismantleActive;
  uint8 vild_st_TBOXLockVehType;
  float32 vild_st_TBOXLockResultResp;
  uint8 vild_st_TBOXLockLimSet;
  uint8 vild_st_tboxLockVehPerFlag;
  uint8 vild_st_tboxVersionConversionFlag;
  uint8 vild_st_tboxSpdLmtLevelReq;
  uint8 vild_st_tboxInventorySpdLmtReq;
  uint8 vild_st_tboxStartBattChgReq;
  uint8 vild_st_tboxLife;
  uint16 vild_el_tboxElevation;
  uint8 vild_st_tboxChgLmtSw;
  float32 vild_pct_tboxAlwChgCurrMax;
  float32 vild_pct_tboxChgDepth;
  uint8 vild_st_tboxChgSftSwCtlSt;
  uint8 vild_st_tboxRsrChgSt;
  uint8 vild_st_tboxPrtFullSwSt;
  boolean vild_b_tboxPrtFullSwStUB;
  boolean vild_b_tboxPowOffCmd;
} struct_r0gZxQnRfEcSOJqujsQhr;

#endif

/* PublicStructure Variables for Internal Data, for system '<S930>/timer' */
typedef struct {
  float32 UnitDelay3_DSTATE;           /* '<S932>/UnitDelay3' */
} ARID_DEF_timer_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S921>/debounce' */
typedef struct {
  float32 t_wait;                      /* '<S927>/timed_debounce' */
  uint8 is_c6_Ricardo_SW_dev_lib;      /* '<S927>/timed_debounce' */
  uint8 is_active_c6_Ricardo_SW_dev_lib;/* '<S927>/timed_debounce' */
} ARID_DEF_debounce_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S260>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S270>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S251>/turnON_delay' */
typedef struct {
  float32 t_wait;                      /* '<S254>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S254>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S254>/timed_delay' */
} ARID_DEF_turnON_delay_swc_VCI_T;

/* PublicStructure Variables for Internal Data, for system '<S167>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S185>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCIP_h_T;

/* PublicStructure Variables for Internal Data, for system '<S167>/SR_latch3' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S187>/Unit Delay' */
} ARID_DEF_SR_latch3_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S188>/SR_latch4' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S201>/Unit Delay' */
} ARID_DEF_SR_latch4_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S188>/SR_latch5' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S202>/Unit Delay' */
} ARID_DEF_SR_latch5_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S188>/SR_latch6' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S203>/Unit Delay' */
} ARID_DEF_SR_latch6_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S188>/SR_latch7' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S204>/Unit Delay' */
} ARID_DEF_SR_latch7_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S188>/SR_latch8' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S205>/Unit Delay' */
} ARID_DEF_SR_latch8_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S188>/turnON_delay' */
typedef struct {
  float32 t_wait;                      /* '<S207>/timed_delay' */
  uint8 is_c14_swc_VCIP;               /* '<S207>/timed_delay' */
  uint8 is_active_c14_swc_VCIP;        /* '<S207>/timed_delay' */
} ARID_DEF_turnON_delay_swc_V_d_T;

/* PublicStructure Variables for Internal Data, for system '<S189>/timed_delay' */
typedef struct {
  float32 t_wait;                      /* '<S189>/timed_delay' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S189>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S189>/timed_delay' */
} ARID_DEF_timed_delay_swc_VCIP_T;

/* PublicStructure Variables for Internal Data, for system '<S14>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S169>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCIP_f_T;

/* PublicStructure Variables for Internal Data, for system '<S10>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S110>/Unit Delay' */
} ARID_DEF_SR_latch_swc_VCIP_fi_T;

/* PublicStructure Variables for Internal Data, for system '<S10>/turnON_delay1' */
typedef struct {
  float32 t_wait;                      /* '<S115>/timed_delay' */
  uint8 is_c19_swc_VCIP;               /* '<S115>/timed_delay' */
  uint8 is_active_c19_swc_VCIP;        /* '<S115>/timed_delay' */
} ARID_DEF_turnON_delay1_swc_VC_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_turnON_delay_swc_VCI_T ARID_DEF_turnON_delay;/* '<S6>/turnON_delay' */
  ARID_DEF_turnON_delay_swc_VCI_T ARID_DEF_turnON_delay_m;/* '<S20>/turnON_delay' */
  ARID_DEF_timed_delay_swc_VCIP_T ARID_DEF_timed_delay;/* '<S306>/timed_delay' */
  ARID_DEF_SR_latch_swc_VCIP_T ARID_DEF_SR_latch;/* '<S20>/SR_latch' */
  ARID_DEF_turnON_delay1_swc_VC_T ARID_DEF_turnON_delay2;/* '<S4>/turnON_delay2' */
  ARID_DEF_turnON_delay1_swc_VC_T ARID_DEF_turnON_delay1;/* '<S4>/turnON_delay1' */
  ARID_DEF_SR_latch_swc_VCIP_fi_T ARID_DEF_SR_latch1;/* '<S4>/SR_latch1' */
  ARID_DEF_turnON_delay1_swc_VC_T ARID_DEF_turnON_delay2_c;/* '<S10>/turnON_delay2' */
  ARID_DEF_turnON_delay1_swc_VC_T ARID_DEF_turnON_delay1_k;/* '<S10>/turnON_delay1' */
  ARID_DEF_SR_latch_swc_VCIP_fi_T ARID_DEF_SR_latch1_c;/* '<S10>/SR_latch1' */
  ARID_DEF_turnON_delay_swc_VCI_T ARID_DEF_turnON_delay_b;/* '<S14>/turnON_delay ' */
  ARID_DEF_turnON_delay_swc_VCI_T ARID_DEF_turnON_delay_p;/* '<S14>/turnON_delay' */
  ARID_DEF_SR_latch_swc_VCIP_f_T ARID_DEF_SR_latch_c;/* '<S14>/SR_latch' */
  ARID_DEF_turnON_delay_swc_VCI_T ARID_DEF_turnON_delay1_f;/* '<S167>/turnON_delay1' */
  ARID_DEF_timed_delay_swc_VCIP_T ARID_DEF_timed_delay_g;/* '<S189>/timed_delay' */
  ARID_DEF_turnON_delay_swc_V_d_T ARID_DEF_turnON_delay7;/* '<S188>/turnON_delay7' */
  ARID_DEF_turnON_delay_swc_V_d_T ARID_DEF_turnON_delay6;/* '<S188>/turnON_delay6' */
  ARID_DEF_turnON_delay_swc_V_d_T ARID_DEF_turnON_delay5;/* '<S188>/turnON_delay5' */
  ARID_DEF_turnON_delay_swc_V_d_T ARID_DEF_turnON_delay4;/* '<S188>/turnON_delay4' */
  ARID_DEF_turnON_delay_swc_V_d_T ARID_DEF_turnON_delay3;/* '<S188>/turnON_delay3' */
  ARID_DEF_turnON_delay_swc_V_d_T ARID_DEF_turnON_delay2_g;/* '<S188>/turnON_delay2' */
  ARID_DEF_turnON_delay_swc_V_d_T ARID_DEF_turnON_delay_me;/* '<S188>/turnON_delay' */
  ARID_DEF_SR_latch8_swc_VCIP_T ARID_DEF_SR_latch8;/* '<S188>/SR_latch8' */
  ARID_DEF_SR_latch7_swc_VCIP_T ARID_DEF_SR_latch7;/* '<S188>/SR_latch7' */
  ARID_DEF_SR_latch6_swc_VCIP_T ARID_DEF_SR_latch6;/* '<S188>/SR_latch6' */
  ARID_DEF_SR_latch5_swc_VCIP_T ARID_DEF_SR_latch5;/* '<S188>/SR_latch5' */
  ARID_DEF_SR_latch4_swc_VCIP_T ARID_DEF_SR_latch4;/* '<S188>/SR_latch4' */
  ARID_DEF_SR_latch3_swc_VCIP_T ARID_DEF_SR_latch3;/* '<S167>/SR_latch3' */
  ARID_DEF_SR_latch_swc_VCIP_T ARID_DEF_SR_latch2;/* '<S167>/SR_latch2' */
  ARID_DEF_SR_latch_swc_VCIP_h_T ARID_DEF_SR_latch1_n;/* '<S167>/SR_latch1' */
  ARID_DEF_turnON_delay_swc_VCI_T ARID_DEF_turnON_delay_pp;/* '<S251>/turnON_delay' */
  ARID_DEF_SR_latch_swc_VCIP_T ARID_DEF_SR_latch1_l;/* '<S260>/SR_latch1' */
  ARID_DEF_SR_latch_swc_VCIP_T ARID_DEF_SR_latch_j;/* '<S260>/SR_latch' */
  ARID_DEF_debounce_swc_VCIP_T ARID_DEF_debounce1;/* '<S921>/debounce1' */
  ARID_DEF_debounce_swc_VCIP_T ARID_DEF_debounce;/* '<S921>/debounce' */
  ARID_DEF_timer_swc_VCIP_T ARID_DEF_timer;/* '<S938>/timer' */
  ARID_DEF_timer_swc_VCIP_T ARID_DEF_timer_d;/* '<S934>/timer' */
  ARID_DEF_timer_swc_VCIP_T ARID_DEF_timer_g;/* '<S930>/timer' */
  float32 VariableIntegerDelay_DSTATE[100];/* '<S302>/Variable Integer Delay' */
  float32 Switch3;                     /* '<S6>/Switch3' */
  float32 vscd_v_vehSpd_kph;           /* '<S20>/Switch' */
  float32 vscd_tq_axle2MaxTqReq_Nm;    /* '<S303>/Constant3' */
  float32 vscd_tq_axle2MinTqReq_Nm;    /* '<S303>/Constant5' */
  float32 vscd_tq_axle2RgnBrkTqReq_Nm; /* '<S300>/Constant2' */
  float32 vscd_tq_vscEHBPtTrqDecReq_Nm;/* '<S20>/SignalConversion156' */
  float32 vscd_tq_vscEHBPtTrqIncReq_Nm;/* '<S20>/SignalConversion157' */
  float32 vscd_tq_vscEHBVlcPtTrqReq_Nm;/* '<S20>/SignalConversion161' */
  float32 vscd_tq_vscEHBMbRgnTgtWhl_Nm;/* '<S20>/SignalConversion164' */
  float32 accd_u_acPresVolt_V;         /* '<S4>/Signal Conversion13' */
  float32 accd_n_acFanReqSpd_pct;      /* '<S4>/Signal Conversion20' */
  float32 eadd_i_eadInv2ActCurrDC_A;   /* '<S12>/Signal Conversion7' */
  float32 hvbd_q_hvbSOC_pct;           /* '<S14>/Signal Conversion2' */
  float32 hvbd_t_hvbInCoolTemp_C;      /* '<S14>/Signal Conversion15' */
  float32 hvbd_t_hvbAvg_C;             /* '<S14>/Signal Conversion20' */
  float32 hvbd_t_acwpOutptTemp_C;      /* '<S14>/Signal Conversion1' */
  float32 vild_tq_adc0TargetDrvTq_Nm;  /* '<S385>/SignalConversion70' */
  float32 vild_tq_adc1TargetDrvTq_Nm;  /* '<S385>/SignalConversion76' */
  float32 vild_tq_adc02TargetDrvTq_Nm; /* '<S385>/SignalConversion144' */
  float32 vild_tq_adc12TargetDrvTq_Nm; /* '<S385>/SignalConversion150' */
  float32 vild_v_cruiseADvoltage;      /* '<S922>/Signal Conversion7' */
  float32 signal_mn;                   /* '<S1021>/Switch2' */
  float32 AT1;                         /* '<S938>/RollingAverage' */
  float32 AT1_m;                       /* '<S934>/RollingAverage' */
  float32 AT1_i;                       /* '<S930>/RollingAverage' */
  float32 vild_st_TBOXLockResultResp;  /* '<S1232>/Signal Conversion15' */
  float32 Switch2;                     /* '<S1238>/Switch2' */
  float32 Switch2_a;                   /* '<S1239>/Switch2' */
  float32 vild_pct_mhgvCrtPos;         /* '<S502>/Signal Conversion9' */
  float32 vild_pct_fwfvCrtPos;         /* '<S502>/Signal Conversion17' */
  float32 signal_d;                    /* '<S1214>/Switch2' */
  float32 vild_tq_vscEHBPtTrqDecReq_Nm;/* '<S1288>/SignalConversion156' */
  float32 vild_tq_vscEHBPtTrqIncReq_Nm;/* '<S1288>/SignalConversion157' */
  float32 vild_tq_vscEHBVlcPtTrqReq_Nm;/* '<S1288>/SignalConversion161' */
  float32 vild_tq_vscEHBMbRgnTgtWhl_Nm;/* '<S1288>/SignalConversion164' */
  float32 vild_t_obcTemp_C_o;          /* '<S1141>/Signal Conversion2' */
  float32 vild_u_obcOutptVolt_V_b;     /* '<S1141>/Signal Conversion21' */
  float32 vild_i_obcOutptCurr_A_e;     /* '<S1141>/Signal Conversion22' */
  float32 vild_pwr_obcPwrEgyMgrAvl_kW_j;/* '<S1141>/Signal Conversion27' */
  float32 vild_tq_eadMot2LTBstTqLim_Nm;/* '<S615>/Signal Conversion5' */
  float32 vild_tq_eadMot2STBstTqLim_Nm;/* '<S615>/Signal Conversion8' */
  float32 vild_tq_eadMot2LTGenTqLim_Nm;/* '<S615>/Signal Conversion7' */
  float32 vild_tq_eadMot2STGenTqLim_Nm;/* '<S615>/Signal Conversion9' */
  float32 vild_n_ead2MotActSpd_rpm;    /* '<S615>/Signal Conversion10' */
  float32 vild_tq_eadMot2ActTq_Nm;     /* '<S615>/Signal Conversion11' */
  float32 vild_i_eadInv2ActCurrDC_A;   /* '<S615>/Signal Conversion2' */
  float32 vild_u_eadInv2ActVoltDC_V;   /* '<S615>/Signal Conversion3' */
  float32 vild_t_eadMot2Temp_C;        /* '<S615>/Signal Conversion6' */
  float32 vild_t_eadInv2Temp_C;        /* '<S615>/Signal Conversion1' */
  float32 vild_u_ipuHVBusVolt_V;       /* '<S615>/Signal Conversion45' */
  float32 vild_t_hvbMax_C;             /* '<S703>/Signal Conversion4' */
  float32 vild_t_hvbMin_C;             /* '<S703>/Signal Conversion1' */
  float32 vild_i_hvbCurr_A;            /* '<S703>/Signal Conversion2' */
  float32 vild_q_hvbSOC_pct;           /* '<S703>/Signal Conversion6' */
  float32 vild_u_hvbVolt_V;            /* '<S703>/Signal Conversion3' */
  float32 vild_pwr_hvbSTChrgPwrMax_kW; /* '<S703>/Signal Conversion98' */
  float32 vild_pwr_hvbLTChrgPwrMax_kW; /* '<S703>/Signal Conversion99' */
  float32 vild_pwr_hvbSTDischPwrMax_kW;/* '<S703>/Signal Conversion24' */
  float32 vild_pwr_hvbLTDischPwrMax_kW;/* '<S703>/Signal Conversion25' */
  float32 vild_fact_hvbSOH_pct;        /* '<S703>/Signal Conversion7' */
  float32 vild_t_hvbInCoolTemp_C;      /* '<S703>/Signal Conversion54' */
  float32 vild_t_hvbAvg_C;             /* '<S703>/Signal Conversion40' */
  float32 vild_E_hvbPackRemnEgy_kWh;   /* '<S703>/Signal Conversion26' */
  float32 vild_R_posInslRes_Ohm;       /* '<S703>/Signal Conversion73' */
  float32 vild_t_hvbOutCoolTemp_C;     /* '<S703>/Signal Conversion104' */
  float32 vild_t_hvbSetTgtTemp_C;      /* '<S703>/Signal Conversion105' */
  float32 vild_u_BmsMinCellVolt_V_d;   /* '<S703>/Signal Conversion115' */
  float32 vild_u_BmsMaxCellVolt_V_a;   /* '<S703>/Signal Conversion116' */
  float32 vild_tm_hvbFnshChgTim_m;     /* '<S703>/SignalConversion1' */
  float32 vild_u_hvbPackVolt_V;        /* '<S703>/SignalConversion2' */
  float32 vild_t_dcdcTemp_C;           /* '<S561>/Signal Conversion4' */
  float32 vild_i_dcdcInpCurr_A;        /* '<S561>/Signal Conversion14' */
  float32 vild_u_dcdcInpVolt_V;        /* '<S561>/Signal Conversion13' */
  float32 vild_u_dcdcRelayVolt_V;      /* '<S561>/Signal Conversion33' */
  float32 vild_u_brkVacuumPres_V;      /* '<S517>/Signal Conversion2' */
  float32 OutportBufferForvild_x_accPedlP;/* '<S340>/Constant' */
  float32 OutportBufferForvild_u_accPdlSe;/* '<S340>/Constant2' */
  float32 OutportBufferForvild_u_accPdl_m;/* '<S340>/Constant3' */
  float32 vild_t_outdTemp_C;           /* '<S342>/Signal Conversion2' */
  float32 vild_pwr_airCmprAct_kW;      /* '<S342>/Signal Conversion1' */
  float32 vild_pwr_PTCActPwr_kW;       /* '<S342>/Signal Conversion4' */
  float32 vild_u_acPresVolt_V;         /* '<S342>/Signal Conversion11' */
  float32 vild_n_acFanReqSpd_pct_a;    /* '<S342>/Signal Conversion44' */
  float32 vild_t_acwpOutptTemp_C;      /* '<S342>/Signal Conversion41' */
  float32 vild_pwr_acwpHeatPower_kW;   /* '<S342>/Signal Conversion3' */
  float32 UnitDelay_DSTATE;            /* '<S42>/Unit Delay' */
  float32 UnitDelay_DSTATE_p;          /* '<S43>/Unit Delay' */
  float32 UnitDelay_DSTATE_pa;         /* '<S53>/Unit Delay' */
  float32 UnitDelay_DSTATE_a;          /* '<S55>/Unit Delay' */
  float32 UnitDelay_DSTATE_m;          /* '<S293>/Unit Delay' */
  float32 UnitDelay_DSTATE_b;          /* '<S311>/Unit Delay' */
  float32 UnitDelay_DSTATE_as;         /* '<S310>/Unit Delay' */
  float32 UnitDelay_DSTATE_e;          /* '<S282>/Unit Delay' */
  float32 UnitDelay_DSTATE_h;          /* '<S127>/Unit Delay' */
  float32 UnitDelay_DSTATE_l;          /* '<S128>/Unit Delay' */
  float32 UnitDelay_DSTATE_at;         /* '<S129>/Unit Delay' */
  float32 UnitDelay1_DSTATE;           /* '<S14>/Unit Delay1' */
  float32 Delay1_DSTATE;               /* '<S930>/Delay1' */
  float32 UnitDelay_DSTATE_a1;         /* '<S930>/Unit Delay' */
  float32 UnitDelay_DSTATE_o;          /* '<S924>/Unit Delay' */
  float32 Delay1_DSTATE_e;             /* '<S934>/Delay1' */
  float32 UnitDelay_DSTATE_hc;         /* '<S934>/Unit Delay' */
  float32 UnitDelay_DSTATE_g;          /* '<S925>/Unit Delay' */
  float32 Delay1_DSTATE_o;             /* '<S938>/Delay1' */
  float32 UnitDelay_DSTATE_k;          /* '<S938>/Unit Delay' */
  float32 UnitDelay_DSTATE_ki;         /* '<S926>/Unit Delay' */
  float32 Delay1_DSTATE_g;             /* '<S1354>/Delay1' */
  float32 Delay3_DSTATE;               /* '<S1354>/Delay3' */
  float32 t_wait;                      /* '<S77>/timed_debounce' */
  float32 t_wait_b;                    /* '<S75>/timed_debounce' */
  float32 t_wait_o;                    /* '<S73>/timed_debounce' */
  float32 t_wait_p;                    /* '<S71>/timed_debounce' */
  float32 t_wait_a;                    /* '<S69>/timed_debounce' */
  float32 t_wait_h;                    /* '<S67>/timed_debounce' */
  float32 t_wait_ot;                   /* '<S98>/timed_debounce' */
  float32 t_wait_g;                    /* '<S97>/timed_debounce' */
  float32 t_wait_p1;                   /* '<S305>/timed_delay' */
  float32 t_wait_ow;                   /* '<S304>/timed_debounce' */
  float32 y_prev;                      /* '<S302>/MATLAB Function' */
  float32 t_wait_l;                    /* '<S215>/timed_delay' */
  float32 t_wait_e;                    /* '<S267>/timed_debounce' */
  float32 t_wait_by;                   /* '<S1189>/timed_debounce' */
  uint16 vild_num_hvbCellSum;          /* '<S703>/SignalConversion170' */
  uint8 DataTypeConversion22;          /* '<S1>/Data Type Conversion22' */
  uint8 Switch11;                      /* '<S6>/Switch11' */
  uint8 Switch28;                      /* '<S6>/Switch28' */
  uint8 macd_st_sdcacWrk;              /* '<S15>/Signal Conversion5' */
  uint8 vscd_b_vscEHBMbRgnTgtWhlSts;   /* '<S20>/SignalConversion163' */
  uint8 accd_st_cbnThermMngReq;        /* '<S4>/Signal Conversion9' */
  uint8 dccd_st_12vDcdcModAct;         /* '<S10>/Signal Conversion2' */
  uint8 dccd_st_24vDcdcModAct;         /* '<S10>/Signal Conversion5' */
  uint8 eadd_st_eadInv2WrkMod;         /* '<S12>/Signal Conversion11' */
  uint8 hvbd_st_hvbThermMngReq;        /* '<S14>/Signal Conversion10' */
  uint8 hvbd_st_hcmMaiRlyNeg;          /* '<S14>/Signal Conversion16' */
  uint8 hvbd_st_hvbPwrActvMod;         /* '<S14>/Signal Conversion21' */
  uint8 hvbd_st_hcmPwrActvMod;         /* '<S14>/Signal Conversion22' */
  uint8 vild_st_rfrSwapprocd;          /* '<S1217>/SignalConversion80' */
  uint8 vild_st_rfrConnctSts;          /* '<S1217>/SignalConversion84' */
  uint8 vild_st_adc0TargetGearPostion; /* '<S385>/SignalConversion66' */
  uint8 vild_st_adc1TargetGearPostion; /* '<S385>/SignalConversion72' */
  uint8 vild_st_adc02TargetGearPostion;/* '<S385>/SignalConversion140' */
  uint8 vild_st_adc12TargetGearPostion;/* '<S385>/SignalConversion146' */
  uint8 Cntr;                          /* '<S938>/RollingAverage' */
  uint8 Cntr_i;                        /* '<S934>/RollingAverage' */
  uint8 Cntr_m;                        /* '<S930>/RollingAverage' */
  uint8 signal_nk;                     /* '<S513>/Switch2' */
  uint8 vild_st_TBOXLockVehCtrl;       /* '<S1232>/Signal Conversion11' */
  uint8 vild_st_TBOXFunLockVehActive;  /* '<S1232>/Signal Conversion12' */
  uint8 vild_st_TBOXFunAntiDismantleAct;/* '<S1232>/Signal Conversion13' */
  uint8 vild_st_TBOXLockVehType;       /* '<S1232>/Signal Conversion14' */
  uint8 vild_st_TBOXLockLimSet;        /* '<S1232>/type_conv' */
  uint8 Switch2_g;                     /* '<S1252>/Switch2' */
  uint8 Switch2_l;                     /* '<S1257>/Switch2' */
  uint8 Switch2_h;                     /* '<S1255>/Switch2' */
  uint8 Switch2_e;                     /* '<S1250>/Switch2' */
  uint8 Switch2_d;                     /* '<S1256>/Switch2' */
  uint8 Switch2_dw;                    /* '<S1251>/Switch2' */
  uint8 Switch2_k;                     /* '<S1248>/Switch2' */
  uint8 Switch2_f;                     /* '<S1249>/Switch2' */
  uint8 Switch2_fl;                    /* '<S1254>/Switch2' */
  uint8 Switch2_pn;                    /* '<S1253>/Switch2' */
  uint8 signal_jfh;                    /* '<S1213>/Switch2' */
  uint8 vild_st_epsWrkSt;              /* '<S1200>/Signal Conversion3' */
  uint8 vild_st_epsFltLvl;             /* '<S1200>/Signal Conversion29' */
  uint8 vild_st_epsSubFltLvl;          /* '<S1200>/Signal Conversion5' */
  uint8 vild_st_epsErrorCode;          /* '<S1200>/Signal Conversion6' */
  uint8 vild_st_pepsPduLvlVld;         /* '<S1180>/Signal Conversion' */
  uint8 vild_b_vscEHBMbRgnTgtWhlSts;   /* '<S1288>/SignalConversion163' */
  uint8 vild_st_ehbBrkSysErrFlt_a;     /* '<S1288>/Signal Conversion55' */
  uint8 vild_st_obcOnBdCCline_a;       /* '<S1141>/Signal Conversion20' */
  uint8 vild_st_dcChgCcSt;             /* '<S1141>/Signal Conversion' */
  uint8 vild_st_obcfltLvl_o;           /* '<S1141>/Signal Conversion3' */
  uint8 vild_st_obcLockLoopSts_o;      /* '<S1141>/Signal Conversion8' */
  uint8 vild_st_obcChgCCSts_d;         /* '<S1141>/Signal Conversion18' */
  uint8 vild_st_obcChgSts;             /* '<S1141>/Signal Conversion19' */
  uint8 vild_st_obcOnBdDchaCCline_n;   /* '<S1141>/Signal Conversion23' */
  uint8 vild_st_obcElckStMod_j;        /* '<S1141>/Signal Conversion24' */
  uint8 vild_st_obcOnBdCPline_d;       /* '<S1141>/Signal Conversion28' */
  uint8 vild_st_ead2InvActMode;        /* '<S615>/Signal Conversion12' */
  uint8 vild_st_eadInv2FltSts;         /* '<S615>/Signal Conversion4' */
  uint8 vild_st_eadInv2Sts;            /* '<S615>/Signal Conversion14' */
  uint8 vild_st_eadInv2WrkMod;         /* '<S615>/Signal Conversion13' */
  uint8 vild_st_eadInv2TempHiAlrm;     /* '<S615>/Signal Conversion21' */
  uint8 vild_st_eadInv2PwrActvMod;     /* '<S615>/Signal Conversion32' */
  uint8 vild_st_inv2SubFltSts;         /* '<S615>/Signal Conversion34' */
  uint8 vild_st_eadMot2ImmoRlsChk;     /* '<S615>/Signal Conversion35' */
  uint8 vild_st_ipuMotTempHighFlt;     /* '<S615>/Signal Conversion46' */
  uint8 vild_st_ipuInvTempHighAlm;     /* '<S615>/Signal Conversion47' */
  uint8 Switch2_b;                     /* '<S613>/Switch2' */
  uint8 Switch2_az;                    /* '<S609>/Switch2' */
  uint8 Switch2_gp;                    /* '<S610>/Switch2' */
  uint8 vild_st_prkBrkSts_n;           /* '<S691>/Signal Conversion8' */
  uint8 vild_st_hvbStatus;             /* '<S905>/Switch' */
  uint8 vild_st_actWorkSts1;           /* '<S703>/Signal Conversion122' */
  uint8 vild_st_hvbMaiRlyPos;          /* '<S703>/Signal Conversion37' */
  uint8 vild_st_hvbAssiRly;            /* '<S703>/Signal Conversion38' */
  uint8 vild_st_hvbMaiRlyNeg;          /* '<S703>/Signal Conversion36' */
  uint8 vild_st_hcmMaiRlyNeg;          /* '<S703>/Signal Conversion46' */
  uint8 vild_st_hvbHvilFlt;            /* '<S703>/Signal Conversion139' */
  uint8 vild_st_hvbInslErr;            /* '<S703>/Signal Conversion28' */
  uint8 vild_st_hvbFltSts;             /* '<S703>/Signal Conversion8' */
  uint8 vild_st_hcmWrkSt;              /* '<S703>/Signal Conversion5' */
  uint8 vild_st_hvbThermMngReq;        /* '<S703>/Signal Conversion22' */
  uint8 vild_st_hcmFltLvl;             /* '<S703>/Signal Conversion33' */
  uint8 vild_st_hvbPwrActvMod;         /* '<S703>/Signal Conversion42' */
  uint8 vild_st_hcmPwrActvMod;         /* '<S703>/Signal Conversion43' */
  uint8 vild_st_hvbSocFlt;             /* '<S703>/Signal Conversion49' */
  uint8 vild_st_hvbTempFlt;            /* '<S703>/Signal Conversion57' */
  uint8 vild_st_hvbSocJumpFlt;         /* '<S703>/Signal Conversion58' */
  uint8 vild_st_hvbOvrChgFlt;          /* '<S703>/Signal Conversion27' */
  uint8 vild_st_hvbBattIsolationSts;   /* '<S703>/Signal Conversion61' */
  uint8 vild_st_hvbCellTempDevFlt;     /* '<S703>/Signal Conversion70' */
  uint8 vild_st_hvbCellVoltDevFlt;     /* '<S703>/Signal Conversion71' */
  uint8 vild_st_hcmPtcDefRlyStFb;      /* '<S703>/Signal Conversion52' */
  uint8 vild_st_hcmHvilSt;             /* '<S703>/Signal Conversion81' */
  uint8 vild_st_hvbSubFaultSts;        /* '<S703>/Signal Conversion78' */
  uint8 vild_st_BmsTempOutOfCtrlFlt_k; /* '<S703>/Signal Conversion112' */
  uint8 vild_st_hvbDischgFltReq_g;     /* '<S703>/SignalConversion167' */
  uint8 vild_st_hvbChgFltReq_l;        /* '<S703>/SignalConversion168' */
  uint8 vild_st_hvbDCChgProcss;        /* '<S703>/SignalConversion175' */
  uint8 vild_st_hvbChgOvrCurr;         /* '<S703>/SignalConversion176' */
  uint8 vild_st_hvbDCChgPlgPOvrTmp;    /* '<S703>/SignalConversion177' */
  uint8 vild_st_hvbDCChgPlgNOvrTmp;    /* '<S703>/SignalConversion178' */
  uint8 vild_st_dcdcFltSts;            /* '<S561>/Signal Conversion3' */
  uint8 DataTypeConversion;            /* '<S604>/Data Type Conversion' */
  uint8 vild_st_24vDcdcModAct;         /* '<S561>/Signal Conversion9' */
  uint8 vild_st_24vDcdcFltSts;         /* '<S561>/Signal Conversion5' */
  uint8 vild_st_24vDcdcSubFltSts;      /* '<S561>/Signal Conversion6' */
  uint8 vild_st_dcdcErrorCode;         /* '<S561>/Signal Conversion31' */
  uint8 vild_st_dccAccyConnStsFb_g;    /* '<S561>/Signal Conversion36' */
  uint8 vild_st_acuCrashOutStsC;
  uint8 vild_st_acuCrashOutStsPT;
  uint8 vild_st_brkPedlStsFromCan;     /* '<S517>/Signal Conversion1' */
  uint8 vild_st_brkPmpWrkSt;           /* '<S517>/Signal Conversion6' */
  uint8 vild_st_acWrkSts;              /* '<S342>/Signal Conversion12' */
  uint8 vild_st_cbnThermMngReq;        /* '<S342>/Signal Conversion5' */
  uint8 vild_st_airCmprSt;             /* '<S342>/Signal Conversion7' */
  uint8 vild_st_PTCSt;                 /* '<S342>/Signal Conversion6' */
  uint8 vild_st_acFltLvl_h;            /* '<S342>/Signal Conversion32' */
  uint8 vild_st_acSubFltSts_c;         /* '<S342>/Signal Conversion33' */
  uint8 vild_st_ptcConnStsFb_o;        /* '<S342>/Signal Conversion45' */
  KeyAuthStatus vild_ImmoReleaseStatus;/* '<S1180>/Data Type Conversion' */
  CanDataStatus vild_e_msgDataStatusOBC;/* '<S1141>/Signal Conversion9' */
  uint8 UnitDelay_DSTATE_co;           /* '<S294>/Unit Delay' */
  uint8 UnitDelay_DSTATE_oe;           /* '<S188>/Unit Delay' */
  uint8 Delay_DSTATE;                  /* '<S9>/Delay' */
  uint8 Delay1_DSTATE_j;               /* '<S9>/Delay1' */
  DCDCMode Delay_DSTATE_i;             /* '<S188>/Delay' */
  PmmStatus UnitDelay1_DSTATE_ij;      /* '<S20>/Unit Delay1' */
  uint8 is_c16_swc_VCIP;               /* '<S77>/timed_debounce' */
  uint8 is_active_c16_swc_VCIP;        /* '<S77>/timed_debounce' */
  uint8 is_c15_swc_VCIP;               /* '<S75>/timed_debounce' */
  uint8 is_active_c15_swc_VCIP;        /* '<S75>/timed_debounce' */
  uint8 is_c11_swc_VCIP;               /* '<S73>/timed_debounce' */
  uint8 is_active_c11_swc_VCIP;        /* '<S73>/timed_debounce' */
  uint8 is_c10_swc_VCIP;               /* '<S71>/timed_debounce' */
  uint8 is_active_c10_swc_VCIP;        /* '<S71>/timed_debounce' */
  uint8 is_c9_swc_VCIP;                /* '<S69>/timed_debounce' */
  uint8 is_active_c9_swc_VCIP;         /* '<S69>/timed_debounce' */
  uint8 is_c8_swc_VCIP;                /* '<S67>/timed_debounce' */
  uint8 is_active_c8_swc_VCIP;         /* '<S67>/timed_debounce' */
  uint8 is_c6_Ricardo_SW_dev_lib;      /* '<S98>/timed_debounce' */
  uint8 is_active_c6_Ricardo_SW_dev_lib;/* '<S98>/timed_debounce' */
  uint8 is_c6_Ricardo_SW_dev_lib_d;    /* '<S97>/timed_debounce' */
  uint8 is_active_c6_Ricardo_SW_dev_l_p;/* '<S97>/timed_debounce' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S305>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S305>/timed_delay' */
  uint8 is_c6_Ricardo_SW_dev_lib_g;    /* '<S304>/timed_debounce' */
  uint8 is_active_c6_Ricardo_SW_dev_l_i;/* '<S304>/timed_debounce' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S215>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S215>/timed_delay' */
  uint8 is_c6_Ricardo_SW_dev_lib_a;    /* '<S267>/timed_debounce' */
  uint8 is_active_c6_Ricardo_SW_dev__i3;/* '<S267>/timed_debounce' */
  uint8 is_c7_swc_VCIP;                /* '<S259>/PDULevel' */
  uint8 is_ACTIVE;                     /* '<S259>/PDULevel' */
  uint8 is_active_c7_swc_VCIP;         /* '<S259>/PDULevel' */
  uint8 is_c27_swc_VCIP;               /* '<S1189>/timed_debounce' */
  uint8 is_active_c27_swc_VCIP;        /* '<S1189>/timed_debounce' */
  boolean DataTypeConversion408;       /* '<S1>/Data Type Conversion408' */
  boolean DataTypeConversion410;       /* '<S1>/Data Type Conversion410' */
  boolean Switch2_j;                   /* '<S6>/Switch2' */
  boolean flg_out;                     /* '<S77>/timed_debounce' */
  boolean flg_out_e;                   /* '<S75>/timed_debounce' */
  boolean flg_out_eq;                  /* '<S73>/timed_debounce' */
  boolean flg_out_eq2;                 /* '<S71>/timed_debounce' */
  boolean flg_out_eq25;                /* '<S69>/timed_debounce' */
  boolean flg_out_eq25a;               /* '<S67>/timed_debounce' */
  boolean macd_b_pullUpDiagCmpl;       /* '<S15>/Signal Conversion15' */
  boolean LogicalOperator6;            /* '<S20>/Logical Operator6' */
  boolean vscd_b_vehSlipWarn;          /* '<S20>/Constant8' */
  boolean vscd_b_ehbAbsOvrdActv;       /* '<S20>/Logical Operator1' */
  boolean vscd_b_vscEHBAebActv;        /* '<S20>/SignalConversion154' */
  boolean vscd_b_vscEHBPtTrqDecReqActv;/* '<S20>/SignalConversion155' */
  boolean vscd_b_vscEHBVlcPtTrqReqActv;/* '<S20>/SignalConversion160' */
  boolean vscd_b_vscEHBPtTrqIncReqActv;/* '<S20>/SignalConversion162' */
  boolean vscd_b_vscEHBVlcAvlb;        /* '<S20>/SignalConversion158' */
  boolean vscd_b_vscEHBVlcActv;        /* '<S20>/SignalConversion159' */
  boolean vscd_b_vscEHBDtcActv;        /* '<S20>/SignalConversion165' */
  boolean LogicalOperator3;            /* '<S301>/Logical Operator3' */
  boolean eadd_st_eadInv2Sts;          /* '<S12>/Signal Conversion6' */
  boolean hvbd_b_hcmRlyWldFlt;         /* '<S14>/Constant4' */
  boolean Switch1;                     /* '<S9>/Switch1' */
  boolean vild_b_rfrSwapBatReq;        /* '<S1217>/SignalConversion81' */
  boolean vild_b_adc1SwitchCtrlReq;    /* '<S385>/SignalConversion63' */
  boolean vild_b_adc0CtrlGearEn;       /* '<S385>/SignalConversion67' */
  boolean vild_b_adc0CtrlTorqEn;       /* '<S385>/SignalConversion68' */
  boolean vild_b_adc1CtrlGearEn;       /* '<S385>/SignalConversion73' */
  boolean vild_b_adc1CtrlTorqEn;       /* '<S385>/SignalConversion74' */
  boolean vild_b_adc12SwitchCtrlReq;   /* '<S385>/SignalConversion137' */
  boolean vild_b_adc02CtrlGearEn;      /* '<S385>/SignalConversion141' */
  boolean vild_b_adc02CtrlTorqEn;      /* '<S385>/SignalConversion142' */
  boolean vild_b_adc12CtrlGearEn;      /* '<S385>/SignalConversion147' */
  boolean vild_b_adc12CtrlTorqEn;      /* '<S385>/SignalConversion148' */
  boolean vild_b_adc01CtrComRxToutFlg; /* '<S385>/Signal Conversion' */
  boolean vild_b_adc11CtrComRxToutFlg; /* '<S385>/Signal Conversion3' */
  boolean vild_b_adc01PMSCtrCsmErrFlg; /* '<S385>/Signal Conversion7' */
  boolean vild_b_adc01PMSCtrAlvCtrErrFlg;/* '<S385>/Signal Conversion8' */
  boolean vild_b_adc11PMSCtrCsmErrFlg; /* '<S385>/Signal Conversion10' */
  boolean vild_b_adc11PMSCtrAlvCtrErrFlg;/* '<S385>/Signal Conversion11' */
  boolean vild_b_adc02CtrComRxToutFlg; /* '<S385>/Signal Conversion12' */
  boolean vild_b_adc12CtrComRxToutFlg; /* '<S385>/Signal Conversion15' */
  boolean vild_b_adc02PMSCtrCsmErrFlg; /* '<S385>/Signal Conversion17' */
  boolean vild_b_adc02PMSCtrAlvCtrErrFlg;/* '<S385>/Signal Conversion18' */
  boolean vild_b_adc12PMSCtrCsmErrFlg; /* '<S385>/Signal Conversion20' */
  boolean vild_b_adc12PMSCtrAlvCtrErrFlg;/* '<S385>/Signal Conversion21' */
  boolean vild_b_pmsCANBusOffFlg;      /* '<S385>/Signal Conversion24' */
  boolean vild_b_adcCANBusOffFlg;      /* '<S385>/Signal Conversion25' */
  boolean vild_b_flgBBMMsgErr_g;       /* '<S1055>/Signal Conversion4' */
  boolean flg_out_ez;                  /* '<S928>/timed_debounce' */
  boolean flg_out_l;                   /* '<S927>/timed_debounce' */
  boolean vild_b_tboxIntelChgCmd;      /* '<S1232>/Signal Conversion7' */
  boolean Switch2_i;                   /* '<S1235>/Switch2' */
  boolean Switch2_c;                   /* '<S1234>/Switch2' */
  boolean vild_b_mhgvRespErr;          /* '<S502>/Signal Conversion' */
  boolean vild_b_mhgvOvrVoltFlt;       /* '<S502>/Signal Conversion1' */
  boolean vild_b_mhgvOvrCurrFlt;       /* '<S502>/Signal Conversion2' */
  boolean vild_b_mhgvOvrTempFlt;       /* '<S502>/Signal Conversion3' */
  boolean vild_b_mhgvUndVoltFlt;       /* '<S502>/Signal Conversion4' */
  boolean vild_b_mhgvInitSts;          /* '<S502>/Signal Conversion5' */
  boolean vild_b_mhgvCcwFlg;           /* '<S502>/Signal Conversion6' */
  boolean vild_b_mhgvMotSts;           /* '<S502>/Signal Conversion8' */
  boolean vild_b_fwfvRespErr;          /* '<S502>/Signal Conversion7' */
  boolean vild_b_fwfvOvrVoltFlt;       /* '<S502>/Signal Conversion10' */
  boolean vild_b_fwfvOvrCurrFlt;       /* '<S502>/Signal Conversion11' */
  boolean vild_b_fwfvOvrTempFlt;       /* '<S502>/Signal Conversion12' */
  boolean vild_b_fwfvUndVoltFlt;       /* '<S502>/Signal Conversion13' */
  boolean vild_b_fwfvInitSts;          /* '<S502>/Signal Conversion14' */
  boolean vild_b_fwfvCcwFlg;           /* '<S502>/Signal Conversion15' */
  boolean vild_b_fwfvMotSts;           /* '<S502>/Signal Conversion16' */
  boolean LogicalOperator1;            /* '<S1215>/Logical Operator1' */
  boolean LogicalOperator2;            /* '<S1215>/Logical Operator2' */
  boolean vild_b_ignStsAcc;            /* '<S1180>/Constant_5' */
  boolean vild_b_vscABSActv;           /* '<S1288>/Signal Conversion6' */
  boolean vild_b_vscVehSpdVld;         /* '<S1288>/Signal Conversion11' */
  boolean vild_b_ehbABSFaild;          /* '<S1288>/Signal Conversion34' */
  boolean vild_b_vscEHBAebActv;        /* '<S1288>/SignalConversion154' */
  boolean vild_b_vscEHBPtTrqDecReqActv;/* '<S1288>/SignalConversion155' */
  boolean vild_b_vscEHBVlcAvlb;        /* '<S1288>/SignalConversion158' */
  boolean vild_b_vscEHBVlcActv;        /* '<S1288>/SignalConversion159' */
  boolean vild_b_vscEHBVlcPtTrqReqActv;/* '<S1288>/SignalConversion160' */
  boolean vild_b_vscEHBPtTrqIncReqActv;/* '<S1288>/SignalConversion162' */
  boolean vild_b_vscEHBDtcActv;        /* '<S1288>/SignalConversion165' */
  boolean vild_b_pdcStsInfoCtrCsmErr;  /* '<S1288>/Signal Conversion5' */
  boolean vild_b_pdcStsInfoCtrAlvCtrErr;/* '<S1288>/Signal Conversion7' */
  boolean vild_b_obcCCSts;             /* '<S1141>/Logical Operator' */
  boolean vild_b_obcCCStsValid;        /* '<S1141>/Signal Conversion7' */
  boolean RelationalOperator;          /* '<S1179>/Relational Operator' */
  boolean RelationalOperator1;         /* '<S1179>/Relational Operator1' */
  boolean vild_b_csmV2XDchaSw_o;       /* '<S1141>/Signal Conversion25' */
  boolean vild_b_csmV2XDchaSwInvld_b;  /* '<S1141>/Signal Conversion26' */
  boolean vild_st_ipkAlwChgSftCtlSt_f; /* '<S1141>/Signal Conversion4' */
  boolean vild_b_eadMot2ActTqVld;      /* '<S615>/Constant13' */
  boolean vild_b_eadMot2LTBstTqLimVld; /* '<S615>/Constant1' */
  boolean vild_b_eadMot2LTGenTqLimVld; /* '<S615>/Constant3' */
  boolean vild_b_eadMot2STBstTqLimVld; /* '<S615>/Constant9' */
  boolean vild_b_eadMot2STGenTqLimVld; /* '<S615>/Constant2' */
  boolean LogicalOperator;             /* '<S689>/Logical Operator' */
  boolean LogicalOperator2_g;          /* '<S689>/Logical Operator2' */
  boolean vild_b_ipuIsgSpdActSgnInvld; /* '<S615>/Signal Conversion48' */
  boolean vild_b_driverHEVModeReq;     /* '<S326>/Constant_1' */
  boolean vild_b_driverSportModeReq;   /* '<S326>/Constant_3' */
  boolean vild_b_driver4WDModeReq;     /* '<S326>/Constant_4' */
  boolean vild_b_flgFnctnConfgEGSM;    /* '<S326>/Constant_5' */
  boolean vild_b_epbErrSts_i;          /* '<S691>/Signal Conversion9' */
  boolean LogicalOperator1_k;          /* '<S918>/Logical Operator1' */
  boolean LogicalOperator2_b;          /* '<S918>/Logical Operator2' */
  boolean vild_b_eadInv2MainRlyPosClosed;/* '<S703>/Signal Conversion15' */
  boolean vild_b_dcdcMainRlyPosClosed; /* '<S703>/Signal Conversion18' */
  boolean vild_b_hvbMainRlyPosClosed;  /* '<S703>/Signal Conversion34' */
  boolean vild_b_hvbMainRlyNegClosed;  /* '<S703>/Signal Conversion30' */
  boolean vild_b_eadInv2MainRlyNegClosed;/* '<S703>/Signal Conversion19' */
  boolean vild_b_dcdcMainRlyNegClosed; /* '<S703>/Signal Conversion21' */
  boolean vild_b_hvbOBCChrgReq;        /* '<S703>/Constant3' */
  boolean LogicalOperator1_kg;         /* '<S917>/Logical Operator1' */
  boolean LogicalOperator2_n;          /* '<S917>/Logical Operator2' */
  boolean RelationalOperator_g;        /* '<S915>/Relational Operator' */
  boolean RelationalOperator_i;        /* '<S916>/Relational Operator' */
  boolean RelationalOperator1_d;       /* '<S914>/Relational Operator1' */
  boolean RelationalOperator1_a;       /* '<S913>/Relational Operator1' */
  boolean RelationalOperator_o;        /* '<S907>/Relational Operator' */
  boolean RelationalOperator_n;        /* '<S605>/Relational Operator' */
  boolean LogicalOperator1_i;          /* '<S606>/Logical Operator1' */
  boolean LogicalOperator2_e;          /* '<S606>/Logical Operator2' */
  boolean vild_b_dcdcTempAlm;          /* '<S561>/Signal Conversion34' */
  boolean vild_b_dcdcStsAlm;           /* '<S561>/Signal Conversion35' */
  boolean vild_b_Estop;
  boolean vild_b_acuDrvSeatbltBcklSts;
  boolean vild_b_acuDrvSeatbltBcklInvld;
  boolean vild_b_brkPedlPosVld;        /* '<S517>/Signal Conversion27' */
  boolean vild_b_brkPedlStsInVld;      /* '<S517>/Signal Conversion28' */
  boolean LogicalOperator1_e;          /* '<S528>/Logical Operator1' */
  boolean LogicalOperator2_c;          /* '<S528>/Logical Operator2' */
  boolean OutportBufferForvild_b_accPedlP;/* '<S340>/Constant1' */
  boolean UnitDelay_DSTATE_bh;         /* '<S60>/Unit Delay' */
  boolean UnitDelay_DSTATE_ek;         /* '<S62>/Unit Delay' */
  boolean UnitDelay_DSTATE_mt;         /* '<S61>/Unit Delay' */
  boolean UnitDelay_DSTATE_j;          /* '<S64>/Unit Delay' */
  boolean UnitDelay_DSTATE_ass;        /* '<S63>/Unit Delay' */
  boolean UnitDelay_DSTATE_k2;         /* '<S65>/Unit Delay' */
  boolean DelayInput1_DSTATE;          /* '<S126>/Delay Input1' */
  boolean UnitDelay1_DSTATE_g;         /* '<S5>/Unit Delay1' */
  boolean UnitDelay2_DSTATE;           /* '<S5>/Unit Delay2' */
  boolean init_DSTATE;                 /* '<S42>/init' */
  boolean init_DSTATE_k;               /* '<S43>/init' */
  boolean init_DSTATE_g;               /* '<S53>/init' */
  boolean init_DSTATE_gw;              /* '<S55>/init' */
  boolean init_DSTATE_c;               /* '<S293>/init' */
  boolean init_DSTATE_m;               /* '<S311>/init' */
  boolean init_DSTATE_ka;              /* '<S310>/init' */
  boolean DelayInput1_DSTATE_o;        /* '<S308>/Delay Input1' */
  boolean DelayInput1_DSTATE_b;        /* '<S309>/Delay Input1' */
  boolean DelayInput1_DSTATE_m;        /* '<S295>/Delay Input1' */
  boolean init_DSTATE_o;               /* '<S282>/init' */
  boolean UnitDelay_DSTATE_g5;         /* '<S4>/Unit Delay' */
  boolean UnitDelay_DSTATE_d;          /* '<S10>/Unit Delay' */
  boolean init_DSTATE_gy;              /* '<S127>/init' */
  boolean UnitDelay2_DSTATE_l;         /* '<S147>/Unit Delay2' */
  boolean UnitDelay1_DSTATE_i;         /* '<S147>/Unit Delay1' */
  boolean init_DSTATE_a;               /* '<S128>/init' */
  boolean init_DSTATE_cv;              /* '<S129>/init' */
  boolean init_DSTATE_j;               /* '<S162>/init' */
  boolean init_DSTATE_k0;              /* '<S163>/init' */
  boolean DelayInput1_DSTATE_k;        /* '<S183>/Delay Input1' */
  boolean Delay1_DSTATE_k;             /* '<S167>/Delay1' */
  boolean Delay6_DSTATE;               /* '<S167>/Delay6' */
  boolean DelayInput1_DSTATE_l;        /* '<S184>/Delay Input1' */
  boolean UnitDelay_DSTATE_hj;         /* '<S14>/Unit Delay' */
  boolean init_DSTATE_n;               /* '<S164>/init' */
  boolean init_DSTATE_d;               /* '<S165>/init' */
  boolean init_DSTATE_p;               /* '<S161>/init' */
  boolean Delay1_DSTATE_f;             /* '<S188>/Delay1' */
  boolean Delay2_DSTATE;               /* '<S188>/Delay2' */
  boolean Delay3_DSTATE_h;             /* '<S188>/Delay3' */
  boolean Delay4_DSTATE;               /* '<S188>/Delay4' */
  boolean Delay5_DSTATE;               /* '<S188>/Delay5' */
  boolean DelayInput1_DSTATE_e;        /* '<S193>/Delay Input1' */
  boolean DelayInput1_DSTATE_h;        /* '<S194>/Delay Input1' */
  boolean UnitDelay3_DSTATE;           /* '<S206>/Unit Delay3' */
  boolean DelayInput1_DSTATE_hf;       /* '<S195>/Delay Input1' */
  boolean DelayInput1_DSTATE_f;        /* '<S196>/Delay Input1' */
  boolean DelayInput1_DSTATE_lo;       /* '<S197>/Delay Input1' */
  boolean UnitDelay2_DSTATE_i;         /* '<S188>/Unit Delay2' */
  boolean UnitDelay_DSTATE_jf;         /* '<S251>/Unit Delay' */
  boolean UnitDelay1_DSTATE_h;         /* '<S930>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_g2;        /* '<S934>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_k;         /* '<S938>/Unit Delay1' */
  boolean UnitDelay_DSTATE_hx;         /* '<S1181>/Unit Delay' */
  boolean Relay1_Mode;                 /* '<S45>/Relay1' */
  boolean Relay9_Mode;                 /* '<S96>/Relay9' */
  boolean Relay9_Mode_b;               /* '<S86>/Relay9' */
  boolean Relay_Mode;                  /* '<S20>/Relay' */
  boolean Relay2_Mode;                 /* '<S14>/Relay2' */
  boolean Relay_Mode_d;                /* '<S14>/Relay' */
  boolean TmTrig;                      /* '<S938>/RollingAverage' */
  boolean TmTrig_b;                    /* '<S934>/RollingAverage' */
  boolean TmTrig_m;                    /* '<S930>/RollingAverage' */
  boolean debounce_MODE;               /* '<S65>/debounce' */
  boolean debounce_MODE_l;             /* '<S64>/debounce' */
  boolean debounce_MODE_le;            /* '<S63>/debounce' */
  boolean debounce_MODE_li;            /* '<S62>/debounce' */
  boolean debounce_MODE_j;             /* '<S61>/debounce' */
  boolean debounce_MODE_e;             /* '<S60>/debounce' */
  boolean debounce_MODE_n;             /* '<S1181>/debounce' */
} ARID_DEF_swc_VCIP_T;

/* Invariant block signals for system '<S10>/SR_latch1' */
typedef struct {
  const boolean LogicalOperator1;      /* '<S110>/Logical Operator1' */
} ConstB_SR_latch_swc_VCIP_m_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float32 DataTypeConversion2;   /* '<S310>/Data Type Conversion2' */
  const float32 DataTypeConversion2_d; /* '<S311>/Data Type Conversion2' */
  const float32 Road_Angle_deg;        /* '<S302>/Product1' */
  const float32 t_delay_off;           /* '<S306>/Saturation1' */
  const float32 Product1;              /* '<S12>/Product1' */
  const float32 Constant;              /* '<S340>/Constant' */
  const float32 Constant2;             /* '<S340>/Constant2' */
  const float32 Constant3;             /* '<S340>/Constant3' */
  const uint16 type_conv;              /* '<S693>/type_conv' */
  const uint8 DataTypeConversion;      /* '<S137>/Data Type Conversion' */
  const uint8 Saturation1;             /* '<S137>/Saturation1' */
  const uint8 Switch3;                 /* '<S923>/Switch3' */
  const uint8 Switch2;                 /* '<S923>/Switch2' */
  const uint8 Switch1;                 /* '<S923>/Switch1' */
  const uint8 Switch6;                 /* '<S923>/Switch6' */
  const uint8 type_conv_l;             /* '<S1256>/type_conv' */
  const uint8 Switch3_b;               /* '<S611>/Switch3' */
  const uint8 Switch2_f;               /* '<S611>/Switch2' */
  const uint8 Switch1_b;               /* '<S611>/Switch1' */
  const uint8 Switch6_d;               /* '<S611>/Switch6' */
  const uint8 Switch5;                 /* '<S611>/Switch5' */
  const uint8 type_conv_f;             /* '<S613>/type_conv' */
  const uint8 type_conv_fi;            /* '<S695>/type_conv' */
  const uint8 type_conv_c;             /* '<S696>/type_conv' */
  const uint8 type_conv_p;             /* '<S697>/type_conv' */
  const uint8 type_conv_k;             /* '<S694>/type_conv' */
  const uint8 type_conv_h;             /* '<S699>/type_conv' */
  const uint8 type_conv_a;             /* '<S700>/type_conv' */
  const uint8 vild_st_srsCrashSts;     /* '<S323>/Constant3' */
  const boolean RelationalOperator;    /* '<S137>/Relational Operator' */
  const boolean hvbd_b_hcmRlyWldFlt;   /* '<S14>/Constant4' */
  const boolean RelationalOperator7;   /* '<S923>/Relational Operator7' */
  const boolean RelationalOperator1;   /* '<S923>/Relational Operator1' */
  const boolean LogicalOperator;       /* '<S923>/Logical Operator' */
  const boolean RelationalOperator3;   /* '<S923>/Relational Operator3' */
  const boolean RelationalOperator2;   /* '<S923>/Relational Operator2' */
  const boolean LogicalOperator1;      /* '<S923>/Logical Operator1' */
  const boolean RelationalOperator5;   /* '<S923>/Relational Operator5' */
  const boolean RelationalOperator4;   /* '<S923>/Relational Operator4' */
  const boolean LogicalOperator2;      /* '<S923>/Logical Operator2' */
  const boolean RelationalOperator8;   /* '<S923>/Relational Operator8' */
  const boolean RelationalOperator6;   /* '<S923>/Relational Operator6' */
  const boolean LogicalOperator3;      /* '<S923>/Logical Operator3' */
  const boolean RelationalOperator10;  /* '<S923>/Relational Operator10' */
  const boolean RelationalOperator9;   /* '<S923>/Relational Operator9' */
  const boolean LogicalOperator4;      /* '<S923>/Logical Operator4' */
  const boolean LogicalOperator_g;     /* '<S1215>/Logical Operator' */
  const boolean vild_b_ignStsAcc;      /* '<S1180>/Constant_5' */
  const boolean Constant4;             /* '<S1141>/Constant4' */
  const boolean vild_b_eadMot2ActTqVld;/* '<S615>/Constant13' */
  const boolean vild_b_eadMot2LTBstTqLimVld;/* '<S615>/Constant1' */
  const boolean vild_b_eadMot2LTGenTqLimVld;/* '<S615>/Constant3' */
  const boolean vild_b_eadMot2STBstTqLimVld;/* '<S615>/Constant9' */
  const boolean vild_b_eadMot2STGenTqLimVld;/* '<S615>/Constant2' */
  const boolean LogicalOperator1_d;    /* '<S689>/Logical Operator1' */
  const boolean RelationalOperator_j;  /* '<S611>/Relational Operator' */
  const boolean RelationalOperator1_h; /* '<S611>/Relational Operator1' */
  const boolean RelationalOperator4_k; /* '<S611>/Relational Operator4' */
  const boolean RelationalOperator5_k; /* '<S611>/Relational Operator5' */
  const boolean RelationalOperator6_o; /* '<S611>/Relational Operator6' */
  const boolean LogicalOperator_k;     /* '<S1043>/Logical Operator' */
  const boolean LogicalOperator_d;     /* '<S918>/Logical Operator' */
  const boolean LogicalOperator_m;     /* '<S917>/Logical Operator' */
  const boolean vild_b_engDoorStatus;  /* '<S323>/Constant1' */
  const boolean vild_b_airbagActive;   /* '<S323>/Constant4' */
  const boolean Constant2_i;           /* '<S517>/Constant2' */
  const boolean Constant1;             /* '<S340>/Constant1' */
  const CanDataStatus Constant_h;      /* '<S1176>/Constant' */
  ConstB_SR_latch_swc_VCIP_m_T SR_latch1_i;/* '<S4>/SR_latch1' */
  ConstB_SR_latch_swc_VCIP_m_T SR_latch1_a;/* '<S10>/SR_latch1' */
} ConstB_swc_VCIP_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_VCIP_T swc_VCIP_ARID_DEF;
extern const ConstB_swc_VCIP_T swc_VCIP_ConstB;/* constant block i/o */

/* Exported data declaration */
#define swc_VCIP_START_SEC_CONST_VOLATILE
#include "swc_VCIP_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile FaultStatus HVB_FAULTSTATUS[4];/* Referenced by: '<S14>/Constant2' */

/* HVB Fault Status mapping */
extern const volatile FaultStatus accc_e_faultStatusDflt;/* Referenced by: '<S4>/Constant13' */

/* A/C Fault Status default value */
extern const volatile float32 accc_pct_HVILReturnPWMHiThd;/* Referenced by: '<S4>/Constant10' */

/* HVILReturnPWM high threshold */
extern const volatile float32 accc_pct_HVILReturnPWMLoThd;/* Referenced by: '<S4>/Constant11' */

/* HVILReturnPWM low threshold */
extern const volatile boolean acpc_b_accPed1Vld_ovrdflg;
                        /* Referenced by: '<S37>/vilc_b_b_accPed1Vld_ovrdflg' */

/* Override flag for signal acpd_b_acp1Sho2GndSet */
extern const volatile boolean acpc_b_accPed1Vld_ovrdval;
                       /* Referenced by: '<S37>/vilc_st_b_accPed1Vld_ovrdval' */

/* Override value for signal acpd_b_acp1Sho2GndSet */
extern const volatile boolean acpc_b_accPed2Vld_ovrdflg;
                          /* Referenced by: '<S38>/vilc_b_accPed2Vld_ovrdflg' */

/* Override flag for signal acpd_b_acp1Sho2GndSet */
extern const volatile boolean acpc_b_accPed2Vld_ovrdval;
                          /* Referenced by: '<S38>/vilc_b_accPed2Vld_ovrdval' */

/* Override value for signal acpd_b_acp1Sho2GndSet */
extern const volatile boolean acpc_b_accPedlPosOvrd;/* Referenced by: '<S34>/Constant2' */

/* Override Accel Pedal Position */
extern const volatile boolean acpc_b_useAccPedPosFromCAN;/* Referenced by:
                                                          * '<S5>/Constant4'
                                                          * '<S33>/Constant4'
                                                          */

/* Use Accel Pedal Position from CAN */
extern const volatile boolean acpc_b_useBrkStsChk;/* Referenced by: '<S45>/Constant4' */

/* Enable brake status check for Pedals Overlap Detection */
extern const volatile boolean acpc_b_usePedlPosFilt;/* Referenced by:
                                                     * '<S32>/Constant1'
                                                     * '<S32>/Constant14'
                                                     */

/* Enable Accel Pedal Position Filter */
extern const volatile boolean acpc_b_useSens1LinearConv;/* Referenced by: '<S51>/Constant2' */

/* Enable Accel Pedal Sensor 1 signal linear conversion */
extern const volatile boolean acpc_b_useSens2LinearConv;/* Referenced by: '<S52>/Constant2' */

/* Enable Accel Pedal Sensor 2 signal linear conversion */
extern const volatile float32 acpc_fact_accPedlPosSens1Gain;/* Referenced by: '<S51>/Constant1' */

/* Accel Pedal Sensor 1 signal gain */
extern const volatile float32 acpc_fact_accPedlPosSens2Gain;/* Referenced by: '<S52>/Constant1' */

/* Accel Pedal Sensor 2 signal gain */
extern const volatile float32 acpc_tm_accPedSens2Filt_s;/* Referenced by: '<S52>/Constant3' */

/* Filter time constant for Accel Pedal Sensor 2 signal */
extern const volatile float32 acpc_tm_accPedlPosFilt_s;/* Referenced by:
                                                        * '<S40>/Constant1'
                                                        * '<S41>/Constant1'
                                                        */

/* Accel Pedal Position Filter time constant */
extern const volatile float32 acpc_tm_accPedlPosSens1Filt_s;/* Referenced by: '<S51>/Constant3' */

/* Filter time constant for Accel Pedal Sensor 1 signal */
extern const volatile float32 acpc_u_accPedlPosSens1MaxVolt_V;/* Referenced by: '<S51>/Constant14' */

/* Max voltage limit for Accel Pedal Sensor 1 signal */
extern const volatile float32 acpc_u_accPedlPosSens1MinVolt_V;/* Referenced by: '<S51>/Constant4' */

/* Min voltage limit for Accel Pedal Sensor 1 signal */
extern const volatile float32 acpc_u_accPedlPosSens2MaxVolt_V;/* Referenced by: '<S52>/Constant14' */

/* Max voltage limit for Accel Pedal Sensor 2 signal */
extern const volatile float32 acpc_u_accPedlPosSens2MinVolt_V;/* Referenced by: '<S52>/Constant4' */

/* Min voltage limit for Accel Pedal Sensor 2 signal */
extern const volatile float32 acpc_v_vehHiThdPedlOverlap_kph;/* Referenced by: '<S45>/Relay1' */

/* Vehicle speed high threshold for Pedals Overlap Detection */
extern const volatile float32 acpc_v_vehLoThdPedlOverlap_kph;/* Referenced by: '<S45>/Relay1' */

/* Vehicle speed low threshold for Pedals Overlap Detection */
extern const volatile float32 acpc_x_accPedlPosDft_pct;/* Referenced by: '<S34>/Constant3' */

/* Accel Pedal Position Override Value */
extern const volatile float32 acpc_x_accPedlPosMax_pct;/* Referenced by: '<S34>/Constant14' */

/* Accel Pedal Position Max */
extern const volatile float32 acpc_x_accPedlPosMin_pct;/* Referenced by: '<S34>/Constant1' */

/* Accel Pedal Position Min */
extern const volatile float32 acpf_accPedlPosSens1_X_Volt_V[4];
                                   /* Referenced by: '<S51>/1-D Lookup Table' */

/* Accel Pedal Sensor 1 Map - Voltage Axis */
extern const volatile float32 acpf_accPedlPosSens1_Y_pct[4];
                                   /* Referenced by: '<S51>/1-D Lookup Table' */

/* Accel Pedal Sensor 1 Map - Pedal Position */
extern const volatile float32 acpf_accPedlPosSens2_X_Volt_V[4];
                                   /* Referenced by: '<S52>/1-D Lookup Table' */

/* Accel Pedal Sensor 2 Map - Voltage Axis */
extern const volatile float32 acpf_accPedlPosSens2_Y_pct[4];
                                   /* Referenced by: '<S52>/1-D Lookup Table' */

/* Accel Pedal Sensor 2 Map - Pedal Position */
extern const volatile boolean brpc_b_calcBrkStsFromPedlPos;/* Referenced by: '<S86>/Constant3' */

/* Calculate Brake Status from Brake Pedal Position */
extern const volatile boolean brpc_b_hasBrkPedPosSignal;/* Referenced by: '<S96>/Constant3' */

/* Determine whether there is brake pedal position signal */
extern const volatile boolean brpc_b_invertBrkSwitch1;/* Referenced by: '<S96>/Constant2' */

/* Invert Brake Switch 1 */
extern const volatile boolean brpc_b_invertBrkSwitch2;/* Referenced by: '<S96>/Constant1' */

/* Invert Brake Switch 2 */
extern const volatile boolean brpc_b_use2BrkSwt;/* Referenced by: '<S96>/Constant4' */

/* Use 2 brake switches for brake pressed detection */
extern const volatile boolean brpc_b_useBrkStatusFromCAN;/* Referenced by: '<S7>/Constant2' */

/* Use Brake Status from CAN */
extern const volatile BrakePedalStatus brpc_e_brkStatusDflt;/* Referenced by: '<S86>/Constant1' */

/* Brake Pedal Status default value */
extern const volatile float32 brpc_tm_brkSwitch1DebOFF_s;/* Referenced by:
                                                          * '<S95>/Constant5'
                                                          * '<S95>/Constant6'
                                                          */

/* Brake Switch 1 OFF debounce time */
extern const volatile float32 brpc_tm_brkSwitch1DebON_s;/* Referenced by:
                                                         * '<S95>/Constant2'
                                                         * '<S95>/Constant4'
                                                         */

/* Brake Switch 1 ON debounce time */
extern const volatile float32 brpc_x_brkPedlPrsdHiThd_pct;/* Referenced by:
                                                           * '<S86>/Relay9'
                                                           * '<S96>/Relay9'
                                                           */

/* Brake Pedal Position high threshold for Brake Pressed detection */
extern const volatile float32 brpc_x_brkPedlPrsdLoThd_pct;/* Referenced by:
                                                           * '<S86>/Relay9'
                                                           * '<S96>/Relay9'
                                                           */

/* Brake Pedal Position low threshold for Brake Pressed detection */
extern const volatile float32 brpf_AirPres_Y_Kpa[11];
                                   /* Referenced by: '<S7>/1-D Lookup Table1' */

/* Brake vacuum sensor characteristics - pressure */
extern const volatile uint16 brpf_Elevation_X_m[11];
                                   /* Referenced by: '<S7>/1-D Lookup Table1' */

/* Elevation */
extern const volatile float32 brpf_brkVacuumSens_X_V[6];
                                  /* Referenced by: '<S82>/1-D Lookup Table1' */

/* Brake vacuum sensor characteristics - voltage axis */
extern const volatile float32 brpf_brkVacuumSens_Y_Kpa[6];
                                  /* Referenced by: '<S82>/1-D Lookup Table1' */

/* Brake vacuum sensor characteristics - pressure */
extern const volatile uint8 cesc_st_acCrashSts;/* Referenced by:
                                                * '<S9>/Constant128'
                                                * '<S9>/Constant3'
                                                */

/* Crash Status to indicate crash */
extern const volatile uint8 cesc_st_acCrashSts1;/* Referenced by:
                                                 * '<S9>/Constant5'
                                                 * '<S9>/Constant7'
                                                 */

/* Crash Status to indicate crash */
extern const volatile uint8 cesc_st_acCrashSts2;/* Referenced by:
                                                 * '<S9>/Constant10'
                                                 * '<S9>/Constant8'
                                                 */

/* Crash Status to indicate crash */
extern const volatile uint8 cesc_st_acCrashSts3;/* Referenced by:
                                                 * '<S9>/Constant11'
                                                 * '<S9>/Constant9'
                                                 */

/* Crash Status to indicate crash */
extern const volatile boolean dccc_b_use12vDcdcModAct;/* Referenced by: '<S10>/Constant' */

/* Use Gear Lever position from CAN */
extern const volatile DCDCMode dccc_e_dcdcActModeDflt;/* Referenced by: '<S112>/Constant1' */

/* DC/DC Actual Mode default value */
extern const volatile FaultStatus dccc_e_faultStatusDflt;/* Referenced by: '<S10>/Constant3' */

/* DC/DC Fault Status default value */
extern const volatile float32 dccc_pct_HVILReturnPWMHiThd;/* Referenced by: '<S10>/Constant10' */

/* HVILReturnPWM high threshold */
extern const volatile float32 dccc_pct_HVILReturnPWMLoThd;/* Referenced by: '<S10>/Constant11' */

/* HVILReturnPWM low threshold */
extern const volatile boolean ddic_b_evtFaildBMSMsgErr_ovrdflg;
                    /* Referenced by: '<S105>/vilc_b_ACCPedalCrossNP_ovrdflg' */

/* Override flag for DFC_HYB_BMSMsgErr */
extern const volatile boolean ddic_b_evtFaildBMSMsgErr_ovrdval;
                    /* Referenced by: '<S105>/vilc_b_ACCPedalCrossNP_ovrdval' */

/* Override value for DFC_HYB_BMSMsgErr */
extern const volatile GearLeverPos dric_e_gearLvrPosDft;/* Referenced by:
                                                         * '<S11>/Constant1'
                                                         * '<S11>/Constant2'
                                                         */

/* Gear Lever Position default value */
extern const volatile boolean eadc_b_ead2MotSpdVldDisable;/* Referenced by: '<S130>/Constant1' */

/* Flag to disable EAD2 speed validity */
extern const volatile boolean eadc_b_enaMot2TqQuadSwap;/* Referenced by: '<S132>/Constant11' */

/* Enable Secondary EAD torque quadrants swap */
extern const volatile boolean eadc_b_mot2PosTrqQuadInit;/* Referenced by: '<S132>/Constant14' */

/* Secondary EAD positive torque quadrant initial value */
extern const volatile FaultStatus eadc_e_inv2FltStsDft;/* Referenced by:
                                                        * '<S12>/Constant4'
                                                        * '<S12>/Constant9'
                                                        */

/* Secondary EAD Fault Status default value */
extern const volatile ElMac eadc_e_inv2ModeActDft;/* Referenced by: '<S12>/Constant1' */

/* Secondary EAD Actual Mode default value */
extern const volatile McuSts eadc_e_mcuStatusDflt;/* Referenced by:
                                                   * '<S4>/Constant15'
                                                   * '<S4>/Constant4'
                                                   * '<S7>/Constant15'
                                                   * '<S10>/Constant15'
                                                   * '<S12>/Constant15'
                                                   * '<S14>/Constant19'
                                                   * '<S15>/Constant15'
                                                   */
extern const volatile float32 eadc_fact_mot2GearRat;/* Referenced by: '<S12>/Constant8' */

/* Secondary EAD gear ratio */
extern const volatile float32 eadc_n_mot2SwapQuadHiThr_rpm;/* Referenced by: '<S132>/Constant8' */

/* Secondary EAD high speed threshold for torque quadrants swap */
extern const volatile float32 eadc_n_mot2SwapQuadLoThr_rpm;/* Referenced by: '<S132>/Constant13' */

/* Secondary EAD low speed threshold for torque quadrants swap */
extern const volatile float32 eadc_tm_mot21ActPwrFilt_s;/* Referenced by: '<S12>/Constant10' */

/* Secondary EAD21 Actual Power Filter time constant */
extern const volatile float32 eadc_tm_mot2ActPwrFilt_s;/* Referenced by: '<S12>/Constant5' */

/* Secondary EAD Actual Power Filter time constant */
extern const volatile float32 eadc_tm_mot2ActSpdFilt_s;/* Referenced by: '<S12>/Constant17' */

/* Secondary EAD Actual Speed Filter time constant */
extern const volatile ParkingStatus epbc_e_parkStatusDflt;/* Referenced by: '<S13>/Constant2' */

/* EPB Parking Status default value */
extern const volatile boolean hvbc_b_UseHiPrecsnSOC;/* Referenced by: '<S703>/Constant15' */

/* Enable Flag for Use High Precision SOC */
extern const volatile boolean hvbc_b_wrkChgModMergeEn;/* Referenced by:
                                                       * '<S905>/Constant2'
                                                       * '<S905>/Constant6'
                                                       */

/* Enable merge BMS work mode and act mode */
extern const volatile FaultStatus hvbc_e_faultStatusDflt;/* Referenced by: '<S14>/Constant3' */

/* HVB Fault Status default value */
extern const volatile HVBRelayStatus hvbc_e_hvbRlyStatusDflt;/* Referenced by:
                                                              * '<S14>/Constant10'
                                                              * '<S14>/Constant11'
                                                              * '<S14>/Constant13'
                                                              * '<S14>/Constant15'
                                                              */

/* HVB Relay Status default value */
extern const volatile HVBattStatus hvbc_e_hvbStatusDflt;/* Referenced by: '<S14>/Constant1' */

/* HVB BMS Status default value */
extern const volatile float32 hvbc_fact_acwpHeatPower;/* Referenced by: '<S14>/constant2' */

/* EWP_HeatPower signal gain */
extern const volatile float32 hvbc_pwr_lowChPwrThld_kW;/* Referenced by: '<S14>/Constant35' */

/* HVB Low Charge Power threshold */
extern const volatile float32 hvbc_pwr_lowDischPwrDnThld_kW;/* Referenced by: '<S14>/Constant27' */

/* HVB Low Discharge Power down threshold */
extern const volatile float32 hvbc_pwr_lowDischPwrUpThld_kW;/* Referenced by: '<S14>/Constant28' */

/* HVB Low Discharge Power up threshold */
extern const volatile float32 hvbc_q_hvbSocMinDisIntelChg_pct;/* Referenced by: '<S188>/Constant29' */

/* HVB Minimum SOC in Intelligent Charging */
extern const volatile float32 hvbc_q_hvbSocMinDn_pct;/* Referenced by: '<S14>/Constant34' */

/* HVB Minimum SOC in Low Temp Protection Mode */
extern const volatile float32 hvbc_q_hvbSocMin_pct;/* Referenced by: '<S14>/Constant29' */

/* HVB Minimum SOC in Low Temp Protection Mode */
extern const volatile float32 hvbc_t_IntChgDisDly_s;/* Referenced by: '<S206>/Constant25' */
extern const volatile float32 hvbc_t_hvbLowTempDnThld_C;/* Referenced by: '<S14>/Relay' */

/* HVB Low Temp down threshold */
extern const volatile float32 hvbc_t_hvbLowTempUpThld_C;/* Referenced by:
                                                         * '<S14>/Relay'
                                                         * '<S14>/Unit Delay1'
                                                         */

/* HVB Low Temp up threshold */
extern const volatile float32 hvbc_t_hvbOvrTempDnThld_C;/* Referenced by: '<S14>/Relay2' */

/* HVB Over Temp down threshold */
extern const volatile float32 hvbc_t_hvbOvrTempUpThld_C;/* Referenced by: '<S14>/Relay2' */

/* HVB Over Temp up threshold */
extern const volatile float32 hvbc_tm_Delay_s;/* Referenced by:
                                               * '<S167>/Constant12'
                                               * '<S188>/Constant13'
                                               * '<S188>/Constant14'
                                               * '<S188>/Constant16'
                                               * '<S188>/Constant18'
                                               * '<S188>/Constant20'
                                               * '<S188>/Constant22'
                                               */

/* DCDC Enable delay */
extern const volatile float32 hvbc_tm_EnableDelay_s;/* Referenced by: '<S167>/Constant2' */

/* Enable Subsystem delay */
extern const volatile float32 hvbc_tm_hvbActPwrFilter_s;/* Referenced by: '<S14>/Constant7' */

/* HVB Actual Power Filter time constant */
extern const volatile float32 hvbc_tm_lowTempProtnDiDly_s;/* Referenced by: '<S14>/Constant31' */

/* HVB Low Temp Protection Disable Time Delay */
extern const volatile float32 hvbc_tm_lowTempProtnEnDly_s;/* Referenced by: '<S14>/Constant33' */

/* HVB Low Temp Protection Enable Time Delay */
extern const volatile float32 hvbc_tm_peakChMaxFilter_s;/* Referenced by: '<S14>/Constant25' */

/* HVB peakChMax Power Filter time constant */
extern const volatile float32 hvbc_tm_peakDischMaxFilter_s;/* Referenced by: '<S14>/Constant26' */

/* HVB peakDischMax Power Filter time constant */
extern const volatile float32 hvbc_tm_statChMaxFilter_s;/* Referenced by: '<S14>/Constant17' */

/* HVB statChMax Power Filter time constant */
extern const volatile float32 hvbc_tm_statDischMaxFilter_s;/* Referenced by: '<S14>/Constant22' */

/* HVB statDischMax Power Filter time constant */
extern const volatile float32 hvbc_u_batDcdcWorkError_V;/* Referenced by: '<S206>/Constant2' */
extern const volatile float32 macc_ADCCANBusofffail_s;/* Referenced by: '<S6>/Constant17' */

/* macc_EVCANBusofffail_s fault set threshold */
extern const volatile float32 macc_ADCCANBusoffheal_s;/* Referenced by: '<S6>/Constant18' */

/* macc_EVCANBusoffheal_s fault clear threshold */
extern const volatile float32 macc_ADCMsgErr2fail_s;/* Referenced by: '<S6>/Constant21' */

/* macc_ABSMsgErr2fail_s fault set threshold */
extern const volatile float32 macc_ADCMsgErr2heal_s;/* Referenced by:
                                                     * '<S6>/Constant22'
                                                     * '<S6>/Constant25'
                                                     * '<S6>/Constant26'
                                                     * '<S6>/Constant29'
                                                     * '<S6>/Constant30'
                                                     * '<S6>/Constant33'
                                                     * '<S6>/Constant34'
                                                     */

/* macc_ABSMsgErr2heal_s fault clear threshold */
extern const volatile float32 macc_PMSCANBusofffail_s;/* Referenced by: '<S6>/Constant3' */

/* macc_EVCANBusofffail_s fault set threshold */
extern const volatile float32 macc_PMSCANBusoffheal_s;/* Referenced by: '<S6>/Constant9' */

/* macc_EVCANBusoffheal_s fault clear threshold */
extern const volatile boolean macc_b_CPSelfCheckSts_ovrdflg;
                     /* Referenced by: '<S242>/macc_b_CPSelfCheckSts_ovrdflg' */

/* Override flag for signal CPSelfCheckSts */
extern const volatile float32 macc_fact_5VT1Gain;/* Referenced by: '<S15>/constant2' */

/* EXT_AO_TRACKING_5V_01 signal gain */
extern const volatile float32 macc_fact_5VT2Gain;/* Referenced by: '<S15>/constant3' */

/* EXT_AO_TRACKING_5V_02 signal gain */
extern const volatile float32 macc_fact_batIntSmplGain;/* Referenced by: '<S15>/constant1' */

/* Bat_Internal_Sample signal gain */
extern const volatile uint8 macc_st_CPSelfCheckSts_ovrdval;
                    /* Referenced by: '<S242>/macc_st_CPSelfCheckSts_ovrdval' */

/* Override value for signal CPSelfCheckSts */
extern const volatile boolean obcc_b_disableObcWkUpChk;/* Referenced by: '<S16>/Constant2' */

/* Disable OBC wakeup signal check for charger plugged */
extern const volatile float32 obcc_tm_dlyForObcWakeUp_s;/* Referenced by: '<S251>/Constant5' */

/* Delay for OBC wakeup signal */
extern const volatile boolean pmmc_b_useAnyIgnOn;/* Referenced by: '<S260>/Constant7' */
extern const volatile boolean pmmc_b_useCanIgnOn;/* Referenced by:
                                                  * '<S260>/Constant1'
                                                  * '<S260>/Constant3'
                                                  * '<S260>/Constant5'
                                                  */

/* Use CAN Ignition ON */
extern const volatile boolean pmmc_b_useHwIgnOn;/* Referenced by:
                                                 * '<S260>/Constant2'
                                                 * '<S260>/Constant4'
                                                 * '<S260>/Constant6'
                                                 */

/* Use HW Ignition ON */
extern const volatile boolean pmmc_b_usePepsPDULvlFromCan;/* Referenced by: '<S259>/t_step3' */

/* Use PEPS PDULvl from CAN */
extern const volatile PDULevel pmmc_e_pduLvlDft;/* Referenced by: '<S259>/Constant4' */

/* PDU Level default value */
extern const volatile float32 pmmc_tm_hwIgnOffDeb_s;/* Referenced by: '<S259>/t_step2' */

/* HW Ignition OFF debounce time */
extern const volatile float32 pmmc_tm_hwIgnOnDeb_s;/* Referenced by: '<S259>/t_step1' */

/* HW Ignition ON debounce time */
extern const volatile boolean swcvcip_ddic_b_evtFaildMCUMsgErr_ovrdflg;/* Referenced by:
                                                                      * '<S141>/DFC_ovrdflg'
                                                                      * '<S1357>/DFC_ovrdflg'
                                                                      */

/* Override flag for DFC_HYB_MCUMsgErr */
extern const volatile boolean swcvcip_ddic_b_evtFaildMCUMsgErr_ovrdval;/* Referenced by:
                                                                      * '<S141>/DFC_ovrdval'
                                                                      * '<S1357>/DFC_ovrdval'
                                                                      */

/* Override value for DFC_HYB_MCUMsgErr */
extern const volatile float32 swcvcip_hvbc_tm_DcdcAct_s;/* Referenced by: '<S188>/Constant8' */
extern const volatile float32 swcvcip_macc_tm_ignOnDeb_s;/* Referenced by: '<S6>/Constant35' */
extern const volatile float32 swcvcip_vslc_l_whlRad1_m;/* Referenced by:
                                                        * '<S1055>/Constant1'
                                                        * '<S1354>/Constant4'
                                                        */

/* Wheel radius */
extern const volatile float32 swcvcip_vslc_l_whlRad2_m;/* Referenced by:
                                                        * '<S1055>/Constant2'
                                                        * '<S1354>/Constant37'
                                                        */

/* Wheel radius */
extern const volatile float32 swcvcip_vslc_l_whlRad_m;/* Referenced by:
                                                       * '<S130>/Constant37'
                                                       * '<S1055>/Constant'
                                                       * '<S1354>/Constant5'
                                                       */

/* Wheel radius */
extern const volatile ParkingStatus trac_e_trsm1PrkgStsDft;/* Referenced by: '<S277>/Constant8' */

/* Primary Transmission Parking Status Default */
extern const volatile float32 trac_fact_trsm2FinalDrvRat;/* Referenced by:
                                                          * '<S279>/Constant8'
                                                          * '<S1354>/Constant3'
                                                          */

/* Secondary Transmission Final Drive ratio */
extern const volatile float32 trac_fact_trsm2GearRatDecGrad;/* Referenced by: '<S279>/Constant11' */

/* Secondary Transmission gear ratio decrease gradient */
extern const volatile float32 trac_fact_trsm2GearRatIncGrad;/* Referenced by: '<S279>/Constant10' */

/* Secondary Transmission gear ratio increase gradient */
extern const volatile sint8 trac_st_trsm2GearActDft;/* Referenced by: '<S281>/Constant2' */

/* Secondary Transmission Gear default value */
extern const volatile float32 trac_tq_enaGearShftRespThdBrk_Nm;/* Referenced by: '<S280>/Constant4' */

/* Secondary EAD available brake torque threshold to enable gear shift  response */
extern const volatile float32 trac_tq_enaGearShftRespThdBst_Nm;/* Referenced by: '<S280>/Constant2' */

/* Secondary EAD available boost torque threshold to enable gear shift  response */
extern const volatile sint8 traf_trsm2GearRat_X_gearAct[4];
                                  /* Referenced by: '<S279>/1-D Lookup Table' */

/* Secondary Transmission gear ratios Map - Gear Axis */
extern const volatile float32 traf_trsm2GearRat_Y_fact[4];
                                  /* Referenced by: '<S279>/1-D Lookup Table' */

/* Secondary Transmission gear ratios Map - factor */
extern const volatile boolean vcip_b_BMSHealthMonErr_ovrdflg;
                    /* Referenced by: '<S104>/vilc_b_ACCPedalCrossNP_ovrdflg' */
extern const volatile boolean vcip_b_BMSHealthMonErr_ovrdval;
                    /* Referenced by: '<S104>/vilc_b_ACCPedalCrossNP_ovrdval' */
extern const volatile boolean vcip_b_MCUHealthMonErr_ovrdflg;/* Referenced by:
                                                              * '<S142>/DFC_ovrdflg'
                                                              * '<S1358>/DFC_ovrdflg'
                                                              */
extern const volatile boolean vcip_b_MCUHealthMonErr_ovrdval;/* Referenced by:
                                                              * '<S142>/DFC_ovrdval'
                                                              * '<S1358>/DFC_ovrdval'
                                                              */
extern const volatile boolean vcip_b_flgFctCfgDspRemainRng_ovrdflg;
             /* Referenced by: '<S1093>/vcip_b_flgFctCfgDspRemainRng_ovrdflg' */
extern const volatile boolean vcip_cesc_b_ACUMsgErr_ovrdflg;
                    /* Referenced by: '<S103>/vilc_b_ACCPedalCrossNP_ovrdflg' */
extern const volatile boolean vcip_cesc_b_ACUMsgErr_ovrdval;
                    /* Referenced by: '<S103>/vilc_b_ACCPedalCrossNP_ovrdval' */
extern const volatile uint16 vcip_st_flgFctCfgDspRemainRng_ovrdval;
            /* Referenced by: '<S1093>/vcip_st_flgFctCfgDspRemainRng_ovrdval' */
extern const volatile float32 vcip_vscc_tm_pdcCsmAlvCtrErrDly_s;/* Referenced by: '<S20>/Constant14' */
extern const volatile float32 vilc_E_hvbPackRemnEgy_ovrdval;
                     /* Referenced by: '<S754>/vilc_E_hvbPackRemnEgy_ovrdval' */

/* Override value for signal E_hvbPackRemnEgy */
extern const volatile float32 vilc_R_NegInslRes_ovrdval;
                         /* Referenced by: '<S755>/vilc_R_NegInslRes_ovrdval' */

/* Override value for signal R_NegInslRes */
extern const volatile float32 vilc_R_posInslRes_ovrdval;
                         /* Referenced by: '<S756>/vilc_R_posInslRes_ovrdval' */

/* Override value for signal R_posInslRes */
extern const volatile float32 vilc_V_FuelLevelStsLDT_ovrdval;
                   /* Referenced by: '<S1027>/vilc_V_FuelLevelStsLDT_ovrdval' */

/* Override value for LDT fuel level in Liter */
extern const volatile float32 vilc_V_fuelLevelHDTMax_l;
                   /* Referenced by: '<S1024>/vild_fact_FuelLevelHDT_ovrdval' */

/* HDT fuel tank max in Liter */
extern const volatile float32 vilc_a_brkLhtResetdec_mpss;/* Referenced by: '<S20>/Relay' */
extern const volatile float32 vilc_a_brkLhtsetdec_mpss;/* Referenced by: '<S20>/Relay' */
extern const volatile float32 vilc_a_yrsLongitAcce_ovrdval;
                     /* Referenced by: '<S1289>/vilc_a_yrsLongitAcce_ovrdval' */
extern const volatile float32 vilc_ang_strWhlAng_ovrdval;
                       /* Referenced by: '<S1212>/vilc_ang_strWhlAng_ovrdval' */

/* Override value for signal tq_eadMot21ActTq */
extern const volatile boolean vilc_b_24vDcdcFltSts_ovrdflg;
                    /* Referenced by: '<S566>/vilc_flg_24vDcdcFltSts_ovrdflg' */

/* Override flag for signal b_24vDcdcFltSts */
extern const volatile boolean vilc_b_24vDcdcModAct_ovrdflg;
                    /* Referenced by: '<S567>/vilc_flg_24vDcdcModAct_ovrdflg' */

/* Override flag for signal b_24vDcdcModAct */
extern const volatile boolean vilc_b_24vDcdcSelfChk_ovrdflg;
                   /* Referenced by: '<S568>/vilc_flg_24vDcdcSelfChk_ovrdflg' */

/* Override flag for signal b_24vDcdcSelfChk */
extern const volatile boolean vilc_b_24vDcdcSubFltSts_ovrdflg;
                   /* Referenced by: '<S569>/vilc_b_24vDcdcSubFltSts_ovrdflg' */

/* Override flag for signal DCDC_SubFltLevel */
extern const volatile boolean vilc_b_24vDcdcTemp_ovrdflg;
                      /* Referenced by: '<S579>/vilc_flg_24vDcdcTemp_ovrdflg' */

/* Override flag for signal b_24vDcdcTemp */
extern const volatile boolean vilc_b_5VT1IntSmpl_ovrdflg;
                                /* Referenced by: '<S982>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal b_5VT1IntSmpl */
extern const volatile boolean vilc_b_5VT2IntSmpl_ovrdflg;
                                /* Referenced by: '<S983>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal b_5VT2IntSmpl */
extern const volatile boolean vilc_b_ABSPrio_flg;/* Referenced by: '<S1354>/Constant' */
extern const volatile boolean vilc_b_ACCPedalCrossNP_ovrdflg;
                     /* Referenced by: '<S46>/vilc_b_ACCPedalCrossNP_ovrdflg' */
extern const volatile boolean vilc_b_ACCPedalCrossNP_ovrdval;
                     /* Referenced by: '<S46>/vilc_b_ACCPedalCrossNP_ovrdval' */
extern const volatile boolean vilc_b_ACSwtSt_ovrdflg;
                          /* Referenced by: '<S352>/vilc_flg_ACSwtSt_ovrdflg' */

/* Override flag for signal b_ACSwtSt */
extern const volatile boolean vilc_b_Acc1Raw_ovrdflg;
                                /* Referenced by: '<S984>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal Acc1Raw */
extern const volatile boolean vilc_b_Acc1_ovrdflg;
                               /* Referenced by: '<S985>/vilc_b_Acc1_ovrdflg' */

/* Override flag for signal b_Acc1 */
extern const volatile boolean vilc_b_Acc2Raw_ovrdflg;
                                /* Referenced by: '<S986>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal Acc2Raw */
extern const volatile boolean vilc_b_Acc2_ovrdflg;
                               /* Referenced by: '<S987>/vilc_b_Acc2_ovrdflg' */

/* Override flag for signal b_Acc2 */
extern const volatile boolean vilc_b_AccyEnReq_ovrdflg;
                          /* Referenced by: '<S943>/vilc_b_AccyEnReq_ovrdflg' */
extern const volatile boolean vilc_b_AccyEnReq_ovrdval;
                          /* Referenced by: '<S943>/vilc_b_AccyEnReq_ovrdval' */
extern const volatile boolean vilc_b_AccyFltSts_ovrdflg;
                       /* Referenced by: '<S944>/vilc_flg_AccyFltSts_ovrdflg' */
extern const volatile boolean vilc_b_AccyFltSts_ovrdval;
                         /* Referenced by: '<S944>/vilc_b_AccyFltSts_ovrdval' */
extern const volatile boolean vilc_b_AvrgVehSpd_ovrdflg;
                        /* Referenced by: '<S1038>/vilc_b_AvrgVehSpd_ovrdflg' */

/* Override flag for signal IC_AverageVehSpd */
extern const volatile boolean vilc_b_BmsMaxCellVolt_ovrdflg;
                     /* Referenced by: '<S823>/vilc_b_BmsMaxCellVolt_ovrdflg' */

/* Override flag for signal BMS_MaxCellVolt */
extern const volatile boolean vilc_b_BmsMinCellVolt_ovrdflg;
                     /* Referenced by: '<S824>/vilc_b_BmsMinCellVolt_ovrdflg' */

/* Override flag for signal BMS_MinCellVolt */
extern const volatile boolean vilc_b_BmsTempOutOfCtrlFlt_ovrdflg;
                /* Referenced by: '<S777>/vilc_b_BmsTempOutOfCtrlFlt_ovrdflg' */

/* Override flag for signal BMS_TempOutofCtr */
extern const volatile boolean vilc_b_Brk2Raw_ovrdflg;
                                /* Referenced by: '<S990>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal Brk2Raw */
extern const volatile boolean vilc_b_Brk2_ovrdflg;
                                /* Referenced by: '<S989>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal b_Brk */
extern const volatile boolean vilc_b_BrkRaw_ovrdflg;
                                /* Referenced by: '<S991>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal BrkRaw */
extern const volatile boolean vilc_b_BrkSwitch1_invert;
                       /* Referenced by: '<S945>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for b_BrkSwitch1_invert */
extern const volatile boolean vilc_b_BrkSwitch2_invert;
                       /* Referenced by: '<S946>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for signal BrkSwitch2 */
extern const volatile boolean vilc_b_BrkSwitch2_ovrdflg;
                      /* Referenced by: '<S946>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal BrkSwitch2 */
extern const volatile boolean vilc_b_BrkSwitch2_ovrdval;
                      /* Referenced by: '<S946>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal BrkSwitch2 */
extern const volatile boolean vilc_b_BrkSwitch_ovrdflg;
                          /* Referenced by: '<S945>/vilc_b_BrkSwitch_ovrdflg' */

/* Override flag for signal b_BrkSwitch */
extern const volatile boolean vilc_b_BrkSwitch_ovrdval;
                          /* Referenced by: '<S945>/vilc_b_BrkSwitch_ovrdval' */

/* Override value for signal b_BrkSwitch */
extern const volatile boolean vilc_b_Brk_ovrdflg;
                                /* Referenced by: '<S988>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal b_Brk */
extern const volatile boolean vilc_b_CCSginal_invert;
                       /* Referenced by: '<S947>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for signal CCSginal */
extern const volatile boolean vilc_b_CCSginal_ovrdflg;
                      /* Referenced by: '<S947>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal CCSginal */
extern const volatile boolean vilc_b_CCSginal_ovrdval;
                      /* Referenced by: '<S947>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal CCSginal */
extern const volatile boolean vilc_b_DryAirSwitch_invert;
                        /* Referenced by: '<S948>/vilc_b_DryAirSwitch_invert' */

/* Invert flag for signal b_DryAirSwitch */
extern const volatile boolean vilc_b_DryAirSwitch_ovrdflg;
                       /* Referenced by: '<S948>/vilc_b_DryAirSwitch_ovrdflg' */

/* Override flag for signal b_DryAirSwitch */
extern const volatile boolean vilc_b_DryAirSwitch_ovrdval;
                       /* Referenced by: '<S948>/vilc_b_DryAirSwitch_ovrdval' */

/* Override value for signal b_DryAirSwitch */
extern const volatile boolean vilc_b_FuelLevelStsLDT_ovrdflg;
                   /* Referenced by: '<S1027>/vilc_V_FuelLevelStsLDT_ovrdflg' */

/* Override flag for LDT fuel level */
extern const volatile boolean vilc_b_GearPosnSt_ovrdflg;
                         /* Referenced by: '<S977>/vilc_b_GearPosnSt_ovrdflg' */

/* Override flag for signal GearPosn */
extern const volatile boolean vilc_b_GearPosn_ovrdflg;
                                /* Referenced by: '<S968>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal GearPosn */
extern const volatile boolean vilc_b_HVILReturnPWM_ovrdflg;
                      /* Referenced by: '<S969>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal pct_HVILReturnPWM */
extern const volatile boolean vilc_b_HandBrk_ovrdflg;
                            /* Referenced by: '<S992>/vilc_b_HandBrk_ovrdflg' */

/* Override flag for signal b_HandBrk */
extern const volatile boolean vilc_b_HybridCanBusOff_ovrdflg;
                    /* Referenced by: '<S949>/vilc_b_HybridCanBusOff_ovrdflg' */

/* Override flag for signal BSW_HybridCanBusOff */
extern const volatile boolean vilc_b_HybridCanBusOff_ovrdval;
                    /* Referenced by: '<S949>/vilc_b_HybridCanBusOff_ovrdval' */

/* Override value for signal BSW_HybridCanBusOff */
extern const volatile boolean vilc_b_McaCalNum_ovrdflg;
                         /* Referenced by: '<S1240>/vilc_b_McaCalNum_ovrdflg' */

/* Override flag for signal MCA_CalNum */
extern const volatile boolean vilc_b_McaOvrLoadInd_ovrdflg;
                     /* Referenced by: '<S1241>/vilc_b_McaOvrLoadInd_ovrdflg' */

/* Override flag for signal MCA_OverloadInd */
extern const volatile boolean vilc_b_McaVehWeight_ovrdflg;
                      /* Referenced by: '<S1237>/vilc_b_McaVehWeight_ovrdflg' */

/* Override flag for signal MCA_VehicleWeight */
extern const volatile boolean vilc_b_NegInslRes_ovrdflg;
                       /* Referenced by: '<S755>/vilc_flg_NegInslRes_ovrdflg' */

/* Override flag for signal b_NegInslRes */
extern const volatile boolean vilc_b_PTCActPwr_ovrdflg;
                       /* Referenced by: '<S346>/vilc_flg_airCmprAct_ovrdflg' */

/* Override flag for signal PTCActPwr */
extern const volatile boolean vilc_b_PTCSt_ovrdflg;
                        /* Referenced by: '<S353>/vilc_flg_airCmprSt_ovrdflg' */

/* Override flag for signal PTCStatus */
extern const volatile boolean vilc_b_PtcWrkSts_ovrdflg;
                          /* Referenced by: '<S354>/vilc_b_PtcWrkSts_ovrdflg' */

/* Override flag for signal PTC_WorkSts */
extern const volatile boolean vilc_b_ResrAirSwitch_invert;
                       /* Referenced by: '<S950>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for signal b_ResrAirSwitch */
extern const volatile boolean vilc_b_ResrAirSwitch_ovrdflg;
                      /* Referenced by: '<S950>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal b_ResrAirSwitch */
extern const volatile boolean vilc_b_ResrAirSwitch_ovrdval;
                      /* Referenced by: '<S950>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal b_ResrAirSwitch */
extern const volatile boolean vilc_b_TBOXFunAntiDismantleActive_ovrdflg;
        /* Referenced by: '<S1242>/vilc_b_TBOXFunAntiDismantleActive_ovrdflg' */

/* Override flag for signal b_TBOXFunAntiDismantleActive */
extern const volatile boolean vilc_b_TBOXFunLockVehActive_ovrdflg;
              /* Referenced by: '<S1243>/vilc_b_TBOXFunLockVehActive_ovrdflg' */

/* Override flag for signal b_TBOXFunLockVehActive */
extern const volatile boolean vilc_b_TBOXLockLimSet_ovrdflg;
                    /* Referenced by: '<S1244>/vilc_b_TBOXLockLimSet_ovrdflg' */

/* Override flag for signal b_TBOXLockLimSet */
extern const volatile boolean vilc_b_TBOXLockResultResp_ovrdflg;
                /* Referenced by: '<S1245>/vilc_b_TBOXLockResultResp_ovrdflg' */

/* Override flag for signal b_TBOXLockResultResp */
extern const volatile boolean vilc_b_TBOXLockVehCtrl_ovrdflg;
                   /* Referenced by: '<S1246>/vilc_b_TBOXLockVehCtrl_ovrdflg' */

/* Override flag for signal b_TBOXLockVehCtrl */
extern const volatile boolean vilc_b_TBOXLockVehType_ovrdflg;
                   /* Referenced by: '<S1247>/vilc_b_TBOXLockVehType_ovrdflg' */

/* Override flag for signal b_TBOXLockVehType */
extern const volatile boolean vilc_b_TS5sensorFb_ovrdflg;
                        /* Referenced by: '<S979>/vilc_b_TS5sensorFb_ovrdflg' */

/* Override flag for signal b_TS5sensorFb */
extern const volatile boolean vilc_b_TS5sensorVoltFb_ovrdflg;
                                /* Referenced by: '<S993>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal TS5sensorFb */
extern const volatile boolean vilc_b_VacTkAirPres_ovrdflg;
                                /* Referenced by: '<S994>/vilc_b_Brk_ovrdflg' */
extern const volatile boolean vilc_b_VacTkEnFb_ovrdflg;
                          /* Referenced by: '<S995>/vilc_b_VacTkEnFb_ovrdflg' */
extern const volatile boolean vilc_b_WatPmpEP1FbPWM_ovrdflg;
                     /* Referenced by: '<S970>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal b_WatPmpEP1FbPWM */
extern const volatile boolean vilc_b_WatPmpEP2FbPWM_ovrdflg;
                     /* Referenced by: '<S971>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal b_WatPmpEP2FbPWM */
extern const volatile boolean vilc_b_WatPmpEP3FbPWM_ovrdflg;
                     /* Referenced by: '<S972>/vilc_b_WatPmpEP3FbPWM_ovrdflg' */

/* Override flag for signal b_WatPmpEP3FbPWM */
extern const volatile boolean vilc_b_acAmbTempInvalid_invert;
                    /* Referenced by: '<S344>/vilc_b_acAmbTempInvalid_invert' */

/* Invert flag for signal AC_AmbientTemperatureInvalid */
extern const volatile boolean vilc_b_acAmbTempInvalid_ovrdflg;
                   /* Referenced by: '<S344>/vilc_b_acAmbTempInvalid_ovrdflg' */

/* Override flag for signal AC_AmbientTemperatureInvalid */
extern const volatile boolean vilc_b_acAmbTempInvalid_ovrdval;
                   /* Referenced by: '<S344>/vilc_b_acAmbTempInvalid_ovrdval' */

/* Override value for signal AC_AmbientTemperatureInvalid */
extern const volatile boolean vilc_b_acFanReqSpd_ovrdflg;
                        /* Referenced by: '<S345>/vilc_b_acFanReqSpd_ovrdflg' */
extern const volatile boolean vilc_b_acFltLvl_ovrdflg;
                           /* Referenced by: '<S355>/vilc_b_acFltLvl_ovrdflg' */

/* Override flag for signal AC_SysFaultLevel */
extern const volatile boolean vilc_b_acHvilPrdInpt_ovrdflg;
                    /* Referenced by: '<S965>/vilc_flg_acHvilPrdInpt_ovrdflg' */
extern const volatile boolean vilc_b_acPresVolt_ovrdflg;
                       /* Referenced by: '<S343>/vilc_flg_acPresVolt_ovrdflg' */

/* Override flag for signal acPresVolt */
extern const volatile boolean vilc_b_acSubFltSts_ovrdflg;
                        /* Referenced by: '<S356>/vilc_b_acSubFltSts_ovrdflg' */

/* Override flag for signal AC_SubSysFaultLevel */
extern const volatile boolean vilc_b_accm1ActPwr_ovrdflg;
                      /* Referenced by: '<S347>/vilc_flg_accm1ActPwr_ovrdflg' */
extern const volatile boolean vilc_b_acuCrashOutStsC_ovrdflg;
                    /* Referenced by: '<S534>/vilc_b_acuCrashOutStsC_ovrdflg' */

/* Override flag for signal ACU_CrashOutputStatus from C Can */
extern const volatile boolean vilc_b_acuCrashOutStsPT_ovrdflg;
                   /* Referenced by: '<S535>/vilc_b_acuCrashOutStsPT_ovrdflg' */

/* Override flag for signal ACU_CrashOutputStatus from PT Can */
extern const volatile boolean vilc_b_acuCrashStsInvalid_ovrdflg;
                 /* Referenced by: '<S536>/vilc_b_acuCrashStsInvalid_ovrdflg' */

/* Override flag for signal ACU_CrashStatusInvalid */
extern const volatile boolean vilc_b_acuDrvSeatbltBcklInvld_ovrdflg;
           /* Referenced by: '<S532>/vilc_flg_acuDrvSeatbltBcklInvld_ovrdflg' */
extern const volatile boolean vilc_b_acuDrvSeatbltBcklInvld_ovrdval;
             /* Referenced by: '<S532>/vilc_b_acuDrvSeatbltBcklInvld_ovrdval' */
extern const volatile boolean vilc_b_acuDrvSeatbltBcklSts_ovrdflg;
             /* Referenced by: '<S533>/vilc_flg_acuDrvSeatbltBcklSts_ovrdflg' */
extern const volatile boolean vilc_b_acuDrvSeatbltBcklSts_ovrdval;
               /* Referenced by: '<S533>/vilc_b_acuDrvSeatbltBcklSts_ovrdval' */
extern const volatile boolean vilc_b_acuWarnLampSts_ovrdflg;
                     /* Referenced by: '<S537>/vilc_b_acuWarnLampSts_ovrdflg' */

/* Override flag for signal ACU_WarningLampStatus */
extern const volatile boolean vilc_b_acwpHeatPower_ovrdflg;
                      /* Referenced by: '<S348>/vilc_b_acwpHeatPower_ovrdflg' */

/* Override flag for signal EWP_HeatPower */
extern const volatile boolean vilc_b_acwpOutptTemp_ovrdflg;
                      /* Referenced by: '<S362>/vilc_b_acwpOutptTemp_ovrdflg' */

/* Override flag for signal EWP_OutputTemp */
extern const volatile boolean vilc_b_adc01CtrAlvCtrErrFlg_ovrdflg;
             /* Referenced by: '<S386>/vilc_flg_adc01CtrAlvCtrErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc01CtrAlvCtrErrFlg_ovrdval;
               /* Referenced by: '<S386>/vilc_b_adc01CtrAlvCtrErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc01CtrComRxToutFlg_ovrdflg;
             /* Referenced by: '<S387>/vilc_flg_adc01CtrComRxToutFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc01CtrComRxToutFlg_ovrdval;
               /* Referenced by: '<S387>/vilc_b_adc01CtrComRxToutFlg_ovrdval' */
extern const volatile boolean vilc_b_adc01CtrCsmErrFlg_ovrdflg;
                /* Referenced by: '<S388>/vilc_flg_adc01CtrCsmErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc01CtrCsmErrFlg_ovrdval;
                  /* Referenced by: '<S388>/vilc_b_adc01CtrCsmErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc01PMSCtrAlvCtrErrFlg_ovrdflg;
          /* Referenced by: '<S389>/vilc_flg_adc01PMSCtrAlvCtrErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc01PMSCtrAlvCtrErrFlg_ovrdval;
            /* Referenced by: '<S389>/vilc_b_adc01PMSCtrAlvCtrErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc01PMSCtrComRxToutFlg_ovrdflg;
          /* Referenced by: '<S390>/vilc_flg_adc01PMSCtrComRxToutFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc01PMSCtrComRxToutFlg_ovrdval;
            /* Referenced by: '<S390>/vilc_b_adc01PMSCtrComRxToutFlg_ovrdval' */
extern const volatile boolean vilc_b_adc01PMSCtrCsmErrFlg_ovrdflg;
             /* Referenced by: '<S391>/vilc_flg_adc01PMSCtrCsmErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc01PMSCtrCsmErrFlg_ovrdval;
               /* Referenced by: '<S391>/vilc_b_adc01PMSCtrCsmErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc02CtrAlvCtrErrFlg_ovrdflg;
             /* Referenced by: '<S392>/vilc_flg_adc02CtrAlvCtrErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc02CtrAlvCtrErrFlg_ovrdval;
               /* Referenced by: '<S392>/vilc_b_adc02CtrAlvCtrErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc02CtrComRxToutFlg_ovrdflg;
             /* Referenced by: '<S393>/vilc_flg_adc02CtrComRxToutFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc02CtrComRxToutFlg_ovrdval;
               /* Referenced by: '<S393>/vilc_b_adc02CtrComRxToutFlg_ovrdval' */
extern const volatile boolean vilc_b_adc02CtrCsmErrFlg_ovrdflg;
                /* Referenced by: '<S394>/vilc_flg_adc02CtrCsmErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc02CtrCsmErrFlg_ovrdval;
                  /* Referenced by: '<S394>/vilc_b_adc02CtrCsmErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc02CtrlGearEn_ovrdflg;
                  /* Referenced by: '<S395>/vilc_flg_adc02CtrlGearEn_ovrdflg' */
extern const volatile boolean vilc_b_adc02CtrlGearEn_ovrdval;
                    /* Referenced by: '<S395>/vilc_b_adc02CtrlGearEn_ovrdval' */
extern const volatile boolean vilc_b_adc02CtrlSts_ovrdflg;
                     /* Referenced by: '<S396>/vilc_flg_adc02CtrlSts_ovrdflg' */
extern const volatile boolean vilc_b_adc02CtrlSts_ovrdval;
                       /* Referenced by: '<S396>/vilc_b_adc02CtrlSts_ovrdval' */
extern const volatile boolean vilc_b_adc02CtrlTorqEn_ovrdflg;
                  /* Referenced by: '<S397>/vilc_flg_adc02CtrlTorqEn_ovrdflg' */
extern const volatile boolean vilc_b_adc02CtrlTorqEn_ovrdval;
                    /* Referenced by: '<S397>/vilc_b_adc02CtrlTorqEn_ovrdval' */
extern const volatile boolean vilc_b_adc02PMSCtrAlvCtrErrFlg_ovrdflg;
          /* Referenced by: '<S398>/vilc_flg_adc02PMSCtrAlvCtrErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc02PMSCtrAlvCtrErrFlg_ovrdval;
            /* Referenced by: '<S398>/vilc_b_adc02PMSCtrAlvCtrErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc02PMSCtrComRxToutFlg_ovrdflg;
          /* Referenced by: '<S399>/vilc_flg_adc02PMSCtrComRxToutFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc02PMSCtrComRxToutFlg_ovrdval;
            /* Referenced by: '<S399>/vilc_b_adc02PMSCtrComRxToutFlg_ovrdval' */
extern const volatile boolean vilc_b_adc02PMSCtrCsmErrFlg_ovrdflg;
             /* Referenced by: '<S400>/vilc_flg_adc02PMSCtrCsmErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc02PMSCtrCsmErrFlg_ovrdval;
               /* Referenced by: '<S400>/vilc_b_adc02PMSCtrCsmErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc02SystSts_ovrdflg;
                     /* Referenced by: '<S401>/vilc_flg_adc02SystSts_ovrdflg' */
extern const volatile boolean vilc_b_adc02SystSts_ovrdval;
                       /* Referenced by: '<S401>/vilc_b_adc02SystSts_ovrdval' */
extern const volatile boolean vilc_b_adc02TargetDrvTq_ovrdflg;
                 /* Referenced by: '<S440>/vilc_flg_adc02TargetDrvTq_ovrdflg' */
extern const volatile boolean vilc_b_adc02TargetGearPostion_ovrdflg;
           /* Referenced by: '<S432>/vilc_flg_adc02TargetGearPostion_ovrdflg' */
extern const volatile boolean vilc_b_adc02Temp_ovrdflg;
                        /* Referenced by: '<S436>/vilc_flg_adc02Temp_ovrdflg' */
extern const volatile boolean vilc_b_adc0CtrlGearEn_ovrdflg;
                   /* Referenced by: '<S402>/vilc_flg_adc0CtrlGearEn_ovrdflg' */
extern const volatile boolean vilc_b_adc0CtrlGearEn_ovrdval;
                     /* Referenced by: '<S402>/vilc_b_adc0CtrlGearEn_ovrdval' */
extern const volatile boolean vilc_b_adc0CtrlSts_ovrdflg;
                      /* Referenced by: '<S403>/vilc_flg_adc0CtrlSts_ovrdflg' */
extern const volatile boolean vilc_b_adc0CtrlSts_ovrdval;
                        /* Referenced by: '<S403>/vilc_b_adc0CtrlSts_ovrdval' */
extern const volatile boolean vilc_b_adc0CtrlTorqEn_ovrdflg;
                   /* Referenced by: '<S404>/vilc_flg_adc0CtrlTorqEn_ovrdflg' */
extern const volatile boolean vilc_b_adc0CtrlTorqEn_ovrdval;
                     /* Referenced by: '<S404>/vilc_b_adc0CtrlTorqEn_ovrdval' */
extern const volatile boolean vilc_b_adc0SystSts_ovrdflg;
                      /* Referenced by: '<S405>/vilc_flg_adc0SystSts_ovrdflg' */
extern const volatile boolean vilc_b_adc0SystSts_ovrdval;
                        /* Referenced by: '<S405>/vilc_b_adc0SystSts_ovrdval' */
extern const volatile boolean vilc_b_adc0TargetDrvTq_Nm_ovrdflg;
               /* Referenced by: '<S441>/vilc_flg_adc0TargetDrvTq_Nm_ovrdflg' */
extern const volatile boolean vilc_b_adc0TargetGearPostion_ovrdflg;
            /* Referenced by: '<S433>/vilc_flg_adc0TargetGearPostion_ovrdflg' */
extern const volatile boolean vilc_b_adc0Temp_ovrdflg;
                         /* Referenced by: '<S437>/vilc_flg_adc0Temp_ovrdflg' */
extern const volatile boolean vilc_b_adc11CtrAlvCtrErrFlg_ovrdflg;
             /* Referenced by: '<S406>/vilc_flg_adc11CtrAlvCtrErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc11CtrAlvCtrErrFlg_ovrdval;
               /* Referenced by: '<S406>/vilc_b_adc11CtrAlvCtrErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc11CtrComRxToutFlg_ovrdflg;
             /* Referenced by: '<S407>/vilc_flg_adc11CtrComRxToutFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc11CtrComRxToutFlg_ovrdval;
               /* Referenced by: '<S407>/vilc_b_adc11CtrComRxToutFlg_ovrdval' */
extern const volatile boolean vilc_b_adc11CtrCsmErrFlg_ovrdflg;
                /* Referenced by: '<S408>/vilc_flg_adc11CtrCsmErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc11CtrCsmErrFlg_ovrdval;
                  /* Referenced by: '<S408>/vilc_b_adc11CtrCsmErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc11PMSCtrAlvCtrErrFlg_ovrdflg;
          /* Referenced by: '<S409>/vilc_flg_adc11PMSCtrAlvCtrErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc11PMSCtrAlvCtrErrFlg_ovrdval;
            /* Referenced by: '<S409>/vilc_b_adc11PMSCtrAlvCtrErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc11PMSCtrComRxToutFlg_ovrdflg;
          /* Referenced by: '<S410>/vilc_flg_adc11PMSCtrComRxToutFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc11PMSCtrComRxToutFlg_ovrdval;
            /* Referenced by: '<S410>/vilc_b_adc11PMSCtrComRxToutFlg_ovrdval' */
extern const volatile boolean vilc_b_adc11PMSCtrCsmErrFlg_ovrdflg;
             /* Referenced by: '<S411>/vilc_flg_adc11PMSCtrCsmErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc11PMSCtrCsmErrFlg_ovrdval;
               /* Referenced by: '<S411>/vilc_b_adc11PMSCtrCsmErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc12CanbusFlg_ovrdflg;
                   /* Referenced by: '<S412>/vilc_flg_adc12CanbusFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc12CanbusFlg_ovrdval;
                     /* Referenced by: '<S412>/vilc_b_adc12CanbusFlg_ovrdval' */
extern const volatile boolean vilc_b_adc12CtrAlvCtrErrFlg_ovrdflg;
             /* Referenced by: '<S413>/vilc_flg_adc12CtrAlvCtrErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc12CtrAlvCtrErrFlg_ovrdval;
               /* Referenced by: '<S413>/vilc_b_adc12CtrAlvCtrErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc12CtrComRxToutFlg_ovrdflg;
             /* Referenced by: '<S414>/vilc_flg_adc12CtrComRxToutFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc12CtrComRxToutFlg_ovrdval;
               /* Referenced by: '<S414>/vilc_b_adc12CtrComRxToutFlg_ovrdval' */
extern const volatile boolean vilc_b_adc12CtrCsmErrFlg_ovrdflg;
                /* Referenced by: '<S415>/vilc_flg_adc12CtrCsmErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc12CtrCsmErrFlg_ovrdval;
                  /* Referenced by: '<S415>/vilc_b_adc12CtrCsmErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc12CtrlGearEn_ovrdflg;
                  /* Referenced by: '<S416>/vilc_flg_adc12CtrlGearEn_ovrdflg' */
extern const volatile boolean vilc_b_adc12CtrlGearEn_ovrdval;
                    /* Referenced by: '<S416>/vilc_b_adc12CtrlGearEn_ovrdval' */
extern const volatile boolean vilc_b_adc12CtrlSts_ovrdflg;
                     /* Referenced by: '<S417>/vilc_flg_adc12CtrlSts_ovrdflg' */
extern const volatile boolean vilc_b_adc12CtrlSts_ovrdval;
                       /* Referenced by: '<S417>/vilc_b_adc12CtrlSts_ovrdval' */
extern const volatile boolean vilc_b_adc12CtrlTorqEn_ovrdflg;
                  /* Referenced by: '<S418>/vilc_flg_adc12CtrlTorqEn_ovrdflg' */
extern const volatile boolean vilc_b_adc12CtrlTorqEn_ovrdval;
                    /* Referenced by: '<S418>/vilc_b_adc12CtrlTorqEn_ovrdval' */
extern const volatile boolean vilc_b_adc12PMSCtrAlvCtrErrFlg_ovrdflg;
          /* Referenced by: '<S419>/vilc_flg_adc12PMSCtrAlvCtrErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc12PMSCtrAlvCtrErrFlg_ovrdval;
            /* Referenced by: '<S419>/vilc_b_adc12PMSCtrAlvCtrErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc12PMSCtrComRxToutFlg_ovrdflg;
          /* Referenced by: '<S420>/vilc_flg_adc12PMSCtrComRxToutFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc12PMSCtrComRxToutFlg_ovrdval;
            /* Referenced by: '<S420>/vilc_b_adc12PMSCtrComRxToutFlg_ovrdval' */
extern const volatile boolean vilc_b_adc12PMSCtrCsmErrFlg_ovrdflg;
             /* Referenced by: '<S421>/vilc_flg_adc12PMSCtrCsmErrFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc12PMSCtrCsmErrFlg_ovrdval;
               /* Referenced by: '<S421>/vilc_b_adc12PMSCtrCsmErrFlg_ovrdval' */
extern const volatile boolean vilc_b_adc12SwitchCtrlReq_ovrdflg;
               /* Referenced by: '<S422>/vilc_flg_adc12SwitchCtrlReq_ovrdflg' */
extern const volatile boolean vilc_b_adc12SwitchCtrlReq_ovrdval;
                 /* Referenced by: '<S422>/vilc_b_adc12SwitchCtrlReq_ovrdval' */
extern const volatile boolean vilc_b_adc12SystSts_ovrdflg;
                     /* Referenced by: '<S423>/vilc_flg_adc12SystSts_ovrdflg' */
extern const volatile boolean vilc_b_adc12SystSts_ovrdval;
                       /* Referenced by: '<S423>/vilc_b_adc12SystSts_ovrdval' */
extern const volatile boolean vilc_b_adc12TargetDrvTq_ovrdflg;
                 /* Referenced by: '<S442>/vilc_flg_adc12TargetDrvTq_ovrdflg' */
extern const volatile boolean vilc_b_adc12TargetGearPostion_ovrdflg;
           /* Referenced by: '<S434>/vilc_flg_adc12TargetGearPostion_ovrdflg' */
extern const volatile boolean vilc_b_adc12Temp_ovrdflg;
                        /* Referenced by: '<S438>/vilc_flg_adc12Temp_ovrdflg' */
extern const volatile boolean vilc_b_adc1CanbusFlg_ovrdflg;
                    /* Referenced by: '<S424>/vilc_flg_adc1CanbusFlg_ovrdflg' */
extern const volatile boolean vilc_b_adc1CanbusFlg_ovrdval;
                      /* Referenced by: '<S424>/vilc_b_adc1CanbusFlg_ovrdval' */
extern const volatile boolean vilc_b_adc1CtrlGearEn_ovrdflg;
                   /* Referenced by: '<S425>/vilc_flg_adc1CtrlGearEn_ovrdflg' */
extern const volatile boolean vilc_b_adc1CtrlGearEn_ovrdval;
                     /* Referenced by: '<S425>/vilc_b_adc1CtrlGearEn_ovrdval' */
extern const volatile boolean vilc_b_adc1CtrlSts_ovrdflg;
                      /* Referenced by: '<S426>/vilc_flg_adc1CtrlSts_ovrdflg' */
extern const volatile boolean vilc_b_adc1CtrlSts_ovrdval;
                        /* Referenced by: '<S426>/vilc_b_adc1CtrlSts_ovrdval' */
extern const volatile boolean vilc_b_adc1CtrlTorqEn_ovrdflg;
                   /* Referenced by: '<S427>/vilc_flg_adc1CtrlTorqEn_ovrdflg' */
extern const volatile boolean vilc_b_adc1CtrlTorqEn_ovrdval;
                     /* Referenced by: '<S427>/vilc_b_adc1CtrlTorqEn_ovrdval' */
extern const volatile boolean vilc_b_adc1SwitchCtrlReq_ovrdflg;
                /* Referenced by: '<S428>/vilc_flg_adc1SwitchCtrlReq_ovrdflg' */
extern const volatile boolean vilc_b_adc1SwitchCtrlReq_ovrdval;
                  /* Referenced by: '<S428>/vilc_b_adc1SwitchCtrlReq_ovrdval' */
extern const volatile boolean vilc_b_adc1SystSts_ovrdflg;
                      /* Referenced by: '<S429>/vilc_flg_adc1SystSts_ovrdflg' */
extern const volatile boolean vilc_b_adc1SystSts_ovrdval;
                        /* Referenced by: '<S429>/vilc_b_adc1SystSts_ovrdval' */
extern const volatile boolean vilc_b_adc1TargetDrvTq_ovrdflg;
                  /* Referenced by: '<S443>/vilc_flg_adc1TargetDrvTq_ovrdflg' */
extern const volatile boolean vilc_b_adc1TargetGearPostion_ovrdflg;
            /* Referenced by: '<S435>/vilc_flg_adc1TargetGearPostion_ovrdflg' */
extern const volatile boolean vilc_b_adc1Temp_ovrdflg;
                         /* Referenced by: '<S439>/vilc_flg_adc1Temp_ovrdflg' */
extern const volatile boolean vilc_b_adcCANBusOffFlg_ovrdflg;
                  /* Referenced by: '<S430>/vilc_flg_adcCANBusOffFlg_ovrdflg' */
extern const volatile boolean vilc_b_adcCANBusOffFlg_ovrdval;
                    /* Referenced by: '<S430>/vilc_b_adcCANBusOffFlg_ovrdval' */
extern const volatile boolean vilc_b_airCmprAct_ovrdflg;
                       /* Referenced by: '<S349>/vilc_flg_airCmprAct_ovrdflg' */

/* Override flag for signal b_airCmprAct */
extern const volatile boolean vilc_b_airCmprSt_ovrdflg;
                        /* Referenced by: '<S357>/vilc_flg_airCmprSt_ovrdflg' */

/* Override flag for signal b_airCmprSt */
extern const volatile boolean vilc_b_batIntSmpl_ovrdflg;
                                /* Referenced by: '<S996>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal b_batIntSmpl */
extern const volatile boolean vilc_b_batLowSoc2_ovrdflg;
                     /* Referenced by: '<S779>/vilc_b_hvbDCChgCurReq_ovrdflg' */
extern const volatile boolean vilc_b_batLpPmpCtrlFb_ovrdflg;
                                /* Referenced by: '<S997>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal batLpPmpCtrlFb */
extern const volatile boolean vilc_b_batOvrSoc2_ovrdflg;
                        /* Referenced by: '<S780>/vilc_flg_hvbChgSts_ovrdflg' */
extern const volatile boolean vilc_b_batOvrVolt2_ovrdflg;
                        /* Referenced by: '<S781>/vilc_b_batOvrVolt2_ovrdflg' */
extern const volatile boolean vilc_b_batUdrVolt2_ovrdflg;
                        /* Referenced by: '<S782>/vilc_b_batUdrVolt2_ovrdflg' */
extern const volatile boolean vilc_b_bbmFltSts_ovrdflg;
                          /* Referenced by: '<S505>/vilc_b_bbmFltSts_ovrdflg' */
extern const volatile boolean vilc_b_bbmWorkSts_ovrdflg;
                         /* Referenced by: '<S506>/vilc_b_bbmWorkSts_ovrdflg' */
extern const volatile boolean vilc_b_bcmATWSSt_ovrdflg;
                          /* Referenced by: '<S507>/vilc_b_bcmATWSSt_ovrdflg' */

/* Override flag for signal BCM_ATWS_St */
extern const volatile boolean vilc_b_bcmFrntLDoorAjarSt_ovrdflg;
                 /* Referenced by: '<S508>/vilc_b_bcmFrntLDoorAjarSt_ovrdflg' */

/* Override flag for signal vild_st_bcmFrntLDoorAjarSt */
extern const volatile boolean vilc_b_bcmFrntRDoorAjarSt_ovrdflg;
                 /* Referenced by: '<S509>/vilc_b_bcmFrntRDoorAjarSt_ovrdflg' */

/* Override flag for signal vild_st_bcmFrntRDoorAjarSt */
extern const volatile boolean vilc_b_bcmOdometerbackup_ovrdflg;
                  /* Referenced by: '<S504>/vilc_b_bcmOdometerbackup_ovrdflg' */
extern const volatile boolean vilc_b_bmsBattPackMatchFlt_ovrdflg;
                /* Referenced by: '<S708>/vilc_b_bmsBattPackMatchFlt_ovrdflg' */
extern const volatile boolean vilc_b_bmsBattPackNum_ovrdflg;
                     /* Referenced by: '<S709>/vilc_b_bmsBattPackNum_ovrdflg' */
extern const volatile boolean vilc_b_bmsBattSysNum_ovrdflg;
                      /* Referenced by: '<S710>/vilc_b_bmsBattSysNum_ovrdflg' */
extern const volatile boolean vilc_b_bmsDlyDataUpldEnb_ovrdflg;
                  /* Referenced by: '<S711>/vilc_b_bmsDlyDataUpldEnb_ovrdflg' */
extern const volatile boolean vilc_b_bmsTboxFireAlm_ovrdflg;
                     /* Referenced by: '<S712>/vilc_b_bmsTboxFireAlm_ovrdflg' */
extern const volatile boolean vilc_b_brkPedlStsInVld_ovrdflg;
                      /* Referenced by: '<S518>/vilc_b_brkPedlStsVld_ovrdflg' */
extern const volatile boolean vilc_b_brkPedlStsInVld_ovrdval;
                    /* Referenced by: '<S518>/vilc_st_brkPmpEnaOutFb_ovrdval' */
extern const volatile boolean vilc_b_brkPmpEnaOutFb_ovrdflg;
                     /* Referenced by: '<S519>/vilc_b_brkPmpEnaOutFb_ovrdflg' */

/* Override flag for signal BDCACEnableOutFb */
extern const volatile boolean vilc_b_brkPmpSelfChk_ovrdflg;
                    /* Referenced by: '<S520>/vilc_flg_brkPmpSelfChk_ovrdflg' */

/* Override flag for signal b_brkPmpSelfChk */
extern const volatile boolean vilc_b_brkPmpWrkSt_ovrdflg;
                      /* Referenced by: '<S521>/vilc_flg_brkPmpWrkSt_ovrdflg' */

/* Override flag for signal b_brkPmpWrkSt */
extern const volatile boolean vilc_b_brkPumpFault_invert;
                       /* Referenced by: '<S951>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for signal brkPumpFault */
extern const volatile boolean vilc_b_brkPumpFault_ovrdflg;
                      /* Referenced by: '<S951>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal brkPumpFault */
extern const volatile boolean vilc_b_brkPumpFault_ovrdval;
                      /* Referenced by: '<S951>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal brkPumpFault */
extern const volatile boolean vilc_b_brkVacuumPres_ovrdflg;
                      /* Referenced by: '<S522>/vilc_b_brkVacuumPres_ovrdflg' */
extern const volatile boolean vilc_b_calCanBusOff_invert;
                       /* Referenced by: '<S952>/vilc_b_ResrAirSwitch_invert' */

/* Inversion flag for signal calCanBusOff */
extern const volatile boolean vilc_b_calCanBusOff_ovrdflg;
                      /* Referenced by: '<S952>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal calCanBusOff */
extern const volatile boolean vilc_b_calCanBusOff_ovrdval;
                      /* Referenced by: '<S952>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal calCanBusOff */
extern const volatile boolean vilc_b_cbnLpPmpCtrlFb_ovrdflg;
                                /* Referenced by: '<S998>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal cbnLpPmpCtrlFb */
extern const volatile boolean vilc_b_cbnThermMngReq_ovrdflg;
                   /* Referenced by: '<S358>/vilc_flg_cbnThermMngReq_ovrdflg' */

/* Override flag for signal b_cbnThermMngReq */
extern const volatile boolean vilc_b_cellOverVolt2_ovrdflg;
                      /* Referenced by: '<S783>/vilc_b_cellOverVolt2_ovrdflg' */
extern const volatile boolean vilc_b_cellUdrVolt2_ovrdflg;
                       /* Referenced by: '<S784>/vilc_b_cellUdrVolt2_ovrdflg' */
extern const volatile boolean vilc_b_chdLckActv_ovrdflg;
                         /* Referenced by: '<S694>/vilc_b_chdLckActv_ovrdflg' */

/* Override flag for signal b_chdLckActv */
extern const volatile boolean vilc_b_cntnrCtrlEnaFb_ovrdflg;
                     /* Referenced by: '<S953>/vilc_b_cntnrCtrlEnaFb_ovrdflg' */

/* Override flag for signal vild_b_cntnrCtrlEnaFb */
extern const volatile boolean vilc_b_cntnrCtrlEnaFb_ovrdval;
                     /* Referenced by: '<S953>/vild_b_cntnrCtrlEnaFb_ovrdval' */

/* Override value for signal vild_b_cntnrCtrlEnaFb */
extern const volatile boolean vilc_b_cruiseADvoltage_ovrdflg;
                    /* Referenced by: '<S999>/vilc_b_cruiseADvoltage_ovrdflg' */

/* Override flag for signal CruiseCtrlInp_V */
extern const volatile boolean vilc_b_csmCampModeSwtInvld_ovrdflg;
                /* Referenced by: '<S547>/vilc_b_csmCampModeSwtInvld_ovrdflg' */
extern const volatile boolean vilc_b_csmCampModeSwtInvld_ovrdval;
                /* Referenced by: '<S547>/vilc_b_csmCampModeSwtInvld_ovrdval' */
extern const volatile boolean vilc_b_csmCampModeSwt_ovrdflg;
                     /* Referenced by: '<S546>/vilc_b_csmCampModeSwt_ovrdflg' */
extern const volatile boolean vilc_b_csmCampModeSwt_ovrdval;
                     /* Referenced by: '<S546>/vilc_b_csmCampModeSwt_ovrdval' */
extern const volatile boolean vilc_b_csmEcoReqInvld_ovrdflg;
                   /* Referenced by: '<S548>/vilc_flg_csmEcoReqInvld_ovrdflg' */
extern const volatile boolean vilc_b_csmEcoReqInvld_ovrdval;
                     /* Referenced by: '<S548>/vilc_b_csmEcoReqInvld_ovrdval' */
extern const volatile boolean vilc_b_csmEngRecReqInvalid_ovrdflg;
                /* Referenced by: '<S553>/vilc_b_csmEngRecReqInvalid_ovrdflg' */
extern const volatile boolean vilc_b_csmEngRecReq_ovrdflg;
                       /* Referenced by: '<S552>/vilc_b_csmEngRecReq_ovrdflg' */
extern const volatile boolean vilc_b_csmEngRecSwtReq_ovrdflg;
                    /* Referenced by: '<S549>/vilc_b_csmEngRecSwtReq_ovrdflg' */
extern const volatile boolean vilc_b_csmEngRecSwtReq_ovrdval;
                    /* Referenced by: '<S549>/vilc_b_csmEngRecSwtReq_ovrdval' */
extern const volatile boolean vilc_b_csmTakeEleSwtReqInvld_ovrdflg;
              /* Referenced by: '<S551>/vilc_b_csmTakeEleSwtReqInvld_ovrdflg' */
extern const volatile boolean vilc_b_csmTakeEleSwtReqInvld_ovrdval;
              /* Referenced by: '<S551>/vilc_b_csmTakeEleSwtReqInvld_ovrdval' */
extern const volatile boolean vilc_b_csmTakeEleSwt_ovrdflg;
                      /* Referenced by: '<S550>/vilc_b_csmTakeEleSwt_ovrdflg' */
extern const volatile boolean vilc_b_csmTakeEleSwt_ovrdval;
                      /* Referenced by: '<S550>/vilc_b_csmTakeEleSwt_ovrdval' */
extern const volatile boolean vilc_b_csmV2XDchaSwInvld_ovrdflg;
                 /* Referenced by: '<S1145>/vilc_b_csmV2XDchaSwInvld_ovrdflg' */
extern const volatile boolean vilc_b_csmV2XDchaSwInvld_ovrdval;
                 /* Referenced by: '<S1145>/vilc_b_csmV2XDchaSwInvld_ovrdval' */
extern const volatile boolean vilc_b_csmV2XDchaSw_ovrdflg;
                      /* Referenced by: '<S1144>/vilc_b_csmV2XDchaSw_ovrdflg' */
extern const volatile boolean vilc_b_csmV2XDchaSw_ovrdval;
                      /* Referenced by: '<S1144>/vilc_b_csmV2XDchaSw_ovrdval' */
extern const volatile boolean vilc_b_dcChgCcSt_ovrdflg;
                      /* Referenced by: '<S1142>/vilc_flag_dcChgCcSt_ovrdflg' */

/* Override flag for signal b_dcChgCcSt */
extern const volatile boolean vilc_b_dccAccyConnStsFb_ovrdflg;
                   /* Referenced by: '<S570>/vilc_b_dccAccyConnStsFb_ovrdflg' */
extern const volatile boolean vilc_b_dcdcCanComFlt_ovrdflg;
                    /* Referenced by: '<S571>/vilc_flg_dcdcCanComFlt_ovrdflg' */

/* Override flag for signal b_dcdcCanComFlt */
extern const volatile boolean vilc_b_dcdcCutOffLvFb_ovrdflg;
                   /* Referenced by: '<S572>/vilc_flg_dcdcCutOffLvFb_ovrdflg' */

/* Override flag for signal b_dcdcCutOffLvFb */
extern const volatile boolean vilc_b_dcdcErrorCode_ovrdflg;
                      /* Referenced by: '<S573>/vilc_b_dcdcErrorCode_ovrdflg' */

/* Override flag for signal DCDC_ErrorCode */
extern const volatile boolean vilc_b_dcdcFltSts_ovrdflg;
                       /* Referenced by: '<S574>/vilc_flg_dcdcFltSts_ovrdflg' */

/* Override flag for signal b_dcdcFltSts */
extern const volatile boolean vilc_b_dcdcInpCurr_ovrdflg;
                      /* Referenced by: '<S564>/vilc_flg_dcdcInpCurr_ovrdflg' */
extern const volatile boolean vilc_b_dcdcInpVolt_ovrdflg;
                      /* Referenced by: '<S580>/vilc_flg_dcdcInpVolt_ovrdflg' */
extern const volatile boolean vilc_b_dcdcModAct_ovrdflg;
                       /* Referenced by: '<S575>/vilc_flg_dcdcModAct_ovrdflg' */

/* Override flag for signal b_dcdcModAct */
extern const volatile boolean vilc_b_dcdcOutpCurr_ovrdflg;
                     /* Referenced by: '<S565>/vilc_flg_dcdcOutpCurr_ovrdflg' */

/* Override flag for signal b_dcdcOutpCurr */
extern const volatile boolean vilc_b_dcdcOutpOvrCurr_ovrdflg;
                  /* Referenced by: '<S576>/vilc_flg_dcdcOutpOvrCurr_ovrdflg' */

/* Override flag for signal b_dcdcOutpOvrCurr */
extern const volatile boolean vilc_b_dcdcOutpOvrVolt_ovrdflg;
                  /* Referenced by: '<S577>/vilc_flg_dcdcOutpOvrVolt_ovrdflg' */

/* Override flag for signal b_dcdcOutpOvrVolt */
extern const volatile boolean vilc_b_dcdcOutpVolt_ovrdflg;
                     /* Referenced by: '<S581>/vilc_flg_dcdcOutpVolt_ovrdflg' */

/* Override flag for signal b_dcdcOutpVolt */
extern const volatile boolean vilc_b_dcdcRelayVolt_ovrdflg;
                    /* Referenced by: '<S582>/vilc_flg_dcdcRelayVolt_ovrdflg' */
extern const volatile boolean vilc_b_dcdcSelfChk_ovrdflg;
                      /* Referenced by: '<S578>/vilc_flg_dcdcSelfChk_ovrdflg' */

/* Override flag for signal b_dcdcSelfChk */
extern const volatile boolean vilc_b_dcdcStsAlm_ovrdflg;
                         /* Referenced by: '<S562>/vilc_b_dcdcStsAlm_ovrdflg' */
extern const volatile boolean vilc_b_dcdcStsAlm_ovrdval;
                         /* Referenced by: '<S562>/vilc_b_dcdcStsAlm_ovrdval' */
extern const volatile boolean vilc_b_dcdcTempAlm_ovrdflg;
                        /* Referenced by: '<S563>/vilc_b_dcdcTempAlm_ovrdflg' */
extern const volatile boolean vilc_b_dcdcTempAlm_ovrdval;
                        /* Referenced by: '<S563>/vilc_b_dcdcTempAlm_ovrdval' */
extern const volatile boolean vilc_b_disChgSwtSt_ovrdflg;
                      /* Referenced by: '<S954>/vilc_flg_disChgSwtSt_ovrdflg' */
extern const volatile boolean vilc_b_disChgSwtSt_ovrdval;
                        /* Referenced by: '<S954>/vilc_b_disChgSwtSt_ovrdval' */
extern const volatile boolean vilc_b_drvCabOverturned_invert;
                   /* Referenced by: '<S1029>/vilc_b_drvCabOverturned_invert' */

/* Invert flag for signal vild_b_drvCabOverturned */
extern const volatile boolean vilc_b_drvCabOverturned_ovrdval;
                  /* Referenced by: '<S1029>/vilc_b_drvCabOverturned_ovrdval' */

/* Override value for signal vild_b_drvCabOverturned */
extern const volatile boolean vilc_b_eLpWpCtrlCur_ovrdflg;
                               /* Referenced by: '<S1000>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal eLpWpCtrlCur */
extern const volatile boolean vilc_b_eadInv2ActCurrDC_ovrdflg;
                 /* Referenced by: '<S617>/vilc_flg_eadInv2ActCurrDC_ovrdflg' */

/* Override flag for signal b_eadInv2ActCurrDC */
extern const volatile boolean vilc_b_eadInv2ActMod_ovrdflg;
                    /* Referenced by: '<S620>/vilc_flg_eadInv2ActMod_ovrdflg' */

/* Override flag for signal b_eadInv2ActMod */
extern const volatile boolean vilc_b_eadInv2ActVoltDC_ovrdflg;
                 /* Referenced by: '<S650>/vilc_flg_eadInv2ActVoltDC_ovrdflg' */

/* Override flag for signal b_eadInv2ActVoltDC */
extern const volatile boolean vilc_b_eadInv2ActvDischgFlt_ovrdflg;
             /* Referenced by: '<S621>/vilc_flg_eadInv2ActvDischgFlt_ovrdflg' */

/* Override flag for signal b_eadInv2ActvDischgFlt */
extern const volatile boolean vilc_b_eadInv2CanComFlt_ovrdflg;
                 /* Referenced by: '<S622>/vilc_flg_eadInv2CanComFlt_ovrdflg' */

/* Override flag for signal b_eadInv2CanComFlt */
extern const volatile boolean vilc_b_eadInv2CtrlMod_ovrdflg;
                   /* Referenced by: '<S623>/vilc_flg_eadInv2CtrlMod_ovrdflg' */

/* Override flag for signal b_eadInv2CtrlMod */
extern const volatile boolean vilc_b_eadInv2FltSts_ovrdflg;
                    /* Referenced by: '<S624>/vilc_flg_eadInv2FltSts_ovrdflg' */

/* Override flag for signal b_eadInv2FltSts */
extern const volatile boolean vilc_b_eadInv2HVLFlt_ovrdflg;
                      /* Referenced by: '<S625>/vilc_b_eadInv2HVLFlt_ovrdflg' */

/* Override flag for signal MCU_HVLoopFault */
extern const volatile boolean vilc_b_eadInv2IgbtFlt_ovrdflg;
                   /* Referenced by: '<S626>/vilc_flg_eadInv2IgbtFlt_ovrdflg' */

/* Override flag for signal b_eadInv2IgbtFlt */
extern const volatile boolean vilc_b_eadInv2MemFlt_ovrdflg;
                    /* Referenced by: '<S627>/vilc_flg_eadInv2MemFlt_ovrdflg' */

/* Override flag for signal b_eadInv2MemFlt */
extern const volatile boolean vilc_b_eadInv2PwrActvMod_ovrdflg;
                  /* Referenced by: '<S628>/vilc_b_eadInv2PwrActvMod_ovrdflg' */

/* Override flag for signal MCU_PowerActiveMode */
extern const volatile boolean vilc_b_eadInv2RotInvFlt_ovrdflg;
                 /* Referenced by: '<S629>/vilc_flg_eadInv2RotInvFlt_ovrdflg' */

/* Override flag for signal b_eadInv2RotInvFlt */
extern const volatile boolean vilc_b_eadInv2SelfChk_ovrdflg;
                   /* Referenced by: '<S630>/vilc_flg_eadInv2SelfChk_ovrdflg' */

/* Override flag for signal b_eadInv2SelfChk */
extern const volatile boolean vilc_b_eadInv2TempHiAlrm_ovrdflg;
                /* Referenced by: '<S631>/vilc_flg_eadInv2TempHiAlrm_ovrdflg' */

/* Override flag for signal b_eadInv2TempHiAlrm */
extern const volatile boolean vilc_b_eadInv2TempSnsrErr_ovrdflg;
               /* Referenced by: '<S632>/vilc_flg_eadInv2TempSnsrErr_ovrdflg' */

/* Override flag for signal b_eadInv2TempSnsrErr */
extern const volatile boolean vilc_b_eadInv2Temp_ovrdflg;
                      /* Referenced by: '<S645>/vilc_flg_eadInv2Temp_ovrdflg' */

/* Override flag for signal b_eadInv2Temp */
extern const volatile boolean vilc_b_eadInv2WrkMod_ovrdflg;
                    /* Referenced by: '<S633>/vilc_flg_eadInv2WrkMod_ovrdflg' */

/* Override flag for signal b_eadInv2WrkMod */
extern const volatile boolean vilc_b_eadMot2ActOutpPwr_ovrdflg;
                /* Referenced by: '<S619>/vilc_flg_eadMot2ActOutpPwr_ovrdflg' */

/* Override flag for signal b_eadMot2ActOutpPwr */
extern const volatile boolean vilc_b_eadMot2ActSpd_ovrdflg;
                    /* Referenced by: '<S618>/vilc_flg_eadMot2ActSpd_ovrdflg' */

/* Override flag for signal b_eadMot2ActSpd */
extern const volatile boolean vilc_b_eadMot2ActTq_ovrdflg;
                     /* Referenced by: '<S647>/vilc_flg_eadMot2ActTq_ovrdflg' */

/* Override flag for signal b_eadMot2ActTq */
extern const volatile boolean vilc_b_eadMot2BlkRotErr_ovrdflg;
                 /* Referenced by: '<S634>/vilc_flg_eadMot2BlkRotErr_ovrdflg' */

/* Override flag for signal b_eadMot2BlkRotErr */
extern const volatile boolean vilc_b_eadMot2ImmoRlsChk_ovrdflg;
                  /* Referenced by: '<S635>/vilc_b_eadMot2ImmoRlsChk_ovrdflg' */

/* Override flag for signal vild_st_eadMot2ImmoRlsChk */
extern const volatile boolean vilc_b_eadMot2LTBstTqLim_ovrdflg;
                /* Referenced by: '<S648>/vilc_flg_eadMot2LTBstTqLim_ovrdflg' */

/* Override flag for signal b_eadMot2LTBstTqLim */
extern const volatile boolean vilc_b_eadMot2LTGenTqLim_ovrdflg;
                /* Referenced by: '<S649>/vilc_flg_eadMot2LTGenTqLim_ovrdflg' */

/* Override flag for signal b_eadMot2LTGenTqLim */
extern const volatile boolean vilc_b_eadMot2SpdHiAlrm_ovrdflg;
                 /* Referenced by: '<S636>/vilc_flg_eadMot2SpdHiAlrm_ovrdflg' */

/* Override flag for signal b_eadMot2SpdHiAlrm */
extern const volatile boolean vilc_b_eadMot2SysOvrLdAlrm_ovrdflg;
              /* Referenced by: '<S637>/vilc_flg_eadMot2SysOvrLdAlrm_ovrdflg' */

/* Override flag for signal b_eadMot2SysOvrLdAlrm */
extern const volatile boolean vilc_b_eadMot2TempHiAlrm_ovrdflg;
                /* Referenced by: '<S638>/vilc_flg_eadMot2TempHiAlrm_ovrdflg' */

/* Override flag for signal b_eadMot2TempHiAlrm */
extern const volatile boolean vilc_b_eadMot2TempHiFlt_ovrdflg;
                 /* Referenced by: '<S639>/vilc_flg_eadMot2TempHiFlt_ovrdflg' */
extern const volatile boolean vilc_b_eadMot2TempSnsrErr_ovrdflg;
               /* Referenced by: '<S640>/vilc_flg_eadMot2TempSnsrErr_ovrdflg' */

/* Override flag for signal b_eadMot2TempSnsrErr */
extern const volatile boolean vilc_b_eadMot2Temp_ovrdflg;
                      /* Referenced by: '<S646>/vilc_flg_eadMot2Temp_ovrdflg' */

/* Override flag for signal b_eadMot2Temp */
extern const volatile boolean vilc_b_ecoModeSwitch_invert;
                       /* Referenced by: '<S955>/vilc_b_ecoModeSwitch_invert' */

/* Invert flag for signal b_ecoModeSwitch */
extern const volatile boolean vilc_b_ecoModeSwitch_ovrdflg;
                      /* Referenced by: '<S955>/vilc_b_ecoModeSwitch_ovrdflg' */

/* Override flag for signal b_ecoModeSwitch */
extern const volatile boolean vilc_b_ecoModeSwitch_ovrdval;
                      /* Referenced by: '<S955>/vilc_b_ecoModeSwitch_ovrdval' */

/* Override value for signal b_ecoModeSwitch */
extern const volatile boolean vilc_b_ecuFunConfigData1_ovrdflg;
                 /* Referenced by: '<S1057>/vilc_b_ecuFunConfigData1_ovrdflg' */

/* Override flag for signal ECU_Fun_Config_Data1 */
extern const volatile boolean vilc_b_ecuFunConfigData2_ovrdflg;
                 /* Referenced by: '<S1058>/vilc_b_ecuFunConfigData2_ovrdflg' */

/* Override flag for signal ECU_Fun_Config_Data2 */
extern const volatile boolean vilc_b_egsmFltLvl_ovrdflg;
                         /* Referenced by: '<S612>/vilc_b_egsmFltLvl_ovrdflg' */

/* Override flag for signal b_egsmFltLvl */
extern const volatile boolean vilc_b_egsmGearReq_ovrdflg;
                        /* Referenced by: '<S613>/vilc_b_egsmGearReq_ovrdflg' */

/* Override flag for signal b_egsmGearReq */
extern const volatile boolean vilc_b_egsmLeverPosition_ovrdflg;
                        /* Referenced by: '<S609>/vilc_b_egsmGearReq_ovrdflg' */
extern const volatile boolean vilc_b_egsmParkReq_ovrdflg;
                        /* Referenced by: '<S610>/vilc_b_egsmGearReq_ovrdflg' */
extern const volatile boolean vilc_b_ehbABSFaild_ovrdflg;
                       /* Referenced by: '<S1290>/vilc_b_ehbABSFaild_ovrdflg' */
extern const volatile boolean vilc_b_ehbABSFaild_ovrdval;
                       /* Referenced by: '<S1290>/vilc_b_ehbABSFaild_ovrdval' */
extern const volatile boolean vilc_b_ehbBrkSysErrFlt_ovrdflg;
                 /* Referenced by: '<S1305>/vilc_flg_ehbBrkSysErrFlt_ovrdflg' */
extern const volatile boolean vilc_b_ehbEPBDynAppSts_ovrdflg;
                 /* Referenced by: '<S1306>/vilc_flg_ehbEPBDynAppSts_ovrdflg' */
extern const volatile boolean vilc_b_ehbHHCActive_ovrdflg;
                    /* Referenced by: '<S1307>/vilc_flg_ehbHHCActive_ovrdflg' */
extern const volatile boolean vilc_b_ehbIsaPtTrqDecReqActv_ovrdflg;
             /* Referenced by: '<S1291>/vilc_b_ehbIsaPtTrqDecReqActv_ovrdflg' */
extern const volatile boolean vilc_b_ehbIsaPtTrqDecReqActv_ovrdval;
             /* Referenced by: '<S1291>/vilc_b_ehbIsaPtTrqDecReqActv_ovrdval' */
extern const volatile boolean vilc_b_ehbIsaPtTrqDecReq_ovrdflg;
                 /* Referenced by: '<S1311>/vilc_b_ehbIsaPtTrqDecReq_ovrdflg' */
extern const volatile boolean vilc_b_ehbIsaSts_ovrdflg;
                         /* Referenced by: '<S1308>/vilc_b_ehbIsaSts_ovrdflg' */
extern const volatile boolean vilc_b_ehbVehSpdInvld_ovrdflg;
                  /* Referenced by: '<S1292>/vilc_flg_ehbVehSpdInvld_ovrdflg' */
extern const volatile boolean vilc_b_ehbVehSpdInvld_ovrdval;
                    /* Referenced by: '<S1292>/vilc_b_ehbVehSpdInvld_ovrdval' */
extern const volatile boolean vilc_b_ehbVehSpd_ovrdflg;
                    /* Referenced by: '<S1316>/vilc_flg_vscEHBAVHSts_ovrdflg' */
extern const volatile boolean vilc_b_ehbVlcCddActv_ovrdflg;
                     /* Referenced by: '<S1293>/vilc_b_ehbVlcCddActv_ovrdflg' */
extern const volatile boolean vilc_b_ehbVlcCddActv_ovrdval;
                     /* Referenced by: '<S1293>/vilc_b_ehbVlcCddActv_ovrdval' */
extern const volatile boolean vilc_b_emgyStopIn_invert;
                       /* Referenced by: '<S956>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for signal emgyStopIn */
extern const volatile boolean vilc_b_emgyStopIn_ovrdflg;
                      /* Referenced by: '<S956>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal emgyStopIn */
extern const volatile boolean vilc_b_emgyStopIn_ovrdval;
                      /* Referenced by: '<S956>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal emgyStopIn */
extern const volatile boolean vilc_b_ep1Fb_invert;
                   /* Referenced by: '<S970>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for b_ep1Fb_invert */
extern const volatile boolean vilc_b_ep2Fb_invert;
                   /* Referenced by: '<S971>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for b_ep2Fb_invert */
extern const volatile boolean vilc_b_ep3Fb_invert;
                   /* Referenced by: '<S972>/volc_b_waterValveTV4V3_V_invert' */

/* Invert flag for b_ep3Fb_invert */
extern const volatile boolean vilc_b_epbErrCod_ovrdflg;
                          /* Referenced by: '<S693>/vilc_b_epbErrCod_ovrdflg' */

/* Override flag for signal b_epbErrCod */
extern const volatile boolean vilc_b_epbErrSts_ovrdflg;
                          /* Referenced by: '<S692>/vilc_b_prkBrkSts_ovrdflg' */
extern const volatile boolean vilc_b_epbErrSts_ovrdval;
                         /* Referenced by: '<S692>/vilc_st_prkBrkSts_ovrdval' */
extern const volatile boolean vilc_b_epbFltLvl_ovrdflg;
                          /* Referenced by: '<S695>/vilc_b_epbFltLvl_ovrdflg' */

/* Override flag for signal b_epbFltLvl */
extern const volatile boolean vilc_b_epsEpasFail_ovrdflg;
                       /* Referenced by: '<S1211>/vilc_b_epsEpasFail_ovrdflg' */
extern const volatile boolean vilc_b_epsErrorCode_ovrdflg;
                      /* Referenced by: '<S1201>/vilc_b_epsErrorCode_ovrdflg' */

/* Override flag for signal SDCAC_ErrorCode */
extern const volatile boolean vilc_b_epsFltLvl_ovrdflg;
                       /* Referenced by: '<S1202>/vilc_flg_epsFltLvl_ovrdflg' */

/* Override flag for signal b_epsFltLvl */
extern const volatile boolean vilc_b_epsSelfChk_ovrdflg;
                      /* Referenced by: '<S1203>/vilc_flg_epsSelfChk_ovrdflg' */

/* Override flag for signal b_epsSelfChk */
extern const volatile boolean vilc_b_epsSubFltLvl_ovrdflg;
                      /* Referenced by: '<S1204>/vilc_b_epsSubFltLvl_ovrdflg' */

/* Override flag for signal SDCAC_SubFltLevel */
extern const volatile boolean vilc_b_epsWrkSt_ovrdflg;
                        /* Referenced by: '<S1205>/vilc_flg_epsWrkSt_ovrdflg' */

/* Override flag for signal b_epsWrkSt */
extern const volatile boolean vilc_b_evModeSwitch_invert;
                        /* Referenced by: '<S957>/vilc_b_evModeSwitch_invert' */

/* Invert flag for signal b_evModeSwitch */
extern const volatile boolean vilc_b_evModeSwitch_ovrdflg;
                       /* Referenced by: '<S957>/vilc_b_evModeSwitch_ovrdflg' */

/* Override flag for signal b_evModeSwitch */
extern const volatile boolean vilc_b_evModeSwitch_ovrdval;
                       /* Referenced by: '<S957>/vilc_b_evModeSwitch_ovrdval' */

/* Override value for signal b_evModeSwitch */
extern const volatile boolean vilc_b_evtFaildABSMsgErr_ovrdval;/* Referenced by:
                                                                * '<S1359>/DFC_ovrdflg'
                                                                * '<S1359>/DFC_ovrdval'
                                                                */

/* Override value for DFC_HYB_ABSMsgErr */
extern const volatile boolean vilc_b_fan1Fb_ovrdflg;
                             /* Referenced by: '<S973>/vilc_b_fan1Fb_ovrdflg' */

/* Override flag for signal vild_pct_fan1Fb */
extern const volatile boolean vilc_b_fan2Fb_ovrdflg;
                             /* Referenced by: '<S974>/vilc_b_fan2Fb_ovrdflg' */

/* Override flag for signal vild_pct_fan2Fb */
extern const volatile boolean vilc_b_flg2FctCfgVehTyp_ovrdflg;
               /* Referenced by: '<S1089>/vilc_b_flgFctCfgDrvModConn_ovrdflg' */
extern const volatile boolean vilc_b_flg2FctCfgVehTyp_ovrdval;
               /* Referenced by: '<S1089>/vilc_b_flgFctCfgDrvModConn_ovrdval' */
extern const volatile boolean vilc_b_flgBBMMsgErr_ovrdflg;
                      /* Referenced by: '<S1056>/vilc_b_flgBBMMsgErr_ovrdflg' */
extern const volatile boolean vilc_b_flgBBMMsgErr_ovrdval;
                      /* Referenced by: '<S1056>/vilc_b_flgBBMMsgErr_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgACU_ovrdflg;
                      /* Referenced by: '<S1071>/vilc_b_flgFctCfgACU_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgACU_ovrdval;
                      /* Referenced by: '<S1071>/vilc_b_flgFctCfgACU_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgAccyButton_ovrdflg;
               /* Referenced by: '<S1072>/vilc_b_flgFctCfgDrvModConn_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgAccyButton_ovrdval;
               /* Referenced by: '<S1072>/vilc_b_flgFctCfgDrvModConn_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgAccy_ovrdflg;
                     /* Referenced by: '<S1090>/vilc_b_flgFctCfgAccy_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgAdc_ovrdflg;
                              /* Referenced by: '<S1073>/vilc_b_flgFctCfgAdc' */
extern const volatile boolean vilc_b_flgFctCfgAdc_ovrdval;
                      /* Referenced by: '<S1073>/vilc_b_flgFctCfgAdc_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgAirBag_ovrdflg;
                   /* Referenced by: '<S1074>/vilc_b_flgFctCfgAirBag_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgAirBag_ovrdval;
                   /* Referenced by: '<S1074>/vilc_b_flgFctCfgAirBag_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgBatCol_ovrdflg;
                   /* Referenced by: '<S1075>/vilc_b_flgFctCfgBatCol_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgBatCol_ovrdval;
                   /* Referenced by: '<S1075>/vilc_b_flgFctCfgBatCol_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgBatTyp_ovrdflg;
                   /* Referenced by: '<S1091>/vilc_b_flgFctCfgBatTyp_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgBox_ovrdflg;
                      /* Referenced by: '<S1092>/vilc_b_flgFctCfgBox_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgChgTyp_ovrdflg;
                   /* Referenced by: '<S1076>/vilc_b_flgFctCfgChgTyp_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgChgTyp_ovrdval;
                   /* Referenced by: '<S1076>/vilc_b_flgFctCfgChgTyp_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgCoastActivBrkLight_ovrdflg;
               /* Referenced by: '<S1077>/vilc_b_flgFctCfgDrvModConn_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgCoastActivBrkLight_ovrdval;
               /* Referenced by: '<S1077>/vilc_b_flgFctCfgDrvModConn_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgDrvModConn_ovrdflg;
               /* Referenced by: '<S1079>/vilc_b_flgFctCfgDrvModConn_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgDrvModConn_ovrdval;
               /* Referenced by: '<S1079>/vilc_b_flgFctCfgDrvModConn_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgDrvModStor_ovrdflg;
               /* Referenced by: '<S1080>/vilc_b_flgFctCfgDrvModStor_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgDrvModStor_ovrdval;
               /* Referenced by: '<S1080>/vilc_b_flgFctCfgDrvModStor_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgDrvMod_ovrdflg;
                   /* Referenced by: '<S1078>/vilc_b_flgFctCfgDrvMod_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgDrvMod_ovrdval;
                   /* Referenced by: '<S1078>/vilc_b_flgFctCfgDrvMod_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgDrvSeat_ovrdflg;
                        /* Referenced by: '<S1081>/vilc_b_pepsPduLvl_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgDrvSeat_ovrdval;
                       /* Referenced by: '<S1081>/vilc_st_pepsPduLvl_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgDualAuthN_ovrdflg;
                      /* Referenced by: '<S1082>/vilc_b_flgFctCfgACU_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgDualAuthN_ovrdval;
                      /* Referenced by: '<S1082>/vilc_b_flgFctCfgACU_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgECOMaxSpd_ovrdflg;
                /* Referenced by: '<S1094>/vilc_b_flgFctCfgECOMaxSpd_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgEpdel_ovrdflg;
                        /* Referenced by: '<S1083>/vilc_b_pepsPduLvl_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgEpdel_ovrdval;
                       /* Referenced by: '<S1083>/vilc_st_pepsPduLvl_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgFan_ovrdflg;
                   /* Referenced by: '<S1095>/vilc_b_flgFctCfgFanPwr_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgMaxChgCurr_ovrdflg;
                        /* Referenced by: '<S1084>/vilc_b_pepsPduLvl_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgMaxChgCurr_ovrdval;
                       /* Referenced by: '<S1084>/vilc_st_pepsPduLvl_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgMaxSpd_ovrdflg;
                        /* Referenced by: '<S1096>/vilc_b_pepsPduLvl_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgMotTyp_ovrdflg;
                   /* Referenced by: '<S1097>/vilc_b_flgFctCfgMotTyp_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgMotor_ovrdflg;
                        /* Referenced by: '<S1085>/vilc_b_pepsPduLvl_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgMotor_ovrdval;
                       /* Referenced by: '<S1085>/vilc_st_pepsPduLvl_ovrdval' */
extern const volatile boolean vilc_b_flgFctCfgNormalMaxSpd_ovrdflg;
             /* Referenced by: '<S1098>/vilc_b_flgFctCfgNormalMaxSpd_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgPowerMaxSpd_ovrdflg;
              /* Referenced by: '<S1099>/vilc_b_flgFctCfgPowerMaxSpd_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgSlowChg_ovrdflg;
                  /* Referenced by: '<S1100>/vilc_b_flgFctCfgSlowChg_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgTyre_ovrdflg;
                     /* Referenced by: '<S1086>/vilc_b_flgFctCfgTyre_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgV2L_ovrdflg;
                        /* Referenced by: '<S1101>/vilc_b_pepsPduLvl_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgVehCfg_ovrdflg;
                   /* Referenced by: '<S1102>/vilc_b_flgFctCfgVehCfg_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgVehTyp_ovrdflg;
                        /* Referenced by: '<S1103>/vilc_b_pepsPduLvl_ovrdflg' */
extern const volatile boolean vilc_b_flgFctCfgVehUsg_ovrdflg;
                   /* Referenced by: '<S1104>/vilc_b_flgFctCfgVehUsg_ovrdflg' */
extern const volatile boolean vilc_b_flgFnctnConfgEHB_ovrdflg;
                        /* Referenced by: '<S1087>/vilc_b_pepsPduLvl_ovrdflg' */
extern const volatile boolean vilc_b_flgFnctnConfgEHB_ovrdval;
                       /* Referenced by: '<S1087>/vilc_st_pepsPduLvl_ovrdval' */
extern const volatile boolean vilc_b_flgNetConfgABS_ovrdflg;
               /* Referenced by: '<S1088>/vilc_b_flgFctCfgDrvModConn_ovrdflg' */
extern const volatile boolean vilc_b_flgNetConfgABS_ovrdval;
               /* Referenced by: '<S1088>/vilc_b_flgFctCfgDrvModConn_ovrdval' */
extern const volatile boolean vilc_b_frontAirTankPressure_ovrdflg;
              /* Referenced by: '<S1025>/vilc_b_frontAirTankPressure_ovrdflg' */

/* Override flag for IC_FrontAirTankPressure */
extern const volatile boolean vilc_b_hcmAccConnStsFb_ovrdflg;
                    /* Referenced by: '<S713>/vilc_b_hcmAccConnStsFb_ovrdflg' */
extern const volatile boolean vilc_b_hcmAcceRlyVoltVldSts_ovrdflg;
               /* Referenced by: '<S704>/vilc_b_hcmAcceRlyVoltVldSts_ovrdflg' */
extern const volatile boolean vilc_b_hcmAcceRlyVoltVldSts_ovrdval;
               /* Referenced by: '<S704>/vilc_b_hcmAcceRlyVoltVldSts_ovrdval' */
extern const volatile boolean vilc_b_hcmAcceRlyVolt_ovrdflg;
                     /* Referenced by: '<S726>/vilc_b_hcmAcceRlyVolt_ovrdflg' */
extern const volatile boolean vilc_b_hcmCutOffLvFb_ovrdflg;
                    /* Referenced by: '<S714>/vilc_flg_hcmCutOffLvFb_ovrdflg' */

/* Override flag for signal b_hcmCutOffLvFb */
extern const volatile boolean vilc_b_hcmFltLvl_ovrdflg;
                        /* Referenced by: '<S715>/vilc_flg_hcmFltLvl_ovrdflg' */

/* Override flag for signal b_hcmFltLvl */
extern const volatile boolean vilc_b_hcmHvilSt_ovrdflg;
                        /* Referenced by: '<S716>/vilc_flg_hcmHvilSt_ovrdflg' */

/* Override flag for signal b_hcmHvilSt */
extern const volatile boolean vilc_b_hcmMainPosBckVoltVldSts_ovrdflg;
            /* Referenced by: '<S705>/vilc_b_hcmMainPosBckVoltVldSts_ovrdflg' */
extern const volatile boolean vilc_b_hcmMainPosBckVoltVldSts_ovrdval;
            /* Referenced by: '<S705>/vilc_b_hcmMainPosBckVoltVldSts_ovrdval' */
extern const volatile boolean vilc_b_hcmMainPosBckVolt_ovrdflg;
                  /* Referenced by: '<S727>/vilc_b_hcmMainPosBckVolt_ovrdflg' */
extern const volatile boolean vilc_b_hcmPTC1ConnStsFb_ovrdflg;
                   /* Referenced by: '<S717>/vilc_b_hcmPTC1ConnStsFb_ovrdflg' */
extern const volatile boolean vilc_b_hcmPtcDefRlyStFb_ovrdflg;
                 /* Referenced by: '<S718>/vilc_flg_hcmPtcDefRlyStFb_ovrdflg' */

/* Override flag for signal b_hcmPtcDefRlyStFb */
extern const volatile boolean vilc_b_hcmPtcRlyVoltVldSts_ovrdflg;
                /* Referenced by: '<S706>/vilc_b_hcmPtcRlyVoltVldSts_ovrdflg' */
extern const volatile boolean vilc_b_hcmPtcRlyVoltVldSts_ovrdval;
                /* Referenced by: '<S706>/vilc_b_hcmPtcRlyVoltVldSts_ovrdval' */
extern const volatile boolean vilc_b_hcmPtcRlyVolt_ovrdflg;
                      /* Referenced by: '<S728>/vilc_b_hcmPtcRlyVolt_ovrdflg' */
extern const volatile boolean vilc_b_hcmPwrActvMod_ovrdflg;
                    /* Referenced by: '<S719>/vilc_flg_hcmPwrActvMod_ovrdflg' */

/* Override flag for signal b_hcmPwrActvMod */
extern const volatile boolean vilc_b_hcmSelfChk_ovrdflg;
                       /* Referenced by: '<S720>/vilc_flg_hcmSelfChk_ovrdflg' */

/* Override flag for signal b_hcmSelfChk */
extern const volatile boolean vilc_b_hcmWrkSt_ovrdflg;
                         /* Referenced by: '<S721>/vilc_flg_hcmWrkSt_ovrdflg' */

/* Override flag for signal b_hcmWrkSt */
extern const volatile boolean vilc_b_hillStrtAssi_ovrdflg;
                       /* Referenced by: '<S696>/vilc_b_hillStrtAssi_ovrdflg' */

/* Override flag for signal b_hillStrtAssi */
extern const volatile boolean vilc_b_hndBrk_invert;
                       /* Referenced by: '<S992>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for b_hndBrk_invert */
extern const volatile boolean vilc_b_hvbAvg_ovrdflg;
                           /* Referenced by: '<S817>/vilc_flg_hvbAvg_ovrdflg' */

/* Override flag for signal b_hvbAvg */
extern const volatile boolean vilc_b_hvbBatUniformity_ovrdflg;
                   /* Referenced by: '<S785>/vilc_b_hvbBatUniformity_ovrdflg' */
extern const volatile boolean vilc_b_hvbBmsHwFlt_ovrdflg;
                      /* Referenced by: '<S787>/vilc_flg_hvbBmsHwFlt_ovrdflg' */

/* Override flag for signal b_hvbBmsHwFlt */
extern const volatile boolean vilc_b_hvbCellMaxID_ovrdflg;
                        /* Referenced by: '<S766>/vilc_flg_hvbChgSts_ovrdflg' */
extern const volatile boolean vilc_b_hvbCellMinID_ovrdflg;
                     /* Referenced by: '<S767>/vilc_b_hvbDCChgCurReq_ovrdflg' */
extern const volatile boolean vilc_b_hvbCellSum_ovrdflg;
                   /* Referenced by: '<S768>/vilc_flg_num_hvbCellSum_ovrdflg' */
extern const volatile boolean vilc_b_hvbCellTempDevFlt_ovrdflg;
                /* Referenced by: '<S788>/vilc_flg_hvbCellTempDevFlt_ovrdflg' */

/* Override flag for signal b_hvbCellTempDevFlt */
extern const volatile boolean vilc_b_hvbCellVoltDevFlt_ovrdflg;
                /* Referenced by: '<S789>/vilc_flg_hvbCellVoltDevFlt_ovrdflg' */

/* Override flag for signal b_hvbCellVoltDevFlt */
extern const volatile boolean vilc_b_hvbChgCcsts_ovrdflg;
                        /* Referenced by: '<S790>/vilc_b_hvbChgCcsts_ovrdflg' */
extern const volatile boolean vilc_b_hvbChgFltReq_ovrdflg;
                     /* Referenced by: '<S791>/vilc_flg_hvbChgFltReq_ovrdflg' */
extern const volatile boolean vilc_b_hvbChgOvrCurr_ovrdflg;
                    /* Referenced by: '<S792>/vilc_flg_hvbChgOvrCurr_ovrdflg' */
extern const volatile boolean vilc_b_hvbChgSts_ovrdflg;
                        /* Referenced by: '<S794>/vilc_flg_hvbChgSts_ovrdflg' */
extern const volatile boolean vilc_b_hvbCooltInSnsr_ovrdflg;
                               /* Referenced by: '<S1001>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal hvbCooltInSnsr */
extern const volatile boolean vilc_b_hvbCooltInTemp_ovrdflg;
                                /* Referenced by: '<S980>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal hvbCooltInTemp */
extern const volatile boolean vilc_b_hvbCooltOutSnsr_ovrdflg;
                               /* Referenced by: '<S1002>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal hvbCooltOutSnsr */
extern const volatile boolean vilc_b_hvbCooltOutTemp_ovrdflg;
                                /* Referenced by: '<S981>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal hvbCooltOutTemp */
extern const volatile boolean vilc_b_hvbCurr_ovrdflg;
                          /* Referenced by: '<S762>/vilc_flg_hvbCurr_ovrdflg' */

/* Override flag for signal b_hvbCurr */
extern const volatile boolean vilc_b_hvbDCChgCurReqRngUp_ovrdflg;
                /* Referenced by: '<S757>/vilc_b_hvbDCChgCurReqRngUp_ovrdflg' */
extern const volatile boolean vilc_b_hvbDCChgCurReqRngUp_ovrdval;
                /* Referenced by: '<S757>/vilc_b_hvbDCChgCurReqRngUp_ovrdval' */
extern const volatile boolean vilc_b_hvbDCChgCurReq_ovrdflg;
                     /* Referenced by: '<S763>/vilc_b_hvbDCChgCurReq_ovrdflg' */
extern const volatile boolean vilc_b_hvbDCChgPlgNOvrTmp_ovrdflg;
               /* Referenced by: '<S795>/vilc_flg_hvbDCChgPlgNOvrTmp_ovrdflg' */
extern const volatile boolean vilc_b_hvbDCChgPlgPOvrTmp_ovrdflg;
               /* Referenced by: '<S902>/vilc_flg_hvbDCChgPlgPOvrTmp_ovrdflg' */
extern const volatile boolean vilc_b_hvbDCChgProcss_ovrdflg;
                   /* Referenced by: '<S796>/vilc_flg_hvbDCChgProcss_ovrdflg' */
extern const volatile boolean vilc_b_hvbDisChgSopRngUp_ovrdflg;
                  /* Referenced by: '<S758>/vilc_b_hvbDisChgSopRngUp_ovrdflg' */
extern const volatile boolean vilc_b_hvbDisChgSopRngUp_ovrdval;
                  /* Referenced by: '<S758>/vilc_b_hvbDisChgSopRngUp_ovrdval' */
extern const volatile boolean vilc_b_hvbDischgFltReq_ovrdflg;
                  /* Referenced by: '<S797>/vilc_flg_hvbDischgFltReq_ovrdflg' */
extern const volatile boolean vilc_b_hvbEmgyCutOffReq_ovrdflg;
                 /* Referenced by: '<S798>/vilc_flg_hvbEmgyCutOffReq_ovrdflg' */

/* Override flag for signal b_hvbEmgyCutOffReq */
extern const volatile boolean vilc_b_hvbFltSt_ovrdflg;
                         /* Referenced by: '<S799>/vilc_flg_hvbFltSt_ovrdflg' */

/* Override flag for signal b_hvbFltSt */
extern const volatile boolean vilc_b_hvbFnshChgTim_ovrdflg;
                    /* Referenced by: '<S822>/vilc_flg_hvbFnshChgTim_ovrdflg' */
extern const volatile boolean vilc_b_hvbHeatSts_ovrdflg;
                        /* Referenced by: '<S801>/vilc_flg_hvbELkSts_ovrdflg' */

/* Override flag for signal hvbHeatSts */
extern const volatile boolean vilc_b_hvbHvilSts_ovrdflg;
                       /* Referenced by: '<S802>/vilc_flg_hvbHvilSts_ovrdflg' */

/* Override flag for signal b_hvbHvilSts */
extern const volatile boolean vilc_b_hvbInCoolTemp_ovrdflg;
                       /* Referenced by: '<S803>/vilc_flg_hvbTempFlt_ovrdflg' */

/* Override flag for signal hvbInCoolTemp */
extern const volatile boolean vilc_b_hvbInPositionDetct1_ovrdflg;
                    /* Referenced by: '<S958>/vilc_flg_acHvilPrdInpt_ovrdflg' */
extern const volatile boolean vilc_b_hvbInPositionDetct1_ovrdval;
                     /* Referenced by: '<S958>/vilc_fq_acHvilPrdInpt_ovrdval' */
extern const volatile boolean vilc_b_hvbInPositionDetct2_ovrdflg;
                   /* Referenced by: '<S959>/vilc_flg_odpHvilDtyInpt_ovrdflg' */
extern const volatile boolean vilc_b_hvbInPositionDetct2_ovrdval;
                   /* Referenced by: '<S959>/vilc_pct_odpHvilDtyInpt_ovrdval' */
extern const volatile boolean vilc_b_hvbInslErr1_ovrdflg;
                      /* Referenced by: '<S786>/vilc_flg_hvbInslErr1_ovrdflg' */

/* Override flag for signal b_hvbInslErr1 */
extern const volatile boolean vilc_b_hvbInslErr2_ovrdflg;
                      /* Referenced by: '<S800>/vilc_flg_hvbInslErr2_ovrdflg' */

/* Override flag for signal b_hvbInslErr2 */
extern const volatile boolean vilc_b_hvbInslErr3_ovrdflg;
                      /* Referenced by: '<S804>/vilc_flg_hvbInslErr3_ovrdflg' */

/* Override flag for signal b_hvbInslErr3 */
extern const volatile boolean vilc_b_hvbMaiRlyNeg_ovrdflg;
                     /* Referenced by: '<S805>/vilc_flg_hvbMaiRlyNeg_ovrdflg' */

/* Override flag for signal b_hvbMaiRlyNeg */
extern const volatile boolean vilc_b_hvbMaiRlyPos_ovrdflg;
                     /* Referenced by: '<S722>/vilc_flg_hvbMaiRlyPos_ovrdflg' */

/* Override flag for signal b_hvbMaiRlyPos */
extern const volatile boolean vilc_b_hvbMaxContChgPwr_ovrdflg;
                   /* Referenced by: '<S772>/vilc_b_hvbMaxContChgPwr_ovrdflg' */

/* Override flag for signal hvbMaxContChgPwr */
extern const volatile boolean vilc_b_hvbMaxPeakChgPwr_ovrdflg;
                   /* Referenced by: '<S773>/vilc_b_hvbMaxPeakChgPwr_ovrdflg' */

/* Override flag for signal hvbMaxPeakChgPwr */
extern const volatile boolean vilc_b_hvbMaxPeakDischPwr_ovrdflg;
                 /* Referenced by: '<S774>/vilc_b_hvbMaxPeakDischPwr_ovrdflg' */

/* Override flag for signal hvbMaxPeakDischPwr */
extern const volatile boolean vilc_b_hvbMaxPrmtDischCurr_ovrdflg;
              /* Referenced by: '<S764>/vilc_flg_hvbMaxPrmtDischCurr_ovrdflg' */

/* Override flag for signal b_hvbMaxPrmtDischCurr */
extern const volatile boolean vilc_b_hvbMaxPrmtRgnCurr_ovrdflg;
                /* Referenced by: '<S765>/vilc_flg_hvbMaxPrmtRgnCurr_ovrdflg' */

/* Override flag for signal b_hvbMaxPrmtRgnCurr */
extern const volatile boolean vilc_b_hvbMaxTempID_ovrdflg;
                        /* Referenced by: '<S769>/vilc_flg_hvbChgSts_ovrdflg' */
extern const volatile boolean vilc_b_hvbMax_ovrdflg;
                           /* Referenced by: '<S818>/vilc_flg_hvbMax_ovrdflg' */

/* Override flag for signal b_hvbMax */
extern const volatile boolean vilc_b_hvbMinTempId_ovrdflg;
                     /* Referenced by: '<S770>/vilc_b_hvbDCChgCurReq_ovrdflg' */
extern const volatile boolean vilc_b_hvbMin_ovrdflg;
                           /* Referenced by: '<S819>/vilc_flg_hvbMin_ovrdflg' */

/* Override flag for signal b_hvbMin */
extern const volatile boolean vilc_b_hvbOutCoolTemp_ovrdflg;
                     /* Referenced by: '<S820>/vilc_b_hvbOutCoolTemp_ovrdflg' */

/* Override flag for signal BMS_BattPackOutCoolTemp */
extern const volatile boolean vilc_b_hvbOvrChgFlt_ovrdflg;
                     /* Referenced by: '<S806>/vilc_flg_hvbOvrChgFlt_ovrdflg' */

/* Override flag for signal b_hvbOvrChgFlt */
extern const volatile boolean vilc_b_hvbPackRemnEgy_ovrdflg;
                   /* Referenced by: '<S754>/vilc_flg_hvbPackRemnEgy_ovrdflg' */

/* Override flag for signal b_hvbPackRemnEgy */
extern const volatile boolean vilc_b_hvbPackVolt_ovrdflg;
                      /* Referenced by: '<S825>/vilc_flg_hvbPackVolt_ovrdflg' */

/* Override flag for signal b_hvbVolt */
extern const volatile boolean vilc_b_hvbPreChgSts_ovrdflg;
                        /* Referenced by: '<S807>/vilc_b_batOvrVolt2_ovrdflg' */
extern const volatile boolean vilc_b_hvbPrmtCutOffLvFb_ovrdflg;
                /* Referenced by: '<S808>/vilc_flg_hvbPrmtCutOffLvFb_ovrdflg' */

/* Override flag for signal b_hvbPrmtCutOffLvFb */
extern const volatile boolean vilc_b_hvbPwrActvMod_ovrdflg;
                    /* Referenced by: '<S809>/vilc_flg_hvbPwrActvMod_ovrdflg' */

/* Override flag for signal b_hvbPwrActvMod */
extern const volatile boolean vilc_b_hvbSOC01_ovrdflg;
                         /* Referenced by: '<S776>/vilc_flg_hvbSOC01_ovrdflg' */

/* Override flag for signal b_hvbSOC01 */
extern const volatile boolean vilc_b_hvbSOC_ovrdflg;
                           /* Referenced by: '<S775>/vilc_flg_hvbSOC_ovrdflg' */

/* Override flag for signal b_hvbSOC */
extern const volatile boolean vilc_b_hvbSOH_ovrdflg;
                           /* Referenced by: '<S761>/vilc_flg_hvbSOH_ovrdflg' */

/* Override flag for signal b_hvbSOH */
extern const volatile boolean vilc_b_hvbSelfChkSt_ovrdflg;
                     /* Referenced by: '<S759>/vilc_flg_hvbSelfChkSt_ovrdflg' */

/* Override flag for signal b_hvbSelfChkSt */
extern const volatile uint8 vilc_b_hvbSelfChkSt_ovrdval;
                       /* Referenced by: '<S759>/vilc_b_hvbSelfChkSt_ovrdval' */

/* Override value for signal b_hvbSelfChkSt */
extern const volatile boolean vilc_b_hvbSetTgtTemp_ovrdflg;
                      /* Referenced by: '<S821>/vilc_b_hvbSetTgtTemp_ovrdflg' */

/* Override flag for signal BMS_SetTgtTemp */
extern const volatile boolean vilc_b_hvbSocFlt_ovrdflg;
                        /* Referenced by: '<S810>/vilc_flg_hvbSocFlt_ovrdflg' */

/* Override flag for signal b_hvbSocFlt */
extern const volatile boolean vilc_b_hvbSocJumpFlt_ovrdflg;
                    /* Referenced by: '<S811>/vilc_flg_hvbSocJumpFlt_ovrdflg' */

/* Override flag for signal b_hvbSocJumpFlt */
extern const volatile boolean vilc_b_hvbStatus1_ovrdflg;
                       /* Referenced by: '<S793>/vilc_flg_hvbStatus1_ovrdflg' */

/* Override flag for signal b_hvbStatus1 */
extern const volatile boolean vilc_b_hvbStatus2_ovrdflg;
                       /* Referenced by: '<S778>/vilc_flg_hvbStatus2_ovrdflg' */

/* Override flag for signal b_hvbStatus2 */
extern const volatile boolean vilc_b_hvbStsChgFlt_ovrdflg;
                       /* Referenced by: '<S812>/vilc_b_hvbStsChgFlt_ovrdflg' */
extern const volatile boolean vilc_b_hvbStsDischgFlt_ovrdflg;
                    /* Referenced by: '<S813>/vilc_b_hvbStsDischgFlt_ovrdflg' */
extern const volatile boolean vilc_b_hvbSubFaultSts_ovrdflg;
                     /* Referenced by: '<S814>/vilc_b_hvbSubFaultSts_ovrdflg' */

/* Override flag for signal BMS_SubFltLevel */
extern const volatile boolean vilc_b_hvbTempFlt_ovrdflg;
                       /* Referenced by: '<S815>/vilc_flg_hvbTempFlt_ovrdflg' */

/* Override flag for signal b_hvbTempFlt */
extern const volatile boolean vilc_b_hvbTempSum_ovrdflg;
                   /* Referenced by: '<S771>/vilc_flg_hvbPackRemnEgy_ovrdflg' */
extern const volatile boolean vilc_b_hvbThermMngReq_ovrdflg;
                   /* Referenced by: '<S816>/vilc_flg_hvbThermMngReq_ovrdflg' */

/* Override flag for signal b_hvbThermMngReq */
extern const volatile boolean vilc_b_hvbVolt_ovrdflg;
                          /* Referenced by: '<S826>/vilc_flg_hvbVolt_ovrdflg' */

/* Override flag for signal b_hvbVolt */
extern const volatile boolean vilc_b_hvbZeroPwrReq_ovrdflg;
                      /* Referenced by: '<S760>/vilc_b_hvbZeroPwrReq_ovrdflg' */
extern const volatile uint8 vilc_b_hvbZeroPwrReq_ovrdval;
                      /* Referenced by: '<S760>/vilc_b_hvbZeroPwrReq_ovrdval' */
extern const volatile boolean vilc_b_inv2SubFltSts_ovrdflg;
                      /* Referenced by: '<S641>/vilc_b_inv2SubFltSts_ovrdflg' */

/* Override flag for signal MCU_MotorSubFltLevel */
extern const volatile boolean vilc_b_ipkAlwChgSftCtlSt_ovrdflg;
                 /* Referenced by: '<S1148>/vilc_b_ipkAlwChgSftCtlSt_ovrdflg' */
extern const volatile boolean vilc_b_ipkChgSftSwCtlSt_ovrdflg;
                  /* Referenced by: '<S1036>/vilc_b_ipkChgSftSwCtlSt_ovrdflg' */
extern const volatile boolean vilc_b_ipkCruisingDstSwt_ovrdflg;
               /* Referenced by: '<S1037>/vilc_flg_ipkCruisingDstSwt_ovrdflg' */
extern const volatile boolean vilc_b_ipkOdoBckUpEn_ovrdflg;
                   /* Referenced by: '<S1030>/vilc_flg_ipkOdoBckUpEn_ovrdflg' */
extern const volatile boolean vilc_b_ipkOdoBckUpEn_ovrdval;
                     /* Referenced by: '<S1030>/vilc_b_ipkOdoBckUpEn_ovrdval' */
extern const volatile boolean vilc_b_ipkOdometerbackup_ovrdflg;
                 /* Referenced by: '<S1033>/vilc_b_ipkOdometerbackup_ovrdflg' */
extern const volatile boolean vilc_b_iptActPwr_ovrdflg;
                          /* Referenced by: '<S350>/vilc_b_iptActPwr_ovrdflg' */
extern const volatile boolean vilc_b_iptWorkSt_ovrdflg;
                          /* Referenced by: '<S359>/vilc_b_iptWorkSt_ovrdflg' */
extern const volatile boolean vilc_b_ipuHVBusVolt_ovrdflg;
                     /* Referenced by: '<S651>/vilc_flg_ipuHVBusVolt_ovrdflg' */
extern const volatile boolean vilc_b_ipuInvTempHighAlm_ovrdflg;
                  /* Referenced by: '<S642>/vilc_b_ipuInvTempHighAlm_ovrdflg' */
extern const volatile boolean vilc_b_ipuIsgSpdActSgnInvld_ovrdflg;
               /* Referenced by: '<S616>/vilc_b_ipuIsgSpdActSgnInvld_ovrdflg' */
extern const volatile boolean vilc_b_ipuIsgSpdActSgnInvld_ovrdval;
               /* Referenced by: '<S616>/vilc_b_ipuIsgSpdActSgnInvld_ovrdval' */
extern const volatile boolean vilc_b_ipuMotTempHighFlt_ovrdflg;
                  /* Referenced by: '<S643>/vilc_b_ipuMotTempHighFlt_ovrdflg' */
extern const volatile boolean vilc_b_ipuMotorOverCurrFlt_ovrdflg;
                /* Referenced by: '<S723>/vilc_b_ipuMotorOverCurrFlt_ovrdflg' */
extern const volatile boolean vilc_b_ipuMotorOverSpdFlt_ovrdflg;
                 /* Referenced by: '<S724>/vilc_b_ipuMotorOverSpdFlt_ovrdflg' */
extern const volatile boolean vilc_b_ipuMotorSubFltLvl_ovrdflg;
                /* Referenced by: '<S644>/vilc_flg_ipuMotorSubFltLvl_ovrdflg' */
extern const volatile boolean vilc_b_lowPresRelsPrkLim_ovrdflg;
                  /* Referenced by: '<S697>/vilc_b_lowPresRelsPrkLim_ovrdflg' */

/* Override flag for signal b_lowPresRelsPrkLim */
extern const volatile boolean vilc_b_mmiLocBkChgTarVal_ovrdflg;
                  /* Referenced by: '<S707>/vilc_b_mmiLocBkChgTarVal_ovrdflg' */

/* Override flag for signal MMI_LocalBookChrgnTarVal */
extern const volatile boolean vilc_b_mmiRestSwitch_ovrdflg;
                      /* Referenced by: '<S725>/vilc_b_mmiRestSwitch_ovrdflg' */
extern const volatile boolean vilc_b_obcChgCCSts_ovrdflg;
                       /* Referenced by: '<S1149>/vilc_b_obcChgCCSts_ovrdflg' */
extern const volatile boolean vilc_b_obcChgSts_ovrdflg;
                         /* Referenced by: '<S1150>/vilc_b_obcChgSts_ovrdflg' */
extern const volatile boolean vilc_b_obcElckStMod_ovrdflg;
                      /* Referenced by: '<S1151>/vilc_b_obcElckStMod_ovrdflg' */
extern const volatile boolean vilc_b_obcLockLoopSts_ovrdflg;
                    /* Referenced by: '<S1152>/vilc_b_obcLockLoopSts_ovrdflg' */

/* Override flag for signal OBC_LockLoopSts */
extern const volatile boolean vilc_b_obcOnBdCCline_ovrdflg;
                     /* Referenced by: '<S1153>/vilc_b_obcOnBdCCline_ovrdflg' */
extern const volatile boolean vilc_b_obcOnBdCPline_ovrdflg;
                     /* Referenced by: '<S1154>/vilc_b_obcOnBdCPline_ovrdflg' */
extern const volatile boolean vilc_b_obcOnBdDchaCCline_ovrdflg;
                     /* Referenced by: '<S1155>/vilc_b_obcOnBdCCline_ovrdflg' */
extern const volatile boolean vilc_b_obcOutptCurr_ovrdflg;
                    /* Referenced by: '<S1146>/vilc_flg_obcOutptCurr_ovrdflg' */
extern const volatile boolean vilc_b_obcOutptVolt_ovrdflg;
                      /* Referenced by: '<S1159>/vilc_b_obcOutptVolt_ovrdflg' */
extern const volatile boolean vilc_b_obcPwrEgyMgrAvl_ovrdflg;
                   /* Referenced by: '<S1147>/vilc_b_obcPwrEgyMgrAvl_ovrdflg' */
extern const volatile boolean vilc_b_obcSelfChk_ovrdflg;
                      /* Referenced by: '<S1156>/vilc_flag_dcChgCcSt_ovrdflg' */

/* Override flag for signal obcSelfChk */
extern const volatile boolean vilc_b_obcTemp_ovrdflg;
                           /* Referenced by: '<S1158>/vilc_b_obcTemp_ovrdflg' */
extern const volatile boolean vilc_b_obcWakeHCU_ovrdflg;
                        /* Referenced by: '<S1003>/vilc_b_obcWakeHCU_ovrdflg' */

/* Override flag for signal b_obcWakeHCU */
extern const volatile boolean vilc_b_obcWkUp_invert;
                      /* Referenced by: '<S1003>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for b_obcWkUp_invert */
extern const volatile boolean vilc_b_obcfltLvl_ovrdflg;
                      /* Referenced by: '<S1157>/vilc_flag_dcChgCcSt_ovrdflg' */

/* Override flag for signal obcfltLvl */
extern const volatile boolean vilc_b_odometer_ovrdflg;
                          /* Referenced by: '<S1034>/vilc_b_odometer_ovrdflg' */

/* Override flag for signal IC_Odometer */
extern const volatile boolean vilc_b_odpHvilDtyInpt_ovrdflg;
                   /* Referenced by: '<S975>/vilc_flg_odpHvilDtyInpt_ovrdflg' */
extern const volatile boolean vilc_b_odpHvilPrdInpt_ovrdflg;
                   /* Referenced by: '<S966>/vilc_flg_odpHvilPrdInpt_ovrdflg' */
extern const volatile boolean vilc_b_outdTemp_ovrdflg;
                         /* Referenced by: '<S363>/vilc_flg_outdTemp_ovrdflg' */

/* Override flag for signal b_outdTemp */
extern const volatile boolean vilc_b_pdcBrkFlg_ovrdflg;
                         /* Referenced by: '<S1294>/vilc_b_pdcBrkFlg_ovrdflg' */
extern const volatile boolean vilc_b_pdcBrkFlg_ovrdval;
                         /* Referenced by: '<S1294>/vilc_b_pdcBrkFlg_ovrdval' */
extern const volatile boolean vilc_b_pdcStsInfoCtrAlvCtrErr_ovrdflg;
            /* Referenced by: '<S1295>/vilc_b_pdcStsInfoCtrAlvCtrErr_ovrdflg' */
extern const volatile boolean vilc_b_pdcStsInfoCtrCsmErr_ovrdflg;
               /* Referenced by: '<S1296>/vilc_b_pdcStsInfoCtrCsmErr_ovrdflg' */
extern const volatile boolean vilc_b_pepsMsgErrSet_ovrdflg;
                     /* Referenced by: '<S1182>/vilc_b_pepsMsgErrSet_ovrdflg' */
extern const volatile boolean vilc_b_pepsMsgErrSet_ovrdval;
                     /* Referenced by: '<S1182>/vilc_b_pepsMsgErrSet_ovrdval' */
extern const volatile boolean vilc_b_pepsON_invert;
                      /* Referenced by: '<S1004>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for b_pepsON_invert */
extern const volatile boolean vilc_b_pepsON_ovrdflg;
                            /* Referenced by: '<S1004>/vilc_b_pepsON_ovrdflg' */

/* Override flag for signal b_pepsON */
extern const volatile boolean vilc_b_pepsOnSwtSt_ovrdflg;
                      /* Referenced by: '<S960>/vilc_flg_pepsOnSwtSt_ovrdflg' */
extern const volatile boolean vilc_b_pepsOnSwtSt_ovrdval;
                        /* Referenced by: '<S960>/vilc_b_pepsOnSwtSt_ovrdval' */
extern const volatile boolean vilc_b_pepsOnmV_ovrdflg;
                    /* Referenced by: '<S1005>/vilc_b_WatPmpEP2FbPWM_ovrdflg' */

/* Override flag for signal u_pepsOn */
extern const volatile boolean vilc_b_pepsPduLvlVld_ovrdflg;
                        /* Referenced by: '<S1184>/vilc_b_pepsPduLvl_ovrdflg' */

/* Override flag for signal pepsPduLvlVld */
extern const volatile boolean vilc_b_pepsPduLvlVld_ovrdval;
                       /* Referenced by: '<S1184>/vilc_st_pepsPduLvl_ovrdval' */

/* Override value for signal pepsPduLvlVld */
extern const volatile boolean vilc_b_pepsPduLvl_ovrdflg;
                        /* Referenced by: '<S1185>/vilc_b_pepsPduLvl_ovrdflg' */

/* Override flag for signal pepsPduLvl */
extern const volatile boolean vilc_b_pepsRKECom_ovrdflg;
                        /* Referenced by: '<S1186>/vilc_b_pepsRKECom_ovrdflg' */
extern const volatile boolean vilc_b_pepsRmtCtrlSt_ovrdflg;
                     /* Referenced by: '<S1183>/vilc_b_pepsRmtCtrlSt_ovrdflg' */
extern const volatile boolean vilc_b_pepsRmtCtrlSt_ovrdval;
                     /* Referenced by: '<S1183>/vilc_b_pepsRmtCtrlSt_ovrdval' */
extern const volatile boolean vilc_b_pepsStart_ovrdflg;
                         /* Referenced by: '<S1006>/vilc_b_pepsStart_ovrdflg' */

/* Override flag for signal b_pepsStart */
extern const volatile boolean vilc_b_pepsStt_invert;
                      /* Referenced by: '<S1006>/vilc_b_ResrAirSwitch_invert' */

/* Invert flag for b_pepsStt_invert */
extern const volatile boolean vilc_b_pepsTrqCtrlCounterError_ovrdflg;/* Referenced by:
                                                                      * '<S1187>/vilc_b_pepsTrqCtrlCounterError_ovrdflg'
                                                                      * '<S1188>/vilc_b_pepsTrqCtrlCounterError_ovrdflg'
                                                                      * '<S272>/vilc_b_pepsTrqCtrlCounterError_ovrdflg'
                                                                      */
extern const volatile boolean vilc_b_pepsTrqCtrlCounterError_ovrdval;/* Referenced by:
                                                                      * '<S1187>/vilc_b_pepsTrqCtrlCounterError_ovrdval'
                                                                      * '<S1188>/vilc_b_pepsTrqCtrlCounterError_ovrdval'
                                                                      * '<S272>/vilc_b_pepsTrqCtrlCounterError_ovrdval'
                                                                      */
extern const volatile boolean vilc_b_pmsCANBusOffFlg_ovrdflg;
                  /* Referenced by: '<S431>/vilc_flg_pmsCANBusOffFlg_ovrdflg' */
extern const volatile boolean vilc_b_pmsCANBusOffFlg_ovrdval;
                    /* Referenced by: '<S431>/vilc_b_pmsCANBusOffFlg_ovrdval' */
extern const volatile boolean vilc_b_posInslRes_ovrdflg;
                       /* Referenced by: '<S756>/vilc_flg_posInslRes_ovrdflg' */

/* Override flag for signal b_posInslRes */
extern const volatile boolean vilc_b_prkBrkSts_ovrdflg;
                          /* Referenced by: '<S698>/vilc_b_prkBrkSts_ovrdflg' */

/* Override flag for signal b_prkBrkSts */
extern const volatile boolean vilc_b_ptCanBusOff_invert;
                       /* Referenced by: '<S961>/vilc_b_ResrAirSwitch_invert' */

/* Inversion flag for signal ptCanBusOff */
extern const volatile boolean vilc_b_ptCanBusOff_ovrdflg;
                      /* Referenced by: '<S961>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal ptCanBusOff */
extern const volatile boolean vilc_b_ptCanBusOff_ovrdval;
                      /* Referenced by: '<S961>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal ptCanBusOff */
extern const volatile boolean vilc_b_ptCanNm_ovrdflg;
                                /* Referenced by: '<S978>/vilc_b_Brk_ovrdflg' */

/* Override flag for signal ptCanNm */
extern const volatile boolean vilc_b_ptcActPwrRear_ovrdflg;
                      /* Referenced by: '<S351>/vilc_b_ptcActPwrRear_ovrdflg' */
extern const volatile boolean vilc_b_ptcConnStsFb_ovrdflg;
                     /* Referenced by: '<S360>/vilc_flg_ptcConnStsFb_ovrdflg' */
extern const volatile boolean vilc_b_ptcWorkStRear_ovrdflg;
                      /* Referenced by: '<S361>/vilc_b_ptcWorkStRear_ovrdflg' */
extern const volatile boolean vilc_b_pullUpDiagCmpl_invert;
                       /* Referenced by: '<S962>/vilc_b_ResrAirSwitch_invert' */

/* Inversion flag for signal pullUpDiagCmpl */
extern const volatile boolean vilc_b_pullUpDiagCmpl_ovrdflg;
                      /* Referenced by: '<S962>/vilc_b_ResrAirSwitch_ovrdflg' */

/* Override flag for signal pullUpDiagCmpl */
extern const volatile boolean vilc_b_pullUpDiagCmpl_ovrdval;
                      /* Referenced by: '<S962>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal pullUpDiagCmpl */
extern const volatile boolean vilc_b_rearAirTankPressure_ovrdflg;
               /* Referenced by: '<S1028>/vilc_b_rearAirTankPressure_ovrdflg' */

/* Override flag for IC_RearAirTankPressure */
extern const volatile boolean vilc_b_revModeSwitch_invert;
                       /* Referenced by: '<S963>/vilc_b_revModeSwitch_invert' */

/* Invert flag for signal b_revModeSwitch */
extern const volatile boolean vilc_b_revModeSwitch_ovrdflg;
                      /* Referenced by: '<S963>/vilc_b_revModeSwitch_ovrdflg' */

/* Override flag for signal b_revModeSwitch */
extern const volatile boolean vilc_b_revModeSwitch_ovrdval;
                      /* Referenced by: '<S963>/vilc_b_revModeSwitch_ovrdval' */

/* Override value for signal b_revModeSwitch */
extern const volatile boolean vilc_b_rfrCarLocConfm_ovrdflg;
                  /* Referenced by: '<S1218>/vilc_flg_rfrCarLocConfm_ovrdflg' */
extern const volatile boolean vilc_b_rfrCarLocConfm_ovrdval;
                    /* Referenced by: '<S1218>/vilc_b_rfrCarLocConfm_ovrdval' */
extern const volatile boolean vilc_b_rfrCarStation_ovrdflg;
                   /* Referenced by: '<S1219>/vilc_flg_rfrCarStation_ovrdflg' */
extern const volatile boolean vilc_b_rfrCarStation_ovrdval;
                     /* Referenced by: '<S1219>/vilc_b_rfrCarStation_ovrdval' */
extern const volatile boolean vilc_b_rfrConnctSts_ovrdflg;
                    /* Referenced by: '<S1221>/vilc_flg_rfrConnctSts_ovrdflg' */
extern const volatile boolean vilc_b_rfrSeed_ovrdflg;
                         /* Referenced by: '<S1222>/vilc_flg_rfrSeed_ovrdflg' */
extern const volatile boolean vilc_b_rfrSwapBatCod_ovrdflg;
                   /* Referenced by: '<S1223>/vilc_flg_rfrSwapBatCod_ovrdflg' */
extern const volatile boolean vilc_b_rfrSwapBatReq_ovrdflg;
                   /* Referenced by: '<S1220>/vilc_flg_rfrSwapBatReq_ovrdflg' */
extern const volatile boolean vilc_b_rfrSwapBatReq_ovrdval;
                     /* Referenced by: '<S1220>/vilc_b_rfrSwapBatReq_ovrdval' */
extern const volatile boolean vilc_b_rfrSwapprocd_ovrdflg;
                    /* Referenced by: '<S1224>/vilc_flg_rfrSwapprocd_ovrdflg' */
extern const volatile boolean vilc_b_rstAvgFuelConsumption_ovrdflg;
             /* Referenced by: '<S1031>/vilc_b_rstAvgFuelConsumption_ovrdflg' */

/* Override flag for signal IC_ResetAverageFuelConsumption */
extern const volatile boolean vilc_b_rstAvgFuelConsumption_ovrdval;
             /* Referenced by: '<S1031>/vilc_b_rstAvgFuelConsumption_ovrdval' */

/* Override value for signal IC_ResetAverageFuelConsumption */
extern const volatile boolean vilc_b_rstAvgPwrConsumption_ovrdflg;
              /* Referenced by: '<S1032>/vilc_b_rstAvgPwrConsumption_ovrdflg' */

/* Override flag for signal IC_ResetAveragePowerConsumption */
extern const volatile boolean vilc_b_rstAvgPwrConsumption_ovrdval;
              /* Referenced by: '<S1032>/vilc_b_rstAvgPwrConsumption_ovrdval' */

/* Override value for signal IC_ResetAveragePowerConsumption */
extern const volatile boolean vilc_b_strWhlAng_ovrdflg;
                         /* Referenced by: '<S1212>/vilc_b_strWhlAng_ovrdflg' */

/* Override flag for signal b_eadMot21ActTq */
extern const volatile boolean vilc_b_tboxAlwChgCurrMax_ovrdflg;
               /* Referenced by: '<S1238>/vilc_b_tboxStartBattChgReq_ovrdflg' */
extern const volatile boolean vilc_b_tboxChgDepth_ovrdflg;
                          /* Referenced by: '<S1239>/vilc_b_tboxLife_ovrdflg' */
extern const volatile boolean vilc_b_tboxChgLmtSw_ovrdflg;
            /* Referenced by: '<S1248>/vilc_b_tboxInventorySpdLmtReq_ovrdflg' */
extern const volatile boolean vilc_b_tboxChgSftSwCtlSt_ovrdflg;
            /* Referenced by: '<S1249>/vilc_b_tboxInventorySpdLmtReq_ovrdflg' */
extern const volatile boolean vilc_b_tboxDay_ovrdflg;
                         /* Referenced by: '<S1258>/vilc_flg_tboxDay_ovrdflg' */

/* Override flag for signal b_tboxDay */
extern const volatile boolean vilc_b_tboxElevation_ovrdflg;
                    /* Referenced by: '<S1236>/vilc_el_tboxElevation_ovrdflg' */
extern const volatile boolean vilc_b_tboxHr_ovrdflg;
                          /* Referenced by: '<S1259>/vilc_flg_tboxHr_ovrdflg' */

/* Override flag for signal b_tboxHr */
extern const volatile boolean vilc_b_tboxIntelChgCmd_ovrdval;
                   /* Referenced by: '<S1233>/vilc_b_tboxIntelChgCmd_ovrdval' */

/* Override value for signal vild_flg_tboxIntelChgCmd */
extern const volatile boolean vilc_b_tboxInventorySpdLmtReq_ovrdflg;
            /* Referenced by: '<S1250>/vilc_b_tboxInventorySpdLmtReq_ovrdflg' */

/* Override flag for signal b_tboxInventorySpdLmtReq */
extern const volatile boolean vilc_b_tboxLife_ovrdflg;
                          /* Referenced by: '<S1251>/vilc_b_tboxLife_ovrdflg' */

/* Override flag for signal b_tboxLife */
extern const volatile boolean vilc_b_tboxLockVehPerFlag_ovrdflg;
                /* Referenced by: '<S1252>/vilc_b_tboxLockVehPerFlag_ovrdflg' */

/* Override flag for signal b_tboxLockVehPerFlag */
extern const volatile boolean vilc_b_tboxMins_ovrdflg;
                        /* Referenced by: '<S1260>/vilc_flg_tboxMins_ovrdflg' */

/* Override flag for signal b_tboxMins */
extern const volatile boolean vilc_b_tboxMth_ovrdflg;
                         /* Referenced by: '<S1261>/vilc_flg_tboxMth_ovrdflg' */

/* Override flag for signal b_tboxMth */
extern const volatile boolean vilc_b_tboxPowOffCmd_ovrdflg;
                          /* Referenced by: '<S1234>/vilc_b_tboxLife_ovrdflg' */
extern const volatile boolean vilc_b_tboxPowOffCmd_ovrdval;
                         /* Referenced by: '<S1234>/vilc_st_tboxLife_ovrdval' */
extern const volatile boolean vilc_b_tboxPrtFullSwStUB_ovrdflg;
                          /* Referenced by: '<S1235>/vilc_b_tboxLife_ovrdflg' */
extern const volatile boolean vilc_b_tboxPrtFullSwStUB_ovrdval;
                         /* Referenced by: '<S1235>/vilc_st_tboxLife_ovrdval' */
extern const volatile boolean vilc_b_tboxPrtFullSwSt_ovrdflg;
                          /* Referenced by: '<S1253>/vilc_b_tboxLife_ovrdflg' */
extern const volatile boolean vilc_b_tboxRsrChgSt_ovrdflg;
               /* Referenced by: '<S1254>/vilc_b_tboxStartBattChgReq_ovrdflg' */
extern const volatile boolean vilc_b_tboxSec_ovrdflg;
                         /* Referenced by: '<S1262>/vilc_flg_tboxSec_ovrdflg' */

/* Override flag for signal b_tboxSec */
extern const volatile boolean vilc_b_tboxSpdLmtLevelReq_ovrdflg;
                /* Referenced by: '<S1255>/vilc_b_tboxSpdLmtLevelReq_ovrdflg' */

/* Override flag for signal b_tboxSpdLmtLevelReq */
extern const volatile boolean vilc_b_tboxStartBattChgReq_ovrdflg;
               /* Referenced by: '<S1256>/vilc_b_tboxStartBattChgReq_ovrdflg' */

/* Override flag for signal b_tboxStartBattChgReq */
extern const volatile boolean vilc_b_tboxVersionConversionFlag_ovrdflg;
         /* Referenced by: '<S1257>/vilc_b_tboxVersionConversionFlag_ovrdflg' */

/* Override flag for signal b_tboxVersionConversionFlag */
extern const volatile boolean vilc_b_tboxYr_ovrdflg;
                          /* Referenced by: '<S1263>/vilc_flg_tboxYr_ovrdflg' */

/* Override flag for signal b_tboxYr */
extern const volatile boolean vilc_b_tmpPrkActv_ovrdflg;
                         /* Referenced by: '<S699>/vilc_b_tmpPrkActv_ovrdflg' */

/* Override flag for signal b_tmpPrkActv */
extern const volatile boolean vilc_b_tmpPrkBrkSts_ovrdflg;
                       /* Referenced by: '<S700>/vilc_b_tmpPrkBrkSts_ovrdflg' */

/* Override flag for signal b_tmpPrkBrkSts */
extern const volatile boolean vilc_b_trsm2GearAct_ovrdflg;
                    /* Referenced by: '<S1278>/vilc_flg_trsm2GearAct_ovrdflg' */

/* Override flag for signal TCU_CurrentGear */
extern const volatile boolean vilc_b_trsm2GearShftReq_ovrdflg;
                  /* Referenced by: '<S1279>/vilc_b_trsm2GearShftReq_ovrdflg' */

/* Override flag for signal TCU_Gearshift_Req */
extern const volatile boolean vilc_b_trsm2OutpShaftSpd_ovrdflg;
               /* Referenced by: '<S1277>/vilc_flg_trsm2OutpShaftSpd_ovrdflg' */

/* Override flag for signal TCU_TrsmOutSpd */
extern const volatile boolean vilc_b_trsm2Unauthorized_ovrdflg;
                 /* Referenced by: '<S1280>/vilc_b_trsm2Unauthorized_ovrdflg' */

/* Override flag for signal TCU_unauthorized */
extern const volatile boolean vilc_b_useCPWakeUp;/* Referenced by: '<S16>/Constant1' */

/* Wake up using the CP signal */
extern const volatile boolean vilc_b_vacTankLowPrs_invert;
                       /* Referenced by: '<S964>/vilc_b_ResrAirSwitch_invert' */

/* Inversion flag for signal vacTankLowPrs */
extern const volatile boolean vilc_b_vacTankLowPrs_ovrdflg;
                          /* Referenced by: '<S964>/vilc_b_BrkSwitch_ovrdflg' */

/* Override flag for signal vacTankLowPrs */
extern const volatile boolean vilc_b_vacTankLowPrs_ovrdval;
                          /* Referenced by: '<S964>/vilc_b_BrkSwitch_ovrdval' */

/* Override value for signal vacTankLowPrs */
extern const volatile boolean vilc_b_vacTkPowSup_ovrdflg;
                       /* Referenced by: '<S1007>/vilc_b_vacTkPowSup_ovrdflg' */
extern const volatile boolean vilc_b_vehCrashStsDuty_ovrdflg;
                          /* Referenced by: '<S976>/vilc_b_BrkSwitch_ovrdflg' */

/* Override flag for signal vehCrashStsDuty */
extern const volatile boolean vilc_b_vehCrashStsFreq_ovrdflg;
                    /* Referenced by: '<S967>/vilc_b_vehCrashStsFreq_ovrdflg' */

/* Override flag for signal vehCrashStsFreq */
extern const volatile boolean vilc_b_vehNtwrkConfigData1_ovrdflg;
               /* Referenced by: '<S1059>/vilc_b_vehNtwrkConfigData1_ovrdflg' */

/* Override flag for signal Veh_Network_Config_Data1 */
extern const volatile boolean vilc_b_vehNtwrkConfigData2_ovrdflg;
               /* Referenced by: '<S1060>/vilc_b_vehNtwrkConfigData2_ovrdflg' */

/* Override flag for signal Veh_Network_Config_Data2 */
extern const volatile boolean vilc_b_vehTrip_ovrdflg;
                         /* Referenced by: '<S1035>/vilc_flg_vehTrip_ovrdflg' */

/* Override flag for signal IC_Trip */
extern const volatile boolean vilc_b_vscAbsActv_ovrdflg;
                      /* Referenced by: '<S1309>/vilc_flg_vscAbsActv_ovrdflg' */

/* Override flag for signal b_vscAbsActv */
extern const volatile boolean vilc_b_vscEHBAVHSts_ovrdflg;
                    /* Referenced by: '<S1310>/vilc_flg_vscEHBAVHSts_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBAebActv_ovrdflg;
                   /* Referenced by: '<S1297>/vilc_flg_vscEHBAebActv_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBAebActv_ovrdval;
                     /* Referenced by: '<S1297>/vilc_b_vscEHBAebActv_ovrdval' */
extern const volatile boolean vilc_b_vscEHBDtcActv_ovrdflg;
                   /* Referenced by: '<S1298>/vilc_flg_vscEHBDtcActv_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBDtcActv_ovrdval;
                     /* Referenced by: '<S1298>/vilc_b_vscEHBDtcActv_ovrdval' */
extern const volatile boolean vilc_b_vscEHBMbRgnTgtWhlSts_ovrdflg;
            /* Referenced by: '<S1299>/vilc_flg_vscEHBMbRgnTgtWhlSts_ovrdflg' */
extern const volatile uint8 vilc_b_vscEHBMbRgnTgtWhlSts_ovrdval;
              /* Referenced by: '<S1299>/vilc_b_vscEHBMbRgnTgtWhlSts_ovrdval' */
extern const volatile boolean vilc_b_vscEHBMbRgnTgtWhl_ovrdflg;
               /* Referenced by: '<S1312>/vilc_flg_vscEHBMbRgnTgtWhl_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBPtTrqDecReqActv_ovrdflg;
           /* Referenced by: '<S1300>/vilc_flg_vscEHBPtTrqDecReqActv_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBPtTrqDecReqActv_ovrdval;
             /* Referenced by: '<S1300>/vilc_b_vscEHBPtTrqDecReqActv_ovrdval' */
extern const volatile boolean vilc_b_vscEHBPtTrqDecReq_ovrdflg;
               /* Referenced by: '<S1313>/vilc_flg_vscEHBPtTrqDecReq_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBPtTrqIncReqActv_ovrdflg;
           /* Referenced by: '<S1301>/vilc_flg_vscEHBPtTrqIncReqActv_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBPtTrqIncReqActv_ovrdval;
             /* Referenced by: '<S1301>/vilc_b_vscEHBPtTrqIncReqActv_ovrdval' */
extern const volatile boolean vilc_b_vscEHBPtTrqIncReq_ovrdflg;
               /* Referenced by: '<S1314>/vilc_flg_vscEHBPtTrqIncReq_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBVlcActv_ovrdflg;
                   /* Referenced by: '<S1302>/vilc_flg_vscEHBVlcActv_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBVlcActv_ovrdval;
                     /* Referenced by: '<S1302>/vilc_b_vscEHBVlcActv_ovrdval' */
extern const volatile boolean vilc_b_vscEHBVlcAvlb_ovrdflg;
                   /* Referenced by: '<S1303>/vilc_flg_vscEHBVlcAvlb_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBVlcAvlb_ovrdval;
                     /* Referenced by: '<S1303>/vilc_b_vscEHBVlcAvlb_ovrdval' */
extern const volatile boolean vilc_b_vscEHBVlcPtTrqReqActv_ovrdflg;
           /* Referenced by: '<S1304>/vilc_flg_vscEHBVlcPtTrqReqActv_ovrdflg' */
extern const volatile boolean vilc_b_vscEHBVlcPtTrqReqActv_ovrdval;
             /* Referenced by: '<S1304>/vilc_b_vscEHBVlcPtTrqReqActv_ovrdval' */
extern const volatile boolean vilc_b_vscEHBVlcPtTrqReq_Nm_ovrdflg;
            /* Referenced by: '<S1315>/vilc_flg_vscEHBVlcPtTrqReq_Nm_ovrdflg' */
extern const volatile boolean vilc_b_vscWhlFLSpd_ovrdflg;
                     /* Referenced by: '<S1317>/vilc_flg_vscWhlFLSpd_ovrdflg' */

/* Override flag for signal b_vscWhlFLSpd */
extern const volatile boolean vilc_b_vscWhlFRSpd_ovrdflg;
                     /* Referenced by: '<S1318>/vilc_flg_vscWhlFRSpd_ovrdflg' */

/* Override flag for signal b_vscWhlFRSpd */
extern const volatile boolean vilc_b_vscWhlRLSpd_ovrdflg;
                     /* Referenced by: '<S1319>/vilc_flg_vscWhlRLSpd_ovrdflg' */

/* Override flag for signal b_vscWhlRLSpd */
extern const volatile boolean vilc_b_vscWhlRRSpd_ovrdflg;
                     /* Referenced by: '<S1320>/vilc_flg_vscWhlRRSpd_ovrdflg' */

/* Override flag for signal b_vscWhlRRSpd */
extern const volatile boolean vilc_b_yrsLongitAcce_ovrdflg;
                     /* Referenced by: '<S1289>/vilc_b_yrsLongitAcce_ovrdflg' */
extern const volatile float32 vilc_d_bcmOdometerbackup_ovrdval;
                  /* Referenced by: '<S504>/vilc_d_bcmOdometerbackup_ovrdval' */
extern const volatile float32 vilc_d_ipkOdometerbackup_ovrdval;
                 /* Referenced by: '<S1033>/vilc_d_ipkOdometerbackup_ovrdval' */
extern const volatile float32 vilc_d_odometer_ovrdval;
                          /* Referenced by: '<S1034>/vilc_d_odometer_ovrdval' */

/* Override value for signal IC_Odometer */
extern const volatile float32 vilc_d_vehTrip_ovrdval;
                           /* Referenced by: '<S1035>/vilc_d_vehTrip_ovrdval' */

/* Override value for signal IC_Trip */
extern const volatile uint16 vilc_el_tboxElevation_ovrdval;
                    /* Referenced by: '<S1236>/vilc_el_tboxElevation_ovrdval' */
extern const volatile boolean vilc_fact_FuelLevelHDT_ovrdflg;
                   /* Referenced by: '<S1026>/vilc_fact_FuelLevelHDT_ovrdflg' */

/* Override flag for HDT fuel level */
extern const volatile float32 vilc_fact_FuelLevelHDT_ovrdval;
                   /* Referenced by: '<S1026>/vilc_fact_FuelLevelHDT_ovrdval' */

/* Override value for HDT fuel level in percentage */
extern const volatile float32 vilc_fact_hvbSOH_ovrdval;
                          /* Referenced by: '<S761>/vilc_fact_hvbSOH_ovrdval' */

/* Override value for signal fact_hvbSOH */
extern const volatile boolean vilc_flg_drvCabOverturned_ovrdflg;
                /* Referenced by: '<S1029>/vilc_flg_drvCabOverturned_ovrdflg' */

/* Override flag for signal vild_b_drvCabOverturned */
extern const volatile boolean vilc_flg_tboxIntelChgCmd_ovrdflg;
                 /* Referenced by: '<S1233>/vilc_flg_tboxIntelChgCmd_ovrdflg' */

/* Override flag for signal vild_flg_tboxIntelChgCmd */
extern const volatile float32 vilc_fq_acHvilPrdInpt_ovrdval;
                     /* Referenced by: '<S965>/vilc_fq_acHvilPrdInpt_ovrdval' */
extern const volatile float32 vilc_fq_odpHvilPrdInpt_ovrdval;
                    /* Referenced by: '<S966>/vilc_fq_odpHvilPrdInpt_ovrdval' */
extern const volatile float32 vilc_frq_vehCrashStsFreq_ovrdval;
                  /* Referenced by: '<S967>/vilc_frq_vehCrashStsFreq_ovrdval' */

/* Override value for signal vehCrashStsFreq */
extern const volatile float32 vilc_i_dcdcInpCurr_ovrdval;
                        /* Referenced by: '<S564>/vilc_i_dcdcInpCurr_ovrdval' */
extern const volatile float32 vilc_i_dcdcOutpCurr_ovrdval;
                       /* Referenced by: '<S565>/vilc_i_dcdcOutpCurr_ovrdval' */

/* Override value for signal i_dcdcOutpCurr */
extern const volatile float32 vilc_i_eadInv2ActCurrDC_ovrdval;
                   /* Referenced by: '<S617>/vilc_i_eadInv2ActCurrDC_ovrdval' */

/* Override value for signal i_eadInv2ActCurrDC */
extern const volatile float32 vilc_i_hvbCurr_ovrdval;
                            /* Referenced by: '<S762>/vilc_i_hvbCurr_ovrdval' */

/* Override value for signal i_hvbCurr */
extern const volatile float32 vilc_i_hvbDCChgCurReq_ovrdval;
                     /* Referenced by: '<S763>/vilc_i_hvbDCChgCurReq_ovrdval' */
extern const volatile float32 vilc_i_hvbMaxPrmtDischCurr_ovrdval;
                /* Referenced by: '<S764>/vilc_i_hvbMaxPrmtDischCurr_ovrdval' */

/* Override value for signal i_hvbMaxPrmtDischCurr */
extern const volatile float32 vilc_i_hvbMaxPrmtRgnCurr_ovrdval;
                  /* Referenced by: '<S765>/vilc_i_hvbMaxPrmtRgnCurr_ovrdval' */

/* Override value for signal i_hvbMaxPrmtRgnCurr */
extern const volatile float32 vilc_i_obcOutptCurr_ovrdval;
                      /* Referenced by: '<S1146>/vilc_i_obcOutptCurr_ovrdval' */
extern const volatile float32 vilc_m_McaVehWeight_ovrdval;
                      /* Referenced by: '<S1237>/vilc_m_McaVehWeight_ovrdval' */

/* Override value for signal MCA_VehicleWeight */
extern const volatile float32 vilc_n_acFanReqSpd_ovrdval;
                        /* Referenced by: '<S345>/vilc_n_acFanReqSpd_ovrdval' */
extern const volatile float32 vilc_n_brkLhtTurnOffThd_s;/* Referenced by: '<S20>/Constant17' */
extern const volatile float32 vilc_n_brkLhtTurnOnThd_s;/* Referenced by: '<S20>/Constant16' */
extern const volatile float32 vilc_n_ead2MotSpdVldThdNeg_rpm;/* Referenced by: '<S130>/Constant2' */

/* EAD2 motor speed validity speed threshold Negative number */
extern const volatile float32 vilc_n_ead2MotSpdVldThd_rpm;/* Referenced by:
                                                           * '<S130>/Constant12'
                                                           * '<S1354>/Constant2'
                                                           */

/* EAD2 motor speed validity speed threshold */
extern const volatile float32 vilc_n_eadMot2ActSpd_ovrdval;
                      /* Referenced by: '<S618>/vilc_n_eadMot2ActSpd_ovrdval' */

/* Override value for signal n_eadMot2ActSpd */
extern const volatile uint16 vilc_n_epbErrCod_ovrdval;
                          /* Referenced by: '<S693>/vilc_n_epbErrCod_ovrdval' */

/* Override value for signal n_epbErrCod */
extern const volatile float32 vilc_n_hvbInPositionDetctOffDlyThd_s;/* Referenced by:
                                                                    * '<S921>/Constant19'
                                                                    * '<S921>/Constant3'
                                                                    */
extern const volatile float32 vilc_n_hvbInPositionDetctOnDlyThd_s;/* Referenced by:
                                                                   * '<S921>/Constant1'
                                                                   * '<S921>/Constant18'
                                                                   */
extern const volatile float32 vilc_n_trsm2OutpShaftSpd_ovrdval;
                 /* Referenced by: '<S1277>/vilc_n_trsm2OutpShaftSpd_ovrdval' */

/* Override value for signal TCU_TrsmOutSpd */
extern const volatile uint8 vilc_num_hvbCellMaxID_ovrdval;
                         /* Referenced by: '<S766>/vilc_st_hvbChgSts_ovrdval' */
extern const volatile uint8 vilc_num_hvbCellMinID_ovrdval;
                     /* Referenced by: '<S767>/vilc_i_hvbDCChgCurReq_ovrdval' */
extern const volatile uint16 vilc_num_hvbCellSum_ovrdval;
                       /* Referenced by: '<S768>/vilc_num_hvbCellSum_ovrdval' */
extern const volatile uint8 vilc_num_hvbMaxTempID_ovrdval;
                         /* Referenced by: '<S769>/vilc_st_hvbChgSts_ovrdval' */
extern const volatile uint8 vilc_num_hvbMinTempId_ovrdval;
                     /* Referenced by: '<S770>/vilc_i_hvbDCChgCurReq_ovrdval' */
extern const volatile uint8 vilc_num_hvbTempSum_ovrdval;
                     /* Referenced by: '<S771>/vilc_E_hvbPackRemnEgy_ovrdval' */
extern const volatile float32 vilc_p_frontAirTankPressure_ovrdval;
              /* Referenced by: '<S1025>/vilc_p_frontAirTankPressure_ovrdval' */

/* Override value for IC_FrontAirTankPressure */
extern const volatile float32 vilc_p_rearAirTankPressure_ovrdval;
               /* Referenced by: '<S1028>/vilc_p_rearAirTankPressure_ovrdval' */

/* Override value for IC_RearAirTankPressure */
extern const volatile float32 vilc_pct_GearPosn_ovrdval;
                                /* Referenced by: '<S968>/vilc_u_Brk_ovrdval' */

/* Override value for signal GearPosn */
extern const volatile float32 vilc_pct_HVILReturnPWM_ovrdval;
                      /* Referenced by: '<S969>/vilc_b_ResrAirSwitch_ovrdval' */

/* Override value for signal pct_HVILReturnPWM */
extern const volatile float32 vilc_pct_TS5sensorFb_ovrdval;
                      /* Referenced by: '<S979>/vilc_pct_TS5sensorFb_ovrdval' */

/* Override value for signal pct_TS5sensorFb */
extern const volatile float32 vilc_pct_WatPmpEP1FbPWM_ovrdval;
                   /* Referenced by: '<S970>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal b_WatPmpEP1FbPWM */
extern const volatile float32 vilc_pct_WatPmpEP2FbPWM_ovrdval;
                   /* Referenced by: '<S971>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal pct_WatPmpEP2FbPWM */
extern const volatile float32 vilc_pct_WatPmpEP3FbPWM_ovrdval;
                   /* Referenced by: '<S972>/vilc_pct_WatPmpEP3FbPWM_ovrdval' */

/* Override value for signal pct_WatPmpEP3FbPWM */
extern const volatile float32 vilc_pct_fan1Fb_ovrdval;
                           /* Referenced by: '<S973>/vild_pct_fan1Fb_ovrdval' */

/* Override value for signal vild_pct_fan1Fb */
extern const volatile float32 vilc_pct_fan2Fb_ovrdval;
                           /* Referenced by: '<S974>/vild_pct_fan2Fb_ovrdval' */

/* Override value for signal vild_pct_fan2Fb */
extern const volatile float32 vilc_pct_mmiLocBkChgTarVal_ovrdval;
                /* Referenced by: '<S707>/vilc_pct_mmiLocBkChgTarVal_ovrdval' */

/* Override value for signal MMI_LocalBookChrgnTarVal */
extern const volatile float32 vilc_pct_odpHvilDtyInpt_ovrdval;
                   /* Referenced by: '<S975>/vilc_pct_odpHvilDtyInpt_ovrdval' */
extern const volatile float32 vilc_pct_tboxAlwChgCurrMax_ovrdval;
              /* Referenced by: '<S1238>/vilc_st_tboxStartBattChgReq_ovrdval' */
extern const volatile float32 vilc_pct_tboxChgDepth_ovrdval;
                         /* Referenced by: '<S1239>/vilc_st_tboxLife_ovrdval' */
extern const volatile float32 vilc_pct_vehCrashStsDuty_ovrdval;
                          /* Referenced by: '<S976>/vilc_b_BrkSwitch_ovrdval' */

/* Override value for signal vehCrashStsDuty */
extern const volatile uint8 vilc_pst_hvbChgOvrCurr_ovrdval;
                    /* Referenced by: '<S792>/vilc_pst_hvbChgOvrCurr_ovrdval' */
extern const volatile float32 vilc_pwr_PTCActPwr_ovrdval;
                       /* Referenced by: '<S346>/vilc_pwr_airCmprAct_ovrdval' */

/* Override value for signal PTCActPwr */
extern const volatile float32 vilc_pwr_accm1ActPwr_ovrdval;
                      /* Referenced by: '<S347>/vilc_pwr_accm1ActPwr_ovrdval' */
extern const volatile float32 vilc_pwr_acwpHeatPower_ovrdval;
                       /* Referenced by: '<S348>/vilc_pwr_hvbTempFlt_ovrdval' */

/* Override value for signal EWP_HeatPower */
extern const volatile float32 vilc_pwr_airCmprAct_ovrdval;
                       /* Referenced by: '<S349>/vilc_pwr_airCmprAct_ovrdval' */

/* Override value for signal pwr_airCmprAct */
extern const volatile float32 vilc_pwr_eadMot2ActOutpPwr_ovrdval;
                /* Referenced by: '<S619>/vilc_pwr_eadMot2ActOutpPwr_ovrdval' */

/* Override value for signal pwr_eadMot2ActOutpPwr */
extern const volatile float32 vilc_pwr_hvbMaxContChgPwr_ovrdval;
                 /* Referenced by: '<S772>/vilc_pwr_hvbMaxContChgPwr_ovrdval' */

/* Override value for signal hvbMaxContChgPwr */
extern const volatile float32 vilc_pwr_hvbMaxPeakChgPwr_ovrdval;
                 /* Referenced by: '<S773>/vilc_pwr_hvbMaxPeakChgPwr_ovrdval' */

/* Override value for signal hvbMaxPeakChgPwr */
extern const volatile float32 vilc_pwr_hvbMaxPeakDischPwr_ovrdval;
               /* Referenced by: '<S774>/vilc_pwr_hvbMaxPeakDischPwr_ovrdval' */

/* Override value for signal hvbMaxPeakDischPwr */
extern const volatile float32 vilc_pwr_iptActPwr_ovrdval;
                        /* Referenced by: '<S350>/vilc_pwr_iptActPwr_ovrdval' */
extern const volatile float32 vilc_pwr_obcPwrEgyMgrAvl_ovrdval;
                 /* Referenced by: '<S1147>/vilc_pwr_obcPwrEgyMgrAvl_ovrdval' */
extern const volatile float32 vilc_pwr_ptcActPwrRear_ovrdval;
                    /* Referenced by: '<S351>/vilc_pwr_ptcActPwrRear_ovrdval' */
extern const volatile float32 vilc_q_hvbSOC01_ovrdval;
                           /* Referenced by: '<S776>/vilc_q_hvbSOC01_ovrdval' */

/* Override value for signal q_hvbSOC01 */
extern const volatile float32 vilc_q_hvbSOC_ovrdval;
                             /* Referenced by: '<S775>/vilc_q_hvbSOC_ovrdval' */

/* Override value for signal q_hvbSOC */
extern const volatile uint8 vilc_st_24vDcdcFltSts_ovrdval;
                     /* Referenced by: '<S566>/vilc_st_24vDcdcFltSts_ovrdval' */

/* Override value for signal st_24vDcdcFltSts */
extern const volatile uint8 vilc_st_24vDcdcModAct_ovrdval;
                     /* Referenced by: '<S567>/vilc_st_24vDcdcModAct_ovrdval' */

/* Override value for signal st_24vDcdcModAct */
extern const volatile uint8 vilc_st_24vDcdcSelfChk_ovrdval;
                    /* Referenced by: '<S568>/vilc_st_24vDcdcSelfChk_ovrdval' */

/* Override value for signal st_24vDcdcSelfChk */
extern const volatile uint8 vilc_st_24vDcdcSubFltSts_ovrdval;
                  /* Referenced by: '<S569>/vilc_st_24vDcdcSubFltSts_ovrdval' */

/* Override value for signal DCDC_SubFltLevel */
extern const volatile uint8 vilc_st_ACSwtSt_ovrdval;
                           /* Referenced by: '<S352>/vilc_st_ACSwtSt_ovrdval' */

/* Override value for signal st_ACSwtSt */
extern const volatile uint8 vilc_st_BmsTempOutOfCtrlFlt_ovrdval;
               /* Referenced by: '<S777>/vilc_st_BmsTempOutOfCtrlFlt_ovrdval' */

/* Override value for signal BMS_TempOutofCtr */
extern const volatile uint8 vilc_st_GearPosn_ovrdval;
                          /* Referenced by: '<S977>/vilc_st_GearPosn_ovrdval' */

/* Override value for signal GearPosn */
extern const volatile uint16 vilc_st_McaCalNum_ovrdval;
                        /* Referenced by: '<S1240>/vilc_st_McaCalNum_ovrdval' */

/* Override value for signal MCA_CalNum */
extern const volatile uint8 vilc_st_McaOvrLoadInd_ovrdval;
                    /* Referenced by: '<S1241>/vilc_st_McaOvrLoadInd_ovrdval' */

/* Override value for signal MCA_OverloadInd */
extern const volatile uint8 vilc_st_PTCSt_ovrdval;
                         /* Referenced by: '<S353>/vilc_st_airCmprSt_ovrdval' */

/* Override value for signal PTCstatus */
extern const volatile uint8 vilc_st_PtcWrkSts_ovrdval;
                         /* Referenced by: '<S354>/vilc_st_PtcWrkSts_ovrdval' */

/* Override value for signal PTC_WorkSts */
extern const volatile uint8 vilc_st_TBOXFunAntiDismantleActive_ovrdval;
       /* Referenced by: '<S1242>/vilc_st_TBOXFunAntiDismantleActive_ovrdval' */

/* Override value for signal st_TBOXFunAntiDismantleActive */
extern const volatile uint8 vilc_st_TBOXFunLockVehActive_ovrdval;
             /* Referenced by: '<S1243>/vilc_st_TBOXFunLockVehActive_ovrdval' */

/* Override value for signal st_TBOXFunLockVehActive */
extern const volatile float32 vilc_st_TBOXLockLimSet_ovrdval;
                   /* Referenced by: '<S1244>/vilc_st_TBOXLockLimSet_ovrdval' */

/* Override value for signal st_TBOXLockLimSet */
extern const volatile float32 vilc_st_TBOXLockResultResp_ovrdval;
               /* Referenced by: '<S1245>/vilc_st_TBOXLockResultResp_ovrdval' */

/* Override value for signal st_TBOXLockResultResp */
extern const volatile uint8 vilc_st_TBOXLockVehCtrl_ovrdval;
                  /* Referenced by: '<S1246>/vilc_st_TBOXLockVehCtrl_ovrdval' */

/* Override value for signal st_TBOXLockVehCtrl */
extern const volatile uint8 vilc_st_TBOXLockVehType_ovrdval;
                  /* Referenced by: '<S1247>/vilc_st_TBOXLockVehType_ovrdval' */

/* Override value for signal st_TBOXLockVehType */
extern const volatile uint8 vilc_st_acFltLvl_ovrdval;
                          /* Referenced by: '<S355>/vilc_st_acFltLvl_ovrdval' */

/* Override value for signal AC_SysFaultLevel */
extern const volatile uint8 vilc_st_acSubFltSts_ovrdval;
                       /* Referenced by: '<S356>/vilc_st_acSubFltSts_ovrdval' */

/* Override value for signal AC_SubSysFaultLevel */
extern const volatile uint8 vilc_st_acuCrashOutStsC_ovrdval;
                   /* Referenced by: '<S534>/vilc_st_acuCrashOutStsC_ovrdval' */

/* Override value for signal ACU_CrashOutputStatus from C Can */
extern const volatile uint8 vilc_st_acuCrashOutStsPT_ovrdval;
                  /* Referenced by: '<S535>/vilc_st_acuCrashOutStsPT_ovrdval' */

/* Override value for signal ACU_CrashOutputStatus from PT Can */
extern const volatile uint8 vilc_st_acuCrashStsInvalid_ovrdval;
                /* Referenced by: '<S536>/vilc_st_acuCrashStsInvalid_ovrdval' */

/* Override value for signal ACU_CrashStatusInvalid */
extern const volatile uint8 vilc_st_acuWarnLampSts_ovrdval;
                    /* Referenced by: '<S537>/vilc_st_acuWarnLampSts_ovrdval' */

/* Override value for signal ACU_WarningLampStatus */
extern const volatile uint8 vilc_st_adc02TargetGearPostion_ovrdval;
            /* Referenced by: '<S432>/vilc_st_adc02TargetGearPostion_ovrdval' */
extern const volatile uint8 vilc_st_adc0TargetGearPostion_ovrdval;
             /* Referenced by: '<S433>/vilc_st_adc0TargetGearPostion_ovrdval' */
extern const volatile uint8 vilc_st_adc12TargetGearPostion_ovrdval;
            /* Referenced by: '<S434>/vilc_st_adc12TargetGearPostion_ovrdval' */
extern const volatile uint8 vilc_st_adc1TargetGearPostion_ovrdval;
             /* Referenced by: '<S435>/vilc_st_adc1TargetGearPostion_ovrdval' */
extern const volatile uint8 vilc_st_airCmprSt_ovrdval;
                         /* Referenced by: '<S357>/vilc_st_airCmprSt_ovrdval' */

/* Override value for signal st_airCmprSt */
extern const volatile uint8 vilc_st_batLowSoc2_ovrdval;
                     /* Referenced by: '<S779>/vilc_i_hvbDCChgCurReq_ovrdval' */
extern const volatile uint8 vilc_st_batOvrSoc2_ovrdval;
                         /* Referenced by: '<S780>/vilc_st_hvbChgSts_ovrdval' */
extern const volatile uint8 vilc_st_batOvrVolt2_ovrdval;
                       /* Referenced by: '<S781>/vilc_st_batOvrVolt2_ovrdval' */
extern const volatile uint8 vilc_st_batUdrVolt2_ovrdval;
                       /* Referenced by: '<S782>/vilc_st_batUdrVolt2_ovrdval' */
extern const volatile uint8 vilc_st_bbmFltSts_ovrdval;
                         /* Referenced by: '<S505>/vilc_st_bbmFltSts_ovrdval' */
extern const volatile uint8 vilc_st_bbmWorkSts_ovrdval;
                        /* Referenced by: '<S506>/vilc_st_bbmWorkSts_ovrdval' */
extern const volatile uint8 vilc_st_bcmATWSSt_ovrdval;
                         /* Referenced by: '<S507>/vilc_st_bcmATWSSt_ovrdval' */

/* Override value for signal BCM_ATWS_St */
extern const volatile uint8 vilc_st_bcmFrntLDoorAjarSt_ovrdval;
                /* Referenced by: '<S508>/vilc_st_bcmFrntLDoorAjarSt_ovrdval' */

/* Override value for signal vild_st_bcmFrntLDoorAjarSt */
extern const volatile uint8 vilc_st_bcmFrntRDoorAjarSt_ovrdval;
                /* Referenced by: '<S509>/vilc_st_bcmFrntRDoorAjarSt_ovrdval' */

/* Override value for signal vild_st_bcmFrntRDoorAjarSt */
extern const volatile uint8 vilc_st_bmsBattPackMatchFlt_ovrdval;
               /* Referenced by: '<S708>/vilc_st_bmsBattPackMatchFlt_ovrdval' */
extern const volatile uint8 vilc_st_bmsBattPackNum_ovrdval;
                    /* Referenced by: '<S709>/vilc_st_bmsBattPackNum_ovrdval' */
extern const volatile uint8 vilc_st_bmsBattSysNum_ovrdval;
                     /* Referenced by: '<S710>/vilc_st_bmsBattSysNum_ovrdval' */
extern const volatile uint8 vilc_st_bmsDlyDataUpldEnb_ovrdval;
                 /* Referenced by: '<S711>/vilc_st_bmsDlyDataUpldEnb_ovrdval' */
extern const volatile uint8 vilc_st_bmsTboxFireAlm_ovrdval;
                    /* Referenced by: '<S712>/vilc_st_bmsTboxFireAlm_ovrdval' */
extern const volatile uint8 vilc_st_brkPmpEnaOutFb_ovrdval;
                    /* Referenced by: '<S519>/vilc_st_brkPmpEnaOutFb_ovrdval' */

/* Override value for signal BDCACEnableOutFb */
extern const volatile uint8 vilc_st_brkPmpSelfChk_ovrdval;
                     /* Referenced by: '<S520>/vilc_st_brkPmpSelfChk_ovrdval' */

/* Override value for signal st_brkPmpSelfChk */
extern const volatile uint8 vilc_st_brkPmpWrkSt_ovrdval;
                       /* Referenced by: '<S521>/vilc_st_brkPmpWrkSt_ovrdval' */

/* Override value for signal st_brkPmpWrkSt */
extern const volatile uint8 vilc_st_cbnThermMngReq_ovrdval;
                    /* Referenced by: '<S358>/vilc_st_cbnThermMngReq_ovrdval' */

/* Override value for signal st_cbnThermMngReq */
extern const volatile uint8 vilc_st_cellOverVolt2_ovrdval;
                     /* Referenced by: '<S783>/vilc_st_cellOverVolt2_ovrdval' */
extern const volatile uint8 vilc_st_cellUdrVolt2_ovrdval;
                      /* Referenced by: '<S784>/vilc_st_cellUdrVolt2_ovrdval' */
extern const volatile uint8 vilc_st_chdLckActv_ovrdval;
                        /* Referenced by: '<S694>/vilc_st_chdLckActv_ovrdval' */

/* Override value for signal st_chdLckActv */
extern const volatile boolean vilc_st_csmEngRecReqInvalid_ovrdval;
               /* Referenced by: '<S553>/vilc_st_csmEngRecReqInvalid_ovrdval' */
extern const volatile uint8 vilc_st_csmEngRecReq_ovrdval;
                      /* Referenced by: '<S552>/vilc_st_csmEngRecReq_ovrdval' */
extern const volatile uint8 vilc_st_dcChgCcSt_ovrdval;
                        /* Referenced by: '<S1142>/vilc_st_dcChgCcSt_ovrdval' */

/* Override value for signal st_dcChgCcSt */
extern const volatile uint8 vilc_st_dccAccyConnStsFb_ovrdval;
                  /* Referenced by: '<S570>/vilc_st_dccAccyConnStsFb_ovrdval' */
extern const volatile uint8 vilc_st_dcdcCanComFlt_ovrdval;
                     /* Referenced by: '<S571>/vilc_st_dcdcCanComFlt_ovrdval' */

/* Override value for signal st_dcdcCanComFlt */
extern const volatile uint8 vilc_st_dcdcCutOffLvFb_ovrdval;
                    /* Referenced by: '<S572>/vilc_st_dcdcCutOffLvFb_ovrdval' */

/* Override value for signal st_dcdcCutOffLvFb */
extern const volatile uint8 vilc_st_dcdcErrorCode_ovrdval;
                     /* Referenced by: '<S573>/vilc_st_dcdcErrorCode_ovrdval' */

/* Override value for signal DCDC_ErrorCode */
extern const volatile uint8 vilc_st_dcdcFltSts_ovrdval;
                        /* Referenced by: '<S574>/vilc_st_dcdcFltSts_ovrdval' */

/* Override value for signal st_dcdcFltSts */
extern const volatile uint8 vilc_st_dcdcModAct_ovrdval;
                        /* Referenced by: '<S575>/vilc_st_dcdcModAct_ovrdval' */

/* Override value for signal st_dcdcModAct */
extern const volatile uint8 vilc_st_dcdcOutpOvrCurr_ovrdval;
                   /* Referenced by: '<S576>/vilc_st_dcdcOutpOvrCurr_ovrdval' */

/* Override value for signal st_dcdcOutpOvrCurr */
extern const volatile uint8 vilc_st_dcdcOutpOvrVolt_ovrdval;
                   /* Referenced by: '<S577>/vilc_st_dcdcOutpOvrVolt_ovrdval' */

/* Override value for signal st_dcdcOutpOvrVolt */
extern const volatile uint8 vilc_st_dcdcSelfChk_ovrdval;
                       /* Referenced by: '<S578>/vilc_st_dcdcSelfChk_ovrdval' */

/* Override value for signal st_dcdcSelfChk */
extern const volatile uint8 vilc_st_eadInv2ActMod_ovrdval;
                     /* Referenced by: '<S620>/vilc_st_eadInv2ActMod_ovrdval' */

/* Override value for signal st_eadInv2ActMod */
extern const volatile uint8 vilc_st_eadInv2ActvDischgFlt_ovrdval;
              /* Referenced by: '<S621>/vilc_st_eadInv2ActvDischgFlt_ovrdval' */

/* Override value for signal st_eadInv2ActvDischgFlt */
extern const volatile uint8 vilc_st_eadInv2CanComFlt_ovrdval;
                  /* Referenced by: '<S622>/vilc_st_eadInv2CanComFlt_ovrdval' */

/* Override value for signal st_eadInv2CanComFlt */
extern const volatile uint8 vilc_st_eadInv2CtrlMod_ovrdval;
                    /* Referenced by: '<S623>/vilc_st_eadInv2CtrlMod_ovrdval' */

/* Override value for signal st_eadInv2CtrlMod */
extern const volatile uint8 vilc_st_eadInv2FltSts_ovrdval;
                     /* Referenced by: '<S624>/vilc_st_eadInv2FltSts_ovrdval' */

/* Override value for signal st_eadInv2FltSts */
extern const volatile uint8 vilc_st_eadInv2HVLFlt_ovrdval;
                     /* Referenced by: '<S625>/vilc_st_eadInv2HVLFlt_ovrdval' */

/* Override value for signal MCU_HVLoopFault */
extern const volatile uint8 vilc_st_eadInv2IgbtFlt_ovrdval;
                    /* Referenced by: '<S626>/vilc_st_eadInv2IgbtFlt_ovrdval' */

/* Override value for signal st_eadInv2IgbtFlt */
extern const volatile uint8 vilc_st_eadInv2MemFlt_ovrdval;
                     /* Referenced by: '<S627>/vilc_st_eadInv2MemFlt_ovrdval' */

/* Override value for signal st_eadInv2MemFlt */
extern const volatile uint8 vilc_st_eadInv2PwrActvMod_ovrdval;
                 /* Referenced by: '<S628>/vilc_st_eadInv2PwrActvMod_ovrdval' */

/* Override value for signal MCU_PowerActiveMode */
extern const volatile uint8 vilc_st_eadInv2RotInvFlt_ovrdval;
                  /* Referenced by: '<S629>/vilc_st_eadInv2RotInvFlt_ovrdval' */

/* Override value for signal st_eadInv2RotInvFlt */
extern const volatile uint8 vilc_st_eadInv2SelfChk_ovrdval;
                    /* Referenced by: '<S630>/vilc_st_eadInv2SelfChk_ovrdval' */

/* Override value for signal st_eadInv2SelfChk */
extern const volatile uint8 vilc_st_eadInv2TempHiAlrm_ovrdval;
                 /* Referenced by: '<S631>/vilc_st_eadInv2TempHiAlrm_ovrdval' */

/* Override value for signal st_eadInv2TempHiAlrm */
extern const volatile uint8 vilc_st_eadInv2TempSnsrErr_ovrdval;
                /* Referenced by: '<S632>/vilc_st_eadInv2TempSnsrErr_ovrdval' */

/* Override value for signal st_eadInv2TempSnsrErr */
extern const volatile uint8 vilc_st_eadInv2WrkMod_ovrdval;
                     /* Referenced by: '<S633>/vilc_st_eadInv2WrkMod_ovrdval' */

/* Override value for signal st_eadInv2WrkMod */
extern const volatile uint8 vilc_st_eadMot2BlkRotErr_ovrdval;
                  /* Referenced by: '<S634>/vilc_st_eadMot2BlkRotErr_ovrdval' */

/* Override value for signal st_eadMot2BlkRotErr */
extern const volatile uint8 vilc_st_eadMot2ImmoRlsChk_ovrdval;
                 /* Referenced by: '<S635>/vilc_st_eadMot2ImmoRlsChk_ovrdval' */

/* Override value for signal vild_st_eadMot2ImmoRlsChk */
extern const volatile uint8 vilc_st_eadMot2SpdHiAlrm_ovrdval;
                  /* Referenced by: '<S636>/vilc_st_eadMot2SpdHiAlrm_ovrdval' */

/* Override value for signal st_eadMot2SpdHiAlrm */
extern const volatile uint8 vilc_st_eadMot2SysOvrLdAlrm_ovrdval;
               /* Referenced by: '<S637>/vilc_st_eadMot2SysOvrLdAlrm_ovrdval' */

/* Override value for signal st_eadMot2SysOvrLdAlrm */
extern const volatile uint8 vilc_st_eadMot2TempHiAlrm_ovrdval;
                 /* Referenced by: '<S638>/vilc_st_eadMot2TempHiAlrm_ovrdval' */

/* Override value for signal st_eadMot2TempHiAlrm */
extern const volatile uint8 vilc_st_eadMot2TempHiFlt_ovrdval;
                  /* Referenced by: '<S639>/vilc_st_eadMot2TempHiFlt_ovrdval' */
extern const volatile uint8 vilc_st_eadMot2TempSnsrErr_ovrdval;
                /* Referenced by: '<S640>/vilc_st_eadMot2TempSnsrErr_ovrdval' */

/* Override value for signal st_eadMot2TempSnsrErr */
extern const volatile uint32 vilc_st_ecuFunConfigData1_ovrdval;
                /* Referenced by: '<S1057>/vilc_st_ecuFunConfigData1_ovrdval' */

/* Override value for signal ECU_Fun_Config_Data1 */
extern const volatile uint32 vilc_st_ecuFunConfigData2_ovrdval;
                /* Referenced by: '<S1058>/vilc_st_ecuFunConfigData2_ovrdval' */

/* Override value for signal ECU_Fun_Config_Data2 */
extern const volatile uint8 vilc_st_egsmFltLvl_ovrdval;
                        /* Referenced by: '<S612>/vilc_st_egsmFltLvl_ovrdval' */

/* Override value for signal st_egsmFltLvl */
extern const volatile uint8 vilc_st_egsmGearReq_ovrdval;
                       /* Referenced by: '<S613>/vilc_st_egsmGearReq_ovrdval' */

/* Override value for signal st_egsmGearReq */
extern const volatile uint8 vilc_st_egsmLeverPosition_ovrdval;
                       /* Referenced by: '<S609>/vilc_st_egsmGearReq_ovrdval' */
extern const volatile uint8 vilc_st_egsmParkReq_ovrdval;
                       /* Referenced by: '<S610>/vilc_st_egsmGearReq_ovrdval' */
extern const volatile uint8 vilc_st_ehbBrkSysErrFlt_ovrdval;
                  /* Referenced by: '<S1305>/vilc_st_ehbBrkSysErrFlt_ovrdval' */
extern const volatile uint8 vilc_st_ehbEPBDynAppSts_ovrdval;
                  /* Referenced by: '<S1306>/vilc_st_ehbEPBDynAppSts_ovrdval' */
extern const volatile uint8 vilc_st_ehbHHCActive_ovrdval;
                     /* Referenced by: '<S1307>/vilc_st_ehbHHCActive_ovrdval' */
extern const volatile uint8 vilc_st_ehbIsaSts_ovrdval;
                        /* Referenced by: '<S1308>/vilc_st_ehbIsaSts_ovrdval' */
extern const volatile uint8 vilc_st_epbFltLvl_ovrdval;
                         /* Referenced by: '<S695>/vilc_st_epbFltLvl_ovrdval' */

/* Override value for signal st_epbFltLvl */
extern const volatile uint8 vilc_st_epsEpasFail_ovrdval;
                      /* Referenced by: '<S1211>/vilc_st_epsEpasFail_ovrdval' */
extern const volatile uint8 vilc_st_epsErrorCode_ovrdval;
                     /* Referenced by: '<S1201>/vilc_st_epsErrorCode_ovrdval' */

/* Override value for signal SDCAC_ErrorCode */
extern const volatile uint8 vilc_st_epsFltLvl_ovrdval;
                        /* Referenced by: '<S1202>/vilc_st_epsFltLvl_ovrdval' */

/* Override value for signal st_epsFltLvl */
extern const volatile uint8 vilc_st_epsSelfChk_ovrdval;
                       /* Referenced by: '<S1203>/vilc_st_epsSelfChk_ovrdval' */

/* Override value for signal st_epsSelfChk */
extern const volatile uint8 vilc_st_epsSubFltLvl_ovrdval;
                     /* Referenced by: '<S1204>/vilc_st_epsSubFltLvl_ovrdval' */

/* Override value for signal SDCAC_SubFltLevel */
extern const volatile uint8 vilc_st_epsWrkSt_ovrdval;
                         /* Referenced by: '<S1205>/vilc_st_epsWrkSt_ovrdval' */

/* Override value for signal st_epsWrkSt */
extern const volatile uint8 vilc_st_flgFctCfgAccy_ovrdval;
                    /* Referenced by: '<S1090>/vilc_st_flgFctCfgAccy_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgBatTyp_ovrdval;
                  /* Referenced by: '<S1091>/vilc_st_flgFctCfgBatTyp_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgBox_ovrdval;
                     /* Referenced by: '<S1092>/vilc_st_flgFctCfgBox_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgECOMaxSpd_ovrdval;
               /* Referenced by: '<S1094>/vilc_st_flgFctCfgECOMaxSpd_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgFan_ovrdval;
                  /* Referenced by: '<S1095>/vilc_st_flgFctCfgFanPwr_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgMaxSpd_ovrdval;
                       /* Referenced by: '<S1096>/vilc_st_pepsPduLvl_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgMotTyp_ovrdval;
                  /* Referenced by: '<S1097>/vilc_st_flgFctCfgMotTyp_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgNormalMaxSpd_ovrdval;
            /* Referenced by: '<S1098>/vilc_st_flgFctCfgNormalMaxSpd_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgPowerMaxSpd_ovrdval;
             /* Referenced by: '<S1099>/vilc_st_flgFctCfgPowerMaxSpd_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgSlowChg_ovrdval;
                 /* Referenced by: '<S1100>/vilc_st_flgFctCfgSlowChg_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgTyre_ovrdval;
                     /* Referenced by: '<S1086>/vilc_b_flgFctCfgTyre_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgV2L_ovrdval;
                       /* Referenced by: '<S1101>/vilc_st_pepsPduLvl_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgVehCfg_ovrdval;
                  /* Referenced by: '<S1102>/vilc_st_flgFctCfgVehCfg_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgVehTyp_ovrdval;
                       /* Referenced by: '<S1103>/vilc_st_pepsPduLvl_ovrdval' */
extern const volatile uint8 vilc_st_flgFctCfgVehUsg_ovrdval;
                   /* Referenced by: '<S1104>/vilc_b_flgFctCfgVehUsg_ovrdval' */
extern const volatile uint8 vilc_st_hcmAccConnStsFb_ovrdval;
                   /* Referenced by: '<S713>/vilc_st_hcmAccConnStsFb_ovrdval' */
extern const volatile uint8 vilc_st_hcmCutOffLvFb_ovrdval;
                     /* Referenced by: '<S714>/vilc_st_hcmCutOffLvFb_ovrdval' */

/* Override value for signal st_hcmCutOffLvFb */
extern const volatile uint8 vilc_st_hcmFltLvl_ovrdval;
                         /* Referenced by: '<S715>/vilc_st_hcmFltLvl_ovrdval' */

/* Override value for signal st_hcmFltLvl */
extern const volatile uint8 vilc_st_hcmHvilSt_ovrdval;
                         /* Referenced by: '<S716>/vilc_st_hcmHvilSt_ovrdval' */

/* Override value for signal st_hcmHvilSt */
extern const volatile uint8 vilc_st_hcmPTC1ConnStsFb_ovrdval;
                  /* Referenced by: '<S717>/vilc_st_hcmPTC1ConnStsFb_ovrdval' */
extern const volatile uint8 vilc_st_hcmPtcDefRlyStFb_ovrdval;
                  /* Referenced by: '<S718>/vilc_st_hcmPtcDefRlyStFb_ovrdval' */

/* Override value for signal st_hcmPtcDefRlyStFb */
extern const volatile uint8 vilc_st_hcmPwrActvMod_ovrdval;
                     /* Referenced by: '<S719>/vilc_st_hcmPwrActvMod_ovrdval' */

/* Override value for signal st_hcmPwrActvMod */
extern const volatile uint8 vilc_st_hcmSelfChk_ovrdval;
                        /* Referenced by: '<S720>/vilc_st_hcmSelfChk_ovrdval' */

/* Override value for signal st_hcmSelfChk */
extern const volatile uint8 vilc_st_hcmWrkSt_ovrdval;
                          /* Referenced by: '<S721>/vilc_st_hcmWrkSt_ovrdval' */

/* Override value for signal st_hcmWrkSt */
extern const volatile uint8 vilc_st_hillStrtAssi_ovrdval;
                      /* Referenced by: '<S696>/vilc_st_hillStrtAssi_ovrdval' */

/* Override value for signal st_hillStrtAssi */
extern const volatile uint8 vilc_st_hvbBatUniformity_ovrdval;
                  /* Referenced by: '<S785>/vilc_st_hvbBatUniformity_ovrdval' */
extern const volatile uint8 vilc_st_hvbBmsHwFlt_ovrdval;
                       /* Referenced by: '<S787>/vilc_st_hvbBmsHwFlt_ovrdval' */

/* Override value for signal st_hvbBmsHwFlt */
extern const volatile uint8 vilc_st_hvbCellTempDevFlt_ovrdval;
                 /* Referenced by: '<S788>/vilc_st_hvbCellTempDevFlt_ovrdval' */

/* Override value for signal st_hvbCellTempDevFlt */
extern const volatile uint8 vilc_st_hvbCellVoltDevFlt_ovrdval;
                 /* Referenced by: '<S789>/vilc_st_hvbCellVoltDevFlt_ovrdval' */

/* Override value for signal st_hvbCellVoltDevFlt */
extern const volatile uint8 vilc_st_hvbChgCcsts_ovrdval;
                       /* Referenced by: '<S790>/vilc_st_hvbChgCcsts_ovrdval' */
extern const volatile uint8 vilc_st_hvbChgFltReq_ovrdval;
                      /* Referenced by: '<S791>/vilc_st_hvbChgFltReq_ovrdval' */
extern const volatile uint8 vilc_st_hvbChgSts_ovrdval;
                         /* Referenced by: '<S794>/vilc_st_hvbChgSts_ovrdval' */
extern const volatile uint8 vilc_st_hvbDCChgPlgNOvrTmp_ovrdval;
                /* Referenced by: '<S795>/vilc_st_hvbDCChgPlgNOvrTmp_ovrdval' */
extern const volatile uint8 vilc_st_hvbDCChgPlgPOvrTmp_ovrdval;
                /* Referenced by: '<S902>/vilc_st_hvbDCChgPlgPOvrTmp_ovrdval' */
extern const volatile uint8 vilc_st_hvbDCChgProcss_ovrdval;
                    /* Referenced by: '<S796>/vilc_st_hvbDCChgProcss_ovrdval' */
extern const volatile uint8 vilc_st_hvbDischgFltReq_ovrdval;
                   /* Referenced by: '<S797>/vilc_st_hvbDischgFltReq_ovrdval' */
extern const volatile uint8 vilc_st_hvbEmgyCutOffReq_ovrdval;
                  /* Referenced by: '<S798>/vilc_st_hvbEmgyCutOffReq_ovrdval' */

/* Override value for signal st_hvbEmgyCutOffReq */
extern const volatile uint8 vilc_st_hvbFltSt_ovrdval;
                          /* Referenced by: '<S799>/vilc_st_hvbFltSt_ovrdval' */

/* Override value for signal st_hvbFltSt */
extern const volatile uint8 vilc_st_hvbHeatSts_ovrdval;
                         /* Referenced by: '<S801>/vilc_st_hvbELkSts_ovrdval' */

/* Override value for signal hvbHeatSts */
extern const volatile uint8 vilc_st_hvbHvilSts_ovrdval;
                        /* Referenced by: '<S802>/vilc_st_hvbHvilSts_ovrdval' */

/* Override value for signal st_hvbHvilSts */
extern const volatile uint8 vilc_st_hvbInslErr1_ovrdval;
                       /* Referenced by: '<S786>/vilc_st_hvbInslErr1_ovrdval' */

/* Override value for signal st_hvbInslErr1 */
extern const volatile uint8 vilc_st_hvbInslErr2_ovrdval;
                       /* Referenced by: '<S800>/vilc_st_hvbInslErr2_ovrdval' */

/* Override value for signal st_hvbInslErr2 */
extern const volatile uint8 vilc_st_hvbInslErr3_ovrdval;
                       /* Referenced by: '<S804>/vilc_st_hvbInslErr3_ovrdval' */

/* Override value for signal st_hvbInslErr3 */
extern const volatile uint8 vilc_st_hvbMaiRlyNeg_ovrdval;
                      /* Referenced by: '<S805>/vilc_st_hvbMaiRlyNeg_ovrdval' */

/* Override value for signal st_hvbMaiRlyNeg */
extern const volatile uint8 vilc_st_hvbMaiRlyPos_ovrdval;
                      /* Referenced by: '<S722>/vilc_st_hvbMaiRlyPos_ovrdval' */

/* Override value for signal st_hvbMaiRlyPos */
extern const volatile uint8 vilc_st_hvbOvrChgFlt_ovrdval;
                      /* Referenced by: '<S806>/vilc_st_hvbOvrChgFlt_ovrdval' */

/* Override value for signal st_hvbOvrChgFlt */
extern const volatile uint8 vilc_st_hvbPreChgSts_ovrdval;
                       /* Referenced by: '<S807>/vilc_st_batOvrVolt2_ovrdval' */
extern const volatile uint8 vilc_st_hvbPrmtCutOffLvFb_ovrdval;
                 /* Referenced by: '<S808>/vilc_st_hvbPrmtCutOffLvFb_ovrdval' */

/* Override value for signal st_hvbPrmtCutOffLvFb */
extern const volatile uint8 vilc_st_hvbPwrActvMod_ovrdval;
                     /* Referenced by: '<S809>/vilc_st_hvbPwrActvMod_ovrdval' */

/* Override value for signal st_hvbPwrActvMod */
extern const volatile uint8 vilc_st_hvbSocFlt_ovrdval;
                         /* Referenced by: '<S810>/vilc_st_hvbSocFlt_ovrdval' */

/* Override value for signal st_hvbSocFlt */
extern const volatile uint8 vilc_st_hvbSocJumpFlt_ovrdval;
                     /* Referenced by: '<S811>/vilc_st_hvbSocJumpFlt_ovrdval' */

/* Override value for signal st_hvbSocJumpFlt */
extern const volatile uint8 vilc_st_hvbStatus1_ovrdval;
                        /* Referenced by: '<S793>/vilc_st_hvbStatus1_ovrdval' */

/* Override value for signal st_hvbStatus1 */
extern const volatile uint8 vilc_st_hvbStatus2_ovrdval;
                        /* Referenced by: '<S778>/vilc_st_hvbStatus2_ovrdval' */

/* Override value for signal st_hvbStatus2 */
extern const volatile uint8 vilc_st_hvbStsChgFlt_ovrdval;
                      /* Referenced by: '<S812>/vilc_st_hvbStsChgFlt_ovrdval' */
extern const volatile uint8 vilc_st_hvbStsDischgFlt_ovrdval;
                   /* Referenced by: '<S813>/vilc_st_hvbStsDischgFlt_ovrdval' */
extern const volatile uint8 vilc_st_hvbSubFaultSts_ovrdval;
                    /* Referenced by: '<S814>/vilc_st_hvbSubFaultSts_ovrdval' */

/* Override value for signal BMS_SubFltLevel */
extern const volatile uint8 vilc_st_hvbTempFlt_ovrdval;
                        /* Referenced by: '<S815>/vilc_st_hvbTempFlt_ovrdval' */

/* Override value for signal st_hvbTempFlt */
extern const volatile uint8 vilc_st_hvbThermMngReq_ovrdval;
                    /* Referenced by: '<S816>/vilc_st_hvbThermMngReq_ovrdval' */

/* Override value for signal st_hvbThermMngReq */
extern const volatile uint8 vilc_st_inv2SubFltSts_ovrdval;
                     /* Referenced by: '<S641>/vilc_st_inv2SubFltSts_ovrdval' */

/* Override value for signal MCU_MotorSubFltLevel */
extern const volatile boolean vilc_st_ipkAlwChgSftCtlSt_ovrdval;
                /* Referenced by: '<S1148>/vilc_st_ipkAlwChgSftCtlSt_ovrdval' */
extern const volatile boolean vilc_st_ipkChgSftSwCtlSt_ovrdval;
                /* Referenced by: '<S1036>/vilc_st_ipkOdometerbackup_ovrdval' */
extern const volatile uint8 vilc_st_ipkCruisingDstSwt_ovrdval;
                /* Referenced by: '<S1037>/vilc_st_ipkCruisingDstSwt_ovrdval' */
extern const volatile uint8 vilc_st_iptWorkSt_ovrdval;
                         /* Referenced by: '<S359>/vilc_st_iptWorkSt_ovrdval' */
extern const volatile uint8 vilc_st_ipuInvTempHighAlm_ovrdval;
                 /* Referenced by: '<S642>/vilc_st_ipuInvTempHighAlm_ovrdval' */
extern const volatile uint8 vilc_st_ipuMotTempHighFlt_ovrdval;
                 /* Referenced by: '<S643>/vilc_st_ipuMotTempHighFlt_ovrdval' */
extern const volatile uint8 vilc_st_ipuMotorOverCurrFlt_ovrdval;
               /* Referenced by: '<S723>/vilc_st_ipuMotorOverCurrFlt_ovrdval' */
extern const volatile uint8 vilc_st_ipuMotorOverSpdFlt_ovrdval;
                /* Referenced by: '<S724>/vilc_st_ipuMotorOverSpdFlt_ovrdval' */
extern const volatile uint8 vilc_st_ipuMotorSubFltLvl_ovrdval;
                 /* Referenced by: '<S644>/vilc_st_ipuMotorSubFltLvl_ovrdval' */
extern const volatile uint8 vilc_st_lowPresRelsPrkLim_ovrdval;
                 /* Referenced by: '<S697>/vilc_st_lowPresRelsPrkLim_ovrdval' */

/* Override value for signal st_lowPresRelsPrkLim */
extern const volatile uint8 vilc_st_mmiRestSwitch_ovrdval;
                     /* Referenced by: '<S725>/vilc_st_mmiRestSwitch_ovrdval' */
extern const volatile uint8 vilc_st_obcChgCCSts_ovrdval;
                      /* Referenced by: '<S1149>/vilc_st_obcChgCCSts_ovrdval' */
extern const volatile uint8 vilc_st_obcChgSts_ovrdval;
                        /* Referenced by: '<S1150>/vilc_st_obcChgSts_ovrdval' */
extern const volatile uint8 vilc_st_obcElckStMod_ovrdval;
                     /* Referenced by: '<S1151>/vilc_st_obcElckStMod_ovrdval' */
extern const volatile uint8 vilc_st_obcLockLoopSts_ovrdval;
                   /* Referenced by: '<S1152>/vilc_st_obcLockLoopSts_ovrdval' */

/* Override value for signal OBC_LockLoopSts */
extern const volatile uint8 vilc_st_obcOnBdCCline_ovrdval;
                    /* Referenced by: '<S1153>/vilc_st_obcOnBdCCline_ovrdval' */
extern const volatile uint8 vilc_st_obcOnBdCPline_ovrdval;
                    /* Referenced by: '<S1154>/vilc_st_obcOnBdCPline_ovrdval' */
extern const volatile uint8 vilc_st_obcOnBdDchaCCline_ovrdval;
                    /* Referenced by: '<S1155>/vilc_st_obcOnBdCCline_ovrdval' */
extern const volatile uint8 vilc_st_obcSelfChk_ovrdval;
                        /* Referenced by: '<S1156>/vilc_st_dcChgCcSt_ovrdval' */

/* Override value for signal obcSelfChk */
extern const volatile uint8 vilc_st_obcfltLvl_ovrdval;
                        /* Referenced by: '<S1157>/vilc_st_dcChgCcSt_ovrdval' */

/* Override value for signal obcfltLvl */
extern const volatile uint8 vilc_st_pdcStsInfoCtrAlvCtrErr_ovrdval;
           /* Referenced by: '<S1295>/vilc_st_pdcStsInfoCtrAlvCtrErr_ovrdval' */
extern const volatile uint8 vilc_st_pdcStsInfoCtrCsmErr_ovrdval;
              /* Referenced by: '<S1296>/vilc_st_pdcStsInfoCtrCsmErr_ovrdval' */
extern const volatile uint8 vilc_st_pepsPduLvl_ovrdval;
                       /* Referenced by: '<S1185>/vilc_st_pepsPduLvl_ovrdval' */

/* Override value for signal pepsPduLvl */
extern const volatile uint8 vilc_st_pepsRKECom_ovrdval;
                       /* Referenced by: '<S1186>/vilc_st_pepsRKECom_ovrdval' */
extern const volatile uint8 vilc_st_prkBrkSts_ovrdval;
                         /* Referenced by: '<S698>/vilc_st_prkBrkSts_ovrdval' */

/* Override value for signal st_prkBrkSts */
extern const volatile uint8 vilc_st_ptCanNm_ovrdval;
                                /* Referenced by: '<S978>/vilc_u_Brk_ovrdval' */

/* Override value for signal st_ptCanNm */
extern const volatile uint8 vilc_st_ptcConnStsFb_ovrdval;
                      /* Referenced by: '<S360>/vilc_st_ptcConnStsFb_ovrdval' */
extern const volatile uint8 vilc_st_ptcWorkStRear_ovrdval;
                     /* Referenced by: '<S361>/vilc_st_ptcWorkStRear_ovrdval' */
extern const volatile uint8 vilc_st_rfrConnctSts_ovrdval;
                     /* Referenced by: '<S1221>/vilc_st_rfrConnctSts_ovrdval' */
extern const volatile uint64 vilc_st_rfrSeed_ovrdval;
                          /* Referenced by: '<S1222>/vilc_st_rfrSeed_ovrdval' */
extern const volatile uint64 vilc_st_rfrSwapBatCod_ovrdval;
                    /* Referenced by: '<S1223>/vilc_st_rfrSwapBatCod_ovrdval' */
extern const volatile uint8 vilc_st_rfrSwapprocd_ovrdval;
                     /* Referenced by: '<S1224>/vilc_st_rfrSwapprocd_ovrdval' */
extern const volatile uint8 vilc_st_tboxChgLmtSw_ovrdval;
           /* Referenced by: '<S1248>/vilc_st_tboxInventorySpdLmtReq_ovrdval' */
extern const volatile uint8 vilc_st_tboxChgSftSwCtlSt_ovrdval;
           /* Referenced by: '<S1249>/vilc_st_tboxInventorySpdLmtReq_ovrdval' */
extern const volatile uint8 vilc_st_tboxInventorySpdLmtReq_ovrdval;
           /* Referenced by: '<S1250>/vilc_st_tboxInventorySpdLmtReq_ovrdval' */

/* Override value for signal st_tboxInventorySpdLmtReq */
extern const volatile uint8 vilc_st_tboxLife_ovrdval;
                         /* Referenced by: '<S1251>/vilc_st_tboxLife_ovrdval' */

/* Override value for signal st_tboxLife */
extern const volatile uint8 vilc_st_tboxLockVehPerFlag_ovrdval;
               /* Referenced by: '<S1252>/vilc_st_tboxLockVehPerFlag_ovrdval' */

/* Override value for signal st_tboxLockVehPerFlag */
extern const volatile uint8 vilc_st_tboxPrtFullSwSt_ovrdval;
                         /* Referenced by: '<S1253>/vilc_st_tboxLife_ovrdval' */
extern const volatile uint8 vilc_st_tboxRsrChgSt_ovrdval;
              /* Referenced by: '<S1254>/vilc_st_tboxStartBattChgReq_ovrdval' */
extern const volatile uint8 vilc_st_tboxSpdLmtLevelReq_ovrdval;
               /* Referenced by: '<S1255>/vilc_st_tboxSpdLmtLevelReq_ovrdval' */

/* Override value for signal st_tboxSpdLmtLevelReq */
extern const volatile uint8 vilc_st_tboxStartBattChgReq_ovrdval;
              /* Referenced by: '<S1256>/vilc_st_tboxStartBattChgReq_ovrdval' */

/* Override value for signal st_tboxStartBattChgReq */
extern const volatile uint8 vilc_st_tboxVersionConversionFlag_ovrdval;
        /* Referenced by: '<S1257>/vilc_st_tboxVersionConversionFlag_ovrdval' */

/* Override value for signal st_tboxVersionConversionFlag */
extern const volatile uint8 vilc_st_tmpPrkActv_ovrdval;
                        /* Referenced by: '<S699>/vilc_st_tmpPrkActv_ovrdval' */

/* Override value for signal st_tmpPrkActv */
extern const volatile uint8 vilc_st_tmpPrkBrkSts_ovrdval;
                      /* Referenced by: '<S700>/vilc_st_tmpPrkBrkSts_ovrdval' */

/* Override value for signal st_tmpPrkBrkSts */
extern const volatile uint8 vilc_st_trsm2GearAct_ovrdval;
                     /* Referenced by: '<S1278>/vilc_st_trsm2GearAct_ovrdval' */

/* Override value for signal TCU_CurrentGear */
extern const volatile uint8 vilc_st_trsm2GearShftReq_ovrdval;
                 /* Referenced by: '<S1279>/vilc_st_trsm2GearShftReq_ovrdval' */

/* Override value for signal TCU_Gearshift_Req */
extern const volatile uint8 vilc_st_trsm2Unauthorized_ovrdval;
                     /* Referenced by: '<S1280>/vilc_st_trsm2GearSts_ovrdval' */

/* Override value for signal TCU_unauthorized */
extern const volatile uint32 vilc_st_vehNtwrkConfigData1_ovrdval;
              /* Referenced by: '<S1059>/vilc_st_vehNtwrkConfigData1_ovrdval' */

/* Override value for signal Veh_Network_Config_Data1 */
extern const volatile uint32 vilc_st_vehNtwrkConfigData2_ovrdval;
              /* Referenced by: '<S1060>/vilc_st_vehNtwrkConfigData2_ovrdval' */

/* Override value for signal Veh_Network_Config_Data2 */
extern const volatile uint8 vilc_st_vscAbsActv_ovrdval;
                       /* Referenced by: '<S1309>/vilc_st_vscAbsActv_ovrdval' */

/* Override value for signal st_vscAbsActv */
extern const volatile uint8 vilc_st_vscEHBAVHSts_ovrdval;
                     /* Referenced by: '<S1310>/vilc_st_vscEHBAVHSts_ovrdval' */
extern const volatile float32 vilc_t_24vDcdcTemp_ovrdval;
                        /* Referenced by: '<S579>/vilc_t_24vDcdcTemp_ovrdval' */

/* Override value for signal t_24vDcdcTemp */
extern const volatile float32 vilc_t_TS5OutTempFltSet;/* Referenced by:
                                                       * '<S929>/Constant'
                                                       * '<S933>/Constant'
                                                       * '<S937>/Constant'
                                                       */
extern const volatile float32 vilc_t_acwpOutptTemp_ovrdval;
                      /* Referenced by: '<S362>/vilc_t_acwpOutptTemp_ovrdval' */

/* Override value for signal EWP_OutputTemp */
extern const volatile float32 vilc_t_adc02Temp_ovrdval;
                          /* Referenced by: '<S436>/vilc_t_adc02Temp_ovrdval' */
extern const volatile float32 vilc_t_adc0Temp_ovrdval;
                           /* Referenced by: '<S437>/vilc_t_adc0Temp_ovrdval' */
extern const volatile float32 vilc_t_adc12Temp_ovrdval;
                          /* Referenced by: '<S438>/vilc_t_adc12Temp_ovrdval' */
extern const volatile float32 vilc_t_adc1Temp_ovrdval;
                           /* Referenced by: '<S439>/vilc_t_adc1Temp_ovrdval' */
extern const volatile float32 vilc_t_eadInv2Temp_ovrdval;
                        /* Referenced by: '<S645>/vilc_t_eadInv2Temp_ovrdval' */

/* Override value for signal t_eadInv2Temp */
extern const volatile float32 vilc_t_eadMot2Temp_ovrdval;
                        /* Referenced by: '<S646>/vilc_t_eadMot2Temp_ovrdval' */

/* Override value for signal t_eadMot2Temp */
extern const volatile float32 vilc_t_hvbAvg_ovrdval;
                             /* Referenced by: '<S817>/vilc_t_hvbAvg_ovrdval' */

/* Override value for signal t_hvbAvg */
extern const volatile float32 vilc_t_hvbCooltInTemp_ovrdval;
                                /* Referenced by: '<S980>/vilc_u_Brk_ovrdval' */

/* Override value for signal hvbCooltInTemp */
extern const volatile float32 vilc_t_hvbCooltOutTemp_ovrdval;
                                /* Referenced by: '<S981>/vilc_u_Brk_ovrdval' */

/* Override value for signal hvbCooltOutTemp */
extern const volatile float32 vilc_t_hvbInCoolTemp_ovrdval;
                        /* Referenced by: '<S803>/vilc_st_hvbTempFlt_ovrdval' */

/* Override value for signal hvbInCoolTemp */
extern const volatile float32 vilc_t_hvbMax_ovrdval;
                             /* Referenced by: '<S818>/vilc_t_hvbMax_ovrdval' */

/* Override value for signal t_hvbMax */
extern const volatile float32 vilc_t_hvbMin_ovrdval;
                             /* Referenced by: '<S819>/vilc_t_hvbMin_ovrdval' */

/* Override value for signal t_hvbMin */
extern const volatile float32 vilc_t_hvbOutCoolTemp_ovrdval;
                     /* Referenced by: '<S820>/vilc_t_hvbOutCoolTemp_ovrdval' */

/* Override value for signal BMS_BattPackOutCoolTemp */
extern const volatile float32 vilc_t_hvbSetTgtTemp_ovrdval;
                      /* Referenced by: '<S821>/vilc_t_hvbSetTgtTemp_ovrdval' */

/* Override value for signal BMS_SetTgtTemp */
extern const volatile float32 vilc_t_obcTemp_ovrdval;
                           /* Referenced by: '<S1158>/vilc_t_obcTemp_ovrdval' */
extern const volatile float32 vilc_t_outdTemp_ovrdval;
                           /* Referenced by: '<S363>/vilc_t_outdTemp_ovrdval' */

/* Override value for signal t_outdTemp */
extern const volatile float32 vilc_t_tboxDay_ovrdval;
                           /* Referenced by: '<S1258>/vilc_t_tboxDay_ovrdval' */

/* Override value for signal t_tboxDay */
extern const volatile float32 vilc_t_tboxHr_ovrdval;
                            /* Referenced by: '<S1259>/vilc_t_tboxHr_ovrdval' */

/* Override value for signal t_tboxHr */
extern const volatile float32 vilc_t_tboxMins_ovrdval;
                          /* Referenced by: '<S1260>/vilc_t_tboxMins_ovrdval' */

/* Override value for signal t_tboxMins */
extern const volatile float32 vilc_t_tboxMth_ovrdval;
                           /* Referenced by: '<S1261>/vilc_t_tboxMth_ovrdval' */

/* Override value for signal t_tboxMth */
extern const volatile float32 vilc_t_tboxSec_ovrdval;
                           /* Referenced by: '<S1262>/vilc_t_tboxSec_ovrdval' */

/* Override value for signal t_tboxSec */
extern const volatile float32 vilc_t_tboxYr_ovrdval;
                            /* Referenced by: '<S1263>/vilc_t_tboxYr_ovrdval' */

/* Override value for signal t_tboxYr */
extern const volatile float32 vilc_tm_aTCycTm_s;/* Referenced by:
                                                 * '<S930>/Constant16'
                                                 * '<S930>/Constant3'
                                                 * '<S934>/Constant16'
                                                 * '<S934>/Constant3'
                                                 * '<S938>/Constant16'
                                                 * '<S938>/Constant3'
                                                 */

/* Average time for Engine Coolent temperature  */
extern const volatile uint16 vilc_tm_hvbFnshChgTim_ovrdval;
                     /* Referenced by: '<S822>/vilc_tm_hvbFnshChgTim_ovrdval' */
extern const volatile float32 vilc_tm_hvilDetctDly_s;/* Referenced by:
                                                      * '<S4>/Constant22'
                                                      * '<S4>/Constant3'
                                                      * '<S10>/Constant12'
                                                      * '<S10>/Constant9'
                                                      */
extern const volatile float32 vilc_tm_pepsMsgErr2fail_s;
                                     /* Referenced by: '<S1180>/t_delay_fail' */
extern const volatile float32 vilc_tm_pepsMsgErr2heal_s;
                                     /* Referenced by: '<S1180>/t_delay_heal' */
extern const volatile float32 vilc_tq_adc02TargetDrvTq_ovrdval;
                  /* Referenced by: '<S440>/vilc_tq_adc02TargetDrvTq_ovrdval' */
extern const volatile float32 vilc_tq_adc0TargetDrvTq_Nm_ovrdval;
                /* Referenced by: '<S441>/vilc_tq_adc0TargetDrvTq_Nm_ovrdval' */
extern const volatile float32 vilc_tq_adc12TargetDrvTq_ovrdval;
                  /* Referenced by: '<S442>/vilc_tq_adc12TargetDrvTq_ovrdval' */
extern const volatile float32 vilc_tq_adc1TargetDrvTq_ovrdval;
                   /* Referenced by: '<S443>/vilc_tq_adc1TargetDrvTq_ovrdval' */
extern const volatile float32 vilc_tq_eadMot2ActTq_ovrdval;
                      /* Referenced by: '<S647>/vilc_tq_eadMot2ActTq_ovrdval' */

/* Override value for signal tq_eadMot2ActTq */
extern const volatile float32 vilc_tq_eadMot2LTBstTqLim_ovrdval;
                 /* Referenced by: '<S648>/vilc_tq_eadMot2LTBstTqLim_ovrdval' */

/* Override value for signal tq_eadMot2LTBstTqLim */
extern const volatile float32 vilc_tq_eadMot2LTGenTqLim_ovrdval;
                 /* Referenced by: '<S649>/vilc_tq_eadMot2LTGenTqLim_ovrdval' */

/* Override value for signal tq_eadMot2LTGenTqLim */
extern const volatile float32 vilc_tq_ehbIsaPtTrqDecReq_ovrdval;
                /* Referenced by: '<S1311>/vilc_tq_ehbIsaPtTrqDecReq_ovrdval' */
extern const volatile float32 vilc_tq_vscEHBMbRgnTgtWhl_ovrdval;
                /* Referenced by: '<S1312>/vilc_tq_vscEHBMbRgnTgtWhl_ovrdval' */
extern const volatile float32 vilc_tq_vscEHBPtTrqDecReq_ovrdval;
                /* Referenced by: '<S1313>/vilc_tq_vscEHBPtTrqDecReq_ovrdval' */
extern const volatile float32 vilc_tq_vscEHBPtTrqIncReq_ovrdval;
                /* Referenced by: '<S1314>/vilc_tq_vscEHBPtTrqIncReq_ovrdval' */
extern const volatile float32 vilc_tq_vscEHBVlcPtTrqReq_ovrdval;
                /* Referenced by: '<S1315>/vilc_tq_vscEHBVlcPtTrqReq_ovrdval' */
extern const volatile float32 vilc_u_5VT1IntSmpl_ovrdval;
                                /* Referenced by: '<S982>/vilc_u_Brk_ovrdval' */

/* 5VT1 voltage */
extern const volatile float32 vilc_u_5VT2IntSmpl_ovrdval;
                                /* Referenced by: '<S983>/vilc_u_Brk_ovrdval' */

/* 5VT2 voltage */
extern const volatile float32 vilc_u_Acc1Raw_ovrdval;
                                /* Referenced by: '<S984>/vilc_u_Brk_ovrdval' */

/* Override value of Acc1Raw */
extern const volatile float32 vilc_u_Acc1_ovrdval;
                               /* Referenced by: '<S985>/vilc_u_Acc1_ovrdval' */

/* Override value for signal u_Acc1 */
extern const volatile float32 vilc_u_Acc2Raw_ovrdval;
                                /* Referenced by: '<S986>/vilc_u_Brk_ovrdval' */

/* Override value of Acc2Raw */
extern const volatile float32 vilc_u_Acc2_ovrdval;
                               /* Referenced by: '<S987>/vilc_u_Acc2_ovrdval' */

/* Override value for signal u_Acc2 */
extern const volatile float32 vilc_u_BmsMaxCellVolt_ovrdval;
                     /* Referenced by: '<S823>/vilc_u_BmsMaxCellVolt_ovrdval' */

/* Override value for signal BMS_MaxCellVolt */
extern const volatile float32 vilc_u_BmsMinCellVolt_ovrdval;
                     /* Referenced by: '<S824>/vilc_u_BmsMinCellVolt_ovrdval' */

/* Override value for signal BMS_MinCellVolt */
extern const volatile float32 vilc_u_Brk2Raw_ovrdval;
                                /* Referenced by: '<S990>/vilc_u_Brk_ovrdval' */

/* Override value of Brk2Raw */
extern const volatile float32 vilc_u_Brk2_ovrdval;
                                /* Referenced by: '<S989>/vilc_u_Brk_ovrdval' */

/* Override value for signal u_Brk */
extern const volatile float32 vilc_u_BrkRaw_ovrdval;
                                /* Referenced by: '<S991>/vilc_u_Brk_ovrdval' */

/* Override value of BrkRaw */
extern const volatile float32 vilc_u_Brk_ovrdval;
                                /* Referenced by: '<S988>/vilc_u_Brk_ovrdval' */

/* Override value for signal u_Brk */
extern const volatile boolean vilc_u_HandBrk_ovrdval;
                            /* Referenced by: '<S992>/vilc_u_HandBrk_ovrdval' */

/* Override value for signal u_HandBrk */
extern const volatile float32 vilc_u_TS5sensorFb_ovrdval;
                                /* Referenced by: '<S993>/vilc_u_Brk_ovrdval' */

/* Override value of TS5sensorFb */
extern const volatile float32 vilc_u_VacTkAirPres_ovrdval;
                                /* Referenced by: '<S994>/vilc_u_Brk_ovrdval' */
extern const volatile float32 vilc_u_VacTkEnFb_ovrdval;
                          /* Referenced by: '<S995>/vilc_u_VacTkEnFb_ovrdval' */
extern const volatile float32 vilc_u_acPresVolt_ovrdval;
                         /* Referenced by: '<S343>/vilc_u_acPresVolt_ovrdval' */

/* Override value for signal acPresVolt */
extern const volatile float32 vilc_u_batIntSmpl_ovrdval;
                                /* Referenced by: '<S996>/vilc_u_Brk_ovrdval' */

/* Low voltage battery voltage */
extern const volatile float32 vilc_u_batLpPmpCtrlFb_ovrdval;
                                /* Referenced by: '<S997>/vilc_u_Brk_ovrdval' */

/* Override value of batLpPmpCtrlFb */
extern const volatile float32 vilc_u_brkVacuumPres_ovrdval;
                      /* Referenced by: '<S522>/vilc_u_brkVacuumPres_ovrdval' */
extern const volatile float32 vilc_u_cbnLpPmpCtrlFb_ovrdval;
                                /* Referenced by: '<S998>/vilc_u_Brk_ovrdval' */

/* Override value of cbnLpPmpCtrlFb */
extern const volatile float32 vilc_u_cruiseADvoltage_ovrdval;
                    /* Referenced by: '<S999>/vilc_u_cruiseADvoltage_ovrdval' */

/* Override value for signal CruiseCtrlInp_V */
extern const volatile float32 vilc_u_dcdcInpVolt_ovrdval;
                        /* Referenced by: '<S580>/vilc_u_dcdcInpVolt_ovrdval' */
extern const volatile float32 vilc_u_dcdcOutpVolt_ovrdval;
                       /* Referenced by: '<S581>/vilc_u_dcdcOutpVolt_ovrdval' */

/* Override value for signal u_dcdcOutpVolt */
extern const volatile float32 vilc_u_dcdcRelayVolt_ovrdval;
                      /* Referenced by: '<S582>/vilc_u_dcdcRelayVolt_ovrdval' */
extern const volatile float32 vilc_u_eLpWpCtrlCur_ovrdval;
                               /* Referenced by: '<S1000>/vilc_u_Brk_ovrdval' */

/* Override value of eLpWpCtrlCur */
extern const volatile float32 vilc_u_eadInv2ActVoltDC_ovrdval;
                   /* Referenced by: '<S650>/vilc_u_eadInv2ActVoltDC_ovrdval' */

/* Override value for signal u_eadInv2ActVoltDC */
extern const volatile float32 vilc_u_hcmAcceRlyVolt_ovrdval;
                     /* Referenced by: '<S726>/vilc_u_hcmAcceRlyVolt_ovrdval' */
extern const volatile float32 vilc_u_hcmMainPosBckVolt_ovrdval;
                  /* Referenced by: '<S727>/vilc_u_hcmMainPosBckVolt_ovrdval' */
extern const volatile float32 vilc_u_hcmPtcRlyVolt_ovrdval;
                      /* Referenced by: '<S728>/vilc_u_hcmPtcRlyVolt_ovrdval' */
extern const volatile float32 vilc_u_hvbCooltInSnsr_ovrdval;
                               /* Referenced by: '<S1001>/vilc_u_Brk_ovrdval' */

/* Override value for signal hvbCooltInSnsr */
extern const volatile float32 vilc_u_hvbCooltOutSnsr_ovrdval;
                               /* Referenced by: '<S1002>/vilc_u_Brk_ovrdval' */

/* Override value for signal hvbCooltOutSnsr */
extern const volatile float32 vilc_u_hvbPackVolt_ovrdval;
                        /* Referenced by: '<S825>/vilc_u_hvbPackVolt_ovrdval' */

/* Override value for signal u_hvbVolt */
extern const volatile float32 vilc_u_hvbVolt_ovrdval;
                            /* Referenced by: '<S826>/vilc_u_hvbVolt_ovrdval' */

/* Override value for signal u_hvbVolt */
extern const volatile float32 vilc_u_ipuHVBusVolt_ovrdval;
                       /* Referenced by: '<S651>/vilc_u_ipuHVBusVolt_ovrdval' */
extern const volatile float32 vilc_u_obcOutptVolt_ovrdval;
                      /* Referenced by: '<S1159>/vilc_u_obcOutptVolt_ovrdval' */
extern const volatile boolean vilc_u_obcWakeHCU_ovrdval;
                        /* Referenced by: '<S1003>/vilc_u_obcWakeHCU_ovrdval' */

/* Override value for signal u_obcWakeHCU */
extern const volatile boolean vilc_u_pepsON_ovrdval;
                            /* Referenced by: '<S1004>/vilc_u_pepsON_ovrdval' */

/* Override value for signal u_pepsON */
extern const volatile float32 vilc_u_pepsOnmV_ovrdval;
                  /* Referenced by: '<S1005>/vilc_pct_WatPmpEP2FbPWM_ovrdval' */

/* Override value for signal u_pepsOn */
extern const volatile boolean vilc_u_pepsStart_ovrdval;
                         /* Referenced by: '<S1006>/vilc_u_pepsStart_ovrdval' */

/* Override value for signal u_pepsStart */
extern const volatile uint16 vilc_u_vacTkPowSup_ovrdval;
                       /* Referenced by: '<S1007>/vilc_u_vacTkPowSup_ovrdval' */
extern const volatile uint8 vilc_v_AvrgVehSpd_ovrdval;
                        /* Referenced by: '<S1038>/vilc_v_AvrgVehSpd_ovrdval' */

/* Override value for signal IC_AverageVehSpd */
extern const volatile float32 vilc_v_brkLhtVehSpd_kph;/* Referenced by: '<S20>/Constant15' */
extern const volatile float32 vilc_v_ehbVehMaxSpd_kph;/* Referenced by: '<S1354>/Constant44' */
extern const volatile float32 vilc_v_ehbVehSpd_ovrdval;
                     /* Referenced by: '<S1316>/vilc_st_vscEHBAVHSts_ovrdval' */
extern const volatile float32 vilc_v_vscWhlFLSpd_ovrdval;
                       /* Referenced by: '<S1317>/vilc_v_vscWhlFLSpd_ovrdval' */

/* Override value for signal v_vscWhlFLSpd */
extern const volatile float32 vilc_v_vscWhlFRSpd_ovrdval;
                       /* Referenced by: '<S1318>/vilc_v_vscWhlFRSpd_ovrdval' */

/* Override value for signal v_vscWhlFRSpd */
extern const volatile float32 vilc_v_vscWhlRLSpd_ovrdval;
                       /* Referenced by: '<S1319>/vilc_v_vscWhlRLSpd_ovrdval' */

/* Override value for signal v_vscWhlRLSpd */
extern const volatile float32 vilc_v_vscWhlRRSpd_ovrdval;
                       /* Referenced by: '<S1320>/vilc_v_vscWhlRRSpd_ovrdval' */

/* Override value for signal v_vscWhlRRSpd */
extern const volatile float32 vilf_X_brkPedl2Pos_mV[3];
                                 /* Referenced by: '<S921>/1-D Lookup Table6' */
extern const volatile float32 vilf_X_brkPedlPos_mV[3];
                                 /* Referenced by: '<S921>/1-D Lookup Table1' */
extern const volatile float32 vilf_X_hvbCooltInTemp_mV[15];
                                 /* Referenced by: '<S921>/1-D Lookup Table7' */
extern const volatile float32 vilf_X_hvbCooltOutTemp_mV[15];
                                 /* Referenced by: '<S921>/1-D Lookup Table8' */
extern const volatile float32 vilf_X_ts5Temp_mV[15];
                                 /* Referenced by: '<S921>/1-D Lookup Table2' */
extern const volatile float32 vilf_Y_brkPedl2Pos_pct[3];
                                 /* Referenced by: '<S921>/1-D Lookup Table6' */
extern const volatile float32 vilf_Y_brkPedlPos_pct[3];
                                 /* Referenced by: '<S921>/1-D Lookup Table1' */
extern const volatile float32 vilf_Y_hvbCooltInTemp_degC[15];
                                 /* Referenced by: '<S921>/1-D Lookup Table7' */
extern const volatile float32 vilf_Y_hvbCooltOutTemp_degC[15];
                                 /* Referenced by: '<S921>/1-D Lookup Table8' */
extern const volatile float32 vilf_Y_ts5Temp_degC[15];
                                 /* Referenced by: '<S921>/1-D Lookup Table2' */
extern const volatile uint8 volc_VCU_DCDCEnableOut_ovrdval;
                  /* Referenced by: '<S200>/vilc_st_dccAccyConnStsFb_ovrdval' */

/* Override value for signal VCU_DCDCEnableOut */
extern const volatile boolean volc_b_VCU_DCDCEnableOut_ovrdflg;
                   /* Referenced by: '<S200>/vilc_b_dccAccyConnStsFb_ovrdflg' */

/* Override flag for signal b_VCU_DCDCEnableOut */
extern const volatile float32 vscc_X_acpPrsdThd_pct;/* Referenced by: '<S294>/Constant2' */

/* Accel Pedal Pressed Threshold */
extern const volatile uint8 vscc_ctr_absActvMax;/* Referenced by: '<S20>/Constant1' */

/* ABS Active before setting fault */
extern const volatile float32 vscc_t_motSpdFiltTc_s;/* Referenced by: '<S20>/Constant39' */

/* Vehicle speed time constant for 1 order filter */
extern const volatile float32 vscc_tm_ESPDeactvnDly_s;/* Referenced by: '<S20>/Constant9' */

/* ESP Deactivation delay */
extern const volatile float32 vscc_tm_vehSpdFilter1_s;/* Referenced by: '<S302>/pred2' */
extern const volatile float32 vscc_tm_vehSpdFilter2_s;/* Referenced by: '<S302>/pred4' */

#define swc_VCIP_STOP_SEC_CONST_VOLATILE
#include "swc_VCIP_MemMap.h"
#define swc_VCIP_START_SEC_VAR
#include "swc_VCIP_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern boolean accd_b_acHvilDtyOpn;    /* '<S4>/Logical Operator3' */

/* AC Duty HVIL Open */
extern boolean accd_b_acHvilOpn;       /* '<S4>/Switch' */

/* AC HVIL Open */
extern boolean accd_b_acHvilOpnEnb;    /* '<S4>/Logical Operator4' */
extern boolean accd_b_acHvilOpnInvld;  /* '<S4>/Switch1' */
extern McuSts accd_e_PtcSt;            /* '<S25>/Switch' */

/* AC PTC Status */
extern FaultStatus accd_e_acFltLvl;    /* '<S26>/Switch' */

/* AC Fault Level */
extern McuSts accd_e_airCmprSt;        /* '<S27>/Switch' */

/* AC Air Cmpr Status */
extern uint8 accd_st_AcWrk;            /* '<S4>/Signal Conversion8' */

/* AC work status enable */
extern uint8 accd_st_acSubFltSts;      /* '<S4>/Signal Conversion18' */

/* AC sub fault status */
extern uint8 accd_st_airCmprSt;        /* '<S4>/Signal Conversion14' */

/* ACCM Status */
extern uint8 accd_st_iptWorkSt;        /* '<S4>/Signal Conversion21' */
extern uint8 accd_st_ptcWorkStRear;    /* '<S4>/Signal Conversion22' */
extern float32 accd_t_ambTemp_C;       /* '<S4>/Signal Conversion5' */

/* AC Outside Temperature */
extern boolean acpd_b_accPedlPosVld;   /* '<S33>/Logical Operator2' */

/* Accelerator Pedal position valid */
extern boolean acpd_b_brkPedlPrsd;     /* '<S45>/Logical Operator2' */

/* Brake Pedal Pressed - risk of Pedals Overlap */
extern float32 acpd_u_accPedlPosSens1Filt_V;/* '<S53>/Data Type Conversion3' */

/* Accel Pedal Sensor 1 signal filtered */
extern float32 acpd_u_accPedlPosSens1Lim_V;/* '<S51>/Switch1' */

/* Accel Pedal Sensor 1 signal limited */
extern float32 acpd_u_accPedlPosSens1VoltRaw_V;/* '<S51>/Signal Conversion1' */

/* Accel Pedal Sensor 1 signal raw */
extern float32 acpd_u_accPedlPosSens2Filt_V;/* '<S55>/Data Type Conversion3' */

/* Accel Pedal Sensor 2 signal filtered */
extern float32 acpd_u_accPedlPosSens2Lim_V;/* '<S52>/Switch1' */

/* Accel Pedal Sensor 2 signal limited */
extern float32 acpd_u_accPedlPosSens2VoltRaw_V;/* '<S52>/Signal Conversion1' */

/* Accel Pedal Sensor 2 signal raw */
extern float32 acpd_x_accPedlPosCan_pct;/* '<S32>/Switch1' */

/* Accelerator Pedal position sent to CAN */
extern float32 acpd_x_accPedlPosFiltdCan_pct;/* '<S43>/Data Type Conversion3' */

/* Accelerator Pedal position filtered sent to CAN */
extern float32 acpd_x_accPedlPosFiltd_pct;/* '<S42>/Data Type Conversion3' */

/* Accelerator Pedal position filtered */
extern float32 acpd_x_accPedlPosLimd_pct;/* '<S34>/Switch2' */

/* Limited accelerator pedal position */
extern float32 acpd_x_accPedlPosSens1_pct;/* '<S51>/Switch2' */

/* Accel Pedal 1 position */
extern float32 acpd_x_accPedlPosSens2_pct;/* '<S52>/Switch2' */

/* Accel Pedal 2 position */
extern float32 acpd_x_accPedlPosUnfiltdCan_pct;/* '<S33>/Switch' */

/* Accelerator Pedal position unfiltered sent to CAN */
extern float32 acpd_x_accPedlPosUnfiltd_pct;/* '<S33>/Switch1' */

/* Accelerator Pedal position unfiltered */
extern float32 acpd_x_accPedlPos_pct;  /* '<S32>/Switch2' */

/* Accelerator Pedal position */
extern boolean adcd_b_adc01ComFlt;     /* '<S6>/Logical Operator1' */
extern boolean adcd_b_adc01CtrlReq;    /* '<S6>/Logical Operator50' */
extern boolean adcd_b_adc02ComFlt;     /* '<S6>/Logical Operator4' */
extern boolean adcd_b_adc02CtrlReq;    /* '<S6>/Logical Operator53' */
extern boolean adcd_b_adc11ComFlt;     /* '<S6>/Logical Operator3' */
extern boolean adcd_b_adc11CtrlReq;    /* '<S6>/Logical Operator40' */
extern boolean adcd_b_adc12ComFlt;     /* '<S6>/Logical Operator5' */
extern boolean adcd_b_adc12CtrlReq;    /* '<S6>/Logical Operator43' */
extern boolean adcd_b_adc1CtrlTorqEn;  /* '<S6>/Switch6' */
extern boolean adcd_b_adc1SwtchCtrlReq;/* '<S6>/Switch10' */
extern boolean adcd_b_adcCtrlGearEn;   /* '<S6>/Switch1' */
extern boolean adcd_b_adcCtrlTorqEn;   /* '<S6>/Switch22' */
extern uint8 adcd_st_adcTgtGearPostn;  /* '<S6>/Switch4' */
extern float32 adcd_tq_adc1TgtDrvTorq_Nm;/* '<S6>/Switch17' */
extern float32 adcd_tq_adcTgtDrvTorq_Nm;/* '<S6>/Switch13' */
extern boolean brpd_b_DryAirSwitch;    /* '<S7>/Signal Conversion5' */

/* Dry Air Switch */
extern boolean brpd_b_ResrAirSwitch;   /* '<S7>/Signal Conversion6' */

/* Resr Air Switch */
extern boolean brpd_b_brakeSwitch1Closed;/* '<S96>/Switch' */

/* Brake switch 1 closed */
extern boolean brpd_b_brakeSwitch1Deb; /* '<S97>/timed_debounce' */

/* Brake switch 1 debounced */
extern boolean brpd_b_brakeSwitch2Closed;/* '<S96>/Switch1' */

/* Brake switch 2 closed */
extern boolean brpd_b_brakeSwitch2Deb; /* '<S98>/timed_debounce' */

/* Brake switch 2 debounced */
extern boolean brpd_b_brkPedlPosVld;   /* '<S7>/Signal Conversion1' */

/* Brake Pedal Position Valid */
extern boolean brpd_b_brkPedlStsVld;   /* '<S7>/Signal Conversion2' */

/* Brake Pedal Status Valid */
extern boolean brpd_b_brkPmpSelfChkErr;/* '<S7>/Signal Conversion7' */

/* Brake Pump Self Check Error */
extern boolean brpd_b_brkPmpSelfChkOk; /* '<S7>/Signal Conversion11' */

/* Brake Pump Self Check OK */
extern boolean brpd_b_brkPressedFromSwitch;/* '<S96>/Switch2' */

/* Brake Pressed from Switch */
extern boolean brpd_b_brkPumpFault;    /* '<S7>/Signal Conversion10' */

/* Brake Pump Fault */
extern boolean brpd_b_vacTankLowPrs;   /* '<S7>/Signal Conversion9' */

/* Brake Vacuum Tank Pressure Low Flag */
extern McuSts brpd_e_bdcacWrk;         /* '<S85>/Switch' */

/* Brake Pump Work Status */
extern BrakePedalStatus brpd_e_brkPedalStatus;/* '<S80>/Merge' */

/* Brake Pedal Status */
extern float32 brpd_p_AirPres_kpa;     /* '<S7>/1-D Lookup Table1' */

/* Air Pressure */
extern float32 brpd_p_brkVacuumPres_bar;/* '<S82>/1-D Lookup Table1' */

/* Brake vacuum Pressure */
extern uint8 brpd_st_bdcacWrk;         /* '<S7>/Signal Conversion3' */

/* Brake pump work status enable */
extern float32 brpd_x_brkPedlPos_pct;  /* '<S7>/Signal Conversion4' */

/* Brake Pedal position */
extern float32 ccdd_u_cruiseADvoltage_V;/* '<S8>/Signal Conversion2' */

/* Cruise Control Button Voltage */
extern boolean cesd_b_ACUMsgErr;       /* '<S106>/Switch2' */
extern boolean cesd_b_EmergencyStop;   /* '<S9>/Signal Conversion4' */

/* Emergency Stop signal */
extern boolean cesd_b_crash;           /* '<S9>/Switch2' */

/* Crash Signal */
extern boolean cesd_b_crashRaw;        /* '<S9>/Logical Operator1' */

/* Crash Signal */
extern boolean dccd_b_dcdcCutOffLvFb;  /* '<S10>/Signal Conversion10' */

/* DC/DC Low Voltage Cut Off Allow */
extern boolean dccd_b_dcdcHvilFlt;     /* '<S10>/Switch3' */

/* DC/DC HVIL Fault */
extern boolean dccd_b_dcdcHvilFltEnb;  /* '<S10>/Logical Operator5' */
extern boolean dccd_b_dcdcHvilFltInvld;/* '<S10>/Switch4' */
extern boolean dccd_b_dcdcSelfChkErr;  /* '<S10>/Signal Conversion8' */

/* DC/DC Self Check Error */
extern boolean dccd_b_dcdcSelfChkOk;   /* '<S10>/Signal Conversion7' */

/* DC/DC Self Check OK */
extern boolean dccd_b_odpHvilDtyOpn;   /* '<S10>/Logical Operator3' */

/* DC/DC HVIL Duty Fault */
extern McuSts dccd_e_24vDcdcModAct;    /* '<S114>/Switch' */

/* DC/DC Work Status */
extern FaultStatus dccd_e_dcdcFaultStatus;/* '<S113>/Switch' */

/* DC/DC Fault Status */
extern DCDCMode dccd_e_modeAct;        /* '<S112>/Switch2' */

/* DC/DC Actual Mode */
extern float32 dccd_pwr_dcdcHVpwr_kW;  /* '<S117>/Product' */

/*  DCDC HV input power  */
extern uint8 dccd_st_24vDcdcFltSts;    /* '<S10>/Signal Conversion6' */

/* DC/DC Fault Status */
extern uint8 dccd_st_24vDcdcSubFltSts; /* '<S10>/Signal Conversion11' */

/* DC/DC sub fault status */
extern float32 dccd_t_dcdcTemp_C;      /* '<S10>/Signal Conversion1' */

/* DC/DC temperature */
extern boolean drid_b_drvrModeReq;     /* '<S123>/Switch2' */
extern boolean drid_b_drvrModeReq4WD;  /* '<S11>/Signal Conversion5' */

/* Driver Mode Request 4WD */
extern boolean drid_b_drvrModeReqECO;  /* '<S123>/Constant3' */

/* Driver Mode Request ECO */
extern boolean drid_b_drvrModeReqEV;   /* '<S11>/Signal Conversion4' */

/* Driver Mode Request EV */
extern boolean drid_b_drvrModeReqHEV;  /* '<S11>/Signal Conversion1' */

/* Driver Mode Request HEV */
extern boolean drid_b_drvrModeReqSPORT;/* '<S11>/Signal Conversion3' */

/* Driver Mode Request SPORT */
extern GearLeverPos drid_e_gearLvrPosRaw;/* '<S11>/Switch1' */

/* Gear Lever Position Raw */
extern uint8 drid_st_gearLvrPosSeql;   /* '<S11>/Signal Conversion7' */

/* Sequencial Gear Lever Position */
extern uint8 drid_st_parkBtnPressed;   /* '<S11>/Signal Conversion6' */

/* Park Button pressed */
extern boolean eadd_b_eadInv2ActvDischCmplt;/* '<S134>/Relational Operator' */

/* Secondary EAD Auto Discharge finished */
extern boolean eadd_b_eadInv2RdyToCutOffLV;/* '<S133>/Relational Operator' */

/* Secondary EAD Ready To Cutoff LV */
extern boolean eadd_b_eadInv2SelfChkErr;/* '<S12>/Signal Conversion15' */

/* Secondary EAD Self Check Error */
extern boolean eadd_b_eadInv2SelfChkOk;/* '<S12>/Signal Conversion12' */

/* Secondary EAD Self Check OK */
extern McuSts eadd_e_eadInv2Sts;       /* '<S138>/Switch' */

/* Secondary EAD Work Status */
extern FaultStatus eadd_e_inv21FltSts; /* '<S137>/Switch' */

/* Secondary EAD21 Fault Status */
extern FaultStatus eadd_e_inv2FltSts;  /* '<S136>/Switch' */

/* Secondary EAD Fault Status */
extern ElMac eadd_e_inv2ModeAct;       /* '<S135>/Switch' */

/* Secondary EAD Actual Mode */
extern float32 eadd_fact_mot2GearRat;  /* '<S12>/Constant8' */

/* Secondary EAD gear ratio */
extern float32 eadd_n_mot2ActSpd_rpm;  /* '<S127>/Data Type Conversion3' */

/* Secondary EAD Actual Speed */
extern float32 eadd_pwr_mot21ActPwr_kW;/* '<S129>/Data Type Conversion3' */

/* Secondary EAD Actual Power */
extern float32 eadd_pwr_mot2ActPwr_kW; /* '<S128>/Data Type Conversion3' */

/* Secondary EAD Actual Power */
extern uint8 eadd_st_eadInv2PwrActvMod;/* '<S12>/Signal Conversion16' */

/* Secondary EAD Power Active Mode */
extern uint8 eadd_st_eadMot2ImmoRlsChk;/* '<S12>/Signal Conversion18' */

/* Motor Immo Check Release Status */
extern uint8 eadd_st_inv2SubFltSts;    /* '<S12>/Signal Conversion17' */

/* Secondary EAD sub fault status */
extern float32 eadd_t_inv2Temp_C;      /* '<S12>/Signal Conversion5' */

/* Secondary EAD inverter temperature */
extern float32 eadd_t_mot2Temp_C;      /* '<S12>/Signal Conversion4' */

/* Secondary EAD motor temperature */
extern float32 eadd_tq_mot2ActTq_Nm;   /* '<S132>/Switch1' */

/* Secondary EAD Actual Torque */
extern float32 eadd_tq_mot2MaxAvailLTBrk_Nm;/* '<S132>/Switch5' */

/* Secondary EAD Max Available Long-term Braking Torque */
extern float32 eadd_tq_mot2MaxAvailLTBst_Nm;/* '<S132>/Switch4' */

/* Secondary EAD Max Available Long-term Boosting Torque */
extern float32 eadd_tq_mot2MaxAvailSTBrk_Nm;/* '<S132>/Switch9' */

/* Secondary EAD Max Available Short-term Braking Torque */
extern float32 eadd_tq_mot2MaxAvailSTBst_Nm;/* '<S132>/Switch8' */

/* Secondary EAD Max Available Short-term Boosting Torque */
extern float32 eadd_u_busInv2HVAct_V;  /* '<S12>/Signal Conversion9' */

/* Secondary EAD actual voltage on DC Bus */
extern ParkingStatus epbd_e_parkingSts;/* '<S160>/Switch' */

/* EPB Parking Status */
extern uint8 hvbd_b_DrivehvilCfm;      /* '<S168>/Switch15' */
extern uint8 hvbd_b_PowerhvilCfm;      /* '<S168>/Switch16' */
extern boolean hvbd_b_bmsSelfChkErr;   /* '<S14>/Signal Conversion28' */

/* HVB HV Self Check Error */
extern boolean hvbd_b_bmsSelfChkOk;    /* '<S14>/Signal Conversion7' */

/* HVB HV Self Check OK */
extern boolean hvbd_b_hcmCutOffLvFb;   /* '<S14>/Signal Conversion19' */

/* HCM Allow Cut Off */
extern boolean hvbd_b_hcmPtcDefRlyCls; /* '<S14>/Signal Conversion31' */

/* HCM PTC contactor is closed */
extern boolean hvbd_b_hcmSelfChkErr;   /* '<S14>/Signal Conversion29' */

/* HCM Self Check Error */
extern boolean hvbd_b_hcmSelfChkOk;    /* '<S14>/Signal Conversion17' */

/* HCM Self Check OK */
extern boolean hvbd_b_hvbChPwrLimdByTemp;/* '<S14>/Signal Conversion30' */

/* HVB Charge Power Limited By Temperature */
extern boolean hvbd_b_hvbDischPwrLimdByTemp;/* '<S14>/Signal Conversion27' */

/* HVB Discharge Power Limited By Temperature */
extern boolean hvbd_b_hvbHeatEnad;     /* '<S14>/Signal Conversion26' */

/* HVB Heating */
extern boolean hvbd_b_hvbPrmtCutOffLvFb;/* '<S14>/Signal Conversion18' */

/* HVB Allow Cut Off */
extern boolean hvbd_b_hvilDriveOpen;   /* '<S168>/Logical Operator14' */

/* DriverONE HVIL open */
extern boolean hvbd_b_hvilOpen;        /* '<S168>/Switch14' */

/* HVIL open */
extern boolean hvbd_b_hvilPowerOpen;   /* '<S168>/Logical Operator24' */

/* PowerONE HVIL open */
extern boolean hvbd_b_lowTempProtnReq; /* '<S169>/Logical Operator3' */

/* Low Ambient Temp Protection Enable */
extern boolean hvbd_b_obcChrgReq;      /* '<S14>/Signal Conversion9' */

/* HVB External Charge Request by OBC */
extern boolean hvbd_b_tboxIntelChgCmd; /* '<S167>/Logical Operator1' */

/* HVB Intelligent Charge Command */
extern boolean hvbd_b_tboxIntelChgCmdRaw;/* '<S185>/Logical Operator3' */

/* HVB Intelligent Charge Command Raw - Quit Conditions Not Considered */
extern HVBRelayStatus hvbd_e_dcdcMainRlySts;/* '<S168>/Switch6' */

/* DC/DC Main Relays Status */
extern HVBRelayStatus hvbd_e_eadInv2MainRlySts;/* '<S168>/Switch4' */

/* Secondary EAD Inverter Main Relays Status */
extern HVBRelayStatus hvbd_e_hcmMaiRlyNeg;/* '<S172>/Switch' */

/* HCM Main Negative Relay Status */
extern McuSts hvbd_e_hcmWrkSt;         /* '<S176>/Switch' */

/* HCM Work Status */
extern HVBRelayStatus hvbd_e_hvbAssiRly;/* '<S174>/Switch' */

/* HVB Assist Relay Status */
extern FaultStatus hvbd_e_hvbFaultStatus;/* '<S171>/Switch' */

/* HVB Fault Status */
extern HVBRelayStatus hvbd_e_hvbMaiRlyNeg;/* '<S173>/Switch' */

/* HVB Main Negative Relay Status */
extern HVBRelayStatus hvbd_e_hvbMaiRlyPos;/* '<S175>/Switch' */

/* HVB Main Positive Relay Status */
extern HVBRelayStatus hvbd_e_hvbMainRlySts;/* '<S168>/Switch1' */

/* HVB Main Relays Status */
extern HVBattStatus hvbd_e_hvbStatus;  /* '<S170>/Switch' */

/* HVB Status */
extern float32 hvbd_fact_hvbSOH_pct;   /* '<S14>/Signal Conversion8' */

/* HVB SOH */
extern float32 hvbd_i_hvbCurr_A;       /* '<S14>/Signal Conversion14' */

/* HV Battery Current */
extern float32 hvbd_pwr_PeakChMax_kW;  /* '<S164>/Data Type Conversion3' */

/* HVB Max Peak Charging Power */
extern float32 hvbd_pwr_PeakDischMax_kW;/* '<S165>/Data Type Conversion3' */

/* HVB Max Peak Discharging Power */
extern float32 hvbd_pwr_StatChMax_kW;  /* '<S162>/Data Type Conversion3' */

/* HVB Max Sationary Charging Power */
extern float32 hvbd_pwr_StatDischMax_kW;/* '<S163>/Data Type Conversion3' */

/* HVB Max Sationary Discharging Power */
extern float32 hvbd_pwr_acwpHeatPower_kW;/* '<S14>/Product2' */
extern float32 hvbd_pwr_hvbActRaw_kW;  /* '<S14>/Signal Conversion3' */

/* HVB Actual Power */
extern float32 hvbd_pwr_hvbAct_kW;     /* '<S161>/Data Type Conversion3' */

/* HVB Actual Power */
extern float32 hvbd_pwr_hvbChgPwr_kW;  /* '<S14>/Signal Conversion4' */
extern uint8 hvbd_st_hcmFltLvl;        /* '<S14>/Signal Conversion13' */

/* HCM fault level */
extern uint8 hvbd_st_hvbSubFaultSts;   /* '<S14>/Signal Conversion32' */

/* HVB sub fault status */
extern uint8 hvbd_st_hvilOpenSt;       /* '<S168>/Switch13' */
extern uint8 hvbd_st_intlChgQuit;      /* '<S188>/Switch4' */

/* HVB Intelligent Charge Quit State */
extern uint8 hvbd_st_tboxIntelChgQuit; /* '<S167>/Switch7' */

/* HVB Intelligent Charge Quit State */
extern boolean hvbd_st_tboxIntelChgQuitCrit;/* '<S188>/Logical Operator6' */

/* HVB Intelligent Charge Quit State Criteria */
extern float32 hvbd_t_hvbMin_C;        /* '<S14>/Signal Conversion12' */

/* HVB Minimum Temperature */
extern float32 hvbd_t_hvbTemp_C;       /* '<S14>/Signal Conversion6' */

/* HVB Temperature */
extern float32 inrd_t_TS5sensorFbFilt_C;/* '<S930>/RollingAverage' */
extern float32 inrd_t_hvbColInFbFilt_C;/* '<S934>/RollingAverage' */
extern float32 inrd_t_hvbColOutFbFilt_C;/* '<S938>/RollingAverage' */
extern float32 lswd_B13_BatteryLoopWaterOut_TempSensor;/* '<S1>/Data Type Conversion582' */
extern float32 lswd_B15_BatteryLoopWaterIn_TempSensor;/* '<S1>/Data Type Conversion580' */
extern boolean lswd_b_BrkSwitch;       /* '<S1>/Data Type Conversion1187' */
extern boolean lswd_b_BrkSwitch2;      /* '<S1>/Data Type Conversion1189' */
extern boolean lswd_b_DryAirSwitch;    /* '<S1>/Data Type Conversion602' */
extern boolean lswd_b_ecoModeSwitch;   /* '<S1>/Data Type Conversion440' */
extern float32 lswd_pct_HVILReturnPWM; /* '<S1>/Data Type Conversion626' */
extern float32 lswd_pct_WatPmpEP1FbPWM;/* '<S1>/Data Type Conversion616' */
extern float32 lswd_pct_WatPmpEP2FbPWM;/* '<S1>/Data Type Conversion636' */
extern float32 lswd_u_Acc1_mV;         /* '<S1>/Data Type Conversion592' */
extern float32 lswd_u_Acc2_mV;         /* '<S1>/Data Type Conversion594' */
extern float32 lswd_u_TS5sensorFb_mV;  /* '<S1>/Data Type Conversion578' */
extern boolean lswd_u_obcWakeHCU_V;    /* '<S1>/Data Type Conversion576' */
extern boolean lswd_u_pepsON_V;        /* '<S1>/Data Type Conversion568' */
extern float32 lswd_v_5VT1_Internal_Sample;/* '<S1>/Data Type Conversion564' */
extern float32 lswd_v_5VT2_Internal_Sample;/* '<S1>/Data Type Conversion566' */
extern float32 lswd_v_Bat_Internal_Sample;/* '<S1>/Data Type Conversion560' */
extern float32 macd_V_tankFuelLvl_l;   /* '<S15>/Signal Conversion1' */

/* Fuel Tank Level */
extern boolean macd_b_epsSelfChkErr;   /* '<S15>/Signal Conversion16' */

/* EPS Self Check Error */
extern boolean macd_b_epsSelfChkOk;    /* '<S15>/Signal Conversion7' */

/* EPS Self Check OK */
extern boolean macd_b_vcuSelfChkOk;    /* '<S15>/Relational Operator7' */

/* VCU Self Check OK */
extern McuSts macd_e_sdcacWrk;         /* '<S248>/Switch' */

/* EPS Status */
extern float32 macd_p_frontAirTankPres_bar;/* '<S246>/Product' */

/* Front Air Tank Pressure */
extern float32 macd_p_rearAirTankPres_bar;/* '<S247>/Product' */

/* Rear Air Tank Pressure */
extern uint8 macd_st_epsErrorCode;     /* '<S15>/Signal Conversion18' */

/* EPS Error Code */
extern uint8 macd_st_epsFltLvl;        /* '<S15>/Signal Conversion6' */

/* EPS fault level */
extern uint8 macd_st_epsSubFltLvl;     /* '<S15>/Signal Conversion8' */

/* EPS sub fault level */
extern float32 macd_t_ts5SnsrTemp_C;   /* '<S15>/Signal Conversion2' */

/* TS5 sensor Temperature */
extern float32 macd_u_5VT1IntSmpl_V;   /* '<S15>/Product2' */

/* 5VT1 voltage */
extern float32 macd_u_5VT2IntSmpl_V;   /* '<S15>/Product3' */

/* 5VT2 voltage */
extern float32 macd_u_batIntSmpl_V;    /* '<S15>/Product1' */

/* Low voltage battery voltage */
extern boolean obcd_b_obcCANMsgValid;  /* '<S16>/Relational Operator2' */

/* CAN message from OBC valid */
extern boolean obcd_b_obcChrgCablePlugged;/* '<S16>/Logical Operator1' */

/* Charge Cable Plugged */
extern boolean obcd_b_obcChrgCableUnplugged;/* '<S16>/Logical Operator7' */

/* Charge Cable Unplugged */
extern boolean obcd_b_obcSelfChkErr;   /* '<S16>/Signal Conversion5' */
extern boolean obcd_b_obcSelfChkOk;    /* '<S16>/Signal Conversion4' */
extern boolean obcd_b_obcWakeUp;       /* '<S16>/Logical Operator3' */

/* HCU Wake-up from OBC */
extern float32 obcd_pwr_obcOutpt_kW;   /* '<S252>/Product' */
extern float32 obcd_pwr_obcRlTmOutpt_kW;/* '<S253>/Product' */
extern uint8 obcd_st_obcfltLvl;        /* '<S16>/Signal Conversion3' */
extern float32 obcd_t_obcTemp_C;       /* '<S16>/Signal Conversion6' */

/* OBC Temperature */
extern boolean pmmd_b_anyIgnOn;        /* '<S260>/Switch' */

/* True if any ignition input is ON */
extern boolean pmmd_b_canIgnOn;        /* '<S259>/Logical Operator5' */

/* CAN-based ignition active */
extern boolean pmmd_b_driverStartReq;  /* '<S259>/Switch1' */

/* Driver Start Request from CAN */
extern boolean pmmd_b_hwIgnOn;         /* '<S267>/timed_debounce' */

/* HW-based ignition active */
extern boolean pmmd_b_ignOn;           /* '<S260>/Switch1' */

/* Arbitrated ignition ON */
extern boolean pmmd_b_ignStsStrt;      /* '<S17>/Signal Conversion2' */

/* Hardware Ignition Status START */
extern boolean pmmd_b_pepsPduLvlValid; /* '<S259>/Signal Conversion3' */

/* PDU Level Valid */
extern boolean pmmd_b_ptCanNmStRdy;    /* '<S17>/Relational Operator' */

/* Pp_PtCan_CanNm_NmState is wake up */
extern KeyAuthStatus pmmd_e_authenticationStatus;/* '<S258>/Multiport Switch' */

/* Authen Status send to EMS */
extern uint8 s2vd_ABS_Active;          /* '<S1>/Data Type Conversion254' */
extern float32 s2vd_ABS_RelativeSpd_FAxleLWheel;/* '<S1>/Data Type Conversion192' */
extern float32 s2vd_ABS_RelativeSpd_FAxleRWheel;/* '<S1>/Data Type Conversion198' */
extern float32 s2vd_ABS_RelativeSpd_RAxle1_Lwheel;/* '<S1>/Data Type Conversion214' */
extern float32 s2vd_ABS_RelativeSpd_RAxle1_RWheel;/* '<S1>/Data Type Conversion220' */
extern float32 s2vd_ACCM1_ActPower;    /* '<S1>/Data Type Conversion402' */
extern float32 s2vd_ACCM_ActPower;     /* '<S1>/Data Type Conversion658' */
extern uint8 s2vd_ACCM_Status;         /* '<S1>/Data Type Conversion378' */
extern uint8 s2vd_ACU_CrashOutputStatusC;/* '<S1>/Data Type Conversion412' */
extern uint8 s2vd_ACU_CrashOutputStatusPT;/* '<S1>/Data Type Conversion793' */
extern boolean s2vd_AC_AmbientTemperatureInvalid;/* '<S1>/Data Type Conversion382' */
extern uint8 s2vd_AC_Cab_ThermalMangeReq;/* '<S1>/Data Type Conversion376' */
extern float32 s2vd_AC_CoolingFanPWMSpd;/* '<S1>/Data Type Conversion394' */
extern float32 s2vd_AC_IPTC_ActPower;  /* '<S1>/Data Type Conversion386' */
extern uint8 s2vd_AC_IPTC_WorkSts;     /* '<S1>/Data Type Conversion380' */
extern float32 s2vd_AC_PTC_ActPwr_Rear;/* '<S1>/con_1' */
extern uint8 s2vd_AC_PTC_WorkSts_Rear; /* '<S1>/con_2' */
extern float32 s2vd_AC_VehicleOutTemp; /* '<S1>/Data Type Conversion1948' */
extern boolean s2vd_ADC1Ctr_AlvCtrErrFlg_ADC;/* '<S1>/Data Type Conversion1163' */
extern boolean s2vd_ADC1Ctr_AlvCtrErrFlg_PMS;/* '<S1>/Data Type Conversion1036' */
extern boolean s2vd_ADC1Ctr_ComRxToutFlg_ADC;/* '<S1>/Data Type Conversion1026' */
extern boolean s2vd_ADC1Ctr_ComRxToutFlg_PMS;/* '<S1>/Data Type Conversion939' */
extern boolean s2vd_ADC1Ctr_CsmErrFlg_ADC;/* '<S1>/Data Type Conversion1161' */
extern boolean s2vd_ADC1Ctr_CsmErrFlg_PMS;/* '<S1>/Data Type Conversion1034' */
extern boolean s2vd_ADC1PMSCtr_AlvCtrErrFlg_ADC;/* '<S1>/Data Type Conversion1175' */
extern boolean s2vd_ADC1PMSCtr_AlvCtrErrFlg_PMS;/* '<S1>/Data Type Conversion991' */
extern boolean s2vd_ADC1PMSCtr_ComRxToutFlg_ADC;/* '<S1>/Data Type Conversion1171' */
extern boolean s2vd_ADC1PMSCtr_ComRxToutFlg_PMS;/* '<S1>/Data Type Conversion979' */
extern boolean s2vd_ADC1PMSCtr_CsmErrFlg_ADC;/* '<S1>/Data Type Conversion1173' */
extern boolean s2vd_ADC1PMSCtr_CsmErrFlg_PMS;/* '<S1>/Data Type Conversion989' */
extern boolean s2vd_ADC1_CANBUS_flag;  /* '<S1>/Data Type Conversion895' */
extern boolean s2vd_ADC1_ControlGear_Enable;/* '<S1>/Data Type Conversion1040' */
extern boolean s2vd_ADC1_ControlGear_Enable_ADC;/* '<S1>/Data Type Conversion1013' */
extern boolean s2vd_ADC1_ControlTorque_Enable;/* '<S1>/Data Type Conversion1042' */
extern boolean s2vd_ADC1_ControlTorque_Enable_ADC;/* '<S1>/Data Type Conversion1015' */
extern boolean s2vd_ADC1_Ctrl_Status;  /* '<S1>/Data Type Conversion873' */
extern boolean s2vd_ADC1_Ctrl_Status_ADC;/* '<S1>/Data Type Conversion985' */
extern boolean s2vd_ADC1_SwitchCtrl_Req;/* '<S1>/Data Type Conversion1088' */
extern boolean s2vd_ADC1_SwitchCtrl_Req_ADC;/* '<S1>/Data Type Conversion981' */
extern boolean s2vd_ADC1_System_Status;/* '<S1>/Data Type Conversion1045' */
extern boolean s2vd_ADC1_System_Status_ADC;/* '<S1>/Data Type Conversion1018' */
extern uint8 s2vd_ADC1_TargetGearPostion;/* '<S1>/Data Type Conversion1038' */
extern uint8 s2vd_ADC1_TargetGearPostion_ADC;/* '<S1>/Data Type Conversion1011' */
extern float32 s2vd_ADC1_Target_DrivingTorque;/* '<S1>/Data Type Conversion1047' */
extern float32 s2vd_ADC1_Target_DrivingTorque_ADC;/* '<S1>/Data Type Conversion1020' */
extern float32 s2vd_ADC1_Temp;         /* '<S1>/Data Type Conversion1049' */
extern float32 s2vd_ADC1_Temp_ADC;     /* '<S1>/Data Type Conversion1022' */
extern boolean s2vd_ADCCtr_AlvCtrErrFlg_ADC;/* '<S1>/Data Type Conversion1024' */
extern boolean s2vd_ADCCtr_AlvCtrErrFlg_PMS;/* '<S1>/Data Type Conversion917' */
extern boolean s2vd_ADCCtr_ComRxToutFlg_ADC;/* '<S1>/Data Type Conversion1007' */
extern boolean s2vd_ADCCtr_ComRxToutFlg_PMS;/* '<S1>/Data Type Conversion1044' */
extern boolean s2vd_ADCCtr_CsmErrFlg_ADC;/* '<S1>/Data Type Conversion1009' */
extern boolean s2vd_ADCCtr_CsmErrFlg_PMS;/* '<S1>/Data Type Conversion1066' */
extern boolean s2vd_ADCPMSCtr_AlvCtrErrFlg_ADC;/* '<S1>/Data Type Conversion1169' */
extern boolean s2vd_ADCPMSCtr_AlvCtrErrFlg_PMS;/* '<S1>/Data Type Conversion977' */
extern boolean s2vd_ADCPMSCtr_ComRxToutFlg_ADC;/* '<S1>/Data Type Conversion1165' */
extern boolean s2vd_ADCPMSCtr_ComRxToutFlg_PMS;/* '<S1>/Data Type Conversion1051' */
extern boolean s2vd_ADCPMSCtr_CsmErrFlg_ADC;/* '<S1>/Data Type Conversion1167' */
extern boolean s2vd_ADCPMSCtr_CsmErrFlg_PMS;/* '<S1>/Data Type Conversion1053' */
extern boolean s2vd_ADC_CANBusOff_flg; /* '<S1>/Data Type Conversion1127' */
extern boolean s2vd_ADC_ControlGear_Enable;/* '<S1>/Data Type Conversion984' */
extern boolean s2vd_ADC_ControlGear_Enable_ADC;/* '<S1>/Data Type Conversion996' */
extern boolean s2vd_ADC_ControlTorque_Enable;/* '<S1>/Data Type Conversion1006' */
extern boolean s2vd_ADC_ControlTorque_Enable_ADC;/* '<S1>/Data Type Conversion998' */
extern boolean s2vd_ADC_Ctrl_Status;   /* '<S1>/Data Type Conversion983' */
extern boolean s2vd_ADC_Ctrl_Status_ADC;/* '<S1>/Data Type Conversion975' */
extern boolean s2vd_ADC_System_Status; /* '<S1>/Data Type Conversion1027' */
extern boolean s2vd_ADC_System_Status_ADC;/* '<S1>/Data Type Conversion1000' */
extern uint8 s2vd_ADC_TargetGearPostion;/* '<S1>/Data Type Conversion961' */
extern uint8 s2vd_ADC_TargetGearPostion_ADC;/* '<S1>/Data Type Conversion993' */
extern float32 s2vd_ADC_Target_DrivingTorque;/* '<S1>/Data Type Conversion1029' */
extern float32 s2vd_ADC_Target_DrivingTorque_ADC;/* '<S1>/Data Type Conversion1002' */
extern float32 s2vd_ADC_Temp;          /* '<S1>/Data Type Conversion1031' */
extern float32 s2vd_ADC_Temp_ADC;      /* '<S1>/Data Type Conversion1004' */
extern boolean s2vd_AccyFltSts;        /* '<S1>/Data Type Conversion1216' */
extern uint8 s2vd_BBM_FaultStatus;     /* '<S1>/Data Type Conversion1218' */
extern uint8 s2vd_BBM_WorkSts;         /* '<S1>/Data Type Conversion1220' */
extern uint8 s2vd_BCM_ATWS_St;         /* '<S1>/Data Type Conversion23' */
extern boolean s2vd_BCM_BrakePedalSwitchInvalid;/* '<S1>/Data Type Conversion480' */
extern uint8 s2vd_BCM_FrontLeftDoorAjarStatus;/* '<S1>/Data Type Conversion51' */

/* BCM Front Left Door Ajar Status */
extern uint8 s2vd_BCM_FrontRightDoorAjarStatus;/* '<S1>/Data Type Conversion488' */

/* BCM Front Left Door Ajar Status */
extern float32 s2vd_BCM_Odometerbackup;/* '<S1>/Data Type Conversion1230' */
extern uint8 s2vd_BMSH_BattPackNum;    /* '<S1>/Data Type Conversion457' */
extern uint8 s2vd_BMSH_BattSysNum;     /* '<S1>/Data Type Conversion455' */
extern uint8 s2vd_BMSH_ChgOverCurrent_EV;/* '<S1>/Data Type Conversion800' */
extern uint8 s2vd_BMSH_DCChargeProcess_EV;/* '<S1>/Data Type Conversion798' */
extern boolean s2vd_BMSH_DCChgCurReqRangeUP;/* '<S1>/Data Type Conversion826' */
extern float32 s2vd_BMSH_DCChgCurReq_EV;/* '<S1>/Data Type Conversion830' */
extern uint8 s2vd_BMSH_DCChgPlugNOverTemp_EV;/* '<S1>/Data Type Conversion946' */
extern uint8 s2vd_BMSH_DCChgPlugPOverTemp_EV;/* '<S1>/Data Type Conversion804' */
extern float32 s2vd_BMSH_FinishChgTime_EV;/* '<S1>/Data Type Conversion819' */
extern float32 s2vd_BMSH_PackVolt_EV;  /* '<S1>/Data Type Conversion795' */
extern uint8 s2vd_BMSH_StsChgFault;    /* '<S1>/Data Type Conversion848' */
extern uint8 s2vd_BMSH_StsDischgFault; /* '<S1>/Data Type Conversion825' */
extern uint8 s2vd_BMSH_StsPrecharge;   /* '<S1>/Data Type Conversion396' */
extern uint8 s2vd_BMSH_TBOX_BatLowSOC2;/* '<S1>/Data Type Conversion1033' */
extern uint8 s2vd_BMSH_TBOX_BatOverSOC2;/* '<S1>/Data Type Conversion1025' */
extern uint8 s2vd_BMSH_TBOX_BatOverVoltage2;/* '<S1>/Data Type Conversion1135' */
extern uint8 s2vd_BMSH_TBOX_BatUnderVoltage2;/* '<S1>/Data Type Conversion1131' */
extern uint8 s2vd_BMSH_TBOX_BatUniformity2;/* '<S1>/Data Type Conversion801' */
extern uint8 s2vd_BMSH_TBOX_CellOverVoltage2;/* '<S1>/Data Type Conversion1143' */
extern uint8 s2vd_BMSH_TBOX_CellUnderVoltage2;/* '<S1>/Data Type Conversion1139' */
extern uint8 s2vd_BMSH_TBOX_CellVoltMaxID;/* '<S1>/Data Type Conversion548' */
extern uint8 s2vd_BMSH_TBOX_CellVoltMinID;/* '<S1>/Data Type Conversion550' */
extern uint16 s2vd_BMSH_TBOX_CellsSum_EV;/* '<S1>/Data Type Conversion779' */
extern uint8 s2vd_BMSH_TBOX_FireAlarm; /* '<S1>/Data Type Conversion415' */
extern uint8 s2vd_BMSH_TBOX_MaxTempID; /* '<S1>/Data Type Conversion686' */
extern uint8 s2vd_BMSH_TBOX_MinTempID; /* '<S1>/Data Type Conversion688' */
extern uint8 s2vd_BMSH_VCU_ChgFaultReq;/* '<S1>/Data Type Conversion150' */
extern boolean s2vd_BMSH_VCU_DisChgSOPRangeUP;/* '<S1>/Data Type Conversion849' */
extern uint8 s2vd_BMSH_VCU_DischgFaultReq;/* '<S1>/Data Type Conversion148' */
extern uint8 s2vd_BMS_ActWorkSts;      /* '<S1>/Data Type Conversion152' */
extern float32 s2vd_BMS_BattCurr;      /* '<S1>/Data Type Conversion1930' */
extern uint8 s2vd_BMS_BattIsolationSts;/* '<S1>/Data Type Conversion775' */
extern float32 s2vd_BMS_BattMaxTemp1;  /* '<S1>/Data Type Conversion695' */
extern float32 s2vd_BMS_BattMinTemp1;  /* '<S1>/Data Type Conversion694' */
extern float32 s2vd_BMS_BattPackInCoolTemp;/* '<S1>/Data Type Conversion702' */
extern uint8 s2vd_BMS_BattPackMatchFault;/* '<S1>/Data Type Conversion435' */
extern float32 s2vd_BMS_BattPackOutCoolTemp;/* '<S1>/Data Type Conversion703' */
extern float32 s2vd_BMS_BattPackRemainEgy;/* '<S1>/Data Type Conversion536' */
extern float32 s2vd_BMS_BattSOH;       /* '<S1>/Data Type Conversion482' */
extern uint8 s2vd_BMS_BattTempFault;   /* '<S1>/Data Type Conversion1147' */
extern float32 s2vd_BMS_BattVol;       /* '<S1>/Data Type Conversion802' */
extern uint8 s2vd_BMS_Batty_ThermalMangeReq;/* '<S1>/Data Type Conversion722' */
extern uint8 s2vd_BMS_CellTempDiffFault;/* '<S1>/Data Type Conversion1055' */
extern uint8 s2vd_BMS_CellVolDiffFault;/* '<S1>/Data Type Conversion1155' */
extern float32 s2vd_BMS_Cell_Avg_Temp; /* '<S1>/Data Type Conversion1056' */
extern uint8 s2vd_BMS_ChgCCSts;        /* '<S1>/con_6' */
extern uint8 s2vd_BMS_ChgStatus_EV;    /* '<S1>/Data Type Conversion935' */
extern uint8 s2vd_BMS_DCChgPlugSts;    /* '<S1>/Data Type Conversion154' */
extern uint8 s2vd_BMS_DelayDataUpldEnb;/* '<S1>/Data Type Conversion721' */
extern uint8 s2vd_BMS_IsolationFault;  /* '<S1>/Data Type Conversion1151' */
extern float32 s2vd_BMS_MaxCellVolt;   /* '<S1>/Data Type Conversion556' */
extern float32 s2vd_BMS_MaxChgPwrPeak; /* '<S1>/Data Type Conversion546' */

/* Battery maximum peak charge power */
extern float32 s2vd_BMS_MaxDischgPwrContinuous;/* '<S1>/Data Type Conversion166' */

/* Battery maximum continuous discharge power */
extern float32 s2vd_BMS_MinCellVolt;   /* '<S1>/Data Type Conversion558' */
extern uint8 s2vd_BMS_NegRelaySts;     /* '<S1>/Data Type Conversion160' */
extern uint8 s2vd_BMS_OverChgFault;    /* '<S1>/Data Type Conversion530' */
extern uint8 s2vd_BMS_PmtCutoffLVFb;   /* '<S1>/Data Type Conversion187' */
extern float32 s2vd_BMS_PosIsolationRes;/* '<S1>/Data Type Conversion1008' */
extern uint8 s2vd_BMS_SOCJumpFault;    /* '<S1>/Data Type Conversion1050' */
extern float32 s2vd_BMS_SOC_01;        /* '<S1>/Data Type Conversion1940' */
extern uint8 s2vd_BMS_ST1_Flt_HVIL;    /* '<S1>/Data Type Conversion156' */
extern float32 s2vd_BMS_SetTgtTemp;    /* '<S1>/Data Type Conversion705' */
extern uint8 s2vd_BMS_TempOutofCtr;    /* '<S1>/Data Type Conversion784' */
extern uint8 s2vd_BMS_TempSnsNum;      /* '<S1>/Data Type Conversion990' */
extern uint8 s2vd_BMS_ZeroPwr_Req;     /* '<S1>/con_3' */
extern boolean s2vd_CSM_CampModeSwt;   /* '<S1>/Data Type Conversion299' */
extern boolean s2vd_CSM_CampModeSwtInvalid;/* '<S1>/Data Type Conversion301' */
extern boolean s2vd_CSM_ECO_ReqInvalid;/* '<S1>/Data Type Conversion442' */
extern boolean s2vd_CSM_EngRecSwt_Req; /* '<S1>/Data Type Conversion724' */
extern uint8 s2vd_CSM_EngRec_Req;      /* '<S1>/Data Type Conversion444' */
extern boolean s2vd_CSM_EngRec_ReqInvalid;/* '<S1>/Data Type Conversion446' */
extern boolean s2vd_CSM_TakeEleSwt;    /* '<S1>/Data Type Conversion162' */
extern boolean s2vd_CSM_TakeEleSwt_ReqInvalid;/* '<S1>/Data Type Conversion164' */
extern boolean s2vd_CSM_V2XDchaSwt;    /* '<S1>/Data Type Conversion450' */
extern boolean s2vd_CSM_V2XDchaSwtInvalid;/* '<S1>/Data Type Conversion452' */
extern uint8 s2vd_DCDC_12V_CANComFault;/* '<S1>/Data Type Conversion128' */
extern uint8 s2vd_DCDC_12V_CutOffLVFb; /* '<S1>/Data Type Conversion104' */
extern uint8 s2vd_DCDC_12V_FaultLevel; /* '<S1>/Data Type Conversion110' */
extern float32 s2vd_DCDC_12V_OutCurr;  /* '<S1>/Data Type Conversion102' */
extern uint8 s2vd_DCDC_12V_OutOverCurr;/* '<S1>/Data Type Conversion122' */
extern uint8 s2vd_DCDC_12V_OutOverVolt;/* '<S1>/Data Type Conversion124' */
extern float32 s2vd_DCDC_12V_OutVolt;  /* '<S1>/Data Type Conversion100' */
extern uint8 s2vd_DCDC_12V_WorkSts;    /* '<S1>/Data Type Conversion114' */
extern uint8 s2vd_DCDC_AccessoryConnStsFb;/* '<S1>/Data Type Conversion852' */
extern float32 s2vd_DCDC_IDCDCActHiside;/* '<S1>/Data Type Conversion118' */
extern uint8 s2vd_DCDC_PTCConnStsFb;   /* '<S1>/Data Type Conversion978' */
extern float32 s2vd_DCDC_Relay_Volt;   /* '<S1>/Data Type Conversion659' */
extern uint8 s2vd_DCDC_SelfCheSts;     /* '<S1>/Data Type Conversion106' */
extern float32 s2vd_DCDC_Temp;         /* '<S1>/Data Type Conversion112' */
extern float32 s2vd_DCDC_UDCDCActHiside;/* '<S1>/Data Type Conversion120' */
extern boolean s2vd_DcDcStsAlm;        /* '<S1>/Data Type Conversion108' */
extern uint32 s2vd_ECU_Fun_Config_Data1;/* '<S1>/Data Type Conversion1159' */
extern uint32 s2vd_ECU_Fun_Config_Data2;/* '<S1>/Data Type Conversion25' */
extern uint8 s2vd_EGSM_FaultLevel;     /* '<S1>/Data Type Conversion8' */
extern uint8 s2vd_EGSM_LeverPosition;  /* '<S1>/Data Type Conversion67' */
extern uint8 s2vd_EGSM_ParkReq1;       /* '<S1>/Data Type Conversion2' */
extern boolean s2vd_EHB_ABSFailed;     /* '<S1>/Data Type Conversion258' */
extern boolean s2vd_EHB_AEB_active;    /* '<S1>/Data Type Conversion312' */
extern uint8 s2vd_EHB_AVHStatus;       /* '<S1>/Data Type Conversion278' */
extern uint8 s2vd_EHB_BrkSysErrFault;  /* '<S1>/Data Type Conversion33' */
extern boolean s2vd_EHB_DTC_Active;    /* '<S1>/Data Type Conversion330' */
extern boolean s2vd_EHB_EPBErrorStatus;/* '<S1>/Data Type Conversion282' */
extern uint8 s2vd_EHB_EPB_DynamicApplystatus;/* '<S1>/Data Type Conversion1183' */
extern uint8 s2vd_EHB_HHCActive;       /* '<S1>/Data Type Conversion288' */
extern float32 s2vd_EHB_ISA_PTTrqDecReq;/* '<S1>/Data Type Conversion39' */
extern boolean s2vd_EHB_ISA_PTTrqDecReqActive;/* '<S1>/Data Type Conversion79' */
extern uint8 s2vd_EHB_ISA_Status;      /* '<S1>/Data Type Conversion90' */
extern float32 s2vd_EHB_MbRegenTargetWheel;/* '<S1>/Data Type Conversion340' */
extern uint8 s2vd_EHB_MbRegenTargetWheelSts;/* '<S1>/Data Type Conversion342' */
extern float32 s2vd_EHB_PTTrqDecReq;   /* '<S1>/Data Type Conversion348' */
extern boolean s2vd_EHB_PTTrqDecReqActive;/* '<S1>/Data Type Conversion352' */
extern float32 s2vd_EHB_PTTrqIncReq;   /* '<S1>/Data Type Conversion350' */
extern boolean s2vd_EHB_PTTrqIncReqActive;/* '<S1>/Data Type Conversion354' */
extern boolean s2vd_EHB_VLC_Active;    /* '<S1>/Data Type Conversion176' */
extern boolean s2vd_EHB_VLC_Available; /* '<S1>/Data Type Conversion178' */
extern boolean s2vd_EHB_VLC_CDD_active_ADC;/* '<S1>/Data Type Conversion174' */
extern float32 s2vd_EHB_VLC_PTTrqReq;  /* '<S1>/Data Type Conversion184' */
extern boolean s2vd_EHB_VLC_PTTrqReqActive;/* '<S1>/Data Type Conversion186' */
extern float32 s2vd_EHB_VehicleSpeed;  /* '<S1>/Data Type Conversion268' */
extern boolean s2vd_EHB_VehicleSpeedInvalid;/* '<S1>/Data Type Conversion274' */
extern uint8 s2vd_EPB_ParkBrakeSts;    /* '<S1>/Data Type Conversion280' */
extern uint8 s2vd_EPS_EpasFailed;      /* '<S1>/Data Type Conversion955' */
extern float32 s2vd_EWP_HeatPower;     /* '<S1>/Data Type Conversion229' */
extern float32 s2vd_EWP_OutputTemp;    /* '<S1>/Data Type Conversion211' */
extern boolean s2vd_FWFV_CCWFlg;       /* '<S1>/Data Type Conversion674' */
extern float32 s2vd_FWFV_CurrentPos;   /* '<S1>/Data Type Conversion678' */
extern boolean s2vd_FWFV_InitState;    /* '<S1>/Data Type Conversion672' */
extern boolean s2vd_FWFV_MotorState;   /* '<S1>/Data Type Conversion676' */
extern boolean s2vd_FWFV_OverCurrentFlt;/* '<S1>/Data Type Conversion666' */
extern boolean s2vd_FWFV_OverTempFlt;  /* '<S1>/Data Type Conversion668' */
extern boolean s2vd_FWFV_OverVoltageFlt;/* '<S1>/Data Type Conversion664' */
extern boolean s2vd_FWFV_RESPERROR;    /* '<S1>/Data Type Conversion662' */
extern boolean s2vd_FWFV_UnderVoltageFlt;/* '<S1>/Data Type Conversion670' */
extern float32 s2vd_HCM_AcceRelayVolt; /* '<S1>/Data Type Conversion1191' */
extern boolean s2vd_HCM_AcceRelayVoltValidStat;/* '<S1>/Data Type Conversion1194' */
extern uint8 s2vd_HCM_AccessoryConnStsFb;/* '<S1>/con_4' */
extern uint8 s2vd_HCM_IntelLockLoopSts;/* '<S1>/Data Type Conversion1181' */
extern float32 s2vd_HCM_MainPosBackVolt;/* '<S1>/Data Type Conversion1199' */
extern boolean s2vd_HCM_MainPosBackVoltValidStat;/* '<S1>/Data Type Conversion1201' */
extern uint8 s2vd_HCM_MainPosConnSts;  /* '<S1>/Data Type Conversion158' */
extern uint8 s2vd_HCM_PTC1ConnStsFb;   /* '<S1>/Data Type Conversion146' */
extern uint8 s2vd_HCM_PTCConnStsFb_Reserved;/* '<S1>/Data Type Conversion1124' */
extern float32 s2vd_HCM_PTCRelayVolt;  /* '<S1>/Data Type Conversion1192' */
extern boolean s2vd_HCM_PTCRelayVoltValidStat;/* '<S1>/Data Type Conversion1195' */
extern float32 s2vd_IC_Odometer;       /* '<S1>/Data Type Conversion370' */
extern boolean s2vd_IPK_AllowChgSoftSwCtrlSt;/* '<S1>/Data Type Conversion190' */
extern boolean s2vd_IPK_ChrgSoftSwCtrlSt;/* '<S1>/Data Type Conversion168' */
extern uint8 s2vd_IPK_CruisingDstSwt;  /* '<S1>/Data Type Conversion1224' */
extern float32 s2vd_IPK_Odometerbackup;/* '<S1>/Data Type Conversion1228' */
extern boolean s2vd_IPK_OdometerbackupEnable;/* '<S1>/Data Type Conversion372' */
extern float32 s2vd_IPU_HVBusVolt_IPUSts;/* '<S1>/Data Type Conversion928' */
extern boolean s2vd_IPU_IsgSpdActSgnInvalid;/* '<S1>/Data Type Conversion763' */
extern uint8 s2vd_IPU_MCUTempHighAlarm1;/* '<S1>/Data Type Conversion484' */
extern uint8 s2vd_IPU_MotorOverCurrFlt;/* '<S1>/Data Type Conversion447' */
extern uint8 s2vd_IPU_MotorOverSpdFlt; /* '<S1>/Data Type Conversion437' */
extern uint8 s2vd_IPU_MotorSubFltLevell;/* '<S1>/Data Type Conversion65' */
extern boolean s2vd_IPU_MotorTempHighFault;/* '<S1>/Data Type Conversion56' */
extern uint8 s2vd_IPU_MotorTempHighFault1;/* '<S1>/Data Type Conversion495' */
extern uint8 s2vd_MCU_ActiveDischgFlt; /* '<S1>/Data Type Conversion36' */
extern uint8 s2vd_MCU_CANCommFlt;      /* '<S1>/Data Type Conversion68' */
extern float32 s2vd_MCU_HVBusVol;      /* '<S1>/Data Type Conversion137' */
extern float32 s2vd_MCU_HVDCCurr;      /* '<S1>/Data Type Conversion533' */
extern uint8 s2vd_MCU_IGBTFlt;         /* '<S1>/Data Type Conversion46' */
extern uint8 s2vd_MCU_MCUMemoryFlt;    /* '<S1>/Data Type Conversion70' */
extern uint8 s2vd_MCU_MCUSts;          /* '<S1>/Data Type Conversion14' */
extern float32 s2vd_MCU_MCUTemp;       /* '<S1>/Data Type Conversion681' */
extern uint8 s2vd_MCU_MCUTempHighAlarm;/* '<S1>/Data Type Conversion59' */
extern uint8 s2vd_MCU_McuTempSensorErr;/* '<S1>/Data Type Conversion86' */
extern float32 s2vd_MCU_MotorActTrq;   /* '<S1>/Data Type Conversion16' */
extern uint8 s2vd_MCU_MotorFltLevel;   /* '<S1>/Data Type Conversion91' */
extern uint8 s2vd_MCU_MotorLockRotErr; /* '<S1>/Data Type Conversion84' */
extern float32 s2vd_MCU_MotorMaxTrq;   /* '<S1>/Data Type Conversion28' */
extern float32 s2vd_MCU_MotorMinTrq;   /* '<S1>/Data Type Conversion30' */
extern uint8 s2vd_MCU_MotorSpdHighAlarm;/* '<S1>/Data Type Conversion63' */
extern float32 s2vd_MCU_MotorSpeed;    /* '<S1>/Data Type Conversion18' */
extern float32 s2vd_MCU_MotorTemp;     /* '<S1>/Data Type Conversion683' */
extern uint8 s2vd_MCU_MotorTempHighAlarm;/* '<S1>/Data Type Conversion49' */
extern uint8 s2vd_MCU_MotorTempSensorErr;/* '<S1>/Data Type Conversion88' */
extern uint8 s2vd_MCU_MotorWorkMode;   /* '<S1>/Data Type Conversion20' */
extern uint8 s2vd_MCU_RotateInverterFlt;/* '<S1>/Data Type Conversion44' */
extern uint8 s2vd_MCU_SelfChkSts;      /* '<S1>/Data Type Conversion12' */
extern boolean s2vd_MHGV_CCWFlg;       /* '<S1>/Data Type Conversion656' */
extern float32 s2vd_MHGV_CurrentPos;   /* '<S1>/Data Type Conversion660' */
extern boolean s2vd_MHGV_InitState;    /* '<S1>/Data Type Conversion654' */
extern boolean s2vd_MHGV_MotorState;   /* '<S1>/Data Type Conversion74' */
extern boolean s2vd_MHGV_OverCurrentFlt;/* '<S1>/Data Type Conversion648' */
extern boolean s2vd_MHGV_OverTempFlt;  /* '<S1>/Data Type Conversion650' */
extern boolean s2vd_MHGV_OverVoltageFlt;/* '<S1>/Data Type Conversion644' */
extern boolean s2vd_MHGV_RESPERROR;    /* '<S1>/Data Type Conversion646' */
extern boolean s2vd_MHGV_UnderVoltageFlt;/* '<S1>/Data Type Conversion652' */
extern float32 s2vd_MMI_LocalBookChrgnTarVal;/* '<S1>/Data Type Conversion374' */

/* MMI_LocalBookChrgnTarVal  */
extern uint8 s2vd_MMI_RestSwitch;      /* '<S1>/Data Type Conversion251' */
extern uint8 s2vd_OBC_ChgCCSts;        /* '<S1>/Data Type Conversion907' */
extern uint8 s2vd_OBC_ChrgrSt;         /* '<S1>/Data Type Conversion1086' */
extern uint8 s2vd_OBC_Elock_Stmode;    /* '<S1>/Data Type Conversion1102' */
extern uint8 s2vd_OBC_LockLoopSts;     /* '<S1>/Data Type Conversion911' */
extern uint8 s2vd_OBC_OnBdCCline;      /* '<S1>/Data Type Conversion1100' */
extern uint8 s2vd_OBC_OnBdCPline;      /* '<S1>/Data Type Conversion1104' */
extern float32 s2vd_OBC_OnBdChrgrT;    /* '<S1>/Data Type Conversion1095' */
extern uint8 s2vd_OBC_OnBdDisChrgrCCline;/* '<S1>/Data Type Conversion878' */
extern float32 s2vd_OBC_OnBdOuptI_EV;  /* '<S1>/Data Type Conversion1093' */
extern float32 s2vd_OBC_OnBdOuptU_EV;  /* '<S1>/Data Type Conversion1091' */
extern float32 s2vd_OBC_PwrEgyMgrAvl;  /* '<S1>/Data Type Conversion1185' */
extern uint8 s2vd_OBC_SelfCheSts;      /* '<S1>/Data Type Conversion898' */
extern boolean s2vd_ODP_DCDC_TDcDcAlm; /* '<S1>/Data Type Conversion295' */
extern boolean s2vd_PDC_Brake_Flag;    /* '<S1>/Data Type Conversion170' */
extern boolean s2vd_PDC_Status_Info_AlvCtrErrFlg;/* '<S1>/Data Type Conversion249' */
extern boolean s2vd_PDC_Status_Info_CsmErrFlg;/* '<S1>/Data Type Conversion231' */
extern uint8 s2vd_PEPS_PowerMode;      /* '<S1>/Data Type Conversion364' */
extern uint8 s2vd_PEPS_PowerModeValidity;/* '<S1>/Data Type Conversion362' */
extern uint8 s2vd_PEPS_RKECommand;     /* '<S1>/Data Type Conversion462' */
extern boolean s2vd_PEPS_RemoteControlSt;/* '<S1>/Data Type Conversion968' */
extern boolean s2vd_PMS_CANBusOff_flg; /* '<S1>/Data Type Conversion1122' */
extern float32 s2vd_PTC_ActPower;      /* '<S1>/Data Type Conversion404' */
extern uint8 s2vd_PTC_Status;          /* '<S1>/Data Type Conversion400' */
extern uint8 s2vd_RFR_ConnectionStatus_EV;/* '<S1>/Data Type Conversion1069' */
extern uint64 s2vd_RFR_Seed_EV;        /* '<S1>/Data Type Conversion1075' */
extern uint64 s2vd_RFR_SwapBatCode_EV; /* '<S1>/Data Type Conversion1058' */
extern float32 s2vd_SAS_StrWhlAng;     /* '<S1>/Data Type Conversion962' */
extern boolean s2vd_Station_CarLocationConfirm_EV;/* '<S1>/Data Type Conversion1067' */
extern boolean s2vd_Station_CarStation_EV;/* '<S1>/Data Type Conversion1064' */
extern boolean s2vd_Station_SwapBatRequest_EV;/* '<S1>/Data Type Conversion1062' */
extern uint8 s2vd_Station_Swapingproceeding_EV;/* '<S1>/Data Type Conversion1060' */
extern float32 s2vd_TBOX_AllowChgCurrentMax;/* '<S1>/Data Type Conversion951' */
extern float32 s2vd_TBOX_ChargeDepth;  /* '<S1>/Data Type Conversion953' */
extern uint8 s2vd_TBOX_ChargeLimitSwitch;/* '<S1>/Data Type Conversion948' */
extern uint8 s2vd_TBOX_ChrgSoftSwCtrlSt;/* '<S1>/Data Type Conversion504' */
extern float32 s2vd_TBOX_Day;          /* '<S1>/Data Type Conversion500' */
extern uint16 s2vd_TBOX_Elevation;     /* '<S1>/Data Type Conversion514' */
extern uint8 s2vd_TBOX_FunAnti_DismantleActive;/* '<S1>/Data Type Conversion520' */
extern uint8 s2vd_TBOX_FunLockVehActive;/* '<S1>/Data Type Conversion518' */
extern uint8 s2vd_TBOX_Hour;           /* '<S1>/Data Type Conversion54' */
extern boolean s2vd_TBOX_IntelligentChargeCommand;/* '<S1>/Data Type Conversion512' */
extern uint8 s2vd_TBOX_InventorySpdLmtReq;/* '<S1>/Data Type Conversion1210' */
extern uint8 s2vd_TBOX_Life;           /* '<S1>/Data Type Conversion1212' */
extern float32 s2vd_TBOX_LockLimSet;   /* '<S1>/Data Type Conversion528' */
extern float32 s2vd_TBOX_LockResultResp;/* '<S1>/Data Type Conversion526' */
extern uint8 s2vd_TBOX_LockVehCtrl;    /* '<S1>/Data Type Conversion516' */
extern uint8 s2vd_TBOX_LockVehPerFlag; /* '<S1>/Data Type Conversion1203' */
extern uint8 s2vd_TBOX_LockVehType;    /* '<S1>/Data Type Conversion522' */
extern uint8 s2vd_TBOX_Minute;         /* '<S1>/Data Type Conversion494' */
extern uint8 s2vd_TBOX_Month;          /* '<S1>/Data Type Conversion498' */
extern boolean s2vd_TBOX_PowerOffCmd;  /* '<S1>/Data Type Conversion145' */
extern uint8 s2vd_TBOX_PriorityFullSwitchSts;/* '<S1>/Data Type Conversion508' */
extern boolean s2vd_TBOX_PriorityFullSwitchSts_UB;/* '<S1>/Data Type Conversion510' */
extern uint8 s2vd_TBOX_ReservationChrgnSts;/* '<S1>/Data Type Conversion506' */
extern float32 s2vd_TBOX_Second;       /* '<S1>/Data Type Conversion492' */
extern uint8 s2vd_TBOX_SpdLmtLevelReq; /* '<S1>/Data Type Conversion1205' */
extern uint8 s2vd_TBOX_VersionConversionFlag;/* '<S1>/Data Type Conversion1207' */
extern float32 s2vd_TBOX_Year;         /* '<S1>/Data Type Conversion502' */
extern uint32 s2vd_Veh_Network_Config_Data1;/* '<S1>/Data Type Conversion343' */
extern uint32 s2vd_Veh_Network_Config_Data2;/* '<S1>/Data Type Conversion345' */
extern float32 s2vd_YRS_LongitAcce;    /* '<S1>/Data Type Conversion434' */
extern float32 s2vd_acHvilPrdInpt;     /* '<S1>/Data Type Conversion628' */
extern boolean s2vd_accyEnReq;         /* '<S1>/Data Type Conversion1214' */
extern boolean s2vd_b_cntnrCtrlEnaFb;  /* '<S1>/Data Type Conversion1222' */

/* Container control enable feedback */
extern boolean s2vd_b_flgBBMMsgErr;    /* '<S1>/Data Type Conversion210' */
extern uint8 s2vd_brkPedlStsFromCan;   /* '<S1>/Data Type Conversion478' */
extern boolean s2vd_disChgSwtSt;       /* '<S1>/Data Type Conversion34' */
extern float32 s2vd_fan1Fb_pct;        /* '<S1>/Data Type Conversion31' */

/* Fan1 speed feedback */
extern boolean s2vd_hvbInPositionDetct1;/* '<S1>/Data Type Conversion1177' */
extern boolean s2vd_hvbInPositionDetct2;/* '<S1>/Data Type Conversion1179' */
extern float32 s2vd_odpHvilDtyInpt;    /* '<S1>/Data Type Conversion606' */
extern float32 s2vd_odpHvilPrdInpt;    /* '<S1>/Data Type Conversion608' */
extern uint16 s2vd_u_VacTkAirPres_mV;  /* '<S1>/Data Type Conversion335' */
extern uint16 s2vd_u_VacTkEnFb_mV;     /* '<S1>/Data Type Conversion337' */
extern float32 s2vd_u_brkVacuumPres_V; /* '<S1>/Data Type Conversion596' */
extern uint16 s2vd_u_pepsON_mv;        /* '<S1>/Data Type Conversion413' */
extern uint16 s2vd_u_vacTkPowSup_mV;   /* '<S1>/Data Type Conversion355' */
extern boolean trad_b_trsm2GearActVld; /* '<S281>/Logical Operator16' */

/* Secondary Transmission Actual Gear Valid */
extern boolean trad_b_trsm2GearshiftActv;/* '<S19>/Constant7' */

/* Secondary Transmission Gear-Shift Active */
extern ParkingStatus trad_e_trsm1PrkgSts;/* '<S278>/Switch' */

/* Primary Transmission Parking Status */
extern GearShiftResp trad_e_trsm2GearShftResp;/* '<S280>/Switch' */

/* Secondary Transmission Gear Shift Response */
extern float32 trad_fact_trsm2FinalDrvRat;/* '<S279>/MinMax1' */

/* Secondary Transmission Gear Ratio of Final Drive */
extern float32 trad_fact_trsm2GbxGearRat;/* '<S279>/MinMax2' */

/* Secondary Transmission Gear Ratio of Gearbox */
extern float32 trad_fact_trsm2GearRat; /* '<S279>/MinMax3' */

/* Secondary Transmission Gear Ratio */
extern sint8 trad_st_trsm2GearAct;     /* '<S281>/Switch1' */

/* Secondary Transmission Actual Gear */
extern boolean vcip_vild_b_ABSMsgErr;  /* '<S1363>/Switch2' */
extern boolean vcip_vild_b_MCUMsgErr;  /* '<S1361>/Switch2' */
extern uint32 vild_ECU_Fun_Config_Data1_eepRead;/* '<S1055>/C Caller5' */
extern uint32 vild_ECU_Fun_Config_Data2_eepRead;/* '<S1055>/C Caller4' */
extern uint32 vild_ECU_Fun_Config_Data2_eepWrite;/* '<S1055>/Switch7' */
extern uint32 vild_ECU_Network_Config_Data1_eepRead;/* '<S1055>/C Caller1' */
extern float32 vild_V_tankFuelLvl_l;   /* '<S1024>/Multiport Switch' */

/* Fuel Tank Level */
extern float32 vild_a_yrsLongitAcce_mps2;/* '<S1288>/Signal Conversion36' */
extern boolean vild_b_AccyEnReq;       /* '<S1008>/Switch2' */
extern boolean vild_b_AccyFltSts;      /* '<S1009>/Switch2' */
extern boolean vild_b_CCSginal;        /* '<S947>/Switch2' */
extern boolean vild_b_DryAirSwitch;    /* '<S948>/Switch2' */
extern boolean vild_b_HandBrk;         /* '<S992>/Switch2' */
extern boolean vild_b_HybridCanBusOff; /* '<S1010>/Switch2' */
extern boolean vild_b_MCUHealthMonErr; /* '<S145>/Switch2' */
extern boolean vild_b_PEPSMsgErrDebd;  /* '<S1189>/timed_debounce' */
extern boolean vild_b_PEPSMsgErrSet;   /* '<S1191>/Switch2' */
extern boolean vild_b_ResrAirSwitch;   /* '<S950>/Switch2' */
extern boolean vild_b_adc1ComErrFlg;   /* '<S6>/Logical Operator28' */
extern boolean vild_b_adcComErrFlg;    /* '<S6>/Logical Operator27' */
extern boolean vild_b_brkPumpFault;    /* '<S951>/Switch2' */
extern boolean vild_b_brkSwt1Actv;     /* '<S945>/Switch2' */

/* Brake switch 1 active */
extern boolean vild_b_brkSwt2Actv;     /* '<S946>/Switch2' */
extern boolean vild_b_calCanBusOff;    /* '<S952>/Switch2' */
extern boolean vild_b_cntnrCtrlEnaFb;  /* '<S1011>/Switch2' */

/* Container control enable feedback */
extern boolean vild_b_csmCampModeSwt;  /* '<S545>/Signal Conversion3' */
extern boolean vild_b_csmCampModeSwtInvld;/* '<S545>/SignalConversion2' */
extern boolean vild_b_csmEcoReqInvld;  /* '<S545>/SignalConversion169' */
extern boolean vild_b_csmEngRecSwtReq; /* '<S545>/SignalConversion3' */
extern boolean vild_b_csmTakeEleSwt;   /* '<S545>/Signal Conversion2' */
extern boolean vild_b_csmTakeEleSwtReqInvld;/* '<S545>/SignalConversion1' */
extern boolean vild_b_csmV2XDchaSw;    /* '<S1160>/Switch2' */
extern boolean vild_b_csmV2XDchaSwInvld;/* '<S1161>/Switch2' */
extern boolean vild_b_disChgSwtSt;     /* '<S1012>/Switch2' */
extern boolean vild_b_driverEVModeReq; /* '<S957>/Switch2' */
extern boolean vild_b_driverEcoModeReq;/* '<S955>/Switch2' */
extern boolean vild_b_drvCabOverturned;/* '<S1024>/Signal Conversion5' */

/* Driver Cab Overturned */
extern boolean vild_b_ehbIsaPtTrqDecReqActv;/* '<S1288>/Signal Conversion3' */
extern boolean vild_b_ehbVehSpdInvld;  /* '<S1324>/Switch2' */
extern boolean vild_b_ehbVlcCddActv;   /* '<S1288>/Signal Conversion8' */
extern boolean vild_b_emgyStopIn;      /* '<S956>/Switch2' */
extern boolean vild_b_epbErrSts;       /* '<S692>/Switch2' */
extern boolean vild_b_flgBBMMsgErr;    /* '<S1061>/Switch2' */
extern boolean vild_b_flgFctCfgACU;    /* '<S1105>/Switch2' */
extern boolean vild_b_flgFctCfgAccyButton;/* '<S1106>/switch' */
extern boolean vild_b_flgFctCfgAdc;    /* '<S1107>/Switch2' */
extern boolean vild_b_flgFctCfgAirBag; /* '<S1108>/switch' */

/* Airbag Type */
extern boolean vild_b_flgFctCfgBatCol; /* '<S1109>/switch' */

/* Battery Cool Type */
extern boolean vild_b_flgFctCfgChgTyp; /* '<S1110>/switch' */
extern boolean vild_b_flgFctCfgCoastActivBrkLight;/* '<S1111>/switch' */
extern boolean vild_b_flgFctCfgDrvMod; /* '<S1112>/switch' */

/* Drive Mode */
extern boolean vild_b_flgFctCfgDrvModConn;/* '<S1113>/switch' */
extern boolean vild_b_flgFctCfgDrvModStor;/* '<S1114>/switch' */
extern boolean vild_b_flgFctCfgDrvSeat;/* '<S1115>/Switch2' */
extern boolean vild_b_flgFctCfgDualAuthN;/* '<S1116>/Switch2' */
extern boolean vild_b_flgFctCfgEpdel;  /* '<S1117>/Switch2' */
extern boolean vild_b_flgFctCfgMaxChgCurr;/* '<S1118>/Switch2' */
extern boolean vild_b_flgFctCfgMotor;  /* '<S1119>/Switch2' */
extern boolean vild_b_flgFnctnConfgEHB;/* '<S1121>/Switch2' */
extern boolean vild_b_flgNetConfgABS;  /* '<S1122>/switch' */
extern boolean vild_b_flgPEPSAlvErr;   /* '<S1>/Data Type Conversion357' */
extern boolean vild_b_flgPEPSCsmErr;   /* '<S1>/Data Type Conversion365' */
extern boolean vild_b_flgPEPSMsgErr;   /* '<S1>/Data Type Conversion367' */
extern boolean vild_b_hcmAcceRlyVoltVldSts;/* '<S703>/Signal Conversion95' */
extern boolean vild_b_hcmMainPosBckVoltVldSts;/* '<S703>/Signal Conversion138' */
extern boolean vild_b_hcmPtcRlyVoltVldSts;/* '<S703>/Signal Conversion94' */
extern boolean vild_b_hvbChPwrLimdByTemp;/* '<S910>/Signal Conversion2' */

/* HVB Charge Power Limited By Temperature */
extern boolean vild_b_hvbDCChgCurReqRngUp;/* '<S703>/Signal Conversion136' */
extern boolean vild_b_hvbDisChgSopRngUp;/* '<S703>/Signal Conversion137' */
extern boolean vild_b_hvbDischPwrLimdByTemp;/* '<S911>/Signal Conversion2' */

/* HVB Discharge Power Limited By Temperature */
extern boolean vild_b_hvbHvilFlt;      /* '<S912>/Relational Operator' */

/* HV Battery HVIL Fault */
extern boolean vild_b_hvbInPositionDetct1;/* '<S1013>/Switch2' */
extern boolean vild_b_hvbInPositionDetct2;/* '<S1014>/Switch2' */
extern uint8 vild_b_hvbZeroPwrReq;     /* '<S703>/SigCon3' */
extern boolean vild_b_ignStsOn;        /* '<S1004>/Switch2' */
extern boolean vild_b_ignStsStrt;      /* '<S1006>/Switch2' */
extern boolean vild_b_ipkOdoBckUpEn;   /* '<S1024>/Signal Conversion' */
extern boolean vild_b_obcWakeUpActv;   /* '<S1003>/Switch2' */
extern boolean vild_b_odometerInvalid; /* '<S1024>/Logical Operator3' */

/* IC Odometer Invalid */
extern boolean vild_b_pdcBrkFlg;       /* '<S1288>/Signal Conversion4' */
extern boolean vild_b_pepsOnSwtSt;     /* '<S1015>/Switch2' */
extern boolean vild_b_pepsPduLvlVld;   /* '<S1193>/Switch2' */

/* PEPS PduLevel Valid */
extern boolean vild_b_pepsRmtCtrlSt;   /* '<S1192>/Switch2' */
extern boolean vild_b_ptCanBusOff;     /* '<S961>/Switch2' */
extern boolean vild_b_pullUpDiagCmpl;  /* '<S962>/Switch2' */
extern boolean vild_b_revModeSwitch;   /* '<S963>/Switch2' */
extern boolean vild_b_rstAvgFuelConsumption;/* '<S1024>/Signal Conversion8' */
extern boolean vild_b_rstAvgPwrConsumption;/* '<S1024>/Signal Conversion6' */
extern boolean vild_b_trsm2GearActFail;/* '<S1276>/Constant11' */

/* Secondary Transmission Actual Gear Failure */
extern boolean vild_b_trsm2GearShftReq;/* '<S1286>/Logical Operator2' */
extern boolean vild_b_trsm2OutpShaftSpdInvld;/* '<S1285>/Relational Operator' */

/* Secondary Transmission Output Shaft Speed Invalid */
extern boolean vild_b_vacTankLowPrs;   /* '<S964>/Switch2' */
extern boolean vild_b_vscSftyRelatedFctActv;/* '<S1353>/Relational Operator' */

/* ESP Safety Related Fuction Active */
extern float32 vild_d_bcmOdometerbackup;/* '<S510>/Switch2' */
extern float32 vild_d_ipkOdometerbackup;/* '<S1024>/Signal Conversion12' */
extern float32 vild_d_odometer_km;     /* '<S1024>/Switch5' */

/* IC Odometer */
extern float32 vild_d_vehTrip_km;      /* '<S1024>/Signal Conversion4' */

/* IC_Trip */
extern uint16 vild_el_tboxElevation;   /* '<S1232>/Signal Conversion16' */
extern float32 vild_frq_vehCrashStsFreq_Hz;/* '<S1018>/Switch2' */
extern float32 vild_i_hvbDCChgCurReq_A;/* '<S703>/Signal Conversion123' */
extern float32 vild_i_obcOutptCurr_A;  /* '<S1162>/Switch2' */
extern float32 vild_l_whlRad_m;        /* '<S1055>/Switch1' */

/* Wheel radius */
extern float32 vild_n_acFanReqSpd_pct; /* '<S365>/Switch2' */
extern uint16 vild_n_epbErrCod;        /* '<S693>/Switch2' */
extern float32 vild_n_trsm2OutpShaftSpd_rpm;/* '<S1276>/Signal Conversion1' */
extern uint8 vild_num_hvbCellMaxID;    /* '<S703>/Signal Conversion125' */
extern uint8 vild_num_hvbCellMinID;    /* '<S703>/Signal Conversion126' */
extern uint8 vild_num_hvbMaxTempID;    /* '<S703>/Signal Conversion127' */
extern uint8 vild_num_hvbMinTempID;    /* '<S703>/Signal Conversion128' */
extern uint8 vild_num_hvbTempSum;      /* '<S703>/Signal Conversion124' */
extern float32 vild_p_frontAirTankPres_kPa;/* '<S1024>/Signal Conversion1' */

/* Front Air Tank Pressure */
extern float32 vild_p_rearAirTankPres_kPa;/* '<S1024>/Signal Conversion2' */

/* Rear Air Tank Pressure */
extern float32 vild_pct_GearPosn;      /* '<S968>/Switch2' */
extern float32 vild_pct_HVILReturnPWM; /* '<S969>/Switch2' */
extern float32 vild_pct_WatPmpEP1FbPWM;/* '<S970>/Switch2' */
extern float32 vild_pct_WatPmpEP2FbPWM;/* '<S971>/Switch2' */
extern float32 vild_pct_WatPmpEP3FbPWM;/* '<S972>/Switch2' */
extern float32 vild_pct_fan1Fb;        /* '<S1019>/Switch2' */

/* Fan1 speed feedback */
extern float32 vild_pct_fan2Fb;        /* '<S1020>/Switch2' */

/* Fan2 speed feedback */
extern float32 vild_pct_mmiLocBkChgTarVal;/* '<S703>/Signal Conversion44' */

/* MMI_LocalBookChrgnTarVal  */
extern float32 vild_pct_vehCrashStsDuty;/* '<S976>/Switch2' */
extern float32 vild_pwr_accm1ActPwr_kW;/* '<S367>/Switch2' */
extern float32 vild_pwr_hvbMaxContChgPwr_kW;/* '<S847>/Switch2' */

/* Battery maximum continuous charge power */
extern float32 vild_pwr_hvbMaxPeakChgPwr_kW;/* '<S848>/Switch2' */

/* Battery maximum peak charge power */
extern float32 vild_pwr_hvbMaxPeakDischPwr_kW;/* '<S849>/Switch2' */

/* Battery maximum peak discharge power */
extern float32 vild_pwr_iptActPwr_kW;  /* '<S342>/Signal Conversion49' */
extern float32 vild_pwr_obcPwrEgyMgrAvl_kW;/* '<S1163>/Switch2' */
extern float32 vild_pwr_ptcActPwrRear_kW;/* '<S342>/Signal Conversion47' */
extern uint8 vild_st_BmsTempOutOfCtrlFlt;/* '<S852>/Switch2' */
extern uint8 vild_st_GearPosn;         /* '<S977>/Switch2' */
extern uint8 vild_st_PtcWrkSts;        /* '<S374>/Switch2' */
extern uint8 vild_st_acFltLvl;         /* '<S375>/Switch2' */

/* AC System Fault Level */
extern uint8 vild_st_acSubFltSts;      /* '<S376>/Switch2' */

/* AC System Sub Fault Level */
extern uint8 vild_st_batLowSoc2;       /* '<S703>/Signal Conversion130' */
extern uint8 vild_st_batOvrSoc2;       /* '<S703>/Signal Conversion129' */
extern uint8 vild_st_batOvrVolt2;      /* '<S703>/Signal Conversion134' */
extern uint8 vild_st_batUdrVolt2;      /* '<S703>/Signal Conversion133' */
extern uint8 vild_st_bbmFltSts;        /* '<S511>/Switch2' */
extern uint8 vild_st_bbmWorkSts;       /* '<S512>/Switch2' */
extern boolean vild_st_bcmFrntLDoorAjarSt;/* '<S503>/Data Type Conversion' */

/* BCM Front Left Door Ajar Status */
extern uint8 vild_st_bcmFrntRDoorAjarSt;/* '<S515>/Switch2' */

/* BCM Front Left Door Ajar Status */
extern uint8 vild_st_bmsBattPackMatchFlt;/* '<S703>/Signal Conversion50' */
extern uint8 vild_st_bmsBattPackNum;   /* '<S703>/Signal Conversion56' */
extern uint8 vild_st_bmsBattSysNum;    /* '<S703>/Signal Conversion55' */
extern uint8 vild_st_bmsDlyDataUpldEnb;/* '<S703>/Signal Conversion59' */
extern uint8 vild_st_bmsTboxFireAlm;   /* '<S703>/Signal Conversion45' */
extern uint8 vild_st_cellOverVolt2;    /* '<S703>/Signal Conversion132' */
extern uint8 vild_st_cellUdrVolt2;     /* '<S703>/Signal Conversion131' */
extern uint8 vild_st_chdLckActv;       /* '<S694>/Switch2' */
extern uint8 vild_st_csmEngRecReq;     /* '<S545>/Signal Conversion' */
extern boolean vild_st_csmEngRecReqInvalid;/* '<S545>/Signal Conversion1' */
extern uint8 vild_st_dccAccyConnStsFb; /* '<S591>/Switch2' */
extern uint32 vild_st_ecuFunConfigData1;/* '<S1062>/Switch2' */
extern uint32 vild_st_ecuFunConfigData2;/* '<S1063>/Switch2' */
extern uint8 vild_st_egsmFltLvl;       /* '<S612>/Switch2' */
extern uint8 vild_st_ehbBrkSysErrFlt;  /* '<S1337>/Switch2' */
extern uint8 vild_st_ehbEPBDynAppSts;  /* '<S1288>/Signal Conversion52' */
extern uint8 vild_st_ehbHHCActive;     /* '<S1288>/Signal Conversion44' */
extern uint8 vild_st_ehbIsaSts;        /* '<S1288>/Signal Conversion2' */
extern uint8 vild_st_epbFltLvl;        /* '<S695>/Switch2' */
extern uint8 vild_st_flg2FctCfgVehTyp; /* '<S1123>/switch' */
extern uint8 vild_st_flgFctCfgAccy;    /* '<S1124>/switch' */

/* Accy */
extern uint8 vild_st_flgFctCfgBatTyp;  /* '<S1125>/switch' */

/* Battery Type */
extern uint8 vild_st_flgFctCfgBox;     /* '<S1126>/switch' */
extern uint16 vild_st_flgFctCfgDspRemainRng;/* '<S1127>/switch' */
extern uint8 vild_st_flgFctCfgECOMaxSpd;/* '<S1128>/switch' */

/* ECO Speed Limit */
extern uint8 vild_st_flgFctCfgFan;     /* '<S1129>/switch' */

/* Fan Power */
extern uint8 vild_st_flgFctCfgMaxSpd;  /* '<S1130>/Switch2' */
extern uint8 vild_st_flgFctCfgMotTyp;  /* '<S1131>/switch' */

/* Motoe Type */
extern uint8 vild_st_flgFctCfgNormalMaxSpd;/* '<S1132>/switch' */

/* Normal Speed Limit */
extern uint8 vild_st_flgFctCfgPowerMaxSpd;/* '<S1133>/switch' */

/* Power Speed Limit */
extern uint8 vild_st_flgFctCfgSlowChg; /* '<S1134>/switch' */

/* Slow Chg */
extern uint8 vild_st_flgFctCfgTyre;    /* '<S1120>/switch' */

/* Tyre Type */
extern uint8 vild_st_flgFctCfgV2L;     /* '<S1135>/Switch2' */
extern uint8 vild_st_flgFctCfgVehCfg;  /* '<S1136>/switch' */
extern uint8 vild_st_flgFctCfgVehTyp;  /* '<S1137>/Switch2' */
extern uint8 vild_st_flgFctCfgVehUsg;  /* '<S1138>/switch' */
extern uint8 vild_st_hcmAccConnStsFb;  /* '<S703>/SigCon4' */
extern uint8 vild_st_hcmPTC1ConnStsFb; /* '<S703>/Signal Conversion29' */
extern uint8 vild_st_hillStrtAssi;     /* '<S696>/Switch2' */
extern uint8 vild_st_hvbBatUniformity; /* '<S703>/SigCon5' */
extern uint8 vild_st_hvbChgCcsts;      /* '<S703>/SigCon6' */
extern uint8 vild_st_hvbChgFltReq;     /* '<S866>/Switch2' */
extern uint8 vild_st_hvbChgSts;        /* '<S703>/SignalConversion3' */
extern uint8 vild_st_hvbDischgFltReq;  /* '<S872>/Switch2' */
extern uint8 vild_st_hvbPreChgSts;     /* '<S703>/Signal Conversion135' */
extern uint8 vild_st_hvbStsChgFlt;     /* '<S703>/SigCon2' */
extern uint8 vild_st_hvbStsDischgFlt;  /* '<S703>/SigCon1' */
extern boolean vild_st_ipkAlwChgSftCtlSt;/* '<S1164>/Switch2' */
extern boolean vild_st_ipkChgSftSwCtlSt;/* '<S1024>/Signal Conversion3' */
extern uint8 vild_st_ipkCruisingDstSwt;/* '<S1024>/Signal Conversion10' */
extern uint8 vild_st_iptWorkSt;        /* '<S342>/Signal Conversion50' */
extern uint8 vild_st_ipuMotorOverCurrFlt;/* '<S703>/Signal Conversion53' */
extern uint8 vild_st_ipuMotorOverSpdFlt;/* '<S703>/Signal Conversion51' */
extern uint8 vild_st_lowPresRelsPrkLim;/* '<S697>/Switch2' */
extern uint8 vild_st_mmiRestSwitch;    /* '<S703>/Signal Conversion41' */
extern uint8 vild_st_obcChgCCSts;      /* '<S1165>/Switch2' */
extern uint8 vild_st_obcChrgrSt;       /* '<S1166>/Switch2' */
extern uint8 vild_st_obcElckStMod;     /* '<S1167>/Switch2' */
extern uint8 vild_st_obcLockLoopSts;   /* '<S1168>/Switch2' */
extern uint8 vild_st_obcOnBdCCline;    /* '<S1169>/Switch2' */
extern uint8 vild_st_obcOnBdCPline;    /* '<S1170>/Switch2' */
extern uint8 vild_st_obcOnBdDchaCCline;/* '<S1171>/Switch2' */
extern uint8 vild_st_obcSelfChk;       /* '<S1172>/Switch2' */
extern uint8 vild_st_obcfltLvl;        /* '<S1173>/Switch2' */
extern uint8 vild_st_pepsPduLvl;       /* '<S1194>/Switch2' */

/* PEPS PduLevel */
extern uint8 vild_st_pepsRKECom;       /* '<S1195>/Switch2' */
extern uint8 vild_st_prkBrkSts;        /* '<S698>/Switch2' */
extern uint8 vild_st_ptCanNm;          /* '<S978>/Switch2' */
extern uint8 vild_st_ptcConnStsFb;     /* '<S380>/Switch2' */
extern uint8 vild_st_ptcWorkStRear;    /* '<S342>/Signal Conversion48' */
extern uint8 vild_st_tmpPrkActv;       /* '<S699>/Switch2' */
extern uint8 vild_st_tmpPrkBrkSts;     /* '<S700>/Switch2' */
extern uint8 vild_st_trsm2GearAct;     /* '<S1276>/Signal Conversion2' */
extern uint8 vild_st_trsm2Unauthorized;/* '<S1276>/Signal Conversion3' */
extern uint32 vild_st_vehNtwrkConfigData1;/* '<S1064>/Switch2' */
extern uint32 vild_st_vehNtwrkConfigData2;/* '<S1065>/Switch2' */
extern uint8 vild_st_vscEHBAVHSts;     /* '<S1288>/SignalConversion1' */
extern float32 vild_t_OutTempFltVal1s_C;/* '<S930>/RollingAverage' */
extern float32 vild_t_TS5sensorFb_C;   /* '<S979>/Switch2' */
extern float32 vild_t_hvbColInTempFltVal1s_C;/* '<S934>/RollingAverage' */
extern float32 vild_t_hvbColInTotTemp_C;/* '<S934>/Sum' */
extern float32 vild_t_hvbColOutTempFltVal1s_C;/* '<S938>/RollingAverage' */
extern float32 vild_t_hvbColOutTotTemp_C;/* '<S938>/Sum' */
extern float32 vild_t_hvbCooltInTemp_C;/* '<S980>/Switch2' */
extern float32 vild_t_hvbCooltOutTemp_C;/* '<S981>/Switch2' */
extern float32 vild_t_obcTemp_C;       /* '<S1174>/Switch2' */
extern float32 vild_t_totTemp_C;       /* '<S930>/Sum' */
extern float32 vild_tq_ehbIsaPtTrqDecReq_Nm;/* '<S1288>/Signal Conversion1' */
extern float32 vild_u_5VT1IntSmpl_V;   /* '<S982>/Switch2' */
extern float32 vild_u_5VT2IntSmpl_V;   /* '<S983>/Switch2' */
extern float32 vild_u_Acc1Raw_mV;      /* '<S984>/Switch2' */
extern float32 vild_u_Acc2Raw_mV;      /* '<S986>/Switch2' */
extern float32 vild_u_BmsMaxCellVolt_V;/* '<S898>/Switch2' */
extern float32 vild_u_BmsMinCellVolt_V;/* '<S899>/Switch2' */
extern float32 vild_u_Brk2Raw_mV;      /* '<S990>/Switch2' */
extern float32 vild_u_Brk2_V;          /* '<S922>/Signal Conversion3' */
extern float32 vild_u_BrkRaw_mV;       /* '<S991>/Switch2' */
extern float32 vild_u_Brk_V;           /* '<S922>/Signal Conversion2' */
extern float32 vild_u_TS5sensorFb_mV;  /* '<S993>/Switch2' */
extern float32 vild_u_VacTkAirPres_V;  /* '<S994>/Switch2' */
extern float32 vild_u_VacTkEnFb_V;     /* '<S995>/Switch2' */
extern float32 vild_u_accPdlSens1InpVolt_V;/* '<S985>/Switch2' */

/* Accelerator Pedal Position Sensor 1 Input Voltage */
extern float32 vild_u_accPdlSens2InpVolt_V;/* '<S987>/Switch2' */

/* Accelerator Pedal Position Sensor 2 Input Voltage */
extern float32 vild_u_batIntSmpl_V;    /* '<S996>/Switch2' */
extern float32 vild_u_batLpPmpCtrlFb_mV;/* '<S997>/Switch2' */
extern float32 vild_u_cbnLpPmpCtrlFb_mV;/* '<S998>/Switch2' */
extern float32 vild_u_cruiseADvoltage_V;/* '<S1022>/Switch2' */

/* Cruise Control Input Voltage */
extern float32 vild_u_eLpWpCtrlCur_mV; /* '<S1000>/Switch2' */
extern float32 vild_u_hcmAcceRlyVolt;  /* '<S703>/Signal Conversion74' */
extern float32 vild_u_hcmMainPosBckVolt;/* '<S703>/Signal Conversion96' */
extern float32 vild_u_hcmPtcRlyVolt;   /* '<S703>/Signal Conversion63' */
extern float32 vild_u_hvbCooltInSnsr_V;/* '<S1001>/Switch2' */

/* HVB Coolant Inlet Temperature Voltage */
extern float32 vild_u_hvbCooltOutSnsr_V;/* '<S1002>/Switch2' */

/* HVB Coolant Inlet Temperature Voltage */
extern float32 vild_u_obcOutptVolt_V;  /* '<S1175>/Switch2' */
extern float32 vild_u_pepsOn_mV;       /* '<S1005>/Switch2' */

/* Key on wake up voltage feedback */
extern uint16 vild_u_vacTkPowSup_V;    /* '<S1007>/Switch2' */
extern uint8 vild_v_AvrgVehSpd_kph;    /* '<S1024>/Signal Conversion9' */
extern float32 vild_v_ehbVehSpd_kph;   /* '<S1288>/Signal Conversion35' */
extern float32 vild_v_vscVehSpd_kph;   /* '<S1354>/Switch4' */

/* Vehicle Speed */
extern float32 vild_x_Brk2_pct;        /* '<S989>/Switch2' */
extern float32 vild_x_brkPedlPos_pct;  /* '<S988>/Switch2' */

/* Brake Pedal position */
extern float32 vscd_a_vscLongitAcce_mps2;/* '<S20>/SignalConversion1' */
extern boolean vscd_b_ESPActv;         /* '<S20>/Logical Operator' */

/* ESP Intervention active */
extern boolean vscd_b_ESPActvRaw;      /* '<S305>/timed_delay' */

/* ESP Intervention active raw */
extern boolean vscd_b_vehSpdVld;       /* '<S20>/Signal Conversion4' */

/* Vehicle Speed Valid */
extern boolean vscd_b_vscBrkLghtActv;  /* '<S304>/timed_debounce' */
extern uint8 vscd_ctr_absActvCntr;     /* '<S294>/Switch1' */

/* ABS Active Counter */
extern uint8 vscd_st_ehbAVHSts;        /* '<S20>/Signal Conversion5' */
extern uint8 vscd_st_ehbEPBDynAppSts;  /* '<S20>/Signal Conversion7' */
extern uint8 vscd_st_ehbHHCActive;     /* '<S20>/Signal Conversion6' */
extern uint8 vscd_st_vscIsgActvDampModReq;/* '<S20>/Switch1' */
extern float32 vscd_v_vehSpdRaw_kph;   /* '<S20>/Signal Conversion1' */

/* Vehicle Speed Raw */
#define swc_VCIP_STOP_SEC_VAR
#include "swc_VCIP_MemMap.h"

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'swc_VCIP'
 * '<S1>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing'
 * '<S2>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs'
 * '<S3>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer'
 * '<S4>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing'
 * '<S5>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing'
 * '<S6>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing'
 * '<S7>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing'
 * '<S8>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CCD_InputsProcessing'
 * '<S9>'   : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CES_InputsProcessing'
 * '<S10>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing'
 * '<S11>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DRI_InputsProcessing'
 * '<S12>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2'
 * '<S13>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EPB_InputsProcessing'
 * '<S14>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing'
 * '<S15>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing'
 * '<S16>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/OBC_InputsProcessing'
 * '<S17>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing'
 * '<S18>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm1'
 * '<S19>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2'
 * '<S20>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing'
 * '<S21>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/DocBlock'
 * '<S22>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/SR_latch1'
 * '<S23>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/Subsystem1'
 * '<S24>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/Subsystem3'
 * '<S25>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/state_mapping2'
 * '<S26>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/state_mapping5'
 * '<S27>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/state_mapping6'
 * '<S28>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/turnON_delay1'
 * '<S29>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/turnON_delay2'
 * '<S30>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/turnON_delay1/timed_delay'
 * '<S31>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACC_InputsProcessing/turnON_delay2/timed_delay'
 * '<S32>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionFilter'
 * '<S33>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionPlausibility'
 * '<S34>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalSensorsIntegration'
 * '<S35>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/DocBlock'
 * '<S36>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/HardwiredAccelPedal'
 * '<S37>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/Ovrd_b_accPed1Vld'
 * '<S38>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/Ovrd_b_accPed2Vld'
 * '<S39>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionFilter/DocBlock'
 * '<S40>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionFilter/filters'
 * '<S41>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionFilter/filters1'
 * '<S42>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionFilter/filters/1st Order Filter'
 * '<S43>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionFilter/filters1/1st Order Filter'
 * '<S44>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionPlausibility/DocBlock'
 * '<S45>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionPlausibility/PedalsOverlapDetection'
 * '<S46>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionPlausibility/vild_b_ACCPedalCrossNP'
 * '<S47>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionPlausibility/PedalsOverlapDetection/Enumerated Constant2'
 * '<S48>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalPositionPlausibility/vild_b_ACCPedalCrossNP/override_signal2'
 * '<S49>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/AccelPedalSensorsIntegration/DocBlock'
 * '<S50>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/HardwiredAccelPedal/DocBlock'
 * '<S51>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/HardwiredAccelPedal/VoltageToPositionConv_Sensor1'
 * '<S52>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/HardwiredAccelPedal/VoltageToPositionConv_Sensor2'
 * '<S53>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/HardwiredAccelPedal/VoltageToPositionConv_Sensor1/1st Order Filter'
 * '<S54>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/HardwiredAccelPedal/VoltageToPositionConv_Sensor1/Interval Test Dynamic'
 * '<S55>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/HardwiredAccelPedal/VoltageToPositionConv_Sensor2/1st Order Filter'
 * '<S56>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/HardwiredAccelPedal/VoltageToPositionConv_Sensor2/Interval Test Dynamic'
 * '<S57>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/Ovrd_b_accPed1Vld/override_signal'
 * '<S58>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ACP_InputsProcessing/Ovrd_b_accPed2Vld/override_signal'
 * '<S59>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/Compare To Constant2'
 * '<S60>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce'
 * '<S61>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce1'
 * '<S62>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce2'
 * '<S63>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce3'
 * '<S64>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce4'
 * '<S65>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce5'
 * '<S66>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/turnON_delay'
 * '<S67>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce/debounce'
 * '<S68>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce/debounce/timed_debounce'
 * '<S69>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce1/debounce'
 * '<S70>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce1/debounce/timed_debounce'
 * '<S71>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce2/debounce'
 * '<S72>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce2/debounce/timed_debounce'
 * '<S73>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce3/debounce'
 * '<S74>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce3/debounce/timed_debounce'
 * '<S75>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce4/debounce'
 * '<S76>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce4/debounce/timed_debounce'
 * '<S77>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce5/debounce'
 * '<S78>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/DFCSetWithDebounce5/debounce/timed_debounce'
 * '<S79>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/ADC_InputsProcessing/turnON_delay/timed_delay'
 * '<S80>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus'
 * '<S81>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakeSwitch'
 * '<S82>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakeVacuumSensor'
 * '<S83>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/DocBlock'
 * '<S84>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/Subsystem4'
 * '<S85>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/state_mapping6'
 * '<S86>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromCAN'
 * '<S87>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromSwitch'
 * '<S88>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromCAN/Enumerated Constant'
 * '<S89>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromCAN/Enumerated Constant1'
 * '<S90>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromCAN/Enumerated Constant2'
 * '<S91>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromCAN/state_mapping'
 * '<S92>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromSwitch/Enumerated Constant'
 * '<S93>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromSwitch/Enumerated Constant1'
 * '<S94>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakePedalStatus/BrakePedalStatusFromSwitch/Enumerated Constant3'
 * '<S95>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakeSwitch/Debounce'
 * '<S96>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakeSwitch/SwitchStateDetection'
 * '<S97>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakeSwitch/Debounce/debounce_brake_switch_1'
 * '<S98>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakeSwitch/Debounce/debounce_brake_switch_2'
 * '<S99>'  : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakeSwitch/Debounce/debounce_brake_switch_1/timed_debounce'
 * '<S100>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/BRP_InputsProcessing/BrakeSwitch/Debounce/debounce_brake_switch_2/timed_debounce'
 * '<S101>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CCD_InputsProcessing/model_info1'
 * '<S102>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CES_InputsProcessing/DocBlock'
 * '<S103>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CES_InputsProcessing/cesd_b_ACUMsgErr'
 * '<S104>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CES_InputsProcessing/vild_b_BMSHealthMonErr'
 * '<S105>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CES_InputsProcessing/vild_b_BMSMsgErr'
 * '<S106>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CES_InputsProcessing/cesd_b_ACUMsgErr/override_signal1'
 * '<S107>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CES_InputsProcessing/vild_b_BMSHealthMonErr/override_signal2'
 * '<S108>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/CES_InputsProcessing/vild_b_BMSMsgErr/override_signal1'
 * '<S109>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/DocBlock'
 * '<S110>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/SR_latch1'
 * '<S111>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/Subsystem1'
 * '<S112>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/Subsystem2'
 * '<S113>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/state_mapping1'
 * '<S114>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/state_mapping6'
 * '<S115>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/turnON_delay1'
 * '<S116>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/turnON_delay2'
 * '<S117>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/xx2kxx'
 * '<S118>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/Subsystem2/Enumerated Constant4'
 * '<S119>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/Subsystem2/state_mapping'
 * '<S120>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/turnON_delay1/timed_delay'
 * '<S121>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DCC_InputsProcessing/turnON_delay2/timed_delay'
 * '<S122>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DRI_InputsProcessing/DocBlock'
 * '<S123>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DRI_InputsProcessing/EcoButtonCounter'
 * '<S124>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DRI_InputsProcessing/state_mapping'
 * '<S125>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DRI_InputsProcessing/state_mapping  '
 * '<S126>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/DRI_InputsProcessing/EcoButtonCounter/Detect Increase3'
 * '<S127>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/1st Order Filter'
 * '<S128>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/1st Order Filter1'
 * '<S129>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/1st Order Filter2'
 * '<S130>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/MotorSpeedValidity'
 * '<S131>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Subsystem1'
 * '<S132>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque'
 * '<S133>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/eadInv2RdyToCutOffLV'
 * '<S134>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/eadInv2RdyToDischargeLV'
 * '<S135>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/state_mapping'
 * '<S136>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/state_mapping1'
 * '<S137>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/state_mapping2'
 * '<S138>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/state_mapping6'
 * '<S139>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/xx2kxx'
 * '<S140>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/xx2kxx1'
 * '<S141>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/MotorSpeedValidity/DFC_Ovrd1'
 * '<S142>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/MotorSpeedValidity/DFC_Ovrd2'
 * '<S143>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/MotorSpeedValidity/MotSpd_kph2rpm'
 * '<S144>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/MotorSpeedValidity/DFC_Ovrd1/override_signal'
 * '<S145>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/MotorSpeedValidity/DFC_Ovrd2/override_signal'
 * '<S146>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/MotorSpeedValidity/MotSpd_kph2rpm/kph2mps'
 * '<S147>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/Hysteresis_InitValue'
 * '<S148>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val'
 * '<S149>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val2'
 * '<S150>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val3'
 * '<S151>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val4'
 * '<S152>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val/neg'
 * '<S153>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val/pos'
 * '<S154>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val2/neg'
 * '<S155>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val2/pos'
 * '<S156>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val3/neg'
 * '<S157>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val3/pos'
 * '<S158>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val4/neg'
 * '<S159>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EAD_InputsProcessingMot2/Torque/abs_val4/pos'
 * '<S160>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/EPB_InputsProcessing/state_mapping'
 * '<S161>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/1st Order Filter'
 * '<S162>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/1st Order Filter '
 * '<S163>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/1st Order Filter  '
 * '<S164>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/1st Order Filter   '
 * '<S165>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/1st Order Filter    '
 * '<S166>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/DocBlock'
 * '<S167>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge'
 * '<S168>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus'
 * '<S169>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/SR_latch'
 * '<S170>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/state_mapping'
 * '<S171>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/state_mapping1'
 * '<S172>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/state_mapping3'
 * '<S173>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/state_mapping4'
 * '<S174>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/state_mapping5'
 * '<S175>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/state_mapping6'
 * '<S176>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/state_mapping7'
 * '<S177>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/turnON_delay'
 * '<S178>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/turnON_delay '
 * '<S179>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/xx2kxx'
 * '<S180>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/xx2kxx1'
 * '<S181>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Compare To Constant1'
 * '<S182>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Compare To Constant2'
 * '<S183>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Detect Increase'
 * '<S184>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Detect Increase6'
 * '<S185>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/SR_latch1'
 * '<S186>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/SR_latch2'
 * '<S187>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/SR_latch3'
 * '<S188>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1'
 * '<S189>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/turnOFF_delay'
 * '<S190>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/turnON_delay1'
 * '<S191>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Compare To Constant'
 * '<S192>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Compare To Constant6'
 * '<S193>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Detect Increase1'
 * '<S194>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Detect Increase2'
 * '<S195>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Detect Increase3'
 * '<S196>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Detect Increase4'
 * '<S197>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Detect Increase5'
 * '<S198>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Enumerated Constant12'
 * '<S199>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Enumerated Constant13'
 * '<S200>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Ovrd_VCU_DCDCEnableOut'
 * '<S201>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/SR_latch4'
 * '<S202>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/SR_latch5'
 * '<S203>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/SR_latch6'
 * '<S204>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/SR_latch7'
 * '<S205>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/SR_latch8'
 * '<S206>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Subsystem'
 * '<S207>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay'
 * '<S208>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay2'
 * '<S209>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay3'
 * '<S210>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay4'
 * '<S211>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay5'
 * '<S212>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay6'
 * '<S213>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay7'
 * '<S214>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Ovrd_VCU_DCDCEnableOut/override_signal'
 * '<S215>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Subsystem/turnON_delay'
 * '<S216>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/Subsystem/turnON_delay/timed_delay'
 * '<S217>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay/timed_delay'
 * '<S218>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay2/timed_delay'
 * '<S219>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay3/timed_delay'
 * '<S220>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay4/timed_delay'
 * '<S221>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay5/timed_delay'
 * '<S222>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay6/timed_delay'
 * '<S223>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/Subsystem1/turnON_delay7/timed_delay'
 * '<S224>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/turnOFF_delay/timed_delay'
 * '<S225>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/IntelligentCharge/turnON_delay1/timed_delay'
 * '<S226>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Compare To Constant1'
 * '<S227>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Compare To Constant10'
 * '<S228>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Compare To Constant12'
 * '<S229>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Compare To Constant13'
 * '<S230>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Compare To Constant2'
 * '<S231>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Compare To Constant3'
 * '<S232>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Compare To Constant4'
 * '<S233>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Compare To Constant5'
 * '<S234>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Enumerated Constant'
 * '<S235>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Enumerated Constant1'
 * '<S236>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Enumerated Constant10'
 * '<S237>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Enumerated Constant11'
 * '<S238>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Enumerated Constant5'
 * '<S239>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/RelaysStatus/Enumerated Constant6'
 * '<S240>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/turnON_delay/timed_delay'
 * '<S241>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/HVB_InputsProcessing/turnON_delay /timed_delay'
 * '<S242>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing/Ovrd_st_CP_SelfCheckSts'
 * '<S243>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing/Subsystem1'
 * '<S244>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing/kxx2xx'
 * '<S245>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing/kxx2xx1'
 * '<S246>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing/pa2bar'
 * '<S247>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing/pa2bar1'
 * '<S248>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing/state_mapping6'
 * '<S249>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/MAC_InputsProcessing/Ovrd_st_CP_SelfCheckSts/override_signal'
 * '<S250>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/OBC_InputsProcessing/Enumerated Constant5'
 * '<S251>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/OBC_InputsProcessing/ObcWakeUpDelay'
 * '<S252>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/OBC_InputsProcessing/xx2kxx1'
 * '<S253>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/OBC_InputsProcessing/xx2kxx2'
 * '<S254>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/OBC_InputsProcessing/ObcWakeUpDelay/turnON_delay'
 * '<S255>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/OBC_InputsProcessing/ObcWakeUpDelay/turnON_delay/timed_delay'
 * '<S256>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/DocBlock'
 * '<S257>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus'
 * '<S258>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/KeyAuthenticationStatus'
 * '<S259>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel'
 * '<S260>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/Determine_Ignition_Status'
 * '<S261>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/Enumerated Constant1'
 * '<S262>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/Enumerated Constant2'
 * '<S263>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/Enumerated Constant3'
 * '<S264>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/Enumerated Constant4'
 * '<S265>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/Enumerated Constant5'
 * '<S266>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/PDULevel'
 * '<S267>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/debounce'
 * '<S268>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/state_mapping'
 * '<S269>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/CheckPDULevel/debounce/timed_debounce'
 * '<S270>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/Determine_Ignition_Status/SR_latch'
 * '<S271>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/Determine_Ignition_Status/SR_latch1'
 * '<S272>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/Determine_Ignition_Status/Subsystem'
 * '<S273>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/IgnitionStatus/Determine_Ignition_Status/Subsystem/override_signal1'
 * '<S274>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/KeyAuthenticationStatus/default'
 * '<S275>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/KeyAuthenticationStatus/fail'
 * '<S276>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/PMM_InputsProcessing/KeyAuthenticationStatus/success'
 * '<S277>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm1/TransmissionStates'
 * '<S278>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm1/TransmissionStates/state_mapping2'
 * '<S279>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearRatios'
 * '<S280>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse'
 * '<S281>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/TransmissionStates'
 * '<S282>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearRatios/RateLimit'
 * '<S283>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/Enumerated Constant1'
 * '<S284>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/Enumerated Constant2'
 * '<S285>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/Enumerated Constant4'
 * '<S286>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/Enumerated Constant5'
 * '<S287>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/Enumerated Constant6'
 * '<S288>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/Enumerated Constant7'
 * '<S289>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/abs_val'
 * '<S290>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/abs_val/neg'
 * '<S291>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/GearShiftResponse/abs_val/pos'
 * '<S292>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/TRA_InputsProcessingTrsm2/TransmissionStates/state_mapping1'
 * '<S293>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/1st Order Filter'
 * '<S294>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/AbsActiveCounter'
 * '<S295>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Detect Increase'
 * '<S296>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Enumerated Constant'
 * '<S297>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Enumerated Constant1'
 * '<S298>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Enumerated Constant2'
 * '<S299>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Enumerated Constant3'
 * '<S300>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/RegenerativeBrakingCatB'
 * '<S301>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/SR_latch'
 * '<S302>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Subsystem'
 * '<S303>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/VSC_Interventions'
 * '<S304>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/debounce'
 * '<S305>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/turnOFF_delay'
 * '<S306>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/turnOFF_delay2'
 * '<S307>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/turnON_delay'
 * '<S308>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/AbsActiveCounter/Detect Increase1'
 * '<S309>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/AbsActiveCounter/Detect Increase3'
 * '<S310>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Subsystem/1st Order Filter1'
 * '<S311>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Subsystem/1st Order Filter2'
 * '<S312>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/Subsystem/MATLAB Function'
 * '<S313>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/debounce/timed_debounce'
 * '<S314>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/turnOFF_delay/timed_delay'
 * '<S315>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/turnOFF_delay2/timed_delay'
 * '<S316>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VCI__VCU_Control_Inputs/VSC_InputsProcessing/turnON_delay/timed_delay'
 * '<S317>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ACP_in'
 * '<S318>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in'
 * '<S319>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in'
 * '<S320>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ATS_in'
 * '<S321>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in'
 * '<S322>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in'
 * '<S323>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in'
 * '<S324>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in'
 * '<S325>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in'
 * '<S326>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DRI_in'
 * '<S327>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in'
 * '<S328>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in'
 * '<S329>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in'
 * '<S330>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in'
 * '<S331>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in'
 * '<S332>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in'
 * '<S333>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in'
 * '<S334>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in'
 * '<S335>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in'
 * '<S336>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in'
 * '<S337>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in'
 * '<S338>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in'
 * '<S339>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in'
 * '<S340>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ACP_in/convert'
 * '<S341>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in'
 * '<S342>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/convert'
 * '<S343>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_AC_PreSenorVolt'
 * '<S344>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_b_acAmbTempInvalid'
 * '<S345>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_n_acFanReqSpd'
 * '<S346>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_PTCActPwr'
 * '<S347>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_accm1ActPwr'
 * '<S348>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_acwpHeatPower'
 * '<S349>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_airCmprAct'
 * '<S350>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_iptActPwr_kW'
 * '<S351>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_ptcActPwrRear'
 * '<S352>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_ACSwtSt'
 * '<S353>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_PTCSt'
 * '<S354>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_PtcWrkSts'
 * '<S355>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_acFltLvl'
 * '<S356>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_acSubFltSts'
 * '<S357>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_airCmprSt'
 * '<S358>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_cbnThermMngReq'
 * '<S359>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_iptWorkSt'
 * '<S360>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_ptcConnStsFb'
 * '<S361>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_ptcWorkStRear'
 * '<S362>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_t_acwpOutptTemp_C'
 * '<S363>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_t_outdTemp'
 * '<S364>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_AC_PreSenorVolt/override_signal'
 * '<S365>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_n_acFanReqSpd/override_signal'
 * '<S366>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_PTCActPwr/override_signal'
 * '<S367>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_accm1ActPwr/override_signal'
 * '<S368>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_acwpHeatPower/override_signal'
 * '<S369>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_airCmprAct/override_signal'
 * '<S370>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_iptActPwr_kW/override_signal'
 * '<S371>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_pwr_ptcActPwrRear/override_signal'
 * '<S372>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_ACSwtSt/override_signal'
 * '<S373>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_PTCSt/override_signal'
 * '<S374>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_PtcWrkSts/override_signal'
 * '<S375>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_acFltLvl/override_signal'
 * '<S376>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_acSubFltSts/override_signal'
 * '<S377>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_airCmprSt/override_signal'
 * '<S378>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_cbnThermMngReq/override_signal'
 * '<S379>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_iptWorkSt/override_signal'
 * '<S380>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_ptcConnStsFb/override_signal'
 * '<S381>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_st_ptcWorkStRear/override_signal'
 * '<S382>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_t_acwpOutptTemp_C/override_signal'
 * '<S383>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/AC_in/AC_in/Ovrd_t_outdTemp/override_signal'
 * '<S384>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in'
 * '<S385>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/convert'
 * '<S386>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01CtrAlvCtrErrFlg'
 * '<S387>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01CtrComRxToutFlg'
 * '<S388>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01CtrCsmErrFlg'
 * '<S389>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01PMSCtrAlvCtrErrFlg'
 * '<S390>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01PMSCtrComRxToutFlg'
 * '<S391>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01PMSCtrCsmErrFlg'
 * '<S392>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrAlvCtrErrFlg'
 * '<S393>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrComRxToutFlg'
 * '<S394>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrCsmErrFlg'
 * '<S395>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrlGearEn'
 * '<S396>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrlSts'
 * '<S397>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrlTorqEn'
 * '<S398>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02PMSCtrAlvCtrErrFlg'
 * '<S399>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02PMSCtrComRxToutFlg'
 * '<S400>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02PMSCtrCsmErrFlg'
 * '<S401>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02SystSts'
 * '<S402>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc0CtrlGearEn'
 * '<S403>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc0CtrlSts'
 * '<S404>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc0CtrlTorqEn'
 * '<S405>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc0SystSts'
 * '<S406>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11CtrAlvCtrErrFlg'
 * '<S407>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11CtrComRxToutFlg'
 * '<S408>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11CtrCsmErrFlg'
 * '<S409>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11PMSCtrAlvCtrErrFlg'
 * '<S410>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11PMSCtrComRxToutFlg'
 * '<S411>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11PMSCtrCsmErrFlg'
 * '<S412>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CanbusFlg'
 * '<S413>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrAlvCtrErrFlg'
 * '<S414>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrComRxToutFlg'
 * '<S415>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrCsmErrFlg'
 * '<S416>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrlGearEn'
 * '<S417>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrlSts'
 * '<S418>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrlTorqEn'
 * '<S419>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12PMSCtrAlvCtrErrFlg'
 * '<S420>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12PMSCtrComRxToutFlg'
 * '<S421>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12PMSCtrCsmErrFlg'
 * '<S422>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12SwitchCtrlReq'
 * '<S423>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12SystSts'
 * '<S424>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1CanbusFlg'
 * '<S425>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1CtrlGearEn'
 * '<S426>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1CtrlSts'
 * '<S427>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1CtrlTorqEn'
 * '<S428>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1SwitchCtrlReq'
 * '<S429>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1SystSts'
 * '<S430>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adcCANBusOffFlg'
 * '<S431>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_pmsCANBusOffFlg'
 * '<S432>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_st_adc02TargetGearPostion'
 * '<S433>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_st_adc0TargetGearPostion'
 * '<S434>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_st_adc12TargetGearPostion'
 * '<S435>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_st_adc1TargetGearPostion'
 * '<S436>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_t_adc02Temp'
 * '<S437>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_t_adc0Temp'
 * '<S438>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_t_adc12Temp'
 * '<S439>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_t_adc1Temp'
 * '<S440>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_tq_adc02TargetDrvTq'
 * '<S441>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_tq_adc0TargetDrvTq_Nm'
 * '<S442>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_tq_adc12TargetDrvTq'
 * '<S443>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_tq_adc1TargetDrvTq'
 * '<S444>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01CtrAlvCtrErrFlg/override_signal'
 * '<S445>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01CtrComRxToutFlg/override_signal'
 * '<S446>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01CtrCsmErrFlg/override_signal'
 * '<S447>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01PMSCtrAlvCtrErrFlg/override_signal'
 * '<S448>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01PMSCtrComRxToutFlg/override_signal'
 * '<S449>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc01PMSCtrCsmErrFlg/override_signal'
 * '<S450>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrAlvCtrErrFlg/override_signal'
 * '<S451>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrComRxToutFlg/override_signal'
 * '<S452>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrCsmErrFlg/override_signal'
 * '<S453>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrlGearEn/override_signal'
 * '<S454>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrlSts/override_signal'
 * '<S455>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02CtrlTorqEn/override_signal'
 * '<S456>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02PMSCtrAlvCtrErrFlg/override_signal'
 * '<S457>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02PMSCtrComRxToutFlg/override_signal'
 * '<S458>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02PMSCtrCsmErrFlg/override_signal'
 * '<S459>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc02SystSts/override_signal'
 * '<S460>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc0CtrlGearEn/override_signal'
 * '<S461>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc0CtrlSts/override_signal'
 * '<S462>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc0CtrlTorqEn/override_signal'
 * '<S463>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc0SystSts/override_signal'
 * '<S464>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11CtrAlvCtrErrFlg/override_signal'
 * '<S465>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11CtrComRxToutFlg/override_signal'
 * '<S466>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11CtrCsmErrFlg/override_signal'
 * '<S467>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11PMSCtrAlvCtrErrFlg/override_signal'
 * '<S468>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11PMSCtrComRxToutFlg/override_signal'
 * '<S469>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc11PMSCtrCsmErrFlg/override_signal'
 * '<S470>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CanbusFlg/override_signal'
 * '<S471>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrAlvCtrErrFlg/override_signal'
 * '<S472>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrComRxToutFlg/override_signal'
 * '<S473>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrCsmErrFlg/override_signal'
 * '<S474>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrlGearEn/override_signal'
 * '<S475>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrlSts/override_signal'
 * '<S476>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12CtrlTorqEn/override_signal'
 * '<S477>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12PMSCtrAlvCtrErrFlg/override_signal'
 * '<S478>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12PMSCtrComRxToutFlg/override_signal'
 * '<S479>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12PMSCtrCsmErrFlg/override_signal'
 * '<S480>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12SwitchCtrlReq/override_signal'
 * '<S481>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc12SystSts/override_signal'
 * '<S482>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1CanbusFlg/override_signal'
 * '<S483>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1CtrlGearEn/override_signal'
 * '<S484>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1CtrlSts/override_signal'
 * '<S485>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1CtrlTorqEn/override_signal'
 * '<S486>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1SwitchCtrlReq/override_signal'
 * '<S487>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adc1SystSts/override_signal'
 * '<S488>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_adcCANBusOffFlg/override_signal'
 * '<S489>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_b_pmsCANBusOffFlg/override_signal'
 * '<S490>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_st_adc02TargetGearPostion/override_signal'
 * '<S491>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_st_adc0TargetGearPostion/override_signal'
 * '<S492>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_st_adc12TargetGearPostion/override_signal'
 * '<S493>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_st_adc1TargetGearPostion/override_signal'
 * '<S494>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_t_adc02Temp/override_signal'
 * '<S495>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_t_adc0Temp/override_signal'
 * '<S496>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_t_adc12Temp/override_signal'
 * '<S497>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_t_adc1Temp/override_signal'
 * '<S498>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_tq_adc02TargetDrvTq/override_signal'
 * '<S499>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_tq_adc0TargetDrvTq_Nm/override_signal'
 * '<S500>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_tq_adc12TargetDrvTq/override_signal'
 * '<S501>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ADC_in/ADC_in/Ovrd_tq_adc1TargetDrvTq/override_signal'
 * '<S502>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ATS_in/ATS_in'
 * '<S503>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in'
 * '<S504>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_d_bcmOdometerbackup'
 * '<S505>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bbmFltSts'
 * '<S506>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bbmWorkSts'
 * '<S507>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bcmATWSSt'
 * '<S508>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bcmFrntLDoorAjarSt'
 * '<S509>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bcmFrntRDoorAjarSt'
 * '<S510>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_d_bcmOdometerbackup/override_signal'
 * '<S511>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bbmFltSts/override_signal'
 * '<S512>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bbmWorkSts/override_signal'
 * '<S513>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bcmATWSSt/override_signal'
 * '<S514>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bcmFrntLDoorAjarSt/override_signal'
 * '<S515>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCM_in/BCM_in/Ovrd_st_bcmFrntRDoorAjarSt/override_signal'
 * '<S516>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in'
 * '<S517>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/convert'
 * '<S518>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_b_brkPedlStsInVld'
 * '<S519>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_st_brkPmpEnaOutFb'
 * '<S520>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_st_brkPmpSelfChk'
 * '<S521>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_st_brkPmpWrkSt'
 * '<S522>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_u_brkVacuumPres'
 * '<S523>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_b_brkPedlStsInVld/override_signal'
 * '<S524>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_st_brkPmpEnaOutFb/override_signal'
 * '<S525>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_st_brkPmpSelfChk/override_signal'
 * '<S526>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_st_brkPmpWrkSt/override_signal'
 * '<S527>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/BCP_in/Ovrd_u_brkVacuumPres/override_signal'
 * '<S528>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/convert/brkPmpSelfChk'
 * '<S529>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/convert/brkPmpSelfChk/Compare To Constant1'
 * '<S530>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/BCP_in/convert/brkPmpSelfChk/Compare To Constant2'
 * '<S531>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in'
 * '<S532>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_b_acuDrvSeatbltBcklInvld'
 * '<S533>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_b_acuDrvSeatbltBcklSts'
 * '<S534>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_st_acuCrashOutStsC'
 * '<S535>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_st_acuCrashOutStsPT'
 * '<S536>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_st_acuCrashStsInvalid'
 * '<S537>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_st_acuWarnLampSts'
 * '<S538>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_b_acuDrvSeatbltBcklInvld/override_signal'
 * '<S539>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_b_acuDrvSeatbltBcklSts/override_signal'
 * '<S540>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_st_acuCrashOutStsC/override_signal'
 * '<S541>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_st_acuCrashOutStsPT/override_signal'
 * '<S542>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_st_acuCrashStsInvalid/override_signal'
 * '<S543>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CES_in/CES_in/Ovrd_st_acuWarnLampSts/override_signal'
 * '<S544>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in'
 * '<S545>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/convert'
 * '<S546>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmCampModeSwt'
 * '<S547>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmCampModeSwtInvld'
 * '<S548>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmEcoReqInvld'
 * '<S549>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmEngRecSwtReq'
 * '<S550>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmTakeEleSwt'
 * '<S551>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmTakeEleSwtReqInvld'
 * '<S552>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_st_csmEngRecReq'
 * '<S553>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_st_csmEngRecReqInvalid'
 * '<S554>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmCampModeSwt/override_signal'
 * '<S555>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmCampModeSwtInvld/override_signal'
 * '<S556>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmEcoReqInvld/override_signal'
 * '<S557>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmEngRecSwtReq/override_signal'
 * '<S558>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmTakeEleSwt/override_signal'
 * '<S559>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/CSM_in/CSM_in/Ovrd_b_csmTakeEleSwtReqInvld/override_signal'
 * '<S560>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in'
 * '<S561>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/convert'
 * '<S562>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_b_dcdcStsAlm'
 * '<S563>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_b_dcdcTempAlm'
 * '<S564>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_i_dcdcInpCurr'
 * '<S565>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_i_dcdcOutpCurr'
 * '<S566>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_24vDcdcFltSts'
 * '<S567>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_24vDcdcModAct'
 * '<S568>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_24vDcdcSelfChk'
 * '<S569>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_24vDcdcSubFltSts'
 * '<S570>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dccAccyConnStsFb'
 * '<S571>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcCanComFlt'
 * '<S572>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcCutOffLvFb'
 * '<S573>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcErrorCode'
 * '<S574>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcFltSts'
 * '<S575>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcModAct'
 * '<S576>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcOutpOvrCurr'
 * '<S577>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcOutpOvrVolt'
 * '<S578>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcSelfChk'
 * '<S579>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_t_24vDcdcTemp'
 * '<S580>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_u_dcdcInpVolt'
 * '<S581>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_u_dcdcOutpVolt'
 * '<S582>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_u_dcdcRelayVolt'
 * '<S583>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_b_dcdcStsAlm/override_signal'
 * '<S584>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_b_dcdcTempAlm/override_signal'
 * '<S585>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_i_dcdcInpCurr/override_signal'
 * '<S586>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_i_dcdcOutpCurr/override_signal'
 * '<S587>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_24vDcdcFltSts/override_signal'
 * '<S588>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_24vDcdcModAct/override_signal'
 * '<S589>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_24vDcdcSelfChk/override_signal'
 * '<S590>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_24vDcdcSubFltSts/override_signal'
 * '<S591>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dccAccyConnStsFb/override_signal'
 * '<S592>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcCanComFlt/override_signal'
 * '<S593>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcCutOffLvFb/override_signal'
 * '<S594>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcErrorCode/override_signal'
 * '<S595>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcFltSts/override_signal'
 * '<S596>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcModAct/override_signal'
 * '<S597>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcOutpOvrCurr/override_signal'
 * '<S598>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcOutpOvrVolt/override_signal'
 * '<S599>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_st_dcdcSelfChk/override_signal'
 * '<S600>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_t_24vDcdcTemp/override_signal'
 * '<S601>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_u_dcdcInpVolt/override_signal'
 * '<S602>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_u_dcdcOutpVolt/override_signal'
 * '<S603>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/DCDC_in/Ovrd_u_dcdcRelayVolt/override_signal'
 * '<S604>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/convert/Subsystem4'
 * '<S605>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/convert/Subsystem7'
 * '<S606>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/convert/dcdcSelfChk'
 * '<S607>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DCDC_in/convert/dcdcSelfChk/Compare To Constant2'
 * '<S608>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DRI_in/Ovrd_st_drvrReqdGear'
 * '<S609>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DRI_in/Ovrd_st_egsmLeverPosition'
 * '<S610>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DRI_in/Ovrd_st_egsmParkReq'
 * '<S611>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DRI_in/Ovrd_st_drvrReqdGear/GearLeverConvertLDT'
 * '<S612>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DRI_in/Ovrd_st_drvrReqdGear/Ovrd_st_egsmFltLvl'
 * '<S613>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/DRI_in/Ovrd_st_drvrReqdGear/Ovrd_st_egsmGearReq'
 * '<S614>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in'
 * '<S615>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/convert'
 * '<S616>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_b_ipuIsgSpdActSgnInvld'
 * '<S617>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_i_eadInv2ActCurrDC'
 * '<S618>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_n_eadMot2ActSpd'
 * '<S619>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_pwr_eadMot2ActOutpPwr'
 * '<S620>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2ActMod'
 * '<S621>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2ActvDischgFlt'
 * '<S622>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2CanComFlt'
 * '<S623>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2CtrlMod'
 * '<S624>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2FltSts'
 * '<S625>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2HVLFlt'
 * '<S626>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2IgbtFlt'
 * '<S627>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2MemFlt'
 * '<S628>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2PwrActvMod'
 * '<S629>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2RotInvFlt'
 * '<S630>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2SelfChk'
 * '<S631>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2TempHiAlrm'
 * '<S632>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2TempSnsrErr'
 * '<S633>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2WrkMod'
 * '<S634>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2BlkRotErr'
 * '<S635>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2ImmoRlsChk'
 * '<S636>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2SpdHiAlrm'
 * '<S637>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2SysOvrLdAlrm'
 * '<S638>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2TempHiAlrm'
 * '<S639>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2TempHiFlt'
 * '<S640>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2TempSnsrErr'
 * '<S641>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_inv2SubFltSts'
 * '<S642>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_ipuInvTempHighAlm'
 * '<S643>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_ipuMotTempHighFlt'
 * '<S644>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_ipuMotorSubFltLvl'
 * '<S645>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_t_eadInv2Temp'
 * '<S646>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_t_eadMot2Temp'
 * '<S647>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_tq_eadMot2ActTq'
 * '<S648>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_tq_eadMot2LTBstTqLim'
 * '<S649>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_tq_eadMot2LTGenTqLim'
 * '<S650>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_u_eadInv2ActVoltDC'
 * '<S651>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_u_ipuHVBusVolt'
 * '<S652>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_b_ipuIsgSpdActSgnInvld/override_signal'
 * '<S653>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_i_eadInv2ActCurrDC/override_signal'
 * '<S654>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_n_eadMot2ActSpd/override_signal'
 * '<S655>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_pwr_eadMot2ActOutpPwr/override_signal'
 * '<S656>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2ActMod/override_signal'
 * '<S657>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2ActvDischgFlt/override_signal'
 * '<S658>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2CanComFlt/override_signal'
 * '<S659>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2CtrlMod/override_signal'
 * '<S660>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2FltSts/override_signal'
 * '<S661>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2HVLFlt/override_signal'
 * '<S662>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2IgbtFlt/override_signal'
 * '<S663>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2MemFlt/override_signal'
 * '<S664>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2PwrActvMod/override_signal'
 * '<S665>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2RotInvFlt/override_signal'
 * '<S666>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2SelfChk/override_signal'
 * '<S667>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2TempHiAlrm/override_signal'
 * '<S668>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2TempSnsrErr/override_signal'
 * '<S669>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadInv2WrkMod/override_signal'
 * '<S670>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2BlkRotErr/override_signal'
 * '<S671>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2ImmoRlsChk/override_signal'
 * '<S672>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2SpdHiAlrm/override_signal'
 * '<S673>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2SysOvrLdAlrm/override_signal'
 * '<S674>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2TempHiAlrm/override_signal'
 * '<S675>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2TempHiFlt/override_signal'
 * '<S676>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_eadMot2TempSnsrErr/override_signal'
 * '<S677>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_inv2SubFltSts/override_signal'
 * '<S678>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_ipuInvTempHighAlm/override_signal'
 * '<S679>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_ipuMotTempHighFlt/override_signal'
 * '<S680>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_st_ipuMotorSubFltLvl/override_signal'
 * '<S681>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_t_eadInv2Temp/override_signal'
 * '<S682>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_t_eadMot2Temp/override_signal'
 * '<S683>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_tq_eadMot2ActTq/override_signal'
 * '<S684>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_tq_eadMot2LTBstTqLim/override_signal'
 * '<S685>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_tq_eadMot2LTGenTqLim/override_signal'
 * '<S686>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_u_eadInv2ActVoltDC/override_signal'
 * '<S687>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/EDA2_in/Ovrd_u_ipuHVBusVolt/override_signal'
 * '<S688>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/convert/Subsystem2'
 * '<S689>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EAD2_in/convert/eadInv2SelfChk'
 * '<S690>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in'
 * '<S691>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/convert'
 * '<S692>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_b_epbErrSts'
 * '<S693>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_n_epbErrCod'
 * '<S694>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_st_chdLckActv'
 * '<S695>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_st_epbFltLvl'
 * '<S696>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_st_hillStrtAssi'
 * '<S697>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_st_lowPresRelsPrkLim'
 * '<S698>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_st_prkBrkSts'
 * '<S699>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_st_tmpPrkActv'
 * '<S700>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/EPB_in/EPB_in/Ovrd_st_tmpPrkBrkSts'
 * '<S701>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in'
 * '<S702>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in'
 * '<S703>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert'
 * '<S704>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_b_hcmAcceRlyVoltVldSts'
 * '<S705>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_b_hcmMainPosBckVoltVldSts'
 * '<S706>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_b_hcmPtcRlyVoltVldSts'
 * '<S707>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_pct_mmiLocBkChgTarVal'
 * '<S708>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsBattPackMatchFlt'
 * '<S709>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsBattPackNum'
 * '<S710>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsBattSysNum'
 * '<S711>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsDlyDataUpldEnb'
 * '<S712>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsTboxFireAlm'
 * '<S713>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmAccConnStsFb'
 * '<S714>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmCutOffLvFb'
 * '<S715>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmFltLvl'
 * '<S716>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmHvilSt'
 * '<S717>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmPTC1ConnStsFb'
 * '<S718>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmPtcDefRlyStFb'
 * '<S719>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmPwrActvMod'
 * '<S720>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmSelfChk'
 * '<S721>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmWrkSt'
 * '<S722>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hvbMaiRlyPos'
 * '<S723>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_ipuMotorOverCurrFlt'
 * '<S724>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_ipuMotorOverSpdFlt'
 * '<S725>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_mmiRestSwitch'
 * '<S726>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_u_hcmAcceRlyVolt'
 * '<S727>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_u_hcmMainPosBckVolt'
 * '<S728>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_u_hcmPtcRlyVolt'
 * '<S729>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_b_hcmAcceRlyVoltVldSts/override_signal'
 * '<S730>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_b_hcmMainPosBckVoltVldSts/override_signal'
 * '<S731>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_b_hcmPtcRlyVoltVldSts/override_signal'
 * '<S732>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_pct_mmiLocBkChgTarVal/override_signal'
 * '<S733>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsBattPackMatchFlt/override_signal'
 * '<S734>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsBattPackNum/override_signal'
 * '<S735>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsBattSysNum/override_signal'
 * '<S736>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsDlyDataUpldEnb/override_signal'
 * '<S737>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_bmsTboxFireAlm/override_signal'
 * '<S738>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmAccConnStsFb/override_signal'
 * '<S739>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmCutOffLvFb/override_signal'
 * '<S740>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmFltLvl/override_signal'
 * '<S741>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmHvilSt/override_signal'
 * '<S742>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmPTC1ConnStsFb/override_signal'
 * '<S743>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmPtcDefRlyStFb/override_signal'
 * '<S744>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmPwrActvMod/override_signal'
 * '<S745>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmSelfChk/override_signal'
 * '<S746>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hcmWrkSt/override_signal'
 * '<S747>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_hvbMaiRlyPos/override_signal'
 * '<S748>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_ipuMotorOverCurrFlt/override_signal'
 * '<S749>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_ipuMotorOverSpdFlt/override_signal'
 * '<S750>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_st_mmiRestSwitch/override_signal'
 * '<S751>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_u_hcmAcceRlyVolt/override_signal'
 * '<S752>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_u_hcmMainPosBckVolt/override_signal'
 * '<S753>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HCM_in/Ovrd_u_hcmPtcRlyVolt/override_signal'
 * '<S754>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_E_hvbPackRemnEgy'
 * '<S755>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_R_NegInslRes'
 * '<S756>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_R_posInslRes'
 * '<S757>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_b_hvbDCChgCurReqRngUp'
 * '<S758>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_b_hvbDisChgSopRngUp'
 * '<S759>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_b_hvbSelfChkSt'
 * '<S760>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_b_hvbZeroPwrReq'
 * '<S761>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_fact_hvbSOH'
 * '<S762>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_i_hvbCurr'
 * '<S763>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_i_hvbDCChgCurReq'
 * '<S764>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_i_hvbMaxPrmtDischCurr'
 * '<S765>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_i_hvbMaxPrmtRgnCurr'
 * '<S766>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbCellMaxID'
 * '<S767>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbCellMinID'
 * '<S768>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbCellSum'
 * '<S769>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbMaxTempID'
 * '<S770>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbMinTempID'
 * '<S771>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbTempSum'
 * '<S772>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_pwr_hvbMaxContChgPwr'
 * '<S773>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_pwr_hvbMaxPeakChgPwr'
 * '<S774>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_pwr_hvbMaxPeakDischPwr'
 * '<S775>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_q_hvbSOC'
 * '<S776>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_q_hvbSOC01'
 * '<S777>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_BmsTempOutOfCtrlFlt'
 * '<S778>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_actWorkSts'
 * '<S779>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_batLowSoc2'
 * '<S780>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_batOvrSoc2'
 * '<S781>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_batOvrVolt2'
 * '<S782>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_batUdrVolt2'
 * '<S783>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_cellOverVolt2'
 * '<S784>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_cellUdrVolt2'
 * '<S785>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbBatUniformity'
 * '<S786>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbBattIsolationSts'
 * '<S787>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbBmsHwFlt'
 * '<S788>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbCellTempDevFlt'
 * '<S789>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbCellVoltDevFlt'
 * '<S790>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgCcsts'
 * '<S791>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgFltReq'
 * '<S792>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgOvrCurr'
 * '<S793>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgStatus'
 * '<S794>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgSts'
 * '<S795>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbDCChgPlgNOvrTmp'
 * '<S796>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbDCChgProcss'
 * '<S797>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbDischgFltReq'
 * '<S798>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbEmgyCutOffReq'
 * '<S799>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbFltSt'
 * '<S800>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbHVIsolationSts'
 * '<S801>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbHeatSts'
 * '<S802>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbHvilSts'
 * '<S803>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbInCoolTemp'
 * '<S804>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbInslErr'
 * '<S805>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbMaiRlyNeg'
 * '<S806>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbOvrChgFlt'
 * '<S807>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbPreChgSts'
 * '<S808>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbPrmtCutOffLvFb'
 * '<S809>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbPwrActvMod'
 * '<S810>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbSocFlt'
 * '<S811>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbSocJumpFlt'
 * '<S812>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbStsChgFlt'
 * '<S813>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbStsDischgFlt'
 * '<S814>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbSubFaultSts'
 * '<S815>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbTempFlt'
 * '<S816>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbThermMngReq'
 * '<S817>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbAvg'
 * '<S818>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbMax'
 * '<S819>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbMin'
 * '<S820>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbOutCoolTemp'
 * '<S821>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbSetTgtTemp'
 * '<S822>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_tm_hvbFnshChgTim'
 * '<S823>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_u_BmsMaxCellVolt'
 * '<S824>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_u_BmsMinCellVolt'
 * '<S825>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_u_hvbPackVolt'
 * '<S826>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_u_hvbVolt'
 * '<S827>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Subsystem'
 * '<S828>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Subsystem7'
 * '<S829>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_E_hvbPackRemnEgy/override_signal'
 * '<S830>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_R_NegInslRes/override_signal'
 * '<S831>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_R_posInslRes/override_signal'
 * '<S832>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_b_hvbDCChgCurReqRngUp/override_signal'
 * '<S833>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_b_hvbDisChgSopRngUp/override_signal'
 * '<S834>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_b_hvbSelfChkSt/override_signal'
 * '<S835>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_b_hvbZeroPwrReq/override_signal'
 * '<S836>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_fact_hvbSOH/override_signal'
 * '<S837>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_i_hvbCurr/override_signal'
 * '<S838>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_i_hvbDCChgCurReq/override_signal'
 * '<S839>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_i_hvbMaxPrmtDischCurr/override_signal'
 * '<S840>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_i_hvbMaxPrmtRgnCurr/override_signal'
 * '<S841>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbCellMaxID/override_signal'
 * '<S842>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbCellMinID/override_signal'
 * '<S843>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbCellSum/override_signal'
 * '<S844>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbMaxTempID/override_signal'
 * '<S845>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbMinTempID/override_signal'
 * '<S846>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_num_hvbTempSum/override_signal'
 * '<S847>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_pwr_hvbMaxContChgPwr/override_signal'
 * '<S848>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_pwr_hvbMaxPeakChgPwr/override_signal'
 * '<S849>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_pwr_hvbMaxPeakDischPwr/override_signal'
 * '<S850>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_q_hvbSOC/override_signal'
 * '<S851>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_q_hvbSOC01/override_signal'
 * '<S852>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_BmsTempOutOfCtrlFlt/override_signal'
 * '<S853>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_actWorkSts/override_signal'
 * '<S854>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_batLowSoc2/override_signal'
 * '<S855>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_batOvrSoc2/override_signal'
 * '<S856>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_batOvrVolt2/override_signal'
 * '<S857>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_batUdrVolt2/override_signal'
 * '<S858>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_cellOverVolt2/override_signal'
 * '<S859>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_cellUdrVolt2/override_signal'
 * '<S860>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbBatUniformity/override_signal'
 * '<S861>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbBattIsolationSts/override_signal'
 * '<S862>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbBmsHwFlt/override_signal'
 * '<S863>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbCellTempDevFlt/override_signal'
 * '<S864>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbCellVoltDevFlt/override_signal'
 * '<S865>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgCcsts/override_signal'
 * '<S866>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgFltReq/override_signal'
 * '<S867>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgOvrCurr/override_signal'
 * '<S868>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgStatus/override_signal'
 * '<S869>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbChgSts/override_signal'
 * '<S870>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbDCChgPlgNOvrTmp/override_signal'
 * '<S871>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbDCChgProcss/override_signal'
 * '<S872>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbDischgFltReq/override_signal'
 * '<S873>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbEmgyCutOffReq/override_signal'
 * '<S874>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbFltSt/override_signal'
 * '<S875>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbHVIsolationSts/override_signal'
 * '<S876>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbHeatSts/override_signal'
 * '<S877>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbHvilSts/override_signal'
 * '<S878>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbInCoolTemp/override_signal'
 * '<S879>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbInslErr/override_signal'
 * '<S880>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbMaiRlyNeg/override_signal'
 * '<S881>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbOvrChgFlt/override_signal'
 * '<S882>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbPreChgSts/override_signal'
 * '<S883>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbPrmtCutOffLvFb/override_signal'
 * '<S884>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbPwrActvMod/override_signal'
 * '<S885>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbSocFlt/override_signal'
 * '<S886>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbSocJumpFlt/override_signal'
 * '<S887>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbStsChgFlt/override_signal'
 * '<S888>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbStsDischgFlt/override_signal'
 * '<S889>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbSubFaultSts/override_signal'
 * '<S890>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbTempFlt/override_signal'
 * '<S891>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_st_hvbThermMngReq/override_signal'
 * '<S892>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbAvg/override_signal'
 * '<S893>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbMax/override_signal'
 * '<S894>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbMin/override_signal'
 * '<S895>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbOutCoolTemp/override_signal'
 * '<S896>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_t_hvbSetTgtTemp/override_signal'
 * '<S897>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_tm_hvbFnshChgTim/override_signal'
 * '<S898>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_u_BmsMaxCellVolt/override_signal'
 * '<S899>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_u_BmsMinCellVolt/override_signal'
 * '<S900>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_u_hvbPackVolt/override_signal'
 * '<S901>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Ovrd_u_hvbVolt/override_signal'
 * '<S902>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Subsystem/Ovrd_st_hvbDCChgPlgPOvrTmp'
 * '<S903>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/HVB_in/Subsystem/Ovrd_st_hvbDCChgPlgPOvrTmp/override_signal'
 * '<S904>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/AssistRlyStatusCheck'
 * '<S905>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/HVBStatusMerge'
 * '<S906>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/HcmNegRlyStatusCheck'
 * '<S907>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/HcmPtcDefRlyStFb'
 * '<S908>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/MainNegRlyStatusCheck'
 * '<S909>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/MainPosRlyStatusCheck'
 * '<S910>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/MaxPmtChPwr'
 * '<S911>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/MaxPmtDischPwr'
 * '<S912>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/Subsystem11'
 * '<S913>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/Subsystem15'
 * '<S914>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/Subsystem6'
 * '<S915>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/Subsystem7'
 * '<S916>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/Subsystem8'
 * '<S917>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/hcmSelfChk'
 * '<S918>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/hvbSelfChk'
 * '<S919>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/hcmSelfChk/Compare To Constant2'
 * '<S920>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HVB_in/convert/hvbSelfChk/Compare To Constant2'
 * '<S921>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in'
 * '<S922>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert'
 * '<S923>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/Subsystem6'
 * '<S924>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter'
 * '<S925>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter1'
 * '<S926>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter2'
 * '<S927>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/debounce'
 * '<S928>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/debounce1'
 * '<S929>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter/Compare To Constant1'
 * '<S930>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter/Subsystem'
 * '<S931>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter/Subsystem/RollingAverage'
 * '<S932>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter/Subsystem/timer'
 * '<S933>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter1/Compare To Constant1'
 * '<S934>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter1/Subsystem'
 * '<S935>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter1/Subsystem/RollingAverage'
 * '<S936>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter1/Subsystem/timer'
 * '<S937>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter2/Compare To Constant1'
 * '<S938>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter2/Subsystem'
 * '<S939>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter2/Subsystem/RollingAverage'
 * '<S940>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/TempFilter2/Subsystem/timer'
 * '<S941>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/debounce/timed_debounce'
 * '<S942>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/HW_in/debounce1/timed_debounce'
 * '<S943>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_AccyEnReq'
 * '<S944>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_AccyFltSts'
 * '<S945>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_BrkSwitch'
 * '<S946>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_BrkSwitch2'
 * '<S947>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_CCSginal'
 * '<S948>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_DryAirSwitch'
 * '<S949>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_HybridCanBusOff'
 * '<S950>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_ResrAirSwitch'
 * '<S951>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_brkPumpFault'
 * '<S952>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_calCanBusOff'
 * '<S953>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_cntnrCtrlEnaFb'
 * '<S954>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_disChgSwtSt'
 * '<S955>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_ecoModeSwitch'
 * '<S956>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_emgyStopIn'
 * '<S957>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_evModeSwitch'
 * '<S958>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_hvbInPositionDetct1'
 * '<S959>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_hvbInPositionDetct2'
 * '<S960>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_pepsOnSwtSt'
 * '<S961>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_ptCanBusOff'
 * '<S962>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_pullUpDiagCmpl'
 * '<S963>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_revModeSwitch'
 * '<S964>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_vacTankLowPrs'
 * '<S965>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_fq_acHOvrPrdInpt'
 * '<S966>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_fq_odpHOvrPrdInpt'
 * '<S967>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_frq_vehCrashStsFreq'
 * '<S968>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_GearPosn'
 * '<S969>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_HVILReturnPWM'
 * '<S970>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_WatPmpEP1FbPWM'
 * '<S971>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_WatPmpEP2FbPWM'
 * '<S972>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_WatPmpEP3FbPWM'
 * '<S973>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_fan1Fb'
 * '<S974>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_fan2Fb'
 * '<S975>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_odpHvilDtyInpt'
 * '<S976>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_vehCrashStsDuty'
 * '<S977>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_st_GearPosn'
 * '<S978>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_st_ptCanNm'
 * '<S979>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_t_TS5sensorFb'
 * '<S980>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_t_hvbCooltInTemp_C'
 * '<S981>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_t_hvbCooltOutTemp_C'
 * '<S982>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_5VT1IntSmpl'
 * '<S983>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_5VT2IntSmpl'
 * '<S984>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_Acc1Raw_mV'
 * '<S985>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_Acc1_V'
 * '<S986>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_Acc2Raw_mV'
 * '<S987>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_Acc2_V'
 * '<S988>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_Brk'
 * '<S989>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_Brk2'
 * '<S990>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_Brk2Raw_mV'
 * '<S991>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_BrkRaw_mV'
 * '<S992>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_HandBrk'
 * '<S993>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_TS5sensorFb_mV'
 * '<S994>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_VacTkAirPres_V'
 * '<S995>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_VacTkEnFb_V'
 * '<S996>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_batIntSmpl'
 * '<S997>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_batLpPmpCtrlFb_mV'
 * '<S998>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_cbnLpPmpCtrlFb_mV'
 * '<S999>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_cruiseADvoltage'
 * '<S1000>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_eLpWpCtrlCur_mV'
 * '<S1001>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_hvbCooltInSnsr_V'
 * '<S1002>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_hvbCooltOutSnsr_V'
 * '<S1003>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_obcWakeHCU_V'
 * '<S1004>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_pepsON_V'
 * '<S1005>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_pepsOn_mV'
 * '<S1006>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_pepsStart_V'
 * '<S1007>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_vacTkPowSup_V'
 * '<S1008>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_AccyEnReq/override_signal'
 * '<S1009>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_AccyFltSts/override_signal'
 * '<S1010>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_HybridCanBusOff/override_signal'
 * '<S1011>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_cntnrCtrlEnaFb/override_signal'
 * '<S1012>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_disChgSwtSt/override_signal'
 * '<S1013>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_hvbInPositionDetct1/override_signal'
 * '<S1014>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_hvbInPositionDetct2/override_signal'
 * '<S1015>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_b_pepsOnSwtSt/override_signal'
 * '<S1016>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_fq_acHOvrPrdInpt/override_signal'
 * '<S1017>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_fq_odpHOvrPrdInpt/override_signal'
 * '<S1018>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_frq_vehCrashStsFreq/override_signal'
 * '<S1019>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_fan1Fb/override_signal'
 * '<S1020>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_fan2Fb/override_signal'
 * '<S1021>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_pct_odpHvilDtyInpt/override_signal'
 * '<S1022>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/HW_in/convert/Ovrd_u_cruiseADvoltage/override_signal'
 * '<S1023>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in'
 * '<S1024>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/convert'
 * '<S1025>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_IC_FrontAirTankPressure'
 * '<S1026>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_IC_FuelLevel'
 * '<S1027>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_IC_FuelLevelSts'
 * '<S1028>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_IC_RearAirTankPressure'
 * '<S1029>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_drvCabOverturned'
 * '<S1030>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_ipkOdoBckUpEn'
 * '<S1031>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_rstAvgFuelConsumption'
 * '<S1032>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_rstAvgPwrConsumption'
 * '<S1033>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_d_ipkOdometerbackup'
 * '<S1034>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_d_odometer'
 * '<S1035>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_d_vehTrip'
 * '<S1036>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_st_ipkChgSftSwCtlSt'
 * '<S1037>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_st_ipkCruisingDstSwt'
 * '<S1038>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_v_ICAvrgVehSpd '
 * '<S1039>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_IC_FrontAirTankPressure/override_signal'
 * '<S1040>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_IC_FuelLevel/override_signal'
 * '<S1041>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_IC_FuelLevelSts/override_signal'
 * '<S1042>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_IC_RearAirTankPressure/override_signal'
 * '<S1043>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_drvCabOverturned/invert_boolean'
 * '<S1044>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_drvCabOverturned/override_signal'
 * '<S1045>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_ipkOdoBckUpEn/override_signal'
 * '<S1046>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_rstAvgFuelConsumption/override_signal'
 * '<S1047>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_b_rstAvgPwrConsumption/override_signal'
 * '<S1048>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_d_ipkOdometerbackup/override_signal'
 * '<S1049>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_d_odometer/override_signal'
 * '<S1050>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_d_vehTrip/override_signal'
 * '<S1051>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_st_ipkChgSftSwCtlSt/override_signal'
 * '<S1052>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_st_ipkCruisingDstSwt/override_signal'
 * '<S1053>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/ICU_in/ICU_in/Ovrd_v_ICAvrgVehSpd /override_signal'
 * '<S1054>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in'
 * '<S1055>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1'
 * '<S1056>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_b_flgBBMMsgErr'
 * '<S1057>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_st_ecuFunConfigData1'
 * '<S1058>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_st_ecuFunConfigData2'
 * '<S1059>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_st_vehNtwrkConfigData1'
 * '<S1060>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_st_vehNtwrkConfigData2'
 * '<S1061>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_b_flgBBMMsgErr/override_signal'
 * '<S1062>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_st_ecuFunConfigData1/override_signal'
 * '<S1063>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_st_ecuFunConfigData2/override_signal'
 * '<S1064>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_st_vehNtwrkConfigData1/override_signal'
 * '<S1065>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in/Ovrd_st_vehNtwrkConfigData2/override_signal'
 * '<S1066>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Compare To Constant'
 * '<S1067>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Compare To Constant1'
 * '<S1068>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Compare To Constant2'
 * '<S1069>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Compare To Constant3'
 * '<S1070>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Compare To Constant4'
 * '<S1071>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgACU'
 * '<S1072>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgAccyButton'
 * '<S1073>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgAdc'
 * '<S1074>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgAirBag'
 * '<S1075>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgBatCol'
 * '<S1076>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgChgTyp'
 * '<S1077>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgCoastActivBrkLight'
 * '<S1078>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDrvMod'
 * '<S1079>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDrvModConn'
 * '<S1080>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDrvModStor'
 * '<S1081>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDrvSeat'
 * '<S1082>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDualAuthN'
 * '<S1083>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgEpdel'
 * '<S1084>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgMaxChgCurr'
 * '<S1085>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgMotor'
 * '<S1086>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgTyre'
 * '<S1087>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFnctnConfgEHB'
 * '<S1088>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgNetConfgABS'
 * '<S1089>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flg2FctCfgVehTyp'
 * '<S1090>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgAccy'
 * '<S1091>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgBatTyp'
 * '<S1092>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgBox'
 * '<S1093>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgDspRemainRng'
 * '<S1094>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgECOMaxSpd'
 * '<S1095>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgFan'
 * '<S1096>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgMaxSpd'
 * '<S1097>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgMotTyp'
 * '<S1098>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgNormalMaxSpd'
 * '<S1099>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgPowerMaxSpd'
 * '<S1100>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgSlowChg'
 * '<S1101>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgV2L'
 * '<S1102>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgVehCfg'
 * '<S1103>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgVehTyp'
 * '<S1104>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgVehUsg'
 * '<S1105>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgACU/override_signal'
 * '<S1106>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgAccyButton/override_signal'
 * '<S1107>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgAdc/override_signal'
 * '<S1108>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgAirBag/override_signal'
 * '<S1109>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgBatCol/override_signal'
 * '<S1110>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgChgTyp/override_signal'
 * '<S1111>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgCoastActivBrkLight/override_signal'
 * '<S1112>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDrvMod/override_signal'
 * '<S1113>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDrvModConn/override_signal'
 * '<S1114>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDrvModStor/override_signal'
 * '<S1115>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDrvSeat/override_signal'
 * '<S1116>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgDualAuthN/override_signal'
 * '<S1117>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgEpdel/override_signal'
 * '<S1118>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgMaxChgCurr/override_signal'
 * '<S1119>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgMotor/override_signal'
 * '<S1120>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFctCfgTyre/override_signal'
 * '<S1121>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgFnctnConfgEHB/override_signal'
 * '<S1122>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_b_flgNetConfgABS/override_signal'
 * '<S1123>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flg2FctCfgVehTyp/override_signal'
 * '<S1124>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgAccy/override_signal'
 * '<S1125>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgBatTyp/override_signal'
 * '<S1126>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgBox/override_signal'
 * '<S1127>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgDspRemainRng/override_signal'
 * '<S1128>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgECOMaxSpd/override_signal'
 * '<S1129>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgFan/override_signal'
 * '<S1130>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgMaxSpd/override_signal'
 * '<S1131>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgMotTyp/override_signal'
 * '<S1132>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgNormalMaxSpd/override_signal'
 * '<S1133>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgPowerMaxSpd/override_signal'
 * '<S1134>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgSlowChg/override_signal'
 * '<S1135>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgV2L/override_signal'
 * '<S1136>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgVehCfg/override_signal'
 * '<S1137>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgVehTyp/override_signal'
 * '<S1138>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/NWM_in/NWM_in1/Ovrd_st_flgFctCfgVehUsg/override_signal'
 * '<S1139>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/DC_Charger_in'
 * '<S1140>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override'
 * '<S1141>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/convert'
 * '<S1142>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/DC_Charger_in/Ovrd_st_dcChgCcSt'
 * '<S1143>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/DC_Charger_in/Ovrd_st_dcChgCcSt/override_signal'
 * '<S1144>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_b_csmV2XDchaSw'
 * '<S1145>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_b_csmV2XDchaSwInvld'
 * '<S1146>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_i_obcOutptCurr'
 * '<S1147>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_pwr_obcPwrEgyMgrAvl '
 * '<S1148>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_ipkAlwChgSftCtlSt'
 * '<S1149>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcChgCCSts'
 * '<S1150>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcChrgrSt'
 * '<S1151>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcElckStMod'
 * '<S1152>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcLockLoopSts'
 * '<S1153>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcOnBdCCline'
 * '<S1154>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcOnBdCPline'
 * '<S1155>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcOnBdDisChgCCline'
 * '<S1156>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcSelfChk'
 * '<S1157>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcfltLvl'
 * '<S1158>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_t_obcTemp'
 * '<S1159>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_u_obcOutptVolt'
 * '<S1160>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_b_csmV2XDchaSw/override_signal'
 * '<S1161>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_b_csmV2XDchaSwInvld/override_signal'
 * '<S1162>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_i_obcOutptCurr/override_signal'
 * '<S1163>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_pwr_obcPwrEgyMgrAvl /override_signal'
 * '<S1164>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_ipkAlwChgSftCtlSt/override_signal'
 * '<S1165>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcChgCCSts/override_signal'
 * '<S1166>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcChrgrSt/override_signal'
 * '<S1167>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcElckStMod/override_signal'
 * '<S1168>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcLockLoopSts/override_signal'
 * '<S1169>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcOnBdCCline/override_signal'
 * '<S1170>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcOnBdCPline/override_signal'
 * '<S1171>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcOnBdDisChgCCline/override_signal'
 * '<S1172>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcSelfChk/override_signal'
 * '<S1173>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_st_obcfltLvl/override_signal'
 * '<S1174>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_t_obcTemp/override_signal'
 * '<S1175>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/Override/Ovrd_u_obcOutptVolt/override_signal'
 * '<S1176>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/convert/Enumerated Constant5'
 * '<S1177>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/convert/Subsystem'
 * '<S1178>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/convert/Subsystem2'
 * '<S1179>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/OBC_in/convert/obcSelfChk'
 * '<S1180>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert'
 * '<S1181>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/DFC_HYB_PEPSMsgErr'
 * '<S1182>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_b_PEPSMsgErrSet'
 * '<S1183>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_b_PEPS_RemoteControlSt'
 * '<S1184>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_b_pepsPduLvlVld'
 * '<S1185>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_st_pepsPduLvl'
 * '<S1186>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_st_pepsRKECom'
 * '<S1187>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Subsystem'
 * '<S1188>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Subsystem1'
 * '<S1189>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/DFC_HYB_PEPSMsgErr/debounce'
 * '<S1190>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/DFC_HYB_PEPSMsgErr/debounce/timed_debounce'
 * '<S1191>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_b_PEPSMsgErrSet/override_signal'
 * '<S1192>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_b_PEPS_RemoteControlSt/override_signal'
 * '<S1193>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_b_pepsPduLvlVld/override_signal'
 * '<S1194>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_st_pepsPduLvl/override_signal'
 * '<S1195>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Ovrd_st_pepsRKECom/override_signal'
 * '<S1196>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Subsystem/override_signal1'
 * '<S1197>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/PEPS_in/convert/Subsystem1/override_signal1'
 * '<S1198>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in'
 * '<S1199>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/SAS_in'
 * '<S1200>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/convert'
 * '<S1201>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsErrorCode'
 * '<S1202>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsFltLvl'
 * '<S1203>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsSelfChk'
 * '<S1204>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsSubFltLvl'
 * '<S1205>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsWrkSt'
 * '<S1206>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsErrorCode/override_signal'
 * '<S1207>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsFltLvl/override_signal'
 * '<S1208>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsSelfChk/override_signal'
 * '<S1209>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsSubFltLvl/override_signal'
 * '<S1210>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/EPS_in/Ovrd_st_epsWrkSt/override_signal'
 * '<S1211>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/SAS_in/Ovrd_st_epsEpasFail'
 * '<S1212>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/SAS_in/Ovrd_st_strWhlAng_rad'
 * '<S1213>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/SAS_in/Ovrd_st_epsEpasFail/override_signal'
 * '<S1214>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/SAS_in/Ovrd_st_strWhlAng_rad/override_signal'
 * '<S1215>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SAS_in/convert/epsSelfChk'
 * '<S1216>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem'
 * '<S1217>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem1'
 * '<S1218>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_b_rfrCarLocConfm'
 * '<S1219>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_b_rfrCarStation'
 * '<S1220>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_b_rfrSwapBatReq'
 * '<S1221>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_st_rfrConnctSts'
 * '<S1222>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_st_rfrSeed'
 * '<S1223>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_st_rfrSwapBatCod'
 * '<S1224>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_st_rfrSwapprocd'
 * '<S1225>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_b_rfrCarLocConfm/override_signal'
 * '<S1226>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_b_rfrCarStation/override_signal'
 * '<S1227>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_b_rfrSwapBatReq/override_signal'
 * '<S1228>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_st_rfrConnctSts/override_signal'
 * '<S1229>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_st_rfrSeed/override_signal'
 * '<S1230>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_st_rfrSwapBatCod/override_signal'
 * '<S1231>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/SWB_in/Function-Call Subsystem/Ovrd_st_rfrSwapprocd/override_signal'
 * '<S1232>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in'
 * '<S1233>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_b_tboxIntelChgCmd'
 * '<S1234>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_b_tboxPowOffCmd'
 * '<S1235>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_b_tboxPrtFullSwStUB'
 * '<S1236>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_el_tboxElevation'
 * '<S1237>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_m_McaVehWeight'
 * '<S1238>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_pct_tboxAlwChgCurrMax'
 * '<S1239>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_pct_tboxChgDepth'
 * '<S1240>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_McaCalNum'
 * '<S1241>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_McaOvrLoadInd '
 * '<S1242>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_TBOXFunAntiDismantleActive'
 * '<S1243>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_TBOXFunLockVehActive'
 * '<S1244>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_TBOXLockLimSet'
 * '<S1245>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_TBOXLockResultResp'
 * '<S1246>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_TBOXLockVehCtrl'
 * '<S1247>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_TBOXLockVehType'
 * '<S1248>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxChgLmtSw'
 * '<S1249>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxChgSftSwCtlSt'
 * '<S1250>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxInventorySpdLmtReq'
 * '<S1251>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxLife'
 * '<S1252>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxLockVehPerFlag'
 * '<S1253>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxPrtFullSwSt'
 * '<S1254>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxRsrChgSt'
 * '<S1255>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxSpdLmtLevelReq'
 * '<S1256>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxStartBattChgReq'
 * '<S1257>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_tboxVersionConversionFlag'
 * '<S1258>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxDay'
 * '<S1259>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxHr'
 * '<S1260>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxMins'
 * '<S1261>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxMth'
 * '<S1262>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxSec'
 * '<S1263>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxYr'
 * '<S1264>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_b_tboxIntelChgCmd/override_signal'
 * '<S1265>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_el_tboxElevation/override_signal'
 * '<S1266>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_m_McaVehWeight/override_signal'
 * '<S1267>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_McaCalNum/override_signal'
 * '<S1268>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_st_McaOvrLoadInd /override_signal'
 * '<S1269>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxDay/override_signal'
 * '<S1270>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxHr/override_signal'
 * '<S1271>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxMins/override_signal'
 * '<S1272>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxMth/override_signal'
 * '<S1273>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxSec/override_signal'
 * '<S1274>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TBOX_in/TBOX_in/Ovrd_t_tboxYr/override_signal'
 * '<S1275>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in'
 * '<S1276>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/convert'
 * '<S1277>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in/Ovrd_n_trsm2OutpShaftSpd'
 * '<S1278>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in/Ovrd_st_trsm2GearAct'
 * '<S1279>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in/Ovrd_st_trsm2GearShftReq'
 * '<S1280>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in/Ovrd_st_trsm2Unauthorized'
 * '<S1281>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in/Ovrd_n_trsm2OutpShaftSpd/override_signal'
 * '<S1282>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in/Ovrd_st_trsm2GearAct/override_signal'
 * '<S1283>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in/Ovrd_st_trsm2GearShftReq/override_signal'
 * '<S1284>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/TRA_in/Ovrd_st_trsm2Unauthorized/override_signal'
 * '<S1285>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/convert/Subsystem1'
 * '<S1286>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/TRA2_in/convert/Subsystem4'
 * '<S1287>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in'
 * '<S1288>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1'
 * '<S1289>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_a_yrsLongitAcce_mps2'
 * '<S1290>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_ehbABSFaild'
 * '<S1291>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_ehbIsaPtTrqDecReqActv'
 * '<S1292>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_ehbVehSpdInvld'
 * '<S1293>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_ehbVlcCddActv'
 * '<S1294>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_pdcBrkFlg'
 * '<S1295>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_pdcStsInfoCtrAlvCtrErr'
 * '<S1296>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_pdcStsInfoCtrCsmErr'
 * '<S1297>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBAebActv'
 * '<S1298>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBDtcActv'
 * '<S1299>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBMbRgnTgtWhlSts'
 * '<S1300>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBPtTrqDecReqActv'
 * '<S1301>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBPtTrqIncReqActv'
 * '<S1302>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBVlcActv'
 * '<S1303>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBVlcAvlb'
 * '<S1304>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBVlcPtTrqReqActv'
 * '<S1305>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_ehbBrkSysErrFlt'
 * '<S1306>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_ehbEPBDynAppSts'
 * '<S1307>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_ehbHHCActive'
 * '<S1308>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_ehbIsaSts'
 * '<S1309>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_vscAbsActv'
 * '<S1310>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_vscEHBAVHSts'
 * '<S1311>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_ehbIsaPtTrqDecReq_Nm'
 * '<S1312>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_vscEHBMbRgnTgtWhl'
 * '<S1313>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_vscEHBPtTrqDecReq'
 * '<S1314>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_vscEHBPtTrqIncReq'
 * '<S1315>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_vscEHBVlcPtTrqReq'
 * '<S1316>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_ehbVehSpd'
 * '<S1317>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_vscWhlFLSpd'
 * '<S1318>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_vscWhlFRSpd'
 * '<S1319>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_vscWhlRLSpd'
 * '<S1320>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_vscWhlRRSpd'
 * '<S1321>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_a_yrsLongitAcce_mps2/override_signal'
 * '<S1322>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_ehbABSFaild/override_signal'
 * '<S1323>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_ehbIsaPtTrqDecReqActv/override_signal'
 * '<S1324>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_ehbVehSpdInvld/override_signal'
 * '<S1325>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_ehbVlcCddActv/override_signal'
 * '<S1326>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_pdcBrkFlg/override_signal'
 * '<S1327>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_pdcStsInfoCtrAlvCtrErr/override_signal'
 * '<S1328>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_pdcStsInfoCtrCsmErr/override_signal'
 * '<S1329>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBAebActv/override_signal'
 * '<S1330>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBDtcActv/override_signal'
 * '<S1331>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBMbRgnTgtWhlSts/override_signal'
 * '<S1332>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBPtTrqDecReqActv/override_signal'
 * '<S1333>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBPtTrqIncReqActv/override_signal'
 * '<S1334>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBVlcActv/override_signal'
 * '<S1335>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBVlcAvlb/override_signal'
 * '<S1336>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_b_vscEHBVlcPtTrqReqActv/override_signal'
 * '<S1337>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_ehbBrkSysErrFlt/override_signal'
 * '<S1338>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_ehbEPBDynAppSts/override_signal'
 * '<S1339>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_ehbHHCActive/override_signal'
 * '<S1340>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_ehbIsaSts/override_signal'
 * '<S1341>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_vscAbsActv/override_signal'
 * '<S1342>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_st_vscEHBAVHSts/override_signal'
 * '<S1343>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_ehbIsaPtTrqDecReq_Nm/override_signal'
 * '<S1344>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_vscEHBMbRgnTgtWhl/override_signal'
 * '<S1345>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_vscEHBPtTrqDecReq/override_signal'
 * '<S1346>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_vscEHBPtTrqIncReq/override_signal'
 * '<S1347>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_tq_vscEHBVlcPtTrqReq/override_signal'
 * '<S1348>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_ehbVehSpd/override_signal'
 * '<S1349>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_vscWhlFLSpd/override_signal'
 * '<S1350>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_vscWhlFRSpd/override_signal'
 * '<S1351>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_vscWhlRLSpd/override_signal'
 * '<S1352>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/VSC_in/Ovrd_v_vscWhlRRSpd/override_signal'
 * '<S1353>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/Subsystem1'
 * '<S1354>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1'
 * '<S1355>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/Compare To Constant'
 * '<S1356>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/Compare To Constant1'
 * '<S1357>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/DFC_Ovrd1'
 * '<S1358>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/DFC_Ovrd2'
 * '<S1359>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/DFC_Ovrd7'
 * '<S1360>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/VehicleSpd_rpm2kph'
 * '<S1361>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/DFC_Ovrd1/override_signal'
 * '<S1362>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/DFC_Ovrd2/override_signal'
 * '<S1363>' : 'swc_VCIP/VCIP__VCU_Inputs_Processing/VIL__VCU_Input_Layer/VSC_in/convert1/VehicleSpeedProcess1/DFC_Ovrd7/override_signal'
 */
#endif                                 /* RTW_HEADER_swc_VCIP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
