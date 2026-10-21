/*
********************************************************************************
*
*  File name: Csm.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date: jiaF/2020.03.02
*  Change: New
*  Cause: New
********************************************************************************
*  Version: 3.0
*  Author/Date: jiaF/2020.07.02
*  Change: Nothing
*  Cause: Update
********************************************************************************
*  Version: 3.1
*  Author/Date: GuoZY/2020.10.27
*  Change: Modify the code according to the AUTOSAR specification
*  Cause: Optimization
********************************************************************************
*  Version: 3.2
*  Author/Date: ZhangY/2021.07.07
*  Change: CRYPTO_E_BUSY...CRYPTO_E_KEY_EMPTY, These macro change to Csm_Types.h.
*  Cause: Optimization
********************************************************************************
*  Version: 3.3
*  Author/Date: ZhangY/2021.11.1
*  Change: Change CRYIF_SW_PATCH_VERSION to 1.
*  Cause: Update
********************************************************************************
*  Version: 3.4
*  Author/Date: ZhangY/2022.01.05
*  Change: Csm_KeyExchangeCalcSecret parameter partnerPublicValuePtr change to P2CONST.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.5
*  Author/Date: LiRQ/2022.12.02
*  Change: Update software version to 3.2.2 about the bug of the method of
*          refering to CryIfkeyId.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.6
*  Author/Date: NiXM/2022.12.10
*  Change: Update software version to 3.2.3 about the bug of the method of
*          refering to CryIfkeyId.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.7
*  Author/Date: NiXM/2023.01.17
*  Change: Update software version to 3.2.4 about the elimination of compilation
*          warnings.
*  Cause: Optimization
********************************************************************************
*  Version: 3.8
*  Author/Date: NiXM/2023.01.31
*  Change: Update software version to 3.2.5 about the coding standards.
*  Cause: Optimization
********************************************************************************
*  Version: 3.9
*  Author/Date: NiXM/2023.03.22
*  Change: Update software version to 3.2.6 about the bug of byte alignment and
*          job processing.
*  Cause: Bug
********************************************************************************
*  Version: 3.10
*  Author/Date: NiXM/2023.04.12
*  Change: Update software version to 3.2.7 about the parameter of Csm_AEADDecrypt.
*  Cause: Bug
********************************************************************************
*  Version: 3.11
*  Author/Date: NiXM/2023.05.24
*  Change: Update software version to 3.7.0 about the publishment of the edition.
*  Cause: Update
********************************************************************************
*  Version: 3.12
*  Author/Date: NiXM/2023.05.24
*  Change: Update the patch version.
*  Cause: Update
********************************************************************************
*  Version: 3.13
*  Author/Date: MengY/2023.08.03
*  Change: Update the patch version.
*  Cause: Update
********************************************************************************
*  Version: 3.14
*  Author/Date: MengY/2023.09.18
*  Change: Update the patch version.
*  Cause: Update
********************************************************************************
*  Version: 3.15
*  Author/Date: MengY/2023.11.22
*  Change: Update the patch version.
*  Cause: Update
********************************************************************************
*  Version: 3.16
*  Author/Date: MengY/2023.11.23
*  Change: Update the patch version.
*  Cause: Update
********************************************************************************
* Version: 3.17
* Author/Date: MengY/2024.05.08
* Change: 1.Add memmap section for function declaration.
*         2.Update the patch version.
* Cause: Update
********************************************************************************
* Version: 3.18
* Author/Date: MengY/2024.07.16
* Change: Update the version number.
* Cause: Update
********************************************************************************
* Version: 3.19
* Author/Date: MengY/2024.10.11
* Change: 1.Modify the CRYIF_CODE to CSM_CODE for function.
*         2.Update the version number.
* Cause: Update
********************************************************************************
* Version: 3.20
* Author/Date: WangLX/2025.03.31
* Change: 1.Fix QAC and Polyspace warnings and add analysis results.
*         2.Updata Minor Version and Revision Version.
* Cause: Update
********************************************************************************
* Version: 3.21
* Author/Date: MengY/2025.06.26
* Change: Update the version number.
* Cause: Update
********************************************************************************
*/
#ifndef CSM_H_
#define CSM_H_

/*
********************************************************************************
* Includes
********************************************************************************
*/
#include "Csm_Cfg.h"
#include "Csm_Util.h"
#include "CryIf.h"

/*
*******************************************************************************
*    Global Macros
*******************************************************************************
*/
#define CSM_VENDOR_ID                               119U
#define CSM_MODULE_ID                               110U
#define CSM_INSTANCE_ID                             0U

