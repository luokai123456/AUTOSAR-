/****************************************************************************
* Copyright (c) 2023  C*Core -   All Rights Reserved
*
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED,
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
*   Project              : AUTOSAR 4.4.0 MCAL
*   Platform             : PowerPC e200
*   Peripheral           : PWM
*   Dependencies         : -
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           :
*   Build Version        :
*
*****************************************************************************/

/**
*   @file    Pwm_Irq.c
*   @version 3.0.0
*
*   @brief   AUTOSAR 4.4.0 - Common Level Driver source file.
*   @details Autosar layer of Pwm MCAL driver.
*
*   @addtogroup Pwm
*   @{
*/
/* PRQA S 4342, 0491, 4322, 2844, 2934 EOF */
/* PRQA S 4397, 2053, 3432, 1006, 2986 EOF */
#ifdef __cplusplus
extern "C"{
#endif

#include "Pwm.h" /* PRQA S 0380 */
#include "Mcal.h"
#include "Pwm_LLDriver.h"
#include "Pwm_HAL_Wrapper.h"
#if (defined(RESOURCE_SUPPORT_ETPU))
#include "eTPU_LLDrivers.h"
#endif
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#include "Pwm_Ccu7_LLDriver.h"
#endif
#include "Pwm_Irq.h"

#define PWM_IRQ_C_VENDOR_ID                      176
#define PWM_IRQ_C_AR_REL_MAJOR_VER               4
#define PWM_IRQ_C_AR_REL_MINOR_VER               4
#define PWM_IRQ_C_AR_REL_REV_VER                 0
#define PWM_IRQ_C_SW_MAJOR_VER                   3
#define PWM_IRQ_C_SW_MINOR_VER                   0
#define PWM_IRQ_C_SW_PATCH_VER                   0

#if (PWM_IRQ_C_VENDOR_ID != PWM_CFG_H_VENDOR_ID)
    #error " NON-MATCHED DATA : PWM_IRQ_C_VENDOR_ID "
#endif
#if (PWM_IRQ_C_AR_REL_MAJOR_VER != PWM_CFG_H_AR_REL_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_AR_REL_MAJOR_VER "
#endif
#if (PWM_IRQ_C_AR_REL_MINOR_VER != PWM_CFG_H_AR_REL_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_AR_REL_MINOR_VER "
#endif
#if (PWM_IRQ_C_AR_REL_REV_VER != PWM_CFG_H_AR_REL_REV_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_AR_REL_REV_VER "
#endif
#if (PWM_IRQ_C_SW_MAJOR_VER != PWM_CFG_H_SW_MAJOR_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_SW_MAJOR_VER "
#endif
#if (PWM_IRQ_C_SW_MINOR_VER != PWM_CFG_H_SW_MINOR_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_SW_MINOR_VER "
#endif
#if (PWM_IRQ_C_SW_PATCH_VER != PWM_CFG_H_SW_PATCH_VER)
    #error " NON-MATCHED DATA : PWM_IRQ_C_SW_PATCH_VER "
#endif

#if (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE)Pwm_Tom_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch0_index, \
    VAR(uint8, AUTOMATIC) u8ch1_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0U;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag0 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag1 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag2 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag3 = 0U;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();

    u8Pwm_Flag0 = GTM_TOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
        (VAR(GTM_TOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU0TC \
    );
    u8Pwm_Flag1 = GTM_TOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
        (VAR(GTM_TOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU1TC \
    );

    u8Pwm_Flag2 = GTM_TOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
        (VAR(GTM_TOM_Interrupt_Type, AUTOMATIC))TOM_IRQ_CCU0TC \
    );
    u8Pwm_Flag3 = GTM_TOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
        (VAR(GTM_TOM_Interrupt_Type, AUTOMATIC))TOM_IRQ_CCU1TC \
    );

    if(u8Pwm_Flag0 == 1u)
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
            TOM_IRQ_CCU0TC \
        );
    }

    if(u8Pwm_Flag1 == 1u)
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
            TOM_IRQ_CCU1TC \
        );
    }

    if(u8Pwm_Flag2 == 1u)
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
            TOM_IRQ_CCU0TC \
        );
    }

    if(u8Pwm_Flag3 == 1u)
    {
        (void)GTM_TOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_TOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_TOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
            TOM_IRQ_CCU1TC \
        );
    }

    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_TomNotifyTable[(u8hw_index * PWM_TOM_CHANNEL_MAX) + u8ch0_index].pNotification;/* polyspace RTE:NIP,COR,IDP */ 
        Pwm_ChannelId = Pwm_Configs->pPwm_TomNotifyTable[(u8hw_index * PWM_TOM_CHANNEL_MAX) + u8ch0_index].nPwmChannelId;/* polyspace RTE:NIV */ 
        if((Pwm_Notify != NULL_PTR) && ((u8Pwm_Flag0 == 1U) || (u8Pwm_Flag1 == 1U)))
        {
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < PWM_CORE_NUM)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))/* polyspace RTE:COR,IDP */ 
                {
                	Pwm_Notify();/* polyspace RTE:COR */
                }
            }
        }

        Pwm_Notify = Pwm_Configs->pPwm_TomNotifyTable[(u8hw_index * PWM_TOM_CHANNEL_MAX) + u8ch1_index].pNotification;/* polyspace RTE:NIP,COR,IDP */ 
        Pwm_ChannelId = Pwm_Configs->pPwm_TomNotifyTable[(u8hw_index * PWM_TOM_CHANNEL_MAX) + u8ch1_index].nPwmChannelId;/* polyspace RTE:NIV */ 
        if((Pwm_Notify != NULL_PTR) && ((u8Pwm_Flag2 == 1U) || (u8Pwm_Flag3 == 1U)))
        {
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if((pChannelNotificationStatus[Pwm_ChannelId] == 1U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))/* polyspace RTE:COR,IDP */ 
            {
            	Pwm_Notify();/* polyspace RTE:COR */
            }
        }
    }

}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE)Pwm_Atom_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch0_index, \
    VAR(uint8, AUTOMATIC) u8ch1_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0U;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag0 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag1 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag2 = 0U;
    VAR(uint8, AUTOMATIC) u8Pwm_Flag3 = 0U;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();

    u8Pwm_Flag0 = GTM_ATOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
        (VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU0TC \
    );
    u8Pwm_Flag1 = GTM_ATOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
        (VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU1TC \
    );

    u8Pwm_Flag2 = GTM_ATOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
        (VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU0TC \
    );
    u8Pwm_Flag3 = GTM_ATOM_LLD_Channel_GetInterruptFlag \
    ( \
        (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
        (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
        (VAR(GTM_ATOM_Interrupt_Type, AUTOMATIC))ATOM_IRQ_CCU1TC \
    );

    if(u8Pwm_Flag0 == 1u)
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
            ATOM_IRQ_CCU0TC \
        );
    }

    if(u8Pwm_Flag1 == 1u)
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch0_index, \
            ATOM_IRQ_CCU1TC \
        );
    }

    if(u8Pwm_Flag2 == 1u)
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
            ATOM_IRQ_CCU0TC \
        );
    }

    if(u8Pwm_Flag3 == 1u)
    {
        (void)GTM_ATOM_LLD_Channel_ClearInterruptFlag \
        ( \
            (VAR(GTM_ATOM_Type, AUTOMATIC)) u8hw_index, \
            (VAR(GTM_ATOM_Channel_Type, AUTOMATIC)) u8ch1_index, \
            ATOM_IRQ_CCU1TC \
        );
    }

    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_AtomNotifyTable[(u8hw_index * PWM_ATOM_CHANNEL_MAX) + u8ch0_index].pNotification;/* polyspace RTE:NIP,COR,IDP */ 
        Pwm_ChannelId = Pwm_Configs->pPwm_AtomNotifyTable[(u8hw_index * PWM_ATOM_CHANNEL_MAX) + u8ch0_index].nPwmChannelId;/* polyspace RTE:NIV */ 

        if((Pwm_Notify != NULL_PTR) && ((u8Pwm_Flag0 == 1U) || (u8Pwm_Flag1 == 1U)))
        {
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < PWM_CORE_NUM)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))/* polyspace RTE:COR,IDP */ 
                {
                	Pwm_Notify();/* polyspace RTE:COR */
                }
            }
        }

        Pwm_Notify = Pwm_Configs->pPwm_AtomNotifyTable[(u8hw_index * PWM_ATOM_CHANNEL_MAX) + u8ch1_index].pNotification;/* polyspace RTE:NIP,COR,IDP */ 
        Pwm_ChannelId = Pwm_Configs->pPwm_AtomNotifyTable[(u8hw_index * PWM_ATOM_CHANNEL_MAX) + u8ch1_index].nPwmChannelId;/* polyspace RTE:NIV */ 
        if((Pwm_Notify != NULL_PTR) && ((u8Pwm_Flag2 == 1U) || (u8Pwm_Flag3 == 1U)))
        {
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < PWM_CORE_NUM)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))/* polyspace RTE:COR,IDP */ 
                {
                	Pwm_Notify();/* polyspace RTE:COR */
                }
            }
        }
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* (defined(RESOURCE_SUPPORT_GTM104) || defined (RESOURCE_SUPPORT_GTM410)) */

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE)Pwm_Emios_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(uint8, AUTOMATIC) channelState = 0;
    VAR(uint8*, AUTOMATIC) pChannelNotifiClass = NULL_PTR;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();

    pChannelNotifiClass = Pwm_Wrapper_Get_ChannelNotifiClass();

    eMIOS_LLD_UC_ClearFlag(u8hw_index,u8ch_index);

    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_EmiosNotifyTable[(u8hw_index * PWM_EMIOS_CHANNEL_MAX) + u8ch_index].pNotification;/* polyspace RTE:NIP,COR,IDP */ 

        if(Pwm_Notify != NULL_PTR)
        {
            pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
            Pwm_ChannelId = Pwm_Configs->pPwm_EmiosNotifyTable[(u8hw_index * PWM_EMIOS_CHANNEL_MAX) + u8ch_index].nPwmChannelId;/* polyspace RTE:NIV */ 
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if((u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))
            {
                if(u32CoreID < PWM_CORE_NUM)
                {
                    if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U))/* polyspace RTE:COR,IDP */ 
                    {
                        channelState = Pwm_Wrapper_GetEmiosOutputState(&(Pwm_Configs->sPwmChConfigs[Pwm_ChannelId]));
                        if(pChannelNotifiClass[Pwm_ChannelId] == (uint8)PWM_BOTH_EDGES)
                        {
                            Pwm_Notify();/* polyspace RTE:COR */
                        }
                        else if((pChannelNotifiClass[Pwm_ChannelId] == (uint8)PWM_RISING_EDGE) && (channelState == 1U))
                        {
                            Pwm_Notify();/* polyspace RTE:COR */
                        }
                        else if((pChannelNotifiClass[Pwm_ChannelId] == (uint8)PWM_FALLING_EDGE) && (channelState == 0U))
                        {
                            Pwm_Notify();/* polyspace RTE:COR */
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                }
            }
        }
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined(RESOURCE_SUPPORT_ETPU))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE)Pwm_Etpu_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();

    if(u8hw_index == 0U)
    {
        (void)ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_A_B,ETPU_A_CHANNLE(u8ch_index));
    }
    else if(u8hw_index == 1U)
    {
        (void)ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_A_B,ETPU_B_CHANNLE(u8ch_index));
    }
    else if(u8hw_index == 2U)
    {
        (void)ETPU_LLD_ClearChannelInterruptFlag(ETPU_INSTANCE_C,ETPU_C_CHANNLE(u8ch_index));
    }
    else
    {
        /* Do nothing */
    }

    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_EtpuNotifyTable[(u8hw_index * PWM_ETPU_CHANNEL_MAX) + u8ch_index].pNotification;/* polyspace RTE:NIP,COR,IDP */ 

        if(Pwm_Notify != NULL_PTR)
        {
            pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
            Pwm_ChannelId = Pwm_Configs->pPwm_EtpuNotifyTable[(u8hw_index * PWM_ETPU_CHANNEL_MAX) + u8ch_index].nPwmChannelId;/* polyspace RTE:NIV */ 
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < PWM_CORE_NUM)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))/* polyspace RTE:COR,IDP */ 
                {
                	Pwm_Notify();/* polyspace RTE:COR */
                }
            }
        }
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_ETPU */
#if (defined(RESOURCE_SUPPORT_CCU7_IP))
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
static FUNC(void, PWM_CODE)Pwm_Ccu7_isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index \
)
{
    P2VAR(Pwm_ChConfigsType, PWM_VAR, PWM_APPL_VAR) Pwm_Configs = NULL_PTR;
    VAR(Pwm_NotifyType, PWM_VAR) Pwm_Notify = NULL_PTR;
    VAR(Pwm_ChannelType, AUTOMATIC) Pwm_ChannelId = 0;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelNotificationStatus = NULL_PTR;
    VAR(Pwm_DutycycleType, AUTOMATIC) u32Pwm_Dutycycle = 0U;
    VAR(uint32, AUTOMATIC) u32CoreID = 0U;
    u32CoreID = (uint32)GetCoreID();    //get core id

    Pwm_Configs = Pwm_Pwm_Wrapper_Get_pChConfigs();



    if(Pwm_Configs != NULL_PTR)
    {
        Pwm_Notify = Pwm_Configs->pPwm_Ccu7NotifyTable[(u8hw_index * PWM_CCU7_CHANNEL_MAX) + u8ch_index].pNotification;/* polyspace RTE:NIP,IDP */
        if(Pwm_Notify != NULL_PTR)
        {
            pChannelNotificationStatus = Pwm_Wrapper_Get_ChannelNotification();
            Pwm_ChannelId = Pwm_Configs->pPwm_Ccu7NotifyTable[(u8hw_index * PWM_CCU7_CHANNEL_MAX) + u8ch_index].nPwmChannelId;/* polyspace RTE:NIV */
            u32Pwm_Dutycycle = Pwm_Wrapper_Get_ChannelDutyCycle(Pwm_ChannelId);
            if(u32CoreID < 3U)
            {
                if(((pChannelNotificationStatus[Pwm_ChannelId]&(1U<<u32CoreID)) != 0U) && (u32Pwm_Dutycycle != 0x8000U) && (u32Pwm_Dutycycle != 0U))/* polyspace RTE:COR,IDP */
                {
                	Pwm_Notify();/* polyspace RTE:COR */
                }
            }
        }
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE)CCU70_ISR (void)
{
    VAR(uint32, AUTOMATIC) u32tempIntStatus = 0U;
    VAR(uint32, AUTOMATIC) u32tempIntEn = 0U;

    u32tempIntStatus = CCU7_0.IS.reg;
    u32tempIntEn = CCU7_0.IEN.reg;

    CCU7_0.ISR.reg = 0xffffu;

    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelPmStatus = NULL_PTR;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelDuty0or100Status = NULL_PTR;

    pChannelPmStatus = Ccu7_LLD_PWM_Get_PmStatus();
    pChannelDuty0or100Status = Ccu7_LLD_PWM_Get_Duty0or100Status();

    if(((u32tempIntStatus & 0x1U) == 1U)&&((u32tempIntEn & 0x1U) == 1U))
    {
        Pwm_Ccu7_isr_handle(0U, 0U);
    }

    if((((u32tempIntStatus & 0x4U) >> 2) == 1U)&&(((u32tempIntEn & 0x4U) >> 2) == 1U))
    {
        Pwm_Ccu7_isr_handle(0U, 1U);
    }

    if((((u32tempIntStatus & 0x10U) >> 4) == 1U)&&(((u32tempIntEn & 0x10U) >> 4) == 1U))
    {
        Pwm_Ccu7_isr_handle(0U, 2U);
    }

    if((((u32tempIntStatus & 0x80U) >> 7) == 1U)&&(((u32tempIntEn & 0x80U) >> 7) == 1U))
    {
        if(((pChannelPmStatus[0] & 0x1U) == 1U)&&((pChannelDuty0or100Status[0] & 0x1U) != 1U))
        {
            Pwm_Ccu7_isr_handle(0U, 0U);
        }

        if((((pChannelPmStatus[0] & 0x2U) >> 1) == 1U)&&(((pChannelDuty0or100Status[0] & 0x2U) >> 1) != 1U))
        {
            Pwm_Ccu7_isr_handle(0U, 1U);
        }

        if((((pChannelPmStatus[0] & 0x4U) >> 2) == 1U)&&(((pChannelDuty0or100Status[0] & 0x4U) >> 2) != 1U))
        {
            Pwm_Ccu7_isr_handle(0U, 2U);
        }
    }

    if((((u32tempIntStatus & 0x100U) >> 8) == 1U)&&(((u32tempIntEn & 0x100U) >> 8) == 1U))
    {
        Pwm_Ccu7_isr_handle(0U, 3U);
    }

    if((((u32tempIntStatus & 0x200U) >> 9) == 1U)&&(((u32tempIntEn & 0x200U) >> 9) == 1U))
    {
        Pwm_Ccu7_isr_handle(0U, 3U);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE)CCU71_ISR (void)
{
    VAR(uint32, AUTOMATIC) u32tempIntStatus = 0U;
    VAR(uint32, AUTOMATIC) u32tempIntEn = 0U;

    u32tempIntStatus = CCU7_1.IS.reg;
    u32tempIntEn = CCU7_1.IEN.reg;

    CCU7_1.ISR.reg = 0xffffu;

    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelPmStatus = NULL_PTR;
    P2VAR(uint8, PWM_VAR, PWM_APPL_VAR) pChannelDuty0or100Status = NULL_PTR;

    pChannelPmStatus = Ccu7_LLD_PWM_Get_PmStatus();
    pChannelDuty0or100Status = Ccu7_LLD_PWM_Get_Duty0or100Status();

    if(((u32tempIntStatus & 0x1U) == 1U)&&((u32tempIntEn & 0x1U) == 1U))
    {
        Pwm_Ccu7_isr_handle(1U, 0U);
    }

    if((((u32tempIntStatus & 0x4U) >> 2) == 1U)&&(((u32tempIntEn & 0x4U) >> 2) == 1U))
    {
        Pwm_Ccu7_isr_handle(1U, 1U);
    }

    if((((u32tempIntStatus & 0x10U) >> 4) == 1U)&&(((u32tempIntEn & 0x10U) >> 4) == 1U))
    {
        Pwm_Ccu7_isr_handle(1U, 2U);
    }

    if((((u32tempIntStatus & 0x80U) >> 7) == 1U)&&(((u32tempIntEn & 0x80U) >> 7) == 1U))
    {
        if(((pChannelPmStatus[1] & 0x1U) == 1U)&&((pChannelDuty0or100Status[1] & 0x1U) != 1U))
        {
            Pwm_Ccu7_isr_handle(1U, 0U);
        }

        if((((pChannelPmStatus[1] & 0x2U) >> 1) == 1U)&&(((pChannelDuty0or100Status[1] & 0x2U) >> 1) != 1U))
        {
            Pwm_Ccu7_isr_handle(1U, 1U);
        }

        if((((pChannelPmStatus[1] & 0x4U) >> 2) == 1U)&&(((pChannelDuty0or100Status[1] & 0x4U) >> 2) != 1U))
        {
            Pwm_Ccu7_isr_handle(1U, 2U);
        }
    }

    if((((u32tempIntStatus & 0x100U) >> 8) == 1U)&&(((u32tempIntEn & 0x100U) >> 8) == 1U))
    {
        Pwm_Ccu7_isr_handle(1U, 3U);
    }

    if((((u32tempIntStatus & 0x200U) >> 9) == 1U)&&(((u32tempIntEn & 0x200U) >> 9) == 1U))
    {
        Pwm_Ccu7_isr_handle(1U, 3U);
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"
#endif /* RESOURCE_SUPPORT_CCU7_IP */
#define PWM_START_SEC_VAR_NO_INIT
#include "Pwm_MemMap.h"
static volatile VAR(eMIOS_PWM_DAOC_ISR_ParamType, PWM_VAR) Pwm_Emios_DAOC_Param[PWM_EMIOS_CHANNEL_MAX * PWM_EMIOS_MAX];
#define PWM_STOP_SEC_VAR_NO_INIT
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Set_Emios_DAOC_B \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index, \
    VAR(uint32, AUTOMATIC) value \
)
{
    if((((PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index) < (PWM_EMIOS_CHANNEL_MAX * PWM_EMIOS_MAX)) && (value < 0xFFFFFFU))
    {
        Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].duty = value;
    }
    else
    {
        if(((PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index) < (PWM_EMIOS_CHANNEL_MAX * PWM_EMIOS_MAX))
        {
            Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].duty = 0xFFFFFFU;
        }

    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Set_Emios_DAOC_Active \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index, \
    VAR(uint32, AUTOMATIC) value \
)
{
    Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].active = (uint8)value;/* polyspace RTE:OBAI */  
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"
FUNC(void, PWM_CODE) Pwm_Emios_DAOC_Isr_handle \
( \
    VAR(uint8, AUTOMATIC) u8hw_index, \
    VAR(uint8, AUTOMATIC) u8ch_index \
)
{
    VAR(uint8, AUTOMATIC) vla = 0;
    vla = eMIOS_UC_Sn_GetUCOUT(u8hw_index, u8ch_index);
    if(((PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index) < (PWM_EMIOS_CHANNEL_MAX * PWM_EMIOS_MAX))
    {
        if(vla != Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].active)
        {
            if(Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].duty < 0xFFFFFFU)
            {
                eMIOS_UC_Bn_SetValue \
                ( \
                        u8hw_index, \
                        u8ch_index, \
                        Pwm_Emios_DAOC_Param[(PWM_EMIOS_CHANNEL_MAX * u8hw_index) + u8ch_index].duty \
                );
            }
            else
            {
                eMIOS_UC_Bn_SetValue \
                ( \
                        u8hw_index, \
                        u8ch_index, \
                        0xFFFFFFU \
                );
            }
            eMIOS_UC_An_SetValue(u8hw_index, u8ch_index,1U);
        }
    }
}
#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif
