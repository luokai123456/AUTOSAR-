/*
********************************************************************************
*
* File name: CanNm_Cfg.h                                                   
*                                                                              
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.           
*
********************************************************************************
*
* History                                                               
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2018.12.13
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : jia_feng/2019.12.27
* Change: Add unimplemented macros.
* Cause: Optimization
********************************************************************************
* Version: 1.2
* Author/Date : jia_feng/2020.01.16
* Change: Optimize the configuration of CanNm ,delete some extra configurations.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date : jia_feng/2020.04.20
* Change: Add BusLoadReductionActive in the struct of CanNm_ChannelConfigType.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date : jia_feng/2020.04.26
* Change: Add macro of CANNM_MAX_NUMBER_OF_COMM_CHANNELS.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date : jia_feng/2020.05.09
* Change: Optimize variable definition(add CANNM_PN_INFO_LENGTH and 
*         CANNM_PN_INFO_OFFSET).
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date : jia_feng/2020.06.17
* Change: Add Tx Rx message buffer for every channel(CanNm_TxMessageData,
*         CanNm_RxMessageData).
* Cause: Bugfix
********************************************************************************
*/
#ifndef CANNM_CFG_H_
#define CANNM_CFG_H_

/*
*******************************************************************************
*    Includes
*******************************************************************************
*/
#include "ComStack_Types.h"
#include "NmStack_Types.h"

/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CANNM_MAX_NUMBER_OF_COMM_CHANNELS                                   7U
#define CANNM_NUMBER_OF_CANNM_CHANNELS                                      2U

/* Options */
#define CANNM_RMR_FAST_TRANSITION                                           (STD_ON)//NOS或者RSS通过RMR回到RMS之后，是否需要进入快发模式，手动添加配置项
#define CANNM_AWB_RSS_UPDATE_SUPPORTED                                      (STD_ON)//RSS -> RMS/NOS AWB更新，是否支持RSS唤醒更新AWB，手动添加配置项
#define CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED                               (STD_ON)//所有NM报文是否支持同睡同醒，手动添加配置项
#define CANNM_NM_USER_ENABLE_SUPPORTED                                      (STD_ON)//用户层是否支持NM报文发送使能，手动添加配置项
#define CANNM_ACTIVE_WUP_BIT_FEATURE_ENABLED                                (STD_ON)
#define CANNM_ALL_MSG_KEEP_AWAKE_ENABLED                                    (STD_OFF)
#define CANNM_BUS_LOAD_REDUCTION_ENABLED                                    (STD_ON)
#define CANNM_BUS_SYNCHRONIZATION_ENABLED                                   (STD_ON)
#define CANNM_CAR_WUP_FILTER_FEATURE_ENABLED                                (STD_OFF)
#define CANNM_CAR_WUP_RX_FEATURE_ENABLED                                    (STD_OFF)
#define CANNM_COM_CONTROL_ENABLED                                           (STD_ON)
#define CANNM_COM_USER_DATA_SUPPORT                                         (STD_ON)
#define CANNM_COORDINATOR_SYNC_SUPPORT                                      (STD_OFF)
#define CANNM_DEV_ERROR_DETECT                                              (STD_ON)
#define CANNM_IMMEDIATE_RESTART_ENABLED                                     (STD_ON)
#define CANNM_IMMEDIATE_TXCONF_ENABLED                                      (STD_OFF)
#define CANNM_NODE_DETECTION_ENABLED                                        (STD_ON)
#define CANNM_NODE_ID_ENABLED                                               (STD_ON)
#define CANNM_PASSIVE_MODE_ENABLED                                          (STD_OFF)
#define CANNM_PDU_RX_INDICATION_ENABLED                                     (STD_ON)
#define CANNM_PN_EIRA_CALC_FEATURE_ENABLED                                  (STD_OFF)
#define CANNM_PN_ERA_CALC_FEATURE_ENABLED                                   (STD_OFF)
#define CANNM_PN_FEATURE_ENABLED                                            (STD_OFF)
#define CANNM_PN_HANDLE_MULTIPLE_NETWORK_REQUEST                            (STD_OFF)
#define CANNM_PN_MESSAGE_FILTER_FORCED_ENABLED                              (STD_OFF)
#define CANNM_REMOTE_SLEEP_IND_ENABLED                                      (STD_OFF)
#define CANNM_REPEAT_MSG_IND_ENABLED                                        (STD_ON)
#define CANNM_RETRY_FIRST_MESSAGE_REQUEST                                   (STD_ON)
#define CANNM_STATE_CHANGE_IND_ENABLED                                      (STD_OFF)
#define CANNM_USER_DATA_ENABLED                                             (STD_OFF)
#define CANNM_VERSION_INFO_API                                              (STD_ON)
#define CANNM_PN_EIRA_RXPDUID                                               0xFFFFU
#define CANNM_PN_INFO_LENGTH                                                0U
#define CANNM_PN_RESET_TIME                                                 0U

