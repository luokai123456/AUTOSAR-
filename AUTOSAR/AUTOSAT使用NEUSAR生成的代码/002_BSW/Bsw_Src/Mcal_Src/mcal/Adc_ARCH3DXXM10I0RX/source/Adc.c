/****************************************************************************
*
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : Adc
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
*   @file    Adc.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

/* PRQA S 0380, 1006, 3432, 0686, 2982 EOF */
/* PRQA S 2844, 0491, 2877, 4499, 4491 EOF */    /* QAC_CWE */

#ifdef __cplusplus
extern "C"{
#endif

#include "Adc.h"
#include "Adc_AutoSar_Wrapper.h"
#include "Det.h"
#include "SchM_Adc.h"

#define ADC_C_VENDOR_ID                     176
#define ADC_C_AR_REL_MAJOR_VER              4
#define ADC_C_AR_REL_MINOR_VER              4
#define ADC_C_AR_REL_REV_VER                0   
#define ADC_C_SW_MAJOR_VER                  3
#define ADC_C_SW_MINOR_VER                  0
#define ADC_C_SW_PATCH_VER                  0

#if (ADC_VENDOR_ID               != ADC_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_C_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_C_AR_REL_MAJOR_VER "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_C_AR_REL_MINOR_VER "
#endif
#if (ADC_AR_REL_REV_VER != ADC_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_C_AR_REL_REV_VER "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_C_SW_MAJOR_VER "
#endif
#if (ADC_SW_MINOR_VER        != ADC_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_C_SW_MINOR_VER "
#endif
#if (ADC_SW_PATCH_VER        != ADC_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_C_SW_PATCH_VER "
#endif

#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) Adc_ConfigPtr[ADC_CORE_NUM] = {NULL_PTR};    /* PRQA S 0686 */
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
VAR(Adc_GlobalStatusType, ADC_VAR) Adc_GlobalStatus[ADC_CORE_NUM] = {ADC_GS_UNINIT};    /* PRQA S 0686 */
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT
#include "Adc_MemMap.h"
VAR(Adc_RunningHwUnitType, ADC_VAR) sAdc_RunningUnit[ADC_CORE_NUM][ADC_MAX_HW_UNITS];
#define ADC_STOP_SEC_VAR_NO_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT
#include "Adc_MemMap.h"
VAR(Adc_RunningGroupType, ADC_VAR) sAdc_RunningGroup[ADC_CORE_NUM][ADC_CONFIG_GROUPS];
#define ADC_STOP_SEC_VAR_NO_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT
#include "Adc_MemMap.h"
VAR(uint8, ADC_VAR) u8Adc_MainFunctionFlag[ADC_CONFIG_GROUPS][ADC_CORE_NUM] = {{0U}};
#define ADC_STOP_SEC_VAR_INIT
#include "Adc_MemMap.h"

#if (ADC_ENABLE_MULTICORE == STD_ON)
#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
VAR(Adc_GroupState, ADC_VAR) sAdc_GroupState[ADC_CONFIG_GROUPS] = {ADC_GROUP_STATUS_UNINIT};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
VAR(Adc_AdcHwInitState, ADC_VAR) sAdc_AdcHwInitState[ADC_MAX_HW_UNITS] = {ADC_HW_NOT_USE};
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
VAR(uint8, ADC_VAR) Adc_HwInitStateFlag = 0U;
#define ADC_STOP_SEC_VAR_SHARED_INIT
#include "Adc_MemMap.h"
#endif

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
#define ADC_START_SEC_VAR_NO_INIT
#include "Adc_MemMap.h"
static VAR(Adc_PowerStateType, ADC_VAR) eAdc_CurrentState[ADC_CORE_NUM];
#define ADC_STOP_SEC_VAR_NO_INIT
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT
#include "Adc_MemMap.h"
static VAR(Adc_PowerStateType, ADC_VAR) eAdc_TargetState[ADC_CORE_NUM];
#define ADC_STOP_SEC_VAR_NO_INIT
#include "Adc_MemMap.h"
#endif /* ADC_POWER_STATE_SUPPORTED == STD_ON */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) Adc_ReportRuntimeError \
( \
    VAR(uint8, ADC_VAR) u8Adc_ServiceId, \
    VAR(uint8, AUTOMATIC) u8Adc_ErrorId \
) 
{
    (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U, u8Adc_ServiceId, u8Adc_ErrorId);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_DEV_ERROR_DETECT)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
static FUNC(void, ADC_CODE) Adc_ReportError \
(                                           \
    VAR(uint8, ADC_VAR) u8Adc_ServiceId,    \
    VAR(uint8, AUTOMATIC) u8Adc_ErrorId     \
) 
{
    (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, u8Adc_ServiceId, u8Adc_ErrorId);
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_ENABLE_MULTICORE == STD_ON)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(Std_ReturnType, ADC_VAR) Adc_CoreVerify
(
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group,
    VAR(uint8, AUTOMATIC) u8Adc_ServiceId
)
{
    VAR(uint32, AUTOMATIC) u32CoreId = GetCoreID();
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = (1U << u32CoreId);/* polyspace RTE:SHF */
    VAR(Std_ReturnType, AUTOMATIC) u8Adc_RetValue = (Std_ReturnType)E_NOT_OK;
    VAR(uint8, AUTOMATIC) u8Adc_Coreflag = 0U; 

    u8Adc_Coreflag = (uint8)((u32Adc_ICoreId) & (Adc_ConfigPtr[u32CoreId]->Adc_CoreMapItem[u16Adc_Group].GroupCoreId));/* polyspace RTE:OBAI,NIV,IDP */
    if(u8Adc_Coreflag == 0U)
    {
        (void)Adc_ReportError(u8Adc_ServiceId, ADC_E_PARAM_CONFIG);
    }
    else
    {
        u8Adc_RetValue = (Std_ReturnType)E_OK;
    }
    return u8Adc_RetValue;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_InitVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_Init                         
**                                                                            
**  Parameters (in)  : pAdc_ConfigPtr: Pointer to configuration set
**                     u32Adc_CoreId: CoreId
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_InitVerify \
( \
    P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigPtr, \
    VAR(uint32, AUTOMATIC) u32Adc_CoreId
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetInitRetVal = (Std_ReturnType)E_NOT_OK;

    /** Specification of ADC Driver : [SWS_Adc_00107] **/
    if (Adc_GlobalStatus[u32Adc_CoreId] != ADC_GS_UNINIT)/* polyspace RTE:OBAI */
    {
        Adc_ReportError(ADC_INIT_ID, (uint8)ADC_E_ALREADY_INITIALIZED);
    }
#if (ADC_PRECOMPILE_SUPPORT == STD_ON)
    else if (pAdc_ConfigPtr != NULL_PTR)
#else
    else if (pAdc_ConfigPtr == NULL_PTR)
#endif
    {
        Adc_ReportError(ADC_INIT_ID, (uint8)ADC_E_PARAM_POINTER);
    }
    else
    {
        u8Adc_DetInitRetVal = (Std_ReturnType)E_OK;
    }

    return u8Adc_DetInitRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_SetupResultBufferVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_SetupResultBuffer                         
**                                                                            
**  Parameters (in)  : pAdc_DataBufferPtr: Pointer to configuration set
**                     u16Adc_Group: Group Id number                            
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBufferVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group, \
    P2CONST(Adc_ValueGroupType, ADC_CONST, ADC_APPL_CONST) pAdc_DataBufferPtr, \
    VAR(uint32, AUTOMATIC) u32Adc_CoreId
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetSetupResultBufferRetVal = (Std_ReturnType)E_NOT_OK;

    if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_CoreId])/* polyspace RTE:OBAI */ 
    {
        /** Specification of ADC Driver : [SWS_Adc_00434] **/
        Adc_ReportError(ADC_SETUPRESULTBUFFER_ID, (uint8)ADC_E_UNINIT);
    }
    else if (NULL_PTR == pAdc_DataBufferPtr)
    {
        /** Specification of ADC Driver : [SWS_Adc_00457] **/
        Adc_ReportError(ADC_SETUPRESULTBUFFER_ID, (uint8)ADC_E_PARAM_POINTER);
    }
    else if (ADC_CONFIG_GROUPS <= u16Adc_Group)
    {
        /** Specification of ADC Driver : [SWS_Adc_00423] **/
        Adc_ReportError(ADC_SETUPRESULTBUFFER_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetSetupResultBufferRetVal = Adc_CoreVerify(u16Adc_Group, ADC_SETUPRESULTBUFFER_ID);
#else
        u8Adc_DetSetupResultBufferRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetSetupResultBufferRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"


/** Specification of ADC Driver : [SWS_Adc_00228] **/
#if (STD_ON == ADC_DEINIT_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_DeInitVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_DeInit                        
**                                                                            
**  Parameters (in)  : None                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_DeInitVerify(void) {
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetDeInitRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00154] **/
        Adc_ReportError(ADC_DEINIT_API, (uint8)ADC_E_UNINIT);
    }
    else
    {
        u8Adc_DetDeInitRetVal = (Std_ReturnType)E_OK;
    }
    return u8Adc_DetDeInitRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_StartGroupConvVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_StartGroupConversion                        
**                                                                            
**  Parameters (in)  : u16Adc_GroupId                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_StartGroupConvVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetStartGroupConvRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00125] **/
        Adc_ReportError(ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00294] **/
        Adc_ReportError(ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_UNINIT);
    }
    else if (NULL_PTR == sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupResultBufferPtr)
    {
        /** Specification of ADC Driver : [SWS_Adc_00424] **/
        Adc_ReportError(ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_BUFFER_UNINIT);
    }
    else if (ADC_TRIGG_SRC_HW == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].SwOrHw)/* polyspace RTE:NIV,IDP */
    {
        /** Specification of ADC Driver : [SWS_Adc_00133] **/
        Adc_ReportError(ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_WRONG_TRIGG_SRC);
    }
