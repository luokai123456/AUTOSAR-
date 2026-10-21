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
*   @file    Adc_AutoSar_Wrapper.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Adc MCAL driver.
*
*   @addtogroup Adc
*   @{
*/

/* PRQA S 0380, 1006, 3432, 4491, 4499 EOF */
/* PRQA S 2844, 0491, 2934, 0488, 0492, 2053, 2877 EOF */    /* QAC_CWE */

#ifdef __cplusplus
extern "C"{
#endif

#include "Adc_AutoSar_Wrapper.h"
#include "Adc_HAL_Wrapper.h"
#include "Det.h"
#include "SchM_Adc.h"

#define ADC_ATS_WRA_C_VENDOR_ID                     176
#define ADC_ATS_WRA_C_AR_REL_MAJOR_VER              4
#define ADC_ATS_WRA_C_AR_REL_MINOR_VER              4
#define ADC_ATS_WRA_C_AR_REL_REV_VER                0
#define ADC_ATS_WRA_C_SW_MAJOR_VER                  3
#define ADC_ATS_WRA_C_SW_MINOR_VER                  0
#define ADC_ATS_WRA_C_SW_PATCH_VER                  0

#if (ADC_VENDOR_ID               != ADC_ATS_WRA_C_VENDOR_ID)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_C_VENDOR_ID "
#endif
#if (ADC_AR_REL_MAJOR_VER    != ADC_ATS_WRA_C_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_C_AR_REL_MAJOR_VER "
#endif
#if (ADC_AR_REL_MINOR_VER    != ADC_ATS_WRA_C_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_C_AR_REL_MINOR_VER "
#endif
#if (ADC_AR_REL_REV_VER != ADC_ATS_WRA_C_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_C_AR_REL_REV_VER "
#endif
#if (ADC_SW_MAJOR_VER        != ADC_ATS_WRA_C_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_C_SW_MAJOR_VER "
#endif
#if (ADC_SW_MINOR_VER        != ADC_ATS_WRA_C_SW_MINOR_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_C_SW_MINOR_VER "
#endif
#if (ADC_SW_PATCH_VER        != ADC_ATS_WRA_C_SW_PATCH_VER)
    #error " NON-MATCHED DATA : ADC_ATS_WRA_C_SW_PATCH_VER "
#endif

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(boolean, ADC_CODE) Adc_ImplicStop \
( \
    P2CONST(Adc_GroupConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_GroupConfig \
) 
{
    VAR(boolean, ADC_VAR) bAdc_retVal = FALSE;
    if(pAdc_GroupConfig->SwOrHw == ADC_TRIGG_SRC_SW)/* polyspace RTE:NIV,IDP */
    {
        if(((pAdc_GroupConfig->ConvMode == ADC_CONV_MODE_ONESHOT) /* polyspace RTE:NIV */
            && (pAdc_GroupConfig->AccessMode == ADC_ACCESS_MODE_SINGLE)) /* polyspace RTE:NIV */
            || ((pAdc_GroupConfig->ConvMode == ADC_CONV_MODE_CONTINUOUS) /* polyspace RTE:NIV */
            && (pAdc_GroupConfig->AccessMode == ADC_ACCESS_MODE_STREAMING) /* polyspace RTE:NIV */
            && (pAdc_GroupConfig->StreamBufMode == ADC_STREAM_BUFFER_LINEAR)))/* polyspace RTE:NIV */
        {
            bAdc_retVal = TRUE;
        }
    }
    else
    {
        if((pAdc_GroupConfig->ConvMode == ADC_CONV_MODE_ONESHOT) /* polyspace RTE:NIV */
            && (pAdc_GroupConfig->AccessMode == ADC_ACCESS_MODE_STREAMING) /* polyspace RTE:NIV */
            && (pAdc_GroupConfig->StreamBufMode == ADC_STREAM_BUFFER_LINEAR))/* polyspace RTE:NIV */
        {
            bAdc_retVal = TRUE;
        }
    }
    return bAdc_retVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_HW_TRIGGER_API)
#ifdef RESOURCE_SUPPORT_EQADC_SIUL2_TRIG_SRC_LIMIT
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_HWTrigRegLimit \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_GroupId \
) 
{
    VAR(uint16, ADC_VAR) u16Adc_Index = 0U;
    VAR(Std_ReturnType, ADC_VAR) u8Adc_retVal = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    P2CONST(Adc_GroupConfigType, ADC_VAR, ADC_APPL_CONST) Adc_GroupConfig = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig;/* polyspace RTE:IDP,OBAI */
    VAR(boolean, ADC_VAR) FifoCheck = FALSE;

    for(u16Adc_Index = 0U; u16Adc_Index < ADC_CONFIG_GROUPS; u16Adc_Index++)
    {
        if( (Adc_GroupConfig[u16Adc_Index].HwUnitId < 4U)/* polyspace RTE:NIV,IDP */
            && (Adc_GroupConfig[u16Adc_GroupId].HwUnitId < 4U) )/* polyspace RTE:NIV */
        {
            FifoCheck = TRUE;
        }
        else if( (Adc_GroupConfig[u16Adc_Index].HwUnitId < 10U) && (Adc_GroupConfig[u16Adc_Index].HwUnitId > 3U)
            && (Adc_GroupConfig[u16Adc_GroupId].HwUnitId < 10U) && (Adc_GroupConfig[u16Adc_GroupId].HwUnitId > 3U) )/* polyspace RTE:NIV */
        {
            FifoCheck = TRUE;
        }
        else
        {
            FifoCheck = FALSE;
        }

        if(FifoCheck == TRUE)
        {
            if(Adc_GroupConfig[u16Adc_Index].CFifo == Adc_GroupConfig[u16Adc_GroupId].CFifo)/* polyspace RTE:NIV */
            {
                if(Adc_GroupConfig[u16Adc_Index].HwTrigSrc != Adc_GroupConfig[u16Adc_GroupId].HwTrigSrc)/* polyspace RTE:NIV */
                {
                    #if (STD_ON == ADC_DEV_ERROR_DETECT)
                    (void)Det_ReportError((uint16)ADC_MODULE_ID, (uint8)0U, ADC_ENABLEHARDWARETRIGGER_ID, (uint8)ADC_E_TRIG_CONFLICT);
                    #endif
                    u8Adc_retVal = (Std_ReturnType)E_NOT_OK;
                }
            }
        }
    }
    return u8Adc_retVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* RESOURCE_SUPPORT_EQADC_SIUL2_TRIG_SRC_LIMIT */
#endif  /* STD_ON == ADC_HW_TRIGGER_API */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) Adc_InitHwUnit(void) 
{
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
#if ( STD_OFF == ADC_ENABLE_QUEUING )

#elif ((PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
    VAR(uint16, ADC_VAR) u16Adc_QueueElementIndex = 0U;
#elif ((PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
    VAR(uint16, ADC_VAR) u16Adc_QueueElementIndex = 0U;
#endif

    for (u16Adc_HwUnitId = 0U; u16Adc_HwUnitId < ADC_MAX_HW_UNITS; u16Adc_HwUnitId++)
    {
        sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_STStatus = HWUNIT_ST_IDLE;/* polyspace RTE:OBAI */
        sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HTStatus = HWUNIT_HT_OFF;
        sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HwTriEnableCount = (uint8)0U;
#if (STD_OFF == ADC_ENABLE_QUEUING)
        sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupId = (Adc_GroupType)ADC_CONFIG_GROUPS;
#elif ((PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
        for(u16Adc_QueueElementIndex = 0U; u16Adc_QueueElementIndex < ADC_QUEUE_MAX_DEPTH; u16Adc_QueueElementIndex++)
        {
            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupQueueId[u16Adc_QueueElementIndex] \
                    = (Adc_GroupType)ADC_CONFIG_GROUPS;
        }
#elif ((PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
        sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupPrio = 0U;
        for(u16Adc_QueueElementIndex = 0U; u16Adc_QueueElementIndex < ADC_QUEUE_MAX_DEPTH; u16Adc_QueueElementIndex++)
        {
            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupQueueId[u16Adc_QueueElementIndex] \
                    = (Adc_GroupType)ADC_CONFIG_GROUPS;
        }
        sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_QueueNumEmpSlot = 0U;
#endif
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(void, ADC_CODE) Adc_InitGroup(void) 
{
    VAR(Adc_GroupType, ADC_VAR) u16Adc_GroupId;
    VAR(boolean, ADC_VAR) bAdc_ImplicStop = FALSE;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
#if (ADC_ENABLE_MULTICORE == STD_ON)
    VAR(uint32, AUTOMATIC) CurrentCoreId = Adc_GetCoreID();/* polyspace RTE:SHF */
    VAR(uint8, AUTOMATIC) u8Adc_Coreflag = 0U;
#endif

    for (u16Adc_GroupId = 0U; u16Adc_GroupId < ADC_CONFIG_GROUPS; u16Adc_GroupId++)
    {
#if (ADC_ENABLE_MULTICORE == STD_ON)
        u8Adc_Coreflag = (uint8)((CurrentCoreId) & (Adc_ConfigPtr[u32Adc_ICoreId]->Adc_CoreMapItem[u16Adc_GroupId].GroupCoreId));/* polyspace RTE:OBAI,NIV,IDP*/
        if(u8Adc_Coreflag != 0U)
        {
#endif
            bAdc_ImplicStop = Adc_ImplicStop(&Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupId]);/* polyspace RTE:OBAI,IDP */
            /** Specification of ADC Driver : [SWS_Adc_00307] **/
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupStatus = ADC_IDLE;
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupResultBufferPtr = NULL_PTR;
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupResultIndex = (Adc_StreamNumSampleType)0U;
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupImplicStop = bAdc_ImplicStop;
#if (STD_ON == ADC_HW_TRIGGER_API)
            /** Specification of ADC Driver : [SWS_Adc_00077] **/
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupSwitchHwTrig = ADC_GROUP_HWTRIGGER_DISABLED;
#endif
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
            /** Specification of ADC Driver : [SWS_Adc_00077] **/
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupSwitchNotifCall = ADC_GROUP_NOTIFICATION_DISABLED;
#endif
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].StreamNumSamp = 0U;
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].ChannelCount = 0U;
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].CfifoFlag = 0U;
            u8Adc_MainFunctionFlag[u16Adc_GroupId][u32Adc_ICoreId] = 0U;
#if (ADC_ENABLE_MULTICORE == STD_ON)
        }
#endif
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_ENABLE_LIMIT_CHECK)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
ADC_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_CheckResult \
( \
    VAR(uint32, AUTOMATIC) u32Adc_Value, \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group, \
    VAR(uint8, AUTOMATIC) u8Adc_ChannelIndex \
)
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_retVal = (Std_ReturnType)E_NOT_OK;
    VAR(Adc_ChannelRangeSelectType, ADC_VAR) eAdc_RangeSelect;
    VAR(uint32, ADC_VAR) u32Adc_HighLimit;
    VAR(uint32, ADC_VAR) u32Adc_LowLimit;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    eAdc_RangeSelect = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group]. \
        Eqadc_ChannelLimit[u8Adc_ChannelIndex].RangeSelect;
    u32Adc_HighLimit = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group]. \
        Eqadc_ChannelLimit[u8Adc_ChannelIndex].HighLimit;
    u32Adc_LowLimit = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group]. \
        Eqadc_ChannelLimit[u8Adc_ChannelIndex].LowLimit;

    switch(eAdc_RangeSelect)
    {
        case ADC_RANGE_UNDER_LOW:
        {
            if(u32Adc_Value <= u32Adc_LowLimit)
            {
                u8Adc_retVal = (Std_ReturnType)E_OK;
            }
            break;
        }
        case ADC_RANGE_BETWEEN:
        {
            if((u32Adc_Value > u32Adc_LowLimit) && (u32Adc_Value <= u32Adc_HighLimit))
            {
                u8Adc_retVal = (Std_ReturnType)E_OK;
            }
            break;
        }
        case ADC_RANGE_OVER_HIGH:
        {
            if(u32Adc_Value > u32Adc_HighLimit)
            {
                u8Adc_retVal = (Std_ReturnType)E_OK;
            }
            break;
        }
        case ADC_RANGE_ALWAYS:
        {
            u8Adc_retVal = (Std_ReturnType)E_OK;
            break;
        }
        case ADC_RANGE_NOT_UNDER_LOW:
        {
            if(u32Adc_Value > u32Adc_LowLimit)
            {
                u8Adc_retVal = (Std_ReturnType)E_OK;
            }
            break;
        }
        case ADC_RANGE_NOT_BETWEEN:
        {
            if((u32Adc_Value > u32Adc_HighLimit) || (u32Adc_Value <= u32Adc_LowLimit))
            {
                u8Adc_retVal = (Std_ReturnType)E_OK;
            }
            break;
        }
        case ADC_RANGE_NOT_OVER_HIGH:
        {
            if(u32Adc_Value <= u32Adc_HighLimit)
            {
                u8Adc_retVal = (Std_ReturnType)E_OK;
            }
            break;
        }
        default:
        {
            break;
        }
    }
    return u8Adc_retVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif  /* STD_ON == ADC_ENABLE_LIMIT_CHECK */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_Init \
( \
    P2CONST(Adc_ConfigType, ADC_CONST, ADC_APPL_CONST) pAdc_ConfigPtr \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_retVal = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
#if (ADC_ENABLE_MULTICORE == STD_ON)
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwIndex = 0U;
    VAR(Adc_GroupType, ADC_VAR) u16Adc_GroupIndex = 0U;

    if(Adc_HwInitStateFlag == 0U)
    {
        for(u16Adc_GroupIndex = 0U; u16Adc_GroupIndex < ADC_CONFIG_GROUPS; u16Adc_GroupIndex++)
        {
            u16Adc_HwIndex = pAdc_ConfigPtr->Adc_GroupConfig[u16Adc_GroupIndex].HwUnitId;/* polyspace RTE:NIV,IDP */
            if(sAdc_AdcHwInitState[u16Adc_HwIndex] != ADC_HW_STATUS_UNINIT)/* polyspace RTE:OBAI */
            {
                sAdc_AdcHwInitState[u16Adc_HwIndex] = ADC_HW_STATUS_UNINIT;
            }
        }
        Adc_HwInitStateFlag = 1U;
    }
#endif
    u8Adc_retVal = Adc_Wrapper_Init(pAdc_ConfigPtr);
    if(u8Adc_retVal == (Std_ReturnType)E_OK)
    {
        Adc_InitHwUnit();
        Adc_InitGroup();
        SchM_Enter_Adc_EXCLUSIVE_AREA_06();
        Adc_GlobalStatus[u32Adc_ICoreId] = ADC_GS_INITED;/* polyspace RTE:OBAI */
        SchM_Exit_Adc_EXCLUSIVE_AREA_06();
    }
    else
    {
        SchM_Enter_Adc_EXCLUSIVE_AREA_07();
        Adc_GlobalStatus[u32Adc_ICoreId] = ADC_GS_UNINIT;/* polyspace RTE:OBAI */
        SchM_Exit_Adc_EXCLUSIVE_AREA_07();
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (STD_ON == ADC_DEINIT_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_AutoSar_Wrapper_DeInit(void) 
{
    VAR(Adc_GroupType, ADC_VAR) u16Adc_GroupId;
    VAR(Std_ReturnType, ADC_VAR) u8Adc_retVal = (Std_ReturnType)E_NOT_OK;
    VAR(boolean, ADC_VAR) bAdc_flag = TRUE;
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
#if ( STD_OFF == ADC_ENABLE_QUEUING )

#elif ((PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
    VAR(uint16, ADC_VAR) u16Adc_QueueElementIndex = 0U;
#elif ((PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
    VAR(uint16, ADC_VAR) u16Adc_QueueElementIndex = 0U;
#endif
    for (u16Adc_GroupId = 0; u16Adc_GroupId < ADC_CONFIG_GROUPS; u16Adc_GroupId++)
    {
        if(sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupStatus != ADC_IDLE) /* polyspace RTE:OBAI */
        {
            bAdc_flag = FALSE;
            break;
        }
    }
    if (bAdc_flag == TRUE)
    {
        u8Adc_retVal = Adc_Wrapper_DeInit();
        if(u8Adc_retVal == (Std_ReturnType)E_OK)
        {
            for (u16Adc_GroupId = 0U; u16Adc_GroupId < ADC_CONFIG_GROUPS; u16Adc_GroupId++) /* PRQA S 2877 */
            {
                u8Adc_MainFunctionFlag[u16Adc_GroupId][u32Adc_ICoreId] = 0U;
                sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupStatus = ADC_IDLE; 
                sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupResultBufferPtr = NULL_PTR;
                sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupResultIndex = (Adc_StreamNumSampleType)0U;
#if (STD_ON == ADC_HW_TRIGGER_API)
                /** Specification of ADC Driver : [SWS_Adc_00111] **/
                sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupSwitchHwTrig = ADC_GROUP_HWTRIGGER_DISABLED;
#endif
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
                /** Specification of ADC Driver : [SWS_Adc_00111] **/
                sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupSwitchNotifCall = ADC_GROUP_NOTIFICATION_DISABLED;
#endif
#if (ADC_ENABLE_MULTICORE == STD_ON)
                sAdc_GroupState[u16Adc_GroupId] = ADC_GROUP_STATUS_UNINIT;
#endif
            }
            for(u16Adc_HwUnitId = 0U; u16Adc_HwUnitId < ADC_MAX_HW_UNITS; u16Adc_HwUnitId++)
            {
                sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_STStatus = HWUNIT_ST_IDLE;
                sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HTStatus = HWUNIT_HT_OFF;
                sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HwTriEnableCount = (uint8)0U;
#if (STD_OFF == ADC_ENABLE_QUEUING)
                sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupId = (Adc_GroupType)ADC_CONFIG_GROUPS;
#elif ((PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
                for(u16Adc_QueueElementIndex = 0U; u16Adc_QueueElementIndex < ADC_QUEUE_MAX_DEPTH; u16Adc_QueueElementIndex++)
                {
                    sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupQueueId[u16Adc_QueueElementIndex] \
                            = (Adc_GroupType)ADC_CONFIG_GROUPS;
                }
#elif ((PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
                sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupPrio = 0U;
                for(u16Adc_QueueElementIndex = 0U; u16Adc_QueueElementIndex < ADC_QUEUE_MAX_DEPTH; u16Adc_QueueElementIndex++)
                {
                    sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupQueueId[u16Adc_QueueElementIndex] \
                            = (Adc_GroupType)ADC_CONFIG_GROUPS;
                }
                sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_QueueNumEmpSlot = 0U;
#endif
#if (ADC_ENABLE_MULTICORE == STD_ON)
                sAdc_AdcHwInitState[u16Adc_HwUnitId] = ADC_HW_NOT_USE;
                Adc_HwInitStateFlag = 0U;
#endif
            }
            SchM_Enter_Adc_EXCLUSIVE_AREA_08();
            Adc_GlobalStatus[u32Adc_ICoreId] = ADC_GS_UNINIT;
            SchM_Exit_Adc_EXCLUSIVE_AREA_08();
        }
        else
        {
            SchM_Enter_Adc_EXCLUSIVE_AREA_09();
            Adc_GlobalStatus[u32Adc_ICoreId] = ADC_GS_INITED;
            SchM_Exit_Adc_EXCLUSIVE_AREA_09();
        }
    }
    else
    {
        /** Specification of ADC Driver : [SWS_Adc_00112] **/
        (void)Det_ReportRuntimeError((uint16)ADC_MODULE_ID, (uint8)0U, ADC_DEINIT_ID, (uint8)ADC_E_BUSY);
    }
    return u8Adc_retVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_DEINIT_API */

#if (STD_ON == ADC_ENABLE_START_STOP_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_StartGroupConversion \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
)
{
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    P2CONST(Adc_GroupConfigType, ADC_VAR, ADC_APPL_DATA) Adc_GroupCfgPtr = &Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group];/* polyspace RTE:IDP,OBAI */
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId = Adc_GroupCfgPtr->HwUnitId;/* polyspace RTE:NIV,IDP */
    P2VAR(Adc_RunningHwUnitType, ADC_VAR, ADC_APPL_DATA) Adc_RunningHwUnitPtr = &sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId];
    P2VAR(Adc_RunningGroupType, ADC_VAR, ADC_APPL_DATA) Adc_RunningGroupPtr = &sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group];

#if (PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING)
    VAR(Adc_GroupType, ADC_VAR) u16Adc_OldGroupId = 0U;
    VAR(uint16, ADC_VAR) u16Adc_IndexQueue = 0U;
    VAR(uint16, ADC_VAR) u16Adc_IndexShift = 0U;
#endif
    /** Specification of ADC Driver : [SWS_Adc_00146] **/
    if(Adc_GroupCfgPtr->SwOrHw == ADC_TRIGG_SRC_SW)/* polyspace RTE:NIV */
    {
#if (STD_OFF == ADC_ENABLE_QUEUING)
        if((Adc_RunningGroupPtr->GroupStatus != ADC_IDLE) && (Adc_RunningGroupPtr->GroupImplicStop == FALSE))/* polyspace RTE:IDP */
        {
            /** Specification of ADC Driver : [SWS_Adc_00346] **/
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)ADC_MODULE_ID, \
                (uint8)0U, \
                ADC_STARTGROUPCONVERSION_ID, \
                (uint8)ADC_E_BUSY \
            );
        }
        else if((Adc_RunningGroupPtr->GroupStatus != ADC_IDLE) \
            && (Adc_RunningGroupPtr->GroupStatus != ADC_STREAM_COMPLETED)
            && (Adc_RunningGroupPtr->GroupImplicStop == TRUE))
        {
            /** Specification of ADC Driver : [SWS_Adc_00426] **/
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)ADC_MODULE_ID, \
                (uint8)0U, \
                ADC_STARTGROUPCONVERSION_ID, \
                (uint8)ADC_E_BUSY \
            );
        }
        else
        {
            SchM_Enter_Adc_EXCLUSIVE_AREA_00();
            Adc_RunningHwUnitPtr->HwUnit_RunGroupId = u16Adc_Group;/* polyspace RTE:IDP */
            Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_BUSY_LAST;
            Adc_RunningGroupPtr->GroupStatus = ADC_BUSY;
            Adc_RunningGroupPtr->GroupResultIndex = 0U;
            (void)Adc_Wrapper_StartGroupConversion(u16Adc_Group);
            SchM_Exit_Adc_EXCLUSIVE_AREA_00();
        }
/* (PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION) && (STD_OFF == ADC_ENABLE_QUEUING) */
#elif ((PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
        if((Adc_RunningGroupPtr->GroupImplicStop == FALSE) && (Adc_RunningGroupPtr->GroupStatus != ADC_IDLE))
        {
            /** Specification of ADC Driver : [SWS_Adc_00351] **/
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)ADC_MODULE_ID, \
                (uint8)0U, \
                ADC_STARTGROUPCONVERSION_ID, \
                (uint8)ADC_E_BUSY \
            );
        }
        else if((Adc_RunningGroupPtr->GroupImplicStop == TRUE) \
                && (Adc_RunningGroupPtr->GroupStatus != ADC_IDLE) \
                && (Adc_RunningGroupPtr->GroupStatus != ADC_STREAM_COMPLETED))
        {
            /** Specification of ADC Driver : [SWS_Adc_00428] **/
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)ADC_MODULE_ID, \
                (uint8)0U, \
                ADC_STARTGROUPCONVERSION_ID, \
                (uint8)ADC_E_BUSY \
            );
        }
        else
        {

            if(Adc_RunningHwUnitPtr->HwUnit_STStatus == HWUNIT_ST_IDLE)
            {
                SchM_Enter_Adc_EXCLUSIVE_AREA_01();
                Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_BUSY_LAST;
                Adc_RunningGroupPtr->GroupStatus = ADC_BUSY;
                Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0] = u16Adc_Group;
                Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot = 1U;
                Adc_RunningGroupPtr->GroupResultIndex = 0U;
                (void)Adc_Wrapper_StartGroupConversion(u16Adc_Group);
                SchM_Exit_Adc_EXCLUSIVE_AREA_01();
            }
            else
            {
                Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_BUSY_QUEUING;
                Adc_RunningGroupPtr->GroupStatus = ADC_BUSY;
                Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot] = u16Adc_Group;
                Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot++;
                Adc_RunningGroupPtr->GroupResultIndex = 0U;
            }
        }
/* PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION && STD_ON == ADC_ENABLE_QUEUING */
#elif ((PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
        if(Adc_RunningHwUnitPtr->HwUnit_STStatus == HWUNIT_ST_IDLE)
        {
            SchM_Enter_Adc_EXCLUSIVE_AREA_02();
            Adc_RunningHwUnitPtr->HwUnit_RunGroupPrio = Adc_GroupCfgPtr->Prio;
            Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_BUSY_LAST;
            Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0] = u16Adc_Group;
            Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot = 1U;

            Adc_RunningGroupPtr->GroupStatus = ADC_BUSY;
            Adc_RunningGroupPtr->GroupResultIndex = 0U;
            (void)Adc_Wrapper_StartGroupConversion(u16Adc_Group);
            SchM_Exit_Adc_EXCLUSIVE_AREA_02();
        }
        else if( ((Adc_RunningGroupPtr->GroupStatus != ADC_IDLE) && (Adc_RunningGroupPtr->GroupImplicStop == FALSE)) \
                 || ((Adc_RunningGroupPtr->GroupStatus != ADC_IDLE) && (Adc_RunningGroupPtr->GroupImplicStop == TRUE) \
                      && (Adc_RunningGroupPtr->GroupStatus != ADC_STREAM_COMPLETED)) )
        {
            /** Specification of ADC Driver : [SWS_Adc_00348] **/
            /** Specification of ADC Driver : [SWS_Adc_00427] **/
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)ADC_MODULE_ID, \
                (uint8)0U, \
                ADC_STARTGROUPCONVERSION_ID, \
                (uint8)ADC_E_BUSY \
            );
        }
        else
        {
            SchM_Enter_Adc_EXCLUSIVE_AREA_03();
            Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_BUSY_QUEUING;
            Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot++;
            Adc_RunningGroupPtr->GroupStatus = ADC_BUSY;
            Adc_RunningGroupPtr->GroupResultIndex = 0U;

            if(Adc_GroupCfgPtr->Prio > Adc_RunningHwUnitPtr->HwUnit_RunGroupPrio)
            {
                u16Adc_OldGroupId = Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0U];
                Adc_RunningHwUnitPtr->HwUnit_RunGroupPrio = Adc_GroupCfgPtr->Prio;


                for(u16Adc_IndexQueue =  Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot; \
                    u16Adc_IndexQueue > (uint16)0U; u16Adc_IndexQueue--)
                {
                    Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_IndexQueue] \
                        = Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_IndexQueue - 1U];
                }
                Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0U] = u16Adc_Group;

                (void)Adc_Wrapper_StopGroupConversion(u16Adc_OldGroupId);
                (void)Adc_Wrapper_StartGroupConversion(u16Adc_Group);
            }
            else
            {
                for(u16Adc_IndexQueue = (uint16)1U; u16Adc_IndexQueue < (Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot - 1U); u16Adc_IndexQueue++)
                {
                    if(Adc_GroupCfgPtr->Prio > Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_IndexQueue]].Prio)
                    {
                        for(u16Adc_IndexShift = Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot; u16Adc_IndexShift > u16Adc_IndexQueue; u16Adc_IndexShift--)
                        {
                            Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_IndexShift] \
                                = Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_IndexShift - 1U];
                        }
                        break;
                    }
                }
                Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_IndexQueue] = u16Adc_Group;
            }
            SchM_Exit_Adc_EXCLUSIVE_AREA_03();
        }
