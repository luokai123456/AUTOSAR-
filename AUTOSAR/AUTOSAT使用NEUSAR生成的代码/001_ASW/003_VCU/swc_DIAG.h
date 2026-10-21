/*
 * File: swc_DIAG.h
 *
 * Code generated for Simulink model 'swc_DIAG'.
 *
 * Model version                  : 6.377
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 21 15:45:21 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_DIAG_h_
#define RTW_HEADER_swc_DIAG_h_
#ifndef swc_DIAG_COMMON_INCLUDES_
#define swc_DIAG_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_DIAG.h"
#endif                                 /* swc_DIAG_COMMON_INCLUDES_ */

#include "Rte_Type.h"
#include "zero_crossing_types.h"

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
} vcib_VCIP;

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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_AUXC_
#define DEFINED_TYPEDEF_FOR_vcsb_AUXC_

typedef struct {
  boolean brpd_b_airTankPresLowEVDis;
  boolean brpd_b_VacPumpSnrFlt;
  boolean brpd_b_VacTkAirPresLowFlt;
  boolean brpd_b_VacPumpAuxRlyEn;
  boolean brpd_b_VacPumpRlyEn;
  boolean brpd_b_VacPumpSysFailFlt;
  boolean brpd_b_VacPumpEnOvrTmLoPreFlt;
  boolean brpd_b_VacPumpEnOvrTmHiPreFlt;
  boolean brpd_b_VacPumpLoPreFlt;
  float32 brpd_p_VacPumpPressure_kPa;
  float32 brpd_u_VacPumpVol_V;
  boolean pscd_b_epsStopFlt;
  boolean brpd_b_brkPmp1Rly;
  boolean brpd_b_brkPmp2Rly;
  boolean brpd_b_bdcacEna;
  boolean brpd_b_pumpRdy;
  boolean brpd_b_airTankFlt;
  boolean brpd_b_bdcacTmOut;
  boolean brpd_b_airTankPresLow;
  boolean lvbd_b_lvbSOCValid;
  float32 lvbd_q_lvbSOC_pct;
  float32 pscd_frq_epsFrqTgt_Hz;
  boolean pscd_b_epsEna;
  boolean brpd_b_airTankPresLowInhDrv;
  boolean brpd_b_VacPumpRlyFlt;
} vcsb_AUXC;

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

/* PublicStructure Variables for Internal Data, for system '<S165>/timed_debounce' */
typedef struct {
  float32 t_wait;                      /* '<S165>/timed_debounce' */
  uint8 is_c65_swc_DIAG;               /* '<S165>/timed_debounce' */
  uint8 is_active_c65_swc_DIAG;        /* '<S165>/timed_debounce' */
} ARID_DEF_timed_debounce_swc_D_T;

/* PublicStructure Variables for Internal Data, for system '<S117>/turnOFF_delay' */
typedef struct {
  float32 t_wait;                      /* '<S161>/timed_delay' */
  uint8 is_c62_swc_DIAG;               /* '<S161>/timed_delay' */
  uint8 is_active_c62_swc_DIAG;        /* '<S161>/timed_delay' */
} ARID_DEF_turnOFF_delay_swc_DI_T;

/* PublicStructure Variables for Internal Data, for system '<S5>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S186>/Unit Delay' */
} ARID_DEF_SR_latch1_swc_DIAG_T;

/* PublicStructure Variables for Internal Data, for system '<S206>/turnON_delay' */
typedef struct {
  float32 t_wait;                      /* '<S224>/timed_delay' */
  uint8 is_c14_Ricardo_SW_dev_lib;     /* '<S224>/timed_delay' */
  uint8 is_active_c14_Ricardo_SW_dev_li;/* '<S224>/timed_delay' */
} ARID_DEF_turnON_delay_swc_DIA_T;

/* PublicStructure Variables for Internal Data, for system '<S7>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S213>/Unit Delay' */
} ARID_DEF_SR_latch1_swc_DIAG_m_T;

/* PublicStructure Variables for Internal Data, for system '<S8>/SR_latch2' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S276>/Unit Delay' */
} ARID_DEF_SR_latch2_swc_DIAG_T;

/* PublicStructure Variables for Internal Data, for system '<S8>/SR_latch3' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S277>/Unit Delay' */
} ARID_DEF_SR_latch3_swc_DIAG_T;

