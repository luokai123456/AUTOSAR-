/*
********************************************************************************
*
*  File name: SecOC.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
* History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 1.0
* Author/Date: ZhangY/2020.05.09
* Change: New created.
* Cause: New
********************************************************************************
* Version: 1.1
* Author/Date: FangT/2021.08.05
* Change: Delete the redundant content in the IPDU_BufType structure.
* Cause: New
********************************************************************************
* Version: 1.2
* Author/Date: FangT/2021.08.18
* Change: Remove duplicate function declarations.
* Cause: New
********************************************************************************
* Version: 3.0
* Author/Date: FangT/2021.09.01
* Change: Eliminate compilation warnings.
* Cause: Optimization
********************************************************************************
* Version: 3.1
* Author/Date: FangT/2021.09.01
* Change: Added SecOc_TxPduBuf and SecOc_RxPduBuf declarations.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: FangT/2021.10.29
* Change: Modify coding style.
* Cause: Optimization
********************************************************************************
*  Version: 3.3
*  Author/Date: FangT/2021.11.01
*  Change: Update software version to 3.2.1.
*  Cause: Update
********************************************************************************
*  Version: 3.3
*  Author/Date: FangT/2022.08.10
*  Change: Update software version to 3.2.2.
*  Cause: Update
********************************************************************************
*  Version: 3.4
*  Author/Date: FangT/2022.11.16
* Change: 1.Support Tp transmission function.
*         2.Support PduCollection.
*         3.Add Dem verification fault.
*         4.Add default code function.
*         5.Update software version to 3.2.3.
*  Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: FangT/2022.11.25
* Change: 1.Back to version 3.3.
*         2.Update software version to 3.2.4.
* Cause: Optimization
********************************************************************************
* Version: 3.6
* Author/Date: FangT/2022.12.12
* Change: 1.Add Dem verification fault.
*         2.Add default code function.
*         3.Update software version to 3.2.5.
* Cause: Optimization
********************************************************************************
* Version: 3.7
* Author/Date: FangT/2022.12.27
* Change: Clear QAC static code check warning problems above level 4.
* Cause: Optimization
********************************************************************************
* Version: 3.8
* Author/Date: FangT/2023.03.01
* Change: 1.Adapt Rte function.
*         2.Update software version to 3.2.6.
* Cause: Optimization
********************************************************************************
* Version: 3.9
* Author/Date: FangT/2023.04.20
* Change: 1.Add SecOC enable and disable functions.
*         2.Update software version to 3.2.7.
*         3.Add AutoSAR version description.
* Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: FangT/2023.05.17
* Change: Update software version to 3.7.0.
* Cause: Optimization
********************************************************************************
* Version: 3.11
* Author/Date: FangT/2023.05.26
* Change: Add SECOC_REVISION_VERSION.
* Cause: Optimize
********************************************************************************
* Version: 3.12
* Author/Date: ZhangF/2024.07.05
* Change: 1.Update software version to 3.11.0.1.
*         2.Add the async process for the Csm job.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: ZhangF/2024.07.13
* Change: Add the struct member verifyPtr in the struct SecOC_IPDU_BufType.
* Cause: Optimize
********************************************************************************
* Version: 3.14
* Author/Date: TianSL/2024.07.15
* Change: 1.Add Memmap segment definition.
*         2.Modify copyright.
* Cause: Update
********************************************************************************
* Version: 3.15
* Author/Date: ZhangF/2024.07.15
* Change: Add the SECOC_INDEX macro definition.
* Cause: Update
********************************************************************************
* Version: 3.16
* Author/Date: ZhangF/2024.08.30
* Change: 1.Add the SECOC_BYPASS_TXPDUSTATE macro definition.
*         2.Update the software version to 3.11.0.2.
* Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: TianSL/2024.09.11
* Change: Update the software version to 3.11.0.3.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: TianSL/2024.09.18
* Change: Add SecOC_VerificationStatusService function declaration.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: TianSL/2024.10.11
* Change: Update the software version to 3.11.0.4.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: TianSL/2024.10.16
* Change: Update the software version to 3.12.0.5.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: TianSL/2024.12.05
* Change: Update the software version to 3.12.0.6.
* Cause: Update
********************************************************************************
* Version: 3.22
* Author/Date: TianSL/2025.02.28
* Change: Update the software version to 3.13.0.7.
* Cause: Update
********************************************************************************
* Version: 3.23
* Author/Date: TianSL/2025.03.12
* Change: Update the software version to 3.13.0.8.
* Cause: Update
********************************************************************************
* Version: 3.24
* Author/Date: TianSL/2025.03.26
* Change: Update the software version to 3.13.0.9.
* Cause: Update
********************************************************************************
* Version: 3.25
* Author/Date: TianSL/2025.03.27
* Change: Modify the QAC deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.26
* Author/Date: TianSL/2025.04.11
* Change: Update the software version to 3.13.0.10.
* Cause: Update
********************************************************************************
* Version: 3.27
* Author/Date: TianSL/2025.05.12
* Change: Update the software version to 3.14.0.11.
* Cause: Update
********************************************************************************
* Version: 3.28
* Author/Date: TianSL/2025.05.14
* Change: Add the struct member pduVerifyResult in the struct SecOC_IPDU_BufType.
* Cause: Update
********************************************************************************
* Version: 3.29
* Author/Date: TianSL/2025.05.27
* Change: Update the software version to 3.14.0.12.
* Cause: Update
********************************************************************************
* Version: 3.30
* Author/Date: TianSL/2025.06.06
* Change: Add the polyspace deviation suppression comment.
* Cause: Update
********************************************************************************
* Version: 3.31
* Author/Date: TianSL/2025.07.16
* Change: Update the software version to 3.15.0.13.
* Cause: Update
********************************************************************************
*/
#ifndef SECOC_H_
#define SECOC_H_

