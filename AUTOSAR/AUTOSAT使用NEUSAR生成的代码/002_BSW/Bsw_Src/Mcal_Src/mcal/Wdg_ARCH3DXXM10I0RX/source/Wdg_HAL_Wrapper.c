/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Wdg
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*****************************************************************************/
/**
*   @file    Wdg_HAL_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Wdg MCAL driver.
*
*   @addtogroup Wdg
*   @{
*/
/*PRQA S 2844 EOF */    /* QAC_CWE */

#ifdef __cplusplus
extern "C"{
#endif


/*=======================================INCLUDE FILES==============================================*/
#include "Wdg_HAL_Wrapper.h"/*PRQA S 0380*/
#include "Wdg_Module.h"
/*=============================SOURCE FILE VERSION INFORMATION====================================*/
#define Wdg_HAL_WRA_C_VENDOR_ID                      176
#define Wdg_HAL_WRA_C_VERSION_MAJOR                  4
#define Wdg_HAL_WRA_C_VERSION_MINOR                  4
#define Wdg_HAL_WRA_C_VERSION_REVISION               0
#define Wdg_HAL_WRA_C_SW_VERSION_MAJOR               3
#define Wdg_HAL_WRA_C_SW_VERSION_MINOR               0
#define Wdg_HAL_WRA_C_SW_VERSION_PATCH               0

#if (Wdg_HAL_WRA_C_VENDOR_ID != Wdg_HAL_WRA_H_VENDOR_ID)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_C_VENDOR_ID "
#endif
#if (Wdg_HAL_WRA_C_VERSION_MAJOR != Wdg_HAL_WRA_H_VERSION_MAJOR)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_C_VERSION_MAJOR "
#endif
#if (Wdg_HAL_WRA_C_VERSION_MINOR != Wdg_HAL_WRA_H_VERSION_MINOR)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_C_VERSION_MINOR "
#endif
#if (Wdg_HAL_WRA_C_VERSION_REVISION != Wdg_HAL_WRA_H_VERSION_REVISION)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_C_VERSION_REVISION "
#endif
#if (Wdg_HAL_WRA_C_SW_VERSION_MAJOR != Wdg_HAL_WRA_H_SW_VERSION_MAJOR)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_C_SW_VERSION_MAJOR "
#endif
#if (Wdg_HAL_WRA_C_SW_VERSION_MINOR != Wdg_HAL_WRA_H_SW_VERSION_MINOR)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_C_SW_VERSION_MINOR "
#endif
#if (Wdg_HAL_WRA_C_SW_VERSION_PATCH != Wdg_HAL_WRA_H_SW_VERSION_PATCH)
    #error " NON-MATCHED DATA : Wdg_HAL_WRA_C_SW_VERSION_PATCH "
#endif

/*===============================================LOCAL FUNCTIONS====================================*/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE) Wdg_HAL_WRA_Init \
( \
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) pConfigPtr \
)
{
    VAR(uint32, AUTOMATIC) eWdg_Status = (uint32)STATUS_ERROR;
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_Ret = (Std_ReturnType)E_NOT_OK;
    
    eWdg_Status =  (uint32)SWT_LLD_Init(pConfigPtr->SWT_Config_Type);

    if(eWdg_Status == (Std_ReturnType)STATUS_SUCCESS)
    {
        u8Wdg_Ret = (Std_ReturnType)E_OK;
    } 
    return u8Wdg_Ret;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(uint32, WDG_CODE) Wdg_HAL_WRA_SetMode \
( \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID, \
	VAR(WdgIf_ModeType, WDG_VAR) Mode  \
)
{
    VAR(uint32, AUTOMATIC) eWdg_Status = (uint32)STATUS_ERROR;
    VAR(uint32, AUTOMATIC) u8Wdg_Ret = (Std_ReturnType)E_NOT_OK;
    
    eWdg_Status = (uint32)SWT_LLD_SetMode(SWT_ModuleID,Mode);
    if(eWdg_Status == (Std_ReturnType)STATUS_SUCCESS)/*PRQA S 2992,2996*/
    {
        u8Wdg_Ret = (Std_ReturnType)E_OK;
    }
    return u8Wdg_Ret;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) Wdg_HAL_WRA_Trigger(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    SWT_Trigger(SWT_ModuleID, \
        pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->  /* polyspace RTE:IDP */
            SWT_Config[pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->SWT_DefaultRunMode]->SWT_ServiceMode);
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#ifdef __cplusplus
}
#endif

/** @} */
