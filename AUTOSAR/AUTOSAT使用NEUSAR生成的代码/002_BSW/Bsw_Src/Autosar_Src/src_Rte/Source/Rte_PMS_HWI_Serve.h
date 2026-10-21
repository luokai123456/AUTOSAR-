 
/*
************************************************************************************************************************
*
* File name: Rte_PMS_HWI_Serve.h
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
#ifndef RTE_PMS_HWI_SERVE_H_
#define RTE_PMS_HWI_SERVE_H_

#include "Rte_PMS_HWI_Serve_Type.h"
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
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_BATTERY_TEMPH_5_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_BATTERY_TEMPH_6_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_EXT_IGN_ON_AI_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_MID_COOLING_TEMPH_8_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_SENSOR_1_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_SENSOR_2_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_SENSOR_6_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AI_SWITCH_1_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AO_LDO_5V_02_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AO_TRACKING_5V_01_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_AO_TRACKING_5V_02_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_CHARGE_ON_AI_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_04_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_05_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_06_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_07_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_08_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_DI_HS_10_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_IGN_ON_DI_PMSHWI_GetDI(P2VAR(boolean, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) RawResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_KL30_PMSHWI_GetAI(P2VAR(uint16, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) FileterResult);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_PI_HVIL_1_PMSHWI_GetPWM(P2VAR(uint8, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numDuty, P2VAR(uint32, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numFreq);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_PI_HVIL_2_PMSHWI_GetPWM(P2VAR(uint8, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numDuty, P2VAR(uint32, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numFreq);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_PI_PWM_1_PMSHWI_GetPWM(P2VAR(uint8, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numDuty, P2VAR(uint32, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numFreq);
FUNC(void, PMS_HWI_Serve_CODE) PMSHWI_PI_PWM_2_PMSHWI_GetPWM(P2VAR(uint8, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numDuty, P2VAR(uint32, AUTOMATIC, RTE_PMS_HWI_Serve_APPL_DATA) numFreq);
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
#endif /* RTE_PMS_HWI_SERVE_H_ */
 
 
 
