/*
 * File: swc_OGVL.h
 *
 * Code generated for Simulink model 'swc_OGVL'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Aug 20 10:58:11 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_OGVL_h_
#define RTW_HEADER_swc_OGVL_h_
#ifndef swc_OGVL_COMMON_INCLUDES_
#define swc_OGVL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_OGVL.h"
#endif                                 /* swc_OGVL_COMMON_INCLUDES_ */

#include "Rte_Type.h"

/* Includes for objects with custom storage classes */
#include "const_ImportedDefine.h"

/* user code (top of header file) */
#include "Platform_Types.h"
#include "enum_Type.h"
#include "Rte_swc_rte_dem.h"
#include "Aes_Encypt.h"
#include "AES_Lib.h"
#include "mca.h"
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
  boolean vild_st_pepsRKECom;
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
} vcib_VCIP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_vcsb_OGVL_
#define DEFINED_TYPEDEF_FOR_vcsb_OGVL_

typedef struct {
  uint8 dtld_st_lockVehPer;
  uint8 dtld_st_versionConversion;
  uint8 dtld_st_spdLmtLevelReq;
  uint8 dtld_st_inventorySpdLmtReq;
  uint8 dtld_st_lifeCnt;
  float32 dtld_v_dstSpdLim_kph;
  uint8 dtld_st_tboxLifeSts;
  uint8 dtld_st_lockVehPerRxSts;
  uint8 dtld_st_verCvsRxSts;
  uint8 dtld_st_spdLmtLvRxSts;
  uint8 dtld_st_invSpdLmtRxSts;
  uint8 dtld_st_pwrOffCmdRxSts;
  uint8 dtld_st_pwrOffCmd;
} vcsb_OGVL;

#endif

/* PublicStructure Variables for Internal Data, for system '<S4>/turnON_delay3' */
typedef struct {
  float32 t_wait;                      /* '<S16>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S16>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S16>/timed_delay' */
} ARID_DEF_turnON_delay3_swc_OG_T;

/* PublicStructure Variables for Internal Data, for system '<S106>/Counter' */
typedef struct {
  uint8 UnitDelay3_DSTATE;             /* '<S124>/UnitDelay3' */
} ARID_DEF_Counter_swc_OGVL_T;

