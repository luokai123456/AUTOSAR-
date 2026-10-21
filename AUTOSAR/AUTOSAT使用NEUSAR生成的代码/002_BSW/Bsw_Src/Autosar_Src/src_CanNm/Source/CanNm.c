/*
********************************************************************************
*
* File name: CanNm.c
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2018.12.13
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: yong.zhang/2019.06.08
* Change: Modify QAC Check Warning.
* Cause: Revision
********************************************************************************
* Version: 1.2
* Author/Date: yong.zhang/2019.11.12
* Change: Standardize code style.
* Cause: Optimization
********************************************************************************
* Version: 1.3
* Author/Date: jia_feng/2019.12.24
* Change: Add unimplemented features.
* Cause: Optimization
********************************************************************************
* Version: 1.4
* Author/Date: jia_feng/2020.01.16
* Change: Test the code and modify some bugs.
* Cause: Optimization
********************************************************************************
* Version: 1.5
* Author/Date: jia_feng/2020.02.17
* Change: Modify some bugs and standardize code style.
*         details: CanNm_EnableCommunication: CanNm_GetTxControlState(nmChannelHandle)
*                                                  -> CanNm_GetTxControlState(channel)
*                  CanNm_RequestBusSynchronization: add macro definition judgement.
*                                                   CANNM_PASSIVE_MODE_ENABLED == STD_OFF
*                                                   "=" -> "!="
*                  CanNm_SetSleepReadyBit: "!=" -> "=="
* Cause: Optimization
********************************************************************************
* Version: 1.6
* Author/Date: jia_feng/2020.02.18
* Change: Modify some bugs.
*        details: CanNm_NetworkRequest: Modify judgment conditions of
*                 CanNm_SetNetworkRestartFlag(channel, CANNM_ACTIVE_RESTART)
*                          in CanNm_NetworkRequest()
* Cause: Optimization
********************************************************************************
* Version: 1.7
* Author/Date: jia_feng/2020.02.18
* Change: Modify bugs
*         details: Add ERA caculate in CanNm_PnFilterHandling.
* Cause: Optimization
********************************************************************************
* Version: 1.8
* Author/Date: jia_feng/2020.02.27
* Change: Add judgement of CANNM_E_INVALID_CHANNEL error to all standard functions.
* Cause: Optimization
********************************************************************************
* Version: 1.9
* Author/Date: jiafeng/2020.03.26
* Change: Modify QAC Check Warning.
* Cause: Revision
********************************************************************************
* Version: 3.0
* Author/Date: jiafeng/2020.03.27
* Change: Nothing
* Cause: Update to V3.0
********************************************************************************
* Version: 3.1
* Author/Date: jiafeng/2020.04.20
* Change: Modify a bug(add the judgement of BusLoadReductionActive for each channel).
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: jiafeng/2020.05.18
* Change: Delete codes for A39 (IpduControl).
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: jiafeng/2020.06.19
* Change: Repair PN function,modify CanNm_Transmit.
* Cause: Optimization
********************************************************************************
* Version: 3.4
* Author/Date: jiafeng/2020.06.26
* Change: Modify QAC Check Warning.
* Cause: Revision
********************************************************************************
* Version: 3.5
* Author/Date: jiafeng/2020.07.11
* Change: Modify compile error in (void)CanNm_LeaveCritical() and 
*         (void)CanNm_EnterCritical(), delete the (void).
*
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: jiafeng/2020.07.13
* Change: Add judge of (CANNM_ACTIVE_RESTART == CanNm_GetNetworkRestartFlag(channel)) in 
*             function CanNm_TransitionToNetworkMode.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: jiafeng/2020.07.13
* Change: 1. Add configuration of CANNM_PN_MESSAGE_FILTER_FORCED_ENABLED for the transceiver
*         without PN function.
*         2. Optimize the function of PN message filter.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: guoziyang/2020.10.29
* Change: Modify the code according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: JiaF/2020.12.3
* Change: Modify remote sleep function.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: JiaF/2021.6.4
* Change: Modify errorId about CANNM_E_INVALID_PDUID and CANNM_E_INIT_FAILED, modify
*         initial value of Tx Message to 0xFF.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: JiaF/2021.7.9
* Change: Delete the assignment of nmPduInfo in CanNm_TriggerTransmission reported
*         by PolySpace.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: JiaF/2021.9.1
* Change: Delete the inclusion of the not used file CanNm_MemMap.h, add CANNM_DUMMY_STATEMENT(errorId)
*         in CanNm_GetVersionInfo for compile warning.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: JiaF/2021.9.1
* Change: Modify CanNm_PnEraCalculation for pnc gateway.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: LiX/2023.3.2
* Change: Add the call condition of CanIf_Transmit.
* Cause: Bugfix.
********************************************************************************
* Version: 3.14
* Author/Date: TianG/2023.8.1
* Change: CanNm requires a corresponding PnFilter for each CAN.
* Cause: Optimization
********************************************************************************
* Version: 3.15
* Author/Date: TianG/2023.8.25
* Change: Add CanNm_GetEraPnInfo evaluates to null to CanNm_TriggerTransmission.
* Cause: Optimization
********************************************************************************
* Version: 3.16
* Author/Date: TianG/2023.10.8
* Change: Modifying compile Warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.17
* Author/Date: TianL/2023.10.10
* Change: Modifying Polyspace High Warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.18
* Author/Date: TianL/2023.10.27
* Change: Modifying compile Warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.19
* Author/Date: TianL/2024.2.21
* Change: Modify ERA branch implementation error in CanNm_PnFilterHandling function.
* Cause: Bugfix
********************************************************************************
* Version: 3.20
* Author/Date: TianSL/2024.3.11
* Change: 1.Fix the problem of PduR_CanNmRxIndication definition not found when
*           CanNmPnEiraCalcEnabled or CanNmPnEraCalcEnabled is disabled.
*         2.When CANNM-PN_EIRA-CALC-FEATURE-ENABLED or CANNM-PN_ERA-CALC-FEATURE-ENABLED
*           is enabled, the PduR.CanNm.h header file is also included.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: TianSL/2024.3.18
* Change: Fix compile warning.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: TianSL/2024.4.02
* Change: Modify the label of P2CONST member.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: TianSL/2024.5.20
* Change: Add Memmap segment definition.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: TianSL/2024.7.1
* Change: Modify copyright.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: TianSL/2024.9.30
* Change: Modify the coding specification.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: TianSL/2024.12.02
* Change: Modify the coding specification.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: TianSL/2025.01.09
* Change: Fix Polyspace warning.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: TianSL/2025.03.24
* Change: Fix the QAC warning and add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: TianSL/2025.06.04
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: TianSL/2025.06.23
* Change: Fix the problem that 28 Service  fails to resume after timeout.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanNm.h"                          /* Include CAN Network Management header. */
#include "CanNm_Cbk.h"                      /* Include CAN NM callback header. */
#include "Nm_Cbk.h"                         /* Include NM Interface callback header. */
#include "CanIf.h"                          /* Include CAN Interface header. */
#include "SchM_CanNm.h"                     /* Include Scheduler Module for Critical Sections. */
#include "CanSM_TxTimeoutException.h"       /* CanSM TxTimeoutException Header for CanNm. */
#include "Com.h"
#include "CanNm_Cfg.h"
#include "Nm.h"

#include "ComM.h"//同睡同醒
#include "CAN_NM_Userdata_fill.h"//Userdata填充

#if( (CANNM_COM_USER_DATA_SUPPORT == STD_ON) || (CANNM_PN_EIRA_CALC_FEATURE_ENABLED == STD_ON) \
    || (CANNM_PN_ERA_CALC_FEATURE_ENABLED == STD_ON) )
#include "PduR_CanNm.h"                     /* PduR Callback Header for CanNm. */
#endif

#if( CANNM_DEV_ERROR_DETECT == STD_ON )
#include "Det.h"
#endif

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
/* The application has no communication need and is ready to sleep. */
#define COMM_READY_SLEEP                            ((uint8)0x00U)
/* The application has communication need. */
#define COMM_NORMAL_OPERATION                       ((uint8)0x01U)

/* Enumeration type for Message Transmission Control (optimized). */
/*! Message Transmission Ability is disabled/enabled */
#define MSG_TX_DISABLED                             ((uint8)0x00U)
#define MSG_TX_ENABLED                              ((uint8)0x01U)

/* Mask to check if the Repeat Message Bit is set or reset. */
#define CANNM_REPEAT_MSG_BIT_MASK                   ((uint8)0x01U)
#define CANNM_REPEAT_MSG_BIT_INV_MASK               ((uint8)0xFEU)


/* ! Mask to check if the Active Wakeup Bit is set or reset. */
#define CANNM_ACT_WU_BIT_MASK                       ((uint8)0x10U)
#define CANNM_ACT_WU_BIT_INV_MASK                   ((uint8)0xEFu)

/* Mask to check if the Cluster Request Bit is set. */
#define CANNM_CRI_BIT_MASK                          ((uint8)0x40U)

/* Mask to check if asynchronous transmission is requested. */
#define CANNM_NO_TRANSMIT_REQUEST                   ((uint8)0x00U)
#define CANNM_TRANSMIT_REQUEST                      ((uint8)0x02U)

/* Macros for communication requests. */
#define CANNM_NO_RESTART                            ((uint8)0U)
#define CANNM_PASSIVE_RESTART                       ((uint8)1U)
#define CANNM_ACTIVE_RESTART                        ((uint8)2U)

/* CanNm Instance ID. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANNM_INSTANCE_ID                           ((uint8)0x00U)

/* Development Error Detection. */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANNM_REPORT_DEV_ERROR(SID, ERROR)     \
    ((void)Det_ReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, (SID), (ERROR)))

/* critical section macros. */
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanNm_EnterCritical() SchM_Enter_CanNm_CANNM_EXCLUSIVE_AREA_0()
/* polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define CanNm_LeaveCritical() SchM_Exit_CanNm_CANNM_EXCLUSIVE_AREA_0()

#ifndef CANNM_LOCAL
#define CANNM_LOCAL static
#endif

#ifndef CANNM_LOCAL_INLINE
#define CANNM_LOCAL_INLINE LOCAL_INLINE
#endif

/*
********************************************************************************
*    Local Types
********************************************************************************
*/
/*
********************************************************************************
*    Local Variables
********************************************************************************
*/
#define CANNM_START_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_UsedNonSharedVariable" */
static VAR(uint8, CANNM_VAR_INIT) CanNm_ModuleInitState = CANNM_UNINIT;
/* polyspace +1 VARIABLE:* [Justified:Unset] "NSCA_Polyspace_CanNm_UsedNonSharedVariable" */
static VAR(boolean, CANNM_VAR_INIT) CanNM_Message_Receive = FALSE;

#define CANNM_STOP_SEC_VAR_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define CANNM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( CANNM_PN_EIRA_CALC_FEATURE_ENABLED == STD_ON )
static FUNC(void, CANNM_CODE) CanNm_PnEiraCalculation
(
    NetworkHandleType channel
);
#endif

#if( CANNM_PN_ERA_CALC_FEATURE_ENABLED == STD_ON )
CANNM_LOCAL_INLINE FUNC(void, CANNM_CODE) CanNm_PnEraCalculation
(
    NetworkHandleType channel
);
#endif

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
static FUNC(boolean, CANNM_CODE) CanNm_PnFilterHandling
(
    NetworkHandleType channel,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
);
#endif

#if( (CANNM_NODE_ID_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) \
    || (CANNM_CAR_WUP_RX_FEATURE_ENABLED == STD_ON) )
static FUNC(void, CANNM_CODE) CanNm_CopyRxMessageData
(
    NetworkHandleType channel,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
);
#endif

static FUNC(void, CANNM_CODE) CanNm_MainRxTxConfHandling
(
    NetworkHandleType channel
);

#if( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_NODE_DETECTION_ENABLED == STD_ON) )
static FUNC(void, CANNM_CODE) CanNm_RepeatMessageIndHandling
(
    NetworkHandleType channel
);
#endif

static FUNC(void, CANNM_CODE) CanNm_BusCommunicationHandling
(
    NetworkHandleType channel,
    uint8 commState
);
static FUNC(void, CANNM_CODE) CanNm_TimeoutTimerHandling
(
    NetworkHandleType channel
);
static FUNC(void, CANNM_CODE) CanNm_RepeatMessageTimerHandling
(
    NetworkHandleType channel
);
static FUNC(void, CANNM_CODE) CanNm_WaitBusSleepTimerHandling
(
    NetworkHandleType channel
);
static FUNC(void, CANNM_CODE) CanNm_MessageTimerHandling
(
    NetworkHandleType channel
);
static FUNC(void, CANNM_CODE) CanNm_MessageTimeoutTimerHandling
(
    NetworkHandleType channel
);
static FUNC(void, CANNM_CODE) CanNm_TransitionToRepeatMessage
(
    NetworkHandleType channel
);
static FUNC(void, CANNM_CODE) CanNm_TransitionToNetworkMode
(
    NetworkHandleType channel,
    uint8 lastNmState
);
#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
static FUNC(void, CANNM_CODE) CanNm_PnLocal_Init
(
    NetworkHandleType channel
);
#endif

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
static FUNC(void, CANNM_CODE) CanNm_DisablePnFilter
(
    NetworkHandleType channel
);
#endif

static FUNC(void, CANNM_CODE) CanNm_LocalInit
(
    NetworkHandleType channel
);
static FUNC(Std_ReturnType, CANNM_CODE) CanNm_TriggerTransmission
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
);
static FUNC(void, CANNM_CODE) CanNm_StateTransition
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel,
    Nm_StateType nextNmState
);

#define CANNM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define CANNM_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( CANNM_PN_EIRA_CALC_FEATURE_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_PnEiraCalculation
*
* Explanation: Calculate pn Eira.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
static FUNC(void, CANNM_CODE) CanNm_PnEiraCalculation(NetworkHandleType channel)
{
    /* Local Variables. */
    uint8       pnClusterRequestByte = CANNM_ZERO;
    uint8       pnClusterRequestBit = CANNM_ZERO;
    uint8       pnClusterRequestNew = CANNM_ZERO;
    uint8       PnClusterRequestNewSize = CANNM_ZERO;
    boolean     pnClusterRequestChanged = FALSE;
    PduInfoType nmPnInfo = {NULL_PTR,CANNM_ZERO};

    if( CANNM_ZERO == channel )
    {
        /* Get Size Of Pn Cluster Request. */
        PnClusterRequestNewSize = CanNm_GetSizeOfPnClusterReqNew();
        /* Iterate all Partial Networking Cluster Bytes. */
        for( pnClusterRequestByte = CANNM_ZERO;
                pnClusterRequestByte < PnClusterRequestNewSize; pnClusterRequestByte++ )
        {
            /* Received Nm message contains new or repeated requests. */
            if( CANNM_ZERO != CanNm_GetPnClusterReqNew(pnClusterRequestByte) )
            {
                pnClusterRequestNew = CanNm_GetPnClusterReqNew(pnClusterRequestByte);
                CanNm_SetPnClusterReqNew(pnClusterRequestByte, CANNM_ZERO);

                /* pnClusterRequestBit contains now the sum of current
                    and new PN EIRA requests. variable is reused as iterator below. */
                pnClusterRequestBit = (uint8)(CanNm_GetPnClusterReq(pnClusterRequestByte)
                                                                        | pnClusterRequestNew);

                if( pnClusterRequestBit != CanNm_GetPnClusterReq(pnClusterRequestByte) )
                {
                    pnClusterRequestChanged = TRUE;
                    CanNm_SetPnClusterReq(pnClusterRequestByte, (uint8)pnClusterRequestBit);
                }

                /* Reuse of variable pnClusterRequestBit to iterate all Bits in current Cluster Request Byte. */
                for( pnClusterRequestBit = CANNM_ZERO;
                        pnClusterRequestBit < CANNM_PN_CLUSTERS_PER_BYTE; pnClusterRequestBit++ )
                {
                    if( CANNM_ZERO != (pnClusterRequestNew & ((CANNM_ONE << pnClusterRequestBit))) )  /* PRQA S 4397 */ /* NSCA_QAC_ComNm_Rule10.7 */
                    {
                        CanNm_GetPnClusterResetTimer(pnClusterRequestByte)[pnClusterRequestBit]
                                                                    = (uint16)CanNm_GetPnResetTime() + CANNM_ONE;
                    }
                }
            }

            /* at least one PNC is requested. */
            if( CANNM_ZERO != CanNm_GetPnClusterReq(pnClusterRequestByte) )
            {
                /* Iterate all PNC Bits in the current PNC Byte. */
                for( pnClusterRequestBit = CANNM_ZERO;
                        pnClusterRequestBit < CANNM_PN_CLUSTERS_PER_BYTE; pnClusterRequestBit++ )
                {
                    /* PnClusterResetTimer of PNC Bit in PNC Byte has not elapsed. */
                    if( CANNM_ZERO != CanNm_GetPnClusterResetTimer(pnClusterRequestByte)[pnClusterRequestBit] )
                    {
                        CanNm_GetPnClusterResetTimer(pnClusterRequestByte)[pnClusterRequestBit]--;

                        if( CANNM_ZERO == CanNm_GetPnClusterResetTimer(pnClusterRequestByte)[pnClusterRequestBit] )
                        {
                            pnClusterRequestChanged = TRUE;

                            /* Reset the local PNC request. */
                            CanNm_SetPnClusterReq(pnClusterRequestByte,  /* PRQA S 4397 */ /* NSCA_QAC_ComNm_Rule10.7 */
                                (uint8)(CanNm_GetPnClusterReq(pnClusterRequestByte)
                                            & (uint8)(~(CANNM_ONE << pnClusterRequestBit))));
                        }
                    }
                }
            }
        }

        /* If an PNC EIRA request has changed, indicate this to the ComM (via PduR -> Com <- ComM)
                Pass the changed PnClusterRequest buffer to the Com by calling PduR_CanNmRxIndication. */
        if( (boolean)TRUE == pnClusterRequestChanged )
        {
            /* Assign nmPnInfo.SduDataPtr pointer to address of PnClusterReq array. */
            nmPnInfo.SduDataPtr = CanNm_GetAddrPnClusterReq(CANNM_ZERO);

            /* Set nmPnInfo.SduLength to length of PnInfo container. */
            nmPnInfo.SduLength = CanNm_GetPnInfoLength();

            PduR_CanNmRxIndication(CanNm_GetPnEiraRxPduId(), &nmPnInfo);
        }
    }
}
#endif /* CANNM_PN_EIRA_CALC_FEATURE_ENABLED */

#if( CANNM_PN_ERA_CALC_FEATURE_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_PnEraCalculation
*
* Explanation: Calculate pn Era.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
CANNM_LOCAL_INLINE FUNC(void, CANNM_CODE) CanNm_PnEraCalculation
(
    NetworkHandleType channel
)
{
    /* Local Variables. */
    uint8       pnClusterRequestByte = CANNM_ZERO;
    uint8       pnClusterRequestBit = CANNM_ZERO;
    uint8       pnClusterRequestNew = CANNM_ZERO;
    boolean     pnClusterRequestChanged = FALSE;
    PduInfoType nmPnInfo = {NULL_PTR,CANNM_ZERO};

    if( (TRUE == CanNm_IsPnEnabled(channel)) && (TRUE == CanNm_IsPnEraCalcEnabled(channel))
      && ( NULL_PTR != CanNm_GetEraPnInfo(channel)) )
    {
        for( pnClusterRequestByte = CanNm_GetPnClusterReqExtStartIdx(channel);
                 pnClusterRequestByte < CanNm_GetPnClusterReqExtEndIdx(channel);
                 pnClusterRequestByte++ )
        {
            if( CANNM_ZERO != CanNm_GetPnClusterReqExtNew(channel, pnClusterRequestByte) )
            {
                pnClusterRequestNew = CanNm_GetPnClusterReqExtNew(channel, pnClusterRequestByte);
                CanNm_SetPnClusterReqExtNew(channel, pnClusterRequestByte, CANNM_ZERO);

                pnClusterRequestBit = (uint8)(CanNm_GetPnClusterReqExt(channel, pnClusterRequestByte) | pnClusterRequestNew);
                if( pnClusterRequestBit != CanNm_GetPnClusterReqExt(channel, pnClusterRequestByte) )
                {
                    pnClusterRequestChanged = TRUE;
                    CanNm_SetPnClusterReqExt(channel, pnClusterRequestByte, (uint8)pnClusterRequestBit);
                }
                for( pnClusterRequestBit = CANNM_ZERO; pnClusterRequestBit < CANNM_PN_CLUSTERS_PER_BYTE; pnClusterRequestBit++ )
                {
                    if( CANNM_ZERO != (pnClusterRequestNew & (CANNM_ONE << pnClusterRequestBit)) )    /* PRQA S 4397 */ /* NSCA_QAC_ComNm_Rule10.7 */
                    {
                        CanNm_GetPnClusterResetTimerExt(channel, pnClusterRequestByte)[pnClusterRequestBit] = (uint16)CanNm_GetPnResetTime() + CANNM_ONE;
                    }
                }
            }

            if( CANNM_ZERO != CanNm_GetPnClusterReqExt(channel, pnClusterRequestByte) )
            {
              for( pnClusterRequestBit = CANNM_ZERO; pnClusterRequestBit < CANNM_PN_CLUSTERS_PER_BYTE; pnClusterRequestBit++ )
              {
                if( CanNm_GetPnClusterResetTimerExt(channel, pnClusterRequestByte)[pnClusterRequestBit] != CANNM_ZERO )
                {
                  CanNm_GetPnClusterResetTimerExt(channel, pnClusterRequestByte)[pnClusterRequestBit]--;
                  if( CanNm_GetPnClusterResetTimerExt(channel, pnClusterRequestByte)[pnClusterRequestBit] == CANNM_ZERO )
                  {
                    pnClusterRequestChanged = TRUE;
                    CanNm_SetPnClusterReqExt(channel, pnClusterRequestByte, (uint8)(CanNm_GetPnClusterReqExt(channel, pnClusterRequestByte) & (uint8)(~(CANNM_ONE << pnClusterRequestBit))));  /* PRQA S 4397 */ /* NSCA_QAC_ComNm_Rule10.7 */
                  }
                }
              }
            }
        }
    }

    if( ((boolean)TRUE == pnClusterRequestChanged ) && ( NULL_PTR != CanNm_GetEraPnInfo(channel)) )
    {
      /* Assign nmPnInfo.SduDataPtr pointer to address of PnClusterReqExt array (with channel offset) */
      nmPnInfo.SduDataPtr = (uint8*)(CanNm_GetAddrPnClusterReqExt(channel, CanNm_GetPnClusterReqExtStartIdx(channel)));
      /* Set nmPnInfo.SduLength to length of PnInfo container */
      nmPnInfo.SduLength = CanNm_GetEraPnInfoLength(channel);
      PduR_CanNmRxIndication( CanNm_GetPnEraRxPduId(channel), &nmPnInfo );
    }
}
#endif

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_PnFilterHandling
*
* Explanation: Handling pn Eira.
*
* param: channel: Identification of the NM-channel.
*       PduInfoPtr: point to pdu info.
*
* retval: boolean: is message relevant.
********************************************************************************
*/
static FUNC(boolean, CANNM_CODE) CanNm_PnFilterHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
)
{
    /* Local variabls. */
    boolean      msgRelevant = FALSE;
    uint8        rxMsgBytePos;
    uint8        reqCluster;

    /* If PN Enabled. */
    if( ((boolean)TRUE == CanNm_IsPnEnabled(channel) ) && ( NULL_PTR != CanNm_GetEraPnInfo(channel)) )
    {
        /* CBV position not CANNM_PDU_OFF. */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( CANNM_PDU_OFF != CanNm_GetPduCbvPosition(channel) )
        {
            /* Partial Network Information Bit. */
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
            if( (CANNM_ZERO != ((PduInfoPtr->SduDataPtr[CanNm_GetPduCbvPosition(channel)])& CANNM_CRI_BIT_MASK))
               && (NULL_PTR != CanNm_GetEraPnFilterMask(channel)) )
            {
                /* Iteration PNI info, use mask find relevant msg. */
                for( rxMsgBytePos = CANNM_ZERO;
                        rxMsgBytePos < CanNm_GetEraPnInfoLength(channel); rxMsgBytePos++ )
                {
                    reqCluster = (uint8)(PduInfoPtr->SduDataPtr[rxMsgBytePos
                            + CanNm_GetEraPnInfoOffset(channel)] & CanNm_GetEraPnFilterMask(channel)[rxMsgBytePos]);

                    if( CANNM_ZERO != reqCluster )
                    {
                        msgRelevant = TRUE;

#if( CANNM_PN_EIRA_CALC_FEATURE_ENABLED == STD_ON )
                        /* Copy the requests to pn cluster. */
                        CanNm_SetPnClusterReqNew(rxMsgBytePos,
                            (uint8)(CanNm_GetPnClusterReqNew(rxMsgBytePos) | reqCluster));
#endif

#if( CANNM_PN_ERA_CALC_FEATURE_ENABLED == STD_ON )
                        /* Copy the requests to pn cluster. */
                        if( TRUE == CanNm_IsPnEraCalcEnabled(channel) )
                        {
                            CanNm_SetPnClusterReqExtNew(channel, rxMsgBytePos,
                                (uint8)(CanNm_GetPnClusterReqExtNew(channel, rxMsgBytePos) | reqCluster));
                        }
#endif
                    }
                }
            }
        }
    }
    else
    {
        msgRelevant = TRUE;
    }

    return msgRelevant;
}
#endif

#if( (CANNM_NODE_ID_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) \
    || (CANNM_CAR_WUP_RX_FEATURE_ENABLED == STD_ON) )
/*
********************************************************************************
* Function Name: CanNm_CopyRxMessageData
*
* Explanation: Copy received NM message data to the Rx Message Data buffer.
*
* param: channel: Identification of the NM-channel.
*       PduInfoPtr: point to pdu info.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_CopyRxMessageData
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
)
{
    /* Local variables. */
    uint8  rxMsgByte;

    /* Copy received NM message data to the Rx Message Data buffer. */
    for( rxMsgByte = CANNM_ZERO; rxMsgByte < CanNm_GetRxMsgDataLength(channel); rxMsgByte++ )
    {
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
        CanNm_SetRxMessageData(channel, CanNm_GetRxMsgDataStartIdx(channel) + rxMsgByte,
                                    (uint8)(PduInfoPtr->SduDataPtr[rxMsgByte]));
    }
}
#endif
/*
********************************************************************************
* Function Name: CanNm_MainRxTxConfHandling
*
* Explanation: Perform Related Confirmation Operations When Tx Confirmation Is 
*              Enabled, Perform Related Operation According To Received State
*              Of CanNM.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_MainRxTxConfHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    /* Process tx confirmation. */
    if( (boolean)TRUE == CanNm_IsMsgConfirmationFlag(channel) )
    {
        CanNm_SetMsgConfirmationFlag(channel, FALSE);

        /* Restart Timeout Timer. */
        CanNm_SetTimeoutTimer(channel, (uint16)(CanNm_GetTimeoutTime(channel) + CANNM_ONE));

        /* Stop Message Timeout Timer if Immediate Tx conf is enabled. */
        CanNm_SetMsgTimeoutTimer(channel, CANNM_ZERO);
    }

    /* Process rx indication. */
    if( (boolean)TRUE == CanNm_IsMsgIndicationFlag(channel) )
    {
        CanNm_SetMsgIndicationFlag(channel, FALSE);
        switch(CanNm_GetNmState(channel))
        {
            case NM_STATE_BUS_SLEEP:
                /* In BusSleep:  Request to restart the network
                               if a NM message has been received in Bus-Sleep Mode. */
                (void)Nm_NetworkStartIndication(CanNm_GetChannelId(channel));
                break;

            case NM_STATE_PREPARE_BUS_SLEEP:
                /* In PrepareBusSleep: Perform state transition to RepeatMessage state. */
                CanNm_StateTransition(channel, NM_STATE_REPEAT_MESSAGE);
                break;

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON ) || ( CANNM_BUS_LOAD_REDUCTION_ENABLED == STD_ON )
                    /* -------------------- Normal Operation -------------------- */
            case NM_STATE_NORMAL_OPERATION:

#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
            if( MSG_TX_ENABLED == CanNm_GetTxControlState(channel) )
#endif  /* ( CANNM_COM_CONTROL_ENABLED == STD_ON ) */
            {

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
                CanNm_SetRemoteSleepTimer(channel, (uint16)(CanNm_GetRemoteSleepIndTime(channel) + 1U));
#endif  /* ( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON ) */

#if( CANNM_BUS_LOAD_REDUCTION_ENABLED == STD_ON )
                if( TRUE == CanNm_IsBusLoadReductionActive(channel) )
                {
                    CanNm_SetMsgTimer(channel, (uint16)(CanNm_GetMsgReduceTime(channel) + 1U));
                }
#endif  /* ( CANNM_BUS_LOAD_REDUCTION_ENABLED == STD_ON ) */

            }
#endif  /* ( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON ) || ( CANNM_BUS_LOAD_REDUCTION_ENABLED == STD_ON ) */

            case NM_STATE_READY_SLEEP:

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
                if( TRUE == CanNm_IsRemoteSleepIndState(channel) )
                {
                    CanNm_SetRemoteSleepIndState(channel, FALSE);
                    Nm_RemoteSleepCancellation(CanNm_GetChannelId(channel));
                }
#endif

            default:
                /* In RepeatMessage, ReadySleep or NormalOperation:
                                If message transmission is allowed Restart TimeoutTimer in order to stay awake. */
                CanNm_SetTimeoutTimer(channel,
                    (uint16)(CanNm_GetTimeoutTime(channel) + CANNM_ONE));
            break;
        }
    }
}

#if( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_NODE_DETECTION_ENABLED == STD_ON) )
/*
********************************************************************************
* Function Name: CanNm_RepeatMessageIndHandling
*
* Explanation: Handle repeat message.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_RepeatMessageIndHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    /* RepeatMessage state was requested internally. */
    if( (boolean)TRUE == CanNm_IsRepeatMsgReqFlag(channel) )
    {
        CanNm_SetRepeatMsgBitIndFlag(channel, TRUE);

        /* Check for valid PDU Position. */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( CanNm_GetTxMsgData_CBVIdx(channel) != CANNM_PDU_OFF )
        {
            /* Set Repeat Message Bit. */
            CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
            (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) | CANNM_REPEAT_MSG_BIT_MASK));
        }
    }

    /* RepeatMessageIndication is requested by Network or internally. */
    if( (boolean)TRUE == CanNm_IsRepeatMsgBitIndFlag(channel) )
    {

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
        if( (TRUE == CanNm_IsRemoteSleepIndState(channel)) )
        {
          /* Notification that some nodes in the network are not ready to sleep. */
          Nm_RemoteSleepCancellation(CanNm_GetChannelId(channel));
        }
#endif
        /* Perform a State Transition to Repeat Message State. */
        CanNm_StateTransition(channel, NM_STATE_REPEAT_MESSAGE);
        /* Reset RepeatMessage request. */
        CanNm_SetRepeatMsgReqFlag(channel, FALSE);
    }
}
#endif

/*
********************************************************************************
* Function Name: CanNm_BusCommunicationHandling
*
* Explanation: If Network is requested AND NmState is ReadySleep,
*                               Do state transition to NormalOperation state,
*              If Network is released AND NmState is NormalOperation,
*                               Do state transition to ReadySleep state.
*
* param: channel: Identification of the NM-channel.
*       commState: Comm State.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_BusCommunicationHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel,
    uint8 commState
)
{
    if( COMM_NORMAL_OPERATION == commState )
    {
        if( NM_STATE_READY_SLEEP == CanNm_GetNmState(channel) )
        {
            /* Perform a state transition because bus-communication has been requested. */
            CanNm_StateTransition(channel, NM_STATE_NORMAL_OPERATION);
        }
    }
    else
    {
        if( NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel) )
        {
            /* Perform a state transition because bus-communication has been released. */
            CanNm_StateTransition(channel, NM_STATE_READY_SLEEP);
        }
    }
}

/*
********************************************************************************
* Function Name: CanNm_TimeoutTimerHandling
*
* Explanation: Handle timeout timer, control timer in ready sleep.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_TimeoutTimerHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    /* Local variables. */
    uint8 errorId = CANNM_E_NO_ERROR;

    if( CANNM_ZERO != CanNm_GetTimeoutTimer(channel) )
    {
        /*  Decrement Timeout Timer. */
        CanNm_DecTimeoutTimer(channel);

        /* Timeout */
        if( CANNM_ZERO == CanNm_GetTimeoutTimer(channel) )
        {
            if( NM_STATE_READY_SLEEP != CanNm_GetNmState(channel) )
            {
                /* Restart the NM Timeout Timer. */
                CanNm_SetTimeoutTimer(channel, (uint16)CanNm_GetTimeoutTime(channel));
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
                errorId = CANNM_E_NETWORK_TIMEOUT;
#endif
            }
            else
            {
                /* Leave Ready Sleep State, when the Timeout Timer has expired. */
                CanNm_StateTransition(channel, NM_STATE_PREPARE_BUS_SLEEP);
            }
        }
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_TIMEOUTTIMERHANDLING, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif /* CANNM_DEV_ERROR_DETECT */
}

/*
********************************************************************************
* Function Name: CanNm_RepeatMessageTimerHandling
*
* Explanation: Repeat Message Timer Determine The Time Remain In Repeat Message State,
*            State Transition To Another State When Repeat Message Timer has elapsed.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_RepeatMessageTimerHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    /* Repeat Message Timer is running. */
    if( CANNM_ZERO != CanNm_GetRepeatMsgTimer(channel) )
    {
        CanNm_DecRepeatMsgTimer(channel);
        if( CANNM_ZERO == CanNm_GetRepeatMsgTimer(channel) )
        {
            /*  Do state transition to either NormalOperation (non-passive)
                            or ReadySleep state, depending on internal request state. */
#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF)
            CanNm_StateTransition(channel,
            (Nm_StateType)((COMM_NORMAL_OPERATION == CanNm_GetCommState(channel))
                                    ? NM_STATE_NORMAL_OPERATION : NM_STATE_READY_SLEEP));
#else
            CanNm_StateTransition(channel, NM_STATE_READY_SLEEP);
#endif
        }
    }
}

/*
********************************************************************************
* Function Name:   CanNm_WaitBusSleepTimerHandling
*
* Explanation: Wait Bus Sleep Timer Determine The Time Remain In Prepare Bus Sleep State,
*              The Bus Sleep State shall be entered When Wait Bus Sleep Timer Has Elapsed.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_WaitBusSleepTimerHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    /* Wait Bus Sleep Timer is running. */
    if( CANNM_ZERO != CanNm_GetWaitBusSleepTimer(channel) )
    {
        /* Decrement Wait Bus Sleep Timer. */
        CanNm_DecWaitBusSleepTimer(channel);

        if( CANNM_ZERO == CanNm_GetWaitBusSleepTimer(channel) )
        {
            /* Do state transition to PrepareBusSleep state. */
            CanNm_StateTransition(channel, NM_STATE_BUS_SLEEP);
        }
    }
}

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name:   CanNm_RemoteSleepTimerHandling
*
* Explanation: Remote Sleep Timer handling.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
 */
static FUNC(void, CANNM_CODE) CanNm_RemoteSleepTimerHandling
(
    NetworkHandleType channel
)
{
  /* #10 If Remote Sleep Indication Timer is running
   *      Decrement Remote Sleep Indication Timer
   *      If Remote Sleep Indication Timer has elapsed
   *       Indicate that channel is ready to go to sleep
   */
  if( CANNM_ZERO !=CanNm_GetRemoteSleepTimer(channel) )
  {
    CanNm_DecRemoteSleepTimer(channel);
    if( CANNM_ZERO == CanNm_GetRemoteSleepTimer(channel) )
    {
      /* Remote Sleep Indication (Normal Operation State only). */
       CanNm_SetRemoteSleepIndState(channel, TRUE);
      /* Notification that all other nodes are ready to sleep. */
       Nm_RemoteSleepIndication( CanNm_GetChannelId(channel) );
    }
  }
}
#endif /* ( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON ) */


