/* PRQA S 2053, 2843, 3432 EOF */
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
/* PRQA S 2913,2853,2834,1259,1863 EOF */  
/**
*   @file    Fls.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

/* PRQA S 2844 EOF */

#ifdef __cplusplus
extern "C"{
#endif

#include "Fls.h" /* PRQA S 0380 */
#include "Fls_AutoSar_Wrapper.h"
#include "Det.h"
#include "Fls_DflashLock_LLDriver.h"
#include "SchM_Fls.h"

#define FLS_C_VENDOR_ID_PLUGIN              176
#define FLS_C_AR_REL_MAJOR_VER				4
#define FLS_C_AR_REL_MINOR_VER			    4
#define FLS_C_AR_REL_REV_VER   		        0
#define FLS_C_SW_MAJOR_VER                  3
#define FLS_C_SW_MINOR_VER                  0
#define FLS_C_SW_PATCH_VER                  0

#if (FLS_VENDOR_ID_OUTPUT != FLS_C_VENDOR_ID_PLUGIN)
    #error " NON-MATCHED DATA : FLS_C_VENDOR_ID_PLUGIN "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_C_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_C_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_C_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_C_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_C_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_C_SW_PATCH_VER "
#endif

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_AC_UNLOAD_PATTERN 0xffffffffU
#endif

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR(uint32, FLS_VAR) u32Fls_TimerCounterAC = 0UL;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"
#endif

#ifndef RESOURCE_SUPPORT_PFI
#define FLASH_AC_CODE_MAX_SIZE         32U
#else
#define FLASH_AC_CODE_MAX_SIZE         128U
#endif

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) gFls_ConfigPtr = NULL_PTR;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
P2VAR( uint8, FLS_VAR, FLS_APPL_DATA ) gFls_JobDataDestPtr = NULL_PTR;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
P2CONST( uint8, FLS_VAR, FLS_APPL_CONST ) gFls_JobDataSrcPtr = NULL_PTR;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR( fls_acload_t, AUTOMATIC) pFls_AcCodePtr = NULL_PTR; /* PRQA S 3408 */
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR( uint32, AUTOMATIC) u32Fls_LockTimeOutCounter = 0U; /* PRQA S 3408 */
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
#ifndef RESOURCE_SUPPORT_PFI
extern FUNC( void, FLS_CODE ) FLS_AccessCode \
( \
    P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC \
);
#else
extern FUNC( void, FLS_CODE ) FLS_AccessCode
(
		P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC ,
		volatile struct C55FMC_tag *fmc
);
#endif 
#else
#ifndef RESOURCE_SUPPORT_PFI
extern FUNC( void, FLS_CODE ) FLS_AccessCode(void);
#else
extern  FUNC( void, FLS_CODE ) FLS_AccessCode(volatile struct C55FMC_tag *fmc);
#endif 
#endif /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */

#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define Fls_ReportError(ApiId, ErrorId) \
        (void)Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE, (ApiId), (ErrorId) );
#endif

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(Fls_SectorIndex_Type, FLS_CODE) Fls_GetSectorIndexByAddr \
(
    CONST (Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(boolean, FLS_CODE) Fls_IsAddrSectorStartAligned \
( \
    CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(boolean, FLS_CODE) Fls_IsAddrSectorEndAligned \
( \
    CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr \
( \
    CONST(Fls_SectorIndex_Type, AUTOMATIC) u32Fls_SectorIndex \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define Fls_ReportTransientFault(ApiId, ErrorId) \
        (void)Det_ReportTransientFault( (uint16)FLS_MODULE_ID, FLS_INSTANCE, (ApiId), (ErrorId) );

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
/*****************************************************************************
** Service Name      : Fls_LoadAc                                              
** 
** 
**  Description      : Load the access code for erasing or writing into the 
**                     static pre-configured location in RAM.                        
**                                                                            
**  Parameters (in)  : eFls_Job: The type of access code to load. 
**                     The type can be FLS_JOB_ERASE or FLS_JOB_WRITE.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_LoadAc \
( \
    CONST( Fls_Job_Type, AUTOMATIC) eFls_Job \
)
{
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_RomPtr = NULL_PTR;
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_RomEndPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_RamPtr = NULL_PTR;

    if(eFls_Job == FLS_JOB_WRITE)
    {
        pFls_RomPtr = (uint32 *)&FLS_AccessCode;
        pFls_RomEndPtr = pFls_RomPtr + (uint32)(FLASH_AC_CODE_MAX_SIZE);
        pFls_RamPtr = (uint32*)(gFls_ConfigPtr->acWritePtr);
#if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
        u32Fls_TimerCounterAC = FLS_SYNC_WRITE_TIMEOUT_VALUE;
#endif 
    }
    else if(eFls_Job == FLS_JOB_ERASE)
    {
        pFls_RomPtr = (uint32 *)&FLS_AccessCode;;
        pFls_RomEndPtr = pFls_RomPtr + (uint32)(FLASH_AC_CODE_MAX_SIZE);
        pFls_RamPtr = (uint32*)(gFls_ConfigPtr->acErasePtr);
#if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
        u32Fls_TimerCounterAC = FLS_SYNC_ERASE_TIMEOUT_VALUE;
#endif 
    }
    else
    {
        /* Do nothing */
    }

    pFls_AcCodePtr = (fls_acload_t)pFls_RamPtr;
    for(; (uint32)pFls_RomPtr < (uint32)pFls_RomEndPtr; pFls_RomPtr++)
    {
        *pFls_RamPtr = *pFls_RomPtr;
        pFls_RamPtr++;
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_UnloadAc                                              
** 
** 
**  Description      : Used to erase write or erase access codes from static 
**                     pre-configured locations in RAM. And fills the 
**                     corresponding RAM location with FLS_AC_UNLOAD_PATTERN.                        
**                                                                            
**  Parameters (in)  : eFls_Job: The type of access code to unload. 
**                     The type can be FLS_JOB_ERASE or FLS_JOB_WRITE.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_UnloadAc \
( \
    CONST( Fls_Job_Type, AUTOMATIC) eFls_Job \
)
{
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_RamPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_RamEndPtr = NULL_PTR;
    
    if( eFls_Job ==  FLS_JOB_WRITE) 
    {
        pFls_RamPtr = (uint32*)(gFls_ConfigPtr->acWritePtr);
        pFls_RamEndPtr = pFls_RamPtr + (uint32)(FLASH_AC_CODE_MAX_SIZE);
    }
    else if(eFls_Job == FLS_JOB_ERASE)
    {
        pFls_RamPtr = (uint32*)(gFls_ConfigPtr->acErasePtr);
        pFls_RamEndPtr = pFls_RamPtr + (uint32)(FLASH_AC_CODE_MAX_SIZE);
    }
    else
    {
        /* Do nothing */
    }

    for(; (uint32)pFls_RamPtr < (uint32)pFls_RamEndPtr; pFls_RamPtr++)
    {
        *pFls_RamPtr = FLS_AC_UNLOAD_PATTERN;
    }    
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif /* FLS_AC_LOAD_ON_JOB_START */

/*****************************************************************************
** Service Name      : Fls_GetSectorIndexByAddr                                              
** 
** 
**  Description      : Used to calculate the index of the logical sector to
**                     which TargetAddress belongs.                         
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Fls_SectorIndex_Type: Logical sector index.                                                   
**                                                                            
******************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(Fls_SectorIndex_Type, FLS_CODE) Fls_GetSectorIndexByAddr \
( \
    CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
)
{
    VAR( Fls_SectorIndex_Type, AUTOMATIC ) u32Fls_SectorIndex = 0UL;

    /*Within the sector count range*/
    while (u32Fls_SectorIndex < gFls_ConfigPtr->u32SectorCount)
    {
        if( u32Fls_TargetAddress > (*(gFls_ConfigPtr->paSectorEndAddr))[u32Fls_SectorIndex] )  /*polyspace RTE:OBAI,IDP,NIV*/
        {
            
        }
        else
        {
            break;
        }
        u32Fls_SectorIndex++;
    }

    return u32Fls_SectorIndex;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_IsAddrSectorStartAligned                                              
** 
** 
**  Description      : Used to check whether u32Fls_TargetAddress is in range 
**                     and aligned with the first byte of the flash sector.                         
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : boolean: TRUE u32Fls_TargetAddress is in the range, 
**                                   and it is aligned with the beginning of the sector.
**                              FLASE u32Fls_TargetAddress is not in the range, 
**                                    and it is not aligned with the beginning of the sector.                                                   
**                                                                            
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(boolean, FLS_CODE) Fls_IsAddrSectorStartAligned \
( \
    CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
)
{
    VAR( boolean, AUTOMATIC ) bFls_RetVal = (boolean)FALSE;

    if(( u32Fls_TargetAddress < FLS_TOTAL_SIZE ) /*polyspace RTE:OBAI,IDP,NIV*/
         && ( u32Fls_TargetAddress \
         == Fls_GetSectorStartAddr \
         ( Fls_GetSectorIndexByAddr ( u32Fls_TargetAddress ))))
    {
        bFls_RetVal = (boolean)TRUE;
    }
    return bFls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_GetSectorStartAddr                                              
** 
** 
**  Description      : Used to calculate the starting address of logical sector.                         
**                                                                            
**  Parameters (in)  : u32Fls_SectorIndex: The logical sector index                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Fls_AddressType: Used as address offset from the configured 
**                     flash base address to access a certain flash memory area.                                                   
**                                                                            
******************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr \
( \
    CONST(Fls_SectorIndex_Type, AUTOMATIC) u32Fls_SectorIndex \
)
{
    VAR( Fls_AddressType, AUTOMATIC ) u32Fls_TargetAddress = 0U;

    /*Confirm sector start address*/
    if( 0U == u32Fls_SectorIndex ) 
    {
        /*first sector address 0*/
    }
    else
    {
        u32Fls_TargetAddress = (*(gFls_ConfigPtr->paSectorEndAddr))[u32Fls_SectorIndex - 1U] + 1U; /*polyspace RTE:IDP,OBAI,NIV*/
    }

    return u32Fls_TargetAddress;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_IsAddrSectorEndAligned                                              
** 
** 
**  Description      : Used to check whether u32Fls_TargetAddress is in
**                     range and aligned with the last byte of the flash sector.                        
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : boolean: TRUE U32Fls_TargetAddress is in the range, 
**                                   and it is aligned with the ending of the sector.
**                              FLASE U32Fls_TargetAddress is not in the range, 
**                                    and it is not aligned with the ending of the sector.                                                   
**                                                                            
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(boolean, FLS_CODE) Fls_IsAddrSectorEndAligned \
( \
    CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
)
{
    VAR( boolean, AUTOMATIC ) bFls_RetVal = (boolean)FALSE;
    VAR( Fls_SectorIndex_Type, AUTOMATIC ) u32Fls_SectorIndex = 0UL;

    /*Sector index number obtained from target address*/
    u32Fls_SectorIndex = Fls_GetSectorIndexByAddr( u32Fls_TargetAddress );
    if(( u32Fls_TargetAddress < FLS_TOTAL_SIZE ) /*polyspace RTE:OBAI,IDP,NIV*/
        && ( u32Fls_TargetAddress == (*(gFls_ConfigPtr->paSectorEndAddr))[u32Fls_SectorIndex] )) /*polyspace RTE:IDP,OBAI,NIV*/
    {
        bFls_RetVal =  (boolean)TRUE;
    }

    return bFls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_IsAddrPageAligned                                              
** 
** 
**  Description      : Used to check whether the destination address is an 
**                     integer multiple of the page u32Fls_Size.                         
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : boolean: TRUE It is page aligned.
**                              FLASE It is not page aligned.                                                   
**                                                                            
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(boolean, FLS_CODE) Fls_IsAddrPageAligned \
( \
    CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
)
{
    VAR( boolean, AUTOMATIC ) bFls_RetVal = (boolean)FALSE;
    VAR( uint32, AUTOMATIC ) u32Fls_IndexValue = 0UL;

    /*Get the index number of the sector where the target address is located.*/
    u32Fls_IndexValue = Fls_GetSectorIndexByAddr(u32Fls_TargetAddress);
    if(0U == (u32Fls_TargetAddress % (*(gFls_ConfigPtr->paSectorPageSize))[u32Fls_IndexValue]))  /*polyspace RTE:ZDV,IDP,OBAI,NIV*/
    {
        bFls_RetVal = (boolean)TRUE;
    }

    return( bFls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_IsAddrPageEndAligned                                              
** 
** 
**  Description      : Used to check whether the end address calculated based 
**                     on u32Fls_TargetAddress is in the range.                        
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : boolean: TRUE U32Fls_TargetAddress is in the range, and 
**                              it is aligned with the ending of the page.
**                              FLASE U32Fls_TargetAddress is not in the range, and 
**                                    it is not aligned with the ending of the page.                                                   
**                                                                            
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(boolean, FLS_CODE) Fls_IsAddrPageEndAligned \
( \
    CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
)
{
    VAR( boolean, AUTOMATIC ) bFls_RetVal = (boolean)FALSE;
    VAR(Fls_LengthType, AUTOMATIC) u32Fls_SectorOffset = 0UL;

    /*Sector index number obtained from target address*/
    u32Fls_SectorOffset = u32Fls_TargetAddress \
                          - Fls_GetSectorStartAddr \
                          (Fls_GetSectorIndexByAddr(u32Fls_TargetAddress));
        
    if(((u32Fls_TargetAddress - 1U) < (Fls_AddressType)FLS_TOTAL_SIZE )  /*polyspace RTE:OBAI,IDP,NIV*/
        && (0U == (u32Fls_SectorOffset % (Fls_LengthType)8)))
    {
        bFls_RetVal = (boolean)TRUE;
    }
    else
    {
        
    }

    return( bFls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(boolean, FLS_CODE) Fls_Islock \
( \
    CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress \
)
{
    VAR( boolean, AUTOMATIC ) bFls_RetVal = (boolean)TRUE;
    VAR(uint32, AUTOMATIC) u32Fls_index = 0UL;

    /*Sector index number obtained from target address*/
    u32Fls_index = (Fls_GetSectorIndexByAddr(u32Fls_TargetAddress));
    
    if((*(gFls_ConfigPtr->sectorUnlock))[u32Fls_index] == 0) /*polyspace RTE:IDP,OBAI,NIV*/
    {
        bFls_RetVal = (boolean)FALSE;
    }
    else
    {
        
    }

    return( bFls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_IsAddrPageStartAligned                                              
** 
** 
**  Description      : Used to check whether U32Fls_TargetAddress is in 
**                     range and aligned with the first byte of the flash page.                        
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : boolean: TRUE U32Fls_TargetAddress is in the range, and 
**                              it is aligned with the beginning of the page.
**                              FLASE U32Fls_TargetAddress is not in the range, and 
**                                    it is not aligned with the beginning of the page.                                                   
**                                                                            
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC(boolean, FLS_CODE) Fls_IsAddrPageStartAligned
( CONST(Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress )
{
    VAR( boolean, AUTOMATIC ) bFls_RetVal = (boolean)FALSE;

    if(( u32Fls_TargetAddress < (Fls_AddressType)FLS_TOTAL_SIZE ) &&  /*polyspace RTE:OBAI,IDP,NIV*/
        ( (boolean)TRUE == Fls_IsAddrPageAligned( u32Fls_TargetAddress ) ) )
    {
        bFls_RetVal = (boolean)TRUE;
    }
    else
    {
        
    }

    return( bFls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_ClrJobResult                                              
** 
** 
**  Description      : Used to clear the state of erasing or writing 
**                     hardware job results.                        
**                                                                            
**  Parameters (in)  : None                              
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_ClrJobResult( void )
{
	gFls_LLDJobResult = MEMIF_JOB_OK;
	gFls_LLDJob = FLASH_JOB_NONE;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_InitVerify                                              
** 
** 
**  Description      : Development error verification of Fls_Init interface.                       
**                                                                            
**  Parameters (in)  : stFls_ConfigPtr: Pointer to flash driver configuration set.                             
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
 #if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_InitVerify \
( \
    P2CONST( Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST ) stFls_ConfigPtr \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_VerifyRetVal = E_NOT_OK;
    /* Specification of Flash Driver : [SWS_Fls_00015] */
#if (FLS_PRECOMPILE_SUPPORT == STD_ON)
    if(NULL_PTR != stFls_ConfigPtr)
#else 
    if (NULL_PTR == stFls_ConfigPtr)
#endif
    {
       
        Fls_ReportError(FLS_INIT_ID, FLS_E_PARAM_CONFIG);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( MEMIF_BUSY == gFls_ModuleStatus )
    {
        /* Specification of Flash Driver : [SWS_Fls_00312] */
        Fls_ReportError(FLS_INIT_ID, FLS_E_BUSY);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    } 
    else
    {
        u8Fls_VerifyRetVal = E_OK;
    }

    return u8Fls_VerifyRetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_EraseVerify                                              
** 
** 
**  Description      : Development error verification of Fls_Erase interface.                       
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.This 
**                                              address offset will be added to the 
**                                              flash memory base address. 
**                                              Min.: 0 
**                                              Max.: FLS_SIZE - 1  
**                     u32Fls_Length: Number of bytes to erase 
**                                       Min.: 1 
**                                       Max.: FLS_SIZE - TargetAddress                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_EraseVerify \
( \
    VAR( Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress, \
    VAR( Fls_LengthType, AUTOMATIC) u32Fls_Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;
    /* Specification of Flash Driver : [SWS_Fls_00065] */
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        
        Fls_ReportError(FLS_ERASE_ID, FLS_E_UNINIT);
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00020] */
    else if( (boolean)FALSE == (Fls_IsAddrSectorStartAligned \
                               ( (Fls_AddressType)u32Fls_TargetAddress )) )
    {
        Fls_ReportError(FLS_ERASE_ID, FLS_E_PARAM_ADDRESS);
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00021] */
    else if((0U == u32Fls_Length ) || ( (boolean)FALSE \
             == (Fls_IsAddrSectorEndAligned \
             (( (Fls_AddressType)u32Fls_TargetAddress + u32Fls_Length ) - 1U ))))
    {
        Fls_ReportError(FLS_ERASE_ID, FLS_E_PARAM_LENGTH);
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00023] */
    else if( MEMIF_BUSY == gFls_ModuleStatus )
    {
        /* Specification of Flash Driver : [SWS_Fls_00312] */
        Fls_ReportError(FLS_ERASE_ID, FLS_E_BUSY);
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /*Check if it's locked*/
    else if(Fls_Islock(u32Fls_TargetAddress) == (boolean)FALSE)
    {
        Fls_ReportTransientFault( FLS_ERASE_ID, FLS_E_UNLOCK_FAILED );
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_RetVal = (Std_ReturnType)E_OK;
    }

    return u8Fls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
 #endif


/*****************************************************************************
** Service Name      : Fls_ReadVerify                                              
** 
** 
**  Description      : Development error verification of Fls_Read interface.                       
**                                                                            
**  Parameters (in)  : u8Fls_SourceAddress: Source address in flash memory. This 
**                                             address offset will be added to the 
**                                             flash memory base address. 
**                                             Min.: 0 
**                                             Max.: FLS_SIZE - 1
**                     u32Fls_Length: Number of bytes to read 
**                                       Min.: 1 
**                                       Max.: FLS_SIZE - TargetAddress                           
**                                                                            
**  Parameters (out) : u8Fls_TargetAddressPtr: Pointer to target data buffer                                                    
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_ReadVerify \
( \
    VAR( Fls_AddressType, AUTOMATIC) u32Fls_SourceAddress, \
    P2CONST( uint8, AUTOMATIC, FLS_APPL_DATA ) u8Fls_TargetAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) u32Fls_Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    /* Specification of Flash Driver : [SWS_Fls_00099] */
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        
        Fls_ReportError(FLS_READ_ID, FLS_E_UNINIT);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00097] */
    else if( u32Fls_SourceAddress >= FLS_TOTAL_SIZE )   /*polyspace RTE:OBAI,IDP,NIV*/
    {
        Fls_ReportError(FLS_READ_ID, FLS_E_PARAM_ADDRESS);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00098] */
    else if(( 0U == u32Fls_Length ) || ((u32Fls_SourceAddress + u32Fls_Length) > FLS_TOTAL_SIZE ))  /*polyspace RTE:OBAI,IDP*/
    {
        Fls_ReportError(FLS_READ_ID, FLS_E_PARAM_LENGTH);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00158] */
    else if( NULL_PTR == u8Fls_TargetAddressPtr )
    {
        Fls_ReportError(FLS_READ_ID, FLS_E_PARAM_DATA);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00100] */
    else if( MEMIF_BUSY == gFls_ModuleStatus )
    {
        /* Specification of Flash Driver : [SWS_Fls_00312] */
        Fls_ReportError(FLS_READ_ID, FLS_E_BUSY);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_VerifyRetVal = (Std_ReturnType)E_OK;
    }

    return u8Fls_VerifyRetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_WriteVerify                                              
** 
** 
**  Description      : Development error verification of Fls_Write interface.                       
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.This 
**                                              address offset will be added to the 
**                                              flash memory base address. 
**                                              Min.: 0 
**                                              Max.: FLS_SIZE - 1  
**                     u8Fls_SourceAddressPtr: Pointer to source data buffer
**                     u32Fls_Length: Number of bytes to write 
**                                       Min.: 1 
**                                       Max.: FLS_SIZE - TargetAddress                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_WriteVerify \
( \
    VAR( Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress, \
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) u8Fls_SourceAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) u32Fls_Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;

    /* Specification of Flash Driver : [SWS_Fls_00066] */
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        
        Fls_ReportError(FLS_WRITE_ID, FLS_E_UNINIT);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00026] */
    else if( (boolean)FALSE == (Fls_IsAddrPageStartAligned \
           ( (Fls_AddressType)u32Fls_TargetAddress )))
    {
        Fls_ReportError(FLS_WRITE_ID, FLS_E_PARAM_ADDRESS);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00027] */
    else if((0U == u32Fls_Length ) || ( (boolean)FALSE == \
            (Fls_IsAddrPageEndAligned( u32Fls_TargetAddress +  u32Fls_Length ))))
    {
        Fls_ReportError(FLS_WRITE_ID, FLS_E_PARAM_LENGTH);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00157] */
    else if( NULL_PTR == u8Fls_SourceAddressPtr )
    {
        Fls_ReportError(FLS_WRITE_ID, FLS_E_PARAM_DATA);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00030] */
    else if( MEMIF_BUSY == gFls_ModuleStatus)
    {
        /* Specification of Flash Driver : [SWS_Fls_00312] */
        Fls_ReportError(FLS_WRITE_ID, FLS_E_BUSY);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /*Check if it's locked*/
    else if(Fls_Islock(u32Fls_TargetAddress) == (boolean)FALSE)
    {
        Fls_ReportTransientFault( FLS_WRITE_ID, FLS_E_UNLOCK_FAILED );
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_VerifyRetVal = (Std_ReturnType)E_OK;
    }
    
    return u8Fls_VerifyRetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
 #endif

/*****************************************************************************
** Service Name      : Fls_SetModeVerify                                              
** 
** 
**  Description      : Development error verification of Fls_SetMode interface.                       
**                                                                            
**  Parameters (in)  : None                         
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#if( FLS_SET_MODE_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_SetModeVerify(void)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        Fls_ReportError(FLS_SETMODE_ID, FLS_E_UNINIT);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00156] */
    else if( MEMIF_BUSY == gFls_ModuleStatus )
    {
        /* Specification of Flash Driver : [SWS_Fls_00312] */
        Fls_ReportError(FLS_SETMODE_ID, FLS_E_BUSY);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_VerifyRetVal = (Std_ReturnType)E_OK;
    }
    return u8Fls_VerifyRetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif
#endif

/*****************************************************************************
** Service Name      : Fls_GetVersionInfoVerify                                              
** 
** 
**  Description      : Development error verification of Fls_GetVersionInfo interface.                       
**                                                                            
**  Parameters (in)  : None                         
**                                                                            
**  Parameters (out) : stFls_VersionInfoPtr: Pointer to where to store the version 
**                                             information of this module.                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#if( FLS_VERSION_INFO_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_GetVersionInfoVerify \
( \
    P2CONST( Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA ) stFls_VersionInfoPtr \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;

    /* Specification of Flash Driver : [SWS_Fls_00363] */
    if( NULL_PTR == stFls_VersionInfoPtr )
    {
        
        Fls_ReportError(FLS_GETVERSIONINFO_ID, FLS_E_PARAM_POINTER);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_VerifyRetVal = (Std_ReturnType)E_OK;
    }
    return u8Fls_VerifyRetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif
#endif

/*****************************************************************************
** Service Name      : Fls_CompareVerify                                              
** 
** 
**  Description      : Development error verification of Fls_Compare interface.                       
**                                                                            
**  Parameters (in)  : u8Fls_SourceAddress: Source address in flash memory. This 
**                                             address offset will be added to the 
**                                             flash memory base address. 
**                                             Min.: 0 
**                                             Max.: FLS_SIZE - 1
**                     u8Fls_TargetAddressPtr: Pointer to target data buffer
**                     u32Fls_Length: Number of bytes to compare 
**                                       Min.: 1 
**                                       Max.: FLS_SIZE - TargetAddress                           
**                                                                            
**  Parameters (out) : None                                                    
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#if( FLS_COMPARE_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_CompareVerify \
( \
    VAR( Fls_AddressType, AUTOMATIC) u32Fls_SourceAddress, \
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) u8Fls_TargetAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) u32Fls_Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;

    /* Specification of Flash Driver : [SWS_Fls_00152] */
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        
        Fls_ReportError(FLS_COMPARE_ID, FLS_E_UNINIT);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00150] */
    else if( u32Fls_SourceAddress >= FLS_TOTAL_SIZE )   /*polyspace RTE:OBAI,IDP,NIV*/
    {
        Fls_ReportError(FLS_COMPARE_ID, FLS_E_PARAM_ADDRESS);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00151] */
    else if(( 0U == u32Fls_Length ) || ((u32Fls_SourceAddress + u32Fls_Length) > FLS_TOTAL_SIZE ))  /*polyspace RTE:OBAI,IDP*/
    {
        Fls_ReportError(FLS_COMPARE_ID, FLS_E_PARAM_LENGTH);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00273] */
    else if( NULL_PTR == u8Fls_TargetAddressPtr )
    {
        Fls_ReportError(FLS_COMPARE_ID, FLS_E_PARAM_DATA);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00153] */
    else if( MEMIF_BUSY == gFls_ModuleStatus )
    {
        /* Specification of Flash Driver : [SWS_Fls_00312] */
        Fls_ReportError(FLS_COMPARE_ID, FLS_E_BUSY);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_VerifyRetVal = (Std_ReturnType)E_OK;
    }

    return u8Fls_VerifyRetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif
#endif


/*****************************************************************************
** Service Name      : Fls_CancelVerify                                              
** 
** 
**  Description      : Development error verification of Fls_Cancel interface.                       
**                                                                            
**  Parameters (in)  : None                         
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#if( FLS_CANCEL_API == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_CancelVerify( void )
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    /* Specification of Flash Driver : [SWS_Fls_00356] */
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        
        Fls_ReportError(FLS_CANCEL_ID, FLS_E_UNINIT);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_VerifyRetVal = (Std_ReturnType)E_OK;
    }
    return u8Fls_VerifyRetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif
#endif


/*****************************************************************************
** Service Name      : Fls_BlankCheckVerify                                              
** 
** 
**  Description      : Development error verification of Fls_BlankCheck interface.                                                   
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.This 
**                                              address offset will be added to the 
**                                              flash memory base address. 
**                                              Min.: 0 
**                                              Max.: FLS_SIZE - 1  
**                     u32Fls_Length: Number of bytes to write 
**                                       Min.: 1 
**                                       Max.: FLS_SIZE - TargetAddress                                                                                          
**                                                                            
**  Parameters (out) : None                         
**          
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#if (FLS_BLANK_CHECK_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_PUBLIC_CODE ) Fls_BlankCheckVerify \
( \
    VAR( Fls_AddressType, AUTOMATIC) u32Fls_TargetAddress, \
    VAR( Fls_LengthType, AUTOMATIC) u32Fls_Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;

    /* Specification of Flash Driver : [SWS_Fls_00382] */
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        
        Fls_ReportError(FLS_BLANK_CHECK_ID, FLS_E_UNINIT );
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00380] */
    else if( u32Fls_TargetAddress >= FLS_TOTAL_SIZE )  /*polyspace RTE:OBAI,IDP,NIV*/
    {
        Fls_ReportError(FLS_BLANK_CHECK_ID, FLS_E_PARAM_ADDRESS );
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00381] */
    else if(( 0U == u32Fls_Length ) \
           || ((u32Fls_TargetAddress + u32Fls_Length) > FLS_TOTAL_SIZE ))  /*polyspace RTE:OBAI,IDP*/
    {
        Fls_ReportError(FLS_BLANK_CHECK_ID, FLS_E_PARAM_LENGTH );
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    /* Specification of Flash Driver : [SWS_Fls_00383] */
    else if( MEMIF_BUSY == gFls_ModuleStatus )
    {
        /* Specification of Flash Driver : [SWS_Fls_00312] */
        Fls_ReportError(FLS_BLANK_CHECK_ID, FLS_E_BUSY );
        u8Fls_RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_RetVal = (Std_ReturnType)E_OK;
    }

    return( u8Fls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif
 #endif

/*****************************************************************************
** Service Name      : Fls_MainFunctionVerify                                              
** 
** 
**  Description      : Development error verification of Fls_MainFunction interface.                       
**                                                                            
**  Parameters (in)  : None                         
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK      There are no development errors. 
**                                     E_NOT_OK  There are development errors.
**
******************************************************************************/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( Std_ReturnType, FLS_CODE ) Fls_MainFunctionVerify(void)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    /* Specification of Flash Driver : [SWS_Fls_00117] */
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        
        Fls_ReportError(FLS_MAINFUNCTION_ID, FLS_E_UNINIT);
        u8Fls_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        u8Fls_VerifyRetVal = (Std_ReturnType)E_OK;
    }
    return u8Fls_VerifyRetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_Init                                              
** 
** 
**  Description      : Initializes the Flash Driver.                         
**                                                                            
**  Service ID       : 0x00                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : ConfigPtr: Pointer to flash driver configuration set.                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00249] */
/* Specification of Flash Driver : [SWS_Fls_00086] */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_Init( P2CONST( Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST ) ConfigPtr )
{   
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = E_OK;

    Host_Flash_LockInit();

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_InitVerify(ConfigPtr);
#endif

    if(u8Fls_RetVal == (Std_ReturnType)E_OK)
    {
        #if (FLS_PRECOMPILE_SUPPORT == STD_ON)
            gFls_ConfigPtr = &Fls_Config;
            (void)ConfigPtr;
        #else 
            gFls_ConfigPtr = ConfigPtr;
        #endif

        Fls_Ats_Wrapper_Init();
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_Erase                                              
** 
** 
**  Description      : Erases flash sector(s).                         
**                                                                            
**  Service ID       : 0x01                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : TargetAddress: Target address in flash memory.This 
**                                    address offset will be added to the 
**                                    flash memory base address. 
**                                    Min.: 0 
**                                    Max.: FLS_SIZE - 1
**                     Length: Number of bytes to erase 
**                             Min.: 1 
**                             Max.: FLS_SIZE - TargetAddress                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: erase command has been accepted
**                                     E_NOT_OK: erase command has not been accepted                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00250] */
/* Specification of Flash Driver : [SWS_Fls_00218] */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_Erase \
( \
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_EraseVerify(TargetAddress, Length);
#endif

    if((Std_ReturnType)E_OK == u8Fls_RetVal)
    {
        SchM_Enter_Fls_EXCLUSIVE_AREA_10();

        Fls_Ats_Wrapper_Erase(TargetAddress,Length);

        SchM_Exit_Fls_EXCLUSIVE_AREA_10();
    }

    /* Specification of Flash Driver : [SWS_Fls_00330] */
    return( u8Fls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_Read                                              
** 
** 
**  Description      : Reads from flash memory.                        
**                                                                            
**  Service ID       : 0x07                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : SourceAddress: Source address in flash memory. This 
**                                    address offset will be added to the 
**                                    flash memory base address. 
**                                    Min.: 0 
**                                    Max.: FLS_SIZE - 1
**                     Length: Number of bytes to read 
**                             Min.: 1 
**                             Max.: FLS_SIZE - SourceAddress                               
**                                                                            
**  Parameters (out) : TargetAddressPtr: Pointer to target data buffer                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: read command has been accepted
**                                     E_NOT_OK: read command has not been accepted                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00256] */
/* Specification of Flash Driver : [SWS_Fls_00236] */
/* Specification of Flash Driver : [SWS_Fls_00240] */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_Read \
( \
    VAR( Fls_AddressType, AUTOMATIC) SourceAddress, \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) TargetAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_ReadVerify(SourceAddress, TargetAddressPtr, Length);
#endif

    if((Std_ReturnType)E_OK == u8Fls_RetVal)
    {
        SchM_Enter_Fls_EXCLUSIVE_AREA_12();

        Fls_Ats_Wrapper_Read(SourceAddress, TargetAddressPtr, Length);

         SchM_Exit_Fls_EXCLUSIVE_AREA_12();
    }

    /* Specification of Flash Driver : [SWS_Fls_00340] */
    return( u8Fls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_Write                                              
** 
** 
**  Description      : Writes one or more complete flash pages.                        
**                                                                            
**  Service ID       : 0x02                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : TargetAddress: Target address in flash memory.This 
**                                    address offset will be added to the 
**                                    flash memory base address. 
**                                    Min.: 0 
**                                    Max.: FLS_SIZE - 1
**                     SourceAddressPtr: Pointer to source data buffer
**                     Length: Number of bytes to write 
**                             Min.: 1 
**                             Max.: FLS_SIZE - TargetAddress                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: write command has been accepted
**                                     E_NOT_OK: write command has not been accepted                                                   
**                                                                            
******************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_Write \
( \
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress, \
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) SourceAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_WriteVerify(TargetAddress,SourceAddressPtr,Length);
#endif
    if ((Std_ReturnType)E_OK == u8Fls_RetVal)
    {
        SchM_Enter_Fls_EXCLUSIVE_AREA_11();

        Fls_Ats_Wrapper_Write(TargetAddress,SourceAddressPtr,Length);

        SchM_Exit_Fls_EXCLUSIVE_AREA_11();
    }

    /* Specification of Flash Driver : [SWS_Fls_00334] */
    return u8Fls_RetVal;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_SetMode                                              
** 
** 
**  Description      : Sets the flash driver’s operation u32Fls_Mode.                        
**                                                                            
**  Service ID       : 0x09                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : Mode: MEMIF_MODE_SLOW: Slow read access / normal SPI access.
**                           MEMIF_MODE_FAST: Fast read access / SPI burst access.                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00258] */
#if( FLS_SET_MODE_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_SetMode \
( \
    VAR( MemIf_ModeType, FLS_CODE ) Mode \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_SetModeVerify();
#endif

    if(u8Fls_RetVal == (Std_ReturnType)E_OK)
    {
        Fls_Ats_Wrapper_SetMode(Mode);
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_GetVersionInfo                                              
** 
** 
**  Description      : Returns the version information of this module.                        
**                                                                            
**  Service ID       : 0x10                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : VersioninfoPtr: Pointer to where to store the version 
**                                     information of this module.                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
#if( FLS_VERSION_INFO_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_GetVersionInfo \
( \
    P2VAR( Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA ) VersionInfoPtr \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_GetVersionInfoVerify(VersionInfoPtr);
#endif
    
    if ((Std_ReturnType)E_OK == u8Fls_RetVal)
    {
        VersionInfoPtr->moduleID = (uint16)FLS_MODULE_ID;
        VersionInfoPtr->vendorID = (uint16)FLS_C_VENDOR_ID_PLUGIN;
        VersionInfoPtr->sw_major_version = (uint8)FLS_C_SW_MAJOR_VER;
        VersionInfoPtr->sw_minor_version = (uint8)FLS_C_SW_MINOR_VER;
        VersionInfoPtr->sw_patch_version = (uint8)FLS_C_SW_PATCH_VER;
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_Compare                                              
** 
** 
**  Description      : Compares the contents of an area of flash memory 
**                     with that of an application data buffer.                        
**                                                                            
**  Service ID       : 0x08                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : SourceAddress: Source address in flash memory. This 
**                                    address offset will be added to the 
**                                    flash memory base address.  
**                                    Min.: 0 
**                                    Max.: FLS_SIZE - 1
**                     TargetAddressPtr: Pointer to target data buffer
**                     Length: Number of bytes to compare 
**                             Min.: 1 
**                             Max.: FLS_SIZE - SourceAddress                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType: E_OK: compare command has been accepted
**                                     E_NOT_OK: compare command has not been accepted                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00257] */
/* Specification of Flash Driver : [SWS_Fls_00241] */
#if( FLS_COMPARE_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_Compare \
( \
    VAR( Fls_AddressType, AUTOMATIC) SourceAddress, \
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) TargetAddressPtr, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_CompareVerify(SourceAddress, TargetAddressPtr, Length);
#endif

    if((Std_ReturnType)E_OK == u8Fls_RetVal)
    {
        SchM_Enter_Fls_EXCLUSIVE_AREA_13();

        Fls_Ats_Wrapper_Compare(SourceAddress, TargetAddressPtr, Length);

        SchM_Exit_Fls_EXCLUSIVE_AREA_13();
    }

    /* Specification of Flash Driver : [SWS_Fls_00344] */
    return( u8Fls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_Cancel                                              
** 
** 
**  Description      : Cancels an ongoing job.                        
**                                                                            
**  Service ID       : 0x03                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00252] */
#if ( FLS_CANCEL_API == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_Cancel( void )
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_CancelVerify();
#endif

    if((Std_ReturnType)E_OK == u8Fls_RetVal)
    {
        SchM_Enter_Fls_EXCLUSIVE_AREA_17();
        Fls_Ats_Wrapper_Cancel();
        SchM_Exit_Fls_EXCLUSIVE_AREA_17();
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_GetStatus                                              
** 
** 
**  Description      : Returns the driver state.                        
**                                                                            
**  Service ID       : 0x04                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : MemIf_StatusType                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00253] */
/* Specification of Flash Driver : [SWS_Fls_00034] */
#if( FLS_GET_STATUS_API == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( MemIf_StatusType, FLS_CODE ) Fls_GetStatus( void )
{
    VAR( MemIf_StatusType, AUTOMATIC ) eFls_RetVal = MEMIF_IDLE;

    if( NULL_PTR == gFls_ConfigPtr )
    {
        eFls_RetVal = MEMIF_UNINIT;
    }
    else
    {
        eFls_RetVal = gFls_ModuleStatus;
    }

    return( eFls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_GetJobResult                                              
** 
** 
**  Description      : Returns the result of the last job.                        
**                                                                            
**  Service ID       : 0x05                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Reentrant                                          
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : MemIf_StatusType                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00254] */
/* Specification of Flash Driver : [SWS_Fls_00035] */
#if ( FLS_GET_JOB_RESULT_API == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( MemIf_JobResultType, FLS_CODE ) Fls_GetJobResult( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eFls_mRetVal = MEMIF_JOB_OK;

    /* Specification of Flash Driver : [SWS_Fls_00358] */
    if( NULL_PTR == gFls_ConfigPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00311] */
        #if( FLS_DEV_ERROR_DETECT == STD_ON )
        Fls_ReportError(FLS_GETJOBRESULT_ID, FLS_E_UNINIT);
        #endif
        eFls_mRetVal = (MemIf_JobResultType)MEMIF_JOB_FAILED;
    }
    else
    {
        /* Specification of Flash Driver : [SWS_Fls_00036] */
        eFls_mRetVal = gFls_JobResult;
    }
    return( eFls_mRetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif


/*****************************************************************************
** Service Name      : Fls_BlankCheck                                              
** 
** 
**  Description      : The function Fls_BlankCheck shall verify, whether a 
**                     given memory area has been erased but not (yet) programmed. 
**                     The function shall limit the maximum number of checked 
**                     flash cells per main function cycle to the configured 
**                     value FlsMaxReadNormalMode or FlsMaxReadFastMode respectively.                        
**                                                                            
**  Service ID       : 0x0A                                                   
**                                                                            
**  Sync/Async       : Asynchronous                                            
**                                                                            
**  Reentrancy       : Non Reentrant                                          
**                                                                            
**  Parameters (in)  : u32Fls_TargetAddress: Target address in flash memory.This 
**                                              address offset will be added to the 
**                                              flash memory base address. 
**                                              Min.: 0 
**                                              Max.: FLS_SIZE - 1  
**                     u32Fls_Length: Number of bytes to write 
**                                       Min.: 1 
**                                       Max.: FLS_SIZE - TargetAddress                              
**                                                                            
**  Parameters (out) : None                                                  
**                                                                            
**  Return value     : Std_ReturnType: E_OK: request for blank checking has 
**                                           been accepted by the module
**                                     E_NOT_OK: request for blank checking has 
**                                               not been accepted by the module                                                   
**                                                                                                                                             
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00371] */
/* Specification of Flash Driver : [SWS_Fls_00373] */
/* Specification of Flash Driver : [SWS_Fls_00374] */
#if (FLS_BLANK_CHECK_API == STD_ON)
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( Std_ReturnType, FLS_CODE ) Fls_BlankCheck \
( \
    VAR( Fls_AddressType, AUTOMATIC) TargetAddress, \
    VAR( Fls_LengthType, AUTOMATIC) Length \
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_BlankCheckVerify(TargetAddress, Length);
#endif

    if((Std_ReturnType)E_OK == u8Fls_RetVal)
    {
        SchM_Enter_Fls_EXCLUSIVE_AREA_14();

        Fls_Ats_Wrapper_BlankCheck(TargetAddress, Length);

        SchM_Exit_Fls_EXCLUSIVE_AREA_14();
    }

    /* Specification of Flash Driver : [SWS_Fls_00377] */
    return( u8Fls_RetVal );
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*****************************************************************************
** Service Name      : Fls_MainFunction                                              
** 
** 
**  Description      : Performs the processing of jobs.                        
**                                                                            
**  Service ID       : 0x06                                                   
**                                                                            
**  Timing           : FIXED_CYCLIC                                            
**                                                                            
**  Parameters (in)  : None                               
**                                                                            
**  Parameters (out) : None                                                  
**                                                                            
**  Return value     : None                                                   
**                                                                            
******************************************************************************/
/* Specification of Flash Driver : [SWS_Fls_00001] */
/* Specification of Flash Driver : [SWS_Fls_00255] */
/* Specification of Flash Driver : [SWS_Fls_00037] */
/* Specification of Flash Driver : [SWS_Fls_00038] */
/* Specification of Flash Driver : [SWS_Fls_00040] */
/* Specification of Flash Driver : [SWS_Fls_00385] */
/* Specification of Flash Driver : [SWS_Fls_00235] */
/* Specification of Flash Driver : [SWS_Fls_00196] */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_MainFunction( void )
{
    VAR( Std_ReturnType, AUTOMATIC ) u8Fls_RetVal = (Std_ReturnType)E_OK;
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    u8Fls_RetVal = Fls_MainFunctionVerify();
#endif

    if( (Std_ReturnType)E_OK == u8Fls_RetVal )
    {
        SchM_Enter_Fls_EXCLUSIVE_AREA_15();

        Fls_Ats_Wrapper_MainFunction();

        SchM_Exit_Fls_EXCLUSIVE_AREA_15();

    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( uint32, FLS_CODE ) Fls_GetTimeOutCounter( void )
{
    return u32Fls_LockTimeOutCounter;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_ClearTimeOutCounter( void )
{
    u32Fls_LockTimeOutCounter = 0U;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
