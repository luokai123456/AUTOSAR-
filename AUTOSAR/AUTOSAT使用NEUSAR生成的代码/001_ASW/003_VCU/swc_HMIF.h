/*
 * File: swc_HMIF.h
 *
 * Code generated for Simulink model 'swc_HMIF'.
 *
 * Model version                  : 6.412
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Sep  9 19:15:42 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_HMIF_h_
#define RTW_HEADER_swc_HMIF_h_
#ifndef swc_HMIF_COMMON_INCLUDES_
#define swc_HMIF_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_HMIF.h"
#endif                                 /* swc_HMIF_COMMON_INCLUDES_ */

#include "Rte_Type.h"
#include "zero_crossing_types.h"

/* Includes for objects with custom storage classes */
#include "const_ImportFromFile.h"
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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_HMIF_
#define DEFINED_TYPEDEF_FOR_vcsb_HMIF_

typedef struct {
  uint8 dspd_st_vehOverLoadSts;
  float32 dspd_d_vehCrsDst_km;
  boolean dspd_b_HazardReqLmpOn;
  float32 dspd_m_vehWeight_kg;
  boolean dspd_b_vehOvrLoadEnbl;
  uint8 dspd_st_vehCalNum;
  uint8 dspd_st_vehSubFailLvl;
  uint8 dspd_st_vehDrvMode;
  PowerFlowMode dspd_e_vehPwrFlow;
  uint8 dspd_st_vehFailLvl;
  boolean dspd_b_evLampOn;
  boolean dspd_b_hevLampOn;
  float32 dspd_q_hvbSOC_pct;
  float32 dspd_d_vehDrvRngEVMod_km;
  float32 dspd_V_engFuelConsAvg_lp100km;
  float32 dspd_d_vehDrvRngHEVMod_km;
  float32 dspd_num_AecEV_kWhp100km;
  float32 dspd_num_errorCode;
  uint8 dspd_st_drvModInd;
  uint8 dspd_st_drvrOptRmdr;
  float32 dspd_pwr_hvPwrCsmpt_kW;
  boolean dspd_b_turtleLmpOn;
  float32 dspd_pwr_hvPwrRemain_kW;
  float32 dspd_d_pmsOdoBckUpMilg_km;
  boolean dspd_b_ePTFault;
  uint16 dspd_st_drvPfmncRedn;
  boolean dspd_b_brkSysFlt;
  boolean dspd_b_CruisingDstSwtFb;
  float32 dspd_d_vehDrvRngStandard_km;
  boolean dspd_b_odoBckpEn;
  float32 dspd_d_odoTotal_km;
} vcsb_HMIF;

#endif

/* PublicStructure Variables for Internal Data, for system '<S27>/CsmptEngyCal' */
typedef struct {
  float32 UnitDelay3_DSTATE;           /* '<S30>/UnitDelay3' */
} ARID_DEF_CsmptEngyCal_swc_HMI_T;

/* PublicStructure Variables for Internal Data, for system '<S27>/MileageCal' */
typedef struct {
  float32 UnitDelay3_DSTATE;           /* '<S33>/UnitDelay3' */
} ARID_DEF_MileageCal_swc_HMIF_T;

/* PublicStructure Variables for Internal Data, for system '<S46>/Subsystem' */
typedef struct {
  float64 UnitDelay5_DSTATE;           /* '<S53>/Unit Delay5' */
  boolean Subsystem_MODE;              /* '<S46>/Subsystem' */
} ARID_DEF_Subsystem_swc_HMIF_T;

/* PublicStructure Variables for Internal Data, for system '<S47>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S54>/Unit Delay' */
} ARID_DEF_SR_latch_swc_HMIF_T;

/* PublicStructure Variables for Internal Data, for system '<S56>/Subsystem' */
typedef struct {
  float64 UnitDelay5_DSTATE;           /* '<S61>/Unit Delay5' */
  boolean Subsystem_MODE;              /* '<S56>/Subsystem' */
} ARID_DEF_Subsystem_swc_HMIF_h_T;

/* PublicStructure Variables for Internal Data, for system '<S80>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S192>/Unit Delay' */
} ARID_DEF_SR_latch_swc_HMIF_h_T;

