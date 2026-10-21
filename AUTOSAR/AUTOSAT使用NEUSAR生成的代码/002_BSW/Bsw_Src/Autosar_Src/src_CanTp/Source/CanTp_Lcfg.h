/*
********************************************************************************
*
* File name: CanTp_Lcfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date : Tanlx/2019.03.10
* Change: New
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date : Tanlx/2019.10.12
* Change: Modify MIRSA-C code.
* Cause: Modify
********************************************************************************
* Version: 1.2
* Author/Date : Liuziyang/2019.11.19
* Change: The format of code and comment.
* Cause: Modify the code according to the coding specification.
********************************************************************************
* Version: 1.3
* Author/Date : Songqingwei/2020.01.22
* Change: Change the "enum CANTP_PHYSICAL" from 0 to 1.
* Cause: Access the addresss type according to the CanTpRxSdu struct.
********************************************************************************
* Version: 3.0
* Author/Date : ZhuCY/2021.10.28
* Change: Delete header file "Std_Types.h".
* Cause: Optimization.
********************************************************************************
* Version: 3.1
* Author/Date: YanCL/2024.7.3
* Change: 1.Add Memmap segment definition.
*         2.Update copyright information.
* Cause: Update
********************************************************************************
*/
#ifndef CANTP_LCFG_H_
#define CANTP_LCFG_H_

/*
********************************************************************************
* Includes
********************************************************************************
*/
#include "ComStack_Types.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANTP_RXSDU_NUM                                                (3U)
#define CANTP_RX_PDU_N72__PMS_PT_CANFD_20260425_DC_1__XQC0B_FUNC_DIAGREQ__XQC0B_INDEX  (1U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANTP_RX_PDU_N72__PMS_PT_CANFD_20260425_DC_1__XQC0B_PMS_DIAGREQ__XQC0B_INDEX  (0U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANTP_RX_PDU_N72__PMS_PT_CANFD_20260425_DC_2__XQC0B_PMS_OBD_DIAGREQ__XQC0B_INDEX  (2U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANTP_TXSDU_NUM                                                (2U)
#define CANTP_TX_PDU_N72__PMS_PT_CANFD_20260425_DC_1__XQC0B_PMS_DIAGRESP__XQC0B_INDEX  (0U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANTP_TX_PDU_N72__PMS_PT_CANFD_20260425_DC_2__XQC0B_PMS_OBD_DIAGRESP__XQC0B_INDEX  (1U)  /* PRQA S 0779 */ /* NSCA_QAC_Common_IdentifierLength */
#define CANTP_PADDING_PATTERN                                          (170U)
#define CANTP_MAIN_PERIOD                                              (5U)
#define CANTP_CHANNEL_NUM                                              (2U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
enum   
{
    CANTP_OFF,
    CANTP_ON
};

enum   
{
    CANTP_EXTENDED,
    CANTP_MIXED,
    CANTP_MIXED29BIT,
    CANTP_NORMALFIXED,
    CANTP_STANDARD
};

enum
{
    CANTP_CAN20,
    CANTP_CANFD,
};

enum
{
    CANTP_PHYSICAL = 1U,
    CANTP_FUNCTIONAL,
    CANTP_TA_ORTHER
};

typedef struct{
    PduIdType CanTpRxPduId; /* CanTP rx pdu Index from 0 to n. */
    PduIdType CanTpTxPduId; /* CanTP tx pdu Index from 0 to n, mapping is according to dcm. */
    PduIdType PduRRxPduId;  /* PduR rx pduId(PduRSourcePduHandleId). */
    uint8 CanTpRxAddressingFormat;
    uint8 CanTpRxTaType;
    uint8 CanTpRxPaddingActivation;
    uint8 CanTpRxDataLen;
    uint8 CanTpBs;
    uint16 CanTpRxWftMax;
    uint32 CanTpNar;
    uint32 CanTpNbr;
    uint32 CanTpNcr;
    uint32 CanTpSTmin;
    uint8 CanTpChnId;
} CanTpRxNSdu_st;

typedef struct{
    PduIdType CanTpTxPduId; /* CanTP tx pdu Index from 0 to n. */
    PduIdType CanIfTxPduId; /* CanIf tx pduId */
    PduIdType PduRTxPduId;  /* PduR tx pduId for dcm confirmation(PduRDestPduHandleId) */
    uint8 CanTpTxAddressingFormat;
    uint8 CanTpTxTaType;
    uint8 CanTpTxPaddingActivation;
    uint8 CanTpTxDataLen;
    uint32 CanTpNas;
    uint32 CanTpNbs;
    uint32 CanTpNcs;
    uint8 CanTpChnId;
    uint8 CanType;
    Std_ReturnType (*CanTp_TransmitToCanIf_p)(PduIdType CanIfTxSduId, const PduInfoType* CanIfTxInfoPtr);
} CanTpTxNSdu_st;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANTP_START_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

extern VAR(CanTpRxNSdu_st, CANTP_VAR_INIT) CanTpRxSdu[CANTP_RXSDU_NUM + 1U];
extern VAR(CanTpTxNSdu_st, CANTP_VAR_INIT) CanTpTxSdu[CANTP_TXSDU_NUM + 1U];

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANTP_STOP_SEC_VAR_INIT
/* Polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "CanTp_MemMap.h"

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

#endif

