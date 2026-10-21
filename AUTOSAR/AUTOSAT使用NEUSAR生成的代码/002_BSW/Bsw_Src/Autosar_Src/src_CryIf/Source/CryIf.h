/*
********************************************************************************
*
*  File name: CryIf.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
* Version: 3.0
* Author/Date: JiaF/2020.07.02
* Change: New created.
* Cause: New
********************************************************************************
* Version: 3.1
* Author/Date: GuoZY/2020.10.27
* Change: Modify the code according to the AUTOSAR specification.
* Cause: Optimization
********************************************************************************
* Version: 3.2
* Author/Date: JiaF/2020.11.10
* Change: Delete #include "Mcal.h".
* Cause: Optimization
********************************************************************************
* Version: 3.3
* Author/Date: ZhangY/2021.11.1
* Change: Change CRYIF_SW_PATCH_VERSION to 1.
* Cause: Update
********************************************************************************
* Version: 3.4
* Author/Date: ZhangY/2021.11.12
* Change: Change CRYIF_SW_PATCH_VERSION to 2.
* Cause: Update
********************************************************************************
* Version: 3.5
* Author/Date: NiXM/2022.12.21
* Change: Change CRYIF_SW_PATCH_VERSION to 3.
*         In function CryIf_GetObjectDriverIdx and CryIf_GetKeyObjectDriverIdx,
*         use CryptoChannelIdx and CryptoKeyIdx instead of ObjectDriverIdx.
* Cause: Update
********************************************************************************
*  Version: 3.6
*  Author/Date: NiXM/2023.02.03
*  Change: Update software version to 3.2.4 about the coding standards.
*  Cause: Optimization
********************************************************************************
*  Version: 3.7
*  Author/Date: NiXM/2023.05.24
*  Change: Update software version to 3.7.0 about the publishment of the edition.
*  Cause: Update
********************************************************************************
*  Version: 3.8
*  Author/Date: MengY/2023.08.03
*  Change: Remove compilation warnings.
*  Cause: Optimization
********************************************************************************
*  Version: 3.8
*  Author/Date: MengY/2023.08.25
*  Change: Modify patch version and revision version.
*  Cause: Optimization
********************************************************************************
*  Version: 3.9
*  Author/Date: MengY/2024.04.02
*  Change: Modify the version number.
*  Cause: Optimization
********************************************************************************
* Version: 3.10
* Author/Date: MengY/2024.05.08
* Change: 1.Add memmap section for function declaration.
*         2.Modify the version number.
* Cause: Update
********************************************************************************
* Version: 3.11
* Author/Date: MengY/2024.10.11
* Change: Modify the version number.
* Cause: Update
********************************************************************************
* Version: 3.12
* Author/Date: ZhangXL/2025.03.31
* Change: Fix QAC and Polyspace warnings and add analysis results.
* Cause: Update
********************************************************************************
* Version: 3.13
* Author/Date: LiSK/2025.07.15
* Change: Modify the version number.
* Cause: Update
********************************************************************************
*/
#ifndef CRYIF_H_
#define CRYIF_H_

/*
********************************************************************************
* Includes
********************************************************************************
*/
#include "Csm.h"
#include "CryIf_Cfg.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
#define CRYIF_VENDOR_ID                                 119U
#define CRYIF_MODULE_ID                                 112U
#define CRYIF_INSTANCE_ID                               0U

/* Component version information. */
#define CRYIF_SW_MAJOR_VERSION                          (3U)
#define CRYIF_SW_MINOR_VERSION                          (15U)
#define CRYIF_SW_PATCH_VERSION                          (0U)
#define CRYIF_SW_REVISION_VERSION                       (12U)

#define CRYIF_AR_RELEASE_MAJOR_VERSION                  (4U)
#define CRYIF_AR_RELEASE_MINOR_VERSION                  (4U)
#define CRYIF_AR_RELEASE_REVISION_VERSION               (0U)

/* Development Errors */
#define CRYIF_E_NO_ERROR                                0xFFU
#define CRYIF_E_UNINIT                                  0x00U
#define CRYIF_E_INIT_FAILED                             0x01U
#define CRYIF_E_PARAM_POINTER                           0x02U
#define CRYIF_E_PARAM_HANDLE                            0x03U
#define CRYIF_E_PARAM_VALUE                             0x04U
#define CRYIF_E_KEY_SIZE_MISMATCH                       0x05U

/* number value */
#define CRYIF_VALUE_ZERO                                0U
#ifndef CRYIF_VALUE_ONE
#define CRYIF_VALUE_ONE                                 1U
#endif
#define CRYIF_VALUE_TWO                                 2U
#define CRYIF_VALUE_0XFF                                0xFFU

/* Service IDs */
#define CRYIF_SID_INIT                                  0x00U
#define CRYIF_SID_GETVERSIONINFO                        0x01U
#define CRYIF_SID_PROCESSJOB                            0x03U
#define CRYIF_SID_CANCELJOB                             0x0EU
#define CRYIF_SID_KEYELEMENTSET                         0x04U
#define CRYIF_SID_KEYSETVALID                           0x05U
#define CRYIF_SID_KEYELEMENTGET                         0x06U
#define CRYIF_SID_KEYELEMENTCOPY                        0x0FU
#define CRYIF_SID_KEYELEMENTCOPYPARTIAL                 0x12U
#define CRYIF_SID_KEYCOPY                               0x10U
#define CRYIF_SID_RANDOMSEED                            0x07U
#define CRYIF_SID_KEYGENERATE                           0x08U
#define CRYIF_SID_KEYDERIVE                             0x09U
#define CRYIF_SID_KEYEXCHANGECALCPUBVAL                 0x0AU
#define CRYIF_SID_KEYEXCHANGECALCSECRET                 0x0BU
#define CRYIF_SID_CERTIFICATEPARSE                      0x0CU
#define CRYIF_SID_CERTIFICATEVERIFY                     0x11U
#define CRYIF_SID_CALLBACKNOTIFICATION                  0x0DU

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
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
#define CRYIF_START_SEC_CODE
//wjc:CryIf_MemMap.h /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */
extern FUNC(void, CRYIF_CODE) CryIf_Init
(
    P2CONST(CryIf_ConfigType, AUTOMATIC, CRYIF_APPL_CONST) configPtr
);
extern FUNC(void ,CRYIF_CODE) CryIf_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, CRYIF_APPL_DATA) versioninfo
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_ProcessJob
(
    uint32 channelId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_DATA) job
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_CancelJob
(
    uint32 channelId,
    P2VAR(Crypto_JobType, AUTOMATIC, CRYIF_APPL_DATA) job
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementSet
(
    uint32 cryIfKeyId,
    uint32 keyElementId,
    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) keyPtr,
    uint32 keyLength
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeySetValid
(
    uint32 cryIfKeyId
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementGet
(
    uint32 cryIfKeyId,
    uint32 keyElementId,
    P2VAR(uint8, AUTOMATIC, CRYIF_APPL_DATA) resultPtr,
    P2VAR(uint32, AUTOMATIC, CRYIF_APPL_DATA) resultLengthPtr
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementCopy
(
    uint32 cryIfKeyId,
    uint32 keyElementId,
    uint32 targetCryIfKeyId,
    uint32 targetKeyElementId
);

#if( CRYIF_KEY_ELEMENT_COPY_PARTIAL == STD_ON )
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyElementCopyPartial
(
    uint32 cryIfKeyId,
    uint32 keyElementId,
    uint32 keyElementSourceOffset,
    uint32 keyElementTargetOffset,
    uint32 keyElementCopyLength,
    uint32 targetCryIfKeyId,
    uint32 targetKeyElementId
);
#endif /* CRYIF_KEY_ELEMENT_COPY_PARTIAL == STD_ON */

extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyCopy
(
    uint32 cryIfKeyId,
    uint32 targetCryIfKeyId
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_RandomSeed
(
    uint32 cryIfKeyId,
    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) seedPtr,
    uint32 seedLength
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyGenerate
(
    uint32 cryIfKeyId
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyDerive
(
    uint32 cryIfKeyId,
    uint32 targetCryIfKeyId
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyExchangeCalcPubVal
(
    uint32 cryIfKeyId,
    P2VAR(uint8, AUTOMATIC, CRYIF_APPL_DATA) publicValuePtr,
    P2VAR(uint32, AUTOMATIC, CRYIF_APPL_DATA) publicValueLengthPtr
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_KeyExchangeCalcSecret
(
    uint32 cryIfKeyId,
    P2CONST(uint8, AUTOMATIC, CRYIF_APPL_CONST) partnerPublicValuePtr,
    uint32 partnerPublicValueLength
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_CertificateParse
(
    uint32 cryIfKeyId
);
extern FUNC(Std_ReturnType ,CRYIF_CODE) CryIf_CertificateVerify
(
    uint32 cryIfKeyId,
    uint32 verifyCryIfKeyId,
    P2VAR(Crypto_VerifyResultType, AUTOMATIC, CRYIF_APPL_DATA) verifyPtr
);
#define CRYIF_STOP_SEC_CODE
//wjc:CryIf_MemMap.h /* PRQA S 5087 */ /* NSCA_QAC_Common_MemMap */

#endif

