/*
 * File: swc_TCOO.h
 *
 * Code generated for Simulink model 'swc_TCOO'.
 *
 * Model version                  : 6.575
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Sep 21 15:11:05 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_TCOO_h_
#define RTW_HEADER_swc_TCOO_h_
#ifndef swc_TCOO_COMMON_INCLUDES_
#define swc_TCOO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_TCOO.h"
#endif                                 /* swc_TCOO_COMMON_INCLUDES_ */

#include "Rte_Type.h"

/* Includes for objects with custom storage classes */
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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_SCAP_
#define DEFINED_TYPEDEF_FOR_vcsb_SCAP_

typedef struct {
  float32 tqld_tq_axle2MaxTq_Nm;
  float32 tqld_tq_axle2MinTq_Nm;
  float32 eadd_tq_mot2MaxLTTq_Nm;
  float32 tqld_tq_whlMax_Nm;
  float32 eadd_tq_mot2MaxSTTq_Nm;
  float32 tqld_tq_whlMin_Nm;
  float32 eadd_tq_mot2MinLTTq_Nm;
  float32 eadd_tq_mot2MinSTTq_Nm;
  boolean eadd_b_mot2TqOff;
  float32 ptld_pwr_hvbDischAvail_kW;
} vcsb_SCAP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_SCOO_
#define DEFINED_TYPEDEF_FOR_vcsb_SCOO_

typedef struct {
  float32 ccdd_tq_whlDemRawAdv_Nm;
  float32 ccdd_acc_vehAccTgt_mps2;
  boolean ccdd_b_accCtrlActv;
  float32 ccdd_acc_intAccTgt_mps2;
  CruiseSts_e ccdd_e_crsCtrlSts;
  float32 ccdd_v_crsCtrlTgtSpd_kph;
  CrModeMngr_e ccdd_e_crsCtrlSpdMode;
  CrsBtnSts ccdd_e_crsBtnSts;
  float32 ccdd_v_crsTgtSpdQuit_kph;
  float32 ccdd_tq_whlDem_Nm;
  boolean ccdd_b_crsCtrlAccPedlOvrd;
  CrsBtnErrSts ccdd_e_crsBtnErrSts;
  float32 ccdd_x_accPedlPosVirt_pct;
  boolean ctdd_b_clthCreepReq;
  float32 ctdd_tq_whlDem_Nm;
  boolean ctdd_b_eCreepReq;
  float32 ctdd_n_vehTgtCrpSpdFwd_kph;
  boolean vsld_b_vslTqIntvReq;
  float32 vsld_tq_whlMaxTqLimFast_Nm;
  float32 vsld_tq_whlMaxTqLimSlow_Nm;
  boolean esld_b_eslTqIntvReq;
  float32 esld_tq_crsMaxTqLimFast_Nm;
  float32 esld_tq_crsMaxTqLimSlow_Nm;
  boolean hhdd_b_hilHldEnab_flg;
  boolean escd_b_engSpdCtrlEnad;
  float32 escd_tq_crsEngSpdCtrlDmd_Nm;
  float32 escd_tq_crsEngSpdCtrlDmdSlow_Nm;
  float32 tscd_tq_tmmSpdCtrlTgt_Nm;
  boolean tscd_b_motSpdCtrlEnad;
  float32 vsld_v_vehMaxCfgSpd_kph;
  boolean ctdd_b_crpSlopeTrqOffsetEnHld;
  float32 ctdd_a_yrsLongAccAvgVld_mps2;
  float32 vsld_v_vehMaxSpd_kph;
} vcsb_SCOO;

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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_TCOO_
#define DEFINED_TYPEDEF_FOR_vcsb_TCOO_

typedef struct {
  uint8 dtdd_st_RegenLvlDisp;
  float32 dtdd_tq_whlDragDem_Nm;
  float32 apdd_tq_whlDem_Nm;
  float32 tdad_tq_whlDemUnfilt_Nm;
  float32 tdad_tq_whlDemUnlim_Nm;
  float32 msgd_tq_targetTqReq_Nm;
  float32 tdad_tq_whlDem_Nm;
  float32 eadd_tq_mot2TgtTqReq_Nm;
  float32 eadd_tq_mot2TgtTq_Nm;
  float32 tvrd_tq_mot2TgtTqReq_Nm;
  float32 dtdd_tq_whlCoastDrgDem_Nm;
  boolean tqdd_b_gpOvrd;
  boolean dtdd_b_drvPfmncDrgDec;
  boolean tqdd_b_ehbDisEnbCreep;
  float32 tqdd_x_accPedlPosVirt_pct;
  boolean tqdd_b_accPedlPosVirtVld;
  float32 dtdd_tq_whlCstDrgDemNoEhb_Nm;
  uint8 tqdd_st_ehbOvrdActv;
  uint8 tqdd_st_ehbOvrdTyp;
  uint8 tqdd_st_whlAcceSupprsn;
} vcsb_TCOO;

#endif

/* PublicStructure Variables for Internal Data, for system '<S79>/turnON_delay' */
typedef struct {
  float32 t_wait;                      /* '<S84>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S84>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S84>/timed_delay' */
} ARID_DEF_turnON_delay_swc_TCO_T;

/* PublicStructure Variables for Internal Data, for system '<S92>/Falling_Edge' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S98>/Unit Delay' */
} ARID_DEF_Falling_Edge_swc_TCO_T;

/* PublicStructure Variables for Internal Data, for system '<S87>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S128>/Unit Delay' */
} ARID_DEF_SR_latch_swc_TCOO_T;

/* PublicStructure Variables for Internal Data, for system '<S87>/turnOFF_delay' */
typedef struct {
  float32 t_wait;                      /* '<S130>/timed_delay' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S130>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S130>/timed_delay' */
} ARID_DEF_turnOFF_delay_swc_TC_T;

/* PublicStructure Variables for Internal Data, for system '<S335>/SwitchRampEADShiftIntvn' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S433>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S433>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S433>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S433>/Chart' */
} ARID_DEF_switch_ramp_swc_TCOO_T;

/* PublicStructure Variables for Internal Data, for system '<S332>/SwitchRampMot2RegenBrkLim' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S436>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S436>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S436>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S436>/Chart' */
} ARID_DEF_switch_ramp_swc_TC_m_T;