#if (STD_ON == ADC_ENABLE_QUEUING)
    else if (sAdc_RunningUnit[u32Adc_ICoreId][Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].HwUnitId].HwUnit_QueueNumEmpSlot > ADC_QUEUE_MAX_DEPTH)
    {
        Adc_ReportError(ADC_STARTGROUPCONVERSION_ID, (uint8)ADC_E_QUEUE_FULL);
    }
#endif
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetStartGroupConvRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_STARTGROUPCONVERSION_ID);
#else
        u8Adc_DetStartGroupConvRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetStartGroupConvRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_StopGroupConvVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_StopGroupConversion         
**                                                                            
**  Parameters (in)  : Group                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType : Boolean variables used by functions
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_StopGroupConvVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetStopGroupConvRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00126] **/
        Adc_ReportError(ADC_STOPGROUPCONVERSION_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00295] **/
        Adc_ReportError(ADC_STOPGROUPCONVERSION_ID, (uint8)ADC_E_UNINIT);
    }
    else if (ADC_TRIGG_SRC_HW == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].SwOrHw)/* polyspace RTE:NIV,IDP */
    {
        /** Specification of ADC Driver : [SWS_Adc_00164] **/
        Adc_ReportError(ADC_STOPGROUPCONVERSION_ID, (uint8)ADC_E_WRONG_TRIGG_SRC);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetStopGroupConvRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_STOPGROUPCONVERSION_ID);
#else
        u8Adc_DetStopGroupConvRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetStopGroupConvRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_ENABLE_START_STOP_GROUP_API */

