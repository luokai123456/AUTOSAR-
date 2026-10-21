/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Mcu
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
*   @file    Mcu_AutoSAR_Wrapper.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Mcu MCAL driver.
*
*   @addtogroup Mcu
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/

#include "Mcu_LLDriver.h" /*PRQA S 0380*/
#include "Mcu_HAL_Wrapper.h"
#include "Mcu_AutoSAR_Wrapper.h"

/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define MCU_WAR_VENDOR_ID_C                       176
#define MCU_WAR_AR_MAJOR_VER_C                    4
#define MCU_WAR_AR_MINOR_VER_C                    4
#define MCU_WAR_AR_PATCH_VER_C                    0
#define MCU_WAR_SW_MAJOR_VER_C                    3
#define MCU_WAR_SW_MINOR_VER_C                    0
#define MCU_WAR_SW_PATCH_VER_C                    0
/*============================================FILE VERSION CHECKS===================================*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_WAR_VENDOR_ID_C != MCU_WAR_VENDOR_ID)
#error "NON-MATCHED DATA : MCU_WAR_VENDOR_ID"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#if (MCU_WAR_AR_MAJOR_VER_C != MCU_WAR_AR_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_WAR_AR_MAJOR_VER"
#endif
#if (MCU_WAR_AR_MINOR_VER_C != MCU_WAR_AR_MINOR_VER)
#error "NON-MATCHED DATA : MCU_WAR_AR_MINOR_VER"
#endif
#if (MCU_WAR_AR_PATCH_VER_C != MCU_WAR_AR_PATCH_VER)
#error "NON-MATCHED DATA : MCU_WAR_AR_PATCH_VER"
#endif

/* Check if current file and MCU header file are of the same Software version */
#if (MCU_WAR_SW_MAJOR_VER_C != MCU_WAR_SW_MAJOR_VER)
#error "NON-MATCHED DATA : MCU_WAR_SW_MAJOR_VER"
#endif
#if (MCU_WAR_SW_MINOR_VER_C != MCU_WAR_SW_MINOR_VER)
#error "NON-MATCHED DATA : MCU_WAR_SW_MINOR_VER"
#endif
#if (MCU_WAR_SW_PATCH_VER_C != MCU_WAR_SW_PATCH_VER)
#error "NON-MATCHED DATA : MCU_WAR_SW_PATCH_VER"
#endif

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Std_ReturnType, MCU_CODE)Mcu_Wrap_InitRamSection
(
    P2CONST( Mcu_RamConfigType, AUTOMATIC, MCU_APPL_CONST) pMcu_RamConfigPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Mcu_RetResult = (Std_ReturnType)E_OK;
    /* Variable for indexing RAM sections. */
    VAR(uint32, AUTOMATIC) u32Mcu_RamCounter;
    /* Limit of u32Mcu_RamCounter. */
    VAR(uint32, AUTOMATIC) u32Mcu_RamCounterLimit;

    u32Mcu_RamCounterLimit = (uint32)( (pMcu_RamConfigPtr->Mcu_RamSize) /* polyspace RTE:IDP */
                               / (pMcu_RamConfigPtr->Mcu_RamWriteSize) ); /* polyspace RTE:ZDV */ /*PRQA S 2834*/
    for (u32Mcu_RamCounter = (uint32)0UL; (u32Mcu_RamCounter < u32Mcu_RamCounterLimit); u32Mcu_RamCounter++)
    {
        switch (pMcu_RamConfigPtr->Mcu_RamWriteSize)
        {
            case 1U:
            {
                ((uint8 *)pMcu_RamConfigPtr->Mcu_RamBaseAddrPtr)[u32Mcu_RamCounter]  /*PRQA S 3305,0310,0491*/ /* polyspace RTE:IDP */
                    = (uint8) pMcu_RamConfigPtr->Mcu_RamDefaultValue;
                break;
            }
            case 2U:
            {
                ((uint16 *)pMcu_RamConfigPtr->Mcu_RamBaseAddrPtr)[u32Mcu_RamCounter] /*PRQA S 3305,0310,0491*/ /* polyspace RTE:IDP */
                    = (uint16) pMcu_RamConfigPtr->Mcu_RamDefaultValue;
                break;
            }
            case 4U:
            {
                ((uint32 *)pMcu_RamConfigPtr->Mcu_RamBaseAddrPtr)[u32Mcu_RamCounter] /*PRQA S 3305,0310,0491*/ /* polyspace RTE:IDP */
                    = (uint32) pMcu_RamConfigPtr->Mcu_RamDefaultValue;
                break;
            }
            case 8U:
            {
                ((uint64 *)pMcu_RamConfigPtr->Mcu_RamBaseAddrPtr)[u32Mcu_RamCounter] /*PRQA S 3305,0310,0491*/ /* polyspace RTE:IDP */
                    = (uint64) pMcu_RamConfigPtr->Mcu_RamDefaultValue;
                break;
            }
            default:
            {
                u8Mcu_RetResult = (Std_ReturnType)E_NOT_OK;
                break;
            }
        }
    }
    return (Std_ReturnType)u8Mcu_RetResult;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_NO_PLL == STD_OFF)
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"
FUNC(Mcu_PllStatusType, MCU_CODE) Mcu_Wrap_GetPllStatus( VAR(void, AUTOMATIC) )
{
    VAR(Std_ReturnType, MCU_VAR) eMcu_SdkPllStatus = (Std_ReturnType)E_UNSUPPORTED;
    VAR(Mcu_PllStatusType, MCU_VAR) eMcu_PllStatus = (Mcu_PllStatusType)MCU_PLL_STATUS_UNDEFINED;
    eMcu_SdkPllStatus = Mcu_HAL_GetPllStatus();
    if((Std_ReturnType)E_OK == eMcu_SdkPllStatus)
    {
        eMcu_PllStatus = (Mcu_PllStatusType)MCU_PLL_LOCKED;
    }
    else
    {
        eMcu_PllStatus = (Mcu_PllStatusType)MCU_PLL_UNLOCKED;
    }
    return (Mcu_PllStatusType)eMcu_PllStatus;
}
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
#endif /* MCU_NO_PLL  STD_OFF */
#endif /* MCU_INIT_CLOCK  STD_ON */



#ifdef __cplusplus
}
#endif