#define CSM_AR_MAJOR_VERSION                        4U
#define CSM_AR_MINOR_VERSION                        4U
#define CSM_AR_PATCH_VERSION                        0U

#define CSM_SW_MAJOR_VERSION                        3U
#define CSM_SW_MINOR_VERSION                        14U
#define CSM_SW_PATCH_VERSION                        0U
#define CSM_SW_REVISION_VERSION                     10U



/* Development Errors */
#define CSM_E_NO_ERROR                              0x00U
#define CSM_E_PARAM_POINTER                         0x01U       /* API request called with invalid parameter (Nullpointer) */
#define CSM_E_SMALL_BUFFER                          0x03U       /* Buffer is too small for operation */
#define CSM_E_PARAM_HANDLE                          0x04U       /* keyID is out of range */
#define CSM_E_UNINIT                                0x05U       /* API request called before initialization of CSM module */
#define CSM_E_INIT_FAILED                           0x07U       /* Initialization of CSM module failed */
#define CSM_E_PROCESSING_MODE                       0x08U       /* API request called with invalid processing mode */

#define CSM_E_LENGTH_NOT_ZERO                       0x80U       /* Add for redirection function, add by reach. */
#define CSM_E_SERVICE_INVALID                       0x81U       /* Service is not matched with current function, add by reach. */

/* Runtime Errors */
#define CSM_E_QUEUE_FULL                            0x01U       /* Queue overrun */

/* Service Id */
#define CSM_SID_INIT                                0x00U
#define CSM_SID_GETVERSIONINFO                      0x3BU
#define CSM_SID_HASH                                0x5DU
#define CSM_SID_MACGENERATE                         0x60U
#define CSM_SID_MACVERIFY                           0x61U
#define CSM_SID_ENCRYPT                             0x5EU
#define CSM_SID_DECRYPT                             0x5FU
#define CSM_SID_AEADENCRYPT                         0x62U
#define CSM_SID_AEADDECRYPT                         0x63U
#define CSM_SID_SIGNATUREGENERATE                   0x76U
#define CSM_SID_SIGNATUREVERIFY                     0x64U
#define CSM_SID_RANDOMGENERATE                      0x72U
#define CSM_SID_KEYELEMENTSET                       0x78U
#define CSM_SID_KEYSETVALID                         0x67U
#define CSM_SID_KEYELEMENTGET                       0x68U
#define CSM_SID_KEYELEMENTCOPY                      0x71U
#define CSM_SID_KEYCOPY                             0x73U
#define CSM_SID_KEYELEMENTCOPYPARTIAL               0x79U
#define CSM_SID_RANDOMSEED                          0x69U
#define CSM_SID_KEYGENERATE                         0x6AU
#define CSM_SID_KEYDERIVE                           0x6BU
#define CSM_SID_KEYEXCHANGECALCPUBVAL               0x6CU
#define CSM_SID_KEYEXCHANGECALCSECRET               0x6DU
#define CSM_SID_CERTIFICATEPARSE                    0x6EU
#define CSM_SID_CERTIFICATEVERIFY                   0x74U
#define CSM_SID_JOBKEYSETVALID                      0x7AU
#define CSM_SID_JOBRANDOMSEED                       0x7BU
#define CSM_SID_JOBKEYGENERATE                      0x7CU
#define CSM_SID_JOBKEYDERIVE                        0x7DU
#define CSM_SID_JOBKEYEXCHANGECALCPUBVAL            0x7EU
#define CSM_SID_JOBKEYEXCHANGECALCSECRET            0x7FU
#define CSM_SID_JOBCERTIFICATEPARSE                 0x80U
#define CSM_SID_JOBCERTIFICATEVERIFY                0x81U
#define CSM_SID_CANCELJOB                           0x6FU
#define CSM_SID_CALLBACKNOTIFICATION                0x70U
#define CSM_SID_MAINFUNCTION                        0x01U

#define CSM_ZERO                                    0U
#define CSM_ONE                                     1U
#define CSM_SEVEN                                   7U
#define CSM_EIGHT                                   8U
#define CSM_INVALID_IDX_U8                          0xFFU
#define CSM_INVALID_IDX_U32                         0xFFFFFFFFU
/*
*******************************************************************************
*    Global Types
*******************************************************************************
*/
/*
*******************************************************************************
*    Global variable
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Constants
*******************************************************************************
*/
/*
*******************************************************************************
*    Global Functions
*******************************************************************************
*/
#define CSM_START_SEC_CODE
#include "Csm_MemMap.h"     /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#if( CSM_VERSION_INFO_API == STD_ON )
extern FUNC(void ,CSM_CODE) Csm_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CSM_APPL_DATA) versionInfo
);
#endif

extern FUNC(void ,CSM_CODE) Csm_Init
(
    P2CONST(Csm_ConfigType, AUTOMATIC, CSM_APPL_CONST) configPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_Hash
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_MacGenerate
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) macPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) macLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_MacVerify
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) macPtr,
    CONST(uint32, CSM_CONST) macLength,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_Encrypt
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_Decrypt
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_AEADEncrypt
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) plaintextPtr,
    uint32 plaintextLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) associatedDataPtr,
    uint32 associatedDataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) ciphertextPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) ciphertextLengthPtr,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) tagPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) tagLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_AEADDecrypt
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) ciphertextPtr,
    uint32 ciphertextLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) associatedDataPtr,
    uint32 associatedDataLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) tagPtr,
    uint32 tagLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) plaintextPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) plaintextLengthPtr,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_SignatureGenerate
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_SignatureVerify
(
    uint32 jobId,
    Crypto_OperationModeType mode,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) dataPtr,
    uint32 dataLength,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) signaturePtr,
    uint32 signatureLength,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_RandomGenerate
(
    uint32 jobId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) resultLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyElementSet
(
    uint32 keyId,
    uint32 keyElementId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) keyPtr,
    uint32 keyLength
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeySetValid
(
    uint32 keyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyElementGet
(
    uint32 keyId,
    uint32 keyElementId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) keyPtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) keyLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyElementCopy
(
    CONST(uint32, CSM_CONST) keyId,
    CONST(uint32, CSM_CONST) keyElementId,
    CONST(uint32, CSM_CONST) targetKeyId,
    CONST(uint32, CSM_CONST) targetKeyElementId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyCopy
(
    CONST(uint32, CSM_CONST) keyId,
    CONST(uint32, CSM_CONST) targetKeyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyElementCopyPartial
(
    uint32 keyId,
    uint32 keyElementId,
    uint32 keyElementSourceOffset,
    uint32 keyElementTargetOffset,
    uint32 keyElementCopyLength,
    uint32 targetKeyId,
    uint32 targetKeyElementId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_RandomSeed
(
    uint32 keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) seedPtr,
    uint32  seedLength
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyGenerate
(
    uint32 keyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyDerive
(
    uint32 keyId,
    uint32 targetKeyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyExchangeCalcPubVal
(
    uint32 keyId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) publicValueLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_KeyExchangeCalcSecret
(
    uint32 keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) partnerPublicValuePtr,
    uint32 partnerPublicValueLength
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_CertificateParse
(
    CONST(uint32, CSM_CONST) keyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_CertificateVerify
(
    CONST(uint32, CSM_CONST) keyId,
    CONST(uint32, CSM_CONST) verifyCryptoKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeySetValid
(
    uint32 jobId,
    uint32 keyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_JobRandomSeed
(
    uint32 jobId,
    uint32 keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) seedPtr,
    uint32  seedLength
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeyGenerate
(
    uint32 jobId,
    uint32 keyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeyDerive
(
    uint32 jobId,
    uint32 keyId,
    uint32 targetKeyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeyExchangeCalcPubVal
(
    uint32 jobId,
    uint32 keyId,
    P2VAR(uint8, AUTOMATIC, CSM_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CSM_APPL_DATA) publicValueLengthPtr
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_JobKeyExchangeCalcSecret
(
    uint32 jobId,
    uint32 keyId,
    P2CONST(uint8, AUTOMATIC, CSM_APPL_CONST) partnerPublicValuePtr,
    uint32 partnerPublicValueLength
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_JobCertificateParse
(
    uint32 jobId,
    uint32 keyId
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_JobCertificateVerify
(
    CONST(uint32, CSM_CONST) jobId,
    CONST(uint32, CSM_CONST) keyId,
    CONST(uint32, CSM_CONST) verifyKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CSM_APPL_DATA) verifyPtr
);
extern FUNC(void, CSM_CODE) Csm_CallbackNotification
(
    P2VAR(Crypto_JobType, AUTOMATIC, CSM_APPL_DATA) job,
    Csm_ResultType result
);
extern FUNC(Std_ReturnType ,CSM_CODE) Csm_CancelJob
(
    uint32 job,
    Crypto_OperationModeType mode
);
extern FUNC(void ,CSM_CODE) Csm_MainFunction(void);

#define CSM_STOP_SEC_CODE
#include "Csm_MemMap.h"     /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif
