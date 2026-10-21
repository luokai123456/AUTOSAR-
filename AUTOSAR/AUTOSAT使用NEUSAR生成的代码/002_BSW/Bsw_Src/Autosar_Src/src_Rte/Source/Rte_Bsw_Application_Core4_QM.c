/*
************************************************************************************************************************
*
* File name: Rte_Bsw_Application_Core4_QM.c
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
#include "ASW_Task_Instead.h"
#include "EcuM.h"
#include "Rte_Cbk.h"
#include "Rte_Hook.h"
#include "SchM_BswM.h"
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_CanTp.h"
#include "Com.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Dcm.h"
#include "SchM_Dem.h"
#include "SchM_J1939Tp.h"
#include "SchM_LinIf.h"
#include "SchM_LinSM.h"

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

#define RTE_START_SEC_BSW_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"
#if 0//UDS 不需要内容
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_DTC_0x0402_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_DTC_0x0402_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData,
    Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type),
    Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData,
    Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData,
    Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1002_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x1002_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1003_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x1003_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x11_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x11_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x14_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x14_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x22_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x22_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x27_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x27_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x28_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x28_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x2E_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x2E_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x31_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x31_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x85_Operation = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_ServiceCheckRule_0x85_Operation = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type),
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation,
    Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type),
    Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData,
    Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4000_Start = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4000_Start = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x400F_Start = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x400F_Start = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
VAR(Rte_CS_Server_Property_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData = {FALSE, FALSE};
VAR(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type, RTE_VAR_INIT_NOCACHE) Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData[RTE_CALL_STACK_LENGTH_SYNC] = {0U};
VAR(RteStackBufferType, RTE_VAR_INIT_NOCACHE) RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData = 
{
    RTE_CALL_STACK_LENGTH_SYNC,
    0U,
    sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type),
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData,
    Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData + RTE_CALL_STACK_LENGTH_SYNC
};
#endif
#define RTE_STOP_SEC_BSW_APPLICATION_CORE4_QM_GLOBAL_VAR_INIT
#include "Rte_MemMap.h"

#if 0//UDS 不需要内容
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_DTC_0x0402_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_DTC_0x0402_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_DTC_0x0402_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_DTC_0X0402_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_DTC_0x0402_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_DTC_0X0402_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_DTC_0x0402_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_DTC_0X0402_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_DTC_0x0402_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_DTC_0X0402_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_DTC_0x0402_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_DTC_0X0402_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DTC_0x0402_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_DTC_0x0402_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_DISCHGSTATE_0X04CF_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_DISCHGSTATE_0X04CF_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_DISCHGSTATE_0X04CF_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_DISCHGSTATE_0X04CF_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_DISCHGSTATE_0X04CF_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_DischgState_0X04CF_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSCUR_0X0409_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSCUR_0X0409_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_HVBUSCUR_0X0409_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSCUR_0X0409_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSCUR_0X0409_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_HVBusCur_0x0409_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSVOLT_500_0X0408_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSVOLT_500_0X0408_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_HVBUSVOLT_500_0X0408_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSVOLT_500_0X0408_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_HVBUSVOLT_500_0X0408_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_HVBusVolt_500_0x0408_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGMOTT_0X040B_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGMOTT_0X040B_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGMOTT_0X040B_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGMOTT_0X040B_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGMOTT_0X040B_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_IsgMotT_0x040B_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGSPDACTSGN_0X0403_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGSPDACTSGN_0X0403_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGSPDACTSGN_0X0403_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGSPDACTSGN_0X0403_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGSPDACTSGN_0X0403_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_IsgSpdActSgn_0x0403_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_ISGTQACTISGTQACT_0X0404_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_IsgTqActIsgTqAct_0x0404_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_MOTORTEMP_0X040D_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_MOTORTEMP_0X040D_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_MOTORTEMP_0X040D_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_MOTORTEMP_0X040D_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_MOTORTEMP_0X040D_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_MotorTemp_0x040D_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMAX_0X0406_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMAX_0X0406_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_TQAVLISGMAX_0X0406_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMAX_0X0406_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMAX_0X0406_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMax_0x0406_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMIN_0X0407_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMIN_0X0407_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_IPU_TQAVLISGMIN_0X0407_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMIN_0X0407_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_IPU_TQAVLISGMIN_0X0407_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_IPU_TqAvlIsgMin_0x0407_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData( VAR(UInt8_T, RTE_MCU_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_MCU_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA);

            while(Rte_CS_Server_Property_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_DID_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_DID_PMS_DRIVERDEMANDTORQUE_0X0405_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_DID_PMS_DriverDemandTorque_0x0405_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData( VAR(UInt8_T, RTE_MCU_UDS_Interface_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_UDS_Interface_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_MCU_UDS_Interface_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_UDS_INTERFACE_DATASERVICES_DSPDATA_0X0400_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_UDS_INTERFACE_DATASERVICES_DSPDATA_0X0400_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE3_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE3_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0400_22_RE);

            while(Rte_CS_Server_Property_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_MCU_UDS_INTERFACE_DATASERVICES_DSPDATA_0X0400_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_MCU_UDS_INTERFACE_DATASERVICES_DSPDATA_0X0400_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_MCU_UDS_Interface_DataServices_DspData_0x0400_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_AC_ACCM_ACTPOWER_0X0328_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_AC_ACCM_ACTPOWER_0X0328_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_AC_ACCM_ACTPOWER_0X0328_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_AC_ACCM_ACTPOWER_0X0328_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_AC_ACCM_ACTPOWER_0X0328_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_AC_ACCM_ActPower_0x0328_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_BMSH_CCM_THERMALMANAGEREQ_0X0329_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_BMSH_CCM_ThermalManageReq_0x0329_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_BMSH_SELFCHECKFAULT_0X032B_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_BMSH_SelfCheckFault_0x032B_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_CSM_V2XDCHASWTINVALID_0X0324_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_CSM_V2XDchaSwtInvalid_0x0324_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_DCDC_SELFCHKSTS_0X032C_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_DCDC_SELFCHKSTS_0X032C_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_DCDC_SELFCHKSTS_0X032C_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_DCDC_SELFCHKSTS_0X032C_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_DCDC_SELFCHKSTS_0X032C_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_DCDC_SelfChkSts_0x032C_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_EHB_EPBSTATUS_0X0312_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_EHB_EPBSTATUS_0X0312_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_EHB_EPBSTATUS_0X0312_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_EHB_EPBSTATUS_0X0312_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_EHB_EPBSTATUS_0X0312_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_EHB_EPBStatus_0x0312_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_IPU_SELFCHKSTS_0X032A_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_IPU_SELFCHKSTS_0X032A_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_IPU_SELFCHKSTS_0X032A_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_IPU_SELFCHKSTS_0X032A_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_IPU_SELFCHKSTS_0X032A_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_IPU_SelfChkSts_0x032A_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PEPS_POWERMODE_0X0319_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PEPS_POWERMODE_0X0319_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PEPS_POWERMODE_0X0319_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PEPS_POWERMODE_0X0319_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PEPS_POWERMODE_0X0319_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PEPS_PowerMode_0x0319_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ACCMENABLE_0X031D_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ACCMENABLE_0X031D_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ACCMENABLE_0X031D_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ACCMENABLE_0X031D_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ACCMENABLE_0X031D_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_ACCMEnable_0x031D_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BATTERYVOL_0X0331_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BATTERYVOL_0X0331_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BATTERYVOL_0X0331_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BATTERYVOL_0X0331_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BATTERYVOL_0X0331_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_BatteryVol_0x0331_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE1SWITCH_0X0311_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE1SWITCH_0X0311_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BRAKE1SWITCH_0X0311_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE1SWITCH_0X0311_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE1SWITCH_0X0311_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_Brake1Switch_0x0311_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE2SWITCH_0X0333_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE2SWITCH_0X0333_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_BRAKE2SWITCH_0X0333_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE2SWITCH_0X0333_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_BRAKE2SWITCH_0X0333_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_Brake2Switch_0x0333_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_CPSREN_0X0313_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_CPSREN_0X0313_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_CPSREN_0X0313_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_CPSREN_0X0313_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_CPSREN_0X0313_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_CPSREn_0x0313_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_COOLINGFANPWMSPD_0X031C_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_CoolingFanPWMSpd_0x031C_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCCUTOFFLV_0X032E_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_DCDCCutOffLV_0x032E_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCACTVDREQ_0X032D_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCACTVDREQ_0X032D_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DCDCACTVDREQ_0X032D_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCACTVDREQ_0X032D_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DCDCACTVDREQ_0X032D_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_DcDcActvdReq_0x032D_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DRIVEMODEIND_0X0317_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DRIVEMODEIND_0X0317_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_DRIVEMODEIND_0X0317_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DRIVEMODEIND_0X0317_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_DRIVEMODEIND_0X0317_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_DriveModeInd_0x0317_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_EDCPPWMCTRL_0X031A_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_EDCPPWMCTRL_0X031A_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_EDCPPWMCTRL_0X031A_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_EDCPPWMCTRL_0X031A_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_EDCPPWMCTRL_0X031A_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_EDCPPWMCtrl_0x031A_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ENGRECMODE_FB_0X0325_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ENGRECMODE_FB_0X0325_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ENGRECMODE_FB_0X0325_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ENGRECMODE_FB_0X0325_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ENGRECMODE_FB_0X0325_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_EngRecMode_Fb_0x0325_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_FUNLOCKVEHACTIVE_0X0318_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_FunLockVehActive_0x0318_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HBCPPWMCTRL_0X031B_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HBCPPWMCTRL_0X031B_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HBCPPWMCTRL_0X031B_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HBCPPWMCTRL_0X031B_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HBCPPWMCTRL_0X031B_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_HBCPPWMCtrl_0x031B_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL1STS_0X0322_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL1STS_0X0322_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HVIL1STS_0X0322_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL1STS_0X0322_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL1STS_0X0322_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_HVIL1Sts_0x0322_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL2STS_0X0323_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL2STS_0X0323_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_HVIL2STS_0X0323_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL2STS_0X0323_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_HVIL2STS_0X0323_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_HVIL2Sts_0x0323_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_3));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_IPKTOTALODOMETER_0X0334_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_3));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_IPKTotalOdometer_0x0334_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_IGNONSTS_0X0332_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_IGNONSTS_0X0332_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_IGNONSTS_0X0332_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_IGNONSTS_0X0332_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_IGNONSTS_0X0332_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_IgnONSts_0x0332_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ISGMODREQ_0X032F_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ISGMODREQ_0X032F_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ISGMODREQ_0X032F_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ISGMODREQ_0X032F_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ISGMODREQ_0X032F_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_IsgModReq_0x032F_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ISGTQREQ_0X0314_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ISGTQREQ_0X0314_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_ISGTQREQ_0X0314_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ISGTQREQ_0X0314_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_ISGTQREQ_0X0314_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_IsgTqReq_0x0314_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_MODEGEARDISPLAYSTS_0X0316_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_ModeGearDisplaySts_0x0316_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTC2ENABLE_0X031F_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTC2ENABLE_0X031F_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTC2ENABLE_0X031F_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTC2ENABLE_0X031F_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTC2ENABLE_0X031F_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_PTC2Enable_0x031F_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTC3ENABLE_0X0320_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTC3ENABLE_0X0320_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTC3ENABLE_0X0320_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTC3ENABLE_0X0320_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTC3ENABLE_0X0320_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_PTC3Enable_0x0320_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTCENABLE_0X031E_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTCENABLE_0X031E_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTCENABLE_0X031E_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTCENABLE_0X031E_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTCENABLE_0X031E_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_PTCEnable_0x031E_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_PTRESIDUEPWRIND_0X0315_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_PTResiduePwrInd_0x0315_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_REAL_PEDALPOSITION_0X0310_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_Real_PedalPosition_0x0310_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_SELFCHECKSTS_0X0321_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_SELFCHECKSTS_0X0321_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_SELFCHECKSTS_0X0321_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_SELFCHECKSTS_0X0321_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_SELFCHECKSTS_0X0321_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_SelfCheckSts_0x0321_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_VEHICLESPEED_0X0327_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_VEHICLESPEED_0X0327_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_PMS_VEHICLESPEED_0X0327_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_VEHICLESPEED_0X0327_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_PMS_VEHICLESPEED_0X0327_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_PMS_VehicleSpeed_0x0327_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x1002_Operation( P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1002_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1002_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1002_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x1002_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1002_OPERATION);
        if(NULL_PTR != pPush)
        {
            cs_Server.Cond = *Cond;
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1002_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X1002_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1002_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1002_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x1002_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1002_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1002_Operation_Type));
                *Cond = cs_Server.Cond;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1002_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x1003_Operation( P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Cond)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1003_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1003_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1003_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x1003_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1003_OPERATION);
        if(NULL_PTR != pPush)
        {
            cs_Server.Cond = *Cond;
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1003_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X1003_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1003_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1003_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x1003_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X1003_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x1003_Operation_Type));
                *Cond = cs_Server.Cond;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x1003_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x11_Operation(void)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x11_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x11_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X11_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x11_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X11_OPERATION);
        if(NULL_PTR != pPush)
        {
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x11_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X11_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x11_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X11_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x11_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X11_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x11_Operation_Type));
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x11_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x14_Operation(void)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x14_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x14_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X14_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x14_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X14_OPERATION);
        if(NULL_PTR != pPush)
        {
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x14_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X14_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x14_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X14_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x14_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X14_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x14_Operation_Type));
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x14_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x22_Operation(void)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x22_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x22_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X22_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x22_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X22_OPERATION);
        if(NULL_PTR != pPush)
        {
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x22_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X22_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x22_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X22_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x22_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X22_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x22_Operation_Type));
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x22_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x27_Operation(void)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x27_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x27_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X27_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x27_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X27_OPERATION);
        if(NULL_PTR != pPush)
        {
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x27_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X27_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x27_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X27_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x27_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X27_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x27_Operation_Type));
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x27_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x28_Operation(void)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x28_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x28_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X28_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x28_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X28_OPERATION);
        if(NULL_PTR != pPush)
        {
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x28_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X28_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x28_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X28_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x28_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X28_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x28_Operation_Type));
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x28_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x2E_Operation(void)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x2E_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x2E_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X2E_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x2E_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X2E_OPERATION);
        if(NULL_PTR != pPush)
        {
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x2E_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X2E_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x2E_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X2E_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x2E_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X2E_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x2E_Operation_Type));
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x2E_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x31_Operation(void)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x31_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x31_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X31_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x31_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X31_OPERATION);
        if(NULL_PTR != pPush)
        {
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x31_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X31_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x31_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X31_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x31_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X31_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x31_Operation_Type));
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x31_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_ServiceCheckRule_0x85_Operation(void)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x85_Operation.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x85_Operation.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X85_OPERATION);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x85_Operation);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X85_OPERATION);
        if(NULL_PTR != pPush)
        {
            Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x85_Operation.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_SERVICECHECKRULE_0X85_OPERATION);

            while(Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x85_Operation.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X85_OPERATION);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_ServiceCheckRule_0x85_Operation);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_SERVICECHECKRULE_0X85_OPERATION);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_ServiceCheckRule_0x85_Operation_Type));
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_ServiceCheckRule_0x85_Operation.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_VCU_BMSH_STSMODEREQ_0X0330_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_VCU_BMSH_StsModeReq_0x0330_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData( VAR(UInt8_T, RTE_PMS_DID_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_PMS_DID_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_PMS_DID_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_VCU_ODOMETERBACKUP_0X0326_CS_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_VCU_ODOMETERBACKUP_0X0326_CS_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type));

            (void)SetEvent(APP1_TASK_UDS_CORE1_QM, RTE_EV_CYCLIC_APP1_TASK_UDS_CORE1_QM_VCU_ODOMETERBACKUP_0X0326_CS_READDATA);

            while(Rte_CS_Server_Property_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_PMS_DID_VCU_ODOMETERBACKUP_0X0326_CS_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_PMS_DID_VCU_ODOMETERBACKUP_0X0326_CS_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_PMS_DID_VCU_Odometerbackup_0x0326_CS_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start( P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_START);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_START);
        if(NULL_PTR != pPush)
        {
            Rte_MemCpy32((uint8*)(cs_Server.DataIn), (uint8*)DataIn, sizeof(rt_Array_UInt8_T_2));
            cs_Server.OpStatus = OpStatus;
            cs_Server.DataOut = *DataOut;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X03E2_START_SERVICES);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_START);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_START);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start_Type));
                *DataOut = cs_Server.DataOut;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Start.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop( P2CONST(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_STOP);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_STOP);
        if(NULL_PTR != pPush)
        {
            Rte_MemCpy32((uint8*)(cs_Server.DataIn), (uint8*)DataIn, sizeof(rt_Array_UInt8_T_2));
            cs_Server.OpStatus = OpStatus;
            cs_Server.DataOut = *DataOut;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X03E2_STOP_SERVICES);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_STOP);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X03E2_STOP);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop_Type));
                *DataOut = cs_Server.DataOut;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x03E2_Stop.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4000_Start( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4000_Start.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4000_Start.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4000_START);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4000_Start);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4000_START);
        if(NULL_PTR != pPush)
        {
            cs_Server.DataIn = DataIn;
            cs_Server.OpStatus = OpStatus;
            cs_Server.DataOut = *DataOut;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4000_Start.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4000_START_SERVICES);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4000_Start.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4000_START);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4000_Start);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4000_START);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4000_Start_Type));
                *DataOut = cs_Server.DataOut;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4000_Start.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x400F_Start( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x400F_Start.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x400F_Start.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X400F_START);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x400F_Start);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X400F_START);
        if(NULL_PTR != pPush)
        {
            cs_Server.DataIn = DataIn;
            cs_Server.OpStatus = OpStatus;
            cs_Server.DataOut = *DataOut;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x400F_Start.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X400F_START_SERVICES);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x400F_Start.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X400F_START);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x400F_Start);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X400F_START);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x400F_Start_Type));
                *DataOut = cs_Server.DataOut;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x400F_Start.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F02_START);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F02_START);
        if(NULL_PTR != pPush)
        {
            cs_Server.DataIn = DataIn;
            cs_Server.OpStatus = OpStatus;
            cs_Server.DataOut = *DataOut;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F02_START_SERVICES);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F02_START);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F02_START);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start_Type));
                *DataOut = cs_Server.DataOut;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F02_Start.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F03_START);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F03_START);
        if(NULL_PTR != pPush)
        {
            cs_Server.DataIn = DataIn;
            cs_Server.OpStatus = OpStatus;
            cs_Server.DataOut = *DataOut;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F03_START_SERVICES);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F03_START);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F03_START);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start_Type));
                *DataOut = cs_Server.DataOut;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F03_Start.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) DataIn, VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) DataOut, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F04_START);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F04_START);
        if(NULL_PTR != pPush)
        {
            cs_Server.DataIn = DataIn;
            cs_Server.OpStatus = OpStatus;
            cs_Server.DataOut = *DataOut;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_ROUTINESERVICES_0X4F04_START_SERVICES);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F04_START);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_ROUTINESERVICES_0X4F04_START);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start_Type));
                *DataOut = cs_Server.DataOut;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_RoutineServices_0x4F04_Start.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0501_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0501_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0501_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0501_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0501_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0501_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0502_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0502_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0502_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0502_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0502_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0502_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0503_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0503_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0503_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0503_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0503_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0503_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0504_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0504_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0504_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0504_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0504_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0504_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(Std_ReturnType, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0505_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0505_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0505_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0505_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0505_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0505_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0507_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0507_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_255));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0507_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0507_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0507_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_255));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0507_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X050A_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X050A_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_54));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X050A_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X050A_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X050A_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_54));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x050A_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0525_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0525_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0525_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0525_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0525_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0525_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0526_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0526_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0526_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0526_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0526_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0526_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0527_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0527_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0527_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0527_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0527_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0527_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0528_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0528_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0528_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0528_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0528_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0528_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0529_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0529_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0529_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0529_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0529_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0529_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052B_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052B_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052B_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052B_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052B_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052B_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052D_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052D_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052D_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052D_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052D_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052D_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052E_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052E_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X052E_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052E_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X052E_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x052E_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0530_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0530_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0530_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0530_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0530_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0530_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0531_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0531_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0531_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0531_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0531_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0531_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0532_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0532_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0532_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0532_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0532_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0532_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0533_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0533_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0533_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0533_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0533_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0533_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0534_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0534_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0534_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0534_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0534_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0534_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0535_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0535_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0535_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0535_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0535_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0535_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0536_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0536_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0536_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0536_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0536_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0536_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0537_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0537_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0537_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0537_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0537_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0537_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0538_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0538_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0538_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0538_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0538_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0538_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0539_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0539_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0539_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0539_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0539_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0539_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053B_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053B_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053B_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053B_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053B_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053B_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053C_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053C_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053C_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053C_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053C_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053C_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053D_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053D_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_4));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053D_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053D_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053D_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_4));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053D_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053E_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053E_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_4));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X053E_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053E_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X053E_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_4));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x053E_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0542_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0542_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0542_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0542_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0542_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0542_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0543_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0543_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0543_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0543_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0543_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0543_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0544_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0544_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0544_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0544_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0544_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0544_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0545_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0545_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0545_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0545_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0545_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0545_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0547_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0547_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0547_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0547_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0547_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0547_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0552_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0552_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0552_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0552_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0552_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0552_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055A_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055A_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055A_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055A_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055A_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055A_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055C_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055C_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055C_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055C_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055C_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055C_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055D_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055D_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X055D_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055D_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X055D_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x055D_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0585_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0585_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0585_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0585_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0585_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0585_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0586_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0586_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0586_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0586_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0586_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0586_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0587_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0587_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0587_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0587_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0587_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0587_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0588_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0588_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0588_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0588_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0588_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0588_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0589_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0589_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type));

            (void)SetEvent(APP1_TASK0_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK0_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0589_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0589_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0589_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0589_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058A_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058A_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058A_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058A_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058A_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058A_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058B_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058B_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058B_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058B_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058B_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058B_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058C_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058C_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_4));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058C_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058C_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058C_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_4));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058C_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058D_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058D_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_4));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058D_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058D_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058D_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_4));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058D_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058E_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058E_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_4));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058E_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058E_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058E_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_4));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058E_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058F_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058F_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_4));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X058F_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058F_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X058F_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_4));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x058F_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0590_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0590_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_4));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0590_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0590_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0590_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_4));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0590_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0591_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0591_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_4));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0591_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0591_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0591_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_4));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0591_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0592_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0592_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0592_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0592_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0592_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0592_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0593_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0593_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_48));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0593_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0593_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0593_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_48));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0593_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0594_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0594_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0594_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0594_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0594_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0594_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0595_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0595_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0595_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0595_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0595_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0595_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0596_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0596_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0596_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0596_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0596_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0596_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0597_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0597_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0597_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0597_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0597_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0597_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0598_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0598_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0598_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0598_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0598_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0598_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0599_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0599_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X0599_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0599_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X0599_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x0599_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059A_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059A_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059A_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059A_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059A_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059A_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059B_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059B_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059B_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059B_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059B_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059B_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059C_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059C_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059C_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059C_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059C_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059C_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059D_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059D_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_8));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059D_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059D_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059D_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_8));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059D_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059E_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059E_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059E_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059E_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059E_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059E_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059F_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059F_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X059F_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059F_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X059F_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x059F_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A1_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A1_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A1_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A1_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A1_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A1_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A2_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A2_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A2_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A2_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A2_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A2_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A3_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A3_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A3_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A3_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A3_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A3_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A4_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A4_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A4_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A4_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A4_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A4_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A5_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A5_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A5_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A5_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A5_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A5_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A6_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A6_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A6_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A6_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A6_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A6_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A7_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A7_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A7_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A7_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A7_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A7_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A8_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A8_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A8_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A8_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A8_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A8_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A9_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A9_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05A9_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A9_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05A9_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05A9_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AA_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AA_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AA_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AA_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AA_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AA_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AB_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AB_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AB_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AB_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AB_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AB_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AC_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AC_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AC_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AC_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AC_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AC_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AD_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AD_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AD_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AD_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AD_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AD_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AE_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AE_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AE_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AE_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AE_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AE_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AF_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AF_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05AF_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AF_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05AF_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05AF_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B0_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B0_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_48));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B0_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B0_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B0_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_48));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B0_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B1_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B1_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_48));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B1_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B1_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B1_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_48));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B1_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B2_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B2_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_288));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B2_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B2_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B2_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_288));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B2_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B3_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B3_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B3_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B3_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B3_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B3_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B4_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B4_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B4_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B4_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B4_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B4_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B5_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B5_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B5_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B5_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B5_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B5_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B6_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B6_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B6_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B6_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B6_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B6_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B7_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B7_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B7_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B7_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B7_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B7_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B8_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B8_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B8_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B8_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B8_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B8_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B9_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B9_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05B9_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B9_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05B9_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05B9_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BA_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BA_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BA_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BA_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BA_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BA_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BB_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BB_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BB_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BB_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BB_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BB_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BC_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BC_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BC_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BC_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BC_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BC_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BD_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BD_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BD_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BD_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BD_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BD_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BE_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BE_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BE_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BE_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BE_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BE_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BF_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BF_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05BF_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BF_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05BF_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05BF_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C0_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C0_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C0_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C0_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C0_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C0_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C1_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C1_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C1_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C1_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C1_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C1_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C2_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C2_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C2_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C2_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C2_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C2_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C3_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C3_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C3_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C3_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C3_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C3_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C4_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C4_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C4_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C4_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C4_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C4_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C5_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C5_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C5_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C5_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C5_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C5_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C6_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C6_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C6_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C6_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C6_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C6_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C7_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C7_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C7_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C7_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C7_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C7_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C8_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C8_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C8_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C8_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C8_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C8_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C9_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C9_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05C9_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C9_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05C9_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05C9_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CA_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CA_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type));

            (void)SetEvent(APP1_TASK1_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK1_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CA_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CA_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CA_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CA_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CB_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CB_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CB_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CB_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CB_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CB_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CC_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CC_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CC_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CC_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CC_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CC_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CD_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CD_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CD_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CD_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CD_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CD_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CE_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CE_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CE_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CE_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CE_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CE_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CF_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CF_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05CF_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CF_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05CF_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05CF_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D0_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D0_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D0_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D0_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D0_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D0_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D1_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D1_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D1_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D1_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D1_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D1_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D2_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D2_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D2_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D2_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D2_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D2_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D3_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D3_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D3_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D3_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D3_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D3_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D4_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D4_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0X05D4_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D4_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0X05D4_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0x05D4_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF00_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF00_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF00_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF00_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF00_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF00_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF05_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF05_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF05_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF05_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF05_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF05_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF06_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF06_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF06_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF06_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF06_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF06_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF07_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF07_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XCF07_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF07_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XCF07_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xCF07_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDD00_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDD00_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_6));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDD00_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDD00_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDD00_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_6));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDD00_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF00_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF00_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF00_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF00_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF00_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF00_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF01_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF01_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_2));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF01_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF01_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF01_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_2));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF01_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF02_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF02_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF02_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF02_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF02_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF02_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF03_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF03_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_3));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF03_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF03_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF03_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_3));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF03_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(uint8, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF04_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF04_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            Rte_MemCpy32((uint8*)(cs_Server.Data), (uint8*)Data, sizeof(rt_Array_UInt8_T_3));
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF04_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF04_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF04_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData_Type));
                Rte_MemCpy32((uint8*)Data, (uint8*)(cs_Server.Data), sizeof(rt_Array_UInt8_T_3));
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF04_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF06_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF06_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF06_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF06_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF06_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF06_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData( VAR(UInt8_T, RTE_swc_DiagcEveHndlg_APPL_DATA) OpStatus, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) Data, P2VAR(UInt8_T, AUTOMATIC, RTE_swc_DiagcEveHndlg_APPL_DATA) ErrorCode)
{
    Std_ReturnType ret = RTE_E_OK;

    if(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData.Rte_Call_Busy == FALSE)
    {
        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData.Rte_Call_Busy = TRUE;
        Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type cs_Server = {0};

        (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF09_0_READDATA);
        void* pPush = RteStack_Push(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData);
        (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF09_0_READDATA);
        if(NULL_PTR != pPush)
        {
            cs_Server.OpStatus = OpStatus;
            cs_Server.Data = *Data;
            cs_Server.ErrorCode = *ErrorCode;
            Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData.Rte_ServerCompleted = FALSE;
            Rte_MemCpy32((uint8*)pPush, (uint8*)(&cs_Server), sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type));

            (void)SetEvent(APP1_TASK2_UDS_CORE2_QM, RTE_EV_CYCLIC_APP1_TASK2_UDS_CORE2_QM_SWC_TESTDCM_DATASERVICES_DSPDATA_0XDF09_22_RE);

            while(Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData.Rte_ServerCompleted == FALSE);

            (void)GetSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF09_0_READDATA);
            void* pPop = RteStack_Pop(&RteStackBuffer_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData);
            (void)ReleaseSpinlock(SPINLOCK_RTE_CS_SWC_DIAGCEVEHNDLG_DATASERVICES_DSPDATA_0XDF09_0_READDATA);
            if(NULL_PTR != pPop)
            {
                Rte_MemCpy32((uint8*)(&cs_Server), (uint8*)pPop, sizeof(Rte_CS_Server_Parameter_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData_Type));
                *Data = cs_Server.Data;
                *ErrorCode = cs_Server.ErrorCode;
            }
            else
            {
                ret = RTE_E_INVALID;
            }
        }
        else
        {
            ret = RTE_E_INVALID;
        }

        Rte_CS_Server_Property_swc_DiagcEveHndlg_DataServices_DspData_0xDF09_0_ReadData.Rte_Call_Busy = FALSE;
    }
    else
    {
        ret = RTE_E_INVALID;
    }
    return ret;
}


#endif
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

/*
************************************************************************************************************************
*    Definition of Internal/External Rx connections
************************************************************************************************************************
*/
#define RTE_START_SEC_CODE
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BSW_NM_BMS_DelayControl_BMS_DelayControl(P2VAR(Boolean, AUTOMATIC, RTE_BSW_NM_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_COL_BMS_DelayControl_BMS_DelayControl;
    return ret;
}
FUNC(Std_ReturnType, RTE_CODE) Rte_Read_BSW_NM_vcib_VCIP_hvbd_b_tboxIntelChgCmd(P2VAR(Boolean, AUTOMATIC, RTE_BSW_NM_APPL_DATA) data)
{
    Std_ReturnType ret = RTE_E_OK;
    *(data) = Rte_swc_VCIP_vcib_VCIP_hvbd_b_tboxIntelChgCmd;
    return ret;
}
#define RTE_STOP_SEC_CODE
#include "Rte_MemMap.h"
  
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
TASK(Bsw_Task_1ms_Core4_QM)
{
    Core4_Runnable_Bsw_1ms();

    (void)TerminateTask();
}

TASK(Bsw_Task_5ms_Core4_QM)
{
    Core4_Runnable_Bsw_5ms();

    BswM_MainFunction();

    ComM_MainFunction_0();

    ComM_MainFunction_1();

    ComM_MainFunction_2();

    ComM_MainFunction_3();

    ComM_MainFunction_4();

    ComM_MainFunction_5();

    ComM_MainFunction_6();

    CanSM_MainFunction();

    (void)TerminateTask();
}

TASK(Bsw_Task_5ms_Core4_Offest_QM)
{
    CanNm_UserWakeUp();

    BSW_NM_5ms();

    CanNm_MainFunction();

    Com_MainFunctionTx();

    CanTp_MainFunction();

    (void)TerminateTask();
}

TASK(Bsw_Task_10ms_Core4_QM)
{
    Core4_Runnable_Bsw_10ms();

    Com_MainFunctionRouteSignals();

    Com_MainFunctionRx();

    LinSM_MainFunction();

    (void)TerminateTask();
}

TASK(Bsw_Task_10ms_Core4_Offest_QM)
{
    LinIf_MainFunction_VE21_N72_PMS_LIN_ldf_T34TDk();

    Rte_ComSendSignalProxyPeriodic_OsCore0();

    J1939Tp_MainFunction();

    Dcm_MainFunction();

    Dem_MainFunction();

    (void)TerminateTask();
}

TASK(Bsw_Task_20ms_Core4_QM)
{
    Core4_Runnable_Bsw_20ms();

    (void)TerminateTask();
}

TASK(Bsw_Task_50ms_Core4_QM)
{
    Core4_Runnable_Bsw_50ms();

    (void)TerminateTask();
}

TASK(Bsw_Task_100ms_Core4_QM)
{
    Core4_Runnable_Bsw_100ms();

    (void)TerminateTask();
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

