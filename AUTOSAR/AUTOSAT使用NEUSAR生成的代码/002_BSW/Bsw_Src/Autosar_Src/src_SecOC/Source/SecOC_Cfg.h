/*
********************************************************************************
*
* File name: SecOC_Cfg.h
*
* Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: ZhangY/2021.11.12
* Change: New created
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: FangT/2022.01.15
* Change: 1.Added SecOC_ConfigType type and SecOC_Config constant declaration.
*         2.Modify code specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: TianSL/2024.07.08
* Change: 1.Add header file Csm.h.
*         2.Delete not used macro.
*         3.Add SecOCTxAuthServiceProcType member to SecOCTxPduProcessingType.
*         4.Add SecOCRxAuthServiceProcType member to SecOCRxPduProcessingType.
* Cause: Optimization
********************************************************************************
*/
#ifndef SECOC_CFG_H_
#define SECOC_CFG_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "ComStack_Types.h"
#include "Std_Types.h"
#include "Rte_SecOC_Type.h"
#include "Csm.h"
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define SECOC_CFUNC (0U)
#define SECOC_RTE   (1U)
#define SECOC_IFPDU                 (0U)
#define SECOC_TPPDU                 (1U)
#define SECOC_NOUSED_DEM            (0xFFFFU)
/* /AUTOSAR/EcucDefs/SecOC/SecOCGeneral */
#define SECOC_DEFAULTAUTHENTICATIONINFORMATIONPATTERN (0U)
#define SECOC_DEVERRORDETECT (STD_ON)
#define SECOC_ENABLEFORCEDPASSOVERRIDE (STD_OFF)
#define SECOC_IGNOREVERIFICATIONRESULT (STD_OFF)
#define SECOC_MAINFUNCTIONPERIODRX (10U)
#define SECOC_MAINFUNCTIONPERIODTX (10U)
#define SECOC_MAXALIGNSCALARTYPE (uint8)
#define SECOC_OVERRIDESTATUSWITHDATAID (STD_ON)
#define SECOC_QUERYFRESHNESSVALUE (SECOC_CFUNC)
#define SECOC_VERSIONINFOAPI (STD_ON)

#define SECOC_NUM_TXPDUPRO (1U)
#define SECOC_NUM_SECUREDAREA (1U)
#define SECOC_NUM_SECUREDLAYERINS (1U)
#define SECOC_NUM_SECUREDPDU (1U)
#define SECOC_NUM_SECUREDPDUCOLL (0U)
#define SECOC_NUM_AUTHENTICPDULAYER (1U)
#define SECOC_NUM_TXAUTHENTICPDU (0U)
#define SECOC_NUM_TXCRYPTOGRAPHICPDU (0U)
#define SECOC_NUM_USEMESSAGELINK_TX (0U)
#define SECOC_NUM_USEMESSAGELINK_RX (0U)

#define SECOC_NUM_RXPDUPRO (1U)
#define SECOC_NUM_RXAUTHENTICPDULAYER (1U)
#define SECOC_NUM_RXSECUREDPDU (1U)
#define SECOC_NUM_RXSECUREDAREA (1U)
#define SECOC_NUM_RXSECUREDPDULAYER (1U)
#define SECOC_NUM_RXSECUREDPDUCOLL (0U)
#define SECOC_NUM_RXAUTHENTICPDU (0U)
#define SECOC_NUM_RXCRYPTOGRAPHICPDU (0U)

#define SECOC_MAX_RXSECURE_LEN (30U)
#define SECOC_MAX_TXSECURE_LEN (64U)
#define SECOC_E_VERIFY_FAILED (SECOC_NOUSED_DEM)
#define SECOC_E_AUTHENTICATE_FAILED (SECOC_NOUSED_DEM)
#define SECOC_E_FRESHNESS_FAILED (SECOC_NOUSED_DEM)
#define SECOC_VERIFYATTEMPTS (0U)
#define SECOC_ENABLEDEFAULTCODE (STD_OFF)
#define SECOC_E_NOINITED (SECOC_NOUSED_DEM)
#define SECOC_IMMEDIATE_RETRY (STD_OFF)
#define SECOC_TXPDUTYPE (SECOC_IFPDU)
#define SECOC_RXPDUTYPE (SECOC_IFPDU)

#define SECOC_E_INITED_FAILED (SECOC_NOUSED_DEM)

#define SECOC_SETMODE (STD_OFF)
/* polyspace-begin MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define SECOC_RXPDU_NUM (1U)
#define SECOC_RXPDU_TOTAL_TABLES (1U)
#define SecOC_MainFunctionRx() SecOC_MainFunction_Rx(0U)
#define SECOC_TXPDU_NUM (1U)
#define SECOC_TXPDU_TOTAL_TABLES (1U)
#define SecOC_MainFunctionTx() SecOC_MainFunction_Tx(0U)
/* polyspace-end MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
/*
********************************************************************************
*    Global Types
********************************************************************************
*/

/* ECUC_SecOC_00072 This container specifies the PDU (that is transmitted by the SecOC module to the PduR)
which contains the Secured I-PDU Header and the Authentic I-PDU. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint8 SecOCPduType;
    uint16 SecOCTxAuthenticPduId;
    uint16 SecOCTxAuthenticPduRef;
} SecOCTxAuthenticPduLayerType;

/* ECUC_SecOC_00070 This container specifies one Pdu that is transmitted by the SecOC module to the PduR after the
Mac was generated. This Pdu contains the cryptographic information. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint8 SecOCAuthPduHeaderLength;
    uint16 SecOCTxSecuredLayerPduId;
    uint16 SecOCTxSecuredLayerPduRef;
} SecOCTxSecuredPduType;

/* ECUC_SecOC_00072 This container specifies the PDU (that is transmitted by the SecOC module to the PduR)
which contains the Secured I-PDU Header and the Authentic I-PDU. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint8 SecOCAuthPduHeaderLength;
    uint16 SecOCTxAuthenticPduId;
    uint16 SecOCTxAuthenticPduRef;
} SecOCTxAuthenticPduType;

/* ECUC_SecOC_00073 This container specifies the Cryptographic Pdu that is transmitted by the SecOC module to the PduR
after the Mac was generated. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint16 SecOCTxCryptographicPduId;
    uint16 SecOCTxCryptographicPduRef;
} SecOCTxCryptographicPduType;

/* ECUC_SecOC_00074 SecOC links an Authentic I-PDU and Cryptographic I-PDU together by repeating a specific part (Message Linker)
of the Authentic I-PDU in the Cryptographic I-PDU. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint16 SecOCMessageLinkLen;
    uint16 SecOCMessageLinkPos;
} SecOCUseMessageLinkType;

/* ECUC_SecOC_00071 This container specifies the Pdu that is transmitted by the SecOC module to the PduR after the Mac was generated.
Two separate Pdus are transmitted to the PduR: Authentic I-PDU and Cryptographic I-PDU.*/
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    const SecOCTxAuthenticPduType* SecOCTxAuthenticPdu;
    const SecOCTxCryptographicPduType* SecOCTxCryptographicPdu;
    const SecOCUseMessageLinkType* SecOCUseMessageLink;
} SecOCTxSecuredPduCollectionType;

