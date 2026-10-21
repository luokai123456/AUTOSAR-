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
*   @file    Gpt_Gtm_HAL_Wrapper.c
*   @version 3.0.0
*
*      AUTOSAR 4.4.0 - Common Level Driver source file.
*    Autosar layer of Gpt MCAL driver.
*
*   @addtogroup Gpt
*   @{
*/
/* PRQA S 0380,2985,3432 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Gpt_Gtm_HAL_Wrapper.h"
#include "Gpt.h"
#include "Gpt_Irq.h"
#include "SchM_Gpt.h"
#if (defined(RESOURCE_SUPPORT_GTM104) || defined(RESOURCE_SUPPORT_GTM410))

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
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define GPT_GTM_CMU_DEINIT_VAL            (0UL)
#define GPT_GTM_CMU_GCLK_NUM_DEINIT_VAL   (1UL)
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(void, GPT_CODE) GPT_GTM_CMU_LLD_IsEnableAllClock        \
(                                                                   \
    VAR(VAR(GPT_GTM_Status_Type, AUTOMATIC), AUTOMATIC) IsEnable    \
)
{
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_FXCLK, IsEnable);
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK0, IsEnable);
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK1, IsEnable);
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK2, IsEnable);
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK3, IsEnable);
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK4, IsEnable);
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK5, IsEnable);
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK6, IsEnable);
    (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK7, IsEnable);
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
GPT_INLINE FUNC(boolean, GPT_CODE) Gpt_Gtm_Channel_Check(VAR(uint8, AUTOMATIC) u8Gtm_HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);

    VAR(boolean, AUTOMATIC) Ret = TRUE;
    /* check GTM module within module define */
    if (!((u8ModuleId) < GPT_GTM_MODULE_MAX))
    {
    	Ret = (boolean)FALSE;
    }

    /* check GTM channel within channel define */
    if (!((u8ChannelId) < GPT_GTM_CHANNEL_MAX))
    {
    	Ret = (boolean)FALSE;
    }

    return (boolean)Ret;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

/**
    @breif: gtm init
    @param: u32ChannelRegCtrl1: bit0~bit2   source clock
                                bit3:       mode (0: continue, 1:one-shot)
**/
#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_Init       \
(                                               \
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel, \
    VAR(uint32,     AUTOMATIC) u32Gtm_ChannelRegCtrl1,
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
    VAR(boolean,    AUTOMATIC) bGtm_SupportOutputEnable,
#endif
    VAR(boolean,    AUTOMATIC) bGtm_FreezeEnable \
)
{
	(void)bGtm_FreezeEnable;
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId = Gpt_GTM_LLD_ConvertModuleId(u8ModuleId);
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId = Gpt_Gtm_LLD_ConvertChannelId(u8ChannelId);

    VAR(uint32, AUTOMATIC) u32Gpt_ChannelMode = 0;
    VAR(GPT_GTM_TOM_ClockSource_Type, AUTOMATIC) Gpt_CntSrc = GPT_GTM_TOM_CLK_SRC_CMU_FXCLK0;
    VAR(uint8, AUTOMATIC) u8Gpt_CntSrc_temp = 0;

    /* check GTM channel is valid */
    if (Gpt_Gtm_Channel_Check(u8Gtm_HwChannel) == (boolean)FALSE)
    {
        /* no action */
    }
    else
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_13();

        /* write the GTM_CTRL value */
        u8Gpt_CntSrc_temp = (uint8)(u32Gtm_ChannelRegCtrl1 & 0x00000007UL);
        switch(u8Gpt_CntSrc_temp)
        {
            case 0:
            {
                Gpt_CntSrc  = GPT_GTM_TOM_CLK_SRC_CMU_FXCLK0;
                break;
            }
            case 1:
            {
                Gpt_CntSrc  = GPT_GTM_TOM_CLK_SRC_CMU_FXCLK1;
                break;
            }
            case 2:
            {
                Gpt_CntSrc  = GPT_GTM_TOM_CLK_SRC_CMU_FXCLK2;
                break;
            }
            case 3:
            {
                Gpt_CntSrc  = GPT_GTM_TOM_CLK_SRC_CMU_FXCLK3;
                break;
            }
            case 4:
            {
                Gpt_CntSrc  = GPT_GTM_TOM_CLK_SRC_CMU_FXCLK4;
                break;
            }
            default:
            {
                Gpt_CntSrc = GPT_GTM_TOM_CLK_SRC_NO_CMU_FXCLK;
                break;
            }
        }
        /* Select clock source */
        (void)GPT_GTM_TOM_LLD_SelectClockSource(eModuleId, eChannelId, \
                                        Gpt_CntSrc);

        /* GPT_GTM_Disable GTM channel, wait config complete */
        (void)GPT_GTM_TOM_LLD_IsEnableChannel \
                    (eModuleId, eChannelId, GPT_GTM_Disable);

#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
        if((boolean)TRUE == bGtm_SupportOutputEnable)
        {
            GPT_GTM_TOM_LLD_IsEnableOut(eModuleId, eChannelId, GPT_GTM_Enable);
        }
#endif // GPT_GTM_OUTPUT_ENABLE_MODE

        /* Disabale all interrupt */
        (void)GPT_GTM_TOM_LLD_IsEnableInterrupt \
        ( \
            eModuleId, eChannelId, GPT_GTM_TOM_IRQ_CCU0TC, GPT_GTM_Disable \
        );
        (void)GPT_GTM_TOM_LLD_IsEnableInterrupt \
        ( \
            eModuleId, eChannelId, GPT_GTM_TOM_IRQ_CCU1TC, GPT_GTM_Disable \
        );

        /* Clear all interrupt flags */
        (void)GPT_GTM_TOM_LLD_ClearInterruptFlag \
        ( \
            eModuleId, eChannelId, GPT_GTM_TOM_IRQ_CCU0TC \
        );
        (void)GPT_GTM_TOM_LLD_ClearInterruptFlag \
        ( \
                eModuleId, eChannelId, GPT_GTM_TOM_IRQ_CCU1TC \
        );

        /* Reset Counter 0, CN0 */
        (void)GPT_GTM_TOM_LLD_SetCounter(eModuleId, eChannelId, 0);

        /* Reset Compare1 and Compare2 0, CM0,CM1 */
        (void)GPT_GTM_TOM_LLD_SetCompareRegister(eModuleId, eChannelId, 0, 0);

        /* Reset Shadow1 and Shadow2 0, S0,S1 */
        (void)GPT_GTM_TOM_LLD_SetShadowRegister(eModuleId, eChannelId, 0, 0);

        /* GPT_GTM_Enable update for control and CM0, CM1 register */
        (void)GPT_GTM_TOM_LLD_IsEnableUpdate(eModuleId, eChannelId, GPT_GTM_Enable);
#ifdef RESOURCE_SUPPORT_GTM410
        (void)GTM_LLD_HresEn();
#endif
        /* Reset source of CCU0 */
        (void)GPT_GTM_TOM_LLD_SelectCCU0ResetSource(eModuleId, eChannelId, \
                                        GPT_GTM_TOM_RST_CCU0_CM0);

        /* Set channel mode */
        u32Gpt_ChannelMode = (uint32)(u32Gtm_ChannelRegCtrl1 & 0x00000080UL);
        if (GTM_CH_MODE_ONESHOT == u32Gpt_ChannelMode)
        {
            (void)Gpt_GTM_TOM_LLD_IsEnableOneShotMode(eModuleId, eChannelId, \
                                                                        GPT_GTM_Enable);
        }
        else
        {
            (void)Gpt_GTM_TOM_LLD_IsEnableOneShotMode(eModuleId, eChannelId, \
                                                                        GPT_GTM_Disable);
        }

        /* GPT_GTM_Disable update for control and CM0, CM1 register */
        (void)GPT_GTM_TOM_LLD_IsEnableUpdate(eModuleId, eChannelId, GPT_GTM_Disable);
        
        SchM_Exit_Gpt_EXCLUSIVE_AREA_13();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_DeInit(VAR(uint8, AUTOMATIC) u8Gtm_HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId = Gpt_GTM_LLD_ConvertModuleId(u8ModuleId);
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId = Gpt_Gtm_LLD_ConvertChannelId(u8ChannelId);

    /* check GTM channel is valid */
    if (Gpt_Gtm_Channel_Check(u8Gtm_HwChannel) == (boolean)FALSE)
    {
        /* no action */
    }
    else
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_14();
        /* GPT_GTM_Disable GTM channel, wait config complete */
        (void)GPT_GTM_TOM_LLD_IsEnableChannel(eModuleId, eChannelId, GPT_GTM_Disable);

    #if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
        GPT_GTM_TOM_LLD_IsEnableOut(eModuleId, eChannelId, GPT_GTM_Disable);
    #endif // GPT_GTM_OUTPUT_ENABLE_MODE

        /* Disabale all interrupt */
        (void)GPT_GTM_TOM_LLD_IsEnableInterrupt(eModuleId, eChannelId, \
                                                    GPT_GTM_TOM_IRQ_CCU0TC, GPT_GTM_Disable);
        (void)GPT_GTM_TOM_LLD_IsEnableInterrupt(eModuleId, eChannelId, \
                                                    GPT_GTM_TOM_IRQ_CCU1TC, GPT_GTM_Disable);

        /* Clear all interrupt flags */
        (void)GPT_GTM_TOM_LLD_ClearInterruptFlag(eModuleId, eChannelId, \
                                                            GPT_GTM_TOM_IRQ_CCU0TC);
        (void)GPT_GTM_TOM_LLD_ClearInterruptFlag(eModuleId, eChannelId, \
                                                            GPT_GTM_TOM_IRQ_CCU1TC);

        /* Reset Counter 0, CN0 */
        (void)GPT_GTM_TOM_LLD_SetCounter(eModuleId, eChannelId, 0);

        /* Reset Compare1 and Compare2 0, CM0,CM1 */
        (void)GPT_GTM_TOM_LLD_SetCompareRegister(eModuleId, eChannelId, 0, 0);

        /* Reset Shadow1 and Shadow2 0, S0,S1 */
        (void)GPT_GTM_TOM_LLD_SetShadowRegister(eModuleId, eChannelId, 0, 0);

        /* GPT_GTM_Enable update for control and CM0, CM1 register */
        (void)GPT_GTM_TOM_LLD_IsEnableUpdate(eModuleId, eChannelId, GPT_GTM_Enable);

        /* GPT_GTM_Disable all config */
        /* Stop clock source */
        (void)GPT_GTM_TOM_LLD_SelectClockSource(eModuleId, eChannelId, \
                                                            GPT_GTM_TOM_CLK_SRC_NO_CMU_FXCLK);

        /* GPT_GTM_Disable update for control and CM0, CM1 register */
        (void)GPT_GTM_TOM_LLD_IsEnableUpdate(eModuleId, eChannelId, GPT_GTM_Disable);
        
        SchM_Exit_Gpt_EXCLUSIVE_AREA_14();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_Channel_StartTimer\
(                                               \
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel, \
    VAR(uint32,     AUTOMATIC) u32Gtm_Value     \
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId = Gpt_GTM_LLD_ConvertModuleId(u8ModuleId);
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId = Gpt_Gtm_LLD_ConvertChannelId(u8ChannelId);

    /* check GTM channel is valid */
    if (Gpt_Gtm_Channel_Check(u8Gtm_HwChannel) == (boolean)FALSE)
    {
        /* no action */
    }
    else
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_15();
#if (GPT_GTM_OUTPUT_ENABLE_MODE == STD_ON)
        GPT_GTM_TOM_LLD_SetCompareRegister(eModuleId, eChannelId, \
                                                u32Gtm_Value, (u32Gtm_Value >> 1));

        GPT_GTM_TOM_LLD_SetCounter(eModuleId, eChannelId, (u32Gtm_Value >> 1) + 1);
#else

        (void)GPT_GTM_TOM_LLD_SetCompareRegister(eModuleId, eChannelId, (uint16)u32Gtm_Value, (uint16)0);

        (void)GPT_GTM_TOM_LLD_SetCounter(eModuleId, eChannelId, (uint16)0);
#endif
        /* GPT_GTM_Enable GTM channel, wait config complete */
        (void)GPT_GTM_TOM_LLD_IsEnableChannel(eModuleId, eChannelId, GPT_GTM_Enable);

        (void)GPT_GTM_TOM_LLD_SetCounter(eModuleId, eChannelId, (uint16)0);

        SchM_Exit_Gpt_EXCLUSIVE_AREA_15();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_StopTimer(VAR(uint8, AUTOMATIC) u8Gtm_HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId = Gpt_GTM_LLD_ConvertModuleId(u8ModuleId);
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId = Gpt_Gtm_LLD_ConvertChannelId(u8ChannelId);

    /* check GTM channel is valid */
    if (Gpt_Gtm_Channel_Check(u8Gtm_HwChannel) == (boolean)FALSE)
    {
        /* no action */
    }
    else
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_16();
        /* GPT_GTM_Disable GTM channel, wait config complete */
        (void)GPT_GTM_TOM_LLD_IsEnableChannel(eModuleId, eChannelId, \
                                                            GPT_GTM_Disable);
        /* Clear all interrupt flags */
        (void)GPT_GTM_TOM_LLD_ClearInterruptFlag(eModuleId, eChannelId, \
                                                            GPT_GTM_TOM_IRQ_CCU0TC);
        (void)GPT_GTM_TOM_LLD_ClearInterruptFlag(eModuleId, eChannelId, \
                                                            GPT_GTM_TOM_IRQ_CCU1TC);
        SchM_Exit_Gpt_EXCLUSIVE_AREA_16();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Gtm_Wrapper_GetTimeElapsed \
(                                                     \
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel,       \
    P2VAR(boolean,  AUTOMATIC, GPT_APPL_DATA) pbGtm_IsChannelRollover, \
    P2VAR(uint32,   AUTOMATIC, GPT_APPL_DATA) pu32Gtm_TargetValue \
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId = Gpt_GTM_LLD_ConvertModuleId(u8ModuleId);
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId = Gpt_Gtm_LLD_ConvertChannelId(u8ChannelId);
    VAR(uint32, AUTOMATIC)  u32Gpt_ReturnValue = 0;

    /* check GTM channel is valid */
    if (Gpt_Gtm_Channel_Check(u8Gtm_HwChannel) == (boolean)FALSE)
    {
        u32Gpt_ReturnValue = 0;
    }
    else
    {
        /* Get compare counter value */
        *pu32Gtm_TargetValue = Gpt_GTM_TOM_LLD_Channel_GetCompareRegister(eModuleId, \
                                                                        eChannelId);

        /* Get counter value */
        u32Gpt_ReturnValue = (uint32)GPT_GTM_TOM_LLD_GetCounter(eModuleId, eChannelId) + 1U;

        /*Check for interrupt status flag*/
        if (GPT_GTM_TOM_LLD_GetInterruptFlag(eModuleId, eChannelId, \
                                                                        GPT_GTM_TOM_IRQ_CCU0TC) != (uint8)0U)
        {
            *pbGtm_IsChannelRollover = (boolean)TRUE;
        }
        else
        {
            *pbGtm_IsChannelRollover = (boolean)FALSE;
        }
    }


    return u32Gpt_ReturnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(uint32, GPT_CODE) Gpt_Gtm_Wrapper_GetTimeRemaining\
(                                         \
    VAR(uint8, AUTOMATIC) u8Gtm_HwChannel \
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId = Gpt_GTM_LLD_ConvertModuleId(u8ModuleId);
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId = Gpt_Gtm_LLD_ConvertChannelId(u8ChannelId);
    VAR(uint32, AUTOMATIC)  u32Gpt_CompareValue = 0;
    VAR(uint32, AUTOMATIC)  u32Gpt_ReturnValue = 0;

    /* check GTM channel is valid */
    if (Gpt_Gtm_Channel_Check(u8Gtm_HwChannel) == (boolean)FALSE)
    {
        u32Gpt_ReturnValue = 0;
    }
    else
    {
        /* Get compare counter value */
        u32Gpt_CompareValue = Gpt_GTM_TOM_LLD_Channel_GetCompareRegister(eModuleId, \
                                                                        eChannelId);

        /* Get counter value */
        u32Gpt_ReturnValue = (uint32)GPT_GTM_TOM_LLD_GetCounter(eModuleId, eChannelId) + 1U;

        u32Gpt_ReturnValue = u32Gpt_CompareValue - u32Gpt_ReturnValue;
    }



    return u32Gpt_ReturnValue;
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_EnableInterrupt \
(                                                    \
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel       \
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId = Gpt_GTM_LLD_ConvertModuleId(u8ModuleId);
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId = Gpt_Gtm_LLD_ConvertChannelId(u8ChannelId);

    /* check GTM channel is valid */
    if (Gpt_Gtm_Channel_Check(u8Gtm_HwChannel) == (boolean)FALSE)
    {
        /* no action */
    }
    else
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_17();
        /* GPT_GTM_Enable update for control and CM0, CM1 register */
        (void)GPT_GTM_TOM_LLD_IsEnableUpdate(eModuleId, eChannelId, GPT_GTM_Enable);

        /* GPT_GTM_Enable CCU0TC interrupts */
        (void)GPT_GTM_TOM_LLD_IsEnableInterrupt(eModuleId, eChannelId, \
                                                    GPT_GTM_TOM_IRQ_CCU0TC, GPT_GTM_Enable);

        /* Clear TOM CCU0/CCU1 interrupt flags */
        (void)GPT_GTM_TOM_LLD_ClearInterruptFlag(eModuleId, eChannelId, \
                                                    GPT_GTM_TOM_IRQ_CCU0TC);
        (void)GPT_GTM_TOM_LLD_ClearInterruptFlag(eModuleId, eChannelId, \
                                                    GPT_GTM_TOM_IRQ_CCU1TC);

        /* GPT_GTM_Disable update for control and CM0, CM1 register */
        (void)GPT_GTM_TOM_LLD_IsEnableUpdate(eModuleId, eChannelId, GPT_GTM_Disable);

        SchM_Exit_Gpt_EXCLUSIVE_AREA_17();
    }
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_Gtm_Wrapper_DisableInterrupt \
( \
    VAR(uint8,      AUTOMATIC) u8Gtm_HwChannel \
)
{
    VAR(uint8, AUTOMATIC) u8ModuleId  = (uint8)GTM_MODULE_INDEX_U32(u8Gtm_HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelId = (uint8)GTM_CHANNEL_INDEX_U32(u8Gtm_HwChannel);
    VAR(GPT_GTM_TOM_Type, AUTOMATIC) eModuleId = Gpt_GTM_LLD_ConvertModuleId(u8ModuleId);
    VAR(GPT_GTM_TOM_Channel_Type, AUTOMATIC) eChannelId = Gpt_Gtm_LLD_ConvertChannelId(u8ChannelId);

    /* check GTM channel is valid */
    if (Gpt_Gtm_Channel_Check(u8Gtm_HwChannel) == (boolean)FALSE)
    {
        /* no action */
    }
    else 
    {
        SchM_Enter_Gpt_EXCLUSIVE_AREA_18();
        /* GPT_GTM_Disable CCU0TC interrupts */
        (void)GPT_GTM_TOM_LLD_IsEnableInterrupt(eModuleId, eChannelId, \
                                                    GPT_GTM_TOM_IRQ_CCU0TC, GPT_GTM_Disable);
        SchM_Exit_Gpt_EXCLUSIVE_AREA_18();
    }

}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_GtmCmu_Wrapper_Init(P2CONST(GPT_GTM_CMU_LLD_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr)
{
    VAR(GTM_CMU_FXCLKSource_Type, AUTOMATIC) FXCLKSource = CMU_FXCLK_CTRL_CMU_GCLK_EN;

    SchM_Enter_Gpt_EXCLUSIVE_AREA_19();

    (void)GPT_GTMINT_LLD_IsEnableModule(GPT_GTM_Enable);

    GPT_GTM_CMU_LLD_IsEnableAllClock(GPT_GTM_Disable);

    (void)GPT_GTM_CMU_LLD_SetGlobalClockNumerator(configPtr->global_clock_numerator);
    (void)GPT_GTM_CMU_LLD_SetGlobalClockNumerator(configPtr->global_clock_numerator);

    (void)GPT_GTM_CMU_LLD_SetGlobalClockDenominator(configPtr->global_clock_denominator);

    switch (configPtr->cmu_fxclk_sel_register)
    {
        case 0:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_GCLK_EN;
            break;
        }
        case 1:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_CLK0;
            break;
        }
        case 2:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_CLK1;
            break;
        }
        case 3:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_CLK2;
            break;
        }
        case 4:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_CLK3;
            break;
        }
        case 5:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_CLK4;
            break;
        }
        case 6:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_CLK5;
            break;
        }
        case 7:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_CLK6;
            break;
        }
        case 8:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_CLK7;
            break;
        }
        default:
        {
            FXCLKSource = CMU_FXCLK_CTRL_CMU_GCLK_EN;
            break;
        }
    }

    (void)GPT_GTM_CMU_LLD_SelectFXCLKSource(FXCLKSource);

    for(uint8 i = 0; i < configPtr->count_of_configured_clocks; i++)
    {
        (void)GPT_GTM_CMU_LLD_SetClockCount((*(configPtr->clock_configPtr))[i].clockId, (uint32)((*(configPtr->clock_configPtr))[i].clockControlRegister)); /* polyspace RTE:IDP,OBAI*/
    }
    
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_FXCLK_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_FXCLK, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_ECLK2_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_ECLK2, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_ECLK1_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_ECLK1, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_ECLK0_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_ECLK0, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_CLK7_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK7, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_CLK6_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK6, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_CLK5_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK5, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_CLK4_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK4, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_CLK3_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK3, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_CLK2_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK2, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_CLK1_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK1, GPT_GTM_Enable);
    }
    if(((uint32)(configPtr->cmu_clk_control_register >> CMU_CLK_EN_EN_CLK0_OFFSET) & 0x3u) == (uint32)CMU_CLK_EN_ENABLE_CLOCK)
    {
        (void)GPT_GTM_CMU_LLD_IsEnableClock(GPT_GTM_CMU_CLK0, GPT_GTM_Enable);
    }
