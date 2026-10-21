/*
********************************************************************************
*
*  File name: Csm_Types.h
*
*  Copyright 2020-2025 Neusoft Reach Corporation. All rights reserved.
*
********************************************************************************
*
*  History
*-------------------------------------------------------------------------------
********************************************************************************
*  Version: 1.0
*  Author/Date : JiaF/2020.03.03
*  Change: New
*  Cause: New
********************************************************************************
*  Version: 3.0
*  Author/Date : JiaF/2020.07.02
*  Change: Nothing
*  Cause: Update
********************************************************************************
*  Version: 3.1
*  Author/Date : ZhangY/2020.07.07
*  Change: Add macro CRYPTO_E_BUSY...CRYPTO_E_KEY_EMPTY.
*  Cause: Optimization
********************************************************************************
*  Version: 3.2
*  Author/Date : ZhangY/2022.01.05
*  Change: Csm module specific return values for use in Std_ReturnType.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.3
*  Author/Date : MengY/2023.08.03
*  Change: Remove compilation warnings.
*  Cause: Optimization
********************************************************************************
*  Version: 3.4
*  Author/Date : MengY/2023.11.22
*  Change: Remove header file.
*  Cause: Bugfix
********************************************************************************
*  Version: 3.5
*  Author/Date : MengY/2025.06.26
*  Change: Remove duplicate structure definitions with RTE.
*  Cause: Optimization
********************************************************************************
*/
#ifndef CSM_TYPES_H_
#define CSM_TYPES_H_

/*
********************************************************************************
* Includes
********************************************************************************
*/
#include "Std_Types.h"
#include "Rte_Csm_Type.h"

/*
********************************************************************************
*    Global Macros
********************************************************************************
*/
/* Csm module specific return values for use in Std_ReturnType. */
#ifndef CRYPTO_E_BUSY
#define CRYPTO_E_BUSY                       ((uint8)0x02U)
#endif
#define CRYPTO_E_SMALL_BUFFER               ((uint8)0x03U)
#define CRYPTO_E_ENTROPY_EXHAUSTION         ((uint8)0x04U)
#define CRYPTO_E_QUEUE_FULL                 ((uint8)0x05U)
#ifndef CRYPTO_E_KEY_READ_FAIL
#define CRYPTO_E_KEY_READ_FAIL              ((uint8)0x06U)
#endif
#ifndef CRYPTO_E_KEY_WRITE_FAIL
#define CRYPTO_E_KEY_WRITE_FAIL             ((uint8)0x07U)
#endif
#ifndef CRYPTO_E_KEY_NOT_AVAILABLE
#define CRYPTO_E_KEY_NOT_AVAILABLE          ((uint8)0x08U)
#endif
#ifndef CRYPTO_E_KEY_NOT_VALID
#define CRYPTO_E_KEY_NOT_VALID              ((uint8)0x09U)
#endif
#ifndef CRYPTO_E_KEY_SIZE_MISMATCH
#define CRYPTO_E_KEY_SIZE_MISMATCH          ((uint8)0x0AU)
#endif
#define CRYPTO_E_COUNTER_OVERFLOW           ((uint8)0x0BU)
#ifndef CRYPTO_E_JOB_CANCELED
#define CRYPTO_E_JOB_CANCELED               ((uint8)0x0CU)
#endif
#ifndef CRYPTO_E_KEY_EMPTY
#define CRYPTO_E_KEY_EMPTY                  ((uint8)0x0DU)
#endif
/* SWS_Csm_01022 key element Name */
#define CRYPTO_KE_MAC_KEY                           1U
#define CRYPTO_KE_MAC_PROOF                         2U
#define CRYPTO_KE_KEYGENERATE_SEED                  16U
#define CRYPTO_KE_SIGNATURE_KEY                     1U
#define CRYPTO_KE_RANDOM_SEED_STATE                 3U
#define CRYPTO_KE_RANDOM_ALGORITHM                  4U
#define CRYPTO_KE_CIPHER_KEY                        1U
#define CRYPTO_KE_CIPHER_IV                         5U
#define CRYPTO_KE_CIPHER_PROOF                      6U
#define CRYPTO_KE_CIPHER_2NDKEY                     7U
#define CRYPTO_KE_KEYEXCHANGE_BASE                  8U
#define CRYPTO_KE_KEYEXCHANGE_PRIVKEY               9U
#define CRYPTO_KE_KEYEXCHANGE_OWNPUBKEY             10U
#define CRYPTO_KE_KEYEXCHANGE_SHAREDVALUE           1U  
#define CRYPTO_KE_KEYEXCHANGE_ALGORITHM             12U
#define CRYPTO_KE_KEYDERIVATION_PASSWORD            1U
#define CRYPTO_KE_KEYDERIVATION_SALT                13U
#define CRYPTO_KE_KEYDERIVATION_ITERATIONS          14U
#define CRYPTO_KE_KEYDERIVATION_ALGORITHM           15U
#define CRYPTO_KE_KEYGENERATE_KEY                   1U
#define CRYPTO_KE_KEYGENERATE_SEED                  16U
#define CRYPTO_KE_KEYGENERATE_ALGORITHM             17U
#define CRYPTO_KE_CERTIFICATE_DATA                  0U
#define CRYPTO_KE_CERTIFICATE_PARSING_FORMAT        18U
#define CRYPTO_KE_CERTIFICATE_CURRENT_TIME          19U
#define CRYPTO_KE_CERTIFICATE_VERSION               20U
#define CRYPTO_KE_CERTIFICATE_SERIALNUMBER          21U
#define CRYPTO_KE_CERTIFICATE_SIGNATURE_ALGORITHM   22U
#define CRYPTO_KE_CERTIFICATE_ISSUER                23U
#define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_BEFORE   24U
#define CRYPTO_KE_CERTIFICATE_VALIDITY_NOT_AFTER    25U
#define CRYPTO_KE_CERTIFICATE_SUBJECT               26U
#define CRYPTO_KE_CERTIFICATE_SUBJECT_PUBLIC_KEY    1U
#define CRYPTO_KE_CERTIFICATE_EXTENSIONS            27U
#define CRYPTO_KE_CERTIFICATE_SIGNATURE             28U
#define CRYPTO_KE_KEYGENERATE_CURVETYPE             29U

/*
********************************************************************************
*    Global Types
********************************************************************************
*/
typedef enum
{
    CSM_JOB_STATE_IDLE = 0U,
    CSM_JOB_STATE_ACTIVE
} Csm_JobStateType;

typedef struct
{
    const uint8 ConfigNeverUsed;
} Csm_ConfigType;

/* Defines which of the input/output parameters are re-directed to a key element.
   The values can be combined to define a bit field.*/
typedef enum
{
    CRYPTO_REDIRECT_CONFIG_PRIMARY_INPUT = 0x01U,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_INPUT = 0x02U,
    CRYPTO_REDIRECT_CONFIG_TERTIARY_INPUT = 0x04U,
    CRYPTO_REDIRECT_CONFIG_PRIMARY_OUTPUT = 0x10U,
    CRYPTO_REDIRECT_CONFIG_SECONDARY_OUTPUT = 0x20U
} Crypto_InputOutputRedirectionConfigType;

#ifndef Csm_ConfigIdType
#define Csm_ConfigIdType  uint16
#endif
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

#endif