/* PublicStructure Variables for Internal Data, for system '<S106>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S126>/Unit Delay' */
} ARID_DEF_SR_latch_swc_OGVL_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay;/* '<S3>/turnON_delay' */
  ARID_DEF_SR_latch_swc_OGVL_T ARID_DEF_SR_latch;/* '<S111>/SR_latch' */
  ARID_DEF_Counter_swc_OGVL_T ARID_DEF_Counter;/* '<S111>/Counter' */
  ARID_DEF_SR_latch_swc_OGVL_T ARID_DEF_SR_latch_m;/* '<S110>/SR_latch' */
  ARID_DEF_Counter_swc_OGVL_T ARID_DEF_Counter_c;/* '<S110>/Counter' */
  ARID_DEF_SR_latch_swc_OGVL_T ARID_DEF_SR_latch_k;/* '<S109>/SR_latch' */
  ARID_DEF_Counter_swc_OGVL_T ARID_DEF_Counter_cx;/* '<S109>/Counter' */
  ARID_DEF_SR_latch_swc_OGVL_T ARID_DEF_SR_latch_b;/* '<S108>/SR_latch' */
  ARID_DEF_Counter_swc_OGVL_T ARID_DEF_Counter_p;/* '<S108>/Counter' */
  ARID_DEF_SR_latch_swc_OGVL_T ARID_DEF_SR_latch_c;/* '<S107>/SR_latch' */
  ARID_DEF_Counter_swc_OGVL_T ARID_DEF_Counter_f;/* '<S107>/Counter' */
  ARID_DEF_SR_latch_swc_OGVL_T ARID_DEF_SR_latch_g;/* '<S106>/SR_latch' */
  ARID_DEF_Counter_swc_OGVL_T ARID_DEF_Counter_g;/* '<S106>/Counter' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay4;/* '<S7>/turnON_delay4' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1;/* '<S33>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_m;/* '<S32>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_n;/* '<S31>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_p;/* '<S30>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_l;/* '<S29>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_j;/* '<S28>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_d;/* '<S27>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_g;/* '<S26>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_ld;/* '<S25>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_dh;/* '<S24>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay1_dy;/* '<S23>/turnON_delay1' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay4_l;/* '<S4>/turnON_delay4' */
  ARID_DEF_turnON_delay3_swc_OG_T ARID_DEF_turnON_delay3;/* '<S4>/turnON_delay3' */
  float64 Delay_DSTATE[10];            /* '<S7>/Delay' */
  float64 Delay_DSTATE_k[10];          /* '<S4>/Delay' */
  float64 Delay1_DSTATE[20];           /* '<S4>/Delay1' */
  float64 Delay2_DSTATE[30];           /* '<S4>/Delay2' */
  float64 UnitDelay_DSTATE;            /* '<S112>/Unit Delay' */
  float64 UnitDelay_DSTATE_g;          /* '<S113>/Unit Delay' */
  float64 UnitDelay_DSTATE_l;          /* '<S114>/Unit Delay' */
  float64 UnitDelay_DSTATE_c;          /* '<S115>/Unit Delay' */
  float64 UnitDelay_DSTATE_j;          /* '<S116>/Unit Delay' */
  float64 UnitDelay_DSTATE_a;          /* '<S117>/Unit Delay' */
  float32 UnitDelay_DSTATE_h;          /* '<S9>/Unit Delay' */
  float32 t_wait;                      /* '<S98>/timed_delay' */
  float32 t_wait_l;                    /* '<S96>/timed_delay' */
  float32 t_wait_k;                    /* '<S94>/timed_delay' */
  float32 t_wait_ku;                   /* '<S92>/timed_delay' */
  float32 t_wait_ly;                   /* '<S90>/timed_delay' */
  float32 t_wait_g;                    /* '<S88>/timed_delay' */
  float32 t_wait_h;                    /* '<S86>/timed_delay' */
  float32 t_wait_n;                    /* '<S84>/timed_delay' */
  float32 t_wait_b;                    /* '<S66>/timed_delay' */
  float32 t_wait_o;                    /* '<S65>/timed_delay' */
  float32 dt;                          /* '<S7>/ControlTorqueOff' */
  float32 t_wait_d;                    /* '<S61>/timed_delay' */
  float32 t_wait_f;                    /* '<S59>/timed_delay' */
  float32 t_wait_m;                    /* '<S15>/timed_delay' */
  float32 t_wait_p;                    /* '<S14>/timed_delay' */
  uint8 vsld_st_InventorySpdLmtReq;    /* '<S5>/Data Type Conversion1' */
  uint8 vsld_st_LockVehPer;            /* '<S5>/Switch12' */
  uint8 vsld_st_SpdLmtLevelReq;        /* '<S5>/Switch14' */
  uint8 Switch2;                       /* '<S22>/Switch2' */
  uint8 Switch1;                       /* '<S5>/Switch1' */
  uint8 Switch3;                       /* '<S5>/Switch3' */
  uint8 Switch5;                       /* '<S5>/Switch5' */
  uint8 Switch8;                       /* '<S5>/Switch8' */
  uint8 Switch10;                      /* '<S5>/Switch10' */
  uint8 Switch17;                      /* '<S5>/Switch17' */
  uint8 vsld_PowerOffCmdSts;           /* '<S5>/Data Type Conversion2' */
  uint8 UnitDelay_DSTATE_lx;           /* '<S22>/Unit Delay' */
  uint8 UnitDelay1_DSTATE;             /* '<S22>/Unit Delay1' */
  uint8 UnitDelay_DSTATE_p;            /* '<S5>/Unit Delay' */
  uint8 UnitDelay1_DSTATE_n;           /* '<S5>/Unit Delay1' */
  uint8 UnitDelay2_DSTATE;             /* '<S5>/Unit Delay2' */
  uint8 UnitDelay3_DSTATE;             /* '<S5>/Unit Delay3' */
  uint8 UnitDelay6_DSTATE;             /* '<S5>/Unit Delay6' */
  uint8 UnitDelay7_DSTATE;             /* '<S111>/Unit Delay7' */
  uint8 UnitDelay7_DSTATE_e;           /* '<S110>/Unit Delay7' */
  uint8 UnitDelay7_DSTATE_o;           /* '<S109>/Unit Delay7' */
  uint8 UnitDelay7_DSTATE_k;           /* '<S108>/Unit Delay7' */
  uint8 UnitDelay7_DSTATE_ox;          /* '<S107>/Unit Delay7' */
  uint8 UnitDelay7_DSTATE_k2;          /* '<S106>/Unit Delay7' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S98>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S98>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_b;   /* '<S96>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__d;/* '<S96>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_f;   /* '<S94>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__c;/* '<S94>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_l;   /* '<S92>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__o;/* '<S92>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_p;   /* '<S90>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_og;/* '<S90>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_h;   /* '<S88>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__p;/* '<S88>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_ps;  /* '<S86>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__g;/* '<S86>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_hw;  /* '<S84>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__e;/* '<S84>/timed_delay' */
  uint8 is_c19_swc_OGVL;              /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */
  uint8 is_Key_On;                    /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */
  uint8 is_active_c19_swc_OGVL;       /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */
  uint8 is_c18_swc_OGVL;              /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */
  uint8 is_Key_On_c;                  /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */
  uint8 is_active_c18_swc_OGVL;       /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */
  uint8 is_c17_swc_OGVL;              /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
  uint8 is_Key_On_o;                  /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
  uint8 is_active_c17_swc_OGVL;       /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
  uint8 is_c16_swc_OGVL;         /* '<S10>/En_Immediately_Dis_NextKeyOn_Lvl1' */
  uint8 is_active_c16_swc_OGVL;  /* '<S10>/En_Immediately_Dis_NextKeyOn_Lvl1' */
  uint8 is_c14_Ricardo_SW_dev_lib_n;   /* '<S66>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__b;/* '<S66>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_h1;  /* '<S65>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_ci;/* '<S65>/timed_delay' */
  uint8 is_c15_swc_OGVL;               /* '<S7>/En_Immediately_Dis_NextKeyOn' */
  uint8 is_active_c15_swc_OGVL;        /* '<S7>/En_Immediately_Dis_NextKeyOn' */
  uint8 is_c13_swc_OGVL;               /* '<S7>/ControlTorqueOff' */
  uint8 is_Active;                     /* '<S7>/ControlTorqueOff' */
  uint8 is_active_c13_swc_OGVL;        /* '<S7>/ControlTorqueOff' */
  uint8 is_c14_Ricardo_SW_dev_lib_d;   /* '<S61>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__a;/* '<S61>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_bk;  /* '<S59>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev__m;/* '<S59>/timed_delay' */
  uint8 is_c12_swc_OGVL;             /* '<S6>/En_Immediately_Dis_Immediately' */
  uint8 is_active_c12_swc_OGVL;      /* '<S6>/En_Immediately_Dis_Immediately' */
  uint8 is_c10_swc_OGVL;               /* '<S15>/timed_delay' */
  uint8 is_active_c10_swc_OGVL;        /* '<S15>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib_o;   /* '<S14>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_g3;/* '<S14>/timed_delay' */
  uint8 is_c1_swc_OGVL;               /* '<S4>/En_Immediately_Dis_NextKeyOn1' */
  uint8 is_active_c1_swc_OGVL;        /* '<S4>/En_Immediately_Dis_NextKeyOn1' */
  uint8 is_c8_swc_OGVL;                /* '<S4>/En_Immediately_Dis_NextKeyOn' */
  uint8 is_active_c8_swc_OGVL;         /* '<S4>/En_Immediately_Dis_NextKeyOn' */
  boolean vsld_b_dstTboxOfflineRaw;    /* '<S4>/Logical Operator5' */
  boolean LogicalOperator6;            /* '<S4>/Logical Operator6' */
  boolean LogicalOperator;             /* '<S4>/Logical Operator' */
  boolean vsld_st_VersionConversion;   /* '<S5>/Signal Conversion' */
  boolean cmdWrite;                   /* '<S4>/En_Immediately_Dis_NextKeyOn1' */
  boolean cmdWrite_i;                  /* '<S4>/En_Immediately_Dis_NextKeyOn' */
  boolean UnitDelay_DSTATE_hv;         /* '<S4>/Unit Delay' */
  boolean UnitDelay4_DSTATE;           /* '<S10>/UnitDelay4' */
  boolean UnitDelay1_DSTATE_a;         /* '<S10>/UnitDelay1' */
  boolean UnitDelay2_DSTATE_h;         /* '<S10>/UnitDelay2' */
  boolean DelayInput1_DSTATE;          /* '<S71>/Delay Input1' */
  boolean DelayInput1_DSTATE_n;        /* '<S145>/Delay Input1' */
  boolean DelayInput1_DSTATE_l;        /* '<S141>/Delay Input1' */
  boolean DelayInput1_DSTATE_d;        /* '<S137>/Delay Input1' */
  boolean DelayInput1_DSTATE_e;        /* '<S133>/Delay Input1' */
  boolean DelayInput1_DSTATE_lx;       /* '<S129>/Delay Input1' */
  boolean DelayInput1_DSTATE_b;        /* '<S125>/Delay Input1' */
  boolean DstSpeedLimit_MODE;          /* '<S1>/DstSpeedLimit' */
} ARID_DEF_swc_OGVL_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float64 Divide;                /* '<S112>/Divide' */
  const float64 Divide_k;              /* '<S113>/Divide' */
  const float64 Divide_n;              /* '<S114>/Divide' */
  const float64 Divide_e;              /* '<S115>/Divide' */
  const float64 Divide_f;              /* '<S116>/Divide' */
  const float64 Divide_g;              /* '<S117>/Divide' */
} ConstB_swc_OGVL_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_OGVL_T swc_OGVL_ARID_DEF;
extern const ConstB_swc_OGVL_T swc_OGVL_ConstB;/* constant block i/o */

