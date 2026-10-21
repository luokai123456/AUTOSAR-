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
*   @file    Lin_AutoSar_Wrapper.h
*   @version 3.0.0
*
*   @brief   AUTOSAR Lin - Isolation level header file for LIN driver.
*   @details Header file for function definition on isolation level betwen high and low level driver.
*
*   @addtogroup Lin
*   @{
*/


#ifndef LIN_AUTOSAR_WRAPPER_H
#define LIN_AUTOSAR_WRAPPER_H

#ifdef __cplusplus
extern "C"
{
#endif

/*=======================================INCLUDE FILES==============================================*/

#include "Lin_LLDriver.h"
/* =====================================SOURCE FILE VERSION INFORMATION============================== */
#define LIN_ATS_H_VENDOR_ID                            LIN_VENDOR_ID_PLUGIN
#define LIN_ATS_H_AR_REL_MAJOR_VER                     LIN_AR_REL_MJR_VERSION_PLUGIN
#define LIN_ATS_H_AR_REL_MINOR_VER                     LIN_AR_REL_MNR_VERSION_PLUGIN
#define LIN_ATS_H_AR_REL_REV_VER                       LIN_AR_REL_REV_VERSION_PLUGIN
#define LIN_ATS_H_SW_MAJOR_VER                         LIN_SW_MAJOR_VERSION_PLUGIN
#define LIN_ATS_H_SW_MINOR_VER                         LIN_SW_MINOR_VERSION_PLUGIN
#define LIN_ATS_H_SW_PATCH_VER                         LIN_SW_PATCH_VERSION_PLUGIN
/* ============================================FILE VERSION CHECKS=================================== */
#if (LIN_VENDOR_ID_OUTPUT != LIN_ATS_H_VENDOR_ID)
    #error " NON-MATCHED DATA : LIN_ATS_H_VENDOR_ID "
#endif
#if (LIN_AR_REL_MJR_VERSION_PLUGIN != LIN_ATS_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_ATS_H_AR_REL_MAJOR_VER "
#endif
#if (LIN_AR_REL_MNR_VERSION_PLUGIN != LIN_ATS_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_ATS_H_AR_REL_MINOR_VER "
#endif
#if (LIN_AR_REL_REV_VERSION_OUTPUT != LIN_ATS_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : LIN_ATS_H_AR_REL_REV_VER "
#endif
#if (LIN_SW_MAJOR_VERSION_OUTPUT != LIN_ATS_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : LIN_ATS_H_SW_MAJOR_VER "
#endif
#if (LIN_SW_MINOR_VERSION_OUTPUT != LIN_ATS_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : LIN_ATS_H_SW_MINOR_VER "
#endif
#if (LIN_SW_PATCH_VERSION_OUTPUT != LIN_ATS_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : LIN_ATS_H_SW_PATCH_VER "
#endif
/*=================================================CONSTANTS========================================*/

/*============================================DEFINES AND MACROS====================================*/

/*===================================================ENUMS==========================================*/

/*=======================================STRUCTURES AND OTHER TYPEDEFS==============================*/

/*===========================================VARIABLE DECLARATIONS==================================*/

/*============================================FUNCTION PROTOTYPES===================================*/
#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_AutoSar_Wrapper_InitChannel(void);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_AutoSar_Wrapper_CheckWakeup(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_AutoSar_Wrapper_SendHeader(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_AutoSar_Wrapper_SendResponse(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) spLin_PduInfoPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_AutoSar_Wrapper_GoToSleep(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Std_ReturnType, LIN_CODE) Lin_AutoSar_Wrapper_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(Lin_StatusType, LIN_CODE) Lin_AutoSar_Wrapper_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Lin_Channel, \
        P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) u8pLin_SduPtr);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_AutoSar_Wrapper_WakeUp(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#define LIN_START_SEC_CODE
#include "Lin_MemMap.h"
FUNC(void, LIN_CODE) Lin_AutoSar_Wrapper_WakeUpInternal(CONST(uint8, AUTOMATIC) u8Lin_Channel);
#define LIN_STOP_SEC_CODE
#include "Lin_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* LIN_Wrapper_H */

/** @} */
