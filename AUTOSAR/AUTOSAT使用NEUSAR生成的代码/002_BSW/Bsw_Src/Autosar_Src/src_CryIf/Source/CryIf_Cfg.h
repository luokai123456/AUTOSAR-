/*
********************************************************************************
*
*  File name: CryIf_Cfg.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 3.0
*  Author/Date : JiaF/2020.07.02
*  Change: New created.
*  Cause: New
********************************************************************************
*  Version: 3.1
*  Author/Date : LQiao/2023.02.14
*  Change: Mudify array length.
*  Cause: Optimization
********************************************************************************
*/
#ifndef CRYIF_CFG_H_
#define CRYIF_CFG_H_

/*
********************************************************************************
* Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Rte_Csm_Type.h"
#include "Crypto.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define CRYIF_DEV_ERROR_DETECT             (STD_ON)
#define CRYIF_VERSION_INFO_API             (STD_ON)

#define CRYIF_NUMBER_OF_CHANNEL            (1U)
#define CRYIF_NUMBER_OF_KEY                (1U)
#define CRYIF_NUMBER_OF_DRIVER             (1U)
#define CRYIF_NUMBER_OF_ELEMENT            (1U)
#define CRYIF_MAX_SIZE_OF_KEY_ELEMENT      (1U)
#define CRYIF_KEY_ELEMENT_COPY_PARTIAL     (STD_OFF)

#define CRYIF_DUMMY_STATEMENT(v)           ((v)=(v))
#define CRYIF_DUMMY_STATEMENT_CONST(v)     ((void)(v))

#define CRYIF_VALUE_ONE                    (1U)
#define CRYIF_INVALID_ID                   (0xFFFFFFFFU)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_ProcessJob)(VAR(uint32, AUTOMATIC) channelId, P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_DATA) job);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_CancelJob)(VAR(uint32, AUTOMATIC) channelId, P2VAR(Crypto_JobInfoType, AUTOMATIC, CRYIF_APPL_DATA) job);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyElementSet)(VAR(uint32, AUTOMATIC) cryIfKeyId, VAR(uint32, AUTOMATIC) keyElementId, P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) keyPtr, VAR(uint32, AUTOMATIC) keyLength);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeySetValid)(VAR(uint32, AUTOMATIC) channelId);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyElementGet)(VAR(uint32, AUTOMATIC) cryIfKeyId, VAR(uint32, AUTOMATIC) keyElementId, P2VAR(uint8, AUTOMATIC, CRYIF_APPL_DATA) resultPtr, P2VAR(uint32, AUTOMATIC, CRYIF_APPL_DATA) resultLengthPtr);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyElementCopy)(VAR(uint32, AUTOMATIC) cryIfKeyId, VAR(uint32, AUTOMATIC) keyElementId, VAR(uint32, AUTOMATIC) targetCryIfKeyId, VAR(uint32, AUTOMATIC) targetKeyElementId);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyElementCopyPartial)(VAR(uint32, AUTOMATIC) cryIfKeyId, VAR(uint32, AUTOMATIC) keyElementId, VAR(uint32, AUTOMATIC) keyElementSourceOffset, VAR(uint32, AUTOMATIC) keyElementTargetOffset, VAR(uint32, AUTOMATIC) keyElementCopyLength, VAR(uint32, AUTOMATIC) targetCryIfKeyId, VAR(uint32, AUTOMATIC) targetKeyElementId);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyCopy)(VAR(uint32, AUTOMATIC) cryIfKeyId, VAR(uint32, AUTOMATIC) targetCryIfKeyId);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_RandomSeed)(VAR(uint32, AUTOMATIC) cryIfKeyId,  P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) seedPtr, VAR(uint32, AUTOMATIC) seedLength);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyGenerate)(VAR(uint32, AUTOMATIC) cryIfKeyId);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyDerive)(VAR(uint32, AUTOMATIC) cryIfKeyId, VAR(uint32, AUTOMATIC) targetCryIfKeyId);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyExchangeCalcPubVal)(VAR(uint32, AUTOMATIC) cryIfKeyId, P2VAR(uint8, AUTOMATIC, CRYIF_APPL_CONST) publicValuePtr, P2VAR(uint32, AUTOMATIC, CRYIF_APPL_DATA) publicValueLengthPtr);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyExchangeCalcSecret)(VAR(uint32, AUTOMATIC) cryIfKeyId, P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) partnerPublicValuePtr, VAR(uint32, AUTOMATIC) partnerPublicValueLength);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_CertificateParse)(VAR(uint32, AUTOMATIC) cryIfKeyId);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_CertificateVerify)(VAR(uint32, AUTOMATIC) cryIfKeyId, VAR(uint32, AUTOMATIC) verifyCryIfKeyId, P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYIF_APPL_DATA) verifyPtr);

typedef P2FUNC(Std_ReturnType, CRYIF_CODE, CryptoFunctionType_KeyElementIdsGet)(VAR(uint32, AUTOMATIC) cryptoKeyId, P2VAR(uint32, AUTOMATIC, CRYIF_APPL_DATA) keyElementIdsPtr, P2VAR(uint32, AUTOMATIC, CRYIF_APPL_DATA) keyElementIdsLengthPtr);

typedef enum
{
    CRYIF_UNINITIALIZED = 0x00U,
    CRYIF_INITIALIZED
} CryIf_InitStatusType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} CryIf_ConfigType;

typedef struct
{
    const uint32 CryIfChannelId;
    const uint32 CryptoDriverObjectRef;
    const uint32 CryptoChannelIdx;
} CryIf_ChannelConfigType;

typedef struct
{
    const uint32 CryIfKeyId;
    const uint32 CryptoKeyRef;
    const uint32 CryptoKeyIdx;
} CryIf_KeyConfigType;

typedef struct
{
    CryptoFunctionType_ProcessJob ProcessJobFunctionTable;
    CryptoFunctionType_CancelJob CancelJobFunctionTable;
    CryptoFunctionType_KeyElementSet KeyElementSetFunctionTable;
    CryptoFunctionType_KeySetValid KeySetValidFunctionTable;
    CryptoFunctionType_KeyElementGet KeyElementGetFunctionTable;
    CryptoFunctionType_KeyElementCopy KeyElementCopyFunctionTable;
    CryptoFunctionType_KeyElementCopyPartial KeyElementCopyPartialFunctionTable;
    CryptoFunctionType_KeyCopy KeyCopyFunctionTable;
    CryptoFunctionType_RandomSeed RandomSeedFunctionTable;
    CryptoFunctionType_KeyGenerate KeyGenerateFunctionTable;
    CryptoFunctionType_KeyDerive KeyDeriveFunctionTable;
    CryptoFunctionType_KeyExchangeCalcPubVal KeyExchangeCalcPubValFunctionTable;
    CryptoFunctionType_KeyExchangeCalcSecret KeyExchangeCalcSecretFunctionTable;
    CryptoFunctionType_CertificateParse CertificateParseFunctionTable;
    CryptoFunctionType_CertificateVerify CertificateVerifyFunctionTable;
    CryptoFunctionType_KeyElementIdsGet KeyElementIdsGetFunctionTable;
} CryIf_ObjectDriverFunctionTableType;

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
#define CRYIF_START_SEC_CONFIG_DATA
//wjc:CryIf_MemMap.h

extern CONST(CryIf_ChannelConfigType, CRYIF_CONFIG_DATA) CryIf_ChannelConfig[CRYIF_NUMBER_OF_CHANNEL + CRYIF_VALUE_ONE];
extern CONST(CryIf_KeyConfigType, CRYIF_CONFIG_DATA) CryIf_KeyConfig[CRYIF_NUMBER_OF_KEY + CRYIF_VALUE_ONE];
extern CONST(CryIf_ObjectDriverFunctionTableType, CRYIF_CONFIG_DATA) CryIf_ObejectDriverFunctionTable[CRYIF_NUMBER_OF_DRIVER + CRYIF_VALUE_ONE];

#define CRYIF_STOP_SEC_CONFIG_DATA
//wjc:CryIf_MemMap.h
/*
********************************************************************************
*    Global Functions
********************************************************************************
*/

#endif /* CRYIF_CFG_H_ */