/* PublicStructure Variables for Internal Data, for system '<S8>/SR_latch4' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S278>/Unit Delay' */
} ARID_DEF_SR_latch4_swc_DIAG_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_turnON_delay_swc_DIA_T ARID_DEF_turnON_delay5;/* '<S367>/turnON_delay5' */
  ARID_DEF_turnON_delay_swc_DIA_T ARID_DEF_turnON_delay5_m;/* '<S366>/turnON_delay5' */
  ARID_DEF_turnON_delay_swc_DIA_T ARID_DEF_turnON_delay5_c;/* '<S365>/turnON_delay5' */
  ARID_DEF_turnON_delay_swc_DIA_T ARID_DEF_turnON_delay5_k;/* '<S364>/turnON_delay5' */
  ARID_DEF_SR_latch4_swc_DIAG_T ARID_DEF_SR_latch4;/* '<S8>/SR_latch4' */
  ARID_DEF_SR_latch3_swc_DIAG_T ARID_DEF_SR_latch3;/* '<S8>/SR_latch3' */
  ARID_DEF_SR_latch2_swc_DIAG_T ARID_DEF_SR_latch2;/* '<S8>/SR_latch2' */
  ARID_DEF_SR_latch1_swc_DIAG_m_T ARID_DEF_SR_latch1;/* '<S7>/SR_latch1' */
  ARID_DEF_turnON_delay_swc_DIA_T ARID_DEF_turnON_delay;/* '<S206>/turnON_delay' */
  ARID_DEF_SR_latch1_swc_DIAG_T ARID_DEF_SR_latch1_c;/* '<S5>/SR_latch1' */
  ARID_DEF_turnOFF_delay_swc_DI_T ARID_DEF_turnOFF_delay1;/* '<S117>/turnOFF_delay1' */
  ARID_DEF_turnOFF_delay_swc_DI_T ARID_DEF_turnOFF_delay;/* '<S117>/turnOFF_delay' */
  ARID_DEF_timed_debounce_swc_D_T ARID_DEF_timed_debounce;/* '<S160>/timed_debounce' */
  ARID_DEF_timed_debounce_swc_D_T ARID_DEF_timed_debounce_b;/* '<S165>/timed_debounce' */
  float64 DataTypeConversion117;       /* '<Root>/Data Type Conversion117' */
  float64 DataTypeConversion20;        /* '<Root>/Data Type Conversion20' */
  float64 DataTypeConversion33;        /* '<Root>/Data Type Conversion33' */
  float64 DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  float64 DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  float32 DataTypeConversion51;        /* '<Root>/Data Type Conversion51' */
  float32 DataTypeConversion52;        /* '<Root>/Data Type Conversion52' */
  float32 DataTypeConversion53;        /* '<Root>/Data Type Conversion53' */
  float32 DataTypeConversion252;       /* '<Root>/Data Type Conversion252' */
  float32 DataTypeConversion253;       /* '<Root>/Data Type Conversion253' */
  float32 t_wait;                      /* '<S434>/timed_debounce' */
  float32 t_wait_p;                    /* '<S431>/timed_debounce' */
  float32 t_wait_l;                    /* '<S428>/timed_debounce' */
  float32 t_wait_k;                    /* '<S425>/timed_debounce' */
  float32 t_wait_m;                    /* '<S422>/timed_debounce' */
  float32 t_wait_c;                    /* '<S419>/timed_debounce' */
  float32 t_wait_a;                    /* '<S416>/timed_debounce' */
  float32 t_wait_h;                    /* '<S413>/timed_debounce' */
  float32 t_wait_l1;                   /* '<S410>/timed_debounce' */
  float32 t_wait_ky;                   /* '<S407>/timed_debounce' */
  float32 t_wait_b;                    /* '<S404>/timed_debounce' */
  float32 t_wait_h0;                   /* '<S401>/timed_debounce' */
  float32 t_wait_be;                   /* '<S327>/timed_debounce' */
  float32 t_wait_mg;                   /* '<S325>/timed_debounce' */
  float32 t_wait_cb;                   /* '<S323>/timed_debounce' */
  float32 t_wait_j;                    /* '<S321>/timed_debounce' */
  float32 t_wait_f;                    /* '<S319>/timed_debounce' */
  float32 t_wait_cc;                   /* '<S317>/timed_debounce' */
  float32 t_wait_mt;                   /* '<S315>/timed_debounce' */
  float32 t_wait_pp;                   /* '<S313>/timed_debounce' */
  float32 t_wait_ph;                   /* '<S311>/timed_debounce' */
  float32 t_wait_d;                    /* '<S309>/timed_debounce' */
  float32 t_wait_ho;                   /* '<S307>/timed_debounce' */
  float32 t_wait_i;                    /* '<S305>/timed_debounce' */
  float32 t_wait_jt;                   /* '<S303>/timed_debounce' */
  float32 t_wait_fi;                   /* '<S301>/timed_debounce' */
  float32 t_wait_ap;                   /* '<S299>/timed_debounce' */
  float32 t_wait_i1;                   /* '<S297>/timed_debounce' */
  float32 t_wait_d1;                   /* '<S295>/timed_debounce' */
  float32 t_wait_e;                    /* '<S227>/timed_debounce' */
  float32 t_wait_k3;                   /* '<S223>/timed_debounce' */
  float32 t_wait_bd;                   /* '<S220>/timed_debounce' */
  float32 t_wait_g;                    /* '<S218>/timed_debounce' */
  float32 t_wait_il;                   /* '<S191>/timed_debounce' */
  float32 t_wait_iu;                   /* '<S189>/timed_debounce' */
  float32 t_wait_ml;                   /* '<S175>/timed_debounce' */
  float32 t_wait_lj;                   /* '<S137>/timed_debounce' */
  float32 t_wait_fp;                   /* '<S135>/timed_debounce' */
  float32 t_wait_iq;                   /* '<S133>/timed_debounce' */
  float32 t_wait_aj;                   /* '<S131>/timed_debounce' */
  float32 t_wait_jv;                   /* '<S129>/timed_debounce' */
  float32 t_wait_df;                   /* '<S127>/timed_debounce' */
  float32 t_wait_eg;                   /* '<S125>/timed_debounce' */
  float32 t_wait_fu;                   /* '<S80>/timed_debounce' */
  float32 t_wait_pu;                   /* '<S77>/timed_debounce' */
  float32 t_wait_ij;                   /* '<S76>/timed_debounce' */
  float32 t_wait_bj;                   /* '<S73>/timed_debounce' */
  float32 t_wait_n;                    /* '<S72>/timed_debounce' */
  float32 t_wait_do;                   /* '<S69>/timed_debounce' */
  float32 t_wait_a3;                   /* '<S68>/timed_debounce' */
  float32 t_wait_j0;                   /* '<S65>/timed_debounce' */
  float32 t_wait_aq;                   /* '<S64>/timed_debounce' */
  float32 t_wait_g0;                   /* '<S61>/timed_debounce' */
  float32 t_wait_cv;                   /* '<S60>/timed_debounce' */
  float32 t_wait_hq;                   /* '<S57>/timed_debounce' */
  float32 t_wait_ng;                   /* '<S56>/timed_debounce' */
  float32 t_wait_ez;                   /* '<S53>/timed_debounce' */
  float32 t_wait_nj;                   /* '<S52>/timed_debounce' */
  float32 t_wait_j4;                   /* '<S49>/timed_debounce' */
  float32 t_wait_jr;                   /* '<S48>/timed_debounce' */
  uint8 DataTypeConversion182;         /* '<Root>/Data Type Conversion182' */
  uint8 DataTypeConversion24;          /* '<Root>/Data Type Conversion24' */
  FaultStatus DataTypeConversion183;   /* '<Root>/Data Type Conversion183' */
  uint8 Delay1_DSTATE;                 /* '<S117>/Delay1' */
  uint8 DelayInput1_DSTATE;            /* '<S158>/Delay Input1' */
  uint8 Delay_DSTATE;                  /* '<S117>/Delay' */
  uint8 is_c55_swc_DIAG;               /* '<S434>/timed_debounce' */
  uint8 is_active_c55_swc_DIAG;        /* '<S434>/timed_debounce' */
  uint8 is_c54_swc_DIAG;               /* '<S431>/timed_debounce' */
  uint8 is_active_c54_swc_DIAG;        /* '<S431>/timed_debounce' */
  uint8 is_c53_swc_DIAG;               /* '<S428>/timed_debounce' */
  uint8 is_active_c53_swc_DIAG;        /* '<S428>/timed_debounce' */
  uint8 is_c52_swc_DIAG;               /* '<S425>/timed_debounce' */
  uint8 is_active_c52_swc_DIAG;        /* '<S425>/timed_debounce' */
  uint8 is_c51_swc_DIAG;               /* '<S422>/timed_debounce' */
  uint8 is_active_c51_swc_DIAG;        /* '<S422>/timed_debounce' */
  uint8 is_c50_swc_DIAG;               /* '<S419>/timed_debounce' */
  uint8 is_active_c50_swc_DIAG;        /* '<S419>/timed_debounce' */
  uint8 is_c49_swc_DIAG;               /* '<S416>/timed_debounce' */
  uint8 is_active_c49_swc_DIAG;        /* '<S416>/timed_debounce' */
  uint8 is_c48_swc_DIAG;               /* '<S413>/timed_debounce' */
  uint8 is_active_c48_swc_DIAG;        /* '<S413>/timed_debounce' */
  uint8 is_c47_swc_DIAG;               /* '<S410>/timed_debounce' */
  uint8 is_active_c47_swc_DIAG;        /* '<S410>/timed_debounce' */
  uint8 is_c46_swc_DIAG;               /* '<S407>/timed_debounce' */
  uint8 is_active_c46_swc_DIAG;        /* '<S407>/timed_debounce' */
  uint8 is_c45_swc_DIAG;               /* '<S404>/timed_debounce' */
  uint8 is_active_c45_swc_DIAG;        /* '<S404>/timed_debounce' */
  uint8 is_c44_swc_DIAG;               /* '<S401>/timed_debounce' */
  uint8 is_active_c44_swc_DIAG;        /* '<S401>/timed_debounce' */
  uint8 is_c13_swc_DIAG;               /* '<S327>/timed_debounce' */
  uint8 is_active_c13_swc_DIAG;        /* '<S327>/timed_debounce' */
  uint8 is_c43_swc_DIAG;               /* '<S325>/timed_debounce' */
  uint8 is_active_c43_swc_DIAG;        /* '<S325>/timed_debounce' */
  uint8 is_c42_swc_DIAG;               /* '<S323>/timed_debounce' */
  uint8 is_active_c42_swc_DIAG;        /* '<S323>/timed_debounce' */
  uint8 is_c41_swc_DIAG;               /* '<S321>/timed_debounce' */
  uint8 is_active_c41_swc_DIAG;        /* '<S321>/timed_debounce' */
  uint8 is_c17_swc_DIAG;               /* '<S319>/timed_debounce' */
  uint8 is_active_c17_swc_DIAG;        /* '<S319>/timed_debounce' */
  uint8 is_c11_swc_DIAG;               /* '<S317>/timed_debounce' */
  uint8 is_active_c11_swc_DIAG;        /* '<S317>/timed_debounce' */
  uint8 is_c40_swc_DIAG;               /* '<S315>/timed_debounce' */
  uint8 is_active_c40_swc_DIAG;        /* '<S315>/timed_debounce' */
  uint8 is_c39_swc_DIAG;               /* '<S313>/timed_debounce' */
  uint8 is_active_c39_swc_DIAG;        /* '<S313>/timed_debounce' */
  uint8 is_c61_swc_DIAG;               /* '<S311>/timed_debounce' */
  uint8 is_active_c61_swc_DIAG;        /* '<S311>/timed_debounce' */
  uint8 is_c9_swc_DIAG;                /* '<S309>/timed_debounce' */
  uint8 is_active_c9_swc_DIAG;         /* '<S309>/timed_debounce' */
  uint8 is_c38_swc_DIAG;               /* '<S307>/timed_debounce' */
  uint8 is_active_c38_swc_DIAG;        /* '<S307>/timed_debounce' */
  uint8 is_c37_swc_DIAG;               /* '<S305>/timed_debounce' */
  uint8 is_active_c37_swc_DIAG;        /* '<S305>/timed_debounce' */
  uint8 is_c36_swc_DIAG;               /* '<S303>/timed_debounce' */
  uint8 is_active_c36_swc_DIAG;        /* '<S303>/timed_debounce' */
  uint8 is_c10_swc_DIAG;               /* '<S301>/timed_debounce' */
  uint8 is_active_c10_swc_DIAG;        /* '<S301>/timed_debounce' */
  uint8 is_c35_swc_DIAG;               /* '<S299>/timed_debounce' */
  uint8 is_active_c35_swc_DIAG;        /* '<S299>/timed_debounce' */
  uint8 is_c34_swc_DIAG;               /* '<S297>/timed_debounce' */
  uint8 is_active_c34_swc_DIAG;        /* '<S297>/timed_debounce' */
  uint8 is_c33_swc_DIAG;               /* '<S295>/timed_debounce' */
  uint8 is_active_c33_swc_DIAG;        /* '<S295>/timed_debounce' */
  uint8 is_c32_swc_DIAG;               /* '<S227>/timed_debounce' */
  uint8 is_active_c32_swc_DIAG;        /* '<S227>/timed_debounce' */
  uint8 is_c31_swc_DIAG;               /* '<S223>/timed_debounce' */
  uint8 is_active_c31_swc_DIAG;        /* '<S223>/timed_debounce' */
  uint8 is_c30_swc_DIAG;               /* '<S220>/timed_debounce' */
  uint8 is_active_c30_swc_DIAG;        /* '<S220>/timed_debounce' */
  uint8 is_c29_swc_DIAG;               /* '<S218>/timed_debounce' */
  uint8 is_active_c29_swc_DIAG;        /* '<S218>/timed_debounce' */
  uint8 is_c28_swc_DIAG;               /* '<S191>/timed_debounce' */
  uint8 is_active_c28_swc_DIAG;        /* '<S191>/timed_debounce' */
  uint8 is_c27_swc_DIAG;               /* '<S189>/timed_debounce' */
  uint8 is_active_c27_swc_DIAG;        /* '<S189>/timed_debounce' */
  uint8 is_c22_swc_DIAG;               /* '<S175>/timed_debounce' */
  uint8 is_active_c22_swc_DIAG;        /* '<S175>/timed_debounce' */
  uint8 is_c24_swc_DIAG;               /* '<S117>/Chart1' */
  uint8 is_active_c24_swc_DIAG;        /* '<S117>/Chart1' */
  uint8 is_c4_swc_DIAG;                /* '<S137>/timed_debounce' */
  uint8 is_active_c4_swc_DIAG;         /* '<S137>/timed_debounce' */
  uint8 is_c3_swc_DIAG;                /* '<S135>/timed_debounce' */
  uint8 is_active_c3_swc_DIAG;         /* '<S135>/timed_debounce' */
  uint8 is_c6_swc_DIAG;                /* '<S133>/timed_debounce' */
  uint8 is_active_c6_swc_DIAG;         /* '<S133>/timed_debounce' */
  uint8 is_c5_swc_DIAG;                /* '<S131>/timed_debounce' */
  uint8 is_active_c5_swc_DIAG;         /* '<S131>/timed_debounce' */
  uint8 is_c1_swc_DIAG;                /* '<S129>/timed_debounce' */
  uint8 is_active_c1_swc_DIAG;         /* '<S129>/timed_debounce' */
  uint8 is_c2_swc_DIAG;                /* '<S127>/timed_debounce' */
  uint8 is_active_c2_swc_DIAG;         /* '<S127>/timed_debounce' */
  uint8 is_c12_swc_DIAG;               /* '<S125>/timed_debounce' */
  uint8 is_active_c12_swc_DIAG;        /* '<S125>/timed_debounce' */
  uint8 is_c26_swc_DIAG;               /* '<S80>/timed_debounce' */
  uint8 is_active_c26_swc_DIAG;        /* '<S80>/timed_debounce' */
  uint8 is_c57_swc_DIAG;               /* '<S77>/timed_debounce' */
  uint8 is_active_c57_swc_DIAG;        /* '<S77>/timed_debounce' */
  uint8 is_c25_swc_DIAG;               /* '<S76>/timed_debounce' */
  uint8 is_active_c25_swc_DIAG;        /* '<S76>/timed_debounce' */
  uint8 is_c58_swc_DIAG;               /* '<S73>/timed_debounce' */
  uint8 is_active_c58_swc_DIAG;        /* '<S73>/timed_debounce' */
  uint8 is_c23_swc_DIAG;               /* '<S72>/timed_debounce' */
  uint8 is_active_c23_swc_DIAG;        /* '<S72>/timed_debounce' */
  uint8 is_c59_swc_DIAG;               /* '<S69>/timed_debounce' */
  uint8 is_active_c59_swc_DIAG;        /* '<S69>/timed_debounce' */
  uint8 is_c21_swc_DIAG;               /* '<S68>/timed_debounce' */
  uint8 is_active_c21_swc_DIAG;        /* '<S68>/timed_debounce' */
  uint8 is_c60_swc_DIAG;               /* '<S65>/timed_debounce' */
  uint8 is_active_c60_swc_DIAG;        /* '<S65>/timed_debounce' */
  uint8 is_c20_swc_DIAG;               /* '<S64>/timed_debounce' */
  uint8 is_active_c20_swc_DIAG;        /* '<S64>/timed_debounce' */
  uint8 is_c7_swc_DIAG;                /* '<S61>/timed_debounce' */
  uint8 is_active_c7_swc_DIAG;         /* '<S61>/timed_debounce' */
  uint8 is_c15_swc_DIAG;               /* '<S60>/timed_debounce' */
  uint8 is_active_c15_swc_DIAG;        /* '<S60>/timed_debounce' */
  uint8 is_c8_swc_DIAG;                /* '<S57>/timed_debounce' */
  uint8 is_active_c8_swc_DIAG;         /* '<S57>/timed_debounce' */
  uint8 is_c19_swc_DIAG;               /* '<S56>/timed_debounce' */
  uint8 is_active_c19_swc_DIAG;        /* '<S56>/timed_debounce' */
  uint8 is_c14_swc_DIAG;               /* '<S53>/timed_debounce' */
  uint8 is_active_c14_swc_DIAG;        /* '<S53>/timed_debounce' */
  uint8 is_c18_swc_DIAG;               /* '<S52>/timed_debounce' */
  uint8 is_active_c18_swc_DIAG;        /* '<S52>/timed_debounce' */
  uint8 is_c56_swc_DIAG;               /* '<S49>/timed_debounce' */
  uint8 is_active_c56_swc_DIAG;        /* '<S49>/timed_debounce' */
  uint8 is_c16_swc_DIAG;               /* '<S48>/timed_debounce' */
  uint8 is_active_c16_swc_DIAG;        /* '<S48>/timed_debounce' */
  ZCSigState Subsystem_Trig_ZCE;       /* '<S170>/Subsystem' */
  ZCSigState Delay_Reset_ZCE;          /* '<S117>/Delay' */
  boolean DataTypeConversion254;       /* '<Root>/Data Type Conversion254' */
  boolean DataTypeConversion123;       /* '<Root>/Data Type Conversion123' */
  boolean DataTypeConversion14;        /* '<Root>/Data Type Conversion14' */
  boolean DataTypeConversion84;        /* '<Root>/Data Type Conversion84' */
  boolean DataTypeConversion4;         /* '<Root>/Data Type Conversion4' */
  boolean DataTypeConversion10;        /* '<Root>/Data Type Conversion10' */
  boolean DataTypeConversion12;        /* '<Root>/Data Type Conversion12' */
  boolean SignalConversion;            /* '<S1>/Signal Conversion' */
  boolean DataTypeConversion13;        /* '<Root>/Data Type Conversion13' */
  boolean DataTypeConversion82;        /* '<Root>/Data Type Conversion82' */
  boolean DataTypeConversion23;        /* '<Root>/Data Type Conversion23' */
  boolean OR1;                         /* '<S9>/OR1' */
  boolean DataTypeConversion93;        /* '<Root>/Data Type Conversion93' */
  boolean DataTypeConversion22;        /* '<Root>/Data Type Conversion22' */
  boolean DataTypeConversion16;        /* '<Root>/Data Type Conversion16' */
  boolean DataTypeConversion25;        /* '<Root>/Data Type Conversion25' */
  boolean DataTypeConversion27;        /* '<Root>/Data Type Conversion27' */
  boolean DataTypeConversion28;        /* '<Root>/Data Type Conversion28' */
  boolean DataTypeConversion30;        /* '<Root>/Data Type Conversion30' */
  boolean DataTypeConversion31;        /* '<Root>/Data Type Conversion31' */
  boolean flg_out;                     /* '<S374>/timed_delay' */
  boolean flg_out_c;                   /* '<S370>/timed_delay' */
  boolean flg_out_h;                   /* '<S368>/timed_delay' */
  boolean LogicalOperator;             /* '<S8>/Logical Operator' */
  boolean SignalConversion5;           /* '<S8>/Signal Conversion5' */
  boolean LogicalOperator3;            /* '<S276>/Logical Operator3' */
  boolean OutportBufferForflg_out;     /* '<S325>/timed_debounce' */
  boolean OutportBufferForflg_out_h;   /* '<S323>/timed_debounce' */
  boolean OutportBufferForflg_out_hs;  /* '<S319>/timed_debounce' */
  boolean OutportBufferForflg_out_hso; /* '<S317>/timed_debounce' */
  boolean OutportBufferForflg_out_hsoh;/* '<S227>/timed_debounce' */
  boolean OutportBufferForflg_out_hsoht;/* '<S223>/timed_debounce' */
  boolean OutportBufferForflg_out_hsohtg;/* '<S220>/timed_debounce' */
  boolean OutportBufferForflg_out_hsohtgi;/* '<S191>/timed_debounce' */
  boolean flg_out_p;                   /* '<S165>/timed_debounce' */
  boolean ClearEn;                     /* '<S117>/Chart1' */
  boolean OutportBufferForflg_ou_hsohtgiq;/* '<S125>/timed_debounce' */
  boolean UnitDelay_DSTATE;            /* '<S376>/Unit Delay' */
  boolean UnitDelay_DSTATE_g;          /* '<S377>/Unit Delay' */
  boolean UnitDelay_DSTATE_c;          /* '<S378>/Unit Delay' */
  boolean UnitDelay_DSTATE_a;          /* '<S379>/Unit Delay' */
  boolean UnitDelay_DSTATE_i;          /* '<S380>/Unit Delay' */
  boolean UnitDelay_DSTATE_p;          /* '<S381>/Unit Delay' */
  boolean UnitDelay_DSTATE_a3;         /* '<S382>/Unit Delay' */
  boolean UnitDelay_DSTATE_k;          /* '<S383>/Unit Delay' */
  boolean UnitDelay_DSTATE_n;          /* '<S384>/Unit Delay' */
  boolean UnitDelay_DSTATE_e;          /* '<S385>/Unit Delay' */
  boolean UnitDelay_DSTATE_d;          /* '<S386>/Unit Delay' */
  boolean UnitDelay_DSTATE_o;          /* '<S387>/Unit Delay' */
  boolean UnitDelay_DSTATE_d4;         /* '<S247>/Unit Delay' */
  boolean UnitDelay_DSTATE_iw;         /* '<S246>/Unit Delay' */
  boolean UnitDelay_DSTATE_da;         /* '<S241>/Unit Delay' */
  boolean UnitDelay_DSTATE_nj;         /* '<S237>/Unit Delay' */
  boolean UnitDelay_DSTATE_m;          /* '<S248>/Unit Delay' */
  boolean UnitDelay_DSTATE_cp;         /* '<S236>/Unit Delay' */
  boolean UnitDelay_DSTATE_h;          /* '<S239>/Unit Delay' */
  boolean UnitDelay_DSTATE_ov;         /* '<S244>/Unit Delay' */
  boolean UnitDelay_DSTATE_d2;         /* '<S249>/Unit Delay' */
  boolean UnitDelay_DSTATE_kq;         /* '<S250>/Unit Delay' */
  boolean UnitDelay_DSTATE_f;          /* '<S245>/Unit Delay' */
  boolean UnitDelay_DSTATE_mn;         /* '<S242>/Unit Delay' */
  boolean UnitDelay_DSTATE_l;          /* '<S243>/Unit Delay' */
  boolean UnitDelay_DSTATE_la;         /* '<S238>/Unit Delay' */
  boolean UnitDelay_DSTATE_ia;         /* '<S251>/Unit Delay' */
  boolean UnitDelay_DSTATE_dc;         /* '<S235>/Unit Delay' */
  boolean UnitDelay_DSTATE_cl;         /* '<S240>/Unit Delay' */
  boolean UnitDelay_DSTATE_m1;         /* '<S207>/Unit Delay' */
  boolean UnitDelay_DSTATE_mc;         /* '<S205>/Unit Delay' */
  boolean UnitDelay_DSTATE_nr;         /* '<S204>/Unit Delay' */
  boolean UnitDelay_DSTATE_ix;         /* '<S206>/Unit Delay' */
  boolean UnitDelay_DSTATE_j;          /* '<S180>/Unit Delay' */
  boolean UnitDelay_DSTATE_ms;         /* '<S179>/Unit Delay' */
  boolean UnitDelay_DSTATE_o5;         /* '<S170>/Unit Delay' */
  boolean DelayInput1_DSTATE_p;        /* '<S157>/Delay Input1' */
  boolean DelayInput1_DSTATE_a;        /* '<S155>/Delay Input1' */
  boolean DelayInput1_DSTATE_c;        /* '<S156>/Delay Input1' */
  boolean UnitDelay_DSTATE_pd;         /* '<S102>/Unit Delay' */
  boolean UnitDelay_DSTATE_h1;         /* '<S104>/Unit Delay' */
  boolean UnitDelay_DSTATE_lc;         /* '<S103>/Unit Delay' */
  boolean UnitDelay_DSTATE_dh;         /* '<S107>/Unit Delay' */
  boolean UnitDelay_DSTATE_i0;         /* '<S108>/Unit Delay' */
  boolean UnitDelay_DSTATE_fr;         /* '<S105>/Unit Delay' */
  boolean UnitDelay_DSTATE_eo;         /* '<S106>/Unit Delay' */
  boolean UnitDelay2_DSTATE;           /* '<S15>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_k;         /* '<S14>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_c;         /* '<S13>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_a;         /* '<S12>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_p;         /* '<S19>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_j;         /* '<S18>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_n;         /* '<S17>/Unit Delay2' */
  boolean UnitDelay2_DSTATE_cs;        /* '<S16>/Unit Delay2' */
  boolean UnitDelay_DSTATE_lab;        /* '<S20>/Unit Delay' */
  boolean UnitDelay1_DSTATE;           /* '<S12>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_f;         /* '<S13>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_p;         /* '<S14>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_n;         /* '<S15>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_o;         /* '<S16>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_j;         /* '<S17>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_i;         /* '<S18>/Unit Delay1' */
  boolean UnitDelay1_DSTATE_l;         /* '<S19>/Unit Delay1' */
  boolean debounce_MODE;               /* '<S387>/debounce' */
  boolean debounce_MODE_i;             /* '<S386>/debounce' */
  boolean debounce_MODE_a;             /* '<S385>/debounce' */
  boolean debounce_MODE_m;             /* '<S384>/debounce' */
  boolean debounce_MODE_o;             /* '<S383>/debounce' */
  boolean debounce_MODE_ig;            /* '<S382>/debounce' */
  boolean debounce_MODE_g;             /* '<S381>/debounce' */
  boolean debounce_MODE_n;             /* '<S380>/debounce' */
  boolean debounce_MODE_ns;            /* '<S379>/debounce' */
  boolean debounce_MODE_p;             /* '<S378>/debounce' */
  boolean debounce_MODE_po;            /* '<S377>/debounce' */
  boolean debounce_MODE_j;             /* '<S376>/debounce' */
  boolean debounce_MODE_aj;            /* '<S251>/debounce' */
  boolean debounce_MODE_c;             /* '<S250>/debounce' */
  boolean debounce_MODE_h;             /* '<S249>/debounce' */
  boolean debounce_MODE_l;             /* '<S248>/debounce' */
  boolean debounce_MODE_n4;            /* '<S247>/debounce' */
  boolean debounce_MODE_gg;            /* '<S246>/debounce' */
  boolean debounce_MODE_pa;            /* '<S245>/debounce' */
  boolean debounce_MODE_cj;            /* '<S244>/debounce' */
  boolean debounce_MODE_k;             /* '<S243>/debounce' */
  boolean debounce_MODE_j3;            /* '<S242>/debounce' */
  boolean debounce_MODE_b;             /* '<S241>/debounce' */
  boolean debounce_MODE_bk;            /* '<S240>/debounce' */
  boolean debounce_MODE_o1;            /* '<S239>/debounce' */
  boolean debounce_MODE_o3;            /* '<S238>/debounce' */
  boolean debounce_MODE_iq;            /* '<S237>/debounce' */
  boolean debounce_MODE_hl;            /* '<S236>/debounce' */
  boolean debounce_MODE_jr;            /* '<S235>/debounce' */
  boolean debounce_MODE_gu;            /* '<S207>/debounce' */
  boolean debounce_MODE_ka;            /* '<S206>/debounce' */
  boolean debounce_MODE_e;             /* '<S205>/debounce' */
  boolean debounce_MODE_jy;            /* '<S204>/debounce' */
  boolean debounce_MODE_b0;            /* '<S180>/debounce' */
  boolean debounce_MODE_b5;            /* '<S179>/debounce' */
  boolean debounce_MODE_ih;            /* '<S170>/debounce' */
  boolean debounce_MODE_av;            /* '<S108>/debounce' */
  boolean debounce_MODE_mr;            /* '<S107>/debounce' */
  boolean debounce_MODE_pt;            /* '<S106>/debounce' */
  boolean debounce_MODE_gv;            /* '<S105>/debounce' */
  boolean debounce_MODE_o5;            /* '<S104>/debounce' */
  boolean debounce_MODE_c0;            /* '<S103>/debounce' */
  boolean debounce_MODE_kx;            /* '<S102>/debounce' */
  boolean debounce_MODE_id;            /* '<S20>/debounce' */
  boolean debounce2_MODE;              /* '<S19>/debounce2' */
  boolean debounce1_MODE;              /* '<S19>/debounce1' */
  boolean debounce2_MODE_o;            /* '<S18>/debounce2' */
  boolean debounce1_MODE_b;            /* '<S18>/debounce1' */
  boolean debounce2_MODE_g;            /* '<S17>/debounce2' */
  boolean debounce1_MODE_h;            /* '<S17>/debounce1' */
  boolean debounce2_MODE_e;            /* '<S16>/debounce2' */
  boolean debounce1_MODE_f;            /* '<S16>/debounce1' */
  boolean debounce2_MODE_b;            /* '<S15>/debounce2' */
  boolean debounce1_MODE_o;            /* '<S15>/debounce1' */
  boolean debounce2_MODE_c;            /* '<S14>/debounce2' */
  boolean debounce1_MODE_p;            /* '<S14>/debounce1' */
  boolean debounce2_MODE_gv;           /* '<S13>/debounce2' */
  boolean debounce1_MODE_c;            /* '<S13>/debounce1' */
  boolean debounce2_MODE_p;            /* '<S12>/debounce2' */
  boolean debounce1_MODE_ps;           /* '<S12>/debounce1' */
} ARID_DEF_swc_DIAG_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_DIAG_T swc_DIAG_ARID_DEF;

/* Exported data declaration */
#define swc_DIAG_START_SEC_CONST_VOLATILE
#include "swc_DIAG_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile boolean acpc_b_acp1RngHiEnb_ovrdflg;
                        /* Referenced by: '<S21>/acpc_b_acp1RngHiEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal1ORHigh */
extern const volatile boolean acpc_b_acp1RngHiEnb_ovrdval;
                        /* Referenced by: '<S21>/acpc_b_acp1RngHiEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal1ORHigh */
extern const volatile float32 acpc_b_acp1RngHiFail_s;
                                      /* Referenced by: '<S11>/t_delay_fail3' */

/* DFC_HYB_ACCPedal1ORHigh fault set threshold */
extern const volatile float32 acpc_b_acp1RngHiHeal_s;
                                      /* Referenced by: '<S11>/t_delay_heal3' */

/* DFC_HYB_ACCPedal1ORHigh fault clear threshold */
extern const volatile boolean acpc_b_acp1RngHiSet_ovrdflg;
                        /* Referenced by: '<S22>/acpc_b_acp1RngHiSet_ovrdflg' */

/* Override flag for signal acpd_b_acp1RngHiSet */
extern const volatile boolean acpc_b_acp1RngHiSet_ovrdval;
                        /* Referenced by: '<S22>/acpc_b_acp1RngHiSet_ovrdval' */

/* Override value for signal acpd_b_acp1RngHiSet */
extern const volatile boolean acpc_b_acp1RngLowEnb_ovrdflg;
                       /* Referenced by: '<S23>/acpc_b_acp1RngLowEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal1ORLow */
extern const volatile boolean acpc_b_acp1RngLowEnb_ovrdval;
                       /* Referenced by: '<S23>/acpc_b_acp1RngLowEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal1ORLow */
extern const volatile float32 acpc_b_acp1RngLowFail_s;
                                      /* Referenced by: '<S11>/t_delay_fail2' */

/* DFC_HYB_ACCPedal1ORLow fault set threshold */
extern const volatile float32 acpc_b_acp1RngLowHeal_s;
                                      /* Referenced by: '<S11>/t_delay_heal2' */

/* DFC_HYB_ACCPedal1ORLow fault clear threshold */
extern const volatile boolean acpc_b_acp1RngLowSet_ovrdflg;
                       /* Referenced by: '<S24>/acpc_b_acp1RngLowSet_ovrdflg' */

/* Override flag for signal acpd_b_acp1RngLowSet */
extern const volatile boolean acpc_b_acp1RngLowSet_ovrdval;
                       /* Referenced by: '<S24>/acpc_b_acp1RngLowSet_ovrdval' */

/* Override value for signal acpd_b_acp1RngLowSet */
extern const volatile boolean acpc_b_acp1Sho2BatEnb_ovrdflg;
                      /* Referenced by: '<S25>/acpc_b_acp1Sho2BatEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal1SCB */
extern const volatile boolean acpc_b_acp1Sho2BatEnb_ovrdval;
                      /* Referenced by: '<S25>/acpc_b_acp1Sho2BatEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal1SCB */
extern const volatile float32 acpc_b_acp1Sho2BatFail_s;
                                      /* Referenced by: '<S11>/t_delay_fail1' */

/* DFC_HYB_ACCPedal1SCB fault set threshold */
extern const volatile float32 acpc_b_acp1Sho2BatHeal_s;
                                      /* Referenced by: '<S11>/t_delay_heal1' */

/* DFC_HYB_ACCPedal1SCB fault clear threshold */
extern const volatile boolean acpc_b_acp1Sho2BatSet_ovrdflg;
                      /* Referenced by: '<S26>/acpc_b_acp1Sho2BatSet_ovrdflg' */

/* Override flag for signal acpd_b_acp1Sho2BatSet */
extern const volatile boolean acpc_b_acp1Sho2BatSet_ovrdval;
                      /* Referenced by: '<S26>/acpc_b_acp1Sho2BatSet_ovrdval' */

/* Override value for signal acpd_b_acp1Sho2BatSet */
extern const volatile boolean acpc_b_acp1Sho2GndEnb_ovrdflg;
                      /* Referenced by: '<S27>/acpc_b_acp1Sho2GndEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal1SCG */
extern const volatile boolean acpc_b_acp1Sho2GndEnb_ovrdval;
                      /* Referenced by: '<S27>/acpc_b_acp1Sho2GndEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal1SCG */
extern const volatile float32 acpc_b_acp1Sho2GndFail_s;/* Referenced by: '<S11>/t_delay_fail' */

/* DFC_HYB_ACCPedal1SCG fault set threshold */
extern const volatile float32 acpc_b_acp1Sho2GndHeal_s;/* Referenced by: '<S11>/t_delay_heal' */

/* DFC_HYB_ACCPedal1SCG fault clear threshold */
extern const volatile boolean acpc_b_acp1Sho2GndSet_ovrdflg;
                      /* Referenced by: '<S28>/acpc_b_acp1Sho2GndSet_ovrdflg' */

/* Override flag for signal acpd_b_acp1Sho2GndSet */
extern const volatile boolean acpc_b_acp1Sho2GndSet_ovrdval;
                      /* Referenced by: '<S28>/acpc_b_acp1Sho2GndSet_ovrdval' */

/* Override value for signal acpd_b_acp1Sho2GndSet */
extern const volatile boolean acpc_b_acp2RngHiEnb_ovrdflg;
                        /* Referenced by: '<S29>/acpc_b_acp2RngHiEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal2ORHigh */
extern const volatile boolean acpc_b_acp2RngHiEnb_ovrdval;
                        /* Referenced by: '<S29>/acpc_b_acp2RngHiEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal2ORHigh */
extern const volatile float32 acpc_b_acp2RngHiFail_s;
                                      /* Referenced by: '<S11>/t_delay_fail7' */

/* DFC_HYB_ACCPedal2ORHigh fault set threshold */
extern const volatile float32 acpc_b_acp2RngHiHeal_s;
                                      /* Referenced by: '<S11>/t_delay_heal7' */

/* DFC_HYB_ACCPedal2ORHigh fault clear threshold */
extern const volatile boolean acpc_b_acp2RngHiSet_ovrdflg;
                        /* Referenced by: '<S30>/acpc_b_acp2RngHiSet_ovrdflg' */

/* Override flag for signal acpd_b_acp2RngHiSet */
extern const volatile boolean acpc_b_acp2RngHiSet_ovrdval;
                        /* Referenced by: '<S30>/acpc_b_acp2RngHiSet_ovrdval' */

/* Override value for signal acpd_b_acp2RngHiSet */
extern const volatile boolean acpc_b_acp2RngLowEnb_ovrdflg;
                       /* Referenced by: '<S31>/acpc_b_acp2RngLowEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal2ORLow */
extern const volatile boolean acpc_b_acp2RngLowEnb_ovrdval;
                       /* Referenced by: '<S31>/acpc_b_acp2RngLowEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal2ORLow */
extern const volatile float32 acpc_b_acp2RngLowFail_s;
                                      /* Referenced by: '<S11>/t_delay_fail6' */

/* DFC_HYB_ACCPedal2ORLow fault set threshold */
extern const volatile float32 acpc_b_acp2RngLowHeal_s;
                                      /* Referenced by: '<S11>/t_delay_heal6' */

/* DFC_HYB_ACCPedal2ORLow fault clear threshold */
extern const volatile boolean acpc_b_acp2RngLowSet_ovrdflg;
                       /* Referenced by: '<S32>/acpc_b_acp2RngLowSet_ovrdflg' */

/* Override flag for signal acpd_b_acp2RngLowSet */
extern const volatile boolean acpc_b_acp2RngLowSet_ovrdval;
                       /* Referenced by: '<S32>/acpc_b_acp2RngLowSet_ovrdval' */

/* Override value for signal acpd_b_acp2RngLowSet */
extern const volatile boolean acpc_b_acp2Sho2BatEnb_ovrdflg;
                      /* Referenced by: '<S33>/acpc_b_acp2Sho2BatEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal2SCB */
extern const volatile boolean acpc_b_acp2Sho2BatEnb_ovrdval;
                      /* Referenced by: '<S33>/acpc_b_acp2Sho2BatEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal2SCB */
extern const volatile float32 acpc_b_acp2Sho2BatFail_s;
                                      /* Referenced by: '<S11>/t_delay_fail5' */

/* DFC_HYB_ACCPedal2SCB fault set threshold */
extern const volatile float32 acpc_b_acp2Sho2BatHeal_s;
                                      /* Referenced by: '<S11>/t_delay_heal5' */

/* DFC_HYB_ACCPedal2SCB fault clear threshold */
extern const volatile boolean acpc_b_acp2Sho2BatSet_ovrdflg;
                      /* Referenced by: '<S34>/acpc_b_acp2Sho2BatSet_ovrdflg' */

/* Override flag for signal acpd_b_acp2Sho2BatSet */
extern const volatile boolean acpc_b_acp2Sho2BatSet_ovrdval;
                      /* Referenced by: '<S34>/acpc_b_acp2Sho2BatSet_ovrdval' */

/* Override value for signal acpd_b_acp2Sho2BatSet */
extern const volatile boolean acpc_b_acp2Sho2GndEnb_ovrdflg;
                      /* Referenced by: '<S35>/acpc_b_acp2Sho2GndEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedal2SCG */
extern const volatile boolean acpc_b_acp2Sho2GndEnb_ovrdval;
                      /* Referenced by: '<S35>/acpc_b_acp2Sho2GndEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedal2SCG */
extern const volatile float32 acpc_b_acp2Sho2GndFail_s;
                                      /* Referenced by: '<S11>/t_delay_fail4' */

/* DFC_HYB_ACCPedal2SCG fault set threshold */
extern const volatile float32 acpc_b_acp2Sho2GndHeal_s;
                                      /* Referenced by: '<S11>/t_delay_heal4' */

/* DFC_HYB_ACCPedal2SCG fault clear threshold */
extern const volatile boolean acpc_b_acp2Sho2GndSet_ovrdflg;
                      /* Referenced by: '<S36>/acpc_b_acp2Sho2GndSet_ovrdflg' */

/* Override flag for signal acpd_b_acp2Sho2GndSet */
extern const volatile boolean acpc_b_acp2Sho2GndSet_ovrdval;
                      /* Referenced by: '<S36>/acpc_b_acp2Sho2GndSet_ovrdval' */

/* Override value for signal acpd_b_acp2Sho2GndSet */
extern const volatile boolean acpc_b_acpCrsFltEnb_ovrdflg;
                        /* Referenced by: '<S37>/acpc_b_acpCrsFltEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_ACCPedalCrossNP */
extern const volatile boolean acpc_b_acpCrsFltEnb_ovrdval;
                        /* Referenced by: '<S37>/acpc_b_acpCrsFltEnb_ovrdval' */

/* Override value to enable DFC_HYB_ACCPedalCrossNP */
extern const volatile boolean acpc_b_acpCrsFltSet_ovrdflg;
                        /* Referenced by: '<S38>/acpc_b_acpCrsFltSet_ovrdflg' */

/* Override flag for signal acpd_b_acpCrsFltSet */
extern const volatile boolean acpc_b_acpCrsFltSet_ovrdval;
                        /* Referenced by: '<S38>/acpc_b_acpCrsFltSet_ovrdval' */

/* Override value for signal acpd_b_acpCrsFltSet */
extern const volatile boolean brpc_b_VacPumpEnOvrTmHiPreFltSet_ovrdflg;
                /* Referenced by: '<S111>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
extern const volatile boolean brpc_b_VacPumpEnOvrTmHiPreFltSet_ovrdval;
                /* Referenced by: '<S111>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
extern const volatile boolean brpc_b_VacPumpEnOvrTmLoPreFltSet_ovrdflg;
                /* Referenced by: '<S112>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
extern const volatile boolean brpc_b_VacPumpEnOvrTmLoPreFltSet_ovrdval;
                /* Referenced by: '<S112>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
extern const volatile boolean brpc_b_VacPumpLoPreFltSet_ovrdflg;
                /* Referenced by: '<S113>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
extern const volatile boolean brpc_b_VacPumpLoPreFltSet_ovrdval;
                /* Referenced by: '<S113>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
extern const volatile boolean brpc_b_VacPumpRlyFltSet_ovrdflg;
                /* Referenced by: '<S114>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
extern const volatile boolean brpc_b_VacPumpRlyFltSet_ovrdval;
                /* Referenced by: '<S114>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
extern const volatile boolean brpc_b_VacPumpSnrFltSet_ovrdflg;
                /* Referenced by: '<S115>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
extern const volatile boolean brpc_b_VacPumpSnrFltSet_ovrdval;
                /* Referenced by: '<S115>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
extern const volatile boolean brpc_b_VacPumpSysFailFltSet_ovrdflg;
                /* Referenced by: '<S116>/brpc_b_BdcacOpTmLongFltSet_ovrdflg' */
extern const volatile boolean brpc_b_VacPumpSysFailFltSet_ovrdval;
                /* Referenced by: '<S116>/brpc_b_BdcacOpTmLongFltSet_ovrdval' */
extern const volatile boolean brpc_b_brkSwtMismatchEnb_ovrdflg;
                  /* Referenced by: '<S109>/brpc_b_brkSwtMismatchEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_BrkSthNP */
extern const volatile boolean brpc_b_brkSwtMismatchEnb_ovrdval;
                  /* Referenced by: '<S109>/brpc_b_brkSwtMismatchEnb_ovrdval' */

/* Override value to enable DFC_HYB_BrkSthNP */
extern const volatile float32 brpc_b_brkSwtMismatchHeal_s;
                                     /* Referenced by: '<S159>/t_delay_heal3' */

/* DFC_HYB_BrkSthNP fault clear threshold */
extern const volatile boolean brpc_b_brkSwtMismatchSet_ovrdflg;
                  /* Referenced by: '<S110>/brpc_b_brkSwtMismatchSet_ovrdflg' */

/* Override flag for signal brpd_b_brkSwtMismatchSet */
extern const volatile boolean brpc_b_brkSwtMismatchSet_ovrdval;
                  /* Referenced by: '<S110>/brpc_b_brkSwtMismatchSet_ovrdval' */

/* Override value for signal brpd_b_brkSwtMismatchSet */
extern const volatile boolean cesc_b_crashEventEnb_ovrdflg;
                      /* Referenced by: '<S171>/cesc_b_crashEventEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_CrashEvent */
extern const volatile boolean cesc_b_crashEventEnb_ovrdval;
                      /* Referenced by: '<S171>/cesc_b_crashEventEnb_ovrdval' */

/* Override value to enable DFC_HYB_CrashEvent */
extern const volatile boolean cesc_b_crashEventSet_ovrdflg;
                      /* Referenced by: '<S172>/cesc_b_crashEventSet_ovrdflg' */

/* Override flag for signal cesd_b_crashEventSet */
extern const volatile boolean cesc_b_crashEventSet_ovrdval;
                      /* Referenced by: '<S172>/cesc_b_crashEventSet_ovrdval' */

/* Override value for signal cesd_b_crashEventSet */
extern const volatile boolean ddic_b_forceDisDTCFcnCall;
                                     /* Referenced by: '<S206>/t_delay_heal2' */
extern const volatile float32 digc_ABSMsgErr2fail_s;/* Referenced by: '<S8>/Constant156' */

/* macc_ABSMsgErr2fail_s fault set threshold */
extern const volatile float32 digc_ABSMsgErr2heal_s;/* Referenced by: '<S8>/Constant157' */

/* macc_ABSMsgErr2heal_s fault clear threshold */
extern const volatile float32 digc_ABSSpdMsgErr2fail_s;/* Referenced by: '<S8>/Constant223' */

/* macc_ABSSpdMsgErr2fail_s fault set threshold */
extern const volatile float32 digc_ABSSpdMsgErr2heal_s;/* Referenced by: '<S8>/Constant224' */

/* macc_ABSSpdMsgErr2heal_s fault clear threshold */
extern const volatile float32 digc_ACUMsgErrfail_s;/* Referenced by: '<S8>/Constant15' */
extern const volatile float32 digc_ACUMsgErrheal_s;/* Referenced by: '<S8>/Constant16' */
extern const volatile float32 digc_BMSHealthMonErrfail_s;/* Referenced by: '<S8>/Constant18' */
extern const volatile float32 digc_BMSHealthMonErrheal_s;/* Referenced by: '<S8>/Constant19' */
extern const volatile float32 digc_CSMMsgErrfail_s;/* Referenced by: '<S8>/Constant24' */
extern const volatile float32 digc_CSMMsgErrheal_s;/* Referenced by: '<S8>/Constant25' */
extern const volatile float32 digc_DCDCMsgErr2fail_s;/* Referenced by: '<S8>/Constant175' */

/* macc_DCDCMsgErr2fail_s fault set threshold */
extern const volatile float32 digc_DCDCMsgErr2heal_s;/* Referenced by: '<S8>/Constant176' */

/* macc_DCDCMsgErr2heal_s fault clear threshold */
extern const volatile float32 digc_EGSMMsgErr2fail_s;/* Referenced by: '<S8>/Constant189' */

/* macc_EGSMMsgErr2fail_s fault set threshold */
extern const volatile float32 digc_EGSMMsgErr2heal_s;/* Referenced by: '<S8>/Constant192' */

/* macc_EGSMMsgErr2heal_s fault clear threshold */
extern const volatile float32 digc_MCUHealthMonErrfail_s;/* Referenced by: '<S8>/Constant21' */
extern const volatile float32 digc_MCUHealthMonErrheal_s;/* Referenced by: '<S8>/Constant22' */
extern const volatile float32 digc_PEPSMsgErr2fail_s;/* Referenced by: '<S8>/Constant2' */

/* macc_PEPSMsgErr2fail_s fault set threshold */
extern const volatile float32 digc_PEPSMsgErr2heal_s;/* Referenced by: '<S8>/Constant3' */

/* macc_PEPSMsgErr2heal_s fault clear threshold */
extern const volatile float32 digc_b_acpCrsFltFail_s;
                                      /* Referenced by: '<S11>/t_delay_fail8' */
extern const volatile float32 digc_b_acpCrsFltHeal_s;
                                      /* Referenced by: '<S11>/t_delay_heal8' */
extern const volatile float32 digc_b_batIntSmplHiFail_s;/* Referenced by: '<S8>/t_delay_fail1' */
extern const volatile float32 digc_b_batIntSmplLoFail_s;/* Referenced by: '<S8>/t_delay_fail' */
extern const volatile float32 digc_b_brkSwtMismatchFail_s;/* Referenced by:
                                                           * '<S117>/t_delay_fail1'
                                                           * '<S159>/t_delay_fail3'
                                                           */
extern const volatile float32 digc_b_crashEventFail_s;/* Referenced by: '<S4>/t_delay_fail' */
extern const volatile float32 digc_b_crashEventHeal_s;/* Referenced by: '<S4>/t_delay_heal' */
extern const volatile boolean digc_b_edcpBlock_ovrdflg;
                  /* Referenced by: '<S395>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_edcpBlock_ovrdval;
                  /* Referenced by: '<S395>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_edcpIdly_ovrdflg;
                  /* Referenced by: '<S392>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_edcpIdly_ovrdval;
                  /* Referenced by: '<S392>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_edcpOvrCurr_ovrdflg;
                  /* Referenced by: '<S396>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_edcpOvrCurr_ovrdval;
                  /* Referenced by: '<S396>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_edcpOvrTmp_ovrdflg;
                  /* Referenced by: '<S388>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_edcpOvrTmp_ovrdval;
                  /* Referenced by: '<S388>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_edcpOvrVolt_ovrdflg;
                  /* Referenced by: '<S394>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_edcpOvrVolt_ovrdval;
                  /* Referenced by: '<S394>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_edcpUdVolt_ovrdflg;
                  /* Referenced by: '<S393>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_edcpUdVolt_ovrdval;
                  /* Referenced by: '<S393>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_evtFaildBMSFaultLevel4A_ovrdflg;/* Referenced by: '<S7>/DFC_ovrdflg' */
extern const volatile boolean digc_b_evtFaildBMSFaultLevel4A_ovrdval;/* Referenced by: '<S7>/DFC_ovrdval' */
extern const volatile boolean digc_b_evtFaildCrashEvent_ovrdflg;/* Referenced by: '<S4>/DFC_ovrdflg' */
extern const volatile boolean digc_b_evtFaildCrashEvent_ovrdval;/* Referenced by: '<S4>/DFC_ovrdval' */
extern const volatile boolean digc_b_hbcpBlock_ovrdflg;
                  /* Referenced by: '<S390>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_hbcpBlock_ovrdval;
                  /* Referenced by: '<S390>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_hbcpIdly_ovrdflg;
                  /* Referenced by: '<S398>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_hbcpIdly_ovrdval;
                  /* Referenced by: '<S398>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_hbcpOvrCurr_ovrdflg;
                  /* Referenced by: '<S391>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_hbcpOvrCurr_ovrdval;
                  /* Referenced by: '<S391>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_hbcpOvrTmp_ovrdflg;
                  /* Referenced by: '<S397>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_hbcpOvrTmp_ovrdval;
                  /* Referenced by: '<S397>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_hbcpOvrVolt_ovrdflg;
                  /* Referenced by: '<S389>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_hbcpOvrVolt_ovrdval;
                  /* Referenced by: '<S389>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile boolean digc_b_hbcpUdVolt_ovrdflg;
                  /* Referenced by: '<S399>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */
extern const volatile boolean digc_b_hbcpUdVolt_ovrdval;
                  /* Referenced by: '<S399>/macc_b_5VT1IntSmplFltEnb_ovrdval' */
extern const volatile float32 digc_cCanBusOfffail_s;/* Referenced by: '<S8>/Constant170' */
extern const volatile float32 digc_cCanBusOffheal_s;/* Referenced by: '<S8>/Constant174' */
extern const volatile float32 digc_evCanBusOfffail_s;/* Referenced by:
                                                      * '<S8>/Constant1'
                                                      * '<S8>/Constant243'
                                                      */
extern const volatile float32 digc_evCanBusOffheal_s;/* Referenced by:
                                                      * '<S8>/Constant244'
                                                      * '<S8>/Constant5'
                                                      */
extern const volatile float32 digc_ptCanBusOfffail_s;/* Referenced by: '<S8>/Constant188' */
extern const volatile float32 digc_ptCanBusOffheal_s;/* Referenced by: '<S8>/Constant194' */
extern const volatile float32 digc_tm_brkStsOffDly_s;
                                     /* Referenced by: '<S117>/t_delay_heal3' */
extern const volatile float32 digc_tm_brkStsOpenDly_s;
                                     /* Referenced by: '<S117>/t_delay_heal2' */
