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
*   @file    Fls_AutoSar_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

#ifndef FLS_AUTOSAR_WRAPPER_H
#define FLS_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Cfg.h"

#define FLS_ATC_WRA_H_VENDOR_ID                     176
#define FLS_ATC_WRA_H_AR_REL_MAJOR_VER              4
#define FLS_ATC_WRA_H_AR_REL_MINOR_VER              4
#define FLS_ATC_WRA_H_AR_REL_REV_VER                0
#define FLS_ATC_WRA_H_SW_MAJOR_VER                  3
#define FLS_ATC_WRA_H_SW_MINOR_VER                  0
#define FLS_ATC_WRA_H_SW_PATCH_VER                  0

#if (FLS_VENDOR_ID_OUTPUT != FLS_ATC_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : FLS_ATC_WRA_H_VENDOR_ID "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_ATC_WRA_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_ATC_WRA_H_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_ATC_WRA_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_ATC_WRA_H_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_ATC_WRA_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_ATC_WRA_H_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_ATC_WRA_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_ATC_WRA_H_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_ATC_WRA_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_ATC_WRA_H_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_ATC_WRA_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_ATC_WRA_H_SW_PATCH_VER "
#endif

extern P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) gFls_ConfigPtr;

extern P2VAR( uint8, FLS_VAR, FLS_APPL_DATA ) gFls_JobDataDestPtr;

extern P2CONST( uint8, FLS_VAR, FLS_APPL_CONST ) gFls_JobDataSrcPtr;

extern VAR( uint32, AUTOMATIC) gFLS_Ecc_Flag;

extern VAR( uint32, AUTOMATIC) gFLS_Ecc_Addr;

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
extern VAR(uint32, FLS_VAR) u32Fls_TimerCounterAC;
#endif

#define Fls_ReportTransientFault(ApiId, ErrorId) \
        (void)Det_ReportTransientFault( (uint16)FLS_MODULE_ID, FLS_INSTANCE, (ApiId), (ErrorId) );
extern FUNC(Fls_SectorIndex_Type, FLS_CODE) Fls_GetSectorIndexByAddr \
( \
    CONST (Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
);

extern FUNC( void, FLS_CODE ) Fls_ClrJobResult( void );

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
    extern FUNC( void, FLS_CODE ) Fls_UnloadAc
    ( CONST( Fls_Job_Type, AUTOMATIC) eFls_Job );

    extern FUNC( void, FLS_CODE ) Fls_LoadAc
    ( CONST( Fls_Job_Type, AUTOMATIC) eFls_Job );
#endif

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Ats_Wrapper_Init(void);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Ats_Wrapper_Erase \
( \
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Ats_Wrapper_Read \
( \
    VAR( Fls_AddressType, AUTOMATIC) SourceAddress, \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) TargetAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Ats_Wrapper_Write \
( \
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress, \
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) SourceAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Ats_Wrapper_SetMode \
( \
    VAR( MemIf_ModeType, FLS_CODE ) Mode \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE)Fls_Ats_Wrapper_Cancel(void);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE) Fls_Ats_Wrapper_Compare \
( \
    VAR( Fls_AddressType, AUTOMATIC) SourceAddress, \
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) TargetAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE ) Fls_Ats_Wrapper_BlankCheck \
( \
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(void, FLS_CODE)Fls_Ats_Wrapper_MainFunction(void);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
#endif /* FLS_AUTOSAR_WRAPPER_H */