/* PublicStructure Variables for Internal Data, for system '<S7>/turnON_delay' */
typedef struct {
  float32 t_wait;                      /* '<S197>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S197>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S197>/timed_delay' */
} ARID_DEF_turnON_delay_swc_HMI_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_turnON_delay_swc_HMI_T ARID_DEF_turnON_delay2;/* '<S8>/turnON_delay2' */
  ARID_DEF_turnON_delay_swc_HMI_T ARID_DEF_turnON_delay1;/* '<S8>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_HMI_T ARID_DEF_turnON_delay;/* '<S7>/turnON_delay' */
  ARID_DEF_SR_latch_swc_HMIF_h_T ARID_DEF_SR_latch;/* '<S80>/SR_latch' */
  ARID_DEF_SR_latch_swc_HMIF_T ARID_DEF_SR_latch1;/* '<S77>/SR_latch1' */
  ARID_DEF_Subsystem_swc_HMIF_h_T ARID_DEF_Subsystem;/* '<S70>/Subsystem' */
  ARID_DEF_Subsystem_swc_HMIF_T ARID_DEF_Subsystem_m;/* '<S66>/Subsystem' */
  ARID_DEF_Subsystem_swc_HMIF_h_T ARID_DEF_Subsystem_c;/* '<S56>/Subsystem' */
  ARID_DEF_SR_latch_swc_HMIF_T ARID_DEF_SR_latch_k;/* '<S47>/SR_latch' */
  ARID_DEF_Subsystem_swc_HMIF_T ARID_DEF_Subsystem_cx;/* '<S46>/Subsystem' */
  ARID_DEF_MileageCal_swc_HMIF_T ARID_DEF_MileageCal;/* '<S27>/MileageCal' */
  ARID_DEF_CsmptEngyCal_swc_HMI_T ARID_DEF_CsmptEngyCal;/* '<S27>/CsmptEngyCal' */
  float64 DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  float64 DataTypeConversion91;        /* '<Root>/Data Type Conversion91' */
  float64 DataTypeConversion7;         /* '<Root>/Data Type Conversion7' */
  float64 DataTypeConversion24;        /* '<Root>/Data Type Conversion24' */
  float64 DataTypeConversion25;        /* '<Root>/Data Type Conversion25' */
  float64 DataTypeConversion26;        /* '<Root>/Data Type Conversion26' */
  float64 DataTypeConversion58;        /* '<Root>/Data Type Conversion58' */
  float64 DataTypeConversion63;        /* '<Root>/Data Type Conversion63' */
  float64 OutportBufferFordspd_d_vehCrsDs;
  float64 OutportBufferFordspd_st_vehOver;
  float64 OutportBufferFordspd_m_vehWeigh;
  float64 OutportBufferFordspd_st_vehCalN;
  float64 OutportBufferFordspd_b_vehOvrLo;
  float64 OdometerAdd;                 /* '<S8>/OdometerAdd' */
  float64 Delay_DSTATE;                /* '<S218>/Delay' */
  float64 Delay_DSTATE_d;              /* '<S206>/Delay' */
  float64 UnitDelay5_DSTATE;           /* '<S89>/Unit Delay5' */
  float64 UnitDelay5_DSTATE_o;         /* '<S52>/Unit Delay5' */
  float64 UnitDelay5_DSTATE_k;         /* '<S40>/Unit Delay5' */
  float32 DispTm[51];                  /* '<S5>/ErrorCodeChart' */
  float32 DataTypeConversion10;        /* '<Root>/Data Type Conversion10' */
  float32 DataTypeConversion6;         /* '<Root>/Data Type Conversion6' */
  float32 DataTypeConversion13;        /* '<Root>/Data Type Conversion13' */
  float32 DataTypeConversion15;        /* '<Root>/Data Type Conversion15' */
  float32 DataTypeConversion16;        /* '<Root>/Data Type Conversion16' */
  float32 DataTypeConversion28;        /* '<Root>/Data Type Conversion28' */
  float32 DataTypeConversion29;        /* '<Root>/Data Type Conversion29' */
  float32 DataTypeConversion55;        /* '<Root>/Data Type Conversion55' */
  float32 DataTypeConversion85;        /* '<Root>/Data Type Conversion85' */
  float32 DataTypeConversion86;        /* '<Root>/Data Type Conversion86' */
  float32 DataTypeConversion90;        /* '<Root>/Data Type Conversion90' */
  float32 DataTypeConversion5;         /* '<Root>/Data Type Conversion5' */
  float32 DataTypeConversion134;       /* '<Root>/Data Type Conversion134' */
  float32 DataTypeConversion133;       /* '<Root>/Data Type Conversion133' */
  float32 DataTypeConversion84;        /* '<Root>/Data Type Conversion84' */
  float32 Switch;                      /* '<S32>/Switch' */
  float32 dspd_q_hvbSOC_pct;           /* '<S10>/1-D Lookup Table' */
  float32 UnitDelay_DSTATE;            /* '<S26>/Unit Delay' */
  float32 UnitDelay3_DSTATE;           /* '<S27>/Unit Delay3' */
  float32 UnitDelay2_DSTATE;           /* '<S34>/Unit Delay2' */
  float32 Delay2_DSTATE;               /* '<S47>/Delay2' */
  float32 Delay_DSTATE_l;              /* '<S47>/Delay' */
  float32 UnitDelay_DSTATE_c;          /* '<S58>/Unit Delay' */
  float32 UnitDelay_DSTATE_l;          /* '<S8>/Unit Delay' */
  float32 UnitDelay1_DSTATE;           /* '<S8>/Unit Delay1' */
  float32 UnitDelay_DSTATE_a;          /* '<S73>/Unit Delay' */
  float32 UnitDelay_DSTATE_ci;         /* '<S219>/Unit Delay' */
  float32 Delay1_DSTATE;               /* '<S6>/Delay1' */
  float32 Delay2_DSTATE_d;             /* '<S6>/Delay2' */
  float32 UnitDelay_DSTATE_f;          /* '<S193>/Unit Delay' */
  float32 t;                           /* '<S8>/OdometerBackup1' */
  float32 t_e;                         /* '<S8>/OdometerAdd' */
  float32 t_wait;                      /* '<S39>/timed_delay' */
  float32 Aec11;                       /* '<S27>/RollingAverage' */
  float32 Aec12;                       /* '<S27>/RollingAverage' */
  float32 Aec13;                       /* '<S27>/RollingAverage' */
  float32 Aec14;                       /* '<S27>/RollingAverage' */
  float32 Aec15;                       /* '<S27>/RollingAverage' */
  float32 Aec16;                       /* '<S27>/RollingAverage' */
  float32 Aec17;                       /* '<S27>/RollingAverage' */
  float32 Aec18;                       /* '<S27>/RollingAverage' */
  float32 Aec19;                       /* '<S27>/RollingAverage' */
  float32 Aec20;                       /* '<S27>/RollingAverage' */
  float32 Aec21;                       /* '<S27>/RollingAverage' */
  float32 Aec22;                       /* '<S27>/RollingAverage' */
  float32 Aec23;                       /* '<S27>/RollingAverage' */
  float32 Aec24;                       /* '<S27>/RollingAverage' */
  float32 Aec25;                       /* '<S27>/RollingAverage' */
  float32 Aec26;                       /* '<S27>/RollingAverage' */
  float32 Aec27;                       /* '<S27>/RollingAverage' */
  float32 Aec28;                       /* '<S27>/RollingAverage' */
  float32 Aec29;                       /* '<S27>/RollingAverage' */
  float32 Aec30;                       /* '<S27>/RollingAverage' */
  float32 Aec31;                       /* '<S27>/RollingAverage' */
  float32 Aec32;                       /* '<S27>/RollingAverage' */
  float32 Aec33;                       /* '<S27>/RollingAverage' */
  float32 Aec34;                       /* '<S27>/RollingAverage' */
  float32 Aec35;                       /* '<S27>/RollingAverage' */
  float32 Aec36;                       /* '<S27>/RollingAverage' */
  float32 Aec37;                       /* '<S27>/RollingAverage' */
  float32 Aec38;                       /* '<S27>/RollingAverage' */
  float32 Aec39;                       /* '<S27>/RollingAverage' */
  float32 Aec40;                       /* '<S27>/RollingAverage' */
  float32 Aec41;                       /* '<S27>/RollingAverage' */
  float32 Aec42;                       /* '<S27>/RollingAverage' */
  float32 Aec43;                       /* '<S27>/RollingAverage' */
  float32 Aec44;                       /* '<S27>/RollingAverage' */
  float32 Aec45;                       /* '<S27>/RollingAverage' */
  float32 Aec46;                       /* '<S27>/RollingAverage' */
  float32 Aec47;                       /* '<S27>/RollingAverage' */
  float32 Aec48;                       /* '<S27>/RollingAverage' */
  float32 Aec49;                       /* '<S27>/RollingAverage' */
  float32 Aec50;                       /* '<S27>/RollingAverage' */
  uint32 Odometerbackup_write;         /* '<S7>/odometerbackup' */
  uint32 Delay_DSTATE_h;               /* '<S7>/Delay' */
  uint16 Count;                        /* '<S7>/odometerbackup' */
  sint8 DataTypeConversion8;           /* '<Root>/Data Type Conversion8' */
  uint8 DataTypeConversion34;          /* '<Root>/Data Type Conversion34' */
  uint8 ClearCnt;                      /* '<S8>/OdometerAdd' */
  PmmStatus DataTypeConversion56;      /* '<Root>/Data Type Conversion56' */
  ParkingStatus DataTypeConversion77;  /* '<Root>/Data Type Conversion77' */
  HybModeMngr DataTypeConversion27;    /* '<Root>/Data Type Conversion27' */
  HVBRelayStatus DataTypeConversion9;  /* '<Root>/Data Type Conversion9' */
  HEVModeReq DataTypeConversion2;      /* '<Root>/Data Type Conversion2' */
  GearLeverPos DataTypeConversion61;   /* '<Root>/Data Type Conversion61' */
  DriveDir DataTypeConversion1;        /* '<Root>/Data Type Conversion1' */
  BrakePedalStatus DataTypeConversion60;/* '<Root>/Data Type Conversion60' */
  uint8 is_c4_swc_HMIF;                /* '<S8>/OdometerBackup1' */
  uint8 is_active_c4_swc_HMIF;         /* '<S8>/OdometerBackup1' */
  uint8 is_c1_swc_HMIF;                /* '<S8>/OdometerAdd' */
  uint8 is_Delay;                      /* '<S8>/OdometerAdd' */
  uint8 is_active_c1_swc_HMIF;         /* '<S8>/OdometerAdd' */
  uint8 is_c14_swc_HMIF;               /* '<S7>/odometerbackup' */
  uint8 count_enable;                  /* '<S7>/odometerbackup' */
  uint8 is_active_c14_swc_HMIF;        /* '<S7>/odometerbackup' */
  uint8 is_c12_Ricardo_SW_dev_lib;     /* '<S39>/timed_delay' */
  uint8 is_active_c12_Ricardo_SW_dev_li;/* '<S39>/timed_delay' */
  ZCSigState Delay_Reset_ZCE;          /* '<S206>/Delay' */
  boolean Delay3_DSTATE[2];            /* '<S47>/Delay3' */
  boolean LatchedList[51];             /* '<S5>/ErrorCodeChart' */
  boolean DataTypeConversion4;         /* '<Root>/Data Type Conversion4' */
  boolean DataTypeConversion14;        /* '<Root>/Data Type Conversion14' */
  boolean DataTypeConversion59;        /* '<Root>/Data Type Conversion59' */
  boolean DataTypeConversion62;        /* '<Root>/Data Type Conversion62' */
  boolean DataTypeConversion43;        /* '<Root>/Data Type Conversion43' */
  boolean DataTypeConversion45;        /* '<Root>/Data Type Conversion45' */
  boolean DataTypeConversion80;        /* '<Root>/Data Type Conversion80' */
  boolean DataTypeConversion71;        /* '<Root>/Data Type Conversion71' */
  boolean DataTypeConversion94;        /* '<Root>/Data Type Conversion94' */
  boolean DataTypeConversion95;        /* '<Root>/Data Type Conversion95' */
  boolean DataTypeConversion110;       /* '<Root>/Data Type Conversion110' */
  boolean DataTypeConversion112;       /* '<Root>/Data Type Conversion112' */
  boolean DataTypeConversion113;       /* '<Root>/Data Type Conversion113' */
  boolean DataTypeConversion111;       /* '<Root>/Data Type Conversion111' */
  boolean DataTypeConversion115;       /* '<Root>/Data Type Conversion115' */
  boolean DataTypeConversion92;        /* '<Root>/Data Type Conversion92' */
  boolean DataTypeConversion114;       /* '<Root>/Data Type Conversion114' */
  boolean DataTypeConversion116;       /* '<Root>/Data Type Conversion116' */
  boolean DataTypeConversion135;       /* '<Root>/Data Type Conversion135' */
  boolean DataTypeConversion137;       /* '<Root>/Data Type Conversion137' */
  boolean DataTypeConversion44;        /* '<Root>/Data Type Conversion44' */
  boolean DataTypeConversion132;       /* '<Root>/Data Type Conversion132' */
  boolean DataTypeConversion139;       /* '<Root>/Data Type Conversion139' */
  boolean DataTypeConversion140;       /* '<Root>/Data Type Conversion140' */
  boolean DataTypeConversion141;       /* '<Root>/Data Type Conversion141' */
  boolean DataTypeConversion11;        /* '<Root>/Data Type Conversion11' */
  boolean DataTypeConversion12;        /* '<Root>/Data Type Conversion12' */
  boolean DataTypeConversion18;        /* '<Root>/Data Type Conversion18' */
  boolean DataTypeConversion19;        /* '<Root>/Data Type Conversion19' */
  boolean DataTypeConversion20;        /* '<Root>/Data Type Conversion20' */
  boolean Compare;                     /* '<S63>/Compare' */
  boolean RelationalOperator;          /* '<S89>/Relational Operator' */
  boolean RelationalOperator_p;        /* '<S76>/Relational Operator' */
  boolean RelationalOperator_d;        /* '<S69>/Relational Operator' */
  boolean RelationalOperator_n;        /* '<S61>/Relational Operator' */
  boolean RelationalOperator_o;        /* '<S53>/Relational Operator' */
  boolean RelationalOperator_e;        /* '<S52>/Relational Operator' */
  boolean RelationalOperator_g;        /* '<S40>/Relational Operator' */
  boolean init_DSTATE;                 /* '<S26>/init' */
  boolean UnitDelay_DSTATE_h;          /* '<S27>/Unit Delay' */
  boolean UnitDelay1_DSTATE_m;         /* '<S27>/Unit Delay1' */
  boolean UnitDelay6_DSTATE;           /* '<S27>/Unit Delay6' */
  boolean UnitDelay5_DSTATE_j;         /* '<S27>/Unit Delay5' */
  boolean UnitDelay4_DSTATE;           /* '<S27>/Unit Delay4' */
  boolean DelayInput1_DSTATE;          /* '<S31>/Delay Input1' */
  boolean Delay1_DSTATE_g;             /* '<S47>/Delay1' */
  boolean DelayInput1_DSTATE_m;        /* '<S48>/Delay Input1' */
  boolean UnitDelay_DSTATE_p;          /* '<S38>/Unit Delay' */
  boolean init_DSTATE_e;               /* '<S58>/init' */
  boolean Delay_DSTATE_o;              /* '<S8>/Delay' */
  boolean DelayInput1_DSTATE_a;        /* '<S205>/Delay Input1' */
  boolean UnitDelay_DSTATE_n;          /* '<S65>/Unit Delay' */
  boolean init_DSTATE_a;               /* '<S73>/init' */
  boolean init_DSTATE_j;               /* '<S219>/init' */
  boolean init_DSTATE_o;               /* '<S193>/init' */
  boolean DelayInput1_DSTATE_j;        /* '<S204>/Delay Input1' */
  boolean UnitDelay2_DSTATE_h;         /* '<S8>/Unit Delay2' */
  boolean DelayInput1_DSTATE_i;        /* '<S203>/Delay Input1' */
  boolean UnitDelay_DSTATE_h4;         /* '<S206>/Unit Delay' */
  boolean Relay_Mode;                  /* '<S3>/Relay' */
  boolean Relay3_Mode;                 /* '<S6>/Relay3' */
  boolean Relay2_Mode;                 /* '<S6>/Relay2' */
  boolean Relay1_Mode;                 /* '<S9>/Relay1' */
  boolean TmTrig;                      /* '<S27>/RollingAverage' */
  boolean EnabledSubsystem_MODE;       /* '<S8>/Enabled Subsystem' */
  boolean Subsystem_MODE;              /* '<S88>/Subsystem' */
  boolean Subsystem_MODE_o;            /* '<S45>/Subsystem' */
} ARID_DEF_swc_HMIF_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float64 DataTypeConversion127; /* '<Root>/Data Type Conversion127' */
  const uint32 DataTypeConversion2;    /* '<S7>/Data Type Conversion2' */
  const boolean LogicalOperator10;     /* '<S3>/Logical Operator10' */
} ConstB_swc_HMIF_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_HMIF_T swc_HMIF_ARID_DEF;
extern const ConstB_swc_HMIF_T swc_HMIF_ConstB;/* constant block i/o */