/* ECUC_SecOC_00086 This container specifies an area in the Authentic I-Pdu that will be the input to the Authenticator generation algorithm.
If this container does not exist in the configuration the complete Authentic I-Pdu will be the input to the Authenticator generation algorithm. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint32 SecOCSecuredTxPduLength;
    uint32 SecOCSecuredTxPduOffset;
} SecOCTxPduSecuredAreaType;

/* polyspace +1 MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define TxSecuredPdu
/* ECUC_SecOC_00024 This container specifies the Pdu that is transmitted by the SecOC module to the PduR after the Mac was generated. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    const SecOCTxSecuredPduType* SecOCTxSecuredPdu;
    const SecOCTxSecuredPduCollectionType* SecOCTxSecuredPduCollection;
} SecOCTxSecuredPduLayerType;

/* ECUC_SecOC_00012 Contains the parameters to configure the TxPdus to be secured by the SecOC module.*/
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint16 SecOCAuthenticationBuildAttempts;
    uint32 SecOCAuthInfoTruncLength;
    uint16 SecOCDataId;
    uint16 SecOCFreshnessValueId;
    uint32 SecOCFreshnessValueLength;
    uint32 SecOCFreshnessValueTruncLength;
    boolean SecOCProvideTxTruncatedFreshnessValue;
    boolean SecOCFreshnessValueSynMessage;
    boolean SecOCUseTxConfirmation;
    uint32 SecOCTxAuthServiceConfigRef;
    Crypto_ProcessingType SecOCTxAuthServiceProcType;  /* SecOC tx auth service process type */
    const SecOCTxAuthenticPduLayerType* SecOCTxAuthenticPduLayer;
    const SecOCTxSecuredPduLayerType* SecOCTxSecuredPduLayer;      /* SecOCTxSecuredPdu or SecOCTxSecuredPduCollectionType */
    const SecOCTxPduSecuredAreaType* SecOCTxPduSecuredArea;
} SecOCTxPduProcessingType;

/* ECUC_SecOC_00044 This container specifies the Pdu that is transmitted by the SecOC module to the PduR after the Mac was verified. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint8 SecOCPduType;
    uint16 SecOCRxAuthenticLayerPduRef;
} SecOCRxAuthenticPduLayerType;

/* ECUC_SecOC_00069 This container specifies the Pdu that is received by the SecOC module from the PduR.
For this Pdu the Mac verification is provided. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint8 SecOCAuthPduHeaderLength;
    uint16 SecOCRxSecuredLayerPduId;
    boolean SecOCSecuredRxPduVerification;
    uint16 SecOCRxSecuredLayerPduRef;
} SecOCRxSecuredPduType;

/* ECUC_SecOC_00061 This container specifies the PDU (that is received by the SecOC module from the PduR)
which contains the Secured I-PDU Header and the Authentic I-PDU. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint8 SecOCAuthPduHeaderLength;
    uint16 SecOCRxAuthenticPduId;
    uint16 SecOCRxAuthenticPduRef;
} SecOCRxAuthenticPduType;

/* ECUC_SecOC_00064 This container specifies the Cryptographic Pdu that is received by the SecOC module from the PduR. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint16 SecOCRxCryptographicPduId;
    uint16 SecOCRxCryptographicPduRef;
} SecOCRxCryptographicPduType;

/* ECUC_SecOC_00067 This container specifies two Pdus that are received by the SecOC module from the PduR
and a message linking between them. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    boolean SecOCSecuredRxPduVerification;
    const SecOCRxAuthenticPduType* SecOCRxAuthenticPdu;
    const SecOCRxCryptographicPduType* SecOCRxCryptographicPdu;
    const SecOCUseMessageLinkType* SecOCUseMessageLink;
} SecOCRxSecuredPduCollectionType;

/* ECUC_SecOC_00041 This container specifies the Pdu that is received by the SecOC module from the PduR.
For this Pdu the Mac verification is provided. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    const SecOCRxSecuredPduType* SecOCRxSecuredPdu;
    const SecOCRxSecuredPduCollectionType* SecOCRxSecuredPduCollection;
}SecOCRxSecuredPduLayerType;

/* ECUC_SecOC_00089 This container specifies an area in the Authentic I-Pdu that will be the input to the Authenticator verification algorithm.
If this container does not exist in the configuration the complete Authentic I-Pdu will be the input to the Authenticator verification algorithm.*/
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint32 SecOCSecuredRxPduLength;
    uint32 SecOCSecuredRxPduOffset;
} SecOCRxPduSecuredAreaType;

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint16 SecOCValueId;
    uint8 SecOCNumberOfMessages;
    SecOC_OverrideStatusType SecOCOverrideStatus;
}SecOC_RxPdu_OverrideStatusType;
/* ECUC_SecOC_00011 Contains the parameters to configure the RxPdus to be verified by the SecOC module. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    uint16 SecOCAuthDataFreshnessLen;
    uint16 SecOCAuthDataFreshnessStartPosition;
    uint16 SecOCAuthenticationBuildAttempts;
    uint16 SecOCAuthenticationVerifyAttempts;
    uint32 SecOCAuthInfoTruncLength;
    uint16 SecOCDataId;
    uint16 SecOCFreshnessValueId;
    uint8 SecOCFreshnessValueLength;
    uint32 SecOCFreshnessValueTruncLength;
    uint8 SecOCReceptionOverflowStrategy;
    uint16 SecOCReceptionQueueSize;
    boolean SecOCUseAuthDataFreshness;
    boolean SecOCFreshnessValueSynMessage;
    uint8 SecOCVerificationStatusPropagationMode;
    uint32 SecOCRxAuthServiceConfigRef;
    Crypto_ProcessingType SecOCRxAuthServiceProcType;  /* SecOC rx auth service process type */
    const SecOCRxAuthenticPduLayerType* SecOCRxAuthenticPduLayer;
    const SecOCRxSecuredPduLayerType* SecOCRxSecuredPduLayer;
    const SecOCRxPduSecuredAreaType* SecOCRxPduSecuredArea;
    uint8 authDataLen;  /* Reach Add */
    SecOC_RxPdu_OverrideStatusType* SecOCRxPduOverrideStatus;
} SecOCRxPduProcessingType;