/*
********************************************************************************
*    Includes
********************************************************************************
*/
#include "SecOC_Cfg.h"
#include "Rte_SecOC_Type.h"

#if( SECOC_DEVERRORDETECT == STD_ON )
#include "Det.h"
#endif

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Vendor and module identification. */
/* polyspace-begin MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */
#define SECOC_VENDOR_ID                          (119U)
#define SECOC_MODULE_ID                          (150U)
#define SECOC_INSTANCE_ID_DET                    (0U)

/* Component version information. */
#define SECOC_SW_MAJOR_VERSION                   (3U)
#define SECOC_SW_MINOR_VERSION                   (15U)
#define SECOC_SW_PATCH_VERSION                   (0U)
#define SECOC_SW_REVISION_VERSION                (13U)
/* AUTOSAR Version. */
#define SECOC_AR_RELEASE_MAJOR_VERSION           (4U)
#define SECOC_AR_RELEASE_MINOR_VERSION           (4U)
#define SECOC_AR_RELEASE_REVISION_VERSION        (0U)

/* polyspace +1 MISRA-C3:17.8 [Justified:Unset] "NSCA_Polyspace_Common_DummyStmt" polyspace +1 MISRA-C3:D4.9 [Justified:Unset] "NSCA_Polyspace_Common_FctLikeMacro" */
#define SECOC_DUMMY_STATEMENT(v) ((v)=(v))

/* Error codes */
#define SECOC_E_NO_ERROR            (0x00U)
#define SECOC_E_PARAM_POINTER       (0x01U)
#define SECOC_E_UNINIT              (0x02U)
#define SECOC_E_INVALID_PDU_SDU_ID  (0x03U)
#define SECOC_E_INIT_FAILED         (0x07U)
#define SECOC_E_CRYPTO_FAILURE      (0x04U)

#define SECOC_E_FRESHNESS_FAILURE   (0x08U)

#define SECOC_INIT_0                (0U)

#define SECOC_INDEX_0               (0U)
#define SECOC_INDEX_1               (1U)
#define SECOC_INDEX_2               (2U)
#define SECOC_INDEX_3               (3U)
#define SECOC_INDEX_4               (4U)
#define SECOC_INDEX_5               (5U)
#define SECOC_INDEX_6               (6U)
#define SECOC_INDEX_7               (7U)

#define SECOC_VALUE_0               (0U)
#define SECOC_VALUE_1               (1U)
#define SECOC_VALUE_2               (2U)
#define SECOC_VALUE_3               (3U)
#define SECOC_VALUE_4               (4U)
#define SECOC_VALUE_5               (5U)
#define SECOC_VALUE_6               (6U)
#define SECOC_VALUE_7               (7U)
#define SECOC_VALUE_8               (8U)
#define SECOC_VALUE_32              (32U)
#define SECOC_VALUE_255             (255U)

#define SECOC_0                     (0U)
#define SECOC_1                     (1U)
#define SECOC_2                     (2U)
#define SECOC_6                     (6U)
#define SECOC_7                     (7U)
#define SECOC_8                     (8U)
#define SECOC_10                    (10U)
#define SECOC_24                    (24U)
#define SECOC_32                    (32U)
#define SECOC_64                    (64U)
#define SECOC_255                   (255U)

#define SECOC_QUEUE                 (0U)
#define SECOC_REJECT                (1U)
#define SECOC_REPLACE               (2U)

#define SECOC_SECUPDU               (0U)
#define SECOC_AUTHPDUCOLLECTION     (1U)
#define SECOC_CRYPTOPDUCOLLECTION   (2U)

#define SECOC_BOTH                  (0U)
#define SECOC_FAILURE_ONLY          (1U)
#define SECOC_NONE                  (2U)

#define SECOC_E_BUSY                (0x02U)

#define SECOC_INVALID_SECURED_PDU_TXPDUSTATE          (0x00U)
#define SECOC_TP_AUTHENTIC_PDU_TXPDUSTATE             (0x06U)
#define SECOC_REAUTHENTICATION_NEEDED_TXPDUSTATE      (0x01U)
#define SECOC_AUTHENTICATED_TXPDUSTATE                (0x02U)
#define SECOC_TRANSMISSION_INITIATED_TXPDUSTATE       (0x03U)
#define SECOC_COPYING_TXPDUSTATE                      (0x04U)
#define SECOC_TRIGGER_TRANSMIT_TXPDUSTATE             (0x05U)
#define SECOC_DEFAULT_CODE_TXPDUSTATE                 (0x06U)

#define SECOC_UNAUTHENTICATED_TXPDUSTATE              (0x10U)
#define SECOC_TO_BE_STARTED_TXPDUSTATE                (0x10U)
#define SECOC_FINISHED_TXPDUSTATE                     (0x16U)
#define SECOC_BYPASS_TXPDUSTATE                       (0x1AU)
#define SECOC_WAIT_CSM_JOB_PROCESS                    (0xAAU)

#define SECOC_IDLE_RXPDUSTATE                         (0x00U)
#define SECOC_COPYING_RXPDUSTATE                      (0x01U)
#define SECOC_VERIFIED_RXPDUSTATE                     (0x02U)
#define SECOC_COPY_AUTHENTIC_RXPDUSTATE               (0x03U)
#define SECOC_FV_NEEDED_RXPDUSTATE                    (0x04U)
#define SECOC_UNVERIFIED_RXPDUSTATE                   (0x10U)
#define SECOC_DEFAULTCODE_RXPDUSTATE                  (0x20U)
#define SECOC_VERIFY_FINISHED_RXPDUSTATE              (0x17U)

#define SECOC_IDLE_TRANSMITREQUEST                    (0x00U)
#define SECOC_TRANSMIT_TRANSMITREQUEST                (0x01U)

#define SECOC_SID_INIT                                (0x01U)
#define SECOC_SID_GET_VERSION_INFO                    (0x02U)
#define SECOC_SID_IFTRANSMIT                          (0x49U)
#define SECOC_SID_TPTRANSMIT                          (0x49U)
#define SECOC_SID_CANCEL_RECEIVE                      (0x4CU)
#define SECOC_SID_CANCEL_IFTRANSMIT                   (0x4AU)
#define SECOC_SID_CANCEL_TPTRANSMIT                   (0x4AU)
#define SECOC_SID_DE_INIT                             (0x05U)
#define SECOC_SID_VERIFY_STATUS_OVERRIDE              (0x0BU)
#define SECOC_SID_RXINDICATION                        (0x42U)
#define SECOC_SID_TPRXINDICATION                      (0x45U)
#define SECOC_SID_TX_CONFIRMATION                     (0x40U)
#define SECOC_SID_TRIGGER_TRANSMIT                    (0x41U)
#define SECOC_SID_COPY_TX_DATA                        (0x43U)
#define SECOC_SID_COPY_RX_DATA                        (0x44U)
#define SECOC_SID_START_OF_RECEPTION                  (0x46U)
#define SECOC_SID_TP_TX_CONFIRMATION                  (0x48U)
#define SECOC_SID_MAIN_FUNCTION_RX                    (0x06U)
#define SECOC_SID_MAIN_FUNCTION_TX                    (0x03U)
#define SECOC_SID_SETMODE                             (0x50U)
/* polyspace-end MISRA-C3:2.5 [Justified:Unset] "NSCA_Polyspace_Common_UnusedDef" */

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
/* [SWS_SecOC_00162] States of the SecOC module. */
typedef enum
{
    SECOC_UNINIT = SECOC_0,   /* SecOC module is not initialized. */
    SECOC_INIT = SECOC_1      /* SecOC module is initialized. */
} SecOC_StateType;

typedef struct
{
    uint32 BufferLen;
    uint8 PduBuffer[SECOC_MAX_TXSECURE_LEN + SECOC_1];
} SecOC_TxPduBuffer_st;

typedef struct
{
    uint32 BufferLen;
    uint8 PduBuffer[SECOC_MAX_RXSECURE_LEN + SECOC_1];
} SecOC_RxPduBuffer_st;

typedef struct
{  
    uint8 pduState;
    uint8 txRequest;
    uint8 verifyCount;
    uint8 Authenticator[SECOC_32];
    Crypto_VerifyResultType verifyPtr; /* The mac verify result ptr. */

    uint16 attempCounter;
    uint16 builtAttempCnt;

    uint8 *authpdubuf;
    uint32 authpdubuflen;
    uint8 *cryptoPduBuf;
    uint32 cryptoPduBuflen;    
    uint8 *authData;
    uint32 authDataLen;    /* The length of DataToAuthenticator. */
    uint32 availableLen;   /* The length of data that can be transmitted by Tp transmission. */
    uint32 tpAuthLength;
    uint32 tpCryptoLength; /* Tp transfer the amount of data that has been transferred. */
    uint32 AuthIPduLen;    /* The length of the Authentic I-PDU */
    uint32 tpSduLength;    /* Total length of the N-SDU to be received. */
    uint32 tpSduCryptoLength;    /* Total length of the Crypto to be received. */
    boolean pduVerifyResult;     /* The verification Result of the PDU. */
} SecOC_IPDU_BufType;

typedef struct
{
    uint8 defaultVal;
    boolean useDefaultVal;
}SecOC_DefaultDataType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define SECOC_START_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"

#if( SECOC_NUM_TXPDUPRO > SECOC_0 )
extern VAR(SecOC_IPDU_BufType, SECOC_VAR_NO_INIT) SecOC_TxPduBuf[SECOC_NUM_TXPDUPRO];
#endif

#if( SECOC_NUM_RXPDUPRO > SECOC_0 )
extern VAR(SecOC_IPDU_BufType, SECOC_VAR_NO_INIT) SecOC_RxPduBuf[SECOC_NUM_RXPDUPRO];
#endif