extern const volatile float32 digc_u_acp1RngHiSet_V;/* Referenced by: '<S11>/Constant12' */

/* Accel pedal 1 range high fault set threshold */
extern const volatile float32 digc_u_acp1RngLowSet_V;/* Referenced by: '<S11>/Constant28' */

/* Accel pedal 1 range low fault set threshold */
extern const volatile float32 digc_u_acp1Sho2BatSet_V;/* Referenced by: '<S11>/Constant8' */

/* Accel pedal 1 short to 12V battery fault set */
extern const volatile float32 digc_u_acp1Sho2GndSet_V;/* Referenced by: '<S11>/Constant' */

/* Accel pedal 1 short to ground fault set */
extern const volatile float32 digc_u_acp2RngHiSet_V;/* Referenced by: '<S11>/Constant19' */

/* Accel pedal 2 range high fault set threshold */
extern const volatile float32 digc_u_acp2RngLowSet_V;/* Referenced by: '<S11>/Constant32' */

/* Accel pedal 2 range low fault set threshold */
extern const volatile float32 digc_u_acp2Sho2BatSet_V;/* Referenced by: '<S11>/Constant26' */

/* Accel pedal 2 short to 12V battery fault set threshold */
extern const volatile float32 digc_u_acp2Sho2GndSet_V;/* Referenced by: '<S11>/Constant16' */

/* Accel pedal 2 short to ground fault set threshold */
extern const volatile float32 digc_u_acpCrsFltSet_V;/* Referenced by: '<S11>/Constant36' */

/* Accel pedal cross fault set threshold */
extern const volatile boolean digd_b_VehLvl1Flt_ovrdflg;/* Referenced by: '<S197>/Constant5' */

/* Override flag for digd_b_VehLvl1Flt */
extern const volatile boolean digd_b_VehLvl1Flt_ovrdval;/* Referenced by: '<S197>/Constant6' */

/* Override value for digd_b_VehLvl1Flt */
extern const volatile boolean digd_b_VehLvl21Flt_ovrdflg;/* Referenced by: '<S198>/Constant2' */

/* Override flag for digd_b_VehLvl21Flt */
extern const volatile boolean digd_b_VehLvl21Flt_ovrdval;/* Referenced by: '<S198>/Constant3' */

/* Override value for digd_b_VehLvl21Flt */
extern const volatile boolean digd_b_VehLvl22Flt_ovrdflg;/* Referenced by: '<S199>/Constant16' */

/* Override flag for digd_b_VehLvl21Flt */
extern const volatile boolean digd_b_VehLvl22Flt_ovrdval;/* Referenced by: '<S199>/Constant17' */

/* Override value for digd_b_VehLvl21Flt */
extern const volatile boolean digd_b_VehLvl23Flt_ovrdflg;/* Referenced by: '<S200>/Constant18' */

/* Override flag for digd_b_VehLvl21Flt */
extern const volatile boolean digd_b_VehLvl23Flt_ovrdval;/* Referenced by: '<S200>/Constant19' */

/* Override value for digd_b_VehLvl21Flt */
extern const volatile boolean digd_b_VehLvl31Flt_ovrdflg;/* Referenced by: '<S201>/Constant7' */

/* Override flag for digd_b_VehLvl31Flt */
extern const volatile boolean digd_b_VehLvl31Flt_ovrdval;/* Referenced by: '<S201>/Constant8' */

/* Override value for digd_b_VehLvl31Flt */
extern const volatile boolean digd_b_VehLvl32Flt_ovrdflg;/* Referenced by: '<S202>/Constant9' */

/* Override flag for digd_b_VehLvl32Flt */
extern const volatile boolean digd_b_VehLvl32Flt_ovrdval;/* Referenced by: '<S202>/Constant10' */

/* Override value for digd_b_VehLvl32Flt */
extern const volatile boolean digd_b_VehLvl33Flt_ovrdflg;/* Referenced by: '<S203>/Constant2' */

/* Override flag for digd_b_VehLvl33Flt */
extern const volatile boolean digd_b_VehLvl33Flt_ovrdval;/* Referenced by: '<S203>/Constant12' */

/* Override value for digd_b_VehLvl33Flt */
extern const volatile boolean hvbc_b_BMSFaultLevel2ASet_ovrdflg;
                      /* Referenced by: '<S210>/hvbc_b_vehHvilFltSet_ovrdflg' */
extern const volatile boolean hvbc_b_BMSFaultLevel2ASet_ovrdval;
                      /* Referenced by: '<S210>/hvbc_b_vehHvilFltSet_ovrdval' */
extern const volatile boolean hvbc_b_BMSFaultLevel3ASet_ovrdflg;
                      /* Referenced by: '<S211>/hvbc_b_vehHvilFltSet_ovrdflg' */
extern const volatile boolean hvbc_b_BMSFaultLevel3ASet_ovrdval;
                      /* Referenced by: '<S211>/hvbc_b_vehHvilFltSet_ovrdval' */
extern const volatile boolean hvbc_b_BMSFaultLevel4ASet_ovrdflg;
                      /* Referenced by: '<S212>/hvbc_b_vehHvilFltSet_ovrdflg' */
extern const volatile boolean hvbc_b_BMSFaultLevel4ASet_ovrdval;
                      /* Referenced by: '<S212>/hvbc_b_vehHvilFltSet_ovrdval' */
extern const volatile boolean hvbc_b_MCUFaultLevel2ASet_ovrdflg;
                      /* Referenced by: '<S184>/hvbc_b_vehHvilFltSet_ovrdflg' */
extern const volatile boolean hvbc_b_MCUFaultLevel2ASet_ovrdval;
                      /* Referenced by: '<S184>/hvbc_b_vehHvilFltSet_ovrdval' */
extern const volatile boolean hvbc_b_MCUFaultLevel3ASet_ovrdflg;
                      /* Referenced by: '<S185>/hvbc_b_vehHvilFltSet_ovrdflg' */
extern const volatile boolean hvbc_b_MCUFaultLevel3ASet_ovrdval;
                      /* Referenced by: '<S185>/hvbc_b_vehHvilFltSet_ovrdval' */
extern const volatile float32 hvbc_b_vehHvilFltFail_s;/* Referenced by: '<S7>/t_delay_fail7' */

/* DFC_HYB_VehicleHVILFlt fault set threshold */
extern const volatile float32 hvbc_b_vehHvilFltHeal_s;/* Referenced by: '<S7>/t_delay_heal7' */

/* DFC_HYB_VehicleHVILFlt fault clear threshold */
extern const volatile boolean hvbc_b_vehHvilFltSet_ovrdflg;
                      /* Referenced by: '<S209>/hvbc_b_vehHvilFltSet_ovrdflg' */

/* Override flag for signal hvbd_b_vehHvilFltSet */
extern const volatile boolean hvbc_b_vehHvilFltSet_ovrdval;
                      /* Referenced by: '<S209>/hvbc_b_vehHvilFltSet_ovrdval' */

/* Override value for signal hvbd_b_vehHvilFltSet */
extern const volatile boolean macc_b_5VT1IntSmplFltEnb_ovrdflg;
                  /* Referenced by: '<S259>/macc_b_5VT1IntSmplFltEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_T5V1Mon */
extern const volatile boolean macc_b_5VT1IntSmplFltEnb_ovrdval;
                  /* Referenced by: '<S259>/macc_b_5VT1IntSmplFltEnb_ovrdval' */

/* Override value to enable DFC_HYB_T5V1Mon */
extern const volatile float32 macc_b_5VT1IntSmplFltFail_s;/* Referenced by: '<S8>/t_delay_fail2' */

/* DFC_HYB_T5V1Mon fault set threshold */
extern const volatile float32 macc_b_5VT1IntSmplFltHeal_s;/* Referenced by: '<S8>/t_delay_heal2' */

/* DFC_HYB_T5V1Mon fault clear threshold */
extern const volatile boolean macc_b_5VT1IntSmplFltSet_ovrdflg;
                  /* Referenced by: '<S260>/macc_b_5VT1IntSmplFltSet_ovrdflg' */

/* Override flag for signal macd_b_5VT1IntSmplFltSet */
extern const volatile boolean macc_b_5VT1IntSmplFltSet_ovrdval;
                  /* Referenced by: '<S260>/macc_b_5VT1IntSmplFltSet_ovrdval' */

/* Override value for signal macd_b_5VT1IntSmplFltSet */
extern const volatile boolean macc_b_5VT2IntSmplFltEnb_ovrdflg;
                  /* Referenced by: '<S261>/macc_b_5VT2IntSmplFltEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_T5V2Mon */
extern const volatile boolean macc_b_5VT2IntSmplFltEnb_ovrdval;
                  /* Referenced by: '<S261>/macc_b_5VT2IntSmplFltEnb_ovrdval' */

/* Override value to enable DFC_HYB_T5V2Mon */
extern const volatile float32 macc_b_5VT2IntSmplFltFail_s;/* Referenced by: '<S8>/t_delay_fail3' */

/* DFC_HYB_T5V2Mon fault set threshold */
extern const volatile float32 macc_b_5VT2IntSmplFltHeal_s;/* Referenced by: '<S8>/t_delay_heal3' */

/* DFC_HYB_T5V2Mon fault clear threshold */
extern const volatile boolean macc_b_5VT2IntSmplFltSet_ovrdflg;
                  /* Referenced by: '<S262>/macc_b_5VT2IntSmplFltSet_ovrdflg' */

/* Override flag for signal macd_b_5VT2IntSmplFltSet */
extern const volatile boolean macc_b_5VT2IntSmplFltSet_ovrdval;
                  /* Referenced by: '<S262>/macc_b_5VT2IntSmplFltSet_ovrdval' */

/* Override value for signal macd_b_5VT2IntSmplFltSet */
extern const volatile boolean macc_b_ABSMsgErrSet_ovrdflg;
                    /* Referenced by: '<S273>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_ABSMsgErrSet_ovrdval;
                    /* Referenced by: '<S273>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_ABSSpdMsgErrSet_ovrdflg;
                    /* Referenced by: '<S264>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_ABSSpdMsgErrSet_ovrdval;
                    /* Referenced by: '<S264>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_ACUMsgErrSet_ovrdflg;
                    /* Referenced by: '<S266>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_ACUMsgErrSet_ovrdval;
                    /* Referenced by: '<S266>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_BMSHealthMonErrSet_ovrdflg;
                    /* Referenced by: '<S267>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_BMSHealthMonErrSet_ovrdval;
                    /* Referenced by: '<S267>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_CSMMsgErrSet_ovrdflg;
                    /* Referenced by: '<S269>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_CSMMsgErrSet_ovrdval;
                    /* Referenced by: '<S269>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_DCDCMsgErrSet_ovrdflg;
                    /* Referenced by: '<S274>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_DCDCMsgErrSet_ovrdval;
                    /* Referenced by: '<S274>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_EGSMMsgErrSet_ovrdflg;
                    /* Referenced by: '<S275>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_EGSMMsgErrSet_ovrdval;
                    /* Referenced by: '<S275>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_MCUHealthMonErrSet_ovrdflg;
                    /* Referenced by: '<S268>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_MCUHealthMonErrSet_ovrdval;
                    /* Referenced by: '<S268>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_PEPSMsgErrSet_ovrdflg;
                    /* Referenced by: '<S265>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_PEPSMsgErrSet_ovrdval;
                    /* Referenced by: '<S265>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_batIntSmplHiEnb_ovrdflg;
                    /* Referenced by: '<S255>/macc_b_batIntSmplHiEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_PwrSuplyORHigh */
extern const volatile boolean macc_b_batIntSmplHiEnb_ovrdval;
                    /* Referenced by: '<S255>/macc_b_batIntSmplHiEnb_ovrdval' */

/* Override value to enable DFC_HYB_PwrSuplyORHigh */
extern const volatile float32 macc_b_batIntSmplHiHeal_s;/* Referenced by: '<S8>/t_delay_heal1' */

/* DFC_HYB_PwrSuplyORHigh fault clear threshold */
extern const volatile boolean macc_b_batIntSmplHiSet_ovrdflg;
                    /* Referenced by: '<S256>/macc_b_batIntSmplHiSet_ovrdflg' */

/* Override flag for signal macd_b_batIntSmplHiSet */
extern const volatile boolean macc_b_batIntSmplHiSet_ovrdval;
                    /* Referenced by: '<S256>/macc_b_batIntSmplHiSet_ovrdval' */

/* Override value for signal macd_b_batIntSmplHiSet */
extern const volatile boolean macc_b_batIntSmplLoEnb_ovrdflg;
                    /* Referenced by: '<S257>/macc_b_batIntSmplLoEnb_ovrdflg' */

/* Override flag to enable DFC_HYB_PwrSuplyORLow */
extern const volatile boolean macc_b_batIntSmplLoEnb_ovrdval;
                    /* Referenced by: '<S257>/macc_b_batIntSmplLoEnb_ovrdval' */

/* Override value to enable DFC_HYB_PwrSuplyORLow */
extern const volatile float32 macc_b_batIntSmplLoHeal_s;/* Referenced by: '<S8>/t_delay_heal' */

/* DFC_HYB_PwrSuplyORLow fault clear threshold */
extern const volatile boolean macc_b_batIntSmplLoSet_ovrdflg;
                    /* Referenced by: '<S258>/macc_b_batIntSmplLoSet_ovrdflg' */

/* Override flag for signal macd_b_batIntSmplLoSet */
extern const volatile boolean macc_b_batIntSmplLoSet_ovrdval;
                    /* Referenced by: '<S258>/macc_b_batIntSmplLoSet_ovrdval' */

/* Override value for signal macd_b_batIntSmplLoSet */
extern const volatile boolean macc_b_cCanBusOffSet_ovrdflg;
                    /* Referenced by: '<S272>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_cCanBusOffSet_ovrdval;
                    /* Referenced by: '<S272>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile boolean macc_b_evCANBusoffSet_ovrdflg;/* Referenced by:
                                                             * '<S270>/macc_b_batIntSmplHiSet_ovrdflg'
                                                             * '<S271>/macc_b_batIntSmplHiSet_ovrdflg'
                                                             */
extern const volatile boolean macc_b_evCANBusoffSet_ovrdval;/* Referenced by:
                                                             * '<S270>/macc_b_batIntSmplHiSet_ovrdval'
                                                             * '<S271>/macc_b_batIntSmplHiSet_ovrdval'
                                                             */
extern const volatile boolean macc_b_ptCanBusOffSet_ovrdflg;
                    /* Referenced by: '<S263>/macc_b_batIntSmplHiSet_ovrdflg' */
extern const volatile boolean macc_b_ptCanBusOffSet_ovrdval;
                    /* Referenced by: '<S263>/macc_b_batIntSmplHiSet_ovrdval' */
