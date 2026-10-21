 
/*
************************************************************************************************************************
*
* File name: Rte_swc_BcuStTranCtl.h
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
#ifndef RTE_SWC_BCUSTTRANCTL_H_
#define RTE_SWC_BCUSTTRANCTL_H_

#include "Rte_swc_BcuStTranCtl_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_DelayTime_BSTC_DelayTime;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ErrInfo_BSTC_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_RstCmd_BSTC_RstCmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_RstCmd100_BSTC_RstCmd100;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcuInt_BSTC_StBcuInt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBmsChk_BSTC_StBmsChk;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TiBatOff_BSTC_TiBatOff;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TiBatOn_BSTC_TiBatOn;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_TrigCh_BSTC_TrigCh;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvObcOff_BSTC_bAcvObcOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrPwrOff_BSTC_bErrPwrOff;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_StAcSys_BCC_StAcSys;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StChkUMax_BPIU_StChkUMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StChkUMin_BPIU_StChkUMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StErrTOver_BTHM_StErrTOver;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_DayRtc_CIL_DayRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_HourRtc_CIL_HourRtc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MinuRtc_CIL_MinuRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_ModeSysWup_CIL_ModeSysWup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_MonthRtc_CIL_MonthRtc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_SecRtc_CIL_SecRtc;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatHvReq_CIL_StBatHvReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StChWup_CIL_StChWup;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StRtcFlt_CIL_StRtcFlt;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StTrml15_CIL_StTrml15;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_YearRtc_CIL_YearRtc;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bCANWakeUp_CIL_bCANWakeUp;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_ReqRlyCh_CTC_ReqRlyCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkCh_CTC_StRlyChkCh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkHeat_CTC_StRlyChkHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyChkPos_CTC_StRlyChkPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvBswCtl_CTC_bAcvBswCtl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvCh_CTC_bAcvCh;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd2_DEH_ErrCfmd2;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd5_DEH_ErrCfmd5;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrash_ELHPN_StCrash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrashIni_ELHPN_StCrashIni;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_DayRtcLst_NVM_DayRtcLst;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_HourRtcLst_NVM_HourRtcLst;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_MinuRtcLst_NVM_MinuRtcLst;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_MonthRtcLst_NVM_MonthRtcLst;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_SecRtcLst_NVM_SecRtcLst;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_YearRtcLst_NVM_YearRtcLst;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_10ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_10ms_Core2_QM;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
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
#define Rte_IRead_BSTC_10ms_BBC_bAcvBaln_BBC_bAcvBaln() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value)

#define Rte_IRead_BSTC_10ms_BCC_StAcSys_BCC_StAcSys() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BCC_StAcSys_BCC_StAcSys.value)

#define Rte_IRead_BSTC_10ms_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax.value)

#define Rte_IRead_BSTC_10ms_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin.value)

#define Rte_IRead_BSTC_10ms_BPIU_StChkUMax_BPIU_StChkUMax() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BPIU_StChkUMax_BPIU_StChkUMax.value)

#define Rte_IRead_BSTC_10ms_BPIU_StChkUMin_BPIU_StChkUMin() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BPIU_StChkUMin_BPIU_StChkUMin.value)

#define Rte_IWrite_BSTC_10ms_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_DayRtcLstNv_BSTC_DayRtcLstNv.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_DelayTime_BSTC_DelayTime(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_DelayTime_BSTC_DelayTime.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_DelayTime_BSTC_DelayTime() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_DelayTime_BSTC_DelayTime.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_ErrInfo_BSTC_ErrInfo(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ErrInfo_BSTC_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_ErrInfo_BSTC_ErrInfo() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ErrInfo_BSTC_ErrInfo.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_HourRtcLstNv_BSTC_HourRtcLstNv.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_MinuRtcLstNv_BSTC_MinuRtcLstNv.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ModeBmsAcvn_BSTC_ModeBmsAcvn.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_MonthRtcLstNv_BSTC_MonthRtcLstNv.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqEmcyHvOffFromBms_BSTC_ReqEmcyHvOffFromBms.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqEmcyHvOffFromVcu_BSTC_ReqEmcyHvOffFromVcu.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_ReqShtdnBas_BSTC_ReqShtdnBas.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_RstCmd_BSTC_RstCmd(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_RstCmd_BSTC_RstCmd.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_RstCmd_BSTC_RstCmd() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_RstCmd_BSTC_RstCmd.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_RstCmd100_BSTC_RstCmd100(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_RstCmd100_BSTC_RstCmd100.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_RstCmd100_BSTC_RstCmd100() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_RstCmd100_BSTC_RstCmd100.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_SecRtcLstNv_BSTC_SecRtcLstNv.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_StBcu_BSTC_StBcu(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_StBcu_BSTC_StBcu() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBcu_BSTC_StBcu.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_StBcuInt_BSTC_StBcuInt(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBcuInt_BSTC_StBcuInt.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_StBcuInt_BSTC_StBcuInt() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBcuInt_BSTC_StBcuInt.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_StBmsChk_BSTC_StBmsChk(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBmsChk_BSTC_StBmsChk.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_StBmsChk_BSTC_StBmsChk() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_StBmsChk_BSTC_StBmsChk.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_TiBatOff_BSTC_TiBatOff(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TiBatOff_BSTC_TiBatOff.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_TiBatOff_BSTC_TiBatOff() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TiBatOff_BSTC_TiBatOff.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_TiBatOn_BSTC_TiBatOn(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TiBatOn_BSTC_TiBatOn.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_TiBatOn_BSTC_TiBatOn() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TiBatOn_BSTC_TiBatOn.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_TrigCh_BSTC_TrigCh(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TrigCh_BSTC_TrigCh.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_TrigCh_BSTC_TrigCh() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_TrigCh_BSTC_TrigCh.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_YearRtcLstNv_BSTC_YearRtcLstNv.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvCutoffLvFromBms_BSTC_bAcvCutoffLvFromBms.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvDcStChToStHvOffNorm_BSTC_bAcvDcStChToStHvOffNorm.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvHvOffNormFromVcu_BSTC_bAcvHvOffNormFromVcu.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bAcvObcOff_BSTC_bAcvObcOff(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bAcvObcOff_BSTC_bAcvObcOff() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvObcOff_BSTC_bAcvObcOff.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStDchaToStHvOffNorm_BSTC_bAcvStDchaToStHvOffNorm.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStRunToStHvOffEmcy_BSTC_bAcvStRunToStHvOffEmcy.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bAcvStStbToStAftRun_BSTC_bAcvStStbToStAftRun.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrHvOffAbno_BSTC_bErrHvOffAbno.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bErrPwrOff_BSTC_bErrPwrOff(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrPwrOff_BSTC_bErrPwrOff.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bErrPwrOff_BSTC_bErrPwrOff() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrPwrOff_BSTC_bErrPwrOff.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrToutForRxCutoffLvReq_BSTC_bErrToutForRxCutoffLvReq.value \
)

#define Rte_IWrite_BSTC_10ms_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq(data) \
( \
  Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq.value = (data) \
)

#define Rte_IWriteRef_BSTC_10ms_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq() \
( \
  &Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BSTC_bErrToutForRxHvOffReq_BSTC_bErrToutForRxHvOffReq.value \
)

#define Rte_IRead_BSTC_10ms_BTHM_StErrTOver_BTHM_StErrTOver() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_BTHM_StErrTOver_BTHM_StErrTOver.value)

#define Rte_IRead_BSTC_10ms_CIL_DayRtc_CIL_DayRtc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_DayRtc_CIL_DayRtc.value)

#define Rte_IRead_BSTC_10ms_CIL_HourRtc_CIL_HourRtc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_HourRtc_CIL_HourRtc.value)

#define Rte_IRead_BSTC_10ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_BSTC_10ms_CIL_MinuRtc_CIL_MinuRtc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_MinuRtc_CIL_MinuRtc.value)

#define Rte_IRead_BSTC_10ms_CIL_ModeSysWup_CIL_ModeSysWup() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_ModeSysWup_CIL_ModeSysWup.value)

#define Rte_IRead_BSTC_10ms_CIL_MonthRtc_CIL_MonthRtc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_MonthRtc_CIL_MonthRtc.value)

#define Rte_IRead_BSTC_10ms_CIL_SecRtc_CIL_SecRtc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_SecRtc_CIL_SecRtc.value)

#define Rte_IRead_BSTC_10ms_CIL_SpdVeh_CIL_SpdVeh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_SpdVeh_CIL_SpdVeh.value)

#define Rte_IRead_BSTC_10ms_CIL_StBatHvReq_CIL_StBatHvReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StBatHvReq_CIL_StBatHvReq.value)

#define Rte_IRead_BSTC_10ms_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StBatLvCutoffReq_CIL_StBatLvCutoffReq.value)

#define Rte_IRead_BSTC_10ms_CIL_StChWup_CIL_StChWup() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StChWup_CIL_StChWup.value)

#define Rte_IRead_BSTC_10ms_CIL_StChWup2_CIL_StChWup2() \
  (0U)

#define Rte_IRead_BSTC_10ms_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StMsgToutForPMS_CIL_StMsgToutForPMS.value)

#define Rte_IRead_BSTC_10ms_CIL_StRtcFlt_CIL_StRtcFlt() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StRtcFlt_CIL_StRtcFlt.value)

#define Rte_IRead_BSTC_10ms_CIL_StTrml15_CIL_StTrml15() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_StTrml15_CIL_StTrml15.value)

#define Rte_IRead_BSTC_10ms_CIL_YearRtc_CIL_YearRtc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_YearRtc_CIL_YearRtc.value)

#define Rte_IRead_BSTC_10ms_CIL_bCANWakeUp_CIL_bCANWakeUp() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_bCANWakeUp_CIL_bCANWakeUp.value)

#define Rte_IRead_BSTC_10ms_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_bRdyBswStoreFnshd_CIL_bRdyBswStoreFnshd.value)

#define Rte_IRead_BSTC_10ms_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value)

#define Rte_IRead_BSTC_10ms_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value)

#define Rte_IRead_BSTC_10ms_CTC_ReqRlyCh_CTC_ReqRlyCh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_ReqRlyCh_CTC_ReqRlyCh.value)

#define Rte_IRead_BSTC_10ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BSTC_10ms_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_BSTC_10ms_CTC_StRlyChkCh_CTC_StRlyChkCh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StRlyChkCh_CTC_StRlyChkCh.value)

#define Rte_IRead_BSTC_10ms_CTC_StRlyChkHeat_CTC_StRlyChkHeat() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StRlyChkHeat_CTC_StRlyChkHeat.value)

#define Rte_IRead_BSTC_10ms_CTC_StRlyChkPos_CTC_StRlyChkPos() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_StRlyChkPos_CTC_StRlyChkPos.value)

#define Rte_IRead_BSTC_10ms_CTC_bAcvBswCtl_CTC_bAcvBswCtl() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_bAcvBswCtl_CTC_bAcvBswCtl.value)

#define Rte_IRead_BSTC_10ms_CTC_bAcvCh_CTC_bAcvCh() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_bAcvCh_CTC_bAcvCh.value)

#define Rte_IRead_BSTC_10ms_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_CTC_bAcvTrml15Chk_CTC_bAcvTrml15Chk.value)

#define Rte_IRead_BSTC_10ms_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_CtrHvOffReqDiag_DEH_CtrHvOffReqDiag.value)

#define Rte_IRead_BSTC_10ms_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_CtrHvOnReqDiag_DEH_CtrHvOnReqDiag.value)

#define Rte_IRead_BSTC_10ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_BSTC_10ms_DEH_ErrCfmd2_DEH_ErrCfmd2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_ErrCfmd2_DEH_ErrCfmd2.value)

#define Rte_IRead_BSTC_10ms_DEH_ErrCfmd5_DEH_ErrCfmd5() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_ErrCfmd5_DEH_ErrCfmd5.value)

#define Rte_IRead_BSTC_10ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_BSTC_10ms_DEH_StsIninNv_DEH_StsIninNv() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value)

#define Rte_IRead_BSTC_10ms_DEH_bAcvBdNew_DEH_bAcvBdNew() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value)

#define Rte_IRead_BSTC_10ms_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_bAcvEmcyHvOff1_DEH_bAcvEmcyHvOff1.value)

#define Rte_IRead_BSTC_10ms_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_DEH_bAcvEmcyHvOff2_DEH_bAcvEmcyHvOff2.value)

#define Rte_IRead_BSTC_10ms_ELHPN_StCrash_ELHPN_StCrash() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StCrash_ELHPN_StCrash.value)

#define Rte_IRead_BSTC_10ms_ELHPN_StCrashIni_ELHPN_StCrashIni() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StCrashIni_ELHPN_StCrashIni.value)

#define Rte_IRead_BSTC_10ms_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc.value)

#define Rte_IRead_BSTC_10ms_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2.value)

#define Rte_IRead_BSTC_10ms_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni.value)

#define Rte_IRead_BSTC_10ms_NVM_DayRtcLst_NVM_DayRtcLst() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_DayRtcLst_NVM_DayRtcLst.value)

#define Rte_IRead_BSTC_10ms_NVM_HourRtcLst_NVM_HourRtcLst() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_HourRtcLst_NVM_HourRtcLst.value)

#define Rte_IRead_BSTC_10ms_NVM_MinuRtcLst_NVM_MinuRtcLst() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_MinuRtcLst_NVM_MinuRtcLst.value)

#define Rte_IRead_BSTC_10ms_NVM_MonthRtcLst_NVM_MonthRtcLst() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_MonthRtcLst_NVM_MonthRtcLst.value)

#define Rte_IRead_BSTC_10ms_NVM_SecRtcLst_NVM_SecRtcLst() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_SecRtcLst_NVM_SecRtcLst.value)

#define Rte_IRead_BSTC_10ms_NVM_YearRtcLst_NVM_YearRtcLst() \
  (Rte_App1_Task_10ms_Core2_QM.Rte_RB.Rte_swc_BcuStTranCtl_BSTC_10ms.Rte_NVM_YearRtcLst_NVM_YearRtcLst.value)

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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, swc_SetOutputInterface_CODE) If_SetRtcWakeUp_SetWakeUpTime(VAR(UInt16, RTE_swc_SetOutputInterface_APPL_DATA) minute);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifndef RTE_CORE
#define Rte_Call_If_SetRtcWakeUp_SetWakeUpTime Rte_Call_swc_BcuStTranCtl_If_SetRtcWakeUp_SetWakeUpTime
#define Rte_Call_swc_BcuStTranCtl_If_SetRtcWakeUp_SetWakeUpTime(arg1) (If_SetRtcWakeUp_SetWakeUpTime(arg1), ((Std_ReturnType)RTE_E_OK))
#endif /* !defined(RTE_CORE) */

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
FUNC(void, swc_BcuStTranCtl_CODE) BSTC_10ms(void);
FUNC(void, swc_BcuStTranCtl_CODE) BSTC_Init(void);
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
#endif /* RTE_SWC_BCUSTTRANCTL_H_ */
 
 
 
