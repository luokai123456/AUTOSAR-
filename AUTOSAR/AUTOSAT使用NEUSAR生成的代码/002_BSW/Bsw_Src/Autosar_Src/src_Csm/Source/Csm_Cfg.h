/*
********************************************************************************
*
*  File name: Csm_Cfg.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date : jia_feng/2020.03.02
*  Change: New
*  Cause: New
********************************************************************************
*  Version: 3.0
*  Author/Date : jia_feng/2020.07.02
*  Change: Nothing
*  Cause: Update
********************************************************************************
*  Version: 3.01
*  Author/Date: MengY/2024.04.02
*  Change: Remove the unused variables.
*  Cause: Optimization
********************************************************************************
*/
#ifndef CSM_CFG_H_
#define CSM_CFG_H_

/*
********************************************************************************
* Includes
********************************************************************************
*/
#include "Csm_Types.h"
#include "Rte_Csm_Type.h"
#include "CryIf.h"
/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define CSM_NUMBER_OF_JOBS                         (1U)
#define CSM_NUMBER_OF_KEYS                         (1U)
#define CSM_NUMBER_OF_CALLBACKS                    (1U)
#define CSM_NUMBER_OF_QUEUES                       (1U)
#define CSM_NUMBER_OF_PRIMITIVES                   (1U)
#define CSM_NUMBER_OF_INOUTREDIRECTIONS            (1U)
#define CSM_NUMBER_OF_INOUTREDIRECTIONS_CONFIG     (1U)
/* General Config */
#define CSM_DEV_ERROR_DETECT                       (STD_OFF)
#define CSM_VERSION_INFO_API                       (STD_ON)
#define CSM_USE_DEPRECATED                         (STD_OFF)
#define CSM_MAIN_FUNCTION_PERIOD                   (10U)
#define CSM_ASYM_PUBLIC_KEY_MAX_LENGTH             (64U)
#define CSM_ASYM_PRIVATE_KEY_MAX_LENGTH            (64U)
#define CSM_KEY_ELEMENT_COPY_PARTIAL               (STD_OFF)
#define CSM_MAX_SIZE_OF_ELEMENT             (CSM_ASYM_PUBLIC_KEY_MAX_LENGTH > CSM_ASYM_PUBLIC_KEY_MAX_LENGTH) ? CSM_ASYM_PUBLIC_KEY_MAX_LENGTH : CSM_ASYM_PUBLIC_KEY_MAX_LENGTH

#define CSM_DUMMY_STATEMENT(v)              ((v)=(v))
#define CSM_DUMMY_STATEMENT_CONST(v)        ((void)(v))

#define CSM_U32_NO_CFG                      ((uint32)0xFFFFFFFFU)
/* Value used to mark the end of a job queue */
#define CSM_JOB_QUEUE_NONE_U32              ((uint32)0xFFFFFFFFU)

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef P2FUNC(void ,CSM_CODE, Csm_CallbackFuncType) (P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job, VAR(Csm_ResultType, AUTOMATIC) result);

typedef enum
{
    CRYPTO_USE_FNC = 0x00U,
    CRYPTO_USE_PORT,
    CRYPTO_USE_PORT_OPTIMIZED
} Csm_JobInterfaceUsePortType;

typedef struct sCsm_JobConfigType
{
    const Crypto_JobInfoType* JobInfo;
    const Csm_JobInterfaceUsePortType JobInterfaceUsePort;
    const uint32 JobPrimitiveRef;
    const Csm_CallbackFuncType JobPrimitiveCallbackRef;
    const boolean JobPrimitiveCallbackUpdateNotification;
    const uint32 JobQueueRef;
    const uint32 JobKeyRef;
    const Crypto_ProcessingType ProcessingMode;
    const uint32 JobInOutRedrectionIdx;
} Csm_JobConfigType;

typedef struct
{
    const uint32 KeyId;
    const boolean KeyUsePort;
    const uint32 Keyref;    /* This parameter refers to the used CryIfKey.
                               The underlying CryIfKey refers to a specific
                               CryptoKey in the Crypto Driver. */
} Csm_KeyConfigType;

typedef struct
{
    const uint32 QueueSize;
    const uint32 ChannelRef;
} Csm_QueueConfigType;

typedef struct sCsm_CallbackConfigType
{
    const uint32 CallbackId;
    const Csm_CallbackFuncType CallbackFunc;
} Csm_CallbackConfigType;

typedef struct
{
    const uint32 InputKeyElementId;
    const uint32 OutputKeyElementId;
    const uint32 SecondaryInputKeyElementId;
    const uint32 SecondaryOutputKeyElementId;
    const uint32 TertiaryInputKeyElementId;
    const uint32 InputKeyRef;
    const uint32 OutputKeyRef;
    const uint32 SecondaryInputKeyRef;
    const uint32 SecondaryOutputKeyRef;
    const uint32 TertiaryInputKeyRef;
} Csm_InOutRedirectionConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType HashAlgorithmFamily;
    const uint8* HashAlgorithmFamilyCustomName;
    const Crypto_AlgorithmModeType HashAlgorithmMode;
    const uint8* HashAlgorithmModeCustom_Name;
    const Crypto_AlgorithmFamilyType HashAlgorithmSecondaryFamily;
    const uint8* HashAlgorithmSecondaryFamilyCustomName;
    const uint32 HashDataMaxLength;
    const uint32 HashResultLength;
} Csm_HashConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType MacGenerateAlgorithmFamily;
    const uint8* MacGenerateAlgorithmFamilyCustomName;
    const uint32 MacGenerateAlgorithmKeyLength;
    const Crypto_AlgorithmModeType MacGenerateAlgorithmMode;
    const uint8* MacGenerateAlgorithmModeCustom_Name;
    const Crypto_AlgorithmFamilyType MacGenerateAlgorithmSecondaryFamily;
    const uint8* MacGenerateAlgorithmSecondaryFamilyCustomName;
    const uint32 MacGenerateDataMaxLength;
    const uint32 MacGenerateResultLength;
} Csm_MacGenerateConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType MacVerifyAlgorithmFamily;
    const uint8* MacVerifyAlgorithmFamilyCustomName;
    const uint32 MacVerifyeAlgorithmKeyLength;
    const Crypto_AlgorithmModeType MacVerifyAlgorithmMode;
    const uint8* MacVerifyAlgorithmModeCustom_Name;
    const Crypto_AlgorithmFamilyType MacVerifyAlgorithmSecondaryFamily;
    const uint8* MacVerifyAlgorithmSecondaryFamilyCustomName;
    const uint32 MacVerifyCompareLength;
    const uint32 MacVerifyDataMaxLength;
} Csm_MacVerifyConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType EncryptAlgorithmFamily;
    const uint8* EncryptAlgorithmFamilyCustomName;
    const uint32 EncryptAlgorithmKeyLength;
    const Crypto_AlgorithmModeType EncryptAlgorithmMode;
    const uint8* EncryptAlgorithmModeCustom_Name;
    const Crypto_AlgorithmFamilyType EncryptAlgorithmSecondaryFamily;
    const uint8* EncryptAlgorithmSecondaryFamilyCustomName;
    const uint32 EncryptDataMaxLength;
    const uint32 EncryptResultLength;
} Csm_EncryptConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType DecryptAlgorithmFamily;
    const uint8* DecryptAlgorithmFamilyCustomName;
    const uint32 DecryptAlgorithmKeyLength;
    const Crypto_AlgorithmModeType DecryptAlgorithmMode;
    const uint8* DecryptAlgorithmModeCustom_Name;
    const Crypto_AlgorithmFamilyType DecryptAlgorithmSecondaryFamily;
    const uint8* DecryptAlgorithmSecondaryFamilyCustomName;
    const uint32 DecryptDataMaxLength;
    const uint32 DecryptResultLength;

} Csm_DecryptConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType AEADEncryptAlgorithmFamily;
    const uint8* AEADEncryptAlgorithmFamilyCustomName;
    const uint32 AEADEncryptAlgorithmKeyLength;
    const Crypto_AlgorithmModeType AEADEncryptAlgorithmMode;
    const uint8* AEADEncryptAlgorithmModeCustom_Name;
    const uint32 AEADEncryptAssociatedDataMaxLength;
    const uint32 AEADEncryptCiphertextMaxLength;
    const uint32 AEADEncryptPlaintextMaxLength;
    const uint32 AEADEncryptTagLength;
    const uint32 AEADEncryptKeyRef;
    const uint32 AEADEncryptQueueRef;
} Csm_AEADEncryptConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType AEADDecryptAlgorithmFamily;
    const uint8* AEADDecryptAlgorithmFamilyCustomName;
    const uint32 AEADDecryptAlgorithmKeyLength;
    const Crypto_AlgorithmModeType AEADDecryptAlgorithmMode;
    const uint8* AEADDecryptAlgorithmModeCustom_Name;
    const uint32 AEADDecryptAssociatedDataMaxLength;
    const uint32 AEADDecryptCiphertextMaxLength;
    const uint32 AEADDecryptPlaintextMaxLength;
    const uint32 AEADDecryptTagLength;
    const uint32 AEADDecryptKeyRef;
    const uint32 AEADDecryptQueueRef;
} Csm_AEADDecryptConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType SignatureGenerateAlgorithmFamily;
    const uint8* SignatureGenerateAlgorithmFamilyCustomName;
    const Crypto_AlgorithmModeType SignatureGenerateAlgorithmMode;
    const uint8* SignatureGenerateAlgorithmModeCustom_Name;
    const Crypto_AlgorithmFamilyType SignatureGenerateAlgorithmSecondaryFamily;
    const uint8* SignatureGenerateAlgorithmSecondaryFamilyCustomName;
    const uint32 SignatureGenerateDataMaxLength;
    const uint32 SignatureGenerateKeyLength;
    const uint32 SignatureGenerateResultLength;
} Csm_SignatureGenerateConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType SignatureVerifyAlgorithmFamily;
    const uint8* SignatureVerifyAlgorithmFamilyCustomName;
    const Crypto_AlgorithmModeType SignatureVerifyAlgorithmMode;
    const uint8* SignatureVerifyAlgorithmModeCustom_Name;
    const Crypto_AlgorithmFamilyType SignatureVerifyAlgorithmSecondaryFamily;
    const uint8* SignatureVerifyAlgorithmSecondaryFamilyCustomName;
    const uint32 SignatureVerifyCompareLength;
    const uint32 SignatureVerifyDataMaxLength;
    const uint32 SignatureVerifyKeyLength;
} Csm_SignatureVerifyConfigType;

typedef struct
{
    const Crypto_AlgorithmFamilyType RandomGenerateAlgorithmFamily;
    const uint8* RandomGenerateAlgorithmFamilyCustomName;
    const Crypto_AlgorithmModeType RandomGenerateAlgorithmMode;
    const uint8* RandomGenerateAlgorithmModeCustom_Name;
    const Crypto_AlgorithmFamilyType RandomGenerateAlgorithmSecondaryFamily;
    const uint8* RandomGenerateAlgorithmSecondaryFamilyCustomName;
    const uint32 RandomGenerateResultLength;
} Csm_RandomGenerateConfigType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_JobKeySetValidConfigType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_JobRandomSeedConfigType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_JobKeyDeriveConfigType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_JobKeyGenerateConfigType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_JobKeyExchangeCalcPubValConfigType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_JobKeyExchangeCalcSecretConfigType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_JobCertificateParseConfigType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_JobCertificateVerifyConfigType;

typedef struct
{
    const uint32 SecureCounterQueueRef;
} Csm_SecureCounterConfigType;

typedef struct
{
    const Csm_HashConfigType* Hash;
    const Csm_MacGenerateConfigType* MacGenerate;
    const Csm_MacVerifyConfigType* MacVerify;
    const Csm_EncryptConfigType* Encrypt;
    const Csm_DecryptConfigType* Decrypt;
    const Csm_AEADEncryptConfigType* AEADEncrypt;
    const Csm_AEADDecryptConfigType* AEADDecrypt;
    const Csm_SignatureGenerateConfigType* SignatureGenerate;
    const Csm_SignatureVerifyConfigType* SignatureVerify;
    const Csm_RandomGenerateConfigType* RandomGenerate;
    const Csm_JobKeySetValidConfigType* JobKeySetValid;
    const Csm_JobRandomSeedConfigType* JobRandomSeed;
    const Csm_JobKeyDeriveConfigType* JobKeyDerive;
    const Csm_JobKeyGenerateConfigType* JobKeyGenerate;
    const Csm_JobKeyExchangeCalcPubValConfigType* JobKeyExchangeCalcPubVal;
    const Csm_JobKeyExchangeCalcSecretConfigType* JobKeyExchangeCalcSecret;
    const Csm_JobCertificateParseConfigType* JobCertificateParse;
    const Csm_JobCertificateVerifyConfigType* JobCertificateVerify;
    const Csm_SecureCounterConfigType* SecureCounterQueueRef;
} Csm_PrimitiveConfigType;