#if (STD_ON == ADC_READ_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_ReadGroupVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_ReadGroup                        
**                                                                            
**  Parameters (in)  : Group     
**                     pAdc_DataBufferPtr: Pointer to configuration set                      
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType : Boolean variables used by functions                                     
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType,ADC_APPL_CODE) Adc_ReadGroupVerify \
( \
    VAR(Adc_GroupType, ADC_VAR) u16Adc_GroupId, \
    P2CONST(Adc_ValueGroupType, ADC_CONST, ADC_APPL_DATA) pAdc_DataBufferPtr
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetReadGroupRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00152] **/
        Adc_ReportError(ADC_READGROUP_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00296] **/
        Adc_ReportError(ADC_READGROUP_ID, (uint8)ADC_E_UNINIT);
    }
    else if (NULL_PTR == pAdc_DataBufferPtr)
    {
        Adc_ReportError(ADC_READGROUP_ID, (uint8)ADC_E_PARAM_POINTER);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetReadGroupRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_READGROUP_ID);
#else
        u8Adc_DetReadGroupRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetReadGroupRetVal;
}   
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_DEV_ERROR_DETECT */

#if (STD_ON == ADC_HW_TRIGGER_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_EnableHWTriVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_EnableHardwareTrigger                        
**                                                                            
**  Parameters (in)  : Group                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType : Boolean variables used by functions                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_EnableHWTriVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetEnableHWTriRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00128] **/
        Adc_ReportError(ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00297] **/
        Adc_ReportError(ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_UNINIT);
    }
    else if (NULL_PTR == sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupResultBufferPtr)
    {
        /** Specification of ADC Driver : [SWS_Adc_00425] **/
        Adc_ReportError(ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_BUFFER_UNINIT);
    }
    else if ((Adc_TriggerSourceType)ADC_TRIGG_SRC_SW \
            == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].SwOrHw)/* polyspace RTE:NIV,IDP */
    {
        /** Specification of ADC Driver : [SWS_Adc_00136] **/
        Adc_ReportError(ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_WRONG_TRIGG_SRC);
    }
    else if ((Adc_GroupConvModeType)ADC_CONV_MODE_CONTINUOUS \
            == (Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].ConvMode))/* polyspace RTE:NIV,IDP */
    {
        /** Specification of ADC Driver : [SWS_Adc_00281] **/
        Adc_ReportError(ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_WRONG_CONV_MODE);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetEnableHWTriRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_ENABLEHARDWARETRIGGER_ID);
#else
        u8Adc_DetEnableHWTriRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetEnableHWTriRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_DisableHWTriVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_DisableHardwareTrigger                        
**                                                                            
**  Parameters (in)  : u16Adc_GroupId                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType : Boolean variables used by functions                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_DisableHWTriVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
)
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetDisableHWTriRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00129] **/
        Adc_ReportError(ADC_DISABLEHARDWARETRIGGER_ID,(uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00298] **/
        Adc_ReportError(ADC_DISABLEHARDWARETRIGGER_ID,(uint8)ADC_E_UNINIT);
    }
    else if ((Adc_TriggerSourceType)ADC_TRIGG_SRC_SW \
            == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].SwOrHw)/* polyspace RTE:NIV,IDP */
    {
        /** Specification of ADC Driver : [SWS_Adc_00137] **/
        Adc_ReportError(ADC_DISABLEHARDWARETRIGGER_ID,(uint8)ADC_E_WRONG_TRIGG_SRC);
    }
    else if ((Adc_GroupConvModeType)ADC_CONV_MODE_CONTINUOUS \
            == (Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].ConvMode))/* polyspace RTE:NIV,IDP */
    {
        /** Specification of ADC Driver : [SWS_Adc_00282] **/
        Adc_ReportError(ADC_DISABLEHARDWARETRIGGER_ID,(uint8)ADC_E_WRONG_CONV_MODE);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetDisableHWTriRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_DISABLEHARDWARETRIGGER_ID);
#else
        u8Adc_DetDisableHWTriRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetDisableHWTriRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif


#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_EnableGrpNotifVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_EnableGroupNotification                        
**                                                                            
**  Parameters (in)  : u16Adc_GroupId                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_EnableGrpNotifVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetGrpNotifEnRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00130] **/
        Adc_ReportError(ADC_ENABLEGROUPNOTIFICATION_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00299] **/
        Adc_ReportError(ADC_ENABLEGROUPNOTIFICATION_ID, (uint8)ADC_E_UNINIT);
    }
    else if ((NULL_PTR == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].GroupNotif)/* polyspace RTE:NIP,IDP */
        && (NULL_PTR == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].GroupNotif_OverFlow))/* polyspace RTE:NIP,IDP */
    {
        /** Specification of ADC Driver : [SWS_Adc_00165] **/
        Adc_ReportError(ADC_ENABLEGROUPNOTIFICATION_ID, (uint8)ADC_E_NOTIF_CAPABILITY);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetGrpNotifEnRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_ENABLEGROUPNOTIFICATION_ID);
#else
        u8Adc_DetGrpNotifEnRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetGrpNotifEnRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_DisableGrpNotifVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_DisableGroupNotification                        
**                                                                            
**  Parameters (in)  : u16Adc_GroupId                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_DisableGrpNotifVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetDisGrpNotifEnRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00131] **/
        Adc_ReportError(ADC_DISABLEGROUPNOTIFICATION_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00300] **/
        Adc_ReportError(ADC_DISABLEGROUPNOTIFICATION_ID, (uint8)ADC_E_UNINIT);
    }
    else if ((NULL_PTR == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].GroupNotif)/* polyspace RTE:NIP,IDP */
        && (NULL_PTR == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].GroupNotif_OverFlow))/* polyspace RTE:NIP,IDP */
    {
        /** Specification of ADC Driver : [SWS_Adc_00166] **/
        Adc_ReportError(ADC_DISABLEGROUPNOTIFICATION_ID, (uint8)ADC_E_NOTIF_CAPABILITY);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetDisGrpNotifEnRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_DISABLEGROUPNOTIFICATION_ID);
#else
        u8Adc_DetDisGrpNotifEnRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetDisGrpNotifEnRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_GRP_NOTIF_CAPABILITY */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_GetGroupStatusVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_GetGroupStatus                        
**                                                                            
**  Parameters (in)  : Group                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_GetGroupStatusVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetGetGroupStatusRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00225] **/
        Adc_ReportError(ADC_GETGROUPSTATUS_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00301] **/
        Adc_ReportError(ADC_GETGROUPSTATUS_ID, (uint8)ADC_E_UNINIT);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetGetGroupStatusRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_GETGROUPSTATUS_ID);
#else
        u8Adc_DetGetGroupStatusRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetGetGroupStatusRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_GetStreamLastPointerVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_GetStreamLastPointer                       
**                                                                            
**  Parameters (in)  : Group                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_GetStreamLastPointerVerify \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetGetStreamLastPointerRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if (ADC_CONFIG_GROUPS <= u16Adc_GroupId)
    {
        /** Specification of ADC Driver : [SWS_Adc_00218] **/
        Adc_ReportError(ADC_GETSTREAMLASTPOINTER_ID, (uint8)ADC_E_PARAM_GROUP);
    }
    else if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00302] **/
        Adc_ReportError(ADC_GETSTREAMLASTPOINTER_ID, (uint8)ADC_E_UNINIT);
    }
    else
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_DetGetStreamLastPointerRetVal = Adc_CoreVerify(u16Adc_GroupId, ADC_GETSTREAMLASTPOINTER_ID);
#else
        u8Adc_DetGetStreamLastPointerRetVal = (Std_ReturnType)E_OK;
#endif
    }

    return u8Adc_DetGetStreamLastPointerRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_SetPowerStateVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_SetPowerState                       
**                                                                            
**  Parameters (in)  : None                           
**                                                                            
**  Parameters (out) : pAdc_Result                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_SetPowerStateVerify \
( \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pAdc_Result \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetSetPowerStateRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00486] **/
        Adc_ReportError(ADC_SETPOWERSTATE_ID, (uint8)ADC_E_UNINIT);
    }
    else if(eAdc_TargetState[u32Adc_ICoreId] >= ADC_NODEFINE_POWER)
    {
        Adc_ReportError(ADC_SETPOWERSTATE_ID, (uint8)ADC_E_PERIPHERAL_NOT_PREPARED);
        *pAdc_Result = ADC_SEQUENCE_ERROR;
    }
    else
    {
        u8Adc_DetSetPowerStateRetVal = (Std_ReturnType)E_OK;
    }
    return u8Adc_DetSetPowerStateRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_GetCurrentPowerStateVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_GetCurrentPowerState                       
**                                                                            
**  Parameters (in)  : None                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_GetCurrentPowerStateVerify(void) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetGetCurrentPowerStateRetVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00491] **/
        Adc_ReportError(ADC_GETCURRENTPOWERSTATE_ID, (uint8)ADC_E_UNINIT);
        u8Adc_DetGetCurrentPowerStateRetVal = (Std_ReturnType)E_NOT_OK;
    }
    return u8Adc_DetGetCurrentPowerStateRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_GetTargetPowerStateVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - TargetPowerState                       
**                                                                            
**  Parameters (in)  : None                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_GetTargetPowerStateVerify(void) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetTargetPowerStateRetVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00493] **/
        Adc_ReportError(ADC_GETTARGETPOWERSTATE_ID, (uint8)ADC_E_UNINIT);
        u8Adc_DetTargetPowerStateRetVal = (Std_ReturnType)E_NOT_OK;
    }
    return u8Adc_DetTargetPowerStateRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*****************************************************************************
