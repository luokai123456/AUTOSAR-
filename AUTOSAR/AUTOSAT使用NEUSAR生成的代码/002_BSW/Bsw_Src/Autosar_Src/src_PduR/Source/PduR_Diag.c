/*
********************************************************************************
*
*  File name: PduR_Diag.c
*
*  Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: SunHQ/2023.01.24
* Change: New create.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: SunHQ/2023.03.24
* Change: 1.Add verification for dstPduPtr parameter of PduR_Diag_Entry.
*         2.Change the diagnostic status to idle when the timer stops.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: YuHC/2023.04.13
* Change: 1.CCOREDBUG-2618：When a new request arrives and the previous request is
*            a suppression positive response request, start monitoring the new reques.
* Cause: Bugfix
********************************************************************************
* Version: 3.21
* Author/Date: LuQ/2024.04.02
* Change: 1. Modify the comments format.
*         2. Modify P2CONST member labels.
* Cause: Optimization
********************************************************************************
* Version: 3.22
* Author/Date: LuQ/2024.05.13
* Change: Add Memmap segment definition.
* Cause: Optimization
********************************************************************************
* Version: 3.23
* Author/Date: LuQ/2024.09.20
* Change: Modify copyright information.
* Cause: Optimization
********************************************************************************
* Version: 3.24
* Author/Date: LuQ/2024.09.23
* Change: Modify the comments format.
* Cause: Optimization
********************************************************************************
* Version: 3.25
* Author/Date: LuQ/2025.06.17
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: LuQ/2025.06.23
* Change: Modify the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "PduR_Diag.h"

#if (STD_OFF == PDUR_ZERO_COST_OPERATION)

#if (STD_ON == PDUR_SUPPORT_DIAG)

/*
********************************************************************************
*    Local Macros
********************************************************************************
*/
#define PDUR_DIAG_ZERO                              (uint8)(0x00U)
#define PDUR_DIAG_ONE                               (uint8)(0x01U)
#define PDUR_DIAG_NRC78                             (uint8)(0x78U)
#define PDUR_DIAG_NRC7F                             (uint8)(0x7FU)
#define PDUR_DIAG_NRC_NONE                          (uint8)(0x00U)
#define PDUR_DIAG_NRC_ALREADY                       (uint8)(0x01U)
#define PDUR_DIAG_IDLE                              (uint8)(0x00U)
#define PDUR_DIAG_WORKING                           (uint8)(0x01U)
#define PDUR_DIAG_DOUBLE                            (uint8)(0x02U)
#define PDUR_DIAG_SUBFUNREQNUM                      (uint8)(0x0CU)

#define PDUR_UDS_SID_INDEX                          (uint8)(0x00U)
#define PDUR_UDS_NEG_SID_INDEX                      (uint8)(0x01U)
#define PDUR_UDS_NRC_INDEX                          (uint8)(0x02U)
#define PDUR_RES_LENGTH                             (uint8)(0x03U)

#define PDUR_TIMER_STOPPED                          (uint8)(0x00U)
#define PDUR_TIMER_RUNNING                          (uint8)(0x01U)

#define PDUR_UDS_RES_SID_INDEX                      (uint8)(0x01U)

#define PDUR_DIAG_POSISITIVE_RES                    (uint8)(0x00U)
#define PDUR_DIAG_NO_POSISITIVE_RES                 (uint8)(0x01U)
#define PDUR_DIAG_RES_FLAG_BIT                      (uint8)(0x07U)
#define PDUR_DIAG_POSISITIVE_SID                    (uint8)(0xBFU)