/* Exported data declaration */
#define swc_OGVL_START_SEC_CONST_VOLATILE
#include "swc_OGVL_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile boolean ogvl_dtlc_b_nvmWriteAntiDismtLckReq_ovrdflg;
            /* Referenced by: '<S100>/dtlc_b_nvmWriteAntiDismtLckReq_ovrdflg' */
extern const volatile boolean ogvl_dtlc_b_nvmWriteDSTNOSC_ovrdflg;
                    /* Referenced by: '<S101>/dtlc_b_nvmWriteDSTNOSC_ovrdflg' */
extern const volatile boolean ogvl_dtlc_b_nvmWriteInvtryLck_ovrdflg;
             /* Referenced by: '<S102>/ogvl_dtlc_b_nvmWriteInvtryLck_ovrdflg' */
extern const volatile boolean ogvl_dtlc_b_nvmWritePwrOffCmdReq_ovrdflg;
               /* Referenced by: '<S103>/dtlc_b_nvmWritePwrOffCmdReq_ovrdflg' */
extern const volatile boolean ogvl_dtlc_b_nvmWriteSpdLmtLvlReq_ovrdflg;
               /* Referenced by: '<S104>/dtlc_b_nvmWriteSpdLmtLvlReq_ovrdflg' */
extern const volatile uint8 ogvl_dtlc_st_nvmWriteAntiDismtLckReq_ovrdval;
           /* Referenced by: '<S100>/dtlc_st_nvmWriteAntiDismtLckReq_ovrdval' */
extern const volatile uint8 ogvl_dtlc_st_nvmWriteDSTNOSC_ovrdval;
                   /* Referenced by: '<S101>/dtlc_st_nvmWriteDSTNOSC_ovrdval' */
extern const volatile uint8 ogvl_dtlc_st_nvmWriteInvtryLck_ovrdval;
            /* Referenced by: '<S102>/ogvl_dtlc_st_nvmWriteInvtryLck_ovrdval' */
extern const volatile uint8 ogvl_dtlc_st_nvmWritePwrOffCmdReq_ovrdval;
              /* Referenced by: '<S103>/dtlc_st_nvmWritePwrOffCmdReq_ovrdval' */
extern const volatile uint8 ogvl_dtlc_st_nvmWriteSpdLmtLvlReq_ovrdval;
              /* Referenced by: '<S104>/dtlc_st_nvmWriteSpdLmtLvlReq_ovrdval' */
extern const volatile boolean ovgl_b_nvmWriteTboxDsmtSet_ovrdflg;
                /* Referenced by: '<S105>/ovgl_b_nvmWriteTboxDsmtSet_ovrdflg' */
extern const volatile uint8 ovgl_b_nvmWriteTboxDsmtSet_ovrdval;
                /* Referenced by: '<S105>/ovgl_b_nvmWriteTboxDsmtSet_ovrdval' */
extern const volatile float32 vslc_tm_IgnOnGetNvmDly_s;/* Referenced by: '<S3>/Constant11' */
extern const volatile float32 vslc_tm_tboxDsmtDlyOff_s;/* Referenced by: '<S4>/Constant57' */
extern const volatile float32 vslc_tm_tboxDsmtDlyOn_s;/* Referenced by: '<S4>/Constant56' */
extern const volatile float32 vslc_tm_tboxVerConvDlyOff_s;/* Referenced by: '<S57>/Constant5' */
extern const volatile float32 vslc_tm_tboxVerConvDlyOn_s;/* Referenced by: '<S58>/Constant4' */
extern const volatile float32 vslc_v_vehSpdLimLevel1_kph;/* Referenced by:
                                                          * '<S5>/Constant1'
                                                          * '<S9>/Constant1'
                                                          */

/* Speed limit Level1 */
extern const volatile float32 vslc_v_vehSpdLimLevel2_kph;/* Referenced by:
                                                          * '<S5>/Constant3'
                                                          * '<S9>/Constant3'
                                                          */

