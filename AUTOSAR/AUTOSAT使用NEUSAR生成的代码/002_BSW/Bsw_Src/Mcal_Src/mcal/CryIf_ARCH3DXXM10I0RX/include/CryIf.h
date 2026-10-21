/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : CryIf
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
*   @file    CryIf.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of CryIf MCAL driver.
*
*   @addtogroup Crypto
*   @{
*/

#ifndef CRYIF_H
#define CRYIF_H


#include "Csm.h"

/* The Crypto Stack API uses the following extension to Std_ReturnType */

#define CRYPTO_E_BUSY                   0x02U   /* The service request failed because the service is still busy */

#define CRYPTO_E_SMALL_BUFFER           0x03U   /* The service request failed because the provided buffer is too small to store the result */

#define CRYPTO_E_ENTROPY_EXHAUSTION     0x04U   /* The service request failed because the entropy of the random number generator is exhausted */

#define CRYPTO_E_QUEUE_FULL             0x05U   /* The service request failed because the queue is full */

#define CRYPTO_E_KEY_READ_FAIL          0x06U   /* The service request failed, because key element extraction is not allowed */

#define CRYPTO_E_KEY_WRITE_FAIL         0x07U   /* The service request failed because the writing access failed */

#define CRYPTO_E_KEY_NOT_AVAILABLE      0x08U   /* The service request failed because the key is not available */

#define CRYPTO_E_KEY_NOT_VALID          0x09U   /* The service request failed because the key is invalid */

#define CRYPTO_E_KEY_SIZE_MISMATCH      0x0AU   /* The service request failed because the key size does not match */

#define CRYPTO_E_JOB_CANCELED           0x0CU   /* The service request failed because the Job has been canceled */

#define CRYPTO_E_KEY_EMPTY              0x0DU   /* The service request failed because of uninitialized source key element */

#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define CRYIF_START_SEC_CONFIG_DATA           __attribute__((section(".mcal_cryif_rodata")))
#define CRYIF_STOP_SEC_CONFIG_DATA
#define CRYIF_START_SEC_CODE                  __attribute__((section(".mcal_cryif_text")))
#define CRYIF_STOP_SEC_CODE
#define CRYIF_START_SEC_VAR_NO_INIT           __attribute__((section(".mcal_cryif_bss")))
#define CRYIF_STOP_SEC_VAR_NO_INIT
#define CRYIF_START_SEC_VAR_INIT              __attribute__((section(".mcal_cryif_data")))
#define CRYIF_STOP_SEC_VAR_INIT
#define CRYIF_START_SEC_VAR_SHARED_INIT       __attribute__((section(".mcal_cryif_share")))
#define CRYIF_STOP_SEC_VAR_SHARED_INIT
#define CRYIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__((section(".mcal_cryif_bss_share")))
#define CRYIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define CRYIF_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_cryif_rodata")
#define CRYIF_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define CRYIF_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_cryif_text")
#define CRYIF_STOP_SEC_CODE                   PRAGMA(ghs section)
#define CRYIF_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_cryif_bss")
#define CRYIF_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define CRYIF_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_cryif_data")
#define CRYIF_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define CRYIF_START_SEC_VAR_SHARED_INIT       __attribute__((section(".mcal_cryif_share")))
#define CRYIF_STOP_SEC_VAR_SHARED_INIT
#define CRYIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__((section(".mcal_cryif_bss_share")))
#define CRYIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define CRYIF_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_cryif_rodata" a)
#define CRYIF_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define CRYIF_START_SEC_CODE                  PRAGMA(section ".mcal_cryif_text" avx)
#define CRYIF_STOP_SEC_CODE                   PRAGMA(section)
#define CRYIF_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_cryif_bss")
#define CRYIF_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define CRYIF_START_SEC_VAR_INIT              PRAGMA(section ".mcal_cryif_data")
#define CRYIF_STOP_SEC_VAR_INIT               PRAGMA(section)
#define CRYIF_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_cryif_share")
#define CRYIF_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define CRYIF_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_cryif_bss_share")
#define CRYIF_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define CRYIF_START_SEC_CONFIG_DATA
#define CRYIF_STOP_SEC_CONFIG_DATA
#define CRYIF_START_SEC_CODE
#define CRYIF_STOP_SEC_CODE
#define CRYIF_START_SEC_VAR_NO_INIT
#define CRYIF_STOP_SEC_VAR_NO_INIT
#define CRYIF_START_SEC_VAR_INIT
#define CRYIF_STOP_SEC_VAR_INIT
#define CRYIF_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define CRYIF_STOP_SEC_VAR_SHARED_INIT
#define CRYIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define CRYIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define CRYIF_START_SEC_CONFIG_DATA
#define CRYIF_STOP_SEC_CONFIG_DATA
#define CRYIF_START_SEC_CODE
#define CRYIF_STOP_SEC_CODE
#define CRYIF_START_SEC_VAR_NO_INIT
#define CRYIF_STOP_SEC_VAR_NO_INIT
#define CRYIF_START_SEC_VAR_INIT
#define CRYIF_STOP_SEC_VAR_INIT
#define CRYIF_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define CRYIF_STOP_SEC_VAR_SHARED_INIT
#define CRYIF_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define CRYIF_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                             _Pragma(#x)
#define CRYIF_START_SEC_CONFIG_DATA           PRAGMA(section ".rodata" a)
#define CRYIF_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define CRYIF_START_SEC_CODE                  PRAGMA(section ".text" avx)
#define CRYIF_STOP_SEC_CODE                   PRAGMA(section)
#define CRYIF_START_SEC_VAR_NO_INIT           PRAGMA(section ".bss")
#define CRYIF_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define CRYIF_START_SEC_VAR_INIT              PRAGMA(section ".data")
#define CRYIF_STOP_SEC_VAR_INIT               PRAGMA(section)
#define CRYIF_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".data_share")
#define CRYIF_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define CRYIF_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".bss_share")
#define CRYIF_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#endif /* MEM_MAP */

/*==============================================GLOBAL FUNCTIONS====================================*/
CRYIF_START_SEC_CODE
void CryIf_CallbackNotification ( const Crypto_JobType *job, Std_ReturnType result);
CRYIF_STOP_SEC_CODE

#endif /* CRYIF_H */

/** @} */