#define PDUR_DIAG_RES_DIAGSESSIONCTRL               (uint8)(0x10U)
#define PDUR_DIAG_RES_ECURST                        (uint8)(0x11U)
#define PDUR_DIAG_RES_AECURITYACC                   (uint8)(0x27U)
#define PDUR_DIAG_RES_COMMUNICATIONCTRL             (uint8)(0x28U)
#define PDUR_DIAG_RES_TESTERPRESENT                 (uint8)(0x3EU)
#define PDUR_DIAG_RES_ACCTIMPARM                    (uint8)(0x83U)
#define PDUR_DIAG_RES_CTRLDTCSET                    (uint8)(0x85U)
#define PDUR_DIAG_RES_REQONEVENT                    (uint8)(0x86U)
#define PDUR_DIAG_RES_LINKCTRL                      (uint8)(0x87U)
#define PDUR_DIAG_RES_DYNDEFDATAIDENTIFER           (uint8)(0x2CU)
#define PDUR_DIAG_RES_READDTCINFO                   (uint8)(0x19U)
#define PDUR_DIAG_RES_ROUTINECTRL                   (uint8)(0x31U)

#define PDUR_TIMER_START(timer)                     ((timer).status = PDUR_TIMER_RUNNING)

#define PDUR_TIMER_STOP(timer)                      do { \
                                                        (timer).status = PDUR_TIMER_STOPPED; \
                                                        (timer).counter = PDUR_DIAG_ZERO; \
                                                    } while(0)

#define PDUR_TIMER_RESET(timer)                     do { \
                                                        (timer).status = PDUR_TIMER_RUNNING; \
                                                        (timer).counter = PDUR_DIAG_ZERO; \
                                                    } while(0)

#define PDUR_GET_UDS_SID(dstPduPtr)                 ((uint8)((dstPduPtr)->SduDataPtr[PDUR_UDS_SID_INDEX]))
#define PDUR_GET_UDS_NRC(dstPduPtr)                 ((uint8)((dstPduPtr)->SduDataPtr[PDUR_UDS_NRC_INDEX]))
#define PDUR_GET_RES_UDS_SID(dstPduPtr)             ((uint8)((dstPduPtr)->SduDataPtr[PDUR_UDS_RES_SID_INDEX]))
#define PDUR_GET_UDS_RESFLG(dstPduPtr)              ((uint8)((dstPduPtr)->SduDataPtr[PDUR_UDS_NEG_SID_INDEX]) >> PDUR_DIAG_RES_FLAG_BIT)

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
#define PDUR_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
static boolean PduR_DiagNewReqFlg[PDUR_DIAG_PATH_NUM] = {PDUR_FALSE};
#define PDUR_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

/*
********************************************************************************
*    Local Constants
********************************************************************************
*/
#define PDUR_START_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
static const uint8 PduR_Dig_SubfunReq[PDUR_DIAG_SUBFUNREQNUM] =
{
    PDUR_DIAG_RES_DIAGSESSIONCTRL,
    PDUR_DIAG_RES_ECURST,
    PDUR_DIAG_RES_AECURITYACC,
    PDUR_DIAG_RES_COMMUNICATIONCTRL,
    PDUR_DIAG_RES_TESTERPRESENT,
    PDUR_DIAG_RES_ACCTIMPARM,
    PDUR_DIAG_RES_CTRLDTCSET,
    PDUR_DIAG_RES_REQONEVENT,
    PDUR_DIAG_RES_LINKCTRL,
    PDUR_DIAG_RES_DYNDEFDATAIDENTIFER,
    PDUR_DIAG_RES_READDTCINFO,
    PDUR_DIAG_RES_ROUTINECTRL
};
#define PDUR_STOP_SEC_CONST
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

/*
********************************************************************************
*    Local Functions
********************************************************************************
*/
#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
static FUNC(void, PDUR_CODE) PduR_Diag_ReplyNRC78
(
    uint16 pduId,
    uint8 sid
);

static FUNC(void, PDUR_CODE) PduR_Diag_Handle_Uds
(
    P2VAR(PduR_DiagPathType, AUTOMATIC, PDUR_APPL_DATA) path
);

static FUNC(void, PDUR_CODE) PduR_Diag_Handle_Timer
(
    P2VAR(PduR_DiagPathType, AUTOMATIC, PDUR_APPL_DATA) path
);
static FUNC(Std_ReturnType, PDUR_CODE) PduR_Diag_ChkSubFun
(
    uint8 sid
);
#define PDUR_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

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
#define PDUR_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
extern PduR_DiagPathType PduR_DiagPaths[PDUR_DIAG_PATH_NUM];
#define PDUR_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"

#define PDUR_START_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
/*
********************************************************************************
* Function Name: PduR_Diag_ReplyNRC78
*
* Explanation: Send the NRC78 response code to the corresponding diagnostic unit.
* (Synchronous)
*
* param: pduId-> The ID number of the diagnosis request,
*                 Each time the diagnosis message is forwarded,
*                there will be a unique corresponding ID number.
*         sid-> UDS message field sid number.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, PDUR_CODE) PduR_Diag_ReplyNRC78
(
    uint16 pduId,
    uint8 sid
)
{
    PduInfoType pduInfo;
    uint8 sendBuff[PDUR_RES_LENGTH];

    /* constructing negative response */
    sendBuff[PDUR_UDS_SID_INDEX] = PDUR_DIAG_NRC7F;                        /* 0x7F */
    sendBuff[PDUR_UDS_NEG_SID_INDEX] = sid;                                /* SID */
    sendBuff[PDUR_UDS_NRC_INDEX] = PDUR_DIAG_NRC78;                        /* NRC78 */

    /* constructing a PDU object */
    pduInfo.SduDataPtr = sendBuff;
    pduInfo.SduLength = PDUR_RES_LENGTH;

    (void)PduR_UpTransmit(pduId, &pduInfo);
}
/*
********************************************************************************
* Function Name: PduR_Diag_ChkSubFun
*
* Explanation: Check if this request includes subfunctions.
*
* param:  sid-> UDS message field sid number.
*
* retval: E_OK-> Request contains subfunctions.
          E_NOT_OK-> Request does not include subfunctions.
********************************************************************************
*/
static FUNC(Std_ReturnType, PDUR_CODE) PduR_Diag_ChkSubFun
(
    uint8 sid
)
{
    uint8 reqIdx = PDUR_DIAG_ZERO;
    Std_ReturnType retValue = PDUR_E_NOT_OK;

    for( reqIdx = PDUR_DIAG_ZERO; reqIdx < PDUR_DIAG_SUBFUNREQNUM; reqIdx++ )
    {
        if( sid == PduR_Dig_SubfunReq[reqIdx] )
        {
            retValue = PDUR_E_OK;
            break;
        }
    }
    return retValue;
}
/*
********************************************************************************
* Function Name: PduR_Diag_ReqFlgSet
*
* Explanation: Set the request flag that identifies the current path.
* (Synchronous)
*
* param: pduId-> Identification of the I-PDU corresponding to the received message.
*
* retval: None
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_Diag_ReqFlgSet
(
    PduIdType pduId
)
{
    uint16 pathIdx = PDUR_DIAG_ZERO;

    for( pathIdx = PDUR_DIAG_ZERO; pathIdx < PDUR_DIAG_PATH_NUM; pathIdx++ )
    {
        if( (PduR_DiagPaths[pathIdx].resPduId == pduId) || (PduR_DiagPaths[pathIdx].pduId == pduId) )
        {
            PduR_DiagNewReqFlg[pathIdx] = PDUR_TRUE;
            break;
        }
    }
}
/*
********************************************************************************
* Function Name: PduR_Diag_Entry
*
* Explanation: Each time a message arrives, check to see if it is a diagnostic
*               request or response that needs to be processed.
* (Synchronous)
*
* param: pduId-> Identification of the I-PDU corresponding to the received message.
*         dstPduPtr-> Length and pointer to the buffer of the I-PDU.
*
* retval: None
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_Diag_Entry
(
    PduIdType pduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) dstPduPtr
)
{
    boolean isMatch = PDUR_FALSE;
    uint8 sid = PDUR_DIAG_ZERO;
    uint16 pathIdx = PDUR_DIAG_ZERO;
    PduR_DiagPathType* path = NULL_PTR;

    if( (NULL_PTR != dstPduPtr) && (NULL_PTR != dstPduPtr->SduDataPtr) )
    {
        /* Check for a diagnostic request or response that needs to be processed */
        for( pathIdx = PDUR_DIAG_ZERO; pathIdx < PDUR_DIAG_PATH_NUM; pathIdx++ )
        {
            path = &PduR_DiagPaths[pathIdx];

            /* If there is a diagnostic request */
            if( (path->pduId == pduId) && (PduR_DiagNewReqFlg[pathIdx] == PDUR_TRUE) )
            {
                /* (1) New diagnostic request arrives */
                if( PDUR_DIAG_IDLE == path->uds.status )
                {
                    /* The status is switched to working */
                    path->uds.status = PDUR_DIAG_WORKING;
                    /* Save the SID */
                    path->uds.sid = PDUR_GET_UDS_SID(dstPduPtr);
                    /* Request have subfunctions */
                    if( PDUR_E_OK == PduR_Diag_ChkSubFun(path->uds.sid) )
                    {
                        /* Save the RESFLG */
                        path->uds.resFlag = PDUR_GET_UDS_RESFLG(dstPduPtr);
                    }
                    else
                    {
                        /* Save the RESFLG */
                        path->uds.resFlag = PDUR_DIAG_POSISITIVE_RES;
                    }
                    /* Start p2 and p6 timers */
                    PDUR_TIMER_START(path->timer.p2);             /* Start p2 timer */
                    PDUR_TIMER_START(path->timer.p6);             /* Start p6 timer */
                }
                else if( PDUR_DIAG_WORKING == path->uds.status )
                {
                    sid = PDUR_GET_UDS_SID(dstPduPtr);

                    if( (sid != path->uds.sid) && (path->uds.resFlag == PDUR_DIAG_NO_POSISITIVE_RES) )
                    {
                        /* The status is switched to working */
                        path->uds.status = PDUR_DIAG_WORKING;
                        /* Save the SID */
                        path->uds.sid = PDUR_GET_UDS_SID(dstPduPtr);
                        /* Request have subfunctions */
                        if( PDUR_E_OK == PduR_Diag_ChkSubFun(sid) )
                        {
                            /* Save the RESFLG */
                            path->uds.resFlag = PDUR_GET_UDS_RESFLG(dstPduPtr);
                        }
                        else
                        {
                            /* Save the RESFLG */
                            path->uds.resFlag = PDUR_DIAG_POSISITIVE_RES;
                        }
                    }
                    /* (2) Repeated diagnostic requests arrive, overwrite */
                    path->uds.hasRcvNrc = PDUR_DIAG_NRC_NONE;

                    /* Reset all timers of the current path. why??? */
                    PDUR_TIMER_STOP(path->timer.p2Ex);
                    PDUR_TIMER_STOP(path->timer.p6Ex);
                    PDUR_TIMER_RESET(path->timer.p2);
                    PDUR_TIMER_RESET(path->timer.p6);
                }
                else
                {
                    /* Do nothing */
                }

                isMatch = PDUR_TRUE;
            }
            else if( (path->resPduId == pduId) && (PduR_DiagNewReqFlg[pathIdx] == PDUR_TRUE) )
            {
                if( PDUR_DIAG_NRC7F == PDUR_GET_UDS_SID(dstPduPtr) )
                {
                    sid = PDUR_GET_RES_UDS_SID(dstPduPtr);
                }
                else
                {
                    sid = PDUR_GET_UDS_SID(dstPduPtr) & PDUR_DIAG_POSISITIVE_SID;
                }
                /* If there is a diagnostic response */
                /* (3) When the domain control nrc78 arrives, change the p6 timer to p6* */
                if( (PDUR_DIAG_NRC7F == PDUR_GET_UDS_SID(dstPduPtr)) &&
                    (PDUR_DIAG_NRC78 == PDUR_GET_UDS_NRC(dstPduPtr)) &&
                    (sid == path->uds.sid) )
                {
                    /* Domain control response nrc78 negative pending */
                    path->uds.hasRcvNrc = PDUR_DIAG_NRC_ALREADY;
                    /* Close p6 timer */
                    PDUR_TIMER_STOP(path->timer.p6);
                    /* Start p6* timer */
                    PDUR_TIMER_START(path->timer.p6Ex);
                }
                else
                {
                    if( sid == path->uds.sid )
                    {
                        /* (4) When the domain control diagnostic response arrives (except nrc78) */
                        /* Domain controller responds to non nrc78 and close all timers */
                        path->uds.status = PDUR_DIAG_IDLE;
                        path->uds.hasRcvNrc = PDUR_DIAG_NRC_NONE;
                        /* Close all timers */
                        PDUR_TIMER_STOP(path->timer.p2);
                        PDUR_TIMER_STOP(path->timer.p2Ex);
                        PDUR_TIMER_STOP(path->timer.p6);
                        PDUR_TIMER_STOP(path->timer.p6Ex);
                    }
                }

                isMatch = PDUR_TRUE;
            }
            else
            {
                /* Do nothing */
            }

            if( PDUR_TRUE == isMatch )
            {
                PduR_DiagNewReqFlg[pathIdx] = PDUR_FALSE;
                break;
            }
        }
    }
}
/*
********************************************************************************
* Function Name: PduR_Diag_Handle_Uds
*
* Explanation: The function handles diagnostic requests for each path.
* (Synchronous)
*
* param: path-> The path contains IDs of the diagnostic request and response.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, PDUR_CODE) PduR_Diag_Handle_Uds
(
    P2VAR(PduR_DiagPathType, AUTOMATIC, PDUR_APPL_DATA) path
)
{
    /* check Nrc */
    if( PDUR_DIAG_NRC_ALREADY == path->uds.hasRcvNrc )
    {
        /* Judge p6* timer, p6* timer timeout */
        if( PDUR_P6EX_TIMER <= path->timer.p6Ex.counter )
        {
            /* Close p6*, p2/p2* timers */
            if( PDUR_TIMER_RUNNING == path->timer.p2.status )
            {
                /* Close p2, p6* timers */
                PDUR_TIMER_STOP(path->timer.p2);
                PDUR_TIMER_STOP(path->timer.p6Ex);
            }
            else
            {
                /* Close p2* and p6* timers */
                PDUR_TIMER_STOP(path->timer.p2Ex);
                PDUR_TIMER_STOP(path->timer.p6Ex);
            }

            /* The status is reset to idle */
            path->uds.status = PDUR_DIAG_IDLE;
            path->uds.hasRcvNrc = PDUR_DIAG_NRC_NONE;
        }
        else
        {
            if( PDUR_TIMER_RUNNING == path->timer.p2.status )
            {
                if( PDUR_P2_TIMER <= (path->timer.p2.counter * PDUR_DIAG_DOUBLE) )
                {
                    /* Switch to p2* timer */
                    PDUR_TIMER_STOP(path->timer.p2);
                    PDUR_TIMER_START(path->timer.p2Ex);
                    /* Reply NRC78 */
                    PduR_Diag_ReplyNRC78(path->resPduId, path->uds.sid);
                }
            }
            else
            {
                if( PDUR_P2EX_TIMER <= (path->timer.p2Ex.counter * PDUR_DIAG_DOUBLE) )
                {
                    /* Reply NRC78 */
                    PduR_Diag_ReplyNRC78(path->resPduId, path->uds.sid);
                    /* Restart p2* timer */
                    PDUR_TIMER_RESET(path->timer.p2Ex);
                }
            }
        }
    }
    else
    {
        /* Judge p6 timer */
        if( PDUR_P6_TIMER <= path->timer.p6.counter )
        {
            /* Close p6, p2/p2* timers */
            if( PDUR_TIMER_RUNNING == path->timer.p2.status )
            {
                /* Close p2 and p6 timers */
                PDUR_TIMER_STOP(path->timer.p2);
                PDUR_TIMER_STOP(path->timer.p6);
            }
            else
            {
                /* Close p2* and p6 timers */
                PDUR_TIMER_STOP(path->timer.p2Ex);
                PDUR_TIMER_STOP(path->timer.p6);
            }

            /* The status is reset to idle */
            path->uds.status = PDUR_DIAG_IDLE;
            path->uds.hasRcvNrc = PDUR_DIAG_NRC_NONE;
        }
        else
        {
            if( PDUR_TIMER_RUNNING == path->timer.p2.status )
            {
                if( PDUR_P2_TIMER <= (path->timer.p2.counter * PDUR_DIAG_DOUBLE) )
                {
                    /* Switch to p2* timer */
                    PDUR_TIMER_STOP(path->timer.p2);
                    PDUR_TIMER_START(path->timer.p2Ex);
                    /* Reply NRC78 */
                    PduR_Diag_ReplyNRC78(path->resPduId, path->uds.sid);
                }
            }
            else
            {
                if( PDUR_P2EX_TIMER <= (path->timer.p2Ex.counter * PDUR_DIAG_DOUBLE) )
                {
                    /* Reply NRC78 */
                    PduR_Diag_ReplyNRC78(path->resPduId, path->uds.sid);
                    /* Restart p2* Timer */
                    PDUR_TIMER_RESET(path->timer.p2Ex);
                }
            }
        }
    }
}

/*
********************************************************************************
* Function Name: PduR_Diag_Handle_Timer
*
* Explanation: The function handles diagnostic timers for each path.
*
* param: path-> The path contains IDs of the diagnostic request and response.
*
* retval: None.
********************************************************************************
*/
static FUNC(void, PDUR_CODE) PduR_Diag_Handle_Timer
(
    P2VAR(PduR_DiagPathType, AUTOMATIC, PDUR_APPL_DATA) path
)
{
    /* P2 Timer */
    if( PDUR_TIMER_RUNNING == path->timer.p2.status )
    {
        path->timer.p2.counter += PDUR_DIAG_TASK_INTERVAL;
    }

    /* P2* Timer */
    if( PDUR_TIMER_RUNNING == path->timer.p2Ex.status )
    {
        path->timer.p2Ex.counter += PDUR_DIAG_TASK_INTERVAL;
    }

    /* P6 Timer */
    if( PDUR_TIMER_RUNNING == path->timer.p6.status )
    {
        path->timer.p6.counter += PDUR_DIAG_TASK_INTERVAL;
    }

    /* P6* Timer */
    if( PDUR_TIMER_RUNNING == path->timer.p6Ex.status )
    {
        path->timer.p6Ex.counter += PDUR_DIAG_TASK_INTERVAL;
    }
}

/*
********************************************************************************
* Function Name: PduR_Diag_MainFunction
*
* Explanation: Main function for diagnostic processing and timing.
* (Synchronous)
*
* param: None.
*
* retval: None.
********************************************************************************
*/
FUNC(void, PDUR_CODE) PduR_Diag_MainFunction(void)
{
    uint16 pathIdx = PDUR_DIAG_ZERO;

    /* handle each path separately */
    for( pathIdx = PDUR_DIAG_ZERO; pathIdx < PDUR_DIAG_PATH_NUM; pathIdx++ )
    {
        PduR_Diag_Handle_Timer(&PduR_DiagPaths[pathIdx]);
        PduR_Diag_Handle_Uds(&PduR_DiagPaths[pathIdx]);
    }
}

#define PDUR_STOP_SEC_CODE
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "PduR_MemMap.h"
#endif /* #if (STD_ON == PDUR_SUPPORT_DIAG) */

#endif /* #if (STD_OFF == PDUR_ZERO_COST_OPERATION) */
