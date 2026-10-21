/* PRQA S 0380, 3432, 1881, 2013, 4342 EOF */
/****************************************************************************
 *
 * Copyright (c) 2023  C*Core -   All Rights Reserved
 *
 * THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
 * INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *   Project              : AUTOSAR 4.4.0 MCAL
 *   Platform             : PowerPC e200
 *   Peripheral           :
 *   Dependencies         :
 *
 *   Autosar Version      : 4.4.0
 *   Autosar Revision     : ASR_REL_4_3_REV_0000
 *   Autosar Conf.Variant :
 *   SW Version           :
 *   Build Version        :
 *
 *****************************************************************************/

/**
 *   @file    Fr_HAL_Wrapper.c
 *   @version 3.0.0
 *
 *   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
 *   @details Autosar layer of Fr MCAL driver.
 *
 *   @addtogroup Fr
 *   @{
 */

#ifdef __cplusplus
extern "C"{
#endif

#include "derivative.h"
#ifdef RESOURCE_SUPPORT_FLEXRAY
#include "Fr_HAL_Wrapper.h"
#include "Fr_LLDriver.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_HAL_WAR_VENDOR_ID_C                        176
#define FR_HAL_WAR_AR_RELEASE_MAJOR_VERSION_C         4
#define FR_HAL_WAR_AR_RELEASE_MINOR_VERSION_C         4
/* @violates @ref FR_FR_HAL_WAR_H_REF_2 */
#define FR_HAL_WAR_AR_RELEASE_REVISION_VERSION_C      0
#define FR_HAL_WAR_SW_MAJOR_VERSION_C                 3
#define FR_HAL_WAR_SW_MINOR_VERSION_C                 0
#define FR_HAL_WAR_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_HAL_Wrapper.h header file are of the same vendor */
#if(FR_HAL_WAR_VENDOR_ID_C != FR_HAL_WAR_H_VENDOR_ID)
    #error "Fr_HAL_Wrapper.c and Fr_HAL_Wrapper.h have different Vendor IDs"
#endif
/* Check if current file and Fr_HAL_Wrapper.h header file are of the same Autosar version */
#if((FR_HAL_WAR_AR_RELEASE_MAJOR_VERSION_C    != FR_HAL_WAR_H_AR_RELEASE_MAJOR_VERSION) || \
    (FR_HAL_WAR_AR_RELEASE_MINOR_VERSION_C    != FR_HAL_WAR_H_AR_RELEASE_MINOR_VERSION) || \
    (FR_HAL_WAR_AR_RELEASE_REVISION_VERSION_C != FR_HAL_WAR_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_HAL_Wrapper.c and Fr_HAL_Wrapper.h are different"
#endif
/* Check if current file and Fr_HAL_Wrapper.h header file are of the same software version */
#if((FR_HAL_WAR_SW_MAJOR_VERSION_C != FR_HAL_WAR_H_SW_MAJOR_VERSION) || \
    (FR_HAL_WAR_SW_MINOR_VERSION_C != FR_HAL_WAR_H_SW_MINOR_VERSION) || \
    (FR_HAL_WAR_SW_PATCH_VERSION_C != FR_HAL_WAR_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_HAL_Wrapper.c and Fr_HAL_Wrapper.h are different"
#endif

/* Check if current file and Fr_LLDriver header file are of the same vendor */
#if(FR_HAL_WAR_VENDOR_ID_C != FR_LLD_H_VENDOR_ID)
    #error "Fr_HAL_Wrapper.c and Fr_LLDriver have different Vendor IDs"
#endif
/* Check if current file and Fr_LLDriver header file are of the same Autosar version */
#if((FR_HAL_WAR_AR_RELEASE_MAJOR_VERSION_C    != FR_LLD_H_AR_RELEASE_MAJOR_VERSION) || \
    (FR_HAL_WAR_AR_RELEASE_MINOR_VERSION_C    != FR_LLD_H_AR_RELEASE_MINOR_VERSION) || \
    (FR_HAL_WAR_AR_RELEASE_REVISION_VERSION_C != FR_LLD_H_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_HAL_Wrapper.c and Fr_LLDriver are different"
#endif
/* Check if current file and Fr_LLDriver header file are of the same software version */
#if((FR_HAL_WAR_SW_MAJOR_VERSION_C != FR_LLD_H_SW_MAJOR_VERSION) || \
    (FR_HAL_WAR_SW_MINOR_VERSION_C != FR_LLD_H_SW_MINOR_VERSION) || \
    (FR_HAL_WAR_SW_PATCH_VERSION_C != FR_LLD_H_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_HAL_Wrapper.c and Fr_LLDriver.h are different"
#endif

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_HAL_InitConfigMode(P2CONST(Fr_HW_config_type, AUTOMATIC, FR_APPL_CONST) Fr_HW_config_temp_ptr, P2CONST(Fr_low_level_config_type, AUTOMATIC, FR_APPL_CONST) Fr_low_level_config_temp_ptr)
{

    return Fr_LLD_Init(Fr_HW_config_temp_ptr,Fr_low_level_config_temp_ptr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_ClusterNodeParamCfg(P2CONST(Fr_HW_config_type, AUTOMATIC, FR_APPL_CONST) Fr_HW_config_temp_ptr, P2CONST(Fr_low_level_config_type, AUTOMATIC, FR_APPL_CONST) Fr_low_level_config_temp_ptr)
{

    Fr_LLD_Set_Configuration(Fr_HW_config_temp_ptr,Fr_low_level_config_temp_ptr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_HAL_Buffers_Init(VAR(uint8, FR_VAR) Fr_CtrlIdx,P2CONST(Fr_buffer_info_type, AUTOMATIC, FR_APPL_CONST) Fr_buffers_config_temp_ptr, P2CONST(Fr_index_selector_type, AUTOMATIC, FR_APPL_CONST) Fr_buffer_config_set_temp_ptr)
{

    return Fr_LLD_Buffers_Init(Fr_CtrlIdx,Fr_buffers_config_temp_ptr,Fr_buffer_config_set_temp_ptr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_HAL_Leave_Configuration_Mode(VAR(void, FR_VAR))
{

    return Fr_LLD_Leave_Configuration_Mode();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_ReadCCConfig(P2CONST(Fr_low_level_config_type, AUTOMATIC, *) Fr_low_level_config_ptr)
{

    return Fr_Driver_ReadCCConfig(Fr_low_level_config_ptr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_DisableTimers(VAR(void, FR_VAR))
{

    Fr_Driver_DisableTimers();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_CheckCCAccess(VAR(void, FR_VAR))
{

    return Fr_Driver_CheckCCAccess();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_POCStateType, FR_CODE) Fr_HAL_Get_POC_State(VAR(void, FR_VAR))
{

    return Fr_LLD_Get_POC_State();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_HAL_Start_Communication(VAR(void, FR_VAR))
{

    return Fr_LLD_Start_Communication();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_InvokeCHICommand(VAR(uint16, AUTOMATIC) CHICommand)
{

    return Fr_Driver_InvokeCHICommand(CHICommand);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_HAL_Stop_Communication(VAR(Fr_stop_communication_type, FR_VAR) Fr_stop_option)
{

    return Fr_LLD_Stop_Communication(Fr_stop_option);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_LLDriver_StatusType, FR_CODE) Fr_HAL_Send_Wakeup(VAR(void, FR_VAR))
{

    return Fr_LLD_Send_Wakeup();
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_SetWakeupChannel(VAR(Fr_ChannelType, FR_VAR) Fr_ChnlIdx)
{

    return Fr_Driver_SetWakeupChannel(Fr_ChnlIdx);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_GetPOCStatus(P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) pPocState)
{

    return Fr_Driver_GetPOCStatus(pPocState);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_tx_MB_status_type, FR_CODE) Fr_HAL_Transmit_Data(VAR(uint16, FR_VAR) Fr_buffer_idx, P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_data_ptr, VAR(uint8, FR_VAR) Fr_data_length)
{

    return Fr_LLD_Transmit_Data(Fr_buffer_idx,Fr_data_ptr,Fr_data_length);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_FrExtendedLPduReport(P2CONST(Fr_CtrlCfgType, AUTOMATIC, *) pCtrlCfg, VAR(uint16, AUTOMATIC) mb_index, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) pSlotAssignment)
{

    return Fr_Driver_FrExtendedLPduReport(pCtrlCfg,mb_index,pSlotAssignment);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_CancelTxLPdu(VAR(uint16, AUTOMATIC) Mbidx,P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) pbPendingStatus)
{

    return Fr_Driver_CancelTxLPdu(Mbidx,pbPendingStatus);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_RxLPduStatusType, FR_CODE) Fr_HAL_Receive_Data(VAR(uint16, FR_VAR) Fr_buffer_idx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr,P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{

    return Fr_LLD_Receive_Data(Fr_buffer_idx,Fr_data_ptr,Fr_data_length_ptr,Fr_SlotAssignmentPtr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_RxLPduStatusType, FR_CODE) Fr_HAL_Receive_FifoA_Data(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{
    VAR(Fr_FIFO_status_type, FR_VAR) fifo_rx_retval;
    VAR(Fr_RxLPduStatusType, FR_VAR) retVal;
    
    fifo_rx_retval = Fr_LLD_Receive_FifoA_Data(Fr_data_ptr,Fr_data_length_ptr,Fr_SlotAssignmentPtr);
    switch (fifo_rx_retval)
    {
        case FR_FIFO_RECEIVED:
            retVal = FR_RECEIVED_MORE_DATA_AVAILABLE;
            break;
        case FR_FIFO_NOT_RECEIVED:
            retVal = FR_NOT_RECEIVED;
            break;
        default:
            retVal = FR_NOT_RECEIVED;
            break;
    }
    return retVal;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Fr_RxLPduStatusType, FR_CODE) Fr_HAL_Receive_FifoB_Data(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_ptr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_data_length_ptr, P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) Fr_SlotAssignmentPtr)
{
    VAR(Fr_FIFO_status_type, FR_VAR) fifo_rx_retval;
    VAR(Fr_RxLPduStatusType, FR_VAR) retVal;
    
    fifo_rx_retval = Fr_LLD_Receive_FifoB_Data(Fr_data_ptr,Fr_data_length_ptr,Fr_SlotAssignmentPtr);
    switch (fifo_rx_retval)
    {
        case FR_FIFO_RECEIVED:
            retVal = FR_RECEIVED_MORE_DATA_AVAILABLE;
            break;
        case FR_FIFO_NOT_RECEIVED:
            retVal = FR_NOT_RECEIVED;
            break;
        default:
            retVal = FR_NOT_RECEIVED;
            break;
    }
    return retVal;

}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_Check_Tx_Status(P2CONST(Fr_CtrlCfgType, AUTOMATIC, *)pCtrlCfg, VAR(uint16, FR_VAR) Fr_LPduIdx,P2VAR(Fr_SlotAssignmentType, AUTOMATIC, FR_APPL_DATA) pSlotAssignment,P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr)
{

    return Fr_LLD_Check_Tx_Status(pCtrlCfg,Fr_LPduIdx,pSlotAssignment,Fr_TxLPduStatusPtr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#if (FR_RECONFIG_LPDU_SUPPORT == STD_ON)
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_PrepareLPdu(P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,VAR(uint16, AUTOMATIC) Mbindex,VAR(uint16, AUTOMATIC) LPduIdx)
{

    return Fr_Driver_PrepareLPdu(pCtrlCfg,Mbindex,LPduIdx);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_ReconfigLPdu
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint16, AUTOMATIC) Mbindex,
    VAR(uint16, AUTOMATIC) FrameId,
    VAR(Fr_ChannelType, AUTOMATIC) chnlIdx,
    VAR(uint8, AUTOMATIC) CycleRepetition,
    VAR(uint8, AUTOMATIC) CycleOffset,
    VAR(uint8, AUTOMATIC) PayloadLength,
    VAR(uint16, AUTOMATIC) HeaderCRC
)
{

    return Fr_Driver_ReconfigLPdu(pCtrlCfg,Mbindex, FrameId, chnlIdx, CycleRepetition,CycleOffset, PayloadLength, HeaderCRC);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"


#if (FR_DISABLE_LPDU_SUPPORT == STD_ON)
#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_DisableLPdu(VAR(uint16, AUTOMATIC) Mbidx)
{

    return Fr_Driver_DisableLPdu( Mbidx );
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"
#endif
#endif

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_Get_Global_Time(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_cycle_ptr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_macrotick_ptr)
{

    Fr_LLD_Get_Global_Time(Fr_cycle_ptr,Fr_macrotick_ptr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_Get_Network_Management_Vector(P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_vector_ptr)
{

    return Fr_LLD_Get_Network_Management_Vector(Fr_vector_ptr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_GetChannelStatus
( 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAStatusPtr, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBStatusPtr
)
{

    Fr_Driver_GetChannelStatus(channelAStatusPtr,channelBStatusPtr);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_GetClockCorrection(P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) ps16RateCorrection,P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) ps32OffsetCorrection)
{

    return Fr_Driver_GetClockCorrection(ps16RateCorrection,ps32OffsetCorrection);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_GetSyncFrameList
(
    P2CONST(Fr_CtrlCfgType, AUTOMATIC, FR_APPL_CONST) pCtrlCfg,
    VAR(uint8, AUTOMATIC) u8ListSize,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelAEvenList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelBEvenList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelAOddList,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) pu16ChannelBOddList
)
{

    return Fr_Driver_GetSyncFrameList(pCtrlCfg,u8ListSize,pu16ChannelAEvenList,pu16ChannelBEvenList,pu16ChannelAOddList,pu16ChannelBOddList);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_GetWakeupRxStatus
(
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) pu8WakeupRxStatus
)
{

    return Fr_Driver_GetWakeupRxStatus(pu8WakeupRxStatus);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_SetAbsTimers(VAR(uint8, AUTOMATIC) timerIdx,VAR(uint8, AUTOMATIC) cycle,VAR(uint16, AUTOMATIC) offset)
{

    return Fr_Driver_SetAbsTimers(timerIdx,cycle,offset);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_CancelAbsTimer(VAR(uint8, FR_VAR) timer_ID)
{

    Fr_Stop_Timer((Fr_timer_ID_type)timer_ID);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_EnableAbsoluteTimerIRQ(VAR(uint8, AUTOMATIC) timerIdx)
{
    VAR(Std_ReturnType, AUTOMATIC) ret = E_NOT_OK;

    if( (uint8)FR_TIMER_T1 == timerIdx)
    {
        Fr_LLD_Enable_Interrupts((FR_PROTOCOL_IRQ), \
                                (FR_TIMER_1_EXPIRED_IRQ), 0U);
        ret = E_OK;
    }
    else if((uint8)FR_TIMER_T2 == timerIdx)
    {
        Fr_LLD_Enable_Interrupts((FR_PROTOCOL_IRQ ), \
                                (FR_TIMER_2_EXPIRED_IRQ ), 0U);
        ret = E_OK;
    }
    else
    {
    /*do nothing*/
    }

    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(Std_ReturnType, FR_CODE) Fr_HAL_DisableAbsoluteTimerIRQ(VAR(uint8, AUTOMATIC) timerIdx)
{
    VAR(Std_ReturnType, AUTOMATIC) ret = E_NOT_OK;

    if( (uint8)FR_TIMER_T1 == timerIdx)
    {
        Fr_LLD_Disable_Interrupts(0U, (FR_TIMER_1_EXPIRED_IRQ), 0U);
        ret = E_OK;
    }
    else if((uint8)FR_TIMER_T2 == timerIdx)
    {
        Fr_LLD_Disable_Interrupts(0U, (FR_TIMER_2_EXPIRED_IRQ ), 0U);
        ret = E_OK;
    }
    else
    {
    /*do nothing*/
    }

    return ret;
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_AckAbsTimerIRQ(VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx)
{
    
    Fr_Driver_AckAbsTimerIRQ(Fr_AbsTimerIdx);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(boolean, FR_CODE) Fr_HAL_GetAbsoluteTimerIRQStatus(VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx)
{

    return Fr_Driver_GetAbsoluteTimerIRQStatus(Fr_AbsTimerIdx);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_InterruptEnable(VAR(uint16, AUTOMATIC) Fr_InterruptSource)
{

    Fr_LLD_Enable_Interrupts(Fr_InterruptSource, 0, 0);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_InterruptDisable(VAR(uint16, AUTOMATIC) Fr_InterruptSource)
{

    Fr_LLD_Disable_Interrupts(Fr_InterruptSource, 0, 0);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#define FR_START_SEC_CODE
#include "Fr_MemMap.h"
FUNC(void, FR_CODE) Fr_HAL_Disable_AllInterrupts(void)
{

    Fr_LLD_Low_Level_Access_Write_Reg(FrGIFER,0U);
    Fr_LLD_Low_Level_Access_Write_Reg(FrPIER0,0U);
    Fr_LLD_Low_Level_Access_Write_Reg(FrPIER1,0U);
}
#define FR_STOP_SEC_CODE
#include "Fr_MemMap.h"

#endif /* RESOURCE_SUPPORT_FLEXRAY */

#ifdef __cplusplus
}
#endif