/* Speed limit Level2 */
extern const volatile float32 vslc_v_vehSpdLimLevel3_kph;/* Referenced by:
                                                          * '<S5>/Constant13'
                                                          * '<S9>/Constant13'
                                                          */

/* Speed limit Level3 */
extern const volatile float32 vslc_v_vehSpdUpdLimCfg_kph;/* Referenced by: '<S9>/Constant2' */

/* Remote Lock Speed Limit Update Enable Speed Threshold */
#define swc_OGVL_STOP_SEC_CONST_VOLATILE
#include "swc_OGVL_MemMap.h"
#define swc_OGVL_START_SEC_VAR
#include "swc_OGVL_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern uint8 Ovrd_b_nvmWriteTboxDsmtWrite;/* '<S123>/Switch2' */
extern boolean ovgl_b_dstTboxDsmtExc; /* '<S4>/En_Immediately_Dis_NextKeyOn1' */
extern boolean ovgl_dtld_b_dstAntiDismtLckDis;/* '<S4>/Logical Operator2' */
extern boolean ovgl_dtld_b_dstAntiDismtLckEn;/* '<S4>/Logical Operator12' */
extern boolean ovgl_dtld_b_dstAntiDismtLckExc;/* '<S4>/En_Immediately_Dis_NextKeyOn' */
extern boolean ovgl_dtld_b_dstCtrlTqLmt;/* '<S7>/Signal Conversion' */
extern boolean ovgl_dtld_b_dstCtrlTqOff;/* '<S7>/Signal Conversion1' */
extern boolean ovgl_dtld_b_dstInvtryLckDis;/* '<S96>/timed_delay' */
extern boolean ovgl_dtld_b_dstInvtryLckEn;/* '<S94>/timed_delay' */
extern boolean ovgl_dtld_b_dstInvtryLckExc;
                                      /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */
extern boolean ovgl_dtld_b_dstInvtryLckRead;/* '<S8>/Data Type Conversion4' */
extern boolean ovgl_dtld_b_dstInvtryLckWrite;
                                      /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl2' */
extern boolean ovgl_dtld_b_dstLckVehVerDis;/* '<S59>/timed_delay' */
extern boolean ovgl_dtld_b_dstLckVehVerEn;/* '<S61>/timed_delay' */
extern boolean ovgl_dtld_b_dstLckVehVerExc;
                                     /* '<S6>/En_Immediately_Dis_Immediately' */
extern boolean ovgl_dtld_b_dstLckVehVerWrite;
                                     /* '<S6>/En_Immediately_Dis_Immediately' */
extern boolean ovgl_dtld_b_dstPwrOffDis;/* '<S65>/timed_delay' */
extern boolean ovgl_dtld_b_dstPwrOffExc;/* '<S7>/En_Immediately_Dis_NextKeyOn' */
extern boolean ovgl_dtld_b_dstPwrOffOn;/* '<S66>/timed_delay' */
extern boolean ovgl_dtld_b_dstPwrOffWrite;/* '<S7>/En_Immediately_Dis_NextKeyOn' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl1Dis;/* '<S86>/timed_delay' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl1En;/* '<S88>/timed_delay' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl1Exc;
                                 /* '<S10>/En_Immediately_Dis_NextKeyOn_Lvl1' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl1Write;
                                 /* '<S10>/En_Immediately_Dis_NextKeyOn_Lvl1' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl2Dis;/* '<S90>/timed_delay' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl2En;/* '<S98>/timed_delay' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl2Exc;
                                      /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl2Write;
                                      /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl1' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl3Dis;/* '<S92>/timed_delay' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl3En;/* '<S84>/timed_delay' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl3Exc;
                                      /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */
extern boolean ovgl_dtld_b_dstSpdLmtLvl3Write;
                                      /* '<S10>/En_NextOn_Dis_NextKeyOn_Lvl3' */
extern uint8 ovgl_dtld_st_dstAntiDismtLckRead;/* '<S8>/Data Type Conversion3' */
extern uint8 ovgl_dtld_st_dstLckVehVerRead;/* '<S8>/Data Type Conversion2' */
extern uint8 ovgl_dtld_st_dstPwrOffCmdRead;/* '<S8>/Data Type Conversion1' */
extern uint8 ovgl_dtld_st_dstSpdLmtLvlRead;/* '<S8>/Data Type Conversion5' */
extern uint8 ovgl_dtld_st_dstSpdLmtLvlWrite;/* '<S10>/Switch4' */
extern uint8 ovgl_dtld_st_dstTboxDsmtRead;/* '<S8>/Data Type Conversion13' */
extern uint8 ovgl_dtld_st_nvmWriteAntiDismtLckReq;/* '<S118>/Switch2' */
extern uint8 ovgl_dtld_st_nvmWriteDSTNOSC;/* '<S119>/Switch2' */
extern uint8 ovgl_dtld_st_nvmWriteDismantleCmdCnt;/* '<S107>/Counter' */
extern boolean ovgl_dtld_st_nvmWriteDismantleCmdEnbl;/* '<S107>/SR_latch' */
extern uint8 ovgl_dtld_st_nvmWriteDismantleCmdReturnVal;
                                     /* '<S107>/mBSW_NvmRead_DSTNOSC_retval1' */