/* Exported data declaration */
#define swc_HMIF_START_SEC_CONST_VOLATILE
#include "swc_HMIF_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile boolean ddic_b_BMSHealthMonErr_ovrdflg;/* Referenced by: '<S130>/DFC_ovrdflg' */
extern const volatile boolean ddic_b_BMSHealthMonErr_ovrdval;/* Referenced by: '<S130>/DFC_ovrdval' */
extern const volatile boolean ddic_b_MCUHealthMonErr_ovrdflg;/* Referenced by: '<S90>/DFC_ovrdflg' */
extern const volatile boolean ddic_b_MCUHealthMonErr_ovrdval;/* Referenced by: '<S90>/DFC_ovrdval' */
extern const volatile boolean ddic_b_VacPumpRlyErr_ovrdflg;/* Referenced by: '<S127>/DFC_ovrdflg' */
extern const volatile boolean ddic_b_VacPumpRlyErr_ovrdval;/* Referenced by: '<S127>/DFC_ovrdval' */
extern const volatile boolean ddic_b_evtFaildVacPumpLoPre_ovrdflg;/* Referenced by: '<S123>/DFC_ovrdflg' */
extern const volatile boolean ddic_b_evtFaildVacPumpLoPre_ovrdval;/* Referenced by: '<S123>/DFC_ovrdval' */
extern const volatile boolean ddic_b_evtFaildVacPumpSnr_ovrdflg;/* Referenced by: '<S122>/DFC_ovrdflg' */
extern const volatile boolean ddic_b_evtFaildVacPumpSnr_ovrdval;/* Referenced by: '<S122>/DFC_ovrdval' */
extern const volatile boolean ddic_b_evtFaildVpEnOvTmHiPre_ovrdflg;/* Referenced by: '<S124>/DFC_ovrdflg' */
extern const volatile boolean ddic_b_evtFaildVpEnOvTmHiPre_ovrdval;/* Referenced by: '<S124>/DFC_ovrdval' */
extern const volatile boolean ddic_b_evtFaildVpEnOvTmLoPre_ovrdflg;/* Referenced by: '<S125>/DFC_ovrdflg' */
extern const volatile boolean ddic_b_evtFaildVpEnOvTmLoPre_ovrdval;/* Referenced by: '<S125>/DFC_ovrdval' */
extern const volatile boolean ddic_b_evtFaildVpSysFail_ovrdflg;/* Referenced by: '<S126>/DFC_ovrdflg' */
extern const volatile boolean ddic_b_evtFaildVpSysFail_ovrdval;/* Referenced by: '<S126>/DFC_ovrdval' */
extern const volatile float32 dspc_FCHiHEVRange_mlps;/* Referenced by: '<S6>/Relay2' */

/* fuel consumption high for HEV range calculation */
extern const volatile float32 dspc_FCLoHEVRange_mlps;/* Referenced by: '<S6>/Relay2' */

/* fuel consumption low for HEV range calculation */
extern const volatile float32 dspc_X_rngAct[12];/* Referenced by:
                                                 * '<S68>/1-D Lookup Table1'
                                                 * '<S51>/1-D Lookup Table1'
                                                 */
extern const volatile float32 dspc_Y_rngVarFactor[12];/* Referenced by:
                                                       * '<S68>/1-D Lookup Table1'
                                                       * '<S51>/1-D Lookup Table1'
                                                       */
extern const volatile boolean dspc_b_ACUMsgErr_ovrdflg;/* Referenced by: '<S91>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_ACUMsgErr_ovrdval;/* Referenced by: '<S91>/DFC_ovrdval' */
extern const volatile boolean dspc_b_CSMMsgErr_ovrdflg;/* Referenced by: '<S110>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_CSMMsgErr_ovrdval;/* Referenced by: '<S110>/DFC_ovrdval' */
extern const volatile boolean dspc_b_EDCPBlockingSet_ovrdflg;/* Referenced by: '<S102>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_EDCPBlockingSet_ovrdval;/* Referenced by: '<S102>/DFC_ovrdval' */
extern const volatile boolean dspc_b_EDCPIdlySet_ovrdflg;/* Referenced by: '<S99>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_EDCPIdlySet_ovrdval;/* Referenced by: '<S99>/DFC_ovrdval' */
extern const volatile boolean dspc_b_EDCPOverCurrSet_ovrdflg;/* Referenced by: '<S98>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_EDCPOverCurrSet_ovrdval;/* Referenced by: '<S98>/DFC_ovrdval' */
extern const volatile boolean dspc_b_EDCPOverTempSet_ovrdflg;/* Referenced by: '<S97>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_EDCPOverTempSet_ovrdval;/* Referenced by: '<S97>/DFC_ovrdval' */
extern const volatile boolean dspc_b_EDCPOverVoltSet_ovrdflg;/* Referenced by: '<S100>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_EDCPOverVoltSet_ovrdval;/* Referenced by: '<S100>/DFC_ovrdval' */
extern const volatile boolean dspc_b_EDCPUnderVoltSet_ovrdflg;/* Referenced by: '<S101>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_EDCPUnderVoltSet_ovrdval;/* Referenced by: '<S101>/DFC_ovrdval' */
extern const volatile boolean dspc_b_FCAllAlowed;/* Referenced by:
                                                  * '<S6>/Constant3'
                                                  * '<S6>/Constant6'
                                                  */

/* allow to calculate HEV range according to FC level */
extern const volatile boolean dspc_b_PEPSMsgInvDataErr_ovrdflg;/* Referenced by: '<S109>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_PEPSMsgCntErr */
extern const volatile boolean dspc_b_PEPSMsgInvDataErr_ovrdval;/* Referenced by: '<S109>/DFC_ovrdval' */

/* Override value for DFC_HYB_PEPSMsgCntErr */
extern const volatile boolean dspc_b_enaDisplayEVinGear;/* Referenced by: '<S247>/Constant1' */

/* Display EV mode when Gear Lever Position is R/D/S */
extern const volatile boolean dspc_b_evtFaildABSMsgErr_ovrdflg;/* Referenced by: '<S135>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ABSMsgErr */
extern const volatile boolean dspc_b_evtFaildABSSpdMsgErr_ovrdflg;/* Referenced by: '<S92>/DFC_ovrdflg' */

/* Override value for DFC_HYB_ABSSpdMsgErr */
extern const volatile boolean dspc_b_evtFaildABSSpdMsgErr_ovrdval;/* Referenced by: '<S92>/DFC_ovrdval' */

/* Override flag for DFC_HYB_ABSSpdMsgErr */
extern const volatile boolean dspc_b_evtFaildACCPedal1ORHigh_ovrdflg;/* Referenced by: '<S134>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal1ORHigh */
extern const volatile boolean dspc_b_evtFaildACCPedal1ORHigh_ovrdval;/* Referenced by: '<S134>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal1ORHigh */
extern const volatile boolean dspc_b_evtFaildACCPedal1ORLow_ovrdflg;/* Referenced by: '<S133>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal1ORLow */
extern const volatile boolean dspc_b_evtFaildACCPedal1ORLow_ovrdval;/* Referenced by: '<S133>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal1ORLow */
extern const volatile boolean dspc_b_evtFaildACCPedal1SCB_ovrdflg;/* Referenced by: '<S132>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal1SCB */
extern const volatile boolean dspc_b_evtFaildACCPedal1SCB_ovrdval;/* Referenced by: '<S132>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal1SCB */
extern const volatile boolean dspc_b_evtFaildACCPedal1SCG_ovrdflg;/* Referenced by: '<S131>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal1SCG */
extern const volatile boolean dspc_b_evtFaildACCPedal1SCG_ovrdval;/* Referenced by: '<S131>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal1SCG */
extern const volatile boolean dspc_b_evtFaildACCPedal2ORHigh_ovrdflg;/* Referenced by: '<S139>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal2ORHigh */
extern const volatile boolean dspc_b_evtFaildACCPedal2ORHigh_ovrdval;/* Referenced by: '<S139>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal2ORHigh */
extern const volatile boolean dspc_b_evtFaildACCPedal2ORLow_ovrdflg;/* Referenced by: '<S138>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal2ORLow */
extern const volatile boolean dspc_b_evtFaildACCPedal2ORLow_ovrdval;/* Referenced by: '<S138>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal2ORLow */
extern const volatile boolean dspc_b_evtFaildACCPedal2SCB_ovrdflg;/* Referenced by: '<S137>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal2SCB */
extern const volatile boolean dspc_b_evtFaildACCPedal2SCB_ovrdval;/* Referenced by: '<S137>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal2SCB */
extern const volatile boolean dspc_b_evtFaildACCPedal2SCG_ovrdflg;/* Referenced by: '<S136>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedal2SCG */
extern const volatile boolean dspc_b_evtFaildACCPedal2SCG_ovrdval;/* Referenced by: '<S136>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedal2SCG */
extern const volatile boolean dspc_b_evtFaildACCPedalCrossNP_ovrdflg;/* Referenced by: '<S111>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_ACCPedalCrossNP */
extern const volatile boolean dspc_b_evtFaildACCPedalCrossNP_ovrdval;/* Referenced by: '<S111>/DFC_ovrdval' */

/* Override value for DFC_HYB_ACCPedalCrossNP */
extern const volatile boolean dspc_b_evtFaildBMSFaultLevel2A_ovrdflg;/* Referenced by: '<S119>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_evtFaildBMSFaultLevel2A_ovrdval;/* Referenced by: '<S119>/DFC_ovrdval' */
extern const volatile boolean dspc_b_evtFaildBMSFaultLevel3A_ovrdflg;/* Referenced by: '<S112>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_evtFaildBMSFaultLevel3A_ovrdval;/* Referenced by: '<S112>/DFC_ovrdval' */
extern const volatile boolean dspc_b_evtFaildBMSFaultLevel4A_ovrdflg;/* Referenced by: '<S128>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_evtFaildBMSFaultLevel4A_ovrdval;/* Referenced by: '<S128>/DFC_ovrdval' */
extern const volatile boolean dspc_b_evtFaildBrkSthNP_ovrdflg;/* Referenced by: '<S114>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_BrkSthNP */
extern const volatile boolean dspc_b_evtFaildBrkSthNP_ovrdval;/* Referenced by: '<S114>/DFC_ovrdval' */

/* Override value for DFC_HYB_BrkSthNP */
extern const volatile boolean dspc_b_evtFaildCrashEvent_ovrdflg;/* Referenced by: '<S117>/DFC_ovrdflg' */

/* Override value for DFC_HYB_CrashEvent */
extern const volatile boolean dspc_b_evtFaildCrashEvent_ovrdval;/* Referenced by: '<S117>/DFC_ovrdval' */

/* Override flag for DFC_HYB_CrashEvent */
extern const volatile boolean dspc_b_evtFaildEGSMMsgErr_ovrdflg;/* Referenced by: '<S140>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_EGSMMsgErr */
extern const volatile boolean dspc_b_evtFaildEGSMMsgErr_ovrdval;/* Referenced by: '<S140>/DFC_ovrdval' */

/* Override value for DFC_HYB_EGSMMsgErr */
extern const volatile boolean dspc_b_evtFaildEPCANBusoff_ovrdflg;/* Referenced by: '<S94>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_EPCANBusoff */
extern const volatile boolean dspc_b_evtFaildEPCANBusoff_ovrdval;/* Referenced by: '<S94>/DFC_ovrdval' */

/* Override value for DFC_HYB_EPCANBusoff */
extern const volatile boolean dspc_b_evtFaildEVCANBusoff_ovrdflg;/* Referenced by: '<S121>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_evtFaildEVCANBusoff_ovrdval;/* Referenced by: '<S121>/DFC_ovrdval' */
extern const volatile boolean dspc_b_evtFaildMCUFaultLevel2A_ovrdflg;/* Referenced by: '<S113>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_evtFaildMCUFaultLevel2A_ovrdval;/* Referenced by: '<S113>/DFC_ovrdval' */
extern const volatile boolean dspc_b_evtFaildMCUFaultLevel3A_ovrdflg;/* Referenced by: '<S120>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_evtFaildMCUFaultLevel3A_ovrdval;/* Referenced by: '<S120>/DFC_ovrdval' */
extern const volatile boolean dspc_b_evtFaildPwrSuplyORHigh_ovrdflg;/* Referenced by: '<S118>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_PwrSuplyORHigh */
extern const volatile boolean dspc_b_evtFaildPwrSuplyORHigh_ovrdval;/* Referenced by: '<S118>/DFC_ovrdval' */

/* Override value for DFC_HYB_PwrSuplyORHigh */
extern const volatile boolean dspc_b_evtFaildPwrSuplyORLow_ovrdflg;/* Referenced by: '<S116>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_PwrSuplyORLow */
extern const volatile boolean dspc_b_evtFaildPwrSuplyORLow_ovrdval;/* Referenced by: '<S116>/DFC_ovrdval' */

/* Override value for DFC_HYB_PwrSuplyORLow */
extern const volatile boolean dspc_b_evtFaildT5V1Mon_ovrdflg;/* Referenced by: '<S93>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_T5V1Mon */
extern const volatile boolean dspc_b_evtFaildT5V1Mon_ovrdval;/* Referenced by: '<S93>/DFC_ovrdval' */

/* Override value for DFC_HYB_T5V1Mon */
extern const volatile boolean dspc_b_evtFaildT5V2Mon_ovrdflg;/* Referenced by: '<S96>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_T5V2Mon */
extern const volatile boolean dspc_b_evtFaildT5V2Mon_ovrdval;/* Referenced by: '<S96>/DFC_ovrdval' */

/* Override value for DFC_HYB_T5V2Mon */
extern const volatile boolean dspc_b_evtFaildTPCANBusoff_ovrdflg;/* Referenced by: '<S95>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_TPCANBusoff */
extern const volatile boolean dspc_b_evtFaildTPCANBusoff_ovrdval;/* Referenced by: '<S95>/DFC_ovrdval' */

/* Override value for DFC_HYB_TPCANBusoff */
extern const volatile boolean dspc_b_evtFaildVehicleHVILFlt_ovrdflg;/* Referenced by: '<S115>/DFC_ovrdflg' */

/* Override value for DFC_HYB_VehicleHVILFlt */
extern const volatile boolean dspc_b_evtFaildVehicleHVILFlt_ovrdval;/* Referenced by: '<S115>/DFC_ovrdval' */

/* Override flag for DFC_HYB_VehicleHVILFlt */
extern const volatile boolean dspc_b_hbcpBlock_ovrdflg;/* Referenced by: '<S107>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_hbcpBlock_ovrdval;/* Referenced by: '<S107>/DFC_ovrdval' */
extern const volatile boolean dspc_b_hbcpIdly_ovrdflg;/* Referenced by: '<S104>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_hbcpIdly_ovrdval;/* Referenced by: '<S104>/DFC_ovrdval' */
extern const volatile boolean dspc_b_hbcpOvrCurr_ovrdflg;/* Referenced by: '<S108>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_hbcpOvrCurr_ovrdval;/* Referenced by: '<S108>/DFC_ovrdval' */
extern const volatile boolean dspc_b_hbcpOvrTmp_ovrdflg;/* Referenced by: '<S105>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_hbcpOvrTmp_ovrdval;/* Referenced by: '<S105>/DFC_ovrdval' */
extern const volatile boolean dspc_b_hbcpOvrVolt_ovrdflg;/* Referenced by: '<S106>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_hbcpOvrVolt_ovrdval;/* Referenced by: '<S106>/DFC_ovrdval' */
extern const volatile boolean dspc_b_hbcpUdVolt_ovrdflg;/* Referenced by: '<S103>/DFC_ovrdflg' */
extern const volatile boolean dspc_b_hbcpUdVolt_ovrdval;/* Referenced by: '<S103>/DFC_ovrdval' */
extern const volatile boolean dspc_b_nvmDataWriteAec_ovrdflg;
                     /* Referenced by: '<S41>/dspc_b_nvmDataWriteAec_ovrdflg' */