#endif /* PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION && STD_ON == ADC_ENABLE_QUEUING */
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_StopGroupConversion \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
) 
{
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    P2CONST(Adc_GroupConfigType, ADC_VAR, ADC_APPL_DATA) Adc_GroupCfgPtr = &Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group];/* polyspace RTE:NIV,IDP,OBAI */
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId = Adc_GroupCfgPtr->HwUnitId;/* polyspace RTE:NIV,IDP */
    P2VAR(Adc_RunningHwUnitType, ADC_VAR, ADC_APPL_DATA) Adc_RunningHwUnitPtr = &sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId];
    P2VAR(Adc_RunningGroupType, ADC_VAR, ADC_APPL_DATA) Adc_RunningGroupPtr = &sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group];

#if (STD_OFF == ADC_ENABLE_QUEUING)

#elif ((PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
    VAR(Adc_GroupType, ADC_VAR) u16Adc_NextGropId = (uint16)ADC_CONFIG_GROUPS;
    VAR(uint16, ADC_VAR) u16Adc_QueueIndex = (uint16)0U;
    VAR(uint16, ADC_VAR) u16Adc_IndexShift = (uint16)0U;
    VAR(boolean, ADC_VAR) bAdc_QuAutoStartFlag = (boolean)FALSE;
#elif ((PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION) && (STD_ON == ADC_ENABLE_QUEUING))
    VAR(Adc_GroupType,ADC_VAR) u16Adc_NextGropId = (uint16)ADC_CONFIG_GROUPS;
    VAR(uint16, ADC_VAR) u16Adc_QueueIndex = (uint16)0U;
    VAR(uint16, ADC_VAR) u16Adc_IndexShift = (uint16)0U;
    VAR(boolean, ADC_VAR) bAdc_QuAutoStartFlag = (boolean)FALSE;
#endif
    /** Specification of ADC Driver : [SWS_Adc_00283] **/
    if(Adc_GroupCfgPtr->SwOrHw == ADC_TRIGG_SRC_SW)/* polyspace RTE:NIV */
    {
        if(Adc_RunningGroupPtr->GroupStatus ==  ADC_IDLE)/* polyspace RTE:IDP */
        {
            /** Specification of ADC Driver : [SWS_Adc_00241] **/
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)ADC_MODULE_ID, \
                (uint8)0U, \
                ADC_STOPGROUPCONVERSION_ID, \
                (uint8)ADC_E_IDLE \
            );        
        }
        else
        {
#if (STD_OFF == ADC_ENABLE_QUEUING)
            if(Adc_RunningHwUnitPtr->HwUnit_RunGroupId == u16Adc_Group)/* polyspace RTE:IDP */
            {
                u8Adc_MainFunctionFlag[u16Adc_Group][u32Adc_ICoreId] = 0U;/* polyspace RTE:IDP,OBAI */
                /** Specification of ADC Driver : [SWS_Adc_00385] [SWS_Adc_00386] **/
                (void)Adc_Wrapper_StopGroupConversion(u16Adc_Group);
                Adc_RunningHwUnitPtr->HwUnit_RunGroupId \
                    = (uint16)ADC_CONFIG_GROUPS;
                Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_IDLE;
                Adc_RunningGroupPtr->GroupResultIndex = 0U;
                /** Specification of ADC Driver : [SWS_Adc_00360] **/
                Adc_RunningGroupPtr->GroupStatus = ADC_IDLE;
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
                /** Specification of ADC Driver : [SWS_Adc_00155] **/
                Adc_RunningGroupPtr->GroupSwitchNotifCall = ADC_GROUP_NOTIFICATION_DISABLED;
#endif

            }

/* PRIORITY_NONE == ADC_PRIORITY_IMPLEMENTATION && STD_OFF == ADC_ENABLE_QUEUING */

#elif (STD_ON == ADC_ENABLE_QUEUING)
            SchM_Enter_Adc_EXCLUSIVE_AREA_05();
            if(Adc_RunningHwUnitPtr->HwUnit_STStatus != HWUNIT_ST_IDLE)
            {
                if(Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0U] == u16Adc_Group)
                {
                    /** Specification of ADC Driver : [SWS_Adc_00385] [SWS_Adc_00386] **/
                    (void)Adc_Wrapper_StopGroupConversion(u16Adc_Group);
                    Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot--;
                    if(Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot != 0U)
                    {
                        u16Adc_NextGropId = Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[1U];
                        for(u16Adc_QueueIndex = 0U; u16Adc_QueueIndex < Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot; u16Adc_QueueIndex++)
                        {
                             Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_QueueIndex] = \
                                 Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_QueueIndex + 1U];
                        }
                        Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_QueueIndex] = ADC_CONFIG_GROUPS;
                        if(Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot == 1U)
                        {
                            Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_BUSY_LAST;
                        }

#if (PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION)
                        Adc_RunningHwUnitPtr->HwUnit_RunGroupPrio = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].Prio;
#endif
                        bAdc_QuAutoStartFlag = TRUE;
                    }
                    else
                    {
#if (PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION)
                        Adc_RunningHwUnitPtr->HwUnit_RunGroupPrio = 0U;
#endif
                        Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_IDLE;
                        Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0] = ADC_CONFIG_GROUPS;
                        Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot = 0U;
                    }
                }
                else
                {
                    for(u16Adc_QueueIndex = (uint8)1U; u16Adc_QueueIndex < Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot; u16Adc_QueueIndex++)
                    {
                        if(u16Adc_Group == Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_QueueIndex])
                        {
                            for(u16Adc_IndexShift = u16Adc_QueueIndex; u16Adc_IndexShift<(uint8)(Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot - 1U); u16Adc_IndexShift++)
                            {
                                Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_IndexShift] =
                                        Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_IndexShift + 1U];
                            }
                            if(Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot == 1U)
                            {
                                Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_BUSY_LAST;
                            }
                            Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot--;
                            break;
                        }
                    }
                }
                u8Adc_MainFunctionFlag[u16Adc_Group][u32Adc_ICoreId] = 0U;
                Adc_RunningGroupPtr->GroupResultIndex = 0U;
                /** Specification of ADC Driver : [SWS_Adc_00360] **/
                Adc_RunningGroupPtr->GroupStatus = ADC_IDLE;
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
                /** Specification of ADC Driver : [SWS_Adc_00155] **/
                Adc_RunningGroupPtr->GroupSwitchNotifCall \
                    = ADC_GROUP_NOTIFICATION_DISABLED;
#endif
                if(((boolean)TRUE == bAdc_QuAutoStartFlag) \
                    && (ADC_CONFIG_GROUPS > u16Adc_NextGropId))
                {
                    (void)Adc_Wrapper_StartGroupConversion(u16Adc_NextGropId);
                }
            }
            else
            {
                u8Adc_MainFunctionFlag[u16Adc_Group][u32Adc_ICoreId] = 0U;
                Adc_RunningGroupPtr->GroupResultIndex = 0U;
                /** Specification of ADC Driver : [SWS_Adc_00360] **/
                Adc_RunningGroupPtr->GroupStatus = ADC_IDLE;
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
                /** Specification of ADC Driver : [SWS_Adc_00155] **/
                Adc_RunningGroupPtr->GroupSwitchNotifCall \
                    = ADC_GROUP_NOTIFICATION_DISABLED;
#endif
                if(((boolean)TRUE == bAdc_QuAutoStartFlag) \
                    && (ADC_CONFIG_GROUPS > u16Adc_NextGropId))
                {
                    (void)Adc_Wrapper_StartGroupConversion(u16Adc_NextGropId);
                }
            }
            SchM_Exit_Adc_EXCLUSIVE_AREA_05();
#endif /* PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION && STD_ON == ADC_ENABLE_QUEUING */
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_ENABLE_START_STOP_GROUP_API */

#if(STD_ON == ADC_ENABLE_QUEUING)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_SchedulerMain(VAR(Adc_HwUnitType, AUTOMATIC) u16Adc_HwUnitId)
{
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    P2VAR(Adc_RunningHwUnitType, ADC_VAR, ADC_APPL_DATA)Adc_RunningHwUnitPtr = \
            &sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId];
    VAR(uint16, ADC_VAR) u16Adc_QueueIndex = (uint16)0U;
    VAR(boolean, ADC_VAR) bAdc_QuAutoStartFlag = (boolean)FALSE;
    (void)Adc_Wrapper_StopGroupConversion(Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0U]);
    Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot--;
    if(Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot != 0U)
    {
        for(u16Adc_QueueIndex = 0U; u16Adc_QueueIndex < Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot; u16Adc_QueueIndex++)
        {
             Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_QueueIndex] = \
                 Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_QueueIndex + 1U];
        }
        Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[u16Adc_QueueIndex] = ADC_CONFIG_GROUPS;
        if(Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot == 1U)
        {
            Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_BUSY_LAST;
        }

#if (PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION)
        Adc_RunningHwUnitPtr->HwUnit_RunGroupPrio = \
            Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0U]].Prio;
#endif
        bAdc_QuAutoStartFlag = TRUE;
    }
    else
    {
#if (PRIORITY_HW_SW == ADC_PRIORITY_IMPLEMENTATION)
        Adc_RunningHwUnitPtr->HwUnit_RunGroupPrio = 0U;
#endif
        Adc_RunningHwUnitPtr->HwUnit_STStatus = HWUNIT_ST_IDLE;
        Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0] = ADC_CONFIG_GROUPS;
        Adc_RunningHwUnitPtr->HwUnit_QueueNumEmpSlot = 0U;
    }

    if((boolean)TRUE == bAdc_QuAutoStartFlag)
    {
        (void)Adc_Wrapper_StartGroupConversion(Adc_RunningHwUnitPtr->HwUnit_RunGroupQueueId[0U]);
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_ENABLE_START_STOP_GROUP_API */

#if (STD_ON == ADC_READ_GROUP_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_AutoSar_Wrapper_ReadGroup \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group, \
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pAdc_DataBufferPtr \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_retVal = (Std_ReturnType)E_OK;
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId;
    VAR(boolean, ADC_VAR) bAdc_ImplicStop = FALSE;
    VAR(Adc_StreamNumSampleType, ADC_VAR) u16Adc_NumSamp = (Adc_StreamNumSampleType)0U;
    P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA) pAdc_ResultTemp = NULL_PTR;
    VAR(Adc_ChannelType, ADC_VAR) u8Adc_ChannelCount = (Adc_ChannelType)0U;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    VAR(uint8, ADC_VAR) u8Adc_Shift = 0U;
#if (STD_ON == ADC_ENABLE_LIMIT_CHECK)
    VAR(Std_ReturnType, ADC_VAR) u8Adc_Limitflag = (Std_ReturnType)E_OK;
#endif
    u16Adc_HwUnitId = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].HwUnitId;/* polyspace RTE:NIV,IDP,OBAI */
    if((sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus == ADC_IDLE)  /* polyspace RTE:IDP,OBAI */
        && (sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultIndex == (Adc_StreamNumSampleType)0U))
    {
        /** Specification of ADC Driver : [SWS_Adc_00388] **/
        (void)Det_ReportRuntimeError \
        ( \
            (uint16)ADC_MODULE_ID, \
            (uint8)0U, \
            ADC_READGROUP_ID, \
            (uint8)ADC_E_IDLE \
        );
    }
    else
    {
        bAdc_ImplicStop = sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupImplicStop;
        if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].AccessMode == ADC_ACCESS_MODE_STREAMING)/* polyspace RTE:NIV */
        {
            u16Adc_NumSamp = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].StreamNumSamp;/* polyspace RTE:NIV */
        }
        else
        {
            u16Adc_NumSamp = (Adc_StreamNumSampleType)1U;
        }
        if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].DmaSampleNum == 1U)/* polyspace RTE:NIV */
        {
            pAdc_ResultTemp = (Adc_ValueGroupType *) \
              (sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultBufferPtr + (u16Adc_NumSamp - 1U));
        }
        else
        {
            pAdc_ResultTemp = (Adc_ValueGroupType *) \
              (sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultBufferPtr \
                  + ((Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].DmaSampleNum - 1U) \
                      * Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].ChannelCount));/* polyspace RTE:NIV */
        }

        u8Adc_Shift = (uint8)(14U - (uint8)(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].Resolution));/* polyspace RTE:NIV */
        for(u8Adc_ChannelCount = 0U; u8Adc_ChannelCount < (Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].ChannelCount); u8Adc_ChannelCount++)/* polyspace RTE:NIV */
        {
#if (STD_ON == ADC_ENABLE_LIMIT_CHECK)
            if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group]. \
                Eqadc_ChannelLimit[u8Adc_ChannelCount].LimitCheck == TRUE)
            {
                /* SWS_Adc_00447*/
                u8Adc_Limitflag = Adc_CheckResult \
                                ( \
                                    (uint32)((*pAdc_ResultTemp)>>u8Adc_Shift), \
                                    u16Adc_Group, u8Adc_ChannelCount \
                                );
                if(u8Adc_Limitflag == (Std_ReturnType)E_OK)
                {
                    pAdc_DataBufferPtr[u8Adc_ChannelCount] = (Adc_ValueGroupType)((*pAdc_ResultTemp)>>u8Adc_Shift);
                }
                else
                {
                    pAdc_DataBufferPtr[u8Adc_ChannelCount] = 0;
                    u8Adc_retVal = (Std_ReturnType)E_NOT_OK;
                }
            }
            else
            {
#endif
                    if(u8Adc_Shift <= 16U)
                    {
#ifdef RESOURCE_SUPPORT_EQADC_CMD_OSR
                        if (EQADC_OVERSAMPLE_DISABLED == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].Eqadc_ConvCmd[u8Adc_ChannelCount].OverSampleRate)/* polyspace RTE:IDP,NIV,NIP */
                        {
                            pAdc_DataBufferPtr[u8Adc_ChannelCount] = (Adc_ValueGroupType)((*pAdc_ResultTemp) >> u8Adc_Shift);/* polyspace RTE:NIV,IDP */
                        }
                        else
                        {
                            pAdc_DataBufferPtr[u8Adc_ChannelCount] = (Adc_ValueGroupType)(*pAdc_ResultTemp);/* polyspace RTE:NIV,IDP */
                        }
#else
                        pAdc_DataBufferPtr[u8Adc_ChannelCount] = (Adc_ValueGroupType)((*pAdc_ResultTemp) >> u8Adc_Shift);/* polyspace RTE:NIV,IDP */
#endif  /* RESOURCE_SUPPORT_EQADC_CMD_OSR */
                    }
