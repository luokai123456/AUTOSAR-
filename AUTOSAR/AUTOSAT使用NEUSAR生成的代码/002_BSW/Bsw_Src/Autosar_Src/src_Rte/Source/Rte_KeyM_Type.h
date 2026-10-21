/*
************************************************************************************************************************
*
* File name: Rte_KeyM_Type.h
*
* Copyright 2018-2025 Neusoft Reach Corporation. All rights reserved.
*
************************************************************************************************************************
*
* History
*-----------------------------------------------------------------------------------------------------------------------
************************************************************************************************************************
* Version: 1.0
* Author/Date : yong.zhang/2020.06.19
* Change: New created.
* Cause: New
************************************************************************************************************************
* Version: 4.0
* Author/Date: LanZG/2024.03.18
* Change: Upgrade template.
* Cause: Update
************************************************************************************************************************
* Version: 4.1
* Author/Date: ZhouSl/2024.12.19
* Change: Handling compilation warnings.
* Cause: Optimization
************************************************************************************************************************
*/
#ifndef RTE_KEYM_TYPE_H_
#define RTE_KEYM_TYPE_H_

/*
************************************************************************************************************************
*    Includes
************************************************************************************************************************
*/
#include "Std_Types.h"

/*
************************************************************************************************************************
*    Global Macros
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*    Global Types
************************************************************************************************************************
*/
/* [SWS_KeyM_00300] Certificate Element handle. */
#ifndef Rte_TypeDef_KeyM_CertElementIdType
#define Rte_TypeDef_KeyM_CertElementIdType
typedef uint16 KeyM_CertElementIdType;
#endif

/* [SWS_KeyM_00302] Crypto key handle. */
#ifndef Rte_TypeDef_KeyM_CertificateIdType
#define Rte_TypeDef_KeyM_CertificateIdType
typedef uint16 KeyM_CertificateIdType;
#endif

#ifndef Rte_TypeDef_KeyM_CryptoKeyDataType
#define Rte_TypeDef_KeyM_CryptoKeyDataType
typedef uint8* KeyM_CryptoKeyDataType;
#endif

/* [SWS_KeyM_91003] Enumeration of the result type of verification operations. */
#ifndef Rte_TypeDef_KeyM_CertificateStatusType
#define Rte_TypeDef_KeyM_CertificateStatusType
typedef uint8 KeyM_CertificateStatusType;
#endif

#ifndef KEYM_CERTIFICATE_VALID
#define KEYM_CERTIFICATE_VALID                      (0x00U)
#endif

#ifndef KEYM_CERTIFICATE_INVALID
#define KEYM_CERTIFICATE_INVALID                    (0x01U)
#endif

#ifndef KEYM_CERTIFICATE_NOT_PARSED
#define KEYM_CERTIFICATE_NOT_PARSED                 (0x02U)
#endif

#ifndef KEYM_CERTIFICATE_PARSED_NOT_VALIDATED
#define KEYM_CERTIFICATE_PARSED_NOT_VALIDATED       (0x03U)
#endif

#ifndef KEYM_CERTIFICATE_NOT_AVAILABLE
#define KEYM_CERTIFICATE_NOT_AVAILABLE              (0x04U)
#endif

#ifndef KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL
#define KEYM_E_CERTIFICATE_VALIDITY_PERIOD_FAIL     (0x05U)
#endif

#ifndef KEYM_E_CERTIFICATE_SIGNATURE_FAIL
#define KEYM_E_CERTIFICATE_SIGNATURE_FAIL           (0x06U)
#endif

#ifndef KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST
#define KEYM_E_CERTIFICATE_INVALID_CHAIN_OF_TRUST   (0x07U)
#endif

#ifndef KEYM_E_CERTIFICATE_INVALID_TYPE
#define KEYM_E_CERTIFICATE_INVALID_TYPE             (0x08U)
#endif

#ifndef KEYM_E_CERTIFICATE_INVALID_FORMAT
#define KEYM_E_CERTIFICATE_INVALID_FORMAT           (0x09U)
#endif

#ifndef KEYM_E_CERTIFICATE_INVALID_CONTENT
#define KEYM_E_CERTIFICATE_INVALID_CONTENT          (0x0AU)
#endif

#ifndef KEYM_E_CERTIFICATE_REVOKED
#define KEYM_E_CERTIFICATE_REVOKED                  (0x0BU)
#endif

#ifndef KEYM_CERTIFICATE_PARSED_IN_VALIDATING
#define KEYM_CERTIFICATE_PARSED_IN_VALIDATING       (0x0CU)
#endif

/* [SWS_KeyM_00038] This type specifies in which mode the key operation will start. The OEM production 
mode provides higher privileges compared to workshop mode. */
#ifndef Rte_TypeDef_KeyM_StartType
#define Rte_TypeDef_KeyM_StartType
typedef uint8 KeyM_StartType;
#endif

#ifndef KEYM_START_OEM_PRODUCTIONMODE
#define KEYM_START_OEM_PRODUCTIONMODE               (0x01U)
#endif

#ifndef KEYM_START_WORKSHOPMODE
#define KEYM_START_WORKSHOPMODE                     (0x02U)
#endif

/* [SWS_KeyM_00039] This type specifies the requested service operation and what information is provided with this function. */
#ifndef Rte_TypeDef_KeyM_ServiceCertificateType
#define Rte_TypeDef_KeyM_ServiceCertificateType
typedef uint8 KeyM_ServiceCertificateType;
#endif

#ifndef KEYM_SERVICE_CERT_REQUEST_CSR
#define KEYM_SERVICE_CERT_REQUEST_CSR               (0x01U)
#endif

#ifndef KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR
#define KEYM_SERVICE_CERT_UPDATE_SIGNED_CSR         (0x02U)
#endif

#ifndef KEYM_SERVICE_CERT_SET_ROOT
#define KEYM_SERVICE_CERT_SET_ROOT                  (0x03U)
#endif

#ifndef KEYM_SERVICE_CERT_UPDATE_ROOT
#define KEYM_SERVICE_CERT_UPDATE_ROOT               (0x04U)
#endif

#ifndef KEYM_SERVICE_CERT_SET_INTERMEDIATE
#define KEYM_SERVICE_CERT_SET_INTERMEDIATE          (0x05U)
#endif

#ifndef KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE
#define KEYM_SERVICE_CERT_UPDATE_INTERMEDIATE       (0x06U)
#endif

#ifndef KEYM_SERVICE_CERT_UPDATE_CRL
#define KEYM_SERVICE_CERT_UPDATE_CRL                (0x07U)
#endif

/* SWS_KeyM_91008 */
#ifndef Rte_TypeDef_KeyM_ResultType
#define Rte_TypeDef_KeyM_ResultType
typedef uint8 KeyM_ResultType;
#endif

#ifndef KEYM_RT_OK
#define KEYM_RT_OK                                  (0x00U)
#endif

#ifndef KEYM_RT_NOT_OK
#define KEYM_RT_NOT_OK                              (0x01U)
#endif

#ifndef KEYM_RT_KEY_CERT_INVALID
#define KEYM_RT_KEY_CERT_INVALID                    (0x02U)
#endif

#ifndef KEYM_RT_KEY_CERT_WRITE_FAIL
#define KEYM_RT_KEY_CERT_WRITE_FAIL                 (0x03U)
#endif

#ifndef KEYM_RT_KEY_CERT_UPDATE_FAIL
#define KEYM_RT_KEY_CERT_UPDATE_FAIL                (0x04U)
#endif

#ifndef KEYM_RT_CERT_INVALID_CHAIN_OF_TRUST
#define KEYM_RT_CERT_INVALID_CHAIN_OF_TRUST         (0x05U)
#endif

/*
************************************************************************************************************************
*    Global variables
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

#endif  /* RTE_KEYM_TYPE_H_ */