extern boolean ovgl_dtld_st_nvmWriteDismantleCmdRset;/* '<S129>/FixPt Relational Operator' */
extern uint8 ovgl_dtld_st_nvmWriteDismantleCmd_1s;/* '<S107>/Signal Conversion' */
extern uint8 ovgl_dtld_st_nvmWriteDstLckVehTypeCmdCnt;/* '<S108>/Counter' */
extern boolean ovgl_dtld_st_nvmWriteDstLckVehTypeCmdEnbl;/* '<S108>/SR_latch' */
extern uint8 ovgl_dtld_st_nvmWriteDstLckVehTypeCmdReturnVal;
                                     /* '<S108>/mBSW_NvmRead_DSTNOSC_retval1' */
extern boolean ovgl_dtld_st_nvmWriteDstLckVehTypeCmdRset;/* '<S133>/FixPt Relational Operator' */
extern uint8 ovgl_dtld_st_nvmWriteDstLckVehTypeCmd_1s;/* '<S108>/Signal Conversion' */
extern uint8 ovgl_dtld_st_nvmWriteDstNoscCnt;/* '<S106>/Counter' */
extern boolean ovgl_dtld_st_nvmWriteDstNoscEnbl;/* '<S106>/SR_latch' */
extern boolean ovgl_dtld_st_nvmWriteDstNoscRset;/* '<S125>/FixPt Relational Operator' */
extern uint8 ovgl_dtld_st_nvmWriteDstNosc_1s;/* '<S106>/Signal Conversion' */
extern uint8 ovgl_dtld_st_nvmWriteDstPwrOffCmdReqCnt;/* '<S110>/Counter' */
extern boolean ovgl_dtld_st_nvmWriteDstPwrOffCmdReqEnbl;/* '<S110>/SR_latch' */
extern uint8 ovgl_dtld_st_nvmWriteDstPwrOffCmdReqReturnVal;
                                     /* '<S110>/mBSW_NvmRead_DSTNOSC_retval1' */
extern boolean ovgl_dtld_st_nvmWriteDstPwrOffCmdReqRset;/* '<S141>/FixPt Relational Operator' */
extern uint8 ovgl_dtld_st_nvmWriteDstPwrOffCmdReq_1s;/* '<S110>/Signal Conversion' */
extern uint8 ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqCnt;/* '<S109>/Counter' */
extern boolean ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqEnbl;/* '<S109>/SR_latch' */
extern uint8 ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqReturnVal;
                                     /* '<S109>/mBSW_NvmRead_DSTNOSC_retval1' */
extern boolean ovgl_dtld_st_nvmWriteDstSpdLmtLvlReqRset;/* '<S137>/FixPt Relational Operator' */
extern uint8 ovgl_dtld_st_nvmWriteDstSpdLmtLvlReq_1s;/* '<S109>/Signal Conversion' */
extern boolean ovgl_dtld_st_nvmWriteDstTboxDsmtEnbl;/* '<S111>/SR_latch' */
extern uint8 ovgl_dtld_st_nvmWriteDstTboxDsmtReturnVal;
                                     /* '<S111>/mBSW_NvmRead_TboxDsmt_retval' */
extern boolean ovgl_dtld_st_nvmWriteDstTboxDsmtRset;/* '<S145>/FixPt Relational Operator' */
extern uint8 ovgl_dtld_st_nvmWriteDstnoscReturnVal;
                                     /* '<S106>/mBSW_NvmRead_DSTNOSC_retval1' */
extern uint8 ovgl_dtld_st_nvmWriteInvtryLck;/* '<S120>/Switch2' */
extern uint8 ovgl_dtld_st_nvmWritePwrOffCmdReq;/* '<S121>/Switch2' */
extern uint8 ovgl_dtld_st_nvmWriteSpdLmtLvlReq;/* '<S122>/Switch2' */
extern boolean vsld_b_dstTboxDsmtReset;/* '<S15>/timed_delay' */
extern boolean vsld_b_dstTboxDsmtSet;  /* '<S14>/timed_delay' */
extern float32 vsld_v_dstSpdLimRaw_kph;/* '<S9>/Switch' */
extern float32 vsld_v_dstSpdLim_kph;   /* '<S9>/Switch3' */