/*  These macros can be used to read deduplicated data elements. */
#define CanNm_GetPnEiraRxPduId()                CANNM_PN_EIRA_RXPDUID
#define CanNm_GetPnResetTime()                  CANNM_PN_RESET_TIME
#define CanNm_GetPnInfoLength()                 CANNM_PN_INFO_LENGTH
#define CanNm_GetPnInfoOffset()                 CANNM_PN_INFO_OFFSET
#define CanNm_GetSizeOfChannelConfig()          CANNM_NUMBER_OF_CANNM_CHANNELS
#define CanNm_GetSizeOfSysToNmChInd()			CANNM_MAX_NUMBER_OF_COMM_CHANNELS
#define CanNm_GetSizeOfPnClusterReqNew()        CANNM_PN_INFO_LENGTH
#define CanNm_GetSizeOfPnClusterResetTimer()    CANNM_PN_INFO_LENGTH
#define CanNm_GetSizeOfPnFilterMask()           CANNM_PN_INFO_LENGTH

/* Invalid Channel Handle */
#define CANNM_INVALID_CHANNEL  					(0xFFU)

/* Pdu CBV / NID Position Defines */
#define CANNM_PDU_OFF          					(0xFFU)
#define CANNM_PDU_BYTE_0      					(0x00U)
#define CANNM_PDU_BYTE_1       					(0x01U)

/* PN Calculation */
#define CANNM_PN_CLUSTERS_PER_BYTE              (0x08U)
#define CANNM_MAX_NUM_RXPDUID_PER_CHANNEL                                   2U

/* PolySpace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_CanNm_17.8" */
#define CANNM_DUMMY_STATEMENT(v)				((v)=(v)) /* Default */
#define CANNM_DUMMY_STATEMENT_CONST(v)			((void)(v))/* Default */

/*  These defines are used to indicate unused indexes in data relations. */ 
#define CANNM_NO_SYSTONMCHIND								(0xFFU)
#define CANNM_NO_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG		(0xFFU)

/*  Symbolic initialization pointers to be used in the call of a preinit or init function. */
#define CanNm_Config_Ptr                                    NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CanNm' */


/* Symbolic initialization pointers which may be used in the call of a preinit or init function.
Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable. */
#define CanNm_Config										NULL_PTR  /**< symbolic identifier which could be used to initialize 'CanNm */

/* These macros can be used to read CONST and VAR data. */
#define CanNm_GetChannelId(Index)                           ((NetworkHandleType)CanNm_ChannelConfig[(Index)].ChannelId)
#define CanNm_GetImmediateNmCycleTime(Index)                (CanNm_ChannelConfig[(Index)].ImmediateNmCycleTime)
#define CanNm_GetImmediateNmTransmissions(Index)            (CanNm_ChannelConfig[(Index)].ImmediateNmTransmissions)
#define CanNm_GetMsgCycleTime(Index)                        (CanNm_ChannelConfig[(Index)].MsgCycleTime)
#define CanNm_GetMsgTimeoutTime(Index)						(CanNm_ChannelConfig[(Index)].MsgTimeoutTime)
#define CanNm_IsNodeDetectionEnabled(Index)					(CanNm_ChannelConfig[(Index)].NodeDetectionEnabled)
#define CanNm_IsNodeIdEnabled(Index)						(CanNm_ChannelConfig[(Index)].NodeIdEnabled)
#define CanNm_GetPduCbvPosition(Index)						(CanNm_ChannelConfig[(Index)].PduCbvPosition)
#define CanNm_GetPduNidPosition(Index)						(CanNm_ChannelConfig[(Index)].PduNidPosition)
#define CanNm_IsPnCallTxTimeoutException(Index)				(CanNm_ChannelConfig[(Index)].PnCallTxTimeoutException)
#define CanNm_GetRemoteSleepIndTime(Index)					(CanNm_ChannelConfig[(Index)].RemoteSleepIndTime)
#define CanNm_GetRepeatMessageTime(Index)					(CanNm_ChannelConfig[(Index)].RepeatMessageTime)
#define CanNm_GetTimeoutTime(Index)							(CanNm_ChannelConfig[(Index)].TimeoutTime)
#define CanNm_GetWaitBusSleepTime(Index)					(CanNm_ChannelConfig[(Index)].WaitBusSleepTime)
#define CanNm_GetCommState(Index)							(CanNm_CommState[(Index)])
#define CanNm_GetCoordReadyToSleepState(Index)				(CanNm_CoordReadyToSleepState[(Index)])
#define CanNm_GetImmediateNmMsgCount(Index)					(CanNm_ImmediateNmMsgCount[(Index)])
#define CanNm_IsMsgConfirmationFlag(Index)					(CanNm_MsgConfirmationFlag[(Index)])
#define CanNm_IsMsgIndicationFlag(Index)					(CanNm_MsgIndicationFlag[(Index)])
#define CanNm_GetMsgRequest(Index)							(CanNm_MsgRequest[(Index)])
#define CanNm_GetMsgTimeoutTimer(Index)						(CanNm_MsgTimeoutTimer[(Index)])
#define CanNm_GetMsgTimer(Index)							(CanNm_MsgTimer[(Index)])
#define CanNm_GetNetworkRestartFlag(Index)					(CanNm_NetworkRestartFlag[(Index)])
#define CanNm_GetMsgCycleOffset(Index)						(CanNm_PbChannelConfig[(Index)].MsgCycleOffset)
#define CanNm_GetNodeId(Index)								(CanNm_PbChannelConfig[(Index)].NodeId)
#define CanNm_IsPnEnabled(Index)							(CanNm_PbChannelConfig[(Index)].PnEnabled)
#define CanNm_IsPnHandleMultipleNetworkRequest(Index)		(CanNm_PbChannelConfig[(Index)].PnHandleMultipleNetworkRequest)
#define CanNm_IsAllMessagesKeepAwakeEnabled(Index)			(CanNm_ChannelConfig[(Index)].AllMessagesKeepAwakeEnabled)

