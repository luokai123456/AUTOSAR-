/*
********************************************************************************
*
* File name: LinTp_Types.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: WangJipeng/2020.05.25
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
* Author/Date: LiZH/2021.09.02
* Change: Add uLinTp_CtrlType type.
* Cause: Update
********************************************************************************
* Version:3.3
* Author/Date:ZhangXF/2024.01.21
* Change: 1) Add macro LINTP_VALUE_0XF2, LINTP_VALUE_0X12, 
*            LINTP_VALUE_0X22,LINTP_VALUE_0X21.
*         2) Add linTp_Curr_Tx_Id and LinTp_MaxBufReqCounter to LinTp_ControlType.
* Cause:  Update
********************************************************************************
* Version:3.4
* Author/Date:ZhangXF/2024.03.13
* Change: Add LinTp_NodeType to LinTp_ControlType.
* Cause:  Update
********************************************************************************
* Version: 3.5
* Author/Date: TianG/2024.06.27
* Change: 1. Modify copyright.
*         2. Modify the comments format.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: YanCL/2025.06.18
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/

#ifndef LINTP_TYPES_H_
#define LINTP_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "LinTp_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Type definitions of LinTp. */
#define LINTP_FUNC_REQUEST_IDLE                    (0x00U)
#define LINTP_FUNC_REQUEST_PENDING                 (0x01U)
#define LINTP_FUNC_REQUEST_TRANSMITTED             (0x02U)

#define LINTP_LOCAL_BUFFER_SIZE                    (8U) /* Currently must be a multiple of 2 because of mask definition below */
#define LINTP_LOCAL_BUFFER_SIZE_MASK               (LINTP_LOCAL_BUFFER_SIZE - 0x1U)

#define LINTP_CHANNEL_IDLE                         ((uint8)0x00U)
/* LinTp channel tx/rx maske. */
#define LINTP_CHANNEL_TX_MSK                       ((uint8)0x10U)
#define LINTP_CHANNEL_RX_MSK                       ((uint8)0x20U)
/* List of TP frame types. */
#define LINTP_FRAMETYPE_SF                         ((uint8)0x00U)
#define LINTP_FRAMETYPE_FF                         ((uint8)0x10U)
#define LINTP_FRAMETYPE_CF                         ((uint8)0x20U)

/* LIN TP sub channel state engine. */
#define LINTP_CHANNEL_BUSY_TX_INVALID              ((uint8)0x10U) /* Transmission data currently not available, pending. */
#define LINTP_CHANNEL_BUSY_TX_VALID                ((uint8)0x11U) /* Transmission ongoing. */
#define LINTP_CHANNEL_BUSY_RX                      ((uint8)0x20U) /* Reception ongoing. */
#define LINTP_CHANNEL_BUSY_RX_SUSPENDED            ((uint8)0x21U) /* Currently no buffer for reception available suppress SRF header transmission. */
#define LINTP_CHANNEL_BUSY_RX_WAIT_FOR_START       ((uint8)0x22U) /* A new reception is started but PduR not informed yet. */
#define LINTP_CHANNEL_BUSY_RX_POLLBUFFER           ((uint8)0x23U) /* Schedule next SRF header but poll for receive buffer after reception. */

/* PduR notifitication state. */
#define LINTP_PDURNOTIFITY_IDLE                    ((uint8)0x00U)
#define LINTP_PDURNOTIFITY_TX                      ((uint8)0x01U)
#define LINTP_PDURNOTIFITY_TXTM                    ((uint8)0x02U)
#define LINTP_PDURNOTIFITY_RX                      ((uint8)0x10U)
#define LINTP_PORTNOTIFITY_IDLE                    ((uint8)0xFFU)

/* LinTp size value. */
#define LINTP_LENGTH_6BYTE                         (0x6U)
#define LINTP_LENGTH_8BYTE                         (0x8U)
#define LINTP_LENGTH_8BIT                          (0x8U)

#define LINTP_INIT_ZERO                            (0U)
#define LINTP_INIT_ONE                             (1U)
#define LINTP_INIT_TWO                             (2U)
#define LINTP_INIT_THREE                           (3U)
#define LINTP_INIT_FOUR                            (4U)
#define LINTP_INIT_FIVE                            (5U)
#define LINTP_INIT_SIX                             (6U)
#define LINTP_INIT_SEVEN                           (7U)

#define LINTP_VALUE_0XFF                           (0xFFU)
#define LINTP_VALUE_0X7E                           (0x7EU)
#define LINTP_VALUE_0X03                           (0x03U)
#define LINTP_VALUE_0X7F                           (0x7FU)
#define LINTP_VALUE_0X78                           (0x78U)
#define LINTP_VALUE_0X21                           (0x21U)
#define LINTP_VALUE_0X22                           (0x22U)
#define LINTP_VALUE_0X12                           (0x12U)
#define LINTP_VALUE_0XF2                           (0xF2U)

/* Get bit value. */
#define LINTP_16BIT_HIGH4BIT                       (0x0F00U)
#define LINTP_16BIT_LOW8BIT                        (0x00FFU)
#define LINTP_8BIT_LOW4BIT                         (0x0FU)
#define LINTP_8BIT_HIGH4BIT                        (0xF0U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint8 LinTp_ChannelType;

/* This type denotes which Schedule table can be requested by LIN TP during diagnostic session. */
typedef enum
{
    LINTP_APPLICATIVE_SCHEDULE,     /* Applicative schedule is selected. */
    LINTP_DIAG_REQUEST,             /* Master request schedule table is selected. */
    LINTP_DIAG_RESPONSE,            /* Slave response schedule table is selected. */

} LinTp_Mode;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinTp_ControlTypeTag /* Control structure of LinTp for one channel. */
{
    uint16         linTp_Timer;               /* Current timer value for timeout handling. */
    uint16         linTp_TimerReload;         /* Timer timeout value depends on next awaited frame type. */
    uint16         linTp_P2Timer;             /* Storing current timer value used for P2 and P2max. */
    uint16         linTp_RespPendingCounter;  /* Number of received response pending frames. */
    PduLengthType  linTp_RemainingLength;     /* Bytes to be stored in PduR buffer / to be transmitted. */
    PduIdType      linTp_Curr_UL_NSdu_Id;     /* Network layer Pdu ID of current request / response. */
    PduInfoType    linTp_PduInfoPtr;          /* PduInfo structure passed to PduR. */
    PduIdType      linTp_Curr_Rx_Id;          /* Internal ID of RxNSdu belonging to current LinTpRxNSdu. */
    PduIdType      linTp_Curr_Tx_Id;          /* Internal ID of TxNSdu belonging to current LinTpTxNSdu. */
    PduInfoType    linTp_FuncPduInfoPtr;      /* PduInfo structure passed to PduR for functional req. */
    PduIdType      linTp_Curr_Func_NSdu_Id;   /* Network layer Pdu ID of functional request. */
    uint8          linTp_ComModeRestore;      /* Recovery to correct schedule after functional request. */
    uint8          linTp_FuncRequest;         /* Status of the functional request. */
    uint8          linTp_Ch_State;            /* State engine. */
    uint8          linTp_NAD_Requested;       /* NAD of request - responses will be compared against it. */
    uint8          linTp_Tx_Rx_Buffer_Idx;    /* Null based index of Tp buffer. */
    uint8          linTp_Tx_Rx_Buffer_Length; /* Number of payload bytes of current frame. */
    uint8          linTp_Tx_Rx_Buffer[LINTP_LOCAL_BUFFER_SIZE];     /* Local Tp buffer. */
    uint8          linTp_SN;                  /* Sequence Number of CFs. */
    uint8          linTp_PortNotifity;        /* Indication flag to change the schedule table for diag. */
    uint8          linTp_PduRNotifity;        /* Indication flag to notify PduR on Tp Tx/Rx frame. */
    uint8          linTp_PduRNotifyResultTx;  /* Result of Tx notification to PduR. */
    PduIdType      linTp_PduRNSduIdTx;        /* Tx NsduId which shall be reported to PduR. */
    uint8          linTp_PduRNotifyResultRx;  /* Result of Rx notification to PduR. */
    PduIdType      linTp_PduRNSduIdRx;        /* Rx NsduId which shall be reported to PduR. */
    PduIdType      linTp_PduRNSduIdTm;        /* NsduId which shall be reported to PduR. */
    uint8          LinTp_MaxBufReqCounter;
    uint8          LinTp_NodeType;
} LinTp_ControlType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinTp_RxNSduTypeTag
{
    uint16 ctrlIdxOfRxNSdu;                /* The index of the 1:1 relation pointing to LinTp_Ctrl. */
    uint16 ncrOfRxNSdu;                    /* Value in seconds of the N_Cr timeout. */
    PduIdType upperLayerPduIdOfRxNSdu;     /* RxNSdu external ID (SNV). */
    uint8 nadOfRxNSdu;                     /* A N-SDU transported on LIN is identified using the NAD for the specific slave. */
} LinTp_RxNSduType;

/* This container exists once for each transmitted N-SDU on any channel the node is connected to. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinTp_TxNSduTypeTag
{
    uint16 ctrlIdxOfTxNSdu;                /* The index of the 1:1 relation pointing to LinTp_Ctrl. */
    uint16 nasOfTxNSdu;                    /* Value in seconds of the N_As timeout. */
    uint16 ncsOfTxNSdu;                    /* Value in seconds of the performance requirement of N_Cs. */
    PduIdType associatedRxNSduIdOfTxNSdu;
    PduIdType upperLayerPduIdOfTxNSdu;     /* The identifier of the Transport Protocol message. */
    uint8 nadOfTxNSdu;                     /* A N-SDU transported on LIN is identified using the NAD for the specific slave. */
    uint8 LinTpMaxBufReq;
} LinTp_TxNSduType;

/* Type used in LinTp_ChannelConfig. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct LinTp_ChannelConfigTypeTag
{
    boolean schedChangeNotifyOfChannelCfg;
    boolean strictNADCheckOfChannelCfg;
    uint16 linTp_P2TimerOut;
    uint16 LinTp_P2MaxTimerOut;
    uint32 LinTp_MaxNumberOfRespPendingFrames;
} LinTp_ChannelConfigType;

/* Type to access LinTp_Ctrl in an index and symbol based style. */
/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct uLinTp_CtrlTag
{
    LinTp_ControlType raw[LINTP_CHANNEL_NUMBER];
} uLinTp_CtrlType;

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

#endif /* LINTP_TYPES_H_ */

