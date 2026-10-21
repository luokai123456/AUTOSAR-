/*
*******************************************************************************
*                                                                              
* File name: CanNm_Cfg.c                                                               
*                                                                              
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.                
*                                                                              
*******************************************************************************
*                                                                              
* History                                                                      
*------------------------------------------------------------------------------
*******************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2018.12.13
* Change: New created.
* Cause: New
*******************************************************************************
* Version: 1.1
* Author/Date : jiafeng/2019.12.27
* Change: add elements in structure.
* Cause: Optimization
*******************************************************************************
* Version: 1.2
* Author/Date : jia_feng/2020.01.16
* Change: Optimize the configuration of CanNm ,delete some extra configurations.
* Cause: Optimization
********************************************************************************
* Version: 3.0
* Author/Date : jia_feng/2020.04.20
* Change: Add the configuration of BusLoadReductionActive in CanNm_ChannelConfig[].
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date : jia_feng/2020.05.09
* Change: Optimize variable definition.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date : jia_feng/2020.06.17
* Change: Add Tx Rx message buffer for every channel(CanNm_TxMessageData,
*         CanNm_RxMessageData).
* Cause: Bugfix.
********************************************************************************
*/
/*
*******************************************************************************
*    Include
*******************************************************************************
*/
#include "CanNm_Cfg.h"

/*
*******************************************************************************
*    Local Macros
*******************************************************************************
*/
/*
*******************************************************************************
*    Local Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Local Variables
*******************************************************************************
*/
/*
*******************************************************************************
*    Local Constants
*******************************************************************************
*/
/*
*******************************************************************************
*    Local Functions
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Variable
*******************************************************************************
*/
#define CANNM_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
VAR(Nm_StateType, CANNM_VAR_INIT) CanNm_NmState[CANNM_NUMBER_OF_CANNM_CHANNELS] =
{

	NM_STATE_UNINIT,

	NM_STATE_UNINIT,

};

#define CANNM_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#define CANNM_START_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* polyspace-begin VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_CommState[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_CoordReadyToSleepState[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_ImmediateNmMsgCount[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_MsgConfirmationFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_MsgIndicationFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_MsgRequest[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint16, CANNM_VAR_NO_INIT) CanNm_MsgTimeoutTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint16, CANNM_VAR_NO_INIT) CanNm_MsgTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_NetworkRestartFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_PnClusterReq[CANNM_PN_INFO_LENGTH + 1U];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_PnClusterReqNew[CANNM_PN_INFO_LENGTH + 1U];
VAR(CanNm_PnClusterResetTimerType, CANNM_VAR_NO_INIT) CanNm_PnClusterResetTimer[CANNM_PN_INFO_LENGTH + 1U];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_PnMessageFilterEnabled[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_PnMessageFilterDeactived[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_RepeatMsgBitIndFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_RepeatMsgReqFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint16, CANNM_VAR_NO_INIT) CanNm_RepeatMsgTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_RxMessageData[CANNM_NUMBER_OF_CANNM_CHANNELS][8U];
VAR(uint16, CANNM_VAR_NO_INIT) CanNm_TimeoutTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_TxControlState[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_TxControlStateRequest[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_TxMessageData[CANNM_NUMBER_OF_CANNM_CHANNELS][8U];
VAR(uint16, CANNM_VAR_NO_INIT) CanNm_WaitBusSleepTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_ImmediateRestartFailed[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_BusLoadReductionActive[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint16, CANNM_VAR_NO_INIT)  CanNm_RemoteSleepTimer[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_RemoteSleepState[CANNM_NUMBER_OF_CANNM_CHANNELS];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_PnClusterReqExt[CANNM_NUMBER_OF_CANNM_CHANNELS][CANNM_PN_INFO_LENGTH + 1U];
VAR(uint8, CANNM_VAR_NO_INIT) CanNm_PnClusterReqExtNew[CANNM_NUMBER_OF_CANNM_CHANNELS][CANNM_PN_INFO_LENGTH + 1U];
VAR(CanNm_PnClusterResetTimerType, CANNM_VAR_NO_INIT) CanNm_PnClusterResetTimerExt[CANNM_NUMBER_OF_CANNM_CHANNELS][CANNM_PN_INFO_LENGTH + 1U];
VAR(boolean, CANNM_VAR_NO_INIT) CanNm_RetryFirstMessageRequestFlag[CANNM_NUMBER_OF_CANNM_CHANNELS];
/* polyspace-end VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */

#define CANNM_STOP_SEC_VAR_NO_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define CANNM_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/* PolySpace +3 MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_CanNm_8.4" */
/* PolySpace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_CanNm_8.7" */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
CONST(uint8, CANNM_CONFIG_DATA) N72PMS_PT_CANFD_20260228__XQc0BPnFilterMask[CANNM_PN_INFO_LENGTH + 1] =  /* PRQA S 3408,1840 */ /* NSCA_QAC_CanNm_Rule8.4,NSCA_QAC_CanNm_Rule10.4  */
{
    0U
};
/* PolySpace +3 MISRA-C3:8.4 [Justified:Unset] "NSCA_Polyspace_CanNm_8.4" */
/* PolySpace +2 MISRA-C3:8.7 [Justified:Unset] "NSCA_Polyspace_CanNm_8.7" */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
CONST(uint8, CANNM_CONFIG_DATA) PMS_EV_CAN_20260126_RMXr12PnFilterMask[CANNM_PN_INFO_LENGTH + 1] =  /* PRQA S 3408,1840 */ /* NSCA_QAC_CanNm_Rule8.4,NSCA_QAC_CanNm_Rule10.4  */
{
    0U
};

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
CONST(CanNm_ConfigType, CANNM_CONFIG_DATA) CanNm_ChannelConfig[CANNM_NUMBER_OF_CANNM_CHANNELS] = {
	{
		380U,                                              /* TimeoutTime */
		401U,                                              /* WaitBusSleepTime*/
		(TRUE),                                            /* NodeDetectionEnabled*/
		(TRUE),                                            /* NodeIdEnabled*/
		TRUE,                                              /* PnCallTxTimeoutException*/
		6U,                                                /* ChannelId*/
		4U,                                                /* ImmediateNmCycleTime*/
		10U,                                               /* ImmediateNmTransmissions*/
		100U,                                              /* MsgCycleTime*/
		16U,                                               /* MsgTimeoutTime*/
		CANNM_PDU_BYTE_1,                                  /* PduCbvPosition */
		CANNM_PDU_BYTE_0,                                  /* PduNidPosition*/
		380U,                                              /* RemoteSleepIndTime*/
		320U,                                              /* RepeatMessageTime*/
		(FALSE),                                           /* PnEraCalcEnabled*/
		0xFFFFU,                                           /* PnEraRxPduId*/
		(TRUE),                                            /* ActiveWakeupBitEnabled*/
		(FALSE),                                           /* AllMessagesKeepAwakeEnabled*/
		(FALSE),                                           /* BusLoadReductionActive*/
		56U,                                               /* MsgReducedTime*/
		0U,                                                /* CarWakeUpBitMask*/
		255U,                                              /* CarWakeUpBytePosition*/
		0U,                                                /* CarWakeUpFilterNodeId*/
		(FALSE),                                           /* CarWakeUpRxEnabled*/
		(FALSE),                                           /* CarWakeUpFilterEnabled*/
		(TRUE),                                            /* RetryFirstMessageRequestEnabled*/
	},
	{
		380U,                                              /* TimeoutTime */
		401U,                                              /* WaitBusSleepTime*/
		(TRUE),                                            /* NodeDetectionEnabled*/
		(TRUE),                                            /* NodeIdEnabled*/
		TRUE,                                              /* PnCallTxTimeoutException*/
		2U,                                                /* ChannelId*/
		4U,                                                /* ImmediateNmCycleTime*/
		10U,                                               /* ImmediateNmTransmissions*/
		100U,                                              /* MsgCycleTime*/
		16U,                                               /* MsgTimeoutTime*/
		CANNM_PDU_BYTE_1,                                  /* PduCbvPosition */
		CANNM_PDU_BYTE_0,                                  /* PduNidPosition*/
		380U,                                              /* RemoteSleepIndTime*/
		320U,                                              /* RepeatMessageTime*/
		(FALSE),                                           /* PnEraCalcEnabled*/
		0xFFFFU,                                           /* PnEraRxPduId*/
		(TRUE),                                            /* ActiveWakeupBitEnabled*/
		(FALSE),                                           /* AllMessagesKeepAwakeEnabled*/
		(FALSE),                                           /* BusLoadReductionActive*/
		56U,                                               /* MsgReducedTime*/
		0U,                                                /* CarWakeUpBitMask*/
		255U,                                              /* CarWakeUpBytePosition*/
		0U,                                                /* CarWakeUpFilterNodeId*/
		(FALSE),                                           /* CarWakeUpRxEnabled*/
		(FALSE),                                           /* CarWakeUpFilterEnabled*/
		(TRUE),                                            /* RetryFirstMessageRequestEnabled*/
	},
};

/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
CONST(CanNm_PbChannelConfigType, CANNM_CONFIG_DATA) CanNm_PbChannelConfig[CANNM_NUMBER_OF_CANNM_CHANNELS] = {
	{
		(FALSE),                                           /* PnEnabled */
		(FALSE),                                           /* PnHandleMultipleNetworkRequest */
		0U,                                                /* MsgCycleOffset */
		39U,                                               /* NodeId */
		0U,                                                /* PnClusterReqExtEndIdx */
		0U,                                                /* PnClusterReqExtLength */
		0U,                                                /* PnClusterReqExtStartIdx */
		0U,                                                /* PnClusterResetTimerExtEndIdx */
		0U,                                                /* PnClusterResetTimerExtLength */
		0U,                                                /* PnClusterResetTimerExtStartIdx */
		8U,                                                /* RxMessageDataEndIdx */
		8U,                                                /* RxMessageDataLength */
		0U,                                                /* RxMessageDataStartIdx */
		CANNM_PDU_BYTE_1,                                  /* RxMessageData_CBVIdx */
		CANNM_PDU_BYTE_0,                                  /* RxMessageData_NIDIdx */
		8U,                                                /* RxMessageData_UserDataEndIdx */
		6U,                                                /* RxMessageData_UserDataLength */
		2U,                                                /* RxMessageData_UserDataStartIdx */
		8U,                                                /* TxMessageDataEndIdx */
		8U,                                                /* TxMessageDataLength */
		0U,                                                /* TxMessageDataStartIdx */
		CANNM_PDU_BYTE_1,                                  /* TxMessageData_CBVIdx */
		CANNM_PDU_BYTE_0,                                  /* TxMessageData_NIDIdx */
		2U,                                                /* TxMessageData_PnFilterMaskEndIdx */
		2U,                                                /* TxMessageData_PnFilterMaskStartIdx */
		8U,                                                /* TxMessageData_UserDataEndIdx */
		6U,                                                /* TxMessageData_UserDataLength */
		2U,                                                /* TxMessageData_UserDataStartIdx */
		1U,                                                /* TxPduId*/
		176U,                                              /* TxPduRef*/
		311U,                                              /* TxUserDataPduId  */
		NULL_PTR                                           /* PnInfo */
	},
	{
		(FALSE),                                           /* PnEnabled */
		(FALSE),                                           /* PnHandleMultipleNetworkRequest */
		0U,                                                /* MsgCycleOffset */
		35U,                                               /* NodeId */
		0U,                                                /* PnClusterReqExtEndIdx */
		0U,                                                /* PnClusterReqExtLength */
		0U,                                                /* PnClusterReqExtStartIdx */
		0U,                                                /* PnClusterResetTimerExtEndIdx */
		0U,                                                /* PnClusterResetTimerExtLength */
		0U,                                                /* PnClusterResetTimerExtStartIdx */
		8U,                                                /* RxMessageDataEndIdx */
		8U,                                                /* RxMessageDataLength */
		0U,                                                /* RxMessageDataStartIdx */
		CANNM_PDU_BYTE_1,                                  /* RxMessageData_CBVIdx */
		CANNM_PDU_BYTE_0,                                  /* RxMessageData_NIDIdx */
		8U,                                                /* RxMessageData_UserDataEndIdx */
		6U,                                                /* RxMessageData_UserDataLength */
		2U,                                                /* RxMessageData_UserDataStartIdx */
		8U,                                                /* TxMessageDataEndIdx */
		8U,                                                /* TxMessageDataLength */
		0U,                                                /* TxMessageDataStartIdx */
		CANNM_PDU_BYTE_1,                                  /* TxMessageData_CBVIdx */
		CANNM_PDU_BYTE_0,                                  /* TxMessageData_NIDIdx */
		2U,                                                /* TxMessageData_PnFilterMaskEndIdx */
		2U,                                                /* TxMessageData_PnFilterMaskStartIdx */
		8U,                                                /* TxMessageData_UserDataEndIdx */
		6U,                                                /* TxMessageData_UserDataLength */
		2U,                                                /* TxMessageData_UserDataStartIdx */
		0U,                                                /* TxPduId*/
		94U,                                               /* TxPduRef*/
		312U,                                              /* TxUserDataPduId  */
		NULL_PTR                                           /* PnInfo */
	},
};



/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
CONST(uint8, CANNM_CONFIG_DATA) CanNm_SysToNmChInd[CANNM_MAX_NUMBER_OF_COMM_CHANNELS] = {
	CANNM_NO_SYSTONMCHIND,
	CANNM_NO_SYSTONMCHIND,
	1U,
	CANNM_NO_SYSTONMCHIND,
	CANNM_NO_SYSTONMCHIND,
	CANNM_NO_SYSTONMCHIND,
	0U,
};
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_GlobalVariables" */
CONST(CanNm_ChannelToRxPduId, CANNM_CONFIG_DATA) CanNm_ChToRxPduId[CANNM_NUMBER_OF_CANNM_CHANNELS] = {
	{1, {78,} },  /* PRQA S 686 */ /* NSCA_QAC_CanNm_Rule9.3 */
	{2, {11,19,} },  /* PRQA S 686 */ /* NSCA_QAC_CanNm_Rule9.3 */
};


#define CANNM_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

