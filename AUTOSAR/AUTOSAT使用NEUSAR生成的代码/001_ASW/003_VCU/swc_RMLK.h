/*
 * File: swc_RMLK.h
 *
 * Code generated for Simulink model 'swc_RMLK'.
 *
 * Model version                  : 1.63
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Apr 14 10:15:08 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_RMLK_h_
#define RTW_HEADER_swc_RMLK_h_
#ifndef swc_RMLK_COMMON_INCLUDES_
#define swc_RMLK_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_RMLK.h"
#endif                                 /* swc_RMLK_COMMON_INCLUDES_ */

#include "Rte_Type.h"

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
} vcib_VCIP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_RMLK_
#define DEFINED_TYPEDEF_FOR_vcsb_RMLK_

typedef struct {
  /* Remote Lock Limit Speed */
  float32 rlcd_v_rmtCtrlFctSpdLim_kph;

  /* &#x9501;&#x8F66;&#x70B9;&#x4E4C;&#x9F9F;&#x7B49;&#x6807;&#x5FD7;&#x4F4D; */
  boolean rlcd_b_rmtCtrlTurtleLampOn;

  /* &#x9501;&#x8F66;&#x9650;&#x5236;&#x626D;&#x77E9;&#x6807;&#x5FD7;&#x4F4D; */
  boolean rlcd_b_rmtCtrlTqOff;

  /* &#x9501;&#x8F66;&#x6FC0;&#x6D3B;&#x9650;&#x5236;&#x6CB9;&#x95E8;&#x6807;&#x5FD7;&#x4F4D; */
  boolean rlcd_b_rmtCtrlAccPedlOff;

  /* &#x9501;&#x8F66;&#x529F;&#x80FD;&#x6FC0;&#x6D3B; */
  uint8 rlcd_num_FunLockVehActive;

  /* &#x9632;&#x76D7;&#x9501;&#x8F66;&#x529F;&#x80FD;&#x6FC0;&#x6D3B; */
  uint8 rlcd_num_FunAnti_DismantleActive;

  /* &#x9501;&#x8F66;&#x9650;&#x901F;&#x7ED3;&#x679C; */
  uint8 rlcd_num_LockLimResult;

  /* &#x9501;&#x8F66;&#x7C7B;&#x578B; */
  uint8 rlcd_num_LockVehType;

  /* &#x9501;&#x8F66;&#x6267;&#x884C;&#x72B6;&#x6001; */
  boolean rlcd_b_LockVehSts;

  /* PMS&#x53CD;&#x9988;&#x9501;&#x8F66;&#x6267;&#x884C;&#x7ED3;&#x679C; */
  uint8 rlcd_st_LockVehExecutedSts;
} vcsb_RMLK;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_aKCXq7Ne1WydWlExrA6wHH_
#define DEFINED_TYPEDEF_FOR_struct_aKCXq7Ne1WydWlExrA6wHH_

typedef struct {
  boolean WirteNvmFlg;
  uint8 FunLockVehActiveResultCur;
  uint8 FunAntiDismtActiveResultCur;
  uint8 LockLimSetBswCur;
  uint8 VCU_NormLockSaveResultCur;
  uint8 rlcd_num_ChgLockReq;
  uint8 vsld_num_ChgLockExcReq;
  uint8 rlcd_num_AntiLockReq;
  boolean rlcd_b_igOnDwn;
  uint8 rlcd_num_ExeStsUpdate;
  uint8 rlcd_num_ExeStsUpdate1;
} struct_aKCXq7Ne1WydWlExrA6wHH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DlgnvLd5bPtX6Wu8CK8pYG_
#define DEFINED_TYPEDEF_FOR_struct_DlgnvLd5bPtX6Wu8CK8pYG_

typedef struct {
  uint8 rlcd_v_remoteEskBsw[16];
  uint8 rlcd_num_VCU_LockLimSetSaveResult;
  uint8 rlcd_num_VCU_FunLockVehActiveResult;
  uint8 rlcd_num_VCU_FunAnti_DismantleActiveResult;
  uint8 rlcd_num_VCU_NormLockSaveResult;
  uint8 rlcd_num_VCU_ChgLockSaveResult;
  uint8 rlcd_num_VCU_ChgLockExcSaveResult;
  uint8 rlcd_num_VCU_AntiLockSaveResult;
  uint8 rlcd_num_ExeStsUpdateSaveResult;
  uint8 rlcd_num_ExeStsUpdate1SaveResult;
} struct_DlgnvLd5bPtX6Wu8CK8pYG;

#endif

/* PublicStructure Variables for Internal Data, for system '<S9>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S109>/Unit Delay' */
} ARID_DEF_SR_latch_swc_RMLK_T;

/* PublicStructure Variables for Internal Data, for system '<S9>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S110>/Unit Delay' */
} ARID_DEF_SR_latch1_swc_RMLK_T;

/* PublicStructure Variables for Internal Data, for system '<S9>/SR_latch2' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S111>/Unit Delay' */
} ARID_DEF_SR_latch2_swc_RMLK_T;

