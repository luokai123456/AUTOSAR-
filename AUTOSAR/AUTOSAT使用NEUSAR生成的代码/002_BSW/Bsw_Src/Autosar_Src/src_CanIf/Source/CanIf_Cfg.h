/*
********************************************************************************
*
* File name: CanIf_Cfg.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: WangCong/2019.10.01
* Change: New
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: YanCL/2023.10.30
* Change: Example Change the PduIdNum type to uint16.
* Cause: Bugfix
********************************************************************************
* Version: 3.2
* Author/Date: YanCL/2024.7.15
* Change: Update copyright information.
* Cause: Update
********************************************************************************
*/
#ifndef CANIF_CFG_H_
#define CANIF_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "CanIf_Types.h"
/* polyspace +2 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */	
	
#define CANIF_CANSM_CBK_ENABLE
#include "CanSM_Cbk.h"
	

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define CANIF_PRIVATE_DLC_CHECK_SPECIAL_CA 
#define CANIF_AUTOSAR_VERSION_431_SUPPORT 
#define CANIF_METADATA_SUPPORT                 (STD_ON)

#define CANIF_PUB_CANCEL_TRANSMIT_SUP          (STD_OFF)

#define CANIF_DEV_ERROR_DETECT                 (STD_ON)

#define CANIF_PUB_ICOM_SUPPORT                 (STD_OFF)

#define CANIF_PUB_MULTIPLE_DRV_SUP             (STD_ON)

#define CANIF_PUB_PN_SUPPORT                   (STD_OFF)

#define CANIF_PUB_READRXPDU_DATA_API           (STD_OFF)

#define CANIF_PUB_READRXPDU_NTF_STA_API        (STD_OFF)

#define CANIF_PUB_READTXPDU_NTF_STA_API        (STD_OFF)

#define CANIF_PUB_SETDYNAMIC_TXID_API          (STD_OFF)

#define CANIF_PUB_TXBUFFERING                  (STD_OFF)

#define CANIF_PUB_TXCONFIRM_POLLING            (STD_ON)

#define CANIF_PUB_WUCHKVAL_BYNM                (STD_OFF)

#define CANIF_PUB_WUCHKVAL_SUP                 (STD_OFF)

#define CANIF_PUB_SETBAUDRATE_API              (STD_ON)

#define CANIF_TRI_TRANSMIT_SUP                 (STD_ON)

#define CANIF_PUB_VERSION_API                  (STD_ON)

#define CANIF_TXOFFLINEACTIVE_SUP              (STD_OFF)

#define CANIF_WAKEUP_SUPPORT                   (STD_ON)

#define CANIF_PRIVATE_DLC_CHECK                (STD_ON)

#define CANIF_SUPPORT_TTCAN                    (STD_OFF)

#define CANIF_PRIVATE_FIXEDBUF                 (STD_OFF)

#define CANIF_PRIVATE_SWFILTER_TYPE            CANIF_SWFILTER_BINARY

#define CANIF_CANTRCV_SUPPORT                  (STD_OFF)

#define CanIf_User_ControllerBusOff            CanSM_ControllerBusOff

#define CanIf_User_ControllerModeIndication    CanSM_ControllerModeIndication

#define CanIf_User_ValidateWakeupEvent         EcuM_ValidateWakeupEvent


/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef Std_ReturnType (*CanIf_TriggerTransmitFctType)(PduIdType TxPduId,PduInfoType* PduInfoPtr);
typedef void (*CanIf_TxConfirmationFctType)(PduIdType CanTxPduId);
typedef void (*CanIf_RxIndicationFctListType)(PduIdType RxPduId, const PduInfoType* PduInfoPtr);

#ifdef  CANIF_AUTOSAR_VERSION_431_SUPPORT
typedef Std_ReturnType (*CanIf_Can_WriteFuncType)( Can_HwHandleType Hth, const Can_PduType* PduInfo );
typedef Std_ReturnType (*CanIf_Can_SetCtrlModeFuncType)( uint8 Controller, Can_ControllerStateType Transition );
#else   /* CANIF_AUTOSAR_VERSION_431_SUPPORT */
typedef Can_ReturnType (*CanIf_Can_WriteFuncType)( Can_HwHandleType Hth, const Can_PduType* PduInfo );
typedef Can_ReturnType (*CanIf_Can_SetCtrlModeFuncType)( uint8 Controller, Can_StateTransitionType Transition );
#endif  /* CANIF_AUTOSAR_VERSION_431_SUPPORT */

/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef uint16 CanIf_HwObjectType;

typedef enum
{
    CANIF_RECEIVE = 0U,   /* Receive. */
    CANIF_TRANSMIT        /* Transmit. */
} CanIf_CanObjectType;

typedef enum
{
    CANIF_TXPDU_STATIC    = 0U,
    CANIF_TXPDU_DYNAMIC   = 1U
} CanIf_TxPudType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct CanIf_TxMBBufTypeTag
{
    VAR(PduIdType, TYPEDEF) CanIfTxSduId;
    VAR(PduInfoType, TYPEDEF) CanIfTxInfo;
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} CanIf_TxMBBufType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct CanIf_TrcvMapTypeTag
{
    VAR(uint8, TYPEDEF) CanIf_TrcvId; /* Cfg:CanIfTrcvId. */
    VAR(uint8, TYPEDEF) CanTrcvId;    /* Cfg:CanIfTrcvCanTrcvRef --- CanTrcvChannelId. */
} CanIf_TrcvMapType;

typedef struct 
{
    VAR(PduIdType, TYPEDEF) pduId;
    VAR(uint8, TYPEDEF) txLen;
    VAR(Can_IdType, TYPEDEF) canId;
    /* Polyspace +1 DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_CanIf_HARD_CODED_BUFFER_SIZE" */
    uint8 txData[8U];
} CanIf_TxBufType;

typedef struct 
{
    VAR(PduIdType, TYPEDEF) pduId;
    VAR(uint8, TYPEDEF) txLen;
    VAR(Can_IdType, TYPEDEF) canId;
    /* Polyspace +1 DEFECT:HARD_CODED_BUFFER_SIZE [Justified:Unset] "NSCA_Polyspace_CanIf_HARD_CODED_BUFFER_SIZE" */
    uint8 txData[64U];
} CanIf_TxBuf_CANFDType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct CanIf_CanObjectMapTypeTag
{
    VAR(CanIf_CanObjectType, TYPEDEF) ObjectType; /* Cfg: CanObjectType. */
    P2CONST(PduIdType, TYPEDEF, CANIF_APPL_CONST) PduIdPtr;      /* Cfg: CanIfRxPduId OR Cfg: CanIfRxPduId. */
    VAR(uint16, TYPEDEF) PduIdNum;                 /* Cfg: CanIfRxPduId Num OR Cfg: CanIfRxPduId Num. */
    VAR(uint8, TYPEDEF) TxBufSize;
    P2VAR(CanIf_TxBufType, TYPEDEF, CANIF_APPL_DATA) TxBufPtr;
    P2VAR(CanIf_TxBuf_CANFDType, TYPEDEF, CANIF_APPL_DATA) TxBufCANFDPtr;
    P2VAR(uint16, TYPEDEF, CANIF_APPL_DATA) write;
    P2VAR(uint16, TYPEDEF, CANIF_APPL_DATA) read;
    VAR(boolean, TYPEDEF) basicCan;             /* Cfg:  */
} CanIf_CanObjectMapType;

typedef struct
{
    VAR(CanIf_Can_WriteFuncType, TYPEDEF) CanIf_Can_WriteFunc;    /* Can_Write. */
    VAR(CanIf_Can_SetCtrlModeFuncType, TYPEDEF) CanIf_Can_SetCtrlModeFunc;    /* Can_SetControllerMode. */
    P2CONST(CanIf_CanObjectMapType, TYPEDEF, CANIF_APPL_CONST) canObjectMapPtr;    /* CanHardwareObjects. */
    VAR(uint16, TYPEDEF) canObjectNum;
    /* VAR(uint8, TYPEDEF) canControllerId; */
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} CanIf_CanMultipeDrvInfoType;

/* polyspace +1 MISRA-C3:2.4 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
typedef struct Can_MsgCycles_typ
{
    VAR(uint16, TYPEDEF) canPduId;           /* canPduId. */
    VAR(uint16, TYPEDEF) CanHOH;             /* HOH. */
    VAR(uint8, TYPEDEF) hwchanlNo;          /* hardware channel number. */
    VAR(uint16, TYPEDEF) upperPduId;         /* up layer Pdu Id. */
    VAR(Can_IdType, TYPEDEF) msgID;          /* Message Identifier. */
    VAR(uint32, TYPEDEF) msgIDMask;          /* Acceptance ID mask. */
    VAR(uint8, TYPEDEF) msgDir;             /* Message Direction. */
    VAR(uint16, TYPEDEF) msgDlc;             /* Message Data Length. */
    VAR(uint8, TYPEDEF) moMode;             /* MailBox multiplexer mode. */
    VAR(uint8, TYPEDEF) intr;               /* Interrupt select. */
    P2VAR(uint8, TYPEDEF, CANIF_APPL_DATA) mailboxNo;          /* can message mailbox number. */
    P2VAR(uint8, TYPEDEF, CANIF_APPL_DATA) dataraw;            /* pointer to dataraw. */
    VAR(uint8, TYPEDEF) CanIf_CbkType;      /* Index Cbk type. */
                                    /* 0 */ /* [NULL_PTR] */
                                    /* 1 */ /* [CanNm] */
                                    /* 2 */ /* [CanTp] */
                                    /* 3 */ /* [J1939Tp] */
                                    /* 4 */ /* [Xcp] */
/* polyspace +1 MISRA-C3:2.3 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
} Can_MsgCycles_st;

typedef struct
{
    VAR(uint16, TYPEDEF) rxPduId;                                   /* CanIfRxPduId */
    VAR(uint8, TYPEDEF) ctrlId;                                 /* CanIfRxPduHrhIdRef */
    VAR(boolean, TYPEDEF) canIdRang;                                /* CanIfRxPduCanIdRange */
    VAR(Can_IdType, TYPEDEF) canId;                             /* CanIfRxPduCanId or CanIfRxPduCanIdRangeLowerCanId, CanIfRxPduCanIdType */
    VAR(Can_IdType, TYPEDEF) canIdMask;                         /* CanIfRxPduCanIdMask or CanIfRxPduCanIdRangeUpperCanId, CanIfRxPduCanIdType */
    VAR(uint16, TYPEDEF) rxPduDlc;                              /* CanIfRxPduDlc */
    VAR(uint8, TYPEDEF) metaDataLen;                            /* CanIfRxPduReadData */
    VAR(boolean, TYPEDEF) rxReadNotify;                         /* CanIfRxPduReadNotifyStatus */
    VAR(CanIf_RxIndicationFctListType, TYPEDEF) rxIndcCallback; /* CanIfRxPduUserRxIndicationName & CanIfRxPduUserRxIndicationUL */
    P2CONST(CanIf_CanObjectMapType, TYPEDEF, CANIF_APPL_CONST) hrhPtr;          /* CanIfRxPduHrhIdRef */
    VAR(uint16, TYPEDEF) upperLayerPduId;                           /* CanIfRxPduRef */
} CanIf_RxPduCfgType;

typedef struct
{
    VAR(uint16, TYPEDEF) txPduId;                                   /* CanIfTxPduId */
    VAR(uint8, TYPEDEF) ctrlId;                                 /* CanIfTxPduHrhIdRef */
    VAR(Can_HwHandleType, TYPEDEF) hth;                         /* CanIfTxPduHthIdRef */
    P2VAR(Can_IdType, TYPEDEF, CANIF_APPL_DATA) canId;          /* CanIfTxPduCanId, CanIfTxPduCanIdType */
    VAR(Can_IdType, TYPEDEF) canIdMask;                         /* CanIfTxPduCanIdMask, CanIfTxPduCanIdType */
    VAR(boolean, TYPEDEF) pnFilter;                             /* CanIfTxPduPnFilterPdu */
    VAR(boolean, TYPEDEF) txReadNotify;                         /* CanIfTxPduReadNotifyStatus */
    VAR(boolean, TYPEDEF) triggerTransmit;                      /* CanIfTxPduTriggerTransmit */
    VAR(CanIf_TxPudType, TYPEDEF) txPduType;                        /* CanIfTxPduType */
    VAR(CanIf_TriggerTransmitFctType, TYPEDEF) trggTransmitFunc;    /* CanIfTxPduUserTxConfirmationName & CanIfTxPduUserTxConfirmationUL */
    VAR(CanIf_TxConfirmationFctType, TYPEDEF) TxCfmCallback;        /* CanIfTxPduUserTxConfirmationName & CanIfTxPduUserTxConfirmationUL */
    P2CONST(CanIf_CanObjectMapType, TYPEDEF, CANIF_APPL_CONST) hthPtr;          /* CanIfTxPduHthIdRef */
    VAR(uint16, TYPEDEF) upperLayerPduId;                           /* CanIfTxPduRef */
    VAR(uint8, TYPEDEF) metaDataLen;                            /* CanIfTxPduMetaData */
} CanIf_TxPduCfgType;

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

#endif /* CANIF_CFG_H_ */

