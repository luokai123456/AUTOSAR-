 
/*
************************************************************************************************************************
*
* File name: Rte_swc_EltlLnkHzrdProtnNet.h
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
#ifndef RTE_SWC_ELTLLNKHZRDPROTNNET_H_
#define RTE_SWC_ELTLLNKHZRDPROTNNET_H_

#include "Rte_swc_EltlLnkHzrdProtnNet_Type.h"
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
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_ErrInfo_ELHPN_ErrInfo;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNeg_ELHPN_RIslnNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPos_ELHPN_RIslnPos;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrash_ELHPN_StCrash;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StCrashIni_ELHPN_StCrashIni;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIsln_ELHPN_StIsln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StIslnErr_ELHPN_StIslnErr;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIsln_ELHPN_StVehIsln;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_EltlLnkHzrdProtnNet_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BcuStTranCtl_BSTC_StBcu_BSTC_StBcu;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_CIL_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycCrash_CIL_DucycCrash;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_DucycHvil_CIL_DucycHvil;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_FrqCrash_CIL_FrqCrash;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_FrqHvil_CIL_FrqHvil;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RIslnNeg_CIL_RIslnNeg;
extern VAR(SInt32, RTE_VAR_INIT) Rte_swc_CIL_CIL_RIslnPos_CIL_RIslnPos;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CIL_CIL_StCrash_CIL_StCrash;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_CIL_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StHvbat_CTC_StHvbat;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_CtctrTranCtl_CTC_StLoopHv_CTC_StLoopHv;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_EnaDiagGlb_DEH_EnaDiagGlb;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd1_DEH_ErrCfmd1;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd3_DEH_ErrCfmd3;
extern VAR(UInt32, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrCfmd5_DEH_ErrCfmd5;
extern VAR(UInt16, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_ErrHisCfmd_DEH_ErrHisCfmd;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_RstDiagGlb_DEH_RstDiagGlb;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StIslnMeasReq_DEH_StIslnMeasReq;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_StsIninNv_DEH_StsIninNv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_DEH_bAcvBdNew_DEH_bAcvBdNew;
extern VAR(UInt8, RTE_VAR_INIT) Rte_swc_BatChCtl_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RIslnNeg_NVM_RIslnNeg;
extern VAR(Float, RTE_VAR_INIT) Rte_swc_DiagcEveHndlg_NVM_RIslnPos_NVM_RIslnPos;
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
#define Rte_IRead_ELHPN_50ms_BSTC_StBcu_BSTC_StBcu() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_BSTC_StBcu_BSTC_StBcu.value)

#define Rte_IRead_ELHPN_50ms_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_CtrIslnRSamplg_CIL_CtrIslnRSamplg.value)

#define Rte_IRead_ELHPN_50ms_CIL_DucycCrash_CIL_DucycCrash() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_DucycCrash_CIL_DucycCrash.value)

#define Rte_IRead_ELHPN_50ms_CIL_DucycHvil_CIL_DucycHvil() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_DucycHvil_CIL_DucycHvil.value)

#define Rte_IRead_ELHPN_50ms_CIL_FrqCrash_CIL_FrqCrash() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_FrqCrash_CIL_FrqCrash.value)

#define Rte_IRead_ELHPN_50ms_CIL_FrqHvil_CIL_FrqHvil() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_FrqHvil_CIL_FrqHvil.value)

#define Rte_IRead_ELHPN_50ms_CIL_RIslnNeg_CIL_RIslnNeg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_RIslnNeg_CIL_RIslnNeg.value)

#define Rte_IRead_ELHPN_50ms_CIL_RIslnPos_CIL_RIslnPos() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_RIslnPos_CIL_RIslnPos.value)

#define Rte_IRead_ELHPN_50ms_CIL_StCrash_CIL_StCrash() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_StCrash_CIL_StCrash.value)

#define Rte_IRead_ELHPN_50ms_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CIL_UMainPosPoleBefRly_CIL_UMainPosPoleBefRly.value)

#define Rte_IRead_ELHPN_50ms_CTC_StHvbat_CTC_StHvbat() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CTC_StHvbat_CTC_StHvbat.value)

#define Rte_IRead_ELHPN_50ms_CTC_StLoopHv_CTC_StLoopHv() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_CTC_StLoopHv_CTC_StLoopHv.value)

#define Rte_IRead_ELHPN_50ms_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_CtrIslnMeasReqDiag_DEH_CtrIslnMeasReqDiag.value)

#define Rte_IRead_ELHPN_50ms_DEH_EnaDiagGlb_DEH_EnaDiagGlb() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_EnaDiagGlb_DEH_EnaDiagGlb.value)

#define Rte_IRead_ELHPN_50ms_DEH_ErrCfmd1_DEH_ErrCfmd1() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_ErrCfmd1_DEH_ErrCfmd1.value)

#define Rte_IRead_ELHPN_50ms_DEH_ErrCfmd3_DEH_ErrCfmd3() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_ErrCfmd3_DEH_ErrCfmd3.value)

#define Rte_IRead_ELHPN_50ms_DEH_ErrCfmd5_DEH_ErrCfmd5() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_ErrCfmd5_DEH_ErrCfmd5.value)

#define Rte_IRead_ELHPN_50ms_DEH_ErrHisCfmd_DEH_ErrHisCfmd() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_ErrHisCfmd_DEH_ErrHisCfmd.value)

#define Rte_IRead_ELHPN_50ms_DEH_RstDiagGlb_DEH_RstDiagGlb() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_RstDiagGlb_DEH_RstDiagGlb.value)

#define Rte_IRead_ELHPN_50ms_DEH_StIslnMeasReq_DEH_StIslnMeasReq() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_StIslnMeasReq_DEH_StIslnMeasReq.value)

#define Rte_IRead_ELHPN_50ms_DEH_StsIninNv_DEH_StsIninNv() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_StsIninNv_DEH_StsIninNv.value)

#define Rte_IRead_ELHPN_50ms_DEH_bAcvBdNew_DEH_bAcvBdNew() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_DEH_bAcvBdNew_DEH_bAcvBdNew.value)

#define Rte_IWrite_ELHPN_50ms_ELHPN_ErrInfo_ELHPN_ErrInfo(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_ErrInfo_ELHPN_ErrInfo.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_ErrInfo_ELHPN_ErrInfo() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_ErrInfo_ELHPN_ErrInfo.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_RIslnNeg_ELHPN_RIslnNeg(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_RIslnNeg_ELHPN_RIslnNeg() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnNeg_ELHPN_RIslnNeg.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnNegNv_ELHPN_RIslnNegNv.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_RIslnPos_ELHPN_RIslnPos(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnPos_ELHPN_RIslnPos.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_RIslnPos_ELHPN_RIslnPos() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnPos_ELHPN_RIslnPos.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_RIslnPosNv_ELHPN_RIslnPosNv.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StCrash_ELHPN_StCrash(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StCrash_ELHPN_StCrash.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StCrash_ELHPN_StCrash() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StCrash_ELHPN_StCrash.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StCrashIni_ELHPN_StCrashIni(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StCrashIni_ELHPN_StCrashIni.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StCrashIni_ELHPN_StCrashIni() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StCrashIni_ELHPN_StCrashIni.value \
)

#define Rte_IWrite_ELHPN_Init_ELHPN_StCrashIni_ELHPN_StCrashIni(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StCrashIni_ELHPN_StCrashIni.value = (data) \
)

#define Rte_IWriteRef_ELHPN_Init_ELHPN_StCrashIni_ELHPN_StCrashIni() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StCrashIni_ELHPN_StCrashIni.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrHvIntlc_ELHPN_StErrHvIntlc.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc.value \
)

#define Rte_IWrite_ELHPN_Init_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc.value = (data) \
)

#define Rte_IWriteRef_ELHPN_Init_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StErrIniHvIntlc_ELHPN_StErrIniHvIntlc.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StErrIniHvIntlc2_ELHPN_StErrIniHvIntlc2.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StIsln_ELHPN_StIsln(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StIsln_ELHPN_StIsln.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StIsln_ELHPN_StIsln() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StIsln_ELHPN_StIsln.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StIslnErr_ELHPN_StIslnErr(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StIslnErr_ELHPN_StIslnErr.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StIslnErr_ELHPN_StIslnErr() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StIslnErr_ELHPN_StIslnErr.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StVehIsln_ELHPN_StVehIsln(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StVehIsln_ELHPN_StVehIsln.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StVehIsln_ELHPN_StVehIsln() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StVehIsln_ELHPN_StVehIsln.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni.value \
)

#define Rte_IWrite_ELHPN_Init_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni(data) \
( \
  Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni.value = (data) \
)

#define Rte_IWriteRef_ELHPN_Init_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni() \
( \
  &Rte_SWC_Init_Task_Core2.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_Init.Rte_ELHPN_StVehIslnIni_ELHPN_StVehIslnIni.value \
)

#define Rte_IWrite_ELHPN_50ms_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas(data) \
( \
  Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas.value = (data) \
)

#define Rte_IWriteRef_ELHPN_50ms_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas() \
( \
  &Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_ELHPN_bInhIslnMeas_ELHPN_bInhIslnMeas.value \
)

#define Rte_IRead_ELHPN_50ms_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_EVCSH_StIslnMeasReq_EVCSH_StIslnMeasReq.value)

#define Rte_IRead_ELHPN_50ms_NVM_RIslnNeg_NVM_RIslnNeg() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_NVM_RIslnNeg_NVM_RIslnNeg.value)

#define Rte_IRead_ELHPN_50ms_NVM_RIslnPos_NVM_RIslnPos() \
  (Rte_App1_Task_50ms_Core2_QM.Rte_RB.Rte_swc_EltlLnkHzrdProtnNet_ELHPN_50ms.Rte_NVM_RIslnPos_NVM_RIslnPos.value)

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
FUNC(void, swc_SetOutputInterface_CODE) If_PwmValueOutput_SetPwmValue(VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) NumId, VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) Period, VAR(UInt32, RTE_swc_SetOutputInterface_APPL_DATA) Ducy);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

#ifndef RTE_CORE
#define Rte_Call_If_PwmValueOutput_SetPwmValue Rte_Call_swc_EltlLnkHzrdProtnNet_If_PwmValueOutput_SetPwmValue
#define Rte_Call_swc_EltlLnkHzrdProtnNet_If_PwmValueOutput_SetPwmValue(arg1, arg2, arg3) (If_PwmValueOutput_SetPwmValue(arg1, arg2, arg3), ((Std_ReturnType)RTE_E_OK))
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
FUNC(void, swc_EltlLnkHzrdProtnNet_CODE) ELHPN_50ms(void);
FUNC(void, swc_EltlLnkHzrdProtnNet_CODE) ELHPN_Init(void);
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
#endif /* RTE_SWC_ELTLLNKHZRDPROTNNET_H_ */
 
 
 
