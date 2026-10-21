/*
 * File: swc_THSM.h
 *
 * Code generated for Simulink model 'swc_THSM'.
 *
 * Model version                  : 6.156
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Jul  3 15:08:27 2026
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Renesas->RH850
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_swc_THSM_h_
#define RTW_HEADER_swc_THSM_h_
#ifndef swc_THSM_COMMON_INCLUDES_
#define swc_THSM_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_swc_THSM.h"
#endif                                 /* swc_THSM_COMMON_INCLUDES_ */

#include "Rte_Type.h"

/* Includes for objects with custom storage classes */
#include "const_ImportFromFile.h"
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
  uint8 vild_st_bmsTboxFireAlm;
  uint8 vild_st_bmsBattPackMatchFlt;
  uint8 vild_st_ipuMotorOverSpdFlt;
  uint8 vild_st_ipuMotorOverCurrFlt;
  uint8 vild_st_bmsBattSysNum;
  uint8 vild_st_bmsBattPackNum;
  uint8 vild_st_bmsDlyDataUpldEnb;
  uint8 vild_st_csmEngRecReqInvalid;
  uint8 vild_b_csmEngRecSwtReq;
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
} vcsb_HVSM;

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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_VBSW_
#define DEFINED_TYPEDEF_FOR_vcsb_VBSW_

typedef struct {
  boolean vbsd_b_vbsShtDwnHVReq;
  boolean vbsd_b_vbsShtDwnBatLVReq;
  uint8 vbsd_st_vbsSwapSts;
} vcsb_VBSW;

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

#ifndef DEFINED_TYPEDEF_FOR_vcsb_THSM_
#define DEFINED_TYPEDEF_FOR_vcsb_THSM_

typedef struct {
  FanStatus thmd_e_fanTgtSts;
  PumpStatus thmd_e_wtrPmp1TgtSts;
  PumpStatus thmd_e_wtrPmp2TgtSts;
  boolean thmd_b_afterRunActive;
  boolean thmd_b_fanRly1Req;
  boolean thmd_b_fanRly2Req;
  boolean thmd_b_wtrPmpRly1Req;
  boolean thmd_b_wtrPmpRly2Req;
  float32 thmd_n_fan1TgtSpd_rpm;
  float32 thmd_n_wtrPmp1TgtSpd_rpm;
  float32 thmd_n_wtrPmp2TgtSpd_rpm;
  float32 thmd_n_fan1TgtSpd_pct;
  float32 thmd_n_pmp1TgtSpd_pct;
  float32 thmd_n_pmp2TgtSpd_pct;
  uint8 thmd_st_FanReqCmd;
  uint8 thmd_st_wtrPmp1ReqCmd;
  uint8 thmd_st_wtrPmp2ReqCmd;
  boolean thmd_b_TwoWayVlvReq;
  float32 thmd_n_fan2TgtSpd_pct;
  uint8 thmd_b_fan2Ena;
  boolean thmd_b_tv4V2;
  boolean thmd_b_tv4V3;
  TV4Status thmd_e_tv4;
  uint8 thmd_st_tv4;
  boolean thmd_b_tv1V2;
  boolean thmd_b_tv1V3;
  boolean thmd_b_tv2V2;
  boolean thmd_b_tv2V3;
  boolean thmd_b_heaterEna;
  boolean thmd_b_tv3V2;
  boolean thmd_b_tv3V3;
  uint8 thmd_st_tv3;
  float32 thmd_n_ep1TgtSpd_pct;
  boolean thmd_b_accmEnb;
  float32 thmd_x_iceB_pct;
  float32 thmd_x_iceC_pct;
  float32 thmd_x_hvbcB_pct;
  float32 thmd_x_hvbcC_pct;
  uint8 thmd_x_hvbB_pct;
  uint8 thmd_x_hvbC_pct;
  boolean thmd_b_wtrPmp1CtrlEnabled;
  boolean thmd_b_wtrPmp2CtrlEnabled;
  boolean thmd_b_engStartReq;
  float32 thmd_n_MHGVTgt_pct;
  float32 thmd_n_FWFVTgt_pct;
  boolean thmd_b_PassCool_flg;
  boolean thmd_b_ActiveCool_flg;
  boolean thmd_b_BalanceHeat_flg;
  boolean thmd_b_PassHeat_flg;
  float32 thmd_q_pmp2FlowFeedback;
  boolean thmd_b_hvbDeft;
  boolean thmd_b_iptcHtIpuResvHt;
  boolean thmd_b_iptcHtIpuCl;
  boolean thmd_b_ipuResvHt;
  boolean thmd_b_ipuSupHtIptcHt;
  boolean thmd_b_ipuHeatEnableFlg;
  float32 thmd_pwr_ipuHeatPwrAllwd_kW;
  boolean thmd_b_heaterEna2;
  boolean thmd_b_heaterEna3;
  boolean thmd_b_heaterEnaHW;
  boolean thmd_b_heaterEna3HW;
  uint8 thmd_st_ptcRlyVoltSamSwitch;
  uint8 thmd_st_acceRlyVoltSamSwitch;
  uint8 thmd_st_ptcConnStsFb;
  uint8 thmd_st_ptcRlyFlt;
  uint8 thmd_st_ptc3ConnStsFb;
  uint8 thmd_st_ptc3RlyFlt;
  uint8 thmd_st_acwpSpdReq;
  float32 thmd_t_acwpTemp_C;
  uint8 thmd_st_acwpRun;
  uint8 thmd_st_acwpHeat;
} vcsb_THSM;

#endif

/* PublicStructure Variables for Internal Data, for system '<S3>/SR_latch1' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S19>/Unit Delay' */
} ARID_DEF_SR_latch1_swc_THSM_T;

/* PublicStructure Variables for Internal Data, for system '<S20>/SR_latch' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S24>/Unit Delay' */
} ARID_DEF_SR_latch_swc_THSM_T;

/* PublicStructure Variables for Internal Data, for system '<S25>/timed_delay' */
typedef struct {
  float32 t_wait;                      /* '<S25>/timed_delay' */
  uint8 is_c12_swc_THSM;               /* '<S25>/timed_delay' */
  uint8 is_active_c12_swc_THSM;        /* '<S25>/timed_delay' */
} ARID_DEF_timed_delay_swc_THSM_T;

/* PublicStructure Variables for Internal Data, for system '<S20>/turnOFF_delay' */
typedef struct {
  ARID_DEF_timed_delay_swc_THSM_T ARID_DEF_timed_delay;/* '<S25>/timed_delay' */
} ARID_DEF_turnOFF_delay_swc_TH_T;

/* PublicStructure Variables for Internal Data, for system '<S70>/timed_delay' */
typedef struct {
  float32 t_wait;                      /* '<S70>/timed_delay' */
  uint8 is_c9_swc_THSM;                /* '<S70>/timed_delay' */
  uint8 is_active_c9_swc_THSM;         /* '<S70>/timed_delay' */
} ARID_DEF_timed_delay_swc_TH_c_T;

/* PublicStructure Variables for Internal Data, for system '<S36>/turnON_delay' */
typedef struct {
  ARID_DEF_timed_delay_swc_TH_c_T ARID_DEF_timed_delay;/* '<S70>/timed_delay' */
} ARID_DEF_turnON_delay_swc_THS_T;

/* PublicStructure Variables for Internal Data, for system '<S10>/SR_latch2' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S133>/Unit Delay' */
} ARID_DEF_SR_latch2_swc_THSM_T;