#define CanNm_GetCarWakeUpBitMask(Index)                    (CanNm_ChannelConfig[(Index)].CarWakeUpBitMask)
#define CanNm_GetCarWakeUpBytePosition(Index)               (CanNm_ChannelConfig[(Index)].CarWakeUpBytePosition)
#define CanNm_GetCarWakeUpFilterNodeId(Index)               (CanNm_ChannelConfig[(Index)].CarWakeUpFilterNodeId)
#define CanNm_IsCarWakeUpFilterEnabled(Index)               (CanNm_ChannelConfig[(Index)].CarWakeUpFilterEnabled)
#define CanNm_IsCarWakeUpRxEnabled(Index)                   (CanNm_ChannelConfig[(Index)].CarWakeUpRxEnabled)

#define CanNm_GetRxMsgDataEndIdx(Index)                     (CanNm_PbChannelConfig[(Index)].RxMsgDataEndIdx)
#define CanNm_GetRxMsgDataLength(Index)                     (CanNm_PbChannelConfig[(Index)].RxMsgDataLength)
#define CanNm_GetRxMsgDataStartIdx(Index)                   (CanNm_PbChannelConfig[(Index)].RxMsgDataStartIdx)
#define CanNm_GetRxMsgData_CBVIdx(Index)                    (CanNm_PbChannelConfig[(Index)].RxMsgData_CBVIdx)
#define CanNm_GetRxMsgData_NIDIdx(Index)                    (CanNm_PbChannelConfig[(Index)].RxMsgData_NIDIdx)
#define CanNm_GetRxMsgData_UserDataEndIdx(Index)            (CanNm_PbChannelConfig[(Index)].RxMsgData_UserDataEndIdx)
#define CanNm_GetRxMsgData_UserDataLength(Index)            (CanNm_PbChannelConfig[(Index)].RxMsgData_UserDataLength)
#define CanNm_GetRxMsgData_UserDataStartIdx(Index)          (CanNm_PbChannelConfig[(Index)].RxMsgData_UserDataStartIdx)
#define CanNm_GetTxMsgDataEndIdx(Index)                     (CanNm_PbChannelConfig[(Index)].TxMsgDataEndIdx)
#define CanNm_GetTxMsgDataLength(Index)                     (CanNm_PbChannelConfig[(Index)].TxMsgDataLength)
#define CanNm_GetTxMsgDataStartIdx(Index)                   (CanNm_PbChannelConfig[(Index)].TxMsgDataStartIdx)
#define CanNm_GetTxMsgData_CBVIdx(Index)                    (CanNm_PbChannelConfig[(Index)].TxMsgData_CBVIdx)
#define CanNm_GetTxMsgData_NIDIdx(Index)                    (CanNm_PbChannelConfig[(Index)].TxMsgData_NIDIdx)
#define CanNm_GetTxMsgData_PFMEndIdx(Index)                 (CanNm_PbChannelConfig[(Index)].TxMsgData_PnFilterMaskEndIdx)
#define CanNm_GetTxMsgData_PFMStartIdx(Index)               (CanNm_PbChannelConfig[(Index)].TxMsgData_PnFilterMaskStartIdx)
#define CanNm_GetTxMsgData_UserDataEndIdx(Index)            (CanNm_PbChannelConfig[(Index)].TxMsgData_UserDataEndIdx)
#define CanNm_GetTxMsgData_UserDataLength(Index)            (CanNm_PbChannelConfig[(Index)].TxMsgData_UserDataLength)
#define CanNm_GetTxMsgData_UserDataStartIdx(Index)          (CanNm_PbChannelConfig[(Index)].TxMsgData_UserDataStartIdx)
#define CanNm_GetTxPduId(Index)                             (CanNm_PbChannelConfig[(Index)].TxPduId)
#define CanNm_GetTxPduRef(Index)                            (CanNm_PbChannelConfig[(Index)].TxPduRef)
#define CanNm_GetTxUserDataPduId(Index)                     (CanNm_PbChannelConfig[(Index)].TxUserDataPduId)
#define CanNm_GetPnClusterReq(Index)                        (CanNm_PnClusterReq[(Index)])
#define CanNm_GetPnClusterReqNew(Index)                     (CanNm_PnClusterReqNew[(Index)])
#define CanNm_GetPnClusterResetTimer(Index)                 (CanNm_PnClusterResetTimer[(Index)])
#define CanNm_GetPnFilterMask(Index)                        (CanNm_PnFilterMask[(Index)])
#define CanNm_IsPnEraCalcEnabled(Index)                     (CanNm_ChannelConfig[(Index)].PnEraCalcEnabled)
#define CanNm_GetPnClusterReqExtStartIdx(Index)             (CanNm_PbChannelConfig[(Index)].PnClusterReqExtStartIdx)
#define CanNm_GetPnClusterReqExtEndIdx(Index)               (CanNm_PbChannelConfig[(Index)].PnClusterReqExtEndIdx)
#define CanNm_GetPnClusterReqExtNew(Channel,Index)                    (CanNm_PnClusterReqExtNew[(Channel)][(Index)])
#define CanNm_GetPnClusterReqExt(Channel,Index)                       (CanNm_PnClusterReqExt[(Channel)][(Index)])
#define CanNm_GetPnClusterResetTimerExt(Channel,Index)                (CanNm_PnClusterResetTimerExt[(Channel)][(Index)])
#define CanNm_GetAddrPnClusterReqExt(Channel,Index)                   (&CanNm_GetPnClusterReqExt(Channel,Index))
#define CanNm_GetPnEraRxPduId(Index)                        (CanNm_ChannelConfig[(Index)].PnEraRxPduId)

#define CanNm_IsPnMessageFilterEnabled(Index)               (CanNm_PnMessageFilterEnabled[(Index)])
#define CanNm_IsPnMessageFilterDeactived(Index)             (CanNm_PnMessageFilterDeactived[(Index)])

#define CanNm_IsRepeatMsgBitIndFlag(Index)                  (CanNm_RepeatMsgBitIndFlag[(Index)])
#define CanNm_IsRepeatMsgReqFlag(Index)                     (CanNm_RepeatMsgReqFlag[(Index)])
#define CanNm_GetRepeatMsgTimer(Index)                      (CanNm_RepeatMsgTimer[(Index)])
#define CanNm_GetRxMessageData(Channel, Index)              (CanNm_RxMessageData[(Channel)][(Index)])
#define CanNm_GetSysToNmChInd(Index)                        (CanNm_SysToNmChInd[(Index)])
#define CanNm_GetTimeoutTimer(Index)                        (CanNm_TimeoutTimer[(Index)])
#define CanNm_GetTxControlState(Index)                      (CanNm_TxControlState[(Index)])
#define CanNm_GetTxControlStateRequest(Index)               (CanNm_TxControlStateRequest[(Index)])
#define CanNm_GetTxMessageData(Channel, Index)              (CanNm_TxMessageData[(Channel)][(Index)])
#define CanNm_GetWaitBusSleepTimer(Index)                   (CanNm_WaitBusSleepTimer[(Index)])
#define CanNm_GetChToRxPduIdSize(Index)                     (CanNm_ChToRxPduId[(Index)].Size)
#define CanNm_GetChToRxPduId(Channel, Index)                (CanNm_ChToRxPduId[(Channel)].RxPduId[Index])
#define CanNm_GetTxMessageData_UDStartIdx(Index)            (CanNm_PbChannelConfig[(Index)].TxMsgData_UserDataStartIdx)
#define CanNm_GetTxMessageData_UDLength(Index)              (CanNm_PbChannelConfig[(Index)].TxMsgData_UserDataLength)
#define CanNm_GetTxUserDataPduId(Index)                     (CanNm_PbChannelConfig[(Index)].TxUserDataPduId)
#define CanNm_GetRemoteSleepTimer(Index)                    (CanNm_RemoteSleepTimer[(Index)])
#define CanNm_GetMsgReduceTime(Index)                       (CanNm_ChannelConfig[(Index)].MsgReducedTime)
#define CanNm_GetRemoteSleepIndState(Index)                 (CanNm_RemoteSleepState[(Index)])
#define CanNm_IsImmediateRestartFailed(Index)               (CanNm_ImmediateRestartFailed[(Index)])
#define CanNm_IsBusLoadReductionActive(Index)               (CanNm_BusLoadReductionActive[(Index)])
#define CanNm_IsActiveWakeupBitEnable(Index)                (CanNm_ChannelConfig[(Index)].ActiveWakeupBitEnabled)
#define CanNm_IsRemoteSleepIndState(Index)                  (CanNm_RemoteSleepState[(Index)])
#define CanNm_IsRetryFirstMessageRequestFlag(Index)         (CanNm_RetryFirstMessageRequestFlag[(Index)])
#define CanNm_GetRetryFirstMessageRequestEnabled(Index)     (CanNm_ChannelConfig[(Index)].RetryFirstMessageRequestEnabled)
#define CanNm_GetEraPnInfo(Index)                           (CanNm_PbChannelConfig[(Index)].PnInfo)
#define CanNm_GetEraPnInfoLength(Index)                     (CanNm_PbChannelConfig[(Index)].PnInfo->CanNmPnInfoLength)
#define CanNm_GetEraPnInfoOffset(Index)                     (CanNm_PbChannelConfig[(Index)].PnInfo->CanNmPnInfoOffset)
#define CanNm_GetEraPnFilterMask(Index)                     (CanNm_PbChannelConfig[(Index)].PnInfo->CanNmPnFilterMaskByte)

/*  These macros can be used to write data.*/
#define CanNm_SetCommState(Index, Value)                    CanNm_CommState[(Index)] = (Value)
#define CanNm_SetCoordReadyToSleepState(Index, Value)       CanNm_CoordReadyToSleepState[(Index)] = (Value)
#define CanNm_SetImmediateNmMsgCount(Index, Value)          CanNm_ImmediateNmMsgCount[(Index)] = (Value)
#define CanNm_SetMsgConfirmationFlag(Index, Value)          CanNm_MsgConfirmationFlag[(Index)] = (Value)
#define CanNm_SetMsgIndicationFlag(Index, Value)            CanNm_MsgIndicationFlag[(Index)] = (Value)
#define CanNm_SetMsgRequest(Index, Value)                   CanNm_MsgRequest[(Index)] = (Value)
#define CanNm_SetMsgTimeoutTimer(Index, Value)              CanNm_MsgTimeoutTimer[(Index)] = (Value)
#define CanNm_SetMsgTimer(Index, Value)                     CanNm_MsgTimer[(Index)] = (Value)
#define CanNm_SetNetworkRestartFlag(Index, Value)           CanNm_NetworkRestartFlag[(Index)] = (Value)
#define CanNm_SetPnClusterReq(Index, Value)                 CanNm_PnClusterReq[(Index)] = (Value)
#define CanNm_SetPnClusterReqNew(Index, Value)              CanNm_PnClusterReqNew[(Index)] = (Value)
#define CanNm_SetPnClusterResetTimer(Index, Value)          CanNm_PnClusterResetTimer[(Index)] = (Value)
#define CanNm_SetPnMessageFilterEnabled(Index, Value)       CanNm_PnMessageFilterEnabled[(Index)] = (Value)
#define CanNm_SetPnMessageFilterDeactived(Index, Value)     CanNm_PnMessageFilterDeactived[(Index)] = (Value)

#define CanNm_SetPnClusterReqExtNew(Channel,Index, Value)             CanNm_PnClusterReqExtNew[(Channel)][(Index)] = (Value)
#define CanNm_SetPnClusterReqExt(Channel,Index, Value)                CanNm_PnClusterReqExt[(Channel)] [(Index)] = (Value)

#define CanNm_SetRepeatMsgBitIndFlag(Index, Value)          CanNm_RepeatMsgBitIndFlag[(Index)] = (Value)
#define CanNm_SetRepeatMsgReqFlag(Index, Value)             CanNm_RepeatMsgReqFlag[(Index)] = (Value)
#define CanNm_SetRepeatMsgTimer(Index, Value)               CanNm_RepeatMsgTimer[(Index)] = (Value)
#define CanNm_SetRxMessageData(Channel, Index, Value)       CanNm_RxMessageData[(Channel)][(Index)] = (Value)
#define CanNm_SetTimeoutTimer(Index, Value)                 CanNm_TimeoutTimer[(Index)] = (Value)
#define CanNm_SetTxControlState(Index, Value)               CanNm_TxControlState[(Index)] = (Value)
#define CanNm_SetTxControlStateRequest(Index, Value)        CanNm_TxControlStateRequest[(Index)] = (Value)
#define CanNm_SetTxMessageData(Channel, Index, Value)       CanNm_TxMessageData[(Channel)][(Index)] = (Value)
#define CanNm_SetWaitBusSleepTimer(Index, Value)            CanNm_WaitBusSleepTimer[(Index)] = (Value)
#define CanNm_SetImmediateRestartFailed(Index, Value)       CanNm_ImmediateRestartFailed[(Index)] = (Value)
#define CanNm_SetBusLoadReductionActive(Index, Value)       CanNm_BusLoadReductionActive[(Index)] = (Value)
#define CanNm_SetRemoteSleepTimer(Index, Value)             CanNm_RemoteSleepTimer[(Index)] = (Value)
#define CanNm_SetRemoteSleepIndState(Index, Value)          CanNm_RemoteSleepState[(Index)] = (Value)
#define CanNm_SetRetryFirstMessageRequestFlag(Index, Value) CanNm_RetryFirstMessageRequestFlag[(Index)] = (Value)

/*  These macros can be used to get the data by the address operator. */
#define CanNm_GetAddrPnClusterReq(Index)                    &CanNm_GetPnClusterReq(Index)
#define CanNm_GetAddrPnClusterReqNew(Index)                 &CanNm_GetPnClusterReqNew(Index)
#define CanNm_GetAddrRxMessageData(Channel,Index)           &CanNm_GetRxMessageData(Channel,Index)
#define CanNm_GetAddrTxMessageData(Channel,Index)           &CanNm_GetTxMessageData(Channel,Index)

/*These macros can be used to increment VAR data with numerical nature. */
#define CanNm_IncCommState(Index)                           CanNm_GetCommState(Index)++
#define CanNm_IncCoordReadyToSleepState(Index)              CanNm_GetCoordReadyToSleepState(Index)++
#define CanNm_IncImmediateNmMsgCount(Index)                 CanNm_GetImmediateNmMsgCount(Index)++
#define CanNm_IncMsgRequest(Index)                          CanNm_GetMsgRequest(Index)++
#define CanNm_IncMsgTimeoutTimer(Index)                     CanNm_GetMsgTimeoutTimer(Index)++
#define CanNm_IncMsgTimer(Index)                            CanNm_GetMsgTimer(Index)++
#define CanNm_IncNetworkRestartFlag(Index)                  CanNm_GetNetworkRestartFlag(Index)++
#define CanNm_IncPnClusterReq(Index)                        CanNm_GetPnClusterReq(Index)++
#define CanNm_IncPnClusterReqNew(Index)                     CanNm_GetPnClusterReqNew(Index)++
#define CanNm_IncPnClusterResetTimer(Index)                 CanNm_GetPnClusterResetTimer(Index)++
#define CanNm_IncRepeatMsgTimer(Index)                      CanNm_GetRepeatMsgTimer(Index)++
#define CanNm_IncRxMessageData(Channel,Index)               CanNm_GetRxMessageData(Channel,Index)++
#define CanNm_IncTimeoutTimer(Index)                        CanNm_GetTimeoutTimer(Index)++
#define CanNm_IncTxControlState(Index)                      CanNm_GetTxControlState(Index)++
#define CanNm_IncTxControlStateRequest(Index)               CanNm_GetTxControlStateRequest(Index)++
#define CanNm_IncTxMessageData(Channel,Index)               CanNm_GetTxMessageData(Channel,Index)++
#define CanNm_IncWaitBusSleepTimer(Index)                   CanNm_GetWaitBusSleepTimer(Index)++
#define CanNm_IncRemoteSleepTimer(Index)                    CanNm_GetRemoteSleepTimer(Index)++

/*  These macros can be used to decrement VAR data with numerical nature. */
#define CanNm_DecCommState(Index)                           CanNm_GetCommState(Index)--
#define CanNm_DecCoordReadyToSleepState(Index)              CanNm_GetCoordReadyToSleepState(Index)--
#define CanNm_DecImmediateNmMsgCount(Index)                 CanNm_GetImmediateNmMsgCount(Index)--
#define CanNm_DecMsgRequest(Index)                          CanNm_GetMsgRequest(Index)--
#define CanNm_DecMsgTimeoutTimer(Index)                     CanNm_GetMsgTimeoutTimer(Index)--
#define CanNm_DecMsgTimer(Index)                            CanNm_GetMsgTimer(Index)--
#define CanNm_DecNetworkRestartFlag(Index)                  CanNm_GetNetworkRestartFlag(Index)--
#define CanNm_DecPnClusterReq(Index)                        CanNm_GetPnClusterReq(Index)--
#define CanNm_DecPnClusterReqNew(Index)                     CanNm_GetPnClusterReqNew(Index)--
#define CanNm_DecPnClusterResetTimer(Index)                 CanNm_GetPnClusterResetTimer(Index)--
#define CanNm_DecRepeatMsgTimer(Index)                      CanNm_GetRepeatMsgTimer(Index)--
#define CanNm_DecRxMessageData(Index)                       CanNm_GetRxMessageData(Index)--
#define CanNm_DecTimeoutTimer(Index)                        CanNm_GetTimeoutTimer(Index)--
#define CanNm_DecTxControlState(Index)                      CanNm_GetTxControlState(Index)--
#define CanNm_DecTxControlStateRequest(Index)               CanNm_GetTxControlStateRequest(Index)--
#define CanNm_DecTxMessageData(Channel, Index)              CanNm_GetTxMessageData(Channel, Index)--
#define CanNm_DecWaitBusSleepTimer(Index)                   CanNm_GetWaitBusSleepTimer(Index)--
#define CanNm_DecRemoteSleepTimer(Index)                    CanNm_GetRemoteSleepTimer(Index)--

#define CanNm_GetNmState(Index)				CanNm_NmState[(Index)]
#define CanNm_SetNmState(Index, Value)		CanNm_NmState[(Index)] = (Value)
/* polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_CanNm_2.4" */
typedef struct sCanNm_PnInfoType
{
    uint8 CanNmPnInfoLength;  /* Specifies the length of the PN request information in the NM PDU */
    uint8 CanNmPnInfoOffset;  /* Specifies the offset of the PN request information in the NM PDU */
    const uint8* CanNmPnFilterMaskByte;/* Pn Filter Mask */
} CanNm_PnInfoType;

typedef uint16 CanNm_PnClusterResetTimerType[CANNM_PN_CLUSTERS_PER_BYTE];

/* type used in CanNm_ChannelConfig */
/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_CanNm_2.4" */
typedef struct sCanNm_ChannelConfigType
{
    uint16 TimeoutTime;					/* Timeout for the NM messages [ms]. */
    uint16 WaitBusSleepTime;			/* Timeout for bus calm down phase [ms]. */
    boolean NodeDetectionEnabled; 		/* Determines if Node Detection feature is active or not */
    boolean NodeIdEnabled;				/* Determines if Node Ids are enabled or not */
    boolean PnCallTxTimeoutException;	/* Determines whether CanSM_TxTimeoutException has to be called */
    uint8 ChannelId;					/* Channel ID configured for the respective instance of the NM. */
    uint16 ImmediateNmCycleTime;		/* Fast NM PDU Transmission Time during WUP */
    uint8 ImmediateNmTransmissions;		/* Number of fast NM PDU Transmissions during WUP */
    uint16 MsgCycleTime;				/* Period of a NM message [ms]. It determines the 
										   periodic rate in the periodic transmission mode. */
    uint16 MsgTimeoutTime;				/* Transmission Timeout [ms] of NM message. If there is
										   no transmission confirmation by the CAN Interface 
										   within this timeout, the CAN NM module shall give an
										   error notification. */
    uint8 PduCbvPosition;				/* Control Bit Vector Position in the PDU */
    uint8 PduNidPosition;				/* Node ID Position in the PDU */
    uint16 RemoteSleepIndTime;			/* Timeout for Remote Sleep Indication [ms]. */
    uint16 RepeatMessageTime;			/* Timeout for Repeat Message State [ms]. */

    boolean PnEraCalcEnabled;
    PduIdType PnEraRxPduId;
    boolean ActiveWakeupBitEnabled;
    boolean AllMessagesKeepAwakeEnabled;
    boolean BusLoadReductionActive;
    uint16 MsgReducedTime;
    uint8 CarWakeUpBitMask;
    uint8 CarWakeUpBytePosition;
    uint8 CarWakeUpFilterNodeId;
    boolean CarWakeUpRxEnabled;
    boolean CarWakeUpFilterEnabled;
    boolean RetryFirstMessageRequestEnabled;
} CanNm_ConfigType;
/* type used in CanNm_PbChannelConfig */
/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_CanNm_2.4" */
typedef struct sCanNm_PbChannelConfigType
{
    boolean PnEnabled;
    boolean PnHandleMultipleNetworkRequest;
    uint8 MsgCycleOffset;
    uint8 NodeId;
    uint8 PnClusterReqExtEndIdx;			/* the end index of the 0:n relation pointing to CanNm_PnClusterReqExt */
    uint8 PnClusterReqExtLength;			/* the number of relations pointing to CanNm_PnClusterReqExt */
    uint8 PnClusterReqExtStartIdx;			/* the start index of the 0:n relation pointing to CanNm_PnClusterReqExt */
    uint8 PnClusterResetTimerExtEndIdx;		/* the end index of the 0:n relation pointing to CanNm_PnClusterResetTimerExt */
    uint8 PnClusterResetTimerExtLength;		/* the number of relations pointing to CanNm_PnClusterResetTimerExt */
    uint8 PnClusterResetTimerExtStartIdx;	/* the start index of the 0:n relation pointing to CanNm_PnClusterResetTimerExt */
    uint8 RxMsgDataEndIdx;					/* the end index of the 0:n relation pointing to CanNm_RxMessageData */
    uint8 RxMsgDataLength;					/* the number of relations pointing to CanNm_RxMessageData */
    uint8 RxMsgDataStartIdx;				/* the start index of the 0:n relation pointing to CanNm_RxMessageData */
    uint8 RxMsgData_CBVIdx;					/* the index of the 0:1 relation pointing to CanNm_RxMessageData */
    uint8 RxMsgData_NIDIdx;					/* the index of the 0:1 relation pointing to CanNm_RxMessageData */
    uint8 RxMsgData_UserDataEndIdx;			/* the end index of the 0:n relation pointing to CanNm_RxMessageData */
    uint8 RxMsgData_UserDataLength;			/* the number of relations pointing to CanNm_RxMessageData */
    uint8 RxMsgData_UserDataStartIdx;		/* the start index of the 0:n relation pointing to CanNm_RxMessageData */
    uint8 TxMsgDataEndIdx;					/* the end index of the 0:n relation pointing to CanNm_TxMessageData */
    uint8 TxMsgDataLength;					/* the number of relations pointing to CanNm_TxMessageData */
    uint8 TxMsgDataStartIdx;				/* the start index of the 0:n relation pointing to CanNm_TxMessageData */
    uint8 TxMsgData_CBVIdx;					/* the index of the 0:1 relation pointing to CanNm_TxMessageData */
    uint8 TxMsgData_NIDIdx;					/* the index of the 0:1 relation pointing to CanNm_TxMessageData */
    uint8 TxMsgData_PnFilterMaskEndIdx;		/* the end index of the 0:n relation pointing to CanNm_TxMessageData */
    uint8 TxMsgData_PnFilterMaskStartIdx;	/* the start index of the 0:n relation pointing to CanNm_TxMessageData */
    uint8 TxMsgData_UserDataEndIdx;			/* the end index of the 0:n relation pointing to CanNm_TxMessageData */
    uint8 TxMsgData_UserDataLength;			/* the number of relations pointing to CanNm_TxMessageData */
    uint8 TxMsgData_UserDataStartIdx;		/* the start index of the 0:n relation pointing to CanNm_TxMessageData */
    PduIdType TxPduId;
    PduIdType TxPduRef;
    PduIdType TxUserDataPduId;
    const CanNm_PnInfoType* PnInfo;
} CanNm_PbChannelConfigType;

/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_CanNm_2.4" */
typedef struct sCanNm_ChannelToRxPduIdType
{
    uint8 Size;
    PduIdType RxPduId[CANNM_MAX_NUM_RXPDUID_PER_CHANNEL];
} CanNm_ChannelToRxPduId;
/* These type definitions are used for value representations in root arrays.*/
/* PolySpace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_CanNm_2.4" */
typedef struct sCanNm_PCConfigType
{
    uint8 CanNm_PCConfigNeverUsed;  /* dummy entry for the structure in the configuration 
										variant precompile which is not used by the code. */
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} CanNm_PCConfigType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define CANNM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern VAR(Nm_StateType, CANNM_VAR_INIT) CanNm_NmState[CANNM_NUMBER_OF_CANNM_CHANNELS];

#define CANNM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define CANNM_START_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_CommState[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_CoordReadyToSleepState[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_ImmediateNmMsgCount[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_MsgConfirmationFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_MsgIndicationFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_MsgRequest[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint16, CANNM_VAR_NO_INIT) CanNm_MsgTimeoutTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint16, CANNM_VAR_NO_INIT) CanNm_MsgTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_NetworkRestartFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_PnClusterReq[CANNM_PN_INFO_LENGTH + 1U];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_PnClusterReqNew[CANNM_PN_INFO_LENGTH + 1U];
extern VAR(CanNm_PnClusterResetTimerType, CANNM_VAR_NO_INIT) CanNm_PnClusterResetTimer[CANNM_PN_INFO_LENGTH + 1U];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_PnMessageFilterEnabled[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_PnMessageFilterDeactived[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_RepeatMsgBitIndFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_RepeatMsgReqFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint16, CANNM_VAR_NO_INIT) CanNm_RepeatMsgTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
/* Polyspace +1 DEFECT:HARD_CODED_BUFFER_SIZE [JUstified:Unset] "NSCA_Polyspace_CanNm_DATA_RACE_ALL" */
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_RxMessageData[CANNM_NUMBER_OF_CANNM_CHANNELS][8U];
extern VAR(uint16, CANNM_VAR_NO_INIT) CanNm_TimeoutTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_TxControlState[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_TxControlStateRequest[CANNM_NUMBER_OF_CANNM_CHANNELS];
/* Polyspace +1 DEFECT:HARD_CODED_BUFFER_SIZE [JUstified:Unset] "NSCA_Polyspace_CanNm_DATA_RACE_ALL" */
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_TxMessageData[CANNM_NUMBER_OF_CANNM_CHANNELS][8U];
extern VAR(uint16, CANNM_VAR_NO_INIT) CanNm_WaitBusSleepTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_ImmediateRestartFailed[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_BusLoadReductionActive[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint16, CANNM_VAR_NO_INIT)  CanNm_RemoteSleepTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_RemoteSleepState[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_PnClusterReqExt[CANNM_NUMBER_OF_CANNM_CHANNELS][CANNM_PN_INFO_LENGTH + 1U];
extern VAR(uint8, CANNM_VAR_NO_INIT) CanNm_PnClusterReqExtNew[CANNM_NUMBER_OF_CANNM_CHANNELS][CANNM_PN_INFO_LENGTH + 1U];
extern VAR(CanNm_PnClusterResetTimerType, CANNM_VAR_NO_INIT) CanNm_PnClusterResetTimerExt[CANNM_NUMBER_OF_CANNM_CHANNELS][CANNM_PN_INFO_LENGTH + 1U];
extern VAR(boolean, CANNM_VAR_NO_INIT) CanNm_RetryFirstMessageRequestFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];

#define CANNM_STOP_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define CANNM_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

extern CONST(CanNm_ConfigType, CANNM_CONFIG_DATA) CanNm_ChannelConfig[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern CONST(CanNm_PbChannelConfigType, CANNM_CONFIG_DATA) CanNm_PbChannelConfig[CANNM_NUMBER_OF_CANNM_CHANNELS];
extern CONST(uint8, CANNM_CONFIG_DATA) CanNm_PnFilterMask[CANNM_PN_INFO_LENGTH + 1U];
extern CONST(uint8, CANNM_CONFIG_DATA) CanNm_SysToNmChInd[CANNM_MAX_NUMBER_OF_COMM_CHANNELS];
extern CONST(CanNm_ChannelToRxPduId, CANNM_CONFIG_DATA) CanNm_ChToRxPduId[CANNM_NUMBER_OF_CANNM_CHANNELS];

#define CANNM_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* CANNN_CFG_H_ */

