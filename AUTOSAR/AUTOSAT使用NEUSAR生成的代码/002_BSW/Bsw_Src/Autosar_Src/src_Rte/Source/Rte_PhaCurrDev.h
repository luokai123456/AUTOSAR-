 
/*
************************************************************************************************************************
*
* File name: Rte_PhaCurrDev.h
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
#ifndef RTE_PHACURRDEV_H_
#define RTE_PHACURRDEV_H_

#include "Rte_PhaCurrDev_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW;
extern VAR(Float, RTE_VAR_INIT) Rte_DynFrq_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV;
extern VAR(Float, RTE_VAR_INIT) Rte_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#define RTE_START_SEC_APP1_APPLICATION_CORE5_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(Boolean, RTE_VAR_INIT) Rte_ExtTqDes_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy;
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU(P2VAR(Float, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV(P2VAR(Float, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW(P2VAR(Float, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp(P2VAR(Float, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PhaCurrDev_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy(P2VAR(Boolean, AUTOMATIC, RTE_PhaCurrDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW(Float data);
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
#define Rte_Read_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU Rte_Read_PhaCurrDev_BIfRx_iSmpPhaU_BIfRx_iSmpPhaU
#define Rte_Read_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV Rte_Read_PhaCurrDev_BIfRx_iSmpPhaV_BIfRx_iSmpPhaV
#define Rte_Read_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW Rte_Read_PhaCurrDev_BIfRx_iSmpPhaW_BIfRx_iSmpPhaW
#define Rte_Read_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp Rte_Read_PhaCurrDev_DynFrq_tiPWMSmp_DynFrq_tiPWMSmp
#define Rte_Read_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy Rte_Read_PhaCurrDev_ExtTqDes_bHvRdy_ExtTqDes_bHvRdy
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
#define Rte_Write_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU Rte_Write_PhaCurrDev_PhaCurrDev_iPhyU_PhaCurrDev_iPhyU
#define Rte_Write_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV Rte_Write_PhaCurrDev_PhaCurrDev_iPhyV_PhaCurrDev_iPhyV
#define Rte_Write_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW Rte_Write_PhaCurrDev_PhaCurrDev_iPhyW_PhaCurrDev_iPhyW
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
FUNC(void, PhaCurrDev_CODE) PhaCurrDev_Init(void);
FUNC(void, PhaCurrDev_CODE) fc_PhaCurrDev(void);
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
#endif /* RTE_PHACURRDEV_H_ */
 
 
 
