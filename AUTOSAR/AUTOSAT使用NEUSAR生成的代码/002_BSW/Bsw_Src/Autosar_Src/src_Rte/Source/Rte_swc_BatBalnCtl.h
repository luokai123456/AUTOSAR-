 
/*
************************************************************************************************************************
*
* File name: Rte_swc_BatBalnCtl.h
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
#ifndef RTE_SWC_BATBALNCTL_H_
#define RTE_SWC_BATBALNCTL_H_

#include "Rte_swc_BatBalnCtl_Type.h"
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
extern VAR(rt_Array_UInt32_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp;
extern VAR(rt_Array_UInt16_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp;
extern VAR(rt_Array_UInt16_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_ICellBaln_BBC_ICellBaln;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp;
extern VAR(rt_Array_UInt8_255, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvBaln_BBC_bAcvBaln;
extern VAR(rt_Array_Boolean_24, RTE_VAR_INIT) Rte_swc_BatBalnCtl_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatChCtl_BCC_IObcLimn_BCC_IObcLimn;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UCellAvg_BCF_UCellAvg;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_CIL_BMC_UCell_BMC_UCell;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_CIL_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_LvlErr_DEH_LvlErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ModBalCtl_DEH_ModBalCtl;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ReqBalCtl_DEH_ReqBalCtl;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
extern VAR(rt_Array_UInt8_255, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln;
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
#define Rte_IWrite_BBC_100ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp(data) \
  RteIWrite_BBC_100ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp(data)

#define RteIWrite_BBC_100ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp.value, data, sizeof(rt_Array_UInt32_24)) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp() \
  (&((*RteIWriteRef_BBC_100ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp())[0]))

#define RteIWriteRef_BBC_100ms_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_AcvCellSrcReqdOutp_BBC_AcvCellSrcReqdOutp.value \
)

#define Rte_IWrite_BBC_100ms_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp(data) \
  RteIWrite_BBC_100ms_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp(data)

#define RteIWrite_BBC_100ms_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp.value, data, sizeof(rt_Array_UInt16_24)) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp() \
  (&((*RteIWriteRef_BBC_100ms_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp())[0]))

#define RteIWriteRef_BBC_100ms_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_AcvCellTgtReqdOutp_BBC_AcvCellTgtReqdOutp.value \
)

#define Rte_IWrite_BBC_100ms_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp(data) \
  RteIWrite_BBC_100ms_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp(data)

#define RteIWrite_BBC_100ms_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp.value, data, sizeof(rt_Array_UInt16_24)) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp() \
  (&((*RteIWriteRef_BBC_100ms_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp())[0]))

#define RteIWriteRef_BBC_100ms_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_CtrBalnReqdOutp_BBC_CtrBalnReqdOutp.value \
)

#define Rte_IWrite_BBC_100ms_BBC_ICellBaln_BBC_ICellBaln(data) \
  RteIWrite_BBC_100ms_BBC_ICellBaln_BBC_ICellBaln(data)

#define RteIWrite_BBC_100ms_BBC_ICellBaln_BBC_ICellBaln(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_ICellBaln_BBC_ICellBaln.value, data, sizeof(rt_Array_Float_255)) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_ICellBaln_BBC_ICellBaln() \
  (&((*RteIWriteRef_BBC_100ms_BBC_ICellBaln_BBC_ICellBaln())[0]))

#define RteIWriteRef_BBC_100ms_BBC_ICellBaln_BBC_ICellBaln() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_ICellBaln_BBC_ICellBaln.value \
)

#define Rte_IWrite_BBC_100ms_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp(data) \
  RteIWrite_BBC_100ms_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp(data)

#define RteIWrite_BBC_100ms_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp() \
  (&((*RteIWriteRef_BBC_100ms_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp())[0]))

#define RteIWriteRef_BBC_100ms_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_NrMdulSrcReqdOutp_BBC_NrMdulSrcReqdOutp.value \
)

#define Rte_IWrite_BBC_100ms_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp(data) \
  RteIWrite_BBC_100ms_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp(data)

#define RteIWrite_BBC_100ms_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp.value, data, sizeof(rt_Array_UInt8_24)) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp() \
  (&((*RteIWriteRef_BBC_100ms_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp())[0]))

#define RteIWriteRef_BBC_100ms_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_NrMdulTgtReqdOutp_BBC_NrMdulTgtReqdOutp.value \
)

#define Rte_IWrite_BBC_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv(data) \
  RteIWrite_BBC_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv(data)

#define RteIWrite_BBC_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv.value, data, sizeof(rt_Array_UInt8_255)) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv() \
  (&((*RteIWriteRef_BBC_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv())[0]))

#define RteIWriteRef_BBC_100ms_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_RemTimeCellBalnNv_BBC_RemTimeCellBalnNv.value \
)

#define Rte_IWrite_BBC_100ms_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim.value = (data) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_TiCtlBalMaxLim_BBC_TiCtlBalMaxLim.value \
)

#define Rte_IWrite_BBC_100ms_BBC_bAcvBaln_BBC_bAcvBaln(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value = (data) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_bAcvBaln_BBC_bAcvBaln() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_bAcvBaln_BBC_bAcvBaln.value \
)

#define Rte_IWrite_BBC_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln(data) \
  RteIWrite_BBC_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln(data)

#define RteIWrite_BBC_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln(data) \
( \
  Rte_MemCpy(Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln.value, data, sizeof(rt_Array_Boolean_24)) \
)

#define Rte_IWriteRef_BBC_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln() \
  (&((*RteIWriteRef_BBC_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln())[0]))

#define RteIWriteRef_BBC_100ms_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BBC_bAcvMdulBaln_BBC_bAcvMdulBaln.value \
)

#define Rte_IRead_BBC_100ms_BCC_IObcLimn_BCC_IObcLimn() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BCC_IObcLimn_BCC_IObcLimn.value)

#define Rte_IRead_BBC_100ms_BCF_IChLim_BCF_IChLim() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BCF_IChLim_BCF_IChLim.value)

#define Rte_IRead_BBC_100ms_BCF_IDchaLim_BCF_IDchaLim() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value)

#define Rte_IRead_BBC_100ms_BCF_UCellAvg_BCF_UCellAvg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BCF_UCellAvg_BCF_UCellAvg.value)

#define Rte_IRead_BBC_100ms_BMC_UCell_BMC_UCell() \
  (&((*RteIRead_BBC_100ms_BMC_UCell_BMC_UCell())[0]))

#define RteIRead_BBC_100ms_BMC_UCell_BMC_UCell() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BMC_UCell_BMC_UCell.value)

#define Rte_IRead_BBC_100ms_BPIU_UCellMax_BPIU_UCellMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value)

#define Rte_IRead_BBC_100ms_BPIU_UCellMin_BPIU_UCellMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value)

#define Rte_IRead_BBC_100ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_BBC_100ms_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BTHM_TMdulSnsrMax_BTHM_TMdulSnsrMax.value)

#define Rte_IRead_BBC_100ms_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_BTHM_TMdulSnsrMin_BTHM_TMdulSnsrMin.value)

#define Rte_IRead_BBC_100ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_BBC_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE() \
  (&((*RteIRead_BBC_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE())[0]))

#define RteIRead_BBC_100ms_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_CIL_TMdulCtlrFromAFE_CIL_TMdulCtlrFromAFE.value)

#define Rte_IRead_BBC_100ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_BBC_100ms_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_CtrBalCtlDiag_DEH_CtrBalCtlDiag.value)

#define Rte_IRead_BBC_100ms_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_IdxCellBalCtl_DEH_IdxCellBalCtl.value)

#define Rte_IRead_BBC_100ms_DEH_LvlErr_DEH_LvlErr() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_LvlErr_DEH_LvlErr.value)

#define Rte_IRead_BBC_100ms_DEH_ModBalCtl_DEH_ModBalCtl() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_ModBalCtl_DEH_ModBalCtl.value)

#define Rte_IRead_BBC_100ms_DEH_ReqBalCtl_DEH_ReqBalCtl() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_DEH_ReqBalCtl_DEH_ReqBalCtl.value)

#define Rte_IRead_BBC_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&((*RteIRead_BBC_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul())[0]))

#define RteIRead_BBC_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value)

#define Rte_IRead_BBC_100ms_MCC_NrMdulTot_MCC_NrMdulTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value)

#define Rte_IRead_BBC_100ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln() \
  (&((*RteIRead_BBC_100ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln())[0]))

#define RteIRead_BBC_100ms_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatBalnCtl_BBC_100ms.Rte_NVM_RemTimeCellBaln_NVM_RemTimeCellBaln.value)

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
FUNC(void, swc_BatBalnCtl_CODE) BBC_100ms(void);
FUNC(void, swc_BatBalnCtl_CODE) BBC_Init(void);
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
#endif /* RTE_SWC_BATBALNCTL_H_ */
 
 
 