#define swc_OGVL_STOP_SEC_VAR
#include "swc_OGVL_MemMap.h"

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
 * '<Root>' : 'swc_OGVL'
 * '<S1>'   : 'swc_OGVL/DTL_DstVehicleLock1'
 * '<S2>'   : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit'
 * '<S3>'   : 'swc_OGVL/DTL_DstVehicleLock1/Subsystem'
 * '<S4>'   : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand'
 * '<S5>'   : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend'
 * '<S6>'   : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/LockVersionDemand'
 * '<S7>'   : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand'
 * '<S8>'   : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/ReadFromNVM'
 * '<S9>'   : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitCommand'
 * '<S10>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand'
 * '<S11>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM'
 * '<S12>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/En_Immediately_Dis_NextKeyOn'
 * '<S13>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/En_Immediately_Dis_NextKeyOn1'
 * '<S14>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/turnON_delay1'
 * '<S15>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/turnON_delay2'
 * '<S16>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/turnON_delay3'
 * '<S17>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/turnON_delay4'
 * '<S18>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/turnON_delay1/timed_delay'
 * '<S19>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/turnON_delay2/timed_delay'
 * '<S20>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/turnON_delay3/timed_delay'
 * '<S21>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/Anti_DismantleDemand/turnON_delay4/timed_delay'
 * '<S22>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/LifeCounter'
 * '<S23>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce1'
 * '<S24>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce14'
 * '<S25>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce15'
 * '<S26>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce2'
 * '<S27>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce3'
 * '<S28>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce4'
 * '<S29>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce5'
 * '<S30>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce6'
 * '<S31>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce7'
 * '<S32>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce8'
 * '<S33>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce9'
 * '<S34>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce1/turnON_delay1'
 * '<S35>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce1/turnON_delay1/timed_delay'
 * '<S36>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce14/turnON_delay1'
 * '<S37>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce14/turnON_delay1/timed_delay'
 * '<S38>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce15/turnON_delay1'
 * '<S39>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce15/turnON_delay1/timed_delay'
 * '<S40>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce2/turnON_delay1'
 * '<S41>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce2/turnON_delay1/timed_delay'
 * '<S42>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce3/turnON_delay1'
 * '<S43>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce3/turnON_delay1/timed_delay'
 * '<S44>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce4/turnON_delay1'
 * '<S45>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce4/turnON_delay1/timed_delay'
 * '<S46>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce5/turnON_delay1'
 * '<S47>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce5/turnON_delay1/timed_delay'
 * '<S48>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce6/turnON_delay1'
 * '<S49>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce6/turnON_delay1/timed_delay'
 * '<S50>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce7/turnON_delay1'
 * '<S51>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce7/turnON_delay1/timed_delay'
 * '<S52>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce8/turnON_delay1'
 * '<S53>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce8/turnON_delay1/timed_delay'
 * '<S54>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce9/turnON_delay1'
 * '<S55>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/CANSend/debounce9/turnON_delay1/timed_delay'
 * '<S56>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/LockVersionDemand/En_Immediately_Dis_Immediately'
 * '<S57>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/LockVersionDemand/Subsystem4'
 * '<S58>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/LockVersionDemand/debounce4'
 * '<S59>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/LockVersionDemand/Subsystem4/turnON_delay1'
 * '<S60>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/LockVersionDemand/Subsystem4/turnON_delay1/timed_delay'
 * '<S61>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/LockVersionDemand/debounce4/turnON_delay1'
 * '<S62>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/LockVersionDemand/debounce4/turnON_delay1/timed_delay'
 * '<S63>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand/ControlTorqueOff'
 * '<S64>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand/En_Immediately_Dis_NextKeyOn'
 * '<S65>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand/turnON_delay1'
 * '<S66>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand/turnON_delay2'
 * '<S67>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand/turnON_delay4'
 * '<S68>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand/turnON_delay1/timed_delay'
 * '<S69>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand/turnON_delay2/timed_delay'
 * '<S70>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/PowerOffDemand/turnON_delay4/timed_delay'
 * '<S71>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/Detect Increase'
 * '<S72>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/En_Immediately_Dis_NextKeyOn_Lvl1'
 * '<S73>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/En_NextOn_Dis_NextKeyOn_Lvl1'
 * '<S74>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/En_NextOn_Dis_NextKeyOn_Lvl2'
 * '<S75>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/En_NextOn_Dis_NextKeyOn_Lvl3'
 * '<S76>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce1'
 * '<S77>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce11'
 * '<S78>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce12'
 * '<S79>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce17'
 * '<S80>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce2'
 * '<S81>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce3'
 * '<S82>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce4'
 * '<S83>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce6'
 * '<S84>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce1/turnON_delay1'
 * '<S85>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce1/turnON_delay1/timed_delay'
 * '<S86>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce11/turnON_delay1'
 * '<S87>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce11/turnON_delay1/timed_delay'
 * '<S88>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce12/turnON_delay1'
 * '<S89>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce12/turnON_delay1/timed_delay'
 * '<S90>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce17/turnON_delay1'
 * '<S91>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce17/turnON_delay1/timed_delay'
 * '<S92>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce2/turnON_delay1'
 * '<S93>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce2/turnON_delay1/timed_delay'
 * '<S94>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce3/turnON_delay1'
 * '<S95>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce3/turnON_delay1/timed_delay'
 * '<S96>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce4/turnON_delay1'
 * '<S97>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce4/turnON_delay1/timed_delay'
 * '<S98>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce6/turnON_delay1'
 * '<S99>'  : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/SpeedLimitLevelDemand/debounce6/turnON_delay1/timed_delay'
 * '<S100>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteAntiDismtLckReq'
 * '<S101>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteDSTNOSC_eep'
 * '<S102>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteInvtryLck'
 * '<S103>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWritePwrOffCmdReq'
 * '<S104>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteSpdLmtLvlReq'
 * '<S105>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteTboxDsmtWrite'
 * '<S106>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem10'
 * '<S107>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem11'
 * '<S108>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem12'
 * '<S109>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem13'
 * '<S110>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem14'
 * '<S111>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem2'
 * '<S112>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg'
 * '<S113>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg1'
 * '<S114>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg2'
 * '<S115>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg3'
 * '<S116>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg4'
 * '<S117>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg6'
 * '<S118>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteAntiDismtLckReq/override_signal'
 * '<S119>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteDSTNOSC_eep/override_signal'
 * '<S120>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteInvtryLck/override_signal'
 * '<S121>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWritePwrOffCmdReq/override_signal'
 * '<S122>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteSpdLmtLvlReq/override_signal'
 * '<S123>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Ovrd_b_nvmWriteTboxDsmtWrite/override_signal'
 * '<S124>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem10/Counter'
 * '<S125>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem10/Detect Decrease'
 * '<S126>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem10/SR_latch'
 * '<S127>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem10/mBSW_NvmWrite_DSTNOSC_eep'
 * '<S128>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem11/Counter'
 * '<S129>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem11/Detect Decrease'
 * '<S130>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem11/SR_latch'
 * '<S131>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem11/mBSW_NvmWrite_dstAntiDismtLckReq'
 * '<S132>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem12/Counter'
 * '<S133>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem12/Detect Decrease'
 * '<S134>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem12/SR_latch'
 * '<S135>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem12/vsld_st_dstLckVehTypeCmd'
 * '<S136>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem13/Counter'
 * '<S137>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem13/Detect Decrease'
 * '<S138>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem13/SR_latch'
 * '<S139>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem13/ogvl_vsld_st_dstSpdLmtLvlReq'
 * '<S140>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem14/Counter'
 * '<S141>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem14/Detect Decrease'
 * '<S142>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem14/SR_latch'
 * '<S143>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem14/ogvl_dtld_st_dstPwrOffCmdReq'
 * '<S144>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem2/Counter'
 * '<S145>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem2/Detect Decrease'
 * '<S146>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem2/SR_latch'
 * '<S147>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/Subsystem2/ogvl_dtld_st_dstPwrOffCmdReq'
 * '<S148>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg/Enabled Subsystem'
 * '<S149>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg1/Enabled Subsystem'
 * '<S150>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg2/Enabled Subsystem'
 * '<S151>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg3/Enabled Subsystem'
 * '<S152>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg4/Enabled Subsystem'
 * '<S153>' : 'swc_OGVL/DTL_DstVehicleLock1/DstSpeedLimit/WriteToNVM/TaskPeriodConfg6/Enabled Subsystem'
 * '<S154>' : 'swc_OGVL/DTL_DstVehicleLock1/Subsystem/turnON_delay'
 * '<S155>' : 'swc_OGVL/DTL_DstVehicleLock1/Subsystem/turnON_delay/timed_delay'
 */
#endif                                 /* RTW_HEADER_swc_OGVL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
