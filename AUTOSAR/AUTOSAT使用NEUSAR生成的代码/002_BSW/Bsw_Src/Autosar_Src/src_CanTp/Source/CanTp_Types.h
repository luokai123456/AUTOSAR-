/*
********************************************************************************
*
* File name: CanTp_Types.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: Tanlx/2018.12.10
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: Tanlx/2019.10.12
* Change: Modify MIRSA-C code.
* Cause: Modify
********************************************************************************
* Version: 1.2
* Author/Date: Liuziyang/2019.11.19
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.3
* Author/Date: Songqingwei/2019.12.23
* Change: Add the macros of the TP_INVALIDPDUID.
* Cause: Features require.
********************************************************************************
* Version: 3.0
* Author/Date: Songqingwei/2020.05.15
* Change: Modify the coding specification.
* Cause: Optimize
********************************************************************************
* Version: 3.1
* Author/Date: LiuZY/2020.11.03
* Change: Modify the incorrectly defined part of the code format.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: SongQW/2020.12.06
* Change: Add macro.
* Cause: Update
********************************************************************************
* Version: 3.3
* Author/Date: ZhuCY/2021.04.13
* Change: Add macro for FC frame length.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: SongQW/2021.07.14
* Change: 1. Add macro "CANTP_FRAME_FFMASK", "CANTP_BYTE_ONE", "CANTP_BYTE_TWO",
*            "CANTP_BYTE_THREE", "CANTP_BYTE_FOUR", "CANTP_BYTE_FIVE",
*             "CANTP_BYTE_SIX" and "CANTP_FFDATALENGTH" for bugfix that solve
*             the problem of CANFD length is more than 4095.
*         2. The type of the "bsCounter" change from uint8 to uint32.
* Cause: Bugfix
********************************************************************************
* Version: 3.5
* Author/Date: SongQW/2021.09.06
* Change: 1. Change the lower case letters to uppercase letter for macro
*            "CANTP_STMIN_MILLISEC_MAX", "CANTP_STMIN_MICROSEC_MIN" and
*            "CANTP_STMIN_MICROSEC_MAX".
*         2. Add enum "CANTP_gOperatingType_e" to "U".
* Cause: Bugfix
********************************************************************************
* Version: 3.6
* Author/Date: SongQW/2022.01.25
* Change: Add "copyType" element to structure "CanTp_TxStateType_st" for the
*         gateway mode.
* Cause: Update
********************************************************************************
* Version: 3.7
* Author/Date: Tiang/2023.06.28
* Change: Add "canRxffDLC" to "CanTp_RxStateType_st".
* Cause: Update
********************************************************************************
* Version: 3.8
* Author/Date: YanCL/2024.4.2
* Change: Modify the annotation.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: YanCL/2024.7.3
* Change: Update copyright information.
* Cause: Update
********************************************************************************
* Version: 3.10
* Author/Date: YanCL/2025.2.8
* Change: Add macro definition: CANTP_NOTIFY_NOT_OK.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: YanCL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
*/
#ifndef CANTP_TYPES_H_
#define CANTP_TYPES_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "CanTp_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/* Frame type. */
#define CANTP_SF                           (0x00U)
#define CANTP_FF                           (0x10U)
#define CANTP_CF                           (0x20U)
#define CANTP_FC                           (0x30U)

/* Control bit of the FC. */
#define CANTP_FS_CTS                       (0x00U)  /* CANTP_FlowStatus_ClearToSend. */
#define CANTP_FS_WAIT                      (0x01U)  /* CANTP_FlowStatus_Wait. */
#define CANTP_FS_OVFLW                     (0x02U)  /* CANTP_FS_OVFLW. */

/* TP tx state machine. */
#define CANTP_TXSTATE_IDLE                 (0U)  /* TP tx state is idle. */
#define CANTP_TXSTATE_WAITFC               (1U)  /* TP wait for FC. */
#define CANTP_TXSTATE_WAITFORTPTXCF        (2U)  /* TP wait for send CF. */
#define CANTP_TXSTATE_WAITFORSFORFFCONFISR (3U)  /* Wait for tx isr confirmation of FF or SF. */
#define CANTP_TXSTATE_WAITFORCFCONFISR     (4U)  /* Wait for confirmation of CF. */

