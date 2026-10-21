/*
********************************************************************************
*
* File name: LinIf_Types.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.04.02
* Change: New created
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: lizhiheng/2020.07.01
* Change: Tab to spaces.
* Cause: Update
********************************************************************************
* Version: 3.0
* Author/Date: lizhiheng/2020.07.01
* Change: Update to 3.0.
* Cause: Update
********************************************************************************
* Version: 3.1
* Author/Date: lizhiheng/2020.08.25
* Change: Add data type.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: lizhiheng/2020.09.03
* Change: Adjusts the order of structural variables.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: lizhiheng/2020.09.04
* Change: Add file precompilation.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: lizhiheng/2020.09.04
* Change: Modify the structure variable type.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: LiZH/2020.10.28
* Change: Add channel references to comm.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2020.11.02
* Change: Modify the name of the SRF frame type.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: LiZH/2020.11.06
* Change: Add wakeup delay time.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: LiZH/2022.2.10
* Change: MCAL API name compatible.
* Cause: Optimize
********************************************************************************
* Version: 3.9
* Author/Date: SunHQ/2022.12.9
* Change: Append the missing header files.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: YuHC/2023.03.30
* Change: 1.Delete the definition of type EcuM_WakeupSourceType.
*         2.Include the file EcuM_Types.h when LINIF_CHANNEL_WAKEUP_SUPPORT or
*           LINIF_TRCV_WAKEUP_SUPPORT ON.
* Cause: Bugfix
********************************************************************************
* Version: 3.11
* Author/Date: LiXB/2023.06.29
* Change: 1.Add macro LINIF_CHANNEL_MASTER, LINIF_CHANNEL_SLAVE, LINIF_CHANNEL_NAD_NULL
*           LINIF_CHANNEL_NAD_NULL, LINIF_INVALID_COMSIGNALID, LINIF_PIDCONVERTTABLE_SIZE
*           LINIF_INVALID_FRAMEID
*         2.Add data type definition LinIf_ChannelBusIdleMonitorType, LinIf_ResponseErrorSignalChangedFuncType
*         3.Add frameIdOfChannel, nodeChannelType, goToSleepIndication_p, channelIdleCnt,
*           errorSignalId to LinIf_Channel_Config_st
*         4.Add channelId and change name of pidOfFrameList to frameId, change function pointer txConfirmation_p
*           (add a parameter result) of LINIf_Frame_Table_st,
*         5.Add busMaxIdleCnt, txFrameConfirmFlag, rxFrameReceiveFlag, errorSignalValue and
*           nodeWakeUpFlag to LinIf_ChannelDataType.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: LiXB/2023.07.08
* Change: Include head file Com.h
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: LiXB/2023.08.15
* Change: Add reqWakeUpFlag to LinIf_ChannelDataType
*         Add goToSleepCommandFlag to LinIf_ChannelDataType
*         Add frameIdOfErrorSignal to LinIf_Channel_Config_st
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: LiXB/2023.10.25
* Change: Update version to R21-11
* Cause: Update
********************************************************************************
* Version:3.15
* Author/Date:ZhangXF/2024.01.21
* Change: 1. Add node configuration service LinIf_SlaveChannel_Nc_ConfigType.
*         2. Add macro LINIF_NC_BUF_SIZE, LINIF_NC_ASSIGNNAD_0xB0, 
*            LINIF_NC_READBYIDENTIFIER_0xB2,LINIF_NC_SAVECONFIGURATION_0xB6,LINIF_NC_ASSIGNFRAMEIDRANGE_0xB7.
*         3. Add NodeConfiguration-related macros
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: TianG/2024.06.27
* Change: 1. Modify copyright.
*         2. Modify the comments format.
* Cause: Update
********************************************************************************
* Version:3.17
* Author/Date:TianG/2024.08.09
* Change: 1. Add LinIf_SendFrameStatusType.
*         2. Add LinIf_SendFrameStatus to LinIf_ChannelDataType.
* Cause: Update
********************************************************************************
* Version:3.18
* Author/Date:TianG/2024.08.13
* Change: Modify copyright.
* Cause: Update
********************************************************************************
* Version:3.19
* Author/Date:TianG/2024.10.23
* Change: 1. Add wakeupDelayTime to LinIf_Channel_Config_st.
*         2. Modify macro definition of LINIF_GET_WAKEUP_DELAY_EXTER_TIME 
*            and LINIF_GET_WAKEUP_DELAY_INTERNAL_TIME.
* Cause: Update
********************************************************************************
* Version:3.20
* Author/Date:TianG/2025.06.17
* Change: Add macro definition of LINIF_SEND_CONFIRMATION_TIMEOUT_5MS 
*         and LINIF_SEND_CONFIRMATION_TIMEOUT_10MS.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: YanCL/2025.06.18
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: TianG/2025.07.14
* Change: Add the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef LINIF_TYPES_H_
#define LINIF_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "LinIf_Cfg.h"
#include "Lin_GeneralTypes.h"

#if( (LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON) || (LINIF_TRCV_WAKEUP_SUPPORT == STD_ON) )
#include "EcuM_Types.h"
#endif

#if( LINIF_SLAVE_SUPPORT == STD_ON )
#include "Com.h"
#endif

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* LIN interface API service ID. */
#define LINIF_INIT                      (0x01U)
#define LINIF_GET_VERSION_INFO          (0x03U)
#define LINIF_TRANSMIT                  (0x04U)
#define LINIF_SCHEDULE_REQUEST          (0x05U)
#define LINIF_GO_TO_SLEEP               (0x06U)
#define LINIF_WAKE_UP                   (0x07U)
#define LINIF_SET_TRCV_MODE             (0x08U)
#define LINIF_GET_TRCV_MODE             (0x09U)
#define LINIF_GET_TRCV_WAKE_UP_REASON   (0x0AU)
#define LINIF_SET_TRCV_WAKE_UP_MODE     (0x0BU)
#define LINIF_CANCEL_TRANSMIT           (0x0CU)
#define LINTP_INIT                      (0x40U)
#define LINTP_TRANSMIT                  (0x41U)
#define LINTP_GET_VERSION_INFO          (0x42U)
#define LINTP_SHUT_DOWN                 (0x43U)
#define LINTP_CANCEL_TRANSMIT           (0x46U)
#define LINTP_CHANGE_PARAMETER          (0x44U)
#define LINIF_CHEKCK_WAKE_UP            (0x60U)
#define LINTP_CANCEL_RECEIVE            (0x47U)
#define LINIF_WAKE_UP_CONFIRMATION      (0x61U)
#define LINIF_HEADERINDICATION          (0x78U)
#define LINIF_RXINDICATION              (0x79U)
#define LINIF_TXCONFIRMATION            (0x7AU)
#define LINIF_LINERRORINDICATION        (0x7BU)
#define LINIF_MAIN_FUNCTION             (0x80U)

