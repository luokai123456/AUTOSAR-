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
*   @file    Gpt_Pit_HAL_Wrapper.c
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

#include "Gpt_Pit_HAL_Wrapper.h"
#include "Gpt.h"
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

#define GPT_START_SEC_VAR_NO_INIT
#include "Gpt_MemMap.h"
VAR(PIT_ClkFreq, AUTOMATIC) PitClkFreq;
#define GPT_STOP_SEC_VAR_NO_INIT
#include "Gpt_MemMap.h"

#define GPT_START_SEC_VAR_SHARED_INIT
#include "Gpt_MemMap.h"
static VAR(uint8, GPT_VAR) u8PitChannelStatus[GPT_PIT_MODULE_MAX][GPT_PIT_MODULE_CHANNEL_MAX] = {{0u}};
#define GPT_STOP_SEC_VAR_SHARED_INIT
#include "Gpt_MemMap.h"

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(boolean, GPT_CODE) Gpt_Pit_Channel_Check(VAR(uint8, AUTOMATIC) u8Pit_HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);

    VAR(boolean, AUTOMATIC) Ret = TRUE;
    /* check pit module within module define */
    if (!((u8ModuleId) < GPT_PIT_MODULE_MAX)) 
    {
        Ret = (boolean)FALSE;
    }

    /* check pit channel within channel define */
    if (!((u8ChannelId) < GPT_PIT_MODULE_CHANNEL_MAX)) 
    {
        Ret = (boolean)FALSE;
    }

    return (boolean)Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_Wrapper_Init   \