extern const volatile boolean dspc_b_odoClearCntOvrdFlg;/* Referenced by: '<S8>/Constant17' */
extern const volatile boolean dspc_b_phevOvrEvBtn;/* Referenced by: '<S13>/Constant3' */

/* PHEV hybrid powertrain mode overrides the EV button press for the purposes of determining the Drive Mode */
extern const volatile boolean dspc_b_sportModDspEnb;/* Referenced by: '<S13>/Constant7' */
extern const volatile boolean dspc_b_useFuelRateForFC;/* Referenced by: '<S218>/Constant1' */

/* Use Fuel Rate for FC calculation */
extern const volatile float32 dspc_d_aecCellMileage_km;/* Referenced by: '<S27>/Constant16' */
extern const volatile float32 dspc_d_odoBckpDiff_km;/* Referenced by:
                                                     * '<S8>/Constant15'
                                                     * '<S8>/Constant16'
                                                     */
extern const volatile float32 dspc_d_odoWriteSet_km;/* Referenced by: '<S206>/Constant17' */
extern const volatile float32 dspc_d_storedDynRange;/* Referenced by: '<S68>/Constant' */
extern const volatile float32 dspc_d_vehDrvRngInvalid_km;
                                 /* Referenced by: '<S65>/InvalidValue_0X3FF' */
extern const volatile float32 dspc_d_vehDrvRngStdInvalid;
                                 /* Referenced by: '<S38>/InvalidValue_0XFFF' */
extern const volatile float32 dspc_dn_RngDecGradH;/* Referenced by:
                                                   * '<S65>/Constant24'
                                                   * '<S38>/Constant24'
                                                   */
extern const volatile float32 dspc_dn_RngDecGradL;/* Referenced by: '<S65>/Constant27' */
extern const volatile float32 dspc_dn_RngIncGradH;/* Referenced by:
                                                   * '<S65>/Constant13'
                                                   * '<S38>/Constant13'
                                                   */
extern const volatile float32 dspc_dn_RngIncGradL;/* Referenced by: '<S65>/Constant26' */
extern const volatile float32 dspc_dn_StdRngDecGradL;/* Referenced by: '<S38>/Constant27' */
extern const volatile float32 dspc_dn_StdRngIncGradL;/* Referenced by: '<S38>/Constant26' */
extern const volatile float32 dspc_dn_aecDecGrad_kWhp100km;/* Referenced by: '<S27>/Constant14' */

/* AEC decrease gradient */
extern const volatile float32 dspc_dn_aecIncGrad_kWhp100km;/* Referenced by: '<S27>/Constant13' */

/* AEC increase gradient */
extern const volatile DisplayLampMode dspc_e_lampMode;/* Referenced by: '<S220>/Constant' */

/* Lamp lighting strategy choice */
extern const volatile float32 dspc_num_AecMin_kWhp100km;/* Referenced by:
                                                         * '<S27>/Constant1'
                                                         * '<S27>/Unit Delay3'
                                                         */

/* AEC Cell Minimum Value */
extern const volatile float32 dspc_num_nvmDataWriteAec_ovrdval;
                   /* Referenced by: '<S41>/dspc_num_nvmDataWriteAec_ovrdval' */
extern const volatile float32 dspc_pwr_AECHiLimit;/* Referenced by:
                                                   * '<S36>/Constant1'
                                                   * '<S44>/Constant'
                                                   */
extern const volatile float32 dspc_pwr_AECLowLimit;/* Referenced by:
                                                    * '<S36>/Constant'
                                                    * '<S43>/Constant'
                                                    */
extern const volatile float32 dspc_pwr_eadActiveThold_kW;/* Referenced by: '<S14>/Constant2' */

/* Threshold for ICU to consider the EAD active */
extern const volatile float32 dspc_q_socLowAcDnThd;/* Referenced by: '<S3>/Relay' */
extern const volatile float32 dspc_q_socLowAcUpThd;/* Referenced by: '<S3>/Relay' */
extern const volatile boolean dspc_st_odoClearCntOvrdVal;/* Referenced by: '<S8>/Constant' */
extern const volatile float32 dspc_t_ipkOdoBckUp_s;/* Referenced by: '<S7>/Constant19' */
extern const volatile float32 dspc_tm_DisplayTime_s;/* Referenced by: '<S5>/Constant_disp' */

/* Display time threshold */
extern const volatile float32 dspc_tm_FCFilter_s;/* Referenced by: '<S218>/Constant7' */

/* Fuel Consumption Time constant filter */
extern const volatile float32 dspc_tm_HEVRangeFilter_s;/* Referenced by: '<S6>/Constant1' */

/* HEV range Time constant filter */
extern const volatile float32 dspc_tm_bcmOdoDebd_s;/* Referenced by: '<S8>/Constant11' */
extern const volatile float32 dspc_tm_drRngDelay;/* Referenced by:
                                                  * '<S40>/Constant1'
                                                  * '<S69>/Constant1'
                                                  * '<S52>/Constant1'
                                                  * '<S53>/Constant1'
                                                  */
extern const volatile float32 dspc_tm_hvPwrCsmptFilter_s;/* Referenced by: '<S23>/Constant15' */

/* HV power consumption constant filter */
extern const volatile float32 dspc_tm_ipkOdoDebd_s;/* Referenced by: '<S8>/Constant10' */
extern const volatile float32 dspc_tm_nvmReadHold_s;/* Referenced by: '<S27>/Constant8' */
extern const volatile float32 dspc_tm_rangeCrtnwkUpDly;/* Referenced by:
                                                        * '<S76>/Constant1'
                                                        * '<S61>/Constant1'
                                                        */
extern const volatile float32 dspc_tq_motorActiveThold;/* Referenced by: '<S14>/Constant1' */

/* Threshold for ICU to consider the EAD active */
extern const volatile float32 dspc_v_defaultVehSpdforFC_kph;/* Referenced by: '<S9>/Constant4' */

/* default vehicle speed for average fuel consumption calculation */
extern const volatile float32 dspc_v_dfltVehSpdHEVRange_kph;/* Referenced by: '<S6>/Constant5' */

/* default vehicle speed for HEV range */
extern const volatile float32 dspc_v_vehSpdHiFC_kph;/* Referenced by: '<S9>/Relay1' */

/* vehicle speed high for average fuel consumption calculation */
extern const volatile float32 dspc_v_vehSpdHiHEVRange_kph;/* Referenced by: '<S6>/Relay3' */

/* vehicle speed high for HEV range calculation */
extern const volatile float32 dspc_v_vehSpdLoFC_kph;/* Referenced by: '<S9>/Relay1' */

/* vehicle speed low for average fuel consumption calculation */
extern const volatile float32 dspc_v_vehSpdLoHEVRange_kph;/* Referenced by: '<S6>/Relay3' */

/* vehicle speed low for HEV range calculation */
extern const volatile float32 dspc_v_vehStopSpd_kph;/* Referenced by: '<S27>/Constant25' */
extern const volatile boolean dspd_b_odoTotal2NVM_ovrdflg;/* Referenced by: '<S8>/Constant23' */
extern const volatile float32 dspd_b_odoTotal2NVM_ovrdval;/* Referenced by: '<S8>/Constant22' */
extern const volatile float32 dspd_d_distRange;/* Referenced by: '<S8>/Constant30' */
extern const volatile float32 dspd_num_AecLowLim;/* Referenced by: '<S32>/Constant1' */
extern const volatile float32 dspd_num_AecUpLim;/* Referenced by: '<S32>/Constant9' */
extern const volatile float32 dspv_SOCDisplayMap_X_SOC_pct[8];
                                   /* Referenced by: '<S10>/1-D Lookup Table' */

/* SOC Display Map - Battery SOC Axis */
extern const volatile float32 dspv_SOCDisplayMap_Y_pct[8];
                                   /* Referenced by: '<S10>/1-D Lookup Table' */

/* SOC Display Map - Displayed SOC */
extern const volatile boolean swchmif_ddic_b_evtFaildABSMsgErr_ovrdval;/* Referenced by: '<S135>/DFC_ovrdval' */

/* Override value for DFC_HYB_ABSMsgErr */
extern const volatile boolean swchmif_ddic_b_evtFaildDCDCMsgErr_ovrdflg;/* Referenced by: '<S129>/DFC_ovrdflg' */

/* Override flag for DFC_HYB_DCDCMsgErr */
extern const volatile boolean swchmif_ddic_b_evtFaildDCDCMsgErr_ovrdval;/* Referenced by: '<S129>/DFC_ovrdval' */

/* Override value for DFC_HYB_DCDCMsgErr */
#define swc_HMIF_STOP_SEC_CONST_VOLATILE
#include "swc_HMIF_MemMap.h"
#define swc_HMIF_START_SEC_VAR
#include "swc_HMIF_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern float32 Aec1;                   /* '<S27>/RollingAverage' */

/* AEC1 */
extern float32 Aec10;                  /* '<S27>/RollingAverage' */

/* AEC10 */
extern float32 Aec2;                   /* '<S27>/RollingAverage' */

/* AEC2 */
extern float32 Aec3;                   /* '<S27>/RollingAverage' */

/* AEC3 */
extern float32 Aec4;                   /* '<S27>/RollingAverage' */

/* AEC4 */
extern float32 Aec5;                   /* '<S27>/RollingAverage' */

/* AEC5 */
extern float32 Aec6;                   /* '<S27>/RollingAverage' */

/* AEC6 */
extern float32 Aec7;                   /* '<S27>/RollingAverage' */

/* AEC7 */
extern float32 Aec8;                   /* '<S27>/RollingAverage' */

/* AEC8 */
extern float32 Aec9;                   /* '<S27>/RollingAverage' */

/* AEC9 */
extern uint8 Cntr;                     /* '<S27>/RollingAverage' */

/* AEC Rolling Average Counter */
extern uint8 dspd_ST;                  /* '<S8>/OdometerAdd' */
extern float32 dspd_V_engFuelConsAvg_lp100km;/* '<S9>/Divide' */

/* average fuel consumption in L/100km  */
extern boolean dspd_b_ABSMsgErr;       /* '<S186>/Switch2' */

/* Lost Communication with ABS */
extern boolean dspd_b_ABSSpdMsgErr;    /* '<S143>/Switch2' */

/* DFC_HYB_ABSSpdMsgErr Fault */
extern boolean dspd_b_ACCPedal1ORHigh; /* '<S185>/Switch2' */

/* Throttle Position Sensor/Switch "G" Circuit Range/Performance */
extern boolean dspd_b_ACCPedal1ORLow;  /* '<S184>/Switch2' */

/* Throttle Position Sensor/Switch "G" Circuit Range/Performance */
extern boolean dspd_b_ACCPedal1SCB;    /* '<S183>/Switch2' */

/* DFC_HYB_ACCPedal1SCB Fault */
extern boolean dspd_b_ACCPedal1SCG;    /* '<S182>/Switch2' */

/* DFC_HYB_ACCPedal1SCG Fault */
extern boolean dspd_b_ACCPedal2ORHigh; /* '<S190>/Switch2' */

/* Throttle/Pedal Position Sensor/Switch "F" Circuit Range/Performance */
extern boolean dspd_b_ACCPedal2ORLow;  /* '<S189>/Switch2' */

/* Throttle/Pedal Position Sensor/Switch "F" Circuit Range/Performance */
extern boolean dspd_b_ACCPedal2SCB;    /* '<S188>/Switch2' */

/* DFC_HYB_ACCPedal2SCB Fault */
extern boolean dspd_b_ACCPedal2SCG;    /* '<S187>/Switch2' */

/* DFC_HYB_ACCPedal2SCG Fault */
extern boolean dspd_b_ACCPedalCrossNP; /* '<S162>/Switch2' */

/* Throttle/Pedal Position Sensor/Switch "F"/"G" Voltage Correlation */
extern boolean dspd_b_ACUMsgErr;       /* '<S142>/Switch2' */
extern boolean dspd_b_BMSFaultLevel2;  /* '<S170>/Switch2' */
extern boolean dspd_b_BMSHealthMonErr; /* '<S181>/Switch2' */
extern boolean dspd_b_BrkSthNP;        /* '<S165>/Switch2' */

/* Brake Switch "A"/"B" Correlation */
extern boolean dspd_b_CSMMsgErr;       /* '<S161>/Switch2' */
extern boolean dspd_b_CrashEvent;      /* '<S168>/Switch2' */
extern boolean dspd_b_DCDCMsgErr;      /* '<S180>/Switch2' */

/* Lost Communication with DCDC */
extern boolean dspd_b_EDCPBlocking;    /* '<S153>/Switch2' */

/* DFC_HYB_EDCP Blocking protection */
extern boolean dspd_b_EDCPIdly;        /* '<S150>/Switch2' */

/* DFC_HYB_EDCP Idly protection */
extern boolean dspd_b_EDCPOverCurr;    /* '<S149>/Switch2' */

/* DFC_HYB_EDCP Overcurrent protection */
extern boolean dspd_b_EDCPOverTemp;    /* '<S148>/Switch2' */

/* DFC_HYB_EDCP Over temp protection */
extern boolean dspd_b_EDCPOverVolt;    /* '<S151>/Switch2' */

/* DFC_HYB_EDCP Overpressure protection */
extern boolean dspd_b_EDCPUnderVolt;   /* '<S152>/Switch2' */

/* DFC_HYB_EDCP Undervoltage protection */
extern boolean dspd_b_EGSMMsgErr;      /* '<S191>/Switch2' */

/* Lost Communication with EGSM */
extern boolean dspd_b_EPCANBusoff;     /* '<S145>/Switch2' */

/* DFC_HYB_EPCANBusoff Fault */
extern boolean dspd_b_EVCANBusoff;     /* '<S172>/Switch2' */
extern boolean dspd_b_HBCPBlock;       /* '<S158>/Switch2' */

/* DFC_HYB_HBCP Blocking protection */
extern boolean dspd_b_HBCPOvrCurr;     /* '<S159>/Switch2' */

/* DFC_HYB_HBCP Overcurrent protection */
extern boolean dspd_b_HBCPOvrTmp;      /* '<S156>/Switch2' */

/* DFC_HYB_HBCP Overpressure protection */
extern boolean dspd_b_HBCPOvrVolt;     /* '<S157>/Switch2' */

/* DFC_HYB_HBCP Overpressure protection */
extern boolean dspd_b_HBCPUdVolt;      /* '<S154>/Switch2' */

/* DFC_HYB_HBCP Overpressure protection */
extern boolean dspd_b_HazardReqLmpOn;  /* '<S192>/Logical Operator3' */
extern boolean dspd_b_HbcpIdly;        /* '<S155>/Switch2' */

/* DFC_HYB_HBCP Idly protection */
extern boolean dspd_b_MCUFaultLevel2;  /* '<S164>/Switch2' */
extern boolean dspd_b_MCUHealthMonErr; /* '<S141>/Switch2' */
extern boolean dspd_b_OdoAddEn;        /* '<S8>/Logical Operator' */
extern boolean dspd_b_PEPSMsgInvDataErr;/* '<S160>/Switch2' */

/* PEPS_PMSTrqCtrl Counter Error */
extern boolean dspd_b_PwrSuplyORHigh;  /* '<S169>/Switch2' */

/* System Voltage High */
extern boolean dspd_b_PwrSuplyORLow;   /* '<S167>/Switch2' */

/* System Voltage Low */
extern uint8 dspd_b_RoutineResultSet;  /* '<S8>/Switch7' */
extern boolean dspd_b_T5V1Mon;         /* '<S144>/Switch2' */

/* Sensor Reference Voltage "1" Circuit/Open */
extern boolean dspd_b_T5V2Mon;         /* '<S147>/Switch2' */

/* Sensor Reference Voltage "2" Circuit/Open */
extern boolean dspd_b_TPCANBusoff;     /* '<S146>/Switch2' */

/* DFC_HYB_TPCANBusoff Fault */
extern boolean dspd_b_VacPumpEnOvrTmHiPreFlt;/* '<S175>/Switch2' */
extern boolean dspd_b_VacPumpEnOvrTmLoPreFlt;/* '<S176>/Switch2' */
extern boolean dspd_b_VacPumpLoPreFlt; /* '<S174>/Switch2' */
extern boolean dspd_b_VacPumpRlyErr;   /* '<S178>/Switch2' */
extern boolean dspd_b_VacPumpSnrFlt;   /* '<S173>/Switch2' */
extern boolean dspd_b_VacPumpSysFailFlt;/* '<S177>/Switch2' */
extern boolean dspd_b_VehicleHVILFlt;  /* '<S166>/Switch2' */
extern boolean dspd_b_bcmOdoValid;     /* '<S8>/Logical Operator2' */
extern boolean dspd_b_bmsFltLvl3;      /* '<S163>/Switch2' */

/* BMS Fault Level 3 */
extern boolean dspd_b_bmsFltLvl4;      /* '<S179>/Switch2' */
extern boolean dspd_b_brkSysFlt;       /* '<S81>/Logical Operator8' */

/* Brake System Fault */
extern boolean dspd_b_ePTFault;        /* '<S82>/Logical Operator8' */
extern boolean dspd_b_evLampOn;        /* '<S11>/Logical Operator2' */
extern boolean dspd_b_hevLampOn;       /* '<S11>/Logical Operator1' */
extern boolean dspd_b_ignOFFodoWriteEn;/* '<S204>/FixPt Relational Operator' */
extern boolean dspd_b_ipkOdoValid;     /* '<S8>/Logical Operator1' */
extern boolean dspd_b_mcuFltLvl3;      /* '<S171>/Switch2' */

/* Motor Fault Level 3 */
extern boolean dspd_b_odoBckpChgValid; /* '<S8>/Logical Operator3' */
extern boolean dspd_b_odoBckpEn;       /* '<S8>/OdometerBackup1' */
extern boolean dspd_b_odoClearActv;    /* '<S8>/C Caller' */
extern boolean dspd_b_odoWriteEn;      /* '<S8>/OR' */
extern boolean dspd_b_rtStorageEn;     /* '<S206>/Relational Operator11' */
extern boolean dspd_b_turtleLmpOn;     /* '<S83>/Logical Operator7' */
extern float32 dspd_dV_engFuelConsInst_mlps;/* '<S219>/Data Type Conversion3' */

/* instantaneous fuel consumption in ml/s  */
extern float64 dspd_d_MileageInit;     /* '<S8>/Switch10' */
extern float32 dspd_d_dynRngMapVal;    /* '<S68>/Product' */
extern float32 dspd_d_dynamicRange;    /* '<S64>/Switch1' */
extern float64 dspd_d_odoBckp_km;      /* '<S8>/OdometerBackup1' */
extern float32 dspd_d_odoRead_float;   /* '<S8>/Switch' */
extern float32 dspd_d_odoRead_km;      /* '<S8>/Max' */
extern float32 dspd_d_odoRead_u32;     /* '<S8>/Switch5' */
extern float32 dspd_d_odoTotal_km;     /* '<S8>/Switch1' */
extern float32 dspd_d_odoWrite_km;     /* '<S8>/Switch3' */
extern float32 dspd_d_pmsOdoBckUpMilg_km;/* '<S7>/Data Type Conversion1' */

/* pms Odo BackUp Mileage */
extern float32 dspd_d_standardRange;   /* '<S37>/Switch9' */
extern float32 dspd_d_stdRng2NVM;      /* '<S47>/Switch1' */
extern float32 dspd_d_stdRngDecRate;   /* '<S47>/Switch4' */
extern float32 dspd_d_stdRngLatVal;    /* '<S47>/Switch' */
extern float32 dspd_d_stdRngMapVal;    /* '<S51>/Product' */
extern float32 dspd_d_vehDrvRngDynamic_km;/* '<S24>/Divide5' */
extern float32 dspd_d_vehDrvRngEVMod_km;/* '<S65>/Switch4' */

/* Drive Range in EV Mode */
extern float32 dspd_d_vehDrvRngHEVModUnfilt_km;/* '<S6>/Switch1' */

/* Unfiltered Drive Range in HEV Mode */
extern float32 dspd_d_vehDrvRngHEVMod_km;/* '<S193>/Data Type Conversion3' */

/* Drive Range in HEV Mode */
extern float32 dspd_d_vehDrvRngStandardRaw_km;/* '<S27>/Product1' */
extern float32 dspd_d_vehDrvRngStandard_km;/* '<S38>/Switch10' */
extern PowerFlowMode dspd_e_vehPwrFlow;/* '<S14>/Switch' */
extern float32 dspd_num_AecCell_kWhp100km;/* '<S36>/Switch1' */

/* AEC Cell in EV Mode */
extern float32 dspd_num_AecEV_kWhp100km;/* '<S27>/Switch1' */

/* AEC in EV Mode */
extern float32 dspd_num_AecInit_kWhp100km;/* '<S37>/Constant10' */
extern float32 dspd_num_AecRaw_kWhp100km;/* '<S27>/RollingAverage' */

/* AEC Raw in EV Mode */
extern float32 dspd_num_errorCode;     /* '<S5>/Data Type Conversion' */

/* Error code */
extern float32 dspd_num_nvmDataReadAec;/* '<S27>/C Caller25' */
extern float32 dspd_num_nvmDataWriteAec;/* '<S42>/Switch2' */
extern float32 dspd_pwr_hvPwrCsmpt_kW; /* '<S26>/Data Type Conversion3' */

/* HV power consumption */
extern float32 dspd_pwr_hvPwrRemain_kW;/* '<S25>/MinMax2' */

/* HV power remain */
extern uint8 dspd_st_drvModInd;        /* '<S13>/Switch7' */
extern uint16 dspd_st_drvPfmncRedn;    /* '<S77>/Switch4' */
extern uint8 dspd_st_drvrOptRmdr;      /* '<S3>/Multiport Switch' */
extern uint8 dspd_st_nvmMileageClrCnt; /* '<S8>/C Caller3' */
extern uint8 dspd_st_odoClrCntRead;    /* '<S8>/Switch4' */
extern uint8 dspd_st_odoClrCntWrite;   /* '<S8>/Switch2' */
extern uint8 dspd_st_vehDrvMode;       /* '<S13>/Switch9' */
extern uint8 dspd_st_vehFailLvl;       /* '<S12>/maxerrlevel1' */
extern uint8 dspd_st_vehSubFailLvl;    /* '<S12>/maxerrlevel2' */
extern float64 dspd_v_vehSpd;          /* '<S8>/Data Type Conversion2' */

