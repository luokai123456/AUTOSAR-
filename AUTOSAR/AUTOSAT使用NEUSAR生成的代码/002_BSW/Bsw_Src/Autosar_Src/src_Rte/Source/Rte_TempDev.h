 
/*
************************************************************************************************************************
*
* File name: Rte_TempDev.h
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
#ifndef RTE_TEMPDEV_H_
#define RTE_TEMPDEV_H_

#include "Rte_TempDev_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySicU_TempDev_tPhySicU;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySicV_TempDev_tPhySicV;
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhySicW_TempDev_tPhySicW;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE5_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhyMot_BIfRx_tPhyMot;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicU_BIfRx_tPhySicU;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicV_BIfRx_tPhySicV;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_tPhySicW_BIfRx_tPhySicW;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_TempDev_TempDev_tPhyMot_TempDev_tPhyMot;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TempDev_BIfRx_tPhyMot_BIfRx_tPhyMot(P2VAR(Float, AUTOMATIC, RTE_TempDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TempDev_BIfRx_tPhySicU_BIfRx_tPhySicU(P2VAR(Float, AUTOMATIC, RTE_TempDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TempDev_BIfRx_tPhySicV_BIfRx_tPhySicV(P2VAR(Float, AUTOMATIC, RTE_TempDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_TempDev_BIfRx_tPhySicW_BIfRx_tPhySicW(P2VAR(Float, AUTOMATIC, RTE_TempDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhyMot_TempDev_tPhyMot(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhySic_TempDev_tPhySic(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhySicU_TempDev_tPhySicU(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhySicV_TempDev_tPhySicV(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_TempDev_TempDev_tPhySicW_TempDev_tPhySicW(Float data);
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
#define Rte_Read_BIfRx_tPhyMot_BIfRx_tPhyMot Rte_Read_TempDev_BIfRx_tPhyMot_BIfRx_tPhyMot
#define Rte_Read_BIfRx_tPhySicU_BIfRx_tPhySicU Rte_Read_TempDev_BIfRx_tPhySicU_BIfRx_tPhySicU
#define Rte_Read_BIfRx_tPhySicV_BIfRx_tPhySicV Rte_Read_TempDev_BIfRx_tPhySicV_BIfRx_tPhySicV
#define Rte_Read_BIfRx_tPhySicW_BIfRx_tPhySicW Rte_Read_TempDev_BIfRx_tPhySicW_BIfRx_tPhySicW
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
#define Rte_Write_TempDev_tPhyMot_TempDev_tPhyMot Rte_Write_TempDev_TempDev_tPhyMot_TempDev_tPhyMot
#define Rte_Write_TempDev_tPhyMotFild_TempDev_tPhyMotFild Rte_Write_TempDev_TempDev_tPhyMotFild_TempDev_tPhyMotFild
#define Rte_Write_TempDev_tPhySic_TempDev_tPhySic Rte_Write_TempDev_TempDev_tPhySic_TempDev_tPhySic
#define Rte_Write_TempDev_tPhySicU_TempDev_tPhySicU Rte_Write_TempDev_TempDev_tPhySicU_TempDev_tPhySicU
#define Rte_Write_TempDev_tPhySicV_TempDev_tPhySicV Rte_Write_TempDev_TempDev_tPhySicV_TempDev_tPhySicV
#define Rte_Write_TempDev_tPhySicW_TempDev_tPhySicW Rte_Write_TempDev_TempDev_tPhySicW_TempDev_tPhySicW
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
FUNC(void, TempDev_CODE) TempDev_Init(void);
FUNC(void, TempDev_CODE) fc_TempDev(void);
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
#endif /* RTE_TEMPDEV_H_ */
 
 
 