/*
********************************************************************************
* Function Name:   CanNm_MessageTimerHandling
*
* Explanation: Be Used For Timer When CanNM Translate Message And
*              Make Relevant processing If Tx Message Timer Has Elapsed 0.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_MessageTimerHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    /* Local variables. */
    Std_ReturnType success;

    /* Tx Message Timer is running. */
    if( CANNM_ZERO != CanNm_GetMsgTimer(channel) )
    {
        CanNm_DecMsgTimer(channel);
        if( (CANNM_ZERO == CanNm_GetMsgTimer(channel))

#if( CANNM_COM_USER_DATA_SUPPORT == STD_ON )
           || (CANNM_ZERO != CanNm_GetMsgRequest(channel))
#endif

        )
        {
            /* Transmit a NM message. */
            success = CanNm_TriggerTransmission(channel);

            /* Reset timer with immediate cycle time when transmissions greater zero. */
            if( CANNM_ZERO != CanNm_GetImmediateNmMsgCount(channel) )
            {

#if( CANNM_RETRY_FIRST_MESSAGE_REQUEST == STD_ON )
        CanNm_SetRetryFirstMessageRequestFlag(channel, FALSE);
#endif
                if( E_OK == success )
                {
                    /* Reduce number of Immediate NM transmissions. */
                    CanNm_DecImmediateNmMsgCount(channel);
                    CanNm_SetMsgTimer(channel, (uint16)CanNm_GetImmediateNmCycleTime(channel));
                }
                else
                {   /* Restart the Msg timer. */
                    CanNm_SetMsgTimer(channel, CANNM_ONE);
                }
            }
            else
            {

#if( CANNM_RETRY_FIRST_MESSAGE_REQUEST == STD_ON )
                if( (boolean)TRUE == CanNm_IsRetryFirstMessageRequestFlag(channel) )
                {
                    if( (uint8)E_OK == success )
                    {
                        /* If one message was successfully transmitted, the RetryFirstMessageRequest feature is turned off. */
                        CanNm_SetRetryFirstMessageRequestFlag(channel, FALSE);

#if( CANNM_IMMEDIATE_RESTART_ENABLED == STD_ON )
                        /* If the ImmediateRestart message failed, the MsgTimer will be reloaded with the offset that would have been transmitted if the ImmediateRestart didn't fail. */
                        if( (boolean)TRUE == CanNm_IsImmediateRestartFailed(channel) )
                        {
                          CanNm_SetImmediateRestartFailed(channel, FALSE);
                          /* Reset Timer to MsgCycleOffset. */
                          CanNm_SetMsgTimer(channel, (uint16)(CanNm_GetMsgCycleOffset(channel)));
                        }
                        else
#endif

                        {
                            /* Reset Timer. */
                            CanNm_SetMsgTimer(channel, (uint16)(CanNm_GetMsgCycleTime(channel)));
                        }
                    }
                    else
                    {   /* Transmmit immediately at next main function. */
                        CanNm_SetMsgTimer(channel, CANNM_ONE);
                    }
                }
                else
#endif

                {   /* Restart the Msg timer. */
                    CanNm_SetMsgTimer(channel, (uint16)(CanNm_GetMsgCycleTime(channel)));
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: CanNm_MessageTimeoutTimerHandling
*
* Explanation: Be Used For Timeout Timer When CanNM Translate Message And
*              Make Relevant processing If Tx Message Timeout Timer Has Elapsed.
*
* param: channel: Identification of the CANNM-channel.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_MessageTimeoutTimerHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    /* Tx Message Timeout Timer is running. */
    if( CANNM_ZERO != CanNm_GetMsgTimeoutTimer(channel) )
    {
        /* Decrement Tx Message Timeout Timer. */
        CanNm_DecMsgTimeoutTimer(channel);

        /* Tx Message Timer Timeout has elapsed. */
        if( CANNM_ZERO == CanNm_GetMsgTimeoutTimer(channel) )
        {
            /* Call timeout exception only once. */
            Nm_TxTimeoutException(CanNm_GetChannelId(channel));

            if( ((boolean)TRUE == CanNm_IsPnEnabled(channel)) && ((boolean)TRUE == CanNm_IsPnCallTxTimeoutException(channel)) )
            {
                /* PN Feature enabled: call CanSM_TxTimeoutException. */
                CanSM_TxTimeoutException(CanNm_GetChannelId(channel));
            }
        }
    }
}

#if( CANNM_CAR_WUP_RX_FEATURE_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_CarWakeupIndication
*
* Explanation: Be Used For Timeout Timer When CanNM Translate Message And
*              Make Relevant processing If Tx Message Timeout Timer Has Elapsed.
*
* param: channel: Identification of the CANNM-channel.
*
* retval: None
********************************************************************************
*/
CANNM_LOCAL_INLINE FUNC(void, CANNM_CODE) CanNm_CarWakeupIndication
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
)
{
    /* polyspace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_CanNm_Rule10.1" */
    if( CanNm_IsCarWakeUpRxEnabled(channel) && (PduInfoPtr->SduLength > CanNm_GetCarWakeUpBytePosition(channel)) )
    {
        /* polyspace +1 MISRA-C3:D4.1 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.1" polyspace +1 MISRA-C3:14.4 [Justified:Unset] "NSCA_Polyspace_CanNm_Rule14.4" polyspace +1 MISRA-C3:18.1 [Justified:Unset] "NSCA_Polyspace_CanNm_Rule18.1" polyspace +1 RTE:OBAI [Justified:Unset] "NSCA_Polyspace_CanNm_OBAI" */
        if( (CanNm_GetRxMessageData(channel,CanNm_GetCarWakeUpBytePosition(channel))) & (CanNm_GetCarWakeUpBitMask(channel)) )
        {
#if( CANNM_CAR_WUP_FILTER_FEATURE_ENABLED == STD_ON )
            /* polyspace +1 MISRA-C3:10.1 [Justified:Unset] "NSCA_Polyspace_CanNm_Rule10.1" */
            if( !CanNm_IsCarWakeUpFilterEnabled(channel) ||
            ((CANNM_PDU_OFF != CanNm_GetPduNidPosition(channel) ) &&
          (CanNm_GetRxMessageData(channel,CanNm_GetPduNidPosition(channel))
          == CanNm_GetCarWakeUpFilterNodeId(channel))) )
#endif
            {
                Nm_CarWakeUpIndication(CanNm_GetChannelId(channel));
            }
        }
    }
}
#endif /* ( CANNM_CAR_WUP_RX_FEATURE_ENABLED == STD_ON ) */

#if( CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_CoordReadyToSleepHandling
*
* Explanation: Judgment of sleep ready bit and related operations.
*
* param: channel: Identification of the CANNM-channel.
*
* retval: None
********************************************************************************
*/
CANNM_LOCAL_INLINE FUNC( void, CANNM_CODE ) CanNm_CoordReadyToSleepHandling
(
    NetworkHandleType channel,
    uint8 rxMsgByte
)
{
    uint8 sleepReadyBit;

    sleepReadyBit = (uint8)(rxMsgByte & NM_COORD_BIT_SLEEP);
    if( CanNm_GetCoordReadyToSleepState(channel) != sleepReadyBit )
    {
        if( CANNM_ZERO != sleepReadyBit )
        {
            Nm_CoordReadyToSleepIndication(CanNm_GetChannelId(channel));
        }
        else
        {
            Nm_CoordReadyToSleepCancellation(CanNm_GetChannelId(channel));
        }
        CanNm_SetCoordReadyToSleepState(channel, (uint8)sleepReadyBit);
    }
}
#endif

/*
********************************************************************************
* Function Name: CanNm_TransitionToRepeatMessage
*
* Explanation: Transition To Repeat Message State And Perform Related Configuration
*              In Current State.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_TransitionToRepeatMessage
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{

    #if( CANNM_RMR_FAST_TRANSITION == STD_ON )
    /* 新增：记录本次进入 RMS 是否由“收到 RMR 位”触发 */
    boolean immediateTxRequested = FALSE;
    #endif

    /* Start the Repeat Message Timer. */
    CanNm_SetRepeatMsgTimer(channel, (uint16)(CanNm_GetRepeatMessageTime(channel) + (uint16)CANNM_ONE));

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
      CanNm_SetRemoteSleepTimer(channel, CANNM_ZERO );
      CanNm_SetRemoteSleepIndState(channel, FALSE);
#endif

#if( CANNM_NODE_DETECTION_ENABLED == STD_ON )
    if( (boolean)TRUE == CanNm_IsRepeatMsgBitIndFlag(channel) )
    {
        #if( CANNM_RMR_FAST_TRANSITION == STD_ON )
        /* 记录RMR触发情况 */
        immediateTxRequested = TRUE;      
        #endif
        /* Clear Repeat Message Indication flag. */
        CanNm_SetRepeatMsgBitIndFlag(channel, FALSE);

#if( CANNM_REPEAT_MSG_IND_ENABLED == STD_ON ) /* depends on CANNM_NODE_DETECTION_ENABLED == STD_ON. */
        Nm_RepeatMessageIndication(CanNm_GetChannelId(channel));
#endif

    }
#endif /* CANNM_NODE_DETECTION_ENABLED == STD_ON */

#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )

#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
    if( MSG_TX_ENABLED == CanNm_GetTxControlState(channel) )
#endif /* CANNM_COM_CONTROL_ENABLED == STD_ON  */

    {
        #if( CANNM_RMR_FAST_TRANSITION == STD_ON )
        /* Trigger an asynchronous transmission of the NM message. */
        if( (CANNM_ZERO < CanNm_GetImmediateNmTransmissions(channel)) &&
            ( (CANNM_ACTIVE_RESTART == CanNm_GetNetworkRestartFlag(channel)) ||
              (TRUE == immediateTxRequested) ) )          /* RMR的情况，也进入快发 */
        #else
        /* Trigger an asynchronous transmission of the NM message. */
        if( (CANNM_ZERO < CanNm_GetImmediateNmTransmissions(channel)) &&
            (CANNM_ACTIVE_RESTART == CanNm_GetNetworkRestartFlag(channel)))
        #endif
        
        {
            CanNm_SetMsgTimer(channel, CANNM_ONE);
            CanNm_SetImmediateNmMsgCount(channel, (uint8)(CanNm_GetImmediateNmTransmissions(channel) - CANNM_ONE));
        }
        else
        {
            CanNm_SetMsgTimer(channel, (uint16)(CanNm_GetMsgCycleOffset(channel) + (uint16)CANNM_ONE));
        }
    }
#endif /* CANNM_PASSIVE_MODE_ENABLED == STD_OFF */
}

/*
********************************************************************************
* Function Name: CanNm_TransitionToNetworkMode
*
* Explanation: Transition To Network Mode And Perform Related Configuration In Current Mode.
*
* param: channel: Identification of the NM-channel.
*       lastNmState: Last nm state.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_TransitionToNetworkMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel,
    uint8 lastNmState
)
{
    /* If RepeatMessage state was entered from BusSleep or PrepareBusSleep state. */
    if( NM_STATE_READY_SLEEP > lastNmState )
    {
        /* Clear Wait Bus Sleep Timer. */
        CanNm_SetWaitBusSleepTimer(channel, CANNM_ZERO);

        /* Restart the Timeout Timer. */
        CanNm_SetTimeoutTimer(channel, (uint16)(CanNm_GetTimeoutTime(channel) + CANNM_ONE));

        /* Notify Nm Interface that the network mode is entered. */
        Nm_NetworkMode(CanNm_GetChannelId(channel));

#if( CANNM_ACTIVE_WUP_BIT_FEATURE_ENABLED == STD_ON )
        if( ((boolean)TRUE == CanNm_IsActiveWakeupBitEnable(channel)) && (CANNM_ACTIVE_RESTART == CanNm_GetNetworkRestartFlag(channel)) )
        {
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( CANNM_NO_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG != CanNm_GetTxMsgData_CBVIdx(channel) )
            {
                CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
                          (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) | CANNM_ACT_WU_BIT_MASK));
            }
        }
#endif

#if( CANNM_RETRY_FIRST_MESSAGE_REQUEST == STD_ON )
          if( (NM_STATE_BUS_SLEEP == lastNmState) || (NM_STATE_PREPARE_BUS_SLEEP == lastNmState) ) /* COV_CANNM_NO_NODE_DETECTION_ENABLED */
          {
            CanNm_SetRetryFirstMessageRequestFlag(channel, CanNm_GetRetryFirstMessageRequestEnabled(channel)); /* SBSW_CANNM_CSL_CHANNEL_INDEX_ACCESS */
          }
#endif /* CANNM_RETRYFIRSTMESSAGEREQUESTOFCHANNELCONFIG == STD_ON */
    }

//RSS -> RMS AWB更新
#if(( CANNM_AWB_RSS_UPDATE_SUPPORTED == STD_ON ) && ( CANNM_ACTIVE_WUP_BIT_FEATURE_ENABLED == STD_ON ))
    /* RSS -> RMS 重入：NM 停发后再次发送，按当前 active/passive 状态重写 AWB */
    if( NM_STATE_READY_SLEEP == lastNmState )
    {
        if( (boolean)TRUE == CanNm_IsActiveWakeupBitEnable(channel) )
        {
            if( CANNM_NO_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG != CanNm_GetTxMsgData_CBVIdx(channel) )
            {
                if( COMM_NORMAL_OPERATION == CanNm_GetCommState(channel) )
                {
                    /* 主动：AWB 置位 */
                    CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
                        (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) | CANNM_ACT_WU_BIT_MASK));
                }
                else
                {
                    /* 被动：AWB 清零 */
                    CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
                        (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) & CANNM_ACT_WU_BIT_INV_MASK));
                }
            }
        }
    }
#endif
}

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_PnLocal_Init
*
* Explanation: Service for resetting all internal variables about Partial Networking.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
static FUNC(void, CANNM_CODE) CanNm_PnLocal_Init(NetworkHandleType channel)
{
    /* Local variables. */
    uint8 pnClusterRequestByte = CANNM_ZERO;
    uint8 pnClusterRequestBit = CANNM_ZERO;
    uint8 pnFilterMaskSize = CANNM_ZERO;

    /* Disable Pn Message Filter mechanism (Refer to API CanNm_ConfirmPnAvaiability ). */
    CanNm_SetPnMessageFilterEnabled(channel, FALSE);
    CanNm_SetPnMessageFilterDeactived(channel, FALSE);

#if( CANNM_PN_MESSAGE_FILTER_FORCED_ENABLED == STD_ON )
    CanNm_SetPnMessageFilterEnabled(channel, (boolean)CanNm_IsPnEnabled(channel));
#endif

    /* Partial Networking is enabled on this channel. */
    if( (boolean)TRUE == CanNm_IsPnEnabled(channel) )
    {

#if( CANNM_PN_ERA_CALC_FEATURE_ENABLED == STD_ON )
        for( pnClusterRequestByte = CanNm_GetPnClusterReqExtStartIdx(channel);
             pnClusterRequestByte < CanNm_GetPnClusterReqExtEndIdx(channel);
             pnClusterRequestByte++ )
        {
            CanNm_SetPnClusterReqExt(channel, pnClusterRequestByte, CANNM_ZERO);
            CanNm_SetPnClusterReqExtNew(channel, pnClusterRequestByte, CANNM_ZERO);

            for( pnClusterRequestBit = CANNM_ZERO; pnClusterRequestBit < CANNM_PN_CLUSTERS_PER_BYTE; pnClusterRequestBit++ )
            {
                CanNm_GetPnClusterResetTimerExt(channel, pnClusterRequestByte)[pnClusterRequestBit] = CANNM_ZERO;
            }
        }
#else
    CANNM_DUMMY_STATEMENT(pnClusterRequestByte);
    CANNM_DUMMY_STATEMENT(pnClusterRequestBit);
#endif

#if( CANNM_PN_EIRA_CALC_FEATURE_ENABLED == STD_ON )
        if( CANNM_ZERO == channel )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        {
            /* Get Size Of Pn Filter Mask. */
            pnFilterMaskSize = CanNm_GetSizeOfPnFilterMask();
            for( pnClusterRequestByte = CANNM_ZERO;
                pnClusterRequestByte < pnFilterMaskSize; pnClusterRequestByte++ )
            {
                /* Initialize EIRA request buffer. */
                CanNm_SetPnClusterReq(pnClusterRequestByte, CANNM_ZERO);
                CanNm_SetPnClusterReqNew(pnClusterRequestByte, CANNM_ZERO);

                for( pnClusterRequestBit = CANNM_ZERO;
                    pnClusterRequestBit < CANNM_PN_CLUSTERS_PER_BYTE; pnClusterRequestBit++ )
                {
                    /* Stop all EIRA PnClusterResetTimer. */
                    CanNm_GetPnClusterResetTimer(pnClusterRequestByte)[pnClusterRequestBit] = CANNM_ZERO;
                }
            }
        }
#endif
    }
}
#endif

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_DisablePnFilter
*
* Explanation: Configure Partial Networking Filter Is Disabled.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
static FUNC(void, CANNM_CODE) CanNm_DisablePnFilter(NetworkHandleType channel)
{
    if( (NM_STATE_BUS_SLEEP == CanNm_GetNmState(channel)) && (TRUE == CanNm_IsPnMessageFilterDeactived(channel)) )
    {
        CanNm_SetPnMessageFilterEnabled(channel, FALSE);
        CanNm_SetPnMessageFilterDeactived(channel, FALSE);
    }

#if( CANNM_PN_MESSAGE_FILTER_FORCED_ENABLED == STD_ON )
    CanNm_SetPnMessageFilterEnabled(channel, (boolean)CanNm_IsPnEnabled(channel));
#endif

}
#endif

/*
********************************************************************************
* Function Name: CanNm_TriggerTransmission
*
* Explanation: Trigger Transmission.
*
* param: channel: Identification of the NM-channel.
*
* retval: E_OK: Trigger Transmission success.
*            Any other: Trigger Transmission not success.
********************************************************************************
*/
static FUNC(Std_ReturnType, CANNM_CODE) CanNm_TriggerTransmission
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    /* Local variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 pnClusterRequestByte = CANNM_ZERO;
    PduInfoType nmPduInfo;

#if( CANNM_COM_USER_DATA_SUPPORT == STD_ON )
    nmPduInfo.SduDataPtr = (uint8*)(CanNm_GetAddrTxMessageData(channel,CanNm_GetTxMessageData_UDStartIdx(channel)));
    nmPduInfo.SduLength = CanNm_GetTxMessageData_UDLength(channel);
    (void)PduR_CanNmTriggerTransmit(CanNm_GetTxUserDataPduId(channel), &nmPduInfo);

#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( nmPduInfo.SduLength != (uint16)CanNm_GetTxMessageData_UDLength(channel) )
    {
      (void)Det_ReportError(CANNM_MODULE_ID, channel, CANNM_SID_MAINFUNCTION , CANNM_E_PDUR_TRIGGERTX_ERROR);
    }
#endif

#endif

#if( CANNM_PN_EIRA_CALC_FEATURE_ENABLED == STD_ON )
    /* If PN enabled. */
    if( (boolean)TRUE == CanNm_IsPnEnabled(channel) )
    {
        CanNm_EnterCritical();
        /* Iterate all Pn Cluster Request Bytes. */
        if( NULL_PTR != CanNm_GetEraPnInfo(channel) )
        {
            for( pnClusterRequestByte = CANNM_ZERO; pnClusterRequestByte < CanNm_GetEraPnInfoLength(channel); pnClusterRequestByte++ )
            {
                /* Copy EIRA requests and apply the PN filter mask. */
                CanNm_SetPnClusterReqNew(pnClusterRequestByte,
                    (uint8)(CanNm_GetPnClusterReqNew(pnClusterRequestByte)|
                        ((CanNm_GetTxMessageData(channel, (CanNm_GetTxMsgDataStartIdx(channel)) +
                        (pnClusterRequestByte + CanNm_GetEraPnInfoOffset(channel)))) &
                        CanNm_GetEraPnFilterMask(channel)[pnClusterRequestByte])));
            }
        }
        CanNm_LeaveCritical();
    }
#else
    CANNM_DUMMY_STATEMENT(pnClusterRequestByte);
#endif

    /* Prepare user data for transmission. */
    nmPduInfo.SduDataPtr = CanNm_GetAddrTxMessageData(channel,CanNm_GetTxMsgDataStartIdx(channel));
    nmPduInfo.SduLength = (PduLengthType)CanNm_GetTxMsgDataLength(channel);

#if( CANNM_COM_USER_DATA_SUPPORT == STD_ON )
    /* Clear local transmission request shortly before actual transmission. */
    CanNm_SetMsgRequest(channel, CANNM_NO_TRANSMIT_REQUEST);
#endif

    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( CANNM_0XFFFF != CanNm_GetTxPduRef(channel) )
    {
        //解决NM UserData在发送前没有填充的问题
        Can_NM_UserData_Fill();

#if( CANNM_NM_USER_ENABLE_SUPPORTED == STD_ON )
        //支持NM User Enable功能时，调用CanNm_GetTxUserNMEnable()判断是否允许发送
        if( E_NOT_OK == CanNm_GetTxUserNMEnable() )
        {
            /* Stop Transmit the NM message. */
            retVal = E_OK;
        }else
#endif
        {
            /* Transmit the NM message. */
            retVal = CanIf_Transmit(CanNm_GetTxPduRef(channel), &nmPduInfo);
        }

        if( (uint8)E_OK == retVal )
        {

#if( CANNM_IMMEDIATE_TXCONF_ENABLED == STD_ON )
            /* A flag is used in order to ensure data consistency of the timeout timer. */
            CanNm_SetMsgConfirmationFlag(channel, TRUE);
#else
            /* Start Message Timeout Timer. */
            CanNm_SetMsgTimeoutTimer(channel, (uint16)(CanNm_GetMsgTimeoutTime(channel) + (uint16)CANNM_ONE));
#endif
        }
    }
    return retVal;

}

/*
********************************************************************************
* Function Name: CanNm_LocalInit
*
* Explanation: Service for resetting all internal variables about CanNm.
*
* param: channel: Identification of the NM-channel.
*
* retval: None
********************************************************************************
*/
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
static FUNC(void, CANNM_CODE) CanNm_LocalInit(NetworkHandleType channel)
{
    /* Local variables. */
    uint8       userDataByte;
    uint8       nidPosition;
    uint8       cbvPosition;
    /* Init comm state, default ready sleep. */
    CanNm_SetCommState(channel, COMM_READY_SLEEP);
    /* Reset flags. */
    CanNm_SetNetworkRestartFlag(channel, CANNM_NO_RESTART);
    CanNm_SetMsgIndicationFlag(channel, FALSE);
    CanNm_SetImmediateNmMsgCount(channel, CANNM_ZERO);
    CanNm_SetMsgConfirmationFlag(channel, FALSE);
    CanNm_SetRepeatMsgBitIndFlag(channel, FALSE);
    CanNm_SetRepeatMsgReqFlag(channel, FALSE);
    /* Reset Timers. */
    /* All timers have to be initialized since they are processed in every state. */
    CanNm_SetTimeoutTimer(channel, CANNM_ZERO );
    CanNm_SetWaitBusSleepTimer(channel, CANNM_ZERO );
    CanNm_SetRepeatMsgTimer(channel, CANNM_ZERO );

#if( CANNM_RETRY_FIRST_MESSAGE_REQUEST == STD_ON )
    CanNm_SetRetryFirstMessageRequestFlag(channel, FALSE);
#if( CANNM_IMMEDIATE_RESTART_ENABLED == STD_ON )
    CanNm_SetImmediateRestartFailed(channel, FALSE);
#endif
#endif

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
      /* Reset Remote Sleep Timer and state. */
      CanNm_SetRemoteSleepTimer(channel, CANNM_ZERO );
      CanNm_SetRemoteSleepIndState(channel, FALSE);
#endif

    /* The transmission of NM messages is initially stopped. */
    CanNm_SetMsgTimer(channel, CANNM_ZERO );
    /* Timeout Timer is initially stopped. */
    CanNm_SetMsgTimeoutTimer(channel, CANNM_ZERO );

#if( CANNM_COM_USER_DATA_SUPPORT == STD_ON )
    /* set no transmit request. */
    CanNm_SetMsgRequest(channel, CANNM_NO_TRANSMIT_REQUEST);
#endif

#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
      /* Per default the transmission control status is enabled. */
      CanNm_SetTxControlState(channel, MSG_TX_ENABLED);
      CanNm_SetTxControlStateRequest(channel, MSG_TX_ENABLED);
#endif

#if( CANNM_BUS_LOAD_REDUCTION_ENABLED == STD_ON )
      if( TRUE == CanNm_ChannelConfig[channel].BusLoadReductionActive )
      {
        CanNm_SetBusLoadReductionActive(channel, TRUE);
      }
      else
      {
        CanNm_SetBusLoadReductionActive(channel, FALSE);
      }
#else
        CanNm_SetBusLoadReductionActive(channel, FALSE);
#endif

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
    /* Initialize PN relevant variables. */
    CanNm_PnLocal_Init(channel);
#endif
    /* Initialize User Data with 0x00. */
    for( userDataByte = CanNm_GetTxMsgDataStartIdx(channel);
            userDataByte < CanNm_GetTxMsgDataEndIdx(channel); userDataByte++ )
    {
        CanNm_SetTxMessageData(channel, userDataByte, CANNM_0XFF);
    }
    /* Initialize receive data with oxFF. */
    for( userDataByte = CanNm_GetRxMsgDataStartIdx(channel);
        userDataByte < CanNm_GetRxMsgDataEndIdx(channel); userDataByte++ )
    {
        CanNm_SetRxMessageData(channel, userDataByte, CANNM_0XFF);
    }
    /* If Node Id Enabled is configured and 'Pdu Nid Position' is configured to Byte0 or Byte1
       Initialize Source Node Identifier Byte to the configured Node Id. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( CANNM_PDU_OFF != CanNm_GetPduNidPosition(channel) )
    {
        nidPosition = (uint8)(CanNm_GetTxMsgData_NIDIdx(channel));

        /* Source Node Identifier. */
        CanNm_SetTxMessageData(channel, nidPosition, (uint8)CanNm_GetNodeId(channel));
    }
    /* If 'Pn Enabled' is configured and 'Pdu Cbv Position' is configured to Byte0 or Byte1,
                        Initialize CBV Byte with CRI bit set otherwise initialize CBV to zero. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    if( CANNM_PDU_OFF !=CanNm_GetTxMsgData_CBVIdx(channel) )
    {
        cbvPosition = (uint8)(CanNm_GetTxMsgData_CBVIdx(channel));

        if( (boolean)TRUE == CanNm_IsPnEnabled(channel) )
        {
            CanNm_SetTxMessageData(channel, cbvPosition, CANNM_CRI_BIT_MASK);
        }
        else
        {
            /* ControlBitVector = 0x00, RepeatMessageBit = FALSE. */
            CanNm_SetTxMessageData(channel, cbvPosition, CANNM_ZERO);
        }
    }
    /* Set NmState to default state Bus Sleep without notification of upper layer. */
    CanNm_SetNmState(channel, NM_STATE_BUS_SLEEP);
}

/*
********************************************************************************
* Function Name: CanNm_StateTransition
*
* Explanation: State Transition And Related Operation In Current State.
*
* param: channel: Identification of the NM-channel.
*       nextNmState: Next State Of The State Machine.
*
* retval: None
********************************************************************************
*/
static FUNC(void, CANNM_CODE) CanNm_StateTransition
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel,
    Nm_StateType nextNmState
)
{
    /* Local variables. */
    /* polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
    Nm_StateType  lastNmState = CanNm_GetNmState(channel);

#if( CANNM_IMMEDIATE_RESTART_ENABLED == STD_ON )
    boolean additionalTransmissionRequired = FALSE;
#endif

    /* Update Nm state. */
    CanNm_SetNmState(channel, nextNmState);

    switch(nextNmState)
    {
        /* Transition to Bus Sleep. */
        case NM_STATE_BUS_SLEEP:
            /* Notify Nm Interface that BusSleep mode has been entered. Disable the PN message filtering. */
            Nm_BusSleepMode(CanNm_GetChannelId(channel));

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
            CanNm_SetPnMessageFilterDeactived(channel, TRUE);
#endif
            break;
        /* Transition to Prepare Bus Sleep.  */
        case NM_STATE_PREPARE_BUS_SLEEP:
            /* Notify Nm Interface that PrepareBusSleep mode has been entered. */
            Nm_PrepareBusSleepMode(CanNm_GetChannelId(channel));

            /* Start the WaitBusSleepTimer with WaitBusSleep time. */
            CanNm_SetWaitBusSleepTimer(channel, (uint16)CanNm_GetWaitBusSleepTime(channel));

#if( CANNM_ACTIVE_WUP_BIT_FEATURE_ENABLED == STD_ON )
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( (boolean)TRUE == CanNm_IsActiveWakeupBitEnable(channel) )
            {
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( CANNM_NO_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG != CanNm_GetTxMsgData_CBVIdx(channel) )
                {
                    CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
                          (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) & CANNM_ACT_WU_BIT_INV_MASK));
                }
            }
#endif
            break;
        /* Transition to Ready Sleep */
        case NM_STATE_READY_SLEEP:
            /* Stop NM message timer. */
            CanNm_SetMsgTimer(channel, CANNM_ZERO);

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
            CanNm_SetRemoteSleepTimer(channel, CANNM_ZERO );
#endif
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( CANNM_PDU_OFF != CanNm_GetTxMsgData_CBVIdx(channel) )
            {
                /*  Clear the repeat message bit in CBV */
                CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
                (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) & CANNM_REPEAT_MSG_BIT_INV_MASK));
            }
            /* Stop transmission of Nm Messages with faster cycle time. */
            CanNm_SetImmediateNmMsgCount(channel, CANNM_ZERO);

#if( CANNM_RETRY_FIRST_MESSAGE_REQUEST == STD_ON )
            CanNm_SetRetryFirstMessageRequestFlag(channel, FALSE); /* SBSW_CANNM_CSL_CHANNEL_INDEX_ACCESS */
#endif
            break;

#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
        /* Transition to Normal Operation. */
        case NM_STATE_NORMAL_OPERATION:

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
            if( MSG_TX_ENABLED == CanNm_GetTxControlState(channel) )
#endif /* ( CANNM_COM_CONTROL_ENABLED == STD_ON ) */
            {
              CanNm_SetRemoteSleepTimer(channel, (uint16)(CanNm_GetRemoteSleepIndTime(channel) + 1U));
              CanNm_SetRemoteSleepIndState(channel, FALSE);
            }
#endif /* ( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON ) */

            if( NM_STATE_READY_SLEEP == lastNmState )
            {
#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
                if( MSG_TX_ENABLED == CanNm_GetTxControlState(channel) )
#endif /* CANNM_COM_CONTROL_ENABLED == STD_ON */
                {
                    /* Trigger asynchronous transmission of the NM message. */
                    CanNm_SetMsgTimer(channel, CANNM_ONE);
                }

//RSS -> NOS AWB更新
#if(( CANNM_AWB_RSS_UPDATE_SUPPORTED == STD_ON ) && ( CANNM_ACTIVE_WUP_BIT_FEATURE_ENABLED == STD_ON ))
                /* RSS -> NOS：由主动请求触发（commState 必为 NORMAL），AWB 置位 */
                if( (boolean)TRUE == CanNm_IsActiveWakeupBitEnable(channel) )
                {
                    if( CANNM_NO_TXMESSAGEDATA_CBVIDXOFPBCHANNELCONFIG != CanNm_GetTxMsgData_CBVIdx(channel) )
                    {
                        CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
                            (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) | CANNM_ACT_WU_BIT_MASK));
                    }
                }
#endif                
            }
            else
            {
                /* Clear the repeat message bit in TxMessageData buffer. */
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( CANNM_PDU_OFF != CanNm_GetTxMsgData_CBVIdx(channel) )
                {
                    CanNm_SetTxMessageData(channel, (CanNm_GetTxMsgData_CBVIdx(channel)),
                    (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) & CANNM_REPEAT_MSG_BIT_INV_MASK));
                }
            }
            break;
#endif /* ( CANNM_PASSIVE_MODE_ENABLED == STD_OFF ) */
        default:
            /* Transition to Repeat Message. */
            CanNm_TransitionToRepeatMessage(channel);
            /* Additional actions when entering Network Mode. */
            CanNm_TransitionToNetworkMode(channel, lastNmState);

#if( CANNM_IMMEDIATE_RESTART_ENABLED == STD_ON )
              if( (NM_STATE_PREPARE_BUS_SLEEP == lastNmState) &&
                  (CANNM_ONE < CanNm_GetMsgTimer(channel)) &&
                  (CANNM_ACTIVE_RESTART == CanNm_GetNetworkRestartFlag(channel)) )
              {
                additionalTransmissionRequired = TRUE;
              }
#endif
            /* Clear NetworkRestartFlag. */
            CanNm_SetNetworkRestartFlag(channel, CANNM_NO_RESTART);
            break;
    }

#if( CANNM_STATE_CHANGE_IND_ENABLED == STD_ON )
      /* #20 Notify Nm Interface that state has changed. */
      if ( lastNmState != nextNmState )
      {
        Nm_StateChangeNotification(CanNm_GetChannelId(channel), lastNmState, nextNmState);
      }
#endif

#if( CANNM_IMMEDIATE_RESTART_ENABLED == STD_ON )
    if( (boolean)TRUE == additionalTransmissionRequired )
    {
        Std_ReturnType retVal;
        retVal = CanNm_TriggerTransmission(channel);

#if( CANNM_RETRY_FIRST_MESSAGE_REQUEST == STD_ON )
        if( (boolean)TRUE ==CanNm_IsRetryFirstMessageRequestFlag(channel) ) /* COV_CANNM_RETRY_FIRST_MESSAGE_REQUEST_ENABLED */
        {
          if ( E_NOT_OK == retVal )
          {
            /* MsgTimer = 2 since the MsgTimer Handling is done later in the main function and a transmit request was already
             * processed during the current main function cycle. */
            CanNm_SetMsgTimer(channel, CANNM_TWO);
            CanNm_SetImmediateRestartFailed(channel, TRUE);
          }
          else
          {
            CanNm_SetRetryFirstMessageRequestFlag(channel, FALSE);
          }
        }
#endif
        CANNM_DUMMY_STATEMENT(retVal);
    }
#endif
}

/*
********************************************************************************
* Function Name: CanNm_Init
*
* Explanation: Initialize the CanNm module, must be called after initialization of the CanIf.
*
* param: cannmConfigPtr: Pointer to a selected configuration structure.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANNM_CODE) CanNm_Init
(
    P2CONST(CanNm_ConfigType, AUTOMATIC, CANNM_APPL_CONST) cannmConfigPtr
)
{
    /* Local variables. */
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel;
    uint8 errorId = CANNM_E_NO_ERROR;
    /* Dummy parameter. */
    CANNM_DUMMY_STATEMENT(cannmConfigPtr);

    if( CANNM_INIT == CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_INIT_FAILED;
#endif
    }
    else
    {
        for( channel=CANNM_ZERO; channel<CanNm_GetSizeOfChannelConfig(); channel++ )
        {
            /* Call CanNm_LocalInit to initialize all global and local variables. */
            CanNm_LocalInit(channel);
        }
        /* Init CanNm moudle. */
        CanNm_ModuleInitState = CANNM_INIT;
    }
        /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_INIT, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif /* CANNM_DEV_ERROR_DETECT */
}

/*
********************************************************************************
* Function Name: CanNm_PassiveStartUp
*
* Explanation: Passive startup of the AUTOSAR CAN NM. It triggers the transition from
*           BusSleep Mode or Prepare Bus Sleep Mode to the Network Mode in Repeat Message
*           State.
*
* param: nmChannelHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*       E_NOT_OK: Passive startup of network management has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_PassiveStartUp
(
    NetworkHandleType nmChannelHandle
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;
    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_INVALID_CHANNEL;
#endif
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        if( (NM_STATE_BUS_SLEEP == CanNm_GetNmState(channel)) || (NM_STATE_PREPARE_BUS_SLEEP == CanNm_GetNmState(channel)) )
        {

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
            /* Deactivate Pn Message Filtering (Bus Sleep only). */
            CanNm_DisablePnFilter(channel);
#endif
            /* network was not actively requested */
            if( CANNM_NO_RESTART == CanNm_GetNetworkRestartFlag(channel) )
            {
                /* Set NetworkRestartFlag to passive restart for further handling in main function. */
                CanNm_SetNetworkRestartFlag(channel, CANNM_PASSIVE_RESTART);
            }
            retVal = E_OK;
        }
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_PASSIVESTARTUP, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}

#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
/*
********************************************************************************
* Function Name: CanNm_NetworkRequest
*
* Explanation: Request the network, since ECU needs to communicate on the bus.
*
* param: nmChannelHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*       E_NOT_OK: Requesting of network has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_NetworkRequest
(
    NetworkHandleType nmChannelHandle
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else if( (nmChannelHandle >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_INVALID_CHANNEL;
#endif
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /* Set internal communication flag to NormalOperation. */
        CanNm_SetCommState(channel, COMM_NORMAL_OPERATION);

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
        /* Deactivate Pn Message Filtering. */
        CanNm_DisablePnFilter(channel);
#endif
        /* Ensure Start-Up. */
        if( (CANNM_NO_RESTART == CanNm_GetNetworkRestartFlag(channel)) && ((NM_STATE_READY_SLEEP > CanNm_GetNmState(channel))

#if( (CANNM_PN_FEATURE_ENABLED == STD_ON) && (CANNM_PN_HANDLE_MULTIPLE_NETWORK_REQUEST == STD_ON) )
            || ((TRUE == CanNm_IsPnEnabled(channel)) && (TRUE == CanNm_IsPnHandleMultipleNetworkRequest(channel)) )
#endif
        ))
        {
            /* Set NetworkRestartFlag to active restart for further handling in main function. */
            CanNm_SetNetworkRestartFlag(channel, CANNM_ACTIVE_RESTART);
        }
        retVal = E_OK;
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_NETWORKREQUEST, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CanNm_NetworkRelease
*
* Explanation: Release the network, since ECU doesn't have to communicate on the bus.
*
* param: nmChannelHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*      E_NOT_OK: Releasing of network has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_NetworkRelease
(
    NetworkHandleType nmChannelHandle
)
{
    /* Local Variables. */
    Std_ReturnType  retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
             (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_INVALID_CHANNEL;
#endif
    }
    else
    {
#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /*Set internal communication flag to ReadySleep. */
        CanNm_SetCommState(channel, COMM_READY_SLEEP);

        retVal = E_OK;
#endif
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_NETWORKRELEASE, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* ( CANNM_DEV_ERROR_DETECT == STD_ON ) */

    return retVal;
}
#endif  /* ( CANNM_PASSIVE_MODE_ENABLED == STD_OFF ) */

#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_DisableCommunication
*
* Explanation: Disable the NM PDU transmission ability due to a ISO14229 Communication
*            Control (28hex) service.
*
* param: nmChannelHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*       E_NOT_OK: Disabling of NM PDU transmission ability has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_DisableCommunication
(
    NetworkHandleType nmChannelHandle
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_INVALID_CHANNEL;
#endif
    }
    else
    {
#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        if( NM_STATE_PREPARE_BUS_SLEEP < CanNm_GetNmState(channel) )
        {
            CanNm_SetTxControlStateRequest(channel, MSG_TX_DISABLED);
            retVal = E_OK;
        }
#endif
    }

    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_DISABLECOMMUNICATION, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CanNm_EnableCommunication
*
* Explanation: Enable the NM PDU transmission ability due to a ISO14229 Communication
*            Control (28hex) service.
*
* param: nmChannelHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*       E_NOT_OK: Enabling of NM PDU transmission ability has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_EnableCommunication
(
    NetworkHandleType nmChannelHandle
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_INVALID_CHANNEL;
#endif
    }
    else
    {
#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        if( NM_STATE_PREPARE_BUS_SLEEP < CanNm_GetNmState(channel) )
        {
            if( MSG_TX_DISABLED == CanNm_GetTxControlState(channel) )
            {
                CanNm_SetTxControlStateRequest(channel, MSG_TX_ENABLED);
            }
            retVal = E_OK;
        }
#endif
    }

    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_ENABLECOMMUNICATION, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif  /* ( CANNM_COM_CONTROL_ENABLED == STD_ON ) */

#if( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_CONTROL_ENABLED == STD_ON) )
/*
********************************************************************************
* Function Name: CanNm_CommunicationControlHandling
*
* Explanation: Handle the com control.
*
* param: channel: Channel of CanNm.
*
* retval: E_OK: No error.
*         E_NOT_OK: Setting of user data has failed.
********************************************************************************
*/

static FUNC(void, CANNM_CODE) CanNm_CommunicationControlHandling
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel
)
{
    uint8 txCtlSta;

    txCtlSta = CanNm_GetTxControlStateRequest(channel);
    if( CanNm_GetTxControlState(channel) != txCtlSta )
    {
        CanNm_SetTxControlState(channel, txCtlSta);

        if( MSG_TX_DISABLED == txCtlSta )
        {
            CanNm_SetTimeoutTimer(channel, CANNM_ZERO);
            CanNm_SetMsgTimer(channel, CANNM_ZERO);

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
            CanNm_SetRemoteSleepTimer(channel, CANNM_ZERO );
            CanNm_SetRemoteSleepIndState(channel, FALSE);
#endif
        }
        else
        {
            CanNm_SetTimeoutTimer(channel, (uint16)(CanNm_GetTimeoutTime(channel) + (uint16)CANNM_ONE));
            if( (NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel)) || (NM_STATE_REPEAT_MESSAGE == CanNm_GetNmState(channel)) )
            {
                CanNm_SetMsgTimer(channel, (uint16)(CanNm_GetMsgCycleOffset(channel) + (uint16)CANNM_ONE));
            }

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
            if( NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel) )
            {
                CanNm_SetRemoteSleepTimer(channel, (uint16)(CanNm_GetRemoteSleepIndTime(channel) + 1U));
            }
#endif
        }
    }
}
#endif  /* ( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_CONTROL_ENABLED == STD_ON) ) */

#if(CANNM_USER_DATA_ENABLED == STD_ON)
#if( (CANNM_COM_USER_DATA_SUPPORT == STD_OFF)&&(CANNM_PASSIVE_MODE_ENABLED == STD_OFF) )
/*
********************************************************************************
* Function Name: CanNm_SetUserData
*
* Explanation: Set user data for NM PDUs transmitted next on the bus.
*
* param: nmChannelHandle: Identification of the NM-channel.
*       nmUserDataPtr: Pointer where the user data for the next transmitted NM PDU
*                       shall be copied from.
*
* retval: E_OK: No error.
*      E_NOT_OK: Setting of user data has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetUserData
(
    NetworkHandleType nmChannelHandle,
    P2CONST(uint8, AUTOMATIC, CANNM_APPL_CONST) nmUserDataPtr
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;
    uint8 txMesssageDataByte = CANNM_ZERO;
    uint8 userDataByte = CANNM_ZERO;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( NULL_PTR == nmUserDataPtr )  /* Check pointer NULL. */
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else
    {
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        userDataByte = CANNM_ZERO;
        CanNm_EnterCritical();
        for( txMesssageDataByte = CanNm_GetTxMsgData_UserDataStartIdx(channel);
            txMesssageDataByte < CanNm_GetTxMsgData_UserDataEndIdx(channel);txMesssageDataByte++ )
        {
            CanNm_SetTxMessageData(channel, txMesssageDataByte, nmUserDataPtr[userDataByte]);
            userDataByte++;
        }
        CanNm_LeaveCritical();
        retVal = E_OK;
    }

    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_SETUSERDATA, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif
#endif

#if( CANNM_USER_DATA_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_GetUserData
*
* Explanation: Get user data out of the most recently received NM PDU.
*
* param: nmChannelHandle: Identification of the NM-channel.
*       nmUserDataPtr: Pointer where user data out of the most recently received NM
*                       PDU shall be copied to.
*
* retval: E_OK: No error.
*       E_NOT_OK: Getting of user data has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetUserData
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;
    uint8 userDataByte;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else if( NULL_PTR == nmUserDataPtr )  /* Check pointer NULL. */
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else
    {
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /* Iterate all user data bytes. */
        for( userDataByte = CANNM_ZERO; userDataByte < CanNm_GetRxMsgData_UserDataLength(channel); userDataByte++ )
        {
            /* Return user data from last received Nm message. */
            nmUserDataPtr[userDataByte] = CanNm_GetRxMessageData(channel,CanNm_GetRxMsgData_UserDataStartIdx(channel) + userDataByte);
        }

        retVal = E_OK;
    }

    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_GETUSERDATA, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif  /* (CANNM_USER_DATA_ENABLED == STD_ON) */