/* PublicStructure Variables for Internal Data, for system '<S9>/SwitchRampMot2TrqDem' */
typedef struct {
  uint8 is_c11_Ricardo_SW_dev_lib;     /* '<S442>/Chart' */
  uint8 is_U2_TO_U1;                   /* '<S442>/Chart' */
  uint8 is_U1_TO_U2;                   /* '<S442>/Chart' */
  uint8 is_active_c11_Ricardo_SW_dev_li;/* '<S442>/Chart' */
} ARID_DEF_switch_ramp_swc_TC_c_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_switch_ramp_swc_TC_c_T ARID_DEF_SwitchRampMot2TrqDem;/* '<S9>/SwitchRampMot2TrqDem' */
  ARID_DEF_SR_latch_swc_TCOO_T ARID_DEF_SR_latch1;/* '<S189>/SR_latch1' */
  ARID_DEF_SR_latch_swc_TCOO_T ARID_DEF_SR_latch;/* '<S175>/SR_latch' */
  ARID_DEF_switch_ramp_swc_TC_m_T ARID_DEF_SwitchRampMot2RegenBr;/* '<S332>/SwitchRampMot2RegenBrkLim' */
  ARID_DEF_switch_ramp_swc_TCOO_T ARID_DEF_SwitchRampEADShiftInt;/* '<S335>/SwitchRampEADShiftIntvn' */
  ARID_DEF_SR_latch_swc_TCOO_T ARID_DEF_SR_latch_m;/* '<S365>/SR_latch' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay4;/* '<S316>/turnON_delay4' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay3;/* '<S316>/turnON_delay3' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay2;/* '<S316>/turnON_delay2' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay1;/* '<S316>/turnON_delay1' */
  ARID_DEF_SR_latch_swc_TCOO_T ARID_DEF_SR_latch1_c;/* '<S316>/SR_latch1' */
  ARID_DEF_SR_latch_swc_TCOO_T ARID_DEF_SR_latch_k;/* '<S316>/SR_latch' */
  ARID_DEF_Falling_Edge_swc_TCO_T ARID_DEF_Falling_Edge2;/* '<S88>/Falling_Edge2' */
  ARID_DEF_Falling_Edge_swc_TCO_T ARID_DEF_Falling_Edge1;/* '<S88>/Falling_Edge1' */
  ARID_DEF_Falling_Edge_swc_TCO_T ARID_DEF_Falling_Edge;/* '<S88>/Falling_Edge' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay1_c;/* '<S87>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay;/* '<S87>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_TC_T ARID_DEF_turnOFF_delay1;/* '<S87>/turnOFF_delay1' */
  ARID_DEF_turnOFF_delay_swc_TC_T ARID_DEF_turnOFF_delay;/* '<S87>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_TCOO_T ARID_DEF_SR_latch1_b;/* '<S87>/SR_latch1' */
  ARID_DEF_SR_latch_swc_TCOO_T ARID_DEF_SR_latch_p;/* '<S87>/SR_latch' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay3_c;/* '<S86>/turnON_delay3' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay2_f;/* '<S86>/turnON_delay2' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay1_g;/* '<S86>/turnON_delay1' */
  ARID_DEF_Falling_Edge_swc_TCO_T ARID_DEF_Falling_Edge_g;/* '<S94>/Falling_Edge' */
  ARID_DEF_Falling_Edge_swc_TCO_T ARID_DEF_Falling_Edge_m;/* '<S93>/Falling_Edge' */
  ARID_DEF_Falling_Edge_swc_TCO_T ARID_DEF_Falling_Edge_n;/* '<S92>/Falling_Edge' */
  ARID_DEF_turnON_delay_swc_TCO_T ARID_DEF_turnON_delay_p;/* '<S79>/turnON_delay' */
  float64 DataTypeConversion12;        /* '<Root>/Data Type Conversion12' */
  float64 DataTypeConversion63;        /* '<Root>/Data Type Conversion63' */
  float64 DataTypeConversion175;       /* '<Root>/Data Type Conversion175' */
  float64 DataTypeConversion176;       /* '<Root>/Data Type Conversion176' */
  float64 DataTypeConversion185;       /* '<Root>/Data Type Conversion185' */
  float64 DataTypeConversion180;       /* '<Root>/Data Type Conversion180' */
  float64 DataTypeConversion182;       /* '<Root>/Data Type Conversion182' */
  float64 DataTypeConversion183;       /* '<Root>/Data Type Conversion183' */
  float64 DataTypeConversion15;        /* '<Root>/Data Type Conversion15' */
  float64 DataTypeConversion22;        /* '<Root>/Data Type Conversion22' */
  float64 DataTypeConversion37;        /* '<Root>/Data Type Conversion37' */
  float64 DataTypeConversion171;       /* '<Root>/Data Type Conversion171' */
  float64 DataTypeConversion190;       /* '<Root>/Data Type Conversion190' */
  float64 DataTypeConversion170;       /* '<Root>/Data Type Conversion170' */
  float64 DataTypeConversion45;        /* '<Root>/Data Type Conversion45' */
  float64 DataTypeConversion46;        /* '<Root>/Data Type Conversion46' */
  float64 DataTypeConversion197;       /* '<Root>/Data Type Conversion197' */
  float64 DataTypeConversion30;        /* '<Root>/Data Type Conversion30' */
  float64 DataTypeConversion187;       /* '<Root>/Data Type Conversion187' */
  float64 DataTypeConversion192;       /* '<Root>/Data Type Conversion192' */
  float64 DataTypeConversion193;       /* '<Root>/Data Type Conversion193' */
  float64 DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  float64 DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  float64 DataTypeConversion35;        /* '<Root>/Data Type Conversion35' */
  float64 DataTypeConversion39;        /* '<Root>/Data Type Conversion39' */
  float64 DelayInput1_DSTATE;          /* '<S162>/Delay Input1' */
  float64 DelayInput1_DSTATE_o;        /* '<S161>/Delay Input1' */
  float32 DataTypeConversion106;       /* '<Root>/Data Type Conversion106' */
  float32 DataTypeConversion11;        /* '<Root>/Data Type Conversion11' */
  float32 DataTypeConversion65;        /* '<Root>/Data Type Conversion65' */
  float32 DataTypeConversion78;        /* '<Root>/Data Type Conversion78' */
  float32 DataTypeConversion84;        /* '<Root>/Data Type Conversion84' */
  float32 DataTypeConversion26;        /* '<Root>/Data Type Conversion26' */
  float32 DataTypeConversion47;        /* '<Root>/Data Type Conversion47' */
  float32 DataTypeConversion177;       /* '<Root>/Data Type Conversion177' */
  float32 DataTypeConversion184;       /* '<Root>/Data Type Conversion184' */
  float32 DataTypeConversion188;       /* '<Root>/Data Type Conversion188' */
  float32 DataTypeConversion4;         /* '<Root>/Data Type Conversion4' */
  float32 DataTypeConversion54;        /* '<Root>/Data Type Conversion54' */
  float32 DataTypeConversion92;        /* '<Root>/Data Type Conversion92' */
  float32 DataTypeConversion91;        /* '<Root>/Data Type Conversion91' */
  float32 DataTypeConversion94;        /* '<Root>/Data Type Conversion94' */
  float32 DataTypeConversion95;        /* '<Root>/Data Type Conversion95' */
  float32 DataTypeConversion179;       /* '<Root>/Data Type Conversion179' */
  float32 DataTypeConversion25;        /* '<Root>/Data Type Conversion25' */
  float32 DataTypeConversion13;        /* '<Root>/Data Type Conversion13' */
  float32 DataTypeConversion21;        /* '<Root>/Data Type Conversion21' */
  float32 DataTypeConversion172;       /* '<Root>/Data Type Conversion172' */
  float32 DataTypeConversion189;       /* '<Root>/Data Type Conversion189' */
  float32 DataTypeConversion8;         /* '<Root>/Data Type Conversion8' */
  float32 DataTypeConversion33;        /* '<Root>/Data Type Conversion33' */
  float32 DataTypeConversion29;        /* '<Root>/Data Type Conversion29' */
  float32 y;                           /* '<S436>/Chart' */
  float32 y_b;                         /* '<S433>/Chart' */
  float32 DataTypeConversion;          /* '<S262>/Data Type Conversion' */
  float32 Sum3;                        /* '<S248>/Sum3' */
  float32 Product;                     /* '<S247>/Product' */
  float32 DataTypeConversion_d;        /* '<S239>/Data Type Conversion' */
  float32 UnitDelay3_DSTATE;           /* '<S188>/Unit Delay3' */
  float32 UnitDelay1_DSTATE_k;         /* '<S188>/Unit Delay1' */
  float32 UnitDelay2_DSTATE_d;         /* '<S188>/Unit Delay2' */
  float32 UnitDelay6_DSTATE;           /* '<S188>/Unit Delay6' */
  float32 UnitDelay4_DSTATE;           /* '<S188>/Unit Delay4' */
  float32 UnitDelay5_DSTATE;           /* '<S188>/Unit Delay5' */
  float32 UnitDelay_DSTATE;            /* '<S188>/Unit Delay' */
  float32 UnitDelay1_DSTATE_f;         /* '<S314>/UnitDelay1' */
  float32 UnitDelay4_DSTATE_b;         /* '<S220>/Unit Delay4' */
  float32 UnitDelay4_DSTATE_h;         /* '<S316>/Unit Delay4' */
  float32 UnitDelay1_DSTATE_i;         /* '<S315>/UnitDelay1' */
  float32 UnitDelay_DSTATE_n;          /* '<S261>/Unit Delay' */
  float32 UnitDelay_DSTATE_l;          /* '<S262>/Unit Delay' */
  float32 UnitDelay_DSTATE_h;          /* '<S239>/Unit Delay' */
  float32 time;                        /* '<S79>/CoastingDrgAutoModeKCal' */
  uint8 DataTypeConversion18;          /* '<Root>/Data Type Conversion18' */
  PmmStatus DataTypeConversion165;     /* '<Root>/Data Type Conversion165' */
  GearLeverPos DataTypeConversion36;   /* '<Root>/Data Type Conversion36' */
  DriveDir DataTypeConversion7;        /* '<Root>/Data Type Conversion7' */
  BrakePedalStatus DataTypeConversion167;/* '<Root>/Data Type Conversion167' */
  uint8 UnitDelay2_DSTATE_k;           /* '<S88>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_b;           /* '<S88>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_d4;          /* '<S116>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_eb;          /* '<S73>/Unit Delay2' */
  uint8 UnitDelay3_DSTATE_c;           /* '<S94>/Unit Delay3' */
  uint8 UnitDelay4_DSTATE_p;           /* '<S94>/Unit Delay4' */
  uint8 UnitDelay1_DSTATE_n;           /* '<S73>/Unit Delay1' */
  uint8 UnitDelay3_DSTATE_p;           /* '<S92>/Unit Delay3' */
  uint8 UnitDelay4_DSTATE_j;           /* '<S92>/Unit Delay4' */
  uint8 UnitDelay_DSTATE_b;            /* '<S73>/Unit Delay' */
  uint8 UnitDelay3_DSTATE_h;           /* '<S93>/Unit Delay3' */
  uint8 UnitDelay4_DSTATE_pd;          /* '<S93>/Unit Delay4' */
  uint8 UnitDelay2_DSTATE_i;           /* '<S145>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_o;           /* '<S144>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_em;          /* '<S140>/Unit Delay2' */
  uint8 is_c2_tda;                     /* '<S223>/TorqueRange' */
  uint8 is_PEDAL_TIP_OUT;              /* '<S223>/TorqueRange' */
  uint8 is_PEDAL_TIP_IN;               /* '<S223>/TorqueRange' */
  uint8 is_active_c2_tda;              /* '<S223>/TorqueRange' */
  uint8 is_c3_swc_TCOO;                /* '<S79>/CoastingDrgAutoModeKCal' */
  uint8 is_active_c3_swc_TCOO;         /* '<S79>/CoastingDrgAutoModeKCal' */
  boolean Delay_DSTATE[100];           /* '<S189>/Delay' */
  boolean DataTypeConversion1;         /* '<Root>/Data Type Conversion1' */
  boolean DataTypeConversion23;        /* '<Root>/Data Type Conversion23' */
  boolean DataTypeConversion181;       /* '<Root>/Data Type Conversion181' */
  boolean Compare;                     /* '<S3>/Compare' */
  boolean DataTypeConversion14;        /* '<Root>/Data Type Conversion14' */
  boolean DataTypeConversion27;        /* '<Root>/Data Type Conversion27' */
  boolean DataTypeConversion160;       /* '<Root>/Data Type Conversion160' */
  boolean DataTypeConversion5;         /* '<Root>/Data Type Conversion5' */
  boolean DataTypeConversion6;         /* '<Root>/Data Type Conversion6' */
  boolean DataTypeConversion17;        /* '<Root>/Data Type Conversion17' */
  boolean DataTypeConversion31;        /* '<Root>/Data Type Conversion31' */
  boolean DataTypeConversion164;       /* '<Root>/Data Type Conversion164' */
  boolean DataTypeConversion195;       /* '<Root>/Data Type Conversion195' */
  boolean DataTypeConversion34;        /* '<Root>/Data Type Conversion34' */
  boolean tqdd_b_ehbVlcCtlDrvTqEnb;    /* '<S364>/Logical Operator24' */
  boolean LogicalOperator48;           /* '<S365>/Logical Operator48' */
  boolean DelayInput1_DSTATE_h;        /* '<S441>/Delay Input1' */
  boolean UnitDelay_DSTATE_g;          /* '<S175>/Unit Delay' */
  boolean DelayInput1_DSTATE_i;        /* '<S231>/Delay Input1' */
  boolean DelayInput1_DSTATE_f;        /* '<S240>/Delay Input1' */
  boolean DelayInput1_DSTATE_n;        /* '<S241>/Delay Input1' */
  boolean DelayInput1_DSTATE_k;        /* '<S258>/Delay Input1' */
  boolean init_DSTATE;                 /* '<S15>/init' */
  boolean DelayInput1_DSTATE_nh;       /* '<S118>/Delay Input1' */
  boolean DelayInput1_DSTATE_n1;       /* '<S123>/Delay Input1' */
  boolean DelayInput1_DSTATE_d;        /* '<S117>/Delay Input1' */
  boolean DelayInput1_DSTATE_dr;       /* '<S120>/Delay Input1' */
  boolean DelayInput1_DSTATE_ie;       /* '<S119>/Delay Input1' */
  boolean UnitDelay3_DSTATE_o;         /* '<S86>/Unit Delay3' */
  boolean DelayInput1_DSTATE_iv;       /* '<S122>/Delay Input1' */
  boolean DelayInput1_DSTATE_hb;       /* '<S121>/Delay Input1' */
  boolean UnitDelay2_DSTATE_kd;        /* '<S86>/Unit Delay2' */
  boolean UnitDelay1_DSTATE_o;         /* '<S86>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_n;         /* '<S145>/Unit Delay3' */
  boolean UnitDelay1_DSTATE_ol;        /* '<S145>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_j;         /* '<S144>/Unit Delay3' */
  boolean UnitDelay1_DSTATE_l;         /* '<S144>/Unit Delay1' */
  boolean UnitDelay3_DSTATE_l;         /* '<S140>/Unit Delay3' */
  boolean UnitDelay1_DSTATE_o4;        /* '<S140>/Unit Delay1' */
  boolean Relay_Mode;                  /* '<S332>/Relay' */
  boolean Relay1_Mode;                 /* '<S332>/Relay1' */
  boolean Relay2_Mode;                 /* '<S365>/Relay2' */
  boolean Relay1_Mode_j;               /* '<S365>/Relay1' */
  boolean Relay3_Mode;                 /* '<S365>/Relay3' */
  boolean Relay_Mode_o;                /* '<S11>/Relay' */
  boolean Relay_Mode_i;                /* '<S78>/Relay' */
  boolean Relay1_Mode_a;               /* '<S79>/Relay1' */
  boolean Relay_Mode_c;                /* '<S79>/Relay' */
  boolean Relay2_Mode_n;               /* '<S87>/Relay2' */
  boolean Relay1_Mode_f;               /* '<S75>/Relay1' */
  boolean Relay2_Mode_m;               /* '<S75>/Relay2' */
  boolean Filter_MODE;                 /* '<S228>/Filter' */
  boolean Filter_MODE_c;               /* '<S226>/Filter' */
  boolean SptRegenLvlCalc_MODE;        /* '<S88>/SptRegenLvlCalc' */
  boolean NormalRegenLvlCalc_MODE;     /* '<S88>/NormalRegenLvlCalc' */
  boolean EcoRegenLvlCalc_MODE;        /* '<S88>/EcoRegenLvlCalc' */
} ARID_DEF_swc_TCOO_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S27>/2-D Lookup Table'
   *   '<S28>/2-D Lookup Table'
   *   '<S28>/2-D Lookup Table1'
   *   '<S42>/2-D Lookup Table'
   *   '<S43>/2-D Lookup Table'
   *   '<S43>/2-D Lookup Table1'
   *   '<S57>/2-D Lookup Table'
   *   '<S58>/2-D Lookup Table'
   *   '<S58>/2-D Lookup Table1'
   *   '<S33>/2-D Lookup Table'
   *   '<S34>/2-D Lookup Table1'
   *   '<S35>/2-D Lookup Table'
   *   '<S36>/2-D Lookup Table1'
   *   '<S37>/2-D Lookup Table'
   *   '<S38>/2-D Lookup Table1'
   *   '<S48>/2-D Lookup Table'
   *   '<S49>/2-D Lookup Table1'
   *   '<S50>/2-D Lookup Table'
   *   '<S51>/2-D Lookup Table1'
   *   '<S52>/2-D Lookup Table'
   *   '<S53>/2-D Lookup Table1'
   *   '<S63>/2-D Lookup Table'
   *   '<S64>/2-D Lookup Table1'
   *   '<S65>/2-D Lookup Table'
   *   '<S66>/2-D Lookup Table1'
   *   '<S67>/2-D Lookup Table'
   *   '<S68>/2-D Lookup Table1'
   */
  uint32 pooled13[2];

  /* Computed Parameter: uDLookupTable4_maxIndex
   * Referenced by: '<S366>/2-D Lookup Table4'
   */
  uint32 uDLookupTable4_maxIndex[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S188>/2-D Lookup Table'
   *   '<S188>/2-D Lookup Table1'
   *   '<S188>/2-D Lookup Table10'
   *   '<S188>/2-D Lookup Table11'
   *   '<S188>/2-D Lookup Table2'
   *   '<S188>/2-D Lookup Table3'
   *   '<S188>/2-D Lookup Table4'
   *   '<S188>/2-D Lookup Table5'
   *   '<S188>/2-D Lookup Table6'
   *   '<S188>/2-D Lookup Table7'
   *   '<S188>/2-D Lookup Table8'
   *   '<S188>/2-D Lookup Table9'
   *   '<S284>/2-D Lookup Table3'
   *   '<S285>/2-D Lookup Table4'
   *   '<S286>/2-D Lookup Table1'
   *   '<S287>/2-D Lookup Table2'
   *   '<S288>/2-D Lookup Table3'
   *   '<S289>/2-D Lookup Table4'
   *   '<S290>/2-D Lookup Table1'
   *   '<S291>/2-D Lookup Table2'
   *   '<S292>/2-D Lookup Table3'
   *   '<S293>/2-D Lookup Table4'
   *   '<S294>/2-D Lookup Table1'
   *   '<S295>/2-D Lookup Table2'
   *   '<S310>/2-D Lookup Table3'
   *   '<S310>/2-D Lookup Table7'
   *   '<S311>/2-D Lookup Table4'
   *   '<S311>/2-D Lookup Table8'
   *   '<S312>/2-D Lookup Table1'
   *   '<S312>/2-D Lookup Table5'
   *   '<S313>/2-D Lookup Table2'
   *   '<S313>/2-D Lookup Table6'
   */
  uint32 pooled14[2];
} ConstP_swc_TCOO_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_TCOO_T swc_TCOO_ARID_DEF;

/* Constant parameters (default storage) */
extern const ConstP_swc_TCOO_T swc_TCOO_ConstP;

/* Exported data declaration */
#define swc_TCOO_START_SEC_CONST_VOLATILE
#include "swc_TCOO_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile float32 apda_trqDemGearD_Y_EngSpd_rpm[12];/* Referenced by:
                                                                 * '<S34>/2-D Lookup Table1'
                                                                 * '<S35>/2-D Lookup Table'
                                                                 * '<S36>/2-D Lookup Table1'
                                                                 * '<S49>/2-D Lookup Table1'
                                                                 * '<S51>/2-D Lookup Table1'
                                                                 * '<S64>/2-D Lookup Table1'
                                                                 * '<S66>/2-D Lookup Table1'
                                                                 */

/* Driver Pedal Map in Gear D - Vehicle Speed Axis */
extern const volatile float32 apda_trqDemGearE_Y_EngSpd_rpm[12];
                                   /* Referenced by: '<S33>/2-D Lookup Table' */
extern const volatile float32 apda_trqDemGearS_Y_EngSpd_rpm[12];/* Referenced by:
                                                                 * '<S37>/2-D Lookup Table'
                                                                 * '<S38>/2-D Lookup Table1'
                                                                 * '<S53>/2-D Lookup Table1'
                                                                 * '<S68>/2-D Lookup Table1'
                                                                 */

/* Driver Pedal Map in Gear S - Vehicle Speed Axis */
extern const volatile boolean apdc_b_trsmGearTgt_ovrdflg;
                         /* Referenced by: '<S69>/apdc_b_trsmGearTgt_ovrdflg' */

/* Override flag for apdd_st_trsmGearTgt */
extern const volatile boolean apdc_b_useSportMapsIn4WDMode;/* Referenced by:
                                                            * '<S21>/Constant17'
                                                            * '<S22>/Constant17'
                                                            * '<S23>/Constant17'
                                                            */

/* Use Sport Pedal Maps in 4WD Mode */
extern const volatile float32 apdc_frac_pedalDeadBandHigh_pct;/* Referenced by: '<S11>/Relay' */

/* Pedal dead band high threshold */
extern const volatile float32 apdc_frac_pedalDeadBandLow_pct;/* Referenced by: '<S11>/Relay' */

/* Pedal dead band low threshold */
extern const volatile sint8 apdc_st_trsmGearTgt_ovrdval;
                        /* Referenced by: '<S69>/apdc_st_trsmGearTgt_ovrdval' */

/* Override value for apdd_st_trsmGearTgt */
extern const volatile float32 apdc_tm_engMdlActSpdFilter_s;/* Referenced by: '<S10>/Constant17' */

/* Engine Modeled Actual Speed Time constant filter */
extern const volatile float32 apdm_trqDemGearD1_X_PedPos_pct[11];/* Referenced by:
                                                                  * '<S35>/2-D Lookup Table'
                                                                  * '<S50>/2-D Lookup Table'
                                                                  * '<S65>/2-D Lookup Table'
                                                                  */

/* Driver Pedal Map in Gear D1 - Pedal Position Axis */
extern const volatile float32 apdm_trqDemGearD1_Z_Nm[132];
                                   /* Referenced by: '<S35>/2-D Lookup Table' */

/* Driver Pedal Map in Gear D1 - Torque Demand */
extern const volatile float32 apdm_trqDemGearD2_X_PedPos_pct[11];/* Referenced by:
                                                                  * '<S34>/2-D Lookup Table1'
                                                                  * '<S36>/2-D Lookup Table1'
                                                                  * '<S49>/2-D Lookup Table1'
                                                                  * '<S51>/2-D Lookup Table1'
                                                                  * '<S64>/2-D Lookup Table1'
                                                                  * '<S66>/2-D Lookup Table1'
                                                                  */

/* Driver Pedal Map in Gear D2 - Pedal Position Axis */
extern const volatile float32 apdm_trqDemGearD2_Z_Nm[132];/* Referenced by:
                                                           * '<S34>/2-D Lookup Table1'
                                                           * '<S36>/2-D Lookup Table1'
                                                           * '<S49>/2-D Lookup Table1'
                                                           * '<S51>/2-D Lookup Table1'
                                                           * '<S64>/2-D Lookup Table1'
                                                           * '<S66>/2-D Lookup Table1'
                                                           */

/* Driver Pedal Map in Gear D2 - Torque Demand */
extern const volatile float32 apdm_trqDemGearE1_X_PedPos_pct[11];/* Referenced by:
                                                                  * '<S33>/2-D Lookup Table'
                                                                  * '<S48>/2-D Lookup Table'
                                                                  * '<S63>/2-D Lookup Table'
                                                                  */
extern const volatile float32 apdm_trqDemGearE1_Z_Nm[132];
                                   /* Referenced by: '<S33>/2-D Lookup Table' */
extern const volatile float32 apdm_trqDemGearN_X_PedPos_pct[11];/* Referenced by:
                                                                 * '<S27>/2-D Lookup Table'
                                                                 * '<S42>/2-D Lookup Table'
                                                                 * '<S57>/2-D Lookup Table'
                                                                 */

/* Driver Pedal Map in Gear N - Pedal Position Axis */
extern const volatile float32 apdm_trqDemGearN_Y_EngSpd_rpm[12];/* Referenced by:
                                                                 * '<S27>/2-D Lookup Table'
                                                                 * '<S42>/2-D Lookup Table'
                                                                 * '<S57>/2-D Lookup Table'
                                                                 */

/* Driver Pedal Map in Gear N - Vehicle Speed Axis */
extern const volatile float32 apdm_trqDemGearN_Z_Nm[132];
                                   /* Referenced by: '<S27>/2-D Lookup Table' */

/* Driver Pedal Map in Gear N - Torque Demand */
extern const volatile float32 apdm_trqDemGearR_X_PedPos_pct[11];/* Referenced by:
                                                                 * '<S28>/2-D Lookup Table'
                                                                 * '<S28>/2-D Lookup Table1'
                                                                 * '<S43>/2-D Lookup Table'
                                                                 * '<S43>/2-D Lookup Table1'
                                                                 * '<S58>/2-D Lookup Table'
                                                                 * '<S58>/2-D Lookup Table1'
                                                                 */

/* Driver Pedal Map in Gear R - Pedal Position Axis */
extern const volatile float32 apdm_trqDemGearR_Y_EngSpd_rpm[12];/* Referenced by:
                                                                 * '<S28>/2-D Lookup Table'
                                                                 * '<S28>/2-D Lookup Table1'
                                                                 * '<S43>/2-D Lookup Table'
                                                                 * '<S43>/2-D Lookup Table1'
                                                                 * '<S58>/2-D Lookup Table'
                                                                 * '<S58>/2-D Lookup Table1'
                                                                 */

/* Driver Pedal Map in Gear R - Vehicle Speed Axis */
extern const volatile float32 apdm_trqDemGearR_Z_Nm[132];
                                   /* Referenced by: '<S28>/2-D Lookup Table' */

/* Driver Pedal Map in Gear R - Torque Demand */
extern const volatile float32 apdm_trqDemGearS1_X_PedPos_pct[11];/* Referenced by:
                                                                  * '<S37>/2-D Lookup Table'
                                                                  * '<S52>/2-D Lookup Table'
                                                                  * '<S67>/2-D Lookup Table'
                                                                  */

/* Driver Pedal Map in Gear S1 - Pedal Position Axis */
extern const volatile float32 apdm_trqDemGearS1_Z_Nm[132];
                                   /* Referenced by: '<S37>/2-D Lookup Table' */

/* Driver Pedal Map in Gear S1 - Torque Demand */
extern const volatile float32 apdm_trqDemGearS2_X_PedPos_pct[11];/* Referenced by:
                                                                  * '<S38>/2-D Lookup Table1'
                                                                  * '<S53>/2-D Lookup Table1'
                                                                  * '<S68>/2-D Lookup Table1'
                                                                  */

/* Driver Pedal Map in Gear S2 - Pedal Position Axis */
extern const volatile float32 apdm_trqDemGearS2_Z_Nm[132];/* Referenced by:
                                                           * '<S38>/2-D Lookup Table1'
                                                           * '<S53>/2-D Lookup Table1'
                                                           * '<S68>/2-D Lookup Table1'
                                                           */

/* Driver Pedal Map in Gear S2 - Torque Demand */
extern const volatile float32 dtda_regBrkTrqDerate_X_VehSpd_kph[10];
                                  /* Referenced by: '<S71>/1-D Lookup Table2' */

/* Brake Drag Torque Demand Derate X Axle - Vehicle Speed */
extern const volatile float32 dtda_regBrkTrqMap_X_BrkPres_bar[8];
                                   /* Referenced by: '<S71>/1-D Lookup Table' */

/* Regenerative Braking Map - Brake Pressure Axis */
extern const volatile float32 dtda_trqDragDemEV_Y_VehSpd_kph[27];/* Referenced by:
                                                                  * '<S75>/1-D Lookup Table3'
                                                                  * '<S78>/1-D Lookup Table'
                                                                  * '<S78>/1-D Lookup Table3'
                                                                  * '<S78>/1-D Lookup Table5'
                                                                  * '<S78>/1-D Lookup Table6'
                                                                  */

/* Drag Torque Demand Map EV Mode - Vehicle Speed Axis */
extern const volatile uint8 dtdc_ECODefaultRegLvl;/* Referenced by: '<S86>/Constant22' */
extern const volatile uint8 dtdc_EEPDefaultRegLvl;/* Referenced by:
                                                   * '<S86>/Constant1'
                                                   * '<S86>/Constant2'
                                                   * '<S86>/Constant4'
                                                   */
extern const volatile uint8 dtdc_EEPDefaultRegLvl1;/* Referenced by:
                                                    * '<S86>/Constant19'
                                                    * '<S86>/Constant30'
                                                    * '<S86>/Constant6'
                                                    */
extern const volatile uint8 dtdc_EEPDefaultRegLvl2;/* Referenced by:
                                                    * '<S86>/Constant20'
                                                    * '<S86>/Constant31'
                                                    * '<S86>/Constant7'
                                                    */
extern const volatile uint8 dtdc_EEPDefaultRegLvl3;/* Referenced by:
                                                    * '<S86>/Constant21'
                                                    * '<S86>/Constant32'
                                                    * '<S86>/Constant8'
                                                    */
extern const volatile float32 dtdc_EEPUpdDelay_s;/* Referenced by:
                                                  * '<S86>/Constant13'
                                                  * '<S86>/Constant36'
                                                  * '<S86>/Constant38'
                                                  * '<S87>/Constant15'
                                                  * '<S87>/Constant4'
                                                  */
extern const volatile uint8 dtdc_MaxCounterValue;/* Referenced by:
                                                  * '<S88>/Constant2'
                                                  * '<S88>/Constant3'
                                                  * '<S88>/Constant35'
                                                  */
extern const volatile uint8 dtdc_NormalDefaultRegLvl;/* Referenced by: '<S86>/Constant18' */
extern const volatile boolean dtdc_b_noUseGearLeverPos;/* Referenced by: '<S87>/Constant1' */
extern const volatile boolean dtdc_b_useIncEdgeCount;/* Referenced by: '<S89>/Constant4' */
extern const volatile boolean dtdc_b_useRgnOffEna;/* Referenced by: '<S87>/Constant12' */
extern const volatile boolean dtdc_b_useS2CstDrgTqOvrSpd;/* Referenced by: '<S75>/Constant7' */
extern const volatile boolean dtdc_b_useSportMapsIn4WDMode;/* Referenced by: '<S87>/Constant17' */

/* Use Sport Drag Maps in 4WD Mode */
extern const volatile uint8 dtdc_cnt_rgnOffEnaCount;/* Referenced by: '<S87>/Constant13' */
extern const volatile float32 dtdc_frac_rgnOffAccPdl_pct;/* Referenced by: '<S87>/Constant11' */
extern const volatile float32 dtdc_p_brkPresHighThd_bar;/* Referenced by: '<S78>/Relay' */
extern const volatile float32 dtdc_p_brkPresLowThd_bar;/* Referenced by: '<S78>/Relay' */
extern const volatile float32 dtdc_t_IgonInitTime_s;/* Referenced by:
                                                     * '<S87>/Constant6'
                                                     * '<S87>/Constant7'
                                                     */
extern const volatile boolean dtdc_useLvl123Ena;/* Referenced by:
                                                 * '<S86>/Constant12'
                                                 * '<S86>/Constant34'
                                                 * '<S86>/Constant9'
                                                 */
extern const volatile float32 dtdf_regBrkTrqDerate_Y_fact[10];
                                  /* Referenced by: '<S71>/1-D Lookup Table2' */

/* Brake Drag Torque Demand Derate Y Axle - factor */
extern const volatile float32 dtdf_regBrkTrqEVMap_Y_Nm[8];
                                   /* Referenced by: '<S71>/1-D Lookup Table' */

/* Regenerative Braking Map EV Mode - Torque Demand */
extern const volatile float32 dtdm_trqDragDemEVOffs1_Z_Nm[27];
                                  /* Referenced by: '<S78>/1-D Lookup Table5' */

/* Drag Torque Demand Offset1 Map EV Mode - Torque Demand */
extern const volatile float32 dtdm_trqDragDemEVOffs2_Z_Nm[27];/* Referenced by:
                                                               * '<S75>/1-D Lookup Table3'
                                                               * '<S78>/1-D Lookup Table3'
                                                               */

/* Drag Torque Demand Offset2 Map EV Mode - Torque Demand */
extern const volatile float32 dtdm_trqDragDemEVOffs3_Z_Nm[27];
                                  /* Referenced by: '<S78>/1-D Lookup Table6' */

/* Drag Torque Demand Offset3 Map EV Mode - Torque Demand */
extern const volatile float32 dtdm_trqDragDemEV_Z_Nm[27];
                                   /* Referenced by: '<S78>/1-D Lookup Table' */

/* Drag Torque Demand Map EV Mode - Torque Demand */
extern const volatile float32 eada_mot2ZeroCross_X_VehSpd_kph[6];/* Referenced by:
                                                                  * '<S188>/2-D Lookup Table'
                                                                  * '<S188>/2-D Lookup Table1'
                                                                  * '<S188>/2-D Lookup Table6'
                                                                  * '<S188>/2-D Lookup Table7'
                                                                  * '<S188>/2-D Lookup Table8'
                                                                  * '<S188>/2-D Lookup Table9'
                                                                  */

/* Motor zero-crossing filter gradient map - Vehicle Speed Axis */
extern const volatile float32 eada_mot2ZeroCross_Y_MotTrq_Nm[11];/* Referenced by:
                                                                  * '<S188>/2-D Lookup Table'
                                                                  * '<S188>/2-D Lookup Table1'
                                                                  * '<S188>/2-D Lookup Table6'
                                                                  * '<S188>/2-D Lookup Table7'
                                                                  * '<S188>/2-D Lookup Table8'
                                                                  * '<S188>/2-D Lookup Table9'
                                                                  */

/* Motor zero-crossing filter gradient map - motor torque Axis */
extern const volatile float32 eada_mot2ZroCrsAcceLmt_X_VehSpd_kph[6];/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table10'
                                                                      * '<S188>/2-D Lookup Table11'
                                                                      */
extern const volatile float32 eada_mot2ZroCrsAcceLmt_Y_MotTrq_Nm[11];/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table10'
                                                                      * '<S188>/2-D Lookup Table11'
                                                                      */
extern const volatile float32 eadc_a_acceSuprsnEnSlpeHi_mps2;/* Referenced by: '<S189>/Constant11' */
extern const volatile boolean eadc_b_disMot2ZeroCrossDurESP;/* Referenced by: '<S188>/Constant1' */

/* Disable motor zero-crossing filter during the ESP intervention */
extern const volatile boolean eadc_b_enAcceSuprsn;/* Referenced by: '<S189>/Constant9' */
extern const volatile boolean eadc_b_enaMot2ZeroCrossRamp;/* Referenced by: '<S188>/Constant10' */

/* Enable motor zero-crossing filter */
extern const volatile boolean eadc_b_enbEad2TqOvrd;/* Referenced by: '<S177>/Constant6' */
extern const volatile boolean eadc_b_useForceTqBrkGearR;/* Referenced by: '<S175>/Constant5' */
extern const volatile boolean eadc_b_useGearR2NTqDirSwt;/* Referenced by:
                                                         * '<S175>/Constant6'
                                                         * '<S175>/Constant8'
                                                         */