/* PublicStructure Variables for Internal Data, for system '<S10>/SR_latch3' */
typedef struct {
  boolean UnitDelay_DSTATE;            /* '<S134>/Unit Delay' */
} ARID_DEF_SR_latch3_swc_THSM_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_turnON_delay_swc_THS_T ARID_DEF_turnON_delay1;/* '<S207>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_THS_T ARID_DEF_turnON_delay;/* '<S207>/turnON_delay' */
  ARID_DEF_turnON_delay_swc_THS_T ARID_DEF_turnON_delay1_m;/* '<S202>/turnON_delay1' */
  ARID_DEF_turnON_delay_swc_THS_T ARID_DEF_turnON_delay_c;/* '<S202>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_TH_T ARID_DEF_turnOFF_delay;/* '<S148>/turnOFF_delay' */
  ARID_DEF_turnOFF_delay_swc_TH_T ARID_DEF_turnOFF_delay_k;/* '<S147>/turnOFF_delay' */
  ARID_DEF_timed_delay_swc_TH_c_T ARID_DEF_timed_delay;/* '<S138>/timed_delay' */
  ARID_DEF_timed_delay_swc_THSM_T ARID_DEF_timed_delay_c;/* '<S136>/timed_delay' */
  ARID_DEF_SR_latch3_swc_THSM_T ARID_DEF_SR_latch3;/* '<S10>/SR_latch3' */
  ARID_DEF_SR_latch2_swc_THSM_T ARID_DEF_SR_latch2;/* '<S10>/SR_latch2' */
  ARID_DEF_SR_latch1_swc_THSM_T ARID_DEF_SR_latch1;/* '<S10>/SR_latch1' */
  ARID_DEF_turnON_delay_swc_THS_T ARID_DEF_turnON_delay_b;/* '<S37>/turnON_delay' */
  ARID_DEF_turnON_delay_swc_THS_T ARID_DEF_turnON_delay_p;/* '<S36>/turnON_delay' */
  ARID_DEF_turnOFF_delay_swc_TH_T ARID_DEF_turnOFF_delay_c;/* '<S34>/turnOFF_delay' */
  ARID_DEF_turnOFF_delay_swc_TH_T ARID_DEF_turnOFF_delay_f;/* '<S33>/turnOFF_delay' */
  ARID_DEF_turnOFF_delay_swc_TH_T ARID_DEF_turnOFF_delay2;/* '<S20>/turnOFF_delay2' */
  ARID_DEF_turnOFF_delay_swc_TH_T ARID_DEF_turnOFF_delay1;/* '<S20>/turnOFF_delay1' */
  ARID_DEF_turnOFF_delay_swc_TH_T ARID_DEF_turnOFF_delay_g;/* '<S20>/turnOFF_delay' */
  ARID_DEF_SR_latch_swc_THSM_T ARID_DEF_SR_latch;/* '<S20>/SR_latch' */
  ARID_DEF_SR_latch1_swc_THSM_T ARID_DEF_SR_latch1_g;/* '<S3>/SR_latch1' */
  float64 DataTypeConversion139;       /* '<Root>/Data Type Conversion139' */
  float64 DataTypeConversion144;       /* '<Root>/Data Type Conversion144' */
  float64 DataTypeConversion145;       /* '<Root>/Data Type Conversion145' */
  float64 DataTypeConversion149;       /* '<Root>/Data Type Conversion149' */
  float64 DataTypeConversion151;       /* '<Root>/Data Type Conversion151' */
  float64 DataTypeConversion152;       /* '<Root>/Data Type Conversion152' */
  float64 DataTypeConversion153;       /* '<Root>/Data Type Conversion153' */
  float64 DataTypeConversion150;       /* '<Root>/Data Type Conversion150' */
  float64 DataTypeConversion3;         /* '<Root>/Data Type Conversion3' */
  float64 OutportBufferForthmd_b_PassCool;
  float64 OutportBufferForthmd_n_wtrPmp2T;/* '<S2>/WaterPumpsManagement' */
  float64 OutportBufferForthmd_q_pmp2Flow;/* '<S2>/WaterPumpsManagement' */
  float64 OutportBufferForthmd_n_MHGVTgt_;
  float64 OutportBufferForthmd_n_FWFVTgt_;
  float64 OutportBufferForthmd_b_ActiveCo;
  float64 OutportBufferForthmd_b_BalanceH;
  float64 OutportBufferForthmd_b_PassHeat;
  float64 OutportBufferForthmd_b_hvbDeft;
  float64 OutportBufferForthmd_b_iptcHtIp;
  float64 OutportBufferForthmd_b_iptcHt_h;
  float64 OutportBufferForthmd_b_ipuResvH;
  float64 OutportBufferForthmd_b_ipuSupHt;
  float64 OutportBufferForthmd_b_ipuHeatE;
  float64 OutportBufferForthmd_pwr_ipuHea;
  float32 DataTypeConversion11;        /* '<Root>/Data Type Conversion11' */
  float32 DataTypeConversion27;        /* '<Root>/Data Type Conversion27' */
  float32 DataTypeConversion31;        /* '<Root>/Data Type Conversion31' */
  float32 DataTypeConversion21;        /* '<Root>/Data Type Conversion21' */
  float32 DataTypeConversion39;        /* '<Root>/Data Type Conversion39' */
  float32 DataTypeConversion33;        /* '<Root>/Data Type Conversion33' */
  float32 DataTypeConversion120;       /* '<Root>/Data Type Conversion120' */
  float32 DataTypeConversion2;         /* '<Root>/Data Type Conversion2' */
  float32 thmd_n_fan1TgtSpd_pct_b;     /* '<S8>/Signal Conversion' */
  float32 thmd_n_fan2TgtSpd_pct;       /* '<S8>/Signal Conversion1' */
  float32 SignalConversion;            /* '<S147>/Signal Conversion' */
  float32 UnitDelay_DSTATE;            /* '<S20>/Unit Delay' */
  float32 DelayOneStep1_DSTATE_m;      /* '<S147>/Delay One Step1' */
  float32 DelayOneStep1_DSTATE_j;      /* '<S148>/Delay One Step1' */
  float32 UnitDelay2_DSTATE;           /* '<S172>/Unit Delay2' */
  float32 UnitDelay1_DSTATE;           /* '<S164>/Unit Delay1' */
  float32 UnitDelay_DSTATE_k;          /* '<S164>/Unit Delay' */
  float32 UnitDelay3_DSTATE_p;         /* '<S167>/Unit Delay3' */
  float32 UnitDelay2_DSTATE_n;         /* '<S167>/Unit Delay2' */
  float32 UnitDelay1_DSTATE_a;         /* '<S162>/Unit Delay1' */
  float32 UnitDelay_DSTATE_m;          /* '<S162>/Unit Delay' */
  float32 UnitDelay3_DSTATE_d;         /* '<S165>/Unit Delay3' */
  float32 UnitDelay2_DSTATE_p;         /* '<S165>/Unit Delay2' */
  float32 UnitDelay5_DSTATE;           /* '<S168>/Unit Delay5' */
  float32 UnitDelay4_DSTATE;           /* '<S168>/Unit Delay4' */
  float32 UnitDelay7_DSTATE;           /* '<S170>/Unit Delay7' */
  float32 UnitDelay6_DSTATE;           /* '<S170>/Unit Delay6' */
  float32 UnitDelay3_DSTATE_n;         /* '<S173>/Unit Delay3' */
  float32 UnitDelay2_DSTATE_c;         /* '<S173>/Unit Delay2' */
  float32 UnitDelay1_DSTATE_h;         /* '<S163>/Unit Delay1' */
  float32 UnitDelay_DSTATE_b;          /* '<S163>/Unit Delay' */
  float32 UnitDelay3_DSTATE_b;         /* '<S166>/Unit Delay3' */
  float32 UnitDelay2_DSTATE_i;         /* '<S166>/Unit Delay2' */
  float32 UnitDelay5_DSTATE_g;         /* '<S169>/Unit Delay5' */
  float32 UnitDelay4_DSTATE_g;         /* '<S169>/Unit Delay4' */
  float32 UnitDelay7_DSTATE_o;         /* '<S171>/Unit Delay7' */
  float32 UnitDelay6_DSTATE_g;         /* '<S171>/Unit Delay6' */
  float32 UnitDelay3_DSTATE_p1;        /* '<S174>/Unit Delay3' */
  float32 UnitDelay2_DSTATE_o;         /* '<S174>/Unit Delay2' */
  float32 UnitDelay6_DSTATE_gi;        /* '<S80>/Unit Delay6' */
  float32 UnitDelay7_DSTATE_og;        /* '<S82>/Unit Delay7' */
  float32 UnitDelay6_DSTATE_i;         /* '<S82>/Unit Delay6' */
  float32 UnitDelay7_DSTATE_l;         /* '<S86>/Unit Delay7' */
  float32 UnitDelay6_DSTATE_o;         /* '<S86>/Unit Delay6' */
  float32 UnitDelay7_DSTATE_d;         /* '<S88>/Unit Delay7' */
  float32 UnitDelay6_DSTATE_o4;        /* '<S88>/Unit Delay6' */
  float32 UnitDelay7_DSTATE_f;         /* '<S92>/Unit Delay7' */
  float32 UnitDelay6_DSTATE_a;         /* '<S92>/Unit Delay6' */
  float32 UnitDelay7_DSTATE_k;         /* '<S84>/Unit Delay7' */
  float32 UnitDelay6_DSTATE_n;         /* '<S84>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_k;         /* '<S81>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_l;         /* '<S83>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_f;         /* '<S87>/Unit Delay6' */
  float32 UnitDelay7_DSTATE_m;         /* '<S89>/Unit Delay7' */
  float32 UnitDelay6_DSTATE_h;         /* '<S89>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_b;         /* '<S93>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_p;         /* '<S85>/Unit Delay6' */
  float32 UnitDelay2_DSTATE_d;         /* '<S90>/Unit Delay2' */
  float32 UnitDelay3_DSTATE_j;         /* '<S90>/Unit Delay3' */
  float32 UnitDelay2_DSTATE_e;         /* '<S91>/Unit Delay2' */
  float32 UnitDelay6_DSTATE_oi;        /* '<S64>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_gk;        /* '<S66>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_oh;        /* '<S67>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_g3;        /* '<S69>/Unit Delay6' */
  float32 UnitDelay6_DSTATE_fq;        /* '<S65>/Unit Delay6' */
  float32 UnitDelay2_DSTATE_dp;        /* '<S68>/Unit Delay2' */
  float32 DelayOneStep1_DSTATE_c;      /* '<S34>/Delay One Step1' */
  float32 DelayOneStep1_DSTATE_f;      /* '<S33>/Delay One Step1' */
  float32 t_wait;                      /* '<S137>/timed_delay' */
  float32 t_wait_b;                    /* '<S135>/timed_delay' */
  float32 t_wait_n;                    /* '<S118>/timed_debounce' */
  float32 t_wait_g;                    /* '<S117>/timed_debounce' */
  float32 t_wait_i;                    /* '<S116>/timed_debounce' */
  float32 t_wait_j;                    /* '<S115>/timed_debounce' */
  float32 T;                           /* '<S3>/AccmOnOffProtection' */
  uint32 Counter;                      /* '<S11>/Chart' */
  uint8 DataTypeConversion1;           /* '<Root>/Data Type Conversion1' */
  uint8 DataTypeConversion34;          /* '<Root>/Data Type Conversion34' */
  uint8 DataTypeConversion35;          /* '<Root>/Data Type Conversion35' */
  uint8 DataTypeConversion140;         /* '<Root>/Data Type Conversion140' */
  uint8 DataTypeConversion146;         /* '<Root>/Data Type Conversion146' */
  uint8 DataTypeConversion147;         /* '<Root>/Data Type Conversion147' */
  uint8 DataTypeConversion148;         /* '<Root>/Data Type Conversion148' */
  uint8 OutportBufferForthmd_st_ptcRlyV;/* '<S2>/ptcFaultStatusControl' */
  uint8 OutportBufferForthmd_st_acceRly;/* '<S13>/Constant' */
  uint8 Switch;                        /* '<S202>/Switch' */
  uint8 Switch1;                       /* '<S202>/Switch1' */
  PmmStatus DataTypeConversion25;      /* '<Root>/Data Type Conversion25' */
  GearLeverPos DataTypeConversion62;   /* '<Root>/Data Type Conversion62' */
  BrakePedalStatus DataTypeConversion118;/* '<Root>/Data Type Conversion118' */
  uint8 is_c27_swc_THSM;               /* '<S11>/Chart' */
  uint8 is_WaterPumpMode_NormWork;     /* '<S11>/Chart' */
  uint8 is_active_c27_swc_THSM;        /* '<S11>/Chart' */
  uint8 is_c20_swc_THSM;               /* '<S137>/timed_delay' */
  uint8 is_active_c20_swc_THSM;        /* '<S137>/timed_delay' */
  uint8 is_c18_swc_THSM;               /* '<S135>/timed_delay' */
  uint8 is_active_c18_swc_THSM;        /* '<S135>/timed_delay' */
  uint8 is_c17_swc_THSM;               /* '<S118>/timed_debounce' */
  uint8 is_active_c17_swc_THSM;        /* '<S118>/timed_debounce' */
  uint8 is_c16_swc_THSM;               /* '<S117>/timed_debounce' */
  uint8 is_active_c16_swc_THSM;        /* '<S117>/timed_debounce' */
  uint8 is_c15_swc_THSM;               /* '<S116>/timed_debounce' */
  uint8 is_active_c15_swc_THSM;        /* '<S116>/timed_debounce' */
  uint8 is_c13_swc_THSM;               /* '<S115>/timed_debounce' */
  uint8 is_active_c13_swc_THSM;        /* '<S115>/timed_debounce' */
  uint8 is_c11_swc_THSM;               /* '<S3>/AccmOnOffProtection' */
  uint8 is_active_c11_swc_THSM;        /* '<S3>/AccmOnOffProtection' */
  boolean DataTypeConversion22;        /* '<Root>/Data Type Conversion22' */
  boolean DataTypeConversion29;        /* '<Root>/Data Type Conversion29' */
  boolean DataTypeConversion65;        /* '<Root>/Data Type Conversion65' */
  boolean DataTypeConversion111;       /* '<Root>/Data Type Conversion111' */
  boolean DataTypeConversion64;        /* '<Root>/Data Type Conversion64' */
  boolean DataTypeConversion138;       /* '<Root>/Data Type Conversion138' */
  boolean DataTypeConversion143;       /* '<Root>/Data Type Conversion143' */
  boolean DataTypeConversion154;       /* '<Root>/Data Type Conversion154' */
  boolean DataTypeConversion155;       /* '<Root>/Data Type Conversion155' */
  boolean DataTypeConversion12;        /* '<Root>/Data Type Conversion12' */
  boolean DataTypeConversion15;        /* '<Root>/Data Type Conversion15' */
  boolean flg_WaterPumpMode;           /* '<S11>/Chart' */
  boolean flg_out;                     /* '<S138>/timed_delay' */
  boolean flg_out_j;                   /* '<S136>/timed_delay' */
  boolean DelayInput1_DSTATE;          /* '<S21>/Delay Input1' */
  boolean DelayInput1_DSTATE_k;        /* '<S22>/Delay Input1' */
  boolean DelayInput1_DSTATE_i;        /* '<S144>/Delay Input1' */
  boolean DelayInput1_DSTATE_j;        /* '<S151>/Delay Input1' */
  boolean DelayInput1_DSTATE_n;        /* '<S158>/Delay Input1' */
  boolean UnitDelay_DSTATE_i;          /* '<S37>/Unit Delay' */
  boolean UnitDelay_DSTATE_f;          /* '<S36>/Unit Delay' */
  boolean DelayInput1_DSTATE_nm;       /* '<S46>/Delay Input1' */
  boolean DelayInput1_DSTATE_ny;       /* '<S41>/Delay Input1' */
  boolean Relay3_Mode;                 /* '<S7>/Relay3' */
  boolean Relay2_Mode;                 /* '<S7>/Relay2' */
  boolean Relay4_Mode;                 /* '<S7>/Relay4' */
  boolean Relay1_Mode;                 /* '<S7>/Relay1' */
  boolean Relay_Mode;                  /* '<S9>/Relay' */
  boolean Relay1_Mode_j;               /* '<S9>/Relay1' */
  boolean Relay2_Mode_g;               /* '<S9>/Relay2' */
  boolean Relay3_Mode_o;               /* '<S9>/Relay3' */
  boolean Relay4_Mode_o;               /* '<S9>/Relay4' */
  boolean icLoad;                      /* '<S147>/Delay One Step1' */
  boolean icLoad_n;                    /* '<S148>/Delay One Step1' */
  boolean Relay5_Mode;                 /* '<S150>/Relay5' */
  boolean Relay3_Mode_d;               /* '<S150>/Relay3' */
  boolean Relay4_Mode_d;               /* '<S150>/Relay4' */
  boolean ptc1FaultStatus_MODE;        /* '<S14>/ptc1FaultStatus' */
  boolean ptc3FaultStatusControl_MODE; /* '<S2>/ptc3FaultStatusControl' */
  boolean ptc3FaultStatus_MODE;        /* '<S13>/ptc3FaultStatus' */
} ARID_DEF_swc_THSM_T;

