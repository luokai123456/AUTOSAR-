/* PRQA S 2053, 3432, 0310 EOF */
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
/* PRQA S 1863,1006 ,3401,3400,3397,0498 ,2934,2982,2996,1525,1599,1594 ,1756 EOF */ 
/**
*   @file    Fls_LLDriver.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of FLS MCAL driver.
*
*   @addtogroup FLS
*   @{
*/

/* PRQA S 0488, 0751,3305 ,2844 ,2985 ,0491 ,3200,1594,1756,1599,2755 EOF */

#include "Fls_LLDriver.h" /* PRQA S 0380 */
#include "Fls.h"
#include "Det.h"
#include "common.h"

#define FLS_LLD_WRA_C_VENDOR_ID                     176
#define FLS_LLD_WRA_C_AR_REL_MAJOR_VER              4
#define FLS_LLD_WRA_C_AR_REL_MINOR_VER              4
#define FLS_LLD_WRA_C_AR_REL_REV_VER                0
#define FLS_LLD_WRA_C_SW_MAJOR_VER                  3
#define FLS_LLD_WRA_C_SW_MINOR_VER                  0
#define FLS_LLD_WRA_C_SW_PATCH_VER                  0

#if (FLS_VENDOR_ID_OUTPUT != FLS_LLD_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_VENDOR_ID "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_LLD_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_LLD_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_LLD_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_LLD_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_LLD_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_LLD_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_LLD_WRA_C_SW_PATCH_VER "
#endif

#define Fls_ReportRuntimeError(ApiId, ErrorId) \
        (void)Det_ReportRuntimeError( (uint16)FLS_MODULE_ID, FLS_INSTANCE, (ApiId), (ErrorId) );

/* Flash EHV value */
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
static VAR( uint32, AUTOMATIC) FLS_EHV_Val = 0U;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
static uint8_t FLS_EHV_Val_All[FLS_CONTROLLER_NUM] = {0U}; /* PRQA S 3218 */
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"
#endif // RESOURCE_SUPPORT_PFI
/* Flash Swap Status */
#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR( uint8, AUTOMATIC ) g_swapStatus = 0U;  
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR( uint8, AUTOMATIC ) g_flashSize = 1U;  /* PRQA S 3408 */
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"
#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR( uint32, AUTOMATIC) gFLS_Ecc_Flag = 0U;/* PRQA S 3408 */
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#ifdef RESOURCE_SUPPORT_PFI
/* The controller currently in operation */
#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
static volatile struct C55FMC_tag *FLS_OpEFMC[FLS_CONTROLLER_NUM] = {NULL};
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
static volatile struct C55FMC_tag *FLS_OpPFMC = NULL;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
static volatile struct C55FMC_tag * const flashControllerList[FLS_CONTROLLER_NUM] = {
    &FLS_FMC,
    #ifdef RESOURCE_SUPPORT_PFI0
    &FLS_T40FMC0,
    #endif // RESOURCE_SUPPORT_PFI0
    #ifdef RESOURCE_SUPPORT_PFI1
    &FLS_T40FMC1,
    #endif // RESOURCE_SUPPORT_PFI1
    #ifdef RESOURCE_SUPPORT_PFI2
    &FLS_T40FMC2,
    #endif // RESOURCE_SUPPORT_PFI2
    #ifdef RESOURCE_SUPPORT_PFI3
    &FLS_T40FMC3,
    #endif // RESOURCE_SUPPORT_PFI3
    #ifdef RESOURCE_SUPPORT_PFI4
    &FLS_T40FMC4,
    #endif // RESOURCE_SUPPORT_PFI4
    #ifdef RESOURCE_SUPPORT_PFI5
    &FLS_T40FMC5,
    #endif // RESOURCE_SUPPORT_PFI5
};
#define FLS_STOP_SEC_CONFIG_DATA
#include "Fls_MemMap.h"
#endif // RESOURCE_SUPPORT_PFI

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR( uint32, AUTOMATIC) gFLS_Ecc_Addr = 0U;/* PRQA S 3408 */
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