** Service Name       : Adc_PreparePowerStateVerify                                              
** 
** 
**  Description      : Det Check for AUTOSAR SWS API - Adc_PreparePowerState                       
**                                                                            
**  Parameters (in)  : eAdc_PowerState                           
**                                                                            
**  Parameters (out) : None                                                   
**                                                                            
**  Return value     : Std_ReturnType                                                    
**                                                                            
******************************************************************************/
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_PreparePowerStateVerify \
( \
    VAR(Adc_PowerStateType, AUTOMATIC) eAdc_PowerState \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetTargetPowerStateRetVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
    
    if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        /** Specification of ADC Driver : [SWS_Adc_00496] **/
        Adc_ReportError(ADC_PREPAREPOWERSTATE_ID, (uint8)ADC_E_UNINIT);
        u8Adc_DetTargetPowerStateRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(eAdc_PowerState >= ADC_NODEFINE_POWER)
    {
        /** Specification of ADC Driver : [SWS_Adc_00497] **/
        Adc_ReportError(ADC_PREPAREPOWERSTATE_ID, (uint8)ADC_E_POWER_STATE_NOT_SUPPORTED);
        u8Adc_DetTargetPowerStateRetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* No action */
    }
    return u8Adc_DetTargetPowerStateRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#endif /* ADC_POWER_STATE_SUPPORTED == STD_ON */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_MainFunctionVerify(void) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_DetMainFunctionRetVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */

    if ((Adc_GlobalStatusType)ADC_GS_UNINIT == Adc_GlobalStatus[u32Adc_ICoreId])/* polyspace RTE:OBAI */
    {
        Adc_ReportError(ADC_MAINFUNCTION_ID, (uint8)ADC_E_UNINIT);
    }
    else
    {
        u8Adc_DetMainFunctionRetVal = (Std_ReturnType)E_OK;
    }
    return u8Adc_DetMainFunctionRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_DEV_ERROR_DETECT */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Initializes the ADC hardware units and driver.         **
**                                                                            **
**  Service ID       : 0x00                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : Non-Reentrant                                          **
**                                                                            **
**  Parameters (in)  : ConfigPtr: Pointer to configuration set in Variant PB  **
**                     (Variant PC requires a NULL_PTR).                      **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
FUNC(void, ADC_CODE) Adc_Init(P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) ConfigPtr) 
{
    VAR(volatile uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_InitVerify(ConfigPtr, u32Adc_ICoreId) == (Std_ReturnType)E_OK)
    {
#endif
#if (ADC_PRECOMPILE_SUPPORT == STD_ON)
        Adc_ConfigPtr[u32Adc_ICoreId] = &Adc_Config;
        (void)ConfigPtr;
#else
        /** Specification of ADC Driver : [SWS_Adc_00054] **/
        Adc_ConfigPtr[u32Adc_ICoreId] = ConfigPtr;/* polyspace RTE:OBAI */
#endif /* ADC_PRECOMPILE_SUPPORT == STD_ON */
#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
        eAdc_CurrentState[u32Adc_ICoreId] = ADC_FULL_POWER;/* polyspace RTE:OBAI */
        eAdc_TargetState[u32Adc_ICoreId]= ADC_NODEFINE_POWER;/* polyspace RTE:OBAI */
#endif /* ADC_POWER_STATE_SUPPORTED == STD_ON */
        Adc_AutoSar_Wrapper_Init(Adc_ConfigPtr[u32Adc_ICoreId]);/* polyspace RTE:OBAI */
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Initializes ADC driver with the group specific result  **
**                     buffer start address where the conversion results will **
**                     application has to ensure that the application         **
**                     be stored. The buffer, where DataBufferPtr points to,  **
**                     can holdall the conversion results of the              **
**                     specified group. The initialization with               **
**                     Adc_SetupResultBuffer is required after reset, before  **
**                     a group conversion can be started.                     **
**                                                                            **
**  Service ID       : 0x0C                                                   **
**                                                                            **
**  Sync/Async       : Asynchronous                                           **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                     DataBufferPtr: Pointer to result data buffer.          **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : Std_ReturnType                                         **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, ADC_CODE) Adc_SetupResultBuffer \
( \
    VAR(Adc_GroupType, AUTOMATIC) Group, \
    CONSTP2VAR(Adc_ValueGroupType, ADC_CONST, ADC_APPL_CONST) DataBufferPtr \
)
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_RetSetupResultBuffer = (Std_ReturnType)E_NOT_OK;
    VAR(volatile uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();

#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_SetupResultBufferVerify(Group, DataBufferPtr, u32Adc_ICoreId) == (Std_ReturnType)E_OK)
    {
#endif  /* STD_ON == ADC_DEV_ERROR_DETECT */
        if(sAdc_RunningGroup[u32Adc_ICoreId][Group].GroupStatus != ADC_IDLE)/* polyspace RTE:OBAI */
        {
            /** Specification of ADC Driver : [SWS_Adc_00433] **/
            Adc_ReportRuntimeError(ADC_SETUPRESULTBUFFER_ID, (uint8)ADC_E_BUSY);
        }
        else
        {
            sAdc_RunningGroup[u32Adc_ICoreId][Group].GroupResultBufferPtr = DataBufferPtr;/* polyspace RTE:OBAI */
            u8Adc_RetSetupResultBuffer = (Std_ReturnType)E_OK;
        }
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif  /* STD_ON == ADC_DEV_ERROR_DETECT */

    return u8Adc_RetSetupResultBuffer;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

/*******************************************************************************
**  Description      : Returns all ADC HW Units to a state comparable         **
**                     to their power on reset state.                         **
**                                                                            **
**  Service ID       : 0x01                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : Non-Reentrant                                          **
**                                                                            **
**  Parameters (in)  : None                                                   **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
#if (STD_ON == ADC_DEINIT_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_DeInit(void) 
{
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_DeInitVerify() == (Std_ReturnType)E_OK)
    {
#endif   
        VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
        if(Adc_AutoSar_Wrapper_DeInit()== (Std_ReturnType)E_OK)
        {
            Adc_ConfigPtr[u32Adc_ICoreId] = NULL_PTR;/* polyspace RTE:OBAI */
        }
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif    
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_DEINIT_API */

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Starts the conversion of all channels of               **
**                     the requested ADC Channel group.                       **
**                                                                            **
**  Service ID       : 0x02                                                   **
**                                                                            **
**  Sync/Async       : Asynchronous                                           **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                     DataBufferPtr: Pointer to result data buffer.          **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
FUNC(void, ADC_CODE) Adc_StartGroupConversion(VAR(Adc_GroupType, AUTOMATIC) Group) 
{
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_StartGroupConvVerify(Group) == (Std_ReturnType)E_OK)
    {
#endif
        Adc_AutoSar_Wrapper_StartGroupConversion(Group);
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Stops the conversion of the requested ADC              **
**                     Channel group.                                         **
**                                                                            **
**  Service ID       : 0x03                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
FUNC(void, ADC_CODE) Adc_StopGroupConversion(VAR(Adc_GroupType, AUTOMATIC) Group) 
{
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_StopGroupConvVerify(Group) == (Std_ReturnType)E_OK)
    {
#endif
        Adc_AutoSar_Wrapper_StopGroupConversion(Group);
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_ENABLE_START_STOP_GROUP_API */

#if (STD_ON == ADC_READ_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Reads the group conversion result of the last          **
**                     completed conversion round of the requested group      **
**                     and stores the channel values starting at the          **
**                     DataBufferPtr address. The group channel values are    **
**                     stored in ascending channel number order ( in contrast **
**                     to the storage layout of the result buffer if streaming**
**                     access is configured).                                 **
**                                                                            **
**  Service ID       : 0x04                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                                                                            **
**  Parameters (out) : DataBufferPtr: ADC results of all channels of the      **
**                     selected group are stored in the data buffer addressed **
**                     with the pointer.                                      **
**                                                                            **
**  Return value     : Std_ReturnType                                         **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, ADC_CODE) Adc_ReadGroup \
( \
    VAR(Adc_GroupType, AUTOMATIC) Group, \
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) DataBufferPtr \
)
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_RetReadGroup = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_ReadGroupVerify(Group, DataBufferPtr) == (Std_ReturnType)E_OK)
    {
#endif
        u8Adc_RetReadGroup = Adc_AutoSar_Wrapper_ReadGroup(Group, DataBufferPtr);
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
    return u8Adc_RetReadGroup;
} /* STD_ON == ADC_READ_GROUP_API */
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_HW_TRIGGER_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Enable the hardware trigger.                           **
**                                                                            **
**  Service ID       : 0x05                                                   **
**                                                                            **
**  Sync/Async       : Asynchronous                                           **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
FUNC(void, ADC_CODE) Adc_EnableHardwareTrigger(VAR(Adc_GroupType, AUTOMATIC) Group) 
{
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_EnableHWTriVerify(Group) == (Std_ReturnType)E_OK)
    {
#endif
        Adc_AutoSar_Wrapper_EnableHardwareTrigger(Group);
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Disables the hardware trigger for the requested        **
**                     ADC Channel group.                                     **
**                                                                            **
**  Service ID       : 0x06                                                   **
**                                                                            **
**  Sync/Async       : Asynchronous                                           **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
FUNC(void, ADC_CODE) Adc_DisableHardwareTrigger(VAR(Adc_GroupType, AUTOMATIC) Group) 
{
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_DisableHWTriVerify(Group) == (Std_ReturnType)E_OK)
    {
#endif
        Adc_AutoSar_Wrapper_DisableHardwareTrigger(Group);
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Enables the notification mechanism for the requested   **
**                     ADC Channel group.                                     **
**                                                                            **
**  Service ID       : 0x07                                                   **
**                                                                            **
**  Sync/Async       : Asynchronous                                           **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
FUNC(void, ADC_CODE) Adc_EnableGroupNotification(VAR(Adc_GroupType, AUTOMATIC) Group) 
{
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_EnableGrpNotifVerify(Group) == (Std_ReturnType)E_OK)
    {
#endif
        VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
        /** Specification of ADC Driver : [SWS_Adc_00057] **/
        sAdc_RunningGroup[u32Adc_ICoreId][Group].GroupSwitchNotifCall = ADC_GROUP_NOTIFICATION_ENABLED;/* polyspace RTE:OBAI */
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Disables the notification mechanism for the requested  **
**                     ADC Channel group.                                     **
**                                                                            **
**  Service ID       : 0x08                                                   **
**                                                                            **
**  Sync/Async       : Asynchronous                                           **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
FUNC(void, ADC_CODE) Adc_DisableGroupNotification(VAR(Adc_GroupType, AUTOMATIC) Group) 
{
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_DisableGrpNotifVerify(Group) == (Std_ReturnType)E_OK)
    {
#endif
        VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
        /** Specification of ADC Driver : [SWS_Adc_00058] **/
        sAdc_RunningGroup[u32Adc_ICoreId][Group].GroupSwitchNotifCall = ADC_GROUP_NOTIFICATION_DISABLED;/* polyspace RTE:OBAI */
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_GRP_NOTIF_CAPABILITY */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Returns the conversion status of the requested ADC     **
**                     Channel group.                                         **
**                                                                            **
**  Service ID       : 0x09                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : Adc_StatusType                                         **
**                                                                            **
*******************************************************************************/
FUNC(Adc_StatusType, ADC_CODE) Adc_GetGroupStatus(VAR(Adc_GroupType, AUTOMATIC) Group) 
{
    VAR(Adc_StatusType, ADC_VAR) eAdc_GroupStatusRetVal = ADC_IDLE;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_GetGroupStatusVerify(Group) == (Std_ReturnType)E_OK)
    {
#endif
        VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
        /** Specification of ADC Driver : [SWS_Adc_00220] **/
        SchM_Enter_Adc_EXCLUSIVE_AREA_04();
        eAdc_GroupStatusRetVal = sAdc_RunningGroup[u32Adc_ICoreId][Group].GroupStatus;/* polyspace RTE:OBAI */
        SchM_Exit_Adc_EXCLUSIVE_AREA_04();
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
    return eAdc_GroupStatusRetVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Returns the number of valid samples per channel,       **
**                     stored in the result buffer.Reads a pointer, pointing  **
**                     to a position in the group result buffer. With the     **
**                     pointer position, the results of all group channels    **
**                     of the last completed conversion round can be          **
**                     accessed. With the pointer and the return value, all   **
**                     valid group conversion results can be accessed (the    **
**                     user has to take the layout of the result buffer into  **
**                     account).                                              **
**                                                                            **
**  Service ID       : 0x0B                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : Group: Numeric ID of requested ADC channel group.      **
**                                                                            **
**  Parameters (out) : PtrToSamplePtr: Pointer to result buffer pointer.      **
**                                                                            **
**  Return value     : Adc_StreamNumSampleType                                **
**                                                                            **
*******************************************************************************/
FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_GetStreamLastPointer \
( \
    VAR(Adc_GroupType, AUTOMATIC) Group, \
    P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) PtrToSamplePtr \
) 
{
    VAR(Adc_StreamNumSampleType, ADC_VAR) u16Adc_LastPoint = (Adc_StreamNumSampleType)0U;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_GetStreamLastPointerVerify(Group) == (Std_ReturnType)E_OK)
    {
#endif
        u16Adc_LastPoint = Adc_AutoSar_Wrapper_GetStreamLastPointer(Group, PtrToSamplePtr);
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
    else
    {
        *PtrToSamplePtr = NULL_PTR;
    }
#endif
    return u16Adc_LastPoint;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_VERSION_INFO_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Returns the version information of this module.        **
**                                                                            **
**  Service ID       : 0x0A                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : versioninfo: Pointer to where to store the version     **
**                     information of this module.                            **
**                                                                            **
**  Parameters (out) : None                                                   **
**                                                                            **
**  Return value     : None                                                   **
**                                                                            **
*******************************************************************************/
FUNC(void, ADC_CODE) Adc_GetVersionInfo \
( \
    P2VAR(Std_VersionInfoType, AUTOMATIC, ADC_APPL_DATA) versioninfo \
) 
{    
    if(NULL_PTR == versioninfo)
    {
#if (STD_ON == ADC_DEV_ERROR_DETECT)
        /** Specification of ADC Driver : [SWS_Adc_00458] **/
        Adc_ReportError(ADC_GETVERSIONINFO_ID, (uint8)ADC_E_PARAM_POINTER);
#endif
    }
    else
    {
        versioninfo->vendorID         = (uint16)ADC_VENDOR_ID;
        versioninfo->moduleID         = (uint16)ADC_MODULE_ID;
        versioninfo->sw_major_version = (uint8)ADC_SW_MAJOR_VER;
        versioninfo->sw_minor_version = (uint8)ADC_SW_MINOR_VER;
        versioninfo->sw_patch_version = (uint8)ADC_SW_PATCH_VER;
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_VERSION_INFO_API */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : Enters the already prepared power state.               **
**                                                                            **
**  Service ID       : 0x10                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : NonReentrant                                           **
**                                                                            **
**  Parameters (in)  : None                                                   **
**                                                                            **
**  Parameters (out) : Result :Pointer to a variable to store the result of   **
**                     this function.                                         **
**                                                                            **
**  Return value     : Std_ReturnType                                         **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, ADC_CODE) Adc_SetPowerState \
( \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_RetSetPowerState = (Std_ReturnType)E_NOT_OK;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    VAR(Std_ReturnType, ADC_VAR) u8Adc_RetSetPowerStateVerify = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
   

    u8Adc_RetSetPowerStateVerify = Adc_SetPowerStateVerify(Result);
    if(u8Adc_RetSetPowerStateVerify == (Std_ReturnType)E_OK)
    {
        if(eAdc_TargetState[u32Adc_ICoreId] >= ADC_NODEFINE_POWER)/* polyspace RTE:OBAI */
        {
            Adc_ReportError(ADC_SETPOWERSTATE_ID, (uint8)ADC_E_POWER_STATE_NOT_SUPPORTED);
            *Result = ADC_POWER_STATE_NOT_SUPP;
            u8Adc_RetSetPowerState = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            u8Adc_RetSetPowerState = (Std_ReturnType)E_OK;
        }
        if(u8Adc_RetSetPowerState == (Std_ReturnType)E_OK)
        {
#endif
            u8Adc_RetSetPowerState = Adc_AutoSar_Wrapper_SetPowerState(Result);
#if (STD_ON == ADC_DEV_ERROR_DETECT)
        }       
    }
#endif
    return u8Adc_RetSetPowerState;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : This API returns the current power state of the ADC    **
**                     HW unit.                                               **
**                                                                            **
**  Service ID       : 0x11                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : NonReentrant                                           **
**                                                                            **
**  Parameters (in)  : None                                                   **
**                                                                            **
**  Parameters (out) : CurrentPowerState: The current power mode of the ADC   **
**                     HW Unit is returned in this parameter.                 **
**                     Result: Pointer to a variable to store the result of   **
**                     this function.                                         **
**                                                                            **
**  Return value     : Std_ReturnType                                         **
**                                                                            **
*******************************************************************************/
FUNC(Std_ReturnType, ADC_CODE) Adc_GetCurrentPowerState \
( \
    P2VAR(Adc_PowerStateType, AUTOMATIC, ADC_APPL_DATA) CurrentPowerState, \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_RetGetCurrentPowerState = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_GetCurrentPowerStateVerify() == (Std_ReturnType)E_OK)
    {
#endif
        *CurrentPowerState = eAdc_CurrentState[u32Adc_ICoreId];/* polyspace RTE:OBAI */
        *Result = ADC_SERVICE_ACCEPTED;
        u8Adc_RetGetCurrentPowerState = (Std_ReturnType)E_OK;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
    return u8Adc_RetGetCurrentPowerState;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : This API returns the Target power state of the ADC     **
**                     HW unit.                                               **
**                                                                            **
**  Service ID       : 0x12                                                   **
**                                                                            **
**  Sync/Async       : NonReentrant                                           **
**                                                                            **
**  Reentrancy       : Reentrant                                              **
**                                                                            **
**  Parameters (in)  : None                                                   **
**                                                                            **
**  Parameters (out) : TargetPowerState: The Target power mode of the ADC HW  **
**                     Unit is returned in this parameter.                    **
**                     Result: Pointer to a variable to store the result of   **
**                     this function.                                         **
**                                                                            **
**  Return value     : Std_ReturnType                                         **
**                                                                            **
*******************************************************************************/ 
FUNC(Std_ReturnType, ADC_CODE) Adc_GetTargetPowerState \
( \
    P2VAR(Adc_PowerStateType, AUTOMATIC, ADC_APPL_DATA) TargetPowerState, \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_RetGetTargetPowerState = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_GetTargetPowerStateVerify() == (Std_ReturnType)E_OK)
    {
#endif
        /** Specification of ADC Driver : [SWS_Adc_00492] **/
        *TargetPowerState = eAdc_TargetState[u32Adc_ICoreId];/* polyspace RTE:OBAI */
        *Result = ADC_SERVICE_ACCEPTED;
        u8Adc_RetGetTargetPowerState = (Std_ReturnType)E_OK;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
    return u8Adc_RetGetTargetPowerState;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
/*******************************************************************************
**  Description      : This API starts the needed process to allow the ADC HW **
**                     module to enter the requested power state.             **
**                                                                            **
**  Service ID       : 0x13                                                   **
**                                                                            **
**  Sync/Async       : Synchronous                                            **
**                                                                            **
**  Reentrancy       : NonReentrant                                           **
**                                                                            **
**  Parameters (in)  : PowerState: The target power state intended to be      **
**                     attained.                                              **
**                                                                            **
**  Parameters (out) : Result: Pointer to a variable to store the result of   **
**                     this function.                                         **
**                                                                            **
**  Return value     : Std_ReturnType                                         **
**                                                                            **
*******************************************************************************/ 
FUNC(Std_ReturnType, ADC_CODE) Adc_PreparePowerState \
( \
    VAR(Adc_PowerStateType, AUTOMATIC) PowerState, \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) Result \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_RetPreparePowerState = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID(); /* GetCoreID */
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_PreparePowerStateVerify(PowerState) == (Std_ReturnType)E_OK)
    {
#endif
        /** Specification of ADC Driver : [SWS_Adc_00495] **/
        eAdc_TargetState[u32Adc_ICoreId] = PowerState;/* polyspace RTE:OBAI */
        *Result = ADC_SERVICE_ACCEPTED;
        u8Adc_RetPreparePowerState = (Std_ReturnType)E_OK;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
    return u8Adc_RetPreparePowerState;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_MainFunction(void)
{
    VAR(Adc_GroupType, ADC_VAR) u16Adc_GroupId;
    VAR(uint32, ADC_VAR) u32Adc_ICoreId = GetCoreID();
    VAR(EqadcInstanceType, ADC_VAR) eAdc_instance;
    VAR(EqadcFifoIdxType, ADC_VAR) eAdc_Rfifo_x = EQADC_FIFO_0;
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId = 0U;
    VAR(uint8, ADC_VAR) u8Adc_Flag = 0U;
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    if(Adc_MainFunctionVerify() == (Std_ReturnType)E_OK)
    {
#endif
        for (u16Adc_GroupId = 0U; u16Adc_GroupId < ADC_CONFIG_GROUPS; u16Adc_GroupId++)
        {
            if( Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].IntDma_Sel == EQADC_FILL_NOT_INT)/* polyspace RTE:NIV,IDP,OBAI */
            {
                u16Adc_HwUnitId = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].HwUnitId;/* polyspace RTE:NIV */
                #ifdef RESOURCE_SUPPORT_EQADC_INST0
                if(u16Adc_HwUnitId < (Adc_HwUnitType)2U)
                {
                    eAdc_instance = EQADC_INSTANCE_0;
                }
                #else
                if(FALSE) {} /* PRQA S 2742 */
                #endif  /* RESOURCE_SUPPORT_EQADC_INST0 */
                #ifdef RESOURCE_SUPPORT_EQADC_INST1
                else if(u16Adc_HwUnitId < (Adc_HwUnitType)4U)
                {
                    eAdc_instance = EQADC_INSTANCE_1;
                }
                #endif  /* RESOURCE_SUPPORT_EQADC_INST1 */
                #ifdef RESOURCE_SUPPORT_EQADC_INST2
                else if(u16Adc_HwUnitId < (Adc_HwUnitType)6U)
                {
                    eAdc_instance = EQADC_INSTANCE_2;
                }
                #endif  /* RESOURCE_SUPPORT_EQADC_INST2 */
                #ifdef RESOURCE_SUPPORT_EQADC_INST3
                else if(u16Adc_HwUnitId < (Adc_HwUnitType)8U)
                {
                    eAdc_instance = EQADC_INSTANCE_3;
                }
                #endif  /* RESOURCE_SUPPORT_EQADC_INST3 */
                #ifdef RESOURCE_SUPPORT_EQADC_INST4
                else if(u16Adc_HwUnitId < (Adc_HwUnitType)10U)
                {
                    eAdc_instance = EQADC_INSTANCE_4;
                }
                #endif  /* RESOURCE_SUPPORT_EQADC_INST4 */
                #ifdef RESOURCE_SUPPORT_EQADC_INST5
                else if(u16Adc_HwUnitId < (Adc_HwUnitType)12U)
                {
                    eAdc_instance = EQADC_INSTANCE_5;
                }
                #endif  /* RESOURCE_SUPPORT_EQADC_INST5 */
                #ifdef RESOURCE_SUPPORT_EQADC_INST6
                else if(u16Adc_HwUnitId < (Adc_HwUnitType)13U)
                {
                    eAdc_instance = EQADC_INSTANCE_6;
                }
                #endif  /* RESOURCE_SUPPORT_EQADC_INST6 */
                else
                {
                    u8Adc_Flag = 1U;
                }
                if(u8Adc_Flag == 0U)
                {
                    eAdc_Rfifo_x = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId].Eqadc_ConvCmd[0].RfifoMsgTag;/* polyspace RTE:NIV,NIP,IDP */
                    Adc_GetResultIrq(eAdc_instance, eAdc_Rfifo_x, u16Adc_GroupId);
                }
            }
        }
#if (STD_ON == ADC_DEV_ERROR_DETECT)
    }
#endif
    return;
}

#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif
