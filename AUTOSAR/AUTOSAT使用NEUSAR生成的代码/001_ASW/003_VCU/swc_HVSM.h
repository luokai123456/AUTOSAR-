/*
 * File: swc_HVSM.h
 *
 * Code generated for Simulink model 'swc_HVSM'.
 *
 * Model version                  : 6.239
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Sep 18 14:26:04 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_HVSM_h_
#define RTW_HEADER_swc_HVSM_h_
#ifndef swc_HVSM_COMMON_INCLUDES_
#define swc_HVSM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_HVSM.h"
#endif                                 /* swc_HVSM_COMMON_INCLUDES_ */

#include "Rte_Type.h"
#include "Platform_Types.h"
#include "enum_Type.h"
#include "Rte_swc_rte_dem.h"
#include "Aes_Encypt.h"
#include "AES_Lib.h"

/* Includes for objects with custom storage classes */
#include "const_ImportedDefine.h"

/* user code (top of header file) */
#include "Platform_Types.h"
#include "enum_Type.h"
#include "Rte_swc_rte_dem.h"
#include "Aes_Encypt.h"
#include "AES_Lib.h"
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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_EGYM_
#define DEFINED_TYPEDEF_FOR_vcsb_EGYM_

typedef struct {
  uint8 emgd_st_gearDmd;
  float32 accd_pwr_maxPwrLim_kW;
  float32 accd_pwr_minPwrLim_kW;
  float32 dccd_i_outCurrMaxLim_A;
  float32 dccd_i_inpCurrMaxLim_A;
  float32 dccd_u_outVoltSetP_V;
  float32 emgd_n_engSpdTgtSHEVMode_rpm;
  float32 emgd_tq_crsMSGChgDem_Nm;
  float32 emgd_tq_whlEAD2ChgDem_Nm;
  float32 emgd_tq_trsm1ClthTMMChgDem_Nm;
  float32 emgd_tq_whlEAD1ChgDem_Nm;
  float32 emgd_n_engSpdTgtPHEVIdleMode_rpm;
  float32 emgd_tq_trsm1ClthTMMPHEVMode_Nm;
  float32 accd_pwr_hvAttpwr_kW;
  boolean egmd_b_dcdcEnbAllowFlg;
  boolean egmd_b_ptcEnbAllowFlg;
  boolean egmd_b_acEnbAllowFlg;
  boolean egmd_b_mcuEnbFlg;
  float32 egmd_pwr_accmHvClPwrAllwd_kW;
  float32 egmd_pwr_ptcHvHtPwrAllwd_kW;
  float32 egmd_pwr_mcuHvAttpwr_kW;
  float32 egmd_i_bmshAlwChgCurrMax;
  uint8 egmd_pct_vcuChgDepReq;
  uint8 egmd_st_vcuChgLimResp;
  boolean egmd_b_obcEnbAllowFlg;
  boolean egmd_b_ptcRearEnbAllowFlg;
  boolean egmd_b_zeroPwrFb;
  boolean egmd_b_accyEnbFlg;
  float32 egmd_pwr_acwpHeatPwrCnsAllwd;
} vcsb_EGYM;

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

#ifndef DEFINED_TYPEDEF_FOR_vcob_VCOP_
#define DEFINED_TYPEDEF_FOR_vcob_VCOP_