#if (defined(RESOURCE_SUPPORT_GTM410))
#ifdef RESOURCE_SUPPORT_GTM410_CLS0
    (void)GPT_GTM_LLD_IsEnableClsDiv(GTM_CLS0, GPT_CLS0DIV_CHOOSE_STATUS);
#endif
#ifdef RESOURCE_SUPPORT_GTM410_CLS1
    (void)GPT_GTM_LLD_IsEnableClsDiv(GTM_CLS1, GPT_CLS1DIV_CHOOSE_STATUS);
#endif
#ifdef RESOURCE_SUPPORT_GTM410_CLS2
    (void)GPT_GTM_LLD_IsEnableClsDiv(GTM_CLS2, GPT_CLS2DIV_CHOOSE_STATUS);
#endif
#ifdef RESOURCE_SUPPORT_GTM410_CLS3
    (void)GPT_GTM_LLD_IsEnableClsDiv(GTM_CLS3, GPT_CLS3DIV_CHOOSE_STATUS);
#endif
#ifdef RESOURCE_SUPPORT_GTM410_CLS4
    (void)GPT_GTM_LLD_IsEnableClsDiv(GTM_CLS4, GPT_CLS4DIV_CHOOSE_STATUS);
#endif
#ifdef RESOURCE_SUPPORT_GTM410_CLS5
    (void)GPT_GTM_LLD_IsEnableClsDiv(GTM_CLS5, GPT_CLS5DIV_CHOOSE_STATUS);
