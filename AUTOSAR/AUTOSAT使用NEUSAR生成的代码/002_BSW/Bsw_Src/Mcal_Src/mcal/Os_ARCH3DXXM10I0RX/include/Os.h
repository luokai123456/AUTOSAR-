/**************************************************************************** 
* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : OS
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
*   @file    os.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Os MCAL driver.
*
*   @addtogroup Os
*   @{
*/

#ifndef OS_H
#define OS_H


#ifdef __cplusplus
extern "C"
{
#endif


#include    "Os_version.h"    /**< OS version info */
#include    "Std_Types.h"     /**< Standard type header - from MCAL  */
#include    "Os_types_public.h"   /**< Autosar OS public types  */
#include    "Os_counter_api.h"

#ifdef MEM_MAP
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define OS_START_SEC_CONFIG_DATA           __attribute__ ((section (".mcal_os_rodata")))
#define OS_STOP_SEC_CONFIG_DATA
#define OS_START_SEC_CODE                  __attribute__ ((section (".mcal_os_text")))
#define OS_STOP_SEC_CODE
#define OS_START_SEC_VAR_NO_INIT           __attribute__ ((section (".mcal_os_bss")))
#define OS_STOP_SEC_VAR_NO_INIT
#define OS_START_SEC_VAR_INIT              __attribute__ ((section (".mcal_os_data")))
#define OS_STOP_SEC_VAR_INIT
#define OS_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_os_share")))
#define OS_STOP_SEC_VAR_SHARED_INIT
#define OS_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_os_bss_share")))
#define OS_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                          _Pragma(#x)
#define OS_START_SEC_CONFIG_DATA           PRAGMA(ghs section rodata=".mcal_os_rodata")
#define OS_STOP_SEC_CONFIG_DATA            PRAGMA(ghs section)
#define OS_START_SEC_CODE                  PRAGMA(ghs section text=".mcal_os_text")
#define OS_STOP_SEC_CODE                   PRAGMA(ghs section)
#define OS_START_SEC_VAR_NO_INIT           PRAGMA(ghs section bss=".mcal_os_bss")
#define OS_STOP_SEC_VAR_NO_INIT            PRAGMA(ghs section)
#define OS_START_SEC_VAR_INIT              PRAGMA(ghs section data = ".mcal_os_data")
#define OS_STOP_SEC_VAR_INIT               PRAGMA(ghs section)
#define OS_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".mcal_os_share")))
#define OS_STOP_SEC_VAR_SHARED_INIT
#define OS_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".mcal_os_bss_share")))
#define OS_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                          _Pragma(#x)
#define OS_START_SEC_CONFIG_DATA           PRAGMA(section ".mcal_os_rodata" a)
#define OS_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define OS_START_SEC_CODE                  PRAGMA(section ".mcal_os_text" avx)
#define OS_STOP_SEC_CODE                   PRAGMA(section)
#define OS_START_SEC_VAR_NO_INIT           PRAGMA(section ".mcal_os_bss")
#define OS_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define OS_START_SEC_VAR_INIT              PRAGMA(section ".mcal_os_data")
#define OS_STOP_SEC_VAR_INIT               PRAGMA(section)
#define OS_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".mcal_os_share")
#define OS_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define OS_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".mcal_os_bss_share")
#define OS_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#else
#include "CompilerDefinition.h"
#ifdef S32DS_C_CCFC30XX
#define OS_START_SEC_CONFIG_DATA
#define OS_STOP_SEC_CONFIG_DATA
#define OS_START_SEC_CODE
#define OS_STOP_SEC_CODE
#define OS_START_SEC_VAR_NO_INIT
#define OS_STOP_SEC_VAR_NO_INIT
#define OS_START_SEC_VAR_INIT
#define OS_STOP_SEC_VAR_INIT
#define OS_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define OS_STOP_SEC_VAR_SHARED_INIT
#define OS_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define OS_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* S32DS_C_CCFC30XX */
#ifdef GHS_C_CCFC30XX
#define PRAGMA(x)                          _Pragma(#x)
#define OS_START_SEC_CONFIG_DATA
#define OS_STOP_SEC_CONFIG_DATA
#define OS_START_SEC_CODE
#define OS_STOP_SEC_CODE
#define OS_START_SEC_VAR_NO_INIT
#define OS_STOP_SEC_VAR_NO_INIT
#define OS_START_SEC_VAR_INIT
#define OS_STOP_SEC_VAR_INIT
#define OS_START_SEC_VAR_SHARED_INIT       __attribute__ ((section (".data_share")))
#define OS_STOP_SEC_VAR_SHARED_INIT
#define OS_START_SEC_VAR_SHARED_NO_INIT    __attribute__ ((section (".bss_share")))
#define OS_STOP_SEC_VAR_SHARED_NO_INIT
#endif /* GHS_C_CCFC30XX */
#ifdef HITECH_C_CCFC30XX
#define PRAGMA(x)                          _Pragma(#x)
#define OS_START_SEC_CONFIG_DATA           PRAGMA(section ".rodata" a)
#define OS_STOP_SEC_CONFIG_DATA            PRAGMA(section)
#define OS_START_SEC_CODE                  PRAGMA(section ".text" avx)
#define OS_STOP_SEC_CODE                   PRAGMA(section)
#define OS_START_SEC_VAR_NO_INIT           PRAGMA(section ".bss")
#define OS_STOP_SEC_VAR_NO_INIT            PRAGMA(section)
#define OS_START_SEC_VAR_INIT              PRAGMA(section ".data")
#define OS_STOP_SEC_VAR_INIT               PRAGMA(section)
#define OS_START_SEC_VAR_SHARED_INIT       PRAGMA(section ".data_share")
#define OS_STOP_SEC_VAR_SHARED_INIT        PRAGMA(section)
#define OS_START_SEC_VAR_SHARED_NO_INIT    PRAGMA(section ".bss_share")
#define OS_STOP_SEC_VAR_SHARED_NO_INIT     PRAGMA(section)
#endif /* HITECH_C_CCFC30XX */
#endif /* MEM_MAP */



#ifdef __cplusplus
}
#endif



#endif /*OS_H*/

/** @} */