typedef struct {
  uint8 PMS_IsgModReq;
  uint8 PMS_FrntHeatPwrAllwd;
  boolean FrntHeatModEnad;
  boolean PMS_MCUActvdReq;
  uint16 PMS_IsgTqReq;
  uint8 PMS_Command_AliveCounter_EV;
  uint8 PMS_Command_Checksum_EV;
  uint8 VCU_BMSH_StsModeReq;
  uint8 VCU_BMSH_DCChgRelayVolt;
  uint8 VCU_CrashOutputSts;
  uint16 VCU_ActInputVolt;
  uint8 VCU_BMSH_Ctrl_AliveCounter;
  uint8 VCU_BMSH_Ctrl_CheckSum;
  uint8 PMS_DCDCCutOffLV;
  boolean PMS_DcDcActvdReq;
  uint8 PMS_DCDCPwrLmt;
  uint8 PMS_DCDC_Ctrl_AliveCounter;
  uint8 PMS_DCDC_Ctrl_Checksum;
  boolean PMS_ePTReady_EV;
  uint8 VCU_BMSH_AllowChgCurrentMax;
  uint8 VCU_ChargeDepthReq;
  uint8 VCU_VehicleInfo_AliveCounter;
  uint8 VCU_VehicleInfo_CheckSum;
  uint16 VCU_Odometerbackup_EV;
  uint8 PEPS_PowerModeValidity;
  uint8 PEPS_PowerMode;
  uint16 EHB_VehicleSpeed;
  boolean EHB_VehicleSpeedInvalid;
  uint8 EGSM_Status_AliveCounter_EV;
  uint8 EGSM_Status_Checksum_EV;
  uint8 PMS_SlidingmomentrSetReq;
  uint8 PMS_Command_AliveCounter;
  uint8 PMS_Command_Checksum;
  uint16 PMS_RegenTrqPot;
  uint16 PMS_RegenTrqAct;
  boolean PMS_EPBClosedReq;
  boolean PMS_DriverGearAbort;
  boolean PMS_RegenTarTrqPotQualifier;
  boolean PMS_RegenTrqActQualifier;
  boolean PMS_RegenTrqPotQualifier;
  boolean PMS_AccelPedalPositionInvalid;
  uint8 PMS_AccelPedalPosition;
  uint16 PMS_RegenTarTrqPot;
  uint8 PMS_CSControl2_AliveCounter;
  uint8 PMS_CSControl2_CheckSum;
  uint8 PMS_DriveModeInd;
  uint8 PMS_VehicleSysErrorLevel;
  uint8 PMS_GearOperateErr;
  boolean PMS_BrkSysErr;
  uint8 PMS_ePTModeSelect;
  uint8 PMS_ePTModeActual;
  boolean PMS_DriverRemind;
  boolean PMS_ChargerFault;
  boolean PMS_ePTReady;
  uint8 PMS_ePTReleaseSig;
  uint8 PMS_ePTRegencyLevInd;
  boolean PMS_DoubleFlashLampOn;
  boolean PMS_TurtleLampOn;
  boolean PMS_ePTFault;
  uint8 PMS_Ctrl_AliveCounter;
  uint8 PMS_Ctrl_Checksum;
  uint8 PMS_Real_PedalPosition;
  uint8 PMS_ModeGearDisplaySts;
  uint8 PMS_ADCCtrlSts;
  boolean PMS_CANBus_RecSta;
  uint8 PMS_ACC_BeControlled_Status;
  uint8 PMS_CurrentGearPosition;
  boolean PMS_CurrentGearPosition_Valid;
  boolean PMS_Gear_intervene;
  uint8 PMS_ChargeHV_Status;
  boolean PMS_APA_BeControlled_Status;
  boolean PMS_Real_PedalPositionInvalid;
  uint8 PMS_ModeControl_AliveCounter;
  uint8 PMS_ModeControl_CheckSum;
  uint16 PMS_ActualPTTorque;
  uint16 PMS_DriverDemandTorque;
  boolean PMS_GP_Ovrd;
  boolean PMS_ActualPTTorqueInvalid;
  boolean PMS_DriverDemandTorqueInvalid;
  uint8 PMS_VacuumSystemsta;
  uint16 PMS_VacuumPressure;
  uint8 PMS_EngTrqReqSrc;
  boolean PMS_LimpHomeSts;
  uint8 PMS_EngControl_AliveCounter;
  uint8 PMS_EngControl_CheckSum;
  uint16 PMS_MinPTTorqueAllowed;
  uint16 PMS_MaxPTTorqueAllowed;
  boolean PMS_StartActive;
  uint8 PMS_CruiseControlSts;
  boolean PMS_CruiseSwitchSts;
  uint8 PMS_ControlSetSpeed;
  uint8 PMS_DM_FailureReasonAndSysFaultFBK;
  uint8 PMS_CSControl1_AliveCounter;
  uint8 PMS_CSControl1_CheckSum;
  uint16 PMS_EVDTEodometer;
  uint16 PMS_PTResiduePwrInd;
  uint8 PMS_EpedalActive;
  uint8 PMS_EPedlDrvrIndcnMsg;
  uint16 DrvPfmncRedn;
  uint8 PMS_DrvrGearLvrLockIndcn;
  boolean PMS_HvBattCooltLvl;
  uint8 PMS_V2XDchaSwtFb1;
  uint16 PMS_BookChrgnTarValFb;
  uint16 PMS_DchaEgyAct;
  uint16 PMS_DchaEgyStrg;
  uint8 PMS_ACCMEnable;
  uint8 PMS_PTCEnable;
  uint8 BMSH_HvBattThermMod;
  uint8 PMS_CoolingFanPWMSpd;
  uint8 PMS_HvCoolgPwrAllwd;
  uint8 BMSH_Inlet_WaterTemp;
  uint8 BMSH_Outlet_WaterTemp;
  uint8 BMSH_HvBattCooltTReq;
  uint8 PMS_DriveCircuitTemp;
  uint8 PMS_HvHeatgPwrAllwd;
  uint8 PMS_LTCoolingFanFB;
  uint8 PMS_AuthResult;
  uint8 PMS_RespResult;
  uint64 PMS_ReqSeed;
  uint8 PMS_ExecuteLockVehResults;
  uint8 PMS_LockVehSts;
  uint8 PMS_FunLockVehActive;
  uint8 PMS_FunAnti_DismantleActive;
  uint8 PMS_LockVehType;
  uint8 PMS_LockLimResult;
  uint8 PMS_IntelligentChargeState;
  uint8 PMS_IntelligentChargeQuit;
  uint8 PMS_IntelligentChargeExitReq;
  boolean PMS_TBOX_HVILState;
  uint16 PMS_Odometerbackup;
  uint8 BMSH_BattSOH;
  uint16 BMSH_BattCurr;
  uint16 BMSH_HVBusVolt;
  boolean BMSH_HvShutdownReq;
  uint16 BMSH_BattVolt;
  uint8 BMSH_VoltCurr_AliveCounter;
  uint8 BMSH_VoltCurr_Checksum;
  uint16 BMSH_BattRemainEnergy;
  uint16 BMSH_BattSOC;
  uint8 BMSH_Cell_TotalNum;
  uint8 BMSH_Battery_Performance_AliveCounter;
  uint8 BMSH_Battery_Performance_Checksum;
  uint8 IPU_BattFaultLampState;
  uint16 IPU_IsgTqActIsgTqAct;
  uint16 IPU_IsgSpdActSgn;
  uint8 IPU_IsgModSts;
  uint8 IPU_TrqSpd_AliveCounter;
  uint8 IPU_TrqSpd_CheckSum;
  boolean ODP_DcDcStsAlm;
  uint8 ODP_DCDC_stCtrl;
  uint8 BMSH_BattFaultLampState;
  boolean BMSH_Vehicle_HVILSts_PHEV;
  uint8 BMSH_stMode;
  uint8 BMSH_FastChgCC2ConntState;
  uint16 BMSH_ACChgTimeRemain;
  boolean BMSH_ThermalOutofControl;
  boolean BMSH_ChargeToBeFinished;
  uint8 BMSH_BattTempAvg;
  uint8 BMSH_TempSensor_MaxTemp;
  uint8 BMSH_TempSensor_MinTemp;
  uint8 BMSH_ChargeLEDCtrl;
  uint8 BMSH_Charge_Over_Current;
  uint8 BMSH_InsulationRes_Fault;
  uint8 BMSH_DCChgminusSocketTempSensing_Failure;
  uint8 BMSH_DCChgplusSocketTempSensing_Failure;
  uint16 BMSH_ChgTimeRemain;
  boolean IPU_IsgOverTemp;
  uint64 PMS_PEPSAuth;
  uint8 EGSM_ParkReq;
  uint8 EGSM_ShiftleverFailSt;
  uint8 EGSM_LeverPosition;
  uint8 EGSM_Status_AliveCounter;
  uint8 EGSM_Status_Checksum;
  uint8 PMS_EDCPEnable;
  uint8 PMS_HBCPEnable;
  uint8 PMS_EDCPPWMCtrl;
  uint8 PMS_HBCPPWMCtrl;
  uint8 EDCP_Flt;
  uint8 EDCP_FltLevel;
  uint8 EDCP_State;
  uint8 EDCP_PWMFB;
  uint8 HBCP_Flt;
  uint8 HBCP_FltLevel;
  uint8 HBCP_State;
  uint8 HBCP_PWMFB;
  uint8 PMS_MHGV_PosSet;
  boolean PMS_MHGV_EnableReq;
  boolean PMS_MHGV_ReqMotorEmgyStop;
  boolean PMS_MHGV_ReqMotorOptRecovery;
  boolean PMS_FWFV_MoveEnable;
  uint8 PMS_FWFV_ReqMovePos;
  boolean MHGV_RESP_ERROR;
  boolean MHGV_OverVoltageFlt;
  boolean MHGV_OverCurrentFlt;
  boolean MHGV_OverTempFlt;
  boolean MHGV_UnderVoltageFlt;
  boolean MHGV_InitState;
  boolean MHGV_CCWFlg;
  boolean MHGV_MotorState;
  uint8 MHGV_CurrentPos;
  boolean FWFV_RESP_ERROR;
  boolean FWFV_OverVoltageFlt;
  boolean FWFV_OverCurrentFlt;
  boolean FWFV_OverTempFlt;
  boolean FWFV_UnderVoltageFlt;
  boolean FWFV_InitState;
  boolean FWFV_CCWFlg;
  boolean FWFV_MotorState;
  uint8 FWFV_CurrentPos;
  boolean O_S_PIN88;
  boolean O_S_PIN83;
  boolean O_S_PIN89;
  boolean O_S_PIN110;
  uint16 O_T_PIN82_Duty;
  uint32 O_T_PIN82_Period;
  uint16 O_T_PIN118_Duty;
  uint32 O_T_PIN118_Period;
  uint16 O_T_PIN77_Duty;
  uint32 O_T_PIN77_Period;
  uint16 O_T_PIN104_Duty;
  uint32 O_T_PIN104_Period;
  uint16 O_T_PIN103_Duty;
  uint32 O_T_PIN103_Period;
  uint16 O_T_PIN14_Duty;
  uint16 O_T_PIN28_Duty;
  uint32 O_T_PIN14_Period;
  uint32 O_T_PIN28_Period;
  uint8 st_ShtDown;
  uint8 PMS_MHGV_PosSet_LIN;
  boolean PMS_MHGV_EnableReq_LIN;
  boolean PMS_MHGV_ReqMotorEmgyStop_LIN;
  boolean PMS_MHGV_ReqMotorOptRecovery_LIN;
  boolean PMS_FWFV_MoveEnable_LIN;
  uint8 PMS_FWFV_ReqMovePos_LIN;
  boolean PMS_TBOX_HVILState_3A1;
  uint8 PMS_AppSts;
  boolean PMS_HVIL1Sts_EV;
  boolean PMS_HVIL1Sts_UB_EV;
  boolean PMS_HVIL2Sts_EV;
  boolean PMS_HVIL2Sts_UB_EV;
  uint8 PMS_SelfCheckSts_EV;
  uint8 PMS_CurrentGearPosition_EV;
  boolean PMS_CurrentGearPosition_Valid_EV;
  boolean PMS_HVILSts_EV;
  boolean PMS_HVILSts_UB_EV;
  uint8 PMS_DriveCircuitTemp_EV;
  uint8 PMS_EDCPEnable_EV;
  uint8 PMS_EDCPPWMCtrl_EV;
  uint8 VCU_DCInputCurrent_EV;
  uint8 PMS_ThermalReq;
  uint8 PMS_IsgActvDampgModReq_EV;
  uint8 PMS_PTCEnable_EV;
  uint8 IPK_Second_EV;
  uint8 IPK_Minute_EV;
  uint8 IPK_Hour_EV;
  uint8 IPK_Day_EV;
  uint8 IPK_Month_EV;
  uint8 IPK_Year_EV;
  uint16 EHB_FLWheelSpeedKPH_EV;
  boolean EHB_FLWheelSpeedInvalid_EV;
  uint8 EHB_FLWheelDirection_EV;
  uint16 EHB_FRWheelSpeedKPH_EV;
  boolean EHB_FRWheelSpeedInvalid_EV;
  uint8 EHB_FRWheelDirection_EV;
  uint8 EHB_FrontWheelSpeedsKPH_AliveCounter_EV;
  uint8 EHB_FrontWheelSpeedsKPH_CheckSum_EV;
  uint16 EHB_RLWheelSpeedKPH_EV;
  boolean EHB_RLWheelSpeedInvalid_EV;
  uint8 EHB_RLWheelDirection_EV;
  uint16 EHB_RRWheelSpeedKPH_EV;
  boolean EHB_RRWheelSpeedInvalid_EV;
  uint8 EHB_RRWheelDirection_EV;
  uint8 EHB_RearWheelSpeedsKPH_AliveCounter_EV;
  uint8 EHB_RearWheelSpeedsKPH_CheckSum_EV;
  boolean PMS_IgnONSts_EV;
  uint8 PMS_ACC1PosVol_EV;
  uint8 PMS_ACC2PosVol_EV;
  uint8 PMS_BatteryVol_EV;
  uint8 PMS_HVPRASts_EV;
  uint8 PMS_AppSts_EV;
  uint8 PMS_HBCP_PWMCtrl_EV;
  uint8 PMS_ChargWakeupSts_EV;
  uint8 PMS_EDCP_PWMCtrl_EV;
  uint8 PMS_HBCP_FaultFB_EV;
  uint8 PMS_EDCP_FaultFB_EV;
  uint8 PMS_BattPackInCoolTempback_EV;
  uint8 PMS_BattPackOutCoolTempback_EV;
  uint8 PMS_CPSRU_EV;
  uint8 PMS_FAN_PWMCtrl_EV;
  uint8 PMS_DDwaterPump_PWMCtrl_EV;
  uint8 PMS_VacuumPump_FB_EV;
  uint16 PMS_VehicleSpeed_EV;
  boolean PMS_CPSREn_EV;
  boolean PMS_VacuumPumpCmd_EV;
  boolean PMS_VehicleSpeedInvalid_EV;
  uint8 PMS_MCUTemp_EV;
  boolean PMS_HVILSts;
  boolean PMS_HVILSts_UB;
  uint8 BMSH_TempSensor_TotalNum;
  uint8 IsgTqActCntr;
  boolean IsgTqAct_UB;
  boolean IsgCluSts_UB;
  uint8 IsgTqActChks;
  uint8 IsgTqActQualityFactor;
  uint16 IsgTqActIsgTqAct;
  uint8 IsgModSts;
  boolean IsgModSts_UB;
  uint8 IsgCluSts;
  boolean IsgSpdActSgn_UB;
  uint16 IsgSpdActSgn;
  uint8 PMS_MCUFlowFeedback_EV;
  uint16 SAS_SteerWheelAngle_EV;
  uint8 SAS_Status_AliveCounter_EV;
  uint8 SAS_Status_CheckSum_EV;
  uint64 PMS_SwapAuth_EV;
  uint8 EHB_Mcylinder_Pressure_EV;
  boolean EHB_Mcylinder_PressureInvalid_EV;
  uint8 EHB_EPBStatus_EV;
  uint8 EHB_Status_AliveCounter_EV;
  uint8 EHB_Status_Checksum_EV;
  sint16 PMS_EPS_SteeringAngleValue_EV;
  boolean PMS_EPS_SteeringAngleValueInvalid_EV;
  uint8 PMS_EPS_SystemSts_AliveCounter_EV;
  uint8 PMS_EPS_SystemSts_CheckSum_EV;
  uint8 PMS_DischargeEnable_EV;
  boolean PMS_0X16A_TimeoutFlag_EV;
  uint8 PMS_ModeGearDisplaySts_EV;
  uint8 PMS_ModeControl_AliveCounter_EV;
  uint8 PMS_ModeControl_CheckSum_EV;
  boolean PMS_StsBrkSwitch1_EV;
  uint8 PMS_StsSwapFault_EV;
  uint8 PMS_SwapAuthRelease_EV;
  uint8 PMS_StsSwap_EV;
  boolean PMS_PackTypeUnmatch_EV;
  uint8 PMS_StsSwap_AliveCounter_EV;
  uint8 PMS_StsSwap_CheckSum_EV;
  boolean PMS_IPK_HandBrakeSts_EV;
  boolean BCM_Central_Lock_CMD_EV;
  boolean BCM_Central_unLock_CMD_EV;
  boolean BCM_FrontLeftDoorAjarStatus_EV;
  uint8 BCM_DoorLockStatusDrv_EV;
  boolean BCM_FrontRightDoorAjarStatus_EV;
  uint8 BCM_DoorLockStatusPass_EV;
  boolean AC_AmbientTemperatureInvalid_EV;
  uint8 AC_AmbientTemperature_EV;
  uint16 PMS_BMSH_BattSOCDisp_EV;
  uint8 PMS_PEPS_PowerModeValidity_EV;
  uint8 PMS_PEPS_PowerMode_EV;
  boolean PEPS_RemoteControlSt_EV;
  boolean PEPS_EngForbidWarn_EV;
  boolean PEPS_EngineforbidSt_EV;
  boolean PMS_PEPS_0x1E2_TimeoutFlag_EV;
  uint16 PMS_BMSH_BattSOH_EV;
  uint16 PMS_BMSH_BattRemainEnergy_EV;
  uint16 BMSH_ICU_BatteryElectricDTE;
  uint8 BMSH_PackCode_ID;
  uint8 BMSH_PackCode1;
  uint8 BMSH_PackCode2;
  uint8 BMSH_PackCode3;
  uint8 BMSH_PackCode4;
  uint8 BMSH_PackCode5;
  uint8 BMSH_PackCode6;
  uint8 BMSH_PackCode7;
  uint8 BMSH_BatSwapPosTemp;
  uint8 BMSH_BatSwapNegTemp;
  uint8 BMSH_DisChgOverCurrent;
  uint8 BMSH_MainPosRelayFault;
  uint8 BMSH_MainNegRelayFault;
  uint8 BMSH_DCChgRelayFault;
  boolean BMSH_TBOX_BatStoreSysFault;
  boolean BMSH_TBOX_BatLowTemp;
  uint8 BMSH_VCU_StsMainHVIL;
  uint8 VCU_PMS_APPowerActual_EV;
  uint8 BMS_CellVoltFrameNum;
  uint8 BMS_VoltCellNum;
  uint16 BMS_CellVoltN1;
  uint16 BMS_CellVoltN2;
  uint16 BMS_CellVoltN3;
  uint8 IsgTqActCntr_ADC;
  boolean IsgTqAct_UB_ADC;
  boolean IsgCluSts_UB_ADC;
  uint8 IsgTqActChks_ADC;
  uint8 IsgTqActQualityFactor_ADC;
  uint16 IsgTqActIsgTqAct_ADC;
  uint8 IsgModSts_ADC;
  boolean IsgModSts_UB_ADC;
  uint8 IsgCluSts_ADC;
  boolean IsgSpdActSgn_UB_ADC;
  uint16 IsgSpdActSgn_ADC;
  uint8 PMS_BMS_ReignLockSts;
  boolean PMS_DcDc1ActvdReq_EV;
  uint8 PMS_Wakeup_reasons;
  boolean PMS_NMSts;
  uint32 PMS_Stayawake_reasons;
  uint8 PMS_BMS_Reignstatus1;
  uint8 PMS_BMS_Reignstatus2;
  uint8 PMS_ChargeLimitResponse;
  uint16 BMSH_InsulationRes;
  uint16 IPU_HVBusVolt;
  uint16 IPU_HVBusCur;
  uint8 BMS_MaxVoltCellNum;
  uint8 BMS_MinVoltCellNum;
  uint16 BMS_MaxCellVolt;
  uint16 BMS_MinCellVolt;
  uint8 BMS_MaxTemp1SnsNum;
  uint8 BMS_MinxTemp1SnsNum;
  uint8 BMSH_Over_SOC;
  boolean BMSH_SOC_Hop;
  uint8 BMSH_Low_SOC;
  boolean BMSH_CellTemp_Uniformity;
  uint8 BMSH_Cell_UnderVol;
  uint8 BMSH_Cell_OverVol;
  uint8 BMSH_Pack_UnderVoltage;
  uint8 BMSH_Pack_OverVoltage;
  uint8 BMSH_Over_Temperature;
  uint8 BMSH_CellVolt_Uniformity;
  boolean IPU_IPUTAlm;
  boolean PMS_StsBrkSwitch1_PMS;
  boolean PMS_StsBrkSwitch1Invalid_PMS;
  uint8 PMS_LockVehPerFlag_PMS;
  uint8 PMS_VersionConversionFlag_PMS;
  uint8 PMS_SpdLmtLevel_PMS;
  uint8 PMS_InventorySpdLmtSts_PMS;
  uint8 PMS_StartBattChgRes_PMS;
  uint8 PMS_Life_PMS;
  uint8 PMS_VehicleSysErrorLevelG_PMS;
  boolean ODP_TBOX_TDcDcAlm_PMS;
  boolean ODP_TBOX_DcDcStsAlm_PMS;
  boolean IPU_MotorTempHighFault1_PMS;
  boolean IPU_MCUTempHighAlarm1_PMS;
  boolean BMSH_TBOX_BatTempUniformity2_PMS;
  boolean BMSH_TBOX_BatOverSOC2_PMS;
  boolean BMSH_TBOX_SOCHop2_PMS;
  boolean BMSH_TBOX_BatLowSOC2_PMS;
  boolean BMSH_TBOX_BatOverCharge2_PMS;
  boolean BMSH_TBOX_BatUniformity2_PMS;
  boolean BMSH_TBOX_CellUnderVoltage2_PMS;
  boolean BMSH_TBOX_BatUnderVoltage2_PMS;
  boolean BMSH_TBOX_BatOverTemp2_PMS;
  boolean BMSH_TBOX_BatIsoAlarm2_PMS;
  boolean BMSH_TBOX_BatOverVoltage2_PMS;
  boolean BMSH_TBOX_CellOverVoltage2_PMS;
  boolean BMS_BattPackMatchFault_PMS;
  boolean PMS_TBOX_BrkSysErr_PMS;
  boolean PMS_TBOX_HVILSts_PMS;
  boolean PMS_StsBrkSwitch1Invalid_EV;
  boolean PMS_AccessoryCtrlCommand_EV;
  boolean PMS_PTC2Enable_EV;
  boolean PMS_PTC3Enable_EV;
  boolean PMS_BatCoolType_EV;
  boolean PMS_ZeroPwr_Fb_EV;
  boolean PMS_DisChrgrSwtSt_EV;
  boolean PMS_CruisingDstSwtFb_EV;
  uint8 PMS_VINMessageNum_S_EV;
  uint8 PMS_VINCode1_8_15_S_EV;
  uint8 PMS_VINCode2_9_16_S_EV;
  uint8 PMS_VINCode3_10_17_S_EV;
  uint8 PMS_VINCode4_11_S_EV;
  uint8 PMS_VINCode5_12_S_EV;
  uint8 PMS_VINCode6_13_S_EV;
  uint8 PMS_VINCode7_14_S_EV;
  uint8 PMS_EngRecMode_Fb_EV;
  uint8 AC_BMSH_ThermReqFb_EV;
  uint8 PMS_StsBatLockSensor_EV;
  boolean PMS_DCDCAwake_HW_EV;
  uint8 PMS_CoolingFanFaultFB_PMS;
  uint16 PMS_ErrCode_PMS;
  uint16 PMS_GrossComVehWeight_PMS;
  uint8 PMS_OverloadInd_PMS;
  float32 EXT_PO_PWM_1_DutyCycle;
  float32 EXT_PO_PWM_2_DutyCycle;
  float32 EXT_PO_HVIL_1_DutyCycle;
  boolean EXT_DO_RELAY_LS_10;
  boolean EXT_DO_RELAY_LS_9;
  boolean EXT_DO_RELAY_LS_12;
  float32 EXT_PO_PWM_4_DutyCycle;
  boolean EXT_DO_KEY_HS_05;
  boolean EXT_DO_RELAY_LS_7;
  float32 EXT_PO_PWM_1_Period;
  float32 EXT_PO_PWM_2_Period;
  float32 EXT_PO_PWM_4_Period;
  float32 EXT_PO_HVIL_1_Period;
  boolean EXT_DO_RELAY_HS_11;
  uint8 PMS_PTC1ConnStsFb_EV;
  uint8 PMS_PTC1RelayFlt_EV;
  uint8 PMS_PTC3ConnStsFb_EV;
  uint8 PMS_PTC3RelayFlt_EV;
  uint8 PMS_AccessoryConnStsFb_EV;
  uint8 PMS_AccessoryRelayFlt_EV;
  uint8 PMS_PreAccessoryConnStsFb_EV;
  uint8 PMS_PreAccessoryRelayFlt_EV;
  boolean EXT_DO_RELAY_HS_9;
  boolean EXT_DO_RELAY_HS_8;
  boolean EXT_DO_RELAY_HS_6;
  uint8 PMS_PTCRelayVoltSampSwich;
  uint8 PMS_AcceRelayVoltSampSwich;
  boolean PMS_BBM_FaultStatus_EV;
  boolean PMS_BBM_WorkSts_EV;
  uint8 PMS_DrivingTakeEleSts_EV;
  boolean PMS_BBMPowerSupplyEn_Ctrl_EV;
  boolean O_S_PIN123;
  boolean O_S_PIN98;
  boolean EXT_DO_KEY_HS_03;
  boolean PMS_BBMAllowEnable_Ctrl_EV;
  uint8 PMS_BBM1CtrlCmd_EV;
  boolean PMS_BBM_HVReq_EV;
  boolean PMS_StsBrkSwitch2;
  uint32 IPK_IPKTotalOdometer_EV;
  uint8 VCU_BMSH_Inlet_WaterTemp_EV;
  uint8 VCU_BMSH_Outlet_WaterTemp_EV;
  boolean VCU_EVCAN_InhibitFBL_EV;
  boolean VCU_BMSH_FaultResetReq_EV;
  uint8 VCU_ChargeModeReq_EV;
  uint8 VCU_EVCAN_StsSwap_EV;
  uint8 PMS_LockVehPerRxSts_PMS;
  uint8 PMS_VersionConversionRxSts_PMS;
  uint8 PMS_SpdLmtLevelRxSts_PMS;
  uint8 PMS_InventorySpdLmtRxSts_PMS;
  uint8 PMS_TBOX_LifeSts_PMS;
  uint16 PMS_AveragePowerConsumption;
  boolean PMS_0X16A_TimeoutFlag_PMS;
  uint16 PMS_VehicleSpeed_PMS;
  boolean PMS_VehicleSpeedInvalid_PMS;
  uint16 PMS_AveragePowerConsumption_PMS;
  uint8 PMS_PreAccessoryCtrl_EV;
  uint16 PMS_EVDTEodometer_EV;
  uint8 PMS_LockVehExecutedSts_PMS;
  uint16 PMS_ChargPwr_PMS;
  uint8 PMS_VINMessageNum_S_PMS;
  uint8 PMS_VINCode1_8_15_S_PMS;
  uint8 PMS_VINCode2_9_16_S_PMS;
  uint8 PMS_VINCode3_10_17_S_PMS;
  uint8 PMS_VINCode4_11_S_PMS;
  uint8 PMS_VINCode5_12_S_PMS;
  uint8 PMS_VINCode6_13_S_PMS;
  uint8 PMS_VINCode7_14_S_PMS;
  uint8 PMS_HardwareMajorVer_PMS;
  uint8 PMS_HardwareMinorVer_PMS;
  uint8 PMS_SoftwareMajorVer_PMS;
  uint8 PMS_SoftwareMinorVer_PMS;
  uint8 PMS_SWCompileYear_PMS;
  uint8 PMS_SWCompileMonth_PMS;
  uint8 PMS_SWCompileDay_PMS;
  uint32 PMS_IPKTotalOdometer_PMS;
  boolean PMS_OdometerbackupEnable_PMS;
  uint8 PMS_PowerOffCmdSts_PMS;
  uint8 PMS_PowerOffCmdRxSts_PMS;
  boolean PMS_Brake1Switch_PMS;
  boolean PMS_Brake2Switch_PMS;
  uint8 TBOX_ChrgSoftSwCtrlst_EV;
  uint8 PMS_LockVehExecutedSts;
  uint8 PMS_RemChrgCmdFailrPrompt;
  uint8 TBOX_ReservationChrgnSts_EV;
  uint8 PMS_ChargPwr;
  uint8 AC_EWP_SpeedReq;
  uint8 AC_EWP_SpeedReq_LIN;
  uint8 AC_EWP_Heat;
  uint8 AC_EWP_Heat_LIN;
  uint8 AC_EWP_Temp;
  uint8 AC_EWP_Temp_LIN;
  uint8 AC_EWP_Run;
  uint8 AC_EWP_Run_LIN;
  uint8 AC_EWP_HeatrPwrCnsAllwd;
  uint8 AC_EWP_HeatrPwrCnsAllwd_LIN;
  uint8 PMS_Torque_Ovrd_Active;
  uint8 PMS_Torque_Ovrd_Type;
  uint8 PMS_RegulationSpeed_PMS;
  uint8 PMS_AcceSuppressionSts_PMS;
  boolean PMS_TakeEleSwtIndReq_PMS;
  uint8 PMS_CPSRU;
  boolean PMS_Fn1GearRlyDrvStsFb;
  boolean PMS_Fn2GearRlyDrvStsFb;
  boolean PMS_CampModeFb;
  uint8 PMS_CampModeFbFailrReason;
  boolean EXT_DO_RELAY_LS_5;
  uint8 PMS_VehicleSysErrorLevelG1_PMS;
  uint8 ODP_TBOX_TDcDcAlm1_PMS;
  uint8 ODP_TBOX_DcDcStsAlm1_PMS;
  uint8 IPU_MotorTempHighFault2_PMS;
  uint8 IPU_MCUTempHighAlarm2_PMS;
  uint8 BMSH_TBOX_BatTempUniformity3_PMS;
  uint8 BMSH_TBOX_BatOverSOC3_PMS;
  uint8 BMSH_TBOX_SOCHop3_PMS;
  uint8 BMSH_TBOX_BatLowSOC3_PMS;
  uint8 BMSH_TBOX_BatOverCharge3_PMS;
  uint8 BMSH_TBOX_BatUniformity3_PMS;
  uint8 BMSH_TBOX_CellUnderVoltage3_PMS;
  uint8 BMSH_TBOX_BatUnderVoltage3_PMS;
  uint8 BMSH_TBOX_BatOverTemp3_PMS;
  uint8 BMSH_TBOX_BatIsoAlarm3_PMS;
  uint8 BMSH_TBOX_BatOverVoltage3_PMS;
  uint8 BMSH_TBOX_CellOverVoltage3_PMS;
  uint8 PMS_TBOX_BrkSysErr1_PMS;
  uint8 PMS_TBOX_HVILSts1_PMS;
  uint8 BMSH_TBOX_FireAlarm2_PMS;
  uint8 PMS_32960FltNum_PMS;
  uint8 IPU_MotorOverSpdFlt1_PMS;
  uint8 IPU_MotorOverCurrFlt1_PMS;
  uint8 BMSH_BattSysNum_PMS;
  uint8 BMSH_BattPackNum_PMS;
} vcob_VCOP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_ATAU_
#define DEFINED_TYPEDEF_FOR_vcsb_ATAU_

