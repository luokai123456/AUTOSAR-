/*
********************************************************************************
*
* File name: J1939Tp_Types.h
*
* Copyright 2019-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: yong.zhang/2019.3.18
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: li.zhiheng/2020.03.30
* Change: Nothing
* Cause: Update to 3.0.
********************************************************************************
* Version: 3.1
* Author/Date: li.zhiheng/2020.05.20
* Change: Modification code specification.
* Cause: Update
********************************************************************************
* Version: 3.2
* Author/Date: li.zhiheng/2020.10.15
* Change: 1.Modify coding standards.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: li.zhiheng/2021.04.27
* Change: 1.Modify type name.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: li.zhiheng/2021.05.10
* Change: 1.Modify J1939TP_MAXPACKETPERBLOCK_NOUSED value.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: li.zhiheng/2021.05.24
* Change: Add SduStartIndx, SduEndIdx in channel struct.
* Cause: Update
********************************************************************************
* Version: 3.6
* Author/Date: LiZH/2021.05.25
* Change: Modify the scope of Channel index.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: LiZH/2021.05.31
* Change: Add StartIdx/EndIdx of TxSduInfo in J1939Tp_TxChannelType.
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: Li.ZH/2021.8.16
* Change: Modification code specification.
* Cause: Optimize
********************************************************************************
* Version: 3.9
* Author/Date: TongXY/2022.10.28
* Change: Change the type of the member variable 'SduLength' in the structures
*         J1939Tp_TxSdu_Type and J1939Tp_RxSdu_Type to uint16.
* Cause: Bugfix
********************************************************************************
* Version: 3.10
* Author/Date: TongXY/2023.3.14
* Change: 1.Added elements required for retransmission.
*         2.Added elements required for receiving direct PDUs.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: TongXY/2023.05.24
* Change: Modify the location of the macro definition.
* Cause: Optimization
********************************************************************************
* Version: 3.12
* Author/Date: YanCL/2024.4.2
* Change: Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.13
* Author/Date: YanCL/2024.5.23
* Change: Add TpDtCount member to the structure of J1939Tp_TxSduStateType.
* Cause: Update
********************************************************************************
* Version: 3.14
* Author/Date: YanCL/2024.6.25
* Change: Add copyright information.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: YanCL/2024.10.2
* Change: Modify PduIdOfTxPdu and PduIdOfRxPdu types to PduIdType(uint16).
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef J1939TP_TYPES_H_
#define J1939TP_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define J1939TP_PROTOCOL_CMDT 1U
#define J1939TP_PROTOCOL_BAM  2U
#define J1939TP_PROTOCOL_NONE  3U

#define J1939TP_TPCM_PDUTYPEOFTXPDU   (1U)
#define J1939TP_TPDT_PDUTYPEOFTXPDU   (2U)
#define J1939TP_DIRECT_PDUTYPEOFTXPDU (3U)

#define J1939TP_FINDSDUIDX_ERROR    (0xffffU)

#define J1939TP_MAXPACKETPERBLOCK_NOUSED  (0x0U)

#define J1939TP_TXCONFRM_NOUESD           (0xFFU)
#define J1939TP_RXCONFRM_NOUESD           (0xFFU)
#define J1939TP_TXTPCM_NOUESD             (0xFFU)
#define J1939TP_TXTPDT_NOUESD             (0xFFU)
#define J1939TP_RXTPCM_NOUESD             (0xFFU)
#define J1939TP_RXTPDT_NOUESD             (0xFFU)

#define J1939TP_NO_CFG_DIRECT       (0xffffU)

#define J1939T_8BYTE_LENGTH         (8U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef enum
{
    /* *INDENT-OFF* */
    J1939TP_CAR_NO_ABORT = 0U,         /* No Abort Reason, do not send abort. */
    /* J1939, ISOBUS (TP, ETP) */
    J1939TP_CAR_CONNECTION = 1U,       /* Abort Reason: Already in one or more connection-managed sessions and cannot support another. */
    J1939TP_CAR_RESOURCES = 2U,        /* Abort Reason: System resources were needed for another task so this connection managed session was terminated. */
    J1939TP_CAR_TIMEOUT = 3U,          /* Abort Reason: A timeout occurred and this is the connection abort to close the session. */
    J1939TP_CAR_UNTIMELY_CTS = 4U,     /* Abort Reason: CTS messages received when data transfer is in progress. */
    J1939TP_CAR_RETRANSMIT = 5U,       /* Abort Reason: Maximum retransmit request limit reached. */
    /* ISOBUS (TP, ETP) */
    J1939TP_CAR_UNTIMELY_DT = 6U,      /* Abort Reason: Unexpected data transfer packet. */
    J1939TP_CAR_BAD_SEQ = 7U,          /* Abort Reason: Bad sequence number (and software is not able to recover). */
    J1939TP_CAR_DUP_SEQ = 8U,          /* Abort Reason: Duplicate sequence number (and software is not able to recover). */
    /* ISOBUS (ETP) */
    J1939TP_CAR_UNTIMELY_DPO = 9U,     /* Abort Reason: Unexpected EDPO packet. */
    J1939TP_CAR_DPO_PGN = 10U,         /* Abort Reason: Unexpected EDPO PGN (PGN in EDPO is bad). */
    J1939TP_CAR_DPO_PACKETS = 11U,     /* Abort Reason: EDPO number of packets is greater than CTS. */
    J1939TP_CAR_DPO_OFFSET = 12U,      /* Abort Reason: Bad EDPO offset. */
    J1939TP_CAR_ECTS_PGN = 14U,        /* Abort Reason: Unexpected ECTS PGN (PGN in ECTS is bad). */
    J1939TP_CAR_ECTS_PACKETS = 15U,    /* Abort Reason: ECTS requested packets exceeds message size. */
    /* J1939, ISOBUS (TP, ETP) */
    J1939TP_CAR_OTHER = 255U           /* Abort Reason: Unknown. */
    /* *INDENT-ON* */
} J1939Tp_ConnectionAbortReasonType;

