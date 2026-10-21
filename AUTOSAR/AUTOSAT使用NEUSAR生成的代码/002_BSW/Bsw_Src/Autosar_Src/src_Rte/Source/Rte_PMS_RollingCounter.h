 
/*
************************************************************************************************************************
*
* File name: Rte_PMS_RollingCounter.h
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
#ifndef RTE_PMS_ROLLINGCOUNTER_H_
#define RTE_PMS_ROLLINGCOUNTER_H_

#include "Rte_PMS_RollingCounter_Type.h"
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
#define RTE_START_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter;
extern VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
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
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter(UInt8 data);
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter(UInt8 data);
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
#define Rte_Write_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter Rte_Write_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter
#define Rte_Write_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter Rte_Write_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter
#define Rte_Write_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter Rte_Write_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter
#define Rte_Write_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter Rte_Write_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter
#define Rte_Write_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter Rte_Write_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter
#define Rte_Write_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter Rte_Write_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter
#define Rte_Write_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter Rte_Write_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter
#define Rte_Write_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter Rte_Write_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter
#define Rte_Write_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter Rte_Write_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter
#define Rte_Write_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter Rte_Write_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter
#define Rte_Write_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter Rte_Write_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter
#define Rte_Write_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter Rte_Write_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter
#define Rte_Write_PMS_Command_AliveCounter_PMS_Command_AliveCounter Rte_Write_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter
#define Rte_Write_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter Rte_Write_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter
#define Rte_Write_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter Rte_Write_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter
#define Rte_Write_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter Rte_Write_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter
#define Rte_Write_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter Rte_Write_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter
#define Rte_Write_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter Rte_Write_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter
#define Rte_Write_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter Rte_Write_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter
#define Rte_Write_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter Rte_Write_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter
#define Rte_Write_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter Rte_Write_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter
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
FUNC(void, PMS_RollingCounter_CODE) PMS_RollingCounter_Init(void);
FUNC(void, PMS_RollingCounter_CODE) PMS_RollingCounter_Runnable(void);
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
#endif /* RTE_PMS_ROLLINGCOUNTER_H_ */
 
 
 
