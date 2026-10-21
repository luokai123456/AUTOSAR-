 
/*
************************************************************************************************************************
*
* File name: Rte_AngEmDev.h
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
#ifndef RTE_ANGEMDEV_H_
#define RTE_ANGEMDEV_H_

#include "Rte_AngEmDev_Type.h"
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
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgCosN_AngEmDev_uPhyAgCosN;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgCosP_AngEmDev_uPhyAgCosP;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgExctN_AngEmDev_uPhyAgExctN;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgExctP_AngEmDev_uPhyAgExctP;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgSinN_AngEmDev_uPhyAgSinN;
extern VAR(Float, RTE_VAR_INIT) Rte_AngEmDev_AngEmDev_uPhyAgSinP_AngEmDev_uPhyAgSinP;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosN_BIfRx_uAgCosN;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgCosP_BIfRx_uAgCosP;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgExctN_BIfRx_uAgExctN;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgExctP_BIfRx_uAgExctP;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinN_BIfRx_uAgSinN;
extern VAR(Float, RTE_VAR_INIT) Rte_BIfRx_BIfRx_uAgSinP_BIfRx_uAgSinP;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE3_QM_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgCosN_AngEmDev_uPhyAgCosN(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgCosP_AngEmDev_uPhyAgCosP(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgExctN_AngEmDev_uPhyAgExctN(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgExctP_AngEmDev_uPhyAgExctP(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgSinN_AngEmDev_uPhyAgSinN(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_AngEmDev_AngEmDev_uPhyAgSinP_AngEmDev_uPhyAgSinP(Float data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgCosN_BIfRx_uAgCosN(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgCosP_BIfRx_uAgCosP(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgExctN_BIfRx_uAgExctN(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgExctP_BIfRx_uAgExctP(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgSinN_BIfRx_uAgSinN(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AngEmDev_BIfRx_uAgSinP_BIfRx_uAgSinP(P2VAR(Float, AUTOMATIC, RTE_AngEmDev_APPL_DATA) data);
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
#define Rte_Read_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp Rte_Read_AngEmDev_BIfRx_uAgCosEnvlp_BIfRx_uAgCosEnvlp
#define Rte_Read_BIfRx_uAgCosN_BIfRx_uAgCosN Rte_Read_AngEmDev_BIfRx_uAgCosN_BIfRx_uAgCosN
#define Rte_Read_BIfRx_uAgCosP_BIfRx_uAgCosP Rte_Read_AngEmDev_BIfRx_uAgCosP_BIfRx_uAgCosP
#define Rte_Read_BIfRx_uAgExctN_BIfRx_uAgExctN Rte_Read_AngEmDev_BIfRx_uAgExctN_BIfRx_uAgExctN
#define Rte_Read_BIfRx_uAgExctP_BIfRx_uAgExctP Rte_Read_AngEmDev_BIfRx_uAgExctP_BIfRx_uAgExctP
#define Rte_Read_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp Rte_Read_AngEmDev_BIfRx_uAgSinEnvlp_BIfRx_uAgSinEnvlp
#define Rte_Read_BIfRx_uAgSinN_BIfRx_uAgSinN Rte_Read_AngEmDev_BIfRx_uAgSinN_BIfRx_uAgSinN
#define Rte_Read_BIfRx_uAgSinP_BIfRx_uAgSinP Rte_Read_AngEmDev_BIfRx_uAgSinP_BIfRx_uAgSinP
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
#define Rte_Write_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp Rte_Write_AngEmDev_AngEmDev_uPhyAgCosEnvlp_AngEmDev_uPhyAgCosEnvlp
#define Rte_Write_AngEmDev_uPhyAgCosN_AngEmDev_uPhyAgCosN Rte_Write_AngEmDev_AngEmDev_uPhyAgCosN_AngEmDev_uPhyAgCosN
#define Rte_Write_AngEmDev_uPhyAgCosP_AngEmDev_uPhyAgCosP Rte_Write_AngEmDev_AngEmDev_uPhyAgCosP_AngEmDev_uPhyAgCosP
#define Rte_Write_AngEmDev_uPhyAgExctN_AngEmDev_uPhyAgExctN Rte_Write_AngEmDev_AngEmDev_uPhyAgExctN_AngEmDev_uPhyAgExctN
#define Rte_Write_AngEmDev_uPhyAgExctP_AngEmDev_uPhyAgExctP Rte_Write_AngEmDev_AngEmDev_uPhyAgExctP_AngEmDev_uPhyAgExctP
#define Rte_Write_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp Rte_Write_AngEmDev_AngEmDev_uPhyAgSinEnvlp_AngEmDev_uPhyAgSinEnvlp
#define Rte_Write_AngEmDev_uPhyAgSinN_AngEmDev_uPhyAgSinN Rte_Write_AngEmDev_AngEmDev_uPhyAgSinN_AngEmDev_uPhyAgSinN
#define Rte_Write_AngEmDev_uPhyAgSinP_AngEmDev_uPhyAgSinP Rte_Write_AngEmDev_AngEmDev_uPhyAgSinP_AngEmDev_uPhyAgSinP
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
FUNC(void, AngEmDev_CODE) AngEmDev_Init(void);
FUNC(void, AngEmDev_CODE) fc_AngEmDev(void);
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
#endif /* RTE_ANGEMDEV_H_ */
 
 
 
