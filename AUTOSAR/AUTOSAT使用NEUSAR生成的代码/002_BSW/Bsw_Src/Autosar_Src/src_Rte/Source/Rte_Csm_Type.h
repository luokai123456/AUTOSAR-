/*
************************************************************************************************************************
*
*  File name: Rte_Csm_Type.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
*  History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
*  Version: 1.0
*  Author/Date : jia_feng/2020.03.02
*  Change: New
*  Cause: New
************************************************************************************************************************
*  Version: 1.0
*  Author/Date : jia_feng/2020.03.02
*  Change: New
*  Cause: New
************************************************************************************************************************
*  Version: 3.0
*  Author/Date: NiXM/2023.03.08
*  Change: Add new structure due to interaction with RTE.
*  Cause: Optimization
************************************************************************************************************************
*  Version: 4.0
*  Author/Date: NiXM/2023.05.31
*  Change: Csm module is update to R21-11.
*  Cause: Update
************************************************************************************************************************
*  Version: 4.1
*  Author/Date: WuHW/2023.11.16
*  Change: 1.Add Crypto_ResultType to replace Csm_ResultType.
*          2.Change Crypto_OperationModeType to the R21-11 version.
*          3.Delete the Csm_CbkServiceOutputType.
*  Cause: Update
************************************************************************************************************************
*/

#ifndef RTE_CSM_TYPE_H_
#define RTE_CSM_TYPE_H_

/*
************************************************************************************************************************
* Includes
************************************************************************************************************************
*/
#include "Std_Types.h"

/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/
/* Csm module specific return values for use in Std_ReturnType that could occur on async. */
#define E_SMALL_BUFFER                  0x02U
#define E_ENTROPY_EXHAUSTION            0x03U
#define E_KEY_READ_FAIL                 0x04U
#define E_KEY_NOT_AVAILABLE             0x05U
#define E_KEY_NOT_VALID                 0x06U
#define E_JOB_CANCELED                  0x07U
#define E_KEY_EMPTY                     0x08U

/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/

#ifndef Rte_TypeDef_Crypto_VerifyResultType
#define Rte_TypeDef_Crypto_VerifyResultType
typedef uint8 Crypto_VerifyResultType;
#endif

/* The result of the verification is "true",
i.e. the two compared elements are identical.
This return code shall be given as value "0" */
#ifndef CRYPTO_E_VER_OK
#define CRYPTO_E_VER_OK                             (0x00U)
#endif

/* The result of the verification is "false",
i.e. the two compared elements are not identical.
This return code shall be given as value "1". */
#ifndef CRYPTO_E_VER_NOT_OK
#define CRYPTO_E_VER_NOT_OK                         (0x01U)
#endif

#ifndef Rte_TypeDef_Csm_ResultType
#define Rte_TypeDef_Csm_ResultType
typedef uint8 Csm_ResultType;
#endif

#ifndef Rte_TypeDef_Crypto_OperationModeType
#define Rte_TypeDef_Crypto_OperationModeType
typedef uint8 Crypto_OperationModeType;
#endif

#ifndef CRYPTO_OPERATIONMODE_IDLE
#define CRYPTO_OPERATIONMODE_IDLE                   (0x00U)  /* Operation Mode is "Idle". */
#endif

#ifndef CRYPTO_OPERATIONMODE_START
#define CRYPTO_OPERATIONMODE_START                  (0x01U)  /* Operation Mode is "Start". The job's state shall be reset, i.e. previous input data and intermediate results shall be deleted. */
#endif

#ifndef CRYPTO_OPERATIONMODE_UPDATE 
#define CRYPTO_OPERATIONMODE_UPDATE                 (0x02U)  /* Operation Mode is "Update". Used to calculate intermediate results. */
#endif

#ifndef CRYPTO_OPERATIONMODE_STREAMSTART
#define CRYPTO_OPERATIONMODE_STREAMSTART            (0x03U)  /* Operation Mode is "Stream Start". Mixture of "Start" and "Update". Used for streaming.*/
#endif

#ifndef CRYPTO_OPERATIONMODE_FINISH
#define CRYPTO_OPERATIONMODE_FINISH                 (0x04U)  /* Operation Mode is "Finish". The calculations shall be finalized. */
#endif

#ifndef CRYPTO_OPERATIONMODE_ERROE
#define CRYPTO_OPERATIONMODE_ERROE                  (0x05U)  /* If Operation Mode is "Start" and "Finish" only,Return E_NOT_OK */
#endif

#ifndef CRYPTO_OPERATIONMODE_SINGLECALL
#define CRYPTO_OPERATIONMODE_SINGLECALL             (0x07U)  /* Operation Mode is "Single Call". Mixture of "Start", "Update" and "Finish". */
#endif

#ifndef CRYPTO_OPERATIONMODE_SAVE_CONTEXT
#define CRYPTO_OPERATIONMODE_SAVE_CONTEXT           (0x08U)  /* Operation mode is "Save workspace context". Context data shall be provided by the crypto driver to the application.*/
#endif

#ifndef CRYPTO_OPERATIONMODE_RESTORE_CONTEXT
#define CRYPTO_OPERATIONMODE_RESTORE_CONTEXT        (0x10U)  /* Operation mode is "Restore workspace context". Application provides the context data that was previously stored and the crypto driver shall restore the internal workspace.*/
#endif

#ifndef Rte_TypeDef_Csm_CbkServiceOutputType
#define Rte_TypeDef_Csm_CbkServiceOutputType
typedef struct
{
    uint8* outputPtr;                               /* Pointer to the output data. */
    uint32* outputLengthPtr;                        /* Holds a pointer to a memory location containing the output length in bytes. */
    uint8* secondaryOutputPtr;                      /* Pointer to the secondary output data. */
    uint32* secondaryOutputLengthPtr;               /* Holds a pointer to a memory location containing the secondary output length in bytes. */
    Crypto_VerifyResultType* verifyPtr;             /* Output pointer to a memory location holding a Crypto_VerifyResultType */
}Csm_CbkServiceOutputType;
#endif

#ifndef Rte_TypeDef_Csm_DataPtr
#define Rte_TypeDef_Csm_DataPtr
typedef uint8* Csm_DataPtr;
#endif
#ifndef Rte_TypeDef_Crypto_ProcessingType
#define Rte_TypeDef_Crypto_ProcessingType
typedef enum Crypto_ProcessingTypeS
{
    CRYPTO_PROCESSING_ASYNC = 0x00U,                 /* Asynchronous job processing */
    CRYPTO_PROCESSING_SYNC,                          /* Synchronous job processing */
    CRYPTO_PROCESSING_NOT_SET                        /* Not set job processing */
} Crypto_ProcessingType;
#endif

#ifndef Rte_TypeDef_Crypto_JobStateType
#define Rte_TypeDef_Crypto_JobStateType
typedef enum
{
    CRYPTO_JOBSTATE_IDLE = 0x00U,                   /* Job is in the state "idle".
                                                       This state is reached after Csm_Init() 
                                                       or when the "Finish" state is finished. */
    CRYPTO_JOBSTATE_ACTIVE                          /* Job is in the state "active". There was
                                                       already some input or there are intermediate results.
                                                       This state is reached, when the "update" or "start"
                                                       operation finishes. */
} Crypto_JobStateType;
#endif