extern const volatile float32 eadc_tq_ead2TqOvrdVal_Nm;/* Referenced by: '<S177>/Constant7' */
extern const volatile float32 eadc_tq_mot2FrcDrvTqDirR_Nm;/* Referenced by: '<S175>/Constant' */

/* Drive Direction R Motor2 Force Torque */
extern const volatile float32 eadc_v_acceSuprsnEnVehSpd_kph;/* Referenced by: '<S189>/Constant14' */
extern const volatile float32 eadc_v_acceSuprsnQutVehSpd_kph;/* Referenced by:
                                                              * '<S189>/Constant6'
                                                              * '<S189>/Constant7'
                                                              */
extern const volatile float32 eadc_x_accPdlRate_pctps;/* Referenced by: '<S189>/Constant5' */
extern const volatile float32 eadc_x_acceSuprsnAccPdlHi_pct;/* Referenced by:
                                                             * '<S189>/Constant2'
                                                             * '<S189>/Constant3'
                                                             * '<S189>/Constant8'
                                                             */
extern const volatile float32 eadc_x_acceSuprsnAccPdlLo_pct;/* Referenced by:
                                                             * '<S189>/Constant1'
                                                             * '<S189>/Constant4'
                                                             */
extern const volatile float32 eadm_mot2ZeroCrossDec_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table1' */

/* Motor zero-crossing filter negative gradient map */
extern const volatile float32 eadm_mot2ZeroCrossInc_Z_Nmps[66];
                                  /* Referenced by: '<S188>/2-D Lookup Table' */

/* Motor zero-crossing filter positive gradient map */
extern const volatile float32 eadm_mot2ZroCrsDecAcceLmt_Z_Nmps[66];
                                /* Referenced by: '<S188>/2-D Lookup Table11' */
extern const volatile float32 eadm_mot2ZroCrsIncAcceLmt_Z_Nmps[66];
                                /* Referenced by: '<S188>/2-D Lookup Table10' */
extern const volatile float32 swctcoo_apda_trqDemGearDVehTyp1_Y_EngSpd_rpm[12];
                                   /* Referenced by: '<S50>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apda_trqDemGearDVehTyp2_Y_EngSpd_rpm[12];
                                   /* Referenced by: '<S65>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apda_trqDemGearEVehTyp1_Y_EngSpd_rpm[12];
                                   /* Referenced by: '<S48>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apda_trqDemGearEVehTyp2_Y_EngSpd_rpm[12];
                                   /* Referenced by: '<S63>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apda_trqDemGearSVehTyp1_Y_EngSpd_rpm[12];
                                   /* Referenced by: '<S52>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apda_trqDemGearSVehTyp2_Y_EngSpd_rpm[12];
                                   /* Referenced by: '<S67>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearD1VehTyp1_Z_Nm[132];
                                   /* Referenced by: '<S50>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearD1VehTyp2_Z_Nm[132];
                                   /* Referenced by: '<S65>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearE1VehTyp1_Z_Nm[132];
                                   /* Referenced by: '<S48>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearE1VehTyp2_Z_Nm[132];
                                   /* Referenced by: '<S63>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearNVehTyp1_Z_Nm[132];
                                   /* Referenced by: '<S42>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearNVehTyp2_Z_Nm[132];
                                   /* Referenced by: '<S57>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearRVehTyp1_Z_Nm[132];
                                   /* Referenced by: '<S43>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearRVehTyp2_Z_Nm[132];
                                   /* Referenced by: '<S58>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearS1VehTyp1_Z_Nm[132];
                                   /* Referenced by: '<S52>/2-D Lookup Table' */
extern const volatile float32 swctcoo_apdm_trqDemGearS1VehTyp2_Z_Nm[132];
                                   /* Referenced by: '<S67>/2-D Lookup Table' */
extern const volatile uint8 swctcoo_dtdc_SptDefaultRegLvl;/* Referenced by: '<S86>/Constant5' */
extern const volatile boolean swctcoo_dtdc_b_ehbOvrCtlWhlDrgPmt;/* Referenced by: '<S75>/Constant12' */
extern const volatile boolean swctcoo_dtdc_b_useFctCfgEHB;/* Referenced by: '<S75>/Constant3' */
extern const volatile boolean swctcoo_dtdc_b_whlDrgDemEhb_ovrdflg;/* Referenced by: '<S75>/Constant4' */
extern const volatile float32 swctcoo_dtdc_frac_hvbSocDrgDecHigh_pct;/* Referenced by: '<S87>/Relay2' */
extern const volatile float32 swctcoo_dtdc_frac_hvbSocDrgDecLow_pct;/* Referenced by: '<S87>/Relay2' */
extern const volatile float32 swctcoo_dtdc_frac_pedCoastOffHigh_pct;/* Referenced by: '<S75>/Relay1' */
extern const volatile float32 swctcoo_dtdc_frac_pedCoastOffLow_pct;/* Referenced by: '<S75>/Relay1' */
extern const volatile float32 swctcoo_dtdc_tq_whlDrgDemEhb_ovrdval;/* Referenced by: '<S75>/Constant5' */
extern const volatile float32 swctcoo_dtdc_v_vSpdCrbsOnHigh_kph;/* Referenced by: '<S75>/Relay2' */
extern const volatile float32 swctcoo_dtdc_v_vSpdCrbsOnLow_kph;/* Referenced by: '<S75>/Relay2' */
extern const volatile float32 swctcoo_dtdf_brkTqMinMapEHB_X_VehSpd_kph[12];
                                  /* Referenced by: '<S75>/1-D Lookup Table1' */
extern const volatile float32 swctcoo_dtdf_brkTqMinMapEHB_Y_Nm[12];
                                  /* Referenced by: '<S75>/1-D Lookup Table1' */

/* Braking Min Torque Map - Torque Limit */
extern const volatile float32 swctcoo_dtdf_brkTqMinMap_X_VehSpd_kph[12];
                                  /* Referenced by: '<S75>/1-D Lookup Table2' */

/* Braking Min Torque Map - Vehicle Speed Axis */
extern const volatile float32 swctcoo_dtdf_brkTqMinMap_Y_Nm[12];
                                  /* Referenced by: '<S75>/1-D Lookup Table2' */

/* Braking Min Torque Map - Torque Limit */
extern const volatile float32 swctcoo_eada_mot2ZroCrsAdc_X_VehSpd_kph[6];/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table4'
                                                                      * '<S188>/2-D Lookup Table5'
                                                                      */
extern const volatile float32 swctcoo_eada_mot2ZroCrsAdc_Y_MotTrq_Nm[11];/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table4'
                                                                      * '<S188>/2-D Lookup Table5'
                                                                      */
extern const volatile float32 swctcoo_eada_mot2ZroCrsEhb_X_VehSpd_kph[6];/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table2'
                                                                      * '<S188>/2-D Lookup Table3'
                                                                      */
extern const volatile float32 swctcoo_eada_mot2ZroCrsEhb_Y_MotTrq_Nm[11];/* Referenced by:
                                                                      * '<S188>/2-D Lookup Table2'
                                                                      * '<S188>/2-D Lookup Table3'
                                                                      */
extern const volatile boolean swctcoo_eadc_b_enaAdcFild;/* Referenced by: '<S188>/Constant5' */
extern const volatile boolean swctcoo_eadc_b_enaCtlFild;/* Referenced by:
                                                         * '<S188>/Constant13'
                                                         * '<S188>/Constant15'
                                                         * '<S188>/Constant16'
                                                         * '<S188>/Constant17'
                                                         * '<S188>/Constant18'
                                                         * '<S188>/Constant21'
                                                         * '<S188>/Constant22'
                                                         */
extern const volatile boolean swctcoo_eadc_b_enaEcoModeFild;/* Referenced by: '<S188>/Constant12' */
extern const volatile boolean swctcoo_eadc_b_enaEhbMbRgnFild;/* Referenced by: '<S188>/Constant3' */
extern const volatile boolean swctcoo_eadc_b_enaSptModeFild;/* Referenced by: '<S188>/Constant14' */
extern const volatile boolean swctcoo_eadc_b_useSportMapsIn4WDMode;/* Referenced by: '<S188>/Constant11' */
extern const volatile float32 swctcoo_eadm_mot2ZroCrsDecAdc_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table5' */

/* L4&#x74D2;&#x5A43;&#x6F48;&#x9422;&#x57AB;&#x6E80;2&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5B2E;&#x6AB7;&#x93C2;&#x6EC5;&#x5DFC; */
extern const volatile float32 swctcoo_eadm_mot2ZroCrsDecEco_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table9' */

/* Eco&#x59AF;&#x2033;&#x7D21;&#x6D93;&#x5B2C;&#x6578;&#x93C8;?&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5B2E;&#x6AB7;&#x93C2;&#x6EC5;&#x5DFC; */
extern const volatile float32 swctcoo_eadm_mot2ZroCrsDecEhb_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table3' */
extern const volatile float32 swctcoo_eadm_mot2ZroCrsDecSpt_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table7' */

/* Sport&#x59AF;&#x2033;&#x7D21;&#x6D93;&#x5B2C;&#x6578;&#x93C8;?&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5B2E;&#x6AB7;&#x93C2;&#x6EC5;&#x5DFC; */
extern const volatile float32 swctcoo_eadm_mot2ZroCrsIncAdc_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table4' */

/* L4&#x74D2;&#x5A43;&#x6F48;&#x9422;&#x57AB;&#x6E80;2&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5A42;&#x5D0C;&#x93C2;&#x6EC5;&#x5DFC; */
extern const volatile float32 swctcoo_eadm_mot2ZroCrsIncEco_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table8' */

/* Eco&#x59AF;&#x2033;&#x7D21;&#x6D93;&#x5B2C;&#x6578;&#x93C8;?&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5A42;&#x5D0C;&#x93C2;&#x6EC5;&#x5DFC; */
extern const volatile float32 swctcoo_eadm_mot2ZroCrsIncEhb_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table2' */
extern const volatile float32 swctcoo_eadm_mot2ZroCrsIncSpt_Z_Nmps[66];
                                 /* Referenced by: '<S188>/2-D Lookup Table6' */

/* Sport&#x59AF;&#x2033;&#x7D21;&#x6D93;&#x5B2C;&#x6578;&#x93C8;?&#x93B5;&#xE160;&#x7169;&#x5A4A;&#x3086;&#x5C1D;map-&#x6D93;&#x5A42;&#x5D0C;&#x93C2;&#x6EC5;&#x5DFC; */
extern const volatile boolean swctcoo_tdac_b_adcCtrlSts_ovrdflg;/* Referenced by: '<S204>/Constant9' */
extern const volatile boolean swctcoo_tdac_b_adcOvrCtlPmt;/* Referenced by:
                                                           * '<S204>/Constant12'
                                                           * '<S204>/Constant13'
                                                           * '<S204>/Constant14'
                                                           */
extern const volatile boolean swctcoo_tdac_b_ehbOvrCtlWhlDrgPmt;/* Referenced by: '<S206>/Constant1' */
extern const volatile boolean swctcoo_tdac_b_whlDemAdcCtl_ovrdflg;/* Referenced by: '<S204>/Constant1' */
extern const volatile uint8 swctcoo_tdac_st_adcCtrlSts_ovrdval;/* Referenced by: '<S204>/Constant11' */
extern const volatile float32 swctcoo_tdac_tq_whlDemAdcCtl_ovrdval;/* Referenced by: '<S204>/Constant5' */
extern const volatile boolean swctcoo_tqdc_b_axle2EhbTgtTq_ovrdflg;/* Referenced by: '<S335>/Constant4' */
extern const volatile boolean swctcoo_tqdc_b_ehbOvrCtlPmt;/* Referenced by: '<S364>/Constant2' */
extern const volatile boolean swctcoo_tqdc_b_enaEhbTqRamp;/* Referenced by: '<S335>/Constant12' */
extern const volatile float32 swctcoo_tqdc_tq_axle2EhbTgtTq_ovrdval;/* Referenced by: '<S335>/Constant5' */
extern const volatile float32 swctcoo_tqdc_tq_axle2EhbTqDecGrd_Nmps;/* Referenced by: '<S335>/Constant9' */
extern const volatile float32 swctcoo_tqdc_tq_axle2EhbTqIncGrd_Nmps;/* Referenced by: '<S335>/Constant8' */
extern const volatile float32 swctcoo_tqdc_tq_vlcAccPedlOvrdHi_Nm;/* Referenced by: '<S365>/Relay2' */
extern const volatile float32 swctcoo_tqdc_tq_vlcAccPedlOvrdLo_Nm;/* Referenced by: '<S365>/Relay2' */
extern const volatile boolean tcoo_apdc_b_useFctCfgMotor;/* Referenced by:
                                                          * '<S12>/Constant1'
                                                          * '<S12>/Constant12'
                                                          */
extern const volatile float32 tcoo_apdm_trqDemGearRTcs_Z_Nm[132];
                                  /* Referenced by: '<S28>/2-D Lookup Table1' */
extern const volatile float32 tcoo_apdm_trqDemGearRVehTyp1Tcs_Z_Nm[132];
                                  /* Referenced by: '<S43>/2-D Lookup Table1' */
extern const volatile float32 tcoo_apdm_trqDemGearRVehTyp2Tcs_Z_Nm[132];
                                  /* Referenced by: '<S58>/2-D Lookup Table1' */
extern const volatile float32 tcoo_dtdc_a_yrsLgtAcceTgt_mps2;/* Referenced by: '<S79>/Constant14' */
extern const volatile boolean tcoo_dtdc_b_useAccPdlEhbWhlCstDrg;/* Referenced by: '<S75>/Constant2' */
extern const volatile boolean tcoo_dtdc_b_useCoastDrgKi_flg;/* Referenced by: '<S79>/Constant8' */
extern const volatile uint8 tcoo_dtdc_defaultRegLvl;/* Referenced by: '<S86>/Constant16' */
extern const volatile float32 tcoo_dtdc_frac_coastDrgKMax;/* Referenced by: '<S79>/Constant2' */
extern const volatile float32 tcoo_dtdc_frac_coastDrgKMin;/* Referenced by: '<S79>/Constant5' */
extern const volatile float32 tcoo_dtdc_frac_drvAccPedalHi_pct;/* Referenced by: '<S79>/Relay' */
extern const volatile float32 tcoo_dtdc_frac_drvAccPedalLo_pct;/* Referenced by: '<S79>/Relay' */
extern const volatile float32 tcoo_dtdc_tm_timeCalKDelay_s;/* Referenced by: '<S79>/Constant11' */
extern const volatile float32 tcoo_dtdc_tm_vehStopDelay_s;/* Referenced by: '<S79>/Constant15' */
extern const volatile float32 tcoo_dtdc_v_calAvrgKVehSpdLo_kph;/* Referenced by: '<S79>/Constant4' */
extern const volatile float32 tcoo_dtdc_v_vehSpdErrCtrlHi_kph;/* Referenced by: '<S79>/Relay1' */
extern const volatile float32 tcoo_dtdc_v_vehSpdErrCtrlLo_kph;/* Referenced by: '<S79>/Relay1' */
extern const volatile float32 tcoo_dtdc_v_vehStopSpd_kph;/* Referenced by: '<S79>/Constant7' */
extern const volatile float32 tcoo_eada_mot2ZroCrsCrpSlp_X_yrsAcc_mps2[9];/* Referenced by:
                                                                      * '<S188>/1-D Lookup Table1'
                                                                      * '<S188>/1-D Lookup Table2'
                                                                      */
