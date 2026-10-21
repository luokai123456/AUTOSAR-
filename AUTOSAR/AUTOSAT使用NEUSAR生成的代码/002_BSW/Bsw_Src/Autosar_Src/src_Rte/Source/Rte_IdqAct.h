 
/*
************************************************************************************************************************
*
* File name: Rte_IdqAct.h
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
#ifndef RTE_IDQACT_H_
#define RTE_IDQACT_H_

#include "Rte_IdqAct_Type.h"
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

#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iAa_IdqAct_iAa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iBa_IdqAct_iBa;
extern VAR(Float, RTE_VAR_INIT) Rte_AngSwDecod_AngSwDecod_agRotate_AngSwDecod_agRotate;
extern VAR(Float, RTE_VAR_INIT) Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDa_IdqAct_iDa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQa_IdqAct_iQa;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt;
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_AngSwDecod_agRotate_AngSwDecod_agRotate(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iAa_IdqAct_iAa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iBa_IdqAct_iBa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iDa_IdqAct_iDa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iQa_IdqAct_iQa(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_IdqAct_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(P2VAR(Float, AUTOMATIC, RTE_IdqAct_APPL_DATA) data);
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
#define Rte_Read_AngSwDecod_agRotate_AngSwDecod_agRotate Rte_Read_IdqAct_AngSwDecod_agRotate_AngSwDecod_agRotate
#define Rte_Read_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp Rte_Read_IdqAct_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp
#define Rte_Read_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU Rte_Read_IdqAct_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU
#define Rte_Read_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV Rte_Read_IdqAct_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV
#define Rte_Read_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW Rte_Read_IdqAct_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW
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
#define Rte_Write_IdqAct_iAa_IdqAct_iAa Rte_Write_IdqAct_IdqAct_iAa_IdqAct_iAa
#define Rte_Write_IdqAct_iBa_IdqAct_iBa Rte_Write_IdqAct_IdqAct_iBa_IdqAct_iBa
#define Rte_Write_IdqAct_iDa_IdqAct_iDa Rte_Write_IdqAct_IdqAct_iDa_IdqAct_iDa
#define Rte_Write_IdqAct_iDaFiltd_IdqAct_iDaFiltd Rte_Write_IdqAct_IdqAct_iDaFiltd_IdqAct_iDaFiltd
#define Rte_Write_IdqAct_iQa_IdqAct_iQa Rte_Write_IdqAct_IdqAct_iQa_IdqAct_iQa
#define Rte_Write_IdqAct_iQaFiltd_IdqAct_iQaFiltd Rte_Write_IdqAct_IdqAct_iQaFiltd_IdqAct_iQaFiltd
#define Rte_Write_IdqAct_iSqrt_IdqAct_iSqrt Rte_Write_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt
#define Rte_Write_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd Rte_Write_IdqAct_IdqAct_iSqrtFiltd_IdqAct_iSqrtFiltd
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
FUNC(void, IdqAct_CODE) IdqAct_Init(void);
FUNC(void, IdqAct_CODE) fc_IdqAct(void);
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
#endif /* RTE_IDQACT_H_ */
 
 
 