extern VAR( fls_acload_t, AUTOMATIC) pFls_AcCodePtr;
#ifdef DCACHE_ENABLE
extern void CACHE_LLD_InvalidateDcache(void);
#endif

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
VAR( uint32, AUTOMATIC) FLS_AcCodeArea[32] = {0U}; /* PRQA S 3408 */
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT
#include "Fls_MemMap.h"
static P2CONST( volatile uint8, FLS_VAR, FLS_APPL_CONST ) volatile gFls_ReadAddressPtr = NULL_PTR;
#define FLS_STOP_SEC_VAR_INIT
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckEraseStatus \
( \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Erase \
( \
    VAR( uint8, AUTOMATIC ) u8Fls_EraseSpace, \
    P2VAR( fls_blksel_t, AUTOMATIC, FLS_APPL_DATA ) pFls_BlkSel, \
    VAR( uint32, AUTOMATIC) u32Fls_Mode \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*
 * @brief Get the controller FLS_EHV_Val
 *
 * This function will return the FLS_EHV_Val depend on controller
 *
 * @param[in] fmc The controller.
 * @param[in] fmc The controller.
 * @return Operation status
 */
#ifdef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_LLD_Get_FLS_EHV_Val
(
    const volatile struct C55FMC_tag *fmc,
    uint8_t **ehv_val
)
{
    VAR(uint32, AUTOMATIC) u32Fls_index = 0U;
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_ERROR;

    for (u32Fls_index = 0U; u32Fls_index < FLS_CONTROLLER_NUM;u32Fls_index++) {
        if (fmc == flashControllerList[u32Fls_index]) 
        {
            sFls_Ret = STATUS_SUCCESS;
            *ehv_val = FLS_EHV_Val_All + u32Fls_index;
            break;
        }
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_LLD_GetMappedPFlash
(
    volatile struct C55FMC_tag *controller,
    volatile struct PFLASH_tag **mapped_pflash)
{
    VAR(uint32, AUTOMATIC) u32Fls_count = 0U;
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_ERROR;

    for (u32Fls_count = 0U; u32Fls_count < FLS_CONTROLLER_NUM; u32Fls_count++) {
        if (flashPFlashMap[u32Fls_count].controller == controller) {
        	sFls_Ret = STATUS_SUCCESS;
            *mapped_pflash = flashPFlashMap[u32Fls_count].mapped_pflash;

            break;
        }
    }
    
        return sFls_Ret;
    }
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


/*
 * @brief Get Flash Block Controller
 *
 * This function will get flash block controller.
 *
 * @param[in]  blk: The Index of Block.
 * @param[out] controller: The Controller of Selected Block.
 * @return Operation status
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_GetBlockController
(
    VAR( uint32, AUTOMATIC) u32Fls_blk, 
    volatile struct C55FMC_tag **controller
) 
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    const flash_block_map_t *block_map = NULL;

    if (u32Fls_blk >= FLS_BLOCK_ALL) {
        return STATUS_ERROR;
    }

    if (g_swapStatus == 0U) {
        block_map = flashBlockMap0;
    } else {
        block_map = flashBlockMap1;
    }

    *controller = block_map[u32Fls_blk].controller;

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*
 * @brief Get Mapped Controller
 *
 * This function will get mapped controller.
 *
 * @param[in]  controller: The Target Controller.
 * @param[out] mapped_controller: The Mapped Controller.
 * @return Operation status
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_GetMappedController
(
    volatile struct C55FMC_tag *controller, 
    volatile struct C55FMC_tag **mapped_controller) 
{
    VAR( uint32, AUTOMATIC) u32Fls_Index = 0;
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_ERROR;
    const flash_controller_map_t *controller_map = NULL;

    if (g_swapStatus == 0U) {
        controller_map = flashControllerMap0;
    } else {
        controller_map = flashControllerMap1;
    }

    for (u32Fls_Index = 0U; u32Fls_Index < FLS_CONTROLLER_NUM; u32Fls_Index++) {
        if (controller_map[u32Fls_Index].controller == controller) {
            sFls_Ret = STATUS_SUCCESS;
            *mapped_controller = controller_map[u32Fls_Index].mapped_controller;

            break;
        }
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif // RESOURCE_SUPPORT_PFI
/*****************************************************************************
** Service Name      : Fls_LLD_CalcInitDataLength                                              
** 
** 
**  Description      : Used to calculate the number of bytes read from flash 
**                     memory until the source pointer is aligned with the data 
**                     width and the optimized wide flash memory read can start.                         
**                                                                            
**  Parameters (in)  : u8Fls_SourceAddrPtr: Source pointer
**                     u32Fls_TotalBytes: Total number of bytes read                      
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : uint32: The length of the initial 8-bit flash read(in bytes)                                                  
**                                                                            
******************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( uint32, FLS_CODE ) Fls_LLD_CalcInitDataLength
( 
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) u8Fls_SourceAddrPtr,
    CONST(uint32, AUTOMATIC) u32Fls_TotalBytes 
)
{
    VAR(uint32, AUTOMATIC) u32Fls_length = 0UL;

    u32Fls_length = ( (uint32)u8Fls_SourceAddrPtr ) & ( sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - 1UL );

    if ( u32Fls_length != 0U )
    {
        u32Fls_length = sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - u32Fls_length;
    }

    if( u32Fls_length > u32Fls_TotalBytes ) 
    {
        u32Fls_length = u32Fls_TotalBytes;
    }
    
    return u32Fls_length;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*****************************************************************************
** Service Name      : Fls_LLD_CalcWideDataLength                                              
** 
** 
**  Description      : Used to calculate the number of bytes read from flash 
**                     memory until the source pointer is misaligned with the 
**                     data bus width.                         
**                                                                            
**  Parameters (in)  : u32Fls_InitDataLength: Calculated by 
**                     Fls_LLD_CalcInitDataLength function
**                     u32Fls_TotalBytes: Total number of bytes read                      
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : uint32: The length of the initial 32-bit or 64-bit 
**                             flash read(in bytes)                                                  
**                                                                            
******************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( uint32, FLS_CODE ) Fls_LLD_CalcWideDataLength
(
    CONST(uint32, AUTOMATIC) u32Fls_InitDataLength,
    CONST(uint32, AUTOMATIC) u32Fls_TotalBytes 
)
{
    VAR(uint32, AUTOMATIC) u32Fls_length = 0UL;

    u32Fls_length = (( u32Fls_TotalBytes - u32Fls_InitDataLength ) & (~( sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE) - 1UL )));

    return u32Fls_length;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Init (void)
{
	VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;

    /* unLock Flash Block*/
    FLS_FMC.LOCK0.B.LOWLOCK = 0U;
#ifndef CCFC3008PCSA
    FLS_FMC.LOCK0.B.MIDLOCK = 0U;
#endif

#if defined(CCFC3008PCSN)
    FLS_FMC.LOCK1.B.LOWLOCK = 0U;
#else
  #ifndef CCFC3008PCSA
    FLS_FMC.LOCK1.B.HIGHLOCK = 0U;
  #endif
#endif // CCFC3008PCSN

#ifndef RESOURCE_SUPPORT_PFI
  #if defined(CCFC3008PC) || defined(CCFC3008PCSN)
    *((volatile uint8 *)(&FLS_FMC) + 0x1FCU) = 0x20U;/* polyspace RTE:IDP */
    *((volatile uint8 *)(&FLS_FMC) + 0x1FDU) = 0x22U;/* polyspace RTE:IDP */
    *((volatile uint8 *)(&FLS_FMC) + 0x1FEU) = 0x08U;/* polyspace RTE:IDP */
    *((volatile uint8 *)(&FLS_FMC) + 0x1FFU) = 0x01U;/* polyspace RTE:IDP */

    FLS_FMC.LOCK1.B.MTLOCK = 0xFFFFU; // for the info block, setting the bit to 1 is unlocking
  #endif // CCFC3008PC || CCFC3008PCSN

    FLS_FMC.LOCK2.B.A256KLOCK = 0U;
  #ifndef CCFC3008PCSA
    FLS_FMC.LOCK3.B.A256KLOCK = 0U;
  #endif

  #if defined(CCFC3008PCSN)
    FLS_FMC.LOCK4.B.MIDLOCK = 0U;
  #endif // CCFC3008PCSN

  #if defined(CCFC3008PC)
    FLS_FMC.LOCK0.R |= 0x3FFFFFFFU;

	FLS_FMC.LOCK1.R |= 0xFFFFFFFFU;

	FLS_FMC.LOCK2.R |= 0xFFFFFFFFU;

	FLS_FMC.LOCK3.R |= 0xFFFFU;
  #elif defined(CCFC3008PCSN)
    FLS_FMC.LOCK0.R |= 0xFFFFU;

    FLS_FMC.LOCK2.R |= 0xFFFFFFFU;
  #elif defined(CCFC3008PCSA)
    FLS_FMC.LOCK0.R |= 0x8000FFFFU;
    FLS_FMC.LOCK1.R |= 0x0000FFFFU;
    FLS_FMC.LOCK2.R |= 0xFFFFFFFFU;
  #else
	FLS_FMC.LOCK0.R |= 0x3DE0000U;

	FLS_FMC.LOCK1.R |= 0xFFU;

	FLS_FMC.LOCK2.R |= 0xFFFFFFFFU;

	FLS_FMC.LOCK3.R |= 0xFFFFU;
  #endif // CCFC3008PC || CCFC3008PCSN || CCFC3008PCSA
#else
	FLS_FMC.LOCK0.R |= 0xFFF0000U;
	FLS_FMC.LOCK1.R |= 0xFFU;
	FLS_FMC.LOCK2.R |= 0xFFFFFFFFU;
  #ifdef RESOURCE_SUPPORT_PFI0
	FLS_T40FMC0.LOCK2.R |= 0xFFFFFFFFU;
  #endif
  #ifdef RESOURCE_SUPPORT_PFI1
    FLS_T40FMC1.LOCK2.R |= 0xFFFFFFFFU;
  #endif
  #ifdef RESOURCE_SUPPORT_PFI2
    FLS_T40FMC2.LOCK2.R |= 0xFFFFFFFFU;
  #endif
  #ifdef RESOURCE_SUPPORT_PFI3
    FLS_T40FMC3.LOCK2.R |= 0xFFFFFFFFU;
  #endif
  #ifdef RESOURCE_SUPPORT_PFI4
    FLS_T40FMC4.LOCK2.R |= 0xFFFFFFFFU;
  #endif
  #ifdef RESOURCE_SUPPORT_PFI5
    FLS_T40FMC5.LOCK2.R |= 0xFFFFFFFFU;
  #endif
#endif // RESOURCE_SUPPORT_PFI

    /* Clear error bits */
#ifndef RESOURCE_SUPPORT_PFI
    FLS_FMC.MCR.B.EER = 1U;
    FLS_FMC.MCR.B.RWE = 1U;
    FLS_FMC.MCR.B.SBC = 1U;
    FLS_FMC.MCR.B.RVE = 1U;
    FLS_FMC.MCR.B.RRE = 1U;
    FLS_FMC.MCR.B.AEE = 1U;
    FLS_FMC.MCR.B.EEE = 1U;
	
#else
    for (uint32 u32Fls_Index = 0U; u32Fls_Index < FLS_CONTROLLER_NUM; u32Fls_Index++) {
        flashControllerList[u32Fls_Index]->MCR.B.EER = 1U;
        flashControllerList[u32Fls_Index]->MCR.B.RWE = 1U;
        flashControllerList[u32Fls_Index]->MCR.B.SBC = 1U;
        flashControllerList[u32Fls_Index]->MCR.B.RVE = 1U;
        flashControllerList[u32Fls_Index]->MCR.B.RRE = 1U;
        flashControllerList[u32Fls_Index]->MCR.B.AEE = 1U;
        flashControllerList[u32Fls_Index]->MCR.B.EEE = 1U;
		}

#endif // RESOURCE_SUPPORT_PFI

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#if( FLS_ERASE_VERIFICATION_ENABLED == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) Fls_LLD_VerifyErase \
( \
    P2CONST(volatile uint32, AUTOMATIC, FLS_APPL_CONST ) u32Fls_FlashAreaPtr, \
	CONST( Fls_LengthType, AUTOMATIC) u32Fls_DataLength \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) u8Fls_FlashAreaEndPtr = NULL_PTR;

    u8Fls_FlashAreaEndPtr = ((volatile const uint8 *)u32Fls_FlashAreaPtr) + u32Fls_DataLength;
    gFls_ReadAddressPtr = ((volatile const uint8 *)u32Fls_FlashAreaPtr);

    while( (uint32)gFls_ReadAddressPtr < (uint32)u8Fls_FlashAreaEndPtr )
    {
        if( FLS_ERASED_VALUE != *((volatile const uint32*)gFls_ReadAddressPtr) )  /*polyspace RTE:IDP,NIV*/
        {
            break;
        }   
        gFls_ReadAddressPtr += sizeof(uint32);
    }

    if( gFls_ReadAddressPtr != u8Fls_FlashAreaEndPtr )
    {
        Fls_ReportRuntimeError(FLS_MAINFUNCTION_ID, FLS_E_VERIFY_ERASE_FAILED);
        sFls_Ret = STATUS_ERROR;
    }

    #ifndef RESOURCE_SUPPORT_PFI
	if(FLS_FMC.MCR.B.EER == 1U)
	{
        FLS_FMC.MCR.B.EER = 1U;
        gFLS_Ecc_Addr = (uint32)u32Fls_FlashAreaPtr;
        gFLS_Ecc_Flag = 1U;
		sFls_Ret = STATUS_ERROR;
	}
    #else
    VAR( uint32, AUTOMATIC) u32Fls_Index = 0;
    for (u32Fls_Index = 0U; u32Fls_Index < FLS_CONTROLLER_NUM; u32Fls_Index++) 
    {
        if(flashControllerList[u32Fls_Index]->MCR.B.EER == 1U)
        {
            flashControllerList[u32Fls_Index]->MCR.B.EER = 1U;
        	gFLS_Ecc_Addr = (uint32)u32Fls_FlashAreaPtr;
        	gFLS_Ecc_Flag = 1U;
            sFls_Ret = STATUS_ERROR;
            break;
        }
	}
    #endif

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

#if( FLS_WRITE_VERIFICATION_ENABLED == STD_ON )
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) Fls_LLD_VerifyWrite \
( \
    P2CONST( volatile uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_FlashAreaPtr, \
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pFls_UserBufferPtr, \
    CONST( Fls_LengthType, AUTOMATIC) u32Fls_DataLength \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) u8Fls_FlashAreaEndPtr = NULL_PTR;
    P2CONST( volatile uint8, FLS_VAR, FLS_APPL_CONST ) volatile gFls_CompareAddressPtr = NULL_PTR;

    u8Fls_FlashAreaEndPtr = ((volatile const uint8 *)pFls_FlashAreaPtr) + u32Fls_DataLength;
    gFls_CompareAddressPtr = ((const uint8 *)pFls_UserBufferPtr);
    gFls_ReadAddressPtr = ((volatile const uint8 *)pFls_FlashAreaPtr);

    while( (uint32)gFls_ReadAddressPtr < (uint32)u8Fls_FlashAreaEndPtr )
    {
        if( *((volatile const uint32*)gFls_ReadAddressPtr) !=  /* polyspace RTE:IDP,NIV */
            *((volatile const uint32*)gFls_CompareAddressPtr) )  /* polyspace RTE:IDP,NIV */
        {
            break;
        }
        
        gFls_CompareAddressPtr += sizeof(uint32);
        gFls_ReadAddressPtr += sizeof(uint32);
    }

    if( gFls_ReadAddressPtr != u8Fls_FlashAreaEndPtr )
    {
        /* Specification of Flash Driver : [SWS_Fls_00314] */
        /* Specification of Flash Driver : [SWS_Fls_00056] */
        Fls_ReportRuntimeError(FLS_MAINFUNCTION_ID, FLS_E_VERIFY_WRITE_FAILED);
        sFls_Ret = STATUS_ERROR;
    }
	#ifndef RESOURCE_SUPPORT_PFI
	if(FLS_FMC.MCR.B.EER == 1U)
	{
        FLS_FMC.MCR.B.EER = 1U;
        gFLS_Ecc_Addr = (uint32)pFls_FlashAreaPtr;
        for (uint32 flash_index = 0U; flash_index < FLS_BLOCK_ALL; flash_index++)
        {
            if ((gFLS_Ecc_Addr >= flashInfo[flash_index].addrStart) && (gFLS_Ecc_Addr <= flashInfo[flash_index].addrEnd))
            {
                gFLS_Ecc_Addr = flashInfo[flash_index].addrStart;
				break;
            }
        }
        gFLS_Ecc_Flag = 1U;
		sFls_Ret = STATUS_ERROR;
	}
	#else
    VAR( uint32, AUTOMATIC) u32Fls_Index = 0;
    for (u32Fls_Index = 0U; u32Fls_Index < FLS_CONTROLLER_NUM; u32Fls_Index++) 
    {
        if((flashControllerList[u32Fls_Index]->MCR.B.EER) == 1U)
        {
            flashControllerList[u32Fls_Index]->MCR.B.EER = 1U;
	        gFLS_Ecc_Addr = (uint32)pFls_FlashAreaPtr;
	        for (uint32 flash_index = 0U; flash_index < FLS_BLOCK_ALL; flash_index++)
	        {
	            if ((gFLS_Ecc_Addr >= flashInfo[flash_index].addrStart) && (gFLS_Ecc_Addr <= flashInfo[flash_index].addrEnd))
	            {
	                gFLS_Ecc_Addr = flashInfo[flash_index].addrStart;
					break;
	            }
	        }
	        gFLS_Ecc_Flag = 1U;
			sFls_Ret = STATUS_ERROR;
            break;
        }
        
	}
    #endif
    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif

/*
 * @brief Execute suspend operation
 *
 * This function will suspend the program, erase activities
 *
 * @param[out] u8Fls_SusStatus The status of suspend after calling the function.
 * @return Operation status
 */
#if (FLS_CANCEL_API == STD_ON )
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( void, FLS_CODE ) FLS_LLD_SusExec_Cancel \
( \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) u8Fls_SusStatus \
)
{
    VAR( uint16, AUTOMATIC) u16Fls_SusDelay = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Index = ABT_OPT_TIMEOUT_COUNTER;

    if (FLS_FMC.MCR.B.EHV == 0U)
    {
        if (FLS_FMC.MCR.B.PGM != 0U)
        {
            *u8Fls_SusStatus = FLS_PGM_WRITE;

            if (FLS_FMC.MCR.B.ERS != 0U)
            {
                *u8Fls_SusStatus = FLS_ERS_SUS_PGM_WRITE;
            }
        }
        else
        {
            *u8Fls_SusStatus = FLS_ERS_WRITE;
        }
        /* Wait MCR DONE bit is set */
        while ((FLS_FMC.MCR.B.DONE == 0x0U) && (u32Fls_Index > 0U))
        {
            u32Fls_Index--;
        }
    }
    else
    {
        if (FLS_FMC.MCR.B.PGM != 0x0U)
        {
            /* Set MCR_PSUS bit */
            FLS_FMC.MCR.B.PSUS = 1U;
            for (u16Fls_SusDelay = 0U; u16Fls_SusDelay < 160U; u16Fls_SusDelay++)
            {}
        }
        else
        {
            /* Set MCR-ESUS bit */
            FLS_FMC.MCR.B.ESUS = 1U;
            for (u16Fls_SusDelay = 0U; u16Fls_SusDelay < 320U; u16Fls_SusDelay++)
            {}
        }
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( void, FLS_CODE ) FLS_LLD_SusExec_Cancel
(
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) u8Fls_SusStatus, \
     volatile struct C55FMC_tag *fmc
)
{   
    VAR( uint16, AUTOMATIC) u16Fls_SusDelay = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Index = ABT_OPT_TIMEOUT_COUNTER;

    if (fmc->MCR.B.EHV == 0U)
    {
        if (fmc->MCR.B.PGM != 0U)
        {
            *u8Fls_SusStatus = FLS_PGM_WRITE;

            if (fmc->MCR.B.ERS != 0U)
            {
                *u8Fls_SusStatus = FLS_ERS_SUS_PGM_WRITE;
            }
        }
        else
        {
            *u8Fls_SusStatus = FLS_ERS_WRITE;
        }
        /* Wait MCR DONE bit is set */
        while ((fmc->MCR.B.DONE == 0x0U) && (u32Fls_Index > 0U))
        {
            u32Fls_Index--;
        }
    }
    else
    {
        if (fmc->MCR.B.PGM != 0x0U)
        {
            /* Set MCR_PSUS bit */
            fmc->MCR.B.PSUS = 1U;
            for (u16Fls_SusDelay = 0U; u16Fls_SusDelay < 160U; u16Fls_SusDelay++)
            {}
        }
        else
        {
            /* Set MCR-ESUS bit */
            fmc->MCR.B.ESUS = 1U;
            for (u16Fls_SusDelay = 0U; u16Fls_SusDelay < 320U; u16Fls_SusDelay++)
            {}
        }
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
       
#endif // RESOURCE_SUPPORT_PFI
#endif

#if (FLS_CANCEL_API == STD_ON )
/*****************************************************************************
** Service Name      : Fls_LLD_Cancel                                              
** 
** 
**  Description      : Used to cancel the last working operation of the driver layer.                     
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
FUNC( status_t, FLS_CODE ) Fls_LLD_Cancel(P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) u8Fls_SusStatus)
{
    VAR( uint32, AUTOMATIC) u32Fls_Count = ABT_OPT_TIMEOUT_COUNTER;

#ifdef RESOURCE_SUPPORT_PFI
	VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_ERROR;
    uint32 u32fls_index = 0U;
#endif // RESOURCE_SUPPORT_PFI
    if ( u8Fls_SusStatus == NULL)
    {
        return STATUS_ERROR;
    }

    *u8Fls_SusStatus = FLS_NO_SUS;

#ifndef RESOURCE_SUPPORT_PFI
    /* No program/erase sequence */
    if ((FLS_FMC.MCR.B.PGM == 0U) && (FLS_FMC.MCR.B.ERS == 0U))
    {
        /* Nothing to do */
    }
    else
    {
        if (((FLS_FMC.MCR.B.PGM != 0U) && (FLS_FMC.MCR.B.PSUS == 0U))\
             || ((FLS_FMC.MCR.B.ERS != 0U) && (FLS_FMC.MCR.B.ESUS == 0U)))
        {
            FLS_LLD_SusExec_Cancel(u8Fls_SusStatus);
        }

        /* Check the high voltage is cleared or not */
        if ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U))
        {
            if (FLS_FMC.MCR.B.PSUS != 0U)
            {
                *u8Fls_SusStatus = FLS_PGM_SUS;

                if (FLS_FMC.MCR.B.ESUS != 0U)
                {
                    *u8Fls_SusStatus = FLS_ERS_SUS_PGM_SUS;
                }
            }
            else
            {
                *u8Fls_SusStatus = FLS_ERS_SUS;
            }

            /* Wait MCR DONE bit is set */
            while ((FLS_FMC.MCR.B.DONE == 0U) && (u32Fls_Count > 0U))
            {
                u32Fls_Count--;
            }

            /* Set MCR_EHV to 0 */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
        }
    }
#else
    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++) {
        volatile struct C55FMC_tag * const fmc = flashControllerList[u32fls_index];

        /* No program/erase sequence */
        if ((fmc->MCR.B.PGM == 0U) && (fmc->MCR.B.ERS == 0U)) {
            /* Nothing to do */
        } else {
        	P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) fls_ehv_val = NULL_PTR;

            if (((fmc->MCR.B.PGM != 0U) && (fmc->MCR.B.PSUS == 0U)) ||
                ((fmc->MCR.B.ERS != 0U) && (fmc->MCR.B.ESUS == 0U))) {
                 FLS_LLD_SusExec_Cancel(u8Fls_SusStatus, fmc);
            }

            sFls_Ret = FLS_LLD_Get_FLS_EHV_Val(fmc, &fls_ehv_val);
            if(sFls_Ret !=STATUS_SUCCESS )
            {
            	return sFls_Ret;
            }

            /* Check the high voltage is cleared or not */
            if ((fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U))  /* polyspace RTE:NIV */
            {
                if (fmc->MCR.B.PSUS != 0U) /* polyspace RTE:NIV */
                { 
                    *u8Fls_SusStatus = FLS_PGM_SUS;

                    if (fmc->MCR.B.ESUS != 0U) /* polyspace RTE:NIV */
                    {
                        *u8Fls_SusStatus = FLS_ERS_SUS_PGM_SUS;
                    }
                } else {
                    *u8Fls_SusStatus = FLS_ERS_SUS;
                }

                /* Wait MCR DONE bit is set */
                while ((fmc->MCR.B.DONE == 0U) && (u32Fls_Count > 0U)) /* polyspace RTE:NIV */
                {
                    u32Fls_Count--;
                }

                /* Set MCR_EHV to 0 */
                fmc->MCR.B.EHV = 0U;
                *fls_ehv_val = 0U;
            }
        }
    }
#endif // RESOURCE_SUPPORT_PFI
    return STATUS_SUCCESS;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif /* FLS_CANCEL_API == STD_ON */


/*
 * @brief FLS_Get_Offset_Select
 *
 * Flash get special block offset and select state.
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_Get_Offset_Select \
( \
    VAR( uint16, AUTOMATIC) u16Fls_FlashBlock, \
    VAR( uint32, AUTOMATIC) u32Fls_Index, \
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) u32Fls_Offset, \
    P2VAR( fls_blksel_t, AUTOMATIC, FLS_APPL_DATA ) pFls_BlkSel)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;

    /* Check index */
    if (u32Fls_Index >= 32U)
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }
    else
    {
        /*
        * clear pFls_BlkSel
        *
        *  */
        pFls_BlkSel->lowBlkSel = 0x0U;
        pFls_BlkSel->midBlkSel = 0x0U;
        pFls_BlkSel->highBlkSel = 0x0U;
    #ifndef RESOURCE_SUPPORT_PFI
        pFls_BlkSel->first256KBlkSel = 0x0U;
        pFls_BlkSel->second256KBlkSel = 0x0U;
    #else
    #ifdef RESOURCE_SUPPORT_PFI0
        pFls_BlkSel->large0BlkSel = 0x0U;
    #endif
    #ifdef RESOURCE_SUPPORT_PFI1
        pFls_BlkSel->large1BlkSel = 0x0U;
    #endif
    #ifdef RESOURCE_SUPPORT_PFI2
        pFls_BlkSel->large2BlkSel = 0x0U;
    #endif
    #ifdef RESOURCE_SUPPORT_PFI3
        pFls_BlkSel->large3BlkSel = 0x0U;
    #endif
    #ifdef RESOURCE_SUPPORT_PFI4
        pFls_BlkSel->large4BlkSel = 0x0U;
    #endif
    #ifdef RESOURCE_SUPPORT_PFI5
        pFls_BlkSel->large5BlkSel = 0x0U;
    #endif
    #endif // RESOURCE_SUPPORT_PFI

        /* Select flash block to erase */
        switch (u16Fls_FlashBlock)
        {
            case FLS_BLK_LOW:
            {
                 *u32Fls_Offset = FLS_LOW_OFFSET;
                pFls_BlkSel->lowBlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_MID:
            {
                *u32Fls_Offset = FLS_MID_OFFSET;
                pFls_BlkSel->midBlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_HIGH:
            {
                *u32Fls_Offset = FLS_HIGH_OFFSET;
                pFls_BlkSel->highBlkSel = (1UL << u32Fls_Index);
                break;
            }
        #ifndef RESOURCE_SUPPORT_PFI
            case FLS_BLK_FIRST_256K:
            {
                *u32Fls_Offset = FLS_256K_FIRST_OFFSET;
                pFls_BlkSel->first256KBlkSel = (1UL << u32Fls_Index);
                break;
            }
            case FLS_BLK_SECOND_256K:
            {
                *u32Fls_Offset = FLS_256K_SECOND_OFFSET;
                pFls_BlkSel->second256KBlkSel = (1UL << u32Fls_Index);
                break;
            }
        #else
        #ifdef RESOURCE_SUPPORT_PFI0
            case FLS_BLK_LARGE0_256K:
            {
                *u32Fls_Offset = FLS_256K_LARGE0_OFFSET;
                pFls_BlkSel->large0BlkSel = (1UL << u32Fls_Index);
                break;
            }
        #endif
        #ifdef RESOURCE_SUPPORT_PFI1
            case FLS_BLK_LARGE1_256K:
            {
                *u32Fls_Offset = FLS_256K_LARGE1_OFFSET;
                pFls_BlkSel->large1BlkSel = (1UL << u32Fls_Index);
                break;
            }
        #endif
        #ifdef RESOURCE_SUPPORT_PFI2
            case FLS_BLK_LARGE2_256K: 
            {
                *u32Fls_Offset = FLS_256K_LARGE2_OFFSET;
                pFls_BlkSel->large2BlkSel = (1UL << u32Fls_Index);
                break;
            }
        #endif
        #ifdef RESOURCE_SUPPORT_PFI3
            case FLS_BLK_LARGE3_256K:  
            {
                *u32Fls_Offset = FLS_256K_LARGE3_OFFSET;
                pFls_BlkSel->large3BlkSel = (1UL << u32Fls_Index);
                break;
            }
        #endif
        #ifdef RESOURCE_SUPPORT_PFI4
            case FLS_BLK_LARGE4_256K:   
            {
                *u32Fls_Offset = FLS_256K_LARGE4_OFFSET;
                pFls_BlkSel->large4BlkSel = (1UL << u32Fls_Index);
                break;
            }
        #endif
        #ifdef RESOURCE_SUPPORT_PFI5
            case FLS_BLK_LARGE5_256K: 
            {
                *u32Fls_Offset = FLS_256K_LARGE5_OFFSET;
                pFls_BlkSel->large5BlkSel = (1UL << u32Fls_Index);
                break;
            }
        #endif
        #endif // RESOURCE_SUPPORT_PFI
            default:
            {
                sFls_Ret = STATUS_ERROR;
                break;
            }
        }
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( uint32, FLS_CODE ) FLS_SDK_LLD_GetInterWriteAddr(const fls_blksel_t * pFls_BlkSel)
{
    VAR( uint8, AUTOMATIC) u8Fls_Index = 0U;
    VAR( uint8, AUTOMATIC) u8Fls_Offset = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Addr = 0U;

    if (pFls_BlkSel->lowBlkSel > 0U)
    {
        u8Fls_Offset = FLS_LOW_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_LOW_BLOCK; u8Fls_Index++)
        {
            if (((pFls_BlkSel->lowBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart; /* PRQA S 2985 */
                break;
            }
        }
    }
#if FLS_MID_BLOCK > 0U
    else if (pFls_BlkSel->midBlkSel > 0U)
    {
        u8Fls_Offset = FLS_MID_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_MID_BLOCK; u8Fls_Index++)
        {
            if (((pFls_BlkSel->midBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
#endif
	#if !defined(CCFC3008PC) && !defined(CCFC3008PCSN) && !defined(CCFC3008PCSA)
    else if (pFls_BlkSel->highBlkSel > 0U)
    {
        u8Fls_Offset = FLS_HIGH_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_HIGH_BLOCK; u8Fls_Index++)
        {
            if (((pFls_BlkSel->highBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
	#endif
	#ifndef RESOURCE_SUPPORT_PFI
    else if (pFls_BlkSel->first256KBlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_FIRST_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_FIRST; u8Fls_Index++)
        {
            if (((pFls_BlkSel->first256KBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
#if (FLS_256K_BLOCK_SECOND != 0U)
    else if (pFls_BlkSel->second256KBlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_SECOND_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_SECOND; u8Fls_Index++)
        {
            if (((pFls_BlkSel->second256KBlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
#endif
#else
    #ifdef RESOURCE_SUPPORT_PFI0
    else if (pFls_BlkSel->large0BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE0_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE0; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large0BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI0
    #ifdef RESOURCE_SUPPORT_PFI1
    else if (pFls_BlkSel->large1BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE1_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE1; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large1BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI1
    #ifdef RESOURCE_SUPPORT_PFI2
    else if (pFls_BlkSel->large2BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE2_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE2; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large2BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI2
    #ifdef RESOURCE_SUPPORT_PFI3
    else if (pFls_BlkSel->large3BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE3_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE3; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large3BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI3
    #ifdef RESOURCE_SUPPORT_PFI4
    else if (pFls_BlkSel->large4BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE4_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE4; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large4BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI4
    #ifdef RESOURCE_SUPPORT_PFI5
    else if (pFls_BlkSel->large5BlkSel > 0U)
    {
        u8Fls_Offset = FLS_256K_LARGE5_OFFSET;
        for (u8Fls_Index = 0U; u8Fls_Index < FLS_256K_BLOCK_LARGE5; u8Fls_Index++)
        {
            if (((pFls_BlkSel->large5BlkSel & (1UL << u8Fls_Index)) >> u8Fls_Index) == 1UL)
            {
                u32Fls_Addr = flashInfo[u8Fls_Index + u8Fls_Offset].addrStart;
                break;
            }
        }
    }
    #endif // RESOURCE_SUPPORT_PFI5
#endif // RESOURCE_SUPPORT_PFI
    else
    {
    }

    return u32Fls_Addr;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( void, FLS_CODE ) FLS_SDK_LLD_DCacheInvalid(void) /* PRQA S 3006 */
{

#ifdef DCACHE_ENABLE
	CACHE_LLD_InvalidateDcache();
#endif

}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/*
 * @brief Execute program operation
 *
 * This function will do program operation
 *
 * @param[in] pFls_CtxData Storing context variables.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_PgmExec \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_SrcIndex = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Temp = 0U;

    if (0U != pFls_CtxData->u32Fls_Size)
    {
        /* Set MCR_PGM to start program operation */
        FLS_FMC.MCR.B.PGM = 1U;

        if (FLS_FMC.MCR.B.PGM == 0U)
        {
            sFls_Ret = STATUS_FLASH_ERROR_ENABLE;
        }
        else
        {
            /* Compute the buffer u32Fls_Size used in the program cycle and calculate number of word for interlock write */
            if (pFls_CtxData->u32Fls_Size > FLS_SDK_PROGRAMABLE_SIZE)
            {
                u32Fls_Temp = FLS_SDK_PROGRAMABLE_SIZE / FLS_SDK_WORD_SIZE;
            }
            else
            {
                u32Fls_Temp = pFls_CtxData->u32Fls_Size / FLS_SDK_WORD_SIZE;
            }

            /* Program data */
            for (u32Fls_SrcIndex = 0U; u32Fls_SrcIndex < u32Fls_Temp; u32Fls_SrcIndex++)
            {
                /* Programming write */
                *(volatile uint32 *)(pFls_CtxData->u32Fls_Dest) /*polyspace RTE:IDP,NIV*/ 
                    = *(volatile uint32 *)(pFls_CtxData->u32Fls_Src); /*polyspace RTE:IDP,NIV*/
                
                /* Update u32Fls_Dest, u32Fls_Size, source index */
                pFls_CtxData->u32Fls_Dest += FLS_SDK_WORD_SIZE;
                pFls_CtxData->u32Fls_Src += FLS_SDK_WORD_SIZE;
                pFls_CtxData->u32Fls_Size -= FLS_SDK_WORD_SIZE;

                /* Is it time to do page programming?  */
                if (0U == (pFls_CtxData->u32Fls_Dest % FLS_SDK_PROGRAMABLE_SIZE))
                {
                    break;
                }
            }
            
            /* Set MCR_EHV bit */
            if (FLS_OP_SYNC == pFls_CtxData->u32Fls_Mode)
            {
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )                   
                pFls_AcCodePtr(&u32Fls_TimerCounterAC);  /*polyspace RTE:COR*/
                if( 0U == u32Fls_TimerCounterAC )
                {
                    sFls_Ret = STATUS_TIMEOUT;
                    Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                }
            #else
                pFls_AcCodePtr();
            #endif
            }
            else
            {
                FLS_FMC.MCR.B.EHV = 1U;
            }
        }
    }
    else
    {
    }
	return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_PgmExec
(
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData ,\
    volatile struct C55FMC_tag *fmc
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_SrcIndex = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Temp = 0U;

    if (0U != pFls_CtxData->u32Fls_Size)
    {
        /* Set MCR_PGM to start program operation */
        fmc->MCR.B.PGM = 1U;

        if (fmc->MCR.B.PGM == 0U)
        {
            sFls_Ret = STATUS_FLASH_ERROR_ENABLE;
        }
        else
        {
          
            /* Compute the buffer size used in the program cycle and calculate number of word for interlock write */
            if (pFls_CtxData->u32Fls_Size > FLS_SDK_PROGRAMABLE_SIZE)
            {
                u32Fls_Temp = FLS_SDK_PROGRAMABLE_SIZE / FLS_SDK_WORD_SIZE;
            }
            else
            {
                u32Fls_Temp = pFls_CtxData->u32Fls_Size / FLS_SDK_WORD_SIZE;
            }

            /* Program data */
            for (u32Fls_SrcIndex = 0U; u32Fls_SrcIndex < u32Fls_Temp; u32Fls_SrcIndex++)
            {
                /* Programming write */
                *(volatile uint32_t *)(pFls_CtxData->u32Fls_Dest) = *(volatile uint32_t *)(pFls_CtxData->u32Fls_Src); /*polyspace RTE:IDP,NIV*/ 
                /* Update u32Fls_Dest, size, source index */
                pFls_CtxData->u32Fls_Dest += FLS_SDK_WORD_SIZE;
                pFls_CtxData->u32Fls_Src += FLS_SDK_WORD_SIZE;
                pFls_CtxData->u32Fls_Size -= FLS_SDK_WORD_SIZE;

                /* Is it time to do page programming?  */
                if (0U == (pFls_CtxData->u32Fls_Dest % FLS_SDK_PROGRAMABLE_SIZE))
                {
                    break;
                }
            }

            /* Set MCR_EHV bit */
            if (FLS_OP_SYNC == pFls_CtxData->u32Fls_Mode)
                {
                   #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )                   
                    pFls_AcCodePtr(&u32Fls_TimerCounterAC,fmc); /*polyspace RTE:COR*/
                    if( 0U == u32Fls_TimerCounterAC )
                    {
                        sFls_Ret = STATUS_TIMEOUT;
                        Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                    }
                    #else
                        pFls_AcCodePtr(fmc);
                    #endif
                }
            else
            {
                fmc->MCR.B.EHV = 1U;
            }
        }
    }
    else
    {
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Check the status of flash erase operate
 *
 * This function will check the status of ongoing high voltage in erase
 *
 * @param[out] pFls_Status The status of flash erase after calling the function.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_CheckErsExec(uint8 * pFls_Status)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    *pFls_Status = FLS_OK;

    /* Check EGOOD (PEG) */
    if (FLS_FMC.MCR.B.PEG != 0U)
    {
        /* Clear EHV if it is high */
        if ( (FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U) )
        {
            /* Clear EHV */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
        }
        else
        {
            *pFls_Status = FLS_ERS_WRITE;
        }
    }
    else
    {
        /* EGOOD (PEG) is low */
        sFls_Ret = STATUS_ERROR;

        /* Clear EHV if it is high */
        if ( (FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U) )
        {
            /* Clear EHV */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
        }
    }

    if (*pFls_Status != FLS_ERS_WRITE)
    {
        /* Clear ERS */
        FLS_FMC.MCR.B.ERS = 0U;
        /* Disable Cache */
        PFLASH.PFCR1.B.P0_BFEN = 0U;
        PFLASH.PFCR2.B.P1_BFEN = 0U;
        /* Enable Cache */
        PFLASH.PFCR1.B.P0_BFEN = 1U;
        PFLASH.PFCR2.B.P1_BFEN = 1U;
    }
    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_CheckErsExec(uint8_t * pFls_Status, volatile struct C55FMC_tag * fmc)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) fls_ehv_val ;
    sFls_Ret = FLS_LLD_Get_FLS_EHV_Val(fmc, &fls_ehv_val);
    if(sFls_Ret != STATUS_SUCCESS)
    {
    	return sFls_Ret;
    }
    *pFls_Status = FLS_OK;

    /* Check EGOOD (PEG) */
    if (fmc->MCR.B.PEG != 0U) /*polyspace RTE:NIV*/
    {
        /* Clear EHV if it is high */
        if ( (fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U) ) /*polyspace RTE:NIV*/
        {
            /* Clear EHV */
            fmc->MCR.B.EHV = 0U;
            *fls_ehv_val = 0U;
        }
        else
        {
            *pFls_Status = FLS_ERS_WRITE;
        }
    }
    else
    {
        /* EGOOD (PEG) is low */
    	sFls_Ret = STATUS_ERROR;

        /* Clear EHV if it is high */
        if ( (fmc->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U) ) /*polyspace RTE:NIV*/
        {
            /* Clear EHV */
            fmc->MCR.B.EHV = 0U;
            *fls_ehv_val = 0U;
        }
    }

    if (*pFls_Status != FLS_ERS_WRITE)
    {
        volatile struct PFLASH_tag *pflash = NULL;

        /* Clear ERS */
        fmc->MCR.B.ERS = 0U;
        /* Enable Cache */
        sFls_Ret = FLS_LLD_GetMappedPFlash(fmc, &pflash);
	 	if((pflash == NULL) || (sFls_Ret != STATUS_SUCCESS) )
		{
			sFls_Ret = STATUS_ERROR;
		}
		else
		{
            pflash->PFCR1.B.P0_BFEN = 0U;
            pflash->PFCR2.B.P1_BFEN = 0U;

			pflash->PFCR1.B.P0_BFEN = 1U;
            pflash->PFCR2.B.P1_BFEN = 1U;
		}
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif //RESOURCE_SUPPORT_PFI

/*
 * @brief Check the erase operation
 *
 * This function will check the status of ongoing erase operation.
 *
 * @param[out] pFls_OpRet: Return the state of flash.
 * @return Operation status
 */


#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckEraseStatus \
( \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;

#ifdef RESOURCE_SUPPORT_PFI
    uint32 u32fls_index = 0U;
    uint32 u32fls_ers_num = 0U;

#endif // RESOURCE_SUPPORT_PFI
    if (pFls_OpRet == NULL)
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    *pFls_OpRet = FLS_OK;

#ifndef RESOURCE_SUPPORT_PFI
    /* There must be an erase operation */
    if (FLS_FMC.MCR.B.ERS != 0U)
    {
        /* If DONE bit goes high */
        if (FLS_FMC.MCR.B.DONE != 0U)
        {
            /* If the operation is suspended */
            if (FLS_FMC.MCR.B.ESUS != 0U)
            {
                *pFls_OpRet = FLS_ERS_SUS;
            }
            else
            {
                sFls_Ret = FLS_SDK_LLD_CheckErsExec(pFls_OpRet);
            }

        }
        else
        {
 			#if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            u32Fls_TimerCounterAC--;
            if( 0U == u32Fls_TimerCounterAC )
            {
                /* Specification of Flash Driver : [SWS_Fls_00361] */
                /* Specification of Flash Driver : [SWS_Fls_00360] */
                sFls_Ret = STATUS_TIMEOUT;
                Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                u32Fls_TimerCounterAC = FLS_ASYNC_ERASE_TIMEOUT_VALUE;
            }
            else
            {
            #endif
                sFls_Ret = STATUS_FLASH_INPROGRESS;
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            }
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            
           
        }
    }
    else
	{
		sFls_Ret = STATUS_INITIALIZED;
	}
#else
    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++)
    {

        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[u32fls_index];

        if (fmc == NULL)
        {
            u32fls_ers_num = u32fls_ers_num + 1U;
            continue;
        }

        /* There must be an erase operation */
        if (fmc->MCR.B.ERS != 0U)  /*polyspace RTE:IDP,NIV*/
        {
            /* If DONE bit goes high */
            if (fmc->MCR.B.DONE != 0U) /*polyspace RTE:NIV*/
            {
                 /* Make the erased flash space in DCache invalid */
                FLS_SDK_LLD_DCacheInvalid();
                /* If the operation is suspended */
                if (fmc->MCR.B.ESUS != 0U)  /*polyspace RTE:NIV*/
				{
                    *pFls_OpRet = FLS_ERS_SUS;
                    break;
				}
				else 
				{
                   sFls_Ret = FLS_SDK_LLD_CheckErsExec(pFls_OpRet, fmc);

                    if (sFls_Ret != STATUS_SUCCESS) 
					{
                        break;
                    }
                }
            }
            else
            {
                /* DONE bit is still low means the operation is in-progress */
                 #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
                    u32Fls_TimerCounterAC--;
                    if( 0U == u32Fls_TimerCounterAC )
                    {
                        /* Specification of Flash Driver : [SWS_Fls_00361] */
                        /* Specification of Flash Driver : [SWS_Fls_00360] */
                        sFls_Ret = STATUS_TIMEOUT;
                        Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                        u32Fls_TimerCounterAC = FLS_ASYNC_ERASE_TIMEOUT_VALUE;
                        break;
                    }
                    else
                    {
                    #endif
                        sFls_Ret = STATUS_FLASH_INPROGRESS;
                        break;
                    #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )	
                    }
                    #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
               
            }
        }
        else
        {
            u32fls_ers_num = u32fls_ers_num + 1U;
        }
    }
    if (u32fls_ers_num >= FLS_CONTROLLER_NUM)
    {
        sFls_Ret = STATUS_INITIALIZED;
    }
    else
    {
    }
    
#endif // RESOURCE_SUPPORT_PFI

    return sFls_Ret;
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"







/*
 * @brief Program operation for flash
 *
 * This function is to do program operation for flash.
 *
 * @param[in] pFls_CtxData: Storing context variables.
 * @return Operation status
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Program \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;

#ifdef RESOURCE_SUPPORT_PFI
    VAR( uint32, AUTOMATIC) u32Fls_count = 0U;
#endif // RESOURCE_SUPPORT_PFI

    if ( (pFls_CtxData == NULL) || ((pFls_CtxData->u32Fls_Dest % FLS_SDK_DWORD_SIZE) != 0U) \
        || ((pFls_CtxData->u32Fls_Size % FLS_SDK_DWORD_SIZE) != 0U) )
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

#ifndef RESOURCE_SUPPORT_PFI
    if (((FLS_FMC.MCR.B.PGM != 0U) && ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_FMC.MCR.B.PSUS != 0U))) \
        || ((FLS_FMC.MCR.B.ERS != 0U) && (FLS_FMC.MCR.B.ESUS == 0U)))
    {
        /*
         * Return busy: program in progress, program in suspended, erase in progress
         * */
        sFls_Ret = STATUS_BUSY;
    }
    else
    {
        /*
         * Do program: no program and erase, erase_suspend and EHV is low
         * */
        sFls_Ret = FLS_SDK_LLD_PgmExec(pFls_CtxData);
    }

#else
    /* Obtain the controller corresponding to the target address */
    for (u32Fls_count = 0; u32Fls_count < FLS_BLOCK_ALL; u32Fls_count++) 
	{
        uint32_t addr_start = flashInfo[u32Fls_count].addrStart;
        uint32_t addr_end   = flashInfo[u32Fls_count].addrEnd;

        if ((addr_start <= pFls_CtxData->u32Fls_Dest) && ((pFls_CtxData->u32Fls_Dest ) <= addr_end))
         {  
            volatile struct C55FMC_tag *fmc = NULL;

            FLS_SDK_LLD_GetBlockController(u32Fls_count, &fmc);
            if(fmc ==NULL_PTR)
            {
                sFls_Ret = STATUS_ERROR;
                break;
            }

            if (((fmc->MCR.B.PGM != 0U) && ((fmc->MCR.B.EHV != 0U) || (fmc->MCR.B.PSUS != 0U))) || /*polyspace RTE:NIV*/
                 ((fmc->MCR.B.ERS != 0U) && (fmc->MCR.B.ESUS == 0U))) /*polyspace RTE:NIV*/
            {
                /*
                * Return busy: program in progress, program in suspended, erase in progress
                * */
                sFls_Ret = STATUS_BUSY;
            }
            else
            {
                /*
                * Do program: no program and erase, erase_suspend and EHV is low
                * */
                if ((FLS_OpPFMC != NULL) && (FLS_OpPFMC != fmc)) {
                    FLS_OpPFMC->MCR.B.PGM = 0U;
                }

                FLS_OpPFMC = fmc;
                sFls_Ret = FLS_SDK_LLD_PgmExec(pFls_CtxData, fmc);
            }
            break;
        }
    }

    if (u32Fls_count == FLS_BLOCK_ALL) {
        sFls_Ret = STATUS_ERROR;
    }
#endif // RESOURCE_SUPPORT_PFI
    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"


/*
 * @brief Check the status of flash program operate
 *
 * This function will check the status of ongoing high voltage in program
 *
 * @param[in] pFls_CtxData Storing context variables.
 * @param[out] pFls_Status The status of flash program after calling the function.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLS_SDK_LLD_CheckPgmExec \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    uint8 * pFls_Status \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    *pFls_Status = FLS_OK;

    /* check PEG */
    if (FLS_FMC.MCR.B.PEG != 0U) /* PEG is high */
    {
        /* Clear EHV if it is high */
        if ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U))
        {
            /* Clear EHV */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
            /* If there is remaining data needs to be programmed */
            if ((pFls_CtxData->u32Fls_Size) != 0x0U)  /* polyspace RTE:NIV */
            {
                /* Call FLASH_LLD_Program to continue the operation */
                sFls_Ret = FLASH_SDK_LLD_Program(pFls_CtxData);

                if (sFls_Ret == STATUS_SUCCESS)
                {
                    sFls_Ret = STATUS_FLASH_INPROGRESS;
                }
            }
            else /* pFls_CtxData->u32Fls_Size == 0 */
            {
                /* Program finished successfully, clear PGM */
                FLS_FMC.MCR.B.PGM = 0U;
                /* Disable Cache */
                PFLASH.PFCR1.B.P0_BFEN = 0U;
                PFLASH.PFCR2.B.P1_BFEN = 0U;
                /* Enable Cache */
                PFLASH.PFCR1.B.P0_BFEN = 1U;
                PFLASH.PFCR2.B.P1_BFEN = 1U;
            }
        }
        else /* EHV == 0 */
        {
            if (FLS_FMC.MCR.B.ERS != 0U)
            {
                *pFls_Status = FLS_ERS_SUS_PGM_WRITE;
            }
            else
            {
                *pFls_Status = FLS_PGM_WRITE;
            }
        }
    }
    else /* PEG is low */
    {
        if ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_EHV_Val == 1U))
        {
            /* Clear EHV */
            FLS_FMC.MCR.B.EHV = 0U;
            FLS_EHV_Val = 0U;
        }
        else /* EHV == 0 */
        {
            /* PEG is invalid at this stage */
            if (FLS_FMC.MCR.B.ERS != 0U)
            {
                *pFls_Status = FLS_ERS_SUS_PGM_WRITE;
            }
            else
            {
                *pFls_Status = FLS_PGM_WRITE;
            }
        }
        /* Program finished unsuccessfully, clear PGM */
        FLS_FMC.MCR.B.PGM = 0U;
        sFls_Ret = STATUS_ERROR;
        /* Disable Cache */
        PFLASH.PFCR1.B.P0_BFEN = 0U;
        PFLASH.PFCR2.B.P1_BFEN = 0U;
        /* Enable Cache */
        PFLASH.PFCR1.B.P0_BFEN = 1U;
        PFLASH.PFCR2.B.P1_BFEN = 1U;
    }
    return  sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE )  FLS_SDK_LLD_CheckPgmExec
(
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    uint8 * pFls_Status \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) fls_ehv_val ;
    sFls_Ret = FLS_LLD_Get_FLS_EHV_Val(FLS_OpPFMC, &fls_ehv_val);
    if((sFls_Ret != STATUS_SUCCESS) || (FLS_OpPFMC == NULL_PTR))
    {
        sFls_Ret = STATUS_ERROR;
    	return sFls_Ret;
    }
    *pFls_Status = FLS_OK;

    /* check PEG */
    if (FLS_OpPFMC->MCR.B.PEG != 0U) /* PEG is high */ /*polyspace RTE:NIV*/
    {
       
        /* Clear EHV if it is high */
        if ((FLS_OpPFMC->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U)) /*polyspace RTE:NIV*/
        {
            /* Clear EHV */
            FLS_OpPFMC->MCR.B.EHV = 0U;
            *fls_ehv_val = 0U;
            /* If there is remaining data needs to be programmed */
            if ((pFls_CtxData->u32Fls_Size) != 0x0U)
            {
                /* Call FLASH_LLD_Program to continue the operation */
                sFls_Ret = FLASH_SDK_LLD_Program(pFls_CtxData);

                if (sFls_Ret == STATUS_SUCCESS)
                {
                    sFls_Ret = STATUS_FLASH_INPROGRESS;
                }
            }
            else /* pFls_CtxData->u32Fls_Size == 0 */
            {
                volatile struct PFLASH_tag *pflash = NULL;
                /* Program finished successfully, clear PGM */
                FLS_OpPFMC->MCR.B.PGM = 0U;

                /* Enable Cache */
                sFls_Ret = FLS_LLD_GetMappedPFlash(FLS_OpPFMC, &pflash);
                if((pflash == NULL) || (sFls_Ret != STATUS_SUCCESS) )
                {
                    sFls_Ret = STATUS_ERROR;
                }
                else
                {
                    pflash->PFCR1.B.P0_BFEN = 0U;
                    pflash->PFCR2.B.P1_BFEN = 0U;
                    pflash->PFCR1.B.P0_BFEN = 1U;
                    pflash->PFCR2.B.P1_BFEN = 1U;

                }
            }
        }
        else /* EHV == 0 */
        {
            if (FLS_OpPFMC->MCR.B.ERS != 0U) /*polyspace RTE:NIV*/
            {
                *pFls_Status = FLS_ERS_SUS_PGM_WRITE;
            }
            else
            {
                *pFls_Status = FLS_PGM_WRITE;
            }
        }
    }
    else /* PEG is low */
    {
        volatile struct PFLASH_tag *pflash = NULL;
        
        if ((FLS_OpPFMC->MCR.B.EHV != 0U) || (*fls_ehv_val == 1U)) /*polyspace RTE:NIV*/
        {
            /* Clear EHV */
            FLS_OpPFMC->MCR.B.EHV = 0U;
            *fls_ehv_val = 0U;
        }
        else /* EHV == 0 */
        {
            /* PEG is invalid at this stage */
            if (FLS_OpPFMC->MCR.B.ERS != 0U) /*polyspace RTE:NIV*/
            {
                *pFls_Status = FLS_ERS_SUS_PGM_WRITE;
            }
            else
            {
                *pFls_Status = FLS_PGM_WRITE;
            }
        }
        /* Program finished unsuccessfully, clear PGM */
        FLS_OpPFMC->MCR.B.PGM = 0U;

        sFls_Ret = STATUS_ERROR;
        
        /* Enable Cache */
        sFls_Ret = FLS_LLD_GetMappedPFlash(FLS_OpPFMC, &pflash);
		if((pflash == NULL) || (sFls_Ret != STATUS_SUCCESS) )
		{
			sFls_Ret = STATUS_ERROR;
		}
		else
		{
            pflash->PFCR1.B.P0_BFEN = 0U;
            pflash->PFCR2.B.P1_BFEN = 0U;
			pflash->PFCR1.B.P0_BFEN = 1U;
	        pflash->PFCR2.B.P1_BFEN = 1U;
		}
        
       
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
 
#endif // RESOURCE_SUPPORT_PFI

/*
 * @brief Check the program operation
 *
 * This function will check the status of ongoing program operation.
 *
 * @param[in] pFls_CtxData: Storing context variables.
 * @param[out] pFls_OpRet: Return the status of flash.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckProgramStatus \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    if ( (pFls_CtxData == NULL) || (pFls_OpRet == NULL))
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    *pFls_OpRet = FLS_OK;

    /* There must be a program operation */
    if (FLS_FMC.MCR.B.PGM != 0U)
    {
        /* If DONE bit goes high */
        if (FLS_FMC.MCR.B.DONE != 0U)
        {
            /* If the operation is suspended */
            if (FLS_FMC.MCR.B.PSUS != 0U)
            {
                /* Check if the suspended program is PGM_SUS or ERS_SUS_PGM_SUS */
                if (FLS_FMC.MCR.B.ERS != 0U)
                {
                    *pFls_OpRet = FLS_ERS_SUS_PGM_SUS;
                }
                else
                {
                    *pFls_OpRet = FLS_PGM_SUS;
                }
            }
            else
            {
                sFls_Ret = FLS_SDK_LLD_CheckPgmExec(pFls_CtxData, pFls_OpRet);
            }
        }
        else
        {
            /* DONE bit is still low means the operation is in-progress */
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            u32Fls_TimerCounterAC--;
            if( 0U == u32Fls_TimerCounterAC )
            {
                /* Specification of Flash Driver : [SWS_Fls_00361] */
                /* Specification of Flash Driver : [SWS_Fls_00362] */
				sFls_Ret = STATUS_TIMEOUT;
                Fls_ReportRuntimeError(FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
				 u32Fls_TimerCounterAC = FLS_ASYNC_WRITE_TIMEOUT_VALUE;
            }
			else 
			{
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            	sFls_Ret = STATUS_FLASH_INPROGRESS; 
			#if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            }
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            
        }
    
    }
    else
    {
        sFls_Ret = STATUS_INITIALIZED;
    }
	return sFls_Ret;
	}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_CheckProgramStatus \
( \
    P2VAR( fls_ctxdata_t, AUTOMATIC, FLS_APPL_DATA ) pFls_CtxData, \
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pFls_OpRet \
)

{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;

    if ( (pFls_CtxData == NULL) || (pFls_OpRet == NULL))
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    *pFls_OpRet = FLS_OK;
    /* There must be a program operation */
    if ((FLS_OpPFMC != NULL) && (FLS_OpPFMC->MCR.B.PGM != 0U))  /*polyspace RTE:NIV*/
    {
        /* If DONE bit goes high */
        if (FLS_OpPFMC->MCR.B.DONE != 0U) /*polyspace RTE:NIV*/
        {
            /* If the operation is suspended */
            if (FLS_OpPFMC->MCR.B.PSUS != 0U) /*polyspace RTE:NIV*/
            {
                /* Check if the suspended program is PGM_SUS or ERS_SUS_PGM_SUS */
                if (FLS_OpPFMC->MCR.B.ERS != 0U) /*polyspace RTE:NIV*/
                {
                    *pFls_OpRet = FLS_ERS_SUS_PGM_SUS;
                }
                else
                {
                    *pFls_OpRet = FLS_PGM_SUS;
                }
            }
            else
            {
                
            	sFls_Ret = FLS_SDK_LLD_CheckPgmExec(pFls_CtxData, pFls_OpRet);
               
            }
        }
        else
        {
            /* DONE bit is still low means the operation is in-progress */
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )
            u32Fls_TimerCounterAC--;
            if( 0U == u32Fls_TimerCounterAC )
            {
                /* Specification of Flash Driver : [SWS_Fls_00361] */
                /* Specification of Flash Driver : [SWS_Fls_00362] */
                sFls_Ret = STATUS_TIMEOUT;
                Fls_ReportRuntimeError(FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                u32Fls_TimerCounterAC = FLS_ASYNC_WRITE_TIMEOUT_VALUE;
            }
            else
            {
            #endif
                sFls_Ret = STATUS_FLASH_INPROGRESS;
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )	
            }
            #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
        }
    }
    else 
    {
        sFls_Ret = STATUS_INITIALIZED;
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif // RESOURCE_SUPPORT_PFI
   
/*
 * @brief Erase the selected flash block
 *
 * This function is to do erase operation for selected flash block.
 *
 * @param[in] u8Fls_EraseSpace: Select flash main space.
 * @param[in] pFls_BlkSel: Select the special flash block for erasing.
 * @param[in] u32Fls_Mode: means the operate u32Fls_Mode of erase.
              FLS_OP_SYNC: means sync erase operate.
              FLS_OP_ASYNC: means async erase operate.
 * @return Operation status
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FLS_INLINE FUNC( status_t, FLS_CODE ) FLASH_SDK_LLD_Erase \
( \
    VAR( uint8, AUTOMATIC ) u8Fls_EraseSpace, \
    P2VAR( fls_blksel_t, AUTOMATIC, FLS_APPL_DATA ) pFls_BlkSel, \
    VAR( uint32, AUTOMATIC) u32Fls_Mode \
)
{
    VAR( status_t, AUTOMATIC)  sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC)  u32Fls_InterlockWriteAddress = 0U;

#ifdef RESOURCE_SUPPORT_PFI
    uint32 u32fls_index = 0U, u32fls_index1 = 0U;
#endif // RESOURCE_SUPPORT_PFI
    if (pFls_BlkSel == NULL)
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }
    /* Check for validity of erase option */
    if (u8Fls_EraseSpace != FLS_ERS_MAIN_SPACE)
    {
    	sFls_Ret = STATUS_ERROR;
		return sFls_Ret;

    }

    pFls_BlkSel->lowBlkSel &= FLS_SEL_MASK_LOW;
#if FLS_MID_BLOCK > 0U
	pFls_BlkSel->midBlkSel &= FLS_SEL_MASK_MID;
#endif
#if !defined(CCFC3008PC) && !defined(CCFC3008PCSA)
	pFls_BlkSel->highBlkSel &= FLS_SEL_MASK_HIGH;
#endif
#ifndef RESOURCE_SUPPORT_PFI

	pFls_BlkSel->first256KBlkSel &= FLS_SEL_MASK_FIR256K; /* PRQA S 2985 */
	pFls_BlkSel->second256KBlkSel &= FLS_SEL_MASK_SEC256K;
    u32Fls_InterlockWriteAddress = FLS_SDK_LLD_GetInterWriteAddr(pFls_BlkSel);
	if (0U == u32Fls_InterlockWriteAddress)
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    if ((FLS_FMC.MCR.B.PGM != 0U) || ((FLS_FMC.MCR.B.ERS != 0U) \
        && ((FLS_FMC.MCR.B.EHV != 0U) || (FLS_FMC.MCR.B.ESUS != 0U))))
    {
        sFls_Ret = STATUS_BUSY;
    }
    else
    {
        /* Set MCR_ERS to start erase operation */
        FLS_FMC.MCR.B.ERS = 1U;

        if (FLS_FMC.MCR.B.ERS == 0U)
        {
            sFls_Ret = STATUS_FLASH_ERROR_ENABLE;
        }
        else
        {
            /* No blocks to be selected for erase, just return */
            if ((pFls_BlkSel->lowBlkSel | pFls_BlkSel->midBlkSel | pFls_BlkSel->highBlkSel \
                | pFls_BlkSel->first256KBlkSel | pFls_BlkSel->second256KBlkSel) == 0U) /* PRQA S 2992, 2996 */
            {
                /* Return with STATUS_SUCCESS */
                FLS_FMC.MCR.B.ERS = 0U;
            }
            else
            {
                /* Set the block selection registers */
                #if defined(CCFC3008PC)
                FLS_FMC.SEL0.B.LOWSEL = ((pFls_BlkSel->lowBlkSel & 0xFU) << 1U) | ((pFls_BlkSel->lowBlkSel & 0xF0U) << 2U);
                #elif defined(CCFC3008PCSN)
                FLS_FMC.SEL0.B.LOWSEL = pFls_BlkSel->lowBlkSel & FLS_SEL_MASK_LOW0;
                FLS_FMC.SEL1.B.LOWSEL = (pFls_BlkSel->lowBlkSel >> FLS_LOCK_OFFSET_LOW) & FLS_LOCK_MASK_LOW1;
                #else
                FLS_FMC.SEL0.B.LOWSEL = pFls_BlkSel->lowBlkSel;
                #endif // CCFC3008PC || CCFC3008PCSN

            #ifdef CCFC3007BC
                FLS_FMC.SEL0.B.MIDSEL = pFls_BlkSel->midBlkSel << FLS_LOCK_OFFSET_MID;
            #else
				#ifndef CCFC3008PCSA
                FLS_FMC.SEL0.B.MIDSEL = pFls_BlkSel->midBlkSel;
				#endif
            #endif // CCFC3007BC

            #if !defined(CCFC3008PCSN) && !defined(CCFC3008PCSA)
                FLS_FMC.SEL1.R = pFls_BlkSel->highBlkSel;
            #endif

				#ifdef CCFC3008PT
                /* If Swapped to B partition */
                if (1U == g_swapStatus)
                {
                    FLS_FMC.SEL2.R = (((pFls_BlkSel->first256KBlkSel >> 8U) & 0x000000FFU) /* PRQA S 2985 */
                                      | ((pFls_BlkSel->first256KBlkSel << 8U) & 0x0000FF00U)); 
                }
                else
                {
				#endif
                    FLS_FMC.SEL2.R = pFls_BlkSel->first256KBlkSel;
				#ifdef CCFC3008PT
                }
				#endif
                FLS_FMC.SEL3.R = pFls_BlkSel->second256KBlkSel; /* PRQA S 2985 */
            }
        
            /* Check if ERS bit is set */
            if (FLS_FMC.MCR.B.ERS != 0U)
            {
                /* Interlock write */
                *((volatile uint32*)u32Fls_InterlockWriteAddress) = FLS_ERASED_VALUE;  /*polyspace RTE:IDP*/
                /* Write a 1 to MCR_EHV */
                if (FLS_OP_SYNC == u32Fls_Mode)
                {
                #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )                   
                    pFls_AcCodePtr(&u32Fls_TimerCounterAC);  /*polyspace RTE:COR*/
                    if( 0U == u32Fls_TimerCounterAC )
                    {
                        sFls_Ret = STATUS_TIMEOUT;
                        Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                    }
                #else
                    pFls_AcCodePtr();
                #endif
                }
                else
                {  
                    FLS_FMC.MCR.B.EHV = 1U;
                }
                /* Not wait until MCR_DONE is set */
            }
        }
    }
#else
#if defined(RESOURCE_SUPPORT_PFI0)
    pFls_BlkSel->large0BlkSel &= FLS_SEL_MASK_LARGE0_256K;
#endif

#if defined(RESOURCE_SUPPORT_PFI1)
    pFls_BlkSel->large1BlkSel &= FLS_SEL_MASK_LARGE1_256K;
#endif

#if defined(RESOURCE_SUPPORT_PFI2)
    pFls_BlkSel->large2BlkSel &= FLS_SEL_MASK_LARGE2_256K;
#endif

#if defined(RESOURCE_SUPPORT_PFI3)
    pFls_BlkSel->large3BlkSel &= FLS_SEL_MASK_LARGE3_256K;
#endif

#if defined(RESOURCE_SUPPORT_PFI4)
    pFls_BlkSel->large4BlkSel &= FLS_SEL_MASK_LARGE4_256K;
#endif

#if defined(RESOURCE_SUPPORT_PFI5)
    pFls_BlkSel->large5BlkSel &= FLS_SEL_MASK_LARGE5_256K;
#endif


    fls_blksel_t  blkSelTmp = *pFls_BlkSel; /* PRQA S 3604 */

    /* Get the controller that needs to be operated on */

    cc_memset((uint8_t *)(&FLS_OpEFMC), 0U, sizeof(FLS_OpEFMC));
    if ((pFls_BlkSel->lowBlkSel > 0U) || (pFls_BlkSel->midBlkSel > 0U) || (pFls_BlkSel->highBlkSel > 0U)) {
        FLS_OpEFMC[0] = &FLS_FMC;
    }

    #ifdef RESOURCE_SUPPORT_PFI0
    if (pFls_BlkSel->large0BlkSel > 0U) {
	 	volatile struct C55FMC_tag *controller = NULL;
     	FLS_SDK_LLD_GetMappedController(&FLS_T40FMC0, &controller);
        FLS_OpEFMC[1] = controller;
    }
    #endif // RESOURCE_SUPPORT_PFI0

    #ifdef RESOURCE_SUPPORT_PFI1
    if (pFls_BlkSel->large1BlkSel > 0U) {
       	volatile struct C55FMC_tag *controller = NULL;
       	FLS_SDK_LLD_GetMappedController(&FLS_T40FMC1, &controller);
        FLS_OpEFMC[2] = controller;
    }
    #endif // RESOURCE_SUPPORT_PFI1

    #ifdef RESOURCE_SUPPORT_PFI2
    if (pFls_BlkSel->large2BlkSel > 0U) {
       	volatile struct C55FMC_tag *controller = NULL;
       	FLS_SDK_LLD_GetMappedController(&FLS_T40FMC2, &controller);
        FLS_OpEFMC[3] = controller;
    }
    #endif // RESOURCE_SUPPORT_PFI2

    #ifdef RESOURCE_SUPPORT_PFI3
    if (pFls_BlkSel->large3BlkSel > 0U) {
       	volatile struct C55FMC_tag *controller = NULL;
       	FLS_SDK_LLD_GetMappedController(&FLS_T40FMC3, &controller);
        FLS_OpEFMC[4] = controller;
    }
    #endif // RESOURCE_SUPPORT_PFI3

    #ifdef RESOURCE_SUPPORT_PFI4
    if (pFls_BlkSel->large4BlkSel > 0U) {
       volatile struct C55FMC_tag *controller = NULL;
       FLS_SDK_LLD_GetMappedController(&FLS_T40FMC4, &controller);
        FLS_OpEFMC[5] = controller;
    }
    #endif // RESOURCE_SUPPORT_PFI4

    #ifdef RESOURCE_SUPPORT_PFI5
    if (pFls_BlkSel->large5BlkSel > 0U) {
        volatile struct C55FMC_tag *controller = NULL;
        FLS_SDK_LLD_GetMappedController(&FLS_T40FMC5, &controller);
        FLS_OpEFMC[6] = controller;
    }
    #endif // RESOURCE_SUPPORT_PFI5
    /* Check parameters */
    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++)
    {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[u32fls_index];

        if (fmc == NULL) {
            continue;
        }

        /* Check busy */
        if ((fmc->MCR.B.PGM != 0U) || ((fmc->MCR.B.ERS != 0U) && ((fmc->MCR.B.EHV != 0U) || (fmc->MCR.B.ESUS != 0U)))) /* polyspace RTE:IDP,NIV*/  
        {
            sFls_Ret = STATUS_BUSY;
            return sFls_Ret;
        }
        /* Set MCR_ERS to start erase operation */
        fmc->MCR.B.ERS = 1U;

        if (fmc->MCR.B.ERS == 0U)
        {
            for (u32fls_index1 = 0U; u32fls_index1 < u32fls_index; u32fls_index1++)
            {
                fmc = FLS_OpEFMC[u32fls_index1];

                if (fmc != NULL) {
                    fmc->MCR.B.ERS = 0U;/* polyspace RTE:IDP*/  
                }
            }

            sFls_Ret = STATUS_FLASH_ERROR_ENABLE;
            return sFls_Ret;
        }
    }
    /* Execute erase */
    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++) 
    {
        volatile struct C55FMC_tag *fmc = FLS_OpEFMC[u32fls_index];
        volatile struct C55FMC_tag *recovered_fmc = NULL;

        if (fmc == NULL) {
            continue;
        }

        u32Fls_InterlockWriteAddress = FLS_SDK_LLD_GetInterWriteAddr(&blkSelTmp);

        FLS_SDK_LLD_GetMappedController(fmc, &recovered_fmc);
        if (fmc == &FLS_FMC)
        {
            blkSelTmp.lowBlkSel = 0;
            blkSelTmp.midBlkSel = 0;
            blkSelTmp.highBlkSel = 0;

            /* Set the block selection registers */
            FLS_FMC.SEL0.B.LOWSEL = pFls_BlkSel->lowBlkSel;
            FLS_FMC.SEL0.B.MIDSEL = pFls_BlkSel->midBlkSel << FLS_LOCK_OFFSET_MID;
            FLS_FMC.SEL1.B.HIGHSEL = pFls_BlkSel->highBlkSel;
        } 
		#ifdef RESOURCE_SUPPORT_PFI0
		else if (recovered_fmc == & FLS_T40FMC0) 
		{
            blkSelTmp.large0BlkSel = 0;

            /* Set the block selection registers */
             fmc->SEL2.B.A256KSEL = pFls_BlkSel->large0BlkSel;/* polyspace RTE:IDP*/
        }
		 #endif // RESOURCE_SUPPORT_PFI0
		 #ifdef RESOURCE_SUPPORT_PFI1 
		 else if (recovered_fmc == & FLS_T40FMC1) 
		 {
            blkSelTmp.large1BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = pFls_BlkSel->large1BlkSel;/* polyspace RTE:IDP*/
        } 
		 #endif // RESOURCE_SUPPORT_PFI1
		#ifdef RESOURCE_SUPPORT_PFI2
		else if (recovered_fmc == & FLS_T40FMC2) 
		{
            blkSelTmp.large2BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = pFls_BlkSel->large2BlkSel;/* polyspace RTE:IDP*/
        } 
		  #endif // RESOURCE_SUPPORT_PFI2
		  #ifdef RESOURCE_SUPPORT_PFI3
		else if (recovered_fmc == & FLS_T40FMC3) 
		{
            blkSelTmp.large3BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = pFls_BlkSel->large3BlkSel;/* polyspace RTE:IDP*/
        } 
		#endif // RESOURCE_SUPPORT_PFI3
		#ifdef RESOURCE_SUPPORT_PFI4
		else if (recovered_fmc == & FLS_T40FMC4)
		 {
            blkSelTmp.large4BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = pFls_BlkSel->large4BlkSel;/* polyspace RTE:IDP*/
        } 
		#endif // RESOURCE_SUPPORT_PFI4
		#ifdef RESOURCE_SUPPORT_PFI5
		else if (recovered_fmc == & FLS_T40FMC5) 
		{
            blkSelTmp.large5BlkSel = 0;

            /* Set the block selection registers */
            fmc->SEL2.B.A256KSEL = pFls_BlkSel->large5BlkSel;/* polyspace RTE:IDP*/
        } 
		#endif // RESOURCE_SUPPORT_PFI5
		else 
		{
        }
   
        /* Interlock write */
        *((volatile uint32_t *)u32Fls_InterlockWriteAddress) = FLS_ERASED_VALUE;  /*polyspace RTE:IDP*/

        /* Write a 1 to MCR_EHV */
        if (FLS_OP_SYNC == u32Fls_Mode)
        {
            #if( FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON )                   
                pFls_AcCodePtr(&u32Fls_TimerCounterAC,fmc);  /*polyspace RTE:COR*/
                if( 0U == u32Fls_TimerCounterAC )
                {
                    sFls_Ret = STATUS_TIMEOUT;
                    Fls_ReportRuntimeError( FLS_MAINFUNCTION_ID, FLS_E_TIMEOUT);
                }
            #else
                pFls_AcCodePtr(fmc);
            #endif
        }
        else
        {
            fmc->MCR.B.EHV = 1U;  /*polyspace RTE:IDP*/
        }

        /* Not wait until MCR_DONE is set */
    }
#endif // RESOURCE_SUPPORT_PFI
    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"



/*
 * @brief FLS_Erase
 *
 * Flash erase special block.
 */
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) FLS_SDK_Erase \
( \
    VAR( uint16, AUTOMATIC) u16Fls_FlashBlock, \
    VAR( uint32, AUTOMATIC) u32Fls_Index, \
    VAR( uint16, AUTOMATIC ) bFls_Mode \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( fls_blksel_t, AUTOMATIC) pFls_BlkSel;
    VAR( uint8, AUTOMATIC)  u8Fls_OpRet;
    VAR( uint32, AUTOMATIC) u32Fls_Offset = 0U;

#ifndef RESOURCE_SUPPORT_PFI
    if (u16Fls_FlashBlock > FLS_BLK_SECOND_256K)
#else
#if defined(RESOURCE_SUPPORT_PFI5)
    if (u16Fls_FlashBlock > FLS_BLK_LARGE5_256K)
#elif defined(RESOURCE_SUPPORT_PFI4)
    if (u16Fls_FlashBlock > FLS_BLK_LARGE4_256K)
#elif defined(RESOURCE_SUPPORT_PFI3)
    if (u16Fls_FlashBlock > FLS_BLK_LARGE3_256K)
#elif defined(RESOURCE_SUPPORT_PFI2)
    if (u16Fls_FlashBlock > FLS_BLK_LARGE2_256K)
#elif defined(RESOURCE_SUPPORT_PFI1)
    if (u16Fls_FlashBlock > FLS_BLK_LARGE1_256K)
#elif defined(RESOURCE_SUPPORT_PFI0)
    if (u16Fls_FlashBlock > FLS_BLK_LARGE0_256K)
#endif
#endif // RESOURCE_SUPPORT_PFI
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }
    
    /*
     * Flash erase operate
     *
     *  */
    sFls_Ret = FLASH_SDK_LLD_CheckEraseStatus(&u8Fls_OpRet);
    
    if(sFls_Ret == STATUS_SUCCESS && (FLS_OK == u8Fls_OpRet) )
	{
        FLS_SDK_LLD_DCacheInvalid();   // Make the erased flash space in Dcache invalid
        return sFls_Ret;	
	}
    else if(sFls_Ret == STATUS_INITIALIZED )
	{
    /* Get flash block offset and select state */
		sFls_Ret = FLS_SDK_Get_Offset_Select(u16Fls_FlashBlock, u32Fls_Index, &u32Fls_Offset, &pFls_BlkSel);
		if (STATUS_SUCCESS != sFls_Ret)
		{
			return sFls_Ret;
		}
		/* Call FLASH_LLD_Erase to start erase */
		sFls_Ret = FLASH_SDK_LLD_Erase(FLS_ERS_MAIN_SPACE, &pFls_BlkSel, bFls_Mode);
		if (STATUS_SUCCESS != sFls_Ret)
		{
			return sFls_Ret;
		}

		/* Call FLASH_LLD_CheckEraseStatus to confirm erase successful or not */

		sFls_Ret = FLASH_SDK_LLD_CheckEraseStatus(&u8Fls_OpRet);

		if ((STATUS_SUCCESS != sFls_Ret) || (FLS_OK != u8Fls_OpRet))
		{
			return sFls_Ret;
		}
        FLS_SDK_LLD_DCacheInvalid();   // Make the erased flash space in Dcache invalid
		/* Check offset and index */
		if ((u32Fls_Offset + u32Fls_Index) >= FLS_BLOCK_ALL)
		{
			sFls_Ret = STATUS_ERROR;
			return sFls_Ret;
		 }
    }
    else 
    {
        return sFls_Ret;
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) FLS_SDK_Read  \
( \
    VAR( uint32, AUTOMATIC) u32Fls_dest, \
    VAR( uint32, AUTOMATIC) u32Fls_size,  \
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pDataPtr
)
{
    VAR(uint32, AUTOMATIC) u32Fls_InitDataLength = 0UL;
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) Fls_ReadEndAddressPtr = NULL_PTR;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) u8Fls_ReadBlockAddressEndPtr = NULL_PTR;

    gFls_ReadAddressPtr = (volatile const uint8 *)u32Fls_dest;
    Fls_ReadEndAddressPtr = gFls_ReadAddressPtr + u32Fls_size;

    u32Fls_InitDataLength = Fls_LLD_CalcInitDataLength( gFls_ReadAddressPtr, u32Fls_size );
    u8Fls_ReadBlockAddressEndPtr = gFls_ReadAddressPtr + u32Fls_InitDataLength;

    while( (uint32)gFls_ReadAddressPtr < (uint32)u8Fls_ReadBlockAddressEndPtr )   
    {
        *pDataPtr = *gFls_ReadAddressPtr;  /*polyspace RTE:IDP,NIV*/
        pDataPtr++;
        gFls_ReadAddressPtr++;
    }

    u8Fls_ReadBlockAddressEndPtr += Fls_LLD_CalcWideDataLength( u32Fls_InitDataLength, u32Fls_size );
    while( (uint32)gFls_ReadAddressPtr < (uint32)u8Fls_ReadBlockAddressEndPtr )   
    {
        *((FLS_LLD_DATA_BUS_WIDTH_TYPE*)pDataPtr) = /*polyspace RTE:IDP,NIV*/
        *((volatile const FLS_LLD_DATA_BUS_WIDTH_TYPE*)gFls_ReadAddressPtr); /*polyspace RTE:IDP,NIV*/
        pDataPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE);
        gFls_ReadAddressPtr += sizeof(FLS_LLD_DATA_BUS_WIDTH_TYPE);
    }

    while( (uint32)gFls_ReadAddressPtr < (uint32)Fls_ReadEndAddressPtr )    
    {
        *pDataPtr = *gFls_ReadAddressPtr;  /*polyspace RTE:IDP,NIV*/
        pDataPtr++;
        gFls_ReadAddressPtr++;
    }
    #ifndef RESOURCE_SUPPORT_PFI
    if(FLS_FMC.MCR.B.EER == 1U)
    {
        FLS_FMC.MCR.B.EER = 1U;
        gFLS_Ecc_Addr = u32Fls_dest;
        for (uint32 flash_index = 0U; flash_index < FLS_BLOCK_ALL; flash_index++)
        {
            if ((gFLS_Ecc_Addr >= flashInfo[flash_index].addrStart) && (gFLS_Ecc_Addr <= flashInfo[flash_index].addrEnd))
            {
                gFLS_Ecc_Addr = flashInfo[flash_index].addrStart;
				break;
            }
        }
        gFLS_Ecc_Flag = 1U;
        sFls_Ret = STATUS_ERROR;
    }
	#else
    VAR( uint32, AUTOMATIC) u32Fls_Index = 0;
    for (u32Fls_Index = 0U; u32Fls_Index < FLS_CONTROLLER_NUM; u32Fls_Index++) 
    {
        if(flashControllerList[u32Fls_Index]->MCR.B.EER == 1U)
        {
            flashControllerList[u32Fls_Index]->MCR.B.EER = 1U;
            gFLS_Ecc_Addr = u32Fls_dest;
            for (uint32 flash_index = 0U; flash_index < FLS_BLOCK_ALL; flash_index++)
            {
                if ((gFLS_Ecc_Addr >= flashInfo[flash_index].addrStart) && (gFLS_Ecc_Addr <= flashInfo[flash_index].addrEnd))
                {
                    gFLS_Ecc_Addr = flashInfo[flash_index].addrStart;
                    break;
                }
            }
            gFLS_Ecc_Flag = 1U;
            sFls_Ret = STATUS_ERROR;
            break;
        }
        
	}
    #endif
    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC(status_t, FLS_CODE) FLASH_SDK_LLD_Abort(void)
{
    volatile VAR(uint32, AUTOMATIC) u32Fls_clearFlag = 0x0U;
    VAR( uint32, AUTOMATIC) u32Fls_count = 450U;
    VAR(status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;

#ifndef RESOURCE_SUPPORT_PFI
    volatile uint32_t u32Fls_erase = 0x0U;
    u32Fls_erase = FLS_FMC.MCR.B.ERS;
    if (FLS_FMC.MCR.B.ESUS != 0U)
    {
        if (FLS_FMC.MCR.B.PSUS != 0U)
        {
            u32Fls_clearFlag = 0x3U;
        }
        else
        {
            u32Fls_clearFlag = 0x2U;
        }
    }
    else
    {
        if (FLS_FMC.MCR.B.PSUS != 0U)
        {
            u32Fls_clearFlag = 0x1U;
        }
    }

    if ((u32Fls_clearFlag & 0x1U) != 0x0U)  /* Program-suspended Erase-suspended or Program-suspended only */
    {
        /* Wait MCR DONE bit is set to program-suspended operation accomplish */
        while ((FLS_FMC.MCR.B.DONE == 0U) && (u32Fls_count > 0U))
        {
            u32Fls_count--;
        }
        /* Set MCR_EHV bit then clear MCR_PSUS to resume program operation */
        FLS_FMC.MCR.B.EHV = 1U;
        FLS_FMC.MCR.B.PSUS = 0U;
    }

    if ((u32Fls_clearFlag & 0x2U) != 0x0U)
    {
        /* Clear EHV to abort program operation and then clear MCR_PGM */
        FLS_FMC.MCR.B.EHV = 0U;
        /* Wait MCR DONE bit is set */
        while ((FLS_FMC.MCR.B.DONE == 0U) && (u32Fls_count > 0U))
        {
            u32Fls_count--;
        }
        FLS_FMC.MCR.B.PGM = 0U;
        /* Set MCR_EHV bit then clear MCR_PSUS to resume erase operation */
        FLS_FMC.MCR.B.EHV = 1U;
        FLS_FMC.MCR.B.ESUS = 0U;
    }

    /* Clear EHV bit to abort flash operation */
    FLS_FMC.MCR.B.EHV = 0U;
    /* Wait MCR DONE bit is set */
    while ((FLS_FMC.MCR.B.DONE == 0U) && (u32Fls_count > 0U))
    {
        u32Fls_count--;
    }

    /* Clear PGM, ERS bit */
    FLS_FMC.MCR.B.PGM = 0U;
    FLS_FMC.MCR.B.ERS = 0U;
    /* Disable Cache */
    PFLASH.PFCR1.B.P0_BFEN = 0U;
    PFLASH.PFCR2.B.P1_BFEN = 0U;
    /* Enable Cache */
    PFLASH.PFCR1.B.P0_BFEN = 1U;
    PFLASH.PFCR2.B.P1_BFEN = 1U;
    if (u32Fls_erase != 0x0U)
    {
        FLS_SDK_LLD_DCacheInvalid();
    }
#else
    uint32_t u32fls_index = 0U;
	volatile uint32_t u32Fls_erase = 0x0U;

    for (u32fls_index = 0U; u32fls_index < FLS_CONTROLLER_NUM; u32fls_index++)
    {
        volatile struct C55FMC_tag * const fmc = flashControllerList[u32fls_index];

        volatile struct PFLASH_tag *pflash = NULL;
        u32Fls_count = 450U;
        u32Fls_clearFlag = 0x0U;
        u32Fls_erase |= fmc->MCR.B.ERS;
        if (fmc->MCR.B.ESUS != 0U)
        {
            if (fmc->MCR.B.PSUS != 0U)
            {
                u32Fls_clearFlag = 0x3U;
            }
            else
            {
                u32Fls_clearFlag = 0x2U;
            }
        }
        else
        {
            if (fmc->MCR.B.PSUS != 0U)
            {
                u32Fls_clearFlag = 0x1U;
            }
        }

        if ((u32Fls_clearFlag & 0x1U) != 0x0U)  /* Program-suspended Erase-suspended or Program-suspended only */
        {
            /* Wait MCR DONE bit is set to program-suspended operation accomplish */
            while ((fmc->MCR.B.DONE == 0U) && (u32Fls_count > 0U))
            {
                u32Fls_count--;
            }
            /* Set MCR_EHV bit then clear MCR_PSUS to resume program operation */
            fmc->MCR.B.EHV = 1U;
            fmc->MCR.B.PSUS = 0U;
        }

        if ((u32Fls_clearFlag & 0x2U) != 0x0U)
        {
            /* Clear EHV to abort program operation and then clear MCR_PGM */
            fmc->MCR.B.EHV = 0U;
            /* Wait MCR DONE bit is set */
            while ((fmc->MCR.B.DONE == 0U) && (u32Fls_count > 0U))
            {
                u32Fls_count--;
            }
            fmc->MCR.B.PGM = 0U;
            /* Set MCR_EHV bit then clear MCR_PSUS to resume erase operation */
            fmc->MCR.B.EHV = 1U;
            fmc->MCR.B.ESUS = 0U;
        }

        /* Clear EHV bit to abort flash operation */
        fmc->MCR.B.EHV = 0U;
        /* Wait MCR DONE bit is set */
        while ((fmc->MCR.B.DONE == 0U) && (u32Fls_count > 0U))
        {
            u32Fls_count--;
        }

        /* Clear PGM, ERS bit */
        fmc->MCR.B.PGM = 0U;
        fmc->MCR.B.ERS = 0U;
        /* Enable Cache */
        sFls_Ret = FLS_LLD_GetMappedPFlash(fmc, &pflash);
		if((pflash == NULL) || (sFls_Ret != STATUS_SUCCESS) )
		{
			sFls_Ret = STATUS_ERROR;
			return sFls_Ret;
		}

        pflash->PFCR1.B.P0_BFEN = 0U;
        pflash->PFCR2.B.P1_BFEN = 0U;
        pflash->PFCR1.B.P0_BFEN = 1U;
        pflash->PFCR2.B.P1_BFEN = 1U;
    }
       
    /* Make the erased flash space in DCache invalid */
    if (u32Fls_erase != 0x0U)
    {
        FLS_SDK_LLD_DCacheInvalid();
    }
#endif // RESOURCE_SUPPORT_PFI

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) FLASH_LLD_BlankCheck \
( \
    VAR( uint32, AUTOMATIC) u32Fls_Dest, \
    VAR( uint32, AUTOMATIC) u32Fls_Size, \
    VAR( uint32, AUTOMATIC) u32Fls_CheckWordSize, \
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_FailAddr \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_DestIndex = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Temp = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_DestTmp = u32Fls_Dest;
    VAR( uint32, AUTOMATIC) u32Fls_SizeTmp = u32Fls_Size;

    if (((u32Fls_DestTmp | u32Fls_SizeTmp) % FLS_SDK_WORD_SIZE) != 0U)
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    while ((u32Fls_SizeTmp > 0U) && (STATUS_SUCCESS == sFls_Ret))
    {
        /* Number of words needs to be checked for blank */
        u32Fls_Temp = u32Fls_SizeTmp / FLS_SDK_WORD_SIZE;

        /* In each blank check cycle, we take up to a certain words */
        if (u32Fls_Temp >= u32Fls_CheckWordSize)
        {
            u32Fls_Temp = u32Fls_CheckWordSize;
        }

        /* Word by word blank check */
        for (u32Fls_DestIndex = 0U; u32Fls_DestIndex < u32Fls_Temp; u32Fls_DestIndex++)
        {
            if ((*(volatile uint32 *)u32Fls_DestTmp) != 0xFFFFFFFFU) /*polyspace RTE:NIV,IDP*/
            {
                sFls_Ret = STATUS_ERROR;
                *pFls_FailAddr = u32Fls_DestTmp;
                break;
            }
            u32Fls_DestTmp += FLS_SDK_WORD_SIZE;
            u32Fls_SizeTmp -= FLS_SDK_WORD_SIZE;
			gFls_JobAddrIt += FLS_SDK_WORD_SIZE;
        }

        #ifndef RESOURCE_SUPPORT_PFI
        if(FLS_FMC.MCR.B.EER == 1U)
		{
            FLS_FMC.MCR.B.EER = 1U;
            gFLS_Ecc_Addr = u32Fls_Dest;
            gFLS_Ecc_Flag = 1U;
			sFls_Ret = STATUS_ERROR;
		}
        #else
        VAR( uint32, AUTOMATIC) u32Fls_Index = 0;
        for (u32Fls_Index = 0U; u32Fls_Index < FLS_CONTROLLER_NUM; u32Fls_Index++) 
        {
            if(flashControllerList[u32Fls_Index]->MCR.B.EER == 1U)
            {
                flashControllerList[u32Fls_Index]->MCR.B.EER = 1U;
                gFLS_Ecc_Addr = u32Fls_Dest;
                gFLS_Ecc_Flag = 1U;
                sFls_Ret = STATUS_ERROR;
                break;
            }
        }
        #endif
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( status_t, FLS_CODE ) FLASH_LLD_ProgramVerify \
( \
    VAR( uint32, AUTOMATIC) u32Fls_Dest, \
    VAR( uint32, AUTOMATIC) u32Fls_Size, \
    VAR( uint32, AUTOMATIC) u32Fls_Src, \
    VAR( uint32, AUTOMATIC) u32Fls_CheckWordSize, \
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pFls_FailAddr \
)
{
    VAR( status_t, AUTOMATIC) sFls_Ret = STATUS_SUCCESS;
    VAR( uint32, AUTOMATIC) u32Fls_DestIndex = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_Temp = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_ValDest = 0U;
    VAR( uint32, AUTOMATIC) u32Fls_DestTmp = u32Fls_Dest;
    VAR( uint32, AUTOMATIC) u32Fls_SizeTmp = u32Fls_Size;
    VAR( uint32, AUTOMATIC) u32Fls_SrcTmp = u32Fls_Src;

    if ( ((u32Fls_DestTmp | u32Fls_SizeTmp | u32Fls_Src) % FLS_SDK_WORD_SIZE) != 0U )
    {
        sFls_Ret = STATUS_ERROR;
        return sFls_Ret;
    }

    while ((u32Fls_SizeTmp > 0U) && (STATUS_SUCCESS == sFls_Ret))
    {
        /* Number of words needs to be verified */
        u32Fls_Temp = u32Fls_SizeTmp / FLS_SDK_WORD_SIZE;

        /* In each verify cycle, we take up to a certain words */
        if (u32Fls_Temp >= u32Fls_CheckWordSize)
        {
            u32Fls_Temp = u32Fls_CheckWordSize;
        }

        /* Word by word verify */
        for (u32Fls_DestIndex = 0U; u32Fls_DestIndex < u32Fls_Temp; u32Fls_DestIndex++)
        {
            u32Fls_ValDest = *(volatile uint32 *)u32Fls_DestTmp; /*polyspace RTE:NIV,IDP*/
            if (u32Fls_ValDest != *(volatile uint32 *)u32Fls_SrcTmp)  /*polyspace RTE:NIV,IDP*/
            {
                sFls_Ret = STATUS_ERROR;
                *pFls_FailAddr = u32Fls_DestTmp;
                break;
            }

            u32Fls_DestTmp += FLS_SDK_WORD_SIZE;
            u32Fls_SrcTmp += FLS_SDK_WORD_SIZE;
            u32Fls_SizeTmp -= FLS_SDK_WORD_SIZE;
        }

		#ifndef RESOURCE_SUPPORT_PFI
        if(FLS_FMC.MCR.B.EER == 1U)
		{
            FLS_FMC.MCR.B.EER = 1U;
            gFLS_Ecc_Addr = u32Fls_Dest;
            for (uint32 flash_index = 0U; flash_index < FLS_BLOCK_ALL; flash_index++)
            {
                if ((gFLS_Ecc_Addr >= flashInfo[flash_index].addrStart) && (gFLS_Ecc_Addr <= flashInfo[flash_index].addrEnd))
                {
                    gFLS_Ecc_Addr = flashInfo[flash_index].addrStart;
					break;
                }
            }   
            gFLS_Ecc_Flag = 1U;
			sFls_Ret = STATUS_ERROR;
		}
        #else
        VAR( uint32, AUTOMATIC) u32Fls_Index = 0;
        for (u32Fls_Index = 0U; u32Fls_Index < FLS_CONTROLLER_NUM; u32Fls_Index++) 
        {
            if(flashControllerList[u32Fls_Index]->MCR.B.EER == 1U)
            {
                flashControllerList[u32Fls_Index]->MCR.B.EER = 1U;
                gFLS_Ecc_Addr = u32Fls_Dest;
                for (uint32 flash_index = 0U; flash_index < FLS_BLOCK_ALL; flash_index++)
                {
                    if ((gFLS_Ecc_Addr >= flashInfo[flash_index].addrStart) && (gFLS_Ecc_Addr <= flashInfo[flash_index].addrEnd))
                    {
                        gFLS_Ecc_Addr = flashInfo[flash_index].addrStart;
                        break;
                    }
                }   
                gFLS_Ecc_Flag = 1U;
                sFls_Ret = STATUS_ERROR;
                break;
            }
            
        }
        #endif
    }

    return sFls_Ret;
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_LLD_Lock (void)
{
#ifndef RESOURCE_SUPPORT_PFI

    #if defined(CCFC3008PC)
    FLS_FMC.LOCK0.R |= 0x3FFFFFFFU;

	FLS_FMC.LOCK1.R |= 0xFFFFFFFFU;

	FLS_FMC.LOCK2.R |= 0xFFFFFFFFU;

	FLS_FMC.LOCK3.R |= 0xFFFFU;
    #elif defined(CCFC3008PCSN)
    FLS_FMC.LOCK0.R |= 0xFFFFU;

    FLS_FMC.LOCK2.R |= 0xFFFFFFFU;
    #elif defined(CCFC3008PCSA)
    FLS_FMC.LOCK0.R |= 0x8000FFFFU;
    FLS_FMC.LOCK1.R |= 0x0000FFFFU;
    FLS_FMC.LOCK2.R |= 0xFFFFFFFFU;
    #else
	FLS_FMC.LOCK0.R |= 0x3DE0000U;

	FLS_FMC.LOCK1.R |= 0xFFU;

	FLS_FMC.LOCK2.R |= 0xFFFFFFFFU;

	FLS_FMC.LOCK3.R |= 0xFFFFU;
    #endif // CCFC3008PC || CCFC3008PCSN


#else
	FLS_FMC.LOCK0.R |= 0xFFF0000U;
	FLS_FMC.LOCK1.R |= 0xFFU;
	FLS_FMC.LOCK2.R |= 0xFFFFFFFFU;
#if defined(RESOURCE_SUPPORT_PFI0)
	FLS_T40FMC0.LOCK2.R |= 0xFFFFFFFFU;
#endif
#if defined(RESOURCE_SUPPORT_PFI1)
    FLS_T40FMC1.LOCK2.R |= 0xFFFFFFFFU;
#endif
#if defined(RESOURCE_SUPPORT_PFI2)
    FLS_T40FMC2.LOCK2.R |= 0xFFFFFFFFU;
#endif
#if defined(RESOURCE_SUPPORT_PFI3)
    FLS_T40FMC3.LOCK2.R |= 0xFFFFFFFFU;
#endif
#if defined(RESOURCE_SUPPORT_PFI4)
    FLS_T40FMC4.LOCK2.R |= 0xFFFFFFFFU;
#endif
#if defined(RESOURCE_SUPPORT_PFI5)
    FLS_T40FMC5.LOCK2.R |= 0xFFFFFFFFU;
#endif

#endif // RESOURCE_SUPPORT_PFI
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) Fls_LLD_Unlock \
(\
    VAR( uint32, AUTOMATIC) u32Fls_Dest,
    VAR(uint32,AUTOMATIC)  u32Fls_EndAddr
)
{
    VAR(uint32,AUTOMATIC) dest_Temp = u32Fls_Dest;
    VAR(uint32,AUTOMATIC) u32Fls_PhyIndex = 0U;
    VAR(uint32,AUTOMATIC) u32fls_Num = 0;
    VAR(uint32,AUTOMATIC) u32fls_DestEnd_Temp = (*(gFls_ConfigPtr->paSectorEndAddr))[dest_Temp]; /* polyspace RTE:OBAI,IDP*/
    while(u32Fls_EndAddr > u32fls_DestEnd_Temp)
    {
        dest_Temp++;
        u32fls_DestEnd_Temp = (*(gFls_ConfigPtr->paSectorEndAddr))[dest_Temp]; /* polyspace RTE:OBAI,IDP*/
    }
    for(u32fls_Num = u32Fls_Dest; u32fls_Num <= dest_Temp; u32fls_Num++)
    {
        u32Fls_PhyIndex =(uint32)(*(gFls_ConfigPtr->pSectorList))[u32fls_Num]; /* polyspace RTE:OBAI,IDP*/
        VAR( uint8, AUTOMATIC) SelBit = (uint8)flashInfo[u32Fls_PhyIndex].lockSelBit;/* polyspace RTE:OBAI */
        if (SelBit < 32U)
        {
			#ifndef RESOURCE_SUPPORT_PFI
			if (0U == flashInfo[u32Fls_PhyIndex].lockSelReg)
			{
				FLS_FMC.LOCK0.R &= ~(1UL << SelBit);
			}
			else if (1U == flashInfo[u32Fls_PhyIndex].lockSelReg)
			{
				FLS_FMC.LOCK1.R &= ~(1UL << SelBit);
			}
			else if (2U == flashInfo[u32Fls_PhyIndex].lockSelReg)
			{
				FLS_FMC.LOCK2.R &= ~(1UL << SelBit);
			}
			else if (3U == flashInfo[u32Fls_PhyIndex].lockSelReg)
			{
				FLS_FMC.LOCK3.R &= ~(1UL << SelBit);
			}
            #else
			if (0U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize < 0x40000U)
			{
				FLS_FMC.LOCK0.R &= ~(1UL << SelBit);
			}
			else if (1U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize < 0x40000U)
			{
				FLS_FMC.LOCK1.R &= ~(1UL << SelBit);
			}
			else if (2U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize < 0x40000U)
			{
				FLS_FMC.LOCK2.R &= ~(1UL << SelBit);
			}
			else if (3U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize < 0x40000U)
			{
				FLS_FMC.LOCK3.R &= ~(1UL << SelBit);
			}
			#if defined(RESOURCE_SUPPORT_PFI0)
			else if (0U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize == 0x40000U)
			{
				volatile struct C55FMC_tag *controller = NULL;

				FLS_SDK_LLD_GetMappedController(&FLS_T40FMC0, &controller);

				controller->LOCK2.R &= ~(1UL << SelBit);/* polyspace RTE:NIV,IDP */
			}
			#endif
			#if defined(RESOURCE_SUPPORT_PFI1)
			else if (1U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize == 0x40000U)
			{
				volatile struct C55FMC_tag *controller = NULL;

				FLS_SDK_LLD_GetMappedController(&FLS_T40FMC1, &controller);

				controller->LOCK2.R &= ~(1UL << SelBit);/* polyspace RTE:NIV,IDP */
			}
			#endif
			#if defined(RESOURCE_SUPPORT_PFI2)
			else if (2U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize == 0x40000U)
			{
				volatile struct C55FMC_tag *controller = NULL;

				FLS_SDK_LLD_GetMappedController(&FLS_T40FMC2, &controller);

				controller->LOCK2.R &= ~(1UL << SelBit);/* polyspace RTE:NIV,IDP */
			}
			#endif
			#if defined(RESOURCE_SUPPORT_PFI3)
			else if (3U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize == 0x40000U)
			{
				volatile struct C55FMC_tag *controller = NULL;

				FLS_SDK_LLD_GetMappedController(&FLS_T40FMC3, &controller);

				controller->LOCK2.R &= ~(1UL << SelBit);/* polyspace RTE:NIV,IDP */
			}
			#endif
			#if defined(RESOURCE_SUPPORT_PFI4)
			else if (4U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize == 0x40000U)
			{
				volatile struct C55FMC_tag *controller = NULL;

				FLS_SDK_LLD_GetMappedController(&FLS_T40FMC4, &controller);

				controller->LOCK2.R &= ~(1UL << SelBit);/* polyspace RTE:NIV,IDP */
			}
			#endif
			#if defined(RESOURCE_SUPPORT_PFI5)
			else if (5U == flashInfo[u32Fls_PhyIndex].lockSelReg && flashInfo[u32Fls_PhyIndex].blockSize == 0x40000U)
			{
				volatile struct C55FMC_tag *controller = NULL;

				FLS_SDK_LLD_GetMappedController(&FLS_T40FMC5, &controller);

				controller->LOCK2.R &= ~(1UL << SelBit);/* polyspace RTE:NIV,IDP */
			}
			#endif
            #endif
			else
			{
				/* No operation */
			}
        }
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"