/* Development error. */
#define LINIF_E_NO_ERR                  (0xFFU)     /* No error. */
#define LINIF_E_UNINIT                  (0x00U)     /* API called without initialization of LIN Interface. */
#define LINIF_E_ALREADY_INITIALIZED     (0x10U)     /* Initialization API is used when already initialized. */
#define LINIF_E_NONEXISTENT_CHANNEL     (0x20U)     /* Referenced channel does not exist(identification is out of range). */
#define LINIF_E_PARAMETER               (0x30U)     /* API service called with wrong parameter. */
#define LINIF_E_PARAM_POINTER           (0x40U)     /* API service called with invalid pointer. */
#define LINIF_E_SCHEDULE_REQUEST_ERROR  (0x51U)     /* Schedule request made in channel sleep. */
#define LINIF_E_TRCV_INV_MODE           (0x53U)     /* API service called with invalid parameter for LIN transceiver operation mode. */
#define LINIF_E_TRCV_NOT_NORMAL         (0x54U)     /* Referenced transceiver state is not normal. */
#define LINIF_E_PARAM_WAKEUPSOURCE      (0x55U)     /* API service called with invalid parameter for WakeupSource. */
#define LINIF_E_RESPONSE                (0x60U)     /* LIN frame error detected. */
#define LINIF_E_NC_NO_RESPONSE          (0x61U)     /* Slave did not answer on a node configuration request. */

/* Dummy function. */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" Polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" */
#define LINIF_DUMMY_STATEMENT(v)          (v)=(v)

/* The upper layer (UL) module. */
#define LINIF_UPPER_LAYER_CDD   (0x00U)
#define LINIF_UPPER_LTR_LIN_SM  (0x01U)

/* Defines the state of each LIN channel after startup. */
#define LINIF_START_UP_SLEEP    (0x00U)
#define LINIF_START_UP_NORMAL   (0x01U)

/* Type of checksum that the frame is using. */
#define LINIF_CEHCK_SUM_TYPE_CLASSIC    (0x00U)
#define LINIF_CHECK_SUM_TYPE_ENHANCED   (0x01U)

/* Type of frame/slot. */
#define LINIF_FRAME_ASSIGN                  (0x01U)
#define LINIF_FRAME_ASSIGN_FRAME_ID_RANGE   (0x02U)
#define LINIF_FRAME_ASSIGN_NAD              (0x03U)
#define LINIF_FRAME_CONDITIONAL             (0x04U)
#define LINIF_FRAME_EVENT_TRIGGERED         (0x05U)
#define LINIF_FRAME_FREE                    (0x06U)
#define LINIF_FRAME_MRF                     (0x07U)
#define LINIF_FRAME_SAVE_CONFIGURATION      (0x08U)
#define LINIF_FRAME_SPORADIC                (0x09U)
#define LINIF_FRAME_SRF                     (0x0AU)
#define LINIF_FRAME_UNASSIGN                (0x0BU)
#define LINIF_FRAME_UNCONDITIONAL           (0x0CU)

/* Values for LinIf_ChannelStateType. */
#define LINIF_CHANNEL_UNINIT               ((LinIf_ChannelStateType)0x00U)
#define LINIF_CHANNEL_OPERATIONAL          ((LinIf_ChannelStateType)0x01U)
#define LINIF_CHANNEL_SLEEP                ((LinIf_ChannelStateType)0x02U)

/* Sleep / Wakeup handling. */
#define LINIF_ONSLRRPMODEFRM_IDLE                  ((uint8)0x00U)
#define LINIF_ONSLRRPMODEFRM_ONREQ                 ((uint8)0x01U)
#define LINIF_ONSLRRPMODEFRM_ONTRANS               ((uint8)0x02U)
#define LINIF_ONSLRRPMODEFRM_ONREWAKEINT           ((uint8)0x03U)
#define LINIF_ONSLRRPMODEFRM_ONREQINT              ((uint8)0x04U)
#define LINIF_ONWAKEUPFRM_ONTRANS                  ((uint8)0x05U)

/* Event-triggered collision resolving table states. */
#define LINIF_EVTCOLLRESOLVINGSTA_IDLE             ((uint8)0x00U)
#define LINIF_EVTCOLLRESOLVINGSTA_DETCED           ((uint8)0x01U)
#define LINIF_EVTCOLLRESOLVINGSTA_ONRESOLVING      ((uint8)0x02U)

/* List of frame types. */
#define LINIF_FRMTYPE_UNCONDITIONALFRAME           ((uint8)0x00U)
#define LINIF_FRMTYPE_MRF                          ((uint8)0x01U)
#define LINIF_FRMTYPE_SRF                          ((uint8)0x02U)
#define LINIF_FRMTYPE_EVENTTRIGGREDFRAME           ((uint8)0x04U)
#define LINIF_FRMTYPE_SPORADICFRAME                ((uint8)0x05U)
#define LINIF_FRMTYPE_ASSIGNFRAMEID                ((uint8)0x06U)
#define LINIF_FRMTYPE_UNASSIGNFRAMEID              ((uint8)0x07U)
#define LINIF_FRMTYPE_ASSIGNAD                     ((uint8)0x08U)
#define LINIF_FRMTYPE_FREEFORMAT                   ((uint8)0x09U)
#define LINIF_FRMTYPE_CONDITIONALCHANGENAD         ((uint8)0x0AU)
#define LINIF_FRMTYPE_ASSIGNFRAMEIDRANGE           ((uint8)0x0BU)
#define LINIF_FRMTYPE_SAVECONFIGURATION            ((uint8)0x0CU)
#define LINIF_FRMTYPE_SLEEPMODEFRAME               ((uint8)0x0DU)
#define LINIF_FRMTYPE_WAKEUPFRAME                  ((uint8)0x0EU)

/* Node configuration command handling */
#define LINIF_NODECONFIGCMD_IDLE                   ((uint8)0x00U)
#define LINIF_NODECONFIGCMD_SENDMRF                ((uint8)0x01U)
#define LINIF_NODECONFIGCMD_SKIPSRF                ((uint8)0x02U)
#define LINIF_NODECONFIGCMD_SENDSRF                ((uint8)0x03U)

/* PduR notification pending flag. */
#define LINIF_PDURNOTIFICATIONIDLE                  ((uint8)0x00U)
#define LINIF_PDURNOTIFICATIONTX                    ((uint8)0x01U)
#define LINIF_PDURNOTIFICATIONRX                    ((uint8)0x02U)

/* hese defines are used to indicate unused indexes in data relations. */
#define LINIF_NO_ENTRYENDIDXOFSCHEDULETABLELIST     (65535U)
#define LINIF_NO_ENTRYSTARTIDXOFSCHEDULETABLELIST   (65535U)

#define LINIF_LINPDU_SIZE                           (8U)
#define LINIF_LINPDU_SIZE_MASK                      (LINIF_LINPDU_SIZE - 1U)

/* LinIf NULL schedule table. */
#define NULL_SCHEDULE                               (0x00U)
#define LINIF_SCHEDULE_INVALID                      ((LinIf_SchHandleType)0xFFU)
#define LINIF_SCHEDULE_NULL                         (NULL_SCHEDULE)

/* Schedule state. */
#define LINIF_SCHDLHDLRRET_ONNULLSCHEDULE           ((uint8)0x00U)
#define LINIF_SCHDLHDLRRET_NONEWMESSAGE             ((uint8)0x01U)
#define LINIF_SCHDLHDLRRET_NEWMESSAGE               ((uint8)0x02U)

/* Schedule table resume position. */
#define LINIF_CONTINUE_AT_IT_POINT                  ((uint8)0x00U)
#define LINIF_START_FROM_BEGINNING                  ((uint8)0x01U)

/* LinIf Run mode. */
#define LINIF_RUNMODE_RUNONCE                       (0x00U)
#define LINIF_RUNMODE_RUNCONTINUOUS                 (0x01U)

/* linIf scheule end notification. */
#define LINIF_SCHEDULE_END_NOTIFICATION             (STD_OFF)

/* Startup state. */
#define LINIF_STARTUPSTATE_SLEEP                    ((uint8)0x00U)
#define LINIF_STARTUPSTATE_NORMAL                   ((uint8)0x01U)

/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define LinIf_GetSizeOfChannelData()                LINIF_CHANNEL_NUMTOTAL
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define LinIf_GetSporTransmitFlags(Index)           (LinIf_GetSporTransmitFlagsOfPCConfig()[(Index)])
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define LinIf_SetSporTransmitFlags(Index, Value)    LinIf_GetSporTransmitFlagsOfPCConfig()[(Index)] = (Value)

/* Not ref LinTrcv. */
#define LINIF_NOTREF_TRCV                           (0xffU)

/* LinIf data valude. */
/* Polyspace +1 MISRA-C3:11.4 [Justified:Unset] "NSCA_Polyspace_LinIf_11.4" */
#define LINIF_INIT_ZERO                             (0U)
#define LINIF_INIT_ONE                              (1U)
#define LINIF_INIT_TWO                              (2U)

#define LINIF_NO_FIXEDFRAMESDULISTIDXOFFRAMELIST    (0xFFFFU)

/* Wakeup delay external time. */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define LINIF_GET_WAKEUP_DELAY_EXTER_TIME(Channel)    (uint16)(LinIf_Channl_Cfg_Tab[Channel].wakeupDelayTime / LinIf_Channl_Cfg_Tab[Channel].channelFuncCallCycleCfg)
/* Wakeup delay Internal time. */
/* Polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define LINIF_GET_WAKEUP_DELAY_INTERNAL_TIME(Channel) (uint16)(LinIf_Channl_Cfg_Tab[Channel].wakeupDelayTime / LinIf_Channl_Cfg_Tab[Channel].channelFuncCallCycleCfg)

/* Linif channel node type */
#define LINIF_CHANNEL_MASTER                        ((uint8)0x00U)
#define LINIF_CHANNEL_SLAVE                         ((uint8)0x01U)

/* LinIf Node address value */
#define LINIF_CHANNEL_NAD_NULL                      ((uint8)0x00U)

/* LinIf invalid signal id */
#define LINIF_INVALID_COMSIGNALID                   ((uint16)0xFFFFU)

/* LinIf pid convert table size */
#define LINIF_PIDCONVERTTABLE_SIZE                  (64U)

/* LinIf invalid frame id */
#define LINIF_INVALID_FRAMEID                       ((uint8)0xFFU)

#define LINIF_AR_VERSION_BEFORE_440                 (0U)
#define LINIF_AR_VERSION_ABOVE_440                  (1U)

#define LINIF_NC_ASSIGNNAD_0xB0                     ((uint8)0xB0U)
#define LINIF_NC_READBYIDENTIFIER_0xB2              ((uint8)0xB2U)
#define LINIF_NC_SAVECONFIGURATION_0xB6             ((uint8)0xB6U)
#define LINIF_NC_ASSIGNFRAMEIDRANGE_0xB7            ((uint8)0xB7U)

#define LINIF_NC_RET_ACCEPTED                       ((LinIf_Nc_RetType)0x00U)
#define LINIF_NC_RET_IGNORED                        ((LinIf_Nc_RetType)0x01U)
#define LINIF_NC_RET_IGNOREDNOFORWARD               ((LinIf_Nc_RetType)0x02U)

#define LINIF_NC_WILDCARD_SUPPLIERID                ((uint16)0x7FFFU) /* Wildcard value for Supplier ID */
#define LINIF_NC_WILDCARD_FUNCTIONID                ((uint16)0xFFFFU) /* Wildcard value for Function ID */
#define LINIF_NC_BUF_SIZE                           (8U)
#define LINIF_VALUE_MRF                             (0x3CU)
#define LINIF_VALUE_SRF                             (0x7DU)
#define LINIF_VALUE_0XB0                            (0xB0U)
#define LINIF_VALUE_0XB8                            (0xB8U)

#if( LINIF_ADAPTED_AR_VERSION == LINIF_AR_VERSION_BEFORE_440 )
#define LINIF_MSR_MASTER_RESPONSE                   LIN_MASTER_RESPONSE
#define LINIF_MSR_SLAVE_RESPONSE                    LIN_SLAVE_RESPONSE
#define LINIF_SLV_MASTER_RESPONSE                   LIN_MASTER_RESPONSE
#define LINIF_SLV_SLAVE_RESPONSE                    LIN_SLAVE_RESPONSE
#define LINIF_MSR_SLAVE_TO_SLAVE                    LIN_SLAVE_TO_SLAVE
#define LINIF_SLV_FRAMERESPONSE_IGNORE              LIN_SLAVE_TO_SLAVE
#else
#define LINIF_MSR_MASTER_RESPONSE                   LIN_FRAMERESPONSE_TX
#define LINIF_MSR_SLAVE_RESPONSE                    LIN_FRAMERESPONSE_RX
#define LINIF_SLV_MASTER_RESPONSE                   LIN_FRAMERESPONSE_RX
#define LINIF_SLV_SLAVE_RESPONSE                    LIN_FRAMERESPONSE_TX
#define LINIF_MSR_SLAVE_TO_SLAVE                    LIN_FRAMERESPONSE_IGNORE
#define LINIF_SLV_FRAMERESPONSE_IGNORE              LIN_FRAMERESPONSE_IGNORE
#endif

/* Timeout period for sending confirmation */
#define LINIF_SEND_CONFIRMATION_TIMEOUT_5MS         (5U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define LINIF_SEND_CONFIRMATION_TIMEOUT_10MS        (10U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* Index of the schedule table that is selectable and followed by LIN Interface.
   Value is unique per LIN channel/controller, but not per ECU. */
typedef uint8 LinIf_SchHandleType;

/* A pointer to an instance of this structure will be used in the initialization of the LIN Interface. */
typedef uint8 LinIf_CongfigType;

/* A pointer to an instance of this structure will be used in the initialization of the LIN Transport Protocol. */
typedef uint8 LinTp_ConfigType;

typedef uint8 LinIf_ChannelStateType;

typedef uint16 LinIf_ScheduleTableTickType;

/* Value based type definition for LinIf_FrameListIdxOfEntry. */
typedef uint16 LinIf_FrameListIdxOfEntryType;

/* Value based type definition for LinIf_DelayInTimebaseTicksOfEntry. */
typedef uint8 LinIf_DelayInTimebaseTicksOfEntryType;

/* Value to monitor bus idle time */
typedef uint16 LinIf_ChannelBusIdleMonitorType;

typedef uint8 LinIf_Nc_RetType;

#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
typedef Std_ReturnType (*LinIf_Lin_SendFrameFuncType)( const uint8 Channel, const Lin_PduType const* PduInfoPtr );
typedef Lin_StatusType (*LinIf_Lin_GetStatusFuncType)( uint8 Channel, uint8** Lin_SduPtr );
typedef Std_ReturnType (*LinIf_Lin_GoToSleepFuncType)( uint8 Channel );
typedef Std_ReturnType (*LinIf_Lin_GoToSleepInternalFuncType)( uint8 Channel );
typedef Std_ReturnType (*LinIf_Lin_WakeupFuncType)( uint8 Channel );
typedef Std_ReturnType (*LinIf_Lin_WakeupInternalFuncType)( uint8 Channel );
typedef Std_ReturnType (*LinIf_Lin_CheckWakeupFuncType)( uint8 Channel );
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */

typedef void (*LinIf_ResponseErrorSignalChangedFuncType)( NetworkHandleType Channel, boolean RespErrSigValue );

typedef struct
{
    uint16 maxFrameCnt;                             /* Maximum number of Frames. */
    uint8 trcvIndexRef;                             /* LinTrcvRef. */
    uint16 frmListStartIdxOfChannelCfg;             /* The start index of the 1:n relation pointing to LinIf_FrameList. */
    uint16 frmListEndIdxOfChannelCfg;               /* The end index of the 1:n relation pointing to LinIf_FrameList. */
    uint16 ScheduleTableListStartIdxOfChannelCfg;   /* The start index of the 1:n relation pointing to LinIf_ScheduleTableListInd.  */
    uint16 ScheduleTableListEndIdxOfChannelCfg;     /* The end index of the 1:n relation pointing to LinIf_ScheduleTableListInd. */
    uint8 numbeOfSchedules;                         /* Number of schedule tables. */
    uint16 sporcUncFrmListStartOfChannelCfg;        /* The start index of the 0:n relation pointing to LinIf_SporadicFrameInfo. */
    uint16 sporcUncFrmListEndOfChannelCfg;          /* The end index of the 0:n relation pointing to LinIf_SporadicFrameInfo. */
    uint16 eventFrmListStartOfChannelCfg;           /* The start index of the 0:n relation pointing to LinIf_EvtFrameInfo. */
    uint16 eventFrmListEndOfChannelCfg;             /* The end index of the 0:n relation pointing to LinIf_EvtFrameInfo. */
    uint16 channelFuncCallCycleCfg;                 /* LinIfTimeBase. */
    uint8 numberOfSporadicFrames;                   /* Number of sporadic slots on channel. */
    uint8 numberOfEventFrames;                      /* Number of sporadic slots on channel. */
    uint8 linChannelIdRef;
    boolean CddCfg;                                 /* Reference to the CDD module description. */
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    void (*goToSleepConfirmation_p)(NetworkHandleType channel, boolean success);   /* LinIfGotoSleepConfirmationUL. */
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    void (*scheduleRequestConfirmation_p)(NetworkHandleType channel, LinIf_SchHandleType schedule);   /* LinIfScheduleRequestConfirmationUL.  */
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    void (*WakeupConfirmation_p)(NetworkHandleType channel, boolean success);   /* LinIfWakeupConfirmationUL. */
    uint8 ComMChannelRef;
    uint8 ctrlId;                                   /* Control index. */
    uint8* frameIdOfChannel;                        /* frame id of channel. */
    uint8 nodeChannelType;                          /* channel node type */
    /* Polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_LinIf_Dir4.5" */
    void (*goToSleepIndication_p)(NetworkHandleType channel);                   /* LinIfGotoSleepIndicationUL. */
    LinIf_ChannelBusIdleMonitorType channelIdleCnt; /* channel idle counter */
    uint16 errorSignalId;                           /*error Signal Id*/
    uint8 frameIdOfErrorSignal;                     /* frame Id of pdu, in which error signal is located */
    uint16 wakeupDelayTime;                         /*  Lin wakeup delay time. */
} LinIf_Channel_Config_st;

typedef struct
{
    uint16 fixedFrameSduListIdxOfFrameList;  /* The index of the 0:1 relation pointing to LinIf_EvtFrameInfo,LinIf_FixedFrameSduList,LinIf_SporadicFrameInfo. */
    Lin_FrameCsModelType chkSumType;            /* Type of checksum that the frame is using. */
    Lin_FrameResponseType pduDirection;         /* Direction of the frame. */
    uint8 frameType;                        /* Type of frame/slot. */
    uint8 lengthOfFrameList;                /* Frame Length(Byte). */
    uint8 frameId;                          /* frame id. */
    PduIdType pduIdOfFrameList;                 /* Upper layer PduId. */
    boolean CddCfg;                             /* LinIfUserTxUL or LinIfUserRxIndicationUL. */
    void (*txConfirmation_p)(PduIdType TxPduId, Std_ReturnType result);                                         /* LinIfTxConfirmationUL. */
    Std_ReturnType (*txTriggerTransmit_p)(PduIdType TxPduId, PduInfoType* PduInfoPtr);   /* LinIfTxTriggerTransmitUL. */
    void (*rxIndication_p)(PduIdType RxPduId, const PduInfoType* PduInfoPtr);            /* LinIfRxIndicationUL. */
    uint8 channelId;                        /* channel id */
} LINIf_Frame_Table_st;

/* Type used in LinIf_Entry. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_EntryTypeTag
{
    LinIf_FrameListIdxOfEntryType frameListIdx;         /* The index of the 1:1 relation pointing to LINIf_Frame_Cfg_Tab. */
    LinIf_DelayInTimebaseTicksOfEntryType delayTime;    /* Delay to next entry in schedule table in seconds. */

} LinIf_EntryType;

/* Type used in LinIf_ScheduleTableList. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_ScheduleTableListTypeTag
{
    uint16 entryStartIdxOfScheduleTableList;  /* The start index of the 0:n relation pointing to LinIf_Entry. */
    uint16 entryEndIdxOfScheduleTableList;    /* The end index of the 0:n relation pointing to LinIf_Entry. */
    uint8 numberOfScheduleEntries;            /* Number of entries. */
    uint8 resumePosition;                     /* ONTINUE_AT_IT_POINT : 0 START_FROM_BEGINNING : 1. */
    uint8 runMode;                            /* RUN_CONTINUOUS : 1 RUN_ONCE : 0. */

} LinIf_ScheduleTableListType;

/* Type used in LinIf_ChannelIndTable. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_ChannelIndTableTypeTag
{
    uint8 channelIdx;         /* LinIf channel index. */
    uint8 comMNetworkHandle;  /* Reference to one of the network handles configured for the ComM. */

} LinIf_ChannelIndTableType;

/* Type used in LinIf_SporUnconditionalFrame. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_SporUnconditionalFrameTypeTag
{
    uint16 frmIdxOfSporUncFrm;           /* The index of the 1:1 relation pointing to LinIf_FrameList. */
    uint8 bitMskOfSporUncFrm;            /* Byte flag. */
    uint8 byteMskOfSporUncFrm;           /* Bit flag. */
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} LinIf_SporUnconditionalFrameType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_SporadicFrameInfoTypeTag
{
    uint16 sporUncFrmByProListEndIdx;    /* The end index of the 1:n relation pointing to LinIf_SporUnconditionalFrame. */
    uint16 sporUncFrmByProListStartdx;   /* The Start index of the 1:n relation pointing to LinIf_SporUnconditionalFrame. */
    uint8 uncFrameCount;                /* Unconditional frame counter. */

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} LinIf_SporadicFrameInfoType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_SporadicFrameLookupTableTypeTag
{
    PduIdType txPduId;               /* LinIfTxPduId of associated unconditional frame. */
    uint8 bitMskOfSporFrm;           /* Byte flag. */
    uint8 byteMskOfSporFrm;          /* Bit flag. */

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} LinIf_SporadicFrameLookupTableType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_EvtFrameInfoTypeTag
{
    uint16 evtUncFrmInfoEndIdx;     /* The end index of the 1:n relation pointing to LinIf_EvtUnconditionalFrameInfo. */
    uint16 evtUncFrmInfoStartIdx;   /* The start index of the 1:n relation pointing to LinIf_EvtUnconditionalFrameInfo. */
    uint8 collisionResolvingRef;    /* Reference to the schedule table, which resolves the collision. */

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} LinIf_EvtFrameInfoType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_EvtUnconditionalFrameInfoTypeTag
{
    uint16 frmIdxOfEvtUncFrm;       /* The index of the 1:1 relation pointing to LinIf_FrameList. */
    uint8 pidOfEvtUncFrame;         /* Frame ID of the corresponding unconditional frame. */

} LinIf_EvtUnconditionalFrameInfoType;

/* Control structure of LinIf schedule table handler. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_SchedTabDataTypeTag
{
    LinIf_ScheduleTableTickType  currentSlotDelay;
    uint8                        currentSlot;
    uint8                        currentTable;
    uint8                        previousContinuousSlot;
    uint8                        previousContinuousTable;
    uint8                        requestedTable;
    uint8                        schedReqConfirmTable;
#if( LINIF_EVT_FRM_SUPPORTED == STD_ON )
    uint8                        evtCollResolvingState;
#endif

#if( LINIF_SCHEDULE_END_NOTIFICATION == STD_ON )
    uint8                        schedEndNotifyTable;
#endif

} LinIf_SchedTabDataType;

/* LinIf send staus. */
typedef enum
{
    LINIF_SENDFRAME_IDLE = 0U,
    LINIF_SENDFRAME_BUSY,
}LinIf_SendFrameStatusType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinIf_ChannelDataTypeTag
{
    LinIf_SchedTabDataType       schedTabData;                       /* Pointer to schedule table handling variables. */
    LinIf_ScheduleTableTickType  frameMaxDelayCtn;                   /* Remaining transmission duration of current frame in ticks. */
    LinIf_ChannelStateType       channelState;                       /* Channel state engine. */
    uint16                       frameHandle;                        /* Handle of current processed/active frame. */
    uint8                        sleepModeFrameHandle;               /* Internal node management state machine. */
    uint8                        currentFrameType;                   /* Type of current processed/active frame. */
#if( LINIF_FIXEDFRAMESDULIST == STD_ON )
    uint8                        nodeConfigurationCmd;               /* Node configuration command state machine. */
#endif

#if( LINIF_CHANNEL_WAKEUP_SUPPORT == STD_ON ) || ( LINIF_TRCV_WAKEUP_SUPPORT == STD_ON )
    uint8                        wakeupFlag;                         /* External wakeup detection flag. Range: 0 or 1. */
#endif
    uint16                       wakeupDelayTimer;                   /* Lin wake-up delay time */
    uint8                        pduRNotification;                   /* PduR notification pending flag; either Idle, Rx or Tx notification. */
    PduIdType                    pduRNotificationPduId;              /* PduId to pass to PduR if notification is pending. */
    uint8                        pduRNotificationPduLength;          /* Pdu length to pass to PduR if notification is pending. */

#ifdef LINIF_PDUR_ONLY_UL_OPTIMIZATION
    uint8                        pduRNotificationFctIndex;           /* Index of PduR notification callback function pointer list. */
#endif
    uint8                        LinIf_RxData[LINIF_LINPDU_SIZE];    /* Local buffer to receive frames. */
    uint8                        LinIf_TxData[LINIF_LINPDU_SIZE];    /* Local buffer to transmission frames. */
    LinIf_ChannelBusIdleMonitorType  busMaxIdleCnt;                  /* recording bus idle time of channel in ticks. */

#if( LINIF_SLAVE_SUPPORT == STD_ON )
    boolean                      txFrameConfirmFlag;                 /* Flag indicates, if a tx Frame in the channel need to send */
    boolean                      rxFrameReceiveFlag;                 /* Flag indicates, if a rx Frame in the channel is received */
    uint8                        errorSignalValue;                   /* Error signal value */
    uint8                        nodeWakeUpFlag;                     /* channel wake up flag */
    uint8                        firstReceiveHeaderFlag;             /* header receive indication flag */
    boolean                      goToSleepCommandFlag;               /* go to sleep flag */
#endif /* LINIF_SLAVE_SUPPORT == STD_ON */

    boolean                      reqWakeUpFlag;                      /* flag, which indicates if a wake up request exsits or not */
    LinIf_SendFrameStatusType    LinIf_SendFrameStatus;              /* LinIf send staus. */

} LinIf_ChannelDataType;

typedef struct 
{
    /* Slave node configured NAD. */
    uint8 LinIf_ConfiguredNAD;
    /* LIN function Id. */
    uint16 LinIf_FunctionId;
    /* Slave node initial NAD. */
    uint8 LinIf_InitialNAD;
    /* N_As timeout in seconds.*/
    uint16 LinIf_NasTimeOut;
    /* LIN supplier Id. */
    uint16 LinIf_SupplierId;
    /* LIN variant Id. */
    uint8 LinIf_VariantId;
    /* N_As timer */
    uint16* LinIf_NasTimer;
    /* NC pesponse RAM buffer */
    uint8* LinIf_NcRespBuffer; 
    Std_ReturnType (*LinTp_Nc_ReadByIdentifier)(uint8 Identifier, uint8* DataPtr, uint8* DataLen);
}LinIf_SlaveChannel_Nc_ConfigType;

#if( LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON )
typedef struct
{
    VAR(LinIf_Lin_SendFrameFuncType, TYPEDEF) LinIf_Lin_SendFrameFunc;                 /* Lin_SendFrame. */
    VAR(LinIf_Lin_GetStatusFuncType, TYPEDEF) LinIf_Lin_GetStatusFunc;                 /* Lin_GetStatus. */
    VAR(LinIf_Lin_GoToSleepFuncType, TYPEDEF) LinIf_Lin_GoToSleepFunc;                 /* Lin_GoToSleep. */
    VAR(LinIf_Lin_GoToSleepInternalFuncType, TYPEDEF) LinIf_Lin_GoToSleepInternalFunc; /* Lin_GoToSleepInternal. */
    VAR(LinIf_Lin_WakeupFuncType, TYPEDEF) LinIf_Lin_WakeupFunc;                       /* Lin_Wakeup */
    VAR(LinIf_Lin_WakeupInternalFuncType, TYPEDEF) LinIf_Lin_WakeupInternalFunc;       /* Lin_WakeupInternal */
    VAR(LinIf_Lin_CheckWakeupFuncType, TYPEDEF) LinIf_Lin_CheckWakeupFunc;             /* Lin_CheckWakeup */
} LinIf_LinMultipeDrvInfoType;
#endif  /* LINIF_MULTIPLE_DRIVERS_SUPPORTED == STD_ON */

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
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* LINIF_TYPES_H_ */

