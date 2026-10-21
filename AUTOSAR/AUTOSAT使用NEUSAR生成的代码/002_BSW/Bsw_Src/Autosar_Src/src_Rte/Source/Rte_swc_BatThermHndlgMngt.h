 
/*
************************************************************************************************************************
*
* File name: Rte_swc_BatThermHndlgMngt.h
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
#ifndef RTE_SWC_BATTHERMHNDLGMNGT_H_
#define RTE_SWC_BATTHERMHNDLGMNGT_H_

#include "Rte_swc_BatThermHndlgMngt_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrChEnd_BTHM_ErrChEnd;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ErrInfo_BTHM_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMax_BTHM_IdCellTMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdCellTMin_BTHM_IdCellTMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdMdulTMax_BTHM_IdMdulTMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_IdMdulTMin_BTHM_IdMdulTMin;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_MfCoolt_BTHM_MfCoolt;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_ReqRePrech_BTHM_ReqRePrech;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StErrTOver_BTHM_StErrTOver;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyMain_BTHM_StRlyMain;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StSys_BTHM_StSys;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_StThermReq_BTHM_StThermReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TBatTgt_BTHM_TBatTgt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TBcuSnsr_BTHM_TBcuSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCorrn_BTHM_TMdulCorrn;
extern VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsr_BTHM_TMdulSnsr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TOptmMax_BTHM_TOptmMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TOptmMin_BTHM_TOptmMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TPack_BTHM_TPack;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig64_BTHM_bAcvDig64;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvDig93_BTHM_bAcvDig93;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bAcvTAbno_BTHM_bAcvTAbno;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_bErrSnsrT_BTHM_bErrSnsrT;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_SocPack_BCF_SocPack;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_BSOF_UChrgr_BSOF_UChrgr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_BatCoolType_CIL_BatCoolType;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_SpdVeh_CIL_SpdVeh;
extern VAR(rt_Array_UInt8_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCellT_CIL_StCellT;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StProj_CIL_StProj;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBd_CIL_TBd;
extern VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TBdSnsr_CIL_TBdSnsr;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr;
extern VAR(rt_Array_Float_54, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdul_CIL_TMdul;
extern VAR(rt_Array_Float_32, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdulCtlr_CIL_TMdulCtlr;
extern VAR(SInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_TSnsrI_CIL_TSnsrI;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UObcChOutp_CIL_UObcChOutp;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bDCDCW_CIL_bDCDCW;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyHeat_CTC_StRlyHeat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StRlyPos_CTC_StRlyPos;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvHeatInh_DEH_bAcvHeatInh;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrAFETot_MCC_NrAFETot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrSnsrTTot_MCC_NrSnsrTTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_StMdulCu_MCC_StMdulCu;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_100ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_100ms_Core2_QM;
extern VAR(Rte_ts_SWC_Init_Task_Core2, RTE_VAR_NOINIT) Rte_SWC_Init_Task_Core2;
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
#define Rte_IRead_BTHM_100ms_BCF_SocPack_BCF_SocPack() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BCF_SocPack_BCF_SocPack.value)

#define Rte_IRead_BTHM_100ms_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_BTHM_100ms_BSOF_UChrgr_BSOF_UChrgr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BSOF_UChrgr_BSOF_UChrgr.value)

#define Rte_IRead_BTHM_100ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IWrite_BTHM_100ms_BTHM_ErrChEnd_BTHM_ErrChEnd(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_ErrChEnd_BTHM_ErrChEnd() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ErrChEnd_BTHM_ErrChEnd.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_ErrInfo_BTHM_ErrInfo(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ErrInfo_BTHM_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_ErrInfo_BTHM_ErrInfo() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ErrInfo_BTHM_ErrInfo.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_IdCellTMax_BTHM_IdCellTMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_IdCellTMax_BTHM_IdCellTMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdCellTMax_BTHM_IdCellTMax.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_IdCellTMin_BTHM_IdCellTMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_IdCellTMin_BTHM_IdCellTMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdCellTMin_BTHM_IdCellTMin.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_IdMdulTMax_BTHM_IdMdulTMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdMdulTMax_BTHM_IdMdulTMax.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_IdMdulTMax_BTHM_IdMdulTMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdMdulTMax_BTHM_IdMdulTMax.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_IdMdulTMin_BTHM_IdMdulTMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdMdulTMin_BTHM_IdMdulTMin.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_IdMdulTMin_BTHM_IdMdulTMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_IdMdulTMin_BTHM_IdMdulTMin.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_MfCoolt_BTHM_MfCoolt(data) \
  RteIWrite_BTHM_100ms_BTHM_MfCoolt_BTHM_MfCoolt(data)

#define RteIWrite_BTHM_100ms_BTHM_MfCoolt_BTHM_MfCoolt(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_MfCoolt_BTHM_MfCoolt.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_MfCoolt_BTHM_MfCoolt() \
  (&((*RteIWriteRef_BTHM_100ms_BTHM_MfCoolt_BTHM_MfCoolt())[0]))

#define RteIWriteRef_BTHM_100ms_BTHM_MfCoolt_BTHM_MfCoolt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_MfCoolt_BTHM_MfCoolt.value \
)

#define Rte_IWrite_BTHM_Init_BTHM_MfCoolt_BTHM_MfCoolt(data) \
  RteIWrite_BTHM_Init_BTHM_MfCoolt_BTHM_MfCoolt(data)

#define RteIWrite_BTHM_Init_BTHM_MfCoolt_BTHM_MfCoolt(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_MfCoolt_BTHM_MfCoolt.value, data, sizeof(rt_Array_Float_24)) \
)

#define Rte_IWriteRef_BTHM_Init_BTHM_MfCoolt_BTHM_MfCoolt() \
  (&((*RteIWriteRef_BTHM_Init_BTHM_MfCoolt_BTHM_MfCoolt())[0]))

#define RteIWriteRef_BTHM_Init_BTHM_MfCoolt_BTHM_MfCoolt() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_MfCoolt_BTHM_MfCoolt.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_ReqRePrech_BTHM_ReqRePrech(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ReqRePrech_BTHM_ReqRePrech.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_ReqRePrech_BTHM_ReqRePrech() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_ReqRePrech_BTHM_ReqRePrech.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_StErrTOver_BTHM_StErrTOver(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StErrTOver_BTHM_StErrTOver.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_StErrTOver_BTHM_StErrTOver() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StErrTOver_BTHM_StErrTOver.value \
)

#define Rte_IWrite_BTHM_Init_BTHM_StErrTOver_BTHM_StErrTOver(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_StErrTOver_BTHM_StErrTOver.value = (data) \
)

#define Rte_IWriteRef_BTHM_Init_BTHM_StErrTOver_BTHM_StErrTOver() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_StErrTOver_BTHM_StErrTOver.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyHeatReq_BTHM_StRlyHeatReq.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_StRlyMain_BTHM_StRlyMain(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyMain_BTHM_StRlyMain.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_StRlyMain_BTHM_StRlyMain() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyMain_BTHM_StRlyMain.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StRlyMainNeg_BTHM_StRlyMainNeg.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_StSys_BTHM_StSys(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StSys_BTHM_StSys.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_StSys_BTHM_StSys() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StSys_BTHM_StSys.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_StThermReq_BTHM_StThermReq(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StThermReq_BTHM_StThermReq.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_StThermReq_BTHM_StThermReq() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_StThermReq_BTHM_StThermReq.value \
)

#define Rte_IWrite_BTHM_Init_BTHM_StThermReq_BTHM_StThermReq(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_StThermReq_BTHM_StThermReq.value = (data) \
)

#define Rte_IWriteRef_BTHM_Init_BTHM_StThermReq_BTHM_StThermReq() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_StThermReq_BTHM_StThermReq.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TBatTgt_BTHM_TBatTgt(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TBatTgt_BTHM_TBatTgt.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TBatTgt_BTHM_TBatTgt() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TBatTgt_BTHM_TBatTgt.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TBcuSnsr_BTHM_TBcuSnsr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TBcuSnsr_BTHM_TBcuSnsr.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TBcuSnsr_BTHM_TBcuSnsr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TBcuSnsr_BTHM_TBcuSnsr.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TCooltPackInSnsr_BTHM_TCooltPackInSnsr.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TCooltPackOutSnsr_BTHM_TCooltPackOutSnsr.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn(data) \
  RteIWrite_BTHM_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn(data)

#define RteIWrite_BTHM_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCorrn_BTHM_TMdulCorrn.value, data, sizeof(rt_Array_Float_54)) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn() \
  (&((*RteIWriteRef_BTHM_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn())[0]))

#define RteIWriteRef_BTHM_100ms_BTHM_TMdulCorrn_BTHM_TMdulCorrn() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCorrn_BTHM_TMdulCorrn.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr(data) \
  RteIWrite_BTHM_100ms_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr(data)

#define RteIWrite_BTHM_100ms_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr.value, data, sizeof(rt_Array_Float_32)) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr() \
  (&((*RteIWriteRef_BTHM_100ms_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr())[0]))

#define RteIWriteRef_BTHM_100ms_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsr_BTHM_TMdulCtlrSnsr.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsrMax_BTHM_TMdulCtlrSnsrMax.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulCtlrSnsrMin_BTHM_TMdulCtlrSnsrMin.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulSnsr_BTHM_TMdulSnsr(data) \
  RteIWrite_BTHM_100ms_BTHM_TMdulSnsr_BTHM_TMdulSnsr(data)

#define RteIWrite_BTHM_100ms_BTHM_TMdulSnsr_BTHM_TMdulSnsr(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsr_BTHM_TMdulSnsr.value, data, sizeof(rt_Array_Float_54)) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulSnsr_BTHM_TMdulSnsr() \
  (&((*RteIWriteRef_BTHM_100ms_BTHM_TMdulSnsr_BTHM_TMdulSnsr())[0]))

#define RteIWriteRef_BTHM_100ms_BTHM_TMdulSnsr_BTHM_TMdulSnsr() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsr_BTHM_TMdulSnsr.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMaxRaw_BTHM_TMdulSnsrMaxRaw.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw(data) \
  RteIWrite_BTHM_100ms_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw(data)

#define RteIWrite_BTHM_100ms_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw.value, data, sizeof(rt_Array_Float_54)) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw() \
  (&((*RteIWriteRef_BTHM_100ms_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw())[0]))

#define RteIWriteRef_BTHM_100ms_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TMdulSnsrRaw_BTHM_TMdulSnsrRaw.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TOptmMax_BTHM_TOptmMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TOptmMax_BTHM_TOptmMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value \
)

#define Rte_IWrite_BTHM_Init_BTHM_TOptmMax_BTHM_TOptmMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value = (data) \
)

#define Rte_IWriteRef_BTHM_Init_BTHM_TOptmMax_BTHM_TOptmMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_TOptmMax_BTHM_TOptmMax.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TOptmMin_BTHM_TOptmMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TOptmMin_BTHM_TOptmMin.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TOptmMin_BTHM_TOptmMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TOptmMin_BTHM_TOptmMin.value \
)

#define Rte_IWrite_BTHM_Init_BTHM_TOptmMin_BTHM_TOptmMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_TOptmMin_BTHM_TOptmMin.value = (data) \
)

#define Rte_IWriteRef_BTHM_Init_BTHM_TOptmMin_BTHM_TOptmMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_TOptmMin_BTHM_TOptmMin.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_TPack_BTHM_TPack(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TPack_BTHM_TPack.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_TPack_BTHM_TPack() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_TPack_BTHM_TPack.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_bAcvDig64_BTHM_bAcvDig64(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvDig64_BTHM_bAcvDig64.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_bAcvDig64_BTHM_bAcvDig64() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvDig64_BTHM_bAcvDig64.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_bAcvDig93_BTHM_bAcvDig93(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvDig93_BTHM_bAcvDig93.value = (data) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_bAcvDig93_BTHM_bAcvDig93() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvDig93_BTHM_bAcvDig93.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno(data) \
  RteIWrite_BTHM_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno(data)

#define RteIWrite_BTHM_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno.value, data, sizeof(rt_Array_Boolean_24)) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno() \
  (&((*RteIWriteRef_BTHM_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno())[0]))

#define RteIWriteRef_BTHM_100ms_BTHM_bAcvTAbno_BTHM_bAcvTAbno() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno.value \
)

#define Rte_IWrite_BTHM_Init_BTHM_bAcvTAbno_BTHM_bAcvTAbno(data) \
  RteIWrite_BTHM_Init_BTHM_bAcvTAbno_BTHM_bAcvTAbno(data)

#define RteIWrite_BTHM_Init_BTHM_bAcvTAbno_BTHM_bAcvTAbno(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno.value, data, sizeof(rt_Array_Boolean_24)) \
)

#define Rte_IWriteRef_BTHM_Init_BTHM_bAcvTAbno_BTHM_bAcvTAbno() \
  (&((*RteIWriteRef_BTHM_Init_BTHM_bAcvTAbno_BTHM_bAcvTAbno())[0]))

#define RteIWriteRef_BTHM_Init_BTHM_bAcvTAbno_BTHM_bAcvTAbno() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_bAcvTAbno_BTHM_bAcvTAbno.value \
)

#define Rte_IWrite_BTHM_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT(data) \
  RteIWrite_BTHM_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT(data)

#define RteIWrite_BTHM_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT.value, data, sizeof(rt_Array_Boolean_24)) \
)

#define Rte_IWriteRef_BTHM_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT() \
  (&((*RteIWriteRef_BTHM_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT())[0]))

#define RteIWriteRef_BTHM_100ms_BTHM_bErrSnsrT_BTHM_bErrSnsrT() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT.value \
)

#define Rte_IWrite_BTHM_Init_BTHM_bErrSnsrT_BTHM_bErrSnsrT(data) \
  RteIWrite_BTHM_Init_BTHM_bErrSnsrT_BTHM_bErrSnsrT(data)

#define RteIWrite_BTHM_Init_BTHM_bErrSnsrT_BTHM_bErrSnsrT(data) \
( \
  Rte_MemCpy(Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT.value, data, sizeof(rt_Array_Boolean_24)) \
)

#define Rte_IWriteRef_BTHM_Init_BTHM_bErrSnsrT_BTHM_bErrSnsrT() \
  (&((*RteIWriteRef_BTHM_Init_BTHM_bErrSnsrT_BTHM_bErrSnsrT())[0]))

#define RteIWriteRef_BTHM_Init_BTHM_bErrSnsrT_BTHM_bErrSnsrT() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_Init.Rte_BTHM_bErrSnsrT_BTHM_bErrSnsrT.value \
)

#define Rte_IRead_BTHM_100ms_CIL_BatCoolType_CIL_BatCoolType() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_BatCoolType_CIL_BatCoolType.value)

#define Rte_IRead_BTHM_100ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_BTHM_100ms_CIL_SpdVeh_CIL_SpdVeh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_SpdVeh_CIL_SpdVeh.value)

#define Rte_IRead_BTHM_100ms_CIL_StCellT_CIL_StCellT() \
  (&((*RteIRead_BTHM_100ms_CIL_StCellT_CIL_StCellT())[0]))

#define RteIRead_BTHM_100ms_CIL_StCellT_CIL_StCellT() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_StCellT_CIL_StCellT.value)

#define Rte_IRead_BTHM_100ms_CIL_StProj_CIL_StProj() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_StProj_CIL_StProj.value)

#define Rte_IRead_BTHM_100ms_CIL_TBd_CIL_TBd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TBd_CIL_TBd.value)

#define Rte_IRead_BTHM_100ms_CIL_TBdSnsr_CIL_TBdSnsr() \
  (&((*RteIRead_BTHM_100ms_CIL_TBdSnsr_CIL_TBdSnsr())[0]))

#define RteIRead_BTHM_100ms_CIL_TBdSnsr_CIL_TBdSnsr() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TBdSnsr_CIL_TBdSnsr.value)

#define Rte_IRead_BTHM_100ms_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TCooltPackInSnsr_CIL_TCooltPackInSnsr.value)

#define Rte_IRead_BTHM_100ms_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TCooltPackOutSnsr_CIL_TCooltPackOutSnsr.value)

#define Rte_IRead_BTHM_100ms_CIL_TMdul_CIL_TMdul() \
  (&((*RteIRead_BTHM_100ms_CIL_TMdul_CIL_TMdul())[0]))

#define RteIRead_BTHM_100ms_CIL_TMdul_CIL_TMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TMdul_CIL_TMdul.value)

#define Rte_IRead_BTHM_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr() \
  (&((*RteIRead_BTHM_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr())[0]))

#define RteIRead_BTHM_100ms_CIL_TMdulCtlr_CIL_TMdulCtlr() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TMdulCtlr_CIL_TMdulCtlr.value)

#define Rte_IRead_BTHM_100ms_CIL_TSnsrI_CIL_TSnsrI() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_TSnsrI_CIL_TSnsrI.value)

#define Rte_IRead_BTHM_100ms_CIL_UObcChOutp_CIL_UObcChOutp() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_UObcChOutp_CIL_UObcChOutp.value)

#define Rte_IRead_BTHM_100ms_CIL_bDCDCW_CIL_bDCDCW() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_bDCDCW_CIL_bDCDCW.value)

#define Rte_IRead_BTHM_100ms_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value)

#define Rte_IRead_BTHM_100ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BTHM_100ms_CTC_StRlyHeat_CTC_StRlyHeat() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CTC_StRlyHeat_CTC_StRlyHeat.value)

#define Rte_IRead_BTHM_100ms_CTC_StRlyPos_CTC_StRlyPos() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CTC_StRlyPos_CTC_StRlyPos.value)

#define Rte_IRead_BTHM_100ms_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_CTC_bAcvRePrechFnshd_CTC_bAcvRePrechFnshd.value)

#define Rte_IRead_BTHM_100ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_BTHM_100ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_BTHM_100ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_BTHM_100ms_DEH_bAcvHeatInh_DEH_bAcvHeatInh() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_DEH_bAcvHeatInh_DEH_bAcvHeatInh.value)

#define Rte_IRead_BTHM_100ms_MCC_NrAFETot_MCC_NrAFETot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrAFETot_MCC_NrAFETot.value)

#define Rte_IRead_BTHM_100ms_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrMdulCtlrSnsrTTot_MCC_NrMdulCtlrSnsrTTot.value)

#define Rte_IRead_BTHM_100ms_MCC_NrMdulTot_MCC_NrMdulTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value)

#define Rte_IRead_BTHM_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul() \
  (&((*RteIRead_BTHM_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul())[0]))

#define RteIRead_BTHM_100ms_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrSnsrTByMdul_MCC_NrSnsrTByMdul.value)

#define Rte_IRead_BTHM_100ms_MCC_NrSnsrTTot_MCC_NrSnsrTTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_NrSnsrTTot_MCC_NrSnsrTTot.value)

#define Rte_IRead_BTHM_100ms_MCC_StMdulCu_MCC_StMdulCu() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatThermHndlgMngt_BTHM_100ms.Rte_MCC_StMdulCu_MCC_StMdulCu.value)

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
FUNC(void, swc_BatThermHndlgMngt_CODE) BTHM_100ms(void);
FUNC(void, swc_BatThermHndlgMngt_CODE) BTHM_Init(void);
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
#endif /* RTE_SWC_BATTHERMHNDLGMNGT_H_ */
 
 
 