/* [SWS_SecOC_00104] Configuration data structure of SecOC module. */
typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    const SecOCTxPduProcessingType* SecOCTxPduProcessing;
    const SecOCRxPduProcessingType* SecOCRxPduProcessing;
} SecOC_ConfigType;

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    const uint16* pduTxInfo;                              /* index of SecOCTxPduProcessingIns */
    uint16 pduNum;                                        /* total number of tx Pdus which have the same Tx time period. */
} SecOC_TxPduInfoTableType;

typedef struct
/* polyspace +1 MISRA-C3:D4.8 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.8" */
{
    const uint16* pduRxInfo;                              /* index of SecOCRxPduProcessingIns */
    uint16 pduNum;                                        /* total number of rx Pdus which have the same Tx time period. */
} SecOC_RxPduInfoTableType;
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
#define SECOC_START_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"
extern VAR(SecOC_RxPdu_OverrideStatusType, SECOC_VAR_INIT) SecOC_RxPdu_OverrideStatus[SECOC_NUM_RXPDUPRO];
#define SECOC_STOP_SEC_VAR_INIT
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"


#define SECOC_START_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"

#if( SECOC_NUM_TXPDUPRO > 0U )
extern CONST( SecOCTxPduProcessingType, SECOC_CONFIG_DATA) SecOCTxPduProcessingIns[SECOC_NUM_TXPDUPRO];
#endif

#if( SECOC_NUM_RXPDUPRO > 0U )
extern CONST( SecOCRxPduProcessingType, SECOC_CONFIG_DATA) SecOCRxPduProcessingIns[SECOC_NUM_RXPDUPRO];
#endif

extern CONST(SecOC_ConfigType, SECOC_CONFIG_DATA) SecOC_Config;

extern CONST(SecOC_RxPduInfoTableType, SECOC_CONFIG_DATA) SecOC_RxPduInfoTable[SECOC_RXPDU_TOTAL_TABLES];
extern CONST(SecOC_TxPduInfoTableType, SECOC_CONFIG_DATA) SecOC_TxPduInfoTable[SECOC_TXPDU_TOTAL_TABLES];

#define SECOC_STOP_SEC_CONFIG_DATA
/* PolySpace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif  /* SECOC_CFG_H_ */