(                                           \
    VAR(uint8, AUTOMATIC) u8Pit_HwChannel,  \
    VAR(boolean, AUTOMATIC) bPit_FreezeEnable
#if (GPT_PIT_CHAIN_MODE == STD_ON)
    ,
    VAR(boolean, AUTOMATIC) bGpt_Pit_ChainMode
#endif
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8ModuleId);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8ChannelId);

    /* check PIT channel is valid */
    if (Gpt_Pit_Channel_Check(u8Pit_HwChannel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_06();

        /*Enable PIT moduel clock*/
        Gpt_Pit_LLD_ModuleEnable(eModuleId);

        /*Enable RTI moduel clock*/
        (void)Gpt_Rti_LLD_ModuleEnable(eModuleId);

        /*Set channel load u32Pit_Value*/
        (void)Gpt_Pit_LLD_SetLoadValue
        (
            eModuleId, eChannelId, 0xFFFFFFFFU,PIT_Period_Count
        );

        /*Diable channel*/
        Gpt_Pit_LLD_ChannelDisable(eModuleId, eChannelId);

        /* Disable channel interrupt */
        Gpt_Pit_LLD_SetChIntState(eModuleId, eChannelId, PIT_Status_Disable);

        /* Clear interrupt flag */
        (void)Gpt_Pit_LLD_ClearIntFlag(eModuleId, eChannelId);

    #if (GPT_PIT_CHAIN_MODE == STD_ON)
        if (bGpt_Pit_ChainMode == (boolean)TRUE)
        {
            Gpt_Pit_LLD_SetChChainMode(eModuleId, eChannelId, PIT_Status_Enable);
        }
        else
        {
            Gpt_Pit_LLD_SetChChainMode(eModuleId, eChannelId, PIT_Status_Disable);
        }
    #endif

        if(bPit_FreezeEnable == TRUE)
        {
            Gpt_Pit_LLD_SetDebugFreeze(eModuleId, FREEZEON);
        }
        else
        {
            Gpt_Pit_LLD_SetDebugFreeze(eModuleId, FREEZEOFF);
        }
        
        u8PitChannelStatus[u8ModuleId][u8ChannelId] = (uint8)GPT_READY;/* polyspace RTE:OBAI */

        SchM_Exit_Gpt_EXCLUSIVE_AREA_06();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE)  Gpt_Pit_Disable_Channel \
(                                   \
    VAR(uint8, AUTOMATIC) u8Module, \
    VAR(uint8, AUTOMATIC) u8Channel \
)
{
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8Module);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8Channel);

    SchM_Enter_Gpt_EXCLUSIVE_AREA_07();

    /*Clear RTI channel interrupt flag*/
    (void)Gpt_Pit_LLD_ClearIntFlag(eModuleId, eChannelId);/*PRQA S 4442*/
    /*Clear load value register*/
    (void)Gpt_Pit_LLD_SetLoadValue(eModuleId, eChannelId, 1U, PIT_Period_Count);/*PRQA S 4442*/
    /*Disable PIT channel*/
    Gpt_Pit_LLD_ChannelDisable(eModuleId, eChannelId);/*PRQA S 4442*/
    if (PIT0 == eModuleId)
    {
        /*Disable PIT channel chain mode*/
        Gpt_Pit_LLD_SetChChainMode(eModuleId, eChannelId, PIT_Status_Disable);/*PRQA S 4442*/
    }
    /*Disable PIT channel interrupt*/
    Gpt_Pit_LLD_SetChIntState(eModuleId, eChannelId, PIT_Status_Disable);/*PRQA S 4442*/

    SchM_Exit_Gpt_EXCLUSIVE_AREA_07();
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_Wrapper_DeInit(VAR(uint8, AUTOMATIC) u8Pit_HwChannel)
{
    VAR(uint8, AUTOMATIC) u8StatusCnt = 0;

    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8ModuleId);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8ChannelId);

    /* check PIT channel is valid */
    if (Gpt_Pit_Channel_Check(u8Pit_HwChannel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_08();     
        if ((eChannelId == PIT_RTI) && (eModuleId == PIT0))
        {
            /*Disable RTI moduel clock*/
            (void)Gpt_Rti_LLD_ModuleDisable(PIT0);
            /*Clear load value register*/
            (void)Gpt_Pit_LLD_SetLoadValue(PIT0, PIT_RTI, 1U, PIT_Period_Count);
            /*Disable RTI channel*/
            Gpt_Pit_LLD_ChannelDisable(PIT0, PIT_RTI);
            /*Disable RTI channel interrupt*/
            Gpt_Pit_LLD_SetChIntState(PIT0, PIT_RTI, PIT_Status_Disable);
            /*Clear RTI channel interrupt flag*/
            (void)Gpt_Pit_LLD_ClearIntFlag(PIT0, PIT_RTI);
        }
        else
        {
            Gpt_Pit_Disable_Channel((uint8)eModuleId, (uint8)eChannelId);
        }

        u8PitChannelStatus[u8ModuleId][u8ChannelId] = (uint8)GPT_UNINIT;/* polyspace RTE:OBAI */

        for(uint8 i = 0; i < GPT_PIT_MODULE_CHANNEL_MAX; i++)
        {
            u8StatusCnt = u8PitChannelStatus[u8ModuleId][i] + u8StatusCnt;
        }

        /* all channel disable, then disable PIT module */
        if(u8StatusCnt == (uint8)GPT_UNINIT)
        {
            Gpt_Pit_LLD_Deinit(eModuleId);
        }
        SchM_Exit_Gpt_EXCLUSIVE_AREA_08();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Pit_Wrapper_GetTimeElapsed 			\
( 																\
    VAR(uint8, AUTOMATIC) u8Pit_HwChannel, 						\
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbPit_IsRollover,  \
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32Pit_TargetValue \
)
{    
    VAR(uint32, AUTOMATIC)  returnValue = 0;
    VAR(uint32, AUTOMATIC)  tFlag = 0;
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8ModuleId);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8ChannelId);


    /* check PIT channel is valid */
    if (Gpt_Pit_Channel_Check(u8Pit_HwChannel) != (boolean)FALSE)
    {
		if (eChannelId == PIT_RTI)
		{
			/* PIT RTI Timer used only once */
		}
		else
		{
			/* Get PIT channel auto-reload register value */
			*pu32Pit_TargetValue = Gpt_Pit_LLD_GetLoadValue(eModuleId, eChannelId, PIT_Period_Count);

			/* Get PIT channel current value */
			returnValue = *pu32Pit_TargetValue - Gpt_Pit_LLD_GetCurrentValue(eModuleId, eChannelId);

			/* Get interrupt status flag */
			tFlag = Gpt_Pit_LLD_GetIntFlag(eModuleId, eChannelId);
			if (tFlag == 0UL)
			{
				/* Channel counter wasn't roll-over */
				*pbPit_IsRollover = (boolean)FALSE;
			}
			/* Interrupt is set */
			else
			{
				/* Channel counter was roll-over */
				*pbPit_IsRollover = (boolean)TRUE;
			}
		}
    }
    return returnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Pit_Wrapper_GetTimeRemaining \
( 														\
    VAR(uint8, AUTOMATIC) u8Pit_HwChannel 				\
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8ModuleId);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8ChannelId);
    VAR(uint32, AUTOMATIC)  returnValue = 0;

    /* check PIT channel is valid */
    if (Gpt_Pit_Channel_Check(u8Pit_HwChannel) == (boolean)FALSE)
    {
        returnValue =  0;
    }
    else
    {
        /* PIT CVAL register is counter down, remain value is CVAL */
        returnValue = Gpt_Pit_LLD_GetCurrentValue(eModuleId, eChannelId);
    }
    return returnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_Wrapper_StartTimer \