#define swc_HMIF_STOP_SEC_VAR
#include "swc_HMIF_MemMap.h"

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
 * '<Root>' : 'swc_HMIF'
 * '<S1>'   : 'swc_HMIF/HMIF_Human_Machine_Interface'
 * '<S2>'   : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display'
 * '<S3>'   : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Driver_Operation_Reminder'
 * '<S4>'   : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range'
 * '<S5>'   : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code'
 * '<S6>'   : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/HEV_range'
 * '<S7>'   : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Mileage_Backup'
 * '<S8>'   : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal'
 * '<S9>'   : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/average_fuel_consumption'
 * '<S10>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_calc_disp_soc'
 * '<S11>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_lamps'
 * '<S12>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_map_errorlevel'
 * '<S13>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode'
 * '<S14>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow'
 * '<S15>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/model_info1'
 * '<S16>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Driver_Operation_Reminder/Compare To Constant'
 * '<S17>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Driver_Operation_Reminder/Enumerated Constant'
 * '<S18>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Driver_Operation_Reminder/Enumerated Constant1'
 * '<S19>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Driver_Operation_Reminder/Enumerated Constant2'
 * '<S20>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Driver_Operation_Reminder/Enumerated Constant4'
 * '<S21>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Driver_Operation_Reminder/Enumerated Constant5'
 * '<S22>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Driver_Operation_Reminder/Enumerated Constant3'
 * '<S23>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation'
 * '<S24>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation'
 * '<S25>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/RemainPowerCalculation'
 * '<S26>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/1st Order Filter  '
 * '<S27>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation'
 * '<S28>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/1-0'
 * '<S29>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/AecNvmDataWrite'
 * '<S30>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/CsmptEngyCal'
 * '<S31>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Detect Decrease'
 * '<S32>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Limit'
 * '<S33>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/MileageCal'
 * '<S34>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/RateLimitEnable'
 * '<S35>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/RollingAverage'
 * '<S36>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem'
 * '<S37>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1'
 * '<S38>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/rangeCorrection3'
 * '<S39>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/turnOFF_delay2'
 * '<S40>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/1-0/Subsystem'
 * '<S41>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/AecNvmDataWrite/Ovrd_st_Aec'
 * '<S42>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/AecNvmDataWrite/Ovrd_st_Aec/override_signal'
 * '<S43>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem/Compare To Constant'
 * '<S44>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem/Compare To Constant1'
 * '<S45>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/0-1'
 * '<S46>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/1-0'
 * '<S47>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/D'
 * '<S48>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/Detect Decrease'
 * '<S49>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/Limit1'
 * '<S50>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/Subsystem'
 * '<S51>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/Subsystem2'
 * '<S52>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/0-1/Subsystem'
 * '<S53>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/1-0/Subsystem'
 * '<S54>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/D/SR_latch'
 * '<S55>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/Subsystem1/Subsystem2/Interval Test'
 * '<S56>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/rangeCorrection3/1-0'
 * '<S57>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/rangeCorrection3/Enumerated Constant'
 * '<S58>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/rangeCorrection3/RateLimit'
 * '<S59>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/rangeCorrection3/bmsMsgErr'
 * '<S60>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/rangeCorrection3/bmsMsgErr1'
 * '<S61>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/rangeCorrection3/1-0/Subsystem'
 * '<S62>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/AecCalculation/AecAccumulation/turnOFF_delay2/timed_delay'
 * '<S63>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/Compare To Constant3'
 * '<S64>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/Subsystem3'
 * '<S65>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/rangeCorrection2'
 * '<S66>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/Subsystem3/1-0'
 * '<S67>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/Subsystem3/Limit'
 * '<S68>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/Subsystem3/Subsystem2'
 * '<S69>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/Subsystem3/1-0/Subsystem'
 * '<S70>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/rangeCorrection2/1-0'
 * '<S71>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/rangeCorrection2/Compare To Constant'
 * '<S72>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/rangeCorrection2/Enumerated Constant'
 * '<S73>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/rangeCorrection2/RateLimit'
 * '<S74>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/rangeCorrection2/bmsBusoff'
 * '<S75>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/rangeCorrection2/bmsMsgErr'
 * '<S76>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/EV&APU_range/DteCalculation/rangeCorrection2/1-0/Subsystem'
 * '<S77>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/DIM_LmpOn'
 * '<S78>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodeChart'
 * '<S79>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition'
 * '<S80>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/HazardLmpOn'
 * '<S81>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/brkSysFlt_LmpOn'
 * '<S82>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ePTFault_LmpOn'
 * '<S83>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/turtleLmpOn'
 * '<S84>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/DIM_LmpOn/Compare To Constant'
 * '<S85>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/DIM_LmpOn/Enumerated Constant'
 * '<S86>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/DIM_LmpOn/Enumerated Constant1'
 * '<S87>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/DIM_LmpOn/SR_latch1'
 * '<S88>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/DIM_LmpOn/TurnON_Delay5S'
 * '<S89>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/DIM_LmpOn/TurnON_Delay5S/Subsystem'
 * '<S90>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd1'
 * '<S91>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd104'
 * '<S92>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd105'
 * '<S93>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd15'
 * '<S94>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd157'
 * '<S95>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd158'
 * '<S96>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd16'
 * '<S97>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd165'
 * '<S98>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd166'
 * '<S99>'  : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd175'
 * '<S100>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd176'
 * '<S101>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd177'
 * '<S102>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd178'
 * '<S103>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd188'
 * '<S104>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd189'
 * '<S105>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd190'
 * '<S106>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd191'
 * '<S107>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd192'
 * '<S108>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd193'
 * '<S109>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd194'
 * '<S110>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd2'
 * '<S111>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd21'
 * '<S112>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd210'
 * '<S113>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd211'
 * '<S114>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd22'
 * '<S115>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd232'
 * '<S116>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd26'
 * '<S117>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd265'
 * '<S118>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd27'
 * '<S119>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd277'
 * '<S120>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd278'
 * '<S121>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd282'
 * '<S122>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd283'
 * '<S123>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd284'
 * '<S124>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd285'
 * '<S125>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd286'
 * '<S126>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd287'
 * '<S127>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd288'
 * '<S128>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd290'
 * '<S129>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd3'
 * '<S130>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd4'
 * '<S131>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd66'
 * '<S132>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd67'
 * '<S133>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd68'
 * '<S134>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd69'
 * '<S135>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd7'
 * '<S136>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd70'
 * '<S137>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd72'
 * '<S138>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd73'
 * '<S139>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd74'
 * '<S140>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd8'
 * '<S141>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd1/override_signal'
 * '<S142>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd104/override_signal'
 * '<S143>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd105/override_signal'
 * '<S144>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd15/override_signal'
 * '<S145>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd157/override_signal'
 * '<S146>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd158/override_signal'
 * '<S147>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd16/override_signal'
 * '<S148>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd165/override_signal'
 * '<S149>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd166/override_signal'
 * '<S150>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd175/override_signal'
 * '<S151>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd176/override_signal'
 * '<S152>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd177/override_signal'
 * '<S153>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd178/override_signal'
 * '<S154>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd188/override_signal'
 * '<S155>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd189/override_signal'
 * '<S156>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd190/override_signal'
 * '<S157>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd191/override_signal'
 * '<S158>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd192/override_signal'
 * '<S159>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd193/override_signal'
 * '<S160>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd194/override_signal'
 * '<S161>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd2/override_signal'
 * '<S162>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd21/override_signal'
 * '<S163>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd210/override_signal'
 * '<S164>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd211/override_signal'
 * '<S165>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd22/override_signal'
 * '<S166>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd232/override_signal'
 * '<S167>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd26/override_signal'
 * '<S168>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd265/override_signal'
 * '<S169>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd27/override_signal'
 * '<S170>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd277/override_signal'
 * '<S171>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd278/override_signal'
 * '<S172>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd282/override_signal'
 * '<S173>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd283/override_signal'
 * '<S174>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd284/override_signal'
 * '<S175>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd285/override_signal'
 * '<S176>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd286/override_signal'
 * '<S177>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd287/override_signal'
 * '<S178>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd288/override_signal'
 * '<S179>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd290/override_signal'
 * '<S180>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd3/override_signal'
 * '<S181>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd4/override_signal'
 * '<S182>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd66/override_signal'
 * '<S183>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd67/override_signal'
 * '<S184>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd68/override_signal'
 * '<S185>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd69/override_signal'
 * '<S186>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd7/override_signal'
 * '<S187>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd70/override_signal'
 * '<S188>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd72/override_signal'
 * '<S189>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd73/override_signal'
 * '<S190>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd74/override_signal'
 * '<S191>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/ErrorCodePreCondition/DFC_Ovrd8/override_signal'
 * '<S192>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Error_Code/HazardLmpOn/SR_latch'
 * '<S193>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/HEV_range/1st Order Filter2'
 * '<S194>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Mileage_Backup/Compare To Constant23'
 * '<S195>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Mileage_Backup/Compare To Constant60'
 * '<S196>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Mileage_Backup/odometerbackup'
 * '<S197>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Mileage_Backup/turnON_delay'
 * '<S198>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/Mileage_Backup/turnON_delay/timed_delay'
 * '<S199>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Compare To Constant1'
 * '<S200>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Compare To Constant3'
 * '<S201>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Compare To Constant4'
 * '<S202>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Compare To Constant5'
 * '<S203>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Detect Decrease'
 * '<S204>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Detect Decrease1'
 * '<S205>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Detect Increase'
 * '<S206>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Enabled Subsystem'
 * '<S207>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Enabled Subsystem1'
 * '<S208>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Enabled Subsystem2'
 * '<S209>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Interval Test'
 * '<S210>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Interval Test1'
 * '<S211>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/OdometerAdd'
 * '<S212>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/OdometerBackup1'
 * '<S213>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/Subsystem1'
 * '<S214>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/turnON_delay1'
 * '<S215>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/turnON_delay2'
 * '<S216>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/turnON_delay1/timed_delay'
 * '<S217>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/TotalOdometerCal/turnON_delay2/timed_delay'
 * '<S218>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/average_fuel_consumption/fuel_consumption_converter'
 * '<S219>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/average_fuel_consumption/fuel_consumption_converter/1st Order Filter1'
 * '<S220>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_lamps/enum_const'
 * '<S221>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_lamps/icu_active_mode_lamps'
 * '<S222>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_lamps/icu_button_state_lamps'
 * '<S223>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_lamps/icu_drive_mode_lamps'
 * '<S224>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_lamps/icu_driver_req_lamps'
 * '<S225>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_lamps/icu_drive_mode_lamps/Compare To Constant'
 * '<S226>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_lamps/icu_driver_req_lamps/Enumerated Constant'
 * '<S227>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/Compare To Constant1'
 * '<S228>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/Enumerated Constant'
 * '<S229>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/HDT_DriveMode'
 * '<S230>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/LDT_DriveMode'
 * '<S231>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/HDT_DriveMode/Enumerated Constant1'
 * '<S232>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/HDT_DriveMode/Enumerated Constant11'
 * '<S233>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/HDT_DriveMode/Enumerated Constant13'
 * '<S234>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/HDT_DriveMode/Enumerated Constant16'
 * '<S235>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/HDT_DriveMode/Enumerated Constant2'
 * '<S236>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/HDT_DriveMode/Enumerated Constant5'
 * '<S237>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_drivemode/HDT_DriveMode/Enumerated Constant9'
 * '<S238>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/Enumerated Constant16'
 * '<S239>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/Enumerated Constant2'
 * '<S240>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/Enumerated Constant8'
 * '<S241>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/TqW_2_P'
 * '<S242>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_ev_mode'
 * '<S243>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_gen_mode'
 * '<S244>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_parked_mode'
 * '<S245>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/ead_offset_tol'
 * '<S246>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_generation_mode'
 * '<S247>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_powerflow_off'
 * '<S248>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/msg_offset_to_tol'
 * '<S249>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_ev_mode/Enumerated Constant10'
 * '<S250>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_ev_mode/Enumerated Constant9'
 * '<S251>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_ev_mode/within_tol3'
 * '<S252>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_gen_mode/Enumerated Constant17'
 * '<S253>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_gen_mode/Enumerated Constant18'
 * '<S254>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_gen_mode/within_tol6'
 * '<S255>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_parked_mode/Enumerated Constant1'
 * '<S256>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_parked_mode/Enumerated Constant15'
 * '<S257>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_parked_mode/Enumerated Constant2'
 * '<S258>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/classify_parked_mode/within_tol5'
 * '<S259>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/ead_offset_tol/above_tol'
 * '<S260>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/ead_offset_tol/below_tol'
 * '<S261>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/ead_offset_tol/within_tol'
 * '<S262>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_generation_mode/Enumerated Constant16'
 * '<S263>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_generation_mode/within_tol7'
 * '<S264>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_powerflow_off/Enumerated Constant'
 * '<S265>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_powerflow_off/Enumerated Constant3'
 * '<S266>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_powerflow_off/Enumerated Constant7'
 * '<S267>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_powerflow_off/within_tol1'
 * '<S268>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/is_powerflow_off/within_tol2'
 * '<S269>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/msg_offset_to_tol/above_tol'
 * '<S270>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/msg_offset_to_tol/below_tol'
 * '<S271>' : 'swc_HMIF/HMIF_Human_Machine_Interface/DSP_Display/icu_select_powerflow/msg_offset_to_tol/within_tol'
 */
#endif                                 /* RTW_HEADER_swc_HMIF_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