/* TP rx state machine. */
#define CANTP_RXSTATE_IDLE                 (0U)  /* TP rx state is idle. */
#define CANTP_RXSTATE_WAITCF               (1U)  /* TP wait for CF. */
#define CANTP_RXSTATE_WAITFORFCCONFISR     (2U)  /* Wait for tx isr confirmation of FC. */
#define CANTP_RXSTATE_WAITFORFCOVERCONFISR (3U)  /* TP response buffer overflow. */
#define CANTP_RXSTATE_USEDFORAPPL          (4U)  /* Rx resource is busy. */

/* Frame offset. */
#define CANTP_FMTOFFSET_FRAMETYPE          (0U)  /* Frame type. */
#define CANTP_FMTOFFSET_FRAMETYPE_CANFD    (1U)  /* CanFD frame type. */

#define CANTP_FMTOFFSET_BS                 (1U)  /* BS */
#define CANTP_FMTOFFSET_STMIN              (2U)  /* STmin */

/* Notify type. */
#define CANTP_NOTIFY                       (1U)  /* Notify */
#define CANTP_SILENT                       (0U)  /* Silent */
#define CANTP_NOTIFY_NOT_OK                (2U)  /* Notify NOT_OK */

/* Rx frame type. */
#define CANTP_CANRX_SF                     (0U)
#define CANTP_CANRX_FF                     (1U)
#define CANTP_CANRX_CF                     (2U)
#define CANTP_CANRX_FC                     (3U)
#define CANTP_CANINVALIDFRAME              (4U)

/* Date mask. */
#define CANTP_FRAME_LMASK                  (0x0FU)
#define CANTP_FRAME_HMASK                  (0xF0U)
#define CANTP_FRAME_FFMASK                 (0x0FFFU)

#define CANTP_STANDARD_FRAME_LENGTH        (8U)  /* CAN 2.0 standard frame length */
#define CANTP_DATELENPERMSG                (7U)  /* Data length per FF and CF. */
#define CANTP_SF_MIN_LEN                   (0U)  /* Min length per SF. */
#define CANTP_SF_MAX_LEN                   (7U)  /* Max length per SF. */
#define CANTP_MF_MIN_LEN                   (7U)  /* Min length per MF. */
#define CANTP_FF_DATA_LEN                  (6U)  /* Data length per FF. */
#define CANTP_FC_MIN_DATA_LEN              (8U)  /* Min length per FC. */

/* Data offset. */
#define CANTP_SF_OFFSET                    (1U)
#define CANTP_FF_OFFSET                    (2U)
#define CANTP_CF_OFFSET                    (1U)

#define CANTP_SF_OFFSET_CANFD              (2U)
#define CANTP_FF_OFFSET_CANFD              (2U)
#define CANTP_CF_OFFSET_CANFD              (1U)

#define CANTP_LEN_FC                       (3U)

#define CANTP_MF_MIN_LEN_CANFD             (63U)  /* Min length per MF for CANFD message. */
#define CANTP_LEN_CANFDDLC8                (8U)
#define CANTP_LEN_CANFDDLC12               (12U)
#define CANTP_LEN_CANFDDLC16               (16U)
#define CANTP_LEN_CANFDDLC20               (20U)
#define CANTP_LEN_CANFDDLC24               (24U)
#define CANTP_LEN_CANFDDLC32               (32U)
#define CANTP_LEN_CANFDDLC48               (48U)
#define CANTP_LEN_CANFDDLC64               (64U)
#define CANTP_SF_MAX_LEN_CANFD             (62U)  /* Max length per SF for CANFD message. */
#define CANTP_FF_DATA_LEN_CANFD            (62U)  /* Data length per FF for CANFD message. */

#define CANTP_DATELENPERMSG_CANFD          (63U)  /* Data length per CF for CANFD message. */

/* Last frame of the MF. */
#define CANTP_LASTCF                       (1U)
#define CANTP_NO_LASTCF                    (0U)

/* Data buffer. */
#if ( STD_ON == CANTP_CANFD_SUPPORT )
#define CANTP_REVDATALEN                   (64U)
#else
#define CANTP_REVDATALEN                   (8U)
#endif

#define CANTP_ZERO                         (0U)  /* Init value is 0. */
#define CANTP_INIT_ONE                     (1U)  /* Init value is 1. */
#define CANTP_INIT_TWO                     (2U)  /* Init value is 2. */
#define CANTP_INIT_FOUR                    (4U)  /* Init value is 4. */
#define CANTP_INIT_EIGHT                   (8U)  /* Init value is 8. */
#define CANTP_INIT_0X10                    (0x10U)  /* Init value is 0x10U. */
#define CANTP_INIT_0XF0                    (0xF0U)  /* Init value is 0xF0U. */
#define CANTP_INIT_0XFC                    (0xFCU)  /* Init value is 0xFC. */

#define CANTP_INVALIDPDUID                 (0xFFFFU)

#define CANTP_STMIN_PARA_HIGH              (0x80U)

#define CANTP_STATUS_NOT_INITIALIZED    CANTP_OFF
#define CANTP_STATUS_INITIALIZED        CANTP_ON
#define CANTP_STATUS_SHUTDOWN           CANTP_STATUS_NOT_INITIALIZED

/* STmin values. */
#define CANTP_STMIN_MILLISEC_MAX        (0x7FU)
#define CANTP_STMIN_MICROSEC_MIN        (0xF1U)
#define CANTP_STMIN_MICROSEC_MAX        (0xF9U)

#define CANTP_SERVICEID_3E              (0x3EU)
#define CANTP_SUBSERVICEID_80           (0x80U)

#ifndef NTFRSLT_OK
#define NTFRSLT_OK       (0x00U)
#endif

#ifndef NTFRSLT_E_NOT_OK
#define NTFRSLT_E_NOT_OK (0x01U)
#endif

#define CANTP_BYTE_ONE            (0x01U)
#define CANTP_BYTE_TWO            (0x02U)
#define CANTP_BYTE_THREE          (0x03U)
#define CANTP_BYTE_FOUR           (0x04U)
#define CANTP_BYTE_FIVE           (0x05U)
#define CANTP_BYTE_SIX            (0x06U)
#define CANTP_FFDATALENGTH        (0x0FFFU)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef uint8  CanTp_InitStatusType;  /* Initialization Status. */

typedef enum
{
  CANTP_IDLE = 0U,     /* Default value. */
  CANTP_RX,            /* Rx direction. */
  CANTP_TX             /* Tx direction. */
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
}CANTP_gOperatingType_e;

/* Rx data struction. */
typedef struct
{
    uint8 frameType;           /* Frame type. */
    uint8 channelState;        /* Channel state. */
    uint8 stmin;               /* STMIN */
    uint8 queued;              /* Send request. */
    uint8 expectedSN;          /* SN */
    uint16 timer;              /* Timer */
    uint16 wftCounter;         /* WFT counter. */
    uint16 wftCurCounter;      /* WFT current counter. */
    PduIdType rxPduId;         /* PDU Id. */
    uint32 bsCounter;          /* BS */
    PduLengthType dataLen;     /* Current data length. */
    uint8* dataBufferPtr;      /* Data buffer. */
    uint32 canRxffDlc;         /* CANRX FF DLC . */
}CanTp_RxStateType_st;

/*Tx data struction. */
typedef struct
{
    uint8 frameType;           /* Frame type. */
    uint8 channelState;        /* Channel state. */
    uint8 stmin;               /* STMIN */
    uint8 timerStmin;          /* STMIN Caculate. */
    uint8 queued;              /* Send request. */
    uint8 seqNumber;           /* SN */
    boolean copyType;          /* TRUE: Call PduR_CanTpCopyTxData. */
    PduIdType rxPduId;         /* PDU Id. */
    PduIdType txPduId;         /* PDU Id. */
    uint16 timer;              /* Timer */
    uint16 dataLength;         /* Send data length. */
    uint16 totalDataLength;    /* Send total data length. */
    uint32 bsCounter;          /* BS */
    uint8* dataBufferPtr;      /* Data buffer. */
}CanTp_TxStateType_st;

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

#endif  /* CANTP_TYPES_H_ */