/* Invariant block signals for system '<S20>/SR_latch' */
typedef struct {
  const boolean LogicalOperator1;      /* '<S24>/Logical Operator1' */
} ConstB_SR_latch_swc_THSM_T;

/* Invariant block signals (default storage) */
typedef struct {
  const float64 DataTypeConversion1;   /* '<S11>/Data Type Conversion1' */
  const float32 DataTypeConversion;    /* '<S7>/Data Type Conversion' */
  const float32 DataTypeConversion1_m; /* '<S7>/Data Type Conversion1' */
  const float32 DataTypeConversion2;   /* '<S7>/Data Type Conversion2' */
  const float32 DataTypeConversion3;   /* '<S7>/Data Type Conversion3' */
  uint8 DataTypeConversion85;          /* '<Root>/Data Type Conversion85' */
  uint8 DataTypeConversion90;          /* '<Root>/Data Type Conversion90' */
  const uint8 Constant;                /* '<S14>/Constant' */
  boolean DataTypeConversion83;        /* '<Root>/Data Type Conversion83' */
  boolean DataTypeConversion86;        /* '<Root>/Data Type Conversion86' */
  boolean DataTypeConversion88;        /* '<Root>/Data Type Conversion88' */
  boolean DataTypeConversion89;        /* '<Root>/Data Type Conversion89' */
  boolean DataTypeConversion91;        /* '<Root>/Data Type Conversion91' */
  boolean DataTypeConversion96;        /* '<Root>/Data Type Conversion96' */
  const boolean LogicalOperator1;      /* '<S20>/Logical Operator1' */
  ConstB_SR_latch_swc_THSM_T SR_latch; /* '<S20>/SR_latch' */
} ConstB_swc_THSM_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable_maxIndex
   * Referenced by: '<S63>/2-D Lookup Table'
   */
  uint32 uDLookupTable_maxIndex[2];
} ConstP_swc_THSM_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_swc_THSM_T swc_THSM_ARID_DEF;
extern const ConstB_swc_THSM_T swc_THSM_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_swc_THSM_T swc_THSM_ConstP;

/* Exported data declaration */
#define swc_THSM_START_SEC_CONST_VOLATILE
#include "swc_THSM_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_CAL */
extern const volatile boolean thmc_b_diHVBHeatEnadCnd;/* Referenced by: '<S7>/Constant1' */

/* disable water pump1 stop function in battery heating. */
extern const volatile boolean thmc_b_enaIntelChgAfterRun;/* Referenced by: '<S20>/Constant6' */

/* Enable after-run after inteligent charge */
extern const volatile boolean thmc_b_enaLongerAfterRun;/* Referenced by: '<S20>/Constant3' */

/* Enable longer after-run if temperatures are not yet acceptable */
extern const volatile boolean thmc_b_enaShorterAfterRun;/* Referenced by: '<S20>/Constant2' */

/* Enable shorter after-run if temperatures are already acceptable */
extern const volatile boolean thmc_b_fanRly1Dflt;/* Referenced by: '<S32>/Constant1' */

/* Fan Request relay 1 default value */
extern const volatile boolean thmc_b_fanRly2Dflt;/* Referenced by: '<S32>/Constant3' */

/* Fan Request relay 2 default value */
extern const volatile boolean thmc_b_nonFillingFlg;/* Referenced by: '<S11>/Constant' */
extern const volatile boolean thmc_b_onlyfterRunAcv;/* Referenced by:
                                                     * '<S36>/Constant8'
                                                     * '<S37>/Constant8'
                                                     */
extern const volatile boolean thmc_b_wtrPmpRly1Dflt;/* Referenced by: '<S149>/Constant1' */

/* Water Pump Request relay 1 default value */
extern const volatile boolean thmc_b_wtrPmpRly2Dflt;/* Referenced by: '<S149>/Constant3' */

/* Water Pump Request relay 2 default value */
extern const volatile float32 thmc_n_Fan1SpdIni_pct;/* Referenced by:
                                                     * '<S36>/Constant12'
                                                     * '<S37>/Constant12'
                                                     */
extern const volatile float32 thmc_n_Fan1SpdOff_pct;/* Referenced by: '<S37>/Constant11' */
extern const volatile float32 thmc_n_fan120SpdReqFltSts_pct;/* Referenced by: '<S33>/Constant3' */
extern const volatile float32 thmc_n_fan1SpdOffAirCl_pct;/* Referenced by: '<S36>/Constant11' */
extern const volatile boolean thmc_n_fan1SpdReqEnable;/* Referenced by: '<S33>/Constant5' */
extern const volatile boolean thmc_n_fan1SpdReqEnbAirCl;/* Referenced by: '<S34>/Constant5' */
extern const volatile float32 thmc_n_fan1SpdReqFltAirCl_pct;/* Referenced by: '<S34>/Constant1' */

/* Air Cool Fan1 Request during fault status */
extern const volatile float32 thmc_n_fan1SpdReqFltSts_pct;/* Referenced by: '<S33>/Constant1' */

/* Fan1 Request during fault status */
extern const volatile float32 thmc_n_fan1SpdReqOffAirCl_pct;/* Referenced by:
                                                             * '<S34>/Constant2'
                                                             * '<S34>/Constant3'
                                                             */

/* Fan1 Request during OFF */
extern const volatile float32 thmc_n_fan1SpdReqOff_pct;/* Referenced by:
                                                        * '<S33>/Constant2'
                                                        * '<S33>/Constant7'
                                                        * '<S37>/Constant14'
                                                        */

/* Fan1 Request during OFF */
extern const volatile float32 thmc_n_fan1SpdReqfull_pct;/* Referenced by:
                                                         * '<S33>/Constant6'
                                                         * '<S34>/Constant6'
                                                         */
extern const volatile float32 thmc_n_fanMaxSpd_rpm;/* Referenced by:
                                                    * '<S33>/Constant4'
                                                    * '<S34>/Constant4'
                                                    */

/* Fan Max Speed */
extern const volatile float32 thmc_n_pmp1BalceTgtSpd_pct;/* Referenced by: '<S147>/Constant14' */
extern const volatile float32 thmc_n_pmp1BmshThemReqTgtSpd_pct;/* Referenced by: '<S147>/Constant1' */
extern const volatile float32 thmc_n_pmp1CoolChrTgtSpd_pct;/* Referenced by: '<S147>/Constant5' */
extern const volatile float32 thmc_n_pmp1CoolUnChrTgtSpd_pct;/* Referenced by: '<S147>/Constant6' */
extern const volatile float32 thmc_n_pmp1DefTgtSpd_pct;/* Referenced by:
                                                        * '<S147>/Constant13'
                                                        * '<S147>/Constant2'
                                                        * '<S147>/Constant3'
                                                        * '<S147>/Constant7'
                                                        * '<S147>/Constant8'
                                                        * '<S192>/Constant'
                                                        */
extern const volatile float32 thmc_n_pmp1FltStsTgtSpd_pct;/* Referenced by: '<S147>/Constant15' */
extern const volatile float32 thmc_n_pmp1NonVacFillTgtSpd_pct;/* Referenced by: '<S147>/Constant11' */
extern const volatile float32 thmc_n_pmp2FltTgtSpdAirCl_pct;/* Referenced by: '<S148>/Constant15' */
extern const volatile float32 thmc_n_pmp2HiSpdReqDis_pct;/* Referenced by: '<S150>/Relay5' */

/* Water Pump 2 Request threshold for disable high speed */
extern const volatile float32 thmc_n_pmp2HiSpdReqEna_pct;/* Referenced by: '<S150>/Relay5' */

/* Water Pump 2 Request threshold for enable high speed */
extern const volatile float32 thmc_n_pmp2LoSpdReqDis_pct;/* Referenced by: '<S150>/Relay4' */

/* Water Pump 2 Request threshold for disable low speed */
extern const volatile float32 thmc_n_pmp2LoSpdReqEna_pct;/* Referenced by: '<S150>/Relay4' */

/* Water Pump 2 Request threshold for enable low speed */
extern const volatile float32 thmc_n_pmp2MedSpdReqDis_pct;/* Referenced by: '<S150>/Relay3' */

/* Water Pump 2 Request threshold for disable medium speed */
extern const volatile float32 thmc_n_pmp2MedSpdReqEna_pct;/* Referenced by: '<S150>/Relay3' */

/* Water Pump 2 Request threshold for enable medium speed */
extern const volatile float32 thmc_n_pmp2NonVacTgtSpdAirCl_pct;/* Referenced by: '<S148>/Constant11' */
extern const volatile float32 thmc_n_pmp2StopTgtSpdAirCl_pct;/* Referenced by:
                                                              * '<S148>/Constant'
                                                              * '<S148>/Constant2'
                                                              */
extern const volatile float32 thmc_n_wtrPmp1MaxSpd_rpm;/* Referenced by: '<S147>/Constant4' */

/* Water Pump 1 Max Speed */
extern const volatile float32 thmc_n_wtrPmp2MaxSpd_rpm;/* Referenced by: '<S148>/Constant4' */

/* Water Pump 2 Max Speed */
extern const volatile uint8 thmc_st_fanReqStatusDflt;/* Referenced by: '<S35>/Constant3' */

/* Fan Request Status default value */
extern const volatile uint8 thmc_st_pmp1ReqStatusDflt;/* Referenced by: '<S150>/Constant3' */

/* Pump 1 Request Status default value */
extern const volatile uint8 thmc_st_pmp2ReqStatusDflt;/* Referenced by: '<S150>/Constant2' */

/* Pump 2 Request Status default value */
extern const volatile float32 thmc_t_acewpDisTemp_C;/* Referenced by: '<S10>/Constant' */
extern const volatile float32 thmc_t_dcdcOverTempDw_C;/* Referenced by: '<S9>/Relay2' */
extern const volatile float32 thmc_t_dcdcOverTempUp_C;/* Referenced by: '<S9>/Relay2' */
extern const volatile float32 thmc_t_ewpOutFltThrDw;/* Referenced by: '<S114>/Lower Limit' */
extern const volatile float32 thmc_t_ewpOutFltThrUp;/* Referenced by: '<S114>/Upper Limit' */
extern const volatile float32 thmc_t_fanEnaInvHiThd_C;/* Referenced by: '<S7>/Relay2' */

/* Fan enable TMM inverter temperature high threshold */
extern const volatile float32 thmc_t_fanEnaInvLoThd_C;/* Referenced by: '<S7>/Relay2' */

/* Fan enable TMM inverter temperature low threshold */
extern const volatile float32 thmc_t_fanEnaMotHiThd_C;/* Referenced by: '<S7>/Relay3' */

/* Fan enable TMM motor temperature high threshold */
extern const volatile float32 thmc_t_fanEnaMotLoThd_C;/* Referenced by: '<S7>/Relay3' */

/* Fan enable TMM motor temperature low threshold */
extern const volatile float32 thmc_t_inv2OverTempDw_C;/* Referenced by: '<S9>/Relay1' */
extern const volatile float32 thmc_t_inv2OverTempUp_C;/* Referenced by: '<S9>/Relay1' */
extern const volatile float32 thmc_t_mot2OverTempDw_C;/* Referenced by: '<S9>/Relay' */
extern const volatile float32 thmc_t_mot2OverTempUp_C;/* Referenced by: '<S9>/Relay' */
extern const volatile float32 thmc_t_ts5LowTempDw_C;/* Referenced by: '<S9>/Relay4' */
extern const volatile float32 thmc_t_ts5LowTempUp_C;/* Referenced by: '<S9>/Relay4' */
extern const volatile float32 thmc_t_ts5OverTempDw_C;/* Referenced by: '<S9>/Relay3' */
extern const volatile float32 thmc_t_ts5OverTempUp_C;/* Referenced by: '<S9>/Relay3' */
extern const volatile float32 thmc_t_wtrPmp2EnaInvHiThd_C;/* Referenced by: '<S7>/Relay1' */

/* Water Pump enable TMM inverter temperature high threshold */
extern const volatile float32 thmc_t_wtrPmp2EnaInvLoThd_C;/* Referenced by: '<S7>/Relay1' */

/* Water Pump enable TMM inverter temperature low threshold */
extern const volatile float32 thmc_t_wtrPmp2EnaMotHiThd_C;/* Referenced by: '<S7>/Relay4' */

/* Water Pump enable TMM motor temperature high threshold */
extern const volatile float32 thmc_t_wtrPmp2EnaMotLoThd_C;/* Referenced by: '<S7>/Relay4' */

/* Water Pump enable TMM motor temperature low threshold */
extern const volatile float32 thmc_tm_Fan115OffDlyAirCl_s;/* Referenced by: '<S34>/Constant10' */
extern const volatile float32 thmc_tm_Fan115OffDly_s;/* Referenced by: '<S33>/Constant10' */
extern const volatile float32 thmc_tm_Fan1EnbDly_s;/* Referenced by:
                                                    * '<S36>/Constant10'
                                                    * '<S37>/Constant10'
                                                    */
extern const volatile float32 thmc_tm_FltStsOffDly_s;/* Referenced by:
                                                      * '<S9>/Constant1'
                                                      * '<S9>/Constant11'
                                                      * '<S9>/Constant4'
                                                      * '<S9>/Constant7'
                                                      */

/* Fault status hold time */
extern const volatile float32 thmc_tm_FltStsOnDly_s;/* Referenced by:
                                                     * '<S9>/Constant2'
                                                     * '<S9>/Constant5'
                                                     * '<S9>/Constant8'
                                                     * '<S9>/Constant9'
                                                     */

/* Fault status hold time */
extern const volatile float32 thmc_tm_Pump215OffDlyAirCl_s;/* Referenced by: '<S148>/Constant10' */
extern const volatile float32 thmc_tm_Pump215OffDly_s;/* Referenced by: '<S147>/Constant10' */
extern const volatile float32 thmc_tm_accmRstLim_s;/* Referenced by: '<S3>/Constant7' */

/* ACCM enable reset time */
extern const volatile float32 thmc_tm_maxAfterRunTime_s;/* Referenced by:
                                                         * '<S20>/Constant5'
                                                         * '<S20>/Constant7'
                                                         */

/* Max after-run time */
extern const volatile float32 thmc_tm_ptc3DlyCan_s;/* Referenced by: '<S10>/Constant6' */

/* ptc3 Can signal delayed sent */
extern const volatile float32 thmc_tm_ptc3DlyHw_s;/* Referenced by: '<S10>/Constant8' */

/* ptc3 HW signal delayed stop */
extern const volatile float32 thmc_tm_ptc3VoltFaultThr1_s;/* Referenced by: '<S202>/Constant8' */
extern const volatile float32 thmc_tm_ptc3VoltFaultThr_s;/* Referenced by: '<S202>/Constant3' */
extern const volatile float32 thmc_tm_ptcDlyCan_s;/* Referenced by: '<S10>/Constant4' */

/* ptc Can signal delayed sent */
extern const volatile float32 thmc_tm_ptcDlyHw_s;/* Referenced by: '<S10>/Constant1' */

/* ptc HW signal delayed stop */
extern const volatile float32 thmc_tm_ptcVoltFaultThr1_s;/* Referenced by: '<S207>/Constant8' */
extern const volatile float32 thmc_tm_ptcVoltFaultThr_s;/* Referenced by: '<S207>/Constant3' */
extern const volatile float32 thmc_v_hvbInFltThrDw;/* Referenced by: '<S112>/Lower Limit' */
extern const volatile float32 thmc_v_hvbInFltThrUp;/* Referenced by: '<S112>/Upper Limit' */
extern const volatile float32 thmc_v_hvbOutFltThrDw;/* Referenced by: '<S113>/Lower Limit' */
extern const volatile float32 thmc_v_hvbOutFltThrUp;/* Referenced by: '<S113>/Upper Limit' */
extern const volatile float32 thmc_v_ts5FltThrDw;/* Referenced by: '<S111>/Lower Limit' */
extern const volatile float32 thmc_v_ts5FltThrUp;/* Referenced by: '<S111>/Upper Limit' */
extern const volatile float32 thmf_X_ObcEdcpDecPct[7];
                                  /* Referenced by: '<S173>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_ObcEdcpIdleDecPct[7];
                                  /* Referenced by: '<S174>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_ObcEdcpIdleIncPct[7];
                                  /* Referenced by: '<S174>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_ObcEdcpIncPct[7];
                                  /* Referenced by: '<S173>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_PassCoolSnsrTempFan1_t[4];
                                   /* Referenced by: '<S37>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_Pmp2DcdcIdleDecPct[6];
                                  /* Referenced by: '<S166>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_Pmp2DcdcIdleIncPct[6];
                                  /* Referenced by: '<S166>/1D_Lookup_Table1' */
extern const volatile float32 thmf_X_Pmp2McuIdleDecPct[6];
                                  /* Referenced by: '<S169>/1D_Lookup_Table5' */
extern const volatile float32 thmf_X_Pmp2McuIdleIncPct[6];
                                  /* Referenced by: '<S169>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_Pmp2MotorIdleDecPct[6];
                                  /* Referenced by: '<S171>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_Pmp2MotorIdleIncPct[6];
                                  /* Referenced by: '<S171>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_Pmp2SnsrTempIdleDecPct[8];
                                  /* Referenced by: '<S163>/1D_Lookup_Table1' */
extern const volatile float32 thmf_X_Pmp2SnsrTempIdleIncPct[8];
                                   /* Referenced by: '<S163>/1D_Lookup_Table' */
extern const volatile float32 thmf_X_SnsrTempFan1Dec_t[5];
                                   /* Referenced by: '<S80>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_SnsrTempFan1Inc_t[5];
                                   /* Referenced by: '<S80>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_SnsrTempFanDec_t[5];
                                   /* Referenced by: '<S81>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_SnsrTempFanInc_t[4];
                                   /* Referenced by: '<S81>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_dcdcTempFan1DecChr_t[5];
                                   /* Referenced by: '<S84>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_dcdcTempFan1Dec_t[7];
                                   /* Referenced by: '<S82>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_dcdcTempFan1IncChr_t[4];
                                   /* Referenced by: '<S84>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_dcdcTempFan1Inc_t[5];
                                   /* Referenced by: '<S82>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_dcdcTempFanDecChr_t[4];
                                   /* Referenced by: '<S85>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_dcdcTempFanDec_t[6];
                                   /* Referenced by: '<S83>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_dcdcTempFanIncChr_t[3];
                                   /* Referenced by: '<S85>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_dcdcTempFanInc_t[5];
                                   /* Referenced by: '<S83>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_fan1DcdcTempChgDecAirCl_t[8];
                                   /* Referenced by: '<S65>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_fan1DcdcTempChgIncAirCl_t[8];
                                   /* Referenced by: '<S65>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_fan1VehSpdAirCl_kph[5];
                                   /* Referenced by: '<S63>/2-D Lookup Table' */
extern const volatile float32 thmf_X_fan1dcdcTempDecAirCl_t[7];
                                   /* Referenced by: '<S64>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_fan1dcdcTempIncAirCl_t[7];
                                   /* Referenced by: '<S64>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_fan1inv2TempDecAirCl_t[7];
                                   /* Referenced by: '<S66>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_fan1inv2TempIncAirCl_t[7];
                                   /* Referenced by: '<S66>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_fan1mot2TempDecAirCl_t[8];
                                   /* Referenced by: '<S67>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_fan1mot2TempIncAirCl_t[8];
                                   /* Referenced by: '<S67>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_fan1obcTempChgDecAirCl_t[6];
                                   /* Referenced by: '<S68>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_fan1obcTempChgIncAirCl_t[6];
                                   /* Referenced by: '<S68>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_fan1ts5TempChgDecAirCl_t[8];
                                   /* Referenced by: '<S69>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_fan1ts5TempChgIncAirCl_t[8];
                                   /* Referenced by: '<S69>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_inv2TempFan1Dec_t[7];
                                   /* Referenced by: '<S86>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_inv2TempFan1Inc_t[5];
                                   /* Referenced by: '<S86>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_inv2TempFanDec_t[6];
                                   /* Referenced by: '<S87>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_inv2TempFanInc_t[5];
                                   /* Referenced by: '<S87>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_mot2TempFan1lowDec_t[7];
                                   /* Referenced by: '<S88>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_mot2TempFan1lowInc_t[5];
                                   /* Referenced by: '<S88>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_mot2TempFanlowDec_t[6];
                                   /* Referenced by: '<S89>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_mot2TempFanlowInc_t[5];
                                   /* Referenced by: '<S89>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_obcTempFan1Dec_t[5];
                                   /* Referenced by: '<S90>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_obcTempFan1Inc_t[4];
                                   /* Referenced by: '<S90>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_obcTempFanDec_t[4];
                                   /* Referenced by: '<S91>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_obcTempFanInc_t[3];
                                   /* Referenced by: '<S91>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_pmp2DcdcTempChgDecAirCl_t[5];
                                  /* Referenced by: '<S167>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_pmp2DcdcTempChgIncAirCl_t[5];
                                  /* Referenced by: '<S167>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_pmp2DcdcTempReqDecAirCl_t[5];
                                  /* Referenced by: '<S165>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_pmp2DcdcTempReqIncAirCl_t[5];
                                  /* Referenced by: '<S165>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_pmp2Inv2TempReqDecAirCl_t[5];
                                  /* Referenced by: '<S168>/1D_Lookup_Table5' */
extern const volatile float32 thmf_X_pmp2Inv2TempReqIncAirCl_t[5];
                                  /* Referenced by: '<S168>/1D_Lookup_Table4' */
extern const volatile float32 thmf_X_pmp2Mot2TempReqDecAirCl_t[5];
                                  /* Referenced by: '<S170>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_pmp2Mot2TempReqIncAirCl_t[5];
                                  /* Referenced by: '<S170>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_pmp2ObcTempDecBig_t[5];
                                  /* Referenced by: '<S172>/1D_Lookup_Table3' */
extern const volatile float32 thmf_X_pmp2ObcTempIncBigAirCl_t[5];
                                  /* Referenced by: '<S172>/1D_Lookup_Table2' */
extern const volatile float32 thmf_X_pmp2SnsrTempChrDecAirCl_t[7];
                                  /* Referenced by: '<S164>/1D_Lookup_Table1' */
extern const volatile float32 thmf_X_pmp2SnsrTempChrIncAirCl_t[7];
                                   /* Referenced by: '<S164>/1D_Lookup_Table' */
extern const volatile float32 thmf_X_pmp2SnsrTempReqDecAirCl_t[7];
                                  /* Referenced by: '<S162>/1D_Lookup_Table1' */
extern const volatile float32 thmf_X_pmp2SnsrTempReqIncAirCl_t[7];
                                   /* Referenced by: '<S162>/1D_Lookup_Table' */
extern const volatile float32 thmf_X_pmp2TgtSpd_pct[9];
                                  /* Referenced by: '<S148>/1-D Lookup Table' */
extern const volatile float32 thmf_X_ts5TempFan1Dec_t[7];
                                   /* Referenced by: '<S92>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_ts5TempFan1Inc_t[5];
                                   /* Referenced by: '<S92>/1D_Lookup_Table6' */
extern const volatile float32 thmf_X_ts5TempFanDec_t[6];
                                   /* Referenced by: '<S93>/1D_Lookup_Table7' */
extern const volatile float32 thmf_X_ts5TempFanInc_t[5];
                                   /* Referenced by: '<S93>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_ObcEdcpDecPct[7];
                                  /* Referenced by: '<S173>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_ObcEdcpIdleDecPct[7];
                                  /* Referenced by: '<S174>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_ObcEdcpIdleIncPct[7];
                                  /* Referenced by: '<S174>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_ObcEdcpIncPct[7];
                                  /* Referenced by: '<S173>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_PassCoolSnsrTempFan1_pct[4];
                                   /* Referenced by: '<S37>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_Pmp2DcdcIdleDecPct[6];
                                  /* Referenced by: '<S166>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_Pmp2DcdcIdleIncPct[6];
                                  /* Referenced by: '<S166>/1D_Lookup_Table1' */
extern const volatile float32 thmf_Y_Pmp2McuIdleDecPct[6];
                                  /* Referenced by: '<S169>/1D_Lookup_Table5' */
extern const volatile float32 thmf_Y_Pmp2McuIdleIncPct[6];
                                  /* Referenced by: '<S169>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_Pmp2MotorIdleDecPct[6];
                                  /* Referenced by: '<S171>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_Pmp2MotorIdleIncPct[6];
                                  /* Referenced by: '<S171>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_Pmp2SnsrTempIdleDecPct[8];
                                  /* Referenced by: '<S163>/1D_Lookup_Table1' */
extern const volatile float32 thmf_Y_Pmp2SnsrTempIdleIncPct[8];
                                   /* Referenced by: '<S163>/1D_Lookup_Table' */
extern const volatile float32 thmf_Y_SnsrTempFan1Dec_pct[5];
                                   /* Referenced by: '<S80>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_SnsrTempFan1Inc_pct[5];
                                   /* Referenced by: '<S80>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_SnsrTempFanDec_pct[5];
                                   /* Referenced by: '<S81>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_SnsrTempFanInc_pct[4];
                                   /* Referenced by: '<S81>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_dcdcTempFan1DecChr_pct[5];
                                   /* Referenced by: '<S84>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_dcdcTempFan1Dec_pct[7];
                                   /* Referenced by: '<S82>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_dcdcTempFan1IncChr_pct[4];
                                   /* Referenced by: '<S84>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_dcdcTempFan1Inc_pct[5];
                                   /* Referenced by: '<S82>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_dcdcTempFanDecChr_pct[4];
                                   /* Referenced by: '<S85>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_dcdcTempFanDec_pct[6];
                                   /* Referenced by: '<S83>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_dcdcTempFanIncChr_pct[3];
                                   /* Referenced by: '<S85>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_dcdcTempFanInc_pct[5];
                                   /* Referenced by: '<S83>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_fan1DcdcTempChgDecAirCl_pct[8];
                                   /* Referenced by: '<S65>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_fan1DcdcTempChgIncAirCl_pct[8];
                                   /* Referenced by: '<S65>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_fan1SnsrTempAirCl_t[7];
                                   /* Referenced by: '<S63>/2-D Lookup Table' */
extern const volatile float32 thmf_Y_fan1dcdcTempDecAirCl_pct[7];
                                   /* Referenced by: '<S64>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_fan1dcdcTempIncAirCl_pct[7];
                                   /* Referenced by: '<S64>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_fan1inv2TempDecAirCl_pct[7];
                                   /* Referenced by: '<S66>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_fan1inv2TempIncAirCl_pct[7];
                                   /* Referenced by: '<S66>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_fan1mot2TempDecAirCl_pct[8];
                                   /* Referenced by: '<S67>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_fan1mot2TempIncAirCl_pct[8];
                                   /* Referenced by: '<S67>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_fan1obcTempChgDecAirCl_pct[6];
                                   /* Referenced by: '<S68>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_fan1obcTempChgIncAirCl_pct[6];
                                   /* Referenced by: '<S68>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_fan1ts5TempChgDecAirCl_pct[8];
                                   /* Referenced by: '<S69>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_fan1ts5TempChgIncAirCl_pct[8];
                                   /* Referenced by: '<S69>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_inv2TempFan1Dec_pct[7];
                                   /* Referenced by: '<S86>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_inv2TempFan1Inc_pct[5];
                                   /* Referenced by: '<S86>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_inv2TempFanDec_pct[6];
                                   /* Referenced by: '<S87>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_inv2TempFanInc_pct[5];
                                   /* Referenced by: '<S87>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_mot2TempFan1lowDec_pct[7];
                                   /* Referenced by: '<S88>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_mot2TempFan1lowInc_pct[5];
                                   /* Referenced by: '<S88>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_mot2TempFanlowDec_pct[6];
                                   /* Referenced by: '<S89>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_mot2TempFanlowInc_pct[5];
                                   /* Referenced by: '<S89>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_obcTempFan1Dec_pct[5];
                                   /* Referenced by: '<S90>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_obcTempFan1Inc_pct[4];
                                   /* Referenced by: '<S90>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_obcTempFanDec_pct[4];
                                   /* Referenced by: '<S91>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_obcTempFanInc_pct[3];
                                   /* Referenced by: '<S91>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_pmp2DcdcTempChgDecAirCl_pct[5];
                                  /* Referenced by: '<S167>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_pmp2DcdcTempChgIncAirCl_pct[5];
                                  /* Referenced by: '<S167>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_pmp2DcdcTempReqDecAirCl_pct[5];
                                  /* Referenced by: '<S165>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_pmp2DcdcTempReqIncAirCl_pct[5];
                                  /* Referenced by: '<S165>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_pmp2FlowFeedback_Lmin[9];
                                  /* Referenced by: '<S148>/1-D Lookup Table' */
extern const volatile float32 thmf_Y_pmp2Inv2TempReqDecAirCl_pct[5];
                                  /* Referenced by: '<S168>/1D_Lookup_Table5' */
extern const volatile float32 thmf_Y_pmp2Inv2TempReqIncAirCl_pct[5];
                                  /* Referenced by: '<S168>/1D_Lookup_Table4' */
extern const volatile float32 thmf_Y_pmp2Mot2TempReqDecAirCl_pct[5];
                                  /* Referenced by: '<S170>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_pmp2Mot2TempReqIncAirCl_pct[5];
                                  /* Referenced by: '<S170>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_pmp2ObcTempDecBig_pct[5];
                                  /* Referenced by: '<S172>/1D_Lookup_Table3' */
extern const volatile float32 thmf_Y_pmp2ObcTempIncBigAirCl_pct[5];
                                  /* Referenced by: '<S172>/1D_Lookup_Table2' */
extern const volatile float32 thmf_Y_pmp2SnsrTempChrDecAirCl_pct[7];
                                  /* Referenced by: '<S164>/1D_Lookup_Table1' */
extern const volatile float32 thmf_Y_pmp2SnsrTempChrIncAirCl_pct[7];
                                   /* Referenced by: '<S164>/1D_Lookup_Table' */
extern const volatile float32 thmf_Y_pmp2SnsrTempReqDecAirCl_pct[7];
                                  /* Referenced by: '<S162>/1D_Lookup_Table1' */
extern const volatile float32 thmf_Y_pmp2SnsrTempReqIncAirCl_pct[7];
                                   /* Referenced by: '<S162>/1D_Lookup_Table' */
extern const volatile float32 thmf_Y_ts5TempFan1Dec_pct[7];
                                   /* Referenced by: '<S92>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_ts5TempFan1Inc_pct[5];
                                   /* Referenced by: '<S92>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Y_ts5TempFanDec_pct[6];
                                   /* Referenced by: '<S93>/1D_Lookup_Table7' */
extern const volatile float32 thmf_Y_ts5TempFanInc_pct[5];
                                   /* Referenced by: '<S93>/1D_Lookup_Table6' */
extern const volatile float32 thmf_Z_fan1SnsrTempAirCl_pct[35];
                                   /* Referenced by: '<S63>/2-D Lookup Table' */

#define swc_THSM_STOP_SEC_CONST_VOLATILE
#include "swc_THSM_MemMap.h"
#define swc_THSM_START_SEC_VAR
#include "swc_THSM_MemMap.h"

/* Declaration for custom storage class: AUTOSAR4_SIG */
extern boolean thmd_b_FaultStsHvbIn_flg;/* '<S116>/timed_debounce' */
extern boolean thmd_b_FaultStsHvbOut_flg;/* '<S117>/timed_debounce' */
extern boolean thmd_b_FaultSts_flg;    /* '<S115>/timed_debounce' */

/* Fault status flg */
extern boolean thmd_b_FaultSts_flg1;   /* '<S9>/Switch' */
extern boolean thmd_b_NonVacFilling_flg;/* '<S11>/Switch' */

/* Non Vacuum filling mode flg */
extern boolean thmd_b_accmEnaCnd1;     /* '<S3>/Logical Operator5' */

/* ACCM Enable condition 1 */
extern boolean thmd_b_accmEnaCnd2;     /* '<S3>/Logical Operator20' */

/* ACCM Enable condition 2 */
extern boolean thmd_b_accmEnaCnd3;     /* '<Root>/Data Type Conversion40' */

/* ACCM Enable condition 3 */
extern boolean thmd_b_accmEnb;         /* '<S3>/AccmOnOffProtection' */
extern boolean thmd_b_accmEnbChrflg;   /* '<S3>/Relational Operator11' */
extern boolean thmd_b_accmEnbRaw;      /* '<S3>/SR_latch1' */
extern boolean thmd_b_accmEnboffChrflg;/* '<S3>/Logical Operator21' */
extern boolean thmd_b_accmEnterEnableFlg;/* '<S3>/Logical Operator1' */
extern boolean thmd_b_accmExitEnableFlg;/* '<S3>/Logical Operator23' */
extern boolean thmd_b_afterRunActive;  /* '<S20>/Logical Operator14' */

/* After-run active for cooling and power-hold */
extern boolean thmd_b_ewpOutTempFaultFlg;/* '<S118>/timed_debounce' */
extern boolean thmd_b_fanCtrlEnabled;  /* '<S7>/Logical Operator1' */

/* Fan Control Enabled */
extern boolean thmd_b_fanRly1Req;      /* '<S38>/Switch' */

/* Fan Relay 1 request */
extern boolean thmd_b_fanRly2Req;      /* '<S39>/Switch' */

/* Fan Relay 2 request */
extern boolean thmd_b_heaterEna2;      /* '<S133>/Logical Operator3' */

/* BPTC Enable */
extern boolean thmd_b_heaterEna3;      /* '<S10>/SR_latch3' */

/* BPTC Enable */
extern boolean thmd_b_heaterEnaCnd1;   /* '<S10>/Logical Operator2' */

/* BPTC Enable condition 1 */
extern boolean thmd_b_heaterEnaCnd2;   /* '<S10>/Relational Operator5' */

/* BPTC Enable condition 2 */
extern boolean thmd_b_iptcEnbCmd2;     /* '<S10>/Logical Operator10' */
extern boolean thmd_b_ptc2EnterEnableFlg;/* '<S10>/Logical Operator11' */
extern boolean thmd_b_ptc2ExitEnableFlg;/* '<S10>/Logical Operator16' */
extern boolean thmd_b_ptc3EnterEnableFlg;/* '<S10>/Logical Operator19' */
extern boolean thmd_b_ptc3ExitEnableFlg;/* '<S10>/Logical Operator24' */
extern boolean thmd_b_ptcCanEnbFlg;    /* '<S137>/timed_delay' */
extern boolean thmd_b_ptcEna;          /* '<S10>/SR_latch1' */

/* PTC Enable */
extern boolean thmd_b_ptcEnterEnableFlg;/* '<S10>/Logical Operator3' */
extern boolean thmd_b_ptcExitEnableFlg;/* '<S10>/Logical Operator6' */
extern boolean thmd_b_ptcHWEnbFlg;     /* '<S135>/timed_delay' */
extern boolean thmd_b_wtrPmp1CtrlEnabled;/* '<S7>/Logical Operator3' */

/* Water Pump 1 Control Enabled */
extern boolean thmd_b_wtrPmp2CtrlEnabled;/* '<S7>/Logical Operator4' */

/* Water Pump 2 Control Enabled */
extern boolean thmd_b_wtrPmpRly1Req;   /* '<S190>/Switch' */

/* Water Pump Relay 1 request */
extern boolean thmd_b_wtrPmpRly2Req;   /* '<S191>/Switch' */

/* Water Pump Relay 2 request */
extern FanStatus thmd_e_fanTgtSts;     /* '<S35>/Switch' */

/* Fan Target Status */
extern PumpStatus thmd_e_wtrPmp1TgtSts;/* '<S150>/Switch4' */

/* Water Pump 1 Target Status */
extern PumpStatus thmd_e_wtrPmp2TgtSts;/* '<S150>/Switch8' */

/* Water Pump 2 Target Status */
extern float32 thmd_n_SnsrTempFan1_pct;/* '<S81>/Switch3' */

/* Fan1 Target Speed PWM BEV acording to SnsrTemp  */
extern float32 thmd_n_dcdcTempChrFan1_pct;/* '<S85>/Switch3' */

/* Fan1 Target Speed in Charge mode PWM BEV acording to SnsrTemp  */
extern float32 thmd_n_dcdcTempFan1_pct;/* '<S83>/Switch3' */

/* Fan1 Target Speed PWM BEV acording to SnsrTemp  */
extern float32 thmd_n_fan1DcdcTempAirCl_pct;/* '<S64>/Switch3' */
extern float32 thmd_n_fan1DcdcTempChrAirCl_pct;/* '<S65>/Switch3' */
extern float32 thmd_n_fan1DelayModTgtSpd_pct;/* '<S33>/Switch2' */
extern float32 thmd_n_fan1DlyTgtSpdAirCl_pct;/* '<S34>/Switch2' */
extern float32 thmd_n_fan1Inv2TempAirCl_pct;/* '<S66>/Switch3' */
extern float32 thmd_n_fan1Mot2TempAirCl_pct;/* '<S67>/Switch3' */
extern float32 thmd_n_fan1SnsrTempAirCl_pct;/* '<S63>/2-D Lookup Table' */
extern float32 thmd_n_fan1TgtSpdAirCl2_pct;/* '<S34>/Switch6' */

/* Fan1 Target Speed PWM */
extern float32 thmd_n_fan1TgtSpdAirCl_pct;/* '<S36>/Switch19' */
extern float32 thmd_n_fan1TgtSpdLdtBev_pct;/* '<S37>/Switch19' */

/* Fan1 Target Speed PWM BEV */
extern float32 thmd_n_fan1TgtSpd_pct;  /* '<S33>/Switch6' */

/* Fan1 Target Speed PWM */
extern float32 thmd_n_fan1obcTempChrAirCl_pct;/* '<S68>/Switch1' */

/* Fan1 Target Speed in Charge mode PWM BEV acording to SnsrTemp  */
extern float32 thmd_n_fan1ts5TempChrAirCl_pct;/* '<S69>/Switch3' */
extern float32 thmd_n_fan300ts5TempTgtSpd_pct;/* '<S80>/Switch3' */
extern float32 thmd_n_inv2TempFan1_pct;/* '<S87>/Switch3' */
extern float32 thmd_n_obcTempChrFan1_pct;/* '<S91>/Switch1' */
extern float32 thmd_n_pmp1FaultTgtSpd_pct;/* '<S147>/Switch11' */
extern float32 thmd_n_pmp1NewTgtSpd_pct;/* '<S147>/Switch1' */

/* HBCP Target Speed  */
extern float32 thmd_n_pmp1SwapTgtSpd_pct;/* '<S147>/Switch6' */
extern float32 thmd_n_pmp2IpuClTgtSpdAirCl_pct;/* '<S148>/Switch' */
extern float32 thmd_n_pmp2Kl15TgtSpdAirCl_pct;/* '<S148>/Switch2' */
extern float32 thmd_n_pmp2ObcTempTgtSpdBigAirCl_pct;/* '<S172>/Switch1' */
extern float32 thmd_n_pmp2TgtSpdAirCl_pct;/* '<S148>/Switch1' */
extern float32 thmd_n_ts5TempChrFan1_pct;/* '<S93>/Switch3' */

/* Fan1 Target Speed in Charge mode PWM BEV acording to SnsrTemp  */
extern float32 thmd_n_wtrPmp1NewTgtSpd_rpm;/* '<S147>/Product2' */

/* HBCP Target Speed */
extern uint8 thmd_st_FanReqCmd;        /* '<S61>/Switch' */

/* Fan Request Command */
extern uint8 thmd_st_acwpHeat;         /* '<S10>/Switch1' */
extern uint8 thmd_st_ptc3ConnStsFb;    /* '<S13>/ptc3FaultStatus' */
extern uint8 thmd_st_ptc3RlyFlt;       /* '<S13>/ptc3FaultStatus' */
extern uint8 thmd_st_ptcConnStsFb;     /* '<S207>/Switch' */
extern uint8 thmd_st_ptcRlyFlt;        /* '<S207>/Switch1' */
extern uint8 thmd_st_wtrPmp1ReqCmd;    /* '<S200>/Switch' */

/* Water Pump 1 Request Command */
extern uint8 thmd_st_wtrPmp2ReqCmd;    /* '<S201>/Switch' */

/* Water Pump 2 Request Command */
extern float32 thmd_t_acwpTemp_C;      /* '<S10>/Switch' */

#define swc_THSM_STOP_SEC_VAR
#include "swc_THSM_MemMap.h"

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
 * '<Root>' : 'swc_THSM'
 * '<S1>'   : 'swc_THSM/THSM__Thermal_System_Manager'
 * '<S2>'   : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl'
 * '<S3>'   : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ACCM_Control'
 * '<S4>'   : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement'
 * '<S5>'   : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Compare To Constant'
 * '<S6>'   : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Compare To Constant1'
 * '<S7>'   : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/EnablingConditions'
 * '<S8>'   : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement'
 * '<S9>'   : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl'
 * '<S10>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control'
 * '<S11>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/NonVacuumFillingControl'
 * '<S12>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement'
 * '<S13>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptc3FaultStatusControl'
 * '<S14>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptcFaultStatusControl'
 * '<S15>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ACCM_Control/AccmOnOffProtection'
 * '<S16>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ACCM_Control/Enumerated Constant'
 * '<S17>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ACCM_Control/Enumerated Constant1'
 * '<S18>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ACCM_Control/Enumerated Constant2'
 * '<S19>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ACCM_Control/SR_latch1'
 * '<S20>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation'
 * '<S21>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/Detect Decrease'
 * '<S22>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/Detect Increase'
 * '<S23>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/Enumerated Constant2'
 * '<S24>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/SR_latch'
 * '<S25>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/turnOFF_delay'
 * '<S26>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/turnOFF_delay1'
 * '<S27>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/turnOFF_delay2'
 * '<S28>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/turnOFF_delay/timed_delay'
 * '<S29>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/turnOFF_delay1/timed_delay'
 * '<S30>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/AfterRunManagement/AfterRunActivation/turnOFF_delay2/timed_delay'
 * '<S31>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/EnablingConditions/Compare To Constant2'
 * '<S32>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1RelaysControl'
 * '<S33>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitration'
 * '<S34>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitrationAirCool'
 * '<S35>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus'
 * '<S36>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool'
 * '<S37>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev'
 * '<S38>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1RelaysControl/state_mapping'
 * '<S39>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1RelaysControl/state_mapping1'
 * '<S40>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitration/Compare To Constant'
 * '<S41>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitration/Detect Increase'
 * '<S42>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitration/Enumerated Constant1'
 * '<S43>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitration/Enumerated Constant2'
 * '<S44>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitration/turnOFF_delay'
 * '<S45>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitration/turnOFF_delay/timed_delay'
 * '<S46>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitrationAirCool/Detect Increase'
 * '<S47>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitrationAirCool/Enumerated Constant1'
 * '<S48>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitrationAirCool/Enumerated Constant2'
 * '<S49>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitrationAirCool/turnOFF_delay'
 * '<S50>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetSpeedArbitrationAirCool/turnOFF_delay/timed_delay'
 * '<S51>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant1'
 * '<S52>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant14'
 * '<S53>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant15'
 * '<S54>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant16'
 * '<S55>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant17'
 * '<S56>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant2'
 * '<S57>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant3'
 * '<S58>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant4'
 * '<S59>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant5'
 * '<S60>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/Enumerated Constant6'
 * '<S61>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TargetStatus/state_mapping'
 * '<S62>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/Enumerated Constant1'
 * '<S63>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/SnsrTempFan1LowSpdTgtAirCool'
 * '<S64>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/dcdcTempFan1LowSpdTgtAirCool'
 * '<S65>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/dcdcTempFan1LowSpdTgtChr'
 * '<S66>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/inv2TempFan1LowSpdTgtAirCool'
 * '<S67>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/mot2TempFan1LowSpdTgtAirCool'
 * '<S68>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/obcTempEDCPSpdTgtChr'
 * '<S69>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/ts5TempFan1LowSpdTgtChr'
 * '<S70>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/turnON_delay'
 * '<S71>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/dcdcTempFan1LowSpdTgtAirCool/Compare To Constant3'
 * '<S72>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/dcdcTempFan1LowSpdTgtChr/Compare To Constant3'
 * '<S73>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/inv2TempFan1LowSpdTgtAirCool/Compare To Constant3'
 * '<S74>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/mot2TempFan1LowSpdTgtAirCool/Compare To Constant3'
 * '<S75>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/obcTempEDCPSpdTgtChr/Compare To Constant1'
 * '<S76>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/ts5TempFan1LowSpdTgtChr/Compare To Constant3'
 * '<S77>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdAirCool/turnON_delay/timed_delay'
 * '<S78>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/Compare To Constant'
 * '<S79>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/Enumerated Constant1'
 * '<S80>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/SnsrTempFan1LowSpdTgt'
 * '<S81>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/SnsrTempFan1LowSpdTgt1'
 * '<S82>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/dcdcTempFan1LowSpdTgt'
 * '<S83>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/dcdcTempFan1LowSpdTgt1'
 * '<S84>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/dcdcTempFan1LowSpdTgtChr'
 * '<S85>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/dcdcTempFanLowSpdTgtChr'
 * '<S86>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/inv2TempFan1LowSpdTgt'
 * '<S87>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/inv2TempFan1LowSpdTgt1'
 * '<S88>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/mot2TempFan1LowSpdTgt'
 * '<S89>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/mot2TempFan1LowSpdTgt1'
 * '<S90>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/obcTempEDCPSpdTgtChr'
 * '<S91>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/obcTempfanSpdTgtChr'
 * '<S92>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/ts5TempFan1LowSpdTgtChr'
 * '<S93>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/ts5TempFanFLowSpdTgtChr'
 * '<S94>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/turnON_delay'
 * '<S95>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/SnsrTempFan1LowSpdTgt/Compare To Constant3'
 * '<S96>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/SnsrTempFan1LowSpdTgt1/Compare To Constant3'
 * '<S97>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/dcdcTempFan1LowSpdTgt/Compare To Constant3'
 * '<S98>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/dcdcTempFan1LowSpdTgt1/Compare To Constant3'
 * '<S99>'  : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/dcdcTempFan1LowSpdTgtChr/Compare To Constant3'
 * '<S100>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/dcdcTempFanLowSpdTgtChr/Compare To Constant3'
 * '<S101>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/inv2TempFan1LowSpdTgt/Compare To Constant3'
 * '<S102>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/inv2TempFan1LowSpdTgt1/Compare To Constant3'
 * '<S103>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/mot2TempFan1LowSpdTgt/Compare To Constant3'
 * '<S104>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/mot2TempFan1LowSpdTgt1/Compare To Constant3'
 * '<S105>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/obcTempEDCPSpdTgtChr/Compare To Constant1'
 * '<S106>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/obcTempfanSpdTgtChr/Compare To Constant1'
 * '<S107>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/ts5TempFan1LowSpdTgtChr/Compare To Constant3'
 * '<S108>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/ts5TempFanFLowSpdTgtChr/Compare To Constant3'
 * '<S109>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FanManagement/Fan1TgtSpdLdt45TBev/turnON_delay/timed_delay'
 * '<S110>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/Compare To Constant'
 * '<S111>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/Interval Test'
 * '<S112>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/Interval Test1'
 * '<S113>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/Interval Test2'
 * '<S114>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/Interval Test3'
 * '<S115>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/debounce'
 * '<S116>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/debounce1'
 * '<S117>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/debounce2'
 * '<S118>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/debounce3'
 * '<S119>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/debounce/timed_debounce'
 * '<S120>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/debounce1/timed_debounce'
 * '<S121>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/debounce2/timed_debounce'
 * '<S122>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/FaultStatusControl/debounce3/timed_debounce'
 * '<S123>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant'
 * '<S124>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant1'
 * '<S125>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant2'
 * '<S126>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant3'
 * '<S127>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant4'
 * '<S128>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant5'
 * '<S129>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant6'
 * '<S130>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant7'
 * '<S131>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/Enumerated Constant8'
 * '<S132>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/SR_latch1'
 * '<S133>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/SR_latch2'
 * '<S134>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/SR_latch3'
 * '<S135>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/turnOFF_delay'
 * '<S136>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/turnOFF_delay1'
 * '<S137>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/turnON_delay'
 * '<S138>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/turnON_delay1'
 * '<S139>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/turnOFF_delay/timed_delay'
 * '<S140>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/turnOFF_delay1/timed_delay'
 * '<S141>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/turnON_delay/timed_delay'
 * '<S142>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/Heater_EP1_Control/turnON_delay1/timed_delay'
 * '<S143>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/NonVacuumFillingControl/Chart'
 * '<S144>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/NonVacuumFillingControl/Detect Increase1'
 * '<S145>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/NonVacuumFillingControl/Enumerated Constant1'
 * '<S146>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/NonVacuumFillingControl/Enumerated Constant4'
 * '<S147>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump1TargetSpeed'
 * '<S148>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool'
 * '<S149>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpRelaysControl'
 * '<S150>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus'
 * '<S151>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump1TargetSpeed/Detect Increase'
 * '<S152>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump1TargetSpeed/Enumerated Constant1'
 * '<S153>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump1TargetSpeed/Enumerated Constant2'
 * '<S154>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump1TargetSpeed/Enumerated Constant3'
 * '<S155>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump1TargetSpeed/turnOFF_delay'
 * '<S156>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump1TargetSpeed/turnOFF_delay/timed_delay'
 * '<S157>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/Compare To Constant'
 * '<S158>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/Detect Increase'
 * '<S159>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/Enumerated Constant1'
 * '<S160>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/Enumerated Constant2'
 * '<S161>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/Enumerated Constant3'
 * '<S162>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/SnsrTempEDCPSpdTgtAirCool'
 * '<S163>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/SnsrTempEDCPSpdTgtAirCool1'
 * '<S164>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/SnsrTempEDCPSpdTgtChrAirCool'
 * '<S165>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/dcdcTempEDCPSpdTgAirCool'
 * '<S166>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/dcdcTempEDCPSpdTgAirCool1'
 * '<S167>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/dcdcTempEDCPSpdTgtChrAirCool'
 * '<S168>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/inv2TempEDCPSpdTgtAirCool'
 * '<S169>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/inv2TempEDCPSpdTgtAirCool1'
 * '<S170>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/mot2TempEDCPSpdTgtAirCool'
 * '<S171>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/mot2TempEDCPSpdTgtAirCool1'
 * '<S172>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/obcTempEDCPSpdTgt'
 * '<S173>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/obcTempEdcpPct'
 * '<S174>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/obcTempEdcpPct1'
 * '<S175>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/turnOFF_delay'
 * '<S176>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/SnsrTempEDCPSpdTgtAirCool/Compare To Constant'
 * '<S177>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/SnsrTempEDCPSpdTgtAirCool1/Compare To Constant'
 * '<S178>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/SnsrTempEDCPSpdTgtChrAirCool/Compare To Constant'
 * '<S179>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/dcdcTempEDCPSpdTgAirCool/Compare To Constant1'
 * '<S180>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/dcdcTempEDCPSpdTgAirCool1/Compare To Constant1'
 * '<S181>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/dcdcTempEDCPSpdTgtChrAirCool/Compare To Constant1'
 * '<S182>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/inv2TempEDCPSpdTgtAirCool/Compare To Constant2'
 * '<S183>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/inv2TempEDCPSpdTgtAirCool1/Compare To Constant2'
 * '<S184>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/mot2TempEDCPSpdTgtAirCool/Compare To Constant3'
 * '<S185>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/mot2TempEDCPSpdTgtAirCool1/Compare To Constant3'
 * '<S186>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/obcTempEDCPSpdTgt/Compare To Constant1'
 * '<S187>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/obcTempEdcpPct/Compare To Constant1'
 * '<S188>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/obcTempEdcpPct1/Compare To Constant1'
 * '<S189>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/Pump2TargetSpeedAirCool/turnOFF_delay/timed_delay'
 * '<S190>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpRelaysControl/state_mapping'
 * '<S191>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpRelaysControl/state_mapping1'
 * '<S192>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/Compare To Constant'
 * '<S193>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/Enumerated Constant10'
 * '<S194>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/Enumerated Constant11'
 * '<S195>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/Enumerated Constant5'
 * '<S196>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/Enumerated Constant6'
 * '<S197>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/Enumerated Constant7'
 * '<S198>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/Enumerated Constant8'
 * '<S199>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/Enumerated Constant9'
 * '<S200>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/state_mapping'
 * '<S201>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/WaterPumpsManagement/PumpsTargetStatus/state_mapping1'
 * '<S202>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptc3FaultStatusControl/ptc3FaultStatus'
 * '<S203>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptc3FaultStatusControl/ptc3FaultStatus/turnON_delay'
 * '<S204>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptc3FaultStatusControl/ptc3FaultStatus/turnON_delay1'
 * '<S205>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptc3FaultStatusControl/ptc3FaultStatus/turnON_delay/timed_delay'
 * '<S206>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptc3FaultStatusControl/ptc3FaultStatus/turnON_delay1/timed_delay'
 * '<S207>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptcFaultStatusControl/ptc1FaultStatus'
 * '<S208>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptcFaultStatusControl/ptc1FaultStatus/turnON_delay'
 * '<S209>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptcFaultStatusControl/ptc1FaultStatus/turnON_delay1'
 * '<S210>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptcFaultStatusControl/ptc1FaultStatus/turnON_delay/timed_delay'
 * '<S211>' : 'swc_THSM/THSM__Thermal_System_Manager/THM_ThermalControl/ptcFaultStatusControl/ptc1FaultStatus/turnON_delay1/timed_delay'
 */
#endif                                 /* RTW_HEADER_swc_THSM_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