extern VAR(SecOC_TxPduBuffer_st, SECOC_VAR_NO_INIT) SecOC_TxPduBuffer;
extern VAR(SecOC_RxPduBuffer_st, SECOC_VAR_NO_INIT) SecOC_RxPduBuffer;

#define SECOC_STOP_SEC_VAR_NO_INIT
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"

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

#define SECOC_START_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"

/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
extern FUNC(void, SECOC_CODE) SecOC_Init
(
    P2CONST(SecOC_ConfigType, AUTOMATIC, SECOC_APPL_CONST) config
);
extern FUNC(void, SECOC_CODE) SecOC_DeInit(void);

#if( SECOC_VERSIONINFOAPI == STD_ON )
extern FUNC(void, SECOC_CODE) SecOC_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, SECOC_APPL_DATA) versioninfo
);
#endif

extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_IfTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr
);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_TpTransmit
(
    PduIdType TxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr
);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_CancelReceive(PduIdType RxPduId);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_IfCancelTransmit(PduIdType TxPduId);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_TpCancelTransmit(PduIdType TxPduId);
extern FUNC(void, SECOC_CODE) SecOC_RxIndication
(
    PduIdType RxPduId,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) PduInfoPtr
);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
extern FUNC(void, SECOC_CODE) SecOC_TpRxIndication(PduIdType id, Std_ReturnType result);
extern FUNC(void, SECOC_CODE) SecOC_TxConfirmation(PduIdType TxPduId);
/* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
extern FUNC(void, SECOC_CODE) SecOC_TpTxConfirmation(PduIdType id, Std_ReturnType result);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_TriggerTransmit
(
    PduIdType TxPduId,
    P2VAR(PduInfoType, AUTOMATIC, SECOC_APPL_DATA) PduInfoPtr
);
extern FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_CopyRxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr
);
extern FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_CopyTxData
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    P2CONST(RetryInfoType, AUTOMATIC, SECOC_APPL_CONST) retry,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) availableDataPtr
);
extern FUNC(BufReq_ReturnType, SECOC_CODE) SecOC_StartOfReception
(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, SECOC_APPL_CONST) info,
    PduLengthType TpSduLength,
    P2VAR(PduLengthType, AUTOMATIC, SECOC_APPL_DATA) bufferSizePtr
);
extern FUNC(void ,SECOC_CODE) SecOC_CsmMacGenerateCallback
(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job,
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    VAR(uint8, AUTOMATIC) result
);
extern FUNC(void ,SECOC_CODE) SecOC_CsmMacVerifyCallback
(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job, 
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    VAR(uint8, AUTOMATIC) result
);

extern FUNC(void, SECOC_CODE) SecOC_MainFunction_Rx(uint16 SecOCRxPduInfoTableIndex);
extern FUNC(void, SECOC_CODE) SecOC_MainFunction_Tx(uint16 SecOCTxPduInfoTableIndex);

#if( SECOC_QUERYFRESHNESSVALUE == SECOC_CFUNC )
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetTxFreshness
(
    uint16 SecOCFreshnessValueID,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength
);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetTxFreshnessTruncData
(
    uint16 SecOCFreshnessValueID,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,
    P2CONST(uint32, AUTOMATIC, SECOC_APPL_CONST) SecOCFreshnessValueLength,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue,
    P2CONST(uint32, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValueLength
);
extern FUNC(void, SECOC_CODE) SecOC_SPduTxConfirmation(uint16 SecOCFreshnessValueID);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetRxFreshness
(
    uint16 SecOCFreshnessValueID,
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValue,
    uint32 SecOCTruncatedFreshnessValueLength,
    uint16 SecOCAuthVerifyAttempts,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength
);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_GetRxFreshnessAuthData
(
    uint16 SecOCFreshnessValueID,
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValue,
    uint32 SecOCTruncatedFreshnessValueLength,
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCAuthDataFreshnessValue,
    uint16 SecOCAuthDataFreshnessValueLength,
    uint16 SecOCAuthVerifyAttempts,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength
);

#else
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessManagementGetTxFreshness
(
    uint16 SecOCFreshnessValueID,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength
);
/* polyspace +1 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule5.1" */
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessManagementGetTxFreshnessTruncData
(
    uint16 SecOCFreshnessValueID,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,
    P2CONST(uint32, AUTOMATIC, SECOC_APPL_CONST) SecOCFreshnessValueLength,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCTruncatedFreshnessValue,
    P2CONST(uint32, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValueLength
);  /* PRQA S 777,779 */ /* NSCA_QAC_SecOC_Rule1.3,NSCA_QAC_Common_IdentifierLength */
extern FUNC(void, SECOC_CODE) SecOC_FreshnessManagementSPduTxConfirmation
(
    uint16 SecOCFreshnessValueID
);
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessManagementGetRxFreshness
(
    uint16 SecOCFreshnessValueID,
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValue,
    uint32 SecOCTruncatedFreshnessValueLength,
    uint16 SecOCAuthVerifyAttempts,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength
);
/* polyspace +1 MISRA-C3:5.1 [Justified:Unset] "NSCA_Polyspace_SecOC_Rule5.1" */
extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_FreshnessManagementGetRxFreshnessAuthData
(
    uint16 SecOCFreshnessValueID,
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCTruncatedFreshnessValue,
    uint32 SecOCTruncatedFreshnessValueLength,
    P2CONST(uint8, AUTOMATIC, SECOC_APPL_CONST) SecOCAuthDataFreshnessValue,
    uint16 SecOCAuthDataFreshnessValueLength,
    uint16 SecOCAuthVerifyAttempts,
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValue,
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) SecOCFreshnessValueLength
);  /* PRQA S 777,779 */ /* NSCA_QAC_SecOC_Rule1.3,NSCA_QAC_Common_IdentifierLength */
#endif

extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_VerifyStatusOverride
(
    uint16 ValueID,
    SecOC_OverrideStatusType overrideStatus,
    uint8 numberOfMessagesToOverride
);

extern FUNC(void, SECOC_CODE) SecOC_VerificationStatusCallout
(
    SecOC_VerificationStatusType verificationStatus
);

extern FUNC(void, SECOC_CODE) SecOC_VerificationStatusService
(
    SecOC_VerificationStatusType verificationStatus
);

extern FUNC(void, SECOC_CODE) SecOC_VerificationStatusIndication
(
    SecOC_VerificationStatusType verificationStatus
);

extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_VerifyByDefaultCode
(
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) AuthInfo,
    uint32 AuthInfoleng,
    uint32 SecOCTruncatedFreshnessValueLength,
    uint32 SecOCAuthInfoTruncLength
);

extern FUNC(Std_ReturnType, SECOC_CODE) SecOC_AuthenticationByDefaultCode
(
    P2VAR(uint8, AUTOMATIC, SECOC_APPL_DATA) AuthInfo,
    P2VAR(uint32, AUTOMATIC, SECOC_APPL_DATA) AuthInfoleng,
    uint32 SecOCTruncatedFreshnessValueLength,
    uint32 SecOCAuthInfoTruncLength
);

#if( SECOC_SETMODE == STD_ON )
FUNC(void, SECOC_CODE) SecOC_SetMode
(
    /* polyspace +1 MISRA-C3:D4.5 [Justified:Unset] "NSCA_Polyspace_SecOC_RuleD4.5" */
    SecOC_ModeType mode,
    uint8 defaultVal,
    boolean useDefaultVal
);
#endif

#define SECOC_STOP_SEC_CODE
/* polyspace +1 MISRA-C3:20.1 [Justified:Unset] "NSCA_Polyspace_Common_MemMap" */
#include "SecOC_MemMap.h"

#endif  /* SECOC_H_ */
