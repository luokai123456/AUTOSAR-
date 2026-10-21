 
/*
************************************************************************************************************************
*
* File name: Rte_DernEm.h
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
#ifndef RTE_DERNEM_H_
#define RTE_DERNEM_H_

#include "Rte_DernEm_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernEm_DernEm_bRtrTempLimActv_DernEm_bRtrTempLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernEm_DernEm_bRtrTempLimZeroActv_DernEm_bRtrTempLimZeroActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernEm_DernEm_bStrTempLimActv_DernEm_bStrTempLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernEm_DernEm_bStrTempLimZeroActv_DernEm_bStrTempLimZeroActv;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facDernCurr_DernEm_facDernCurr;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernEm_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt16, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs;
extern VAR(Boolean, RTE_VAR_INIT) Rte_Diag_Diag_bMotStalFlt_Diag_bMotStalFlt;
extern VAR(Float, RTE_VAR_INIT) Rte_HvInvDev_HvInvDev_uPhyHV_HvInvDev_uPhyHV;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/
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
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs(P2VAR(UInt16, AUTOMATIC, RTE_DernEm_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bRtrTempLimActv_DernEm_bRtrTempLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bRtrTempLimZeroActv_DernEm_bRtrTempLimZeroActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bStrTempLimActv_DernEm_bStrTempLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_bStrTempLimZeroActv_DernEm_bStrTempLimZeroActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facDernCurr_DernEm_facDernCurr(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernEm_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_Diag_bMotStalFlt_Diag_bMotStalFlt(P2VAR(Boolean, AUTOMATIC, RTE_DernEm_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_EmTMdl_tRtr_EmTMdl_tRtr(P2VAR(Float, AUTOMATIC, RTE_DernEm_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_HvInvDev_uPhyHV_HvInvDev_uPhyHV(P2VAR(Float, AUTOMATIC, RTE_DernEm_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_IdqAct_iSqrt_IdqAct_iSqrt(P2VAR(Float, AUTOMATIC, RTE_DernEm_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernEm_TempDev_tPhyMotFild_TempDev_tPhyMotFild(P2VAR(Float, AUTOMATIC, RTE_DernEm_APPL_DATA) data);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
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
#define Rte_Read_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs Rte_Read_DernEm_AngSwDecod_nRotateSpdAbs_AngSwDecod_nRotateSpdAbs
#define Rte_Read_Diag_bMotStalFlt_Diag_bMotStalFlt Rte_Read_DernEm_Diag_bMotStalFlt_Diag_bMotStalFlt
#define Rte_Read_HvInvDev_uPhyHV_HvInvDev_uPhyHV Rte_Read_DernEm_HvInvDev_uPhyHV_HvInvDev_uPhyHV
#define Rte_Read_IdqAct_iSqrt_IdqAct_iSqrt Rte_Read_DernEm_IdqAct_iSqrt_IdqAct_iSqrt
#define Rte_Read_TempDev_tPhyMotFild_TempDev_tPhyMotFild Rte_Read_DernEm_TempDev_tPhyMotFild_TempDev_tPhyMotFild
#define Rte_Read_EmTMdl_tRtr_EmTMdl_tRtr Rte_Read_DernEm_EmTMdl_tRtr_EmTMdl_tRtr
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
#define Rte_Write_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl Rte_Write_DernEm_DernEm_bCurrDernCtrl_DernEm_bCurrDernCtrl
#define Rte_Write_DernEm_bRtrTempLimActv_DernEm_bRtrTempLimActv Rte_Write_DernEm_DernEm_bRtrTempLimActv_DernEm_bRtrTempLimActv
#define Rte_Write_DernEm_bRtrTempLimZeroActv_DernEm_bRtrTempLimZeroActv Rte_Write_DernEm_DernEm_bRtrTempLimZeroActv_DernEm_bRtrTempLimZeroActv
#define Rte_Write_DernEm_bStrTempLimActv_DernEm_bStrTempLimActv Rte_Write_DernEm_DernEm_bStrTempLimActv_DernEm_bStrTempLimActv
#define Rte_Write_DernEm_bStrTempLimZeroActv_DernEm_bStrTempLimZeroActv Rte_Write_DernEm_DernEm_bStrTempLimZeroActv_DernEm_bStrTempLimZeroActv
#define Rte_Write_DernEm_facDernCurr_DernEm_facDernCurr Rte_Write_DernEm_DernEm_facDernCurr_DernEm_facDernCurr
#define Rte_Write_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim Rte_Write_DernEm_DernEm_facGenTempRtrLim_DernEm_facGenTempRtrLim
#define Rte_Write_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim Rte_Write_DernEm_DernEm_facGenTempStrLim_DernEm_facGenTempStrLim
#define Rte_Write_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim Rte_Write_DernEm_DernEm_facMotTempRtrLim_DernEm_facMotTempRtrLim
#define Rte_Write_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim Rte_Write_DernEm_DernEm_facMotTempStrLim_DernEm_facMotTempStrLim
#define Rte_Write_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim Rte_Write_DernEm_DernEm_tqGenExtChartcLim_DernEm_tqGenExtChartcLim
#define Rte_Write_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim Rte_Write_DernEm_DernEm_tqMotExtChartcLim_DernEm_tqMotExtChartcLim
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
FUNC(void, DernEm_CODE) DernEm_Init(void);
FUNC(void, DernEm_CODE) fc_DernEm(void);
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
#endif /* RTE_DERNEM_H_ */
 
 
 