#endif
#ifdef RESOURCE_SUPPORT_GTM410_CLS6
    (void)GPT_GTM_LLD_IsEnableClsDiv(GTM_CLS6, GPT_CLS6DIV_CHOOSE_STATUS);
#endif
#ifdef RESOURCE_SUPPORT_GTM410_CLS7
    (void)GPT_GTM_LLD_IsEnableClsDiv(GTM_CLS7, GPT_CLS7DIV_CHOOSE_STATUS);
#endif
#endif
    SchM_Exit_Gpt_EXCLUSIVE_AREA_19();
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_GtmTbu_Wrapper_Init	\
(												\
	P2CONST(GPT_GTM_TBU_LLD_ConfigType, AUTOMATIC, GPT_APPL_CONST) configPtr	\
)
{
    SchM_Enter_Gpt_EXCLUSIVE_AREA_20();
    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH0, TBU_CHEN_DISABLE_CHANNEL);
    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH1, TBU_CHEN_DISABLE_CHANNEL);
    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH2, TBU_CHEN_DISABLE_CHANNEL);

    (void)GPT_GTM_TBU_LLD_SetSLK(GPT_GTM_TBU_CHEN_CH0, configPtr->tbu_ch0_control_clk_src);
    (void)GPT_GTM_TBU_LLD_SetSLK(GPT_GTM_TBU_CHEN_CH1, configPtr->tbu_ch1_control_clk_src);
    (void)GPT_GTM_TBU_LLD_SetSLK(GPT_GTM_TBU_CHEN_CH2, configPtr->tbu_ch2_control_clk_src);

    (void)GPT_GTM_TBU_LLD_SetCH0_LOWRES(configPtr->tbu_ch0_control_low_res);
    (void)GPT_GTM_TBU_LLD_SetCHMODE(GPT_GTM_TBU_CHEN_CH1, configPtr->tbu_ch1_control_ch_mode);
    (void)GPT_GTM_TBU_LLD_SetCHMODE(GPT_GTM_TBU_CHEN_CH2, configPtr->tbu_ch2_control_ch_mode);
    
    (void)GPT_GTM_TBU_LLD_SetBASE(GPT_GTM_TBU_CHEN_CH0, 0);
    (void)GPT_GTM_TBU_LLD_SetBASE(GPT_GTM_TBU_CHEN_CH1, 0);
    (void)GPT_GTM_TBU_LLD_SetBASE(GPT_GTM_TBU_CHEN_CH2, 0);

    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH0, configPtr->tbu_channel0_enable_reg);
    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH1, configPtr->tbu_channel1_enable_reg);
    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH2, configPtr->tbu_channel2_enable_reg);

    SchM_Exit_Gpt_EXCLUSIVE_AREA_20();
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_GtmCmu_Wrapper_Deinit(void)
{
    SchM_Enter_Gpt_EXCLUSIVE_AREA_21();
    GPT_GTM_CMU_LLD_IsEnableAllClock(GPT_GTM_Disable);
    
    (void)GPT_GTM_CMU_LLD_SetGlobalClockNumerator(GPT_GTM_CMU_GCLK_NUM_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetGlobalClockNumerator(GPT_GTM_CMU_GCLK_NUM_DEINIT_VAL);

    (void)GPT_GTM_CMU_LLD_SetGlobalClockDenominator(GPT_GTM_CMU_GCLK_NUM_DEINIT_VAL);

    (void)GPT_GTM_CMU_LLD_SelectFXCLKSource(CMU_FXCLK_CTRL_CMU_GCLK_EN);

    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_CLK0, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_CLK1, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_CLK2, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_CLK3, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_CLK4, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_CLK5, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_CLK6, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_CLK7, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_ECLK0, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_ECLK1, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_ECLK2, GPT_GTM_CMU_DEINIT_VAL);
    (void)GPT_GTM_CMU_LLD_SetClockCount(GPT_GTM_CMU_FXCLK, GPT_GTM_CMU_DEINIT_VAL);

    SchM_Exit_Gpt_EXCLUSIVE_AREA_21();
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"
FUNC(void, GPT_CODE) Gpt_GtmTbu_Wrapper_Deinit(void)
{
    SchM_Enter_Gpt_EXCLUSIVE_AREA_22();
    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH0, TBU_CHEN_DISABLE_CHANNEL);
    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH1, TBU_CHEN_DISABLE_CHANNEL);
    (void)GPT_GTM_TBU_LLD_IsEnableClock(GPT_GTM_TBU_CHEN_CH2, TBU_CHEN_DISABLE_CHANNEL);

    (void)GPT_GTM_TBU_LLD_SetSLK(GPT_GTM_TBU_CHEN_CH0, 0u);
    (void)GPT_GTM_TBU_LLD_SetSLK(GPT_GTM_TBU_CHEN_CH1, 0u);
    (void)GPT_GTM_TBU_LLD_SetSLK(GPT_GTM_TBU_CHEN_CH2, 0u);

    (void)GPT_GTM_TBU_LLD_SetCH0_LOWRES(0u);
    (void)GPT_GTM_TBU_LLD_SetCHMODE(GPT_GTM_TBU_CHEN_CH1, 0u);
    (void)GPT_GTM_TBU_LLD_SetCHMODE(GPT_GTM_TBU_CHEN_CH2, 0u);
    
    (void)GPT_GTM_TBU_LLD_SetBASE(GPT_GTM_TBU_CHEN_CH0, 0u);
    (void)GPT_GTM_TBU_LLD_SetBASE(GPT_GTM_TBU_CHEN_CH1, 0u);
    (void)GPT_GTM_TBU_LLD_SetBASE(GPT_GTM_TBU_CHEN_CH2, 0u);
    SchM_Exit_Gpt_EXCLUSIVE_AREA_22();
}
#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h" 

#ifdef __cplusplus
}
#endif
#endif