/* PublicStructure Variables for Internal Data, for system '<S4>/Falling_Edge1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S16>/Unit Delay' */
} ARID_DEF_Falling_Edge1_swc_RM_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_SR_latch1_swc_RMLK_T ARID_DEF_SR_latch1;/* '<S26>/SR_latch1' */
  ARID_DEF_Falling_Edge1_swc_RM_T ARID_DEF_Falling_Edge1;/* '<S239>/Falling_Edge1' */
  ARID_DEF_Falling_Edge1_swc_RM_T ARID_DEF_Falling_Edge;/* '<S239>/Falling_Edge' */
  ARID_DEF_Falling_Edge1_swc_RM_T ARID_DEF_Falling_Edge1_m;/* '<S227>/Falling_Edge1' */
  ARID_DEF_Falling_Edge1_swc_RM_T ARID_DEF_Falling_Edge_c;/* '<S227>/Falling_Edge' */
  ARID_DEF_Falling_Edge1_swc_RM_T ARID_DEF_Falling_Edge_k;/* '<S17>/Falling_Edge' */
  ARID_DEF_Falling_Edge1_swc_RM_T ARID_DEF_Falling_Edge1_c;/* '<S4>/Falling_Edge1' */
  ARID_DEF_SR_latch_swc_RMLK_T ARID_DEF_SR_latch;/* '<S10>/SR_latch' */
  ARID_DEF_SR_latch1_swc_RMLK_T ARID_DEF_SR_latch5;/* '<S9>/SR_latch5' */
  ARID_DEF_SR_latch2_swc_RMLK_T ARID_DEF_SR_latch4;/* '<S9>/SR_latch4' */
  ARID_DEF_SR_latch2_swc_RMLK_T ARID_DEF_SR_latch2;/* '<S9>/SR_latch2' */
  ARID_DEF_SR_latch1_swc_RMLK_T ARID_DEF_SR_latch1_b;/* '<S9>/SR_latch1' */
  ARID_DEF_SR_latch_swc_RMLK_T ARID_DEF_SR_latch_p;/* '<S9>/SR_latch' */
  float32 OutportBufferForrlcd_v_rmtCtrlF;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  float32 UnitDelay1_DSTATE;           /* '<S20>/Unit Delay1' */
  float32 t_wait;                      /* '<S27>/timed_delay' */
  float32 timer;                       /* '<S184>/ExeSts' */
  float32 timer_f;                     /* '<S180>/fuelUpMode' */
  float32 t_wait_a;                    /* '<S150>/timed_delay' */
  float32 t_wait_n;                    /* '<S149>/timed_delay' */
  float32 timer_d;                     /* '<S10>/AuthState' */
  float32 timer_b;                     /* '<S9>/KeyOnAntiStateReq' */
  float32 timer_fy;                    /* '<S9>/ChgAntiStateReq' */
  uint32 state_i[2];                   /* '<S146>/MATLAB Function' */
  uint32 state_b[625];                 /* '<S146>/MATLAB Function' */
  uint32 UnitDelay1_DSTATE_o;          /* '<S163>/Unit Delay1' */
  uint32 UnitDelay3_DSTATE;            /* '<S163>/Unit Delay3' */
  uint32 UnitDelay2_DSTATE;            /* '<S163>/Unit Delay2' */
  uint32 UnitDelay_DSTATE;             /* '<S17>/Unit Delay' */
  uint32 method;                       /* '<S146>/MATLAB Function' */
  uint32 state;                        /* '<S146>/MATLAB Function' */
  uint16 Saturation;                   /* '<S146>/Saturation' */
  uint16 Cnt;                          /* '<S146>/AES_Cal' */
  uint16 UnitDelay3_DSTATE_b;          /* '<S10>/Unit Delay3' */
  uint8 out_o[7];                      /* '<S146>/MATLAB Function' */
  uint8 s_out[16];                     /* '<S146>/AES_Cal' */
  uint8 expKey[176];                   /* '<S146>/AES_Cal' */
  uint8 OutportBufferForrlcd_num_FunAnt;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  uint8 OutportBufferForrlcd_num_FunLoc;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  uint8 OutportBufferForrlcd_num_LockLi;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  uint8 OutportBufferForrlcd_num_LockVe;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  uint8 OutportBufferForrlcd_st_LockVeh;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  uint8 out;                           /* '<S180>/fuelUpMode' */
  uint8 AntiReq;                       /* '<S9>/KeyOnAntiStateReq' */
  uint8 AntiReq_b;                     /* '<S9>/ChgAntiStateReq' */
  uint8 UnitDelay_DSTATE_g;            /* '<S7>/Unit Delay' */
  uint8 UnitDelay_DSTATE_h;            /* '<S18>/Unit Delay' */
  uint8 UnitDelay4_DSTATE;             /* '<S10>/Unit Delay4' */
  uint8 UnitDelay1_DSTATE_l;           /* '<S10>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_k;           /* '<S22>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_p;           /* '<S26>/Unit Delay2' */
  uint8 UnitDelay4_DSTATE_l;           /* '<S26>/Unit Delay4' */
  uint8 UnitDelay2_DSTATE_e;           /* '<S23>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_l;           /* '<S10>/Unit Delay2' */
  uint8 UnitDelay9_DSTATE;             /* '<S10>/Unit Delay9' */
  uint8 UnitDelay3_DSTATE_a;           /* '<S8>/Unit Delay3' */
  uint8 UnitDelay1_DSTATE_n;           /* '<S8>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_ev;          /* '<S8>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_i;           /* '<S25>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_im;          /* '<S24>/Unit Delay2' */
  uint8 UnitDelay4_DSTATE_k;           /* '<S49>/Unit Delay4' */
  uint8 UnitDelay8_DSTATE;             /* '<S9>/Unit Delay8' */
  uint8 UnitDelay9_DSTATE_i;           /* '<S9>/Unit Delay9' */
  uint8 UnitDelay2_DSTATE_f;           /* '<S11>/Unit Delay2' */
  uint8 UnitDelay3_DSTATE_d;           /* '<S9>/Unit Delay3' */
  uint8 UnitDelay1_DSTATE_d;           /* '<S9>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE_ko;          /* '<S9>/Unit Delay2' */
  uint8 UnitDelay3_DSTATE_l;           /* '<S11>/Unit Delay3' */
  uint8 UnitDelay1_DSTATE_j;           /* '<S225>/Unit Delay1' */
  uint8 UnitDelay3_DSTATE_h;           /* '<S225>/Unit Delay3' */
  uint8 UnitDelay4_DSTATE_c;           /* '<S227>/Unit Delay4' */
  uint8 UnitDelay2_DSTATE_ij;          /* '<S225>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_k;           /* '<S226>/Unit Delay1' */
  uint8 UnitDelay3_DSTATE_ay;          /* '<S226>/Unit Delay3' */
  uint8 UnitDelay4_DSTATE_j;           /* '<S239>/Unit Delay4' */
  uint8 UnitDelay2_DSTATE_g;           /* '<S226>/Unit Delay2' */
  uint8 UnitDelay2_DSTATE_l4;          /* '<S18>/Unit Delay2' */
  uint8 UnitDelay1_DSTATE_c;           /* '<S19>/Unit Delay1' */
  uint8 UnitDelay1_DSTATE_n2;          /* '<S181>/Unit Delay1' */
  uint8 UnitDelay_DSTATE_f;            /* '<S182>/Unit Delay' */
  uint8 UnitDelay_DSTATE_m;            /* '<S180>/Unit Delay' */
  uint8 UnitDelay3_DSTATE_h0;          /* '<S22>/Unit Delay3' */
  uint8 UnitDelay3_DSTATE_ly;          /* '<S23>/Unit Delay3' */
  uint8 UnitDelay3_DSTATE_k;           /* '<S24>/Unit Delay3' */
  uint8 UnitDelay3_DSTATE_a4;          /* '<S25>/Unit Delay3' */
  uint8 UnitDelay3_DSTATE_br;          /* '<S26>/Unit Delay3' */
  uint8 is_c14_mylib2017a;             /* '<S27>/timed_delay' */
  uint8 is_active_c14_mylib2017a;      /* '<S27>/timed_delay' */
  uint8 is_c17_swc_RMLK;               /* '<S186>/Chart' */
  uint8 is_active_c17_swc_RMLK;        /* '<S186>/Chart' */
  uint8 is_c16_swc_RMLK;               /* '<S184>/ExeSts' */
  uint8 BuffSts;                       /* '<S184>/ExeSts' */
  uint8 LockCmd;                       /* '<S184>/ExeSts' */
  uint8 UnlockCmd;                     /* '<S184>/ExeSts' */
  uint8 is_active_c16_swc_RMLK;        /* '<S184>/ExeSts' */
  uint8 is_c2_swc_RMLK;                /* '<S180>/fuelUpMode' */
  uint8 is_FuelUpMet;                  /* '<S180>/fuelUpMode' */
  uint8 is_FuelUpMetB;                 /* '<S180>/fuelUpMode' */
  uint8 is_active_c2_swc_RMLK;         /* '<S180>/fuelUpMode' */
  uint8 is_c15_swc_RMLK;               /* '<S150>/timed_delay' */
  uint8 is_active_c15_swc_RMLK;        /* '<S150>/timed_delay' */
  uint8 is_c12_swc_RMLK;               /* '<S149>/timed_delay' */
  uint8 is_active_c12_swc_RMLK;        /* '<S149>/timed_delay' */
  uint8 is_active_c10_swc_RMLK;        /* '<S146>/AES_Cal' */
  uint8 is_c8_swc_RMLK;                /* '<S10>/AuthState' */
  uint8 ReqCnt;                        /* '<S10>/AuthState' */
  uint8 AuthType;                      /* '<S10>/AuthState' */
  uint8 is_active_c8_swc_RMLK;         /* '<S10>/AuthState' */
  uint8 is_c9_swc_RMLK;                /* '<S9>/KeyOnAntiStateReq' */
  uint8 is_AntiReqVerify;              /* '<S9>/KeyOnAntiStateReq' */
  uint8 AntiReqBuff;                   /* '<S9>/KeyOnAntiStateReq' */
  uint8 is_active_c9_swc_RMLK;         /* '<S9>/KeyOnAntiStateReq' */
  uint8 is_c1_swc_RMLK;                /* '<S9>/ChgAntiStateReq' */
  uint8 is_FuelUpVerify;               /* '<S9>/ChgAntiStateReq' */
  uint8 is_ChgAntiVerify;              /* '<S9>/ChgAntiStateReq' */
  uint8 is_active_c1_swc_RMLK;         /* '<S9>/ChgAntiStateReq' */
  boolean VariableIntegerDelay_DSTATE[100];/* '<S26>/Variable Integer Delay' */
  boolean OutportBufferForrlcd_b_LockVehS;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  boolean OutportBufferForrlcd_b_rmtCtrlA;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  boolean OutportBufferForrlcd_b_rmtCtrlT;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  boolean OutportBufferForrlcd_b_rmtCtr_d;/* '<S3>/RmtLckCtrl_OutputLayer_N72' */
  boolean UnitDelay_DSTATE_hv;         /* '<S171>/Unit Delay' */
  boolean UnitDelay_DSTATE_hp;         /* '<S166>/Unit Delay' */
  boolean UnitDelay_DSTATE_j;          /* '<S164>/Unit Delay' */
  boolean UnitDelay_DSTATE_k;          /* '<S165>/Unit Delay' */
  boolean DelayInput1_DSTATE;          /* '<S32>/Delay Input1' */
  boolean DelayInput1_DSTATE_h;        /* '<S33>/Delay Input1' */
  boolean UnitDelay1_DSTATE_cd;        /* '<S7>/Unit Delay1' */
  boolean UnitDelay_DSTATE_n;          /* '<S172>/Unit Delay' */
  boolean UnitDelay_DSTATE_o;          /* '<S173>/Unit Delay' */
  boolean UnitDelay1_DSTATE_d4;        /* '<S18>/Unit Delay1' */
  boolean UnitDelay_DSTATE_e;          /* '<S147>/Unit Delay' */
  boolean UnitDelay_DSTATE_hn;         /* '<S258>/Unit Delay' */
  boolean UnitDelay_DSTATE_b;          /* '<S259>/Unit Delay' */
  boolean UnitDelay_DSTATE_d;          /* '<S22>/Unit Delay' */
  boolean UnitDelay5_DSTATE;           /* '<S10>/Unit Delay5' */
  boolean UnitDelay_DSTATE_on;         /* '<S10>/Unit Delay' */
  boolean UnitDelay_DSTATE_nk;         /* '<S269>/Unit Delay' */
  boolean UnitDelay_DSTATE_dh;         /* '<S270>/Unit Delay' */
  boolean UnitDelay_DSTATE_bo;         /* '<S26>/Unit Delay' */
  boolean DelayInput1_DSTATE_e;        /* '<S268>/Delay Input1' */
  boolean UnitDelay_DSTATE_l;          /* '<S260>/Unit Delay' */
  boolean UnitDelay_DSTATE_i;          /* '<S261>/Unit Delay' */
  boolean UnitDelay_DSTATE_nk2;        /* '<S23>/Unit Delay' */
  boolean UnitDelay8_DSTATE_p;         /* '<S10>/Unit Delay8' */
  boolean UnitDelay5_DSTATE_e;         /* '<S8>/Unit Delay5' */
  boolean UnitDelay8_DSTATE_a;         /* '<S8>/Unit Delay8' */
  boolean UnitDelay_DSTATE_gw;         /* '<S264>/Unit Delay' */
  boolean UnitDelay_DSTATE_a;          /* '<S265>/Unit Delay' */
  boolean UnitDelay_DSTATE_ok;         /* '<S25>/Unit Delay' */
  boolean UnitDelay_DSTATE_mq;         /* '<S262>/Unit Delay' */
  boolean UnitDelay_DSTATE_da;         /* '<S263>/Unit Delay' */
  boolean UnitDelay_DSTATE_c;          /* '<S24>/Unit Delay' */
  boolean UnitDelay_DSTATE_am;         /* '<S106>/Unit Delay' */
  boolean UnitDelay_DSTATE_hx;         /* '<S107>/Unit Delay' */
  boolean UnitDelay10_DSTATE;          /* '<S9>/Unit Delay10' */
  boolean UnitDelay_DSTATE_br;         /* '<S108>/Unit Delay' */
  boolean UnitDelay_DSTATE_ni;         /* '<S155>/Unit Delay' */
  boolean UnitDelay_DSTATE_fw;         /* '<S156>/Unit Delay' */
  boolean UnitDelay_DSTATE_i1;         /* '<S11>/Unit Delay' */
  boolean UnitDelay4_DSTATE_a;         /* '<S9>/Unit Delay4' */
  boolean UnitDelay5_DSTATE_a;         /* '<S9>/Unit Delay5' */
  boolean UnitDelay_DSTATE_fh;         /* '<S9>/Unit Delay' */
  boolean UnitDelay6_DSTATE;           /* '<S9>/Unit Delay6' */
  boolean DelayInput1_DSTATE_hw;       /* '<S102>/Delay Input1' */
  boolean DelayInput1_DSTATE_b;        /* '<S103>/Delay Input1' */
  boolean UnitDelay7_DSTATE;           /* '<S9>/Unit Delay7' */
  boolean UnitDelay2_DSTATE_o;         /* '<S184>/Unit Delay2' */
  boolean UnitDelay1_DSTATE_b;         /* '<S184>/Unit Delay1' */
  boolean UnitDelay_DSTATE_o5;         /* '<S184>/Unit Delay' */
  boolean DelayInput1_DSTATE_k;        /* '<S218>/Delay Input1' */
  boolean DelayInput1_DSTATE_a;        /* '<S219>/Delay Input1' */
  boolean DelayInput1_DSTATE_m;        /* '<S220>/Delay Input1' */
  boolean DelayInput1_DSTATE_n;        /* '<S221>/Delay Input1' */
  boolean DelayInput1_DSTATE_p;        /* '<S222>/Delay Input1' */
  boolean DelayInput1_DSTATE_o;        /* '<S223>/Delay Input1' */
  boolean DelayInput1_DSTATE_bz;       /* '<S229>/Delay Input1' */
  boolean DelayInput1_DSTATE_i;        /* '<S230>/Delay Input1' */
  boolean DelayInput1_DSTATE_hu;       /* '<S241>/Delay Input1' */
  boolean DelayInput1_DSTATE_b1;       /* '<S242>/Delay Input1' */
  boolean DelayInput1_DSTATE_j;        /* '<S177>/Delay Input1' */
  boolean DelayInput1_DSTATE_g;        /* '<S178>/Delay Input1' */
  boolean DelayInput1_DSTATE_o2;       /* '<S198>/Delay Input1' */
  boolean DelayInput1_DSTATE_n5;       /* '<S199>/Delay Input1' */
  boolean DelayInput1_DSTATE_bx;       /* '<S203>/Delay Input1' */
  boolean DelayInput1_DSTATE_eb;       /* '<S204>/Delay Input1' */
  boolean UpdtBuff;                    /* '<S184>/ExeSts' */
  boolean ExcuteUnlockCmd;             /* '<S184>/ExeSts' */
  boolean ExcuteLockCmd;               /* '<S184>/ExeSts' */
  boolean TboxReq;                     /* '<S9>/KeyOnAntiStateReq' */
  boolean TboxReq_g;                   /* '<S9>/ChgAntiStateReq' */
  boolean RMLK_Enable_MODE;            /* '<S1>/RMLK_Enable' */
} ARID_DEF_swc_RMLK_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float32 t_delay_on;            /* '<S27>/Saturation' */
  const float32 t_delay_off;           /* '<S149>/Saturation1' */
} ConstB_swc_RMLK_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: Constant1_Value
   * Referenced by: '<S146>/Constant1'
   */
  uint8 Constant1_Value[9];

  /* Pooled Parameter (Expression: [170 170 170 170 170 170 170])
   * Referenced by:
   *   '<S10>/Constant2'
   *   '<S10>/Constant4'
   */
  uint8 pooled16[7];

  /* Pooled Parameter (Expression: [0 0 0 0 0 0 0])
   * Referenced by:
   *   '<S10>/Constant3'
   *   '<S10>/Constant5'
   */
  uint8 pooled18[7];
} ConstP_swc_RMLK_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_RMLK_T swc_RMLK_ARID_DEF;
extern const ConstB_swc_RMLK_T swc_RMLK_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_swc_RMLK_T swc_RMLK_ConstP;