( 												\
    VAR(uint8, AUTOMATIC) u8Pit_HwChannel, 		\
    VAR(uint32, AUTOMATIC) u32Pit_Value 		\
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8ModuleId);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8ChannelId);
    VAR(Std_ReturnType, AUTOMATIC) status = (Std_ReturnType)E_NOT_OK;
    VAR(uint32, AUTOMATIC) retry = GPT_RETRY_TIMEOUT_COUNTER;

    /* check PIT channel is valid */
    if (Gpt_Pit_Channel_Check(u8Pit_HwChannel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_09();

        /* Disable PIT channel */
        Gpt_Pit_LLD_ChannelDisable(eModuleId, eChannelId);

        while ((status != (Std_ReturnType)E_OK) && (retry != 0u))
        {
            status = Gpt_Pit_LLD_SetLoadValue(eModuleId, eChannelId, u32Pit_Value, PIT_Period_US);
            retry--;
        }

        if (retry != 0u)
        {
            /* Disable PIT channel */
            Gpt_Pit_LLD_ChannelEnable(eModuleId, eChannelId);
        }

        SchM_Exit_Gpt_EXCLUSIVE_AREA_09();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_Wrapper_StopTimer(VAR(uint8, AUTOMATIC) u8Pit_HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8ModuleId);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8ChannelId);

    /* check PIT channel is valid */
    if (Gpt_Pit_Channel_Check(u8Pit_HwChannel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_10();

        /* Disable PIT channel */
        Gpt_Pit_LLD_ChannelDisable(eModuleId, eChannelId);

        /* Clear interrupt flag TIF */
        (void)Gpt_Pit_LLD_ClearIntFlag(eModuleId, eChannelId);

        SchM_Exit_Gpt_EXCLUSIVE_AREA_10();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_Wrapper_EnableNotification \
(                                          \
    VAR(uint8, AUTOMATIC) u8Pit_HwChannel  \
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8ModuleId);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8ChannelId);

    /* check PIT channel is valid */
    if (Gpt_Pit_Channel_Check(u8Pit_HwChannel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_11();

        /* Clear interrupt flag TIF */
        (void)Gpt_Pit_LLD_ClearIntFlag(eModuleId, eChannelId);

        /* Enable PIT channel interrupt */
        Gpt_Pit_LLD_SetChIntState(eModuleId, eChannelId, PIT_Status_Enable);

        SchM_Exit_Gpt_EXCLUSIVE_AREA_11();
    }

}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Pit_Wrapper_DisableNotification \
(                                           \
    VAR(uint8, AUTOMATIC) u8Pit_HwChannel   \
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)PIT_MODULE_INDEX_U32(u8Pit_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)PIT_CHANNEL_INDEX_U32(u8Pit_HwChannel);
    VAR(PIT_Module_t, AUTOMATIC)eModuleId = Gpt_Pit_LLD_ConvertModuleId(u8ModuleId);
    VAR(PIT_Channel_t, AUTOMATIC)eChannelId = Gpt_Pit_LLD_ConvertChannelId(u8ChannelId);

    /* check PIT channel is valid */
    if (Gpt_Pit_Channel_Check(u8Pit_HwChannel) != (boolean)FALSE)
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_12();
        
		/* Clear interrupt flag TIF */
		Gpt_Pit_LLD_ClearIntFlag(eModuleId, eChannelId);
		/* Disable PIT channel interrupt */
		Gpt_Pit_LLD_SetChIntState(eModuleId, eChannelId, PIT_Status_Disable);

        SchM_Exit_Gpt_EXCLUSIVE_AREA_12();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#ifdef __cplusplus
}
#endif