extern const volatile float32 macc_tm_ignOnDeb_s;/* Referenced by:
                                                  * '<S364>/Constant198'
                                                  * '<S365>/Constant198'
                                                  * '<S366>/Constant198'
                                                  * '<S367>/Constant198'
                                                  */
extern const volatile float32 macc_u_5VT1IntSmplFltSetHi_V;/* Referenced by: '<S8>/Constant303' */

/* 5VT1 voltage open circuit set higher threshold */
extern const volatile float32 macc_u_5VT1IntSmplFltSetLo_V;/* Referenced by: '<S8>/Constant292' */

/* 5VT1 voltage open circuit set lower threshold */
extern const volatile float32 macc_u_5VT2IntSmplFltSetHi_V;/* Referenced by: '<S8>/Constant325' */

/* 5VT2 voltage open circuit set higher threshold */
extern const volatile float32 macc_u_5VT2IntSmplFltSetLo_V;/* Referenced by: '<S8>/Constant314' */

/* 5VT2 voltage open circuit set lower threshold */
extern const volatile float32 macc_u_batIntSmplHiSet_V;/* Referenced by: '<S8>/Constant281' */

/* Low voltage battery voltage high set threshold */
extern const volatile float32 macc_u_batIntSmplLoSet_V;/* Referenced by: '<S8>/Constant230' */

/* Low voltage battery voltage low set threshold */
extern const volatile boolean sysc_b_delayEnaDTCFcnCall;
                                     /* Referenced by: '<S206>/t_delay_heal1' */

/* Calibration to delay enabling the DTC function call by the fault set debounce time */
extern const volatile boolean sysc_b_forceEnaDTCFcnCall;
                                    /* Referenced by: '<S206>/t_delay_heal15' */

/* Calibration to always enable the DTC function call regardless of the enabling conditions */
#define swc_DIAG_STOP_SEC_CONST_VOLATILE
#include "swc_DIAG_MemMap.h"
#define swc_DIAG_START_SEC_VAR
#include "swc_DIAG_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern boolean acpd_b_accPed1Vld;      /* '<S11>/Logical Operator8' */

/* Accelerator Pedal 1 valid */
extern boolean acpd_b_accPed2Vld;      /* '<S11>/Logical Operator9' */

/* Accelerator Pedal 2 valid */
extern boolean acpd_b_acp1RngHiDebd;   /* '<S49>/timed_debounce' */

/* acp1RngHi fault debounced */
extern boolean acpd_b_acp1RngHiEnb;    /* '<S82>/Switch2' */

/* DFC_HYB_ACCPedal1ORHigh enabled */
extern boolean acpd_b_acp1RngHiRaw;    /* '<S48>/timed_debounce' */

/* acp1RngHi fault raw */
extern boolean acpd_b_acp1RngHiSet;    /* '<S83>/Switch2' */

/* Accel pedal 1 range high fault set */
extern boolean acpd_b_acp1RngLowDebd;  /* '<S53>/timed_debounce' */

/* acp1RngLow fault debounced */
extern boolean acpd_b_acp1RngLowEnb;   /* '<S84>/Switch2' */

/* DFC_HYB_ACCPedal1ORLow enabled */
extern boolean acpd_b_acp1RngLowRaw;   /* '<S52>/timed_debounce' */

/* acp1RngLow fault raw */
extern boolean acpd_b_acp1RngLowSet;   /* '<S85>/Switch2' */

/* Accel pedal 1 range low fault set */
extern boolean acpd_b_acp1Sho2BatDebd; /* '<S57>/timed_debounce' */

/* acp1Sho2Bat fault debounced */
extern boolean acpd_b_acp1Sho2BatEnb;  /* '<S86>/Switch2' */

/* DFC_HYB_ACCPedal1SCB enabled */
extern boolean acpd_b_acp1Sho2BatRaw;  /* '<S56>/timed_debounce' */

/* acp1Sho2Bat fault raw */
extern boolean acpd_b_acp1Sho2BatSet;  /* '<S87>/Switch2' */

/* Accel pedal 1 short to 12V battery fault set */
extern boolean acpd_b_acp1Sho2GndDebd; /* '<S61>/timed_debounce' */

/* acp1Sho2Gnd fault debounced */
extern boolean acpd_b_acp1Sho2GndEnb;  /* '<S88>/Switch2' */

/* DFC_HYB_ACCPedal1SCG enabled */
extern boolean acpd_b_acp1Sho2GndRaw;  /* '<S60>/timed_debounce' */

/* acp1Sho2Gnd fault raw */
extern boolean acpd_b_acp1Sho2GndSet;  /* '<S89>/Switch2' */

/* Accel pedal 1 short to ground fault set */
extern boolean acpd_b_acp2RngHiDebd;   /* '<S65>/timed_debounce' */

/* acp2RngHi fault debounced */
extern boolean acpd_b_acp2RngHiEnb;    /* '<S90>/Switch2' */

/* DFC_HYB_ACCPedal2ORHigh enabled */
extern boolean acpd_b_acp2RngHiRaw;    /* '<S64>/timed_debounce' */

/* acp2RngHi fault raw */
extern boolean acpd_b_acp2RngHiSet;    /* '<S91>/Switch2' */

/* Accel pedal 2 range high fault set */
extern boolean acpd_b_acp2RngLowDebd;  /* '<S69>/timed_debounce' */

/* acp2RngLow fault debounced */
extern boolean acpd_b_acp2RngLowEnb;   /* '<S92>/Switch2' */

/* DFC_HYB_ACCPedal2ORLow enabled */
extern boolean acpd_b_acp2RngLowRaw;   /* '<S68>/timed_debounce' */

/* acp2RngLow fault raw */
extern boolean acpd_b_acp2RngLowSet;   /* '<S93>/Switch2' */

/* Accel pedal 2 range low fault set */
extern boolean acpd_b_acp2Sho2BatDebd; /* '<S73>/timed_debounce' */

/* acp2Sho2Bat fault debounced */
extern boolean acpd_b_acp2Sho2BatEnb;  /* '<S94>/Switch2' */

/* DFC_HYB_ACCPedal2SCB enabled */
extern boolean acpd_b_acp2Sho2BatRaw;  /* '<S72>/timed_debounce' */

/* acp2Sho2Bat fault raw */
extern boolean acpd_b_acp2Sho2BatSet;  /* '<S95>/Switch2' */

/* Accel pedal 2 short to 12V battery fault set */
extern boolean acpd_b_acp2Sho2GndDebd; /* '<S77>/timed_debounce' */

/* acp2Sho2Gnd fault debounced */
extern boolean acpd_b_acp2Sho2GndEnb;  /* '<S96>/Switch2' */

/* DFC_HYB_ACCPedal2SCG enabled */
extern boolean acpd_b_acp2Sho2GndRaw;  /* '<S76>/timed_debounce' */

/* acp2Sho2Gnd fault raw */
extern boolean acpd_b_acp2Sho2GndSet;  /* '<S97>/Switch2' */

/* Accel pedal 2 short to ground fault set */
extern boolean acpd_b_acpCrsFltDebd;   /* '<S80>/timed_debounce' */

/* acpCrsFlt fault debounced */
extern boolean acpd_b_acpCrsFltEnb;    /* '<S98>/Switch2' */

/* DFC_HYB_ACCPedalCrossNP enabled */
extern boolean acpd_b_acpCrsFltSet;    /* '<S99>/Switch2' */

/* Accel pedal cross fault set */
extern boolean brpd_b_BrkSigUnreasnFlt_Flg;/* '<S154>/Compare' */
extern boolean brpd_b_VacPumpLoPreDebd;/* '<S127>/timed_debounce' */
extern boolean brpd_b_VacPumpLoPreSet; /* '<S143>/Switch2' */
extern boolean brpd_b_VacPumpRlyFltDebd;/* '<S129>/timed_debounce' */
extern boolean brpd_b_VacPumpRlyFltSet;/* '<S144>/Switch2' */
extern boolean brpd_b_VacPumpSnrFltDebd;/* '<S131>/timed_debounce' */
extern boolean brpd_b_VacPumpSnrFltSet;/* '<S145>/Switch2' */
extern boolean brpd_b_VacPumpSysFailDebd;/* '<S133>/timed_debounce' */
extern boolean brpd_b_VacPumpSysFailSet;/* '<S146>/Switch2' */
extern boolean brpd_b_VpEnOvTmHiPreDebd;/* '<S135>/timed_debounce' */
extern boolean brpd_b_VpEnOvTmHiPreSet;/* '<S141>/Switch2' */
extern boolean brpd_b_VpEnOvrTmLoPreDebd;/* '<S137>/timed_debounce' */
extern boolean brpd_b_VpEnOvrTmLoPreSet;/* '<S142>/Switch2' */
extern boolean brpd_b_brakeMutExcErr_flg;/* '<S117>/Logical Operator10' */
extern boolean brpd_b_brakeStateOff_flg;/* '<S117>/Logical Operator2' */
extern boolean brpd_b_brakeStateOpen_flg;/* '<S117>/Logical Operator1' */
extern boolean brpd_b_brakeUnreasn_flg;/* '<S157>/FixPt Relational Operator' */
extern boolean brpd_b_breakFailOver_flg;/* '<S117>/Logical Operator11' */
extern boolean brpd_b_brkSwtMismatch;  /* '<S101>/Signal Conversion' */

/* Brake pedal switch mismatch error flag */
extern boolean brpd_b_brkSwtMismatchEnb;/* '<S139>/Switch2' */

/* DFC_HYB_BrkSthNP enabled */
extern boolean brpd_b_brkSwtMismatchSet;/* '<S140>/Switch2' */

/* brkSwtMismatch fault set */
extern uint8 brpd_d_BrkSigErrCn;       /* '<S117>/Subtract' */
extern uint8 brpd_d_BrkSigStoreCn;     /* '<S117>/C Caller' */
extern boolean cesd_b_crashEventDebd;  /* '<S175>/timed_debounce' */

/* crashEvent fault debounced */
extern boolean cesd_b_crashEventEnb;   /* '<S177>/Switch2' */

/* DFC_HYB_CrashEvent enabled */
extern boolean cesd_b_crashEventSet;   /* '<S178>/Switch2' */

/* crashEvent fault set */
extern boolean digd_b_ACUMsgErrDebd;   /* '<S297>/timed_debounce' */
extern boolean digd_b_VehLvl1Flt_flg;  /* '<S197>/Switch' */
extern boolean digd_b_VehLvl1Flt_flgRaw;/* '<S197>/Logical Operator1' */
extern boolean digd_b_VehLvl21Flt_flg; /* '<S198>/Switch1' */
extern boolean digd_b_VehLvl21Flt_flgRaw;/* '<S198>/Logical Operator' */
extern boolean digd_b_VehLvl22Flt_flg; /* '<S199>/Switch5' */
extern boolean digd_b_VehLvl23Flt_flg; /* '<S200>/Switch6' */
extern boolean digd_b_VehLvl31Flt_flg; /* '<S201>/Switch2' */
extern boolean digd_b_VehLvl32Flt_flg; /* '<S202>/Switch3' */
extern boolean digd_b_VehLvl33Flt_flg; /* '<S203>/Switch4' */
extern boolean digd_b_edcpBlockDebd;   /* '<S419>/timed_debounce' */
extern boolean digd_b_edcpBlockSet;    /* '<S443>/Switch2' */
extern boolean digd_b_edcpIdlyDebd;    /* '<S404>/timed_debounce' */
extern boolean digd_b_edcpIdlySet;     /* '<S440>/Switch2' */
extern boolean digd_b_edcpOvrCurrDebd; /* '<S422>/timed_debounce' */
extern boolean digd_b_edcpOvrCurrSet;  /* '<S444>/Switch2' */
extern boolean digd_b_edcpOvrTmpDebd;  /* '<S401>/timed_debounce' */
extern boolean digd_b_edcpOvrTmpSet;   /* '<S436>/Switch2' */
extern boolean digd_b_edcpOvrVoltDebd; /* '<S416>/timed_debounce' */
extern boolean digd_b_edcpOvrVoltSet;  /* '<S442>/Switch2' */
extern boolean digd_b_edcpUdVoltDebd;  /* '<S413>/timed_debounce' */
extern boolean digd_b_edcpUdVoltSet;   /* '<S441>/Switch2' */
extern boolean digd_b_hbcpBlockDebd;   /* '<S407>/timed_debounce' */
extern boolean digd_b_hbcpBlockSet;    /* '<S438>/Switch2' */
extern boolean digd_b_hbcpIdlyDebd;    /* '<S428>/timed_debounce' */
extern boolean digd_b_hbcpIdlySet;     /* '<S446>/Switch2' */
extern boolean digd_b_hbcpOvrCurrDebd; /* '<S410>/timed_debounce' */
extern boolean digd_b_hbcpOvrCurrSet;  /* '<S439>/Switch2' */
extern boolean digd_b_hbcpOvrTmpDebd;  /* '<S425>/timed_debounce' */
extern boolean digd_b_hbcpOvrTmpSet;   /* '<S445>/Switch2' */
extern boolean digd_b_hbcpOvrVoltDebd; /* '<S434>/timed_debounce' */
extern boolean digd_b_hbcpOvrVoltSet;  /* '<S437>/Switch2' */
extern boolean digd_b_hbcpUdVoltDebd;  /* '<S431>/timed_debounce' */
extern boolean digd_b_hbcpUdVoltSet;   /* '<S447>/Switch2' */
extern boolean digd_b_vcuLvl1Flt_MAC;  /* '<S8>/Logical Operator264' */
extern boolean digd_b_vcuLvl1Flt_THM;  /* '<S10>/Logical Operator' */
extern boolean digd_b_vcuLvl21Flt_MAC; /* '<S309>/timed_debounce' */
extern boolean digd_b_vcuLvl23Flt_MAC; /* '<S8>/Logical Operator265' */
extern boolean digd_b_vcuLvl31Flt_MAC; /* '<S8>/Logical Operator271' */
extern boolean digd_b_vcuVehLvl1Flt_flg_ACP;/* '<S11>/Logical Operator20' */
extern boolean digd_b_vcuVehLvl1Flt_flg_HVB;/* '<S7>/Signal Conversion' */
extern boolean digd_b_vcuVehLvl21Flt_flg_EAD;/* '<S189>/timed_debounce' */
extern boolean digd_b_vcuVehLvl21Flt_flg_HVB;/* '<S218>/timed_debounce' */
extern boolean digd_b_vcuVehLvl22Flt_flg_BRP;/* '<S101>/Logical Operator36' */
extern boolean digd_b_vcuVehLvl23Flt_flg_ACP;/* '<S11>/Signal Conversion' */
extern boolean digd_b_vcuVehLvl31Flt_flg_EAD;/* '<S186>/Logical Operator3' */
extern boolean digd_b_vcuVehLvl32Flt_flg_HVB;/* '<S213>/Logical Operator3' */
extern boolean digd_b_vcuVehLvl33Flt_flg_CES;/* '<S4>/Signal Conversion' */
extern boolean digd_b_vcuVehLvl33Flt_flg_HVB;/* '<S7>/Signal Conversion3' */
extern uint8 digd_st_edcpFlt;          /* '<S10>/Switch' */
extern uint8 digd_st_hbcpFlt;          /* '<S10>/Switch6' */
extern uint8 digd_st_vehSysErrLevel;   /* '<S6>/Switch' */
extern boolean hvbd_b_BMSFaultLevel2ASet;/* '<S230>/Switch2' */
extern boolean hvbd_b_BMSFaultLevel3ASet;/* '<S231>/Switch2' */
extern boolean hvbd_b_BMSFaultLevel4ASet;/* '<S232>/Switch2' */
extern boolean hvbd_b_MCUFaultLevel2ASet;/* '<S195>/Switch2' */
extern boolean hvbd_b_MCUFaultLevel3ASet;/* '<S196>/Switch2' */
extern boolean hvbd_b_vehHvilFltSet;   /* '<S229>/Switch2' */