/* Exported data declaration */
#define swc_RMLK_START_SEC_CONST_VOLATILE
#include "swc_RMLK_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile boolean rlcc_b_VSLTEST1_sw;/* Referenced by: '<S9>/Constant3' */
extern const volatile boolean rlcc_b_VSLTEST2_sw;/* Referenced by: '<S9>/Constant11' */
extern const volatile boolean rlcc_b_VSLTEST3_sw;/* Referenced by: '<S9>/Constant13' */
extern const volatile boolean rlcc_b_VSLTEST5_sw;/* Referenced by: '<S7>/Constant14' */
extern const volatile boolean rlcc_b_useEskNvmDataEna;/* Referenced by: '<S145>/Constant9' */
extern const volatile float32 rlcc_n_igOnDelayCnt;/* Referenced by: '<S26>/Constant1' */
extern const volatile uint32 rlcc_n_pwrCntAntiLock;/* Referenced by: '<S17>/Constant' */
extern const volatile uint8 rlcc_n_useEskNvmDataDefualt[16];/* Referenced by: '<S145>/Constant4' */
extern const volatile float32 rlcc_tm_antiChgTm_s;/* Referenced by: '<S9>/Constant17' */
extern const volatile float32 rlcc_tm_antiKL15Tm_s;/* Referenced by:
                                                    * '<S9>/Constant16'
                                                    * '<S9>/Constant5'
                                                    */
