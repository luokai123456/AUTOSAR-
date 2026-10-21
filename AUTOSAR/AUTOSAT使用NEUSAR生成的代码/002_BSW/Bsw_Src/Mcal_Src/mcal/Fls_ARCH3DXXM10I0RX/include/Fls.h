/**************************************************************************** 
* 

* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : 
*   Dependencies         : 
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : 
*   Autosar Conf.Variant :
*   SW Version           : 
*   Build Version        : 
*
*****************************************************************************/

/**
*   @file    Fls.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

#ifndef FLS_H
#define FLS_H 

#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Cfg.h"
#include "status.h"
#include "derivative.h"

#define FLS_MCR_DONE 0x00000400U
#define FLS_MCR_EHV  0x00000001U
#define FLS_MCR_OFT  0x0000U

#define FLS_H_VENDOR_ID_PLUGIN              176
#define FLS_AR_RELEASE_MAJOR_VERSION        4
#define FLS_AR_RELEASE_MINOR_VERSION        4
#define FLS_H_AR_REL_REV_VER                0
#define FLS_H_SW_MAJOR_VER                  3
#define FLS_H_SW_MINOR_VER                  0
#define FLS_H_SW_PATCH_VER                  0
#define FLS_MODULE_ID                       92

#if (FLS_VENDOR_ID_OUTPUT != FLS_H_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : FLS_H_VENDOR_ID_PLUGIN "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : FLS_AR_RELEASE_MAJOR_VERSION "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : FLS_AR_RELEASE_MINOR_VERSION "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_H_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_H_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_H_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_H_SW_PATCH_VER "
#endif

#if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
#ifndef RESOURCE_SUPPORT_PFI
typedef void (* fls_acload_t)(P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC);
#else
typedef void (* fls_acload_t)(P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC,volatile struct C55FMC_tag *fmc); /* PRQA S 3432 EOF */
#endif
#else
#ifndef RESOURCE_SUPPORT_PFI
typedef void (* fls_acload_t)(void);
#else
typedef void (* fls_acload_t)(volatile struct C55FMC_tag *fmc);
#endif
#endif


#define FLS_E_PARAM_CONFIG           0x01U
#define FLS_E_PARAM_ADDRESS          0x02U
#define FLS_E_PARAM_LENGTH           0x03U
#define FLS_E_PARAM_DATA             0x04U
#define FLS_E_UNINIT                 0x05U
#define FLS_E_BUSY                   0x06U
#define FLS_E_VERIFY_ERASE_FAILED    0x07U
#define FLS_E_VERIFY_WRITE_FAILED    0x08U
#define FLS_E_TIMEOUT                0x09U
#define FLS_E_PARAM_POINTER          0x0AU
#define FLS_E_BUSY_LOCK              0x80U


#define FLS_INIT_ID                  0x00U
#define FLS_ERASE_ID                 0x01U
#define FLS_WRITE_ID                 0x02U
#define FLS_CANCEL_ID                0x03U
#define FLS_GETSTATUS_ID             0x04U
#define FLS_GETJOBRESULT_ID          0x05U
#define FLS_MAINFUNCTION_ID          0x06U
#define FLS_READ_ID                  0x07U
#define FLS_COMPARE_ID               0x08U
#define FLS_SETMODE_ID               0x09U
#define FLS_GETVERSIONINFO_ID        0x10U
#define FLS_BLANK_CHECK_ID           0x0AU

#define FLS_E_ERASE_FAILED           0x01U
#define FLS_E_WRITE_FAILED           0x02U
#define FLS_E_READ_FAILED            0x03U
#define FLS_E_COMPARE_FAILED         0x04U
#define FLS_E_UNEXPECTED_FLASH_ID    0x05U
#define FLS_E_UNLOCK_FAILED          0x06U

#define FLS_CORE_NUM                 MCAL_CORE_NUM

extern P2VAR( uint8, FLS_VAR, FLS_APPL_DATA ) gFls_JobDataDestPtr;

extern VAR( fls_acload_t, AUTOMATIC) pFls_AcCodePtr;

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_Init \
( \
    P2CONST( Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST ) ConfigPtr \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/* Specification of Flash Driver : [SWS_Fls_00209] */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_Erase \
( \
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/* Specification of Flash Driver : [SWS_Fls_00209] */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_Write \
( \
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress, \
    P2CONST(uint8, AUTOMATIC, FLS_APPL_DATA) SourceAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/* Specification of Flash Driver : [SWS_Fls_00209] */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_Read \
( \
    VAR( Fls_AddressType, AUTOMATIC) SourceAddress, \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) TargetAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/* Specification of Flash Driver : [SWS_Fls_00185] */
#if ( FLS_GET_JOB_RESULT_API == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( MemIf_JobResultType, FLS_CODE ) Fls_GetJobResult( void );
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/* Specification of Flash Driver : [SWS_Fls_00187] */
#if( FLS_SET_MODE_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_SetMode
( VAR( MemIf_ModeType, FLS_CODE ) Mode );
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/* Specification of Flash Driver : [SWS_Fls_00183] */
#if (FLS_CANCEL_API == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_Cancel( void );
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#if( FLS_VERSION_INFO_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_GetVersionInfo
( P2VAR( Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA ) VersionInfoPtr );
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#if (FLS_BLANK_CHECK_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_BlankCheck
(
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress,
    VAR( Fls_LengthType, AUTOMATIC) Length
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#if( FLS_GET_STATUS_API == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( MemIf_StatusType, FLS_CODE ) Fls_GetStatus( void );
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#if( FLS_COMPARE_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_Compare \
( \
    VAR( Fls_AddressType, AUTOMATIC) SourceAddress, \
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) TargetAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_MainFunction( void );
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( uint32, FLS_CODE ) Fls_GetTimeOutCounter( void );
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_ClearTimeOutCounter( void );
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


#ifdef __cplusplus
}
#endif
#endif /* FLS_H */