typedef struct {
  KeyAuthStatus pmmd_e_authenticationStatus;
  uint8 pmmd_b_ePTRelease_flg;
} vcsb_ATAU;

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

/* PublicStructure Variables for Internal Data, for system '<S10>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S23>/Unit Delay' */
} ARID_DEF_SR_latch_swc_HVSM_T;

/* PublicStructure Variables for Internal Data, for system '<S2>/turnOFF_delay' */
typedef struct {
  float32 t_wait;                      /* '<S11>/timed_delay' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S11>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S11>/timed_delay' */
} ARID_DEF_turnOFF_delay_swc_HV_T;

/* PublicStructure Variables for Internal Data, for system '<S310>/turnON_delay' */
typedef struct {
  float32 t_wait;                      /* '<S311>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S311>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S311>/timed_delay' */
} ARID_DEF_turnON_delay_swc_HVS_T;

/* PublicStructure Variables for Internal Data, for system '<S61>/turnOFF_delay1' */
typedef struct {
  float32 t_wait;                      /* '<S135>/timed_delay' */
  uint8 is_c9_hvb;                     /* '<S135>/timed_delay' */
  uint8 is_active_c9_hvb;              /* '<S135>/timed_delay' */
} ARID_DEF_turnOFF_delay1_swc_H_T;

/* PublicStructure Variables for Internal Data, for system '<S63>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S164>/Unit Delay' */
} ARID_DEF_SR_latch_swc_HVSM_f_T;

/* PublicStructure Variables for Internal Data, for system '<S64>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S176>/Unit Delay' */
} ARID_DEF_SR_latch1_swc_HVSM_T;

/* PublicStructure Variables for Internal Data, for system '<S64>/turnON_delay1' */
typedef struct {
  float32 t_wait;                      /* '<S180>/timed_delay' */
  uint8 is_c5_hvb;                     /* '<S180>/timed_delay' */
  uint8 is_active_c5_hvb;              /* '<S180>/timed_delay' */
} ARID_DEF_turnON_delay1_swc_HV_T;

/* PublicStructure Variables for Internal Data, for system '<S96>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S288>/Unit Delay' */
} ARID_DEF_SR_latch_swc_HVSM_a_T;

/* PublicStructure Variables for Internal Data, for system '<S99>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S301>/Unit Delay' */
} ARID_DEF_SR_latch_swc_HVSM_ad_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch;/* '<S31>/SR_latch' */
  ARID_DEF_turnOFF_delay_swc_HV_T ARID_DEF_turnOFF_delay;/* '<S43>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_m;/* '<S41>/SR_latch' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay;/* '<S5>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_HV_T ARID_DEF_turnOFF_delay_c;/* '<S100>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch1;/* '<S100>/SR_latch1' */
  ARID_DEF_SR_latch_swc_HVSM_ad_T ARID_DEF_SR_latch_k;/* '<S99>/SR_latch' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_c;/* '<S98>/SR_latch' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch1_b;/* '<S5>/SR_latch1' */
  ARID_DEF_SR_latch_swc_HVSM_a_T ARID_DEF_SR_latch1_p;/* '<S96>/SR_latch1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay1;/* '<S276>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay_c;/* '<S95>/turnON_delay' */
  ARID_DEF_SR_latch1_swc_HVSM_T ARID_DEF_SR_latch2;/* '<S95>/SR_latch2' */
  ARID_DEF_SR_latch1_swc_HVSM_T ARID_DEF_SR_latch1_f;/* '<S95>/SR_latch1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay_g;/* '<S234>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_HV_T ARID_DEF_turnOFF_delay_g;/* '<S234>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_me;/* '<S234>/SR_latch' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay_n;/* '<S233>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_HV_T ARID_DEF_turnOFF_delay_p;/* '<S233>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_l;/* '<S233>/SR_latch' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay_j;/* '<S232>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_HV_T ARID_DEF_turnOFF_delay_d;/* '<S232>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_g;/* '<S232>/SR_latch' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay_l;/* '<S231>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_HV_T ARID_DEF_turnOFF_delay_dh;/* '<S231>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_d;/* '<S231>/SR_latch' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch4;/* '<S92>/SR_latch4' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch3;/* '<S92>/SR_latch3' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch1_l;/* '<S92>/SR_latch1' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_o;/* '<S92>/SR_latch' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay1_b;/* '<S91>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay_nu;/* '<S91>/turnON_delay' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay1_bs;/* '<S197>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay1_l;/* '<S196>/turnON_delay1' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_h;/* '<S83>/SR_latch' */
  ARID_DEF_turnON_delay1_swc_HV_T ARID_DEF_turnON_delay2;/* '<S64>/turnON_delay2' */
  ARID_DEF_turnON_delay1_swc_HV_T ARID_DEF_turnON_delay1_bn;/* '<S64>/turnON_delay1' */
  ARID_DEF_turnOFF_delay1_swc_H_T ARID_DEF_turnOFF_delay2;/* '<S64>/turnOFF_delay2' */
  ARID_DEF_turnOFF_delay1_swc_H_T ARID_DEF_turnOFF_delay1;/* '<S64>/turnOFF_delay1' */
  ARID_DEF_turnOFF_delay1_swc_H_T ARID_DEF_turnOFF_delay_da;/* '<S64>/turnOFF_delay' */
  ARID_DEF_SR_latch1_swc_HVSM_T ARID_DEF_SR_latch1_e;/* '<S64>/SR_latch1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay1_bj;/* '<S63>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay_jz;/* '<S63>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_HV_T ARID_DEF_turnOFF_delay2_f;/* '<S63>/turnOFF_delay2' */
  ARID_DEF_SR_latch_swc_HVSM_f_T ARID_DEF_SR_latch_a;/* '<S63>/SR_latch' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay1_j;/* '<S138>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay1_jz;/* '<S137>/turnON_delay1' */
  ARID_DEF_turnOFF_delay1_swc_H_T ARID_DEF_turnOFF_delay2_o;/* '<S61>/turnOFF_delay2' */
  ARID_DEF_turnOFF_delay1_swc_H_T ARID_DEF_turnOFF_delay1_n;/* '<S61>/turnOFF_delay1' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch2_i;/* '<S61>/SR_latch2' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch1_o;/* '<S61>/SR_latch1' */
  ARID_DEF_turnON_delay_swc_HVS_T ARID_DEF_turnON_delay_nv;/* '<S310>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_HV_T ARID_DEF_turnOFF_delay_m;/* '<S2>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_HVSM_T ARID_DEF_SR_latch_cz;/* '<S10>/SR_latch' */
  float64 DataTypeConversion210;       /* '<Root>/Data Type Conversion210' */
  float64 DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  float64 DataTypeConversion119;       /* '<Root>/Data Type Conversion119' */
  float64 DataTypeConversion218;       /* '<Root>/Data Type Conversion218' */
  float64 DataTypeConversion221;       /* '<Root>/Data Type Conversion221' */
  float64 DataTypeConversion225;       /* '<Root>/Data Type Conversion225' */
  float64 Switch3;                     /* '<S5>/Switch3' */
  float64 accyHvOnCmd;                 /* '<S2>/Chart' */
  float64 accyWorkEnCmd;               /* '<S2>/Chart' */
  float64 flg_accyDisEnOvrTm;          /* '<S2>/Chart' */
  float64 AccyPreRlyCmd;               /* '<S2>/Chart' */
  float64 AccyPreRlySts;               /* '<S2>/Chart' */
  float64 AccyRlyFlt;                  /* '<S2>/Chart' */
  float64 AccyPreRlyFlt;               /* '<S2>/Chart' */
  float64 DelayInput1_DSTATE;          /* '<S302>/Delay Input1' */
  float64 DelayInput1_DSTATE_p;        /* '<S82>/Delay Input1' */
  float64 Counter;                     /* '<S2>/Chart' */
  float32 DataTypeConversion27;        /* '<Root>/Data Type Conversion27' */
  float32 DataTypeConversion32;        /* '<Root>/Data Type Conversion32' */
  float32 DataTypeConversion156;       /* '<Root>/Data Type Conversion156' */
  float32 TimeInState;                 /* '<S89>/LdtNewPlatform' */
  float32 ShutdownTime;                /* '<S3>/DCDC_Converter' */
  float32 DischargeTime;               /* '<S3>/DCDC_Converter' */
  float32 t_wait;                      /* '<S281>/timed_delay' */
  float32 canNmWaitSlpDebTime;         /* '<S89>/LdtNewPlatform' */
  float32 t;                           /* '<S2>/Chart' */
  uint16 UnitDelay3_DSTATE;            /* '<S95>/Unit Delay3' */
  uint8 DataTypeConversion99;          /* '<Root>/Data Type Conversion99' */
  uint8 DataTypeConversion95;          /* '<Root>/Data Type Conversion95' */
  uint8 DataTypeConversion209;         /* '<Root>/Data Type Conversion209' */
  uint8 DataTypeConversion115;         /* '<Root>/Data Type Conversion115' */
  uint8 DataTypeConversion213;         /* '<Root>/Data Type Conversion213' */
  uint8 DataTypeConversion216;         /* '<Root>/Data Type Conversion216' */
  uint8 DataTypeConversion224;         /* '<Root>/Data Type Conversion224' */
  uint8 Switch20;                      /* '<S61>/Switch20' */
  uint8 Switch24;                      /* '<S61>/Switch24' */
  uint8 Switch;                        /* '<S63>/Switch' */
  uint8 BMSCtrlSts;                    /* '<S89>/LdtNewPlatform' */
  ParkingStatus DataTypeConversion66;  /* '<Root>/Data Type Conversion66' */
  McuSts DataTypeConversion54;         /* '<Root>/Data Type Conversion54' */
  McuSts DataTypeConversion41;         /* '<Root>/Data Type Conversion41' */
  McuSts DataTypeConversion49;         /* '<Root>/Data Type Conversion49' */
  McuSts DataTypeConversion50;         /* '<Root>/Data Type Conversion50' */
  McuSts DataTypeConversion51;         /* '<Root>/Data Type Conversion51' */
  McuSts DataTypeConversion56;         /* '<Root>/Data Type Conversion56' */
  McuSts DataTypeConversion42;         /* '<Root>/Data Type Conversion42' */
  HVBattStatus DataTypeConversion;     /* '<Root>/Data Type Conversion' */
  HVBRelayStatus DataTypeConversion47; /* '<Root>/Data Type Conversion47' */
  HVBRelayStatus DataTypeConversion48; /* '<Root>/Data Type Conversion48' */
  HVBRelayStatus DataTypeConversion64; /* '<Root>/Data Type Conversion64' */
  HVBRelayStatus DataTypeConversion76; /* '<Root>/Data Type Conversion76' */
  HVBRelayStatus DataTypeConversion25; /* '<Root>/Data Type Conversion25' */
  ElMac DataTypeConversion26;          /* '<Root>/Data Type Conversion26' */
  ElMac swchvsm_eadd_e_inv2ModeTgtRaw; /* '<S5>/Signal Conversion2' */
  ElMac ElMacSts;                      /* '<S89>/LdtNewPlatform' */
  DriveDir DataTypeConversion5;        /* '<Root>/Data Type Conversion5' */
  DCDCMode DataTypeConversion21;       /* '<Root>/Data Type Conversion21' */
  BrakePedalStatus DataTypeConversion126;/* '<Root>/Data Type Conversion126' */
  uint8 UnitDelay_DSTATE;              /* '<S9>/Unit Delay' */
  uint8 UnitDelay1_DSTATE;             /* '<S95>/Unit Delay1' */
  uint8 UnitDelay8_DSTATE;             /* '<S95>/Unit Delay8' */
  uint8 UnitDelay_DSTATE_l;            /* '<S61>/Unit Delay' */
  uint8 UnitDelay_DSTATE_g;            /* '<S83>/Unit Delay' */
  uint8 UnitDelay3_DSTATE_h;           /* '<S61>/Unit Delay3' */
  uint8 UnitDelay4_DSTATE;             /* '<S61>/Unit Delay4' */
  uint8 UnitDelay1_DSTATE_j;           /* '<S61>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE;             /* '<S61>/Unit Delay2' */
  uint8 UnitDelay_DSTATE_c;            /* '<S63>/Unit Delay' */
  uint8 UnitDelay4_DSTATE_a;           /* '<S5>/Unit Delay4' */
  uint8 UnitDelay6_DSTATE;             /* '<S5>/Unit Delay6' */
  uint8 UnitDelay5_DSTATE;             /* '<S5>/Unit Delay5' */
  uint8 UnitDelay3_DSTATE_b;           /* '<S5>/Unit Delay3' */
  PmmStatus UnitDelay13_DSTATE;        /* '<S5>/Unit Delay13' */
  PmmStatus UnitDelay2_DSTATE_d;       /* '<S5>/Unit Delay2' */
  PmmStatus UnitDelay7_DSTATE;         /* '<S5>/Unit Delay7' */
  PmmStatus UnitDelay12_DSTATE;        /* '<S5>/Unit Delay12' */
  PmmStatus UnitDelay2_DSTATE_nf;      /* '<S99>/Unit Delay2' */
  DCDCMode UnitDelay11_DSTATE;         /* '<S5>/Unit Delay11' */
  DCDCMode UnitDelay10_DSTATE;         /* '<S5>/Unit Delay10' */
  uint8 is_c2_swc_HVSM;                /* '<S3>/DCDC_Converter' */
  uint8 is_CONTROL_OFF;                /* '<S3>/DCDC_Converter' */
  uint8 is_HV_DISCHARGE;               /* '<S3>/DCDC_Converter' */
  uint8 is_active_c2_swc_HVSM;         /* '<S3>/DCDC_Converter' */
  uint8 is_c4_swc_HVSM;                /* '<S4>/TractionMotor' */
  uint8 is_CONTROL_ACTIVE1;            /* '<S4>/TractionMotor' */
  uint8 is_active_c4_swc_HVSM;         /* '<S4>/TractionMotor' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S281>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S281>/timed_delay' */
  uint8 is_c31_hvb;                    /* '<S89>/LdtNewPlatform' */
  uint8 is_OFF;                        /* '<S89>/LdtNewPlatform' */
  uint8 is_DCDC_ACT;                   /* '<S89>/LdtNewPlatform' */
  uint8 is_BMS_RELAY_CLOSE;            /* '<S89>/LdtNewPlatform' */
  uint8 is_WAKEUP;                     /* '<S89>/LdtNewPlatform' */
  uint8 is_POWER_ON;                   /* '<S89>/LdtNewPlatform' */
  uint8 is_active_c31_hvb;             /* '<S89>/LdtNewPlatform' */
  uint8 is_c1_swc_HVSM;                /* '<S6>/ChargerStatus' */
  uint8 is_active_c1_swc_HVSM;         /* '<S6>/ChargerStatus' */
  uint8 is_c68_swc_HVSM;               /* '<S2>/Chart' */
  uint8 is_PowerOneHvOn;               /* '<S2>/Chart' */
  uint8 is_AccyPreChg;                 /* '<S2>/Chart' */
  uint8 is_active_c68_swc_HVSM;        /* '<S2>/Chart' */
  boolean DataTypeConversion15;        /* '<Root>/Data Type Conversion15' */
  boolean DataTypeConversion17;        /* '<Root>/Data Type Conversion17' */
  boolean DataTypeConversion16;        /* '<Root>/Data Type Conversion16' */
  boolean DataTypeConversion24;        /* '<Root>/Data Type Conversion24' */
  boolean DataTypeConversion19;        /* '<Root>/Data Type Conversion19' */
  boolean DataTypeConversion44;        /* '<Root>/Data Type Conversion44' */
  boolean DataTypeConversion55;        /* '<Root>/Data Type Conversion55' */
  boolean DataTypeConversion58;        /* '<Root>/Data Type Conversion58' */
  boolean DataTypeConversion61;        /* '<Root>/Data Type Conversion61' */
  boolean DataTypeConversion62;        /* '<Root>/Data Type Conversion62' */
  boolean DataTypeConversion34;        /* '<Root>/Data Type Conversion34' */
  boolean DataTypeConversion37;        /* '<Root>/Data Type Conversion37' */
  boolean DataTypeConversion43;        /* '<Root>/Data Type Conversion43' */
  boolean DataTypeConversion127;       /* '<Root>/Data Type Conversion127' */
  boolean DataTypeConversion13;        /* '<Root>/Data Type Conversion13' */
  boolean DataTypeConversion68;        /* '<Root>/Data Type Conversion68' */
  boolean DataTypeConversion71;        /* '<Root>/Data Type Conversion71' */
  boolean DataTypeConversion83;        /* '<Root>/Data Type Conversion83' */
  boolean DataTypeConversion85;        /* '<Root>/Data Type Conversion85' */
  boolean DataTypeConversion86;        /* '<Root>/Data Type Conversion86' */
  boolean DataTypeConversion89;        /* '<Root>/Data Type Conversion89' */
  boolean DataTypeConversion74;        /* '<Root>/Data Type Conversion74' */
  boolean DataTypeConversion70;        /* '<Root>/Data Type Conversion70' */
  boolean DataTypeConversion96;        /* '<Root>/Data Type Conversion96' */
  boolean DataTypeConversion87;        /* '<Root>/Data Type Conversion87' */
  boolean DataTypeConversion217;       /* '<Root>/Data Type Conversion217' */
  boolean DataTypeConversion31;        /* '<Root>/Data Type Conversion31' */
  boolean DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  boolean DataTypeConversion22;        /* '<Root>/Data Type Conversion22' */
  boolean GetEnable;                   /* '<S29>/S-Function' */
  boolean GetEnable_g;                 /* '<S42>/S-Function' */
  boolean LogicalOperator36;           /* '<S61>/Logical Operator36' */
  boolean hvbd_b_tmOutFlgDly;          /* '<S5>/Unit Delay' */
  boolean RelationalOperator3_a;       /* '<S5>/Relational Operator3' */
  boolean RelationalOperator6_j;       /* '<S5>/Relational Operator6' */
  boolean LogicalOperator7;            /* '<S5>/Logical Operator7' */
  boolean Compare;                     /* '<S77>/Compare' */
  boolean RelationalOperator1_b;       /* '<S5>/Relational Operator1' */
  boolean RelationalOperator4;         /* '<S5>/Relational Operator4' */
  boolean RelationalOperator8;         /* '<S5>/Relational Operator8' */
  boolean Compare_m;                   /* '<S71>/Compare' */
  boolean hvbd_b_hvbIntelChgCmplt;     /* '<S5>/Signal Conversion' */
  boolean flg_out;                     /* '<S101>/timed_delay' */
  boolean IntelChgCmplt;               /* '<S89>/LdtNewPlatform' */
  boolean IntelChgExitReq;             /* '<S89>/LdtNewPlatform' */
  boolean flg_out_e;                   /* '<S179>/timed_delay' */
  boolean DelayInput1_DSTATE_o;        /* '<S14>/Delay Input1' */
  boolean DelayInput1_DSTATE_m;        /* '<S8>/Delay Input1' */
  boolean UnitDelay_DSTATE_b;          /* '<S2>/Unit Delay' */
  boolean UnitDelay2_DSTATE_m;         /* '<S64>/Unit Delay2' */
  boolean DelayInput1_DSTATE_k;        /* '<S171>/Delay Input1' */
  boolean UnitDelay2_DSTATE_g;         /* '<S95>/Unit Delay2' */
  boolean DelayInput1_DSTATE_l;        /* '<S272>/Delay Input1' */
  boolean UnitDelay5_DSTATE_l;         /* '<S95>/Unit Delay5' */
  boolean DelayInput1_DSTATE_i;        /* '<S107>/Delay Input1' */
  boolean DelayInput1_DSTATE_mi;       /* '<S105>/Delay Input1' */
  boolean DelayInput1_DSTATE_e;        /* '<S108>/Delay Input1' */
  boolean DelayInput1_DSTATE_ea;       /* '<S106>/Delay Input1' */
  boolean UnitDelay1_DSTATE_a;         /* '<S64>/Unit Delay1' */
  boolean DelayInput1_DSTATE_kb;       /* '<S291>/Delay Input1' */
  boolean UnitDelay2_DSTATE_h;         /* '<S63>/Unit Delay2' */
  boolean DelayInput1_DSTATE_ph;       /* '<S158>/Delay Input1' */
  boolean UnitDelay1_DSTATE_l;         /* '<S63>/Unit Delay1' */
  boolean UnitDelay_DSTATE_j;          /* '<S5>/Unit Delay' */
  boolean DelayInput1_DSTATE_g;        /* '<S303>/Delay Input1' */
  boolean DelayInput1_DSTATE_ky;       /* '<S80>/Delay Input1' */
  boolean DelayInput1_DSTATE_c;        /* '<S81>/Delay Input1' */
  boolean UnitDelay1_DSTATE_f;         /* '<S83>/Unit Delay1' */
  boolean DelayInput1_DSTATE_d;        /* '<S191>/Delay Input1' */
  boolean DelayInput1_DSTATE_os;       /* '<S192>/Delay Input1' */
  boolean UnitDelay2_DSTATE_n;         /* '<S83>/Unit Delay2' */
  boolean DelayInput1_DSTATE_gg;       /* '<S157>/Delay Input1' */
  boolean UnitDelay3_DSTATE_p;         /* '<S63>/Unit Delay3' */
  boolean DelayInput1_DSTATE_a;        /* '<S235>/Delay Input1' */
  boolean DelayInput1_DSTATE_le;       /* '<S236>/Delay Input1' */
  boolean UnitDelay_DSTATE_p;          /* '<S231>/Unit Delay' */
  boolean DelayInput1_DSTATE_ct;       /* '<S244>/Delay Input1' */
  boolean DelayInput1_DSTATE_j;        /* '<S245>/Delay Input1' */
  boolean UnitDelay_DSTATE_cp;         /* '<S232>/Unit Delay' */
  boolean DelayInput1_DSTATE_gt;       /* '<S253>/Delay Input1' */
  boolean DelayInput1_DSTATE_pz;       /* '<S254>/Delay Input1' */
  boolean UnitDelay_DSTATE_f;          /* '<S233>/Unit Delay' */
  boolean UnitDelay_DSTATE_pu;         /* '<S234>/Unit Delay' */
  boolean DelayInput1_DSTATE_mz;       /* '<S262>/Delay Input1' */
  boolean DelayInput1_DSTATE_mk;       /* '<S263>/Delay Input1' */
  boolean UnitDelay8_DSTATE_g;         /* '<S5>/Unit Delay8' */
  boolean DelayInput1_DSTATE_gw;       /* '<S294>/Delay Input1' */
  boolean IntelChgActive;              /* '<S89>/LdtNewPlatform' */
  boolean TmOutSts;                    /* '<S89>/LdtNewPlatform' */
  boolean ObcWkUp_prev;                /* '<S89>/LdtNewPlatform' */
  boolean ObcWkUp_start;               /* '<S89>/LdtNewPlatform' */
  boolean Subsystem3_MODE;             /* '<S61>/Subsystem3' */
  boolean Subsystem2_MODE;             /* '<S61>/Subsystem2' */
  boolean Subsystem1_MODE;             /* '<S61>/Subsystem1' */
  boolean Subsystem_MODE;              /* '<S61>/Subsystem' */
} ARID_DEF_swc_HVSM_T;

/* Invariant block signals (default storage) */
typedef struct {
  const boolean LogicalOperator6;      /* '<S30>/Logical Operator6' */
  const boolean Constant6;             /* '<S5>/Constant6' */
  const boolean LogicalOperator5;      /* '<S90>/Logical Operator5' */
  const boolean LogicalOperator6_k;    /* '<S90>/Logical Operator6' */
  const boolean Compare;               /* '<S289>/Compare' */
  const boolean Compare_a;             /* '<S290>/Compare' */
  const boolean LogicalOperator1;      /* '<S98>/Logical Operator1' */
  const boolean LogicalOperator1_d;    /* '<S100>/Logical Operator1' */
} ConstB_swc_HVSM_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_HVSM_T swc_HVSM_ARID_DEF;
extern const ConstB_swc_HVSM_T swc_HVSM_ConstB;/* constant block i/o */

/* Exported data declaration */
#define swc_HVSM_START_SEC_CONST_VOLATILE
#include "swc_HVSM_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile boolean dccc_b_ActiveDischgAlwaysEna;/* Referenced by: '<S3>/Constant10' */

/* Always enable DCDC Active Discharge */
extern const volatile boolean dccc_b_enaAbortDischarge;/* Referenced by: '<S3>/Constant2' */

/* Enable DCDC Active Discharge Abort */
extern const volatile boolean dccc_b_enaDCDCFail;/* Referenced by: '<S3>/Constant1' */

/* Enable DCDC Fail judgment by DCDC Mode Act */
extern const volatile boolean dccc_b_enableDCDC;/* Referenced by: '<S25>/Constant10' */

/* Enable DCDC */
extern const volatile boolean dccc_b_enableDCDCWithOBCPlug;/* Referenced by: '<S25>/Constant5' */

/* Enable DCDC when OBC plugged */
extern const volatile float32 dccc_tm_dischargeTimeout_s;/* Referenced by: '<S3>/Constant11' */

/* DCDC discharge timeout */
extern const volatile float32 dccc_tm_shutdownTimeout_s;/* Referenced by: '<S3>/Constant7' */

/* DCDC shut-down timeout */
extern const volatile boolean eadc_b_disMot2InGear0;/* Referenced by: '<S43>/Constant4' */

/* Disable Secondary EAD when RAT actual gear is 0 */
extern const volatile boolean eadc_b_disMot2InGearPN;/* Referenced by: '<S43>/Constant3' */

/* Disable Secondary EAD when gear lever is in position P/N */
extern const volatile boolean eadc_b_enaInv2AbortDisch;/* Referenced by: '<S41>/Constant1' */

/* Enable Secondary EAD Active Discharge Abort */
extern const volatile boolean eadc_b_enaMot2;/* Referenced by: '<S41>/Constant10' */

/* Enable Secondary EAD */
extern const volatile boolean eadc_b_enaMot2AfterVehRun;/* Referenced by: '<S43>/Constant9' */

/* Secondary EAD enabled after Vehicle is Run */
extern const volatile boolean eadc_b_forceInv2ActvDisch;/* Referenced by: '<S4>/Constant10' */

/* Always enable Secondary EAD Active Discharge */
extern const volatile float32 eadc_tm_disMot2InGearPN_s;/* Referenced by: '<S43>/Constant10' */

/* Delay for disable Secondary EAD when gear lever is in position P/N */
extern const volatile float32 eadc_tm_inv2ActvDischTout_s;/* Referenced by: '<S4>/Constant11' */

/* ESecondary AD discharge timeout */
extern const volatile float32 eadc_tm_inv2ShtdwnTout_s;/* Referenced by: '<S4>/Constant2' */

/* Secondary EAD shut-down timeout */
extern const volatile boolean hvbc_b_FidVehFltLvl32_ovrdflg;/* Referenced by: '<S100>/Constant3' */

/* Override flag for FID_HYB_VEHFLTLVL3_3 */
extern const volatile boolean hvbc_b_FidVehFltLvl3_ovrdflg;/* Referenced by: '<S100>/Constant1' */

/* Override flag for FID_HYB_VEHFLTLVL3_3 */
extern const volatile boolean hvbc_b_FidVehFltLvl3_ovrdval;/* Referenced by: '<S100>/Constant4' */

/* Override value for FID_HYB_VEHFLTLVL3_3 */
extern const volatile boolean hvbc_b_HvONFailResult_ovrdflg;/* Referenced by: '<S131>/FID_ovrdflg' */
extern const volatile boolean hvbc_b_WriteBookChrgnTarVal_ovrdflg;/* Referenced by: '<S95>/Constant42' */
extern const volatile float32 hvbc_b_WriteBookChrgnTarVal_ovrdval;/* Referenced by: '<S95>/Constant43' */
extern const volatile boolean hvbc_b_accyCtrlHw_ovrdflg;/* Referenced by: '<S2>/Constant8' */
extern const volatile boolean hvbc_b_accyCtrlHw_ovrdval;/* Referenced by: '<S2>/Constant5' */
extern const volatile boolean hvbc_b_accyRlyUseDcc;/* Referenced by: '<S2>/Constant6' */
extern const volatile boolean hvbc_b_dchaOn_ovrdflg;/* Referenced by: '<S83>/Constant12' */
extern const volatile boolean hvbc_b_dchaOn_ovrdval;/* Referenced by: '<S83>/Constant11' */
extern const volatile boolean hvbc_b_fltShutDn_ovrdflg;/* Referenced by: '<S88>/Constant8' */

/* Override flag for fltShutDn */
extern const volatile boolean hvbc_b_fltShutDn_ovrdval;/* Referenced by: '<S88>/Constant6' */

/* Override value for fltShutDn */
extern const volatile boolean hvbc_b_hvOnReq_ovrdflg;/* Referenced by: '<S129>/FID_ovrdflg' */
extern const volatile boolean hvbc_b_hvOnReq_ovrdval;/* Referenced by: '<S129>/FID_ovrdval' */
extern const volatile boolean hvbc_b_hvOnResult_ovrdflg;/* Referenced by: '<S132>/FID_ovrdflg' */
extern const volatile boolean hvbc_b_hvShutDnFailResult_ovrdflg;/* Referenced by: '<S133>/FID_ovrdflg' */
extern const volatile boolean hvbc_b_hvShutDnReq_ovrdflg;/* Referenced by: '<S130>/FID_ovrdflg' */
extern const volatile boolean hvbc_b_hvShutDnReq_ovrdval;/* Referenced by: '<S130>/FID_ovrdval' */
extern const volatile boolean hvbc_b_hvShutDnResult_ovrdflg;/* Referenced by: '<S134>/FID_ovrdflg' */
extern const volatile boolean hvbc_b_otaHvOn_ovrdflg;/* Referenced by: '<S61>/Constant7' */
extern const volatile boolean hvbc_b_otaHvOn_ovrdval;/* Referenced by: '<S61>/Constant8' */
extern const volatile boolean hvbc_b_otaShutDn_ovrdflg;/* Referenced by: '<S61>/Constant5' */
extern const volatile boolean hvbc_b_otaShutDn_ovrdval;/* Referenced by: '<S61>/Constant6' */
extern const volatile boolean hvbc_b_prepCmpl_ovrdval;/* Referenced by: '<S62>/Constant6' */
extern const volatile boolean hvbc_b_rsrNotAlwChg_ovrdflg;/* Referenced by: '<S95>/Constant11' */
extern const volatile boolean hvbc_b_rsrNotAlwChg_ovrdval;/* Referenced by: '<S95>/Constant10' */
extern const volatile boolean hvbc_b_udsGetActiveSession_ovrdflg;/* Referenced by: '<S61>/Constant34' */
extern const volatile boolean hvbc_b_useAccyCanEnb;/* Referenced by: '<S9>/Constant4' */
extern const volatile boolean hvbc_b_vcuWkUpOvrd;/* Referenced by: '<S5>/Constant4' */

/* vcuWkUp signal overide flg */
extern const volatile boolean hvbc_b_vcuWkUpOvrdVal;/* Referenced by: '<S5>/Constant3' */

/* vcuWkUp signal overide value */
extern const volatile boolean hvbc_cesc_b_evtFaildCrashEvent_ovrdflg;/* Referenced by: '<S79>/DFC_ovrdflg' */
extern const volatile boolean hvbc_cesc_b_evtFaildCrashEvent_ovrdval;/* Referenced by: '<S79>/DFC_ovrdval' */
extern const volatile boolean hvbc_cesc_b_evtFaildV2XDchaSwt_ovrdflg;/* Referenced by: '<S190>/DFC_ovrdflg' */
extern const volatile boolean hvbc_cesc_b_evtFaildV2XDchaSwt_ovrdval;/* Referenced by: '<S190>/DFC_ovrdval' */
extern const volatile float32 hvbc_i_bmsCurrent_A;/* Referenced by:
                                                   * '<S62>/Constant'
                                                   * '<S90>/Constant1'
                                                   */

/* HVB Shutdown Condition */
extern const volatile float32 hvbc_q_220ACQuitSoc_pct;/* Referenced by: '<S83>/Constant7' */
extern const volatile float32 hvbc_q_CampModeSoc_pct;/* Referenced by: '<S63>/Constant4' */
extern const volatile float32 hvbc_q_dchaAlwSoc_pct;/* Referenced by: '<S83>/Constant4' */
extern const volatile float32 hvbc_s_FidVehFltLvl3BTmOut_s;/* Referenced by: '<S100>/Constant10' */

/* HV off max time for the FID_HYB_VEHFLTLVL3_2 */
extern const volatile uint8 hvbc_st_HvONFailResult_ovrdval;/* Referenced by: '<S131>/FID_ovrdval' */
extern const volatile uint8 hvbc_st_hvOnResult_ovrdval;/* Referenced by: '<S132>/FID_ovrdval' */
extern const volatile uint8 hvbc_st_hvShutDnFailResult_ovrdval;/* Referenced by: '<S133>/FID_ovrdval' */
extern const volatile uint8 hvbc_st_hvShutDnResult_ovrdval;/* Referenced by: '<S134>/FID_ovrdval' */
extern const volatile uint8 hvbc_st_udsGetActiveSession_ovrdval;/* Referenced by: '<S61>/Constant33' */
extern const volatile float32 hvbc_t_accyDisEnOvrTm_s;/* Referenced by: '<S2>/Constant3' */
extern const volatile float32 hvbc_t_accyPreChgOvrTm_s;/* Referenced by: '<S2>/Constant13' */
extern const volatile float32 hvbc_t_accyRePreChgTm_s;/* Referenced by: '<S2>/Constant24' */
extern const volatile float32 hvbc_t_accyRlyClsOvrTmDrvone_s;/* Referenced by: '<S2>/Constant15' */
extern const volatile float32 hvbc_t_accyRlyClsOvrTm_s;/* Referenced by: '<S2>/Constant14' */
extern const volatile float32 hvbc_t_ignOnHold_s;/* Referenced by: '<S2>/Constant1' */
extern const volatile float32 hvbc_tm_AftRun_s;/* Referenced by: '<S99>/Constant4' */
extern const volatile float32 hvbc_tm_BmsNegClsDrv_s;/* Referenced by: '<S99>/Constant3' */
extern const volatile float32 hvbc_tm_BmsNegOpenEmgy_s;/* Referenced by: '<S99>/Constant26' */
extern const volatile float32 hvbc_tm_BmsNegOpen_s;/* Referenced by: '<S99>/Constant24' */
extern const volatile float32 hvbc_tm_BmsRlyOpnDly_s;/* Referenced by: '<S5>/Constant15' */
extern const volatile float32 hvbc_tm_BrkTankRdy_s;/* Referenced by: '<S99>/Constant11' */
extern const volatile float32 hvbc_tm_CampFailrReason_s;/* Referenced by: '<S63>/Constant10' */
extern const volatile float32 hvbc_tm_DcdcAct_s;/* Referenced by: '<S99>/Constant8' */
extern const volatile float32 hvbc_tm_Default_s;/* Referenced by: '<S99>/Constant5' */
extern const volatile float32 hvbc_tm_HcmAssisCls_s;/* Referenced by: '<S99>/Constant7' */
extern const volatile float32 hvbc_tm_HcmAssisOpenEmgy_s;/* Referenced by: '<S99>/Constant22' */
extern const volatile float32 hvbc_tm_HcmAssisOpen_s;/* Referenced by: '<S99>/Constant19' */
extern const volatile float32 hvbc_tm_HcmNegCls_s;/* Referenced by: '<S99>/Constant6' */
extern const volatile float32 hvbc_tm_HcmNegOpenEmgy_s;/* Referenced by: '<S99>/Constant21' */
extern const volatile float32 hvbc_tm_HcmNegOpen_s;/* Referenced by: '<S99>/Constant20' */
extern const volatile float32 hvbc_tm_HcmPosCls_s;/* Referenced by: '<S99>/Constant10' */
extern const volatile float32 hvbc_tm_HcmPosOpenEmgy_s;/* Referenced by: '<S99>/Constant18' */
extern const volatile float32 hvbc_tm_HcmPosOpen_s;/* Referenced by: '<S99>/Constant16' */
extern const volatile float32 hvbc_tm_HcmWkUp_s;/* Referenced by: '<S99>/Constant1' */
extern const volatile float32 hvbc_tm_HvDvcDeActEmgy_s;/* Referenced by: '<S99>/Constant17' */
extern const volatile float32 hvbc_tm_HvDvcDeAct_s;/* Referenced by: '<S99>/Constant14' */
extern const volatile float32 hvbc_tm_LvSysCutOffReq_s;/* Referenced by: '<S99>/Constant25' */
extern const volatile float32 hvbc_tm_McuAct_s;/* Referenced by: '<S99>/Constant12' */
extern const volatile float32 hvbc_tm_McuDeAct_s;/* Referenced by: '<S99>/Constant15' */
extern const volatile float32 hvbc_tm_McuDisChgDly_s;/* Referenced by: '<S5>/Constant16' */
extern const volatile float32 hvbc_tm_McuDsChg_s;/* Referenced by: '<S99>/Constant23' */
extern const volatile float32 hvbc_tm_McuWkUp_s;/* Referenced by: '<S99>/Constant2' */
extern const volatile float32 hvbc_tm_SdcacAct_s;/* Referenced by: '<S99>/Constant9' */
extern const volatile float32 hvbc_tm_ShutDnWait_s;/* Referenced by: '<S99>/Constant13' */
extern const volatile float32 hvbc_tm_WakeUpOffDly_s;/* Referenced by:
                                                      * '<S231>/Constant6'
                                                      * '<S232>/Constant6'
                                                      * '<S233>/Constant6'
                                                      * '<S234>/Constant6'
                                                      */

/* Wake Up Off Delay for Relay Timeout Detection */
extern const volatile float32 hvbc_tm_bmsIntelChgCmplt_s;/* Referenced by: '<S99>/Constant28' */

/* HVB Intelligent Charge Timeout Detection */
extern const volatile float32 hvbc_tm_canNmWaitSlpThd_s;/* Referenced by: '<S5>/Constant8' */
extern const volatile float32 hvbc_tm_chrgRlyTimeOut_s;/* Referenced by:
                                                        * '<S231>/Constant5'
                                                        * '<S232>/Constant5'
                                                        * '<S233>/Constant5'
                                                        * '<S234>/Constant5'
                                                        */
extern const volatile float32 hvbc_tm_dcdcEnFailChg_s;/* Referenced by: '<S5>/Constant12' */
extern const volatile float32 hvbc_tm_disChgDccUnWrk_s;/* Referenced by: '<S196>/Constant7' */
extern const volatile float32 hvbc_tm_disChgSocLow_s;/* Referenced by: '<S197>/Constant7' */
extern const volatile float32 hvbc_tm_dischRlyTimeOut_s;/* Referenced by:
                                                         * '<S231>/Constant2'
                                                         * '<S232>/Constant2'
                                                         * '<S233>/Constant2'
                                                         * '<S234>/Constant2'
                                                         */
extern const volatile float32 hvbc_tm_hvbCampModeExit_s;/* Referenced by:
                                                         * '<S63>/t_step1'
                                                         * '<S63>/t_step3'
                                                         */
extern const volatile float32 hvbc_tm_hvbChEpbgCfmTm_s;/* Referenced by:
                                                        * '<S64>/Constant11'
                                                        * '<S64>/Constant12'
                                                        * '<S64>/Constant13'
                                                        * '<S64>/Constant8'
                                                        */
extern const volatile float32 hvbc_u_accyPreFinVolt_V;/* Referenced by: '<S2>/Constant11' */
extern const volatile float32 hvbc_u_accyRlyClsVolt_V;/* Referenced by: '<S2>/Constant' */
extern const volatile float32 hvbc_u_accyRlyFltVolt_V;/* Referenced by: '<S2>/Constant10' */
extern const volatile float32 hvbc_v_otaCutOffHvSpd_kph;/* Referenced by: '<S61>/Constant13' */
extern const volatile boolean hvbd_b_RmtCtrlSw;/* Referenced by: '<S63>/Constant12' */
extern const volatile float32 hvbd_tm_BookChrgnTarTm_s;/* Referenced by: '<S95>/Constant28' */
extern const volatile float32 obcc_tm_obcNoWakeUpAtIgnOn_s;/* Referenced by: '<S310>/Constant2' */

/* OBC no Wake-Up time after Ignition ON */
extern const volatile float32 obcc_v_ChargerPlugThr_kph;/* Referenced by:
                                                         * '<S5>/Constant5'
                                                         * '<S6>/Constant5'
                                                         * '<S64>/Constant5'
                                                         */

/* Vehicle speed threshold for charger plug detection */
extern const volatile float32 obcc_v_VehLvl32FltThr_kph;/* Referenced by: '<S100>/Constant5' */

/* Vehicle speed threshold for VehLvl32Flt */
extern const volatile boolean swchvsm_hvbc_b_notUseHvBusSts;/* Referenced by: '<S90>/Constant' */
extern const volatile boolean swchvsm_hvbc_flg_PowerONEB_Cfg;/* Referenced by: '<S5>/Constant11' */
extern const volatile float32 swchvsm_hvbc_tm_BmsNegClsChg_s;/* Referenced by: '<S99>/Constant31' */
extern const volatile float32 swchvsm_hvbc_tm_hvShutDnEmgy_s;/* Referenced by: '<S99>/Constant30' */
extern const volatile float32 swchvsm_hvbc_tm_hvbChgCfmTm_s;/* Referenced by: '<S64>/Constant3' */
extern const volatile float32 swchvsm_hvbc_tm_hvbChgFltCfm_s;/* Referenced by: '<S91>/Constant4' */
extern const volatile float32 swchvsm_hvbc_tm_hvbChgFltTm_s;/* Referenced by: '<S91>/Constant1' */
extern const volatile float32 swchvsm_hvbc_tm_shtDnWaitEmgy_s;/* Referenced by: '<S99>/Constant29' */
extern const volatile boolean swchvsm_vsmc_b_enaPTReadyVehRun;/* Referenced by: '<S5>/Constant7' */

/* Enable PT Ready determination of Vehicle Run */
#define swc_HVSM_STOP_SEC_CONST_VOLATILE
#include "swc_HVSM_MemMap.h"
#define swc_HVSM_START_SEC_VAR
#include "swc_HVSM_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern uint8 bmsd_e_modeTgt;           /* '<S5>/Signal Conversion3' */
extern boolean dccd_b_DCDCEnabled;     /* '<S25>/Logical Operator1' */

/* DCDC Enabled */
extern DCDCMode dccd_e_modeTgt;        /* '<S3>/DCDC_Converter' */

/* DCDC Target Mode */
extern boolean eadd_b_ead2Avail;       /* '<S41>/Logical Operator7' */

/* Secondary EAD Available */
extern boolean eadd_b_ead2Enad;        /* '<S41>/Relational Operator6' */

/* Secondary EAD Enabled */
extern ElMac eadd_e_inv2ModeTgt;       /* '<S4>/TractionMotor' */

/* Secondary EAD Target Mode */
extern boolean hvbd_b_CampModeFb;      /* '<S164>/Logical Operator3' */
extern boolean hvbd_b_ChgLEDCtlFlg;    /* '<S281>/timed_delay' */
extern boolean hvbd_b_FidVehFltLvl3HvOff;/* '<S100>/Switch' */