extern const volatile float32 rlcc_tm_fuleUpA1Dly_s;/* Referenced by: '<S180>/Constant2' */
extern const volatile float32 rlcc_tm_fuleUpA2Dly_s;/* Referenced by: '<S180>/Constant3' */
extern const volatile float32 rlcc_tm_fuleUpB1Dly_s;/* Referenced by: '<S180>/Constant4' */
extern const volatile float32 rlcc_tm_fuleUpB2Dly_s;/* Referenced by: '<S180>/Constant5' */
extern const volatile float32 rlcc_tm_fuleUpB3Dly_s;/* Referenced by: '<S180>/Constant6' */
extern const volatile float32 rlcc_v_VehSpdMax_kph;/* Referenced by:
                                                    * '<S20>/Constant4'
                                                    * '<S20>/Constant5'
                                                    */
extern const volatile float32 rlcc_v_antiDismantleSpdLim_kph;/* Referenced by: '<S20>/Constant6' */
extern const volatile float32 rlcc_v_fuleLv1;/* Referenced by: '<S180>/Constant' */
extern const volatile float32 rlcc_v_fuleLv2;/* Referenced by: '<S180>/Constant1' */
extern const volatile float32 rlcc_v_normLockSpdLimDft_kph;/* Referenced by: '<S20>/Unit Delay1' */
extern const volatile float32 rlcc_v_normlLckSpd_kph;/* Referenced by: '<S26>/Constant3' */
extern const volatile float32 rlcc_v_rmtCtrlPedlOff_kph;/* Referenced by: '<S20>/Constant1' */
extern const volatile float32 rlcc_v_rmtCtrlTqOff_kph;/* Referenced by: '<S20>/Constant7' */
extern const volatile float32 rlcc_v_vehSpdUpdLimCfg_kph;/* Referenced by: '<S20>/Constant2' */
extern const volatile float32 rlcv_v_vehSpdLimCfg_kph[4];
                                      /* Referenced by: '<S19>/TV4V2_Status5' */

#define swc_RMLK_STOP_SEC_CONST_VOLATILE
#include "swc_RMLK_MemMap.h"
#define swc_RMLK_START_SEC_VAR
#include "swc_RMLK_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern uint8 rlcd_TBOXFunAntiDismantleActive;/* '<S5>/Data Type Conversion8' */
extern uint8 rlcd_TBOX_FunLockVehActive;/* '<S5>/Data Type Conversion9' */
extern uint8 rlcd_TBOX_Key[7];         /* '<S5>/Data Type Conversion24' */
extern uint8 rlcd_TBOX_LockLimSet;     /* '<S5>/Data Type Conversion10' */
extern uint8 rlcd_TBOX_LockVehCtrl;    /* '<S5>/Data Type Conversion11' */
extern uint8 rlcd_TBOX_LockVehType;    /* '<S5>/Data Type Conversion12' */
extern uint8 rlcd_TBOX_Update;         /* '<S5>/Data Type Conversion23' */
extern boolean rlcd_b_ChgAntiLockReq;  /* '<S9>/SR_latch2' */
extern boolean rlcd_b_ChgLockExcReqCur;/* '<S9>/Logical Operator' */
extern boolean rlcd_b_LockVehResults;  /* '<S185>/Logical Operator5' */
extern boolean rlcd_b_NormLockActv;    /* '<S26>/Logical Operator2' */
extern boolean rlcd_b_NormLockActvRaw; /* '<S26>/SR_latch1' */
extern boolean rlcd_b_NormLockNotActv; /* '<S26>/Logical Operator3' */
extern boolean rlcd_b_aswTboxUpdate;   /* '<S10>/Logical Operator11' */
extern boolean rlcd_b_chgAnti_flg;     /* '<S273>/Logical Operator' */
extern boolean rlcd_b_cmdFail_flg;     /* '<S10>/Logical Operator21' */
extern boolean rlcd_b_cmdLockAuth_flg; /* '<S10>/Logical Operator12' */
extern boolean rlcd_b_defualtAuth_flg; /* '<S10>/Logical Operator5' */
extern boolean rlcd_b_frameUpdateFlg;  /* '<S150>/timed_delay' */
extern boolean rlcd_b_fuelUpAntiLockReq;/* '<S180>/Logical Operator6' */
extern boolean rlcd_b_fuelUpCalEna;    /* '<S180>/Logical Operator1' */
extern boolean rlcd_b_fuelUpNormalLockReq;/* '<S180>/Logical Operator3' */
extern boolean rlcd_b_fuleUpAntiLockExcReq;/* '<S9>/SR_latch4' */
extern boolean rlcd_b_ignOn;           /* '<S5>/Data Type Conversion14' */
extern boolean rlcd_b_obcWakeUp;       /* '<S5>/Data Type Conversion15' */
extern boolean rlcd_b_rmtCtrlAntiDismtLock;/* '<S14>/Compare' */
extern boolean rlcd_b_rmtCtrlChrgLock; /* '<S13>/Compare' */
extern boolean rlcd_b_rmtCtrlNormLock; /* '<S12>/Compare' */
extern boolean rlcd_b_tboxCmd_flg;     /* '<S10>/Logical Operator10' */
extern boolean rlcd_b_tboxKey_flg;     /* '<S10>/Logical Operator9' */
extern uint32 rlcd_n_flashCnt;         /* '<S17>/Switch8' */
extern uint16 rlcd_n_gcvRlcVer;        /* '<S4>/Constant' */
extern uint32 rlcd_n_pwrCntDiff;       /* '<S17>/Add' */
extern uint32 rlcd_n_rmlkIgOnCnt;      /* '<S17>/Saturation' */
extern uint8 rlcd_num_AntiLockReq;     /* '<S9>/Switch15' */
extern uint8 rlcd_num_ChgLockExcReq;   /* '<S9>/Switch14' */
extern uint8 rlcd_num_ChgLockReq;      /* '<S9>/Switch13' */
extern uint8 rlcd_num_ExeStsUpdate;    /* '<S184>/ExeSts' */
extern uint8 rlcd_num_ExeStsUpdate1;   /* '<S184>/ExeSts' */
extern uint8 rlcd_num_ExeStsUpdate1SaveResult;/* '<S5>/Data Type Conversion25' */
extern uint8 rlcd_num_ExeStsUpdateSaveResult;/* '<S5>/Data Type Conversion16' */
extern uint8 rlcd_num_FunAnti_DismantleActiveReq;/* '<S8>/Switch6' */
extern uint8 rlcd_num_FunLockVehActiveReq;/* '<S8>/Switch1' */
extern uint8 rlcd_num_LockLimSetReq;   /* '<S7>/Switch11' */
extern uint8 rlcd_num_NormLockReq;     /* '<S9>/Switch12' */
extern uint8 rlcd_num_NormLockReqRaw;  /* '<S9>/Switch3' */
extern uint8 rlcd_num_NormLockSaveRltRaw;/* '<S26>/Switch8' */
extern uint8 rlcd_num_VCU_AntiLockSaveResult;/* '<S5>/Data Type Conversion6' */
extern uint8 rlcd_num_VCU_AuthResult;  /* '<S10>/AuthState' */
extern uint8 rlcd_num_VCU_ChgLockExcSaveResult;/* '<S5>/Data Type Conversion5' */
extern uint8 rlcd_num_VCU_ChgLockSaveResult;/* '<S5>/Data Type Conversion4' */
extern uint8 rlcd_num_VCU_FunAnti_DismantleActiveResult;/* '<S5>/Data Type Conversion2' */
extern uint8 rlcd_num_VCU_FunLockVehActiveResult;/* '<S5>/Data Type Conversion1' */
extern uint8 rlcd_num_VCU_LockLimSetSaveResult;/* '<S5>/Data Type Conversion' */
extern uint8 rlcd_num_VCU_NormLockSaveResult;/* '<S5>/Data Type Conversion3' */
extern uint8 rlcd_num_pmsRespResult;   /* '<S10>/AuthState' */
extern uint8 rlcd_num_rmtLkSpdLimCfg;  /* '<S19>/Switch17' */
extern uint8 rlcd_num_rmtLkSpdLimCfg3; /* '<S176>/Switch4' */
extern uint8 rlcd_num_rmtLkSpdLimCfgInit;/* '<S19>/Switch1' */
extern uint8 rlcd_st_FuelingStatus;    /* '<S180>/Unit Delay' */
extern uint8 rlcd_st_LockVehExecutedSts;/* '<S184>/ExeSts' */
extern uint8 rlcd_st_LockVehExecutedStsOut;/* '<S184>/ExeSts' */
extern uint8 rlcd_st_authState;        /* '<S10>/AuthState' */
extern float32 rlcd_v_fuelA1Pos;       /* '<S180>/fuelUpMode' */
extern float32 rlcd_v_fuelA2Pos;       /* '<S180>/fuelUpMode' */
extern float32 rlcd_v_fuelB1Pos;       /* '<S180>/fuelUpMode' */
extern uint8 rlcd_v_pmsReqSeed[7];     /* '<S10>/AuthState' */
extern uint8 rlcd_v_remoteEskBsw[16];  /* '<S5>/Data Type Conversion7' */
extern float32 rlcd_v_rmtCtrlFctSpdLimCfg_kph;/* '<S19>/Index Vector1' */
extern uint8 rlcd_v_tboxKeyVect[7];    /* '<S4>/Signal Conversion' */
extern float32 rlcd_v_vehSpd_kph;      /* '<S5>/Data Type Conversion13' */