typedef enum
{
    J1939TP_STATE_IDLE = 0x0000U,
    J1939TP_STATE_FINISH = 0x0001U,
    J1939TP_STATEMASK_BUSY = 0x0040U,
    J1939TP_STATEMASK_CONF = 0x0080U,
    J1939TP_STATEMASK_DIRECT = 0x0100U,
    J1939TP_STATE_DIRECT = 0x0101U,
    J1939TP_STATE_DIRECT_BUSY = 0x0141U,
    J1939TP_STATE_DIRECT_CONF = 0x0181U,
    J1939TP_STATEMASK_BAM = 0x0200U,
    J1939TP_STATE_BAM_BAM = 0x0201U,
    J1939TP_STATE_BAM_DATA = 0x0205U,
    J1939TP_STATE_BAM_BAM_BUSY = 0x0241U,
    J1939TP_STATE_BAM_DATA_BUSY = 0x0245U,
    J1939TP_STATE_BAM_BAM_CONF = 0x0281U,
    J1939TP_STATE_BAM_DATA_CONF = 0x0285U,
    J1939TP_STATEMASK_CMDT = 0x0400U,
    J1939TP_STATE_CMDT_RTS = 0x0401U,
    J1939TP_STATE_CMDT_CTSWAIT = 0x0402U,
    J1939TP_STATE_CMDT_CTS = 0x0403U,
    J1939TP_STATE_CMDT_DATA_FIRST = 0x0404,
    J1939TP_STATE_CMDT_DATA = 0x0405U,
    J1939TP_STATE_CMDT_EOMACK = 0x0406U,
    J1939TP_STATE_CMDT_ABORT = 0x0407U,
    J1939TP_STATE_CMDT_CTSRETRY = 0x0408U,
    J1939TP_STATE_CMDT_RTS_BUSY = 0x0441U,
    J1939TP_STATE_CMDT_CTSWAIT_BUSY = 0x0442U,
    J1939TP_STATE_CMDT_CTS_BUSY = 0x0443U,
    J1939TP_STATE_CMDT_DATA_BUSY = 0x0445U,
    J1939TP_STATE_CMDT_EOMACK_BUSY = 0x0446U,
    J1939TP_STATE_CMDT_ABORT_BUSY = 0x0447U,
    J1939TP_STATE_CMDT_CTSRETRY_BUSY = 0x0448U,
    J1939TP_STATE_CMDT_RTS_CONF = 0x0481U,
    J1939TP_STATE_CMDT_CTSWAIT_CONF = 0x0482U,
    J1939TP_STATE_CMDT_CTS_CONF = 0x0483U,
    J1939TP_STATE_CMDT_DATA_CONF = 0x0485U,
    J1939TP_STATE_CMDT_EOMACK_CONF = 0x0486U,
    J1939TP_STATE_CMDT_ABORT_CONF = 0x0487U,
    J1939TP_STATE_CMDT_CTSRETRY_CONF = 0x0488U,
    J1939TP_STATEMASK_PROTOCOL = 0x1F00U
} J1939Tp_StateType;

typedef enum
{
    J1939TP_CB_DEFAULT = 0U,
    J1939TP_CB_RTS = 16U,
    J1939TP_CB_CTS = 17U,
    J1939TP_CB_EOMACK = 19U,
    J1939TP_CB_ABORT = 255U,
    J1939TP_CB_BAM = 32U
} J1939Tp_ControlByteType;

typedef enum
{
    J1939TP_NSDU_DIRECT = 0U,
    J1939TP_NSDU_BAM,
    J1939TP_NSDU_CMDT_TX,
    J1939TP_NSDU_CMDT_RX
} J1939Tp_NSduType;

typedef struct
{
    uint32 Size;                /* Sdu size. */
    uint8 PacketOffset;        /* Pcakets offset (reserved). */
    /* Polyspace +1 MISRA-C3:5.6 [Justified:Unset] "NSCA_Polyspace_J1939Tp_Rule5.6" */
    PduLengthType BufSize;      /* Buffer size (bam use). */
    J1939Tp_StateType State;    /* Sdu state. */
    J1939Tp_ConnectionAbortReasonType AbortReason;      /* Abort reason. */
    uint16 TimeOut;             /* Sdu timeout. */
    uint8 Packets;              /* Number of (E)TP.DT frames for BAM/CMDT. */
    boolean Aborted;              /* Is abort (reserved). */
    uint8 Sequence;             /* Sequence number for BAM/CMDT/ETP, frame counter for FPP. */
    uint8 NextBlock;            /* Packet number that starts the next block for BAM/CMDT/ETP. */
    uint8 MaxBlock;             /* Max block (reserved). */
    uint8 Sender;               /* Sender address. */
    uint8 Receiver;             /* Receiver address. */
    uint8 Priority;             /* Sdu priority. */
    uint8 RetryState;
} J1939Tp_RxSduStateType;


/* This container describes a reception channel of the J1939Tp module. */
typedef struct
{
    boolean rxCancellationSupport;
    uint8 rxDa;
    boolean rxDynamicBlockCalculation;
    uint8 rxDynamicBufferRatio;
    uint8 rxPacketsPerBlock;
    uint8 rxProtocolType;
    boolean rxRetrySupport;
    uint8 rxSa;
    uint16 txConfitmIdx;   /* Index of TxPdu */
    uint16 rxCmNPduIdx;    /* Index of RxPdu */
    uint16 rxDtNPduIdx;    /* Index of RxPdu */
    uint16 startOfRxSduIdx;
    uint16 endOfRxSduIdx;

} J1939Tp_RxChannelType;

typedef struct
{
    boolean rxPgDynLengthSupport;
    uint32 rxPgPgn;
    uint16 rxNSduIdx;
    uint16 rxSduOfChannelIdx;
    uint16 SduLength;
    uint8 metaDataLength;
    uint16 rxDirectPduIdxOfTxPdu;
} J1939Tp_RxSdu_Type;

typedef struct
{
    boolean txCancellationSupport;
    uint8 txDa;
    boolean txDynamicBlockCalculation;
    uint8 txMaxPacketsPerBlock;
    uint8 txProtocolType;
    boolean txRetrySupport;
    uint8 txSa;
    uint16 rxConfitmIdx;
    uint16 txCmNPduIdx;
    uint16 txDtNPduIdx;
    uint16 startOfTxSduIdx;
    uint16 endOfTxSduIdx;

} J1939Tp_TxChannelType;

typedef struct
{
    boolean txPgDynLengthSupport;
    uint32 txPgPgn;
    PduIdType txNSduIdx;
    uint16 txSduOfChannelIdx;
    uint16 SduLength;
    uint8 metaDataLength;
    uint16 txDirectPduIdxOfTxPdu;

} J1939Tp_TxSdu_Type;

/* Type to access J1939Tp_TxPduState in an index and symbol based style. */
typedef struct
{
    uint16 ConfTimeout;
    J1939Tp_NSduType CurrentNSduType;
    PduIdType CurrentNSduId;
    boolean Locked;
} J1939Tp_TxPduStateType;

/* Type to access J1939Tp_TxSduState in an index and symbol based style. */
typedef struct
{
    uint32 Size;            /* Sdu size. */
    uint32 ByteOffset;      /* Pcakets offset (reserved). */
    PduLengthType DataSize; /* Data size. */
    J1939Tp_StateType State;/* Sdu state(J1939Tp_StateType). */
    J1939Tp_ConnectionAbortReasonType AbortReason; /* Abort reason. */
    uint16 TimeOut;         /* Sdu timeout. */
    uint8 Packets;          /* Number of (E)TP.DT frames for BAM/CMDT. */
    boolean Aborted;          /* Is abort (reserved).*/
    uint8 Sequence;         /* Sequence number for BAM/CMDT/ETP, frame counter for FPP. */
    uint8 NextBlock;        /* Packet number that starts the next block for BAM/CMDT/ETP. */
    uint8 MaxBlock;         /* Max block (reserved). */
    uint8 Sender;           /* Sender address. */
    uint8 Receiver;         /* Receiver address. */
    uint8 Priority;         /* Sdu priority. */
    uint8 RetryState;       /* Retry state. */
    uint16 TpDtCount;       /* TP.DT send count. */
} J1939Tp_TxSduStateType;

typedef struct
{
    PduIdType PduIdOfRxPdu;      /* PDU ID. */
    uint8 PduFormatOfRxPdu;      /* PDU format. */
    uint8 PduTypeOfRxPdu;        /* PDU Type. */
} J1939Tp_RxPduType;

typedef struct
{
    PduIdType PduIdOfTxPdu;      /* PDU ID. */
    uint8 PduTypeOfTxPdu;        /* PDU Type. */
} J1939Tp_TxPduType;

typedef struct
{
    uint16 ConfTimeout;         /* Pdu timeout. */
    PduIdType CurrentNSduId;    /* Current sdu id. */
    boolean Locked;             /* Is pdu locked. */
} J1939Tp_RxPduStateType;

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

#endif /* J1939TP_TYPES_H_ */
