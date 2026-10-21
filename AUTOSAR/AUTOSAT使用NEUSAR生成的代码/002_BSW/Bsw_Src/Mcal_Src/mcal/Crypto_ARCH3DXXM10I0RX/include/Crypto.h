/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Crypto
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Crypto.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Crypto MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/

/*
 * QAC violations
 *
 * @ID:rcma-4.0.0-1534 Rule:M3CM Rule-2.5
 * The macro '%1s' is declared but not used within this project.
 *
 * @ID:rcma-4.0.0-1535 Rule:M3CM Rule-2.3
 * The typedef '%1s' is declared but not used within this project.
 */

/* PRQA S 1534,1535, 0722 EOF */

#ifndef CRYPTO_H
#define CRYPTO_H

#include "Csm.h"
#include "Crypto_LLDriver.h"
#include "Crypto_Irq.h"
#include "Crypto_cfg.h"
#include "Crypto_AutoSar_Externsion.h"
#include "CryIf_Cbk.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CRYPTO_VENDOR_ID                176
#define CRYPTO_MODULE_ID                114
#define CRYPTO_AR_RELEASE_MAJOR_VERSION 4
#define CRYPTO_AR_RELEASE_MINOR_VERSION 4
#define CRYPTO_AR_REL_REV_VER           0
#define CRYPTO_SW_MAJOR_VER             3
#define CRYPTO_SW_MINOR_VER             0
#define CRYPTO_SW_PATCH_VER             0


#define   CRYPTO_ALGOFAM_SM4					0x30U    /* zxy add */
/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/*
 * Selfdefine retvalue to Std_ReturnType
 */
/* service is not supported  */
#define CRYPTO_RE_NOT_SUPPORTED                   ((Std_ReturnType)0x81U)

/*
 * Development Error Types
 */
/* API request called before initialization of Crypto Driver */
#define CRYPTO_E_UNINIT                           ((uint8)0x00U)

/* Initiation of Crypto Driver failed */
#define CRYPTO_E_INIT_FAILED                      ((uint8)0x01U)

/* API request called with invalid parameter (Nullpointer) */
#define CRYPTO_E_PARAM_POINTER                    ((uint8)0x02U)

/* API request called with invalid parameter (out of range) */
#define CRYPTO_E_PARAM_HANDLE                     ((uint8)0x04U)

/* API request called with invalid parameter (invalid value) */
#define CRYPTO_E_PARAM_VALUE                      ((uint8)0x05U)

/* The service request failed because it is not supported by the driver (Extension of Development Errors) */
#define CRYPTO_E_NOT_SUPPORTED                    ((uint8)0x81)

/* The service request failed because at least one parameter is invalid (Extension of Development Errors) */
#define CRYPTO_E_INVALID_PARAM                    ((uint8)0x82)

/*
 * Runtime Error Types
 */
/* Buffer is too small for operation */
#define CRYPTO_E_RE_SMALL_BUFFER                  ((uint8)0x00)

/* Requested key is not available */
#define CRYPTO_E_RE_KEY_NOT_AVAILABLE             ((uint8)0x01)

/* Key cannot be read */
#define CRYPTO_E_RE_KEY_READ_FAIL                 ((uint8)0x02)

/* Entropy is too low */
#define CRYPTO_E_RE_ENTROPY_EXHAUSTED             ((uint8)0x03)

/* Crypto extension to Std_ReturnType */
#define CRYPTO_RET_OPERATION_TIMEOUT              ((Std_ReturnType)0x80U)

#define CRYPTO_RET_NOT_SUPPORTED                  ((Std_ReturnType)0x81U)

#define CRYPTO_RET_INVALID_PARAM                  ((Std_ReturnType)0x82U)

#define CRYPTO_INIT_ID                            ((uint8)0x00U)
#define CRYPTO_GETVERSIONINFO_ID                  ((uint8)0x01U)
#define CRYPTO_PROCESSJOB_ID                      ((uint8)0x03U)
#define CRYPTO_CANCELJOB_ID                       ((uint8)0x0EU)
#define CRYPTO_KEYELEMENTSET_ID                   ((uint8)0x04U)
#define CRYPTO_KEYVALIDSET_ID                     ((uint8)0x05U)
#define CRYPTO_KEYELEMENTGET_ID                   ((uint8)0x06U)
#define CRYPTO_KEYELEMENTCOPY_ID                  ((uint8)0x0FU)
#define CRYPTO_KEYCOPY_ID                         ((uint8)0x10U)
#define CRYPTO_KEYELEMENTIDSGET_ID                ((uint8)0x11U)
#define CRYPTO_RANDOMSEED_ID                      ((uint8)0x0DU)
#define CRYPTO_KEYGENERATE_ID                     ((uint8)0x07U)
#define CRYPTO_KEYDERIVE_ID                       ((uint8)0x08U)
#define CRYPTO_KEYEXCHANGECALCPUBVAL_ID           ((uint8)0x09U)
#define CRYPTO_KEYEXCHANGECALCSECRET_ID           ((uint8)0x0AU)
#define CRYPTO_CERTIFICATEPARSE_ID                ((uint8)0x0BU)
#define CRYPTO_CERTIFICATEVERIFY_ID               ((uint8)0x12U)

/* Key Element ID of the key material */
#define CRYPTO_HSM_KEY_MATERIAL                   ((uint32)0x01U)

#ifndef CRYPTO_PROCESSING_ASYNC_POLLING_MODE
    #define CRYPTO_PROCESSING_ASYNC_POLLING_MODE                 (0x02)
#endif

#define CRYPTO_CORE_NUM                    MCAL_CORE_NUM
typedef enum
{
    CRYPTO_OK           = 0x00U,
    CRYPTO_NULL_PTR     = 0x01U,
    CRYPTO_INVALID_LEN  = 0x02U,
    CRYPTO_NOT_OK       = 0x03U
} Crypto_ReturnType;

typedef struct
{
    boolean bSingleCallOnly;
    boolean bCheckTargetKeyId;
    uint8   u8InputModeMask;
    uint8   u8SecondaryInputModeMask;
    uint8   u8TertiaryInputModeMask;
    uint8   u8OutputModeMask;
    uint8   u8SecondaryOutputModeMask;
    uint8   u8VerifyPtrModeMask;
} Crypto_ProcessJobServiceParametersType;

typedef enum {
    CRYPTO_UNINIT = 0U,
    CRYPTO_READY  =1U,
} Crypto_DriverStateType;

typedef struct
{
	VAR(uint32, CRYPTO_VAR) u32Timeout;
} Crypto_ConfigType;

typedef enum
{
    CRYPTO_KE_FORMAT_BIN_OCTET                       = 0x01U,
    CRYPTO_KE_FORMAT_BIN_SHEKEYS                     = 0x02U,
    CRYPTO_KE_FORMAT_BIN_IDENT_PRIVATEKEY_PKCS8      = 0x03U,
    CRYPTO_KE_FORMAT_BIN_IDENT_PUBLICKEY             = 0x04U,
    CRYPTO_KE_FORMAT_BIN_RSA_PRIVATEKEY              = 0x05U,
    CRYPTO_KE_FORMAT_BIN_RSA_PUBLICKEY               = 0x06U,
    CRYPTO_KE_FORMAT_BIN_CERT_X509_V3                = 0x07U,
    CRYPTO_KE_FORMAT_BIN_CERT_CVC                    = 0x08U
} Crypto_KeyFormatType;

typedef enum
{
    CRYPTO_RA_DENIED         = 0x01U,
    CRYPTO_RA_INTERNAL_COPY  = 0x02U,
    CRYPTO_RA_ALLOWED        = 0x03U,
    CRYPTO_RA_ENCRYPTED      = 0x04U
} Crypto_KeyElementReadAccessType;

typedef enum
{
    CRYPTO_WA_DENIED        = 0x01U,
    CRYPTO_WA_INTERNAL_COPY = 0x02U,
    CRYPTO_WA_ALLOWED       = 0x03U,
    CRYPTO_WA_ENCRYPTED     = 0x04U
} Crypto_KeyElementWriteAccessType;

typedef struct
{
    CONST(uint32, CRYPTO_CONST) u32Crypto_KeyElementId;
    CONST(uint32, CRYPTO_CONST) u32Crypto_KeyElementUniqueId;
    CONST(boolean, CRYPTO_CONST) bCrypto_KeyElementAllowPartialAccess;
    CONST(Crypto_KeyFormatType, CRYPTO_CONST) eCrypto_KeyFormatType;
    CONST(boolean, CRYPTO_CONST) bCrypto_KeyElementPersist;
    CONST(Crypto_KeyElementReadAccessType, CRYPTO_CONST) eCrypto_KeyElementReadAccess;
    CONST(uint32, CRYPTO_CONST) u32Crypto_KeyElementMaxSize;
    VAR(uint32, CRYPTO_VAR) u32Crypto_KeyElementActualSize;
    CONST(Crypto_KeyElementWriteAccessType, CRYPTO_CONST) eCrypto_KeyElementWriteAccess;
    P2VAR(uint8, AUTOMATIC, CRYPTO_APPL_DATA) pCrypto_ElementArray;
    /* Add For HSM */
    CONST(uint32, CRYPTO_VAR) u32HsmKeyCounter;
    CONST(uint8, CRYPTO_VAR) u8HsmEccCurveId;
    CONST(uint16, CRYPTO_VAR) u16HsmKeyType;
    CONST(uint16, CRYPTO_VAR) u16HsmKeyFlags;
    CONST(uint32, CRYPTO_VAR) u32HsmKeyBits;
    CONST(uint32, CRYPTO_VAR) u32HsmKeyHandle;
} Crypto_KeyElementType;

typedef struct
{
    CONST(uint32, CRYPTO_CONST) u32CryptoKeyElementsCount;
    CONSTP2CONST(uint32, CRYPTO_VAR, CRYPTO_APPL_CONST) pCryptoKeyElementsNumberConfig;
} Crypto_KeyElementsType;

typedef struct
{
	VAR(uint32, AUTOMATIC) u32Crypto_KeyId;
    VAR(boolean, AUTOMATIC) bCrypto_KeyValid;
    CONSTP2CONST(Crypto_KeyElementsType, CRYPTO_VAR, CRYPTO_APPL_CONST) pCrypto_KeyElementConfig;
} Crypto_KeyType;

typedef struct
{
    CONST (Crypto_ServiceInfoType, CRYPTO_CONST) eCrypto_Service;
    CONST (Crypto_AlgorithmFamilyType, CRYPTO_CONST) eCrypto_Family;
    CONST (Crypto_AlgorithmModeType, CRYPTO_CONST) eCrypto_Mode;
    CONST (Crypto_AlgorithmFamilyType, CRYPTO_CONST) eCrypto_SecondaryFamily;
} Crypto_PrimitiveType;

typedef struct
{
    VAR(boolean, AUTOMATIC) bCrypto_JobValid;
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_CONST) pJob;
} Crypto_QueueType;

typedef struct
{
    CONST(uint32, CRYPTO_CONST) u32Crypto_DriverObjectId;
    P2VAR(Crypto_QueueType, AUTOMATIC, CRYPTO_APPL_DATA) pCrypto_QueuedJobs;
    CONST(uint32, CRYPTO_CONST) u32Crypto_QueueSize;
    P2CONST(Crypto_PrimitiveType,AUTOMATIC, CRYPTO_CONST) pCrypto_Primitives;
    CONST(uint32, CRYPTO_CONST) u32Crypto_PrimitivesNumber;
} Crypto_ObjectType;

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_Init
(
     P2CONST(Crypto_ConfigType, CRYPTO_CONST, CRYPTO_APPL_CONST) configPtr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_GetVersionInfo
(
    P2VAR( Std_VersionInfoType, AUTOMATIC, CRYPTO_APPL_DATA ) versioninfo
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_ProcessJob
(
    VAR  (uint32,         AUTOMATIC                  ) objectId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_APPL_DATA) job
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CancelJob
(
    VAR  (uint32,             AUTOMATIC                  ) objectId,
    P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYPTO_APPL_DATA) job
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementSet
(
    VAR    (uint32, AUTOMATIC                   ) cryptoKeyId,
    VAR    (uint32, AUTOMATIC                   ) keyElementId,
    P2CONST(uint8,  AUTOMATIC, CRYPTO_APPL_CONST) keyPtr,
    VAR    (uint32, AUTOMATIC                   ) keyLength
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyValidSet	/* PRQA S 1753 */
(
    VAR(uint32, AUTOMATIC) cryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeySetValid
(
    VAR(uint32, AUTOMATIC) cryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementGet
(
    VAR  (uint32, AUTOMATIC                  ) cryptoKeyId,
    VAR  (uint32, AUTOMATIC                  ) keyElementId,
    P2VAR(uint8,  AUTOMATIC, CRYPTO_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) resultLengthPtr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyElementCopy
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) keyElementId,
    VAR(uint32, AUTOMATIC) targetCryptoKeyId,
    VAR(uint32, AUTOMATIC) targetKeyElementId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE)Crypto_KeyElementCopyPartial
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) keyElementId,
    VAR(uint32, AUTOMATIC) keyElementSourceOffset,
    VAR(uint32, AUTOMATIC) keyElementTargetOffset,
    VAR(uint32, AUTOMATIC) keyElementCopyLength,
    VAR(uint32, AUTOMATIC) targetCryptoKeyId,
    VAR(uint32, AUTOMATIC) targetKeyElementId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyCopy
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) targetCryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyElementIdsGet
(
    VAR  (uint32, AUTOMATIC                  ) cryptoKeyId,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) keyElementIdsPtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) keyElementIdsLengthPtr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_RandomSeed
(
    VAR    (uint32, AUTOMATIC                   ) cryptoKeyId,
    P2CONST(uint8,  AUTOMATIC, CRYPTO_APPL_CONST) seedPtr,
    VAR    (uint32, AUTOMATIC                   ) seedLength
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyGenerate
(
    VAR(uint32, AUTOMATIC) cryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyDerive
(
    VAR(uint32, AUTOMATIC) cryptoKeyId,
    VAR(uint32, AUTOMATIC) targetCryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyExchangeCalcPubVal
(
    VAR  (uint32, AUTOMATIC                  ) cryptoKeyId,
    P2VAR(uint8,  AUTOMATIC, CRYPTO_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CRYPTO_APPL_DATA) publicValueLengthPtr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_KeyExchangeCalcSecret
(
    VAR    (uint32, AUTOMATIC                   ) cryptoKeyId,
    P2CONST(uint8,  AUTOMATIC, CRYPTO_APPL_CONST) partnerPublicValuePtr,
    VAR    (uint32, AUTOMATIC                   ) partnerPublicValueLength
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CertificateParse
(
    VAR(uint32, AUTOMATIC) cryptoKeyId
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(Std_ReturnType, CRYPTO_CODE) Crypto_CertificateVerify
(
    VAR  (uint32,                  AUTOMATIC                  ) cryptoKeyId,
    VAR  (uint32,                  AUTOMATIC                  ) verifyCryptoKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYPTO_APPL_DATA) verifyPtr
);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

#define CRYPTO_START_SEC_CODE
#include "Crypto_MemMap.h"
FUNC(void, CRYPTO_CODE) Crypto_MainFunction(void);
#define CRYPTO_STOP_SEC_CODE
#include "Crypto_MemMap.h"

extern CONST(Crypto_ConfigType,CRYPTO_CONST) Crypto_Config;

#endif /* CRYPTO_H */

/** @} */
