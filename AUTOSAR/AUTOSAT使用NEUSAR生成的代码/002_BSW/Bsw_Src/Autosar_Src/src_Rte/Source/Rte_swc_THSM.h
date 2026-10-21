 
/*
************************************************************************************************************************
*
* File name: Rte_swc_THSM.h
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
#ifndef RTE_SWC_THSM_H_
#define RTE_SWC_THSM_H_

#include "Rte_swc_THSM_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ActiveCool_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_BalanceHeat_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_PassCool_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_PassHeat_flg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_TwoWayVlvReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_accmEnb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_afterRunActive;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fan2Ena;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly1Req;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_fanRly2Req;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEna3HW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_heaterEnaHW;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_hvbDeft;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuCl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_iptcHtIpuResvHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuHeatEnableFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuResvHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_ipuSupHtIptcHt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv1V3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv2V2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv4V2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_tv4V3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmpRly1Req;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_b_wtrPmpRly2Req;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_FWFVTgt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_MHGVTgt_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_fan1TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_fan2TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_pmp1TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_n_pmp2TgtSpd_pct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_q_pmp2FlowFeedback;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_acwpSpdReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3ConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptc3RlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcConnStsFb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_st_tv4;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_THSM_vcsb_THSM_thmd_t_acwpTemp_C;
extern VAR(McuSts, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_e_PtcSt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_n_acFanReqSpd_pct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_cbnThermMngReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_iptWorkSt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_st_ptcWorkStRear;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_t_ambTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_accd_u_acPresVolt_V;
extern VAR(BrakePedalStatus, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_brpd_e_brkPedalStatus;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_st_12vDcdcModAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_dccd_t_dcdcTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_t_inv2Temp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_eadd_t_mot2Temp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_hvbHeatEnad;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_st_hvbThermMngReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbInCoolTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbMin_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_hvbd_t_hvbTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_macd_t_ts5SnsrTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_obcd_t_obcTemp_C;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_pmmd_b_ignOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_flgFctCfgBatCol;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flg2FctCfgVehTyp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgAccy;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_st_flgFctCfgFan;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_acwpOutptTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_t_hvbSetTgtTemp_C;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_TS5sensorFb_mV;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmAcceRlyVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hcmPtcRlyVolt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltInSnsr_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_hvbCooltOutSnsr_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vild_u_ipuHVBusVolt_V;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_VCIP_vcib_VCIP_vscd_v_vehSpd_kph;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DIAG_vcsb_DIAG_digd_b_vehCrashFltLvl33;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcEnbAllowFlg;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EGYM_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg;
extern VAR(PmmStatus, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_hvbd_e_PmmStatus;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_HVSM_vcsb_HVSM_obcd_b_chargerPlugged;
extern VAR(GearLeverPos, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_drid_e_gearLvrPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_VOMM_vcsb_VOMM_pmmd_b_pwrHoldReq;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE1_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE1_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_100ms_Core1_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core1_QM;
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
#define Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_e_PtcSt() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_e_PtcSt.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_n_acFanReqSpd_pct() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_n_acFanReqSpd_pct.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_st_cbnThermMngReq() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_st_cbnThermMngReq.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_st_iptWorkSt() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_st_iptWorkSt.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_st_ptcWorkStRear() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_st_ptcWorkStRear.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_t_ambTemp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_t_ambTemp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_accd_u_acPresVolt_V() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_accd_u_acPresVolt_V.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_brpd_e_brkPedalStatus() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_brpd_e_brkPedalStatus.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_dccd_st_12vDcdcModAct() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_dccd_st_12vDcdcModAct.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_dccd_t_dcdcTemp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_dccd_t_dcdcTemp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_eadd_t_inv2Temp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_eadd_t_inv2Temp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_eadd_t_mot2Temp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_eadd_t_mot2Temp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_b_hvbHeatEnad() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_b_hvbHeatEnad.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_b_tboxIntelChgCmdRaw.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_st_hvbThermMngReq() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_st_hvbThermMngReq.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_t_hvbInCoolTemp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_t_hvbInCoolTemp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_t_hvbMin_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_t_hvbMin_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_hvbd_t_hvbTemp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_hvbd_t_hvbTemp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_macd_t_ts5SnsrTemp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_macd_t_ts5SnsrTemp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_obcd_t_obcTemp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_obcd_t_obcTemp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_pmmd_b_ignOn() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_pmmd_b_ignOn.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_b_flgFctCfgBatCol() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_b_flgFctCfgBatCol.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_b_hcmAcceRlyVoltVldSts.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_b_hcmPtcRlyVoltVldSts.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_st_flg2FctCfgVehTyp() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_st_flg2FctCfgVehTyp.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_st_flgFctCfgAccy() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgAccy.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_st_flgFctCfgFan() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_st_flgFctCfgFan.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_t_acwpOutptTemp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_t_acwpOutptTemp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_t_hvbSetTgtTemp_C() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_t_hvbSetTgtTemp_C.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_TS5sensorFb_mV() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_TS5sensorFb_mV.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_hcmAcceRlyVolt() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_hcmAcceRlyVolt.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_hcmPtcRlyVolt() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_hcmPtcRlyVolt.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_hvbCooltInSnsr_V() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_hvbCooltInSnsr_V.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_hvbCooltOutSnsr_V() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_hvbCooltOutSnsr_V.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vild_u_ipuHVBusVolt_V() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vild_u_ipuHVBusVolt_V.value)

#define Rte_IRead_swc_THSM_Step_vcib_VCIP_vscd_v_vehSpd_kph() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcib_VCIP_vscd_v_vehSpd_kph.value)

#define Rte_IRead_swc_THSM_Step_vcsb_DIAG_digd_b_vehCrashFltLvl33() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_DIAG_digd_b_vehCrashFltLvl33.value)

#define Rte_IRead_swc_THSM_Step_vcsb_EGYM_egmd_b_ptcEnbAllowFlg() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_EGYM_egmd_b_ptcEnbAllowFlg.value)

#define Rte_IRead_swc_THSM_Step_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_EGYM_egmd_b_ptcRearEnbAllowFlg.value)

#define Rte_IRead_swc_THSM_Step_vcsb_HVSM_hvbd_e_PmmStatus() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_HVSM_hvbd_e_PmmStatus.value)

#define Rte_IRead_swc_THSM_Step_vcsb_HVSM_obcd_b_chargerPlugged() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_HVSM_obcd_b_chargerPlugged.value)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_ActiveCool_flg(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ActiveCool_flg.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_ActiveCool_flg() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ActiveCool_flg.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_BalanceHeat_flg(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_BalanceHeat_flg.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_BalanceHeat_flg() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_BalanceHeat_flg.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_PassCool_flg(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_PassCool_flg.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_PassCool_flg() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_PassCool_flg.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_PassHeat_flg(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_PassHeat_flg.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_PassHeat_flg() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_PassHeat_flg.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_TwoWayVlvReq(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_TwoWayVlvReq.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_TwoWayVlvReq() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_TwoWayVlvReq.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_accmEnb(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_accmEnb.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_accmEnb() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_accmEnb.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_afterRunActive(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_afterRunActive.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_afterRunActive() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_afterRunActive.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_fan2Ena(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fan2Ena.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_fan2Ena() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fan2Ena.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_fanRly1Req(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fanRly1Req.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_fanRly1Req() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fanRly1Req.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_fanRly2Req(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fanRly2Req.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_fanRly2Req() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_fanRly2Req.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna2(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna2.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna2() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna2.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna3(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna3.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna3() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna3.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna3HW(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna3HW.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEna3HW() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEna3HW.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEnaHW(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEnaHW.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_heaterEnaHW() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_heaterEnaHW.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_hvbDeft(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_hvbDeft.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_hvbDeft() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_hvbDeft.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_iptcHtIpuCl(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuCl.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_iptcHtIpuCl() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuCl.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_iptcHtIpuResvHt(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuResvHt.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_iptcHtIpuResvHt() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_iptcHtIpuResvHt.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_ipuHeatEnableFlg(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuHeatEnableFlg.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_ipuHeatEnableFlg() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuHeatEnableFlg.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_ipuResvHt(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuResvHt.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_ipuResvHt() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuResvHt.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_ipuSupHtIptcHt(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuSupHtIptcHt.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_ipuSupHtIptcHt() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_ipuSupHtIptcHt.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv1V2(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv1V2.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_tv1V2() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv1V2.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv1V3(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv1V3.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_tv1V3() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv1V3.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv2V2(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv2V2.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_tv2V2() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv2V2.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv4V2(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv4V2.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_tv4V2() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv4V2.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_tv4V3(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv4V3.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_tv4V3() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_tv4V3.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmp1CtrlEnabled.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmp2CtrlEnabled.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmpRly1Req(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmpRly1Req.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmpRly1Req() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmpRly1Req.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmpRly2Req(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmpRly2Req.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_b_wtrPmpRly2Req() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_b_wtrPmpRly2Req.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_FWFVTgt_pct(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_FWFVTgt_pct.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_n_FWFVTgt_pct() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_FWFVTgt_pct.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_MHGVTgt_pct(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_MHGVTgt_pct.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_n_MHGVTgt_pct() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_MHGVTgt_pct.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_fan1TgtSpd_pct(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_fan1TgtSpd_pct.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_n_fan1TgtSpd_pct() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_fan1TgtSpd_pct.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_fan2TgtSpd_pct(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_fan2TgtSpd_pct.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_n_fan2TgtSpd_pct() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_fan2TgtSpd_pct.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_pmp1TgtSpd_pct(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_pmp1TgtSpd_pct.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_n_pmp1TgtSpd_pct() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_pmp1TgtSpd_pct.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_n_pmp2TgtSpd_pct(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_pmp2TgtSpd_pct.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_n_pmp2TgtSpd_pct() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_n_pmp2TgtSpd_pct.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_pwr_ipuHeatPwrAllwd_kW.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_q_pmp2FlowFeedback(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_q_pmp2FlowFeedback.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_q_pmp2FlowFeedback() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_q_pmp2FlowFeedback.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acceRlyVoltSamSwitch.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_acwpHeat(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acwpHeat.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_acwpHeat() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acwpHeat.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_acwpSpdReq(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acwpSpdReq.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_acwpSpdReq() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_acwpSpdReq.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptc3ConnStsFb(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptc3ConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_ptc3ConnStsFb() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptc3ConnStsFb.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptc3RlyFlt(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptc3RlyFlt.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_ptc3RlyFlt() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptc3RlyFlt.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptcConnStsFb(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcConnStsFb.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_ptcConnStsFb() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcConnStsFb.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptcRlyFlt(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcRlyFlt.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_ptcRlyFlt() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcRlyFlt.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_ptcRlyVoltSamSwitch.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_st_tv4(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_tv4.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_st_tv4() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_st_tv4.value \
)

#define Rte_IWrite_swc_THSM_Step_vcsb_THSM_thmd_t_acwpTemp_C(data) \
( \
  Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_t_acwpTemp_C.value = (data) \
)

#define Rte_IWriteRef_swc_THSM_Step_vcsb_THSM_thmd_t_acwpTemp_C() \
( \
  &Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_THSM_thmd_t_acwpTemp_C.value \
)

#define Rte_IRead_swc_THSM_Step_vcsb_VBSW_vbsd_b_vbsShtDwnHVReq() \
  (FALSE)

#define Rte_IRead_swc_THSM_Step_vcsb_VOMM_drid_e_gearLvrPos() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_VOMM_drid_e_gearLvrPos.value)

#define Rte_IRead_swc_THSM_Step_vcsb_VOMM_pmmd_b_pwrHoldReq() \
  (Rte_App1_Task_100ms_Core1_QM.Rte_RB.Rte_swc_THSM_swc_THSM_Step.Rte_vcsb_VOMM_pmmd_b_pwrHoldReq.value)

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
FUNC(void, swc_THSM_CODE) swc_THSM_Step(void);
FUNC(void, swc_THSM_CODE) swc_THSM_Init(void);
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
#endif /* RTE_SWC_THSM_H_ */
 
 
 