#ifndef Rte_TypeDef_Crypto_JobPrimitiveInputOutputType
#define Rte_TypeDef_Crypto_JobPrimitiveInputOutputType
typedef struct
{
    const uint8* inputPtr;                          /* Pointer to the input data. */
    uint32 inputLength;                             /* Contains the input length in bytes. */
    const uint8* secondaryInputPtr;                 /* Pointer to the secondary input data (for MacVerify, SignatureVerify). */
    uint32 secondaryInputLength;                    /* Contains the secondary input length in bytes. */
    const uint8* tertiaryInputPtr;                  /* Pointer to the tertiary input data (for MacVerify, SignatureVerify). */
    uint32 tertiaryInputLength;                     /* Contains the tertiary input length in bytes. */
    uint8* outputPtr;                               /* Pointer to the output data. */
    uint32* outputLengthPtr;                        /* Holds a pointer to a memory location containing the output length in bytes. */
    uint8* secondaryOutputPtr;                      /* Pointer to the secondary output data. */
    uint32* secondaryOutputLengthPtr;               /* Holds a pointer to a memory location containing the secondary output length in bytes. */
    uint64 input64;                                 /* versatile input parameter */
    Crypto_VerifyResultType* verifyPtr;             /* Output pointer to a memory location holding a Crypto_VerifyResultType */
    uint64* output64Ptr;                            /* Output pointer to a memory location holding a uint64. */
    Crypto_OperationModeType mode;                  /* Indicator of the mode(s)/operation(s) to be performed */
    uint32 cryIfKeyId;                              /* Holds the CryIf key id for key operation services. */
    uint32 targetCryIfKeyId;                        /* Holds the target CryIf key id for key operation services. */
} Crypto_JobPrimitiveInputOutputType;
#endif

#ifndef Rte_TypeDef_Crypto_ServiceInfoType
#define Rte_TypeDef_Crypto_ServiceInfoType
typedef enum
{
   CRYPTO_HASH = 0x00U, 						   /* Hash Service */
   CRYPTO_MACGENERATE,							   /* MacGenerate Service */
   CRYPTO_MACVERIFY,							   /* MacVerify Service */
   CRYPTO_ENCRYPT,								   /* Encrypt Service */
   CRYPTO_DECRYPT,								   /* Decrypt Service */
   CRYPTO_AEADENCRYPT,							   /* AEADEncrypt Service */
   CRYPTO_AEADDECRYPT,							   /* AEADDecrypt Service */
   CRYPTO_SIGNATUREGENERATE,					   /* SignatureGenerate Service */
   CRYPTO_SIGNATUREVERIFY,						   /* SignatureVerify Service */
   CRYPTO_SECCOUNTERINCREMENT,					   /* SecureCounterIncrement Service  AutoSar 4.3.1 required */
   CRYPTO_SECCOUNTERREAD,						   /* SecureCounterRead Service  AutoSar 4.3.1 required */
   CRYPTO_RANDOMGENERATE = 0x0BU,				   /* RandomGenerate Service */
   CRYPTO_RANDOMSEED,							   /* RandomSeed Service */
   CRYPTO_KEYGENERATE,							   /* KeyGenerate Service */
   CRYPTO_KEYDERIVE,							   /* KeyDerive Service */
   CRYPTO_KEYEXCHANGECALCPUBVAL,				   /* KeyExchangeCalcPubVal Service */
   CRYPTO_KEYEXCHANGECALCSECRET,				   /* KeyExchangeCalcSecret Service */
   CRYPTO_CERTIFICATEPARSE, 					   /* CertificiateParse Service */
   CRYPTO_CERTIFICATEVERIFY,					   /* CertificateVerify Service */
   CRYPTO_KEYSETVALID,							   /* KeySetValid Service */
} Crypto_ServiceInfoType;
#endif

