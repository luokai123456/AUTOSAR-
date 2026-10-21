/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Csm
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Csm.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Csm MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/
/* PRQA S 0779 EOF */
#ifndef CSM_H
#define CSM_H

#include "Compiler.h"
#include "Std_Types.h"

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* key element index definition */
/* MAC */
#define CRYPTO_KE_MAC_KEY                               ((uint32)1U)    /* Key Material */
#define CRYPTO_KE_MAC_PROOF                             ((uint32)2U)    /* Proof (SHE) */
/* Signature */
#define CRYPTO_KE_SIGNATURE_KEY                         ((uint32)1U)    /* Key Material */
/* Random */
#define CRYPTO_KE_RANDOM_SEED_STATE                     ((uint32)3U)    /* Seed State */
#define CRYPTO_KE_RANDOM_ALGORITHM                      ((uint32)4U)    /* Algorithm */
/* Cipher/AEAD */
#define CRYPTO_KE_CIPHER_KEY                            ((uint32)1U)    /* Key Material */
#define CRYPTO_KE_CIPHER_IV                             ((uint32)5U)    /* Init Vector */
#define CRYPTO_KE_CIPHER_PROOF                          ((uint32)6U)    /* Proof (SHE) */
#define CRYPTO_KE_CIPHER_2NDKEY                         ((uint32)7U)    /* 2nd Key Material */
/* Key Exchange */
#define CRYPTO_KE_KEYEXCHANGE_BASE                      ((uint32)8U)    /* Base */
#define CRYPTO_KE_KEYEXCHANGE_PRIVKEY                   ((uint32)9U)    /* Private Key */
#define CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY                 ((uint32)10U)   /* Own Public Key */
#define CYRPTO_KE_KEYEXCHANGE_SHAREDVALUE               ((uint32)1U)    /* Shared Value */
#define CRYPTO_KE_KEYEXCHANGE_ALGORITHM                 ((uint32)12U)   /* Algorithm */
/* Key Derivation */
#define CRYPTO_KE_KEYDERIVATION_PASSWORD                ((uint32)1U)    /* Password */
#define CRYPTO_KE_KEYDERIVATION_SALT                    ((uint32)13U)   /* Salt */
#define CRYPTO_KE_KEYDERIVATION_ITERATIONS              ((uint32)14U)   /* Iterations */
#define CRYPTO_KE_KEYDERIVATION_ALGORITHM               ((uint32)15U)   /* Algorithm */
/* Key Generate */
#define CRYPTO_KE_KEYGENERATE_KEY                       ((uint32)1U)    /* Algorithm */
#define CRYPTO_KE_KEYGENERATE_SEED                      ((uint32)16U)   /* Algorithm */
#define CRYPTO_KE_KEYGENERATE_ALGORITHM                 ((uint32)17U)   /* Algorithm */
/* Certificate Parsing */
#define CRYPTO_KE_CERTIFICATE_DATA                      ((uint32)0U)    /* Certificate */
#define CRYPTO_KE_CERTIFICATE_PARSING_FORMAT            ((uint32)18U)   /* Format */
#define CRYPTO_KE_CERTIFICATE_CURRENT_TIME              ((uint32)19U)   /* Current time */
#define CRYPTO_KE_CERTIFICATE_VERSION                   ((uint32)20U)   /* Version */
#define CRYPTO_KE_CERTIFICATE_SERIALNUMBER              ((uint32)21U)   /* Serial Number */
#define CRYPTO_KE_CERTIFICATE_SIGNATURE_ALGORITHM       ((uint32)22U)   /* Signature Algorithm */
#define CRYPTO_KE_CERTIFICATE_ISSUER                    ((uint32)23U)   /* Issuer */
#define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE       ((uint32)24U)   /* Validity Start */
#define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER        ((uint32)25U)   /* Validity End */
#define CRYPTO_KE_CERTIFICATE_SUBJECT                   ((uint32)26U)   /* Subject */
#define CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY        ((uint32)1U)    /* Subject Public Key */
#define CRYPTO_KE_CERTIFICATE_EXTENSIONS                ((uint32)27U)   /* Extensions */
#define CRYPTO_KE_CERTIFICATE_SIGNATURE                 ((uint32)28U)   /* Signature */

/* Enumeration of the algorithm family. */
typedef enum
{
    CRYPTO_ALGOFAM_NOT_SET              = 0x00U,
    CRYPTO_ALGOFAM_SHA1                 = 0x01U,
    CRYPTO_ALGOFAM_SHA2_224             = 0x02U,
    CRYPTO_ALGOFAM_SHA2_256             = 0x03U,
    CRYPTO_ALGOFAM_SHA2_384             = 0x04U,
    CRYPTO_ALGOFAM_SHA2_512             = 0x05U,
    CRYPTO_ALGOFAM_SHA2_512_224         = 0x06U,
    CRYPTO_ALGOFAM_SHA2_512_256         = 0x07U,
    CRYPTO_ALGOFAM_SHA3_224             = 0x08U,
    CRYPTO_ALGOFAM_SHA3_256             = 0x09U,
    CRYPTO_ALGOFAM_SHA3_384             = 0x0AU,
    CRYPTO_ALGOFAM_SHA3_512             = 0x0BU,
    CRYPTO_ALGOFAM_SHAKE128             = 0x0CU,
    CRYPTO_ALGOFAM_SHAKE256             = 0x0DU,
    CRYPTO_ALGOFAM_RIPEMD160            = 0x0EU,
    CRYPTO_ALGOFAM_BLAKE_1_256          = 0x0FU,
    CRYPTO_ALGOFAM_BLAKE_1_512          = 0x10U,
    CRYPTO_ALGOFAM_BLAKE_2s_256         = 0x11U,
    CRYPTO_ALGOFAM_BLAKE_2s_512         = 0x12U,
    CRYPTO_ALGOFAM_3DES                 = 0x13U,
    CRYPTO_ALGOFAM_AES                  = 0x14U,
    CRYPTO_ALGOFAM_CHACHA               = 0x15U,
    CRYPTO_ALGOFAM_RSA                  = 0x16U,
    CRYPTO_ALGOFAM_ED25519              = 0x17U,
    CRYPTO_ALGOFAM_BRAINPOOL            = 0x18U,
    CRYPTO_ALGOFAM_ECCNIST              = 0x19U,
    CRYPTO_ALGOFAM_SECURECOUNTER        = 0x1AU,
    CRYPTO_ALGOFAM_RNG                  = 0x1BU,
    CRYPTO_ALGOFAM_SIPHASH              = 0x1CU,
    CRYPTO_ALGOFAM_ECCANSI              = 0x1eU,
    CRYPTO_ALGOFAM_ECCSEC               = 0x1fU,
    CRYPTO_ALGOFAM_DRBG                 = 0x20U,
    CRYPTO_ALGOFAM_FIPS186              = 0x21U,
    CRYPTO_ALGOFAM_PADDING_PKCS7        = 0x22U,
    CRYPTO_ALGOFAM_PADDING_ONEWITHZEROS = 0x23U,
    CRYPTO_ALGOFAM_PBKDF2               = 0x24U,
    CRYPTO_ALGOFAM_KDFX963              = 0x25U,
    CRYPTO_ALGOFAM_DH                   = 0x26U,
    CRYPTO_ALGOFAM_SM2                  = 0x27U,
    CRYPTO_ALGOFAM_EEA3                 = 0x28U,
    CRYPTO_ALGOFAM_SM3                  = 0x29U,
    CRYPTO_ALGOFAM_EIA3                 = 0x2AU,
    CRYPTO_ALGOFAM_HKDF                 = 0x2BU,
    CRYPTO_ALGOFAM_ECDSA                = 0x2CU,
    CRYPTO_ALGOFAM_POLY1305             = 0x2DU,
    CRYPTO_ALGOFAM_X25519               = 0x2EU,
    CRYPTO_ALGOFAM_ECDH                 = 0x2FU,
	CRYPTO_ALGOFAM_SM4					= 0x30U,
    CRYPTO_ALGOFAM_CUSTOM               = 0xFFU
} Crypto_AlgorithmFamilyType;