extern const volatile boolean tcoo_eadc_b_enaCrpSlopeModeFild;/* Referenced by: '<S188>/Constant19' */
extern const volatile boolean tcoo_eadc_b_useGetEventSts;/* Referenced by: '<S6>/Constant3' */
extern const volatile float32 tcoo_eadm_mot2ZroCrsDecCrsSlp_Y_Nmps[9];
                                 /* Referenced by: '<S188>/1-D Lookup Table1' */
extern const volatile float32 tcoo_eadm_mot2ZroCrsIncCrpSlp_Y_Nmps[9];
                                 /* Referenced by: '<S188>/1-D Lookup Table2' */
extern const volatile boolean tcoo_tdac_b_enaEhbVlcFilt;/* Referenced by: '<S224>/Constant2' */
extern const volatile float32 tcoo_tqda_pedlPosVirt_X_VehSpd_kph[11];
                                 /* Referenced by: '<S366>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position  - Vehicle Speed Axis */
extern const volatile float32 tcoo_tqda_pedlPosVirt_Y_WhlDem_Nm[10];
                                 /* Referenced by: '<S366>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position  - Wheel Torque Demand Axis */
extern const volatile boolean tcoo_tqdc_b_enaVlcMaxSpdLmt;/* Referenced by: '<S365>/Constant22' */
extern const volatile float32 tcoo_tqdc_frac_vlcAccPedlOvrdHi_pct;/* Referenced by: '<S365>/Relay1' */
extern const volatile float32 tcoo_tqdc_frac_vlcAccPedlOvrdLo_pct;/* Referenced by: '<S365>/Relay1' */
extern const volatile float32 tcoo_tqdc_tq_vlcDisGpOvrdFiltHi_Nm;/* Referenced by: '<S365>/Relay3' */
extern const volatile float32 tcoo_tqdc_tq_vlcDisGpOvrdFiltLo_Nm;/* Referenced by: '<S365>/Relay3' */
extern const volatile boolean tcoo_tqdd_b_gpOvrdCtrlFilt_ovrdflg;/* Referenced by: '<S365>/Constant1' */
extern const volatile boolean tcoo_tqdd_b_gpOvrdCtrlFilt_ovrdval;/* Referenced by: '<S365>/Constant14' */
extern const volatile float32 tcoo_tqdm_pedlPosVirt_Z_pct[110];
                                 /* Referenced by: '<S366>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position */
extern const volatile float32 tdaa_dmp2nd_X_VehSpd_kph[6];/* Referenced by:
                                                           * '<S310>/2-D Lookup Table7'
                                                           * '<S311>/2-D Lookup Table8'
                                                           * '<S312>/2-D Lookup Table5'
                                                           * '<S313>/2-D Lookup Table6'
                                                           */

/* Damping Factor Map 2nd Order Filter - Vehicle Speed Axis */
extern const volatile float32 tdaa_dmp2nd_Y_TgtTrq_Nm[11];/* Referenced by:
                                                           * '<S310>/2-D Lookup Table7'
                                                           * '<S311>/2-D Lookup Table8'
                                                           * '<S312>/2-D Lookup Table5'
                                                           * '<S313>/2-D Lookup Table6'
                                                           */

/* Damping Factor Map 2nd Order Filter - Target Torque Axis */
extern const volatile float32 tdaa_tau1st_X_VehSpd_kph[6];/* Referenced by:
                                                           * '<S284>/2-D Lookup Table3'
                                                           * '<S285>/2-D Lookup Table4'
                                                           * '<S286>/2-D Lookup Table1'
                                                           * '<S287>/2-D Lookup Table2'
                                                           * '<S288>/2-D Lookup Table3'
                                                           * '<S289>/2-D Lookup Table4'
                                                           * '<S290>/2-D Lookup Table1'
                                                           * '<S291>/2-D Lookup Table2'
                                                           * '<S292>/2-D Lookup Table3'
                                                           * '<S293>/2-D Lookup Table4'
                                                           * '<S294>/2-D Lookup Table1'
                                                           * '<S295>/2-D Lookup Table2'
                                                           */

/* Time Constant Map 1st Order Filter - Vehicle Speed Axis */
extern const volatile float32 tdaa_tau1st_Y_TgtTrq_Nm[11];/* Referenced by:
                                                           * '<S284>/2-D Lookup Table3'
                                                           * '<S285>/2-D Lookup Table4'
                                                           * '<S286>/2-D Lookup Table1'
                                                           * '<S287>/2-D Lookup Table2'
                                                           * '<S288>/2-D Lookup Table3'
                                                           * '<S289>/2-D Lookup Table4'
                                                           * '<S290>/2-D Lookup Table1'
                                                           * '<S291>/2-D Lookup Table2'
                                                           * '<S292>/2-D Lookup Table3'
                                                           * '<S293>/2-D Lookup Table4'
                                                           * '<S294>/2-D Lookup Table1'
                                                           * '<S295>/2-D Lookup Table2'
                                                           */

/* Time Constant Map 1st Order Filter - Target Torque Axis */
extern const volatile float32 tdaa_tau2nd_X_VehSpd_kph[6];/* Referenced by:
                                                           * '<S310>/2-D Lookup Table3'
                                                           * '<S311>/2-D Lookup Table4'
                                                           * '<S312>/2-D Lookup Table1'
                                                           * '<S313>/2-D Lookup Table2'
                                                           */

/* Time Constant Map 2nd Order Filter - Vehicle Speed Axis */
extern const volatile float32 tdaa_tau2nd_Y_TgtTrq_Nm[11];/* Referenced by:
                                                           * '<S310>/2-D Lookup Table3'
                                                           * '<S311>/2-D Lookup Table4'
                                                           * '<S312>/2-D Lookup Table1'
                                                           * '<S313>/2-D Lookup Table2'
                                                           */

/* Time Constant Map 2nd Order Filter - Target Torque Axis */
extern const volatile float32 tdaa_tauParabola_X_VehSpd_kph[6];/* Referenced by:
                                                                * '<S300>/1-D Lookup Table'
                                                                * '<S301>/1-D Lookup Table'
                                                                * '<S302>/1-D Lookup Table'
                                                                * '<S303>/1-D Lookup Table'
                                                                * '<S304>/1-D Lookup Table'
                                                                * '<S305>/1-D Lookup Table'
                                                                * '<S306>/1-D Lookup Table'
                                                                * '<S307>/1-D Lookup Table'
                                                                */

/* Time Constant Map Parabolic Filter - Vehicle Speed Axis */
extern const volatile boolean tdac_b_enaEhbCrbsFilt;/* Referenced by: '<S224>/Constant3' */
extern const volatile boolean tdac_b_useSportMapsIn4WDMode;/* Referenced by: '<S221>/Constant17' */

/* Use Drivability Sport Maps in 4WD Mode */
extern const volatile float32 tdac_dtq_whlMaxLimDecGrad_Nmps;/* Referenced by: '<S222>/Constant2' */

/* Wheel Max Safety Limit Decrease Gradient */
extern const volatile float32 tdac_dtq_whlMinLimIncGrad_Nmps;/* Referenced by: '<S222>/Constant6' */

/* Wheel Min Safety Limit Increase Gradient */
extern const volatile uint8 tdac_st_filtEnaCW;/* Referenced by: '<S267>/Constant7' */

/* Filter Enable CodeWord */
extern const volatile float32 tdac_tm_negFiltSetTime_s;/* Referenced by: '<S316>/Constant7' */

/* Negative filtering set time */
extern const volatile float32 tdac_tm_posFiltSetTime_s;/* Referenced by: '<S316>/Constant8' */

/* Positive filtering set time */
extern const volatile float32 tdac_tm_tipInSetTime_s;/* Referenced by: '<S316>/Constant6' */

/* Tip-In set time */
extern const volatile float32 tdac_tm_tipOutSetTime_s;/* Referenced by: '<S316>/Constant5' */

/* Tip-Out set time */
extern const volatile float32 tdac_tq_whlLoLimNegOffs_Nm;/* Referenced by: '<S318>/Constant5' */

/* Lower Torque Limit for negative demand */
extern const volatile float32 tdac_tq_whlLoLimPosOffs_Nm;/* Referenced by: '<S318>/Constant4' */

/* Lower Torque Limit for positive demand */
extern const volatile float32 tdac_tq_whlMaxLimOffset_Nm;/* Referenced by: '<S222>/Constant1' */

/* Wheel Max Safety Limit Offset */
extern const volatile float32 tdac_tq_whlMinLimOffset_Nm;/* Referenced by: '<S222>/Constant4' */

/* Wheel Min Safety Limit Offset */
extern const volatile float32 tdac_tq_whlNegErrTqOffs_Nm;/* Referenced by: '<S316>/Constant3' */

/* Negative Torque Error Offset */
extern const volatile float32 tdac_tq_whlNegTgtTqOffsNoDeb_Nm;/* Referenced by: '<S316>/Constant11' */

/* Negative Target Torque Offset without debounce */
extern const volatile float32 tdac_tq_whlNegTgtTqOffs_Nm;/* Referenced by: '<S316>/Constant2' */

/* Negative Target Torque Offset */
extern const volatile float32 tdac_tq_whlPosErrTqOffs_Nm;/* Referenced by: '<S316>/Constant1' */

/* Positive Torque Error Offset */
extern const volatile float32 tdac_tq_whlPosTgtTqOffsNoDeb_Nm;/* Referenced by: '<S316>/Constant10' */

/* Positive Target Torque Offset without debounce */
extern const volatile float32 tdac_tq_whlPosTgtTqOffs_Nm;/* Referenced by: '<S316>/Constant9' */

/* Positive Target Torque Offset */
extern const volatile float32 tdac_tq_whlUpLimNegOffs_Nm;/* Referenced by: '<S318>/Constant1' */

/* Upper Torque Limit for negative demand */
extern const volatile float32 tdac_tq_whlUpLimPosOffs_Nm;/* Referenced by: '<S318>/Constant' */

/* Upper Torque Limit for positive demand */
extern const volatile float32 tdac_tq_whlZeroRefNeg_Nm;/* Referenced by: '<S318>/Constant3' */

/* Zero Torque Reference for negative demand */
extern const volatile float32 tdac_tq_whlZeroRefPos_Nm;/* Referenced by: '<S318>/Constant2' */

/* Zero Torque Reference for positive demand */
extern const volatile float32 tdam_dmp2ndPwrPosEVSprt_Z_fact[66];
                                 /* Referenced by: '<S311>/2-D Lookup Table8' */

/* Damping Factor Map 2nd Order Filter - EV Sport Map */
extern const volatile float32 tdam_dmp2ndPwrPosEV_Z_fact[66];
                                 /* Referenced by: '<S310>/2-D Lookup Table7' */

/* Damping Factor Map 2nd Order Filter - EV Map */
extern const volatile float32 tdam_dmp2ndPwrPosSprt_Z_fact[66];
                                 /* Referenced by: '<S313>/2-D Lookup Table6' */

/* Damping Factor Map 2nd Order Filter - Sport Map */
extern const volatile float32 tdam_dmp2ndPwrPos_Z_fact[66];
                                 /* Referenced by: '<S312>/2-D Lookup Table5' */

/* Damping Factor Map 2nd Order Filter - Normal Map */
extern const volatile float32 tdam_tau1stBrkNegEVSprt_Z_s[66];
                                 /* Referenced by: '<S285>/2-D Lookup Table4' */

/* Time Constant Map 1st Order Filter - EV Sport Map */
extern const volatile float32 tdam_tau1stBrkNegEV_Z_s[66];
                                 /* Referenced by: '<S284>/2-D Lookup Table3' */

/* Time Constant Map 1st Order Filter - EV Map */
extern const volatile float32 tdam_tau1stBrkNegSprt_Z_s[66];
                                 /* Referenced by: '<S287>/2-D Lookup Table2' */

/* Time Constant Map 1st Order Filter - Sport Map */
extern const volatile float32 tdam_tau1stBrkNeg_Z_s[66];
                                 /* Referenced by: '<S286>/2-D Lookup Table1' */

/* Time Constant Map 1st Order Filter - Normal Map */
extern const volatile float32 tdam_tau1stBrkPosEVSprt_Z_s[66];
                                 /* Referenced by: '<S289>/2-D Lookup Table4' */

/* Time Constant Map 1st Order Filter - EV Sport Map */
extern const volatile float32 tdam_tau1stBrkPosEV_Z_s[66];
                                 /* Referenced by: '<S288>/2-D Lookup Table3' */

/* Time Constant Map 1st Order Filter - EV Map */
extern const volatile float32 tdam_tau1stBrkPosSprt_Z_s[66];
                                 /* Referenced by: '<S291>/2-D Lookup Table2' */

/* Time Constant Map 1st Order Filter - Sport Map */
extern const volatile float32 tdam_tau1stBrkPos_Z_s[66];
                                 /* Referenced by: '<S290>/2-D Lookup Table1' */

/* Time Constant Map 1st Order Filter - Normal Map */
extern const volatile float32 tdam_tau1stPwrNegEVSprt_Z_s[66];
                                 /* Referenced by: '<S293>/2-D Lookup Table4' */

/* Time Constant Map 1st Order Filter - EV Sport Map */
extern const volatile float32 tdam_tau1stPwrNegEV_Z_s[66];
                                 /* Referenced by: '<S292>/2-D Lookup Table3' */

/* Time Constant Map 1st Order Filter - EV Map */
extern const volatile float32 tdam_tau1stPwrNegSprt_Z_s[66];
                                 /* Referenced by: '<S295>/2-D Lookup Table2' */

/* Time Constant Map 1st Order Filter - Sport Map */
extern const volatile float32 tdam_tau1stPwrNeg_Z_s[66];
                                 /* Referenced by: '<S294>/2-D Lookup Table1' */

/* Time Constant Map 1st Order Filter - Normal Map */
extern const volatile float32 tdam_tau2ndPwrPosEVSprt_Z_s[66];
                                 /* Referenced by: '<S311>/2-D Lookup Table4' */

/* Time Constant Map 2nd Order Filter - EV Sport Map */
extern const volatile float32 tdam_tau2ndPwrPosEV_Z_s[66];
                                 /* Referenced by: '<S310>/2-D Lookup Table3' */

/* Time Constant Map 2nd Order Filter - EV Map */
extern const volatile float32 tdam_tau2ndPwrPosSprt_Z_s[66];
                                 /* Referenced by: '<S313>/2-D Lookup Table2' */

/* Time Constant Map 2nd Order Filter - Sport Map */
extern const volatile float32 tdam_tau2ndPwrPos_Z_s[66];
                                 /* Referenced by: '<S312>/2-D Lookup Table1' */

/* Time Constant Map 2nd Order Filter - Normal Map */
extern const volatile float32 tdam_tauParabolaNegEVSprt_Z_s[6];
                                  /* Referenced by: '<S301>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - EV Sport Map */
extern const volatile float32 tdam_tauParabolaNegEV_Z_s[6];
                                  /* Referenced by: '<S300>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - EV Map */
extern const volatile float32 tdam_tauParabolaNegSprt_Z_s[6];
                                  /* Referenced by: '<S303>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - Sport Map */
extern const volatile float32 tdam_tauParabolaNeg_Z_s[6];
                                  /* Referenced by: '<S302>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - Normal Map */
extern const volatile float32 tdam_tauParabolaPosEVSprt_Z_s[6];
                                  /* Referenced by: '<S305>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - EV Sport Map */
extern const volatile float32 tdam_tauParabolaPosEV_Z_s[6];
                                  /* Referenced by: '<S304>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - EV Map */
extern const volatile float32 tdam_tauParabolaPosSprt_Z_s[6];
                                  /* Referenced by: '<S307>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - Sport Map */
extern const volatile float32 tdam_tauParabolaPos_Z_s[6];
                                  /* Referenced by: '<S306>/1-D Lookup Table' */

/* Time Constant Map Parabolic Filter - Normal Map */
extern const volatile boolean tqdc_b_disGpOvrdTq;/* Referenced by: '<S352>/Constant11' */
extern const volatile float32 tqdc_tq_axle2RBSLimDecGrad_Nmps;/* Referenced by: '<S332>/Constant1' */

/* Regenerative Braking Torque Limit Decrease Gradient on Secondary Axle */
extern const volatile float32 tqdc_tq_axle2RBSLimIncGrad_Nmps;/* Referenced by: '<S332>/Constant3' */

/* Regenerative Braking Torque Limit Increase Gradient on Secondary Axle */
extern const volatile float32 tqdc_x_accPedlPosHiDisRBS_pct;/* Referenced by: '<S332>/Relay' */

/* Accelerator Pedal Position high threshold to disable Regenerative Braking */
extern const volatile float32 tqdc_x_accPedlPosLoDisRBS_pct;/* Referenced by: '<S332>/Relay' */

/* Accelerator Pedal Position low threshold to disable Regenerative Braking */
extern const volatile float32 tqdc_x_brkPedlPosHiEnaRBS_pct;/* Referenced by: '<S332>/Relay1' */

/* Brake Pedal Position high threshold to enable Regenerative Braking */
extern const volatile float32 tqdc_x_brkPedlPosLoEnaRBS_pct;/* Referenced by: '<S332>/Relay1' */

/* Brake Pedal Position low threshold to enable Regenerative Braking */
extern const volatile float32 tvrc_dtq_Mot2TqDec_Nmps;/* Referenced by: '<S9>/Constant11' */
extern const volatile float32 tvrc_dtq_Mot2TqInc_Nmps;/* Referenced by: '<S9>/Constant10' */

#define swc_TCOO_STOP_SEC_CONST_VOLATILE
#include "swc_TCOO_MemMap.h"
#define swc_TCOO_START_SEC_VAR
#include "swc_TCOO_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern float32 apdd_fact_trsmGearRat;  /* '<S13>/Multiport Switch1' */

/* Arbitrated Transmission Gear Ratio for Pedal Maps */
extern float32 apdd_n_engActSpdMdl_rpm;/* '<S15>/Data Type Conversion3' */

/* Engine Actual Speed Modeled */
extern sint8 apdd_st_trsmGearTgt;      /* '<S70>/Switch2' */

/* Arbitrated Transmission Target Gear for Pedal Maps */
extern float32 apdd_tq_crsDem_Nm;      /* '<S21>/Merge' */

/* Crank-shaft Driver Torque Demand */
extern float32 apdd_tq_whlDem_Nm;      /* '<S18>/Switch2' */

/* Wheel Torque Demand */
extern float32 apdd_tq_whlDrvrDem_Nm;  /* '<S21>/Product' */

/* Wheel Driver Torque Demand */
extern boolean drid_b_rgnOffGlobalEna; /* '<S87>/Logical Operator14' */
extern boolean dtdd_b_rgnOffEna;       /* '<S87>/SR_latch1' */
extern uint8 dtdd_cnt_rgnOffCount;     /* '<S116>/Switch5' */
extern uint8 dtdd_st_EcoMemRegenLvl;   /* '<S88>/Signal Conversion1' */

/* Regeneration Level Actual */
extern uint8 dtdd_st_EcoRegenLvlAct;   /* '<S140>/Switch3' */

/* Regeneration Level Actual */
extern uint8 dtdd_st_EcoRegenLvlFromEE;/* '<S86>/C Caller24' */

/* Regeneration Level From EEPROM */
extern uint8 dtdd_st_NormMemRegenLvl;  /* '<S88>/Signal Conversion' */

/* Regeneration Level Actual */
extern uint8 dtdd_st_NormRegenLvlFromEE;/* '<S86>/C Caller23' */

/* Regeneration Level From EEPROM */
extern uint8 dtdd_st_NormalRegenLvlAct;/* '<S144>/Switch3' */

/* Regeneration Level Actual */
extern uint8 dtdd_st_RegenLvlAct;      /* '<S88>/Switch4' */

/* Regeneration Level Actual */
extern uint8 dtdd_st_RegenLvlDisp;     /* '<S88>/Switch6' */

/* Regeneration Level Display */
extern float32 dtdd_tq_whlDragDem_Nm;  /* '<S75>/MinMax4' */

/* Drag Torque Demand */
extern float32 dtdd_tq_whlEVBrakingDrag_Nm;/* '<S71>/Sum' */

/* EV Braking Drag Torque Demand */
extern float32 dtdd_tq_whlEVCoastingDrag_Nm;/* '<S78>/Sum1' */

/* EV Coasting Drag Torque Demand */
extern boolean eadd_b_gearR2NTqDirSwt; /* '<S175>/SR_latch' */
extern boolean eadd_b_whlAcceSupprsn;  /* '<S189>/Logical Operator3' */
extern float32 eadd_tq_axle2TgtTq_Nm;  /* '<S186>/Switch2' */

/* Secondary EAD Target Torque Raw */
extern float32 eadd_tq_mot2TgtFldAcceLmt_Nm;/* '<S201>/Sum6' */
extern float32 eadd_tq_mot2TgtTqFild_Nm;/* '<S199>/Sum6' */

/* Secondary EAD Filtered Target Torque */
extern float32 eadd_tq_mot2TgtTqReq_Nm;/* '<S177>/Switch2' */

/* Secondary EAD Torque Request */
extern float32 eadd_tq_mot2TgtTqUnfilt_Nm;/* '<S175>/Product1' */

/* Secondary EAD Unfiltered Target Torque */
extern float32 eadd_tq_mot2TgtTq_Nm;   /* '<S188>/Switch5' */

/* Secondary EAD Target Torque */
extern float32 swctcoo_apdd_tq_crsDemVehTyp1_Nm;/* '<S22>/Merge' */
extern float32 swctcoo_apdd_tq_crsDemVehTyp2_Nm;/* '<S23>/Merge' */
extern float32 swctcoo_apdd_tq_whlDrvrDemVehTyp1_Nm;/* '<S22>/Product' */
extern float32 swctcoo_apdd_tq_whlDrvrDemVehTyp2_Nm;/* '<S23>/Product' */
extern float32 swctcoo_apdd_tq_whlDrvrDem_Nm;/* '<S12>/Switch3' */
extern boolean swctcoo_dtdd_b_drvPfmncDrgDec;/* '<S87>/Switch11' */

/* DIM&#x93BB;&#x612E;&#x305A;&#x9473;&#x4ECB;&#x567A;&#x9365;&#x70B4;&#x6579;&#x9351;&#x5FD3;&#x6025; */
extern boolean swctcoo_dtdd_b_ehbMbRgnOvrCtl;/* '<S75>/Logical Operator5' */
extern uint8 swctcoo_dtdd_st_SptMemRegenLvl;/* '<S88>/Signal Conversion2' */

/* Regeneration Level Actual */
extern uint8 swctcoo_dtdd_st_SptRegenLvlAct;/* '<S145>/Switch3' */

/* Regeneration Level Actual */
extern uint8 swctcoo_dtdd_st_ecoRegLvlInit;/* '<S86>/Switch15' */

/* Regeneration Level Init */
extern uint8 swctcoo_dtdd_st_normRegLvlInit;/* '<S86>/Switch10' */

/* Regeneration Level Init */
extern uint8 swctcoo_dtdd_st_sptRegLvlInit;/* '<S86>/Switch17' */

/* Regeneration Level Init */
extern uint8 swctcoo_dtdd_st_sptRegenLvlFromEE;/* '<S86>/C Caller' */

/* Regeneration Level From EEPROM */
extern float32 swctcoo_dtdd_tq_whlCoastDrgDem_Nm;/* '<S75>/MinMax3' */
extern float32 swctcoo_dtdd_tq_whlDrgDemEhb_Nm;/* '<S75>/Switch2' */
extern boolean swctcoo_eadd_b_adcOvrCtl;/* '<S188>/Logical Operator3' */
extern boolean swctcoo_eadd_b_ehbOvrCtl;/* '<S188>/Logical Operator2' */
extern boolean swctcoo_eadd_b_vehEcoModCtl;/* '<S188>/Logical Operator10' */
extern boolean swctcoo_eadd_b_vehSptModCtl;/* '<S188>/Logical Operator9' */
extern float32 swctcoo_eadd_tq_axle2TgtUnitDlyMotTyp0_Nm;/* '<S188>/Switch2' */
extern float32 swctcoo_eadd_tq_mot2TgtFldAdc_Nm;/* '<S195>/Sum6' */
extern float32 swctcoo_eadd_tq_mot2TgtFldEco_Nm;/* '<S198>/Sum6' */
extern float32 swctcoo_eadd_tq_mot2TgtFldEhb_Nm;/* '<S196>/Sum6' */
extern float32 swctcoo_eadd_tq_mot2TgtFldSpt_Nm;/* '<S197>/Sum6' */
extern uint8 swctcoo_tdad_st_adcCtrlSts;/* '<S204>/Switch7' */
extern float32 swctcoo_tdad_tq_whlDemAdcCtl_Nm;/* '<S204>/Switch4' */
extern float32 swctcoo_tdad_tq_whlDemUnAdc_Nm;/* '<S225>/Switch2' */
extern boolean swctcoo_tqdd_b_ehbOvrCtl;/* '<S364>/Logical Operator6' */
extern boolean swctcoo_tqdd_b_ehbVlcOvrCtl;/* '<S364>/Logical Operator23' */
extern boolean swctcoo_tqdd_b_gpOvrd;  /* '<S365>/Switch9' */
extern float32 swctcoo_tqdd_tq_axle2EhbTgtTqRaw_Nm;/* '<S335>/Switch4' */
extern float32 swctcoo_tqdd_tq_axle2EhbTgtTq_Nm;/* '<S335>/Switch8' */
extern float32 swctcoo_tqdd_tq_ehbAccCtrlTgtTq_Nm;/* '<S352>/Switch4' */
extern float32 tcoo_dtdd_a_acce;       /* '<S79>/CoastingDrgAutoModeKCal' */
extern boolean tcoo_dtdd_b_calKVld;    /* '<S79>/CoastingDrgAutoModeKCal' */
extern float32 tcoo_dtdd_frac_coastDrgK;/* '<S79>/CoastingDrgAutoModeKCal' */
extern float32 tcoo_dtdd_frac_coastDrgKlast;/* '<S79>/Switch2' */
extern float32 tcoo_dtdd_frac_coastDrgKlastUnLim;/* '<S79>/CoastingDrgAutoModeKCal' */
extern uint8 tcoo_dtdd_st_calKSts;     /* '<S79>/CoastingDrgAutoModeKCal' */
extern float32 tcoo_dtdd_tm_calKTime_s;/* '<S79>/CoastingDrgAutoModeKCal' */
extern float32 tcoo_dtdd_tq_whlCstDrgDemNoEhb_Nm;/* '<S75>/MinMax7' */
extern float32 tcoo_dtdd_v_coastDrgVehSpdEnd;/* '<S79>/CoastingDrgAutoModeKCal' */
extern float32 tcoo_dtdd_v_coastDrgVehSpdStrt;/* '<S79>/CoastingDrgAutoModeKCal' */
extern boolean tcoo_eadd_b_acpCrsFltDebd;/* '<S6>/con_1' */
extern boolean tcoo_eadd_b_ehbMsgErrDebd;/* '<S6>/Logical Operator1' */
extern float32 tcoo_eadd_tq_mot2TgtFldCrpSlp_Nm;/* '<S200>/Sum6' */
extern boolean tcoo_tqdd_b_accPedlPosVirtVld;/* '<S366>/Switch3' */
extern boolean tcoo_tqdd_b_ehbDisEnbCreep;/* '<S364>/Logical Operator10' */
extern boolean tcoo_tqdd_b_gpOvrdCtrlFilt;/* '<S365>/Switch11' */
extern boolean tcoo_tqdd_b_vlcMaxSpdLmtFilt;/* '<S365>/Logical Operator46' */
extern float32 tcoo_tqdd_x_accPedlPosVirtRaw_pct;/* '<S366>/2-D Lookup Table4' */

/* Virtual accelerator Pedal position raw value */
extern float32 tcoo_tqdd_x_accPedlPosVirt_pct;/* '<S366>/Switch1' */

/* Virtual accelerator Pedal position */
extern boolean tdad_b_disEnbDrvFilter; /* '<S224>/Logical Operator5' */
extern boolean tdad_b_tipIn;           /* '<S316>/SR_latch1' */

/* Driver tip-in detected */
extern FiltTrqRange tdad_e_filterTrqRange;/* '<S223>/TorqueRange' */

/* Filter torque range */
extern FiltTrqRange tdad_e_filterType; /* '<S267>/Switch' */

/* Filter type */
extern float32 tdad_fact_dampFilt2nd;  /* '<S309>/Merge1' */

/* Damping Factor 2nd Order Filter */
extern float32 tdad_tm_tauFilt1st_s;   /* '<S268>/Merge' */

/* Time Constant 1st Order Filter */
extern float32 tdad_tm_tauFilt2nd_s;   /* '<S309>/Merge' */

/* Time Constant 2nd Order Filter */
extern float32 tdad_tm_tauFiltPar_s;   /* '<S269>/Merge' */

/* Time Constant Parabolic Filter */
extern float32 tdad_tq_whlDemFilt1st_Nm;/* '<S238>/Switch2' */

/* Wheel Filtered Torque Demand after 1st order filter */
extern float32 tdad_tq_whlDemFilt2nd_Nm;/* '<S228>/Switch2' */

/* Wheel Filtered Torque Demand after 2nd order filter */
extern float32 tdad_tq_whlDemFiltPar_Nm;/* '<S227>/Switch2' */

/* Wheel Filtered Torque Demand after parabolic filter */
extern float32 tdad_tq_whlDemFilt_Nm;  /* '<S230>/Switch2' */

/* Wheel Filtered Torque Demand */
extern float32 tdad_tq_whlDemUnfilt_Nm;/* '<S329>/Switch2' */

/* Wheel Unfiltered Torque Demand */
extern float32 tdad_tq_whlDemUnlim_Nm; /* '<S205>/MinMax2' */

/* Wheel Unlimited Driver Torque Demand */
extern float32 tdad_tq_whlDem_Nm;      /* '<S206>/Switch2' */

/* Wheel Fast Torque Demand */
extern float32 tdad_tq_whlFiltMax_Nm;  /* '<S314>/MinMax2' */

/* Wheel Max Filtered Torque Limit */
extern float32 tdad_tq_whlFiltMin_Nm;  /* '<S315>/MinMax2' */

/* Wheel Min Filtered Torque Limit */
extern boolean tqdd_b_absOvrCtl_flg;   /* '<S364>/Logical Operator50' */
extern boolean tqdd_b_pdcBrkFlg;       /* '<S335>/Logical Operator4' */
extern uint8 tqdd_st_ehbTrqOvrdActv;   /* '<S367>/Switch10' */
extern uint8 tqdd_st_ehbTrqOvrdType;   /* '<S367>/Switch8' */
extern float32 tqdd_tq_axle2AbsTgtTq_Nm;/* '<S338>/Switch11' */
extern float32 tqdd_tq_axle2RBSTqLim_Nm;/* '<S332>/SwitchRampMot2RegenBrkLim' */

/* Secondary Axle Torque Limit For Regenerative Braking */
extern float32 tqdd_tq_axle2TqDem_Nm;  /* '<S334>/Switch2' */

/* Secondary Axle Torque Demand */
extern float32 tqdd_tq_axle2VSCMaxTqIntv_Nm;/* '<S336>/MinMax6' */

/* Secondary Axle Max torque for VSC intervention */
extern float32 tqdd_tq_axle2VSCMinTqIntv_Nm;/* '<S336>/MinMax3' */

/* Secondary Axle Min torque for VSC intervention */
extern float32 tqdd_tq_axle2VSCTqTgt_Nm;/* '<S337>/Switch2' */

/* Secondary Axle Target Torque after VSC Intervention */
extern float32 tvrd_tq_mot2TgtTqReq_Nm;/* '<S442>/Chart' */

#define swc_TCOO_STOP_SEC_VAR
#include "swc_TCOO_MemMap.h"

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
 * '<Root>' : 'swc_TCOO'
 * '<S1>'   : 'swc_TCOO/TCOO_Torque_Coordinator'
 * '<S2>'   : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand'
 * '<S3>'   : 'swc_TCOO/TCOO_Torque_Coordinator/Compare To Constant'
 * '<S4>'   : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl'
 * '<S5>'   : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2'
 * '<S6>'   : 'swc_TCOO/TCOO_Torque_Coordinator/GetEventStatus'
 * '<S7>'   : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration'
 * '<S8>'   : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution'
 * '<S9>'   : 'swc_TCOO/TCOO_Torque_Coordinator/TVR_TorqueVectorControl'
 * '<S10>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/EngineSpeedModel'
 * '<S11>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalDeadBand'
 * '<S12>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection'
 * '<S13>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/TranmissionGearProcessing'
 * '<S14>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/model_info1'
 * '<S15>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/EngineSpeedModel/1st Order Filter'
 * '<S16>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/EngineSpeedModel/kph2mps'
 * '<S17>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/EngineSpeedModel/radps2rpm'
 * '<S18>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalDeadBand/saturation_dynamic'
 * '<S19>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/Compare To Constant1'
 * '<S20>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/Compare To Constant19'
 * '<S21>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection'
 * '<S22>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1'
 * '<S23>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2'
 * '<S24>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/Compare To Constant1'
 * '<S25>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/Enumerated Constant3'
 * '<S26>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/Enumerated Constant4'
 * '<S27>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMap_GearN'
 * '<S28>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMap_GearR'
 * '<S29>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_Eco'
 * '<S30>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_GearD'
 * '<S31>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_Sport'
 * '<S32>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMap_GearR/Compare To Constant'
 * '<S33>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_Eco/Switch Case Action Subsystem'
 * '<S34>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_Eco/Switch Case Action Subsystem1'
 * '<S35>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_GearD/Switch Case Action Subsystem'
 * '<S36>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_GearD/Switch Case Action Subsystem1'
 * '<S37>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_Sport/Switch Case Action Subsystem'
 * '<S38>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection/PedalMaps_Sport/Switch Case Action Subsystem1'
 * '<S39>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/Compare To Constant1'
 * '<S40>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/Enumerated Constant3'
 * '<S41>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/Enumerated Constant4'
 * '<S42>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMap_GearN'
 * '<S43>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMap_GearR'
 * '<S44>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_Eco'
 * '<S45>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_GearD'
 * '<S46>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_Sport'
 * '<S47>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMap_GearR/Compare To Constant'
 * '<S48>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_Eco/Switch Case Action Subsystem'
 * '<S49>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_Eco/Switch Case Action Subsystem1'
 * '<S50>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_GearD/Switch Case Action Subsystem'
 * '<S51>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_GearD/Switch Case Action Subsystem1'
 * '<S52>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_Sport/Switch Case Action Subsystem'
 * '<S53>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp1/PedalMaps_Sport/Switch Case Action Subsystem1'
 * '<S54>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/Compare To Constant1'
 * '<S55>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/Enumerated Constant3'
 * '<S56>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/Enumerated Constant4'
 * '<S57>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMap_GearN'
 * '<S58>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMap_GearR'
 * '<S59>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_Eco'
 * '<S60>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_GearD'
 * '<S61>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_Sport'
 * '<S62>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMap_GearR/Compare To Constant'
 * '<S63>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_Eco/Switch Case Action Subsystem'
 * '<S64>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_Eco/Switch Case Action Subsystem1'
 * '<S65>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_GearD/Switch Case Action Subsystem'
 * '<S66>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_GearD/Switch Case Action Subsystem1'
 * '<S67>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_Sport/Switch Case Action Subsystem'
 * '<S68>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/PedalMapsSelection/PedalMapsSelection_VehTyp2/PedalMaps_Sport/Switch Case Action Subsystem1'
 * '<S69>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/TranmissionGearProcessing/Ovrd_trsmGearTgt'
 * '<S70>'  : 'swc_TCOO/TCOO_Torque_Coordinator/APD_DriverDemand/TranmissionGearProcessing/Ovrd_trsmGearTgt/override_signal'
 * '<S71>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/BrakingDrag'
 * '<S72>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag'
 * '<S73>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl'
 * '<S74>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/Enumerated Constant1'
 * '<S75>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit'
 * '<S76>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/model_info1'
 * '<S77>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/BrakingDrag/Compare To Constant20'
 * '<S78>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag/CoastingDragCal'
 * '<S79>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag/CoastingDrgAutoModeKCal'
 * '<S80>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag/CoastingDragCal/Compare To Constant20'
 * '<S81>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag/CoastingDrgAutoModeKCal/CoastingDrgAutoModeKCal'
 * '<S82>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag/CoastingDrgAutoModeKCal/Enumerated Constant1'
 * '<S83>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag/CoastingDrgAutoModeKCal/saturation_dynamic'
 * '<S84>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag/CoastingDrgAutoModeKCal/turnON_delay'
 * '<S85>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingDrag/CoastingDrgAutoModeKCal/turnON_delay/timed_delay'
 * '<S86>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc'
 * '<S87>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition'
 * '<S88>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager'
 * '<S89>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlReq'
 * '<S90>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/Compare To Constant'
 * '<S91>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/Compare To Constant1'
 * '<S92>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlEco'
 * '<S93>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlNormal'
 * '<S94>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlSport'
 * '<S95>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/turnON_delay1'
 * '<S96>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/turnON_delay2'
 * '<S97>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/turnON_delay3'
 * '<S98>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlEco/Falling_Edge'
 * '<S99>'  : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlEco/Falling_Edge/DocBlock'
 * '<S100>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlEco/Falling_Edge/DocBlockDescription'
 * '<S101>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlEco/Falling_Edge/model_info1'
 * '<S102>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlNormal/Falling_Edge'
 * '<S103>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlNormal/Falling_Edge/DocBlock'
 * '<S104>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlNormal/Falling_Edge/DocBlockDescription'
 * '<S105>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlNormal/Falling_Edge/model_info1'
 * '<S106>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlSport/Falling_Edge'
 * '<S107>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlSport/Falling_Edge/DocBlock'
 * '<S108>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlSport/Falling_Edge/DocBlockDescription'
 * '<S109>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/GetNvmWriteStsRegLvlSport/Falling_Edge/model_info1'
 * '<S110>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/turnON_delay1/timed_delay'
 * '<S111>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/turnON_delay2/timed_delay'
 * '<S112>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/InitRegenLvlCalc/turnON_delay3/timed_delay'
 * '<S113>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Compare To Constant'
 * '<S114>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Compare To Constant1'
 * '<S115>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Compare To Constant20'
 * '<S116>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Counter'
 * '<S117>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Detect Decrease'
 * '<S118>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Detect Decrease1'
 * '<S119>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Detect Decrease2'
 * '<S120>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Detect Increase'
 * '<S121>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Detect Increase1'
 * '<S122>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Detect Increase2'
 * '<S123>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Detect Increase3'
 * '<S124>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Enumerated Constant1'
 * '<S125>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Enumerated Constant2'
 * '<S126>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Enumerated Constant3'
 * '<S127>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/Enumerated Constant4'
 * '<S128>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/SR_latch'
 * '<S129>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/SR_latch1'
 * '<S130>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/turnOFF_delay'
 * '<S131>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/turnOFF_delay1'
 * '<S132>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/turnON_delay'
 * '<S133>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/turnON_delay1'
 * '<S134>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/turnOFF_delay/timed_delay'
 * '<S135>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/turnOFF_delay1/timed_delay'
 * '<S136>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/turnON_delay/timed_delay'
 * '<S137>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlEnbCondition/turnON_delay1/timed_delay'
 * '<S138>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Compare To Constant1'
 * '<S139>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Compare To Constant4'
 * '<S140>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/EcoRegenLvlCalc'
 * '<S141>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge'
 * '<S142>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge1'
 * '<S143>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge2'
 * '<S144>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/NormalRegenLvlCalc'
 * '<S145>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/SptRegenLvlCalc'
 * '<S146>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/mBSW_NvmWrite_RegenLvlECO'
 * '<S147>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/mBSW_NvmWrite_RegenLvlNORMAL'
 * '<S148>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/mBSW_NvmWrite_RegenLvlSPORT'
 * '<S149>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/EcoRegenLvlCalc/Compare To Constant4'
 * '<S150>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge/DocBlock'
 * '<S151>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge/DocBlockDescription'
 * '<S152>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge/model_info1'
 * '<S153>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge1/DocBlock'
 * '<S154>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge1/DocBlockDescription'
 * '<S155>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge1/model_info1'
 * '<S156>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge2/DocBlock'
 * '<S157>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge2/DocBlockDescription'
 * '<S158>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/Falling_Edge2/model_info1'
 * '<S159>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/NormalRegenLvlCalc/Compare To Constant4'
 * '<S160>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlManager/SptRegenLvlCalc/Compare To Constant4'
 * '<S161>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlReq/Detect Decrease'
 * '<S162>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/CoastingLvl/RegenLvlReq/Detect Increase'
 * '<S163>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant1'
 * '<S164>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant10'
 * '<S165>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant12'
 * '<S166>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant14'
 * '<S167>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant16'
 * '<S168>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant17'
 * '<S169>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant18'
 * '<S170>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant19'
 * '<S171>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant20'
 * '<S172>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant5'
 * '<S173>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant7'
 * '<S174>' : 'swc_TCOO/TCOO_Torque_Coordinator/DTD_DecelerationControl/FilterAndLimit/Compare To Constant8'
 * '<S175>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/AxleToMotorShaftConv'
 * '<S176>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/GearshiftCompensation'
 * '<S177>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/GearshiftTorqueIntervention'
 * '<S178>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/TorqueSwapInGearR'
 * '<S179>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter'
 * '<S180>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/AxleToMotorShaftConv/Enumerated Constant1'
 * '<S181>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/AxleToMotorShaftConv/Enumerated Constant2'
 * '<S182>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/AxleToMotorShaftConv/Enumerated Constant4'
 * '<S183>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/AxleToMotorShaftConv/SR_latch'
 * '<S184>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/AxleToMotorShaftConv/saturation_dynamic1'
 * '<S185>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/AxleToMotorShaftConv/saturation_dynamic6'
 * '<S186>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/GearshiftCompensation/saturation_dynamic6'
 * '<S187>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/TorqueSwapInGearR/Enumerated Constant2'
 * '<S188>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter'
 * '<S189>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/AccPdlTrqFiltLmt'
 * '<S190>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/Compare To Constant1'
 * '<S191>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/Compare To Constant2'
 * '<S192>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/Compare To Constant3'
 * '<S193>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/Enumerated Constant1'
 * '<S194>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/Enumerated Constant2'
 * '<S195>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/RateLimitEnable'
 * '<S196>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/RateLimitEnable1'
 * '<S197>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/RateLimitEnable2'
 * '<S198>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/RateLimitEnable3'
 * '<S199>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/RateLimitEnable4'
 * '<S200>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/RateLimitEnable5'
 * '<S201>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/RateLimitEnable6'
 * '<S202>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/AccPdlTrqFiltLmt/Compare To Constant'
 * '<S203>' : 'swc_TCOO/TCOO_Torque_Coordinator/EAD_TargetTorqueControlMot2/ZeroCrossingFilter/ZeroCrossingFilter/AccPdlTrqFiltLmt/SR_latch1'
 * '<S204>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq'
 * '<S205>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandArbitration'
 * '<S206>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering'
 * '<S207>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandLimitation'
 * '<S208>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/model_info1'
 * '<S209>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq/Compare To Constant10'
 * '<S210>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq/Compare To Constant11'
 * '<S211>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq/Compare To Constant6'
 * '<S212>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq/Compare To Constant7'
 * '<S213>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq/Compare To Constant8'
 * '<S214>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq/Enumerated Constant1'
 * '<S215>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq/Enumerated Constant2'
 * '<S216>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/ADCOverCtrlAxle2TgtTrq/saturation_dynamic'
 * '<S217>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Compare To Constant1'
 * '<S218>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Compare To Constant11'
 * '<S219>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Compare To Constant2'
 * '<S220>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics'
 * '<S221>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters'
 * '<S222>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/SafetyLimit'
 * '<S223>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange'
 * '<S224>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/disEnbDrvFilt'
 * '<S225>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/saturation_dynamic2'
 * '<S226>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter'
 * '<S227>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter'
 * '<S228>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SecondOrderFilter'
 * '<S229>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SelectFilter'
 * '<S230>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/saturation_dynamic'
 * '<S231>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/Detect Increase'
 * '<S232>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/Enumerated Constant'
 * '<S233>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/Enumerated Constant1'
 * '<S234>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/Enumerated Constant2'
 * '<S235>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/Enumerated Constant3'
 * '<S236>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/Enumerated Constant4'
 * '<S237>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/Filter'
 * '<S238>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/saturation_dynamic'
 * '<S239>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/FirstOrderFilter/Filter/Integrator'
 * '<S240>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/Detect Increase1'
 * '<S241>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/Detect Increase2'
 * '<S242>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/Enumerated Constant'
 * '<S243>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/Enumerated Constant1'
 * '<S244>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/Enumerated Constant2'
 * '<S245>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit'
 * '<S246>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/saturation_dynamic'
 * '<S247>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/CalcGain'
 * '<S248>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/Parabola'
 * '<S249>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/CalcGain/abs_val'
 * '<S250>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/CalcGain/abs_val/neg'
 * '<S251>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/CalcGain/abs_val/pos'
 * '<S252>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/Parabola/abs_val'
 * '<S253>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/Parabola/abs_val1'
 * '<S254>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/Parabola/abs_val/neg'
 * '<S255>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/Parabola/abs_val/pos'
 * '<S256>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/Parabola/abs_val1/neg'
 * '<S257>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/ParabolicFilter/ParabolaLimit/Parabola/abs_val1/pos'
 * '<S258>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SecondOrderFilter/Detect Increase'
 * '<S259>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SecondOrderFilter/Enumerated Constant'
 * '<S260>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SecondOrderFilter/Filter'
 * '<S261>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SecondOrderFilter/Filter/Integrator'
 * '<S262>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SecondOrderFilter/Filter/Integrator1'
 * '<S263>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SelectFilter/Enumerated Constant2'
 * '<S264>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SelectFilter/Enumerated Constant3'
 * '<S265>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/FiltersDynamics/SelectFilter/Enumerated Constant5'
 * '<S266>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/Compare To Constant1'
 * '<S267>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/EnableFilters'
 * '<S268>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter'
 * '<S269>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter'
 * '<S270>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/SecondOrderFilter'
 * '<S271>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/EnableFilters/Enumerated Constant'
 * '<S272>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/EnableFilters/Enumerated Constant1'
 * '<S273>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/EnableFilters/Enumerated Constant2'
 * '<S274>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/EnableFilters/Enumerated Constant3'
 * '<S275>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/EnableFilters/Enumerated Constant4'
 * '<S276>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/EnableFilters/Enumerated Constant5'
 * '<S277>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/EnableFilters/Enumerated Constant6'
 * '<S278>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Neg'
 * '<S279>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Pos'
 * '<S280>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Enumerated Constant'
 * '<S281>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Enumerated Constant1'
 * '<S282>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Enumerated Constant5'
 * '<S283>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Power_Neg'
 * '<S284>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Neg/EVMap'
 * '<S285>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Neg/EVSportMap'
 * '<S286>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Neg/NormalMap'
 * '<S287>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Neg/SportMap'
 * '<S288>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Pos/EVMap'
 * '<S289>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Pos/EVSportMap'
 * '<S290>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Pos/NormalMap'
 * '<S291>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Braking_Pos/SportMap'
 * '<S292>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Power_Neg/EVMap'
 * '<S293>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Power_Neg/EVSportMap'
 * '<S294>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Power_Neg/NormalMap'
 * '<S295>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/FirstOrderFilter/Power_Neg/SportMap'
 * '<S296>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Enumerated Constant'
 * '<S297>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Enumerated Constant1'
 * '<S298>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Neg'
 * '<S299>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Pos'
 * '<S300>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Neg/EVMap'
 * '<S301>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Neg/EVSportMap'
 * '<S302>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Neg/NormalMap'
 * '<S303>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Neg/SportMap'
 * '<S304>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Pos/EVMap'
 * '<S305>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Pos/EVSportMap'
 * '<S306>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Pos/NormalMap'
 * '<S307>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/ParabolicFilter/Parabola_Pos/SportMap'
 * '<S308>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/SecondOrderFilter/Enumerated Constant'
 * '<S309>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/SecondOrderFilter/Power_Pos'
 * '<S310>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/SecondOrderFilter/Power_Pos/EVMap'
 * '<S311>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/SecondOrderFilter/Power_Pos/EVSportMap'
 * '<S312>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/SecondOrderFilter/Power_Pos/NormalMap'
 * '<S313>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/Parameters/SecondOrderFilter/Power_Pos/SportMap'
 * '<S314>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/SafetyLimit/MaxLimit'
 * '<S315>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/SafetyLimit/MinLimit'
 * '<S316>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection'
 * '<S317>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TorqueRange'
 * '<S318>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TorqueRangesDefinition'
 * '<S319>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/SR_latch'
 * '<S320>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/SR_latch1'
 * '<S321>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/turnON_delay1'
 * '<S322>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/turnON_delay2'
 * '<S323>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/turnON_delay3'
 * '<S324>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/turnON_delay4'
 * '<S325>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/turnON_delay1/timed_delay'
 * '<S326>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/turnON_delay2/timed_delay'
 * '<S327>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/turnON_delay3/timed_delay'
 * '<S328>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandFiltering/TorqueRange/TipInDetection/turnON_delay4/timed_delay'
 * '<S329>' : 'swc_TCOO/TCOO_Torque_Coordinator/TDA_TorqueDemandsArbitration/TorqueDemandLimitation/saturation_dynamic'
 * '<S330>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_Torque_Distribution'
 * '<S331>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution'
 * '<S332>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/RegenerativeBrakeTorqueCapacityCalc'
 * '<S333>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/model_info1'
 * '<S334>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_Torque_Distribution/saturation_dynamic8'
 * '<S335>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq'
 * '<S336>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/FAD_RAD_Split'
 * '<S337>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/saturation_dynamic5'
 * '<S338>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/AbsOvrdCtrlTrqDem'
 * '<S339>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant'
 * '<S340>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant1'
 * '<S341>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant10'
 * '<S342>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant11'
 * '<S343>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant2'
 * '<S344>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant20'
 * '<S345>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant3'
 * '<S346>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant4'
 * '<S347>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant5'
 * '<S348>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant6'
 * '<S349>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant7'
 * '<S350>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant8'
 * '<S351>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Compare To Constant9'
 * '<S352>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBAccOvrdCtrl'
 * '<S353>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg'
 * '<S354>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/Enumerated Constant2'
 * '<S355>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/SwitchRampEADShiftIntvn'
 * '<S356>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/AbsOvrdCtrlTrqDem/Compare To Constant10'
 * '<S357>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/AbsOvrdCtrlTrqDem/Compare To Constant11'
 * '<S358>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/AbsOvrdCtrlTrqDem/Compare To Constant12'
 * '<S359>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBAccOvrdCtrl/Compare To Constant1'
 * '<S360>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBAccOvrdCtrl/Compare To Constant16'
 * '<S361>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBAccOvrdCtrl/Compare To Constant17'
 * '<S362>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBAccOvrdCtrl/Compare To Constant21'
 * '<S363>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBAccOvrdCtrl/Compare To Constant25'
 * '<S364>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl'
 * '<S365>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd'
 * '<S366>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt'
 * '<S367>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType'
 * '<S368>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant1'
 * '<S369>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant10'
 * '<S370>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant11'
 * '<S371>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant12'
 * '<S372>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant14'
 * '<S373>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant15'
 * '<S374>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant16'
 * '<S375>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant17'
 * '<S376>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant18'
 * '<S377>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant19'
 * '<S378>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant2'
 * '<S379>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant21'
 * '<S380>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant25'
 * '<S381>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant26'
 * '<S382>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant27'
 * '<S383>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant28'
 * '<S384>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant29'
 * '<S385>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant3'
 * '<S386>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant30'
 * '<S387>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant4'
 * '<S388>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant5'
 * '<S389>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant51'
 * '<S390>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant52'
 * '<S391>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant53'
 * '<S392>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant54'
 * '<S393>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant6'
 * '<S394>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant7'
 * '<S395>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant8'
 * '<S396>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbOvrCtrl/Compare To Constant9'
 * '<S397>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant10'
 * '<S398>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant13'
 * '<S399>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant14'
 * '<S400>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant16'
 * '<S401>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant17'
 * '<S402>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant4'
 * '<S403>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant46'
 * '<S404>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant47'
 * '<S405>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant48'
 * '<S406>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant49'
 * '<S407>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant50'
 * '<S408>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/Compare To Constant9'
 * '<S409>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/EhbVlcGpOvrd/SR_latch'
 * '<S410>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt/Compare To Constant20'
 * '<S411>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt/Compare To Constant22'
 * '<S412>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt/Compare To Constant23'
 * '<S413>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt/Compare To Constant24'
 * '<S414>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt/Compare To Constant31'
 * '<S415>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt/Compare To Constant32'
 * '<S416>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt/Compare To Constant33'
 * '<S417>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/accPedlPosVirt/Compare To Constant34'
 * '<S418>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant1'
 * '<S419>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant14'
 * '<S420>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant16'
 * '<S421>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant35'
 * '<S422>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant36'
 * '<S423>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant37'
 * '<S424>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant38'
 * '<S425>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant39'
 * '<S426>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant40'
 * '<S427>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant41'
 * '<S428>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant42'
 * '<S429>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant43'
 * '<S430>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant44'
 * '<S431>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant45'
 * '<S432>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/EHBOvrdCtrlEnbFlg/ehbTrqOvrdType/Compare To Constant55'
 * '<S433>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/SwitchRampEADShiftIntvn/switch_ramp'
 * '<S434>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/Front_Rear_Axle_VSC_Torque_Intervention_Distribution/EHBOverCtrlAxle2TgtTrq/SwitchRampEADShiftIntvn/switch_ramp/Chart'
 * '<S435>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/RegenerativeBrakeTorqueCapacityCalc/SwitchRampMot2RegenBrkLim'
 * '<S436>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/RegenerativeBrakeTorqueCapacityCalc/SwitchRampMot2RegenBrkLim/switch_ramp'
 * '<S437>' : 'swc_TCOO/TCOO_Torque_Coordinator/TQD_TorqueDistribution/RegenerativeBrakeTorqueCapacityCalc/SwitchRampMot2RegenBrkLim/switch_ramp/Chart'
 * '<S438>' : 'swc_TCOO/TCOO_Torque_Coordinator/TVR_TorqueVectorControl/MotorSwitchOffTq'
 * '<S439>' : 'swc_TCOO/TCOO_Torque_Coordinator/TVR_TorqueVectorControl/SwitchRampMot2TrqDem'
 * '<S440>' : 'swc_TCOO/TCOO_Torque_Coordinator/TVR_TorqueVectorControl/model_info1'
 * '<S441>' : 'swc_TCOO/TCOO_Torque_Coordinator/TVR_TorqueVectorControl/MotorSwitchOffTq/Detect Increase'
 * '<S442>' : 'swc_TCOO/TCOO_Torque_Coordinator/TVR_TorqueVectorControl/SwitchRampMot2TrqDem/switch_ramp'
 * '<S443>' : 'swc_TCOO/TCOO_Torque_Coordinator/TVR_TorqueVectorControl/SwitchRampMot2TrqDem/switch_ramp/Chart'
 */
#endif                                 /* RTW_HEADER_swc_TCOO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