typedef enum
{
    CSM_UNINITIALIZED = 0x00U,
    CSM_INITIALIZED
} Csm_InitStatusType;

typedef union
{
    struct
    {
        uint8 start:1;
        uint8 update:1;
        uint8 finish:1;
    }mode;

    Crypto_OperationModeType all;
} Csm_OperationModeType;

typedef struct
{
    uint32 u32Next;
    Crypto_JobType job;
} Csm_QueueType;

typedef struct
{
    const uint32 u32ChannelRef;
    Csm_QueueType* pQueuedJobs;
    const uint32 u32CsmQueueSize;
    uint32 u32HeadOfFreeJobs;
    uint32 u32HeadOfQueuedJobs;
} Csm_JobQueueType;

/*
********************************************************************************
*    Global Variables
********************************************************************************
*/
#define CSM_START_SEC_VAR_INIT
#include "Csm_MemMap.h"

extern P2VAR(Crypto_JobType, CSM_CONFIG_DATA, CSM_VAR_INIT) cryptoJob[CSM_NUMBER_OF_JOBS];
extern P2VAR(Csm_JobQueueType, CSM_CONFIG_DATA, CSM_VAR_INIT) csmJobQueue[CSM_NUMBER_OF_QUEUES];

#define CSM_STOP_SEC_VAR_INIT
#include "Csm_MemMap.h"

#define CSM_START_SEC_VAR_NO_INIT
#include "Csm_MemMap.h"

extern VAR(Crypto_JobRedirectionInfoType, CSM_VAR_NO_INIT) cryptoJobRedirectionInfo[CSM_NUMBER_OF_INOUTREDIRECTIONS_CONFIG];

#define CSM_STOP_SEC_VAR_NO_INIT
#include "Csm_MemMap.h"

/*
********************************************************************************
*    Global Constants
********************************************************************************
*/
#define CSM_START_SEC_CONFIG_DATA
#include "Csm_MemMap.h"

extern CONST(Csm_JobConfigType, CSM_CONFIG_DATA) csmJobConfig[CSM_NUMBER_OF_JOBS];
extern CONST(Csm_KeyConfigType, CSM_CONFIG_DATA) csmKey[CSM_NUMBER_OF_KEYS];
extern CONST(Csm_CallbackFuncType, CSM_CONFIG_DATA) csmJobCbkService[CSM_NUMBER_OF_JOBS] ;
extern CONST(Crypto_JobRedirectionInfoType, CSM_CONFIG_DATA) cryptoInOutRedirectionConfig[CSM_NUMBER_OF_INOUTREDIRECTIONS];
#define CSM_STOP_SEC_CONFIG_DATA
#include "Csm_MemMap.h"

/*
********************************************************************************
*    Global Functions
********************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"


#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"

#endif /* CSM_CFG_H_ */

