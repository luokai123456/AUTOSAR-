/**************************************************************************** 
* 

* Copyright (c) 2023  C*Core -   All Rights Reserved  
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* 
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : LIN
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
*   @file    Lin.h
*   @implements Lin.h_Artifact
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin - High level header of LIN driver.
*   @details This file contains declarations of the functions defined by AutoSAR.
*
*   @addtogroup Lin
*   @{
*/

/*PRQA S 1535,1758,1594,1599,1756 EOF*/
#ifndef LIN_H
#define LIN_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==============================================INCLUDE FILES=======================================*/

#include "Mcal.h"

#include "ComStack_Types.h"
#include "Lin_GeneralTypes.h"
#include "Lin_Cfg.h"
#include "Lin_Types.h"

/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_H_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_AR_RELEASE_MAJOR_VERSION               LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_AR_RELEASE_MINOR_VERSION               LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_H_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_H_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_H_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_H_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_H_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_H_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : LIN_AR_RELEASE_MAJOR_VERSION "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : LIN_AR_RELEASE_MINOR_VERSION "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_H_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_H_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_H_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_H_SW_PATCH_VER "
#endif
/*=================================================CONSTANTS========================================*/

/*============================================DEFINES AND MACROS====================================*/
/* Specification of Lin Driver : [SWS_Lin_00054] */
#define LIN_E_UNINIT            ((uint8)0x00U)
#define LIN_E_INVALID_CHANNEL   ((uint8)0x02U)
#define LIN_E_INVALID_POINTER   ((uint8)0x03U)
#define LIN_E_STATE_TRANSITION  ((uint8)0x04U)
#define LIN_E_PARAM_POINTER     ((uint8)0x05U)
#define LIN_E_TIMEOUT           ((uint8)0x06U)

/*===================================================ENUMS==========================================*/
typedef enum
{
    LIN_INIT_ID              =   (uint8)0x00U,
    LIN_GETVERSIONINFO_ID    =   (uint8)0x01U, 
    LIN_SENDFRAME_ID         =   (uint8)0x04U, 
    LIN_GOTOSLEEP_ID         =   (uint8)0x06U, 
    LIN_WAKEUP_ID            =   (uint8)0x07U,
    LIN_GETSTATUS_ID         =   (uint8)0x08U,
    LIN_GOTOSLEEPINTERNAL_ID =   (uint8)0x09U, 
    LIN_CHECKWAKEUP_ID       =   (uint8)0x0AU, 
    LIN_WAKEUPINTERNAL_ID    =   (uint8)0x0BU 
} Lin_ApiFunctionIdType;
/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

#if (STD_ON == LIN_MULTICORE_SUPPORT)
    #define Lin_GetCoreID() GetCoreID()
#else
    #define Lin_GetCoreID() (LIN_UNALLOCATEDPAR_CORE_ID)
#endif /* (STD_ON == LIN_MULTICORE_SUPPORT) */

#define LIN_CORE_NUM                    MCAL_CORE_NUM

/* Specification of Lin Driver : [SWS_Lin_00227] */
typedef struct{
    VAR(uint8,                  LIN_VAR) u16Lin_SIUPin;
    VAR(uint8,                  LIN_VAR) u8CoreId;
}Lin_CoreMapItemType;
typedef struct
{
#if (LIN_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        CONST(Mcal_DemErrorType, LIN_CONST) Lin_E_TimeoutCfg;
#endif

        CONST(uint8, LIN_CONST) u8Lin_MaxHWChannels;

        CONSTP2CONST(Lin_ChannelConfigType, LIN_APPL_CONST, LIN_CONST) pLin_Channel[LIN_HW_MAX_MODULES];
        
        CONSTP2CONST(Lin_CoreMapItemType, LIN_APPL_CONST, LIN_CONST) coreMap;
} Lin_ConfigType;
/*====================================GLOBAL VARIABLE DECLARATIONS==================================*/
 
/*==============================================GLOBAL FUNCTIONS====================================*/

#if LIN_VERSION_INFO_API == STD_ON
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
 FUNC (void, LIN_CODE) Lin_GetVersionInfo (P2VAR (Std_VersionInfoType, AUTOMATIC, \
              LIN_APPL_DATA) versioninfo);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"
#endif  /*LIN_VERSION_INFO_API */

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE)  Lin_CheckWakeup(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE)            Lin_Init(P2CONST(Lin_ConfigType, AUTOMATIC, LIN_APPL_CONST) Config);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE)  Lin_GoToSleepInternal(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Lin_StatusType, LIN_CODE)  Lin_GetStatus(VAR(uint8, AUTOMATIC) Channel, \
        P2P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) Lin_SduPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"                              
FUNC(Std_ReturnType, LIN_CODE)  Lin_SendFrame(VAR(uint8, AUTOMATIC) Channel, \
        P2CONST(Lin_PduType, AUTOMATIC,LIN_APPL_CONST) PduInfoPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"  
FUNC(Std_ReturnType, LIN_CODE)  Lin_GoToSleep(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"  

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"  
FUNC(Std_ReturnType, LIN_CODE)  Lin_WakeupInternal(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"  

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"  
FUNC(Std_ReturnType, LIN_CODE)  Lin_Wakeup(VAR(uint8, AUTOMATIC) Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

/*=================================EXTERNAL CONSTANTS===============================================*/

extern CONST(Lin_ConfigType,LIN_CONST)Lin_Config;


#ifdef __cplusplus
}
#endif

#endif /* LIN_H */

/** @} */
