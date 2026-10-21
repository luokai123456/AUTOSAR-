/* PRQA S 2053,0380,3432 EOF */ 
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
*   @file    Fls_ac.c
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


#include "Fls.h"

#define FLS_AC_WRA_C_VENDOR_ID                     176
#define FLS_AC_WRA_C_AR_REL_MAJOR_VER              4
#define FLS_AC_WRA_C_AR_REL_MINOR_VER              4
#define FLS_AC_WRA_C_AR_REL_REV_VER                0
#define FLS_AC_WRA_C_SW_MAJOR_VER                  3
#define FLS_AC_WRA_C_SW_MINOR_VER                  0
#define FLS_AC_WRA_C_SW_PATCH_VER                  0

#if (FLS_VENDOR_ID_OUTPUT != FLS_AC_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_VENDOR_ID "
#endif
#if (FLS_AR_REL_MAJOR_VER_OUTPUT != FLS_AC_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (FLS_AR_REL_MINOR_VER_OUTPUT != FLS_AC_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_AR_REL_MINOR_VER "
#endif
#if (FLS_AR_REL_REVISION_VER_OUTPUT != FLS_AC_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_AR_REL_REV_VER "
#endif
#if (FLS_SW_MAJOR_VERSION_OUTPUT != FLS_AC_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_SW_MAJOR_VER "
#endif
#if (FLS_SW_MINOR_VERSION_OUTPUT != FLS_AC_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_SW_MINOR_VER "
#endif
#if (FLS_SW_PATCH_VERSION_OUTPUT != FLS_AC_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : FLS_AC_WRA_C_SW_PATCH_VER "
#endif

/* Specification of Flash Driver : [SWS_Fls_00137] */
/* Specification of Flash Driver : [SWS_Fls_00215] */
/* Specification of Flash Driver : [SWS_Fls_00211] */


#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) FLS_AccessCode \
( \
    P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC \
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) FLS_AccessCode
(
		P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC , /* PRQA S 3432 */
		volatile struct C55FMC_tag *fmc
);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif // RESOURCE_SUPPORT_PFI
#else
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) FLS_AccessCode(void);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) FLS_AccessCode(volatile struct C55FMC_tag *fmc);
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif // RESOURCE_SUPPORT_PFI
#endif /* FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON */


/*****************************************************************************
** Service Name      : Fls_AccessCode                                              
** 
** 
**  Description      : Initializes the FLASH module                         
**                                                                            
**  Parameters (in)  : lockBlk: Indicating the lock status of flash module.
**                     pFls_TimerCounterAC: Time counting pointer
**                                          (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)                          
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                  
**                                                                            
******************************************************************************/
#if (FLS_TIMEOUT_SUPERVISION_ENABLED == STD_ON)
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) FLS_AccessCode \
( \
    P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC \
)
{
    /* Set MCR EHV bit, start operation */
    FLS_FMC.MCR.B.EHV = 1U;

    /* Wait MCR DONE bit is set */
    while ((FLS_FMC.MCR.B.DONE == 0x0U) && (0U < *pFls_TimerCounterAC))
    {
        (*pFls_TimerCounterAC)--;
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) FLS_AccessCode
(
		P2VAR(uint32, AUTOMATIC, FLS_CODE) pFls_TimerCounterAC , /* PRQA S 3432 */
		volatile struct C55FMC_tag *fmc
)
{
    /* Set MCR EHV bit, start operation */
    fmc->MCR.B.EHV = 1U;

    /* Wait MCR DONE bit is set */
    while ((fmc->MCR.B.DONE == 0x0U) && (0U < *pFls_TimerCounterAC))
    {
		(*pFls_TimerCounterAC)--;
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
   
#endif // RESOURCE_SUPPORT_PFI

#else
/*
 * @brief Initializes the FLASH module
 *
 * This function will initialize flash module.
 *
 * @param[in] lockBlk: Indicating the lock status of flash module.
 * @return Operation status
 */
#ifndef RESOURCE_SUPPORT_PFI
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) FLS_AccessCode(void)
{
    /* Set MCR EHV bit, start operation */
    FLS_FMC.MCR.B.EHV = 1U;
    uint32 Fls_Timeout_Temp = 0;

    /* Wait MCR DONE bit is set */
    while ((FLS_FMC.MCR.B.DONE == 0x0U) && (Fls_Timeout_Temp < DEFAULT_TIMEOUT)  )
    {
        Fls_Timeout_Temp++;  
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#else
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"
FUNC( void, FLS_CODE ) FLS_AccessCode(volatile struct C55FMC_tag *fmc)
{
    /* Set MCR EHV bit, start operation */
    fmc->MCR.B.EHV = 1U;
    uint32 Fls_Timeout_Temp = 0;

    /* Wait MCR DONE bit is set */
    while ((fmc->MCR.B.DONE == 0x0U) && (Fls_Timeout_Temp < DEFAULT_TIMEOUT))
    {
        Fls_Timeout_Temp++;  
    }
}
#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"
#endif // RESOURCE_SUPPORT_PFI


#endif /* FLS_TIMEOUT_HANDLING == STD_ON */


#ifdef __cplusplus
}
#endif