#if (STD_ON == ADC_ENABLE_LIMIT_CHECK)
            }
#endif
            pAdc_ResultTemp += u16Adc_NumSamp;
        }
#if (STD_ON == ADC_ENABLE_LIMIT_CHECK)
        if(u8Adc_Limitflag == (Std_ReturnType)E_OK)
        {
#endif
            if ((Adc_StatusType)ADC_STREAM_COMPLETED \
                == sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus)
            {
                if(bAdc_ImplicStop == FALSE)
                {
                    /** Specification of ADC Driver : [SWS_Adc_00329] **/
                    sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = ADC_BUSY;
                }
                else
                {
                    /** Specification of ADC Driver : [SWS_Adc_00330] **/
                    sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = ADC_IDLE;
                    if(u16Adc_HwUnitId < ADC_MAX_HW_UNITS)/* polyspace RTE:NIV */
                    {
                        if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].SwOrHw == ADC_TRIGG_SRC_HW)/* polyspace RTE:NIV */
                        {
                            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HTStatus = HWUNIT_HT_OFF;
                        }
                        else
                        {
                            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_STStatus = HWUNIT_ST_IDLE;
                        }
                    }
                    
                }
            }
            else if((Adc_StatusType)ADC_COMPLETED == sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus)
            {
                /** Specification of ADC Driver : [SWS_Adc_00331] **/
                sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = ADC_BUSY;
            }
            else
            {
                /* No action */
            }
#if (STD_ON == ADC_ENABLE_LIMIT_CHECK)
        }
        else
        {
            if(ADC_CONV_MODE_ONESHOT == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].ConvMode)
            {
                if(ADC_TRIGG_SRC_SW == Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].SwOrHw)
                {
                    /* SWS_Adc_00449 */
                    sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = ADC_BUSY;
                }
                else
                {
                    /* SWS_Adc_00450 */
                    sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = ADC_IDLE;
                }
            }
        }
#endif

    }
    return u8Adc_retVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif

#if (STD_ON == ADC_HW_TRIGGER_API)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_EnableHardwareTrigger \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
) 
{
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId;
    VAR(Adc_GroupType, ADC_VAR) u16Adc_GroupIndex;
    VAR(boolean, ADC_VAR) bAdc_Flag = TRUE;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    u16Adc_HwUnitId = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].HwUnitId;/* polyspace RTE:NIV,IDP,OBAI */
    /** Specification of ADC Driver : [SWS_Adc_00120] **/
    if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].SwOrHw == ADC_TRIGG_SRC_HW)/* polyspace RTE:NIV */
    {
#ifdef RESOURCE_SUPPORT_EQADC_SIUL2_TRIG_SRC_LIMIT
        if(Adc_HWTrigRegLimit(u16Adc_Group) == (Std_ReturnType)E_NOT_OK)
        {
            bAdc_Flag = FALSE;
        }
#endif  /* RESOURCE_SUPPORT_EQADC_SIUL2_TRIG_SRC_LIMIT */
        if((sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupSwitchHwTrig == (Adc_HwTriggSwitch)ADC_GROUP_HWTRIGGER_ENABLED)/* polyspace RTE:IDP,OBAI */
            && (sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus == ADC_BUSY))
        {
            /** Specification of ADC Driver : [SWS_Adc_00349] **/
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)ADC_MODULE_ID, \
                (uint8)0U, \
                ADC_ENABLEHARDWARETRIGGER_ID, \
                (uint8)ADC_E_BUSY \
            );
            bAdc_Flag = FALSE;
        }
        else if(sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_STStatus != HWUNIT_ST_IDLE)/* polyspace RTE:OBAI */
        {
            for(u16Adc_GroupIndex = 0U; u16Adc_GroupIndex < ADC_CONFIG_GROUPS; u16Adc_GroupIndex++)
            {
                if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupIndex].HwUnitId == u16Adc_HwUnitId)/* polyspace RTE:NIV */
                {
                    if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_GroupIndex].SwOrHw == ADC_TRIGG_SRC_SW)/* polyspace RTE:NIV */
                    {
                        if(sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupIndex].GroupStatus != ADC_IDLE)
                        {
                            /** Specification of ADC Driver : [SWS_Adc_00321] **/
                            (void)Det_ReportRuntimeError \
                            ( \
                                (uint16)ADC_MODULE_ID, \
                                (uint8)0U, \
                                ADC_ENABLEHARDWARETRIGGER_ID, \
                                (uint8)ADC_E_BUSY \
                            );
                            bAdc_Flag = FALSE;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            bAdc_Flag = TRUE;
        }
        if(bAdc_Flag == TRUE)
        {
            if(sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus == ADC_STREAM_COMPLETED)
            {
                sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HTStatus = HWUNIT_HT_OFF;
                sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HwTriEnableCount = 0U;
            }
            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HTStatus = HWUNIT_HT_ON;
            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HwTriEnableCount++;
#if (STD_OFF == ADC_ENABLE_QUEUING)
            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupId = u16Adc_Group;
#endif
            /** Specification of ADC Driver : [SWS_Adc_00432] **/
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultIndex = (Adc_StreamNumSampleType)0U;
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = ADC_BUSY;
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupSwitchHwTrig \
                = (Adc_HwTriggSwitch)ADC_GROUP_HWTRIGGER_ENABLED;
            (void)Adc_Wrapper_EnableHardwareTrigger(u16Adc_Group);
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(void, ADC_CODE) Adc_AutoSar_Wrapper_DisableHardwareTrigger \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group \
) 
{
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    u16Adc_HwUnitId = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].HwUnitId;/* polyspace RTE:NIV,IDP,OBAI */
    /** Specification of ADC Driver : [SWS_Adc_00121] **/
    if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].SwOrHw == ADC_TRIGG_SRC_HW)/* polyspace RTE:NIV */
    {
        if(sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupSwitchHwTrig  /* polyspace RTE:IDP,OBAI */
            == (Adc_HwTriggSwitch)ADC_GROUP_HWTRIGGER_DISABLED)
        {
            /** Specification of ADC Driver : [SWS_Adc_00304] **/
            (void)Det_ReportRuntimeError \
            ( \
                (uint16)ADC_MODULE_ID, \
                (uint8)0U, \
                ADC_DISABLEHARDWARETRIGGER_ID, \
                (uint8)ADC_E_IDLE \
            );
        }
        else
        {
            (void)Adc_Wrapper_DisableHardwareTrigger(u16Adc_Group);
            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HwTriEnableCount--;/* polyspace RTE:OBAI */
            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HTStatus = HWUNIT_HT_OFF;
#if (STD_OFF == ADC_ENABLE_QUEUING)
            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_RunGroupId = ADC_CONFIG_GROUPS;
#endif
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultIndex = (Adc_StreamNumSampleType)0U;
            /** Specification of ADC Driver : [SWS_Adc_00361] **/
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = ADC_IDLE;
            /** Specification of ADC Driver : [SWS_Adc_00116] **/
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupSwitchHwTrig \
                = (Adc_HwTriggSwitch)ADC_GROUP_HWTRIGGER_DISABLED;
#if (STD_ON == ADC_GRP_NOTIF_CAPABILITY)
            /** Specification of ADC Driver : [SWS_Adc_00157] **/
            sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupSwitchNotifCall \
                = ADC_GROUP_NOTIFICATION_DISABLED;
#endif
        }
    }
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* STD_ON == ADC_HW_TRIGGER_API */

#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Adc_StreamNumSampleType, ADC_CODE) Adc_AutoSar_Wrapper_GetStreamLastPointer \
( \
    VAR(Adc_GroupType, AUTOMATIC) u16Adc_Group, \
    P2P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pAdc_PtrToSamplePtr \
) 
{
    VAR(Adc_StreamNumSampleType, ADC_VAR) u16Adc_LastPoint = (Adc_StreamNumSampleType)0U;
    VAR(Adc_StreamNumSampleType, ADC_VAR) u16Adc_ResultNum = (Adc_StreamNumSampleType)0U;
    VAR(boolean, ADC_VAR) bAdc_ImplicStop = FALSE;
    VAR(Adc_HwUnitType, ADC_VAR) u16Adc_HwUnitId;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    u16Adc_HwUnitId = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].HwUnitId;/* polyspace RTE:NIV,IDP,OBAI */
    if((sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus == (Adc_StatusType)ADC_IDLE) /* polyspace RTE:IDP,OBAI */
        && (sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultIndex == 0U))
    {
        /** Specification of ADC Driver : [SWS_Adc_00215] **/
        (void)Det_ReportRuntimeError \
        ( \
            (uint16)ADC_MODULE_ID, \
            (uint8)0U, \
            ADC_GETSTREAMLASTPOINTER_ID, \
            (uint8)ADC_E_IDLE \
        );
    }
    else
    {
        /** Specification of ADC Driver : [SWS_Adc_00387] [SWS_Adc_00216] **/
        if((sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus == (Adc_StatusType)ADC_IDLE) \
            || (sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus == (Adc_StatusType)ADC_BUSY))
        {
            u16Adc_ResultNum = (Adc_StreamNumSampleType)0U;
            *pAdc_PtrToSamplePtr = NULL_PTR;
        }
        else
        {
            if(sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultIndex == (Adc_StreamNumSampleType)0U)
            {
                u16Adc_LastPoint \
                    = (uint16)(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].StreamNumSamp - (Adc_StreamNumSampleType)1U);/* polyspace RTE:NIV */
                u16Adc_ResultNum = Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].StreamNumSamp;
            }
            else
            {
                u16Adc_LastPoint \
                    = (uint16)(sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultIndex - (Adc_StreamNumSampleType)1U);/* polyspace RTE:NIV */
                u16Adc_ResultNum = sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultIndex;
            }
            /* SWS_Adc_00418 */
            **pAdc_PtrToSamplePtr \
                = sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupResultBufferPtr[u16Adc_LastPoint];/* polyspace RTE:NIV,IDP */
            bAdc_ImplicStop = sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupImplicStop;
            if ((Adc_StatusType)ADC_STREAM_COMPLETED \
                == sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus)
            {
                if ((boolean)FALSE == bAdc_ImplicStop)
                {
                    /** Specification of ADC Driver : [SWS_Adc_00326] **/
                    sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = (Adc_StatusType)ADC_BUSY;
                }
                else
                {
                    /** Specification of ADC Driver : [SWS_Adc_00327] **/
                    sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = (Adc_StatusType)ADC_IDLE;
                    if(u16Adc_HwUnitId < ADC_MAX_HW_UNITS)
                    {
                        if(Adc_ConfigPtr[u32Adc_ICoreId]->Adc_GroupConfig[u16Adc_Group].SwOrHw == ADC_TRIGG_SRC_HW)/* polyspace RTE:NIV */
                        {
                            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_HTStatus = HWUNIT_HT_OFF;
                        }
                        else
                        {
                            sAdc_RunningUnit[u32Adc_ICoreId][u16Adc_HwUnitId].HwUnit_STStatus = HWUNIT_ST_IDLE;
                        }
                    }
                    
                }
            }
            else if ((Adc_StatusType)ADC_COMPLETED == sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus)
            {
                /** Specification of ADC Driver : [SWS_Adc_00328] **/
                sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_Group].GroupStatus = (Adc_StatusType)ADC_BUSY;
            }
            else
            {
                /* No action */
            }
        }
    }
    return u16Adc_ResultNum;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
#define ADC_START_SEC_CODE
#include "Adc_MemMap.h"
FUNC(Std_ReturnType, ADC_CODE) Adc_AutoSar_Wrapper_SetPowerState \
( \
    P2VAR(Adc_PowerStateRequestResultType, AUTOMATIC, ADC_APPL_DATA) pAdc_Result \
) 
{
    VAR(Std_ReturnType, ADC_VAR) u8Adc_retVal = (Std_ReturnType)E_NOT_OK;
    VAR(boolean, ADC_VAR) bAdc_IsIDLE = TRUE;
    VAR(Adc_GroupType, ADC_VAR) u16Adc_GroupId;
    VAR(uint32, AUTOMATIC) u32Adc_ICoreId = GetCoreID();
    for (u16Adc_GroupId = 0; u16Adc_GroupId < ADC_CONFIG_GROUPS; u16Adc_GroupId++) /* PRQA S 2877 */
    {
        if(sAdc_RunningGroup[u32Adc_ICoreId][u16Adc_GroupId].GroupStatus != (Adc_StatusType)ADC_IDLE)/* polyspace RTE:OBAI */
        {
            bAdc_IsIDLE = FALSE;
            break;
        }
    }
    
    if(bAdc_IsIDLE == FALSE)
    {
        /** Specification of ADC Driver : [SWS_Adc_00487] **/
        (void)Det_ReportRuntimeError \
        ( \
            (uint16)ADC_MODULE_ID, \
            (uint8)0U, \
            ADC_SETPOWERSTATE_ID, \
            (uint8)ADC_E_NOT_DISENGAGED \
        );
    }
    else
    {
        /** Specification of ADC Driver : [SWS_Adc_00482] **/
        u8Adc_retVal = (Std_ReturnType)E_OK;
        *pAdc_Result = ADC_SERVICE_ACCEPTED;
    }
    return u8Adc_retVal;
}
#define ADC_STOP_SEC_CODE
#include "Adc_MemMap.h"
#endif /* ADC_POWER_STATE_SUPPORTED == STD_ON */

#ifdef __cplusplus
}
#endif
