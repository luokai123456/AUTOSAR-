/*
************************************************************************************************************************
*
* File name: Rte_App1_Application_Core4_QM.c
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
#define RTE_CORE


/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Os.h"
#include "Rte_Type.h"
#include "Rte_Main.h"
#include "Rte_IoHwAbSelf.h"
#include "Rte_BSW_NM.h"
#include "Rte_PMS_RollingCounter.h"
#include "ASW_Task_Instead.h"
#include "EcuM.h"
#include "Rte_Cbk.h"
#include "Rte_Hook.h"
#include "Com.h"

/*
************************************************************************************************************************
    Timer handling
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Local Types
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    API for enable / disable interrupts up to the systemLevel . 
************************************************************************************************************************
*/
#define Rte_DisableOSInterrupts() SuspendOSInterrupts()
#define Rte_EnableOSInterrupts() ResumeOSInterrupts()

/*
************************************************************************************************************************
*    Definition of Buffers for unqueued S/R 
************************************************************************************************************************
*/
#define RTE_START_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter = 0U;
#define RTE_STOP_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"


/*
************************************************************************************************************************
*    Buffers for implicit communication
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    TxAck/ModeSwitchAck Flags
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Update Flags for each Receiver variables
************************************************************************************************************************
*/

#define RTE_START_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
VAR(Rte_App1_Application_Core4_QM_TxUpdateFlagsType, RTE_VAR_INIT_NOCACHE) Rte_App1_Application_Core4_QM_TxUpdateFlags = {
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
    0U,
};

#define RTE_STOP_SEC_APP1_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Timeout Flags for each Receiver variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Invalid Flags for each Receiver variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Never Received Flags for each external Rx Signal with handleNeverReceived != 0
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Per-Instance Memory variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Buffers for inter-runnable variables
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Data structures for mode management
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    Definition of Rte functions
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE) Rte_MemClr(P2VAR(void, AUTOMATIC, RTE_VAR_NOINIT) ptr, uint16_least num); 
FUNC(void, RTE_CODE) Rte_MemCpy(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) Rte_MemCpy32(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) source, uint32_least num);
FUNC(void, RTE_CODE) RteBuff_PushRelease(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC(void, RTE_CODE) RteBuff_PopRelease(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PopLock(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteBuff_PushLock(P2VAR(RteQueueBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Push(P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) RteStack_Pop(P2VAR(RteStackBufferType, AUTOMATIC, RTE_APPL_DATA) cPtr);
FUNC_P2VAR(void, RTE_APPL_DATA, RTE_CODE) Rte_MemSet(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) destination, uint8 c, uint32 num);
FUNC(void, RTE_CODE) Rte_MoveFront(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength);
FUNC(void, RTE_CODE) Rte_MoveBehind(P2VAR(void, AUTOMATIC, RTE_APPL_DATA) cPtr, uint32 bufferLength, uint32 moveLength);
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Client Server API (Rte_Call)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE_CALL Func
************************************************************************************************************************
*/


/*
************************************************************************************************************************
*    COM-Callbacks for COM Invalid Notification
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM-Callbacks for DataSendCompletedEvent triggered runnables for transmission acknowledgement and error handling
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    COM Callbacks Function definition for Rx Update Notification
************************************************************************************************************************
*/



/*
************************************************************************************************************************
*    LdCom Callbacks Function definition for TX Trigger Transmit
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Internal/External Tx connections
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_Battery_Performance_AliveCounter_BMSH_Battery_Performance_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_CCM_Req_AliveCounter_BMSH_CCM_Req_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_SOP_AliveCounter_BMSH_SOP_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_Status_AliveCounter_BMSH_Status_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_VoltCurr_AliveCounter_BMSH_VoltCurr_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMSH_VoltCurrent_AliveCounter_BMSH_VoltCurrent_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMS_ChgInfo_AliveCounter_BMS_ChgInfo_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_BMS_RelaySampSwich_AliveCounter_BMS_RelaySampSwich_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_IPU_Sts_AliveCounter_IPU_Sts_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_IPU_TrqSpd_AliveCounter_IPU_TrqSpd_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_CSControl1_AliveCounter_PMS_CSControl1_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_CSControl2_AliveCounter_PMS_CSControl2_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_Command_AliveCounter_PMS_Command_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_Ctrl_AliveCounter_PMS_Ctrl_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_EPS_SystemSts_AliveCounter_PMS_EPS_SystemSts_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_EngControl_AliveCounter_PMS_EngControl_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_ModeControl_AliveCounter_PMS_ModeControl_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_RelaySampSwich_AliveCounter_PMS_RelaySampSwich_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_PMS_StsSwap_AliveCounter_PMS_StsSwap_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_VCU_BMSH_Ctrl_AliveCounter_VCU_BMSH_Ctrl_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter(UInt8 data)
{
    Std_ReturnType ret = RTE_E_OK;

    Rte_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter = *(&data);
    Rte_App1_Application_Core4_QM_TxUpdateFlags.Rte_TxUpdate_PMS_RollingCounter_VCU_VehicleInfo_AliveCounter_VCU_VehicleInfo_AliveCounter = RTE_COM_SENDSIGNALPROXY_SEND;

    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Definition of Internal/External Rx connections
************************************************************************************************************************
*/
  
/*
************************************************************************************************************************
*    Inter-runnable variable access
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Definition of Rte_Invalidate_<p>_<d> (explicit S/R communication with isQueued = false)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Transmission/Mode Switch Acknowledgement handling (Rte_Feedback/Rte_SwitchAck)
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Runnable Entities for Nv Block Components
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Task bodies for RTE controlled tasks
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(SWC_Init_Task_Core4)
{
    Core4_Runnable_Task_Init();

    BSW_NM_Init();

    PMS_RollingCounter_Init();

    (void)TerminateTask();
}

TASK(App1_Task_1ms_Core4_QM)
{
    Core4_Runnable_App_1ms();

    (void)TerminateTask();
}

TASK(App1_Task_5ms_Core4_QM)
{
    Core4_Runnable_App_5ms();

    (void)TerminateTask();
}

TASK(App1_Task_10ms_Core4_QM)
{
    PMS_RollingCounter_Runnable();

    Core4_Runnable_App_10ms();

    (void)TerminateTask();
}

TASK(App1_Task_20ms_Core4_QM)
{
    Core4_Runnable_App_20ms();

    (void)TerminateTask();
}

TASK(App1_Task_50ms_Core4_QM)
{
    Core4_Runnable_App_50ms();

    (void)TerminateTask();
}

TASK(App1_Task_100ms_Core4_QM)
{
    Core4_Runnable_App_100ms();

    (void)TerminateTask();
}

#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
TASK(App1_Task_UDS_Core4_QM)
{
    EventMaskType ev = 0U;
    for(;;)
    {
        (void)WaitEvent(APP1_EVENT_UDS_CORE4_QM);
        (void)GetEvent(APP1_TASK_UDS_CORE4_QM, &ev);
        (void)ClearEvent(ev & (APP1_EVENT_UDS_CORE4_QM));

    }
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"

/*
************************************************************************************************************************
*    Mode Switch API (Rte_Switch)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Mode Mode API (Rte_Mode)
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    IsUpdate Func
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    RTE_ISUPDATE Func
************************************************************************************************************************
*/