#ifndef Rte_TypeDef_Crypto_AlgorithmFamilyType
#define Rte_TypeDef_Crypto_AlgorithmFamilyType
typedef enum
{
    CRYPTO_ALGOFAM_NOT_SET              = 0x00U, /* Algorithm family is not set */
    CRYPTO_ALGOFAM_SHA1                 = 0x01U, /* SHA1 hash */
    CRYPTO_ALGOFAM_SHA2_224             = 0x02U, /* SHA2-224 hash */
    CRYPTO_ALGOFAM_SHA2_256             = 0x03U, /* SHA2-256 hash */
    CRYPTO_ALGOFAM_SHA2_384             = 0x04U, /* SHA2-384 hash */
    CRYPTO_ALGOFAM_SHA2_512             = 0x05U, /* SHA2-512 hash */
    CRYPTO_ALGOFAM_SHA2_512_224         = 0x06U, /* SHA2-512/224 hash */
    CRYPTO_ALGOFAM_SHA2_512_256         = 0x07U, /* SHA2-512/256 hash */
    CRYPTO_ALGOFAM_SHA3_224             = 0x08U, /* SHA3-224 hash */
    CRYPTO_ALGOFAM_SHA3_256             = 0x09U, /* SHA3-256 hash */
    CRYPTO_ALGOFAM_SHA3_384             = 0x0AU, /* SHA3-384 hash */
    CRYPTO_ALGOFAM_SHA3_512             = 0x0BU, /* SHA3-512 hash */
    CRYPTO_ALGOFAM_SHAKE128             = 0x0CU, /* SHAKE128 hash */
    CRYPTO_ALGOFAM_SHAKE256             = 0x0DU, /* SHAKE256 hash */
    CRYPTO_ALGOFAM_RIPEMD160            = 0x0EU, /* RIPEMD hash */
    CRYPTO_ALGOFAM_BLAKE_1_256          = 0x0FU, /* BLAKE-1-256 hash */
    CRYPTO_ALGOFAM_BLAKE_1_512          = 0x10U, /* BLAKE-1-512 hash */
    CRYPTO_ALGOFAM_BLAKE_2s_256         = 0x11U, /* BLAKE-2s-256 hash */
    CRYPTO_ALGOFAM_BLAKE_2s_512         = 0x12U, /* BLAKE-2s-512 hash */
    CRYPTO_ALGOFAM_3DES                 = 0x13U, /* 3DES cipher */
    CRYPTO_ALGOFAM_AES                  = 0x14U, /* AES cipher */
    CRYPTO_ALGOFAM_CHACHA               = 0x15U, /* ChaCha cipher */
    CRYPTO_ALGOFAM_RSA                  = 0x16U, /* RSA cipher */
    CRYPTO_ALGOFAM_ED25519              = 0x17U, /* ED22518 elliptic curve */
    CRYPTO_ALGOFAM_BRAINPOOL            = 0x18U, /* Brainpool elliptic curve */
    CRYPTO_ALGOFAM_ECCNIST              = 0x19U, /* NIST ECC elliptic curves */
    CRYPTO_ALGOFAM_SECURECOUNTER        = 0x1AU, /* Secure Counter, AutoSar 4.3.1 required */
    CRYPTO_ALGOFAM_RNG                  = 0x1BU, /* Random Number Generator */
    CRYPTO_ALGOFAM_SIPHASH              = 0x1CU, /* SipHash */
    CRYPTO_ALGOFAM_ECIES                = 0x1DU, /* ECIES Cipher */
    CRYPTO_ALGOFAM_ECCANSI              = 0x1EU, /* Elliptic curve according to ANSI X9.62 */
    CRYPTO_ALGOFAM_ECCSEC               = 0x1FU, /* Elliptic curve according to SECG */
    CRYPTO_ALGOFAM_DRBG                 = 0x20U, /* Random number generator according to NIST SP800-90A */
    CRYPTO_ALGOFAM_FIPS186              = 0x21U, /* Random number generator according to FIPS 186. */
    CRYPTO_ALGOFAM_PADDING_PKCS7        = 0x22U, /* Cipher padding according to PKCS.7 */
    CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS = 0x23U, /* Cipher padding mode. Fill/verify data with 0,but first bit after the data is 1. Eg. "DATA" & 0x80 & 0x00... */
    CRYPTO_ALGOFAM_PBKDF2               = 0x24U, /* Password-Based Key Derivation Function 2 */
    CRYPTO_ALGOFAM_KDFX963              = 0x25U, /* ANSI X9.63 Public Key Cryptography */
    CRYPTO_ALGOFAM_DH                   = 0x26U, /* Diffie-Hellman */
    /* Add by AUTOSAR R2011 */
    CRYPTO_ALGOFAM_SM2                  = 0x27U, /* SM2 elliptic curve algorithm */
    CRYPTO_ALGOFAM_EEA3                 = 0x28U, /* Stream cipher based on [x01] */
    CRYPTO_ALGOFAM_SM3                  = 0x29U, /* Chinese hash algorithm based on [x02] */
    CRYPTO_ALGOFAM_EIA3                 = 0x2AU, /* Authentication algorithm [x01] */
    CRYPTO_ALGOFAM_HKDF                 = 0x2BU, /* HMAC-based extract-and-expand keyderivation function */
    CRYPTO_ALGOFAM_ECDSA                = 0x2CU, /* Elliptic-curve Digital Signatures */
    CRYPTO_ALGOFAM_POLY1305             = 0x2DU, /* MAC calculation algorithm */
    CRYPTO_ALGOFAM_X25519               = 0x2EU, /* Elliptic curve X25519 for ECDH */
    CRYPTO_ALGOFAM_ECDH                 = 0x2FU, /* Elliptic-curve Diffie Hellman */
    CRYPTO_ALGOFAM_CUSTOM               = 0xFFU  /* Custom algorithm family */
} Crypto_AlgorithmFamilyType;
#endif

#ifndef Rte_TypeDef_Crypto_AlgorithmModeType
#define Rte_TypeDef_Crypto_AlgorithmModeType
typedef enum
{
    CRYPTO_ALGOMODE_NOT_SET = 0x00U,                /* Algorithm key is not set */
    CRYPTO_ALGOMODE_ECB,                            /* Blockmode: Electronic Code Book */
    CRYPTO_ALGOMODE_CBC,                            /* Blockmode: Cipher Block Chaining */
    CRYPTO_ALGOMODE_CFB,                            /* Blockmode: Cipher Feedback Mode */
    CRYPTO_ALGOMODE_OFB,                            /* Blockmode: Output Feedback Mode */
    CRYPTO_ALGOMODE_CTR,                            /* Blockmode: Counter Modex */
    CRYPTO_ALGOMODE_GCM,                            /* Blockmode: Galois/Counter Mode */
    CRYPTO_ALGOMODE_XTS,                            /* XOR-encryption-based tweaked-codebook mode with ciphertext stealing */
    CRYPTO_ALGOMODE_RSAES_OAEP,                     /* RSA Optimal Asymmetric Encryption Padding */
    CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5,               /* RSA encryption/decryption with PKCS#1 v1.5 padding */
    CRYPTO_ALGOMODE_RSASSA_PSS,                     /* RSA Probabilistic Signature Scheme */
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5,              /* RSA signature with PKCS#1 v1.5 */
    CRYPTO_ALGOMODE_8ROUNDS,                        /* 8 rounds (e.g. ChaCha8) */
    CRYPTO_ALGOMODE_12ROUNDS,                       /* 12 rounds (e.g. ChaCha12) */
    CRYPTO_ALGOMODE_20ROUNDS,                       /* 20 rounds (e.g. ChaCha20) */
    CRYPTO_ALGOMODE_HMAC,                           /* Hashed-based MAC */
    CRYPTO_ALGOMODE_CMAC,                           /* Cipher-based MAC */
    CRYPTO_ALGOMODE_GMAC,                           /* Galois MAC */
    CRYPTO_ALGOMODE_CTRDRBG,                        /* Counter-based Deterministic Random Bit Generator */
    CRYPTO_ALGOMODE_SIPHASH_2_4,                    /* Siphash-2-4 */
    CRYPTO_ALGOMODE_SIPHASH_4_8,                    /* Siphash-4-8 */
    CRYPTO_ALGOMODE_PXXXR1,                         /* ANSI R1 Curve */
    CRYPTO_ALGOMODE_CUSTOM = 0xFFU                  /* Custom algorithm mode */
} Crypto_AlgorithmModeType;
#endif


#ifndef Rte_TypeDef_Crypto_AlgorithmInfoType
#define Rte_TypeDef_Crypto_AlgorithmInfoType
typedef struct
{
    Crypto_AlgorithmFamilyType family;              /* The family of the algorithm */
    Crypto_AlgorithmFamilyType secondaryFamily;     /* The secondary family of the algorithm */
    uint32 keyLength;                               /* The key length in bits to be used with that algorithm */
    Crypto_AlgorithmModeType mode;                  /* The operation mode to be used with that algorithm */
} Crypto_AlgorithmInfoType;
#endif


#ifndef Rte_TypeDef_Crypto_PrimitiveInfoType
#define Rte_TypeDef_Crypto_PrimitiveInfoType
typedef struct
{
    const uint32 resultLength;                      /* Contains the result length in bytes. */
    const Crypto_ServiceInfoType service;           /* Contains the enum of the used service, e.g. Encrypt */
    const Crypto_AlgorithmInfoType algorithm;       /* Contains the information of the used algorithm */
} Crypto_PrimitiveInfoType;
#endif

#ifndef Rte_TypeDef_Crypto_JobPrimitiveInfoType
#define Rte_TypeDef_Crypto_JobPrimitiveInfoType
typedef struct
{
    uint32 callbackId;                              /* Identifier of the callback */
    const Crypto_PrimitiveInfoType* primitiveInfo;  /* Pointer to a structure containing further configuration of the crypto primitives */
    uint32 cryIfKeyId;                              /* Identifier of the CryIf key. */
    Crypto_ProcessingType processingType;           /* Determines the synchronous or asynchronous behavior. */
    boolean callbackUpdateNotification;             /* Indicates, whether the callback function shall be called, if the UPDATE operation has finished. */
} Crypto_JobPrimitiveInfoType;
#endif

#ifndef Rte_TypeDef_Crypto_JobInfoType
#define Rte_TypeDef_Crypto_JobInfoType
typedef struct
{
    const uint32 jobId;                             /* The family of the algorithm */
    const uint32 jobPriority;                       /* Specifies the importance of the job (the higher, the more important). */
} Crypto_JobInfoType;
#endif

#ifndef Rte_TypeDef_Crypto_JobRedirectionInfoType
#define Rte_TypeDef_Crypto_JobRedirectionInfoType
typedef struct
{
    uint8 redirectionConfig;                        /* Bit structure which indicates which buffer shall 
                                                       be redirected to a key element. Values from
                                                       Crypto_InputOutputRedirectionConfigType can
                                                       be used and combined with unary OR operation. */
    uint32 inputKeyId;                              /* Identifier of the key which shall be used as input */
    uint32 inputKeyElementId;                       /* Identifier of the key element which shall be used as input */
    uint32 secondaryInputKeyId;                     /* Identifier of the key which shall be used as secondary input */
    uint32 secondaryInputKeyElementId;              /* Identifier of the key element which shall be used as secondary input */
    uint32 tertiaryInputKeyId;                      /* Identifier of the key which shall be used as tertiary input */
    uint32 tertiaryInputKeyElementId;               /* Identifier of the key element which shall be used as tertiary input */
    uint32 outputKeyId;                             /* Identifier of the key which shall be used as output */
    uint32 outputKeyElementId;                      /* Identifier of the key element which shall be used as output */
    uint32 secondaryOutputKeyId;                    /* Identifier of the key which shall be used as secondary output */
    uint32 secondaryOutputKeyElementId;             /* Identifier of the key element which shall be used as secondary output */
} Crypto_JobRedirectionInfoType;
#endif

#ifndef Rte_TypeDef_Crypto_JobType
#define Rte_TypeDef_Crypto_JobType
typedef struct
{
    uint32 jobId;
    Crypto_JobStateType jobState;
    Crypto_JobPrimitiveInputOutputType jobPrimitiveInputOutput;
    const Crypto_JobPrimitiveInfoType* jobPrimitiveInfo;
    const Crypto_JobInfoType* jobInfo;
    uint32 cryptoKeyId;                                         /* Identifier of the Crypto Driver key.
                                                                   The identifier shall be written by
                                                                   the Crypto Interface. AutoSar 4.3.1 required */
    uint32 targetCryptoKeyId;
    Crypto_JobRedirectionInfoType* jobRedirectionInfoRef;
} Crypto_JobType;
#endif
/*
************************************************************************************************************************
*    Global variable
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Constants
************************************************************************************************************************
*/
/*
************************************************************************************************************************
*    Global Functions
************************************************************************************************************************
*/

#endif