/* FID Vehicle fault level HV off */
extern boolean hvbd_b_LvSysCutOffAlw;  /* '<S92>/Logical Operator3' */

/* LV System Cut Off Allow */
extern boolean hvbd_b_LvSysSlfChkOk;   /* '<S93>/Logical Operator2' */

/* LV System Self-check OK */
extern boolean hvbd_b_ResChgRouterReset;/* '<S95>/Logical Operator4' */
extern boolean hvbd_b_ResChgRouterSwt; /* '<S95>/SR_latch1' */
extern boolean hvbd_b_StsModeReqFlg;   /* '<S272>/FixPt Relational Operator' */
extern boolean hvbd_b_TakeEleSwtIndReq;/* '<S9>/Switch4' */
extern boolean hvbd_b_acPtcEnb;        /* '<S288>/Logical Operator3' */
extern boolean hvbd_b_accyCtrlHw;      /* '<S2>/Switch' */
extern boolean hvbd_b_accyDisEnOvrTm;  /* '<S2>/Data Type Conversion4' */
extern boolean hvbd_b_accyEnReq;       /* '<S9>/Logical Operator3' */
extern uint8 hvbd_b_accyHvOnCmd;       /* '<S2>/Data Type Conversion3' */
extern boolean hvbd_b_accyLvPwrOnCmd;  /* '<S10>/SR_latch' */
extern boolean hvbd_b_accyPreRlyCmd;   /* '<S2>/Data Type Conversion6' */
extern boolean hvbd_b_accyWrkEnCmd;    /* '<S2>/Data Type Conversion' */
extern boolean hvbd_b_allowChg;        /* '<S89>/LdtNewPlatform' */

/* Charge Allow */
extern boolean hvbd_b_assistPosRlyTmOut;/* '<S231>/SR_latch' */

/* Assist Positive Relay Time Out Flag */
extern boolean hvbd_b_bmsNegRlyTmOut;  /* '<S232>/SR_latch' */

/* BMS Negative Relay Time Out Flag */
extern boolean hvbd_b_brpEpsSlfChkOk;  /* '<S93>/Logical Operator1' */

/* Brake Pump and EPS Self-check OK */
extern boolean hvbd_b_chargeReq;       /* '<S64>/Logical Operator1' */

/* Charge Request */
extern boolean hvbd_b_chgCablePlugged; /* '<S5>/Switch4' */
extern boolean hvbd_b_crashShutDn;     /* '<Root>/Data Type Conversion80' */
extern boolean hvbd_b_dchaOn;          /* '<S83>/Switch4' */
extern boolean hvbd_b_dchaReq;         /* '<S83>/Data Type Conversion' */
extern boolean hvbd_b_emgyShutDn;      /* '<S5>/Logical Operator5' */
extern boolean hvbd_b_fltPwrShutDn;    /* '<S5>/Unit Delay8' */
extern boolean hvbd_b_fltShutDn;       /* '<S88>/Switch1' */

/* Fault Shut Down */
extern boolean hvbd_b_hcmNegRlyTmOut;  /* '<S233>/SR_latch' */

/* HCM Negative Relay Time Out Flag */
extern boolean hvbd_b_hvBusShutDwnCmpl;/* '<S62>/Logical Operator4' */

/* HV Bus shutdown complete */
extern boolean hvbd_b_hvDvcShutDnCmplt;/* '<S90>/Logical Operator4' */

/* High Voltage Device Shut Down Complete */
extern boolean hvbd_b_hvShutDnCmplt;   /* '<S90>/Logical Operator1' */

/* High Voltage Shut Down Complete */
extern boolean hvbd_b_hvbHvOnReq;      /* '<S139>/Switch2' */
extern boolean hvbd_b_hvbIntelChgExitReq;/* '<S5>/Signal Conversion1' */

/* HVB Intelligent Charge Exit Flag */
extern boolean hvbd_b_hvbShutDnReq;    /* '<S140>/Switch2' */
extern boolean hvbd_b_hvilOpenCfm;     /* '<S5>/SR_latch1' */
extern boolean hvbd_b_lvCutOffReq;     /* '<S89>/LdtNewPlatform' */

/* LV Cut Off Request */
extern boolean hvbd_b_mainPosRlyTmOut; /* '<S234>/SR_latch' */

/* Main Positive Relay Time Out Flag */
extern boolean hvbd_b_otaHvOn;         /* '<S61>/Switch7' */
extern boolean hvbd_b_otaShutDn;       /* '<S61>/Switch1' */
extern boolean hvbd_b_parkingSts;      /* '<S64>/Relational Operator2' */
extern boolean hvbd_b_rlyTmOut;        /* '<S94>/Logical Operator' */

/* Relay Time Out Flag */
extern boolean hvbd_b_rsrNotAlwChg;    /* '<S95>/Logical Operator6' */
extern boolean hvbd_b_startReq;        /* '<S98>/SR_latch' */

/* Start Request */
extern boolean hvbd_b_tboxPrtFullSwStUB;/* '<Root>/Data Type Conversion214' */
extern boolean hvbd_b_tmOutFlg;        /* '<S99>/Relational Operator' */

/* PMM Time Out Flg */
extern boolean hvbd_b_tmOutFlgCfm;     /* '<S301>/Logical Operator3' */

/* PMM Time Out Flg Latched */
extern boolean hvbd_b_vcuRdyToSlp;     /* '<S5>/Logical Operator4' */

/* VCU Ready To Sleep */
extern boolean hvbd_b_vcuWkUpCmd;      /* '<S5>/Switch' */

/* VCU Wake Up Command */
extern boolean hvbd_b_vcuWkUpCmdRaw;   /* '<S89>/LdtNewPlatform' */

/* VCU Wake Up Command Raw */
extern boolean hvbd_cesd_b_CrashEvent; /* '<S187>/Switch2' */

/* Crash Signal */
extern boolean hvbd_cesd_b_V2XDchaSwt; /* '<S198>/Switch2' */
extern PmmStatus hvbd_e_PmmStatus;     /* '<S89>/LdtNewPlatform' */

/* PMM Status */
extern HVBattStatus hvbd_e_modeTgt;    /* '<S89>/LdtNewPlatform' */

/* HVB Target Mode */
extern PmmStatus hvbd_e_tmOutSource;   /* '<S99>/Switch' */

/* PMM Status */
extern uint16 hvbd_pct_BookChrgnTarValFb;/* '<S95>/Switch' */
extern uint16 hvbd_pct_LocBkChgTarVal_Read;/* '<S95>/C Caller2' */
extern uint8 hvbd_st_CampModeFbFailrReason;/* '<S63>/Switch6' */
extern uint8 hvbd_st_RmChgCmdFailPmt;  /* '<S95>/Switch5' */
extern uint8 hvbd_st_accyPreRlyFlt;    /* '<S2>/Data Type Conversion9' */
extern uint8 hvbd_st_accyPreRlySts;    /* '<S2>/Data Type Conversion7' */
extern uint8 hvbd_st_accyRlyFlt;       /* '<S2>/Data Type Conversion8' */
extern uint8 hvbd_st_accyRlyVoltSamSw; /* '<S2>/Data Type Conversion5' */
extern uint8 hvbd_st_accyTakeSts;      /* '<S2>/Data Type Conversion2' */
extern uint8 hvbd_st_bbmWrkEnCmd;      /* '<S2>/Data Type Conversion1' */
extern uint8 hvbd_st_hcmMaiRlyNegClsReq;/* '<S89>/LdtNewPlatform' */

/* HCM Main Negative Relay Close Command */
extern uint8 hvbd_st_hvbAssiRlyPosClsReq;/* '<S89>/LdtNewPlatform' */

/* HVB Assist Positive Relay Close Command */
extern uint8 hvbd_st_hvbHvOnFailResult;/* '<S128>/Signal Conversion' */
extern uint8 hvbd_st_hvbHvOnFlg;       /* '<S126>/Signal Conversion' */
extern uint8 hvbd_st_hvbMaiRlyNegClsReq;/* '<S89>/LdtNewPlatform' */

/* HVB Main Negative Relay Close Command */
extern uint8 hvbd_st_hvbMaiRlyPosClsReq;/* '<S89>/LdtNewPlatform' */

/* HVB Main Positive Relay Close Command */
extern uint8 hvbd_st_hvbShutDnFailResult;/* '<S127>/Signal Conversion' */
extern uint8 hvbd_st_hvbShutDnFlg;     /* '<S125>/Signal Conversion' */
extern uint8 hvbd_st_ptRdyInd;         /* '<S89>/LdtNewPlatform' */

/* Power Train Ready Indication */
extern uint8 hvbd_st_tboxChgSftSwCtlStEV;/* '<S95>/Switch2' */
extern uint8 hvbd_st_tboxPrtFullSwSt;  /* '<Root>/Data Type Conversion215' */
extern uint8 hvbd_st_udsGetActiveSession;/* '<S61>/Switch25' */
extern boolean hvsm_hvbd_b_nmRdySlp;   /* '<S5>/Logical Operator3' */
extern boolean hvsm_hvbd_b_nmWkUp;     /* '<S5>/C Caller' */
extern uint8 hvsm_pmmd_num_keyOnCnt;   /* '<S95>/C Caller1' */
extern boolean obcd_b_chargerPlugged;  /* '<S6>/Relational Operator1' */

/* Charger Plugged */
extern ChargerStatus obcd_e_chargerSts;/* '<S6>/ChargerStatus' */

/* Validated external charger status */
extern uint8 swchvsm_dccd_pct_DCDCPwrLmt;/* '<S25>/Switch' */

/* DCDC Enabled Power Limit */
extern boolean swchvsm_hvbd_b_hvbChgEnd;/* '<S91>/Relational Operator2' */
extern boolean swchvsm_hvbd_b_hvbChging;/* '<S91>/Logical Operator11' */
extern boolean swchvsm_hvbd_b_hvbNoChgFlg;/* '<S91>/Logical Operator2' */
extern boolean swchvsm_hvbd_st_hvbRlyClsd;/* '<S91>/Logical Operator7' */

#define swc_HVSM_STOP_SEC_VAR
#include "swc_HVSM_MemMap.h"

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
 * '<Root>' : 'swc_HVSM'
 * '<S1>'   : 'swc_HVSM/HVSM__HV_System_Manager'
 * '<S2>'   : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control'
 * '<S3>'   : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager'
 * '<S4>'   : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2'
 * '<S5>'   : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager'
 * '<S6>'   : 'swc_HVSM/HVSM__HV_System_Manager/OBC_ChargerStatus'
 * '<S7>'   : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Chart'
 * '<S8>'   : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Detect Increase'
 * '<S9>'   : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem'
 * '<S10>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/accyRelayEnable'
 * '<S11>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/turnOFF_delay'
 * '<S12>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Compare To Constant'
 * '<S13>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Compare To Constant1'
 * '<S14>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Detect Increase3'
 * '<S15>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Enumerated Constant1'
 * '<S16>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Enumerated Constant2'
 * '<S17>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Enumerated Constant4'
 * '<S18>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Enumerated Constant5'
 * '<S19>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Enumerated Constant6'
 * '<S20>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/Subsystem/Enumerated Constant7'
 * '<S21>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/accyRelayEnable/Enumerated Constant1'
 * '<S22>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/accyRelayEnable/Enumerated Constant6'
 * '<S23>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/accyRelayEnable/SR_latch'
 * '<S24>'  : 'swc_HVSM/HVSM__HV_System_Manager/Accy_Control/turnOFF_delay/timed_delay'
 * '<S25>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDCEnable'
 * '<S26>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDC_Converter'
 * '<S27>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/Enumerated Constant3'
 * '<S28>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/Enumerated Constant4'
 * '<S29>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/Get_FID_Enable'
 * '<S30>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/ModeRequest'
 * '<S31>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDCEnable/DcdcEnableReq'
 * '<S32>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDCEnable/DcdcEnableReq/Compare To Constant1'
 * '<S33>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDCEnable/DcdcEnableReq/Enumerated Constant'
 * '<S34>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDCEnable/DcdcEnableReq/Enumerated Constant1'
 * '<S35>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDCEnable/DcdcEnableReq/Enumerated Constant2'
 * '<S36>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDCEnable/DcdcEnableReq/Enumerated Constant3'
 * '<S37>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/DCDCEnable/DcdcEnableReq/SR_latch'
 * '<S38>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/ModeRequest/Enumerated Constant2'
 * '<S39>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/ModeRequest/Enumerated Constant6'
 * '<S40>'  : 'swc_HVSM/HVSM__HV_System_Manager/DCC_ModeManager/ModeRequest/Enumerated Constant7'
 * '<S41>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions'
 * '<S42>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/Get_FID_Enable'
 * '<S43>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/TargetMode'
 * '<S44>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/TractionMotor'
 * '<S45>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant3'
 * '<S46>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant4'
 * '<S47>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant5'
 * '<S48>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant8'
 * '<S49>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant9'
 * '<S50>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant1'
 * '<S51>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant14'
 * '<S52>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant15'
 * '<S53>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant16'
 * '<S54>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant17'
 * '<S55>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant19'
 * '<S56>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/Enumerated Constant7'
 * '<S57>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/ElMacConditions/SR_latch'
 * '<S58>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/TargetMode/Enumerated Constant'
 * '<S59>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/TargetMode/turnOFF_delay'
 * '<S60>'  : 'swc_HVSM/HVSM__HV_System_Manager/EAD_ModeManagerMot2/TargetMode/turnOFF_delay/timed_delay'
 * '<S61>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service'
 * '<S62>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Calc_HV_absorption'
 * '<S63>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode'
 * '<S64>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest'
 * '<S65>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant10'
 * '<S66>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant12'
 * '<S67>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant13'
 * '<S68>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant14'
 * '<S69>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant15'
 * '<S70>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant16'
 * '<S71>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant2'
 * '<S72>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant3'
 * '<S73>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant4'
 * '<S74>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant5'
 * '<S75>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant6'
 * '<S76>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant7'
 * '<S77>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant8'
 * '<S78>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Compare To Constant9'
 * '<S79>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DFC_Ovrd'
 * '<S80>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Detect Increase1'
 * '<S81>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Detect Increase2'
 * '<S82>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Detect Increase3'
 * '<S83>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge'
 * '<S84>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Enumerated Constant'
 * '<S85>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Enumerated Constant4'
 * '<S86>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Enumerated Constant12'
 * '<S87>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Enumerated Constant13'
 * '<S88>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/FaultShutDown'
 * '<S89>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HVBStatus'
 * '<S90>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt'
 * '<S91>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts'
 * '<S92>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/LowVoltageSystemCutOffAlow'
 * '<S93>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/LowVoltageSystemSelfCheck'
 * '<S94>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection'
 * '<S95>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage'
 * '<S96>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage1'
 * '<S97>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/SR_latch1'
 * '<S98>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/StartReqLatch'
 * '<S99>'  : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement'
 * '<S100>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/VehicleFaultLevel3HVOFF'
 * '<S101>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/turnON_delay'
 * '<S102>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Compare To Constant'
 * '<S103>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Compare To Constant3'
 * '<S104>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Compare To Constant4'
 * '<S105>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Detect Change'
 * '<S106>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Detect Change1'
 * '<S107>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Detect Increase1'
 * '<S108>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Detect Increase2'
 * '<S109>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant1'
 * '<S110>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant10'
 * '<S111>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant11'
 * '<S112>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant2'
 * '<S113>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant3'
 * '<S114>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant5'
 * '<S115>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant6'
 * '<S116>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant7'
 * '<S117>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant8'
 * '<S118>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant9'
 * '<S119>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant12'
 * '<S120>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant13'
 * '<S121>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant14'
 * '<S122>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Enumerated Constant15'
 * '<S123>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/SR_latch1'
 * '<S124>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/SR_latch2'
 * '<S125>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Subsystem'
 * '<S126>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Subsystem1'
 * '<S127>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Subsystem2'
 * '<S128>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/Subsystem3'
 * '<S129>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_HvOnReq'
 * '<S130>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_HvShutDnReq'
 * '<S131>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_SetHvONFailResult'
 * '<S132>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_SetHvOnResult'
 * '<S133>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_SetHvShutDnFailResult'
 * '<S134>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_SetHvShutDnResult'
 * '<S135>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnOFF_delay1'
 * '<S136>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnOFF_delay2'
 * '<S137>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnON_delay1'
 * '<S138>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnON_delay2'
 * '<S139>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_HvOnReq/override_signal'
 * '<S140>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_HvShutDnReq/override_signal'
 * '<S141>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_SetHvONFailResult/override_signal'
 * '<S142>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_SetHvOnResult/override_signal'
 * '<S143>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_SetHvShutDnFailResult/override_signal'
 * '<S144>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/mBSW_SetHvShutDnResult/override_signal'
 * '<S145>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnOFF_delay1/timed_delay'
 * '<S146>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnOFF_delay2/timed_delay'
 * '<S147>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnON_delay1/turnON_delay1'
 * '<S148>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnON_delay1/turnON_delay1/timed_delay'
 * '<S149>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnON_delay2/turnON_delay1'
 * '<S150>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/31_service/turnON_delay2/turnON_delay1/timed_delay'
 * '<S151>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Calc_HV_absorption/abs_val'
 * '<S152>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Calc_HV_absorption/abs_val/neg'
 * '<S153>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/Calc_HV_absorption/abs_val/pos'
 * '<S154>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Compare To Constant'
 * '<S155>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Compare To Constant1'
 * '<S156>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Compare To Constant2'
 * '<S157>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Detect Decrease'
 * '<S158>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Detect Increase4'
 * '<S159>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Enumerated Constant1'
 * '<S160>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Enumerated Constant3'
 * '<S161>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Enumerated Constant4'
 * '<S162>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Enumerated Constant9'
 * '<S163>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/Enumerated Constant2'
 * '<S164>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/SR_latch'
 * '<S165>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/turnOFF_delay2'
 * '<S166>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/turnON_delay'
 * '<S167>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/turnON_delay1'
 * '<S168>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/turnOFF_delay2/timed_delay'
 * '<S169>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/turnON_delay/timed_delay'
 * '<S170>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/CampMode/turnON_delay1/timed_delay'
 * '<S171>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/Detect Decrease'
 * '<S172>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/Enumerated Constant1'
 * '<S173>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/Enumerated Constant2'
 * '<S174>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/Enumerated Constant3'
 * '<S175>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/Enumerated Constant4'
 * '<S176>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/SR_latch1'
 * '<S177>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnOFF_delay'
 * '<S178>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnOFF_delay1'
 * '<S179>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnOFF_delay2'
 * '<S180>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnON_delay1'
 * '<S181>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnON_delay2'
 * '<S182>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnOFF_delay/timed_delay'
 * '<S183>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnOFF_delay1/timed_delay'
 * '<S184>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnOFF_delay2/timed_delay'
 * '<S185>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnON_delay1/timed_delay'
 * '<S186>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ChargeRequest/turnON_delay2/timed_delay'
 * '<S187>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DFC_Ovrd/override_signal'
 * '<S188>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/Compare To Constant'
 * '<S189>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/Compare To Constant1'
 * '<S190>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/DFC_Ovrd'
 * '<S191>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/Detect Increase2'
 * '<S192>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/Detect Increase3'
 * '<S193>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/Enumerated Constant1'
 * '<S194>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/Enumerated Constant2'
 * '<S195>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/SR_latch'
 * '<S196>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/turnON_delay1'
 * '<S197>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/turnON_delay2'
 * '<S198>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/DFC_Ovrd/override_signal'
 * '<S199>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/turnON_delay1/turnON_delay1'
 * '<S200>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/turnON_delay1/turnON_delay1/timed_delay'
 * '<S201>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/turnON_delay2/turnON_delay1'
 * '<S202>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/DisCharge/turnON_delay2/turnON_delay1/timed_delay'
 * '<S203>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HVBStatus/LdtNewPlatform'
 * '<S204>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt/Enumerated Constant5'
 * '<S205>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt/Enumerated Constant6'
 * '<S206>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt/Enumerated Constant7'
 * '<S207>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt/Enumerated Constant8'
 * '<S208>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt/Enumerated Constant9'
 * '<S209>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt/abs_val'
 * '<S210>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt/abs_val/neg'
 * '<S211>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HighVoltageDeviceShutDnCmplt/abs_val/pos'
 * '<S212>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant1'
 * '<S213>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant2'
 * '<S214>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant3'
 * '<S215>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant4'
 * '<S216>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant5'
 * '<S217>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant6'
 * '<S218>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant7'
 * '<S219>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant8'
 * '<S220>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/Enumerated Constant9'
 * '<S221>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/turnON_delay'
 * '<S222>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/turnON_delay1'
 * '<S223>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/turnON_delay/timed_delay'
 * '<S224>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/HvbSts/turnON_delay1/timed_delay'
 * '<S225>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/LowVoltageSystemCutOffAlow/Enumerated Constant2'
 * '<S226>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/LowVoltageSystemCutOffAlow/SR_latch'
 * '<S227>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/LowVoltageSystemCutOffAlow/SR_latch1'
 * '<S228>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/LowVoltageSystemCutOffAlow/SR_latch3'
 * '<S229>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/LowVoltageSystemCutOffAlow/SR_latch4'
 * '<S230>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/LowVoltageSystemSelfCheck/Enumerated Constant1'
 * '<S231>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection'
 * '<S232>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection'
 * '<S233>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection'
 * '<S234>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection'
 * '<S235>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/Detect Increase'
 * '<S236>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/Detect Increase1'
 * '<S237>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/Enumerated Constant1'
 * '<S238>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/Enumerated Constant2'
 * '<S239>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/SR_latch'
 * '<S240>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/turnOFF_delay'
 * '<S241>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/turnON_delay'
 * '<S242>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/turnOFF_delay/timed_delay'
 * '<S243>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/AssistPositiveRlyTimeOutDetection/turnON_delay/timed_delay'
 * '<S244>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/Detect Increase'
 * '<S245>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/Detect Increase1'
 * '<S246>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/Enumerated Constant1'
 * '<S247>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/Enumerated Constant2'
 * '<S248>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/SR_latch'
 * '<S249>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/turnOFF_delay'
 * '<S250>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/turnON_delay'
 * '<S251>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/turnOFF_delay/timed_delay'
 * '<S252>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/BmsNegRlyTimeOutDetection/turnON_delay/timed_delay'
 * '<S253>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/Detect Increase'
 * '<S254>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/Detect Increase1'
 * '<S255>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/Enumerated Constant1'
 * '<S256>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/Enumerated Constant2'
 * '<S257>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/SR_latch'
 * '<S258>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/turnOFF_delay'
 * '<S259>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/turnON_delay'
 * '<S260>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/turnOFF_delay/timed_delay'
 * '<S261>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/HcmNegRlyTimeOutDetection/turnON_delay/timed_delay'
 * '<S262>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/Detect Increase'
 * '<S263>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/Detect Increase1'
 * '<S264>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/Enumerated Constant1'
 * '<S265>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/Enumerated Constant2'
 * '<S266>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/SR_latch'
 * '<S267>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/turnOFF_delay'
 * '<S268>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/turnON_delay'
 * '<S269>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/turnOFF_delay/timed_delay'
 * '<S270>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/RelayTimeOutDetection/MainPositiveRlyTimeOutDetection/turnON_delay/timed_delay'
 * '<S271>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/Compare To Constant'
 * '<S272>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/Detect Decrease'
 * '<S273>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/SR_latch1'
 * '<S274>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/SR_latch2'
 * '<S275>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/turnON_delay'
 * '<S276>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/turnON_delay1'
 * '<S277>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/turnON_delay2'
 * '<S278>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/turnON_delay/timed_delay'
 * '<S279>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/turnON_delay1/turnON_delay1'
 * '<S280>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/turnON_delay1/turnON_delay1/timed_delay'
 * '<S281>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/turnON_delay2/turnON_delay1'
 * '<S282>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage/turnON_delay2/turnON_delay1/timed_delay'
 * '<S283>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage1/Enumerated Constant1'
 * '<S284>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage1/Enumerated Constant2'
 * '<S285>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage1/Enumerated Constant3'
 * '<S286>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage1/Enumerated Constant4'
 * '<S287>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage1/Enumerated Constant5'
 * '<S288>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/ReservationChrage1/SR_latch1'
 * '<S289>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/StartReqLatch/Compare To Constant4'
 * '<S290>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/StartReqLatch/Compare To Constant5'
 * '<S291>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/StartReqLatch/Detect Decrease'
 * '<S292>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/StartReqLatch/SR_latch'
 * '<S293>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/Compare To Constant1'
 * '<S294>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/Detect Increase'
 * '<S295>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/Enumerated Constant1'
 * '<S296>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/Enumerated Constant2'
 * '<S297>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/Enumerated Constant3'
 * '<S298>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/Enumerated Constant4'
 * '<S299>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/Enumerated Constant5'
 * '<S300>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/Enumerated Constant6'
 * '<S301>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/TimeOutManagement/SR_latch'
 * '<S302>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/VehicleFaultLevel3HVOFF/Detect Decrease'
 * '<S303>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/VehicleFaultLevel3HVOFF/Detect Decrease1'
 * '<S304>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/VehicleFaultLevel3HVOFF/SR_latch1'
 * '<S305>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/VehicleFaultLevel3HVOFF/turnOFF_delay'
 * '<S306>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/VehicleFaultLevel3HVOFF/turnOFF_delay/timed_delay'
 * '<S307>' : 'swc_HVSM/HVSM__HV_System_Manager/HVB_ModeManager/turnON_delay/timed_delay'
 * '<S308>' : 'swc_HVSM/HVSM__HV_System_Manager/OBC_ChargerStatus/ChargerStatus'
 * '<S309>' : 'swc_HVSM/HVSM__HV_System_Manager/OBC_ChargerStatus/Enumerated Constant1'
 * '<S310>' : 'swc_HVSM/HVSM__HV_System_Manager/OBC_ChargerStatus/OBCStatus'
 * '<S311>' : 'swc_HVSM/HVSM__HV_System_Manager/OBC_ChargerStatus/OBCStatus/turnON_delay'
 * '<S312>' : 'swc_HVSM/HVSM__HV_System_Manager/OBC_ChargerStatus/OBCStatus/turnON_delay/timed_delay'
 */
#endif                                 /* RTW_HEADER_swc_HVSM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
