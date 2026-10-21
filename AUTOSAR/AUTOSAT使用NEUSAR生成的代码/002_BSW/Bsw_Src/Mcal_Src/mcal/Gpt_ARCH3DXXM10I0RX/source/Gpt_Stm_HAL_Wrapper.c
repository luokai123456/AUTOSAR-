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
*   @file    Gpt_Stm_HAL_Wrapper.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Gpt
*   @{
*/
/* PRQA S 0380,0686,2985,3432,2844 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Stm_HAL_Wrapper.h"
#include "Gpt_Irq.h"
#include "SchM_Gpt.h"
/*=====================================SOURCE FILE VERSION INFORMATION==============================*/

#define GPT_VENDOR_ID_C                 176
#define GPT_AR_MAJOR_VER_C              4
#define GPT_AR_MINOR_VER_C              4
#define GPT_AR_PATCH_VER_C              0
#define GPT_SW_MAJOR_VER_C              3
#define GPT_SW_MINOR_VER_C              0
#define GPT_SW_PATCH_VER_C              0

/*============================================FILE VERSION CHECKS===================================*/

/* Check if current file and GPT header file are of the same vendor */
#if (GPT_VENDOR_ID_C != GPT_VENDOR_ID)
#error "NON-MATCHED DATA : GPT_VENDOR_ID"
#endif

/* Check if current file and GPT header file are of the same Autosar version */
#if (GPT_AR_MAJOR_VER_C != GPT_CFG_AR_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MAJOR_VER"
#endif
#if (GPT_AR_MINOR_VER_C != GPT_CFG_AR_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_MINOR_VER"
#endif
#if (GPT_AR_PATCH_VER_C != GPT_CFG_AR_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_AR_PATCH_VER"
#endif

/* Check if current file and GPT header file are of the same Software version */
#if (GPT_SW_MAJOR_VER_C != GPT_CFG_SW_MAJOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MAJOR_VER"
#endif
#if (GPT_SW_MINOR_VER_C != GPT_CFG_SW_MINOR_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_MINOR_VER"
#endif
#if (GPT_SW_PATCH_VER_C != GPT_CFG_SW_PATCH_VER)
#error "NON-MATCHED DATA : GPT_CFG_SW_PATCH_VER"
#endif


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define STM_OVERFLOW_PAD_U32         ((uint32)1UL)

#define STM_CNT_MAX_VALUE_U32        ((uint32)0xFFFFFFFFUL)

#define STM_CIR_CIF_SET_MASK         ((uint32)1UL)

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#define GPT_START_SEC_VAR_INIT
#include "Gpt_MemMap.h"
VAR(uint32, GPT_VAR) u32StmTargetValue[GPT_STM_MODULE_MAX][GPT_STM_CHANNEL_MAX];
#define GPT_STOP_SEC_VAR_INIT
#include "Gpt_MemMap.h"


#define GPT_START_SEC_VAR_SHARED_INIT
#include "Gpt_MemMap.h"
static VAR(uint8, GPT_VAR) u8StmChannelStatus[GPT_STM_MODULE_MAX][GPT_STM_CHANNEL_MAX] = {{0u}};
#define GPT_STOP_SEC_VAR_SHARED_INIT
#include "Gpt_MemMap.h"


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(boolean, GPT_CODE) Stm_Channel_Check(VAR(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)STM_CHANNEL_INDEX_U32(u8Channel);
    VAR(boolean, AUTOMATIC) Ret = TRUE;
    /* check stm module within module define */
    if (!((u8ModuleId) < GPT_STM_MODULE_MAX))  
    {
    	Ret = (boolean)FALSE;
    }

    /* check stm channel within channel define */
    if (!((u8ChannelId) < GPT_STM_CHANNEL_MAX))  
    {
    	Ret = (boolean)FALSE;
    }

    return (boolean)Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_Init   \
( 											\
    VAR(uint8, AUTOMATIC) u8Channel,  \
    VAR(uint8, AUTOMATIC) u8StmPrescaler,   \
    VAR(boolean, AUTOMATIC) bFreezeEnable   \
)
{
    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(uint8, AUTOMATIC) u8channelId = (uint8)STM_CHANNEL_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);
    VAR(STM_ChannelID_Type, AUTOMATIC) eChannelId = Gpt_Stm_LLD_ConvertChanId(u8channelId);


    VAR(STM_DebugMode_Type, AUTOMATIC) debugMode = STM_FREEZEOFF;

    /* check stm channel is valid */
    if (Stm_Channel_Check(u8Channel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_00();

        if (Gpt_Stm_LLD_IsModuleEnable(eModuleId) == STM_Disable)
        {
            /*Set module prescaler*/
            Gpt_Stm_LLD_SetPrescaler(eModuleId, u8StmPrescaler);

            debugMode = ((boolean)TRUE == bFreezeEnable) ? STM_FREEZEON : STM_FREEZEOFF;
            /*Set module freeze mode*/
            Gpt_Stm_LLD_SetDebugFreeze(eModuleId, debugMode);

            /*Enable module clock*/
            (void)Gpt_Stm_LLD_ModuleEnable(eModuleId);
        }

        /*Set channel compare value*/
        Gpt_Stm_LLD_SetCompareValue(eModuleId, eChannelId, 0u);
        /* Disable channel interrupt */
        Gpt_Stm_LLD_ChannelDisable(eModuleId, eChannelId);
        /* Clear interrupt flag */
        Gpt_Stm_LLD_ClearIntFlag(eModuleId, eChannelId);

        u8StmChannelStatus[u8moduleId][u8channelId] = (uint8)GPT_READY; /* polyspace RTE:OBAI */
    
        SchM_Exit_Gpt_EXCLUSIVE_AREA_00();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_DeInit(VAR(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(uint8, AUTOMATIC) u8channelId = (uint8)STM_CHANNEL_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);
    VAR(STM_ChannelID_Type, AUTOMATIC) eChannelId = Gpt_Stm_LLD_ConvertChanId(u8channelId);
    VAR(uint8, AUTOMATIC) u8StatusCnt = 0;

    /* check stm channel is valid */
    if (Stm_Channel_Check(u8Channel) != (boolean)FALSE)
    {
        if (Gpt_Stm_LLD_IsModuleEnable(eModuleId) == STM_Enable)
        {
            SchM_Enter_Gpt_EXCLUSIVE_AREA_01();

            /*Disable channel*/
            Gpt_Stm_LLD_ChannelDisable(eModuleId, eChannelId);
            /*Clear channel interrupt flag*/
            Gpt_Stm_LLD_ClearIntFlag(eModuleId, eChannelId);
            /*Reset channel compare value*/
            Gpt_Stm_LLD_SetCompareValue(eModuleId, eChannelId, 0u);

            u8StmChannelStatus[u8moduleId][u8channelId] = (uint8)GPT_UNINIT;/* polyspace RTE:OBAI */

            for(uint8 i = 0; i < GPT_STM_CHANNEL_MAX; i++)
            {
                u8StatusCnt = u8StmChannelStatus[u8moduleId][i] + u8StatusCnt;
            }
            if(u8StatusCnt == (uint8)GPT_UNINIT)
            {
                Gpt_Stm_LLD_Deinit(eModuleId);
            }
            
            SchM_Exit_Gpt_EXCLUSIVE_AREA_01();
        }
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Stm_Wrapper_GetTimeElapsed 			\
( 																\
    VAR(uint8, AUTOMATIC) u8Channel, 						\
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbStm_IsRollover,  \
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32Stm_TargetValue \
)
{
    VAR(uint32, AUTOMATIC) returnValue = 0u;
    VAR(uint32, AUTOMATIC) compareValue = 0u;
    VAR(uint32, AUTOMATIC) counterValue = 0u;
    VAR(uint32, AUTOMATIC) tempValue = 0u;
    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(uint8, AUTOMATIC) u8channelId = (uint8)STM_CHANNEL_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);
    VAR(STM_ChannelID_Type, AUTOMATIC) eChannelId = Gpt_Stm_LLD_ConvertChanId(u8channelId);
    
    /* check stm channel is valid */
    if (Stm_Channel_Check(u8Channel) == (boolean)FALSE)
    {
        returnValue = 0u;
    }
    else
    {
        *pu32Stm_TargetValue = u32StmTargetValue[eModuleId][eChannelId];

        counterValue = Gpt_Stm_LLD_GetCounter(eModuleId);
        compareValue = Gpt_Stm_LLD_GetCompareValue(eModuleId, eChannelId);

        if (counterValue >= compareValue)
        {
            tempValue = ((STM_CNT_MAX_VALUE_U32 - counterValue) + compareValue) + STM_OVERFLOW_PAD_U32;
        }
        else
        {
            tempValue = compareValue - counterValue;
        }

        if (tempValue > *pu32Stm_TargetValue)
        {
            returnValue = *pu32Stm_TargetValue;
        }
        else
        {
            returnValue = *pu32Stm_TargetValue - tempValue;
        }

        /*get channel interrupt flag*/
        if (Gpt_Stm_LLD_GetIntFlag(eModuleId, eChannelId) == STM_CIR_CIF_SET_MASK)
        {
            *pbStm_IsRollover = (boolean)TRUE;
        }
        else
        {
            *pbStm_IsRollover = (boolean)FALSE;
        }
    }
    return returnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Stm_Wrapper_GetTimeRemaining \
(                                                       \
    VAR(uint8, AUTOMATIC) u8Channel               	    \
)
{
    VAR(uint32, AUTOMATIC) returnValue = 0UL;
    VAR(boolean, AUTOMATIC) isRollover =(boolean)FALSE;
    VAR(uint32, AUTOMATIC) targetValue = 0UL;
    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(uint8, AUTOMATIC) u8channelId = (uint8)STM_CHANNEL_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);
    VAR(STM_ChannelID_Type, AUTOMATIC) eChannelId = Gpt_Stm_LLD_ConvertChanId(u8channelId);

    /* check stm channel is valid */
    if (Stm_Channel_Check(u8Channel) == (boolean)FALSE)
    {
        returnValue = 0;
    }
    else
    {
        returnValue = Gpt_Stm_Wrapper_GetTimeElapsed(u8Channel, &isRollover, &targetValue);

        returnValue = u32StmTargetValue[eModuleId][eChannelId] - returnValue;
    }

    return returnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_StartTimer \
(                                               \
    VAR(uint8, AUTOMATIC) u8Channel,      \
    VAR(uint32, AUTOMATIC) u32Stm_Value         \
)
{
    VAR(uint32, AUTOMATIC) counterValue = 0;

    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(uint8, AUTOMATIC) u8channelId = (uint8)STM_CHANNEL_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);
    VAR(STM_ChannelID_Type, AUTOMATIC) eChannelId = Gpt_Stm_LLD_ConvertChanId(u8channelId);
    /* check stm channel is valid */
    if (Stm_Channel_Check(u8Channel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_02();

        counterValue = Gpt_Stm_LLD_GetCounter(eModuleId);


        Gpt_Stm_LLD_SetCompareValue(eModuleId, eChannelId, counterValue + u32Stm_Value);
        

        u32StmTargetValue[eModuleId][eChannelId] = u32Stm_Value;

        Gpt_Stm_LLD_ChannelEnable(eModuleId, eChannelId);
        
        SchM_Exit_Gpt_EXCLUSIVE_AREA_02();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_StopTimer(VAR(uint8, AUTOMATIC) u8Channel)
{

    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(uint8, AUTOMATIC) u8channelId = (uint8)STM_CHANNEL_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);
    VAR(STM_ChannelID_Type, AUTOMATIC) eChannelId = Gpt_Stm_LLD_ConvertChanId(u8channelId);

    /* check stm channel is valid */
    if (Stm_Channel_Check(u8Channel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_03();
        Gpt_Stm_LLD_ChannelDisable(eModuleId, eChannelId);
        Gpt_Stm_LLD_ClearIntFlag(eModuleId, eChannelId);
        SchM_Exit_Gpt_EXCLUSIVE_AREA_03();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Stm_Wrapper_GetPredefTimerValue   \
(                                                            \
    VAR(uint8, AUTOMATIC) u8Channel,                         \
    VAR(Gpt_PredefTimerType, AUTOMATIC) eStm_PredefTimerType \
)
{
    VAR(uint32, AUTOMATIC) returnValue = 0;

    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);

    /* check stm channel is valid */
    if (Stm_Channel_Check(u8Channel) == (boolean)FALSE)
    {
        returnValue = 0;
    }
    else
    {   
        /*
            [SWS_Gpt_00395]  The function Gpt_GetPredefTimerValue shall return the
            current value of the GPT Predef Timer passed by PredefTimer. 
        */
        returnValue = Gpt_Stm_LLD_GetCounter(eModuleId);

        switch(eStm_PredefTimerType)
        {
            /*
                [SWS_Gpt_00396]  If the timer value of the function Gpt_GetPredefTimerValue
                is less than 32 bit (16bit or 24bit timer), the upper bits shall be filled with zero. 
            */
            case GPT_PREDEF_TIMER_1US_16BIT:
            {
                returnValue = (0x0000FFFFU & returnValue);
                break;
            }
            case GPT_PREDEF_TIMER_1US_24BIT:
            {
                returnValue = (0x00FFFFFFU & returnValue);
                break;
            }
            case GPT_PREDEF_TIMER_1US_32BIT:
            case GPT_PREDEF_TIMER_100US_32BIT:
            {
                break;
            }
            default:
            {
                /* 32bit timer */
                break;
            }
        }
    }
    return  returnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_StartPredefTimer
(
    VAR(uint8, AUTOMATIC) u8Channel,
    VAR(uint8, AUTOMATIC) u8StmPrescaler,
    VAR(boolean, AUTOMATIC) bFreezeEnable
)
{
    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);
    VAR(STM_DebugMode_Type, AUTOMATIC) debugMode = STM_FREEZEOFF;

    if (Gpt_Stm_LLD_IsModuleEnable(eModuleId) == STM_Disable)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_04();

        /* Reset stm counter 0 */
    	Gpt_Stm_LLD_SetCounter(eModuleId, 0);

        /* Set stm module prescaler */
        Gpt_Stm_LLD_SetPrescaler(eModuleId, u8StmPrescaler);
        /* Set Freeze mode */
        debugMode = ((boolean)TRUE == bFreezeEnable) ? STM_FREEZEON : STM_FREEZEOFF;
        (void)Gpt_Stm_LLD_SetDebugFreeze(eModuleId, debugMode);
        /* Enable Module */
        (void)Gpt_Stm_LLD_ModuleEnable(eModuleId);

        SchM_Exit_Gpt_EXCLUSIVE_AREA_04();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Stm_Wrapper_StopPredefTimer (VAR(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8moduleId  = (uint8)STM_MODULE_INDEX_U32(u8Channel);
    VAR(STM_ModuleID_Type, AUTOMATIC) eModuleId = Gpt_Stm_LLD_ConvertModuleId(u8moduleId);
	/* Check Stm Module Status is DISABLE */
	if (Gpt_Stm_LLD_IsModuleEnable(eModuleId) == STM_Enable)
	{
        SchM_Enter_Gpt_EXCLUSIVE_AREA_05();

        /* Disable Module */
        Gpt_Stm_LLD_ModuleDisable(eModuleId);
        /* Reset stm counter 0 */
        Gpt_Stm_LLD_SetCounter(eModuleId, 0);
        /* Reset Pre-scaler 0 */
        Gpt_Stm_LLD_SetPrescaler(eModuleId, 0);

        SchM_Exit_Gpt_EXCLUSIVE_AREA_05();
	}
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#ifdef __cplusplus
}
#endif

