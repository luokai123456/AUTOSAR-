 
/*
************************************************************************************************************************
*
* File name: Rte_DernInv.h
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
#ifndef RTE_DERNINV_H_
#define RTE_DERNINV_H_

#include "Rte_DernInv_Type.h"
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
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_bIvtrCooltTempLimActv_DernInv_bIvtrCooltTempLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_bIvtrCooltTempLimZeroActv_DernInv_bIvtrCooltTempLimZeroActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_bSicTempLimActv_DernInv_bSicTempLimActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_bSicTempLimZeroActv_DernInv_bSicTempLimZeroActv;
extern VAR(Boolean, RTE_VAR_INIT) Rte_DernInv_DernInv_biSqrtLimActv_DernInv_biSqrtLimActv;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim;
extern VAR(Float, RTE_VAR_INIT) Rte_DernInv_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim;
extern VAR(Float, RTE_VAR_INIT) Rte_ComRx_CAN_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_IdqAct_IdqAct_iSqrt_IdqAct_iSqrt;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySic_TempDev_tPhySic;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernInv_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet(P2VAR(Float, AUTOMATIC, RTE_DernInv_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_bIvtrCooltTempLimActv_DernInv_bIvtrCooltTempLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_bIvtrCooltTempLimZeroActv_DernInv_bIvtrCooltTempLimZeroActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_bSicTempLimActv_DernInv_bSicTempLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_bSicTempLimZeroActv_DernInv_bSicTempLimZeroActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_biSqrtLimActv_DernInv_biSqrtLimActv(Boolean data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_DernInv_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernInv_IdqAct_iSqrt_IdqAct_iSqrt(P2VAR(Float, AUTOMATIC, RTE_DernInv_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_DernInv_TempDev_tPhySic_TempDev_tPhySic(P2VAR(Float, AUTOMATIC, RTE_DernInv_APPL_DATA) data);
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
#define Rte_Read_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet Rte_Read_DernInv_ComRx_tIvtrCooltInlet_ComRx_tIvtrCooltInlet
#define Rte_Read_IdqAct_iSqrt_IdqAct_iSqrt Rte_Read_DernInv_IdqAct_iSqrt_IdqAct_iSqrt
#define Rte_Read_TempDev_tPhySic_TempDev_tPhySic Rte_Read_DernInv_TempDev_tPhySic_TempDev_tPhySic
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
#define Rte_Write_DernInv_bIvtrCooltTempLimActv_DernInv_bIvtrCooltTempLimActv Rte_Write_DernInv_DernInv_bIvtrCooltTempLimActv_DernInv_bIvtrCooltTempLimActv
#define Rte_Write_DernInv_bIvtrCooltTempLimZeroActv_DernInv_bIvtrCooltTempLimZeroActv Rte_Write_DernInv_DernInv_bIvtrCooltTempLimZeroActv_DernInv_bIvtrCooltTempLimZeroActv
#define Rte_Write_DernInv_bSicTempLimActv_DernInv_bSicTempLimActv Rte_Write_DernInv_DernInv_bSicTempLimActv_DernInv_bSicTempLimActv
#define Rte_Write_DernInv_bSicTempLimZeroActv_DernInv_bSicTempLimZeroActv Rte_Write_DernInv_DernInv_bSicTempLimZeroActv_DernInv_bSicTempLimZeroActv
#define Rte_Write_DernInv_biSqrtLimActv_DernInv_biSqrtLimActv Rte_Write_DernInv_DernInv_biSqrtLimActv_DernInv_biSqrtLimActv
#define Rte_Write_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim Rte_Write_DernInv_DernInv_facGenTempIvtrCooltLim_DernInv_facGenTempIvtrCooltLim
#define Rte_Write_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim Rte_Write_DernInv_DernInv_facGenTempSicLim_DernInv_facGenTempSicLim
#define Rte_Write_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim Rte_Write_DernInv_DernInv_facGeniSqrtLim_DernInv_facGeniSqrtLim
#define Rte_Write_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim Rte_Write_DernInv_DernInv_facMotTempIvtrCooltLim_DernInv_facMotTempIvtrCooltLim
#define Rte_Write_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim Rte_Write_DernInv_DernInv_facMotTempSicLim_DernInv_facMotTempSicLim
#define Rte_Write_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim Rte_Write_DernInv_DernInv_facMotiSqrtLim_DernInv_facMotiSqrtLim
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
FUNC(void, DernInv_CODE) DernInv_Init(void);
FUNC(void, DernInv_CODE) fc_DernInv(void);
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
#endif /* RTE_DERNINV_H_ */
 
 
 
