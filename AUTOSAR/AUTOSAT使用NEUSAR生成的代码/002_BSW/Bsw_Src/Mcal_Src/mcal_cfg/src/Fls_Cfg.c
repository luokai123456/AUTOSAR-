
/* PRQA S 2053,0380,0305 EOF */ 
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
*   @file    Fls_Cfg.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif

#include "Fls_Cfg.h"

#define FLS_VENDOR_ID_PLUGIN_CFG_C          176
#define FLS_AR_REL_MAJOR_VER_CFG_C          4
#define FLS_AR_REL_MINOR_VER_CFG_C          4
#define FLS_AR_REL_REVISION_VER_CFG_C       0
#define FLS_SW_MAJOR_VERSION_CFG_C          3
#define FLS_SW_MINOR_VERSION_CFG_C          0
#define FLS_SW_PATCH_VERSION_CFG_C          0

#if (MCAL_VENDOR_ID != FLS_VENDOR_ID_PLUGIN_CFG_C)
    #error " NON-MATCHED DATA : FLS_VENDOR_ID_PLUGIN_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MAJOR_VERSION != FLS_AR_REL_MAJOR_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_MAJOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_MINOR_VERSION != FLS_AR_REL_MINOR_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_MINOR_VER_CFG_C "
#endif
#if (MCAL_AR_RELEASE_REVISION_VERSION != FLS_AR_REL_REVISION_VER_CFG_C)
    #error " NON-MATCHED DATA : FLS_AR_REL_REVISION_VER_CFG_C "
#endif
#if (MCAL_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_MAJOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_MINOR_VERSION_CFG_C "
#endif
#if (MCAL_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG_C)
    #error " NON-MATCHED DATA : FLS_SW_PATCH_VERSION_CFG_C "
#endif

extern FUNC( void, FLS_CODE ) Fee_JobEndNotification( void );
extern FUNC( void, FLS_CODE )Fee_JobErrorNotification( void );


#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(Fls_AddressType, FLS_VAR) gFls_JobAddrIt = 0UL;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(Fls_AddressType, FLS_VAR) gFls_JobAddrEnd = 0UL;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(volatile Fls_SectorIndex_Type, FLS_VAR) gFls_JobSectorIt = 0UL;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(Fls_SectorIndex_Type, FLS_VAR) gFls_JobSectorEnd = 0UL;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(uint8, FLS_VAR) gFls_JobStart = 0U;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(uint32, FLS_VAR) gFls_MaxRead = 0UL;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(uint32, FLS_VAR) gFls_MaxWrite = 0UL;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(MemIf_StatusType, FLS_VAR) gFls_ModuleStatus = MEMIF_UNINIT;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(MemIf_JobResultType, FLS_VAR) gFls_JobResult = MEMIF_JOB_OK;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(Fls_Job_Type, FLS_VAR) gFls_Job = FLS_JOB_ERASE;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(volatile MemIf_JobResultType, FLS_VAR) gFls_LLDJobResult = MEMIF_JOB_OK;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(Fls_LLDJob_Type, FLS_VAR) gFls_LLDJob = FLASH_JOB_NONE;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(uint8, FLS_VAR) gFls_JobTimeOutStart = 0U;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(Fls_SubJobStatusType, FLS_VAR) gFls_SubJobStatus = FLS_JOB_IDLE;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"


#define FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
static CONST(uint8, FLS_CONST) FlsConfig_FlsSectorFlags[56] =
{
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_0) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_1) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_2) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_3) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_4) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_5) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_6) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_7) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_8) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_9) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_10) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_11) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_12) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_13) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_14) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_15) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_16) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_17) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_18) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_19) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_20) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_21) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_22) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_23) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_24) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_25) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_26) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_27) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_28) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_29) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_30) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_31) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_32) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_33) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_34) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_35) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_36) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_37) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_38) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_39) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_40) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_41) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_42) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_43) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_44) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_45) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_46) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_47) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_48) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_49) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_50) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_51) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_52) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_53) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH, /* (FlsSector_54) */
    FLS_SECTOR_ERASE_ASYNCH |FLS_PAGE_WRITE_ASYNCH /* (FlsSector_55) */
};
#define FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
static CONST(uint16, FLS_CONST) FlsConfig_FlsSectorUnlock[56] =
{
    1U, /* (FlsSector_0) */
    1U, /* (FlsSector_1) */
    1U, /* (FlsSector_2) */
    1U, /* (FlsSector_3) */
    1U, /* (FlsSector_4) */
    1U, /* (FlsSector_5) */
    1U, /* (FlsSector_6) */
    1U, /* (FlsSector_7) */
    1U, /* (FlsSector_8) */
    1U, /* (FlsSector_9) */
    1U, /* (FlsSector_10) */
    1U, /* (FlsSector_11) */
    1U, /* (FlsSector_12) */
    1U, /* (FlsSector_13) */
    1U, /* (FlsSector_14) */
    1U, /* (FlsSector_15) */
    1U, /* (FlsSector_16) */
    1U, /* (FlsSector_17) */
    1U, /* (FlsSector_18) */
    1U, /* (FlsSector_19) */
    1U, /* (FlsSector_20) */
    1U, /* (FlsSector_21) */
    1U, /* (FlsSector_22) */
    1U, /* (FlsSector_23) */
    1U, /* (FlsSector_24) */
    1U, /* (FlsSector_25) */
    1U, /* (FlsSector_26) */
    1U, /* (FlsSector_27) */
    1U, /* (FlsSector_28) */
    1U, /* (FlsSector_29) */
    1U, /* (FlsSector_30) */
    1U, /* (FlsSector_31) */
    1U, /* (FlsSector_32) */
    1U, /* (FlsSector_33) */
    1U, /* (FlsSector_34) */
    1U, /* (FlsSector_35) */
    1U, /* (FlsSector_36) */
    1U, /* (FlsSector_37) */
    1U, /* (FlsSector_38) */
    1U, /* (FlsSector_39) */
    1U, /* (FlsSector_40) */
    1U, /* (FlsSector_41) */
    1U, /* (FlsSector_42) */
    1U, /* (FlsSector_43) */
    1U, /* (FlsSector_44) */
    1U, /* (FlsSector_45) */
    1U, /* (FlsSector_46) */
    1U, /* (FlsSector_47) */
    1U, /* (FlsSector_48) */
    1U, /* (FlsSector_49) */
    1U, /* (FlsSector_50) */
    1U, /* (FlsSector_51) */
    1U, /* (FlsSector_52) */
    1U, /* (FlsSector_53) */
    1U, /* (FlsSector_54) */
    1U, /* (FlsSector_55) */
};
#define FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
static CONST(Fls_AddressType, FLS_CONST) FlsConfig_FlsSectorEndAddr[56] =
{
    0x3fff, /* (FlsSector_0) */
    0x7fff, /* (FlsSector_1) */
    0xbfff, /* (FlsSector_2) */
    0xffff, /* (FlsSector_3) */
    0x17fff, /* (FlsSector_4) */
    0x1ffff, /* (FlsSector_5) */
    0x2ffff, /* (FlsSector_6) */
    0x3ffff, /* (FlsSector_7) */
    0x4ffff, /* (FlsSector_8) */
    0x5ffff, /* (FlsSector_9) */
    0x6ffff, /* (FlsSector_10) */
    0x7ffff, /* (FlsSector_11) */
    0x8ffff, /* (FlsSector_12) */
    0x9ffff, /* (FlsSector_13) */
    0xdffff, /* (FlsSector_14) */
    0x11ffff, /* (FlsSector_15) */
    0x15ffff, /* (FlsSector_16) */
    0x19ffff, /* (FlsSector_17) */
    0x1dffff, /* (FlsSector_18) */
    0x21ffff, /* (FlsSector_19) */
    0x25ffff, /* (FlsSector_20) */
    0x29ffff, /* (FlsSector_21) */
    0x2dffff, /* (FlsSector_22) */
    0x31ffff, /* (FlsSector_23) */
    0x35ffff, /* (FlsSector_24) */
    0x39ffff, /* (FlsSector_25) */
    0x3dffff, /* (FlsSector_26) */
    0x41ffff, /* (FlsSector_27) */
    0x45ffff, /* (FlsSector_28) */
    0x49ffff, /* (FlsSector_29) */
    0x4dffff, /* (FlsSector_30) */
    0x51ffff, /* (FlsSector_31) */
    0x55ffff, /* (FlsSector_32) */
    0x59ffff, /* (FlsSector_33) */
    0x5dffff, /* (FlsSector_34) */
    0x61ffff, /* (FlsSector_35) */
    0x65ffff, /* (FlsSector_36) */
    0x69ffff, /* (FlsSector_37) */
    0x6dffff, /* (FlsSector_38) */
    0x71ffff, /* (FlsSector_39) */
    0x75ffff, /* (FlsSector_40) */
    0x79ffff, /* (FlsSector_41) */
    0x7dffff, /* (FlsSector_42) */
    0x81ffff, /* (FlsSector_43) */
    0x85ffff, /* (FlsSector_44) */
    0x89ffff, /* (FlsSector_45) */
    0x8dffff, /* (FlsSector_46) */
    0x91ffff, /* (FlsSector_47) */
    0x95ffff, /* (FlsSector_48) */
    0x99ffff, /* (FlsSector_49) */
    0x9dffff, /* (FlsSector_50) */
    0xa1ffff, /* (FlsSector_51) */
    0xa5ffff, /* (FlsSector_52) */
    0xa9ffff, /* (FlsSector_53) */
    0xadffff, /* (FlsSector_54) */
    0xb1ffff, /* (FlsSector_55) */
};
#define FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
static CONST(Fls_AddressType, FLS_CONST) FlsConfig_FlsSectorStartAddr[56] = 
{
    0x0, /* (FlsSector_0) */
    0x4000, /* (FlsSector_1) */
    0x8000, /* (FlsSector_2) */
    0xc000, /* (FlsSector_3) */
    0x10000, /* (FlsSector_4) */
    0x18000, /* (FlsSector_5) */
    0x20000, /* (FlsSector_6) */
    0x30000, /* (FlsSector_7) */
    0x40000, /* (FlsSector_8) */
    0x50000, /* (FlsSector_9) */
    0x60000, /* (FlsSector_10) */
    0x70000, /* (FlsSector_11) */
    0x80000, /* (FlsSector_12) */
    0x90000, /* (FlsSector_13) */
    0xa0000, /* (FlsSector_14) */
    0xe0000, /* (FlsSector_15) */
    0x120000, /* (FlsSector_16) */
    0x160000, /* (FlsSector_17) */
    0x1a0000, /* (FlsSector_18) */
    0x1e0000, /* (FlsSector_19) */
    0x220000, /* (FlsSector_20) */
    0x260000, /* (FlsSector_21) */
    0x2a0000, /* (FlsSector_22) */
    0x2e0000, /* (FlsSector_23) */
    0x320000, /* (FlsSector_24) */
    0x360000, /* (FlsSector_25) */
    0x3a0000, /* (FlsSector_26) */
    0x3e0000, /* (FlsSector_27) */
    0x420000, /* (FlsSector_28) */
    0x460000, /* (FlsSector_29) */
    0x4a0000, /* (FlsSector_30) */
    0x4e0000, /* (FlsSector_31) */
    0x520000, /* (FlsSector_32) */
    0x560000, /* (FlsSector_33) */
    0x5a0000, /* (FlsSector_34) */
    0x5e0000, /* (FlsSector_35) */
    0x620000, /* (FlsSector_36) */
    0x660000, /* (FlsSector_37) */
    0x6a0000, /* (FlsSector_38) */
    0x6e0000, /* (FlsSector_39) */
    0x720000, /* (FlsSector_40) */
    0x760000, /* (FlsSector_41) */
    0x7a0000, /* (FlsSector_42) */
    0x7e0000, /* (FlsSector_43) */
    0x820000, /* (FlsSector_44) */
    0x860000, /* (FlsSector_45) */
    0x8a0000, /* (FlsSector_46) */
    0x8e0000, /* (FlsSector_47) */
    0x920000, /* (FlsSector_48) */
    0x960000, /* (FlsSector_49) */
    0x9a0000, /* (FlsSector_50) */
    0x9e0000, /* (FlsSector_51) */
    0xa20000, /* (FlsSector_52) */
    0xa60000, /* (FlsSector_53) */
    0xaa0000, /* (FlsSector_54) */
    0xae0000, /* (FlsSector_55) */
};
#define FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
static CONST(Fls_LengthType, FLS_CONST) FlsConfig_FlsPageSize[56] =
{
    8UL, /* (FlsSector_0) */
    8UL, /* (FlsSector_1) */
    8UL, /* (FlsSector_2) */
    8UL, /* (FlsSector_3) */
    8UL, /* (FlsSector_4) */
    8UL, /* (FlsSector_5) */
    8UL, /* (FlsSector_6) */
    8UL, /* (FlsSector_7) */
    8UL, /* (FlsSector_8) */
    8UL, /* (FlsSector_9) */
    8UL, /* (FlsSector_10) */
    8UL, /* (FlsSector_11) */
    8UL, /* (FlsSector_12) */
    8UL, /* (FlsSector_13) */
    8UL, /* (FlsSector_14) */
    8UL, /* (FlsSector_15) */
    8UL, /* (FlsSector_16) */
    8UL, /* (FlsSector_17) */
    8UL, /* (FlsSector_18) */
    8UL, /* (FlsSector_19) */
    8UL, /* (FlsSector_20) */
    8UL, /* (FlsSector_21) */
    8UL, /* (FlsSector_22) */
    8UL, /* (FlsSector_23) */
    8UL, /* (FlsSector_24) */
    8UL, /* (FlsSector_25) */
    8UL, /* (FlsSector_26) */
    8UL, /* (FlsSector_27) */
    8UL, /* (FlsSector_28) */
    8UL, /* (FlsSector_29) */
    8UL, /* (FlsSector_30) */
    8UL, /* (FlsSector_31) */
    8UL, /* (FlsSector_32) */
    8UL, /* (FlsSector_33) */
    8UL, /* (FlsSector_34) */
    8UL, /* (FlsSector_35) */
    8UL, /* (FlsSector_36) */
    8UL, /* (FlsSector_37) */
    8UL, /* (FlsSector_38) */
    8UL, /* (FlsSector_39) */
    8UL, /* (FlsSector_40) */
    8UL, /* (FlsSector_41) */
    8UL, /* (FlsSector_42) */
    8UL, /* (FlsSector_43) */
    8UL, /* (FlsSector_44) */
    8UL, /* (FlsSector_45) */
    8UL, /* (FlsSector_46) */
    8UL, /* (FlsSector_47) */
    8UL, /* (FlsSector_48) */
    8UL, /* (FlsSector_49) */
    8UL, /* (FlsSector_50) */
    8UL, /* (FlsSector_51) */
    8UL, /* (FlsSector_52) */
    8UL, /* (FlsSector_53) */
    8UL, /* (FlsSector_54) */
    8UL, /* (FlsSector_55) */
};
#define FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
static CONST(Fls_PhysicalSector_Type, FLS_CONST) FlsConfig_FlsPhysicalSector[56] =
{
    FLS_DATA_L1, /* (FlsSector_0) */
    FLS_DATA_L2, /* (FlsSector_1) */
    FLS_DATA_L3, /* (FlsSector_2) */
    FLS_DATA_L4, /* (FlsSector_3) */
    FLS_DATA_L6, /* (FlsSector_4) */
    FLS_DATA_L7, /* (FlsSector_5) */
    FLS_DATA_H0, /* (FlsSector_6) */
    FLS_DATA_H1, /* (FlsSector_7) */
    FLS_DATA_H2, /* (FlsSector_8) */
    FLS_DATA_H3, /* (FlsSector_9) */
    FLS_DATA_H4, /* (FlsSector_10) */
    FLS_DATA_H5, /* (FlsSector_11) */
    FLS_DATA_H6, /* (FlsSector_12) */
    FLS_DATA_H7, /* (FlsSector_13) */
    FLS_DATA_B0, /* (FlsSector_14) */
    FLS_DATA_B1, /* (FlsSector_15) */
    FLS_DATA_B2, /* (FlsSector_16) */
    FLS_DATA_B3, /* (FlsSector_17) */
    FLS_DATA_B4, /* (FlsSector_18) */
    FLS_DATA_B5, /* (FlsSector_19) */
    FLS_DATA_B6, /* (FlsSector_20) */
    FLS_DATA_B7, /* (FlsSector_21) */
    FLS_DATA_B8, /* (FlsSector_22) */
    FLS_DATA_B9, /* (FlsSector_23) */
    FLS_DATA_B10, /* (FlsSector_24) */
    FLS_DATA_B11, /* (FlsSector_25) */
    FLS_DATA_B12, /* (FlsSector_26) */
    FLS_DATA_B13, /* (FlsSector_27) */
    FLS_DATA_B14, /* (FlsSector_28) */
    FLS_DATA_B15, /* (FlsSector_29) */
    FLS_DATA_B16, /* (FlsSector_30) */
    FLS_DATA_B17, /* (FlsSector_31) */
    FLS_DATA_B18, /* (FlsSector_32) */
    FLS_DATA_B19, /* (FlsSector_33) */
    FLS_DATA_B20, /* (FlsSector_34) */
    FLS_DATA_B21, /* (FlsSector_35) */
    FLS_DATA_B22, /* (FlsSector_36) */
    FLS_DATA_B23, /* (FlsSector_37) */
    FLS_DATA_B24, /* (FlsSector_38) */
    FLS_DATA_B25, /* (FlsSector_39) */
    FLS_DATA_B26, /* (FlsSector_40) */
    FLS_DATA_B27, /* (FlsSector_41) */
    FLS_DATA_B28, /* (FlsSector_42) */
    FLS_DATA_B29, /* (FlsSector_43) */
    FLS_DATA_B30, /* (FlsSector_44) */
    FLS_DATA_B31, /* (FlsSector_45) */
    FLS_DATA_B32, /* (FlsSector_46) */
    FLS_DATA_B33, /* (FlsSector_47) */
    FLS_DATA_B34, /* (FlsSector_48) */
    FLS_DATA_B35, /* (FlsSector_49) */
    FLS_DATA_B36, /* (FlsSector_50) */
    FLS_DATA_B37, /* (FlsSector_51) */
    FLS_DATA_B38, /* (FlsSector_52) */
    FLS_DATA_B39, /* (FlsSector_53) */
    FLS_DATA_B40, /* (FlsSector_54) */
    FLS_DATA_B41, /* (FlsSector_55) */
};
#define FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"

void Fee_JobEndNotification(void){} //wjc
void Fee_JobErrorNotification(void){} //wjc

#define FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
CONST(Fls_ConfigType, FLS_CONST) Fls_Config = /* PRQA S 1756 EOF */
{
    (Fls_AcErasePtrType)1074396672,/* FlsAcErase */
    (Fls_AcWritePtrType)1074396672,/* FlsAcWrite */
    0.0,/* FlsCallCycle */
    MEMIF_MODE_SLOW,/* FlsDefaultMode */
    1048576U,/* FlsMaxReadFastMode */
    1024U,/* FlsMaxReadNormalMode */
    256U,/* FlsMaxWriteFastMode */
    64U,/* FlsMaxWriteNormalMode */
    &Fee_JobEndNotification,/* FlsEndNotification */
    &Fee_JobErrorNotification,/* FlsErrorNotification */
    56U,/* FlsSectorCount */
    &FlsConfig_FlsSectorStartAddr,/* FlsSectorStartAddr */
    &FlsConfig_FlsSectorEndAddr,/* FlsSectorEndAddr */
    &FlsConfig_FlsPhysicalSector,/* FlsPhysicalSector */
    &FlsConfig_FlsSectorFlags,/* FlsSectorFlags */
    &FlsConfig_FlsSectorUnlock,/* FlsSectorUnlock */
    &FlsConfig_FlsPageSize,/* FlsPageSize */
	NULL_PTR,
    NULL_PTR,

};
#define FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"



#ifdef __cplusplus
}
#endif