#if( (CANNM_COM_USER_DATA_SUPPORT == STD_ON) || (CANNM_PN_FEATURE_ENABLED == STD_ON) )
/*
********************************************************************************
* Function Name: CanNm_Transmit
*
* Explanation: This function is used by the PduR to trigger a spontaneous transmission of an
*               NM PDU with the provided NM User Data.
*
* param: CanNmTxPduId: Handle of the CanNm user data PDU.
*       PduInfoPtr: Pointer to a structure containing the pointer to the NM user
*                   data buffer and the related DLC.
*
* retval: E_OK: Transmit request has been accepted.
*       E_NOT_OK: Transmit request has not been accepted.
*                       (CanNm is not in Repeat Message or Normal Operation State)
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_Transmit
(
    PduIdType CanNmTxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
)
{
    /* Local Variables */
    Std_ReturnType retVal= E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    uint8 channel;

    for( channel = CANNM_ZERO; channel < CanNm_GetSizeOfChannelConfig(); channel++ )
    {
        if( CanNmTxPduId == CanNm_GetTxPduId(channel) )
        {
            break;
        }
    }
    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( channel >= CanNm_GetSizeOfChannelConfig() )
    {
        errorId = CANNM_E_INVALID_PDUID;
    }
    else if( NULL_PTR == PduInfoPtr )  /* Check pointer NULL. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else
    {
        CANNM_DUMMY_STATEMENT(PduInfoPtr);

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
        /* If Partial Networking is enabled. */
        if( (boolean)TRUE == CanNm_IsPnEnabled(channel) )
#endif
        {
            /* CanNm state in normal or in repeat message. */
            if( ((NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel))
                    || (NM_STATE_REPEAT_MESSAGE == CanNm_GetNmState(channel)))

#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
                    && ( MSG_TX_ENABLED == CanNm_GetTxControlState(channel) )
#endif
                    )
            {
                /* Trigger transmission in next main function call. */
                CanNm_SetMsgRequest(channel, CANNM_TRANSMIT_REQUEST);
                retVal = E_OK;
            }
        }

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
        else
        {
            retVal = E_OK;
        }
#endif

    }
    /* Dev error report */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_TRANSMIT, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif  /* (CANNM_USER_DATA_ENABLED == STD_ON) || (CANNM_PN_FEATURE_ENABLED == STD_ON) */

#if( CANNM_NODE_ID_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_GetNodeIdentifier
*
* Explanation: Get node identifier out of the most recently received NM PDU.
*
* param: nmChannelHandle: Identification of the NM-channel.
*       nmNodeIdPtr: Pointer to where to store Node ID.
*
* retval: E_OK: No error.
*      Any other: Getting of the node identifier out of the most recently received NM PDU has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetNodeIdentifier
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmNodeIdPtr
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else if( NULL_PTR == nmNodeIdPtr )  /* Check pointer NULL. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /* NodeIdentifier position is configured to Byte0 or Byte1. */
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( CANNM_PDU_OFF != CanNm_GetPduNidPosition(channel) )
        {
            /* Return the current Node Identifier from the last received NM message. */
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
            *nmNodeIdPtr = CanNm_GetRxMessageData(channel,CanNm_GetRxMsgData_NIDIdx(channel));
            retVal = E_OK;
        }
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_GETNODEIDENTIFIER, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}

/*
********************************************************************************
* Function Name: CanNm_GetLocalNodeIdentifier
*
* Explanation: Get node identifier configured for the local node.
*
* param: nmChannelHandle: Identification of the NM-channel.
*       nmNodeIdPtr:Pointer to where to store Node ID.
*
* retval: E_OK: No error.
*       Any other: Getting of the node identifier out of the most recently received NM PDU has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetLocalNodeIdentifier
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmNodeIdPtr
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else if( NULL_PTR == nmNodeIdPtr )  /* Check pointer NULL. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /* Return Node ID from configuration. */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
        *nmNodeIdPtr = CanNm_GetNodeId(channel);
        retVal = E_OK;
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_GETLOCALNODEIDENTIFIER, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif  /* ( CANNM_NODE_ID_ENABLED == STD_ON ) */

#if( CANNM_NODE_DETECTION_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_RepeatMessageRequest
*
* Explanation: Set Repeat Message Request Bit for NM PDUs transmitted next on the bus.
*
* param: nmChannelHandle: Identification of the NM-channel.
*
* retval: E_OK: No error
*       E_NOT_OK: Setting of Repeat Message Request Bit has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_RepeatMessageRequest
(
    NetworkHandleType nmChannelHandle
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /* If current state is ReadySleep or NormalOperation. Request Transition to Repeat Message State. */
        if( (NM_STATE_READY_SLEEP == CanNm_GetNmState(channel)) || (NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel)) )
        {
            CanNm_SetRepeatMsgReqFlag(channel, TRUE);
            retVal =  E_OK;
        }
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_REPEATMESSAGEREQUEST, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif

#if( (CANNM_NODE_DETECTION_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) || (CANNM_NODE_ID_ENABLED == STD_ON) )
/*
********************************************************************************
* Function Name: CanNm_GetPduData
*
* Explanation: Get the whole PDU data out of the most recently received NM PDU.
*
* param: nmChannelHandle: Identification of the NM-channel.
*       nmPduDataPtr: Pointer To where To store NM PDU.
*
* retval: E_OK: No error.
*        Any other: Getting of NM PDU data has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetPduData
(
    NetworkHandleType nmChannelHandle,
    P2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmPduDataPtr
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;
    uint8 msgDataByte;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else if( NULL_PTR == nmPduDataPtr )  /* Check pointer NULL. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /* Iterate all data bytes of last received Nm message. */

#if( CANNM_USER_DATA_ENABLED == STD_OFF )
        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
        if( (boolean)TRUE == CanNm_IsNodeIdEnabled(channel) )
#endif
        {
            CanNm_EnterCritical();
            for( msgDataByte = CANNM_ZERO; msgDataByte < CanNm_GetRxMsgDataLength(channel); msgDataByte++ )
            {
                /* Return current PDU data. */
                /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
                nmPduDataPtr[msgDataByte] = CanNm_GetRxMessageData(channel,(CanNm_GetRxMsgDataStartIdx(channel)) + (msgDataByte));
            }
            CanNm_LeaveCritical();
            retVal = E_OK;
        }
    }

    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_GETPDUDATA, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif

/*
********************************************************************************
* Function Name: CanNm_GetState
*
* Explanation: Set Network Mode According To Get State.
*
* param: nmChannelHandle: Identification of the NM-channel.
*       nmStatePtr: Pointer to where to store CanNm State.
*       nmModePtr: Pointer to where to store Network Mode.
*
* retval: E_OK: Function has been Processed successfully.
*         Any other: Function has been Processed unsuccessfully.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetState
(
    NetworkHandleType nmChannelHandle,
    P2VAR(Nm_StateType, AUTOMATIC, CANNM_APPL_DATA) nmStatePtr,
    P2VAR(Nm_ModeType, AUTOMATIC, CANNM_APPL_DATA) nmModePtr
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_INVALID_CHANNEL;
#endif
    }
    else if( (NULL_PTR==nmStatePtr) || (NULL_PTR==nmModePtr) )  /* Check pointer. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_PARAM_POINTER;
#endif
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /* Return current CanNm state in passed <nmStatePtr> parameter. */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
        *nmStatePtr = CanNm_GetNmState(channel);

        /* If CanNm state is BusSleep, Return 'Bus Sleep Mode'. */
        if( NM_STATE_BUS_SLEEP == CanNm_GetNmState(channel) )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
            *nmModePtr = NM_MODE_BUS_SLEEP;
        }
        /* If CanNm state is PrepareBusSleep, Return 'Prepare Bus Sleep Mode'. */
        else if( NM_STATE_PREPARE_BUS_SLEEP == CanNm_GetNmState(channel) )
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
            *nmModePtr = NM_MODE_PREPARE_BUS_SLEEP;
        }
        /* in all other cases, Return 'Network Mode'. */
        else
        {
            /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
            *nmModePtr = NM_MODE_NETWORK;
        }
        retVal = E_OK;
    }

    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_GETSTATE, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}

#if( CANNM_VERSION_INFO_API == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_GetVersionInfo
*
* Explanation: Get cannm module version info.
*
* param: versioninfo: Pointer point to VersionInfoType.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANNM_CODE) CanNm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CANNM_APPL_DATA) versioninfo
)
{
    /* Local Variables. */
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( NULL_PTR == versioninfo )  /* Check that module is initialized. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else
    {
        /* Return vendor ID, module ID and version data. */
        /* polyspace +1 DEFECT:TAINTED_PTR [Justified:Unset] "NSCA_Polyspace_CanNm_TAINTED_PTR" polyspace +1 MISRA-C3:D4.14 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.14" */
        versioninfo->vendorID = (uint16)CANNM_VENDOR_ID;
        versioninfo->moduleID = (uint8)CANNM_MODULE_ID;
        versioninfo->sw_major_version = (uint8)CANNM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)CANNM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)CANNM_SW_PATCH_VERSION;
    }

    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_GETVERSIONINFO, errorId);
    }
#else
        CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */
}
#endif  /* CANNM_VERSION_INFO_API */

#if( (CANNM_BUS_SYNCHRONIZATION_ENABLED == STD_ON) && (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) )
/*
********************************************************************************
* Function Name: CanNm_RequestBusSynchronization
*
* Explanation: Request bus synchronization.
*
* param: nmChannelHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*       E_NOT_OK: Requesting of bus synchronization has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_RequestBusSynchronization
(
    NetworkHandleType nmChannelHandle
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else
    {
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        if( (NM_STATE_BUS_SLEEP != CanNm_GetNmState(channel)) &&
        (NM_STATE_PREPARE_BUS_SLEEP != CanNm_GetNmState(channel))
#if( CANNM_COM_CONTROL_ENABLED == STD_ON )
          && ( MSG_TX_ENABLED == CanNm_GetTxControlState(channel) )
#endif
       )
        {
          retVal = CanNm_TriggerTransmission(channel);
        }
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_REQUESTBUSSYNCHRONIZATION, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif

#if( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_CheckRemoteSleepIndication
*
* Explanation: Check if remote sleep indication takes place or not.
*
* param: nmChannelHandle: Identification of the NM-channel.
*
* retval: E_OK: No error.
*       E_NOT_OK: Checking of remote sleep indication bits has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_CheckRemoteSleepIndication
(
    NetworkHandleType nmChannelHandle,
    P2VAR(boolean, AUTOMATIC, CANNM_APPL_DATA) nmRemoteSleepIndPtr
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else if( NULL_PTR == nmRemoteSleepIndPtr )
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else
    {
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        if( (NM_STATE_READY_SLEEP == CanNm_GetNmState(channel)) ||
            (NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel)) )
        {
          /* Provide information about current status of remote sleep indication. */
          *nmRemoteSleepIndPtr = (boolean)CanNm_IsRemoteSleepIndState(channel);
          retVal = E_OK;
        }
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_CHECKREMOTESLEEPIND, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif /* ( CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON ) */

#if( CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_SetSleepReadyBit
*
* Explanation: Check if remote sleep indication takes place or not.
*
* param: nmChannelHandle: Identification of the NM-channel.
*       nmSleepReadyBit: Value written to ReadySleep Bit in CBV.
*
* retval: E_OK: No error.
*       E_NOT_OK: Writing of remote sleep indication bit has failed.
********************************************************************************
*/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetSleepReadyBit
(
    NetworkHandleType nmChannelHandle,
    boolean nmSleepReadyBit
)
{
    /* Local Variables. */
    Std_ReturnType retVal = E_NOT_OK;
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else if( CANNM_ONE < nmSleepReadyBit )
    {
        errorId = CANNM_E_PARAM_POINTER;
    }
    else
    {
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        if( CANNM_PDU_OFF !=CanNm_GetTxMsgData_CBVIdx(channel) )
        {
            if( (boolean)TRUE == nmSleepReadyBit )
            {
                CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
                    (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) | NM_COORD_BIT_SLEEP));
            }
            else
            {
                CanNm_SetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel),
                    (uint8)(CanNm_GetTxMessageData(channel, CanNm_GetTxMsgData_CBVIdx(channel)) & NM_COORD_BIT_INV_SLEEP));
            }
        }
        if( ((NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel)) ||
              (NM_STATE_REPEAT_MESSAGE == CanNm_GetNmState(channel)))

#if ( CANNM_COM_CONTROL_ENABLED == STD_ON )
            && (MSG_TX_ENABLED == CanNm_GetTxControlState(channel))
#endif
        )
      {
        CanNm_SetMsgRequest(channel, CANNM_TRANSMIT_REQUEST);
      }
        retVal = E_OK;
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_SETSLEEPREADYBIT, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

    return retVal;
}
#endif  /* ( CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON ) */

#if( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_IMMEDIATE_TXCONF_ENABLED == STD_OFF) )
/*
********************************************************************************
* Function Name: CanNm_TxConfirmation
*
* Explanation: The lower layer communication interface module confirms the transmission of an IPDU.
*
* param: TxPduId: ID of the I-PDU that has been transmitted.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANNM_CODE) CanNm_TxConfirmation(PduIdType TxPduId)
{
    /* Local Variables. */
    uint8 errorId = CANNM_E_NO_ERROR;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel;  /* channel = (NetworkHandleType)TxPduId */

    for( channel = CANNM_ZERO; channel < CanNm_GetSizeOfChannelConfig(); channel++)
    {
        if( TxPduId == CanNm_GetTxPduRef(channel) )
        {
            break;
        }
    }
    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else if( channel >= CanNm_GetSizeOfChannelConfig() )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_INVALID_PDUID;
#endif
    }
    else
    {
        /* Set Message Confirmation Flag for further handling in CanNm_MainFunction,  Confirm User Data Transmission.*/
        CanNm_SetMsgConfirmationFlag(channel, TRUE);

#if( CANNM_COM_USER_DATA_SUPPORT == STD_ON )
        PduR_CanNmTxConfirmation(CanNm_GetTxUserDataPduId(channel));
#endif
    }
    /* Dev error report */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_TXCONFIRMATION, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

}
#endif

/*
********************************************************************************
* Function Name: CanNm_RxIndication
*
* Explanation: Indication of a received I-PDU from a lower layer communication interface module.
*
* param: RxPduId:This type serve as a unique identifier of a PDU within a software module.
*       PduInfoPtr: Pointer To Where to store the basic information about a PDU of any type.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANNM_CODE) CanNm_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr
)
{
    /* Local Variables. */
    uint8  errorId = CANNM_E_NO_ERROR;
    uint8  controlBitVector = CANNM_ZERO;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    uint8  channel;
    uint8  num;

    CANNM_DUMMY_STATEMENT(controlBitVector);
    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else if( NULL_PTR == PduInfoPtr )  /* Check pointer NULL. */
    /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_PARAM_POINTER;
#endif
    }
    else
    {
        for( channel = CANNM_ZERO; channel < CanNm_GetSizeOfChannelConfig(); channel++ )
        {
            for( num = CANNM_ZERO; num < CanNm_GetChToRxPduIdSize(channel); num++ )
            {
                if( RxPduId == CanNm_GetChToRxPduId(channel,num) )
                {
                    break;
                }
            }
            if( num < CanNm_GetChToRxPduIdSize(channel) )
            {
                break;
            }
        }
        if( channel >= CanNm_GetSizeOfChannelConfig() )
        {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
            errorId = CANNM_E_INVALID_PDUID;
#endif
        }
        else
        {
            /* Check CANNM_E_NET_START_IND. */
            if( NM_STATE_BUS_SLEEP == CanNm_GetNmState(channel) )
            {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
                errorId = CANNM_E_NET_START_IND;
#endif
            }
            /* Judge is relevant msg or is PnFilter enabled. */

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
            if( ((boolean)TRUE == CanNm_PnFilterHandling(channel, PduInfoPtr)) ||

#if( CANNM_ALL_MSG_KEEP_AWAKE_ENABLED == STD_ON )
                 ( (boolean)TRUE == CanNm_IsAllMessagesKeepAwakeEnabled(channel)) ||
#endif

                 ( (boolean)FALSE == CanNm_IsPnMessageFilterEnabled(channel)) )
#endif
            {

#if( (CANNM_NODE_ID_ENABLED == STD_ON) || (CANNM_USER_DATA_ENABLED == STD_ON) \
    || (CANNM_CAR_WUP_RX_FEATURE_ENABLED == STD_ON) )

#if( (CANNM_USER_DATA_ENABLED == STD_OFF) && (CANNM_CAR_WUP_RX_FEATURE_ENABLED == STD_OFF) )
                if( (boolean)TRUE == CanNm_IsNodeIdEnabled(channel) )
#endif
                {
                    /* Copy received NM message data to the Rx Message Data buffer. */
                    CanNm_CopyRxMessageData( channel, PduInfoPtr );
                }
#endif

#if( ( CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON ) || (( CANNM_NODE_DETECTION_ENABLED == STD_ON ) && ( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )) )
                /* If configuration parameter <Pdu Cbv Position> is set to Byte 0 or Byte 1. */
                /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                if( CANNM_PDU_OFF != CanNm_GetPduCbvPosition(channel) )
                {
                    /* Store the CBV Byte. */
                    controlBitVector = (uint8)(PduInfoPtr->SduDataPtr[CanNm_GetPduCbvPosition(channel)]);

                    #if ( CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED == STD_ON )
                    //同睡同醒
                    for(uint8 channel_LO = 0; channel_LO < CanNm_GetSizeOfChannelConfig(); channel_LO++)
                    {
                        if( (NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel_LO)) || (NM_STATE_READY_SLEEP == CanNm_GetNmState(channel_LO)) )
                        {
                            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                            if( (boolean)TRUE == CanNm_IsNodeDetectionEnabled(channel_LO) )
                            {
                                if( (boolean)TRUE != CanNm_IsRepeatMsgBitIndFlag(channel_LO) )
                                {
                                    /* Set the Repeat Message Indication flag in order to notify it to the Nm Interface in next main function. */
                                    CanNm_SetRepeatMsgBitIndFlag(channel_LO, (boolean)(controlBitVector & CANNM_REPEAT_MSG_BIT_MASK));
                                }
                            }
                        }
                    }
                    #else
                    if( (NM_STATE_NORMAL_OPERATION == CanNm_GetNmState(channel)) || (NM_STATE_READY_SLEEP == CanNm_GetNmState(channel)) )
                    {
                        /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
                        if( (boolean)TRUE == CanNm_IsNodeDetectionEnabled(channel) )
                        {
                            if( (boolean)TRUE != CanNm_IsRepeatMsgBitIndFlag(channel) )
                            {
                                /* Set the Repeat Message Indication flag in order to notify it to the Nm Interface in next main function. */
                                CanNm_SetRepeatMsgBitIndFlag(channel, (boolean)(controlBitVector & CANNM_REPEAT_MSG_BIT_MASK));
                            }
                        }
                    }
                    #endif

#if( CANNM_COORDINATOR_SYNC_SUPPORT == STD_ON )
                    /* Call CoordReadyToSleepHandling. */
                    CanNm_CoordReadyToSleepHandling(channel, controlBitVector);
#endif
                }
#endif

#if ( CANNM_CAR_WUP_RX_FEATURE_ENABLED == STD_ON )
                /* #320 Car Wakeup Indication Handing. */
                CanNm_CarWakeupIndication(channel, PduInfoPtr);
#endif

                
                // CanNm_SetMsgIndicationFlag(channel, TRUE);
                #if ( CANNM_BOTH_WAKEUP_AND_SLEEP_SUPPORTED == STD_ON )
                //同睡同醒
                /* Further Message Reception is processed in CanNm_MainFunction. */
                for(uint8 channel_LO = 0; channel_LO < CanNm_GetSizeOfChannelConfig(); channel_LO++)
                {
                    CanNm_SetMsgIndicationFlag(channel_LO, TRUE);
                }
                #else
                /* Further Message Reception is processed in CanNm_MainFunction. */
                CanNm_SetMsgIndicationFlag(channel, TRUE);
                #endif


#if( CANNM_PDU_RX_INDICATION_ENABLED == STD_ON )
                /* Notify NM Interface that a Nm message has been received. */
                Nm_PduRxIndication(CanNm_GetChannelId(channel));
#endif
            }
        }
    }
    /* CanNM_Message_Receive */
    CanNM_Message_Receive = TRUE;
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_RXINDICATION, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

}

#if( CANNM_PN_FEATURE_ENABLED == STD_ON )
/*
********************************************************************************
* Function Name: CanNm_ConfirmPnAvailability
*
* Explanation: Enables the PN filter functionality on the indicated NM channel.
*
* param: nmChannelHandle: Handle Channel.
*
* retval: None
********************************************************************************
*/
FUNC(void, CANNM_CODE) CanNm_ConfirmPnAvailability(NetworkHandleType nmChannelHandle)
{
    /* Local Variables. */
    uint8 errorId = CANNM_E_NO_ERROR;

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
        errorId = CANNM_E_NO_INIT;
    }
    else if( (nmChannelHandle  >= CanNm_GetSizeOfSysToNmChInd()) ||
            (CanNm_GetSysToNmChInd(nmChannelHandle) >= CanNm_GetSizeOfChannelConfig()) )
    {
        errorId = CANNM_E_INVALID_CHANNEL;
    }
    else
    {
        /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" polyspace +1 DEFECT:UNMODIFIED_VAR_NOT_CONST [Justified:Unset] "NSCA_Polyspace_CanNm_UNMODIFIED_VAR_NOT_CONST" */
        NetworkHandleType channel = CanNm_GetSysToNmChInd(nmChannelHandle);
        /* Enable PN message filter. */
        CanNm_SetPnMessageFilterEnabled(channel, (boolean)CanNm_IsPnEnabled(channel));
        CanNm_SetPnMessageFilterDeactived(channel, FALSE);
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_CONFIRMPNAVAILABILITY, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

}
#endif

/*
********************************************************************************
* Function Name: CanNm_GetMessageReceive
*
* Explanation: Service to app for nm message receive.
*
* param: None
*
* retval: None
********************************************************************************
*/
FUNC(boolean, CANNM_CODE) CanNm_GetMessageReceive(void)
{
    boolean nmRecFlag;

    nmRecFlag = CanNM_Message_Receive;
    CanNM_Message_Receive = FALSE;

    return nmRecFlag;
}

/*
********************************************************************************
* Function Name: CanNm_MainFunction
*
* Explanation: Service for performing the processing of the CnmNM jobs.
*
* param: None
*
* retval: None
********************************************************************************
*/
#ifdef VCU_Test_Code_YXP
extern void Test_IO_Turn_LS10(void);
#endif

FUNC(void, CANNM_CODE) CanNm_MainFunction(void)
{
    /* Local variables. */
    uint8 errorId = CANNM_E_NO_ERROR;
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_CanNm_RuleD4.5" */
    NetworkHandleType channel;
    uint8 commState;

    #ifdef VCU_Test_Code_YXP
    Test_IO_Turn_LS10();//测试代码
    #endif

    /* Check module init. */
    if( CANNM_INIT != CanNm_ModuleInitState )
    {
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
        errorId = CANNM_E_NO_INIT;
#endif
    }
    else
    {
        /* Iterate all Nm channels. */
        for( channel = CANNM_ZERO; channel < (NetworkHandleType)CanNm_GetSizeOfChannelConfig(); channel++ )
        {
            /* Process Rx Indication and Tx Confirmation events. */
            CanNm_MainRxTxConfHandling(channel);

#if( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_COM_CONTROL_ENABLED == STD_ON) )
            CanNm_CommunicationControlHandling(channel);
#endif

#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
            /* Copy the global communication state. */
            commState = CanNm_GetCommState(channel);
#endif

#if( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_NODE_DETECTION_ENABLED == STD_ON) )
            /* Process Repeat Message Ind. (if NodeDetectionEnabled enabled) */
            /* polyspace +1 RTE:UNR [Justified:Unset] "NSCA_Polyspace_Common_Unreachable" */
            if( (boolean)TRUE == CanNm_IsNodeDetectionEnabled(channel) )
            {
                CanNm_RepeatMessageIndHandling(channel);
            }
#endif
            /* Process Network Restart. */
            /* If passive or active start-up is requested, Perform a state transition to RepeatMessage (Network Mode). */
            if( CANNM_NO_RESTART !=CanNm_GetNetworkRestartFlag(channel) )
            {
                CanNm_StateTransition(channel,  NM_STATE_REPEAT_MESSAGE);
            }

#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
            /* Process Request or Release bus communication */
            CanNm_BusCommunicationHandling(channel, commState);
#endif
            /* Process NM Timeout Timer. */
            CanNm_TimeoutTimerHandling(channel);
            /* Process Repeat Message Timer. */
            CanNm_RepeatMessageTimerHandling(channel);
            /* Process Wait Bus Sleep Timer. */
            CanNm_WaitBusSleepTimerHandling(channel);

#if( (CANNM_PASSIVE_MODE_ENABLED == STD_OFF) && (CANNM_REMOTE_SLEEP_IND_ENABLED == STD_ON) )
            CanNm_RemoteSleepTimerHandling(channel);
#endif

#if( CANNM_PASSIVE_MODE_ENABLED == STD_OFF )
            /* Process Tx Message Timer. */
            CanNm_MessageTimerHandling(channel);

#if ( CANNM_IMMEDIATE_TXCONF_ENABLED == STD_OFF )
            /* Process Tx Message Timeout Timer. */
            CanNm_MessageTimeoutTimerHandling(channel);
#endif /* ( CANNM_IMMEDIATE_TXCONF_ENABLED == STD_OFF ) */

#endif /* ( CANNM_PASSIVE_MODE_ENABLED == STD_OFF ) */

#if( CANNM_PN_EIRA_CALC_FEATURE_ENABLED == STD_ON )
            /* Calculate Pn Eira (if PnEiraCalcEnabled enabled). */
            CanNm_PnEiraCalculation(channel);
#endif

#if( CANNM_PN_ERA_CALC_FEATURE_ENABLED == STD_ON )
            /* Calculate Pn Era (if PnEraCalcEnabled enabled). */
            CanNm_PnEraCalculation(channel);
#endif
        }  /* Channel Iteration. */
    }
    /* Dev error report. */
#if( CANNM_DEV_ERROR_DETECT == STD_ON )
    if( CANNM_E_NO_ERROR != errorId )
    {
        (void)CANNM_REPORT_DEV_ERROR(CANNM_SID_MAINFUNCTION, errorId);
    }
#else
    CANNM_DUMMY_STATEMENT(errorId);
#endif  /* CANNM_DEV_ERROR_DETECT */

}  /* CanNm_MainFunction */

#define CANNM_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanNm_MemMap.h"  /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
