/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Wdg
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     :-
*   Autosar Conf.Variant :-
*   SW Version           :-
*   Build Version        :-
*   *****************************************************************************/
/**
*   @file    Wdg_Module.c
*   @version 3.0.0
*
*   @addtogroup Wdg
*   @{
*/
/*PRQA S 0686,2844,3432,2842,2834 EOF*/

#ifdef __cplusplus
extern "C"{
#endif


/*====================================== INCLUDE FILES==========================================*/
#include "Wdg_Module.h"/*PRQA S 0380*/
#if (WDG_ERROR_CHECK ==STD_ON)
#include "Det.h"
#endif
#if (WDG_DEM_REPORT_ERROR_ENABLE == STD_OFF)
#include "Dem.h"
#endif
#include "Gpt.h"
#include "Wdg_AutoSar_Wrapper.h"
#include "SchM_Wdg.h"
/*============================= SOURCE FILE VERSION INFORMATION===================================*/


#define WDG_C_VENDOR_ID                      176
#define WDG_C_VERSION_MAJOR                  4
#define WDG_C_VERSION_MINOR                  4
#define WDG_C_VERSION_REVISION               0
#define WDG_C_SW_VERSION_MAJOR               3
#define WDG_C_SW_VERSION_MINOR               0
#define WDG_C_SW_VERSION_PATCH               0

/*=================================== FILE VERSION CHECKS========================================*/

#if (WDG_C_VENDOR_ID != WDG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : WDG_C_VENDOR_ID "
#endif
#if (WDG_C_VERSION_MAJOR != WDG_AR_RELEASE_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_C_VERSION_MAJOR "
#endif
#if (WDG_C_VERSION_MINOR != WDG_AR_RELEASE_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_C_VERSION_MINOR "
#endif
#if (WDG_C_VERSION_REVISION != WDG_H_REVISION_VERSION)
    #error " NON-MATCHED DATA : WDG_C_VERSION_REVISION "
#endif
#if (WDG_C_SW_VERSION_MAJOR != WDG_H_SW_MAJOR_VERSION)
    #error " NON-MATCHED DATA : WDG_C_SW_VERSION_MAJOR "
#endif
#if (WDG_C_SW_VERSION_MINOR != WDG_H_SW_MINOR_VERSION)
    #error " NON-MATCHED DATA : WDG_C_SW_VERSION_MINOR "
#endif
#if (WDG_C_SW_VERSION_PATCH != WDG_H_SW_PATCH_VERSION)
    #error " NON-MATCHED DATA : WDG_C_SW_VERSION_PATCH "
#endif
#define WDG_START_SEC_VAR_INIT
#include "Wdg_MemMap.h"
VAR(uint32, WDG_VAR) Wdg_u32Timeout[WDG_INSTANCES_NUM] = {0x0u};
#define WDG_STOP_SEC_VAR_INIT
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_INIT
#include "Wdg_MemMap.h"
VAR(uint32, WDG_VAR) Wdg_u32GptPeriod[WDG_INSTANCES_NUM] = {0x0u};
#define WDG_STOP_SEC_VAR_INIT
#include "Wdg_MemMap.h"

#define WDG_START_SEC_VAR_NO_INIT
#include "Wdg_MemMap.h"
P2CONST(Wdg_ConfigType, WDG_VAR, WDG_APPL_CONST) pWdg_ConfigPtr[WDG_INSTANCES_NUM] ;
#define WDG_STOP_SEC_VAR_NO_INIT
#include "Wdg_MemMap.h"

#define SWT_MIN_VALUE_TIMEOUT_U32               (0x100u)

#define WDG_START_SEC_VAR_INIT
#include "Wdg_MemMap.h"
VAR(Wdg_Status_Type, WDG_VAR) eWdg_DriverStatus[WDG_INSTANCES_NUM] = {WDG_UNINIT};
#define WDG_STOP_SEC_VAR_INIT
#include "Wdg_MemMap.h"

#if (STD_ON == WDG_ERROR_CHECK)
#define WDG_START_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"
static CONST(uint8, WDG_CONST) u8Wdg_Index[WDG_INSTANCES_NUM] =
{
		WdgIndex0,
		WdgIndex1,
		WdgIndex2,
		WdgIndex3,
		WdgIndex4,
		WdgIndex5,
		WdgIndex6,
		WdgIndex7
};
#define WDG_STOP_SEC_CONFIG_DATA
#include "Wdg_MemMap.h"
#endif

#if (WDG_ERROR_CHECK ==STD_ON)
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(void, WDG_CODE) Wdg_102DetReportError \
( \
    VAR(uint8, AUTOMATIC) Wdg_102InstanceId, \
    VAR(uint8, AUTOMATIC) ApiId, \
    VAR(uint8, AUTOMATIC) ErrorId \
)
{
    (void)Det_ReportError((uint16)WDG_H_MODULE_ID, \
        (uint8)u8Wdg_Index[Wdg_102InstanceId], ApiId, ErrorId);
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif

#if (WDG_DEM_REPORT_ERROR_ENABLE == STD_OFF)
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(void, WDG_CODE)Wdg_102DemReportErrorStatus \
( \
    VAR(Dem_EventIdType, AUTOMATIC) Wdg_102EventId, \
    VAR(Dem_EventStatusType, AUTOMATIC) Wdg_102EventStatus \
)
{
	(void)Dem_SetEventStatus((Dem_EventIdType)Wdg_102EventId, Wdg_102EventStatus);
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

WDG_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_CheckHwSettings \
( \
    P2CONST(SWT_ModeConfig_Type, AUTOMATIC, WDG_APPL_CONST) Wdog_ConfigPtr \
);

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"



/*******************************************************************************
**  Service Name     : Wdg_GetVersionInfoVerify                                                                                                    
**  Description      : Verify GetVersionInfo Error.                                                                                                   
**  Parameters (in)  : pVersioninfo: Pointer to where to store the version     
**                     information of this module.                                                                                                  
**  Parameters (out) : None                                                                                                                          
**  Return value     : Std_ReturnType                                                                                                                 
*******************************************************************************/
#if (STD_ON == WDG_ERROR_CHECK)
#if(WDG_VERSION_INFO_API==STD_ON)
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_GetVersionInfoVerify \
( \
	P2CONST(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) pVersioninfo, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    if (NULL_PTR != pVersioninfo)
    {
        u8Wdg_VerifyRetVal = (Std_ReturnType)E_OK;  
    }
    else
    {
#if (STD_ON == WDG_ERROR_CHECK)
        Wdg_102DetReportError(u8Wdg_Index[SWT_ModuleID],(uint8)(WDG_GETVERSION_ID),(uint8)(WDG_E_PARAM_POINTER));
#endif
    }
    return u8Wdg_VerifyRetVal;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif
#endif
/*******************************************************************************
**  Service Name     : Wdg_GetVersionInfo                                                                                                               
**  Description      : Returns the version information of the module.                                                                          
**  Service ID       : 0x04                                                                                                                        
**  Sync/Async       : Synchronous                                                                                                                    
**  Parameters (in)  : versioninfo: Pointer to where to store the version     
**                     information of this module.                                                                                                    
**  Parameters (out) : None                                                                                                                           
**  Return value     : None                                                                                                                          
*******************************************************************************/
#if(WDG_VERSION_INFO_API==STD_ON)
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) Wdg_RunGetVersionInfo \
( \
		P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) Versioninfo, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{
    (void)SWT_ModuleID;
#if (STD_ON == WDG_ERROR_CHECK)
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    u8Wdg_VerifyRetVal = Wdg_GetVersionInfoVerify(Versioninfo,SWT_ModuleID);
    if ((Std_ReturnType)E_OK == u8Wdg_VerifyRetVal)
    {
#endif
        (Versioninfo)->vendorID         = (uint16)WDG_H_VENDOR_ID;
        (Versioninfo)->moduleID         = (uint8)WDG_H_MODULE_ID;
        (Versioninfo)->sw_major_version = (uint8)WDG_H_SW_MAJOR_VERSION;
        (Versioninfo)->sw_minor_version = (uint8)WDG_H_SW_MINOR_VERSION;
        (Versioninfo)->sw_patch_version = (uint8)WDG_H_SW_PATCH_VERSION;
#if (STD_ON == WDG_ERROR_CHECK)
    }
#endif
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
#endif
/*******************************************************************************
**  Service Name     : Wdg_LLDrivers_Wdog_CheckHwSettings
**
**  Description      : Check Hardware Settings.
**
**  Parameters (in)  : Wdog_ConfigPtr : Pointer to configuration set.
**
**  Parameters (out) : None
**
**  Return value     : Std_ReturnType
**
*******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_CheckHwSettings \
( \
    P2CONST(SWT_ModeConfig_Type, AUTOMATIC, WDG_APPL_CONST) Wdog_ConfigPtr \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Response = (Std_ReturnType)E_OK;
    if (NULL_PTR == Wdog_ConfigPtr)
    {
        u8Response = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if (Wdog_ConfigPtr->SWT_Timeout < SWT_MIN_VALUE_TIMEOUT_U32)
        {
            u8Response = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            if((SWT_Lock_Type)SWT_Hardlock == Wdog_ConfigPtr->SWT_Lock_Mode)
            {
                u8Response = (Std_ReturnType)E_NOT_OK;
            }
            else{
                /*nothing*/
            }
            if ((SWT_Status_Type)SWT_Enable == Wdog_ConfigPtr->SWT_WindowMode)
            {
                if (Wdog_ConfigPtr->SWT_Timeout< Wdog_ConfigPtr->SWT_WindowValue)
                {
                    u8Response = (Std_ReturnType)E_NOT_OK;
                }
            }
        }
    }
    return u8Response;
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
WDG_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_ModeVerify
(
    VAR(WdgIf_ModeType, AUTOMATIC) eWdg_Mode,
    VAR(Wdg_ServiceId_Type, AUTOMATIC)eFunctionApiId,
    VAR(Wdg_ErrorId_Type, AUTOMATIC)eError,
    VAR(SWT_ModuleID_Type, AUTOMATIC)Wdg_Mode_instance
)
{
   VAR(Std_ReturnType, AUTOMATIC) u8Wdg_Valid = (Std_ReturnType)E_OK;
   VAR(boolean, AUTOMATIC) bWdg_DisableRejectedErrActive  = (boolean)FALSE;
   VAR(boolean, AUTOMATIC) bWdg_ModeFailedErrActive  = (boolean)FALSE;
#if (WDG_DISABLE_ALLOWED == STD_OFF)
   if (WDGIF_OFF_MODE == eWdg_Mode)
   {
       bWdg_DisableRejectedErrActive  = (boolean)TRUE;
       u8Wdg_Valid = (Std_ReturnType)E_NOT_OK;
   }
#endif
    if((WDGIF_OFF_MODE != eWdg_Mode)&&(WDGIF_FAST_MODE != eWdg_Mode)
        &&(WDGIF_SLOW_MODE != eWdg_Mode))
    {
#if (WDG_ERROR_CHECK == STD_ON)
        if(Wdg_Mode_instance <= SWT7_AO )
        {
            Wdg_102DetReportError(u8Wdg_Index[Wdg_Mode_instance],(uint8)(eFunctionApiId),(uint8)(eError));
        } 
#else
       (void)eFunctionApiId;
       (void)eError;
#endif
       bWdg_ModeFailedErrActive  = (boolean)TRUE;
       u8Wdg_Valid = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        if(Wdg_Mode_instance <= SWT7_AO)
        {
            if ((Std_ReturnType)E_NOT_OK \
                == Wdg_CheckHwSettings(pWdg_ConfigPtr[Wdg_Mode_instance]->SWT_Config_Type->  /* polyspace RTE:IDP */
                    SWT_Config[eWdg_Mode]))
            {
            #if (WDG_ERROR_CHECK == STD_ON)
                Wdg_102DetReportError(u8Wdg_Index[Wdg_Mode_instance],(uint8)(eFunctionApiId),(uint8)(eError));
            #endif
                bWdg_ModeFailedErrActive  = (boolean)TRUE;
                u8Wdg_Valid = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
#if (WDG_DEM_REPORT_ERROR_ENABLE == STD_OFF)
    if((uint32)STD_ON == Wdg_E_Disable_Rejected.state)
    {
        #if (WDG_DISABLE_ALLOWED == STD_OFF)
        if((boolean)TRUE == bWdg_DisableRejectedErrActive)
        {
            (void) Wdg_102DemReportErrorStatus((Dem_EventIdType)Wdg_E_Disable_Rejected.id, \
                DEM_EVENT_STATUS_FAILED);
        }
        #else
        (void)bWdg_DisableRejectedErrActive;
        #endif
    }
    if((uint32)STD_ON == Wdg_E_Mode_Failed.state)
    {
        if((boolean)TRUE == bWdg_ModeFailedErrActive)
        {
            (void) Wdg_102DemReportErrorStatus((Dem_EventIdType)Wdg_E_Mode_Failed.id, \
                DEM_EVENT_STATUS_FAILED);
        }
    }
#else
    (void)bWdg_ModeFailedErrActive;
    (void)bWdg_DisableRejectedErrActive;
#endif
    return u8Wdg_Valid;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
**  Service Name     : Wdg_InitVerify                                                                                                                    
**  Description      : Verify Init Error.                                     
**  Parameters (in)  : pConfigPtr: Pointer to configuration set.                                                                                        
**  Parameters (out) : None                                                                                                                            
**  Return value     : Std_ReturnType                                                                                                                  
*******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_InitVerify \
( \
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) pConfigPtr, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    if ((WDG_BUSY == eWdg_DriverStatus[SWT_ModuleID])||(WDG_UNINIT != eWdg_DriverStatus[SWT_ModuleID]))
    {
#if (STD_ON == WDG_ERROR_CHECK)
        Wdg_102DetReportError(u8Wdg_Index[SWT_ModuleID],(uint8)(WDG_INIT_ID),(uint8)(WDG_E_DRIVER_STATE));
#endif
    }
#if(WDG_POSTBUILD_SUPPORT == STD_ON)
    else if(NULL_PTR == pConfigPtr)
#else
    else if (NULL_PTR != pConfigPtr)
#endif
    {
#if (STD_ON == WDG_ERROR_CHECK)
        Wdg_102DetReportError(u8Wdg_Index[SWT_ModuleID],(uint8)(WDG_INIT_ID),(uint8)(WDG_E_INIT_FAILED));
#endif
    }
    else      
    {
#if (WDG_POSTBUILD_SUPPORT == STD_ON)
            pWdg_ConfigPtr[SWT_ModuleID] = pConfigPtr;
#else

            if (SWT_ModuleID==SWT0)
            {
#if (WDGINSTANCE0==STD_ON)
                pWdg_ConfigPtr[SWT_ModuleID] = &Wdg_Config_0;
#endif
            }
            else if (SWT_ModuleID==SWT1)
            {
#if (WDGINSTANCE1==STD_ON)
                pWdg_ConfigPtr[SWT_ModuleID] = &Wdg_Config_1;
#endif
            }
            else if (SWT_ModuleID==SWT2)
            {
#if (WDGINSTANCE2==STD_ON)
                pWdg_ConfigPtr[SWT_ModuleID] = &Wdg_Config_2;
#endif
            }
            else if (SWT_ModuleID==SWT3)
            {
#if (WDGINSTANCE3==STD_ON)
                pWdg_ConfigPtr[SWT_ModuleID] = &Wdg_Config_3;
#endif
            }
            else if (SWT_ModuleID==SWT4)
            {
#if (WDGINSTANCE4==STD_ON)
                pWdg_ConfigPtr[SWT_ModuleID] = &Wdg_Config_4;
#endif
            }
            else if (SWT_ModuleID==SWT5)
            {
#if (WDGINSTANCE5==STD_ON)
                pWdg_ConfigPtr[SWT_ModuleID] = &Wdg_Config_5;
#endif
            }
            else if (SWT_ModuleID==SWT6)
            {
#if (WDGINSTANCE6==STD_ON)
                pWdg_ConfigPtr[SWT_ModuleID] = &Wdg_Config_6;
#endif
            }
            else if (SWT_ModuleID==SWT7_AO)
            {
#if (WDGINSTANCE7_AO==STD_ON)
                pWdg_ConfigPtr[SWT_ModuleID] = &Wdg_Config_7;
#endif
            }
            else
            {
                /*nothing*/
            }
#endif
        if(SWT_ModuleID <= SWT7_AO)
        {
            u8Wdg_VerifyRetVal = Wdg_ModeVerify(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->SWT_DefaultRunMode,
                WDG_INIT_ID, WDG_E_PARAM_CONFIG,SWT_ModuleID);
        }
    }
    return u8Wdg_VerifyRetVal;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
**  Service Name     : Wdg_SetModeVerify                                      
**                                                                            
**  Description      : Verify SetMode Error.                                  
**                                                                            
**  Parameters (in)  : eMode: One of the following statically configured modes:
**                           1. WDGIF_OFF_MODE                                
**                           2. WDGIF_SLOW_MODE                               
**                           3. WDGIF_FAST_MODE                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                         
**                                                                            
*******************************************************************************/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

WDG_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_SetModeVerify \
( \
    VAR(WdgIf_ModeType, WDG_VAR) eMode, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    if((WDG_IDLE != eWdg_DriverStatus[SWT_ModuleID]))
    {
#if (STD_ON == WDG_ERROR_CHECK)
        Wdg_102DetReportError(u8Wdg_Index[SWT_ModuleID],(uint8)(WDG_SETMODE_ID),(uint8)(WDG_E_DRIVER_STATE));
#endif
    }
    else
    {
        u8Wdg_VerifyRetVal = Wdg_ModeVerify(eMode, WDG_SETMODE_ID, WDG_E_PARAM_MODE,SWT_ModuleID);
    }
    return u8Wdg_VerifyRetVal;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
**  Service Name     : WdgTriggerVerify                                       
**                                                                            
**  Description      : Verify the Trigger Status.                             
**                                                                            
**  Parameters (in)  : None                                                   
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                         
**                                                                            
*******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(Std_ReturnType, WDG_CODE) WdgTriggerVerify(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    SchM_Enter_Wdg_EXCLUSIVE_AREA_05();
    if(WDG_IDLE != eWdg_DriverStatus[SWT_ModuleID])
    {
        #if (STD_ON == WDG_ERROR_CHECK)
        Wdg_102DetReportError(u8Wdg_Index[SWT_ModuleID],(uint8)(WDG_TRIGGER_ID),(uint8)(WDG_E_DRIVER_STATE));
        #endif
    }
    else
    {
        u8Wdg_VerifyRetVal = (Std_ReturnType)E_OK;
    }
    SchM_Exit_Wdg_EXCLUSIVE_AREA_05();          
    return u8Wdg_VerifyRetVal;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
**  Service Name     : WdgTrigger                               
**                                                                            
**  Description      : Watch Dog Trigger.                                     
**                                                                            
**  Parameters (in)  : None                                                   
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(void, WDG_CODE) WdgTrigger(VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    u8Wdg_VerifyRetVal = WdgTriggerVerify(SWT_ModuleID);
    if((Std_ReturnType)E_OK == u8Wdg_VerifyRetVal)
    {
        (void)Wdg_Autosar_wrapper_Trigger(SWT_ModuleID);
    }
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

/*******************************************************************************
**  Service Name     : Wdg_Init                                                                                                                        
**  Description      : Configured core Initialization function                
**                    * This function initializes:                            
**                    * WDG core specific global variables                    
**                    * WDG core specific controller settings                                                                                   
**  Service ID       : 0x00                                                                                                                           
**  Sync/Async       : Synchronous                                                                                                                   
**  Reentrancy       : Non-Reentrant                                                                                                                  
**  Parameters (in)  : ConfigPtr: Pointer to configuration set.
**  Parameters (out) : None                                                                                                                            
**  Return value     : None                                                                                                                             
*******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

FUNC(void, WDG_CODE) Wdg_RunInstance_Init \
( \
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{

    if((Std_ReturnType)E_OK == Wdg_InitVerify(ConfigPtr,SWT_ModuleID) )
    {
        (void)Wdg_Autosar_Wrapper_Init(SWT_ModuleID);
    }
    else{
        if(SWT_ModuleID <= SWT7_AO)
        {
    	    pWdg_ConfigPtr[SWT_ModuleID] = NULL_PTR;
            eWdg_DriverStatus[SWT_ModuleID] = WDG_UNINIT;
        }
    }
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
**  Service Name     : Wdg_SetMode                                            
**                                                                            
**  Description      : Switches the watchdog into the mode Mode.              
**                                                                            
**  Service ID       : 0x01                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : Mode: One of the following statically configured modes:
**                           1. WDGIF_OFF_MODE                                
**                           2. WDGIF_SLOW_MODE                               
**                           3. WDGIF_FAST_MODE                               
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                         
**                                                                            
*******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
FUNC(Std_ReturnType, WDG_CODE) Wdg_RunInstance_SetMode \
( \
	VAR(WdgIf_ModeType, WDG_VAR) Mode, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{
    VAR(uint32, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Wdg_ReturnValue = (Std_ReturnType)E_NOT_OK;
    u8Wdg_VerifyRetVal = Wdg_SetModeVerify(Mode,SWT_ModuleID);
    if ((Std_ReturnType)E_OK == u8Wdg_VerifyRetVal)
    {
        u32Wdg_ReturnValue = (uint32)Wdg_Autosar_Wrapper_SetMode(SWT_ModuleID,Mode);
    }
    return (Std_ReturnType)u32Wdg_ReturnValue;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
**  Service Name     : Wdg_SetTriggerConditionVerify                          
**                                                                            
**  Description      : Verify SetTriggerCondition Error.                      
**                                                                            
**  Parameters (in)  : u16Timeout: Timeout value (milliseconds) for setting the  
**                     trigger counter.                                       
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                         
**                                                                            
*******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
WDG_INLINE FUNC(Std_ReturnType, WDG_CODE) Wdg_SetTriggerConditionVerify \
( \
    VAR(uint32,AUTOMATIC) u32Timeout, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;

    if ((WDG_UNINIT == eWdg_DriverStatus[SWT_ModuleID]) )
    {
#if (STD_ON == WDG_ERROR_CHECK)

        Wdg_102DetReportError(u8Wdg_Index[SWT_ModuleID],
        		(uint8)(WDG_SETTRIGGERCONDITION_ID),(uint8)(WDG_E_DRIVER_STATE));
#endif
    }
    else if ((u32Timeout * 1000U) > WDG_MAX_TIMEOUT_U32)
    {        
#if (STD_ON == WDG_ERROR_CHECK)
        Wdg_102DetReportError(u8Wdg_Index[SWT_ModuleID], \
        		(uint8)(WDG_SETTRIGGERCONDITION_ID),(uint8)(WDG_E_PARAM_TIMEOUT));
#endif
    }
    else
    {
        u8Wdg_VerifyRetVal = (Std_ReturnType)E_OK;
    }
    return u8Wdg_VerifyRetVal;
}
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else
#define WDG_STOP_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"
/*******************************************************************************
**  Service Name     : Wdg_RunSetTriggerCondition                                
**                                                                            
**  Description      : Sets the timeout value for the trigger counter.        
**                                                                            
**  Service ID       : 0x03                                                   
**                                                                            
**  Sync/Async       : Synchronous                                            
**                                                                            
**  Reentrancy       : Non-Reentrant                                          
**                                                                            
**  Parameters (in)  : timeout: Timeout value (milliseconds) for setting      
**                     the trigger counter.                                   
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : None                                                   
**                                                                            
*******************************************************************************/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else
#define WDG_START_SEC_RAMCODE
#endif
#include "Wdg_MemMap.h"

FUNC(void, WDG_CODE) Wdg_RunSetTriggerCondition \
( \
    VAR(uint16,AUTOMATIC) timeout, \
    VAR(SWT_ModuleID_Type, WDG_VAR) SWT_ModuleID \
)
{
    VAR(Std_ReturnType, AUTOMATIC) u8Wdg_VerifyRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Wdg_Gpt_timeout = 0;

    u8Wdg_VerifyRetVal = Wdg_SetTriggerConditionVerify(timeout,SWT_ModuleID);
    if((Std_ReturnType)E_OK == u8Wdg_VerifyRetVal)
    {
        VAR(uint32, AUTOMATIC) u32getGptpasstime = 0;
        SchM_Enter_Wdg_EXCLUSIVE_AREA_04();
        #if (GPT_TIME_ELAPSED_API==STD_ON)
        u32getGptpasstime = Gpt_GetTimeElapsed(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel) ; /* polyspace RTE:IDP */
        #endif
        u32Wdg_Gpt_timeout = (uint32)(u32getGptpasstime/(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u32Wdg_TriggerSourceClock / 1000U)); /* polyspace RTE:ZDV*/
        

        if ((u32Wdg_Gpt_timeout > Wdg_u32Timeout[SWT_ModuleID]) || ((uint16)0 == timeout))
        {
            Wdg_u32Timeout[SWT_ModuleID] = 0u;
            SchM_Exit_Wdg_EXCLUSIVE_AREA_04();
            Gpt_StopTimer(pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u8Wdg_GptTimerChannel);
        }
        else
        {
            Wdg_u32Timeout[SWT_ModuleID] = \
                (uint32)(u32getGptpasstime / (pWdg_ConfigPtr[SWT_ModuleID]->SWT_Config_Type->u32Wdg_TriggerSourceClock /1000U)) /* polyspace RTE:ZDV*/
				+ ((uint32)timeout * 1000U);
            SchM_Exit_Wdg_EXCLUSIVE_AREA_04();
        }

    }
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
