 
/*
************************************************************************************************************************
*
* File name: Rte_swc_BatProtnIU.h
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
#ifndef RTE_SWC_BATPROTNIU_H_
#define RTE_SWC_BATPROTNIU_H_

#include "Rte_swc_BatProtnIU_Type.h"
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
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellU_BPIU_ErrCellU;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellUDif_BPIU_ErrCellUDif;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrCellUOver_BPIU_ErrCellUOver;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIChLim_BPIU_ErrIChLim;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrInfo_BPIU_ErrInfo;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_ErrUAcqn_BPIU_ErrUAcqn;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMax_BPIU_IdCellUMax;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdCellUMin_BPIU_IdCellUMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StChkUMax_BPIU_StChkUMax;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_StChkUMin_BPIU_StChkUMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMax_BPIU_UCellMax;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnIU_BPIU_UCellMin_BPIU_UCellMin;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IChLim_BCF_IChLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_IDchaLim_BCF_IDchaLim;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UBatTotInt_BCF_UBatTotInt;
extern VAR(rt_Array_Float_24, RTE_VAR_INIT) Rte_swc_BatCoreFct_BCF_UMdul_BCF_UMdul;
extern VAR(rt_Array_Float_255, RTE_VAR_INIT) Rte_swc_CIL_BMC_UCell_BMC_UCell;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IChAct_BPP_IChAct;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatProtnPack_BPP_IDchaAct_BPP_IDchaAct;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_BatThermHndlgMngt_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_IBatHv_CIL_IBatHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StAcChCnct_CIL_StAcChCnct;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StPtIndcr_CIL_StPtIndcr;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UTrml30_CIL_UTrml30;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_CIL_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldBatIHv_CIL_bVldBatIHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(rt_Array_UInt8_24, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellByMdul_MCC_NrCellByMdul;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrCellTot_MCC_NrCellTot;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_MCC_NrMdulTot_MCC_NrMdulTot;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE2_QM_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE2_QM_VAR_NO_INIT
#include "Rte_MemMap.h"
extern VAR(Rte_ts_App1_Task_50ms_Core2_QM, RTE_VAR_NOINIT) Rte_App1_Task_50ms_Core2_QM;
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
#define Rte_IRead_BPIU_50ms_BCF_IChLim_BCF_IChLim() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BCF_IChLim_BCF_IChLim.value)

#define Rte_IRead_BPIU_50ms_BCF_IDchaLim_BCF_IDchaLim() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BCF_IDchaLim_BCF_IDchaLim.value)

#define Rte_IRead_BPIU_100ms_BCF_UBatTotInt_BCF_UBatTotInt() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BCF_UBatTotInt_BCF_UBatTotInt.value)

#define Rte_IRead_BPIU_100ms_BCF_UMdul_BCF_UMdul() \
  (&((*RteIRead_BPIU_100ms_BCF_UMdul_BCF_UMdul())[0]))

#define RteIRead_BPIU_100ms_BCF_UMdul_BCF_UMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BCF_UMdul_BCF_UMdul.value)

#define Rte_IRead_BPIU_100ms_BMC_UCell_BMC_UCell() \
  (&((*RteIRead_BPIU_100ms_BMC_UCell_BMC_UCell())[0]))

#define RteIRead_BPIU_100ms_BMC_UCell_BMC_UCell() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BMC_UCell_BMC_UCell.value)

#define Rte_IWrite_BPIU_100ms_BPIU_ErrCellU_BPIU_ErrCellU(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellU_BPIU_ErrCellU.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_ErrCellU_BPIU_ErrCellU() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellU_BPIU_ErrCellU.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_ErrCellUDif_BPIU_ErrCellUDif(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellUDif_BPIU_ErrCellUDif.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_ErrCellUDif_BPIU_ErrCellUDif() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellUDif_BPIU_ErrCellUDif.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_ErrCellUOver_BPIU_ErrCellUOver(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellUOver_BPIU_ErrCellUOver.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_ErrCellUOver_BPIU_ErrCellUOver() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrCellUOver_BPIU_ErrCellUOver.value \
)

#define Rte_IWrite_BPIU_50ms_BPIU_ErrIChLim_BPIU_ErrIChLim(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIChLim_BPIU_ErrIChLim.value = (data) \
)

#define Rte_IWriteRef_BPIU_50ms_BPIU_ErrIChLim_BPIU_ErrIChLim() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIChLim_BPIU_ErrIChLim.value \
)

#define Rte_IWrite_BPIU_50ms_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim.value = (data) \
)

#define Rte_IWriteRef_BPIU_50ms_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIDchaLim_BPIU_ErrIDchaLim.value \
)

#define Rte_IWrite_BPIU_50ms_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur.value = (data) \
)

#define Rte_IWriteRef_BPIU_50ms_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrIRgnOvcur_BPIU_ErrIRgnOvcur.value \
)

#define Rte_IWrite_BPIU_50ms_BPIU_ErrInfo_BPIU_ErrInfo(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrInfo_BPIU_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_BPIU_50ms_BPIU_ErrInfo_BPIU_ErrInfo() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrInfo_BPIU_ErrInfo.value \
)

#define Rte_IWrite_BPIU_50ms_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI.value = (data) \
)

#define Rte_IWriteRef_BPIU_50ms_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_ErrPackSnsrI_BPIU_ErrPackSnsrI.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_ErrUAcqn_BPIU_ErrUAcqn(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrUAcqn_BPIU_ErrUAcqn.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_ErrUAcqn_BPIU_ErrUAcqn() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_ErrUAcqn_BPIU_ErrUAcqn.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_IdCellUMax_BPIU_IdCellUMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_IdCellUMax_BPIU_IdCellUMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value \
)

#define Rte_IWrite_BatProtnIU_Init_BPIU_IdCellUMax_BPIU_IdCellUMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value = (data) \
)

#define Rte_IWriteRef_BatProtnIU_Init_BPIU_IdCellUMax_BPIU_IdCellUMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdCellUMax_BPIU_IdCellUMax.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_IdCellUMin_BPIU_IdCellUMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_IdCellUMin_BPIU_IdCellUMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value \
)

#define Rte_IWrite_BatProtnIU_Init_BPIU_IdCellUMin_BPIU_IdCellUMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value = (data) \
)

#define Rte_IWriteRef_BatProtnIU_Init_BPIU_IdCellUMin_BPIU_IdCellUMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdCellUMin_BPIU_IdCellUMin.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax.value \
)

#define Rte_IWrite_BatProtnIU_Init_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax.value = (data) \
)

#define Rte_IWriteRef_BatProtnIU_Init_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdMdulForCellUMax_BPIU_IdMdulForCellUMax.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin.value \
)

#define Rte_IWrite_BatProtnIU_Init_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin.value = (data) \
)

#define Rte_IWriteRef_BatProtnIU_Init_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_IdMdulForCellUMin_BPIU_IdMdulForCellUMin.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_StCellUChkOverMax_BPIU_StCellUChkOverMax.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_StCellUChkOverMin_BPIU_StCellUChkOverMin.value \
)

#define Rte_IWrite_BPIU_50ms_BPIU_StChkUMax_BPIU_StChkUMax(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_StChkUMax_BPIU_StChkUMax.value = (data) \
)

#define Rte_IWriteRef_BPIU_50ms_BPIU_StChkUMax_BPIU_StChkUMax() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_StChkUMax_BPIU_StChkUMax.value \
)

#define Rte_IWrite_BPIU_50ms_BPIU_StChkUMin_BPIU_StChkUMin(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_StChkUMin_BPIU_StChkUMin.value = (data) \
)

#define Rte_IWriteRef_BPIU_50ms_BPIU_StChkUMin_BPIU_StChkUMin() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPIU_StChkUMin_BPIU_StChkUMin.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_UCellMax_BPIU_UCellMax(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_UCellMax_BPIU_UCellMax() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_UCellMax_BPIU_UCellMax.value \
)

#define Rte_IWrite_BatProtnIU_Init_BPIU_UCellMax_BPIU_UCellMax(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_UCellMax_BPIU_UCellMax.value = (data) \
)

#define Rte_IWriteRef_BatProtnIU_Init_BPIU_UCellMax_BPIU_UCellMax() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_UCellMax_BPIU_UCellMax.value \
)

#define Rte_IWrite_BPIU_100ms_BPIU_UCellMin_BPIU_UCellMin(data) \
( \
  Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value = (data) \
)

#define Rte_IWriteRef_BPIU_100ms_BPIU_UCellMin_BPIU_UCellMin() \
( \
  &Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BPIU_UCellMin_BPIU_UCellMin.value \
)

#define Rte_IWrite_BatProtnIU_Init_BPIU_UCellMin_BPIU_UCellMin(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_UCellMin_BPIU_UCellMin.value = (data) \
)

#define Rte_IWriteRef_BatProtnIU_Init_BPIU_UCellMin_BPIU_UCellMin() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_BatProtnIU_BatProtnIU_Init.Rte_BPIU_UCellMin_BPIU_UCellMin.value \
)

#define Rte_IRead_BPIU_50ms_BPP_IChAct_BPP_IChAct() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPP_IChAct_BPP_IChAct.value)

#define Rte_IRead_BPIU_50ms_BPP_IDchaAct_BPP_IDchaAct() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BPP_IDchaAct_BPP_IDchaAct.value)

#define Rte_IRead_BPIU_50ms_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BSOF_ValDcChrgrPlgOr_BSOF_ValDcChrgrPlgOr.value)

#define Rte_IRead_BPIU_100ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_BPIU_50ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_BPIU_100ms_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_BTHM_TMdulSnsrMinRaw_BTHM_TMdulSnsrMinRaw.value)

#define Rte_IRead_BPIU_50ms_CIL_IBatHv_CIL_IBatHv() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_IBatHv_CIL_IBatHv.value)

#define Rte_IRead_BPIU_50ms_CIL_StAcChCnct_CIL_StAcChCnct() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_StAcChCnct_CIL_StAcChCnct.value)

#define Rte_IRead_BPIU_50ms_CIL_StPtIndcr_CIL_StPtIndcr() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_StPtIndcr_CIL_StPtIndcr.value)

#define Rte_IRead_BPIU_100ms_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_BPIU_50ms_CIL_UTrml30_CIL_UTrml30() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_UTrml30_CIL_UTrml30.value)

#define Rte_IRead_BPIU_50ms_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_bErrCtrBatIHv_CIL_bErrCtrBatIHv.value)

#define Rte_IRead_BPIU_100ms_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_bErrCtrBatUHv_CIL_bErrCtrBatUHv.value)

#define Rte_IRead_BPIU_50ms_CIL_bVldBatIHv_CIL_bVldBatIHv() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_CIL_bVldBatIHv_CIL_bVldBatIHv.value)

#define Rte_IRead_BPIU_100ms_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_bVldCellTSamplg_CIL_bVldCellTSamplg.value)

#define Rte_IRead_BPIU_100ms_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_bVldCellUSamplg_CIL_bVldCellUSamplg.value)

#define Rte_IRead_BPIU_100ms_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_CIL_bVldUMainPosPoleBefRly_CIL_bVldUMainPosPoleBefRly.value)

#define Rte_IRead_BPIU_100ms_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_DEH_CtrCellLvlErrRstDiag_DEH_CtrCellLvlErrRstDiag.value)

#define Rte_IRead_BPIU_100ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_BPIU_50ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_BPIU_50ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_BPIU_100ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_BPIU_100ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_BPIU_50ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_50ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_BPIU_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&((*RteIRead_BPIU_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul())[0]))

#define RteIRead_BPIU_100ms_MCC_NrCellByMdul_MCC_NrCellByMdul() \
  (&Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_MCC_NrCellByMdul_MCC_NrCellByMdul.value)

#define Rte_IRead_BPIU_100ms_MCC_NrCellTot_MCC_NrCellTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_MCC_NrCellTot_MCC_NrCellTot.value)

#define Rte_IRead_BPIU_100ms_MCC_NrMdulTot_MCC_NrMdulTot() \
  (Rte_App1_Task_100ms_Core2_QM.Rte_RB.Rte_swc_BatProtnIU_BPIU_100ms.Rte_MCC_NrMdulTot_MCC_NrMdulTot.value)

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
FUNC(void, swc_BatProtnIU_CODE) BPIU_100ms(void);
FUNC(void, swc_BatProtnIU_CODE) BPIU_50ms(void);
FUNC(void, swc_BatProtnIU_CODE) BatProtnIU_Init(void);
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
#endif /* RTE_SWC_BATPROTNIU_H_ */
 
 
 
