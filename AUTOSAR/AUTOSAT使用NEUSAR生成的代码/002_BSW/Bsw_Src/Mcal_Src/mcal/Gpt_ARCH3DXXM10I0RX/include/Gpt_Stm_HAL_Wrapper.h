/* PRQA S 2053 EOF */ 
/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC
*   Peripheral           : Gpt
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : -
*   Autosar Conf.Variant : -
*   SW Version           : -
*   Build Version        : -
*
*****************************************************************************/

/**
*   @file    Gpt_Stm_HAL_Wrapper.h
*   @version 3.0.0
*
*    AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Gpt
*   @{
*/
/* PRQA S 3432,1535 EOF */
#ifndef GPT_STM_HAL_WRAPPER_H
#define GPT_STM_HAL_WRAPPER_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================INCLUDE FILES=======================================*/
#include "Gpt_Stm_LLDriver.h"
#include "Gpt.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/
#define GPT_VENDOR_ID_H                     176
#define GPT_MODULE_ID_H                     100
#define GPT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_AR_RELEASE_MINOR_VERSION        4
#define GPT_AR_PATCH_VER_H                  0
#define GPT_SW_MAJOR_VER_H                  3
#define GPT_SW_MINOR_VER_H                  0
#define GPT_SW_PATCH_VER_H                  0

/*============================================FILE VERSION CHECKS===================================*/

#if (GPT_VENDOR_ID_H != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_CFG_VENDOR_ID"
#endif

#if (GPT_AR_RELEASE_MAJOR_VERSION != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_RELEASE_MINOR_VERSION != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_H != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

#if (GPT_SW_MAJOR_VER_H != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_H != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_H != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif
/*=================================================Constants========================================*/

/*============================================DEFINES AND MACROS====================================*/

/*===================================================ENUMS==========================================*/
/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

extern VAR(uint32, GPT_VAR) u32StmTargetValue[GPT_STM_MODULE_MAX][GPT_STM_CHANNEL_MAX];
/*==============================================GLOBAL FUNCTIONS====================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_Init  \
( 										   \
    VAR(uint8, AUTOMATIC) u8Channel,       \
    VAR(uint8, AUTOMATIC) u8StmPrescaler,  \
    VAR(boolean, AUTOMATIC) bFreezeEnable  \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_DeInit \
( 									\
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Stm_Wrapper_GetTimeElapsed \
(                                     \
    VAR(uint8, AUTOMATIC) u8Channel,  \
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbStm_IsRollover,  \
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32Stm_TargetValue \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Stm_Wrapper_GetTimeRemaining \
(                                   \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_StartTimer \
(                                          \
    VAR(uint8, AUTOMATIC) u8Channel,       \
    VAR(uint32, AUTOMATIC) u32Stm_Value    \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_StopTimer \
(                                   \
    VAR(uint8, AUTOMATIC) u8Channel \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Stm_Wrapper_GetPredefTimerValue \
(                                    \
    VAR(uint8, AUTOMATIC) u8Channel, \
    VAR(Gpt_PredefTimerType, AUTOMATIC) eStm_PredefTimerType \
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_StartPredefTimer
(
    VAR(uint8, AUTOMATIC) u8Channel,
    VAR(uint8, AUTOMATIC) u8StmPrescaler,
    VAR(boolean, AUTOMATIC) bFreezeEnable
);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_StopPredefTimer (VAR(uint8, AUTOMATIC) u8Channel);
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#ifdef __cplusplus
}
#endif

#endif //STM_WRAPPER_H