/* Enumeration of the algorithm mode */
typedef enum
{
    CRYPTO_ALGOMODE_NOT_SET             = 0x00U,  /* Algorithm key is not set */
    CRYPTO_ALGOMODE_ECB                 = 0x01U,  /* Blockmode: Electronic Code Book */
    CRYPTO_ALGOMODE_CBC                 = 0x02U,  /* Blockmode: Cipher Block Chaining */
    CRYPTO_ALGOMODE_CFB                 = 0x03U,  /* Blockmode: Cipher Feedback Mode */
    CRYPTO_ALGOMODE_OFB                 = 0x04U,  /* Blockmode: Output Feedback Mode */
    CRYPTO_ALGOMODE_CTR                 = 0x05U,  /* Blockmode: Counter Modex */
    CRYPTO_ALGOMODE_GCM                 = 0x06U,  /* Blockmode: Galois/Counter Mode */
    CRYPTO_ALGOMODE_XTS                 = 0x07U,  /* XOR-encryption-based tweaked-codebook mode with ciphertext stealing */
    CRYPTO_ALGOMODE_RSAES_OAEP          = 0x08U,  /* RSA Optimal Asymmetric Encryption Padding */
    CRYPTO_ALGOMODE_RSAES_PKCS1_v1_5    = 0x09U,  /* RSA encryption/decryption with PKCS#1 v1.5 padding */
    CRYPTO_ALGOMODE_RSASSA_PSS          = 0x0AU,  /* RSA Probabilistic Signature Scheme */
    CRYPTO_ALGOMODE_RSASSA_PKCS1_v1_5   = 0x0BU,  /* RSA signature with PKCS#1 v1.5 */
    CRYPTO_ALGOMODE_8ROUNDS             = 0x0CU,  /* 8 rounds (e.g. ChaCha8) */
    CRYPTO_ALGOMODE_12ROUNDS            = 0x0DU,  /* 12 rounds (e.g. ChaCha12) */
    CRYPTO_ALGOMODE_20ROUNDS            = 0x0EU,  /* 20 rounds (e.g. ChaCha20) */
    CRYPTO_ALGOMODE_HMAC                = 0x0FU,  /* Hashed-based MAC */
    CRYPTO_ALGOMODE_CMAC                = 0x10U,  /* Cipher-based MAC */
    CRYPTO_ALGOMODE_GMAC                = 0x11U,  /* Galois MAC */
    CRYPTO_ALGOMODE_CTRDRBG             = 0x12U,  /* Counter-based Deterministic Random Bit Generator */
    CRYPTO_ALGOMODE_SIPHASH_2_4         = 0x13U,  /* Siphash-2-4 */
    CRYPTO_ALGOMODE_SIPHASH_4_8         = 0x14U,  /* Siphash-4-8 */
    CRYPTO_ALGOMODE_PXXXR1              = 0x15U,  /* ANSI R1 Curve */
    CRYPTO_ALGOMODE_CUSTOM              = 0xffU   /* Custom algorithm mode */
} Crypto_AlgorithmModeType;

/* Enumeration of the processing type */
typedef enum
{
    CRYPTO_PROCESSING_ASYNC = 0x00, /* Asynchronous job processing */
    CRYPTO_PROCESSING_SYNC  = 0x01  /* Synchronous job processing */
} Crypto_ProcessingType;

/* Defines which of the input/output parameters are re-directed to a key element. The values can be combined to define a bit field. */
typedef enum
{
    CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT    = 0x01U,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT  = 0x02U,
    CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT   = 0x04U,
    CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT   = 0x10U,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT = 0x20U
} Crypto_InputOutputRedirectionConfigType;

/* Enumeration of the current job state */
typedef enum
{
    CRYPTO_JOBSTATE_IDLE    = 0x00U, /* Job is in the state "idle". This state is reached after Csm_ Init() or when the "Finish" state is finished */
    CRYPTO_JOBSTATE_ACTIVE  = 0x01U  /* Job is in the state "active". There was already some input or there are intermediate results. This state is reached, when the "update" or "start" operation finishes. */
} Crypto_JobStateType;

/* Enumeration of the result type of verification operations. */
typedef enum
{
    CRYPTO_E_VER_OK          = 0x00U,    /* The result of the verification is "true", i.e. the two compared elements are identical. This return code shall be given as value "0" */
    CRYPTO_E_VER_NOT_OK      = 0x01U     /* The result of the verification is "false", i.e. the two compared elements are not identical. This return code shall be given as value "1". */
} Crypto_VerifyResultType;

/* Enumeration which operation shall be performed. This enumeration is constructed
   from a bit mask, where the first bit indicates "Start", the second "Update" and the third
  "Finish" */
typedef enum
{
    CRYPTO_OPERATIONMODE_START           = 0x01U, /* Operation Mode is "Start". The job's state shall be reset, i.e. previous input data and intermediate results shall be deleted. */
    CRYPTO_OPERATIONMODE_UPDATE          = 0x02U, /* Operation Mode is "Update". Used to calculate intermediate results. */
    CRYPTO_OPERATIONMODE_STREAMSTART     = 0x03U, /* Operation Mode is "Stream Start". Mixture of "Start" and "Update". Used for streaming. */
    CRYPTO_OPERATIONMODE_FINISH          = 0x04U, /* Operation Mode is "Finish". The calculations shall be finalized */
    CRYPTO_OPERATIONMODE_SINGLECALL      = 0x07U, /* Operation Mode is "Single Call". Mixture of "Start", "Update" and "Finish". */
    CRYPTO_OPERATIONMODE_SAVE_CONTEXT    = 0x08U, /* Operation mode is "Save workspace context".Context data shall be provided by the crypto driver to the application */
    CRYPTO_OPERATIONMODE_RESTORE_CONTEXT = 0x10U, /* Operation mode is "Restore workspace context". Application provides the context data that was previously stored and the crypto driver shall restore the internal workspace. */
} Crypto_OperationModeType;

/* Enumeration of the kind of the service. */
typedef enum
{
    CRYPTO_HASH                  = 0x00U,  /* Hash Service */
    CRYPTO_MACGENERATE           = 0x01U,  /* MacGenerate Service */
    CRYPTO_MACVERIFY             = 0x02U,  /* MacVerify Service */
    CRYPTO_ENCRYPT               = 0x03U,  /* Encrypt Service */
    CRYPTO_DECRYPT               = 0x04U,  /* Decrypt Service */
    CRYPTO_AEADENCRYPT           = 0x05U,  /* AEADEncrypt Service */
    CRYPTO_AEADDECRYPT           = 0x06U,  /* AEADDecrypt Service */
    CRYPTO_SIGNATUREGENERATE     = 0x07U,  /* SignatureGenerate Service */
    CRYPTO_SIGNATUREVERIFY       = 0x08U,  /* SignatureVerify Service */
    CRYPTO_RANDOMGENERATE        = 0x0BU,  /* RandomGenerate Service */
    CRYPTO_RANDOMSEED            = 0x0CU,  /* RandomSeed Service */
    CRYPTO_KEYGENERATE           = 0x0DU,  /* KeyGenerate Service */
    CRYPTO_KEYDERIVE             = 0x0EU,  /* KeyDerive Service */
    CRYPTO_KEYEXCHANGECALCPUBVAL = 0x0FU,  /* KeyExchangeCalcPubVaL Service */
    CRYPTO_KEYEXCHANGECALCSECRET = 0x10U,  /* KeyExchangeCalcSecret Service */
	CRYPTO_CERTIFICATEPARSE		 = 0x11u,  /* CertificiateParse Service */
	CRYPTO_CERTIFICATEVERIFY	 = 0x12u,  /* CertificateVerify Service */
    CRYPTO_KEYSETVALID           = 0x13U   /* KeySetValid Service */
} Crypto_ServiceInfoType;

typedef struct
{
    CONST (uint32, CSM_CONST) jobId;
    CONST (uint32, CSM_CONST) jobPriority;
} Crypto_JobInfoType;

typedef struct
{
    VAR(uint8, AUTOMATIC) redirectionConfig; /* Bit structure which indicates which buffer shall be redirected to a key element. Values from
                                                Crypto_InputOutputRedirectionConfigType can be used and combined with unary OR operation. */
    VAR(uint32, AUTOMATIC) inputKeyId; /* Identifier of the key which shall be used as input */
    VAR(uint32, AUTOMATIC) inputKeyElementId; /* Identifier of the key element which shall be used as input */
    VAR(uint32, AUTOMATIC) secondaryInputKeyId; /* Identifier of the key which shall be used as secondary input */
    VAR(uint32, AUTOMATIC) secondaryInputKeyElementId; /* Identifier of the key element which shall be used as secondary input */
    VAR(uint32, AUTOMATIC) tertiaryInputKeyId; /* Identifier of the key which shall be used as tertiary input */
    VAR(uint32, AUTOMATIC) tertiaryInputKeyElementId; /* Identifier of the key element which shall be used as tertiary input */
    VAR(uint32, AUTOMATIC) outputKeyId; /* Identifier of the key which shall be used as output */
    VAR(uint32, AUTOMATIC) outputKeyElementId; /* Identifier of the key element which shall be used as output */
    VAR(uint32, AUTOMATIC) secondaryOutputKeyId; /* Identifier of the key which shall be used as secondary output */
    VAR(uint32, AUTOMATIC) secondaryOutputKeyElementId; /* Identifier of the key element which shall be used as secondary output */
} Crypto_JobRedirectionInfoType;

/* Structure which contains input and output information depending on the job and the crypto primitive. */
typedef struct
{
    P2CONST (uint8, AUTOMATIC, CSM_APPL_CONST) inputPtr;                 /* Pointer to the input data. */
    VAR (uint32, AUTOMATIC) inputLength;                                 /* Contains the input length in bytes. */
    P2CONST (uint8, AUTOMATIC, CSM_APPL_CONST) secondaryInputPtr;        /* Pointer to the secondary input data (for MacVerify, SignatureVerify). */
    VAR (uint32, AUTOMATIC) secondaryInputLength;                        /* Contains the secondary input length in bytes. */
    P2CONST (uint8, AUTOMATIC, CSM_APPL_CONST) tertiaryInputPtr;         /* Pointer to the tertiary input data (for MacVerify, SignatureVerify). */
    VAR (uint32, AUTOMATIC) tertiaryInputLength;                         /* Contains the tertiary input length in bytes. */
    P2VAR (uint8, AUTOMATIC, CSM_APPL_DATA) outputPtr;                   /* Pointer to the output data. */
    P2VAR (uint32, AUTOMATIC, CSM_APPL_DATA) outputLengthPtr;            /* Holds a pointer to a memory location containing the output length in bytes. */
    P2VAR (uint8, AUTOMATIC, CSM_APPL_DATA) secondaryOutputPtr;          /* Pointer to the secondary output data. */
    P2VAR (uint32, AUTOMATIC, CSM_APPL_DATA) secondaryOutputLengthPtr;   /* Holds a pointer to a memory location containing the secondary output length in bytes. */
    VAR (uint64, AUTOMATIC) input64;                                     /* Versatile input parameter */
    P2VAR (Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr; /* Output pointer to a memory location holding a Crypto_VerifyResultType */
    P2VAR (uint64, AUTOMATIC, CSM_APPL_DATA) output64Ptr;                /* Output pointer to a memory location holding an uint64. */
    VAR (Crypto_OperationModeType, AUTOMATIC) mode;                      /* Indicator of the mode(s)/operation(s) to be performed */
    VAR (uint32, AUTOMATIC) cryIfKeyId;									 /* Holds the CryIf key id for key operation services. */
    VAR (uint32, AUTOMATIC) targetCryIfKeyId;							 /* Holds the target CryIf key id for key operation services. */
} Crypto_JobPrimitiveInputOutputType;

/* Structure which determines the exact algorithm. Note, not every algorithm needs to specify all fields. AUTOSAR shall only allow valid combinations. */
typedef struct
{
    VAR (Crypto_AlgorithmFamilyType, AUTOMATIC) family;           /* The family of the algorithm */
    VAR (Crypto_AlgorithmFamilyType, AUTOMATIC) secondaryFamily;  /* The secondary family of the algorithm  */
    VAR (uint32, AUTOMATIC) keyLength;                            /* The key length in bits to be used with that algorithm */
    VAR (Crypto_AlgorithmModeType, AUTOMATIC) mode;               /* The operation mode to be used with that algorithm */
} Crypto_AlgorithmInfoType;

/* Structure which contains basic information about the crypto primitive. */
typedef struct
{
	CONST (uint32, CSM_CONST) resultLength;					 /*  Contains the result length in bytes. */
    CONST (Crypto_ServiceInfoType, CSM_CONST) service;       /* Contains the enum of the used service, e.g. Encrypt */
    CONST (Crypto_AlgorithmInfoType, CSM_CONST) algorithm;   /* Contains the information of the used algorithm */
} Crypto_PrimitiveInfoType;

/*  Structure which contains further information, which depends on the job and the crypto primitive */
typedef struct
{
	VAR (uint32, AUTOMATIC) callbackId;                                         /* Internal identifier of the callback function, to be called by Csm, if the configured service is finished. */
    P2CONST (Crypto_PrimitiveInfoType, CSM_VAR, CSM_APPL_CONST) primitiveInfo;  /* Pointer to a structure containing further configuration of the crypto primitives */
    VAR (uint32, AUTOMATIC) cryIfKeyId;                                         /* Identifier of the CryIf key. */
    VAR (Crypto_ProcessingType, AUTOMATIC) processingType;                      /* Determines the synchronous or asynchronous behavior. */
    VAR (boolean, AUTOMATIC) callbackUpdateNotification;						/* Indicates, whether the callback function shall be called, if the UPDATE operation has finished. */
} Crypto_JobPrimitiveInfoType;

typedef struct
{
    CONST (uint32, CSM_CONST) jobId;                                                    		/* identifier for the job structure */
    VAR (Crypto_JobStateType, AUTOMATIC) jobState;                                      		/* determines the current job state */
    VAR (Crypto_JobPrimitiveInputOutputType, AUTOMATIC) jobPrimitiveInputOutput;        		/* structure containing input and output information depending on the job and the crypto primitive */
    P2CONST (Crypto_JobPrimitiveInfoType, AUTOMATIC, CSM_APPL_CONST) jobPrimitiveInfo;    		/* pointer to a structure containing further information, which depends on the job and the crypto primitive */
    P2CONST (Crypto_JobInfoType, AUTOMATIC, CSM_APPL_CONST) jobInfo;                      		/* Pointer to a structure containingfurther information which depends on the job and the */
    VAR (uint32, AUTOMATIC) cryptoKeyId;
    VAR (uint32, AUTOMATIC) targetCryptoKeyId;
    P2VAR (Crypto_JobRedirectionInfoType, AUTOMATIC, CSM_APPL_DATA) jobRedirectionInfoRef;      /* Pointer to a structure containing further information on the usage of keys as input and output for jobs */
} Crypto_JobType;

#endif /* CSM_H */