/* vehHvilFlt fault set */
extern boolean macb_b_P2AD4;           /* '<S8>/Signal Conversion2' */

/* Power supply out of range low - 4.5T BEV and 8T REV */
extern boolean macb_b_P2AD5;           /* '<S8>/Signal Conversion3' */

/* Power supply out of range high - 4.5T BEV and 8T REV */
extern boolean macd_b_5VT1IntSmplFltEnb;/* '<S346>/Switch2' */

/* DFC_HYB_T5V1Mon enabled */
extern boolean macd_b_5VT1IntSmplFltSet;/* '<S347>/Switch2' */

/* 5VT1 voltage open circuit set */
extern boolean macd_b_5VT2IntSmplFltEnb;/* '<S348>/Switch2' */

/* DFC_HYB_T5V2Mon enabled */
extern boolean macd_b_5VT2IntSmplFltSet;/* '<S349>/Switch2' */

/* 5VT2 voltage open circuit set */
extern boolean macd_b_ABSMsgErrDebd;   /* '<S295>/timed_debounce' */

/* ABSMsgErrDebd fault debounced */
extern boolean macd_b_ABSMsgErrSet;    /* '<S360>/Switch2' */
extern boolean macd_b_ABSSpdMsgErrDebd;/* '<S321>/timed_debounce' */

/* macd_b_ABSSpdMsgErrDebd fault debounced */
extern boolean macd_b_ABSSpdMsgErrSet; /* '<S351>/Switch2' */
extern boolean macd_b_ACUMsgErrSet;    /* '<S353>/Switch2' */
extern boolean macd_b_BMSHealthMonErrDebd;/* '<S299>/timed_debounce' */
extern boolean macd_b_BMSHealthMonErrSet;/* '<S354>/Switch2' */
extern boolean macd_b_CSMMsgErrDebd;   /* '<S303>/timed_debounce' */
extern boolean macd_b_CSMMsgErrSet;    /* '<S356>/Switch2' */
extern boolean macd_b_DCDCMsgErrDebd;  /* '<S305>/timed_debounce' */

/* macd_b_DCDCMsgErrDebd fault debounced */
extern boolean macd_b_DCDCMsgErrSet;   /* '<S361>/Switch2' */
extern boolean macd_b_EGSMMsgErrDebd;  /* '<S307>/timed_debounce' */

/* macd_b_EGSMMsgErrDebd fault debounced */
extern boolean macd_b_EGSMMsgErrSet;   /* '<S362>/Switch2' */
extern boolean macd_b_MCUHealthMonErrDebd;/* '<S313>/timed_debounce' */
extern boolean macd_b_MCUHealthMonErrSet;/* '<S355>/Switch2' */
extern boolean macd_b_PEPSMsgErrDebd;  /* '<S315>/timed_debounce' */

/* macd_b_PEPSMsgErrDebd fault debounced */
extern boolean macd_b_PEPSMsgErrSet;   /* '<S352>/Switch2' */
extern boolean macd_b_batIntSmplHiEnb; /* '<S342>/Switch2' */

/* DFC_HYB_PwrSuplyORHigh enabled */
extern boolean macd_b_batIntSmplHiSet; /* '<S343>/Switch2' */

/* Low voltage battery voltage high set */
extern boolean macd_b_batIntSmplLoDebd;/* '<S8>/SR_latch3' */

/* batIntSmplLo fault debounced */
extern boolean macd_b_batIntSmplLoEnb; /* '<S344>/Switch2' */

/* DFC_HYB_PwrSuplyORLow enabled */
extern boolean macd_b_batIntSmplLoSet; /* '<S345>/Switch2' */

/* Low voltage battery voltage low set */
extern boolean macd_b_cCanBusOffDebd;  /* '<S327>/timed_debounce' */
extern boolean macd_b_cCanBusOffSet;   /* '<S359>/Switch2' */
extern boolean macd_b_evCANBusoffDebd; /* '<S311>/timed_debounce' */
extern boolean macd_b_evCANBusoffSet;  /* '<S357>/Switch2' */
extern boolean macd_b_ptCanBusOffDebd; /* '<S301>/timed_debounce' */
extern boolean macd_b_ptCanBusOffSet;  /* '<S350>/Switch2' */

