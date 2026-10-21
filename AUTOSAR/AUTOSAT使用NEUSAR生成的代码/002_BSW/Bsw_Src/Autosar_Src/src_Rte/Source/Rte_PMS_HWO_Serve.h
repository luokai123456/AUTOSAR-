 
/*
************************************************************************************************************************
*
* File name: Rte_PMS_HWO_Serve.h
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
#ifndef RTE_PMS_HWO_SERVE_H_
#define RTE_PMS_HWO_SERVE_H_

#include "Rte_PMS_HWO_Serve_Type.h"
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
/*
************************************************************************************************************************
*    Operation Invocation Runnable entities
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_KEY_HS_03_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_KEY_HS_05_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_HS_11_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_HS_6_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_HS_8_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_HS_9_PMSHWO_SetDOHS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_10_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_12_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_5_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_7_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_DO_RELAY_LS_9_PMSHWO_SetDOLS(VAR(uint8, RTE_PMS_HWO_Serve_APPL_DATA) Ctr);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_HVIL_1_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_HVIL_2_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_PWM_1_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_PWM_2_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
FUNC(void, PMS_HWO_Serve_CODE) PMSHWO_PO_PWM_4_PMSHWO_SetPWM(VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) Frequency, VAR(uint32, RTE_PMS_HWO_Serve_APPL_DATA) DutyCycle);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
/*
************************************************************************************************************************
*    Exclusive Areas.
************************************************************************************************************************
*/

#ifdef __cplusplus
}                  
#endif            
#endif /* RTE_PMS_HWO_SERVE_H_ */
 
 
 