#define swc_RMLK_STOP_SEC_VAR
#include "swc_RMLK_MemMap.h"

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
 * '<Root>' : 'swc_RMLK'
 * '<S1>'   : 'swc_RMLK/RMLK__remote_lock'
 * '<S2>'   : 'swc_RMLK/RMLK__remote_lock/Compare To Constant'
 * '<S3>'   : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable'
 * '<S4>'   : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC'
 * '<S5>'   : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RmtLckCtrl_InputLayer_N72'
 * '<S6>'   : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RmtLckCtrl_OutputLayer_N72'
 * '<S7>'   : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ASWLockLimSetReq'
 * '<S8>'   : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq'
 * '<S9>'   : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq'
 * '<S10>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess'
 * '<S11>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ChgLockSaveResult_Process'
 * '<S12>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/Compare To Constant2'
 * '<S13>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/Compare To Constant4'
 * '<S14>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/Compare To Constant5'
 * '<S15>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/DocBlock'
 * '<S16>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/Falling_Edge1'
 * '<S17>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify'
 * '<S18>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/LockLimSetBsw_Process'
 * '<S19>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtCtrlSpdLimCfg'
 * '<S20>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtSpdArbitrationInner'
 * '<S21>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter'
 * '<S22>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_AntiLockSaveResult_Process'
 * '<S23>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_ChgLockExcSaveResult_Process'
 * '<S24>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_FunAnti_DismantleActiveResult_Process'
 * '<S25>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_FunLockVehActiveResult_Process'
 * '<S26>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_NormLockSaveResult_Process'
 * '<S27>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/turnON_delay'
 * '<S28>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ASWLockLimSetReq/Compare To Constant1'
 * '<S29>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ASWLockLimSetReq/Compare To Constant10'
 * '<S30>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ASWLockLimSetReq/Compare To Constant2'
 * '<S31>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ASWLockLimSetReq/Compare To Constant9'
 * '<S32>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ASWLockLimSetReq/Detect Increase'
 * '<S33>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ASWLockLimSetReq/Detect Increase1'
 * '<S34>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant'
 * '<S35>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant1'
 * '<S36>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant17'
 * '<S37>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant18'
 * '<S38>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant2'
 * '<S39>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant20'
 * '<S40>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant21'
 * '<S41>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant22'
 * '<S42>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant3'
 * '<S43>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant4'
 * '<S44>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant5'
 * '<S45>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant6'
 * '<S46>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant7'
 * '<S47>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant8'
 * '<S48>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockActiveReq/Compare To Constant9'
 * '<S49>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/AuthMap'
 * '<S50>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/ChgAntiStateReq'
 * '<S51>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant1'
 * '<S52>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant10'
 * '<S53>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant11'
 * '<S54>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant12'
 * '<S55>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant13'
 * '<S56>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant14'
 * '<S57>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant15'
 * '<S58>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant16'
 * '<S59>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant17'
 * '<S60>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant18'
 * '<S61>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant19'
 * '<S62>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant2'
 * '<S63>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant20'
 * '<S64>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant21'
 * '<S65>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant22'
 * '<S66>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant23'
 * '<S67>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant24'
 * '<S68>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant25'
 * '<S69>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant26'
 * '<S70>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant27'
 * '<S71>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant28'
 * '<S72>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant29'
 * '<S73>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant3'
 * '<S74>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant30'
 * '<S75>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant31'
 * '<S76>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant32'
 * '<S77>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant33'
 * '<S78>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant34'
 * '<S79>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant35'
 * '<S80>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant36'
 * '<S81>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant37'
 * '<S82>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant38'
 * '<S83>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant39'
 * '<S84>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant4'
 * '<S85>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant40'
 * '<S86>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant41'
 * '<S87>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant42'
 * '<S88>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant43'
 * '<S89>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant44'
 * '<S90>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant45'
 * '<S91>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant46'
 * '<S92>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant47'
 * '<S93>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant49'
 * '<S94>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant5'
 * '<S95>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant50'
 * '<S96>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant51'
 * '<S97>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant52'
 * '<S98>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant6'
 * '<S99>'  : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant7'
 * '<S100>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant8'
 * '<S101>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Compare To Constant9'
 * '<S102>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Detect Increase'
 * '<S103>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Detect Increase1'
 * '<S104>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/DocBlock'
 * '<S105>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/KeyOnAntiStateReq'
 * '<S106>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Rising_Detect'
 * '<S107>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Rising_Detect1'
 * '<S108>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/Rising_Detect2'
 * '<S109>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/SR_latch'
 * '<S110>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/SR_latch1'
 * '<S111>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/SR_latch2'
 * '<S112>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/SR_latch4'
 * '<S113>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/SR_latch5'
 * '<S114>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/AuthMap/Compare To Constant1'
 * '<S115>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/AuthMap/Compare To Constant2'
 * '<S116>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/AuthMap/Compare To Constant3'
 * '<S117>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/AuthMap/Compare To Constant31'
 * '<S118>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/AuthMap/Compare To Constant32'
 * '<S119>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AswLockReq/AuthMap/Compare To Constant33'
 * '<S120>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/AuthState'
 * '<S121>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant1'
 * '<S122>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant10'
 * '<S123>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant11'
 * '<S124>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant12'
 * '<S125>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant13'
 * '<S126>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant14'
 * '<S127>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant15'
 * '<S128>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant16'
 * '<S129>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant17'
 * '<S130>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant18'
 * '<S131>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant19'
 * '<S132>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant2'
 * '<S133>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant20'
 * '<S134>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant21'
 * '<S135>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant22'
 * '<S136>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant23'
 * '<S137>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant25'
 * '<S138>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant3'
 * '<S139>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant4'
 * '<S140>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant5'
 * '<S141>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant6'
 * '<S142>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant7'
 * '<S143>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant8'
 * '<S144>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Compare To Constant9'
 * '<S145>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/EskNvm'
 * '<S146>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Rand_AES'
 * '<S147>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Rising_Detect1'
 * '<S148>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/SR_latch'
 * '<S149>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/turnOFF_delay'
 * '<S150>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/turnOFF_delay1'
 * '<S151>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Rand_AES/AES_Cal'
 * '<S152>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/Rand_AES/MATLAB Function'
 * '<S153>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/turnOFF_delay/timed_delay'
 * '<S154>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/AuthResultProcess/turnOFF_delay1/timed_delay'
 * '<S155>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ChgLockSaveResult_Process/Rising_Detect1'
 * '<S156>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/ChgLockSaveResult_Process/Rising_Detect2'
 * '<S157>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/Falling_Edge1/DocBlock'
 * '<S158>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/Falling_Edge1/DocBlockDescription'
 * '<S159>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/Falling_Edge1/model_info1'
 * '<S160>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Enabled Subsystem'
 * '<S161>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Enabled Subsystem1'
 * '<S162>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Falling_Edge'
 * '<S163>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Read_KeyOnCnt_NvMProcess'
 * '<S164>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Rising_Detect1'
 * '<S165>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Rising_Detect2'
 * '<S166>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Rising_Detect3'
 * '<S167>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Write_KeyOnCnt'
 * '<S168>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Falling_Edge/DocBlock'
 * '<S169>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Falling_Edge/DocBlockDescription'
 * '<S170>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Falling_Edge/model_info1'
 * '<S171>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/FlashPwrOnVerify/Read_KeyOnCnt_NvMProcess/Rising_Detect'
 * '<S172>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/LockLimSetBsw_Process/Rising_Detect1'
 * '<S173>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/LockLimSetBsw_Process/Rising_Detect2'
 * '<S174>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtCtrlSpdLimCfg/Compare To Constant1'
 * '<S175>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtCtrlSpdLimCfg/Compare To Constant15'
 * '<S176>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtCtrlSpdLimCfg/SpeedLimitLatch'
 * '<S177>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtCtrlSpdLimCfg/SpeedLimitLatch/Detect Increase'
 * '<S178>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtCtrlSpdLimCfg/SpeedLimitLatch/Detect Increase2'
 * '<S179>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/DocBlock'
 * '<S180>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus'
 * '<S181>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunAnti_DismantleActive_Mapping'
 * '<S182>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunLockVehActive_Mapping'
 * '<S183>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockLimResult_Mapping'
 * '<S184>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts'
 * '<S185>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehSts_Mapping'
 * '<S186>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehType_Mapping'
 * '<S187>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus/Compare To Constant1'
 * '<S188>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus/Compare To Constant14'
 * '<S189>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus/Compare To Constant2'
 * '<S190>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus/Compare To Constant3'
 * '<S191>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus/Compare To Constant4'
 * '<S192>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus/Compare To Constant5'
 * '<S193>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus/Compare To Constant6'
 * '<S194>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FuelingStatus/fuelUpMode'
 * '<S195>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunAnti_DismantleActive_Mapping/Compare To Constant4'
 * '<S196>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunAnti_DismantleActive_Mapping/Compare To Constant5'
 * '<S197>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunAnti_DismantleActive_Mapping/Compare To Constant8'
 * '<S198>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunAnti_DismantleActive_Mapping/Detect Increase1'
 * '<S199>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunAnti_DismantleActive_Mapping/Detect Increase2'
 * '<S200>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunLockVehActive_Mapping/Compare To Constant1'
 * '<S201>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunLockVehActive_Mapping/Compare To Constant2'
 * '<S202>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunLockVehActive_Mapping/Compare To Constant3'
 * '<S203>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunLockVehActive_Mapping/Detect Increase'
 * '<S204>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_FunLockVehActive_Mapping/Detect Increase1'
 * '<S205>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockLimResult_Mapping/Compare To Constant15'
 * '<S206>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant1'
 * '<S207>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant10'
 * '<S208>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant11'
 * '<S209>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant12'
 * '<S210>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant2'
 * '<S211>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant3'
 * '<S212>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant4'
 * '<S213>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant5'
 * '<S214>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant6'
 * '<S215>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant7'
 * '<S216>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant8'
 * '<S217>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Compare To Constant9'
 * '<S218>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Detect Increase'
 * '<S219>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Detect Increase1'
 * '<S220>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Detect Increase2'
 * '<S221>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Detect Increase3'
 * '<S222>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Detect Increase4'
 * '<S223>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/Detect Increase5'
 * '<S224>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeSts'
 * '<S225>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead'
 * '<S226>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1'
 * '<S227>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus'
 * '<S228>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Compare To Constant8'
 * '<S229>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Detect Increase'
 * '<S230>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Detect Increase1'
 * '<S231>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Falling_Edge'
 * '<S232>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Falling_Edge1'
 * '<S233>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Falling_Edge/DocBlock'
 * '<S234>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Falling_Edge/DocBlockDescription'
 * '<S235>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Falling_Edge/model_info1'
 * '<S236>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Falling_Edge1/DocBlock'
 * '<S237>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Falling_Edge1/DocBlockDescription'
 * '<S238>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead/QuickOnStatus/Falling_Edge1/model_info1'
 * '<S239>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus'
 * '<S240>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Compare To Constant8'
 * '<S241>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Detect Increase'
 * '<S242>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Detect Increase1'
 * '<S243>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Falling_Edge'
 * '<S244>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Falling_Edge1'
 * '<S245>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Falling_Edge/DocBlock'
 * '<S246>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Falling_Edge/DocBlockDescription'
 * '<S247>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Falling_Edge/model_info1'
 * '<S248>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Falling_Edge1/DocBlock'
 * '<S249>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Falling_Edge1/DocBlockDescription'
 * '<S250>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehExecutedSts/ExeStsNvmRead1/QuickOnStatus/Falling_Edge1/model_info1'
 * '<S251>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehSts_Mapping/Compare To Constant10'
 * '<S252>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehSts_Mapping/Compare To Constant11'
 * '<S253>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehSts_Mapping/Compare To Constant12'
 * '<S254>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehType_Mapping/Chart'
 * '<S255>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehType_Mapping/Compare To Constant6'
 * '<S256>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehType_Mapping/Compare To Constant7'
 * '<S257>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/RmtStsArbitrationOutter/PMS_LockVehType_Mapping/Compare To Constant9'
 * '<S258>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_AntiLockSaveResult_Process/Rising_Detect1'
 * '<S259>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_AntiLockSaveResult_Process/Rising_Detect2'
 * '<S260>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_ChgLockExcSaveResult_Process/Rising_Detect1'
 * '<S261>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_ChgLockExcSaveResult_Process/Rising_Detect2'
 * '<S262>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_FunAnti_DismantleActiveResult_Process/Rising_Detect1'
 * '<S263>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_FunAnti_DismantleActiveResult_Process/Rising_Detect2'
 * '<S264>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_FunLockVehActiveResult_Process/Rising_Detect1'
 * '<S265>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_FunLockVehActiveResult_Process/Rising_Detect2'
 * '<S266>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_NormLockSaveResult_Process/Compare To Constant1'
 * '<S267>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_NormLockSaveResult_Process/Compare To Constant10'
 * '<S268>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_NormLockSaveResult_Process/Detect Increase'
 * '<S269>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_NormLockSaveResult_Process/Rising_Detect1'
 * '<S270>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_NormLockSaveResult_Process/Rising_Detect2'
 * '<S271>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/VCU_NormLockSaveResult_Process/SR_latch1'
 * '<S272>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RLC/turnON_delay/timed_delay'
 * '<S273>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RmtLckCtrl_InputLayer_N72/Subsystem'
 * '<S274>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RmtLckCtrl_InputLayer_N72/Subsystem/Compare To Constant'
 * '<S275>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RmtLckCtrl_InputLayer_N72/Subsystem/Compare To Constant1'
 * '<S276>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RmtLckCtrl_InputLayer_N72/Subsystem/Compare To Constant2'
 * '<S277>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RmtLckCtrl_OutputLayer_N72/NvmUpdate'
 * '<S278>' : 'swc_RMLK/RMLK__remote_lock/RMLK_Enable/RmtLckCtrl_OutputLayer_N72/NvmUpdate1'
 */
#endif                                 /* RTW_HEADER_swc_RMLK_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