#define swc_DIAG_STOP_SEC_VAR
#include "swc_DIAG_MemMap.h"

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
 * '<Root>' : 'swc_DIAG'
 * '<S1>'   : 'swc_DIAG/DIAG__Diagnostics'
 * '<S2>'   : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag'
 * '<S3>'   : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag'
 * '<S4>'   : 'swc_DIAG/DIAG__Diagnostics/CES_Diag'
 * '<S5>'   : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2'
 * '<S6>'   : 'swc_DIAG/DIAG__Diagnostics/Fault_Management'
 * '<S7>'   : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag'
 * '<S8>'   : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag'
 * '<S9>'   : 'swc_DIAG/DIAG__Diagnostics/Subsystem'
 * '<S10>'  : 'swc_DIAG/DIAG__Diagnostics/THM_Diag'
 * '<S11>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag'
 * '<S12>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORHigh'
 * '<S13>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORLow'
 * '<S14>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCB'
 * '<S15>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCG'
 * '<S16>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORHigh'
 * '<S17>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORLow'
 * '<S18>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCB'
 * '<S19>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCG'
 * '<S20>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedalCrossNP'
 * '<S21>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1ORHigh_Enb'
 * '<S22>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1ORHigh_Set'
 * '<S23>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1ORLow_Enb'
 * '<S24>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1ORLow_Set'
 * '<S25>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1SCB_Enb'
 * '<S26>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1SCB_Set'
 * '<S27>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1SCG_Enb'
 * '<S28>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1SCG_Set'
 * '<S29>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2ORHigh_Enb'
 * '<S30>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2ORHigh_Set'
 * '<S31>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2ORLow_Enb'
 * '<S32>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2ORLow_Set'
 * '<S33>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2SCB_Enb'
 * '<S34>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2SCB_Set'
 * '<S35>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2SCG_Enb'
 * '<S36>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2SCG_Set'
 * '<S37>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedalCrossNP_Enb'
 * '<S38>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedalCrossNP_Set'
 * '<S39>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem'
 * '<S40>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem1'
 * '<S41>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem2'
 * '<S42>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem3'
 * '<S43>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem4'
 * '<S44>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem5'
 * '<S45>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem6'
 * '<S46>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem7'
 * '<S47>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Subsystem8'
 * '<S48>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORHigh/debounce1'
 * '<S49>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORHigh/debounce2'
 * '<S50>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORHigh/debounce1/timed_debounce'
 * '<S51>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORHigh/debounce2/timed_debounce'
 * '<S52>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORLow/debounce1'
 * '<S53>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORLow/debounce2'
 * '<S54>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORLow/debounce1/timed_debounce'
 * '<S55>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1ORLow/debounce2/timed_debounce'
 * '<S56>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCB/debounce1'
 * '<S57>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCB/debounce2'
 * '<S58>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCB/debounce1/timed_debounce'
 * '<S59>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCB/debounce2/timed_debounce'
 * '<S60>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCG/debounce1'
 * '<S61>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCG/debounce2'
 * '<S62>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCG/debounce1/timed_debounce'
 * '<S63>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal1SCG/debounce2/timed_debounce'
 * '<S64>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORHigh/debounce1'
 * '<S65>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORHigh/debounce2'
 * '<S66>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORHigh/debounce1/timed_debounce'
 * '<S67>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORHigh/debounce2/timed_debounce'
 * '<S68>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORLow/debounce1'
 * '<S69>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORLow/debounce2'
 * '<S70>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORLow/debounce1/timed_debounce'
 * '<S71>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2ORLow/debounce2/timed_debounce'
 * '<S72>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCB/debounce1'
 * '<S73>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCB/debounce2'
 * '<S74>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCB/debounce1/timed_debounce'
 * '<S75>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCB/debounce2/timed_debounce'
 * '<S76>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCG/debounce1'
 * '<S77>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCG/debounce2'
 * '<S78>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCG/debounce1/timed_debounce'
 * '<S79>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedal2SCG/debounce2/timed_debounce'
 * '<S80>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedalCrossNP/debounce'
 * '<S81>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/DFC_HYB_ACCPedalCrossNP/debounce/timed_debounce'
 * '<S82>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1ORHigh_Enb/override_signal'
 * '<S83>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1ORHigh_Set/override_signal'
 * '<S84>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1ORLow_Enb/override_signal'
 * '<S85>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1ORLow_Set/override_signal'
 * '<S86>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1SCB_Enb/override_signal'
 * '<S87>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1SCB_Set/override_signal'
 * '<S88>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1SCG_Enb/override_signal'
 * '<S89>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal1SCG_Set/override_signal'
 * '<S90>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2ORHigh_Enb/override_signal'
 * '<S91>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2ORHigh_Set/override_signal'
 * '<S92>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2ORLow_Enb/override_signal'
 * '<S93>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2ORLow_Set/override_signal'
 * '<S94>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2SCB_Enb/override_signal'
 * '<S95>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2SCB_Set/override_signal'
 * '<S96>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2SCG_Enb/override_signal'
 * '<S97>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedal2SCG_Set/override_signal'
 * '<S98>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedalCrossNP_Enb/override_signal'
 * '<S99>'  : 'swc_DIAG/DIAG__Diagnostics/ACP_Diag/HardwiredAccelPedalDiag/Ovrd_ACCPedalCrossNP_Set/override_signal'
 * '<S100>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem'
 * '<S101>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag'
 * '<S102>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_BrkSthNP'
 * '<S103>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpLoPreFlt'
 * '<S104>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpRlyFlt'
 * '<S105>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpSensorErr'
 * '<S106>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpSysErr'
 * '<S107>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpWorkTOut1'
 * '<S108>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpWorkTOut2'
 * '<S109>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_BrkSthNP_Enb'
 * '<S110>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_BrkSthNP_Set'
 * '<S111>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpEnOvrTmHiPreFlt_Set'
 * '<S112>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpEnOvrTmLoPreFlt_Set'
 * '<S113>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpLoPreFlt_Set'
 * '<S114>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpRlyFlt_Set'
 * '<S115>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpSnrFlt_Set'
 * '<S116>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpSysFailFlt_Set'
 * '<S117>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem'
 * '<S118>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem1'
 * '<S119>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem2'
 * '<S120>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem3'
 * '<S121>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem4'
 * '<S122>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem5'
 * '<S123>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem6'
 * '<S124>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem7'
 * '<S125>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_BrkSthNP/debounce'
 * '<S126>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_BrkSthNP/debounce/timed_debounce'
 * '<S127>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpLoPreFlt/debounce'
 * '<S128>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpLoPreFlt/debounce/timed_debounce'
 * '<S129>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpRlyFlt/debounce'
 * '<S130>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpRlyFlt/debounce/timed_debounce'
 * '<S131>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpSensorErr/debounce'
 * '<S132>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpSensorErr/debounce/timed_debounce'
 * '<S133>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpSysErr/debounce'
 * '<S134>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpSysErr/debounce/timed_debounce'
 * '<S135>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpWorkTOut1/debounce'
 * '<S136>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpWorkTOut1/debounce/timed_debounce'
 * '<S137>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpWorkTOut2/debounce'
 * '<S138>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/DFC_HYB_VacPumpWorkTOut2/debounce/timed_debounce'
 * '<S139>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_BrkSthNP_Enb/override_signal'
 * '<S140>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_BrkSthNP_Set/override_signal'
 * '<S141>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpEnOvrTmHiPreFlt_Set/override_signal'
 * '<S142>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpEnOvrTmLoPreFlt_Set/override_signal'
 * '<S143>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpLoPreFlt_Set/override_signal'
 * '<S144>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpRlyFlt_Set/override_signal'
 * '<S145>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpSnrFlt_Set/override_signal'
 * '<S146>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Ovrd_VacPumpSysFailFlt_Set/override_signal'
 * '<S147>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Chart1'
 * '<S148>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Compare To Constant'
 * '<S149>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Compare To Constant1'
 * '<S150>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Compare To Constant10'
 * '<S151>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Compare To Constant11'
 * '<S152>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Compare To Constant2'
 * '<S153>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Compare To Constant3'
 * '<S154>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Compare To Constant4'
 * '<S155>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Detect Decrease'
 * '<S156>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Detect Decrease1'
 * '<S157>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Detect Increase'
 * '<S158>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Detect Increase4'
 * '<S159>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Enabled Subsystem'
 * '<S160>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/debounce1'
 * '<S161>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/turnOFF_delay'
 * '<S162>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/turnOFF_delay1'
 * '<S163>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Enabled Subsystem/Compare To Constant5'
 * '<S164>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Enabled Subsystem/Compare To Constant6'
 * '<S165>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Enabled Subsystem/debounce3'
 * '<S166>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/Enabled Subsystem/debounce3/timed_debounce'
 * '<S167>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/debounce1/timed_debounce'
 * '<S168>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/turnOFF_delay/timed_delay'
 * '<S169>' : 'swc_DIAG/DIAG__Diagnostics/BRP_Diag/Subsystem/BrakeSwitchDiag/Subsystem/turnOFF_delay1/timed_delay'
 * '<S170>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/DFC_HYB_CrashEvent'
 * '<S171>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/Ovrd_CrashEvent_Enb'
 * '<S172>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/Ovrd_CrashEvent_Set'
 * '<S173>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/override_signal'
 * '<S174>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/DFC_HYB_CrashEvent/Subsystem'
 * '<S175>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/DFC_HYB_CrashEvent/debounce'
 * '<S176>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/DFC_HYB_CrashEvent/debounce/timed_debounce'
 * '<S177>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/Ovrd_CrashEvent_Enb/override_signal'
 * '<S178>' : 'swc_DIAG/DIAG__Diagnostics/CES_Diag/Ovrd_CrashEvent_Set/override_signal'
 * '<S179>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/DFC_HYB_MCUFaultLevel2A'
 * '<S180>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/DFC_HYB_MCUFaultLevel3A'
 * '<S181>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/Enumerated Constant'
 * '<S182>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/Enumerated Constant1'
 * '<S183>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/MalfunctionReset1'
 * '<S184>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/Ovrd_VehicleHVILFlt_Set1'
 * '<S185>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/Ovrd_VehicleHVILFlt_Set2'
 * '<S186>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/SR_latch1'
 * '<S187>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/Subsystem'
 * '<S188>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/Subsystem1'
 * '<S189>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/DFC_HYB_MCUFaultLevel2A/debounce'
 * '<S190>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/DFC_HYB_MCUFaultLevel2A/debounce/timed_debounce'
 * '<S191>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/DFC_HYB_MCUFaultLevel3A/debounce'
 * '<S192>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/DFC_HYB_MCUFaultLevel3A/debounce/timed_debounce'
 * '<S193>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/MalfunctionReset1/Compare To Constant'
 * '<S194>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/MalfunctionReset1/Compare To Constant3'
 * '<S195>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/Ovrd_VehicleHVILFlt_Set1/override_signal'
 * '<S196>' : 'swc_DIAG/DIAG__Diagnostics/EAD_DiagMot2/Ovrd_VehicleHVILFlt_Set2/override_signal'
 * '<S197>' : 'swc_DIAG/DIAG__Diagnostics/Fault_Management/VehicleLevel1'
 * '<S198>' : 'swc_DIAG/DIAG__Diagnostics/Fault_Management/VehicleLevel2_1'
 * '<S199>' : 'swc_DIAG/DIAG__Diagnostics/Fault_Management/VehicleLevel2_2'
 * '<S200>' : 'swc_DIAG/DIAG__Diagnostics/Fault_Management/VehicleLevel2_3'
 * '<S201>' : 'swc_DIAG/DIAG__Diagnostics/Fault_Management/VehicleLevel3_1'
 * '<S202>' : 'swc_DIAG/DIAG__Diagnostics/Fault_Management/VehicleLevel3_2'
 * '<S203>' : 'swc_DIAG/DIAG__Diagnostics/Fault_Management/VehicleLevel3_3'
 * '<S204>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel2A'
 * '<S205>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel3A'
 * '<S206>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel4A'
 * '<S207>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_VehicleHVILFlt'
 * '<S208>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/MalfunctionReset1'
 * '<S209>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Ovrd_VehicleHVILFlt_Set'
 * '<S210>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Ovrd_VehicleHVILFlt_Set1'
 * '<S211>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Ovrd_VehicleHVILFlt_Set2'
 * '<S212>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Ovrd_VehicleHVILFlt_Set3'
 * '<S213>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/SR_latch1'
 * '<S214>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Subsystem'
 * '<S215>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Subsystem1'
 * '<S216>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Subsystem2'
 * '<S217>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/override_signal'
 * '<S218>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel2A/debounce'
 * '<S219>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel2A/debounce/timed_debounce'
 * '<S220>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel3A/debounce'
 * '<S221>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel3A/debounce/timed_debounce'
 * '<S222>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel4A/Subsystem'
 * '<S223>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel4A/debounce'
 * '<S224>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel4A/turnON_delay'
 * '<S225>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel4A/debounce/timed_debounce'
 * '<S226>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_BMSFaultLevel4A/turnON_delay/timed_delay'
 * '<S227>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_VehicleHVILFlt/debounce'
 * '<S228>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/DFC_HYB_VehicleHVILFlt/debounce/timed_debounce'
 * '<S229>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Ovrd_VehicleHVILFlt_Set/override_signal'
 * '<S230>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Ovrd_VehicleHVILFlt_Set1/override_signal'
 * '<S231>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Ovrd_VehicleHVILFlt_Set2/override_signal'
 * '<S232>' : 'swc_DIAG/DIAG__Diagnostics/HVB_Diag/Ovrd_VehicleHVILFlt_Set3/override_signal'
 * '<S233>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Compare To Constant'
 * '<S234>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Compare To Constant1'
 * '<S235>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_ABSMsgErr'
 * '<S236>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_ACUMsgErr'
 * '<S237>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_BMSHealthMonErr'
 * '<S238>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_CANFDBusoff'
 * '<S239>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_CSMMsgErr'
 * '<S240>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_DCDCMsgErr'
 * '<S241>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EGSMMsgErr'
 * '<S242>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EVCANBusoff'
 * '<S243>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EVCANBusoff1'
 * '<S244>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_MCUHealthMonErr'
 * '<S245>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PEPSMsgErr'
 * '<S246>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PwrSuplyORHigh'
 * '<S247>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PwrSuplyORLow'
 * '<S248>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_SpdMsgErr'
 * '<S249>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_T5V1Mon'
 * '<S250>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_T5V2Mon'
 * '<S251>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_TPCANBusoff'
 * '<S252>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset2'
 * '<S253>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset3'
 * '<S254>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset7'
 * '<S255>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_PwrSuplyORHigh_Enb'
 * '<S256>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_PwrSuplyORHigh_Set'
 * '<S257>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_PwrSuplyORLow_Enb'
 * '<S258>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_PwrSuplyORLow_Set'
 * '<S259>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_T5V1Mon_Enb'
 * '<S260>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_T5V1Mon_Set'
 * '<S261>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_T5V2Mon_Enb'
 * '<S262>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_T5V2Mon_Set'
 * '<S263>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set1'
 * '<S264>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set10'
 * '<S265>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set11'
 * '<S266>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set12'
 * '<S267>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set13'
 * '<S268>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set14'
 * '<S269>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set15'
 * '<S270>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set16'
 * '<S271>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set2'
 * '<S272>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set3'
 * '<S273>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set4'
 * '<S274>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set6'
 * '<S275>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set8'
 * '<S276>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/SR_latch2'
 * '<S277>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/SR_latch3'
 * '<S278>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/SR_latch4'
 * '<S279>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem'
 * '<S280>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem1'
 * '<S281>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem10'
 * '<S282>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem11'
 * '<S283>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem12'
 * '<S284>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem13'
 * '<S285>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem14'
 * '<S286>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem15'
 * '<S287>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem2'
 * '<S288>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem3'
 * '<S289>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem4'
 * '<S290>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem5'
 * '<S291>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem6'
 * '<S292>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem7'
 * '<S293>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem8'
 * '<S294>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Subsystem9'
 * '<S295>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_ABSMsgErr/debounce'
 * '<S296>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_ABSMsgErr/debounce/timed_debounce'
 * '<S297>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_ACUMsgErr/debounce'
 * '<S298>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_ACUMsgErr/debounce/timed_debounce'
 * '<S299>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_BMSHealthMonErr/debounce'
 * '<S300>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_BMSHealthMonErr/debounce/timed_debounce'
 * '<S301>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_CANFDBusoff/debounce'
 * '<S302>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_CANFDBusoff/debounce/timed_debounce'
 * '<S303>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_CSMMsgErr/debounce'
 * '<S304>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_CSMMsgErr/debounce/timed_debounce'
 * '<S305>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_DCDCMsgErr/debounce'
 * '<S306>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_DCDCMsgErr/debounce/timed_debounce'
 * '<S307>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EGSMMsgErr/debounce'
 * '<S308>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EGSMMsgErr/debounce/timed_debounce'
 * '<S309>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EVCANBusoff/debounce'
 * '<S310>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EVCANBusoff/debounce/timed_debounce'
 * '<S311>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EVCANBusoff1/debounce'
 * '<S312>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_EVCANBusoff1/debounce/timed_debounce'
 * '<S313>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_MCUHealthMonErr/debounce'
 * '<S314>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_MCUHealthMonErr/debounce/timed_debounce'
 * '<S315>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PEPSMsgErr/debounce'
 * '<S316>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PEPSMsgErr/debounce/timed_debounce'
 * '<S317>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PwrSuplyORHigh/debounce'
 * '<S318>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PwrSuplyORHigh/debounce/timed_debounce'
 * '<S319>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PwrSuplyORLow/debounce'
 * '<S320>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_PwrSuplyORLow/debounce/timed_debounce'
 * '<S321>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_SpdMsgErr/debounce'
 * '<S322>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_SpdMsgErr/debounce/timed_debounce'
 * '<S323>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_T5V1Mon/debounce'
 * '<S324>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_T5V1Mon/debounce/timed_debounce'
 * '<S325>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_T5V2Mon/debounce'
 * '<S326>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_T5V2Mon/debounce/timed_debounce'
 * '<S327>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_TPCANBusoff/debounce'
 * '<S328>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/DFC_HYB_TPCANBusoff/debounce/timed_debounce'
 * '<S329>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset2/Compare To Constant'
 * '<S330>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset2/Compare To Constant1'
 * '<S331>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset2/Compare To Constant2'
 * '<S332>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset2/Compare To Constant3'
 * '<S333>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset3/Compare To Constant'
 * '<S334>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset3/Compare To Constant1'
 * '<S335>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset3/Compare To Constant2'
 * '<S336>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset3/Compare To Constant3'
 * '<S337>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset7/Compare To Constant'
 * '<S338>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset7/Compare To Constant1'
 * '<S339>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset7/Compare To Constant2'
 * '<S340>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset7/Compare To Constant3'
 * '<S341>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/MalfunctionReset7/Compare To Constant4'
 * '<S342>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_PwrSuplyORHigh_Enb/override_signal'
 * '<S343>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_PwrSuplyORHigh_Set/override_signal'
 * '<S344>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_PwrSuplyORLow_Enb/override_signal'
 * '<S345>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_PwrSuplyORLow_Set/override_signal'
 * '<S346>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_T5V1Mon_Enb/override_signal'
 * '<S347>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_T5V1Mon_Set/override_signal'
 * '<S348>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_T5V2Mon_Enb/override_signal'
 * '<S349>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd_T5V2Mon_Set/override_signal'
 * '<S350>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set1/override_signal'
 * '<S351>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set10/override_signal'
 * '<S352>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set11/override_signal'
 * '<S353>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set12/override_signal'
 * '<S354>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set13/override_signal'
 * '<S355>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set14/override_signal'
 * '<S356>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set15/override_signal'
 * '<S357>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set16/override_signal'
 * '<S358>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set2/override_signal'
 * '<S359>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set3/override_signal'
 * '<S360>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set4/override_signal'
 * '<S361>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set6/override_signal'
 * '<S362>' : 'swc_DIAG/DIAG__Diagnostics/MAC_Diag/Ovrd__Set8/override_signal'
 * '<S363>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/Compare To Constant'
 * '<S364>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay1'
 * '<S365>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay2'
 * '<S366>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay4'
 * '<S367>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay5'
 * '<S368>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay1/turnON_delay5'
 * '<S369>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay1/turnON_delay5/timed_delay'
 * '<S370>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay2/turnON_delay5'
 * '<S371>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay2/turnON_delay5/timed_delay'
 * '<S372>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay4/turnON_delay5'
 * '<S373>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay4/turnON_delay5/timed_delay'
 * '<S374>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay5/turnON_delay5'
 * '<S375>' : 'swc_DIAG/DIAG__Diagnostics/Subsystem/delay5/turnON_delay5/timed_delay'
 * '<S376>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon'
 * '<S377>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon1'
 * '<S378>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon10'
 * '<S379>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon11'
 * '<S380>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon2'
 * '<S381>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon3'
 * '<S382>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon4'
 * '<S383>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon5'
 * '<S384>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon6'
 * '<S385>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon7'
 * '<S386>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon8'
 * '<S387>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon9'
 * '<S388>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set1'
 * '<S389>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set10'
 * '<S390>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set11'
 * '<S391>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set12'
 * '<S392>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set2'
 * '<S393>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set3'
 * '<S394>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set4'
 * '<S395>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set5'
 * '<S396>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set6'
 * '<S397>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set7'
 * '<S398>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set8'
 * '<S399>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set9'
 * '<S400>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon/Subsystem'
 * '<S401>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon/debounce'
 * '<S402>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon/debounce/timed_debounce'
 * '<S403>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon1/Subsystem'
 * '<S404>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon1/debounce'
 * '<S405>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon1/debounce/timed_debounce'
 * '<S406>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon10/Subsystem'
 * '<S407>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon10/debounce'
 * '<S408>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon10/debounce/timed_debounce'
 * '<S409>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon11/Subsystem'
 * '<S410>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon11/debounce'
 * '<S411>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon11/debounce/timed_debounce'
 * '<S412>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon2/Subsystem'
 * '<S413>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon2/debounce'
 * '<S414>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon2/debounce/timed_debounce'
 * '<S415>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon3/Subsystem'
 * '<S416>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon3/debounce'
 * '<S417>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon3/debounce/timed_debounce'
 * '<S418>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon4/Subsystem'
 * '<S419>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon4/debounce'
 * '<S420>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon4/debounce/timed_debounce'
 * '<S421>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon5/Subsystem'
 * '<S422>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon5/debounce'
 * '<S423>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon5/debounce/timed_debounce'
 * '<S424>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon6/Subsystem'
 * '<S425>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon6/debounce'
 * '<S426>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon6/debounce/timed_debounce'
 * '<S427>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon7/Subsystem'
 * '<S428>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon7/debounce'
 * '<S429>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon7/debounce/timed_debounce'
 * '<S430>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon8/Subsystem'
 * '<S431>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon8/debounce'
 * '<S432>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon8/debounce/timed_debounce'
 * '<S433>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon9/Subsystem'
 * '<S434>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon9/debounce'
 * '<S435>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/DFC_HYB_T5V1Mon9/debounce/timed_debounce'
 * '<S436>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set1/override_signal'
 * '<S437>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set10/override_signal'
 * '<S438>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set11/override_signal'
 * '<S439>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set12/override_signal'
 * '<S440>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set2/override_signal'
 * '<S441>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set3/override_signal'
 * '<S442>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set4/override_signal'
 * '<S443>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set5/override_signal'
 * '<S444>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set6/override_signal'
 * '<S445>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set7/override_signal'
 * '<S446>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set8/override_signal'
 * '<S447>' : 'swc_DIAG/DIAG__Diagnostics/THM_Diag/Ovrd_Set9/override_signal'
 */
#endif                                 /* RTW_HEADER_swc_DIAG_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
